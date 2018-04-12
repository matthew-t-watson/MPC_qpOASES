/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: calculate_cinf.c
 *
 * MATLAB Coder version            : 3.3
 * C/C++ source code generated on  : 12-Apr-2018 14:00:10
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
  static const double a[32] = { -0.48434796825070447, 0.48434796825070231,
    0.48434796825070314, -0.48434796825070353, -0.389211947078057,
    -0.3892119470780338, -0.38921194707802759, -0.3892119470780469,
    0.55075395902842894, 0.33045237541705663, -0.33045237541706035,
    -0.55075395902843283, -4.7092052887911944E-16, -4.7092052887909065E-16,
    -4.709205288790872E-16, -4.7092052887911382E-16, -1.3146926234261619E-15,
    1.3143086572224055E-15, 1.3155977197865509E-15, -1.312544185819254E-15,
    7.9430336177630788E-16, 7.975268997605627E-16, 8.0719751371346769E-16,
    8.1042105169781678E-16, -2.5894416833935E-15, -1.5973262196984512E-15,
    1.535290470986263E-15, 2.6315861344143577E-15, 5.0008873397439478E-17,
    5.0008873397436427E-17, 5.0008873397436051E-17, 5.0008873397438886E-17 };

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
