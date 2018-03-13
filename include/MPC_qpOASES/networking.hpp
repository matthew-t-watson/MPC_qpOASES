
#ifndef NETWORKING_H
#define NETWORKING_H

#include "MPC_defines.hpp"

typedef struct MPCPacketParams_t
{
	double x[NX], r[NX*NR];
	int id;
};

typedef struct MPCPacketResult_t
{
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
	double tExec;
	int nWSR, id, exitFlag;
}

int configureSockets();
int getPacket();
int getInterfaceIP(char* ip, const char* interface);

#endif
