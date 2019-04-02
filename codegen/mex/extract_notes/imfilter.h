/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * imfilter.h
 *
 * Code generation for function 'imfilter'
 *
 */

#ifndef __IMFILTER_H__
#define __IMFILTER_H__

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
extern void b_imfilter(extract_notesStackData *SD, const real_T varargin_1
  [164592], real_T b[164592]);
extern void imfilter(extract_notesStackData *SD, const real_T varargin_1[164592],
                     real_T b[164592]);

#endif

/* End of code generation (imfilter.h) */
