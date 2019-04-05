/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * eml_sort.c
 *
 * Code generation for function 'eml_sort'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "extract_notes.h"
#include "eml_sort.h"
#include "eml_int_forloop_overflow_check.h"
#include "extract_notes_emxutil.h"
#include "extract_notes_data.h"
#include "libmwimfilter.h"
#include "libmwippfilter.h"

/* Variable Definitions */
static emlrtRSInfo ob_emlrtRSI = { 23, "eml_sort",
  "/Applications/MATLAB_R2015a.app/toolbox/eml/lib/matlab/eml/eml_sort.m" };

static emlrtRSInfo pb_emlrtRSI = { 66, "eml_sort",
  "/Applications/MATLAB_R2015a.app/toolbox/eml/lib/matlab/eml/eml_sort.m" };

static emlrtRSInfo qb_emlrtRSI = { 61, "eml_sort_idx",
  "/Applications/MATLAB_R2015a.app/toolbox/eml/lib/matlab/eml/eml_sort_idx.m" };

static emlrtRSInfo rb_emlrtRSI = { 303, "eml_sort_idx",
  "/Applications/MATLAB_R2015a.app/toolbox/eml/lib/matlab/eml/eml_sort_idx.m" };

static emlrtRSInfo sb_emlrtRSI = { 311, "eml_sort_idx",
  "/Applications/MATLAB_R2015a.app/toolbox/eml/lib/matlab/eml/eml_sort_idx.m" };

static emlrtRSInfo tb_emlrtRSI = { 312, "eml_sort_idx",
  "/Applications/MATLAB_R2015a.app/toolbox/eml/lib/matlab/eml/eml_sort_idx.m" };

static emlrtRSInfo ub_emlrtRSI = { 320, "eml_sort_idx",
  "/Applications/MATLAB_R2015a.app/toolbox/eml/lib/matlab/eml/eml_sort_idx.m" };

static emlrtRSInfo vb_emlrtRSI = { 327, "eml_sort_idx",
  "/Applications/MATLAB_R2015a.app/toolbox/eml/lib/matlab/eml/eml_sort_idx.m" };

static emlrtRSInfo wb_emlrtRSI = { 331, "eml_sort_idx",
  "/Applications/MATLAB_R2015a.app/toolbox/eml/lib/matlab/eml/eml_sort_idx.m" };

static emlrtRSInfo xb_emlrtRSI = { 406, "eml_sort_idx",
  "/Applications/MATLAB_R2015a.app/toolbox/eml/lib/matlab/eml/eml_sort_idx.m" };

static emlrtRSInfo yb_emlrtRSI = { 413, "eml_sort_idx",
  "/Applications/MATLAB_R2015a.app/toolbox/eml/lib/matlab/eml/eml_sort_idx.m" };

static emlrtRSInfo ac_emlrtRSI = { 569, "eml_sort_idx",
  "/Applications/MATLAB_R2015a.app/toolbox/eml/lib/matlab/eml/eml_sort_idx.m" };

static emlrtRSInfo bc_emlrtRSI = { 571, "eml_sort_idx",
  "/Applications/MATLAB_R2015a.app/toolbox/eml/lib/matlab/eml/eml_sort_idx.m" };

static emlrtRSInfo cc_emlrtRSI = { 599, "eml_sort_idx",
  "/Applications/MATLAB_R2015a.app/toolbox/eml/lib/matlab/eml/eml_sort_idx.m" };

static emlrtRSInfo dc_emlrtRSI = { 484, "eml_sort_idx",
  "/Applications/MATLAB_R2015a.app/toolbox/eml/lib/matlab/eml/eml_sort_idx.m" };

static emlrtRSInfo fc_emlrtRSI = { 492, "eml_sort_idx",
  "/Applications/MATLAB_R2015a.app/toolbox/eml/lib/matlab/eml/eml_sort_idx.m" };

static emlrtRSInfo gc_emlrtRSI = { 498, "eml_sort_idx",
  "/Applications/MATLAB_R2015a.app/toolbox/eml/lib/matlab/eml/eml_sort_idx.m" };

static emlrtRSInfo hc_emlrtRSI = { 545, "eml_sort_idx",
  "/Applications/MATLAB_R2015a.app/toolbox/eml/lib/matlab/eml/eml_sort_idx.m" };

static emlrtRSInfo ic_emlrtRSI = { 514, "eml_sort_idx",
  "/Applications/MATLAB_R2015a.app/toolbox/eml/lib/matlab/eml/eml_sort_idx.m" };

static emlrtRSInfo jc_emlrtRSI = { 345, "eml_sort_idx",
  "/Applications/MATLAB_R2015a.app/toolbox/eml/lib/matlab/eml/eml_sort_idx.m" };

static emlrtRSInfo kc_emlrtRSI = { 354, "eml_sort_idx",
  "/Applications/MATLAB_R2015a.app/toolbox/eml/lib/matlab/eml/eml_sort_idx.m" };

static emlrtRSInfo mc_emlrtRSI = { 48, "eml_sort",
  "/Applications/MATLAB_R2015a.app/toolbox/eml/lib/matlab/eml/eml_sort.m" };

