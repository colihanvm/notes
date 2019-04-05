/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * extract_notes.c
 *
 * Code generation for function 'extract_notes'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "extract_notes.h"
#include "extract_notes_emxutil.h"
#include "detectEdges_removeLines.h"
#include "detectCircles.h"
#include "mod.h"
#include "sum.h"
#include "eml_int_forloop_overflow_check.h"
#include "eml_sort.h"
#include "process_stanza.h"
#include "abs.h"
#include "char.h"
#include "repmat.h"
#include "std.h"
#include "rgb2gray.h"
#include "extract_notes_data.h"
#include "libmwimfilter.h"
#include "libmwippfilter.h"

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 7, "extract_notes",
  "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m" };

static emlrtRSInfo b_emlrtRSI = { 23, "extract_notes",
  "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m" };

static emlrtRSInfo c_emlrtRSI = { 73, "extract_notes",
  "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m" };

static emlrtRSInfo d_emlrtRSI = { 125, "extract_notes",
  "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m" };

static emlrtRSInfo e_emlrtRSI = { 128, "extract_notes",
  "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m" };

static emlrtRSInfo f_emlrtRSI = { 129, "extract_notes",
  "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m" };

static emlrtRSInfo g_emlrtRSI = { 132, "extract_notes",
  "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m" };

static emlrtRSInfo h_emlrtRSI = { 137, "extract_notes",
  "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m" };

static emlrtRSInfo i_emlrtRSI = { 138, "extract_notes",
  "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m" };

static emlrtRSInfo j_emlrtRSI = { 154, "extract_notes",
  "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m" };

static emlrtRSInfo k_emlrtRSI = { 159, "extract_notes",
  "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m" };

static emlrtRSInfo l_emlrtRSI = { 160, "extract_notes",
  "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m" };

static emlrtRSInfo m_emlrtRSI = { 169, "extract_notes",
  "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m" };

static emlrtRSInfo n_emlrtRSI = { 170, "extract_notes",
  "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m" };

static emlrtRSInfo o_emlrtRSI = { 213, "extract_notes",
  "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m" };

static emlrtRSInfo lc_emlrtRSI = { 20, "sort",
  "/Applications/MATLAB_R2015a.app/toolbox/eml/lib/matlab/datafun/sort.m" };

static emlrtRSInfo wc_emlrtRSI = { 19, "eml_null_assignment",
  "/Applications/MATLAB_R2015a.app/toolbox/eml/lib/matlab/eml/eml_null_assignment.m"
};

static emlrtRSInfo xc_emlrtRSI = { 23, "eml_null_assignment",
  "/Applications/MATLAB_R2015a.app/toolbox/eml/lib/matlab/eml/eml_null_assignment.m"
};

static emlrtRSInfo yc_emlrtRSI = { 266, "eml_null_assignment",
  "/Applications/MATLAB_R2015a.app/toolbox/eml/lib/matlab/eml/eml_null_assignment.m"
};

static emlrtRSInfo ad_emlrtRSI = { 269, "eml_null_assignment",
  "/Applications/MATLAB_R2015a.app/toolbox/eml/lib/matlab/eml/eml_null_assignment.m"
};

static emlrtRSInfo bd_emlrtRSI = { 128, "eml_null_assignment",
  "/Applications/MATLAB_R2015a.app/toolbox/eml/lib/matlab/eml/eml_null_assignment.m"
};

static emlrtRTEInfo c_emlrtRTEI = { 5, 20, "extract_notes",
  "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m" };

static emlrtRTEInfo d_emlrtRTEI = { 116, 1, "extract_notes",
  "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m" };

static emlrtRTEInfo e_emlrtRTEI = { 124, 5, "extract_notes",
  "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m" };

static emlrtRTEInfo f_emlrtRTEI = { 128, 5, "extract_notes",
  "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m" };

static emlrtRTEInfo g_emlrtRTEI = { 129, 5, "extract_notes",
  "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m" };

static emlrtRTEInfo h_emlrtRTEI = { 140, 5, "extract_notes",
  "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m" };

static emlrtRTEInfo v_emlrtRTEI = { 1, 14, "eml_null_assignment",
  "/Applications/MATLAB_R2015a.app/toolbox/eml/lib/matlab/eml/eml_null_assignment.m"
};

static emlrtBCInfo emlrtBCI = { -1, -1, 39, 1, "lines", "extract_notes",
  "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m", 0 };

static emlrtBCInfo b_emlrtBCI = { -1, -1, 225, 11, "notes", "extract_notes",
  "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m", 0 };

static emlrtBCInfo c_emlrtBCI = { -1, -1, 216, 34, "centers", "extract_notes",
  "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m", 0 };

static emlrtECInfo emlrtECI = { -1, 180, 5, "extract_notes",
  "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m" };

static emlrtBCInfo d_emlrtBCI = { 1, 216, 180, 8, "im", "extract_notes",
  "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m", 0 };

static emlrtDCInfo emlrtDCI = { 180, 8, "extract_notes",
  "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m", 1 };

static emlrtBCInfo e_emlrtBCI = { -1, -1, 174, 31, "chunk_centers",
  "extract_notes", "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m",
  0 };

static emlrtBCInfo f_emlrtBCI = { -1, -1, 172, 31, "chunk_centers",
  "extract_notes", "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m",
  0 };

static emlrtBCInfo g_emlrtBCI = { 1, 762, 170, 84, "blank", "extract_notes",
  "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m", 0 };

static emlrtDCInfo b_emlrtDCI = { 170, 84, "extract_notes",
  "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m", 1 };

static emlrtRTEInfo gb_emlrtRTEI = { 170, 32, "extract_notes",
  "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m" };

static emlrtBCInfo h_emlrtBCI = { -1, -1, 170, 65, "chunk_centers",
  "extract_notes", "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m",
  0 };

static emlrtBCInfo i_emlrtBCI = { -1, -1, 170, 46, "chunk_centers",
  "extract_notes", "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m",
  0 };

static emlrtBCInfo j_emlrtBCI = { 1, 762, 169, 81, "blank", "extract_notes",
  "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m", 0 };

static emlrtDCInfo c_emlrtDCI = { 169, 81, "extract_notes",
  "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m", 1 };

static emlrtBCInfo k_emlrtBCI = { 1, 216, 169, 29, "blank", "extract_notes",
  "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m", 0 };

static emlrtDCInfo d_emlrtDCI = { 169, 29, "extract_notes",
  "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m", 1 };

static emlrtBCInfo l_emlrtBCI = { -1, -1, 169, 76, "chunk_centers",
  "extract_notes", "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m",
  0 };

static emlrtBCInfo m_emlrtBCI = { -1, -1, 168, 27, "chunk_centers",
  "extract_notes", "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m",
  0 };

static emlrtBCInfo n_emlrtBCI = { -1, -1, 166, 27, "chunk_centers",
  "extract_notes", "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m",
  0 };

static emlrtBCInfo o_emlrtBCI = { -1, -1, 164, 27, "chunk_centers",
  "extract_notes", "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m",
  0 };

static emlrtBCInfo p_emlrtBCI = { -1, -1, 162, 27, "chunk_centers",
  "extract_notes", "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m",
  0 };

static emlrtBCInfo q_emlrtBCI = { 1, 762, 160, 80, "blank", "extract_notes",
  "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m", 0 };

static emlrtDCInfo e_emlrtDCI = { 160, 80, "extract_notes",
  "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m", 1 };

static emlrtRTEInfo hb_emlrtRTEI = { 160, 28, "extract_notes",
  "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m" };

static emlrtBCInfo r_emlrtBCI = { -1, -1, 160, 61, "chunk_centers",
  "extract_notes", "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m",
  0 };

static emlrtBCInfo s_emlrtBCI = { -1, -1, 160, 42, "chunk_centers",
  "extract_notes", "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m",
  0 };

static emlrtBCInfo t_emlrtBCI = { 1, 762, 159, 77, "blank", "extract_notes",
  "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m", 0 };

static emlrtDCInfo f_emlrtDCI = { 159, 77, "extract_notes",
  "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m", 1 };

static emlrtBCInfo u_emlrtBCI = { 1, 216, 159, 25, "blank", "extract_notes",
  "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m", 0 };

static emlrtDCInfo g_emlrtDCI = { 159, 25, "extract_notes",
  "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m", 1 };

static emlrtBCInfo v_emlrtBCI = { -1, -1, 159, 72, "chunk_centers",
  "extract_notes", "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m",
  0 };

static emlrtBCInfo w_emlrtBCI = { -1, -1, 145, 56, "chunk_centers",
  "extract_notes", "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m",
  0 };

static emlrtBCInfo x_emlrtBCI = { -1, -1, 145, 35, "chunk_centers",
  "extract_notes", "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m",
  0 };

static emlrtECInfo b_emlrtECI = { -1, 127, 5, "extract_notes",
  "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m" };

static emlrtBCInfo y_emlrtBCI = { 1, 216, 127, 11, "blank", "extract_notes",
  "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m", 0 };

static emlrtDCInfo h_emlrtDCI = { 127, 11, "extract_notes",
  "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m", 1 };

static emlrtBCInfo ab_emlrtBCI = { 1, 216, 124, 19, "im", "extract_notes",
  "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m", 0 };

static emlrtDCInfo i_emlrtDCI = { 124, 19, "extract_notes",
  "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m", 1 };

static emlrtBCInfo bb_emlrtBCI = { -1, -1, 90, 35, "ind", "extract_notes",
  "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m", 0 };

static emlrtBCInfo cb_emlrtBCI = { -1, -1, 90, 16, "ind", "extract_notes",
  "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m", 0 };

static emlrtBCInfo db_emlrtBCI = { -1, -1, 87, 39, "ind", "extract_notes",
  "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m", 0 };

