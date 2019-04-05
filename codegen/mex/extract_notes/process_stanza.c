/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * process_stanza.c
 *
 * Code generation for function 'process_stanza'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "extract_notes.h"
#include "process_stanza.h"
#include "sum.h"
#include "extract_notes_emxutil.h"
#include "std.h"
#include "extract_notes_data.h"
#include "libmwimfilter.h"
#include "libmwippfilter.h"

/* Variable Definitions */
static emlrtRSInfo w_emlrtRSI = { 12, "process_stanza",
  "/Users/vanessacolihan/Documents/MATLAB/sd/process_stanza.m" };

static emlrtRTEInfo i_emlrtRTEI = { 1, 23, "process_stanza",
  "/Users/vanessacolihan/Documents/MATLAB/sd/process_stanza.m" };

/* Function Definitions */
void process_stanza(const emlrtStack *sp, emxArray_uint8_T *im_chunk)
{
  emxArray_real_T *b_im_chunk;
  int32_T i34;
  int32_T loop_ub;
  real_T dv0[762];
  real_T tmp[762];
  real_T std_val;
  real_T threshold_val;
  int16_T tmp_data[762];
  int32_T trueCount;
  int32_T i;
  int32_T partialTrueCount;
  int32_T del;
  real_T last;
  int32_T same;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_real_T(sp, &b_im_chunk, 2, &i_emlrtRTEI, true);

  /* original chunk */
  /*  figure; imshow(im_chunk) */
  /* calculate column sum over the stanza */
  i34 = b_im_chunk->size[0] * b_im_chunk->size[1];
  b_im_chunk->size[0] = im_chunk->size[0];
  b_im_chunk->size[1] = 762;
  emxEnsureCapacity(sp, (emxArray__common *)b_im_chunk, i34, (int32_T)sizeof
                    (real_T), &i_emlrtRTEI);
  loop_ub = im_chunk->size[0] * im_chunk->size[1];
  for (i34 = 0; i34 < loop_ub; i34++) {
    b_im_chunk->data[i34] = im_chunk->data[i34];
  }

  e_sum(b_im_chunk, dv0);
  emxFree_real_T(&b_im_chunk);
  memcpy(&tmp[0], &dv0[0], 762U * sizeof(real_T));

  /*   figure; plot(tmp);  title('col sum'); */
  /* find value to threshold with */
  st.site = &w_emlrtRSI;
  std_val = d_std(&st, tmp);
  threshold_val = f_sum(tmp) / 762.0 - 2.0 * std_val;

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
      tmp_data[partialTrueCount] = (int16_T)(i + 1);
      partialTrueCount++;
    }
  }

  loop_ub = im_chunk->size[0];
  for (i34 = 0; i34 < trueCount; i34++) {
    for (partialTrueCount = 0; partialTrueCount < loop_ub; partialTrueCount++) {
      im_chunk->data[partialTrueCount + im_chunk->size[0] * (tmp_data[i34] - 1)]
        = MAX_uint8_T;
    }
  }

  /* find nasty flags */
  /* max(tmp); */
  del = 0;
  last = -1.0;
  same = 0;
  i = 0;
  while (i < 761) {
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
        for (i34 = 0; i34 < loop_ub; i34++) {
          im_chunk->data[i34 + im_chunk->size[0] * i] = MAX_uint8_T;
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

    i++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  /* the result! */
  /*  figure; imshow(im_chunk) */
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (process_stanza.c) */
