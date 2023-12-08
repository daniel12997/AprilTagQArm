/*
 * AprilTag_PickandPlace.c
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

#include "AprilTag_PickandPlace.h"
#include "rtwtypes.h"
#include "AprilTag_PickandPlace_private.h"
#include <string.h>
#include <math.h>
#include <emmintrin.h>
#include "quanser_video3d.h"
#include "rt_nonfinite.h"
#include "rt_defines.h"
#include "zero_crossing_types.h"
#include "AprilTag_PickandPlace_dt.h"
#define AprilTag_PickandPlace_period   (2.5)

/* Block signals (default storage) */
B_AprilTag_PickandPlace_T AprilTag_PickandPlace_B;

/* Continuous states */
X_AprilTag_PickandPlace_T AprilTag_PickandPlace_X;

/* Block states (default storage) */
DW_AprilTag_PickandPlace_T AprilTag_PickandPlace_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_AprilTag_PickandPlace_T AprilTag_PickandPlace_PrevZCX;

/* Real-time model */
static RT_MODEL_AprilTag_PickandPlac_T AprilTag_PickandPlace_M_;
RT_MODEL_AprilTag_PickandPlac_T *const AprilTag_PickandPlace_M =
  &AprilTag_PickandPlace_M_;
static void rate_monotonic_scheduler(void);
time_T rt_SimUpdateDiscreteEvents(
  int_T rtmNumSampTimes, void *rtmTimingData, int_T *rtmSampleHitPtr, int_T
  *rtmPerTaskSampleHits )
{
  rtmSampleHitPtr[1] = rtmStepTask(AprilTag_PickandPlace_M, 1);
  rtmSampleHitPtr[2] = rtmStepTask(AprilTag_PickandPlace_M, 2);
  rtmSampleHitPtr[3] = rtmStepTask(AprilTag_PickandPlace_M, 3);
  UNUSED_PARAMETER(rtmNumSampTimes);
  UNUSED_PARAMETER(rtmTimingData);
  UNUSED_PARAMETER(rtmPerTaskSampleHits);
  return(-1);
}

/*
 *         This function updates active task flag for each subrate
 *         and rate transition flags for tasks that exchange data.
 *         The function assumes rate-monotonic multitasking scheduler.
 *         The function must be called at model base rate so that
 *         the generated code self-manages all its subrates and rate
 *         transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* To ensure a deterministic data transfer between two rates,
   * data is transferred at the priority of a fast task and the frequency
   * of the slow task.  The following flags indicate when the data transfer
   * happens.  That is, a rate interaction flag is set true when both rates
   * will run, and false otherwise.
   */

  /* tid 1 shares data with slower tid rate: 3 */
  if (AprilTag_PickandPlace_M->Timing.TaskCounters.TID[1] == 0) {
    AprilTag_PickandPlace_M->Timing.RateInteraction.TID1_3 =
      (AprilTag_PickandPlace_M->Timing.TaskCounters.TID[3] == 0);

    /* update PerTaskSampleHits matrix for non-inline sfcn */
    AprilTag_PickandPlace_M->Timing.perTaskSampleHits[7] =
      AprilTag_PickandPlace_M->Timing.RateInteraction.TID1_3;
  }

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (AprilTag_PickandPlace_M->Timing.TaskCounters.TID[2])++;
  if ((AprilTag_PickandPlace_M->Timing.TaskCounters.TID[2]) > 16) {/* Sample time: [0.034s, 0.0s] */
    AprilTag_PickandPlace_M->Timing.TaskCounters.TID[2] = 0;
  }

  (AprilTag_PickandPlace_M->Timing.TaskCounters.TID[3])++;
  if ((AprilTag_PickandPlace_M->Timing.TaskCounters.TID[3]) > 1249) {/* Sample time: [2.5s, 0.0s] */
    AprilTag_PickandPlace_M->Timing.TaskCounters.TID[3] = 0;
  }
}

/*
 * This function updates continuous states using the ODE4 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE4_IntgData *id = (ODE4_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T *f3 = id->f[3];
  real_T temp;
  int_T i;
  int_T nXc = 3;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  AprilTag_PickandPlace_derivatives();

  /* f1 = f(t + (h/2), y + (h/2)*f0) */
  temp = 0.5 * h;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f0[i]);
  }

  rtsiSetT(si, t + temp);
  rtsiSetdX(si, f1);
  AprilTag_PickandPlace_output0();
  AprilTag_PickandPlace_derivatives();

  /* f2 = f(t + (h/2), y + (h/2)*f1) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f1[i]);
  }

  rtsiSetdX(si, f2);
  AprilTag_PickandPlace_output0();
  AprilTag_PickandPlace_derivatives();

  /* f3 = f(t + h, y + h*f2) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (h*f2[i]);
  }

  rtsiSetT(si, tnew);
  rtsiSetdX(si, f3);
  AprilTag_PickandPlace_output0();
  AprilTag_PickandPlace_derivatives();

  /* tnew = t + h
     ynew = y + (h/6)*(f0 + 2*f1 + 2*f2 + 2*f3) */
  temp = h / 6.0;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + temp*(f0[i] + 2.0*f1[i] + 2.0*f2[i] + f3[i]);
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/*
 * Output and update for atomic system:
 *    '<Root>/MATLAB Function2'
 *    '<Root>/MATLAB Function3'
 */
void AprilTag_Pi_MATLABFunction2(const real_T rtu_p[3], const real_T rtu_angles
  [4], B_MATLABFunction2_AprilTag_Pi_T *localB)
{
  __m128d tmp;
  __m128d tmp_0;
  real_T DH[20];
  real_T T_0w[16];
  real_T T_0w_0[16];
  real_T T_0w_tmp_3[16];
  int32_T T_0w_tmp_tmp_0;
  int32_T i;
  int32_T i_0;
  int32_T k;
  static const int8_T c[4] = { 0, 0, 0, 1 };

  static const real_T b_b[16] = { 0.0, -1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 1.0, 0.0, 0.05, -0.05, -0.03, 1.0 };

  DH[0] = 0.0;
  DH[5] = 0.0;
  DH[10] = 0.14;
  DH[15] = rtu_angles[0];
  DH[1] = -1.5707963267948966;
  DH[6] = 0.0;
  DH[11] = 0.0;
  DH[16] = (rtu_angles[1] - 1.5707963267948966) + 0.14189705460416394;
  DH[2] = 0.0;
  DH[7] = 0.35355339059327373;
  DH[12] = 0.0;
  DH[17] = rtu_angles[2] - 0.14189705460416394;
  DH[3] = -1.5707963267948966;
  DH[8] = 0.0;
  DH[13] = 0.25;
  DH[18] = rtu_angles[3];
  DH[4] = 0.0;
  DH[9] = 0.0;
  DH[14] = 0.15;
  DH[19] = 0.0;
  memset(&T_0w[0], 0, sizeof(real_T) << 4U);
  T_0w[0] = 1.0;
  T_0w[5] = 1.0;
  T_0w[10] = 1.0;
  T_0w[15] = 1.0;
  T_0w_tmp_3[8] = 0.0;
  T_0w_tmp_3[3] = 0.0;
  T_0w_tmp_3[7] = 0.0;
  T_0w_tmp_3[11] = 0.0;
  T_0w_tmp_3[15] = 1.0;
  for (k = 0; k < 4; k++) {
    real_T T_0w_tmp;
    real_T T_0w_tmp_0;
    real_T T_0w_tmp_1;
    real_T T_0w_tmp_2;
    real_T T_0w_tmp_tmp;
    T_0w_tmp_tmp = DH[k + 15];
    T_0w_tmp = sin(T_0w_tmp_tmp);
    T_0w_tmp_0 = cos(T_0w_tmp_tmp);
    T_0w_tmp_1 = cos(DH[k]);
    T_0w_tmp_2 = sin(DH[k]);
    T_0w_tmp_3[0] = T_0w_tmp_0;
    T_0w_tmp_3[4] = -T_0w_tmp;
    T_0w_tmp_3[12] = DH[k + 5];
    T_0w_tmp_3[1] = T_0w_tmp * T_0w_tmp_1;
    T_0w_tmp_3[5] = T_0w_tmp_0 * T_0w_tmp_1;
    T_0w_tmp_3[9] = -T_0w_tmp_2;
    T_0w_tmp_tmp = DH[k + 10];
    T_0w_tmp_3[13] = T_0w_tmp_tmp * -T_0w_tmp_2;
    T_0w_tmp_3[2] = T_0w_tmp * T_0w_tmp_2;
    T_0w_tmp_3[6] = T_0w_tmp_0 * T_0w_tmp_2;
    T_0w_tmp_3[10] = T_0w_tmp_1;
    T_0w_tmp_3[14] = T_0w_tmp_tmp * T_0w_tmp_1;
    for (i = 0; i < 4; i++) {
      for (i_0 = 0; i_0 < 4; i_0++) {
        int32_T T_0w_tmp_4;
        T_0w_tmp_tmp_0 = i_0 << 2;
        T_0w_tmp_4 = i + T_0w_tmp_tmp_0;
        T_0w_0[T_0w_tmp_4] = 0.0;
        T_0w_0[T_0w_tmp_4] += T_0w_tmp_3[T_0w_tmp_tmp_0] * T_0w[i];
        T_0w_0[T_0w_tmp_4] += T_0w_tmp_3[T_0w_tmp_tmp_0 + 1] * T_0w[i + 4];
        T_0w_0[T_0w_tmp_4] += T_0w_tmp_3[T_0w_tmp_tmp_0 + 2] * T_0w[i + 8];
        T_0w_0[T_0w_tmp_4] += T_0w_tmp_3[T_0w_tmp_tmp_0 + 3] * T_0w[i + 12];
      }
    }

    memcpy(&T_0w[0], &T_0w_0[0], sizeof(real_T) << 4U);
  }

  T_0w_tmp_3[0] = 1.0;
  T_0w_tmp_3[4] = 0.0;
  T_0w_tmp_3[8] = 0.0;
  T_0w_tmp_3[12] = rtu_p[0];
  T_0w_tmp_3[1] = 0.0;
  T_0w_tmp_3[5] = 1.0;
  T_0w_tmp_3[9] = 0.0;
  T_0w_tmp_3[13] = rtu_p[1];
  T_0w_tmp_3[2] = 0.0;
  T_0w_tmp_3[6] = 0.0;
  T_0w_tmp_3[10] = 1.0;
  T_0w_tmp_3[14] = rtu_p[2];
  for (i = 0; i < 4; i++) {
    for (i_0 = 0; i_0 <= 2; i_0 += 2) {
      k = i << 2;
      T_0w_tmp_tmp_0 = i_0 + k;
      _mm_storeu_pd(&T_0w_0[T_0w_tmp_tmp_0], _mm_set1_pd(0.0));
      tmp = _mm_loadu_pd(&T_0w[i_0]);
      tmp_0 = _mm_loadu_pd(&T_0w_0[T_0w_tmp_tmp_0]);
      _mm_storeu_pd(&T_0w_0[T_0w_tmp_tmp_0], _mm_add_pd(tmp_0, _mm_mul_pd
        (_mm_set1_pd(b_b[k]), tmp)));
      tmp = _mm_loadu_pd(&T_0w[i_0 + 4]);
      tmp_0 = _mm_loadu_pd(&T_0w_0[T_0w_tmp_tmp_0]);
      _mm_storeu_pd(&T_0w_0[T_0w_tmp_tmp_0], _mm_add_pd(_mm_mul_pd(_mm_set1_pd
        (b_b[k + 1]), tmp), tmp_0));
      tmp = _mm_loadu_pd(&T_0w[i_0 + 8]);
      tmp_0 = _mm_loadu_pd(&T_0w_0[T_0w_tmp_tmp_0]);
      _mm_storeu_pd(&T_0w_0[T_0w_tmp_tmp_0], _mm_add_pd(_mm_mul_pd(_mm_set1_pd
        (b_b[k + 2]), tmp), tmp_0));
      tmp = _mm_loadu_pd(&T_0w[i_0 + 12]);
      tmp_0 = _mm_loadu_pd(&T_0w_0[T_0w_tmp_tmp_0]);
      _mm_storeu_pd(&T_0w_0[T_0w_tmp_tmp_0], _mm_add_pd(_mm_mul_pd(_mm_set1_pd
        (b_b[k + 3]), tmp), tmp_0));
    }

    T_0w_tmp_3[(i << 2) + 3] = c[i];
  }

  for (i = 0; i < 4; i++) {
    for (i_0 = 0; i_0 <= 2; i_0 += 2) {
      k = i << 2;
      T_0w_tmp_tmp_0 = i_0 + k;
      _mm_storeu_pd(&T_0w[T_0w_tmp_tmp_0], _mm_set1_pd(0.0));
      tmp = _mm_loadu_pd(&T_0w_0[i_0]);
      tmp_0 = _mm_loadu_pd(&T_0w[T_0w_tmp_tmp_0]);
      _mm_storeu_pd(&T_0w[T_0w_tmp_tmp_0], _mm_add_pd(tmp_0, _mm_mul_pd
        (_mm_set1_pd(T_0w_tmp_3[k]), tmp)));
      tmp = _mm_loadu_pd(&T_0w_0[i_0 + 4]);
      tmp_0 = _mm_loadu_pd(&T_0w[T_0w_tmp_tmp_0]);
      _mm_storeu_pd(&T_0w[T_0w_tmp_tmp_0], _mm_add_pd(_mm_mul_pd(_mm_set1_pd
        (T_0w_tmp_3[k + 1]), tmp), tmp_0));
      tmp = _mm_loadu_pd(&T_0w_0[i_0 + 8]);
      tmp_0 = _mm_loadu_pd(&T_0w[T_0w_tmp_tmp_0]);
      _mm_storeu_pd(&T_0w[T_0w_tmp_tmp_0], _mm_add_pd(_mm_mul_pd(_mm_set1_pd
        (T_0w_tmp_3[k + 2]), tmp), tmp_0));
      tmp = _mm_loadu_pd(&T_0w_0[i_0 + 12]);
      tmp_0 = _mm_loadu_pd(&T_0w[T_0w_tmp_tmp_0]);
      _mm_storeu_pd(&T_0w[T_0w_tmp_tmp_0], _mm_add_pd(_mm_mul_pd(_mm_set1_pd
        (T_0w_tmp_3[k + 3]), tmp), tmp_0));
    }
  }

  localB->position[0] = T_0w[12];
  localB->position[1] = T_0w[13];
  localB->position[2] = T_0w[14];
}

