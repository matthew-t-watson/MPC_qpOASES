
#ifndef NETWORKING_H
#define NETWORKING_H

#include "MPC_defines.hpp"
#include <stdint.h>

typedef struct
{
	int32_t id;
	int32_t pad1;
	double x[NX];
	//int32_t r_len;
	double r[NR*NX];
} MPCPacketParams_t;

typedef struct
{
	int32_t id, nWSR, exitFlag;
	const int32_t c_len = NC*NU;
	double c[NC * NU];
	const int32_t pad2 = 0;
	const int32_t cinf_len = NU;
	double cinf[NU];
	const int32_t pad3 = 0;
	const int32_t s_len = NS;
	double s[NS];
	const int32_t pad4 = 0;
	const int32_t u_len = NU;
	double u[NU];
	double tExec;
	double cost;
} MPCPacketResult_t;

typedef struct
{
	int32_t id, nWSR, exitFlag;
	const int32_t u_len = NU;
	double u[NU];
	double tExec;
	double cost;
} MPCPacketResultReduced_t;

int configureSockets();
int getPacket(MPCPacketParams_t& buf);
int sendPacket(MPCPacketResult_t& data);
int sendPacket(MPCPacketResultReduced_t& data);

#endif