static emlrtBCInfo eb_emlrtBCI = { -1, -1, 87, 20, "ind", "extract_notes",
  "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m", 0 };

static emlrtBCInfo fb_emlrtBCI = { -1, -1, 85, 39, "ind", "extract_notes",
  "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m", 0 };

static emlrtBCInfo gb_emlrtBCI = { -1, -1, 85, 20, "ind", "extract_notes",
  "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m", 0 };

static emlrtBCInfo hb_emlrtBCI = { -1, -1, 35, 13, "ind", "extract_notes",
  "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m", 0 };

static emlrtBCInfo ib_emlrtBCI = { 1, 10, 202, 30, "staffs", "extract_notes",
  "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m", 0 };

static emlrtBCInfo jb_emlrtBCI = { 1, 10, 200, 30, "staffs", "extract_notes",
  "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m", 0 };

static emlrtBCInfo kb_emlrtBCI = { -1, -1, 133, 36, "chunk_centers",
  "extract_notes", "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m",
  0 };

static emlrtBCInfo lb_emlrtBCI = { -1, -1, 159, 39, "chunk_centers",
  "extract_notes", "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m",
  0 };

static emlrtBCInfo mb_emlrtBCI = { -1, -1, 159, 91, "chunk_centers",
  "extract_notes", "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m",
  0 };

static emlrtBCInfo nb_emlrtBCI = { -1, -1, 160, 94, "chunk_centers",
  "extract_notes", "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m",
  0 };

static emlrtBCInfo ob_emlrtBCI = { 1, 216, 160, 28, "blank", "extract_notes",
  "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m", 0 };

static emlrtDCInfo j_emlrtDCI = { 160, 28, "extract_notes",
  "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m", 1 };

static emlrtBCInfo pb_emlrtBCI = { 1, 216, 167, 40, "blank", "extract_notes",
  "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m", 0 };

static emlrtDCInfo k_emlrtDCI = { 167, 40, "extract_notes",
  "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m", 1 };

static emlrtBCInfo qb_emlrtBCI = { -1, -1, 167, 54, "chunk_centers",
  "extract_notes", "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m",
  0 };

static emlrtBCInfo rb_emlrtBCI = { 1, 762, 167, 59, "blank", "extract_notes",
  "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m", 0 };

static emlrtDCInfo l_emlrtDCI = { 167, 59, "extract_notes",
  "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m", 1 };

static emlrtBCInfo sb_emlrtBCI = { -1, -1, 167, 73, "chunk_centers",
  "extract_notes", "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m",
  0 };

static emlrtBCInfo tb_emlrtBCI = { -1, -1, 168, 49, "chunk_centers",
  "extract_notes", "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m",
  0 };

static emlrtBCInfo ub_emlrtBCI = { -1, -1, 168, 71, "chunk_centers",
  "extract_notes", "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m",
  0 };

static emlrtBCInfo vb_emlrtBCI = { -1, -1, 169, 43, "chunk_centers",
  "extract_notes", "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m",
  0 };

static emlrtBCInfo wb_emlrtBCI = { -1, -1, 169, 95, "chunk_centers",
  "extract_notes", "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m",
  0 };

static emlrtBCInfo xb_emlrtBCI = { -1, -1, 170, 98, "chunk_centers",
  "extract_notes", "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m",
  0 };

static emlrtBCInfo yb_emlrtBCI = { 1, 216, 170, 32, "blank", "extract_notes",
  "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m", 0 };

static emlrtDCInfo m_emlrtDCI = { 170, 32, "extract_notes",
  "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m", 1 };

static emlrtBCInfo ac_emlrtBCI = { -1, -1, 174, 53, "chunk_centers",
  "extract_notes", "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m",
  0 };

static emlrtBCInfo bc_emlrtBCI = { -1, -1, 174, 73, "chunk_centers",
  "extract_notes", "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m",
  0 };

static emlrtBCInfo cc_emlrtBCI = { -1, -1, 172, 53, "chunk_centers",
  "extract_notes", "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m",
  0 };

static emlrtBCInfo dc_emlrtBCI = { -1, -1, 172, 73, "chunk_centers",
  "extract_notes", "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m",
  0 };

static emlrtBCInfo ec_emlrtBCI = { -1, -1, 166, 49, "chunk_centers",
  "extract_notes", "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m",
  0 };

static emlrtBCInfo fc_emlrtBCI = { -1, -1, 166, 69, "chunk_centers",
  "extract_notes", "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m",
  0 };

static emlrtBCInfo gc_emlrtBCI = { -1, -1, 164, 49, "chunk_centers",
  "extract_notes", "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m",
  0 };

static emlrtBCInfo hc_emlrtBCI = { -1, -1, 164, 69, "chunk_centers",
  "extract_notes", "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m",
  0 };

static emlrtBCInfo ic_emlrtBCI = { -1, -1, 162, 49, "chunk_centers",
  "extract_notes", "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m",
  0 };

static emlrtBCInfo jc_emlrtBCI = { -1, -1, 162, 69, "chunk_centers",
  "extract_notes", "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m",
  0 };

static emlrtBCInfo kc_emlrtBCI = { -1, -1, 143, 27, "chunk_centers",
  "extract_notes", "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m",
  0 };

static emlrtBCInfo lc_emlrtBCI = { -1, -1, 143, 49, "chunk_centers",
  "extract_notes", "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m",
  0 };

static emlrtBCInfo mc_emlrtBCI = { -1, -1, 146, 17, "sort_ind", "extract_notes",
  "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m", 0 };

static emlrtBCInfo nc_emlrtBCI = { -1, -1, 146, 31, "sort_ind", "extract_notes",
  "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m", 0 };

static emlrtBCInfo oc_emlrtBCI = { -1, -1, 149, 17, "extras", "extract_notes",
  "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m", 0 };

static emlrtBCInfo pc_emlrtBCI = { -1, -1, 147, 17, "extras", "extract_notes",
  "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m", 0 };

static emlrtBCInfo qc_emlrtBCI = { -1, -1, 144, 13, "extras", "extract_notes",
  "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m", 0 };

static emlrtBCInfo rc_emlrtBCI = { -1, -1, 79, 15, "ind", "extract_notes",
  "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m", 0 };

static emlrtBCInfo sc_emlrtBCI = { -1, -1, 80, 15, "ind", "extract_notes",
  "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m", 0 };

static emlrtBCInfo tc_emlrtBCI = { 1, 8, 98, 13, "staff_heights",
  "extract_notes", "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m",
  0 };

static emlrtBCInfo uc_emlrtBCI = { 1, 216, 83, 16, "im", "extract_notes",
  "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m", 0 };

static emlrtBCInfo vc_emlrtBCI = { 1, 216, 89, 19, "im", "extract_notes",
  "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m", 0 };

static emlrtBCInfo wc_emlrtBCI = { 1, 216, 84, 19, "im", "extract_notes",
  "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m", 0 };

static emlrtBCInfo xc_emlrtBCI = { -1, -1, 44, 9, "ind", "extract_notes",
  "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m", 0 };

static emlrtBCInfo yc_emlrtBCI = { -1, -1, 44, 19, "ind", "extract_notes",
  "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m", 0 };

static emlrtBCInfo ad_emlrtBCI = { -1, -1, 55, 33, "ind", "extract_notes",
  "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m", 0 };

static emlrtBCInfo bd_emlrtBCI = { -1, -1, 56, 9, "lines", "extract_notes",
  "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m", 0 };

static emlrtBCInfo cd_emlrtBCI = { 1, 10, 51, 9, "staffs", "extract_notes",
  "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m", 0 };

static emlrtBCInfo dd_emlrtBCI = { -1, -1, 51, 21, "ind", "extract_notes",
  "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m", 0 };

static emlrtBCInfo ed_emlrtBCI = { -1, -1, 52, 9, "lines", "extract_notes",
  "/Users/vanessacolihan/Documents/MATLAB/sd/extract_notes.m", 0 };

static emlrtRTEInfo ob_emlrtRTEI = { 77, 27, "eml_null_assignment",
  "/Applications/MATLAB_R2015a.app/toolbox/eml/lib/matlab/eml/eml_null_assignment.m"
};

static emlrtRTEInfo pb_emlrtRTEI = { 278, 1, "eml_null_assignment",
  "/Applications/MATLAB_R2015a.app/toolbox/eml/lib/matlab/eml/eml_null_assignment.m"
};

/* Function Declarations */
static void eml_null_assignment(const emlrtStack *sp, emxArray_real_T *x, const
  emxArray_boolean_T *idx);

