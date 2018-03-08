
#include <qpOASES.hpp>
//#include "Eigen"
#include "MPC_qpOASES.hpp"
#include "MPC_consts.hpp"
#include "calculate_u.h"
#include "calculate_b.h"

static const double g[NUM_VAR] = {0};

int main()
{
	/* Test routine */
	double x[] = {0,1,0,0,0,0,0,0};
	double r[NR*NX] = {0};
	QP_res_t QP_res;
	double u[NU] = {0};

	computeMPC(x, r, &QP_res, u);
}

int computeMPC(const double* x, const double* r, QP_res_t* QP_res, double* u)
{
	/* Allocate QProblem object */
	qpOASES::QProblem QP(NC*NU+NU+NS,NCON);

	int nWSR = 1000; /* Not too sure what this means - maybe max iterations? */
	double cpuTime = 0;

	qpOASES::Option opt;
	QP.setOptions(opt);

	/* Calculate b */
	double b[NCON];
	calculate_b(x, r, b);

	/* Init QP */
	int res = QP.init(H, g, A, NULL, NULL, NULL, b, nWSR, &cpuTime);

	/* Get result */
	QP.getPrimalSolution( QP_res->z );

	/* Calculate u */
	calculate_u(x, r, res.c, u);

	return res;
}

