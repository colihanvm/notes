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
static emlrtRTEInfo l_emlrtRTEI = { 26, 22, "ind2sub",
  "/Applications/MATLAB_R2015a.app/toolbox/eml/lib/matlab/elmat/ind2sub.m" };

static emlrtRTEInfo m_emlrtRTEI = { 42, 5, "ind2sub",
  "/Applications/MATLAB_R2015a.app/toolbox/eml/lib/matlab/elmat/ind2sub.m" };

static emlrtRTEInfo eb_emlrtRTEI = { 38, 23, "ind2sub",
  "/Applications/MATLAB_R2015a.app/toolbox/eml/lib/matlab/elmat/ind2sub.m" };

static emlrtRSInfo nc_emlrtRSI = { 18, "indexDivide",
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
  int32_T i12;
  int32_T loop_ub;
  emxArray_int32_T *vk;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  i12 = varargout_1->size[0];
  varargout_1->size[0] = ndx->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)varargout_1, i12, (int32_T)sizeof
                    (int32_T), &l_emlrtRTEI);
  loop_ub = ndx->size[0];
  for (i12 = 0; i12 < loop_ub; i12++) {
    varargout_1->data[i12] = (int32_T)ndx->data[i12];
  }

  if (allinrange()) {
  } else {
    emlrtErrorWithMessageIdR2012b(sp, &eb_emlrtRTEI,
      "Coder:MATLAB:ind2sub_IndexOutOfRange", 0);
  }

  i12 = varargout_1->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)varargout_1, i12, (int32_T)sizeof
                    (int32_T), &l_emlrtRTEI);
  loop_ub = varargout_1->size[0];
  for (i12 = 0; i12 < loop_ub; i12++) {
    varargout_1->data[i12]--;
  }

  emxInit_int32_T(sp, &vk, 1, &m_emlrtRTEI, true);
  i12 = vk->size[0];
  vk->size[0] = varargout_1->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)vk, i12, (int32_T)sizeof(int32_T),
                    &l_emlrtRTEI);
  loop_ub = varargout_1->size[0];
  for (i12 = 0; i12 < loop_ub; i12++) {
    st.site = &nc_emlrtRSI;
    vk->data[i12] = div_s32(&st, varargout_1->data[i12], 216);
  }

  i12 = varargout_2->size[0];
  varargout_2->size[0] = vk->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)varargout_2, i12, (int32_T)sizeof
                    (int32_T), &l_emlrtRTEI);
  loop_ub = vk->size[0];
  for (i12 = 0; i12 < loop_ub; i12++) {
    varargout_2->data[i12] = vk->data[i12] + 1;
  }

  i12 = varargout_1->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)varargout_1, i12, (int32_T)sizeof
                    (int32_T), &l_emlrtRTEI);
  loop_ub = varargout_1->size[0];
  for (i12 = 0; i12 < loop_ub; i12++) {
    varargout_1->data[i12] -= vk->data[i12] * 216;
  }

  emxFree_int32_T(&vk);
  i12 = varargout_1->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)varargout_1, i12, (int32_T)sizeof
                    (int32_T), &l_emlrtRTEI);
  loop_ub = varargout_1->size[0];
  for (i12 = 0; i12 < loop_ub; i12++) {
    varargout_1->data[i12]++;
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (ind2sub.c) */
