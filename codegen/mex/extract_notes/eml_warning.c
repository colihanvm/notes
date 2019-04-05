/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * eml_warning.c
 *
 * Code generation for function 'eml_warning'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "extract_notes.h"
#include "eml_warning.h"
#include "libmwimfilter.h"
#include "libmwippfilter.h"

/* Variable Definitions */
static emlrtMCInfo emlrtMCI = { 16, 13, "eml_warning",
  "/Applications/MATLAB_R2015a.app/toolbox/eml/lib/matlab/eml/eml_warning.m" };

static emlrtMCInfo b_emlrtMCI = { 16, 5, "eml_warning",
  "/Applications/MATLAB_R2015a.app/toolbox/eml/lib/matlab/eml/eml_warning.m" };

static emlrtRSInfo ed_emlrtRSI = { 16, "eml_warning",
  "/Applications/MATLAB_R2015a.app/toolbox/eml/lib/matlab/eml/eml_warning.m" };

/* Function Declarations */
static const mxArray *b_message(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, emlrtMCInfo *location);
static const mxArray *message(const emlrtStack *sp, const mxArray *b,
  emlrtMCInfo *location);
static void warning(const emlrtStack *sp, const mxArray *b, emlrtMCInfo
                    *location);

/* Function Definitions */
static const mxArray *b_message(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, emlrtMCInfo *location)
{
  const mxArray *pArrays[2];
  const mxArray *m7;
  pArrays[0] = b;
  pArrays[1] = c;
  return emlrtCallMATLABR2012b(sp, 1, &m7, 2, pArrays, "message", true, location);
}

static const mxArray *message(const emlrtStack *sp, const mxArray *b,
  emlrtMCInfo *location)
{
  const mxArray *pArray;
  const mxArray *m4;
  pArray = b;
  return emlrtCallMATLABR2012b(sp, 1, &m4, 1, &pArray, "message", true, location);
}

static void warning(const emlrtStack *sp, const mxArray *b, emlrtMCInfo
                    *location)
{
  const mxArray *pArray;
  pArray = b;
  emlrtCallMATLABR2012b(sp, 0, NULL, 1, &pArray, "warning", true, location);
}

void b_eml_warning(const emlrtStack *sp, const char_T varargin_2[14])
{
  int32_T i25;
  static const char_T varargin_1[33] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 'i', 'l', 'l', 'C', 'o', 'n', 'd', 'i', 't', 'i',
    'o', 'n', 'e', 'd', 'M', 'a', 't', 'r', 'i', 'x' };

  char_T u[33];
  const mxArray *y;
  static const int32_T iv2[2] = { 1, 33 };

  const mxArray *m2;
  char_T b_u[14];
  const mxArray *b_y;
  static const int32_T iv3[2] = { 1, 14 };

  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  for (i25 = 0; i25 < 33; i25++) {
    u[i25] = varargin_1[i25];
  }

  y = NULL;
  m2 = emlrtCreateCharArray(2, iv2);
  emlrtInitCharArrayR2013a(sp, 33, m2, &u[0]);
  emlrtAssign(&y, m2);
  for (i25 = 0; i25 < 14; i25++) {
    b_u[i25] = varargin_2[i25];
  }

  b_y = NULL;
  m2 = emlrtCreateCharArray(2, iv3);
  emlrtInitCharArrayR2013a(sp, 14, m2, &b_u[0]);
  emlrtAssign(&b_y, m2);
  st.site = &ed_emlrtRSI;
  warning(&st, b_message(&st, y, b_y, &emlrtMCI), &b_emlrtMCI);
}

void eml_warning(const emlrtStack *sp)
{
  int32_T i24;
  static const char_T varargin_1[27] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 's', 'i', 'n', 'g', 'u', 'l', 'a', 'r', 'M', 'a',
    't', 'r', 'i', 'x' };

  char_T u[27];
  const mxArray *y;
  static const int32_T iv1[2] = { 1, 27 };

  const mxArray *m1;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  for (i24 = 0; i24 < 27; i24++) {
    u[i24] = varargin_1[i24];
  }

  y = NULL;
  m1 = emlrtCreateCharArray(2, iv1);
  emlrtInitCharArrayR2013a(sp, 27, m1, &u[0]);
  emlrtAssign(&y, m1);
  st.site = &ed_emlrtRSI;
  warning(&st, message(&st, y, &emlrtMCI), &b_emlrtMCI);
}

/* End of code generation (eml_warning.c) */
