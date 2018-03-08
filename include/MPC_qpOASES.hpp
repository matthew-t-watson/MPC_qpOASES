
#include "MPC_defines.hpp"

/* Structure of results from QP correctly arranged in memory */
typedef union {
	double z[NC * NU + NU + NS];
	struct {
		double c[NC * NU];
		double cinf[NU];
		double s[NS];
	};
} QP_res_t;

int computeMPC(const double* x, const double* r, QP_res_t* QP_res, double* u);
