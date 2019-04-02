/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * detectEdges_removeLines.c
 *
 * Code generation for function 'detectEdges_removeLines'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "extract_notes.h"
#include "detectEdges_removeLines.h"
#include "imfilter.h"
#include "extract_notes_emxutil.h"
#include "atand.h"
#include "rdivide.h"
#include "ind2sub.h"
#include "sqrt.h"
#include "power.h"
#include "libmwimfilter.h"
#include "libmwippfilter.h"

/* Variable Definitions */
static emlrtRSInfo l_emlrtRSI = { 7, "detectEdges_removeLines",
  "/Users/vanessacolihan/Documents/MATLAB/sd/detectEdges_removeLines.m" };

static emlrtRSInfo m_emlrtRSI = { 9, "detectEdges_removeLines",
  "/Users/vanessacolihan/Documents/MATLAB/sd/detectEdges_removeLines.m" };

static emlrtRSInfo n_emlrtRSI = { 16, "detectEdges_removeLines",
  "/Users/vanessacolihan/Documents/MATLAB/sd/detectEdges_removeLines.m" };

static emlrtRSInfo o_emlrtRSI = { 28, "detectEdges_removeLines",
  "/Users/vanessacolihan/Documents/MATLAB/sd/detectEdges_removeLines.m" };

static emlrtRSInfo v_emlrtRSI = { 19, "ind2sub",
  "/Applications/MATLAB_R2015a.app/toolbox/eml/lib/matlab/elmat/ind2sub.m" };

static emlrtRTEInfo emlrtRTEI = { 41, 10, "find",
  "/Applications/MATLAB_R2015a.app/toolbox/eml/lib/matlab/elmat/find.m" };

static emlrtRTEInfo b_emlrtRTEI = { 249, 13, "find",
  "/Applications/MATLAB_R2015a.app/toolbox/eml/lib/matlab/elmat/find.m" };

static emlrtRTEInfo h_emlrtRTEI = { 1, 24, "detectEdges_removeLines",
  "/Users/vanessacolihan/Documents/MATLAB/sd/detectEdges_removeLines.m" };

static emlrtRTEInfo i_emlrtRTEI = { 27, 5, "detectEdges_removeLines",
  "/Users/vanessacolihan/Documents/MATLAB/sd/detectEdges_removeLines.m" };

static emlrtRTEInfo j_emlrtRTEI = { 30, 5, "detectEdges_removeLines",
  "/Users/vanessacolihan/Documents/MATLAB/sd/detectEdges_removeLines.m" };

static emlrtRTEInfo k_emlrtRTEI = { 33, 6, "find",
  "/Applications/MATLAB_R2015a.app/toolbox/eml/lib/matlab/elmat/find.m" };

static emlrtECInfo b_emlrtECI = { 1, 31, 13, "detectEdges_removeLines",
  "/Users/vanessacolihan/Documents/MATLAB/sd/detectEdges_removeLines.m" };