static emlrtRSInfo nc_emlrtRSI = { 69, "eml_sort",
  "/Applications/MATLAB_R2015a.app/toolbox/eml/lib/matlab/eml/eml_sort.m" };

static emlrtRSInfo oc_emlrtRSI = { 72, "eml_sort",
  "/Applications/MATLAB_R2015a.app/toolbox/eml/lib/matlab/eml/eml_sort.m" };

static emlrtRSInfo pc_emlrtRSI = { 74, "eml_sort",
  "/Applications/MATLAB_R2015a.app/toolbox/eml/lib/matlab/eml/eml_sort.m" };

static emlrtRSInfo qc_emlrtRSI = { 77, "eml_sort",
  "/Applications/MATLAB_R2015a.app/toolbox/eml/lib/matlab/eml/eml_sort.m" };

static emlrtRSInfo rc_emlrtRSI = { 80, "eml_sort",
  "/Applications/MATLAB_R2015a.app/toolbox/eml/lib/matlab/eml/eml_sort.m" };

static emlrtRSInfo sc_emlrtRSI = { 82, "eml_sort",
  "/Applications/MATLAB_R2015a.app/toolbox/eml/lib/matlab/eml/eml_sort.m" };

static emlrtRSInfo vc_emlrtRSI = { 378, "eml_sort_idx",
  "/Applications/MATLAB_R2015a.app/toolbox/eml/lib/matlab/eml/eml_sort_idx.m" };

static emlrtRTEInfo t_emlrtRTEI = { 1, 20, "eml_sort",
  "/Applications/MATLAB_R2015a.app/toolbox/eml/lib/matlab/eml/eml_sort.m" };

static emlrtRTEInfo u_emlrtRTEI = { 1, 20, "eml_sort_idx",
  "/Applications/MATLAB_R2015a.app/toolbox/eml/lib/matlab/eml/eml_sort_idx.m" };

static emlrtRTEInfo y_emlrtRTEI = { 50, 1, "eml_sort",
  "/Applications/MATLAB_R2015a.app/toolbox/eml/lib/matlab/eml/eml_sort.m" };

static emlrtRTEInfo ab_emlrtRTEI = { 374, 9, "eml_sort_idx",
  "/Applications/MATLAB_R2015a.app/toolbox/eml/lib/matlab/eml/eml_sort_idx.m" };

static emlrtRTEInfo bb_emlrtRTEI = { 374, 1, "eml_sort_idx",
  "/Applications/MATLAB_R2015a.app/toolbox/eml/lib/matlab/eml/eml_sort_idx.m" };

static emlrtRTEInfo cb_emlrtRTEI = { 508, 9, "eml_sort_idx",
  "/Applications/MATLAB_R2015a.app/toolbox/eml/lib/matlab/eml/eml_sort_idx.m" };

static emlrtRTEInfo db_emlrtRTEI = { 509, 9, "eml_sort_idx",
  "/Applications/MATLAB_R2015a.app/toolbox/eml/lib/matlab/eml/eml_sort_idx.m" };

static emlrtRTEInfo eb_emlrtRTEI = { 508, 1, "eml_sort_idx",
  "/Applications/MATLAB_R2015a.app/toolbox/eml/lib/matlab/eml/eml_sort_idx.m" };

static emlrtRTEInfo fb_emlrtRTEI = { 509, 1, "eml_sort_idx",
  "/Applications/MATLAB_R2015a.app/toolbox/eml/lib/matlab/eml/eml_sort_idx.m" };

/* Function Declarations */
static void b_eml_sort(extract_notesStackData *SD, const emlrtStack *sp, real_T
  x[164592]);
static void b_merge(const emlrtStack *sp, emxArray_int32_T *idx, emxArray_real_T
                    *x, int32_T offset, int32_T np, int32_T nq);
static void b_merge_block(const emlrtStack *sp, emxArray_int32_T *idx,
  emxArray_real_T *x, int32_T offset, int32_T n, int32_T preSortLevel);
static void eml_sort_idx(const emlrtStack *sp, emxArray_real_T *x,
  emxArray_int32_T *idx);
static void merge(extract_notesStackData *SD, const emlrtStack *sp, int32_T idx
                  [164592], real_T x[164592], int32_T offset, int32_T np,
                  int32_T nq);
static void merge_block(extract_notesStackData *SD, const emlrtStack *sp,
  int32_T idx[164592], real_T x[164592], int32_T offset, int32_T n, int32_T
  preSortLevel);
static void merge_pow2_block(int32_T idx[164592], real_T x[164592], int32_T
  offset);

