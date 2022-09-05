/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_O1_Slope_Fast_mex.c
 *
 * Code generation for function '_coder_O1_Slope_Fast_mex'
 *
 */

/* Include files */
#include "_coder_O1_Slope_Fast_mex.h"
#include "O1_Slope_Fast_data.h"
#include "O1_Slope_Fast_initialize.h"
#include "O1_Slope_Fast_terminate.h"
#include "_coder_O1_Slope_Fast_api.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void O1_Slope_Fast_mexFunction(int32_T nlhs, mxArray *plhs[4], int32_T nrhs,
  const mxArray *prhs[9])
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  const mxArray *outputs[4];
  int32_T b_nlhs;
  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 9) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 9, 4,
                        13, "O1_Slope_Fast");
  }

  if (nlhs > 4) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 13,
                        "O1_Slope_Fast");
  }

  /* Call the function. */
  O1_Slope_Fast_api(prhs, nlhs, outputs);

  /* Copy over outputs to the caller. */
  if (nlhs < 1) {
    b_nlhs = 1;
  } else {
    b_nlhs = nlhs;
  }

  emlrtReturnArrays(b_nlhs, plhs, outputs);
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  mexAtExit(&O1_Slope_Fast_atexit);

  /* Module initialization. */
  O1_Slope_Fast_initialize();

  /* Dispatch the entry-point. */
  O1_Slope_Fast_mexFunction(nlhs, plhs, nrhs, prhs);

  /* Module termination. */
  O1_Slope_Fast_terminate();
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  return emlrtRootTLSGlobal;
}

/* End of code generation (_coder_O1_Slope_Fast_mex.c) */
