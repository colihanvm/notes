/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: sum.c
 *
 * MATLAB Coder version            : 2.8
 * C/C++ source code generated on  : 05-Apr-2019 17:03:45
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "extract_notes.h"
#include "sum.h"

/* Function Definitions */

/*
 * Arguments    : const double x[216]
 * Return Type  : double
 */
double b_sum(const double x[216])
{
  double y;
  int k;
  y = x[0];
  for (k = 0; k < 215; k++) {
    y += x[k + 1];
  }

  return y;
}

/*
 * Arguments    : const unsigned char x[164592]
 * Return Type  : double
 */
double c_sum(const unsigned char x[164592])
{
  double y;
  int k;
  y = x[0];
  for (k = 0; k < 164591; k++) {
    y += (double)x[k + 1];
  }

  return y;
}

/*
 * Arguments    : const double x[8]
 * Return Type  : double
 */
double d_sum(const double x[8])
{
  double y;
  int k;
  y = x[0];
  for (k = 0; k < 7; k++) {
    y += x[k + 1];
  }

  return y;
}

/*
 * Arguments    : const emxArray_real_T *x
 *                double y[762]
 * Return Type  : void
 */
void e_sum(const emxArray_real_T *x, double y[762])
{
  int ix;
  int iy;
  int i;
  int ixstart;
  double s;
  if (x->size[0] == 0) {
    memset(&y[0], 0, 762U * sizeof(double));
  } else {
    ix = -1;
    iy = -1;
    for (i = 0; i < 762; i++) {
      ixstart = ix + 1;
      ix++;
      s = x->data[ixstart];
      for (ixstart = 2; ixstart <= x->size[0]; ixstart++) {
        ix++;
        s += x->data[ix];
      }

      iy++;
      y[iy] = s;
    }
  }
}

/*
 * Arguments    : const double x[762]
 * Return Type  : double
 */
double f_sum(const double x[762])
{
  double y;
  int k;
  y = x[0];
  for (k = 0; k < 761; k++) {
    y += x[k + 1];
  }

  return y;
}

/*
 * Arguments    : const emxArray_uint8_T *x
 * Return Type  : double
 */
double g_sum(const emxArray_uint8_T *x)
{
  double y;
  int k;
  if (x->size[0] == 0) {
    y = 0.0;
  } else {
    y = x->data[0];
    for (k = 2; k <= x->size[0]; k++) {
      y += (double)x->data[k - 1];
    }
  }

  return y;
}

/*
 * Arguments    : const double x[164592]
 *                double y[216]
 * Return Type  : void
 */
void sum(const double x[164592], double y[216])
{
  int iy;
  int ixstart;
  int j;
  int ix;
  double s;
  int k;
  iy = -1;
  ixstart = -1;
  for (j = 0; j < 216; j++) {
    ixstart++;
    ix = ixstart;
    s = x[ixstart];
    for (k = 0; k < 761; k++) {
      ix += 216;
      s += x[ix];
    }

    iy++;
    y[iy] = s;
  }
}

/*
 * File trailer for sum.c
 *
 * [EOF]
 */
