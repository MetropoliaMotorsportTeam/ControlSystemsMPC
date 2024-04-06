/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: TorqueVectoring.h
 *
 * Code generated for Simulink model 'TorqueVectoring'.
 *
 * Model version                  : 1.0
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Wed Mar 27 18:22:20 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_TorqueVectoring_h_
#define RTW_HEADER_TorqueVectoring_h_
#include "rtwtypes.h"
#include <stddef.h>
#include <math.h>
#include <string.h>
#ifndef TorqueVectoring_COMMON_INCLUDES_
#define TorqueVectoring_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* TorqueVectoring_COMMON_INCLUDES_ */

/* Model Code Variants */

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM RT_MODEL;

#ifndef DEFINED_TYPEDEF_FOR_struct_WTmPWsEMvOzNnnAVv5fQNC_
#define DEFINED_TYPEDEF_FOR_struct_WTmPWsEMvOzNnnAVv5fQNC_

typedef struct {
  int32_T MaxIterations;
  real_T ConstraintTolerance;
  boolean_T UseWarmStart;
} struct_WTmPWsEMvOzNnnAVv5fQNC;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_WHjMt45Sk148iktWsfFxl_
#define DEFINED_TYPEDEF_FOR_struct_WHjMt45Sk148iktWsfFxl_

typedef struct {
  int32_T MaxIterations;
  real_T ConstraintTolerance;
  real_T OptimalityTolerance;
  real_T ComplementarityTolerance;
  real_T StepTolerance;
} struct_WHjMt45Sk148iktWsfFxl;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_lnQ9KXdSZFplhcBp5LBCc_
#define DEFINED_TYPEDEF_FOR_struct_lnQ9KXdSZFplhcBp5LBCc_

typedef struct {
  int32_T MaxIterations;
  real_T ConstraintTolerance;
  real_T DiscreteConstraintTolerance;
  boolean_T RoundingAtRootNode;
  int32_T MaxPendingNodes;
} struct_lnQ9KXdSZFplhcBp5LBCc;

#endif

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  real_T last_x_PreviousInput[6];      /* '<S13>/last_x' */
  real_T LastPcov_PreviousInput[36];   /* '<S13>/LastPcov' */
  real_T last_mv_DSTATE;               /* '<S13>/last_mv' */
  boolean_T Memory_PreviousInput;      /* '<S13>/Memory' */
} DW;

/* Constant parameters (default storage) */
typedef struct {
  /* Expression: lastPcov
   * Referenced by: '<S13>/LastPcov'
   */
  real_T LastPcov_InitialCondition[36];
} ConstP;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T StrAngleDeg;                  /* '<Root>/StrAngleDeg' */
  real_T VehicleSpeed;                 /* '<Root>/VehicleSpeed' */
  real_T TorqueVectoringEnabled;       /* '<Root>/TorqueVectoringEnabled' */
  real_T VehicleYawRate;               /* '<Root>/VehicleYawRate' */
  boolean_T FeedbackEnabled;           /* '<Root>/FeedbackEnabled' */
  boolean_T FeedForwardEnabled;        /* '<Root>/FeedForwardEnabled' */
  real_T LateralVelocity;              /* '<Root>/LateralVelocity' */
} ExtU;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T TVFL;                         /* '<Root>/TVFL' */
  real_T TVFR;                         /* '<Root>/TVFR' */
  real_T TVRL;                         /* '<Root>/TVRL' */
  real_T TVRR;                         /* '<Root>/TVRR' */
} ExtY;

/* Real-time Model Data Structure */
struct tag_RTM {
  const char_T * volatile errorStatus;
};

/* Block signals and states (default storage) */
extern DW rtDW;

/* External inputs (root inport signals with default storage) */
extern ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY rtY;

/* Constant parameters (default storage) */
extern const ConstP rtConstP;

/* Model entry point functions */
extern void TorqueVectoring_initialize(void);
extern void TorqueVectoring_step(void);

