/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: calculate_cinf.c
 *
 * MATLAB Coder version            : 3.3
 * C/C++ source code generated on  : 07-Apr-2018 10:07:07
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
  static const double a[32] = { -0.66811057056084977, 0.66811057056086109,
    0.66811057056086087, -0.66811057056085, -0.53275545811238967,
    -0.53275545811236269, -0.53275545811236547, -0.53275545811239389,
    0.72244490357908564, 0.43346694214745152, -0.43346694214745146,
    -0.7224449035790862, 7.7849884921693046E-16, 7.7849884921691162E-16,
    7.7849884921691547E-16, 7.7849884921693657E-16, -2.4692270025926094E-15,
    2.4710201215220685E-15, 2.4711483769109716E-15, -2.4690132436111039E-15,
    3.6187032926787764E-15, 3.6224421230125424E-15, 3.6336586140141252E-15,
    3.6373974443480782E-15, -1.4830777654854343E-15, -8.91781374909165E-16,
    8.821077968196446E-16, 1.4734041873959154E-15, -2.6847600611873467E-17,
    -2.6847600611872811E-17, -2.684760061187295E-17, -2.6847600611873677E-17 };

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
