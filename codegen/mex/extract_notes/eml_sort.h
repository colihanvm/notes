/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * eml_sort.h
 *
 * Code generation for function 'eml_sort'
 *
 */

#ifndef __EML_SORT_H__
#define __EML_SORT_H__

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
extern void c_eml_sort(const emlrtStack *sp, emxArray_real_T *x,
  emxArray_int32_T *idx);
extern void eml_sort(extract_notesStackData *SD, const emlrtStack *sp, real_T x
                     [164592]);

#endif

/* End of code generation (eml_sort.h) */
