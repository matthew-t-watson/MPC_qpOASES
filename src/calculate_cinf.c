/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: calculate_cinf.c
 *
 * MATLAB Coder version            : 3.3
 * C/C++ source code generated on  : 05-Apr-2018 10:13:52
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
  static const double a[32] = { -0.66806777392853678, 0.66806777392849837,
    0.66806777392849825, -0.66806777392853833, -0.25552202563610088,
    -0.255522025636013, -0.255522025636002, -0.25552202563608228,
    0.34073599064034843, 0.20444159438420864, -0.20444159438421083,
    -0.34073599064035076, -2.9858601708370759E-17, -2.985860170834856E-17,
    -2.9858601708347481E-17, -2.9858601708368916E-17, 1.9280237139293535E-15,
    -1.9264812979482862E-15, -1.9271996730190637E-15, 1.9268264221447283E-15,
    -6.0413470254434489E-16, -6.0324987173287173E-16, -6.0059537929977282E-16,
    -5.9971054848917935E-16, -4.2573530448283975E-16, -2.5025227679802183E-16,
    2.7619680625646739E-16, 4.5167983394130913E-16, -3.8695402255453108E-17,
    -3.8695402255424352E-17, -3.8695402255422953E-17, -3.8695402255450729E-17 };

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
