/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: rgb2gray.c
 *
 * MATLAB Coder version            : 2.8
 * C/C++ source code generated on  : 02-Apr-2019 12:40:25
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
  double d0;
  int i2;
  static const double b[3] = { 0.29893602129377539, 0.58704307445112125,
    0.11402090425510336 };

  unsigned char u0;
  for (i = 0; i < 164592; i++) {
    b_X[0] = X[i];
    b_X[1] = X[164592 + i];
    b_X[2] = X[329184 + i];
    d0 = 0.0;
    for (i2 = 0; i2 < 3; i2++) {
      d0 += (double)b_X[i2] * b[i2];
    }

    d0 = rt_roundd_snf(d0);
    if (d0 < 256.0) {
      u0 = (unsigned char)d0;
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
