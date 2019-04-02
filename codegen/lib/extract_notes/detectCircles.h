/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: detectCircles.h
 *
 * MATLAB Coder version            : 2.8
 * C/C++ source code generated on  : 02-Apr-2019 12:40:25
 */

#ifndef __DETECTCIRCLES_H__
#define __DETECTCIRCLES_H__

/* Include Files */
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "extract_notes_types.h"

/* Function Declarations */
extern void detectCircles(const emxArray_real_T *edges, double radius, double
  top_k, emxArray_real_T *centers);

#endif

/*
 * File trailer for detectCircles.h
 *
 * [EOF]
 */