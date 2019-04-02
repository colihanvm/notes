/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * extract_notes.h
 *
 * Code generation for function 'extract_notes'
 *
 */

#ifndef __EXTRACT_NOTES_H__
#define __EXTRACT_NOTES_H__

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
extern void extract_notes(extract_notesStackData *SD, const emlrtStack *sp,
  const uint8_T im[493776], real_T threshold, real_T num_find, real_T radius,
  emxArray_char_T *notes);

#endif

/* End of code generation (extract_notes.h) */