/* Function Definitions */
static void b_eml_sort(extract_notesStackData *SD, const emlrtStack *sp, real_T
  x[164592])
{
  real_T x4[4];
  int32_T idx4[4];
  int32_T m;
  int32_T nNaNs;
  int32_T ib;
  int32_T k;
  int32_T nBlocks;
  int32_T i3;
  int32_T i4;
  int8_T perm[4];
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &pb_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  b_st.site = &qb_emlrtRSI;
  c_st.site = &rb_emlrtRSI;
  memset(&SD->u2.f3.idx[0], 0, 164592U * sizeof(int32_T));
  for (m = 0; m < 4; m++) {
    x4[m] = 0.0;
    idx4[m] = 0;
  }

  nNaNs = 0;
  ib = 0;
  for (k = 0; k < 164592; k++) {
    if (muDoubleScalarIsNaN(x[k])) {
      SD->u2.f3.idx[164591 - nNaNs] = k + 1;
      SD->u2.f3.xwork[164591 - nNaNs] = x[k];
      nNaNs++;
    } else {
      ib++;
      idx4[ib - 1] = k + 1;
      x4[ib - 1] = x[k];
      if (ib == 4) {
        ib = k - nNaNs;
        if (x4[0] >= x4[1]) {
          m = 1;
          nBlocks = 2;
        } else {
          m = 2;
          nBlocks = 1;
        }

        if (x4[2] >= x4[3]) {
          i3 = 3;
          i4 = 4;
        } else {
          i3 = 4;
          i4 = 3;
        }

        if (x4[m - 1] >= x4[i3 - 1]) {
          if (x4[nBlocks - 1] >= x4[i3 - 1]) {
            perm[0] = (int8_T)m;
            perm[1] = (int8_T)nBlocks;
            perm[2] = (int8_T)i3;
            perm[3] = (int8_T)i4;
          } else if (x4[nBlocks - 1] >= x4[i4 - 1]) {
            perm[0] = (int8_T)m;
            perm[1] = (int8_T)i3;
            perm[2] = (int8_T)nBlocks;
            perm[3] = (int8_T)i4;
          } else {
            perm[0] = (int8_T)m;
            perm[1] = (int8_T)i3;
            perm[2] = (int8_T)i4;
            perm[3] = (int8_T)nBlocks;
          }
        } else if (x4[m - 1] >= x4[i4 - 1]) {
          if (x4[nBlocks - 1] >= x4[i4 - 1]) {
            perm[0] = (int8_T)i3;
            perm[1] = (int8_T)m;
            perm[2] = (int8_T)nBlocks;
            perm[3] = (int8_T)i4;
          } else {
            perm[0] = (int8_T)i3;
            perm[1] = (int8_T)m;
            perm[2] = (int8_T)i4;
            perm[3] = (int8_T)nBlocks;
          }
        } else {
          perm[0] = (int8_T)i3;
          perm[1] = (int8_T)i4;
          perm[2] = (int8_T)m;
          perm[3] = (int8_T)nBlocks;
        }

        SD->u2.f3.idx[ib - 3] = idx4[perm[0] - 1];
        SD->u2.f3.idx[ib - 2] = idx4[perm[1] - 1];
        SD->u2.f3.idx[ib - 1] = idx4[perm[2] - 1];
        SD->u2.f3.idx[ib] = idx4[perm[3] - 1];
        x[ib - 3] = x4[perm[0] - 1];
        x[ib - 2] = x4[perm[1] - 1];
        x[ib - 1] = x4[perm[2] - 1];
        x[ib] = x4[perm[3] - 1];
        ib = 0;
      }
    }
  }

  if (ib > 0) {
    for (m = 0; m < 4; m++) {
      perm[m] = 0;
    }

    if (ib == 1) {
      perm[0] = 1;
    } else if (ib == 2) {
      if (x4[0] >= x4[1]) {
        perm[0] = 1;
        perm[1] = 2;
      } else {
        perm[0] = 2;
        perm[1] = 1;
      }
    } else if (x4[0] >= x4[1]) {
      if (x4[1] >= x4[2]) {
        perm[0] = 1;
        perm[1] = 2;
        perm[2] = 3;
      } else if (x4[0] >= x4[2]) {
        perm[0] = 1;
        perm[1] = 3;
        perm[2] = 2;
      } else {
        perm[0] = 3;
        perm[1] = 1;
        perm[2] = 2;
      }
    } else if (x4[0] >= x4[2]) {
      perm[0] = 2;
      perm[1] = 1;
      perm[2] = 3;
    } else if (x4[1] >= x4[2]) {
      perm[0] = 2;
      perm[1] = 3;
      perm[2] = 1;
    } else {
      perm[0] = 3;
      perm[1] = 2;
      perm[2] = 1;
    }

    d_st.site = &xb_emlrtRSI;
    if (ib > 2147483646) {
      e_st.site = &bb_emlrtRSI;
      check_forloop_overflow_error(&e_st);
    }

    for (k = 164592; k - 164591 <= ib; k++) {
      SD->u2.f3.idx[(k - nNaNs) - ib] = idx4[perm[k - 164592] - 1];
      x[(k - nNaNs) - ib] = x4[perm[k - 164592] - 1];
    }
  }

  if (nNaNs >= 0) {
    m = (int32_T)((uint32_T)nNaNs >> 1);
  } else {
    m = (int32_T)~(~(uint32_T)nNaNs >> 1);
  }

  d_st.site = &yb_emlrtRSI;
  for (k = 1; k <= m; k++) {
    ib = SD->u2.f3.idx[(k - nNaNs) + 164591];
    SD->u2.f3.idx[(k - nNaNs) + 164591] = SD->u2.f3.idx[164592 - k];
    SD->u2.f3.idx[164592 - k] = ib;
    x[(k - nNaNs) + 164591] = SD->u2.f3.xwork[164592 - k];
    x[164592 - k] = SD->u2.f3.xwork[(k - nNaNs) + 164591];
  }

  if ((nNaNs & 1) != 0) {
    x[(m - nNaNs) + 164592] = SD->u2.f3.xwork[(m - nNaNs) + 164592];
  }

  ib = 2;
  if (164592 - nNaNs > 1) {
    m = 164592 - nNaNs;
    if (m >= 0) {
      nBlocks = (int32_T)((uint32_T)m >> 8);
    } else {
      nBlocks = (int32_T)~(~(uint32_T)m >> 8);
    }

    if (nBlocks > 0) {
      c_st.site = &sb_emlrtRSI;
      for (m = 1; m <= nBlocks; m++) {
        c_st.site = &tb_emlrtRSI;
        merge_pow2_block(SD->u2.f3.idx, x, (m - 1) << 8);
      }

      m = nBlocks << 8;
      ib = 164592 - (nNaNs + m);
      if (ib > 0) {
        c_st.site = &ub_emlrtRSI;
        merge_block(SD, &c_st, SD->u2.f3.idx, x, m, ib, 2);
      }

      ib = 8;
    }

    c_st.site = &vb_emlrtRSI;
    merge_block(SD, &c_st, SD->u2.f3.idx, x, 0, 164592 - nNaNs, ib);
  }

  if ((nNaNs > 0) && (164592 - nNaNs > 0)) {
    c_st.site = &wb_emlrtRSI;
    d_st.site = &jc_emlrtRSI;
    if (nNaNs > 2147483646) {
      e_st.site = &bb_emlrtRSI;
      check_forloop_overflow_error(&e_st);
    }

    for (k = 1; k <= nNaNs; k++) {
      SD->u2.f3.xwork[k - 1] = x[(k - nNaNs) + 164591];
    }

    for (k = 164591 - nNaNs; k + 1 > 0; k--) {
      x[nNaNs + k] = x[k];
    }

    d_st.site = &kc_emlrtRSI;
    for (k = 0; k + 1 <= nNaNs; k++) {
      x[k] = SD->u2.f3.xwork[k];
    }
  }
}

