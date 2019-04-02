/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_extract_notes_mex.c
 *
 * Code generation for function '_coder_extract_notes_mex'
 *
 */

/* Include files */
#include "extract_notes.h"
#include "_coder_extract_notes_mex.h"
#include "extract_notes_terminate.h"
#include "_coder_extract_notes_api.h"
#include "extract_notes_initialize.h"
#include "extract_notes_data.h"
#include "libmwimfilter.h"
#include "libmwippfilter.h"

/* Variable Definitions */
static extract_notesStackData *extract_notesStackDataGlobal = NULL;

/* Function Declarations */
static void extract_notes_mexFunction(extract_notesStackData *SD, int32_T nlhs,
  mxArray *plhs[1], int32_T nrhs, const mxArray *prhs[4]);

/* Function Definitions */
static void extract_notes_mexFunction(extract_notesStackData *SD, int32_T nlhs,
  mxArray *plhs[1], int32_T nrhs, const mxArray *prhs[4])
{
  int32_T n;
  const mxArray *inputs[4];
  const mxArray *outputs[1];
  int32_T b_nlhs;
  emlrtStack st = { NULL, NULL, NULL };

  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 4) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 4, 4,
                        13, "extract_notes");
  }

  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 13,
                        "extract_notes");
  }

  /* Temporary copy for mex inputs. */
  for (n = 0; n < nrhs; n++) {
    inputs[n] = prhs[n];
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(&st);
    }
  }

  /* Call the function. */
  extract_notes_api(SD, inputs, outputs);

  /* Copy over outputs to the caller. */
  if (nlhs < 1) {
    b_nlhs = 1;
  } else {
    b_nlhs = nlhs;
  }

  emlrtReturnArrays(b_nlhs, plhs, outputs);

  /* Module termination. */
  extract_notes_terminate();
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  extract_notesStackDataGlobal = (extract_notesStackData *)mxCalloc(1, sizeof
    (extract_notesStackData));

  /* Initialize the memory manager. */
  mexAtExit(extract_notes_atexit);

  /* Module initialization. */
  extract_notes_initialize();

  /* Dispatch the entry-point. */
  extract_notes_mexFunction(extract_notesStackDataGlobal, nlhs, plhs, nrhs, prhs);
  mxFree(extract_notesStackDataGlobal);
}

/* End of code generation (_coder_extract_notes_mex.c) */
