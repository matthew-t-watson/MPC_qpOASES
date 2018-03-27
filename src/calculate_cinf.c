/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: calculate_cinf.c
 *
 * MATLAB Coder version            : 3.3
 * C/C++ source code generated on  : 27-Mar-2018 15:11:54
 */

/* Include Files */
#include "calculate_cinf.h"

/* Function Definitions */

/*
 * CALCULATE_U Summary of this function goes here
 *    Detailed explanation goes here
 * Arguments    : const double x[8]
 *                const double r[80]
 *                double cinf[4]
 * Return Type  : void
 */
void calculate_cinf(const double x[8], const double r[80], double cinf[4])
{
  int i0;
  double b_x[8];
  int i1;
  static const double a[32] = { -0.85582745271410543, 0.85582745271409844,
    0.85582745271409855, -0.85582745271410654, -0.74418945614144272,
    -0.74418945614141851, -0.74418945614134058, -0.74418945614131216,
    0.31268850336328685, 0.18761310201797479, -0.18761310201796033,
    -0.31268850336327175, -8.5768637972819386E-17, -8.5768637972815355E-17,
    -8.5768637972805938E-17, -8.5768637972803633E-17, 2.7317436564865841E-15,
    -2.7379602622402888E-15, -2.7371053471339434E-15, 2.7331685149971641E-15,
    1.335555899852006E-15, 1.3348662663293707E-15, 1.3327973657615061E-15,
    1.3321077322388974E-15, -1.1942414449401848E-15, -7.6573348820510388E-16,
    5.1979038200015075E-16, 9.4829833873524E-16, -1.4050331985657149E-16,
    -1.4050331985656496E-16, -1.4050331985654952E-16, -1.4050331985654568E-16 };

  for (i0 = 0; i0 < 8; i0++) {
    b_x[i0] = x[i0] - r[72 + i0];
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
