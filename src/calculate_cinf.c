/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: calculate_cinf.c
 *
 * MATLAB Coder version            : 3.3
 * C/C++ source code generated on  : 29-Mar-2018 09:48:33
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
  static const double a[32] = { -0.30444205404276292, 0.30444205404277541,
    0.30444205404277574, -0.3044420540427622, -0.26623624827845244,
    -0.26623624827844322, -0.2662362482784959, -0.2662362482785407,
    0.11346723370925646, 0.068080340225550082, -0.068080340225568525,
    -0.11346723370927458, 1.1510968209733014E-17, -1.5313060198046111E-16,
    -1.5313060198047647E-16, 1.1510968209707247E-17, -5.597711072262642E-16,
    5.6034378921511718E-16, 5.6042588924759972E-16, -5.5963427383879291E-16,
    -8.0472948620696109E-16, -8.045818280347281E-16, -8.0413885351813741E-16,
    -8.0399119534597808E-16, -1.9755350830952298E-16, -1.2508082239475874E-16,
    9.233723534952338E-17, 1.6480992126428058E-16, -3.2349025890662956E-17,
    -3.2349025890663819E-17, -3.2349025890670789E-17, -3.2349025890674635E-17 };

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
