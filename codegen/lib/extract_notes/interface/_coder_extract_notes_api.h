/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_extract_notes_api.h
 *
 * MATLAB Coder version            : 2.8
 * C/C++ source code generated on  : 02-Apr-2019 12:40:25
 */

#ifndef ___CODER_EXTRACT_NOTES_API_H__
#define ___CODER_EXTRACT_NOTES_API_H__

/* Include Files */
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include <stddef.h>
#include <stdlib.h>
#include "_coder_extract_notes_api.h"

/* Type Definitions */
#ifndef struct_emxArray_char_T
#define struct_emxArray_char_T

struct emxArray_char_T
{
  char_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_char_T*/

#ifndef typedef_emxArray_char_T
#define typedef_emxArray_char_T

typedef struct emxArray_char_T emxArray_char_T;

#endif                                 /*typedef_emxArray_char_T*/

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

/* Function Declarations */
extern void extract_notes(uint8_T im[493776], real_T threshold, real_T num_find,
  real_T radius, emxArray_char_T *notes);
extern void extract_notes_api(const mxArray *prhs[4], const mxArray *plhs[1]);
extern void extract_notes_atexit(void);
extern void extract_notes_initialize(void);
extern void extract_notes_terminate(void);
extern void extract_notes_xil_terminate(void);

#endif

/*
 * File trailer for _coder_extract_notes_api.h
 *
 * [EOF]
 */
