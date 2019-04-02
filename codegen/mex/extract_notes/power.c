/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * power.c
 *
 * Code generation for function 'power'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "extract_notes.h"
#include "power.h"
#include "libmwimfilter.h"
#include "libmwippfilter.h"

/* Function Definitions */
void power(const real_T a[164592], real_T y[164592])
{
  int32_T k;
  for (k = 0; k < 164592; k++) {
    y[k] = a[k] * a[k];
  }
}

/* End of code generation (power.c) */
