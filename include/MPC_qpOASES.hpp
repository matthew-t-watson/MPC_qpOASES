
#ifndef MPC_QPOASES_H
#define MPC_QPOASES_H

#include "MPC_defines.hpp"

int initMPC(qpOASES::QProblem& QP);
int computeMPC(qpOASES::QProblem& QP, MPCPacketParams_t& params, MPCPacketResult_t& res);


#endif
