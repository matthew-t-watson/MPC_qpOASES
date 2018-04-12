/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: calculate_cinf.c
 *
 * MATLAB Coder version            : 3.3
 * C/C++ source code generated on  : 12-Apr-2018 14:06:09
 */

/* Include Files */
#include "calculate_cinf.h"

/* Function Definitions */

/*
 * CALCULATE_U Summary of this function goes here
 *    Detailed explanation goes here
 * Arguments    : const double x[8]
 *                const double r[40]
 *                double cinf[4]
 * Return Type  : void
 */
void calculate_cinf(const double x[8], const double r[40], double cinf[4])
{
  int i0;
  double b_x[8];
  int i1;
  static const double a[32] = { -0.48434796825069476, 0.48434796825074322,
    0.48434796825074328, -0.48434796825069493, -0.42357238006682479,
    -0.42357238006692327, -0.42357238006691073, -0.42357238006680381,
    0.55075395902842461, 0.33045237541705613, -0.33045237541705008,
    -0.55075395902841917, -2.3397457642688031E-16, -2.3397457642696418E-16,
    -2.3397457642695481E-16, -2.3397457642686473E-16, 2.7670440571022438E-16,
    -2.7639638224177578E-16, -2.7671456117759197E-16, 2.7617410748386425E-16,
    -7.1776466279858938E-16, -7.1615391589458877E-16, -7.113216751817914E-16,
    -7.0971092827726019E-16, -1.0702536724826095E-15, -6.36606395831759E-16,
    6.6433543412077833E-16, 1.0979827107716196E-15, -2.1758983236364612E-17,
    -4.8700092436424261E-17, -1.2952342003650371E-16, -1.5646452923649706E-16 };

  for (i0 = 0; i0 < 8; i0++) {
    b_x[i0] = x[i0] - r[32 + i0];
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
