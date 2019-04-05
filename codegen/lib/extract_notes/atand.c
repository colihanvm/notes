/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: atand.c
 *
 * MATLAB Coder version            : 2.8
 * C/C++ source code generated on  : 05-Apr-2019 17:03:45
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "extract_notes.h"
#include "atand.h"

/* Function Definitions */

/*
 * Arguments    : double x[164592]
 * Return Type  : void
 */
void atand(double x[164592])
{
  int k;
  for (k = 0; k < 164592; k++) {
    x[k] = 57.295779513082323 * atan(x[k]);
  }
}

/*
 * File trailer for atand.c
 *
 * [EOF]
 */