/* Function Definitions */
static void eml_null_assignment(const emlrtStack *sp, emxArray_real_T *x, const
  emxArray_boolean_T *idx)
{
  int32_T k;
  int32_T nrowx;
  int32_T nrows;
  boolean_T overflow;
  int32_T i;
  int32_T j;
  emxArray_real_T *b_x;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  st.site = &wc_emlrtRSI;
  k = idx->size[0];
  while ((k >= 1) && (!idx->data[k - 1])) {
    k--;
  }

  if (k <= x->size[0]) {
  } else {
    emlrtErrorWithMessageIdR2012b(&st, &ob_emlrtRTEI,
      "MATLAB:subsdeldimmismatch", 0);
  }

  st.site = &xc_emlrtRSI;
  nrowx = x->size[0];
  b_st.site = &yc_emlrtRSI;
  nrows = 0;
  c_st.site = &bd_emlrtRSI;
  if (1 > idx->size[0]) {
    overflow = false;
  } else {
    overflow = (idx->size[0] > 2147483646);
  }

  if (overflow) {
    d_st.site = &bb_emlrtRSI;
    check_forloop_overflow_error(&d_st);
  }

  for (k = 1; k <= idx->size[0]; k++) {
    nrows += idx->data[k - 1];
  }

  nrows = x->size[0] - nrows;
  i = 0;
  b_st.site = &ad_emlrtRSI;
  if (1 > x->size[0]) {
    overflow = false;
  } else {
    overflow = (x->size[0] > 2147483646);
  }

  if (overflow) {
    c_st.site = &bb_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }

  for (k = 1; k <= nrowx; k++) {
    if ((k > idx->size[0]) || (!idx->data[k - 1])) {
      for (j = 0; j < 2; j++) {
        x->data[i + x->size[0] * j] = x->data[(k + x->size[0] * j) - 1];
      }

      i++;
    }
  }

  if (nrows <= nrowx) {
  } else {
    emlrtErrorWithMessageIdR2012b(&st, &pb_emlrtRTEI,
      "Coder:builtins:AssertionFailed", 0);
  }

  if (1 > nrows) {
    nrows = 0;
  }

  emxInit_real_T(&st, &b_x, 2, &v_emlrtRTEI, true);
  i = b_x->size[0] * b_x->size[1];
  b_x->size[0] = nrows;
  b_x->size[1] = 2;
  emxEnsureCapacity(&st, (emxArray__common *)b_x, i, (int32_T)sizeof(real_T),
                    &v_emlrtRTEI);
  for (i = 0; i < 2; i++) {
    for (j = 0; j < nrows; j++) {
      b_x->data[j + b_x->size[0] * i] = x->data[j + x->size[0] * i];
    }
  }

  i = x->size[0] * x->size[1];
  x->size[0] = b_x->size[0];
  x->size[1] = 2;
  emxEnsureCapacity(&st, (emxArray__common *)x, i, (int32_T)sizeof(real_T),
                    &v_emlrtRTEI);
  for (i = 0; i < 2; i++) {
    nrows = b_x->size[0];
    for (j = 0; j < nrows; j++) {
      x->data[j + x->size[0] * i] = b_x->data[j + b_x->size[0] * i];
    }
  }

  emxFree_real_T(&b_x);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

void extract_notes(extract_notesStackData *SD, const emlrtStack *sp, const
                   uint8_T im[493776], real_T threshold, real_T num_find, real_T
                   radius, emxArray_char_T *notes)
{
  int32_T i;
  int32_T j;
  int32_T i0;
  real_T tmp[216];
  real_T std_val;
  real_T threshold_val;
  int32_T idx;
  int32_T ii_data[216];
  int32_T ixstart;
  boolean_T exitg2;
  boolean_T guard1 = false;
  int32_T itmp;
  uint8_T ind_data[216];
  int32_T i1;
  real_T staffs[10];
  real_T num;
  real_T staff_num[10];
  int32_T b_i;
  int32_T i2;
  int32_T b_j;
  int32_T c_i;
  int32_T d_i;
  real_T note_threshold;
  real_T lines_passed;
  real_T staff_heights[8];
  int32_T h;
  int32_T s;
  int32_T i3;
  int32_T above_s;
  int32_T i4;
  real_T below_s;
  int32_T x;
  int32_T i5;
  int32_T i6;
  int32_T i7;
  uint8_T y;
  int32_T i8;
  int32_T b_h;
  emxArray_real_T *centers;
  real_T avg_staff_height;
  int32_T stanza;
  emxArray_uint8_T *im_chunk;
  emxArray_real_T *edges;
  emxArray_real_T *chunk_centers;
  emxArray_boolean_T *extras;
  emxArray_real_T *unusedU0;
  emxArray_int32_T *iidx;
  emxArray_uint8_T *blank;
  emxArray_uint8_T *b_blank;
  emxArray_real_T *b_chunk_centers;
  emxArray_real_T *b_centers;
  real_T chunk_end;
  real_T d0;
  int32_T i9;
  int32_T i10;
  int32_T ii[2];
  int32_T i11;
  int32_T c;
  int32_T i12;
  int32_T b_idx;
  int32_T i13;
  int32_T i14;
  int32_T c_idx;
  int32_T i15;
  int32_T i16;
  int32_T b_c;
  int32_T i17;
  uint8_T blank_data[216];
  int32_T c_c;
  int32_T blank_size[1];
  emxArray_uint8_T b_blank_data;
  real_T top;
  real_T c_chunk_centers;
  int32_T d_c;
  real_T d1;
  int32_T i18;
  real_T bottom;
  int32_T e_c;
  int32_T f_c;
  real_T d_chunk_centers;
  int32_T g_c;
  int32_T h_c;
  int32_T i_c;
  int32_T j_c;
  int32_T k_c;
  int32_T l_c;
  int32_T i19;
  int32_T i20;
  int32_T m_c;
  int32_T n_c;
  int32_T o_c;
  int32_T i21;
  uint8_T c_blank_data[216];
  int32_T p_c;
  int32_T b_blank_size[1];
  emxArray_uint8_T d_blank_data;
  int32_T q_c;
  int32_T i22;
  int32_T r_c;
  int32_T s_c;
  int32_T t_c;
  int32_T u_c;
  int32_T i23;
  int32_T b_ii[2];
  real_T full_staffs[26];
  char_T full_scale[52];
  int32_T full_start;
  int32_T staff_start;
  int32_T l;
  int32_T p;
  int32_T b_l;
  int32_T c_l;
  emxArray_real_T *r0;
  real_T c_centers;
  real_T b_full_staffs[26];
  real_T varargin_1[26];
  real_T mtmp;
  boolean_T exitg1;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);

  /*  radius = 5.4; */
  /*  num_find = 19; */
  /*  threshold = 155; */
  /*  im = imread('rowrowbt_mod3.png'); */
  st.site = &emlrtRSI;
  rgb2gray(&st, im, SD->f6.b_im);
  i = 0;
  while (i < 216) {
    j = 0;
    while (j < 762) {
      if (SD->f6.b_im[i + 216 * j] > 240) {
        SD->f6.b_im[i + 216 * j] = MAX_uint8_T;
      }

      j++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    i++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  /* %  */
  for (i0 = 0; i0 < 164592; i0++) {
    SD->f6.im[i0] = SD->f6.b_im[i0];
  }

  sum(SD->f6.im, tmp);
  st.site = &b_emlrtRSI;
  std_val = b_std(&st, tmp);
  threshold_val = b_sum(tmp) / 216.0 - 2.0 * std_val;
  idx = 0;
  ixstart = 1;
  exitg2 = false;
  while ((!exitg2) && (ixstart < 217)) {
    guard1 = false;
    if (tmp[ixstart - 1] < threshold_val) {
      idx++;
      ii_data[idx - 1] = ixstart;
      if (idx >= 216) {
        exitg2 = true;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }

    if (guard1) {
      ixstart++;
    }
  }

  if (1 > idx) {
    itmp = 0;
  } else {
    itmp = idx;
  }

  for (i0 = 0; i0 < itmp; i0++) {
    ind_data[i0] = (uint8_T)ii_data[i0];
  }

  /* actually delete the staffs */
  if (1 > idx) {
    ixstart = 0;
  } else {
    ixstart = idx;
  }

  for (i0 = 0; i0 < itmp; i0++) {
    ii_data[i0] = ind_data[i0];
  }

  for (i0 = 0; i0 < 762; i0++) {
    for (i1 = 0; i1 < ixstart; i1++) {
      SD->f6.b_im[(ii_data[i1] + 216 * i0) - 1] = MAX_uint8_T;
    }
  }

  /* %  */
  /* calculate staff lines */
  memset(&staffs[0], 0, 10U * sizeof(real_T));
  emlrtDynamicBoundsCheckR2012b(1, 1, itmp, &hb_emlrtBCI, sp);
  staffs[0] = ind_data[0];
  j = 0;
  num = 1.0;
  i0 = (uint8_T)itmp;
  emlrtDynamicBoundsCheckR2012b(1, 1, i0, &emlrtBCI, sp);
  memset(&staff_num[0], 0, 10U * sizeof(real_T));
  staff_num[0] = 1.0;
  i = 2;
  while (i - 2 <= itmp - 2) {
    i0 = i - 1;
    if ((i >= 1) && (i < itmp)) {
      b_i = i;
    } else {
      b_i = emlrtDynamicBoundsCheckR2012b(i, 1, itmp, &xc_emlrtBCI, sp);
    }

    if ((i0 >= 1) && (i0 < itmp)) {
      i2 = i0;
    } else {
      i2 = emlrtDynamicBoundsCheckR2012b(i0, 1, itmp, &yc_emlrtBCI, sp);
    }

    if (ind_data[b_i - 1] > ind_data[i2 - 1] + 1) {
      /* end line deletion */
      staffs[j] = muDoubleScalarFloor(staffs[j] / num);
      num = 1.0;
      j++;
      if ((j + 1 >= 1) && (j + 1 < 10)) {
        b_j = j + 1;
      } else {
        b_j = emlrtDynamicBoundsCheckR2012b(j + 1, 1, 10, &cd_emlrtBCI, sp);
      }

      if ((i >= 1) && (i < itmp)) {
        c_i = i;
      } else {
        c_i = emlrtDynamicBoundsCheckR2012b(i, 1, itmp, &dd_emlrtBCI, sp);
      }

      staffs[b_j - 1] = ind_data[c_i - 1];

      /* first line */
      i0 = (uint8_T)itmp;
      emlrtDynamicBoundsCheckR2012b(i, 1, i0, &ed_emlrtBCI, sp);
      staff_num[j]++;
    } else {
      if ((i >= 1) && (i < itmp)) {
        d_i = i;
      } else {
        d_i = emlrtDynamicBoundsCheckR2012b(i, 1, itmp, &ad_emlrtBCI, sp);
      }

      staffs[j] += (real_T)ind_data[d_i - 1];

      /* there was a line deleted above this */
      i0 = (uint8_T)itmp;
      emlrtDynamicBoundsCheckR2012b(i, 1, i0, &bd_emlrtBCI, sp);
      staff_num[j]++;
      num++;
      if (i == itmp) {
        /* last */
        staffs[j] = muDoubleScalarFloor(staffs[j] / num);
      }
    }

    i++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  /* % */
  /* GAP STITCHING: */
  /* lines array contains index of staffs that were removed, matches ind array */
  /* staff_num tells number of horiz lines deleted around this staff */
  for (i0 = 0; i0 < 164592; i0++) {
    SD->f6.im[i0] = SD->f6.b_im[i0];
  }

  st.site = &c_emlrtRSI;
  note_threshold = muDoubleScalarFloor(c_sum(SD->f6.b_im) / 164592.0) - 2.0 *
    c_std(&st, SD->f6.im);
  lines_passed = 1.0;

  /* will give current index of ind array (y pos of all staff part lines detected) */
  memset(&staff_heights[0], 0, sizeof(real_T) << 3);
  h = 1;
  s = 0;
  while (s < 10) {
    /* y values of staffs. s = index of staffs AKA staff number */
    i0 = (int32_T)lines_passed;
    if ((i0 >= 1) && (i0 < itmp)) {
      i3 = i0;
    } else {
      i3 = emlrtDynamicBoundsCheckR2012b(i0, 1, itmp, &rc_emlrtBCI, sp);
    }

    above_s = ind_data[i3 - 1] - 1;
    i0 = (int32_T)lines_passed;
    if ((i0 >= 1) && (i0 < itmp)) {
      i4 = i0;
    } else {
      i4 = emlrtDynamicBoundsCheckR2012b(i0, 1, itmp, &sc_emlrtBCI, sp);
    }

    below_s = (real_T)ind_data[i4 - 1] + staff_num[s];

    /* ind(lines_passed) + staff_num(s)-1 + 1; */
    x = 0;
    while (x < 762) {
      /* x pos of image */
      i0 = above_s;
      if (i0 >= 1) {
        i5 = i0;
      } else {
        i5 = emlrtDynamicBoundsCheckR2012b(i0, 1, 216, &uc_emlrtBCI, sp);
      }

      if (SD->f6.b_im[(i5 + 216 * x) - 1] < note_threshold) {
        i0 = (int32_T)below_s;
        if ((i0 >= 1) && (i0 < 216)) {
          i6 = i0;
        } else {
          i6 = emlrtDynamicBoundsCheckR2012b(i0, 1, 216, &wc_emlrtBCI, sp);
        }

        if (SD->f6.b_im[(i6 + 216 * x) - 1] < note_threshold) {
          i0 = (int32_T)lines_passed;
          emlrtDynamicBoundsCheckR2012b(i0, 1, itmp, &gb_emlrtBCI, sp);
          i0 = (int32_T)((lines_passed + staff_num[s]) - 1.0);
          emlrtDynamicBoundsCheckR2012b(i0, 1, itmp, &fb_emlrtBCI, sp);
          if (ind_data[(int32_T)lines_passed - 1] > ind_data[(int32_T)
              ((lines_passed + staff_num[s]) - 1.0) - 1]) {
            i0 = 0;
            i1 = 0;
          } else {
            i0 = ind_data[(int32_T)lines_passed - 1] - 1;
            i1 = ind_data[(int32_T)((lines_passed + staff_num[s]) - 1.0) - 1];
          }

          i7 = (int32_T)((uint32_T)SD->f6.b_im[(above_s + 216 * x) - 1] +
                         SD->f6.b_im[((int32_T)below_s + 216 * x) - 1]);
          if ((uint32_T)i7 > 255U) {
            i7 = 255;
          }

          i7 = (int32_T)muDoubleScalarRound((real_T)i7 / 2.0);
          y = (uint8_T)i7;
          idx = i1 - i0;
          for (i1 = 0; i1 < idx; i1++) {
            SD->f6.b_im[(i0 + i1) + 216 * x] = y;
          }
        } else {
          if (SD->f6.b_im[(above_s + 216 * x) - 1] < note_threshold) {
            i0 = (int32_T)lines_passed;
            emlrtDynamicBoundsCheckR2012b(i0, 1, itmp, &eb_emlrtBCI, sp);
            i0 = (int32_T)((lines_passed + staff_num[s]) - 1.0);
            emlrtDynamicBoundsCheckR2012b(i0, 1, itmp, &db_emlrtBCI, sp);
            if (ind_data[(int32_T)lines_passed - 1] > ind_data[(int32_T)
                ((lines_passed + staff_num[s]) - 1.0) - 1]) {
              i0 = 0;
              i1 = 0;
            } else {
              i0 = ind_data[(int32_T)lines_passed - 1] - 1;
              i1 = ind_data[(int32_T)((lines_passed + staff_num[s]) - 1.0) - 1];
            }

            i7 = (int32_T)muDoubleScalarRound((real_T)SD->f6.b_im[(above_s + 216
              * x) - 1] / 2.0);
            y = (uint8_T)i7;
            idx = i1 - i0;
            for (i1 = 0; i1 < idx; i1++) {
              SD->f6.b_im[(i0 + i1) + 216 * x] = y;
            }
          }
        }
      } else {
        i0 = (int32_T)below_s;
        if ((i0 >= 1) && (i0 < 216)) {
          i8 = i0;
        } else {
          i8 = emlrtDynamicBoundsCheckR2012b(i0, 1, 216, &vc_emlrtBCI, sp);
        }

        if (SD->f6.b_im[(i8 + 216 * x) - 1] < note_threshold) {
          i0 = (int32_T)lines_passed;
          emlrtDynamicBoundsCheckR2012b(i0, 1, itmp, &cb_emlrtBCI, sp);
          i0 = (int32_T)((lines_passed + staff_num[s]) - 1.0);
          emlrtDynamicBoundsCheckR2012b(i0, 1, itmp, &bb_emlrtBCI, sp);
          if (ind_data[(int32_T)lines_passed - 1] > ind_data[(int32_T)
              ((lines_passed + staff_num[s]) - 1.0) - 1]) {
            i0 = 0;
            i1 = 0;
          } else {
            i0 = ind_data[(int32_T)lines_passed - 1] - 1;
            i1 = ind_data[(int32_T)((lines_passed + staff_num[s]) - 1.0) - 1];
          }

          i7 = (int32_T)muDoubleScalarRound((real_T)SD->f6.b_im[((int32_T)
            below_s + 216 * x) - 1] / 2.0);
          y = (uint8_T)i7;
          idx = i1 - i0;
          for (i1 = 0; i1 < idx; i1++) {
            SD->f6.b_im[(i0 + i1) + 216 * x] = y;
          }
        }
      }

      x++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    lines_passed += staff_num[s];
    if ((1 + s > 1) && (b_mod(1.0 + (real_T)s, 6.0) != 0.0)) {
      if ((h >= 1) && (h < 8)) {
        b_h = h;
      } else {
        b_h = emlrtDynamicBoundsCheckR2012b(h, 1, 8, &tc_emlrtBCI, sp);
      }

      staff_heights[b_h - 1] = staffs[s] - staffs[s - 1];
      h++;
    }

    s++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxInit_real_T(sp, &centers, 2, &d_emlrtRTEI, true);
  avg_staff_height = d_sum(staff_heights) / 8.0;

  /* % */
  /* do work by chunks in this section */
  /*  radius = 5.4; */
  /*  num = 19;  */
  /* %%%%%%%%%%%%% TO DO: preallocate centers array  */
  i0 = centers->size[0] * centers->size[1];
  centers->size[0] = 0;
  centers->size[1] = 2;
  emxEnsureCapacity(sp, (emxArray__common *)centers, i0, (int32_T)sizeof(real_T),
                    &c_emlrtRTEI);

  /* remove vertical lines by stanza, using process_stanza() function. */
  stanza = 0;
  emxInit_uint8_T(sp, &im_chunk, 2, &e_emlrtRTEI, true);
  emxInit_real_T(sp, &edges, 2, &f_emlrtRTEI, true);
  emxInit_real_T(sp, &chunk_centers, 2, &g_emlrtRTEI, true);
  emxInit_boolean_T(sp, &extras, 1, &h_emlrtRTEI, true);
  b_emxInit_real_T(sp, &unusedU0, 1, &c_emlrtRTEI, true);
  emxInit_int32_T(sp, &iidx, 1, &c_emlrtRTEI, true);
  b_emxInit_uint8_T(sp, &blank, 1, &c_emlrtRTEI, true);
  b_emxInit_uint8_T(sp, &b_blank, 1, &c_emlrtRTEI, true);
  emxInit_real_T(sp, &b_chunk_centers, 2, &c_emlrtRTEI, true);
  emxInit_real_T(sp, &b_centers, 2, &c_emlrtRTEI, true);
  while (stanza < 2) {
    memset(&SD->f6.blank[0], 255, 164592U * sizeof(uint8_T));
    chunk_end = staffs[4 + stanza * 5] + 2.0 * avg_staff_height;
    if (staffs[stanza * 5] > chunk_end) {
      i0 = 0;
      i1 = 0;
    } else {
      d0 = staffs[stanza * 5];
      if (d0 == (int32_T)muDoubleScalarFloor(d0)) {
        i0 = (int32_T)d0;
      } else {
        i0 = (int32_T)emlrtIntegerCheckR2012b(d0, &i_emlrtDCI, sp);
      }

      if ((i0 >= 1) && (i0 < 216)) {
        i9 = i0;
      } else {
        i9 = emlrtDynamicBoundsCheckR2012b(i0, 1, 216, &ab_emlrtBCI, sp);
      }

      i0 = i9 - 1;
      if (chunk_end == (int32_T)muDoubleScalarFloor(chunk_end)) {
        i1 = (int32_T)chunk_end;
      } else {
        i1 = (int32_T)emlrtIntegerCheckR2012b(chunk_end, &i_emlrtDCI, sp);
      }

      if ((i1 >= 1) && (i1 < 216)) {
      } else {
        i1 = emlrtDynamicBoundsCheckR2012b(i1, 1, 216, &ab_emlrtBCI, sp);
      }
    }

    i7 = im_chunk->size[0] * im_chunk->size[1];
    im_chunk->size[0] = i1 - i0;
    im_chunk->size[1] = 762;
    emxEnsureCapacity(sp, (emxArray__common *)im_chunk, i7, (int32_T)sizeof
                      (uint8_T), &c_emlrtRTEI);
    for (i7 = 0; i7 < 762; i7++) {
      itmp = i1 - i0;
      for (idx = 0; idx < itmp; idx++) {
        im_chunk->data[idx + im_chunk->size[0] * i7] = SD->f6.b_im[(i0 + idx) +
          216 * i7];
      }
    }

    st.site = &d_emlrtRSI;
    process_stanza(&st, im_chunk);
    if (staffs[stanza * 5] > chunk_end) {
      i0 = 0;
      i1 = 0;
    } else {
      d0 = staffs[stanza * 5];
      if (d0 == (int32_T)muDoubleScalarFloor(d0)) {
        i0 = (int32_T)d0;
      } else {
        i0 = (int32_T)emlrtIntegerCheckR2012b(d0, &h_emlrtDCI, sp);
      }

      if ((i0 >= 1) && (i0 < 216)) {
        i10 = i0;
      } else {
        i10 = emlrtDynamicBoundsCheckR2012b(i0, 1, 216, &y_emlrtBCI, sp);
      }

      i0 = i10 - 1;
      if (chunk_end == (int32_T)muDoubleScalarFloor(chunk_end)) {
        i1 = (int32_T)chunk_end;
      } else {
        i1 = (int32_T)emlrtIntegerCheckR2012b(chunk_end, &h_emlrtDCI, sp);
      }

      if ((i1 >= 1) && (i1 < 216)) {
      } else {
        i1 = emlrtDynamicBoundsCheckR2012b(i1, 1, 216, &y_emlrtBCI, sp);
      }
    }

    itmp = i1 - i0;
    for (i7 = 0; i7 < itmp; i7++) {
      ii_data[i7] = i0 + i7;
    }

    ii[0] = i1 - i0;
    ii[1] = 762;
    emlrtSubAssignSizeCheckR2012b(ii, 2, *(int32_T (*)[2])im_chunk->size, 2,
      &b_emlrtECI, sp);
    for (i0 = 0; i0 < 762; i0++) {
      itmp = im_chunk->size[0];
      for (i1 = 0; i1 < itmp; i1++) {
        SD->f6.blank[ii_data[i1] + 216 * i0] = im_chunk->data[i1 +
          im_chunk->size[0] * i0];
      }
    }

    st.site = &e_emlrtRSI;
    detectEdges_removeLines(SD, &st, SD->f6.blank, threshold, edges);
    st.site = &f_emlrtRSI;
    detectCircles(SD, &st, edges, radius, num_find, chunk_centers);

    /* sort by x */
    st.site = &g_emlrtRSI;
    itmp = chunk_centers->size[0];
    i0 = unusedU0->size[0];
    unusedU0->size[0] = itmp;
    emxEnsureCapacity(&st, (emxArray__common *)unusedU0, i0, (int32_T)sizeof
                      (real_T), &c_emlrtRTEI);
    for (i0 = 0; i0 < itmp; i0++) {
      unusedU0->data[i0] = chunk_centers->data[i0];
    }

    b_st.site = &lc_emlrtRSI;
    c_eml_sort(&b_st, unusedU0, iidx);
    i0 = unusedU0->size[0];
    unusedU0->size[0] = iidx->size[0];
    emxEnsureCapacity(&st, (emxArray__common *)unusedU0, i0, (int32_T)sizeof
                      (real_T), &c_emlrtRTEI);
    itmp = iidx->size[0];
    for (i0 = 0; i0 < itmp; i0++) {
      unusedU0->data[i0] = iidx->data[i0];
    }

    idx = chunk_centers->size[0];
    i0 = b_chunk_centers->size[0] * b_chunk_centers->size[1];
    b_chunk_centers->size[0] = unusedU0->size[0];
    b_chunk_centers->size[1] = 2;
    emxEnsureCapacity(sp, (emxArray__common *)b_chunk_centers, i0, (int32_T)
                      sizeof(real_T), &c_emlrtRTEI);
    for (i0 = 0; i0 < 2; i0++) {
      itmp = unusedU0->size[0];
      for (i1 = 0; i1 < itmp; i1++) {
        i7 = (int32_T)unusedU0->data[i1];
        if ((i7 >= 1) && (i7 < idx)) {
          i11 = i7;
        } else {
          i11 = emlrtDynamicBoundsCheckR2012b(i7, 1, idx, &kb_emlrtBCI, sp);
        }

        b_chunk_centers->data[i1 + b_chunk_centers->size[0] * i0] =
          chunk_centers->data[(i11 + chunk_centers->size[0] * i0) - 1];
      }
    }

    i0 = chunk_centers->size[0] * chunk_centers->size[1];
    chunk_centers->size[0] = b_chunk_centers->size[0];
    chunk_centers->size[1] = 2;
    emxEnsureCapacity(sp, (emxArray__common *)chunk_centers, i0, (int32_T)sizeof
                      (real_T), &c_emlrtRTEI);
    for (i0 = 0; i0 < 2; i0++) {
      itmp = b_chunk_centers->size[0];
      for (i1 = 0; i1 < itmp; i1++) {
        chunk_centers->data[i1 + chunk_centers->size[0] * i0] =
          b_chunk_centers->data[i1 + b_chunk_centers->size[0] * i0];
      }
    }

    /* post processing of this chunk */
    /* first, remove the random perimeter circles that tend to pop up */
    itmp = chunk_centers->size[0];
    i0 = extras->size[0];
    extras->size[0] = itmp;
    emxEnsureCapacity(sp, (emxArray__common *)extras, i0, (int32_T)sizeof
                      (boolean_T), &c_emlrtRTEI);
    for (i0 = 0; i0 < itmp; i0++) {
      extras->data[i0] = (chunk_centers->data[i0] > 762.0 - radius);
    }

    st.site = &h_emlrtRSI;
    eml_null_assignment(&st, chunk_centers, extras);
    itmp = chunk_centers->size[0];
    i0 = extras->size[0];
    extras->size[0] = itmp;
    emxEnsureCapacity(sp, (emxArray__common *)extras, i0, (int32_T)sizeof
                      (boolean_T), &c_emlrtRTEI);
    for (i0 = 0; i0 < itmp; i0++) {
      extras->data[i0] = (chunk_centers->data[i0 + chunk_centers->size[0]] >
                          216.0 - radius);
    }

    st.site = &i_emlrtRSI;
    eml_null_assignment(&st, chunk_centers, extras);
    i0 = extras->size[0];
    extras->size[0] = chunk_centers->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)extras, i0, (int32_T)sizeof
                      (boolean_T), &c_emlrtRTEI);
    itmp = chunk_centers->size[0];
    for (i0 = 0; i0 < itmp; i0++) {
      extras->data[i0] = false;
    }

    /* check every circle c: */
    c = 0;
    while (c <= (int32_T)((real_T)chunk_centers->size[0] + -1.0) - 1) {
      i0 = chunk_centers->size[0];
      i1 = (int32_T)(2.0 + (real_T)c);
      i7 = chunk_centers->size[0];
      idx = (int32_T)((2.0 + (real_T)c) - 1.0);
      if ((i1 >= 1) && (i1 < i0)) {
        i12 = i1;
      } else {
        i12 = emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &kc_emlrtBCI, sp);
      }

      if ((idx >= 1) && (idx < i7)) {
        b_idx = idx;
      } else {
        b_idx = emlrtDynamicBoundsCheckR2012b(idx, 1, i7, &lc_emlrtBCI, sp);
      }

      if (chunk_centers->data[i12 - 1] == chunk_centers->data[b_idx - 1]) {
        i0 = extras->size[0];
        i1 = (int32_T)(2.0 + (real_T)c);
        if ((i1 >= 1) && (i1 < i0)) {
          i13 = i1;
        } else {
          i13 = emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &qc_emlrtBCI, sp);
        }

        extras->data[i13 - 1] = true;
      } else {
        i0 = chunk_centers->size[0];
        i1 = (int32_T)(2.0 + (real_T)c);
        emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &x_emlrtBCI, sp);
        i0 = chunk_centers->size[0];
        i1 = (int32_T)((2.0 + (real_T)c) - 1.0);
        emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &w_emlrtBCI, sp);
        if (muDoubleScalarAbs(chunk_centers->data[c + 1] - chunk_centers->data
                              [(int32_T)((2.0 + (real_T)c) - 1.0) - 1]) < radius
            * 2.0) {
          i0 = unusedU0->size[0];
          i1 = (int32_T)(2.0 + (real_T)c);
          i7 = unusedU0->size[0];
          idx = (int32_T)((2.0 + (real_T)c) - 1.0);
          if ((i1 >= 1) && (i1 < i0)) {
            i14 = i1;
          } else {
            i14 = emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &mc_emlrtBCI, sp);
          }

          if ((idx >= 1) && (idx < i7)) {
            c_idx = idx;
          } else {
            c_idx = emlrtDynamicBoundsCheckR2012b(idx, 1, i7, &nc_emlrtBCI, sp);
          }

          if (unusedU0->data[i14 - 1] < unusedU0->data[c_idx - 1]) {
            i0 = extras->size[0];
            i1 = (int32_T)((2.0 + (real_T)c) - 1.0);
            if ((i1 >= 1) && (i1 < i0)) {
              i15 = i1;
            } else {
              i15 = emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &pc_emlrtBCI, sp);
            }

            extras->data[i15 - 1] = true;
          } else {
            i0 = extras->size[0];
            i1 = (int32_T)(2.0 + (real_T)c);
            if ((i1 >= 1) && (i1 < i0)) {
              i16 = i1;
            } else {
              i16 = emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &oc_emlrtBCI, sp);
            }

            extras->data[i16 - 1] = true;
          }
        }
      }

      c++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    /* remove the circles we just flagged */
    st.site = &j_emlrtRSI;
    eml_null_assignment(&st, chunk_centers, extras);

    /* final post processing for individual circles */
    /* TODO: better benchmarks */
    i0 = chunk_centers->size[0];
    c = 1;
    while (c - 1 <= i0 - 1) {
      i1 = chunk_centers->size[0];
      if ((c >= 1) && (c < i1)) {
        b_c = c;
      } else {
        b_c = emlrtDynamicBoundsCheckR2012b(c, 1, i1, &lb_emlrtBCI, sp);
      }

      d0 = chunk_centers->data[(b_c + chunk_centers->size[0]) - 1] -
        muDoubleScalarFloor(radius);
      i1 = chunk_centers->size[0];
      i7 = (c - 1) + 1;
      emlrtDynamicBoundsCheckR2012b(i7, 1, i1, &v_emlrtBCI, sp);
      if (d0 > chunk_centers->data[(c + chunk_centers->size[0]) - 1]) {
        i1 = 0;
        i7 = 0;
      } else {
        if (d0 == (int32_T)muDoubleScalarFloor(d0)) {
          i1 = (int32_T)d0;
        } else {
          i1 = (int32_T)emlrtIntegerCheckR2012b(d0, &g_emlrtDCI, sp);
        }

        if ((i1 >= 1) && (i1 < 216)) {
          i17 = i1;
        } else {
          i17 = emlrtDynamicBoundsCheckR2012b(i1, 1, 216, &u_emlrtBCI, sp);
        }

        i1 = i17 - 1;
        d0 = chunk_centers->data[(c + chunk_centers->size[0]) - 1];
        if (d0 == (int32_T)muDoubleScalarFloor(d0)) {
          i7 = (int32_T)d0;
        } else {
          i7 = (int32_T)emlrtIntegerCheckR2012b(d0, &g_emlrtDCI, sp);
        }

        if ((i7 >= 1) && (i7 < 216)) {
        } else {
          i7 = emlrtDynamicBoundsCheckR2012b(i7, 1, 216, &u_emlrtBCI, sp);
        }
      }

      idx = chunk_centers->size[0];
      if ((c >= 1) && (c < idx)) {
        c_c = c;
      } else {
        c_c = emlrtDynamicBoundsCheckR2012b(c, 1, idx, &mb_emlrtBCI, sp);
      }

      d0 = chunk_centers->data[c_c - 1];
      if (d0 == (int32_T)muDoubleScalarFloor(d0)) {
        idx = (int32_T)d0;
      } else {
        idx = (int32_T)emlrtIntegerCheckR2012b(d0, &f_emlrtDCI, sp);
      }

      if ((idx >= 1) && (idx < 762)) {
      } else {
        idx = emlrtDynamicBoundsCheckR2012b(idx, 1, 762, &t_emlrtBCI, sp);
      }

      blank_size[0] = i7 - i1;
      itmp = i7 - i1;
      for (i7 = 0; i7 < itmp; i7++) {
        blank_data[i7] = SD->f6.blank[(i1 + i7) + 216 * (idx - 1)];
      }

      b_blank_data.data = (uint8_T *)&blank_data;
      b_blank_data.size = (int32_T *)&blank_size;
      b_blank_data.allocatedSize = 216;
      b_blank_data.numDimensions = 1;
      b_blank_data.canFreeData = false;
      st.site = &k_emlrtRSI;
      top = g_sum(&st, &b_blank_data);
      i1 = chunk_centers->size[0];
      i7 = (c - 1) + 1;
      emlrtDynamicBoundsCheckR2012b(i7, 1, i1, &s_emlrtBCI, sp);
      i1 = chunk_centers->size[0];
      i7 = (c - 1) + 1;
      emlrtDynamicBoundsCheckR2012b(i7, 1, i1, &r_emlrtBCI, sp);
      if (chunk_centers->data[(c + chunk_centers->size[0]) - 1] ==
          chunk_centers->data[(c + chunk_centers->size[0]) - 1]) {
      } else {
        emlrtErrorWithMessageIdR2012b(sp, &hb_emlrtRTEI,
          "EMLRT:runTime:RepeatedExprWithDifferentResultsInColonIndexing", 0);
      }

      c_chunk_centers = chunk_centers->data[(c + chunk_centers->size[0]) - 1];
      d0 = muDoubleScalarFloor(radius);
      i1 = chunk_centers->size[0];
      if ((c >= 1) && (c < i1)) {
        d_c = c;
      } else {
        d_c = emlrtDynamicBoundsCheckR2012b(c, 1, i1, &nb_emlrtBCI, sp);
      }

      d1 = chunk_centers->data[d_c - 1];
      if (d1 == (int32_T)muDoubleScalarFloor(d1)) {
        i1 = (int32_T)d1;
      } else {
        i1 = (int32_T)emlrtIntegerCheckR2012b(d1, &e_emlrtDCI, sp);
      }

      if ((i1 >= 1) && (i1 < 762)) {
        idx = i1;
      } else {
        idx = emlrtDynamicBoundsCheckR2012b(i1, 1, 762, &q_emlrtBCI, sp);
      }

      i1 = b_blank->size[0];
      b_blank->size[0] = (int32_T)d0 + 1;
      emxEnsureCapacity(sp, (emxArray__common *)b_blank, i1, (int32_T)sizeof
                        (uint8_T), &c_emlrtRTEI);
      itmp = (int32_T)d0;
      for (i1 = 0; i1 <= itmp; i1++) {
        d0 = c_chunk_centers + (real_T)i1;
        if (d0 == (int32_T)muDoubleScalarFloor(d0)) {
          i7 = (int32_T)d0;
        } else {
          i7 = (int32_T)emlrtIntegerCheckR2012b(d0, &j_emlrtDCI, sp);
        }

        if ((i7 >= 1) && (i7 < 216)) {
          i18 = i7;
        } else {
          i18 = emlrtDynamicBoundsCheckR2012b(i7, 1, 216, &ob_emlrtBCI, sp);
        }

        b_blank->data[i1] = SD->f6.blank[(i18 + 216 * (idx - 1)) - 1];
      }

      st.site = &l_emlrtRSI;
      bottom = g_sum(&st, b_blank);
      if (top - bottom < -900.0) {
        idx = chunk_centers->size[0];
        emlrtDynamicBoundsCheckR2012b(c, 1, idx, &p_emlrtBCI, sp);
        idx = chunk_centers->size[0];
        if ((c >= 1) && (c < idx)) {
          e_c = c;
        } else {
          e_c = emlrtDynamicBoundsCheckR2012b(c, 1, idx, &ic_emlrtBCI, sp);
        }

        c_chunk_centers = chunk_centers->data[e_c - 1];
        idx = chunk_centers->size[0];
        if ((c >= 1) && (c < idx)) {
          f_c = c;
        } else {
          f_c = emlrtDynamicBoundsCheckR2012b(c, 1, idx, &jc_emlrtBCI, sp);
        }

        d_chunk_centers = chunk_centers->data[(f_c + chunk_centers->size[0]) - 1];
        chunk_centers->data[c - 1] = c_chunk_centers;
        chunk_centers->data[(c + chunk_centers->size[0]) - 1] = d_chunk_centers
          - radius / 2.0;
      } else if (top - bottom < -500.0) {
        idx = chunk_centers->size[0];
        emlrtDynamicBoundsCheckR2012b(c, 1, idx, &o_emlrtBCI, sp);
        idx = chunk_centers->size[0];
        if ((c >= 1) && (c < idx)) {
          g_c = c;
        } else {
          g_c = emlrtDynamicBoundsCheckR2012b(c, 1, idx, &gc_emlrtBCI, sp);
        }

        c_chunk_centers = chunk_centers->data[g_c - 1];
        idx = chunk_centers->size[0];
        if ((c >= 1) && (c < idx)) {
          h_c = c;
        } else {
          h_c = emlrtDynamicBoundsCheckR2012b(c, 1, idx, &hc_emlrtBCI, sp);
        }

        d_chunk_centers = chunk_centers->data[(h_c + chunk_centers->size[0]) - 1];
        chunk_centers->data[c - 1] = c_chunk_centers;
        chunk_centers->data[(c + chunk_centers->size[0]) - 1] = d_chunk_centers
          - radius / 5.0;
      } else if (top - bottom > 900.0) {
        idx = chunk_centers->size[0];
        emlrtDynamicBoundsCheckR2012b(c, 1, idx, &n_emlrtBCI, sp);
        idx = chunk_centers->size[0];
        if ((c >= 1) && (c < idx)) {
          i_c = c;
        } else {
          i_c = emlrtDynamicBoundsCheckR2012b(c, 1, idx, &ec_emlrtBCI, sp);
        }

        c_chunk_centers = chunk_centers->data[i_c - 1];
        idx = chunk_centers->size[0];
        if ((c >= 1) && (c < idx)) {
          j_c = c;
        } else {
          j_c = emlrtDynamicBoundsCheckR2012b(c, 1, idx, &fc_emlrtBCI, sp);
        }

        d_chunk_centers = chunk_centers->data[(j_c + chunk_centers->size[0]) - 1];
        chunk_centers->data[c - 1] = c_chunk_centers;
        chunk_centers->data[(c + chunk_centers->size[0]) - 1] = d_chunk_centers
          + radius / 2.0;
      } else {
        if (top == bottom) {
          i1 = chunk_centers->size[0];
          if ((c >= 1) && (c < i1)) {
            k_c = c;
          } else {
            k_c = emlrtDynamicBoundsCheckR2012b(c, 1, i1, &qb_emlrtBCI, sp);
          }

          d0 = chunk_centers->data[(k_c + chunk_centers->size[0]) - 1];
          if (d0 == (int32_T)muDoubleScalarFloor(d0)) {
            i1 = (int32_T)d0;
          } else {
            i1 = (int32_T)emlrtIntegerCheckR2012b(d0, &k_emlrtDCI, sp);
          }

          i7 = chunk_centers->size[0];
          if ((c >= 1) && (c < i7)) {
            l_c = c;
          } else {
            l_c = emlrtDynamicBoundsCheckR2012b(c, 1, i7, &sb_emlrtBCI, sp);
          }

          d0 = chunk_centers->data[l_c - 1];
          if (d0 == (int32_T)muDoubleScalarFloor(d0)) {
            i7 = (int32_T)d0;
          } else {
            i7 = (int32_T)emlrtIntegerCheckR2012b(d0, &l_emlrtDCI, sp);
          }

          if ((i1 >= 1) && (i1 < 216)) {
            i19 = i1;
          } else {
            i19 = emlrtDynamicBoundsCheckR2012b(i1, 1, 216, &pb_emlrtBCI, sp);
          }

          if ((i7 >= 1) && (i7 < 762)) {
            i20 = i7;
          } else {
            i20 = emlrtDynamicBoundsCheckR2012b(i7, 1, 762, &rb_emlrtBCI, sp);
          }

          if (SD->f6.blank[(i19 + 216 * (i20 - 1)) - 1] == 255) {
            idx = chunk_centers->size[0];
            emlrtDynamicBoundsCheckR2012b(c, 1, idx, &m_emlrtBCI, sp);
            idx = chunk_centers->size[0];
            if ((c >= 1) && (c < idx)) {
              m_c = c;
            } else {
              m_c = emlrtDynamicBoundsCheckR2012b(c, 1, idx, &tb_emlrtBCI, sp);
            }

            c_chunk_centers = chunk_centers->data[m_c - 1];
            idx = chunk_centers->size[0];
            if ((c >= 1) && (c < idx)) {
              n_c = c;
            } else {
              n_c = emlrtDynamicBoundsCheckR2012b(c, 1, idx, &ub_emlrtBCI, sp);
            }

            d_chunk_centers = chunk_centers->data[(n_c + chunk_centers->size[0])
              - 1];
            chunk_centers->data[c - 1] = c_chunk_centers + 1.0;
            chunk_centers->data[(c + chunk_centers->size[0]) - 1] =
              d_chunk_centers;
            i1 = chunk_centers->size[0];
            if ((c >= 1) && (c < i1)) {
              o_c = c;
            } else {
              o_c = emlrtDynamicBoundsCheckR2012b(c, 1, i1, &vb_emlrtBCI, sp);
            }

            d0 = chunk_centers->data[(o_c + chunk_centers->size[0]) - 1] -
              muDoubleScalarFloor(radius);
            i1 = chunk_centers->size[0];
            i7 = (c - 1) + 1;
            emlrtDynamicBoundsCheckR2012b(i7, 1, i1, &l_emlrtBCI, sp);
            if (d0 > chunk_centers->data[(c + chunk_centers->size[0]) - 1]) {
              i1 = 0;
              i7 = 0;
            } else {
              if (d0 == (int32_T)muDoubleScalarFloor(d0)) {
                i1 = (int32_T)d0;
              } else {
                i1 = (int32_T)emlrtIntegerCheckR2012b(d0, &d_emlrtDCI, sp);
              }

              if ((i1 >= 1) && (i1 < 216)) {
                i21 = i1;
              } else {
                i21 = emlrtDynamicBoundsCheckR2012b(i1, 1, 216, &k_emlrtBCI, sp);
              }

              i1 = i21 - 1;
              d0 = chunk_centers->data[(c + chunk_centers->size[0]) - 1];
              if (d0 == (int32_T)muDoubleScalarFloor(d0)) {
                i7 = (int32_T)d0;
              } else {
                i7 = (int32_T)emlrtIntegerCheckR2012b(d0, &d_emlrtDCI, sp);
              }

              if ((i7 >= 1) && (i7 < 216)) {
              } else {
                i7 = emlrtDynamicBoundsCheckR2012b(i7, 1, 216, &k_emlrtBCI, sp);
              }
            }

            idx = chunk_centers->size[0];
            if ((c >= 1) && (c < idx)) {
              p_c = c;
            } else {
              p_c = emlrtDynamicBoundsCheckR2012b(c, 1, idx, &wb_emlrtBCI, sp);
            }

            d0 = chunk_centers->data[p_c - 1];
            if (d0 == (int32_T)muDoubleScalarFloor(d0)) {
              idx = (int32_T)d0;
            } else {
              idx = (int32_T)emlrtIntegerCheckR2012b(d0, &c_emlrtDCI, sp);
            }

            if ((idx >= 1) && (idx < 762)) {
            } else {
              idx = emlrtDynamicBoundsCheckR2012b(idx, 1, 762, &j_emlrtBCI, sp);
            }

            b_blank_size[0] = i7 - i1;
            itmp = i7 - i1;
            for (i7 = 0; i7 < itmp; i7++) {
              c_blank_data[i7] = SD->f6.blank[(i1 + i7) + 216 * (idx - 1)];
            }

            d_blank_data.data = (uint8_T *)&c_blank_data;
            d_blank_data.size = (int32_T *)&b_blank_size;
            d_blank_data.allocatedSize = 216;
            d_blank_data.numDimensions = 1;
            d_blank_data.canFreeData = false;
            st.site = &m_emlrtRSI;
            top = g_sum(&st, &d_blank_data);
            i1 = chunk_centers->size[0];
            i7 = (c - 1) + 1;
            emlrtDynamicBoundsCheckR2012b(i7, 1, i1, &i_emlrtBCI, sp);
            i1 = chunk_centers->size[0];
            i7 = (c - 1) + 1;
            emlrtDynamicBoundsCheckR2012b(i7, 1, i1, &h_emlrtBCI, sp);
            if (chunk_centers->data[(c + chunk_centers->size[0]) - 1] ==
                chunk_centers->data[(c + chunk_centers->size[0]) - 1]) {
            } else {
              emlrtErrorWithMessageIdR2012b(sp, &gb_emlrtRTEI,
                "EMLRT:runTime:RepeatedExprWithDifferentResultsInColonIndexing",
                0);
            }

            c_chunk_centers = chunk_centers->data[(c + chunk_centers->size[0]) -
              1];
            d0 = muDoubleScalarFloor(radius);
            i1 = chunk_centers->size[0];
            if ((c >= 1) && (c < i1)) {
              q_c = c;
            } else {
              q_c = emlrtDynamicBoundsCheckR2012b(c, 1, i1, &xb_emlrtBCI, sp);
            }

            d1 = chunk_centers->data[q_c - 1];
            if (d1 == (int32_T)muDoubleScalarFloor(d1)) {
              i1 = (int32_T)d1;
            } else {
              i1 = (int32_T)emlrtIntegerCheckR2012b(d1, &b_emlrtDCI, sp);
            }

            if ((i1 >= 1) && (i1 < 762)) {
              idx = i1;
            } else {
              idx = emlrtDynamicBoundsCheckR2012b(i1, 1, 762, &g_emlrtBCI, sp);
            }

            i1 = blank->size[0];
            blank->size[0] = (int32_T)d0 + 1;
            emxEnsureCapacity(sp, (emxArray__common *)blank, i1, (int32_T)sizeof
                              (uint8_T), &c_emlrtRTEI);
            itmp = (int32_T)d0;
            for (i1 = 0; i1 <= itmp; i1++) {
              d0 = c_chunk_centers + (real_T)i1;
              if (d0 == (int32_T)muDoubleScalarFloor(d0)) {
                i7 = (int32_T)d0;
              } else {
                i7 = (int32_T)emlrtIntegerCheckR2012b(d0, &m_emlrtDCI, sp);
              }

              if ((i7 >= 1) && (i7 < 216)) {
                i22 = i7;
              } else {
                i22 = emlrtDynamicBoundsCheckR2012b(i7, 1, 216, &yb_emlrtBCI, sp);
              }

              blank->data[i1] = SD->f6.blank[(i22 + 216 * (idx - 1)) - 1];
            }

            st.site = &n_emlrtRSI;
            bottom = g_sum(&st, blank);
            if (top - bottom < -900.0) {
              idx = chunk_centers->size[0];
              emlrtDynamicBoundsCheckR2012b(c, 1, idx, &f_emlrtBCI, sp);
              idx = chunk_centers->size[0];
              if ((c >= 1) && (c < idx)) {
                r_c = c;
              } else {
                r_c = emlrtDynamicBoundsCheckR2012b(c, 1, idx, &cc_emlrtBCI, sp);
              }

              c_chunk_centers = chunk_centers->data[r_c - 1];
              idx = chunk_centers->size[0];
              if ((c >= 1) && (c < idx)) {
                s_c = c;
              } else {
                s_c = emlrtDynamicBoundsCheckR2012b(c, 1, idx, &dc_emlrtBCI, sp);
              }

              d_chunk_centers = chunk_centers->data[(s_c + chunk_centers->size[0])
                - 1];
              chunk_centers->data[c - 1] = c_chunk_centers;
              chunk_centers->data[(c + chunk_centers->size[0]) - 1] =
                d_chunk_centers - radius / 2.0;
            } else {
              if (top - bottom > 900.0) {
                idx = chunk_centers->size[0];
                emlrtDynamicBoundsCheckR2012b(c, 1, idx, &e_emlrtBCI, sp);
                idx = chunk_centers->size[0];
                if ((c >= 1) && (c < idx)) {
                  t_c = c;
                } else {
                  t_c = emlrtDynamicBoundsCheckR2012b(c, 1, idx, &ac_emlrtBCI,
                    sp);
                }

                c_chunk_centers = chunk_centers->data[t_c - 1];
                idx = chunk_centers->size[0];
                if ((c >= 1) && (c < idx)) {
                  u_c = c;
                } else {
                  u_c = emlrtDynamicBoundsCheckR2012b(c, 1, idx, &bc_emlrtBCI,
                    sp);
                }

                d_chunk_centers = chunk_centers->data[(u_c + chunk_centers->
                  size[0]) - 1];
                chunk_centers->data[c - 1] = c_chunk_centers;
                chunk_centers->data[(c + chunk_centers->size[0]) - 1] =
                  d_chunk_centers + radius / 2.0;
              }
            }
          }
        }
      }

      c++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    i0 = b_centers->size[0] * b_centers->size[1];
    b_centers->size[0] = centers->size[0] + chunk_centers->size[0];
    b_centers->size[1] = 2;
    emxEnsureCapacity(sp, (emxArray__common *)b_centers, i0, (int32_T)sizeof
                      (real_T), &c_emlrtRTEI);
    for (i0 = 0; i0 < 2; i0++) {
      itmp = centers->size[0];
      for (i1 = 0; i1 < itmp; i1++) {
        b_centers->data[i1 + b_centers->size[0] * i0] = centers->data[i1 +
          centers->size[0] * i0];
      }
    }

    for (i0 = 0; i0 < 2; i0++) {
      itmp = chunk_centers->size[0];
      for (i1 = 0; i1 < itmp; i1++) {
        b_centers->data[(i1 + centers->size[0]) + b_centers->size[0] * i0] =
          chunk_centers->data[i1 + chunk_centers->size[0] * i0];
      }
    }

    i0 = centers->size[0] * centers->size[1];
    centers->size[0] = b_centers->size[0];
    centers->size[1] = 2;
    emxEnsureCapacity(sp, (emxArray__common *)centers, i0, (int32_T)sizeof
                      (real_T), &c_emlrtRTEI);
    for (i0 = 0; i0 < 2; i0++) {
      itmp = b_centers->size[0];
      for (i1 = 0; i1 < itmp; i1++) {
        centers->data[i1 + centers->size[0] * i0] = b_centers->data[i1 +
          b_centers->size[0] * i0];
      }
    }

    if (staffs[stanza * 5] > chunk_end) {
      i0 = 0;
      i1 = 0;
    } else {
      d0 = staffs[stanza * 5];
      if (d0 == (int32_T)muDoubleScalarFloor(d0)) {
        i0 = (int32_T)d0;
      } else {
        i0 = (int32_T)emlrtIntegerCheckR2012b(d0, &emlrtDCI, sp);
      }

      if ((i0 >= 1) && (i0 < 216)) {
        i23 = i0;
      } else {
        i23 = emlrtDynamicBoundsCheckR2012b(i0, 1, 216, &d_emlrtBCI, sp);
      }

      i0 = i23 - 1;
      if (chunk_end == (int32_T)muDoubleScalarFloor(chunk_end)) {
        i1 = (int32_T)chunk_end;
      } else {
        i1 = (int32_T)emlrtIntegerCheckR2012b(chunk_end, &emlrtDCI, sp);
      }

      if ((i1 >= 1) && (i1 < 216)) {
      } else {
        i1 = emlrtDynamicBoundsCheckR2012b(i1, 1, 216, &d_emlrtBCI, sp);
      }
    }

    itmp = i1 - i0;
    for (i7 = 0; i7 < itmp; i7++) {
      ii_data[i7] = i0 + i7;
    }

    b_ii[0] = i1 - i0;
    b_ii[1] = 762;
    emlrtSubAssignSizeCheckR2012b(b_ii, 2, *(int32_T (*)[2])im_chunk->size, 2,
      &emlrtECI, sp);
    for (i0 = 0; i0 < 762; i0++) {
      itmp = im_chunk->size[0];
      for (i1 = 0; i1 < itmp; i1++) {
        SD->f6.b_im[ii_data[i1] + 216 * i0] = im_chunk->data[i1 + im_chunk->
          size[0] * i0];
      }
    }

    stanza++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_real_T(&b_centers);
  emxFree_real_T(&b_chunk_centers);
  emxFree_uint8_T(&b_blank);
  emxFree_uint8_T(&blank);
  emxFree_int32_T(&iidx);
  emxFree_real_T(&unusedU0);
  emxFree_boolean_T(&extras);
  emxFree_real_T(&chunk_centers);
  emxFree_real_T(&edges);
  emxFree_uint8_T(&im_chunk);

  /* % */
  /*  create full staffs and etc. */
  memset(&full_staffs[0], 0, 26U * sizeof(real_T));
  repmat(full_scale);
  stanza = 0;
  while (stanza < 2) {
    full_start = 13 * stanza;
    staff_start = 5 * stanza;
    full_staffs[full_start] = staffs[staff_start] - avg_staff_height;

    /* A5 */
    full_staffs[full_start + 1] = staffs[staff_start] - avg_staff_height / 2.0;

    /* G5 */
    l = staff_start + 1;
    idx = 0;
    while (idx <= 8) {
      p = (full_start + idx) + 3;
      if (b_mod((real_T)((p + stanza) + 1) - 1.0, 2.0) != 0.0) {
        if ((l >= 1) && (l < 10)) {
          b_l = l;
        } else {
          b_l = emlrtDynamicBoundsCheckR2012b(l, 1, 10, &jb_emlrtBCI, sp);
        }

        full_staffs[p - 1] = staffs[b_l - 1];
      } else {
        if ((l >= 1) && (l < 10)) {
          c_l = l;
        } else {
          c_l = emlrtDynamicBoundsCheckR2012b(l, 1, 10, &ib_emlrtBCI, sp);
        }

        full_staffs[p - 1] = staffs[c_l - 1] + avg_staff_height / 2.0;
        l++;
      }

      idx++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    full_staffs[full_start + 11] = staffs[staff_start + 4] + avg_staff_height /
      2.0;

    /* D4 */
    full_staffs[full_start + 12] = staffs[staff_start + 4] + avg_staff_height;

    /* C4 */
    stanza++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxInit_real_T(sp, &r0, 2, &c_emlrtRTEI, true);

  /* % */
  /*  get those letters */
  ixstart = centers->size[0];
  i0 = r0->size[0] * r0->size[1];
  r0->size[0] = ixstart;
  r0->size[1] = 2;
  emxEnsureCapacity(sp, (emxArray__common *)r0, i0, (int32_T)sizeof(real_T),
                    &c_emlrtRTEI);
  for (i0 = 0; i0 < ixstart; i0++) {
    for (i1 = 0; i1 < 2; i1++) {
      r0->data[i0 + r0->size[0] * i1] = 48.0;
    }
  }

  st.site = &o_emlrtRSI;
  b_char(&st, r0, notes);
  i = 0;
  emxFree_real_T(&r0);
  while (i <= centers->size[0] - 1) {
    i0 = centers->size[0];
    i1 = i + 1;
    emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &c_emlrtBCI, sp);

    /*      less = abs(diff)<avg_staff_height/2; */
    /*      score = sum(less); */
    c_centers = centers->data[i + centers->size[0]];
    for (i0 = 0; i0 < 26; i0++) {
      b_full_staffs[i0] = full_staffs[i0] - c_centers;
    }

    b_abs(b_full_staffs, varargin_1);
    ixstart = 1;
    mtmp = varargin_1[0];
    itmp = 0;
    if (muDoubleScalarIsNaN(varargin_1[0])) {
      idx = 2;
      exitg1 = false;
      while ((!exitg1) && (idx < 27)) {
        ixstart = idx;
        if (!muDoubleScalarIsNaN(varargin_1[idx - 1])) {
          mtmp = varargin_1[idx - 1];
          itmp = idx - 1;
          exitg1 = true;
        } else {
          idx++;
        }
      }
    }

    if (ixstart < 26) {
      while (ixstart + 1 < 27) {
        if (varargin_1[ixstart] < mtmp) {
          mtmp = varargin_1[ixstart];
          itmp = ixstart;
        }

        ixstart++;
      }
    }

    /*      if score == 1 */
    /*          note = scale(less,:); */
    /*      elseif score > 1 */
    /*          note = scale(min_in,:); */
    /*      end */
    idx = notes->size[0];
    i0 = 1 + i;
    emlrtDynamicBoundsCheckR2012b(i0, 1, idx, &b_emlrtBCI, sp);
    for (i0 = 0; i0 < 2; i0++) {
      notes->data[i + notes->size[0] * i0] = full_scale[itmp + 26 * i0];
    }

    /*      closest_to(centers(i,2), full_staffs, full_scale, avg_staff_height);  */
    i++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_real_T(&centers);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (extract_notes.c) */
