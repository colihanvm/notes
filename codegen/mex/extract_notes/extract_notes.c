/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * extract_notes.c
 *
 * Code generation for function 'extract_notes'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "extract_notes.h"
#include "extract_notes_emxutil.h"
#include "detectEdges_removeLines.h"
#include "detectCircles.h"
#include "eml_int_forloop_overflow_check.h"
#include "eml_sort.h"
#include "sum.h"
#include "rgb2gray.h"
#include "extract_notes_data.h"
#include "libmwimfilter.h"
#include "libmwippfilter.h"

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 7, "extract_notes",
  "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m" };

static emlrtRSInfo b_emlrtRSI = { 98, "extract_notes",
  "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m" };

static emlrtRSInfo c_emlrtRSI = { 100, "extract_notes",
  "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m" };

static emlrtRSInfo d_emlrtRSI = { 103, "extract_notes",
  "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m" };

static emlrtRSInfo e_emlrtRSI = { 112, "extract_notes",
  "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m" };

static emlrtRSInfo f_emlrtRSI = { 134, "extract_notes",
  "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m" };

static emlrtRSInfo g_emlrtRSI = { 132, "extract_notes",
  "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m" };

static emlrtRSInfo wb_emlrtRSI = { 20, "sort",
  "/Applications/MATLAB_R2015a.app/toolbox/eml/lib/matlab/datafun/sort.m" };

static emlrtRSInfo ic_emlrtRSI = { 19, "eml_null_assignment",
  "/Applications/MATLAB_R2015a.app/toolbox/eml/lib/matlab/eml/eml_null_assignment.m"
};

static emlrtRSInfo jc_emlrtRSI = { 23, "eml_null_assignment",
  "/Applications/MATLAB_R2015a.app/toolbox/eml/lib/matlab/eml/eml_null_assignment.m"
};

static emlrtRSInfo kc_emlrtRSI = { 266, "eml_null_assignment",
  "/Applications/MATLAB_R2015a.app/toolbox/eml/lib/matlab/eml/eml_null_assignment.m"
};

static emlrtRSInfo lc_emlrtRSI = { 269, "eml_null_assignment",
  "/Applications/MATLAB_R2015a.app/toolbox/eml/lib/matlab/eml/eml_null_assignment.m"
};

static emlrtRSInfo mc_emlrtRSI = { 128, "eml_null_assignment",
  "/Applications/MATLAB_R2015a.app/toolbox/eml/lib/matlab/eml/eml_null_assignment.m"
};

static emlrtRTEInfo c_emlrtRTEI = { 1, 20, "extract_notes",
  "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m" };

static emlrtRTEInfo d_emlrtRTEI = { 98, 5, "extract_notes",
  "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m" };

static emlrtRTEInfo e_emlrtRTEI = { 100, 5, "extract_notes",
  "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m" };

static emlrtRTEInfo f_emlrtRTEI = { 122, 5, "extract_notes",
  "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m" };

static emlrtRTEInfo g_emlrtRTEI = { 123, 5, "extract_notes",
  "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m" };

static emlrtRTEInfo t_emlrtRTEI = { 1, 14, "eml_null_assignment",
  "/Applications/MATLAB_R2015a.app/toolbox/eml/lib/matlab/eml/eml_null_assignment.m"
};

static emlrtBCInfo emlrtBCI = { -1, -1, 131, 36, "centers", "extract_notes",
  "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m", 0 };

static emlrtBCInfo b_emlrtBCI = { -1, -1, 131, 10, "temp", "extract_notes",
  "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m", 0 };

static emlrtBCInfo c_emlrtBCI = { -1, -1, 37, 5, "lines", "extract_notes",
  "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m", 0 };

static emlrtBCInfo d_emlrtBCI = { -1, -1, 150, 20, "int_notes", "extract_notes",
  "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m", 0 };

static emlrtBCInfo e_emlrtBCI = { -1, -1, 150, 44, "centers", "extract_notes",
  "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m", 0 };

static emlrtECInfo emlrtECI = { -1, 131, 5, "extract_notes",
  "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m" };

static emlrtBCInfo f_emlrtBCI = { -1, -1, 79, 39, "ind", "extract_notes",
  "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m", 0 };

static emlrtBCInfo g_emlrtBCI = { -1, -1, 79, 20, "ind", "extract_notes",
  "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m", 0 };

static emlrtBCInfo h_emlrtBCI = { -1, -1, 76, 43, "ind", "extract_notes",
  "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m", 0 };

static emlrtBCInfo i_emlrtBCI = { -1, -1, 76, 24, "ind", "extract_notes",
  "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m", 0 };

static emlrtBCInfo j_emlrtBCI = { -1, -1, 74, 43, "ind", "extract_notes",
  "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m", 0 };

static emlrtBCInfo k_emlrtBCI = { -1, -1, 74, 24, "ind", "extract_notes",
  "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m", 0 };

