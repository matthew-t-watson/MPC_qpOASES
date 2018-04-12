/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: calculate_cinf.c
 *
 * MATLAB Coder version            : 3.3
 * C/C++ source code generated on  : 12-Apr-2018 15:19:15
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
  static const double a[32] = { -1.0661088395220981, 1.0661088395221192,
    1.066108839522125, -1.0661088395220879, -0.97049851766630724,
    -0.97049851766631612, -0.97049851766636186, -0.97049851766638684,
    1.1743229845904151, 0.70459379075424622, -0.7045937907542591,
    -1.1743229845904271, 1.5305114543517932E-15, 1.5305114543518626E-15,
    1.5305114543519482E-15, 1.5305114543519409E-15, 5.7434868829653143E-15,
    -5.7502595270166864E-15, -5.7469722750013544E-15, 5.7489656363241985E-15,
    -6.0024630319970122E-17, -5.8910563005410451E-17, -5.556836106172689E-17,
    -5.4454293747164384E-17, -3.0179233245476597E-16, -6.3784537691805385E-17,
    2.716789772429264E-16, 2.5731352576978718E-16, -3.4129277732360016E-16,
    -2.1880991150610139E-16, 1.486386859463717E-16, 2.7112155176385485E-16 };

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
