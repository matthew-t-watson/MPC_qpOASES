
#include <qpOASES.hpp>
//#include "Eigen"
#include "MPC_qpOASES.hpp"
#include "MPC_consts.hpp"
#include "calculate_u.h"
#include "calculate_b.h"

static const double g[NUM_VAR] = {0};

int main()
{

}

int computeMPC(const double *x, const double *r, double *b, double *c, double *cinf, double *s
        double *u)
{
	/* Allocate QProblem object */
	qpOASES::QProblem QP(NUM_VAR,NUM_CON);

	int nWSR = 1000; /* Not too sure what this means - maybe max iterations? */
	double cpuTime = 0;

	qpOASES::Option opt;
	QP.setOptions(opt);

	/* Calculate b */
	double b[NCON];
	calculate_b(x, r, b);

	/* Init QP */
	int res = QP.init(H, g, A, [], [], [], b, nWSR, &cpuTime);

	/* Get result */
	QP_res_t res;
	QP.getPrimalSolution( res.z );

	/* Calculate u */
	calculate_u(x, r, res.c, u);

	return res;
}

