/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: process_stanza.c
 *
 * MATLAB Coder version            : 2.8
 * C/C++ source code generated on  : 05-Apr-2019 17:03:45
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "extract_notes.h"
#include "process_stanza.h"
#include "std.h"
#include "sum.h"
#include "extract_notes_emxutil.h"

/* Function Definitions */

/*
 * original chunk
 *  figure; imshow(im_chunk)
 * Arguments    : emxArray_uint8_T *im_chunk
 * Return Type  : void
 */
void process_stanza(emxArray_uint8_T *im_chunk)
{
  emxArray_real_T *b_im_chunk;
  int i10;
  int loop_ub;
  double dv4[762];
  double tmp[762];
  double threshold_val;
  short tmp_data[762];
  int trueCount;
  int i;
  int partialTrueCount;
  int del;
  double last;
  int same;
  emxInit_real_T(&b_im_chunk, 2);

  /* calculate column sum over the stanza */
  i10 = b_im_chunk->size[0] * b_im_chunk->size[1];
  b_im_chunk->size[0] = im_chunk->size[0];
  b_im_chunk->size[1] = 762;
  emxEnsureCapacity((emxArray__common *)b_im_chunk, i10, (int)sizeof(double));
  loop_ub = im_chunk->size[0] * im_chunk->size[1];
  for (i10 = 0; i10 < loop_ub; i10++) {
    b_im_chunk->data[i10] = im_chunk->data[i10];
  }

  e_sum(b_im_chunk, dv4);
  emxFree_real_T(&b_im_chunk);
  memcpy(&tmp[0], &dv4[0], 762U * sizeof(double));

  /*   figure; plot(tmp);  title('col sum'); */
  /* find value to threshold with */
  threshold_val = f_sum(tmp) / 762.0 - 2.0 * d_std(tmp);

  /* select vertical bits */
  /* delete vertical bits */
  trueCount = 0;
  for (i = 0; i < 762; i++) {
    if (tmp[i] < threshold_val) {
      trueCount++;
    }
  }

  partialTrueCount = 0;
  for (i = 0; i < 762; i++) {
    if (tmp[i] < threshold_val) {
      tmp_data[partialTrueCount] = (short)(i + 1);
      partialTrueCount++;
    }
  }

  loop_ub = im_chunk->size[0];
  for (i10 = 0; i10 < trueCount; i10++) {
    for (partialTrueCount = 0; partialTrueCount < loop_ub; partialTrueCount++) {
      im_chunk->data[partialTrueCount + im_chunk->size[0] * (tmp_data[i10] - 1)]
        = MAX_uint8_T;
    }
  }

  /* find nasty flags */
  /* max(tmp); */
  del = 0;
  last = -1.0;
  same = 0;
  for (i = 0; i < 761; i++) {
    if (del != 0) {
      /* last index was deleted or was rightmost edge */
      if (tmp[i] < tmp[0]) {
        if ((same != 0) && (tmp[i] != last)) {
          del = 0;
        }

        if (tmp[i] == last) {
          same = 1;
        }

        loop_ub = im_chunk->size[0];
        for (i10 = 0; i10 < loop_ub; i10++) {
          im_chunk->data[i10 + im_chunk->size[0] * i] = MAX_uint8_T;
        }

        last = tmp[i];
      } else {
        del = 0;
      }
    } else {
      if ((tmp[i] < threshold_val) && (!(tmp[1 + i] < threshold_val))) {
        /* find rightmost edge of a vert line */
        del = 1;
        same = 0;
      }
    }
  }

  /* the result! */
  /*  figure; imshow(im_chunk) */
}

/*
 * File trailer for process_stanza.c
 *
 * [EOF]
 */
