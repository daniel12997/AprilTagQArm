/*
 * CameraCalImageCapture.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "CameraCalImageCapture".
 *
 * Model version              : 1.11
 * Simulink Coder version : 9.8 (R2022b) 13-May-2022
 * C source code generated on : Mon Nov 27 20:29:30 2023
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "CameraCalImageCapture.h"
#include "rtwtypes.h"
#include "CameraCalImageCapture_types.h"
#include "quanser_video3d.h"
#include <math.h>
#include <string.h>
#include "CameraCalImageCapture_private.h"
#include <emmintrin.h>
#include "rt_nonfinite.h"
#include <stdlib.h>
#include <stddef.h>
#include "zero_crossing_types.h"
#include "CameraCalImageCapture_dt.h"
#define CameraCalImageCapture_period   (0.002)

/* Block signals (default storage) */
B_CameraCalImageCapture_T CameraCalImageCapture_B;

/* Continuous states */
X_CameraCalImageCapture_T CameraCalImageCapture_X;

/* Block states (default storage) */
DW_CameraCalImageCapture_T CameraCalImageCapture_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_CameraCalImageCapture_T CameraCalImageCapture_PrevZCX;

/* Real-time model */
static RT_MODEL_CameraCalImageCaptur_T CameraCalImageCapture_M_;
RT_MODEL_CameraCalImageCaptur_T *const CameraCalImageCapture_M =
  &CameraCalImageCapture_M_;

/* Forward declaration for local functions */
static void CameraCalImageCa_emxInit_real_T(emxArray_real_T_CameraCalImag_T
  **pEmxArray, int32_T numDimensions);
static void emxInit_c_images_geotrans_inter(emxArray_c_images_geotrans_in_T
  **pEmxArray, int32_T numDimensions);
static void Camera_emxEnsureCapacity_real_T(emxArray_real_T_CameraCalImag_T
  *emxArray, int32_T oldNumel);
static void CameraCalImageCa_emxInit_char_T(emxArray_char_T_CameraCalImag_T
  **pEmxArray, int32_T numDimensions);
static void Camera_emxEnsureCapacity_char_T(emxArray_char_T_CameraCalImag_T
  *emxArray, int32_T oldNumel);
static void CameraCalImageCa_emxFree_char_T(emxArray_char_T_CameraCalImag_T
  **pEmxArray);
static void emxEnsureCapacity_c_images_geot(emxArray_c_images_geotrans_in_T
  *emxArray, int32_T oldNumel);
static real_T CameraCalImageCapture_det(const real_T x[9]);
static real_T CameraCalImageCapture_xnrm2(int32_T n, const real_T x[9], int32_T
  ix0);
static real_T CameraCalImageCapture_xdotc(int32_T n, const real_T x[9], int32_T
  ix0, const real_T y[9], int32_T iy0);
static void CameraCalImageCapture_xaxpy(int32_T n, real_T a, int32_T ix0, real_T
  y[9], int32_T iy0);
static real_T CameraCalImageCapture_xnrm2_m(const real_T x[3], int32_T ix0);
static void CameraCalImageCapture_xaxpy_g(int32_T n, real_T a, const real_T x[9],
  int32_T ix0, real_T y[3], int32_T iy0);
static void CameraCalImageCapture_xaxpy_gk(int32_T n, real_T a, const real_T x[3],
  int32_T ix0, real_T y[9], int32_T iy0);
static void CameraCalImageCapture_xswap(real_T x[9], int32_T ix0, int32_T iy0);
static void CameraCalImageCapture_xrotg(real_T *a, real_T *b, real_T *c, real_T *
  s);
static void CameraCalImageCapture_xrot(real_T x[9], int32_T ix0, int32_T iy0,
  real_T c, real_T s);
static void CameraCalImageCapture_svd(const real_T A[9], real_T U[9], real_T s[3],
  real_T V[9]);
static void CameraCalImageCapture_svd_d(const real_T A[9], real_T U[3]);
static real_T CameraCalImageCapture_norm(const real_T x[9]);
static void Cam_constrainToRotationMatrix3D(const real_T R[9], real_T Rc[9]);
static void emxFree_c_images_geotrans_inter(emxArray_c_images_geotrans_in_T
  **pEmxArray);
static void CameraCalImageCa_emxFree_real_T(emxArray_real_T_CameraCalImag_T
  **pEmxArray);
static void CameraCalImageC_emxInit_int32_T(emxArray_int32_T_CameraCalIma_T
  **pEmxArray, int32_T numDimensions);
static void Camer_emxEnsureCapacity_int32_T(emxArray_int32_T_CameraCalIma_T
  *emxArray, int32_T oldNumel);
static void CameraCalImag_emxInit_boolean_T(emxArray_boolean_T_CameraCalI_T
  **pEmxArray, int32_T numDimensions);
static void Cam_emxEnsureCapacity_boolean_T(emxArray_boolean_T_CameraCalI_T
  *emxArray, int32_T oldNumel);
static void CameraCalImageC_emxFree_int32_T(emxArray_int32_T_CameraCalIma_T
  **pEmxArray);
static void CameraCalImag_emxFree_boolean_T(emxArray_boolean_T_CameraCalI_T
  **pEmxArray);
static void CameraCalImageCapt_readAprilTag(const uint8_T b_I[307200], const
  real32_T varargin_2_FocalLength[2], const real32_T varargin_2_PrincipalPoint[2],
  emxArray_real_T_CameraCalImag_T *varargout_1, emxArray_real_T_CameraCalImag_T *
  varargout_2, real_T varargout_3_R[9], real_T varargout_3_Translation[3],
  emxArray_c_images_geotrans_in_T *varargout_3_Data);
static void rate_monotonic_scheduler(void);
time_T rt_SimUpdateDiscreteEvents(
  int_T rtmNumSampTimes, void *rtmTimingData, int_T *rtmSampleHitPtr, int_T
  *rtmPerTaskSampleHits )
{
  rtmSampleHitPtr[1] = rtmStepTask(CameraCalImageCapture_M, 1);
  rtmSampleHitPtr[2] = rtmStepTask(CameraCalImageCapture_M, 2);
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
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (CameraCalImageCapture_M->Timing.TaskCounters.TID[2])++;
  if ((CameraCalImageCapture_M->Timing.TaskCounters.TID[2]) > 16) {/* Sample time: [0.034s, 0.0s] */
    CameraCalImageCapture_M->Timing.TaskCounters.TID[2] = 0;
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
  CameraCalImageCapture_derivatives();

  /* f1 = f(t + (h/2), y + (h/2)*f0) */
  temp = 0.5 * h;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f0[i]);
  }

  rtsiSetT(si, t + temp);
  rtsiSetdX(si, f1);
  CameraCalImageCapture_output0();
  CameraCalImageCapture_derivatives();

  /* f2 = f(t + (h/2), y + (h/2)*f1) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f1[i]);
  }

  rtsiSetdX(si, f2);
  CameraCalImageCapture_output0();
  CameraCalImageCapture_derivatives();

  /* f3 = f(t + h, y + h*f2) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (h*f2[i]);
  }

  rtsiSetT(si, tnew);
  rtsiSetdX(si, f3);
  CameraCalImageCapture_output0();
  CameraCalImageCapture_derivatives();

  /* tnew = t + h
     ynew = y + (h/6)*(f0 + 2*f1 + 2*f2 + 2*f3) */
  temp = h / 6.0;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + temp*(f0[i] + 2.0*f1[i] + 2.0*f2[i] + f3[i]);
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

static void CameraCalImageCa_emxInit_real_T(emxArray_real_T_CameraCalImag_T
  **pEmxArray, int32_T numDimensions)
{
  emxArray_real_T_CameraCalImag_T *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_real_T_CameraCalImag_T *)malloc(sizeof
    (emxArray_real_T_CameraCalImag_T));
  emxArray = *pEmxArray;
  emxArray->data = (real_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)malloc(sizeof(int32_T) * (uint32_T)numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

static void emxInit_c_images_geotrans_inter(emxArray_c_images_geotrans_in_T
  **pEmxArray, int32_T numDimensions)
{
  emxArray_c_images_geotrans_in_T *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_c_images_geotrans_in_T *)malloc(sizeof
    (emxArray_c_images_geotrans_in_T));
  emxArray = *pEmxArray;
  emxArray->data = (c_images_geotrans_internal_ri_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)malloc(sizeof(int32_T) * (uint32_T)numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

static void Camera_emxEnsureCapacity_real_T(emxArray_real_T_CameraCalImag_T
  *emxArray, int32_T oldNumel)
{
  int32_T i;
  int32_T newNumel;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }

  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }

  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }

    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i <<= 1;
      }
    }

    newData = calloc((uint32_T)i, sizeof(real_T));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(real_T) * (uint32_T)oldNumel);
      if (emxArray->canFreeData) {
        free(emxArray->data);
      }
    }

    emxArray->data = (real_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

static void CameraCalImageCa_emxInit_char_T(emxArray_char_T_CameraCalImag_T
  **pEmxArray, int32_T numDimensions)
{
  emxArray_char_T_CameraCalImag_T *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_char_T_CameraCalImag_T *)malloc(sizeof
    (emxArray_char_T_CameraCalImag_T));
  emxArray = *pEmxArray;
  emxArray->data = (char_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)malloc(sizeof(int32_T) * (uint32_T)numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

static void Camera_emxEnsureCapacity_char_T(emxArray_char_T_CameraCalImag_T
  *emxArray, int32_T oldNumel)
{
  int32_T i;
  int32_T newNumel;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }

  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }

  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }

    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i <<= 1;
      }
    }

    newData = calloc((uint32_T)i, sizeof(char_T));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(char_T) * (uint32_T)oldNumel);
      if (emxArray->canFreeData) {
        free(emxArray->data);
      }
    }

    emxArray->data = (char_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

static void CameraCalImageCa_emxFree_char_T(emxArray_char_T_CameraCalImag_T
  **pEmxArray)
{
  if (*pEmxArray != (emxArray_char_T_CameraCalImag_T *)NULL) {
    if (((*pEmxArray)->data != (char_T *)NULL) && (*pEmxArray)->canFreeData) {
      free((*pEmxArray)->data);
    }

    free((*pEmxArray)->size);
    free(*pEmxArray);
    *pEmxArray = (emxArray_char_T_CameraCalImag_T *)NULL;
  }
}

static void emxEnsureCapacity_c_images_geot(emxArray_c_images_geotrans_in_T
  *emxArray, int32_T oldNumel)
{
  int32_T i;
  int32_T newNumel;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }

  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }

  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }

    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i <<= 1;
      }
    }

    newData = calloc((uint32_T)i, sizeof(c_images_geotrans_internal_ri_T));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(c_images_geotrans_internal_ri_T)
             * (uint32_T)oldNumel);
      if (emxArray->canFreeData) {
        free(emxArray->data);
      }
    }

    emxArray->data = (c_images_geotrans_internal_ri_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

/* Function for MATLAB Function: '<Root>/MATLAB Function' */
static real_T CameraCalImageCapture_det(const real_T x[9])
{
  real_T A[9];
  real_T y;
  int32_T b_ix;
  int32_T c_k;
  int32_T ijA;
  int32_T j;
  int8_T ipiv[3];
  boolean_T isodd;
  memcpy(&A[0], &x[0], 9U * sizeof(real_T));
  ipiv[0] = 1;
  ipiv[1] = 2;
  for (j = 0; j < 2; j++) {
    real_T smax;
    int32_T ix;
    int32_T iy;
    int32_T jj;
    jj = j << 2;
    iy = 3 - j;
    b_ix = 0;
    ix = jj;
    smax = fabs(A[jj]);
    for (c_k = 2; c_k <= iy; c_k++) {
      real_T s;
      ix++;
      s = fabs(A[ix]);
      if (s > smax) {
        b_ix = c_k - 1;
        smax = s;
      }
    }

    if (A[jj + b_ix] != 0.0) {
      if (b_ix != 0) {
        iy = j + b_ix;
        ipiv[j] = (int8_T)(iy + 1);
        smax = A[j];
        A[j] = A[iy];
        A[iy] = smax;
        smax = A[j + 3];
        A[j + 3] = A[iy + 3];
        A[iy + 3] = smax;
        smax = A[j + 6];
        A[j + 6] = A[iy + 6];
        A[iy + 6] = smax;
      }

      iy = (jj - j) + 3;
      ix = (((((iy - jj) - 1) / 2) << 1) + jj) + 2;
      c_k = ix - 2;
      for (b_ix = jj + 2; b_ix <= c_k; b_ix += 2) {
        __m128d tmp;
        tmp = _mm_loadu_pd(&A[b_ix - 1]);
        _mm_storeu_pd(&A[b_ix - 1], _mm_div_pd(tmp, _mm_set1_pd(A[jj])));
      }

      for (b_ix = ix; b_ix <= iy; b_ix++) {
        A[b_ix - 1] /= A[jj];
      }
    }

    iy = jj + 3;
    b_ix = jj + 5;
    ix = 1 - j;
    for (c_k = 0; c_k <= ix; c_k++) {
      smax = A[iy];
      if (A[iy] != 0.0) {
        int32_T d;
        d = (b_ix - j) + 1;
        for (ijA = b_ix; ijA <= d; ijA++) {
          A[ijA - 1] += A[((jj + ijA) - b_ix) + 1] * -smax;
        }
      }

      iy += 3;
      b_ix += 3;
    }
  }

  isodd = (ipiv[0] > 1);
  y = A[0] * A[4] * A[8];
  if (ipiv[1] > 2) {
    isodd = !isodd;
  }

  if (isodd) {
    y = -y;
  }

  return y;
}

/* Function for MATLAB Function: '<Root>/MATLAB Function' */
static real_T CameraCalImageCapture_xnrm2(int32_T n, const real_T x[9], int32_T
  ix0)
{
  real_T scale;
  real_T y;
  int32_T k;
  int32_T kend;
  y = 0.0;
  scale = 3.3121686421112381E-170;
  kend = (ix0 + n) - 1;
  for (k = ix0; k <= kend; k++) {
    real_T absxk;
    absxk = fabs(x[k - 1]);
    if (absxk > scale) {
      real_T t;
      t = scale / absxk;
      y = y * t * t + 1.0;
      scale = absxk;
    } else {
      real_T t;
      t = absxk / scale;
      y += t * t;
    }
  }

  return scale * sqrt(y);
}

/* Function for MATLAB Function: '<Root>/MATLAB Function' */
static real_T CameraCalImageCapture_xdotc(int32_T n, const real_T x[9], int32_T
  ix0, const real_T y[9], int32_T iy0)
{
  real_T d;
  int32_T b;
  int32_T k;
  d = 0.0;
  b = (uint8_T)n;
  for (k = 0; k < b; k++) {
    d += x[(ix0 + k) - 1] * y[(iy0 + k) - 1];
  }

  return d;
}

/* Function for MATLAB Function: '<Root>/MATLAB Function' */
static void CameraCalImageCapture_xaxpy(int32_T n, real_T a, int32_T ix0, real_T
  y[9], int32_T iy0)
{
  int32_T k;
  if (!(a == 0.0)) {
    for (k = 0; k < n; k++) {
      int32_T tmp;
      tmp = (iy0 + k) - 1;
      y[tmp] += y[(ix0 + k) - 1] * a;
    }
  }
}

/* Function for MATLAB Function: '<Root>/MATLAB Function' */
static real_T CameraCalImageCapture_xnrm2_m(const real_T x[3], int32_T ix0)
{
  real_T scale;
  real_T y;
  int32_T k;
  y = 0.0;
  scale = 3.3121686421112381E-170;
  for (k = ix0; k <= ix0 + 1; k++) {
    real_T absxk;
    absxk = fabs(x[k - 1]);
    if (absxk > scale) {
      real_T t;
      t = scale / absxk;
      y = y * t * t + 1.0;
      scale = absxk;
    } else {
      real_T t;
      t = absxk / scale;
      y += t * t;
    }
  }

  return scale * sqrt(y);
}

/* Function for MATLAB Function: '<Root>/MATLAB Function' */
static void CameraCalImageCapture_xaxpy_g(int32_T n, real_T a, const real_T x[9],
  int32_T ix0, real_T y[3], int32_T iy0)
{
  int32_T k;
  if (!(a == 0.0)) {
    int32_T scalarLB;
    int32_T tmp_0;
    int32_T vectorUB;
    scalarLB = (n / 2) << 1;
    vectorUB = scalarLB - 2;
    for (k = 0; k <= vectorUB; k += 2) {
      __m128d tmp;
      tmp_0 = (iy0 + k) - 1;
      tmp = _mm_loadu_pd(&y[tmp_0]);
      _mm_storeu_pd(&y[tmp_0], _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&x[(ix0 + k) -
        1]), _mm_set1_pd(a)), tmp));
    }

    for (k = scalarLB; k < n; k++) {
      tmp_0 = (iy0 + k) - 1;
      y[tmp_0] += x[(ix0 + k) - 1] * a;
    }
  }
}

