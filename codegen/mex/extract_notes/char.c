/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * char.c
 *
 * Code generation for function 'char'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "extract_notes.h"
#include "char.h"
#include "extract_notes_emxutil.h"
#include "libmwimfilter.h"
#include "libmwippfilter.h"

/* Variable Definitions */
static emlrtRTEInfo w_emlrtRTEI = { 1, 14, "char",
  "/Applications/MATLAB_R2015a.app/toolbox/eml/lib/matlab/strfun/char.m" };

static emlrtBCInfo rd_emlrtBCI = { 0, 255, 17, 9, "char", "char",
  "/Applications/MATLAB_R2015a.app/toolbox/eml/lib/matlab/strfun/char.m", 2 };

/* Function Definitions */
void b_char(const emlrtStack *sp, const emxArray_real_T *varargin_1,
            emxArray_char_T *y)
{
  uint32_T uv0[2];
  int32_T i31;
  int32_T loop_ub;
  int32_T i32;
  real_T d4;
  for (i31 = 0; i31 < 2; i31++) {
    uv0[i31] = (uint32_T)varargin_1->size[i31];
  }

  loop_ub = varargin_1->size[0] << 1;
  for (i31 = 0; i31 < loop_ub; i31++) {
    i32 = (int32_T)varargin_1->data[i31];
    emlrtDynamicBoundsCheckR2012b(i32, 0, 255, &rd_emlrtBCI, sp);
  }

  i31 = y->size[0] * y->size[1];
  y->size[0] = (int32_T)uv0[0];
  y->size[1] = 2;
  emxEnsureCapacity(sp, (emxArray__common *)y, i31, (int32_T)sizeof(char_T),
                    &w_emlrtRTEI);
  loop_ub = (int32_T)uv0[0] << 1;
  for (i31 = 0; i31 < loop_ub; i31++) {
    d4 = muDoubleScalarFloor(varargin_1->data[i31]);
    if (muDoubleScalarIsNaN(d4) || muDoubleScalarIsInf(d4)) {
      d4 = 0.0;
    } else {
      d4 = muDoubleScalarRem(d4, 256.0);
    }

    if (d4 < 0.0) {
      y->data[i31] = (int8_T)-(int8_T)(uint8_T)-d4;
    } else {
      y->data[i31] = (int8_T)(uint8_T)d4;
    }
  }
}

/* End of code generation (char.c) */
