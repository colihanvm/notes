/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: power.c
 *
 * MATLAB Coder version            : 2.8
 * C/C++ source code generated on  : 05-Apr-2019 17:03:45
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "extract_notes.h"
#include "power.h"

/* Function Definitions */

/*
 * Arguments    : const double a[164592]
 *                double y[164592]
 * Return Type  : void
 */
void power(const double a[164592], double y[164592])
{
  int k;
  for (k = 0; k < 164592; k++) {
    y[k] = a[k] * a[k];
  }
}

/*
 * File trailer for power.c
 *
 * [EOF]
 */
