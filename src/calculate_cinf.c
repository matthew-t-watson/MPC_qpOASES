/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: calculate_cinf.c
 *
 * MATLAB Coder version            : 3.3
 * C/C++ source code generated on  : 28-Mar-2018 11:47:15
 */

/* Include Files */
#include "calculate_cinf.h"

/* Function Definitions */

/*
 * CALCULATE_U Summary of this function goes here
 *    Detailed explanation goes here
 * Arguments    : const double x[8]
 *                const double r[56]
 *                double cinf[4]
 * Return Type  : void
 */
void calculate_cinf(const double x[8], const double r[56], double cinf[4])
{
  int i0;
  double b_x[8];
  int i1;
  static const double a[32] = { -4.2996873897653014, 4.299687389765297,
    4.2996873897653076, -4.2996873897653023, -3.6251031782013383,
    -3.6251031782013672, -3.6251031782014547, -3.6251031782014804,
    1.473020686460194, 0.88381241187612136, -0.88381241187610249,
    -1.47302068646018, 3.9671744679526951E-16, 3.9671744679527257E-16,
    3.9671744679528169E-16, 3.9671744679528435E-16, -1.2661174109183868E-15,
    1.2248079546537039E-15, 1.2058736243431894E-15, -1.2976746281025828E-15,
    -1.3665423455739069E-14, -1.3662062078326709E-14, -1.3651977946089641E-14,
    -1.3648616568677275E-14, 4.6571900999684576E-15, -7.8954119623142764E-16,
    -4.8147116506758126E-15, -2.05142732410551E-15, -2.0433443435289722E-15,
    -2.0433443435289868E-15, -2.0433443435290341E-15, -2.0433443435290487E-15 };

  for (i0 = 0; i0 < 8; i0++) {
    b_x[i0] = x[i0] - r[48 + i0];
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
