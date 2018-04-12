/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: calculate_cinf.c
 *
 * MATLAB Coder version            : 3.3
 * C/C++ source code generated on  : 12-Apr-2018 14:41:36
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
  static const double a[32] = { -0.34422306149019449, 0.34422306149021265,
    0.34422306149021192, -0.34422306149019521, -0.2918507635270991,
    -0.29185076352714973, -0.29185076352724687, -0.29185076352726091,
    0.39544173723153148, 0.23726504233891865, -0.23726504233891976,
    -0.39544173723153242, 1.7102602785370155E-16, -2.4993329665312035E-16,
    -2.4993329665313316E-16, 1.7102602785367989E-16, -9.6265589606361238E-16,
    9.6363303960219962E-16, 9.6345328671999061E-16, -9.62955484200626E-16,
    -3.8071060735912612E-16, -3.8139505273870571E-16, -3.8344838887729118E-16,
    -3.8413283425676861E-16, -1.0020816511835274E-15, -5.9838475133380346E-16,
    6.127059482153717E-16, 1.0164028480650977E-15, -1.3522558904341489E-17,
    -1.3522558904344803E-17, -1.3522558904349343E-17, -1.3522558904349052E-17 };

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
