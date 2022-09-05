/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * O1_Slope_Fast.c
 *
 * Code generation for function 'O1_Slope_Fast'
 *
 */

/* Include files */
#include "O1_Slope_Fast.h"
#include "O1_Slope_Fast_data.h"
#include "O1_Slope_Fast_emxutil.h"
#include "O1_Slope_Fast_types.h"
#include "abs.h"
#include "eml_int_forloop_overflow_check.h"
#include "power.h"
#include "rt_nonfinite.h"
#include "scalexpAlloc.h"
#include "sqrt.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 7,     /* lineNo */
  "O1_Slope_Fast",                     /* fcnName */
  "/Users/a1229158/Documents/GitHub/SingleFloeLinearModel/Overwash-Simulations/FirstOrderSlope-SWWE/Core/O1_Slope_Fast.m"/* pathName */
};

static emlrtRSInfo b_emlrtRSI = { 26,  /* lineNo */
  "O1_Slope_Fast",                     /* fcnName */
  "/Users/a1229158/Documents/GitHub/SingleFloeLinearModel/Overwash-Simulations/FirstOrderSlope-SWWE/Core/O1_Slope_Fast.m"/* pathName */
};

static emlrtRSInfo c_emlrtRSI = { 87,  /* lineNo */
  "FluxCalc",                          /* fcnName */
  "/Users/a1229158/Documents/GitHub/SingleFloeLinearModel/Overwash-Simulations/FirstOrderSlope-SWWE/Core/O1_Slope_Fast.m"/* pathName */
};

static emlrtRSInfo d_emlrtRSI = { 86,  /* lineNo */
  "FluxCalc",                          /* fcnName */
  "/Users/a1229158/Documents/GitHub/SingleFloeLinearModel/Overwash-Simulations/FirstOrderSlope-SWWE/Core/O1_Slope_Fast.m"/* pathName */
};

static emlrtRSInfo e_emlrtRSI = { 61,  /* lineNo */
  "FluxCalc",                          /* fcnName */
  "/Users/a1229158/Documents/GitHub/SingleFloeLinearModel/Overwash-Simulations/FirstOrderSlope-SWWE/Core/O1_Slope_Fast.m"/* pathName */
};

static emlrtRSInfo f_emlrtRSI = { 57,  /* lineNo */
  "FluxCalc",                          /* fcnName */
  "/Users/a1229158/Documents/GitHub/SingleFloeLinearModel/Overwash-Simulations/FirstOrderSlope-SWWE/Core/O1_Slope_Fast.m"/* pathName */
};

static emlrtRSInfo g_emlrtRSI = { 56,  /* lineNo */
  "FluxCalc",                          /* fcnName */
  "/Users/a1229158/Documents/GitHub/SingleFloeLinearModel/Overwash-Simulations/FirstOrderSlope-SWWE/Core/O1_Slope_Fast.m"/* pathName */
};

static emlrtRSInfo h_emlrtRSI = { 47,  /* lineNo */
  "FluxCalc",                          /* fcnName */
  "/Users/a1229158/Documents/GitHub/SingleFloeLinearModel/Overwash-Simulations/FirstOrderSlope-SWWE/Core/O1_Slope_Fast.m"/* pathName */
};

static emlrtRSInfo i_emlrtRSI = { 43,  /* lineNo */
  "FluxCalc",                          /* fcnName */
  "/Users/a1229158/Documents/GitHub/SingleFloeLinearModel/Overwash-Simulations/FirstOrderSlope-SWWE/Core/O1_Slope_Fast.m"/* pathName */
};

static emlrtRSInfo j_emlrtRSI = { 40,  /* lineNo */
  "FluxCalc",                          /* fcnName */
  "/Users/a1229158/Documents/GitHub/SingleFloeLinearModel/Overwash-Simulations/FirstOrderSlope-SWWE/Core/O1_Slope_Fast.m"/* pathName */
};

static emlrtRSInfo r_emlrtRSI = { 14,  /* lineNo */
  "min",                               /* fcnName */
  "/Applications/MATLAB_R2020b.app/toolbox/eml/lib/matlab/datafun/min.m"/* pathName */
};

static emlrtRSInfo s_emlrtRSI = { 31,  /* lineNo */
  "minOrMax",                          /* fcnName */
  "/Applications/MATLAB_R2020b.app/toolbox/eml/eml/+coder/+internal/minOrMax.m"/* pathName */
};

static emlrtRSInfo t_emlrtRSI = { 67,  /* lineNo */
  "minimum2",                          /* fcnName */
  "/Applications/MATLAB_R2020b.app/toolbox/eml/eml/+coder/+internal/minOrMax.m"/* pathName */
};

static emlrtRSInfo u_emlrtRSI = { 64,  /* lineNo */
  "binaryMinOrMax",                    /* fcnName */
  "/Applications/MATLAB_R2020b.app/toolbox/eml/eml/+coder/+internal/binaryMinOrMax.m"/* pathName */
};

static emlrtRSInfo v_emlrtRSI = { 46,  /* lineNo */
  "applyBinaryScalarFunction",         /* fcnName */
  "/Applications/MATLAB_R2020b.app/toolbox/eml/eml/+coder/+internal/applyBinaryScalarFunction.m"/* pathName */
};

static emlrtRSInfo y_emlrtRSI = { 14,  /* lineNo */
  "max",                               /* fcnName */
  "/Applications/MATLAB_R2020b.app/toolbox/eml/lib/matlab/datafun/max.m"/* pathName */
};

static emlrtRSInfo ab_emlrtRSI = { 29, /* lineNo */
  "minOrMax",                          /* fcnName */
  "/Applications/MATLAB_R2020b.app/toolbox/eml/eml/+coder/+internal/minOrMax.m"/* pathName */
};

static emlrtRSInfo bb_emlrtRSI = { 58, /* lineNo */
  "maximum2",                          /* fcnName */
  "/Applications/MATLAB_R2020b.app/toolbox/eml/eml/+coder/+internal/minOrMax.m"/* pathName */
};

static emlrtRSInfo eb_emlrtRSI = { 44, /* lineNo */
  "minOrMax",                          /* fcnName */
  "/Applications/MATLAB_R2020b.app/toolbox/eml/eml/+coder/+internal/minOrMax.m"/* pathName */
};

static emlrtRSInfo fb_emlrtRSI = { 79, /* lineNo */
  "maximum",                           /* fcnName */
  "/Applications/MATLAB_R2020b.app/toolbox/eml/eml/+coder/+internal/minOrMax.m"/* pathName */
};

static emlrtRSInfo gb_emlrtRSI = { 22, /* lineNo */
  "cat",                               /* fcnName */
  "/Applications/MATLAB_R2020b.app/toolbox/eml/eml/+coder/+internal/cat.m"/* pathName */
};

static emlrtRSInfo hb_emlrtRSI = { 102,/* lineNo */
  "cat_impl",                          /* fcnName */
  "/Applications/MATLAB_R2020b.app/toolbox/eml/eml/+coder/+internal/cat.m"/* pathName */
};

static emlrtECInfo emlrtECI = { 2,     /* nDims */
  23,                                  /* lineNo */
  22,                                  /* colNo */
  "O1_Slope_Fast",                     /* fName */
  "/Users/a1229158/Documents/GitHub/SingleFloeLinearModel/Overwash-Simulations/FirstOrderSlope-SWWE/Core/O1_Slope_Fast.m"/* pName */
};

static emlrtECInfo b_emlrtECI = { 2,   /* nDims */
  23,                                  /* lineNo */
  11,                                  /* colNo */
  "O1_Slope_Fast",                     /* fName */
  "/Users/a1229158/Documents/GitHub/SingleFloeLinearModel/Overwash-Simulations/FirstOrderSlope-SWWE/Core/O1_Slope_Fast.m"/* pName */
};

static emlrtECInfo c_emlrtECI = { -1,  /* nDims */
  11,                                  /* lineNo */
  5,                                   /* colNo */
  "O1_Slope_Fast",                     /* fName */
  "/Users/a1229158/Documents/GitHub/SingleFloeLinearModel/Overwash-Simulations/FirstOrderSlope-SWWE/Core/O1_Slope_Fast.m"/* pName */
};

static emlrtECInfo d_emlrtECI = { -1,  /* nDims */
  26,                                  /* lineNo */
  5,                                   /* colNo */
  "O1_Slope_Fast",                     /* fName */
  "/Users/a1229158/Documents/GitHub/SingleFloeLinearModel/Overwash-Simulations/FirstOrderSlope-SWWE/Core/O1_Slope_Fast.m"/* pName */
};

static emlrtBCInfo emlrtBCI = { -1,    /* iFirst */
  -1,                                  /* iLast */
  27,                                  /* lineNo */
  5,                                   /* colNo */
  "nQ",                                /* aName */
  "O1_Slope_Fast",                     /* fName */
  "/Users/a1229158/Documents/GitHub/SingleFloeLinearModel/Overwash-Simulations/FirstOrderSlope-SWWE/Core/O1_Slope_Fast.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo b_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  87,                                  /* lineNo */
  33,                                  /* colNo */
  "FluxUH",                            /* aName */
  "FluxCalc",                          /* fName */
  "/Users/a1229158/Documents/GitHub/SingleFloeLinearModel/Overwash-Simulations/FirstOrderSlope-SWWE/Core/O1_Slope_Fast.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  87,                                  /* lineNo */
  19,                                  /* colNo */
  "FluxH",                             /* aName */
  "FluxCalc",                          /* fName */
  "/Users/a1229158/Documents/GitHub/SingleFloeLinearModel/Overwash-Simulations/FirstOrderSlope-SWWE/Core/O1_Slope_Fast.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo d_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  86,                                  /* lineNo */
  35,                                  /* colNo */
  "FluxUH",                            /* aName */
  "FluxCalc",                          /* fName */
  "/Users/a1229158/Documents/GitHub/SingleFloeLinearModel/Overwash-Simulations/FirstOrderSlope-SWWE/Core/O1_Slope_Fast.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo e_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  86,                                  /* lineNo */
  19,                                  /* colNo */
  "FluxH",                             /* aName */
  "FluxCalc",                          /* fName */
  "/Users/a1229158/Documents/GitHub/SingleFloeLinearModel/Overwash-Simulations/FirstOrderSlope-SWWE/Core/O1_Slope_Fast.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo f_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  81,                                  /* lineNo */
  109,                                 /* colNo */
  "Ajhm_bc",                           /* aName */
  "FluxCalc",                          /* fName */
  "/Users/a1229158/Documents/GitHub/SingleFloeLinearModel/Overwash-Simulations/FirstOrderSlope-SWWE/Core/O1_Slope_Fast.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo g_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  81,                                  /* lineNo */
  95,                                  /* colNo */
  "Ajhp_bc",                           /* aName */
  "FluxCalc",                          /* fName */
  "/Users/a1229158/Documents/GitHub/SingleFloeLinearModel/Overwash-Simulations/FirstOrderSlope-SWWE/Core/O1_Slope_Fast.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo h_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  81,                                  /* lineNo */
  60,                                  /* colNo */
  "Ajhm_bc",                           /* aName */
  "FluxCalc",                          /* fName */
  "/Users/a1229158/Documents/GitHub/SingleFloeLinearModel/Overwash-Simulations/FirstOrderSlope-SWWE/Core/O1_Slope_Fast.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo i_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  81,                                  /* lineNo */
  23,                                  /* colNo */
  "Ajhp_bc",                           /* aName */
  "FluxCalc",                          /* fName */
  "/Users/a1229158/Documents/GitHub/SingleFloeLinearModel/Overwash-Simulations/FirstOrderSlope-SWWE/Core/O1_Slope_Fast.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo e_emlrtECI = { 2,   /* nDims */
  74,                                  /* lineNo */
  10,                                  /* colNo */
  "FluxCalc",                          /* fName */
  "/Users/a1229158/Documents/GitHub/SingleFloeLinearModel/Overwash-Simulations/FirstOrderSlope-SWWE/Core/O1_Slope_Fast.m"/* pName */
};

static emlrtECInfo f_emlrtECI = { 2,   /* nDims */
  73,                                  /* lineNo */
  10,                                  /* colNo */
  "FluxCalc",                          /* fName */
  "/Users/a1229158/Documents/GitHub/SingleFloeLinearModel/Overwash-Simulations/FirstOrderSlope-SWWE/Core/O1_Slope_Fast.m"/* pName */
};

static emlrtECInfo g_emlrtECI = { 2,   /* nDims */
  73,                                  /* lineNo */
  96,                                  /* colNo */
  "FluxCalc",                          /* fName */
  "/Users/a1229158/Documents/GitHub/SingleFloeLinearModel/Overwash-Simulations/FirstOrderSlope-SWWE/Core/O1_Slope_Fast.m"/* pName */
};

static emlrtECInfo h_emlrtECI = { 2,   /* nDims */
  73,                                  /* lineNo */
  125,                                 /* colNo */
  "FluxCalc",                          /* fName */
  "/Users/a1229158/Documents/GitHub/SingleFloeLinearModel/Overwash-Simulations/FirstOrderSlope-SWWE/Core/O1_Slope_Fast.m"/* pName */
};

static emlrtBCInfo j_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  73,                                  /* lineNo */
  164,                                 /* colNo */
  "REQ_bc",                            /* aName */
  "FluxCalc",                          /* fName */
  "/Users/a1229158/Documents/GitHub/SingleFloeLinearModel/Overwash-Simulations/FirstOrderSlope-SWWE/Core/O1_Slope_Fast.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo k_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  73,                                  /* lineNo */
  138,                                 /* colNo */
  "REQ_bc",                            /* aName */
  "FluxCalc",                          /* fName */
  "/Users/a1229158/Documents/GitHub/SingleFloeLinearModel/Overwash-Simulations/FirstOrderSlope-SWWE/Core/O1_Slope_Fast.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo i_emlrtECI = { 2,   /* nDims */
  73,                                  /* lineNo */
  53,                                  /* colNo */
  "FluxCalc",                          /* fName */
  "/Users/a1229158/Documents/GitHub/SingleFloeLinearModel/Overwash-Simulations/FirstOrderSlope-SWWE/Core/O1_Slope_Fast.m"/* pName */
};

static emlrtBCInfo l_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  73,                                  /* lineNo */
  83,                                  /* colNo */
  "FluxUHjm_bc",                       /* aName */
  "FluxCalc",                          /* fName */
  "/Users/a1229158/Documents/GitHub/SingleFloeLinearModel/Overwash-Simulations/FirstOrderSlope-SWWE/Core/O1_Slope_Fast.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo m_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  73,                                  /* lineNo */
  40,                                  /* colNo */
  "FluxUHjm_bc",                       /* aName */
  "FluxCalc",                          /* fName */
  "/Users/a1229158/Documents/GitHub/SingleFloeLinearModel/Overwash-Simulations/FirstOrderSlope-SWWE/Core/O1_Slope_Fast.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo j_emlrtECI = { 2,   /* nDims */
  71,                                  /* lineNo */
  9,                                   /* colNo */
  "FluxCalc",                          /* fName */
  "/Users/a1229158/Documents/GitHub/SingleFloeLinearModel/Overwash-Simulations/FirstOrderSlope-SWWE/Core/O1_Slope_Fast.m"/* pName */
};

static emlrtECInfo k_emlrtECI = { 2,   /* nDims */
  70,                                  /* lineNo */
  9,                                   /* colNo */
  "FluxCalc",                          /* fName */
  "/Users/a1229158/Documents/GitHub/SingleFloeLinearModel/Overwash-Simulations/FirstOrderSlope-SWWE/Core/O1_Slope_Fast.m"/* pName */
};

