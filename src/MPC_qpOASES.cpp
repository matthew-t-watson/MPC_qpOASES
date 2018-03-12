
#include <qpOASES.hpp>
//#include "Eigen"
#include "MPC_qpOASES.hpp"
#include "MPC_consts.hpp"
#include "calculate_u.h"
#include "calculate_b.h"

static const double G[NC*NU+NU+NS] = {0};

int main()
{
	/* Test routine */
	double x[] = {0,0.3,0,0,0,0,0,0};
	double r[NR*NX] = {0};
	QP_res_t QP_res;
	double u[NU] = {0};

	int exitFlag = computeMPC(x, r, &QP_res, u);
}

int computeMPC(const double* x, const double* r, QP_res_t* QP_res, double* u)
{
	/* Allocate QProblem object */
	qpOASES::QProblem QP(NC*NU+NU+NS,NCON);

	int nWSR = 1000000; /* Not too sure what this means - maybe max iterations? */
	double cpuTime = 0;

	qpOASES::Options opt;
	opt.setToMPC(); /*  Sets all options to values resulting in minimum solution time */
	opt.print();
	opt.printLevel = PL_HIGH;
	QP.setOptions(opt);

	/* Calculate b */
	double b[NCON];
	calculate_b(x, r, b);

	printf("Calculated b as ");
	for (int i = 0; i < NCON; i++)
	{
		printf("%f\t", b[i]);
	}
	printf("\n");

	/* Init QP */
	int exitFlag = QP.init(H, G, A, NULL, NULL, NULL, b, nWSR, &cpuTime);

	/* Get result */
	QP.getPrimalSolution( QP_res->z );

	/* Calculate u */
	calculate_u(x, r, QP_res->c, u);

	printf("exitFlag %i, Cpu time %fs\n", exitFlag, cpuTime);

	return exitFlag;
}

