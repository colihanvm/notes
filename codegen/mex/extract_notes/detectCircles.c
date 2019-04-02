/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * detectCircles.c
 *
 * Code generation for function 'detectCircles'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "extract_notes.h"
#include "detectCircles.h"
#include "extract_notes_emxutil.h"
#include "eml_sort.h"
#include "sind.h"
#include "cosd.h"
#include "extract_notes_data.h"
#include "libmwimfilter.h"
#include "libmwippfilter.h"

/* Variable Definitions */
static emlrtRSInfo w_emlrtRSI = { 22, "detectCircles",
  "/Users/vanessacolihan/Documents/MATLAB/sd/detectCircles.m" };

static emlrtRSInfo x_emlrtRSI = { 25, "sort",
  "/Applications/MATLAB_R2015a.app/toolbox/eml/lib/matlab/datafun/sort.m" };

static emlrtRTEInfo n_emlrtRTEI = { 1, 22, "detectCircles",
  "/Users/vanessacolihan/Documents/MATLAB/sd/detectCircles.m" };

static emlrtRTEInfo o_emlrtRTEI = { 37, 5, "find",
  "/Applications/MATLAB_R2015a.app/toolbox/eml/lib/matlab/elmat/find.m" };

static emlrtRTEInfo p_emlrtRTEI = { 182, 13, "find",
  "/Applications/MATLAB_R2015a.app/toolbox/eml/lib/matlab/elmat/find.m" };

static emlrtRTEInfo q_emlrtRTEI = { 183, 13, "find",
  "/Applications/MATLAB_R2015a.app/toolbox/eml/lib/matlab/elmat/find.m" };

static emlrtBCInfo db_emlrtBCI = { -1, -1, 33, 24, "col", "detectCircles",
  "/Users/vanessacolihan/Documents/MATLAB/sd/detectCircles.m", 0 };

static emlrtBCInfo eb_emlrtBCI = { -1, -1, 32, 24, "row", "detectCircles",
  "/Users/vanessacolihan/Documents/MATLAB/sd/detectCircles.m", 0 };

static emlrtRTEInfo fb_emlrtRTEI = { 24, 1, "detectCircles",
  "/Users/vanessacolihan/Documents/MATLAB/sd/detectCircles.m" };

static emlrtBCInfo fb_emlrtBCI = { -1, -1, 9, 53, "edges", "detectCircles",
  "/Users/vanessacolihan/Documents/MATLAB/sd/detectCircles.m", 0 };

static emlrtBCInfo gb_emlrtBCI = { -1, -1, 9, 32, "edges", "detectCircles",
  "/Users/vanessacolihan/Documents/MATLAB/sd/detectCircles.m", 0 };

static emlrtBCInfo hb_emlrtBCI = { -1, -1, 9, 15, "edges", "detectCircles",
  "/Users/vanessacolihan/Documents/MATLAB/sd/detectCircles.m", 0 };

static emlrtDCInfo emlrtDCI = { 3, 17, "detectCircles",
  "/Users/vanessacolihan/Documents/MATLAB/sd/detectCircles.m", 1 };

static emlrtDCInfo b_emlrtDCI = { 3, 17, "detectCircles",
  "/Users/vanessacolihan/Documents/MATLAB/sd/detectCircles.m", 4 };

static emlrtBCInfo ib_emlrtBCI = { 1, 164592, 25, 28, "H_sort", "detectCircles",
  "/Users/vanessacolihan/Documents/MATLAB/sd/detectCircles.m", 0 };

static emlrtBCInfo jb_emlrtBCI = { -1, -1, 32, 17, "centers", "detectCircles",
  "/Users/vanessacolihan/Documents/MATLAB/sd/detectCircles.m", 0 };

static emlrtBCInfo kb_emlrtBCI = { -1, -1, 33, 17, "centers", "detectCircles",
  "/Users/vanessacolihan/Documents/MATLAB/sd/detectCircles.m", 0 };

static emlrtBCInfo lb_emlrtBCI = { -1, -1, 27, 17, "centers", "detectCircles",
  "/Users/vanessacolihan/Documents/MATLAB/sd/detectCircles.m", 0 };

static emlrtBCInfo mb_emlrtBCI = { -1, -1, 27, 24, "row", "detectCircles",
  "/Users/vanessacolihan/Documents/MATLAB/sd/detectCircles.m", 0 };

static emlrtBCInfo nb_emlrtBCI = { -1, -1, 28, 17, "centers", "detectCircles",
  "/Users/vanessacolihan/Documents/MATLAB/sd/detectCircles.m", 0 };

static emlrtBCInfo ob_emlrtBCI = { -1, -1, 28, 24, "col", "detectCircles",
  "/Users/vanessacolihan/Documents/MATLAB/sd/detectCircles.m", 0 };

