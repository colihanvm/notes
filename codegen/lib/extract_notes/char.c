/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: char.c
 *
 * MATLAB Coder version            : 2.8
 * C/C++ source code generated on  : 05-Apr-2019 15:22:58
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "extract_notes.h"
#include "char.h"
#include "extract_notes_emxutil.h"
#include "libmwimfilter.h"
#include "libmwippfilter.h"

/* Function Definitions */

/*
 * Arguments    : const emxArray_real_T *varargin_1
 *                emxArray_char_T *y
 * Return Type  : void
 */
void b_char(const emxArray_real_T *varargin_1, emxArray_char_T *y)
{
  unsigned int uv0[2];
  int i7;
  int loop_ub;
  double d3;
  for (i7 = 0; i7 < 2; i7++) {
    uv0[i7] = (unsigned int)varargin_1->size[i7];
  }

  i7 = y->size[0] * y->size[1];
  y->size[0] = (int)uv0[0];
  y->size[1] = 2;
  emxEnsureCapacity((emxArray__common *)y, i7, (int)sizeof(char));
  loop_ub = (int)uv0[0] << 1;
  for (i7 = 0; i7 < loop_ub; i7++) {
    d3 = floor(varargin_1->data[i7]);
    if (rtIsNaN(d3) || rtIsInf(d3)) {
      d3 = 0.0;
    } else {
      d3 = fmod(d3, 256.0);
    }

    if (d3 < 0.0) {
      y->data[i7] = (signed char)-(signed char)(unsigned char)-d3;
    } else {
      y->data[i7] = (signed char)(unsigned char)d3;
    }
  }
}

/*
 * File trailer for char.c
 *
 * [EOF]
 */
