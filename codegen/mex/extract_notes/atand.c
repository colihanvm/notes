/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * atand.c
 *
 * Code generation for function 'atand'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "extract_notes.h"
#include "atand.h"
#include "libmwimfilter.h"
#include "libmwippfilter.h"

/* Function Definitions */
void atand(real_T x[164592])
{
  int32_T k;
  for (k = 0; k < 164592; k++) {
    x[k] = 57.295779513082323 * muDoubleScalarAtan(x[k]);
  }
}

/* End of code generation (atand.c) */
