/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: imfilter.c
 *
 * MATLAB Coder version            : 2.8
 * C/C++ source code generated on  : 05-Apr-2019 17:03:45
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "extract_notes.h"
#include "imfilter.h"
#include "convn.h"
#include "padarray.h"

/* Function Definitions */

/*
 * Arguments    : const double varargin_1[164592]
 *                double b[164592]
 * Return Type  : void
 */
void b_imfilter(const double varargin_1[164592], double b[164592])
{
  double dv2[3];
  int i7;
  static double dv3[166116];
  static double result[166116];
  for (i7 = 0; i7 < 3; i7++) {
    dv2[i7] = -1.0 + (double)i7;
  }

  b_padarray(varargin_1, dv3);
  b_convn(dv3, dv2, result);
  for (i7 = 0; i7 < 762; i7++) {
    memcpy(&b[216 * i7], &result[1 + 218 * i7], 216U * sizeof(double));
  }
}

/*
 * Arguments    : const double varargin_1[164592]
 *                double b[164592]
 * Return Type  : void
 */
void imfilter(const double varargin_1[164592], double b[164592])
{
  double dv0[3];
  int i6;
  static double dv1[165024];
  static double result[165024];
  for (i6 = 0; i6 < 3; i6++) {
    dv0[i6] = -1.0 + (double)i6;
  }

  padarray(varargin_1, dv1);
  convn(dv1, dv0, result);
  for (i6 = 0; i6 < 762; i6++) {
    memcpy(&b[216 * i6], &result[216 * (1 + i6)], 216U * sizeof(double));
  }
}

/*
 * File trailer for imfilter.c
 *
 * [EOF]
 */
