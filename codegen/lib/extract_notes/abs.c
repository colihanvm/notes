/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: abs.c
 *
 * MATLAB Coder version            : 2.8
 * C/C++ source code generated on  : 05-Apr-2019 15:22:58
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "extract_notes.h"
#include "abs.h"
#include "libmwimfilter.h"
#include "libmwippfilter.h"

/* Function Definitions */

/*
 * Arguments    : const double x[26]
 *                double y[26]
 * Return Type  : void
 */
void b_abs(const double x[26], double y[26])
{
  int k;
  for (k = 0; k < 26; k++) {
    y[k] = fabs(x[k]);
  }
}

/*
 * File trailer for abs.c
 *
 * [EOF]
 */