static emlrtECInfo l_emlrtECI = { 2,   /* nDims */
  70,                                  /* lineNo */
  95,                                  /* colNo */
  "FluxCalc",                          /* fName */
  "/Users/a1229158/Documents/GitHub/SingleFloeLinearModel/Overwash-Simulations/FirstOrderSlope-SWWE/Core/O1_Slope_Fast.m"/* pName */
};

static emlrtECInfo m_emlrtECI = { 2,   /* nDims */
  70,                                  /* lineNo */
  124,                                 /* colNo */
  "FluxCalc",                          /* fName */
  "/Users/a1229158/Documents/GitHub/SingleFloeLinearModel/Overwash-Simulations/FirstOrderSlope-SWWE/Core/O1_Slope_Fast.m"/* pName */
};

static emlrtBCInfo n_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  70,                                  /* lineNo */
  163,                                 /* colNo */
  "REQ_bc",                            /* aName */
  "FluxCalc",                          /* fName */
  "/Users/a1229158/Documents/GitHub/SingleFloeLinearModel/Overwash-Simulations/FirstOrderSlope-SWWE/Core/O1_Slope_Fast.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo o_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  70,                                  /* lineNo */
  137,                                 /* colNo */
  "REQ_bc",                            /* aName */
  "FluxCalc",                          /* fName */
  "/Users/a1229158/Documents/GitHub/SingleFloeLinearModel/Overwash-Simulations/FirstOrderSlope-SWWE/Core/O1_Slope_Fast.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo n_emlrtECI = { 2,   /* nDims */
  70,                                  /* lineNo */
  10,                                  /* colNo */
  "FluxCalc",                          /* fName */
  "/Users/a1229158/Documents/GitHub/SingleFloeLinearModel/Overwash-Simulations/FirstOrderSlope-SWWE/Core/O1_Slope_Fast.m"/* pName */
};

static emlrtECInfo o_emlrtECI = { 2,   /* nDims */
  70,                                  /* lineNo */
  52,                                  /* colNo */
  "FluxCalc",                          /* fName */
  "/Users/a1229158/Documents/GitHub/SingleFloeLinearModel/Overwash-Simulations/FirstOrderSlope-SWWE/Core/O1_Slope_Fast.m"/* pName */
};

static emlrtBCInfo p_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  70,                                  /* lineNo */
  81,                                  /* colNo */
  "FluxHjm_bc",                        /* aName */
  "FluxCalc",                          /* fName */
  "/Users/a1229158/Documents/GitHub/SingleFloeLinearModel/Overwash-Simulations/FirstOrderSlope-SWWE/Core/O1_Slope_Fast.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo q_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  70,                                  /* lineNo */
  39,                                  /* colNo */
  "FluxHjm_bc",                        /* aName */
  "FluxCalc",                          /* fName */
  "/Users/a1229158/Documents/GitHub/SingleFloeLinearModel/Overwash-Simulations/FirstOrderSlope-SWWE/Core/O1_Slope_Fast.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo p_emlrtECI = { 2,   /* nDims */
  66,                                  /* lineNo */
  17,                                  /* colNo */
  "FluxCalc",                          /* fName */
  "/Users/a1229158/Documents/GitHub/SingleFloeLinearModel/Overwash-Simulations/FirstOrderSlope-SWWE/Core/O1_Slope_Fast.m"/* pName */
};

static emlrtECInfo q_emlrtECI = { 2,   /* nDims */
  57,                                  /* lineNo */
  80,                                  /* colNo */
  "FluxCalc",                          /* fName */
  "/Users/a1229158/Documents/GitHub/SingleFloeLinearModel/Overwash-Simulations/FirstOrderSlope-SWWE/Core/O1_Slope_Fast.m"/* pName */
};

static emlrtBCInfo r_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  57,                                  /* lineNo */
  126,                                 /* colNo */
  "REQ_bc",                            /* aName */
  "FluxCalc",                          /* fName */
  "/Users/a1229158/Documents/GitHub/SingleFloeLinearModel/Overwash-Simulations/FirstOrderSlope-SWWE/Core/O1_Slope_Fast.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo s_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  57,                                  /* lineNo */
  93,                                  /* colNo */
  "uEQ_bc",                            /* aName */
  "FluxCalc",                          /* fName */
  "/Users/a1229158/Documents/GitHub/SingleFloeLinearModel/Overwash-Simulations/FirstOrderSlope-SWWE/Core/O1_Slope_Fast.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo r_emlrtECI = { 2,   /* nDims */
  57,                                  /* lineNo */
  21,                                  /* colNo */
  "FluxCalc",                          /* fName */
  "/Users/a1229158/Documents/GitHub/SingleFloeLinearModel/Overwash-Simulations/FirstOrderSlope-SWWE/Core/O1_Slope_Fast.m"/* pName */
};

static emlrtBCInfo t_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  57,                                  /* lineNo */
  67,                                  /* colNo */
  "REQ_bc",                            /* aName */
  "FluxCalc",                          /* fName */
  "/Users/a1229158/Documents/GitHub/SingleFloeLinearModel/Overwash-Simulations/FirstOrderSlope-SWWE/Core/O1_Slope_Fast.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo u_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  57,                                  /* lineNo */
  34,                                  /* colNo */
  "uEQ_bc",                            /* aName */
  "FluxCalc",                          /* fName */
  "/Users/a1229158/Documents/GitHub/SingleFloeLinearModel/Overwash-Simulations/FirstOrderSlope-SWWE/Core/O1_Slope_Fast.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo s_emlrtECI = { 2,   /* nDims */
  56,                                  /* lineNo */
  80,                                  /* colNo */
  "FluxCalc",                          /* fName */
  "/Users/a1229158/Documents/GitHub/SingleFloeLinearModel/Overwash-Simulations/FirstOrderSlope-SWWE/Core/O1_Slope_Fast.m"/* pName */
};

static emlrtBCInfo v_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  56,                                  /* lineNo */
  126,                                 /* colNo */
  "REQ_bc",                            /* aName */
  "FluxCalc",                          /* fName */
  "/Users/a1229158/Documents/GitHub/SingleFloeLinearModel/Overwash-Simulations/FirstOrderSlope-SWWE/Core/O1_Slope_Fast.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo w_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  56,                                  /* lineNo */
  93,                                  /* colNo */
  "uEQ_bc",                            /* aName */
  "FluxCalc",                          /* fName */
  "/Users/a1229158/Documents/GitHub/SingleFloeLinearModel/Overwash-Simulations/FirstOrderSlope-SWWE/Core/O1_Slope_Fast.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo t_emlrtECI = { 2,   /* nDims */
  56,                                  /* lineNo */
  21,                                  /* colNo */
  "FluxCalc",                          /* fName */
  "/Users/a1229158/Documents/GitHub/SingleFloeLinearModel/Overwash-Simulations/FirstOrderSlope-SWWE/Core/O1_Slope_Fast.m"/* pName */
};

static emlrtBCInfo x_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  56,                                  /* lineNo */
  67,                                  /* colNo */
  "REQ_bc",                            /* aName */
  "FluxCalc",                          /* fName */
  "/Users/a1229158/Documents/GitHub/SingleFloeLinearModel/Overwash-Simulations/FirstOrderSlope-SWWE/Core/O1_Slope_Fast.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo y_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  56,                                  /* lineNo */
  34,                                  /* colNo */
  "uEQ_bc",                            /* aName */
  "FluxCalc",                          /* fName */
  "/Users/a1229158/Documents/GitHub/SingleFloeLinearModel/Overwash-Simulations/FirstOrderSlope-SWWE/Core/O1_Slope_Fast.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo u_emlrtECI = { 2,   /* nDims */
  47,                                  /* lineNo */
  16,                                  /* colNo */
  "FluxCalc",                          /* fName */
  "/Users/a1229158/Documents/GitHub/SingleFloeLinearModel/Overwash-Simulations/FirstOrderSlope-SWWE/Core/O1_Slope_Fast.m"/* pName */
};

static emlrtECInfo v_emlrtECI = { 2,   /* nDims */
  43,                                  /* lineNo */
  11,                                  /* colNo */
  "FluxCalc",                          /* fName */
  "/Users/a1229158/Documents/GitHub/SingleFloeLinearModel/Overwash-Simulations/FirstOrderSlope-SWWE/Core/O1_Slope_Fast.m"/* pName */
};

static emlrtRTEInfo emlrtRTEI = { 20,  /* lineNo */
  15,                                  /* colNo */
  "rdivide_helper",                    /* fName */
  "/Applications/MATLAB_R2020b.app/toolbox/eml/eml/+coder/+internal/rdivide_helper.m"/* pName */
};

static emlrtRTEInfo b_emlrtRTEI = { 283,/* lineNo */
  27,                                  /* colNo */
  "check_non_axis_size",               /* fName */
  "/Applications/MATLAB_R2020b.app/toolbox/eml/eml/+coder/+internal/cat.m"/* pName */
};

static emlrtRTEInfo d_emlrtRTEI = { 19,/* lineNo */
  23,                                  /* colNo */
  "scalexpAlloc",                      /* fName */
  "/Applications/MATLAB_R2020b.app/toolbox/eml/eml/+coder/+internal/scalexpAlloc.m"/* pName */
};

static emlrtBCInfo ab_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  67,                                  /* lineNo */
  1,                                   /* colNo */
  "FluxCoeff",                         /* aName */
  "FluxCalc",                          /* fName */
  "/Users/a1229158/Documents/GitHub/SingleFloeLinearModel/Overwash-Simulations/FirstOrderSlope-SWWE/Core/O1_Slope_Fast.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo bb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  82,                                  /* lineNo */
  15,                                  /* colNo */
  "FluxCoeff",                         /* aName */
  "FluxCalc",                          /* fName */
  "/Users/a1229158/Documents/GitHub/SingleFloeLinearModel/Overwash-Simulations/FirstOrderSlope-SWWE/Core/O1_Slope_Fast.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo cb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  50,                                  /* lineNo */
  73,                                  /* colNo */
  "REQ_bc",                            /* aName */
  "FluxCalc",                          /* fName */
  "/Users/a1229158/Documents/GitHub/SingleFloeLinearModel/Overwash-Simulations/FirstOrderSlope-SWWE/Core/O1_Slope_Fast.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo db_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  50,                                  /* lineNo */
  27,                                  /* colNo */
  "uEQ_bc",                            /* aName */
  "FluxCalc",                          /* fName */
  "/Users/a1229158/Documents/GitHub/SingleFloeLinearModel/Overwash-Simulations/FirstOrderSlope-SWWE/Core/O1_Slope_Fast.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo eb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  50,                                  /* lineNo */
  48,                                  /* colNo */
  "REQ_bc",                            /* aName */
  "FluxCalc",                          /* fName */
  "/Users/a1229158/Documents/GitHub/SingleFloeLinearModel/Overwash-Simulations/FirstOrderSlope-SWWE/Core/O1_Slope_Fast.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo fb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  53,                                  /* lineNo */
  31,                                  /* colNo */
  "uEQ_bc",                            /* aName */
  "FluxCalc",                          /* fName */
  "/Users/a1229158/Documents/GitHub/SingleFloeLinearModel/Overwash-Simulations/FirstOrderSlope-SWWE/Core/O1_Slope_Fast.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo gb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  53,                                  /* lineNo */
  56,                                  /* colNo */
  "REQ_bc",                            /* aName */
  "FluxCalc",                          /* fName */
  "/Users/a1229158/Documents/GitHub/SingleFloeLinearModel/Overwash-Simulations/FirstOrderSlope-SWWE/Core/O1_Slope_Fast.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo hb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  104,                                 /* lineNo */
  28,                                  /* colNo */
  "Q",                                 /* aName */
  "ReconstructO1",                     /* fName */
  "/Users/a1229158/Documents/GitHub/SingleFloeLinearModel/Overwash-Simulations/FirstOrderSlope-SWWE/Core/O1_Slope_Fast.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ib_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  105,                                 /* lineNo */
  32,                                  /* colNo */
  "Q",                                 /* aName */
  "ReconstructO1",                     /* fName */
  "/Users/a1229158/Documents/GitHub/SingleFloeLinearModel/Overwash-Simulations/FirstOrderSlope-SWWE/Core/O1_Slope_Fast.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo jb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  104,                                 /* lineNo */
  13,                                  /* colNo */
  "RE_bc",                             /* aName */
  "ReconstructO1",                     /* fName */
  "/Users/a1229158/Documents/GitHub/SingleFloeLinearModel/Overwash-Simulations/FirstOrderSlope-SWWE/Core/O1_Slope_Fast.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo w_emlrtECI = { -1,  /* nDims */
  104,                                 /* lineNo */
  1,                                   /* colNo */
  "ReconstructO1",                     /* fName */
  "/Users/a1229158/Documents/GitHub/SingleFloeLinearModel/Overwash-Simulations/FirstOrderSlope-SWWE/Core/O1_Slope_Fast.m"/* pName */
};

static emlrtBCInfo kb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  105,                                 /* lineNo */
  9,                                   /* colNo */
  "RE_bc",                             /* aName */
  "ReconstructO1",                     /* fName */
  "/Users/a1229158/Documents/GitHub/SingleFloeLinearModel/Overwash-Simulations/FirstOrderSlope-SWWE/Core/O1_Slope_Fast.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo lb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  105,                                 /* lineNo */
  15,                                  /* colNo */
  "RE_bc",                             /* aName */
  "ReconstructO1",                     /* fName */
  "/Users/a1229158/Documents/GitHub/SingleFloeLinearModel/Overwash-Simulations/FirstOrderSlope-SWWE/Core/O1_Slope_Fast.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo x_emlrtECI = { -1,  /* nDims */
  105,                                 /* lineNo */
  1,                                   /* colNo */
  "ReconstructO1",                     /* fName */
  "/Users/a1229158/Documents/GitHub/SingleFloeLinearModel/Overwash-Simulations/FirstOrderSlope-SWWE/Core/O1_Slope_Fast.m"/* pName */
};

static emlrtBCInfo mb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  106,                                 /* lineNo */
  9,                                   /* colNo */
  "RE_bc",                             /* aName */
  "ReconstructO1",                     /* fName */
  "/Users/a1229158/Documents/GitHub/SingleFloeLinearModel/Overwash-Simulations/FirstOrderSlope-SWWE/Core/O1_Slope_Fast.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo emlrtDCI = { 101,   /* lineNo */
  18,                                  /* colNo */
  "ReconstructO1",                     /* fName */
  "/Users/a1229158/Documents/GitHub/SingleFloeLinearModel/Overwash-Simulations/FirstOrderSlope-SWWE/Core/O1_Slope_Fast.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo b_emlrtDCI = { 101, /* lineNo */
  1,                                   /* colNo */
  "ReconstructO1",                     /* fName */
  "/Users/a1229158/Documents/GitHub/SingleFloeLinearModel/Overwash-Simulations/FirstOrderSlope-SWWE/Core/O1_Slope_Fast.m",/* pName */
  1                                    /* checkKind */
};

static emlrtRTEInfo g_emlrtRTEI = { 10,/* lineNo */
  5,                                   /* colNo */
  "O1_Slope_Fast",                     /* fName */
  "/Users/a1229158/Documents/GitHub/SingleFloeLinearModel/Overwash-Simulations/FirstOrderSlope-SWWE/Core/O1_Slope_Fast.m"/* pName */
};

static emlrtRTEInfo h_emlrtRTEI = { 11,/* lineNo */
  20,                                  /* colNo */
  "O1_Slope_Fast",                     /* fName */
  "/Users/a1229158/Documents/GitHub/SingleFloeLinearModel/Overwash-Simulations/FirstOrderSlope-SWWE/Core/O1_Slope_Fast.m"/* pName */
};

