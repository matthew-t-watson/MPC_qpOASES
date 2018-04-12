/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: calculate_cinf.c
 *
 * MATLAB Coder version            : 3.3
 * C/C++ source code generated on  : 12-Apr-2018 13:37:44
 */

/* Include Files */
#include "calculate_cinf.h"

/* Function Definitions */

/*
 * CALCULATE_U Summary of this function goes here
 *    Detailed explanation goes here
 * Arguments    : const double x[8]
 *                const double r[32]
 *                double cinf[4]
 * Return Type  : void
 */
void calculate_cinf(const double x[8], const double r[32], double cinf[4])
{
  int i0;
  double b_x[8];
  int i1;
  static const double a[32] = { -0.680862381296035, 0.68086238129602661,
    0.68086238129602594, -0.68086238129603571, -0.58536545856868127,
    -0.58536545856864808, -0.58536545856861755, -0.58536545856863276,
    0.76485593802685958, 0.4589135628161175, -0.45891356281610868,
    -0.76485593802685048, 4.0789888511331359E-16, 4.0789888511328125E-16,
    4.0789888511325492E-16, 4.0789888511327144E-16, 2.56548154796472E-15,
    -2.5569052259178945E-15, -2.5617556765637464E-15, 2.5573974635549652E-15,
    3.8513280494892794E-15, 3.8542793844867483E-15, 3.8631333894798254E-15,
    3.8660847244777566E-15, -2.555474345840899E-15, -1.5646008490635261E-15,
    1.56242066065987E-15, 2.6562281703647611E-15, -7.9541921817686463E-17,
    -7.9541921817680152E-17, -7.9541921817675012E-17, -7.9541921817678242E-17 };

  for (i0 = 0; i0 < 8; i0++) {
    b_x[i0] = x[i0] - r[24 + i0];
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
