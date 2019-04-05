/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * std.c
 *
 * Code generation for function 'std'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "extract_notes.h"
#include "std.h"
#include "eml_error.h"
#include "extract_notes_data.h"
#include "libmwimfilter.h"
#include "libmwippfilter.h"

/* Variable Definitions */
static emlrtRSInfo t_emlrtRSI = { 12, "std",
  "/Applications/MATLAB_R2015a.app/toolbox/eml/lib/matlab/datafun/std.m" };

/* Function Definitions */
real_T b_std(const emlrtStack *sp, const real_T varargin_1[216])
{
  int32_T ix;
  real_T xbar;
  int32_T k;
  real_T r;
  real_T x;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  ix = 0;
  xbar = varargin_1[0];
  for (k = 0; k < 215; k++) {
    ix++;
    xbar += varargin_1[ix];
  }

  xbar /= 216.0;
  ix = 0;
  r = varargin_1[0] - xbar;
  x = r * r;
  for (k = 0; k < 215; k++) {
    ix++;
    r = varargin_1[ix] - xbar;
    x += r * r;
  }

  x /= 215.0;
  st.site = &t_emlrtRSI;
  if (x < 0.0) {
    b_st.site = &u_emlrtRSI;
    eml_error(&b_st);
  }

  return muDoubleScalarSqrt(x);
}

real_T c_std(const emlrtStack *sp, const real_T varargin_1[164592])
{
  int32_T ix;
  real_T xbar;
  int32_T k;
  real_T r;
  real_T x;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  ix = 0;
  xbar = varargin_1[0];
  for (k = 0; k < 164591; k++) {
    ix++;
    xbar += varargin_1[ix];
  }

  xbar /= 164592.0;
  ix = 0;
  r = varargin_1[0] - xbar;
  x = r * r;
  for (k = 0; k < 164591; k++) {
    ix++;
    r = varargin_1[ix] - xbar;
    x += r * r;
  }

  x /= 164591.0;
  st.site = &t_emlrtRSI;
  if (x < 0.0) {
    b_st.site = &u_emlrtRSI;
    eml_error(&b_st);
  }

  return muDoubleScalarSqrt(x);
}

real_T d_std(const emlrtStack *sp, const real_T varargin_1[762])
{
  int32_T ix;
  real_T xbar;
  int32_T k;
  real_T r;
  real_T x;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  ix = 0;
  xbar = varargin_1[0];
  for (k = 0; k < 761; k++) {
    ix++;
    xbar += varargin_1[ix];
  }

  xbar /= 762.0;
  ix = 0;
  r = varargin_1[0] - xbar;
  x = r * r;
  for (k = 0; k < 761; k++) {
    ix++;
    r = varargin_1[ix] - xbar;
    x += r * r;
  }

  x /= 761.0;
  st.site = &t_emlrtRSI;
  if (x < 0.0) {
    b_st.site = &u_emlrtRSI;
    eml_error(&b_st);
  }

  return muDoubleScalarSqrt(x);
}

/* End of code generation (std.c) */
