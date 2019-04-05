/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: rdivide.c
 *
 * MATLAB Coder version            : 2.8
 * C/C++ source code generated on  : 05-Apr-2019 15:22:58
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
  int i6;
  for (i6 = 0; i6 < 164592; i6++) {
    z[i6] = x[i6] / y[i6];
  }
}

/*
 * File trailer for rdivide.c
 *
 * [EOF]
 */
