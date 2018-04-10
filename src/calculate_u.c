/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: calculate_u.c
 *
 * MATLAB Coder version            : 3.3
 * C/C++ source code generated on  : 10-Apr-2018 13:15:38
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
  static const double c_a[32] = { 0.30832954027351622, -0.3083295402734274,
    -0.30832954027342152, 0.3083295402735261, 0.2742959158483208,
    0.27429591584818586, 0.27429591584820495, 0.27429591584835161,
    -0.3552482872358127, -0.21314897234148697, 0.21314897234148913,
    0.35524828723581386, 0.53035135916221021, 0.53035135916214171,
    0.53035135916215226, 0.53035135916222764, 0.12344843625119062,
    -0.1234484362511493, -0.12344843625114732, 0.12344843625119396,
    0.22890828125385118, 0.22890828125374285, 0.22890828125375667,
    0.22890828125387419, -0.048250513436567451, -0.028950308061940468,
    0.028950308061941384, 0.048250513436568956, 0.06035127346909544,
    0.060351273469081611, 0.060351273469083526, 0.060351273469098687 };

  static const double d_a[64] = { -0.29311996904734633, 0.29311996904728022,
    0.29311996904727516, -0.29311996904735482, -0.20637544540092756,
    -0.20637544540079866, -0.20637544540081526, -0.20637544540095415,
    0.30486312068582933, 0.18291787241149698, -0.18291787241149893,
    -0.30486312068583032, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -0.015209571226103363,
    0.015209571226191012, 0.015209571226195881, -0.01520957122609495,
    -0.067920470447958875, -0.067920470448084413, -0.067920470448060669,
    -0.067920470447920045, 0.0503851665499738, 0.030231099929983574,
    -0.030231099929988611, -0.050385166549979883, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
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
