/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * std.h
 *
 * Code generation for function 'std'
 *
 */

#ifndef __STD_H__
#define __STD_H__

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
extern real_T b_std(const emlrtStack *sp, const real_T varargin_1[216]);

#ifdef __WATCOMC__

#pragma aux b_std value [8087];

#endif

extern real_T c_std(const emlrtStack *sp, const real_T varargin_1[164592]);

#ifdef __WATCOMC__

#pragma aux c_std value [8087];

#endif

extern real_T d_std(const emlrtStack *sp, const real_T varargin_1[762]);

#ifdef __WATCOMC__

#pragma aux d_std value [8087];

#endif
#endif

/* End of code generation (std.h) */
