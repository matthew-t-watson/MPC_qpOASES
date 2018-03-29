/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: calculate_cinf.c
 *
 * MATLAB Coder version            : 3.3
 * C/C++ source code generated on  : 29-Mar-2018 09:59:55
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
  static const double a[32] = { -0.27838698332796658, 0.27838698332790773,
    0.27838698332790779, -0.27838698332796652, -0.24351192383201825,
    -0.24351192383199496, -0.24351192383203121, -0.2435119238320787,
    0.10388814561031304, 0.062332887366185911, -0.062332887366194793,
    -0.10388814561032154, 1.1597493178756366E-16, -2.1691501996539447E-17,
    -2.1691501996532024E-17, 1.1597493178757606E-16, 9.0429185600755367E-16,
    -9.0416896140738628E-16, -9.0415347499043218E-16, 9.043176667024775E-16,
    -1.7733398529820344E-15, -1.7734396605540302E-15, -1.7737390832722616E-15,
    -1.7738388908457536E-15, -3.8113461925021635E-16, -2.311338506191448E-16,
    2.1886845527406039E-16, 3.6886922390512591E-16, -3.7774671069249563E-17,
    -3.7774671069235616E-17, -3.7774671069241588E-17, -3.7774671069259522E-17 };

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
