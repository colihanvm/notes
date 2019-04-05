/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * rdivide.c
 *
 * Code generation for function 'rdivide'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "extract_notes.h"
#include "rdivide.h"
#include "libmwimfilter.h"
#include "libmwippfilter.h"

/* Function Definitions */
void rdivide(const real_T x[164592], const real_T y[164592], real_T z[164592])
{
  int32_T i27;
  for (i27 = 0; i27 < 164592; i27++) {
    z[i27] = x[i27] / y[i27];
  }
}

/* End of code generation (rdivide.c) */
