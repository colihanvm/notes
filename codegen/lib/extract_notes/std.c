/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: std.c
 *
 * MATLAB Coder version            : 2.8
 * C/C++ source code generated on  : 05-Apr-2019 17:03:45
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "extract_notes.h"
#include "std.h"

/* Function Definitions */

/*
 * Arguments    : const double varargin_1[216]
 * Return Type  : double
 */
double b_std(const double varargin_1[216])
{
  double y;
  int ix;
  double xbar;
  int k;
  double r;
  ix = 0;
  xbar = varargin_1[0];
  for (k = 0; k < 215; k++) {
    ix++;
    xbar += varargin_1[ix];
  }

  xbar /= 216.0;
  ix = 0;
  r = varargin_1[0] - xbar;
  y = r * r;
  for (k = 0; k < 215; k++) {
    ix++;
    r = varargin_1[ix] - xbar;
    y += r * r;
  }

  y /= 215.0;
  return sqrt(y);
}

/*
 * Arguments    : const double varargin_1[164592]
 * Return Type  : double
 */
double c_std(const double varargin_1[164592])
{
  double y;
  int ix;
  double xbar;
  int k;
  double r;
  ix = 0;
  xbar = varargin_1[0];
  for (k = 0; k < 164591; k++) {
    ix++;
    xbar += varargin_1[ix];
  }

  xbar /= 164592.0;
  ix = 0;
  r = varargin_1[0] - xbar;
  y = r * r;
  for (k = 0; k < 164591; k++) {
    ix++;
    r = varargin_1[ix] - xbar;
    y += r * r;
  }

  y /= 164591.0;
  return sqrt(y);
}

/*
 * Arguments    : const double varargin_1[762]
 * Return Type  : double
 */
double d_std(const double varargin_1[762])
{
  double y;
  int ix;
  double xbar;
  int k;
  double r;
  ix = 0;
  xbar = varargin_1[0];
  for (k = 0; k < 761; k++) {
    ix++;
    xbar += varargin_1[ix];
  }

  xbar /= 762.0;
  ix = 0;
  r = varargin_1[0] - xbar;
  y = r * r;
  for (k = 0; k < 761; k++) {
    ix++;
    r = varargin_1[ix] - xbar;
    y += r * r;
  }

  y /= 761.0;
  return sqrt(y);
}

/*
 * File trailer for std.c
 *
 * [EOF]
 */
