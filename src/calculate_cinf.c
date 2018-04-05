/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: calculate_cinf.c
 *
 * MATLAB Coder version            : 3.3
 * C/C++ source code generated on  : 05-Apr-2018 15:01:37
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
  static const double a[32] = { -2.8045634935390868, 2.8045634935390877,
    2.8045634935390789, -2.8045634935390713, -0.25552202563602916,
    -0.25552202563602916, -0.25552202563598203, -0.25552202563595039,
    0.340735990640354, 0.20444159438421408, -0.20444159438420639,
    -0.34073599064034721, -3.64800770360909E-17, -3.6480077036096338E-17,
    -3.6480077036088763E-17, -3.6480077036078243E-17, 4.5920875585120305E-15,
    -4.5919165475045723E-15, -4.5925405533980706E-15, 4.5910475486894843E-15,
    -2.4428684441473088E-16, -2.4386051615242825E-16, -2.4258153136535751E-16,
    -2.4215520310294621E-16, -1.076793887791436E-15, -6.47137251985163E-16,
    6.4183265543300421E-16, 1.071489291238844E-15, -1.940029826040836E-17,
    -1.9400298260411503E-17, -1.9400298260407469E-17, -1.940029826040163E-17 };

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
