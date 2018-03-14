
#ifndef MPC_QPOASES_H
#define MPC_QPOASES_H

#include "MPC_defines.hpp"

typedef union
{
	double z[NC * NU + NU + NS];
	struct
	{
		double c[NC * NU];
		double cinf[NU];
		double s[NS];
	};
} QPout_t;


#endif