/* Function for MATLAB Function: '<Root>/MATLAB Function' */
static void CameraCalImageCapture_xaxpy_gk(int32_T n, real_T a, const real_T x[3],
  int32_T ix0, real_T y[9], int32_T iy0)
{
  int32_T k;
  if (!(a == 0.0)) {
    int32_T scalarLB;
    int32_T tmp_0;
    int32_T vectorUB;
    scalarLB = (n / 2) << 1;
    vectorUB = scalarLB - 2;
    for (k = 0; k <= vectorUB; k += 2) {
      __m128d tmp;
      tmp_0 = (iy0 + k) - 1;
      tmp = _mm_loadu_pd(&y[tmp_0]);
      _mm_storeu_pd(&y[tmp_0], _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&x[(ix0 + k) -
        1]), _mm_set1_pd(a)), tmp));
    }

    for (k = scalarLB; k < n; k++) {
      tmp_0 = (iy0 + k) - 1;
      y[tmp_0] += x[(ix0 + k) - 1] * a;
    }
  }
}

/* Function for MATLAB Function: '<Root>/MATLAB Function' */
static void CameraCalImageCapture_xswap(real_T x[9], int32_T ix0, int32_T iy0)
{
  real_T temp;
  temp = x[ix0 - 1];
  x[ix0 - 1] = x[iy0 - 1];
  x[iy0 - 1] = temp;
  temp = x[ix0];
  x[ix0] = x[iy0];
  x[iy0] = temp;
  temp = x[ix0 + 1];
  x[ix0 + 1] = x[iy0 + 1];
  x[iy0 + 1] = temp;
}

/* Function for MATLAB Function: '<Root>/MATLAB Function' */
static void CameraCalImageCapture_xrotg(real_T *a, real_T *b, real_T *c, real_T *
  s)
{
  real_T absa;
  real_T absb;
  real_T roe;
  real_T scale;
  roe = *b;
  absa = fabs(*a);
  absb = fabs(*b);
  if (absa > absb) {
    roe = *a;
  }

  scale = absa + absb;
  if (scale == 0.0) {
    *s = 0.0;
    *c = 1.0;
    *a = 0.0;
    *b = 0.0;
  } else {
    real_T ads;
    real_T bds;
    ads = absa / scale;
    bds = absb / scale;
    scale *= sqrt(ads * ads + bds * bds);
    if (roe < 0.0) {
      scale = -scale;
    }

    *c = *a / scale;
    *s = *b / scale;
    if (absa > absb) {
      *b = *s;
    } else if (*c != 0.0) {
      *b = 1.0 / *c;
    } else {
      *b = 1.0;
    }

    *a = scale;
  }
}

/* Function for MATLAB Function: '<Root>/MATLAB Function' */
static void CameraCalImageCapture_xrot(real_T x[9], int32_T ix0, int32_T iy0,
  real_T c, real_T s)
{
  real_T temp;
  real_T temp_tmp;
  temp = x[iy0 - 1];
  temp_tmp = x[ix0 - 1];
  x[iy0 - 1] = temp * c - temp_tmp * s;
  x[ix0 - 1] = temp_tmp * c + temp * s;
  temp = x[ix0] * c + x[iy0] * s;
  x[iy0] = x[iy0] * c - x[ix0] * s;
  x[ix0] = temp;
  temp = x[iy0 + 1];
  temp_tmp = x[ix0 + 1];
  x[iy0 + 1] = temp * c - temp_tmp * s;
  x[ix0 + 1] = temp_tmp * c + temp * s;
}

/* Function for MATLAB Function: '<Root>/MATLAB Function' */
static void CameraCalImageCapture_svd(const real_T A[9], real_T U[9], real_T s[3],
  real_T V[9])
{
  __m128d tmp;
  real_T b_A[9];
  real_T b_s[3];
  real_T e[3];
  real_T work[3];
  real_T nrm;
  real_T rt;
  real_T smm1;
  real_T sqds;
  real_T ztest;
  int32_T kase;
  int32_T m;
  int32_T qjj;
  int32_T qp1;
  int32_T qq;
  int32_T scalarLB;
  b_s[0] = 0.0;
  e[0] = 0.0;
  work[0] = 0.0;
  b_s[1] = 0.0;
  e[1] = 0.0;
  work[1] = 0.0;
  b_s[2] = 0.0;
  e[2] = 0.0;
  work[2] = 0.0;
  for (m = 0; m < 9; m++) {
    b_A[m] = A[m];
    U[m] = 0.0;
    V[m] = 0.0;
  }

  for (m = 0; m < 2; m++) {
    int32_T vectorUB;
    boolean_T apply_transform;
    qp1 = m + 2;
    qq = (3 * m + m) + 1;
    apply_transform = false;
    nrm = CameraCalImageCapture_xnrm2(3 - m, b_A, qq);
    if (nrm > 0.0) {
      apply_transform = true;
      if (b_A[qq - 1] < 0.0) {
        b_s[m] = -nrm;
      } else {
        b_s[m] = nrm;
      }

      if (fabs(b_s[m]) >= 1.0020841800044864E-292) {
        nrm = 1.0 / b_s[m];
        qjj = (qq - m) + 2;
        scalarLB = ((((qjj - qq) + 1) / 2) << 1) + qq;
        vectorUB = scalarLB - 2;
        for (kase = qq; kase <= vectorUB; kase += 2) {
          tmp = _mm_loadu_pd(&b_A[kase - 1]);
          _mm_storeu_pd(&b_A[kase - 1], _mm_mul_pd(tmp, _mm_set1_pd(nrm)));
        }

        for (kase = scalarLB; kase <= qjj; kase++) {
          b_A[kase - 1] *= nrm;
        }
      } else {
        qjj = (qq - m) + 2;
        scalarLB = ((((qjj - qq) + 1) / 2) << 1) + qq;
        vectorUB = scalarLB - 2;
        for (kase = qq; kase <= vectorUB; kase += 2) {
          tmp = _mm_loadu_pd(&b_A[kase - 1]);
          _mm_storeu_pd(&b_A[kase - 1], _mm_div_pd(tmp, _mm_set1_pd(b_s[m])));
        }

        for (kase = scalarLB; kase <= qjj; kase++) {
          b_A[kase - 1] /= b_s[m];
        }
      }

      b_A[qq - 1]++;
      b_s[m] = -b_s[m];
    } else {
      b_s[m] = 0.0;
    }

    for (kase = qp1; kase < 4; kase++) {
      qjj = (kase - 1) * 3 + m;
      if (apply_transform) {
        CameraCalImageCapture_xaxpy(3 - m, -(CameraCalImageCapture_xdotc(3 - m,
          b_A, qq, b_A, qjj + 1) / b_A[m + 3 * m]), qq, b_A, qjj + 1);
      }

      e[kase - 1] = b_A[qjj];
    }

    for (qq = m + 1; qq < 4; qq++) {
      kase = (3 * m + qq) - 1;
      U[kase] = b_A[kase];
    }

    if (m + 1 <= 1) {
      nrm = CameraCalImageCapture_xnrm2_m(e, 2);
      if (nrm == 0.0) {
        e[0] = 0.0;
      } else {
        if (e[1] < 0.0) {
          e[0] = -nrm;
        } else {
          e[0] = nrm;
        }

        nrm = e[0];
        if (fabs(e[0]) >= 1.0020841800044864E-292) {
          nrm = 1.0 / e[0];
          scalarLB = ((((2 - m) / 2) << 1) + m) + 2;
          vectorUB = scalarLB - 2;
          for (qq = qp1; qq <= vectorUB; qq += 2) {
            tmp = _mm_loadu_pd(&e[qq - 1]);
            _mm_storeu_pd(&e[qq - 1], _mm_mul_pd(tmp, _mm_set1_pd(nrm)));
          }

          for (qq = scalarLB; qq < 4; qq++) {
            e[qq - 1] *= nrm;
          }
        } else {
          scalarLB = ((((2 - m) / 2) << 1) + m) + 2;
          vectorUB = scalarLB - 2;
          for (qq = qp1; qq <= vectorUB; qq += 2) {
            tmp = _mm_loadu_pd(&e[qq - 1]);
            _mm_storeu_pd(&e[qq - 1], _mm_div_pd(tmp, _mm_set1_pd(nrm)));
          }

          for (qq = scalarLB; qq < 4; qq++) {
            e[qq - 1] /= nrm;
          }
        }

        e[1]++;
        e[0] = -e[0];
        for (qq = qp1; qq < 4; qq++) {
          work[qq - 1] = 0.0;
        }

        for (qq = qp1; qq < 4; qq++) {
          CameraCalImageCapture_xaxpy_g(2, e[qq - 1], b_A, 3 * (qq - 1) + 2,
            work, 2);
        }

        for (qq = qp1; qq < 4; qq++) {
          CameraCalImageCapture_xaxpy_gk(2, -e[qq - 1] / e[1], work, 2, b_A, 3 *
            (qq - 1) + 2);
        }
      }

      for (qq = qp1; qq < 4; qq++) {
        V[qq - 1] = e[qq - 1];
      }
    }
  }

  m = 1;
  b_s[2] = b_A[8];
  e[1] = b_A[7];
  e[2] = 0.0;
  U[6] = 0.0;
  U[7] = 0.0;
  U[8] = 1.0;
  for (qp1 = 1; qp1 >= 0; qp1--) {
    qq = 3 * qp1 + qp1;
    if (b_s[qp1] != 0.0) {
      for (kase = qp1 + 2; kase < 4; kase++) {
        qjj = ((kase - 1) * 3 + qp1) + 1;
        CameraCalImageCapture_xaxpy(3 - qp1, -(CameraCalImageCapture_xdotc(3 -
          qp1, U, qq + 1, U, qjj) / U[qq]), qq + 1, U, qjj);
      }

      for (qjj = qp1 + 1; qjj < 4; qjj++) {
        kase = (3 * qp1 + qjj) - 1;
        U[kase] = -U[kase];
      }

      U[qq]++;
      if (qp1 - 1 >= 0) {
        U[3 * qp1] = 0.0;
      }
    } else {
      U[3 * qp1] = 0.0;
      U[3 * qp1 + 1] = 0.0;
      U[3 * qp1 + 2] = 0.0;
      U[qq] = 1.0;
    }
  }

  for (qp1 = 2; qp1 >= 0; qp1--) {
    if ((qp1 + 1 <= 1) && (e[0] != 0.0)) {
      CameraCalImageCapture_xaxpy(2, -(CameraCalImageCapture_xdotc(2, V, 2, V, 5)
        / V[1]), 2, V, 5);
      CameraCalImageCapture_xaxpy(2, -(CameraCalImageCapture_xdotc(2, V, 2, V, 8)
        / V[1]), 2, V, 8);
    }

    V[3 * qp1] = 0.0;
    V[3 * qp1 + 1] = 0.0;
    V[3 * qp1 + 2] = 0.0;
    V[qp1 + 3 * qp1] = 1.0;
  }

  for (qp1 = 0; qp1 < 3; qp1++) {
    smm1 = e[qp1];
    if (b_s[qp1] != 0.0) {
      rt = fabs(b_s[qp1]);
      nrm = b_s[qp1] / rt;
      b_s[qp1] = rt;
      if (qp1 + 1 < 3) {
        smm1 /= nrm;
      }

      qq = 3 * qp1 + 1;
      scalarLB = 2 + qq;
      for (qjj = qq; qjj <= qq; qjj += 2) {
        tmp = _mm_loadu_pd(&U[qjj - 1]);
        _mm_storeu_pd(&U[qjj - 1], _mm_mul_pd(tmp, _mm_set1_pd(nrm)));
      }

      for (qjj = scalarLB; qjj <= qq + 2; qjj++) {
        U[qjj - 1] *= nrm;
      }
    }

    if ((qp1 + 1 < 3) && (smm1 != 0.0)) {
      rt = fabs(smm1);
      nrm = rt / smm1;
      smm1 = rt;
      b_s[qp1 + 1] *= nrm;
      qq = (qp1 + 1) * 3 + 1;
      scalarLB = 2 + qq;
      for (qjj = qq; qjj <= qq; qjj += 2) {
        tmp = _mm_loadu_pd(&V[qjj - 1]);
        _mm_storeu_pd(&V[qjj - 1], _mm_mul_pd(tmp, _mm_set1_pd(nrm)));
      }

      for (qjj = scalarLB; qjj <= qq + 2; qjj++) {
        V[qjj - 1] *= nrm;
      }
    }

    e[qp1] = smm1;
  }

  qp1 = 0;
  nrm = fmax(fmax(fmax(0.0, fmax(fabs(b_s[0]), fabs(e[0]))), fmax(fabs(b_s[1]),
    fabs(e[1]))), fmax(fabs(b_s[2]), fabs(e[2])));
  while ((m + 2 > 0) && (qp1 < 75)) {
    kase = m + 1;
    int32_T exitg1;
    do {
      exitg1 = 0;
      qq = kase;
      if (kase == 0) {
        exitg1 = 1;
      } else {
        rt = fabs(e[kase - 1]);
        if ((rt <= (fabs(b_s[kase - 1]) + fabs(b_s[kase])) *
             2.2204460492503131E-16) || ((rt <= 1.0020841800044864E-292) ||
             ((qp1 > 20) && (rt <= 2.2204460492503131E-16 * nrm)))) {
          e[kase - 1] = 0.0;
          exitg1 = 1;
        } else {
          kase--;
        }
      }
    } while (exitg1 == 0);

    if (m + 1 == kase) {
      kase = 4;
    } else {
      boolean_T exitg2;
      qjj = m + 2;
      scalarLB = m + 2;
      exitg2 = false;
      while ((!exitg2) && (scalarLB >= kase)) {
        qjj = scalarLB;
        if (scalarLB == kase) {
          exitg2 = true;
        } else {
          rt = 0.0;
          if (scalarLB < m + 2) {
            rt = fabs(e[scalarLB - 1]);
          }

          if (scalarLB > kase + 1) {
            rt += fabs(e[scalarLB - 2]);
          }

          ztest = fabs(b_s[scalarLB - 1]);
          if ((ztest <= 2.2204460492503131E-16 * rt) || (ztest <=
               1.0020841800044864E-292)) {
            b_s[scalarLB - 1] = 0.0;
            exitg2 = true;
          } else {
            scalarLB--;
          }
        }
      }

      if (qjj == kase) {
        kase = 3;
      } else if (m + 2 == qjj) {
        kase = 1;
      } else {
        kase = 2;
        qq = qjj;
      }
    }

    switch (kase) {
     case 1:
      rt = e[m];
      e[m] = 0.0;
      for (qjj = m + 1; qjj >= qq + 1; qjj--) {
        smm1 = e[0];
        CameraCalImageCapture_xrotg(&b_s[qjj - 1], &rt, &ztest, &sqds);
        if (qjj > qq + 1) {
          rt = -sqds * e[0];
          smm1 = e[0] * ztest;
        }

        CameraCalImageCapture_xrot(V, 3 * (qjj - 1) + 1, 3 * (m + 1) + 1, ztest,
          sqds);
        e[0] = smm1;
      }
      break;

     case 2:
      {
        rt = e[qq - 1];
        e[qq - 1] = 0.0;
        for (qjj = qq + 1; qjj <= m + 2; qjj++) {
          real_T emm1;
          CameraCalImageCapture_xrotg(&b_s[qjj - 1], &rt, &ztest, &sqds);
          emm1 = e[qjj - 1];
          rt = emm1 * -sqds;
          e[qjj - 1] = emm1 * ztest;
          CameraCalImageCapture_xrot(U, 3 * (qjj - 1) + 1, 3 * (qq - 1) + 1,
            ztest, sqds);
        }
      }
      break;

     case 3:
      {
        real_T emm1;
        real_T shift;
        sqds = b_s[m + 1];
        ztest = fmax(fmax(fmax(fmax(fabs(sqds), fabs(b_s[m])), fabs(e[m])), fabs
                          (b_s[qq])), fabs(e[qq]));
        rt = sqds / ztest;
        smm1 = b_s[m] / ztest;
        emm1 = e[m] / ztest;
        sqds = b_s[qq] / ztest;
        smm1 = ((smm1 + rt) * (smm1 - rt) + emm1 * emm1) / 2.0;
        emm1 *= rt;
        emm1 *= emm1;
        if ((smm1 != 0.0) || (emm1 != 0.0)) {
          shift = sqrt(smm1 * smm1 + emm1);
          if (smm1 < 0.0) {
            shift = -shift;
          }

          shift = emm1 / (smm1 + shift);
        } else {
          shift = 0.0;
        }

        rt = (sqds + rt) * (sqds - rt) + shift;
        ztest = e[qq] / ztest * sqds;
        for (qjj = qq + 1; qjj <= m + 1; qjj++) {
          CameraCalImageCapture_xrotg(&rt, &ztest, &sqds, &smm1);
          if (qjj > qq + 1) {
            e[0] = rt;
          }

          emm1 = e[qjj - 1];
          rt = b_s[qjj - 1];
          e[qjj - 1] = emm1 * sqds - rt * smm1;
          ztest = smm1 * b_s[qjj];
          b_s[qjj] *= sqds;
          CameraCalImageCapture_xrot(V, 3 * (qjj - 1) + 1, 3 * qjj + 1, sqds,
            smm1);
          b_s[qjj - 1] = rt * sqds + emm1 * smm1;
          CameraCalImageCapture_xrotg(&b_s[qjj - 1], &ztest, &sqds, &smm1);
          rt = e[qjj - 1] * sqds + smm1 * b_s[qjj];
          b_s[qjj] = e[qjj - 1] * -smm1 + sqds * b_s[qjj];
          ztest = smm1 * e[qjj];
          e[qjj] *= sqds;
          CameraCalImageCapture_xrot(U, 3 * (qjj - 1) + 1, 3 * qjj + 1, sqds,
            smm1);
        }

        e[m] = rt;
        qp1++;
      }
      break;

     default:
      if (b_s[qq] < 0.0) {
        b_s[qq] = -b_s[qq];
        qp1 = 3 * qq + 1;
        scalarLB = 2 + qp1;
        for (qjj = qp1; qjj <= qp1; qjj += 2) {
          tmp = _mm_loadu_pd(&V[qjj - 1]);
          _mm_storeu_pd(&V[qjj - 1], _mm_mul_pd(tmp, _mm_set1_pd(-1.0)));
        }

        for (qjj = scalarLB; qjj <= qp1 + 2; qjj++) {
          V[qjj - 1] = -V[qjj - 1];
        }
      }

      qp1 = qq + 1;
      while ((qq + 1 < 3) && (b_s[qq] < b_s[qp1])) {
        rt = b_s[qq];
        b_s[qq] = b_s[qp1];
        b_s[qp1] = rt;
        CameraCalImageCapture_xswap(V, 3 * qq + 1, 3 * (qq + 1) + 1);
        CameraCalImageCapture_xswap(U, 3 * qq + 1, 3 * (qq + 1) + 1);
        qq = qp1;
        qp1++;
      }

      qp1 = 0;
      m--;
      break;
    }
  }

  s[0] = b_s[0];
  s[1] = b_s[1];
  s[2] = b_s[2];
}

