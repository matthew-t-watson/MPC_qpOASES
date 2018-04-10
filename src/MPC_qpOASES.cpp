
#include <qpOASES.hpp>
#include "Constants.hpp"

//#include "Eigen"
#include "MPC_qpOASES.hpp"
#include "MPC_double_consts.hpp"
#include "MPC_int_consts.hpp"
#include "calculate_u.h"
#include "calculate_b.h"
#include "networking.hpp"
#include <errno.h>
#include "string.h" /* for memcpy */
#include <stdbool.h>


#define USE_REDUCED_PACKET_SIZE /* Only transmit u, omitting c cinf s */

int computeMPC(qpOASES::QProblem& QP, MPCPacketParams_t& params, MPCPacketResultReduced_t& res, bool init);
int computeMPC(qpOASES::QProblem& QP, MPCPacketParams_t& params, MPCPacketResult_t& res, bool init);



static const double G[NC*NU+NU+NS] = {0};


/* create sparse matrices */
qpOASES::SymSparseMat *Hsp;
qpOASES::SparseMatrix *Asp;


int main()
{
	/* Allocate QProblem object */
	qpOASES::QProblem QP(NC*NU+NU+NS,NCON,qpOASES::HST_POSDEF);

	/* create sparse matrices */
	Hsp = new qpOASES::SymSparseMat(H_NROWS, H_NCOLS,
	H_NCOLS, H);
	Asp = new qpOASES::SymSparseMat(A_NROWS, A_NCOLS,
	A_NCOLS, A);

	/* Configure UDP socket */
	if (configureSockets() == 0)
	{
		MPCPacketParams_t MPCParams;
#ifdef USE_REDUCED_PACKET_SIZE
		MPCPacketResultReduced_t MPCRes;
#else
		MPCPacketResult_t MPCRes;
#endif
		MPCRes.exitFlag = 123;

		while (1)
		{
			if (getPacket(MPCParams) > 0)
			{
				continue;
			}

			if (MPCRes.exitFlag == 0)
			{
				/* Last solution was successful, so can hotstart now */
				computeMPC(QP, MPCParams, MPCRes, false);
			}
			else
			{
				/* Last solution errored, so reset and init again */
				QP->reset();
				computeMPC(QP, MPCParams, MPCRes, true);
			}

			if (sendPacket(MPCRes) > 0)
			{
				continue;
			}
		}
	}
	else
	{
		printf("Failed to configure socket\n");
		return 1;
	}

	delete Hsp;
	delete Asp;
}

int computeMPC(qpOASES::QProblem& QP, MPCPacketParams_t& params, MPCPacketResultReduced_t& res, bool init)
{
	/* Calculate b */
	double b[NCON];
	calculate_b(params.x, params.r, b);

	res.nWSR = 1000;
	res.tExec = 10;
	if (init)
	{
		qpOASES::Options opt;
		opt.setToMPC(); /*  Sets all options to values resulting in minimum solution time */
		//opt.setToDefault(); /* Far too slow */
		opt.printLevel = qpOASES::PL_NONE;
		opt.terminationTolerance = 5.0e6 * qpOASES::EPS; /* Same as default options */
		opt.boundTolerance =  1.0e6 * qpOASES::EPS; /* Same as default options */
		opt.enableEqualities =  qpOASES::BT_FALSE; /* Same as default options */
		QP.setOptions(opt);

		/* Init QP - sparse */
		res.exitFlag = QP.init(Hsp, G, Asp, NULL, NULL, NULL, b, res.nWSR,
				&res.tExec);
	}
	else
	{
		/* Compute hotstarted QP */
		res.exitFlag = QP.hotstart(G, NULL, NULL, NULL, b, res.nWSR, &res.tExec);
	}

	/* Get result */
	QPout_t QPout;
	QP.getPrimalSolution(QPout.z);
	res.cost = QP.getObjVal();

	/* Calculate u, storing result in res */
	calculate_u(params.x, params.r, QPout.c, res.u);

	/* Copy remaining QP results into packet */
	res.id = params.id;

	if (res.exitFlag != 0)
	{
		for (int i = 0; i < sizeof(res.u)/sizeof(res.u[0]); i++)
		{
			res.u[i] = 0;
		}
	}

#ifdef VERBOSE
	printf("exitFlag %i, cpu time %fs, nWSR = %i\n", res.exitFlag, res.tExec, res.nWSR);
#endif

	return res.exitFlag;
}

int computeMPC(qpOASES::QProblem& QP, MPCPacketParams_t& params, MPCPacketResult_t& res, bool init)
{
	/* Calculate b */
	double b[NCON];
	calculate_b(params.x, params.r, b);

	res.nWSR = 1000;
	res.tExec = 10;
	if (init)
	{
		qpOASES::Options opt;
		opt.setToMPC(); /*  Sets all options to values resulting in minimum solution time */
		opt.printLevel = qpOASES::PL_NONE;
		QP.setOptions(opt);

		/* Init QP - sparse */
		res.exitFlag = QP.init(Hsp, G, Asp, NULL, NULL, NULL, b, res.nWSR,
				&res.tExec);
	}
	else
	{
		/* Compute hotstarted QP */
		res.exitFlag = QP.hotstart(G, NULL, NULL, NULL, b, res.nWSR, &res.tExec);
	}

	/* Get result */
	QPout_t QPout;
	QP.getPrimalSolution( QPout.z );
	res.cost = QP.getObjVal();

	/* Calculate u, storing result in res */
	calculate_u(params.x, params.r, QPout.c, res.u);

	/* Copy remaining QP results into packet */
	res.id = params.id;
	memcpy(&res.c, &QPout.c, sizeof(res.c));
	memcpy(&res.cinf, &QPout.cinf, sizeof(res.cinf));
	memcpy(&res.s, &QPout.s, sizeof(res.s));


	if (res.exitFlag != 0)
	{
		for (int i = 0; i < sizeof(res.u)/sizeof(res.u[0]); i++)
		{
			res.u[i] = 0;
		}
	}

#ifdef VERBOSE
	printf("exitFlag %i, cpu time %fs, nWSR = %i\n", res.exitFlag, res.tExec, res.nWSR);
#endif

	return res.exitFlag;
}

