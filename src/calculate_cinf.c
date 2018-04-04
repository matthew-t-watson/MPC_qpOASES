/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: calculate_cinf.c
 *
 * MATLAB Coder version            : 3.3
 * C/C++ source code generated on  : 04-Apr-2018 13:35:55
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
  static const double a[32] = { -0.30444205404276453, 0.30444205404277924,
    0.30444205404277797, -0.30444205404276636, -0.25552202563601933,
    -0.25552202563605952, -0.25552202563605564, -0.25552202563601306,
    0.34073599064034471, 0.20444159438420542, -0.20444159438421425,
    -0.34073599064035459, 1.3030064439929346E-16, 1.3030064439932324E-16,
    1.3030064439932509E-16, 1.3030064439929667E-16, -2.7417433407636288E-16,
    2.7433298794881E-16, 2.7393841408988655E-16, -2.7483195717456841E-16,
    1.1105506370459926E-15, 1.1093530138680556E-15, 1.1057601443335013E-15,
    1.1045625211550703E-15, -3.5626549028159109E-16, -2.166441842434953E-16,
    2.0221973387080385E-16, 3.4184103990890738E-16, -7.0200007194904629E-17,
    -7.0200007194920628E-17, -7.02000071949216E-17, -7.0200007194906317E-17 };

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