static emlrtRTEInfo i_emlrtRTEI = { 23,/* lineNo */
  15,                                  /* colNo */
  "O1_Slope_Fast",                     /* fName */
  "/Users/a1229158/Documents/GitHub/SingleFloeLinearModel/Overwash-Simulations/FirstOrderSlope-SWWE/Core/O1_Slope_Fast.m"/* pName */
};

static emlrtRTEInfo j_emlrtRTEI = { 23,/* lineNo */
  41,                                  /* colNo */
  "O1_Slope_Fast",                     /* fName */
  "/Users/a1229158/Documents/GitHub/SingleFloeLinearModel/Overwash-Simulations/FirstOrderSlope-SWWE/Core/O1_Slope_Fast.m"/* pName */
};

static emlrtRTEInfo k_emlrtRTEI = { 23,/* lineNo */
  5,                                   /* colNo */
  "O1_Slope_Fast",                     /* fName */
  "/Users/a1229158/Documents/GitHub/SingleFloeLinearModel/Overwash-Simulations/FirstOrderSlope-SWWE/Core/O1_Slope_Fast.m"/* pName */
};

static emlrtRTEInfo l_emlrtRTEI = { 26,/* lineNo */
  19,                                  /* colNo */
  "O1_Slope_Fast",                     /* fName */
  "/Users/a1229158/Documents/GitHub/SingleFloeLinearModel/Overwash-Simulations/FirstOrderSlope-SWWE/Core/O1_Slope_Fast.m"/* pName */
};

static emlrtRTEInfo n_emlrtRTEI = { 27,/* lineNo */
  10,                                  /* colNo */
  "O1_Slope_Fast",                     /* fName */
  "/Users/a1229158/Documents/GitHub/SingleFloeLinearModel/Overwash-Simulations/FirstOrderSlope-SWWE/Core/O1_Slope_Fast.m"/* pName */
};

static emlrtRTEInfo o_emlrtRTEI = { 4, /* lineNo */
  43,                                  /* colNo */
  "O1_Slope_Fast",                     /* fName */
  "/Users/a1229158/Documents/GitHub/SingleFloeLinearModel/Overwash-Simulations/FirstOrderSlope-SWWE/Core/O1_Slope_Fast.m"/* pName */
};

static emlrtRTEInfo p_emlrtRTEI = { 43,/* lineNo */
  11,                                  /* colNo */
  "O1_Slope_Fast",                     /* fName */
  "/Users/a1229158/Documents/GitHub/SingleFloeLinearModel/Overwash-Simulations/FirstOrderSlope-SWWE/Core/O1_Slope_Fast.m"/* pName */
};

static emlrtRTEInfo q_emlrtRTEI = { 43,/* lineNo */
  24,                                  /* colNo */
  "O1_Slope_Fast",                     /* fName */
  "/Users/a1229158/Documents/GitHub/SingleFloeLinearModel/Overwash-Simulations/FirstOrderSlope-SWWE/Core/O1_Slope_Fast.m"/* pName */
};

static emlrtRTEInfo r_emlrtRTEI = { 43,/* lineNo */
  41,                                  /* colNo */
  "O1_Slope_Fast",                     /* fName */
  "/Users/a1229158/Documents/GitHub/SingleFloeLinearModel/Overwash-Simulations/FirstOrderSlope-SWWE/Core/O1_Slope_Fast.m"/* pName */
};

static emlrtRTEInfo s_emlrtRTEI = { 43,/* lineNo */
  1,                                   /* colNo */
  "O1_Slope_Fast",                     /* fName */
  "/Users/a1229158/Documents/GitHub/SingleFloeLinearModel/Overwash-Simulations/FirstOrderSlope-SWWE/Core/O1_Slope_Fast.m"/* pName */
};

static emlrtRTEInfo t_emlrtRTEI = { 47,/* lineNo */
  16,                                  /* colNo */
  "O1_Slope_Fast",                     /* fName */
  "/Users/a1229158/Documents/GitHub/SingleFloeLinearModel/Overwash-Simulations/FirstOrderSlope-SWWE/Core/O1_Slope_Fast.m"/* pName */
};

static emlrtRTEInfo u_emlrtRTEI = { 47,/* lineNo */
  29,                                  /* colNo */
  "O1_Slope_Fast",                     /* fName */
  "/Users/a1229158/Documents/GitHub/SingleFloeLinearModel/Overwash-Simulations/FirstOrderSlope-SWWE/Core/O1_Slope_Fast.m"/* pName */
};

static emlrtRTEInfo v_emlrtRTEI = { 47,/* lineNo */
  49,                                  /* colNo */
  "O1_Slope_Fast",                     /* fName */
  "/Users/a1229158/Documents/GitHub/SingleFloeLinearModel/Overwash-Simulations/FirstOrderSlope-SWWE/Core/O1_Slope_Fast.m"/* pName */
};

static emlrtRTEInfo w_emlrtRTEI = { 47,/* lineNo */
  43,                                  /* colNo */
  "O1_Slope_Fast",                     /* fName */
  "/Users/a1229158/Documents/GitHub/SingleFloeLinearModel/Overwash-Simulations/FirstOrderSlope-SWWE/Core/O1_Slope_Fast.m"/* pName */
};

static emlrtRTEInfo x_emlrtRTEI = { 47,/* lineNo */
  1,                                   /* colNo */
  "O1_Slope_Fast",                     /* fName */
  "/Users/a1229158/Documents/GitHub/SingleFloeLinearModel/Overwash-Simulations/FirstOrderSlope-SWWE/Core/O1_Slope_Fast.m"/* pName */
};

static emlrtRTEInfo y_emlrtRTEI = { 56,/* lineNo */
  47,                                  /* colNo */
  "O1_Slope_Fast",                     /* fName */
  "/Users/a1229158/Documents/GitHub/SingleFloeLinearModel/Overwash-Simulations/FirstOrderSlope-SWWE/Core/O1_Slope_Fast.m"/* pName */
};

static emlrtRTEInfo ab_emlrtRTEI = { 56,/* lineNo */
  21,                                  /* colNo */
  "O1_Slope_Fast",                     /* fName */
  "/Users/a1229158/Documents/GitHub/SingleFloeLinearModel/Overwash-Simulations/FirstOrderSlope-SWWE/Core/O1_Slope_Fast.m"/* pName */
};

static emlrtRTEInfo bb_emlrtRTEI = { 56,/* lineNo */
  106,                                 /* colNo */
  "O1_Slope_Fast",                     /* fName */
  "/Users/a1229158/Documents/GitHub/SingleFloeLinearModel/Overwash-Simulations/FirstOrderSlope-SWWE/Core/O1_Slope_Fast.m"/* pName */
};

static emlrtRTEInfo cb_emlrtRTEI = { 56,/* lineNo */
  80,                                  /* colNo */
  "O1_Slope_Fast",                     /* fName */
  "/Users/a1229158/Documents/GitHub/SingleFloeLinearModel/Overwash-Simulations/FirstOrderSlope-SWWE/Core/O1_Slope_Fast.m"/* pName */
};

static emlrtRTEInfo db_emlrtRTEI = { 17,/* lineNo */
  9,                                   /* colNo */
  "scalexpAlloc",                      /* fName */
  "/Applications/MATLAB_R2020b.app/toolbox/eml/eml/+coder/+internal/scalexpAlloc.m"/* pName */
};

static emlrtRTEInfo eb_emlrtRTEI = { 57,/* lineNo */
  47,                                  /* colNo */
  "O1_Slope_Fast",                     /* fName */
  "/Users/a1229158/Documents/GitHub/SingleFloeLinearModel/Overwash-Simulations/FirstOrderSlope-SWWE/Core/O1_Slope_Fast.m"/* pName */
};

static emlrtRTEInfo fb_emlrtRTEI = { 57,/* lineNo */
  21,                                  /* colNo */
  "O1_Slope_Fast",                     /* fName */
  "/Users/a1229158/Documents/GitHub/SingleFloeLinearModel/Overwash-Simulations/FirstOrderSlope-SWWE/Core/O1_Slope_Fast.m"/* pName */
};

static emlrtRTEInfo gb_emlrtRTEI = { 57,/* lineNo */
  106,                                 /* colNo */
  "O1_Slope_Fast",                     /* fName */
  "/Users/a1229158/Documents/GitHub/SingleFloeLinearModel/Overwash-Simulations/FirstOrderSlope-SWWE/Core/O1_Slope_Fast.m"/* pName */
};

static emlrtRTEInfo hb_emlrtRTEI = { 57,/* lineNo */
  80,                                  /* colNo */
  "O1_Slope_Fast",                     /* fName */
  "/Users/a1229158/Documents/GitHub/SingleFloeLinearModel/Overwash-Simulations/FirstOrderSlope-SWWE/Core/O1_Slope_Fast.m"/* pName */
};

static emlrtRTEInfo ib_emlrtRTEI = { 66,/* lineNo */
  17,                                  /* colNo */
  "O1_Slope_Fast",                     /* fName */
  "/Users/a1229158/Documents/GitHub/SingleFloeLinearModel/Overwash-Simulations/FirstOrderSlope-SWWE/Core/O1_Slope_Fast.m"/* pName */
};

static emlrtRTEInfo jb_emlrtRTEI = { 66,/* lineNo */
  32,                                  /* colNo */
  "O1_Slope_Fast",                     /* fName */
  "/Users/a1229158/Documents/GitHub/SingleFloeLinearModel/Overwash-Simulations/FirstOrderSlope-SWWE/Core/O1_Slope_Fast.m"/* pName */
};

static emlrtRTEInfo kb_emlrtRTEI = { 66,/* lineNo */
  1,                                   /* colNo */
  "O1_Slope_Fast",                     /* fName */
  "/Users/a1229158/Documents/GitHub/SingleFloeLinearModel/Overwash-Simulations/FirstOrderSlope-SWWE/Core/O1_Slope_Fast.m"/* pName */
};

static emlrtRTEInfo lb_emlrtRTEI = { 67,/* lineNo */
  11,                                  /* colNo */
  "O1_Slope_Fast",                     /* fName */
  "/Users/a1229158/Documents/GitHub/SingleFloeLinearModel/Overwash-Simulations/FirstOrderSlope-SWWE/Core/O1_Slope_Fast.m"/* pName */
};

static emlrtRTEInfo mb_emlrtRTEI = { 35,/* lineNo */
  57,                                  /* colNo */
  "O1_Slope_Fast",                     /* fName */
  "/Users/a1229158/Documents/GitHub/SingleFloeLinearModel/Overwash-Simulations/FirstOrderSlope-SWWE/Core/O1_Slope_Fast.m"/* pName */
};

static emlrtRTEInfo nb_emlrtRTEI = { 70,/* lineNo */
  10,                                  /* colNo */
  "O1_Slope_Fast",                     /* fName */
  "/Users/a1229158/Documents/GitHub/SingleFloeLinearModel/Overwash-Simulations/FirstOrderSlope-SWWE/Core/O1_Slope_Fast.m"/* pName */
};

static emlrtRTEInfo ob_emlrtRTEI = { 70,/* lineNo */
  52,                                  /* colNo */
  "O1_Slope_Fast",                     /* fName */
  "/Users/a1229158/Documents/GitHub/SingleFloeLinearModel/Overwash-Simulations/FirstOrderSlope-SWWE/Core/O1_Slope_Fast.m"/* pName */
};

static emlrtRTEInfo pb_emlrtRTEI = { 70,/* lineNo */
  95,                                  /* colNo */
  "O1_Slope_Fast",                     /* fName */
  "/Users/a1229158/Documents/GitHub/SingleFloeLinearModel/Overwash-Simulations/FirstOrderSlope-SWWE/Core/O1_Slope_Fast.m"/* pName */
};

static emlrtRTEInfo qb_emlrtRTEI = { 70,/* lineNo */
  109,                                 /* colNo */
  "O1_Slope_Fast",                     /* fName */
  "/Users/a1229158/Documents/GitHub/SingleFloeLinearModel/Overwash-Simulations/FirstOrderSlope-SWWE/Core/O1_Slope_Fast.m"/* pName */
};

static emlrtRTEInfo rb_emlrtRTEI = { 70,/* lineNo */
  124,                                 /* colNo */
  "O1_Slope_Fast",                     /* fName */
  "/Users/a1229158/Documents/GitHub/SingleFloeLinearModel/Overwash-Simulations/FirstOrderSlope-SWWE/Core/O1_Slope_Fast.m"/* pName */
};

static emlrtRTEInfo sb_emlrtRTEI = { 70,/* lineNo */
  150,                                 /* colNo */
  "O1_Slope_Fast",                     /* fName */
  "/Users/a1229158/Documents/GitHub/SingleFloeLinearModel/Overwash-Simulations/FirstOrderSlope-SWWE/Core/O1_Slope_Fast.m"/* pName */
};

static emlrtRTEInfo tb_emlrtRTEI = { 70,/* lineNo */
  1,                                   /* colNo */
  "O1_Slope_Fast",                     /* fName */
  "/Users/a1229158/Documents/GitHub/SingleFloeLinearModel/Overwash-Simulations/FirstOrderSlope-SWWE/Core/O1_Slope_Fast.m"/* pName */
};

static emlrtRTEInfo ub_emlrtRTEI = { 71,/* lineNo */
  1,                                   /* colNo */
  "O1_Slope_Fast",                     /* fName */
  "/Users/a1229158/Documents/GitHub/SingleFloeLinearModel/Overwash-Simulations/FirstOrderSlope-SWWE/Core/O1_Slope_Fast.m"/* pName */
};

static emlrtRTEInfo vb_emlrtRTEI = { 73,/* lineNo */
  10,                                  /* colNo */
  "O1_Slope_Fast",                     /* fName */
  "/Users/a1229158/Documents/GitHub/SingleFloeLinearModel/Overwash-Simulations/FirstOrderSlope-SWWE/Core/O1_Slope_Fast.m"/* pName */
};

static emlrtRTEInfo wb_emlrtRTEI = { 73,/* lineNo */
  53,                                  /* colNo */
  "O1_Slope_Fast",                     /* fName */
  "/Users/a1229158/Documents/GitHub/SingleFloeLinearModel/Overwash-Simulations/FirstOrderSlope-SWWE/Core/O1_Slope_Fast.m"/* pName */
};

static emlrtRTEInfo xb_emlrtRTEI = { 73,/* lineNo */
  96,                                  /* colNo */
  "O1_Slope_Fast",                     /* fName */
  "/Users/a1229158/Documents/GitHub/SingleFloeLinearModel/Overwash-Simulations/FirstOrderSlope-SWWE/Core/O1_Slope_Fast.m"/* pName */
};

static emlrtRTEInfo yb_emlrtRTEI = { 73,/* lineNo */
  110,                                 /* colNo */
  "O1_Slope_Fast",                     /* fName */
  "/Users/a1229158/Documents/GitHub/SingleFloeLinearModel/Overwash-Simulations/FirstOrderSlope-SWWE/Core/O1_Slope_Fast.m"/* pName */
};

static emlrtRTEInfo ac_emlrtRTEI = { 73,/* lineNo */
  125,                                 /* colNo */
  "O1_Slope_Fast",                     /* fName */
  "/Users/a1229158/Documents/GitHub/SingleFloeLinearModel/Overwash-Simulations/FirstOrderSlope-SWWE/Core/O1_Slope_Fast.m"/* pName */
};

static emlrtRTEInfo bc_emlrtRTEI = { 73,/* lineNo */
  151,                                 /* colNo */
  "O1_Slope_Fast",                     /* fName */
  "/Users/a1229158/Documents/GitHub/SingleFloeLinearModel/Overwash-Simulations/FirstOrderSlope-SWWE/Core/O1_Slope_Fast.m"/* pName */
};

