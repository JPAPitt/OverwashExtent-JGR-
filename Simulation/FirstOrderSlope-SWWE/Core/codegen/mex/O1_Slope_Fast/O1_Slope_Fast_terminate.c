/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * O1_Slope_Fast_terminate.c
 *
 * Code generation for function 'O1_Slope_Fast_terminate'
 *
 */

/* Include files */
#include "O1_Slope_Fast_terminate.h"
#include "O1_Slope_Fast_data.h"
#include "_coder_O1_Slope_Fast_mex.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void O1_Slope_Fast_atexit(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
  emlrtExitTimeCleanup(&emlrtContextGlobal);
}

void O1_Slope_Fast_terminate(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/* End of code generation (O1_Slope_Fast_terminate.c) */