real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    int32_T tmp;
    int32_T tmp_0;
    if (u0 > 0.0) {
      tmp = 1;
    } else {
      tmp = -1;
    }

    if (u1 > 0.0) {
      tmp_0 = 1;
    } else {
      tmp_0 = -1;
    }

    y = atan2(tmp, tmp_0);
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

uint32_T MWDSP_EPH_R_B(boolean_T evt, uint32_T *sta)
{
  int32_T curState;
  int32_T lastzcevent;
  int32_T newState;
  int32_T newStateR;
  uint32_T previousState;
  uint32_T retVal;

  /* S-Function (sdspcount2): '<Root>/Counter' */
  /* Detect rising edge events */
  previousState = *sta;
  retVal = 0U;
  lastzcevent = 0;
  newState = 5;
  newStateR = 5;
  if (evt) {
    curState = 2;
  } else {
    curState = 1;
  }

  if (*sta == 5U) {
    newStateR = curState;
  } else if ((uint32_T)curState != *sta) {
    if (*sta == 3U) {
      if ((uint32_T)curState == 1U) {
        newStateR = 1;
      } else {
        lastzcevent = 2;
        previousState = 1U;
      }
    }

    if (previousState == 4U) {
      if ((uint32_T)curState == 1U) {
        newStateR = 1;
      } else {
        lastzcevent = 3;
        previousState = 1U;
      }
    }

    if ((previousState == 1U) && ((uint32_T)curState == 2U)) {
      retVal = 2U;
    }

    if (previousState == 0U) {
      retVal = 2U;
    }

    if (retVal == (uint32_T)lastzcevent) {
      retVal = 0U;
    }

    if (((uint32_T)curState == 1U) && (retVal == 2U)) {
      newState = 3;
    } else {
      newState = curState;
    }
  }

  if ((uint32_T)newStateR != 5U) {
    *sta = (uint32_T)newStateR;
    retVal = 0U;
  }

  if ((uint32_T)newState != 5U) {
    *sta = (uint32_T)newState;
  }

  /* End of S-Function (sdspcount2): '<Root>/Counter' */
  return retVal;
}

uint32_T MWDSP_EPH_R_D(real_T evt, uint32_T *sta)
{
  int32_T curState;
  int32_T lastzcevent;
  int32_T newState;
  int32_T newStateR;
  uint32_T previousState;
  uint32_T retVal;

  /* S-Function (sdspcount2): '<Root>/Counter' */
  /* Detect rising edge events */
  previousState = *sta;
  retVal = 0U;
  lastzcevent = 0;
  newState = 5;
  newStateR = 5;
  if (evt > 0.0) {
    curState = 2;
  } else {
    curState = !(evt < 0.0);
  }

  if (*sta == 5U) {
    newStateR = curState;
  } else if ((uint32_T)curState != *sta) {
    if (*sta == 3U) {
      if ((uint32_T)curState == 1U) {
        newStateR = 1;
      } else {
        lastzcevent = 2;
        previousState = 1U;
      }
    }

    if (previousState == 4U) {
      if ((uint32_T)curState == 1U) {
        newStateR = 1;
      } else {
        lastzcevent = 3;
        previousState = 1U;
      }
    }

    if ((previousState == 1U) && ((uint32_T)curState == 2U)) {
      retVal = 2U;
    }

    if (previousState == 0U) {
      retVal = 2U;
    }

    if (retVal == (uint32_T)lastzcevent) {
      retVal = 0U;
    }

    if (((uint32_T)curState == 1U) && (retVal == 2U)) {
      newState = 3;
    } else {
      newState = curState;
    }
  }

  if ((uint32_T)newStateR != 5U) {
    *sta = (uint32_T)newStateR;
    retVal = 0U;
  }

  if ((uint32_T)newState != 5U) {
    *sta = (uint32_T)newState;
  }

  /* End of S-Function (sdspcount2): '<Root>/Counter' */
  return retVal;
}

