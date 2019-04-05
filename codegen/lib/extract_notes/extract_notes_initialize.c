/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: extract_notes_initialize.c
 *
 * MATLAB Coder version            : 2.8
 * C/C++ source code generated on  : 05-Apr-2019 15:22:58
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "extract_notes.h"
#include "extract_notes_initialize.h"
#include "libmwimfilter.h"
#include "libmwippfilter.h"

/* Function Definitions */

/*
 * Arguments    : void
 * Return Type  : void
 */
void extract_notes_initialize(void)
{
  rt_InitInfAndNaN(8U);
}

/*
 * File trailer for extract_notes_initialize.c
 *
 * [EOF]
 */
