
#ifndef NETWORKING_H
#define NETWORKING_H

#include "MPC_defines.hpp"
#include <stdint.h>

typedef struct
{
	int32_t id;
	double x[NX];
	double r[100]; /* We receive more references than we need so that the myRIO doesn't need to know nr at compile time */
} MPCPacketParams_t;

typedef struct
{
	int32_t id, nWSR, exitFlag;
	const int32_t c_len = NC*NU;
	double c[NC * NU];
	int32_t cinf_len;
	double cinf[NU];
	int32_t s_len;
	double s[NS];
	int32_t u_len
	double u[NU], tExec;
} MPCPacketResult_t;

int configureSockets();
int getPacket(MPCPacketParams_t& buf);
int sendPacket(MPCPacketResult_t& data);

#endif
