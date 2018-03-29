/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: calculate_cinf.c
 *
 * MATLAB Coder version            : 3.3
 * C/C++ source code generated on  : 29-Mar-2018 16:15:15
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
  static const double a[32] = { -0.21657776705727153, 0.21657776705726345,
    0.21657776705726281, -0.21657776705727233, -0.183312609396194,
    -0.18331260939617997, -0.18331260939616809, -0.18331260939617419,
    0.081086450122629147, 0.0486518700735788, -0.04865187007357219,
    -0.081086450122622486, -2.9001732531701348E-17, -2.9001732531697386E-17,
    -2.9001732531695235E-17, -2.9001732531697749E-17, -5.5440022140348635E-16,
    5.5397803504320842E-16, 5.5402678840989952E-16, -5.5431896579233386E-16,
    -7.6636319604488286E-16, -7.6632657847077676E-16, -7.6621672574871454E-16,
    -7.6618010817477894E-16, 3.154652244571241E-17, 1.7250847548399447E-17,
    -2.5636177143543672E-17, -3.9931852040859449E-17, -7.96207978915012E-18,
    1.3452315650953928E-17, 1.5204250886100965E-17, -5.0421877305717112E-18 };

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
