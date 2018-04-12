/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: calculate_cinf.c
 *
 * MATLAB Coder version            : 3.3
 * C/C++ source code generated on  : 12-Apr-2018 13:53:43
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
  static const double a[32] = { -0.4843479682507037, 0.48434796825070708,
    0.48434796825070614, -0.4843479682507057, -0.27934937942804722,
    -0.27934937942804455, -0.27934937942803584, -0.27934937942803328,
    0.55075395902842761, 0.33045237541705591, -0.33045237541705608,
    -0.55075395902842528, -7.2258889899373524E-17, -7.2258889899373561E-17,
    -7.2258889899370973E-17, -7.225888989936937E-17, -1.0852702678268544E-15,
    1.087277909575873E-15, 1.0861884268033708E-15, -1.0870860724476924E-15,
    -7.8587731772362309E-16, -7.8609706004474245E-16, -7.8675628700806986E-16,
    -7.8697602932917058E-16, 1.17396111742276E-15, 7.0090024844079252E-16,
    -7.182823585051129E-16, -1.1913432274870816E-15, 8.5039076133311834E-17,
    8.503907613331192E-17, 8.5039076133308876E-17, 8.5039076133306965E-17 };

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
