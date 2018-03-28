/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: calculate_cinf.c
 *
 * MATLAB Coder version            : 3.3
 * C/C++ source code generated on  : 28-Mar-2018 14:26:31
 */

/* Include Files */
#include "calculate_cinf.h"

/* Function Definitions */

/*
 * CALCULATE_U Summary of this function goes here
 *    Detailed explanation goes here
 * Arguments    : const double x[8]
 *                const double r[56]
 *                double cinf[4]
 * Return Type  : void
 */
void calculate_cinf(const double x[8], const double r[56], double cinf[4])
{
  int i0;
  double b_x[8];
  int i1;
  static const double a[32] = { -0.47668217900875492, 0.47668217900876841,
    0.47668217900876841, -0.47668217900875587, -0.41614163309242519,
    -0.41614163309246244, -0.41614163309249169, -0.41614163309247454,
    0.17636440803533399, 0.10581864482119901, -0.10581864482120606,
    -0.1763644080353412, 3.0674223973567245E-16, 3.0674223973571131E-16,
    3.0674223973573418E-16, 3.06742239735711E-16, -6.368182279782121E-16,
    6.414468434124535E-16, 6.4168139607940563E-16, -6.364273068666265E-16,
    9.1195335057138235E-16, 9.123570862717363E-16, 9.135682933725187E-16,
    9.1397202907268766E-16, -2.0462577931151544E-16, -1.1684867570925491E-16,
    1.464826350975291E-16, 2.342597386997913E-16, -9.9634722264357231E-17,
    -9.9634722264369865E-17, -9.963472226437731E-17, -9.9634722264369778E-17 };

  for (i0 = 0; i0 < 8; i0++) {
    b_x[i0] = x[i0] - r[48 + i0];
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
