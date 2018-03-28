/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: calculate_u.c
 *
 * MATLAB Coder version            : 3.3
 * C/C++ source code generated on  : 28-Mar-2018 15:41:27
 */

/* Include Files */
#include "calculate_u.h"

/* Function Definitions */

/*
 * CALCULATE_U Summary of this function goes here
 *    Detailed explanation goes here
 * Arguments    : const double x[8]
 *                const double r[80]
 *                const double c[40]
 *                double u[4]
 * Return Type  : void
 */
void calculate_u(const double x[8], const double r[80], const double c[40],
                 double u[4])
{
  int i0;
  double a[4];
  int i1;
  double b_a[4];
  static const double c_a[32] = { 0.476682179008755, -0.47668217900876847,
    -0.47668217900876808, 0.47668217900875565, 0.4161416330924268,
    0.4161416330924631, 0.416141633092493, 0.41614163309247565,
    -0.17636440803533379, -0.10581864482119915, 0.1058186448212059,
    0.17636440803534131, 0.570733805307602, 0.5707338053076223,
    0.57073380530764062, 0.57073380530763262, 0.15332120200724031,
    -0.15332120200724628, -0.15332120200724614, 0.15332120200724061,
    0.24613451369365874, 0.24613451369367403, 0.24613451369368691,
    0.2461345136936805, -0.0329875969687093, -0.019792558181225335,
    0.019792558181226622, 0.032987596968710634, 0.082488455597141949,
    0.082488455597145238, 0.082488455597148139, 0.0824884555971468 };

  static const double d_a[320] = { -0.43325814814609243, 0.43325814814609642,
    0.43325814814610103, -0.43325814814608471, -0.28825940962770163,
    -0.28825940962773411, -0.28825940962775942, -0.28825940962774282,
    0.14921130854878284, 0.0895267851292699, -0.089526785129273312,
    -0.1492113085487892, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.040316101574859278,
    -0.0403161015748684, -0.040316101574863, 0.040316101574868222,
    0.10773332393406981, 0.10773332393407252, 0.10773332393407573,
    0.1077333239340753, -0.023757603562184874, -0.014254562137309738,
    0.01425456213731249, 0.023757603562185509, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.036279199826427209, -0.036279199826435952, -0.036279199826430207,
    0.036279199826436445, 0.091597848319291367, 0.091597848319293157,
    0.09159784831929535, 0.091597848319295086, -0.0194450277102251,
    -0.011667016626133979, 0.011667016626136244, 0.019445027710225282, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.032452239260515874, -0.032452239260524422,
    -0.032452239260518385, 0.032452239260525644, 0.076928144254654815,
    0.076928144254655842, 0.076928144254657146, 0.076928144254657049,
    -0.015546300819540526, -0.0093277804917233312, 0.00932778049172519,
    0.01554630081954035, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.028832741374747249,
    -0.028832741374755482, -0.028832741374749237, 0.028832741374757342,
    0.063648734662437853, 0.063648734662438269, 0.063648734662438866,
    0.063648734662438908, -0.012047854880095533, -0.0072287129280564225,
    0.00722871292805794, 0.012047854880095075, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.02541755103523417, -0.025417551035242059, -0.025417551035235676,
    0.025417551035244474, 0.051680069001023538, 0.051680069001023475,
    0.051680069001023524, 0.051680069001023655, -0.008933062110887121,
    -0.0053598372665314524, 0.0053598372665326858, 0.0089330621108864409, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.022202911839370554, -0.022202911839377996,
    -0.02220291183937164, 0.02220291183938088, 0.040940505191426738,
    0.040940505191426321, 0.04094050519142594, 0.040940505191426141,
    -0.0061829199214978288, -0.0037097519528979423, 0.003709751952898941,
    0.0061829199214969788, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.019184537228720586,
    -0.01918453722872758, -0.019184537228721255, 0.019184537228730834,
    0.031347890563946483, 0.0313478905639458, 0.031347890563945137,
    0.031347890563945352, -0.0037766609633557249, -0.0022659965780127403,
    0.002265996578013546, 0.003776660963354753, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.016357677429833833, -0.016357677429840334, -0.016357677429834159,
    0.01635767742984387, 0.022820807699770185, 0.022820807699769321,
    0.022820807699768453, 0.022820807699768714, -0.0016922919569825618,
    -0.001015375174188897, 0.0010153751741895452, 0.0016922919569815082, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, -0.26438007992900664, 0.26438007992907547,
    0.26438007992901458, -0.2643800799291115, -0.61445395677696069,
    -0.61445395677693337, -0.614453956776914, -0.61445395677693049,
    0.11852070642497724, 0.071112423854991724, -0.071112423854985007,
    -0.11852070642498408, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  for (i0 = 0; i0 < 4; i0++) {
    a[i0] = 0.0;
    for (i1 = 0; i1 < 8; i1++) {
      a[i0] += c_a[i0 + (i1 << 2)] * x[i1];
    }

    b_a[i0] = 0.0;
    for (i1 = 0; i1 < 80; i1++) {
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
