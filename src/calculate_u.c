/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: calculate_u.c
 *
 * MATLAB Coder version            : 3.3
 * C/C++ source code generated on  : 07-Apr-2018 16:47:48
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
  static const double c_a[32] = { 0.30445509901801671, -0.30445509901801976,
    -0.30445509901802, 0.30445509901801615, 0.25548454739003867,
    0.25548454739002541, 0.25548454739003867, 0.25548454739006016,
    -0.34193249269737191, -0.20515949561842473, 0.20515949561841781,
    0.34193249269736559, 0.50404655977047219, 0.504046559770468,
    0.50404655977047219, 0.504046559770479, 0.12267036325482811,
    -0.122670363254826, -0.12267036325482603, 0.12267036325482801,
    0.21391222952388655, 0.21391222952387476, 0.21391222952388161,
    0.21391222952389732, -0.047337588366830448, -0.02840255302009816,
    0.028402553020098691, 0.047337588366830968, 0.057574581489528369,
    0.057574581489527113, 0.05757458148952805, 0.057574581489529895 };

  static const double d_a[96] = { -0.28220828275791032, 0.2822082827579106,
    0.2822082827579106, -0.28220828275790993, -0.16676077807297507,
    -0.16676077807296075, -0.16676077807297129, -0.16676077807299211,
    0.27185043334027781, 0.16311026000416795, -0.16311026000416315,
    -0.271850433340274, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.020981516160918614,
    -0.02098151616092114, -0.020981516160921389, 0.020981516160918368,
    0.071545368783166988, 0.0715453687831682, 0.071545368783170346,
    0.071545368783170582, -0.058086794933358242, -0.034852076960015181,
    0.034852076960013363, 0.058086794933356029, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    -0.043228332420977789, 0.043228332421055955, 0.0432283324210519,
    -0.043228332420985109, -0.16026913810021004, -0.16026913810017815,
    -0.16026913810016988, -0.16026913810019647, 0.12816885429044647,
    0.076901312574268438, -0.076901312574269479, -0.12816885429045011, 0.0, 0.0,
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
