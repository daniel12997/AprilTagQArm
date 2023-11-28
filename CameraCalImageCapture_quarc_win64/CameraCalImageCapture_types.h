/*
 * CameraCalImageCapture_types.h
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

#ifndef RTW_HEADER_CameraCalImageCapture_types_h_
#define RTW_HEADER_CameraCalImageCapture_types_h_
#include "rtwtypes.h"
#include "quanser_video3d.h"

/* Custom Type definition for MATLAB Function: '<Root>/MATLAB Function' */
#ifndef struct_tag_Gig2vFy4YBrcUWowOjHV1D
#define struct_tag_Gig2vFy4YBrcUWowOjHV1D

struct tag_Gig2vFy4YBrcUWowOjHV1D
{
  real_T R[9];
  real_T Translation[3];
};

#endif                                 /* struct_tag_Gig2vFy4YBrcUWowOjHV1D */

#ifndef typedef_c_images_geotrans_internal_ri_T
#define typedef_c_images_geotrans_internal_ri_T

typedef struct tag_Gig2vFy4YBrcUWowOjHV1D c_images_geotrans_internal_ri_T;

#endif                             /* typedef_c_images_geotrans_internal_ri_T */

#ifndef struct_emxArray_real_T
#define struct_emxArray_real_T

struct emxArray_real_T
{
  real_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /* struct_emxArray_real_T */

#ifndef typedef_emxArray_real_T_CameraCalImag_T
#define typedef_emxArray_real_T_CameraCalImag_T

typedef struct emxArray_real_T emxArray_real_T_CameraCalImag_T;

#endif                             /* typedef_emxArray_real_T_CameraCalImag_T */

#ifndef struct_emxArray_tag_Gig2vFy4YBrcUWowOj
#define struct_emxArray_tag_Gig2vFy4YBrcUWowOj

struct emxArray_tag_Gig2vFy4YBrcUWowOj
{
  c_images_geotrans_internal_ri_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                              /* struct_emxArray_tag_Gig2vFy4YBrcUWowOj */

#ifndef typedef_emxArray_c_images_geotrans_in_T
#define typedef_emxArray_c_images_geotrans_in_T

typedef struct emxArray_tag_Gig2vFy4YBrcUWowOj emxArray_c_images_geotrans_in_T;

#endif                             /* typedef_emxArray_c_images_geotrans_in_T */

#ifndef struct_emxArray_char_T
#define struct_emxArray_char_T

struct emxArray_char_T
{
  char_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /* struct_emxArray_char_T */

#ifndef typedef_emxArray_char_T_CameraCalImag_T
#define typedef_emxArray_char_T_CameraCalImag_T

typedef struct emxArray_char_T emxArray_char_T_CameraCalImag_T;

#endif                             /* typedef_emxArray_char_T_CameraCalImag_T */

#ifndef struct_emxArray_boolean_T
#define struct_emxArray_boolean_T

struct emxArray_boolean_T
{
  boolean_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /* struct_emxArray_boolean_T */

#ifndef typedef_emxArray_boolean_T_CameraCalI_T
#define typedef_emxArray_boolean_T_CameraCalI_T

typedef struct emxArray_boolean_T emxArray_boolean_T_CameraCalI_T;

#endif                             /* typedef_emxArray_boolean_T_CameraCalI_T */

#ifndef struct_emxArray_int32_T
#define struct_emxArray_int32_T

struct emxArray_int32_T
{
  int32_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /* struct_emxArray_int32_T */

#ifndef typedef_emxArray_int32_T_CameraCalIma_T
#define typedef_emxArray_int32_T_CameraCalIma_T

typedef struct emxArray_int32_T emxArray_int32_T_CameraCalIma_T;

#endif                             /* typedef_emxArray_int32_T_CameraCalIma_T */

/* Parameters (default storage) */
typedef struct P_CameraCalImageCapture_T_ P_CameraCalImageCapture_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_CameraCalImageCapture_T RT_MODEL_CameraCalImageCaptur_T;

#endif                           /* RTW_HEADER_CameraCalImageCapture_types_h_ */
