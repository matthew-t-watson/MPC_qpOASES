/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: calculate_u.h
 *
 * MATLAB Coder version            : 3.3
 * C/C++ source code generated on  : 29-Mar-2018 09:39:50
 */

#ifndef CALCULATE_U_H
#define CALCULATE_U_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "calculate_u_types.h"

/* Function Declarations */
extern void calculate_u(const double x[8], const double r[40], const double c[20],
  double u[4]);
extern void calculate_u_initialize(void);

#endif

/*
 * File trailer for calculate_u.h
 *
 * [EOF]
 */
