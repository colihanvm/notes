/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: detectCircles.c
 *
 * MATLAB Coder version            : 2.8
 * C/C++ source code generated on  : 05-Apr-2019 17:03:45
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "extract_notes.h"
#include "detectCircles.h"
#include "sind.h"
#include "cosd.h"
#include "extract_notes_emxutil.h"
#include "eml_sort.h"

/* Function Definitions */

/*
 * Arguments    : const emxArray_real_T *edges
 *                double radius
 *                double top_k
 *                emxArray_real_T *centers
 * Return Type  : void
 */
void detectCircles(const emxArray_real_T *edges, double radius, double top_k,
                   emxArray_real_T *centers)
{
  int ii;
  int jj;
  static double H[164592];
  int i;
  double d2;
  double a;
  double b;
  static double H_sort[164592];
  int repeat;
  emxArray_real_T *row;
  emxArray_real_T *col;
  emxArray_int32_T *b_ii;
  emxArray_int32_T *b_jj;
  boolean_T x[164592];
  int idx;
  boolean_T exitg1;
  boolean_T guard1 = false;
  ii = centers->size[0] * centers->size[1];
  centers->size[0] = (int)top_k;
  centers->size[1] = 2;
  emxEnsureCapacity((emxArray__common *)centers, ii, (int)sizeof(double));
  jj = (int)top_k << 1;
  for (ii = 0; ii < jj; ii++) {
    centers->data[ii] = 0.0;
  }

  memset(&H[0], 0, 164592U * sizeof(double));
  for (i = 0; i < edges->size[0]; i++) {
    /* over every edge */
    /* [x, y, mag, ori] = edges(i, :); */
    d2 = edges->data[i + edges->size[0] * 3];
    cosd(&d2);
    a = ceil((edges->data[i] - radius * d2) / 5.0);
    d2 = edges->data[i + edges->size[0] * 3];
    sind(&d2);
    b = ceil((edges->data[i + edges->size[0]] - radius * d2) / 5.0);
    if ((a > 0.0) && (b > 0.0) && (a < 216.0) && (b < 762.0)) {
      H[(int)((a - 1.0) + 216.0 * (b - 1.0))]++;
    }
  }

  memcpy(&H_sort[0], &H[0], 164592U * sizeof(double));
  eml_sort(H_sort);
  repeat = 1;
  i = 0;
  b_emxInit_real_T(&row, 1);
  b_emxInit_real_T(&col, 1);
  emxInit_int32_T(&b_ii, 1);
  emxInit_int32_T(&b_jj, 1);
  while (i <= (int)top_k - 1) {
    for (ii = 0; ii < 164592; ii++) {
      x[ii] = (H[ii] == H_sort[i]);
    }

    idx = 0;
    ii = b_ii->size[0];
    b_ii->size[0] = 164592;
    emxEnsureCapacity((emxArray__common *)b_ii, ii, (int)sizeof(int));
    ii = b_jj->size[0];
    b_jj->size[0] = 164592;
    emxEnsureCapacity((emxArray__common *)b_jj, ii, (int)sizeof(int));
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

    ii = b_ii->size[0];
    if (1 > idx) {
      b_ii->size[0] = 0;
    } else {
      b_ii->size[0] = idx;
    }

    emxEnsureCapacity((emxArray__common *)b_ii, ii, (int)sizeof(int));
    ii = b_jj->size[0];
    if (1 > idx) {
      b_jj->size[0] = 0;
    } else {
      b_jj->size[0] = idx;
    }

    emxEnsureCapacity((emxArray__common *)b_jj, ii, (int)sizeof(int));
    ii = row->size[0];
    row->size[0] = b_ii->size[0];
    emxEnsureCapacity((emxArray__common *)row, ii, (int)sizeof(double));
    jj = b_ii->size[0];
    for (ii = 0; ii < jj; ii++) {
      row->data[ii] = b_ii->data[ii];
    }

    ii = col->size[0];
    col->size[0] = b_jj->size[0];
    emxEnsureCapacity((emxArray__common *)col, ii, (int)sizeof(double));
    jj = b_jj->size[0];
    for (ii = 0; ii < jj; ii++) {
      col->data[ii] = b_jj->data[ii];
    }

    if ((1.0 + (double)i > 1.0) && (H_sort[i] == H_sort[(int)((1.0 + (double)i)
          - 1.0) - 1])) {
      centers->data[i] = row->data[repeat];
      centers->data[i + centers->size[0]] = col->data[repeat];
      repeat++;
    } else {
      repeat = 1;
      centers->data[i] = row->data[0];
      centers->data[i + centers->size[0]] = col->data[0];
    }

    i++;
  }

  emxFree_int32_T(&b_jj);
  emxFree_int32_T(&b_ii);
  emxFree_real_T(&col);
  emxFree_real_T(&row);
  ii = centers->size[0] * centers->size[1];
  centers->size[1] = 2;
  emxEnsureCapacity((emxArray__common *)centers, ii, (int)sizeof(double));
  jj = centers->size[0];
  ii = centers->size[1];
  jj *= ii;
  for (ii = 0; ii < jj; ii++) {
    centers->data[ii] *= 5.0;
  }
}

/*
 * File trailer for detectCircles.c
 *
 * [EOF]
 */
