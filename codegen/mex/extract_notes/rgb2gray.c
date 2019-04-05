/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * rgb2gray.c
 *
 * Code generation for function 'rgb2gray'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "extract_notes.h"
#include "rgb2gray.h"
#include "eml_warning.h"
#include "norm.h"
#include "libmwimfilter.h"
#include "libmwippfilter.h"

/* Variable Definitions */
static emlrtRSInfo p_emlrtRSI = { 25, "rgb2gray",
  "/Applications/MATLAB_R2015a.app/toolbox/eml/lib/matlab/specfun/rgb2gray.m" };

static emlrtRSInfo q_emlrtRSI = { 27, "inv",
  "/Applications/MATLAB_R2015a.app/toolbox/eml/lib/matlab/matfun/inv.m" };

static emlrtRSInfo r_emlrtRSI = { 40, "inv",
  "/Applications/MATLAB_R2015a.app/toolbox/eml/lib/matlab/matfun/inv.m" };

static emlrtRSInfo s_emlrtRSI = { 44, "inv",
  "/Applications/MATLAB_R2015a.app/toolbox/eml/lib/matlab/matfun/inv.m" };

static emlrtMCInfo c_emlrtMCI = { 29, 23, "eml_flt2str",
  "/Applications/MATLAB_R2015a.app/toolbox/eml/lib/matlab/eml/eml_flt2str.m" };

static emlrtMCInfo d_emlrtMCI = { 29, 15, "eml_flt2str",
  "/Applications/MATLAB_R2015a.app/toolbox/eml/lib/matlab/eml/eml_flt2str.m" };

static emlrtRSInfo fd_emlrtRSI = { 29, "eml_flt2str",
  "/Applications/MATLAB_R2015a.app/toolbox/eml/lib/matlab/eml/eml_flt2str.m" };

/* Function Declarations */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, char_T y[14]);
static const mxArray *b_sprintf(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, const mxArray *d, emlrtMCInfo *location);
static const mxArray *c_sprintf(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, emlrtMCInfo *location);
static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *d_sprintf,
  const char_T *identifier, char_T y[14]);
static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, char_T ret[14]);

/* Function Definitions */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, char_T y[14])
{
  g_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static const mxArray *b_sprintf(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, const mxArray *d, emlrtMCInfo *location)
{
  const mxArray *pArrays[3];
  const mxArray *m5;
  pArrays[0] = b;
  pArrays[1] = c;
  pArrays[2] = d;
  return emlrtCallMATLABR2012b(sp, 1, &m5, 3, pArrays, "sprintf", true, location);
}

static const mxArray *c_sprintf(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, emlrtMCInfo *location)
{
  const mxArray *pArrays[2];
  const mxArray *m6;
  pArrays[0] = b;
  pArrays[1] = c;
  return emlrtCallMATLABR2012b(sp, 1, &m6, 2, pArrays, "sprintf", true, location);
}

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *d_sprintf,
  const char_T *identifier, char_T y[14])
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  b_emlrt_marshallIn(sp, emlrtAlias(d_sprintf), &thisId, y);
  emlrtDestroyArray(&d_sprintf);
}

static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, char_T ret[14])
{
  int32_T iv4[2];
  int32_T i33;
  for (i33 = 0; i33 < 2; i33++) {
    iv4[i33] = 1 + 13 * i33;
  }

  emlrtCheckBuiltInR2012b(sp, msgId, src, "char", false, 2U, iv4);
  emlrtImportCharArrayR2014b(sp, src, ret, 14);
  emlrtDestroyArray(&src);
}

void rgb2gray(const emlrtStack *sp, const uint8_T X[493776], uint8_T I[164592])
{
  real_T T[9];
  static const real_T x[9] = { 1.0, 1.0, 1.0, 0.956, -0.272, -1.106, 0.621,
    -0.647, 1.703 };

  real_T n1x;
  real_T n1xinv;
  real_T rc;
  int32_T i;
  static const char_T cv0[8] = { '%', '%', '%', 'd', '.', '%', 'd', 'e' };

  char_T u[8];
  const mxArray *y;
  static const int32_T iv0[2] = { 1, 8 };

  const mxArray *m0;
  const mxArray *b_y;
  const mxArray *c_y;
  const mxArray *d_y;
  char_T cv1[14];
  uint8_T a[3];
  int32_T k;
  uint8_T u0;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &p_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  T[0] = 0.29893602129377539;
  T[1] = 0.59594574307079939;
  T[2] = 0.21149734030682846;
  T[6] = 0.11402090425510336;
  T[7] = -0.32155710732501;
  T[8] = 0.31141334999614528;
  T[3] = 0.58704307445112125;
  T[4] = -0.27438863574578931;
  T[5] = -0.52291069030297377;
  b_st.site = &q_emlrtRSI;
  n1x = norm(x);
  n1xinv = norm(T);
  rc = 1.0 / (n1x * n1xinv);
  if ((n1x == 0.0) || (n1xinv == 0.0) || (rc == 0.0)) {
    c_st.site = &r_emlrtRSI;
    eml_warning(&c_st);
  } else {
    if (muDoubleScalarIsNaN(rc) || (rc < 2.2204460492503131E-16)) {
      c_st.site = &s_emlrtRSI;
      for (i = 0; i < 8; i++) {
        u[i] = cv0[i];
      }

      y = NULL;
      m0 = emlrtCreateCharArray(2, iv0);
      emlrtInitCharArrayR2013a(&c_st, 8, m0, &u[0]);
      emlrtAssign(&y, m0);
      b_y = NULL;
      m0 = emlrtCreateDoubleScalar(14.0);
      emlrtAssign(&b_y, m0);
      c_y = NULL;
      m0 = emlrtCreateDoubleScalar(6.0);
      emlrtAssign(&c_y, m0);
      d_y = NULL;
      m0 = emlrtCreateDoubleScalar(rc);
      emlrtAssign(&d_y, m0);
      d_st.site = &fd_emlrtRSI;
      emlrt_marshallIn(&d_st, c_sprintf(&d_st, b_sprintf(&d_st, y, b_y, c_y,
        &c_emlrtMCI), d_y, &d_emlrtMCI), "sprintf", cv1);
      c_st.site = &s_emlrtRSI;
      b_eml_warning(&c_st, cv1);
    }
  }

  for (i = 0; i < 164592; i++) {
    a[0] = X[i];
    a[1] = X[164592 + i];
    a[2] = X[329184 + i];
    n1x = 0.0;
    for (k = 0; k < 3; k++) {
      n1x += (real_T)a[k] * T[3 * k];
    }

    n1x = muDoubleScalarRound(n1x);
    if (n1x < 256.0) {
      if (n1x >= 0.0) {
        u0 = (uint8_T)n1x;
      } else {
        u0 = 0;
      }
    } else {
      u0 = MAX_uint8_T;
    }

    I[i] = u0;
  }
}

/* End of code generation (rgb2gray.c) */