static void b_merge(const emlrtStack *sp, emxArray_int32_T *idx, emxArray_real_T
                    *x, int32_T offset, int32_T np, int32_T nq)
{
  emxArray_int32_T *iwork;
  emxArray_real_T *xwork;
  int32_T n;
  int32_T qend;
  boolean_T b3;
  int32_T p;
  int32_T iout;
  int32_T exitg1;
  boolean_T b_p;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_int32_T(sp, &iwork, 1, &eb_emlrtRTEI, true);
  b_emxInit_real_T(sp, &xwork, 1, &fb_emlrtRTEI, true);
  n = iwork->size[0];
  iwork->size[0] = idx->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)iwork, n, (int32_T)sizeof(int32_T),
                    &cb_emlrtRTEI);
  qend = x->size[0];
  n = xwork->size[0];
  xwork->size[0] = qend;
  emxEnsureCapacity(sp, (emxArray__common *)xwork, n, (int32_T)sizeof(real_T),
                    &db_emlrtRTEI);
  if (nq == 0) {
  } else {
    n = np + nq;
    st.site = &ic_emlrtRSI;
    if (1 > n) {
      b3 = false;
    } else {
      b3 = (n > 2147483646);
    }

    if (b3) {
      b_st.site = &bb_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }

    for (qend = 0; qend + 1 <= n; qend++) {
      iwork->data[qend] = idx->data[offset + qend];
      xwork->data[qend] = x->data[offset + qend];
    }

    p = 0;
    n = np;
    qend = np + nq;
    iout = offset - 1;
    do {
      exitg1 = 0;
      iout++;
      if (xwork->data[p] <= xwork->data[n]) {
        idx->data[iout] = iwork->data[p];
        x->data[iout] = xwork->data[p];
        if (p + 1 < np) {
          p++;
        } else {
          exitg1 = 1;
        }
      } else {
        idx->data[iout] = iwork->data[n];
        x->data[iout] = xwork->data[n];
        if (n + 1 < qend) {
          n++;
        } else {
          n = (iout - p) + 1;
          st.site = &hc_emlrtRSI;
          if (p + 1 > np) {
            b_p = false;
          } else {
            b_p = (np > 2147483646);
          }

          if (b_p) {
            b_st.site = &bb_emlrtRSI;
            check_forloop_overflow_error(&b_st);
          }

          while (p + 1 <= np) {
            idx->data[n + p] = iwork->data[p];
            x->data[n + p] = xwork->data[p];
            p++;
          }

          exitg1 = 1;
        }
      }
    } while (exitg1 == 0);
  }

  emxFree_real_T(&xwork);
  emxFree_int32_T(&iwork);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