/* Model output function for TID0 */
void AprilTag_PickandPlace_output0(void) /* Sample time: [0.0s, 0.0s] */
{
  /* local block i/o variables */
  real_T rtb_HILReadTimebase1_o1;
  real_T rtb_HILReadTimebase1_o2;
  real_T rtb_HILReadTimebase1_o3;
  real_T rtb_HILReadTimebase1_o4;
  real_T rtb_HILReadTimebase1_o10;
  real_T rtb_HILReadTimebase1_o11;
  real_T rtb_HILReadTimebase1_o12;
  real_T rtb_HILReadTimebase1_o13;
  real_T rtb_HILReadTimebase1_o14;
  real_T rtb_gripperspeed;
  real_T rtb_HILReadTimebase1_o16;
  real_T rtb_HILReadTimebase1_o17;
  real_T rtb_HILReadTimebase1_o18;
  real_T rtb_HILReadTimebase1_o19;
  real_T rtb_HILReadTimebase1_o20;
  real_T rtb_HILReadTimebase1_o21;
  real_T rtb_HILReadTimebase1_o22;
  real_T rtb_HILReadTimebase1_o23;
  real_T rtb_HILReadTimebase1_o24;
  real_T rtb_gripperpwm;
  real_T dh[20];
  real_T theta1_2_0[16];
  real_T transform[16];
  real_T transform_0[16];
  real_T R_inv[9];
  real_T R_inv_0[9];
  real_T T1Px_1[4];
  real_T T1Px_2[4];
  real_T rtb_Bias;
  int32_T R_inv_tmp;
  int32_T i;
  int32_T i_0;
  if (rtmIsMajorTimeStep(AprilTag_PickandPlace_M)) {
    /* set solver stop time */
    if (!(AprilTag_PickandPlace_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&AprilTag_PickandPlace_M->solverInfo,
                            ((AprilTag_PickandPlace_M->Timing.clockTickH0 + 1) *
        AprilTag_PickandPlace_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&AprilTag_PickandPlace_M->solverInfo,
                            ((AprilTag_PickandPlace_M->Timing.clockTick0 + 1) *
        AprilTag_PickandPlace_M->Timing.stepSize0 +
        AprilTag_PickandPlace_M->Timing.clockTickH0 *
        AprilTag_PickandPlace_M->Timing.stepSize0 * 4294967296.0));
    }

    {                                  /* Sample time: [0.0s, 0.0s] */
      rate_monotonic_scheduler();
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(AprilTag_PickandPlace_M)) {
    AprilTag_PickandPlace_M->Timing.t[0] = rtsiGetT
      (&AprilTag_PickandPlace_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(AprilTag_PickandPlace_M)) {
    __m128d tmp;
    __m128d tmp_0;
    __m128d tmp_1;
    __m128d tmp_2;
    real_T T_tmp;
    real_T c;
    real_T rtb_TmpSignalConversionAtSFun_0;
    real_T rtb_TmpSignalConversionAtSFun_1;
    real_T rtb_TmpSignalConversionAtSFun_2;
    real_T theta1_1;
    real_T theta1_2;

    /* S-Function (hil_read_timebase_block): '<S3>/HIL Read Timebase1' */

    /* S-Function Block: AprilTag_PickandPlace/Hardware Plant P(s)/HIL Read Timebase1 (hil_read_timebase_block) */
    {
      t_error result;
      result = hil_task_read(AprilTag_PickandPlace_DW.HILReadTimebase1_Task, 1,
        &AprilTag_PickandPlace_DW.HILReadTimebase1_AnalogBuffer[0],
        NULL,
        NULL,
        &AprilTag_PickandPlace_DW.HILReadTimebase1_OtherBuffer[0]
        );
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(AprilTag_PickandPlace_M, _rt_error_message);
      } else {
        rtb_HILReadTimebase1_o1 =
          AprilTag_PickandPlace_DW.HILReadTimebase1_AnalogBuffer[0];
        rtb_HILReadTimebase1_o2 =
          AprilTag_PickandPlace_DW.HILReadTimebase1_AnalogBuffer[1];
        rtb_HILReadTimebase1_o3 =
          AprilTag_PickandPlace_DW.HILReadTimebase1_AnalogBuffer[2];
        rtb_HILReadTimebase1_o4 =
          AprilTag_PickandPlace_DW.HILReadTimebase1_AnalogBuffer[3];
        AprilTag_PickandPlace_B.grippercurrent =
          AprilTag_PickandPlace_DW.HILReadTimebase1_AnalogBuffer[4];
        AprilTag_PickandPlace_B.HILReadTimebase1_o6 =
          AprilTag_PickandPlace_DW.HILReadTimebase1_OtherBuffer[0];
        AprilTag_PickandPlace_B.HILReadTimebase1_o7 =
          AprilTag_PickandPlace_DW.HILReadTimebase1_OtherBuffer[1];
        AprilTag_PickandPlace_B.HILReadTimebase1_o8 =
          AprilTag_PickandPlace_DW.HILReadTimebase1_OtherBuffer[2];
        AprilTag_PickandPlace_B.HILReadTimebase1_o9 =
          AprilTag_PickandPlace_DW.HILReadTimebase1_OtherBuffer[3];
        rtb_HILReadTimebase1_o10 =
          AprilTag_PickandPlace_DW.HILReadTimebase1_OtherBuffer[4];
        rtb_HILReadTimebase1_o11 =
          AprilTag_PickandPlace_DW.HILReadTimebase1_OtherBuffer[5];
        rtb_HILReadTimebase1_o12 =
          AprilTag_PickandPlace_DW.HILReadTimebase1_OtherBuffer[6];
        rtb_HILReadTimebase1_o13 =
          AprilTag_PickandPlace_DW.HILReadTimebase1_OtherBuffer[7];
        rtb_HILReadTimebase1_o14 =
          AprilTag_PickandPlace_DW.HILReadTimebase1_OtherBuffer[8];
        rtb_gripperspeed =
          AprilTag_PickandPlace_DW.HILReadTimebase1_OtherBuffer[9];
        rtb_HILReadTimebase1_o16 =
          AprilTag_PickandPlace_DW.HILReadTimebase1_OtherBuffer[10];
        rtb_HILReadTimebase1_o17 =
          AprilTag_PickandPlace_DW.HILReadTimebase1_OtherBuffer[11];
        rtb_HILReadTimebase1_o18 =
          AprilTag_PickandPlace_DW.HILReadTimebase1_OtherBuffer[12];
        rtb_HILReadTimebase1_o19 =
          AprilTag_PickandPlace_DW.HILReadTimebase1_OtherBuffer[13];
        rtb_HILReadTimebase1_o20 =
          AprilTag_PickandPlace_DW.HILReadTimebase1_OtherBuffer[14];
        rtb_HILReadTimebase1_o21 =
          AprilTag_PickandPlace_DW.HILReadTimebase1_OtherBuffer[15];
        rtb_HILReadTimebase1_o22 =
          AprilTag_PickandPlace_DW.HILReadTimebase1_OtherBuffer[16];
        rtb_HILReadTimebase1_o23 =
          AprilTag_PickandPlace_DW.HILReadTimebase1_OtherBuffer[17];
        rtb_HILReadTimebase1_o24 =
          AprilTag_PickandPlace_DW.HILReadTimebase1_OtherBuffer[18];
        rtb_gripperpwm = AprilTag_PickandPlace_DW.HILReadTimebase1_OtherBuffer
          [19];
      }
    }

    /* RateTransition generated from: '<Root>/Multiport Switch1' */
    if (AprilTag_PickandPlace_M->Timing.RateInteraction.TID1_3) {
      /* RateTransition generated from: '<Root>/Multiport Switch1' */
      AprilTag_PickandPlace_B.TmpRTBAtMultiportSwitch1Inport1 =
        AprilTag_PickandPlace_DW.TmpRTBAtMultiportSwitch1Inport1;
    }

    /* End of RateTransition generated from: '<Root>/Multiport Switch1' */

    /* MATLAB Function: '<Root>/MATLAB Function2' incorporates:
     *  Constant: '<Root>/Joint Anle for Camera Position'
     *  Constant: '<Root>/Object Position'
     */
    AprilTag_Pi_MATLABFunction2(AprilTag_PickandPlace_P.ObjectPosition_Value,
      AprilTag_PickandPlace_P.JointAnleforCameraPosition_Valu,
      &AprilTag_PickandPlace_B.sf_MATLABFunction2);

    /* MATLAB Function: '<Root>/MATLAB Function3' incorporates:
     *  Constant: '<Root>/Goal Position'
     *  Constant: '<Root>/Joint Anle for Camera Position'
     */
    AprilTag_Pi_MATLABFunction2(AprilTag_PickandPlace_P.GoalPosition_Value,
      AprilTag_PickandPlace_P.JointAnleforCameraPosition_Valu,
      &AprilTag_PickandPlace_B.sf_MATLABFunction3);

    /* MultiPortSwitch: '<Root>/Multiport Switch1' */
    switch ((int32_T)AprilTag_PickandPlace_B.TmpRTBAtMultiportSwitch1Inport1) {
     case 1:
      /* MultiPortSwitch: '<Root>/Multiport Switch1' incorporates:
       *  Constant: '<Root>/Object Offset'
       *  Constant: '<Root>/Vertical Offset'
       *  Sum: '<Root>/Add'
       *  Sum: '<Root>/Plus'
       */
      AprilTag_PickandPlace_B.MultiportSwitch1[0] =
        (AprilTag_PickandPlace_B.sf_MATLABFunction2.position[0] +
         AprilTag_PickandPlace_P.ObjectOffset_Value[0]) +
        AprilTag_PickandPlace_P.VerticalOffset_Value[0];
      AprilTag_PickandPlace_B.MultiportSwitch1[1] =
        (AprilTag_PickandPlace_B.sf_MATLABFunction2.position[1] +
         AprilTag_PickandPlace_P.ObjectOffset_Value[1]) +
        AprilTag_PickandPlace_P.VerticalOffset_Value[1];
      AprilTag_PickandPlace_B.MultiportSwitch1[2] =
        (AprilTag_PickandPlace_B.sf_MATLABFunction2.position[2] +
         AprilTag_PickandPlace_P.ObjectOffset_Value[2]) +
        AprilTag_PickandPlace_P.VerticalOffset_Value[2];
      break;

     case 2:
      /* MultiPortSwitch: '<Root>/Multiport Switch1' incorporates:
       *  Constant: '<Root>/Object Offset'
       *  Sum: '<Root>/Add'
       */
      AprilTag_PickandPlace_B.MultiportSwitch1[0] =
        AprilTag_PickandPlace_B.sf_MATLABFunction2.position[0] +
        AprilTag_PickandPlace_P.ObjectOffset_Value[0];
      AprilTag_PickandPlace_B.MultiportSwitch1[1] =
        AprilTag_PickandPlace_B.sf_MATLABFunction2.position[1] +
        AprilTag_PickandPlace_P.ObjectOffset_Value[1];
      AprilTag_PickandPlace_B.MultiportSwitch1[2] =
        AprilTag_PickandPlace_B.sf_MATLABFunction2.position[2] +
        AprilTag_PickandPlace_P.ObjectOffset_Value[2];
      break;

     case 3:
      /* MultiPortSwitch: '<Root>/Multiport Switch1' incorporates:
       *  Constant: '<Root>/Object Offset'
       *  Constant: '<Root>/Vertical Offset'
       *  Sum: '<Root>/Add'
       *  Sum: '<Root>/Plus'
       */
      AprilTag_PickandPlace_B.MultiportSwitch1[0] =
        (AprilTag_PickandPlace_B.sf_MATLABFunction2.position[0] +
         AprilTag_PickandPlace_P.ObjectOffset_Value[0]) +
        AprilTag_PickandPlace_P.VerticalOffset_Value[0];
      AprilTag_PickandPlace_B.MultiportSwitch1[1] =
        (AprilTag_PickandPlace_B.sf_MATLABFunction2.position[1] +
         AprilTag_PickandPlace_P.ObjectOffset_Value[1]) +
        AprilTag_PickandPlace_P.VerticalOffset_Value[1];
      AprilTag_PickandPlace_B.MultiportSwitch1[2] =
        (AprilTag_PickandPlace_B.sf_MATLABFunction2.position[2] +
         AprilTag_PickandPlace_P.ObjectOffset_Value[2]) +
        AprilTag_PickandPlace_P.VerticalOffset_Value[2];
      break;

     case 4:
      /* MultiPortSwitch: '<Root>/Multiport Switch1' incorporates:
       *  Constant: '<Root>/Placement Offset'
       *  Constant: '<Root>/Vertical Offset'
       *  Sum: '<Root>/Add1'
       *  Sum: '<Root>/Plus1'
       */
      AprilTag_PickandPlace_B.MultiportSwitch1[0] =
        (AprilTag_PickandPlace_B.sf_MATLABFunction3.position[0] +
         AprilTag_PickandPlace_P.PlacementOffset_Value[0]) +
        AprilTag_PickandPlace_P.VerticalOffset_Value[0];
      AprilTag_PickandPlace_B.MultiportSwitch1[1] =
        (AprilTag_PickandPlace_B.sf_MATLABFunction3.position[1] +
         AprilTag_PickandPlace_P.PlacementOffset_Value[1]) +
        AprilTag_PickandPlace_P.VerticalOffset_Value[1];
      AprilTag_PickandPlace_B.MultiportSwitch1[2] =
        (AprilTag_PickandPlace_B.sf_MATLABFunction3.position[2] +
         AprilTag_PickandPlace_P.PlacementOffset_Value[2]) +
        AprilTag_PickandPlace_P.VerticalOffset_Value[2];
      break;

     case 5:
      /* MultiPortSwitch: '<Root>/Multiport Switch1' incorporates:
       *  Constant: '<Root>/Placement Offset'
       *  Sum: '<Root>/Add1'
       */
      AprilTag_PickandPlace_B.MultiportSwitch1[0] =
        AprilTag_PickandPlace_B.sf_MATLABFunction3.position[0] +
        AprilTag_PickandPlace_P.PlacementOffset_Value[0];
      AprilTag_PickandPlace_B.MultiportSwitch1[1] =
        AprilTag_PickandPlace_B.sf_MATLABFunction3.position[1] +
        AprilTag_PickandPlace_P.PlacementOffset_Value[1];
      AprilTag_PickandPlace_B.MultiportSwitch1[2] =
        AprilTag_PickandPlace_B.sf_MATLABFunction3.position[2] +
        AprilTag_PickandPlace_P.PlacementOffset_Value[2];
      break;

     default:
      /* MultiPortSwitch: '<Root>/Multiport Switch1' incorporates:
       *  Constant: '<Root>/Placement Offset'
       *  Constant: '<Root>/Vertical Offset'
       *  Sum: '<Root>/Add1'
       *  Sum: '<Root>/Plus1'
       */
      AprilTag_PickandPlace_B.MultiportSwitch1[0] =
        (AprilTag_PickandPlace_B.sf_MATLABFunction3.position[0] +
         AprilTag_PickandPlace_P.PlacementOffset_Value[0]) +
        AprilTag_PickandPlace_P.VerticalOffset_Value[0];
      AprilTag_PickandPlace_B.MultiportSwitch1[1] =
        (AprilTag_PickandPlace_B.sf_MATLABFunction3.position[1] +
         AprilTag_PickandPlace_P.PlacementOffset_Value[1]) +
        AprilTag_PickandPlace_P.VerticalOffset_Value[1];
      AprilTag_PickandPlace_B.MultiportSwitch1[2] =
        (AprilTag_PickandPlace_B.sf_MATLABFunction3.position[2] +
         AprilTag_PickandPlace_P.PlacementOffset_Value[2]) +
        AprilTag_PickandPlace_P.VerticalOffset_Value[2];
      break;
    }

    /* End of MultiPortSwitch: '<Root>/Multiport Switch1' */

    /* MultiPortSwitch: '<Root>/Multiport Switch' incorporates:
     *  Constant: '<Root>/State Switch'
     */
    switch ((int32_T)AprilTag_PickandPlace_P.StateSwitch_Value) {
     case 1:
      /* MultiPortSwitch: '<Root>/Multiport Switch' incorporates:
       *  Constant: '<Root>/Home Position'
       */
      AprilTag_PickandPlace_B.MultiportSwitch[0] =
        AprilTag_PickandPlace_P.HomePosition_Value[0];
      AprilTag_PickandPlace_B.MultiportSwitch[1] =
        AprilTag_PickandPlace_P.HomePosition_Value[1];
      AprilTag_PickandPlace_B.MultiportSwitch[2] =
        AprilTag_PickandPlace_P.HomePosition_Value[2];
      break;

     case 2:
      /* MultiPortSwitch: '<Root>/Multiport Switch' incorporates:
       *  Constant: '<Root>/Picture Position '
       */
      AprilTag_PickandPlace_B.MultiportSwitch[0] =
        AprilTag_PickandPlace_P.PicturePosition_Value[0];
      AprilTag_PickandPlace_B.MultiportSwitch[1] =
        AprilTag_PickandPlace_P.PicturePosition_Value[1];
      AprilTag_PickandPlace_B.MultiportSwitch[2] =
        AprilTag_PickandPlace_P.PicturePosition_Value[2];
      break;

     default:
      /* MultiPortSwitch: '<Root>/Multiport Switch' incorporates:
       *  MultiPortSwitch: '<Root>/Multiport Switch1'
       */
      AprilTag_PickandPlace_B.MultiportSwitch[0] =
        AprilTag_PickandPlace_B.MultiportSwitch1[0];
      AprilTag_PickandPlace_B.MultiportSwitch[1] =
        AprilTag_PickandPlace_B.MultiportSwitch1[1];
      AprilTag_PickandPlace_B.MultiportSwitch[2] =
        AprilTag_PickandPlace_B.MultiportSwitch1[2];
      break;
    }

    /* End of MultiPortSwitch: '<Root>/Multiport Switch' */

    /* MATLAB Function: '<Root>/MATLAB Function' */
    theta1_1 = rt_atan2d_snf(AprilTag_PickandPlace_B.MultiportSwitch[1],
      AprilTag_PickandPlace_B.MultiportSwitch[0]);
    theta1_2 = rt_atan2d_snf(-AprilTag_PickandPlace_B.MultiportSwitch[1],
      -AprilTag_PickandPlace_B.MultiportSwitch[0]);
    rtb_TmpSignalConversionAtSFun_0 = AprilTag_PickandPlace_B.MultiportSwitch[0];
    rtb_TmpSignalConversionAtSFun_1 = AprilTag_PickandPlace_B.MultiportSwitch[1];
    rtb_TmpSignalConversionAtSFun_2 = AprilTag_PickandPlace_B.MultiportSwitch[2];
    c = sin(theta1_1);
    T_tmp = cos(theta1_1);
    transform[0] = T_tmp;
    transform[4] = -c;
    transform[8] = 0.0;
    transform[12] = 0.0;
    transform[1] = c;
    transform[5] = T_tmp;
    transform[9] = -0.0;
    transform[13] = -0.0;
    transform[2] = c * 0.0;
    transform[6] = T_tmp * 0.0;
    transform[10] = 1.0;
    transform[14] = 0.14;
    transform[3] = 0.0;
    transform[7] = 0.0;
    transform[11] = 0.0;
    transform[15] = 1.0;
    for (i = 0; i < 3; i++) {
      R_inv[3 * i] = transform[i];
      R_inv[3 * i + 1] = transform[i + 4];
      R_inv[3 * i + 2] = transform[i + 8];
    }

    for (i = 0; i <= 6; i += 2) {
      /* MATLAB Function: '<Root>/MATLAB Function' */
      tmp_2 = _mm_loadu_pd(&R_inv[i]);
      _mm_storeu_pd(&R_inv_0[i], _mm_mul_pd(tmp_2, _mm_set1_pd(-1.0)));
    }

    /* MATLAB Function: '<Root>/MATLAB Function' */
    for (i = 8; i < 9; i++) {
      R_inv_0[i] = -R_inv[i];
    }

    for (i = 0; i < 3; i++) {
      R_inv_tmp = i << 2;
      transform[R_inv_tmp] = R_inv[3 * i];
      transform[R_inv_tmp + 1] = R_inv[3 * i + 1];
      transform[R_inv_tmp + 2] = R_inv[3 * i + 2];
      transform[i + 12] = (R_inv_0[i + 3] * -0.0 + R_inv_0[i] * 0.0) + R_inv_0[i
        + 6] * 0.14;
    }

    transform[3] = 0.0;
    transform[7] = 0.0;
    transform[11] = 0.0;
    transform[15] = 1.0;
    for (i = 0; i <= 2; i += 2) {
      /* MATLAB Function: '<Root>/MATLAB Function' */
      tmp_2 = _mm_loadu_pd(&transform[i]);
      tmp = _mm_loadu_pd(&transform[i + 4]);
      tmp_0 = _mm_loadu_pd(&transform[i + 8]);
      tmp_1 = _mm_loadu_pd(&transform[i + 12]);
      _mm_storeu_pd(&T1Px_1[i], _mm_add_pd(tmp_1, _mm_add_pd(_mm_mul_pd(tmp_0,
        _mm_set1_pd(rtb_TmpSignalConversionAtSFun_2)), _mm_add_pd(_mm_mul_pd(tmp,
        _mm_set1_pd(rtb_TmpSignalConversionAtSFun_1)), _mm_add_pd(_mm_mul_pd
        (tmp_2, _mm_set1_pd(rtb_TmpSignalConversionAtSFun_0)), _mm_set1_pd(0.0))))));
    }

    /* MATLAB Function: '<Root>/MATLAB Function' */
    c = sin(theta1_2);
    T_tmp = cos(theta1_2);
    transform[0] = T_tmp;
    transform[4] = -c;
    transform[8] = 0.0;
    transform[12] = 0.0;
    transform[1] = c;
    transform[5] = T_tmp;
    transform[9] = -0.0;
    transform[13] = -0.0;
    transform[2] = c * 0.0;
    transform[6] = T_tmp * 0.0;
    transform[10] = 1.0;
    transform[14] = 0.14;
    transform[3] = 0.0;
    transform[7] = 0.0;
    transform[11] = 0.0;
    transform[15] = 1.0;
    for (i = 0; i < 3; i++) {
      R_inv[3 * i] = transform[i];
      R_inv[3 * i + 1] = transform[i + 4];
      R_inv[3 * i + 2] = transform[i + 8];
    }

    for (i = 0; i <= 6; i += 2) {
      /* MATLAB Function: '<Root>/MATLAB Function' */
      tmp_2 = _mm_loadu_pd(&R_inv[i]);
      _mm_storeu_pd(&R_inv_0[i], _mm_mul_pd(tmp_2, _mm_set1_pd(-1.0)));
    }

    /* MATLAB Function: '<Root>/MATLAB Function' */
    for (i = 8; i < 9; i++) {
      R_inv_0[i] = -R_inv[i];
    }

    for (i = 0; i < 3; i++) {
      R_inv_tmp = i << 2;
      transform[R_inv_tmp] = R_inv[3 * i];
      transform[R_inv_tmp + 1] = R_inv[3 * i + 1];
      transform[R_inv_tmp + 2] = R_inv[3 * i + 2];
      transform[i + 12] = (R_inv_0[i + 3] * -0.0 + R_inv_0[i] * 0.0) + R_inv_0[i
        + 6] * 0.14;
    }

    transform[3] = 0.0;
    transform[7] = 0.0;
    transform[11] = 0.0;
    transform[15] = 1.0;
    for (i = 0; i <= 2; i += 2) {
      /* MATLAB Function: '<Root>/MATLAB Function' */
      tmp_2 = _mm_loadu_pd(&transform[i]);
      tmp = _mm_loadu_pd(&transform[i + 4]);
      tmp_0 = _mm_loadu_pd(&transform[i + 8]);
      tmp_1 = _mm_loadu_pd(&transform[i + 12]);
      _mm_storeu_pd(&T1Px_2[i], _mm_add_pd(tmp_1, _mm_add_pd(_mm_mul_pd(tmp_0,
        _mm_set1_pd(rtb_TmpSignalConversionAtSFun_2)), _mm_add_pd(_mm_mul_pd(tmp,
        _mm_set1_pd(rtb_TmpSignalConversionAtSFun_1)), _mm_add_pd(_mm_mul_pd
        (tmp_2, _mm_set1_pd(rtb_TmpSignalConversionAtSFun_0)), _mm_set1_pd(0.0))))));
    }

    /* MATLAB Function: '<Root>/MATLAB Function' */
    if (T1Px_1[0] > T1Px_2[0]) {
      c = sqrt(T1Px_1[0] * T1Px_1[0] + T1Px_1[2] * T1Px_1[2]);
      AprilTag_PickandPlace_B.theta[0] = theta1_1;
      theta1_1 = c * c;
      AprilTag_PickandPlace_B.theta[1] = (rt_atan2d_snf(T1Px_1[0], T1Px_1[2]) -
        acos(((theta1_1 + 0.12499999999999997) - 0.16000000000000003) /
             (0.70710678118654746 * c))) - 0.14189705460416394;
      AprilTag_PickandPlace_B.theta[2] = (1.5707963267948966 - acos
        ((0.28500000000000003 - theta1_1) / 0.282842712474619)) +
        0.14189705460416394;
    } else {
      c = sqrt(T1Px_2[0] * T1Px_2[0] + T1Px_2[2] * T1Px_2[2]);
      AprilTag_PickandPlace_B.theta[0] = theta1_2;
      theta1_1 = c * c;
      AprilTag_PickandPlace_B.theta[1] = (rt_atan2d_snf(T1Px_2[0], T1Px_2[2]) -
        acos(((theta1_1 + 0.12499999999999997) - 0.16000000000000003) /
             (0.70710678118654746 * c))) - 0.14189705460416394;
      AprilTag_PickandPlace_B.theta[2] = (1.5707963267948966 - acos
        ((0.28500000000000003 - theta1_1) / 0.282842712474619)) +
        0.14189705460416394;
    }

    AprilTag_PickandPlace_B.theta[3] = 0.0;
    R_inv_tmp = 0;
    if ((AprilTag_PickandPlace_B.theta[0] > 2.9670597283903604) ||
        (AprilTag_PickandPlace_B.theta[0] < -2.9670597283903604) ||
        (AprilTag_PickandPlace_B.theta[1] > 1.5707963267948966) ||
        (AprilTag_PickandPlace_B.theta[1] < -1.5707963267948966) ||
        (AprilTag_PickandPlace_B.theta[2] > 1.3089969389957472) ||
        (AprilTag_PickandPlace_B.theta[2] < -1.6580627893946132) ||
        (AprilTag_PickandPlace_B.theta[3] > 2.7925268031909272) ||
        (AprilTag_PickandPlace_B.theta[3] < -2.7925268031909272)) {
      R_inv_tmp = 1;
    }

    if (R_inv_tmp != 0) {
      AprilTag_PickandPlace_B.theta[0] = 0.0;
      AprilTag_PickandPlace_B.theta[1] = 0.0;
      AprilTag_PickandPlace_B.theta[2] = 0.0;
      AprilTag_PickandPlace_B.theta[3] = 0.0;
    }

    /* RelationalOperator: '<Root>/Equal' incorporates:
     *  Constant: '<Root>/State 3 Constant'
     *  Constant: '<Root>/State Switch'
     */
    AprilTag_PickandPlace_B.Equal = (AprilTag_PickandPlace_P.StateSwitch_Value ==
      AprilTag_PickandPlace_P.State3Constant_Value);

    /* MATLAB Function: '<Root>/MATLAB Function1' incorporates:
     *  SignalConversion generated from: '<S5>/ SFunction '
     */
    dh[0] = AprilTag_PickandPlace_B.HILReadTimebase1_o6;
    dh[5] = 0.0;
    dh[10] = 0.0;
    dh[15] = 0.14;
    dh[1] = (AprilTag_PickandPlace_B.HILReadTimebase1_o7 - 1.5707963267948966) +
      0.14189705460416394;
    dh[6] = -1.5707963267948966;
    dh[11] = 0.0;
    dh[16] = 0.0;
    dh[2] = AprilTag_PickandPlace_B.HILReadTimebase1_o8 - 0.14189705460416394;
    dh[7] = 0.0;
    dh[12] = 0.35355339059327373;
    dh[17] = 0.0;
    dh[3] = AprilTag_PickandPlace_B.HILReadTimebase1_o9;
    dh[8] = -1.5707963267948966;
    dh[13] = 0.0;
    dh[18] = 0.25;
    dh[4] = 0.0;
    dh[9] = 0.0;
    dh[14] = 0.0;
    dh[19] = 0.15;
    memset(&transform[0], 0, sizeof(real_T) << 4U);
    transform[0] = 1.0;
    transform[5] = 1.0;
    transform[10] = 1.0;
    transform[15] = 1.0;
    theta1_2_0[8] = 0.0;
    theta1_2_0[3] = 0.0;
    theta1_2_0[7] = 0.0;
    theta1_2_0[11] = 0.0;
    theta1_2_0[15] = 1.0;
    for (R_inv_tmp = 0; R_inv_tmp < 5; R_inv_tmp++) {
      theta1_1 = sin(dh[R_inv_tmp]);
      theta1_2 = cos(dh[R_inv_tmp]);
      T_tmp = dh[R_inv_tmp + 5];
      c = cos(T_tmp);
      T_tmp = sin(T_tmp);
      theta1_2_0[0] = theta1_2;
      theta1_2_0[4] = -theta1_1;
      theta1_2_0[12] = dh[R_inv_tmp + 10];
      theta1_2_0[1] = theta1_1 * c;
      theta1_2_0[5] = theta1_2 * c;
      theta1_2_0[9] = -T_tmp;
      rtb_TmpSignalConversionAtSFun_0 = dh[R_inv_tmp + 15];
      theta1_2_0[13] = rtb_TmpSignalConversionAtSFun_0 * -T_tmp;
      theta1_2_0[2] = theta1_1 * T_tmp;
      theta1_2_0[6] = theta1_2 * T_tmp;
      theta1_2_0[10] = c;
      theta1_2_0[14] = rtb_TmpSignalConversionAtSFun_0 * c;
      for (i = 0; i < 4; i++) {
        for (i_0 = 0; i_0 < 4; i_0++) {
          int32_T transform_tmp;
          int32_T transform_tmp_tmp;
          transform_tmp_tmp = i_0 << 2;
          transform_tmp = i + transform_tmp_tmp;
          transform_0[transform_tmp] = 0.0;
          transform_0[transform_tmp] += theta1_2_0[transform_tmp_tmp] *
            transform[i];
          transform_0[transform_tmp] += theta1_2_0[transform_tmp_tmp + 1] *
            transform[i + 4];
          transform_0[transform_tmp] += theta1_2_0[transform_tmp_tmp + 2] *
            transform[i + 8];
          transform_0[transform_tmp] += theta1_2_0[transform_tmp_tmp + 3] *
            transform[i + 12];
        }
      }

      memcpy(&transform[0], &transform_0[0], sizeof(real_T) << 4U);
    }

    for (i = 0; i < 3; i++) {
      AprilTag_PickandPlace_B.trans[i] = transform[i + 12];
    }

    /* End of MATLAB Function: '<Root>/MATLAB Function1' */

    /* RateTransition generated from: '<Root>/Rate Limiter' */
    if (AprilTag_PickandPlace_M->Timing.RateInteraction.TID1_3) {
      /* RateTransition generated from: '<Root>/Rate Limiter' */
      AprilTag_PickandPlace_B.TmpRTBAtRateLimiterOutport1 =
        AprilTag_PickandPlace_DW.TmpRTBAtRateLimiterOutport1_Buf;
    }

    /* End of RateTransition generated from: '<Root>/Rate Limiter' */
  }

  /* Integrator: '<S8>/Integrator' */
  /* Limited  Integrator  */
  if (rtsiIsModeUpdateTimeStep(&AprilTag_PickandPlace_M->solverInfo)) {
    ZCEventType zcEvent;
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,
                       &AprilTag_PickandPlace_PrevZCX.Integrator_Reset_ZCE,
                       (AprilTag_PickandPlace_B.TmpRTBAtRateLimiterOutport1));

    /* evaluate zero-crossings */
    if (zcEvent != NO_ZCEVENT) {
      AprilTag_PickandPlace_X.Integrator_CSTATE =
        AprilTag_PickandPlace_P.Integrator_IC;
    }
  }

  if (AprilTag_PickandPlace_X.Integrator_CSTATE >=
      AprilTag_PickandPlace_P.Integrator_UpperSat) {
    AprilTag_PickandPlace_X.Integrator_CSTATE =
      AprilTag_PickandPlace_P.Integrator_UpperSat;
  } else if (AprilTag_PickandPlace_X.Integrator_CSTATE <=
             AprilTag_PickandPlace_P.Integrator_LowerSat) {
    AprilTag_PickandPlace_X.Integrator_CSTATE =
      AprilTag_PickandPlace_P.Integrator_LowerSat;
  }

  /* Switch: '<S8>/Switch' */
  if (AprilTag_PickandPlace_B.TmpRTBAtRateLimiterOutport1 >
      AprilTag_PickandPlace_P.Switch_Threshold) {
    /* Switch: '<S8>/Switch' incorporates:
     *  Integrator: '<S8>/Integrator'
     */
    AprilTag_PickandPlace_B.gripposition =
      AprilTag_PickandPlace_X.Integrator_CSTATE;
  } else {
    /* Switch: '<S8>/Switch' incorporates:
     *  Constant: '<S8>/open position'
     */
    AprilTag_PickandPlace_B.gripposition =
      AprilTag_PickandPlace_P.openposition_Value;
  }

  /* End of Switch: '<S8>/Switch' */
  if (rtmIsMajorTimeStep(AprilTag_PickandPlace_M)) {
    /* S-Function (smooth_signal_generator_block): '<S3>/Smooth Signal Generator' */
    /* S-Function Block: AprilTag_PickandPlace/Hardware Plant P(s)/Smooth Signal Generator (smooth_signal_generator_block) */
    {
      real_T w = TWO_PI *
        AprilTag_PickandPlace_P.SmoothSignalGenerator_Frequency;
      boolean_T params_changed =
        (AprilTag_PickandPlace_P.SmoothSignalGenerator_Amplitude !=
         AprilTag_PickandPlace_DW.SmoothSignalGenerator_RWORK.Amp || w !=
         AprilTag_PickandPlace_DW.SmoothSignalGenerator_RWORK.W);

      /*
         Discrete-time:

         y_sin = sin(w*(t + dt)) = sin(w*t)*cos(w*dt) + cos(w*t)*sin(w*dt)
         y_cos = cos(w*(t + dt)) = cos(w*t)*cos(w*dt) - sin(w*t)*sin(w*dt)

         Since dt is fixed and known (the sampling period), we can compute the
         output at the next time step, t + dt, from the previous time step, t,
         simply by applying the formulae above where sin(w*dt) and cos(w*dt) are constant.

         Now, suppose the amplitude or frequency is changed. Then when the current
         value of the output is less than the new amplitude, we need to solve the
         equation:
         1. A1 * y_sin = A2 * sin(x)
         whence:
         x  = asin(A1*y_sin/A2)
         We can then compute a new value of sin(x) and cos(x).
       */
      real_T y_sin =
        AprilTag_PickandPlace_DW.SmoothSignalGenerator_RWORK.Sin_w_t;
      real_T y_cos =
        AprilTag_PickandPlace_DW.SmoothSignalGenerator_RWORK.Cos_w_t;

      /* Produce the output(s) */
      rtb_Bias = AprilTag_PickandPlace_DW.SmoothSignalGenerator_RWORK.Amp *
        y_sin;

      /* Compute the new sin and cos values */
      AprilTag_PickandPlace_DW.SmoothSignalGenerator_RWORK.Sin_w_t = y_sin *
        AprilTag_PickandPlace_DW.SmoothSignalGenerator_RWORK.Cos_w_dt + y_cos *
        AprilTag_PickandPlace_DW.SmoothSignalGenerator_RWORK.Sin_w_dt;
      AprilTag_PickandPlace_DW.SmoothSignalGenerator_RWORK.Cos_w_t = y_cos *
        AprilTag_PickandPlace_DW.SmoothSignalGenerator_RWORK.Cos_w_dt - y_sin *
        AprilTag_PickandPlace_DW.SmoothSignalGenerator_RWORK.Sin_w_dt;

      /*
         If the amplitude or frequency parameter changes, then adjust the
         sine wave parameters such that the sine wave output is continuous.
       */
      if (params_changed) {
        real_T x;

        /*
           Only adjust the amplitude once the current amplitude crosses zero. Otherwise
           we get strange behaviour when continuously modifying the input amplitude and
           frequency using input signals.
         */
        if (y_sin == 0 ||
            AprilTag_PickandPlace_DW.SmoothSignalGenerator_RWORK.Sin_w_t == 0 ||
            (y_sin < 0) !=
            (AprilTag_PickandPlace_DW.SmoothSignalGenerator_RWORK.Sin_w_t < 0))
        {
          if (fabs(AprilTag_PickandPlace_DW.SmoothSignalGenerator_RWORK.Amp *
                   AprilTag_PickandPlace_DW.SmoothSignalGenerator_RWORK.Sin_w_t)
              < AprilTag_PickandPlace_P.SmoothSignalGenerator_Amplitude) {
            x = asin(AprilTag_PickandPlace_DW.SmoothSignalGenerator_RWORK.Amp *
                     AprilTag_PickandPlace_DW.SmoothSignalGenerator_RWORK.Sin_w_t
                     / AprilTag_PickandPlace_P.SmoothSignalGenerator_Amplitude);
            AprilTag_PickandPlace_DW.SmoothSignalGenerator_RWORK.Sin_w_dt = sin
              (w * 0.002);
            AprilTag_PickandPlace_DW.SmoothSignalGenerator_RWORK.Cos_w_dt = cos
              (w * 0.002);
            AprilTag_PickandPlace_DW.SmoothSignalGenerator_RWORK.Sin_w_t = sin(x);

            /*
               There are always two solutions for the phase. Choose the solution
               that matches the slope as well as the amplitude.
             */
            if ((cos(x) < 0) !=
                (AprilTag_PickandPlace_DW.SmoothSignalGenerator_RWORK.Cos_w_t <
                 0)) {
              AprilTag_PickandPlace_DW.SmoothSignalGenerator_RWORK.Cos_w_t =
                -cos(x);
            } else {
              AprilTag_PickandPlace_DW.SmoothSignalGenerator_RWORK.Cos_w_t = cos
                (x);
            }
          } else {
            /* really low amplitudes where sawtooth wave goes further in one time step after crossing zero than the new amplitude */
            x = w * 0.002;
            AprilTag_PickandPlace_DW.SmoothSignalGenerator_RWORK.Sin_w_t = 0;

            /* Make sure cosine output is also continuous */
            if (AprilTag_PickandPlace_DW.SmoothSignalGenerator_RWORK.Cos_w_t < 0)
            {
              AprilTag_PickandPlace_DW.SmoothSignalGenerator_RWORK.Cos_w_t = -1;
            } else {
              AprilTag_PickandPlace_DW.SmoothSignalGenerator_RWORK.Cos_w_t = +1;
            }

            AprilTag_PickandPlace_DW.SmoothSignalGenerator_RWORK.Sin_w_dt = sin
              (x);
            AprilTag_PickandPlace_DW.SmoothSignalGenerator_RWORK.Cos_w_dt = cos
              (x);
          }

          AprilTag_PickandPlace_DW.SmoothSignalGenerator_RWORK.Amp =
            AprilTag_PickandPlace_P.SmoothSignalGenerator_Amplitude;
          AprilTag_PickandPlace_DW.SmoothSignalGenerator_RWORK.W = w;
        }
      }
    }

    /* Bias: '<S3>/Bias' */
    rtb_Bias += AprilTag_PickandPlace_P.Bias_Bias;

    /* S-Function (hil_write_block): '<S3>/HIL Write' incorporates:
     *  Constant: '<Root>/Constant1'
     *  Constant: '<S2>/Constant'
     */

    /* S-Function Block: AprilTag_PickandPlace/Hardware Plant P(s)/HIL Write (hil_write_block) */
    {
      t_error result;
      AprilTag_PickandPlace_DW.HILWrite_OtherBuffer[0] =
        AprilTag_PickandPlace_B.theta[0];
      AprilTag_PickandPlace_DW.HILWrite_OtherBuffer[1] =
        AprilTag_PickandPlace_B.theta[1];
      AprilTag_PickandPlace_DW.HILWrite_OtherBuffer[2] =
        AprilTag_PickandPlace_B.theta[2];
      AprilTag_PickandPlace_DW.HILWrite_OtherBuffer[3] =
        AprilTag_PickandPlace_B.theta[3];
      AprilTag_PickandPlace_DW.HILWrite_OtherBuffer[4] =
        AprilTag_PickandPlace_B.gripposition;
      AprilTag_PickandPlace_DW.HILWrite_OtherBuffer[5] =
        AprilTag_PickandPlace_P.Constant1_Value[0];
      AprilTag_PickandPlace_DW.HILWrite_OtherBuffer[6] =
        AprilTag_PickandPlace_P.Constant1_Value[1];
      AprilTag_PickandPlace_DW.HILWrite_OtherBuffer[7] =
        AprilTag_PickandPlace_P.Constant1_Value[2];
      AprilTag_PickandPlace_DW.HILWrite_OtherBuffer[8] =
        AprilTag_PickandPlace_P.Constant1_Value[3];
      AprilTag_PickandPlace_DW.HILWrite_OtherBuffer[9] =
        AprilTag_PickandPlace_P.ColorConstant_color[0];
      AprilTag_PickandPlace_DW.HILWrite_OtherBuffer[10] =
        AprilTag_PickandPlace_P.ColorConstant_color[1];
      AprilTag_PickandPlace_DW.HILWrite_OtherBuffer[11] =
        AprilTag_PickandPlace_P.ColorConstant_color[2];
      AprilTag_PickandPlace_DW.HILWrite_OtherBuffer[12] = rtb_Bias;
      result = hil_write(AprilTag_PickandPlace_DW.HILInitializePositionMode_Card,
                         NULL, 0U,
                         NULL, 0U,
                         NULL, 0U,
                         AprilTag_PickandPlace_P.HILWrite_other_channels, 13U,
                         NULL,
                         NULL,
                         NULL,
                         &AprilTag_PickandPlace_DW.HILWrite_OtherBuffer[0]
                         );
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(AprilTag_PickandPlace_M, _rt_error_message);
      }
    }

    /* Constant: '<S9>/x0' */
    AprilTag_PickandPlace_B.x0 = AprilTag_PickandPlace_P.x0_Value;
  }

  /* Integrator: '<S9>/Integrator1' */
  if (AprilTag_PickandPlace_DW.Integrator1_IWORK != 0) {
    AprilTag_PickandPlace_X.Integrator1_CSTATE = AprilTag_PickandPlace_B.x0;
  }

  /* Integrator: '<S9>/Integrator1' */
  AprilTag_PickandPlace_B.Integrator1 =
    AprilTag_PickandPlace_X.Integrator1_CSTATE;
  if (rtmIsMajorTimeStep(AprilTag_PickandPlace_M)) {
    /* Constant: '<S8>/Soft-Grip Current (A)' */
    AprilTag_PickandPlace_B.goalcurrent =
      AprilTag_PickandPlace_P.SoftGripCurrentA_Value;
  }

  /* Product: '<S9>/Product' incorporates:
   *  Constant: '<S9>/Constant'
   *  Constant: '<S9>/wn'
   *  Constant: '<S9>/zt'
   *  Integrator: '<S9>/Integrator2'
   *  Product: '<S9>/Product2'
   *  Sum: '<S9>/Sum'
   *  Sum: '<S9>/Sum1'
   */
  AprilTag_PickandPlace_B.Product = ((AprilTag_PickandPlace_B.grippercurrent -
    AprilTag_PickandPlace_B.Integrator1) -
    AprilTag_PickandPlace_X.Integrator2_CSTATE *
    AprilTag_PickandPlace_P.Constant_Value_e *
    AprilTag_PickandPlace_P.undOrder25HzfilterbasedonFFT__k) *
    AprilTag_PickandPlace_P.undOrder25HzfilterbasedonFFT_in;

  /* Product: '<S9>/Product1' incorporates:
   *  Constant: '<S9>/wn'
   *  Integrator: '<S9>/Integrator2'
   */
  AprilTag_PickandPlace_B.Product1 =
    AprilTag_PickandPlace_P.undOrder25HzfilterbasedonFFT_in *
    AprilTag_PickandPlace_X.Integrator2_CSTATE;

  /* Gain: '<S8>/Gain2' incorporates:
   *  Sum: '<S8>/Subtract'
   */
  AprilTag_PickandPlace_B.Gain2 = (AprilTag_PickandPlace_B.goalcurrent -
    AprilTag_PickandPlace_B.Integrator1) * AprilTag_PickandPlace_P.Gain2_Gain;
}

