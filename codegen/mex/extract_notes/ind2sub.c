/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * ind2sub.c
 *
 * Code generation for function 'ind2sub'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "extract_notes.h"
#include "ind2sub.h"
#include "extract_notes_emxutil.h"
#include "libmwimfilter.h"
#include "libmwippfilter.h"

/* Variable Definitions */
static emlrtRTEInfo n_emlrtRTEI = { 26, 22, "ind2sub",
  "/Applications/MATLAB_R2015a.app/toolbox/eml/lib/matlab/elmat/ind2sub.m" };

static emlrtRTEInfo o_emlrtRTEI = { 42, 5, "ind2sub",
  "/Applications/MATLAB_R2015a.app/toolbox/eml/lib/matlab/elmat/ind2sub.m" };

static emlrtRTEInfo kb_emlrtRTEI = { 38, 23, "ind2sub",
  "/Applications/MATLAB_R2015a.app/toolbox/eml/lib/matlab/elmat/ind2sub.m" };

static emlrtRSInfo dd_emlrtRSI = { 18, "indexDivide",
  "/Applications/MATLAB_R2015a.app/toolbox/shared/coder/coder/+coder/+internal/indexDivide.m"
};

/* Function Declarations */
static boolean_T allinrange(void);
static int32_T div_s32(const emlrtStack *sp, int32_T numerator, int32_T
  denominator);

/* Function Definitions */
static boolean_T allinrange(void)
{
  return true;
}

static int32_T div_s32(const emlrtStack *sp, int32_T numerator, int32_T
  denominator)
{
  int32_T quotient;
  uint32_T absNumerator;
  uint32_T absDenominator;
  boolean_T quotientNeedsNegation;
  if (denominator == 0) {
    if (numerator >= 0) {
      quotient = MAX_int32_T;
    } else {
      quotient = MIN_int32_T;
    }

    emlrtDivisionByZeroErrorR2012b(NULL, sp);
  } else {
    if (numerator >= 0) {
      absNumerator = (uint32_T)numerator;
    } else {
      absNumerator = (uint32_T)-numerator;
    }

    if (denominator >= 0) {
      absDenominator = (uint32_T)denominator;
    } else {
      absDenominator = (uint32_T)-denominator;
    }

    quotientNeedsNegation = ((numerator < 0) != (denominator < 0));
    absNumerator /= absDenominator;
    if (quotientNeedsNegation) {
      quotient = -(int32_T)absNumerator;
    } else {
      quotient = (int32_T)absNumerator;
    }
  }

  return quotient;
}

void ind2sub_indexClass(const emlrtStack *sp, const emxArray_real_T *ndx,
  emxArray_int32_T *varargout_1, emxArray_int32_T *varargout_2)
{
  int32_T i28;
  int32_T loop_ub;
  emxArray_int32_T *vk;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  i28 = varargout_1->size[0];
  varargout_1->size[0] = ndx->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)varargout_1, i28, (int32_T)sizeof
                    (int32_T), &n_emlrtRTEI);
  loop_ub = ndx->size[0];
  for (i28 = 0; i28 < loop_ub; i28++) {
    varargout_1->data[i28] = (int32_T)ndx->data[i28];
  }

  if (allinrange()) {
  } else {
    emlrtErrorWithMessageIdR2012b(sp, &kb_emlrtRTEI,
      "Coder:MATLAB:ind2sub_IndexOutOfRange", 0);
  }

  i28 = varargout_1->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)varargout_1, i28, (int32_T)sizeof
                    (int32_T), &n_emlrtRTEI);
  loop_ub = varargout_1->size[0];
  for (i28 = 0; i28 < loop_ub; i28++) {
    varargout_1->data[i28]--;
  }

  emxInit_int32_T(sp, &vk, 1, &o_emlrtRTEI, true);
  i28 = vk->size[0];
  vk->size[0] = varargout_1->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)vk, i28, (int32_T)sizeof(int32_T),
                    &n_emlrtRTEI);
  loop_ub = varargout_1->size[0];
  for (i28 = 0; i28 < loop_ub; i28++) {
    st.site = &dd_emlrtRSI;
    vk->data[i28] = div_s32(&st, varargout_1->data[i28], 216);
  }

  i28 = varargout_2->size[0];
  varargout_2->size[0] = vk->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)varargout_2, i28, (int32_T)sizeof
                    (int32_T), &n_emlrtRTEI);
  loop_ub = vk->size[0];
  for (i28 = 0; i28 < loop_ub; i28++) {
    varargout_2->data[i28] = vk->data[i28] + 1;
  }

  i28 = varargout_1->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)varargout_1, i28, (int32_T)sizeof
                    (int32_T), &n_emlrtRTEI);
  loop_ub = varargout_1->size[0];
  for (i28 = 0; i28 < loop_ub; i28++) {
    varargout_1->data[i28] -= vk->data[i28] * 216;
  }

  emxFree_int32_T(&vk);
  i28 = varargout_1->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)varargout_1, i28, (int32_T)sizeof
                    (int32_T), &n_emlrtRTEI);
  loop_ub = varargout_1->size[0];
  for (i28 = 0; i28 < loop_ub; i28++) {
    varargout_1->data[i28]++;
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (ind2sub.c) */