static void b_merge_block(const emlrtStack *sp, emxArray_int32_T *idx,
  emxArray_real_T *x, int32_T offset, int32_T n, int32_T preSortLevel)
{
  int32_T nPairs;
  int32_T bLen;
  int32_T tailOffset;
  int32_T nTail;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  if (n >= 0) {
    nPairs = (int32_T)((uint32_T)n >> preSortLevel);
  } else {
    nPairs = (int32_T)~(~(uint32_T)n >> preSortLevel);
  }

  bLen = 1 << preSortLevel;
  while (nPairs > 1) {
    if ((nPairs & 1) != 0) {
      nPairs--;
      tailOffset = bLen * nPairs;
      nTail = n - tailOffset;
      if (nTail > bLen) {
        st.site = &dc_emlrtRSI;
        b_merge(&st, idx, x, offset + tailOffset, bLen, nTail - bLen);
      }
    }

    tailOffset = bLen << 1;
    nPairs = (int32_T)((uint32_T)nPairs >> 1);
    for (nTail = 1; nTail <= nPairs; nTail++) {
      st.site = &fc_emlrtRSI;
      b_merge(&st, idx, x, offset + (nTail - 1) * tailOffset, bLen, bLen);
    }

    bLen = tailOffset;
  }

  if (n > bLen) {
    st.site = &gc_emlrtRSI;
    b_merge(&st, idx, x, offset, bLen, n - bLen);
  }
}

