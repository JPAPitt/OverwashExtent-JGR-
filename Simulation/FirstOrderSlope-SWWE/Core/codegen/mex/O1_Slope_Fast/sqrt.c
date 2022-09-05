/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * sqrt.c
 *
 * Code generation for function 'sqrt'
 *
 */

/* Include files */
#include "sqrt.h"
#include "O1_Slope_Fast_data.h"
#include "O1_Slope_Fast_types.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo p_emlrtRSI = { 16,  /* lineNo */
  "sqrt",                              /* fcnName */
  "/Applications/MATLAB_R2020b.app/toolbox/eml/lib/matlab/elfun/sqrt.m"/* pathName */
};

static emlrtRSInfo q_emlrtRSI = { 33,  /* lineNo */
  "applyScalarFunctionInPlace",        /* fcnName */
  "/Applications/MATLAB_R2020b.app/toolbox/eml/eml/+coder/+internal/applyScalarFunctionInPlace.m"/* pathName */
};

static emlrtRTEInfo f_emlrtRTEI = { 13,/* lineNo */
  9,                                   /* colNo */
  "sqrt",                              /* fName */
  "/Applications/MATLAB_R2020b.app/toolbox/eml/lib/matlab/elfun/sqrt.m"/* pName */
};

/* Function Definitions */
void b_sqrt(const emlrtStack *sp, emxArray_real_T *x)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  int32_T k;
  int32_T nx;
  boolean_T p;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  p = false;
  nx = x->size[1];
  for (k = 0; k < nx; k++) {
    if (p || (x->data[k] < 0.0)) {
      p = true;
    }
  }

  if (p) {
    emlrtErrorWithMessageIdR2018a(sp, &f_emlrtRTEI,
      "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError", 3, 4,
      4, "sqrt");
  }

  st.site = &p_emlrtRSI;
  nx = x->size[1];
  b_st.site = &q_emlrtRSI;
  if ((1 <= x->size[1]) && (x->size[1] > 2147483646)) {
    c_st.site = &o_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }

  for (k = 0; k < nx; k++) {
    x->data[k] = muDoubleScalarSqrt(x->data[k]);
  }
}

/* End of code generation (sqrt.c) */
