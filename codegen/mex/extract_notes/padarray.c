/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * padarray.c
 *
 * Code generation for function 'padarray'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "extract_notes.h"
#include "padarray.h"
#include "libmwimfilter.h"
#include "libmwippfilter.h"

/* Function Definitions */
void b_padarray(const real_T varargin_1[164592], real_T b[166116])
{
  int32_T j;
  for (j = 0; j < 762; j++) {
    b[218 * j] = 0.0;
    b[217 + 218 * j] = 0.0;
    memcpy(&b[1 + 218 * j], &varargin_1[216 * j], 216U * sizeof(real_T));
  }
}

void padarray(const real_T varargin_1[164592], real_T b[165024])
{
  int32_T i;
  for (i = 0; i < 216; i++) {
    b[i] = 0.0;
    b[164808 + i] = 0.0;
  }

  for (i = 0; i < 762; i++) {
    memcpy(&b[216 * (i + 1)], &varargin_1[216 * i], 216U * sizeof(real_T));
  }
}

/* End of code generation (padarray.c) */