static void eml_sort_idx(const emlrtStack *sp, emxArray_real_T *x,
  emxArray_int32_T *idx)
{
  emxArray_real_T *b_x;
  int32_T ib;
  int32_T wOffset;
  int32_T m;
  int32_T n;
  real_T x4[4];
  int32_T idx4[4];
  emxArray_real_T *xwork;
  int32_T nNaNs;
  boolean_T overflow;
  int32_T k;
  int32_T p;
  int32_T nPairs;
  int8_T perm[4];
  int32_T b_nNaNs;
  int32_T nNonNaN;
  int32_T nBlocks;
  int32_T iwork[256];
  real_T b_xwork[256];
  int32_T b;
  int32_T bLen;
  int32_T bLen2;
  int32_T exitg1;
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
  b_emxInit_real_T(sp, &b_x, 1, &u_emlrtRTEI, true);
  ib = x->size[0];
  st.site = &qb_emlrtRSI;
  b_st.site = &rb_emlrtRSI;
  wOffset = b_x->size[0];
  b_x->size[0] = x->size[0];
  emxEnsureCapacity(&b_st, (emxArray__common *)b_x, wOffset, (int32_T)sizeof
                    (real_T), &u_emlrtRTEI);
  m = x->size[0];
  for (wOffset = 0; wOffset < m; wOffset++) {
    b_x->data[wOffset] = x->data[wOffset];
  }

  wOffset = idx->size[0];
  idx->size[0] = ib;
  emxEnsureCapacity(&b_st, (emxArray__common *)idx, wOffset, (int32_T)sizeof
                    (int32_T), &u_emlrtRTEI);
  for (wOffset = 0; wOffset < ib; wOffset++) {
    idx->data[wOffset] = 0;
  }

  n = x->size[0];
  for (m = 0; m < 4; m++) {
    x4[m] = 0.0;
    idx4[m] = 0;
  }

  b_emxInit_real_T(&b_st, &xwork, 1, &bb_emlrtRTEI, true);
  ib = x->size[0];
  wOffset = xwork->size[0];
  xwork->size[0] = ib;
  emxEnsureCapacity(&b_st, (emxArray__common *)xwork, wOffset, (int32_T)sizeof
                    (real_T), &ab_emlrtRTEI);
  nNaNs = 0;
  ib = 0;
  c_st.site = &vc_emlrtRSI;
  if (1 > x->size[0]) {
    overflow = false;
  } else {
    overflow = (x->size[0] > 2147483646);
  }

  if (overflow) {
    d_st.site = &bb_emlrtRSI;
    check_forloop_overflow_error(&d_st);
  }

  for (k = 0; k + 1 <= n; k++) {
    if (muDoubleScalarIsNaN(b_x->data[k])) {
      idx->data[(n - nNaNs) - 1] = k + 1;
      xwork->data[(n - nNaNs) - 1] = b_x->data[k];
      nNaNs++;
    } else {
      ib++;
      idx4[ib - 1] = k + 1;
      x4[ib - 1] = b_x->data[k];
      if (ib == 4) {
        ib = k - nNaNs;
        if (x4[0] <= x4[1]) {
          m = 1;
          wOffset = 2;
        } else {
          m = 2;
          wOffset = 1;
        }

        if (x4[2] <= x4[3]) {
          p = 3;
          nPairs = 4;
        } else {
          p = 4;
          nPairs = 3;
        }

        if (x4[m - 1] <= x4[p - 1]) {
          if (x4[wOffset - 1] <= x4[p - 1]) {
            perm[0] = (int8_T)m;
            perm[1] = (int8_T)wOffset;
            perm[2] = (int8_T)p;
            perm[3] = (int8_T)nPairs;
          } else if (x4[wOffset - 1] <= x4[nPairs - 1]) {
            perm[0] = (int8_T)m;
            perm[1] = (int8_T)p;
            perm[2] = (int8_T)wOffset;
            perm[3] = (int8_T)nPairs;
          } else {
            perm[0] = (int8_T)m;
            perm[1] = (int8_T)p;
            perm[2] = (int8_T)nPairs;
            perm[3] = (int8_T)wOffset;
          }
        } else if (x4[m - 1] <= x4[nPairs - 1]) {
          if (x4[wOffset - 1] <= x4[nPairs - 1]) {
            perm[0] = (int8_T)p;
            perm[1] = (int8_T)m;
            perm[2] = (int8_T)wOffset;
            perm[3] = (int8_T)nPairs;
          } else {
            perm[0] = (int8_T)p;
            perm[1] = (int8_T)m;
            perm[2] = (int8_T)nPairs;
            perm[3] = (int8_T)wOffset;
          }
        } else {
          perm[0] = (int8_T)p;
          perm[1] = (int8_T)nPairs;
          perm[2] = (int8_T)m;
          perm[3] = (int8_T)wOffset;
        }

        idx->data[ib - 3] = idx4[perm[0] - 1];
        idx->data[ib - 2] = idx4[perm[1] - 1];
        idx->data[ib - 1] = idx4[perm[2] - 1];
        idx->data[ib] = idx4[perm[3] - 1];
        b_x->data[ib - 3] = x4[perm[0] - 1];
        b_x->data[ib - 2] = x4[perm[1] - 1];
        b_x->data[ib - 1] = x4[perm[2] - 1];
        b_x->data[ib] = x4[perm[3] - 1];
        ib = 0;
      }
    }
  }

  wOffset = (x->size[0] - nNaNs) - 1;
  if (ib > 0) {
    for (m = 0; m < 4; m++) {
      perm[m] = 0;
    }

    if (ib == 1) {
      perm[0] = 1;
    } else if (ib == 2) {
      if (x4[0] <= x4[1]) {
        perm[0] = 1;
        perm[1] = 2;
      } else {
        perm[0] = 2;
        perm[1] = 1;
      }
    } else if (x4[0] <= x4[1]) {
      if (x4[1] <= x4[2]) {
        perm[0] = 1;
        perm[1] = 2;
        perm[2] = 3;
      } else if (x4[0] <= x4[2]) {
        perm[0] = 1;
        perm[1] = 3;
        perm[2] = 2;
      } else {
        perm[0] = 3;
        perm[1] = 1;
        perm[2] = 2;
      }
    } else if (x4[0] <= x4[2]) {
      perm[0] = 2;
      perm[1] = 1;
      perm[2] = 3;
    } else if (x4[1] <= x4[2]) {
      perm[0] = 2;
      perm[1] = 3;
      perm[2] = 1;
    } else {
      perm[0] = 3;
      perm[1] = 2;
      perm[2] = 1;
    }

    c_st.site = &xb_emlrtRSI;
    if (ib > 2147483646) {
      d_st.site = &bb_emlrtRSI;
      check_forloop_overflow_error(&d_st);
    }

    for (k = 1; k <= ib; k++) {
      idx->data[(wOffset - ib) + k] = idx4[perm[k - 1] - 1];
      b_x->data[(wOffset - ib) + k] = x4[perm[k - 1] - 1];
    }
  }

  if (nNaNs >= 0) {
    b_nNaNs = (int32_T)((uint32_T)nNaNs >> 1);
  } else {
    b_nNaNs = (int32_T)~(~(uint32_T)nNaNs >> 1);
  }

  m = b_nNaNs + 1;
  c_st.site = &yb_emlrtRSI;
  for (k = 1; k < m; k++) {
    ib = idx->data[wOffset + k];
    idx->data[wOffset + k] = idx->data[n - k];
    idx->data[n - k] = ib;
    b_x->data[wOffset + k] = xwork->data[n - k];
    b_x->data[n - k] = xwork->data[wOffset + k];
  }

  if ((nNaNs & 1) != 0) {
    b_x->data[wOffset + m] = xwork->data[wOffset + m];
  }

  emxFree_real_T(&xwork);
  nNonNaN = x->size[0] - nNaNs;
  m = 2;
  if (nNonNaN > 1) {
    if (x->size[0] >= 256) {
      nBlocks = (int32_T)((uint32_T)nNonNaN >> 8);
      if (nBlocks > 0) {
        b_st.site = &sb_emlrtRSI;
        for (nNaNs = 1; nNaNs <= nBlocks; nNaNs++) {
          b_st.site = &tb_emlrtRSI;
          n = (nNaNs - 1) << 8;
          for (b = 0; b < 6; b++) {
            bLen = 1 << (b + 2);
            bLen2 = bLen << 1;
            wOffset = b + 3;
            nPairs = (int32_T)(256U >> wOffset);
            c_st.site = &ac_emlrtRSI;
            for (k = 1; k <= nPairs; k++) {
              m = n + (k - 1) * bLen2;
              c_st.site = &bc_emlrtRSI;
              for (ib = 0; ib + 1 <= bLen2; ib++) {
                iwork[ib] = idx->data[m + ib];
                b_xwork[ib] = b_x->data[m + ib];
              }

              p = 0;
              wOffset = bLen;
              ib = m - 1;
              do {
                exitg1 = 0;
                ib++;
                if (b_xwork[p] <= b_xwork[wOffset]) {
                  idx->data[ib] = iwork[p];
                  b_x->data[ib] = b_xwork[p];
                  if (p + 1 < bLen) {
                    p++;
                  } else {
                    exitg1 = 1;
                  }
                } else {
                  idx->data[ib] = iwork[wOffset];
                  b_x->data[ib] = b_xwork[wOffset];
                  if (wOffset + 1 < bLen2) {
                    wOffset++;
                  } else {
                    ib = (ib - p) + 1;
                    c_st.site = &cc_emlrtRSI;
                    while (p + 1 <= bLen) {
                      idx->data[ib + p] = iwork[p];
                      b_x->data[ib + p] = b_xwork[p];
                      p++;
                    }

                    exitg1 = 1;
                  }
                }
              } while (exitg1 == 0);
            }
          }
        }

        m = nBlocks << 8;
        ib = nNonNaN - m;
        if (ib > 0) {
          b_st.site = &ub_emlrtRSI;
          b_merge_block(&b_st, idx, b_x, m, ib, 2);
        }

        m = 8;
      }
    }

    b_st.site = &vb_emlrtRSI;
    b_merge_block(&b_st, idx, b_x, 0, nNonNaN, m);
  }

  wOffset = x->size[0];
  x->size[0] = b_x->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)x, wOffset, (int32_T)sizeof(real_T),
                    &u_emlrtRTEI);
  m = b_x->size[0];
  for (wOffset = 0; wOffset < m; wOffset++) {
    x->data[wOffset] = b_x->data[wOffset];
  }

  emxFree_real_T(&b_x);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