static emlrtRTEInfo cc_emlrtRTEI = { 73,/* lineNo */
  1,                                   /* colNo */
  "O1_Slope_Fast",                     /* fName */
  "/Users/a1229158/Documents/GitHub/SingleFloeLinearModel/Overwash-Simulations/FirstOrderSlope-SWWE/Core/O1_Slope_Fast.m"/* pName */
};

static emlrtRTEInfo dc_emlrtRTEI = { 74,/* lineNo */
  1,                                   /* colNo */
  "O1_Slope_Fast",                     /* fName */
  "/Users/a1229158/Documents/GitHub/SingleFloeLinearModel/Overwash-Simulations/FirstOrderSlope-SWWE/Core/O1_Slope_Fast.m"/* pName */
};

static emlrtRTEInfo ec_emlrtRTEI = { 86,/* lineNo */
  1,                                   /* colNo */
  "O1_Slope_Fast",                     /* fName */
  "/Users/a1229158/Documents/GitHub/SingleFloeLinearModel/Overwash-Simulations/FirstOrderSlope-SWWE/Core/O1_Slope_Fast.m"/* pName */
};

static emlrtRTEInfo fc_emlrtRTEI = { 87,/* lineNo */
  1,                                   /* colNo */
  "O1_Slope_Fast",                     /* fName */
  "/Users/a1229158/Documents/GitHub/SingleFloeLinearModel/Overwash-Simulations/FirstOrderSlope-SWWE/Core/O1_Slope_Fast.m"/* pName */
};

static emlrtRTEInfo gc_emlrtRTEI = { 40,/* lineNo */
  1,                                   /* colNo */
  "O1_Slope_Fast",                     /* fName */
  "/Users/a1229158/Documents/GitHub/SingleFloeLinearModel/Overwash-Simulations/FirstOrderSlope-SWWE/Core/O1_Slope_Fast.m"/* pName */
};

static emlrtRTEInfo hc_emlrtRTEI = { 56,/* lineNo */
  1,                                   /* colNo */
  "O1_Slope_Fast",                     /* fName */
  "/Users/a1229158/Documents/GitHub/SingleFloeLinearModel/Overwash-Simulations/FirstOrderSlope-SWWE/Core/O1_Slope_Fast.m"/* pName */
};

static emlrtRTEInfo ic_emlrtRTEI = { 57,/* lineNo */
  1,                                   /* colNo */
  "O1_Slope_Fast",                     /* fName */
  "/Users/a1229158/Documents/GitHub/SingleFloeLinearModel/Overwash-Simulations/FirstOrderSlope-SWWE/Core/O1_Slope_Fast.m"/* pName */
};

static emlrtRTEInfo jc_emlrtRTEI = { 47,/* lineNo */
  48,                                  /* colNo */
  "O1_Slope_Fast",                     /* fName */
  "/Users/a1229158/Documents/GitHub/SingleFloeLinearModel/Overwash-Simulations/FirstOrderSlope-SWWE/Core/O1_Slope_Fast.m"/* pName */
};

static emlrtRTEInfo kc_emlrtRTEI = { 101,/* lineNo */
  1,                                   /* colNo */
  "O1_Slope_Fast",                     /* fName */
  "/Users/a1229158/Documents/GitHub/SingleFloeLinearModel/Overwash-Simulations/FirstOrderSlope-SWWE/Core/O1_Slope_Fast.m"/* pName */
};

static emlrtRSInfo ib_emlrtRSI = { 105,/* lineNo */
  "ReconstructO1",                     /* fcnName */
  "/Users/a1229158/Documents/GitHub/SingleFloeLinearModel/Overwash-Simulations/FirstOrderSlope-SWWE/Core/O1_Slope_Fast.m"/* pathName */
};

static emlrtRSInfo jb_emlrtRSI = { 104,/* lineNo */
  "ReconstructO1",                     /* fcnName */
  "/Users/a1229158/Documents/GitHub/SingleFloeLinearModel/Overwash-Simulations/FirstOrderSlope-SWWE/Core/O1_Slope_Fast.m"/* pathName */
};

/* Function Declarations */
static void FluxCalc(const emlrtStack *sp, const emxArray_real_T *Q, const
                     real_T QL[2], const real_T QR[2], real_T g, emxArray_real_T
                     *QFluxO, emxArray_real_T *QFluxI, real_T *MaxA, real_T
                     *EFlux_Left, real_T *EFlux_Right);
static void ReconstructO1(const emlrtStack *sp, const emxArray_real_T *Q, const
  real_T QL[2], const real_T QR[2], emxArray_real_T *RE_bc);
static int32_T div_s32_floor(const emlrtStack *sp, int32_T numerator, int32_T
  denominator);

