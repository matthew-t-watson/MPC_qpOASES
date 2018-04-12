/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: calculate_u.c
 *
 * MATLAB Coder version            : 3.3
 * C/C++ source code generated on  : 12-Apr-2018 15:22:24
 */

/* Include Files */
#include "calculate_u.h"

/* Function Definitions */

/*
 * CALCULATE_U Summary of this function goes here
 *    Detailed explanation goes here
 * Arguments    : const double x[8]
 *                const double r[24]
 *                const double c[12]
 *                double u[4]
 * Return Type  : void
 */
void calculate_u(const double x[8], const double r[24], const double c[12],
                 double u[4])
{
  int i0;
  double a[4];
  int i1;
  double b_a[4];
  static const double c_a[32] = { 0.68086238129605214, -0.68086238129605625,
    -0.6808623812960487, 0.68086238129606469, 0.620984563914527,
    0.62098456391452161, 0.62098456391452028, 0.62098456391452417,
    -0.7648559380268507, -0.45891356281611068, 0.45891356281611362,
    0.76485593802685625, 0.4922214613140713, 0.49222146131406969,
    0.49222146131406963, 0.49222146131407124, 0.18344576705054838,
    -0.18344576705054977, -0.18344576705054813, 0.18344576705055107,
    0.32846887978900058, 0.32846887978899864, 0.32846887978899864,
    0.32846887978900052, -0.070798778374848714, -0.042479267024909423,
    0.042479267024909236, 0.07079877837484902, 0.06779644812337085,
    0.0677964481233706, 0.0677964481233706, 0.06779644812337085 };

  static const double d_a[96] = { -0.6312596262526019, 0.631259626252603,
    0.63125962625259735, -0.63125962625261145, -0.47893040616325655,
    -0.47893040616324989, -0.47893040616324872, -0.47893040616325422,
    0.60852417540646186, 0.36511450524387717, -0.36511450524387962,
    -0.608524175406466, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.046790307582514949,
    -0.046790307582517912, -0.046790307582516268, 0.0467903075825176,
    0.12595371553917514, 0.12595371553917653, 0.12595371553917634,
    0.12595371553917464, -0.12965606347572076, -0.077793638085432562,
    0.077793638085433062, 0.12965606347572184, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    -0.096393062625924439, 0.0963930626259705, 0.096393062625974218,
    -0.096393062625917833, -0.26800787329050563, -0.26800787329047138,
    -0.26800787329047493, -0.26800787329050818, 0.28598782609610757,
    0.17159269565766216, -0.17159269565766386, -0.28598782609610129, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0 };

  for (i0 = 0; i0 < 4; i0++) {
    a[i0] = 0.0;
    for (i1 = 0; i1 < 8; i1++) {
      a[i0] += c_a[i0 + (i1 << 2)] * x[i1];
    }

    b_a[i0] = 0.0;
    for (i1 = 0; i1 < 24; i1++) {
      b_a[i0] += d_a[i0 + (i1 << 2)] * r[i1];
    }

    u[i0] = (a[i0] + b_a[i0]) + c[i0];
  }
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void calculate_u_initialize(void)
{
}

/*
 * File trailer for calculate_u.c
 *
 * [EOF]
 */
