/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * O1_Slope_Fast.h
 *
 * Code generation for function 'O1_Slope_Fast'
 *
 */

#pragma once

/* Include files */
#include "O1_Slope_Fast_types.h"
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
void O1_Slope_Fast(const emlrtStack *sp, const emxArray_real_T *Q, const real_T
                   QL[2], const real_T QR[2], real_T bx, real_T g, real_T dx,
                   real_T CFL, real_T dtmin, real_T dtmax, emxArray_real_T *nQ,
                   real_T *dt, real_T *EFlux_Left, real_T *EFlux_Right);

/* End of code generation (O1_Slope_Fast.h) */