/* Model update function for TID0 */
void AprilTag_PickandPlace_update0(void) /* Sample time: [0.0s, 0.0s] */
{
  /* Update for Integrator: '<S9>/Integrator1' */
  AprilTag_PickandPlace_DW.Integrator1_IWORK = 0;
  if (rtmIsMajorTimeStep(AprilTag_PickandPlace_M)) {
    rt_ertODEUpdateContinuousStates(&AprilTag_PickandPlace_M->solverInfo);
  }

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++AprilTag_PickandPlace_M->Timing.clockTick0)) {
    ++AprilTag_PickandPlace_M->Timing.clockTickH0;
  }

  AprilTag_PickandPlace_M->Timing.t[0] = rtsiGetSolverStopTime
    (&AprilTag_PickandPlace_M->solverInfo);

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick1"
   * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick1 and the high bits
   * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++AprilTag_PickandPlace_M->Timing.clockTick1)) {
    ++AprilTag_PickandPlace_M->Timing.clockTickH1;
  }

  AprilTag_PickandPlace_M->Timing.t[1] =
    AprilTag_PickandPlace_M->Timing.clockTick1 *
    AprilTag_PickandPlace_M->Timing.stepSize1 +
    AprilTag_PickandPlace_M->Timing.clockTickH1 *
    AprilTag_PickandPlace_M->Timing.stepSize1 * 4294967296.0;
}

