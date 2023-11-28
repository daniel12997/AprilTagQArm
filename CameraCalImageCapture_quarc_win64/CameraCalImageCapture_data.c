/*
 * CameraCalImageCapture_data.c
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

/* Block parameters (default storage) */
P_CameraCalImageCapture_T CameraCalImageCapture_P = {
  /* Mask Parameter: ColorConstant_color
   * Referenced by: '<S1>/Constant'
   */
  { 0.0, 0.44706, 0.74118 },

  /* Mask Parameter: CompareToConstant_const
   * Referenced by: '<S6>/Constant'
   */
  0.004,

  /* Mask Parameter: isgreaterthan90degs_const
   * Referenced by: '<S12>/Constant'
   */
  1.5707963267948966,

  /* Mask Parameter: undOrder25HzfilterbasedonFFT_in
   * Referenced by: '<S10>/wn'
   */
  157.07963267948966,

  /* Mask Parameter: undOrder25HzfilterbasedonFFT__n
   * Referenced by: '<S10>/zt'
   */
  1.0,

  /* Mask Parameter: DisplayImage_update_rate
   * Referenced by: '<Root>/Display Image'
   */
  1,

  /* Mask Parameter: HILWrite_other_channels
   * Referenced by: '<S8>/HIL Write'
   */
  { 1000U, 1001U, 1002U, 1003U, 1004U, 11000U, 11001U, 11002U, 11003U, 11005U,
    11006U, 11007U, 11008U },

  /* Mask Parameter: VirtualQArmRGB_stream_index
   * Referenced by: '<Root>/Virtual QArm RGB'
   */
  0U,

  /* Mask Parameter: Video3DInitialize_active
   * Referenced by: '<Root>/Video3D Initialize'
   */
  true,

  /* Mask Parameter: DisplayImage_orig_size
   * Referenced by: '<Root>/Display Image'
   */
  false,

  /* Mask Parameter: StopwithMessage_message_icon
   * Referenced by: '<S11>/Show Message on Host'
   */
  1,

  /* Expression: initial_phase
   * Referenced by: '<S8>/Smooth Signal Generator'
   */
  0.0,

  /* Expression: i_amplitude
   * Referenced by: '<S8>/Smooth Signal Generator'
   */
  0.5,

  /* Expression: i_frequency
   * Referenced by: '<S8>/Smooth Signal Generator'
   */
  0.5,

  /* Expression: 0.5
   * Referenced by: '<S8>/Bias'
   */
  0.5,

  /* Expression: set_other_outputs_at_terminate
   * Referenced by: '<Root>/HIL Initialize (Position Mode)'
   */
  1.0,

  /* Expression: set_other_outputs_at_switch_out
   * Referenced by: '<Root>/HIL Initialize (Position Mode)'
   */
  0.0,

  /* Expression: set_other_outputs_at_start
   * Referenced by: '<Root>/HIL Initialize (Position Mode)'
   */
  1.0,

  /* Expression: set_other_outputs_at_switch_in
   * Referenced by: '<Root>/HIL Initialize (Position Mode)'
   */
  0.0,

  /* Expression: final_analog_outputs
   * Referenced by: '<Root>/HIL Initialize (Position Mode)'
   */
  0.0,

  /* Expression: final_other_outputs
   * Referenced by: '<Root>/HIL Initialize (Position Mode)'
   */
  { 1.0, 0.0, 0.0, 0.0 },

  /* Expression: analog_output_maximums
   * Referenced by: '<Root>/HIL Initialize (Position Mode)'
   */
  0.0,

  /* Expression: analog_output_minimums
   * Referenced by: '<Root>/HIL Initialize (Position Mode)'
   */
  0.0,

  /* Expression: initial_analog_outputs
   * Referenced by: '<Root>/HIL Initialize (Position Mode)'
   */
  0.0,

  /* Expression: initial_other_outputs
   * Referenced by: '<Root>/HIL Initialize (Position Mode)'
   */
  { 0.0, 1.0, 0.0, 1.0 },

  /* Expression: watchdog_other_outputs
   * Referenced by: '<Root>/HIL Initialize (Position Mode)'
   */
  { 0.0, 0.0, 1.0, 0.0 },

  /* Expression: [0 0 0 0]
   * Referenced by: '<Root>/Constant1'
   */
  { 0.0, 0.0, 0.0, 0.0 },

  /* Expression: 0
   * Referenced by: '<Root>/Constant6'
   */
  0.0,

  /* Expression: [0 0 0 0]
   * Referenced by: '<Root>/Default Cmd'
   */
  { 0.0, 0.0, 0.0, 0.0 },

  /* Expression: 1
   * Referenced by: '<Root>/Rate Limiter'
   */
  1.0,

  /* Expression: -1
   * Referenced by: '<Root>/Rate Limiter'
   */
  -1.0,

  /* Expression: 0
   * Referenced by: '<Root>/Rate Limiter'
   */
  0.0,

  /* Expression: 0.1
   * Referenced by: '<S7>/Integrator'
   */
  0.1,

  /* Expression: 0.65
   * Referenced by: '<S7>/Integrator'
   */
  0.65,

  /* Expression: 0.1
   * Referenced by: '<S7>/Integrator'
   */
  0.1,

  /* Expression: 0.1
   * Referenced by: '<S7>/open position'
   */
  0.1,

  /* Expression: 0
   * Referenced by: '<S7>/Switch'
   */
  0.0,

  /* Expression: input_init
   * Referenced by: '<S10>/x0'
   */
  0.0,

  /* Expression: 0.25
   * Referenced by: '<S7>/Soft-Grip Current (A)'
   */
  0.25,

  /* Expression: 2
   * Referenced by: '<S10>/Constant'
   */
  2.0,

  /* Expression: 0
   * Referenced by: '<S10>/Integrator2'
   */
  0.0,

  /* Expression: 10
   * Referenced by: '<S7>/Gain2'
   */
  10.0,

  /* Expression: [5 5 5 0]
   * Referenced by: '<S2>/Constant6'
   */
  { 5.0, 5.0, 5.0, 0.0 },

  /* Expression: 0.24/100
   * Referenced by: '<S2>/Gain'
   */
  0.0024,

  /* Expression: 0.24
   * Referenced by: '<S2>/Saturation'
   */
  0.24,

  /* Expression: 0
   * Referenced by: '<S2>/Saturation'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Memory'
   */
  0.0,

  /* Expression: 0.5
   * Referenced by: '<Root>/Switch'
   */
  0.5,

  /* Expression: d_brightness
   * Referenced by: '<Root>/Virtual QArm RGB'
   */
  50.0,

  /* Expression: d_contrast
   * Referenced by: '<Root>/Virtual QArm RGB'
   */
  50.0,

  /* Expression: d_hue
   * Referenced by: '<Root>/Virtual QArm RGB'
   */
  50.0,

  /* Expression: d_saturation
   * Referenced by: '<Root>/Virtual QArm RGB'
   */
  50.0,

  /* Expression: d_sharpness
   * Referenced by: '<Root>/Virtual QArm RGB'
   */
  50.0,

  /* Expression: d_gamma
   * Referenced by: '<Root>/Virtual QArm RGB'
   */
  50.0,

  /* Expression: d_whitebalance
   * Referenced by: '<Root>/Virtual QArm RGB'
   */
  50.0,

  /* Expression: d_backlightcompensation
   * Referenced by: '<Root>/Virtual QArm RGB'
   */
  50.0,

  /* Expression: d_gain
   * Referenced by: '<Root>/Virtual QArm RGB'
   */
  50.0,

  /* Expression: d_exposure
   * Referenced by: '<Root>/Virtual QArm RGB'
   */
  30.0,

  /* Expression: emitter
   * Referenced by: '<Root>/Virtual QArm RGB'
   */
  1.0,

  /* Computed Parameter: HILInitializePositionMode_CKCha
   * Referenced by: '<Root>/HIL Initialize (Position Mode)'
   */
  0,

  /* Computed Parameter: HILInitializePositionMode_DOWat
   * Referenced by: '<Root>/HIL Initialize (Position Mode)'
   */
  0,

  /* Computed Parameter: HILReadTimebase1_Clock
   * Referenced by: '<S9>/HIL Read Timebase1'
   */
  0,

  /* Computed Parameter: HILSetProperty_PropertyCodes
   * Referenced by: '<S2>/HIL Set Property'
   */
  { 133, 134, 135, 136 },

  /* Computed Parameter: image_Y0
   * Referenced by: '<S4>/image'
   */
  0.0F,

  /* Computed Parameter: HILInitializePositionMode_AICha
   * Referenced by: '<Root>/HIL Initialize (Position Mode)'
   */
  { 5U, 6U, 7U, 8U, 9U },

  /* Computed Parameter: HILInitializePositionMode_OOCha
   * Referenced by: '<Root>/HIL Initialize (Position Mode)'
   */
  { 11005U, 11006U, 11007U, 11008U },

  /* Computed Parameter: HILReadTimebase1_SamplesInBuffe
   * Referenced by: '<S9>/HIL Read Timebase1'
   */
  500U,

  /* Computed Parameter: HILReadTimebase1_AnalogChannels
   * Referenced by: '<S9>/HIL Read Timebase1'
   */
  { 5U, 6U, 7U, 8U, 9U },

  /* Computed Parameter: HILReadTimebase1_OtherChannels
   * Referenced by: '<S9>/HIL Read Timebase1'
   */
  { 1000U, 1001U, 1002U, 1003U, 1004U, 3000U, 3001U, 3002U, 3003U, 3004U, 10000U,
    10001U, 10002U, 10003U, 10004U, 11000U, 11001U, 11002U, 11003U, 11004U },

  /* Computed Parameter: VirtualQArmRGB_Preset
   * Referenced by: '<Root>/Virtual QArm RGB'
   */
  21U,

  /* Computed Parameter: HILWrite_Active
   * Referenced by: '<S8>/HIL Write'
   */
  true,

  /* Computed Parameter: Constant_Value_f
   * Referenced by: '<S13>/Constant'
   */
  false,

  /* Computed Parameter: HILInitializePositionMode_Activ
   * Referenced by: '<Root>/HIL Initialize (Position Mode)'
   */
  true,

  /* Computed Parameter: HILInitializePositionMode_AOTer
   * Referenced by: '<Root>/HIL Initialize (Position Mode)'
   */
  false,

  /* Computed Parameter: HILInitializePositionMode_AOExi
   * Referenced by: '<Root>/HIL Initialize (Position Mode)'
   */
  false,

  /* Computed Parameter: HILInitializePositionMode_DOTer
   * Referenced by: '<Root>/HIL Initialize (Position Mode)'
   */
  false,

  /* Computed Parameter: HILInitializePositionMode_DOExi
   * Referenced by: '<Root>/HIL Initialize (Position Mode)'
   */
  false,

  /* Computed Parameter: HILInitializePositionMode_POTer
   * Referenced by: '<Root>/HIL Initialize (Position Mode)'
   */
  false,

  /* Computed Parameter: HILInitializePositionMode_POExi
   * Referenced by: '<Root>/HIL Initialize (Position Mode)'
   */
  false,

  /* Computed Parameter: HILInitializePositionMode_CKPSt
   * Referenced by: '<Root>/HIL Initialize (Position Mode)'
   */
  false,

  /* Computed Parameter: HILInitializePositionMode_CKPEn
   * Referenced by: '<Root>/HIL Initialize (Position Mode)'
   */
  false,

  /* Computed Parameter: HILInitializePositionMode_CKSta
   * Referenced by: '<Root>/HIL Initialize (Position Mode)'
   */
  false,

  /* Computed Parameter: HILInitializePositionMode_CKEnt
   * Referenced by: '<Root>/HIL Initialize (Position Mode)'
   */
  false,

  /* Computed Parameter: HILInitializePositionMode_AIPSt
   * Referenced by: '<Root>/HIL Initialize (Position Mode)'
   */
  false,

  /* Computed Parameter: HILInitializePositionMode_AIPEn
   * Referenced by: '<Root>/HIL Initialize (Position Mode)'
   */
  false,

  /* Computed Parameter: HILInitializePositionMode_AOPSt
   * Referenced by: '<Root>/HIL Initialize (Position Mode)'
   */
  false,

  /* Computed Parameter: HILInitializePositionMode_AOPEn
   * Referenced by: '<Root>/HIL Initialize (Position Mode)'
   */
  false,

  /* Computed Parameter: HILInitializePositionMode_AOSta
   * Referenced by: '<Root>/HIL Initialize (Position Mode)'
   */
  false,

  /* Computed Parameter: HILInitializePositionMode_AOEnt
   * Referenced by: '<Root>/HIL Initialize (Position Mode)'
   */
  false,

  /* Computed Parameter: HILInitializePositionMode_AORes
   * Referenced by: '<Root>/HIL Initialize (Position Mode)'
   */
  false,

  /* Computed Parameter: HILInitializePositionMode_DOPSt
   * Referenced by: '<Root>/HIL Initialize (Position Mode)'
   */
  false,

  /* Computed Parameter: HILInitializePositionMode_DOPEn
   * Referenced by: '<Root>/HIL Initialize (Position Mode)'
   */
  false,

  /* Computed Parameter: HILInitializePositionMode_DOSta
   * Referenced by: '<Root>/HIL Initialize (Position Mode)'
   */
  false,

  /* Computed Parameter: HILInitializePositionMode_DOEnt
   * Referenced by: '<Root>/HIL Initialize (Position Mode)'
   */
  false,

  /* Computed Parameter: HILInitializePositionMode_DORes
   * Referenced by: '<Root>/HIL Initialize (Position Mode)'
   */
  false,

  /* Computed Parameter: HILInitializePositionMode_EIPSt
   * Referenced by: '<Root>/HIL Initialize (Position Mode)'
   */
  false,

  /* Computed Parameter: HILInitializePositionMode_EIPEn
   * Referenced by: '<Root>/HIL Initialize (Position Mode)'
   */
  false,

  /* Computed Parameter: HILInitializePositionMode_EISta
   * Referenced by: '<Root>/HIL Initialize (Position Mode)'
   */
  false,

  /* Computed Parameter: HILInitializePositionMode_EIEnt
   * Referenced by: '<Root>/HIL Initialize (Position Mode)'
   */
  false,

  /* Computed Parameter: HILInitializePositionMode_POPSt
   * Referenced by: '<Root>/HIL Initialize (Position Mode)'
   */
  false,

  /* Computed Parameter: HILInitializePositionMode_POPEn
   * Referenced by: '<Root>/HIL Initialize (Position Mode)'
   */
  false,

  /* Computed Parameter: HILInitializePositionMode_POSta
   * Referenced by: '<Root>/HIL Initialize (Position Mode)'
   */
  false,

  /* Computed Parameter: HILInitializePositionMode_POEnt
   * Referenced by: '<Root>/HIL Initialize (Position Mode)'
   */
  false,

  /* Computed Parameter: HILInitializePositionMode_PORes
   * Referenced by: '<Root>/HIL Initialize (Position Mode)'
   */
  false,

  /* Computed Parameter: HILInitializePositionMode_OORes
   * Referenced by: '<Root>/HIL Initialize (Position Mode)'
   */
  false,

  /* Computed Parameter: HILInitializePositionMode_DOFin
   * Referenced by: '<Root>/HIL Initialize (Position Mode)'
   */
  false,

  /* Computed Parameter: HILInitializePositionMode_DOIni
   * Referenced by: '<Root>/HIL Initialize (Position Mode)'
   */
  false,

  /* Computed Parameter: HILReadTimebase1_Active
   * Referenced by: '<S9>/HIL Read Timebase1'
   */
  true,

  /* Computed Parameter: HILSetProperty_Active
   * Referenced by: '<S2>/HIL Set Property'
   */
  false,

  /* Computed Parameter: image_Y0_m
   * Referenced by: '<S3>/image'
   */
  0U,

  /* Computed Parameter: HILReadTimebase1_OverflowMode
   * Referenced by: '<S9>/HIL Read Timebase1'
   */
  1U
};