/* Function for MATLAB Function: '<Root>/MATLAB Function' */
static void CameraCalImageCapture_svd_d(const real_T A[9], real_T U[3])
{
  real_T b_A[9];
  real_T e[3];
  real_T s[3];
  real_T work[3];
  real_T nrm;
  real_T rt;
  real_T smm1;
  real_T sqds;
  real_T ztest;
  int32_T c_ix;
  int32_T ix;
  int32_T m;
  int32_T qjj;
  int32_T qp1;
  int32_T qq;
  int32_T scalarLB;
  memcpy(&b_A[0], &A[0], 9U * sizeof(real_T));
  s[0] = 0.0;
  e[0] = 0.0;
  work[0] = 0.0;
  s[1] = 0.0;
  e[1] = 0.0;
  work[1] = 0.0;
  s[2] = 0.0;
  e[2] = 0.0;
  work[2] = 0.0;
  for (m = 0; m < 2; m++) {
    __m128d tmp;
    int32_T vectorUB;
    boolean_T apply_transform;
    qp1 = m + 2;
    ix = 3 * m + m;
    qq = ix + 1;
    apply_transform = false;
    nrm = CameraCalImageCapture_xnrm2(3 - m, b_A, ix + 1);
    if (nrm > 0.0) {
      apply_transform = true;
      if (b_A[ix] < 0.0) {
        s[m] = -nrm;
      } else {
        s[m] = nrm;
      }

      if (fabs(s[m]) >= 1.0020841800044864E-292) {
        nrm = 1.0 / s[m];
        c_ix = (ix - m) + 3;
        scalarLB = ((((c_ix - ix) / 2) << 1) + ix) + 1;
        vectorUB = scalarLB - 2;
        for (qjj = qq; qjj <= vectorUB; qjj += 2) {
          tmp = _mm_loadu_pd(&b_A[qjj - 1]);
          _mm_storeu_pd(&b_A[qjj - 1], _mm_mul_pd(tmp, _mm_set1_pd(nrm)));
        }

        for (qjj = scalarLB; qjj <= c_ix; qjj++) {
          b_A[qjj - 1] *= nrm;
        }
      } else {
        c_ix = (ix - m) + 3;
        scalarLB = ((((c_ix - ix) / 2) << 1) + ix) + 1;
        vectorUB = scalarLB - 2;
        for (qjj = qq; qjj <= vectorUB; qjj += 2) {
          tmp = _mm_loadu_pd(&b_A[qjj - 1]);
          _mm_storeu_pd(&b_A[qjj - 1], _mm_div_pd(tmp, _mm_set1_pd(s[m])));
        }

        for (qjj = scalarLB; qjj <= c_ix; qjj++) {
          b_A[qjj - 1] /= s[m];
        }
      }

      b_A[ix]++;
      s[m] = -s[m];
    } else {
      s[m] = 0.0;
    }

    for (c_ix = qp1; c_ix < 4; c_ix++) {
      qjj = (c_ix - 1) * 3 + m;
      if (apply_transform) {
        nrm = 0.0;
        qq = 3 - m;
        for (scalarLB = 0; scalarLB < qq; scalarLB++) {
          nrm += b_A[ix + scalarLB] * b_A[qjj + scalarLB];
        }

        nrm = -(nrm / b_A[ix]);
        if (!(nrm == 0.0)) {
          qq = 3 - m;
          for (scalarLB = 0; scalarLB < qq; scalarLB++) {
            vectorUB = qjj + scalarLB;
            b_A[vectorUB] += b_A[ix + scalarLB] * nrm;
          }
        }
      }

      e[c_ix - 1] = b_A[qjj];
    }

    if (m + 1 <= 1) {
      nrm = CameraCalImageCapture_xnrm2_m(e, 2);
      if (nrm == 0.0) {
        e[0] = 0.0;
      } else {
        if (e[1] < 0.0) {
          e[0] = -nrm;
        } else {
          e[0] = nrm;
        }

        nrm = e[0];
        if (fabs(e[0]) >= 1.0020841800044864E-292) {
          nrm = 1.0 / e[0];
          scalarLB = ((((2 - m) / 2) << 1) + m) + 2;
          vectorUB = scalarLB - 2;
          for (qq = qp1; qq <= vectorUB; qq += 2) {
            tmp = _mm_loadu_pd(&e[qq - 1]);
            _mm_storeu_pd(&e[qq - 1], _mm_mul_pd(tmp, _mm_set1_pd(nrm)));
          }

          for (qq = scalarLB; qq < 4; qq++) {
            e[qq - 1] *= nrm;
          }
        } else {
          scalarLB = ((((2 - m) / 2) << 1) + m) + 2;
          vectorUB = scalarLB - 2;
          for (qq = qp1; qq <= vectorUB; qq += 2) {
            tmp = _mm_loadu_pd(&e[qq - 1]);
            _mm_storeu_pd(&e[qq - 1], _mm_div_pd(tmp, _mm_set1_pd(nrm)));
          }

          for (qq = scalarLB; qq < 4; qq++) {
            e[qq - 1] /= nrm;
          }
        }

        e[1]++;
        e[0] = -e[0];
        for (qq = qp1; qq < 4; qq++) {
          work[qq - 1] = 0.0;
        }

        for (qq = qp1; qq < 4; qq++) {
          nrm = e[qq - 1];
          if (!(nrm == 0.0)) {
            c_ix = (qq - 1) * 3 + 1;
            work[1] += nrm * b_A[c_ix];
            work[2] += b_A[c_ix + 1] * nrm;
          }
        }

        for (qq = qp1; qq < 4; qq++) {
          CameraCalImageCapture_xaxpy_gk(2, -e[qq - 1] / e[1], work, 2, b_A, 3 *
            (qq - 1) + 2);
        }
      }
    }
  }

  m = 1;
  s[2] = b_A[8];
  smm1 = e[0];
  if (s[0] != 0.0) {
    rt = fabs(s[0]);
    nrm = s[0] / rt;
    s[0] = rt;
    smm1 = e[0] / nrm;
  }

  if (smm1 != 0.0) {
    rt = fabs(smm1);
    nrm = rt / smm1;
    smm1 = rt;
    s[1] *= nrm;
  }

  e[0] = smm1;
  smm1 = b_A[7];
  if (s[1] != 0.0) {
    rt = fabs(s[1]);
    nrm = s[1] / rt;
    s[1] = rt;
    smm1 = b_A[7] / nrm;
  }

  if (smm1 != 0.0) {
    rt = fabs(smm1);
    nrm = rt / smm1;
    smm1 = rt;
    s[2] = b_A[8] * nrm;
  }

  e[1] = smm1;
  if (s[2] != 0.0) {
    s[2] = fabs(s[2]);
  }

  e[2] = 0.0;
  qp1 = 0;
  nrm = fmax(fmax(fmax(s[0], e[0]), fmax(s[1], smm1)), fmax(s[2], 0.0));
  while ((m + 2 > 0) && (qp1 < 75)) {
    qjj = m + 1;
    int32_T exitg1;
    do {
      exitg1 = 0;
      qq = qjj;
      if (qjj == 0) {
        exitg1 = 1;
      } else {
        rt = fabs(e[qjj - 1]);
        if ((rt <= (fabs(s[qjj - 1]) + fabs(s[qjj])) * 2.2204460492503131E-16) ||
            ((rt <= 1.0020841800044864E-292) || ((qp1 > 20) && (rt <=
               2.2204460492503131E-16 * nrm)))) {
          e[qjj - 1] = 0.0;
          exitg1 = 1;
        } else {
          qjj--;
        }
      }
    } while (exitg1 == 0);

    if (m + 1 == qjj) {
      qjj = 4;
    } else {
      boolean_T exitg2;
      c_ix = m + 2;
      ix = m + 2;
      exitg2 = false;
      while ((!exitg2) && (ix >= qjj)) {
        c_ix = ix;
        if (ix == qjj) {
          exitg2 = true;
        } else {
          rt = 0.0;
          if (ix < m + 2) {
            rt = fabs(e[ix - 1]);
          }

          if (ix > qjj + 1) {
            rt += fabs(e[ix - 2]);
          }

          ztest = fabs(s[ix - 1]);
          if ((ztest <= 2.2204460492503131E-16 * rt) || (ztest <=
               1.0020841800044864E-292)) {
            s[ix - 1] = 0.0;
            exitg2 = true;
          } else {
            ix--;
          }
        }
      }

      if (c_ix == qjj) {
        qjj = 3;
      } else if (m + 2 == c_ix) {
        qjj = 1;
      } else {
        qjj = 2;
        qq = c_ix;
      }
    }

    switch (qjj) {
     case 1:
      rt = e[m];
      e[m] = 0.0;
      for (c_ix = m + 1; c_ix >= qq + 1; c_ix--) {
        smm1 = e[0];
        CameraCalImageCapture_xrotg(&s[c_ix - 1], &rt, &ztest, &sqds);
        if (c_ix > qq + 1) {
          rt = -sqds * e[0];
          smm1 = e[0] * ztest;
        }

        e[0] = smm1;
      }
      break;

     case 2:
      {
        rt = e[qq - 1];
        e[qq - 1] = 0.0;
        for (c_ix = qq + 1; c_ix <= m + 2; c_ix++) {
          real_T emm1;
          CameraCalImageCapture_xrotg(&s[c_ix - 1], &rt, &ztest, &sqds);
          emm1 = e[c_ix - 1];
          rt = emm1 * -sqds;
          e[c_ix - 1] = emm1 * ztest;
        }
      }
      break;

     case 3:
      {
        real_T emm1;
        real_T shift;
        sqds = s[m + 1];
        ztest = fmax(fmax(fmax(fmax(fabs(sqds), fabs(s[m])), fabs(e[m])), fabs
                          (s[qq])), fabs(e[qq]));
        rt = sqds / ztest;
        smm1 = s[m] / ztest;
        emm1 = e[m] / ztest;
        sqds = s[qq] / ztest;
        smm1 = ((smm1 + rt) * (smm1 - rt) + emm1 * emm1) / 2.0;
        emm1 *= rt;
        emm1 *= emm1;
        if ((smm1 != 0.0) || (emm1 != 0.0)) {
          shift = sqrt(smm1 * smm1 + emm1);
          if (smm1 < 0.0) {
            shift = -shift;
          }

          shift = emm1 / (smm1 + shift);
        } else {
          shift = 0.0;
        }

        rt = (sqds + rt) * (sqds - rt) + shift;
        ztest = e[qq] / ztest * sqds;
        for (c_ix = qq + 1; c_ix <= m + 1; c_ix++) {
          CameraCalImageCapture_xrotg(&rt, &ztest, &sqds, &smm1);
          if (c_ix > qq + 1) {
            e[0] = rt;
          }

          emm1 = e[c_ix - 1];
          rt = s[c_ix - 1];
          e[c_ix - 1] = emm1 * sqds - rt * smm1;
          ztest = smm1 * s[c_ix];
          s[c_ix] *= sqds;
          s[c_ix - 1] = rt * sqds + emm1 * smm1;
          CameraCalImageCapture_xrotg(&s[c_ix - 1], &ztest, &sqds, &smm1);
          rt = e[c_ix - 1] * sqds + smm1 * s[c_ix];
          s[c_ix] = e[c_ix - 1] * -smm1 + sqds * s[c_ix];
          ztest = smm1 * e[c_ix];
          e[c_ix] *= sqds;
        }

        e[m] = rt;
        qp1++;
      }
      break;

     default:
      if (s[qq] < 0.0) {
        s[qq] = -s[qq];
      }

      qp1 = qq + 1;
      while ((qq + 1 < 3) && (s[qq] < s[qp1])) {
        rt = s[qq];
        s[qq] = s[qp1];
        s[qp1] = rt;
        qq = qp1;
        qp1++;
      }

      qp1 = 0;
      m--;
      break;
    }
  }

  U[0] = s[0];
  U[1] = s[1];
  U[2] = s[2];
}

/* Function for MATLAB Function: '<Root>/MATLAB Function' */
static real_T CameraCalImageCapture_norm(const real_T x[9])
{
  real_T tmp[3];
  real_T y;
  int32_T j;
  y = 0.0;
  for (j = 0; j < 3; j++) {
    real_T absx;
    absx = fabs(x[3 * j]);
    if (rtIsNaN(absx) || (absx > y)) {
      y = absx;
    }

    absx = fabs(x[3 * j + 1]);
    if (rtIsNaN(absx) || (absx > y)) {
      y = absx;
    }

    absx = fabs(x[3 * j + 2]);
    if (rtIsNaN(absx) || (absx > y)) {
      y = absx;
    }
  }

  if ((!rtIsInf(y)) && (!rtIsNaN(y))) {
    CameraCalImageCapture_svd_d(x, tmp);
    y = tmp[0];
  }

  return y;
}

