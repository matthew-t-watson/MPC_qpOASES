/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: calculate_u.c
 *
 * MATLAB Coder version            : 3.3
 * C/C++ source code generated on  : 29-Mar-2018 09:48:32
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
  static const double c_a[32] = { 0.30444205404276287, -0.30444205404277508,
    -0.30444205404277552, 0.30444205404276231, 0.26623624827845183,
    0.26623624827844233, 0.26623624827849518, 0.26623624827853981,
    -0.11346723370925643, -0.06808034022555004, 0.068080340225568525,
    0.1134672337092746, 0.48952035863246024, 0.48952035863246562,
    0.4895203586325117, 0.48952035863253779, 0.12252933574576119,
    -0.12252933574576118, -0.12252933574576143, 0.12252933574576075,
    0.17713089402752855, 0.17713089402752594, 0.1771308940275548,
    0.17713089402757679, -0.026459427360777735, -0.015875656416465718,
    0.015875656416470218, 0.026459427360782162, 0.06870457288612665,
    0.068704572886127038, 0.0687045728861344, 0.0687045728861389 };

  static const double d_a[160] = { -0.282172009011731, 0.28217200901174078,
    0.28217200901174144, -0.28217200901173056, -0.1887128850170286,
    -0.18871288501701808, -0.18871288501706435, -0.18871288501710554,
    0.099339121232468186, 0.059603472739478185, -0.059603472739491292,
    -0.099339121232481023, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.021001994922410828,
    -0.021001994922412719, -0.021001994922412566, 0.021001994922410738,
    0.065780758487883811, 0.065780758487883992, 0.065780758487888266,
    0.065780758487891, -0.012721563431132279, -0.0076329380586785114,
    0.007632938058682732, 0.012721563431136465, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.019345479160635996, -0.019345479160637721, -0.019345479160637544,
    0.019345479160635934, 0.056125726351519, 0.05612572635151844,
    0.056125726351520848, 0.056125726351523048, -0.010915373490201292,
    -0.0065492240941201164, 0.0065492240941233543, 0.010915373490204498, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.017756395214268649, -0.017756395214269943,
    -0.01775639521426985, 0.017756395214268597, 0.047469961374751714,
    0.047469961374750562, 0.047469961374751415, 0.047469961374753185,
    -0.009243747324463019, -0.0055462483946773214, 0.00554624839467974,
    0.0092437473244654181, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -0.080294330920657214,
    0.080294330920275658, 0.080294330920275464, -0.080294330920656964,
    -0.24678840703014671, -0.24678840703018642, -0.24678840703014579,
    -0.24678840703008087, 0.0469924164243279, 0.028195449854596918,
    -0.028195449854596381, -0.046992416424327582, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
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