/* Function Definitions */
void detectCircles(extract_notesStackData *SD, const emlrtStack *sp, const
                   emxArray_real_T *edges, real_T radius, real_T top_k,
                   emxArray_real_T *centers)
{
  int32_T i13;
  real_T d0;
  real_T d1;
  int32_T jj;
  int32_T i;
  int32_T ii;
  real_T a;
  real_T b;
  int32_T repeat;
  emxArray_real_T *row;
  emxArray_real_T *col;
  emxArray_int32_T *b_ii;
  emxArray_int32_T *b_jj;
  boolean_T x[164592];
  int32_T idx;
  boolean_T exitg1;
  boolean_T guard1 = false;
  int32_T b_i;
  int32_T b_repeat;
  int32_T c_i;
  int32_T c_repeat;
  int32_T d_i;
  int32_T e_i;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  i13 = centers->size[0] * centers->size[1];
  if (top_k >= 0.0) {
    d0 = top_k;
  } else {
    d0 = emlrtNonNegativeCheckR2012b(top_k, &b_emlrtDCI, sp);
  }

  if (d0 == (int32_T)muDoubleScalarFloor(d0)) {
    centers->size[0] = (int32_T)d0;
  } else {
    centers->size[0] = (int32_T)emlrtIntegerCheckR2012b(d0, &emlrtDCI, sp);
  }

  centers->size[1] = 2;
  emxEnsureCapacity(sp, (emxArray__common *)centers, i13, (int32_T)sizeof(real_T),
                    &n_emlrtRTEI);
  if (top_k >= 0.0) {
    d0 = top_k;
  } else {
    d0 = emlrtNonNegativeCheckR2012b(top_k, &b_emlrtDCI, sp);
  }

  if (d0 == (int32_T)muDoubleScalarFloor(d0)) {
    d1 = d0;
  } else {
    d1 = emlrtIntegerCheckR2012b(d0, &emlrtDCI, sp);
  }

  jj = (int32_T)d1 << 1;
  for (i13 = 0; i13 < jj; i13++) {
    centers->data[i13] = 0.0;
  }

  memset(&SD->f5.H[0], 0, 164592U * sizeof(real_T));
  i = 0;
  while (i <= edges->size[0] - 1) {
    /* over every edge */
    /* [x, y, mag, ori] = edges(i, :); */
    i13 = edges->size[0];
    ii = i + 1;
    emlrtDynamicBoundsCheckR2012b(ii, 1, i13, &hb_emlrtBCI, sp);
    i13 = edges->size[0];
    ii = i + 1;
    emlrtDynamicBoundsCheckR2012b(ii, 1, i13, &gb_emlrtBCI, sp);
    i13 = edges->size[0];
    ii = i + 1;
    emlrtDynamicBoundsCheckR2012b(ii, 1, i13, &fb_emlrtBCI, sp);
    d0 = edges->data[i + edges->size[0] * 3];
    cosd(&d0);
    a = muDoubleScalarCeil((edges->data[i] - radius * d0) / 5.0);
    d0 = edges->data[i + edges->size[0] * 3];
    sind(&d0);
    b = muDoubleScalarCeil((edges->data[i + edges->size[0]] - radius * d0) / 5.0);
    if ((a > 0.0) && (b > 0.0) && (a < 216.0) && (b < 762.0)) {
      SD->f5.H[(int32_T)((a - 1.0) + 216.0 * (b - 1.0))]++;
    }

    i++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  st.site = &w_emlrtRSI;
  memcpy(&SD->f5.H_sort[0], &SD->f5.H[0], 164592U * sizeof(real_T));
  b_st.site = &x_emlrtRSI;
  eml_sort(SD, &b_st, SD->f5.H_sort);
  repeat = 2;
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, top_k, mxDOUBLE_CLASS, (int32_T)top_k,
    &fb_emlrtRTEI, sp);
  i = 1;
  b_emxInit_real_T(sp, &row, 1, &n_emlrtRTEI, true);
  b_emxInit_real_T(sp, &col, 1, &n_emlrtRTEI, true);
  emxInit_int32_T(sp, &b_ii, 1, &n_emlrtRTEI, true);
  emxInit_int32_T(sp, &b_jj, 1, &n_emlrtRTEI, true);
  while (i - 1 <= (int32_T)top_k - 1) {
    emlrtDynamicBoundsCheckR2012b(i, 1, 164592, &ib_emlrtBCI, sp);
    for (i13 = 0; i13 < 164592; i13++) {
      x[i13] = (SD->f5.H[i13] == SD->f5.H_sort[i - 1]);
    }

    idx = 0;
    i13 = b_ii->size[0];
    b_ii->size[0] = 164592;
    emxEnsureCapacity(sp, (emxArray__common *)b_ii, i13, (int32_T)sizeof(int32_T),
                      &o_emlrtRTEI);
    i13 = b_jj->size[0];
    b_jj->size[0] = 164592;
    emxEnsureCapacity(sp, (emxArray__common *)b_jj, i13, (int32_T)sizeof(int32_T),
                      &o_emlrtRTEI);
    ii = 1;
    jj = 1;
    exitg1 = false;
    while ((!exitg1) && (jj <= 762)) {
      guard1 = false;
      if (x[(ii + 216 * (jj - 1)) - 1]) {
        idx++;
        b_ii->data[idx - 1] = ii;
        b_jj->data[idx - 1] = jj;
        if (idx >= 164592) {
          exitg1 = true;
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }

      if (guard1) {
        ii++;
        if (ii > 216) {
          ii = 1;
          jj++;
        }
      }
    }

    i13 = b_ii->size[0];
    if (1 > idx) {
      b_ii->size[0] = 0;
    } else {
      b_ii->size[0] = idx;
    }

    emxEnsureCapacity(sp, (emxArray__common *)b_ii, i13, (int32_T)sizeof(int32_T),
                      &p_emlrtRTEI);
    i13 = b_jj->size[0];
    if (1 > idx) {
      b_jj->size[0] = 0;
    } else {
      b_jj->size[0] = idx;
    }

    emxEnsureCapacity(sp, (emxArray__common *)b_jj, i13, (int32_T)sizeof(int32_T),
                      &q_emlrtRTEI);
    i13 = row->size[0];
    row->size[0] = b_ii->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)row, i13, (int32_T)sizeof(real_T),
                      &n_emlrtRTEI);
    jj = b_ii->size[0];
    for (i13 = 0; i13 < jj; i13++) {
      row->data[i13] = b_ii->data[i13];
    }

    i13 = col->size[0];
    col->size[0] = b_jj->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)col, i13, (int32_T)sizeof(real_T),
                      &n_emlrtRTEI);
    jj = b_jj->size[0];
    for (i13 = 0; i13 < jj; i13++) {
      col->data[i13] = b_jj->data[i13];
    }

    if ((1.0 + (real_T)(i - 1) > 1.0) && (SD->f5.H_sort[i - 1] == SD->f5.H_sort
         [(int32_T)((1.0 + (real_T)(i - 1)) - 1.0) - 1])) {
      i13 = centers->size[0];
      ii = row->size[0];
      if ((i >= 1) && (i < i13)) {
        b_i = i;
      } else {
        b_i = emlrtDynamicBoundsCheckR2012b(i, 1, i13, &lb_emlrtBCI, sp);
      }

      if ((repeat >= 1) && (repeat < ii)) {
        b_repeat = repeat;
      } else {
        b_repeat = emlrtDynamicBoundsCheckR2012b(repeat, 1, ii, &mb_emlrtBCI, sp);
      }

      centers->data[b_i - 1] = row->data[b_repeat - 1];
      i13 = centers->size[0];
      ii = col->size[0];
      if ((i >= 1) && (i < i13)) {
        c_i = i;
      } else {
        c_i = emlrtDynamicBoundsCheckR2012b(i, 1, i13, &nb_emlrtBCI, sp);
      }

      if ((repeat >= 1) && (repeat < ii)) {
        c_repeat = repeat;
      } else {
        c_repeat = emlrtDynamicBoundsCheckR2012b(repeat, 1, ii, &ob_emlrtBCI, sp);
      }

      centers->data[(c_i + centers->size[0]) - 1] = col->data[c_repeat - 1];
      repeat++;
    } else {
      repeat = 2;
      i13 = row->size[0];
      emlrtDynamicBoundsCheckR2012b(1, 1, i13, &eb_emlrtBCI, sp);
      i13 = centers->size[0];
      if ((i >= 1) && (i < i13)) {
        d_i = i;
      } else {
        d_i = emlrtDynamicBoundsCheckR2012b(i, 1, i13, &jb_emlrtBCI, sp);
      }

      centers->data[d_i - 1] = row->data[0];
      i13 = col->size[0];
      emlrtDynamicBoundsCheckR2012b(1, 1, i13, &db_emlrtBCI, sp);
      i13 = centers->size[0];
      if ((i >= 1) && (i < i13)) {
        e_i = i;
      } else {
        e_i = emlrtDynamicBoundsCheckR2012b(i, 1, i13, &kb_emlrtBCI, sp);
      }

      centers->data[(e_i + centers->size[0]) - 1] = col->data[0];
    }

    i++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_int32_T(&b_jj);
  emxFree_int32_T(&b_ii);
  emxFree_real_T(&col);
  emxFree_real_T(&row);
  i13 = centers->size[0] * centers->size[1];
  centers->size[1] = 2;
  emxEnsureCapacity(sp, (emxArray__common *)centers, i13, (int32_T)sizeof(real_T),
                    &n_emlrtRTEI);
  jj = centers->size[0];
  ii = centers->size[1];
  jj *= ii;
  for (i13 = 0; i13 < jj; i13++) {
    centers->data[i13] *= 5.0;
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (detectCircles.c) */
