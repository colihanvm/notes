/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: extract_notes.c
 *
 * MATLAB Coder version            : 2.8
 * C/C++ source code generated on  : 02-Apr-2019 12:40:25
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "extract_notes.h"
#include "extract_notes_emxutil.h"
#include "eml_sort.h"
#include "detectCircles.h"
#include "atand.h"
#include "rdivide.h"
#include "sqrt.h"
#include "power.h"
#include "imfilter.h"
#include "sum.h"
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
 * radius = 7; %pretty good for 4th, 8th
 *      num = 60;
 *  threshold = 155;
 *  im = imread('rowrowbt_mod3.png');
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
  unsigned char ii_data[216];
  int ii;
  boolean_T exitg2;
  boolean_T guard2 = false;
  int loop_ub;
  unsigned char ind_data[216];
  int i1;
  double staffs[10];
  double staff_num[10];
  double num;
  double lines_passed;
  int s;
  int above_s;
  double below_s;
  int x;
  unsigned char y;
  static double Gx[164592];
  static double Gy[164592];
  static double grad_mag[164592];
  static boolean_T b_x[164592];
  emxArray_int32_T *b_ii;
  boolean_T exitg1;
  boolean_T guard1 = false;
  emxArray_real_T *edge_inds;
  emxArray_int32_T *vk;
  emxArray_real_T *y_inds;
  emxArray_real_T *x_inds;
  emxArray_real_T *b_x_inds;
  emxArray_real_T *b_grad_mag;
  static double dv0[164592];
  int x_inds_idx_0;
  int y_inds_idx_0;
  emxArray_real_T *r0;
  int edge_inds_idx_0;
  emxArray_real_T *centers;
  emxArray_real_T *resort;
  emxArray_int32_T *iidx;
  emxArray_real_T *b_centers;
  emxArray_real_T *c_centers;
  unsigned int uv0[2];
  emxArray_real_T *temp;
  emxArray_boolean_T *b_resort;
  emxArray_boolean_T *c_resort;
  emxArray_real_T *d_centers;
  rgb2gray(im, b_im);
  for (idx = 0; idx < 216; idx++) {
    for (j = 0; j < 762; j++) {
      if (b_im[idx + 216 * j] > 240) {
        b_im[idx + 216 * j] = MAX_uint8_T;
      }
    }
  }

  /*  figure; imshow(im); title('pixel color adjust'); */
  for (i0 = 0; i0 < 164592; i0++) {
    c_im[i0] = b_im[i0];
  }

  sum(c_im, tmp);

  /*  figure; plot(tmp);  title('row sum'); */
  /*   */
  /*  pause; */
  idx = 0;
  ii = 1;
  exitg2 = false;
  while ((!exitg2) && (ii < 217)) {
    guard2 = false;
    if (tmp[ii - 1] < 147000.0) {
      idx++;
      ii_data[idx - 1] = (unsigned char)ii;
      if (idx >= 216) {
        exitg2 = true;
      } else {
        guard2 = true;
      }
    } else {
      guard2 = true;
    }

    if (guard2) {
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
      b_im[(ii_data[i1] + 216 * i0) - 1] = MAX_uint8_T;
    }
  }

  /*  figure; imshow(im); title('lines erased'); */
  /* pause; */
  /* calculate staff lines */
  for (idx = 0; idx < 10; idx++) {
    staffs[idx] = 0.0;
    staff_num[idx] = 0.0;
  }

  staffs[0] = ind_data[0];
  j = 0;
  num = 1.0;
  staff_num[0] = 1.0;
  for (idx = 1; idx - 1 <= loop_ub - 2; idx++) {
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
      if (1 + idx == loop_ub) {
        /* last */
        staffs[j] = floor(staffs[j] / num);
      }
    }
  }

  /*  figure; imshow(im); title('visualization of no staff lines'); hold on */
  /* pause; */
  /* GAP STITCHING: */
  /* lines array contains index of staffs that were removed, matches ind array */
  /* staff_num tells number of horiz lines deleted around this staff */
  lines_passed = 1.0;

  /* will give current index of ind array (y pos of all staff part lines detected) */
  for (s = 0; s < 10; s++) {
    /* y values of staffs. s = index of staffs AKA staff number */
    above_s = ind_data[(int)lines_passed - 1] - 1;
    below_s = (double)ind_data[(int)lines_passed - 1] + staff_num[s];

    /* ind(lines_passed) + staff_num(s)-1 + 1; */
    for (x = 0; x < 762; x++) {
      /* x pos of image */
      if (b_im[(above_s + 216 * x) - 1] < 200) {
        if (b_im[((int)below_s + 216 * x) - 1] < 200) {
          if (ind_data[(int)lines_passed - 1] > ind_data[(int)((lines_passed +
                staff_num[s]) - 1.0) - 1]) {
            i0 = 0;
            i1 = 0;
          } else {
            i0 = ind_data[(int)lines_passed - 1] - 1;
            i1 = ind_data[(int)((lines_passed + staff_num[s]) - 1.0) - 1];
          }

          ii = (int)((unsigned int)b_im[(above_s + 216 * x) - 1] + b_im[((int)
                      below_s + 216 * x) - 1]);
          if ((unsigned int)ii > 255U) {
            ii = 255;
          }

          ii = (int)rt_roundd_snf((double)ii / 2.0);
          y = (unsigned char)ii;
          loop_ub = i1 - i0;
          for (i1 = 0; i1 < loop_ub; i1++) {
            b_im[(i0 + i1) + 216 * x] = y;
          }
        } else {
          if (b_im[(above_s + 216 * x) - 1] < 150) {
            if (ind_data[(int)lines_passed - 1] > ind_data[(int)((lines_passed +
                  staff_num[s]) - 1.0) - 1]) {
              i0 = 0;
              i1 = 0;
            } else {
              i0 = ind_data[(int)lines_passed - 1] - 1;
              i1 = ind_data[(int)((lines_passed + staff_num[s]) - 1.0) - 1];
            }

            ii = (int)rt_roundd_snf((double)b_im[(above_s + 216 * x) - 1] / 2.0);
            y = (unsigned char)ii;
            loop_ub = i1 - i0;
            for (i1 = 0; i1 < loop_ub; i1++) {
              b_im[(i0 + i1) + 216 * x] = y;
            }
          }
        }
      } else {
        if (b_im[((int)below_s + 216 * x) - 1] < 150) {
          if (ind_data[(int)lines_passed - 1] > ind_data[(int)((lines_passed +
                staff_num[s]) - 1.0) - 1]) {
            i0 = 0;
            i1 = 0;
          } else {
            i0 = ind_data[(int)lines_passed - 1] - 1;
            i1 = ind_data[(int)((lines_passed + staff_num[s]) - 1.0) - 1];
          }

          ii = (int)rt_roundd_snf((double)b_im[((int)below_s + 216 * x) - 1] /
            2.0);
          y = (unsigned char)ii;
          loop_ub = i1 - i0;
          for (i1 = 0; i1 < loop_ub; i1++) {
            b_im[(i0 + i1) + 216 * x] = y;
          }
        }
      }
    }

    lines_passed += staff_num[s];
  }

  /*  figure; imshow(im); title('visualization of slightly more lines'); hold on */
  /*  figure; imshow(im); title('visualization of staff lines'); hold on */
  /*  plot(x, staffs*ones(size(x))); */
  /*   */
  /*  pause; */
  /*      radius = 7; %pretty good for 4th, 8th */
  /*      num = 60;  */
  /* im = rgb2gray(im); */
  /*  compute gradients */
  for (i0 = 0; i0 < 164592; i0++) {
    c_im[i0] = b_im[i0];
  }

  imfilter(c_im, Gx);
  for (i0 = 0; i0 < 164592; i0++) {
    c_im[i0] = b_im[i0];
  }

  b_imfilter(c_im, Gy);

  /*      im_less_lines = im; */
  /*      im_less_lines(abs(Gx)>50) = 255; */
  /*      im = im_less_lines; */
  /*  compute gradient magnitude */
  power(Gx, grad_mag);
  power(Gy, c_im);
  for (i0 = 0; i0 < 164592; i0++) {
    grad_mag[i0] += c_im[i0];
  }

  b_sqrt(grad_mag);

  /*  compute gradient orientation */
  /*  set default threshold (optional) */
  /*  find edge points */
  for (i0 = 0; i0 < 164592; i0++) {
    b_x[i0] = (grad_mag[i0] >= threshold);
  }

  emxInit_int32_T(&b_ii, 1);
  idx = 0;
  i0 = b_ii->size[0];
  b_ii->size[0] = 164592;
  emxEnsureCapacity((emxArray__common *)b_ii, i0, (int)sizeof(int));
  ii = 1;
  exitg1 = false;
  while ((!exitg1) && (ii < 164593)) {
    guard1 = false;
    if (b_x[ii - 1]) {
      idx++;
      b_ii->data[idx - 1] = ii;
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
    }
  }

  b_emxInit_real_T(&edge_inds, 1);
  i0 = b_ii->size[0];
  if (1 > idx) {
    b_ii->size[0] = 0;
  } else {
    b_ii->size[0] = idx;
  }

  emxEnsureCapacity((emxArray__common *)b_ii, i0, (int)sizeof(int));
  i0 = edge_inds->size[0];
  edge_inds->size[0] = b_ii->size[0];
  emxEnsureCapacity((emxArray__common *)edge_inds, i0, (int)sizeof(double));
  loop_ub = b_ii->size[0];
  for (i0 = 0; i0 < loop_ub; i0++) {
    edge_inds->data[i0] = b_ii->data[i0];
  }

  i0 = b_ii->size[0];
  b_ii->size[0] = edge_inds->size[0];
  emxEnsureCapacity((emxArray__common *)b_ii, i0, (int)sizeof(int));
  loop_ub = edge_inds->size[0];
  for (i0 = 0; i0 < loop_ub; i0++) {
    b_ii->data[i0] = (int)edge_inds->data[i0];
  }

  i0 = b_ii->size[0];
  emxEnsureCapacity((emxArray__common *)b_ii, i0, (int)sizeof(int));
  loop_ub = b_ii->size[0];
  for (i0 = 0; i0 < loop_ub; i0++) {
    b_ii->data[i0]--;
  }

  emxInit_int32_T(&vk, 1);
  i0 = vk->size[0];
  vk->size[0] = b_ii->size[0];
  emxEnsureCapacity((emxArray__common *)vk, i0, (int)sizeof(int));
  loop_ub = b_ii->size[0];
  for (i0 = 0; i0 < loop_ub; i0++) {
    i1 = b_ii->data[i0];
    vk->data[i0] = i1 / 216;
  }

  i0 = b_ii->size[0];
  emxEnsureCapacity((emxArray__common *)b_ii, i0, (int)sizeof(int));
  loop_ub = b_ii->size[0];
  for (i0 = 0; i0 < loop_ub; i0++) {
    b_ii->data[i0] -= vk->data[i0] * 216;
  }

  b_emxInit_real_T(&y_inds, 1);
  i0 = y_inds->size[0];
  y_inds->size[0] = b_ii->size[0];
  emxEnsureCapacity((emxArray__common *)y_inds, i0, (int)sizeof(double));
  loop_ub = b_ii->size[0];
  for (i0 = 0; i0 < loop_ub; i0++) {
    y_inds->data[i0] = b_ii->data[i0] + 1;
  }

  emxFree_int32_T(&b_ii);
  b_emxInit_real_T(&x_inds, 1);
  i0 = x_inds->size[0];
  x_inds->size[0] = vk->size[0];
  emxEnsureCapacity((emxArray__common *)x_inds, i0, (int)sizeof(double));
  loop_ub = vk->size[0];
  for (i0 = 0; i0 < loop_ub; i0++) {
    x_inds->data[i0] = vk->data[i0] + 1;
  }

  emxFree_int32_T(&vk);
  emxInit_real_T(&b_x_inds, 2);
  b_emxInit_real_T(&b_grad_mag, 1);

  /*  display edges */
  /*      not_edge_inds = find(grad_mag(:) < threshold); */
  /*      im(not_edge_inds) = 0; */
  /*      im(edge_inds) = edge_mag; */
  /*      if (show == 1) */
  /*          figure; imshow(im); title('edge detection');  */
  /*      end; */
  rdivide(Gy, Gx, c_im);
  atand(c_im);
  rdivide(Gy, Gx, dv0);
  atand(dv0);
  x_inds_idx_0 = x_inds->size[0];
  y_inds_idx_0 = y_inds->size[0];
  i0 = b_grad_mag->size[0];
  b_grad_mag->size[0] = edge_inds->size[0];
  emxEnsureCapacity((emxArray__common *)b_grad_mag, i0, (int)sizeof(double));
  loop_ub = edge_inds->size[0];
  for (i0 = 0; i0 < loop_ub; i0++) {
    b_grad_mag->data[i0] = grad_mag[(int)edge_inds->data[i0] - 1];
  }

  b_emxInit_real_T(&r0, 1);
  edge_inds_idx_0 = edge_inds->size[0];
  i0 = r0->size[0];
  r0->size[0] = edge_inds->size[0];
  emxEnsureCapacity((emxArray__common *)r0, i0, (int)sizeof(double));
  loop_ub = edge_inds->size[0];
  for (i0 = 0; i0 < loop_ub; i0++) {
    r0->data[i0] = c_im[(int)edge_inds->data[i0] - 1];
  }

  ii = edge_inds->size[0];
  i0 = b_x_inds->size[0] * b_x_inds->size[1];
  b_x_inds->size[0] = x_inds_idx_0;
  b_x_inds->size[1] = 4;
  emxEnsureCapacity((emxArray__common *)b_x_inds, i0, (int)sizeof(double));
  emxFree_real_T(&edge_inds);
  for (i0 = 0; i0 < x_inds_idx_0; i0++) {
    b_x_inds->data[i0] = x_inds->data[i0];
  }

  emxFree_real_T(&x_inds);
  for (i0 = 0; i0 < y_inds_idx_0; i0++) {
    b_x_inds->data[i0 + b_x_inds->size[0]] = y_inds->data[i0];
  }

  emxFree_real_T(&y_inds);
  for (i0 = 0; i0 < edge_inds_idx_0; i0++) {
    b_x_inds->data[i0 + (b_x_inds->size[0] << 1)] = b_grad_mag->data[i0];
  }

  emxFree_real_T(&b_grad_mag);
  for (i0 = 0; i0 < ii; i0++) {
    b_x_inds->data[i0 + b_x_inds->size[0] * 3] = r0->data[i0];
  }

  emxFree_real_T(&r0);
  emxInit_real_T(&centers, 2);
  b_emxInit_real_T(&resort, 1);
  detectCircles(b_x_inds, radius, num_find, centers);

  /* sort for y pos */
  loop_ub = centers->size[0];
  i0 = resort->size[0];
  resort->size[0] = loop_ub;
  emxEnsureCapacity((emxArray__common *)resort, i0, (int)sizeof(double));
  emxFree_real_T(&b_x_inds);
  for (i0 = 0; i0 < loop_ub; i0++) {
    resort->data[i0] = centers->data[i0 + centers->size[0]];
  }

  emxInit_int32_T(&iidx, 1);
  emxInit_real_T(&b_centers, 2);
  c_eml_sort(resort, iidx);
  i0 = b_centers->size[0] * b_centers->size[1];
  b_centers->size[0] = iidx->size[0];
  b_centers->size[1] = 2;
  emxEnsureCapacity((emxArray__common *)b_centers, i0, (int)sizeof(double));
  for (i0 = 0; i0 < 2; i0++) {
    loop_ub = iidx->size[0];
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_centers->data[i1 + b_centers->size[0] * i0] = centers->data[(iidx->
        data[i1] + centers->size[0] * i0) - 1];
    }
  }

  i0 = centers->size[0] * centers->size[1];
  centers->size[0] = b_centers->size[0];
  centers->size[1] = 2;
  emxEnsureCapacity((emxArray__common *)centers, i0, (int)sizeof(double));
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
  loop_ub = centers->size[0];
  i0 = resort->size[0];
  resort->size[0] = loop_ub;
  emxEnsureCapacity((emxArray__common *)resort, i0, (int)sizeof(double));
  for (i0 = 0; i0 < loop_ub; i0++) {
    resort->data[i0] = centers->data[i0];
  }

  emxInit_real_T(&c_centers, 2);
  c_eml_sort(resort, iidx);
  i0 = c_centers->size[0] * c_centers->size[1];
  c_centers->size[0] = iidx->size[0];
  c_centers->size[1] = 2;
  emxEnsureCapacity((emxArray__common *)c_centers, i0, (int)sizeof(double));
  for (i0 = 0; i0 < 2; i0++) {
    loop_ub = iidx->size[0];
    for (i1 = 0; i1 < loop_ub; i1++) {
      c_centers->data[i1 + c_centers->size[0] * i0] = centers->data[(iidx->
        data[i1] + centers->size[0] * i0) - 1];
    }
  }

  i0 = centers->size[0] * centers->size[1];
  centers->size[0] = c_centers->size[0];
  centers->size[1] = 2;
  emxEnsureCapacity((emxArray__common *)centers, i0, (int)sizeof(double));
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
  emxEnsureCapacity((emxArray__common *)resort, i0, (int)sizeof(double));
  loop_ub = centers->size[0];
  for (i0 = 0; i0 < loop_ub; i0++) {
    resort->data[i0] = 0.0;
  }

  for (i0 = 0; i0 < 2; i0++) {
    uv0[i0] = (unsigned int)centers->size[i0];
  }

  emxInit_real_T(&temp, 2);
  i0 = temp->size[0] * temp->size[1];
  temp->size[0] = (int)uv0[0];
  temp->size[1] = 2;
  emxEnsureCapacity((emxArray__common *)temp, i0, (int)sizeof(double));
  loop_ub = (int)uv0[0] << 1;
  for (i0 = 0; i0 < loop_ub; i0++) {
    temp->data[i0] = 0.0;
  }

  for (idx = 0; idx < centers->size[0]; idx++) {
    if (centers->data[idx + centers->size[0]] > (staffs[4] + staffs[5]) / 2.0) {
      resort->data[idx] = 1.0;
    }
  }

  /* reorder staff line notes so they floooow */
  loop_ub = resort->size[0] - 1;
  ii = 0;
  for (idx = 0; idx <= loop_ub; idx++) {
    if (resort->data[idx] == 1.0) {
      ii++;
    }
  }

  i0 = iidx->size[0];
  iidx->size[0] = ii;
  emxEnsureCapacity((emxArray__common *)iidx, i0, (int)sizeof(int));
  ii = 0;
  for (idx = 0; idx <= loop_ub; idx++) {
    if (resort->data[idx] == 1.0) {
      iidx->data[ii] = idx + 1;
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
  emxInit_boolean_T(&b_resort, 1);
  i0 = b_resort->size[0];
  b_resort->size[0] = resort->size[0];
  emxEnsureCapacity((emxArray__common *)b_resort, i0, (int)sizeof(boolean_T));
  loop_ub = resort->size[0];
  for (i0 = 0; i0 < loop_ub; i0++) {
    b_resort->data[i0] = (resort->data[i0] == 0.0);
  }

  emxInit_boolean_T(&c_resort, 1);
  eml_null_assignment(temp, b_resort);
  i0 = c_resort->size[0];
  c_resort->size[0] = resort->size[0];
  emxEnsureCapacity((emxArray__common *)c_resort, i0, (int)sizeof(boolean_T));
  loop_ub = resort->size[0];
  emxFree_boolean_T(&b_resort);
  for (i0 = 0; i0 < loop_ub; i0++) {
    c_resort->data[i0] = (resort->data[i0] == 1.0);
  }

  emxFree_real_T(&resort);
  emxInit_real_T(&d_centers, 2);
  eml_null_assignment(centers, c_resort);
  i0 = d_centers->size[0] * d_centers->size[1];
  d_centers->size[0] = centers->size[0] + temp->size[0];
  d_centers->size[1] = 2;
  emxEnsureCapacity((emxArray__common *)d_centers, i0, (int)sizeof(double));
  emxFree_boolean_T(&c_resort);
  for (i0 = 0; i0 < 2; i0++) {
    loop_ub = centers->size[0];
    for (i1 = 0; i1 < loop_ub; i1++) {
      d_centers->data[i1 + d_centers->size[0] * i0] = centers->data[i1 +
        centers->size[0] * i0];
    }
  }

  for (i0 = 0; i0 < 2; i0++) {
    loop_ub = temp->size[0];
    for (i1 = 0; i1 < loop_ub; i1++) {
      d_centers->data[(i1 + centers->size[0]) + d_centers->size[0] * i0] =
        temp->data[i1 + temp->size[0] * i0];
    }
  }

  i0 = centers->size[0] * centers->size[1];
  centers->size[0] = d_centers->size[0];
  centers->size[1] = 2;
  emxEnsureCapacity((emxArray__common *)centers, i0, (int)sizeof(double));
  for (i0 = 0; i0 < 2; i0++) {
    loop_ub = d_centers->size[0];
    for (i1 = 0; i1 < loop_ub; i1++) {
      centers->data[i1 + centers->size[0] * i0] = d_centers->data[i1 +
        d_centers->size[0] * i0];
    }
  }

  emxFree_real_T(&d_centers);

  /*  x=1:size(im,2); */
  /*  figure; imshow(im); title(strcat('Detected circles of radius=', num2str(radius), ', accuracy=', num2str(acc))); hold on */
  /*  plot(x, staffs*ones(size(x))); hold on */
  ii = centers->size[0];
  i0 = temp->size[0] * temp->size[1];
  temp->size[0] = ii;
  temp->size[1] = 2;
  emxEnsureCapacity((emxArray__common *)temp, i0, (int)sizeof(double));
  loop_ub = centers->size[0] << 1;
  for (i0 = 0; i0 < loop_ub; i0++) {
    temp->data[i0] = 0.0;
  }

  for (idx = 0; idx < centers->size[0]; idx++) {
    /*     viscircles(centers(i,:), radius * ones(size(centers(i), 1), 1)); hold on */
    for (i0 = 0; i0 < 2; i0++) {
      temp->data[idx + temp->size[0] * i0] = 48.0;
    }
  }

  emxFree_real_T(&centers);
  for (i0 = 0; i0 < 2; i0++) {
    uv0[i0] = (unsigned int)temp->size[i0];
  }

  i0 = notes->size[0] * notes->size[1];
  notes->size[0] = (int)uv0[0];
  notes->size[1] = 2;
  emxEnsureCapacity((emxArray__common *)notes, i0, (int)sizeof(char));
  loop_ub = (int)uv0[0] << 1;
  for (i0 = 0; i0 < loop_ub; i0++) {
    notes->data[i0] = (signed char)floor(temp->data[i0]);
  }

  emxFree_real_T(&temp);

  /*  viscircles(centers, radius * ones(size(centers, 1), 1)); hold on */
  /*  plot(x, staffs*ones(size(x))); */
}

/*
 * File trailer for extract_notes.c
 *
 * [EOF]
 */
