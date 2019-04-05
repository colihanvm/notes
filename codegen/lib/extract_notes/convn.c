/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: convn.c
 *
 * MATLAB Coder version            : 2.8
 * C/C++ source code generated on  : 05-Apr-2019 17:03:45
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "extract_notes.h"
#include "convn.h"

/* Function Definitions */

/*
 * Arguments    : const double A[166116]
 *                const double B[3]
 *                double C[166116]
 * Return Type  : void
 */
void b_convn(const double A[166116], const double B[3], double C[166116])
{
  int k;
  int firstRowA;
  int iC;
  int c;
  int iB;
  int i;
  int b_i;
  int a_length;
  int cidx;
  int r;
  memset(&C[0], 0, 166116U * sizeof(double));
  for (k = 0; k < 762; k++) {
    firstRowA = k;
    iC = firstRowA * 218;
    c = k * 218;
    iB = 0;
    for (i = 0; i < 3; i++) {
      firstRowA = (i < 1);
      if (i + 218 <= 218) {
        b_i = 218;
      } else {
        b_i = 219 - i;
      }

      a_length = b_i - firstRowA;
      firstRowA += c;
      cidx = iC;
      for (r = 1; r <= a_length; r++) {
        C[cidx] += B[iB] * A[firstRowA];
        firstRowA++;
        cidx++;
      }

      iB++;
      if (i >= 1) {
        iC++;
      }
    }
  }
}

/*
 * Arguments    : const double A[165024]
 *                const double B[3]
 *                double C[165024]
 * Return Type  : void
 */
void convn(const double A[165024], const double B[3], double C[165024])
{
  int j;
  int lastColA;
  int k;
  int aidx;
  int b_j;
  int cidx;
  int r;
  memset(&C[0], 0, 165024U * sizeof(double));
  for (j = 0; j < 3; j++) {
    if (j + 763 < 764) {
      lastColA = 763;
    } else {
      lastColA = 764 - j;
    }

    for (k = (j < 1); k <= lastColA; k++) {
      aidx = k * 216;
      if (j + k > 1) {
        b_j = (j + k) - 1;
      } else {
        b_j = 0;
      }

      cidx = b_j * 216;
      for (r = 0; r < 216; r++) {
        C[cidx] += B[j] * A[aidx];
        aidx++;
        cidx++;
      }
    }
  }
}

/*
 * File trailer for convn.c
 *
 * [EOF]
 */