static void merge(extract_notesStackData *SD, const emlrtStack *sp, int32_T idx
                  [164592], real_T x[164592], int32_T offset, int32_T np,
                  int32_T nq)
{
  int32_T n;
  boolean_T b0;
  int32_T qend;
  int32_T p;
  int32_T iout;
  int32_T exitg1;
  boolean_T b_p;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  if (nq == 0) {
  } else {
    n = np + nq;
    st.site = &ic_emlrtRSI;
    if (1 > n) {
      b0 = false;
    } else {
      b0 = (n > 2147483646);
    }

    if (b0) {
      b_st.site = &bb_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }

    for (qend = 0; qend + 1 <= n; qend++) {
      SD->u1.f0.iwork[qend] = idx[offset + qend];
      SD->u1.f0.xwork[qend] = x[offset + qend];
    }

    p = 0;
    n = np;
    qend = np + nq;
    iout = offset - 1;
    do {
      exitg1 = 0;
      iout++;
      if (SD->u1.f0.xwork[p] >= SD->u1.f0.xwork[n]) {
        idx[iout] = SD->u1.f0.iwork[p];
        x[iout] = SD->u1.f0.xwork[p];
        if (p + 1 < np) {
          p++;
        } else {
          exitg1 = 1;
        }
      } else {
        idx[iout] = SD->u1.f0.iwork[n];
        x[iout] = SD->u1.f0.xwork[n];
        if (n + 1 < qend) {
          n++;
        } else {
          n = (iout - p) + 1;
          st.site = &hc_emlrtRSI;
          if (p + 1 > np) {
            b_p = false;
          } else {
            b_p = (np > 2147483646);
          }

          if (b_p) {
            b_st.site = &bb_emlrtRSI;
            check_forloop_overflow_error(&b_st);
          }

          while (p + 1 <= np) {
            idx[n + p] = SD->u1.f0.iwork[p];
            x[n + p] = SD->u1.f0.xwork[p];
            p++;
          }

          exitg1 = 1;
        }
      }
    } while (exitg1 == 0);
  }
}

static void merge_block(extract_notesStackData *SD, const emlrtStack *sp,
  int32_T idx[164592], real_T x[164592], int32_T offset, int32_T n, int32_T
  preSortLevel)
{
  int32_T nPairs;
  int32_T bLen;
  int32_T tailOffset;
  int32_T nTail;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  if (n >= 0) {
    nPairs = (int32_T)((uint32_T)n >> preSortLevel);
  } else {
    nPairs = (int32_T)~(~(uint32_T)n >> preSortLevel);
  }

  bLen = 1 << preSortLevel;
  while (nPairs > 1) {
    if ((nPairs & 1) != 0) {
      nPairs--;
      tailOffset = bLen * nPairs;
      nTail = n - tailOffset;
      if (nTail > bLen) {
        st.site = &dc_emlrtRSI;
        merge(SD, &st, idx, x, offset + tailOffset, bLen, nTail - bLen);
      }
    }

    tailOffset = bLen << 1;
    nPairs = (int32_T)((uint32_T)nPairs >> 1);
    for (nTail = 1; nTail <= nPairs; nTail++) {
      st.site = &fc_emlrtRSI;
      merge(SD, &st, idx, x, offset + (nTail - 1) * tailOffset, bLen, bLen);
    }

    bLen = tailOffset;
  }

  if (n > bLen) {
    st.site = &gc_emlrtRSI;
    merge(SD, &st, idx, x, offset, bLen, n - bLen);
  }
}

