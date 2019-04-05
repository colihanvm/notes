/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: padarray.c
 *
 * MATLAB Coder version            : 2.8
 * C/C++ source code generated on  : 05-Apr-2019 17:03:45
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "extract_notes.h"
#include "padarray.h"

/* Function Definitions */

/*
 * Arguments    : const double varargin_1[164592]
 *                double b[166116]
 * Return Type  : void
 */
void b_padarray(const double varargin_1[164592], double b[166116])
{
  int j;
  for (j = 0; j < 762; j++) {
    b[218 * j] = 0.0;
    b[217 + 218 * j] = 0.0;
    memcpy(&b[1 + 218 * j], &varargin_1[216 * j], 216U * sizeof(double));
  }
}

/*
 * Arguments    : const double varargin_1[164592]
 *                double b[165024]
 * Return Type  : void
 */
void padarray(const double varargin_1[164592], double b[165024])
{
  int i;
  for (i = 0; i < 216; i++) {
    b[i] = 0.0;
    b[164808 + i] = 0.0;
  }

  for (i = 0; i < 762; i++) {
    memcpy(&b[216 * (i + 1)], &varargin_1[216 * i], 216U * sizeof(double));
  }
}

/*
 * File trailer for padarray.c
 *
 * [EOF]
 */