static emlrtBCInfo l_emlrtBCI = { -1, -1, 33, 17, "ind", "extract_notes",
  "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m", 0 };

static emlrtBCInfo m_emlrtBCI = { -1, -1, 104, 24, "centers", "extract_notes",
  "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m", 0 };

static emlrtBCInfo n_emlrtBCI = { -1, -1, 113, 24, "centers", "extract_notes",
  "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m", 0 };

static emlrtBCInfo o_emlrtBCI = { -1, -1, 126, 20, "centers", "extract_notes",
  "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m", 0 };

static emlrtBCInfo p_emlrtBCI = { -1, -1, 127, 13, "resort", "extract_notes",
  "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m", 0 };

static emlrtBCInfo q_emlrtBCI = { -1, -1, 68, 19, "ind", "extract_notes",
  "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m", 0 };

static emlrtBCInfo r_emlrtBCI = { -1, -1, 69, 19, "ind", "extract_notes",
  "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m", 0 };

static emlrtBCInfo s_emlrtBCI = { 1, 216, 72, 20, "im", "extract_notes",
  "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m", 0 };

static emlrtBCInfo t_emlrtBCI = { 1, 216, 78, 23, "im", "extract_notes",
  "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m", 0 };

static emlrtBCInfo u_emlrtBCI = { 1, 216, 73, 23, "im", "extract_notes",
  "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m", 0 };

static emlrtBCInfo v_emlrtBCI = { -1, -1, 41, 13, "ind", "extract_notes",
  "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m", 0 };

static emlrtBCInfo w_emlrtBCI = { -1, -1, 41, 23, "ind", "extract_notes",
  "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m", 0 };

static emlrtBCInfo x_emlrtBCI = { -1, -1, 49, 37, "ind", "extract_notes",
  "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m", 0 };

static emlrtBCInfo y_emlrtBCI = { -1, -1, 50, 13, "lines", "extract_notes",
  "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m", 0 };

static emlrtBCInfo ab_emlrtBCI = { 1, 10, 45, 13, "staffs", "extract_notes",
  "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m", 0 };

static emlrtBCInfo bb_emlrtBCI = { -1, -1, 45, 25, "ind", "extract_notes",
  "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m", 0 };

static emlrtBCInfo cb_emlrtBCI = { -1, -1, 46, 13, "lines", "extract_notes",
  "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m", 0 };

static emlrtRTEInfo hb_emlrtRTEI = { 77, 27, "eml_null_assignment",
  "/Applications/MATLAB_R2015a.app/toolbox/eml/lib/matlab/eml/eml_null_assignment.m"
};

static emlrtRTEInfo ib_emlrtRTEI = { 278, 1, "eml_null_assignment",
  "/Applications/MATLAB_R2015a.app/toolbox/eml/lib/matlab/eml/eml_null_assignment.m"
};

/* Function Declarations */
static void eml_null_assignment(const emlrtStack *sp, emxArray_real_T *x, const
  emxArray_boolean_T *idx);

