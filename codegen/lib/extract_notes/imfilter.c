/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: imfilter.c
 *
 * MATLAB Coder version            : 2.8
 * C/C++ source code generated on  : 05-Apr-2019 15:22:58
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "extract_notes.h"
#include "imfilter.h"
#include "padarray.h"
#include "libmwimfilter.h"
#include "libmwippfilter.h"

/* Function Definitions */

/*
 * Arguments    : const double varargin_1[164592]
 *                double b[164592]
 * Return Type  : void
 */
void b_imfilter(const double varargin_1[164592], double b[164592])
{
  static double a[166116];
  boolean_T tooBig;
  int i;
  double outSize[2];
  double padSize[2];
  double kernel[3];
  double connDims[2];
  double nonZeroKernel[2];
  double start[2];
  static const boolean_T conn[3] = { true, false, true };

  b_padarray(varargin_1, a);
  tooBig = true;
  for (i = 0; i < 2; i++) {
    tooBig = false;
  }

  if (!tooBig) {
    for (i = 0; i < 2; i++) {
      outSize[i] = 216.0 + 546.0 * (double)i;
      padSize[i] = 218.0 + 544.0 * (double)i;
    }

    for (i = 0; i < 3; i++) {
      kernel[i] = 1.0 - (double)i;
    }

    for (i = 0; i < 2; i++) {
      connDims[i] = 3.0 + -2.0 * (double)i;
    }

    ippfilter_real64(a, b, outSize, 2.0, padSize, kernel, connDims, false);
  } else {
    for (i = 0; i < 2; i++) {
      outSize[i] = 216.0 + 546.0 * (double)i;
      padSize[i] = 218.0 + 544.0 * (double)i;
      nonZeroKernel[i] = 1.0 + -2.0 * (double)i;
      connDims[i] = 3.0 + -2.0 * (double)i;
      start[i] = 1.0 - (double)i;
    }

    imfilter_real64(a, b, 2.0, outSize, 2.0, padSize, nonZeroKernel, 2.0, conn,
                    2.0, connDims, start, 2.0, true, false);
  }
}

/*
 * Arguments    : const double varargin_1[164592]
 *                double b[164592]
 * Return Type  : void
 */
void imfilter(const double varargin_1[164592], double b[164592])
{
  static double a[165024];
  boolean_T tooBig;
  int i;
  double outSize[2];
  double padSize[2];
  double kernel[3];
  double connDims[2];
  double nonZeroKernel[2];
  double start[2];
  static const boolean_T conn[3] = { true, false, true };

  padarray(varargin_1, a);
  tooBig = true;
  for (i = 0; i < 2; i++) {
    tooBig = false;
  }

  if (!tooBig) {
    for (i = 0; i < 2; i++) {
      outSize[i] = 216.0 + 546.0 * (double)i;
      padSize[i] = 216.0 + 548.0 * (double)i;
    }

    for (i = 0; i < 3; i++) {
      kernel[i] = 1.0 - (double)i;
    }

    for (i = 0; i < 2; i++) {
      connDims[i] = 1.0 + 2.0 * (double)i;
    }

    ippfilter_real64(a, b, outSize, 2.0, padSize, kernel, connDims, false);
  } else {
    for (i = 0; i < 2; i++) {
      outSize[i] = 216.0 + 546.0 * (double)i;
      padSize[i] = 216.0 + 548.0 * (double)i;
      nonZeroKernel[i] = 1.0 + -2.0 * (double)i;
      connDims[i] = 1.0 + 2.0 * (double)i;
      start[i] = i;
    }

    imfilter_real64(a, b, 2.0, outSize, 2.0, padSize, nonZeroKernel, 2.0, conn,
                    2.0, connDims, start, 2.0, true, false);
  }
}

/*
 * File trailer for imfilter.c
 *
 * [EOF]
 */
