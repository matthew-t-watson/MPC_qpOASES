//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: calculate_cinf.cpp
//
// MATLAB Coder version            : 4.0
// C/C++ source code generated on  : 08-Jan-2019 13:28:48
//

// Include Files
#include "calculate_cinf.h"

// Function Definitions

//
// r = zeros(numel(r_reduced)*(8/3),1);
//  for i=1:numel(r_reduced/3)
//      r((i-1)*nx+(1:3)) = r_reduced((i-1)*3+(1:3));
//  end
// Arguments    : const real_T x[8]
//                const real_T r[24]
//                real_T cinf[4]
// Return Type  : void
//
void calculate_cinf(const real_T x[8], const real_T r[24], real_T cinf[4])
{
  int32_T i0;
  real_T b_x[8];
  int32_T i1;
  static const real_T a[32] = { 0.88125647921141126, -0.88125647921140782,
    -0.88125647921140771, 0.88125647921141059, 0.583668652277088,
    0.58366865227708586, 0.5836686522770882, 0.583668652277092,
    0.717394931172277, 0.43043695870336562, -0.43043695870336779,
    -0.71739493117227926, 1.1223087651614879E-17, 1.1223087651614754E-17,
    1.122308765161483E-17, 1.1223087651615008E-17, -1.1884242435922185E-15,
    1.1725124535061155E-15, 1.1647688205934875E-15, -1.2013302984465973E-15,
    -1.493820832792277E-15, -1.4993293159696098E-15, -1.5158547655016717E-15,
    -1.5213632486790466E-15, 1.919108715726062E-15, 1.2015208944094381E-15,
    -9.5124256954042461E-16, -1.6688303908570436E-15, 2.7666633172383861E-17,
    -1.1860725398759851E-16, -5.5742891546755861E-16, -7.0370280262755E-16 };

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

//
// Arguments    : void
// Return Type  : void
//
void calculate_cinf_initialize()
{
}

//
// File trailer for calculate_cinf.cpp
//
// [EOF]
//