/* Function for MATLAB Function: '<Root>/MATLAB Function' */
static void Cam_constrainToRotationMatrix3D(const real_T R[9], real_T Rc[9])
{
  real_T R_clamped[9];
  real_T b[9];
  real_T minval[9];
  real_T Rc_0[6];
  real_T s[3];
  int32_T Rc_tmp;
  int32_T Rc_tmp_0;
  int32_T k;
  for (k = 0; k < 9; k++) {
    R_clamped[k] = fmax(fmin(R[k], 1.0), -1.0);
  }

  CameraCalImageCapture_svd(R_clamped, minval, s, b);
  for (k = 0; k < 3; k++) {
    for (Rc_tmp_0 = 0; Rc_tmp_0 < 3; Rc_tmp_0++) {
      Rc_tmp = 3 * Rc_tmp_0 + k;
      Rc[Rc_tmp] = 0.0;
      Rc[Rc_tmp] += minval[k] * b[Rc_tmp_0];
      Rc[Rc_tmp] += minval[k + 3] * b[Rc_tmp_0 + 3];
      Rc[Rc_tmp] += minval[k + 6] * b[Rc_tmp_0 + 6];
    }
  }

  if (CameraCalImageCapture_det(Rc) < 0.0) {
    for (k = 0; k < 3; k++) {
      Rc_tmp = k << 1;
      Rc_tmp_0 = 3 * k + 1;
      Rc_0[Rc_tmp] = Rc[Rc_tmp_0];
      Rc_0[Rc_tmp + 1] = Rc[3 * k];
      Rc[3 * k] = Rc_0[Rc_tmp];
      Rc[Rc_tmp_0] = Rc_0[Rc_tmp + 1];
    }
  }

  for (k = 0; k <= 6; k += 2) {
    __m128d tmp;
    __m128d tmp_0;
    tmp = _mm_loadu_pd(&R_clamped[k]);
    tmp_0 = _mm_loadu_pd(&Rc[k]);
    _mm_storeu_pd(&minval[k], _mm_sub_pd(tmp, tmp_0));
  }

  for (k = 8; k < 9; k++) {
    minval[k] = R_clamped[k] - Rc[k];
  }

  if (CameraCalImageCapture_norm(minval) / 2.2204460492503131E-16 < 10.0) {
    memcpy(&Rc[0], &R_clamped[0], 9U * sizeof(real_T));
  }
}

static void emxFree_c_images_geotrans_inter(emxArray_c_images_geotrans_in_T
  **pEmxArray)
{
  if (*pEmxArray != (emxArray_c_images_geotrans_in_T *)NULL) {
    if (((*pEmxArray)->data != (c_images_geotrans_internal_ri_T *)NULL) &&
        (*pEmxArray)->canFreeData) {
      free((*pEmxArray)->data);
    }

    free((*pEmxArray)->size);
    free(*pEmxArray);
    *pEmxArray = (emxArray_c_images_geotrans_in_T *)NULL;
  }
}

static void CameraCalImageCa_emxFree_real_T(emxArray_real_T_CameraCalImag_T
  **pEmxArray)
{
  if (*pEmxArray != (emxArray_real_T_CameraCalImag_T *)NULL) {
    if (((*pEmxArray)->data != (real_T *)NULL) && (*pEmxArray)->canFreeData) {
      free((*pEmxArray)->data);
    }

    free((*pEmxArray)->size);
    free(*pEmxArray);
    *pEmxArray = (emxArray_real_T_CameraCalImag_T *)NULL;
  }
}

