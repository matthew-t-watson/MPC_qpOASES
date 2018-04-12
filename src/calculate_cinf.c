/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: calculate_cinf.c
 *
 * MATLAB Coder version            : 3.3
 * C/C++ source code generated on  : 12-Apr-2018 15:10:24
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
  static const double a[32] = { -0.34422306149020959, 0.34422306149018939,
    0.34422306149020038, -0.34422306149019133, -0.31290452055267637,
    -0.31290452055268453, -0.31290452055271112, -0.31290452055272161,
    0.3954417372315378, 0.23726504233892479, -0.23726504233891665,
    -0.3954417372315312, -3.6095380621518421E-17, -3.6095380621518415E-17,
    -3.6095380621520825E-17, -3.6095380621522544E-17, -1.3803379571653185E-15,
    1.3789328080437127E-15, 1.3789643763484891E-15, -1.3802853433240248E-15,
    1.2532301942036121E-16, 1.2554857203522551E-16, 1.2622522987982671E-16,
    1.2645078249469695E-16, 1.8092956088915041E-15, 1.1032617721667911E-15,
    -1.0937696113521627E-15, -1.8524233636400851E-15, -4.5019395820600755E-17,
    -4.5019395820600743E-17, -4.5019395820603738E-17, -4.5019395820605895E-17 };

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
