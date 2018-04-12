/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: calculate_cinf.c
 *
 * MATLAB Coder version            : 3.3
 * C/C++ source code generated on  : 12-Apr-2018 14:47:21
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
  static const double a[32] = { -0.34422306149020049, 0.34422306149019533,
    0.34422306149019477, -0.34422306149020138, -0.31446513702233719,
    -0.31446513702232864, -0.31446513702231965, -0.31446513702232176,
    0.39544173723153292, 0.23726504233891776, -0.23726504233892479,
    -0.39544173723153797, 5.6048343819549992E-17, 5.6048343819547588E-17,
    5.6048343819546812E-17, 5.6048343819548611E-17, -1.3568297751787599E-15,
    1.3559237277561967E-15, 1.3563638480953562E-15, -1.3560962412801607E-15,
    2.3310126610625695E-15, 2.3324906466205606E-15, 2.3369246032947976E-15,
    2.3384025888529625E-15, 1.3246013757154639E-15, 8.0105043918459678E-16,
    -7.6960237040800329E-16, -1.2931533069388695E-15, 1.6285528076675126E-17,
    1.6285528076674436E-17, 1.6285528076674205E-17, 1.6285528076674726E-17 };

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
