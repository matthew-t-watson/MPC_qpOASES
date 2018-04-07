/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: calculate_cinf.c
 *
 * MATLAB Coder version            : 3.3
 * C/C++ source code generated on  : 07-Apr-2018 11:04:09
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
  static const double a[32] = { -0.47670785986399078, 0.47670785986398329,
    0.47670785986398456, -0.47670785986398906, -0.38992534506043103,
    -0.38992534506040327, -0.38992534506037113, -0.3899253450603779,
    0.52493890514597252, 0.31496334308758317, -0.31496334308758017,
    -0.52493890514596664, -2.6291307728274766E-16, -2.6291307728272336E-16,
    -2.6291307728269925E-16, -2.6291307728270792E-16, -4.5479371297899059E-16,
    4.5815612143668269E-16, 4.5673270774842919E-16, -4.5716606912608018E-16,
    8.355753217729014E-17, 8.1501462256989871E-17, 7.5333252496103843E-17,
    7.3277182575813508E-17, 5.3661008483132488E-17, 4.1696278074698552E-17,
    5.8020868494021425E-18, -6.1626435590281884E-18, -1.3239463471853827E-16,
    -7.0004710068143909E-18, 6.6423690180466172E-17, -1.002103273973736E-17 };

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
