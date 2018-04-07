/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: calculate_cinf.c
 *
 * MATLAB Coder version            : 3.3
 * C/C++ source code generated on  : 07-Apr-2018 15:27:47
 */

/* Include Files */
#include "calculate_cinf.h"

/* Function Definitions */

/*
 * CALCULATE_U Summary of this function goes here
 *    Detailed explanation goes here
 * Arguments    : const double x[8]
 *                const double r[24]
 *                double cinf[4]
 * Return Type  : void
 */
void calculate_cinf(const double x[8], const double r[24], double cinf[4])
{
  int i0;
  double b_x[8];
  int i1;
  static const double a[32] = { -0.33965115047792893, 0.33965115047795341,
    0.33965115047795258, -0.3396511504779301, -0.283468761042562,
    -0.28346876104257351, -0.28346876104258367, -0.28346876104257823,
    0.37978813641993869, 0.22787288185196106, -0.2278728818519703,
    -0.37978813641994691, -1.129667504602344E-16, -1.1296675046025112E-16,
    -1.1296675046025797E-16, -1.1296675046024554E-16, -7.6568342110953644E-16,
    7.6299235207720543E-16, 7.6417522674279075E-16, -7.6371196333356041E-16,
    -2.290932370744516E-16, -2.2819390087189306E-16, -2.2549589226413075E-16,
    -2.2459655606151384E-16, -3.8649549766209286E-16, -2.2707153108860081E-16,
    2.5120036863187232E-16, 4.106243352053624E-16, 2.8402874446848986E-17,
    2.8402874446853183E-17, 2.84028744468549E-17, 2.8402874446851784E-17 };

  for (i0 = 0; i0 < 8; i0++) {
    b_x[i0] = x[i0] - r[16 + i0];
  }

  for (i0 = 0; i0 < 4; i0++) {
    cinf[i0] = 0.0;
    for (i1 = 0; i1 < 8; i1++) {
      cinf[i0] += a[i0 + (i1 << 2)] * b_x[i1];
    }
  }
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void calculate_cinf_initialize(void)
{
}

/*
 * File trailer for calculate_cinf.c
 *
 * [EOF]
 */
