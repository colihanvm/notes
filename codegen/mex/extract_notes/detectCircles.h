/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * detectCircles.h
 *
 * Code generation for function 'detectCircles'
 *
 */

#ifndef __DETECTCIRCLES_H__
#define __DETECTCIRCLES_H__

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
extern void detectCircles(extract_notesStackData *SD, const emlrtStack *sp,
  const emxArray_real_T *edges, real_T radius, real_T top_k, emxArray_real_T
  *centers);

#endif

/* End of code generation (detectCircles.h) */
