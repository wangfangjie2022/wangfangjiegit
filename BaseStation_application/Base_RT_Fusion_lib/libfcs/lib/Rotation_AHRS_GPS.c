#include "Rotation_AHRS_GPS.h"
#ifndef UCHAR_MAX
#include <limits.h>
#endif

#if ( UCHAR_MAX != (0xFFU) ) || ( SCHAR_MAX != (0x7F) )
#error Code was generated for compiler with different sized uchar/char. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( USHRT_MAX != (0xFFFFU) ) || ( SHRT_MAX != (0x7FFF) )
#error Code was generated for compiler with different sized ushort/short. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( UINT_MAX != (0xFFFFFFFFU) ) || ( INT_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized uint/int. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( ULONG_MAX != (0xFFFFFFFFU) ) || ( LONG_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized ulong/long. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        (*((rtm)->errorStatus))
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   (*((rtm)->errorStatus) = (val))
#endif

#ifndef rtmGetErrorStatusPointer
# define rtmGetErrorStatusPointer(rtm) (rtm)->errorStatus
#endif

#ifndef rtmSetErrorStatusPointer
# define rtmSetErrorStatusPointer(rtm, val) ((rtm)->errorStatus = (val))
#endif

P_Rotation_AHRS_GPS_T Rotation_AHRS_GPS_P_g = {

  0.0F,

  1.0F,

  1.0E-7F,

  1.0E-7F,

  1.0E-6F,

  0.5F,

  3.0F,

  6.0F,

  3.0F,

  3.0F,

  0.3F,

  1.0F,

  0.6F,

  0.6F,

  2.0F,

  1.0F,

  1.0F,

  1.0F,

  0.001F,

  0.05F,

  0.005F,

  0.005F,

  0.05F,

  0.05F,

  0.05F,

  0.05F,

  0.05F,

  3.14159274F,

  -3.14159274F,

  3.0F,

  0.2F,

  0.2F,

  0.523560226F,

  1.0F,

  1.0F,

  1.0F,

  1.0F,

  1.0F,

  1.0F,

  0.011F,

  0.05F,

  0.05F,

  0.4F,

  0.00872600358F,

  0.5F,

  10.0F,

  3.14159274F,

  60.0F,

  0.4F,

  0.174520075F,

  0.5F,

  10.0F,

  0.8F,

  0.5F,

  0.68F,

  0.4F,

  0.104712039F,

  0.349040151F,

  0.5F,

  0.349040151F,

  0.0349040143F,

  0.5F,

  0.0349040143F,

  0.5F,

  4.0F,

  2.0F,

  0.2F,

  0.3F,

  0.05F,

  0.2F,

  0.5F,

  0.0F,

  0.523560226F,

  0.698080301F,

  2.5F,

  2.0F,

  3.0F,

  3.0F,

  0.0F,

  4.0F,

  4.0F,

  0.0F,

  3.14159274F,

  0.1F,

  0.4F,

  0.1F,

  0.1F,

  2.0F,

  0.5F,

  0.5F,

  2.0F,

  0.6F,

  0.05F,

  3.0F,

  0.0872600377F,

  64.0F,

  144.0F,

  0.0F,

  0.0F,

  0.1F,

  1.0F,

  0.1F,

  0.01F,

  10.0F,

  0.003F,

  0.5F,

  5.0F,

  0.0F,

  0.002F,

  0.002F,

  0.05F,

  50.0F,

  0.008F,

  0.55F,

  10.0F,

  0.174520075F,

  0.01F,

  0.008F,

  2.0F,

  0.1F,

  1.0F,

  1.0F,

  1.0F,

  1.0F,

  1.0F,

  1.0F,

  5.0F,

  1.0F,

  0.1F,

  0.01F,

  8.0F,

  0.0F,

  5.0F,

  9.0F,

  0,

  0,

  0,

  0,

  0,

  0,

  0,

  0,

  0,

  0,

  0,

  0,

  0,

  0,

  0,

  0,

  0,

  0,

  0,

  0,

  0,

  0,

  0,

  0,

  0,

  0,

  0,

  0,

  0,

  0,

  0,

  0,

  2U,


  { 0.0F, 0.0F, 0.0F },


  { 0.0F, 0.0F, 0.0F },

  1.0F,

  1.3F,

  1.0F,

  0.0F,

  1.0F,

  1.0F,

  0.0F,

  0.0F,

  0.5F,

  1.0F,

  0.0F,

  1.0F,

  0.3F,

  -0.3F,

  0.3F,

  -0.3F,

  0.8F,

  0.0F,

  0.0F,

  1.0F,

  0.174520075F,

  0.349040151F,

  1.0F,

  0.0F,

  1.0F,

  2.0F,

  1.0F,

  0.0F,

  0.5F,

  1.0F,

  57.2957802F,

  57.2957802F,

  6.28318548F,

  6.28318548F,

  -6.28318548F,

  0.0F,

  6.28318548F,

  0.0F,

  0.0F,

  0.2F,

  0.5F,

  6.28318548F,


  { 1.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F },

  0.0F,

  -1.0F,

  -1.0F,

  0.999F,

  -0.999F,

  0.0F,

  0.5F,

  2.0F,

  2.0F,

  2.0F,

  2.0F,

  2.0F,

  2.0F,

  -1.0F,

  0.5F,

  0.0F,

  2.0F,

  2.0F,

  2.0F,

  2.0F,

  2.0F,

  2.0F,

  -1.0F,

  0.5F,

  0.0F,

  0.0F,

  0.0F,

  0.0F,

  2.0F,

  2.0F,

  2.0F,

  2.0F,

  2.0F,

  2.0F,

  -1.0F,

  0.5F,

  0.0F,

  0.01F,

  0.2F,

  0.0F,

  0.01F,

  0.0F,

  1000.0F,

  0.0F,

  0.01F,

  0.01F,

  1.0F,

  0.0F,

  0.01F,

  0.003F,

  0.002F,

  0.0F,

  1.0F,

  0.01F,

  0.0F,

  101.0F,

  0.0F,

  0.0F,

  0.0F,

  0.01F,

  0.0F,

  0.01F,

  0.0F,


  { 1.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F },

  0.0F,


  { 0.2F, 0.2F, 0.2F, 0.2F, 0.2F },

  0.01F,

  0.5F,

  -0.5F,


  { 0.0F, 0.0F, 1.0F },

  0.01F,

  9.8F,

  -9.8F,

  0.0F,


  { 0.2F, 0.2F, 0.2F, 0.2F, 0.2F },


  { 0.0F, 0.0F, 0.0F },

  0.01F,

  0.0F,

  0.01F,

  0.0F,

  0.0F,

  0.01F,

  0.0F,


  { 1.0F, 0.0F },

  1.0F,

  0.0F,

  0.5F,

  0.0F,

  0.0F,

  0.5F,

  2.0F,

  2.0F,

  2.0F,

  2.0F,

  2.0F,

  2.0F,

  0.0F,

  0.01F,


  { 0.0F, 0.0F, -9.80665F },

  0.01F,

  0.0F,

  0.01F,

  0.0F,

  0.0F,


  { 0.0F, 0.0F, 9.80665F },

  1.0F,

  0.01F,


  { 1.0F, 1.0F, 0.0F },

  1.6F,

  0.01F,

  0.01F,

  0.01F,

  0.0F,

  101.0F,

  0.0F,

  0.01F,

  0.0F,

  1.0F,

  1.0F,

  0.0F,

  0.01F,

  0.01F,

  0.01F,

  11.46F,

  8.0F,

  1.0F,

  0.01F,

  0.01F,

  0.0F,

  0.0523560196F,

  -0.0523560196F,


  { 1.0F, 1.0F, 0.0F },

  0.0174532924F,

  0.0F,

  0.0F,

  5.0F,


  { 0.0F, 0.0F, 1.0F },

  0.01F,

  0.0F,

  0.01F,

  0.0F,

  2.0F,

  1.0E-7F,

  2.0F,

  -0.0349065848F,

  0.0349065848F,

  0.4F,

  2.5F,

  1.0F,

  0.0F,

  3.0F,

  0.0F,

  1.0F,

  0.1F,

  2.0F,

  1.0F,

  0.0F,

  0.0F,


  { 0.0333333351F, 0.0333333351F, 0.0333333351F, 0.0333333351F, 0.0333333351F,
    0.0333333351F, 0.0333333351F, 0.0333333351F, 0.0333333351F, 0.0333333351F,
    0.0333333351F, 0.0333333351F, 0.0333333351F, 0.0333333351F, 0.0333333351F,
    0.0333333351F, 0.0333333351F, 0.0333333351F, 0.0333333351F, 0.0333333351F,
    0.0333333351F, 0.0333333351F, 0.0333333351F, 0.0333333351F, 0.0333333351F,
    0.0333333351F, 0.0333333351F, 0.0333333351F, 0.0333333351F, 0.0333333351F },

  1.0F,

  0.0F,

  0.01F,

  1.74520075F,

  0.01F,

  57.3F,

  1.0F,

  0.0F,

  0.174520075F,

  -0.174520075F,

  1.0F,

  0.01F,

  0.0F,

  0.01F,

  0.0F,

  101.0F,

  0.0F,

  0.8F,

  0.5F,

  0.0F,

  1.0F,

  -1.0F,

  0.01F,

  0.0F,

  0.01F,

  0.01F,

  0.01F,

  0.0F,

  11.0F,

  0.0F,

  0.01F,

  0.0F,

  0.0F,

  2.0F,


  { 0.0F, 0.0F, 1.0F },

  1.0F,

  0.0F,

  0.0872600377F,

  1.0F,

  0.0F,

  0.01F,

  0.01F,

  0.01F,

  5.0F,

  0.01F,

  0.01F,

  0.01F,

  5.0F,

  0.01F,

  0.01F,

  0.01F,

  0.0F,

  0.01F,

  0.0F,

  0.01F,

  1.0F,

  0.0F,

  0.01F,

  57.3F,

  1.0F,

  0.0F,

  0.01F,

  0.01F,

  0.0F,

  0.0349040143F,

  -0.0349040143F,

  0.0698080286F,

  -0.0698080286F,

  1.0F,

  1.0F,

  10.0F,

  0.01F,

  2.0F,

  2.0F,

  2.0F,

  2.0F,

  2.0F,

  2.0F,

  -1.0F,

  -1.0F,

  0.999F,

  -0.999F,

  0.0F,

  -1.0F,

  0.0F,

  1.0F,

  0.0F,

  0.0F,

  57.2957802F,

  -1.0F,

  0.01F,

  0.0F,

  -200.0F,

  10000.0F,

  0.01F,

  0.0F,

  14.14F,

  100.0F,

  0.01F,

  0.0F,

  14.14F,

  100.0F,

  5.0F,

  0.025F,


  { 1.0F, 1.0F, 0.0F },

  0.0F,

  1.0F,

  2.0F,

  1.0F,

  50.0F,

  1.0F,

  1.0F,

  5.0F,

  0.01F,

  0.0F,

  -2.828F,

  4.0F,

  0.01F,

  0.0F,

  -2.828F,

  4.0F,

  2.0F,

  1.0F,

  0.0F,

  0.01F,

  0.0F,

  0.01F,

  0.0F,

  0.01F,

  0.0F,

  101.0F,

  0.0F,

  0.01F,

  0.0F,

  101.0F,

  0.0F,

  0.01F,

  0.0F,

  0.01F,

  0.0F,

  0.01F,

  0.0F,

  1.0F,

  1.0F,

  1.0F,

  10.0F,

  2.0F,

  0.01F,

  0.01F,

  0.0F,

  0.0F,

  57.3F,

  57.3F,

  0.05F,

  1.0F,

  1.0F,

  20.0F,

  1.0F,

  0.01F,

  0.0F,

  -14.14F,

  0.0174532924F,

  6.28318548F,

  0.0F,

  1000.0F,

  100.0F,

  0.01F,

  0.0F,

  -14.14F,

  100.0F,

  0.0F,

  0.01F,

  0.0F,

  -15.0F,

  100.0F,

  0.0F,

  1.0F,

  0.0F,

  1.0F,

  2.0F,

  0.0F,

  1.0F,

  0.0F,

  0.0F,

  0.5F,

  0.0F,

  0.5F,

  0.0F,

  1.0F,

  0.0F,

  33.3333321F,

  5.0F,

  1.0F,

  0.01F,

  0.0F,

  -28.28F,

  0.01F,

  0.0F,

  400.0F,

  33.3333321F,


  { 0.0F, 0.0F, 0.0F },


  { 1.0F, -1.0F, 1.0F, 1.0F },

  0.707106769F,

  2.0F,

  0.001F,

  2.0F,

  0.001F,

  0.001F,

  -1.0F,

  0.01F,

  0.0F,

  0.0F,

  0.01F,

  2.0F,

  1.0F,

  2.0F,

  1.0F,

  1.0F,

  0.5F,

  1.0F,

  1.0F,

  0.5F,

  2.0F,

  1.0F,

  2U,

  1U,

  2U,

  1U,

  1U,

  1U,

  1U,

  1U,

  1U,

  1U,

  1U,

  1U,

  1U,

  1U,

  1U,

  1U,

  1U,

  1U,

  5U,

  25U,

  1U,

  1U,

  100U,

  102U,

  1U,

  1U,

  1U,

  1U,

  1U,

  1U,

  1U,

  1U,

  1U,

  1U,

  1U,

  1U,

  1U,

  1U,

  1U,

  1U,

  1U,

  1U,

  1U,

  1U,

  1U,

  1U,

  1,

  0,

  0,

  0,

  0,

  0,

  0,

  0,

  0,

  0,

  0,

  0,

  0,

  0,

  0,

  0,

  0,

  0,

  0,

  0,

  0,

  0,

  0,

  0,

  0,

  0,

  0,

  0,

  128U
};

MdlrefDW_Rotation_AHRS_GPS_T Rotation_AHRS_GPS_MdlrefDW;
B_Rotation_AHRS_GPS_c_T Rotation_AHRS_GPS_B;
DW_Rotation_AHRS_GPS_f_T Rotation_AHRS_GPS_DW;
ZCE_Rotation_AHRS_GPS_T Rotation_AHRS_GPS_PrevZCX;
static void Rotation_AHR_SystemCore_release(dsp_simulink_MovingAverage_Ro_T *obj);
static void Rotation_AHRS_SystemCore_delete(dsp_simulink_MovingAverage_Ro_T *obj);
static void matlabCodegenHandle_matlabCodeg(dsp_simulink_MovingAverage_Ro_T *obj);
static real32_T Rotation_AHRS_GPS_rt_atan2f_snf(real32_T u0, real32_T u1);
static real32_T Rotation_AHRS_GPS_rt_modf_snf(real32_T u0, real32_T u1);
static void Rotation_AHR_SystemCore_release(dsp_simulink_MovingAverage_Ro_T *obj)
{
  dsp_private_SlidingWindowAver_T *obj_0;
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    obj_0 = obj->pStatistic;
    if (obj_0->isInitialized == 1) {
      obj_0->isInitialized = 2;
    }

    obj->NumChannels = -1;
  }
}

static void Rotation_AHRS_SystemCore_delete(dsp_simulink_MovingAverage_Ro_T *obj)
{
  Rotation_AHR_SystemCore_release(obj);
}

static void matlabCodegenHandle_matlabCodeg(dsp_simulink_MovingAverage_Ro_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    Rotation_AHRS_SystemCore_delete(obj);
  }
}

void Rotation_AH_MovingAverage2_Init(DW_MovingAverage2_Rotation_AH_T *localDW)
{
  int32_T i;
  if (localDW->obj.pStatistic->isInitialized == 1) {
    localDW->obj.pStatistic->pCumSum = 0.0F;
    for (i = 0; i < 9; i++) {
      localDW->obj.pStatistic->pCumSumRev[i] = 0.0F;
    }

    localDW->obj.pStatistic->pCumRevIndex = 1.0F;
  }
}

void Rotation_A_MovingAverage2_Reset(DW_MovingAverage2_Rotation_AH_T *localDW)
{
  int32_T i;
  if (localDW->obj.pStatistic->isInitialized == 1) {
    localDW->obj.pStatistic->pCumSum = 0.0F;
    for (i = 0; i < 9; i++) {
      localDW->obj.pStatistic->pCumSumRev[i] = 0.0F;
    }

    localDW->obj.pStatistic->pCumRevIndex = 1.0F;
  }
}

void Rotation_A_MovingAverage2_Start(DW_MovingAverage2_Rotation_AH_T *localDW)
{
  localDW->obj.matlabCodegenIsDeleted = true;
  localDW->obj.isInitialized = 0;
  localDW->obj.NumChannels = -1;
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  localDW->obj.isSetupComplete = false;
  localDW->obj.isInitialized = 1;
  localDW->obj.NumChannels = 1;
  localDW->gobj_0.isInitialized = 0;
  localDW->obj.pStatistic = &localDW->gobj_0;
  localDW->obj.isSetupComplete = true;
  localDW->obj.TunablePropsChanged = false;
}

void Rotation_AHRS_GP_MovingAverage2(real32_T rtu_0,
  B_MovingAverage2_Rotation_AHR_T *localB, DW_MovingAverage2_Rotation_AH_T
  *localDW)
{
  real32_T cumRevIndex;
  real32_T csum;
  real32_T csumrev[9];
  real32_T z;
  int32_T z_tmp;
  if (localDW->obj.TunablePropsChanged) {
    localDW->obj.TunablePropsChanged = false;
  }

  if (localDW->obj.pStatistic->isInitialized != 1) {
    localDW->obj.pStatistic->isSetupComplete = false;
    localDW->obj.pStatistic->isInitialized = 1;
    localDW->obj.pStatistic->pCumSum = 0.0F;
    localDW->obj.pStatistic->pCumRevIndex = 1.0F;
    localDW->obj.pStatistic->isSetupComplete = true;
    localDW->obj.pStatistic->pCumSum = 0.0F;
    for (z_tmp = 0; z_tmp < 9; z_tmp++) {
      localDW->obj.pStatistic->pCumSumRev[z_tmp] = 0.0F;
      localDW->obj.pStatistic->pCumSumRev[z_tmp] = 0.0F;
    }

    localDW->obj.pStatistic->pCumRevIndex = 1.0F;
  }

  cumRevIndex = localDW->obj.pStatistic->pCumRevIndex;
  csum = localDW->obj.pStatistic->pCumSum;
  for (z_tmp = 0; z_tmp < 9; z_tmp++) {
    csumrev[z_tmp] = localDW->obj.pStatistic->pCumSumRev[z_tmp];
  }

  csum += rtu_0;
  z_tmp = (int32_T)cumRevIndex - 1;
  z = csumrev[z_tmp] + csum;
  csumrev[z_tmp] = rtu_0;
  if (cumRevIndex != 9.0F) {
    cumRevIndex++;
  } else {
    cumRevIndex = 1.0F;
    csum = 0.0F;
    for (z_tmp = 7; z_tmp >= 0; z_tmp--) {
      csumrev[z_tmp] += csumrev[z_tmp + 1];
    }
  }

  localDW->obj.pStatistic->pCumSum = csum;
  for (z_tmp = 0; z_tmp < 9; z_tmp++) {
    localDW->obj.pStatistic->pCumSumRev[z_tmp] = csumrev[z_tmp];
  }

  localDW->obj.pStatistic->pCumRevIndex = cumRevIndex;
  localB->MovingAverage2 = z / 10.0F;
}

void Rotation_AH_MovingAverage2_Term(DW_MovingAverage2_Rotation_AH_T *localDW)
{
  matlabCodegenHandle_matlabCodeg(&localDW->obj);
}

static real32_T Rotation_AHRS_GPS_rt_atan2f_snf(real32_T u0, real32_T u1)
{
  real32_T y;
  if (rtIsNaNF(u0) || rtIsNaNF(u1)) {
    y = (rtNaNF);
  } else if (rtIsInfF(u0) && rtIsInfF(u1)) {
    if (u0 > 0.0F) {
      Rotation_AHRS_GPS_B.u0_l = 1;
    } else {
      Rotation_AHRS_GPS_B.u0_l = -1;
    }

    if (u1 > 0.0F) {
      Rotation_AHRS_GPS_B.u1 = 1;
    } else {
      Rotation_AHRS_GPS_B.u1 = -1;
    }

    y = (real32_T)atan2((real32_T)Rotation_AHRS_GPS_B.u0_l, (real32_T)
                        Rotation_AHRS_GPS_B.u1);
  } else if (u1 == 0.0F) {
    if (u0 > 0.0F) {
      y = RT_PIF / 2.0F;
    } else if (u0 < 0.0F) {
      y = -(RT_PIF / 2.0F);
    } else {
      y = 0.0F;
    }
  } else {
    y = (real32_T)atan2(u0, u1);
  }

  return y;
}

static real32_T Rotation_AHRS_GPS_rt_modf_snf(real32_T u0, real32_T u1)
{
  real32_T y;
  boolean_T yEq;
  y = u0;
  if (rtIsNaNF(u0) || rtIsInfF(u0) || (rtIsNaNF(u1) || rtIsInfF(u1))) {
    if (u1 != 0.0F) {
      y = (rtNaNF);
    }
  } else if (u0 == 0.0F) {
    y = u1 * 0.0F;
  } else {
    if (u1 != 0.0F) {
      y = (real32_T)fmod(u0, u1);
      yEq = (y == 0.0F);
      if ((!yEq) && (u1 > (real32_T)floor(u1))) {
        Rotation_AHRS_GPS_B.q = (real32_T)fabs(u0 / u1);
        yEq = ((real32_T)fabs(Rotation_AHRS_GPS_B.q - (real32_T)floor
                              (Rotation_AHRS_GPS_B.q + 0.5F)) <= FLT_EPSILON *
               Rotation_AHRS_GPS_B.q);
      }

      if (yEq) {
        y = u1 * 0.0F;
      } else {
        if ((u0 < 0.0F) != (u1 < 0.0F)) {
          y += u1;
        }
      }
    }
  }

  return y;
}

void Rotation_AHRS_GPS_Init(void)
{
  int32_T i;
  Rotation_AHRS_GPS_DW.Delay5_DSTATE_b =
    Rotation_AHRS_GPS_P_g.Delay5_InitialCondition_p;
  Rotation_AHRS_GPS_DW.Delay4_DSTATE_p[0] =
    Rotation_AHRS_GPS_P_g.Delay4_InitialCondition;
  Rotation_AHRS_GPS_DW.Delay6_DSTATE_m[0] =
    Rotation_AHRS_GPS_P_g.Delay6_InitialCondition;
  Rotation_AHRS_GPS_DW.Delay4_DSTATE_p[1] =
    Rotation_AHRS_GPS_P_g.Delay4_InitialCondition;
  Rotation_AHRS_GPS_DW.Delay6_DSTATE_m[1] =
    Rotation_AHRS_GPS_P_g.Delay6_InitialCondition;
  Rotation_AHRS_GPS_DW.Delay_DSTATE_g =
    Rotation_AHRS_GPS_P_g.Delay_InitialCondition_g;
  Rotation_AHRS_GPS_DW.icLoad = 1U;
  Rotation_AHRS_GPS_DW.Delay_DSTATE_m =
    Rotation_AHRS_GPS_P_g.Delay_InitialCondition_b;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE =
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_IC;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_IC_LOADI = 1U;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_IC_LOA_b = 1U;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_IC_LOAD = 1U;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE_o =
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_IC_k;
  Rotation_AHRS_GPS_DW.DelayInput1_DSTATE_p =
    Rotation_AHRS_GPS_P_g.DetectIncrease5_vinit;
  Rotation_AHRS_GPS_DW.Delay_DSTATE_p =
    Rotation_AHRS_GPS_P_g.Delay_InitialCondition_a;
  Rotation_AHRS_GPS_DW.icLoad_h = 1U;
  Rotation_AHRS_GPS_DW.Delay_DSTATE_k =
    Rotation_AHRS_GPS_P_g.Delay_InitialCondition_ax;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_DSTAT_c =
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator1_IC;
  Rotation_AHRS_GPS_DW.DelayInput1_DSTATE_i =
    Rotation_AHRS_GPS_P_g.DetectIncrease1_vinit;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE_i =
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_IC_j;
  Rotation_AHRS_GPS_DW.DelayInput1_DSTATE_g =
    Rotation_AHRS_GPS_P_g.DetectIncrease2_vinit;
  Rotation_AHRS_GPS_DW.DelayInput1_DSTATE_i5 =
    Rotation_AHRS_GPS_P_g.DetectIncrease3_vinit_n;
  for (i = 0; i < 7; i++) {
    Rotation_AHRS_GPS_DW.Delay17_DSTATE[i] =
      Rotation_AHRS_GPS_P_g.Delay17_InitialCondition;
    Rotation_AHRS_GPS_DW.Delay13_DSTATE[i] =
      Rotation_AHRS_GPS_P_g.Delay13_InitialCondition;
    Rotation_AHRS_GPS_DW.Delay_DSTATE[i] =
      Rotation_AHRS_GPS_P_g.Delay_InitialCondition[i];
  }

  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_IC_LOA_d = 1U;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_IC_LOA_h = 1U;
  Rotation_AHRS_GPS_DW.Memory2_PreviousInput =
    Rotation_AHRS_GPS_P_g.Memory2_InitialCondition;
  Rotation_AHRS_GPS_DW.DelayInput1_DSTATE_b =
    Rotation_AHRS_GPS_P_g.DetectRisePositive2_vinit;
  for (i = 0; i < 12; i++) {
    Rotation_AHRS_GPS_DW.DiscreteFIRFilter1_states[i] =
      Rotation_AHRS_GPS_P_g.DiscreteFIRFilter1_InitialState;
    Rotation_AHRS_GPS_DW.DiscreteFIRFilter_states[i] =
      Rotation_AHRS_GPS_P_g.DiscreteFIRFilter_InitialStates;
  }

  Rotation_AHRS_GPS_DW.DelayInput1_DSTATE_h =
    Rotation_AHRS_GPS_P_g.DetectRisePositive_vinit;
  Rotation_AHRS_GPS_DW.Delay_DSTATE_c =
    Rotation_AHRS_GPS_P_g.Delay_InitialCondition_bz;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE_m =
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_IC_d;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE_b =
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_IC_l;
  Rotation_AHRS_GPS_DW.DelayInput1_DSTATE_ft =
    Rotation_AHRS_GPS_P_g.DetectIncrease_vinit_n;
  Rotation_AHRS_GPS_DW.Delay_DSTATE_e =
    Rotation_AHRS_GPS_P_g.Delay_InitialCondition_p;
  Rotation_AHRS_GPS_DW.DelayInput1_DSTATE_n =
    Rotation_AHRS_GPS_P_g.DetectIncrease1_vinit_c;
  for (i = 0; i < 7; i++) {
    Rotation_AHRS_GPS_DW.Delay2_DSTATE[i] =
      Rotation_AHRS_GPS_P_g.Delay2_InitialCondition;
  }

  Rotation_AHRS_GPS_DW.icLoad_b = 1U;
  Rotation_AHRS_GPS_DW.icLoad_m = 1U;
  Rotation_AHRS_GPS_DW.DelayInput1_DSTATE_a =
    Rotation_AHRS_GPS_P_g.DetectIncrease8_vinit;
  Rotation_AHRS_GPS_DW.DelayInput1_DSTATE_d =
    Rotation_AHRS_GPS_P_g.DetectIncrease1_vinit_h;
  Rotation_AHRS_GPS_DW.DelayInput1_DSTATE_bg =
    Rotation_AHRS_GPS_P_g.DetectIncrease6_vinit;
  Rotation_AHRS_GPS_DW.Delay_DSTATE_n1 =
    Rotation_AHRS_GPS_P_g.Delay_InitialCondition_o;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_ab =
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_IC_lf;
  for (i = 0; i < 15; i++) {
    Rotation_AHRS_GPS_DW.Delay1_DSTATE_o[i] =
      Rotation_AHRS_GPS_P_g.Delay1_InitialCondition;
  }

  for (i = 0; i < 75; i++) {
    Rotation_AHRS_GPS_DW.Delay3_DSTATE[i] =
      Rotation_AHRS_GPS_P_g.Delay3_InitialCondition;
  }

  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_IC_LOA_c = 1U;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_IC_LO_by = 1U;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_IC_LO_n = 1U;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_if =
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_IC_e;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_cq =
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_IC_lw;
  Rotation_AHRS_GPS_DW.Delay_DSTATE_by =
    Rotation_AHRS_GPS_P_g.Delay_InitialCondition_az;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_IC_LOA_g = 1U;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_IC_LOA_k = 1U;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_IC_LOA_i = 1U;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_IC_LO_gv = 1U;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_DSTAT_o[0] =
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator1_IC_f[0];
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE_k[0] =
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_IC_h;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE_n[0] =
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_IC_hz;
  Rotation_AHRS_GPS_DW.Delay_DSTATE_i[0] =
    Rotation_AHRS_GPS_P_g.Delay_InitialCondition_h;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_it[0] =
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_IC_n;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_DSTAT_o[1] =
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator1_IC_f[1];
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE_k[1] =
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_IC_h;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE_n[1] =
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_IC_hz;
  Rotation_AHRS_GPS_DW.Delay_DSTATE_i[1] =
    Rotation_AHRS_GPS_P_g.Delay_InitialCondition_h;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_it[1] =
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_IC_n;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_DSTAT_o[2] =
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator1_IC_f[2];
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE_k[2] =
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_IC_h;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE_n[2] =
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_IC_hz;
  Rotation_AHRS_GPS_DW.Delay_DSTATE_i[2] =
    Rotation_AHRS_GPS_P_g.Delay_InitialCondition_h;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_it[2] =
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_IC_n;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_PrevRe_j = 2;
  for (i = 0; i < 100; i++) {
    Rotation_AHRS_GPS_DW.Delay_DSTATE_f[i] =
      Rotation_AHRS_GPS_P_g.Delay_InitialCondition_m;
  }

  Rotation_AHRS_GPS_DW.DelayInput1_DSTATE =
    Rotation_AHRS_GPS_P_g.DetectIncrease_vinit;
  for (i = 0; i < 102; i++) {
    Rotation_AHRS_GPS_DW.Delay_DSTATE_ez[i] =
      Rotation_AHRS_GPS_P_g.Delay_InitialCondition_gf;
  }

  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_DSTAT_p[0] =
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator1_IC_m;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_DSTAT_p[1] =
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator1_IC_m;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_IC_LO_c = 1U;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_PrevR_l = 2;
  for (i = 0; i < 29; i++) {
    Rotation_AHRS_GPS_DW.DiscreteFIRFilter_states_e[i] =
      Rotation_AHRS_GPS_P_g.DiscreteFIRFilter_InitialStat_e;
  }

  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_IC_LO_bw = 1U;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_IC_LOA_o = 1U;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_jn =
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_IC_c;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTA_ifx =
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_IC_ly;
  Rotation_AHRS_GPS_DW.DelayInput1_DSTATE_o =
    Rotation_AHRS_GPS_P_g.DetectIncrease_vinit_j;
  Rotation_AHRS_GPS_DW.Delay4_DSTATE_j =
    Rotation_AHRS_GPS_P_g.Delay4_InitialCondition_d;
  Rotation_AHRS_GPS_DW.DelayInput1_DSTATE_fa =
    Rotation_AHRS_GPS_P_g.DetectIncrease1_vinit_o;
  Rotation_AHRS_GPS_DW.DelayInput1_DSTATE_oe =
    Rotation_AHRS_GPS_P_g.DetectIncrease1_vinit_h0;
  Rotation_AHRS_GPS_DW.Delay_DSTATE_na =
    Rotation_AHRS_GPS_P_g.Delay_InitialCondition_l;
  Rotation_AHRS_GPS_DW.DelayInput1_DSTATE_pc =
    Rotation_AHRS_GPS_P_g.DetectIncrease2_vinit_p;
  Rotation_AHRS_GPS_DW.Delay_DSTATE_kq =
    Rotation_AHRS_GPS_P_g.Delay_InitialCondition_h5;
  Rotation_AHRS_GPS_DW.DelayInput1_DSTATE_nh =
    Rotation_AHRS_GPS_P_g.DetectIncrease_vinit_g;
  Rotation_AHRS_GPS_DW.DelayInput1_DSTATE_f =
    Rotation_AHRS_GPS_P_g.DetectIncrease3_vinit;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_IC_LO_b = 1U;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_PrevR_g = 2;
  Rotation_AHRS_GPS_DW.icLoad_d = 1U;
  Rotation_AHRS_GPS_DW.icLoad_f = 1U;
  Rotation_AHRS_GPS_DW.Delay_DSTATE_b =
    Rotation_AHRS_GPS_P_g.Delay_InitialCondition_f;
  Rotation_AHRS_GPS_DW.icLoad_hh = 1U;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_IC_LOA_j = 1U;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_IC_LO_h = 1U;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_on =
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_IC_c3;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_c0 =
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_IC_dg;
  Rotation_AHRS_GPS_DW.Delay_DSTATE_iz =
    Rotation_AHRS_GPS_P_g.Delay_InitialCondition_b5;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_IC_LO_jh = 1U;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_IC_L_nd = 1U;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_IC_LOA_m = 1U;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_IC_LO_i4 = 1U;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_IC_LO_m = 1U;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_IC_LO_jz = 1U;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_IC_LO_b4 = 1U;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_IC_LO_g = 1U;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_DSTAT_l =
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator1_IC_fk;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_IC_LO_k = 1U;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_IC_LOA_n = 1U;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_IC_L_bf = 1U;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_PrevR_aq = 2;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_DSTAT_i[0] =
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator1_IC_m5;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_lk[0] =
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_IC_ny;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_b3[0] =
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_IC_dz;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_DSTA_pc[0] =
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator1_IC_o;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_DSTAT_g[0] =
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator1_IC_e;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_DSTAT_i[1] =
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator1_IC_m5;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_lk[1] =
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_IC_ny;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_b3[1] =
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_IC_dz;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_DSTA_pc[1] =
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator1_IC_o;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_DSTAT_g[1] =
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator1_IC_e;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_DSTAT_i[2] =
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator1_IC_m5;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_lk[2] =
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_IC_ny;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_b3[2] =
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_IC_dz;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_DSTA_pc[2] =
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator1_IC_o;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_DSTAT_g[2] =
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator1_IC_e;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_PrevRe_h = 2;
  Rotation_AHRS_GPS_DW.DelayInput1_DSTATE_dq =
    Rotation_AHRS_GPS_P_g.DetectIncrease_vinit_c;
  Rotation_AHRS_GPS_DW.DelayInput1_DSTATE_hh =
    Rotation_AHRS_GPS_P_g.DetectIncrease3_vinit_m;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_a1[0] =
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_IC_cq;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_l3[0] =
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_IC_i;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_a1[1] =
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_IC_cq;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_l3[1] =
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_IC_i;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_aj =
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_IC_hx;
  Rotation_AHRS_GPS_DW.DelayInput1_DSTATE_bh =
    Rotation_AHRS_GPS_P_g.DetectIncrease1_vinit_j;
  Rotation_AHRS_GPS_DW.DelayInput1_DSTATE_ip =
    Rotation_AHRS_GPS_P_g.DetectIncrease6_vinit_l;
  Rotation_AHRS_GPS_DW.Delay_DSTATE_d =
    Rotation_AHRS_GPS_P_g.Delay_InitialCondition_i;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE_h =
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_IC_e4;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTA_lk2 =
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_IC_lx;
  Rotation_AHRS_GPS_DW.Delay_DSTATE_e1 =
    Rotation_AHRS_GPS_P_g.Delay_InitialCondition_k;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_m4 =
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_IC_o;
  Rotation_AHRS_GPS_DW.DelayInput1_DSTATE_m =
    Rotation_AHRS_GPS_P_g.DetectIncrease_vinit_i;
  Rotation_AHRS_GPS_DW.Delay_DSTATE_ig =
    Rotation_AHRS_GPS_P_g.Delay_InitialCondition_gn;
  Rotation_AHRS_GPS_DW.DelayInput1_DSTATE_aq =
    Rotation_AHRS_GPS_P_g.DetectIncrease1_vinit_e;
  Rotation_AHRS_GPS_DW.Delay_DSTATE_o =
    Rotation_AHRS_GPS_P_g.Delay_InitialCondition_ez;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_gr =
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_IC_ob;
  Rotation_AHRS_GPS_DW.DelayInput1_DSTATE_c =
    Rotation_AHRS_GPS_P_g.DetectIncrease11_vinit;
  Rotation_AHRS_GPS_DW.DelayInput1_DSTATE_ne =
    Rotation_AHRS_GPS_P_g.DetectIncrease12_vinit;
  Rotation_AHRS_GPS_DW.DelayInput1_DSTATE_j =
    Rotation_AHRS_GPS_P_g.DetectIncrease2_vinit_c;
  Rotation_AHRS_GPS_DW.Delay_DSTATE_gd =
    Rotation_AHRS_GPS_P_g.Delay_InitialCondition_j;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_bu =
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_IC_hn;
  Rotation_AHRS_GPS_DW.Delay_DSTATE_ef =
    Rotation_AHRS_GPS_P_g.Delay_InitialCondition_kr;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_cf =
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_IC_j0;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_IC_LO_gi = 1U;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_IC_LO_hx = 1U;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_cz =
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_IC_b;
  Rotation_AHRS_GPS_DW.UD_DSTATE = Rotation_AHRS_GPS_P_g.Difference_ICPrevInput;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTA_og2[0] =
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_IC_iy;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTA_og2[1] =
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_IC_iy;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTA_og2[2] =
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_IC_iy;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_ol =
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_IC_a;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_PrevRe_o = 2;
  Rotation_AHRS_GPS_DW.DelayInput1_DSTATE_fq =
    Rotation_AHRS_GPS_P_g.DetectIncrease1_vinit_g;
  Rotation_AHRS_GPS_DW.icLoad_o = 1U;
  Rotation_AHRS_GPS_DW.Delay11_DSTATE =
    Rotation_AHRS_GPS_P_g.Delay11_InitialCondition;
  Rotation_AHRS_GPS_DW.Delay7_DSTATE =
    Rotation_AHRS_GPS_P_g.Delay7_InitialCondition;
  Rotation_AHRS_GPS_DW.Delay5_DSTATE =
    Rotation_AHRS_GPS_P_g.Delay5_InitialCondition;
  Rotation_AHRS_GPS_DW.icLoad_i = 1U;
  Rotation_AHRS_GPS_DW.DelayInput1_DSTATE_ms =
    Rotation_AHRS_GPS_P_g.DetectIncrease5_vinit_e;
  Rotation_AHRS_GPS_DW.DelayInput1_DSTATE_bu =
    Rotation_AHRS_GPS_P_g.DetectIncrease7_vinit;
  Rotation_AHRS_GPS_DW.icLoad_n = 1U;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE_f =
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_IC_o0;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_DSTA_la =
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator1_IC_a;
  Rotation_AHRS_GPS_DW.DelayInput1_DSTATE_dc =
    Rotation_AHRS_GPS_P_g.DetectIncrease3_vinit_a;
  Rotation_AHRS_GPS_DW.DelayInput1_DSTATE_n5 =
    Rotation_AHRS_GPS_P_g.DetectIncrease_vinit_p;
  Rotation_AHRS_GPS_DW.Delay_DSTATE_j =
    Rotation_AHRS_GPS_P_g.Delay_InitialCondition_oa;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_jd =
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_IC_lq;
  Rotation_AHRS_GPS_DW.Delay_DSTATE_l[0] =
    Rotation_AHRS_GPS_P_g.Delay_InitialCondition_e;
  Rotation_AHRS_GPS_DW.Delay_DSTATE_l[1] =
    Rotation_AHRS_GPS_P_g.Delay_InitialCondition_e;
  Rotation_AHRS_GPS_DW.Delay_DSTATE_l[2] =
    Rotation_AHRS_GPS_P_g.Delay_InitialCondition_e;
  Rotation_AHRS_GPS_DW.Delay_DSTATE_l[3] =
    Rotation_AHRS_GPS_P_g.Delay_InitialCondition_e;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_IC_LO_md = 1U;
  Rotation_AHRS_GPS_DW.DelayInput1_DSTATE_px =
    Rotation_AHRS_GPS_P_g.DetectIncrease_vinit_l;
  Rotation_AHRS_GPS_DW.DelayInput1_DSTATE_by =
    Rotation_AHRS_GPS_P_g.DetectIncrease3_vinit_j;
  Rotation_AHRS_GPS_B.Sum = Rotation_AHRS_GPS_P_g.Out1_Y0_d;
  Rotation_AHRS_GPS_B.Sum_e = Rotation_AHRS_GPS_P_g.Out1_Y0_d;
  Rotation_AHRS_GPS_B.Sum_h = Rotation_AHRS_GPS_P_g.Out1_Y0_d;
  Rotation_AHRS_GPS_B.Sum_hp = Rotation_AHRS_GPS_P_g.Out1_Y0_d;
  Rotation_AHRS_GPS_B.TrigonometricFunction = Rotation_AHRS_GPS_P_g.det_yaw12_Y0;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_IC_LOA_e = 1U;
  Rotation_AHRS_GPS_B.In1[4] = Rotation_AHRS_GPS_P_g.Out1_Y0_d;
  Rotation_AHRS_GPS_B.DiscreteTimeIntegrator[0] =
    Rotation_AHRS_GPS_P_g.Out1_Y0_p;
  Rotation_AHRS_GPS_B.In1[5] = Rotation_AHRS_GPS_P_g.Out1_Y0_d;
  Rotation_AHRS_GPS_B.DiscreteTimeIntegrator[1] =
    Rotation_AHRS_GPS_P_g.Out1_Y0_p;
  Rotation_AHRS_GPS_B.In1[6] = Rotation_AHRS_GPS_P_g.Out1_Y0_d;
  Rotation_AHRS_GPS_B.DiscreteTimeIntegrator[2] =
    Rotation_AHRS_GPS_P_g.Out1_Y0_p;
  for (i = 0; i < 7; i++) {
    Rotation_AHRS_GPS_B.Switch[i] = Rotation_AHRS_GPS_P_g.x0_Y0;
  }

  Rotation_AH_MovingAverage2_Init(&Rotation_AHRS_GPS_DW.MovingAverage3);
  Rotation_AH_MovingAverage2_Init(&Rotation_AHRS_GPS_DW.MovingAverage1);
  Rotation_AH_MovingAverage2_Init(&Rotation_AHRS_GPS_DW.MovingAverage2);
  Rotation_AHRS_GPS_B.VectorConcatenate[0] = Rotation_AHRS_GPS_P_g.Out1_Y0;
  Rotation_AHRS_GPS_B.VectorConcatenate[1] = Rotation_AHRS_GPS_P_g.Out1_Y0;
  Rotation_AHRS_GPS_B.VectorConcatenate[2] = Rotation_AHRS_GPS_P_g.Out1_Y0;
}

void Rotation_AHRS_GPS_Reset(void)
{
  int32_T i;
  Rotation_AHRS_GPS_DW.Delay5_DSTATE_b =
    Rotation_AHRS_GPS_P_g.Delay5_InitialCondition_p;
  Rotation_AHRS_GPS_DW.Delay4_DSTATE_p[0] =
    Rotation_AHRS_GPS_P_g.Delay4_InitialCondition;
  Rotation_AHRS_GPS_DW.Delay6_DSTATE_m[0] =
    Rotation_AHRS_GPS_P_g.Delay6_InitialCondition;
  Rotation_AHRS_GPS_DW.Delay4_DSTATE_p[1] =
    Rotation_AHRS_GPS_P_g.Delay4_InitialCondition;
  Rotation_AHRS_GPS_DW.Delay6_DSTATE_m[1] =
    Rotation_AHRS_GPS_P_g.Delay6_InitialCondition;
  Rotation_AHRS_GPS_DW.Delay_DSTATE_g =
    Rotation_AHRS_GPS_P_g.Delay_InitialCondition_g;
  Rotation_AHRS_GPS_DW.icLoad = 1U;
  Rotation_AHRS_GPS_DW.Delay_DSTATE_m =
    Rotation_AHRS_GPS_P_g.Delay_InitialCondition_b;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE =
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_IC;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_IC_LOADI = 1U;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_IC_LOA_b = 1U;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_IC_LOAD = 1U;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE_o =
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_IC_k;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_PrevRese = 0;
  Rotation_AHRS_GPS_DW.DelayInput1_DSTATE_p =
    Rotation_AHRS_GPS_P_g.DetectIncrease5_vinit;
  Rotation_AHRS_GPS_DW.Delay_DSTATE_p =
    Rotation_AHRS_GPS_P_g.Delay_InitialCondition_a;
  Rotation_AHRS_GPS_DW.icLoad_h = 1U;
  Rotation_AHRS_GPS_DW.Delay_DSTATE_k =
    Rotation_AHRS_GPS_P_g.Delay_InitialCondition_ax;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_DSTAT_c =
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator1_IC;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_PrevRes = 0;
  Rotation_AHRS_GPS_DW.DelayInput1_DSTATE_i =
    Rotation_AHRS_GPS_P_g.DetectIncrease1_vinit;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE_i =
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_IC_j;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_PrevRe_a = 0;
  Rotation_AHRS_GPS_DW.DelayInput1_DSTATE_g =
    Rotation_AHRS_GPS_P_g.DetectIncrease2_vinit;
  Rotation_AHRS_GPS_DW.DelayInput1_DSTATE_i5 =
    Rotation_AHRS_GPS_P_g.DetectIncrease3_vinit_n;
  for (i = 0; i < 7; i++) {
    Rotation_AHRS_GPS_DW.Delay17_DSTATE[i] =
      Rotation_AHRS_GPS_P_g.Delay17_InitialCondition;
    Rotation_AHRS_GPS_DW.Delay13_DSTATE[i] =
      Rotation_AHRS_GPS_P_g.Delay13_InitialCondition;
    Rotation_AHRS_GPS_DW.Delay_DSTATE[i] =
      Rotation_AHRS_GPS_P_g.Delay_InitialCondition[i];
  }

  Rotation_AHRS_GPS_DW.DiscreteFIRFilter1_circBuf = 0;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_IC_LOA_d = 1U;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_IC_LOA_h = 1U;
  Rotation_AHRS_GPS_DW.Memory2_PreviousInput =
    Rotation_AHRS_GPS_P_g.Memory2_InitialCondition;
  Rotation_AHRS_GPS_DW.DelayInput1_DSTATE_b =
    Rotation_AHRS_GPS_P_g.DetectRisePositive2_vinit;
  Rotation_AHRS_GPS_DW.DiscreteFIRFilter_circBuf = 0;
  for (i = 0; i < 12; i++) {
    Rotation_AHRS_GPS_DW.DiscreteFIRFilter1_states[i] =
      Rotation_AHRS_GPS_P_g.DiscreteFIRFilter1_InitialState;
    Rotation_AHRS_GPS_DW.DiscreteFIRFilter_states[i] =
      Rotation_AHRS_GPS_P_g.DiscreteFIRFilter_InitialStates;
  }

  Rotation_AHRS_GPS_DW.DelayInput1_DSTATE_h =
    Rotation_AHRS_GPS_P_g.DetectRisePositive_vinit;
  Rotation_AHRS_GPS_DW.Delay_DSTATE_c =
    Rotation_AHRS_GPS_P_g.Delay_InitialCondition_bz;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE_m =
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_IC_d;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_PrevRe_f = 0;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE_b =
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_IC_l;
  Rotation_AHRS_GPS_DW.DelayInput1_DSTATE_ft =
    Rotation_AHRS_GPS_P_g.DetectIncrease_vinit_n;
  Rotation_AHRS_GPS_DW.Delay_DSTATE_e =
    Rotation_AHRS_GPS_P_g.Delay_InitialCondition_p;
  Rotation_AHRS_GPS_DW.DelayInput1_DSTATE_n =
    Rotation_AHRS_GPS_P_g.DetectIncrease1_vinit_c;
  for (i = 0; i < 7; i++) {
    Rotation_AHRS_GPS_DW.Delay2_DSTATE[i] =
      Rotation_AHRS_GPS_P_g.Delay2_InitialCondition;
  }

  Rotation_AHRS_GPS_DW.icLoad_b = 1U;
  Rotation_AHRS_GPS_DW.icLoad_m = 1U;
  Rotation_AHRS_GPS_DW.DelayInput1_DSTATE_a =
    Rotation_AHRS_GPS_P_g.DetectIncrease8_vinit;
  Rotation_AHRS_GPS_DW.DelayInput1_DSTATE_d =
    Rotation_AHRS_GPS_P_g.DetectIncrease1_vinit_h;
  Rotation_AHRS_GPS_DW.DelayInput1_DSTATE_bg =
    Rotation_AHRS_GPS_P_g.DetectIncrease6_vinit;
  Rotation_AHRS_GPS_DW.Delay_DSTATE_n1 =
    Rotation_AHRS_GPS_P_g.Delay_InitialCondition_o;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_ab =
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_IC_lf;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_PrevRe_d = 0;
  for (i = 0; i < 15; i++) {
    Rotation_AHRS_GPS_DW.Delay1_DSTATE_o[i] =
      Rotation_AHRS_GPS_P_g.Delay1_InitialCondition;
  }

  for (i = 0; i < 75; i++) {
    Rotation_AHRS_GPS_DW.Delay3_DSTATE[i] =
      Rotation_AHRS_GPS_P_g.Delay3_InitialCondition;
  }

  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_IC_LOA_c = 1U;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_IC_LO_by = 1U;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_IC_LO_n = 1U;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_if =
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_IC_e;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_PrevRe_k = 0;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_cq =
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_IC_lw;
  Rotation_AHRS_GPS_DW.Delay_DSTATE_by =
    Rotation_AHRS_GPS_P_g.Delay_InitialCondition_az;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_IC_LOA_g = 1U;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_IC_LOA_k = 1U;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_IC_LOA_i = 1U;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_IC_LO_gv = 1U;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_DSTAT_o[0] =
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator1_IC_f[0];
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE_k[0] =
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_IC_h;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE_n[0] =
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_IC_hz;
  Rotation_AHRS_GPS_DW.Delay_DSTATE_i[0] =
    Rotation_AHRS_GPS_P_g.Delay_InitialCondition_h;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_it[0] =
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_IC_n;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_DSTAT_o[1] =
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator1_IC_f[1];
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE_k[1] =
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_IC_h;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE_n[1] =
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_IC_hz;
  Rotation_AHRS_GPS_DW.Delay_DSTATE_i[1] =
    Rotation_AHRS_GPS_P_g.Delay_InitialCondition_h;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_it[1] =
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_IC_n;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_DSTAT_o[2] =
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator1_IC_f[2];
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE_k[2] =
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_IC_h;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE_n[2] =
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_IC_hz;
  Rotation_AHRS_GPS_DW.Delay_DSTATE_i[2] =
    Rotation_AHRS_GPS_P_g.Delay_InitialCondition_h;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_it[2] =
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_IC_n;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_PrevRe_j = 2;
  for (i = 0; i < 100; i++) {
    Rotation_AHRS_GPS_DW.Delay_DSTATE_f[i] =
      Rotation_AHRS_GPS_P_g.Delay_InitialCondition_m;
  }

  Rotation_AHRS_GPS_DW.DelayInput1_DSTATE =
    Rotation_AHRS_GPS_P_g.DetectIncrease_vinit;
  for (i = 0; i < 102; i++) {
    Rotation_AHRS_GPS_DW.Delay_DSTATE_ez[i] =
      Rotation_AHRS_GPS_P_g.Delay_InitialCondition_gf;
  }

  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_DSTAT_p[0] =
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator1_IC_m;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_DSTAT_p[1] =
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator1_IC_m;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_IC_LO_c = 1U;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_PrevR_l = 2;
  Rotation_AHRS_GPS_DW.DiscreteFIRFilter_circBuf_d = 0;
  for (i = 0; i < 29; i++) {
    Rotation_AHRS_GPS_DW.DiscreteFIRFilter_states_e[i] =
      Rotation_AHRS_GPS_P_g.DiscreteFIRFilter_InitialStat_e;
  }

  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_IC_LO_bw = 1U;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_IC_LOA_o = 1U;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_jn =
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_IC_c;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTA_ifx =
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_IC_ly;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_PrevRe_n = 0;
  Rotation_AHRS_GPS_DW.DelayInput1_DSTATE_o =
    Rotation_AHRS_GPS_P_g.DetectIncrease_vinit_j;
  Rotation_AHRS_GPS_DW.Delay4_DSTATE_j =
    Rotation_AHRS_GPS_P_g.Delay4_InitialCondition_d;
  Rotation_AHRS_GPS_DW.DelayInput1_DSTATE_fa =
    Rotation_AHRS_GPS_P_g.DetectIncrease1_vinit_o;
  Rotation_AHRS_GPS_DW.DelayInput1_DSTATE_oe =
    Rotation_AHRS_GPS_P_g.DetectIncrease1_vinit_h0;
  Rotation_AHRS_GPS_DW.Delay_DSTATE_na =
    Rotation_AHRS_GPS_P_g.Delay_InitialCondition_l;
  Rotation_AHRS_GPS_DW.DelayInput1_DSTATE_pc =
    Rotation_AHRS_GPS_P_g.DetectIncrease2_vinit_p;
  Rotation_AHRS_GPS_DW.Delay_DSTATE_kq =
    Rotation_AHRS_GPS_P_g.Delay_InitialCondition_h5;
  Rotation_AHRS_GPS_DW.DelayInput1_DSTATE_nh =
    Rotation_AHRS_GPS_P_g.DetectIncrease_vinit_g;
  Rotation_AHRS_GPS_DW.DelayInput1_DSTATE_f =
    Rotation_AHRS_GPS_P_g.DetectIncrease3_vinit;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_IC_LO_b = 1U;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_PrevR_g = 2;
  Rotation_AHRS_GPS_DW.icLoad_d = 1U;
  Rotation_AHRS_GPS_DW.icLoad_f = 1U;
  Rotation_AHRS_GPS_DW.Delay_DSTATE_b =
    Rotation_AHRS_GPS_P_g.Delay_InitialCondition_f;
  Rotation_AHRS_GPS_DW.icLoad_hh = 1U;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_IC_LOA_j = 1U;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_IC_LO_h = 1U;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_on =
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_IC_c3;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_PrevR_fh = 0;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_c0 =
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_IC_dg;
  Rotation_AHRS_GPS_DW.Delay_DSTATE_iz =
    Rotation_AHRS_GPS_P_g.Delay_InitialCondition_b5;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_IC_LO_jh = 1U;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_IC_L_nd = 1U;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_IC_LOA_m = 1U;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_IC_LO_i4 = 1U;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_IC_LO_m = 1U;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_IC_LO_jz = 1U;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_IC_LO_b4 = 1U;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_IC_LO_g = 1U;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_DSTAT_l =
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator1_IC_fk;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_IC_LO_k = 1U;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_IC_LOA_n = 1U;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_IC_L_bf = 1U;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_PrevR_aq = 2;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_DSTAT_i[0] =
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator1_IC_m5;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_lk[0] =
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_IC_ny;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_b3[0] =
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_IC_dz;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_DSTA_pc[0] =
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator1_IC_o;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_DSTAT_g[0] =
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator1_IC_e;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_DSTAT_i[1] =
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator1_IC_m5;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_lk[1] =
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_IC_ny;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_b3[1] =
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_IC_dz;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_DSTA_pc[1] =
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator1_IC_o;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_DSTAT_g[1] =
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator1_IC_e;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_DSTAT_i[2] =
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator1_IC_m5;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_lk[2] =
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_IC_ny;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_b3[2] =
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_IC_dz;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_DSTA_pc[2] =
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator1_IC_o;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_DSTAT_g[2] =
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator1_IC_e;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_PrevRe_h = 2;
  Rotation_AHRS_GPS_DW.DelayInput1_DSTATE_dq =
    Rotation_AHRS_GPS_P_g.DetectIncrease_vinit_c;
  Rotation_AHRS_GPS_DW.DelayInput1_DSTATE_hh =
    Rotation_AHRS_GPS_P_g.DetectIncrease3_vinit_m;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_a1[0] =
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_IC_cq;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_l3[0] =
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_IC_i;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_a1[1] =
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_IC_cq;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_l3[1] =
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_IC_i;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_aj =
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_IC_hx;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_PrevR_nh = 0;
  Rotation_AHRS_GPS_DW.DelayInput1_DSTATE_bh =
    Rotation_AHRS_GPS_P_g.DetectIncrease1_vinit_j;
  Rotation_AHRS_GPS_DW.DelayInput1_DSTATE_ip =
    Rotation_AHRS_GPS_P_g.DetectIncrease6_vinit_l;
  Rotation_AHRS_GPS_DW.Delay_DSTATE_d =
    Rotation_AHRS_GPS_P_g.Delay_InitialCondition_i;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE_h =
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_IC_e4;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_PrevRe_e = 0;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTA_lk2 =
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_IC_lx;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_PrevR_dh = 0;
  Rotation_AHRS_GPS_DW.Delay_DSTATE_e1 =
    Rotation_AHRS_GPS_P_g.Delay_InitialCondition_k;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_m4 =
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_IC_o;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_PrevR_du = 0;
  Rotation_AHRS_GPS_DW.DelayInput1_DSTATE_m =
    Rotation_AHRS_GPS_P_g.DetectIncrease_vinit_i;
  Rotation_AHRS_GPS_DW.Delay_DSTATE_ig =
    Rotation_AHRS_GPS_P_g.Delay_InitialCondition_gn;
  Rotation_AHRS_GPS_DW.DelayInput1_DSTATE_aq =
    Rotation_AHRS_GPS_P_g.DetectIncrease1_vinit_e;
  Rotation_AHRS_GPS_DW.Delay_DSTATE_o =
    Rotation_AHRS_GPS_P_g.Delay_InitialCondition_ez;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_gr =
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_IC_ob;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_PrevRe_c = 0;
  Rotation_AHRS_GPS_DW.DelayInput1_DSTATE_c =
    Rotation_AHRS_GPS_P_g.DetectIncrease11_vinit;
  Rotation_AHRS_GPS_DW.DelayInput1_DSTATE_ne =
    Rotation_AHRS_GPS_P_g.DetectIncrease12_vinit;
  Rotation_AHRS_GPS_DW.DelayInput1_DSTATE_j =
    Rotation_AHRS_GPS_P_g.DetectIncrease2_vinit_c;
  Rotation_AHRS_GPS_DW.Delay_DSTATE_gd =
    Rotation_AHRS_GPS_P_g.Delay_InitialCondition_j;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_bu =
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_IC_hn;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_PrevR_je = 0;
  Rotation_AHRS_GPS_DW.Delay_DSTATE_ef =
    Rotation_AHRS_GPS_P_g.Delay_InitialCondition_kr;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_cf =
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_IC_j0;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_PrevRe_m = 0;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_IC_LO_gi = 1U;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_IC_LO_hx = 1U;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_cz =
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_IC_b;
  Rotation_AHRS_GPS_DW.UD_DSTATE = Rotation_AHRS_GPS_P_g.Difference_ICPrevInput;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTA_og2[0] =
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_IC_iy;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTA_og2[1] =
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_IC_iy;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTA_og2[2] =
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_IC_iy;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_ol =
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_IC_a;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_PrevRe_o = 2;
  Rotation_AHRS_GPS_DW.DelayInput1_DSTATE_fq =
    Rotation_AHRS_GPS_P_g.DetectIncrease1_vinit_g;
  Rotation_AHRS_GPS_DW.icLoad_o = 1U;
  Rotation_AHRS_GPS_DW.Delay11_DSTATE =
    Rotation_AHRS_GPS_P_g.Delay11_InitialCondition;
  Rotation_AHRS_GPS_DW.Delay7_DSTATE =
    Rotation_AHRS_GPS_P_g.Delay7_InitialCondition;
  Rotation_AHRS_GPS_DW.Delay5_DSTATE =
    Rotation_AHRS_GPS_P_g.Delay5_InitialCondition;
  Rotation_AHRS_GPS_DW.icLoad_i = 1U;
  Rotation_AHRS_GPS_DW.DelayInput1_DSTATE_ms =
    Rotation_AHRS_GPS_P_g.DetectIncrease5_vinit_e;
  Rotation_AHRS_GPS_DW.DelayInput1_DSTATE_bu =
    Rotation_AHRS_GPS_P_g.DetectIncrease7_vinit;
  Rotation_AHRS_GPS_DW.icLoad_n = 1U;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE_f =
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_IC_o0;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_DSTA_la =
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator1_IC_a;
  Rotation_AHRS_GPS_DW.DelayInput1_DSTATE_dc =
    Rotation_AHRS_GPS_P_g.DetectIncrease3_vinit_a;
  Rotation_AHRS_GPS_DW.DelayInput1_DSTATE_n5 =
    Rotation_AHRS_GPS_P_g.DetectIncrease_vinit_p;
  Rotation_AHRS_GPS_DW.Delay_DSTATE_j =
    Rotation_AHRS_GPS_P_g.Delay_InitialCondition_oa;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_jd =
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_IC_lq;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_PrevRe_l = 0;
  Rotation_AHRS_GPS_DW.Delay_DSTATE_l[0] =
    Rotation_AHRS_GPS_P_g.Delay_InitialCondition_e;
  Rotation_AHRS_GPS_DW.Delay_DSTATE_l[1] =
    Rotation_AHRS_GPS_P_g.Delay_InitialCondition_e;
  Rotation_AHRS_GPS_DW.Delay_DSTATE_l[2] =
    Rotation_AHRS_GPS_P_g.Delay_InitialCondition_e;
  Rotation_AHRS_GPS_DW.Delay_DSTATE_l[3] =
    Rotation_AHRS_GPS_P_g.Delay_InitialCondition_e;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_IC_LO_md = 1U;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_PrevR_m4 = 0;
  Rotation_AHRS_GPS_DW.DelayInput1_DSTATE_px =
    Rotation_AHRS_GPS_P_g.DetectIncrease_vinit_l;
  Rotation_AHRS_GPS_DW.DelayInput1_DSTATE_by =
    Rotation_AHRS_GPS_P_g.DetectIncrease3_vinit_j;
  Rotation_A_MovingAverage2_Reset(&Rotation_AHRS_GPS_DW.MovingAverage3);
  Rotation_A_MovingAverage2_Reset(&Rotation_AHRS_GPS_DW.MovingAverage1);
  Rotation_A_MovingAverage2_Reset(&Rotation_AHRS_GPS_DW.MovingAverage2);
}

void Rotation_AHRS_GPS_Start(real32_T rty_Rotation_data_vel_O_O[3])
{
  Rotation_A_MovingAverage2_Start(&Rotation_AHRS_GPS_DW.MovingAverage3);
  Rotation_A_MovingAverage2_Start(&Rotation_AHRS_GPS_DW.MovingAverage1);
  Rotation_A_MovingAverage2_Start(&Rotation_AHRS_GPS_DW.MovingAverage2);
  rty_Rotation_data_vel_O_O[0] = Rotation_AHRS_GPS_P_g.Constant_Value_jz[0];
  rty_Rotation_data_vel_O_O[1] = Rotation_AHRS_GPS_P_g.Constant_Value_jz[1];
  rty_Rotation_data_vel_O_O[2] = Rotation_AHRS_GPS_P_g.Constant_Value_jz[2];
}

void Rotation_AHRS_GPS(const real32_T *rtu_translation_data_h_dot_mDs, const
  real32_T rtu_Sensor_data_rot_IB_B_raw_ra[3], const real32_T
  rtu_Sensor_data_sfor_R_B_mDs2[3], const boolean_T *rtu_Sensor_data_IMU_valid,
  const real32_T rtu_Sensor_data_h_R_B[3], const real32_T
  *rtu_Sensor_data_Mag_Quality, const real32_T *rtu_Sensor_data_GPS_data_Spd_qu,
  const real32_T *rtu_Sensor_data_GPS_data_vel_N, const real32_T
  *rtu_Sensor_data_GPS_data_vel_E, const real32_T
  *rtu_Sensor_data_GPS_data_vel_D, const real32_T
  *rtu_Sensor_data_GPS_data_ant_he, const boolean_T
  *rtu_Sensor_data_GPS_data_headin, const real32_T
  *rtu_Sensor_data_GPS_data_Timest, const boolean_T
  *rtu_Sensor_data_Sonar_data_sona, const real32_T
  *rtu_Sensor_data_Sonar_data_h_gr, const real32_T
  rtu_Sensor_data_Vision_data_vel[2], const real32_T
  *rtu_Sensor_data_Vision_data_Vis, const real32_T
  *rtu_Sensor_data_Vision_data_v_d, const uint8_T
  *rtu_Sensor_data_Vision_data_typ, const boolean_T *rtu_orbit_flag, const
  boolean_T *rtu_dont_reset_yaw, const boolean_T *rtu_hover_flag, const real32_T
  *rtu_h, const boolean_T *rtu_forcedArm, const boolean_T *rtu_Armed, const
  boolean_T *rtu_IMU_switched, const boolean_T *rtu_brake, const real32_T
  rtu_acc_bias_B_est[3], const boolean_T *rtu_stand_still_for_four_second,
  real32_T rty_Rotation_data_vel_O_O[3], real32_T rty_Rotation_data_ATT_quat_OB
  [4], real32_T rty_Rotation_data_M_OB[9], real32_T rty_Rotation_data_att_Oz_B[3],
  real32_T rty_Rotation_data_rot_IB_B_radD[3], real32_T
  rty_Rotation_data_sfor_R_B_mDs2[3], real32_T *rty_Rotation_data_Psi_dot_fused,
  real32_T *rty_Rotation_data_Psi_dot_IMU, real32_T rty_Rotation_data_M_OObar[4],
  real32_T *rty_Rotation_data_Euler_Transfo, real32_T
  *rty_Rotation_data_Euler_Trans_k, real32_T *rty_Rotation_data_Euler_Trans_e,
  real32_T *rty_Rotation_data_Euler_Trans_c, real32_T
  *rty_Rotation_data_Euler_Tran_ez, real32_T *rty_Rotation_data_Euler_Trans_o,
  real32_T *rty_Rotation_data_Euler_Trans_p, real32_T
  *rty_Rotation_data_Heading_Quali, real32_T *rty_Rotation_data_Mag_Quality,
  real32_T rty_Rotation_data_Bias_gyro_rad[3], real32_T
  *rty_Rotation_data_standstill, boolean_T *rty_Rotation_data_reset_Yaw,
  boolean_T *rty_Rotation_data_All_reset_Yaw, boolean_T
  *rty_Rotation_data_rp_init_reset, boolean_T *rty_Rotation_data_heading_init,
  real32_T *rty_det_yaw_gohome, boolean_T *rty_reset_yaw_flag, boolean_T
  *rty_stand_still, boolean_T *rty_att_init_done, boolean_T *rty_rp_init_done,
  real32_T *rty_yaw_mag, real32_T *rty_yaw_rate_bias, real32_T
  rty_roll_pitch_rate_bias[2], boolean_T *rty_once_stand_still)
{
  boolean_T rtb_LogicalOperator12_h;
  boolean_T rtb_Uk1_b;
  boolean_T rtb_DataTypeConversion1_h;
  boolean_T rtb_LogicalOperator1_d;
  boolean_T rtb_DataTypeConversion1_n5;
  boolean_T rtb_FixPtRelationalOperator_pi;
  boolean_T rtb_large_error_detected;
  boolean_T rtb_FixPtRelationalOperator_jv;
  boolean_T rtb_FixPtRelationalOperator_es;
  boolean_T tmp;
  boolean_T rtb_mag_reset2_tmp;
  Rotation_AHRS_GPS_B.Memory2 = !*rtu_IMU_switched;
  Rotation_AHRS_GPS_B.LogicalOperator8_e =
    ((!Rotation_AHRS_GPS_DW.Delay6_DSTATE_m[0]) && Rotation_AHRS_GPS_B.Memory2);
  Rotation_AHRS_GPS_B.i = (int32_T)((uint32_T)
    (Rotation_AHRS_GPS_DW.Delay4_DSTATE_p[0] &&
     Rotation_AHRS_GPS_DW.Delay5_DSTATE_b &&
     Rotation_AHRS_GPS_B.LogicalOperator8_e) +
    (Rotation_AHRS_GPS_DW.Delay_DSTATE_g &&
     Rotation_AHRS_GPS_B.LogicalOperator8_e));
  Rotation_AHRS_GPS_B.DataTypeConversion1_j = (Rotation_AHRS_GPS_B.i != 0);
  if (Rotation_AHRS_GPS_B.DataTypeConversion1_j &&
      (Rotation_AHRS_GPS_PrevZCX.Delay16_Reset_ZCE != POS_ZCSIG)) {
    Rotation_AHRS_GPS_DW.icLoad = 1U;
  }

  Rotation_AHRS_GPS_PrevZCX.Delay16_Reset_ZCE = (ZCSigState)
    (Rotation_AHRS_GPS_B.i != 0);
  if (Rotation_AHRS_GPS_DW.icLoad != 0) {
    for (Rotation_AHRS_GPS_B.i = 0; Rotation_AHRS_GPS_B.i < 7;
         Rotation_AHRS_GPS_B.i++) {
      Rotation_AHRS_GPS_DW.Delay16_DSTATE[Rotation_AHRS_GPS_B.i] =
        Rotation_AHRS_GPS_DW.Delay17_DSTATE[Rotation_AHRS_GPS_B.i];
    }
  }

  Rotation_AHRS_GPS_B.Compare_huc =
    (Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE >
     Rotation_AHRS_GPS_P_g.CompareToConstant_const_h);
  if (Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_IC_LOADI != 0) {
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE_a[0] =
      rtu_Sensor_data_rot_IB_B_raw_ra[0];
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE_a[1] =
      rtu_Sensor_data_rot_IB_B_raw_ra[1];
  }

  Rotation_AHRS_GPS_B.rtb_DiscreteTimeIntegrator_fl_i =
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE_a[0];
  Rotation_AHRS_GPS_B.rtb_DiscreteTimeIntegrator_fl_g =
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE_a[1];
  if (Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_IC_LOA_b != 0) {
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE_g[0] =
      rtu_Sensor_data_rot_IB_B_raw_ra[0];
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE_g[1] =
      rtu_Sensor_data_rot_IB_B_raw_ra[1];
  }

  Rotation_AHRS_GPS_B.rtb_DiscreteTimeIntegrator_fr_i =
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE_g[0];
  Rotation_AHRS_GPS_B.rtb_DiscreteTimeIntegrator1_i_i = (real32_T)fabs
    (Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE_a[0] -
     Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE_g[0]);
  Rotation_AHRS_GPS_B.rtb_DiscreteTimeIntegrator_fr_n =
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE_g[1];
  Rotation_AHRS_GPS_B.rtb_DiscreteTimeIntegrator1_i_f = (real32_T)fabs
    (Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE_a[1] -
     Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE_g[1]);
  if ((Rotation_AHRS_GPS_B.rtb_DiscreteTimeIntegrator1_i_i >
       Rotation_AHRS_GPS_B.rtb_DiscreteTimeIntegrator1_i_f) || rtIsNaNF
      (Rotation_AHRS_GPS_B.rtb_DiscreteTimeIntegrator1_i_f)) {
    Rotation_AHRS_GPS_B.Product_hu =
      Rotation_AHRS_GPS_B.rtb_DiscreteTimeIntegrator1_i_i;
  } else {
    Rotation_AHRS_GPS_B.Product_hu =
      Rotation_AHRS_GPS_B.rtb_DiscreteTimeIntegrator1_i_f;
  }

  if (Rotation_AHRS_GPS_B.Product_hu >
      Rotation_AHRS_GPS_P_g.Saturation1_UpperSat) {
    Rotation_AHRS_GPS_B.Saturation1 = Rotation_AHRS_GPS_P_g.Saturation1_UpperSat;
  } else if (Rotation_AHRS_GPS_B.Product_hu <
             Rotation_AHRS_GPS_P_g.Saturation1_LowerSat) {
    Rotation_AHRS_GPS_B.Saturation1 = Rotation_AHRS_GPS_P_g.Saturation1_LowerSat;
  } else {
    Rotation_AHRS_GPS_B.Saturation1 = Rotation_AHRS_GPS_B.Product_hu;
  }

  if (Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_IC_LOAD != 0) {
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_DSTATE =
      Rotation_AHRS_GPS_B.Saturation1;
  }

  Rotation_AHRS_GPS_B.DiscreteTimeIntegrator1_k =
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_DSTATE;
  if (Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_DSTATE >=
      Rotation_AHRS_GPS_P_g.Relay1_OnVal) {
    Rotation_AHRS_GPS_DW.Relay1_Mode = true;
  } else {
    if (Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_DSTATE <=
        Rotation_AHRS_GPS_P_g.Relay1_OffVal) {
      Rotation_AHRS_GPS_DW.Relay1_Mode = false;
    }
  }

  if (Rotation_AHRS_GPS_DW.Relay1_Mode) {
    Rotation_AHRS_GPS_B.rtb_Product_em_idx_3 = Rotation_AHRS_GPS_P_g.Relay1_YOn;
  } else {
    Rotation_AHRS_GPS_B.rtb_Product_em_idx_3 = Rotation_AHRS_GPS_P_g.Relay1_YOff;
  }

  Rotation_AHRS_GPS_B.trigger_reset = (Rotation_AHRS_GPS_B.Compare_huc &&
    (Rotation_AHRS_GPS_B.rtb_Product_em_idx_3 != 0.0F));
  Rotation_AHRS_GPS_B.LogicalOperator1 = !Rotation_AHRS_GPS_B.trigger_reset;
  if (Rotation_AHRS_GPS_B.LogicalOperator1 ||
      (Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_PrevRese != 0)) {
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE_o =
      Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_IC_k;
  }

  if (Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE_o >=
      Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_UpperS_g) {
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE_o =
      Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_UpperS_g;
  } else {
    if (Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE_o <=
        Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_LowerS_f) {
      Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE_o =
        Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_LowerS_f;
    }
  }

  Rotation_AHRS_GPS_B.LogicalOperator8_e =
    (Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE_o >
     Rotation_AHRS_GPS_P_g.Validaperiod_T_p);
  tmp = !*rtu_Armed;
  *rty_stand_still = (Rotation_AHRS_GPS_B.LogicalOperator8_e && tmp);
  Rotation_AHRS_GPS_B.Memory2 = (Rotation_AHRS_GPS_B.Memory2 && ((int32_T)
    *rty_stand_still <= (int32_T)Rotation_AHRS_GPS_DW.DelayInput1_DSTATE_p));
  Rotation_AHRS_GPS_B.LogicalOperator_e = (Rotation_AHRS_GPS_DW.Delay5_DSTATE_b &&
    Rotation_AHRS_GPS_DW.Delay_DSTATE_m);
  Rotation_AHRS_GPS_B.DataTypeConversion1_ba = ((int32_T)((uint32_T)
    (Rotation_AHRS_GPS_B.LogicalOperator_e && Rotation_AHRS_GPS_B.Memory2) +
    (Rotation_AHRS_GPS_DW.Delay_DSTATE_p && Rotation_AHRS_GPS_B.Memory2)) != 0);
  if (Rotation_AHRS_GPS_B.DataTypeConversion1_ba &&
      (Rotation_AHRS_GPS_PrevZCX.Delay12_Reset_ZCE != POS_ZCSIG)) {
    Rotation_AHRS_GPS_DW.icLoad_h = 1U;
  }

  Rotation_AHRS_GPS_PrevZCX.Delay12_Reset_ZCE = (ZCSigState)((int32_T)((uint32_T)
    (Rotation_AHRS_GPS_B.LogicalOperator_e && Rotation_AHRS_GPS_B.Memory2) +
    (Rotation_AHRS_GPS_DW.Delay_DSTATE_p && Rotation_AHRS_GPS_B.Memory2)) != 0);
  if (Rotation_AHRS_GPS_DW.icLoad_h != 0) {
    for (Rotation_AHRS_GPS_B.i = 0; Rotation_AHRS_GPS_B.i < 7;
         Rotation_AHRS_GPS_B.i++) {
      Rotation_AHRS_GPS_DW.Delay12_DSTATE[Rotation_AHRS_GPS_B.i] =
        Rotation_AHRS_GPS_DW.Delay13_DSTATE[Rotation_AHRS_GPS_B.i];
    }
  }

  Rotation_AHRS_GPS_B.LogicalOperator_e = (Rotation_AHRS_GPS_DW.Delay_DSTATE_k &&
    (!(Rotation_AHRS_GPS_P_g.Constant_Value_n != 0.0F)));
  Rotation_AHRS_GPS_B.LogicalOperator6_m = ((int32_T)((uint32_T)
    (Rotation_AHRS_GPS_DW.Delay_DSTATE_k &&
     (!(Rotation_AHRS_GPS_P_g.Constant_Value_n != 0.0F))) + *rtu_Armed) == 0);
  if (Rotation_AHRS_GPS_B.LogicalOperator6_m ||
      (Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_PrevRes != 0)) {
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_DSTAT_c =
      Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator1_IC;
  }

  Rotation_AHRS_GPS_B.Compare_g =
    (Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_DSTAT_c >=
     Rotation_AHRS_GPS_P_g.CompareToConstant6_const);
  if (Rotation_AHRS_GPS_B.LogicalOperator6_m ||
      (Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_PrevRe_a != 0)) {
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE_i =
      Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_IC_j;
  }

  Rotation_AHRS_GPS_B.Compare_b =
    (Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE_i >=
     Rotation_AHRS_GPS_P_g.CompareToConstant4_const);
  rtb_mag_reset2_tmp = !*rtu_dont_reset_yaw;
  Rotation_AHRS_GPS_B.mag_reset2 = (((rtb_mag_reset2_tmp && ((int32_T)
    Rotation_AHRS_GPS_B.Compare_g > (int32_T)
    Rotation_AHRS_GPS_DW.DelayInput1_DSTATE_i)) || ((int32_T)
    Rotation_AHRS_GPS_B.Compare_b > (int32_T)
    Rotation_AHRS_GPS_DW.DelayInput1_DSTATE_g) || ((int32_T)*rtu_IMU_switched >
    (int32_T)Rotation_AHRS_GPS_DW.DelayInput1_DSTATE_i5)) &&
    (!Rotation_AHRS_GPS_B.DataTypeConversion1_ba) &&
    (!Rotation_AHRS_GPS_B.DataTypeConversion1_j));
  Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_gg = rtu_Sensor_data_h_R_B[0] *
    Rotation_AHRS_GPS_P_g.DiscreteFIRFilter1_Coefficients[0];
  Rotation_AHRS_GPS_B.i = 1;
  Rotation_AHRS_GPS_B.j = Rotation_AHRS_GPS_DW.DiscreteFIRFilter1_circBuf;
  while (Rotation_AHRS_GPS_B.j < 4) {
    Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_gg +=
      Rotation_AHRS_GPS_DW.DiscreteFIRFilter1_states[Rotation_AHRS_GPS_B.j] *
      Rotation_AHRS_GPS_P_g.DiscreteFIRFilter1_Coefficients[Rotation_AHRS_GPS_B.i];
    Rotation_AHRS_GPS_B.i++;
    Rotation_AHRS_GPS_B.j++;
  }

  Rotation_AHRS_GPS_B.j = 0;
  while (Rotation_AHRS_GPS_B.j < Rotation_AHRS_GPS_DW.DiscreteFIRFilter1_circBuf)
  {
    Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_gg +=
      Rotation_AHRS_GPS_DW.DiscreteFIRFilter1_states[Rotation_AHRS_GPS_B.j] *
      Rotation_AHRS_GPS_P_g.DiscreteFIRFilter1_Coefficients[Rotation_AHRS_GPS_B.i];
    Rotation_AHRS_GPS_B.i++;
    Rotation_AHRS_GPS_B.j++;
  }

  Rotation_AHRS_GPS_B.DiscreteFIRFilter1[0] =
    Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_gg;
  Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_gg = rtu_Sensor_data_h_R_B[1] *
    Rotation_AHRS_GPS_P_g.DiscreteFIRFilter1_Coefficients[0];
  Rotation_AHRS_GPS_B.i = 1;
  Rotation_AHRS_GPS_B.j = Rotation_AHRS_GPS_DW.DiscreteFIRFilter1_circBuf;
  while (Rotation_AHRS_GPS_B.j < 4) {
    Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_gg +=
      Rotation_AHRS_GPS_DW.DiscreteFIRFilter1_states[4 + Rotation_AHRS_GPS_B.j] *
      Rotation_AHRS_GPS_P_g.DiscreteFIRFilter1_Coefficients[Rotation_AHRS_GPS_B.i];
    Rotation_AHRS_GPS_B.i++;
    Rotation_AHRS_GPS_B.j++;
  }

  Rotation_AHRS_GPS_B.j = 0;
  while (Rotation_AHRS_GPS_B.j < Rotation_AHRS_GPS_DW.DiscreteFIRFilter1_circBuf)
  {
    Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_gg +=
      Rotation_AHRS_GPS_DW.DiscreteFIRFilter1_states[4 + Rotation_AHRS_GPS_B.j] *
      Rotation_AHRS_GPS_P_g.DiscreteFIRFilter1_Coefficients[Rotation_AHRS_GPS_B.i];
    Rotation_AHRS_GPS_B.i++;
    Rotation_AHRS_GPS_B.j++;
  }

  Rotation_AHRS_GPS_B.DiscreteFIRFilter1[1] =
    Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_gg;
  Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_gg = rtu_Sensor_data_h_R_B[2] *
    Rotation_AHRS_GPS_P_g.DiscreteFIRFilter1_Coefficients[0];
  Rotation_AHRS_GPS_B.i = 1;
  Rotation_AHRS_GPS_B.j = Rotation_AHRS_GPS_DW.DiscreteFIRFilter1_circBuf;
  while (Rotation_AHRS_GPS_B.j < 4) {
    Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_gg +=
      Rotation_AHRS_GPS_DW.DiscreteFIRFilter1_states[8 + Rotation_AHRS_GPS_B.j] *
      Rotation_AHRS_GPS_P_g.DiscreteFIRFilter1_Coefficients[Rotation_AHRS_GPS_B.i];
    Rotation_AHRS_GPS_B.i++;
    Rotation_AHRS_GPS_B.j++;
  }

  Rotation_AHRS_GPS_B.j = 0;
  while (Rotation_AHRS_GPS_B.j < Rotation_AHRS_GPS_DW.DiscreteFIRFilter1_circBuf)
  {
    Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_gg +=
      Rotation_AHRS_GPS_DW.DiscreteFIRFilter1_states[8 + Rotation_AHRS_GPS_B.j] *
      Rotation_AHRS_GPS_P_g.DiscreteFIRFilter1_Coefficients[Rotation_AHRS_GPS_B.i];
    Rotation_AHRS_GPS_B.i++;
    Rotation_AHRS_GPS_B.j++;
  }

  Rotation_AHRS_GPS_B.DiscreteFIRFilter1[2] =
    Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_gg;
  if (Rotation_AHRS_GPS_B.mag_reset2) {
    for (Rotation_AHRS_GPS_B.i = 0; Rotation_AHRS_GPS_B.i < 7;
         Rotation_AHRS_GPS_B.i++) {
      Rotation_AHRS_GPS_B.In1[Rotation_AHRS_GPS_B.i] =
        Rotation_AHRS_GPS_DW.Delay_DSTATE[Rotation_AHRS_GPS_B.i];
    }

    mw_arm_sqrt_f32(((Rotation_AHRS_GPS_B.In1[0] * Rotation_AHRS_GPS_B.In1[0] +
                      Rotation_AHRS_GPS_B.In1[1] * Rotation_AHRS_GPS_B.In1[1]) +
                     Rotation_AHRS_GPS_B.In1[2] * Rotation_AHRS_GPS_B.In1[2]) +
                    Rotation_AHRS_GPS_B.In1[3] * Rotation_AHRS_GPS_B.In1[3],
                    &Rotation_AHRS_GPS_B.Subtract_kk);
    Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_mg = Rotation_AHRS_GPS_B.In1[0] /
      Rotation_AHRS_GPS_B.Subtract_kk;
    Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_pd = Rotation_AHRS_GPS_B.In1[1] /
      Rotation_AHRS_GPS_B.Subtract_kk;
    Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_g5 = Rotation_AHRS_GPS_B.In1[2] /
      Rotation_AHRS_GPS_B.Subtract_kk;
    Rotation_AHRS_GPS_B.Subtract_kk = Rotation_AHRS_GPS_B.In1[3] /
      Rotation_AHRS_GPS_B.Subtract_kk;
    Rotation_AHRS_GPS_B.VectorConcatenate_p[0] =
      ((Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_mg *
        Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_mg +
        Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_pd *
        Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_pd) -
       Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_g5 *
       Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_g5) -
      Rotation_AHRS_GPS_B.Subtract_kk * Rotation_AHRS_GPS_B.Subtract_kk;
    Rotation_AHRS_GPS_B.VectorConcatenate_p[1] =
      (Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_pd *
       Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_g5 -
       Rotation_AHRS_GPS_B.Subtract_kk *
       Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_mg) *
      Rotation_AHRS_GPS_P_g.Gain_Gain_p;
    Rotation_AHRS_GPS_B.VectorConcatenate_p[2] =
      (Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_mg *
       Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_g5 +
       Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_pd *
       Rotation_AHRS_GPS_B.Subtract_kk) * Rotation_AHRS_GPS_P_g.Gain_Gain_ck;
    Rotation_AHRS_GPS_B.VectorConcatenate_p[3] =
      (Rotation_AHRS_GPS_B.Subtract_kk *
       Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_mg +
       Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_pd *
       Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_g5) *
      Rotation_AHRS_GPS_P_g.Gain_Gain_jan;
    Rotation_AHRS_GPS_B.VectorConcatenate_p[4] =
      ((Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_mg *
        Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_mg -
        Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_pd *
        Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_pd) +
       Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_g5 *
       Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_g5) -
      Rotation_AHRS_GPS_B.Subtract_kk * Rotation_AHRS_GPS_B.Subtract_kk;
    Rotation_AHRS_GPS_B.VectorConcatenate_p[5] =
      (Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_g5 *
       Rotation_AHRS_GPS_B.Subtract_kk -
       Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_mg *
       Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_pd) *
      Rotation_AHRS_GPS_P_g.Gain_Gain_pk;
    Rotation_AHRS_GPS_B.VectorConcatenate_p[6] =
      (Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_pd *
       Rotation_AHRS_GPS_B.Subtract_kk -
       Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_mg *
       Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_g5) *
      Rotation_AHRS_GPS_P_g.Gain_Gain_i;
    Rotation_AHRS_GPS_B.VectorConcatenate_p[7] =
      (Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_mg *
       Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_pd +
       Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_g5 *
       Rotation_AHRS_GPS_B.Subtract_kk) * Rotation_AHRS_GPS_P_g.Gain_Gain_g2;
    Rotation_AHRS_GPS_B.VectorConcatenate_p[8] =
      ((Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_mg *
        Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_mg -
        Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_pd *
        Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_pd) -
       Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_g5 *
       Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_g5) +
      Rotation_AHRS_GPS_B.Subtract_kk * Rotation_AHRS_GPS_B.Subtract_kk;
    for (Rotation_AHRS_GPS_B.i = 0; Rotation_AHRS_GPS_B.i < 3;
         Rotation_AHRS_GPS_B.i++) {
      Rotation_AHRS_GPS_B.omg_O[Rotation_AHRS_GPS_B.i] =
        Rotation_AHRS_GPS_B.VectorConcatenate_p[3 * Rotation_AHRS_GPS_B.i + 2] *
        Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_gg +
        (Rotation_AHRS_GPS_B.VectorConcatenate_p[3 * Rotation_AHRS_GPS_B.i + 1] *
         Rotation_AHRS_GPS_B.DiscreteFIRFilter1[1] +
         Rotation_AHRS_GPS_B.VectorConcatenate_p[3 * Rotation_AHRS_GPS_B.i] *
         Rotation_AHRS_GPS_B.DiscreteFIRFilter1[0]);
    }

    Rotation_AHRS_GPS_B.TrigonometricFunction = Rotation_AHRS_GPS_rt_atan2f_snf
      (Rotation_AHRS_GPS_P_g.Gain_Gain_pp * Rotation_AHRS_GPS_B.omg_O[1],
       Rotation_AHRS_GPS_B.omg_O[0]);
    Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_pd =
      Rotation_AHRS_GPS_P_g.Gain_Gain_kc *
      Rotation_AHRS_GPS_B.TrigonometricFunction;
    Rotation_AHRS_GPS_B.rtb_Product_em_idx_3 = arm_sin_f32
      (Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_pd);
    Rotation_AHRS_GPS_B.rtb_Product_em_idx_0 = arm_cos_f32
      (Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_pd);
    Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_pd =
      Rotation_AHRS_GPS_P_g.Constant_Value_p * Rotation_AHRS_GPS_B.In1[2];
    Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_g5 =
      Rotation_AHRS_GPS_P_g.Constant_Value_p * Rotation_AHRS_GPS_B.In1[1];
    Rotation_AHRS_GPS_B.Sum = ((Rotation_AHRS_GPS_B.rtb_Product_em_idx_0 *
      Rotation_AHRS_GPS_B.In1[0] - Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_g5)
      - Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_pd) -
      Rotation_AHRS_GPS_B.rtb_Product_em_idx_3 * Rotation_AHRS_GPS_B.In1[3];
    Rotation_AHRS_GPS_B.rtb_DiscreteTimeIntegrator_l4_i =
      Rotation_AHRS_GPS_P_g.Constant_Value_p * Rotation_AHRS_GPS_B.In1[3];
    Rotation_AHRS_GPS_B.rtb_DiscreteTimeIntegrator_l4_l =
      Rotation_AHRS_GPS_P_g.Constant_Value_p * Rotation_AHRS_GPS_B.In1[0];
    Rotation_AHRS_GPS_B.Sum_e = ((Rotation_AHRS_GPS_B.rtb_Product_em_idx_0 *
      Rotation_AHRS_GPS_B.In1[1] +
      Rotation_AHRS_GPS_B.rtb_DiscreteTimeIntegrator_l4_l) +
      Rotation_AHRS_GPS_B.rtb_DiscreteTimeIntegrator_l4_i) -
      Rotation_AHRS_GPS_B.rtb_Product_em_idx_3 * Rotation_AHRS_GPS_B.In1[2];
    Rotation_AHRS_GPS_B.Sum_h = ((Rotation_AHRS_GPS_B.rtb_Product_em_idx_0 *
      Rotation_AHRS_GPS_B.In1[2] -
      Rotation_AHRS_GPS_B.rtb_DiscreteTimeIntegrator_l4_i) +
      Rotation_AHRS_GPS_B.rtb_DiscreteTimeIntegrator_l4_l) +
      Rotation_AHRS_GPS_B.rtb_Product_em_idx_3 * Rotation_AHRS_GPS_B.In1[1];
    Rotation_AHRS_GPS_B.Sum_hp = ((Rotation_AHRS_GPS_B.rtb_Product_em_idx_0 *
      Rotation_AHRS_GPS_B.In1[3] + Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_pd)
      - Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_g5) +
      Rotation_AHRS_GPS_B.rtb_Product_em_idx_3 * Rotation_AHRS_GPS_B.In1[0];
  }

  Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_pd = (real32_T)fabs
    (rtu_Sensor_data_rot_IB_B_raw_ra[2]);
  if (Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_IC_LOA_d != 0) {
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_gs =
      Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_pd;
  }

  Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_g5 =
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_gs;
  Rotation_AHRS_GPS_B.enable =
    ((Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_gs <=
      Rotation_AHRS_GPS_P_g.CompareToConstant_const_i) && (*rtu_Armed) &&
     (*rtu_hover_flag));
  if (Rotation_AHRS_GPS_B.enable) {
    if (Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_IC_LOA_e != 0) {
      Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_hz[0] =
        rtu_acc_bias_B_est[0];
      Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_hz[1] =
        rtu_acc_bias_B_est[1];
      Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_hz[2] =
        rtu_acc_bias_B_est[2];
    }

    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_IC_LOA_e = 0U;
    Rotation_AHRS_GPS_B.DiscreteTimeIntegrator[0] =
      Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_hz[0];
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_hz[0] +=
      (rtu_acc_bias_B_est[0] - Rotation_AHRS_GPS_B.DiscreteTimeIntegrator[0]) *
      Rotation_AHRS_GPS_P_g.Gain_Gain_ca *
      Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_gainval;
    Rotation_AHRS_GPS_B.DiscreteTimeIntegrator[1] =
      Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_hz[1];
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_hz[1] +=
      (rtu_acc_bias_B_est[1] - Rotation_AHRS_GPS_B.DiscreteTimeIntegrator[1]) *
      Rotation_AHRS_GPS_P_g.Gain_Gain_ca *
      Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_gainval;
    Rotation_AHRS_GPS_B.DiscreteTimeIntegrator[2] =
      Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_hz[2];
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_hz[2] +=
      (rtu_acc_bias_B_est[2] - Rotation_AHRS_GPS_B.DiscreteTimeIntegrator[2]) *
      Rotation_AHRS_GPS_P_g.Gain_Gain_ca *
      Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_gainval;
  }

  if (Rotation_AHRS_GPS_B.DiscreteTimeIntegrator[0] >
      Rotation_AHRS_GPS_P_g.Saturation_UpperSat_h) {
    Rotation_AHRS_GPS_B.rtb_Product_em_idx_3 =
      Rotation_AHRS_GPS_P_g.Saturation_UpperSat_h;
  } else if (Rotation_AHRS_GPS_B.DiscreteTimeIntegrator[0] <
             Rotation_AHRS_GPS_P_g.Saturation_LowerSat_e) {
    Rotation_AHRS_GPS_B.rtb_Product_em_idx_3 =
      Rotation_AHRS_GPS_P_g.Saturation_LowerSat_e;
  } else {
    Rotation_AHRS_GPS_B.rtb_Product_em_idx_3 =
      Rotation_AHRS_GPS_B.DiscreteTimeIntegrator[0];
  }

  Rotation_AHRS_GPS_B.acc_body[0] = rtu_Sensor_data_sfor_R_B_mDs2[0] -
    Rotation_AHRS_GPS_P_g.Gain_Gain_f5[0] *
    Rotation_AHRS_GPS_B.rtb_Product_em_idx_3;
  if (Rotation_AHRS_GPS_B.DiscreteTimeIntegrator[1] >
      Rotation_AHRS_GPS_P_g.Saturation_UpperSat_h) {
    Rotation_AHRS_GPS_B.rtb_Product_em_idx_3 =
      Rotation_AHRS_GPS_P_g.Saturation_UpperSat_h;
  } else if (Rotation_AHRS_GPS_B.DiscreteTimeIntegrator[1] <
             Rotation_AHRS_GPS_P_g.Saturation_LowerSat_e) {
    Rotation_AHRS_GPS_B.rtb_Product_em_idx_3 =
      Rotation_AHRS_GPS_P_g.Saturation_LowerSat_e;
  } else {
    Rotation_AHRS_GPS_B.rtb_Product_em_idx_3 =
      Rotation_AHRS_GPS_B.DiscreteTimeIntegrator[1];
  }

  Rotation_AHRS_GPS_B.acc_body[1] = rtu_Sensor_data_sfor_R_B_mDs2[1] -
    Rotation_AHRS_GPS_P_g.Gain_Gain_f5[1] *
    Rotation_AHRS_GPS_B.rtb_Product_em_idx_3;
  if (Rotation_AHRS_GPS_B.DiscreteTimeIntegrator[2] >
      Rotation_AHRS_GPS_P_g.Saturation_UpperSat_h) {
    Rotation_AHRS_GPS_B.rtb_Product_em_idx_3 =
      Rotation_AHRS_GPS_P_g.Saturation_UpperSat_h;
  } else if (Rotation_AHRS_GPS_B.DiscreteTimeIntegrator[2] <
             Rotation_AHRS_GPS_P_g.Saturation_LowerSat_e) {
    Rotation_AHRS_GPS_B.rtb_Product_em_idx_3 =
      Rotation_AHRS_GPS_P_g.Saturation_LowerSat_e;
  } else {
    Rotation_AHRS_GPS_B.rtb_Product_em_idx_3 =
      Rotation_AHRS_GPS_B.DiscreteTimeIntegrator[2];
  }

  Rotation_AHRS_GPS_B.acc_body[2] = rtu_Sensor_data_sfor_R_B_mDs2[2] -
    Rotation_AHRS_GPS_P_g.Gain_Gain_f5[2] *
    Rotation_AHRS_GPS_B.rtb_Product_em_idx_3;
  if (Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_IC_LOA_h != 0) {
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_oe[0] =
      Rotation_AHRS_GPS_B.acc_body[0];
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_oe[1] =
      Rotation_AHRS_GPS_B.acc_body[1];
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_oe[2] =
      Rotation_AHRS_GPS_B.acc_body[2];
  }

  Rotation_AHRS_GPS_B.rtb_DiscreteTimeIntegrator_l4_i =
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_oe[0];
  Rotation_AHRS_GPS_B.rtb_DiscreteTimeIntegrator_l4_l =
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_oe[1];
  Rotation_AHRS_GPS_B.rtb_DiscreteTimeIntegrator_l4_j =
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_oe[2];
  mw_arm_sqrt_f32((Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_oe[1] *
                   Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_oe[1] +
                   Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_oe[0] *
                   Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_oe[0]) +
                  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_oe[2] *
                  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_oe[2],
                  &Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_gg);
  Rotation_AHRS_GPS_B.Compare_on = (tmp && (*rtu_forcedArm) && ((real32_T)fabs
    (Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_oe[0]) <=
    Rotation_AHRS_GPS_P_g.CompareToConstant2_const) && ((real32_T)fabs
    (Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_oe[1]) <=
    Rotation_AHRS_GPS_P_g.CompareToConstant1_const_l) && ((real32_T)fabs
    (Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_oe[2] +
     Rotation_AHRS_GPS_P_g.Bias_Bias_c) <=
    Rotation_AHRS_GPS_P_g.CompareToConstant_const_j) &&
    (Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_gg +
     Rotation_AHRS_GPS_P_g.Bias1_Bias <=
     Rotation_AHRS_GPS_P_g.CompareToConstant3_const));
  Rotation_AHRS_GPS_B.Memory2 = Rotation_AHRS_GPS_DW.Memory2_PreviousInput;
  Rotation_AHRS_GPS_B.Compare_m = ((int32_T)
    Rotation_AHRS_GPS_DW.Memory2_PreviousInput > (int32_T)
    Rotation_AHRS_GPS_P_g.Constant_Value_ek);
  Rotation_AHRS_GPS_B.LogicalOperator18 = ((int32_T)
    Rotation_AHRS_GPS_B.Compare_m > (int32_T)
    Rotation_AHRS_GPS_DW.DelayInput1_DSTATE_b);
  Rotation_AHRS_GPS_B.LogicalOperator1_i = (Rotation_AHRS_GPS_B.Compare_on ||
    Rotation_AHRS_GPS_B.LogicalOperator18);
  Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_gg = Rotation_AHRS_GPS_B.acc_body[0]
    * Rotation_AHRS_GPS_P_g.DiscreteFIRFilter_Coefficients[0];
  Rotation_AHRS_GPS_B.i = 1;
  Rotation_AHRS_GPS_B.j = Rotation_AHRS_GPS_DW.DiscreteFIRFilter_circBuf;
  while (Rotation_AHRS_GPS_B.j < 4) {
    Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_gg +=
      Rotation_AHRS_GPS_DW.DiscreteFIRFilter_states[Rotation_AHRS_GPS_B.j] *
      Rotation_AHRS_GPS_P_g.DiscreteFIRFilter_Coefficients[Rotation_AHRS_GPS_B.i];
    Rotation_AHRS_GPS_B.i++;
    Rotation_AHRS_GPS_B.j++;
  }

  Rotation_AHRS_GPS_B.j = 0;
  while (Rotation_AHRS_GPS_B.j < Rotation_AHRS_GPS_DW.DiscreteFIRFilter_circBuf)
  {
    Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_gg +=
      Rotation_AHRS_GPS_DW.DiscreteFIRFilter_states[Rotation_AHRS_GPS_B.j] *
      Rotation_AHRS_GPS_P_g.DiscreteFIRFilter_Coefficients[Rotation_AHRS_GPS_B.i];
    Rotation_AHRS_GPS_B.i++;
    Rotation_AHRS_GPS_B.j++;
  }

  Rotation_AHRS_GPS_B.DiscreteFIRFilter[0] =
    Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_gg;
  Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_gg = Rotation_AHRS_GPS_B.acc_body[1]
    * Rotation_AHRS_GPS_P_g.DiscreteFIRFilter_Coefficients[0];
  Rotation_AHRS_GPS_B.i = 1;
  Rotation_AHRS_GPS_B.j = Rotation_AHRS_GPS_DW.DiscreteFIRFilter_circBuf;
  while (Rotation_AHRS_GPS_B.j < 4) {
    Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_gg +=
      Rotation_AHRS_GPS_DW.DiscreteFIRFilter_states[4 + Rotation_AHRS_GPS_B.j] *
      Rotation_AHRS_GPS_P_g.DiscreteFIRFilter_Coefficients[Rotation_AHRS_GPS_B.i];
    Rotation_AHRS_GPS_B.i++;
    Rotation_AHRS_GPS_B.j++;
  }

  Rotation_AHRS_GPS_B.j = 0;
  while (Rotation_AHRS_GPS_B.j < Rotation_AHRS_GPS_DW.DiscreteFIRFilter_circBuf)
  {
    Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_gg +=
      Rotation_AHRS_GPS_DW.DiscreteFIRFilter_states[4 + Rotation_AHRS_GPS_B.j] *
      Rotation_AHRS_GPS_P_g.DiscreteFIRFilter_Coefficients[Rotation_AHRS_GPS_B.i];
    Rotation_AHRS_GPS_B.i++;
    Rotation_AHRS_GPS_B.j++;
  }

  Rotation_AHRS_GPS_B.DiscreteFIRFilter[1] =
    Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_gg;
  Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_gg = Rotation_AHRS_GPS_B.acc_body[2]
    * Rotation_AHRS_GPS_P_g.DiscreteFIRFilter_Coefficients[0];
  Rotation_AHRS_GPS_B.i = 1;
  Rotation_AHRS_GPS_B.j = Rotation_AHRS_GPS_DW.DiscreteFIRFilter_circBuf;
  while (Rotation_AHRS_GPS_B.j < 4) {
    Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_gg +=
      Rotation_AHRS_GPS_DW.DiscreteFIRFilter_states[8 + Rotation_AHRS_GPS_B.j] *
      Rotation_AHRS_GPS_P_g.DiscreteFIRFilter_Coefficients[Rotation_AHRS_GPS_B.i];
    Rotation_AHRS_GPS_B.i++;
    Rotation_AHRS_GPS_B.j++;
  }

  Rotation_AHRS_GPS_B.j = 0;
  while (Rotation_AHRS_GPS_B.j < Rotation_AHRS_GPS_DW.DiscreteFIRFilter_circBuf)
  {
    Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_gg +=
      Rotation_AHRS_GPS_DW.DiscreteFIRFilter_states[8 + Rotation_AHRS_GPS_B.j] *
      Rotation_AHRS_GPS_P_g.DiscreteFIRFilter_Coefficients[Rotation_AHRS_GPS_B.i];
    Rotation_AHRS_GPS_B.i++;
    Rotation_AHRS_GPS_B.j++;
  }

  Rotation_AHRS_GPS_B.DiscreteFIRFilter[2] =
    Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_gg;
  Rotation_AHRS_GPS_B.Compare_if = ((int32_T)Rotation_AHRS_GPS_B.Compare_huc >
    (int32_T)Rotation_AHRS_GPS_P_g.Constant_Value_mgr);
  Rotation_AHRS_GPS_B.FixPtRelationalOperator_m = ((int32_T)
    Rotation_AHRS_GPS_B.Compare_if > (int32_T)
    Rotation_AHRS_GPS_DW.DelayInput1_DSTATE_h);
  if (Rotation_AHRS_GPS_B.FixPtRelationalOperator_m ||
      (Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_PrevRe_f != 0)) {
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE_m =
      Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_IC_d;
  }

  Rotation_AHRS_GPS_B.LogicalOperator_f = (Rotation_AHRS_GPS_DW.Delay_DSTATE_c &&
    (!(Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE_m >=
       Rotation_AHRS_GPS_P_g.CompareTo1sec_const)));
  Rotation_AHRS_GPS_B.rtb_Product_em_idx_3 = (Rotation_AHRS_GPS_B.acc_body[0] *
    Rotation_AHRS_GPS_B.acc_body[0] + Rotation_AHRS_GPS_B.acc_body[1] *
    Rotation_AHRS_GPS_B.acc_body[1]) + Rotation_AHRS_GPS_B.acc_body[2] *
    Rotation_AHRS_GPS_B.acc_body[2];
  Rotation_AHRS_GPS_B.Compare_ep =
    (Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE_b >=
     Rotation_AHRS_GPS_P_g.CompareToConstant1_const_k);
  *rty_once_stand_still = ((int32_T)((uint32_T)*rtu_stand_still_for_four_second
    + Rotation_AHRS_GPS_DW.Delay_DSTATE_e) != 0);
  Rotation_AHRS_GPS_B.LogicalOperator3_f = (Rotation_AHRS_GPS_B.Compare_on ||
    (((int32_T)((uint32_T)(Rotation_AHRS_GPS_DW.Delay_DSTATE_c &&
    (!(Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE_m >=
       Rotation_AHRS_GPS_P_g.CompareTo1sec_const))) +
                Rotation_AHRS_GPS_B.FixPtRelationalOperator_m) != 0) ||
     ((Rotation_AHRS_GPS_P_g.IntervalTest_lowlimit <=
       Rotation_AHRS_GPS_B.rtb_Product_em_idx_3) &&
      (Rotation_AHRS_GPS_B.rtb_Product_em_idx_3 <=
       Rotation_AHRS_GPS_P_g.IntervalTest_uplimit) &&
      Rotation_AHRS_GPS_B.LogicalOperator18) || ((int32_T)
    Rotation_AHRS_GPS_B.Compare_ep > (int32_T)
    Rotation_AHRS_GPS_DW.DelayInput1_DSTATE_ft) || ((int32_T)
    *rty_once_stand_still > (int32_T)Rotation_AHRS_GPS_DW.DelayInput1_DSTATE_n)));
  if (Rotation_AHRS_GPS_B.LogicalOperator3_f) {
    if (Rotation_AHRS_GPS_B.LogicalOperator1_i) {
      mw_arm_sqrt_f32(((Rotation_AHRS_GPS_DW.Delay_DSTATE[0] *
                        Rotation_AHRS_GPS_DW.Delay_DSTATE[0] +
                        Rotation_AHRS_GPS_DW.Delay_DSTATE[1] *
                        Rotation_AHRS_GPS_DW.Delay_DSTATE[1]) +
                       Rotation_AHRS_GPS_DW.Delay_DSTATE[2] *
                       Rotation_AHRS_GPS_DW.Delay_DSTATE[2]) +
                      Rotation_AHRS_GPS_DW.Delay_DSTATE[3] *
                      Rotation_AHRS_GPS_DW.Delay_DSTATE[3],
                      &Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_gg);
      Rotation_AHRS_GPS_B.Product_dn = Rotation_AHRS_GPS_DW.Delay_DSTATE[3] /
        Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_gg;
      Rotation_AHRS_GPS_B.Product2_n2 = Rotation_AHRS_GPS_DW.Delay_DSTATE[2] /
        Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_gg;
      Rotation_AHRS_GPS_B.Product3_k = Rotation_AHRS_GPS_DW.Delay_DSTATE[1] /
        Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_gg;
      Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_gg =
        Rotation_AHRS_GPS_DW.Delay_DSTATE[0] /
        Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_gg;
      Rotation_AHRS_GPS_B.VectorConcatenate_i[8] =
        ((Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_gg *
          Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_gg -
          Rotation_AHRS_GPS_B.Product3_k * Rotation_AHRS_GPS_B.Product3_k) -
         Rotation_AHRS_GPS_B.Product2_n2 * Rotation_AHRS_GPS_B.Product2_n2) +
        Rotation_AHRS_GPS_B.Product_dn * Rotation_AHRS_GPS_B.Product_dn;
      Rotation_AHRS_GPS_B.VectorConcatenate_i[7] =
        (Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_gg *
         Rotation_AHRS_GPS_B.Product3_k + Rotation_AHRS_GPS_B.Product2_n2 *
         Rotation_AHRS_GPS_B.Product_dn) * Rotation_AHRS_GPS_P_g.Gain_Gain_j;
      Rotation_AHRS_GPS_B.VectorConcatenate_i[6] =
        (Rotation_AHRS_GPS_B.Product3_k * Rotation_AHRS_GPS_B.Product_dn -
         Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_gg *
         Rotation_AHRS_GPS_B.Product2_n2) * Rotation_AHRS_GPS_P_g.Gain_Gain_d;
      Rotation_AHRS_GPS_B.VectorConcatenate_i[5] =
        (Rotation_AHRS_GPS_B.Product2_n2 * Rotation_AHRS_GPS_B.Product_dn -
         Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_gg *
         Rotation_AHRS_GPS_B.Product3_k) * Rotation_AHRS_GPS_P_g.Gain_Gain_dp;
      Rotation_AHRS_GPS_B.VectorConcatenate_i[4] =
        ((Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_gg *
          Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_gg -
          Rotation_AHRS_GPS_B.Product3_k * Rotation_AHRS_GPS_B.Product3_k) +
         Rotation_AHRS_GPS_B.Product2_n2 * Rotation_AHRS_GPS_B.Product2_n2) -
        Rotation_AHRS_GPS_B.Product_dn * Rotation_AHRS_GPS_B.Product_dn;
      Rotation_AHRS_GPS_B.VectorConcatenate_i[3] =
        (Rotation_AHRS_GPS_B.Product_dn *
         Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_gg +
         Rotation_AHRS_GPS_B.Product3_k * Rotation_AHRS_GPS_B.Product2_n2) *
        Rotation_AHRS_GPS_P_g.Gain_Gain_fw;
      Rotation_AHRS_GPS_B.VectorConcatenate_i[2] =
        (Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_gg *
         Rotation_AHRS_GPS_B.Product2_n2 + Rotation_AHRS_GPS_B.Product3_k *
         Rotation_AHRS_GPS_B.Product_dn) * Rotation_AHRS_GPS_P_g.Gain_Gain_k;
      Rotation_AHRS_GPS_B.VectorConcatenate_i[1] =
        (Rotation_AHRS_GPS_B.Product3_k * Rotation_AHRS_GPS_B.Product2_n2 -
         Rotation_AHRS_GPS_B.Product_dn *
         Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_gg) *
        Rotation_AHRS_GPS_P_g.Gain_Gain_c3;
      Rotation_AHRS_GPS_B.VectorConcatenate_i[0] =
        ((Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_gg *
          Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_gg +
          Rotation_AHRS_GPS_B.Product3_k * Rotation_AHRS_GPS_B.Product3_k) -
         Rotation_AHRS_GPS_B.Product2_n2 * Rotation_AHRS_GPS_B.Product2_n2) -
        Rotation_AHRS_GPS_B.Product_dn * Rotation_AHRS_GPS_B.Product_dn;
      for (Rotation_AHRS_GPS_B.i = 0; Rotation_AHRS_GPS_B.i < 3;
           Rotation_AHRS_GPS_B.i++) {
        Rotation_AHRS_GPS_B.Switch[Rotation_AHRS_GPS_B.i + 4] =
          Rotation_AHRS_GPS_P_g.Constant1_Value_p[Rotation_AHRS_GPS_B.i];
        Rotation_AHRS_GPS_B.omg_O[Rotation_AHRS_GPS_B.i] =
          Rotation_AHRS_GPS_B.VectorConcatenate_i[3 * Rotation_AHRS_GPS_B.i + 2]
          * Rotation_AHRS_GPS_B.DiscreteFIRFilter1[2] +
          (Rotation_AHRS_GPS_B.VectorConcatenate_i[3 * Rotation_AHRS_GPS_B.i + 1]
           * Rotation_AHRS_GPS_B.DiscreteFIRFilter1[1] +
           Rotation_AHRS_GPS_B.VectorConcatenate_i[3 * Rotation_AHRS_GPS_B.i] *
           Rotation_AHRS_GPS_B.DiscreteFIRFilter1[0]);
      }

      Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_gg =
        Rotation_AHRS_GPS_rt_atan2f_snf(Rotation_AHRS_GPS_P_g.Gain_Gain_ja *
        Rotation_AHRS_GPS_B.omg_O[1], Rotation_AHRS_GPS_B.omg_O[0]) *
        Rotation_AHRS_GPS_P_g.Gain_Gain_nk;
      Rotation_AHRS_GPS_B.rtb_Product_em_idx_3 = arm_sin_f32
        (Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_gg);
      Rotation_AHRS_GPS_B.rtb_Product_em_idx_0 = arm_cos_f32
        (Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_gg);
      Rotation_AHRS_GPS_B.rtb_DiscreteTimeIntegrator1_i_i =
        Rotation_AHRS_GPS_P_g.Constant_Value_f *
        Rotation_AHRS_GPS_DW.Delay_DSTATE[2];
      Rotation_AHRS_GPS_B.rtb_DiscreteTimeIntegrator1_i_f =
        Rotation_AHRS_GPS_P_g.Constant_Value_f *
        Rotation_AHRS_GPS_DW.Delay_DSTATE[1];
      Rotation_AHRS_GPS_B.Switch[0] = ((Rotation_AHRS_GPS_B.rtb_Product_em_idx_0
        * Rotation_AHRS_GPS_DW.Delay_DSTATE[0] -
        Rotation_AHRS_GPS_B.rtb_DiscreteTimeIntegrator1_i_f) -
        Rotation_AHRS_GPS_B.rtb_DiscreteTimeIntegrator1_i_i) -
        Rotation_AHRS_GPS_B.rtb_Product_em_idx_3 *
        Rotation_AHRS_GPS_DW.Delay_DSTATE[3];
      Rotation_AHRS_GPS_B.rtb_acc_GPS_est_idx_0 =
        Rotation_AHRS_GPS_P_g.Constant_Value_f *
        Rotation_AHRS_GPS_DW.Delay_DSTATE[3];
      Rotation_AHRS_GPS_B.rtb_acc_GPS_est_idx_1 =
        Rotation_AHRS_GPS_P_g.Constant_Value_f *
        Rotation_AHRS_GPS_DW.Delay_DSTATE[0];
      Rotation_AHRS_GPS_B.Switch[1] = ((Rotation_AHRS_GPS_B.rtb_Product_em_idx_0
        * Rotation_AHRS_GPS_DW.Delay_DSTATE[1] +
        Rotation_AHRS_GPS_B.rtb_acc_GPS_est_idx_1) +
        Rotation_AHRS_GPS_B.rtb_acc_GPS_est_idx_0) -
        Rotation_AHRS_GPS_B.rtb_Product_em_idx_3 *
        Rotation_AHRS_GPS_DW.Delay_DSTATE[2];
      Rotation_AHRS_GPS_B.Switch[2] = ((Rotation_AHRS_GPS_B.rtb_Product_em_idx_0
        * Rotation_AHRS_GPS_DW.Delay_DSTATE[2] -
        Rotation_AHRS_GPS_B.rtb_acc_GPS_est_idx_0) +
        Rotation_AHRS_GPS_B.rtb_acc_GPS_est_idx_1) +
        Rotation_AHRS_GPS_B.rtb_Product_em_idx_3 *
        Rotation_AHRS_GPS_DW.Delay_DSTATE[1];
      Rotation_AHRS_GPS_B.Switch[3] = ((Rotation_AHRS_GPS_B.rtb_Product_em_idx_0
        * Rotation_AHRS_GPS_DW.Delay_DSTATE[3] +
        Rotation_AHRS_GPS_B.rtb_DiscreteTimeIntegrator1_i_i) -
        Rotation_AHRS_GPS_B.rtb_DiscreteTimeIntegrator1_i_f) +
        Rotation_AHRS_GPS_B.rtb_Product_em_idx_3 *
        Rotation_AHRS_GPS_DW.Delay_DSTATE[0];
    } else {
      mw_arm_sqrt_f32((Rotation_AHRS_GPS_B.DiscreteFIRFilter[0] *
                       Rotation_AHRS_GPS_B.DiscreteFIRFilter[0] +
                       Rotation_AHRS_GPS_B.DiscreteFIRFilter[1] *
                       Rotation_AHRS_GPS_B.DiscreteFIRFilter[1]) +
                      Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_gg *
                      Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_gg,
                      &Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_gg);
      if ((!(Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_gg >
             Rotation_AHRS_GPS_P_g.Normalization_Min_Mag)) && (!rtIsNaNF
           (Rotation_AHRS_GPS_P_g.Normalization_Min_Mag))) {
        Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_gg =
          Rotation_AHRS_GPS_P_g.Normalization_Min_Mag;
      }

      Rotation_AHRS_GPS_B.DiscreteFIRFilter[0] /=
        Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_gg;
      Rotation_AHRS_GPS_B.DiscreteFIRFilter[1] /=
        Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_gg;
      Rotation_AHRS_GPS_B.rtb_Product_em_idx_3 =
        Rotation_AHRS_GPS_B.DiscreteFIRFilter[1];
      if (Rotation_AHRS_GPS_B.DiscreteFIRFilter[0] >
          Rotation_AHRS_GPS_P_g.Saturation_UpperSat_e) {
        Rotation_AHRS_GPS_B.u0 = Rotation_AHRS_GPS_P_g.Saturation_UpperSat_e;
      } else if (Rotation_AHRS_GPS_B.DiscreteFIRFilter[0] <
                 Rotation_AHRS_GPS_P_g.Saturation_LowerSat_n2) {
        Rotation_AHRS_GPS_B.u0 = Rotation_AHRS_GPS_P_g.Saturation_LowerSat_n2;
      } else {
        Rotation_AHRS_GPS_B.u0 = Rotation_AHRS_GPS_B.DiscreteFIRFilter[0];
      }

      Rotation_AHRS_GPS_B.DiscreteFIRFilter[0] = Rotation_AHRS_GPS_P_g.u2_Gain *
        Rotation_AHRS_GPS_P_g.Zero_Yaw_Value;
      if (Rotation_AHRS_GPS_B.u0 > 1.0F) {
        Rotation_AHRS_GPS_B.u0 = 1.0F;
      } else {
        if (Rotation_AHRS_GPS_B.u0 < -1.0F) {
          Rotation_AHRS_GPS_B.u0 = -1.0F;
        }
      }

      Rotation_AHRS_GPS_B.DiscreteFIRFilter[1] = Rotation_AHRS_GPS_P_g.u2_Gain *
        (real32_T)asin(Rotation_AHRS_GPS_B.u0);
      Rotation_AHRS_GPS_B.DiscreteFIRFilter[2] = Rotation_AHRS_GPS_rt_atan2f_snf
        (Rotation_AHRS_GPS_P_g.Gain_Gain_b *
         Rotation_AHRS_GPS_B.rtb_Product_em_idx_3,
         Rotation_AHRS_GPS_B.DiscreteFIRFilter[2] /
         Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_gg *
         Rotation_AHRS_GPS_P_g.Gain1_Gain) * Rotation_AHRS_GPS_P_g.u2_Gain;
      Rotation_AHRS_GPS_B.MatrixMultiply_m[0] = arm_cos_f32
        (Rotation_AHRS_GPS_B.DiscreteFIRFilter[0]);
      Rotation_AHRS_GPS_B.DiscreteFIRFilter[0] = arm_sin_f32
        (Rotation_AHRS_GPS_B.DiscreteFIRFilter[0]);
      Rotation_AHRS_GPS_B.MatrixMultiply_m[1] = arm_cos_f32
        (Rotation_AHRS_GPS_B.DiscreteFIRFilter[1]);
      Rotation_AHRS_GPS_B.DiscreteFIRFilter[1] = arm_sin_f32
        (Rotation_AHRS_GPS_B.DiscreteFIRFilter[1]);
      Rotation_AHRS_GPS_B.MatrixMultiply_m[2] = arm_cos_f32
        (Rotation_AHRS_GPS_B.DiscreteFIRFilter[2]);
      Rotation_AHRS_GPS_B.rtb_DiscreteTimeIntegrator1_i_i = arm_sin_f32
        (Rotation_AHRS_GPS_B.DiscreteFIRFilter[2]);
      Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_gg =
        Rotation_AHRS_GPS_B.MatrixMultiply_m[0] *
        Rotation_AHRS_GPS_B.DiscreteFIRFilter[1];
      Rotation_AHRS_GPS_B.rtb_Product_em_idx_3 =
        Rotation_AHRS_GPS_B.DiscreteFIRFilter[0] *
        Rotation_AHRS_GPS_B.MatrixMultiply_m[1];
      Rotation_AHRS_GPS_B.Product_dn = Rotation_AHRS_GPS_B.rtb_Product_em_idx_3 *
        Rotation_AHRS_GPS_B.MatrixMultiply_m[2] -
        Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_gg *
        Rotation_AHRS_GPS_B.rtb_DiscreteTimeIntegrator1_i_i;
      Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_gg =
        Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_gg *
        Rotation_AHRS_GPS_B.MatrixMultiply_m[2] +
        Rotation_AHRS_GPS_B.rtb_Product_em_idx_3 *
        Rotation_AHRS_GPS_B.rtb_DiscreteTimeIntegrator1_i_i;
      Rotation_AHRS_GPS_B.rtb_Product_em_idx_3 =
        Rotation_AHRS_GPS_B.MatrixMultiply_m[0] *
        Rotation_AHRS_GPS_B.MatrixMultiply_m[1];
      Rotation_AHRS_GPS_B.rtb_Product_em_idx_0 =
        Rotation_AHRS_GPS_B.DiscreteFIRFilter[0] *
        Rotation_AHRS_GPS_B.DiscreteFIRFilter[1];
      Rotation_AHRS_GPS_B.Product2_n2 = Rotation_AHRS_GPS_B.rtb_Product_em_idx_3
        * Rotation_AHRS_GPS_B.rtb_DiscreteTimeIntegrator1_i_i -
        Rotation_AHRS_GPS_B.rtb_Product_em_idx_0 *
        Rotation_AHRS_GPS_B.MatrixMultiply_m[2];
      Rotation_AHRS_GPS_B.Product3_k = Rotation_AHRS_GPS_B.rtb_Product_em_idx_3 *
        Rotation_AHRS_GPS_B.MatrixMultiply_m[2] +
        Rotation_AHRS_GPS_B.rtb_Product_em_idx_0 *
        Rotation_AHRS_GPS_B.rtb_DiscreteTimeIntegrator1_i_i;
      mw_arm_sqrt_f32(((Rotation_AHRS_GPS_B.Product3_k *
                        Rotation_AHRS_GPS_B.Product3_k +
                        Rotation_AHRS_GPS_B.Product2_n2 *
                        Rotation_AHRS_GPS_B.Product2_n2) +
                       Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_gg *
                       Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_gg) +
                      Rotation_AHRS_GPS_B.Product_dn *
                      Rotation_AHRS_GPS_B.Product_dn,
                      &Rotation_AHRS_GPS_B.Product_ge);
      Rotation_AHRS_GPS_B.Product1_h1 = Rotation_AHRS_GPS_B.Product_dn /
        Rotation_AHRS_GPS_B.Product_ge;
      Rotation_AHRS_GPS_B.Product2_lr =
        Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_gg /
        Rotation_AHRS_GPS_B.Product_ge;
      Rotation_AHRS_GPS_B.Product3_jr = Rotation_AHRS_GPS_B.Product2_n2 /
        Rotation_AHRS_GPS_B.Product_ge;
      Rotation_AHRS_GPS_B.Product_ge = Rotation_AHRS_GPS_B.Product3_k /
        Rotation_AHRS_GPS_B.Product_ge;
      Rotation_AHRS_GPS_B.VectorConcatenate_i[8] =
        ((Rotation_AHRS_GPS_B.Product_ge * Rotation_AHRS_GPS_B.Product_ge -
          Rotation_AHRS_GPS_B.Product3_jr * Rotation_AHRS_GPS_B.Product3_jr) -
         Rotation_AHRS_GPS_B.Product2_lr * Rotation_AHRS_GPS_B.Product2_lr) +
        Rotation_AHRS_GPS_B.Product1_h1 * Rotation_AHRS_GPS_B.Product1_h1;
      Rotation_AHRS_GPS_B.VectorConcatenate_i[7] =
        (Rotation_AHRS_GPS_B.Product_ge * Rotation_AHRS_GPS_B.Product3_jr +
         Rotation_AHRS_GPS_B.Product2_lr * Rotation_AHRS_GPS_B.Product1_h1) *
        Rotation_AHRS_GPS_P_g.Gain_Gain_g;
      Rotation_AHRS_GPS_B.VectorConcatenate_i[6] =
        (Rotation_AHRS_GPS_B.Product3_jr * Rotation_AHRS_GPS_B.Product1_h1 -
         Rotation_AHRS_GPS_B.Product_ge * Rotation_AHRS_GPS_B.Product2_lr) *
        Rotation_AHRS_GPS_P_g.Gain_Gain_nz;
      Rotation_AHRS_GPS_B.VectorConcatenate_i[5] =
        (Rotation_AHRS_GPS_B.Product2_lr * Rotation_AHRS_GPS_B.Product1_h1 -
         Rotation_AHRS_GPS_B.Product_ge * Rotation_AHRS_GPS_B.Product3_jr) *
        Rotation_AHRS_GPS_P_g.Gain_Gain_f;
      Rotation_AHRS_GPS_B.VectorConcatenate_i[4] =
        ((Rotation_AHRS_GPS_B.Product_ge * Rotation_AHRS_GPS_B.Product_ge -
          Rotation_AHRS_GPS_B.Product3_jr * Rotation_AHRS_GPS_B.Product3_jr) +
         Rotation_AHRS_GPS_B.Product2_lr * Rotation_AHRS_GPS_B.Product2_lr) -
        Rotation_AHRS_GPS_B.Product1_h1 * Rotation_AHRS_GPS_B.Product1_h1;
      Rotation_AHRS_GPS_B.VectorConcatenate_i[3] =
        (Rotation_AHRS_GPS_B.Product1_h1 * Rotation_AHRS_GPS_B.Product_ge +
         Rotation_AHRS_GPS_B.Product3_jr * Rotation_AHRS_GPS_B.Product2_lr) *
        Rotation_AHRS_GPS_P_g.Gain_Gain_c;
      Rotation_AHRS_GPS_B.VectorConcatenate_i[2] =
        (Rotation_AHRS_GPS_B.Product_ge * Rotation_AHRS_GPS_B.Product2_lr +
         Rotation_AHRS_GPS_B.Product3_jr * Rotation_AHRS_GPS_B.Product1_h1) *
        Rotation_AHRS_GPS_P_g.Gain_Gain_fu;
      Rotation_AHRS_GPS_B.VectorConcatenate_i[1] =
        (Rotation_AHRS_GPS_B.Product3_jr * Rotation_AHRS_GPS_B.Product2_lr -
         Rotation_AHRS_GPS_B.Product1_h1 * Rotation_AHRS_GPS_B.Product_ge) *
        Rotation_AHRS_GPS_P_g.Gain_Gain_bo;
      Rotation_AHRS_GPS_B.VectorConcatenate_i[0] =
        ((Rotation_AHRS_GPS_B.Product_ge * Rotation_AHRS_GPS_B.Product_ge +
          Rotation_AHRS_GPS_B.Product3_jr * Rotation_AHRS_GPS_B.Product3_jr) -
         Rotation_AHRS_GPS_B.Product2_lr * Rotation_AHRS_GPS_B.Product2_lr) -
        Rotation_AHRS_GPS_B.Product1_h1 * Rotation_AHRS_GPS_B.Product1_h1;
      for (Rotation_AHRS_GPS_B.i = 0; Rotation_AHRS_GPS_B.i < 3;
           Rotation_AHRS_GPS_B.i++) {
        Rotation_AHRS_GPS_B.Switch[Rotation_AHRS_GPS_B.i + 4] =
          Rotation_AHRS_GPS_P_g.Constant1_Value_p[Rotation_AHRS_GPS_B.i];
        Rotation_AHRS_GPS_B.MatrixMultiply_m[Rotation_AHRS_GPS_B.i] =
          Rotation_AHRS_GPS_B.VectorConcatenate_i[3 * Rotation_AHRS_GPS_B.i + 2]
          * Rotation_AHRS_GPS_B.DiscreteFIRFilter1[2] +
          (Rotation_AHRS_GPS_B.VectorConcatenate_i[3 * Rotation_AHRS_GPS_B.i + 1]
           * Rotation_AHRS_GPS_B.DiscreteFIRFilter1[1] +
           Rotation_AHRS_GPS_B.VectorConcatenate_i[3 * Rotation_AHRS_GPS_B.i] *
           Rotation_AHRS_GPS_B.DiscreteFIRFilter1[0]);
      }

      Rotation_AHRS_GPS_B.Product_ge = Rotation_AHRS_GPS_rt_atan2f_snf
        (Rotation_AHRS_GPS_P_g.Gain_Gain_h *
         Rotation_AHRS_GPS_B.MatrixMultiply_m[1],
         Rotation_AHRS_GPS_B.MatrixMultiply_m[0]) *
        Rotation_AHRS_GPS_P_g.Gain_Gain_ct;
      Rotation_AHRS_GPS_B.rtb_Product_em_idx_3 = arm_sin_f32
        (Rotation_AHRS_GPS_B.Product_ge);
      Rotation_AHRS_GPS_B.rtb_Product_em_idx_0 = arm_cos_f32
        (Rotation_AHRS_GPS_B.Product_ge);
      Rotation_AHRS_GPS_B.rtb_DiscreteTimeIntegrator1_i_i =
        Rotation_AHRS_GPS_P_g.Constant_Value_b * Rotation_AHRS_GPS_B.Product2_n2;
      Rotation_AHRS_GPS_B.rtb_DiscreteTimeIntegrator1_i_f =
        Rotation_AHRS_GPS_P_g.Constant_Value_b *
        Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_gg;
      Rotation_AHRS_GPS_B.Switch[0] = ((Rotation_AHRS_GPS_B.rtb_Product_em_idx_0
        * Rotation_AHRS_GPS_B.Product3_k -
        Rotation_AHRS_GPS_B.rtb_DiscreteTimeIntegrator1_i_i) -
        Rotation_AHRS_GPS_B.rtb_DiscreteTimeIntegrator1_i_f) -
        Rotation_AHRS_GPS_B.rtb_Product_em_idx_3 *
        Rotation_AHRS_GPS_B.Product_dn;
      Rotation_AHRS_GPS_B.rtb_acc_GPS_est_idx_0 =
        Rotation_AHRS_GPS_P_g.Constant_Value_b * Rotation_AHRS_GPS_B.Product3_k;
      Rotation_AHRS_GPS_B.rtb_acc_GPS_est_idx_1 =
        Rotation_AHRS_GPS_P_g.Constant_Value_b * Rotation_AHRS_GPS_B.Product_dn;
      Rotation_AHRS_GPS_B.Switch[1] = ((Rotation_AHRS_GPS_B.rtb_Product_em_idx_0
        * Rotation_AHRS_GPS_B.Product2_n2 +
        Rotation_AHRS_GPS_B.rtb_acc_GPS_est_idx_0) +
        Rotation_AHRS_GPS_B.rtb_acc_GPS_est_idx_1) -
        Rotation_AHRS_GPS_B.rtb_Product_em_idx_3 *
        Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_gg;
      Rotation_AHRS_GPS_B.Product3_k *= Rotation_AHRS_GPS_B.rtb_Product_em_idx_3;
      Rotation_AHRS_GPS_B.Product_dn *= Rotation_AHRS_GPS_B.rtb_Product_em_idx_0;
      Rotation_AHRS_GPS_B.Switch[2] = ((Rotation_AHRS_GPS_B.rtb_Product_em_idx_0
        * Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_gg -
        Rotation_AHRS_GPS_B.rtb_acc_GPS_est_idx_1) +
        Rotation_AHRS_GPS_B.rtb_acc_GPS_est_idx_0) +
        Rotation_AHRS_GPS_B.rtb_Product_em_idx_3 *
        Rotation_AHRS_GPS_B.Product2_n2;
      Rotation_AHRS_GPS_B.Switch[3] = ((Rotation_AHRS_GPS_B.Product_dn +
        Rotation_AHRS_GPS_B.rtb_DiscreteTimeIntegrator1_i_f) -
        Rotation_AHRS_GPS_B.rtb_DiscreteTimeIntegrator1_i_i) +
        Rotation_AHRS_GPS_B.Product3_k;
    }
  }

  if (Rotation_AHRS_GPS_B.mag_reset2 || Rotation_AHRS_GPS_B.LogicalOperator3_f)
  {
    if (Rotation_AHRS_GPS_B.mag_reset2) {
      Rotation_AHRS_GPS_B.Switch_c[0] = Rotation_AHRS_GPS_B.Sum;
      Rotation_AHRS_GPS_B.Switch_c[1] = Rotation_AHRS_GPS_B.Sum_e;
      Rotation_AHRS_GPS_B.Switch_c[2] = Rotation_AHRS_GPS_B.Sum_h;
      Rotation_AHRS_GPS_B.Switch_c[3] = Rotation_AHRS_GPS_B.Sum_hp;
      Rotation_AHRS_GPS_B.Switch_c[4] = Rotation_AHRS_GPS_B.In1[4];
      Rotation_AHRS_GPS_B.Switch_c[5] = Rotation_AHRS_GPS_B.In1[5];
      Rotation_AHRS_GPS_B.Switch_c[6] = Rotation_AHRS_GPS_B.In1[6];
    } else {
      Rotation_AHRS_GPS_B.Switch_c[0] = Rotation_AHRS_GPS_B.Switch[0];
      Rotation_AHRS_GPS_B.Switch_c[1] = Rotation_AHRS_GPS_B.Switch[1];
      Rotation_AHRS_GPS_B.Switch_c[2] = Rotation_AHRS_GPS_B.Switch[2];
      Rotation_AHRS_GPS_B.Switch_c[3] = Rotation_AHRS_GPS_B.Switch[3];
      Rotation_AHRS_GPS_B.Switch_c[4] = Rotation_AHRS_GPS_B.Switch[4];
      Rotation_AHRS_GPS_B.Switch_c[5] = Rotation_AHRS_GPS_B.Switch[5];
      Rotation_AHRS_GPS_B.Switch_c[6] = Rotation_AHRS_GPS_B.Switch[6];
    }
  } else {
    for (Rotation_AHRS_GPS_B.i = 0; Rotation_AHRS_GPS_B.i < 7;
         Rotation_AHRS_GPS_B.i++) {
      Rotation_AHRS_GPS_B.Switch_c[Rotation_AHRS_GPS_B.i] =
        Rotation_AHRS_GPS_P_g.Constant_Value_c[Rotation_AHRS_GPS_B.i];
    }
  }

  mw_arm_sqrt_f32(((Rotation_AHRS_GPS_B.Switch_c[0] *
                    Rotation_AHRS_GPS_B.Switch_c[0] +
                    Rotation_AHRS_GPS_DW.Delay2_DSTATE[1] *
                    Rotation_AHRS_GPS_DW.Delay2_DSTATE[1]) +
                   Rotation_AHRS_GPS_DW.Delay2_DSTATE[2] *
                   Rotation_AHRS_GPS_DW.Delay2_DSTATE[2]) +
                  Rotation_AHRS_GPS_B.Switch_c[3] *
                  Rotation_AHRS_GPS_B.Switch_c[3],
                  &Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_gg);
  Rotation_AHRS_GPS_B.Product2_n2 = Rotation_AHRS_GPS_B.Switch_c[0] /
    Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_gg;
  Rotation_AHRS_GPS_B.atan1 = Rotation_AHRS_GPS_DW.Delay2_DSTATE[1] /
    Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_gg;
  Rotation_AHRS_GPS_B.Product_dn = Rotation_AHRS_GPS_DW.Delay2_DSTATE[2] /
    Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_gg;
  Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_gg = Rotation_AHRS_GPS_B.Switch_c[3]
    / Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_gg;
  if (Rotation_AHRS_GPS_B.mag_reset2) {
    Rotation_AHRS_GPS_DW.icLoad_b = 1U;
  }

  if (Rotation_AHRS_GPS_DW.icLoad_b != 0) {
    Rotation_AHRS_GPS_DW.Delay1_DSTATE[0] = Rotation_AHRS_GPS_B.Product2_n2;
    Rotation_AHRS_GPS_DW.Delay1_DSTATE[1] = Rotation_AHRS_GPS_B.atan1;
    Rotation_AHRS_GPS_DW.Delay1_DSTATE[2] = Rotation_AHRS_GPS_B.Product_dn;
    Rotation_AHRS_GPS_DW.Delay1_DSTATE[3] =
      Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_gg;
    Rotation_AHRS_GPS_DW.Delay1_DSTATE[4] =
      Rotation_AHRS_GPS_P_g.Constant1_Value_p[0];
    Rotation_AHRS_GPS_DW.Delay1_DSTATE[5] =
      Rotation_AHRS_GPS_P_g.Constant1_Value_p[1];
    Rotation_AHRS_GPS_DW.Delay1_DSTATE[6] =
      Rotation_AHRS_GPS_P_g.Constant1_Value_p[2];
  }

  if (Rotation_AHRS_GPS_B.LogicalOperator3_f) {
    Rotation_AHRS_GPS_DW.icLoad_m = 1U;
  }

  if (Rotation_AHRS_GPS_DW.icLoad_m != 0) {
    for (Rotation_AHRS_GPS_B.i = 0; Rotation_AHRS_GPS_B.i < 7;
         Rotation_AHRS_GPS_B.i++) {
      Rotation_AHRS_GPS_DW.Delay_DSTATE_n[Rotation_AHRS_GPS_B.i] =
        Rotation_AHRS_GPS_B.Switch_c[Rotation_AHRS_GPS_B.i];
    }
  }

  for (Rotation_AHRS_GPS_B.i = 0; Rotation_AHRS_GPS_B.i < 7;
       Rotation_AHRS_GPS_B.i++) {
    if (Rotation_AHRS_GPS_B.DataTypeConversion1_j) {
      Rotation_AHRS_GPS_B.Switch_c[Rotation_AHRS_GPS_B.i] =
        Rotation_AHRS_GPS_DW.Delay16_DSTATE[Rotation_AHRS_GPS_B.i];
    } else if (Rotation_AHRS_GPS_B.DataTypeConversion1_ba) {
      Rotation_AHRS_GPS_B.Switch_c[Rotation_AHRS_GPS_B.i] =
        Rotation_AHRS_GPS_DW.Delay12_DSTATE[Rotation_AHRS_GPS_B.i];
    } else if (Rotation_AHRS_GPS_B.mag_reset2) {
      Rotation_AHRS_GPS_B.Switch_c[Rotation_AHRS_GPS_B.i] =
        Rotation_AHRS_GPS_DW.Delay1_DSTATE[Rotation_AHRS_GPS_B.i];
    } else {
      Rotation_AHRS_GPS_B.Switch_c[Rotation_AHRS_GPS_B.i] =
        Rotation_AHRS_GPS_DW.Delay_DSTATE_n[Rotation_AHRS_GPS_B.i];
    }
  }

  rty_Rotation_data_Bias_gyro_rad[0] = Rotation_AHRS_GPS_B.Switch_c[4];
  rty_Rotation_data_Bias_gyro_rad[1] = Rotation_AHRS_GPS_B.Switch_c[5];
  rty_Rotation_data_Bias_gyro_rad[2] = Rotation_AHRS_GPS_B.Switch_c[6];
  Rotation_AHRS_GPS_B.LogicalOperator_h = (Rotation_AHRS_GPS_B.mag_reset2 ||
    ((int32_T)Rotation_AHRS_GPS_B.DataTypeConversion1_j > (int32_T)
     Rotation_AHRS_GPS_DW.DelayInput1_DSTATE_a) || ((int32_T)
    Rotation_AHRS_GPS_B.DataTypeConversion1_ba > (int32_T)
    Rotation_AHRS_GPS_DW.DelayInput1_DSTATE_d) || ((int32_T)
    Rotation_AHRS_GPS_B.LogicalOperator1_i > (int32_T)
    Rotation_AHRS_GPS_DW.DelayInput1_DSTATE_bg));
  if (Rotation_AHRS_GPS_B.LogicalOperator_h ||
      (Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_PrevRe_d != 0)) {
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_ab =
      Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_IC_lf;
  }

  *rty_reset_yaw_flag = ((int32_T)((uint32_T)
    (Rotation_AHRS_GPS_DW.Delay_DSTATE_n1 &&
     (!(Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_ab >=
        Rotation_AHRS_GPS_P_g.CompareTo11ms_const))) +
    Rotation_AHRS_GPS_B.LogicalOperator_h) != 0);
  *rty_Rotation_data_All_reset_Yaw = *rty_reset_yaw_flag;
  *rty_Rotation_data_Mag_Quality = *rtu_Sensor_data_Mag_Quality;
  rty_Rotation_data_sfor_R_B_mDs2[0] = rtu_Sensor_data_sfor_R_B_mDs2[0];
  rty_Rotation_data_sfor_R_B_mDs2[1] = rtu_Sensor_data_sfor_R_B_mDs2[1];
  rty_Rotation_data_sfor_R_B_mDs2[2] = rtu_Sensor_data_sfor_R_B_mDs2[2];
  Rotation_AHRS_GPS_B.atan1 = Rotation_AHRS_GPS_rt_atan2f_snf
    (Rotation_AHRS_GPS_P_g.Constant_Value_l[1],
     Rotation_AHRS_GPS_P_g.Constant_Value_l[0]);
  Rotation_AHRS_GPS_B.MathFunction2[0] = Rotation_AHRS_GPS_P_g.Constant6_Value;
  Rotation_AHRS_GPS_B.MathFunction2[1] = Rotation_AHRS_GPS_P_g.Constant7_Value;
  Rotation_AHRS_GPS_B.MathFunction2[2] = Rotation_AHRS_GPS_P_g.Constant7_Value;
  Rotation_AHRS_GPS_B.rtb_Product_em_idx_0 = Rotation_AHRS_GPS_P_g.Gain_Gain_fp *
    Rotation_AHRS_GPS_B.Switch_c[0];
  Rotation_AHRS_GPS_B.rtb_Product_em_idx_1 = Rotation_AHRS_GPS_P_g.Gain_Gain_fp *
    Rotation_AHRS_GPS_B.Switch_c[1];
  Rotation_AHRS_GPS_B.rtb_Product_em_idx_2 = Rotation_AHRS_GPS_P_g.Gain_Gain_fp *
    Rotation_AHRS_GPS_B.Switch_c[2];
  Rotation_AHRS_GPS_B.rtb_Product_em_idx_3 = Rotation_AHRS_GPS_P_g.Gain_Gain_fp *
    Rotation_AHRS_GPS_B.Switch_c[3];
  Rotation_AHRS_GPS_B.VectorConcatenate_k[0] = Rotation_AHRS_GPS_P_g.zero_Value;
  Rotation_AHRS_GPS_B.Gain1_i[0] = (Rotation_AHRS_GPS_DW.Delay1_DSTATE_o[0] +
    rtu_Sensor_data_rot_IB_B_raw_ra[0]) * Rotation_AHRS_GPS_P_g.Gain1_Gain_j;
  Rotation_AHRS_GPS_B.Gain1_i[1] = (Rotation_AHRS_GPS_DW.Delay1_DSTATE_o[1] +
    rtu_Sensor_data_rot_IB_B_raw_ra[1]) * Rotation_AHRS_GPS_P_g.Gain1_Gain_j;
  Rotation_AHRS_GPS_B.Gain1_i[2] = (Rotation_AHRS_GPS_DW.Delay1_DSTATE_o[2] +
    rtu_Sensor_data_rot_IB_B_raw_ra[2]) * Rotation_AHRS_GPS_P_g.Gain1_Gain_j;
  Rotation_AHRS_GP_MovingAverage2(Rotation_AHRS_GPS_B.Gain1_i[0],
    &Rotation_AHRS_GPS_B.MovingAverage3, &Rotation_AHRS_GPS_DW.MovingAverage3);
  Rotation_AHRS_GP_MovingAverage2(Rotation_AHRS_GPS_B.Gain1_i[1],
    &Rotation_AHRS_GPS_B.MovingAverage1, &Rotation_AHRS_GPS_DW.MovingAverage1);
  Rotation_AHRS_GP_MovingAverage2(Rotation_AHRS_GPS_B.Gain1_i[2],
    &Rotation_AHRS_GPS_B.MovingAverage2, &Rotation_AHRS_GPS_DW.MovingAverage2);
  mw_arm_sqrt_f32(((Rotation_AHRS_GPS_B.Switch_c[0] *
                    Rotation_AHRS_GPS_B.Switch_c[0] +
                    Rotation_AHRS_GPS_B.Switch_c[1] *
                    Rotation_AHRS_GPS_B.Switch_c[1]) +
                   Rotation_AHRS_GPS_B.Switch_c[2] *
                   Rotation_AHRS_GPS_B.Switch_c[2]) +
                  Rotation_AHRS_GPS_B.Switch_c[3] *
                  Rotation_AHRS_GPS_B.Switch_c[3],
                  &Rotation_AHRS_GPS_B.Product_dn);
  Rotation_AHRS_GPS_B.fcn5 = Rotation_AHRS_GPS_B.Switch_c[0] /
    Rotation_AHRS_GPS_B.Product_dn;
  Rotation_AHRS_GPS_B.Product2_n2 = Rotation_AHRS_GPS_B.Switch_c[1] /
    Rotation_AHRS_GPS_B.Product_dn;
  Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_gg = Rotation_AHRS_GPS_B.Switch_c[2]
    / Rotation_AHRS_GPS_B.Product_dn;
  Rotation_AHRS_GPS_B.Product_dn = Rotation_AHRS_GPS_B.Switch_c[3] /
    Rotation_AHRS_GPS_B.Product_dn;
  Rotation_AHRS_GPS_B.VectorConcatenate_p[0] = ((Rotation_AHRS_GPS_B.fcn5 *
    Rotation_AHRS_GPS_B.fcn5 + Rotation_AHRS_GPS_B.Product2_n2 *
    Rotation_AHRS_GPS_B.Product2_n2) -
    Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_gg *
    Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_gg) -
    Rotation_AHRS_GPS_B.Product_dn * Rotation_AHRS_GPS_B.Product_dn;
  Rotation_AHRS_GPS_B.VectorConcatenate_p[1] = (Rotation_AHRS_GPS_B.Product2_n2 *
    Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_gg -
    Rotation_AHRS_GPS_B.Product_dn * Rotation_AHRS_GPS_B.fcn5) *
    Rotation_AHRS_GPS_P_g.Gain_Gain_o;
  Rotation_AHRS_GPS_B.VectorConcatenate_p[2] = (Rotation_AHRS_GPS_B.fcn5 *
    Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_gg +
    Rotation_AHRS_GPS_B.Product2_n2 * Rotation_AHRS_GPS_B.Product_dn) *
    Rotation_AHRS_GPS_P_g.Gain_Gain_cw;
  Rotation_AHRS_GPS_B.VectorConcatenate_p[3] = (Rotation_AHRS_GPS_B.Product_dn *
    Rotation_AHRS_GPS_B.fcn5 + Rotation_AHRS_GPS_B.Product2_n2 *
    Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_gg) *
    Rotation_AHRS_GPS_P_g.Gain_Gain_a;
  Rotation_AHRS_GPS_B.VectorConcatenate_p[4] = ((Rotation_AHRS_GPS_B.fcn5 *
    Rotation_AHRS_GPS_B.fcn5 - Rotation_AHRS_GPS_B.Product2_n2 *
    Rotation_AHRS_GPS_B.Product2_n2) +
    Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_gg *
    Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_gg) -
    Rotation_AHRS_GPS_B.Product_dn * Rotation_AHRS_GPS_B.Product_dn;
  Rotation_AHRS_GPS_B.VectorConcatenate_p[5] =
    (Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_gg *
     Rotation_AHRS_GPS_B.Product_dn - Rotation_AHRS_GPS_B.fcn5 *
     Rotation_AHRS_GPS_B.Product2_n2) * Rotation_AHRS_GPS_P_g.Gain_Gain_gv;
  Rotation_AHRS_GPS_B.VectorConcatenate_p[6] = (Rotation_AHRS_GPS_B.Product2_n2 *
    Rotation_AHRS_GPS_B.Product_dn - Rotation_AHRS_GPS_B.fcn5 *
    Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_gg) *
    Rotation_AHRS_GPS_P_g.Gain_Gain_p5;
  Rotation_AHRS_GPS_B.VectorConcatenate_p[7] = (Rotation_AHRS_GPS_B.fcn5 *
    Rotation_AHRS_GPS_B.Product2_n2 +
    Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_gg *
    Rotation_AHRS_GPS_B.Product_dn) * Rotation_AHRS_GPS_P_g.Gain_Gain_nq;
  Rotation_AHRS_GPS_B.VectorConcatenate_p[8] = ((Rotation_AHRS_GPS_B.fcn5 *
    Rotation_AHRS_GPS_B.fcn5 - Rotation_AHRS_GPS_B.Product2_n2 *
    Rotation_AHRS_GPS_B.Product2_n2) -
    Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_gg *
    Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_gg) +
    Rotation_AHRS_GPS_B.Product_dn * Rotation_AHRS_GPS_B.Product_dn;
  for (Rotation_AHRS_GPS_B.i = 0; Rotation_AHRS_GPS_B.i < 3;
       Rotation_AHRS_GPS_B.i++) {
    Rotation_AHRS_GPS_B.VectorConcatenate_i[3 * Rotation_AHRS_GPS_B.i] =
      Rotation_AHRS_GPS_B.VectorConcatenate_p[Rotation_AHRS_GPS_B.i];
    Rotation_AHRS_GPS_B.VectorConcatenate_i[1 + 3 * Rotation_AHRS_GPS_B.i] =
      Rotation_AHRS_GPS_B.VectorConcatenate_p[Rotation_AHRS_GPS_B.i + 3];
    Rotation_AHRS_GPS_B.VectorConcatenate_i[2 + 3 * Rotation_AHRS_GPS_B.i] =
      Rotation_AHRS_GPS_B.VectorConcatenate_p[Rotation_AHRS_GPS_B.i + 6];
  }

  Rotation_AHRS_GPS_B.Compare_go = (*rtu_Sensor_data_GPS_data_Spd_qu >
    Rotation_AHRS_GPS_P_g.CompareToConstant_const_l);
  Rotation_AHRS_GPS_B.fcn5 = (real32_T)Rotation_AHRS_GPS_B.Compare_go *
    *rtu_Sensor_data_GPS_data_Spd_qu;
  Rotation_AHRS_GPS_B.need_to_compensate = ((*rtu_Sensor_data_Vision_data_typ ==
    Rotation_AHRS_GPS_P_g.CompareToConstant_const_o) ||
    (Rotation_AHRS_GPS_B.fcn5 > Rotation_AHRS_GPS_P_g.CompareToConstant1_const_m));
  for (Rotation_AHRS_GPS_B.i = 0; Rotation_AHRS_GPS_B.i < 3;
       Rotation_AHRS_GPS_B.i++) {
    Rotation_AHRS_GPS_B.DiscreteFIRFilter1[Rotation_AHRS_GPS_B.i] =
      Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_DSTAT_o[Rotation_AHRS_GPS_B.i];
    Rotation_AHRS_GPS_B.VectorConcatenate_p[3 * Rotation_AHRS_GPS_B.i] =
      Rotation_AHRS_GPS_B.VectorConcatenate_i[Rotation_AHRS_GPS_B.i];
    Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_gg =
      Rotation_AHRS_GPS_B.VectorConcatenate_i[Rotation_AHRS_GPS_B.i + 3];
    Rotation_AHRS_GPS_B.VectorConcatenate_p[1 + 3 * Rotation_AHRS_GPS_B.i] =
      Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_gg;
    Rotation_AHRS_GPS_B.rtb_DiscreteTimeIntegrator1_i_i =
      Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_gg *
      Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_DSTAT_o[1] +
      Rotation_AHRS_GPS_B.VectorConcatenate_i[Rotation_AHRS_GPS_B.i] *
      Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_DSTAT_o[0];
    Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_gg =
      Rotation_AHRS_GPS_B.VectorConcatenate_i[Rotation_AHRS_GPS_B.i + 6];
    Rotation_AHRS_GPS_B.VectorConcatenate_p[2 + 3 * Rotation_AHRS_GPS_B.i] =
      Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_gg;
    Rotation_AHRS_GPS_B.rtb_DiscreteTimeIntegrator1_i_i +=
      Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_gg *
      Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_DSTAT_o[2];
    if (Rotation_AHRS_GPS_B.need_to_compensate) {
      Rotation_AHRS_GPS_B.MatrixMultiply_m[Rotation_AHRS_GPS_B.i] =
        Rotation_AHRS_GPS_DW.Delay3_DSTATE[Rotation_AHRS_GPS_B.i];
    } else {
      Rotation_AHRS_GPS_B.MatrixMultiply_m[Rotation_AHRS_GPS_B.i] =
        Rotation_AHRS_GPS_B.rtb_DiscreteTimeIntegrator1_i_i;
    }

    Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_c[Rotation_AHRS_GPS_B.i] =
      Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE_k[Rotation_AHRS_GPS_B.i];
    Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_a[Rotation_AHRS_GPS_B.i] =
      Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE_n[Rotation_AHRS_GPS_B.i];
    Rotation_AHRS_GPS_B.DiscreteFIRFilter[Rotation_AHRS_GPS_B.i] =
      Rotation_AHRS_GPS_B.rtb_DiscreteTimeIntegrator1_i_i;
  }

  if (Rotation_AHRS_GPS_B.fcn5 > Rotation_AHRS_GPS_P_g.Switch1_Threshold) {
    Rotation_AHRS_GPS_B.need_to_compensate = !*rty_stand_still;
    if (Rotation_AHRS_GPS_B.Compare_go) {
      Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_gg =
        Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE_k[0];
    } else {
      Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_gg =
        Rotation_AHRS_GPS_P_g.Constant_Value_o[0];
    }

    Rotation_AHRS_GPS_B.rtb_acc_GPS_est_idx_0 =
      Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_gg * (real32_T)
      Rotation_AHRS_GPS_B.need_to_compensate;
    if (Rotation_AHRS_GPS_B.Compare_go) {
      Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_gg =
        Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE_k[1];
    } else {
      Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_gg =
        Rotation_AHRS_GPS_P_g.Constant_Value_o[1];
    }

    Rotation_AHRS_GPS_B.rtb_acc_GPS_est_idx_1 =
      Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_gg * (real32_T)
      Rotation_AHRS_GPS_B.need_to_compensate;
    if (Rotation_AHRS_GPS_B.Compare_go) {
      Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_gg =
        Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE_k[2];
    } else {
      Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_gg =
        Rotation_AHRS_GPS_P_g.Constant_Value_o[2];
    }

    Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_gg *= (real32_T)
      Rotation_AHRS_GPS_B.need_to_compensate;
  } else if (*rtu_Sensor_data_Vision_data_Vis >
             Rotation_AHRS_GPS_P_g.CompareToConstant_const_e) {
    Rotation_AHRS_GPS_B.rtb_acc_GPS_est_idx_0 =
      Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE_n[0];
    Rotation_AHRS_GPS_B.rtb_acc_GPS_est_idx_1 =
      Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE_n[1];
    Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_gg =
      Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE_n[2];
  } else {
    Rotation_AHRS_GPS_B.rtb_acc_GPS_est_idx_0 =
      Rotation_AHRS_GPS_P_g.Constant_Value[0];
    Rotation_AHRS_GPS_B.rtb_acc_GPS_est_idx_1 =
      Rotation_AHRS_GPS_P_g.Constant_Value[1];
    Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_gg =
      Rotation_AHRS_GPS_P_g.Constant_Value[2];
  }

  Rotation_AHRS_GPS_B.rtb_acc_GPS_est_idx_0 -= Rotation_AHRS_GPS_P_g.g0_Value[0];
  Rotation_AHRS_GPS_B.rtb_acc_GPS_est_idx_1 -= Rotation_AHRS_GPS_P_g.g0_Value[1];
  Rotation_AHRS_GPS_B.rtb_DiscreteTimeIntegrator1_i_i =
    Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_gg -
    Rotation_AHRS_GPS_P_g.g0_Value[2];
  mw_arm_sqrt_f32((Rotation_AHRS_GPS_B.MatrixMultiply_m[0] *
                   Rotation_AHRS_GPS_B.MatrixMultiply_m[0] +
                   Rotation_AHRS_GPS_B.MatrixMultiply_m[1] *
                   Rotation_AHRS_GPS_B.MatrixMultiply_m[1]) +
                  Rotation_AHRS_GPS_B.MatrixMultiply_m[2] *
                  Rotation_AHRS_GPS_B.MatrixMultiply_m[2],
                  &Rotation_AHRS_GPS_B.Product2_n2);
  mw_arm_sqrt_f32((Rotation_AHRS_GPS_B.rtb_acc_GPS_est_idx_0 *
                   Rotation_AHRS_GPS_B.rtb_acc_GPS_est_idx_0 +
                   Rotation_AHRS_GPS_B.rtb_acc_GPS_est_idx_1 *
                   Rotation_AHRS_GPS_B.rtb_acc_GPS_est_idx_1) +
                  Rotation_AHRS_GPS_B.rtb_DiscreteTimeIntegrator1_i_i *
                  Rotation_AHRS_GPS_B.rtb_DiscreteTimeIntegrator1_i_i,
                  &Rotation_AHRS_GPS_B.Product_dn);
  Rotation_AHRS_GPS_B.Product2_n2 *= Rotation_AHRS_GPS_B.Product_dn;
  if ((Rotation_AHRS_GPS_P_g.Constant1_Value_jo >
       Rotation_AHRS_GPS_B.Product2_n2) || rtIsNaNF
      (Rotation_AHRS_GPS_B.Product2_n2)) {
    Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_gg =
      Rotation_AHRS_GPS_P_g.Constant1_Value_jo;
  } else {
    Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_gg =
      Rotation_AHRS_GPS_B.Product2_n2;
  }

  Rotation_AHRS_GPS_B.rtb_Divide_idx_0 = (Rotation_AHRS_GPS_B.MatrixMultiply_m[1]
    * Rotation_AHRS_GPS_B.rtb_DiscreteTimeIntegrator1_i_i -
    Rotation_AHRS_GPS_B.MatrixMultiply_m[2] *
    Rotation_AHRS_GPS_B.rtb_acc_GPS_est_idx_1) /
    Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_gg;
  Rotation_AHRS_GPS_B.rtb_Divide_idx_1 = (Rotation_AHRS_GPS_B.MatrixMultiply_m[2]
    * Rotation_AHRS_GPS_B.rtb_acc_GPS_est_idx_0 -
    Rotation_AHRS_GPS_B.MatrixMultiply_m[0] *
    Rotation_AHRS_GPS_B.rtb_DiscreteTimeIntegrator1_i_i) /
    Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_gg;
  Rotation_AHRS_GPS_B.rtb_Divide_idx_2 = (Rotation_AHRS_GPS_B.MatrixMultiply_m[0]
    * Rotation_AHRS_GPS_B.rtb_acc_GPS_est_idx_1 -
    Rotation_AHRS_GPS_B.MatrixMultiply_m[1] *
    Rotation_AHRS_GPS_B.rtb_acc_GPS_est_idx_0) /
    Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_gg;
  if (Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_IC_LOA_c != 0) {
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE_c[0] =
      Rotation_AHRS_GPS_B.rtb_Divide_idx_0;
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE_c[1] =
      Rotation_AHRS_GPS_B.rtb_Divide_idx_1;
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE_c[2] =
      Rotation_AHRS_GPS_B.rtb_Divide_idx_2;
  }

  if (Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_IC_LO_by != 0) {
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE_l[0] =
      Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE_c[0];
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE_l[1] =
      Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE_c[1];
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE_l[2] =
      Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE_c[2];
  }

  Rotation_AHRS_GPS_B.omg_O[0] = (real32_T)fabs
    (Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE_l[0]);
  Rotation_AHRS_GPS_B.omg_O[1] = (real32_T)fabs
    (Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE_l[1]);
  Rotation_AHRS_GPS_B.omg_O[2] = (real32_T)fabs
    (Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE_l[2]);
  if ((Rotation_AHRS_GPS_B.omg_O[0] > Rotation_AHRS_GPS_B.omg_O[1]) || rtIsNaNF
      (Rotation_AHRS_GPS_B.omg_O[1])) {
    Rotation_AHRS_GPS_B.Product_hu = Rotation_AHRS_GPS_B.omg_O[0];
  } else {
    Rotation_AHRS_GPS_B.Product_hu = Rotation_AHRS_GPS_B.omg_O[1];
  }

  if ((!(Rotation_AHRS_GPS_B.Product_hu > Rotation_AHRS_GPS_B.omg_O[2])) &&
      (!rtIsNaNF(Rotation_AHRS_GPS_B.omg_O[2]))) {
    Rotation_AHRS_GPS_B.Product_hu = Rotation_AHRS_GPS_B.omg_O[2];
  }

  if (Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_IC_LO_n != 0) {
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_DSTAT_j = (real32_T)
      (Rotation_AHRS_GPS_B.Product_hu <
       Rotation_AHRS_GPS_P_g.CompareToConstant7_const);
  }

  Rotation_AHRS_GPS_B.LogicalOperator18 =
    (Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_DSTAT_j >
     Rotation_AHRS_GPS_P_g.CompareToConstant8_const);
  Rotation_AHRS_GPS_B.Compare_go = !Rotation_AHRS_GPS_B.LogicalOperator18;
  if (Rotation_AHRS_GPS_B.Compare_go ||
      (Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_PrevRe_k != 0)) {
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_if =
      Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_IC_e;
  }

  if (Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_if >=
      Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_UpperS_n) {
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_if =
      Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_UpperS_n;
  } else {
    if (Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_if <=
        Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_LowerS_k) {
      Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_if =
        Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_LowerS_k;
    }
  }

  *rty_rp_init_done = ((int32_T)((uint32_T)
    ((Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_if >
      Rotation_AHRS_GPS_P_g.Validaperiod_T_p_n) &&
     (Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_cq >
      Rotation_AHRS_GPS_P_g.CompareToConstant_const_n)) +
    Rotation_AHRS_GPS_DW.Delay_DSTATE_by) != 0);
  Rotation_AHRS_GPS_B.omg_O[0] = (real32_T)fabs
    (Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE_c[0]);
  Rotation_AHRS_GPS_B.omg_O[1] = (real32_T)fabs
    (Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE_c[1]);
  Rotation_AHRS_GPS_B.omg_O[2] = (real32_T)fabs
    (Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE_c[2]);
  if ((Rotation_AHRS_GPS_B.omg_O[0] > Rotation_AHRS_GPS_B.omg_O[1]) || rtIsNaNF
      (Rotation_AHRS_GPS_B.omg_O[1])) {
    Rotation_AHRS_GPS_B.DataTypeConversion_p = Rotation_AHRS_GPS_B.omg_O[0];
  } else {
    Rotation_AHRS_GPS_B.DataTypeConversion_p = Rotation_AHRS_GPS_B.omg_O[1];
  }

  if ((!(Rotation_AHRS_GPS_B.DataTypeConversion_p > Rotation_AHRS_GPS_B.omg_O[2]))
      && (!rtIsNaNF(Rotation_AHRS_GPS_B.omg_O[2]))) {
    Rotation_AHRS_GPS_B.DataTypeConversion_p = Rotation_AHRS_GPS_B.omg_O[2];
  }

  if (*rty_rp_init_done) {
    Rotation_AHRS_GPS_B.Product2_jx = Rotation_AHRS_GPS_P_g.Constant1_Value_a;
  } else {
    Rotation_AHRS_GPS_B.u0 = 1.0F / (Rotation_AHRS_GPS_P_g.Linearinterp1_x_r -
      Rotation_AHRS_GPS_P_g.Linearinterp1_x_l) *
      (Rotation_AHRS_GPS_B.DataTypeConversion_p -
       Rotation_AHRS_GPS_P_g.Linearinterp1_x_l);
    if (Rotation_AHRS_GPS_B.u0 > Rotation_AHRS_GPS_P_g.Saturation_UpperSat) {
      Rotation_AHRS_GPS_B.u0 = Rotation_AHRS_GPS_P_g.Saturation_UpperSat;
    } else {
      if (Rotation_AHRS_GPS_B.u0 < Rotation_AHRS_GPS_P_g.Saturation_LowerSat) {
        Rotation_AHRS_GPS_B.u0 = Rotation_AHRS_GPS_P_g.Saturation_LowerSat;
      }
    }

    Rotation_AHRS_GPS_B.Product2_jx = (Rotation_AHRS_GPS_P_g.Linearinterp1_y_r -
      Rotation_AHRS_GPS_P_g.Linearinterp1_y_l) * Rotation_AHRS_GPS_B.u0 +
      Rotation_AHRS_GPS_P_g.Linearinterp1_y_l;
  }

  Rotation_AHRS_GPS_B.Product2_jx *= Rotation_AHRS_GPS_P_g.One1_Value_i;
  Rotation_AHRS_GPS_B.Product2_eb = Rotation_AHRS_GPS_P_g.One2_Value *
    Rotation_AHRS_GPS_B.Product2_jx;
  for (Rotation_AHRS_GPS_B.i = 0; Rotation_AHRS_GPS_B.i < 3;
       Rotation_AHRS_GPS_B.i++) {
    Rotation_AHRS_GPS_B.Delay_h[Rotation_AHRS_GPS_B.i] =
      Rotation_AHRS_GPS_DW.Delay_DSTATE_i[Rotation_AHRS_GPS_B.i];
    Rotation_AHRS_GPS_B.rtb_MatrixMultiply2_p_tmp[Rotation_AHRS_GPS_B.i] =
      Rotation_AHRS_GPS_B.VectorConcatenate_i[Rotation_AHRS_GPS_B.i + 6] *
      Rotation_AHRS_GPS_DW.Delay_DSTATE_i[2] +
      (Rotation_AHRS_GPS_B.VectorConcatenate_i[Rotation_AHRS_GPS_B.i + 3] *
       Rotation_AHRS_GPS_DW.Delay_DSTATE_i[1] +
       Rotation_AHRS_GPS_B.VectorConcatenate_i[Rotation_AHRS_GPS_B.i] *
       Rotation_AHRS_GPS_DW.Delay_DSTATE_i[0]);
  }

  if (Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_IC_LOA_g != 0) {
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE_p =
      Rotation_AHRS_GPS_B.rtb_MatrixMultiply2_p_tmp[2];
  }

  Rotation_AHRS_GPS_B.Abs_o = (real32_T)fabs
    (Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE_p);
  if (Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_IC_LOA_k != 0) {
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_o1 =
      Rotation_AHRS_GPS_B.rtb_MatrixMultiply2_p_tmp[0];
  }

  if (Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_IC_LOA_i != 0) {
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_og =
      Rotation_AHRS_GPS_B.rtb_MatrixMultiply2_p_tmp[1];
  }

  Rotation_AHRS_GPS_B.Product3_k = (real32_T)fabs
    (Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_o1);
  if ((Rotation_AHRS_GPS_B.Abs_o > Rotation_AHRS_GPS_B.Product3_k) || rtIsNaNF
      (Rotation_AHRS_GPS_B.Product3_k)) {
    Rotation_AHRS_GPS_B.Product3_k = Rotation_AHRS_GPS_B.Abs_o;
  }

  Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_gg = (real32_T)fabs
    (Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_og);
  if ((Rotation_AHRS_GPS_B.Product3_k >
       Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_gg) || rtIsNaNF
      (Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_gg)) {
    Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_gg =
      Rotation_AHRS_GPS_B.Product3_k;
  }

  Rotation_AHRS_GPS_B.u0 = Rotation_AHRS_GPS_P_g.Gain3_Gain *
    Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_gg;
  if (Rotation_AHRS_GPS_B.u0 > Rotation_AHRS_GPS_P_g.Saturation_UpperSat_m) {
    Rotation_AHRS_GPS_B.u0 = Rotation_AHRS_GPS_P_g.Saturation_UpperSat_m;
  } else {
    if (Rotation_AHRS_GPS_B.u0 < Rotation_AHRS_GPS_P_g.Saturation_LowerSat_lu) {
      Rotation_AHRS_GPS_B.u0 = Rotation_AHRS_GPS_P_g.Saturation_LowerSat_lu;
    }
  }

  Rotation_AHRS_GPS_B.Divide1_i =
    Rotation_AHRS_GPS_P_g.AttitudeFusion_wn_acc_vert *
    Rotation_AHRS_GPS_P_g.One_Value * (1.0F / Rotation_AHRS_GPS_B.u0);
  if (*rtu_hover_flag) {
    Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_gg =
      Rotation_AHRS_GPS_P_g.Constant_Value_e;
  } else {
    Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_gg =
      Rotation_AHRS_GPS_P_g.Constant1_Value;
  }

  if (Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_IC_LO_gv != 0) {
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_ka =
      Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_gg;
  }

  if ((*rtu_stand_still_for_four_second) &&
      (Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_PrevRe_j <= 0)) {
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_it[0] =
      Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_IC_n;
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_it[1] =
      Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_IC_n;
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_it[2] =
      Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_IC_n;
  }

  if (Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_it[0] >=
      Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_UpperS_m) {
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_it[0] =
      Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_UpperS_m;
  } else {
    if (Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_it[0] <=
        Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_LowerS_m) {
      Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_it[0] =
        Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_LowerS_m;
    }
  }

  Rotation_AHRS_GPS_B.Gain10[0] = Rotation_AHRS_GPS_P_g.Gain10_Gain[0] *
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_it[0];
  if (Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_it[1] >=
      Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_UpperS_m) {
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_it[1] =
      Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_UpperS_m;
  } else {
    if (Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_it[1] <=
        Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_LowerS_m) {
      Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_it[1] =
        Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_LowerS_m;
    }
  }

  Rotation_AHRS_GPS_B.Gain10[1] = Rotation_AHRS_GPS_P_g.Gain10_Gain[1] *
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_it[1];
  if (Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_it[2] >=
      Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_UpperS_m) {
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_it[2] =
      Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_UpperS_m;
  } else {
    if (Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_it[2] <=
        Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_LowerS_m) {
      Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_it[2] =
        Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_LowerS_m;
    }
  }

  Rotation_AHRS_GPS_B.Gain10[2] = Rotation_AHRS_GPS_P_g.Gain10_Gain[2] *
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_it[2];
  Rotation_AHRS_GPS_B.Product_dn = Rotation_AHRS_GPS_P_g.Gain_Gain_fk *
    *rtu_Sensor_data_GPS_data_ant_he;
  if (Rotation_AHRS_GPS_B.Product_dn >
      Rotation_AHRS_GPS_P_g.CompareToConstant_const_p) {
    Rotation_AHRS_GPS_B.Product_dn -= Rotation_AHRS_GPS_P_g.Constant_Value_mj;
  }

  if (*rtu_Sensor_data_GPS_data_headin) {
    Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_mg =
      Rotation_AHRS_GPS_P_g.Constant1_Value_c;
  } else {
    Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_mg =
      Rotation_AHRS_GPS_P_g.Constant_Value_a;
  }

  Rotation_AHRS_GPS_B.need_to_compensate = ((*rtu_Sensor_data_GPS_data_Timest >
    Rotation_AHRS_GPS_DW.DelayInput1_DSTATE) &&
    (Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_mg >
     Rotation_AHRS_GPS_P_g.Constant_Value_ak));
  if (Rotation_AHRS_GPS_B.need_to_compensate) {
    Rotation_AHRS_GPS_B.Subtract_kk = Rotation_AHRS_GPS_B.Product_dn -
      Rotation_AHRS_GPS_DW.Delay_DSTATE_f[0];
    if (Rotation_AHRS_GPS_B.Subtract_kk >
        Rotation_AHRS_GPS_P_g.CompareToConstant_const) {
      Rotation_AHRS_GPS_B.Subtract_kk -= Rotation_AHRS_GPS_P_g.Constant_Value_m;
    }

    Rotation_AHRS_GPS_B.VectorConcatenate[0] =
      Rotation_AHRS_GPS_P_g.Constant2_Value_p;
    Rotation_AHRS_GPS_B.VectorConcatenate[1] =
      Rotation_AHRS_GPS_P_g.Constant3_Value_a;
    if (Rotation_AHRS_GPS_B.Subtract_kk <=
        Rotation_AHRS_GPS_P_g.CompareToConstant1_const) {
      Rotation_AHRS_GPS_B.Subtract_kk += Rotation_AHRS_GPS_P_g.Constant_Value_m;
    }

    Rotation_AHRS_GPS_B.VectorConcatenate[2] = (real32_T)tanh
      (Rotation_AHRS_GPS_P_g.Gain_Gain_n * Rotation_AHRS_GPS_B.Subtract_kk) *
      Rotation_AHRS_GPS_P_g.corr_gain_Gain;
  }

  Rotation_AHRS_GPS_B.Delay_p = Rotation_AHRS_GPS_DW.Delay_DSTATE_ez[0];
  Rotation_AHRS_GPS_B.rtb_DiscreteTimeIntegrator1_idx =
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_DSTAT_p[0];
  Rotation_AHRS_GPS_B.rtb_DiscreteTimeIntegrator1_i_g =
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_DSTAT_p[1];
  if (Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_IC_LO_c != 0) {
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_DSTAT_f[0] =
      Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_DSTAT_p[0];
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_DSTAT_f[1] =
      Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_DSTAT_p[1];
  }

  if (Rotation_AHRS_GPS_DW.Delay_DSTATE_ez[0U] &&
      (Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_PrevR_l <= 0)) {
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_DSTAT_f[0] =
      Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_DSTAT_p[0];
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_DSTAT_f[1] =
      Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_DSTAT_p[1];
  }

  Rotation_AHRS_GPS_B.rtb_DiscreteTimeIntegrator1_i_i =
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_DSTAT_f[0];
  Rotation_AHRS_GPS_B.rtb_DiscreteTimeIntegrator1_i_f =
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_DSTAT_f[1];
  mw_arm_sqrt_f32(Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_DSTAT_f[0] *
                  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_DSTAT_f[0] +
                  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_DSTAT_f[1] *
                  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_DSTAT_f[1],
                  &Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_if);
  if ((Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_if >
       Rotation_AHRS_GPS_P_g.Normalization_Min_Mag_d) || rtIsNaNF
      (Rotation_AHRS_GPS_P_g.Normalization_Min_Mag_d)) {
    Rotation_AHRS_GPS_B.Product_dn =
      Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_if;
  } else {
    Rotation_AHRS_GPS_B.Product_dn =
      Rotation_AHRS_GPS_P_g.Normalization_Min_Mag_d;
  }

  Rotation_AHRS_GPS_B.rtb_Sum_jx_idx_0 =
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_DSTAT_f[0] /
    Rotation_AHRS_GPS_B.Product_dn;
  Rotation_AHRS_GPS_B.rtb_Sum_jx_idx_1 =
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_DSTAT_f[1] /
    Rotation_AHRS_GPS_B.Product_dn;
  mw_arm_sqrt_f32(Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_DSTAT_p[0] *
                  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_DSTAT_p[0] +
                  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_DSTAT_p[1] *
                  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_DSTAT_p[1],
                  &Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_if);
  if ((Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_if >
       Rotation_AHRS_GPS_P_g.Normalization1_Min_Mag) || rtIsNaNF
      (Rotation_AHRS_GPS_P_g.Normalization1_Min_Mag)) {
    Rotation_AHRS_GPS_B.Product_dn =
      Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_if;
  } else {
    Rotation_AHRS_GPS_B.Product_dn =
      Rotation_AHRS_GPS_P_g.Normalization1_Min_Mag;
  }

  Rotation_AHRS_GPS_B.omg_O[0] =
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_DSTAT_p[0] /
    Rotation_AHRS_GPS_B.Product_dn;
  Rotation_AHRS_GPS_B.omg_O[1] =
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_DSTAT_p[1] /
    Rotation_AHRS_GPS_B.Product_dn;
  Rotation_AHRS_GPS_B.Product_e[0] = (Rotation_AHRS_GPS_B.rtb_Sum_jx_idx_1 *
    Rotation_AHRS_GPS_P_g.Constant_Value_by -
    Rotation_AHRS_GPS_P_g.Constant_Value_by * Rotation_AHRS_GPS_B.omg_O[1]) *
    Rotation_AHRS_GPS_P_g.Gain_Gain_e;
  Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_oa =
    Rotation_AHRS_GPS_B.rtb_Sum_jx_idx_0 + Rotation_AHRS_GPS_B.omg_O[0];
  Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_if =
    Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_oa *
    Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_oa;
  Rotation_AHRS_GPS_B.Product_e[1] = (Rotation_AHRS_GPS_P_g.Constant_Value_by *
    Rotation_AHRS_GPS_B.omg_O[0] - Rotation_AHRS_GPS_B.rtb_Sum_jx_idx_0 *
    Rotation_AHRS_GPS_P_g.Constant_Value_by) * Rotation_AHRS_GPS_P_g.Gain_Gain_e;
  Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_oa =
    Rotation_AHRS_GPS_B.rtb_Sum_jx_idx_1 + Rotation_AHRS_GPS_B.omg_O[1];
  Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_if +=
    Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_oa *
    Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_oa;
  Rotation_AHRS_GPS_B.Product_e[2] = (Rotation_AHRS_GPS_B.rtb_Sum_jx_idx_0 *
    Rotation_AHRS_GPS_B.omg_O[1] - Rotation_AHRS_GPS_B.rtb_Sum_jx_idx_1 *
    Rotation_AHRS_GPS_B.omg_O[0]) * Rotation_AHRS_GPS_P_g.Gain_Gain_e;
  Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_oa =
    Rotation_AHRS_GPS_P_g.Constant_Value_by +
    Rotation_AHRS_GPS_P_g.Constant_Value_by;
  Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_if +=
    Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_oa *
    Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_oa;
  if ((Rotation_AHRS_GPS_P_g.Constant_Value_j >
       Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_if) || rtIsNaNF
      (Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_if)) {
    Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_if =
      Rotation_AHRS_GPS_P_g.Constant_Value_j;
  }

  mw_arm_sqrt_f32(((Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_if *
                    Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_if +
                    Rotation_AHRS_GPS_B.Product_e[0] *
                    Rotation_AHRS_GPS_B.Product_e[0]) +
                   Rotation_AHRS_GPS_B.Product_e[1] *
                   Rotation_AHRS_GPS_B.Product_e[1]) +
                  Rotation_AHRS_GPS_B.Product_e[2] *
                  Rotation_AHRS_GPS_B.Product_e[2],
                  &Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_if);
  Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_if = Rotation_AHRS_GPS_B.Product_e
    [2] / Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_if;
  if (Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_if > 1.0F) {
    Rotation_AHRS_GPS_B.Product_dn = 1.0F;
  } else if (Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_if < -1.0F) {
    Rotation_AHRS_GPS_B.Product_dn = -1.0F;
  } else {
    Rotation_AHRS_GPS_B.Product_dn =
      Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_if;
  }

  Rotation_AHRS_GPS_B.Product_dn = Rotation_AHRS_GPS_P_g.Gain2_Gain * (real32_T)
    asin(Rotation_AHRS_GPS_B.Product_dn);
  if (Rotation_AHRS_GPS_B.Product_dn > Rotation_AHRS_GPS_P_g.DeadZone_End_d) {
    Rotation_AHRS_GPS_B.Product_dn -= Rotation_AHRS_GPS_P_g.DeadZone_End_d;
  } else if (Rotation_AHRS_GPS_B.Product_dn >=
             Rotation_AHRS_GPS_P_g.DeadZone_Start_c) {
    Rotation_AHRS_GPS_B.Product_dn = 0.0F;
  } else {
    Rotation_AHRS_GPS_B.Product_dn -= Rotation_AHRS_GPS_P_g.DeadZone_Start_c;
  }

  Rotation_AHRS_GPS_B.Product2_lr = (Rotation_AHRS_GPS_B.fcn5 -
    Rotation_AHRS_GPS_P_g.Constant_Value_o5) *
    Rotation_AHRS_GPS_P_g.Gain1_Gain_f;
  if (Rotation_AHRS_GPS_B.Product2_lr >
      Rotation_AHRS_GPS_P_g.Saturation_UpperSat_l5) {
    Rotation_AHRS_GPS_B.Product2_lr =
      Rotation_AHRS_GPS_P_g.Saturation_UpperSat_l5;
  } else {
    if (Rotation_AHRS_GPS_B.Product2_lr <
        Rotation_AHRS_GPS_P_g.Saturation_LowerSat_li) {
      Rotation_AHRS_GPS_B.Product2_lr =
        Rotation_AHRS_GPS_P_g.Saturation_LowerSat_li;
    }
  }

  mw_arm_sqrt_f32(Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_DSTAT_f[0] *
                  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_DSTAT_f[0] +
                  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_DSTAT_f[1] *
                  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_DSTAT_f[1],
                  &Rotation_AHRS_GPS_B.Product2_n2);
  mw_arm_sqrt_f32(Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_DSTAT_p[0] *
                  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_DSTAT_p[0] +
                  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_DSTAT_p[1] *
                  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_DSTAT_p[1],
                  &Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_io);
  if ((Rotation_AHRS_GPS_B.Product2_n2 <
       Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_io) || rtIsNaNF
      (Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_io)) {
    Rotation_AHRS_GPS_B.Product3_k = Rotation_AHRS_GPS_B.Product2_n2;
  } else {
    Rotation_AHRS_GPS_B.Product3_k =
      Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_io;
  }

  if (*rtu_orbit_flag) {
    if (Rotation_AHRS_GPS_B.Product3_k > Rotation_AHRS_GPS_P_g.DeadZone_End) {
      Rotation_AHRS_GPS_B.Product3_k -= Rotation_AHRS_GPS_P_g.DeadZone_End;
    } else if (Rotation_AHRS_GPS_B.Product3_k >=
               Rotation_AHRS_GPS_P_g.DeadZone_Start) {
      Rotation_AHRS_GPS_B.Product3_k = 0.0F;
    } else {
      Rotation_AHRS_GPS_B.Product3_k -= Rotation_AHRS_GPS_P_g.DeadZone_Start;
    }

    Rotation_AHRS_GPS_B.rtb_Sum_jx_idx_1 = Rotation_AHRS_GPS_P_g.Gain5_Gain *
      Rotation_AHRS_GPS_B.Product3_k;
  } else if (Rotation_AHRS_GPS_B.Product3_k >
             Rotation_AHRS_GPS_P_g.DeadZone1_End) {
    Rotation_AHRS_GPS_B.rtb_Sum_jx_idx_1 = Rotation_AHRS_GPS_B.Product3_k -
      Rotation_AHRS_GPS_P_g.DeadZone1_End;
  } else if (Rotation_AHRS_GPS_B.Product3_k >=
             Rotation_AHRS_GPS_P_g.DeadZone1_Start) {
    Rotation_AHRS_GPS_B.rtb_Sum_jx_idx_1 = 0.0F;
  } else {
    Rotation_AHRS_GPS_B.rtb_Sum_jx_idx_1 = Rotation_AHRS_GPS_B.Product3_k -
      Rotation_AHRS_GPS_P_g.DeadZone1_Start;
  }

  if (Rotation_AHRS_GPS_B.rtb_Sum_jx_idx_1 >
      Rotation_AHRS_GPS_P_g.Saturation1_UpperSat_b) {
    Rotation_AHRS_GPS_B.rtb_Sum_jx_idx_1 =
      Rotation_AHRS_GPS_P_g.Saturation1_UpperSat_b;
  } else {
    if (Rotation_AHRS_GPS_B.rtb_Sum_jx_idx_1 <
        Rotation_AHRS_GPS_P_g.Saturation1_LowerSat_l) {
      Rotation_AHRS_GPS_B.rtb_Sum_jx_idx_1 =
        Rotation_AHRS_GPS_P_g.Saturation1_LowerSat_l;
    }
  }

  if ((Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_io >
       Rotation_AHRS_GPS_B.Product2_n2) || rtIsNaNF
      (Rotation_AHRS_GPS_B.Product2_n2)) {
    Rotation_AHRS_GPS_B.Product3_k =
      Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_io;
  } else {
    Rotation_AHRS_GPS_B.Product3_k = Rotation_AHRS_GPS_B.Product2_n2;
  }

  Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_io -=
    Rotation_AHRS_GPS_B.Product2_n2;
  Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_io = (real32_T)fabs
    (Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_io);
  if ((Rotation_AHRS_GPS_P_g.Constant_Value_i > Rotation_AHRS_GPS_B.Product3_k) ||
      rtIsNaNF(Rotation_AHRS_GPS_B.Product3_k)) {
    Rotation_AHRS_GPS_B.Product3_k = Rotation_AHRS_GPS_P_g.Constant_Value_i;
  }

  Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_oa =
    Rotation_AHRS_GPS_P_g.Constant1_Value_o - 1.0F /
    Rotation_AHRS_GPS_B.Product3_k * (Rotation_AHRS_GPS_P_g.Gain_Gain_g3 *
    Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_io);
  if (Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_oa >
      Rotation_AHRS_GPS_P_g.Saturation_UpperSat_l3) {
    Rotation_AHRS_GPS_B.Saturation =
      Rotation_AHRS_GPS_P_g.Saturation_UpperSat_l3;
  } else if (Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_oa <
             Rotation_AHRS_GPS_P_g.Saturation_LowerSat_g) {
    Rotation_AHRS_GPS_B.Saturation = Rotation_AHRS_GPS_P_g.Saturation_LowerSat_g;
  } else {
    Rotation_AHRS_GPS_B.Saturation =
      Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_oa;
  }

  Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_oa = Rotation_AHRS_GPS_B.Saturation
    * Rotation_AHRS_GPS_P_g.DiscreteFIRFilter_Coefficient_n[0];
  Rotation_AHRS_GPS_B.i = 1;
  Rotation_AHRS_GPS_B.j = Rotation_AHRS_GPS_DW.DiscreteFIRFilter_circBuf_d;
  while (Rotation_AHRS_GPS_B.j < 29) {
    Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_oa +=
      Rotation_AHRS_GPS_DW.DiscreteFIRFilter_states_e[Rotation_AHRS_GPS_B.j] *
      Rotation_AHRS_GPS_P_g.DiscreteFIRFilter_Coefficient_n[Rotation_AHRS_GPS_B.i];
    Rotation_AHRS_GPS_B.i++;
    Rotation_AHRS_GPS_B.j++;
  }

  Rotation_AHRS_GPS_B.j = 0;
  while (Rotation_AHRS_GPS_B.j <
         Rotation_AHRS_GPS_DW.DiscreteFIRFilter_circBuf_d) {
    Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_oa +=
      Rotation_AHRS_GPS_DW.DiscreteFIRFilter_states_e[Rotation_AHRS_GPS_B.j] *
      Rotation_AHRS_GPS_P_g.DiscreteFIRFilter_Coefficient_n[Rotation_AHRS_GPS_B.i];
    Rotation_AHRS_GPS_B.i++;
    Rotation_AHRS_GPS_B.j++;
  }

  Rotation_AHRS_GPS_B.Product2_lr = Rotation_AHRS_GPS_B.Product2_lr *
    Rotation_AHRS_GPS_B.rtb_Sum_jx_idx_1 *
    Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_oa;
  if (Rotation_AHRS_GPS_B.Product2_lr >
      Rotation_AHRS_GPS_P_g.Saturation2_UpperSat) {
    Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_io =
      Rotation_AHRS_GPS_P_g.Saturation2_UpperSat;
  } else if (Rotation_AHRS_GPS_B.Product2_lr <
             Rotation_AHRS_GPS_P_g.Saturation2_LowerSat) {
    Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_io =
      Rotation_AHRS_GPS_P_g.Saturation2_LowerSat;
  } else {
    Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_io =
      Rotation_AHRS_GPS_B.Product2_lr;
  }

  Rotation_AHRS_GPS_B.Product_dn *=
    Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_io;
  if (Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_IC_LO_bw != 0) {
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_g4 =
      Rotation_AHRS_GPS_B.Product_dn;
  }

  mw_arm_sqrt_f32(Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_g4 *
                  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_g4,
                  &Rotation_AHRS_GPS_B.Product2_n2);
  if (Rotation_AHRS_GPS_B.Product2_n2 > Rotation_AHRS_GPS_P_g.Constant1_Value_l)
  {
    Rotation_AHRS_GPS_B.Product2_n2 =
      Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_g4 *
      Rotation_AHRS_GPS_P_g.Constant1_Value_l / Rotation_AHRS_GPS_B.Product2_n2;
  } else {
    Rotation_AHRS_GPS_B.Product2_n2 =
      Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_g4;
  }

  if (Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_IC_LOA_o != 0) {
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE_j =
      Rotation_AHRS_GPS_B.Product2_n2;
  }

  Rotation_AHRS_GPS_B.DiscreteTimeIntegrator1_m = (real32_T)fabs
    (Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE_j);
  Rotation_AHRS_GPS_B.u0 = 1.0F / (Rotation_AHRS_GPS_P_g.Linearinterp_x_r -
    Rotation_AHRS_GPS_P_g.Linearinterp_x_l) *
    (Rotation_AHRS_GPS_P_g.Gain_Gain_ia *
     Rotation_AHRS_GPS_B.DiscreteTimeIntegrator1_m -
     Rotation_AHRS_GPS_P_g.Linearinterp_x_l);
  if (*rtu_brake) {
    Rotation_AHRS_GPS_B.Product3_k = Rotation_AHRS_GPS_P_g.Constant_Value_oo;
  } else {
    Rotation_AHRS_GPS_B.Product3_k = Rotation_AHRS_GPS_P_g.Constant1_Value_j;
  }

  if (Rotation_AHRS_GPS_B.u0 > Rotation_AHRS_GPS_P_g.Saturation_UpperSat_i) {
    Rotation_AHRS_GPS_B.u0 = Rotation_AHRS_GPS_P_g.Saturation_UpperSat_i;
  } else {
    if (Rotation_AHRS_GPS_B.u0 < Rotation_AHRS_GPS_P_g.Saturation_LowerSat_d) {
      Rotation_AHRS_GPS_B.u0 = Rotation_AHRS_GPS_P_g.Saturation_LowerSat_d;
    }
  }

  Rotation_AHRS_GPS_B.u0 = ((Rotation_AHRS_GPS_P_g.Linearinterp_y_r -
    Rotation_AHRS_GPS_P_g.Linearinterp_y_l) * Rotation_AHRS_GPS_B.u0 +
    Rotation_AHRS_GPS_P_g.Linearinterp_y_l) *
    (Rotation_AHRS_GPS_P_g.AttitudeFusion_wn_acc_yaw *
     Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE_j *
     Rotation_AHRS_GPS_B.Product3_k);
  if (Rotation_AHRS_GPS_B.u0 > Rotation_AHRS_GPS_P_g.Saturation_UpperSat_b) {
    Rotation_AHRS_GPS_B.u0 = Rotation_AHRS_GPS_P_g.Saturation_UpperSat_b;
  } else {
    if (Rotation_AHRS_GPS_B.u0 < Rotation_AHRS_GPS_P_g.Saturation_LowerSat_n3) {
      Rotation_AHRS_GPS_B.u0 = Rotation_AHRS_GPS_P_g.Saturation_LowerSat_n3;
    }
  }

  Rotation_AHRS_GPS_B.Subtract_kk = Rotation_AHRS_GPS_P_g.Gain_Gain_mt *
    Rotation_AHRS_GPS_B.u0;
  Rotation_AHRS_GPS_B.Compare_nc =
    (Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_jn <=
     Rotation_AHRS_GPS_P_g.CompareToConstant_const_k);
  Rotation_AHRS_GPS_B.LogicalOperator1_c =
    !Rotation_AHRS_GPS_B.need_to_compensate;
  if (Rotation_AHRS_GPS_B.LogicalOperator1_c ||
      (Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_PrevRe_n != 0)) {
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTA_ifx =
      Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_IC_ly;
  }

  if (Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTA_ifx >=
      Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_UpperS_a) {
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTA_ifx =
      Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_UpperS_a;
  } else {
    if (Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTA_ifx <=
        Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_LowerS_b) {
      Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTA_ifx =
        Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_LowerS_b;
    }
  }

  Rotation_AHRS_GPS_B.Compare_bk =
    (Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTA_ifx >
     Rotation_AHRS_GPS_P_g.Validaperiod_T_p_j);
  Rotation_AHRS_GPS_B.Compare_huc = ((int32_T)Rotation_AHRS_GPS_B.Compare_bk >
    (int32_T)Rotation_AHRS_GPS_DW.DelayInput1_DSTATE_o);
  Rotation_AHRS_GPS_B.Delay4_e = Rotation_AHRS_GPS_DW.Delay4_DSTATE_j;
  Rotation_AHRS_GPS_B.Delay_m = Rotation_AHRS_GPS_DW.Delay_DSTATE_na;
  Rotation_AHRS_GPS_B.DataTypeConversion1_e = ((int32_T)((uint32_T)
    ((*rtu_hover_flag) && Rotation_AHRS_GPS_B.DataTypeConversion1_ba) +
    Rotation_AHRS_GPS_DW.Delay_DSTATE_kq) != 0);
  Rotation_AHRS_GPS_B.Compare_on = (((int32_T)((uint32_T)((*rtu_hover_flag) &&
    Rotation_AHRS_GPS_B.DataTypeConversion1_ba) +
    Rotation_AHRS_GPS_DW.Delay_DSTATE_kq) != 0) > (int32_T)
    Rotation_AHRS_GPS_DW.DelayInput1_DSTATE_nh);
  Rotation_AHRS_GPS_B.rtb_Sum_jx_idx_0 = (real32_T)fabs
    (*rtu_translation_data_h_dot_mDs);
  if (Rotation_AHRS_GPS_B.rtb_Sum_jx_idx_0 >= Rotation_AHRS_GPS_P_g.Relay_OnVal)
  {
    Rotation_AHRS_GPS_DW.Relay_Mode = true;
  } else {
    if (Rotation_AHRS_GPS_B.rtb_Sum_jx_idx_0 <=
        Rotation_AHRS_GPS_P_g.Relay_OffVal) {
      Rotation_AHRS_GPS_DW.Relay_Mode = false;
    }
  }

  if (Rotation_AHRS_GPS_DW.Relay_Mode) {
    Rotation_AHRS_GPS_B.relay = Rotation_AHRS_GPS_P_g.Relay_YOn;
  } else {
    Rotation_AHRS_GPS_B.relay = Rotation_AHRS_GPS_P_g.Relay_YOff;
  }

  Rotation_AHRS_GPS_B.LogicalOperator6_d = ((((int32_T)
    Rotation_AHRS_GPS_DW.Delay4_DSTATE_j > (int32_T)
    Rotation_AHRS_GPS_DW.DelayInput1_DSTATE_fa) && (*rtu_Armed)) || ((int32_T)
    *rty_stand_still > (int32_T)Rotation_AHRS_GPS_DW.DelayInput1_DSTATE_oe) ||
    (((int32_T)Rotation_AHRS_GPS_DW.Delay_DSTATE_na > (int32_T)
      Rotation_AHRS_GPS_DW.DelayInput1_DSTATE_pc) && (*rtu_hover_flag)) ||
    Rotation_AHRS_GPS_B.Compare_on || ((Rotation_AHRS_GPS_B.relay >
    Rotation_AHRS_GPS_DW.DelayInput1_DSTATE_f) &&
    Rotation_AHRS_GPS_DW.Delay4_DSTATE_j));
  for (Rotation_AHRS_GPS_B.i = 0; Rotation_AHRS_GPS_B.i < 3;
       Rotation_AHRS_GPS_B.i++) {
    Rotation_AHRS_GPS_B.Product_e[Rotation_AHRS_GPS_B.i] =
      Rotation_AHRS_GPS_B.VectorConcatenate_i[Rotation_AHRS_GPS_B.i + 6] *
      rtu_Sensor_data_h_R_B[2] +
      (Rotation_AHRS_GPS_B.VectorConcatenate_i[Rotation_AHRS_GPS_B.i + 3] *
       rtu_Sensor_data_h_R_B[1] +
       Rotation_AHRS_GPS_B.VectorConcatenate_i[Rotation_AHRS_GPS_B.i] *
       rtu_Sensor_data_h_R_B[0]);
  }

  Rotation_AHRS_GPS_B.Product3_k = Rotation_AHRS_GPS_rt_atan2f_snf
    (Rotation_AHRS_GPS_P_g.Gain_Gain_kr * Rotation_AHRS_GPS_B.Product_e[1],
     Rotation_AHRS_GPS_B.Product_e[0]);
  if (Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_IC_LO_b != 0) {
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_DSTAT_b =
      Rotation_AHRS_GPS_B.Product3_k;
  }

  if (Rotation_AHRS_GPS_B.DataTypeConversion1_ba &&
      (Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_PrevR_g <= 0)) {
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_DSTAT_b =
      Rotation_AHRS_GPS_B.Product3_k;
  }

  Rotation_AHRS_GPS_B.Product_ge =
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_DSTAT_b;
  if (Rotation_AHRS_GPS_B.Compare_on &&
      (Rotation_AHRS_GPS_PrevZCX.Delay3_Reset_ZCE != POS_ZCSIG)) {
    Rotation_AHRS_GPS_DW.icLoad_d = 1U;
  }

  Rotation_AHRS_GPS_PrevZCX.Delay3_Reset_ZCE = Rotation_AHRS_GPS_B.Compare_on;
  if (Rotation_AHRS_GPS_DW.icLoad_d != 0) {
    Rotation_AHRS_GPS_DW.Delay3_DSTATE_p =
      Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_DSTAT_b;
  }

  Rotation_AHRS_GPS_B.Product1_h1 =
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_DSTAT_b -
    Rotation_AHRS_GPS_DW.Delay3_DSTATE_p;
  if (Rotation_AHRS_GPS_B.LogicalOperator6_d &&
      (Rotation_AHRS_GPS_PrevZCX.Delay2_Reset_ZCE != POS_ZCSIG)) {
    Rotation_AHRS_GPS_DW.icLoad_f = 1U;
  }

  Rotation_AHRS_GPS_PrevZCX.Delay2_Reset_ZCE =
    Rotation_AHRS_GPS_B.LogicalOperator6_d;
  if (Rotation_AHRS_GPS_DW.icLoad_f != 0) {
    Rotation_AHRS_GPS_DW.Delay2_DSTATE_l = Rotation_AHRS_GPS_B.Product1_h1;
  }

  Rotation_AHRS_GPS_B.Compare_on =
    (Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_io >
     Rotation_AHRS_GPS_P_g.CompareToConstant9_const);
  if (Rotation_AHRS_GPS_B.Compare_on) {
    Rotation_AHRS_GPS_B.Product3_jr = Rotation_AHRS_GPS_DW.Delay2_DSTATE_l;
  } else {
    Rotation_AHRS_GPS_B.Product3_jr = 0.0F;
  }

  Rotation_AHRS_GPS_B.det_yaw_mag_c = Rotation_AHRS_GPS_B.Product1_h1 -
    Rotation_AHRS_GPS_B.Product3_jr;
  Rotation_AHRS_GPS_B.Sum_d2e = Rotation_AHRS_GPS_B.det_yaw_mag_c -
    Rotation_AHRS_GPS_DW.Delay_DSTATE_b;
  if (Rotation_AHRS_GPS_B.Compare_huc &&
      (Rotation_AHRS_GPS_PrevZCX.Delay1_Reset_ZCE != POS_ZCSIG)) {
    Rotation_AHRS_GPS_DW.icLoad_hh = 1U;
  }

  Rotation_AHRS_GPS_PrevZCX.Delay1_Reset_ZCE = Rotation_AHRS_GPS_B.Compare_huc;
  if (Rotation_AHRS_GPS_DW.icLoad_hh != 0) {
    Rotation_AHRS_GPS_DW.Delay1_DSTATE_i = Rotation_AHRS_GPS_B.Sum_d2e;
  }

  Rotation_AHRS_GPS_B.Product1_h1 = Rotation_AHRS_GPS_B.Sum_d2e -
    Rotation_AHRS_GPS_DW.Delay1_DSTATE_i;
  if (Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_IC_LOA_j != 0) {
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_m0 =
      Rotation_AHRS_GPS_B.Product1_h1;
  }

  if (Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_IC_LO_h != 0) {
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_DSTAT_d = (real32_T)((real32_T)
      fabs(Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_m0) <
      Rotation_AHRS_GPS_P_g.CompareToConstant1_const_o);
  }

  Rotation_AHRS_GPS_B.Compare_huc =
    (Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_DSTAT_d >
     Rotation_AHRS_GPS_P_g.CompareToConstant8_const_l);
  Rotation_AHRS_GPS_B.LogicalOperator6_d = !Rotation_AHRS_GPS_B.Compare_huc;
  if (Rotation_AHRS_GPS_B.LogicalOperator6_d ||
      (Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_PrevR_fh != 0)) {
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_on =
      Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_IC_c3;
  }

  if (Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_on >=
      Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_UpperS_f) {
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_on =
      Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_UpperS_f;
  } else {
    if (Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_on <=
        Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_LowerS_h) {
      Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_on =
        Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_LowerS_h;
    }
  }

  Rotation_AHRS_GPS_B.LogicalOperator_a =
    ((Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_on >
      Rotation_AHRS_GPS_P_g.Validaperiod_T_p_c) &&
     (Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_c0 >
      Rotation_AHRS_GPS_P_g.CompareToConstant_const_j3));
  Rotation_AHRS_GPS_B.LogicalOperator8_d = (((int32_T)((uint32_T)
    ((Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_on >
      Rotation_AHRS_GPS_P_g.Validaperiod_T_p_c) &&
     (Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_c0 >
      Rotation_AHRS_GPS_P_g.CompareToConstant_const_j3)) +
    Rotation_AHRS_GPS_DW.Delay_DSTATE_iz) != 0) || (*rty_once_stand_still));
  if (Rotation_AHRS_GPS_B.fcn5 > Rotation_AHRS_GPS_P_g.Switch_Threshold) {
    Rotation_AHRS_GPS_B.Product3_jr = Rotation_AHRS_GPS_P_g.One1_Value;
  } else {
    Rotation_AHRS_GPS_B.Product3_jr = Rotation_AHRS_GPS_P_g.One6_Value;
  }

  Rotation_AHRS_GPS_B.rtb_Product_e_c = Rotation_AHRS_GPS_B.VectorConcatenate_i
    [2] * Rotation_AHRS_GPS_B.Product1_h1;
  Rotation_AHRS_GPS_B.Sum_e_k = Rotation_AHRS_GPS_B.rtb_Product_e_c *
    Rotation_AHRS_GPS_B.rtb_Product_e_c;
  Rotation_AHRS_GPS_B.Product_e[0] = Rotation_AHRS_GPS_B.rtb_Product_e_c;
  Rotation_AHRS_GPS_B.rtb_Product_e_c = Rotation_AHRS_GPS_B.VectorConcatenate_i
    [5] * Rotation_AHRS_GPS_B.Product1_h1;
  Rotation_AHRS_GPS_B.Sum_e_k += Rotation_AHRS_GPS_B.rtb_Product_e_c *
    Rotation_AHRS_GPS_B.rtb_Product_e_c;
  Rotation_AHRS_GPS_B.Product_e[1] = Rotation_AHRS_GPS_B.rtb_Product_e_c;
  Rotation_AHRS_GPS_B.rtb_Product_e_c = Rotation_AHRS_GPS_B.VectorConcatenate_i
    [8] * Rotation_AHRS_GPS_B.Product1_h1;
  Rotation_AHRS_GPS_B.Sum_e_k += Rotation_AHRS_GPS_B.rtb_Product_e_c *
    Rotation_AHRS_GPS_B.rtb_Product_e_c;
  Rotation_AHRS_GPS_B.Product_e[2] = Rotation_AHRS_GPS_B.rtb_Product_e_c;
  mw_arm_sqrt_f32(Rotation_AHRS_GPS_B.Sum_e_k, &Rotation_AHRS_GPS_B.Sum_e_k);
  if (Rotation_AHRS_GPS_B.Sum_e_k > Rotation_AHRS_GPS_B.Product3_jr) {
    Rotation_AHRS_GPS_B.Product_e[0] = Rotation_AHRS_GPS_B.Product_e[0] *
      Rotation_AHRS_GPS_B.Product3_jr / Rotation_AHRS_GPS_B.Sum_e_k;
    Rotation_AHRS_GPS_B.Product_e[1] = Rotation_AHRS_GPS_B.Product_e[1] *
      Rotation_AHRS_GPS_B.Product3_jr / Rotation_AHRS_GPS_B.Sum_e_k;
    Rotation_AHRS_GPS_B.Product_e[2] = Rotation_AHRS_GPS_B.rtb_Product_e_c *
      Rotation_AHRS_GPS_B.Product3_jr / Rotation_AHRS_GPS_B.Sum_e_k;
  }

  if (Rotation_AHRS_GPS_B.DiscreteTimeIntegrator1_m >
      Rotation_AHRS_GPS_P_g.DeadZone_End_h) {
    Rotation_AHRS_GPS_B.Product3_jr =
      Rotation_AHRS_GPS_B.DiscreteTimeIntegrator1_m -
      Rotation_AHRS_GPS_P_g.DeadZone_End_h;
  } else if (Rotation_AHRS_GPS_B.DiscreteTimeIntegrator1_m >=
             Rotation_AHRS_GPS_P_g.DeadZone_Start_j) {
    Rotation_AHRS_GPS_B.Product3_jr = 0.0F;
  } else {
    Rotation_AHRS_GPS_B.Product3_jr =
      Rotation_AHRS_GPS_B.DiscreteTimeIntegrator1_m -
      Rotation_AHRS_GPS_P_g.DeadZone_Start_j;
  }

  Rotation_AHRS_GPS_B.Product3_jr = Rotation_AHRS_GPS_P_g.Constant1_Value_b -
    Rotation_AHRS_GPS_B.Product3_jr;
  if (Rotation_AHRS_GPS_B.Product3_jr >
      Rotation_AHRS_GPS_P_g.Saturation1_UpperSat_p) {
    Rotation_AHRS_GPS_B.Product3_jr =
      Rotation_AHRS_GPS_P_g.Saturation1_UpperSat_p;
  } else {
    if (Rotation_AHRS_GPS_B.Product3_jr <
        Rotation_AHRS_GPS_P_g.Saturation1_LowerSat_m) {
      Rotation_AHRS_GPS_B.Product3_jr =
        Rotation_AHRS_GPS_P_g.Saturation1_LowerSat_m;
    }
  }

  if (Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_IC_LO_jh != 0) {
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_na =
      Rotation_AHRS_GPS_B.Product3_jr;
  }

  *rty_Rotation_data_Heading_Quali =
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_na;
  if (Rotation_AHRS_GPS_B.Compare_on) {
    if (Rotation_AHRS_GPS_B.DataTypeConversion1_e) {
      Rotation_AHRS_GPS_B.Uk1 = (*rtu_Sensor_data_Mag_Quality >
        Rotation_AHRS_GPS_P_g.CompareToConstant5_const);
    } else {
      Rotation_AHRS_GPS_B.Uk1 = (*rtu_Sensor_data_Mag_Quality >
        Rotation_AHRS_GPS_P_g.CompareToConstant1_const_i);
    }

    Rotation_AHRS_GPS_B.LogicalOperator2_p = ((real32_T)fabs
      (Rotation_AHRS_GPS_B.Sum_d2e) <
      Rotation_AHRS_GPS_P_g.CompareToConstant6_const_c);
  } else {
    Rotation_AHRS_GPS_B.Uk1 = (*rtu_Sensor_data_Mag_Quality >
      Rotation_AHRS_GPS_P_g.CompareToConstant2_const_p);
    Rotation_AHRS_GPS_B.LogicalOperator2_p = ((real32_T)fabs
      (Rotation_AHRS_GPS_B.Sum_d2e) <
      Rotation_AHRS_GPS_P_g.CompareToConstant3_const_m);
  }

  Rotation_AHRS_GPS_B.Uk1 = ((((!*rtu_stand_still_for_four_second) && tmp) ||
    Rotation_AHRS_GPS_B.Uk1) && Rotation_AHRS_GPS_B.LogicalOperator2_p);
  Rotation_AHRS_GPS_B.DataTypeConversion = Rotation_AHRS_GPS_B.Uk1;
  if (Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_IC_L_nd != 0) {
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_DSTA_fu =
      Rotation_AHRS_GPS_B.Uk1;
  }

  if (Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_IC_LOA_m != 0) {
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_jy =
      Rotation_AHRS_GPS_B.det_yaw_mag_c;
  }

  Rotation_AHRS_GPS_B.Sum_e_k = (Rotation_AHRS_GPS_B.det_yaw_mag_c -
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_jy) *
    Rotation_AHRS_GPS_P_g.Gain_Gain_fg;
  if (Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_IC_LO_i4 != 0) {
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_g0 =
      Rotation_AHRS_GPS_B.Sum_e_k;
  }

  if (Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_IC_LO_m != 0) {
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_DSTA_ft = (real32_T)((real32_T)
      fabs(Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_g0) <
      Rotation_AHRS_GPS_P_g.CompareToConstant2_const_n);
  }

  Rotation_AHRS_GPS_B.LogicalOperator2_p =
    (Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_DSTA_ft >
     Rotation_AHRS_GPS_P_g.CompareToConstant3_const_g);
  if (Rotation_AHRS_GPS_B.Compare_on) {
    Rotation_AHRS_GPS_B.Uk1 =
      (Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_DSTA_fu >
       Rotation_AHRS_GPS_P_g.CompareToConstant4_const_c);
  } else {
    Rotation_AHRS_GPS_B.Uk1 = (((real32_T)fabs(Rotation_AHRS_GPS_B.Sum_d2e) <
      Rotation_AHRS_GPS_P_g.CompareToConstant5_const_f) &&
      Rotation_AHRS_GPS_B.LogicalOperator2_p);
  }

  if (Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_IC_LO_jz != 0) {
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE_e =
      Rotation_AHRS_GPS_B.Product1_h1;
  }

  Rotation_AHRS_GPS_B.Sum_d2e = (Rotation_AHRS_GPS_B.Product1_h1 -
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE_e) *
    Rotation_AHRS_GPS_P_g.Gain_Gain_l;
  if (Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_IC_LO_b4 != 0) {
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_ep =
      Rotation_AHRS_GPS_B.Sum_d2e;
  }

  if (Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_IC_LO_g != 0) {
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_DSTA_pn = (real32_T)((real32_T)
      fabs(Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_ep) <
      Rotation_AHRS_GPS_P_g.CompareToConstant7_const_m);
  }

  Rotation_AHRS_GPS_B.DiscreteTimeIntegrator1_e[0] =
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_DSTAT_i[0];
  Rotation_AHRS_GPS_B.DiscreteTimeIntegrator1_e[1] =
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_DSTAT_i[1];
  Rotation_AHRS_GPS_B.DiscreteTimeIntegrator1_e[2] =
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_DSTAT_i[2];
  Rotation_AHRS_GPS_B.DiscreteTimeIntegrator1_m =
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_DSTAT_l;
  if ((*rtu_Sensor_data_Sonar_data_sona) && (*rtu_Sensor_data_Sonar_data_h_gr <=
       Rotation_AHRS_GPS_P_g.CompareToConstant8_const_p4)) {
    Rotation_AHRS_GPS_B.Compare_c = ((real32_T)fabs
      (Rotation_AHRS_GPS_P_g.Gain_Gain_m *
       Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_DSTAT_i[2] -
       Rotation_AHRS_GPS_P_g.Gain_Gain *
       Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_DSTAT_l) <=
      Rotation_AHRS_GPS_P_g.CompareToConstant7_const_o);
  } else {
    Rotation_AHRS_GPS_B.Compare_c = Rotation_AHRS_GPS_P_g.Constant_Value_g;
  }

  Rotation_AHRS_GPS_B.Uk1 = ((Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_io <=
    Rotation_AHRS_GPS_P_g.CompareToConstant_const_g) && Rotation_AHRS_GPS_B.Uk1 &&
    (Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_DSTA_pn >
     Rotation_AHRS_GPS_P_g.CompareToConstant8_const_p) &&
    Rotation_AHRS_GPS_B.Compare_c);
  Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_io = Rotation_AHRS_GPS_B.Uk1 ?
    (real32_T)Rotation_AHRS_GPS_P_g.Gain6_Gain_n * 0.0078125F : 0.0F;
  Rotation_AHRS_GPS_B.Gain_n = *rty_Rotation_data_Heading_Quali *
    Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_io *
    Rotation_AHRS_GPS_P_g.AttitudeFusion_wn_mag;
  if (Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_IC_LO_k != 0) {
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_DSTA_cp =
      Rotation_AHRS_GPS_B.Gain_n;
  }

  if (Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_IC_LOA_n != 0) {
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE_d[0] =
      Rotation_AHRS_GPS_DW.Delay_DSTATE_i[0];
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE_d[1] =
      Rotation_AHRS_GPS_DW.Delay_DSTATE_i[1];
  }

  mw_arm_sqrt_f32(Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE_d[0] *
                  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE_d[0] +
                  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE_d[1] *
                  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE_d[1],
                  &Rotation_AHRS_GPS_B.DiscreteTimeIntegrator1_f);
  Rotation_AHRS_GPS_B.u0 = 1.0F / (Rotation_AHRS_GPS_P_g.Linearinterp2_x_r -
    Rotation_AHRS_GPS_P_g.Linearinterp2_x_l) * (Rotation_AHRS_GPS_P_g.Gain9_Gain
    * Rotation_AHRS_GPS_B.DiscreteTimeIntegrator1_f -
    Rotation_AHRS_GPS_P_g.Linearinterp2_x_l);
  if (Rotation_AHRS_GPS_B.u0 > Rotation_AHRS_GPS_P_g.Saturation_UpperSat_hv) {
    Rotation_AHRS_GPS_B.u0 = Rotation_AHRS_GPS_P_g.Saturation_UpperSat_hv;
  } else {
    if (Rotation_AHRS_GPS_B.u0 < Rotation_AHRS_GPS_P_g.Saturation_LowerSat_ic) {
      Rotation_AHRS_GPS_B.u0 = Rotation_AHRS_GPS_P_g.Saturation_LowerSat_ic;
    }
  }

  Rotation_AHRS_GPS_B.DiscreteTimeIntegrator1_f =
    (Rotation_AHRS_GPS_P_g.Linearinterp2_y_r -
     Rotation_AHRS_GPS_P_g.Linearinterp2_y_l) * Rotation_AHRS_GPS_B.u0 +
    Rotation_AHRS_GPS_P_g.Linearinterp2_y_l;
  if (Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_IC_L_bf != 0) {
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_DSTA_ii =
      Rotation_AHRS_GPS_B.DiscreteTimeIntegrator1_f;
  }

  Rotation_AHRS_GPS_B.u0 = 1.0F / (Rotation_AHRS_GPS_P_g.Linearinterp1_x_r_b -
    Rotation_AHRS_GPS_P_g.Linearinterp1_x_l_o) *
    (Rotation_AHRS_GPS_B.rtb_Sum_jx_idx_0 -
     Rotation_AHRS_GPS_P_g.Linearinterp1_x_l_o);
  if (Rotation_AHRS_GPS_B.u0 > Rotation_AHRS_GPS_P_g.Saturation_UpperSat_j) {
    Rotation_AHRS_GPS_B.u0 = Rotation_AHRS_GPS_P_g.Saturation_UpperSat_j;
  } else {
    if (Rotation_AHRS_GPS_B.u0 < Rotation_AHRS_GPS_P_g.Saturation_LowerSat_o) {
      Rotation_AHRS_GPS_B.u0 = Rotation_AHRS_GPS_P_g.Saturation_LowerSat_o;
    }
  }

  Rotation_AHRS_GPS_B.mag_gain2_l = ((Rotation_AHRS_GPS_P_g.Linearinterp1_y_r_l
    - Rotation_AHRS_GPS_P_g.Linearinterp1_y_l_c) * Rotation_AHRS_GPS_B.u0 +
    Rotation_AHRS_GPS_P_g.Linearinterp1_y_l_c) *
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_DSTA_cp *
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_DSTA_ii;
  Rotation_AHRS_GPS_B.Product_e[0] = Rotation_AHRS_GPS_P_g.Gain3_Gain_o *
    Rotation_AHRS_GPS_B.Product_e[0] * Rotation_AHRS_GPS_P_g.One5_Value[0] *
    Rotation_AHRS_GPS_B.mag_gain2_l;
  Rotation_AHRS_GPS_B.Product_e[1] = Rotation_AHRS_GPS_P_g.Gain3_Gain_o *
    Rotation_AHRS_GPS_B.Product_e[1] * Rotation_AHRS_GPS_P_g.One5_Value[1] *
    Rotation_AHRS_GPS_B.mag_gain2_l;
  Rotation_AHRS_GPS_B.rtb_Product_e_c = Rotation_AHRS_GPS_P_g.Gain3_Gain_o *
    Rotation_AHRS_GPS_B.Product_e[2] * Rotation_AHRS_GPS_P_g.One5_Value[2] *
    Rotation_AHRS_GPS_B.mag_gain2_l;
  Rotation_AHRS_GPS_B.mag_gain2_l = (real32_T)fabs
    (Rotation_AHRS_GPS_B.rtb_Product_e_c);
  if (Rotation_AHRS_GPS_B.LogicalOperator8_d) {
    if (Rotation_AHRS_GPS_B.Compare_nc) {
      Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_h =
        Rotation_AHRS_GPS_P_g.Constant1_Value_ax;
    } else {
      Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_h =
        Rotation_AHRS_GPS_P_g.Constant3_Value_l;
    }
  } else {
    Rotation_AHRS_GPS_B.u0 = 1.0F / (Rotation_AHRS_GPS_P_g.Linearinterp1_x_r_a -
      Rotation_AHRS_GPS_P_g.Linearinterp1_x_l_k) *
      (Rotation_AHRS_GPS_B.mag_gain2_l -
       Rotation_AHRS_GPS_P_g.Linearinterp1_x_l_k);
    if (Rotation_AHRS_GPS_B.u0 > Rotation_AHRS_GPS_P_g.Saturation_UpperSat_lu) {
      Rotation_AHRS_GPS_B.u0 = Rotation_AHRS_GPS_P_g.Saturation_UpperSat_lu;
    } else {
      if (Rotation_AHRS_GPS_B.u0 < Rotation_AHRS_GPS_P_g.Saturation_LowerSat_i)
      {
        Rotation_AHRS_GPS_B.u0 = Rotation_AHRS_GPS_P_g.Saturation_LowerSat_i;
      }
    }

    Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_h =
      (Rotation_AHRS_GPS_P_g.Linearinterp1_y_r_d -
       Rotation_AHRS_GPS_P_g.Linearinterp1_y_l_cr) * Rotation_AHRS_GPS_B.u0 +
      Rotation_AHRS_GPS_P_g.Linearinterp1_y_l_cr;
  }

  if ((*rtu_stand_still_for_four_second) &&
      (Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_PrevR_aq <= 0)) {
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_lk[0] =
      Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_IC_ny;
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_lk[1] =
      Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_IC_ny;
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_lk[2] =
      Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_IC_ny;
  }

  if (Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_lk[0] >=
      Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_UpperS_e) {
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_lk[0] =
      Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_UpperS_e;
  } else {
    if (Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_lk[0] <=
        Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_Lower_hp) {
      Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_lk[0] =
        Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_Lower_hp;
    }
  }

  Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_oa =
    Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_h *
    Rotation_AHRS_GPS_B.Product_e[0] +
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_lk[0];
  if (Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_oa >
      Rotation_AHRS_GPS_P_g.Saturation_UpperSat_bj) {
    Rotation_AHRS_GPS_B.y = Rotation_AHRS_GPS_P_g.Saturation_UpperSat_bj;
    Rotation_AHRS_GPS_B.CaliYawMAG[0] =
      Rotation_AHRS_GPS_P_g.Saturation_UpperSat_bj;
  } else if (Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_oa <
             Rotation_AHRS_GPS_P_g.Saturation_LowerSat_e1) {
    Rotation_AHRS_GPS_B.y = Rotation_AHRS_GPS_P_g.Saturation_LowerSat_e1;
    Rotation_AHRS_GPS_B.CaliYawMAG[0] =
      Rotation_AHRS_GPS_P_g.Saturation_LowerSat_e1;
  } else {
    Rotation_AHRS_GPS_B.y = Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_oa;
    Rotation_AHRS_GPS_B.CaliYawMAG[0] =
      Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_oa;
  }

  Rotation_AHRS_GPS_B.rtb_Sum_jx_idx_0 =
    Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_oa;
  if (Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_lk[1] >=
      Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_UpperS_e) {
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_lk[1] =
      Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_UpperS_e;
  } else {
    if (Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_lk[1] <=
        Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_Lower_hp) {
      Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_lk[1] =
        Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_Lower_hp;
    }
  }

  Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_oa =
    Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_h *
    Rotation_AHRS_GPS_B.Product_e[1] +
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_lk[1];
  if (Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_oa >
      Rotation_AHRS_GPS_P_g.Saturation_UpperSat_bj) {
    Rotation_AHRS_GPS_B.y_l = Rotation_AHRS_GPS_P_g.Saturation_UpperSat_bj;
    Rotation_AHRS_GPS_B.CaliYawMAG[1] =
      Rotation_AHRS_GPS_P_g.Saturation_UpperSat_bj;
  } else if (Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_oa <
             Rotation_AHRS_GPS_P_g.Saturation_LowerSat_e1) {
    Rotation_AHRS_GPS_B.y_l = Rotation_AHRS_GPS_P_g.Saturation_LowerSat_e1;
    Rotation_AHRS_GPS_B.CaliYawMAG[1] =
      Rotation_AHRS_GPS_P_g.Saturation_LowerSat_e1;
  } else {
    Rotation_AHRS_GPS_B.y_l = Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_oa;
    Rotation_AHRS_GPS_B.CaliYawMAG[1] =
      Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_oa;
  }

  Rotation_AHRS_GPS_B.rtb_Sum_jx_idx_1 =
    Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_oa;
  if (Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_lk[2] >=
      Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_UpperS_e) {
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_lk[2] =
      Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_UpperS_e;
  } else {
    if (Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_lk[2] <=
        Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_Lower_hp) {
      Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_lk[2] =
        Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_Lower_hp;
    }
  }

  Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_oa =
    Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_h *
    Rotation_AHRS_GPS_B.rtb_Product_e_c +
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_lk[2];
  if (Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_oa >
      Rotation_AHRS_GPS_P_g.Saturation_UpperSat_bj) {
    Rotation_AHRS_GPS_B.CaliYawMAG[2] =
      Rotation_AHRS_GPS_P_g.Saturation_UpperSat_bj;
  } else if (Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_oa <
             Rotation_AHRS_GPS_P_g.Saturation_LowerSat_e1) {
    Rotation_AHRS_GPS_B.CaliYawMAG[2] =
      Rotation_AHRS_GPS_P_g.Saturation_LowerSat_e1;
  } else {
    Rotation_AHRS_GPS_B.CaliYawMAG[2] =
      Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_oa;
  }

  Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_h =
    Rotation_AHRS_GPS_P_g.Constant4_Value_m -
    Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_mg;
  Rotation_AHRS_GPS_B.fv0[0] = Rotation_AHRS_GPS_B.MovingAverage3.MovingAverage2;
  Rotation_AHRS_GPS_B.fv0[1] = Rotation_AHRS_GPS_B.MovingAverage1.MovingAverage2;
  Rotation_AHRS_GPS_B.fv0[2] = Rotation_AHRS_GPS_B.MovingAverage2.MovingAverage2;
  for (Rotation_AHRS_GPS_B.i = 0; Rotation_AHRS_GPS_B.i < 3;
       Rotation_AHRS_GPS_B.i++) {
    Rotation_AHRS_GPS_B.u0 =
      ((Rotation_AHRS_GPS_P_g.Gain1_Gain_o[Rotation_AHRS_GPS_B.i] *
        (Rotation_AHRS_GPS_B.VectorConcatenate_p[Rotation_AHRS_GPS_B.i + 6] *
         Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE_c[2] +
         (Rotation_AHRS_GPS_B.VectorConcatenate_p[Rotation_AHRS_GPS_B.i + 3] *
          Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE_c[1] +
          Rotation_AHRS_GPS_B.VectorConcatenate_p[Rotation_AHRS_GPS_B.i] *
          Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE_c[0])) *
        Rotation_AHRS_GPS_B.Product2_eb * Rotation_AHRS_GPS_B.Divide1_i *
        Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_ka +
        Rotation_AHRS_GPS_B.Gain10[Rotation_AHRS_GPS_B.i]) +
       ((Rotation_AHRS_GPS_B.VectorConcatenate_i[3 * Rotation_AHRS_GPS_B.i + 2] *
         Rotation_AHRS_GPS_B.Subtract_kk +
         Rotation_AHRS_GPS_B.CaliYawMAG[Rotation_AHRS_GPS_B.i] *
         Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_h) +
        Rotation_AHRS_GPS_P_g.Gain_Gain_gw *
        Rotation_AHRS_GPS_B.VectorConcatenate[Rotation_AHRS_GPS_B.i] *
        Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_mg *
        Rotation_AHRS_GPS_P_g.Gain1_Gain_g[Rotation_AHRS_GPS_B.i])) +
      (Rotation_AHRS_GPS_B.fv0[Rotation_AHRS_GPS_B.i] -
       Rotation_AHRS_GPS_B.Switch_c[4 + Rotation_AHRS_GPS_B.i]);
    Rotation_AHRS_GPS_B.VectorConcatenate_k[Rotation_AHRS_GPS_B.i + 1] =
      Rotation_AHRS_GPS_B.u0;
    Rotation_AHRS_GPS_B.Subtract_m[Rotation_AHRS_GPS_B.i] =
      Rotation_AHRS_GPS_B.u0;
  }

  mw_arm_sqrt_f32(((Rotation_AHRS_GPS_B.Switch_c[0] *
                    Rotation_AHRS_GPS_B.Switch_c[0] +
                    Rotation_AHRS_GPS_B.Switch_c[1] *
                    Rotation_AHRS_GPS_B.Switch_c[1]) +
                   Rotation_AHRS_GPS_B.Switch_c[2] *
                   Rotation_AHRS_GPS_B.Switch_c[2]) +
                  Rotation_AHRS_GPS_B.Switch_c[3] *
                  Rotation_AHRS_GPS_B.Switch_c[3],
                  &Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_mg);
  Rotation_AHRS_GPS_B.Subtract_kk = Rotation_AHRS_GPS_P_g.one_Value -
    Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_mg *
    Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_mg;
  rty_Rotation_data_ATT_quat_OB[0] =
    ((((Rotation_AHRS_GPS_B.rtb_Product_em_idx_0 *
        Rotation_AHRS_GPS_B.VectorConcatenate_k[0] -
        Rotation_AHRS_GPS_B.rtb_Product_em_idx_1 *
        Rotation_AHRS_GPS_B.VectorConcatenate_k[1]) -
       Rotation_AHRS_GPS_B.rtb_Product_em_idx_2 *
       Rotation_AHRS_GPS_B.VectorConcatenate_k[2]) -
      Rotation_AHRS_GPS_B.rtb_Product_em_idx_3 *
      Rotation_AHRS_GPS_B.VectorConcatenate_k[3]) +
     Rotation_AHRS_GPS_B.Switch_c[0] * Rotation_AHRS_GPS_B.Subtract_kk *
     Rotation_AHRS_GPS_P_g.const_Value) *
    Rotation_AHRS_GPS_P_g.WeightedSampleTime_WtEt +
    Rotation_AHRS_GPS_B.Switch_c[0];
  rty_Rotation_data_ATT_quat_OB[1] =
    ((((Rotation_AHRS_GPS_B.rtb_Product_em_idx_0 *
        Rotation_AHRS_GPS_B.VectorConcatenate_k[1] +
        Rotation_AHRS_GPS_B.rtb_Product_em_idx_1 *
        Rotation_AHRS_GPS_B.VectorConcatenate_k[0]) +
       Rotation_AHRS_GPS_B.rtb_Product_em_idx_2 *
       Rotation_AHRS_GPS_B.VectorConcatenate_k[3]) -
      Rotation_AHRS_GPS_B.rtb_Product_em_idx_3 *
      Rotation_AHRS_GPS_B.VectorConcatenate_k[2]) +
     Rotation_AHRS_GPS_B.Switch_c[1] * Rotation_AHRS_GPS_B.Subtract_kk *
     Rotation_AHRS_GPS_P_g.const_Value) *
    Rotation_AHRS_GPS_P_g.WeightedSampleTime_WtEt +
    Rotation_AHRS_GPS_B.Switch_c[1];
  rty_Rotation_data_ATT_quat_OB[2] =
    ((((Rotation_AHRS_GPS_B.rtb_Product_em_idx_0 *
        Rotation_AHRS_GPS_B.VectorConcatenate_k[2] -
        Rotation_AHRS_GPS_B.rtb_Product_em_idx_1 *
        Rotation_AHRS_GPS_B.VectorConcatenate_k[3]) +
       Rotation_AHRS_GPS_B.rtb_Product_em_idx_2 *
       Rotation_AHRS_GPS_B.VectorConcatenate_k[0]) +
      Rotation_AHRS_GPS_B.rtb_Product_em_idx_3 *
      Rotation_AHRS_GPS_B.VectorConcatenate_k[1]) +
     Rotation_AHRS_GPS_B.Switch_c[2] * Rotation_AHRS_GPS_B.Subtract_kk *
     Rotation_AHRS_GPS_P_g.const_Value) *
    Rotation_AHRS_GPS_P_g.WeightedSampleTime_WtEt +
    Rotation_AHRS_GPS_B.Switch_c[2];
  rty_Rotation_data_ATT_quat_OB[3] =
    ((((Rotation_AHRS_GPS_B.rtb_Product_em_idx_0 *
        Rotation_AHRS_GPS_B.VectorConcatenate_k[3] +
        Rotation_AHRS_GPS_B.rtb_Product_em_idx_1 *
        Rotation_AHRS_GPS_B.VectorConcatenate_k[2]) -
       Rotation_AHRS_GPS_B.rtb_Product_em_idx_2 *
       Rotation_AHRS_GPS_B.VectorConcatenate_k[1]) +
      Rotation_AHRS_GPS_B.rtb_Product_em_idx_3 *
      Rotation_AHRS_GPS_B.VectorConcatenate_k[0]) +
     Rotation_AHRS_GPS_B.Switch_c[3] * Rotation_AHRS_GPS_B.Subtract_kk *
     Rotation_AHRS_GPS_P_g.const_Value) *
    Rotation_AHRS_GPS_P_g.WeightedSampleTime_WtEt +
    Rotation_AHRS_GPS_B.Switch_c[3];
  Rotation_AHRS_GPS_B.rtb_Product_em_idx_0 = rty_Rotation_data_ATT_quat_OB[0] *
    rty_Rotation_data_ATT_quat_OB[0];
  Rotation_AHRS_GPS_B.rtb_Product_em_idx_1 = rty_Rotation_data_ATT_quat_OB[1] *
    rty_Rotation_data_ATT_quat_OB[1];
  Rotation_AHRS_GPS_B.rtb_Product_em_idx_2 = rty_Rotation_data_ATT_quat_OB[2] *
    rty_Rotation_data_ATT_quat_OB[2];
  Rotation_AHRS_GPS_B.rtb_Product_em_idx_3 = rty_Rotation_data_ATT_quat_OB[3] *
    rty_Rotation_data_ATT_quat_OB[3];
  rty_Rotation_data_M_OB[0] = ((Rotation_AHRS_GPS_B.rtb_Product_em_idx_0 +
    Rotation_AHRS_GPS_B.rtb_Product_em_idx_1) -
    Rotation_AHRS_GPS_B.rtb_Product_em_idx_2) -
    Rotation_AHRS_GPS_B.rtb_Product_em_idx_3;
  rty_Rotation_data_M_OB[1] = (rty_Rotation_data_ATT_quat_OB[1] *
    rty_Rotation_data_ATT_quat_OB[2] + rty_Rotation_data_ATT_quat_OB[0] *
    rty_Rotation_data_ATT_quat_OB[3]) * Rotation_AHRS_GPS_P_g.Gain_Gain_bn;
  rty_Rotation_data_M_OB[2] = (rty_Rotation_data_ATT_quat_OB[1] *
    rty_Rotation_data_ATT_quat_OB[3] - rty_Rotation_data_ATT_quat_OB[0] *
    rty_Rotation_data_ATT_quat_OB[2]) * Rotation_AHRS_GPS_P_g.Gain1_Gain_gn;
  rty_Rotation_data_M_OB[3] = (rty_Rotation_data_ATT_quat_OB[1] *
    rty_Rotation_data_ATT_quat_OB[2] - rty_Rotation_data_ATT_quat_OB[0] *
    rty_Rotation_data_ATT_quat_OB[3]) * Rotation_AHRS_GPS_P_g.Gain2_Gain_e;
  rty_Rotation_data_M_OB[4] = ((Rotation_AHRS_GPS_B.rtb_Product_em_idx_0 -
    Rotation_AHRS_GPS_B.rtb_Product_em_idx_1) +
    Rotation_AHRS_GPS_B.rtb_Product_em_idx_2) -
    Rotation_AHRS_GPS_B.rtb_Product_em_idx_3;
  rty_Rotation_data_M_OB[5] = (rty_Rotation_data_ATT_quat_OB[2] *
    rty_Rotation_data_ATT_quat_OB[3] + rty_Rotation_data_ATT_quat_OB[0] *
    rty_Rotation_data_ATT_quat_OB[1]) * Rotation_AHRS_GPS_P_g.Gain3_Gain_k;
  rty_Rotation_data_M_OB[6] = (rty_Rotation_data_ATT_quat_OB[1] *
    rty_Rotation_data_ATT_quat_OB[3] + rty_Rotation_data_ATT_quat_OB[0] *
    rty_Rotation_data_ATT_quat_OB[2]) * Rotation_AHRS_GPS_P_g.Gain4_Gain;
  rty_Rotation_data_M_OB[7] = (rty_Rotation_data_ATT_quat_OB[2] *
    rty_Rotation_data_ATT_quat_OB[3] - rty_Rotation_data_ATT_quat_OB[0] *
    rty_Rotation_data_ATT_quat_OB[1]) * Rotation_AHRS_GPS_P_g.Gain5_Gain_c;
  rty_Rotation_data_M_OB[8] = ((Rotation_AHRS_GPS_B.rtb_Product_em_idx_0 -
    Rotation_AHRS_GPS_B.rtb_Product_em_idx_1) -
    Rotation_AHRS_GPS_B.rtb_Product_em_idx_2) +
    Rotation_AHRS_GPS_B.rtb_Product_em_idx_3;
  rty_Rotation_data_att_Oz_B[0] = rty_Rotation_data_M_OB[2];
  rty_Rotation_data_att_Oz_B[1] = rty_Rotation_data_M_OB[5];
  rty_Rotation_data_att_Oz_B[2] = rty_Rotation_data_M_OB[8];
  *rty_Rotation_data_Euler_Trans_k = Rotation_AHRS_GPS_rt_atan2f_snf
    (rty_Rotation_data_att_Oz_B[1], rty_Rotation_data_att_Oz_B[2]);
  *rty_Rotation_data_Euler_Trans_e = arm_sin_f32
    (*rty_Rotation_data_Euler_Trans_k);
  *rty_Rotation_data_Euler_Trans_c = arm_cos_f32
    (*rty_Rotation_data_Euler_Trans_k);
  Rotation_AHRS_GPS_B.MathFunction2[3] = Rotation_AHRS_GPS_P_g.Constant7_Value;
  Rotation_AHRS_GPS_B.MathFunction2[4] = *rty_Rotation_data_Euler_Trans_c;
  Rotation_AHRS_GPS_B.MathFunction2[5] = *rty_Rotation_data_Euler_Trans_e;
  Rotation_AHRS_GPS_B.MathFunction2[6] = Rotation_AHRS_GPS_P_g.Constant7_Value;
  Rotation_AHRS_GPS_B.MathFunction2[7] = Rotation_AHRS_GPS_P_g.Gain3_Gain_i *
    *rty_Rotation_data_Euler_Trans_e;
  Rotation_AHRS_GPS_B.MathFunction2[8] = *rty_Rotation_data_Euler_Trans_c;
  for (Rotation_AHRS_GPS_B.i = 0; Rotation_AHRS_GPS_B.i < 3;
       Rotation_AHRS_GPS_B.i++) {
    Rotation_AHRS_GPS_B.rtb_MathFunction2_m[3 * Rotation_AHRS_GPS_B.i] =
      Rotation_AHRS_GPS_B.MathFunction2[Rotation_AHRS_GPS_B.i];
    Rotation_AHRS_GPS_B.rtb_MathFunction2_m[1 + 3 * Rotation_AHRS_GPS_B.i] =
      Rotation_AHRS_GPS_B.MathFunction2[Rotation_AHRS_GPS_B.i + 3];
    Rotation_AHRS_GPS_B.rtb_MathFunction2_m[2 + 3 * Rotation_AHRS_GPS_B.i] =
      Rotation_AHRS_GPS_B.MathFunction2[Rotation_AHRS_GPS_B.i + 6];
  }

  for (Rotation_AHRS_GPS_B.i = 0; Rotation_AHRS_GPS_B.i < 9;
       Rotation_AHRS_GPS_B.i++) {
    Rotation_AHRS_GPS_B.MathFunction2[Rotation_AHRS_GPS_B.i] =
      Rotation_AHRS_GPS_B.rtb_MathFunction2_m[Rotation_AHRS_GPS_B.i];
  }

  *rty_Rotation_data_Euler_Trans_o = Rotation_AHRS_GPS_P_g.Gain5_Gain_b *
    rty_Rotation_data_att_Oz_B[0];
  if (*rty_Rotation_data_Euler_Trans_o >
      Rotation_AHRS_GPS_P_g.Saturation1_UpperSat_o) {
    Rotation_AHRS_GPS_B.rtb_Product_em_idx_3 =
      Rotation_AHRS_GPS_P_g.Saturation1_UpperSat_o;
  } else if (*rty_Rotation_data_Euler_Trans_o <
             Rotation_AHRS_GPS_P_g.Saturation1_LowerSat_h) {
    Rotation_AHRS_GPS_B.rtb_Product_em_idx_3 =
      Rotation_AHRS_GPS_P_g.Saturation1_LowerSat_h;
  } else {
    Rotation_AHRS_GPS_B.rtb_Product_em_idx_3 = *rty_Rotation_data_Euler_Trans_o;
  }

  if (Rotation_AHRS_GPS_B.rtb_Product_em_idx_3 > 1.0F) {
    Rotation_AHRS_GPS_B.rtb_Product_em_idx_3 = 1.0F;
  } else {
    if (Rotation_AHRS_GPS_B.rtb_Product_em_idx_3 < -1.0F) {
      Rotation_AHRS_GPS_B.rtb_Product_em_idx_3 = -1.0F;
    }
  }

  *rty_Rotation_data_Euler_Tran_ez = (real32_T)asin
    (Rotation_AHRS_GPS_B.rtb_Product_em_idx_3);
  *rty_Rotation_data_Euler_Trans_p = arm_cos_f32
    (*rty_Rotation_data_Euler_Tran_ez);
  Rotation_AHRS_GPS_B.MathFunction3[0] = *rty_Rotation_data_Euler_Trans_p;
  Rotation_AHRS_GPS_B.MathFunction3[1] =
    Rotation_AHRS_GPS_P_g.Constant1_Value_bu;
  Rotation_AHRS_GPS_B.MathFunction3[2] = Rotation_AHRS_GPS_P_g.Gain2_Gain_p *
    *rty_Rotation_data_Euler_Trans_o;
  Rotation_AHRS_GPS_B.MathFunction3[3] = Rotation_AHRS_GPS_P_g.Constant2_Value_n;
  Rotation_AHRS_GPS_B.MathFunction3[4] = Rotation_AHRS_GPS_P_g.Constant4_Value_d;
  Rotation_AHRS_GPS_B.MathFunction3[5] = Rotation_AHRS_GPS_P_g.Constant3_Value_i;
  Rotation_AHRS_GPS_B.MathFunction3[6] = *rty_Rotation_data_Euler_Trans_o;
  Rotation_AHRS_GPS_B.MathFunction3[7] = Rotation_AHRS_GPS_P_g.Constant5_Value;
  Rotation_AHRS_GPS_B.MathFunction3[8] = *rty_Rotation_data_Euler_Trans_p;
  for (Rotation_AHRS_GPS_B.i = 0; Rotation_AHRS_GPS_B.i < 3;
       Rotation_AHRS_GPS_B.i++) {
    Rotation_AHRS_GPS_B.rtb_MathFunction2_m[3 * Rotation_AHRS_GPS_B.i] =
      Rotation_AHRS_GPS_B.MathFunction3[Rotation_AHRS_GPS_B.i];
    Rotation_AHRS_GPS_B.rtb_MathFunction2_m[1 + 3 * Rotation_AHRS_GPS_B.i] =
      Rotation_AHRS_GPS_B.MathFunction3[Rotation_AHRS_GPS_B.i + 3];
    Rotation_AHRS_GPS_B.rtb_MathFunction2_m[2 + 3 * Rotation_AHRS_GPS_B.i] =
      Rotation_AHRS_GPS_B.MathFunction3[Rotation_AHRS_GPS_B.i + 6];
  }

  for (Rotation_AHRS_GPS_B.i = 0; Rotation_AHRS_GPS_B.i < 9;
       Rotation_AHRS_GPS_B.i++) {
    Rotation_AHRS_GPS_B.MathFunction3[Rotation_AHRS_GPS_B.i] =
      Rotation_AHRS_GPS_B.rtb_MathFunction2_m[Rotation_AHRS_GPS_B.i];
  }

  for (Rotation_AHRS_GPS_B.i = 0; Rotation_AHRS_GPS_B.i < 3;
       Rotation_AHRS_GPS_B.i++) {
    Rotation_AHRS_GPS_B.CaliYawMAG[Rotation_AHRS_GPS_B.i] = 0.0F;
    for (Rotation_AHRS_GPS_B.j = 0; Rotation_AHRS_GPS_B.j < 3;
         Rotation_AHRS_GPS_B.j++) {
      Rotation_AHRS_GPS_B.rtb_MathFunction2_tmp = Rotation_AHRS_GPS_B.i + 3 *
        Rotation_AHRS_GPS_B.j;
      Rotation_AHRS_GPS_B.rtb_MathFunction2_m[Rotation_AHRS_GPS_B.rtb_MathFunction2_tmp]
        = 0.0F;
      Rotation_AHRS_GPS_B.rtb_MathFunction2_tmp_d = 3 * Rotation_AHRS_GPS_B.j +
        Rotation_AHRS_GPS_B.i;
      Rotation_AHRS_GPS_B.rtb_MathFunction2_m[Rotation_AHRS_GPS_B.rtb_MathFunction2_tmp]
        =
        Rotation_AHRS_GPS_B.rtb_MathFunction2_m[Rotation_AHRS_GPS_B.rtb_MathFunction2_tmp_d]
        + Rotation_AHRS_GPS_B.MathFunction3[3 * Rotation_AHRS_GPS_B.i] *
        Rotation_AHRS_GPS_B.MathFunction2[Rotation_AHRS_GPS_B.j];
      Rotation_AHRS_GPS_B.rtb_MathFunction2_m[Rotation_AHRS_GPS_B.rtb_MathFunction2_tmp]
        = Rotation_AHRS_GPS_B.MathFunction3[3 * Rotation_AHRS_GPS_B.i + 1] *
        Rotation_AHRS_GPS_B.MathFunction2[Rotation_AHRS_GPS_B.j + 3] +
        Rotation_AHRS_GPS_B.rtb_MathFunction2_m[Rotation_AHRS_GPS_B.rtb_MathFunction2_tmp_d];
      Rotation_AHRS_GPS_B.rtb_MathFunction2_m[Rotation_AHRS_GPS_B.rtb_MathFunction2_tmp]
        = Rotation_AHRS_GPS_B.MathFunction3[3 * Rotation_AHRS_GPS_B.i + 2] *
        Rotation_AHRS_GPS_B.MathFunction2[Rotation_AHRS_GPS_B.j + 6] +
        Rotation_AHRS_GPS_B.rtb_MathFunction2_m[Rotation_AHRS_GPS_B.rtb_MathFunction2_tmp_d];
      Rotation_AHRS_GPS_B.CaliYawMAG[Rotation_AHRS_GPS_B.i] +=
        Rotation_AHRS_GPS_B.rtb_MathFunction2_m[Rotation_AHRS_GPS_B.rtb_MathFunction2_tmp_d]
        * rtu_Sensor_data_h_R_B[Rotation_AHRS_GPS_B.j];
    }
  }

  *rty_yaw_mag = (Rotation_AHRS_GPS_rt_atan2f_snf
                  (Rotation_AHRS_GPS_B.CaliYawMAG[1],
                   Rotation_AHRS_GPS_B.CaliYawMAG[0]) -
                  Rotation_AHRS_GPS_B.atan1) *
    Rotation_AHRS_GPS_P_g.Gain1_Gain_n * Rotation_AHRS_GPS_P_g.Gain1_Gain_a;
  Rotation_AHRS_GPS_B.rtb_VectorConcatenate1_idx_0 =
    *rtu_Sensor_data_GPS_data_vel_N -
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_DSTA_pc[0];
  Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_h = *rtu_Sensor_data_GPS_data_vel_E
    - Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_DSTA_pc[1];
  Rotation_AHRS_GPS_B.rtb_VectorConcatenate1_b = *rtu_Sensor_data_GPS_data_vel_D
    - Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_DSTA_pc[2];
  Rotation_AHRS_GPS_B.omg_O[0] = rtu_Sensor_data_Vision_data_vel[0] -
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_DSTAT_g[0];
  Rotation_AHRS_GPS_B.omg_O[1] = rtu_Sensor_data_Vision_data_vel[1] -
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_DSTAT_g[1];
  Rotation_AHRS_GPS_B.omg_O[2] = *rtu_Sensor_data_Vision_data_v_d -
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_DSTAT_g[2];
  Rotation_AHRS_GPS_B.atan1 = Rotation_AHRS_GPS_B.Product2_jx *
    Rotation_AHRS_GPS_B.Divide1_i * Rotation_AHRS_GPS_P_g.Gain6_Gain;
  if ((*rty_once_stand_still) || (*rty_rp_init_done)) {
    if (*rtu_hover_flag) {
      Rotation_AHRS_GPS_B.u0 = 1.0F / (Rotation_AHRS_GPS_P_g.Linearinterp2_x_r_e
        - Rotation_AHRS_GPS_P_g.Linearinterp2_x_l_c) *
        (Rotation_AHRS_GPS_B.Abs_o - Rotation_AHRS_GPS_P_g.Linearinterp2_x_l_c);
      if (Rotation_AHRS_GPS_B.u0 > Rotation_AHRS_GPS_P_g.Saturation_UpperSat_l)
      {
        Rotation_AHRS_GPS_B.u0 = Rotation_AHRS_GPS_P_g.Saturation_UpperSat_l;
      } else {
        if (Rotation_AHRS_GPS_B.u0 < Rotation_AHRS_GPS_P_g.Saturation_LowerSat_k)
        {
          Rotation_AHRS_GPS_B.u0 = Rotation_AHRS_GPS_P_g.Saturation_LowerSat_k;
        }
      }

      Rotation_AHRS_GPS_B.Subtract_kk =
        ((Rotation_AHRS_GPS_P_g.Linearinterp2_y_r_p -
          Rotation_AHRS_GPS_P_g.Linearinterp2_y_l_b) * Rotation_AHRS_GPS_B.u0 +
         Rotation_AHRS_GPS_P_g.Linearinterp2_y_l_b) *
        Rotation_AHRS_GPS_P_g.Constant2_Value;
    } else {
      Rotation_AHRS_GPS_B.Subtract_kk = Rotation_AHRS_GPS_P_g.Constant3_Value;
    }
  } else {
    Rotation_AHRS_GPS_B.u0 = 1.0F / (Rotation_AHRS_GPS_P_g.Linearinterp_x_r_e -
      Rotation_AHRS_GPS_P_g.Linearinterp_x_l_o) *
      (Rotation_AHRS_GPS_B.DataTypeConversion_p -
       Rotation_AHRS_GPS_P_g.Linearinterp_x_l_o);
    if (Rotation_AHRS_GPS_B.u0 > Rotation_AHRS_GPS_P_g.Saturation_UpperSat_d) {
      Rotation_AHRS_GPS_B.u0 = Rotation_AHRS_GPS_P_g.Saturation_UpperSat_d;
    } else {
      if (Rotation_AHRS_GPS_B.u0 < Rotation_AHRS_GPS_P_g.Saturation_LowerSat_l)
      {
        Rotation_AHRS_GPS_B.u0 = Rotation_AHRS_GPS_P_g.Saturation_LowerSat_l;
      }
    }

    Rotation_AHRS_GPS_B.Subtract_kk = (Rotation_AHRS_GPS_P_g.Linearinterp_y_r_a
      - Rotation_AHRS_GPS_P_g.Linearinterp_y_l_a) * Rotation_AHRS_GPS_B.u0 +
      Rotation_AHRS_GPS_P_g.Linearinterp_y_l_a;
  }

  Rotation_AHRS_GPS_B.rtb_Multiply1_idx_0 = Rotation_AHRS_GPS_P_g.Gain11_Gain *
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE_c[0] *
    Rotation_AHRS_GPS_B.Subtract_kk;
  Rotation_AHRS_GPS_B.rtb_Sum_b_idx_0 =
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE_c[0] -
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE_l[0];
  Rotation_AHRS_GPS_B.rtb_Multiply1_idx_1 = Rotation_AHRS_GPS_P_g.Gain11_Gain *
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE_c[1] *
    Rotation_AHRS_GPS_B.Subtract_kk;
  Rotation_AHRS_GPS_B.rtb_Sum_b_idx_1 =
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE_c[1] -
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE_l[1];
  Rotation_AHRS_GPS_B.rtb_Multiply1_idx_2 = Rotation_AHRS_GPS_P_g.Gain11_Gain *
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE_c[2] *
    Rotation_AHRS_GPS_B.Subtract_kk;
  Rotation_AHRS_GPS_B.rtb_Sum_b_idx_2 =
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE_c[2] -
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE_l[2];
  Rotation_AHRS_GPS_B.Subtract_kk = (real32_T)(Rotation_AHRS_GPS_B.Product_hu <
    Rotation_AHRS_GPS_P_g.CompareToConstant7_const) -
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_DSTAT_j;
  if (Rotation_AHRS_GPS_B.Subtract_kk > Rotation_AHRS_GPS_P_g.Switch_Threshold_l)
  {
    Rotation_AHRS_GPS_B.rtb_Product_em_idx_3 =
      Rotation_AHRS_GPS_P_g.Ascendanddescendtracking1_Tc_as;
  } else {
    Rotation_AHRS_GPS_B.rtb_Product_em_idx_3 =
      Rotation_AHRS_GPS_P_g.Ascendanddescendtracking1_Tc_de;
  }

  Rotation_AHRS_GPS_B.Product_hu = Rotation_AHRS_GPS_B.Subtract_kk /
    Rotation_AHRS_GPS_B.rtb_Product_em_idx_3;
  Rotation_AHRS_GPS_B.DataTypeConversion_p =
    Rotation_AHRS_GPS_B.LogicalOperator18;
  if (Rotation_AHRS_GPS_DW.Delay_DSTATE_ez[0U] &&
      (Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_PrevRe_h <= 0)) {
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_a1[0] =
      Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_IC_cq;
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_a1[1] =
      Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_IC_cq;
  }

  if (Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_if > 1.0F) {
    Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_if = 1.0F;
  } else {
    if (Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_if < -1.0F) {
      Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_if = -1.0F;
    }
  }

  Rotation_AHRS_GPS_B.Subtract_kk = Rotation_AHRS_GPS_P_g.Gain2_Gain_c *
    (real32_T)asin(Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_if);
  Rotation_AHRS_GPS_B.rtb_DiscreteTimeIntegrator_mg_t = (real32_T)fabs
    (Rotation_AHRS_GPS_B.Subtract_kk);
  if (Rotation_AHRS_GPS_B.Product2_lr >
      Rotation_AHRS_GPS_P_g.Saturation5_UpperSat) {
    Rotation_AHRS_GPS_B.Product2_lr = Rotation_AHRS_GPS_P_g.Saturation5_UpperSat;
  } else {
    if (Rotation_AHRS_GPS_B.Product2_lr <
        Rotation_AHRS_GPS_P_g.Saturation5_LowerSat) {
      Rotation_AHRS_GPS_B.Product2_lr =
        Rotation_AHRS_GPS_P_g.Saturation5_LowerSat;
    }
  }

  Rotation_AHRS_GPS_B.Abs_o = (real32_T)(Rotation_AHRS_GPS_B.Product2_lr >=
    Rotation_AHRS_GPS_P_g.CompareToConstant_const_f);
  Rotation_AHRS_GPS_B.Compare_c = (Rotation_AHRS_GPS_B.Product2_lr <
    Rotation_AHRS_GPS_P_g.CompareToConstant2_const_e);
  if (Rotation_AHRS_GPS_B.Compare_c ||
      (Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_PrevR_nh != 0)) {
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_aj =
      Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_IC_hx;
  }

  Rotation_AHRS_GPS_B.Compare_g4 =
    (Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_aj >=
     Rotation_AHRS_GPS_P_g.CompareToConstant1_const_b);
  Rotation_AHRS_GPS_B.Compare_c2 = (Rotation_AHRS_GPS_B.fcn5 >=
    Rotation_AHRS_GPS_P_g.CompareToConstant15_const);
  Rotation_AHRS_GPS_B.FixPtRelationalOperator_ke = ((int32_T)
    Rotation_AHRS_GPS_B.mag_reset2 > (int32_T)
    Rotation_AHRS_GPS_DW.DelayInput1_DSTATE_ip);
  if (Rotation_AHRS_GPS_B.FixPtRelationalOperator_ke ||
      (Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_PrevRe_e != 0)) {
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE_h =
      Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_IC_e4;
  }

  Rotation_AHRS_GPS_B.LogicalOperator18 = ((int32_T)((uint32_T)
    (Rotation_AHRS_GPS_DW.Delay_DSTATE_d &&
     (!(Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE_h >=
        Rotation_AHRS_GPS_P_g.CompareTo1sec_const_o))) +
    Rotation_AHRS_GPS_B.FixPtRelationalOperator_ke) == 0);
  Rotation_AHRS_GPS_B.LogicalOperator1_hy = !Rotation_AHRS_GPS_B.Compare_c2;
  if (Rotation_AHRS_GPS_B.LogicalOperator1_hy ||
      (Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_PrevR_dh != 0)) {
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTA_lk2 =
      Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_IC_lx;
  }

  if (Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTA_lk2 >=
      Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_Upper_a0) {
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTA_lk2 =
      Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_Upper_a0;
  } else {
    if (Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTA_lk2 <=
        Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_LowerS_c) {
      Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTA_lk2 =
        Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_LowerS_c;
    }
  }

  rtb_LogicalOperator12_h = !(Rotation_AHRS_GPS_B.fcn5 <=
    Rotation_AHRS_GPS_P_g.CompareToConstant16_const);
  rtb_DataTypeConversion1_h = ((int32_T)((uint32_T)
    ((Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTA_lk2 >
      Rotation_AHRS_GPS_P_g.Validaperiod_T_p_a) && rtb_LogicalOperator12_h) +
    (Rotation_AHRS_GPS_DW.Delay_DSTATE_e1 && rtb_LogicalOperator12_h)) != 0);
  rtb_Uk1_b = ((Rotation_AHRS_GPS_B.rtb_DiscreteTimeIntegrator_mg_t >=
                Rotation_AHRS_GPS_P_g.CompareToConstant20_const) &&
               (Rotation_AHRS_GPS_B.Product2_lr >=
                Rotation_AHRS_GPS_P_g.CompareToConstant17_const));
  rtb_LogicalOperator1_d = !rtb_Uk1_b;
  if (rtb_LogicalOperator1_d ||
      (Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_PrevR_du != 0)) {
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_m4 =
      Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_IC_o;
  }

  if (Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_m4 >=
      Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_UpperS_h) {
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_m4 =
      Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_UpperS_h;
  } else {
    if (Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_m4 <=
        Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_Lower_mq) {
      Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_m4 =
        Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_Lower_mq;
    }
  }

  rtb_DataTypeConversion1_n5 = ((int32_T)((uint32_T)((int32_T)
    Rotation_AHRS_GPS_B.enable > (int32_T)
    Rotation_AHRS_GPS_DW.DelayInput1_DSTATE_m) +
    Rotation_AHRS_GPS_DW.Delay_DSTATE_ig) != 0);
  rtb_FixPtRelationalOperator_pi = (((int32_T)((uint32_T)((int32_T)
    Rotation_AHRS_GPS_B.enable > (int32_T)
    Rotation_AHRS_GPS_DW.DelayInput1_DSTATE_m) +
    Rotation_AHRS_GPS_DW.Delay_DSTATE_ig) != 0) > (int32_T)
    Rotation_AHRS_GPS_DW.DelayInput1_DSTATE_aq);
  if (rtb_FixPtRelationalOperator_pi ||
      (Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_PrevRe_c != 0)) {
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_gr =
      Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_IC_ob;
  }

  rtb_LogicalOperator12_h = ((int32_T)((uint32_T)
    (Rotation_AHRS_GPS_DW.Delay_DSTATE_o &&
     (!(Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_gr >=
        Rotation_AHRS_GPS_P_g.CompareTo1sec_const_p))) +
    rtb_FixPtRelationalOperator_pi) == 0);
  rtb_large_error_detected = (Rotation_AHRS_GPS_B.LogicalOperator18 &&
    rtb_DataTypeConversion1_h &&
    (Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_m4 >
     Rotation_AHRS_GPS_P_g.Validaperiod1_T_p) && rtb_LogicalOperator12_h &&
    (*rtu_Armed));
  rtb_FixPtRelationalOperator_jv = ((int32_T)
    Rotation_AHRS_GPS_B.DataTypeConversion1_ba > (int32_T)
    Rotation_AHRS_GPS_DW.DelayInput1_DSTATE_c);
  rtb_FixPtRelationalOperator_es = ((int32_T)
    Rotation_AHRS_GPS_B.DataTypeConversion1_j > (int32_T)
    Rotation_AHRS_GPS_DW.DelayInput1_DSTATE_ne);
  Rotation_AHRS_GPS_DW.Delay_DSTATE_m = (rtb_DataTypeConversion1_h &&
    Rotation_AHRS_GPS_B.LogicalOperator18 && ((int32_T)
    Rotation_AHRS_GPS_B.Compare_g4 > (int32_T)
    Rotation_AHRS_GPS_DW.DelayInput1_DSTATE_j) && (*rtu_Armed) &&
    (rtb_mag_reset2_tmp ||
     (!(Rotation_AHRS_GPS_B.rtb_DiscreteTimeIntegrator_mg_t <=
        Rotation_AHRS_GPS_P_g.CompareToConstant9_const_c))) &&
    rtb_LogicalOperator12_h);
  if (rtb_FixPtRelationalOperator_jv ||
      (Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_PrevR_je != 0)) {
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_bu =
      Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_IC_hn;
  }

  if (rtb_FixPtRelationalOperator_es ||
      (Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_PrevRe_m != 0)) {
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_cf =
      Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_IC_j0;
  }

  Rotation_AHRS_GPS_B.fcn5 = rtb_Uk1_b;
  for (Rotation_AHRS_GPS_B.i = 0; Rotation_AHRS_GPS_B.i < 3;
       Rotation_AHRS_GPS_B.i++) {
    Rotation_AHRS_GPS_B.CaliYawMAG[Rotation_AHRS_GPS_B.i] =
      Rotation_AHRS_GPS_B.VectorConcatenate_i[Rotation_AHRS_GPS_B.i + 6] *
      Rotation_AHRS_GPS_DW.Delay_DSTATE_i[2] +
      (Rotation_AHRS_GPS_B.VectorConcatenate_i[Rotation_AHRS_GPS_B.i + 3] *
       Rotation_AHRS_GPS_DW.Delay_DSTATE_i[1] +
       Rotation_AHRS_GPS_B.VectorConcatenate_i[Rotation_AHRS_GPS_B.i] *
       Rotation_AHRS_GPS_DW.Delay_DSTATE_i[0]);
  }

  if (Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_IC_LO_gi != 0) {
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_ez =
      Rotation_AHRS_GPS_B.CaliYawMAG[2];
  }

  if (Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_IC_LO_hx != 0) {
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_di =
      Rotation_AHRS_GPS_B.CaliYawMAG[2];
  }

  Rotation_AHRS_GPS_B.Divide1_i = Rotation_AHRS_GPS_B.Gain_n -
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_DSTA_cp;
  if (Rotation_AHRS_GPS_B.Divide1_i > Rotation_AHRS_GPS_P_g.Switch_Threshold_a)
  {
    Rotation_AHRS_GPS_B.rtb_Product_em_idx_3 =
      Rotation_AHRS_GPS_P_g.Ascendanddescendtracking1_Tc__a;
  } else {
    Rotation_AHRS_GPS_B.rtb_Product_em_idx_3 =
      Rotation_AHRS_GPS_P_g.Ascendanddescendtracking1_Tc__g;
  }

  Rotation_AHRS_GPS_B.Product2_jx = Rotation_AHRS_GPS_B.Divide1_i /
    Rotation_AHRS_GPS_B.rtb_Product_em_idx_3;
  Rotation_AHRS_GPS_B.Divide1_i = Rotation_AHRS_GPS_B.DiscreteTimeIntegrator1_f
    - Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_DSTA_ii;
  if (Rotation_AHRS_GPS_B.Divide1_i > Rotation_AHRS_GPS_P_g.Switch_Threshold_d)
  {
    Rotation_AHRS_GPS_B.rtb_Product_em_idx_3 =
      Rotation_AHRS_GPS_P_g.Ascendanddescendtracking2_Tc_as;
  } else {
    Rotation_AHRS_GPS_B.rtb_Product_em_idx_3 =
      Rotation_AHRS_GPS_P_g.Ascendanddescendtracking2_Tc_de;
  }

  Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_if = Rotation_AHRS_GPS_B.Divide1_i /
    Rotation_AHRS_GPS_B.rtb_Product_em_idx_3;
  rtb_LogicalOperator12_h = (((*rtu_hover_flag) &&
    (Rotation_AHRS_GPS_P_g.Gain1_Gain_c * (real32_T)fabs
     (Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_ez) <=
     Rotation_AHRS_GPS_P_g.CompareToConstant1_const_d)) || tmp);
  *rty_att_init_done = (Rotation_AHRS_GPS_B.LogicalOperator8_d &&
                        (*rty_rp_init_done));
  if (Rotation_AHRS_GPS_B.LogicalOperator8_d) {
    if (Rotation_AHRS_GPS_B.Compare_nc) {
      Rotation_AHRS_GPS_B.Product2_lr = Rotation_AHRS_GPS_P_g.Constant_Value_h;
    } else {
      Rotation_AHRS_GPS_B.Product2_lr = Rotation_AHRS_GPS_P_g.Constant4_Value;
    }
  } else {
    Rotation_AHRS_GPS_B.u0 = 1.0F / (Rotation_AHRS_GPS_P_g.Linearinterp2_x_r_a -
      Rotation_AHRS_GPS_P_g.Linearinterp2_x_l_a) *
      (Rotation_AHRS_GPS_B.mag_gain2_l -
       Rotation_AHRS_GPS_P_g.Linearinterp2_x_l_a);
    if (Rotation_AHRS_GPS_B.u0 > Rotation_AHRS_GPS_P_g.Saturation_UpperSat_p) {
      Rotation_AHRS_GPS_B.u0 = Rotation_AHRS_GPS_P_g.Saturation_UpperSat_p;
    } else {
      if (Rotation_AHRS_GPS_B.u0 < Rotation_AHRS_GPS_P_g.Saturation_LowerSat_n)
      {
        Rotation_AHRS_GPS_B.u0 = Rotation_AHRS_GPS_P_g.Saturation_LowerSat_n;
      }
    }

    Rotation_AHRS_GPS_B.Product2_lr = (Rotation_AHRS_GPS_P_g.Linearinterp2_y_r_g
      - Rotation_AHRS_GPS_P_g.Linearinterp2_y_l_m) * Rotation_AHRS_GPS_B.u0 +
      Rotation_AHRS_GPS_P_g.Linearinterp2_y_l_m;
  }

  Rotation_AHRS_GPS_B.Product_e[0] = (real32_T)(rtb_LogicalOperator12_h &&
    (Rotation_AHRS_GPS_B.rtb_Sum_jx_idx_0 - Rotation_AHRS_GPS_B.y ==
     Rotation_AHRS_GPS_P_g.CompareToConstant_const_he)) *
    (Rotation_AHRS_GPS_P_g.Gain5_Gain_o * Rotation_AHRS_GPS_B.Product_e[0] *
     Rotation_AHRS_GPS_B.Product2_lr) *
    Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_io;
  Rotation_AHRS_GPS_B.Product_e[1] = (real32_T)(rtb_LogicalOperator12_h &&
    (Rotation_AHRS_GPS_B.rtb_Sum_jx_idx_1 - Rotation_AHRS_GPS_B.y_l ==
     Rotation_AHRS_GPS_P_g.CompareToConstant_const_he)) *
    (Rotation_AHRS_GPS_P_g.Gain5_Gain_o * Rotation_AHRS_GPS_B.Product_e[1] *
     Rotation_AHRS_GPS_B.Product2_lr) *
    Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_io;
  if (Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_oa >
      Rotation_AHRS_GPS_P_g.Saturation_UpperSat_bj) {
    Rotation_AHRS_GPS_B.rtb_Product_em_idx_3 =
      Rotation_AHRS_GPS_P_g.Saturation_UpperSat_bj;
  } else if (Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_oa <
             Rotation_AHRS_GPS_P_g.Saturation_LowerSat_e1) {
    Rotation_AHRS_GPS_B.rtb_Product_em_idx_3 =
      Rotation_AHRS_GPS_P_g.Saturation_LowerSat_e1;
  } else {
    Rotation_AHRS_GPS_B.rtb_Product_em_idx_3 =
      Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_oa;
  }

  Rotation_AHRS_GPS_B.rtb_Product_e_c = (real32_T)(rtb_LogicalOperator12_h &&
    (Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_oa -
     Rotation_AHRS_GPS_B.rtb_Product_em_idx_3 ==
     Rotation_AHRS_GPS_P_g.CompareToConstant_const_he)) *
    (Rotation_AHRS_GPS_P_g.Gain5_Gain_o * Rotation_AHRS_GPS_B.rtb_Product_e_c *
     Rotation_AHRS_GPS_B.Product2_lr) *
    Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_io;
  Rotation_AHRS_GPS_B.rtb_Sum_jx_idx_1 = Rotation_AHRS_GPS_P_g.Gain1_Gain_k *
    *rty_yaw_mag;
  Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_io =
    Rotation_AHRS_GPS_B.rtb_Sum_jx_idx_1 - Rotation_AHRS_GPS_DW.UD_DSTATE;
  if (Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_io < 0.0F) {
    Rotation_AHRS_GPS_B.rtb_Product_em_idx_3 = -1.0F;
  } else if (Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_io > 0.0F) {
    Rotation_AHRS_GPS_B.rtb_Product_em_idx_3 = 1.0F;
  } else if (Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_io == 0.0F) {
    Rotation_AHRS_GPS_B.rtb_Product_em_idx_3 = 0.0F;
  } else {
    Rotation_AHRS_GPS_B.rtb_Product_em_idx_3 = (rtNaNF);
  }

  if (Rotation_AHRS_GPS_B.rtb_Product_em_idx_3 >=
      Rotation_AHRS_GPS_P_g.Switch_Threshold_j) {
    Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_io =
      Rotation_AHRS_GPS_rt_modf_snf
      (Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_io,
       Rotation_AHRS_GPS_P_g.Constant_Value_p3);
  } else {
    Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_io =
      Rotation_AHRS_GPS_rt_modf_snf
      (Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_io,
       Rotation_AHRS_GPS_P_g.Constant_Value_p3) +
      Rotation_AHRS_GPS_P_g.Bias_Bias;
  }

  if (Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_io <
      Rotation_AHRS_GPS_P_g.CompareToConstant1_const_p) {
    Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_io +=
      Rotation_AHRS_GPS_P_g.Constant_Value_ec;
  }

  if (Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_io >
      Rotation_AHRS_GPS_P_g.CompareToConstant1_const_h) {
    Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_io -=
      Rotation_AHRS_GPS_P_g.Constant_Value_d;
  }

  Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_oa =
    Rotation_AHRS_GPS_P_g.Gain2_Gain_mr *
    Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_io;
  Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_io =
    Rotation_AHRS_GPS_B.DataTypeConversion -
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_DSTA_fu;
  if (Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_io >
      Rotation_AHRS_GPS_P_g.Switch_Threshold_m) {
    Rotation_AHRS_GPS_B.rtb_Product_em_idx_3 =
      Rotation_AHRS_GPS_P_g.Ascendanddescendtracking_Tc_asc;
  } else {
    Rotation_AHRS_GPS_B.rtb_Product_em_idx_3 =
      Rotation_AHRS_GPS_P_g.Ascendanddescendtracking_Tc_des;
  }

  Rotation_AHRS_GPS_B.DataTypeConversion =
    Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_io /
    Rotation_AHRS_GPS_B.rtb_Product_em_idx_3;
  if (Rotation_AHRS_GPS_B.DataTypeConversion1_ba &&
      (Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_PrevRe_o <= 0)) {
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_ol =
      Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_IC_a;
  }

  Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_io = (real32_T)((real32_T)fabs
    (Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_g0) <
    Rotation_AHRS_GPS_P_g.CompareToConstant2_const_n) -
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_DSTA_ft;
  if (Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_io >
      Rotation_AHRS_GPS_P_g.Switch_Threshold_aq) {
    Rotation_AHRS_GPS_B.rtb_Product_em_idx_3 =
      Rotation_AHRS_GPS_P_g.Ascendanddescendtracking1_Tc__m;
  } else {
    Rotation_AHRS_GPS_B.rtb_Product_em_idx_3 =
      Rotation_AHRS_GPS_P_g.Ascendanddescendtracking1_Tc__n;
  }

  Rotation_AHRS_GPS_B.Product2_eb =
    Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_io /
    Rotation_AHRS_GPS_B.rtb_Product_em_idx_3;
  Rotation_AHRS_GPS_B.Compare_nc = ((*rtu_Armed) && ((int32_T)
    Rotation_AHRS_GPS_B.LogicalOperator2_p > (int32_T)
    Rotation_AHRS_GPS_DW.DelayInput1_DSTATE_fq));
  if (Rotation_AHRS_GPS_B.Compare_nc &&
      (Rotation_AHRS_GPS_PrevZCX.Delay_Reset_ZCE != POS_ZCSIG)) {
    Rotation_AHRS_GPS_DW.icLoad_o = 1U;
  }

  Rotation_AHRS_GPS_PrevZCX.Delay_Reset_ZCE = Rotation_AHRS_GPS_B.Compare_nc;
  if (Rotation_AHRS_GPS_DW.icLoad_o != 0) {
    Rotation_AHRS_GPS_DW.Delay_DSTATE_ih = Rotation_AHRS_GPS_B.det_yaw_mag_c;
  }

  Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_io = (real32_T)((real32_T)fabs
    (Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_m0) <
    Rotation_AHRS_GPS_P_g.CompareToConstant1_const_o) -
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_DSTAT_d;
  if (Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_io >
      Rotation_AHRS_GPS_P_g.Switch_Threshold_h) {
    Rotation_AHRS_GPS_B.rtb_Product_em_idx_3 =
      Rotation_AHRS_GPS_P_g.Ascendanddescendtracking1_Tc__l;
  } else {
    Rotation_AHRS_GPS_B.rtb_Product_em_idx_3 =
      Rotation_AHRS_GPS_P_g.Ascendanddescendtracking1_Tc__e;
  }

  Rotation_AHRS_GPS_B.det_yaw_mag_c =
    Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_io /
    Rotation_AHRS_GPS_B.rtb_Product_em_idx_3;
  Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_io = (real32_T)((real32_T)fabs
    (Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_ep) <
    Rotation_AHRS_GPS_P_g.CompareToConstant7_const_m) -
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_DSTA_pn;
  if (Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_io >
      Rotation_AHRS_GPS_P_g.Switch_Threshold_f) {
    Rotation_AHRS_GPS_B.rtb_Product_em_idx_3 =
      Rotation_AHRS_GPS_P_g.Ascendanddescendtracking1_Tc__b;
  } else {
    Rotation_AHRS_GPS_B.rtb_Product_em_idx_3 =
      Rotation_AHRS_GPS_P_g.Ascendanddescendtracking1_Tc__j;
  }

  Rotation_AHRS_GPS_B.Gain_n = Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_io /
    Rotation_AHRS_GPS_B.rtb_Product_em_idx_3;
  mw_arm_sqrt_f32(((Rotation_AHRS_GPS_B.Switch_c[0] *
                    Rotation_AHRS_GPS_B.Switch_c[0] +
                    Rotation_AHRS_GPS_B.Switch_c[1] *
                    Rotation_AHRS_GPS_B.Switch_c[1]) +
                   Rotation_AHRS_GPS_B.Switch_c[2] *
                   Rotation_AHRS_GPS_B.Switch_c[2]) +
                  Rotation_AHRS_GPS_B.Switch_c[3] *
                  Rotation_AHRS_GPS_B.Switch_c[3],
                  &Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_io);
  if ((!(Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_io >
         Rotation_AHRS_GPS_P_g.Normalization_Min_Mag_j)) && (!rtIsNaNF
       (Rotation_AHRS_GPS_P_g.Normalization_Min_Mag_j))) {
    Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_io =
      Rotation_AHRS_GPS_P_g.Normalization_Min_Mag_j;
  }

  Rotation_AHRS_GPS_B.rtb_Product_em_idx_0 = Rotation_AHRS_GPS_B.Switch_c[0] /
    Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_io;
  Rotation_AHRS_GPS_B.rtb_Product_em_idx_1 = Rotation_AHRS_GPS_B.Switch_c[1] /
    Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_io;
  Rotation_AHRS_GPS_B.rtb_Product_em_idx_2 = Rotation_AHRS_GPS_B.Switch_c[2] /
    Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_io;
  Rotation_AHRS_GPS_B.rtb_Product_em_idx_3 = Rotation_AHRS_GPS_B.Switch_c[3] /
    Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_io;
  mw_arm_sqrt_f32(((Rotation_AHRS_GPS_B.rtb_Product_em_idx_0 *
                    Rotation_AHRS_GPS_B.rtb_Product_em_idx_0 +
                    Rotation_AHRS_GPS_B.rtb_Product_em_idx_1 *
                    Rotation_AHRS_GPS_B.rtb_Product_em_idx_1) +
                   Rotation_AHRS_GPS_B.rtb_Product_em_idx_2 *
                   Rotation_AHRS_GPS_B.rtb_Product_em_idx_2) +
                  Rotation_AHRS_GPS_B.rtb_Product_em_idx_3 *
                  Rotation_AHRS_GPS_B.rtb_Product_em_idx_3,
                  &Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_io);
  Rotation_AHRS_GPS_B.Product2_lr = Rotation_AHRS_GPS_B.rtb_Product_em_idx_0 /
    Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_io;
  Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_mg =
    Rotation_AHRS_GPS_B.rtb_Product_em_idx_1 /
    Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_io;
  Rotation_AHRS_GPS_B.Divide1_i = Rotation_AHRS_GPS_B.rtb_Product_em_idx_2 /
    Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_io;
  Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_io =
    Rotation_AHRS_GPS_B.rtb_Product_em_idx_3 /
    Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_io;
  Rotation_AHRS_GPS_B.rtb_Sum_jx_idx_0 = Rotation_AHRS_GPS_rt_atan2f_snf
    ((Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_mg *
      Rotation_AHRS_GPS_B.Divide1_i + Rotation_AHRS_GPS_B.Product2_lr *
      Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_io) * 2.0F,
     ((Rotation_AHRS_GPS_B.Product2_lr * Rotation_AHRS_GPS_B.Product2_lr +
       Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_mg *
       Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_mg) -
      Rotation_AHRS_GPS_B.Divide1_i * Rotation_AHRS_GPS_B.Divide1_i) -
     Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_io *
     Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_io);
  if (Rotation_AHRS_GPS_DW.Delay7_DSTATE &&
      (Rotation_AHRS_GPS_PrevZCX.Delay4_Reset_ZCE != POS_ZCSIG)) {
    Rotation_AHRS_GPS_DW.icLoad_i = 1U;
  }

  Rotation_AHRS_GPS_PrevZCX.Delay4_Reset_ZCE =
    Rotation_AHRS_GPS_DW.Delay7_DSTATE;
  if (Rotation_AHRS_GPS_DW.icLoad_i != 0) {
    Rotation_AHRS_GPS_DW.Delay4_DSTATE = Rotation_AHRS_GPS_DW.Delay5_DSTATE;
  }

  Rotation_AHRS_GPS_B.Compare_nc = (((int32_T)
    Rotation_AHRS_GPS_B.DataTypeConversion1_ba > (int32_T)
    Rotation_AHRS_GPS_DW.DelayInput1_DSTATE_ms) || ((int32_T)
    Rotation_AHRS_GPS_B.DataTypeConversion1_j > (int32_T)
    Rotation_AHRS_GPS_DW.DelayInput1_DSTATE_bu));
  if (Rotation_AHRS_GPS_B.Compare_nc &&
      (Rotation_AHRS_GPS_PrevZCX.Delay6_Reset_ZCE != POS_ZCSIG)) {
    Rotation_AHRS_GPS_DW.icLoad_n = 1U;
  }

  Rotation_AHRS_GPS_PrevZCX.Delay6_Reset_ZCE = Rotation_AHRS_GPS_B.Compare_nc;
  if (Rotation_AHRS_GPS_DW.icLoad_n != 0) {
    Rotation_AHRS_GPS_DW.Delay6_DSTATE = Rotation_AHRS_GPS_DW.Delay11_DSTATE;
  }

  Rotation_AHRS_GPS_B.Divide1_i = Rotation_AHRS_GPS_DW.Delay4_DSTATE * (real32_T)*
    rtu_Armed;
  Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_mg = (real32_T)*rtu_Armed *
    Rotation_AHRS_GPS_DW.Delay6_DSTATE;
  Rotation_AHRS_GPS_B.Product2_lr = Rotation_AHRS_GPS_P_g.Gain_Gain_n1 *
    Rotation_AHRS_GPS_B.Subtract_kk;
  Rotation_AHRS_GPS_B.rtb_Product_em_idx_3 = arm_sin_f32
    (Rotation_AHRS_GPS_B.Product2_lr);
  Rotation_AHRS_GPS_B.rtb_Product_em_idx_0 = arm_cos_f32
    (Rotation_AHRS_GPS_B.Product2_lr);
  Rotation_AHRS_GPS_DW.Delay13_DSTATE[0] =
    ((Rotation_AHRS_GPS_B.rtb_Product_em_idx_0 * rty_Rotation_data_ATT_quat_OB[0]
      - Rotation_AHRS_GPS_P_g.Constant_Value_id * rty_Rotation_data_ATT_quat_OB
      [1]) - Rotation_AHRS_GPS_P_g.Constant_Value_id *
     rty_Rotation_data_ATT_quat_OB[2]) -
    Rotation_AHRS_GPS_B.rtb_Product_em_idx_3 * rty_Rotation_data_ATT_quat_OB[3];
  Rotation_AHRS_GPS_DW.Delay13_DSTATE[1] =
    ((Rotation_AHRS_GPS_B.rtb_Product_em_idx_0 * rty_Rotation_data_ATT_quat_OB[1]
      + Rotation_AHRS_GPS_P_g.Constant_Value_id * rty_Rotation_data_ATT_quat_OB
      [0]) + Rotation_AHRS_GPS_P_g.Constant_Value_id *
     rty_Rotation_data_ATT_quat_OB[3]) -
    Rotation_AHRS_GPS_B.rtb_Product_em_idx_3 * rty_Rotation_data_ATT_quat_OB[2];
  Rotation_AHRS_GPS_DW.Delay13_DSTATE[2] =
    ((Rotation_AHRS_GPS_B.rtb_Product_em_idx_0 * rty_Rotation_data_ATT_quat_OB[2]
      - Rotation_AHRS_GPS_P_g.Constant_Value_id * rty_Rotation_data_ATT_quat_OB
      [3]) + Rotation_AHRS_GPS_P_g.Constant_Value_id *
     rty_Rotation_data_ATT_quat_OB[0]) +
    Rotation_AHRS_GPS_B.rtb_Product_em_idx_3 * rty_Rotation_data_ATT_quat_OB[1];
  Rotation_AHRS_GPS_DW.Delay13_DSTATE[3] =
    ((Rotation_AHRS_GPS_B.rtb_Product_em_idx_0 * rty_Rotation_data_ATT_quat_OB[3]
      + Rotation_AHRS_GPS_P_g.Constant_Value_id * rty_Rotation_data_ATT_quat_OB
      [2]) - Rotation_AHRS_GPS_P_g.Constant_Value_id *
     rty_Rotation_data_ATT_quat_OB[1]) +
    Rotation_AHRS_GPS_B.rtb_Product_em_idx_3 * rty_Rotation_data_ATT_quat_OB[0];
  Rotation_AHRS_GPS_B.Product2_lr = Rotation_AHRS_GPS_P_g.Gain_Gain_fxn *
    Rotation_AHRS_GPS_B.Subtract_kk;
  Rotation_AHRS_GPS_B.rtb_Product_em_idx_3 = arm_sin_f32
    (Rotation_AHRS_GPS_B.Product2_lr);
  Rotation_AHRS_GPS_B.rtb_Product_em_idx_0 = arm_cos_f32
    (Rotation_AHRS_GPS_B.Product2_lr);
  *rty_det_yaw_gohome = Rotation_AHRS_GPS_B.Divide1_i +
    Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_mg;
  Rotation_AHRS_GPS_DW.Delay11_DSTATE =
    Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_mg +
    Rotation_AHRS_GPS_B.Subtract_kk;
  Rotation_AHRS_GPS_B.u[0] = rty_Rotation_data_ATT_quat_OB[0];
  Rotation_AHRS_GPS_B.u[1] = rty_Rotation_data_ATT_quat_OB[1];
  Rotation_AHRS_GPS_B.u[2] = rty_Rotation_data_ATT_quat_OB[2];
  Rotation_AHRS_GPS_B.u[3] = rty_Rotation_data_ATT_quat_OB[3];
  Rotation_AHRS_GPS_B.u[4] = Rotation_AHRS_GPS_B.Switch_c[4];
  Rotation_AHRS_GPS_B.u[5] = Rotation_AHRS_GPS_B.Switch_c[5];
  Rotation_AHRS_GPS_B.u[6] = Rotation_AHRS_GPS_B.Switch_c[6];
  Rotation_AHRS_GPS_B.TmpSignalConversionAtDelayI[0] =
    rty_Rotation_data_ATT_quat_OB[0];
  Rotation_AHRS_GPS_B.TmpSignalConversionAtDelayI[1] =
    rty_Rotation_data_ATT_quat_OB[1];
  Rotation_AHRS_GPS_B.TmpSignalConversionAtDelayI[2] =
    rty_Rotation_data_ATT_quat_OB[2];
  Rotation_AHRS_GPS_B.TmpSignalConversionAtDelayI[3] =
    rty_Rotation_data_ATT_quat_OB[3];
  Rotation_AHRS_GPS_B.Compare_nc = (Rotation_AHRS_GPS_B.LogicalOperator8_e &&
    (*rtu_Sensor_data_GPS_data_Spd_qu >
     Rotation_AHRS_GPS_P_g.CompareToConstant3_const_m4) &&
    (*rtu_Sensor_data_Mag_Quality >
     Rotation_AHRS_GPS_P_g.CompareToConstant_const_e5));
  Rotation_AHRS_GPS_B.LogicalOperator8_e =
    (Rotation_AHRS_GPS_B.LogicalOperator8_e && (!*rtu_forcedArm));
  Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_io =
    Rotation_AHRS_GPS_B.Saturation1 -
    Rotation_AHRS_GPS_B.DiscreteTimeIntegrator1_k;
  Rotation_AHRS_GPS_B.Saturation1 =
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE_f;
  rtb_Uk1_b = (((*rtu_Sensor_data_GPS_data_Spd_qu >
                 Rotation_AHRS_GPS_P_g.CompareToConstant_const_hz) &&
                (Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_DSTA_la >
                 Rotation_AHRS_GPS_P_g.CompareToConstant7_const_b)) ||
               (*rtu_Sensor_data_GPS_data_Spd_qu <=
                Rotation_AHRS_GPS_P_g.CompareToConstant8_const_e));
  rtb_LogicalOperator12_h = (((*rtu_h >=
    Rotation_AHRS_GPS_P_g.CompareToConstant1_const_hs) ||
    (*rtu_Sensor_data_Sonar_data_h_gr >=
     Rotation_AHRS_GPS_P_g.CompareToConstant5_const_i)) && rtb_Uk1_b);
  rtb_Uk1_b = (((*rtu_h >= Rotation_AHRS_GPS_P_g.CompareToConstant2_const_b) ||
                (*rtu_Sensor_data_Sonar_data_h_gr >=
                 Rotation_AHRS_GPS_P_g.CompareToConstant3_const_n)) && rtb_Uk1_b);
  Rotation_AHRS_GPS_B.TmpSignalConversionAtDelayI[4] =
    Rotation_AHRS_GPS_P_g.Constant1_Value_p[0];
  rty_Rotation_data_vel_O_O[0] = Rotation_AHRS_GPS_P_g.Constant_Value_jz[0];
  Rotation_AHRS_GPS_B.TmpSignalConversionAtDelayI[5] =
    Rotation_AHRS_GPS_P_g.Constant1_Value_p[1];
  rty_Rotation_data_vel_O_O[1] = Rotation_AHRS_GPS_P_g.Constant_Value_jz[1];
  Rotation_AHRS_GPS_B.TmpSignalConversionAtDelayI[6] =
    Rotation_AHRS_GPS_P_g.Constant1_Value_p[2];
  rty_Rotation_data_vel_O_O[2] = Rotation_AHRS_GPS_P_g.Constant_Value_jz[2];
  *rty_Rotation_data_standstill = Rotation_AHRS_GPS_B.LogicalOperator8_e;
  *rty_Rotation_data_rp_init_reset = Rotation_AHRS_GPS_B.LogicalOperator3_f;
  *rty_Rotation_data_heading_init = Rotation_AHRS_GPS_B.LogicalOperator1_i;
  Rotation_AHRS_GPS_B.rtb_Divide2_idx_0 = (rty_Rotation_data_ATT_quat_OB[1] *
    rty_Rotation_data_ATT_quat_OB[2] - rty_Rotation_data_ATT_quat_OB[0] *
    rty_Rotation_data_ATT_quat_OB[3]) * Rotation_AHRS_GPS_P_g.Gain2_Gain_k;
  Rotation_AHRS_GPS_B.VectorConcatenate_k[0] = rty_Rotation_data_ATT_quat_OB[0] *
    rty_Rotation_data_ATT_quat_OB[0];
  Rotation_AHRS_GPS_B.VectorConcatenate_k[1] = rty_Rotation_data_ATT_quat_OB[1] *
    rty_Rotation_data_ATT_quat_OB[1];
  Rotation_AHRS_GPS_B.VectorConcatenate_k[2] = rty_Rotation_data_ATT_quat_OB[2] *
    rty_Rotation_data_ATT_quat_OB[2];
  Rotation_AHRS_GPS_B.VectorConcatenate_k[3] = rty_Rotation_data_ATT_quat_OB[3] *
    rty_Rotation_data_ATT_quat_OB[3];
  Rotation_AHRS_GPS_B.rtb_Divide2_idx_1 =
    ((Rotation_AHRS_GPS_B.VectorConcatenate_k[0] -
      Rotation_AHRS_GPS_B.VectorConcatenate_k[1]) +
     Rotation_AHRS_GPS_B.VectorConcatenate_k[2]) -
    Rotation_AHRS_GPS_B.VectorConcatenate_k[3];
  mw_arm_sqrt_f32(Rotation_AHRS_GPS_B.rtb_Divide2_idx_0 *
                  Rotation_AHRS_GPS_B.rtb_Divide2_idx_0 +
                  Rotation_AHRS_GPS_B.rtb_Divide2_idx_1 *
                  Rotation_AHRS_GPS_B.rtb_Divide2_idx_1,
                  &Rotation_AHRS_GPS_B.Product2_lr);
  if ((Rotation_AHRS_GPS_B.Product2_lr > Rotation_AHRS_GPS_P_g.Constant1_Value_g)
      || rtIsNaNF(Rotation_AHRS_GPS_P_g.Constant1_Value_g)) {
    Rotation_AHRS_GPS_B.DiscreteTimeIntegrator1_k =
      Rotation_AHRS_GPS_B.Product2_lr;
  } else {
    Rotation_AHRS_GPS_B.DiscreteTimeIntegrator1_k =
      Rotation_AHRS_GPS_P_g.Constant1_Value_g;
  }

  Rotation_AHRS_GPS_B.rtb_MathFunction_l_idx_0 =
    Rotation_AHRS_GPS_B.rtb_Divide2_idx_0 /
    Rotation_AHRS_GPS_B.DiscreteTimeIntegrator1_k;
  Rotation_AHRS_GPS_B.Subtract_kk = Rotation_AHRS_GPS_B.rtb_Divide2_idx_1 /
    Rotation_AHRS_GPS_B.DiscreteTimeIntegrator1_k;
  Rotation_AHRS_GPS_B.rtb_Product_em_idx_1 =
    ((Rotation_AHRS_GPS_B.VectorConcatenate_k[0] +
      Rotation_AHRS_GPS_B.VectorConcatenate_k[1]) -
     Rotation_AHRS_GPS_B.VectorConcatenate_k[2]) -
    Rotation_AHRS_GPS_B.VectorConcatenate_k[3];
  Rotation_AHRS_GPS_B.rtb_Divide2_idx_1 = (rty_Rotation_data_ATT_quat_OB[1] *
    rty_Rotation_data_ATT_quat_OB[2] + rty_Rotation_data_ATT_quat_OB[0] *
    rty_Rotation_data_ATT_quat_OB[3]) * Rotation_AHRS_GPS_P_g.Gain_Gain_ok;
  mw_arm_sqrt_f32(Rotation_AHRS_GPS_B.rtb_Product_em_idx_1 *
                  Rotation_AHRS_GPS_B.rtb_Product_em_idx_1 +
                  Rotation_AHRS_GPS_B.rtb_Divide2_idx_1 *
                  Rotation_AHRS_GPS_B.rtb_Divide2_idx_1,
                  &Rotation_AHRS_GPS_B.Product2_lr);
  if ((Rotation_AHRS_GPS_B.Product2_lr > Rotation_AHRS_GPS_P_g.Constant2_Value_l)
      || rtIsNaNF(Rotation_AHRS_GPS_P_g.Constant2_Value_l)) {
    Rotation_AHRS_GPS_B.DiscreteTimeIntegrator1_k =
      Rotation_AHRS_GPS_B.Product2_lr;
  } else {
    Rotation_AHRS_GPS_B.DiscreteTimeIntegrator1_k =
      Rotation_AHRS_GPS_P_g.Constant2_Value_l;
  }

  Rotation_AHRS_GPS_B.rtb_Divide2_p = Rotation_AHRS_GPS_B.rtb_Product_em_idx_1 /
    Rotation_AHRS_GPS_B.DiscreteTimeIntegrator1_k +
    Rotation_AHRS_GPS_B.rtb_MathFunction_l_idx_0;
  Rotation_AHRS_GPS_B.rtb_MathFunction_l_idx_0 =
    Rotation_AHRS_GPS_B.rtb_Divide2_p * Rotation_AHRS_GPS_B.rtb_Divide2_p;
  Rotation_AHRS_GPS_B.rtb_Divide2_idx_0 = Rotation_AHRS_GPS_B.rtb_Divide2_p;
  Rotation_AHRS_GPS_B.rtb_Divide2_p = Rotation_AHRS_GPS_B.rtb_Divide2_idx_1 /
    Rotation_AHRS_GPS_B.DiscreteTimeIntegrator1_k +
    Rotation_AHRS_GPS_B.Subtract_kk;
  mw_arm_sqrt_f32(Rotation_AHRS_GPS_B.rtb_Divide2_p *
                  Rotation_AHRS_GPS_B.rtb_Divide2_p +
                  Rotation_AHRS_GPS_B.rtb_MathFunction_l_idx_0,
                  &Rotation_AHRS_GPS_B.Product2_lr);
  if ((Rotation_AHRS_GPS_B.Product2_lr > Rotation_AHRS_GPS_P_g.Constant3_Value_d)
      || rtIsNaNF(Rotation_AHRS_GPS_P_g.Constant3_Value_d)) {
    Rotation_AHRS_GPS_B.DiscreteTimeIntegrator1_k =
      Rotation_AHRS_GPS_B.Product2_lr;
  } else {
    Rotation_AHRS_GPS_B.DiscreteTimeIntegrator1_k =
      Rotation_AHRS_GPS_P_g.Constant3_Value_d;
  }

  Rotation_AHRS_GPS_B.rtb_Divide2_idx_0 /=
    Rotation_AHRS_GPS_B.DiscreteTimeIntegrator1_k;
  Rotation_AHRS_GPS_B.rtb_Divide2_p /=
    Rotation_AHRS_GPS_B.DiscreteTimeIntegrator1_k;
  Rotation_AHRS_GPS_B.VectorConcatenate_k[0] =
    Rotation_AHRS_GPS_B.rtb_Divide2_idx_0;
  Rotation_AHRS_GPS_B.VectorConcatenate_k[1] = Rotation_AHRS_GPS_B.rtb_Divide2_p;
  Rotation_AHRS_GPS_B.VectorConcatenate_k[2] =
    Rotation_AHRS_GPS_P_g.Gain1_Gain_e * Rotation_AHRS_GPS_B.rtb_Divide2_p;
  Rotation_AHRS_GPS_B.VectorConcatenate_k[3] =
    Rotation_AHRS_GPS_B.rtb_Divide2_idx_0;
  for (Rotation_AHRS_GPS_B.i = 0; Rotation_AHRS_GPS_B.i < 2;
       Rotation_AHRS_GPS_B.i++) {
    Rotation_AHRS_GPS_B.j = Rotation_AHRS_GPS_B.i << 1;
    Rotation_AHRS_GPS_B.Divide3[Rotation_AHRS_GPS_B.j] = 0.0F;
    Rotation_AHRS_GPS_B.Divide3[Rotation_AHRS_GPS_B.j] +=
      Rotation_AHRS_GPS_P_g.Gain3_Gain_l *
      Rotation_AHRS_GPS_P_g.Constant4_Value_p[0] *
      Rotation_AHRS_GPS_B.VectorConcatenate_k[Rotation_AHRS_GPS_B.j];
    Rotation_AHRS_GPS_B.rtb_MathFunction2_tmp = Rotation_AHRS_GPS_B.j + 1;
    Rotation_AHRS_GPS_B.Divide3[Rotation_AHRS_GPS_B.j] +=
      Rotation_AHRS_GPS_B.VectorConcatenate_k[Rotation_AHRS_GPS_B.rtb_MathFunction2_tmp]
      * (Rotation_AHRS_GPS_P_g.Gain3_Gain_l *
         Rotation_AHRS_GPS_P_g.Constant4_Value_p[2]);
    Rotation_AHRS_GPS_B.j++;
    Rotation_AHRS_GPS_B.Divide3[Rotation_AHRS_GPS_B.j] = 0.0F;
    Rotation_AHRS_GPS_B.Divide3[Rotation_AHRS_GPS_B.j] =
      Rotation_AHRS_GPS_B.Divide3[Rotation_AHRS_GPS_B.rtb_MathFunction2_tmp] +
      Rotation_AHRS_GPS_P_g.Gain3_Gain_l *
      Rotation_AHRS_GPS_P_g.Constant4_Value_p[1] *
      Rotation_AHRS_GPS_B.VectorConcatenate_k[Rotation_AHRS_GPS_B.i << 1];
    Rotation_AHRS_GPS_B.Divide3[Rotation_AHRS_GPS_B.j] =
      Rotation_AHRS_GPS_B.VectorConcatenate_k[(Rotation_AHRS_GPS_B.i << 1) + 1] *
      (Rotation_AHRS_GPS_P_g.Gain3_Gain_l *
       Rotation_AHRS_GPS_P_g.Constant4_Value_p[3]) +
      Rotation_AHRS_GPS_B.Divide3[Rotation_AHRS_GPS_B.rtb_MathFunction2_tmp];
  }

  Rotation_AHRS_GPS_B.LogicalOperator8_e = (((int32_T)
    Rotation_AHRS_GPS_B.DataTypeConversion1_j > (int32_T)
    Rotation_AHRS_GPS_DW.DelayInput1_DSTATE_dc) || ((int32_T)
    Rotation_AHRS_GPS_B.DataTypeConversion1_ba > (int32_T)
    Rotation_AHRS_GPS_DW.DelayInput1_DSTATE_n5));
  if (Rotation_AHRS_GPS_B.LogicalOperator8_e ||
      (Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_PrevRe_l != 0)) {
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_jd =
      Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_IC_lq;
  }

  Rotation_AHRS_GPS_B.Sum2_j = (uint8_T)((uint32_T)
    (Rotation_AHRS_GPS_DW.Delay_DSTATE_j &&
     (!(Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_jd >=
        Rotation_AHRS_GPS_P_g.CompareTo1sec_const_n))) +
    Rotation_AHRS_GPS_B.LogicalOperator8_e);
  Rotation_AHRS_GPS_B.LogicalOperator3_f = (Rotation_AHRS_GPS_B.Sum2_j == 0);
  if (Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_IC_LO_md != 0) {
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_dm[0] =
      Rotation_AHRS_GPS_DW.Delay_DSTATE_l[0];
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_dm[1] =
      Rotation_AHRS_GPS_DW.Delay_DSTATE_l[1];
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_dm[2] =
      Rotation_AHRS_GPS_DW.Delay_DSTATE_l[2];
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_dm[3] =
      Rotation_AHRS_GPS_DW.Delay_DSTATE_l[3];
  }

  if (Rotation_AHRS_GPS_B.LogicalOperator3_f ||
      (Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_PrevR_m4 != 0)) {
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_dm[0] =
      Rotation_AHRS_GPS_DW.Delay_DSTATE_l[0];
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_dm[1] =
      Rotation_AHRS_GPS_DW.Delay_DSTATE_l[1];
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_dm[2] =
      Rotation_AHRS_GPS_DW.Delay_DSTATE_l[2];
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_dm[3] =
      Rotation_AHRS_GPS_DW.Delay_DSTATE_l[3];
  }

  rty_Rotation_data_M_OObar[0] =
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_dm[0];
  rty_Rotation_data_M_OObar[1] =
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_dm[1];
  rty_Rotation_data_M_OObar[2] =
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_dm[2];
  rty_Rotation_data_M_OObar[3] =
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_dm[3];
  *rty_Rotation_data_Euler_Transfo = Rotation_AHRS_GPS_rt_atan2f_snf
    ((rty_Rotation_data_ATT_quat_OB[1] * rty_Rotation_data_ATT_quat_OB[2] +
      rty_Rotation_data_ATT_quat_OB[0] * rty_Rotation_data_ATT_quat_OB[3]) *
     Rotation_AHRS_GPS_P_g.Gain_Gain_boy,
     Rotation_AHRS_GPS_B.rtb_Product_em_idx_1);
  rty_Rotation_data_rot_IB_B_radD[0] = rtu_Sensor_data_rot_IB_B_raw_ra[0] -
    Rotation_AHRS_GPS_B.Switch_c[4];
  rty_Rotation_data_rot_IB_B_radD[1] = rtu_Sensor_data_rot_IB_B_raw_ra[1] -
    Rotation_AHRS_GPS_B.Switch_c[5];
  rty_Rotation_data_rot_IB_B_radD[2] = rtu_Sensor_data_rot_IB_B_raw_ra[2] -
    Rotation_AHRS_GPS_B.Switch_c[6];
  Rotation_AHRS_GPS_B.u0 = Rotation_AHRS_GPS_P_g.Constant_Value_el -
    rty_Rotation_data_att_Oz_B[0] * rty_Rotation_data_att_Oz_B[0];
  if (Rotation_AHRS_GPS_B.u0 > Rotation_AHRS_GPS_P_g.Saturation_UpperSat_k) {
    Rotation_AHRS_GPS_B.u0 = Rotation_AHRS_GPS_P_g.Saturation_UpperSat_k;
  } else {
    if (Rotation_AHRS_GPS_B.u0 < Rotation_AHRS_GPS_P_g.Saturation_LowerSat_eo) {
      Rotation_AHRS_GPS_B.u0 = Rotation_AHRS_GPS_P_g.Saturation_LowerSat_eo;
    }
  }

  *rty_Rotation_data_Psi_dot_IMU = (rty_Rotation_data_rot_IB_B_radD[1] *
    rty_Rotation_data_att_Oz_B[1] + rty_Rotation_data_att_Oz_B[2] *
    rty_Rotation_data_rot_IB_B_radD[2]) / Rotation_AHRS_GPS_B.u0;
  Rotation_AHRS_GPS_B.u0 = Rotation_AHRS_GPS_P_g.Constant_Value_mg -
    rty_Rotation_data_att_Oz_B[0] * rty_Rotation_data_att_Oz_B[0];
  if (Rotation_AHRS_GPS_B.u0 > Rotation_AHRS_GPS_P_g.Saturation_UpperSat_hi) {
    Rotation_AHRS_GPS_B.u0 = Rotation_AHRS_GPS_P_g.Saturation_UpperSat_hi;
  } else {
    if (Rotation_AHRS_GPS_B.u0 < Rotation_AHRS_GPS_P_g.Saturation_LowerSat_oc) {
      Rotation_AHRS_GPS_B.u0 = Rotation_AHRS_GPS_P_g.Saturation_LowerSat_oc;
    }
  }

  *rty_Rotation_data_Psi_dot_fused = (Rotation_AHRS_GPS_B.Subtract_m[1] *
    rty_Rotation_data_att_Oz_B[1] + rty_Rotation_data_att_Oz_B[2] *
    Rotation_AHRS_GPS_B.Subtract_m[2]) / Rotation_AHRS_GPS_B.u0;
  *rty_Rotation_data_reset_Yaw = ((((int32_T)
    Rotation_AHRS_GPS_B.DataTypeConversion1_ba > (int32_T)
    Rotation_AHRS_GPS_DW.DelayInput1_DSTATE_px) || ((int32_T)
    Rotation_AHRS_GPS_B.DataTypeConversion1_j > (int32_T)
    Rotation_AHRS_GPS_DW.DelayInput1_DSTATE_by)) &&
    (Rotation_AHRS_GPS_B.rtb_DiscreteTimeIntegrator_mg_t >
     Rotation_AHRS_GPS_P_g.CompareToConstant_const_g3));
  rty_roll_pitch_rate_bias[0] = Rotation_AHRS_GPS_B.Gain10[0];
  rty_roll_pitch_rate_bias[1] = Rotation_AHRS_GPS_B.Gain10[1];
  *rty_yaw_rate_bias = Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_lk[2];
  Rotation_AHRS_GPS_DW.Delay4_DSTATE_p[0] =
    Rotation_AHRS_GPS_DW.Delay4_DSTATE_p[1];
  Rotation_AHRS_GPS_DW.Delay4_DSTATE_p[1] = ((int32_T)rtb_large_error_detected >
    (int32_T)Rotation_AHRS_GPS_DW.DelayInput1_DSTATE_bh);
  Rotation_AHRS_GPS_DW.Delay5_DSTATE_b = (((int32_T)((uint32_T)
    (Rotation_AHRS_GPS_DW.Delay_DSTATE_gd &&
     (!(Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_bu >=
        Rotation_AHRS_GPS_P_g.CompareTo1sec_const_d))) +
    rtb_FixPtRelationalOperator_jv) == 0) && ((int32_T)((uint32_T)
    (Rotation_AHRS_GPS_DW.Delay_DSTATE_ef &&
     (!(Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_cf >=
        Rotation_AHRS_GPS_P_g.CompareTo1sec_const_j))) +
    rtb_FixPtRelationalOperator_es) == 0));
  Rotation_AHRS_GPS_DW.Delay6_DSTATE_m[0] =
    Rotation_AHRS_GPS_DW.Delay6_DSTATE_m[1];
  Rotation_AHRS_GPS_DW.Delay6_DSTATE_m[1] =
    Rotation_AHRS_GPS_B.DataTypeConversion1_j;
  Rotation_AHRS_GPS_DW.Delay_DSTATE_g =
    Rotation_AHRS_GPS_B.DataTypeConversion1_j;
  Rotation_AHRS_GPS_DW.Delay17_DSTATE[0] =
    ((Rotation_AHRS_GPS_B.rtb_Product_em_idx_0 * rty_Rotation_data_ATT_quat_OB[0]
      - Rotation_AHRS_GPS_P_g.Constant_Value_ij * rty_Rotation_data_ATT_quat_OB
      [1]) - Rotation_AHRS_GPS_P_g.Constant_Value_ij *
     rty_Rotation_data_ATT_quat_OB[2]) -
    Rotation_AHRS_GPS_B.rtb_Product_em_idx_3 * rty_Rotation_data_ATT_quat_OB[3];
  Rotation_AHRS_GPS_DW.Delay17_DSTATE[1] =
    ((Rotation_AHRS_GPS_B.rtb_Product_em_idx_0 * rty_Rotation_data_ATT_quat_OB[1]
      + Rotation_AHRS_GPS_P_g.Constant_Value_ij * rty_Rotation_data_ATT_quat_OB
      [0]) + Rotation_AHRS_GPS_P_g.Constant_Value_ij *
     rty_Rotation_data_ATT_quat_OB[3]) -
    Rotation_AHRS_GPS_B.rtb_Product_em_idx_3 * rty_Rotation_data_ATT_quat_OB[2];
  Rotation_AHRS_GPS_DW.Delay17_DSTATE[2] =
    ((Rotation_AHRS_GPS_B.rtb_Product_em_idx_0 * rty_Rotation_data_ATT_quat_OB[2]
      - Rotation_AHRS_GPS_P_g.Constant_Value_ij * rty_Rotation_data_ATT_quat_OB
      [3]) + Rotation_AHRS_GPS_P_g.Constant_Value_ij *
     rty_Rotation_data_ATT_quat_OB[0]) +
    Rotation_AHRS_GPS_B.rtb_Product_em_idx_3 * rty_Rotation_data_ATT_quat_OB[1];
  Rotation_AHRS_GPS_DW.Delay17_DSTATE[3] =
    ((Rotation_AHRS_GPS_B.rtb_Product_em_idx_0 * rty_Rotation_data_ATT_quat_OB[3]
      + Rotation_AHRS_GPS_P_g.Constant_Value_ij * rty_Rotation_data_ATT_quat_OB
      [2]) - Rotation_AHRS_GPS_P_g.Constant_Value_ij *
     rty_Rotation_data_ATT_quat_OB[1]) +
    Rotation_AHRS_GPS_B.rtb_Product_em_idx_3 * rty_Rotation_data_ATT_quat_OB[0];
  Rotation_AHRS_GPS_DW.Delay17_DSTATE[4] = Rotation_AHRS_GPS_B.Switch_c[4];
  Rotation_AHRS_GPS_DW.Delay17_DSTATE[5] = Rotation_AHRS_GPS_B.Switch_c[5];
  Rotation_AHRS_GPS_DW.Delay17_DSTATE[6] = Rotation_AHRS_GPS_B.Switch_c[6];
  Rotation_AHRS_GPS_DW.icLoad = 0U;
  for (Rotation_AHRS_GPS_B.i = 0; Rotation_AHRS_GPS_B.i < 7;
       Rotation_AHRS_GPS_B.i++) {
    Rotation_AHRS_GPS_DW.Delay16_DSTATE[Rotation_AHRS_GPS_B.i] =
      Rotation_AHRS_GPS_B.u[Rotation_AHRS_GPS_B.i];
  }

  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE += (real32_T)
    ((Rotation_AHRS_GPS_B.acc_body[0] != 0.0F) && (Rotation_AHRS_GPS_B.acc_body
      [1] != 0.0F) && (Rotation_AHRS_GPS_B.acc_body[2] != 0.0F)) *
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_gainva_p;
  if (Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE >=
      Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_UpperSat) {
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE =
      Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_UpperSat;
  } else {
    if (Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE <=
        Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_LowerSat) {
      Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE =
        Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_LowerSat;
    }
  }

  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_IC_LOADI = 0U;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_IC_LOA_b = 0U;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE_a[0] +=
    (rtu_Sensor_data_rot_IB_B_raw_ra[0] -
     Rotation_AHRS_GPS_B.rtb_DiscreteTimeIntegrator_fl_i) *
    Rotation_AHRS_GPS_P_g.Gain_Gain_bv *
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_gainv_p2;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE_g[0] +=
    (rtu_Sensor_data_rot_IB_B_raw_ra[0] -
     Rotation_AHRS_GPS_B.rtb_DiscreteTimeIntegrator_fr_i) *
    Rotation_AHRS_GPS_P_g.Gain_Gain_ff *
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_gainva_k;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE_a[1] +=
    (rtu_Sensor_data_rot_IB_B_raw_ra[1] -
     Rotation_AHRS_GPS_B.rtb_DiscreteTimeIntegrator_fl_g) *
    Rotation_AHRS_GPS_P_g.Gain_Gain_bv *
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_gainv_p2;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE_g[1] +=
    (rtu_Sensor_data_rot_IB_B_raw_ra[1] -
     Rotation_AHRS_GPS_B.rtb_DiscreteTimeIntegrator_fr_n) *
    Rotation_AHRS_GPS_P_g.Gain_Gain_ff *
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_gainva_k;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_IC_LOAD = 0U;
  if (Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_io >
      Rotation_AHRS_GPS_P_g.Switch_Threshold_e) {
    Rotation_AHRS_GPS_B.rtb_Product_em_idx_3 =
      Rotation_AHRS_GPS_P_g.Ascendanddescendtracking_Tc_a_m;
  } else {
    Rotation_AHRS_GPS_B.rtb_Product_em_idx_3 =
      Rotation_AHRS_GPS_P_g.Ascendanddescendtracking_Tc_d_i;
  }

  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_DSTATE +=
    Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_io /
    Rotation_AHRS_GPS_B.rtb_Product_em_idx_3 *
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator1_gainval;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE_o +=
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_gainv_kh * (real32_T)
    Rotation_AHRS_GPS_B.trigger_reset;
  if (Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE_o >=
      Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_UpperS_g) {
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE_o =
      Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_UpperS_g;
  } else {
    if (Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE_o <=
        Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_LowerS_f) {
      Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE_o =
        Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_LowerS_f;
    }
  }

  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_PrevRese = (int8_T)
    Rotation_AHRS_GPS_B.LogicalOperator1;
  Rotation_AHRS_GPS_DW.DelayInput1_DSTATE_p = *rty_stand_still;
  Rotation_AHRS_GPS_DW.Delay_DSTATE_p =
    Rotation_AHRS_GPS_B.DataTypeConversion1_ba;
  Rotation_AHRS_GPS_DW.Delay13_DSTATE[4] = Rotation_AHRS_GPS_B.Switch_c[4];
  Rotation_AHRS_GPS_DW.Delay13_DSTATE[5] = Rotation_AHRS_GPS_B.Switch_c[5];
  Rotation_AHRS_GPS_DW.Delay13_DSTATE[6] = Rotation_AHRS_GPS_B.Switch_c[6];
  Rotation_AHRS_GPS_DW.icLoad_h = 0U;
  Rotation_AHRS_GPS_DW.Delay_DSTATE_k = ((int32_T)((uint32_T)*rtu_Armed +
    Rotation_AHRS_GPS_B.LogicalOperator_e) != 0);
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_DSTAT_c +=
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator1_gainv_b * (real32_T)
    rtb_LogicalOperator12_h;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_PrevRes = (int8_T)
    Rotation_AHRS_GPS_B.LogicalOperator6_m;
  Rotation_AHRS_GPS_DW.DelayInput1_DSTATE_i = Rotation_AHRS_GPS_B.Compare_g;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE_i +=
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_gainva_f * (real32_T)rtb_Uk1_b;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_PrevRe_a = (int8_T)
    Rotation_AHRS_GPS_B.LogicalOperator6_m;
  Rotation_AHRS_GPS_DW.DelayInput1_DSTATE_g = Rotation_AHRS_GPS_B.Compare_b;
  Rotation_AHRS_GPS_DW.DelayInput1_DSTATE_i5 = *rtu_IMU_switched;
  for (Rotation_AHRS_GPS_B.i = 0; Rotation_AHRS_GPS_B.i < 7;
       Rotation_AHRS_GPS_B.i++) {
    Rotation_AHRS_GPS_DW.Delay12_DSTATE[Rotation_AHRS_GPS_B.i] =
      Rotation_AHRS_GPS_B.u[Rotation_AHRS_GPS_B.i];
    Rotation_AHRS_GPS_DW.Delay_DSTATE[Rotation_AHRS_GPS_B.i] =
      Rotation_AHRS_GPS_B.Switch_c[Rotation_AHRS_GPS_B.i];
  }

  Rotation_AHRS_GPS_DW.DiscreteFIRFilter1_circBuf--;
  if (Rotation_AHRS_GPS_DW.DiscreteFIRFilter1_circBuf < 0) {
    Rotation_AHRS_GPS_DW.DiscreteFIRFilter1_circBuf = 3;
  }

  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_IC_LOA_d = 0U;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_gs +=
    (Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_pd -
     Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_g5) *
    Rotation_AHRS_GPS_P_g.Gain_Gain_mn *
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_gainva_m;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_IC_LOA_h = 0U;
  Rotation_AHRS_GPS_DW.DiscreteFIRFilter1_states[Rotation_AHRS_GPS_DW.DiscreteFIRFilter1_circBuf]
    = rtu_Sensor_data_h_R_B[0];
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_oe[0] +=
    (Rotation_AHRS_GPS_B.acc_body[0] -
     Rotation_AHRS_GPS_B.rtb_DiscreteTimeIntegrator_l4_i) *
    Rotation_AHRS_GPS_P_g.Gain_Gain_it *
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_gainva_l;
  Rotation_AHRS_GPS_DW.DiscreteFIRFilter1_states[Rotation_AHRS_GPS_DW.DiscreteFIRFilter1_circBuf
    + 4] = rtu_Sensor_data_h_R_B[1];
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_oe[1] +=
    (Rotation_AHRS_GPS_B.acc_body[1] -
     Rotation_AHRS_GPS_B.rtb_DiscreteTimeIntegrator_l4_l) *
    Rotation_AHRS_GPS_P_g.Gain_Gain_it *
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_gainva_l;
  Rotation_AHRS_GPS_DW.DiscreteFIRFilter1_states[Rotation_AHRS_GPS_DW.DiscreteFIRFilter1_circBuf
    + 8] = rtu_Sensor_data_h_R_B[2];
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_oe[2] +=
    (Rotation_AHRS_GPS_B.acc_body[2] -
     Rotation_AHRS_GPS_B.rtb_DiscreteTimeIntegrator_l4_j) *
    Rotation_AHRS_GPS_P_g.Gain_Gain_it *
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_gainva_l;
  Rotation_AHRS_GPS_DW.Memory2_PreviousInput = (Rotation_AHRS_GPS_B.Compare_nc ||
    Rotation_AHRS_GPS_B.Memory2);
  Rotation_AHRS_GPS_DW.DelayInput1_DSTATE_b = Rotation_AHRS_GPS_B.Compare_m;
  Rotation_AHRS_GPS_DW.DiscreteFIRFilter_circBuf--;
  if (Rotation_AHRS_GPS_DW.DiscreteFIRFilter_circBuf < 0) {
    Rotation_AHRS_GPS_DW.DiscreteFIRFilter_circBuf = 3;
  }

  Rotation_AHRS_GPS_DW.DiscreteFIRFilter_states[Rotation_AHRS_GPS_DW.DiscreteFIRFilter_circBuf]
    = Rotation_AHRS_GPS_B.acc_body[0];
  Rotation_AHRS_GPS_DW.DiscreteFIRFilter_states[Rotation_AHRS_GPS_DW.DiscreteFIRFilter_circBuf
    + 4] = Rotation_AHRS_GPS_B.acc_body[1];
  Rotation_AHRS_GPS_DW.DiscreteFIRFilter_states[Rotation_AHRS_GPS_DW.DiscreteFIRFilter_circBuf
    + 8] = Rotation_AHRS_GPS_B.acc_body[2];
  Rotation_AHRS_GPS_DW.DelayInput1_DSTATE_h = Rotation_AHRS_GPS_B.Compare_if;
  Rotation_AHRS_GPS_DW.Delay_DSTATE_c = ((int32_T)((uint32_T)
    Rotation_AHRS_GPS_B.FixPtRelationalOperator_m +
    Rotation_AHRS_GPS_B.LogicalOperator_f) != 0);
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE_m +=
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_gainva_j *
    Rotation_AHRS_GPS_P_g.Constant_Value_cu;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_PrevRe_f = (int8_T)
    Rotation_AHRS_GPS_B.FixPtRelationalOperator_m;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE_b += (real32_T)
    ((*rtu_Sensor_data_IMU_valid) && (*rtu_Sensor_data_Mag_Quality >=
      Rotation_AHRS_GPS_P_g.CompareToConstant2_const_h)) *
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_gainv_fl;
  Rotation_AHRS_GPS_DW.DelayInput1_DSTATE_ft = Rotation_AHRS_GPS_B.Compare_ep;
  Rotation_AHRS_GPS_DW.Delay_DSTATE_e = *rty_once_stand_still;
  Rotation_AHRS_GPS_DW.DelayInput1_DSTATE_n = *rty_once_stand_still;
  Rotation_AHRS_GPS_DW.icLoad_b = 0U;
  Rotation_AHRS_GPS_DW.icLoad_m = 0U;
  for (Rotation_AHRS_GPS_B.i = 0; Rotation_AHRS_GPS_B.i < 7;
       Rotation_AHRS_GPS_B.i++) {
    Rotation_AHRS_GPS_DW.Delay2_DSTATE[Rotation_AHRS_GPS_B.i] =
      Rotation_AHRS_GPS_B.u[Rotation_AHRS_GPS_B.i];
    Rotation_AHRS_GPS_DW.Delay1_DSTATE[Rotation_AHRS_GPS_B.i] =
      Rotation_AHRS_GPS_B.TmpSignalConversionAtDelayI[Rotation_AHRS_GPS_B.i];
    Rotation_AHRS_GPS_DW.Delay_DSTATE_n[Rotation_AHRS_GPS_B.i] =
      Rotation_AHRS_GPS_B.TmpSignalConversionAtDelayI[Rotation_AHRS_GPS_B.i];
  }

  Rotation_AHRS_GPS_DW.DelayInput1_DSTATE_a =
    Rotation_AHRS_GPS_B.DataTypeConversion1_j;
  Rotation_AHRS_GPS_DW.DelayInput1_DSTATE_d =
    Rotation_AHRS_GPS_B.DataTypeConversion1_ba;
  Rotation_AHRS_GPS_DW.DelayInput1_DSTATE_bg =
    Rotation_AHRS_GPS_B.LogicalOperator1_i;
  Rotation_AHRS_GPS_DW.Delay_DSTATE_n1 = *rty_reset_yaw_flag;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_ab +=
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_gainv_me *
    Rotation_AHRS_GPS_P_g.Constant_Value_nk;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_PrevRe_d = (int8_T)
    Rotation_AHRS_GPS_B.LogicalOperator_h;
  for (Rotation_AHRS_GPS_B.i = 0; Rotation_AHRS_GPS_B.i < 4;
       Rotation_AHRS_GPS_B.i++) {
    Rotation_AHRS_GPS_B.j = (Rotation_AHRS_GPS_B.i + 1) * 3;
    Rotation_AHRS_GPS_DW.Delay1_DSTATE_o[Rotation_AHRS_GPS_B.i * 3] =
      Rotation_AHRS_GPS_DW.Delay1_DSTATE_o[Rotation_AHRS_GPS_B.j];
    Rotation_AHRS_GPS_DW.Delay1_DSTATE_o[Rotation_AHRS_GPS_B.i * 3 + 1] =
      Rotation_AHRS_GPS_DW.Delay1_DSTATE_o[Rotation_AHRS_GPS_B.j + 1];
    Rotation_AHRS_GPS_DW.Delay1_DSTATE_o[Rotation_AHRS_GPS_B.i * 3 + 2] =
      Rotation_AHRS_GPS_DW.Delay1_DSTATE_o[Rotation_AHRS_GPS_B.j + 2];
  }

  Rotation_AHRS_GPS_DW.Delay1_DSTATE_o[12] = rtu_Sensor_data_rot_IB_B_raw_ra[0];
  Rotation_AHRS_GPS_DW.Delay1_DSTATE_o[13] = rtu_Sensor_data_rot_IB_B_raw_ra[1];
  Rotation_AHRS_GPS_DW.Delay1_DSTATE_o[14] = rtu_Sensor_data_rot_IB_B_raw_ra[2];
  for (Rotation_AHRS_GPS_B.i = 0; Rotation_AHRS_GPS_B.i < 24;
       Rotation_AHRS_GPS_B.i++) {
    Rotation_AHRS_GPS_DW.Delay3_DSTATE[Rotation_AHRS_GPS_B.i * 3] =
      Rotation_AHRS_GPS_DW.Delay3_DSTATE[(Rotation_AHRS_GPS_B.i + 1) * 3];
    Rotation_AHRS_GPS_DW.Delay3_DSTATE[Rotation_AHRS_GPS_B.i * 3 + 1] =
      Rotation_AHRS_GPS_DW.Delay3_DSTATE[(Rotation_AHRS_GPS_B.i + 1) * 3 + 1];
    Rotation_AHRS_GPS_DW.Delay3_DSTATE[Rotation_AHRS_GPS_B.i * 3 + 2] =
      Rotation_AHRS_GPS_DW.Delay3_DSTATE[(Rotation_AHRS_GPS_B.i + 1) * 3 + 2];
  }

  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_IC_LOA_c = 0U;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_IC_LO_by = 0U;
  Rotation_AHRS_GPS_DW.Delay3_DSTATE[72] =
    Rotation_AHRS_GPS_B.DiscreteFIRFilter[0];
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_DSTAT_o[0] +=
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator1_gainv_j *
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_b3[0];
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE_k[0] +=
    Rotation_AHRS_GPS_P_g.Gain3_Gain_a *
    Rotation_AHRS_GPS_B.rtb_VectorConcatenate1_idx_0 *
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_gainva_b;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE_n[0] +=
    Rotation_AHRS_GPS_P_g.Gain3_Gain_oz * Rotation_AHRS_GPS_B.omg_O[0] *
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_gainva_o;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE_c[0] +=
    (Rotation_AHRS_GPS_B.rtb_Divide_idx_0 -
     Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE_c[0]) *
    Rotation_AHRS_GPS_B.atan1 *
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_gainva_h;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE_l[0] +=
    Rotation_AHRS_GPS_P_g.Gain_Gain_kl * Rotation_AHRS_GPS_B.rtb_Sum_b_idx_0 *
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_gainv_li;
  Rotation_AHRS_GPS_DW.Delay3_DSTATE[73] =
    Rotation_AHRS_GPS_B.DiscreteFIRFilter[1];
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_DSTAT_o[1] +=
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator1_gainv_j *
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_b3[1];
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE_k[1] +=
    Rotation_AHRS_GPS_P_g.Gain3_Gain_a *
    Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_h *
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_gainva_b;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE_n[1] +=
    Rotation_AHRS_GPS_P_g.Gain3_Gain_oz * Rotation_AHRS_GPS_B.omg_O[1] *
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_gainva_o;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE_c[1] +=
    (Rotation_AHRS_GPS_B.rtb_Divide_idx_1 -
     Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE_c[1]) *
    Rotation_AHRS_GPS_B.atan1 *
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_gainva_h;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE_l[1] +=
    Rotation_AHRS_GPS_P_g.Gain_Gain_kl * Rotation_AHRS_GPS_B.rtb_Sum_b_idx_1 *
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_gainv_li;
  Rotation_AHRS_GPS_DW.Delay3_DSTATE[74] =
    Rotation_AHRS_GPS_B.DiscreteFIRFilter[2];
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_DSTAT_o[2] +=
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator1_gainv_j *
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_b3[2];
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE_k[2] +=
    Rotation_AHRS_GPS_P_g.Gain3_Gain_a *
    Rotation_AHRS_GPS_B.rtb_VectorConcatenate1_b *
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_gainva_b;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE_n[2] +=
    Rotation_AHRS_GPS_P_g.Gain3_Gain_oz * Rotation_AHRS_GPS_B.omg_O[2] *
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_gainva_o;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE_c[2] +=
    (Rotation_AHRS_GPS_B.rtb_Divide_idx_2 -
     Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE_c[2]) *
    Rotation_AHRS_GPS_B.atan1 *
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_gainva_h;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE_l[2] +=
    Rotation_AHRS_GPS_P_g.Gain_Gain_kl * Rotation_AHRS_GPS_B.rtb_Sum_b_idx_2 *
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_gainv_li;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_IC_LO_n = 0U;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_DSTAT_j +=
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator1_gain_jp *
    Rotation_AHRS_GPS_B.Product_hu;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_if +=
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_gainv_pf *
    Rotation_AHRS_GPS_B.DataTypeConversion_p;
  if (Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_if >=
      Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_UpperS_n) {
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_if =
      Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_UpperS_n;
  } else {
    if (Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_if <=
        Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_LowerS_k) {
      Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_if =
        Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_LowerS_k;
    }
  }

  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_PrevRe_k = (int8_T)
    Rotation_AHRS_GPS_B.Compare_go;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_cq +=
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_gainva_i *
    Rotation_AHRS_GPS_P_g.Constant_Value_i4;
  Rotation_AHRS_GPS_DW.Delay_DSTATE_by = *rty_rp_init_done;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_IC_LOA_g = 0U;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE_p +=
    (Rotation_AHRS_GPS_B.rtb_MatrixMultiply2_p_tmp[2] -
     Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE_p) *
    Rotation_AHRS_GPS_P_g.Gain_Gain_pg *
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_gainv_of;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_IC_LOA_k = 0U;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_o1 +=
    (Rotation_AHRS_GPS_B.rtb_MatrixMultiply2_p_tmp[0] -
     Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_o1) *
    Rotation_AHRS_GPS_P_g.Gain_Gain_ml *
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_gainv_hk;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_IC_LOA_i = 0U;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_og +=
    (Rotation_AHRS_GPS_B.rtb_MatrixMultiply2_p_tmp[1] -
     Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_og) *
    Rotation_AHRS_GPS_P_g.Gain_Gain_fx *
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_gainva_g;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_IC_LO_gv = 0U;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_ka +=
    (Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_gg -
     Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_ka) *
    Rotation_AHRS_GPS_P_g.Gain_Gain_ka *
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_gainv_mh;
  Rotation_AHRS_GPS_DW.Delay_DSTATE_i[0] = Rotation_AHRS_GPS_B.Subtract_m[0];
  Rotation_AHRS_GPS_B.rtb_DiscreteTimeIntegrator_fl_i =
    Rotation_AHRS_GPS_P_g.Gain_Gain_ay[0] *
    Rotation_AHRS_GPS_B.rtb_Multiply1_idx_0;
  Rotation_AHRS_GPS_DW.Delay_DSTATE_i[1] = Rotation_AHRS_GPS_B.Subtract_m[1];
  Rotation_AHRS_GPS_B.rtb_DiscreteTimeIntegrator_fl_g =
    Rotation_AHRS_GPS_P_g.Gain_Gain_ay[1] *
    Rotation_AHRS_GPS_B.rtb_Multiply1_idx_1;
  Rotation_AHRS_GPS_DW.Delay_DSTATE_i[2] = Rotation_AHRS_GPS_B.Subtract_m[2];
  Rotation_AHRS_GPS_B.rtb_DiscreteTimeIntegrator_fr_i =
    Rotation_AHRS_GPS_P_g.Gain_Gain_ay[2] *
    Rotation_AHRS_GPS_B.rtb_Multiply1_idx_2;
  for (Rotation_AHRS_GPS_B.i = 0; Rotation_AHRS_GPS_B.i < 3;
       Rotation_AHRS_GPS_B.i++) {
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_it[Rotation_AHRS_GPS_B.i] +=
      Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_gainv_bl *
      (Rotation_AHRS_GPS_B.VectorConcatenate_p[Rotation_AHRS_GPS_B.i + 6] *
       Rotation_AHRS_GPS_B.rtb_DiscreteTimeIntegrator_fr_i +
       (Rotation_AHRS_GPS_B.VectorConcatenate_p[Rotation_AHRS_GPS_B.i + 3] *
        Rotation_AHRS_GPS_B.rtb_DiscreteTimeIntegrator_fl_g +
        Rotation_AHRS_GPS_B.VectorConcatenate_p[Rotation_AHRS_GPS_B.i] *
        Rotation_AHRS_GPS_B.rtb_DiscreteTimeIntegrator_fl_i));
    if (Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_it[Rotation_AHRS_GPS_B.i]
        >= Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_UpperS_m) {
      Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_it[Rotation_AHRS_GPS_B.i]
        = Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_UpperS_m;
    } else {
      if (Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_it[Rotation_AHRS_GPS_B.i]
          <= Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_LowerS_m) {
        Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_it[Rotation_AHRS_GPS_B.i]
          = Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_LowerS_m;
      }
    }
  }

  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_PrevRe_j = (int8_T)
    *rtu_stand_still_for_four_second;
  for (Rotation_AHRS_GPS_B.i = 0; Rotation_AHRS_GPS_B.i < 99;
       Rotation_AHRS_GPS_B.i++) {
    Rotation_AHRS_GPS_DW.Delay_DSTATE_f[Rotation_AHRS_GPS_B.i] =
      Rotation_AHRS_GPS_DW.Delay_DSTATE_f[Rotation_AHRS_GPS_B.i + 1];
  }

  Rotation_AHRS_GPS_DW.Delay_DSTATE_f[99] = Rotation_AHRS_GPS_B.rtb_Sum_jx_idx_0;
  Rotation_AHRS_GPS_DW.DelayInput1_DSTATE = *rtu_Sensor_data_GPS_data_Timest;
  for (Rotation_AHRS_GPS_B.i = 0; Rotation_AHRS_GPS_B.i < 101;
       Rotation_AHRS_GPS_B.i++) {
    Rotation_AHRS_GPS_DW.Delay_DSTATE_ez[Rotation_AHRS_GPS_B.i] =
      Rotation_AHRS_GPS_DW.Delay_DSTATE_ez[Rotation_AHRS_GPS_B.i + 1];
  }

  Rotation_AHRS_GPS_DW.Delay_DSTATE_ez[101] = (((int32_T)
    Rotation_AHRS_GPS_B.DataTypeConversion1_ba > (int32_T)
    Rotation_AHRS_GPS_DW.DelayInput1_DSTATE_dq) || ((int32_T)
    Rotation_AHRS_GPS_B.DataTypeConversion1_j > (int32_T)
    Rotation_AHRS_GPS_DW.DelayInput1_DSTATE_hh));
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_IC_LO_c = 0U;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_DSTAT_p[0] +=
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator1_gainv_g *
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_l3[0];
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_DSTAT_f[0] +=
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator1_gainv_e *
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_a1[0];
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_DSTAT_p[1] +=
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator1_gainv_g *
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_l3[1];
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_DSTAT_f[1] +=
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator1_gainv_e *
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_a1[1];
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_PrevR_l = (int8_T)
    Rotation_AHRS_GPS_B.Delay_p;
  Rotation_AHRS_GPS_DW.DiscreteFIRFilter_circBuf_d--;
  if (Rotation_AHRS_GPS_DW.DiscreteFIRFilter_circBuf_d < 0) {
    Rotation_AHRS_GPS_DW.DiscreteFIRFilter_circBuf_d = 28;
  }

  Rotation_AHRS_GPS_DW.DiscreteFIRFilter_states_e[Rotation_AHRS_GPS_DW.DiscreteFIRFilter_circBuf_d]
    = Rotation_AHRS_GPS_B.Saturation;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_IC_LO_bw = 0U;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_g4 +=
    (Rotation_AHRS_GPS_B.Product_dn -
     Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_g4) *
    Rotation_AHRS_GPS_P_g.Gain_Gain_jr *
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_gainva_a;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_IC_LOA_o = 0U;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE_j +=
    (Rotation_AHRS_GPS_B.Product2_n2 -
     Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE_j) *
    Rotation_AHRS_GPS_P_g.Gain_Gain_oc *
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_gainv_o5;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_jn +=
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_gainva_n *
    Rotation_AHRS_GPS_P_g.Constant2_Value_f;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTA_ifx +=
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_gainv_oe * (real32_T)
    Rotation_AHRS_GPS_B.need_to_compensate;
  if (Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTA_ifx >=
      Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_UpperS_a) {
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTA_ifx =
      Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_UpperS_a;
  } else {
    if (Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTA_ifx <=
        Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_LowerS_b) {
      Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTA_ifx =
        Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_LowerS_b;
    }
  }

  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_PrevRe_n = (int8_T)
    Rotation_AHRS_GPS_B.LogicalOperator1_c;
  Rotation_AHRS_GPS_DW.DelayInput1_DSTATE_o = Rotation_AHRS_GPS_B.Compare_bk;
  Rotation_AHRS_GPS_DW.Delay4_DSTATE_j = Rotation_AHRS_GPS_B.Uk1;
  Rotation_AHRS_GPS_DW.DelayInput1_DSTATE_fa = Rotation_AHRS_GPS_B.Delay4_e;
  Rotation_AHRS_GPS_DW.DelayInput1_DSTATE_oe = *rty_stand_still;
  Rotation_AHRS_GPS_DW.Delay_DSTATE_na = (Rotation_AHRS_GPS_P_g.Gain8_Gain *
    (real32_T)fabs(Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_di) <=
    Rotation_AHRS_GPS_P_g.CompareToConstant2_const_eg);
  Rotation_AHRS_GPS_DW.DelayInput1_DSTATE_pc = Rotation_AHRS_GPS_B.Delay_m;
  Rotation_AHRS_GPS_DW.Delay_DSTATE_kq =
    Rotation_AHRS_GPS_B.DataTypeConversion1_e;
  Rotation_AHRS_GPS_DW.DelayInput1_DSTATE_nh =
    Rotation_AHRS_GPS_B.DataTypeConversion1_e;
  Rotation_AHRS_GPS_DW.DelayInput1_DSTATE_f = Rotation_AHRS_GPS_B.relay;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_IC_LO_b = 0U;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_DSTAT_b +=
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator1_gainv_f *
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_ol;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_PrevR_g = (int8_T)
    Rotation_AHRS_GPS_B.DataTypeConversion1_ba;
  Rotation_AHRS_GPS_DW.icLoad_d = 0U;
  Rotation_AHRS_GPS_DW.icLoad_f = 0U;
  if (Rotation_AHRS_GPS_B.Compare_on) {
    Rotation_AHRS_GPS_DW.Delay_DSTATE_b = 0.0F;
  } else {
    Rotation_AHRS_GPS_DW.Delay_DSTATE_b = Rotation_AHRS_GPS_DW.Delay_DSTATE_ih;
  }

  Rotation_AHRS_GPS_DW.icLoad_hh = 0U;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_IC_LOA_j = 0U;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_m0 +=
    (Rotation_AHRS_GPS_B.Product1_h1 -
     Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_m0) *
    Rotation_AHRS_GPS_P_g.Gain_Gain_hd *
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_gainv_pz;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_IC_LO_h = 0U;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_DSTAT_d +=
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator1_gainv_p *
    Rotation_AHRS_GPS_B.det_yaw_mag_c;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_on +=
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_gainv_oq * (real32_T)
    Rotation_AHRS_GPS_B.Compare_huc;
  if (Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_on >=
      Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_UpperS_f) {
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_on =
      Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_UpperS_f;
  } else {
    if (Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_on <=
        Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_LowerS_h) {
      Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_on =
        Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_LowerS_h;
    }
  }

  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_PrevR_fh = (int8_T)
    Rotation_AHRS_GPS_B.LogicalOperator6_d;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_c0 +=
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_gainva_d *
    Rotation_AHRS_GPS_P_g.Constant_Value_dc;
  Rotation_AHRS_GPS_DW.Delay_DSTATE_iz = ((int32_T)((uint32_T)
    Rotation_AHRS_GPS_B.LogicalOperator_a + Rotation_AHRS_GPS_DW.Delay_DSTATE_iz)
    != 0);
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_IC_LO_jh = 0U;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_na +=
    (Rotation_AHRS_GPS_B.Product3_jr - *rty_Rotation_data_Heading_Quali) *
    Rotation_AHRS_GPS_P_g.Gain_Gain_n5 *
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_gainv_ft;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_IC_L_nd = 0U;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_DSTA_fu +=
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator1_gainv_l *
    Rotation_AHRS_GPS_B.DataTypeConversion;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_IC_LOA_m = 0U;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_jy +=
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_gainva_c *
    Rotation_AHRS_GPS_B.Sum_e_k;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_IC_LO_i4 = 0U;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_g0 +=
    (Rotation_AHRS_GPS_B.Sum_e_k -
     Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_g0) *
    Rotation_AHRS_GPS_P_g.Gain_Gain_cj *
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_gainv_ps;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_IC_LO_m = 0U;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_DSTA_ft +=
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator1_gain_ew *
    Rotation_AHRS_GPS_B.Product2_eb;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_IC_LO_jz = 0U;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE_e +=
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_gainva_e *
    Rotation_AHRS_GPS_B.Sum_d2e;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_IC_LO_b4 = 0U;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_ep +=
    (Rotation_AHRS_GPS_B.Sum_d2e -
     Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_ep) *
    Rotation_AHRS_GPS_P_g.Gain_Gain_gy *
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_gainv_he;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_IC_LO_g = 0U;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_DSTA_pn +=
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator1_gainv_h *
    Rotation_AHRS_GPS_B.Gain_n;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_DSTAT_i[0] +=
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator1_gain_pw *
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTA_og2[0];
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_DSTAT_i[1] +=
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator1_gain_pw *
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTA_og2[1];
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_DSTAT_i[2] +=
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator1_gain_pw *
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTA_og2[2];
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_DSTAT_l +=
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator1_gain_lj *
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_cz;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_IC_LO_k = 0U;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_DSTA_cp +=
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator1_gain_pm *
    Rotation_AHRS_GPS_B.Product2_jx;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_IC_LOA_n = 0U;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE_d[0] +=
    (Rotation_AHRS_GPS_B.Delay_h[0] -
     Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE_d[0]) *
    Rotation_AHRS_GPS_P_g.Gain_Gain_jv *
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_gainv_d3;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE_d[1] +=
    (Rotation_AHRS_GPS_B.Delay_h[1] -
     Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE_d[1]) *
    Rotation_AHRS_GPS_P_g.Gain_Gain_jv *
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_gainv_d3;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_IC_L_bf = 0U;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_DSTA_ii +=
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator1_gainv_n *
    Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_if;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_PrevR_aq = (int8_T)
    *rtu_stand_still_for_four_second;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_lk[0] +=
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_gainv_kb *
    Rotation_AHRS_GPS_B.Product_e[0];
  if (Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_lk[0] >=
      Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_UpperS_e) {
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_lk[0] =
      Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_UpperS_e;
  } else {
    if (Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_lk[0] <=
        Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_Lower_hp) {
      Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_lk[0] =
        Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_Lower_hp;
    }
  }

  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_b3[0] +=
    ((Rotation_AHRS_GPS_B.acc_body[0] - Rotation_AHRS_GPS_B.DiscreteFIRFilter1[0])
     * Rotation_AHRS_GPS_P_g.Gain_Gain_ca1 + Rotation_AHRS_GPS_P_g.Gain1_Gain_fg
     * Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_b3[0]) *
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_gainv_id;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_DSTA_pc[0] +=
    (Rotation_AHRS_GPS_P_g.Gain2_Gain_m *
     Rotation_AHRS_GPS_B.rtb_VectorConcatenate1_idx_0 +
     Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_c[0]) *
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator1_gain_el;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_DSTAT_g[0] +=
    (Rotation_AHRS_GPS_P_g.Gain2_Gain_o * Rotation_AHRS_GPS_B.omg_O[0] +
     Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_a[0]) *
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator1_gain_p5;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_lk[1] +=
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_gainv_kb *
    Rotation_AHRS_GPS_B.Product_e[1];
  if (Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_lk[1] >=
      Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_UpperS_e) {
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_lk[1] =
      Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_UpperS_e;
  } else {
    if (Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_lk[1] <=
        Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_Lower_hp) {
      Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_lk[1] =
        Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_Lower_hp;
    }
  }

  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_b3[1] +=
    ((Rotation_AHRS_GPS_B.acc_body[1] - Rotation_AHRS_GPS_B.DiscreteFIRFilter1[1])
     * Rotation_AHRS_GPS_P_g.Gain_Gain_ca1 + Rotation_AHRS_GPS_P_g.Gain1_Gain_fg
     * Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_b3[1]) *
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_gainv_id;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_DSTA_pc[1] +=
    (Rotation_AHRS_GPS_P_g.Gain2_Gain_m *
     Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_h +
     Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_c[1]) *
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator1_gain_el;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_DSTAT_g[1] +=
    (Rotation_AHRS_GPS_P_g.Gain2_Gain_o * Rotation_AHRS_GPS_B.omg_O[1] +
     Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_a[1]) *
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator1_gain_p5;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_lk[2] +=
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_gainv_kb *
    Rotation_AHRS_GPS_B.rtb_Product_e_c;
  if (Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_lk[2] >=
      Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_UpperS_e) {
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_lk[2] =
      Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_UpperS_e;
  } else {
    if (Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_lk[2] <=
        Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_Lower_hp) {
      Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_lk[2] =
        Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_Lower_hp;
    }
  }

  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_b3[2] +=
    ((Rotation_AHRS_GPS_B.acc_body[2] - Rotation_AHRS_GPS_B.DiscreteFIRFilter1[2])
     * Rotation_AHRS_GPS_P_g.Gain_Gain_ca1 + Rotation_AHRS_GPS_P_g.Gain1_Gain_fg
     * Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_b3[2]) *
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_gainv_id;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_DSTA_pc[2] +=
    (Rotation_AHRS_GPS_P_g.Gain2_Gain_m *
     Rotation_AHRS_GPS_B.rtb_VectorConcatenate1_b +
     Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_c[2]) *
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator1_gain_el;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_DSTAT_g[2] +=
    (Rotation_AHRS_GPS_P_g.Gain2_Gain_o * Rotation_AHRS_GPS_B.omg_O[2] +
     Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_a[2]) *
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator1_gain_p5;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_PrevRe_h = (int8_T)
    Rotation_AHRS_GPS_B.Delay_p;
  Rotation_AHRS_GPS_DW.DelayInput1_DSTATE_dq =
    Rotation_AHRS_GPS_B.DataTypeConversion1_ba;
  Rotation_AHRS_GPS_DW.DelayInput1_DSTATE_hh =
    Rotation_AHRS_GPS_B.DataTypeConversion1_j;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_a1[0] +=
    ((Rotation_AHRS_GPS_B.MatrixMultiply_m[0] -
      Rotation_AHRS_GPS_B.rtb_DiscreteTimeIntegrator1_i_i) *
     Rotation_AHRS_GPS_P_g.Gain_Gain_oe + Rotation_AHRS_GPS_P_g.Gain1_Gain_h *
     Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_a1[0]) *
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_gainv_fg;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_l3[0] +=
    ((Rotation_AHRS_GPS_B.rtb_acc_GPS_est_idx_0 -
      Rotation_AHRS_GPS_B.rtb_DiscreteTimeIntegrator1_idx) *
     Rotation_AHRS_GPS_P_g.Gain_Gain_eb + Rotation_AHRS_GPS_P_g.Gain1_Gain_nz *
     Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_l3[0]) *
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_gainv_ne;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_a1[1] +=
    ((Rotation_AHRS_GPS_B.MatrixMultiply_m[1] -
      Rotation_AHRS_GPS_B.rtb_DiscreteTimeIntegrator1_i_f) *
     Rotation_AHRS_GPS_P_g.Gain_Gain_oe + Rotation_AHRS_GPS_P_g.Gain1_Gain_h *
     Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_a1[1]) *
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_gainv_fg;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_l3[1] +=
    ((Rotation_AHRS_GPS_B.rtb_acc_GPS_est_idx_1 -
      Rotation_AHRS_GPS_B.rtb_DiscreteTimeIntegrator1_i_g) *
     Rotation_AHRS_GPS_P_g.Gain_Gain_eb + Rotation_AHRS_GPS_P_g.Gain1_Gain_nz *
     Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_l3[1]) *
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_gainv_ne;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_aj +=
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_gainv_cp *
    Rotation_AHRS_GPS_B.Abs_o;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_PrevR_nh = (int8_T)
    Rotation_AHRS_GPS_B.Compare_c;
  Rotation_AHRS_GPS_DW.DelayInput1_DSTATE_bh = rtb_large_error_detected;
  Rotation_AHRS_GPS_DW.DelayInput1_DSTATE_ip = Rotation_AHRS_GPS_B.mag_reset2;
  Rotation_AHRS_GPS_DW.Delay_DSTATE_d = ((int32_T)((uint32_T)
    (Rotation_AHRS_GPS_DW.Delay_DSTATE_d &&
     (!(Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE_h >=
        Rotation_AHRS_GPS_P_g.CompareTo1sec_const_o))) +
    Rotation_AHRS_GPS_B.FixPtRelationalOperator_ke) != 0);
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE_h +=
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_gainv_m3 *
    Rotation_AHRS_GPS_P_g.Constant_Value_jg;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_PrevRe_e = (int8_T)
    Rotation_AHRS_GPS_B.FixPtRelationalOperator_ke;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTA_lk2 +=
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_gainv_hn * (real32_T)
    Rotation_AHRS_GPS_B.Compare_c2;
  if (Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTA_lk2 >=
      Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_Upper_a0) {
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTA_lk2 =
      Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_Upper_a0;
  } else {
    if (Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTA_lk2 <=
        Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_LowerS_c) {
      Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTA_lk2 =
        Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_LowerS_c;
    }
  }

  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_PrevR_dh = (int8_T)
    Rotation_AHRS_GPS_B.LogicalOperator1_hy;
  Rotation_AHRS_GPS_DW.Delay_DSTATE_e1 = rtb_DataTypeConversion1_h;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_m4 +=
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_gainv_il *
    Rotation_AHRS_GPS_B.fcn5;
  if (Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_m4 >=
      Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_UpperS_h) {
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_m4 =
      Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_UpperS_h;
  } else {
    if (Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_m4 <=
        Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_Lower_mq) {
      Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_m4 =
        Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_Lower_mq;
    }
  }

  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_PrevR_du = (int8_T)
    rtb_LogicalOperator1_d;
  Rotation_AHRS_GPS_DW.DelayInput1_DSTATE_m = Rotation_AHRS_GPS_B.enable;
  Rotation_AHRS_GPS_DW.Delay_DSTATE_ig = rtb_DataTypeConversion1_n5;
  Rotation_AHRS_GPS_DW.DelayInput1_DSTATE_aq = rtb_DataTypeConversion1_n5;
  Rotation_AHRS_GPS_DW.Delay_DSTATE_o = ((int32_T)((uint32_T)
    (Rotation_AHRS_GPS_DW.Delay_DSTATE_o &&
     (!(Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_gr >=
        Rotation_AHRS_GPS_P_g.CompareTo1sec_const_p))) +
    rtb_FixPtRelationalOperator_pi) != 0);
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_gr +=
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_gainv_jv *
    Rotation_AHRS_GPS_P_g.Constant_Value_p2;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_PrevRe_c = (int8_T)
    rtb_FixPtRelationalOperator_pi;
  Rotation_AHRS_GPS_DW.DelayInput1_DSTATE_c =
    Rotation_AHRS_GPS_B.DataTypeConversion1_ba;
  Rotation_AHRS_GPS_DW.DelayInput1_DSTATE_ne =
    Rotation_AHRS_GPS_B.DataTypeConversion1_j;
  Rotation_AHRS_GPS_DW.DelayInput1_DSTATE_j = Rotation_AHRS_GPS_B.Compare_g4;
  Rotation_AHRS_GPS_DW.Delay_DSTATE_gd = ((int32_T)((uint32_T)
    (Rotation_AHRS_GPS_DW.Delay_DSTATE_gd &&
     (!(Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_bu >=
        Rotation_AHRS_GPS_P_g.CompareTo1sec_const_d))) +
    rtb_FixPtRelationalOperator_jv) != 0);
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_bu +=
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_gainv_fi *
    Rotation_AHRS_GPS_P_g.Constant_Value_jf;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_PrevR_je = (int8_T)
    rtb_FixPtRelationalOperator_jv;
  Rotation_AHRS_GPS_DW.Delay_DSTATE_ef = ((int32_T)((uint32_T)
    (Rotation_AHRS_GPS_DW.Delay_DSTATE_ef &&
     (!(Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_cf >=
        Rotation_AHRS_GPS_P_g.CompareTo1sec_const_j))) +
    rtb_FixPtRelationalOperator_es) != 0);
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_cf +=
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_gainv_kj *
    Rotation_AHRS_GPS_P_g.Constant_Value_b3;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_PrevRe_m = (int8_T)
    rtb_FixPtRelationalOperator_es;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_IC_LO_gi = 0U;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_ez +=
    (Rotation_AHRS_GPS_B.CaliYawMAG[2] -
     Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_ez) *
    Rotation_AHRS_GPS_P_g.Gain_Gain_f5p *
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_gainv_gl;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_IC_LO_hx = 0U;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_di +=
    (Rotation_AHRS_GPS_B.CaliYawMAG[2] -
     Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_di) *
    Rotation_AHRS_GPS_P_g.Gain_Gain_br *
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_gainv_a4;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_cz +=
    ((Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_oa -
      Rotation_AHRS_GPS_B.DiscreteTimeIntegrator1_m) *
     Rotation_AHRS_GPS_P_g.Gain_Gain_nw + Rotation_AHRS_GPS_P_g.Gain1_Gain_m *
     Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_cz) *
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_gain_hkc;
  Rotation_AHRS_GPS_DW.UD_DSTATE = Rotation_AHRS_GPS_B.rtb_Sum_jx_idx_1;
  for (Rotation_AHRS_GPS_B.i = 0; Rotation_AHRS_GPS_B.i < 3;
       Rotation_AHRS_GPS_B.i++) {
    Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTA_og2[Rotation_AHRS_GPS_B.i] +=
      ((((Rotation_AHRS_GPS_B.VectorConcatenate_i[Rotation_AHRS_GPS_B.i + 3] *
          rtu_Sensor_data_rot_IB_B_raw_ra[1] +
          Rotation_AHRS_GPS_B.VectorConcatenate_i[Rotation_AHRS_GPS_B.i] *
          rtu_Sensor_data_rot_IB_B_raw_ra[0]) +
         Rotation_AHRS_GPS_B.VectorConcatenate_i[Rotation_AHRS_GPS_B.i + 6] *
         rtu_Sensor_data_rot_IB_B_raw_ra[2]) -
        Rotation_AHRS_GPS_B.DiscreteTimeIntegrator1_e[Rotation_AHRS_GPS_B.i]) *
       Rotation_AHRS_GPS_P_g.Gain_Gain_jy + Rotation_AHRS_GPS_P_g.Gain1_Gain_nv *
       Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTA_og2[Rotation_AHRS_GPS_B.i])
      * Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_gainv_a0;
  }

  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_ol +=
    ((Rotation_AHRS_GPS_B.Product3_k - Rotation_AHRS_GPS_B.Product_ge) *
     Rotation_AHRS_GPS_P_g.Gain_Gain_ks + Rotation_AHRS_GPS_P_g.Gain1_Gain_ny *
     Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_ol) *
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_gainv_f3;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_PrevRe_o = (int8_T)
    Rotation_AHRS_GPS_B.DataTypeConversion1_ba;
  Rotation_AHRS_GPS_DW.DelayInput1_DSTATE_fq =
    Rotation_AHRS_GPS_B.LogicalOperator2_p;
  Rotation_AHRS_GPS_DW.icLoad_o = 0U;
  Rotation_AHRS_GPS_DW.Delay7_DSTATE = Rotation_AHRS_GPS_B.mag_reset2;
  Rotation_AHRS_GPS_DW.Delay5_DSTATE = Rotation_AHRS_GPS_B.Divide1_i +
    Rotation_AHRS_GPS_B.TrigonometricFunction;
  Rotation_AHRS_GPS_DW.icLoad_i = 0U;
  Rotation_AHRS_GPS_DW.Delay4_DSTATE = Rotation_AHRS_GPS_B.Divide1_i;
  Rotation_AHRS_GPS_DW.DelayInput1_DSTATE_ms =
    Rotation_AHRS_GPS_B.DataTypeConversion1_ba;
  Rotation_AHRS_GPS_DW.DelayInput1_DSTATE_bu =
    Rotation_AHRS_GPS_B.DataTypeConversion1_j;
  Rotation_AHRS_GPS_DW.icLoad_n = 0U;
  Rotation_AHRS_GPS_DW.Delay6_DSTATE =
    Rotation_AHRS_GPS_B.DiscreteTimeIntegrator_mg;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE_f +=
    ((*rtu_Sensor_data_Mag_Quality -
      Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_DSTA_la) *
     Rotation_AHRS_GPS_P_g.Gain_Gain_il + Rotation_AHRS_GPS_P_g.Gain1_Gain_gu *
     Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTATE_f) *
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_gainv_lh;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator1_DSTA_la +=
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator1_gainv_a *
    Rotation_AHRS_GPS_B.Saturation1;
  Rotation_AHRS_GPS_DW.DelayInput1_DSTATE_dc =
    Rotation_AHRS_GPS_B.DataTypeConversion1_j;
  Rotation_AHRS_GPS_DW.DelayInput1_DSTATE_n5 =
    Rotation_AHRS_GPS_B.DataTypeConversion1_ba;
  Rotation_AHRS_GPS_DW.Delay_DSTATE_j = (Rotation_AHRS_GPS_B.Sum2_j != 0);
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_jd +=
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_gainv_el *
    Rotation_AHRS_GPS_P_g.Constant_Value_av;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_PrevRe_l = (int8_T)
    Rotation_AHRS_GPS_B.LogicalOperator8_e;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_IC_LO_md = 0U;
  Rotation_AHRS_GPS_DW.Delay_DSTATE_l[0] = Rotation_AHRS_GPS_B.Divide3[0];
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_dm[0] +=
    (Rotation_AHRS_GPS_B.Divide3[0] - rty_Rotation_data_M_OObar[0]) *
    Rotation_AHRS_GPS_P_g.Gain_Gain_c0 *
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_gainv_gn;
  Rotation_AHRS_GPS_DW.Delay_DSTATE_l[1] = Rotation_AHRS_GPS_B.Divide3[1];
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_dm[1] +=
    (Rotation_AHRS_GPS_B.Divide3[1] - rty_Rotation_data_M_OObar[1]) *
    Rotation_AHRS_GPS_P_g.Gain_Gain_c0 *
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_gainv_gn;
  Rotation_AHRS_GPS_DW.Delay_DSTATE_l[2] = Rotation_AHRS_GPS_B.Divide3[2];
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_dm[2] +=
    (Rotation_AHRS_GPS_B.Divide3[2] - rty_Rotation_data_M_OObar[2]) *
    Rotation_AHRS_GPS_P_g.Gain_Gain_c0 *
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_gainv_gn;
  Rotation_AHRS_GPS_DW.Delay_DSTATE_l[3] = Rotation_AHRS_GPS_B.Divide3[3];
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_DSTAT_dm[3] +=
    (Rotation_AHRS_GPS_B.Divide3[3] - rty_Rotation_data_M_OObar[3]) *
    Rotation_AHRS_GPS_P_g.Gain_Gain_c0 *
    Rotation_AHRS_GPS_P_g.DiscreteTimeIntegrator_gainv_gn;
  Rotation_AHRS_GPS_DW.DiscreteTimeIntegrator_PrevR_m4 = (int8_T)
    Rotation_AHRS_GPS_B.LogicalOperator3_f;
  Rotation_AHRS_GPS_DW.DelayInput1_DSTATE_px =
    Rotation_AHRS_GPS_B.DataTypeConversion1_ba;
  Rotation_AHRS_GPS_DW.DelayInput1_DSTATE_by =
    Rotation_AHRS_GPS_B.DataTypeConversion1_j;
}

void Rotation_AHRS_GPS_Term(void)
{
  Rotation_AH_MovingAverage2_Term(&Rotation_AHRS_GPS_DW.MovingAverage3);
  Rotation_AH_MovingAverage2_Term(&Rotation_AHRS_GPS_DW.MovingAverage1);
  Rotation_AH_MovingAverage2_Term(&Rotation_AHRS_GPS_DW.MovingAverage2);
}

void Rotation_AHRS_GPS_initialize(const char_T **rt_errorStatus)
{
  RT_MODEL_Rotation_AHRS_GPS_T *const Rotation_AHRS_GPS_M =
    &(Rotation_AHRS_GPS_MdlrefDW.rtm);
  rt_InitInfAndNaN(sizeof(real_T));
  rtmSetErrorStatusPointer(Rotation_AHRS_GPS_M, rt_errorStatus);
  Rotation_AHRS_GPS_PrevZCX.Delay16_Reset_ZCE = POS_ZCSIG;
  Rotation_AHRS_GPS_PrevZCX.Delay12_Reset_ZCE = POS_ZCSIG;
  Rotation_AHRS_GPS_PrevZCX.Delay3_Reset_ZCE = POS_ZCSIG;
  Rotation_AHRS_GPS_PrevZCX.Delay2_Reset_ZCE = POS_ZCSIG;
  Rotation_AHRS_GPS_PrevZCX.Delay1_Reset_ZCE = POS_ZCSIG;
  Rotation_AHRS_GPS_PrevZCX.Delay_Reset_ZCE = POS_ZCSIG;
  Rotation_AHRS_GPS_PrevZCX.Delay4_Reset_ZCE = POS_ZCSIG;
  Rotation_AHRS_GPS_PrevZCX.Delay6_Reset_ZCE = POS_ZCSIG;
}
