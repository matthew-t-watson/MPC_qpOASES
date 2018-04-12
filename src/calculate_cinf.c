/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: calculate_cinf.c
 *
 * MATLAB Coder version            : 3.3
 * C/C++ source code generated on  : 12-Apr-2018 15:26:56
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
  static const double a[32] = { -0.680862381296053, 0.68086238129605725,
    0.68086238129604937, -0.68086238129606547, -0.62098456391452683,
    -0.6209845639145225, -0.62098456391452062, -0.62098456391452439,
    0.7648559380268507, 0.4589135628161109, -0.45891356281611329,
    -0.76485593802685614, -1.6039132138938375E-16, 1.4865528854509485E-15,
    1.4865528854509389E-15, -1.6039132138939849E-16, -1.686008418096726E-15,
    1.6902468476759162E-15, 1.6865096567854274E-15, -1.6922370695808723E-15,
    -6.68603504260771E-16, -6.7426533646360811E-16, -6.9125083307215341E-16,
    -6.969126652750139E-16, -7.389309481610743E-16, -4.45847975363278E-16,
    4.3340094303015444E-16, 7.2648391582797974E-16, -1.9547407440712656E-16,
    -2.37041151720445E-16, -3.6174238366042342E-16, -4.0330946097375756E-16 };

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
