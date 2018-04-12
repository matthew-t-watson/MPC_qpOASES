/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: calculate_cinf.c
 *
 * MATLAB Coder version            : 3.3
 * C/C++ source code generated on  : 12-Apr-2018 15:03:59
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
  static const double a[32] = { -0.48434796825071047, 0.48434796825070608,
    0.48434796825070492, -0.48434796825071308, -0.43864384757502817,
    -0.43864384757502695, -0.43864384757502306, -0.43864384757502156,
    0.55075395902842383, 0.33045237541705536, -0.3304523754170523,
    -0.550753959028422, 4.3265076720618604E-16, 4.3265076720617761E-16,
    4.326507672061716E-16, 4.3265076720617594E-16, -7.5635152678443E-16,
    7.5801566035380888E-16, 7.5753719873193577E-16, -7.5714896282088591E-16,
    -1.2847592569974115E-15, -1.2843812393987901E-15, -1.2832471866029839E-15,
    -1.282869169004401E-15, -2.1603983693744093E-15, -1.2635646750351443E-15,
    1.2706661083830952E-15, 2.0633196029893224E-15, 6.74232143571129E-17,
    6.7423214357111588E-17, 6.7423214357110663E-17, 6.7423214357111329E-17 };

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
