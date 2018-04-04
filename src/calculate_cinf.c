/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: calculate_cinf.c
 *
 * MATLAB Coder version            : 3.3
 * C/C++ source code generated on  : 04-Apr-2018 14:09:57
 */

/* Include Files */
#include "calculate_cinf.h"

/* Function Definitions */

/*
 * CALCULATE_U Summary of this function goes here
 *    Detailed explanation goes here
 * Arguments    : const double x[8]
 *                const double r[64]
 *                double cinf[4]
 * Return Type  : void
 */
void calculate_cinf(const double x[8], const double r[64], double cinf[4])
{
  int i0;
  double b_x[8];
  int i1;
  static const double a[32] = { -0.33963576287979347, 0.33963576287980651,
    0.3396357628798059, -0.33963576287979463, -0.28357664086436979,
    -0.2835766408644162, -0.2835766408644127, -0.283576640864364,
    0.37838334504799687, 0.22703000702879828, -0.22703000702879719,
    -0.37838334504799576, 4.2171179889877584E-16, 4.2171179889886636E-16,
    4.2171179889885995E-16, 4.2171179889876519E-16, -6.0528135345588021E-16,
    6.047550145558012E-16, 6.0541307603820638E-16, -6.0418458431853842E-16,
    5.1096338472148487E-16, 5.1002066190567686E-16, 5.0719249345791716E-16,
    5.062497706418856E-16, 8.2742241207702136E-16, 4.957811931071695E-16,
    -4.9914246380238994E-16, -8.3078368277224476E-16, -3.338710971306498E-17,
    -3.3387109713072142E-17, -3.3387109713071643E-17, -3.3387109713064148E-17 };

  for (i0 = 0; i0 < 8; i0++) {
    b_x[i0] = x[i0] - r[56 + i0];
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