static void CameraCalImageC_emxInit_int32_T(emxArray_int32_T_CameraCalIma_T
  **pEmxArray, int32_T numDimensions)
{
  emxArray_int32_T_CameraCalIma_T *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_int32_T_CameraCalIma_T *)malloc(sizeof
    (emxArray_int32_T_CameraCalIma_T));
  emxArray = *pEmxArray;
  emxArray->data = (int32_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)malloc(sizeof(int32_T) * (uint32_T)numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

static void Camer_emxEnsureCapacity_int32_T(emxArray_int32_T_CameraCalIma_T
  *emxArray, int32_T oldNumel)
{
  int32_T i;
  int32_T newNumel;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }

  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }

  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }

    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i <<= 1;
      }
    }

    newData = calloc((uint32_T)i, sizeof(int32_T));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(int32_T) * (uint32_T)oldNumel);
      if (emxArray->canFreeData) {
        free(emxArray->data);
      }
    }

    emxArray->data = (int32_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

static void CameraCalImag_emxInit_boolean_T(emxArray_boolean_T_CameraCalI_T
  **pEmxArray, int32_T numDimensions)
{
  emxArray_boolean_T_CameraCalI_T *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_boolean_T_CameraCalI_T *)malloc(sizeof
    (emxArray_boolean_T_CameraCalI_T));
  emxArray = *pEmxArray;
  emxArray->data = (boolean_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)malloc(sizeof(int32_T) * (uint32_T)numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

static void Cam_emxEnsureCapacity_boolean_T(emxArray_boolean_T_CameraCalI_T
  *emxArray, int32_T oldNumel)
{
  int32_T i;
  int32_T newNumel;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }

  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }

  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }

    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i <<= 1;
      }
    }

    newData = calloc((uint32_T)i, sizeof(boolean_T));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(boolean_T) * (uint32_T)oldNumel);
      if (emxArray->canFreeData) {
        free(emxArray->data);
      }
    }

    emxArray->data = (boolean_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

static void CameraCalImageC_emxFree_int32_T(emxArray_int32_T_CameraCalIma_T
  **pEmxArray)
{
  if (*pEmxArray != (emxArray_int32_T_CameraCalIma_T *)NULL) {
    if (((*pEmxArray)->data != (int32_T *)NULL) && (*pEmxArray)->canFreeData) {
      free((*pEmxArray)->data);
    }

    free((*pEmxArray)->size);
    free(*pEmxArray);
    *pEmxArray = (emxArray_int32_T_CameraCalIma_T *)NULL;
  }
}

static void CameraCalImag_emxFree_boolean_T(emxArray_boolean_T_CameraCalI_T
  **pEmxArray)
{
  if (*pEmxArray != (emxArray_boolean_T_CameraCalI_T *)NULL) {
    if (((*pEmxArray)->data != (boolean_T *)NULL) && (*pEmxArray)->canFreeData)
    {
      free((*pEmxArray)->data);
    }

    free((*pEmxArray)->size);
    free(*pEmxArray);
    *pEmxArray = (emxArray_boolean_T_CameraCalI_T *)NULL;
  }
}

/* Function for MATLAB Function: '<Root>/MATLAB Function' */
static void CameraCalImageCapt_readAprilTag(const uint8_T b_I[307200], const
  real32_T varargin_2_FocalLength[2], const real32_T varargin_2_PrincipalPoint[2],
  emxArray_real_T_CameraCalImag_T *varargout_1, emxArray_real_T_CameraCalImag_T *
  varargout_2, real_T varargout_3_R[9], real_T varargout_3_Translation[3],
  emxArray_c_images_geotrans_in_T *varargout_3_Data)
{
  void* detectionsObj;
  void* posesObj;
  c_images_geotrans_internal_ri_T d;
  emxArray_boolean_T_CameraCalI_T *b_b;
  emxArray_c_images_geotrans_in_T *dataArray;
  emxArray_char_T_CameraCalImag_T *familyNames;
  emxArray_int32_T_CameraCalIma_T *idx_tmp;
  emxArray_real_T_CameraCalImag_T *b_varargout_1;
  emxArray_real_T_CameraCalImag_T *familyDetectionsLen;
  emxArray_real_T_CameraCalImag_T *rotMatrices;
  emxArray_real_T_CameraCalImag_T *transVectors;
  emxArray_real_T_CameraCalImag_T *x;
  real_T rotMatrices_0[9];
  real_T countValid;
  int32_T tagLength_data[2];
  int32_T detectedPosesSize;
  int32_T k0;
  int32_T loop_ub;
  int32_T nxin;
  int32_T outidx;
  real32_T focalLength[2];
  real32_T principalPoint[2];
  char_T tagFamilyProc[8];
  static const char_T m[8] = { 't', 'a', 'g', '3', '6', 'h', '1', '1' };

  static const int8_T p[9] = { 1, 0, 0, 0, 1, 0, 0, 0, 1 };

  focalLength[0] = varargin_2_FocalLength[0];
  principalPoint[0] = varargin_2_PrincipalPoint[0];
  focalLength[1] = varargin_2_FocalLength[1];
  principalPoint[1] = varargin_2_PrincipalPoint[1];
  for (k0 = 0; k0 < 480; k0++) {
    for (nxin = 0; nxin < 640; nxin++) {
      CameraCalImageCapture_B.c_I[nxin + 640 * k0] = b_I[480 * nxin + k0];
    }
  }

  for (nxin = 0; nxin < 8; nxin++) {
    tagFamilyProc[nxin] = m[nxin];
  }

  detectionsObj = NULL;
  outidx = 0;
  nxin = 0;
  posesObj = NULL;
  tagLength_data[0] = 8;
  tagLength_data[1] = 0;
  detectedPosesSize = getAprilTagIdPoseDetections(&CameraCalImageCapture_B.c_I[0],
    &tagFamilyProc[0], true, 2.0F, 640, 480, &detectionsObj, &nxin, 1,
    &tagLength_data[0], &focalLength[0], &principalPoint[0], 58.5, &posesObj,
    &outidx);
  CameraCalImageCa_emxInit_real_T(&b_varargout_1, 2);
  k0 = b_varargout_1->size[0] * b_varargout_1->size[1];
  b_varargout_1->size[0] = 1;
  b_varargout_1->size[1] = outidx;
  Camera_emxEnsureCapacity_real_T(b_varargout_1, k0);
  for (k0 = 0; k0 < outidx; k0++) {
    b_varargout_1->data[k0] = 1.0;
  }

  CameraCalImageCa_emxInit_real_T(&x, 3);
  k0 = x->size[0] * x->size[1] * x->size[2];
  x->size[0] = 4;
  x->size[1] = 2;
  x->size[2] = outidx;
  Camera_emxEnsureCapacity_real_T(x, k0);
  loop_ub = outidx << 3;
  if (loop_ub - 1 >= 0) {
    memset(&x->data[0], 0, (uint32_T)loop_ub * sizeof(real_T));
  }

  CameraCalImageCa_emxInit_real_T(&familyDetectionsLen, 2);
  k0 = familyDetectionsLen->size[0] * familyDetectionsLen->size[1];
  familyDetectionsLen->size[0] = 1;
  familyDetectionsLen->size[1] = outidx;
  Camera_emxEnsureCapacity_real_T(familyDetectionsLen, k0);
  if (outidx - 1 >= 0) {
    memset(&familyDetectionsLen->data[0], 0, (uint32_T)outidx * sizeof(real_T));
  }

  CameraCalImageCa_emxInit_real_T(&rotMatrices, 3);
  k0 = rotMatrices->size[0] * rotMatrices->size[1] * rotMatrices->size[2];
  rotMatrices->size[0] = 3;
  rotMatrices->size[1] = 3;
  rotMatrices->size[2] = detectedPosesSize;
  Camera_emxEnsureCapacity_real_T(rotMatrices, k0);
  loop_ub = 9 * detectedPosesSize;
  if (loop_ub - 1 >= 0) {
    memset(&rotMatrices->data[0], 0, (uint32_T)loop_ub * sizeof(real_T));
  }

  CameraCalImageCa_emxInit_real_T(&transVectors, 3);
  k0 = transVectors->size[0] * transVectors->size[1] * transVectors->size[2];
  transVectors->size[0] = 3;
  transVectors->size[1] = 1;
  transVectors->size[2] = detectedPosesSize;
  Camera_emxEnsureCapacity_real_T(transVectors, k0);
  loop_ub = 3 * detectedPosesSize;
  if (loop_ub - 1 >= 0) {
    memset(&transVectors->data[0], 0, (uint32_T)loop_ub * sizeof(real_T));
  }

  CameraCalImageCa_emxInit_char_T(&familyNames, 2);
  k0 = familyNames->size[0] * familyNames->size[1];
  familyNames->size[0] = 1;
  familyNames->size[1] = nxin;
  Camera_emxEnsureCapacity_char_T(familyNames, k0);
  for (k0 = 0; k0 < nxin; k0++) {
    familyNames->data[k0] = ' ';
  }

  initialiseOutput(&b_varargout_1->data[0], &x->data[0],
                   &familyDetectionsLen->data[0], &familyNames->data[0],
                   detectionsObj, outidx);
  CameraCalImageCa_emxFree_char_T(&familyNames);
  initialisePoses(&rotMatrices->data[0], &transVectors->data[0], detectionsObj,
                  posesObj, detectedPosesSize);
  familyDetectionsLen->size[0] = 1;
  familyDetectionsLen->size[1] = 0;
  varargout_3_Translation[0] = 0.0;
  varargout_3_Translation[1] = 0.0;
  varargout_3_Translation[2] = 0.0;
  for (k0 = 0; k0 < 9; k0++) {
    countValid = p[k0];
    d.R[k0] = countValid;
    varargout_3_R[k0] = countValid;
  }

  d.Translation[0] = 0.0;
  d.Translation[1] = 0.0;
  d.Translation[2] = 0.0;
  k0 = varargout_3_Data->size[0] * varargout_3_Data->size[1];
  varargout_3_Data->size[0] = 1;
  varargout_3_Data->size[1] = 1;
  emxEnsureCapacity_c_images_geot(varargout_3_Data, k0);
  varargout_3_Data->data[0] = d;
  countValid = 1.0;
  nxin = rotMatrices->size[2];
  emxInit_c_images_geotrans_inter(&dataArray, 2);
  for (detectedPosesSize = 0; detectedPosesSize < nxin; detectedPosesSize++) {
    if (!(fabs(CameraCalImageCapture_det(&rotMatrices->data[9 *
           detectedPosesSize]) - 1.0) > 0.001)) {
      for (k0 = 0; k0 < 3; k0++) {
        rotMatrices_0[3 * k0] = rotMatrices->data[9 * detectedPosesSize + k0];
        rotMatrices_0[3 * k0 + 1] = rotMatrices->data[(9 * detectedPosesSize +
          k0) + 3];
        rotMatrices_0[3 * k0 + 2] = rotMatrices->data[(9 * detectedPosesSize +
          k0) + 6];
        d.Translation[k0] = transVectors->data[3 * detectedPosesSize + k0];
      }

      Cam_constrainToRotationMatrix3D(rotMatrices_0, d.R);
      if (countValid > varargout_3_Data->size[1]) {
        k0 = dataArray->size[0] * dataArray->size[1];
        dataArray->size[0] = 1;
        dataArray->size[1] = (int32_T)countValid;
        emxEnsureCapacity_c_images_geot(dataArray, k0);
        k0 = varargout_3_Data->size[1];
        memcpy(&dataArray->data[0], &varargout_3_Data->data[0], (uint32_T)k0 *
               sizeof(c_images_geotrans_internal_ri_T));
        dataArray->data[(int32_T)countValid - 1] = d;
        k0 = varargout_3_Data->size[0] * varargout_3_Data->size[1];
        varargout_3_Data->size[0] = 1;
        varargout_3_Data->size[1] = dataArray->size[1];
        emxEnsureCapacity_c_images_geot(varargout_3_Data, k0);
        loop_ub = dataArray->size[1];
        if (loop_ub - 1 >= 0) {
          memcpy(&varargout_3_Data->data[0], &dataArray->data[0], (uint32_T)
                 loop_ub * sizeof(c_images_geotrans_internal_ri_T));
        }
      } else {
        varargout_3_Data->data[(int32_T)countValid - 1] = d;
      }

      countValid++;
    } else {
      outidx = familyDetectionsLen->size[1];
      k0 = familyDetectionsLen->size[0] * familyDetectionsLen->size[1];
      familyDetectionsLen->size[1]++;
      Camera_emxEnsureCapacity_real_T(familyDetectionsLen, k0);
      familyDetectionsLen->data[outidx] = (real_T)detectedPosesSize + 1.0;
    }
  }

  emxFree_c_images_geotrans_inter(&dataArray);
  CameraCalImageCa_emxFree_real_T(&transVectors);
  CameraCalImageCa_emxFree_real_T(&rotMatrices);
  CameraCalImageC_emxInit_int32_T(&idx_tmp, 2);
  k0 = idx_tmp->size[0] * idx_tmp->size[1];
  idx_tmp->size[0] = 1;
  idx_tmp->size[1] = familyDetectionsLen->size[1];
  Camer_emxEnsureCapacity_int32_T(idx_tmp, k0);
  loop_ub = familyDetectionsLen->size[1];
  for (k0 = 0; k0 < loop_ub; k0++) {
    idx_tmp->data[k0] = (int32_T)familyDetectionsLen->data[k0];
  }

  CameraCalImageCa_emxFree_real_T(&familyDetectionsLen);
  nxin = b_varargout_1->size[1];
  CameraCalImag_emxInit_boolean_T(&b_b, 2);
  k0 = b_b->size[0] * b_b->size[1];
  b_b->size[0] = 1;
  b_b->size[1] = b_varargout_1->size[1];
  Cam_emxEnsureCapacity_boolean_T(b_b, k0);
  loop_ub = b_varargout_1->size[1];
  if (loop_ub - 1 >= 0) {
    memset(&b_b->data[0], 0, (uint32_T)loop_ub * sizeof(boolean_T));
  }

  outidx = idx_tmp->size[1];
  for (detectedPosesSize = 0; detectedPosesSize < outidx; detectedPosesSize++) {
    b_b->data[idx_tmp->data[detectedPosesSize] - 1] = true;
  }

  detectedPosesSize = 0;
  k0 = b_b->size[1];
  for (outidx = 0; outidx < k0; outidx++) {
    detectedPosesSize += b_b->data[outidx];
  }

  detectedPosesSize = b_varargout_1->size[1] - detectedPosesSize;
  k0 = -1;
  for (outidx = 0; outidx < nxin; outidx++) {
    if ((outidx + 1 > b_b->size[1]) || (!b_b->data[outidx])) {
      k0++;
      b_varargout_1->data[k0] = b_varargout_1->data[outidx];
    }
  }

  if (detectedPosesSize < 1) {
    loop_ub = -1;
  } else {
    loop_ub = detectedPosesSize - 1;
  }

  k0 = varargout_1->size[0] * varargout_1->size[1];
  varargout_1->size[0] = 1;
  varargout_1->size[1] = loop_ub + 1;
  Camera_emxEnsureCapacity_real_T(varargout_1, k0);
  if (loop_ub >= 0) {
    memcpy(&varargout_1->data[0], &b_varargout_1->data[0], (uint32_T)(loop_ub +
            1) * sizeof(real_T));
  }

  CameraCalImageCa_emxFree_real_T(&b_varargout_1);
  nxin = x->size[2];
  k0 = b_b->size[0] * b_b->size[1];
  b_b->size[0] = 1;
  b_b->size[1] = x->size[2];
  Cam_emxEnsureCapacity_boolean_T(b_b, k0);
  loop_ub = x->size[2];
  if (loop_ub - 1 >= 0) {
    memset(&b_b->data[0], 0, (uint32_T)loop_ub * sizeof(boolean_T));
  }

  outidx = idx_tmp->size[1];
  for (detectedPosesSize = 0; detectedPosesSize < outidx; detectedPosesSize++) {
    b_b->data[idx_tmp->data[detectedPosesSize] - 1] = true;
  }

  CameraCalImageC_emxFree_int32_T(&idx_tmp);
  detectedPosesSize = 0;
  k0 = b_b->size[1];
  for (outidx = 0; outidx < k0; outidx++) {
    detectedPosesSize += b_b->data[outidx];
  }

  k0 = varargout_2->size[0] * varargout_2->size[1] * varargout_2->size[2];
  varargout_2->size[0] = 4;
  varargout_2->size[1] = 2;
  varargout_2->size[2] = x->size[2] - detectedPosesSize;
  Camera_emxEnsureCapacity_real_T(varargout_2, k0);
  detectedPosesSize = 0;
  k0 = 0;
  for (outidx = 0; outidx < nxin; outidx++) {
    if ((outidx + 1 > b_b->size[1]) || (!b_b->data[outidx])) {
      memcpy(&varargout_2->data[k0], &x->data[detectedPosesSize], sizeof(real_T)
             << 3U);
      k0 += 8;
    }

    detectedPosesSize += 8;
  }

  CameraCalImageCa_emxFree_real_T(&x);
  CameraCalImag_emxFree_boolean_T(&b_b);
  outidx = varargout_2->size[2] << 3;
  k0 = varargout_2->size[0] * varargout_2->size[1] * varargout_2->size[2];
  varargout_2->size[0] = 4;
  varargout_2->size[1] = 2;
  Camera_emxEnsureCapacity_real_T(varargout_2, k0);
  detectedPosesSize = (outidx / 2) << 1;
  loop_ub = detectedPosesSize - 2;
  for (k0 = 0; k0 <= loop_ub; k0 += 2) {
    __m128d tmp;
    tmp = _mm_loadu_pd(&varargout_2->data[k0]);
    _mm_storeu_pd(&varargout_2->data[k0], _mm_add_pd(tmp, _mm_set1_pd(1.0)));
  }

  for (k0 = detectedPosesSize; k0 < outidx; k0++) {
    varargout_2->data[k0]++;
  }
}

/* Model output function for TID0 */
void CameraCalImageCapture_output0(void) /* Sample time: [0.0s, 0.0s] */
{
  /* local block i/o variables */
  real_T rtb_HILReadTimebase1_o1;
  real_T rtb_HILReadTimebase1_o2;
  real_T rtb_HILReadTimebase1_o3;
  real_T rtb_HILReadTimebase1_o4;
  real_T rtb_HILReadTimebase1_o6;
  real_T rtb_HILReadTimebase1_o7;
  real_T rtb_HILReadTimebase1_o8;
  real_T rtb_HILReadTimebase1_o9;
  real_T rtb_HILReadTimebase1_o10;
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
  boolean_T rtb_Compare;
  emxArray_c_images_geotrans_in_T *expl_temp_1;
  emxArray_real_T_CameraCalImag_T *id;
  emxArray_real_T_CameraCalImag_T *loc;
  real_T expl_temp[9];
  real_T rtb_Saturation[4];
  real_T expl_temp_0[3];
  real_T rtb_Bias;
  real_T rtb_HILReadTimebase1_o11;
  real_T rtb_HILReadTimebase1_o12;
  real_T rtb_Memory;
  real_T rtb_Subtract_j;
  int32_T i;
  real32_T tmp[2];
  real32_T tmp_0[2];
  if (rtmIsMajorTimeStep(CameraCalImageCapture_M)) {
    /* set solver stop time */
    if (!(CameraCalImageCapture_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&CameraCalImageCapture_M->solverInfo,
                            ((CameraCalImageCapture_M->Timing.clockTickH0 + 1) *
        CameraCalImageCapture_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&CameraCalImageCapture_M->solverInfo,
                            ((CameraCalImageCapture_M->Timing.clockTick0 + 1) *
        CameraCalImageCapture_M->Timing.stepSize0 +
        CameraCalImageCapture_M->Timing.clockTickH0 *
        CameraCalImageCapture_M->Timing.stepSize0 * 4294967296.0));
    }

    {                                  /* Sample time: [0.0s, 0.0s] */
      rate_monotonic_scheduler();
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(CameraCalImageCapture_M)) {
    CameraCalImageCapture_M->Timing.t[0] = rtsiGetT
      (&CameraCalImageCapture_M->solverInfo);
  }

  /* Reset subsysRan breadcrumbs */
  srClearBC(CameraCalImageCapture_DW.Subsystem_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(CameraCalImageCapture_DW.IfActionSubsystem_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(CameraCalImageCapture_DW.IfActionSubsystem1_SubsysRanBC);
  if (rtmIsMajorTimeStep(CameraCalImageCapture_M)) {
    real_T rateLimiterRate;

    /* S-Function (hil_read_timebase_block): '<S9>/HIL Read Timebase1' */

    /* S-Function Block: CameraCalImageCapture/Hardware Plant P(s)/Subsystem1/HIL Read Timebase1 (hil_read_timebase_block) */
    {
      t_error result;
      result = hil_task_read(CameraCalImageCapture_DW.HILReadTimebase1_Task, 1,
        &CameraCalImageCapture_DW.HILReadTimebase1_AnalogBuffer[0],
        NULL,
        NULL,
        &CameraCalImageCapture_DW.HILReadTimebase1_OtherBuffer[0]
        );
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(CameraCalImageCapture_M, _rt_error_message);
      } else {
        rtb_HILReadTimebase1_o1 =
          CameraCalImageCapture_DW.HILReadTimebase1_AnalogBuffer[0];
        rtb_HILReadTimebase1_o2 =
          CameraCalImageCapture_DW.HILReadTimebase1_AnalogBuffer[1];
        rtb_HILReadTimebase1_o3 =
          CameraCalImageCapture_DW.HILReadTimebase1_AnalogBuffer[2];
        rtb_HILReadTimebase1_o4 =
          CameraCalImageCapture_DW.HILReadTimebase1_AnalogBuffer[3];
        CameraCalImageCapture_B.grippercurrent =
          CameraCalImageCapture_DW.HILReadTimebase1_AnalogBuffer[4];
        rtb_HILReadTimebase1_o6 =
          CameraCalImageCapture_DW.HILReadTimebase1_OtherBuffer[0];
        rtb_HILReadTimebase1_o7 =
          CameraCalImageCapture_DW.HILReadTimebase1_OtherBuffer[1];
        rtb_HILReadTimebase1_o8 =
          CameraCalImageCapture_DW.HILReadTimebase1_OtherBuffer[2];
        rtb_HILReadTimebase1_o9 =
          CameraCalImageCapture_DW.HILReadTimebase1_OtherBuffer[3];
        rtb_HILReadTimebase1_o10 =
          CameraCalImageCapture_DW.HILReadTimebase1_OtherBuffer[4];
        rtb_HILReadTimebase1_o11 =
          CameraCalImageCapture_DW.HILReadTimebase1_OtherBuffer[5];
        rtb_HILReadTimebase1_o12 =
          CameraCalImageCapture_DW.HILReadTimebase1_OtherBuffer[6];
        rtb_Subtract_j = CameraCalImageCapture_DW.HILReadTimebase1_OtherBuffer[7];
        rtb_Memory = CameraCalImageCapture_DW.HILReadTimebase1_OtherBuffer[8];
        rtb_gripperspeed =
          CameraCalImageCapture_DW.HILReadTimebase1_OtherBuffer[9];
        rtb_HILReadTimebase1_o16 =
          CameraCalImageCapture_DW.HILReadTimebase1_OtherBuffer[10];
        rtb_HILReadTimebase1_o17 =
          CameraCalImageCapture_DW.HILReadTimebase1_OtherBuffer[11];
        rtb_HILReadTimebase1_o18 =
          CameraCalImageCapture_DW.HILReadTimebase1_OtherBuffer[12];
        rtb_HILReadTimebase1_o19 =
          CameraCalImageCapture_DW.HILReadTimebase1_OtherBuffer[13];
        rtb_HILReadTimebase1_o20 =
          CameraCalImageCapture_DW.HILReadTimebase1_OtherBuffer[14];
        rtb_HILReadTimebase1_o21 =
          CameraCalImageCapture_DW.HILReadTimebase1_OtherBuffer[15];
        rtb_HILReadTimebase1_o22 =
          CameraCalImageCapture_DW.HILReadTimebase1_OtherBuffer[16];
        rtb_HILReadTimebase1_o23 =
          CameraCalImageCapture_DW.HILReadTimebase1_OtherBuffer[17];
        rtb_HILReadTimebase1_o24 =
          CameraCalImageCapture_DW.HILReadTimebase1_OtherBuffer[18];
        rtb_gripperpwm = CameraCalImageCapture_DW.HILReadTimebase1_OtherBuffer
          [19];
      }
    }

    /* RateLimiter: '<Root>/Rate Limiter' incorporates:
     *  Constant: '<Root>/Constant6'
     */
    rateLimiterRate = CameraCalImageCapture_P.Constant6_Value -
      CameraCalImageCapture_DW.PrevY;
    if (rateLimiterRate > CameraCalImageCapture_P.RateLimiter_RisingLim *
        CameraCalImageCapture_period) {
      /* RateLimiter: '<Root>/Rate Limiter' */
      CameraCalImageCapture_B.RateLimiter =
        CameraCalImageCapture_P.RateLimiter_RisingLim *
        CameraCalImageCapture_period + CameraCalImageCapture_DW.PrevY;
    } else if (rateLimiterRate < CameraCalImageCapture_P.RateLimiter_FallingLim *
               CameraCalImageCapture_period) {
      /* RateLimiter: '<Root>/Rate Limiter' */
      CameraCalImageCapture_B.RateLimiter =
        CameraCalImageCapture_P.RateLimiter_FallingLim *
        CameraCalImageCapture_period + CameraCalImageCapture_DW.PrevY;
    } else {
      /* RateLimiter: '<Root>/Rate Limiter' */
      CameraCalImageCapture_B.RateLimiter =
        CameraCalImageCapture_P.Constant6_Value;
    }

    CameraCalImageCapture_DW.PrevY = CameraCalImageCapture_B.RateLimiter;

    /* End of RateLimiter: '<Root>/Rate Limiter' */
  }

  /* Integrator: '<S7>/Integrator' */
  /* Limited  Integrator  */
  if (rtsiIsModeUpdateTimeStep(&CameraCalImageCapture_M->solverInfo)) {
    ZCEventType zcEvent;
    zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,
                       &CameraCalImageCapture_PrevZCX.Integrator_Reset_ZCE,
                       (CameraCalImageCapture_B.RateLimiter));

    /* evaluate zero-crossings */
    if (zcEvent != NO_ZCEVENT) {
      CameraCalImageCapture_X.Integrator_CSTATE =
        CameraCalImageCapture_P.Integrator_IC;
    }
  }

  if (CameraCalImageCapture_X.Integrator_CSTATE >=
      CameraCalImageCapture_P.Integrator_UpperSat) {
    CameraCalImageCapture_X.Integrator_CSTATE =
      CameraCalImageCapture_P.Integrator_UpperSat;
  } else if (CameraCalImageCapture_X.Integrator_CSTATE <=
             CameraCalImageCapture_P.Integrator_LowerSat) {
    CameraCalImageCapture_X.Integrator_CSTATE =
      CameraCalImageCapture_P.Integrator_LowerSat;
  }

  /* Switch: '<S7>/Switch' */
  if (CameraCalImageCapture_B.RateLimiter >
      CameraCalImageCapture_P.Switch_Threshold) {
    /* Switch: '<S7>/Switch' incorporates:
     *  Integrator: '<S7>/Integrator'
     */
    CameraCalImageCapture_B.gripposition =
      CameraCalImageCapture_X.Integrator_CSTATE;
  } else {
    /* Switch: '<S7>/Switch' incorporates:
     *  Constant: '<S7>/open position'
     */
    CameraCalImageCapture_B.gripposition =
      CameraCalImageCapture_P.openposition_Value;
  }

  /* End of Switch: '<S7>/Switch' */

  /* RelationalOperator: '<S6>/Compare' incorporates:
   *  Clock: '<S2>/Clock'
   *  Constant: '<S6>/Constant'
   */
  rtb_Compare = (CameraCalImageCapture_M->Timing.t[0] >=
                 CameraCalImageCapture_P.CompareToConstant_const);

  /* Outputs for Enabled SubSystem: '<S2>/Subsystem' incorporates:
   *  EnablePort: '<S8>/Enable'
   */
  if (rtsiIsModeUpdateTimeStep(&CameraCalImageCapture_M->solverInfo)) {
    if (rtb_Compare) {
      if (!CameraCalImageCapture_DW.Subsystem_MODE) {
        CameraCalImageCapture_DW.Subsystem_MODE = true;
      }
    } else if (CameraCalImageCapture_DW.Subsystem_MODE) {
      CameraCalImageCapture_DW.Subsystem_MODE = false;
    }
  }

  if (CameraCalImageCapture_DW.Subsystem_MODE) {
    if (rtmIsMajorTimeStep(CameraCalImageCapture_M)) {
      /* S-Function (smooth_signal_generator_block): '<S8>/Smooth Signal Generator' */
      /* S-Function Block: CameraCalImageCapture/Hardware Plant P(s)/Subsystem/Smooth Signal Generator (smooth_signal_generator_block) */
      {
        real_T w = TWO_PI *
          CameraCalImageCapture_P.SmoothSignalGenerator_Frequency;
        boolean_T params_changed =
          (CameraCalImageCapture_P.SmoothSignalGenerator_Amplitude !=
           CameraCalImageCapture_DW.SmoothSignalGenerator_RWORK.Amp || w !=
           CameraCalImageCapture_DW.SmoothSignalGenerator_RWORK.W);

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
          CameraCalImageCapture_DW.SmoothSignalGenerator_RWORK.Sin_w_t;
        real_T y_cos =
          CameraCalImageCapture_DW.SmoothSignalGenerator_RWORK.Cos_w_t;

        /* Produce the output(s) */
        rtb_Bias = CameraCalImageCapture_DW.SmoothSignalGenerator_RWORK.Amp *
          y_sin;

        /* Compute the new sin and cos values */
        CameraCalImageCapture_DW.SmoothSignalGenerator_RWORK.Sin_w_t = y_sin *
          CameraCalImageCapture_DW.SmoothSignalGenerator_RWORK.Cos_w_dt + y_cos *
          CameraCalImageCapture_DW.SmoothSignalGenerator_RWORK.Sin_w_dt;
        CameraCalImageCapture_DW.SmoothSignalGenerator_RWORK.Cos_w_t = y_cos *
          CameraCalImageCapture_DW.SmoothSignalGenerator_RWORK.Cos_w_dt - y_sin *
          CameraCalImageCapture_DW.SmoothSignalGenerator_RWORK.Sin_w_dt;

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
              CameraCalImageCapture_DW.SmoothSignalGenerator_RWORK.Sin_w_t == 0 ||
              (y_sin < 0) !=
              (CameraCalImageCapture_DW.SmoothSignalGenerator_RWORK.Sin_w_t < 0))
          {
            if (fabs(CameraCalImageCapture_DW.SmoothSignalGenerator_RWORK.Amp *
                     CameraCalImageCapture_DW.SmoothSignalGenerator_RWORK.Sin_w_t)
                < CameraCalImageCapture_P.SmoothSignalGenerator_Amplitude) {
              x = asin(CameraCalImageCapture_DW.SmoothSignalGenerator_RWORK.Amp *
                       CameraCalImageCapture_DW.SmoothSignalGenerator_RWORK.Sin_w_t
                       / CameraCalImageCapture_P.SmoothSignalGenerator_Amplitude);
              CameraCalImageCapture_DW.SmoothSignalGenerator_RWORK.Sin_w_dt =
                sin(w * 0.002);
              CameraCalImageCapture_DW.SmoothSignalGenerator_RWORK.Cos_w_dt =
                cos(w * 0.002);
              CameraCalImageCapture_DW.SmoothSignalGenerator_RWORK.Sin_w_t = sin
                (x);

              /*
                 There are always two solutions for the phase. Choose the solution
                 that matches the slope as well as the amplitude.
               */
              if ((cos(x) < 0) !=
                  (CameraCalImageCapture_DW.SmoothSignalGenerator_RWORK.Cos_w_t <
                   0)) {
                CameraCalImageCapture_DW.SmoothSignalGenerator_RWORK.Cos_w_t =
                  -cos(x);
              } else {
                CameraCalImageCapture_DW.SmoothSignalGenerator_RWORK.Cos_w_t =
                  cos(x);
              }
            } else {
              /* really low amplitudes where sawtooth wave goes further in one time step after crossing zero than the new amplitude */
              x = w * 0.002;
              CameraCalImageCapture_DW.SmoothSignalGenerator_RWORK.Sin_w_t = 0;

              /* Make sure cosine output is also continuous */
              if (CameraCalImageCapture_DW.SmoothSignalGenerator_RWORK.Cos_w_t <
                  0) {
                CameraCalImageCapture_DW.SmoothSignalGenerator_RWORK.Cos_w_t =
                  -1;
              } else {
                CameraCalImageCapture_DW.SmoothSignalGenerator_RWORK.Cos_w_t =
                  +1;
              }

              CameraCalImageCapture_DW.SmoothSignalGenerator_RWORK.Sin_w_dt =
                sin(x);
              CameraCalImageCapture_DW.SmoothSignalGenerator_RWORK.Cos_w_dt =
                cos(x);
            }

            CameraCalImageCapture_DW.SmoothSignalGenerator_RWORK.Amp =
              CameraCalImageCapture_P.SmoothSignalGenerator_Amplitude;
            CameraCalImageCapture_DW.SmoothSignalGenerator_RWORK.W = w;
          }
        }
      }

      /* Bias: '<S8>/Bias' */
      rtb_Bias += CameraCalImageCapture_P.Bias_Bias;

      /* S-Function (hil_write_block): '<S8>/HIL Write' incorporates:
       *  Constant: '<Root>/Constant1'
       *  Constant: '<Root>/Default Cmd'
       *  Constant: '<S1>/Constant'
       */

      /* S-Function Block: CameraCalImageCapture/Hardware Plant P(s)/Subsystem/HIL Write (hil_write_block) */
      {
        t_error result;
        CameraCalImageCapture_DW.HILWrite_OtherBuffer[0] =
          CameraCalImageCapture_P.DefaultCmd_Value[0];
        CameraCalImageCapture_DW.HILWrite_OtherBuffer[1] =
          CameraCalImageCapture_P.DefaultCmd_Value[1];
        CameraCalImageCapture_DW.HILWrite_OtherBuffer[2] =
          CameraCalImageCapture_P.DefaultCmd_Value[2];
        CameraCalImageCapture_DW.HILWrite_OtherBuffer[3] =
          CameraCalImageCapture_P.DefaultCmd_Value[3];
        CameraCalImageCapture_DW.HILWrite_OtherBuffer[4] =
          CameraCalImageCapture_B.gripposition;
        CameraCalImageCapture_DW.HILWrite_OtherBuffer[5] =
          CameraCalImageCapture_P.Constant1_Value[0];
        CameraCalImageCapture_DW.HILWrite_OtherBuffer[6] =
          CameraCalImageCapture_P.Constant1_Value[1];
        CameraCalImageCapture_DW.HILWrite_OtherBuffer[7] =
          CameraCalImageCapture_P.Constant1_Value[2];
        CameraCalImageCapture_DW.HILWrite_OtherBuffer[8] =
          CameraCalImageCapture_P.Constant1_Value[3];
        CameraCalImageCapture_DW.HILWrite_OtherBuffer[9] =
          CameraCalImageCapture_P.ColorConstant_color[0];
        CameraCalImageCapture_DW.HILWrite_OtherBuffer[10] =
          CameraCalImageCapture_P.ColorConstant_color[1];
        CameraCalImageCapture_DW.HILWrite_OtherBuffer[11] =
          CameraCalImageCapture_P.ColorConstant_color[2];
        CameraCalImageCapture_DW.HILWrite_OtherBuffer[12] = rtb_Bias;
        result = hil_write
          (CameraCalImageCapture_DW.HILInitializePositionMode_Card,
           NULL, 0U,
           NULL, 0U,
           NULL, 0U,
           CameraCalImageCapture_P.HILWrite_other_channels, 13U,
           NULL,
           NULL,
           NULL,
           &CameraCalImageCapture_DW.HILWrite_OtherBuffer[0]
           );
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(CameraCalImageCapture_M, _rt_error_message);
        }
      }
    }

    if (rtsiIsModeUpdateTimeStep(&CameraCalImageCapture_M->solverInfo)) {
      srUpdateBC(CameraCalImageCapture_DW.Subsystem_SubsysRanBC);
    }
  }

  /* End of Outputs for SubSystem: '<S2>/Subsystem' */
  if (rtmIsMajorTimeStep(CameraCalImageCapture_M)) {
    /* Constant: '<S10>/x0' */
    CameraCalImageCapture_B.x0 = CameraCalImageCapture_P.x0_Value;
  }

  /* Integrator: '<S10>/Integrator1' */
  if (CameraCalImageCapture_DW.Integrator1_IWORK != 0) {
    CameraCalImageCapture_X.Integrator1_CSTATE = CameraCalImageCapture_B.x0;
  }

  /* Integrator: '<S10>/Integrator1' */
  CameraCalImageCapture_B.Integrator1 =
    CameraCalImageCapture_X.Integrator1_CSTATE;
  if (rtmIsMajorTimeStep(CameraCalImageCapture_M)) {
    /* Constant: '<S7>/Soft-Grip Current (A)' */
    CameraCalImageCapture_B.goalcurrent =
      CameraCalImageCapture_P.SoftGripCurrentA_Value;
  }

  /* Product: '<S10>/Product' incorporates:
   *  Constant: '<S10>/Constant'
   *  Constant: '<S10>/wn'
   *  Constant: '<S10>/zt'
   *  Integrator: '<S10>/Integrator2'
   *  Product: '<S10>/Product2'
   *  Sum: '<S10>/Sum'
   *  Sum: '<S10>/Sum1'
   */
  CameraCalImageCapture_B.Product = ((CameraCalImageCapture_B.grippercurrent -
    CameraCalImageCapture_B.Integrator1) -
    CameraCalImageCapture_X.Integrator2_CSTATE *
    CameraCalImageCapture_P.Constant_Value *
    CameraCalImageCapture_P.undOrder25HzfilterbasedonFFT__n) *
    CameraCalImageCapture_P.undOrder25HzfilterbasedonFFT_in;

  /* Product: '<S10>/Product1' incorporates:
   *  Constant: '<S10>/wn'
   *  Integrator: '<S10>/Integrator2'
   */
  CameraCalImageCapture_B.Product1 =
    CameraCalImageCapture_P.undOrder25HzfilterbasedonFFT_in *
    CameraCalImageCapture_X.Integrator2_CSTATE;

  /* Gain: '<S7>/Gain2' incorporates:
   *  Sum: '<S7>/Subtract'
   */
  CameraCalImageCapture_B.Gain2 = (CameraCalImageCapture_B.goalcurrent -
    CameraCalImageCapture_B.Integrator1) * CameraCalImageCapture_P.Gain2_Gain;
  if (rtmIsMajorTimeStep(CameraCalImageCapture_M)) {
    int8_T rtAction;

    /* Logic: '<S9>/for any of the joints' incorporates:
     *  Abs: '<S9>/if the  absolute speed'
     *  Constant: '<S12>/Constant'
     *  RelationalOperator: '<S12>/Compare'
     */
    CameraCalImageCapture_B.foranyofthejoints = ((fabs(rtb_HILReadTimebase1_o11)
      >= CameraCalImageCapture_P.isgreaterthan90degs_const) || (fabs
      (rtb_HILReadTimebase1_o12) >=
      CameraCalImageCapture_P.isgreaterthan90degs_const) || (fabs(rtb_Subtract_j)
      >= CameraCalImageCapture_P.isgreaterthan90degs_const) || (fabs(rtb_Memory)
      >= CameraCalImageCapture_P.isgreaterthan90degs_const));

    /* Stop: '<S11>/Stop Simulation' incorporates:
     *  Constant: '<S13>/Constant'
     *  RelationalOperator: '<S13>/Compare'
     */
    if (CameraCalImageCapture_B.foranyofthejoints !=
        CameraCalImageCapture_P.Constant_Value_f) {
      rtmSetStopRequested(CameraCalImageCapture_M, 1);
    }

    /* End of Stop: '<S11>/Stop Simulation' */

    /* Gain: '<S2>/Gain' incorporates:
     *  Constant: '<S2>/Constant6'
     */
    rtb_HILReadTimebase1_o11 = CameraCalImageCapture_P.Gain_Gain *
      CameraCalImageCapture_P.Constant6_Value_f[0];

    /* Saturate: '<S2>/Saturation' */
    if (rtb_HILReadTimebase1_o11 > CameraCalImageCapture_P.Saturation_UpperSat)
    {
      rtb_Saturation[0] = CameraCalImageCapture_P.Saturation_UpperSat;
    } else if (rtb_HILReadTimebase1_o11 <
               CameraCalImageCapture_P.Saturation_LowerSat) {
      rtb_Saturation[0] = CameraCalImageCapture_P.Saturation_LowerSat;
    } else {
      rtb_Saturation[0] = rtb_HILReadTimebase1_o11;
    }

    /* Gain: '<S2>/Gain' incorporates:
     *  Constant: '<S2>/Constant6'
     */
    rtb_HILReadTimebase1_o11 = CameraCalImageCapture_P.Gain_Gain *
      CameraCalImageCapture_P.Constant6_Value_f[1];

    /* Saturate: '<S2>/Saturation' */
    if (rtb_HILReadTimebase1_o11 > CameraCalImageCapture_P.Saturation_UpperSat)
    {
      rtb_Saturation[1] = CameraCalImageCapture_P.Saturation_UpperSat;
    } else if (rtb_HILReadTimebase1_o11 <
               CameraCalImageCapture_P.Saturation_LowerSat) {
      rtb_Saturation[1] = CameraCalImageCapture_P.Saturation_LowerSat;
    } else {
      rtb_Saturation[1] = rtb_HILReadTimebase1_o11;
    }

    /* Gain: '<S2>/Gain' incorporates:
     *  Constant: '<S2>/Constant6'
     */
    rtb_HILReadTimebase1_o11 = CameraCalImageCapture_P.Gain_Gain *
      CameraCalImageCapture_P.Constant6_Value_f[2];

    /* Saturate: '<S2>/Saturation' */
    if (rtb_HILReadTimebase1_o11 > CameraCalImageCapture_P.Saturation_UpperSat)
    {
      rtb_Saturation[2] = CameraCalImageCapture_P.Saturation_UpperSat;
    } else if (rtb_HILReadTimebase1_o11 <
               CameraCalImageCapture_P.Saturation_LowerSat) {
      rtb_Saturation[2] = CameraCalImageCapture_P.Saturation_LowerSat;
    } else {
      rtb_Saturation[2] = rtb_HILReadTimebase1_o11;
    }

    /* Gain: '<S2>/Gain' incorporates:
     *  Constant: '<S2>/Constant6'
     */
    rtb_HILReadTimebase1_o11 = CameraCalImageCapture_P.Gain_Gain *
      CameraCalImageCapture_P.Constant6_Value_f[3];

    /* Saturate: '<S2>/Saturation' */
    if (rtb_HILReadTimebase1_o11 > CameraCalImageCapture_P.Saturation_UpperSat)
    {
      rtb_Saturation[3] = CameraCalImageCapture_P.Saturation_UpperSat;
    } else if (rtb_HILReadTimebase1_o11 <
               CameraCalImageCapture_P.Saturation_LowerSat) {
      rtb_Saturation[3] = CameraCalImageCapture_P.Saturation_LowerSat;
    } else {
      rtb_Saturation[3] = rtb_HILReadTimebase1_o11;
    }

    /* S-Function (hil_set_property_block): '<S2>/HIL Set Property' */

    /* S-Function Block: CameraCalImageCapture/Hardware Plant P(s)/HIL Set Property (hil_set_property_block) */
    {
      t_error result;
      result = hil_set_double_property
        (CameraCalImageCapture_DW.HILInitializePositionMode_Card,
         (t_hil_double_property *)
         CameraCalImageCapture_P.HILSetProperty_PropertyCodes, 4U,
         &rtb_Saturation[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(CameraCalImageCapture_M, _rt_error_message);
      }
    }

    /* Memory: '<Root>/Memory' */
    rtb_Memory = CameraCalImageCapture_DW.Memory_PreviousInput;

    /* Sum: '<Root>/Subtract' */
    rtb_Subtract_j = CameraCalImageCapture_B.VirtualQArmRGB_o3 - rtb_Memory;

    /* If: '<Root>/If' */
    if (rtsiIsModeUpdateTimeStep(&CameraCalImageCapture_M->solverInfo)) {
      rtAction = (int8_T)!(rtb_Subtract_j > 0.5);
      CameraCalImageCapture_DW.If_ActiveSubsystem = rtAction;
    } else {
      rtAction = CameraCalImageCapture_DW.If_ActiveSubsystem;
    }

    if (rtAction == 0) {
      /* Outputs for IfAction SubSystem: '<Root>/If Action Subsystem' incorporates:
       *  ActionPort: '<S3>/Action Port'
       */
      /* SignalConversion generated from: '<S3>/In1' incorporates:
       *  S-Function (video3d_capture_block): '<Root>/Virtual QArm RGB'
       */
      memcpy(&CameraCalImageCapture_B.In1_g[0],
             &CameraCalImageCapture_B.VirtualQArmRGB_o1[0], 307200U * sizeof
             (uint8_T));
      if (rtsiIsModeUpdateTimeStep(&CameraCalImageCapture_M->solverInfo)) {
        srUpdateBC(CameraCalImageCapture_DW.IfActionSubsystem_SubsysRanBC);
      }

      /* End of Outputs for SubSystem: '<Root>/If Action Subsystem' */
    }

    /* End of If: '<Root>/If' */

    /* If: '<Root>/If1' */
    if (rtsiIsModeUpdateTimeStep(&CameraCalImageCapture_M->solverInfo)) {
      rtAction = (int8_T)!(rtb_Subtract_j > 0.5);
      CameraCalImageCapture_DW.If1_ActiveSubsystem = rtAction;
    } else {
      rtAction = CameraCalImageCapture_DW.If1_ActiveSubsystem;
    }

    if (rtAction == 0) {
      /* Outputs for IfAction SubSystem: '<Root>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S4>/Action Port'
       */
      for (i = 0; i < 9; i++) {
        /* SignalConversion generated from: '<S4>/In1' incorporates:
         *  S-Function (video3d_capture_block): '<Root>/Virtual QArm RGB'
         */
        CameraCalImageCapture_B.In1[i] =
          CameraCalImageCapture_B.VirtualQArmRGB_o5[i];
      }

      if (rtsiIsModeUpdateTimeStep(&CameraCalImageCapture_M->solverInfo)) {
        srUpdateBC(CameraCalImageCapture_DW.IfActionSubsystem1_SubsysRanBC);
      }

      /* End of Outputs for SubSystem: '<Root>/If Action Subsystem1' */
    }

    /* End of If: '<Root>/If1' */

    /* MATLAB Function: '<Root>/MATLAB Function' incorporates:
     *  SignalConversion generated from: '<S4>/In1'
     */
    tmp[0] = CameraCalImageCapture_B.In1[0];
    tmp[1] = CameraCalImageCapture_B.In1[4];
    tmp_0[0] = CameraCalImageCapture_B.In1[6];
    tmp_0[1] = CameraCalImageCapture_B.In1[7];
    CameraCalImageCa_emxInit_real_T(&id, 2);
    CameraCalImageCa_emxInit_real_T(&loc, 3);
    emxInit_c_images_geotrans_inter(&expl_temp_1, 2);

    /* MATLAB Function: '<Root>/MATLAB Function' incorporates:
     *  SignalConversion generated from: '<S3>/In1'
     */
    CameraCalImageCapt_readAprilTag(CameraCalImageCapture_B.In1_g, tmp, tmp_0,
      id, loc, expl_temp, expl_temp_0, expl_temp_1);
    emxFree_c_images_geotrans_inter(&expl_temp_1);
    CameraCalImageCa_emxFree_real_T(&loc);
    CameraCalImageCa_emxFree_real_T(&id);

    /* Switch: '<Root>/Switch' */
    if (rtb_Subtract_j >= CameraCalImageCapture_P.Switch_Threshold_i) {
      /* Switch: '<Root>/Switch' */
      CameraCalImageCapture_B.Switch = CameraCalImageCapture_B.VirtualQArmRGB_o3;
    } else {
      /* Switch: '<Root>/Switch' */
      CameraCalImageCapture_B.Switch = rtb_Memory;
    }

    /* End of Switch: '<Root>/Switch' */
  }
}

/* Model update function for TID0 */
void CameraCalImageCapture_update0(void) /* Sample time: [0.0s, 0.0s] */
{
  /* Update for Integrator: '<S10>/Integrator1' */
  CameraCalImageCapture_DW.Integrator1_IWORK = 0;
  if (rtmIsMajorTimeStep(CameraCalImageCapture_M)) {
    /* Update for Memory: '<Root>/Memory' */
    CameraCalImageCapture_DW.Memory_PreviousInput =
      CameraCalImageCapture_B.Switch;
  }

  if (rtmIsMajorTimeStep(CameraCalImageCapture_M)) {
    rt_ertODEUpdateContinuousStates(&CameraCalImageCapture_M->solverInfo);
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
  if (!(++CameraCalImageCapture_M->Timing.clockTick0)) {
    ++CameraCalImageCapture_M->Timing.clockTickH0;
  }

  CameraCalImageCapture_M->Timing.t[0] = rtsiGetSolverStopTime
    (&CameraCalImageCapture_M->solverInfo);

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick1"
   * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick1 and the high bits
   * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++CameraCalImageCapture_M->Timing.clockTick1)) {
    ++CameraCalImageCapture_M->Timing.clockTickH1;
  }

  CameraCalImageCapture_M->Timing.t[1] =
    CameraCalImageCapture_M->Timing.clockTick1 *
    CameraCalImageCapture_M->Timing.stepSize1 +
    CameraCalImageCapture_M->Timing.clockTickH1 *
    CameraCalImageCapture_M->Timing.stepSize1 * 4294967296.0;
}

