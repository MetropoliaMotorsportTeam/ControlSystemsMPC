/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: TorqueVectoring.c
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

#include "TorqueVectoring.h"

/* Named constants for MATLAB Function: '<S41>/FixedHorizonOptimizer' */
#define Wdu                            (0.010000000000000002)
#define Wu                             (0.0)
#define ny                             (3)
#define NumBitsPerChar                 8U

/* Block signals and states (default storage) */
DW rtDW;

/* External inputs (root inport signals with default storage) */
ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
ExtY rtY;

/* Real-time model */
static RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;
extern real_T rt_powd_snf(real_T u0, real_T u1);

/* Forward declaration for local functions */
static void WtMult(real_T W, const real_T M[20], real_T WM[20]);
static int32_T xpotrf(real_T b_A[4]);
static void trisolve(const real_T b_A[4], real_T b_B[4]);
static void mpcblock_optimizer(const real_T rseq[30], const real_T vseq[11],
  const real_T x[6], real_T old_u, boolean_T iA, const real_T b_utarget[10],
  real_T b_uoff, const real_T b_A[36], const real_T Bu[66], const real_T Bv[66],
  const real_T b_C[18], const real_T Dv[33], real_T *u, real_T useq[11], real_T *
  status, boolean_T *iAout);
static real_T rtGetInf(void);
static real32_T rtGetInfF(void);
static real_T rtGetMinusInf(void);
static real32_T rtGetMinusInfF(void);
static real_T rtGetNaN(void);
static real32_T rtGetNaNF(void);
extern real_T rtInf;
extern real_T rtMinusInf;
extern real_T rtNaN;
extern real32_T rtInfF;
extern real32_T rtMinusInfF;
extern real32_T rtNaNF;
static void rt_InitInfAndNaN(size_t realSize);
static boolean_T rtIsInf(real_T value);
static boolean_T rtIsInfF(real32_T value);
static boolean_T rtIsNaN(real_T value);
static boolean_T rtIsNaNF(real32_T value);
typedef struct {
  struct {
    uint32_T wordH;
    uint32_T wordL;
  } words;
} BigEndianIEEEDouble;

typedef struct {
  struct {
    uint32_T wordL;
    uint32_T wordH;
  } words;
} LittleEndianIEEEDouble;

typedef struct {
  union {
    real32_T wordLreal;
    uint32_T wordLuint;
  } wordL;
} IEEESingle;

real_T rtInf;
real_T rtMinusInf;
real_T rtNaN;
real32_T rtInfF;
real32_T rtMinusInfF;
real32_T rtNaNF;

/*
 * Initialize rtInf needed by the generated code.
 * Inf is initialized as non-signaling. Assumes IEEE.
 */
static real_T rtGetInf(void)
{
  size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
  real_T inf = 0.0;
  if (bitsPerReal == 32U) {
    inf = rtGetInfF();
  } else {
    union {
      LittleEndianIEEEDouble bitVal;
      real_T fltVal;
    } tmpVal;

    tmpVal.bitVal.words.wordH = 0x7FF00000U;
    tmpVal.bitVal.words.wordL = 0x00000000U;
    inf = tmpVal.fltVal;
  }

  return inf;
}

/*
 * Initialize rtInfF needed by the generated code.
 * Inf is initialized as non-signaling. Assumes IEEE.
 */
static real32_T rtGetInfF(void)
{
  IEEESingle infF;
  infF.wordL.wordLuint = 0x7F800000U;
  return infF.wordL.wordLreal;
}

/*
 * Initialize rtMinusInf needed by the generated code.
 * Inf is initialized as non-signaling. Assumes IEEE.
 */
static real_T rtGetMinusInf(void)
{
  size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
  real_T minf = 0.0;
  if (bitsPerReal == 32U) {
    minf = rtGetMinusInfF();
  } else {
    union {
      LittleEndianIEEEDouble bitVal;
      real_T fltVal;
    } tmpVal;

    tmpVal.bitVal.words.wordH = 0xFFF00000U;
    tmpVal.bitVal.words.wordL = 0x00000000U;
    minf = tmpVal.fltVal;
  }

  return minf;
}

/*
 * Initialize rtMinusInfF needed by the generated code.
 * Inf is initialized as non-signaling. Assumes IEEE.
 */
static real32_T rtGetMinusInfF(void)
{
  IEEESingle minfF;
  minfF.wordL.wordLuint = 0xFF800000U;
  return minfF.wordL.wordLreal;
}

/*
 * Initialize rtNaN needed by the generated code.
 * NaN is initialized as non-signaling. Assumes IEEE.
 */
static real_T rtGetNaN(void)
{
  size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
  real_T nan = 0.0;
  if (bitsPerReal == 32U) {
    nan = rtGetNaNF();
  } else {
    union {
      LittleEndianIEEEDouble bitVal;
      real_T fltVal;
    } tmpVal;

    tmpVal.bitVal.words.wordH = 0xFFF80000U;
    tmpVal.bitVal.words.wordL = 0x00000000U;
    nan = tmpVal.fltVal;
  }

  return nan;
}

/*
 * Initialize rtNaNF needed by the generated code.
 * NaN is initialized as non-signaling. Assumes IEEE.
 */
static real32_T rtGetNaNF(void)
{
  IEEESingle nanF = { { 0.0F } };

  nanF.wordL.wordLuint = 0xFFC00000U;
  return nanF.wordL.wordLreal;
}

/*
 * Initialize the rtInf, rtMinusInf, and rtNaN needed by the
 * generated code. NaN is initialized as non-signaling. Assumes IEEE.
 */
static void rt_InitInfAndNaN(size_t realSize)
{
  (void) (realSize);
  rtNaN = rtGetNaN();
  rtNaNF = rtGetNaNF();
  rtInf = rtGetInf();
  rtInfF = rtGetInfF();
  rtMinusInf = rtGetMinusInf();
  rtMinusInfF = rtGetMinusInfF();
}

/* Test if value is infinite */
static boolean_T rtIsInf(real_T value)
{
  return (boolean_T)((value==rtInf || value==rtMinusInf) ? 1U : 0U);
}

/* Test if single-precision value is infinite */
static boolean_T rtIsInfF(real32_T value)
{
  return (boolean_T)(((value)==rtInfF || (value)==rtMinusInfF) ? 1U : 0U);
}

/* Test if value is not a number */
static boolean_T rtIsNaN(real_T value)
{
  boolean_T result = (boolean_T) 0;
  size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
  if (bitsPerReal == 32U) {
    result = rtIsNaNF((real32_T)value);
  } else {
    union {
      LittleEndianIEEEDouble bitVal;
      real_T fltVal;
    } tmpVal;

    tmpVal.fltVal = value;
    result = (boolean_T)((tmpVal.bitVal.words.wordH & 0x7FF00000) == 0x7FF00000 &&
                         ( (tmpVal.bitVal.words.wordH & 0x000FFFFF) != 0 ||
                          (tmpVal.bitVal.words.wordL != 0) ));
  }

  return result;
}

