/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: detectEdges_removeLines.c
 *
 * MATLAB Coder version            : 2.8
 * C/C++ source code generated on  : 05-Apr-2019 15:22:58
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "extract_notes.h"
#include "detectEdges_removeLines.h"
#include "extract_notes_emxutil.h"
#include "atand.h"
#include "rdivide.h"
#include "sqrt.h"
#include "power.h"
#include "imfilter.h"
#include "libmwimfilter.h"
#include "libmwippfilter.h"

/* Function Declarations */
static int div_s32(int numerator, int denominator);

/* Function Definitions */

/*
 * Arguments    : int numerator
 *                int denominator
 * Return Type  : int
 */
static int div_s32(int numerator, int denominator)
{
  int quotient;
  unsigned int absNumerator;
  unsigned int absDenominator;
  boolean_T quotientNeedsNegation;
  if (denominator == 0) {
    if (numerator >= 0) {
      quotient = MAX_int32_T;
    } else {
      quotient = MIN_int32_T;
    }
  } else {
    if (numerator >= 0) {
      absNumerator = (unsigned int)numerator;
    } else {
      absNumerator = (unsigned int)-numerator;
    }

    if (denominator >= 0) {
      absDenominator = (unsigned int)denominator;
    } else {
      absDenominator = (unsigned int)-denominator;
    }

    quotientNeedsNegation = ((numerator < 0) != (denominator < 0));
    absNumerator /= absDenominator;
    if (quotientNeedsNegation) {
      quotient = -(int)absNumerator;
    } else {
      quotient = (int)absNumerator;
    }
  }

  return quotient;
}

/*
 * im = rgb2gray(im);
 * Arguments    : const unsigned char im[164592]
 *                double threshold
 *                emxArray_real_T *edges
 * Return Type  : void
 */
