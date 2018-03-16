/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: calculate_cinf.c
 *
 * MATLAB Coder version            : 3.3
 * C/C++ source code generated on  : 16-Mar-2018 17:33:42
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
  static const double a[32] = { -4.2798471313115343, 4.2798471313115023,
    4.2798471313115032, -4.2798471313115405, -3.5755894736631548,
    -3.5755894736631388, -3.5755894736632232, -3.5755894736632916,
    1.4730206864601807, 0.8838124118761046, -0.88381241187611359,
    -1.4730206864601831, 1.6302935568659284E-14, 1.6302935568659029E-14,
    1.6302935568659423E-14, 1.6302935568659922E-14, 1.5821065602648335E-14,
    -1.5844384307913261E-14, -1.5839706780399076E-14, 1.5828861481838668E-14,
    6.1198819510601431E-15, 6.1342520917440652E-15, 6.1773625137962718E-15,
    6.1917326544804811E-15, 2.4042329367789282E-15, -1.4865382799708352E-15,
    -9.5721791545959922E-16, 3.2864335442976576E-15, -8.1869029368010046E-16,
    -8.1869029368008764E-16, -8.1869029368010726E-16, -8.1869029368013241E-16 };

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