/* Test if single-precision value is not a number */
static boolean_T rtIsNaNF(real32_T value)
{
  IEEESingle tmp;
  tmp.wordL.wordLreal = value;
  return (boolean_T)( (tmp.wordL.wordLuint & 0x7F800000) == 0x7F800000 &&
                     (tmp.wordL.wordLuint & 0x007FFFFF) != 0 );
}

/* Function for MATLAB Function: '<S41>/FixedHorizonOptimizer' */
static void WtMult(real_T W, const real_T M[20], real_T WM[20])
{
  int32_T i;
  for (i = 0; i < 10; i++) {
    WM[i] = W * M[i];
    WM[i + 10] = M[i + 10] * W;
  }
}

/* Function for MATLAB Function: '<S41>/FixedHorizonOptimizer' */
static int32_T xpotrf(real_T b_A[4])
{
  int32_T info;
  int32_T ix;
  int32_T j;
  boolean_T exitg1;
  info = 0;
  j = 0;
  exitg1 = false;
  while ((!exitg1) && (j < 2)) {
    real_T ssq;
    int32_T idxAjj;
    idxAjj = (j << 1) + j;
    ssq = 0.0;
    if (j >= 1) {
      ssq = b_A[1] * b_A[1];
    }

    ssq = b_A[idxAjj] - ssq;
    if (ssq > 0.0) {
      ssq = sqrt(ssq);
      b_A[idxAjj] = ssq;
      if (j + 1 < 2) {
        ssq = 1.0 / ssq;
        for (ix = idxAjj + 1; ix < idxAjj + 2; ix++) {
          b_A[ix] *= ssq;
        }
      }

      j++;
    } else {
      b_A[idxAjj] = ssq;
      info = j + 1;
      exitg1 = true;
    }
  }

  return info;
}

real_T rt_powd_snf(real_T u0, real_T u1)
{
  real_T y;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else {
    real_T tmp;
    real_T tmp_0;
    tmp = fabs(u0);
    tmp_0 = fabs(u1);
    if (rtIsInf(u1)) {
      if (tmp == 1.0) {
        y = 1.0;
      } else if (tmp > 1.0) {
        if (u1 > 0.0) {
          y = (rtInf);
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = (rtInf);
      }
    } else if (tmp_0 == 0.0) {
      y = 1.0;
    } else if (tmp_0 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y = sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > floor(u1))) {
      y = (rtNaN);
    } else {
      y = pow(u0, u1);
    }
  }

  return y;
}

/* Function for MATLAB Function: '<S41>/FixedHorizonOptimizer' */
static void trisolve(const real_T b_A[4], real_T b_B[4])
{
  if (b_B[0] != 0.0) {
    b_B[0] /= b_A[0];
    b_B[1] -= b_B[0] * b_A[1];
  }

  if (b_B[1] != 0.0) {
    b_B[1] /= b_A[3];
  }

  if (b_B[2] != 0.0) {
    b_B[2] /= b_A[0];
    b_B[3] -= b_A[1] * b_B[2];
  }

  if (b_B[3] != 0.0) {
    b_B[3] /= b_A[3];
  }
}