void detectEdges_removeLines(const unsigned char im[164592], double threshold,
  emxArray_real_T *edges)
{
  static double b_im[164592];
  int i5;
  static double Gx[164592];
  static double Gy[164592];
  static double grad_mag[164592];
  boolean_T x[164592];
  emxArray_int32_T *ii;
  int idx;
  int b_ii;
  boolean_T exitg1;
  boolean_T guard1 = false;
  emxArray_real_T *edge_inds;
  emxArray_int32_T *vk;
  emxArray_real_T *y_inds;
  emxArray_real_T *x_inds;
  emxArray_real_T *edge_orient;
  emxArray_real_T *b_grad_mag;
  int x_inds_idx_0;
  int y_inds_idx_0;

  /*  compute gradients */
  for (i5 = 0; i5 < 164592; i5++) {
    b_im[i5] = im[i5];
  }

  imfilter(b_im, Gx);
  for (i5 = 0; i5 < 164592; i5++) {
    b_im[i5] = im[i5];
  }

  b_imfilter(b_im, Gy);

  /*      im_less_lines = im; */
  /*      im_less_lines(abs(Gx)>50) = 255; */
  /*      im = im_less_lines; */
  /*  compute gradient magnitude */
  power(Gx, grad_mag);
  power(Gy, b_im);
  for (i5 = 0; i5 < 164592; i5++) {
    grad_mag[i5] += b_im[i5];
  }

  b_sqrt(grad_mag);

  /*  compute gradient orientation */
  /*  set default threshold (optional) */
  /*  find edge points */
  for (i5 = 0; i5 < 164592; i5++) {
    x[i5] = (grad_mag[i5] >= threshold);
  }

  emxInit_int32_T(&ii, 1);
  idx = 0;
  i5 = ii->size[0];
  ii->size[0] = 164592;
  emxEnsureCapacity((emxArray__common *)ii, i5, (int)sizeof(int));
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

  b_emxInit_real_T(&edge_inds, 1);
  i5 = ii->size[0];
  if (1 > idx) {
    ii->size[0] = 0;
  } else {
    ii->size[0] = idx;
  }

  emxEnsureCapacity((emxArray__common *)ii, i5, (int)sizeof(int));
  i5 = edge_inds->size[0];
  edge_inds->size[0] = ii->size[0];
  emxEnsureCapacity((emxArray__common *)edge_inds, i5, (int)sizeof(double));
  b_ii = ii->size[0];
  for (i5 = 0; i5 < b_ii; i5++) {
    edge_inds->data[i5] = ii->data[i5];
  }

  i5 = ii->size[0];
  ii->size[0] = edge_inds->size[0];
  emxEnsureCapacity((emxArray__common *)ii, i5, (int)sizeof(int));
  b_ii = edge_inds->size[0];
  for (i5 = 0; i5 < b_ii; i5++) {
    ii->data[i5] = (int)edge_inds->data[i5];
  }

  i5 = ii->size[0];
  emxEnsureCapacity((emxArray__common *)ii, i5, (int)sizeof(int));
  b_ii = ii->size[0];
  for (i5 = 0; i5 < b_ii; i5++) {
    ii->data[i5]--;
  }

  emxInit_int32_T(&vk, 1);
  i5 = vk->size[0];
  vk->size[0] = ii->size[0];
  emxEnsureCapacity((emxArray__common *)vk, i5, (int)sizeof(int));
  b_ii = ii->size[0];
  for (i5 = 0; i5 < b_ii; i5++) {
    vk->data[i5] = div_s32(ii->data[i5], 216);
  }

  i5 = ii->size[0];
  emxEnsureCapacity((emxArray__common *)ii, i5, (int)sizeof(int));
  b_ii = ii->size[0];
  for (i5 = 0; i5 < b_ii; i5++) {
    ii->data[i5] -= vk->data[i5] * 216;
  }

  b_emxInit_real_T(&y_inds, 1);
  i5 = y_inds->size[0];
  y_inds->size[0] = ii->size[0];
  emxEnsureCapacity((emxArray__common *)y_inds, i5, (int)sizeof(double));
  b_ii = ii->size[0];
  for (i5 = 0; i5 < b_ii; i5++) {
    y_inds->data[i5] = ii->data[i5] + 1;
  }

  emxFree_int32_T(&ii);
  b_emxInit_real_T(&x_inds, 1);
  i5 = x_inds->size[0];
  x_inds->size[0] = vk->size[0];
  emxEnsureCapacity((emxArray__common *)x_inds, i5, (int)sizeof(double));
  b_ii = vk->size[0];
  for (i5 = 0; i5 < b_ii; i5++) {
    x_inds->data[i5] = vk->data[i5] + 1;
  }

  emxFree_int32_T(&vk);
  b_emxInit_real_T(&edge_orient, 1);
  rdivide(Gy, Gx, b_im);
  atand(b_im);
  i5 = edge_orient->size[0];
  edge_orient->size[0] = edge_inds->size[0];
  emxEnsureCapacity((emxArray__common *)edge_orient, i5, (int)sizeof(double));
  b_ii = edge_inds->size[0];
  for (i5 = 0; i5 < b_ii; i5++) {
    edge_orient->data[i5] = b_im[(int)edge_inds->data[i5] - 1];
  }

  b_emxInit_real_T(&b_grad_mag, 1);
  x_inds_idx_0 = x_inds->size[0];
  y_inds_idx_0 = y_inds->size[0];
  i5 = b_grad_mag->size[0];
  b_grad_mag->size[0] = edge_inds->size[0];
  emxEnsureCapacity((emxArray__common *)b_grad_mag, i5, (int)sizeof(double));
  b_ii = edge_inds->size[0];
  for (i5 = 0; i5 < b_ii; i5++) {
    b_grad_mag->data[i5] = grad_mag[(int)edge_inds->data[i5] - 1];
  }

  b_ii = edge_inds->size[0];
  idx = edge_orient->size[0];
  i5 = edges->size[0] * edges->size[1];
  edges->size[0] = x_inds_idx_0;
  edges->size[1] = 4;
  emxEnsureCapacity((emxArray__common *)edges, i5, (int)sizeof(double));
  emxFree_real_T(&edge_inds);
  for (i5 = 0; i5 < x_inds_idx_0; i5++) {
    edges->data[i5] = x_inds->data[i5];
  }

  emxFree_real_T(&x_inds);
  for (i5 = 0; i5 < y_inds_idx_0; i5++) {
    edges->data[i5 + edges->size[0]] = y_inds->data[i5];
  }

  emxFree_real_T(&y_inds);
  for (i5 = 0; i5 < b_ii; i5++) {
    edges->data[i5 + (edges->size[0] << 1)] = b_grad_mag->data[i5];
  }

  emxFree_real_T(&b_grad_mag);
  for (i5 = 0; i5 < idx; i5++) {
    edges->data[i5 + edges->size[0] * 3] = edge_orient->data[i5];
  }

  emxFree_real_T(&edge_orient);

  /*  display edges */
  /*      if (show == 1) */
  /*          figure; imshow(im); title('edge detection');  */
  /*      end; */
}

/*
 * File trailer for detectEdges_removeLines.c
 *
 * [EOF]
 */
