
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

//#pragma pack(push(4))
typedef struct
{
	int32_t id, nWSR, exitFlag;
	const int32_t c_len = NC*NU-1;
	double c[NC * NU];
	const int32_t cinf_len = NU-1;
	double cinf[NU];
	const int32_t s_len = NS-1;
	double s[NS];
	const int32_t u_len = NU-1;
	double u[NU];
	double tExec;
} MPCPacketResult_t;
//#pragma pack(pop)

int configureSockets();
int getPacket(MPCPacketParams_t& buf);
int sendPacket(MPCPacketResult_t& data);

#endif