/* Function for MATLAB Function: '<S41>/FixedHorizonOptimizer' */
static void mpcblock_optimizer(const real_T rseq[30], const real_T vseq[11],
  const real_T x[6], real_T old_u, boolean_T iA, const real_T b_utarget[10],
  real_T b_uoff, const real_T b_A[36], const real_T Bu[66], const real_T Bv[66],
  const real_T b_C[18], const real_T Dv[33], real_T *u, real_T useq[11], real_T *
  status, boolean_T *iAout)
{
  real_T c_Hv[330];
  real_T Su[300];
  real_T c_a[180];
  real_T WySuJm[60];
  real_T c_SuJm[60];
  real_T CA_0[33];
  real_T Sum_0[30];
  real_T b_a[30];
  real_T c_Kv[22];
  real_T I2Jm[20];
  real_T WuI2Jm[20];
  real_T tmp[20];
  real_T CA[18];
  real_T CA_1[18];
  real_T c_Kx[12];
  real_T c[4];
  real_T c_Linv[4];
  real_T c_SuJm_0[4];
  real_T Sum[3];
  real_T b_C_0[3];
  real_T b_a_0[2];
  real_T c_Ku1[2];
  real_T varargin_1[2];
  real_T normH;
  real_T s;
  int32_T CA_tmp;
  int32_T c_Hv_tmp;
  int32_T i;
  int32_T i_0;
  int32_T kidx;
  int16_T ixw;
  int8_T a[100];
  int8_T rows[3];
  static const int8_T c_A[100] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0,
    0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1,
    1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 1 };

  static const real_T b_b[20] = { 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  static const int8_T W[3] = { 1, 0, 0 };

  static const int8_T c_0[20] = { 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0 };

  boolean_T guard1 = false;
  memset(&useq[0], 0, 11U * sizeof(real_T));
  *iAout = false;
  for (i = 0; i < 3; i++) {
    Sum[i] = 0.0;
    b_C_0[i] = 0.0;
    for (c_Hv_tmp = 0; c_Hv_tmp < 6; c_Hv_tmp++) {
      CA_tmp = 3 * c_Hv_tmp + i;
      CA[CA_tmp] = 0.0;
      for (i_0 = 0; i_0 < 6; i_0++) {
        CA[CA_tmp] += b_C[3 * i_0 + i] * b_A[6 * c_Hv_tmp + i_0];
      }

      normH = b_C[CA_tmp];
      Sum[i] += normH * Bu[c_Hv_tmp];
      b_C_0[i] += normH * Bv[c_Hv_tmp];
    }

    c_Hv[i] = b_C_0[i];
    c_Hv[i + 30] = Dv[i];
  }

  for (i = 0; i < 9; i++) {
    c_Hv_tmp = (i + 2) * 30;
    c_Hv[c_Hv_tmp] = 0.0;
    c_Hv[c_Hv_tmp + 1] = 0.0;
    c_Hv[c_Hv_tmp + 2] = 0.0;
  }

  for (i = 0; i < 11; i++) {
    memset(&c_Hv[i * 30 + 3], 0, 27U * sizeof(real_T));
  }

  for (i = 0; i < 6; i++) {
    c_a[30 * i] = CA[3 * i];
    c_a[30 * i + 1] = CA[3 * i + 1];
    c_a[30 * i + 2] = CA[3 * i + 2];
    memset(&c_a[i * 30 + 3], 0, 27U * sizeof(real_T));
  }

  b_a[0] = Sum[0];
  b_a[1] = Sum[1];
  b_a[2] = Sum[2];
  memset(&b_a[3], 0, 27U * sizeof(real_T));
  Su[0] = Sum[0];
  Su[1] = Sum[1];
  Su[2] = Sum[2];
  for (i = 0; i < 9; i++) {
    c_Hv_tmp = (i + 1) * 30;
    Su[c_Hv_tmp] = 0.0;
    Su[c_Hv_tmp + 1] = 0.0;
    Su[c_Hv_tmp + 2] = 0.0;
  }

  for (i = 0; i < 10; i++) {
    memset(&Su[i * 30 + 3], 0, 27U * sizeof(real_T));
  }

  for (kidx = 0; kidx < 9; kidx++) {
    int8_T kidx_0;
    kidx_0 = (int8_T)((kidx + 1) * 3 + 1);
    for (i = 0; i < 3; i++) {
      rows[i] = (int8_T)(i + kidx_0);
      normH = 0.0;
      for (c_Hv_tmp = 0; c_Hv_tmp < 6; c_Hv_tmp++) {
        normH += CA[3 * c_Hv_tmp + i] * Bu[c_Hv_tmp];
      }

      Sum[i] += normH;
    }

    b_a[rows[0] - 1] = Sum[0];
    Sum_0[0] = Sum[0];
    b_a[rows[1] - 1] = Sum[1];
    Sum_0[1] = Sum[1];
    b_a[rows[2] - 1] = Sum[2];
    Sum_0[2] = Sum[2];
    for (i = 0; i < 9; i++) {
      c_Hv_tmp = (i + 1) * 3;
      Sum_0[c_Hv_tmp] = Su[(30 * i + rows[0]) - 4];
      Sum_0[c_Hv_tmp + 1] = Su[(30 * i + rows[1]) - 4];
      Sum_0[c_Hv_tmp + 2] = Su[(30 * i + rows[2]) - 4];
    }

    for (i = 0; i < 10; i++) {
      Su[(rows[0] + 30 * i) - 1] = Sum_0[3 * i];
      Su[(rows[1] + 30 * i) - 1] = Sum_0[3 * i + 1];
      Su[(rows[2] + 30 * i) - 1] = Sum_0[3 * i + 2];
    }

    for (i = 0; i < 3; i++) {
      b_C_0[i] = 0.0;
      for (c_Hv_tmp = 0; c_Hv_tmp < 6; c_Hv_tmp++) {
        b_C_0[i] += CA[3 * c_Hv_tmp + i] * Bv[c_Hv_tmp];
      }

      CA_0[i] = b_C_0[i];
    }

    for (i = 0; i < 10; i++) {
      CA_tmp = (i + 1) * 3;
      CA_0[CA_tmp] = c_Hv[(30 * i + rows[0]) - 4];
      CA_0[CA_tmp + 1] = c_Hv[(30 * i + rows[1]) - 4];
      CA_0[CA_tmp + 2] = c_Hv[(30 * i + rows[2]) - 4];
    }

    for (i = 0; i < 11; i++) {
      c_Hv[(rows[0] + 30 * i) - 1] = CA_0[3 * i];
      c_Hv[(rows[1] + 30 * i) - 1] = CA_0[3 * i + 1];
      c_Hv[(rows[2] + 30 * i) - 1] = CA_0[3 * i + 2];
    }

    for (i = 0; i < 3; i++) {
      for (c_Hv_tmp = 0; c_Hv_tmp < 6; c_Hv_tmp++) {
        CA_tmp = 3 * c_Hv_tmp + i;
        CA_1[CA_tmp] = 0.0;
        for (i_0 = 0; i_0 < 6; i_0++) {
          CA_1[CA_tmp] += CA[3 * i_0 + i] * b_A[6 * c_Hv_tmp + i_0];
        }
      }
    }

    memcpy(&CA[0], &CA_1[0], 18U * sizeof(real_T));
    for (i = 0; i < 6; i++) {
      c_a[(rows[0] + 30 * i) - 1] = CA[3 * i];
      c_a[(rows[1] + 30 * i) - 1] = CA[3 * i + 1];
      c_a[(rows[2] + 30 * i) - 1] = CA[3 * i + 2];
    }
  }

  for (i = 0; i < 2; i++) {
    for (c_Hv_tmp = 0; c_Hv_tmp < 30; c_Hv_tmp++) {
      kidx = 30 * i + c_Hv_tmp;
      c_SuJm[kidx] = 0.0;
      for (i_0 = 0; i_0 < 10; i_0++) {
        c_SuJm[kidx] += Su[30 * i_0 + c_Hv_tmp] * b_b[10 * i + i_0];
      }
    }
  }

  kidx = -1;
  for (i = 0; i < 10; i++) {
    for (c_Hv_tmp = 0; c_Hv_tmp < 10; c_Hv_tmp++) {
      a[(kidx + c_Hv_tmp) + 1] = c_A[10 * i + c_Hv_tmp];
    }

    kidx += 10;
  }

  for (i = 0; i < 2; i++) {
    for (c_Hv_tmp = 0; c_Hv_tmp < 10; c_Hv_tmp++) {
      kidx = 10 * i + c_Hv_tmp;
      I2Jm[kidx] = 0.0;
      for (i_0 = 0; i_0 < 10; i_0++) {
        I2Jm[kidx] += (real_T)a[10 * i_0 + c_Hv_tmp] * b_b[10 * i + i_0];
      }
    }
  }

  ixw = 1;
  for (kidx = 0; kidx < 30; kidx++) {
    i = W[ixw - 1];
    WySuJm[kidx] = (real_T)i * c_SuJm[kidx];
    WySuJm[kidx + 30] = c_SuJm[kidx + 30] * (real_T)i;
    ixw++;
    if (ixw > 3) {
      ixw = 1;
    }
  }

  WtMult(Wu, I2Jm, WuI2Jm);
  WtMult(Wdu, b_b, tmp);
  for (i = 0; i < 2; i++) {
    for (c_Hv_tmp = 0; c_Hv_tmp < 2; c_Hv_tmp++) {
      kidx = (c_Hv_tmp << 1) + i;
      c_SuJm_0[kidx] = 0.0;
      for (i_0 = 0; i_0 < 30; i_0++) {
        c_SuJm_0[kidx] += c_SuJm[30 * i + i_0] * WySuJm[30 * c_Hv_tmp + i_0];
      }

      c[kidx] = 0.0;
      normH = 0.0;
      for (i_0 = 0; i_0 < 10; i_0++) {
        CA_tmp = 10 * c_Hv_tmp + i_0;
        normH += I2Jm[10 * i + i_0] * WuI2Jm[CA_tmp];
        c[kidx] += (real_T)c_0[(i_0 << 1) + i] * tmp[CA_tmp];
      }

      c_Linv[kidx] = (c_SuJm_0[kidx] + c[kidx]) + normH;
    }

    b_a_0[i] = 0.0;
    for (c_Hv_tmp = 0; c_Hv_tmp < 30; c_Hv_tmp++) {
      b_a_0[i] += WySuJm[30 * i + c_Hv_tmp] * b_a[c_Hv_tmp];
    }

    varargin_1[i] = 0.0;
    for (c_Hv_tmp = 0; c_Hv_tmp < 10; c_Hv_tmp++) {
      varargin_1[i] += WuI2Jm[10 * i + c_Hv_tmp];
    }

    c_Ku1[i] = b_a_0[i] + varargin_1[i];
  }

  for (i = 0; i < 20; i++) {
    WuI2Jm[i] = -WuI2Jm[i];
  }

  for (i = 0; i < 6; i++) {
    for (c_Hv_tmp = 0; c_Hv_tmp < 2; c_Hv_tmp++) {
      kidx = 6 * c_Hv_tmp + i;
      c_Kx[kidx] = 0.0;
      for (i_0 = 0; i_0 < 30; i_0++) {
        c_Kx[kidx] += c_a[30 * i + i_0] * WySuJm[30 * c_Hv_tmp + i_0];
      }
    }
  }

  for (i = 0; i < 11; i++) {
    for (c_Hv_tmp = 0; c_Hv_tmp < 2; c_Hv_tmp++) {
      kidx = 11 * c_Hv_tmp + i;
      c_Kv[kidx] = 0.0;
      for (i_0 = 0; i_0 < 30; i_0++) {
        c_Kv[kidx] += c_Hv[30 * i + i_0] * WySuJm[30 * c_Hv_tmp + i_0];
      }
    }
  }

  for (i = 0; i < 60; i++) {
    WySuJm[i] = -WySuJm[i];
  }

  kidx = 0;
  c_SuJm_0[0] = c_Linv[0];
  c_SuJm_0[1] = c_Linv[1];
  c_SuJm_0[2] = c_Linv[2];
  c_SuJm_0[3] = c_Linv[3];
  i = xpotrf(c_SuJm_0);
  guard1 = false;
  if (i == 0) {
    if (c_SuJm_0[0] > c_SuJm_0[3]) {
      normH = c_SuJm_0[3];
    } else if (rtIsNaN(c_SuJm_0[0])) {
      if (!rtIsNaN(c_SuJm_0[3])) {
        normH = c_SuJm_0[3];
      } else {
        normH = c_SuJm_0[0];
      }
    } else {
      normH = c_SuJm_0[0];
    }

    if (normH > 1.4901161193847656E-7) {
    } else {
      guard1 = true;
    }
  } else {
    guard1 = true;
  }

  if (guard1) {
    boolean_T exitg2;
    normH = 0.0;
    i = 0;
    exitg2 = false;
    while ((!exitg2) && (i < 2)) {
      s = fabs(c_Linv[i + 2]) + fabs(c_Linv[i]);
      if (rtIsNaN(s)) {
        normH = (rtNaN);
        exitg2 = true;
      } else {
        if (s > normH) {
          normH = s;
        }

        i++;
      }
    }

    if (normH >= 1.0E+10) {
      kidx = 2;
    } else {
      boolean_T exitg1;
      i = 0;
      exitg1 = false;
      while ((!exitg1) && (i <= 4)) {
        boolean_T guard2 = false;
        normH = rt_powd_snf(10.0, (real_T)i) * 1.4901161193847656E-7;
        c_Linv[0] += normH;
        c_SuJm_0[0] = c_Linv[0];
        c_SuJm_0[1] = c_Linv[1];
        c_SuJm_0[2] = c_Linv[2];
        c_Linv[3] += normH;
        c_SuJm_0[3] = c_Linv[3];
        kidx = xpotrf(c_SuJm_0);
        guard2 = false;
        if (kidx == 0) {
          if (c_SuJm_0[0] > c_SuJm_0[3]) {
            normH = c_SuJm_0[3];
          } else if (rtIsNaN(c_SuJm_0[0])) {
            if (!rtIsNaN(c_SuJm_0[3])) {
              normH = c_SuJm_0[3];
            } else {
              normH = c_SuJm_0[0];
            }
          } else {
            normH = c_SuJm_0[0];
          }

          if (normH > 1.4901161193847656E-7) {
            kidx = 1;
            exitg1 = true;
          } else {
            guard2 = true;
          }
        } else {
          guard2 = true;
        }

        if (guard2) {
          kidx = 3;
          i++;
        }
      }
    }
  }

  if (kidx > 1) {
    *u = old_u + b_uoff;
    for (i = 0; i < 11; i++) {
      useq[i] = *u;
    }

    *status = -2.0;
  } else {
    c_Linv[0] = 1.0;
    c_Linv[1] = 0.0;
    c_Linv[2] = 0.0;
    c_Linv[3] = 1.0;
    trisolve(c_SuJm_0, c_Linv);
    *iAout = iA;
    for (kidx = 0; kidx < 2; kidx++) {
      real_T WuI2Jm_0;
      real_T c_Kv_0;
      c_SuJm_0[kidx] = 0.0;
      i = kidx << 1;
      normH = c_Linv[i];
      c_SuJm_0[kidx] += normH * c_Linv[0];
      s = c_Linv[i + 1];
      c_SuJm_0[kidx] += s * c_Linv[1];
      c_SuJm_0[kidx + 2] = 0.0;
      c_SuJm_0[kidx + 2] += normH * c_Linv[2];
      c_SuJm_0[kidx + 2] += s * c_Linv[3];
      normH = 0.0;
      for (i = 0; i < 6; i++) {
        normH += c_Kx[6 * kidx + i] * x[i];
      }

      s = 0.0;
      for (i = 0; i < 30; i++) {
        s += WySuJm[30 * kidx + i] * rseq[i];
      }

      c_Kv_0 = 0.0;
      for (i = 0; i < 11; i++) {
        c_Kv_0 += c_Kv[11 * kidx + i] * vseq[i];
      }

      WuI2Jm_0 = 0.0;
      for (i = 0; i < 10; i++) {
        WuI2Jm_0 += WuI2Jm[10 * kidx + i] * b_utarget[i];
      }

      b_a_0[kidx] = (((normH + s) + c_Ku1[kidx] * old_u) + c_Kv_0) + WuI2Jm_0;
      varargin_1[kidx] = 0.0;
    }

    varargin_1[0] -= c_SuJm_0[0] * b_a_0[0];
    *status = 1.0;
    *u = ((varargin_1[0] - b_a_0[1] * c_SuJm_0[2]) + old_u) + b_uoff;
  }
}

