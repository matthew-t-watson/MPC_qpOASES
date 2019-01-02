/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: calculate_cinf.c
 *
 * MATLAB Coder version            : 3.3
 * C/C++ source code generated on  : 11-May-2018 14:37:52
 */

/* Include Files */
#include "calculate_cinf.h"

/* Function Definitions */

/*
 * r = zeros(numel(r_reduced)*(8/3),1);
 *  for i=1:numel(r_reduced/3)
 *      r((i-1)*nx+(1:3)) = r_reduced((i-1)*3+(1:3));
 *  end
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
  static const double a[32] = { -0.85447435417628836, 0.85447435417628748,
    0.85447435417628925, -0.85447435417628759, -0.30587748181443664,
    -0.30587748181444274, -0.30587748181444957, -0.30587748181444796,
    0.7566229402454836, 0.45397376414728929, -0.45397376414729168,
    -0.756622940245484, 8.7198178045850213E-16, -6.283684221713555E-16,
    -1.23852384031449E-15, -1.4494391644671948E-16, -1.2890565483135021E-15,
    1.2672638365197819E-15, 1.2778194448962818E-15, -1.2714638676860056E-15,
    1.8878468792273313E-16, 1.9050098476509681E-16, 1.9564987529217809E-16,
    1.973661721345352E-16, 1.5164562410677622E-15, 1.172542997371733E-15,
    -8.3192053115294548E-16, -1.8243163064733673E-15, 1.7711816168603421E-16,
    1.7711816168603886E-16, 1.77118161686044E-16, 1.7711816168604269E-16 };

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
