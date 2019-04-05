/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: eml_sort.c
 *
 * MATLAB Coder version            : 2.8
 * C/C++ source code generated on  : 05-Apr-2019 17:03:45
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "extract_notes.h"
#include "eml_sort.h"
#include "extract_notes_emxutil.h"

/* Function Declarations */
static void b_eml_sort(double x[164592]);
static void b_merge(emxArray_int32_T *idx, emxArray_real_T *x, int offset, int
                    np, int nq);
static void b_merge_block(emxArray_int32_T *idx, emxArray_real_T *x, int offset,
  int n, int preSortLevel);
static void eml_sort_idx(emxArray_real_T *x, emxArray_int32_T *idx);
static void merge(int idx[164592], double x[164592], int offset, int np, int nq);
static void merge_block(int idx[164592], double x[164592], int offset, int n,
  int preSortLevel);
static void merge_pow2_block(int idx[164592], double x[164592], int offset);

/* Function Definitions */

/*
 * Arguments    : double x[164592]
 * Return Type  : void
 */
static void b_eml_sort(double x[164592])
{
  static int idx[164592];
  double x4[4];
  int idx4[4];
  int m;
  static double xwork[164592];
  int nNaNs;
  int ib;
  int k;
  int i2;
  int i3;
  int i4;
  signed char perm[4];
  memset(&idx[0], 0, 164592U * sizeof(int));
  for (m = 0; m < 4; m++) {
    x4[m] = 0.0;
    idx4[m] = 0;
  }

  nNaNs = 0;
  ib = 0;
  for (k = 0; k < 164592; k++) {
    if (rtIsNaN(x[k])) {
      idx[164591 - nNaNs] = k + 1;
      xwork[164591 - nNaNs] = x[k];
      nNaNs++;
    } else {
      ib++;
      idx4[ib - 1] = k + 1;
      x4[ib - 1] = x[k];
      if (ib == 4) {
        ib = k - nNaNs;
        if (x4[0] >= x4[1]) {
          m = 1;
          i2 = 2;
        } else {
          m = 2;
          i2 = 1;
        }

        if (x4[2] >= x4[3]) {
          i3 = 3;
          i4 = 4;
        } else {
          i3 = 4;
          i4 = 3;
        }

        if (x4[m - 1] >= x4[i3 - 1]) {
          if (x4[i2 - 1] >= x4[i3 - 1]) {
            perm[0] = (signed char)m;
            perm[1] = (signed char)i2;
            perm[2] = (signed char)i3;
            perm[3] = (signed char)i4;
          } else if (x4[i2 - 1] >= x4[i4 - 1]) {
            perm[0] = (signed char)m;
            perm[1] = (signed char)i3;
            perm[2] = (signed char)i2;
            perm[3] = (signed char)i4;
          } else {
            perm[0] = (signed char)m;
            perm[1] = (signed char)i3;
            perm[2] = (signed char)i4;
            perm[3] = (signed char)i2;
          }
        } else if (x4[m - 1] >= x4[i4 - 1]) {
          if (x4[i2 - 1] >= x4[i4 - 1]) {
            perm[0] = (signed char)i3;
            perm[1] = (signed char)m;
            perm[2] = (signed char)i2;
            perm[3] = (signed char)i4;
          } else {
            perm[0] = (signed char)i3;
            perm[1] = (signed char)m;
            perm[2] = (signed char)i4;
            perm[3] = (signed char)i2;
          }
        } else {
          perm[0] = (signed char)i3;
          perm[1] = (signed char)i4;
          perm[2] = (signed char)m;
          perm[3] = (signed char)i2;
        }

        idx[ib - 3] = idx4[perm[0] - 1];
        idx[ib - 2] = idx4[perm[1] - 1];
        idx[ib - 1] = idx4[perm[2] - 1];
        idx[ib] = idx4[perm[3] - 1];
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

    for (k = 164592; k - 164591 <= ib; k++) {
      idx[(k - nNaNs) - ib] = idx4[perm[k - 164592] - 1];
      x[(k - nNaNs) - ib] = x4[perm[k - 164592] - 1];
    }
  }

  m = nNaNs >> 1;
  for (k = 164592; k - 164591 <= m; k++) {
    ib = idx[k - nNaNs];
    idx[k - nNaNs] = idx[329183 - k];
    idx[329183 - k] = ib;
    x[k - nNaNs] = xwork[329183 - k];
    x[329183 - k] = xwork[k - nNaNs];
  }

  if ((nNaNs & 1) != 0) {
    x[(m - nNaNs) + 164592] = xwork[(m - nNaNs) + 164592];
  }

  m = 2;
  if (164592 - nNaNs > 1) {
    ib = (164592 - nNaNs) >> 8;
    if (ib > 0) {
      for (m = 1; m <= ib; m++) {
        merge_pow2_block(idx, x, (m - 1) << 8);
      }

      m = ib << 8;
      ib = 164592 - (nNaNs + m);
      if (ib > 0) {
        merge_block(idx, x, m, ib, 2);
      }

      m = 8;
    }

    merge_block(idx, x, 0, 164592 - nNaNs, m);
  }

  if ((nNaNs > 0) && (164592 - nNaNs > 0)) {
    for (k = 1; k <= nNaNs; k++) {
      xwork[k - 1] = x[(k - nNaNs) + 164591];
    }

    for (k = 164591 - nNaNs; k + 1 > 0; k--) {
      x[nNaNs + k] = x[k];
    }

    for (k = 0; k + 1 <= nNaNs; k++) {
      x[k] = xwork[k];
    }
  }
}

/*
 * Arguments    : emxArray_int32_T *idx
 *                emxArray_real_T *x
 *                int offset
 *                int np
 *                int nq
 * Return Type  : void
 */
static void b_merge(emxArray_int32_T *idx, emxArray_real_T *x, int offset, int
                    np, int nq)
{
  emxArray_int32_T *iwork;
  emxArray_real_T *xwork;
  int n;
  int qend;
  int p;
  int iout;
  int32_T exitg1;
  emxInit_int32_T(&iwork, 1);
  b_emxInit_real_T(&xwork, 1);
  n = iwork->size[0];
  iwork->size[0] = idx->size[0];
  emxEnsureCapacity((emxArray__common *)iwork, n, (int)sizeof(int));
  qend = x->size[0];
  n = xwork->size[0];
  xwork->size[0] = qend;
  emxEnsureCapacity((emxArray__common *)xwork, n, (int)sizeof(double));
  if (nq == 0) {
  } else {
    n = np + nq;
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
}

/*
 * Arguments    : emxArray_int32_T *idx
 *                emxArray_real_T *x
 *                int offset
 *                int n
 *                int preSortLevel
 * Return Type  : void
 */
static void b_merge_block(emxArray_int32_T *idx, emxArray_real_T *x, int offset,
  int n, int preSortLevel)
{
  int nPairs;
  int bLen;
  int tailOffset;
  int nTail;
  nPairs = n >> preSortLevel;
  bLen = 1 << preSortLevel;
  while (nPairs > 1) {
    if ((nPairs & 1) != 0) {
      nPairs--;
      tailOffset = bLen * nPairs;
      nTail = n - tailOffset;
      if (nTail > bLen) {
        b_merge(idx, x, offset + tailOffset, bLen, nTail - bLen);
      }
    }

    tailOffset = bLen << 1;
    nPairs >>= 1;
    for (nTail = 1; nTail <= nPairs; nTail++) {
      b_merge(idx, x, offset + (nTail - 1) * tailOffset, bLen, bLen);
    }

    bLen = tailOffset;
  }

  if (n > bLen) {
    b_merge(idx, x, offset, bLen, n - bLen);
  }
}

/*
 * Arguments    : emxArray_real_T *x
 *                emxArray_int32_T *idx
 * Return Type  : void
 */
static void eml_sort_idx(emxArray_real_T *x, emxArray_int32_T *idx)
{
  emxArray_real_T *b_x;
  int ib;
  int p;
  int m;
  int n;
  double x4[4];
  int idx4[4];
  emxArray_real_T *xwork;
  int nNaNs;
  int k;
  int wOffset;
  int i4;
  signed char perm[4];
  int nNonNaN;
  int nBlocks;
  int iwork[256];
  double b_xwork[256];
  int bLen2;
  int nPairs;
  int32_T exitg1;
  b_emxInit_real_T(&b_x, 1);
  ib = x->size[0];
  p = b_x->size[0];
  b_x->size[0] = x->size[0];
  emxEnsureCapacity((emxArray__common *)b_x, p, (int)sizeof(double));
  m = x->size[0];
  for (p = 0; p < m; p++) {
    b_x->data[p] = x->data[p];
  }

  p = idx->size[0];
  idx->size[0] = ib;
  emxEnsureCapacity((emxArray__common *)idx, p, (int)sizeof(int));
  for (p = 0; p < ib; p++) {
    idx->data[p] = 0;
  }

  n = x->size[0];
  for (m = 0; m < 4; m++) {
    x4[m] = 0.0;
    idx4[m] = 0;
  }

  b_emxInit_real_T(&xwork, 1);
  ib = x->size[0];
  p = xwork->size[0];
  xwork->size[0] = ib;
  emxEnsureCapacity((emxArray__common *)xwork, p, (int)sizeof(double));
  nNaNs = 1;
  ib = 0;
  for (k = 0; k + 1 <= n; k++) {
    if (rtIsNaN(b_x->data[k])) {
      idx->data[n - nNaNs] = k + 1;
      xwork->data[n - nNaNs] = b_x->data[k];
      nNaNs++;
    } else {
      ib++;
      idx4[ib - 1] = k + 1;
      x4[ib - 1] = b_x->data[k];
      if (ib == 4) {
        ib = k - nNaNs;
        if (x4[0] <= x4[1]) {
          m = 1;
          p = 2;
        } else {
          m = 2;
          p = 1;
        }

        if (x4[2] <= x4[3]) {
          wOffset = 3;
          i4 = 4;
        } else {
          wOffset = 4;
          i4 = 3;
        }

        if (x4[m - 1] <= x4[wOffset - 1]) {
          if (x4[p - 1] <= x4[wOffset - 1]) {
            perm[0] = (signed char)m;
            perm[1] = (signed char)p;
            perm[2] = (signed char)wOffset;
            perm[3] = (signed char)i4;
          } else if (x4[p - 1] <= x4[i4 - 1]) {
            perm[0] = (signed char)m;
            perm[1] = (signed char)wOffset;
            perm[2] = (signed char)p;
            perm[3] = (signed char)i4;
          } else {
            perm[0] = (signed char)m;
            perm[1] = (signed char)wOffset;
            perm[2] = (signed char)i4;
            perm[3] = (signed char)p;
          }
        } else if (x4[m - 1] <= x4[i4 - 1]) {
          if (x4[p - 1] <= x4[i4 - 1]) {
            perm[0] = (signed char)wOffset;
            perm[1] = (signed char)m;
            perm[2] = (signed char)p;
            perm[3] = (signed char)i4;
          } else {
            perm[0] = (signed char)wOffset;
            perm[1] = (signed char)m;
            perm[2] = (signed char)i4;
            perm[3] = (signed char)p;
          }
        } else {
          perm[0] = (signed char)wOffset;
          perm[1] = (signed char)i4;
          perm[2] = (signed char)m;
          perm[3] = (signed char)p;
        }

        idx->data[ib - 2] = idx4[perm[0] - 1];
        idx->data[ib - 1] = idx4[perm[1] - 1];
        idx->data[ib] = idx4[perm[2] - 1];
        idx->data[ib + 1] = idx4[perm[3] - 1];
        b_x->data[ib - 2] = x4[perm[0] - 1];
        b_x->data[ib - 1] = x4[perm[1] - 1];
        b_x->data[ib] = x4[perm[2] - 1];
        b_x->data[ib + 1] = x4[perm[3] - 1];
        ib = 0;
      }
    }
  }

  wOffset = x->size[0] - nNaNs;
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

    for (k = 1; k <= ib; k++) {
      idx->data[(wOffset - ib) + k] = idx4[perm[k - 1] - 1];
      b_x->data[(wOffset - ib) + k] = x4[perm[k - 1] - 1];
    }
  }

  m = (nNaNs - 1) >> 1;
  for (k = 1; k <= m; k++) {
    p = idx->data[wOffset + k];
    idx->data[wOffset + k] = idx->data[n - k];
    idx->data[n - k] = p;
    b_x->data[wOffset + k] = xwork->data[n - k];
    b_x->data[n - k] = xwork->data[wOffset + k];
  }

  if (((nNaNs - 1) & 1) != 0) {
    b_x->data[(wOffset + m) + 1] = xwork->data[(wOffset + m) + 1];
  }

  emxFree_real_T(&xwork);
  nNonNaN = (x->size[0] - nNaNs) + 1;
  m = 2;
  if (nNonNaN > 1) {
    if (x->size[0] >= 256) {
      nBlocks = nNonNaN >> 8;
      if (nBlocks > 0) {
        for (wOffset = 1; wOffset <= nBlocks; wOffset++) {
          i4 = ((wOffset - 1) << 8) - 1;
          for (nNaNs = 0; nNaNs < 6; nNaNs++) {
            n = 1 << (nNaNs + 2);
            bLen2 = n << 1;
            nPairs = 256 >> (nNaNs + 3);
            for (k = 1; k <= nPairs; k++) {
              m = i4 + (k - 1) * bLen2;
              for (ib = 1; ib <= bLen2; ib++) {
                iwork[ib - 1] = idx->data[m + ib];
                b_xwork[ib - 1] = b_x->data[m + ib];
              }

              p = 0;
              ib = n;
              do {
                exitg1 = 0;
                m++;
                if (b_xwork[p] <= b_xwork[ib]) {
                  idx->data[m] = iwork[p];
                  b_x->data[m] = b_xwork[p];
                  if (p + 1 < n) {
                    p++;
                  } else {
                    exitg1 = 1;
                  }
                } else {
                  idx->data[m] = iwork[ib];
                  b_x->data[m] = b_xwork[ib];
                  if (ib + 1 < bLen2) {
                    ib++;
                  } else {
                    ib = m - p;
                    while (p + 1 <= n) {
                      idx->data[(ib + p) + 1] = iwork[p];
                      b_x->data[(ib + p) + 1] = b_xwork[p];
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
          b_merge_block(idx, b_x, m, ib, 2);
        }

        m = 8;
      }
    }

    b_merge_block(idx, b_x, 0, nNonNaN, m);
  }

  p = x->size[0];
  x->size[0] = b_x->size[0];
  emxEnsureCapacity((emxArray__common *)x, p, (int)sizeof(double));
  m = b_x->size[0];
  for (p = 0; p < m; p++) {
    x->data[p] = b_x->data[p];
  }

  emxFree_real_T(&b_x);
}

/*
 * Arguments    : int idx[164592]
 *                double x[164592]
 *                int offset
 *                int np
 *                int nq
 * Return Type  : void
 */
static void merge(int idx[164592], double x[164592], int offset, int np, int nq)
{
  static int iwork[164592];
  static double xwork[164592];
  int n;
  int qend;
  int p;
  int iout;
  int32_T exitg1;
  if (nq == 0) {
  } else {
    n = np + nq;
    for (qend = 0; qend + 1 <= n; qend++) {
      iwork[qend] = idx[offset + qend];
      xwork[qend] = x[offset + qend];
    }

    p = 0;
    n = np;
    qend = np + nq;
    iout = offset - 1;
    do {
      exitg1 = 0;
      iout++;
      if (xwork[p] >= xwork[n]) {
        idx[iout] = iwork[p];
        x[iout] = xwork[p];
        if (p + 1 < np) {
          p++;
        } else {
          exitg1 = 1;
        }
      } else {
        idx[iout] = iwork[n];
        x[iout] = xwork[n];
        if (n + 1 < qend) {
          n++;
        } else {
          n = (iout - p) + 1;
          while (p + 1 <= np) {
            idx[n + p] = iwork[p];
            x[n + p] = xwork[p];
            p++;
          }

          exitg1 = 1;
        }
      }
    } while (exitg1 == 0);
  }
}

/*
 * Arguments    : int idx[164592]
 *                double x[164592]
 *                int offset
 *                int n
 *                int preSortLevel
 * Return Type  : void
 */
static void merge_block(int idx[164592], double x[164592], int offset, int n,
  int preSortLevel)
{
  int nPairs;
  int bLen;
  int tailOffset;
  int nTail;
  nPairs = n >> preSortLevel;
  bLen = 1 << preSortLevel;
  while (nPairs > 1) {
    if ((nPairs & 1) != 0) {
      nPairs--;
      tailOffset = bLen * nPairs;
      nTail = n - tailOffset;
      if (nTail > bLen) {
        merge(idx, x, offset + tailOffset, bLen, nTail - bLen);
      }
    }

    tailOffset = bLen << 1;
    nPairs >>= 1;
    for (nTail = 1; nTail <= nPairs; nTail++) {
      merge(idx, x, offset + (nTail - 1) * tailOffset, bLen, bLen);
    }

    bLen = tailOffset;
  }

  if (n > bLen) {
    merge(idx, x, offset, bLen, n - bLen);
  }
}

/*
 * Arguments    : int idx[164592]
 *                double x[164592]
 *                int offset
 * Return Type  : void
 */
static void merge_pow2_block(int idx[164592], double x[164592], int offset)
{
  int iwork[256];
  double xwork[256];
  int b;
  int bLen;
  int bLen2;
  int nPairs;
  int k;
  int blockOffset;
  int q;
  int p;
  int32_T exitg1;
  for (b = 0; b < 6; b++) {
    bLen = 1 << (b + 2);
    bLen2 = bLen << 1;
    nPairs = 256 >> (b + 3);
    for (k = 1; k <= nPairs; k++) {
      blockOffset = (offset + (k - 1) * bLen2) - 1;
      for (q = 1; q <= bLen2; q++) {
        iwork[q - 1] = idx[blockOffset + q];
        xwork[q - 1] = x[blockOffset + q];
      }

      p = 0;
      q = bLen;
      do {
        exitg1 = 0;
        blockOffset++;
        if (xwork[p] >= xwork[q]) {
          idx[blockOffset] = iwork[p];
          x[blockOffset] = xwork[p];
          if (p + 1 < bLen) {
            p++;
          } else {
            exitg1 = 1;
          }
        } else {
          idx[blockOffset] = iwork[q];
          x[blockOffset] = xwork[q];
          if (q + 1 < bLen2) {
            q++;
          } else {
            q = blockOffset - p;
            while (p + 1 <= bLen) {
              idx[(q + p) + 1] = iwork[p];
              x[(q + p) + 1] = xwork[p];
              p++;
            }

            exitg1 = 1;
          }
        }
      } while (exitg1 == 0);
    }
  }
}

/*
 * Arguments    : emxArray_real_T *x
 *                emxArray_int32_T *idx
 * Return Type  : void
 */
void c_eml_sort(emxArray_real_T *x, emxArray_int32_T *idx)
{
  int dim;
  int i11;
  emxArray_real_T *vwork;
  int j;
  int vstride;
  int k;
  emxArray_int32_T *iidx;
  dim = 2;
  if (x->size[0] != 1) {
    dim = 1;
  }

  if (dim <= 1) {
    i11 = x->size[0];
  } else {
    i11 = 1;
  }

  b_emxInit_real_T(&vwork, 1);
  j = vwork->size[0];
  vwork->size[0] = i11;
  emxEnsureCapacity((emxArray__common *)vwork, j, (int)sizeof(double));
  vstride = x->size[0];
  j = idx->size[0];
  idx->size[0] = vstride;
  emxEnsureCapacity((emxArray__common *)idx, j, (int)sizeof(int));
  vstride = 1;
  k = 1;
  while (k <= dim - 1) {
    vstride *= x->size[0];
    k = 2;
  }

  j = 0;
  emxInit_int32_T(&iidx, 1);
  while (j + 1 <= vstride) {
    for (k = 0; k + 1 <= i11; k++) {
      vwork->data[k] = x->data[j + k * vstride];
    }

    eml_sort_idx(vwork, iidx);
    for (k = 0; k + 1 <= i11; k++) {
      x->data[j + k * vstride] = vwork->data[k];
      idx->data[j + k * vstride] = iidx->data[k];
    }

    j++;
  }

  emxFree_int32_T(&iidx);
  emxFree_real_T(&vwork);
}

/*
 * Arguments    : double x[164592]
 * Return Type  : void
 */
void eml_sort(double x[164592])
{
  b_eml_sort(x);
}

/*
 * File trailer for eml_sort.c
 *
 * [EOF]
 */