/* Derivatives for root system: '<Root>' */
void AprilTag_PickandPlace_derivatives(void)
{
  XDot_AprilTag_PickandPlace_T *_rtXdot;
  boolean_T lsat;
  boolean_T usat;
  _rtXdot = ((XDot_AprilTag_PickandPlace_T *) AprilTag_PickandPlace_M->derivs);

  /* Derivatives for Integrator: '<S8>/Integrator' */
  lsat = (AprilTag_PickandPlace_X.Integrator_CSTATE <=
          AprilTag_PickandPlace_P.Integrator_LowerSat);
  usat = (AprilTag_PickandPlace_X.Integrator_CSTATE >=
          AprilTag_PickandPlace_P.Integrator_UpperSat);
  if (((!lsat) && (!usat)) || (lsat && (AprilTag_PickandPlace_B.Gain2 > 0.0)) ||
      (usat && (AprilTag_PickandPlace_B.Gain2 < 0.0))) {
    _rtXdot->Integrator_CSTATE = AprilTag_PickandPlace_B.Gain2;
  } else {
    /* in saturation */
    _rtXdot->Integrator_CSTATE = 0.0;
  }

  /* End of Derivatives for Integrator: '<S8>/Integrator' */

  /* Derivatives for Integrator: '<S9>/Integrator1' */
  _rtXdot->Integrator1_CSTATE = AprilTag_PickandPlace_B.Product1;

  /* Derivatives for Integrator: '<S9>/Integrator2' */
  _rtXdot->Integrator2_CSTATE = AprilTag_PickandPlace_B.Product;
}

