
#include <qpOASES.hpp>
//#include "Eigen"
#include "MPC_qpOASES.hpp"
#include "MPC_double_consts.hpp"
#include "MPC_int_consts.hpp"
#include "calculate_u.h"
#include "calculate_b.h"
#include "networking.hpp"
#include <errno.h>
#include "string.h" /* for memcpy */


int computeMPC(qpOASES::QProblem& QP, qpOASES::SymSparseMat* Hsp, qpOASES::SparseMatrix* Asp, MPCPacketParams_t& params, MPCPacketResult_t& res);


static const double G[NC*NU+NU+NS] = {0};
static const double x0[] = {0,0,0,0,0,0,0,0};
static const double r0[NR*NX] = {0};

#define USE_SPARSE_MATRICES
#define INITIALISED_HOMOTOPY

int main()
{
	/* Allocate QProblem object */
	qpOASES::QProblem QP(NC*NU+NU+NS,NCON,qpOASES::HST_POSDEF);

	/* Initialise QP */
	qpOASES::SymSparseMat *Hsp = new qpOASES::SymSparseMat(H_NROWS, H_NCOLS, H_NCOLS, H);
	qpOASES::SparseMatrix *Asp = new qpOASES::SymSparseMat(A_NROWS, A_NCOLS, A_NCOLS, A);

	H.createDiagInfo();
	A.createDiagInfo();

	/* Configure UDP socket */
	if (configureSockets() == 0)
	{
		MPCPacketParams_t MPCParams;
		MPCPacketResult_t MPCRes;
		while (1)
		{
			if (getPacket(MPCParams) > 0)
			{
				continue;
			}

			computeMPC(QP, Hsp, Asp, MPCParams, MPCRes);

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
}


int computeMPC(qpOASES::QProblem& QP, qpOASES::SymSparseMat* Hsp, qpOASES::SparseMatrix* Asp, MPCPacketParams_t& params, MPCPacketResult_t& res)
{
	static double initialPrimalSolution[NC*NU+NU+NS] = {0};

	qpOASES::Options opt;
	opt.setToMPC(); /*  Sets all options to values resulting in minimum solution time */
	opt.printLevel = qpOASES::PL_LOW;
	opt.enableEqualities = qpOASES::BT_FALSE;
	opt.enableInertiaCorrection = qpOASES::BT_FALSE;

	QP.setOptions(opt);

	/* Calculate b */
	double b[NCON];
	calculate_b(params.x, params.r, b);

	res.nWSR = 1000;
	res.tExec = 10;
	res.exitFlag = QP.init(Hsp, G, Asp, NULL, NULL, NULL, b, res.nWSR, &res.tExec, initialPrimalSolution, 0, 0, 0, 0);

	/* Get result */
	QPout_t QPout;
	QP.getPrimalSolution( QPout.z );
	res.cost = QP.getObjVal();

	/* Copy remaining QP results into packet */
	res.id = params.id;
	memcpy(&res.c, &QPout.c, sizeof(res.c));
	memcpy(&res.cinf, &QPout.cinf, sizeof(res.cinf));
	memcpy(&res.s, &QPout.s, sizeof(res.s));

	/* Calculate u */
	calculate_u(params.x, params.r, res.c, res.u);

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

