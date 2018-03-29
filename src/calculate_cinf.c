/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: calculate_cinf.c
 *
 * MATLAB Coder version            : 3.3
 * C/C++ source code generated on  : 29-Mar-2018 17:37:28
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
  static const double a[32] = { -0.21657776705727308, 0.21657776705719503,
    0.21657776705719492, -0.21657776705727394, -0.18877453228731172,
    -0.18877453228721458, -0.18877453228712143, -0.18877453228715615,
    0.081086450122632839, 0.04865187007357985, -0.048651870073579268,
    -0.081086450122632409, -6.0907305317948075E-17, -6.090730531788769E-17,
    -6.090730531785759E-17, -6.090730531789781E-17, 4.8407084972019611E-16,
    -4.8376601438038092E-16, -4.8375030855567414E-16, 4.8409702609470885E-16,
    6.4716333459652184E-16, 6.4713726834490641E-16, 6.4705906959166467E-16,
    6.47033003341118E-16, -1.1313123250302513E-16, -6.7602081762287035E-17,
    6.8985370459937458E-17, 1.1451452120068245E-16, -2.1741251784731592E-17,
    -2.1741251784710037E-17, -2.1741251784699292E-17, -2.1741251784713652E-17 };

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
