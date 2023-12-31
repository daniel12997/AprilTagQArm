/*
 * CameraCalImageCapture_dt.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "CameraCalImageCapture".
 *
 * Model version              : 1.10
 * Simulink Coder version : 9.8 (R2022b) 13-May-2022
 * C source code generated on : Mon Nov 27 19:19:04 2023
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ext_types.h"

/* data type size table */
static uint_T rtDataTypeSizes[] = {
  sizeof(real_T),
  sizeof(real32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int16_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(boolean_T),
  sizeof(fcn_call_T),
  sizeof(int_T),
  sizeof(pointer_T),
  sizeof(action_T),
  2*sizeof(uint32_T),
  sizeof(int32_T),
  sizeof(t_video3d),
  sizeof(t_video3d_stream),
  sizeof(t_int64),
  sizeof(t_uint64),
  sizeof(t_video3d_distortion_model),
  sizeof(t_card),
  sizeof(t_hil_double_property),
  sizeof(t_task),
  sizeof(uint_T),
  sizeof(char_T),
  sizeof(uchar_T),
  sizeof(time_T)
};

/* data type name table */
static const char_T * rtDataTypeNames[] = {
  "real_T",
  "real32_T",
  "int8_T",
  "uint8_T",
  "int16_T",
  "uint16_T",
  "int32_T",
  "uint32_T",
  "boolean_T",
  "fcn_call_T",
  "int_T",
  "pointer_T",
  "action_T",
  "timer_uint32_pair_T",
  "physical_connection",
  "t_video3d",
  "t_video3d_stream",
  "t_int64",
  "t_uint64",
  "t_video3d_distortion_model",
  "t_card",
  "t_hil_double_property",
  "t_task",
  "uint_T",
  "char_T",
  "uchar_T",
  "time_T"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&CameraCalImageCapture_B.VirtualQArmRGB_o2), 18, 0, 1 },

  { (char_T *)(&CameraCalImageCapture_B.grippercurrent), 0, 0, 10 },

  { (char_T *)(&CameraCalImageCapture_B.VirtualQArmRGB_o1[0]), 3, 0, 1843200 },

  { (char_T *)(&CameraCalImageCapture_B.foranyofthejoints), 8, 0, 1 }
  ,

  { (char_T *)(&CameraCalImageCapture_DW.HILReadTimebase1_AnalogBuffer[0]), 0, 0,
    39 },

  { (char_T *)(&CameraCalImageCapture_DW.Video3DInitialize_Video3D), 15, 0, 2 },

  { (char_T *)(&CameraCalImageCapture_DW.VirtualQArmRGB_Stream), 16, 0, 1 },

  { (char_T *)(&CameraCalImageCapture_DW.HILInitializePositionMode_Card), 20, 0,
    1 },

  { (char_T *)(&CameraCalImageCapture_DW.HILReadTimebase1_Task), 22, 0, 1 },

  { (char_T *)(&CameraCalImageCapture_DW.SmoothSignalGenerator_RWORK.Amp), 0, 0,
    1 },

  { (char_T *)(&CameraCalImageCapture_DW.CurrentFilteration_PWORK.LoggedData[0]),
    11, 0, 7 },

  { (char_T *)(&CameraCalImageCapture_DW.VirtualQArmRGB_Intrinsics[0]), 1, 0, 14
  },

  { (char_T *)(&CameraCalImageCapture_DW.HILInitializePositionMode_Clock), 6, 0,
    1 },

  { (char_T *)(&CameraCalImageCapture_DW.VirtualQArmRGB_Model), 19, 0, 1 },

  { (char_T *)(&CameraCalImageCapture_DW.HILSetProperty_DoubleCodes[0]), 21, 0,
    4 },

  { (char_T *)(&CameraCalImageCapture_DW.Integrator1_IWORK), 10, 0, 1 },

  { (char_T *)(&CameraCalImageCapture_DW.Subsystem_SubsysRanBC), 2, 0, 1 },

  { (char_T *)(&CameraCalImageCapture_DW.Subsystem_MODE), 8, 0, 1 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  18U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&CameraCalImageCapture_P.ColorConstant_color[0]), 0, 0, 7 },

  { (char_T *)(&CameraCalImageCapture_P.HILWrite_other_channels[0]), 7, 0, 14 },

  { (char_T *)(&CameraCalImageCapture_P.Video3DInitialize_active), 8, 0, 1 },

  { (char_T *)(&CameraCalImageCapture_P.StopwithMessage_message_icon), 2, 0, 1 },

  { (char_T *)(&CameraCalImageCapture_P.SmoothSignalGenerator_InitialPh), 0, 0,
    64 },

  { (char_T *)(&CameraCalImageCapture_P.HILInitializePositionMode_CKCha), 6, 0,
    7 },

  { (char_T *)(&CameraCalImageCapture_P.HILInitializePositionMode_AICha[0]), 7,
    0, 36 },

  { (char_T *)(&CameraCalImageCapture_P.HILWrite_Active), 8, 0, 39 },

  { (char_T *)(&CameraCalImageCapture_P.HILReadTimebase1_OverflowMode), 3, 0, 1
  }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  9U,
  rtPTransitions
};

/* [EOF] CameraCalImageCapture_dt.h */
