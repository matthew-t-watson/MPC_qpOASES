/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: calculate_u.c
 *
 * MATLAB Coder version            : 3.3
 * C/C++ source code generated on  : 12-Apr-2018 14:10:33
 */

/* Include Files */
#include "calculate_u.h"

/* Function Definitions */

/*
 * CALCULATE_U Summary of this function goes here
 *    Detailed explanation goes here
 * Arguments    : const double x[8]
 *                const double r[16]
 *                const double c[8]
 *                double u[4]
 * Return Type  : void
 */
void calculate_u(const double x[8], const double r[16], const double c[8],
                 double u[4])
{
  int i0;
  double a[4];
  int i1;
  double b_a[4];
  static const double c_a[32] = { 0.48434796825069493, -0.48434796825074328,
    -0.48434796825074294, 0.48434796825069493, 0.4235723800668233,
    0.42357238006692244, 0.42357238006690962, 0.423572380066803,
    -0.55075395902842461, -0.33045237541705591, 0.33045237541705064,
    0.55075395902841984, 0.70915938501575093, 0.70915938501578868,
    0.70915938501578379, 0.70915938501574372, 0.1547236729418687,
    -0.1547236729418851, -0.15472367294188508, 0.1547236729418687,
    0.339491499003266, 0.33949149900334308, 0.33949149900333453,
    0.33949149900325237, -0.060077901781826294, -0.036046741069095875,
    0.036046741069095355, 0.06007790178182576, 0.077478227820759124,
    0.077478227820768061, 0.077478227820766993, 0.0774782278207573 };

  static const double d_a[64] = { -0.4544984832186717, 0.45449848321870429,
    0.45449848321870379, -0.45449848321867187, -0.30397851645973928,
    -0.30397851645983143, -0.30397851645982088, -0.30397851645972279,
    0.45440362485405822, 0.2726421749124357, -0.27264217491243209,
    -0.454403624854055, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -0.029849485031784175,
    0.029849485032224222, 0.029849485032225852, -0.029849485031785229,
    -0.11959386360727414, -0.11959386360701631, -0.11959386360702691,
    -0.11959386360729689, 0.0963503341743633, 0.057810200504618034,
    -0.057810200504618027, -0.096350334174362923, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  for (i0 = 0; i0 < 4; i0++) {
    a[i0] = 0.0;
    for (i1 = 0; i1 < 8; i1++) {
      a[i0] += c_a[i0 + (i1 << 2)] * x[i1];
    }

    b_a[i0] = 0.0;
    for (i1 = 0; i1 < 16; i1++) {
      b_a[i0] += d_a[i0 + (i1 << 2)] * r[i1];
    }

    u[i0] = (a[i0] + b_a[i0]) + c[i0];
  }
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void calculate_u_initialize(void)
{
}

/*
 * File trailer for calculate_u.c
 *
 * [EOF]
 */
