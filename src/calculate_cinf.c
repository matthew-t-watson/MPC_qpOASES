/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: calculate_cinf.c
 *
 * MATLAB Coder version            : 3.3
 * C/C++ source code generated on  : 05-Apr-2018 15:13:30
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
  static const double a[32] = { -1.305085129143817, 1.3050851291438159,
    1.3050851291438201, -1.3050851291438157, -0.25552202563609849,
    -0.25552202563609228, -0.25552202563608645, -0.25552202563608833,
    0.34073599064035109, 0.20444159438421067, -0.20444159438420872,
    -0.34073599064034787, 1.2036843140774722E-16, 1.2036843140774828E-16,
    1.203684314077446E-16, 1.2036843140774091E-16, -3.4587566394780973E-16,
    3.4448378964521719E-16, 3.4491472360338858E-16, -3.4515744068419227E-16,
    3.9513249130489852E-16, 3.9630530810785858E-16, 3.9982375851671832E-16,
    4.0099657531966427E-16, -1.0542638544295178E-16, -6.7822879510485613E-17,
    4.49876382869052E-17, 8.2591144219366254E-17, -1.7079659646329506E-18,
    -1.7079659646329616E-18, -1.7079659646329092E-18, -1.7079659646328607E-18 };

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