/* Function Definitions */
static void FluxCalc(const emlrtStack *sp, const emxArray_real_T *Q, const
                     real_T QL[2], const real_T QR[2], real_T g, emxArray_real_T
                     *QFluxO, emxArray_real_T *QFluxI, real_T *MaxA, real_T
                     *EFlux_Left, real_T *EFlux_Right)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack st;
  emxArray_boolean_T *r1;
  emxArray_int32_T *r2;
  emxArray_real_T *Ajhm_bc;
  emxArray_real_T *Ajhp_bc;
  emxArray_real_T *FluxCoeff;
  emxArray_real_T *FluxH;
  emxArray_real_T *FluxUH;
  emxArray_real_T *FluxUHjm_bc;
  emxArray_real_T *REQ_bc;
  emxArray_real_T *b_REQ_bc;
  emxArray_real_T *c_REQ_bc;
  emxArray_real_T *r;
  emxArray_real_T *uEQ_bc;
  emxArray_real_T *varargin_1;
  real_T Ejm_Left_idx_0;
  real_T Ejm_Left_idx_1;
  real_T Ejm_Right_idx_0;
  real_T Ejm_Right_idx_1;
  real_T FluxEjm_Left_idx_0;
  real_T b_ex;
  real_T b_g;
  real_T b_idx_0;
  real_T b_idx_1;
  real_T d;
  real_T d1;
  real_T ex;
  int32_T iv[2];
  int32_T b_i;
  int32_T csz_idx_1;
  int32_T i;
  int32_T i1;
  int32_T loop_ub;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_real_T(sp, &REQ_bc, 2, &gc_emlrtRTEI, true);
  emxInit_real_T(sp, &b_REQ_bc, 2, &p_emlrtRTEI, true);

  /* Flux calculation */
  /*  n1 = size(Q,1); */
  st.site = &j_emlrtRSI;
  ReconstructO1(&st, Q, QL, QR, REQ_bc);

  /* u recontruction - modified to allow dry beds */
  loop_ub = REQ_bc->size[1];
  i = b_REQ_bc->size[0] * b_REQ_bc->size[1];
  b_REQ_bc->size[0] = 1;
  b_REQ_bc->size[1] = REQ_bc->size[1];
  emxEnsureCapacity_real_T(sp, b_REQ_bc, i, &p_emlrtRTEI);
  for (i = 0; i < loop_ub; i++) {
    b_REQ_bc->data[i] = REQ_bc->data[2 * i + 1];
  }

  emxInit_real_T(sp, &c_REQ_bc, 2, &q_emlrtRTEI, true);
  loop_ub = REQ_bc->size[1];
  i = c_REQ_bc->size[0] * c_REQ_bc->size[1];
  c_REQ_bc->size[0] = 1;
  c_REQ_bc->size[1] = REQ_bc->size[1];
  emxEnsureCapacity_real_T(sp, c_REQ_bc, i, &q_emlrtRTEI);
  for (i = 0; i < loop_ub; i++) {
    c_REQ_bc->data[i] = REQ_bc->data[2 * i];
  }

  emxInit_real_T(sp, &uEQ_bc, 2, &s_emlrtRTEI, true);
  emlrtSizeEqCheckNDR2012b(*(int32_T (*)[2])b_REQ_bc->size, *(int32_T (*)[2])
    c_REQ_bc->size, &v_emlrtECI, sp);
  st.site = &i_emlrtRSI;
  loop_ub = REQ_bc->size[1];
  i = uEQ_bc->size[0] * uEQ_bc->size[1];
  uEQ_bc->size[0] = 1;
  uEQ_bc->size[1] = REQ_bc->size[1];
  emxEnsureCapacity_real_T(&st, uEQ_bc, i, &p_emlrtRTEI);
  for (i = 0; i < loop_ub; i++) {
    uEQ_bc->data[i] = REQ_bc->data[2 * i + 1] * REQ_bc->data[2 * i];
  }

  loop_ub = REQ_bc->size[1];
  i = b_REQ_bc->size[0] * b_REQ_bc->size[1];
  b_REQ_bc->size[0] = 1;
  b_REQ_bc->size[1] = REQ_bc->size[1];
  emxEnsureCapacity_real_T(&st, b_REQ_bc, i, &r_emlrtRTEI);
  for (i = 0; i < loop_ub; i++) {
    b_REQ_bc->data[i] = REQ_bc->data[2 * i];
  }

  emxInit_real_T(&st, &FluxCoeff, 2, &kb_emlrtRTEI, true);
  b_st.site = &i_emlrtRSI;
  power(&b_st, b_REQ_bc, FluxCoeff);
  i = FluxCoeff->size[0] * FluxCoeff->size[1];
  b_i = FluxCoeff->size[0] * FluxCoeff->size[1];
  FluxCoeff->size[0] = 1;
  emxEnsureCapacity_real_T(&st, FluxCoeff, b_i, &r_emlrtRTEI);
  loop_ub = i - 1;
  for (i = 0; i <= loop_ub; i++) {
    FluxCoeff->data[i] += 2.2204460492503131E-16;
  }

  if (uEQ_bc->size[1] != FluxCoeff->size[1]) {
    emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI, "MATLAB:dimagree",
      "MATLAB:dimagree", 0);
  }

  i = uEQ_bc->size[0] * uEQ_bc->size[1];
  b_i = uEQ_bc->size[0] * uEQ_bc->size[1];
  uEQ_bc->size[0] = 1;
  emxEnsureCapacity_real_T(&st, uEQ_bc, b_i, &s_emlrtRTEI);
  loop_ub = i - 1;
  for (i = 0; i <= loop_ub; i++) {
    uEQ_bc->data[i] /= FluxCoeff->data[i];
  }

  /* Naive flux */
  loop_ub = uEQ_bc->size[1];
  i = c_REQ_bc->size[0] * c_REQ_bc->size[1];
  c_REQ_bc->size[0] = 1;
  c_REQ_bc->size[1] = uEQ_bc->size[1];
  emxEnsureCapacity_real_T(sp, c_REQ_bc, i, &t_emlrtRTEI);
  for (i = 0; i < loop_ub; i++) {
    c_REQ_bc->data[i] = uEQ_bc->data[i];
  }

  loop_ub = REQ_bc->size[1];
  i = b_REQ_bc->size[0] * b_REQ_bc->size[1];
  b_REQ_bc->size[0] = 1;
  b_REQ_bc->size[1] = REQ_bc->size[1];
  emxEnsureCapacity_real_T(sp, b_REQ_bc, i, &u_emlrtRTEI);
  for (i = 0; i < loop_ub; i++) {
    b_REQ_bc->data[i] = REQ_bc->data[2 * i + 1];
  }

  emxInit_real_T(sp, &FluxUHjm_bc, 2, &x_emlrtRTEI, true);
  emlrtSizeEqCheckNDR2012b(*(int32_T (*)[2])c_REQ_bc->size, *(int32_T (*)[2])
    b_REQ_bc->size, &u_emlrtECI, sp);
  loop_ub = uEQ_bc->size[1];
  i = FluxUHjm_bc->size[0] * FluxUHjm_bc->size[1];
  FluxUHjm_bc->size[0] = 1;
  FluxUHjm_bc->size[1] = uEQ_bc->size[1];
  emxEnsureCapacity_real_T(sp, FluxUHjm_bc, i, &t_emlrtRTEI);
  for (i = 0; i < loop_ub; i++) {
    FluxUHjm_bc->data[i] = uEQ_bc->data[i] * REQ_bc->data[2 * i + 1];
  }

  loop_ub = REQ_bc->size[1];
  i = b_REQ_bc->size[0] * b_REQ_bc->size[1];
  b_REQ_bc->size[0] = 1;
  b_REQ_bc->size[1] = REQ_bc->size[1];
  emxEnsureCapacity_real_T(sp, b_REQ_bc, i, &v_emlrtRTEI);
  for (i = 0; i < loop_ub; i++) {
    b_REQ_bc->data[i] = REQ_bc->data[2 * i];
  }

  emxInit_real_T(sp, &r, 2, &jc_emlrtRTEI, true);
  st.site = &h_emlrtRSI;
  power(&st, b_REQ_bc, r);
  i = r->size[0] * r->size[1];
  b_i = r->size[0] * r->size[1];
  r->size[0] = 1;
  emxEnsureCapacity_real_T(sp, r, b_i, &w_emlrtRTEI);
  b_g = g / 2.0;
  loop_ub = i - 1;
  for (i = 0; i <= loop_ub; i++) {
    r->data[i] *= b_g;
  }

  emlrtSizeEqCheckNDR2012b(*(int32_T (*)[2])FluxUHjm_bc->size, *(int32_T (*)[2])
    r->size, &u_emlrtECI, sp);
  i = FluxUHjm_bc->size[0] * FluxUHjm_bc->size[1];
  b_i = FluxUHjm_bc->size[0] * FluxUHjm_bc->size[1];
  FluxUHjm_bc->size[0] = 1;
  emxEnsureCapacity_real_T(sp, FluxUHjm_bc, b_i, &x_emlrtRTEI);
  loop_ub = i - 1;
  for (i = 0; i <= loop_ub; i++) {
    FluxUHjm_bc->data[i] += r->data[i];
  }

  b_g = REQ_bc->data[0];
  Ejm_Left_idx_0 = 0.5 * (uEQ_bc->data[0] * REQ_bc->data[1] + g * (b_g * b_g));
  b_g = REQ_bc->data[2];
  Ejm_Left_idx_1 = 0.5 * (uEQ_bc->data[1] * REQ_bc->data[3] + g * (b_g * b_g));
  if ((REQ_bc->size[1] + -1 < 1) || (REQ_bc->size[1] + -1 > REQ_bc->size[1])) {
    emlrtDynamicBoundsCheckR2012b(REQ_bc->size[1] + -1, 1, REQ_bc->size[1],
      &cb_emlrtBCI, sp);
  }

  if (REQ_bc->size[1] < 1) {
    emlrtDynamicBoundsCheckR2012b(REQ_bc->size[1], 1, REQ_bc->size[1],
      &cb_emlrtBCI, sp);
  }

  if ((uEQ_bc->size[1] - 1 < 1) || (uEQ_bc->size[1] - 1 > uEQ_bc->size[1])) {
    emlrtDynamicBoundsCheckR2012b(uEQ_bc->size[1] - 1, 1, uEQ_bc->size[1],
      &db_emlrtBCI, sp);
  }

  if ((REQ_bc->size[1] - 1 < 1) || (REQ_bc->size[1] - 1 > REQ_bc->size[1])) {
    emlrtDynamicBoundsCheckR2012b(REQ_bc->size[1] - 1, 1, REQ_bc->size[1],
      &eb_emlrtBCI, sp);
  }

  if (uEQ_bc->size[1] < 1) {
    emlrtDynamicBoundsCheckR2012b(uEQ_bc->size[1], 1, uEQ_bc->size[1],
      &db_emlrtBCI, sp);
  }

  if (REQ_bc->size[1] < 1) {
    emlrtDynamicBoundsCheckR2012b(REQ_bc->size[1], 1, REQ_bc->size[1],
      &eb_emlrtBCI, sp);
  }

  Ejm_Right_idx_0 = 0.5 * (uEQ_bc->data[uEQ_bc->size[1] - 2] * REQ_bc->data[2 *
    (REQ_bc->size[1] - 2) + 1] + g * (REQ_bc->data[2 * (REQ_bc->size[1] - 2)] *
    REQ_bc->data[2 * (REQ_bc->size[1] - 2)]));
  b_g = uEQ_bc->data[0];
  d = REQ_bc->data[1];
  FluxEjm_Left_idx_0 = 0.5 * (b_g * b_g) * d + g * d * REQ_bc->data[0];
  Ejm_Right_idx_1 = 0.5 * (uEQ_bc->data[uEQ_bc->size[1] - 1] * REQ_bc->data[2 *
    (REQ_bc->size[1] - 1) + 1] + g * (REQ_bc->data[2 * (REQ_bc->size[1] - 1)] *
    REQ_bc->data[2 * (REQ_bc->size[1] - 1)]));
  b_g = uEQ_bc->data[1];
  d = REQ_bc->data[3];
  if ((uEQ_bc->size[1] + -1 < 1) || (uEQ_bc->size[1] + -1 > uEQ_bc->size[1])) {
    emlrtDynamicBoundsCheckR2012b(uEQ_bc->size[1] + -1, 1, uEQ_bc->size[1],
      &fb_emlrtBCI, sp);
  }

  if (uEQ_bc->size[1] < 1) {
    emlrtDynamicBoundsCheckR2012b(uEQ_bc->size[1], 1, uEQ_bc->size[1],
      &fb_emlrtBCI, sp);
  }

  b_idx_0 = uEQ_bc->data[uEQ_bc->size[1] - 2] * uEQ_bc->data[uEQ_bc->size[1] - 2];
  b_idx_1 = uEQ_bc->data[uEQ_bc->size[1] - 1] * uEQ_bc->data[uEQ_bc->size[1] - 1];
  if ((REQ_bc->size[1] - 1 < 1) || (REQ_bc->size[1] - 1 > REQ_bc->size[1])) {
    emlrtDynamicBoundsCheckR2012b(REQ_bc->size[1] - 1, 1, REQ_bc->size[1],
      &gb_emlrtBCI, sp);
  }

  if (REQ_bc->size[1] < 1) {
    emlrtDynamicBoundsCheckR2012b(REQ_bc->size[1], 1, REQ_bc->size[1],
      &gb_emlrtBCI, sp);
  }

  /* Riemann charachteristics */
  i = (int32_T)(2.0 * ((real_T)Q->size[1] + 1.0));
  if ((i < 1) || (i > uEQ_bc->size[1])) {
    emlrtDynamicBoundsCheckR2012b(i, 1, uEQ_bc->size[1], &y_emlrtBCI, sp);
  }

  b_i = (int32_T)(2.0 * ((real_T)Q->size[1] + 1.0));
  if ((b_i < 1) || (b_i > REQ_bc->size[1])) {
    emlrtDynamicBoundsCheckR2012b(b_i, 1, REQ_bc->size[1], &x_emlrtBCI, sp);
  }

  emxInit_real_T(sp, &varargin_1, 2, &ab_emlrtRTEI, true);
  b_i = varargin_1->size[0] * varargin_1->size[1];
  varargin_1->size[0] = 1;
  loop_ub = (((Q->size[1] + 1) << 1) - 1) >> 1;
  varargin_1->size[1] = loop_ub + 1;
  emxEnsureCapacity_real_T(sp, varargin_1, b_i, &y_emlrtRTEI);
  for (b_i = 0; b_i <= loop_ub; b_i++) {
    varargin_1->data[b_i] = g * REQ_bc->data[2 * (b_i << 1)];
  }

  st.site = &g_emlrtRSI;
  b_sqrt(&st, varargin_1);
  b_i = c_REQ_bc->size[0] * c_REQ_bc->size[1];
  c_REQ_bc->size[0] = 1;
  loop_ub = (i - 1) >> 1;
  c_REQ_bc->size[1] = loop_ub + 1;
  emxEnsureCapacity_real_T(sp, c_REQ_bc, b_i, &ab_emlrtRTEI);
  for (b_i = 0; b_i <= loop_ub; b_i++) {
    c_REQ_bc->data[b_i] = uEQ_bc->data[b_i << 1];
  }

  emlrtSizeEqCheckNDR2012b(*(int32_T (*)[2])c_REQ_bc->size, *(int32_T (*)[2])
    varargin_1->size, &t_emlrtECI, sp);
  b_i = (int32_T)(2.0 * ((real_T)Q->size[1] + 1.0));
  if ((b_i < 1) || (b_i > uEQ_bc->size[1])) {
    emlrtDynamicBoundsCheckR2012b(b_i, 1, uEQ_bc->size[1], &w_emlrtBCI, sp);
  }

  i1 = (int32_T)(2.0 * ((real_T)Q->size[1] + 1.0));
  if ((i1 < 1) || (i1 > REQ_bc->size[1])) {
    emlrtDynamicBoundsCheckR2012b(i1, 1, REQ_bc->size[1], &v_emlrtBCI, sp);
  }

  emxInit_real_T(sp, &FluxH, 2, &tb_emlrtRTEI, true);
  i1 = FluxH->size[0] * FluxH->size[1];
  FluxH->size[0] = 1;
  csz_idx_1 = (((Q->size[1] + 1) << 1) - 2) >> 1;
  FluxH->size[1] = csz_idx_1 + 1;
  emxEnsureCapacity_real_T(sp, FluxH, i1, &bb_emlrtRTEI);
  for (i1 = 0; i1 <= csz_idx_1; i1++) {
    FluxH->data[i1] = g * REQ_bc->data[2 * ((i1 << 1) + 1)];
  }

  st.site = &g_emlrtRSI;
  b_sqrt(&st, FluxH);
  i1 = c_REQ_bc->size[0] * c_REQ_bc->size[1];
  c_REQ_bc->size[0] = 1;
  csz_idx_1 = (b_i - 2) >> 1;
  c_REQ_bc->size[1] = csz_idx_1 + 1;
  emxEnsureCapacity_real_T(sp, c_REQ_bc, i1, &cb_emlrtRTEI);
  for (i1 = 0; i1 <= csz_idx_1; i1++) {
    c_REQ_bc->data[i1] = uEQ_bc->data[(i1 << 1) + 1];
  }

  emlrtSizeEqCheckNDR2012b(*(int32_T (*)[2])c_REQ_bc->size, *(int32_T (*)[2])
    FluxH->size, &s_emlrtECI, sp);
  st.site = &g_emlrtRSI;
  i1 = varargin_1->size[0] * varargin_1->size[1];
  varargin_1->size[0] = 1;
  varargin_1->size[1] = ((i - 1) >> 1) + 1;
  emxEnsureCapacity_real_T(&st, varargin_1, i1, &ab_emlrtRTEI);
  for (i = 0; i <= loop_ub; i++) {
    varargin_1->data[i] = uEQ_bc->data[i << 1] - varargin_1->data[i];
  }

  i = FluxH->size[0] * FluxH->size[1];
  FluxH->size[0] = 1;
  FluxH->size[1] = ((b_i - 2) >> 1) + 1;
  emxEnsureCapacity_real_T(&st, FluxH, i, &cb_emlrtRTEI);
  for (i = 0; i <= csz_idx_1; i++) {
    FluxH->data[i] = uEQ_bc->data[(i << 1) + 1] - FluxH->data[i];
  }

  emxInit_real_T(&st, &FluxUH, 2, &cc_emlrtRTEI, true);
  b_st.site = &r_emlrtRSI;
  c_st.site = &s_emlrtRSI;
  d_st.site = &t_emlrtRSI;
  e_st.site = &u_emlrtRSI;
  f_st.site = &v_emlrtRSI;
  if (varargin_1->size[1] <= FluxH->size[1]) {
    csz_idx_1 = varargin_1->size[1];
  } else {
    csz_idx_1 = FluxH->size[1];
  }

  i = FluxUH->size[0] * FluxUH->size[1];
  FluxUH->size[0] = 1;
  if (varargin_1->size[1] <= FluxH->size[1]) {
    FluxUH->size[1] = varargin_1->size[1];
  } else {
    FluxUH->size[1] = FluxH->size[1];
  }

  emxEnsureCapacity_real_T(&f_st, FluxUH, i, &db_emlrtRTEI);
  if (!dimagree(FluxUH, varargin_1, FluxH)) {
    emlrtErrorWithMessageIdR2018a(&f_st, &d_emlrtRTEI, "MATLAB:dimagree",
      "MATLAB:dimagree", 0);
  }

  i = FluxCoeff->size[0] * FluxCoeff->size[1];
  FluxCoeff->size[0] = 1;
  FluxCoeff->size[1] = csz_idx_1;
  emxEnsureCapacity_real_T(&e_st, FluxCoeff, i, &m_emlrtRTEI);
  f_st.site = &m_emlrtRSI;
  for (loop_ub = 0; loop_ub < csz_idx_1; loop_ub++) {
    FluxCoeff->data[loop_ub] = muDoubleScalarMin(varargin_1->data[loop_ub],
      FluxH->data[loop_ub]);
  }

  emxInit_real_T(&f_st, &Ajhm_bc, 2, &hc_emlrtRTEI, true);
  st.site = &g_emlrtRSI;
  b_st.site = &r_emlrtRSI;
  c_st.site = &s_emlrtRSI;
  d_st.site = &t_emlrtRSI;
  e_st.site = &u_emlrtRSI;
  i = Ajhm_bc->size[0] * Ajhm_bc->size[1];
  Ajhm_bc->size[0] = 1;
  Ajhm_bc->size[1] = FluxCoeff->size[1];
  emxEnsureCapacity_real_T(&e_st, Ajhm_bc, i, &m_emlrtRTEI);
  csz_idx_1 = FluxCoeff->size[1];
  for (loop_ub = 0; loop_ub < csz_idx_1; loop_ub++) {
    Ajhm_bc->data[loop_ub] = muDoubleScalarMin(0.0, FluxCoeff->data[loop_ub]);
  }

  i = (int32_T)(2.0 * ((real_T)Q->size[1] + 1.0));
  if ((i < 1) || (i > uEQ_bc->size[1])) {
    emlrtDynamicBoundsCheckR2012b(i, 1, uEQ_bc->size[1], &u_emlrtBCI, sp);
  }

  b_i = (int32_T)(2.0 * ((real_T)Q->size[1] + 1.0));
  if ((b_i < 1) || (b_i > REQ_bc->size[1])) {
    emlrtDynamicBoundsCheckR2012b(b_i, 1, REQ_bc->size[1], &t_emlrtBCI, sp);
  }

  b_i = varargin_1->size[0] * varargin_1->size[1];
  varargin_1->size[0] = 1;
  loop_ub = (((Q->size[1] + 1) << 1) - 1) >> 1;
  varargin_1->size[1] = loop_ub + 1;
  emxEnsureCapacity_real_T(sp, varargin_1, b_i, &eb_emlrtRTEI);
  for (b_i = 0; b_i <= loop_ub; b_i++) {
    varargin_1->data[b_i] = g * REQ_bc->data[2 * (b_i << 1)];
  }

  st.site = &f_emlrtRSI;
  b_sqrt(&st, varargin_1);
  b_i = c_REQ_bc->size[0] * c_REQ_bc->size[1];
  c_REQ_bc->size[0] = 1;
  loop_ub = (i - 1) >> 1;
  c_REQ_bc->size[1] = loop_ub + 1;
  emxEnsureCapacity_real_T(sp, c_REQ_bc, b_i, &fb_emlrtRTEI);
  for (b_i = 0; b_i <= loop_ub; b_i++) {
    c_REQ_bc->data[b_i] = uEQ_bc->data[b_i << 1];
  }

  emlrtSizeEqCheckNDR2012b(*(int32_T (*)[2])c_REQ_bc->size, *(int32_T (*)[2])
    varargin_1->size, &r_emlrtECI, sp);
  b_i = (int32_T)(2.0 * ((real_T)Q->size[1] + 1.0));
  if ((b_i < 1) || (b_i > uEQ_bc->size[1])) {
    emlrtDynamicBoundsCheckR2012b(b_i, 1, uEQ_bc->size[1], &s_emlrtBCI, sp);
  }

  i1 = (int32_T)(2.0 * ((real_T)Q->size[1] + 1.0));
  if ((i1 < 1) || (i1 > REQ_bc->size[1])) {
    emlrtDynamicBoundsCheckR2012b(i1, 1, REQ_bc->size[1], &r_emlrtBCI, sp);
  }

  i1 = FluxH->size[0] * FluxH->size[1];
  FluxH->size[0] = 1;
  csz_idx_1 = (((Q->size[1] + 1) << 1) - 2) >> 1;
  FluxH->size[1] = csz_idx_1 + 1;
  emxEnsureCapacity_real_T(sp, FluxH, i1, &gb_emlrtRTEI);
  for (i1 = 0; i1 <= csz_idx_1; i1++) {
    FluxH->data[i1] = g * REQ_bc->data[2 * ((i1 << 1) + 1)];
  }

  st.site = &f_emlrtRSI;
  b_sqrt(&st, FluxH);
  i1 = c_REQ_bc->size[0] * c_REQ_bc->size[1];
  c_REQ_bc->size[0] = 1;
  csz_idx_1 = (b_i - 2) >> 1;
  c_REQ_bc->size[1] = csz_idx_1 + 1;
  emxEnsureCapacity_real_T(sp, c_REQ_bc, i1, &hb_emlrtRTEI);
  for (i1 = 0; i1 <= csz_idx_1; i1++) {
    c_REQ_bc->data[i1] = uEQ_bc->data[(i1 << 1) + 1];
  }

  emlrtSizeEqCheckNDR2012b(*(int32_T (*)[2])c_REQ_bc->size, *(int32_T (*)[2])
    FluxH->size, &q_emlrtECI, sp);
  st.site = &f_emlrtRSI;
  i1 = varargin_1->size[0] * varargin_1->size[1];
  varargin_1->size[0] = 1;
  varargin_1->size[1] = ((i - 1) >> 1) + 1;
  emxEnsureCapacity_real_T(&st, varargin_1, i1, &fb_emlrtRTEI);
  for (i = 0; i <= loop_ub; i++) {
    varargin_1->data[i] += uEQ_bc->data[i << 1];
  }

  i = FluxH->size[0] * FluxH->size[1];
  FluxH->size[0] = 1;
  FluxH->size[1] = ((b_i - 2) >> 1) + 1;
  emxEnsureCapacity_real_T(&st, FluxH, i, &hb_emlrtRTEI);
  for (i = 0; i <= csz_idx_1; i++) {
    FluxH->data[i] += uEQ_bc->data[(i << 1) + 1];
  }

  b_st.site = &y_emlrtRSI;
  c_st.site = &ab_emlrtRSI;
  d_st.site = &bb_emlrtRSI;
  e_st.site = &u_emlrtRSI;
  f_st.site = &v_emlrtRSI;
  if (varargin_1->size[1] <= FluxH->size[1]) {
    csz_idx_1 = varargin_1->size[1];
  } else {
    csz_idx_1 = FluxH->size[1];
  }

  i = FluxUH->size[0] * FluxUH->size[1];
  FluxUH->size[0] = 1;
  if (varargin_1->size[1] <= FluxH->size[1]) {
    FluxUH->size[1] = varargin_1->size[1];
  } else {
    FluxUH->size[1] = FluxH->size[1];
  }

  emxEnsureCapacity_real_T(&f_st, FluxUH, i, &db_emlrtRTEI);
  if (!dimagree(FluxUH, varargin_1, FluxH)) {
    emlrtErrorWithMessageIdR2018a(&f_st, &d_emlrtRTEI, "MATLAB:dimagree",
      "MATLAB:dimagree", 0);
  }

  i = FluxCoeff->size[0] * FluxCoeff->size[1];
  FluxCoeff->size[0] = 1;
  FluxCoeff->size[1] = csz_idx_1;
  emxEnsureCapacity_real_T(&e_st, FluxCoeff, i, &m_emlrtRTEI);
  f_st.site = &m_emlrtRSI;
  for (loop_ub = 0; loop_ub < csz_idx_1; loop_ub++) {
    FluxCoeff->data[loop_ub] = muDoubleScalarMax(varargin_1->data[loop_ub],
      FluxH->data[loop_ub]);
  }

  emxInit_real_T(&f_st, &Ajhp_bc, 2, &ic_emlrtRTEI, true);
  st.site = &f_emlrtRSI;
  b_st.site = &y_emlrtRSI;
  c_st.site = &ab_emlrtRSI;
  d_st.site = &bb_emlrtRSI;
  e_st.site = &u_emlrtRSI;
  i = Ajhp_bc->size[0] * Ajhp_bc->size[1];
  Ajhp_bc->size[0] = 1;
  Ajhp_bc->size[1] = FluxCoeff->size[1];
  emxEnsureCapacity_real_T(&e_st, Ajhp_bc, i, &m_emlrtRTEI);
  csz_idx_1 = FluxCoeff->size[1];
  for (loop_ub = 0; loop_ub < csz_idx_1; loop_ub++) {
    Ajhp_bc->data[loop_ub] = muDoubleScalarMax(0.0, FluxCoeff->data[loop_ub]);
  }

  /*  dt = CFL * dx / ( max(max(abs(Ajhm_bc )),max(abs(Ajhp_bc )))); */
  st.site = &e_emlrtRSI;
  b_st.site = &e_emlrtRSI;
  b_abs(&b_st, Ajhm_bc, varargin_1);
  b_st.site = &y_emlrtRSI;
  c_st.site = &eb_emlrtRSI;
  d_st.site = &fb_emlrtRSI;
  csz_idx_1 = varargin_1->size[1];
  if (varargin_1->size[1] <= 2) {
    if (varargin_1->size[1] == 1) {
      ex = varargin_1->data[0];
    } else if (varargin_1->data[0] < varargin_1->data[1]) {
      ex = varargin_1->data[1];
    } else {
      ex = varargin_1->data[0];
    }
  } else {
    ex = varargin_1->data[0];
    for (loop_ub = 2; loop_ub <= csz_idx_1; loop_ub++) {
      d1 = varargin_1->data[loop_ub - 1];
      if (ex < d1) {
        ex = d1;
      }
    }
  }

  st.site = &e_emlrtRSI;
  b_st.site = &e_emlrtRSI;
  b_abs(&b_st, Ajhp_bc, varargin_1);
  b_st.site = &y_emlrtRSI;
  c_st.site = &eb_emlrtRSI;
  d_st.site = &fb_emlrtRSI;
  csz_idx_1 = varargin_1->size[1];
  if (varargin_1->size[1] <= 2) {
    if (varargin_1->size[1] == 1) {
      b_ex = varargin_1->data[0];
    } else if (varargin_1->data[0] < varargin_1->data[1]) {
      b_ex = varargin_1->data[1];
    } else {
      b_ex = varargin_1->data[0];
    }
  } else {
    b_ex = varargin_1->data[0];
    for (loop_ub = 2; loop_ub <= csz_idx_1; loop_ub++) {
      d1 = varargin_1->data[loop_ub - 1];
      if (b_ex < d1) {
        b_ex = d1;
      }
    }
  }

  /* Kurganov Flux */
  /* Coefficient */
  loop_ub = Ajhp_bc->size[1];
  i = c_REQ_bc->size[0] * c_REQ_bc->size[1];
  c_REQ_bc->size[0] = 1;
  c_REQ_bc->size[1] = Ajhp_bc->size[1];
  emxEnsureCapacity_real_T(sp, c_REQ_bc, i, &ib_emlrtRTEI);
  for (i = 0; i < loop_ub; i++) {
    c_REQ_bc->data[i] = Ajhp_bc->data[i];
  }

  loop_ub = Ajhm_bc->size[1];
  i = uEQ_bc->size[0] * uEQ_bc->size[1];
  uEQ_bc->size[0] = 1;
  uEQ_bc->size[1] = Ajhm_bc->size[1];
  emxEnsureCapacity_real_T(sp, uEQ_bc, i, &jb_emlrtRTEI);
  for (i = 0; i < loop_ub; i++) {
    uEQ_bc->data[i] = Ajhm_bc->data[i];
  }

  emlrtSizeEqCheckNDR2012b(*(int32_T (*)[2])c_REQ_bc->size, *(int32_T (*)[2])
    uEQ_bc->size, &p_emlrtECI, sp);
  loop_ub = Ajhp_bc->size[1];
  i = FluxCoeff->size[0] * FluxCoeff->size[1];
  FluxCoeff->size[0] = 1;
  FluxCoeff->size[1] = Ajhp_bc->size[1];
  emxEnsureCapacity_real_T(sp, FluxCoeff, i, &kb_emlrtRTEI);
  for (i = 0; i < loop_ub; i++) {
    FluxCoeff->data[i] = 1.0 / (Ajhp_bc->data[i] - Ajhm_bc->data[i]);
  }

  emxInit_boolean_T(sp, &r1, 2, &lb_emlrtRTEI, true);
  i = r1->size[0] * r1->size[1];
  r1->size[0] = 1;
  r1->size[1] = FluxCoeff->size[1];
  emxEnsureCapacity_boolean_T(sp, r1, i, &lb_emlrtRTEI);
  loop_ub = FluxCoeff->size[0] * FluxCoeff->size[1];
  for (i = 0; i < loop_ub; i++) {
    r1->data[i] = muDoubleScalarIsInf(FluxCoeff->data[i]);
  }

  loop_ub = r1->size[1] - 1;
  csz_idx_1 = 0;
  for (b_i = 0; b_i <= loop_ub; b_i++) {
    if (r1->data[b_i]) {
      csz_idx_1++;
    }
  }

  emxInit_int32_T(sp, &r2, 2, &mb_emlrtRTEI, true);
  i = r2->size[0] * r2->size[1];
  r2->size[0] = 1;
  r2->size[1] = csz_idx_1;
  emxEnsureCapacity_int32_T(sp, r2, i, &mb_emlrtRTEI);
  csz_idx_1 = 0;
  for (b_i = 0; b_i <= loop_ub; b_i++) {
    if (r1->data[b_i]) {
      r2->data[csz_idx_1] = b_i + 1;
      csz_idx_1++;
    }
  }

  emxFree_boolean_T(&r1);
  loop_ub = r2->size[0] * r2->size[1] - 1;
  csz_idx_1 = FluxCoeff->size[1];
  for (i = 0; i <= loop_ub; i++) {
    if ((r2->data[i] < 1) || (r2->data[i] > csz_idx_1)) {
      emlrtDynamicBoundsCheckR2012b(r2->data[i], 1, csz_idx_1, &ab_emlrtBCI, sp);
    }

    FluxCoeff->data[r2->data[i] - 1] = 0.0;
  }

  emxFree_int32_T(&r2);

  /* Fluxes h, uh */
  i = (int32_T)(2.0 * ((real_T)Q->size[1] + 1.0));
  if ((i < 1) || (i > REQ_bc->size[1])) {
    emlrtDynamicBoundsCheckR2012b(i, 1, REQ_bc->size[1], &q_emlrtBCI, sp);
  }

  loop_ub = Ajhp_bc->size[1];
  b_i = c_REQ_bc->size[0] * c_REQ_bc->size[1];
  c_REQ_bc->size[0] = 1;
  c_REQ_bc->size[1] = Ajhp_bc->size[1];
  emxEnsureCapacity_real_T(sp, c_REQ_bc, b_i, &nb_emlrtRTEI);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    c_REQ_bc->data[b_i] = Ajhp_bc->data[b_i];
  }

  iv[0] = 1;
  iv[1] = ((i - 1) >> 1) + 1;
  emlrtSizeEqCheckNDR2012b(*(int32_T (*)[2])c_REQ_bc->size, iv, &n_emlrtECI, sp);
  i = (int32_T)(2.0 * ((real_T)Q->size[1] + 1.0));
  if ((i < 1) || (i > REQ_bc->size[1])) {
    emlrtDynamicBoundsCheckR2012b(i, 1, REQ_bc->size[1], &p_emlrtBCI, sp);
  }

  loop_ub = Ajhm_bc->size[1];
  b_i = uEQ_bc->size[0] * uEQ_bc->size[1];
  uEQ_bc->size[0] = 1;
  uEQ_bc->size[1] = Ajhm_bc->size[1];
  emxEnsureCapacity_real_T(sp, uEQ_bc, b_i, &ob_emlrtRTEI);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    uEQ_bc->data[b_i] = Ajhm_bc->data[b_i];
  }

  iv[0] = 1;
  iv[1] = ((i - 2) >> 1) + 1;
  emlrtSizeEqCheckNDR2012b(*(int32_T (*)[2])uEQ_bc->size, iv, &o_emlrtECI, sp);
  loop_ub = Ajhp_bc->size[1];
  i = FluxH->size[0] * FluxH->size[1];
  FluxH->size[0] = 1;
  FluxH->size[1] = Ajhp_bc->size[1];
  emxEnsureCapacity_real_T(sp, FluxH, i, &nb_emlrtRTEI);
  for (i = 0; i < loop_ub; i++) {
    FluxH->data[i] = Ajhp_bc->data[i] * REQ_bc->data[2 * (i << 1) + 1];
  }

  loop_ub = Ajhm_bc->size[1];
  i = r->size[0] * r->size[1];
  r->size[0] = 1;
  r->size[1] = Ajhm_bc->size[1];
  emxEnsureCapacity_real_T(sp, r, i, &ob_emlrtRTEI);
  for (i = 0; i < loop_ub; i++) {
    r->data[i] = Ajhm_bc->data[i] * REQ_bc->data[2 * ((i << 1) + 1) + 1];
  }

  emlrtSizeEqCheckNDR2012b(*(int32_T (*)[2])FluxH->size, *(int32_T (*)[2])
    r->size, &n_emlrtECI, sp);
  loop_ub = Ajhp_bc->size[1];
  i = c_REQ_bc->size[0] * c_REQ_bc->size[1];
  c_REQ_bc->size[0] = 1;
  c_REQ_bc->size[1] = Ajhp_bc->size[1];
  emxEnsureCapacity_real_T(sp, c_REQ_bc, i, &pb_emlrtRTEI);
  for (i = 0; i < loop_ub; i++) {
    c_REQ_bc->data[i] = Ajhp_bc->data[i];
  }

  loop_ub = Ajhm_bc->size[1];
  i = uEQ_bc->size[0] * uEQ_bc->size[1];
  uEQ_bc->size[0] = 1;
  uEQ_bc->size[1] = Ajhm_bc->size[1];
  emxEnsureCapacity_real_T(sp, uEQ_bc, i, &qb_emlrtRTEI);
  for (i = 0; i < loop_ub; i++) {
    uEQ_bc->data[i] = Ajhm_bc->data[i];
  }

  emlrtSizeEqCheckNDR2012b(*(int32_T (*)[2])c_REQ_bc->size, *(int32_T (*)[2])
    uEQ_bc->size, &l_emlrtECI, sp);
  i = (int32_T)(2.0 * ((real_T)Q->size[1] + 1.0));
  if ((i < 1) || (i > REQ_bc->size[1])) {
    emlrtDynamicBoundsCheckR2012b(i, 1, REQ_bc->size[1], &o_emlrtBCI, sp);
  }

  b_i = (int32_T)(2.0 * ((real_T)Q->size[1] + 1.0));
  if ((b_i < 1) || (b_i > REQ_bc->size[1])) {
    emlrtDynamicBoundsCheckR2012b(b_i, 1, REQ_bc->size[1], &n_emlrtBCI, sp);
  }

  i1 = b_REQ_bc->size[0] * b_REQ_bc->size[1];
  b_REQ_bc->size[0] = 1;
  loop_ub = (i - 2) >> 1;
  b_REQ_bc->size[1] = loop_ub + 1;
  emxEnsureCapacity_real_T(sp, b_REQ_bc, i1, &rb_emlrtRTEI);
  for (i1 = 0; i1 <= loop_ub; i1++) {
    b_REQ_bc->data[i1] = REQ_bc->data[2 * ((i1 << 1) + 1)];
  }

  i1 = c_REQ_bc->size[0] * c_REQ_bc->size[1];
  c_REQ_bc->size[0] = 1;
  csz_idx_1 = (b_i - 1) >> 1;
  c_REQ_bc->size[1] = csz_idx_1 + 1;
  emxEnsureCapacity_real_T(sp, c_REQ_bc, i1, &sb_emlrtRTEI);
  for (b_i = 0; b_i <= csz_idx_1; b_i++) {
    c_REQ_bc->data[b_i] = REQ_bc->data[2 * (b_i << 1)];
  }

  emlrtSizeEqCheckNDR2012b(*(int32_T (*)[2])b_REQ_bc->size, *(int32_T (*)[2])
    c_REQ_bc->size, &m_emlrtECI, sp);
  csz_idx_1 = Ajhp_bc->size[1];
  b_i = varargin_1->size[0] * varargin_1->size[1];
  varargin_1->size[0] = 1;
  varargin_1->size[1] = Ajhp_bc->size[1];
  emxEnsureCapacity_real_T(sp, varargin_1, b_i, &pb_emlrtRTEI);
  for (b_i = 0; b_i < csz_idx_1; b_i++) {
    varargin_1->data[b_i] = Ajhp_bc->data[b_i] * Ajhm_bc->data[b_i];
  }

  b_i = b_REQ_bc->size[0] * b_REQ_bc->size[1];
  b_REQ_bc->size[0] = 1;
  b_REQ_bc->size[1] = ((i - 2) >> 1) + 1;
  emxEnsureCapacity_real_T(sp, b_REQ_bc, b_i, &rb_emlrtRTEI);
  for (i = 0; i <= loop_ub; i++) {
    b_REQ_bc->data[i] = REQ_bc->data[2 * ((i << 1) + 1)];
  }

  emlrtSizeEqCheckNDR2012b(*(int32_T (*)[2])varargin_1->size, *(int32_T (*)[2])
    b_REQ_bc->size, &l_emlrtECI, sp);
  i = varargin_1->size[0] * varargin_1->size[1];
  varargin_1->size[0] = 1;
  emxEnsureCapacity_real_T(sp, varargin_1, i, &pb_emlrtRTEI);
  loop_ub = varargin_1->size[1];
  for (i = 0; i < loop_ub; i++) {
    csz_idx_1 = i << 1;
    varargin_1->data[i] *= REQ_bc->data[2 * (csz_idx_1 + 1)] - REQ_bc->data[2 *
      csz_idx_1];
  }

  emlrtSizeEqCheckNDR2012b(*(int32_T (*)[2])FluxH->size, *(int32_T (*)[2])
    varargin_1->size, &k_emlrtECI, sp);
  i = FluxH->size[0] * FluxH->size[1];
  b_i = FluxH->size[0] * FluxH->size[1];
  FluxH->size[0] = 1;
  emxEnsureCapacity_real_T(sp, FluxH, b_i, &tb_emlrtRTEI);
  loop_ub = i - 1;
  for (i = 0; i <= loop_ub; i++) {
    FluxH->data[i] = (FluxH->data[i] - r->data[i]) + varargin_1->data[i];
  }

  emlrtSizeEqCheckNDR2012b(*(int32_T (*)[2])FluxCoeff->size, *(int32_T (*)[2])
    FluxH->size, &j_emlrtECI, sp);
  i = FluxH->size[0] * FluxH->size[1];
  FluxH->size[0] = 1;
  FluxH->size[1] = FluxCoeff->size[1];
  emxEnsureCapacity_real_T(sp, FluxH, i, &ub_emlrtRTEI);
  loop_ub = FluxCoeff->size[0] * FluxCoeff->size[1] - 1;
  for (i = 0; i <= loop_ub; i++) {
    FluxH->data[i] *= FluxCoeff->data[i];
  }

  i = (int32_T)(2.0 * ((real_T)Q->size[1] + 1.0));
  if ((i < 1) || (i > FluxUHjm_bc->size[1])) {
    emlrtDynamicBoundsCheckR2012b(i, 1, FluxUHjm_bc->size[1], &m_emlrtBCI, sp);
  }

  loop_ub = Ajhp_bc->size[1];
  b_i = c_REQ_bc->size[0] * c_REQ_bc->size[1];
  c_REQ_bc->size[0] = 1;
  c_REQ_bc->size[1] = Ajhp_bc->size[1];
  emxEnsureCapacity_real_T(sp, c_REQ_bc, b_i, &vb_emlrtRTEI);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    c_REQ_bc->data[b_i] = Ajhp_bc->data[b_i];
  }

  iv[0] = 1;
  iv[1] = ((i - 1) >> 1) + 1;
  emlrtSizeEqCheckNDR2012b(*(int32_T (*)[2])c_REQ_bc->size, iv, &f_emlrtECI, sp);
  i = (int32_T)(2.0 * ((real_T)Q->size[1] + 1.0));
  if ((i < 1) || (i > FluxUHjm_bc->size[1])) {
    emlrtDynamicBoundsCheckR2012b(i, 1, FluxUHjm_bc->size[1], &l_emlrtBCI, sp);
  }

  loop_ub = Ajhm_bc->size[1];
  b_i = uEQ_bc->size[0] * uEQ_bc->size[1];
  uEQ_bc->size[0] = 1;
  uEQ_bc->size[1] = Ajhm_bc->size[1];
  emxEnsureCapacity_real_T(sp, uEQ_bc, b_i, &wb_emlrtRTEI);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    uEQ_bc->data[b_i] = Ajhm_bc->data[b_i];
  }

  iv[0] = 1;
  iv[1] = ((i - 2) >> 1) + 1;
  emlrtSizeEqCheckNDR2012b(*(int32_T (*)[2])uEQ_bc->size, iv, &i_emlrtECI, sp);
  loop_ub = Ajhp_bc->size[1];
  i = FluxUH->size[0] * FluxUH->size[1];
  FluxUH->size[0] = 1;
  FluxUH->size[1] = Ajhp_bc->size[1];
  emxEnsureCapacity_real_T(sp, FluxUH, i, &vb_emlrtRTEI);
  for (i = 0; i < loop_ub; i++) {
    FluxUH->data[i] = Ajhp_bc->data[i] * FluxUHjm_bc->data[i << 1];
  }

  loop_ub = Ajhm_bc->size[1];
  i = r->size[0] * r->size[1];
  r->size[0] = 1;
  r->size[1] = Ajhm_bc->size[1];
  emxEnsureCapacity_real_T(sp, r, i, &wb_emlrtRTEI);
  for (i = 0; i < loop_ub; i++) {
    r->data[i] = Ajhm_bc->data[i] * FluxUHjm_bc->data[(i << 1) + 1];
  }

  emxFree_real_T(&FluxUHjm_bc);
  emlrtSizeEqCheckNDR2012b(*(int32_T (*)[2])FluxUH->size, *(int32_T (*)[2])
    r->size, &f_emlrtECI, sp);
  loop_ub = Ajhp_bc->size[1];
  i = c_REQ_bc->size[0] * c_REQ_bc->size[1];
  c_REQ_bc->size[0] = 1;
  c_REQ_bc->size[1] = Ajhp_bc->size[1];
  emxEnsureCapacity_real_T(sp, c_REQ_bc, i, &xb_emlrtRTEI);
  for (i = 0; i < loop_ub; i++) {
    c_REQ_bc->data[i] = Ajhp_bc->data[i];
  }

  loop_ub = Ajhm_bc->size[1];
  i = uEQ_bc->size[0] * uEQ_bc->size[1];
  uEQ_bc->size[0] = 1;
  uEQ_bc->size[1] = Ajhm_bc->size[1];
  emxEnsureCapacity_real_T(sp, uEQ_bc, i, &yb_emlrtRTEI);
  for (i = 0; i < loop_ub; i++) {
    uEQ_bc->data[i] = Ajhm_bc->data[i];
  }

  emlrtSizeEqCheckNDR2012b(*(int32_T (*)[2])c_REQ_bc->size, *(int32_T (*)[2])
    uEQ_bc->size, &g_emlrtECI, sp);
  i = (int32_T)(2.0 * ((real_T)Q->size[1] + 1.0));
  emxFree_real_T(&uEQ_bc);
  if ((i < 1) || (i > REQ_bc->size[1])) {
    emlrtDynamicBoundsCheckR2012b(i, 1, REQ_bc->size[1], &k_emlrtBCI, sp);
  }

  b_i = (int32_T)(2.0 * ((real_T)Q->size[1] + 1.0));
  if ((b_i < 1) || (b_i > REQ_bc->size[1])) {
    emlrtDynamicBoundsCheckR2012b(b_i, 1, REQ_bc->size[1], &j_emlrtBCI, sp);
  }

  i1 = b_REQ_bc->size[0] * b_REQ_bc->size[1];
  b_REQ_bc->size[0] = 1;
  loop_ub = (i - 2) >> 1;
  b_REQ_bc->size[1] = loop_ub + 1;
  emxEnsureCapacity_real_T(sp, b_REQ_bc, i1, &ac_emlrtRTEI);
  for (i1 = 0; i1 <= loop_ub; i1++) {
    b_REQ_bc->data[i1] = REQ_bc->data[2 * ((i1 << 1) + 1) + 1];
  }

  i1 = c_REQ_bc->size[0] * c_REQ_bc->size[1];
  c_REQ_bc->size[0] = 1;
  csz_idx_1 = (b_i - 1) >> 1;
  c_REQ_bc->size[1] = csz_idx_1 + 1;
  emxEnsureCapacity_real_T(sp, c_REQ_bc, i1, &bc_emlrtRTEI);
  for (b_i = 0; b_i <= csz_idx_1; b_i++) {
    c_REQ_bc->data[b_i] = REQ_bc->data[2 * (b_i << 1) + 1];
  }

  emlrtSizeEqCheckNDR2012b(*(int32_T (*)[2])b_REQ_bc->size, *(int32_T (*)[2])
    c_REQ_bc->size, &h_emlrtECI, sp);
  csz_idx_1 = Ajhp_bc->size[1];
  b_i = varargin_1->size[0] * varargin_1->size[1];
  varargin_1->size[0] = 1;
  varargin_1->size[1] = Ajhp_bc->size[1];
  emxEnsureCapacity_real_T(sp, varargin_1, b_i, &xb_emlrtRTEI);
  emxFree_real_T(&c_REQ_bc);
  for (b_i = 0; b_i < csz_idx_1; b_i++) {
    varargin_1->data[b_i] = Ajhp_bc->data[b_i] * Ajhm_bc->data[b_i];
  }

  b_i = b_REQ_bc->size[0] * b_REQ_bc->size[1];
  b_REQ_bc->size[0] = 1;
  b_REQ_bc->size[1] = ((i - 2) >> 1) + 1;
  emxEnsureCapacity_real_T(sp, b_REQ_bc, b_i, &ac_emlrtRTEI);
  for (i = 0; i <= loop_ub; i++) {
    b_REQ_bc->data[i] = REQ_bc->data[2 * ((i << 1) + 1) + 1];
  }

  emlrtSizeEqCheckNDR2012b(*(int32_T (*)[2])varargin_1->size, *(int32_T (*)[2])
    b_REQ_bc->size, &g_emlrtECI, sp);
  i = varargin_1->size[0] * varargin_1->size[1];
  varargin_1->size[0] = 1;
  emxEnsureCapacity_real_T(sp, varargin_1, i, &xb_emlrtRTEI);
  loop_ub = varargin_1->size[1];
  emxFree_real_T(&b_REQ_bc);
  for (i = 0; i < loop_ub; i++) {
    csz_idx_1 = i << 1;
    varargin_1->data[i] *= REQ_bc->data[2 * (csz_idx_1 + 1) + 1] - REQ_bc->data
      [2 * csz_idx_1 + 1];
  }

  emlrtSizeEqCheckNDR2012b(*(int32_T (*)[2])FluxUH->size, *(int32_T (*)[2])
    varargin_1->size, &f_emlrtECI, sp);
  i = FluxUH->size[0] * FluxUH->size[1];
  b_i = FluxUH->size[0] * FluxUH->size[1];
  FluxUH->size[0] = 1;
  emxEnsureCapacity_real_T(sp, FluxUH, b_i, &cc_emlrtRTEI);
  loop_ub = i - 1;
  for (i = 0; i <= loop_ub; i++) {
    FluxUH->data[i] = (FluxUH->data[i] - r->data[i]) + varargin_1->data[i];
  }

  emxFree_real_T(&r);
  emxFree_real_T(&varargin_1);
  emlrtSizeEqCheckNDR2012b(*(int32_T (*)[2])FluxCoeff->size, *(int32_T (*)[2])
    FluxUH->size, &e_emlrtECI, sp);
  i = FluxUH->size[0] * FluxUH->size[1];
  FluxUH->size[0] = 1;
  FluxUH->size[1] = FluxCoeff->size[1];
  emxEnsureCapacity_real_T(sp, FluxUH, i, &dc_emlrtRTEI);
  loop_ub = FluxCoeff->size[0] * FluxCoeff->size[1] - 1;
  for (i = 0; i <= loop_ub; i++) {
    FluxUH->data[i] *= FluxCoeff->data[i];
  }

  *EFlux_Left = FluxCoeff->data[0] * ((Ajhp_bc->data[0] * FluxEjm_Left_idx_0 -
    Ajhm_bc->data[0] * (0.5 * (b_g * b_g) * d + g * d * REQ_bc->data[2])) +
    Ajhp_bc->data[0] * Ajhm_bc->data[0] * (Ejm_Left_idx_1 - Ejm_Left_idx_0));
  if (Ajhp_bc->size[1] < 1) {
    emlrtDynamicBoundsCheckR2012b(Ajhp_bc->size[1], 1, Ajhp_bc->size[1],
      &i_emlrtBCI, sp);
  }

  if (Ajhm_bc->size[1] < 1) {
    emlrtDynamicBoundsCheckR2012b(Ajhm_bc->size[1], 1, Ajhm_bc->size[1],
      &h_emlrtBCI, sp);
  }

  if (Ajhp_bc->size[1] < 1) {
    emlrtDynamicBoundsCheckR2012b(Ajhp_bc->size[1], 1, Ajhp_bc->size[1],
      &g_emlrtBCI, sp);
  }

  if (Ajhm_bc->size[1] < 1) {
    emlrtDynamicBoundsCheckR2012b(Ajhm_bc->size[1], 1, Ajhm_bc->size[1],
      &f_emlrtBCI, sp);
  }

  if (FluxCoeff->size[1] < 1) {
    emlrtDynamicBoundsCheckR2012b(FluxCoeff->size[1], 1, FluxCoeff->size[1],
      &bb_emlrtBCI, sp);
  }

  *EFlux_Right = FluxCoeff->data[FluxCoeff->size[1] - 1] * ((Ajhp_bc->
    data[Ajhp_bc->size[1] - 1] * (0.5 * b_idx_0 * REQ_bc->data[2 * (REQ_bc->
    size[1] - 2) + 1] + g * REQ_bc->data[2 * (REQ_bc->size[1] - 2) + 1] *
    REQ_bc->data[2 * (REQ_bc->size[1] - 2)]) - Ajhm_bc->data[Ajhm_bc->size[1] -
    1] * (0.5 * b_idx_1 * REQ_bc->data[2 * (REQ_bc->size[1] - 1) + 1] + g *
          REQ_bc->data[2 * (REQ_bc->size[1] - 1) + 1] * REQ_bc->data[2 *
          (REQ_bc->size[1] - 1)])) + Ajhp_bc->data[Ajhp_bc->size[1] - 1] *
    Ajhm_bc->data[Ajhm_bc->size[1] - 1] * (Ejm_Right_idx_1 - Ejm_Right_idx_0));

  /*  EFlux_Right =  */
  /* Flux in and out */
  emxFree_real_T(&FluxCoeff);
  emxFree_real_T(&Ajhp_bc);
  emxFree_real_T(&Ajhm_bc);
  emxFree_real_T(&REQ_bc);
  if (1 > FluxH->size[1] - 1) {
    loop_ub = 0;
  } else {
    if ((FluxH->size[1] - 1 < 1) || (FluxH->size[1] - 1 > FluxH->size[1])) {
      emlrtDynamicBoundsCheckR2012b(FluxH->size[1] - 1, 1, FluxH->size[1],
        &e_emlrtBCI, sp);
    }

    loop_ub = FluxH->size[1] - 1;
  }

  if (1 > FluxUH->size[1] - 1) {
    csz_idx_1 = 0;
  } else {
    if ((FluxUH->size[1] - 1 < 1) || (FluxUH->size[1] - 1 > FluxUH->size[1])) {
      emlrtDynamicBoundsCheckR2012b(FluxUH->size[1] - 1, 1, FluxUH->size[1],
        &d_emlrtBCI, sp);
    }

    csz_idx_1 = FluxUH->size[1] - 1;
  }

  st.site = &d_emlrtRSI;
  b_st.site = &gb_emlrtRSI;
  c_st.site = &hb_emlrtRSI;
  if (csz_idx_1 != loop_ub) {
    emlrtErrorWithMessageIdR2018a(&c_st, &b_emlrtRTEI,
      "MATLAB:catenate:matrixDimensionMismatch",
      "MATLAB:catenate:matrixDimensionMismatch", 0);
  }

  i = QFluxI->size[0] * QFluxI->size[1];
  QFluxI->size[0] = 2;
  QFluxI->size[1] = loop_ub;
  emxEnsureCapacity_real_T(&b_st, QFluxI, i, &ec_emlrtRTEI);
  for (i = 0; i < loop_ub; i++) {
    QFluxI->data[2 * i] = FluxH->data[i];
  }

  for (i = 0; i < csz_idx_1; i++) {
    QFluxI->data[2 * i + 1] = FluxUH->data[i];
  }

  if (2 > FluxH->size[1]) {
    i = -1;
    b_i = -1;
  } else {
    i = 0;
    if (FluxH->size[1] < 1) {
      emlrtDynamicBoundsCheckR2012b(FluxH->size[1], 1, FluxH->size[1],
        &c_emlrtBCI, sp);
    }

    b_i = FluxH->size[1] - 1;
  }

  if (2 > FluxUH->size[1]) {
    i1 = 0;
    csz_idx_1 = -1;
  } else {
    i1 = 1;
    if (FluxUH->size[1] < 1) {
      emlrtDynamicBoundsCheckR2012b(FluxUH->size[1], 1, FluxUH->size[1],
        &b_emlrtBCI, sp);
    }

    csz_idx_1 = FluxUH->size[1] - 1;
  }

  st.site = &c_emlrtRSI;
  b_st.site = &gb_emlrtRSI;
  c_st.site = &hb_emlrtRSI;
  loop_ub = b_i - i;
  csz_idx_1 -= i1;
  if (csz_idx_1 + 1 != loop_ub) {
    emlrtErrorWithMessageIdR2018a(&c_st, &b_emlrtRTEI,
      "MATLAB:catenate:matrixDimensionMismatch",
      "MATLAB:catenate:matrixDimensionMismatch", 0);
  }

  b_i = QFluxO->size[0] * QFluxO->size[1];
  QFluxO->size[0] = 2;
  QFluxO->size[1] = loop_ub;
  emxEnsureCapacity_real_T(&b_st, QFluxO, b_i, &fc_emlrtRTEI);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    QFluxO->data[2 * b_i] = FluxH->data[(i + b_i) + 1];
  }

  emxFree_real_T(&FluxH);
  for (i = 0; i <= csz_idx_1; i++) {
    QFluxO->data[2 * i + 1] = FluxUH->data[i1 + i];
  }

  emxFree_real_T(&FluxUH);

  /*  if ~isreal(QFluxI) */
  /*       x = 1 */
  /*  end */
  *MaxA = muDoubleScalarMax(ex, b_ex);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

