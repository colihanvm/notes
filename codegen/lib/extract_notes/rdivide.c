/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: rdivide.c
 *
 * MATLAB Coder version            : 2.8
 * C/C++ source code generated on  : 05-Apr-2019 17:03:45
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "extract_notes.h"
#include "rdivide.h"

/* Function Definitions */

/*
 * Arguments    : const double x[164592]
 *                const double y[164592]
 *                double z[164592]
 * Return Type  : void
 */
void rdivide(const double x[164592], const double y[164592], double z[164592])
{
  int i8;
  for (i8 = 0; i8 < 164592; i8++) {
    z[i8] = x[i8] / y[i8];
  }
}

/*
 * File trailer for rdivide.c
 *
 * [EOF]
 */
