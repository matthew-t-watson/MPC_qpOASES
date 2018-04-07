/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: calculate_cinf.c
 *
 * MATLAB Coder version            : 3.3
 * C/C++ source code generated on  : 07-Apr-2018 10:54:57
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
  static const double a[32] = { -0.24170725923509062, 0.24170725923507511,
    0.2417072592350778, -0.24170725923508651, -0.20486618711088811,
    -0.20486618711086421, -0.20486618711084198, -0.20486618711085061,
    0.27377684844468841, 0.16426610906681574, -0.16426610906680644,
    -0.2737768484446822, 8.3848035319888822E-17, -1.2371002134882178E-16,
    -1.2371002134881978E-16, 8.3848035319892359E-17, 1.0474246090629953E-16,
    -1.0506755678875696E-16, -1.0504487861065512E-16, 1.047802578698028E-16,
    -1.1296566014225492E-15, -1.129331037653947E-15, -1.1283543463486468E-15,
    -1.1280287825803797E-15, -5.4791334518145364E-16, -3.2586012595988986E-16,
    3.4029953170478981E-16, 5.623527509263464E-16, 5.2112153036285212E-17,
    5.2112153036275013E-17, 5.2112153036267796E-17, 5.2112153036273059E-17 };

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
