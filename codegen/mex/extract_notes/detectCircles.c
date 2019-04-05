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
static emlrtRSInfo mb_emlrtRSI = { 22, "detectCircles",
  "/Users/vanessacolihan/Documents/MATLAB/sd/detectCircles.m" };

static emlrtRSInfo nb_emlrtRSI = { 25, "sort",
  "/Applications/MATLAB_R2015a.app/toolbox/eml/lib/matlab/datafun/sort.m" };

static emlrtRTEInfo p_emlrtRTEI = { 1, 22, "detectCircles",
  "/Users/vanessacolihan/Documents/MATLAB/sd/detectCircles.m" };

static emlrtRTEInfo q_emlrtRTEI = { 37, 5, "find",
  "/Applications/MATLAB_R2015a.app/toolbox/eml/lib/matlab/elmat/find.m" };

static emlrtRTEInfo r_emlrtRTEI = { 182, 13, "find",
  "/Applications/MATLAB_R2015a.app/toolbox/eml/lib/matlab/elmat/find.m" };

static emlrtRTEInfo s_emlrtRTEI = { 183, 13, "find",
  "/Applications/MATLAB_R2015a.app/toolbox/eml/lib/matlab/elmat/find.m" };

static emlrtBCInfo fd_emlrtBCI = { -1, -1, 33, 24, "col", "detectCircles",
  "/Users/vanessacolihan/Documents/MATLAB/sd/detectCircles.m", 0 };

static emlrtBCInfo gd_emlrtBCI = { -1, -1, 32, 24, "row", "detectCircles",
  "/Users/vanessacolihan/Documents/MATLAB/sd/detectCircles.m", 0 };

static emlrtRTEInfo lb_emlrtRTEI = { 24, 1, "detectCircles",
  "/Users/vanessacolihan/Documents/MATLAB/sd/detectCircles.m" };

static emlrtBCInfo hd_emlrtBCI = { -1, -1, 9, 53, "edges", "detectCircles",
  "/Users/vanessacolihan/Documents/MATLAB/sd/detectCircles.m", 0 };

static emlrtBCInfo id_emlrtBCI = { -1, -1, 9, 32, "edges", "detectCircles",
  "/Users/vanessacolihan/Documents/MATLAB/sd/detectCircles.m", 0 };

static emlrtBCInfo jd_emlrtBCI = { -1, -1, 9, 15, "edges", "detectCircles",
  "/Users/vanessacolihan/Documents/MATLAB/sd/detectCircles.m", 0 };

static emlrtDCInfo n_emlrtDCI = { 3, 17, "detectCircles",
  "/Users/vanessacolihan/Documents/MATLAB/sd/detectCircles.m", 1 };

static emlrtDCInfo o_emlrtDCI = { 3, 17, "detectCircles",
  "/Users/vanessacolihan/Documents/MATLAB/sd/detectCircles.m", 4 };

static emlrtBCInfo kd_emlrtBCI = { 1, 164592, 25, 28, "H_sort", "detectCircles",
  "/Users/vanessacolihan/Documents/MATLAB/sd/detectCircles.m", 0 };

static emlrtBCInfo ld_emlrtBCI = { -1, -1, 32, 17, "centers", "detectCircles",
  "/Users/vanessacolihan/Documents/MATLAB/sd/detectCircles.m", 0 };

static emlrtBCInfo md_emlrtBCI = { -1, -1, 33, 17, "centers", "detectCircles",
  "/Users/vanessacolihan/Documents/MATLAB/sd/detectCircles.m", 0 };

static emlrtBCInfo nd_emlrtBCI = { -1, -1, 27, 17, "centers", "detectCircles",
  "/Users/vanessacolihan/Documents/MATLAB/sd/detectCircles.m", 0 };

static emlrtBCInfo od_emlrtBCI = { -1, -1, 27, 24, "row", "detectCircles",
  "/Users/vanessacolihan/Documents/MATLAB/sd/detectCircles.m", 0 };

static emlrtBCInfo pd_emlrtBCI = { -1, -1, 28, 17, "centers", "detectCircles",
  "/Users/vanessacolihan/Documents/MATLAB/sd/detectCircles.m", 0 };

static emlrtBCInfo qd_emlrtBCI = { -1, -1, 28, 24, "col", "detectCircles",
  "/Users/vanessacolihan/Documents/MATLAB/sd/detectCircles.m", 0 };

