/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: calculate_cinf.c
 *
 * MATLAB Coder version            : 3.3
 * C/C++ source code generated on  : 07-Apr-2018 10:01:14
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
  static const double a[32] = { -0.39102407858450478, 0.39102407858449245,
    0.39102407858450139, -0.39102407858448918, -0.32382388528684775,
    -0.32382388528686412, -0.323823885286863, -0.3238238852868468,
    0.43459960405880038, 0.26075976243527887, -0.26075976243528126,
    -0.43459960405879977, 3.1620894452965431E-16, 3.1620894452967063E-16,
    3.1620894452967029E-16, 3.1620894452965456E-16, 1.8775998214559913E-16,
    -1.8410107228387805E-16, -1.8691222839685422E-16, 1.8307472195730516E-16,
    1.8535749026414828E-15, 1.8557516592101549E-15, 1.8622819289158811E-15,
    1.8644586854843651E-15, 1.422283938049459E-16, 8.2209857121148968E-17,
    -9.7845752930224514E-17, -1.578642896140099E-16, -6.7095771254690153E-17,
    -6.7095771254693592E-17, -6.709577125469353E-17, -6.709577125469019E-17 };

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