/* Function Definitions */
void detectEdges_removeLines(extract_notesStackData *SD, const emlrtStack *sp,
  const uint8_T im[164592], real_T threshold, emxArray_real_T *edges)
{
  int32_T i10;
  boolean_T x[164592];
  emxArray_int32_T *ii;
  int32_T idx;
  int32_T b_ii;
  boolean_T exitg1;
  boolean_T guard1 = false;
  emxArray_real_T *edge_inds;
  emxArray_real_T *y_inds;
  emxArray_int32_T *varargout_4;
  emxArray_real_T *x_inds;
  emxArray_real_T *edge_orient;
  emxArray_real_T *grad_mag;
  int32_T x_inds_idx_0;
  int32_T y_inds_idx_0;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);

  /* im = rgb2gray(im); */
  /*  compute gradients */
  for (i10 = 0; i10 < 164592; i10++) {
    SD->u2.f4.im[i10] = im[i10];
  }

  st.site = &l_emlrtRSI;
  imfilter(SD, SD->u2.f4.im, SD->u2.f4.Gx);
  for (i10 = 0; i10 < 164592; i10++) {
    SD->u2.f4.im[i10] = im[i10];
  }

  st.site = &m_emlrtRSI;
  b_imfilter(SD, SD->u2.f4.im, SD->u2.f4.Gy);

  /*      im_less_lines = im; */
  /*      im_less_lines(abs(Gx)>50) = 255; */
  /*      im = im_less_lines; */
  /*  compute gradient magnitude */
  power(SD->u2.f4.Gx, SD->u2.f4.grad_mag);
  power(SD->u2.f4.Gy, SD->u2.f4.im);
  for (i10 = 0; i10 < 164592; i10++) {
    SD->u2.f4.grad_mag[i10] += SD->u2.f4.im[i10];
  }

  st.site = &n_emlrtRSI;
  b_sqrt(&st, SD->u2.f4.grad_mag);

  /*  compute gradient orientation */
  /*  set default threshold (optional) */
  /*  find edge points */
  for (i10 = 0; i10 < 164592; i10++) {
    x[i10] = (SD->u2.f4.grad_mag[i10] >= threshold);
  }

  emxInit_int32_T(sp, &ii, 1, &k_emlrtRTEI, true);
  idx = 0;
  i10 = ii->size[0];
  ii->size[0] = 164592;
  emxEnsureCapacity(sp, (emxArray__common *)ii, i10, (int32_T)sizeof(int32_T),
                    &emlrtRTEI);
  b_ii = 1;
  exitg1 = false;
  while ((!exitg1) && (b_ii < 164593)) {
    guard1 = false;
    if (x[b_ii - 1]) {
      idx++;
      ii->data[idx - 1] = b_ii;
      if (idx >= 164592) {
        exitg1 = true;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }

    if (guard1) {
      b_ii++;
    }
  }

  b_emxInit_real_T(sp, &edge_inds, 1, &i_emlrtRTEI, true);
  i10 = ii->size[0];
  if (1 > idx) {
    ii->size[0] = 0;
  } else {
    ii->size[0] = idx;
  }

  emxEnsureCapacity(sp, (emxArray__common *)ii, i10, (int32_T)sizeof(int32_T),
                    &b_emlrtRTEI);
  i10 = edge_inds->size[0];
  edge_inds->size[0] = ii->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)edge_inds, i10, (int32_T)sizeof
                    (real_T), &h_emlrtRTEI);
  b_ii = ii->size[0];
  for (i10 = 0; i10 < b_ii; i10++) {
    edge_inds->data[i10] = ii->data[i10];
  }

  b_emxInit_real_T(sp, &y_inds, 1, &h_emlrtRTEI, true);
  emxInit_int32_T(sp, &varargout_4, 1, &h_emlrtRTEI, true);
  st.site = &o_emlrtRSI;
  b_st.site = &v_emlrtRSI;
  ind2sub_indexClass(&b_st, edge_inds, ii, varargout_4);
  i10 = y_inds->size[0];
  y_inds->size[0] = ii->size[0];
  emxEnsureCapacity(&st, (emxArray__common *)y_inds, i10, (int32_T)sizeof(real_T),
                    &h_emlrtRTEI);
  b_ii = ii->size[0];
  for (i10 = 0; i10 < b_ii; i10++) {
    y_inds->data[i10] = ii->data[i10];
  }

  emxFree_int32_T(&ii);
  b_emxInit_real_T(&st, &x_inds, 1, &h_emlrtRTEI, true);
  i10 = x_inds->size[0];
  x_inds->size[0] = varargout_4->size[0];
  emxEnsureCapacity(&st, (emxArray__common *)x_inds, i10, (int32_T)sizeof(real_T),
                    &h_emlrtRTEI);
  b_ii = varargout_4->size[0];
  for (i10 = 0; i10 < b_ii; i10++) {
    x_inds->data[i10] = varargout_4->data[i10];
  }

  emxFree_int32_T(&varargout_4);
  b_emxInit_real_T(&st, &edge_orient, 1, &j_emlrtRTEI, true);
  rdivide(SD->u2.f4.Gy, SD->u2.f4.Gx, SD->u2.f4.im);
  atand(SD->u2.f4.im);
  i10 = edge_orient->size[0];
  edge_orient->size[0] = edge_inds->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)edge_orient, i10, (int32_T)sizeof
                    (real_T), &h_emlrtRTEI);
  b_ii = edge_inds->size[0];
  for (i10 = 0; i10 < b_ii; i10++) {
    edge_orient->data[i10] = SD->u2.f4.im[(int32_T)edge_inds->data[i10] - 1];
  }

  b_emxInit_real_T(sp, &grad_mag, 1, &h_emlrtRTEI, true);
  x_inds_idx_0 = x_inds->size[0];
  y_inds_idx_0 = y_inds->size[0];
  if (x_inds_idx_0 != y_inds_idx_0) {
    emlrtDimSizeEqCheckR2012b(x_inds_idx_0, y_inds_idx_0, &b_emlrtECI, sp);
  }

  x_inds_idx_0 = x_inds->size[0];
  b_ii = edge_inds->size[0];
  if (x_inds_idx_0 != b_ii) {
    emlrtDimSizeEqCheckR2012b(x_inds_idx_0, b_ii, &b_emlrtECI, sp);
  }

  x_inds_idx_0 = x_inds->size[0];
  idx = edge_orient->size[0];
  if (x_inds_idx_0 != idx) {
    emlrtDimSizeEqCheckR2012b(x_inds_idx_0, idx, &b_emlrtECI, sp);
  }

  x_inds_idx_0 = x_inds->size[0];
  y_inds_idx_0 = y_inds->size[0];
  i10 = grad_mag->size[0];
  grad_mag->size[0] = edge_inds->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)grad_mag, i10, (int32_T)sizeof
                    (real_T), &h_emlrtRTEI);
  b_ii = edge_inds->size[0];
  for (i10 = 0; i10 < b_ii; i10++) {
    grad_mag->data[i10] = SD->u2.f4.grad_mag[(int32_T)edge_inds->data[i10] - 1];
  }

  b_ii = edge_inds->size[0];
  idx = edge_orient->size[0];
  i10 = edges->size[0] * edges->size[1];
  edges->size[0] = x_inds_idx_0;
  edges->size[1] = 4;
  emxEnsureCapacity(sp, (emxArray__common *)edges, i10, (int32_T)sizeof(real_T),
                    &h_emlrtRTEI);
  emxFree_real_T(&edge_inds);
  for (i10 = 0; i10 < x_inds_idx_0; i10++) {
    edges->data[i10] = x_inds->data[i10];
  }

  emxFree_real_T(&x_inds);
  for (i10 = 0; i10 < y_inds_idx_0; i10++) {
    edges->data[i10 + edges->size[0]] = y_inds->data[i10];
  }

  emxFree_real_T(&y_inds);
  for (i10 = 0; i10 < b_ii; i10++) {
    edges->data[i10 + (edges->size[0] << 1)] = grad_mag->data[i10];
  }

  emxFree_real_T(&grad_mag);
  for (i10 = 0; i10 < idx; i10++) {
    edges->data[i10 + edges->size[0] * 3] = edge_orient->data[i10];
  }

  emxFree_real_T(&edge_orient);

  /*  display edges */
  /*      not_edge_inds = find(grad_mag(:) < threshold); */
  /*      im(not_edge_inds) = 0; */
  /*      im(edge_inds) = edge_mag; */
  /*      if (show == 1) */
  /*          figure; imshow(im); title('edge detection');  */
  /*      end; */
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (detectEdges_removeLines.c) */