/* Function Definitions */
void detectCircles(extract_notesStackData *SD, const emlrtStack *sp, const
                   emxArray_real_T *edges, real_T radius, real_T top_k,
                   emxArray_real_T *centers)
{
  int32_T i29;
  real_T d2;
  real_T d3;
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
  i29 = centers->size[0] * centers->size[1];
  if (top_k >= 0.0) {
    d2 = top_k;
  } else {
    d2 = emlrtNonNegativeCheckR2012b(top_k, &o_emlrtDCI, sp);
  }

  if (d2 == (int32_T)muDoubleScalarFloor(d2)) {
    centers->size[0] = (int32_T)d2;
  } else {
    centers->size[0] = (int32_T)emlrtIntegerCheckR2012b(d2, &n_emlrtDCI, sp);
  }

  centers->size[1] = 2;
  emxEnsureCapacity(sp, (emxArray__common *)centers, i29, (int32_T)sizeof(real_T),
                    &p_emlrtRTEI);
  if (top_k >= 0.0) {
    d2 = top_k;
  } else {
    d2 = emlrtNonNegativeCheckR2012b(top_k, &o_emlrtDCI, sp);
  }

  if (d2 == (int32_T)muDoubleScalarFloor(d2)) {
    d3 = d2;
  } else {
    d3 = emlrtIntegerCheckR2012b(d2, &n_emlrtDCI, sp);
  }

  jj = (int32_T)d3 << 1;
  for (i29 = 0; i29 < jj; i29++) {
    centers->data[i29] = 0.0;
  }

  memset(&SD->f5.H[0], 0, 164592U * sizeof(real_T));
  i = 0;
  while (i <= edges->size[0] - 1) {
    /* over every edge */
    /* [x, y, mag, ori] = edges(i, :); */
    i29 = edges->size[0];
    ii = i + 1;
    emlrtDynamicBoundsCheckR2012b(ii, 1, i29, &jd_emlrtBCI, sp);
    i29 = edges->size[0];
    ii = i + 1;
    emlrtDynamicBoundsCheckR2012b(ii, 1, i29, &id_emlrtBCI, sp);
    i29 = edges->size[0];
    ii = i + 1;
    emlrtDynamicBoundsCheckR2012b(ii, 1, i29, &hd_emlrtBCI, sp);
    d2 = edges->data[i + edges->size[0] * 3];
    cosd(&d2);
    a = muDoubleScalarCeil((edges->data[i] - radius * d2) / 5.0);
    d2 = edges->data[i + edges->size[0] * 3];
    sind(&d2);
    b = muDoubleScalarCeil((edges->data[i + edges->size[0]] - radius * d2) / 5.0);
    if ((a > 0.0) && (b > 0.0) && (a < 216.0) && (b < 762.0)) {
      SD->f5.H[(int32_T)((a - 1.0) + 216.0 * (b - 1.0))]++;
    }

    i++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  st.site = &mb_emlrtRSI;
  memcpy(&SD->f5.H_sort[0], &SD->f5.H[0], 164592U * sizeof(real_T));
  b_st.site = &nb_emlrtRSI;
  eml_sort(SD, &b_st, SD->f5.H_sort);
  repeat = 2;
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, top_k, mxDOUBLE_CLASS, (int32_T)top_k,
    &lb_emlrtRTEI, sp);
  i = 1;
  b_emxInit_real_T(sp, &row, 1, &p_emlrtRTEI, true);
  b_emxInit_real_T(sp, &col, 1, &p_emlrtRTEI, true);
  emxInit_int32_T(sp, &b_ii, 1, &p_emlrtRTEI, true);
  emxInit_int32_T(sp, &b_jj, 1, &p_emlrtRTEI, true);
  while (i - 1 <= (int32_T)top_k - 1) {
    emlrtDynamicBoundsCheckR2012b(i, 1, 164592, &kd_emlrtBCI, sp);
    for (i29 = 0; i29 < 164592; i29++) {
      x[i29] = (SD->f5.H[i29] == SD->f5.H_sort[i - 1]);
    }

    idx = 0;
    i29 = b_ii->size[0];
    b_ii->size[0] = 164592;
    emxEnsureCapacity(sp, (emxArray__common *)b_ii, i29, (int32_T)sizeof(int32_T),
                      &q_emlrtRTEI);
    i29 = b_jj->size[0];
    b_jj->size[0] = 164592;
    emxEnsureCapacity(sp, (emxArray__common *)b_jj, i29, (int32_T)sizeof(int32_T),
                      &q_emlrtRTEI);
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

    i29 = b_ii->size[0];
    if (1 > idx) {
      b_ii->size[0] = 0;
    } else {
      b_ii->size[0] = idx;
    }

    emxEnsureCapacity(sp, (emxArray__common *)b_ii, i29, (int32_T)sizeof(int32_T),
                      &r_emlrtRTEI);
    i29 = b_jj->size[0];
    if (1 > idx) {
      b_jj->size[0] = 0;
    } else {
      b_jj->size[0] = idx;
    }

    emxEnsureCapacity(sp, (emxArray__common *)b_jj, i29, (int32_T)sizeof(int32_T),
                      &s_emlrtRTEI);
    i29 = row->size[0];
    row->size[0] = b_ii->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)row, i29, (int32_T)sizeof(real_T),
                      &p_emlrtRTEI);
    jj = b_ii->size[0];
    for (i29 = 0; i29 < jj; i29++) {
      row->data[i29] = b_ii->data[i29];
    }

    i29 = col->size[0];
    col->size[0] = b_jj->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)col, i29, (int32_T)sizeof(real_T),
                      &p_emlrtRTEI);
    jj = b_jj->size[0];
    for (i29 = 0; i29 < jj; i29++) {
      col->data[i29] = b_jj->data[i29];
    }

    if ((1.0 + (real_T)(i - 1) > 1.0) && (SD->f5.H_sort[i - 1] == SD->f5.H_sort
         [(int32_T)((1.0 + (real_T)(i - 1)) - 1.0) - 1])) {
      i29 = centers->size[0];
      ii = row->size[0];
      if ((i >= 1) && (i < i29)) {
        b_i = i;
      } else {
        b_i = emlrtDynamicBoundsCheckR2012b(i, 1, i29, &nd_emlrtBCI, sp);
      }

      if ((repeat >= 1) && (repeat < ii)) {
        b_repeat = repeat;
      } else {
        b_repeat = emlrtDynamicBoundsCheckR2012b(repeat, 1, ii, &od_emlrtBCI, sp);
      }

      centers->data[b_i - 1] = row->data[b_repeat - 1];
      i29 = centers->size[0];
      ii = col->size[0];
      if ((i >= 1) && (i < i29)) {
        c_i = i;
      } else {
        c_i = emlrtDynamicBoundsCheckR2012b(i, 1, i29, &pd_emlrtBCI, sp);
      }

      if ((repeat >= 1) && (repeat < ii)) {
        c_repeat = repeat;
      } else {
        c_repeat = emlrtDynamicBoundsCheckR2012b(repeat, 1, ii, &qd_emlrtBCI, sp);
      }

      centers->data[(c_i + centers->size[0]) - 1] = col->data[c_repeat - 1];
      repeat++;
    } else {
      repeat = 2;
      i29 = row->size[0];
      emlrtDynamicBoundsCheckR2012b(1, 1, i29, &gd_emlrtBCI, sp);
      i29 = centers->size[0];
      if ((i >= 1) && (i < i29)) {
        d_i = i;
      } else {
        d_i = emlrtDynamicBoundsCheckR2012b(i, 1, i29, &ld_emlrtBCI, sp);
      }

      centers->data[d_i - 1] = row->data[0];
      i29 = col->size[0];
      emlrtDynamicBoundsCheckR2012b(1, 1, i29, &fd_emlrtBCI, sp);
      i29 = centers->size[0];
      if ((i >= 1) && (i < i29)) {
        e_i = i;
      } else {
        e_i = emlrtDynamicBoundsCheckR2012b(i, 1, i29, &md_emlrtBCI, sp);
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
  i29 = centers->size[0] * centers->size[1];
  centers->size[1] = 2;
  emxEnsureCapacity(sp, (emxArray__common *)centers, i29, (int32_T)sizeof(real_T),
                    &p_emlrtRTEI);
  jj = centers->size[0];
  ii = centers->size[1];
  jj *= ii;
  for (i29 = 0; i29 < jj; i29++) {
    centers->data[i29] *= 5.0;
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (detectCircles.c) */
