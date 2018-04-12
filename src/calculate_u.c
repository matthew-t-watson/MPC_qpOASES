/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: calculate_u.c
 *
 * MATLAB Coder version            : 3.3
 * C/C++ source code generated on  : 12-Apr-2018 11:43:14
 */

/* Include Files */
#include "calculate_u.h"

/* Function Definitions */

/*
 * CALCULATE_U Summary of this function goes here
 *    Detailed explanation goes here
 * Arguments    : const double x[8]
 *                const double r[24]
 *                const double c[12]
 *                double u[4]
 * Return Type  : void
 */
void calculate_u(const double x[8], const double r[24], const double c[12],
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

  static const double d_a[96] = { -0.29311996904734622, 0.29311996904728066,
    0.29311996904727555, -0.29311996904735488, -0.20637544540092675,
    -0.20637544540079811, -0.20637544540081459, -0.20637544540095315,
    0.30486312068582955, 0.18291787241149715, -0.1829178724114989,
    -0.30486312068583027, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.014632665089967516,
    -0.014632665089947721, -0.014632665089947035, 0.014632665089968633,
    0.058939770753041167, 0.058939770753036413, 0.058939770753038564,
    0.058939770753044789, -0.044618459234366643, -0.026771075540619915,
    0.026771075540620116, 0.044618459234366754, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    -0.02984223631610183, 0.029842236316115371, 0.029842236316117866,
    -0.029842236316097712, -0.12686024120097367, -0.12686024120111106,
    -0.12686024120109773, -0.12686024120095069, 0.095003625784343335,
    0.0570021754706065, -0.057002175470605, -0.095003625784342433, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0 };

  for (i0 = 0; i0 < 4; i0++) {
    a[i0] = 0.0;
    for (i1 = 0; i1 < 8; i1++) {
      a[i0] += c_a[i0 + (i1 << 2)] * x[i1];
    }

    b_a[i0] = 0.0;
    for (i1 = 0; i1 < 24; i1++) {
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
