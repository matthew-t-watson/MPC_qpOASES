/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: calculate_u.c
 *
 * MATLAB Coder version            : 3.3
 * C/C++ source code generated on  : 11-Apr-2018 15:24:07
 */

/* Include Files */
#include "calculate_u.h"

/* Function Definitions */

/*
 * CALCULATE_U Summary of this function goes here
 *    Detailed explanation goes here
 * Arguments    : const double x[8]
 *                const double r[40]
 *                const double c[20]
 *                double u[4]
 * Return Type  : void
 */
void calculate_u(const double x[8], const double r[40], const double c[20],
                 double u[4])
{
  int i0;
  double a[4];
  int i1;
  double b_a[4];
  static const double c_a[32] = { 0.30832954027351622, -0.3083295402734274,
    -0.30832954027342152, 0.3083295402735261, 0.2742959158483208,
    0.27429591584818586, 0.27429591584820495, 0.27429591584835161,
    -0.3552482872358127, -0.21314897234148697, 0.21314897234148913,
    0.35524828723581386, 0.53035135916221021, 0.53035135916214171,
    0.53035135916215226, 0.53035135916222764, 0.12344843625119062,
    -0.1234484362511493, -0.12344843625114732, 0.12344843625119396,
    0.22890828125385118, 0.22890828125374285, 0.22890828125375667,
    0.22890828125387419, -0.048250513436567451, -0.028950308061940468,
    0.028950308061941384, 0.048250513436568956, 0.06035127346909544,
    0.060351273469081611, 0.060351273469083526, 0.060351273469098687 };

  static const double d_a[160] = { -0.29311996904734633, 0.29311996904728022,
    0.29311996904727516, -0.29311996904735477, -0.20637544540092734,
    -0.20637544540079816, -0.20637544540081459, -0.20637544540095371,
    0.3048631206858296, 0.18291787241149723, -0.18291787241149896,
    -0.30486312068583038, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.014632665089967408,
    -0.014632665089948158, -0.014632665089947398, 0.014632665089968709,
    0.058939770753040611, 0.058939770753036393, 0.0589397707530386,
    0.058939770753044275, -0.044618459234366553, -0.026771075540619835,
    0.026771075540620089, 0.044618459234366643, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.013873618794927621, -0.01387361879491145, -0.013873618794910779,
    0.013873618794928778, 0.050933359331113981, 0.050933359331111108,
    0.050933359331112933, 0.050933359331117013, -0.037260201696625639,
    -0.022356121017975281, 0.022356121017975385, 0.037260201696625465, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.013134706180148007, -0.013134706180134752,
    -0.01313470618013414, 0.01313470618014906, 0.043558280970358222,
    0.043558280970356494, 0.043558280970357986, 0.043558280970360706,
    -0.030541614925544462, -0.018324968955326589, 0.018324968955326558,
    0.030541614925544119, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -0.056850561291185937,
    0.0568505612911528, 0.056850561291156031, -0.056850561291180927,
    -0.22135188150246321, -0.22135188150258139, -0.2213518815025709,
    -0.22135188150244633, 0.16280544240651432, 0.097683265443908471,
    -0.097683265443909387, -0.16280544240651543, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  for (i0 = 0; i0 < 4; i0++) {
    a[i0] = 0.0;
    for (i1 = 0; i1 < 8; i1++) {
      a[i0] += c_a[i0 + (i1 << 2)] * x[i1];
    }

    b_a[i0] = 0.0;
    for (i1 = 0; i1 < 40; i1++) {
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
