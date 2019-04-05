/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: extract_notes.c
 *
 * MATLAB Coder version            : 2.8
 * C/C++ source code generated on  : 05-Apr-2019 15:22:58
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "extract_notes.h"
#include "mod.h"
#include "sum.h"
#include "extract_notes_emxutil.h"
#include "eml_sort.h"
#include "detectCircles.h"
#include "detectEdges_removeLines.h"
#include "process_stanza.h"
#include "abs.h"
#include "char.h"
#include "repmat.h"
#include "std.h"
#include "rgb2gray.h"
#include "extract_notes_rtwutil.h"
#include "libmwimfilter.h"
#include "libmwippfilter.h"

/* Function Declarations */
static void eml_null_assignment(emxArray_real_T *x, const emxArray_boolean_T
  *idx);

/* Function Definitions */

/*
 * Arguments    : emxArray_real_T *x
 *                const emxArray_boolean_T *idx
 * Return Type  : void
 */
static void eml_null_assignment(emxArray_real_T *x, const emxArray_boolean_T
  *idx)
{
  int nrowx;
  int nrows;
  int k;
  int i;
  int j;
  emxArray_real_T *b_x;
  nrowx = x->size[0];
  nrows = 0;
  for (k = 1; k <= idx->size[0]; k++) {
    nrows += idx->data[k - 1];
  }

  nrows = x->size[0] - nrows;
  i = 0;
  for (k = 1; k <= nrowx; k++) {
    if ((k > idx->size[0]) || (!idx->data[k - 1])) {
      for (j = 0; j < 2; j++) {
        x->data[i + x->size[0] * j] = x->data[(k + x->size[0] * j) - 1];
      }

      i++;
    }
  }

  if (1 > nrows) {
    nrows = 0;
  }

  emxInit_real_T(&b_x, 2);
  i = b_x->size[0] * b_x->size[1];
  b_x->size[0] = nrows;
  b_x->size[1] = 2;
  emxEnsureCapacity((emxArray__common *)b_x, i, (int)sizeof(double));
  for (i = 0; i < 2; i++) {
    for (j = 0; j < nrows; j++) {
      b_x->data[j + b_x->size[0] * i] = x->data[j + x->size[0] * i];
    }
  }

  i = x->size[0] * x->size[1];
  x->size[0] = b_x->size[0];
  x->size[1] = 2;
  emxEnsureCapacity((emxArray__common *)x, i, (int)sizeof(double));
  for (i = 0; i < 2; i++) {
    nrows = b_x->size[0];
    for (j = 0; j < nrows; j++) {
      x->data[j + x->size[0] * i] = b_x->data[j + b_x->size[0] * i];
    }
  }

  emxFree_real_T(&b_x);
}

/*
 * Arguments    : const unsigned char im[493776]
 *                double threshold
 *                double num_find
 *                double radius
 *                emxArray_char_T *notes
 * Return Type  : void
 */
