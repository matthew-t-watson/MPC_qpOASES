
#ifndef NETWORKING_H
#define NETWORKING_H

#include "MPC_defines.hpp"

typedef struct MPCPacketParams_t
{
	double x[NX];
	double r[NX*NR];
};

typedef struct MPCPacketResult_t
{
	double x[NX];
	double r[NX*NR];
};

int configureSockets();
int getPacket();
int getInterfaceIP(char* ip, const char* interface);

#endif