/* Function Definitions */
static void eml_null_assignment(const emlrtStack *sp, emxArray_real_T *x, const
  emxArray_boolean_T *idx)
{
  int32_T k;
  int32_T nrowx;
  int32_T nrows;
  boolean_T overflow;
  int32_T i;
  int32_T j;
  emxArray_real_T *b_x;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  st.site = &ic_emlrtRSI;
  k = idx->size[0];
  while ((k >= 1) && (!idx->data[k - 1])) {
    k--;
  }

  if (k <= x->size[0]) {
  } else {
    emlrtErrorWithMessageIdR2012b(&st, &hb_emlrtRTEI,
      "MATLAB:subsdeldimmismatch", 0);
  }

  st.site = &jc_emlrtRSI;
  nrowx = x->size[0];
  b_st.site = &kc_emlrtRSI;
  nrows = 0;
  c_st.site = &mc_emlrtRSI;
  if (1 > idx->size[0]) {
    overflow = false;
  } else {
    overflow = (idx->size[0] > 2147483646);
  }

  if (overflow) {
    d_st.site = &kb_emlrtRSI;
    check_forloop_overflow_error(&d_st);
  }

  for (k = 1; k <= idx->size[0]; k++) {
    nrows += idx->data[k - 1];
  }

  nrows = x->size[0] - nrows;
  i = 0;
  b_st.site = &lc_emlrtRSI;
  if (1 > x->size[0]) {
    overflow = false;
  } else {
    overflow = (x->size[0] > 2147483646);
  }

  if (overflow) {
    c_st.site = &kb_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }

  for (k = 1; k <= nrowx; k++) {
    if ((k > idx->size[0]) || (!idx->data[k - 1])) {
      for (j = 0; j < 2; j++) {
        x->data[i + x->size[0] * j] = x->data[(k + x->size[0] * j) - 1];
      }

      i++;
    }
  }

  if (nrows <= nrowx) {
  } else {
    emlrtErrorWithMessageIdR2012b(&st, &ib_emlrtRTEI,
      "Coder:builtins:AssertionFailed", 0);
  }

  if (1 > nrows) {
    nrows = 0;
  }

  emxInit_real_T(&st, &b_x, 2, &t_emlrtRTEI, true);
  i = b_x->size[0] * b_x->size[1];
  b_x->size[0] = nrows;
  b_x->size[1] = 2;
  emxEnsureCapacity(&st, (emxArray__common *)b_x, i, (int32_T)sizeof(real_T),
                    &t_emlrtRTEI);
  for (i = 0; i < 2; i++) {
    for (j = 0; j < nrows; j++) {
      b_x->data[j + b_x->size[0] * i] = x->data[j + x->size[0] * i];
    }
  }

  i = x->size[0] * x->size[1];
  x->size[0] = b_x->size[0];
  x->size[1] = 2;
  emxEnsureCapacity(&st, (emxArray__common *)x, i, (int32_T)sizeof(real_T),
                    &t_emlrtRTEI);
  for (i = 0; i < 2; i++) {
    nrows = b_x->size[0];
    for (j = 0; j < nrows; j++) {
      x->data[j + x->size[0] * i] = b_x->data[j + b_x->size[0] * i];
    }
  }

  emxFree_real_T(&b_x);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

void extract_notes(extract_notesStackData *SD, const emlrtStack *sp, const
                   uint8_T im[493776], real_T threshold, real_T num_find, real_T
                   radius, emxArray_char_T *notes)
{
  int32_T i;
  int32_T j;
  int32_T i0;
  real_T dv0[216];
  boolean_T x[216];
  int32_T idx;
  uint8_T ii_data[216];
  int32_T ii;
  boolean_T exitg1;
  boolean_T guard1 = false;
  int32_T loop_ub;
  uint8_T ind_data[216];
  int32_T i1;
  real_T staffs[10];
  real_T num;
  real_T staff_num[10];
  int32_T b_i;
  int32_T i2;
  int32_T b_j;
  int32_T c_i;
  int32_T d_i;
  real_T lines_passed;
  int32_T i3;
  int32_T above_s;
  int32_T i4;
  real_T below_s;
  int32_T b_x;
  int32_T i5;
  int32_T i6;
  uint8_T y;
  int32_T i7;
  emxArray_real_T *edges;
  emxArray_real_T *centers;
  emxArray_real_T *resort;
  emxArray_int32_T *iidx;
  emxArray_real_T *b_centers;
  int32_T e_i;
  emxArray_real_T *c_centers;
  int32_T f_i;
  uint32_T uv0[2];
  emxArray_real_T *temp;
  int32_T g_i;
  int32_T h_i;
  emxArray_real_T *d_centers;
  int32_T b_iidx[2];
  int32_T e_centers[2];
  emxArray_boolean_T *b_resort;
  emxArray_boolean_T *c_resort;
  emxArray_real_T *f_centers;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);

  /*      radius = 7; %pretty good for 4th, 8th */
  /*      num = 60;  */
  /*  threshold = 155; */
  /*  im = imread('rowrowbt_mod3.png'); */
  st.site = &emlrtRSI;
  rgb2gray(&st, im, SD->f6.b_im);
  i = 0;
  while (i < 216) {
    j = 0;
    while (j < 762) {
      if (SD->f6.b_im[i + 216 * j] > 240) {
        SD->f6.b_im[i + 216 * j] = MAX_uint8_T;
      }

      j++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    i++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  /*  figure; imshow(im); title('pixel color adjust'); */
  /*  figure; plot(tmp);  title('row sum'); */
  /*   */
  /*  pause; */
  for (i0 = 0; i0 < 164592; i0++) {
    SD->f6.im[i0] = SD->f6.b_im[i0];
  }

  sum(SD->f6.im, dv0);
  for (i = 0; i < 216; i++) {
    x[i] = (dv0[i] < 147000.0);
  }

  idx = 0;
  ii = 1;
  exitg1 = false;
  while ((!exitg1) && (ii < 217)) {
    guard1 = false;
    if (x[ii - 1]) {
      idx++;
      ii_data[idx - 1] = (uint8_T)ii;
      if (idx >= 216) {
        exitg1 = true;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }

    if (guard1) {
      ii++;
    }
  }

  if (1 > idx) {
    loop_ub = 0;
  } else {
    loop_ub = idx;
  }

  for (i0 = 0; i0 < loop_ub; i0++) {
    ind_data[i0] = ii_data[i0];
  }

  if (1 > idx) {
    ii = 0;
  } else {
    ii = idx;
  }

  for (i0 = 0; i0 < loop_ub; i0++) {
    ii_data[i0] = ind_data[i0];
  }

  for (i0 = 0; i0 < 762; i0++) {
    for (i1 = 0; i1 < ii; i1++) {
      SD->f6.b_im[(ii_data[i1] + 216 * i0) - 1] = MAX_uint8_T;
    }
  }

  /*  figure; imshow(im); title('lines erased'); */
  /* pause; */
  /* calculate staff lines */
  memset(&staffs[0], 0, 10U * sizeof(real_T));
  emlrtDynamicBoundsCheckR2012b(1, 1, loop_ub, &l_emlrtBCI, sp);
  staffs[0] = ind_data[0];
  j = 0;
  num = 1.0;
  emlrtDynamicBoundsCheckR2012b(1, 1, loop_ub, &c_emlrtBCI, sp);
  memset(&staff_num[0], 0, 10U * sizeof(real_T));
  staff_num[0] = 1.0;
  i = 2;
  while (i - 2 <= loop_ub - 2) {
    i0 = i - 1;
    if ((i >= 1) && (i < loop_ub)) {
      b_i = i;
    } else {
      b_i = emlrtDynamicBoundsCheckR2012b(i, 1, loop_ub, &v_emlrtBCI, sp);
    }

    if ((i0 >= 1) && (i0 < loop_ub)) {
      i2 = i0;
    } else {
      i2 = emlrtDynamicBoundsCheckR2012b(i0, 1, loop_ub, &w_emlrtBCI, sp);
    }

    if (ind_data[b_i - 1] > ind_data[i2 - 1] + 1) {
      /* end line deletion */
      staffs[j] = muDoubleScalarFloor(staffs[j] / num);
      num = 1.0;
      j++;
      if ((j + 1 >= 1) && (j + 1 < 10)) {
        b_j = j + 1;
      } else {
        b_j = emlrtDynamicBoundsCheckR2012b(j + 1, 1, 10, &ab_emlrtBCI, sp);
      }

      if ((i >= 1) && (i < loop_ub)) {
        c_i = i;
      } else {
        c_i = emlrtDynamicBoundsCheckR2012b(i, 1, loop_ub, &bb_emlrtBCI, sp);
      }

      staffs[b_j - 1] = ind_data[c_i - 1];

      /* first line */
      emlrtDynamicBoundsCheckR2012b(i, 1, loop_ub, &cb_emlrtBCI, sp);
      staff_num[j]++;
    } else {
      if ((i >= 1) && (i < loop_ub)) {
        d_i = i;
      } else {
        d_i = emlrtDynamicBoundsCheckR2012b(i, 1, loop_ub, &x_emlrtBCI, sp);
      }

      staffs[j] += (real_T)ind_data[d_i - 1];

      /* there was a line deleted above this */
      emlrtDynamicBoundsCheckR2012b(i, 1, loop_ub, &y_emlrtBCI, sp);
      staff_num[j]++;
      num++;
      if (i == loop_ub) {
        /* last */
        staffs[j] = muDoubleScalarFloor(staffs[j] / num);
      }
    }

    i++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  /*  figure; imshow(im); title('visualization of no staff lines'); hold on */
  /* pause; */
  /* GAP STITCHING: */
  /* lines array contains index of staffs that were removed, matches ind array */
  /* staff_num tells number of horiz lines deleted around this staff */
  lines_passed = 1.0;

  /* will give current index of ind array (y pos of all staff part lines detected) */
  idx = 0;
  while (idx < 10) {
    /* y values of staffs. s = index of staffs AKA staff number */
    i0 = (int32_T)lines_passed;
    if ((i0 >= 1) && (i0 < loop_ub)) {
      i3 = i0;
    } else {
      i3 = emlrtDynamicBoundsCheckR2012b(i0, 1, loop_ub, &q_emlrtBCI, sp);
    }

    above_s = ind_data[i3 - 1] - 1;
    i0 = (int32_T)lines_passed;
    if ((i0 >= 1) && (i0 < loop_ub)) {
      i4 = i0;
    } else {
      i4 = emlrtDynamicBoundsCheckR2012b(i0, 1, loop_ub, &r_emlrtBCI, sp);
    }

    below_s = (real_T)ind_data[i4 - 1] + staff_num[idx];

    /* ind(lines_passed) + staff_num(s)-1 + 1; */
    b_x = 0;
    while (b_x < 762) {
      /* x pos of image */
      i0 = above_s;
      if (i0 >= 1) {
        i5 = i0;
      } else {
        i5 = emlrtDynamicBoundsCheckR2012b(i0, 1, 216, &s_emlrtBCI, sp);
      }

      if (SD->f6.b_im[(i5 + 216 * b_x) - 1] < 200) {
        i0 = (int32_T)below_s;
        if ((i0 >= 1) && (i0 < 216)) {
          i6 = i0;
        } else {
          i6 = emlrtDynamicBoundsCheckR2012b(i0, 1, 216, &u_emlrtBCI, sp);
        }

        if (SD->f6.b_im[(i6 + 216 * b_x) - 1] < 200) {
          i0 = (int32_T)lines_passed;
          emlrtDynamicBoundsCheckR2012b(i0, 1, loop_ub, &k_emlrtBCI, sp);
          i0 = (int32_T)((lines_passed + staff_num[idx]) - 1.0);
          emlrtDynamicBoundsCheckR2012b(i0, 1, loop_ub, &j_emlrtBCI, sp);
          if (ind_data[(int32_T)lines_passed - 1] > ind_data[(int32_T)
              ((lines_passed + staff_num[idx]) - 1.0) - 1]) {
            i0 = 0;
            i1 = 0;
          } else {
            i0 = ind_data[(int32_T)lines_passed - 1] - 1;
            i1 = ind_data[(int32_T)((lines_passed + staff_num[idx]) - 1.0) - 1];
          }

          i = (int32_T)((uint32_T)SD->f6.b_im[(above_s + 216 * b_x) - 1] +
                        SD->f6.b_im[((int32_T)below_s + 216 * b_x) - 1]);
          if ((uint32_T)i > 255U) {
            i = 255;
          }

          i = (int32_T)muDoubleScalarRound((real_T)i / 2.0);
          y = (uint8_T)i;
          ii = i1 - i0;
          for (i1 = 0; i1 < ii; i1++) {
            SD->f6.b_im[(i0 + i1) + 216 * b_x] = y;
          }
        } else {
          if (SD->f6.b_im[(above_s + 216 * b_x) - 1] < 150) {
            i0 = (int32_T)lines_passed;
            emlrtDynamicBoundsCheckR2012b(i0, 1, loop_ub, &i_emlrtBCI, sp);
            i0 = (int32_T)((lines_passed + staff_num[idx]) - 1.0);
            emlrtDynamicBoundsCheckR2012b(i0, 1, loop_ub, &h_emlrtBCI, sp);
            if (ind_data[(int32_T)lines_passed - 1] > ind_data[(int32_T)
                ((lines_passed + staff_num[idx]) - 1.0) - 1]) {
              i0 = 0;
              i1 = 0;
            } else {
              i0 = ind_data[(int32_T)lines_passed - 1] - 1;
              i1 = ind_data[(int32_T)((lines_passed + staff_num[idx]) - 1.0) - 1];
            }

            i = (int32_T)muDoubleScalarRound((real_T)SD->f6.b_im[(above_s + 216 *
              b_x) - 1] / 2.0);
            y = (uint8_T)i;
            ii = i1 - i0;
            for (i1 = 0; i1 < ii; i1++) {
              SD->f6.b_im[(i0 + i1) + 216 * b_x] = y;
            }
          }
        }
      } else {
        i0 = (int32_T)below_s;
        if ((i0 >= 1) && (i0 < 216)) {
          i7 = i0;
        } else {
          i7 = emlrtDynamicBoundsCheckR2012b(i0, 1, 216, &t_emlrtBCI, sp);
        }

        if (SD->f6.b_im[(i7 + 216 * b_x) - 1] < 150) {
          i0 = (int32_T)lines_passed;
          emlrtDynamicBoundsCheckR2012b(i0, 1, loop_ub, &g_emlrtBCI, sp);
          i0 = (int32_T)((lines_passed + staff_num[idx]) - 1.0);
          emlrtDynamicBoundsCheckR2012b(i0, 1, loop_ub, &f_emlrtBCI, sp);
          if (ind_data[(int32_T)lines_passed - 1] > ind_data[(int32_T)
              ((lines_passed + staff_num[idx]) - 1.0) - 1]) {
            i0 = 0;
            i1 = 0;
          } else {
            i0 = ind_data[(int32_T)lines_passed - 1] - 1;
            i1 = ind_data[(int32_T)((lines_passed + staff_num[idx]) - 1.0) - 1];
          }

          i = (int32_T)muDoubleScalarRound((real_T)SD->f6.b_im[((int32_T)below_s
            + 216 * b_x) - 1] / 2.0);
          y = (uint8_T)i;
          ii = i1 - i0;
          for (i1 = 0; i1 < ii; i1++) {
            SD->f6.b_im[(i0 + i1) + 216 * b_x] = y;
          }
        }
      }

      b_x++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    lines_passed += staff_num[idx];
    idx++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxInit_real_T(sp, &edges, 2, &d_emlrtRTEI, true);
  emxInit_real_T(sp, &centers, 2, &e_emlrtRTEI, true);
  b_emxInit_real_T(sp, &resort, 1, &f_emlrtRTEI, true);

  /*  figure; imshow(im); title('visualization of slightly more lines'); hold on */
  /*  figure; imshow(im); title('visualization of staff lines'); hold on */
  /*  plot(x, staffs*ones(size(x))); */
  /*   */
  /*  pause; */
  /*      radius = 7; %pretty good for 4th, 8th */
  /*      num = 60;  */
  st.site = &b_emlrtRSI;
  detectEdges_removeLines(SD, &st, SD->f6.b_im, threshold, edges);
  st.site = &c_emlrtRSI;
  detectCircles(SD, &st, edges, radius, num_find, centers);

  /* sort for y pos */
  st.site = &d_emlrtRSI;
  loop_ub = centers->size[0];
  i0 = resort->size[0];
  resort->size[0] = loop_ub;
  emxEnsureCapacity(&st, (emxArray__common *)resort, i0, (int32_T)sizeof(real_T),
                    &c_emlrtRTEI);
  emxFree_real_T(&edges);
  for (i0 = 0; i0 < loop_ub; i0++) {
    resort->data[i0] = centers->data[i0 + centers->size[0]];
  }

  emxInit_int32_T(&st, &iidx, 1, &c_emlrtRTEI, true);
  emxInit_real_T(&st, &b_centers, 2, &c_emlrtRTEI, true);
  b_st.site = &wb_emlrtRSI;
  c_eml_sort(&b_st, resort, iidx);
  ii = centers->size[0];
  i0 = b_centers->size[0] * b_centers->size[1];
  b_centers->size[0] = iidx->size[0];
  b_centers->size[1] = 2;
  emxEnsureCapacity(sp, (emxArray__common *)b_centers, i0, (int32_T)sizeof
                    (real_T), &c_emlrtRTEI);
  for (i0 = 0; i0 < 2; i0++) {
    loop_ub = iidx->size[0];
    for (i1 = 0; i1 < loop_ub; i1++) {
      i = iidx->data[i1];
      if ((i >= 1) && (i < ii)) {
        e_i = i;
      } else {
        e_i = emlrtDynamicBoundsCheckR2012b(i, 1, ii, &m_emlrtBCI, sp);
      }

      b_centers->data[i1 + b_centers->size[0] * i0] = centers->data[(e_i +
        centers->size[0] * i0) - 1];
    }
  }

  i0 = centers->size[0] * centers->size[1];
  centers->size[0] = b_centers->size[0];
  centers->size[1] = 2;
  emxEnsureCapacity(sp, (emxArray__common *)centers, i0, (int32_T)sizeof(real_T),
                    &c_emlrtRTEI);
  for (i0 = 0; i0 < 2; i0++) {
    loop_ub = b_centers->size[0];
    for (i1 = 0; i1 < loop_ub; i1++) {
      centers->data[i1 + centers->size[0] * i0] = b_centers->data[i1 +
        b_centers->size[0] * i0];
    }
  }

  emxFree_real_T(&b_centers);

  /* centers(13:15,:) = []; %change to remove based on staff lol */
  /* also check for stacked circles (works if no chords) */
  /*  NEXT PART: */
  /* sort for x pos */
  st.site = &e_emlrtRSI;
  loop_ub = centers->size[0];
  i0 = resort->size[0];
  resort->size[0] = loop_ub;
  emxEnsureCapacity(&st, (emxArray__common *)resort, i0, (int32_T)sizeof(real_T),
                    &c_emlrtRTEI);
  for (i0 = 0; i0 < loop_ub; i0++) {
    resort->data[i0] = centers->data[i0];
  }

  emxInit_real_T(&st, &c_centers, 2, &c_emlrtRTEI, true);
  b_st.site = &wb_emlrtRSI;
  c_eml_sort(&b_st, resort, iidx);
  ii = centers->size[0];
  i0 = c_centers->size[0] * c_centers->size[1];
  c_centers->size[0] = iidx->size[0];
  c_centers->size[1] = 2;
  emxEnsureCapacity(sp, (emxArray__common *)c_centers, i0, (int32_T)sizeof
                    (real_T), &c_emlrtRTEI);
  for (i0 = 0; i0 < 2; i0++) {
    loop_ub = iidx->size[0];
    for (i1 = 0; i1 < loop_ub; i1++) {
      i = iidx->data[i1];
      if ((i >= 1) && (i < ii)) {
        f_i = i;
      } else {
        f_i = emlrtDynamicBoundsCheckR2012b(i, 1, ii, &n_emlrtBCI, sp);
      }

      c_centers->data[i1 + c_centers->size[0] * i0] = centers->data[(f_i +
        centers->size[0] * i0) - 1];
    }
  }

  i0 = centers->size[0] * centers->size[1];
  centers->size[0] = c_centers->size[0];
  centers->size[1] = 2;
  emxEnsureCapacity(sp, (emxArray__common *)centers, i0, (int32_T)sizeof(real_T),
                    &c_emlrtRTEI);
  for (i0 = 0; i0 < 2; i0++) {
    loop_ub = c_centers->size[0];
    for (i1 = 0; i1 < loop_ub; i1++) {
      centers->data[i1 + centers->size[0] * i0] = c_centers->data[i1 +
        c_centers->size[0] * i0];
    }
  }

  emxFree_real_T(&c_centers);

  /* cleanup */
  /*  centers(6,:) = []; */
  /*  centers(7:8,:) = []; */
  /*  centers(8,:) = []; */
  /*  centers(12,:) = []; */
  i0 = resort->size[0];
  resort->size[0] = centers->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)resort, i0, (int32_T)sizeof(real_T),
                    &c_emlrtRTEI);
  loop_ub = centers->size[0];
  for (i0 = 0; i0 < loop_ub; i0++) {
    resort->data[i0] = 0.0;
  }

  for (i0 = 0; i0 < 2; i0++) {
    uv0[i0] = (uint32_T)centers->size[i0];
  }

  emxInit_real_T(sp, &temp, 2, &g_emlrtRTEI, true);
  i0 = temp->size[0] * temp->size[1];
  temp->size[0] = (int32_T)uv0[0];
  temp->size[1] = 2;
  emxEnsureCapacity(sp, (emxArray__common *)temp, i0, (int32_T)sizeof(real_T),
                    &c_emlrtRTEI);
  loop_ub = (int32_T)uv0[0] << 1;
  for (i0 = 0; i0 < loop_ub; i0++) {
    temp->data[i0] = 0.0;
  }

  i = 1;
  while (i - 1 <= centers->size[0] - 1) {
    i0 = centers->size[0];
    if ((i >= 1) && (i < i0)) {
      g_i = i;
    } else {
      g_i = emlrtDynamicBoundsCheckR2012b(i, 1, i0, &o_emlrtBCI, sp);
    }

    if (centers->data[(g_i + centers->size[0]) - 1] > (staffs[4] + staffs[5]) /
        2.0) {
      i0 = resort->size[0];
      if ((i >= 1) && (i < i0)) {
        h_i = i;
      } else {
        h_i = emlrtDynamicBoundsCheckR2012b(i, 1, i0, &p_emlrtBCI, sp);
      }

      resort->data[h_i - 1] = 1.0;
    }

    i++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  /* reorder staff line notes so they floooow */
  idx = resort->size[0];
  for (i = 0; i < idx; i++) {
    if (resort->data[i] == 1.0) {
      i0 = (int32_T)uv0[0];
      emlrtDynamicBoundsCheckR2012b(i + 1, 1, i0, &b_emlrtBCI, sp);
    }
  }

  idx = resort->size[0];
  for (i = 0; i < idx; i++) {
    if (resort->data[i] == 1.0) {
      i0 = centers->size[0];
      emlrtDynamicBoundsCheckR2012b(i + 1, 1, i0, &emlrtBCI, sp);
    }
  }

  idx = resort->size[0] - 1;
  ii = 0;
  for (i = 0; i <= idx; i++) {
    if (resort->data[i] == 1.0) {
      ii++;
    }
  }

  i0 = iidx->size[0];
  iidx->size[0] = ii;
  emxEnsureCapacity(sp, (emxArray__common *)iidx, i0, (int32_T)sizeof(int32_T),
                    &c_emlrtRTEI);
  ii = 0;
  for (i = 0; i <= idx; i++) {
    if (resort->data[i] == 1.0) {
      iidx->data[ii] = i + 1;
      ii++;
    }
  }

  emxInit_real_T(sp, &d_centers, 2, &c_emlrtRTEI, true);
  b_iidx[0] = iidx->size[0];
  b_iidx[1] = 2;
  i0 = d_centers->size[0] * d_centers->size[1];
  d_centers->size[0] = iidx->size[0];
  d_centers->size[1] = 2;
  emxEnsureCapacity(sp, (emxArray__common *)d_centers, i0, (int32_T)sizeof
                    (real_T), &c_emlrtRTEI);
  for (i0 = 0; i0 < 2; i0++) {
    loop_ub = iidx->size[0];
    for (i1 = 0; i1 < loop_ub; i1++) {
      d_centers->data[i1 + d_centers->size[0] * i0] = centers->data[(iidx->
        data[i1] + centers->size[0] * i0) - 1];
    }
  }

  for (i0 = 0; i0 < 2; i0++) {
    e_centers[i0] = d_centers->size[i0];
  }

  emxFree_real_T(&d_centers);
  emlrtSubAssignSizeCheckR2012b(b_iidx, 2, e_centers, 2, &emlrtECI, sp);
  idx = resort->size[0] - 1;
  ii = 0;
  for (i = 0; i <= idx; i++) {
    if (resort->data[i] == 1.0) {
      ii++;
    }
  }

  i0 = iidx->size[0];
  iidx->size[0] = ii;
  emxEnsureCapacity(sp, (emxArray__common *)iidx, i0, (int32_T)sizeof(int32_T),
                    &c_emlrtRTEI);
  ii = 0;
  for (i = 0; i <= idx; i++) {
    if (resort->data[i] == 1.0) {
      iidx->data[ii] = i + 1;
      ii++;
    }
  }

  for (i0 = 0; i0 < 2; i0++) {
    loop_ub = iidx->size[0];
    for (i1 = 0; i1 < loop_ub; i1++) {
      temp->data[(iidx->data[i1] + temp->size[0] * i0) - 1] = centers->data
        [(iidx->data[i1] + centers->size[0] * i0) - 1];
    }
  }

  emxFree_int32_T(&iidx);
  emxInit_boolean_T(sp, &b_resort, 1, &c_emlrtRTEI, true);
  i0 = b_resort->size[0];
  b_resort->size[0] = resort->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)b_resort, i0, (int32_T)sizeof
                    (boolean_T), &c_emlrtRTEI);
  loop_ub = resort->size[0];
  for (i0 = 0; i0 < loop_ub; i0++) {
    b_resort->data[i0] = (resort->data[i0] == 0.0);
  }

  emxInit_boolean_T(sp, &c_resort, 1, &c_emlrtRTEI, true);
  st.site = &g_emlrtRSI;
  eml_null_assignment(&st, temp, b_resort);
  i0 = c_resort->size[0];
  c_resort->size[0] = resort->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)c_resort, i0, (int32_T)sizeof
                    (boolean_T), &c_emlrtRTEI);
  loop_ub = resort->size[0];
  emxFree_boolean_T(&b_resort);
  for (i0 = 0; i0 < loop_ub; i0++) {
    c_resort->data[i0] = (resort->data[i0] == 1.0);
  }

  emxFree_real_T(&resort);
  emxInit_real_T(sp, &f_centers, 2, &c_emlrtRTEI, true);
  st.site = &f_emlrtRSI;
  eml_null_assignment(&st, centers, c_resort);
  i0 = f_centers->size[0] * f_centers->size[1];
  f_centers->size[0] = centers->size[0] + temp->size[0];
  f_centers->size[1] = 2;
  emxEnsureCapacity(sp, (emxArray__common *)f_centers, i0, (int32_T)sizeof
                    (real_T), &c_emlrtRTEI);
  emxFree_boolean_T(&c_resort);
  for (i0 = 0; i0 < 2; i0++) {
    loop_ub = centers->size[0];
    for (i1 = 0; i1 < loop_ub; i1++) {
      f_centers->data[i1 + f_centers->size[0] * i0] = centers->data[i1 +
        centers->size[0] * i0];
    }
  }

  for (i0 = 0; i0 < 2; i0++) {
    loop_ub = temp->size[0];
    for (i1 = 0; i1 < loop_ub; i1++) {
      f_centers->data[(i1 + centers->size[0]) + f_centers->size[0] * i0] =
        temp->data[i1 + temp->size[0] * i0];
    }
  }

  i0 = centers->size[0] * centers->size[1];
  centers->size[0] = f_centers->size[0];
  centers->size[1] = 2;
  emxEnsureCapacity(sp, (emxArray__common *)centers, i0, (int32_T)sizeof(real_T),
                    &c_emlrtRTEI);
  for (i0 = 0; i0 < 2; i0++) {
    loop_ub = f_centers->size[0];
    for (i1 = 0; i1 < loop_ub; i1++) {
      centers->data[i1 + centers->size[0] * i0] = f_centers->data[i1 +
        f_centers->size[0] * i0];
    }
  }

  emxFree_real_T(&f_centers);

  /*  x=1:size(im,2); */
  /*  figure; imshow(im); title(strcat('Detected circles of radius=', num2str(radius), ', accuracy=', num2str(acc))); hold on */
  /*  plot(x, staffs*ones(size(x))); hold on */
  ii = centers->size[0];
  i0 = temp->size[0] * temp->size[1];
  temp->size[0] = ii;
  temp->size[1] = 2;
  emxEnsureCapacity(sp, (emxArray__common *)temp, i0, (int32_T)sizeof(real_T),
                    &c_emlrtRTEI);
  loop_ub = centers->size[0] << 1;
  for (i0 = 0; i0 < loop_ub; i0++) {
    temp->data[i0] = 0.0;
  }

  i = 0;
  while (i <= centers->size[0] - 1) {
    /*     viscircles(centers(i,:), radius * ones(size(centers(i), 1), 1)); hold on */
    i0 = centers->size[0];
    i1 = i + 1;
    emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &e_emlrtBCI, sp);
    ii = temp->size[0];
    i0 = 1 + i;
    emlrtDynamicBoundsCheckR2012b(i0, 1, ii, &d_emlrtBCI, sp);
    for (i0 = 0; i0 < 2; i0++) {
      temp->data[i + temp->size[0] * i0] = 48.0;
    }

    i++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_real_T(&centers);
  for (i0 = 0; i0 < 2; i0++) {
    uv0[i0] = (uint32_T)temp->size[i0];
  }

  i0 = notes->size[0] * notes->size[1];
  notes->size[0] = (int32_T)uv0[0];
  notes->size[1] = 2;
  emxEnsureCapacity(sp, (emxArray__common *)notes, i0, (int32_T)sizeof(char_T),
                    &c_emlrtRTEI);
  loop_ub = (int32_T)uv0[0] << 1;
  for (i0 = 0; i0 < loop_ub; i0++) {
    notes->data[i0] = (int8_T)muDoubleScalarFloor(temp->data[i0]);
  }

  emxFree_real_T(&temp);

  /*  viscircles(centers, radius * ones(size(centers, 1), 1)); hold on */
  /*  plot(x, staffs*ones(size(x))); */
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (extract_notes.c) */