/* Model step function */
void TorqueVectoring_step(void)
{
  real_T CovMat[81];
  real_T Bu[66];
  real_T Bv[66];
  real_T b_tmp[63];
  real_T b_B[48];
  real_T L_tmp[36];
  real_T L_tmp_0[36];
  real_T L_tmp_1[36];
  real_T b_A[36];
  real_T Dv[33];
  real_T rseq[30];
  real_T Cm_0[18];
  real_T L[18];
  real_T b_C[18];
  real_T tmp[18];
  real_T tmp_0[18];
  real_T rtb_useq[11];
  real_T vseq[11];
  real_T b_utarget[10];
  real_T rtb_A[9];
  real_T rtb_C[9];
  real_T b_xoff[6];
  real_T xk[6];
  real_T xk_0[6];
  real_T Y[3];
  real_T rtb_VectorConcatenate[3];
  real_T rtb_VectorConcatenate1[3];
  real_T rtb_X[3];
  real_T rtb_C_tmp_0;
  real_T rtb_C_tmp_1;
  real_T rtb_C_tmp_2;
  real_T rtb_C_tmp_3;
  real_T rtb_Desiredyawratereferencedegs;
  real_T rtb_Gain_e;
  int32_T i;
  int32_T r1;
  int32_T r3;
  int32_T rtb_C_tmp;
  int32_T rtemp;
  int8_T Cm[198];
  int8_T c_B[9];
  int8_T UnknownIn[7];
  static const real_T c[36] = { -0.01, 0.0, 0.0, 0.0, 0.0, 0.0, -100.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.005, 0.0076500000000000005, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    1.0 };

  static const real_T d[48] = { 0.0, 0.01, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.001, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.001,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.001, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  static const int8_T e[18] = { 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0,
    0, 1 };

  static const int8_T b_D[24] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    0, 0, 0, 1, 0, 0, 0, 1 };

  int32_T rtb_C_tmp_tmp;
  boolean_T tmp_1;

  /* SignalConversion generated from: '<S10>/Vector Concatenate' incorporates:
   *  Inport: '<Root>/LateralVelocity'
   */
  rtb_VectorConcatenate[0] = rtU.LateralVelocity;

  /* SignalConversion generated from: '<S10>/Vector Concatenate' incorporates:
   *  Inport: '<Root>/VehicleYawRate'
   */
  rtb_VectorConcatenate[1] = rtU.VehicleYawRate;

  /* SignalConversion generated from: '<S10>/Vector Concatenate' incorporates:
   *  Inport: '<Root>/StrAngleDeg'
   */
  rtb_VectorConcatenate[2] = rtU.StrAngleDeg;

  /* Fcn: '<S6>/Fcn2' incorporates:
   *  Inport: '<Root>/VehicleSpeed'
   */
  rtb_Gain_e = ((real_T)(rtU.VehicleSpeed == 0.0) + rtU.VehicleSpeed) +
    2.2204460492503131e-16;

  /* Product: '<S6>/Divide' incorporates:
   *  Constant: '<S6>/Constant'
   *  Gain: '<S6>/Gain'
   *  Gain: '<S6>/Gain1'
   *  Inport: '<Root>/StrAngleDeg'
   *  Math: '<S6>/Square'
   *  Product: '<S6>/Product'
   *  Sum: '<S6>/Plus'
   */
  rtb_Desiredyawratereferencedegs = 0.2 * rtU.StrAngleDeg * rtb_Gain_e /
    (rtb_Gain_e * rtb_Gain_e * 0.0 + 1.53);

  /* Gain: '<S6>/Gain2' incorporates:
   *  Product: '<S6>/Divide1'
   */
  rtb_Gain_e = 1.0 / rtb_Gain_e * 19.62 * 57.295779513082323;

  /* MATLAB Function: '<S6>/MATLAB Function' */
  if (fabs(rtb_Desiredyawratereferencedegs) < rtb_Gain_e) {
    rtb_VectorConcatenate1[1] = rtb_Desiredyawratereferencedegs;
  } else {
    if (rtb_Desiredyawratereferencedegs < 0.0) {
      rtb_Desiredyawratereferencedegs = -1.0;
    } else if (rtb_Desiredyawratereferencedegs > 0.0) {
      rtb_Desiredyawratereferencedegs = 1.0;
    } else if (rtb_Desiredyawratereferencedegs == 0.0) {
      rtb_Desiredyawratereferencedegs = 0.0;
    } else {
      rtb_Desiredyawratereferencedegs = (rtNaN);
    }

    rtb_VectorConcatenate1[1] = rtb_Gain_e * rtb_Desiredyawratereferencedegs;
  }

  /* End of MATLAB Function: '<S6>/MATLAB Function' */

  /* MATLAB Function: '<S10>/MATLAB Function' incorporates:
   *  Inport: '<Root>/LateralVelocity'
   *  Inport: '<Root>/StrAngleDeg'
   *  Inport: '<Root>/VehicleSpeed'
   *  Inport: '<Root>/VehicleYawRate'
   */
  rtb_A[0] = -0.01;
  rtb_A[3] = ((-(rtU.VehicleSpeed * rtU.VehicleSpeed) * 200.0 - 0.765) + 0.765) /
    200.0;
  rtb_A[6] = 0.005;
  rtb_A[1] = 0.0;
  rtb_A[2] = 0.0;
  rtb_A[4] = 0.0;
  rtb_A[5] = 0.0;
  rtb_A[7] = 0.0076500000000000005;
  rtb_A[8] = 0.0;
  memset(&rtb_C[0], 0, 9U * sizeof(real_T));
  rtb_X[0] = rtU.LateralVelocity;
  rtb_X[1] = rtU.VehicleYawRate;
  rtb_X[2] = rtU.StrAngleDeg;
  rtb_C[0] = 1.0;

  /* MATLAB Function: '<S41>/FixedHorizonOptimizer' incorporates:
   *  MATLAB Function: '<S10>/MATLAB Function'
   */
  Y[0] = 0.0;

  /* MATLAB Function: '<S10>/MATLAB Function' */
  rtb_C[4] = 1.0;

  /* MATLAB Function: '<S41>/FixedHorizonOptimizer' incorporates:
   *  MATLAB Function: '<S10>/MATLAB Function'
   */
  Y[1] = 0.01;

  /* MATLAB Function: '<S10>/MATLAB Function' */
  rtb_C[8] = 1.0;

  /* MATLAB Function: '<S41>/FixedHorizonOptimizer' incorporates:
   *  Inport: '<Root>/LateralVelocity'
   *  Inport: '<Root>/StrAngleDeg'
   *  Inport: '<Root>/VehicleYawRate'
   *  MATLAB Function: '<S10>/MATLAB Function'
   *  Memory: '<S13>/LastPcov'
   *  Memory: '<S13>/last_x'
   */
  Y[2] = 0.0;
  memset(&Bu[0], 0, 66U * sizeof(real_T));
  memset(&Bv[0], 0, 66U * sizeof(real_T));
  memset(&Dv[0], 0, 33U * sizeof(real_T));
  memset(&Cm[0], 0, 198U * sizeof(int8_T));
  memcpy(&b_A[0], &c[0], 36U * sizeof(real_T));
  memcpy(&b_B[0], &d[0], 48U * sizeof(real_T));
  for (i = 0; i < 18; i++) {
    b_C[i] = e[i];
  }

  for (i = 0; i < 3; i++) {
    b_B[i] = Y[i];
    b_C[3 * i] = rtb_C[3 * i];
    b_A[6 * i] = rtb_A[3 * i];
    r3 = 3 * i + 1;
    b_C[r3] = rtb_C[r3];
    b_A[6 * i + 1] = rtb_A[r3];
    r3 = 3 * i + 2;
    b_C[r3] = rtb_C[r3];
    b_A[6 * i + 2] = rtb_A[r3];
  }

  for (i = 0; i < 6; i++) {
    Bu[i] = b_B[i];
    Bv[i] = b_B[i + 6];
    Cm[3 * i] = (int8_T)b_C[3 * i];
    r3 = 3 * i + 1;
    Cm[r3] = (int8_T)b_C[r3];
    r3 = 3 * i + 2;
    Cm[r3] = (int8_T)b_C[r3];
  }

  for (i = 0; i < 7; i++) {
    UnknownIn[i] = 0;
  }

  UnknownIn[0] = 1;
  for (i = 0; i < 6; i++) {
    UnknownIn[i + 1] = (int8_T)(i + 3);
  }

  for (i = 0; i < 7; i++) {
    for (r3 = 0; r3 < 6; r3++) {
      b_tmp[r3 + 9 * i] = b_B[(UnknownIn[i] - 1) * 6 + r3];
    }

    r3 = (UnknownIn[i] - 1) * 3;
    b_tmp[9 * i + 6] = b_D[r3];
    b_tmp[9 * i + 7] = b_D[r3 + 1];
    b_tmp[9 * i + 8] = b_D[r3 + 2];
  }

  for (i = 0; i < 9; i++) {
    for (r3 = 0; r3 < 9; r3++) {
      rtemp = 9 * r3 + i;
      CovMat[rtemp] = 0.0;
      for (r1 = 0; r1 < 7; r1++) {
        CovMat[rtemp] += b_tmp[9 * r1 + i] * b_tmp[9 * r1 + r3];
      }
    }
  }

  Dv[0] = 0.0;
  Dv[1] = 0.0;
  Dv[2] = 0.0;
  for (i = 0; i < 6; i++) {
    b_xoff[i] = 0.0;
  }

  Y[0] = rtU.LateralVelocity;
  Y[1] = rtU.VehicleYawRate;
  Y[2] = rtU.StrAngleDeg;
  memset(&b_utarget[0], 0, 10U * sizeof(real_T));
  for (i = 0; i < 3; i++) {
    b_xoff[i] = rtb_X[i];
    Bv[i] = (rtb_A[i + 3] * rtU.VehicleYawRate + rtb_A[i] * rtU.LateralVelocity)
      + rtb_A[i + 6] * rtU.StrAngleDeg;
  }

  for (r1 = 0; r1 < 11; r1++) {
    vseq[r1] = 1.0;
  }

  for (r1 = 0; r1 < 10; r1++) {
    rseq[r1 * ny] = rtU.LateralVelocity - rtU.LateralVelocity;
    rseq[r1 * ny + 1] = rtb_VectorConcatenate1[1] - rtU.VehicleYawRate;
    rseq[r1 * ny + 2] = rtU.StrAngleDeg - rtU.StrAngleDeg;
  }

  for (i = 0; i < 9; i++) {
    c_B[i] = 0;
  }

  for (r1 = 0; r1 < 3; r1++) {
    c_B[r1 + 3 * r1] = 1;
    for (i = 0; i < 6; i++) {
      rtemp = 3 * i + r1;
      L[i + 6 * r1] = Cm[rtemp];
      Cm_0[rtemp] = 0.0;
      for (r3 = 0; r3 < 6; r3++) {
        Cm_0[rtemp] += (real_T)Cm[3 * r3 + r1] * rtDW.LastPcov_PreviousInput[6 *
          i + r3];
      }
    }
  }

  for (i = 0; i < 3; i++) {
    for (r3 = 0; r3 < 3; r3++) {
      rtb_Gain_e = 0.0;
      for (r1 = 0; r1 < 6; r1++) {
        rtb_Gain_e += Cm_0[3 * r1 + i] * L[6 * r3 + r1];
      }

      rtb_A[i + 3 * r3] = CovMat[((r3 + 6) * 9 + i) + 6] + rtb_Gain_e;
    }
  }

  r1 = 0;
  i = 1;
  r3 = 2;
  rtb_Gain_e = fabs(rtb_A[0]);
  rtb_Desiredyawratereferencedegs = fabs(rtb_A[1]);
  if (rtb_Desiredyawratereferencedegs > rtb_Gain_e) {
    rtb_Gain_e = rtb_Desiredyawratereferencedegs;
    r1 = 1;
    i = 0;
  }

  if (fabs(rtb_A[2]) > rtb_Gain_e) {
    r1 = 2;
    i = 1;
    r3 = 0;
  }

  rtb_A[i] /= rtb_A[r1];
  rtb_A[r3] /= rtb_A[r1];
  rtb_A[i + 3] -= rtb_A[r1 + 3] * rtb_A[i];
  rtb_A[r3 + 3] -= rtb_A[r1 + 3] * rtb_A[r3];
  rtb_A[i + 6] -= rtb_A[r1 + 6] * rtb_A[i];
  rtb_A[r3 + 6] -= rtb_A[r1 + 6] * rtb_A[r3];
  if (fabs(rtb_A[r3 + 3]) > fabs(rtb_A[i + 3])) {
    rtemp = i;
    i = r3;
    r3 = rtemp;
  }

  rtb_A[r3 + 3] /= rtb_A[i + 3];
  rtb_A[r3 + 6] -= rtb_A[r3 + 3] * rtb_A[i + 6];
  rtb_C[3 * r1] = (real_T)c_B[0] / rtb_A[r1];
  rtb_Desiredyawratereferencedegs = rtb_A[r1 + 3];
  rtb_C[3 * i] = (real_T)c_B[3] - rtb_C[3 * r1] *
    rtb_Desiredyawratereferencedegs;
  rtb_Gain_e = rtb_A[r1 + 6];
  rtb_C[3 * r3] = (real_T)c_B[6] - rtb_C[3 * r1] * rtb_Gain_e;
  rtb_C_tmp_0 = rtb_A[i + 3];
  rtb_C[3 * i] /= rtb_C_tmp_0;
  rtb_C_tmp_1 = rtb_A[i + 6];
  rtb_C[3 * r3] -= rtb_C[3 * i] * rtb_C_tmp_1;
  rtb_C_tmp_2 = rtb_A[r3 + 6];
  rtb_C[3 * r3] /= rtb_C_tmp_2;
  rtb_C_tmp_3 = rtb_A[r3 + 3];
  rtb_C[3 * i] -= rtb_C[3 * r3] * rtb_C_tmp_3;
  rtb_C[3 * r1] -= rtb_C[3 * r3] * rtb_A[r3];
  rtb_C[3 * r1] -= rtb_C[3 * i] * rtb_A[i];
  rtemp = 3 * r1 + 1;
  rtb_C[rtemp] = (real_T)c_B[1] / rtb_A[r1];
  rtb_C_tmp = 3 * i + 1;
  rtb_C[rtb_C_tmp] = (real_T)c_B[4] - rtb_C[rtemp] *
    rtb_Desiredyawratereferencedegs;
  rtb_C_tmp_tmp = 3 * r3 + 1;
  rtb_C[rtb_C_tmp_tmp] = (real_T)c_B[7] - rtb_C[rtemp] * rtb_Gain_e;
  rtb_C[rtb_C_tmp] /= rtb_C_tmp_0;
  rtb_C[rtb_C_tmp_tmp] -= rtb_C[rtb_C_tmp] * rtb_C_tmp_1;
  rtb_C[rtb_C_tmp_tmp] /= rtb_C_tmp_2;
  rtb_C[rtb_C_tmp] -= rtb_C[rtb_C_tmp_tmp] * rtb_C_tmp_3;
  rtb_C[rtemp] -= rtb_C[rtb_C_tmp_tmp] * rtb_A[r3];
  rtb_C[rtemp] -= rtb_C[rtb_C_tmp] * rtb_A[i];
  rtemp = 3 * r1 + 2;
  rtb_C[rtemp] = (real_T)c_B[2] / rtb_A[r1];
  rtb_C_tmp = 3 * i + 2;
  rtb_C[rtb_C_tmp] = (real_T)c_B[5] - rtb_C[rtemp] *
    rtb_Desiredyawratereferencedegs;
  rtb_C_tmp_tmp = 3 * r3 + 2;
  rtb_C[rtb_C_tmp_tmp] = (real_T)c_B[8] - rtb_C[rtemp] * rtb_Gain_e;
  rtb_C[rtb_C_tmp] /= rtb_C_tmp_0;
  rtb_C[rtb_C_tmp_tmp] -= rtb_C[rtb_C_tmp] * rtb_C_tmp_1;
  rtb_C[rtb_C_tmp_tmp] /= rtb_C_tmp_2;
  rtb_C[rtb_C_tmp] -= rtb_C[rtb_C_tmp_tmp] * rtb_C_tmp_3;
  rtb_C[rtemp] -= rtb_C[rtb_C_tmp_tmp] * rtb_A[r3];
  rtb_C[rtemp] -= rtb_C[rtb_C_tmp] * rtb_A[i];
  for (i = 0; i < 6; i++) {
    for (r3 = 0; r3 < 6; r3++) {
      rtemp = 6 * r3 + i;
      L_tmp[rtemp] = 0.0;
      for (r1 = 0; r1 < 6; r1++) {
        L_tmp[rtemp] += b_A[6 * r1 + i] * rtDW.LastPcov_PreviousInput[6 * r3 +
          r1];
      }
    }

    for (r3 = 0; r3 < 3; r3++) {
      rtb_Gain_e = 0.0;
      for (r1 = 0; r1 < 6; r1++) {
        rtb_Gain_e += L_tmp[6 * r1 + i] * L[6 * r3 + r1];
      }

      Cm_0[i + 6 * r3] = CovMat[(r3 + 6) * 9 + i] + rtb_Gain_e;
    }
  }

  for (i = 0; i < 6; i++) {
    for (r3 = 0; r3 < 3; r3++) {
      rtemp = 6 * r3 + i;
      L[rtemp] = 0.0;
      L[rtemp] += rtb_C[3 * r3] * Cm_0[i];
      L[rtemp] += rtb_C[3 * r3 + 1] * Cm_0[i + 6];
      L[rtemp] += rtb_C[3 * r3 + 2] * Cm_0[i + 12];
    }

    xk[i] = rtDW.last_x_PreviousInput[i] - b_xoff[i];
  }

  for (i = 0; i < 3; i++) {
    rtb_Gain_e = 0.0;
    for (r3 = 0; r3 < 6; r3++) {
      rtb_Gain_e += (real_T)Cm[3 * r3 + i] * xk[r3];
    }

    rtb_VectorConcatenate1[i] = (rtb_VectorConcatenate[i] - Y[i]) - rtb_Gain_e;
  }

  for (i = 0; i < 6; i++) {
    for (r3 = 0; r3 < 3; r3++) {
      r1 = 6 * r3 + i;
      tmp[r1] = 0.0;
      for (rtemp = 0; rtemp < 6; rtemp++) {
        tmp[r1] += rtDW.LastPcov_PreviousInput[6 * rtemp + i] * (real_T)Cm[3 *
          rtemp + r3];
      }
    }

    rtb_Gain_e = 0.0;
    for (r3 = 0; r3 < 3; r3++) {
      r1 = 6 * r3 + i;
      tmp_0[r1] = 0.0;
      tmp_0[r1] += rtb_C[3 * r3] * tmp[i];
      tmp_0[r1] += rtb_C[3 * r3 + 1] * tmp[i + 6];
      tmp_0[r1] += rtb_C[3 * r3 + 2] * tmp[i + 12];
      rtb_Gain_e += tmp_0[r1] * rtb_VectorConcatenate1[r3];
    }

    xk_0[i] = xk[i] + rtb_Gain_e;
  }

  /* Update for Memory: '<S13>/Memory' incorporates:
   *  MATLAB Function: '<S10>/MATLAB Function'
   *  MATLAB Function: '<S41>/FixedHorizonOptimizer'
   *  UnitDelay: '<S13>/last_mv'
   */
  mpcblock_optimizer(rseq, vseq, xk_0, rtDW.last_mv_DSTATE,
                     rtDW.Memory_PreviousInput, b_utarget, 0.0, b_A, Bu, Bv, b_C,
                     Dv, &rtb_Desiredyawratereferencedegs, rtb_useq, &rtb_Gain_e,
                     &tmp_1);
  rtDW.Memory_PreviousInput = tmp_1;

  /* MATLAB Function: '<S41>/FixedHorizonOptimizer' */
  for (i = 0; i < 6; i++) {
    for (r3 = 0; r3 < 6; r3++) {
      rtemp = 6 * r3 + i;
      L_tmp_0[rtemp] = 0.0;
      for (r1 = 0; r1 < 6; r1++) {
        L_tmp_0[rtemp] += L_tmp[6 * r1 + i] * b_A[6 * r1 + r3];
      }

      L_tmp_1[rtemp] = 0.0;
      L_tmp_1[rtemp] += Cm_0[i] * L[r3];
      L_tmp_1[rtemp] += Cm_0[i + 6] * L[r3 + 6];
      L_tmp_1[rtemp] += Cm_0[i + 12] * L[r3 + 12];
    }
  }

  /* DeadZone: '<S3>/Dead Zone' incorporates:
   *  Inport: '<Root>/StrAngleDeg'
   */
  if (rtU.StrAngleDeg > 10.0) {
    rtb_Gain_e = rtU.StrAngleDeg - 10.0;
  } else if (rtU.StrAngleDeg >= -10.0) {
    rtb_Gain_e = 0.0;
  } else {
    rtb_Gain_e = rtU.StrAngleDeg - -10.0;
  }

  /* End of DeadZone: '<S3>/Dead Zone' */

  /* Abs: '<S3>/Abs' */
  rtb_Gain_e = fabs(rtb_Gain_e);

  /* Signum: '<S3>/Sign' */
  if (rtb_Gain_e > 0.0) {
    rtb_Gain_e = 1.0;
  } else if (rtb_Gain_e == 0.0) {
    rtb_Gain_e = 0.0;
  } else {
    rtb_Gain_e = (rtNaN);
  }

  /* End of Signum: '<S3>/Sign' */

  /* Saturate: '<S8>/Yaw moment saturation' incorporates:
   *  MATLAB Function: '<S41>/FixedHorizonOptimizer'
   */
  if (rtb_Desiredyawratereferencedegs > 3600.0) {
    rtb_C_tmp_0 = 3600.0;
  } else if (rtb_Desiredyawratereferencedegs < -3600.0) {
    rtb_C_tmp_0 = -3600.0;
  } else {
    rtb_C_tmp_0 = rtb_Desiredyawratereferencedegs;
  }

  /* End of Saturate: '<S8>/Yaw moment saturation' */

  /* Gain: '<S4>/Gain' incorporates:
   *  Constant: '<S2>/Constant'
   *  Constant: '<S7>/Constant'
   *  Gain: '<S4>/Gain1'
   *  Gain: '<S7>/Gain1'
   *  Gain: '<S7>/Gain3'
   *  Inport: '<Root>/FeedbackEnabled'
   *  Inport: '<Root>/TorqueVectoringEnabled'
   *  Inport: '<Root>/VehicleSpeed'
   *  Logic: '<S1>/AND'
   *  Logic: '<S8>/AND'
   *  Product: '<S7>/Divide1'
   *  Product: '<S8>/Product2'
   *  RelationalOperator: '<S2>/Compare'
   */
  rtb_Gain_e = (real_T)(rtU.FeedbackEnabled && ((rtb_Gain_e != 0.0) &&
    (rtU.VehicleSpeed >= 2.4) && (rtU.TorqueVectoringEnabled != 0.0))) *
    rtb_C_tmp_0 * 0.5 * 0.205 / 14.399999999999999 * 0.5;

  /* Outport: '<Root>/TVFL' incorporates:
   *  Gain: '<S4>/Gain'
   */
  rtY.TVFL = rtb_Gain_e;

  /* Outport: '<Root>/TVFR' incorporates:
   *  Gain: '<S4>/Gain'
   */
  rtY.TVFR = rtb_Gain_e;

  /* Outport: '<Root>/TVRL' */
  rtY.TVRL = rtb_Gain_e;

  /* Outport: '<Root>/TVRR' */
  rtY.TVRR = rtb_Gain_e;
  for (i = 0; i < 6; i++) {
    /* MATLAB Function: '<S41>/FixedHorizonOptimizer' */
    rtb_Gain_e = 0.0;
    for (r3 = 0; r3 < 6; r3++) {
      r1 = 6 * i + r3;
      L_tmp[r1] = CovMat[9 * i + r3] + (L_tmp_0[r1] - L_tmp_1[r1]);
      rtb_Gain_e += b_A[6 * r3 + i] * xk[r3];
    }

    /* Update for Memory: '<S13>/last_x' incorporates:
     *  MATLAB Function: '<S41>/FixedHorizonOptimizer'
     */
    rtDW.last_x_PreviousInput[i] = (((L[i + 6] * rtb_VectorConcatenate1[1] + L[i]
      * rtb_VectorConcatenate1[0]) + L[i + 12] * rtb_VectorConcatenate1[2]) +
      ((Bu[i] * rtb_Desiredyawratereferencedegs + rtb_Gain_e) + Bv[i])) +
      b_xoff[i];
  }

  /* Update for UnitDelay: '<S13>/last_mv' incorporates:
   *  MATLAB Function: '<S41>/FixedHorizonOptimizer'
   */
  rtDW.last_mv_DSTATE = rtb_Desiredyawratereferencedegs;

  /* Update for Memory: '<S13>/LastPcov' incorporates:
   *  MATLAB Function: '<S41>/FixedHorizonOptimizer'
   */
  for (i = 0; i < 6; i++) {
    for (r3 = 0; r3 < 6; r3++) {
      /* MATLAB Function: '<S41>/FixedHorizonOptimizer' */
      r1 = 6 * i + r3;
      rtDW.LastPcov_PreviousInput[r1] = (L_tmp[6 * r3 + i] + L_tmp[r1]) * 0.5;
    }
  }

  /* End of Update for Memory: '<S13>/LastPcov' */
}

/* Model initialize function */
void TorqueVectoring_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* InitializeConditions for Memory: '<S13>/LastPcov' */
  memcpy(&rtDW.LastPcov_PreviousInput[0], &rtConstP.LastPcov_InitialCondition[0],
         36U * sizeof(real_T));
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
