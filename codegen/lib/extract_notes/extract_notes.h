/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: extract_notes.h
 *
 * MATLAB Coder version            : 2.8
 * C/C++ source code generated on  : 05-Apr-2019 15:22:58
 */

#ifndef __EXTRACT_NOTES_H__
#define __EXTRACT_NOTES_H__

/* Include Files */
#include <float.h>
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "extract_notes_types.h"

/* Function Declarations */
extern void extract_notes(const unsigned char im[493776], double threshold,
  double num_find, double radius, emxArray_char_T *notes);

#endif

/*
 * File trailer for extract_notes.h
 *
 * [EOF]
 */
