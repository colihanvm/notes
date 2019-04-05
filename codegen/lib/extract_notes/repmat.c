/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: repmat.c
 *
 * MATLAB Coder version            : 2.8
 * C/C++ source code generated on  : 05-Apr-2019 17:03:45
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "extract_notes.h"
#include "repmat.h"

/* Function Definitions */

/*
 * Arguments    : char b[52]
 * Return Type  : void
 */
void repmat(char b[52])
{
  int jcol;
  int iacol;
  int ibmat;
  int itilerow;
  int ibcol;
  int k;
  static const char cv0[26] = { 'A', 'G', 'F', 'E', 'D', 'C', 'B', 'A', 'G', 'F',
    'E', 'D', 'C', '5', '5', '5', '5', '5', '5', '4', '4', '4', '4', '4', '4',
    '4' };

  for (jcol = 0; jcol < 2; jcol++) {
    iacol = jcol * 13;
    ibmat = jcol * 26;
    for (itilerow = 0; itilerow < 2; itilerow++) {
      ibcol = ibmat + itilerow * 13;
      for (k = 0; k < 13; k++) {
        b[ibcol + k] = cv0[iacol + k];
      }
    }
  }
}

/*
 * File trailer for repmat.c
 *
 * [EOF]
 */
