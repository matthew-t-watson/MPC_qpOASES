
#ifndef NETWORKING_H
#define NETWORKING_H

#include "MPC_defines.hpp"

typedef struct
{
	int id;
	double x[NX], r[NX*NR];
} MPCPacketParams_t;

typedef struct
{
	int id, nWSR, exitFlag;
	union
	{
		double z[NC * NU + NU + NS];
		struct
		{
			double c[NC * NU];
			double cinf[NU];
			double s[NS];
		};
	};
	double u[NU], tExec;
} MPCPacketResult_t;

int configureSockets();
int getPacket(MPCPacketParams_t& buf);
int sendPacket(MPCPacketResult_t& data);

#endif
