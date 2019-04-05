/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * repmat.c
 *
 * Code generation for function 'repmat'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "extract_notes.h"
#include "repmat.h"
#include "libmwimfilter.h"
#include "libmwippfilter.h"

/* Function Definitions */
void repmat(char_T b[52])
{
  int32_T jcol;
  int32_T iacol;
  int32_T ibmat;
  int32_T itilerow;
  int32_T ibcol;
  int32_T k;
  static const char_T cv3[26] = { 'A', 'G', 'F', 'E', 'D', 'C', 'B', 'A', 'G',
    'F', 'E', 'D', 'C', '5', '5', '5', '5', '5', '5', '4', '4', '4', '4', '4',
    '4', '4' };

  for (jcol = 0; jcol < 2; jcol++) {
    iacol = jcol * 13;
    ibmat = jcol * 26;
    for (itilerow = 0; itilerow < 2; itilerow++) {
      ibcol = ibmat + itilerow * 13;
      for (k = 0; k < 13; k++) {
        b[ibcol + k] = cv3[iacol + k];
      }
    }
  }
}

/* End of code generation (repmat.c) */
