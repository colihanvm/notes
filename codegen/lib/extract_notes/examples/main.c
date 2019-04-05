/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: main.c
 *
 * MATLAB Coder version            : 2.8
 * C/C++ source code generated on  : 05-Apr-2019 15:22:58
 */

/*************************************************************************/
/* This automatically generated example C main file shows how to call    */
/* entry-point functions that MATLAB Coder generated. You must customize */
/* this file for your application. Do not modify this file directly.     */
/* Instead, make a copy of this file, modify it, and integrate it into   */
/* your development environment.                                         */
/*                                                                       */
/* This file initializes entry-point function arguments to a default     */
/* size and value before calling the entry-point functions. It does      */
/* not store or use any values returned from the entry-point functions.  */
/* If necessary, it does pre-allocate memory for returned values.        */
/* You can use this file as a starting point for a main function that    */
/* you can deploy in your application.                                   */
/*                                                                       */
/* After you copy the file, and before you deploy it, you must make the  */
/* following changes:                                                    */
/* * For variable-size function arguments, change the example sizes to   */
/* the sizes that your application requires.                             */
/* * Change the example values of function arguments to the values that  */
/* your application requires.                                            */
/* * If the entry-point functions return values, store these values or   */
/* otherwise use them as required by your application.                   */
/*                                                                       */
/*************************************************************************/
/* Include Files */
#include "rt_nonfinite.h"
#include "extract_notes.h"
#include "main.h"
#include "extract_notes_terminate.h"
#include "extract_notes_emxAPI.h"
#include "extract_notes_initialize.h"
#include "libmwimfilter.h"
#include "libmwippfilter.h"

/* Function Declarations */
static void argInit_216x762x3_uint8_T(unsigned char result[493776]);
static double argInit_real_T(void);
static unsigned char argInit_uint8_T(void);
static void main_extract_notes(void);

/* Function Definitions */

/*
 * Arguments    : unsigned char result[493776]
 * Return Type  : void
 */
static void argInit_216x762x3_uint8_T(unsigned char result[493776])
{
  int b_j0;
  int b_j1;
  int j2;

  /* Loop over the array to initialize each element. */
  for (b_j0 = 0; b_j0 < 216; b_j0++) {
    for (b_j1 = 0; b_j1 < 762; b_j1++) {
      for (j2 = 0; j2 < 3; j2++) {
        /* Set the value of the array element.
           Change this value to the value that the application requires. */
        result[(b_j0 + 216 * b_j1) + 164592 * j2] = argInit_uint8_T();
      }
    }
  }
}

/*
 * Arguments    : void
 * Return Type  : double
 */
static double argInit_real_T(void)
{
  return 0.0;
}

/*
 * Arguments    : void
 * Return Type  : unsigned char
 */
static unsigned char argInit_uint8_T(void)
{
  return 0;
}

/*
 * Arguments    : void
 * Return Type  : void
 */
static void main_extract_notes(void)
{
  emxArray_char_T *notes;
  static unsigned char uv1[493776];
  emxInitArray_char_T(&notes, 2);

  /* Initialize function 'extract_notes' input arguments. */
  /* Initialize function input argument 'im'. */
  /* Call the entry-point 'extract_notes'. */
  argInit_216x762x3_uint8_T(uv1);
  extract_notes(uv1, argInit_real_T(), argInit_real_T(), argInit_real_T(), notes);
  emxDestroyArray_char_T(notes);
}

/*
 * Arguments    : int argc
 *                const char * const argv[]
 * Return Type  : int
 */
int main(int argc, const char * const argv[])
{
  (void)argc;
  (void)argv;

  /* Initialize the application.
     You do not need to do this more than one time. */
  extract_notes_initialize();

  /* Invoke the entry-point functions.
     You can call entry-point functions multiple times. */
  main_extract_notes();

  /* Terminate the application.
     You do not need to do this more than one time. */
  extract_notes_terminate();
  return 0;
}

/*
 * File trailer for main.c
 *
 * [EOF]
 */
