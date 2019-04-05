/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: rgb2gray.c
 *
 * MATLAB Coder version            : 2.8
 * C/C++ source code generated on  : 05-Apr-2019 15:22:58
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "extract_notes.h"
#include "rgb2gray.h"
#include "extract_notes_rtwutil.h"
#include "libmwimfilter.h"
#include "libmwippfilter.h"

/* Function Definitions */

/*
 * Arguments    : const unsigned char X[493776]
 *                unsigned char I[164592]
 * Return Type  : void
 */
void rgb2gray(const unsigned char X[493776], unsigned char I[164592])
{
  int i;
  unsigned char b_X[3];
  double d1;
  int i4;
  static const double b[3] = { 0.29893602129377539, 0.58704307445112125,
    0.11402090425510336 };

  unsigned char u0;
  for (i = 0; i < 164592; i++) {
    b_X[0] = X[i];
    b_X[1] = X[164592 + i];
    b_X[2] = X[329184 + i];
    d1 = 0.0;
    for (i4 = 0; i4 < 3; i4++) {
      d1 += (double)b_X[i4] * b[i4];
    }

    d1 = rt_roundd_snf(d1);
    if (d1 < 256.0) {
      u0 = (unsigned char)d1;
    } else {
      u0 = MAX_uint8_T;
    }

    I[i] = u0;
  }
}

/*
 * File trailer for rgb2gray.c
 *
 * [EOF]
 */