static void ReconstructO1(const emlrtStack *sp, const emxArray_real_T *Q, const
  real_T QL[2], const real_T QR[2], emxArray_real_T *RE_bc)
{
  emlrtStack st;
  real_T d;
  int32_T iv[2];
  int32_T iv1[2];
  int32_T RE_bc_tmp;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T loop_ub;
  uint32_T u;
  st.prev = sp;
  st.tls = sp->tls;

  /* Reconstruct first order */
  i = RE_bc->size[0] * RE_bc->size[1];
  RE_bc->size[0] = 2;
  emxEnsureCapacity_real_T(sp, RE_bc, i, &kc_emlrtRTEI);
  d = 2.0 * ((real_T)Q->size[1] + 1.0);
  if (d != (int32_T)d) {
    emlrtIntegerCheckR2012b(d, &emlrtDCI, sp);
  }

  i = RE_bc->size[0] * RE_bc->size[1];
  RE_bc->size[1] = (int32_T)d;
  emxEnsureCapacity_real_T(sp, RE_bc, i, &kc_emlrtRTEI);
  d = 2.0 * ((real_T)Q->size[1] + 1.0);
  if (d != (int32_T)d) {
    emlrtIntegerCheckR2012b(d, &b_emlrtDCI, sp);
  }

  loop_ub = (int32_T)d << 1;
  for (i = 0; i < loop_ub; i++) {
    RE_bc->data[i] = 0.0;
  }

  /*   */
  RE_bc->data[0] = QL[0];
  RE_bc->data[1] = QL[1];
  if (1 > Q->size[1]) {
    loop_ub = 0;
  } else {
    if (Q->size[1] < 1) {
      emlrtDynamicBoundsCheckR2012b(Q->size[1], 1, Q->size[1], &hb_emlrtBCI, sp);
    }

    loop_ub = Q->size[1];
  }

  u = (uint32_T)Q->size[1] << 1;
  if (2U > u) {
    i = 1;
    i1 = 1;
    i2 = 0;
  } else {
    i = 2;
    i1 = 2;
    if (((int32_T)u < 1) || ((int32_T)u > RE_bc->size[1])) {
      emlrtDynamicBoundsCheckR2012b((int32_T)u, 1, RE_bc->size[1], &jb_emlrtBCI,
        sp);
    }

    i2 = (int32_T)u;
  }

  iv[0] = 2;
  st.site = &jb_emlrtRSI;
  iv[1] = div_s32_floor(&st, i2 - i, i1) + 1;
  iv1[0] = 2;
  iv1[1] = loop_ub;
  emlrtSubAssignSizeCheckR2012b(&iv[0], 2, &iv1[0], 2, &w_emlrtECI, sp);
  for (i2 = 0; i2 < loop_ub; i2++) {
    RE_bc_tmp = (i + i1 * i2) - 1;
    RE_bc->data[2 * RE_bc_tmp] = Q->data[2 * i2];
    RE_bc->data[2 * RE_bc_tmp + 1] = Q->data[2 * i2 + 1];
  }

  if (1 > Q->size[1]) {
    loop_ub = 0;
  } else {
    if (Q->size[1] < 1) {
      emlrtDynamicBoundsCheckR2012b(Q->size[1], 1, Q->size[1], &ib_emlrtBCI, sp);
    }

    loop_ub = Q->size[1];
  }

  u = ((uint32_T)Q->size[1] << 1) + 1U;
  if (3U > u) {
    i = 1;
    i1 = 1;
    i2 = 0;
  } else {
    if (3 > RE_bc->size[1]) {
      emlrtDynamicBoundsCheckR2012b(3, 1, RE_bc->size[1], &kb_emlrtBCI, sp);
    }

    i = 3;
    i1 = 2;
    if (((int32_T)u < 1) || ((int32_T)u > RE_bc->size[1])) {
      emlrtDynamicBoundsCheckR2012b((int32_T)u, 1, RE_bc->size[1], &lb_emlrtBCI,
        sp);
    }

    i2 = (int32_T)u;
  }

  iv[0] = 2;
  st.site = &ib_emlrtRSI;
  iv[1] = div_s32_floor(&st, i2 - i, i1) + 1;
  iv1[0] = 2;
  iv1[1] = loop_ub;
  emlrtSubAssignSizeCheckR2012b(&iv[0], 2, &iv1[0], 2, &x_emlrtECI, sp);
  for (i2 = 0; i2 < loop_ub; i2++) {
    RE_bc_tmp = (i + i1 * i2) - 1;
    RE_bc->data[2 * RE_bc_tmp] = Q->data[2 * i2];
    RE_bc->data[2 * RE_bc_tmp + 1] = Q->data[2 * i2 + 1];
  }

  i = (int32_T)(2.0 * ((real_T)Q->size[1] + 1.0));
  if ((i < 1) || (i > RE_bc->size[1])) {
    emlrtDynamicBoundsCheckR2012b(i, 1, RE_bc->size[1], &mb_emlrtBCI, sp);
  }

  i = 2 * (i - 1);
  RE_bc->data[i] = QR[0];
  RE_bc->data[i + 1] = QR[1];
}

