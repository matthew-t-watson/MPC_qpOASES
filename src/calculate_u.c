/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: calculate_u.c
 *
 * MATLAB Coder version            : 3.3
 * C/C++ source code generated on  : 05-Apr-2018 09:01:59
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
  static const double c_a[32] = { 0.30444205404276448, -0.30444205404277908,
    -0.304442054042778, 0.30444205404276642, 0.25552202563602067,
    0.25552202563606086, 0.25552202563605675, 0.25552202563601439,
    -0.34073599064034465, -0.20444159438420523, 0.20444159438421436,
    0.3407359906403547, 0.52373167791247621, 0.523731677912496,
    0.52373167791249575, 0.52373167791247632, 0.12252933574575679,
    -0.12252933574576705, -0.12252933574576658, 0.12252933574575763,
    0.20908605410004943, 0.20908605410008013, 0.20908605410007727,
    0.20908605410004447, -0.045851570093187667, -0.027510942055912545,
    0.02751094205591299, 0.045851570093188264, 0.060275832873528522,
    0.060275832873532713, 0.060275832873532588, 0.060275832873528265 };

  static const double d_a[160] = { -0.2821720090117335, 0.28217200901174344,
    0.28217200901174272, -0.282172009011735, -0.16683417763942837,
    -0.16683417763946584, -0.16683417763946251, -0.16683417763942349,
    0.26900660238656915, 0.16140396143194055, -0.16140396143194641,
    -0.26900660238657581, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.021001994922410207,
    -0.021001994922413753, -0.021001994922413447, 0.021001994922410575,
    0.07158426107825766, 0.071584261078259478, 0.0715842610782585,
    0.071584261078256, -0.059080659463546709, -0.0354483956781275,
    0.035448395678130046, 0.059080659463549248, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.019345479160635715, -0.0193454791606383, -0.019345479160638088,
    0.019345479160636062, 0.057113868768185139, 0.05711386876818627,
    0.057113868768185153, 0.057113868768183272, -0.043392674594624071,
    -0.026035604756774029, 0.026035604756775965, 0.043392674594625931, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.017756395214268566, -0.017756395214270426,
    -0.017756395214270252, 0.017756395214268861, 0.044464559149780196,
    0.044464559149780786, 0.044464559149779585, 0.0444645591497782,
    -0.029928873971197444, -0.017957324382718149, 0.017957324382719592,
    0.029928873971198814, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -0.08029433092048914,
    0.080294330920439486, 0.080294330920438348, -0.080294330920488433,
    -0.26171845300159696, -0.261718453001554, -0.26171845300155416,
    -0.261718453001595, 0.20410683850854411, 0.12246410310512602,
    -0.12246410310512681, -0.204106838508544, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

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
