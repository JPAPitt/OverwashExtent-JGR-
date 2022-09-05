/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_O1_Slope_Fast_api.c
 *
 * Code generation for function '_coder_O1_Slope_Fast_api'
 *
 */

/* Include files */
#include "_coder_O1_Slope_Fast_api.h"
#include "O1_Slope_Fast.h"
#include "O1_Slope_Fast_data.h"
#include "O1_Slope_Fast_emxutil.h"
#include "O1_Slope_Fast_types.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRTEInfo mc_emlrtRTEI = { 1,/* lineNo */
  1,                                   /* colNo */
  "_coder_O1_Slope_Fast_api",          /* fName */
  ""                                   /* pName */
};

/* Function Declarations */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y);
static const mxArray *b_emlrt_marshallOut(const real_T u);
static real_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *QL,
  const char_T *identifier))[2];
static real_T (*d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[2];
static real_T e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *bx, const
  char_T *identifier);
static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *Q, const
  char_T *identifier, emxArray_real_T *y);
static const mxArray *emlrt_marshallOut(const emxArray_real_T *u);
static real_T f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret);
static real_T (*h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[2];
static real_T i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId);

/* Function Definitions */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y)
{
  g_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static const mxArray *b_emlrt_marshallOut(const real_T u)
{
  const mxArray *m;
  const mxArray *y;
  y = NULL;
  m = emlrtCreateDoubleScalar(u);
  emlrtAssign(&y, m);
  return y;
}

static real_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *QL,
  const char_T *identifier))[2]
{
  emlrtMsgIdentifier thisId;
  real_T (*y)[2];
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = d_emlrt_marshallIn(sp, emlrtAlias(QL), &thisId);
  emlrtDestroyArray(&QL);
  return y;
}
  static real_T (*d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId))[2]
{
  real_T (*y)[2];
  y = h_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static real_T e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *bx, const
  char_T *identifier)
{
  emlrtMsgIdentifier thisId;
  real_T y;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = f_emlrt_marshallIn(sp, emlrtAlias(bx), &thisId);
  emlrtDestroyArray(&bx);
  return y;
}

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *Q, const
  char_T *identifier, emxArray_real_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  b_emlrt_marshallIn(sp, emlrtAlias(Q), &thisId, y);
  emlrtDestroyArray(&Q);
}

static const mxArray *emlrt_marshallOut(const emxArray_real_T *u)
{
  static const int32_T iv[2] = { 0, 0 };

  const mxArray *m;
  const mxArray *y;
  y = NULL;
  m = emlrtCreateNumericArray(2, &iv[0], mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m, &u->data[0]);
  emlrtSetDimensions((mxArray *)m, u->size, 2);
  emlrtAssign(&y, m);
  return y;
}

static real_T f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = i_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret)
{
  static const int32_T dims[2] = { 2, -1 };

  int32_T iv[2];
  int32_T i;
  const boolean_T bv[2] = { false, true };

  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims, &bv[0],
    iv);
  ret->allocatedSize = iv[0] * iv[1];
  i = ret->size[0] * ret->size[1];
  ret->size[0] = iv[0];
  ret->size[1] = iv[1];
  emxEnsureCapacity_real_T(sp, ret, i, (emlrtRTEInfo *)NULL);
  ret->data = (real_T *)emlrtMxGetData(src);
  ret->canFreeData = false;
  emlrtDestroyArray(&src);
}

static real_T (*h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[2]
{
  static const int32_T dims[1] = { 2 };

  real_T (*ret)[2];
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 1U, dims);
  ret = (real_T (*)[2])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}
  static real_T i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId)
{
  static const int32_T dims = 0;
  real_T ret;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 0U, &dims);
  ret = *(real_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

void O1_Slope_Fast_api(const mxArray * const prhs[9], int32_T nlhs, const
  mxArray *plhs[4])
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  emxArray_real_T *Q;
  emxArray_real_T *nQ;
  real_T (*QL)[2];
  real_T (*QR)[2];
  real_T CFL;
  real_T EFlux_Left;
  real_T EFlux_Right;
  real_T bx;
  real_T dt;
  real_T dtmax;
  real_T dtmin;
  real_T dx;
  real_T g;
  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  emxInit_real_T(&st, &Q, 2, &mc_emlrtRTEI, true);
  emxInit_real_T(&st, &nQ, 2, &mc_emlrtRTEI, true);

  /* Marshall function inputs */
  Q->canFreeData = false;
  emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "Q", Q);
  QL = c_emlrt_marshallIn(&st, emlrtAlias(prhs[1]), "QL");
  QR = c_emlrt_marshallIn(&st, emlrtAlias(prhs[2]), "QR");
  bx = e_emlrt_marshallIn(&st, emlrtAliasP(prhs[3]), "bx");
  g = e_emlrt_marshallIn(&st, emlrtAliasP(prhs[4]), "g");
  dx = e_emlrt_marshallIn(&st, emlrtAliasP(prhs[5]), "dx");
  CFL = e_emlrt_marshallIn(&st, emlrtAliasP(prhs[6]), "CFL");
  dtmin = e_emlrt_marshallIn(&st, emlrtAliasP(prhs[7]), "dtmin");
  dtmax = e_emlrt_marshallIn(&st, emlrtAliasP(prhs[8]), "dtmax");

  /* Invoke the target function */
  O1_Slope_Fast(&st, Q, *QL, *QR, bx, g, dx, CFL, dtmin, dtmax, nQ, &dt,
                &EFlux_Left, &EFlux_Right);

  /* Marshall function outputs */
  nQ->canFreeData = false;
  plhs[0] = emlrt_marshallOut(nQ);
  emxFree_real_T(&nQ);
  emxFree_real_T(&Q);
  if (nlhs > 1) {
    plhs[1] = b_emlrt_marshallOut(dt);
  }

  if (nlhs > 2) {
    plhs[2] = b_emlrt_marshallOut(EFlux_Left);
  }

  if (nlhs > 3) {
    plhs[3] = b_emlrt_marshallOut(EFlux_Right);
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

/* End of code generation (_coder_O1_Slope_Fast_api.c) */