/* Model output function for TID2 */
void AprilTag_PickandPlace_output2(void) /* Sample time: [0.034s, 0.0s] */
{
  /* S-Function (video3d_initialize_block): '<Root>/Video3D Initialize' */

  /* S-Function Block: AprilTag_PickandPlace/Video3D Initialize (video3d_initialize_block) */
  {
  }

  /* S-Function (video3d_capture_block): '<Root>/Virtual QArm RGB' */
  /* S-Function Block: AprilTag_PickandPlace/Virtual QArm RGB (video3d_capture_block) */
  {
    t_video3d_frame frame;
    t_error result;

    {
      int_T i1;
      real32_T *y4 = &AprilTag_PickandPlace_B.VirtualQArmRGB_o5[0];
      real32_T *dw_Intrinsics =
        &AprilTag_PickandPlace_DW.VirtualQArmRGB_Intrinsics[0];
      for (i1=0; i1 < 9; i1++) {
        y4[i1] = dw_Intrinsics[i1];
      }
    }

    result = video3d_stream_get_frame
      (AprilTag_PickandPlace_DW.VirtualQArmRGB_Stream, &frame);
    if (result >= 0) {
      result = video3d_frame_get_data(frame,
        &AprilTag_PickandPlace_B.VirtualQArmRGB_o1[0]);

      /* Release the frame to free up its resources */
      video3d_frame_release(frame);
    }

    if (result < 0 && result != -QERR_WOULD_BLOCK) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(AprilTag_PickandPlace_M, _rt_error_message);
    }
  }
}

