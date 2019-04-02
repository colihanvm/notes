/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_extract_notes_api.c
 *
 * Code generation for function '_coder_extract_notes_api'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "extract_notes.h"
#include "_coder_extract_notes_api.h"
#include "extract_notes_emxutil.h"
#include "extract_notes_data.h"
#include "libmwimfilter.h"
#include "libmwippfilter.h"

/* Variable Definitions */
static emlrtRTEInfo u_emlrtRTEI = { 1, 1, "_coder_extract_notes_api", "" };

/* Function Declarations */
static uint8_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *im,
  const char_T *identifier))[493776];
static uint8_T (*d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId))[493776];
static real_T e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *threshold,
  const char_T *identifier);
static const mxArray *emlrt_marshallOut(const emlrtStack *sp, const
  emxArray_char_T *u);
static real_T f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static uint8_T (*h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[493776];
static real_T i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId);

/* Function Definitions */
static uint8_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *im,
  const char_T *identifier))[493776]
{
  uint8_T (*y)[493776];
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  y = d_emlrt_marshallIn(sp, emlrtAlias(im), &thisId);
  emlrtDestroyArray(&im);
  return y;
}
  static uint8_T (*d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId))[493776]
{
  uint8_T (*y)[493776];
  y = h_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static real_T e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *threshold,
  const char_T *identifier)
{
  real_T y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  y = f_emlrt_marshallIn(sp, emlrtAlias(threshold), &thisId);
  emlrtDestroyArray(&threshold);
  return y;
}

static const mxArray *emlrt_marshallOut(const emlrtStack *sp, const
  emxArray_char_T *u)
{
  const mxArray *y;
  const mxArray *m3;
  y = NULL;
  m3 = emlrtCreateCharArray(2, *(int32_T (*)[2])u->size);
  emlrtInitCharArrayR2013a(sp, u->size[0] << 1, m3, &u->data[0]);
  emlrtAssign(&y, m3);
  return y;
}

static real_T f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = i_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static uint8_T (*h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[493776]
{
  uint8_T (*ret)[493776];
  int32_T iv5[3];
  int32_T i;
  static const int16_T iv6[3] = { 216, 762, 3 };

  for (i = 0; i < 3; i++) {
    iv5[i] = iv6[i];
  }

  emlrtCheckBuiltInR2012b(sp, msgId, src, "uint8", false, 3U, iv5);
  ret = (uint8_T (*)[493776])mxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}
  static real_T i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId)
{
  real_T ret;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 0U, 0);
  ret = *(real_T *)mxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

void extract_notes_api(extract_notesStackData *SD, const mxArray * const prhs[4],
  const mxArray *plhs[1])
{
  emxArray_char_T *notes;
  uint8_T (*im)[493776];
  real_T threshold;
  real_T num_find;
  real_T radius;
  emlrtStack st = { NULL, NULL, NULL };

  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  emxInit_char_T(&st, &notes, 2, &u_emlrtRTEI, true);

  /* Marshall function inputs */
  im = c_emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "im");
  threshold = e_emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "threshold");
  num_find = e_emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "num_find");
  radius = e_emlrt_marshallIn(&st, emlrtAliasP(prhs[3]), "radius");

  /* Invoke the target function */
  extract_notes(SD, &st, *im, threshold, num_find, radius, notes);

  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(&st, notes);
  emxFree_char_T(&notes);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

/* End of code generation (_coder_extract_notes_api.c) */
