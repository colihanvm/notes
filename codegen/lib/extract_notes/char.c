/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: char.c
 *
 * MATLAB Coder version            : 2.8
 * C/C++ source code generated on  : 05-Apr-2019 17:03:45
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "extract_notes.h"
#include "char.h"
#include "extract_notes_emxutil.h"

/* Function Definitions */

/*
 * Arguments    : const emxArray_real_T *varargin_1
 *                emxArray_char_T *y
 * Return Type  : void
 */
void b_char(const emxArray_real_T *varargin_1, emxArray_char_T *y)
{
  unsigned int uv0[2];
  int i9;
  int loop_ub;
  double d3;
  for (i9 = 0; i9 < 2; i9++) {
    uv0[i9] = (unsigned int)varargin_1->size[i9];
  }

  i9 = y->size[0] * y->size[1];
  y->size[0] = (int)uv0[0];
  y->size[1] = 2;
  emxEnsureCapacity((emxArray__common *)y, i9, (int)sizeof(char));
  loop_ub = (int)uv0[0] << 1;
  for (i9 = 0; i9 < loop_ub; i9++) {
    d3 = floor(varargin_1->data[i9]);
    if (rtIsNaN(d3) || rtIsInf(d3)) {
      d3 = 0.0;
    } else {
      d3 = fmod(d3, 256.0);
    }

    if (d3 < 0.0) {
      y->data[i9] = (signed char)-(signed char)(unsigned char)-d3;
    } else {
      y->data[i9] = (signed char)(unsigned char)d3;
    }
  }
}

/*
 * File trailer for char.c
 *
 * [EOF]
 */