/* Model update function for TID2 */
void AprilTag_PickandPlace_update2(void) /* Sample time: [0.034s, 0.0s] */
{
  /* Update absolute time */
  /* The "clockTick2" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick2"
   * and "Timing.stepSize2". Size of "clockTick2" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick2 and the high bits
   * Timing.clockTickH2. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++AprilTag_PickandPlace_M->Timing.clockTick2)) {
    ++AprilTag_PickandPlace_M->Timing.clockTickH2;
  }

  AprilTag_PickandPlace_M->Timing.t[2] =
    AprilTag_PickandPlace_M->Timing.clockTick2 *
    AprilTag_PickandPlace_M->Timing.stepSize2 +
    AprilTag_PickandPlace_M->Timing.clockTickH2 *
    AprilTag_PickandPlace_M->Timing.stepSize2 * 4294967296.0;
}

/* Model output function for TID3 */
void AprilTag_PickandPlace_output3(void) /* Sample time: [2.5s, 0.0s] */
{
  real_T rtb_RateLimiter;
  boolean_T rtb_TmpRTBAtSwitch1Inport2;

  /* Sum: '<S1>/Sum' incorporates:
   *  Constant: '<S1>/Constant'
   *  UnitDelay: '<S1>/Unit Delay'
   */
  AprilTag_PickandPlace_B.Sum = AprilTag_PickandPlace_P.Constant_Value_m -
    AprilTag_PickandPlace_DW.UnitDelay_DSTATE;

  /* RateTransition generated from: '<Root>/Counter' */
  AprilTag_PickandPlace_B.TmpRTBAtCounterInport2 = AprilTag_PickandPlace_B.Equal;

  /* S-Function (sdspcount2): '<Root>/Counter' */
  if (MWDSP_EPH_R_B(AprilTag_PickandPlace_B.TmpRTBAtCounterInport2,
                    &AprilTag_PickandPlace_DW.Counter_RstEphState) != 0U) {
    AprilTag_PickandPlace_DW.Counter_Count =
      AprilTag_PickandPlace_P.Counter_InitialCount;
  }

  if (MWDSP_EPH_R_D(AprilTag_PickandPlace_B.Sum,
                    &AprilTag_PickandPlace_DW.Counter_ClkEphState) != 0U) {
    if (AprilTag_PickandPlace_DW.Counter_Count < 5) {
      AprilTag_PickandPlace_DW.Counter_Count++;
    } else {
      AprilTag_PickandPlace_DW.Counter_Count = 0U;
    }
  }

  /* RateTransition generated from: '<Root>/Switch1' */
  rtb_TmpRTBAtSwitch1Inport2 = AprilTag_PickandPlace_B.Equal;

  /* Switch: '<Root>/Switch1' incorporates:
   *  Constant: '<Root>/Constant'
   *  S-Function (sdspcount2): '<Root>/Counter'
   */
  if (rtb_TmpRTBAtSwitch1Inport2) {
    rtb_RateLimiter = (int8_T)AprilTag_PickandPlace_DW.Counter_Count;
  } else {
    rtb_RateLimiter = AprilTag_PickandPlace_P.Constant_Value;
  }

  /* Bias: '<Root>/Add Constant' incorporates:
   *  Switch: '<Root>/Switch1'
   */
  AprilTag_PickandPlace_B.AddConstant = rtb_RateLimiter +
    AprilTag_PickandPlace_P.AddConstant_Bias;

  /* MultiPortSwitch: '<Root>/Multiport Switch2' */
  switch ((int32_T)AprilTag_PickandPlace_B.AddConstant) {
   case 1:
    /* MultiPortSwitch: '<Root>/Multiport Switch2' incorporates:
     *  Constant: '<Root>/Gripper Open'
     */
    AprilTag_PickandPlace_B.MultiportSwitch2 =
      AprilTag_PickandPlace_P.GripperOpen_Value;
    break;

   case 2:
    /* MultiPortSwitch: '<Root>/Multiport Switch2' incorporates:
     *  Constant: '<Root>/Gripper Close'
     */
    AprilTag_PickandPlace_B.MultiportSwitch2 =
      AprilTag_PickandPlace_P.GripperClose_Value;
    break;

   case 3:
    /* MultiPortSwitch: '<Root>/Multiport Switch2' incorporates:
     *  Constant: '<Root>/Gripper Close'
     */
    AprilTag_PickandPlace_B.MultiportSwitch2 =
      AprilTag_PickandPlace_P.GripperClose_Value;
    break;

   case 4:
    /* MultiPortSwitch: '<Root>/Multiport Switch2' incorporates:
     *  Constant: '<Root>/Gripper Close'
     */
    AprilTag_PickandPlace_B.MultiportSwitch2 =
      AprilTag_PickandPlace_P.GripperClose_Value;
    break;

   case 5:
    /* MultiPortSwitch: '<Root>/Multiport Switch2' incorporates:
     *  Constant: '<Root>/Gripper Open'
     */
    AprilTag_PickandPlace_B.MultiportSwitch2 =
      AprilTag_PickandPlace_P.GripperOpen_Value;
    break;

   default:
    /* MultiPortSwitch: '<Root>/Multiport Switch2' incorporates:
     *  Constant: '<Root>/Gripper Open'
     */
    AprilTag_PickandPlace_B.MultiportSwitch2 =
      AprilTag_PickandPlace_P.GripperOpen_Value;
    break;
  }

  /* End of MultiPortSwitch: '<Root>/Multiport Switch2' */

  /* RateLimiter: '<Root>/Rate Limiter' incorporates:
   *  Delay: '<Root>/Delay'
   */
  rtb_RateLimiter = AprilTag_PickandPlace_DW.Delay_DSTATE -
    AprilTag_PickandPlace_DW.PrevY;
  if (rtb_RateLimiter > AprilTag_PickandPlace_P.RateLimiter_RisingLim *
      AprilTag_PickandPlace_period) {
    rtb_RateLimiter = AprilTag_PickandPlace_P.RateLimiter_RisingLim *
      AprilTag_PickandPlace_period + AprilTag_PickandPlace_DW.PrevY;
  } else if (rtb_RateLimiter < AprilTag_PickandPlace_P.RateLimiter_FallingLim *
             AprilTag_PickandPlace_period) {
    rtb_RateLimiter = AprilTag_PickandPlace_P.RateLimiter_FallingLim *
      AprilTag_PickandPlace_period + AprilTag_PickandPlace_DW.PrevY;
  } else {
    rtb_RateLimiter = AprilTag_PickandPlace_DW.Delay_DSTATE;
  }

  AprilTag_PickandPlace_DW.PrevY = rtb_RateLimiter;

  /* End of RateLimiter: '<Root>/Rate Limiter' */

  /* RateTransition generated from: '<Root>/Multiport Switch1' */
  AprilTag_PickandPlace_DW.TmpRTBAtMultiportSwitch1Inport1 =
    AprilTag_PickandPlace_B.AddConstant;

  /* RateTransition generated from: '<Root>/Rate Limiter' */
  AprilTag_PickandPlace_DW.TmpRTBAtRateLimiterOutport1_Buf = rtb_RateLimiter;
}

/* Model update function for TID3 */
void AprilTag_PickandPlace_update3(void) /* Sample time: [2.5s, 0.0s] */
{
  /* Update for UnitDelay: '<S1>/Unit Delay' */
  AprilTag_PickandPlace_DW.UnitDelay_DSTATE = AprilTag_PickandPlace_B.Sum;

  /* Update for Delay: '<Root>/Delay' */
  AprilTag_PickandPlace_DW.Delay_DSTATE =
    AprilTag_PickandPlace_B.MultiportSwitch2;

  /* Update absolute time */
  /* The "clockTick3" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick3"
   * and "Timing.stepSize3". Size of "clockTick3" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick3 and the high bits
   * Timing.clockTickH3. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++AprilTag_PickandPlace_M->Timing.clockTick3)) {
    ++AprilTag_PickandPlace_M->Timing.clockTickH3;
  }

  AprilTag_PickandPlace_M->Timing.t[3] =
    AprilTag_PickandPlace_M->Timing.clockTick3 *
    AprilTag_PickandPlace_M->Timing.stepSize3 +
    AprilTag_PickandPlace_M->Timing.clockTickH3 *
    AprilTag_PickandPlace_M->Timing.stepSize3 * 4294967296.0;
}

/* Use this function only if you need to maintain compatibility with an existing static main program. */
void AprilTag_PickandPlace_output(int_T tid)
{
  switch (tid) {
   case 0 :
    AprilTag_PickandPlace_output0();
    break;

   case 2 :
    AprilTag_PickandPlace_output2();
    break;

   case 3 :
    AprilTag_PickandPlace_output3();
    break;

   default :
    /* do nothing */
    break;
  }
}

/* Use this function only if you need to maintain compatibility with an existing static main program. */
void AprilTag_PickandPlace_update(int_T tid)
{
  switch (tid) {
   case 0 :
    AprilTag_PickandPlace_update0();
    break;

   case 2 :
    AprilTag_PickandPlace_update2();
    break;

   case 3 :
    AprilTag_PickandPlace_update3();
    break;

   default :
    /* do nothing */
    break;
  }
}

/* Model initialize function */
void AprilTag_PickandPlace_initialize(void)
{
  /* Start for S-Function (hil_initialize_block): '<Root>/HIL Initialize (Position Mode)' */

  /* S-Function Block: AprilTag_PickandPlace/HIL Initialize (Position Mode) (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("qarm_usb", "0",
                      &AprilTag_PickandPlace_DW.HILInitializePositionMode_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(AprilTag_PickandPlace_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options
      (AprilTag_PickandPlace_DW.HILInitializePositionMode_Card,
       "j0_mode=0;j1_mode=0;j2_mode=0;j3_mode=0;gripper_mode=0;j0_profile_config=0;j0_profile_velocity=1.5708;j0_profile_acceleration=1.0472;j1_profile_config=0;j1_profile_velocity=1.5708;j1_profile_acceleration=1.0472;j2_profile_config=0;j2_profile_velocity=1.5708;j2_profile_acceleration=1.0472;j3_profile_config=0;j3_profile_velocity=1.5708;j3_profile_acceleration=1.0472;",
       368);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(AprilTag_PickandPlace_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear
      (AprilTag_PickandPlace_DW.HILInitializePositionMode_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(AprilTag_PickandPlace_M, _rt_error_message);
      return;
    }

    if ((AprilTag_PickandPlace_P.HILInitializePositionMode_OOSta &&
         !is_switching) ||
        (AprilTag_PickandPlace_P.HILInitializePositionMode_OOEnt && is_switching))
    {
      {
        int_T i1;
        const real_T *p_HILInitializePositionMode_OOIni =
          AprilTag_PickandPlace_P.HILInitializePositionMode_OOIni;
        real_T *dw_OOValues =
          &AprilTag_PickandPlace_DW.HILInitializePositionMode_OOVal[0];
        for (i1=0; i1 < 11; i1++) {
          dw_OOValues[i1] = (p_HILInitializePositionMode_OOIni[i1]);
        }
      }

      AprilTag_PickandPlace_DW.HILInitializePositionMode_OOVal[11] =
        (AprilTag_PickandPlace_P.HILInitializePositionMode_OOIni[11]);
      AprilTag_PickandPlace_DW.HILInitializePositionMode_OOVal[12] =
        (AprilTag_PickandPlace_P.HILInitializePositionMode_OOIni[11]);
      result = hil_write_other
        (AprilTag_PickandPlace_DW.HILInitializePositionMode_Card,
         AprilTag_PickandPlace_P.HILInitializePositionMode_OOCha, 13U,
         &AprilTag_PickandPlace_DW.HILInitializePositionMode_OOVal[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(AprilTag_PickandPlace_M, _rt_error_message);
        return;
      }
    }

    if (AprilTag_PickandPlace_P.HILInitializePositionMode_OORes) {
      {
        int_T i1;
        const real_T *p_HILInitializePositionMode_OOWat =
          AprilTag_PickandPlace_P.HILInitializePositionMode_OOWat;
        real_T *dw_OOValues =
          &AprilTag_PickandPlace_DW.HILInitializePositionMode_OOVal[0];
        for (i1=0; i1 < 11; i1++) {
          dw_OOValues[i1] = (p_HILInitializePositionMode_OOWat[i1]);
        }
      }

      AprilTag_PickandPlace_DW.HILInitializePositionMode_OOVal[11] =
        (AprilTag_PickandPlace_P.HILInitializePositionMode_OOWat[11]);
      AprilTag_PickandPlace_DW.HILInitializePositionMode_OOVal[12] =
        (AprilTag_PickandPlace_P.HILInitializePositionMode_OOWat[11]);
      result = hil_watchdog_set_other_expiration_state
        (AprilTag_PickandPlace_DW.HILInitializePositionMode_Card,
         AprilTag_PickandPlace_P.HILInitializePositionMode_OOCha, 13U,
         &AprilTag_PickandPlace_DW.HILInitializePositionMode_OOVal[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(AprilTag_PickandPlace_M, _rt_error_message);
        return;
      }
    }
  }

  /* Start for S-Function (hil_read_timebase_block): '<S3>/HIL Read Timebase1' */

  /* S-Function Block: AprilTag_PickandPlace/Hardware Plant P(s)/HIL Read Timebase1 (hil_read_timebase_block) */
  {
    t_error result;
    result = hil_task_create_reader
      (AprilTag_PickandPlace_DW.HILInitializePositionMode_Card,
       AprilTag_PickandPlace_P.HILReadTimebase1_SamplesInBuffe,
       AprilTag_PickandPlace_P.HILReadTimebase1_AnalogChannels, 5U,
       NULL, 0U,
       NULL, 0U,
       AprilTag_PickandPlace_P.HILReadTimebase1_OtherChannels, 20U,
       &AprilTag_PickandPlace_DW.HILReadTimebase1_Task);
    if (result >= 0) {
      result = hil_task_set_buffer_overflow_mode
        (AprilTag_PickandPlace_DW.HILReadTimebase1_Task, (t_buffer_overflow_mode)
         (AprilTag_PickandPlace_P.HILReadTimebase1_OverflowMode - 1));
    }

    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(AprilTag_PickandPlace_M, _rt_error_message);
    }
  }

  /* Start for RateTransition generated from: '<Root>/Multiport Switch1' */
  AprilTag_PickandPlace_B.TmpRTBAtMultiportSwitch1Inport1 =
    AprilTag_PickandPlace_P.TmpRTBAtMultiportSwitch1Inport1;

  /* Start for RateTransition generated from: '<Root>/Rate Limiter' */
  AprilTag_PickandPlace_B.TmpRTBAtRateLimiterOutport1 =
    AprilTag_PickandPlace_P.TmpRTBAtRateLimiterOutport1_Ini;

  /* Start for S-Function (smooth_signal_generator_block): '<S3>/Smooth Signal Generator' */

  /* S-Function Block: AprilTag_PickandPlace/Hardware Plant P(s)/Smooth Signal Generator (smooth_signal_generator_block) */
  {
    real_T T = 1.0 / AprilTag_PickandPlace_P.SmoothSignalGenerator_Frequency;
    AprilTag_PickandPlace_DW.SmoothSignalGenerator_RWORK.Amp =
      AprilTag_PickandPlace_P.SmoothSignalGenerator_Amplitude;
    AprilTag_PickandPlace_DW.SmoothSignalGenerator_RWORK.W = TWO_PI *
      AprilTag_PickandPlace_P.SmoothSignalGenerator_Frequency;
    AprilTag_PickandPlace_DW.SmoothSignalGenerator_RWORK.Sin_w_dt = sin
      (AprilTag_PickandPlace_DW.SmoothSignalGenerator_RWORK.W * 0.002);
    AprilTag_PickandPlace_DW.SmoothSignalGenerator_RWORK.Cos_w_dt = cos
      (AprilTag_PickandPlace_DW.SmoothSignalGenerator_RWORK.W * 0.002);
    AprilTag_PickandPlace_DW.SmoothSignalGenerator_RWORK.Sin_w_t = sin
      (AprilTag_PickandPlace_P.SmoothSignalGenerator_InitialPh);
    AprilTag_PickandPlace_DW.SmoothSignalGenerator_RWORK.Cos_w_t = cos
      (AprilTag_PickandPlace_P.SmoothSignalGenerator_InitialPh);
  }

  /* Start for Constant: '<S9>/x0' */
  AprilTag_PickandPlace_B.x0 = AprilTag_PickandPlace_P.x0_Value;

  /* Start for S-Function (video3d_initialize_block): '<Root>/Video3D Initialize' */

  /* S-Function Block: AprilTag_PickandPlace/Video3D Initialize (video3d_initialize_block) */
  {
    t_error result;
    result = video3d_open("0",
                          &AprilTag_PickandPlace_DW.Video3DInitialize_Video3D);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(AprilTag_PickandPlace_M, _rt_error_message);
      return;
    }
  }

  /* Start for S-Function (video3d_capture_block): '<Root>/Virtual QArm RGB' */
  {
    t_error result;
    result = video3d_stream_open
      (AprilTag_PickandPlace_DW.Video3DInitialize_Video3D, VIDEO3D_STREAM_COLOR,
       AprilTag_PickandPlace_P.VirtualQArmRGB_stream_index, 29.411764705882351,
       640, 480,
       IMAGE_FORMAT_COL_MAJOR_GRAYSCALE, IMAGE_DATA_TYPE_UINT8,
       &AprilTag_PickandPlace_DW.VirtualQArmRGB_Stream);
    if (result >= 0) {
      t_video3d_property config_properties[4];
      t_double config_values[4];
      t_uint num_config_properties = 0;
      if (AprilTag_PickandPlace_P.VirtualQArmRGB_Preset != 21) {
        config_properties[num_config_properties] =
          VIDEO3D_PROPERTY_VISUAL_PRESET;
        config_values[num_config_properties] = (t_video3d_visual_preset)
          (AprilTag_PickandPlace_P.VirtualQArmRGB_Preset - 1);
        num_config_properties++;
      }

      if (AprilTag_PickandPlace_P.VirtualQArmRGB_Emitter != 3) {
        config_properties[num_config_properties] =
          VIDEO3D_PROPERTY_ENABLE_EMITTER;
        config_values[num_config_properties] =
          (AprilTag_PickandPlace_P.VirtualQArmRGB_Emitter == 1) ? 1.0 : 0.0;
        num_config_properties++;
      }

      config_properties[num_config_properties] =
        VIDEO3D_PROPERTY_ENABLE_AUTO_WHITE_BALANCE;
      config_values[num_config_properties] = 1.0;
      num_config_properties++;
      config_properties[num_config_properties] =
        VIDEO3D_PROPERTY_ENABLE_AUTO_EXPOSURE;
      config_values[num_config_properties] = 1.0;
      num_config_properties++;
      if (num_config_properties > 0) {
        video3d_stream_set_properties
          (AprilTag_PickandPlace_DW.VirtualQArmRGB_Stream, config_properties,
           num_config_properties, config_values);
      }
    }

    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(AprilTag_PickandPlace_M, _rt_error_message);
    }
  }

  AprilTag_PickandPlace_PrevZCX.Integrator_Reset_ZCE = UNINITIALIZED_ZCSIG;

  /* InitializeConditions for RateTransition generated from: '<Root>/Multiport Switch1' */
  AprilTag_PickandPlace_DW.TmpRTBAtMultiportSwitch1Inport1 =
    AprilTag_PickandPlace_P.TmpRTBAtMultiportSwitch1Inport1;

  /* InitializeConditions for RateTransition generated from: '<Root>/Rate Limiter' */
  AprilTag_PickandPlace_DW.TmpRTBAtRateLimiterOutport1_Buf =
    AprilTag_PickandPlace_P.TmpRTBAtRateLimiterOutport1_Ini;

  /* InitializeConditions for Integrator: '<S8>/Integrator' */
  AprilTag_PickandPlace_X.Integrator_CSTATE =
    AprilTag_PickandPlace_P.Integrator_IC;

  /* InitializeConditions for Integrator: '<S9>/Integrator1' */
  if (rtmIsFirstInitCond(AprilTag_PickandPlace_M)) {
    AprilTag_PickandPlace_X.Integrator1_CSTATE = 0.0;
  }

  AprilTag_PickandPlace_DW.Integrator1_IWORK = 1;

  /* End of InitializeConditions for Integrator: '<S9>/Integrator1' */

  /* InitializeConditions for Integrator: '<S9>/Integrator2' */
  AprilTag_PickandPlace_X.Integrator2_CSTATE =
    AprilTag_PickandPlace_P.Integrator2_IC;

  /* InitializeConditions for S-Function (video3d_initialize_block): '<Root>/Video3D Initialize' */

  /* S-Function Block: AprilTag_PickandPlace/Video3D Initialize (video3d_initialize_block) */
  {
    if (rtmIsFirstInitCond(AprilTag_PickandPlace_M)) {
      t_error result = video3d_start_streaming
        (AprilTag_PickandPlace_DW.Video3DInitialize_Video3D);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(AprilTag_PickandPlace_M, _rt_error_message);
        return;
      }
    }
  }

  /* InitializeConditions for S-Function (video3d_capture_block): '<Root>/Virtual QArm RGB' */

  /* S-Function Block: AprilTag_PickandPlace/Virtual QArm RGB (video3d_capture_block) */
  {
    if (rtmIsFirstInitCond(AprilTag_PickandPlace_M)) {
      t_single intrinsics[3][3];
      t_single coefficients[5];
      t_error result;
      result = video3d_stream_get_camera_intrinsics
        (AprilTag_PickandPlace_DW.VirtualQArmRGB_Stream, intrinsics,
         &AprilTag_PickandPlace_DW.VirtualQArmRGB_Model, coefficients);
      if (result >= 0) {
        memory_copy(&AprilTag_PickandPlace_DW.VirtualQArmRGB_Intrinsics[0], 9 *
                    sizeof(t_single), intrinsics);
        memory_copy(&AprilTag_PickandPlace_DW.VirtualQArmRGB_Coefficients[0], 5 *
                    sizeof(t_single), coefficients);
      } else {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(AprilTag_PickandPlace_M, _rt_error_message);
        return;
      }
    }
  }

  /* InitializeConditions for UnitDelay: '<S1>/Unit Delay' */
  AprilTag_PickandPlace_DW.UnitDelay_DSTATE =
    AprilTag_PickandPlace_P.UnitDelay_InitialCondition;

  /* InitializeConditions for S-Function (sdspcount2): '<Root>/Counter' */
  AprilTag_PickandPlace_DW.Counter_ClkEphState = 5U;
  AprilTag_PickandPlace_DW.Counter_RstEphState = 5U;
  AprilTag_PickandPlace_DW.Counter_Count =
    AprilTag_PickandPlace_P.Counter_InitialCount;

  /* InitializeConditions for Delay: '<Root>/Delay' */
  AprilTag_PickandPlace_DW.Delay_DSTATE =
    AprilTag_PickandPlace_P.Delay_InitialCondition;

  /* InitializeConditions for RateLimiter: '<Root>/Rate Limiter' */
  AprilTag_PickandPlace_DW.PrevY = AprilTag_PickandPlace_P.RateLimiter_IC;

  /* set "at time zero" to false */
  if (rtmIsFirstInitCond(AprilTag_PickandPlace_M)) {
    rtmSetFirstInitCond(AprilTag_PickandPlace_M, 0);
  }
}

