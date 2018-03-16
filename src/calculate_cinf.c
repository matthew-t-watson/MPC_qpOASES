/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: calculate_cinf.c
 *
 * MATLAB Coder version            : 3.3
 * C/C++ source code generated on  : 16-Mar-2018 18:05:19
 */

/* Include Files */
#include "calculate_cinf.h"

/* Function Definitions */

/*
 * CALCULATE_U Summary of this function goes here
 *    Detailed explanation goes here
 * Arguments    : const double x[8]
 *                const double r[104]
 *                double cinf[4]
 * Return Type  : void
 */
void calculate_cinf(const double x[8], const double r[104], double cinf[4])
{
  int i0;
  double b_x[8];
  int i1;
  static const double a[32] = { -1.4486461967936948, 1.4486461967936728,
    1.4486461967936739, -1.4486461967936939, -1.2422497669322878,
    -1.2422497669322541, -1.2422497669321935, -1.2422497669321828,
    0.52263244679636189, 0.31357946807781706, -0.31357946807781517,
    -0.52263244679635856, 6.4257933800118968E-15, 6.4257933800115963E-15,
    6.42579338001128E-15, 6.4257933800113486E-15, -2.1908305391639846E-15,
    2.1914563220092526E-15, 2.1954837569461487E-15, -2.1841181476024928E-15,
    -3.5358392944558511E-16, -3.5394615629245651E-16, -3.5503283683310306E-16,
    -3.5539506367999492E-16, 7.6142282406956523E-16, 4.0830598346298958E-16,
    -6.5104453835673952E-16, -1.0041613789633165E-15, 1.2044471270426025E-15,
    1.2044471270425463E-15, 1.2044471270424869E-15, 1.2044471270424997E-15 };

  for (i0 = 0; i0 < 8; i0++) {
    b_x[i0] = x[i0] - r[96 + i0];
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
