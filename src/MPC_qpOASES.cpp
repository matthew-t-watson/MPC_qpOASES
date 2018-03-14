
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


int initMPC(qpOASES::QProblem& QP);
int computeMPC(qpOASES::QProblem& QP, MPCPacketParams_t& params, MPCPacketResult_t& res);

static const double G[NC*NU+NU+NS] = {0};
static const double x0[] = {0,0,0,0,0,0,0,0};
static const double r0[NR*NX] = {0};

#define USE_SPARSE_MATRICES

int main()
{
	/* Allocate QProblem object */
	qpOASES::QProblem QP(NC*NU+NU+NS,NCON,qpOASES::HST_POSDEF);

	/* Initialise QP */
	initMPC(QP);

	/* Configure UDP socket */
	if (configureSockets() > 0)
	{
		return 1;
	}

	MPCPacketParams_t MPCParams;
	MPCPacketResult_t MPCRes;
	while (1)
	{
		if (getPacket(MPCParams) > 0)
		{
			return 1;
		}

		computeMPC(QP, MPCParams, MPCRes);

		if (sendPacket(MPCRes) > 0)
		{
			return 1;
		}
	}
}


int initMPC(qpOASES::QProblem& QP)
{
	int nWSR = 10000;
	double cpuTime = 10;

	qpOASES::Options opt;
	opt.setToMPC(); /*  Sets all options to values resulting in minimum solution time */
	opt.printLevel = qpOASES::PL_LOW;
	opt.enableEqualities = qpOASES::BT_FALSE;
	opt.enableInertiaCorrection = qpOASES::BT_FALSE;

	opt.print();
	QP.setOptions(opt);

	/* Calculate b */
	double b[NCON];
	calculate_b(x0, r0, b);

#ifdef USE_SPARSE_MATRICES
	/* create sparse matrices */
	qpOASES::SymSparseMat *Hsp = new qpOASES::SymSparseMat(H_NROWS, H_NCOLS, H_NCOLS, H);
	qpOASES::SparseMatrix *Asp = new qpOASES::SymSparseMat(A_NROWS, A_NCOLS, A_NCOLS, A);

	/* Init QP - sparse */
	int exitFlag = QP.init(Hsp, G, Asp, NULL, NULL, NULL, b, nWSR, &cpuTime);
#else
	/* Init QP - dense */
	int exitFlag = QP.init(H, G, A, NULL, NULL, NULL, b, nWSR, &cpuTime);
#endif

	printf("exitFlag %i, cpu time %fs, nWSR = %i\n", exitFlag, cpuTime, nWSR);

	return exitFlag;
}

int computeMPC(qpOASES::QProblem& QP, MPCPacketParams_t& params, MPCPacketResult_t& res)
{
	/* Calculate b */
	double b[NCON];
	calculate_b(params.x, params.r, b);

	/* Compute hotstarted QP */
	res.nWSR = 1000;
	res.tExec = 10;
	res.exitFlag = QP.hotstart(G, NULL, NULL, NULL, b, res.nWSR, &res.tExec);

	/* Get result */
	QPout_t QPout;
	QP.getPrimalSolution( QPout.z );

	/* Copy data into packet */
	id = params.id;
	//c_len = NC*NU;
	memcpy(&res.c, &QPout.c, sizeof(res.c));
	cinf_len = NU;
	memcpy(&res.cinf, &QPout.cinf, sizeof(res.cinf));
	s_len = NS;
	memcpy(&res.s, &QPout.s, sizeof(res.s));
	u_len = NU;
	memcpy(&res.u, &QPout.u, sizeof(res.u));

	/* Calculate u */
	calculate_u(params.x, params.r, res.c, res.u);

	printf("exitFlag %i, cpu time %fs, nWSR = %i\n", res.exitFlag, res.tExec, res.nWSR);

	return res.exitFlag;
}

