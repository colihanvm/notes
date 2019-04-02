/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * detectEdges_removeLines.h
 *
 * Code generation for function 'detectEdges_removeLines'
 *
 */

#ifndef __DETECTEDGES_REMOVELINES_H__
#define __DETECTEDGES_REMOVELINES_H__

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
extern void detectEdges_removeLines(extract_notesStackData *SD, const emlrtStack
  *sp, const uint8_T im[164592], real_T threshold, emxArray_real_T *edges);

#endif

/* End of code generation (detectEdges_removeLines.h) */
