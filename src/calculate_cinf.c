/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: calculate_cinf.c
 *
 * MATLAB Coder version            : 3.3
 * C/C++ source code generated on  : 07-Apr-2018 17:41:54
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
  static const double a[32] = { -0.30445509901801671, 0.30445509901802009,
    0.30445509901802043, -0.30445509901801637, -0.2554845473900369,
    -0.25548454739002407, -0.25548454739003712, -0.25548454739005877,
    0.34193249269737219, 0.20515949561842486, -0.20515949561841798,
    -0.34193249269736586, 1.060567379240894E-16, 1.0605673792408497E-16,
    1.0605673792408816E-16, 1.0605673792409473E-16, -1.6830819322621078E-16,
    1.6677906638096579E-16, 1.6674712662634912E-16, -1.6836142615057205E-16,
    1.5876484706845139E-15, 1.5867577526165329E-15, 1.5840855984128362E-15,
    1.58319488034502E-15, 2.0277729072195133E-16, 1.2524139352114993E-16,
    -1.0736629808125225E-16, -1.8490219528205229E-16, -7.7045258367413436E-17,
    -7.7045258367410207E-17, -7.7045258367412512E-17, -7.7045258367417282E-17 };

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
