/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * imfilter.c
 *
 * Code generation for function 'imfilter'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "extract_notes.h"
#include "imfilter.h"
#include "padarray.h"
#include "libmwimfilter.h"
#include "libmwippfilter.h"

/* Function Definitions */
void b_imfilter(extract_notesStackData *SD, const real_T varargin_1[164592],
                real_T b[164592])
{
  boolean_T tooBig;
  int32_T i;
  real_T outSize[2];
  real_T padSize[2];
  real_T kernel[3];
  real_T connDims[2];
  real_T nonZeroKernel[2];
  real_T start[2];
  static const boolean_T conn[3] = { true, false, true };

  b_padarray(varargin_1, SD->u1.f1.a);
  tooBig = true;
  for (i = 0; i < 2; i++) {
    tooBig = false;
  }

  if (!tooBig) {
    for (i = 0; i < 2; i++) {
      outSize[i] = 216.0 + 546.0 * (real_T)i;
      padSize[i] = 218.0 + 544.0 * (real_T)i;
    }

    for (i = 0; i < 3; i++) {
      kernel[i] = 1.0 - (real_T)i;
    }

    for (i = 0; i < 2; i++) {
      connDims[i] = 3.0 + -2.0 * (real_T)i;
    }

    ippfilter_real64(SD->u1.f1.a, b, outSize, 2.0, padSize, kernel, connDims,
                     false);
  } else {
    for (i = 0; i < 2; i++) {
      outSize[i] = 216.0 + 546.0 * (real_T)i;
      padSize[i] = 218.0 + 544.0 * (real_T)i;
      nonZeroKernel[i] = 1.0 + -2.0 * (real_T)i;
      connDims[i] = 3.0 + -2.0 * (real_T)i;
      start[i] = 1.0 - (real_T)i;
    }

    imfilter_real64(SD->u1.f1.a, b, 2.0, outSize, 2.0, padSize, nonZeroKernel,
                    2.0, conn, 2.0, connDims, start, 2.0, true, false);
  }
}

void imfilter(extract_notesStackData *SD, const real_T varargin_1[164592],
              real_T b[164592])
{
  boolean_T tooBig;
  int32_T i;
  real_T outSize[2];
  real_T padSize[2];
  real_T kernel[3];
  real_T connDims[2];
  real_T nonZeroKernel[2];
  real_T start[2];
  static const boolean_T conn[3] = { true, false, true };

  padarray(varargin_1, SD->u1.f2.a);
  tooBig = true;
  for (i = 0; i < 2; i++) {
    tooBig = false;
  }

  if (!tooBig) {
    for (i = 0; i < 2; i++) {
      outSize[i] = 216.0 + 546.0 * (real_T)i;
      padSize[i] = 216.0 + 548.0 * (real_T)i;
    }

    for (i = 0; i < 3; i++) {
      kernel[i] = 1.0 - (real_T)i;
    }

    for (i = 0; i < 2; i++) {
      connDims[i] = 1.0 + 2.0 * (real_T)i;
    }

    ippfilter_real64(SD->u1.f2.a, b, outSize, 2.0, padSize, kernel, connDims,
                     false);
  } else {
    for (i = 0; i < 2; i++) {
      outSize[i] = 216.0 + 546.0 * (real_T)i;
      padSize[i] = 216.0 + 548.0 * (real_T)i;
      nonZeroKernel[i] = 1.0 + -2.0 * (real_T)i;
      connDims[i] = 1.0 + 2.0 * (real_T)i;
      start[i] = i;
    }

    imfilter_real64(SD->u1.f2.a, b, 2.0, outSize, 2.0, padSize, nonZeroKernel,
                    2.0, conn, 2.0, connDims, start, 2.0, true, false);
  }
}

/* End of code generation (imfilter.c) */
