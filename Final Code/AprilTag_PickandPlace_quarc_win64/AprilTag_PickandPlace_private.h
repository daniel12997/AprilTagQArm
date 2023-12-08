/*
 * AprilTag_PickandPlace_private.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "AprilTag_PickandPlace".
 *
 * Model version              : 1.28
 * Simulink Coder version : 9.8 (R2022b) 13-May-2022
 * C source code generated on : Fri Dec  8 12:00:54 2023
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_AprilTag_PickandPlace_private_h_
#define RTW_HEADER_AprilTag_PickandPlace_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"
#include "AprilTag_PickandPlace.h"
#include "AprilTag_PickandPlace_types.h"
#ifndef HALF_PI
#define HALF_PI                        1.5707963267948966192313216916398
#endif

#ifndef ONE_PI
#define ONE_PI                         3.1415926535897932384626433832795
#endif

#ifndef TWO_PI
#define TWO_PI                         6.2831853071795864769252867665590
#endif

/* A global buffer for storing error messages (defined in quanser_common library) */
EXTERN char _rt_error_message[512];
extern real_T rt_atan2d_snf(real_T u0, real_T u1);
extern uint32_T MWDSP_EPH_R_B(boolean_T evt, uint32_T *sta);
extern uint32_T MWDSP_EPH_R_D(real_T evt, uint32_T *sta);
extern void AprilTag_Pi_MATLABFunction2(const real_T rtu_p[3], const real_T
  rtu_angles[4], B_MATLABFunction2_AprilTag_Pi_T *localB);

/* private model entry point functions */
extern void AprilTag_PickandPlace_derivatives(void);

#endif                         /* RTW_HEADER_AprilTag_PickandPlace_private_h_ */