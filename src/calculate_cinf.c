/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: calculate_cinf.c
 *
 * MATLAB Coder version            : 3.3
 * C/C++ source code generated on  : 05-Apr-2018 10:49:18
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
  static const double a[32] = { -0.68083329883860766, 0.68083329883857735,
    0.68083329883857813, -0.680833298838607, -0.27432364478673427,
    -0.274323644786669, -0.27432364478666932, -0.27432364478673521,
    0.35441829258858731, 0.21265097555315296, -0.21265097555315043,
    -0.35441829258858532, 8.3843443827751441E-16, -8.0836907592593409E-16,
    -8.0836907592593508E-16, 8.3843443827751352E-16, -2.5940065679786643E-16,
    2.57594259717158E-16, 2.5782356786844061E-16, -2.59018476545729E-16,
    -2.378720063011972E-15, -2.3786419968823625E-15, -2.3784077984971422E-15,
    -2.3783297323699419E-15, -5.2517038545694486E-16, -2.3596430760028824E-16,
    3.22878267056517E-16, 4.06233905637731E-16, 1.7237325257866489E-18,
    1.723732525785773E-18, 1.7237325257857642E-18, 1.7237325257866372E-18 };

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
