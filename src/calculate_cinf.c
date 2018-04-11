/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: calculate_cinf.c
 *
 * MATLAB Coder version            : 3.3
 * C/C++ source code generated on  : 10-Apr-2018 17:29:26
 */

/* Include Files */
#include "calculate_cinf.h"

/* Function Definitions */

/*
 * CALCULATE_U Summary of this function goes here
 *    Detailed explanation goes here
 * Arguments    : const double x[8]
 *                const double r[16]
 *                double cinf[4]
 * Return Type  : void
 */
void calculate_cinf(const double x[8], const double r[16], double cinf[4])
{
  int i0;
  double b_x[8];
  int i1;
  static const double a[32] = { -0.30832954027351667, 0.30832954027342746,
    0.30832954027342163, -0.30832954027352638, -0.27429591584832169,
    -0.274295915848187, -0.27429591584820578, -0.27429591584835283,
    0.35524828723581264, 0.21314897234148669, -0.21314897234148919,
    -0.355248287235814, -3.30260538324423E-16, 7.4856674529242539E-18,
    7.4856674529093857E-18, -3.3026053832444772E-16, -9.0011151729039933E-16,
    9.01221820652362E-16, 8.9979486219324344E-16, -9.0248978138893047E-16,
    -1.5653881412073902E-15, -1.5662051012433759E-15, -1.5686559813556151E-15,
    -1.5694729413944553E-15, 1.0862718491298725E-15, 6.4916988267428844E-16,
    -6.621360166925543E-16, -1.0992379831481994E-15, -4.8005775818971355E-17,
    -5.6972920753693063E-17, -8.3874355558052136E-17, -9.2841500492903131E-17 };

  for (i0 = 0; i0 < 8; i0++) {
    b_x[i0] = x[i0] - r[8 + i0];
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