/* Derivatives for root system: '<Root>' */
void CameraCalImageCapture_derivatives(void)
{
  XDot_CameraCalImageCapture_T *_rtXdot;
  boolean_T lsat;
  boolean_T usat;
  _rtXdot = ((XDot_CameraCalImageCapture_T *) CameraCalImageCapture_M->derivs);

  /* Derivatives for Integrator: '<S7>/Integrator' */
  lsat = (CameraCalImageCapture_X.Integrator_CSTATE <=
          CameraCalImageCapture_P.Integrator_LowerSat);
  usat = (CameraCalImageCapture_X.Integrator_CSTATE >=
          CameraCalImageCapture_P.Integrator_UpperSat);
  if (((!lsat) && (!usat)) || (lsat && (CameraCalImageCapture_B.Gain2 > 0.0)) ||
      (usat && (CameraCalImageCapture_B.Gain2 < 0.0))) {
    _rtXdot->Integrator_CSTATE = CameraCalImageCapture_B.Gain2;
  } else {
    /* in saturation */
    _rtXdot->Integrator_CSTATE = 0.0;
  }

  /* End of Derivatives for Integrator: '<S7>/Integrator' */

  /* Derivatives for Integrator: '<S10>/Integrator1' */
  _rtXdot->Integrator1_CSTATE = CameraCalImageCapture_B.Product1;

  /* Derivatives for Integrator: '<S10>/Integrator2' */
  _rtXdot->Integrator2_CSTATE = CameraCalImageCapture_B.Product;
}