static void merge_pow2_block(int32_T idx[164592], real_T x[164592], int32_T
  offset)
{
  int32_T iwork[256];
  real_T xwork[256];
  int32_T b;
  int32_T bLen;
  int32_T bLen2;
  int32_T iout;
  int32_T nPairs;
  int32_T k;
  int32_T blockOffset;
  int32_T p;
  int32_T q;
  int32_T exitg1;
  for (b = 0; b < 6; b++) {
    bLen = 1 << (b + 2);
    bLen2 = bLen << 1;
    iout = b + 3;
    nPairs = (int32_T)(256U >> iout);
    for (k = 1; k <= nPairs; k++) {
      blockOffset = offset + (k - 1) * bLen2;
      for (iout = 0; iout + 1 <= bLen2; iout++) {
        iwork[iout] = idx[blockOffset + iout];
        xwork[iout] = x[blockOffset + iout];
      }

      p = 0;
      q = bLen;
      iout = blockOffset - 1;
      do {
        exitg1 = 0;
        iout++;
        if (xwork[p] >= xwork[q]) {
          idx[iout] = iwork[p];
          x[iout] = xwork[p];
          if (p + 1 < bLen) {
            p++;
          } else {
            exitg1 = 1;
          }
        } else {
          idx[iout] = iwork[q];
          x[iout] = xwork[q];
          if (q + 1 < bLen2) {
            q++;
          } else {
            iout = (iout - p) + 1;
            while (p + 1 <= bLen) {
              idx[iout + p] = iwork[p];
              x[iout + p] = xwork[p];
              p++;
            }

            exitg1 = 1;
          }
        }
      } while (exitg1 == 0);
    }
  }
}

void c_eml_sort(const emlrtStack *sp, emxArray_real_T *x, emxArray_int32_T *idx)
{
  int32_T dim;
  int32_T i35;
  emxArray_real_T *vwork;
  int32_T j;
  int32_T vstride;
  int32_T k;
  boolean_T b1;
  emxArray_int32_T *iidx;
  boolean_T b2;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  dim = 2;
  if (x->size[0] != 1) {
    dim = 1;
  }

  st.site = &mc_emlrtRSI;
  if (dim <= 1) {
    i35 = x->size[0];
  } else {
    i35 = 1;
  }

  b_emxInit_real_T(sp, &vwork, 1, &y_emlrtRTEI, true);
  j = vwork->size[0];
  vwork->size[0] = i35;
  emxEnsureCapacity(sp, (emxArray__common *)vwork, j, (int32_T)sizeof(real_T),
                    &t_emlrtRTEI);
  vstride = x->size[0];
  j = idx->size[0];
  idx->size[0] = vstride;
  emxEnsureCapacity(sp, (emxArray__common *)idx, j, (int32_T)sizeof(int32_T),
                    &t_emlrtRTEI);
  st.site = &nc_emlrtRSI;
  vstride = 1;
  k = 1;
  while (k <= dim - 1) {
    vstride *= x->size[0];
    k = 2;
  }

  st.site = &oc_emlrtRSI;
  st.site = &pc_emlrtRSI;
  if (1 > vstride) {
    b1 = false;
  } else {
    b1 = (vstride > 2147483646);
  }

  if (b1) {
    b_st.site = &bb_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }

  j = 0;
  emxInit_int32_T(sp, &iidx, 1, &t_emlrtRTEI, true);
  while (j + 1 <= vstride) {
    st.site = &qc_emlrtRSI;
    if (1 > i35) {
      b2 = false;
    } else {
      b2 = (i35 > 2147483646);
    }

    if (b2) {
      b_st.site = &bb_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }

    for (k = 0; k + 1 <= i35; k++) {
      vwork->data[k] = x->data[j + k * vstride];
    }

    st.site = &rc_emlrtRSI;
    eml_sort_idx(&st, vwork, iidx);
    st.site = &sc_emlrtRSI;
    for (k = 0; k + 1 <= i35; k++) {
      x->data[j + k * vstride] = vwork->data[k];
      idx->data[j + k * vstride] = iidx->data[k];
    }

    j++;
  }

  emxFree_int32_T(&iidx);
  emxFree_real_T(&vwork);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

void eml_sort(extract_notesStackData *SD, const emlrtStack *sp, real_T x[164592])
{
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &ob_emlrtRSI;
  b_eml_sort(SD, &st, x);
}

/* End of code generation (eml_sort.c) */
