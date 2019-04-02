/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: rdivide.c
 *
 * MATLAB Coder version            : 2.8
 * C/C++ source code generated on  : 02-Apr-2019 12:40:25
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "extract_notes.h"
#include "rdivide.h"
#include "libmwimfilter.h"
#include "libmwippfilter.h"

/* Function Definitions */

/*
 * Arguments    : const double x[164592]
 *                const double y[164592]
 *                double z[164592]
 * Return Type  : void
 */
void rdivide(const double x[164592], const double y[164592], double z[164592])
{
  int i3;
  for (i3 = 0; i3 < 164592; i3++) {
    z[i3] = x[i3] / y[i3];
  }
}

/*
 * File trailer for rdivide.c
 *
 * [EOF]
 */
