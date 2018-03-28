/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: calculate_cinf.c
 *
 * MATLAB Coder version            : 3.3
 * C/C++ source code generated on  : 28-Mar-2018 16:06:35
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
  static const double a[32] = { -0.21657776705733153, 0.21657776705719167,
    0.21657776705719242, -0.21657776705733028, -0.1895548666053978,
    -0.18955486660527671, -0.1895548666053066, -0.18955486660544735,
    0.081086450122620057, 0.048651870073568471, -0.048651870073585395,
    -0.081086450122636489, -1.3131749955607939E-16, -1.3131749955588668E-16,
    -1.3131749955591035E-16, -1.3131749955611866E-16, 7.11539509513733E-16,
    -7.1134766980976879E-16, -7.1129663280222973E-16, 7.1162457119296484E-16,
    -9.7071373919680733E-16, -9.7579617592812651E-16, -9.7542067335525189E-16,
    -9.7008790157534826E-16, 1.5274874317493428E-16, 9.4927599396008029E-17,
    -7.8535831940714494E-17, -1.3635697571960342E-16, 2.2005913603359443E-17,
    2.2005913603327152E-17, 2.2005913603331118E-17, 2.2005913603366022E-17 };

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