/* Model output function for TID2 */
void CameraCalImageCapture_output2(void) /* Sample time: [0.034s, 0.0s] */
{
  /* S-Function (video3d_initialize_block): '<Root>/Video3D Initialize' */

  /* S-Function Block: CameraCalImageCapture/Video3D Initialize (video3d_initialize_block) */
  {
  }

  /* S-Function (video3d_capture_block): '<Root>/Virtual QArm RGB' */
  /* S-Function Block: CameraCalImageCapture/Virtual QArm RGB (video3d_capture_block) */
  {
    t_video3d_frame frame;
    t_error result;

    {
      int_T i1;
      real32_T *y4 = &CameraCalImageCapture_B.VirtualQArmRGB_o5[0];
      real32_T *dw_Intrinsics =
        &CameraCalImageCapture_DW.VirtualQArmRGB_Intrinsics[0];
      for (i1=0; i1 < 9; i1++) {
        y4[i1] = dw_Intrinsics[i1];
      }
    }

    result = video3d_stream_get_frame
      (CameraCalImageCapture_DW.VirtualQArmRGB_Stream, &frame);
    if (result >= 0) {
      result = video3d_frame_get_data(frame,
        &CameraCalImageCapture_B.VirtualQArmRGB_o1[0]);
      video3d_frame_get_timestamp(frame,
        &CameraCalImageCapture_B.VirtualQArmRGB_o3);

      /* Release the frame to free up its resources */
      video3d_frame_release(frame);
    }

    if (result < 0 && result != -QERR_WOULD_BLOCK) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(CameraCalImageCapture_M, _rt_error_message);
    }
  }
}

/* Model update function for TID2 */
void CameraCalImageCapture_update2(void) /* Sample time: [0.034s, 0.0s] */
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
  if (!(++CameraCalImageCapture_M->Timing.clockTick2)) {
    ++CameraCalImageCapture_M->Timing.clockTickH2;
  }

  CameraCalImageCapture_M->Timing.t[2] =
    CameraCalImageCapture_M->Timing.clockTick2 *
    CameraCalImageCapture_M->Timing.stepSize2 +
    CameraCalImageCapture_M->Timing.clockTickH2 *
    CameraCalImageCapture_M->Timing.stepSize2 * 4294967296.0;
}

/* Use this function only if you need to maintain compatibility with an existing static main program. */
void CameraCalImageCapture_output(int_T tid)
{
  switch (tid) {
   case 0 :
    CameraCalImageCapture_output0();
    break;

   case 2 :
    CameraCalImageCapture_output2();
    break;

   default :
    /* do nothing */
    break;
  }
}

/* Use this function only if you need to maintain compatibility with an existing static main program. */
void CameraCalImageCapture_update(int_T tid)
{
  switch (tid) {
   case 0 :
    CameraCalImageCapture_update0();
    break;

   case 2 :
    CameraCalImageCapture_update2();
    break;

   default :
    /* do nothing */
    break;
  }
}

/* Model initialize function */
void CameraCalImageCapture_initialize(void)
{
  /* Start for S-Function (hil_initialize_block): '<Root>/HIL Initialize (Position Mode)' */

  /* S-Function Block: CameraCalImageCapture/HIL Initialize (Position Mode) (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("qarm_usb", "0",
                      &CameraCalImageCapture_DW.HILInitializePositionMode_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(CameraCalImageCapture_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options
      (CameraCalImageCapture_DW.HILInitializePositionMode_Card,
       "j0_mode=0;j1_mode=0;j2_mode=0;j3_mode=0;gripper_mode=0;j0_profile_config=0;j0_profile_velocity=0;j0_profile_acceleration=0;j1_profile_config=0;j1_profile_velocity=0;j1_profile_acceleration=0;j2_profile_config=0;j2_profile_velocity=0;j2_profile_acceleration=0;j3_profile_config=0;j3_profile_velocity=0;j3_profile_acceleration=0;",
       328);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(CameraCalImageCapture_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear
      (CameraCalImageCapture_DW.HILInitializePositionMode_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(CameraCalImageCapture_M, _rt_error_message);
      return;
    }

    if ((CameraCalImageCapture_P.HILInitializePositionMode_OOSta &&
         !is_switching) ||
        (CameraCalImageCapture_P.HILInitializePositionMode_OOEnt && is_switching))
    {
      result = hil_write_other
        (CameraCalImageCapture_DW.HILInitializePositionMode_Card,
         CameraCalImageCapture_P.HILInitializePositionMode_OOCha, 4U,
         CameraCalImageCapture_P.HILInitializePositionMode_OOIni);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(CameraCalImageCapture_M, _rt_error_message);
        return;
      }
    }

    if (CameraCalImageCapture_P.HILInitializePositionMode_OORes) {
      result = hil_watchdog_set_other_expiration_state
        (CameraCalImageCapture_DW.HILInitializePositionMode_Card,
         CameraCalImageCapture_P.HILInitializePositionMode_OOCha, 4U,
         CameraCalImageCapture_P.HILInitializePositionMode_OOWat);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(CameraCalImageCapture_M, _rt_error_message);
        return;
      }
    }
  }

  /* Start for S-Function (hil_read_timebase_block): '<S9>/HIL Read Timebase1' */

  /* S-Function Block: CameraCalImageCapture/Hardware Plant P(s)/Subsystem1/HIL Read Timebase1 (hil_read_timebase_block) */
  {
    t_error result;
    result = hil_task_create_reader
      (CameraCalImageCapture_DW.HILInitializePositionMode_Card,
       CameraCalImageCapture_P.HILReadTimebase1_SamplesInBuffe,
       CameraCalImageCapture_P.HILReadTimebase1_AnalogChannels, 5U,
       NULL, 0U,
       NULL, 0U,
       CameraCalImageCapture_P.HILReadTimebase1_OtherChannels, 20U,
       &CameraCalImageCapture_DW.HILReadTimebase1_Task);
    if (result >= 0) {
      result = hil_task_set_buffer_overflow_mode
        (CameraCalImageCapture_DW.HILReadTimebase1_Task, (t_buffer_overflow_mode)
         (CameraCalImageCapture_P.HILReadTimebase1_OverflowMode - 1));
    }

    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(CameraCalImageCapture_M, _rt_error_message);
    }
  }

  /* Start for Enabled SubSystem: '<S2>/Subsystem' */
  CameraCalImageCapture_DW.Subsystem_MODE = false;

  /* Start for S-Function (smooth_signal_generator_block): '<S8>/Smooth Signal Generator' */

  /* S-Function Block: CameraCalImageCapture/Hardware Plant P(s)/Subsystem/Smooth Signal Generator (smooth_signal_generator_block) */
  {
    real_T T = 1.0 / CameraCalImageCapture_P.SmoothSignalGenerator_Frequency;
    CameraCalImageCapture_DW.SmoothSignalGenerator_RWORK.Amp =
      CameraCalImageCapture_P.SmoothSignalGenerator_Amplitude;
    CameraCalImageCapture_DW.SmoothSignalGenerator_RWORK.W = TWO_PI *
      CameraCalImageCapture_P.SmoothSignalGenerator_Frequency;
    CameraCalImageCapture_DW.SmoothSignalGenerator_RWORK.Sin_w_dt = sin
      (CameraCalImageCapture_DW.SmoothSignalGenerator_RWORK.W * 0.002);
    CameraCalImageCapture_DW.SmoothSignalGenerator_RWORK.Cos_w_dt = cos
      (CameraCalImageCapture_DW.SmoothSignalGenerator_RWORK.W * 0.002);
    CameraCalImageCapture_DW.SmoothSignalGenerator_RWORK.Sin_w_t = sin
      (CameraCalImageCapture_P.SmoothSignalGenerator_InitialPh);
    CameraCalImageCapture_DW.SmoothSignalGenerator_RWORK.Cos_w_t = cos
      (CameraCalImageCapture_P.SmoothSignalGenerator_InitialPh);
  }

  /* End of Start for SubSystem: '<S2>/Subsystem' */

  /* Start for Constant: '<S10>/x0' */
  CameraCalImageCapture_B.x0 = CameraCalImageCapture_P.x0_Value;

  /* Start for S-Function (hil_set_property_block): '<S2>/HIL Set Property' */

  /* S-Function Block: CameraCalImageCapture/Hardware Plant P(s)/HIL Set Property (hil_set_property_block) */
  {
  }

  /* Start for If: '<Root>/If' */
  CameraCalImageCapture_DW.If_ActiveSubsystem = -1;

  /* Start for If: '<Root>/If1' */
  CameraCalImageCapture_DW.If1_ActiveSubsystem = -1;

  /* Start for S-Function (video3d_initialize_block): '<Root>/Video3D Initialize' */

  /* S-Function Block: CameraCalImageCapture/Video3D Initialize (video3d_initialize_block) */
  {
    t_error result;
    result = video3d_open("0",
                          &CameraCalImageCapture_DW.Video3DInitialize_Video3D);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(CameraCalImageCapture_M, _rt_error_message);
      return;
    }
  }

  /* Start for S-Function (video3d_capture_block): '<Root>/Virtual QArm RGB' */
  {
    t_error result;
    result = video3d_stream_open
      (CameraCalImageCapture_DW.Video3DInitialize_Video3D, VIDEO3D_STREAM_COLOR,
       CameraCalImageCapture_P.VirtualQArmRGB_stream_index, 29.411764705882351,
       640, 480,
       IMAGE_FORMAT_COL_MAJOR_GRAYSCALE, IMAGE_DATA_TYPE_UINT8,
       &CameraCalImageCapture_DW.VirtualQArmRGB_Stream);
    if (result >= 0) {
      t_video3d_property config_properties[4];
      t_double config_values[4];
      t_uint num_config_properties = 0;
      if (CameraCalImageCapture_P.VirtualQArmRGB_Preset != 21) {
        config_properties[num_config_properties] =
          VIDEO3D_PROPERTY_VISUAL_PRESET;
        config_values[num_config_properties] = (t_video3d_visual_preset)
          (CameraCalImageCapture_P.VirtualQArmRGB_Preset - 1);
        num_config_properties++;
      }

      if (CameraCalImageCapture_P.VirtualQArmRGB_Emitter != 3) {
        config_properties[num_config_properties] =
          VIDEO3D_PROPERTY_ENABLE_EMITTER;
        config_values[num_config_properties] =
          (CameraCalImageCapture_P.VirtualQArmRGB_Emitter == 1) ? 1.0 : 0.0;
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
          (CameraCalImageCapture_DW.VirtualQArmRGB_Stream, config_properties,
           num_config_properties, config_values);
      }
    }

    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(CameraCalImageCapture_M, _rt_error_message);
    }
  }

  CameraCalImageCapture_PrevZCX.Integrator_Reset_ZCE = UNINITIALIZED_ZCSIG;

  {
    int32_T i;

    /* InitializeConditions for RateLimiter: '<Root>/Rate Limiter' */
    CameraCalImageCapture_DW.PrevY = CameraCalImageCapture_P.RateLimiter_IC;

    /* InitializeConditions for Integrator: '<S7>/Integrator' */
    CameraCalImageCapture_X.Integrator_CSTATE =
      CameraCalImageCapture_P.Integrator_IC;

    /* InitializeConditions for Integrator: '<S10>/Integrator1' */
    if (rtmIsFirstInitCond(CameraCalImageCapture_M)) {
      CameraCalImageCapture_X.Integrator1_CSTATE = 0.0;
    }

    CameraCalImageCapture_DW.Integrator1_IWORK = 1;

    /* End of InitializeConditions for Integrator: '<S10>/Integrator1' */

    /* InitializeConditions for Integrator: '<S10>/Integrator2' */
    CameraCalImageCapture_X.Integrator2_CSTATE =
      CameraCalImageCapture_P.Integrator2_IC;

    /* InitializeConditions for Memory: '<Root>/Memory' */
    CameraCalImageCapture_DW.Memory_PreviousInput =
      CameraCalImageCapture_P.Memory_InitialCondition;

    /* InitializeConditions for S-Function (video3d_initialize_block): '<Root>/Video3D Initialize' */

    /* S-Function Block: CameraCalImageCapture/Video3D Initialize (video3d_initialize_block) */
    {
      if (rtmIsFirstInitCond(CameraCalImageCapture_M)) {
        t_error result = video3d_start_streaming
          (CameraCalImageCapture_DW.Video3DInitialize_Video3D);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(CameraCalImageCapture_M, _rt_error_message);
          return;
        }
      }
    }

    /* InitializeConditions for S-Function (video3d_capture_block): '<Root>/Virtual QArm RGB' */

    /* S-Function Block: CameraCalImageCapture/Virtual QArm RGB (video3d_capture_block) */
    {
      if (rtmIsFirstInitCond(CameraCalImageCapture_M)) {
        t_single intrinsics[3][3];
        t_single coefficients[5];
        t_error result;
        result = video3d_stream_get_camera_intrinsics
          (CameraCalImageCapture_DW.VirtualQArmRGB_Stream, intrinsics,
           &CameraCalImageCapture_DW.VirtualQArmRGB_Model, coefficients);
        if (result >= 0) {
          memory_copy(&CameraCalImageCapture_DW.VirtualQArmRGB_Intrinsics[0], 9 *
                      sizeof(t_single), intrinsics);
          memory_copy(&CameraCalImageCapture_DW.VirtualQArmRGB_Coefficients[0],
                      5 * sizeof(t_single), coefficients);
        } else {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(CameraCalImageCapture_M, _rt_error_message);
          return;
        }
      }
    }

    /* SystemInitialize for IfAction SubSystem: '<Root>/If Action Subsystem' */
    for (i = 0; i < 307200; i++) {
      /* SystemInitialize for SignalConversion generated from: '<S3>/In1' incorporates:
       *  Outport: '<S3>/image'
       */
      CameraCalImageCapture_B.In1_g[i] = CameraCalImageCapture_P.image_Y0_m;
    }

    /* End of SystemInitialize for SubSystem: '<Root>/If Action Subsystem' */

    /* SystemInitialize for IfAction SubSystem: '<Root>/If Action Subsystem1' */
    for (i = 0; i < 9; i++) {
      /* SystemInitialize for SignalConversion generated from: '<S4>/In1' incorporates:
       *  Outport: '<S4>/image'
       */
      CameraCalImageCapture_B.In1[i] = CameraCalImageCapture_P.image_Y0;
    }

    /* End of SystemInitialize for SubSystem: '<Root>/If Action Subsystem1' */

    /* set "at time zero" to false */
    if (rtmIsFirstInitCond(CameraCalImageCapture_M)) {
      rtmSetFirstInitCond(CameraCalImageCapture_M, 0);
    }
  }
}

