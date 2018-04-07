/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: calculate_cinf.c
 *
 * MATLAB Coder version            : 3.3
 * C/C++ source code generated on  : 07-Apr-2018 16:12:24
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
  static const double a[32] = { -0.30445509901804696, 0.30445509901804119,
    0.30445509901804158, -0.30445509901804679, -0.23096753799721814,
    -0.23096753799724035, -0.23096753799722505, -0.23096753799719164,
    0.34193249269737647, 0.20515949561842631, -0.20515949561842653,
    -0.3419324926973783, -8.7955521326385866E-17, 2.41355838430374E-16,
    2.4135583843036914E-16, -8.7955521326394556E-17, -1.2551183560824067E-17,
    1.2426744263356895E-17, 1.2405083228275097E-17, -1.2587285285960416E-17,
    -7.475874331942365E-16, -7.4735741788950239E-16, -7.466673719751058E-16,
    -7.4643735667023877E-16, 1.1804678875367408E-15, 7.2648851393812988E-16,
    -6.9719548681210007E-16, -1.1923387803803092E-15, -1.0345006175645931E-17,
    -1.0345006175646611E-17, -1.0345006175645965E-17, -1.034500617564481E-17 };

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
