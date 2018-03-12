
#include <qpOASES.hpp>
//#include "Eigen"
#include "MPC_qpOASES.hpp"
#include "MPC_consts.hpp"
#include "calculate_u.h"
#include "calculate_b.h"

static const double G[NC*NU+NU+NS] = {0};
static const double x0[] = {0,0,0,0,0,0,0,0};
static const double r0[NR*NX] = {0};

int main()
{
	/* Allocate QProblem object */
	qpOASES::QProblem QP(NC*NU+NU+NS,NCON);

	/* Initialise QP */
	initMPC(QP);

	/* Test routine */
	QP_res_t QP_res;
	double u[NU] = {0};
	double x[]={0,0,0,0.2,0,0,0,0};

	int exitFlag = computeMPC(QP, x, r0, &QP_res, u);
}

int initMPC(qpOASES::QProblem& QP)
{
	int nWSR = 100;
	double cpuTime = 0;

	qpOASES::Options opt;
	opt.setToMPC(); /*  Sets all options to values resulting in minimum solution time */
	opt.printLevel = qpOASES::PL_HIGH;
	opt.print();
	QP.setOptions(opt);

	/* Calculate b */
	double b[NCON];
	calculate_b(x0, r0, b);

//	printf("Calculated b as ");
//	for (int i = 0; i < NCON; i++)
//	{
//		printf("%f\t", b[i]);
//	}
//	printf("\n");

	/* Init QP */
	int exitFlag = QP.init(H, G, A, NULL, NULL, NULL, b, nWSR, &cpuTime);

	printf("exitFlag %i, Cpu time %fs, nWSR = %i\n", exitFlag, cpuTime, nWSR);

	return exitFlag;
}

int computeMPC(qpOASES::QProblem& QP, const double* x, const double* r, QP_res_t* QP_res, double* u)
{
	/* Calculate b */
	double b[NCON];
	calculate_b(x, r, b);

//	printf("Calculated b as ");
//	for (int i = 0; i < NCON; i++)
//	{
//		printf("%f\t", b[i]);
//	}
//	printf("\n");

	/* Compute hotstarted QP */
	int nWSR = 100;
	double cpuTime = 0;
	int exitFlag = QP.hotstart(G, NULL, NULL, NULL, b, nWSR, &cpuTime);

	/* Get result */
	QP.getPrimalSolution( QP_res->z );

	/* Calculate u */
	calculate_u(x, r, QP_res->c, u);

	printf("exitFlag %i, Cpu time %fs, nWSR = %i\n", exitFlag, cpuTime, nWSR);

	return exitFlag;
}

