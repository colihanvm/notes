/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * sum.c
 *
 * Code generation for function 'sum'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "extract_notes.h"
#include "sum.h"
#include "eml_int_forloop_overflow_check.h"
#include "extract_notes_data.h"
#include "libmwimfilter.h"
#include "libmwippfilter.h"

/* Variable Definitions */
static emlrtRSInfo x_emlrtRSI = { 13, "sum",
  "/Applications/MATLAB_R2015a.app/toolbox/eml/lib/matlab/datafun/sum.m" };

static emlrtRSInfo y_emlrtRSI = { 46, "sumprod",
  "/Applications/MATLAB_R2015a.app/toolbox/eml/lib/matlab/datafun/private/sumprod.m"
};

static emlrtRSInfo cd_emlrtRSI = { 36, "combine_vector_elements",
  "/Applications/MATLAB_R2015a.app/toolbox/eml/lib/matlab/datafun/private/combine_vector_elements.m"
};

static emlrtRTEInfo mb_emlrtRTEI = { 19, 23, "sumprod",
  "/Applications/MATLAB_R2015a.app/toolbox/eml/lib/matlab/datafun/private/sumprod.m"
};

static emlrtRTEInfo nb_emlrtRTEI = { 39, 9, "sumprod",
  "/Applications/MATLAB_R2015a.app/toolbox/eml/lib/matlab/datafun/private/sumprod.m"
};

/* Function Definitions */
real_T b_sum(const real_T x[216])
{
  real_T y;
  int32_T k;
  y = x[0];
  for (k = 0; k < 215; k++) {
    y += x[k + 1];
  }

  return y;
}

real_T c_sum(const uint8_T x[164592])
{
  real_T y;
  int32_T k;
  y = x[0];
  for (k = 0; k < 164591; k++) {
    y += (real_T)x[k + 1];
  }

  return y;
}

real_T d_sum(const real_T x[8])
{
  real_T y;
  int32_T k;
  y = x[0];
  for (k = 0; k < 7; k++) {
    y += x[k + 1];
  }

  return y;
}

void e_sum(const emxArray_real_T *x, real_T y[762])
{
  int32_T vlen;
  int32_T ix;
  int32_T iy;
  int32_T i;
  int32_T ixstart;
  real_T s;
  if (x->size[0] == 0) {
    memset(&y[0], 0, 762U * sizeof(real_T));
  } else {
    vlen = x->size[0];
    ix = -1;
    iy = -1;
    for (i = 0; i < 762; i++) {
      ixstart = ix + 1;
      ix++;
      s = x->data[ixstart];
      for (ixstart = 2; ixstart <= vlen; ixstart++) {
        ix++;
        s += x->data[ix];
      }

      iy++;
      y[iy] = s;
    }
  }
}

real_T f_sum(const real_T x[762])
{
  real_T y;
  int32_T k;
  y = x[0];
  for (k = 0; k < 761; k++) {
    y += x[k + 1];
  }

  return y;
}

real_T g_sum(const emlrtStack *sp, const emxArray_uint8_T *x)
{
  real_T y;
  boolean_T overflow;
  boolean_T p;
  int32_T k;
  int32_T exitg1;
  int32_T i30;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &x_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  if ((x->size[0] == 1) || (x->size[0] != 1)) {
    overflow = true;
  } else {
    overflow = false;
  }

  if (overflow) {
  } else {
    emlrtErrorWithMessageIdR2012b(&st, &mb_emlrtRTEI,
      "Coder:toolbox:autoDimIncompatibility", 0);
  }

  overflow = false;
  p = false;
  k = 0;
  do {
    exitg1 = 0;
    if (k < 2) {
      if (k + 1 <= 1) {
        i30 = x->size[0];
      } else {
        i30 = 1;
      }

      if (i30 != 0) {
        exitg1 = 1;
      } else {
        k++;
      }
    } else {
      p = true;
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  if (!p) {
  } else {
    overflow = true;
  }

  if (!overflow) {
  } else {
    emlrtErrorWithMessageIdR2012b(&st, &nb_emlrtRTEI,
      "Coder:toolbox:UnsupportedSpecialEmpty", 0);
  }

  b_st.site = &y_emlrtRSI;
  if (x->size[0] == 0) {
    y = 0.0;
  } else {
    y = x->data[0];
    c_st.site = &cd_emlrtRSI;
    if (2 > x->size[0]) {
      overflow = false;
    } else {
      overflow = (x->size[0] > 2147483646);
    }

    if (overflow) {
      d_st.site = &bb_emlrtRSI;
      check_forloop_overflow_error(&d_st);
    }

    for (k = 2; k <= x->size[0]; k++) {
      y += (real_T)x->data[k - 1];
    }
  }

  return y;
}

void sum(const real_T x[164592], real_T y[216])
{
  int32_T iy;
  int32_T ixstart;
  int32_T j;
  int32_T ix;
  real_T s;
  int32_T k;
  iy = -1;
  ixstart = -1;
  for (j = 0; j < 216; j++) {
    ixstart++;
    ix = ixstart;
    s = x[ixstart];
    for (k = 0; k < 761; k++) {
      ix += 216;
      s += x[ix];
    }

    iy++;
    y[iy] = s;
  }
}

/* End of code generation (sum.c) */