void extract_notes(const unsigned char im[493776], double threshold, double
                   num_find, double radius, emxArray_char_T *notes)
{
  static unsigned char b_im[164592];
  int idx;
  int j;
  static double c_im[164592];
  int i0;
  double tmp[216];
  double threshold_val;
  unsigned char ii_data[216];
  int ixstart;
  boolean_T exitg2;
  boolean_T guard1 = false;
  int ix;
  unsigned char ind_data[216];
  int i1;
  double staffs[10];
  double staff_num[10];
  double num;
  double note_threshold;
  double lines_passed;
  double staff_heights[8];
  int h;
  int s;
  int above_s;
  double below_s;
  int x;
  int i2;
  unsigned char y;
  emxArray_real_T *centers;
  double avg_staff_height;
  emxArray_uint8_T *im_chunk;
  emxArray_real_T *edges;
  emxArray_real_T *chunk_centers;
  emxArray_boolean_T *extras;
  emxArray_real_T *unusedU0;
  emxArray_int32_T *iidx;
  emxArray_uint8_T *blank;
  emxArray_uint8_T *b_blank;
  emxArray_real_T *b_chunk_centers;
  emxArray_real_T *b_centers;
  int stanza;
  static unsigned char c_blank[164592];
  double chunk_end;
  int i3;
  int c;
  double d0;
  unsigned char blank_data[216];
  int c_chunk_centers;
  int blank_size[1];
  emxArray_uint8_T b_blank_data;
  double top;
  double d_chunk_centers;
  double bottom;
  double e_chunk_centers;
  unsigned char c_blank_data[216];
  int b_blank_size[1];
  emxArray_uint8_T d_blank_data;
  double full_staffs[26];
  char full_scale[52];
  int full_start;
  int staff_start;
  int l;
  int p;
  int b_p;
  emxArray_real_T *r0;
  double c_centers;
  double b_full_staffs[26];
  double varargin_1[26];
  double mtmp;
  int itmp;
  boolean_T exitg1;

  /*  radius = 5.4; */
  /*  num_find = 19; */
  /*  threshold = 155; */
  /*  im = imread('rowrowbt_mod3.png'); */
  rgb2gray(im, b_im);
  for (idx = 0; idx < 216; idx++) {
    for (j = 0; j < 762; j++) {
      if (b_im[idx + 216 * j] > 240) {
        b_im[idx + 216 * j] = MAX_uint8_T;
      }
    }
  }

  /* %  */
  for (i0 = 0; i0 < 164592; i0++) {
    c_im[i0] = b_im[i0];
  }

  sum(c_im, tmp);
  threshold_val = b_sum(tmp) / 216.0 - 2.0 * b_std(tmp);
  idx = 0;
  ixstart = 1;
  exitg2 = false;
  while ((!exitg2) && (ixstart < 217)) {
    guard1 = false;
    if (tmp[ixstart - 1] < threshold_val) {
      idx++;
      ii_data[idx - 1] = (unsigned char)ixstart;
      if (idx >= 216) {
        exitg2 = true;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }

    if (guard1) {
      ixstart++;
    }
  }

  if (1 > idx) {
    ix = 0;
  } else {
    ix = idx;
  }

  for (i0 = 0; i0 < ix; i0++) {
    ind_data[i0] = ii_data[i0];
  }

  /* actually delete the staffs */
  if (1 > idx) {
    ixstart = 0;
  } else {
    ixstart = idx;
  }

  for (i0 = 0; i0 < ix; i0++) {
    ii_data[i0] = ind_data[i0];
  }

  for (i0 = 0; i0 < 762; i0++) {
    for (i1 = 0; i1 < ixstart; i1++) {
      b_im[(ii_data[i1] + 216 * i0) - 1] = MAX_uint8_T;
    }
  }

  /* %  */
  /* calculate staff lines */
  for (idx = 0; idx < 10; idx++) {
    staffs[idx] = 0.0;
    staff_num[idx] = 0.0;
  }

  staffs[0] = ind_data[0];
  j = 0;
  num = 1.0;
  staff_num[0] = 1.0;
  for (idx = 1; idx - 1 <= ix - 2; idx++) {
    if (ind_data[idx] > ind_data[idx - 1] + 1) {
      /* end line deletion */
      staffs[j] = floor(staffs[j] / num);
      num = 1.0;
      j++;
      staffs[j] = ind_data[idx];

      /* first line */
      staff_num[j]++;
    } else {
      staffs[j] += (double)ind_data[idx];

      /* there was a line deleted above this */
      staff_num[j]++;
      num++;
      if (1 + idx == ix) {
        /* last */
        staffs[j] = floor(staffs[j] / num);
      }
    }
  }

  /* % */
  /* GAP STITCHING: */
  /* lines array contains index of staffs that were removed, matches ind array */
  /* staff_num tells number of horiz lines deleted around this staff */
  for (i0 = 0; i0 < 164592; i0++) {
    c_im[i0] = b_im[i0];
  }

  note_threshold = floor(c_sum(b_im) / 164592.0) - 2.0 * c_std(c_im);
  lines_passed = 1.0;

  /* will give current index of ind array (y pos of all staff part lines detected) */
  memset(&staff_heights[0], 0, sizeof(double) << 3);
  h = 0;
  for (s = 0; s < 10; s++) {
    /* y values of staffs. s = index of staffs AKA staff number */
    above_s = ind_data[(int)lines_passed - 1] - 1;
    below_s = (double)ind_data[(int)lines_passed - 1] + staff_num[s];

    /* ind(lines_passed) + staff_num(s)-1 + 1; */
    for (x = 0; x < 762; x++) {
      /* x pos of image */
      if (b_im[(above_s + 216 * x) - 1] < note_threshold) {
        if (b_im[((int)below_s + 216 * x) - 1] < note_threshold) {
          if (ind_data[(int)lines_passed - 1] > ind_data[(int)((lines_passed +
                staff_num[s]) - 1.0) - 1]) {
            i0 = 0;
            i1 = 0;
          } else {
            i0 = ind_data[(int)lines_passed - 1] - 1;
            i1 = ind_data[(int)((lines_passed + staff_num[s]) - 1.0) - 1];
          }

          i2 = (int)((unsigned int)b_im[(above_s + 216 * x) - 1] + b_im[((int)
                      below_s + 216 * x) - 1]);
          if ((unsigned int)i2 > 255U) {
            i2 = 255;
          }

          i2 = (int)rt_roundd_snf((double)i2 / 2.0);
          y = (unsigned char)i2;
          ix = i1 - i0;
          for (i1 = 0; i1 < ix; i1++) {
            b_im[(i0 + i1) + 216 * x] = y;
          }
        } else {
          if (b_im[(above_s + 216 * x) - 1] < note_threshold) {
            if (ind_data[(int)lines_passed - 1] > ind_data[(int)((lines_passed +
                  staff_num[s]) - 1.0) - 1]) {
              i0 = 0;
              i1 = 0;
            } else {
              i0 = ind_data[(int)lines_passed - 1] - 1;
              i1 = ind_data[(int)((lines_passed + staff_num[s]) - 1.0) - 1];
            }

            i2 = (int)rt_roundd_snf((double)b_im[(above_s + 216 * x) - 1] / 2.0);
            y = (unsigned char)i2;
            ix = i1 - i0;
            for (i1 = 0; i1 < ix; i1++) {
              b_im[(i0 + i1) + 216 * x] = y;
            }
          }
        }
      } else {
        if (b_im[((int)below_s + 216 * x) - 1] < note_threshold) {
          if (ind_data[(int)lines_passed - 1] > ind_data[(int)((lines_passed +
                staff_num[s]) - 1.0) - 1]) {
            i0 = 0;
            i1 = 0;
          } else {
            i0 = ind_data[(int)lines_passed - 1] - 1;
            i1 = ind_data[(int)((lines_passed + staff_num[s]) - 1.0) - 1];
          }

          i2 = (int)rt_roundd_snf((double)b_im[((int)below_s + 216 * x) - 1] /
            2.0);
          y = (unsigned char)i2;
          ix = i1 - i0;
          for (i1 = 0; i1 < ix; i1++) {
            b_im[(i0 + i1) + 216 * x] = y;
          }
        }
      }
    }

    lines_passed += staff_num[s];
    if ((1 + s > 1) && (b_mod(1.0 + (double)s, 6.0) != 0.0)) {
      staff_heights[h] = staffs[s] - staffs[s - 1];
      h++;
    }
  }

  emxInit_real_T(&centers, 2);
  avg_staff_height = d_sum(staff_heights) / 8.0;

  /* % */
  /* do work by chunks in this section */
  /*  radius = 5.4; */
  /*  num = 19;  */
  /* %%%%%%%%%%%%% TO DO: preallocate centers array  */
  i0 = centers->size[0] * centers->size[1];
  centers->size[0] = 0;
  centers->size[1] = 2;
  emxEnsureCapacity((emxArray__common *)centers, i0, (int)sizeof(double));

  /* remove vertical lines by stanza, using process_stanza() function. */
  emxInit_uint8_T(&im_chunk, 2);
  emxInit_real_T(&edges, 2);
  emxInit_real_T(&chunk_centers, 2);
  emxInit_boolean_T(&extras, 1);
  b_emxInit_real_T(&unusedU0, 1);
  emxInit_int32_T(&iidx, 1);
  b_emxInit_uint8_T(&blank, 1);
  b_emxInit_uint8_T(&b_blank, 1);
  emxInit_real_T(&b_chunk_centers, 2);
  emxInit_real_T(&b_centers, 2);
  for (stanza = 0; stanza < 2; stanza++) {
    memset(&c_blank[0], 255, 164592U * sizeof(unsigned char));
    chunk_end = staffs[4 + stanza * 5] + 2.0 * avg_staff_height;
    if (staffs[stanza * 5] > chunk_end) {
      i0 = 0;
      i1 = 0;
    } else {
      i0 = (int)staffs[stanza * 5] - 1;
      i1 = (int)chunk_end;
    }

    i2 = im_chunk->size[0] * im_chunk->size[1];
    im_chunk->size[0] = i1 - i0;
    im_chunk->size[1] = 762;
    emxEnsureCapacity((emxArray__common *)im_chunk, i2, (int)sizeof(unsigned
      char));
    for (i2 = 0; i2 < 762; i2++) {
      ix = i1 - i0;
      for (i3 = 0; i3 < ix; i3++) {
        im_chunk->data[i3 + im_chunk->size[0] * i2] = b_im[(i0 + i3) + 216 * i2];
      }
    }

    process_stanza(im_chunk);
    if (staffs[stanza * 5] > chunk_end) {
      i0 = 0;
    } else {
      i0 = (int)staffs[stanza * 5] - 1;
    }

    for (i1 = 0; i1 < 762; i1++) {
      ix = im_chunk->size[0];
      for (i2 = 0; i2 < ix; i2++) {
        c_blank[(i0 + i2) + 216 * i1] = im_chunk->data[i2 + im_chunk->size[0] *
          i1];
      }
    }

    detectEdges_removeLines(c_blank, threshold, edges);
    detectCircles(edges, radius, num_find, chunk_centers);

    /* sort by x */
    ix = chunk_centers->size[0];
    i0 = unusedU0->size[0];
    unusedU0->size[0] = ix;
    emxEnsureCapacity((emxArray__common *)unusedU0, i0, (int)sizeof(double));
    for (i0 = 0; i0 < ix; i0++) {
      unusedU0->data[i0] = chunk_centers->data[i0];
    }

    c_eml_sort(unusedU0, iidx);
    i0 = unusedU0->size[0];
    unusedU0->size[0] = iidx->size[0];
    emxEnsureCapacity((emxArray__common *)unusedU0, i0, (int)sizeof(double));
    ix = iidx->size[0];
    for (i0 = 0; i0 < ix; i0++) {
      unusedU0->data[i0] = iidx->data[i0];
    }

    i0 = b_chunk_centers->size[0] * b_chunk_centers->size[1];
    b_chunk_centers->size[0] = unusedU0->size[0];
    b_chunk_centers->size[1] = 2;
    emxEnsureCapacity((emxArray__common *)b_chunk_centers, i0, (int)sizeof
                      (double));
    for (i0 = 0; i0 < 2; i0++) {
      ix = unusedU0->size[0];
      for (i1 = 0; i1 < ix; i1++) {
        b_chunk_centers->data[i1 + b_chunk_centers->size[0] * i0] =
          chunk_centers->data[((int)unusedU0->data[i1] + chunk_centers->size[0] *
          i0) - 1];
      }
    }

    i0 = chunk_centers->size[0] * chunk_centers->size[1];
    chunk_centers->size[0] = b_chunk_centers->size[0];
    chunk_centers->size[1] = 2;
    emxEnsureCapacity((emxArray__common *)chunk_centers, i0, (int)sizeof(double));
    for (i0 = 0; i0 < 2; i0++) {
      ix = b_chunk_centers->size[0];
      for (i1 = 0; i1 < ix; i1++) {
        chunk_centers->data[i1 + chunk_centers->size[0] * i0] =
          b_chunk_centers->data[i1 + b_chunk_centers->size[0] * i0];
      }
    }

    /* post processing of this chunk */
    /* first, remove the random perimeter circles that tend to pop up */
    ix = chunk_centers->size[0];
    i0 = extras->size[0];
    extras->size[0] = ix;
    emxEnsureCapacity((emxArray__common *)extras, i0, (int)sizeof(boolean_T));
    for (i0 = 0; i0 < ix; i0++) {
      extras->data[i0] = (chunk_centers->data[i0] > 762.0 - radius);
    }

    eml_null_assignment(chunk_centers, extras);
    ix = chunk_centers->size[0];
    i0 = extras->size[0];
    extras->size[0] = ix;
    emxEnsureCapacity((emxArray__common *)extras, i0, (int)sizeof(boolean_T));
    for (i0 = 0; i0 < ix; i0++) {
      extras->data[i0] = (chunk_centers->data[i0 + chunk_centers->size[0]] >
                          216.0 - radius);
    }

    eml_null_assignment(chunk_centers, extras);
    i0 = extras->size[0];
    extras->size[0] = chunk_centers->size[0];
    emxEnsureCapacity((emxArray__common *)extras, i0, (int)sizeof(boolean_T));
    ix = chunk_centers->size[0];
    for (i0 = 0; i0 < ix; i0++) {
      extras->data[i0] = false;
    }

    /* check every circle c: */
    for (c = 1; c - 1 < (int)((double)chunk_centers->size[0] + -1.0); c++) {
      if (chunk_centers->data[c] == chunk_centers->data[(int)((2.0 + (double)(c
             - 1)) - 1.0) - 1]) {
        extras->data[c] = true;
      } else {
        if (fabs(chunk_centers->data[c] - chunk_centers->data[(int)((2.0 +
               (double)(c - 1)) - 1.0) - 1]) < radius * 2.0) {
          if (unusedU0->data[c] < unusedU0->data[(int)((2.0 + (double)(c - 1)) -
               1.0) - 1]) {
            extras->data[(int)((2.0 + (double)(c - 1)) - 1.0) - 1] = true;
          } else {
            extras->data[c] = true;
          }
        }
      }
    }

    /* remove the circles we just flagged */
    eml_null_assignment(chunk_centers, extras);

    /* final post processing for individual circles */
    /* TODO: better benchmarks */
    i0 = chunk_centers->size[0];
    for (c = 0; c < i0; c++) {
      d0 = chunk_centers->data[c + chunk_centers->size[0]] - floor(radius);
      if (d0 > chunk_centers->data[c + chunk_centers->size[0]]) {
        i1 = 0;
        i2 = 0;
      } else {
        i1 = (int)d0 - 1;
        i2 = (int)chunk_centers->data[c + chunk_centers->size[0]];
      }

      c_chunk_centers = (int)chunk_centers->data[c];
      blank_size[0] = i2 - i1;
      ix = i2 - i1;
      for (i2 = 0; i2 < ix; i2++) {
        blank_data[i2] = c_blank[(i1 + i2) + 216 * (c_chunk_centers - 1)];
      }

      b_blank_data.data = (unsigned char *)&blank_data;
      b_blank_data.size = (int *)&blank_size;
      b_blank_data.allocatedSize = 216;
      b_blank_data.numDimensions = 1;
      b_blank_data.canFreeData = false;
      top = g_sum(&b_blank_data);
      d_chunk_centers = chunk_centers->data[c + chunk_centers->size[0]];
      d0 = floor(radius);
      c_chunk_centers = (int)chunk_centers->data[c];
      i1 = b_blank->size[0];
      b_blank->size[0] = (int)d0 + 1;
      emxEnsureCapacity((emxArray__common *)b_blank, i1, (int)sizeof(unsigned
        char));
      ix = (int)d0;
      for (i1 = 0; i1 <= ix; i1++) {
        b_blank->data[i1] = c_blank[((int)(d_chunk_centers + (double)i1) + 216 *
          (c_chunk_centers - 1)) - 1];
      }

      bottom = g_sum(b_blank);
      if (top - bottom < -900.0) {
        d_chunk_centers = chunk_centers->data[c];
        e_chunk_centers = chunk_centers->data[c + chunk_centers->size[0]];
        chunk_centers->data[c] = d_chunk_centers;
        chunk_centers->data[c + chunk_centers->size[0]] = e_chunk_centers -
          radius / 2.0;
      } else if (top - bottom < -500.0) {
        d_chunk_centers = chunk_centers->data[c];
        e_chunk_centers = chunk_centers->data[c + chunk_centers->size[0]];
        chunk_centers->data[c] = d_chunk_centers;
        chunk_centers->data[c + chunk_centers->size[0]] = e_chunk_centers -
          radius / 5.0;
      } else if (top - bottom > 900.0) {
        d_chunk_centers = chunk_centers->data[c];
        e_chunk_centers = chunk_centers->data[c + chunk_centers->size[0]];
        chunk_centers->data[c] = d_chunk_centers;
        chunk_centers->data[c + chunk_centers->size[0]] = e_chunk_centers +
          radius / 2.0;
      } else {
        if ((top == bottom) && (c_blank[((int)chunk_centers->data[c +
              chunk_centers->size[0]] + 216 * ((int)chunk_centers->data[c] - 1))
             - 1] == 255)) {
          d_chunk_centers = chunk_centers->data[c];
          e_chunk_centers = chunk_centers->data[c + chunk_centers->size[0]];
          chunk_centers->data[c] = d_chunk_centers + 1.0;
          chunk_centers->data[c + chunk_centers->size[0]] = e_chunk_centers;
          d0 = chunk_centers->data[c + chunk_centers->size[0]] - floor(radius);
          if (d0 > chunk_centers->data[c + chunk_centers->size[0]]) {
            i1 = 0;
            i2 = 0;
          } else {
            i1 = (int)d0 - 1;
            i2 = (int)chunk_centers->data[c + chunk_centers->size[0]];
          }

          c_chunk_centers = (int)chunk_centers->data[c];
          b_blank_size[0] = i2 - i1;
          ix = i2 - i1;
          for (i2 = 0; i2 < ix; i2++) {
            c_blank_data[i2] = c_blank[(i1 + i2) + 216 * (c_chunk_centers - 1)];
          }

          d_blank_data.data = (unsigned char *)&c_blank_data;
          d_blank_data.size = (int *)&b_blank_size;
          d_blank_data.allocatedSize = 216;
          d_blank_data.numDimensions = 1;
          d_blank_data.canFreeData = false;
          top = g_sum(&d_blank_data);
          d_chunk_centers = chunk_centers->data[c + chunk_centers->size[0]];
          d0 = floor(radius);
          c_chunk_centers = (int)chunk_centers->data[c];
          i1 = blank->size[0];
          blank->size[0] = (int)d0 + 1;
          emxEnsureCapacity((emxArray__common *)blank, i1, (int)sizeof(unsigned
            char));
          ix = (int)d0;
          for (i1 = 0; i1 <= ix; i1++) {
            blank->data[i1] = c_blank[((int)(d_chunk_centers + (double)i1) + 216
              * (c_chunk_centers - 1)) - 1];
          }

          bottom = g_sum(blank);
          if (top - bottom < -900.0) {
            d_chunk_centers = chunk_centers->data[c];
            e_chunk_centers = chunk_centers->data[c + chunk_centers->size[0]];
            chunk_centers->data[c] = d_chunk_centers;
            chunk_centers->data[c + chunk_centers->size[0]] = e_chunk_centers -
              radius / 2.0;
          } else {
            if (top - bottom > 900.0) {
              d_chunk_centers = chunk_centers->data[c];
              e_chunk_centers = chunk_centers->data[c + chunk_centers->size[0]];
              chunk_centers->data[c] = d_chunk_centers;
              chunk_centers->data[c + chunk_centers->size[0]] = e_chunk_centers
                + radius / 2.0;
            }
          }
        }
      }
    }

    i0 = b_centers->size[0] * b_centers->size[1];
    b_centers->size[0] = centers->size[0] + chunk_centers->size[0];
    b_centers->size[1] = 2;
    emxEnsureCapacity((emxArray__common *)b_centers, i0, (int)sizeof(double));
    for (i0 = 0; i0 < 2; i0++) {
      ix = centers->size[0];
      for (i1 = 0; i1 < ix; i1++) {
        b_centers->data[i1 + b_centers->size[0] * i0] = centers->data[i1 +
          centers->size[0] * i0];
      }
    }

    for (i0 = 0; i0 < 2; i0++) {
      ix = chunk_centers->size[0];
      for (i1 = 0; i1 < ix; i1++) {
        b_centers->data[(i1 + centers->size[0]) + b_centers->size[0] * i0] =
          chunk_centers->data[i1 + chunk_centers->size[0] * i0];
      }
    }

    i0 = centers->size[0] * centers->size[1];
    centers->size[0] = b_centers->size[0];
    centers->size[1] = 2;
    emxEnsureCapacity((emxArray__common *)centers, i0, (int)sizeof(double));
    for (i0 = 0; i0 < 2; i0++) {
      ix = b_centers->size[0];
      for (i1 = 0; i1 < ix; i1++) {
        centers->data[i1 + centers->size[0] * i0] = b_centers->data[i1 +
          b_centers->size[0] * i0];
      }
    }

    if (staffs[stanza * 5] > chunk_end) {
      i0 = 0;
    } else {
      i0 = (int)staffs[stanza * 5] - 1;
    }

    for (i1 = 0; i1 < 762; i1++) {
      ix = im_chunk->size[0];
      for (i2 = 0; i2 < ix; i2++) {
        b_im[(i0 + i2) + 216 * i1] = im_chunk->data[i2 + im_chunk->size[0] * i1];
      }
    }
  }

  emxFree_real_T(&b_centers);
  emxFree_real_T(&b_chunk_centers);
  emxFree_uint8_T(&b_blank);
  emxFree_uint8_T(&blank);
  emxFree_int32_T(&iidx);
  emxFree_real_T(&unusedU0);
  emxFree_boolean_T(&extras);
  emxFree_real_T(&chunk_centers);
  emxFree_real_T(&edges);
  emxFree_uint8_T(&im_chunk);

  /* % */
  /*  create full staffs and etc. */
  memset(&full_staffs[0], 0, 26U * sizeof(double));
  repmat(full_scale);
  for (stanza = 0; stanza < 2; stanza++) {
    full_start = 13 * stanza;
    staff_start = 5 * stanza;
    full_staffs[full_start] = staffs[staff_start] - avg_staff_height;

    /* A5 */
    full_staffs[full_start + 1] = staffs[staff_start] - avg_staff_height / 2.0;

    /* G5 */
    l = staff_start;
    for (p = 0; p < 9; p++) {
      b_p = (full_start + p) + 2;
      if (b_mod((double)((b_p + stanza) + 2) - 1.0, 2.0) != 0.0) {
        full_staffs[b_p] = staffs[l];
      } else {
        full_staffs[b_p] = staffs[l] + avg_staff_height / 2.0;
        l++;
      }
    }

    full_staffs[full_start + 11] = staffs[staff_start + 4] + avg_staff_height /
      2.0;

    /* D4 */
    full_staffs[full_start + 12] = staffs[staff_start + 4] + avg_staff_height;

    /* C4 */
  }

  emxInit_real_T(&r0, 2);

  /* % */
  /*  get those letters */
  ixstart = centers->size[0];
  i0 = r0->size[0] * r0->size[1];
  r0->size[0] = ixstart;
  r0->size[1] = 2;
  emxEnsureCapacity((emxArray__common *)r0, i0, (int)sizeof(double));
  for (i0 = 0; i0 < ixstart; i0++) {
    for (i1 = 0; i1 < 2; i1++) {
      r0->data[i0 + r0->size[0] * i1] = 48.0;
    }
  }

  b_char(r0, notes);
  idx = 0;
  emxFree_real_T(&r0);
  while (idx <= centers->size[0] - 1) {
    c_centers = centers->data[idx + centers->size[0]];
    for (i0 = 0; i0 < 26; i0++) {
      b_full_staffs[i0] = full_staffs[i0] - c_centers;
    }

    b_abs(b_full_staffs, varargin_1);
    ixstart = 1;
    mtmp = varargin_1[0];
    itmp = 0;
    if (rtIsNaN(varargin_1[0])) {
      ix = 2;
      exitg1 = false;
      while ((!exitg1) && (ix < 27)) {
        ixstart = ix;
        if (!rtIsNaN(varargin_1[ix - 1])) {
          mtmp = varargin_1[ix - 1];
          itmp = ix - 1;
          exitg1 = true;
        } else {
          ix++;
        }
      }
    }

    if (ixstart < 26) {
      while (ixstart + 1 < 27) {
        if (varargin_1[ixstart] < mtmp) {
          mtmp = varargin_1[ixstart];
          itmp = ixstart;
        }

        ixstart++;
      }
    }

    for (i0 = 0; i0 < 2; i0++) {
      notes->data[idx + notes->size[0] * i0] = full_scale[itmp + 26 * i0];
    }

    /*      closest_to(centers(i,2), full_staffs, full_scale, avg_staff_height);  */
    idx++;
  }

  emxFree_real_T(&centers);
}

/*
 * File trailer for extract_notes.c
 *
 * [EOF]
 */
