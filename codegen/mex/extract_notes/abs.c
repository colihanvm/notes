/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * abs.c
 *
 * Code generation for function 'abs'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "extract_notes.h"
#include "abs.h"
#include "libmwimfilter.h"
#include "libmwippfilter.h"

/* Function Definitions */
void b_abs(const real_T x[26], real_T y[26])
{
  int32_T k;
  for (k = 0; k < 26; k++) {
    y[k] = muDoubleScalarAbs(x[k]);
  }
}

/* End of code generation (abs.c) */
