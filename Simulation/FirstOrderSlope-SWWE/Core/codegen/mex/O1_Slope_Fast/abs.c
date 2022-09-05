/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * abs.c
 *
 * Code generation for function 'abs'
 *
 */

/* Include files */
#include "abs.h"
#include "O1_Slope_Fast_data.h"
#include "O1_Slope_Fast_emxutil.h"
#include "O1_Slope_Fast_types.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo cb_emlrtRSI = { 18, /* lineNo */
  "abs",                               /* fcnName */
  "/Applications/MATLAB_R2020b.app/toolbox/eml/lib/matlab/elfun/abs.m"/* pathName */
};

static emlrtRSInfo db_emlrtRSI = { 75, /* lineNo */
  "applyScalarFunction",               /* fcnName */
  "/Applications/MATLAB_R2020b.app/toolbox/eml/eml/+coder/+internal/applyScalarFunction.m"/* pathName */
};

static emlrtRTEInfo lc_emlrtRTEI = { 31,/* lineNo */
  21,                                  /* colNo */
  "applyScalarFunction",               /* fName */
  "/Applications/MATLAB_R2020b.app/toolbox/eml/eml/+coder/+internal/applyScalarFunction.m"/* pName */
};

/* Function Definitions */
void b_abs(const emlrtStack *sp, const emxArray_real_T *x, emxArray_real_T *y)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  int32_T k;
  int32_T nx;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &cb_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  nx = x->size[1];
  k = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = x->size[1];
  emxEnsureCapacity_real_T(&st, y, k, &lc_emlrtRTEI);
  b_st.site = &db_emlrtRSI;
  if ((1 <= x->size[1]) && (x->size[1] > 2147483646)) {
    c_st.site = &o_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }

  for (k = 0; k < nx; k++) {
    y->data[k] = muDoubleScalarAbs(x->data[k]);
  }
}

/* End of code generation (abs.c) */