static int32_T div_s32_floor(const emlrtStack *sp, int32_T numerator, int32_T
  denominator)
{
  int32_T quotient;
  uint32_T absDenominator;
  uint32_T absNumerator;
  uint32_T tempAbsQuotient;
  boolean_T quotientNeedsNegation;
  if (denominator == 0) {
    emlrtDivisionByZeroErrorR2012b(NULL, sp);
  } else {
    if (numerator < 0) {
      absNumerator = ~(uint32_T)numerator + 1U;
    } else {
      absNumerator = (uint32_T)numerator;
    }

    if (denominator < 0) {
      absDenominator = ~(uint32_T)denominator + 1U;
    } else {
      absDenominator = (uint32_T)denominator;
    }

    quotientNeedsNegation = ((numerator < 0) != (denominator < 0));
    tempAbsQuotient = absNumerator / absDenominator;
    if (quotientNeedsNegation) {
      absNumerator %= absDenominator;
      if (absNumerator > 0U) {
        tempAbsQuotient++;
      }

      quotient = -(int32_T)tempAbsQuotient;
    } else {
      quotient = (int32_T)tempAbsQuotient;
    }
  }

  return quotient;
}

void O1_Slope_Fast(const emlrtStack *sp, const emxArray_real_T *Q, const real_T
                   QL[2], const real_T QR[2], real_T bx, real_T g, real_T dx,
                   real_T CFL, real_T dtmin, real_T dtmax, emxArray_real_T *nQ,
                   real_T *dt, real_T *EFlux_Left, real_T *EFlux_Right)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack h_st;
  emlrtStack st;
  emxArray_boolean_T *r;
  emxArray_int32_T *r1;
  emxArray_real_T *QFluxI;
  emxArray_real_T *QSource;
  emxArray_real_T *b_nQ;
  emxArray_real_T *z1;
  real_T MaxA;
  real_T a;
  int32_T iv[2];
  int32_T i;
  int32_T k;
  int32_T nx;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  g_st.prev = &f_st;
  g_st.tls = f_st.tls;
  h_st.prev = &g_st;
  h_st.tls = g_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_real_T(sp, &QSource, 2, &g_emlrtRTEI, true);
  emxInit_real_T(sp, &QFluxI, 2, &o_emlrtRTEI, true);

  /* I verified analytic solutions for flat bed, with both dam break (dry and wet) */
  /* Calculate fluxes */
  st.site = &emlrtRSI;
  FluxCalc(&st, Q, QL, QR, g, nQ, QFluxI, &MaxA, EFlux_Left, EFlux_Right);

  /* Body source term - gh_ibx */
  i = QSource->size[0] * QSource->size[1];
  QSource->size[0] = 2;
  QSource->size[1] = Q->size[1];
  emxEnsureCapacity_real_T(sp, QSource, i, &g_emlrtRTEI);
  nx = Q->size[1] << 1;
  for (i = 0; i < nx; i++) {
    QSource->data[i] = 0.0;
  }

  emxInit_real_T(sp, &b_nQ, 2, &l_emlrtRTEI, true);
  a = -g * bx;
  nx = Q->size[1];
  i = b_nQ->size[0] * b_nQ->size[1];
  b_nQ->size[0] = 1;
  b_nQ->size[1] = Q->size[1];
  emxEnsureCapacity_real_T(sp, b_nQ, i, &h_emlrtRTEI);
  for (i = 0; i < nx; i++) {
    b_nQ->data[i] = a * Q->data[2 * i];
  }

  iv[0] = 1;
  iv[1] = Q->size[1];
  emlrtSubAssignSizeCheckR2012b(&iv[0], 2, &b_nQ->size[0], 2, &c_emlrtECI, sp);
  nx = b_nQ->size[1];
  for (i = 0; i < nx; i++) {
    QSource->data[2 * i + 1] = b_nQ->data[i];
  }

  /* evolve dt */
  /*      if isinf(dt) */
  /*          dt = dtmin; */
  /*      end */
  *dt = muDoubleScalarMin(muDoubleScalarMax(dx * (CFL / MaxA), dtmin), dtmax);

  /* time step */
  emlrtSizeEqCheckNDR2012b(*(int32_T (*)[2])nQ->size, *(int32_T (*)[2])
    QFluxI->size, &emlrtECI, sp);
  a = *dt / dx;
  nx = nQ->size[0] * nQ->size[1];
  i = nQ->size[0] * nQ->size[1];
  nQ->size[0] = 2;
  emxEnsureCapacity_real_T(sp, nQ, i, &i_emlrtRTEI);
  for (i = 0; i < nx; i++) {
    nQ->data[i] = a * (nQ->data[i] - QFluxI->data[i]);
  }

  emxFree_real_T(&QFluxI);
  emlrtSizeEqCheckNDR2012b(*(int32_T (*)[2])Q->size, *(int32_T (*)[2])nQ->size,
    &b_emlrtECI, sp);
  nx = QSource->size[0] * QSource->size[1];
  i = QSource->size[0] * QSource->size[1];
  QSource->size[0] = 2;
  emxEnsureCapacity_real_T(sp, QSource, i, &j_emlrtRTEI);
  for (i = 0; i < nx; i++) {
    QSource->data[i] *= *dt;
  }

  emlrtSizeEqCheckNDR2012b(*(int32_T (*)[2])Q->size, *(int32_T (*)[2])
    QSource->size, &b_emlrtECI, sp);
  nx = Q->size[0] * Q->size[1];
  i = nQ->size[0] * nQ->size[1];
  nQ->size[0] = 2;
  nQ->size[1] = Q->size[1];
  emxEnsureCapacity_real_T(sp, nQ, i, &k_emlrtRTEI);
  for (i = 0; i < nx; i++) {
    nQ->data[i] = (Q->data[i] - nQ->data[i]) + QSource->data[i];
  }

  emxFree_real_T(&QSource);
  st.site = &b_emlrtRSI;
  b_st.site = &y_emlrtRSI;
  c_st.site = &ab_emlrtRSI;
  d_st.site = &bb_emlrtRSI;
  e_st.site = &u_emlrtRSI;
  nx = nQ->size[1];
  i = b_nQ->size[0] * b_nQ->size[1];
  b_nQ->size[0] = 1;
  b_nQ->size[1] = nQ->size[1];
  emxEnsureCapacity_real_T(&e_st, b_nQ, i, &l_emlrtRTEI);
  for (i = 0; i < nx; i++) {
    b_nQ->data[i] = nQ->data[2 * i];
  }

  emxInit_real_T(&e_st, &z1, 2, &o_emlrtRTEI, true);
  i = z1->size[0] * z1->size[1];
  z1->size[0] = 1;
  z1->size[1] = b_nQ->size[1];
  emxEnsureCapacity_real_T(&e_st, z1, i, &m_emlrtRTEI);
  f_st.site = &m_emlrtRSI;
  nx = b_nQ->size[1];
  g_st.site = &n_emlrtRSI;
  if ((1 <= b_nQ->size[1]) && (b_nQ->size[1] > 2147483646)) {
    h_st.site = &o_emlrtRSI;
    check_forloop_overflow_error(&h_st);
  }

  emxFree_real_T(&b_nQ);
  for (k = 0; k < nx; k++) {
    z1->data[k] = muDoubleScalarMax(nQ->data[2 * k], 0.0);
  }

  iv[0] = 1;
  iv[1] = nQ->size[1];
  emlrtSubAssignSizeCheckR2012b(&iv[0], 2, &z1->size[0], 2, &d_emlrtECI, sp);
  nx = z1->size[1];
  for (i = 0; i < nx; i++) {
    nQ->data[2 * i] = z1->data[i];
  }

  emxFree_real_T(&z1);
  emxInit_boolean_T(sp, &r, 2, &n_emlrtRTEI, true);
  nx = nQ->size[1];
  i = r->size[0] * r->size[1];
  r->size[0] = 1;
  r->size[1] = nQ->size[1];
  emxEnsureCapacity_boolean_T(sp, r, i, &n_emlrtRTEI);
  for (i = 0; i < nx; i++) {
    r->data[i] = (nQ->data[2 * i] <= 0.0);
  }

  k = r->size[1] - 1;
  nx = 0;
  for (i = 0; i <= k; i++) {
    if (r->data[i]) {
      nx++;
    }
  }

  emxInit_int32_T(sp, &r1, 2, &n_emlrtRTEI, true);
  i = r1->size[0] * r1->size[1];
  r1->size[0] = 1;
  r1->size[1] = nx;
  emxEnsureCapacity_int32_T(sp, r1, i, &o_emlrtRTEI);
  nx = 0;
  for (i = 0; i <= k; i++) {
    if (r->data[i]) {
      r1->data[nx] = i + 1;
      nx++;
    }
  }

  emxFree_boolean_T(&r);
  k = nQ->size[1];
  nx = r1->size[1];
  for (i = 0; i < nx; i++) {
    if ((r1->data[i] < 1) || (r1->data[i] > k)) {
      emlrtDynamicBoundsCheckR2012b(r1->data[i], 1, k, &emlrtBCI, sp);
    }

    nQ->data[2 * (r1->data[i] - 1) + 1] = 0.0;
  }

  emxFree_int32_T(&r1);
  *EFlux_Left *= *dt;
  *EFlux_Right *= *dt;
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (O1_Slope_Fast.c) */
