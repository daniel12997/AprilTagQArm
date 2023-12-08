/*
 * AprilTag_PickandPlace_data.c
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

/* Block parameters (default storage) */
P_AprilTag_PickandPlace_T AprilTag_PickandPlace_P = {
  /* Mask Parameter: ColorConstant_color
   * Referenced by: '<S2>/Constant'
   */
  { 0.0, 0.44706, 0.74118 },

  /* Mask Parameter: undOrder25HzfilterbasedonFFT_in
   * Referenced by: '<S9>/wn'
   */
  157.07963267948966,

  /* Mask Parameter: undOrder25HzfilterbasedonFFT__k
   * Referenced by: '<S9>/zt'
   */
  1.0,

  /* Mask Parameter: HILWrite_other_channels
   * Referenced by: '<S3>/HIL Write'
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

  /* Mask Parameter: Counter_InitialCount
   * Referenced by: '<Root>/Counter'
   */
  0U,

  /* Expression: [0.45 0 0.49]
   * Referenced by: '<Root>/Home Position'
   */
  { 0.45, 0.0, 0.49 },

  /* Expression: [0 0.25 0.1]
   * Referenced by: '<Root>/Picture Position '
   */
  { 0.0, 0.25, 0.1 },

  /* Expression: 0
   * Referenced by: '<Root>/Constant'
   */
  0.0,

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
  0.0,

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
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0 },

  /* Expression: watchdog_other_outputs
   * Referenced by: '<Root>/HIL Initialize (Position Mode)'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  /* Expression: 1
   * Referenced by: '<Root>/State Switch'
   */
  1.0,

  /* Expression: 0
   * Referenced by:
   */
  0.0,

  /* Expression: [0.170006338542880,-0.083530373140931,0.639226541970821]
   * Referenced by: '<Root>/Object Position'
   */
  { 0.17000633854288, -0.083530373140931, 0.639226541970821 },

  /* Expression: [1.569 0.1987 1.044 0.0023]
   * Referenced by: '<Root>/Joint Anle for Camera Position'
   */
  { 1.569, 0.1987, 1.044, 0.0023 },

  /* Expression: [0 0 0.03]
   * Referenced by: '<Root>/Object Offset'
   */
  { 0.0, 0.0, 0.03 },

  /* Expression: [0 0 0.1]
   * Referenced by: '<Root>/Vertical Offset'
   */
  { 0.0, 0.0, 0.1 },

  /* Expression: [-0.163632516714285,-0.066233872037758,0.581053210978698]
   * Referenced by: '<Root>/Goal Position'
   */
  { -0.163632516714285, -0.066233872037758, 0.581053210978698 },

  /* Expression: [0 0 0.03]
   * Referenced by: '<Root>/Placement Offset'
   */
  { 0.0, 0.0, 0.03 },

  /* Expression: 3
   * Referenced by: '<Root>/State 3 Constant'
   */
  3.0,

  /* Expression: [0 0 0 0]
   * Referenced by: '<Root>/Constant1'
   */
  { 0.0, 0.0, 0.0, 0.0 },

  /* Expression: 0
   * Referenced by:
   */
  0.0,

  /* Expression: 0.1
   * Referenced by: '<S8>/Integrator'
   */
  0.1,

  /* Expression: 0.6
   * Referenced by: '<S8>/Integrator'
   */
  0.6,

  /* Expression: 0.1
   * Referenced by: '<S8>/Integrator'
   */
  0.1,

  /* Expression: 0.1
   * Referenced by: '<S8>/open position'
   */
  0.1,

  /* Expression: 0
   * Referenced by: '<S8>/Switch'
   */
  0.0,

  /* Expression: initial_phase
   * Referenced by: '<S3>/Smooth Signal Generator'
   */
  0.0,

  /* Expression: i_amplitude
   * Referenced by: '<S3>/Smooth Signal Generator'
   */
  0.5,

  /* Expression: i_frequency
   * Referenced by: '<S3>/Smooth Signal Generator'
   */
  0.5,

  /* Expression: 0.5
   * Referenced by: '<S3>/Bias'
   */
  0.5,

  /* Expression: input_init
   * Referenced by: '<S9>/x0'
   */
  0.0,

  /* Expression: 0.25
   * Referenced by: '<S8>/Soft-Grip Current (A)'
   */
  0.25,

  /* Expression: 2
   * Referenced by: '<S9>/Constant'
   */
  2.0,

  /* Expression: 0
   * Referenced by: '<S9>/Integrator2'
   */
  0.0,

  /* Expression: 10
   * Referenced by: '<S8>/Gain2'
   */
  10.0,

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

  /* Expression: 1
   * Referenced by: '<S1>/Constant'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S1>/Unit Delay'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<Root>/Add Constant'
   */
  1.0,

  /* Expression: 0.0
   * Referenced by: '<Root>/Delay'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<Root>/Gripper Close'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<Root>/Gripper Open'
   */
  0.0,

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

  /* Computed Parameter: HILInitializePositionMode_CKCha
   * Referenced by: '<Root>/HIL Initialize (Position Mode)'
   */
  0,

  /* Computed Parameter: HILInitializePositionMode_DOWat
   * Referenced by: '<Root>/HIL Initialize (Position Mode)'
   */
  0,

  /* Computed Parameter: HILReadTimebase1_Clock
   * Referenced by: '<S3>/HIL Read Timebase1'
   */
  0,

  /* Computed Parameter: HILInitializePositionMode_AICha
   * Referenced by: '<Root>/HIL Initialize (Position Mode)'
   */
  { 5U, 6U, 7U, 8U, 9U },

  /* Computed Parameter: HILInitializePositionMode_OOCha
   * Referenced by: '<Root>/HIL Initialize (Position Mode)'
   */
  { 11005U, 11006U, 11007U, 11008U, 1000U, 1001U, 1002U, 1003U, 1004U, 11000U,
    11001U, 11002U, 11003U },

  /* Computed Parameter: HILReadTimebase1_SamplesInBuffe
   * Referenced by: '<S3>/HIL Read Timebase1'
   */
  500U,

  /* Computed Parameter: HILReadTimebase1_AnalogChannels
   * Referenced by: '<S3>/HIL Read Timebase1'
   */
  { 5U, 6U, 7U, 8U, 9U },

  /* Computed Parameter: HILReadTimebase1_OtherChannels
   * Referenced by: '<S3>/HIL Read Timebase1'
   */
  { 1000U, 1001U, 1002U, 1003U, 1004U, 3000U, 3001U, 3002U, 3003U, 3004U, 10000U,
    10001U, 10002U, 10003U, 10004U, 11000U, 11001U, 11002U, 11003U, 11004U },

  /* Computed Parameter: VirtualQArmRGB_Preset
   * Referenced by: '<Root>/Virtual QArm RGB'
   */
  21U,

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
   * Referenced by: '<S3>/HIL Read Timebase1'
   */
  true,

  /* Computed Parameter: HILWrite_Active
   * Referenced by: '<S3>/HIL Write'
   */
  true,

  /* Computed Parameter: HILReadTimebase1_OverflowMode
   * Referenced by: '<S3>/HIL Read Timebase1'
   */
  1U
};
