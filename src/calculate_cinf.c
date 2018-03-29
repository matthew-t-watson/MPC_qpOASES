/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: calculate_cinf.c
 *
 * MATLAB Coder version            : 3.3
 * C/C++ source code generated on  : 29-Mar-2018 17:32:28
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
  static const double a[32] = { -0.0694519534704588, 0.069451953470324831,
    0.069451953470374611, -0.069451953470375624, -0.056324535074302018,
    -0.056324535074357973, -0.056324535074609716, -0.0563245350747217,
    0.026276917202495649, 0.015766150321477813, -0.015766150321524269,
    -0.026276917202507834, 1.038764722566668E-17, 1.0387647225662153E-17,
    1.0387647225710095E-17, 1.0387647225746601E-17, 3.0989730954461204E-17,
    -3.1003881332004146E-17, -3.1008789723082027E-17, 3.0981550302664647E-17,
    -5.0832622338194805E-17, -5.0825647961270359E-17, -5.0804724830798427E-17,
    -5.0797750454075005E-17, -3.0185142530141731E-17, -1.8437245715310713E-17,
    1.6806444728383171E-17, 2.8554341542681421E-17, 5.020148455196236E-18,
    4.6276580756933726E-18, 3.4501869372352267E-18, 3.0576965577659996E-18 };

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
