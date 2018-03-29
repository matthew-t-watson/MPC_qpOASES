/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: calculate_cinf.c
 *
 * MATLAB Coder version            : 3.3
 * C/C++ source code generated on  : 29-Mar-2018 16:22:47
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
  static const double a[32] = { -0.33963576287978559, 0.33963576287978919,
    0.33963576287978925, -0.3396357628797842, -0.28716235126416767,
    -0.28716235126417922, -0.28716235126418105, -0.28716235126417061,
    0.12637743524605696, 0.075826461147634014, -0.075826461147634222,
    -0.12637743524605682, -1.2959435212255607E-16, 2.8021987994509111E-16,
    2.8021987994509165E-16, -1.2959435212255444E-16, 5.9611545608234728E-16,
    -5.9761302969386035E-16, -5.976942714266071E-16, 5.9598005319443382E-16,
    -3.5163078043127145E-16, -3.5187362682002125E-16, -3.5260216598621064E-16,
    -3.5284501237492045E-16, 4.3434433729910511E-16, 2.5547835629168939E-16,
    -2.8111958673052416E-16, -4.599855677379177E-16, -1.2283725797228996E-16,
    -1.2283725797229715E-16, -1.2283725797229792E-16, -1.2283725797229119E-16 };

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