/* Model terminate function */
void AprilTag_PickandPlace_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<Root>/HIL Initialize (Position Mode)' */

  /* S-Function Block: AprilTag_PickandPlace/HIL Initialize (Position Mode) (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_other_outputs = 0;
    hil_task_stop_all(AprilTag_PickandPlace_DW.HILInitializePositionMode_Card);
    hil_monitor_stop_all(AprilTag_PickandPlace_DW.HILInitializePositionMode_Card);
    is_switching = false;
    if ((AprilTag_PickandPlace_P.HILInitializePositionMode_OOTer &&
         !is_switching) ||
        (AprilTag_PickandPlace_P.HILInitializePositionMode_OOExi && is_switching))
    {
      AprilTag_PickandPlace_DW.HILInitializePositionMode_OOVal[0] =
        (AprilTag_PickandPlace_P.HILInitializePositionMode_OOFin[0]);
      AprilTag_PickandPlace_DW.HILInitializePositionMode_OOVal[1] =
        (AprilTag_PickandPlace_P.HILInitializePositionMode_OOFin[1]);
      AprilTag_PickandPlace_DW.HILInitializePositionMode_OOVal[2] =
        (AprilTag_PickandPlace_P.HILInitializePositionMode_OOFin[2]);

      {
        int_T i1;
        real_T *dw_OOValues =
          &AprilTag_PickandPlace_DW.HILInitializePositionMode_OOVal[3];
        for (i1=0; i1 < 10; i1++) {
          dw_OOValues[i1] =
            (AprilTag_PickandPlace_P.HILInitializePositionMode_OOFin[3]);
        }
      }

      num_final_other_outputs = 13U;
    } else {
      num_final_other_outputs = 0;
    }

    if (num_final_other_outputs > 0) {
      result = hil_write_other
        (AprilTag_PickandPlace_DW.HILInitializePositionMode_Card,
         AprilTag_PickandPlace_P.HILInitializePositionMode_OOCha,
         num_final_other_outputs,
         &AprilTag_PickandPlace_DW.HILInitializePositionMode_OOVal[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(AprilTag_PickandPlace_M, _rt_error_message);
      }
    }

    hil_task_delete_all(AprilTag_PickandPlace_DW.HILInitializePositionMode_Card);
    hil_monitor_delete_all
      (AprilTag_PickandPlace_DW.HILInitializePositionMode_Card);
    hil_close(AprilTag_PickandPlace_DW.HILInitializePositionMode_Card);
    AprilTag_PickandPlace_DW.HILInitializePositionMode_Card = NULL;
  }

  /* Terminate for S-Function (video3d_initialize_block): '<Root>/Video3D Initialize' */

  /* S-Function Block: AprilTag_PickandPlace/Video3D Initialize (video3d_initialize_block) */
  {
    video3d_stop_streaming(AprilTag_PickandPlace_DW.Video3DInitialize_Video3D);
    video3d_close(AprilTag_PickandPlace_DW.Video3DInitialize_Video3D);
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/

/* Solver interface called by GRT_Main */
#ifndef USE_GENERATED_SOLVER

void rt_ODECreateIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEDestroyIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEUpdateContinuousStates(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

#endif

void MdlOutputs(int_T tid)
{
  if (tid == 1)
    tid = 0;
  AprilTag_PickandPlace_output(tid);
}

void MdlUpdate(int_T tid)
{
  if (tid == 1)
    tid = 0;
  AprilTag_PickandPlace_update(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  AprilTag_PickandPlace_initialize();
}

void MdlTerminate(void)
{
  AprilTag_PickandPlace_terminate();
}

/* Registration function */
RT_MODEL_AprilTag_PickandPlac_T *AprilTag_PickandPlace(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* non-finite (run-time) assignments */
  AprilTag_PickandPlace_P.HILInitializePositionMode_AOHig = rtInf;
  AprilTag_PickandPlace_P.HILInitializePositionMode_AOLow = rtMinusInf;

  /* initialize real-time model */
  (void) memset((void *)AprilTag_PickandPlace_M, 0,
                sizeof(RT_MODEL_AprilTag_PickandPlac_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&AprilTag_PickandPlace_M->solverInfo,
                          &AprilTag_PickandPlace_M->Timing.simTimeStep);
    rtsiSetTPtr(&AprilTag_PickandPlace_M->solverInfo, &rtmGetTPtr
                (AprilTag_PickandPlace_M));
    rtsiSetStepSizePtr(&AprilTag_PickandPlace_M->solverInfo,
                       &AprilTag_PickandPlace_M->Timing.stepSize0);
    rtsiSetdXPtr(&AprilTag_PickandPlace_M->solverInfo,
                 &AprilTag_PickandPlace_M->derivs);
    rtsiSetContStatesPtr(&AprilTag_PickandPlace_M->solverInfo, (real_T **)
                         &AprilTag_PickandPlace_M->contStates);
    rtsiSetNumContStatesPtr(&AprilTag_PickandPlace_M->solverInfo,
      &AprilTag_PickandPlace_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&AprilTag_PickandPlace_M->solverInfo,
      &AprilTag_PickandPlace_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&AprilTag_PickandPlace_M->solverInfo,
      &AprilTag_PickandPlace_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&AprilTag_PickandPlace_M->solverInfo,
      &AprilTag_PickandPlace_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&AprilTag_PickandPlace_M->solverInfo,
                          (&rtmGetErrorStatus(AprilTag_PickandPlace_M)));
    rtsiSetRTModelPtr(&AprilTag_PickandPlace_M->solverInfo,
                      AprilTag_PickandPlace_M);
  }

  rtsiSetSimTimeStep(&AprilTag_PickandPlace_M->solverInfo, MAJOR_TIME_STEP);
  AprilTag_PickandPlace_M->intgData.y = AprilTag_PickandPlace_M->odeY;
  AprilTag_PickandPlace_M->intgData.f[0] = AprilTag_PickandPlace_M->odeF[0];
  AprilTag_PickandPlace_M->intgData.f[1] = AprilTag_PickandPlace_M->odeF[1];
  AprilTag_PickandPlace_M->intgData.f[2] = AprilTag_PickandPlace_M->odeF[2];
  AprilTag_PickandPlace_M->intgData.f[3] = AprilTag_PickandPlace_M->odeF[3];
  AprilTag_PickandPlace_M->contStates = ((real_T *) &AprilTag_PickandPlace_X);
  rtsiSetSolverData(&AprilTag_PickandPlace_M->solverInfo, (void *)
                    &AprilTag_PickandPlace_M->intgData);
  rtsiSetIsMinorTimeStepWithModeChange(&AprilTag_PickandPlace_M->solverInfo,
    false);
  rtsiSetSolverName(&AprilTag_PickandPlace_M->solverInfo,"ode4");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = AprilTag_PickandPlace_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    mdlTsMap[2] = 2;
    mdlTsMap[3] = 3;

    /* polyspace +2 MISRA2012:D4.1 [Justified:Low] "AprilTag_PickandPlace_M points to
       static memory which is guaranteed to be non-NULL" */
    AprilTag_PickandPlace_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    AprilTag_PickandPlace_M->Timing.sampleTimes =
      (&AprilTag_PickandPlace_M->Timing.sampleTimesArray[0]);
    AprilTag_PickandPlace_M->Timing.offsetTimes =
      (&AprilTag_PickandPlace_M->Timing.offsetTimesArray[0]);

    /* task periods */
    AprilTag_PickandPlace_M->Timing.sampleTimes[0] = (0.0);
    AprilTag_PickandPlace_M->Timing.sampleTimes[1] = (0.002);
    AprilTag_PickandPlace_M->Timing.sampleTimes[2] = (0.034);
    AprilTag_PickandPlace_M->Timing.sampleTimes[3] = (2.5);

    /* task offsets */
    AprilTag_PickandPlace_M->Timing.offsetTimes[0] = (0.0);
    AprilTag_PickandPlace_M->Timing.offsetTimes[1] = (0.0);
    AprilTag_PickandPlace_M->Timing.offsetTimes[2] = (0.0);
    AprilTag_PickandPlace_M->Timing.offsetTimes[3] = (0.0);
  }

  rtmSetTPtr(AprilTag_PickandPlace_M, &AprilTag_PickandPlace_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = AprilTag_PickandPlace_M->Timing.sampleHitArray;
    int_T *mdlPerTaskSampleHits =
      AprilTag_PickandPlace_M->Timing.perTaskSampleHitsArray;
    AprilTag_PickandPlace_M->Timing.perTaskSampleHits = (&mdlPerTaskSampleHits[0]);
    mdlSampleHits[0] = 1;
    AprilTag_PickandPlace_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(AprilTag_PickandPlace_M, -1);
  AprilTag_PickandPlace_M->Timing.stepSize0 = 0.002;
  AprilTag_PickandPlace_M->Timing.stepSize1 = 0.002;
  AprilTag_PickandPlace_M->Timing.stepSize2 = 0.034;
  AprilTag_PickandPlace_M->Timing.stepSize3 = 2.5;
  rtmSetFirstInitCond(AprilTag_PickandPlace_M, 1);

  /* External mode info */
  AprilTag_PickandPlace_M->Sizes.checksums[0] = (871265169U);
  AprilTag_PickandPlace_M->Sizes.checksums[1] = (901344641U);
  AprilTag_PickandPlace_M->Sizes.checksums[2] = (3864447070U);
  AprilTag_PickandPlace_M->Sizes.checksums[3] = (1428478312U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[8];
    AprilTag_PickandPlace_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(AprilTag_PickandPlace_M->extModeInfo,
      &AprilTag_PickandPlace_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(AprilTag_PickandPlace_M->extModeInfo,
                        AprilTag_PickandPlace_M->Sizes.checksums);
    rteiSetTPtr(AprilTag_PickandPlace_M->extModeInfo, rtmGetTPtr
                (AprilTag_PickandPlace_M));
  }

  AprilTag_PickandPlace_M->solverInfoPtr = (&AprilTag_PickandPlace_M->solverInfo);
  AprilTag_PickandPlace_M->Timing.stepSize = (0.002);
  rtsiSetFixedStepSize(&AprilTag_PickandPlace_M->solverInfo, 0.002);
  rtsiSetSolverMode(&AprilTag_PickandPlace_M->solverInfo,
                    SOLVER_MODE_MULTITASKING);

  /* block I/O */
  AprilTag_PickandPlace_M->blockIO = ((void *) &AprilTag_PickandPlace_B);
  (void) memset(((void *) &AprilTag_PickandPlace_B), 0,
                sizeof(B_AprilTag_PickandPlace_T));

  /* parameters */
  AprilTag_PickandPlace_M->defaultParam = ((real_T *)&AprilTag_PickandPlace_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &AprilTag_PickandPlace_X;
    AprilTag_PickandPlace_M->contStates = (x);
    (void) memset((void *)&AprilTag_PickandPlace_X, 0,
                  sizeof(X_AprilTag_PickandPlace_T));
  }

  /* states (dwork) */
  AprilTag_PickandPlace_M->dwork = ((void *) &AprilTag_PickandPlace_DW);
  (void) memset((void *)&AprilTag_PickandPlace_DW, 0,
                sizeof(DW_AprilTag_PickandPlace_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    AprilTag_PickandPlace_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 26;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  AprilTag_PickandPlace_M->Sizes.numContStates = (3);/* Number of continuous states */
  AprilTag_PickandPlace_M->Sizes.numPeriodicContStates = (0);
                                      /* Number of periodic continuous states */
  AprilTag_PickandPlace_M->Sizes.numY = (0);/* Number of model outputs */
  AprilTag_PickandPlace_M->Sizes.numU = (0);/* Number of model inputs */
  AprilTag_PickandPlace_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  AprilTag_PickandPlace_M->Sizes.numSampTimes = (4);/* Number of sample times */
  AprilTag_PickandPlace_M->Sizes.numBlocks = (84);/* Number of blocks */
  AprilTag_PickandPlace_M->Sizes.numBlockIO = (29);/* Number of block outputs */
  AprilTag_PickandPlace_M->Sizes.numBlockPrms = (211);/* Sum of parameter "widths" */
  return AprilTag_PickandPlace_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
