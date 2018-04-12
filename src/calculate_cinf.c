/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: calculate_cinf.c
 *
 * MATLAB Coder version            : 3.3
 * C/C++ source code generated on  : 12-Apr-2018 14:29:28
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
  static const double a[32] = { -0.34422306149018855, 0.34422306149020815,
    0.34422306149020765, -0.34422306149018994, -0.30511244989646952,
    -0.30511244989649555, -0.30511244989647263, -0.30511244989643194,
    0.3954417372315277, 0.23726504233891696, -0.23726504233891668,
    -0.3954417372315282, 2.4978568074518513E-16, 2.4978568074522354E-16,
    2.497856807452049E-16, 2.4978568074515456E-16, -1.3230594430236665E-15,
    1.3252381613397343E-15, 1.3239419545956666E-15, -1.325219787597115E-15,
    3.1418637729546022E-15, 3.1424107267981828E-15, 3.144051588327239E-15,
    3.1445985421697017E-15, 1.5727243278077562E-15, 9.46345753881425E-16,
    -9.3278996789759213E-16, -1.5591685418239384E-15, -9.62652796838091E-17,
    -9.626527968382388E-17, -9.6265279683816694E-17, -9.6265279683797293E-17 };

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
