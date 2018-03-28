/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: calculate_cinf.c
 *
 * MATLAB Coder version            : 3.3
 * C/C++ source code generated on  : 28-Mar-2018 15:30:55
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
  static const double a[32] = { -1.4524263763705387, 1.4524263763705525,
    1.452426376370558, -1.4524263763705332, -1.2553051552753691,
    -1.2553051552753653, -1.2553051552753141, -1.2553051552752887,
    0.52263244679636189, 0.31357946807781978, -0.3135794680778084,
    -0.52263244679635179, -6.7673344484426729E-15, -2.9229939337787683E-15,
    -2.6318724874215792E-15, -6.2821320378473822E-15, -5.0519138560154752E-15,
    5.0545848541697626E-15, 5.0558136600112931E-15, -5.0498658462796043E-15,
    6.914894380626311E-16, 6.9099172160407351E-16, 6.8949857222834118E-16,
    6.890008557697469E-16, 1.5411251843401998E-15, 1.0263831062459697E-15,
    -5.17843128036617E-16, -1.0325852061307772E-15, 1.6752971871629737E-15,
    1.6752971871629978E-15, 1.6752971871629256E-15, 1.6752971871628605E-15 };

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
