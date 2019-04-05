/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * sum.h
 *
 * Code generation for function 'sum'
 *
 */

#ifndef __SUM_H__
#define __SUM_H__

/* Include files */
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "mwmathutil.h"
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include "blas.h"
#include "rtwtypes.h"
#include "extract_notes_types.h"

/* Function Declarations */
extern real_T b_sum(const real_T x[216]);

#ifdef __WATCOMC__

#pragma aux b_sum value [8087];

#endif

extern real_T c_sum(const uint8_T x[164592]);

#ifdef __WATCOMC__

#pragma aux c_sum value [8087];

#endif

extern real_T d_sum(const real_T x[8]);

#ifdef __WATCOMC__

#pragma aux d_sum value [8087];

#endif

extern void e_sum(const emxArray_real_T *x, real_T y[762]);
extern real_T f_sum(const real_T x[762]);

#ifdef __WATCOMC__

#pragma aux f_sum value [8087];

#endif

extern real_T g_sum(const emlrtStack *sp, const emxArray_uint8_T *x);

#ifdef __WATCOMC__

#pragma aux g_sum value [8087];

#endif

extern void sum(const real_T x[164592], real_T y[216]);

#endif

/* End of code generation (sum.h) */