/* Real-time Model object */
extern RT_MODEL *const rtM;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S13>/Floor' : Unused code path elimination
 * Block '<S13>/Floor1' : Unused code path elimination
 * Block '<S14>/Matrix Dimension Check' : Unused code path elimination
 * Block '<S15>/Matrix Dimension Check' : Unused code path elimination
 * Block '<S16>/Matrix Dimension Check' : Unused code path elimination
 * Block '<S17>/Matrix Dimension Check' : Unused code path elimination
 * Block '<S18>/Matrix Dimension Check' : Unused code path elimination
 * Block '<S19>/Matrix Dimension Check' : Unused code path elimination
 * Block '<S20>/Matrix Dimension Check' : Unused code path elimination
 * Block '<S21>/Matrix Dimension Check' : Unused code path elimination
 * Block '<S22>/Matrix Dimension Check' : Unused code path elimination
 * Block '<S23>/Matrix Dimension Check' : Unused code path elimination
 * Block '<S24>/Matrix Dimension Check' : Unused code path elimination
 * Block '<S25>/Matrix Dimension Check' : Unused code path elimination
 * Block '<S26>/Matrix Dimension Check' : Unused code path elimination
 * Block '<S27>/Matrix Dimension Check' : Unused code path elimination
 * Block '<S28>/Matrix Dimension Check' : Unused code path elimination
 * Block '<S29>/Matrix Dimension Check' : Unused code path elimination
 * Block '<S30>/Matrix Dimension Check' : Unused code path elimination
 * Block '<S31>/Matrix Dimension Check' : Unused code path elimination
 * Block '<S32>/Matrix Dimension Check' : Unused code path elimination
 * Block '<S33>/Matrix Dimension Check' : Unused code path elimination
 * Block '<S34>/Vector Dimension Check' : Unused code path elimination
 * Block '<S35>/Vector Dimension Check' : Unused code path elimination
 * Block '<S36>/Vector Dimension Check' : Unused code path elimination
 * Block '<S37>/Vector Dimension Check' : Unused code path elimination
 * Block '<S38>/Vector Dimension Check' : Unused code path elimination
 * Block '<S39>/Vector Dimension Check' : Unused code path elimination
 * Block '<S40>/Vector Dimension Check' : Unused code path elimination
 * Block '<S13>/useq_scale' : Unused code path elimination
 * Block '<S13>/useq_scale1' : Unused code path elimination
 * Block '<S13>/ym_zero' : Unused code path elimination
 * Block '<S11>/m_zero' : Unused code path elimination
 * Block '<S11>/p_zero' : Unused code path elimination
 * Block '<S10>/Scope' : Unused code path elimination
 * Block '<S10>/Scope1' : Unused code path elimination
 * Block '<S9>/AND' : Unused code path elimination
 * Block '<S9>/Constant' : Unused code path elimination
 * Block '<S9>/Product' : Unused code path elimination
 * Block '<S9>/Product2' : Unused code path elimination
 * Block '<S9>/Yaw moment saturation' : Unused code path elimination
 * Block '<S13>/Reshape' : Reshape block reduction
 * Block '<S13>/Reshape1' : Reshape block reduction
 * Block '<S13>/Reshape2' : Reshape block reduction
 * Block '<S13>/Reshape3' : Reshape block reduction
 * Block '<S13>/Reshape4' : Reshape block reduction
 * Block '<S13>/Reshape5' : Reshape block reduction
 * Block '<S13>/ext.mv_scale' : Eliminated nontunable gain of 1
 * Block '<S13>/u_scale' : Eliminated nontunable gain of 1
 * Block '<S13>/umin_scale4' : Eliminated nontunable gain of 1
 * Block '<S13>/uref_scale' : Eliminated nontunable gain of 1
 * Block '<S13>/ymin_scale1' : Eliminated nontunable gain of 1
 * Block '<S13>/ymin_scale2' : Eliminated nontunable gain of 1
 * Block '<S10>/NominalU1' : Eliminated nontunable bias of 0
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'TorqueVectoring'
 * '<S1>'   : 'TorqueVectoring/Subsystem'
 * '<S2>'   : 'TorqueVectoring/Subsystem/Compare To Constant'
 * '<S3>'   : 'TorqueVectoring/Subsystem/If steering angle is between -10 and 10 degrees system is off '
 * '<S4>'   : 'TorqueVectoring/Subsystem/Yaw moment distribution'
 * '<S5>'   : 'TorqueVectoring/Subsystem/Yaw rate controller'
 * '<S6>'   : 'TorqueVectoring/Subsystem/Yaw rate reference calculation'
 * '<S7>'   : 'TorqueVectoring/Subsystem/Yaw moment distribution/Lateral torque distribution'
 * '<S8>'   : 'TorqueVectoring/Subsystem/Yaw rate controller/Feedback controller type'
 * '<S9>'   : 'TorqueVectoring/Subsystem/Yaw rate controller/Feedforward controller type'
 * '<S10>'  : 'TorqueVectoring/Subsystem/Yaw rate controller/Feedback controller type/PI controller type'
 * '<S11>'  : 'TorqueVectoring/Subsystem/Yaw rate controller/Feedback controller type/PI controller type/Adaptive MPC Controller'
 * '<S12>'  : 'TorqueVectoring/Subsystem/Yaw rate controller/Feedback controller type/PI controller type/MATLAB Function'
 * '<S13>'  : 'TorqueVectoring/Subsystem/Yaw rate controller/Feedback controller type/PI controller type/Adaptive MPC Controller/MPC'
 * '<S14>'  : 'TorqueVectoring/Subsystem/Yaw rate controller/Feedback controller type/PI controller type/Adaptive MPC Controller/MPC/MPC Matrix Signal Check'
 * '<S15>'  : 'TorqueVectoring/Subsystem/Yaw rate controller/Feedback controller type/PI controller type/Adaptive MPC Controller/MPC/MPC Matrix Signal Check A'
 * '<S16>'  : 'TorqueVectoring/Subsystem/Yaw rate controller/Feedback controller type/PI controller type/Adaptive MPC Controller/MPC/MPC Matrix Signal Check B'
 * '<S17>'  : 'TorqueVectoring/Subsystem/Yaw rate controller/Feedback controller type/PI controller type/Adaptive MPC Controller/MPC/MPC Matrix Signal Check C'
 * '<S18>'  : 'TorqueVectoring/Subsystem/Yaw rate controller/Feedback controller type/PI controller type/Adaptive MPC Controller/MPC/MPC Matrix Signal Check D'
 * '<S19>'  : 'TorqueVectoring/Subsystem/Yaw rate controller/Feedback controller type/PI controller type/Adaptive MPC Controller/MPC/MPC Matrix Signal Check DX'
 * '<S20>'  : 'TorqueVectoring/Subsystem/Yaw rate controller/Feedback controller type/PI controller type/Adaptive MPC Controller/MPC/MPC Matrix Signal Check U'
 * '<S21>'  : 'TorqueVectoring/Subsystem/Yaw rate controller/Feedback controller type/PI controller type/Adaptive MPC Controller/MPC/MPC Matrix Signal Check X'
 * '<S22>'  : 'TorqueVectoring/Subsystem/Yaw rate controller/Feedback controller type/PI controller type/Adaptive MPC Controller/MPC/MPC Matrix Signal Check Y'
 * '<S23>'  : 'TorqueVectoring/Subsystem/Yaw rate controller/Feedback controller type/PI controller type/Adaptive MPC Controller/MPC/MPC Matrix Signal Check1'
 * '<S24>'  : 'TorqueVectoring/Subsystem/Yaw rate controller/Feedback controller type/PI controller type/Adaptive MPC Controller/MPC/MPC Matrix Signal Check2'
 * '<S25>'  : 'TorqueVectoring/Subsystem/Yaw rate controller/Feedback controller type/PI controller type/Adaptive MPC Controller/MPC/MPC Preview Signal Check'
 * '<S26>'  : 'TorqueVectoring/Subsystem/Yaw rate controller/Feedback controller type/PI controller type/Adaptive MPC Controller/MPC/MPC Preview Signal Check1'
 * '<S27>'  : 'TorqueVectoring/Subsystem/Yaw rate controller/Feedback controller type/PI controller type/Adaptive MPC Controller/MPC/MPC Preview Signal Check2'
 * '<S28>'  : 'TorqueVectoring/Subsystem/Yaw rate controller/Feedback controller type/PI controller type/Adaptive MPC Controller/MPC/MPC Preview Signal Check3'
 * '<S29>'  : 'TorqueVectoring/Subsystem/Yaw rate controller/Feedback controller type/PI controller type/Adaptive MPC Controller/MPC/MPC Preview Signal Check4'
 * '<S30>'  : 'TorqueVectoring/Subsystem/Yaw rate controller/Feedback controller type/PI controller type/Adaptive MPC Controller/MPC/MPC Preview Signal Check5'
 * '<S31>'  : 'TorqueVectoring/Subsystem/Yaw rate controller/Feedback controller type/PI controller type/Adaptive MPC Controller/MPC/MPC Preview Signal Check6'
 * '<S32>'  : 'TorqueVectoring/Subsystem/Yaw rate controller/Feedback controller type/PI controller type/Adaptive MPC Controller/MPC/MPC Preview Signal Check7'
 * '<S33>'  : 'TorqueVectoring/Subsystem/Yaw rate controller/Feedback controller type/PI controller type/Adaptive MPC Controller/MPC/MPC Preview Signal Check8'
 * '<S34>'  : 'TorqueVectoring/Subsystem/Yaw rate controller/Feedback controller type/PI controller type/Adaptive MPC Controller/MPC/MPC Scalar Signal Check'
 * '<S35>'  : 'TorqueVectoring/Subsystem/Yaw rate controller/Feedback controller type/PI controller type/Adaptive MPC Controller/MPC/MPC Scalar Signal Check1'
 * '<S36>'  : 'TorqueVectoring/Subsystem/Yaw rate controller/Feedback controller type/PI controller type/Adaptive MPC Controller/MPC/MPC Scalar Signal Check2'
 * '<S37>'  : 'TorqueVectoring/Subsystem/Yaw rate controller/Feedback controller type/PI controller type/Adaptive MPC Controller/MPC/MPC Vector Signal Check'
 * '<S38>'  : 'TorqueVectoring/Subsystem/Yaw rate controller/Feedback controller type/PI controller type/Adaptive MPC Controller/MPC/MPC Vector Signal Check1'
 * '<S39>'  : 'TorqueVectoring/Subsystem/Yaw rate controller/Feedback controller type/PI controller type/Adaptive MPC Controller/MPC/MPC Vector Signal Check6'
 * '<S40>'  : 'TorqueVectoring/Subsystem/Yaw rate controller/Feedback controller type/PI controller type/Adaptive MPC Controller/MPC/moorx'
 * '<S41>'  : 'TorqueVectoring/Subsystem/Yaw rate controller/Feedback controller type/PI controller type/Adaptive MPC Controller/MPC/optimizer'
 * '<S42>'  : 'TorqueVectoring/Subsystem/Yaw rate controller/Feedback controller type/PI controller type/Adaptive MPC Controller/MPC/optimizer/FixedHorizonOptimizer'
 * '<S43>'  : 'TorqueVectoring/Subsystem/Yaw rate reference calculation/MATLAB Function'
 */
#endif                                 /* RTW_HEADER_TorqueVectoring_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
