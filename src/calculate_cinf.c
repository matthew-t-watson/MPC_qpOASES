/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: calculate_cinf.c
 *
 * MATLAB Coder version            : 3.3
 * C/C++ source code generated on  : 29-Mar-2018 09:39:51
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
  static const double a[32] = { -0.33963576287977748, 0.33963576287982677,
    0.33963576287982677, -0.3396357628797772, -0.296911151824368,
    -0.29691115182451489, -0.29691115182454236, -0.29691115182441447,
    0.12637743524605261, 0.075826461147632265, -0.075826461147629282,
    -0.12637743524605002, -1.3074452817379435E-16, -1.9779775133819796E-17,
    5.7538099354595814E-18, -8.818855305832879E-17, -3.9464445256537041E-16,
    3.9444006175030115E-16, 3.9435432002726279E-16, -3.9478735543710066E-16,
    -6.0567801717628834E-16, -6.0584989960651834E-16, -6.0636554689601973E-16,
    -6.0653742932545871E-16, 2.5947744191620743E-16, 1.4316508841921493E-16,
    -2.057719720717004E-16, -3.2208432556865163E-16, -2.0545952103640326E-18,
    -2.0545952103654374E-18, -2.0545952103656227E-18, -2.0545952103643458E-18 };

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