/* Model terminate function */
void CameraCalImageCapture_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<Root>/HIL Initialize (Position Mode)' */

  /* S-Function Block: CameraCalImageCapture/HIL Initialize (Position Mode) (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_other_outputs = 0;
    hil_task_stop_all(CameraCalImageCapture_DW.HILInitializePositionMode_Card);
    hil_monitor_stop_all(CameraCalImageCapture_DW.HILInitializePositionMode_Card);
    is_switching = false;
    if ((CameraCalImageCapture_P.HILInitializePositionMode_OOTer &&
         !is_switching) ||
        (CameraCalImageCapture_P.HILInitializePositionMode_OOExi && is_switching))
    {
      num_final_other_outputs = 4U;
    } else {
      num_final_other_outputs = 0;
    }

    if (num_final_other_outputs > 0) {
      result = hil_write_other
        (CameraCalImageCapture_DW.HILInitializePositionMode_Card,
         CameraCalImageCapture_P.HILInitializePositionMode_OOCha,
         num_final_other_outputs,
         CameraCalImageCapture_P.HILInitializePositionMode_OOFin);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(CameraCalImageCapture_M, _rt_error_message);
      }
    }

    hil_task_delete_all(CameraCalImageCapture_DW.HILInitializePositionMode_Card);
    hil_monitor_delete_all
      (CameraCalImageCapture_DW.HILInitializePositionMode_Card);
    hil_close(CameraCalImageCapture_DW.HILInitializePositionMode_Card);
    CameraCalImageCapture_DW.HILInitializePositionMode_Card = NULL;
  }

  /* Terminate for S-Function (video3d_initialize_block): '<Root>/Video3D Initialize' */

  /* S-Function Block: CameraCalImageCapture/Video3D Initialize (video3d_initialize_block) */
  {
    video3d_stop_streaming(CameraCalImageCapture_DW.Video3DInitialize_Video3D);
    video3d_close(CameraCalImageCapture_DW.Video3DInitialize_Video3D);
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
  CameraCalImageCapture_output(tid);
}

void MdlUpdate(int_T tid)
{
  if (tid == 1)
    tid = 0;
  CameraCalImageCapture_update(tid);
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
  CameraCalImageCapture_initialize();
}

void MdlTerminate(void)
{
  CameraCalImageCapture_terminate();
}

/* Registration function */
RT_MODEL_CameraCalImageCaptur_T *CameraCalImageCapture(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* non-finite (run-time) assignments */
  CameraCalImageCapture_P.HILInitializePositionMode_AOHig = rtInf;
  CameraCalImageCapture_P.HILInitializePositionMode_AOLow = rtMinusInf;

  /* initialize real-time model */
  (void) memset((void *)CameraCalImageCapture_M, 0,
                sizeof(RT_MODEL_CameraCalImageCaptur_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&CameraCalImageCapture_M->solverInfo,
                          &CameraCalImageCapture_M->Timing.simTimeStep);
    rtsiSetTPtr(&CameraCalImageCapture_M->solverInfo, &rtmGetTPtr
                (CameraCalImageCapture_M));
    rtsiSetStepSizePtr(&CameraCalImageCapture_M->solverInfo,
                       &CameraCalImageCapture_M->Timing.stepSize0);
    rtsiSetdXPtr(&CameraCalImageCapture_M->solverInfo,
                 &CameraCalImageCapture_M->derivs);
    rtsiSetContStatesPtr(&CameraCalImageCapture_M->solverInfo, (real_T **)
                         &CameraCalImageCapture_M->contStates);
    rtsiSetNumContStatesPtr(&CameraCalImageCapture_M->solverInfo,
      &CameraCalImageCapture_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&CameraCalImageCapture_M->solverInfo,
      &CameraCalImageCapture_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&CameraCalImageCapture_M->solverInfo,
      &CameraCalImageCapture_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&CameraCalImageCapture_M->solverInfo,
      &CameraCalImageCapture_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&CameraCalImageCapture_M->solverInfo,
                          (&rtmGetErrorStatus(CameraCalImageCapture_M)));
    rtsiSetRTModelPtr(&CameraCalImageCapture_M->solverInfo,
                      CameraCalImageCapture_M);
  }

  rtsiSetSimTimeStep(&CameraCalImageCapture_M->solverInfo, MAJOR_TIME_STEP);
  CameraCalImageCapture_M->intgData.y = CameraCalImageCapture_M->odeY;
  CameraCalImageCapture_M->intgData.f[0] = CameraCalImageCapture_M->odeF[0];
  CameraCalImageCapture_M->intgData.f[1] = CameraCalImageCapture_M->odeF[1];
  CameraCalImageCapture_M->intgData.f[2] = CameraCalImageCapture_M->odeF[2];
  CameraCalImageCapture_M->intgData.f[3] = CameraCalImageCapture_M->odeF[3];
  CameraCalImageCapture_M->contStates = ((real_T *) &CameraCalImageCapture_X);
  rtsiSetSolverData(&CameraCalImageCapture_M->solverInfo, (void *)
                    &CameraCalImageCapture_M->intgData);
  rtsiSetIsMinorTimeStepWithModeChange(&CameraCalImageCapture_M->solverInfo,
    false);
  rtsiSetSolverName(&CameraCalImageCapture_M->solverInfo,"ode4");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = CameraCalImageCapture_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    mdlTsMap[2] = 2;

    /* polyspace +2 MISRA2012:D4.1 [Justified:Low] "CameraCalImageCapture_M points to
       static memory which is guaranteed to be non-NULL" */
    CameraCalImageCapture_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    CameraCalImageCapture_M->Timing.sampleTimes =
      (&CameraCalImageCapture_M->Timing.sampleTimesArray[0]);
    CameraCalImageCapture_M->Timing.offsetTimes =
      (&CameraCalImageCapture_M->Timing.offsetTimesArray[0]);

    /* task periods */
    CameraCalImageCapture_M->Timing.sampleTimes[0] = (0.0);
    CameraCalImageCapture_M->Timing.sampleTimes[1] = (0.002);
    CameraCalImageCapture_M->Timing.sampleTimes[2] = (0.034);

    /* task offsets */
    CameraCalImageCapture_M->Timing.offsetTimes[0] = (0.0);
    CameraCalImageCapture_M->Timing.offsetTimes[1] = (0.0);
    CameraCalImageCapture_M->Timing.offsetTimes[2] = (0.0);
  }

  rtmSetTPtr(CameraCalImageCapture_M, &CameraCalImageCapture_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = CameraCalImageCapture_M->Timing.sampleHitArray;
    int_T *mdlPerTaskSampleHits =
      CameraCalImageCapture_M->Timing.perTaskSampleHitsArray;
    CameraCalImageCapture_M->Timing.perTaskSampleHits = (&mdlPerTaskSampleHits[0]);
    mdlSampleHits[0] = 1;
    CameraCalImageCapture_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(CameraCalImageCapture_M, -1);
  CameraCalImageCapture_M->Timing.stepSize0 = 0.002;
  CameraCalImageCapture_M->Timing.stepSize1 = 0.002;
  CameraCalImageCapture_M->Timing.stepSize2 = 0.034;
  rtmSetFirstInitCond(CameraCalImageCapture_M, 1);

  /* External mode info */
  CameraCalImageCapture_M->Sizes.checksums[0] = (2412154689U);
  CameraCalImageCapture_M->Sizes.checksums[1] = (3137354760U);
  CameraCalImageCapture_M->Sizes.checksums[2] = (1554175097U);
  CameraCalImageCapture_M->Sizes.checksums[3] = (3572230178U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[5];
    CameraCalImageCapture_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = (sysRanDType *)
      &CameraCalImageCapture_DW.Subsystem_SubsysRanBC;
    systemRan[2] = (sysRanDType *)
      &CameraCalImageCapture_DW.IfActionSubsystem_SubsysRanBC;
    systemRan[3] = (sysRanDType *)
      &CameraCalImageCapture_DW.IfActionSubsystem1_SubsysRanBC;
    systemRan[4] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(CameraCalImageCapture_M->extModeInfo,
      &CameraCalImageCapture_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(CameraCalImageCapture_M->extModeInfo,
                        CameraCalImageCapture_M->Sizes.checksums);
    rteiSetTPtr(CameraCalImageCapture_M->extModeInfo, rtmGetTPtr
                (CameraCalImageCapture_M));
  }

  CameraCalImageCapture_M->solverInfoPtr = (&CameraCalImageCapture_M->solverInfo);
  CameraCalImageCapture_M->Timing.stepSize = (0.002);
  rtsiSetFixedStepSize(&CameraCalImageCapture_M->solverInfo, 0.002);
  rtsiSetSolverMode(&CameraCalImageCapture_M->solverInfo,
                    SOLVER_MODE_MULTITASKING);

  /* block I/O */
  CameraCalImageCapture_M->blockIO = ((void *) &CameraCalImageCapture_B);
  (void) memset(((void *) &CameraCalImageCapture_B), 0,
                sizeof(B_CameraCalImageCapture_T));

  /* parameters */
  CameraCalImageCapture_M->defaultParam = ((real_T *)&CameraCalImageCapture_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &CameraCalImageCapture_X;
    CameraCalImageCapture_M->contStates = (x);
    (void) memset((void *)&CameraCalImageCapture_X, 0,
                  sizeof(X_CameraCalImageCapture_T));
  }

  /* states (dwork) */
  CameraCalImageCapture_M->dwork = ((void *) &CameraCalImageCapture_DW);
  (void) memset((void *)&CameraCalImageCapture_DW, 0,
                sizeof(DW_CameraCalImageCapture_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    CameraCalImageCapture_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 27;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  CameraCalImageCapture_M->Sizes.numContStates = (3);/* Number of continuous states */
  CameraCalImageCapture_M->Sizes.numPeriodicContStates = (0);
                                      /* Number of periodic continuous states */
  CameraCalImageCapture_M->Sizes.numY = (0);/* Number of model outputs */
  CameraCalImageCapture_M->Sizes.numU = (0);/* Number of model inputs */
  CameraCalImageCapture_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  CameraCalImageCapture_M->Sizes.numSampTimes = (3);/* Number of sample times */
  CameraCalImageCapture_M->Sizes.numBlocks = (59);/* Number of blocks */
  CameraCalImageCapture_M->Sizes.numBlockIO = (17);/* Number of block outputs */
  CameraCalImageCapture_M->Sizes.numBlockPrms = (176);/* Sum of parameter "widths" */
  return CameraCalImageCapture_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
