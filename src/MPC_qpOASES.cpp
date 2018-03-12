
#include <qpOASES.hpp>
//#include "Eigen"
#include "MPC_qpOASES.hpp"
#include "MPC_double_consts.hpp"
#include "MPC_int_consts.hpp"
#include "calculate_u.h"
#include "calculate_b.h"

static const double G[NC*NU+NU+NS] = {0};
static const double x0[] = {0,0,0,0,0,0,0,0};
static const double r0[NR*NX] = {0};

#define SPARSE_MATRICES

int main()
{
	/* Allocate QProblem object */
	qpOASES::QProblem QP(NC*NU+NU+NS,NCON,qpOASES::HST_POSDEF);

	/* Initialise QP */
	initMPC(QP);

	/* Test routine */
	QP_res_t QP_res;
	double u[NU] = {0};
	double x[]={0,1,0,0,0,0,0,0};

	for(int i = 0; i<5; i++)
		int exitFlag = computeMPC(QP, x, r0, &QP_res, u);
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

#ifdef SPARSE_MATRICES
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

int computeMPC(qpOASES::QProblem& QP, const double* x, const double* r, QP_res_t* QP_res, double* u)
{
	/* Calculate b */
	double b[NCON];
	calculate_b(x, r, b);

	/* Compute hotstarted QP */
	int nWSR = 10000;
	double cpuTime = 10;
	int exitFlag = QP.hotstart(G, NULL, NULL, NULL, b, nWSR, &cpuTime);

	/* Get result */
	QP.getPrimalSolution( QP_res->z );

	/* Calculate u */
	calculate_u(x, r, QP_res->c, u);

	printf("exitFlag %i, cpu time %fs, nWSR = %i\n", exitFlag, cpuTime, nWSR);

	return exitFlag;
}

