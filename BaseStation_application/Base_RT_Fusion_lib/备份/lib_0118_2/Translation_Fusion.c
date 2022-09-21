#include "Translation_Fusion.h"
#include "plook_u32f_evencka.h"
#include "rt_invf2x2_snf.h"
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

P_Translation_Fusion_T Translation_Fusion_P_g = {
  1.0E-6,
  1.0E-6,
  1.0E-6,
  1.0E-6,
  1.0E-6,
  0.0F,
  10.0F,
  42.0F,
  42.0F,
  402.0F,
  10.0F,
  40.0F,
  100.0F,
  1.0F,
  0.2F,
  0.1F,
  0.5F,
  10.0F,
  1.0F,
  1.0F,
  2.0F,
  1.0F,
  1.0F,
  0.3F,
  1.0F,
  0.3F,
  1.0F,
  0.21F,
  0.5F,
  0.1F,
  0.01F,
  0.01F,
  3.84F,
  0.05F,
  0.2F,
  0.5F,
  0.8F,
  0.5F,
  0.6F,
  0.5F,
  0.25F,
  2.0F,
  0.2F,
  10.0F,
  1.5F,
  1.5F,
  0.9F,
  0.21F,
  15.0F,
  0.35F,
  3.0F,
  2.0F,
  2.0F,
  0.5F,
  0.5F,
  0.6F,
  1.0F,
  5.0F,
  5.0F,
  1.0F,
  5.0F,
  1.0F,
  0.17453292F,
  0.6F,
  3.0F,
  1.5F,
  2.0F,
  0.9F,
  210.0F,
  5.0F,
  5.0F,
  0.2F,
  3.0F,
  3.0F,
  -0.3F,
  0.21F,
  0.3F,
  0.01F,
  0.2F,
  0.5F,
  0.2F,
  0.5F,
  10.0F,
  0.01F,
  0.3F,
  0.25F,
  0.5F,
  10.0F,
  0.2F,
  0.0001F,
  0.0001F,
  0.0001F,
  1.0F,
  0.3F,
  20.0F,
  0.95F,
  1.0F,
  0.95F,
  0.6F,
  0.5F,
  0.174520075F,
  410.0F,
  5.0F,
  1.0F,
  5.0F,
  5.0F,
  0.2F,
  3.0F,
  3.0F,
  0.6F,
  210.0F,
  11.0F,
  0.2F,
  0.4F,
  0.9F,
  2.0F,
  0.4F,
  0.0F,
  110.0F,
  110.0F,
  1000.0F,
  0.9F,
  20.0F,
  1.0F,
  0.0001F,
  1.0F,
  1.0F,
  1.0F,
  1.0F,
  1.0F,
  3.84F,
  40.0F,
  10.0F,
  10.0F,
  100.0F,
  100.0F,
  100.0F,
  5.0F,
  100.0F,

  { 0.0001F, 0.0F, 0.0F, 0.0F, 0.0009F, 0.0F, 0.0F, 0.0F, 0.09F },
  0.05F,
  0.3F,
  -0.2F,
  0.3F,
  0.0F,
  0.0F,
  0.0F,
  48U,
  16U,
  48U,
  48U,
  48U,
  48U,
  34U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
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
  1U,
  2U,
  1U,
  1U,
  1U,
  1U,
  1U,
  2U,
  2U,
  1.0,

  { 0.0, 0.0 },
  1.5707963267948966,
  -1.5707963267948966,
  3.1415926535897931,
  -3.1415926535897931,
  -1.0,
  0.0,

  { 0.0, 0.0 },

  { 0.0, 0.0 },
  1.0,

  { 0.0, 0.0 },
  1.0,

  { 0.0, 0.0 },
  1.0,
  1.0E+8,
  0.0,
  0.0,
  0.0,
  1.0E+8,
  1.5707963267948966,
  -1.5707963267948966,
  3.1415926535897931,
  -3.1415926535897931,
  1.0E+8,
  1.5707963267948966,
  -1.5707963267948966,
  3.1415926535897931,
  -3.1415926535897931,
  1.0E+8,
  1.5707963267948966,
  -1.5707963267948966,
  3.1415926535897931,
  -3.1415926535897931,
  0.0F,
  0.0F,
  0.01F,
  1.0F,
  0.0F,
  1.0F,
  1.0F,
  0.5F,
  0.0F,
  0.0F,
  0.0F,
  0.0F,
  1.0F,
  1.0F,
  0.5F,
  0.0F,
  0.0F,
  0.0F,
  -1.0F,
  1.0F,
  1.0F,
  0.0F,
  0.0F,
  0.0F,
  0.0F,

  { 0.0F, 0.0001F, 1.0E-6F },

  { 0.0F, 0.0001F, 9.0E-6F },

  { 0.0F, 0.01F, 0.0001F },
  0.01F,
  0.0F,
  0.0F,
  0.0F,

  { 1.0F, 0.0F, 0.0F, 0.0F, 1.0F, 0.0F, 0.0F, 0.0F, 1.0F },
  1.0F,
  0.0F,
  20.0F,
  1.0F,
  0.1F,
  -0.1F,
  1.0F,
  1.0F,
  0.2F,
  0.0F,
  0.0F,
  0.0F,
  0.0F,
  0.0225F,
  0.0009F,
  1.0F,
  1.0F,
  0.0F,
  0.0F,
  0.0F,
  0.0F,
  0.0F,
  0.02F,
  1.0F,
  0.02F,
  -0.02F,
  0.0F,
  0.0F,
  4.0F,
  0.0F,
  0.0F,
  1.0F,
  0.36F,
  1.0F,
  1.0F,
  0.0F,
  0.0F,
  0.0F,
  0.0F,
  1.0F,
  1.0F,
  0.0F,
  0.0F,
  0.0F,
  0.0F,
  0.09F,
  0.0009F,
  1.0F,
  100.0F,
  0.0F,
  10.0F,
  0.1F,
  -1.0F,

  { 0.0F, 0.0F, 0.0F, 0.0F },
  1.0F,
  0.2F,
  0.0F,
  0.0F,
  0.0F,
  0.0F,
  0.0F,

  { 0.0F, 0.0F },
  4.0F,
  15.0F,
  1.0F,

  { 0.0025F, 0.0025F, 0.0009F, 0.0009F },

  { 0.0025F, 0.0025F, 0.09F, 0.09F },
  0.0F,

  { 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F },
  5.0F,
  1.0F,
  0.2F,

  { 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F },
  0.0F,
  0.0F,

  { 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F },

  { 1.0F, 0.0F, 0.0F, 1.0F },

  { 0.0625F, 0.0F, 0.0F, 0.0625F },
  1.0F,
  100.0F,
  0.0F,
  10.0F,
  -10.0F,
  0.0001F,
  1.0F,

  { 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F },
  1.0F,
  1.0F,
  0.0F,
  0.0F,
  0.0F,
  0.0F,
  0.0F,
  0.02F,
  0.0F,
  0.01F,
  0.01F,

  { 1.0F, 0.0F, 0.0F, 1.0F },

  { 0.01F, 0.0F, 0.0F, 0.01F },

  { 9.0F, 0.0F, 0.0F, 9.0F },

  { 100.0F, 0.0F, 0.0F, 100.0F },
  0.4F,
  0.5F,
  0.3F,
  0.85F,
  0.999F,
  0.25F,
  0.01F,
  0.0F,
  101.0F,
  0.0F,
  9.80665F,
  0.0F,
  0.2F,
  0.1F,
  1.0F,
  0.0F,
  0.0F,
  0.0F,
  0.6F,
  0.2F,
  1.0F,
  0.0F,
  0.6F,
  0.2F,
  1.0F,
  0.0F,
  0.6F,
  0.1F,
  1.0F,
  0.0F,
  0.3F,
  0.2F,
  0.0F,
  1.0F,
  0.6F,
  0.4F,
  0.0F,
  1.0F,
  1.0F,
  1.0F,
  0.0F,
  0.0F,
  0.0F,
  0.0F,
  0.5F,
  0.1F,
  1.0F,
  0.0F,
  0.3F,
  0.2F,
  0.0F,
  1.0F,
  0.6F,
  0.4F,
  0.0F,
  1.0F,
  1.0F,
  0.0F,
  1.0F,
  1.0F,
  0.0F,
  0.0F,
  0.0F,
  1.0F,
  0.0F,
  0.0F,
  0.0F,
  0.0F,
  0.0F,
  0.0F,
  0.0F,
  0.01F,

  { 0.0F, 0.0F, 0.0F },
  -1.0F,
  0.01F,

  { 0.0F, 0.0F, 0.0F, 1.0F, 0.0F, 0.0F, 0.0F, -1.0F, 0.0F },
  0.01F,
  0.5F,
  0.5F,

  { 0.0F, 1.0F, 0.0F },
  0.01F,
  -1.0F,
  1.0F,
  0.0F,
  1.0F,
  0.01F,
  0.0F,

  { 0.0F, 1.0F, 0.0F },
  0.01F,
  0.0F,
  0.01F,
  0.0F,
  0.01F,
  0.01F,
  0.0F,
  101.0F,
  0.0F,
  0.01F,
  0.0F,
  57.3F,
  0.01F,
  0.0F,
  101.0F,
  0.0F,
  0.65F,
  0.05F,
  1.0F,
  0.0F,
  0.4F,
  0.01F,
  1.0F,
  0.0F,
  0.0F,
  0.01F,
  0.5F,
  0.05F,
  1.0F,
  0.0F,
  0.01F,
  0.0F,
  0.0F,
  0.01F,
  0.0F,
  0.01F,
  0.0F,
  101.0F,
  0.0F,
  0.01F,
  0.0F,
  0.01F,
  0.0F,
  0.0F,
  0.01F,
  0.0F,
  57.3F,
  0.01F,
  0.0F,
  0.01F,
  0.0F,
  57.3F,
  0.01F,
  0.0F,
  0.01F,
  0.0F,
  101.0F,
  0.0F,

  { 1.0F, 0.0F, 0.0F },
  0.01F,
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
  101.0F,
  0.0F,

  { 0.0F, 1.0F, 0.0F },
  1.0F,
  1.0F,
  0.2F,
  1.0F,
  0.1F,
  1.0F,
  0.4F,
  0.05F,
  1.0F,
  0.0F,
  0.65F,
  0.2F,
  1.0F,
  0.0F,
  0.01F,
  0.0F,
  0.85F,
  0.35F,
  1.0F,
  0.0F,
  0.7F,
  0.5F,
  1.0F,
  0.0F,
  1.0F,
  0.0F,

  { 1.0F, 0.0F, 0.0F },

  { 0.094F, 0.0F, -0.055F },
  -1.0F,
  0.0F,
  0.01F,
  0.0F,
  0.1F,
  0.0F,
  0.0F,
  10.0F,
  -10.0F,
  0.01F,
  0.015625F,

  { 1.0F, 0.0F, 0.0F, 1.0F, 0.0F, 0.0F },
  0.01F,
  0.0F,
  -1.0F,

  { 0.5625F, 0.0625F },
  0.0F,
  0.0F,
  0.01F,
  0.0F,
  0.01F,
  0.0F,
  0.01F,
  0.0F,
  0.01F,
  0.0F,
  0.0F,
  0.0F,
  0.01F,
  0.0F,
  0.0F,
  0.01F,
  0.0F,
  0.0F,
  0.01F,
  0.0F,
  101.0F,
  0.0F,
  1.0F,
  0.01F,
  3.0F,
  -3.0F,
  0.95F,
  0.9F,
  1.0F,
  0.0F,
  0.01F,
  0.0F,
  0.01F,
  0.0F,
  0.333333343F,
  0.01F,
  0.01F,
  0.01F,
  0.01F,
  0.0F,

  { 1.0F, 0.0F, 0.0F },
  0.01F,
  0.0F,

  { 1.0F, 0.0F, 0.0F },
  0.49F,
  0.01F,
  0.0F,
  0.01F,
  0.0F,
  101.0F,
  0.0F,
  1.0F,
  0.01F,
  0.0F,
  100.0F,
  1.0F,
  -1.0F,
  0.2F,
  -0.2F,
  1.0F,
  1.0F,
  1.0F,
  0.01F,
  0.0F,
  -2.828F,
  0.01F,
  0.0F,
  4.0F,
  0.01F,
  60.0F,
  900.0F,
  0.0F,
  1.0F,
  1.0F,
  0.0F,
  0.01F,
  0.0F,
  -20.0F,
  0.01F,
  0.0F,
  100.0F,
  0.01F,
  0.0F,
  -20.0F,
  0.01F,
  0.0F,
  100.0F,
  0.01F,
  0.0F,
  0.0F,
  0.01F,
  0.0F,
  -14.14F,
  100.0F,
  0.0F,
  1.0F,
  2.0F,
  2.0F,
  2.0F,
  0.01F,
  0.0F,
  101.0F,
  0.0F,
  1.0F,
  0.01F,
  10.0F,
  10.0F,
  1.0F,
  0.01F,
  0.0F,
  9.090909F,
  3.33333325F,
  0.01F,
  0.0F,
  10.0F,
  3.33333325F,
  1.0F,
  0.01F,
  0.0F,
  -89.2212296F,
  0.01F,
  0.0F,
  3947.8418F,
  0.01F,
  0.0F,
  -42.42F,
  0.01F,
  0.0F,
  900.0F,
  0.01F,
  0.0F,
  -42.42F,
  0.01F,
  0.0F,
  900.0F,
  0.01F,
  0.0F,
  70.7F,
  2500.0F,
  0.01F,
  0.0F,
  70.7F,
  2500.0F,
  1.0F,
  1.0F,
  0.01F,
  0.0F,
  -42.42F,
  0.01F,
  0.0F,
  900.0F,
  0.01F,
  0.0F,
  70.7F,
  2500.0F,

  { 0.097F, 0.0F, 0.055F },
  0.01F,
  0.0F,
  -360.0F,
  0.01F,
  0.0F,
  40000.0F,
  0.01F,
  0.0F,
  -360.0F,
  0.01F,
  0.0F,
  40000.0F,
  0.01F,
  0.0F,
  -360.0F,
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
  40000.0F,
  0.01F,
  0.0F,
  -360.0F,
  0.01F,
  0.0F,
  40000.0F,
  0.01F,
  0.0F,
  -360.0F,
  1.0F,
  0.0F,
  0.01F,
  0.0F,
  40000.0F,
  1.0F,
  1.0F,
  10.0F,
  1.0F,
  1.0F,
  1.0F,
  0.5F,
  1.0F,
  0.1F,

  { 0.0001F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0001F, 0.0F, 0.0F, 0.0F, 0.0F, 0.01F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.01F },

  { 0.0F, 0.0F },
  0.01F,
  0.0F,
  1.0F,

  { 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F },

  { 0.001F, 0.0F, 0.0F, 0.001F },
  0.0F,

  { 1.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 1.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.001F, 0.0F, 1.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.001F, 0.0F, 1.0F, 0.0F, 0.0F,
    -5.0E-7F, 0.0F, -0.001F, 0.0F, 1.0F, 0.0F, 0.0F, -5.0E-7F, 0.0F, -0.001F,
    0.0F, 1.0F },
  0.01F,

  { 0.005F, 0.005F, 0.0F, 0.0F, 0.0F, 0.0F },
  0.01F,
  0.0F,
  0.0F,
  0.01F,
  0.0F,
  0.0F,
  1.0F,
  0.0F,
  0.01F,
  0.0F,
  0.1F,
  0.01F,
  0.0F,
  0.5F,
  0.01F,
  0.01F,
  0.0F,
  -1.0F,

  { 1.0F, 0.0F, 0.0F, 1.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F },

  { 0.0F, 0.0F },
  10.0F,
  -10.0F,

  { 0.0F, 0.0F },
  -1.0F,
  0.01F,
  0.0F,
  1.0F,

  { 0.015625F, 0.0F, 0.0F, 0.015625F },

  { 0.0F, 0.0F, 0.0F, 0.0F, 1.0F, 0.0F, 0.0F, 1.0F, 0.0F, 0.0F, 0.0F, 0.0F },

  { 1.0F, 0.0F, 0.0F, 0.0F, 0.0F, 1.0F, 0.0F, 0.0F, 0.0F, 0.0F, 1.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 1.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F },

  { 0.015625F, 0.0F, 0.0F, 0.0F, 0.0F, 0.015625F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0625F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0625F },
  0.0F,
  1.0F,
  0.0F,
  0.0F,
  0.01F,
  0.01F,
  0.01F,

  { 1.0F, 0.0F, 0.0F, 1.0F, 0.0F, 0.0F, 0.0F, 0.0F },
  0.01F,

  { 1.0F, 0.0F, 0.0F, 1.0F },
  1.0F,
  0.0F,
  0.1F,
  0.01F,
  0.01F,

  { 1.0F, 0.0F, 0.0F, 1.0F, 0.0F, 0.0F, 0.0F, 0.0F },
  1.0F,
  0.3F,
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
  1.0F,
  0.0F,
  1.0F,
  0.0F,
  0.02F,
  0.01F,
  0.01F,

  { 1.0F, 0.0F, 0.0F, 1.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F },

  { 0.1225F, 0.0F, 0.0F, 0.1225F },

  { 100.0F, 100.0F, 20.0F, 8.0F, 4.0F, 1.0F },

  { 0.0F, 0.2F, 0.4F, 0.6F, 0.8F, 1.0F },
  100.0F,
  1.0F,
  1.0F,
  33.3333321F,
  33.3333321F,
  0.01F,
  0.01F,
  5.0F,
  -5.0F,
  0.04F,
  0.04F,
  0.01F,
  0.0F,
  -5.4F,
  10.0F,
  9.0F,
  0.01F,
  0.0F,
  -5.4F,
  9.0F,
  1.0F,
  33.3333321F,
  33.3333321F,
  0.01F,
  0.0F,
  -90.7F,
  2500.0F,
  1.0F,
  1.0F,
  1.0F,
  33.3333321F,
  33.3333321F,
  1.0F,
  10.0F,
  1.0F,
  1.0F,
  1U,
  1U,
  1U,
  5U,
  1U,
  1U,
  1U,
  1U,
  1U,
  1U,
  10U,
  1U,
  1U,
  5U,
  1U,
  5U,
  1U,
  1U,
  2U,
  1U,
  1U,
  1U,
  1U,
  10U,
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
  40U,
  140U,
  1U,
  1U,
  2U,
  1U,
  1U,
  1U,
  1U,
  1U,
  1U,
  100U,
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
  140U,
  140U,
  1U,
  2U,
  40U,
  40U,
  1U,
  80U,
  1U,
  1U,
  80U,
  1U,
  0U,
  10U,
  0U,
  1,
  0,
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
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  192U,
  128U,
  128U,
  0U,
  0U,
  0U,
  0U,
  0U,

  {
    0.0F,
    0.0F,

    { 1.0F, 0.0F, 0.0F, 0.0F, 1.0F, 0.0F, 0.0F, 0.0F, 1.0F },
    0.15F,
    -0.15F,
    1.0F
  }
  ,


  {
    0.0F,
    0.0F,

    { 1.0F, 0.0F, 0.0F, 0.0F, 1.0F, 0.0F, 0.0F, 0.0F, 1.0F },
    0.15F,
    -0.15F,
    1.0F
  }
  ,


  {
    0.0F,
    0.0F,

    { 1.0F, 0.0F, 0.0F, 0.0F, 1.0F, 0.0F, 0.0F, 0.0F, 1.0F }
  }
  ,


  {
    0.0F,
    0.0F,

    { 1.0F, 0.0F, 0.0F, 0.0F, 1.0F, 0.0F, 0.0F, 0.0F, 1.0F }
  }
  ,


  {
    0.0F,
    0.0F,

    { 1.0F, 0.0F, 0.0F, 0.0F, 1.0F, 0.0F, 0.0F, 0.0F, 1.0F },

    { 0.15F, 9.0F },

    { -0.15F, -9.0F }
  }
  ,


  {
    0.0F,
    0.0F,

    { 1.0F, 0.0F, 0.0F, 0.0F, 1.0F, 0.0F, 0.0F, 0.0F, 1.0F },

    { 0.15F, 9.0F },

    { -0.15F, -9.0F }
  }
  ,


  {
    0.0F,
    0.0F,

    { 1.0F, 0.0F, 0.0F, 0.0F, 1.0F, 0.0F, 0.0F, 0.0F, 1.0F },
    0.15F,
    -0.15F,
    1.0F
  }
  ,


  {
    0.0F,
    0.0F,

    { 1.0F, 0.0F, 0.0F, 0.0F, 1.0F, 0.0F, 0.0F, 0.0F, 1.0F },
    0.15F,
    -0.15F,
    1.0F
  }
  ,


  {
    0.0F,
    0.0F,

    { 1.0F, 0.0F, 0.0F, 0.0F, 1.0F, 0.0F, 0.0F, 0.0F, 1.0F },

    { 0.15F, 9.0F },

    { -0.15F, -9.0F }
  }

};

MdlrefDW_Translation_Fusion_T Translation_Fusion_MdlrefDW;
B_Translation_Fusion_c_T Translation_Fusion_B;
DW_Translation_Fusion_f_T Translation_Fusion_DW;
ZCE_Translation_Fusion_T Translation_Fusion_PrevZCX;
static void Translation__SystemCore_release(dsp_simulink_MovingAverage_Tr_T *obj);
static void Translation_F_SystemCore_delete(dsp_simulink_MovingAverage_Tr_T *obj);
static void matlabCodegenHandle_matlabCodeg(dsp_simulink_MovingAverage_Tr_T *obj);
static void Translatio_SystemCore_release_m(dsp_simulink_MovingAverage_e_T *obj);
static void Translation_SystemCore_delete_a(dsp_simulink_MovingAverage_e_T *obj);
static void matlabCodegenHandle_matlabCod_g(dsp_simulink_MovingAverage_e_T *obj);
static void Translati_SystemCore_release_mt(dsp_simulink_MovingAverage_e3_T *obj);
static void Translatio_SystemCore_delete_as(dsp_simulink_MovingAverage_e3_T *obj);
static void matlabCodegenHandle_matlabCo_go(dsp_simulink_MovingAverage_e3_T *obj);
static void Translat_SystemCore_release_mt2(dsp_simulink_MovingAverag_e3x_T *obj);
static void Translati_SystemCore_delete_asm(dsp_simulink_MovingAverag_e3x_T *obj);
static void matlabCodegenHandle_matlabC_goq(dsp_simulink_MovingAverag_e3x_T *obj);
static void Transla_SystemCore_release_mt2c(dsp_simulink_MovingAvera_e3xk_T *obj);
static void Translat_SystemCore_delete_asmv(dsp_simulink_MovingAvera_e3xk_T *obj);
static void matlabCodegenHandle_matlab_goqu(dsp_simulink_MovingAvera_e3xk_T *obj);
static void Transl_SystemCore_release_mt2c4(dsp_simulink_MovingAver_e3xkx_T *obj);
static void Transla_SystemCore_delete_asmvp(dsp_simulink_MovingAver_e3xkx_T *obj);
static void matlabCodegenHandle_matla_goquh(dsp_simulink_MovingAver_e3xkx_T *obj);
static void Translation_Fusi_rt_invf2x2_snf(const real32_T u[4], real32_T y[4]);
static void Tran_SystemCore_release_mt2c4ip(dsp_simulink_MovingAve_e3xkxm_T *obj);
static void Trans_SystemCore_delete_asmvpfi(dsp_simulink_MovingAve_e3xkxm_T *obj);
static void matlabCodegenHandle_mat_goquh1b(dsp_simulink_MovingAve_e3xkxm_T *obj);
static void Trans_SystemCore_release_mt2c4i(dsp_simulink_MovingAver_e3xkx_T *obj);
static void Transl_SystemCore_delete_asmvpf(dsp_simulink_MovingAver_e3xkx_T *obj);
static void matlabCodegenHandle_matl_goquh1(dsp_simulink_MovingAver_e3xkx_T *obj);
static void Tra_SystemCore_release_mt2c4ipi(dsp_simulink_MovingAv_e3xkxms_T *obj);
static void Tran_SystemCore_delete_asmvpfiv(dsp_simulink_MovingAv_e3xkxms_T *obj);
static void matlabCodegenHandle_ma_goquh1bj(dsp_simulink_MovingAv_e3xkxms_T *obj);
static void Translation__SystemCore_release(dsp_simulink_MovingAverage_Tr_T *obj)
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

static void Translation_F_SystemCore_delete(dsp_simulink_MovingAverage_Tr_T *obj)
{
  Translation__SystemCore_release(obj);
}

static void matlabCodegenHandle_matlabCodeg(dsp_simulink_MovingAverage_Tr_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    Translation_F_SystemCore_delete(obj);
  }
}

void Translation_MovingAverage2_Init(DW_MovingAverage2_Translation_T *localDW)
{
  if (localDW->obj.pStatistic->isInitialized == 1) {
    localDW->obj.pStatistic->pCumSum = 0.0F;
    memset(&localDW->obj.pStatistic->pCumSumRev[0], 0, 19U * sizeof(real32_T));
    localDW->obj.pStatistic->pCumRevIndex = 1.0F;
  }
}

void Translatio_MovingAverage2_Start(DW_MovingAverage2_Translation_T *localDW)
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

void Translation_Fusi_MovingAverage2(real32_T rtu_0,
  B_MovingAverage2_Translation__T *localB, DW_MovingAverage2_Translation_T
  *localDW)
{
  real32_T cumRevIndex;
  real32_T csum;
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
    memset(&localDW->obj.pStatistic->pCumSumRev[0], 0, 19U * sizeof(real32_T));
    localDW->obj.pStatistic->pCumRevIndex = 1.0F;
  }

  cumRevIndex = localDW->obj.pStatistic->pCumRevIndex;
  csum = localDW->obj.pStatistic->pCumSum;
  for (z_tmp = 0; z_tmp < 19; z_tmp++) {
    localB->csumrev[z_tmp] = localDW->obj.pStatistic->pCumSumRev[z_tmp];
  }

  csum += rtu_0;
  z_tmp = (int32_T)cumRevIndex - 1;
  z = localB->csumrev[z_tmp] + csum;
  localB->csumrev[z_tmp] = rtu_0;
  if (cumRevIndex != 19.0F) {
    cumRevIndex++;
  } else {
    cumRevIndex = 1.0F;
    csum = 0.0F;
    for (z_tmp = 17; z_tmp >= 0; z_tmp--) {
      localB->csumrev[z_tmp] += localB->csumrev[z_tmp + 1];
    }
  }

  localDW->obj.pStatistic->pCumSum = csum;
  memcpy(&localDW->obj.pStatistic->pCumSumRev[0], &localB->csumrev[0], 19U *
         sizeof(real32_T));
  localDW->obj.pStatistic->pCumRevIndex = cumRevIndex;
  localB->MovingAverage2 = z / 20.0F;
}

void Translation_MovingAverage2_Term(DW_MovingAverage2_Translation_T *localDW)
{
  matlabCodegenHandle_matlabCodeg(&localDW->obj);
}

static void Translatio_SystemCore_release_m(dsp_simulink_MovingAverage_e_T *obj)
{
  dsp_private_SlidingWindowAv_h_T *obj_0;
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    obj_0 = obj->pStatistic;
    if (obj_0->isInitialized == 1) {
      obj_0->isInitialized = 2;
    }

    obj->NumChannels = -1;
  }
}

static void Translation_SystemCore_delete_a(dsp_simulink_MovingAverage_e_T *obj)
{
  Translatio_SystemCore_release_m(obj);
}

static void matlabCodegenHandle_matlabCod_g(dsp_simulink_MovingAverage_e_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    Translation_SystemCore_delete_a(obj);
  }
}

void Translation_Fusion_Average_Init(DW_Average_Translation_Fusion_T *localDW)
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

void Translation_Fusio_Average_Reset(DW_Average_Translation_Fusion_T *localDW)
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

void Translation_Fusio_Average_Start(DW_Average_Translation_Fusion_T *localDW)
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

void Translation_Fusion_Average(real32_T rtu_0, B_Average_Translation_Fusion_T
  *localB, DW_Average_Translation_Fusion_T *localDW)
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
  localB->Average = z / 10.0F;
}

void Translation_Fusion_Average_Term(DW_Average_Translation_Fusion_T *localDW)
{
  matlabCodegenHandle_matlabCod_g(&localDW->obj);
}

void Translation_Fusi_Correct_x_Init(B_Correct_x_Translation_Fusio_T *localB,
  P_Correct_x_Translation_Fusio_T *localP)
{
  int32_T i;
  localB->Multiply[0] = localP->X_Cor_Y0;
  localB->Multiply[1] = localP->X_Cor_Y0;
  localB->Multiply[2] = localP->X_Cor_Y0;
  for (i = 0; i < 9; i++) {
    localB->Multiply5[i] = localP->P_next_Y0;
  }
}

void Translation_Fusion_Correct_x(boolean_T rtu_Enable, real32_T rtu_Delay_X,
  real32_T rtu_Delay_X_a, real32_T rtu_Delay_X_h, const real32_T rtu_P[9], const
  real32_T rtu_H[6], real32_T rtu_Z, real32_T rtu_Z_o, const real32_T rtu_R[4],
  B_Correct_x_Translation_Fusio_T *localB, P_Correct_x_Translation_Fusio_T
  *localP)
{
  real32_T rtu_H_0[4];
  real32_T rtu_Z_0[2];
  real32_T tmp[2];
  int32_T i;
  int32_T i_0;
  int32_T rtb_Multiply1_tmp_tmp;
  int32_T rtb_Multiply1_tmp_tmp_0;
  real32_T rtb_Multiply1_tmp;
  if (rtu_Enable) {
    for (i_0 = 0; i_0 < 2; i_0++) {
      for (i = 0; i < 3; i++) {
        rtb_Multiply1_tmp_tmp = i << 1;
        rtb_Multiply1_tmp_tmp_0 = rtb_Multiply1_tmp_tmp + i_0;
        localB->rtb_Multiply1_tmp[i + 3 * i_0] = rtu_H[rtb_Multiply1_tmp_tmp_0];
        rtb_Multiply1_tmp_tmp += i_0;
        localB->rtu_H[rtb_Multiply1_tmp_tmp] = 0.0F;
        localB->rtu_H[rtb_Multiply1_tmp_tmp] = localB->
          rtu_H[rtb_Multiply1_tmp_tmp_0] + rtu_P[3 * i] * rtu_H[i_0];
        localB->rtu_H[rtb_Multiply1_tmp_tmp] = rtu_P[3 * i + 1] * rtu_H[i_0 + 2]
          + localB->rtu_H[rtb_Multiply1_tmp_tmp_0];
        localB->rtu_H[rtb_Multiply1_tmp_tmp] = rtu_P[3 * i + 2] * rtu_H[i_0 + 4]
          + localB->rtu_H[rtb_Multiply1_tmp_tmp_0];
      }
    }

    for (i_0 = 0; i_0 < 2; i_0++) {
      for (i = 0; i < 2; i++) {
        rtb_Multiply1_tmp_tmp = i_0 << 1;
        rtu_H_0[i + rtb_Multiply1_tmp_tmp] = ((localB->rtb_Multiply1_tmp[3 * i_0
          + 1] * localB->rtu_H[i + 2] + localB->rtb_Multiply1_tmp[3 * i_0] *
          localB->rtu_H[i]) + localB->rtb_Multiply1_tmp[3 * i_0 + 2] *
          localB->rtu_H[i + 4]) + rtu_R[rtb_Multiply1_tmp_tmp + i];
      }
    }

    localB->rtu_H_m[0] = rtu_H_0[0];
    localB->rtu_H_m[1] = rtu_H_0[1];
    localB->rtu_H_m[2] = rtu_H_0[2];
    localB->rtu_H_m[3] = rtu_H_0[3];
    rt_invf2x2_snf(localB->rtu_H_m, rtu_H_0);
    for (i_0 = 0; i_0 < 3; i_0++) {
      for (i = 0; i < 2; i++) {
        rtb_Multiply1_tmp_tmp_0 = i_0 + 3 * i;
        localB->rtu_H[rtb_Multiply1_tmp_tmp_0] = 0.0F;
        rtb_Multiply1_tmp_tmp = 3 * i + i_0;
        localB->rtu_H[rtb_Multiply1_tmp_tmp_0] = localB->
          rtu_H[rtb_Multiply1_tmp_tmp] + localB->rtb_Multiply1_tmp[3 * i] *
          rtu_P[i_0];
        localB->rtu_H[rtb_Multiply1_tmp_tmp_0] = localB->rtb_Multiply1_tmp[3 * i
          + 1] * rtu_P[i_0 + 3] + localB->rtu_H[rtb_Multiply1_tmp_tmp];
        localB->rtu_H[rtb_Multiply1_tmp_tmp_0] = localB->rtb_Multiply1_tmp[3 * i
          + 2] * rtu_P[i_0 + 6] + localB->rtu_H[rtb_Multiply1_tmp_tmp];
      }

      localB->Multiply1[i_0] = 0.0F;
      localB->Multiply1[i_0] += localB->rtu_H[i_0] * rtu_H_0[0];
      rtb_Multiply1_tmp = localB->rtu_H[i_0 + 3];
      localB->Multiply1[i_0] += rtb_Multiply1_tmp * rtu_H_0[1];
      localB->Multiply1[i_0 + 3] = 0.0F;
      localB->Multiply1[i_0 + 3] += localB->rtu_H[i_0] * rtu_H_0[2];
      localB->Multiply1[i_0 + 3] += rtb_Multiply1_tmp * rtu_H_0[3];
      for (i = 0; i < 3; i++) {
        rtb_Multiply1_tmp_tmp_0 = i << 1;
        localB->fv0[i_0 + 3 * i] = localP->Constant_Value[3 * i + i_0] -
          (rtu_H[rtb_Multiply1_tmp_tmp_0 + 1] * localB->Multiply1[i_0 + 3] +
           rtu_H[rtb_Multiply1_tmp_tmp_0] * localB->Multiply1[i_0]);
      }

      for (i = 0; i < 3; i++) {
        rtb_Multiply1_tmp_tmp_0 = i_0 + 3 * i;
        localB->Multiply5[rtb_Multiply1_tmp_tmp_0] = 0.0F;
        rtb_Multiply1_tmp_tmp = 3 * i + i_0;
        localB->Multiply5[rtb_Multiply1_tmp_tmp_0] = localB->
          Multiply5[rtb_Multiply1_tmp_tmp] + rtu_P[3 * i] * localB->fv0[i_0];
        localB->Multiply5[rtb_Multiply1_tmp_tmp_0] = rtu_P[3 * i + 1] *
          localB->fv0[i_0 + 3] + localB->Multiply5[rtb_Multiply1_tmp_tmp];
        localB->Multiply5[rtb_Multiply1_tmp_tmp_0] = rtu_P[3 * i + 2] *
          localB->fv0[i_0 + 6] + localB->Multiply5[rtb_Multiply1_tmp_tmp];
      }
    }

    rtu_Z_0[0] = rtu_Z;
    rtu_Z_0[1] = rtu_Z_o;
    for (i_0 = 0; i_0 < 2; i_0++) {
      rtb_Multiply1_tmp = rtu_Z_0[i_0] - ((rtu_H[i_0 + 2] * rtu_Delay_X_a +
        rtu_H[i_0] * rtu_Delay_X) + rtu_H[i_0 + 4] * rtu_Delay_X_h);
      if (rtb_Multiply1_tmp > localP->Saturation1_UpperSat[i_0]) {
        tmp[i_0] = localP->Saturation1_UpperSat[i_0];
      } else if (rtb_Multiply1_tmp < localP->Saturation1_LowerSat[i_0]) {
        tmp[i_0] = localP->Saturation1_LowerSat[i_0];
      } else {
        tmp[i_0] = rtb_Multiply1_tmp;
      }
    }

    for (i_0 = 0; i_0 < 3; i_0++) {
      localB->Multiply[i_0] = 0.0F;
      localB->Multiply[i_0] += localB->Multiply1[i_0] * tmp[0];
      localB->Multiply[i_0] += localB->Multiply1[i_0 + 3] * tmp[1];
    }
  }
}

static void Translati_SystemCore_release_mt(dsp_simulink_MovingAverage_e3_T *obj)
{
  dsp_private_SlidingWindowA_hg_T *obj_0;
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    obj_0 = obj->pStatistic;
    if (obj_0->isInitialized == 1) {
      obj_0->isInitialized = 2;
    }

    obj->NumChannels = -1;
  }
}

static void Translatio_SystemCore_delete_as(dsp_simulink_MovingAverage_e3_T *obj)
{
  Translati_SystemCore_release_mt(obj);
}

static void matlabCodegenHandle_matlabCo_go(dsp_simulink_MovingAverage_e3_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    Translatio_SystemCore_delete_as(obj);
  }
}

void Translation_Fusi_Average_a_Init(DW_Average_Translation_Fusi_f_T *localDW)
{
  if (localDW->obj.pStatistic->isInitialized == 1) {
    localDW->obj.pStatistic->pCumSum = 0.0F;
    memset(&localDW->obj.pStatistic->pCumSumRev[0], 0, 41U * sizeof(real32_T));
    localDW->obj.pStatistic->pCumRevIndex = 1.0F;
  }
}

void Translation_Fus_Average_d_Reset(DW_Average_Translation_Fusi_f_T *localDW)
{
  if (localDW->obj.pStatistic->isInitialized == 1) {
    localDW->obj.pStatistic->pCumSum = 0.0F;
    memset(&localDW->obj.pStatistic->pCumSumRev[0], 0, 41U * sizeof(real32_T));
    localDW->obj.pStatistic->pCumRevIndex = 1.0F;
  }
}

void Translation_Fus_Average_m_Start(DW_Average_Translation_Fusi_f_T *localDW)
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

void Translation_Fusion_Average_p(real32_T rtu_0,
  B_Average_Translation_Fusio_c_T *localB, DW_Average_Translation_Fusi_f_T
  *localDW)
{
  real32_T cumRevIndex;
  real32_T csum;
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
    memset(&localDW->obj.pStatistic->pCumSumRev[0], 0, 41U * sizeof(real32_T));
    localDW->obj.pStatistic->pCumRevIndex = 1.0F;
  }

  cumRevIndex = localDW->obj.pStatistic->pCumRevIndex;
  csum = localDW->obj.pStatistic->pCumSum;
  for (z_tmp = 0; z_tmp < 41; z_tmp++) {
    localB->csumrev[z_tmp] = localDW->obj.pStatistic->pCumSumRev[z_tmp];
  }

  csum += rtu_0;
  z_tmp = (int32_T)cumRevIndex - 1;
  z = localB->csumrev[z_tmp] + csum;
  localB->csumrev[z_tmp] = rtu_0;
  if (cumRevIndex != 41.0F) {
    cumRevIndex++;
  } else {
    cumRevIndex = 1.0F;
    csum = 0.0F;
    for (z_tmp = 39; z_tmp >= 0; z_tmp--) {
      localB->csumrev[z_tmp] += localB->csumrev[z_tmp + 1];
    }
  }

  localDW->obj.pStatistic->pCumSum = csum;
  memcpy(&localDW->obj.pStatistic->pCumSumRev[0], &localB->csumrev[0], 41U *
         sizeof(real32_T));
  localDW->obj.pStatistic->pCumRevIndex = cumRevIndex;
  localB->Average = z / 42.0F;
}

void Translation_Fusi_Average_n_Term(DW_Average_Translation_Fusi_f_T *localDW)
{
  matlabCodegenHandle_matlabCo_go(&localDW->obj);
}

void Translation_Fu_Correct_x_e_Init(B_Correct_x_Translation_Fus_h_T *localB,
  P_Correct_x_Translation_Fus_j_T *localP)
{
  int32_T i;
  for (i = 0; i < 9; i++) {
    localB->Multiply5[i] = localP->P_next_Y0;
  }

  localB->Multiply[0] = localP->X_Cor_Y0;
  localB->Multiply[1] = localP->X_Cor_Y0;
  localB->Multiply[2] = localP->X_Cor_Y0;
}

void Translation_Fusion_Correct_x_d(boolean_T rtu_Enable, real32_T rtu_Delay_X,
  real32_T rtu_Delay_X_l, real32_T rtu_Delay_X_o, const real32_T rtu_P[9], const
  real32_T rtu_H[3], real32_T rtu_Z, real32_T rtu_R,
  B_Correct_x_Translation_Fus_h_T *localB, P_Correct_x_Translation_Fus_j_T
  *localP)
{
  real32_T rtb_Gain_da;
  real32_T rtb_Multiply1_l[3];
  real32_T rtu_Delay_X_0[3];
  real32_T rtu_H_0;
  int32_T i;
  int32_T i_0;
  real32_T rtb_Multiply1_j;
  int32_T Multiply5_tmp;
  int32_T Multiply5_tmp_0;
  if (rtu_Enable) {
    rtu_H_0 = 0.0F;
    for (i = 0; i < 3; i++) {
      rtu_H_0 += (rtu_P[3 * i + 2] * rtu_H[2] + (rtu_P[3 * i + 1] * rtu_H[1] +
        rtu_P[3 * i] * rtu_H[0])) * rtu_H[i];
    }

    rtb_Gain_da = 1.0F / (rtu_H_0 + rtu_R);
    rtu_Delay_X_0[0] = rtu_Delay_X;
    rtu_Delay_X_0[1] = rtu_Delay_X_l;
    rtu_Delay_X_0[2] = rtu_Delay_X_o;
    rtu_H_0 = 0.0F;
    for (i = 0; i < 3; i++) {
      rtb_Multiply1_j = (rtu_P[i + 6] * rtu_H[2] + (rtu_P[i + 3] * rtu_H[1] +
        rtu_P[i] * rtu_H[0])) * rtb_Gain_da;
      localB->fv0[i] = localP->Constant_Value[i] - rtb_Multiply1_j * rtu_H[0];
      localB->fv0[i + 3] = localP->Constant_Value[i + 3] - rtb_Multiply1_j *
        rtu_H[1];
      localB->fv0[i + 6] = localP->Constant_Value[i + 6] - rtb_Multiply1_j *
        rtu_H[2];
      for (i_0 = 0; i_0 < 3; i_0++) {
        Multiply5_tmp = i + 3 * i_0;
        localB->Multiply5[Multiply5_tmp] = 0.0F;
        Multiply5_tmp_0 = 3 * i_0 + i;
        localB->Multiply5[Multiply5_tmp] = localB->Multiply5[Multiply5_tmp_0] +
          rtu_P[3 * i_0] * localB->fv0[i];
        localB->Multiply5[Multiply5_tmp] = rtu_P[3 * i_0 + 1] * localB->fv0[i +
          3] + localB->Multiply5[Multiply5_tmp_0];
        localB->Multiply5[Multiply5_tmp] = rtu_P[3 * i_0 + 2] * localB->fv0[i +
          6] + localB->Multiply5[Multiply5_tmp_0];
      }

      rtu_H_0 += rtu_H[i] * rtu_Delay_X_0[i];
      rtb_Multiply1_l[i] = rtb_Multiply1_j;
    }

    rtu_H_0 = rtu_Z - rtu_H_0;
    if (rtu_H_0 > localP->Saturation1_UpperSat) {
      rtu_H_0 = localP->Saturation1_UpperSat;
    } else {
      if (rtu_H_0 < localP->Saturation1_LowerSat) {
        rtu_H_0 = localP->Saturation1_LowerSat;
      }
    }

    rtb_Gain_da = localP->Gain_Gain * rtu_H_0;
    localB->Multiply[0] = rtb_Multiply1_l[0] * rtb_Gain_da;
    localB->Multiply[1] = rtb_Multiply1_l[1] * rtb_Gain_da;
    localB->Multiply[2] = rtb_Multiply1_l[2] * rtb_Gain_da;
  }
}

void Translation_Fusi_Correct_y_Init(B_Correct_y_Translation_Fusio_T *localB,
  P_Correct_y_Translation_Fusio_T *localP)
{
  int32_T i;
  for (i = 0; i < 9; i++) {
    localB->Multiply5[i] = localP->P_next_Y0;
  }

  localB->Multiply[0] = localP->X_Cor_Y0;
  localB->Multiply[1] = localP->X_Cor_Y0;
  localB->Multiply[2] = localP->X_Cor_Y0;
}

void Translation_Fusion_Correct_y(boolean_T rtu_Enable, real32_T rtu_Delay_X,
  real32_T rtu_Delay_X_c, real32_T rtu_Delay_X_l, const real32_T rtu_P[9], const
  real32_T rtu_H[3], real32_T rtu_Z, real32_T rtu_R,
  B_Correct_y_Translation_Fusio_T *localB, P_Correct_y_Translation_Fusio_T
  *localP)
{
  real32_T rtb_Gain_hg;
  real32_T rtb_Multiply1_e[3];
  real32_T rtu_Delay_X_0[3];
  real32_T rtu_H_0;
  int32_T i;
  int32_T i_0;
  real32_T rtb_Multiply1_p;
  int32_T Multiply5_tmp;
  int32_T Multiply5_tmp_0;
  if (rtu_Enable) {
    rtu_H_0 = 0.0F;
    for (i = 0; i < 3; i++) {
      rtu_H_0 += (rtu_P[3 * i + 2] * rtu_H[2] + (rtu_P[3 * i + 1] * rtu_H[1] +
        rtu_P[3 * i] * rtu_H[0])) * rtu_H[i];
    }

    rtb_Gain_hg = 1.0F / (rtu_H_0 + rtu_R);
    rtu_Delay_X_0[0] = rtu_Delay_X;
    rtu_Delay_X_0[1] = rtu_Delay_X_c;
    rtu_Delay_X_0[2] = rtu_Delay_X_l;
    rtu_H_0 = 0.0F;
    for (i = 0; i < 3; i++) {
      rtb_Multiply1_p = (rtu_P[i + 6] * rtu_H[2] + (rtu_P[i + 3] * rtu_H[1] +
        rtu_P[i] * rtu_H[0])) * rtb_Gain_hg;
      localB->fv0[i] = localP->Constant_Value[i] - rtb_Multiply1_p * rtu_H[0];
      localB->fv0[i + 3] = localP->Constant_Value[i + 3] - rtb_Multiply1_p *
        rtu_H[1];
      localB->fv0[i + 6] = localP->Constant_Value[i + 6] - rtb_Multiply1_p *
        rtu_H[2];
      for (i_0 = 0; i_0 < 3; i_0++) {
        Multiply5_tmp = i + 3 * i_0;
        localB->Multiply5[Multiply5_tmp] = 0.0F;
        Multiply5_tmp_0 = 3 * i_0 + i;
        localB->Multiply5[Multiply5_tmp] = localB->Multiply5[Multiply5_tmp_0] +
          rtu_P[3 * i_0] * localB->fv0[i];
        localB->Multiply5[Multiply5_tmp] = rtu_P[3 * i_0 + 1] * localB->fv0[i +
          3] + localB->Multiply5[Multiply5_tmp_0];
        localB->Multiply5[Multiply5_tmp] = rtu_P[3 * i_0 + 2] * localB->fv0[i +
          6] + localB->Multiply5[Multiply5_tmp_0];
      }

      rtu_H_0 += rtu_H[i] * rtu_Delay_X_0[i];
      rtb_Multiply1_e[i] = rtb_Multiply1_p;
    }

    rtu_H_0 = rtu_Z - rtu_H_0;
    if (rtu_H_0 > localP->Saturation2_UpperSat) {
      rtu_H_0 = localP->Saturation2_UpperSat;
    } else {
      if (rtu_H_0 < localP->Saturation2_LowerSat) {
        rtu_H_0 = localP->Saturation2_LowerSat;
      }
    }

    rtb_Gain_hg = localP->Gain_Gain * rtu_H_0;
    localB->Multiply[0] = rtb_Multiply1_e[0] * rtb_Gain_hg;
    localB->Multiply[1] = rtb_Multiply1_e[1] * rtb_Gain_hg;
    localB->Multiply[2] = rtb_Multiply1_e[2] * rtb_Gain_hg;
  }
}

void Translation_Fu_Correct_x_l_Init(B_Correct_x_Translation_Fus_o_T *localB,
  P_Correct_x_Translation_Fus_m_T *localP)
{
  int32_T i;
  localB->Multiply[0] = localP->X_Cor_Y0;
  localB->Multiply[1] = localP->X_Cor_Y0;
  localB->Multiply[2] = localP->X_Cor_Y0;
  for (i = 0; i < 9; i++) {
    localB->Multiply5[i] = localP->P_next_Y0;
  }
}

void Translation_Fusion_Correct_x_j(boolean_T rtu_Enable, real32_T rtu_Delay_X,
  real32_T rtu_Delay_X_j, real32_T rtu_Delay_X_d, const real32_T rtu_P[9], const
  real32_T rtu_H[3], real32_T rtu_Z, real32_T rtu_R,
  B_Correct_x_Translation_Fus_o_T *localB, P_Correct_x_Translation_Fus_m_T
  *localP)
{
  real32_T rtb_prefit_residual_g;
  real32_T rtb_Multiply1_d[3];
  real32_T rtu_Delay_X_0[3];
  real32_T rtu_H_0;
  int32_T i;
  int32_T i_0;
  real32_T rtb_Multiply1_o;
  int32_T Multiply5_tmp;
  int32_T Multiply5_tmp_0;
  if (rtu_Enable) {
    rtu_H_0 = 0.0F;
    for (i = 0; i < 3; i++) {
      rtu_H_0 += (rtu_P[3 * i + 2] * rtu_H[2] + (rtu_P[3 * i + 1] * rtu_H[1] +
        rtu_P[3 * i] * rtu_H[0])) * rtu_H[i];
    }

    rtb_prefit_residual_g = 1.0F / (rtu_H_0 + rtu_R);
    rtu_Delay_X_0[0] = rtu_Delay_X;
    rtu_Delay_X_0[1] = rtu_Delay_X_j;
    rtu_Delay_X_0[2] = rtu_Delay_X_d;
    rtu_H_0 = 0.0F;
    for (i = 0; i < 3; i++) {
      rtb_Multiply1_o = (rtu_P[i + 6] * rtu_H[2] + (rtu_P[i + 3] * rtu_H[1] +
        rtu_P[i] * rtu_H[0])) * rtb_prefit_residual_g;
      localB->fv0[i] = localP->Constant_Value[i] - rtb_Multiply1_o * rtu_H[0];
      localB->fv0[i + 3] = localP->Constant_Value[i + 3] - rtb_Multiply1_o *
        rtu_H[1];
      localB->fv0[i + 6] = localP->Constant_Value[i + 6] - rtb_Multiply1_o *
        rtu_H[2];
      for (i_0 = 0; i_0 < 3; i_0++) {
        Multiply5_tmp = i + 3 * i_0;
        localB->Multiply5[Multiply5_tmp] = 0.0F;
        Multiply5_tmp_0 = 3 * i_0 + i;
        localB->Multiply5[Multiply5_tmp] = localB->Multiply5[Multiply5_tmp_0] +
          rtu_P[3 * i_0] * localB->fv0[i];
        localB->Multiply5[Multiply5_tmp] = rtu_P[3 * i_0 + 1] * localB->fv0[i +
          3] + localB->Multiply5[Multiply5_tmp_0];
        localB->Multiply5[Multiply5_tmp] = rtu_P[3 * i_0 + 2] * localB->fv0[i +
          6] + localB->Multiply5[Multiply5_tmp_0];
      }

      rtu_H_0 += rtu_H[i] * rtu_Delay_X_0[i];
      rtb_Multiply1_d[i] = rtb_Multiply1_o;
    }

    rtb_prefit_residual_g = rtu_Z - rtu_H_0;
    localB->Multiply[0] = rtb_Multiply1_d[0] * rtb_prefit_residual_g;
    localB->Multiply[1] = rtb_Multiply1_d[1] * rtb_prefit_residual_g;
    localB->Multiply[2] = rtb_Multiply1_d[2] * rtb_prefit_residual_g;
  }
}

static void Translat_SystemCore_release_mt2(dsp_simulink_MovingAverag_e3x_T *obj)
{
  dsp_private_SlidingWindow_hgv_T *obj_0;
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    obj_0 = obj->pStatistic;
    if (obj_0->isInitialized == 1) {
      obj_0->isInitialized = 2;
    }

    obj->NumChannels = -1;
  }
}

static void Translati_SystemCore_delete_asm(dsp_simulink_MovingAverag_e3x_T *obj)
{
  Translat_SystemCore_release_mt2(obj);
}

static void matlabCodegenHandle_matlabC_goq(dsp_simulink_MovingAverag_e3x_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    Translati_SystemCore_delete_asm(obj);
  }
}

void Translation_MovingAverage3_Init(DW_MovingAverage3_Translation_T *localDW)
{
  int32_T i;
  if (localDW->obj.pStatistic->isInitialized == 1) {
    localDW->obj.pStatistic->pCumSum = 0.0F;
    for (i = 0; i < 7; i++) {
      localDW->obj.pStatistic->pCumSumRev[i] = 0.0F;
    }

    localDW->obj.pStatistic->pCumRevIndex = 1.0F;
  }
}

void Translatio_MovingAverage3_Reset(DW_MovingAverage3_Translation_T *localDW)
{
  int32_T i;
  if (localDW->obj.pStatistic->isInitialized == 1) {
    localDW->obj.pStatistic->pCumSum = 0.0F;
    for (i = 0; i < 7; i++) {
      localDW->obj.pStatistic->pCumSumRev[i] = 0.0F;
    }

    localDW->obj.pStatistic->pCumRevIndex = 1.0F;
  }
}

void Translatio_MovingAverage3_Start(DW_MovingAverage3_Translation_T *localDW)
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

void Translation_Fusi_MovingAverage3(real32_T rtu_0,
  B_MovingAverage3_Translation__T *localB, DW_MovingAverage3_Translation_T
  *localDW)
{
  real32_T cumRevIndex;
  real32_T csum;
  real32_T csumrev[7];
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
    for (z_tmp = 0; z_tmp < 7; z_tmp++) {
      localDW->obj.pStatistic->pCumSumRev[z_tmp] = 0.0F;
      localDW->obj.pStatistic->pCumSumRev[z_tmp] = 0.0F;
    }

    localDW->obj.pStatistic->pCumRevIndex = 1.0F;
  }

  cumRevIndex = localDW->obj.pStatistic->pCumRevIndex;
  csum = localDW->obj.pStatistic->pCumSum;
  for (z_tmp = 0; z_tmp < 7; z_tmp++) {
    csumrev[z_tmp] = localDW->obj.pStatistic->pCumSumRev[z_tmp];
  }

  csum += rtu_0;
  z_tmp = (int32_T)cumRevIndex - 1;
  z = csumrev[z_tmp] + csum;
  csumrev[z_tmp] = rtu_0;
  if (cumRevIndex != 7.0F) {
    cumRevIndex++;
  } else {
    cumRevIndex = 1.0F;
    csum = 0.0F;
    for (z_tmp = 5; z_tmp >= 0; z_tmp--) {
      csumrev[z_tmp] += csumrev[z_tmp + 1];
    }
  }

  localDW->obj.pStatistic->pCumSum = csum;
  for (z_tmp = 0; z_tmp < 7; z_tmp++) {
    localDW->obj.pStatistic->pCumSumRev[z_tmp] = csumrev[z_tmp];
  }

  localDW->obj.pStatistic->pCumRevIndex = cumRevIndex;
  localB->MovingAverage3 = z / 8.0F;
}

void Translation_MovingAverage3_Term(DW_MovingAverage3_Translation_T *localDW)
{
  matlabCodegenHandle_matlabC_goq(&localDW->obj);
}

static void Transla_SystemCore_release_mt2c(dsp_simulink_MovingAvera_e3xk_T *obj)
{
  dsp_private_SlidingWindo_hgvz_T *obj_0;
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    obj_0 = obj->pStatistic;
    if (obj_0->isInitialized == 1) {
      obj_0->isInitialized = 2;
    }

    obj->NumChannels = -1;
  }
}

static void Translat_SystemCore_delete_asmv(dsp_simulink_MovingAvera_e3xk_T *obj)
{
  Transla_SystemCore_release_mt2c(obj);
}

static void matlabCodegenHandle_matlab_goqu(dsp_simulink_MovingAvera_e3xk_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    Translat_SystemCore_delete_asmv(obj);
  }
}

void Translation_MovingAverage1_Init(DW_MovingAverage1_Translation_T *localDW)
{
  if (localDW->obj.pStatistic->isInitialized == 1) {
    localDW->obj.pStatistic->pCumSum = 0.0F;
    memset(&localDW->obj.pStatistic->pCumSumRev[0], 0, 39U * sizeof(real32_T));
    localDW->obj.pStatistic->pCumRevIndex = 1.0F;
  }
}

void Translatio_MovingAverage1_Reset(DW_MovingAverage1_Translation_T *localDW)
{
  if (localDW->obj.pStatistic->isInitialized == 1) {
    localDW->obj.pStatistic->pCumSum = 0.0F;
    memset(&localDW->obj.pStatistic->pCumSumRev[0], 0, 39U * sizeof(real32_T));
    localDW->obj.pStatistic->pCumRevIndex = 1.0F;
  }
}

void Translatio_MovingAverage1_Start(DW_MovingAverage1_Translation_T *localDW)
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

void Translation_Fusi_MovingAverage1(real32_T rtu_0,
  B_MovingAverage1_Translation__T *localB, DW_MovingAverage1_Translation_T
  *localDW)
{
  real32_T cumRevIndex;
  real32_T csum;
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
    memset(&localDW->obj.pStatistic->pCumSumRev[0], 0, 39U * sizeof(real32_T));
    localDW->obj.pStatistic->pCumRevIndex = 1.0F;
  }

  cumRevIndex = localDW->obj.pStatistic->pCumRevIndex;
  csum = localDW->obj.pStatistic->pCumSum;
  for (z_tmp = 0; z_tmp < 39; z_tmp++) {
    localB->csumrev[z_tmp] = localDW->obj.pStatistic->pCumSumRev[z_tmp];
  }

  csum += rtu_0;
  z_tmp = (int32_T)cumRevIndex - 1;
  z = localB->csumrev[z_tmp] + csum;
  localB->csumrev[z_tmp] = rtu_0;
  if (cumRevIndex != 39.0F) {
    cumRevIndex++;
  } else {
    cumRevIndex = 1.0F;
    csum = 0.0F;
    for (z_tmp = 37; z_tmp >= 0; z_tmp--) {
      localB->csumrev[z_tmp] += localB->csumrev[z_tmp + 1];
    }
  }

  localDW->obj.pStatistic->pCumSum = csum;
  memcpy(&localDW->obj.pStatistic->pCumSumRev[0], &localB->csumrev[0], 39U *
         sizeof(real32_T));
  localDW->obj.pStatistic->pCumRevIndex = cumRevIndex;
  localB->MovingAverage1 = z / 40.0F;
}

void Translation_MovingAverage1_Term(DW_MovingAverage1_Translation_T *localDW)
{
  matlabCodegenHandle_matlab_goqu(&localDW->obj);
}

static void Transl_SystemCore_release_mt2c4(dsp_simulink_MovingAver_e3xkx_T *obj)
{
  dsp_private_SlidingWind_hgvzv_T *obj_0;
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    obj_0 = obj->pStatistic;
    if (obj_0->isInitialized == 1) {
      obj_0->isInitialized = 2;
    }

    obj->NumChannels = -1;
  }
}

static void Transla_SystemCore_delete_asmvp(dsp_simulink_MovingAver_e3xkx_T *obj)
{
  Transl_SystemCore_release_mt2c4(obj);
}

static void matlabCodegenHandle_matla_goquh(dsp_simulink_MovingAver_e3xkx_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    Transla_SystemCore_delete_asmvp(obj);
  }
}

void Translati_MovingAverage1_a_Init(DW_MovingAverage1_Translati_f_T *localDW)
{
  if (localDW->obj.pStatistic->isInitialized == 1) {
    localDW->obj.pStatistic->pCumSum = 0.0F;
    memset(&localDW->obj.pStatistic->pCumSumRev[0], 0, 99U * sizeof(real32_T));
    localDW->obj.pStatistic->pCumRevIndex = 1.0F;
  }
}

void Translat_MovingAverage1_o_Reset(DW_MovingAverage1_Translati_f_T *localDW)
{
  if (localDW->obj.pStatistic->isInitialized == 1) {
    localDW->obj.pStatistic->pCumSum = 0.0F;
    memset(&localDW->obj.pStatistic->pCumSumRev[0], 0, 99U * sizeof(real32_T));
    localDW->obj.pStatistic->pCumRevIndex = 1.0F;
  }
}

void Translat_MovingAverage1_p_Start(DW_MovingAverage1_Translati_f_T *localDW)
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

void Translation_Fu_MovingAverage1_p(real32_T rtu_0,
  B_MovingAverage1_Translatio_c_T *localB, DW_MovingAverage1_Translati_f_T
  *localDW)
{
  real32_T cumRevIndex;
  real32_T csum;
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
    memset(&localDW->obj.pStatistic->pCumSumRev[0], 0, 99U * sizeof(real32_T));
    localDW->obj.pStatistic->pCumRevIndex = 1.0F;
  }

  cumRevIndex = localDW->obj.pStatistic->pCumRevIndex;
  csum = localDW->obj.pStatistic->pCumSum;
  for (z_tmp = 0; z_tmp < 99; z_tmp++) {
    localB->csumrev[z_tmp] = localDW->obj.pStatistic->pCumSumRev[z_tmp];
  }

  csum += rtu_0;
  z_tmp = (int32_T)cumRevIndex - 1;
  z = localB->csumrev[z_tmp] + csum;
  localB->csumrev[z_tmp] = rtu_0;
  if (cumRevIndex != 99.0F) {
    cumRevIndex++;
  } else {
    cumRevIndex = 1.0F;
    csum = 0.0F;
    for (z_tmp = 97; z_tmp >= 0; z_tmp--) {
      localB->csumrev[z_tmp] += localB->csumrev[z_tmp + 1];
    }
  }

  localDW->obj.pStatistic->pCumSum = csum;
  memcpy(&localDW->obj.pStatistic->pCumSumRev[0], &localB->csumrev[0], 99U *
         sizeof(real32_T));
  localDW->obj.pStatistic->pCumRevIndex = cumRevIndex;
  localB->MovingAverage1 = z / 100.0F;
}

void Translati_MovingAverage1_g_Term(DW_MovingAverage1_Translati_f_T *localDW)
{
  matlabCodegenHandle_matla_goquh(&localDW->obj);
}

static void Translation_Fusi_rt_invf2x2_snf(const real32_T u[4], real32_T y[4])
{
  if ((real32_T)fabs(u[1]) > (real32_T)fabs(u[0])) {
    Translation_Fusion_B.r = u[0] / u[1];
    Translation_Fusion_B.t = 1.0F / (Translation_Fusion_B.r * u[3] - u[2]);
    y[0] = u[3] / u[1] * Translation_Fusion_B.t;
    y[1] = -Translation_Fusion_B.t;
    y[2] = -u[2] / u[1] * Translation_Fusion_B.t;
    y[3] = Translation_Fusion_B.r * Translation_Fusion_B.t;
  } else {
    Translation_Fusion_B.r = u[1] / u[0];
    Translation_Fusion_B.t = 1.0F / (u[3] - Translation_Fusion_B.r * u[2]);
    y[0] = u[3] / u[0] * Translation_Fusion_B.t;
    y[1] = -Translation_Fusion_B.r * Translation_Fusion_B.t;
    y[2] = -u[2] / u[0] * Translation_Fusion_B.t;
    y[3] = Translation_Fusion_B.t;
  }
}

static void Tran_SystemCore_release_mt2c4ip(dsp_simulink_MovingAve_e3xkxm_T *obj)
{
  dsp_private_SlidingWin_hgvzvy_T *obj_0;
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    obj_0 = obj->pStatistic;
    if (obj_0->isInitialized == 1) {
      obj_0->isInitialized = 2;
    }

    obj->NumChannels = -1;
  }
}

static void Trans_SystemCore_delete_asmvpfi(dsp_simulink_MovingAve_e3xkxm_T *obj)
{
  Tran_SystemCore_release_mt2c4ip(obj);
}

static void matlabCodegenHandle_mat_goquh1b(dsp_simulink_MovingAve_e3xkxm_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    Trans_SystemCore_delete_asmvpfi(obj);
  }
}

static void Trans_SystemCore_release_mt2c4i(dsp_simulink_MovingAver_e3xkx_T *obj)
{
  dsp_private_SlidingWind_hgvzv_T *obj_0;
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    obj_0 = obj->pStatistic;
    if (obj_0->isInitialized == 1) {
      obj_0->isInitialized = 2;
    }

    obj->NumChannels = -1;
  }
}

static void Transl_SystemCore_delete_asmvpf(dsp_simulink_MovingAver_e3xkx_T *obj)
{
  Trans_SystemCore_release_mt2c4i(obj);
}

static void matlabCodegenHandle_matl_goquh1(dsp_simulink_MovingAver_e3xkx_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    Transl_SystemCore_delete_asmvpf(obj);
  }
}

static void Tra_SystemCore_release_mt2c4ipi(dsp_simulink_MovingAv_e3xkxms_T *obj)
{
  dsp_private_SlidingWi_hgvzvyp_T *obj_0;
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    obj_0 = obj->pStatistic;
    if (obj_0->isInitialized == 1) {
      obj_0->isInitialized = 2;
    }

    obj->NumChannels = -1;
  }
}

static void Tran_SystemCore_delete_asmvpfiv(dsp_simulink_MovingAv_e3xkxms_T *obj)
{
  Tra_SystemCore_release_mt2c4ipi(obj);
}

static void matlabCodegenHandle_ma_goquh1bj(dsp_simulink_MovingAv_e3xkxms_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    Tran_SystemCore_delete_asmvpfiv(obj);
  }
}

void Translation_Fusion_Init(real32_T *rty_Vx_cor)
{
  int32_T i;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE =
    Translation_Fusion_P_g.DiscreteTimeIntegrator_IC;
  Translation_Fusion_DW.Delay2_DSTATE_h[0] =
    Translation_Fusion_P_g.Delay2_InitialCondition_h;
  Translation_Fusion_DW.Delay2_DSTATE_h[1] =
    Translation_Fusion_P_g.Delay2_InitialCondition_h;
  Translation_Fusion_DW.Delay1_DSTATE[0] =
    Translation_Fusion_P_g.Delay1_InitialCondition_i;
  Translation_Fusion_DW.Delay1_DSTATE[1] =
    Translation_Fusion_P_g.Delay1_InitialCondition_i;
  Translation_Fusion_DW.Delay1_DSTATE[2] =
    Translation_Fusion_P_g.Delay1_InitialCondition_i;
  Translation_Fusion_DW.Delay1_DSTATE[3] =
    Translation_Fusion_P_g.Delay1_InitialCondition_i;
  Translation_Fusion_DW.icLoad = 1U;
  Translation_Fusion_DW.Delay_10_DSTATE[0] =
    Translation_Fusion_P_g.Delay_10_InitialCondition;
  Translation_Fusion_DW.Delay_10_DSTATE[1] =
    Translation_Fusion_P_g.Delay_10_InitialCondition;
  Translation_Fusion_DW.Delay_2_DSTATE =
    Translation_Fusion_P_g.Delay_2_InitialCondition;
  Translation_Fusion_DW.DelayInput1_DSTATE_g =
    Translation_Fusion_P_g.DetectRisePositive3_vinit;
  Translation_Fusion_DW.DelayInput1_DSTATE_k3 =
    Translation_Fusion_P_g.DetectRisePositive2_vinit;
  Translation_Fusion_DW.memory1_PreviousInput[0] =
    Translation_Fusion_P_g.memory1_InitialCondition;
  Translation_Fusion_DW.memory1_PreviousInput[1] =
    Translation_Fusion_P_g.memory1_InitialCondition;
  Translation_Fusion_DW.memory1_PreviousInput[2] =
    Translation_Fusion_P_g.memory1_InitialCondition;
  Translation_Fusion_DW.DelayInput1_DSTATE_g3 =
    Translation_Fusion_P_g.DetectIncrease_vinit_a;
  Translation_Fusion_DW.DelayInput1_DSTATE_ku =
    Translation_Fusion_P_g.DetectIncrease1_vinit;
  Translation_Fusion_DW.DelayInput1_DSTATE_e =
    Translation_Fusion_P_g.DetectIncrease2_vinit;
  for (i = 0; i < 10; i++) {
    Translation_Fusion_DW.Delay_DSTATE_g[i] =
      Translation_Fusion_P_g.Delay_InitialCondition_l;
  }

  Translation_Fusion_DW.memory_PreviousInput[0] =
    Translation_Fusion_P_g.memory_InitialCondition;
  Translation_Fusion_DW.memory_PreviousInput[1] =
    Translation_Fusion_P_g.memory_InitialCondition;
  Translation_Fusion_DW.memory_PreviousInput[2] =
    Translation_Fusion_P_g.memory_InitialCondition;
  Translation_Fusion_DW.UnitDelay_DSTATE_p =
    Translation_Fusion_P_g.UnitDelay_InitialCondition_f;
  Translation_Fusion_DW.icLoad_k = 1U;
  Translation_Fusion_DW.DelayInput1_DSTATE_bh =
    Translation_Fusion_P_g.DetectIncrease1_vinit_h;
  Translation_Fusion_DW.Delay1_DSTATE_l =
    Translation_Fusion_P_g.Delay1_InitialCondition_p;
  Translation_Fusion_DW.icLoad_ki = 1U;
  Translation_Fusion_DW.icLoad_h = 1U;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE_k =
    Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_e;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE_g =
    Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_c;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_k0 =
    Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_a;
  Translation_Fusion_DW.DiscreteTimeIntegrator_IC_LOADI = 1U;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE_p =
    Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_l;
  Translation_Fusion_DW.DelayInput1_DSTATE_k2 =
    Translation_Fusion_P_g.DetectIncrease_vinit;
  Translation_Fusion_DW.DiscreteTimeIntegrator1_DSTATE =
    Translation_Fusion_P_g.DiscreteTimeIntegrator1_IC;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE_n =
    Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_p;
  Translation_Fusion_DW.DelayInput1_DSTATE =
    Translation_Fusion_P_g.DetectUpdate1_vinit;
  Translation_Fusion_DW.Delay_DSTATE_k =
    Translation_Fusion_P_g.Delay_InitialCondition_kg;
  Translation_Fusion_DW.DiscreteTimeIntegrator_IC_LOA_p = 1U;
  Translation_Fusion_DW.Delay_DSTATE_p2 =
    Translation_Fusion_P_g.Delay_InitialCondition_i0;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE_h =
    Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_g;
  Translation_Fusion_DW.Delay_DSTATE_o5 =
    Translation_Fusion_P_g.Delay_InitialCondition_ib;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_ax =
    Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_k;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE_f =
    Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_lj;
  Translation_Fusion_DW.Delay_DSTATE_d =
    Translation_Fusion_P_g.Delay_InitialCondition_b2;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_nz =
    Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_o;
  Translation_Fusion_DW.Delay_DSTATE_db =
    Translation_Fusion_P_g.Delay_InitialCondition_n2;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_a3 =
    Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_d;
  Translation_Fusion_DW.Delay_DSTATE_c =
    Translation_Fusion_P_g.Delay_InitialCondition_jx;
  Translation_Fusion_DW.DiscreteTimeIntegrator1_DSTAT_k =
    Translation_Fusion_P_g.DiscreteTimeIntegrator1_IC_j;
  Translation_Fusion_DW.Delay_DSTATE_h =
    Translation_Fusion_P_g.Delay_InitialCondition_lu;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_pp =
    Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_n;
  Translation_Fusion_DW.DiscreteTimeIntegrator1_DSTAT_a =
    Translation_Fusion_P_g.DiscreteTimeIntegrator1_IC_js;
  Translation_Fusion_DW.Delay_DSTATE_ch =
    Translation_Fusion_P_g.Delay_InitialCondition_mv;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_o4 =
    Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_i;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE_e =
    Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_cm;
  Translation_Fusion_DW.DiscreteTimeIntegrator_IC_LOA_a = 1U;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_hu =
    Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_ce;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE_j =
    Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_f;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_hc =
    Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_f3;
  Translation_Fusion_DW.DelayInput1_DSTATE_a =
    Translation_Fusion_P_g.DetectUpdate1_vinit_e;
  Translation_Fusion_DW.Delay_DSTATE_jd =
    Translation_Fusion_P_g.Delay_InitialCondition_h;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE_c =
    Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_m;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_ag =
    Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_f33;
  Translation_Fusion_DW.DelayInput1_DSTATE_p =
    Translation_Fusion_P_g.DetectChange_vinit;
  Translation_Fusion_DW.icLoad_g = 1U;
  Translation_Fusion_DW.icLoad_kg = 1U;
  Translation_Fusion_DW.DelayInput1_DSTATE_n =
    Translation_Fusion_P_g.DetectIncrease_vinit_k;
  Translation_Fusion_DW.Memory_PreviousInput =
    Translation_Fusion_P_g.Memory_InitialCondition;
  Translation_Fusion_DW.DelayInput1_DSTATE_j =
    Translation_Fusion_P_g.DetectChange_vinit_d;
  Translation_Fusion_DW.Delay_DSTATE_d4 =
    Translation_Fusion_P_g.Delay_InitialCondition_k1;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_gk =
    Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_gn;
  Translation_Fusion_DW.Memory1_PreviousInput =
    Translation_Fusion_P_g.Memory1_InitialCondition;
  Translation_Fusion_DW.Delay_DSTATE_jg =
    Translation_Fusion_P_g.Delay_InitialCondition_jp;
  Translation_Fusion_DW.Delay1_DSTATE_o[0] =
    Translation_Fusion_P_g.Delay1_InitialCondition_hr;
  Translation_Fusion_DW.Delay1_DSTATE_b0[0] =
    Translation_Fusion_P_g.Delay1_InitialCondition_j;
  Translation_Fusion_DW.Delay1_DSTATE_o[1] =
    Translation_Fusion_P_g.Delay1_InitialCondition_hr;
  Translation_Fusion_DW.Delay1_DSTATE_b0[1] =
    Translation_Fusion_P_g.Delay1_InitialCondition_j;
  Translation_Fusion_DW.Memory_PreviousInput_o =
    Translation_Fusion_P_g.Memory_InitialCondition_k;
  Translation_Fusion_DW.DiscreteTimeIntegrator_IC_LOA_b = 1U;
  Translation_Fusion_DW.DiscreteTimeIntegrator_PrevR_hj = 2;
  Translation_Fusion_DW.DiscreteTimeIntegrator1_DSTAT_h[0] =
    Translation_Fusion_P_g.DiscreteTimeIntegrator1_IC_n;
  Translation_Fusion_DW.DiscreteTimeIntegrator1_DSTAT_h[1] =
    Translation_Fusion_P_g.DiscreteTimeIntegrator1_IC_n;
  Translation_Fusion_DW.DiscreteTimeIntegrator1_DSTAT_h[2] =
    Translation_Fusion_P_g.DiscreteTimeIntegrator1_IC_n;
  Translation_Fusion_DW.DelayInput1_DSTATE_j3 =
    Translation_Fusion_P_g.DetectIncrease_vinit_h;
  Translation_Fusion_DW.UD_DSTATE =
    Translation_Fusion_P_g.Difference_ICPrevInput;
  Translation_Fusion_DW.DiscreteTimeIntegrator5_DSTATE =
    Translation_Fusion_P_g.DiscreteTimeIntegrator5_IC;
  Translation_Fusion_DW.DiscreteTimeIntegrator5_DSTAT_d =
    Translation_Fusion_P_g.DiscreteTimeIntegrator5_IC_l;
  Translation_Fusion_DW.Delay_DSTATE_k1 =
    Translation_Fusion_P_g.Delay_InitialCondition_o1;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_fa =
    Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_eg;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE_m =
    Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_ku;
  Translation_Fusion_DW.Delay_DSTATE_n =
    Translation_Fusion_P_g.Delay_InitialCondition_f;
  Translation_Fusion_DW.Delay2_DSTATE[0] =
    Translation_Fusion_P_g.Delay2_InitialCondition;
  Translation_Fusion_DW.Delay2_DSTATE_a[0] =
    Translation_Fusion_P_g.Delay2_InitialCondition_f;
  Translation_Fusion_DW.Delay3_DSTATE[0] =
    Translation_Fusion_P_g.Delay3_InitialCondition;
  Translation_Fusion_DW.Delay1_DSTATE_c[0] =
    Translation_Fusion_P_g.Delay1_InitialCondition_dl;
  Translation_Fusion_DW.Delay2_DSTATE[1] =
    Translation_Fusion_P_g.Delay2_InitialCondition;
  Translation_Fusion_DW.Delay2_DSTATE_a[1] =
    Translation_Fusion_P_g.Delay2_InitialCondition_f;
  Translation_Fusion_DW.Delay3_DSTATE[1] =
    Translation_Fusion_P_g.Delay3_InitialCondition;
  Translation_Fusion_DW.Delay1_DSTATE_c[1] =
    Translation_Fusion_P_g.Delay1_InitialCondition_dl;
  for (i = 0; i < 200; i++) {
    Translation_Fusion_DW.Delay_DSTATE_o[i] =
      Translation_Fusion_P_g.Delay_InitialCondition_o;
  }

  Translation_Fusion_DW.DiscreteTimeIntegrator_IC_LO_aj = 1U;
  Translation_Fusion_DW.icLoad_gb = 1U;
  Translation_Fusion_DW.Delay_DSTATE_o1 =
    Translation_Fusion_P_g.Delay_InitialCondition_mb;
  Translation_Fusion_DW.Delay_DSTATE_of =
    Translation_Fusion_P_g.Delay_InitialCondition_b;
  Translation_Fusion_DW.Delay1_DSTATE_nb =
    Translation_Fusion_P_g.Delay1_InitialCondition_di;
  Translation_Fusion_DW.DelayInput1_DSTATE_o =
    Translation_Fusion_P_g.DetectIncrease_vinit_ax;
  Translation_Fusion_DW.Delay_DSTATE_pi =
    Translation_Fusion_P_g.Delay_InitialCondition_d5;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_ab =
    Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_pc;
  Translation_Fusion_DW.Delay1_DSTATE_g =
    Translation_Fusion_P_g.Delay1_InitialCondition_d;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_gt =
    Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_a3;
  Translation_Fusion_DW.DelayInput1_DSTATE_f =
    Translation_Fusion_P_g.DetectIncrease_vinit_kk;
  Translation_Fusion_DW.icLoad_gm = 1U;
  Translation_Fusion_DW.DelayInput1_DSTATE_k =
    Translation_Fusion_P_g.DetectUpdate_vinit;
  Translation_Fusion_DW.Delay_DSTATE_l =
    Translation_Fusion_P_g.Delay_InitialCondition_al;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_ai =
    Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_b;
  Translation_Fusion_DW.Delay_DSTATE_by =
    Translation_Fusion_P_g.Delay_InitialCondition_e;
  Translation_Fusion_DW.icLoad_d = 1U;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_eb =
    Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_d1;
  Translation_Fusion_DW.DiscreteTimeIntegrator_PrevR_jg = 2;
  Translation_Fusion_DW.DiscreteTimeIntegrator_IC_LOA_f = 1U;
  Translation_Fusion_DW.DiscreteTimeIntegrator_IC_LOA_k = 1U;
  Translation_Fusion_DW.DiscreteTimeIntegrator_IC_LOA_m = 1U;
  Translation_Fusion_DW.DiscreteTimeIntegrator_IC_LO_ae = 1U;
  Translation_Fusion_DW.DiscreteTimeIntegrator_PrevRe_o = 2;
  Translation_Fusion_DW.DiscreteTimeIntegrator1_IC_LOAD = 1U;
  Translation_Fusion_DW.Delay_DSTATE_f =
    Translation_Fusion_P_g.Delay_InitialCondition_d;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE_l =
    Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_io;
  Translation_Fusion_DW.Memory_PreviousInput_o3 =
    Translation_Fusion_P_g.Memory_InitialCondition_n4;
  Translation_Fusion_DW.DiscreteTimeIntegrator1_DSTA_hw =
    Translation_Fusion_P_g.DiscreteTimeIntegrator1_IC_l;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_lb =
    Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_pp;
  Translation_Fusion_DW.DiscreteTimeIntegrator1_DSTAT_b =
    Translation_Fusion_P_g.DiscreteTimeIntegrator1_IC_nx;
  Translation_Fusion_DW.DiscreteTimeIntegrator_IC_LO_fn = 1U;
  Translation_Fusion_DW.Delay_DSTATE_p =
    Translation_Fusion_P_g.Delay_InitialCondition_p;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_pa =
    Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_kux;
  Translation_Fusion_DW.DiscreteTimeIntegrator1_DSTA_fe =
    Translation_Fusion_P_g.DiscreteTimeIntegrator1_IC_p;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_a0 =
    Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_j;
  Translation_Fusion_DW.DiscreteTimeIntegrator1_DSTAT_g =
    Translation_Fusion_P_g.DiscreteTimeIntegrator1_IC_m;
  Translation_Fusion_DW.DiscreteTimeIntegrator1_IC_LO_n = 1U;
  Translation_Fusion_DW.Delay1_DSTATE_f[0] =
    Translation_Fusion_P_g.Delay1_InitialCondition_e;
  Translation_Fusion_DW.DiscreteTimeIntegrator1_DSTAT_f[0] =
    Translation_Fusion_P_g.DiscreteTimeIntegrator1_IC_a;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTA_gt3[0] =
    Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_ll;
  Translation_Fusion_DW.Delay1_DSTATE_f[1] =
    Translation_Fusion_P_g.Delay1_InitialCondition_e;
  Translation_Fusion_DW.DiscreteTimeIntegrator1_DSTAT_f[1] =
    Translation_Fusion_P_g.DiscreteTimeIntegrator1_IC_a;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTA_gt3[1] =
    Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_ll;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_n4 =
    Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_h;
  Translation_Fusion_DW.DiscreteTimeIntegrator_IC_LO_fw = 1U;
  Translation_Fusion_DW.DelayInput1_DSTATE_ey =
    Translation_Fusion_P_g.DetectIncrease_vinit_f;
  Translation_Fusion_DW.DelayInput1_DSTATE_nj =
    Translation_Fusion_P_g.DetectIncrease_vinit_iv;
  Translation_Fusion_DW.Delay1_DSTATE_k1 =
    Translation_Fusion_P_g.Delay1_InitialCondition_oq;
  Translation_Fusion_DW.Delay_DSTATE_pu =
    Translation_Fusion_P_g.Delay_InitialCondition_ps;
  Translation_Fusion_DW.DelayInput1_DSTATE_d =
    Translation_Fusion_P_g.DetectIncrease1_vinit_b;
  Translation_Fusion_DW.DiscreteTimeIntegrator5_DSTAT_g =
    Translation_Fusion_P_g.DiscreteTimeIntegrator5_IC_c;
  Translation_Fusion_DW.DiscreteTimeIntegrator5_DSTAT_j =
    Translation_Fusion_P_g.DiscreteTimeIntegrator5_IC_l3;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE_b =
    Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_ao;
  Translation_Fusion_DW.DiscreteTimeIntegrator1_DSTAT_d =
    Translation_Fusion_P_g.DiscreteTimeIntegrator1_IC_f;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_ak =
    Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_dh;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_ce =
    Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_db;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_ct =
    Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_lc;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_bn =
    Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_hd;
  Translation_Fusion_DW.DiscreteTimeIntegrator1_DSTAT_c =
    Translation_Fusion_P_g.DiscreteTimeIntegrator1_IC_f2;
  Translation_Fusion_DW.DiscreteTimeIntegrator1_DSTA_l2 =
    Translation_Fusion_P_g.DiscreteTimeIntegrator1_IC_d;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_jp =
    Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_hv;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_eh =
    Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_aj;
  Translation_Fusion_DW.DiscreteTimeIntegrator1_DSTA_hj =
    Translation_Fusion_P_g.DiscreteTimeIntegrator1_IC_jh;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_hp =
    Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_jv;
  Translation_Fusion_DW.DiscreteTimeIntegrator1_DSTAT_m =
    Translation_Fusion_P_g.DiscreteTimeIntegrator1_IC_e;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_pd =
    Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_je;
  Translation_Fusion_DW.DiscreteTimeIntegrator1_DSTAT_p =
    Translation_Fusion_P_g.DiscreteTimeIntegrator1_IC_i;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_dc =
    Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_jp;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_bo =
    Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_kt;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_ka =
    Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_ng;
  Translation_Fusion_DW.DiscreteTimeIntegrator1_DSTA_na =
    Translation_Fusion_P_g.DiscreteTimeIntegrator1_IC_pg;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_dv =
    Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_li;
  Translation_Fusion_DW.DiscreteTimeIntegrator1_DSTA_hy =
    Translation_Fusion_P_g.DiscreteTimeIntegrator1_IC_fa;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_n2 =
    Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_bz;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_jr =
    Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_eh;
  Translation_Fusion_DW.DiscreteTimeIntegrator1_DSTA_lz =
    Translation_Fusion_P_g.DiscreteTimeIntegrator1_IC_lf;
  Translation_Fusion_DW.Delay_DSTATE_kd =
    Translation_Fusion_P_g.Delay_InitialCondition_lg;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_ny =
    Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_oy;
  Translation_Fusion_DW.Delay1_DSTATE_d[0] =
    Translation_Fusion_P_g.Delay1_InitialCondition_o[0];
  Translation_Fusion_DW.Delay1_DSTATE_d[1] =
    Translation_Fusion_P_g.Delay1_InitialCondition_o[1];
  Translation_Fusion_DW.Delay1_DSTATE_d[2] =
    Translation_Fusion_P_g.Delay1_InitialCondition_o[2];
  Translation_Fusion_DW.Delay1_DSTATE_d[3] =
    Translation_Fusion_P_g.Delay1_InitialCondition_o[3];
  Translation_Fusion_DW.icLoad_f = 1U;
  for (i = 0; i < 9; i++) {
    Translation_Fusion_DW.Delay2_DSTATE_l[i] =
      Translation_Fusion_P_g.Delay2_InitialCondition_i;
  }

  Translation_Fusion_DW.DiscreteTimeIntegrator1_DSTA_gu =
    Translation_Fusion_P_g.DiscreteTimeIntegrator1_IC_p4;
  Translation_Fusion_DW.DiscreteTimeIntegrator1_DSTAT_e =
    Translation_Fusion_P_g.DiscreteTimeIntegrator1_IC_nw;
  Translation_Fusion_DW.DelayInput1_DSTATE_ap =
    Translation_Fusion_P_g.DetectChange_vinit_g;
  Translation_Fusion_DW.DelayInput1_DSTATE_jf =
    Translation_Fusion_P_g.DetectIncrease_vinit_g;
  Translation_Fusion_DW.DelayInput1_DSTATE_b =
    Translation_Fusion_P_g.DetectChange_vinit_o;
  Translation_Fusion_DW.Delay_DSTATE_e =
    Translation_Fusion_P_g.Delay_InitialCondition_c;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_bc =
    Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_ir;
  Translation_Fusion_DW.icLoad_d1 = 1U;
  Translation_Fusion_DW.icLoad_o = 1U;
  Translation_Fusion_DW.Delay_DSTATE_ev =
    Translation_Fusion_P_g.Delay_InitialCondition_fp;
  Translation_Fusion_DW.UnitDelay_DSTATE[0] =
    Translation_Fusion_P_g.UnitDelay_InitialCondition;
  Translation_Fusion_DW.Memory_PreviousInput_h[0] =
    Translation_Fusion_P_g.Memory_InitialCondition_h;
  Translation_Fusion_DW.Memory1_PreviousInput_c[0] =
    Translation_Fusion_P_g.Memory1_InitialCondition_f;
  Translation_Fusion_DW.Delay1_DSTATE_ci[0] =
    Translation_Fusion_P_g.Delay1_InitialCondition_lq;
  Translation_Fusion_DW.UnitDelay_DSTATE[1] =
    Translation_Fusion_P_g.UnitDelay_InitialCondition;
  Translation_Fusion_DW.Memory_PreviousInput_h[1] =
    Translation_Fusion_P_g.Memory_InitialCondition_h;
  Translation_Fusion_DW.Memory1_PreviousInput_c[1] =
    Translation_Fusion_P_g.Memory1_InitialCondition_f;
  Translation_Fusion_DW.Delay1_DSTATE_ci[1] =
    Translation_Fusion_P_g.Delay1_InitialCondition_lq;
  Translation_Fusion_DW.icLoad_c = 1U;
  Translation_Fusion_DW.icLoad_j = 1U;
  Translation_Fusion_DW.UnitDelay1_DSTATE[0] =
    Translation_Fusion_P_g.UnitDelay1_InitialCondition;
  Translation_Fusion_DW.UnitDelay1_DSTATE[1] =
    Translation_Fusion_P_g.UnitDelay1_InitialCondition;
  Translation_Fusion_DW.UnitDelay1_DSTATE[2] =
    Translation_Fusion_P_g.UnitDelay1_InitialCondition;
  Translation_Fusion_DW.DiscreteTimeIntegrator_IC_LOA_d = 1U;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_lv =
    Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_oo;
  Translation_Fusion_DW.DiscreteTimeIntegrator_IC_LOA_i = 1U;
  Translation_Fusion_DW.DiscreteTimeIntegrator_IC_LOA_o = 1U;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_oy =
    Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_f2;
  Translation_Fusion_DW.DiscreteTimeIntegrator_IC_LOA_h = 1U;
  Translation_Fusion_DW.DiscreteTimeIntegrator_IC_LO_oj = 1U;
  Translation_Fusion_DW.DiscreteTimeIntegrator_IC_LO_fm = 1U;
  Translation_Fusion_DW.DelayInput1_DSTATE_p1 =
    Translation_Fusion_P_g.DetectIncrease_vinit_i;
  Translation_Fusion_DW.UnitDelay_DSTATE_h =
    Translation_Fusion_P_g.UnitDelay_InitialCondition_e;
  Translation_Fusion_DW.Delay1_DSTATE_ls =
    Translation_Fusion_P_g.Delay1_InitialCondition_c;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTA_ppy =
    Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_bh;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_c3 =
    Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_ck;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTA_mos =
    Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_lx;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_hz =
    Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_ln;
  Translation_Fusion_DW.DiscreteTimeIntegrator_IC_LO_fo = 1U;
  Translation_Fusion_DW.DiscreteTimeIntegrator_IC_LO_he = 1U;
  Translation_Fusion_DW.icLoad_on = 1U;
  Translation_Fusion_DW.icLoad_kr = 1U;
  Translation_Fusion_DW.icLoad_fb = 1U;
  Translation_Fusion_DW.icLoad_a = 1U;
  Translation_Fusion_DW.DiscreteTimeIntegrator_IC_LO_mc = 1U;
  Translation_Fusion_DW.DiscreteTimeIntegrator_IC_LOA_l = 1U;
  Translation_Fusion_DW.Memory_PreviousInput_c[0] =
    Translation_Fusion_P_g.Memory_InitialCondition_n[0];
  Translation_Fusion_DW.Memory1_PreviousInput_l[0] =
    Translation_Fusion_P_g.Memory1_InitialCondition_e[0];
  Translation_Fusion_DW.DiscreteTimeIntegrator_PrevR_pz[0] = 2;
  Translation_Fusion_DW.DiscreteTimeIntegrator_PrevR_gr[0] = 2;
  Translation_Fusion_DW.Delay_DSTATE_pc[0] =
    Translation_Fusion_P_g.Delay_InitialCondition_h3;
  Translation_Fusion_DW.Memory_PreviousInput_c[1] =
    Translation_Fusion_P_g.Memory_InitialCondition_n[1];
  Translation_Fusion_DW.Memory1_PreviousInput_l[1] =
    Translation_Fusion_P_g.Memory1_InitialCondition_e[1];
  Translation_Fusion_DW.DiscreteTimeIntegrator_PrevR_pz[1] = 2;
  Translation_Fusion_DW.DiscreteTimeIntegrator_PrevR_gr[1] = 2;
  Translation_Fusion_DW.Delay_DSTATE_pc[1] =
    Translation_Fusion_P_g.Delay_InitialCondition_h3;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_bx =
    Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_k4;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_gr =
    Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_m1;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_in[0] =
    Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_ds;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_in[1] =
    Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_ds;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_in[2] =
    Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_ds;
  Translation_Fusion_DW.DiscreteTimeIntegrator_IC_LO_oh = 1U;
  Translation_MovingAverage2_Init(&Translation_Fusion_DW.MovingAverage_pnae);
  Translation_MovingAverage2_Init(&Translation_Fusion_DW.MovingAverage1_pnae);
  Translation_MovingAverage2_Init(&Translation_Fusion_DW.MovingAverage2_p);
  Translation_Fusion_B.MovingAverage_pnae.MovingAverage2 =
    Translation_Fusion_P_g.acc_bias_O_Y0;
  Translation_Fusion_B.MovingAverage1_pnae.MovingAverage2 =
    Translation_Fusion_P_g.acc_bias_O_Y0;
  Translation_Fusion_B.MovingAverage2_p.MovingAverage2 =
    Translation_Fusion_P_g.acc_bias_O_Y0;
  Translation_Fusion_Average_Init(&Translation_Fusion_DW.Average);
  Translation_Fusi_Average_a_Init(&Translation_Fusion_DW.Average_pna);
  Translation_Fusi_Average_a_Init(&Translation_Fusion_DW.Average_pn);
  Translation_Fusion_DW.Delay_DSTATE_j3 =
    Translation_Fusion_P_g.Delay_InitialCondition_j;
  Translation_Fusion_DW.Delay1_DSTATE_h =
    Translation_Fusion_P_g.Delay1_InitialCondition_k;
  Translation_Fusion_B.Add_c[0] = Translation_Fusion_P_g.x_Y0_l;
  Translation_Fusion_B.Add_c[1] = Translation_Fusion_P_g.x_Y0_l;
  Translation_Fusion_B.Add_c[2] = Translation_Fusion_P_g.x_Y0_l;
  Translation_Fusion_DW.Delay_DSTATE_cc =
    Translation_Fusion_P_g.Delay_InitialCondition_k;
  Translation_Fusion_DW.Delay1_DSTATE_k =
    Translation_Fusion_P_g.Delay1_InitialCondition_g;
  Translation_Fusion_B.Add_k[0] = Translation_Fusion_P_g.x_Y0_h;
  Translation_Fusion_B.Add_k[1] = Translation_Fusion_P_g.x_Y0_h;
  Translation_Fusion_B.Add_k[2] = Translation_Fusion_P_g.x_Y0_h;
  Translation_Fusion_DW.Delay_DSTATE_jl =
    Translation_Fusion_P_g.Delay_InitialCondition;
  Translation_Fusion_DW.Delay1_DSTATE_ot =
    Translation_Fusion_P_g.Delay1_InitialCondition;
  Translation_Fusion_B.Add_cg[0] = Translation_Fusion_P_g.x_Y0;
  Translation_Fusion_B.Add_cg[1] = Translation_Fusion_P_g.x_Y0;
  Translation_Fusion_B.Add_cg[2] = Translation_Fusion_P_g.x_Y0;
  for (i = 0; i < 9; i++) {
    Translation_Fusion_B.Add_p[i] = Translation_Fusion_P_g.P_Y0_p;
    Translation_Fusion_B.Add_m[i] = Translation_Fusion_P_g.P_Y0_d;
    Translation_Fusion_B.Add_f[i] = Translation_Fusion_P_g.P_Y0;
    Translation_Fusion_B.Multiply5[i] = Translation_Fusion_P_g.P_next_Y0;
  }

  Translation_Fusion_B.Multiply[0] = Translation_Fusion_P_g.X_Cor_Y0;
  Translation_Fusion_B.Multiply[1] = Translation_Fusion_P_g.X_Cor_Y0;
  Translation_Fusion_B.Multiply[2] = Translation_Fusion_P_g.X_Cor_Y0;
  Translation_Fusi_Correct_x_Init(&Translation_Fusion_B.Correct_x_m,
    &Translation_Fusion_P_g.Correct_x_m);
  Translation_Fusion_B.X_Cor_RTK[0] = Translation_Fusion_P_g.Merge_InitialOutput;
  Translation_Fusion_B.X_Cor_RTK[1] = Translation_Fusion_P_g.Merge_InitialOutput;
  Translation_Fusion_B.X_Cor_RTK[2] = Translation_Fusion_P_g.Merge_InitialOutput;
  Translation_Fusion_B.bias_filtered = Translation_Fusion_P_g.bias_Y0;
  if (Translation_Fusion_DW.obj.pStatistic->isInitialized == 1) {
    Translation_Fusion_DW.obj.pStatistic->pCumSum = 0.0F;
    memset(&Translation_Fusion_DW.obj.pStatistic->pCumSumRev[0], 0, 401U *
           sizeof(real32_T));
    Translation_Fusion_DW.obj.pStatistic->pCumRevIndex = 1.0F;
  }

  Translation_Fusion_DW.icLoad_b = 1U;
  Translation_Fusion_DW.icLoad_l = 1U;
  Translation_Fusion_B.Gain = Translation_Fusion_P_g.y_Y0;
  if (Translation_Fusion_DW.obj_p.pStatistic->isInitialized == 1) {
    Translation_Fusion_DW.obj_p.pStatistic->pCumSum = 0.0F;
    memset(&Translation_Fusion_DW.obj_p.pStatistic->pCumSumRev[0], 0, 99U *
           sizeof(real32_T));
    Translation_Fusion_DW.obj_p.pStatistic->pCumRevIndex = 1.0F;
  }

  Translation_Fusion_B.In1 = Translation_Fusion_P_g.Out1_Y0;
  Translation_Fusion_DW.Delay_DSTATE_i =
    Translation_Fusion_P_g.Delay_InitialCondition_nx;
  Translation_Fusion_DW.Delay1_DSTATE_hr =
    Translation_Fusion_P_g.Delay1_InitialCondition_l;
  Translation_Fusion_B.Add_o[0] = Translation_Fusion_P_g.x_Y0_o;
  Translation_Fusion_B.Add_o[1] = Translation_Fusion_P_g.x_Y0_o;
  Translation_Fusion_B.Add_o[2] = Translation_Fusion_P_g.x_Y0_o;
  for (i = 0; i < 9; i++) {
    Translation_Fusion_B.Merge1[i] = Translation_Fusion_P_g.Merge1_InitialOutput;
    Translation_Fusion_B.Add_d[i] = Translation_Fusion_P_g.P_Y0_g;
  }

  Translation_Fusion_B.MatrixMultiply3 = Translation_Fusion_P_g.Eta_Y0;
  Translation_Fusion_DW.Delay_DSTATE_ks =
    Translation_Fusion_P_g.Delay_InitialCondition_n;
  for (i = 0; i < 5; i++) {
    Translation_Fusion_DW.Delay1_DSTATE_ky[i] =
      Translation_Fusion_P_g.Delay1_InitialCondition_f;
  }

  Translation_Fusion_B.Add_pl[0] = Translation_Fusion_P_g.x_Y0_c;
  Translation_Fusion_B.Add_pl[1] = Translation_Fusion_P_g.x_Y0_c;
  Translation_Fusion_B.Add_pl[2] = Translation_Fusion_P_g.x_Y0_c;
  for (i = 0; i < 9; i++) {
    Translation_Fusion_B.Add_pa[i] = Translation_Fusion_P_g.P_Y0_l;
  }

  Translation_Fu_Correct_x_e_Init(&Translation_Fusion_B.Correct_x_d,
    &Translation_Fusion_P_g.Correct_x_d);
  Translation_Fusi_Correct_y_Init(&Translation_Fusion_B.Correct_y_f,
    &Translation_Fusion_P_g.Correct_y_f);
  Translation_Fu_Correct_x_l_Init(&Translation_Fusion_B.Correct_x_j,
    &Translation_Fusion_P_g.Correct_x_j);
  Translation_Fu_Correct_x_l_Init(&Translation_Fusion_B.Correct_y_c,
    &Translation_Fusion_P_g.Correct_y_c);
  Translation_Fusion_DW.Delay_DSTATE_b[0] =
    Translation_Fusion_P_g.Delay_InitialCondition_i;
  Translation_Fusion_DW.Delay_DSTATE_b[1] =
    Translation_Fusion_P_g.Delay_InitialCondition_i;
  Translation_Fusion_DW.Delay_DSTATE_b[2] =
    Translation_Fusion_P_g.Delay_InitialCondition_i;
  Translation_Fusion_DW.Delay_DSTATE_b[3] =
    Translation_Fusion_P_g.Delay_InitialCondition_i;
  for (i = 0; i < 10; i++) {
    Translation_Fusion_DW.Delay1_DSTATE_p[i] =
      Translation_Fusion_P_g.Delay1_InitialCondition_f0;
  }

  Translation_Fusi_Correct_x_Init(&Translation_Fusion_B.Correct_x_a,
    &Translation_Fusion_P_g.Correct_x_a);
  Translation_Fusi_Correct_x_Init(&Translation_Fusion_B.Correct_y_b,
    &Translation_Fusion_P_g.Correct_y_b);
  for (i = 0; i < 36; i++) {
    Translation_Fusion_B.P_RTK[i] =
      Translation_Fusion_P_g.Merge1_InitialOutput_k;
  }

  for (i = 0; i < 6; i++) {
    Translation_Fusion_B.X_Cor_RTK_k[i] =
      Translation_Fusion_P_g.Merge_InitialOutput_k;
  }

  Translation_Fusion_Average_Init(&Translation_Fusion_DW.MovingAverage_p);
  Translation_Fusion_Average_Init(&Translation_Fusion_DW.MovingAverage1);
  Translation_Fusion_DW.Delay_DSTATE_ko[0] =
    Translation_Fusion_P_g.Delay_InitialCondition_a;
  Translation_Fusion_DW.Delay_DSTATE_ko[1] =
    Translation_Fusion_P_g.Delay_InitialCondition_a;
  Translation_Fusion_DW.Delay_DSTATE_ko[2] =
    Translation_Fusion_P_g.Delay_InitialCondition_a;
  Translation_Fusion_DW.Delay_DSTATE_ko[3] =
    Translation_Fusion_P_g.Delay_InitialCondition_a;
  for (i = 0; i < 10; i++) {
    Translation_Fusion_DW.Delay1_DSTATE_gi[i] =
      Translation_Fusion_P_g.Delay1_InitialCondition_n;
  }

  for (i = 0; i < 16; i++) {
    Translation_Fusion_B.Add[i] = Translation_Fusion_P_g.P_Y0_da;
  }

  Translation_Fusion_B.MatrixMultiply1_j[0] = Translation_Fusion_P_g.X_Cor_Y0_g;
  Translation_Fusion_B.MatrixMultiply1_j[1] = Translation_Fusion_P_g.X_Cor_Y0_g;
  Translation_Fusion_B.MatrixMultiply1_j[2] = Translation_Fusion_P_g.X_Cor_Y0_g;
  Translation_Fusion_B.MatrixMultiply1_j[3] = Translation_Fusion_P_g.X_Cor_Y0_g;
  Translation_MovingAverage1_Init(&Translation_Fusion_DW.MovingAverage_pn);
  Translation_MovingAverage1_Init(&Translation_Fusion_DW.MovingAverage1_pn);
  Translati_MovingAverage1_a_Init(&Translation_Fusion_DW.MovingAverage_pna);
  Translati_MovingAverage1_a_Init(&Translation_Fusion_DW.MovingAverage1_pna);
  Translation_Fusion_DW.Delay_DSTATE_fh[0] =
    Translation_Fusion_P_g.Delay_InitialCondition_m;
  Translation_Fusion_DW.Delay_DSTATE_fh[1] =
    Translation_Fusion_P_g.Delay_InitialCondition_m;
  Translation_Fusion_DW.Delay_DSTATE_fh[2] =
    Translation_Fusion_P_g.Delay_InitialCondition_m;
  Translation_Fusion_DW.Delay_DSTATE_fh[3] =
    Translation_Fusion_P_g.Delay_InitialCondition_m;
  Translation_Fusion_DW.Delay1_DSTATE_j[0] =
    Translation_Fusion_P_g.Delay1_InitialCondition_h;
  Translation_Fusion_DW.Delay1_DSTATE_j[1] =
    Translation_Fusion_P_g.Delay1_InitialCondition_h;
  for (i = 0; i < 16; i++) {
    Translation_Fusion_B.P[i] = Translation_Fusion_P_g.P_Y0_gk;
  }

  Translation_Fusion_B.MatrixMultiply1[0] = Translation_Fusion_P_g.X_Cor_Y0_m;
  Translation_Fusion_B.MatrixMultiply1[1] = Translation_Fusion_P_g.X_Cor_Y0_m;
  Translation_Fusion_B.MatrixMultiply1[2] = Translation_Fusion_P_g.X_Cor_Y0_m;
  Translation_Fusion_B.MatrixMultiply1[3] = Translation_Fusion_P_g.X_Cor_Y0_m;
  Translation_MovingAverage3_Init(&Translation_Fusion_DW.MovingAverage2);
  Translation_MovingAverage3_Init(&Translation_Fusion_DW.MovingAverage3);
  Translation_Fu_Correct_x_e_Init(&Translation_Fusion_B.Correct_x,
    &Translation_Fusion_P_g.Correct_x);
  Translation_Fusi_Correct_y_Init(&Translation_Fusion_B.Correct_y,
    &Translation_Fusion_P_g.Correct_y);
  if (Translation_Fusion_DW.obj_a.pStatistic->isInitialized == 1) {
    Translation_Fusion_DW.obj_a.pStatistic->pCumSum = 0.0F;
    Translation_Fusion_DW.obj_a.pStatistic->pCumSumRev[0] = 0.0F;
    Translation_Fusion_DW.obj_a.pStatistic->pCumSumRev[1] = 0.0F;
    Translation_Fusion_DW.obj_a.pStatistic->pCumSumRev[2] = 0.0F;
    Translation_Fusion_DW.obj_a.pStatistic->pCumRevIndex = 1.0F;
  }

  *rty_Vx_cor = Translation_Fusion_B.MatrixMultiply1_j[0];
}

void Translation_Fusion_Reset(void)
{
  int32_T i;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE =
    Translation_Fusion_P_g.DiscreteTimeIntegrator_IC;
  Translation_Fusion_DW.DiscreteTimeIntegrator_PrevRese = 0;
  Translation_Fusion_DW.Delay2_DSTATE_h[0] =
    Translation_Fusion_P_g.Delay2_InitialCondition_h;
  Translation_Fusion_DW.Delay2_DSTATE_h[1] =
    Translation_Fusion_P_g.Delay2_InitialCondition_h;
  Translation_Fusion_DW.Delay1_DSTATE[0] =
    Translation_Fusion_P_g.Delay1_InitialCondition_i;
  Translation_Fusion_DW.Delay1_DSTATE[1] =
    Translation_Fusion_P_g.Delay1_InitialCondition_i;
  Translation_Fusion_DW.Delay1_DSTATE[2] =
    Translation_Fusion_P_g.Delay1_InitialCondition_i;
  Translation_Fusion_DW.Delay1_DSTATE[3] =
    Translation_Fusion_P_g.Delay1_InitialCondition_i;
  Translation_Fusion_DW.icLoad = 1U;
  Translation_Fusion_DW.Delay_10_DSTATE[0] =
    Translation_Fusion_P_g.Delay_10_InitialCondition;
  Translation_Fusion_DW.Delay_10_DSTATE[1] =
    Translation_Fusion_P_g.Delay_10_InitialCondition;
  Translation_Fusion_DW.Delay_2_DSTATE =
    Translation_Fusion_P_g.Delay_2_InitialCondition;
  Translation_Fusion_DW.DelayInput1_DSTATE_g =
    Translation_Fusion_P_g.DetectRisePositive3_vinit;
  Translation_Fusion_DW.DelayInput1_DSTATE_k3 =
    Translation_Fusion_P_g.DetectRisePositive2_vinit;
  Translation_Fusion_DW.memory1_PreviousInput[0] =
    Translation_Fusion_P_g.memory1_InitialCondition;
  Translation_Fusion_DW.memory1_PreviousInput[1] =
    Translation_Fusion_P_g.memory1_InitialCondition;
  Translation_Fusion_DW.memory1_PreviousInput[2] =
    Translation_Fusion_P_g.memory1_InitialCondition;
  Translation_Fusion_DW.DelayInput1_DSTATE_g3 =
    Translation_Fusion_P_g.DetectIncrease_vinit_a;
  Translation_Fusion_DW.DelayInput1_DSTATE_ku =
    Translation_Fusion_P_g.DetectIncrease1_vinit;
  Translation_Fusion_DW.DelayInput1_DSTATE_e =
    Translation_Fusion_P_g.DetectIncrease2_vinit;
  for (i = 0; i < 10; i++) {
    Translation_Fusion_DW.Delay_DSTATE_g[i] =
      Translation_Fusion_P_g.Delay_InitialCondition_l;
  }

  Translation_Fusion_DW.memory_PreviousInput[0] =
    Translation_Fusion_P_g.memory_InitialCondition;
  Translation_Fusion_DW.memory_PreviousInput[1] =
    Translation_Fusion_P_g.memory_InitialCondition;
  Translation_Fusion_DW.memory_PreviousInput[2] =
    Translation_Fusion_P_g.memory_InitialCondition;
  Translation_Fusion_DW.UnitDelay_DSTATE_p =
    Translation_Fusion_P_g.UnitDelay_InitialCondition_f;
  Translation_Fusion_DW.icLoad_k = 1U;
  Translation_Fusion_DW.DelayInput1_DSTATE_bh =
    Translation_Fusion_P_g.DetectIncrease1_vinit_h;
  Translation_Fusion_DW.Delay1_DSTATE_l =
    Translation_Fusion_P_g.Delay1_InitialCondition_p;
  Translation_Fusion_DW.icLoad_ki = 1U;
  Translation_Fusion_DW.icLoad_h = 1U;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE_k =
    Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_e;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE_g =
    Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_c;
  Translation_Fusion_DW.DiscreteTimeIntegrator_PrevRe_h = 0;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_k0 =
    Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_a;
  Translation_Fusion_DW.DiscreteTimeIntegrator_PrevRe_b = 0;
  Translation_Fusion_DW.DiscreteTimeIntegrator_IC_LOADI = 1U;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE_p =
    Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_l;
  Translation_Fusion_DW.DiscreteTimeIntegrator_PrevR_hl = 0;
  Translation_Fusion_DW.DelayInput1_DSTATE_k2 =
    Translation_Fusion_P_g.DetectIncrease_vinit;
  Translation_Fusion_DW.DiscreteTimeIntegrator1_DSTATE =
    Translation_Fusion_P_g.DiscreteTimeIntegrator1_IC;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE_n =
    Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_p;
  Translation_Fusion_DW.DiscreteTimeIntegrator_PrevRe_g = 0;
  Translation_Fusion_DW.DelayInput1_DSTATE =
    Translation_Fusion_P_g.DetectUpdate1_vinit;
  Translation_Fusion_DW.Delay_DSTATE_k =
    Translation_Fusion_P_g.Delay_InitialCondition_kg;
  Translation_Fusion_DW.DiscreteTimeIntegrator_IC_LOA_p = 1U;
  Translation_Fusion_DW.Delay_DSTATE_p2 =
    Translation_Fusion_P_g.Delay_InitialCondition_i0;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE_h =
    Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_g;
  Translation_Fusion_DW.DiscreteTimeIntegrator_PrevRe_n = 0;
  Translation_Fusion_DW.Delay_DSTATE_o5 =
    Translation_Fusion_P_g.Delay_InitialCondition_ib;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_ax =
    Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_k;
  Translation_Fusion_DW.DiscreteTimeIntegrator_PrevR_bx = 0;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE_f =
    Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_lj;
  Translation_Fusion_DW.DiscreteTimeIntegrator_PrevRe_f = 0;
  Translation_Fusion_DW.Delay_DSTATE_d =
    Translation_Fusion_P_g.Delay_InitialCondition_b2;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_nz =
    Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_o;
  Translation_Fusion_DW.DiscreteTimeIntegrator_PrevR_n3 = 0;
  Translation_Fusion_DW.Delay_DSTATE_db =
    Translation_Fusion_P_g.Delay_InitialCondition_n2;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_a3 =
    Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_d;
  Translation_Fusion_DW.DiscreteTimeIntegrator_PrevRe_c = 0;
  Translation_Fusion_DW.Delay_DSTATE_c =
    Translation_Fusion_P_g.Delay_InitialCondition_jx;
  Translation_Fusion_DW.DiscreteTimeIntegrator1_DSTAT_k =
    Translation_Fusion_P_g.DiscreteTimeIntegrator1_IC_j;
  Translation_Fusion_DW.Delay_DSTATE_h =
    Translation_Fusion_P_g.Delay_InitialCondition_lu;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_pp =
    Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_n;
  Translation_Fusion_DW.DiscreteTimeIntegrator_PrevRe_m = 0;
  Translation_Fusion_DW.DiscreteTimeIntegrator1_DSTAT_a =
    Translation_Fusion_P_g.DiscreteTimeIntegrator1_IC_js;
  Translation_Fusion_DW.Delay_DSTATE_ch =
    Translation_Fusion_P_g.Delay_InitialCondition_mv;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_o4 =
    Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_i;
  Translation_Fusion_DW.DiscreteTimeIntegrator_PrevR_bd = 0;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE_e =
    Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_cm;
  Translation_Fusion_DW.DiscreteTimeIntegrator_PrevR_mc = 0;
  Translation_Fusion_DW.DiscreteTimeIntegrator_IC_LOA_a = 1U;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_hu =
    Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_ce;
  Translation_Fusion_DW.DiscreteTimeIntegrator_PrevR_br = 0;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE_j =
    Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_f;
  Translation_Fusion_DW.DiscreteTimeIntegrator_PrevRe_i = 0;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_hc =
    Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_f3;
  Translation_Fusion_DW.DiscreteTimeIntegrator_PrevRe_j = 0;
  Translation_Fusion_DW.DelayInput1_DSTATE_a =
    Translation_Fusion_P_g.DetectUpdate1_vinit_e;
  Translation_Fusion_DW.Delay_DSTATE_jd =
    Translation_Fusion_P_g.Delay_InitialCondition_h;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE_c =
    Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_m;
  Translation_Fusion_DW.DiscreteTimeIntegrator_PrevR_g2 = 0;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_ag =
    Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_f33;
  Translation_Fusion_DW.DiscreteTimeIntegrator_PrevRe_p = 0;
  Translation_Fusion_DW.DelayInput1_DSTATE_p =
    Translation_Fusion_P_g.DetectChange_vinit;
  Translation_Fusion_DW.icLoad_g = 1U;
  Translation_Fusion_DW.icLoad_kg = 1U;
  Translation_Fusion_DW.DelayInput1_DSTATE_n =
    Translation_Fusion_P_g.DetectIncrease_vinit_k;
  Translation_Fusion_DW.Memory_PreviousInput =
    Translation_Fusion_P_g.Memory_InitialCondition;
  Translation_Fusion_DW.DelayInput1_DSTATE_j =
    Translation_Fusion_P_g.DetectChange_vinit_d;
  Translation_Fusion_DW.Delay_DSTATE_d4 =
    Translation_Fusion_P_g.Delay_InitialCondition_k1;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_gk =
    Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_gn;
  Translation_Fusion_DW.DiscreteTimeIntegrator_PrevR_gd = 0;
  Translation_Fusion_DW.Memory1_PreviousInput =
    Translation_Fusion_P_g.Memory1_InitialCondition;
  Translation_Fusion_DW.Delay_DSTATE_jg =
    Translation_Fusion_P_g.Delay_InitialCondition_jp;
  Translation_Fusion_DW.Delay1_DSTATE_o[0] =
    Translation_Fusion_P_g.Delay1_InitialCondition_hr;
  Translation_Fusion_DW.Delay1_DSTATE_b0[0] =
    Translation_Fusion_P_g.Delay1_InitialCondition_j;
  Translation_Fusion_DW.Delay1_DSTATE_o[1] =
    Translation_Fusion_P_g.Delay1_InitialCondition_hr;
  Translation_Fusion_DW.Delay1_DSTATE_b0[1] =
    Translation_Fusion_P_g.Delay1_InitialCondition_j;
  Translation_Fusion_DW.Memory_PreviousInput_o =
    Translation_Fusion_P_g.Memory_InitialCondition_k;
  Translation_Fusion_DW.DiscreteTimeIntegrator_IC_LOA_b = 1U;
  Translation_Fusion_DW.DiscreteTimeIntegrator_PrevR_hj = 2;
  Translation_Fusion_DW.DiscreteTimeIntegrator1_DSTAT_h[0] =
    Translation_Fusion_P_g.DiscreteTimeIntegrator1_IC_n;
  Translation_Fusion_DW.DiscreteTimeIntegrator1_DSTAT_h[1] =
    Translation_Fusion_P_g.DiscreteTimeIntegrator1_IC_n;
  Translation_Fusion_DW.DiscreteTimeIntegrator1_DSTAT_h[2] =
    Translation_Fusion_P_g.DiscreteTimeIntegrator1_IC_n;
  Translation_Fusion_DW.DelayInput1_DSTATE_j3 =
    Translation_Fusion_P_g.DetectIncrease_vinit_h;
  Translation_Fusion_DW.UD_DSTATE =
    Translation_Fusion_P_g.Difference_ICPrevInput;
  Translation_Fusion_DW.DiscreteTimeIntegrator5_DSTATE =
    Translation_Fusion_P_g.DiscreteTimeIntegrator5_IC;
  Translation_Fusion_DW.DiscreteTimeIntegrator5_DSTAT_d =
    Translation_Fusion_P_g.DiscreteTimeIntegrator5_IC_l;
  Translation_Fusion_DW.Delay_DSTATE_k1 =
    Translation_Fusion_P_g.Delay_InitialCondition_o1;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_fa =
    Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_eg;
  Translation_Fusion_DW.DiscreteTimeIntegrator_PrevR_by = 0;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE_m =
    Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_ku;
  Translation_Fusion_DW.DiscreteTimeIntegrator_PrevR_gw = 0;
  Translation_Fusion_DW.Delay_DSTATE_n =
    Translation_Fusion_P_g.Delay_InitialCondition_f;
  Translation_Fusion_DW.Delay2_DSTATE[0] =
    Translation_Fusion_P_g.Delay2_InitialCondition;
  Translation_Fusion_DW.Delay2_DSTATE_a[0] =
    Translation_Fusion_P_g.Delay2_InitialCondition_f;
  Translation_Fusion_DW.Delay3_DSTATE[0] =
    Translation_Fusion_P_g.Delay3_InitialCondition;
  Translation_Fusion_DW.Delay1_DSTATE_c[0] =
    Translation_Fusion_P_g.Delay1_InitialCondition_dl;
  Translation_Fusion_DW.Delay2_DSTATE[1] =
    Translation_Fusion_P_g.Delay2_InitialCondition;
  Translation_Fusion_DW.Delay2_DSTATE_a[1] =
    Translation_Fusion_P_g.Delay2_InitialCondition_f;
  Translation_Fusion_DW.Delay3_DSTATE[1] =
    Translation_Fusion_P_g.Delay3_InitialCondition;
  Translation_Fusion_DW.Delay1_DSTATE_c[1] =
    Translation_Fusion_P_g.Delay1_InitialCondition_dl;
  for (i = 0; i < 200; i++) {
    Translation_Fusion_DW.Delay_DSTATE_o[i] =
      Translation_Fusion_P_g.Delay_InitialCondition_o;
  }

  Translation_Fusion_DW.DiscreteTimeIntegrator_IC_LO_aj = 1U;
  Translation_Fusion_DW.icLoad_gb = 1U;
  Translation_Fusion_DW.Delay_DSTATE_o1 =
    Translation_Fusion_P_g.Delay_InitialCondition_mb;
  Translation_Fusion_DW.Delay_DSTATE_of =
    Translation_Fusion_P_g.Delay_InitialCondition_b;
  Translation_Fusion_DW.Delay1_DSTATE_nb =
    Translation_Fusion_P_g.Delay1_InitialCondition_di;
  Translation_Fusion_DW.DelayInput1_DSTATE_o =
    Translation_Fusion_P_g.DetectIncrease_vinit_ax;
  Translation_Fusion_DW.Delay_DSTATE_pi =
    Translation_Fusion_P_g.Delay_InitialCondition_d5;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_ab =
    Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_pc;
  Translation_Fusion_DW.DiscreteTimeIntegrator_PrevR_bz = 0;
  Translation_Fusion_DW.Delay1_DSTATE_g =
    Translation_Fusion_P_g.Delay1_InitialCondition_d;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_gt =
    Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_a3;
  Translation_Fusion_DW.DiscreteTimeIntegrator_PrevRe_d = 0;
  Translation_Fusion_DW.DelayInput1_DSTATE_f =
    Translation_Fusion_P_g.DetectIncrease_vinit_kk;
  Translation_Fusion_DW.icLoad_gm = 1U;
  Translation_Fusion_DW.DelayInput1_DSTATE_k =
    Translation_Fusion_P_g.DetectUpdate_vinit;
  Translation_Fusion_DW.Delay_DSTATE_l =
    Translation_Fusion_P_g.Delay_InitialCondition_al;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_ai =
    Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_b;
  Translation_Fusion_DW.DiscreteTimeIntegrator_PrevRe_a = 0;
  Translation_Fusion_DW.Delay_DSTATE_by =
    Translation_Fusion_P_g.Delay_InitialCondition_e;
  Translation_Fusion_DW.icLoad_d = 1U;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_eb =
    Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_d1;
  Translation_Fusion_DW.DiscreteTimeIntegrator_PrevR_jg = 2;
  Translation_Fusion_DW.DiscreteTimeIntegrator_IC_LOA_f = 1U;
  Translation_Fusion_DW.DiscreteTimeIntegrator_IC_LOA_k = 1U;
  Translation_Fusion_DW.DiscreteTimeIntegrator_IC_LOA_m = 1U;
  Translation_Fusion_DW.DiscreteTimeIntegrator_IC_LO_ae = 1U;
  Translation_Fusion_DW.DiscreteTimeIntegrator_PrevRe_o = 2;
  Translation_Fusion_DW.DiscreteTimeIntegrator1_IC_LOAD = 1U;
  Translation_Fusion_DW.Delay_DSTATE_f =
    Translation_Fusion_P_g.Delay_InitialCondition_d;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE_l =
    Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_io;
  Translation_Fusion_DW.DiscreteTimeIntegrator_PrevR_is = 0;
  Translation_Fusion_DW.Memory_PreviousInput_o3 =
    Translation_Fusion_P_g.Memory_InitialCondition_n4;
  Translation_Fusion_DW.DiscreteTimeIntegrator1_DSTA_hw =
    Translation_Fusion_P_g.DiscreteTimeIntegrator1_IC_l;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_lb =
    Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_pp;
  Translation_Fusion_DW.DiscreteTimeIntegrator1_DSTAT_b =
    Translation_Fusion_P_g.DiscreteTimeIntegrator1_IC_nx;
  Translation_Fusion_DW.DiscreteTimeIntegrator1_PrevRes = 0;
  Translation_Fusion_DW.DiscreteTimeIntegrator_IC_LO_fn = 1U;
  Translation_Fusion_DW.DiscreteTimeIntegrator_PrevR_iz = 0;
  Translation_Fusion_DW.Delay_DSTATE_p =
    Translation_Fusion_P_g.Delay_InitialCondition_p;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_pa =
    Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_kux;
  Translation_Fusion_DW.DiscreteTimeIntegrator1_DSTA_fe =
    Translation_Fusion_P_g.DiscreteTimeIntegrator1_IC_p;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_a0 =
    Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_j;
  Translation_Fusion_DW.DiscreteTimeIntegrator1_DSTAT_g =
    Translation_Fusion_P_g.DiscreteTimeIntegrator1_IC_m;
  Translation_Fusion_DW.DiscreteTimeIntegrator1_IC_LO_n = 1U;
  Translation_Fusion_DW.DiscreteTimeIntegrator_PrevR_gg[0] = 0;
  Translation_Fusion_DW.Delay1_DSTATE_f[0] =
    Translation_Fusion_P_g.Delay1_InitialCondition_e;
  Translation_Fusion_DW.DiscreteTimeIntegrator1_DSTAT_f[0] =
    Translation_Fusion_P_g.DiscreteTimeIntegrator1_IC_a;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTA_gt3[0] =
    Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_ll;
  Translation_Fusion_DW.DiscreteTimeIntegrator_PrevR_gg[1] = 0;
  Translation_Fusion_DW.Delay1_DSTATE_f[1] =
    Translation_Fusion_P_g.Delay1_InitialCondition_e;
  Translation_Fusion_DW.DiscreteTimeIntegrator1_DSTAT_f[1] =
    Translation_Fusion_P_g.DiscreteTimeIntegrator1_IC_a;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTA_gt3[1] =
    Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_ll;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_n4 =
    Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_h;
  Translation_Fusion_DW.DiscreteTimeIntegrator_PrevR_hk = 0;
  Translation_Fusion_DW.DiscreteTimeIntegrator_IC_LO_fw = 1U;
  Translation_Fusion_DW.DelayInput1_DSTATE_ey =
    Translation_Fusion_P_g.DetectIncrease_vinit_f;
  Translation_Fusion_DW.DelayInput1_DSTATE_nj =
    Translation_Fusion_P_g.DetectIncrease_vinit_iv;
  Translation_Fusion_DW.Delay1_DSTATE_k1 =
    Translation_Fusion_P_g.Delay1_InitialCondition_oq;
  Translation_Fusion_DW.Delay_DSTATE_pu =
    Translation_Fusion_P_g.Delay_InitialCondition_ps;
  Translation_Fusion_DW.DelayInput1_DSTATE_d =
    Translation_Fusion_P_g.DetectIncrease1_vinit_b;
  Translation_Fusion_DW.DiscreteTimeIntegrator5_DSTAT_g =
    Translation_Fusion_P_g.DiscreteTimeIntegrator5_IC_c;
  Translation_Fusion_DW.DiscreteTimeIntegrator5_DSTAT_j =
    Translation_Fusion_P_g.DiscreteTimeIntegrator5_IC_l3;
  Translation_Fusion_DW.DiscreteTimeIntegrator5_PrevRes = 0;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE_b =
    Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_ao;
  Translation_Fusion_DW.DiscreteTimeIntegrator1_DSTAT_d =
    Translation_Fusion_P_g.DiscreteTimeIntegrator1_IC_f;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_ak =
    Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_dh;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_ce =
    Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_db;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_ct =
    Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_lc;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_bn =
    Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_hd;
  Translation_Fusion_DW.DiscreteTimeIntegrator1_DSTAT_c =
    Translation_Fusion_P_g.DiscreteTimeIntegrator1_IC_f2;
  Translation_Fusion_DW.DiscreteTimeIntegrator1_DSTA_l2 =
    Translation_Fusion_P_g.DiscreteTimeIntegrator1_IC_d;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_jp =
    Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_hv;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_eh =
    Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_aj;
  Translation_Fusion_DW.DiscreteTimeIntegrator1_DSTA_hj =
    Translation_Fusion_P_g.DiscreteTimeIntegrator1_IC_jh;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_hp =
    Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_jv;
  Translation_Fusion_DW.DiscreteTimeIntegrator1_DSTAT_m =
    Translation_Fusion_P_g.DiscreteTimeIntegrator1_IC_e;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_pd =
    Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_je;
  Translation_Fusion_DW.DiscreteTimeIntegrator1_DSTAT_p =
    Translation_Fusion_P_g.DiscreteTimeIntegrator1_IC_i;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_dc =
    Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_jp;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_bo =
    Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_kt;
  Translation_Fusion_DW.DiscreteTimeIntegrator_PrevR_ix = 0;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_ka =
    Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_ng;
  Translation_Fusion_DW.DiscreteTimeIntegrator_PrevRe_e = 0;
  Translation_Fusion_DW.DiscreteTimeIntegrator1_DSTA_na =
    Translation_Fusion_P_g.DiscreteTimeIntegrator1_IC_pg;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_dv =
    Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_li;
  Translation_Fusion_DW.DiscreteTimeIntegrator1_DSTA_hy =
    Translation_Fusion_P_g.DiscreteTimeIntegrator1_IC_fa;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_n2 =
    Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_bz;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_jr =
    Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_eh;
  Translation_Fusion_DW.DiscreteTimeIntegrator_PrevR_fm = 0;
  Translation_Fusion_DW.DiscreteTimeIntegrator1_DSTA_lz =
    Translation_Fusion_P_g.DiscreteTimeIntegrator1_IC_lf;
  Translation_Fusion_DW.Delay_DSTATE_kd =
    Translation_Fusion_P_g.Delay_InitialCondition_lg;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_ny =
    Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_oy;
  Translation_Fusion_DW.DiscreteTimeIntegrator_PrevR_au = 0;
  Translation_Fusion_DW.Delay1_DSTATE_d[0] =
    Translation_Fusion_P_g.Delay1_InitialCondition_o[0];
  Translation_Fusion_DW.Delay1_DSTATE_d[1] =
    Translation_Fusion_P_g.Delay1_InitialCondition_o[1];
  Translation_Fusion_DW.Delay1_DSTATE_d[2] =
    Translation_Fusion_P_g.Delay1_InitialCondition_o[2];
  Translation_Fusion_DW.Delay1_DSTATE_d[3] =
    Translation_Fusion_P_g.Delay1_InitialCondition_o[3];
  Translation_Fusion_DW.icLoad_f = 1U;
  for (i = 0; i < 9; i++) {
    Translation_Fusion_DW.Delay2_DSTATE_l[i] =
      Translation_Fusion_P_g.Delay2_InitialCondition_i;
  }

  Translation_Fusion_DW.DiscreteTimeIntegrator1_DSTA_gu =
    Translation_Fusion_P_g.DiscreteTimeIntegrator1_IC_p4;
  Translation_Fusion_DW.DiscreteTimeIntegrator1_DSTAT_e =
    Translation_Fusion_P_g.DiscreteTimeIntegrator1_IC_nw;
  Translation_Fusion_DW.DelayInput1_DSTATE_ap =
    Translation_Fusion_P_g.DetectChange_vinit_g;
  Translation_Fusion_DW.DelayInput1_DSTATE_jf =
    Translation_Fusion_P_g.DetectIncrease_vinit_g;
  Translation_Fusion_DW.DelayInput1_DSTATE_b =
    Translation_Fusion_P_g.DetectChange_vinit_o;
  Translation_Fusion_DW.Delay_DSTATE_e =
    Translation_Fusion_P_g.Delay_InitialCondition_c;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_bc =
    Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_ir;
  Translation_Fusion_DW.DiscreteTimeIntegrator_PrevR_a0 = 0;
  Translation_Fusion_DW.icLoad_d1 = 1U;
  Translation_Fusion_DW.icLoad_o = 1U;
  Translation_Fusion_DW.Delay_DSTATE_ev =
    Translation_Fusion_P_g.Delay_InitialCondition_fp;
  Translation_Fusion_DW.UnitDelay_DSTATE[0] =
    Translation_Fusion_P_g.UnitDelay_InitialCondition;
  Translation_Fusion_DW.Memory_PreviousInput_h[0] =
    Translation_Fusion_P_g.Memory_InitialCondition_h;
  Translation_Fusion_DW.Memory1_PreviousInput_c[0] =
    Translation_Fusion_P_g.Memory1_InitialCondition_f;
  Translation_Fusion_DW.Delay1_DSTATE_ci[0] =
    Translation_Fusion_P_g.Delay1_InitialCondition_lq;
  Translation_Fusion_DW.UnitDelay_DSTATE[1] =
    Translation_Fusion_P_g.UnitDelay_InitialCondition;
  Translation_Fusion_DW.Memory_PreviousInput_h[1] =
    Translation_Fusion_P_g.Memory_InitialCondition_h;
  Translation_Fusion_DW.Memory1_PreviousInput_c[1] =
    Translation_Fusion_P_g.Memory1_InitialCondition_f;
  Translation_Fusion_DW.Delay1_DSTATE_ci[1] =
    Translation_Fusion_P_g.Delay1_InitialCondition_lq;
  Translation_Fusion_DW.icLoad_c = 1U;
  Translation_Fusion_DW.icLoad_j = 1U;
  Translation_Fusion_DW.UnitDelay1_DSTATE[0] =
    Translation_Fusion_P_g.UnitDelay1_InitialCondition;
  Translation_Fusion_DW.UnitDelay1_DSTATE[1] =
    Translation_Fusion_P_g.UnitDelay1_InitialCondition;
  Translation_Fusion_DW.UnitDelay1_DSTATE[2] =
    Translation_Fusion_P_g.UnitDelay1_InitialCondition;
  Translation_Fusion_DW.DiscreteTimeIntegrator_IC_LOA_d = 1U;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_lv =
    Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_oo;
  Translation_Fusion_DW.DiscreteTimeIntegrator_PrevR_ov = 0;
  Translation_Fusion_DW.DiscreteTimeIntegrator_IC_LOA_i = 1U;
  Translation_Fusion_DW.DiscreteTimeIntegrator_IC_LOA_o = 1U;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_oy =
    Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_f2;
  Translation_Fusion_DW.DiscreteTimeIntegrator_Prev_jgs = 0;
  Translation_Fusion_DW.DiscreteTimeIntegrator_IC_LOA_h = 1U;
  Translation_Fusion_DW.DiscreteTimeIntegrator_IC_LO_oj = 1U;
  Translation_Fusion_DW.DiscreteTimeIntegrator_IC_LO_fm = 1U;
  Translation_Fusion_DW.DelayInput1_DSTATE_p1 =
    Translation_Fusion_P_g.DetectIncrease_vinit_i;
  Translation_Fusion_DW.UnitDelay_DSTATE_h =
    Translation_Fusion_P_g.UnitDelay_InitialCondition_e;
  Translation_Fusion_DW.Delay1_DSTATE_ls =
    Translation_Fusion_P_g.Delay1_InitialCondition_c;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTA_ppy =
    Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_bh;
  Translation_Fusion_DW.DiscreteTimeIntegrator_PrevR_nj = 0;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_c3 =
    Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_ck;
  Translation_Fusion_DW.DiscreteTimeIntegrator_PrevRe_k = 0;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTA_mos =
    Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_lx;
  Translation_Fusion_DW.DiscreteTimeIntegrator_PrevR_pi = 0;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_hz =
    Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_ln;
  Translation_Fusion_DW.DiscreteTimeIntegrator_PrevR_dw = 0;
  Translation_Fusion_DW.DiscreteTimeIntegrator_IC_LO_fo = 1U;
  Translation_Fusion_DW.DiscreteTimeIntegrator_IC_LO_he = 1U;
  Translation_Fusion_DW.icLoad_on = 1U;
  Translation_Fusion_DW.icLoad_kr = 1U;
  Translation_Fusion_DW.icLoad_fb = 1U;
  Translation_Fusion_DW.icLoad_a = 1U;
  Translation_Fusion_DW.DiscreteTimeIntegrator_IC_LO_mc = 1U;
  Translation_Fusion_DW.DiscreteTimeIntegrator_IC_LOA_l = 1U;
  Translation_Fusion_DW.Memory_PreviousInput_c[0] =
    Translation_Fusion_P_g.Memory_InitialCondition_n[0];
  Translation_Fusion_DW.Memory1_PreviousInput_l[0] =
    Translation_Fusion_P_g.Memory1_InitialCondition_e[0];
  Translation_Fusion_DW.DiscreteTimeIntegrator_PrevR_pz[0] = 2;
  Translation_Fusion_DW.DiscreteTimeIntegrator_PrevR_gr[0] = 2;
  Translation_Fusion_DW.Delay_DSTATE_pc[0] =
    Translation_Fusion_P_g.Delay_InitialCondition_h3;
  Translation_Fusion_DW.Memory_PreviousInput_c[1] =
    Translation_Fusion_P_g.Memory_InitialCondition_n[1];
  Translation_Fusion_DW.Memory1_PreviousInput_l[1] =
    Translation_Fusion_P_g.Memory1_InitialCondition_e[1];
  Translation_Fusion_DW.DiscreteTimeIntegrator_PrevR_pz[1] = 2;
  Translation_Fusion_DW.DiscreteTimeIntegrator_PrevR_gr[1] = 2;
  Translation_Fusion_DW.Delay_DSTATE_pc[1] =
    Translation_Fusion_P_g.Delay_InitialCondition_h3;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_bx =
    Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_k4;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_gr =
    Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_m1;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_in[0] =
    Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_ds;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_in[1] =
    Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_ds;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_in[2] =
    Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_ds;
  Translation_Fusio_Average_Reset(&Translation_Fusion_DW.Average);
  Translation_Fus_Average_d_Reset(&Translation_Fusion_DW.Average_pna);
  Translation_Fus_Average_d_Reset(&Translation_Fusion_DW.Average_pn);
  if (Translation_Fusion_DW.obj.pStatistic->isInitialized == 1) {
    Translation_Fusion_DW.obj.pStatistic->pCumSum = 0.0F;
    memset(&Translation_Fusion_DW.obj.pStatistic->pCumSumRev[0], 0, 401U *
           sizeof(real32_T));
    Translation_Fusion_DW.obj.pStatistic->pCumRevIndex = 1.0F;
  }

  Translation_Fusion_DW.icLoad_b = 1U;
  Translation_Fusion_DW.icLoad_l = 1U;
  if (Translation_Fusion_DW.obj_p.pStatistic->isInitialized == 1) {
    Translation_Fusion_DW.obj_p.pStatistic->pCumSum = 0.0F;
    memset(&Translation_Fusion_DW.obj_p.pStatistic->pCumSumRev[0], 0, 99U *
           sizeof(real32_T));
    Translation_Fusion_DW.obj_p.pStatistic->pCumRevIndex = 1.0F;
  }

  Translation_Fusio_Average_Reset(&Translation_Fusion_DW.MovingAverage_p);
  Translation_Fusio_Average_Reset(&Translation_Fusion_DW.MovingAverage1);
  Translatio_MovingAverage1_Reset(&Translation_Fusion_DW.MovingAverage_pn);
  Translatio_MovingAverage1_Reset(&Translation_Fusion_DW.MovingAverage1_pn);
  Translat_MovingAverage1_o_Reset(&Translation_Fusion_DW.MovingAverage_pna);
  Translat_MovingAverage1_o_Reset(&Translation_Fusion_DW.MovingAverage1_pna);
  Translatio_MovingAverage3_Reset(&Translation_Fusion_DW.MovingAverage2);
  Translatio_MovingAverage3_Reset(&Translation_Fusion_DW.MovingAverage3);
  if (Translation_Fusion_DW.obj_a.pStatistic->isInitialized == 1) {
    Translation_Fusion_DW.obj_a.pStatistic->pCumSum = 0.0F;
    Translation_Fusion_DW.obj_a.pStatistic->pCumSumRev[0] = 0.0F;
    Translation_Fusion_DW.obj_a.pStatistic->pCumSumRev[1] = 0.0F;
    Translation_Fusion_DW.obj_a.pStatistic->pCumSumRev[2] = 0.0F;
    Translation_Fusion_DW.obj_a.pStatistic->pCumRevIndex = 1.0F;
  }
}

void Translation_Fusion_Disable(void)
{
  Translation_Fusion_DW.DiscreteTimeIntegrator5_DSTATE =
    Translation_Fusion_B.DiscreteTimeIntegrator5;
  Translation_Fusion_DW.DiscreteTimeIntegrator5_DSTAT_d =
    Translation_Fusion_B.DiscreteTimeIntegrator5_h;
  Translation_Fusion_DW.DiscreteTimeIntegrator5_DSTAT_g =
    Translation_Fusion_B.DiscreteTimeIntegrator5_h1;
  Translation_Fusion_DW.DiscreteTimeIntegrator5_DSTAT_j =
    Translation_Fusion_B.DiscreteTimeIntegrator5_i;
}

void Translation_Fusion_Start(void)
{
  int32_T i;
  Translatio_MovingAverage2_Start(&Translation_Fusion_DW.MovingAverage_pnae);
  Translatio_MovingAverage2_Start(&Translation_Fusion_DW.MovingAverage1_pnae);
  Translatio_MovingAverage2_Start(&Translation_Fusion_DW.MovingAverage2_p);
  Translation_Fusio_Average_Start(&Translation_Fusion_DW.Average);
  for (i = 0; i < 9; i++) {
    Translation_Fusion_B.IdentityMatrix[i] = 0.0F;
    Translation_Fusion_B.IdentityMatrix_j[i] = 0.0F;
  }

  Translation_Fusion_B.IdentityMatrix[0] = 1.0F;
  Translation_Fusion_B.IdentityMatrix[4] = 1.0F;
  Translation_Fusion_B.IdentityMatrix[8] = 1.0F;
  Translation_Fusion_B.IdentityMatrix_j[0] = 1.0F;
  Translation_Fusion_B.IdentityMatrix_j[4] = 1.0F;
  Translation_Fusion_B.IdentityMatrix_j[8] = 1.0F;
  Translation_Fus_Average_m_Start(&Translation_Fusion_DW.Average_pna);
  Translation_Fus_Average_m_Start(&Translation_Fusion_DW.Average_pn);
  for (i = 0; i < 9; i++) {
    Translation_Fusion_B.IdentityMatrix_i[i] = 0.0F;
    Translation_Fusion_B.IdentityMatrix_e[i] = 0.0F;
    Translation_Fusion_B.IdentityMatrix_j3[i] = 0.0F;
  }

  Translation_Fusion_B.IdentityMatrix_i[0] = 1.0F;
  Translation_Fusion_B.IdentityMatrix_i[4] = 1.0F;
  Translation_Fusion_B.IdentityMatrix_i[8] = 1.0F;
  Translation_Fusion_B.IdentityMatrix_e[0] = 1.0F;
  Translation_Fusion_B.IdentityMatrix_e[4] = 1.0F;
  Translation_Fusion_B.IdentityMatrix_e[8] = 1.0F;
  Translation_Fusion_B.IdentityMatrix_j3[0] = 1.0F;
  Translation_Fusion_B.IdentityMatrix_j3[4] = 1.0F;
  Translation_Fusion_B.IdentityMatrix_j3[8] = 1.0F;
  Translation_Fusion_DW.obj.matlabCodegenIsDeleted = true;
  Translation_Fusion_DW.obj.isInitialized = 0;
  Translation_Fusion_DW.obj.NumChannels = -1;
  Translation_Fusion_DW.obj.matlabCodegenIsDeleted = false;
  Translation_Fusion_DW.objisempty_d = true;
  Translation_Fusion_DW.obj.isSetupComplete = false;
  Translation_Fusion_DW.obj.isInitialized = 1;
  Translation_Fusion_DW.obj.NumChannels = 1;
  Translation_Fusion_DW.gobj_0.isInitialized = 0;
  Translation_Fusion_DW.obj.pStatistic = &Translation_Fusion_DW.gobj_0;
  Translation_Fusion_DW.obj.isSetupComplete = true;
  Translation_Fusion_DW.obj.TunablePropsChanged = false;
  Translation_Fusion_DW.obj_p.matlabCodegenIsDeleted = true;
  Translation_Fusion_DW.obj_p.isInitialized = 0;
  Translation_Fusion_DW.obj_p.NumChannels = -1;
  Translation_Fusion_DW.obj_p.matlabCodegenIsDeleted = false;
  Translation_Fusion_DW.objisempty_i = true;
  Translation_Fusion_DW.obj_p.isSetupComplete = false;
  Translation_Fusion_DW.obj_p.isInitialized = 1;
  Translation_Fusion_DW.obj_p.NumChannels = 1;
  Translation_Fusion_DW.gobj_0_b.isInitialized = 0;
  Translation_Fusion_DW.obj_p.pStatistic = &Translation_Fusion_DW.gobj_0_b;
  Translation_Fusion_DW.obj_p.isSetupComplete = true;
  Translation_Fusion_DW.obj_p.TunablePropsChanged = false;
  for (i = 0; i < 9; i++) {
    Translation_Fusion_B.IdentityMatrix_m[i] = 0.0F;
    Translation_Fusion_B.IdentityMatrix_kr[i] = 0.0F;
  }

  Translation_Fusion_B.IdentityMatrix_m[0] = 1.0F;
  Translation_Fusion_B.IdentityMatrix_m[4] = 1.0F;
  Translation_Fusion_B.IdentityMatrix_m[8] = 1.0F;
  Translation_Fusion_B.IdentityMatrix_kr[0] = 1.0F;
  Translation_Fusion_B.IdentityMatrix_kr[4] = 1.0F;
  Translation_Fusion_B.IdentityMatrix_kr[8] = 1.0F;
  Translation_Fusio_Average_Start(&Translation_Fusion_DW.MovingAverage_p);
  Translation_Fusio_Average_Start(&Translation_Fusion_DW.MovingAverage1);
  memset(&Translation_Fusion_B.IdentityMatrix_f[0], 0, sizeof(real32_T) << 4U);
  Translation_Fusion_B.IdentityMatrix_f[0] = 1.0F;
  Translation_Fusion_B.IdentityMatrix_f[5] = 1.0F;
  Translation_Fusion_B.IdentityMatrix_f[10] = 1.0F;
  Translation_Fusion_B.IdentityMatrix_f[15] = 1.0F;
  Translatio_MovingAverage1_Start(&Translation_Fusion_DW.MovingAverage_pn);
  Translatio_MovingAverage1_Start(&Translation_Fusion_DW.MovingAverage1_pn);
  Translat_MovingAverage1_p_Start(&Translation_Fusion_DW.MovingAverage_pna);
  Translat_MovingAverage1_p_Start(&Translation_Fusion_DW.MovingAverage1_pna);
  memset(&Translation_Fusion_B.IdentityMatrix_k[0], 0, sizeof(real32_T) << 4U);
  Translation_Fusion_B.IdentityMatrix_k[0] = 1.0F;
  Translation_Fusion_B.IdentityMatrix_k[5] = 1.0F;
  Translation_Fusion_B.IdentityMatrix_k[10] = 1.0F;
  Translation_Fusion_B.IdentityMatrix_k[15] = 1.0F;
  Translatio_MovingAverage3_Start(&Translation_Fusion_DW.MovingAverage2);
  Translatio_MovingAverage3_Start(&Translation_Fusion_DW.MovingAverage3);
  Translation_Fusion_DW.obj_a.matlabCodegenIsDeleted = true;
  Translation_Fusion_DW.obj_a.isInitialized = 0;
  Translation_Fusion_DW.obj_a.NumChannels = -1;
  Translation_Fusion_DW.obj_a.matlabCodegenIsDeleted = false;
  Translation_Fusion_DW.objisempty = true;
  Translation_Fusion_DW.obj_a.isSetupComplete = false;
  Translation_Fusion_DW.obj_a.isInitialized = 1;
  Translation_Fusion_DW.obj_a.NumChannels = 1;
  Translation_Fusion_DW.gobj_0_e.isInitialized = 0;
  Translation_Fusion_DW.obj_a.pStatistic = &Translation_Fusion_DW.gobj_0_e;
  Translation_Fusion_DW.obj_a.isSetupComplete = true;
  Translation_Fusion_DW.obj_a.TunablePropsChanged = false;
}

void Translation_Fusion(const real32_T rtu_Rotation_M_OB[9], const real32_T
  rtu_Rotation_rot_IB_B_radDs[3], const real32_T rtu_Rotation_sfor_R_B_mDs2[3],
  const real32_T *rtu_Rotation_Psi_dot_fused, const real32_T
  *rtu_Rotation_Psi_dot_IMU, const real32_T rtu_Rotation_M_OObar[4], const
  real32_T *rtu_Rotation_Euler_Transformati, const real32_T
  *rtu_Rotation_Euler_Transforma_h, const real32_T
  *rtu_Rotation_Euler_Transforma_k, const real32_T *rtu_Rotation_standstill,
  const boolean_T *rtu_Rotation_reset_Yaw, const real32_T
  *rtu_Sensor_delta_h_baro_m, const boolean_T *rtu_Sensor_baro_valid, const
  real32_T *rtu_Sensor_baro_Timestamp_ms, const boolean_T
  *rtu_Sensor_GPS_data_GPS_reset, const real32_T
  *rtu_Sensor_GPS_data_Spd_quality, const real32_T
  *rtu_Sensor_GPS_data_Pos_quality, const real32_T *rtu_Sensor_GPS_data_Status,
  const real_T *rtu_Sensor_GPS_data_dx_dmue, const real_T
  *rtu_Sensor_GPS_data_dy_dlambda, const real_T *rtu_Sensor_GPS_data_mue_rad,
  const real_T *rtu_Sensor_GPS_data_lambda_rad, const real32_T
  *rtu_Sensor_GPS_data_vel_N, const real32_T *rtu_Sensor_GPS_data_vel_E, const
  real32_T *rtu_Sensor_GPS_data_vel_D, const real32_T
  *rtu_Sensor_GPS_data_Timestamp_m, const real32_T
  *rtu_Sensor_GPS_data_GpsHeight, const uint8_T *rtu_Sensor_RTK_Data_RTK_status,
  const real32_T rtu_Sensor_RTK_Data_pos_quality[3], const real32_T
  rtu_Sensor_RTK_Data_vel_quality[3], const uint32_T
  *rtu_Sensor_RTK_Data_rtk_type, const real_T *rtu_Sensor_RTK_Data_dx_dmue,
  const real_T *rtu_Sensor_RTK_Data_dy_dlambda, const real_T
  *rtu_Sensor_RTK_Data_dz_dh, const real_T *rtu_Sensor_RTK_Data_mue_rad, const
  real_T *rtu_Sensor_RTK_Data_lambda_rad, const real_T
  *rtu_Sensor_RTK_Data_height_m, const real32_T *rtu_Sensor_RTK_Data_vel_N,
  const real32_T *rtu_Sensor_RTK_Data_vel_E, const real32_T
  *rtu_Sensor_RTK_Data_vel_D, const uint32_T *rtu_Sensor_RTK_Data_Timestamp_m,
  const boolean_T *rtu_Sensor_Sonar_data_sonar_val, const real32_T
  *rtu_Sensor_Sonar_data_h_grd_son, const uint32_T
  *rtu_Sensor_Sonar_data_timestamp, const real32_T
  rtu_Sensor_Vision_data_vel_xy_O[2], const real32_T
  *rtu_Sensor_Vision_data_Vision_q, const boolean_T
  *rtu_Sensor_Vision_data_Vision_v, const uint32_T
  *rtu_Sensor_Vision_data_timestam, const real32_T
  *rtu_Sensor_Vision_data_vel_z_O_, const real32_T
  *rtu_Sensor_Vision_data_delta_po, const real32_T
  *rtu_Sensor_Vision_data_delta__d, const real32_T
  *rtu_Sensor_Vision_data_delta__m, const uint8_T *rtu_Sensor_Vision_data_type,
  const boolean_T *rtu_Armed, const boolean_T *rtu_Ongrd_flag, const boolean_T
  *rtu_hover_flag, const real32_T *rtu_mode, const boolean_T *rtu_forcedArm,
  const boolean_T *rtu_IMU_switch, real32_T *rty_Translation_data_h_dot_mDs,
  real32_T *rty_Translation_data_h_AGL_m, real32_T
  *rty_Translation_data_h_0_AGL_m, real32_T *rty_Translation_data_delta_h_m,
  real32_T *rty_Translation_data_Bias_z_mDs, real32_T
  rty_Translation_data_VEL_xy_O_m[2], real32_T rty_Translation_data_ACC_xy_O_m[2],
  real_T *rty_Translation_data_mue_est_ra, real_T
  *rty_Translation_data_lambda_est, real32_T rty_Translation_data_POS_xy_O_m[2],
  boolean_T *rty_Translation_data_POS_reset_, boolean_T
  *rty_Translation_data_GPS_Vel_Va, boolean_T *rty_Translation_data_VO_Vel_Val,
  real_T *rty_Translation_data_mue_est__e, real_T
  *rty_Translation_data_lambda_e_o, real32_T rty_acc_bias_B[3], boolean_T
  *rty_RTK_Pos_Good, real32_T *rty_h_MSL, real32_T rty_Vel_G[3], real_T
  rty_Pos_LL_WGS84_Camera[2], boolean_T *rty_Pos_Init_flg, real32_T
  *rty_h_0_m_MSL, real32_T *rty_GPS_logic_log_Status, real32_T
  *rty_GPS_logic_log_Ts_Update, real32_T *rty_GPS_logic_log_En_GPS_cor_co,
  real32_T *rty_GPS_logic_log_En_GPS_Valid, real32_T
  *rty_GPS_logic_log_En_GPS_Correc, real32_T *rty_Vx_cor)
{
  boolean_T rtb_Reset_TF_tmp;
  boolean_T rtb_LogicalOperator1_n_tmp;
  boolean_T tmp;
  boolean_T rtb_Over_15m_tmp;
  Translation_Fusion_B.LogicalOperator1 = !*rtu_Ongrd_flag;
  if (Translation_Fusion_B.LogicalOperator1 ||
      (Translation_Fusion_DW.DiscreteTimeIntegrator_PrevRese != 0)) {
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE =
      Translation_Fusion_P_g.DiscreteTimeIntegrator_IC;
  }

  if (Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE >=
      Translation_Fusion_P_g.DiscreteTimeIntegrator_UpperSat) {
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE =
      Translation_Fusion_P_g.DiscreteTimeIntegrator_UpperSat;
  } else {
    if (Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE <=
        Translation_Fusion_P_g.DiscreteTimeIntegrator_LowerSat) {
      Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE =
        Translation_Fusion_P_g.DiscreteTimeIntegrator_LowerSat;
    }
  }

  Translation_Fusion_B.Compare_i =
    (Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE >
     Translation_Fusion_P_g.Validafteraperiod_T_p);
  for (Translation_Fusion_B.rtb_GPS_gain_tmp = 0;
       Translation_Fusion_B.rtb_GPS_gain_tmp < 3;
       Translation_Fusion_B.rtb_GPS_gain_tmp++) {
    Translation_Fusion_B.sfor_R_O_mDs2[Translation_Fusion_B.rtb_GPS_gain_tmp] =
      rtu_Rotation_M_OB[Translation_Fusion_B.rtb_GPS_gain_tmp + 6] *
      rtu_Rotation_sfor_R_B_mDs2[2] +
      (rtu_Rotation_M_OB[Translation_Fusion_B.rtb_GPS_gain_tmp + 3] *
       rtu_Rotation_sfor_R_B_mDs2[1] +
       rtu_Rotation_M_OB[Translation_Fusion_B.rtb_GPS_gain_tmp] *
       rtu_Rotation_sfor_R_B_mDs2[0]);
  }

  Translation_Fusion_B.Sum2 = (0.0F - Translation_Fusion_B.sfor_R_O_mDs2[2]) -
    Translation_Fusion_P_g.Constant2_Value_p;
  if (Translation_Fusion_B.Compare_i && (*rtu_Rotation_standstill != 0.0F)) {
    if (Translation_Fusion_DW.DiscreteTimeIntegrator_IC_LO_oh != 0) {
      Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_i2[0] =
        Translation_Fusion_B.sfor_R_O_mDs2[0];
      Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_i2[1] =
        Translation_Fusion_B.sfor_R_O_mDs2[1];
      Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_i2[2] =
        Translation_Fusion_B.Sum2;
    }

    Translation_Fusion_B.DiscreteTimeIntegrator_d[0] =
      Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_i2[0];
    Translation_Fusion_B.DiscreteTimeIntegrator_d[1] =
      Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_i2[1];
    Translation_Fusion_B.DiscreteTimeIntegrator_d[2] =
      Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_i2[2];
    Translation_Fusi_MovingAverage2
      (Translation_Fusion_B.DiscreteTimeIntegrator_d[0],
       &Translation_Fusion_B.MovingAverage_pnae,
       &Translation_Fusion_DW.MovingAverage_pnae);
    Translation_Fusi_MovingAverage2
      (Translation_Fusion_B.DiscreteTimeIntegrator_d[1],
       &Translation_Fusion_B.MovingAverage1_pnae,
       &Translation_Fusion_DW.MovingAverage1_pnae);
    Translation_Fusi_MovingAverage2
      (Translation_Fusion_B.DiscreteTimeIntegrator_d[2],
       &Translation_Fusion_B.MovingAverage2_p,
       &Translation_Fusion_DW.MovingAverage2_p);
    Translation_Fusion_DW.DiscreteTimeIntegrator_IC_LO_oh = 0U;
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_i2[0] +=
      (Translation_Fusion_B.sfor_R_O_mDs2[0] -
       Translation_Fusion_B.DiscreteTimeIntegrator_d[0]) *
      Translation_Fusion_P_g.Gain_Gain *
      Translation_Fusion_P_g.DiscreteTimeIntegrator_gainval;
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_i2[1] +=
      (Translation_Fusion_B.sfor_R_O_mDs2[1] -
       Translation_Fusion_B.DiscreteTimeIntegrator_d[1]) *
      Translation_Fusion_P_g.Gain_Gain *
      Translation_Fusion_P_g.DiscreteTimeIntegrator_gainval;
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_i2[2] +=
      (Translation_Fusion_B.Sum2 -
       Translation_Fusion_B.DiscreteTimeIntegrator_d[2]) *
      Translation_Fusion_P_g.Gain_Gain *
      Translation_Fusion_P_g.DiscreteTimeIntegrator_gainval;
  }

  rtb_Reset_TF_tmp = !*rtu_Armed;
  Translation_Fusion_B.Reset_TF = (Translation_Fusion_DW.Delay2_DSTATE_h[0] ||
    rtb_Reset_TF_tmp);
  if ((((Translation_Fusion_PrevZCX.Int_X_Reset_ZCE == POS_ZCSIG) != (int32_T)
        Translation_Fusion_B.Reset_TF) &&
       (Translation_Fusion_PrevZCX.Int_X_Reset_ZCE != UNINITIALIZED_ZCSIG)) ||
      Translation_Fusion_B.Reset_TF) {
    Translation_Fusion_DW.icLoad = 1U;
  }

  Translation_Fusion_PrevZCX.Int_X_Reset_ZCE = Translation_Fusion_B.Reset_TF;
  if (Translation_Fusion_DW.icLoad != 0) {
    if (*rtu_Armed) {
      Translation_Fusion_DW.Int_X_DSTATE[0] =
        Translation_Fusion_DW.Delay1_DSTATE[0];
      Translation_Fusion_DW.Int_X_DSTATE[1] =
        Translation_Fusion_DW.Delay1_DSTATE[1];
      Translation_Fusion_DW.Int_X_DSTATE[2] =
        Translation_Fusion_DW.Delay1_DSTATE[2];
      Translation_Fusion_DW.Int_X_DSTATE[3] =
        Translation_Fusion_DW.Delay1_DSTATE[3];
    } else {
      Translation_Fusion_DW.Int_X_DSTATE[0] = Translation_Fusion_P_g.x0_Value[0];
      Translation_Fusion_DW.Int_X_DSTATE[1] = Translation_Fusion_P_g.x0_Value[1];
      Translation_Fusion_DW.Int_X_DSTATE[2] = Translation_Fusion_P_g.x0_Value[2];
      Translation_Fusion_DW.Int_X_DSTATE[3] = Translation_Fusion_P_g.x0_Value[3];
    }
  }

  Translation_Fusion_B.rtb_Int_X_idx_0 = Translation_Fusion_DW.Int_X_DSTATE[0];
  Translation_Fusion_B.rtb_Int_X_idx_1 = Translation_Fusion_DW.Int_X_DSTATE[1];
  Translation_Fusion_B.rtb_Int_X_idx_2 = Translation_Fusion_DW.Int_X_DSTATE[2];
  Translation_Fusion_B.rtb_Int_X_idx_3 = Translation_Fusion_DW.Int_X_DSTATE[3];
  rty_Translation_data_VEL_xy_O_m[0] = Translation_Fusion_DW.Int_X_DSTATE[0];
  rty_Translation_data_VEL_xy_O_m[1] = Translation_Fusion_DW.Int_X_DSTATE[1];
  Translation_Fusion_B.pos_valid = (uint8_T)(*rtu_Sensor_RTK_Data_RTK_status &
    Translation_Fusion_P_g.BitwiseAND_BitMask);
  Translation_Fusion_B.DiscreteTimeIntegrator_ax =
    rtu_Sensor_RTK_Data_pos_quality[0];
  Translation_Fusion_B.rtb_LogicalOperator1_ls_idx_1 = rtIsNaNF
    (rtu_Sensor_RTK_Data_pos_quality[1]);
  if ((!(rtu_Sensor_RTK_Data_pos_quality[0] < rtu_Sensor_RTK_Data_pos_quality[1]))
      && (!Translation_Fusion_B.rtb_LogicalOperator1_ls_idx_1)) {
    Translation_Fusion_B.DiscreteTimeIntegrator_ax =
      rtu_Sensor_RTK_Data_pos_quality[1];
  }

  if (Translation_Fusion_B.DiscreteTimeIntegrator_ax >=
      Translation_Fusion_P_g.Relay2_OnVal) {
    Translation_Fusion_DW.Relay2_Mode = true;
  } else {
    if (Translation_Fusion_B.DiscreteTimeIntegrator_ax <=
        Translation_Fusion_P_g.Relay2_OffVal) {
      Translation_Fusion_DW.Relay2_Mode = false;
    }
  }

  if (Translation_Fusion_DW.Relay2_Mode) {
    Translation_Fusion_B.Sqrt = Translation_Fusion_P_g.Relay2_YOn;
  } else {
    Translation_Fusion_B.Sqrt = Translation_Fusion_P_g.Relay2_YOff;
  }

  Translation_Fusion_B.rtk_pos_valid = ((Translation_Fusion_B.pos_valid != 0) &&
    (Translation_Fusion_B.Sqrt != 0.0F));
  if (Translation_Fusion_B.rtk_pos_valid) {
    Translation_Fusion_B.rtb_WGS84_derivatives_idx_0 =
      *rtu_Sensor_RTK_Data_dx_dmue;
    Translation_Fusion_B.rtb_WGS84_derivatives_idx_1 =
      *rtu_Sensor_RTK_Data_dy_dlambda;
    Translation_Fusion_B.rtb_WGS84_derivatives_g = *rtu_Sensor_RTK_Data_dz_dh;
  } else {
    Translation_Fusion_B.rtb_WGS84_derivatives_idx_0 =
      *rtu_Sensor_GPS_data_dx_dmue;
    Translation_Fusion_B.rtb_WGS84_derivatives_idx_1 =
      *rtu_Sensor_GPS_data_dy_dlambda;
    Translation_Fusion_B.rtb_WGS84_derivatives_g =
      Translation_Fusion_P_g.Constant_Value_f;
  }

  Translation_Fusion_B.Compare_bnu = !*rtu_Sensor_GPS_data_GPS_reset;
  if (*rtu_Sensor_GPS_data_Spd_quality >= Translation_Fusion_P_g.Relay1_OnVal) {
    Translation_Fusion_DW.Relay1_Mode = true;
  } else {
    if (*rtu_Sensor_GPS_data_Spd_quality <= Translation_Fusion_P_g.Relay1_OffVal)
    {
      Translation_Fusion_DW.Relay1_Mode = false;
    }
  }

  if (*rtu_Sensor_GPS_data_Pos_quality >= Translation_Fusion_P_g.Relay_OnVal) {
    Translation_Fusion_DW.Relay_Mode = true;
  } else {
    if (*rtu_Sensor_GPS_data_Pos_quality <= Translation_Fusion_P_g.Relay_OffVal)
    {
      Translation_Fusion_DW.Relay_Mode = false;
    }
  }

  if (Translation_Fusion_DW.Relay1_Mode) {
    Translation_Fusion_B.Sqrt = Translation_Fusion_P_g.Relay1_YOn;
  } else {
    Translation_Fusion_B.Sqrt = Translation_Fusion_P_g.Relay1_YOff;
  }

  if (Translation_Fusion_DW.Relay_Mode) {
    Translation_Fusion_B.DiscreteTimeIntegrator_am =
      Translation_Fusion_P_g.Relay_YOn;
  } else {
    Translation_Fusion_B.DiscreteTimeIntegrator_am =
      Translation_Fusion_P_g.Relay_YOff;
  }

  Translation_Fusion_B.gps_pos_valid_mk = (Translation_Fusion_B.Compare_bnu &&
    (Translation_Fusion_B.Sqrt != 0.0F) &&
    (Translation_Fusion_B.DiscreteTimeIntegrator_am != 0.0F));
  Translation_Fusion_B.Compare_fx = (Translation_Fusion_B.gps_pos_valid_mk ||
    Translation_Fusion_B.rtk_pos_valid);
  Translation_Fusion_B.Compare_e = ((int32_T)Translation_Fusion_B.Compare_fx >
    (int32_T)Translation_Fusion_P_g.Constant_Value_fw);
  Translation_Fusion_B.LogicalOperator_d = (Translation_Fusion_B.rtk_pos_valid &&
    (*rtu_Sensor_RTK_Data_rtk_type >=
     Translation_Fusion_P_g.CompareToConstant_const_c));
  Translation_Fusion_B.Compare_jn = (((int32_T)Translation_Fusion_B.Compare_e >
    (int32_T)Translation_Fusion_DW.DelayInput1_DSTATE_g) &&
    (!Translation_Fusion_B.LogicalOperator_d));
  Translation_Fusion_B.Compare_n = ((int32_T)
    Translation_Fusion_B.LogicalOperator_d > (int32_T)
    Translation_Fusion_P_g.Constant_Value_lk5);
  Translation_Fusion_B.Compare_epn = ((int32_T)Translation_Fusion_B.Compare_n >
    (int32_T)Translation_Fusion_DW.DelayInput1_DSTATE_k3);
  Translation_Fusion_B.reset_ref = (Translation_Fusion_B.Compare_jn ||
    Translation_Fusion_B.Compare_epn || ((Translation_Fusion_B.Compare_fx ||
    Translation_Fusion_B.LogicalOperator_d) && rtb_Reset_TF_tmp));
  if (Translation_Fusion_B.reset_ref) {
    if (Translation_Fusion_B.rtk_pos_valid) {
      Translation_Fusion_B.rtb_WGS84_position_idx_0 =
        *rtu_Sensor_RTK_Data_mue_rad;
      Translation_Fusion_B.rtb_WGS84_position_idx_1 =
        *rtu_Sensor_RTK_Data_lambda_rad;
      Translation_Fusion_B.rtb_WGS84_position_idx_2 =
        *rtu_Sensor_RTK_Data_height_m;
    } else {
      Translation_Fusion_B.rtb_WGS84_position_idx_0 =
        *rtu_Sensor_GPS_data_mue_rad;
      Translation_Fusion_B.rtb_WGS84_position_idx_1 =
        *rtu_Sensor_GPS_data_lambda_rad;
      Translation_Fusion_B.rtb_WGS84_position_idx_2 =
        *rtu_Sensor_GPS_data_GpsHeight;
    }

    Translation_Fusion_B.rtb_WGS84_pos_ref_idx_0 = fabs
      (Translation_Fusion_B.rtb_WGS84_derivatives_idx_0);
    Translation_Fusion_B.rtb_WGS84_pos_ref_idx_1 = fabs
      (Translation_Fusion_B.rtb_WGS84_derivatives_idx_1);
    if ((Translation_Fusion_B.rtb_WGS84_pos_ref_idx_0 <
         Translation_Fusion_B.rtb_WGS84_pos_ref_idx_1) || rtIsNaN
        (Translation_Fusion_B.rtb_WGS84_pos_ref_idx_1)) {
      Translation_Fusion_B.rtb_test1_k_idx_0 =
        Translation_Fusion_B.rtb_WGS84_pos_ref_idx_0;
    } else {
      Translation_Fusion_B.rtb_test1_k_idx_0 =
        Translation_Fusion_B.rtb_WGS84_pos_ref_idx_1;
    }

    if (Translation_Fusion_B.rtb_test1_k_idx_0 <
        Translation_Fusion_P_g.CompareToConstant_const) {
      Translation_Fusion_B.rtb_test1_k_idx_0 =
        Translation_Fusion_P_g.Constant_Value_m[0];
      Translation_Fusion_B.rtb_test1_k_idx_1 =
        Translation_Fusion_P_g.Constant_Value_m[1];
    } else {
      if (Translation_Fusion_B.rtb_WGS84_derivatives_idx_0 < 0.0) {
        Translation_Fusion_B.rtb_DataTypeConversion3_g_idx_0 = -1.0;
      } else if (Translation_Fusion_B.rtb_WGS84_derivatives_idx_0 > 0.0) {
        Translation_Fusion_B.rtb_DataTypeConversion3_g_idx_0 = 1.0;
      } else if (Translation_Fusion_B.rtb_WGS84_derivatives_idx_0 == 0.0) {
        Translation_Fusion_B.rtb_DataTypeConversion3_g_idx_0 =
          Translation_Fusion_P_g.Constant_Value;
      } else {
        Translation_Fusion_B.rtb_DataTypeConversion3_g_idx_0 = (rtNaN);
      }

      if (Translation_Fusion_B.rtb_WGS84_pos_ref_idx_0 >
          Translation_Fusion_P_g.Saturation_UpperSat_c) {
        Translation_Fusion_B.rtb_WGS84_pos_ref_idx_0 =
          Translation_Fusion_P_g.Saturation_UpperSat_c;
      } else {
        if (Translation_Fusion_B.rtb_WGS84_pos_ref_idx_0 <
            Translation_Fusion_P_g.Zero_Value_Exclusion_thr) {
          Translation_Fusion_B.rtb_WGS84_pos_ref_idx_0 =
            Translation_Fusion_P_g.Zero_Value_Exclusion_thr;
        }
      }

      Translation_Fusion_B.rtb_test1_k_idx_0 =
        Translation_Fusion_P_g.Gain_Gain_g *
        Translation_Fusion_DW.Delay_10_DSTATE[0] /
        (Translation_Fusion_B.rtb_WGS84_pos_ref_idx_0 *
         Translation_Fusion_B.rtb_DataTypeConversion3_g_idx_0);
      if (Translation_Fusion_B.rtb_WGS84_derivatives_idx_1 < 0.0) {
        Translation_Fusion_B.rtb_DataTypeConversion3_g_idx_0 = -1.0;
      } else if (Translation_Fusion_B.rtb_WGS84_derivatives_idx_1 > 0.0) {
        Translation_Fusion_B.rtb_DataTypeConversion3_g_idx_0 = 1.0;
      } else if (Translation_Fusion_B.rtb_WGS84_derivatives_idx_1 == 0.0) {
        Translation_Fusion_B.rtb_DataTypeConversion3_g_idx_0 =
          Translation_Fusion_P_g.Constant_Value;
      } else {
        Translation_Fusion_B.rtb_DataTypeConversion3_g_idx_0 = (rtNaN);
      }

      if (Translation_Fusion_B.rtb_WGS84_pos_ref_idx_1 >
          Translation_Fusion_P_g.Saturation_UpperSat_c) {
        Translation_Fusion_B.rtb_WGS84_pos_ref_idx_1 =
          Translation_Fusion_P_g.Saturation_UpperSat_c;
      } else {
        if (Translation_Fusion_B.rtb_WGS84_pos_ref_idx_1 <
            Translation_Fusion_P_g.Zero_Value_Exclusion_thr) {
          Translation_Fusion_B.rtb_WGS84_pos_ref_idx_1 =
            Translation_Fusion_P_g.Zero_Value_Exclusion_thr;
        }
      }

      Translation_Fusion_B.rtb_test1_k_idx_1 =
        Translation_Fusion_P_g.Gain_Gain_g *
        Translation_Fusion_DW.Delay_10_DSTATE[1] /
        (Translation_Fusion_B.rtb_WGS84_pos_ref_idx_1 *
         Translation_Fusion_B.rtb_DataTypeConversion3_g_idx_0);
    }

    Translation_Fusion_B.rtb_test1_k_idx_0 +=
      Translation_Fusion_B.rtb_WGS84_position_idx_0;
    Translation_Fusion_B.rtb_WGS84_pos_ref_idx_1 =
      Translation_Fusion_B.rtb_test1_k_idx_1 +
      Translation_Fusion_B.rtb_WGS84_position_idx_1;
    if (Translation_Fusion_B.rtb_test1_k_idx_0 >
        Translation_Fusion_P_g.Saturation_UpperSat) {
      Translation_Fusion_B.rtb_WGS84_pos_ref_idx_0 =
        Translation_Fusion_P_g.Saturation_UpperSat;
    } else if (Translation_Fusion_B.rtb_test1_k_idx_0 <
               Translation_Fusion_P_g.Saturation_LowerSat) {
      Translation_Fusion_B.rtb_WGS84_pos_ref_idx_0 =
        Translation_Fusion_P_g.Saturation_LowerSat;
    } else {
      Translation_Fusion_B.rtb_WGS84_pos_ref_idx_0 =
        Translation_Fusion_B.rtb_test1_k_idx_0;
    }

    if (Translation_Fusion_B.rtb_WGS84_pos_ref_idx_1 >
        Translation_Fusion_P_g.Saturation1_UpperSat) {
      Translation_Fusion_B.rtb_WGS84_pos_ref_idx_1 =
        Translation_Fusion_P_g.Saturation1_UpperSat;
    } else {
      if (Translation_Fusion_B.rtb_WGS84_pos_ref_idx_1 <
          Translation_Fusion_P_g.Saturation1_LowerSat) {
        Translation_Fusion_B.rtb_WGS84_pos_ref_idx_1 =
          Translation_Fusion_P_g.Saturation1_LowerSat;
      }
    }

    Translation_Fusion_B.rtb_WGS84_pos_ref_idx_2 =
      Translation_Fusion_B.rtb_WGS84_position_idx_2 -
      Translation_Fusion_DW.Delay_2_DSTATE;
  } else {
    Translation_Fusion_B.rtb_WGS84_pos_ref_idx_0 =
      Translation_Fusion_DW.memory1_PreviousInput[0];
    Translation_Fusion_B.rtb_WGS84_pos_ref_idx_1 =
      Translation_Fusion_DW.memory1_PreviousInput[1];
    Translation_Fusion_B.rtb_WGS84_pos_ref_idx_2 =
      Translation_Fusion_DW.memory1_PreviousInput[2];
  }

  *rty_h_0_m_MSL = (real32_T)Translation_Fusion_B.rtb_WGS84_pos_ref_idx_2;
  if (*rtu_Sensor_GPS_data_Spd_quality >= Translation_Fusion_P_g.Relay2_OnVal_i)
  {
    Translation_Fusion_DW.Relay2_Mode_e = true;
  } else {
    if (*rtu_Sensor_GPS_data_Spd_quality <=
        Translation_Fusion_P_g.Relay2_OffVal_k) {
      Translation_Fusion_DW.Relay2_Mode_e = false;
    }
  }

  if (Translation_Fusion_DW.Relay2_Mode_e) {
    Translation_Fusion_B.Sqrt = Translation_Fusion_P_g.Relay2_YOn_j;
  } else {
    Translation_Fusion_B.Sqrt = Translation_Fusion_P_g.Relay2_YOff_h;
  }

  Translation_Fusion_B.GPS_Good = (Translation_Fusion_B.Compare_bnu &&
    (Translation_Fusion_B.Sqrt != 0.0F));
  Translation_Fusion_B.GPS_gain = rtu_Sensor_RTK_Data_pos_quality[0];
  if ((!(rtu_Sensor_RTK_Data_pos_quality[0] < rtu_Sensor_RTK_Data_pos_quality[1]))
      && (!Translation_Fusion_B.rtb_LogicalOperator1_ls_idx_1)) {
    Translation_Fusion_B.GPS_gain = rtu_Sensor_RTK_Data_pos_quality[1];
  }

  if (Translation_Fusion_B.GPS_gain >= Translation_Fusion_P_g.Relay1_OnVal_c) {
    Translation_Fusion_DW.Relay1_Mode_k = true;
  } else {
    if (Translation_Fusion_B.GPS_gain <= Translation_Fusion_P_g.Relay1_OffVal_b)
    {
      Translation_Fusion_DW.Relay1_Mode_k = false;
    }
  }

  if (Translation_Fusion_B.GPS_gain >= Translation_Fusion_P_g.Relay_OnVal_k) {
    Translation_Fusion_DW.Relay_Mode_m = true;
  } else {
    if (Translation_Fusion_B.GPS_gain <= Translation_Fusion_P_g.Relay_OffVal_f)
    {
      Translation_Fusion_DW.Relay_Mode_m = false;
    }
  }

  if (Translation_Fusion_B.pos_valid > Translation_Fusion_P_g.Switch_Threshold_g)
  {
    if (Translation_Fusion_DW.Relay_Mode_m) {
      Translation_Fusion_B.Sqrt = Translation_Fusion_P_g.Relay_YOn_m;
    } else {
      Translation_Fusion_B.Sqrt = Translation_Fusion_P_g.Relay_YOff_p;
    }

    if (Translation_Fusion_B.Sqrt > Translation_Fusion_P_g.Switch1_Threshold) {
      if (Translation_Fusion_DW.Relay1_Mode_k) {
        Translation_Fusion_B.Sqrt = Translation_Fusion_P_g.Relay1_YOn_i;
      } else {
        Translation_Fusion_B.Sqrt = Translation_Fusion_P_g.Relay1_YOff_j;
      }

      if (Translation_Fusion_B.Sqrt > Translation_Fusion_P_g.Switch2_Threshold)
      {
        Translation_Fusion_B.DiscreteTimeIntegrator_ax =
          Translation_Fusion_P_g.Constant2_Value;
      } else if (Translation_Fusion_B.GPS_Good) {
        Translation_Fusion_B.DiscreteTimeIntegrator_ax =
          Translation_Fusion_P_g.Constant5_Value;
      } else {
        Translation_Fusion_B.DiscreteTimeIntegrator_ax =
          Translation_Fusion_P_g.Constant3_Value;
      }
    } else {
      Translation_Fusion_B.DiscreteTimeIntegrator_ax =
        Translation_Fusion_P_g.Constant1_Value;
    }
  } else {
    Translation_Fusion_B.DiscreteTimeIntegrator_ax =
      Translation_Fusion_P_g.Constant_Value_cc;
  }

  Translation_Fusion_B.Sum_ol = Translation_Fusion_P_g.Constant4_Value_p -
    Translation_Fusion_B.DiscreteTimeIntegrator_ax;
  if (Translation_Fusion_B.Sum_ol > Translation_Fusion_P_g.Saturation_UpperSat_h)
  {
    Translation_Fusion_B.Sum_ol = Translation_Fusion_P_g.Saturation_UpperSat_h;
  } else {
    if (Translation_Fusion_B.Sum_ol <
        Translation_Fusion_P_g.Saturation_LowerSat_m) {
      Translation_Fusion_B.Sum_ol = Translation_Fusion_P_g.Saturation_LowerSat_m;
    }
  }

  Translation_Fusion_B.GPS_gain = (real32_T)Translation_Fusion_B.GPS_Good *
    Translation_Fusion_B.Sum_ol;
  Translation_Fusion_B.GPS_Good =
    (Translation_Fusion_B.DiscreteTimeIntegrator_ax >
     Translation_Fusion_P_g.Constant_Value_ml);
  Translation_Fusion_B.Relay = (real32_T)((int32_T)
    *rtu_Sensor_Sonar_data_sonar_val > (int32_T)
    Translation_Fusion_P_g.Constant_Value_l1);
  if (*rtu_Sensor_GPS_data_Spd_quality >= Translation_Fusion_P_g.Relay2_OnVal_p)
  {
    Translation_Fusion_DW.Relay2_Mode_e3 = true;
  } else {
    if (*rtu_Sensor_GPS_data_Spd_quality <=
        Translation_Fusion_P_g.Relay2_OffVal_d) {
      Translation_Fusion_DW.Relay2_Mode_e3 = false;
    }
  }

  if (Translation_Fusion_DW.Relay2_Mode_e3) {
    Translation_Fusion_B.Sqrt = Translation_Fusion_P_g.Relay2_YOn_c;
  } else {
    Translation_Fusion_B.Sqrt = Translation_Fusion_P_g.Relay2_YOff_m;
  }

  Translation_Fusion_B.LogicalOperator_l = (Translation_Fusion_B.Compare_bnu &&
    (Translation_Fusion_B.Sqrt != 0.0F));
  if (rtu_Sensor_RTK_Data_pos_quality[2] >=
      Translation_Fusion_P_g.Relay1_OnVal_p) {
    Translation_Fusion_DW.Relay1_Mode_p = true;
  } else {
    if (rtu_Sensor_RTK_Data_pos_quality[2] <=
        Translation_Fusion_P_g.Relay1_OffVal_j) {
      Translation_Fusion_DW.Relay1_Mode_p = false;
    }
  }

  if (rtu_Sensor_RTK_Data_pos_quality[2] >= Translation_Fusion_P_g.Relay_OnVal_m)
  {
    Translation_Fusion_DW.Relay_Mode_md = true;
  } else {
    if (rtu_Sensor_RTK_Data_pos_quality[2] <=
        Translation_Fusion_P_g.Relay_OffVal_h) {
      Translation_Fusion_DW.Relay_Mode_md = false;
    }
  }

  if (Translation_Fusion_DW.Relay_Mode_md) {
    Translation_Fusion_B.Sqrt = Translation_Fusion_P_g.Relay_YOn_j;
  } else {
    Translation_Fusion_B.Sqrt = Translation_Fusion_P_g.Relay_YOff_b;
  }

  if (Translation_Fusion_DW.Relay1_Mode_p) {
    Translation_Fusion_B.DiscreteTimeIntegrator_am =
      Translation_Fusion_P_g.Relay1_YOn_g;
  } else {
    Translation_Fusion_B.DiscreteTimeIntegrator_am =
      Translation_Fusion_P_g.Relay1_YOff_c;
  }

  if (Translation_Fusion_B.pos_valid > Translation_Fusion_P_g.Switch_Threshold_l)
  {
    if (Translation_Fusion_B.Sqrt > Translation_Fusion_P_g.Switch1_Threshold_g)
    {
      if (Translation_Fusion_B.DiscreteTimeIntegrator_am >
          Translation_Fusion_P_g.Switch2_Threshold_h) {
        Translation_Fusion_B.DiscreteTimeIntegrator_am =
          Translation_Fusion_P_g.Constant2_Value_n;
      } else if (Translation_Fusion_B.LogicalOperator_l) {
        Translation_Fusion_B.DiscreteTimeIntegrator_am =
          Translation_Fusion_P_g.Constant5_Value_b;
      } else {
        Translation_Fusion_B.DiscreteTimeIntegrator_am =
          Translation_Fusion_P_g.Constant3_Value_j;
      }
    } else {
      Translation_Fusion_B.DiscreteTimeIntegrator_am =
        Translation_Fusion_P_g.Constant1_Value_l;
    }
  } else {
    Translation_Fusion_B.DiscreteTimeIntegrator_am =
      Translation_Fusion_P_g.Constant_Value_fb;
  }

  Translation_Fusion_B.DiscreteTimeIntegrator_ax =
    Translation_Fusion_B.DiscreteTimeIntegrator_am - (real32_T)
    (*rtu_Sensor_RTK_Data_rtk_type <=
     Translation_Fusion_P_g.CompareToConstant_const_h) *
    Translation_Fusion_B.Relay;
  if (Translation_Fusion_B.DiscreteTimeIntegrator_ax >
      Translation_Fusion_P_g.Saturation2_UpperSat) {
    Translation_Fusion_B.DiscreteTimeIntegrator_ax =
      Translation_Fusion_P_g.Saturation2_UpperSat;
  } else {
    if (Translation_Fusion_B.DiscreteTimeIntegrator_ax <
        Translation_Fusion_P_g.Saturation2_LowerSat) {
      Translation_Fusion_B.DiscreteTimeIntegrator_ax =
        Translation_Fusion_P_g.Saturation2_LowerSat;
    }
  }

  Translation_Fusion_B.Sum_ol = (Translation_Fusion_P_g.Constant4_Value_a -
    Translation_Fusion_B.DiscreteTimeIntegrator_ax) - Translation_Fusion_B.Relay;
  if (Translation_Fusion_B.Sum_ol >
      Translation_Fusion_P_g.Saturation_UpperSat_hn) {
    Translation_Fusion_B.Sum_ol = Translation_Fusion_P_g.Saturation_UpperSat_hn;
  } else {
    if (Translation_Fusion_B.Sum_ol <
        Translation_Fusion_P_g.Saturation_LowerSat_j) {
      Translation_Fusion_B.Sum_ol = Translation_Fusion_P_g.Saturation_LowerSat_j;
    }
  }

  Translation_Fusion_B.DiscreteTimeIntegrator_am = (real32_T)
    Translation_Fusion_B.LogicalOperator_l * Translation_Fusion_B.Sum_ol;
  Translation_Fusion_B.LogicalOperator_l =
    (Translation_Fusion_B.DiscreteTimeIntegrator_ax >
     Translation_Fusion_P_g.Constant_Value_gs);
  Translation_Fusion_B.LogicalOperator3 = ((Translation_Fusion_B.GPS_gain >
    Translation_Fusion_P_g.Constant_Value_dr) || Translation_Fusion_B.GPS_Good);
  Translation_Fusion_B.Sum_ol = (((real32_T)*rtu_Sensor_baro_valid -
    Translation_Fusion_B.DiscreteTimeIntegrator_ax) -
    Translation_Fusion_B.DiscreteTimeIntegrator_am) - Translation_Fusion_B.Relay;
  if (Translation_Fusion_B.Sum_ol >
      Translation_Fusion_P_g.Saturation1_UpperSat_a) {
    Translation_Fusion_B.Sum_ol = Translation_Fusion_P_g.Saturation1_UpperSat_a;
  } else {
    if (Translation_Fusion_B.Sum_ol <
        Translation_Fusion_P_g.Saturation1_LowerSat_g) {
      Translation_Fusion_B.Sum_ol =
        Translation_Fusion_P_g.Saturation1_LowerSat_g;
    }
  }

  Translation_Fusion_B.LogicalOperator4_a =
    ((Translation_Fusion_B.DiscreteTimeIntegrator_am >
      Translation_Fusion_P_g.Constant_Value_ig) ||
     Translation_Fusion_B.LogicalOperator_l || (Translation_Fusion_B.Relay >
      Translation_Fusion_P_g.Constant_Value_nr) || (Translation_Fusion_B.Sum_ol >
      Translation_Fusion_P_g.Constant_Value_ac));
  Translation_Fusion_B.Compare_fx = ((int32_T)
    Translation_Fusion_B.LogicalOperator_d > (int32_T)
    Translation_Fusion_DW.DelayInput1_DSTATE_e);
  Translation_Fusion_B.LogicalOperator1_g = (((int32_T)
    Translation_Fusion_B.LogicalOperator4_a > (int32_T)
    Translation_Fusion_DW.DelayInput1_DSTATE_ku) ||
    (Translation_Fusion_P_g.Constant_Value_i3 != 0.0) ||
    Translation_Fusion_B.Compare_fx);
  Translation_Fusion_B.LogicalOperator2_h = (((int32_T)
    Translation_Fusion_B.LogicalOperator3 > (int32_T)
    Translation_Fusion_DW.DelayInput1_DSTATE_g3) ||
    (Translation_Fusion_P_g.Constant_Value_i3 != 0.0) ||
    Translation_Fusion_B.Compare_fx);
  *rty_Pos_Init_flg = Translation_Fusion_DW.Delay_DSTATE_g[0];
  if (!Translation_Fusion_B.reset_ref) {
    Translation_Fusion_B.rtb_WGS84_derivatives_idx_0 =
      Translation_Fusion_DW.memory_PreviousInput[0];
    Translation_Fusion_B.rtb_WGS84_derivatives_idx_1 =
      Translation_Fusion_DW.memory_PreviousInput[1];
    Translation_Fusion_B.rtb_WGS84_derivatives_g =
      Translation_Fusion_DW.memory_PreviousInput[2];
  }

  if (Translation_Fusion_B.Compare_jn || Translation_Fusion_B.Compare_epn) {
    Translation_Fusion_B.Switch3_b2 = Translation_Fusion_P_g.Constant_Value_d4d;
  } else {
    Translation_Fusion_B.Switch3_b2 = Translation_Fusion_DW.UnitDelay_DSTATE_p;
  }

  Translation_Fusion_B.rtk_pos_valid_h = ((Translation_Fusion_B.pos_valid != 0) &&
    (rtu_Sensor_RTK_Data_pos_quality[2] >
     Translation_Fusion_P_g.Constant_Value_h));
  Translation_Fusion_B.GPS_gain = rtu_Sensor_RTK_Data_vel_quality[0];
  Translation_Fusion_B.rtb_LogicalOperator1_ls_idx_1 = rtIsNaNF
    (rtu_Sensor_RTK_Data_vel_quality[1]);
  if ((!(rtu_Sensor_RTK_Data_vel_quality[0] < rtu_Sensor_RTK_Data_vel_quality[1]))
      && (!Translation_Fusion_B.rtb_LogicalOperator1_ls_idx_1)) {
    Translation_Fusion_B.GPS_gain = rtu_Sensor_RTK_Data_vel_quality[1];
  }

  Translation_Fusion_B.gps_pos_valid = (Translation_Fusion_B.Compare_bnu &&
    (*rtu_Sensor_GPS_data_Spd_quality > Translation_Fusion_P_g.Constant_Value_ea));
  Translation_Fusion_B.Sum2_a = (uint8_T)(*rtu_Sensor_RTK_Data_RTK_status &
    Translation_Fusion_P_g.BitwiseAND1_BitMask);
  Translation_Fusion_B.rtk_pos_valid_m = ((Translation_Fusion_B.Sum2_a != 0) &&
    (Translation_Fusion_B.GPS_gain > Translation_Fusion_P_g.Constant_Value_kw));
  Translation_Fusion_B.gps_pos_valid_m = (Translation_Fusion_B.Compare_bnu &&
    (*rtu_Sensor_GPS_data_Spd_quality > Translation_Fusion_P_g.Constant_Value_el));
  Translation_Fusion_B.rtk_pos_valid_j = ((Translation_Fusion_B.Sum2_a != 0) &&
    (rtu_Sensor_RTK_Data_vel_quality[2] >
     Translation_Fusion_P_g.Constant_Value_hg));
  Translation_Fusion_B.Relay = Translation_Fusion_P_g.SampleTime_WtEt_e;
  Translation_Fusion_B.DiscreteTimeIntegrator_am = (real32_T)*rtu_Armed *
    Translation_Fusion_B.Sum2;
  if (rtb_Reset_TF_tmp) {
    Translation_Fusion_DW.icLoad_k = 1U;
  }

  if (Translation_Fusion_DW.icLoad_k != 0) {
    Translation_Fusion_DW.Delay1_DSTATE_n[0] =
      Translation_Fusion_P_g.Constant1_Value_no[0];
    Translation_Fusion_DW.Delay1_DSTATE_n[1] =
      Translation_Fusion_P_g.Constant1_Value_no[1];
    Translation_Fusion_DW.Delay1_DSTATE_n[2] =
      Translation_Fusion_P_g.Constant1_Value_no[2];
  }

  Translation_Fusion_B.Delay1_f[0] = Translation_Fusion_DW.Delay1_DSTATE_n[0];
  Translation_Fusion_B.Delay1_f[1] = Translation_Fusion_DW.Delay1_DSTATE_n[1];
  Translation_Fusion_B.Delay1_f[2] = Translation_Fusion_DW.Delay1_DSTATE_n[2];
  Translation_Fusion_B.Subtract = Translation_Fusion_B.DiscreteTimeIntegrator_am
    - Translation_Fusion_DW.Delay1_DSTATE_n[2];
  Translation_Fusion_Average(Translation_Fusion_B.Subtract,
    &Translation_Fusion_B.Average, &Translation_Fusion_DW.Average);
  Translation_Fusion_B.Sum2 = (real32_T)!(*rtu_Rotation_standstill != 0.0F) *
    *rtu_Sensor_GPS_data_vel_D * (real32_T)*rtu_Armed *
    Translation_Fusion_P_g.Gain4_Gain_o;
  Translation_Fusion_B.Relay_e =
    Translation_Fusion_P_g.ust_orderdelaycompensator_N *
    Translation_Fusion_B.Average.Average * Translation_Fusion_B.Relay +
    Translation_Fusion_B.Sum2;
  Translation_Fusion_B.DiscreteTimeIntegrator_ax =
    Translation_Fusion_P_g.SampleTime_WtEt_p;
  Translation_Fusion_B.Relay = Translation_Fusion_P_g.SampleTime_WtEt_f;
  for (Translation_Fusion_B.i = 0; Translation_Fusion_B.i < 9;
       Translation_Fusion_B.i++) {
    Translation_Fusion_B.Product_i[Translation_Fusion_B.i] =
      Translation_Fusion_P_g.Ac_Value[Translation_Fusion_B.i] *
      Translation_Fusion_P_g.SampleTime_WtEt_f;
  }

  for (Translation_Fusion_B.rtb_GPS_gain_tmp = 0;
       Translation_Fusion_B.rtb_GPS_gain_tmp < 3;
       Translation_Fusion_B.rtb_GPS_gain_tmp++) {
    for (Translation_Fusion_B.i = 0; Translation_Fusion_B.i < 3;
         Translation_Fusion_B.i++) {
      Translation_Fusion_B.DataTypeConversion_ew = Translation_Fusion_B.i + 3 *
        Translation_Fusion_B.rtb_GPS_gain_tmp;
      Translation_Fusion_B.rtb_Product_i_b[Translation_Fusion_B.DataTypeConversion_ew]
        = 0.0F;
      Translation_Fusion_B.DataTypeConversion_bx = 3 *
        Translation_Fusion_B.rtb_GPS_gain_tmp + Translation_Fusion_B.i;
      Translation_Fusion_B.rtb_Product_i_b[Translation_Fusion_B.DataTypeConversion_ew]
        =
        Translation_Fusion_B.rtb_Product_i_b[Translation_Fusion_B.DataTypeConversion_bx]
        + Translation_Fusion_B.Product_i[3 *
        Translation_Fusion_B.rtb_GPS_gain_tmp] *
        Translation_Fusion_B.Product_i[Translation_Fusion_B.i];
      Translation_Fusion_B.rtb_Product_i_b[Translation_Fusion_B.DataTypeConversion_ew]
        = Translation_Fusion_B.Product_i[3 *
        Translation_Fusion_B.rtb_GPS_gain_tmp + 1] *
        Translation_Fusion_B.Product_i[Translation_Fusion_B.i + 3] +
        Translation_Fusion_B.rtb_Product_i_b[Translation_Fusion_B.DataTypeConversion_bx];
      Translation_Fusion_B.rtb_Product_i_b[Translation_Fusion_B.DataTypeConversion_ew]
        = Translation_Fusion_B.Product_i[3 *
        Translation_Fusion_B.rtb_GPS_gain_tmp + 2] *
        Translation_Fusion_B.Product_i[Translation_Fusion_B.i + 6] +
        Translation_Fusion_B.rtb_Product_i_b[Translation_Fusion_B.DataTypeConversion_bx];
    }
  }

  for (Translation_Fusion_B.rtb_GPS_gain_tmp = 0;
       Translation_Fusion_B.rtb_GPS_gain_tmp < 9;
       Translation_Fusion_B.rtb_GPS_gain_tmp++) {
    Translation_Fusion_B.MatrixMultiply4_n[Translation_Fusion_B.rtb_GPS_gain_tmp]
      =
      (Translation_Fusion_B.IdentityMatrix[Translation_Fusion_B.rtb_GPS_gain_tmp]
       + Translation_Fusion_B.Product_i[Translation_Fusion_B.rtb_GPS_gain_tmp])
      + Translation_Fusion_P_g.Gain_Gain_f *
      Translation_Fusion_B.rtb_Product_i_b[Translation_Fusion_B.rtb_GPS_gain_tmp];
    Translation_Fusion_B.rtb_TmpSignalConversionAtMult_p[Translation_Fusion_B.rtb_GPS_gain_tmp]
      = (Translation_Fusion_P_g.Gain1_Gain_g *
         Translation_Fusion_B.Product_i[Translation_Fusion_B.rtb_GPS_gain_tmp] +
         Translation_Fusion_B.IdentityMatrix_j[Translation_Fusion_B.rtb_GPS_gain_tmp])
      * Translation_Fusion_P_g.SampleTime_WtEt_f;
  }

  for (Translation_Fusion_B.rtb_GPS_gain_tmp = 0;
       Translation_Fusion_B.rtb_GPS_gain_tmp < 3;
       Translation_Fusion_B.rtb_GPS_gain_tmp++) {
    Translation_Fusion_B.Add_k_g[Translation_Fusion_B.rtb_GPS_gain_tmp] =
      ((Translation_Fusion_B.MatrixMultiply4_n[Translation_Fusion_B.rtb_GPS_gain_tmp
        + 3] * Translation_Fusion_B.Delay1_f[1] +
        Translation_Fusion_B.MatrixMultiply4_n[Translation_Fusion_B.rtb_GPS_gain_tmp]
        * Translation_Fusion_B.Delay1_f[0]) +
       Translation_Fusion_B.MatrixMultiply4_n[Translation_Fusion_B.rtb_GPS_gain_tmp
       + 6] * Translation_Fusion_B.Delay1_f[2]) +
      (Translation_Fusion_B.rtb_TmpSignalConversionAtMult_p[Translation_Fusion_B.rtb_GPS_gain_tmp
       + 6] * Translation_Fusion_P_g.Bc_Value[2] +
       (Translation_Fusion_B.rtb_TmpSignalConversionAtMult_p[Translation_Fusion_B.rtb_GPS_gain_tmp
        + 3] * Translation_Fusion_P_g.Bc_Value[1] +
        Translation_Fusion_B.rtb_TmpSignalConversionAtMult_p[Translation_Fusion_B.rtb_GPS_gain_tmp]
        * Translation_Fusion_P_g.Bc_Value[0])) *
      Translation_Fusion_B.DiscreteTimeIntegrator_am;
  }

  Translation_Fusion_Average_p(Translation_Fusion_B.Add_k_g[1],
    &Translation_Fusion_B.Average_pna, &Translation_Fusion_DW.Average_pna);
  Translation_Fusion_B.Compare_epn = (((int32_T)*rtu_hover_flag > (int32_T)
    Translation_Fusion_DW.DelayInput1_DSTATE_bh) ||
    Translation_Fusion_DW.Delay1_DSTATE_l);
  if (Translation_Fusion_B.Compare_epn &&
      (Translation_Fusion_PrevZCX.Delay_Reset_ZCE != POS_ZCSIG)) {
    Translation_Fusion_DW.icLoad_ki = 1U;
  }

  Translation_Fusion_PrevZCX.Delay_Reset_ZCE = Translation_Fusion_B.Compare_epn;
  if (Translation_Fusion_DW.icLoad_ki != 0) {
    Translation_Fusion_DW.Delay_DSTATE = Translation_Fusion_B.Add_k_g[0] -
      *rtu_Sensor_Vision_data_delta__m;
  }

  Translation_Fusion_B.DiscreteTimeIntegrator_am =
    Translation_Fusion_DW.Delay_DSTATE;
  Translation_Fusion_B.Relay1_a =
    Translation_Fusion_P_g.ust_orderdelaycompensator1_N *
    Translation_Fusion_B.Average_pna.Average *
    Translation_Fusion_B.DiscreteTimeIntegrator_ax +
    (*rtu_Sensor_Vision_data_delta__m + Translation_Fusion_DW.Delay_DSTATE);
  Translation_Fusion_B.DiscreteTimeIntegrator_ax =
    Translation_Fusion_P_g.SampleTime_WtEt_g;
  Translation_Fusion_Average_p(Translation_Fusion_B.Subtract,
    &Translation_Fusion_B.Average_pn, &Translation_Fusion_DW.Average_pn);
  Translation_Fusion_B.Relay1 =
    Translation_Fusion_P_g.ust_orderdelaycompensator_N_i *
    Translation_Fusion_B.Average_pn.Average *
    Translation_Fusion_B.DiscreteTimeIntegrator_ax + (real32_T)*rtu_Armed *
    *rtu_Sensor_Vision_data_vel_z_O_ * Translation_Fusion_P_g.Gain1_Gain_c;
  if (rtb_Reset_TF_tmp) {
    Translation_Fusion_DW.icLoad_h = 1U;
  }

  if (Translation_Fusion_DW.icLoad_h != 0) {
    for (Translation_Fusion_B.i = 0; Translation_Fusion_B.i < 9;
         Translation_Fusion_B.i++) {
      Translation_Fusion_DW.Delay_DSTATE_j[Translation_Fusion_B.i] =
        Translation_Fusion_P_g.Initialization_p0[Translation_Fusion_B.i];
    }
  }

  for (Translation_Fusion_B.rtb_GPS_gain_tmp = 0;
       Translation_Fusion_B.rtb_GPS_gain_tmp < 3;
       Translation_Fusion_B.rtb_GPS_gain_tmp++) {
    Translation_Fusion_B.Subtract_ia[3 * Translation_Fusion_B.rtb_GPS_gain_tmp] =
      Translation_Fusion_B.MatrixMultiply4_n[Translation_Fusion_B.rtb_GPS_gain_tmp];
    Translation_Fusion_B.Subtract_ia[1 + 3 *
      Translation_Fusion_B.rtb_GPS_gain_tmp] =
      Translation_Fusion_B.MatrixMultiply4_n[Translation_Fusion_B.rtb_GPS_gain_tmp
      + 3];
    Translation_Fusion_B.Subtract_ia[2 + 3 *
      Translation_Fusion_B.rtb_GPS_gain_tmp] =
      Translation_Fusion_B.MatrixMultiply4_n[Translation_Fusion_B.rtb_GPS_gain_tmp
      + 6];
  }

  for (Translation_Fusion_B.i = 0; Translation_Fusion_B.i < 3;
       Translation_Fusion_B.i++) {
    for (Translation_Fusion_B.rtb_GPS_gain_tmp = 0;
         Translation_Fusion_B.rtb_GPS_gain_tmp < 3;
         Translation_Fusion_B.rtb_GPS_gain_tmp++) {
      Translation_Fusion_B.v1_tmp = Translation_Fusion_B.i + 3 *
        Translation_Fusion_B.rtb_GPS_gain_tmp;
      Translation_Fusion_B.v1_c[Translation_Fusion_B.v1_tmp] = 0.0F;
      Translation_Fusion_B.DataTypeConversion_ew = 3 *
        Translation_Fusion_B.rtb_GPS_gain_tmp + Translation_Fusion_B.i;
      Translation_Fusion_B.v1_c[Translation_Fusion_B.v1_tmp] =
        Translation_Fusion_B.v1_c[Translation_Fusion_B.DataTypeConversion_ew] +
        Translation_Fusion_B.Subtract_ia[3 *
        Translation_Fusion_B.rtb_GPS_gain_tmp] *
        Translation_Fusion_DW.Delay_DSTATE_j[Translation_Fusion_B.i];
      Translation_Fusion_B.v1_c[Translation_Fusion_B.v1_tmp] =
        Translation_Fusion_B.Subtract_ia[3 *
        Translation_Fusion_B.rtb_GPS_gain_tmp + 1] *
        Translation_Fusion_DW.Delay_DSTATE_j[Translation_Fusion_B.i + 3] +
        Translation_Fusion_B.v1_c[Translation_Fusion_B.DataTypeConversion_ew];
      Translation_Fusion_B.v1_c[Translation_Fusion_B.v1_tmp] =
        Translation_Fusion_B.Subtract_ia[3 *
        Translation_Fusion_B.rtb_GPS_gain_tmp + 2] *
        Translation_Fusion_DW.Delay_DSTATE_j[Translation_Fusion_B.i + 6] +
        Translation_Fusion_B.v1_c[Translation_Fusion_B.DataTypeConversion_ew];
    }

    Translation_Fusion_B.DiscreteTimeIntegrator1_ek[Translation_Fusion_B.i] =
      Translation_Fusion_DW.Delay_DSTATE_j[Translation_Fusion_B.i << 2];
  }

  Translation_Fusion_B.MatrixMultiply4_a[0] =
    Translation_Fusion_P_g.Gain_Gain_gc *
    Translation_Fusion_B.DiscreteTimeIntegrator1_ek[1];
  Translation_Fusion_B.MatrixMultiply4_a[1] =
    Translation_Fusion_P_g.Gain_Gain_gc *
    Translation_Fusion_B.DiscreteTimeIntegrator1_ek[2];
  Translation_Fusion_B.DiscreteTimeIntegrator_ax =
    Translation_Fusion_P_g.Gain_Gain_ht * *rtu_Sensor_Vision_data_Vision_q;
  Translation_Fusion_B.Compare_epn =
    (Translation_Fusion_B.DiscreteTimeIntegrator_ax <=
     Translation_Fusion_P_g.CompareToConstant_const_f);
  if (!Translation_Fusion_B.Compare_epn) {
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE_k =
      Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_e;
  }

  if (*rtu_IMU_switch) {
    Translation_Fusion_B.DiscreteTimeIntegrator1_ek[0] =
      Translation_Fusion_P_g.Qc2_Value[0];
    Translation_Fusion_B.DiscreteTimeIntegrator1_ek[1] =
      Translation_Fusion_P_g.Qc2_Value[1];
    Translation_Fusion_B.DiscreteTimeIntegrator1_ek[2] =
      Translation_Fusion_P_g.Qc2_Value[2];
  } else if (Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE_k >
             Translation_Fusion_P_g.CompareToConstant5_const) {
    Translation_Fusion_B.DiscreteTimeIntegrator1_ek[0] =
      Translation_Fusion_P_g.Qc_Value[0];
    Translation_Fusion_B.DiscreteTimeIntegrator1_ek[1] =
      Translation_Fusion_P_g.Qc_Value[1];
    Translation_Fusion_B.DiscreteTimeIntegrator1_ek[2] =
      Translation_Fusion_P_g.Qc_Value[2];
  } else {
    Translation_Fusion_B.DiscreteTimeIntegrator1_ek[0] =
      Translation_Fusion_P_g.Qc1_Value[0];
    Translation_Fusion_B.DiscreteTimeIntegrator1_ek[1] =
      Translation_Fusion_P_g.Qc1_Value[1];
    Translation_Fusion_B.DiscreteTimeIntegrator1_ek[2] =
      Translation_Fusion_P_g.Qc1_Value[2];
  }

  Translation_Fusion_B.MatrixMultiply4_a[2] = Translation_Fusion_P_g.zero_Value;
  mw_arm_add_f32(Translation_Fusion_B.MatrixMultiply4_a,
                 Translation_Fusion_B.DiscreteTimeIntegrator1_ek,
                 &Translation_Fusion_B.Delay1_f[0], 3U);
  for (Translation_Fusion_B.i = 0; Translation_Fusion_B.i < 9;
       Translation_Fusion_B.i++) {
    Translation_Fusion_B.Subtract_ia[Translation_Fusion_B.i] = 0.0F;
  }

  Translation_Fusion_B.Subtract_ia[0] = Translation_Fusion_B.Delay1_f[0];
  Translation_Fusion_B.Subtract_ia[4] = Translation_Fusion_B.Delay1_f[1];
  Translation_Fusion_B.Subtract_ia[8] = Translation_Fusion_B.Delay1_f[2];
  for (Translation_Fusion_B.rtb_GPS_gain_tmp = 0;
       Translation_Fusion_B.rtb_GPS_gain_tmp < 3;
       Translation_Fusion_B.rtb_GPS_gain_tmp++) {
    for (Translation_Fusion_B.i = 0; Translation_Fusion_B.i < 3;
         Translation_Fusion_B.i++) {
      Translation_Fusion_B.Product_i[Translation_Fusion_B.i + 3 *
        Translation_Fusion_B.rtb_GPS_gain_tmp] = ((Translation_Fusion_B.v1_c[3 *
        Translation_Fusion_B.rtb_GPS_gain_tmp + 1] *
        Translation_Fusion_B.MatrixMultiply4_n[Translation_Fusion_B.i + 3] +
        Translation_Fusion_B.v1_c[3 * Translation_Fusion_B.rtb_GPS_gain_tmp] *
        Translation_Fusion_B.MatrixMultiply4_n[Translation_Fusion_B.i]) +
        Translation_Fusion_B.v1_c[3 * Translation_Fusion_B.rtb_GPS_gain_tmp + 2]
        * Translation_Fusion_B.MatrixMultiply4_n[Translation_Fusion_B.i + 6]) +
        Translation_Fusion_B.Subtract_ia[3 *
        Translation_Fusion_B.rtb_GPS_gain_tmp + Translation_Fusion_B.i] *
        Translation_Fusion_B.Relay;
    }
  }

  Translation_Fusion_B.Compare_jn = (*rtu_Sensor_GPS_data_Spd_quality >=
    Translation_Fusion_P_g.CompareToConstant5_const_e);
  Translation_Fusion_B.LogicalOperator_mw = !Translation_Fusion_B.Compare_jn;
  if (Translation_Fusion_B.LogicalOperator_mw ||
      (Translation_Fusion_DW.DiscreteTimeIntegrator_PrevRe_h != 0)) {
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE_g =
      Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_c;
  }

  Translation_Fusion_B.Compare_l0 =
    (Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE_g >
     Translation_Fusion_P_g.CompareToConstant_const_g);
  Translation_Fusion_B.Compare_fx = (*rtu_Sensor_GPS_data_Spd_quality >=
    Translation_Fusion_P_g.CompareToConstant4_const);
  Translation_Fusion_B.LogicalOperator_ok = !Translation_Fusion_B.Compare_fx;
  if (Translation_Fusion_B.LogicalOperator_ok ||
      (Translation_Fusion_DW.DiscreteTimeIntegrator_PrevRe_b != 0)) {
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_k0 =
      Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_a;
  }

  Translation_Fusion_B.Compare_h =
    (Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_k0 >
     Translation_Fusion_P_g.CompareToConstant_const_p);
  if (Translation_Fusion_B.Compare_l0) {
    Translation_Fusion_B.Switch4 = Translation_Fusion_P_g.Constant4_Value;
  } else if (Translation_Fusion_B.Compare_h) {
    Translation_Fusion_B.Switch4 = Translation_Fusion_P_g.Constant1_Value_g3;
  } else if (*rtu_Sensor_Vision_data_type ==
             Translation_Fusion_P_g.CompareToConstant_const_fa) {
    Translation_Fusion_B.Switch4 = Translation_Fusion_P_g.R_Value;
  } else {
    Translation_Fusion_B.Switch4 = Translation_Fusion_P_g.R1_Value_n;
  }

  if (Translation_Fusion_DW.DiscreteTimeIntegrator_IC_LOADI != 0) {
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE_o =
      Translation_Fusion_B.Switch4;
  }

  Translation_Fusion_B.Compare_bnu = (*rtu_Sensor_Vision_data_Vision_q >
    Translation_Fusion_P_g.CompareToConstant_const_j4);
  Translation_Fusion_B.LogicalOperator1_f = !Translation_Fusion_B.Compare_bnu;
  if (Translation_Fusion_B.LogicalOperator1_f ||
      (Translation_Fusion_DW.DiscreteTimeIntegrator_PrevR_hl != 0)) {
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE_p =
      Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_l;
  }

  if (Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE_p >=
      Translation_Fusion_P_g.DiscreteTimeIntegrator_UpperS_f) {
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE_p =
      Translation_Fusion_P_g.DiscreteTimeIntegrator_UpperS_f;
  } else {
    if (Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE_p <=
        Translation_Fusion_P_g.DiscreteTimeIntegrator_LowerS_k) {
      Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE_p =
        Translation_Fusion_P_g.DiscreteTimeIntegrator_LowerS_k;
    }
  }

  Translation_Fusion_B.Compare_gj = (Translation_Fusion_P_g.Gain_Gain_hz *
    Translation_Fusion_DW.DiscreteTimeIntegrator1_DSTATE <=
    Translation_Fusion_P_g.CompareToConstant_const_e);
  Translation_Fusion_B.LogicalOperator1_k = !Translation_Fusion_B.Compare_gj;
  if (Translation_Fusion_B.LogicalOperator1_k ||
      (Translation_Fusion_DW.DiscreteTimeIntegrator_PrevRe_g != 0)) {
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE_n =
      Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_p;
  }

  if (Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE_n >=
      Translation_Fusion_P_g.DiscreteTimeIntegrator_UpperS_o) {
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE_n =
      Translation_Fusion_P_g.DiscreteTimeIntegrator_UpperS_o;
  } else {
    if (Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE_n <=
        Translation_Fusion_P_g.DiscreteTimeIntegrator_LowerS_e) {
      Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE_n =
        Translation_Fusion_P_g.DiscreteTimeIntegrator_LowerS_e;
    }
  }

  Translation_Fusion_B.FixPtRelationalOperator_p =
    (*rtu_Sensor_GPS_data_Timestamp_m > Translation_Fusion_DW.DelayInput1_DSTATE);
  if (*rtu_Sensor_GPS_data_Spd_quality >= Translation_Fusion_P_g.u05065_OnVal) {
    Translation_Fusion_DW.u05065_Mode = true;
  } else {
    if (*rtu_Sensor_GPS_data_Spd_quality <= Translation_Fusion_P_g.u05065_OffVal)
    {
      Translation_Fusion_DW.u05065_Mode = false;
    }
  }

  if (Translation_Fusion_DW.u05065_Mode) {
    Translation_Fusion_B.Relay = Translation_Fusion_P_g.u05065_YOn;
  } else {
    Translation_Fusion_B.Relay = Translation_Fusion_P_g.u05065_YOff;
  }

  Translation_Fusion_B.GPS_gain = rtu_Sensor_RTK_Data_vel_quality[0];
  if ((!(rtu_Sensor_RTK_Data_vel_quality[0] < rtu_Sensor_RTK_Data_vel_quality[1]))
      && (!Translation_Fusion_B.rtb_LogicalOperator1_ls_idx_1)) {
    Translation_Fusion_B.GPS_gain = rtu_Sensor_RTK_Data_vel_quality[1];
  }

  Translation_Fusion_B.RTK_Vel_good = ((Translation_Fusion_B.GPS_gain >=
    Translation_Fusion_P_g.CompareToConstant10_const) &&
    Translation_Fusion_B.GPS_Good);
  if (*rtu_Sensor_GPS_data_Spd_quality >= Translation_Fusion_P_g.u0104_OnVal) {
    Translation_Fusion_DW.u0104_Mode = true;
  } else {
    if (*rtu_Sensor_GPS_data_Spd_quality <= Translation_Fusion_P_g.u0104_OffVal)
    {
      Translation_Fusion_DW.u0104_Mode = false;
    }
  }

  rtb_Over_15m_tmp = !*rtu_Sensor_Sonar_data_sonar_val;
  Translation_Fusion_B.Over_15m = (((*rtu_Sensor_Sonar_data_h_grd_son <
    Translation_Fusion_P_g.CompareToConstant1_const_l) || rtb_Over_15m_tmp) &&
    (Translation_Fusion_DW.Delay_DSTATE_k >
     Translation_Fusion_P_g.CompareToConstant3_const_o));
  if (Translation_Fusion_DW.DiscreteTimeIntegrator_IC_LOA_p != 0) {
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE_a =
      *rtu_Sensor_Vision_data_Vision_q;
  }

  Translation_Fusion_B.Vision_bad =
    ((Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE_a <=
      Translation_Fusion_P_g.CompareToConstant2_const_d) &&
     (*rtu_Sensor_Vision_data_Vision_v));
  Translation_Fusion_B.Vision_Unvalid = !*rtu_Sensor_Vision_data_Vision_v;
  if (*rtu_Sensor_GPS_data_Spd_quality >= Translation_Fusion_P_g.u0505_OnVal) {
    Translation_Fusion_DW.u0505_Mode = true;
  } else {
    if (*rtu_Sensor_GPS_data_Spd_quality <= Translation_Fusion_P_g.u0505_OffVal)
    {
      Translation_Fusion_DW.u0505_Mode = false;
    }
  }

  if (!Translation_Fusion_B.RTK_Vel_good) {
    if (Translation_Fusion_B.Over_15m || Translation_Fusion_B.Vision_bad ||
        Translation_Fusion_B.Vision_Unvalid) {
      if (Translation_Fusion_DW.u0104_Mode) {
        Translation_Fusion_B.Relay = Translation_Fusion_P_g.u0104_YOn;
      } else {
        Translation_Fusion_B.Relay = Translation_Fusion_P_g.u0104_YOff;
      }
    } else if (Translation_Fusion_DW.u0505_Mode) {
      Translation_Fusion_B.Relay = Translation_Fusion_P_g.u0505_YOn;
    } else {
      Translation_Fusion_B.Relay = Translation_Fusion_P_g.u0505_YOff;
    }
  }

  if ((Translation_Fusion_B.Relay != 0.0F) ||
      (Translation_Fusion_DW.DiscreteTimeIntegrator_PrevRe_n != 0)) {
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE_h =
      Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_g;
  }

  Translation_Fusion_B.DataTypeConversion1_p = ((real32_T)
    (Translation_Fusion_DW.Delay_DSTATE_p2 &&
     (!(Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE_h >=
        Translation_Fusion_P_g.CompareTo3sec_const))) +
    Translation_Fusion_B.Relay != 0.0F);
  mw_arm_sqrt_f32(Translation_Fusion_DW.Delay1_DSTATE_o[0] *
                  Translation_Fusion_DW.Delay1_DSTATE_o[0] +
                  Translation_Fusion_DW.Delay1_DSTATE_o[1] *
                  Translation_Fusion_DW.Delay1_DSTATE_o[1],
                  &Translation_Fusion_B.low_thr);
  if ((Translation_Fusion_B.Relay != 0.0F) ||
      (Translation_Fusion_DW.DiscreteTimeIntegrator_PrevR_bx != 0)) {
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_ax =
      Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_k;
  }

  Translation_Fusion_B.LogicalOperator_ob =
    (Translation_Fusion_DW.Delay_DSTATE_o5 &&
     (!(Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_ax >=
        Translation_Fusion_P_g.CompareTo2sec_const)));
  if ((Translation_Fusion_B.low_thr >
       Translation_Fusion_P_g.CompareToConstant_const_a) &&
      (Translation_Fusion_B.Over_15m && (Translation_Fusion_B.Vision_bad ||
        Translation_Fusion_B.Vision_Unvalid))) {
    Translation_Fusion_B.Switch1_ko = Translation_Fusion_B.DataTypeConversion1_p;
  } else {
    Translation_Fusion_B.Switch1_ko = ((real32_T)
      (Translation_Fusion_DW.Delay_DSTATE_o5 &&
       (!(Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_ax >=
          Translation_Fusion_P_g.CompareTo2sec_const))) +
      Translation_Fusion_B.Relay != 0.0F);
  }

  Translation_Fusion_B.Over_15m = ((*rtu_Sensor_GPS_data_Status >
    Translation_Fusion_P_g.CompareToConstant_const_f5) &&
    Translation_Fusion_B.FixPtRelationalOperator_p &&
    Translation_Fusion_B.Switch1_ko);
  Translation_Fusion_B.Vision_bad = !Translation_Fusion_B.Over_15m;
  Translation_Fusion_B.Vision_Unvalid = !Translation_Fusion_B.Vision_bad;
  if (Translation_Fusion_B.Vision_Unvalid ||
      (Translation_Fusion_DW.DiscreteTimeIntegrator_PrevRe_f != 0)) {
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE_f =
      Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_lj;
  }

  if (Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE_f >=
      Translation_Fusion_P_g.DiscreteTimeIntegrator_UpperS_d) {
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE_f =
      Translation_Fusion_P_g.DiscreteTimeIntegrator_UpperS_d;
  } else {
    if (Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE_f <=
        Translation_Fusion_P_g.DiscreteTimeIntegrator_LowerS_f) {
      Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE_f =
        Translation_Fusion_P_g.DiscreteTimeIntegrator_LowerS_f;
    }
  }

  Translation_Fusion_B.Compare_j =
    (Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE_f >
     Translation_Fusion_P_g.Validaperiod_T_p_j);
  Translation_Fusion_B.Compare_k = (*rtu_Sensor_GPS_data_Spd_quality <
    Translation_Fusion_P_g.CompareToConstant2_const_l);
  if (Translation_Fusion_B.Compare_k ||
      (Translation_Fusion_DW.DiscreteTimeIntegrator_PrevR_n3 != 0)) {
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_nz =
      Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_o;
  }

  Translation_Fusion_B.DataTypeConversion1_b = ((int32_T)((uint32_T)
    (Translation_Fusion_DW.Delay_DSTATE_d &&
     (!(Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_nz >=
        Translation_Fusion_P_g.CompareTo1sec_const))) +
    Translation_Fusion_B.Compare_k) != 0);
  if ((*rtu_Sensor_Sonar_data_sonar_val) ||
      (Translation_Fusion_DW.DiscreteTimeIntegrator_PrevRe_c != 0)) {
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_a3 =
      Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_d;
  }

  Translation_Fusion_B.LogicalOperator_i =
    (Translation_Fusion_DW.Delay_DSTATE_db &&
     (!(Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_a3 >=
        Translation_Fusion_P_g.CompareTo1sec_const_p)));
  Translation_Fusion_B.LogicalOperator2_g = (Translation_Fusion_B.Compare_j ||
    (Translation_Fusion_B.DataTypeConversion1_b &&
     (*rtu_Sensor_Vision_data_Vision_q >
      Translation_Fusion_P_g.CompareToConstant3_const_i)) || ((int32_T)
    ((uint32_T)(Translation_Fusion_DW.Delay_DSTATE_db &&
                (!(Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_a3 >=
                   Translation_Fusion_P_g.CompareTo1sec_const_p))) +
     *rtu_Sensor_Sonar_data_sonar_val) != 0) || ((real32_T)fabs
    (Translation_Fusion_DW.Delay_DSTATE_c) <=
    Translation_Fusion_P_g.CompareToConstant_const_k));
  Translation_Fusion_B.Compare_b5 = (Translation_Fusion_P_g.Gain_Gain_fc *
    Translation_Fusion_DW.DiscreteTimeIntegrator1_DSTAT_k >=
    Translation_Fusion_P_g.CompareToConstant_const_pn);
  if (Translation_Fusion_B.Compare_b5 ||
      (Translation_Fusion_DW.DiscreteTimeIntegrator_PrevRe_m != 0)) {
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_pp =
      Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_n;
  }

  Translation_Fusion_B.DataTypeConversion1_pq = ((int32_T)((uint32_T)
    (Translation_Fusion_DW.Delay_DSTATE_h &&
     (!(Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_pp >=
        Translation_Fusion_P_g.CompareTo1sec_const_c))) +
    Translation_Fusion_B.Compare_b5) != 0);
  Translation_Fusion_B.Compare_if = (Translation_Fusion_P_g.Gain1_Gain_n1 *
    Translation_Fusion_DW.DiscreteTimeIntegrator1_DSTAT_a >=
    Translation_Fusion_P_g.CompareToConstant1_const_g);
  if (Translation_Fusion_B.Compare_if ||
      (Translation_Fusion_DW.DiscreteTimeIntegrator_PrevR_bd != 0)) {
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_o4 =
      Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_i;
  }

  Translation_Fusion_B.DataTypeConversion1_m = ((int32_T)((uint32_T)
    (Translation_Fusion_DW.Delay_DSTATE_ch &&
     (!(Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_o4 >=
        Translation_Fusion_P_g.CompareTo1sec_const_g))) +
    Translation_Fusion_B.Compare_if) != 0);
  rtb_LogicalOperator1_n_tmp = !*rtu_hover_flag;
  if (rtb_LogicalOperator1_n_tmp ||
      (Translation_Fusion_DW.DiscreteTimeIntegrator_PrevR_mc != 0)) {
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE_e =
      Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_cm;
  }

  if (Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE_e >=
      Translation_Fusion_P_g.DiscreteTimeIntegrator_UpperS_l) {
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE_e =
      Translation_Fusion_P_g.DiscreteTimeIntegrator_UpperS_l;
  } else {
    if (Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE_e <=
        Translation_Fusion_P_g.DiscreteTimeIntegrator_LowerS_g) {
      Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE_e =
        Translation_Fusion_P_g.DiscreteTimeIntegrator_LowerS_g;
    }
  }

  if (*rtu_Sensor_Vision_data_type ==
      Translation_Fusion_P_g.CompareToConstant5_const_h) {
    mw_arm_sqrt_f32(rtu_Sensor_Vision_data_vel_xy_O[0] *
                    rtu_Sensor_Vision_data_vel_xy_O[0] +
                    rtu_Sensor_Vision_data_vel_xy_O[1] *
                    rtu_Sensor_Vision_data_vel_xy_O[1],
                    &Translation_Fusion_B.low_thr);
    if (*rtu_Sensor_GPS_data_Status >
        Translation_Fusion_P_g.CompareToConstant1_const_b) {
      Translation_Fusion_B.En_VO_Correct = (((real32_T)fabs
        (*rtu_Sensor_Vision_data_vel_z_O_) <
        Translation_Fusion_P_g.CompareToConstant2_const) &&
        (Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE_n >
         Translation_Fusion_P_g.Validaperiod_T_p_p));
    } else {
      Translation_Fusion_B.En_VO_Correct =
        Translation_Fusion_P_g.Constant_Value_er;
    }

    Translation_Fusion_B.En_VO_Correct =
      ((Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE_p >
        Translation_Fusion_P_g.Validaperiod_T_p) &&
       (*rtu_Sensor_Vision_data_timestam >
        Translation_Fusion_DW.DelayInput1_DSTATE_k2) &&
       (Translation_Fusion_B.low_thr <
        Translation_Fusion_P_g.CompareToConstant3_const) &&
       Translation_Fusion_B.En_VO_Correct &&
       Translation_Fusion_B.LogicalOperator2_g);
  } else {
    Translation_Fusion_B.En_VO_Correct =
      ((Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE_p >
        Translation_Fusion_P_g.Validaperiod_T_p) &&
       (*rtu_Sensor_Vision_data_timestam >
        Translation_Fusion_DW.DelayInput1_DSTATE_k2) &&
       Translation_Fusion_B.LogicalOperator2_g &&
       (Translation_Fusion_B.DataTypeConversion1_pq ||
        Translation_Fusion_B.DataTypeConversion1_m ||
        (Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE_e >
         Translation_Fusion_P_g.Validaperiod1_T_p)));
  }

  if (Translation_Fusion_B.En_VO_Correct) {
    Translation_Fusion_B.DiscreteTimeIntegrator1_f5h =
      Translation_Fusion_B.Relay1 - ((Translation_Fusion_P_g.C_Value[0] *
      Translation_Fusion_B.Add_k_g[0] + Translation_Fusion_P_g.C_Value[1] *
      Translation_Fusion_B.Add_k_g[1]) + Translation_Fusion_P_g.C_Value[2] *
      Translation_Fusion_B.Add_k_g[2]);
    Translation_Fusion_B.middle_thr =
      (Translation_Fusion_B.DiscreteTimeIntegrator1_f5h *
       Translation_Fusion_B.DiscreteTimeIntegrator1_f5h +
       Translation_Fusion_DW.Delay_DSTATE_j3) -
      Translation_Fusion_DW.Delay1_DSTATE_h *
      Translation_Fusion_DW.Delay1_DSTATE_h;
    Translation_Fusion_B.Inverse_j = 1.0F /
      Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE_o;
    if (Translation_Fusion_B.Inverse_j *
        Translation_Fusion_B.DiscreteTimeIntegrator1_f5h *
        Translation_Fusion_B.DiscreteTimeIntegrator1_f5h >
        Translation_Fusion_P_g.AdaptiveCorrection_kai_a) {
      Translation_Fusion_B.Sqrt = 0.0F;
      for (Translation_Fusion_B.rtb_GPS_gain_tmp = 0;
           Translation_Fusion_B.rtb_GPS_gain_tmp < 3;
           Translation_Fusion_B.rtb_GPS_gain_tmp++) {
        Translation_Fusion_B.Sqrt +=
          Translation_Fusion_P_g.C_Value[Translation_Fusion_B.rtb_GPS_gain_tmp] *
          (Translation_Fusion_B.Product_i[Translation_Fusion_B.rtb_GPS_gain_tmp
           + 6] * Translation_Fusion_P_g.C_Value[2] +
           (Translation_Fusion_B.Product_i[Translation_Fusion_B.rtb_GPS_gain_tmp
            + 3] * Translation_Fusion_P_g.C_Value[1] +
            Translation_Fusion_B.Product_i[Translation_Fusion_B.rtb_GPS_gain_tmp]
            * Translation_Fusion_P_g.C_Value[0]));
      }

      Translation_Fusion_B.Sum_ol = (Translation_Fusion_P_g.Gain_Gain_i *
        Translation_Fusion_B.middle_thr - Translation_Fusion_B.Sqrt) *
        Translation_Fusion_B.Inverse_j;
      if ((!(Translation_Fusion_B.Sum_ol >
             Translation_Fusion_P_g.Constant_Value_a)) && (!rtIsNaNF
           (Translation_Fusion_P_g.Constant_Value_a))) {
        Translation_Fusion_B.Sum_ol = Translation_Fusion_P_g.Constant_Value_a;
      }

      if ((!(Translation_Fusion_B.Sum_ol <
             Translation_Fusion_P_g.AdaptiveCorrection_max_eta_c)) && (!rtIsNaNF
           (Translation_Fusion_P_g.AdaptiveCorrection_max_eta_c))) {
        Translation_Fusion_B.Sum_ol =
          Translation_Fusion_P_g.AdaptiveCorrection_max_eta_c;
      }

      Translation_Fusion_B.GPS_gain = Translation_Fusion_B.Sum_ol *
        Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE_o;
    } else {
      Translation_Fusion_B.GPS_gain =
        Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE_o;
    }

    Translation_Fusion_B.Sqrt = 0.0F;
    for (Translation_Fusion_B.rtb_GPS_gain_tmp = 0;
         Translation_Fusion_B.rtb_GPS_gain_tmp < 3;
         Translation_Fusion_B.rtb_GPS_gain_tmp++) {
      Translation_Fusion_B.Sqrt +=
        Translation_Fusion_P_g.C_Value[Translation_Fusion_B.rtb_GPS_gain_tmp] *
        (Translation_Fusion_B.Product_i[Translation_Fusion_B.rtb_GPS_gain_tmp +
         6] * Translation_Fusion_P_g.C_Value[2] +
         (Translation_Fusion_B.Product_i[Translation_Fusion_B.rtb_GPS_gain_tmp +
          3] * Translation_Fusion_P_g.C_Value[1] +
          Translation_Fusion_B.Product_i[Translation_Fusion_B.rtb_GPS_gain_tmp] *
          Translation_Fusion_P_g.C_Value[0]));
    }

    Translation_Fusion_B.Sum_ol = 1.0F / (Translation_Fusion_B.Sqrt +
      Translation_Fusion_B.GPS_gain);
    for (Translation_Fusion_B.rtb_GPS_gain_tmp = 0;
         Translation_Fusion_B.rtb_GPS_gain_tmp < 3;
         Translation_Fusion_B.rtb_GPS_gain_tmp++) {
      Translation_Fusion_B.Relay1 =
        Translation_Fusion_B.Product_i[Translation_Fusion_B.rtb_GPS_gain_tmp + 6]
        * (Translation_Fusion_P_g.C_Value[2] * Translation_Fusion_B.Sum_ol) +
        (Translation_Fusion_B.Product_i[Translation_Fusion_B.rtb_GPS_gain_tmp +
         3] * (Translation_Fusion_P_g.C_Value[1] * Translation_Fusion_B.Sum_ol)
         + Translation_Fusion_P_g.C_Value[0] * Translation_Fusion_B.Sum_ol *
         Translation_Fusion_B.Product_i[Translation_Fusion_B.rtb_GPS_gain_tmp]);
      Translation_Fusion_B.Subtract_ia[Translation_Fusion_B.rtb_GPS_gain_tmp] =
        Translation_Fusion_B.IdentityMatrix_i[Translation_Fusion_B.rtb_GPS_gain_tmp]
        - Translation_Fusion_B.Relay1 * Translation_Fusion_P_g.C_Value[0];
      Translation_Fusion_B.Subtract_ia[Translation_Fusion_B.rtb_GPS_gain_tmp + 3]
        =
        Translation_Fusion_B.IdentityMatrix_i[Translation_Fusion_B.rtb_GPS_gain_tmp
        + 3] - Translation_Fusion_B.Relay1 * Translation_Fusion_P_g.C_Value[1];
      Translation_Fusion_B.Subtract_ia[Translation_Fusion_B.rtb_GPS_gain_tmp + 6]
        =
        Translation_Fusion_B.IdentityMatrix_i[Translation_Fusion_B.rtb_GPS_gain_tmp
        + 6] - Translation_Fusion_B.Relay1 * Translation_Fusion_P_g.C_Value[2];
      Translation_Fusion_B.TmpSignalConversionAtMultip[Translation_Fusion_B.rtb_GPS_gain_tmp]
        = Translation_Fusion_B.Relay1;
    }

    for (Translation_Fusion_B.rtb_GPS_gain_tmp = 0;
         Translation_Fusion_B.rtb_GPS_gain_tmp < 3;
         Translation_Fusion_B.rtb_GPS_gain_tmp++) {
      for (Translation_Fusion_B.i = 0; Translation_Fusion_B.i < 3;
           Translation_Fusion_B.i++) {
        Translation_Fusion_B.DataTypeConversion_ew =
          Translation_Fusion_B.rtb_GPS_gain_tmp + 3 * Translation_Fusion_B.i;
        Translation_Fusion_B.rtb_Product_i_b[Translation_Fusion_B.DataTypeConversion_ew]
          = 0.0F;
        Translation_Fusion_B.DataTypeConversion_bx = 3 * Translation_Fusion_B.i
          + Translation_Fusion_B.rtb_GPS_gain_tmp;
        Translation_Fusion_B.rtb_Product_i_b[Translation_Fusion_B.DataTypeConversion_ew]
          =
          Translation_Fusion_B.rtb_Product_i_b[Translation_Fusion_B.DataTypeConversion_bx]
          + Translation_Fusion_B.Product_i[Translation_Fusion_B.rtb_GPS_gain_tmp]
          * Translation_Fusion_B.Subtract_ia[Translation_Fusion_B.i];
        Translation_Fusion_B.rtb_Product_i_b[Translation_Fusion_B.DataTypeConversion_ew]
          =
          Translation_Fusion_B.rtb_Product_i_b[Translation_Fusion_B.DataTypeConversion_bx]
          + Translation_Fusion_B.Product_i[Translation_Fusion_B.rtb_GPS_gain_tmp
          + 3] * Translation_Fusion_B.Subtract_ia[Translation_Fusion_B.i + 3];
        Translation_Fusion_B.rtb_Product_i_b[Translation_Fusion_B.DataTypeConversion_ew]
          =
          Translation_Fusion_B.rtb_Product_i_b[Translation_Fusion_B.DataTypeConversion_bx]
          + Translation_Fusion_B.Product_i[Translation_Fusion_B.rtb_GPS_gain_tmp
          + 6] * Translation_Fusion_B.Subtract_ia[Translation_Fusion_B.i + 6];
      }
    }

    for (Translation_Fusion_B.rtb_GPS_gain_tmp = 0;
         Translation_Fusion_B.rtb_GPS_gain_tmp < 3;
         Translation_Fusion_B.rtb_GPS_gain_tmp++) {
      for (Translation_Fusion_B.i = 0; Translation_Fusion_B.i < 3;
           Translation_Fusion_B.i++) {
        Translation_Fusion_B.v1_tmp = Translation_Fusion_B.rtb_GPS_gain_tmp + 3 *
          Translation_Fusion_B.i;
        Translation_Fusion_B.MatrixMultiply4_n[Translation_Fusion_B.v1_tmp] =
          0.0F;
        Translation_Fusion_B.DataTypeConversion_ew = 3 * Translation_Fusion_B.i
          + Translation_Fusion_B.rtb_GPS_gain_tmp;
        Translation_Fusion_B.MatrixMultiply4_n[Translation_Fusion_B.v1_tmp] =
          Translation_Fusion_B.MatrixMultiply4_n[Translation_Fusion_B.DataTypeConversion_ew]
          + Translation_Fusion_B.rtb_Product_i_b[3 * Translation_Fusion_B.i] *
          Translation_Fusion_B.Subtract_ia[Translation_Fusion_B.rtb_GPS_gain_tmp];
        Translation_Fusion_B.MatrixMultiply4_n[Translation_Fusion_B.v1_tmp] =
          Translation_Fusion_B.rtb_Product_i_b[3 * Translation_Fusion_B.i + 1] *
          Translation_Fusion_B.Subtract_ia[Translation_Fusion_B.rtb_GPS_gain_tmp
          + 3] +
          Translation_Fusion_B.MatrixMultiply4_n[Translation_Fusion_B.DataTypeConversion_ew];
        Translation_Fusion_B.MatrixMultiply4_n[Translation_Fusion_B.v1_tmp] =
          Translation_Fusion_B.rtb_Product_i_b[3 * Translation_Fusion_B.i + 2] *
          Translation_Fusion_B.Subtract_ia[Translation_Fusion_B.rtb_GPS_gain_tmp
          + 6] +
          Translation_Fusion_B.MatrixMultiply4_n[Translation_Fusion_B.DataTypeConversion_ew];
        Translation_Fusion_B.rtb_TmpSignalConversionAtMult_p[Translation_Fusion_B.v1_tmp]
          = Translation_Fusion_B.GPS_gain *
          Translation_Fusion_B.TmpSignalConversionAtMultip[Translation_Fusion_B.i]
          * Translation_Fusion_B.TmpSignalConversionAtMultip[Translation_Fusion_B.rtb_GPS_gain_tmp];
      }
    }

    for (Translation_Fusion_B.rtb_GPS_gain_tmp = 0;
         Translation_Fusion_B.rtb_GPS_gain_tmp < 9;
         Translation_Fusion_B.rtb_GPS_gain_tmp++) {
      Translation_Fusion_B.Add_p[Translation_Fusion_B.rtb_GPS_gain_tmp] =
        Translation_Fusion_B.MatrixMultiply4_n[Translation_Fusion_B.rtb_GPS_gain_tmp]
        + Translation_Fusion_B.rtb_TmpSignalConversionAtMult_p[Translation_Fusion_B.rtb_GPS_gain_tmp];
    }

    Translation_Fusion_B.Add_c[0] =
      Translation_Fusion_B.TmpSignalConversionAtMultip[0] *
      Translation_Fusion_B.DiscreteTimeIntegrator1_f5h +
      Translation_Fusion_B.Add_k_g[0];
    Translation_Fusion_B.Add_c[1] =
      Translation_Fusion_B.TmpSignalConversionAtMultip[1] *
      Translation_Fusion_B.DiscreteTimeIntegrator1_f5h +
      Translation_Fusion_B.Add_k_g[1];
    Translation_Fusion_B.Add_c[2] =
      Translation_Fusion_B.TmpSignalConversionAtMultip[2] *
      Translation_Fusion_B.DiscreteTimeIntegrator1_f5h +
      Translation_Fusion_B.Add_k_g[2];
    Translation_Fusion_DW.Delay_DSTATE_j3 = Translation_Fusion_B.middle_thr;
    Translation_Fusion_DW.Delay1_DSTATE_h =
      Translation_Fusion_B.DiscreteTimeIntegrator1_f5h;
    Translation_Fusion_B.Switch_d[0] = Translation_Fusion_B.Add_c[0];
    Translation_Fusion_B.Switch_d[1] = Translation_Fusion_B.Add_c[1];
    Translation_Fusion_B.Switch_d[2] = Translation_Fusion_B.Add_c[2];
  } else {
    Translation_Fusion_B.Switch_d[0] = Translation_Fusion_B.Add_k_g[0];
    Translation_Fusion_B.Switch_d[1] = Translation_Fusion_B.Add_k_g[1];
    Translation_Fusion_B.Switch_d[2] = Translation_Fusion_B.Add_k_g[2];
  }

  for (Translation_Fusion_B.rtb_GPS_gain_tmp = 0;
       Translation_Fusion_B.rtb_GPS_gain_tmp < 9;
       Translation_Fusion_B.rtb_GPS_gain_tmp++) {
    Translation_Fusion_B.GPS_gain =
      Translation_Fusion_B.Product_i[Translation_Fusion_B.rtb_GPS_gain_tmp];
    if (Translation_Fusion_B.En_VO_Correct) {
      Translation_Fusion_B.GPS_gain =
        Translation_Fusion_B.Add_p[Translation_Fusion_B.rtb_GPS_gain_tmp];
    }

    Translation_Fusion_B.Product_i[Translation_Fusion_B.rtb_GPS_gain_tmp] =
      Translation_Fusion_B.GPS_gain;
  }

  if (*rtu_Sensor_Vision_data_type ==
      Translation_Fusion_P_g.CompareToConstant1_const_f) {
    Translation_Fusion_B.GPS_gain = Translation_Fusion_P_g.R2_Value;
  } else {
    Translation_Fusion_B.GPS_gain = Translation_Fusion_P_g.R3_Value;
  }

  if (Translation_Fusion_DW.DiscreteTimeIntegrator_IC_LOA_a != 0) {
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_oe =
      *rtu_Rotation_Psi_dot_fused;
  }

  Translation_Fusion_B.Compare_o4 = ((real32_T)fabs
    (Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_oe) <=
    Translation_Fusion_P_g.CompareToConstant3_const_g);
  Translation_Fusion_B.FixPtRelationalOperator_k =
    !Translation_Fusion_B.Compare_o4;
  if (Translation_Fusion_B.FixPtRelationalOperator_k ||
      (Translation_Fusion_DW.DiscreteTimeIntegrator_PrevR_br != 0)) {
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_hu =
      Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_ce;
  }

  if (Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_hu >=
      Translation_Fusion_P_g.DiscreteTimeIntegrator_UpperS_e) {
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_hu =
      Translation_Fusion_P_g.DiscreteTimeIntegrator_UpperS_e;
  } else {
    if (Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_hu <=
        Translation_Fusion_P_g.DiscreteTimeIntegrator_Lower_ec) {
      Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_hu =
        Translation_Fusion_P_g.DiscreteTimeIntegrator_Lower_ec;
    }
  }

  Translation_Fusion_B.Switch_dy =
    (Translation_Fusion_B.DiscreteTimeIntegrator_ax >=
     Translation_Fusion_P_g.CompareToConstant2_const_lv);
  Translation_Fusion_B.LogicalOperator1_i = !Translation_Fusion_B.Switch_dy;
  if (Translation_Fusion_B.LogicalOperator1_i ||
      (Translation_Fusion_DW.DiscreteTimeIntegrator_PrevRe_i != 0)) {
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE_j =
      Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_f;
  }

  if (Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE_j >=
      Translation_Fusion_P_g.DiscreteTimeIntegrator_Upper_d0) {
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE_j =
      Translation_Fusion_P_g.DiscreteTimeIntegrator_Upper_d0;
  } else {
    if (Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE_j <=
        Translation_Fusion_P_g.DiscreteTimeIntegrator_LowerS_n) {
      Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE_j =
        Translation_Fusion_P_g.DiscreteTimeIntegrator_LowerS_n;
    }
  }

  if (rtb_LogicalOperator1_n_tmp ||
      (Translation_Fusion_DW.DiscreteTimeIntegrator_PrevRe_j != 0)) {
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_hc =
      Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_f3;
  }

  if (Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_hc >=
      Translation_Fusion_P_g.DiscreteTimeIntegrator_Upper_ex) {
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_hc =
      Translation_Fusion_P_g.DiscreteTimeIntegrator_Upper_ex;
  } else {
    if (Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_hc <=
        Translation_Fusion_P_g.DiscreteTimeIntegrator_LowerS_o) {
      Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_hc =
        Translation_Fusion_P_g.DiscreteTimeIntegrator_LowerS_o;
    }
  }

  Translation_Fusion_B.En_VO_Pz_Correct =
    ((Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_hu >
      Translation_Fusion_P_g.Validaperiod2_T_p) &&
     (Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE_j >
      Translation_Fusion_P_g.Validaperiod1_T_p_m) &&
     (Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_hc >
      Translation_Fusion_P_g.Validaperiod_T_p_i) &&
     Translation_Fusion_B.En_VO_Correct && ((real32_T)fabs
      (Translation_Fusion_B.Add_k_g[0] - Translation_Fusion_B.Relay1_a) <=
      Translation_Fusion_P_g.CompareToConstant_const_b));
  if (Translation_Fusion_B.En_VO_Pz_Correct) {
    Translation_Fusion_B.Relay1_a -= (Translation_Fusion_P_g.C1_Value[0] *
      Translation_Fusion_B.Switch_d[0] + Translation_Fusion_P_g.C1_Value[1] *
      Translation_Fusion_B.Switch_d[1]) + Translation_Fusion_P_g.C1_Value[2] *
      Translation_Fusion_B.Switch_d[2];
    Translation_Fusion_B.low_thr = (Translation_Fusion_B.Relay1_a *
      Translation_Fusion_B.Relay1_a + Translation_Fusion_DW.Delay_DSTATE_cc) -
      Translation_Fusion_DW.Delay1_DSTATE_k *
      Translation_Fusion_DW.Delay1_DSTATE_k;
    Translation_Fusion_B.Relay1 = 1.0F / Translation_Fusion_B.GPS_gain;
    if (Translation_Fusion_B.Relay1 * Translation_Fusion_B.Relay1_a *
        Translation_Fusion_B.Relay1_a >
        Translation_Fusion_P_g.AdaptiveCorrection1_kai) {
      Translation_Fusion_B.Sqrt = 0.0F;
      for (Translation_Fusion_B.rtb_GPS_gain_tmp = 0;
           Translation_Fusion_B.rtb_GPS_gain_tmp < 3;
           Translation_Fusion_B.rtb_GPS_gain_tmp++) {
        Translation_Fusion_B.Sqrt +=
          Translation_Fusion_P_g.C1_Value[Translation_Fusion_B.rtb_GPS_gain_tmp]
          * (Translation_Fusion_B.Product_i[Translation_Fusion_B.rtb_GPS_gain_tmp
             + 6] * Translation_Fusion_P_g.C1_Value[2] +
             (Translation_Fusion_B.Product_i[Translation_Fusion_B.rtb_GPS_gain_tmp
              + 3] * Translation_Fusion_P_g.C1_Value[1] +
              Translation_Fusion_B.Product_i[Translation_Fusion_B.rtb_GPS_gain_tmp]
              * Translation_Fusion_P_g.C1_Value[0]));
      }

      Translation_Fusion_B.Sum_ol = (Translation_Fusion_P_g.Gain_Gain_n0 *
        Translation_Fusion_B.low_thr - Translation_Fusion_B.Sqrt) *
        Translation_Fusion_B.Relay1;
      if ((!(Translation_Fusion_B.Sum_ol >
             Translation_Fusion_P_g.Constant_Value_k)) && (!rtIsNaNF
           (Translation_Fusion_P_g.Constant_Value_k))) {
        Translation_Fusion_B.Sum_ol = Translation_Fusion_P_g.Constant_Value_k;
      }

      if ((!(Translation_Fusion_B.Sum_ol <
             Translation_Fusion_P_g.AdaptiveCorrection1_max_eta)) && (!rtIsNaNF
           (Translation_Fusion_P_g.AdaptiveCorrection1_max_eta))) {
        Translation_Fusion_B.Sum_ol =
          Translation_Fusion_P_g.AdaptiveCorrection1_max_eta;
      }

      Translation_Fusion_B.GPS_gain *= Translation_Fusion_B.Sum_ol;
    }

    Translation_Fusion_B.Sqrt = 0.0F;
    for (Translation_Fusion_B.rtb_GPS_gain_tmp = 0;
         Translation_Fusion_B.rtb_GPS_gain_tmp < 3;
         Translation_Fusion_B.rtb_GPS_gain_tmp++) {
      Translation_Fusion_B.Sqrt +=
        Translation_Fusion_P_g.C1_Value[Translation_Fusion_B.rtb_GPS_gain_tmp] *
        (Translation_Fusion_B.Product_i[Translation_Fusion_B.rtb_GPS_gain_tmp +
         6] * Translation_Fusion_P_g.C1_Value[2] +
         (Translation_Fusion_B.Product_i[Translation_Fusion_B.rtb_GPS_gain_tmp +
          3] * Translation_Fusion_P_g.C1_Value[1] +
          Translation_Fusion_B.Product_i[Translation_Fusion_B.rtb_GPS_gain_tmp] *
          Translation_Fusion_P_g.C1_Value[0]));
    }

    Translation_Fusion_B.Sum_ol = 1.0F / (Translation_Fusion_B.Sqrt +
      Translation_Fusion_B.GPS_gain);
    for (Translation_Fusion_B.rtb_GPS_gain_tmp = 0;
         Translation_Fusion_B.rtb_GPS_gain_tmp < 3;
         Translation_Fusion_B.rtb_GPS_gain_tmp++) {
      Translation_Fusion_B.Relay1 =
        Translation_Fusion_B.Product_i[Translation_Fusion_B.rtb_GPS_gain_tmp + 6]
        * (Translation_Fusion_P_g.C1_Value[2] * Translation_Fusion_B.Sum_ol) +
        (Translation_Fusion_B.Product_i[Translation_Fusion_B.rtb_GPS_gain_tmp +
         3] * (Translation_Fusion_P_g.C1_Value[1] * Translation_Fusion_B.Sum_ol)
         + Translation_Fusion_P_g.C1_Value[0] * Translation_Fusion_B.Sum_ol *
         Translation_Fusion_B.Product_i[Translation_Fusion_B.rtb_GPS_gain_tmp]);
      Translation_Fusion_B.Subtract_ia[Translation_Fusion_B.rtb_GPS_gain_tmp] =
        Translation_Fusion_B.IdentityMatrix_e[Translation_Fusion_B.rtb_GPS_gain_tmp]
        - Translation_Fusion_B.Relay1 * Translation_Fusion_P_g.C1_Value[0];
      Translation_Fusion_B.Subtract_ia[Translation_Fusion_B.rtb_GPS_gain_tmp + 3]
        =
        Translation_Fusion_B.IdentityMatrix_e[Translation_Fusion_B.rtb_GPS_gain_tmp
        + 3] - Translation_Fusion_B.Relay1 * Translation_Fusion_P_g.C1_Value[1];
      Translation_Fusion_B.Subtract_ia[Translation_Fusion_B.rtb_GPS_gain_tmp + 6]
        =
        Translation_Fusion_B.IdentityMatrix_e[Translation_Fusion_B.rtb_GPS_gain_tmp
        + 6] - Translation_Fusion_B.Relay1 * Translation_Fusion_P_g.C1_Value[2];
      Translation_Fusion_B.TmpSignalConversionAtMultip[Translation_Fusion_B.rtb_GPS_gain_tmp]
        = Translation_Fusion_B.Relay1;
    }

    for (Translation_Fusion_B.rtb_GPS_gain_tmp = 0;
         Translation_Fusion_B.rtb_GPS_gain_tmp < 3;
         Translation_Fusion_B.rtb_GPS_gain_tmp++) {
      for (Translation_Fusion_B.i = 0; Translation_Fusion_B.i < 3;
           Translation_Fusion_B.i++) {
        Translation_Fusion_B.DataTypeConversion_ew =
          Translation_Fusion_B.rtb_GPS_gain_tmp + 3 * Translation_Fusion_B.i;
        Translation_Fusion_B.rtb_Product_i_b[Translation_Fusion_B.DataTypeConversion_ew]
          = 0.0F;
        Translation_Fusion_B.DataTypeConversion_bx = 3 * Translation_Fusion_B.i
          + Translation_Fusion_B.rtb_GPS_gain_tmp;
        Translation_Fusion_B.rtb_Product_i_b[Translation_Fusion_B.DataTypeConversion_ew]
          =
          Translation_Fusion_B.rtb_Product_i_b[Translation_Fusion_B.DataTypeConversion_bx]
          + Translation_Fusion_B.Product_i[Translation_Fusion_B.rtb_GPS_gain_tmp]
          * Translation_Fusion_B.Subtract_ia[Translation_Fusion_B.i];
        Translation_Fusion_B.rtb_Product_i_b[Translation_Fusion_B.DataTypeConversion_ew]
          =
          Translation_Fusion_B.rtb_Product_i_b[Translation_Fusion_B.DataTypeConversion_bx]
          + Translation_Fusion_B.Product_i[Translation_Fusion_B.rtb_GPS_gain_tmp
          + 3] * Translation_Fusion_B.Subtract_ia[Translation_Fusion_B.i + 3];
        Translation_Fusion_B.rtb_Product_i_b[Translation_Fusion_B.DataTypeConversion_ew]
          =
          Translation_Fusion_B.rtb_Product_i_b[Translation_Fusion_B.DataTypeConversion_bx]
          + Translation_Fusion_B.Product_i[Translation_Fusion_B.rtb_GPS_gain_tmp
          + 6] * Translation_Fusion_B.Subtract_ia[Translation_Fusion_B.i + 6];
      }
    }

    for (Translation_Fusion_B.rtb_GPS_gain_tmp = 0;
         Translation_Fusion_B.rtb_GPS_gain_tmp < 3;
         Translation_Fusion_B.rtb_GPS_gain_tmp++) {
      for (Translation_Fusion_B.i = 0; Translation_Fusion_B.i < 3;
           Translation_Fusion_B.i++) {
        Translation_Fusion_B.v1_tmp = Translation_Fusion_B.rtb_GPS_gain_tmp + 3 *
          Translation_Fusion_B.i;
        Translation_Fusion_B.MatrixMultiply4_n[Translation_Fusion_B.v1_tmp] =
          0.0F;
        Translation_Fusion_B.DataTypeConversion_ew = 3 * Translation_Fusion_B.i
          + Translation_Fusion_B.rtb_GPS_gain_tmp;
        Translation_Fusion_B.MatrixMultiply4_n[Translation_Fusion_B.v1_tmp] =
          Translation_Fusion_B.MatrixMultiply4_n[Translation_Fusion_B.DataTypeConversion_ew]
          + Translation_Fusion_B.rtb_Product_i_b[3 * Translation_Fusion_B.i] *
          Translation_Fusion_B.Subtract_ia[Translation_Fusion_B.rtb_GPS_gain_tmp];
        Translation_Fusion_B.MatrixMultiply4_n[Translation_Fusion_B.v1_tmp] =
          Translation_Fusion_B.rtb_Product_i_b[3 * Translation_Fusion_B.i + 1] *
          Translation_Fusion_B.Subtract_ia[Translation_Fusion_B.rtb_GPS_gain_tmp
          + 3] +
          Translation_Fusion_B.MatrixMultiply4_n[Translation_Fusion_B.DataTypeConversion_ew];
        Translation_Fusion_B.MatrixMultiply4_n[Translation_Fusion_B.v1_tmp] =
          Translation_Fusion_B.rtb_Product_i_b[3 * Translation_Fusion_B.i + 2] *
          Translation_Fusion_B.Subtract_ia[Translation_Fusion_B.rtb_GPS_gain_tmp
          + 6] +
          Translation_Fusion_B.MatrixMultiply4_n[Translation_Fusion_B.DataTypeConversion_ew];
        Translation_Fusion_B.rtb_TmpSignalConversionAtMult_p[Translation_Fusion_B.v1_tmp]
          = Translation_Fusion_B.GPS_gain *
          Translation_Fusion_B.TmpSignalConversionAtMultip[Translation_Fusion_B.i]
          * Translation_Fusion_B.TmpSignalConversionAtMultip[Translation_Fusion_B.rtb_GPS_gain_tmp];
      }
    }

    for (Translation_Fusion_B.rtb_GPS_gain_tmp = 0;
         Translation_Fusion_B.rtb_GPS_gain_tmp < 9;
         Translation_Fusion_B.rtb_GPS_gain_tmp++) {
      Translation_Fusion_B.Add_m[Translation_Fusion_B.rtb_GPS_gain_tmp] =
        Translation_Fusion_B.MatrixMultiply4_n[Translation_Fusion_B.rtb_GPS_gain_tmp]
        + Translation_Fusion_B.rtb_TmpSignalConversionAtMult_p[Translation_Fusion_B.rtb_GPS_gain_tmp];
    }

    Translation_Fusion_B.Add_k[0] =
      Translation_Fusion_B.TmpSignalConversionAtMultip[0] *
      Translation_Fusion_B.Relay1_a + Translation_Fusion_B.Switch_d[0];
    Translation_Fusion_B.Add_k[1] =
      Translation_Fusion_B.TmpSignalConversionAtMultip[1] *
      Translation_Fusion_B.Relay1_a + Translation_Fusion_B.Switch_d[1];
    Translation_Fusion_B.Add_k[2] =
      Translation_Fusion_B.TmpSignalConversionAtMultip[2] *
      Translation_Fusion_B.Relay1_a + Translation_Fusion_B.Switch_d[2];
    Translation_Fusion_DW.Delay_DSTATE_cc = Translation_Fusion_B.low_thr;
    Translation_Fusion_DW.Delay1_DSTATE_k = Translation_Fusion_B.Relay1_a;
    Translation_Fusion_B.Switch_d[0] = Translation_Fusion_B.Add_k[0];
    Translation_Fusion_B.Switch_d[1] = Translation_Fusion_B.Add_k[1];
  }

  Translation_Fusion_B.low_thr = Translation_Fusion_B.Switch_d[2];
  if (Translation_Fusion_B.En_VO_Pz_Correct) {
    Translation_Fusion_B.low_thr = Translation_Fusion_B.Add_k[2];
  }

  for (Translation_Fusion_B.rtb_GPS_gain_tmp = 0;
       Translation_Fusion_B.rtb_GPS_gain_tmp < 9;
       Translation_Fusion_B.rtb_GPS_gain_tmp++) {
    Translation_Fusion_B.GPS_gain =
      Translation_Fusion_B.Product_i[Translation_Fusion_B.rtb_GPS_gain_tmp];
    if (Translation_Fusion_B.En_VO_Pz_Correct) {
      Translation_Fusion_B.GPS_gain =
        Translation_Fusion_B.Add_m[Translation_Fusion_B.rtb_GPS_gain_tmp];
    }

    Translation_Fusion_B.Product_i[Translation_Fusion_B.rtb_GPS_gain_tmp] =
      Translation_Fusion_B.GPS_gain;
  }

  Translation_Fusion_B.DiscreteTimeIntegrator1_f5h =
    Translation_Fusion_P_g.Gain_Gain_kx * *rtu_Sensor_GPS_data_Spd_quality;
  Translation_Fusion_B.Relay1_a = (Translation_Fusion_P_g.Constant_Value_gk -
    Translation_Fusion_B.DiscreteTimeIntegrator1_f5h) *
    Translation_Fusion_P_g.Gain_Gain_gy;
  if (Translation_Fusion_B.Relay1_a >
      Translation_Fusion_P_g.Saturation_UpperSat_n) {
    Translation_Fusion_B.Relay1_a = Translation_Fusion_P_g.Saturation_UpperSat_n;
  } else {
    if (Translation_Fusion_B.Relay1_a <
        Translation_Fusion_P_g.Saturation_LowerSat_lz) {
      Translation_Fusion_B.Relay1_a =
        Translation_Fusion_P_g.Saturation_LowerSat_lz;
    }
  }

  Translation_Fusion_B.GPS_gain = Translation_Fusion_B.Relay1_a *
    Translation_Fusion_B.Relay1_a;
  Translation_Fusion_B.Compare_mr = (*rtu_Sensor_GPS_data_Status >
    Translation_Fusion_P_g.CompareToConstant_const_i);
  Translation_Fusion_B.LogicalOperator2_hv = (*rtu_Sensor_GPS_data_Timestamp_m >
    Translation_Fusion_DW.DelayInput1_DSTATE_a);
  if (*rtu_Sensor_GPS_data_Spd_quality >= Translation_Fusion_P_g.u0504_OnVal) {
    Translation_Fusion_DW.u0504_Mode = true;
  } else {
    if (*rtu_Sensor_GPS_data_Spd_quality <= Translation_Fusion_P_g.u0504_OffVal)
    {
      Translation_Fusion_DW.u0504_Mode = false;
    }
  }

  if (Translation_Fusion_DW.u0504_Mode) {
    Translation_Fusion_B.Sqrt = Translation_Fusion_P_g.u0504_YOn;
  } else {
    Translation_Fusion_B.Sqrt = Translation_Fusion_P_g.u0504_YOff;
  }

  Translation_Fusion_B.En_GPS_Correct_c = ((Translation_Fusion_P_g.Gain1_Gain_d *
    *rtu_Rotation_standstill != 0.0F) || (Translation_Fusion_B.Compare_mr &&
    Translation_Fusion_B.LogicalOperator2_hv && (Translation_Fusion_B.Sqrt !=
    0.0F)));
  if (Translation_Fusion_B.En_GPS_Correct_c) {
    Translation_Fusion_B.Inverse_j = (Translation_Fusion_P_g.C_Value_f[0] *
      Translation_Fusion_B.Switch_d[0] + Translation_Fusion_P_g.C_Value_f[1] *
      Translation_Fusion_B.Switch_d[1]) + Translation_Fusion_P_g.C_Value_f[2] *
      Translation_Fusion_B.low_thr;
    Translation_Fusion_B.Relay1_a = Translation_Fusion_B.Relay_e -
      Translation_Fusion_B.Inverse_j;
    Translation_Fusion_B.DiscreteTimeIntegrator_ax =
      (Translation_Fusion_B.Relay1_a * Translation_Fusion_B.Relay1_a +
       Translation_Fusion_DW.Delay_DSTATE_jl) -
      Translation_Fusion_DW.Delay1_DSTATE_ot *
      Translation_Fusion_DW.Delay1_DSTATE_ot;
    Translation_Fusion_B.middle_thr = 1.0F / Translation_Fusion_B.GPS_gain;
    if (Translation_Fusion_B.middle_thr * Translation_Fusion_B.Relay1_a *
        Translation_Fusion_B.Relay1_a >
        Translation_Fusion_P_g.AdaptiveCorrection_kai) {
      Translation_Fusion_B.Sqrt = 0.0F;
      for (Translation_Fusion_B.rtb_GPS_gain_tmp = 0;
           Translation_Fusion_B.rtb_GPS_gain_tmp < 3;
           Translation_Fusion_B.rtb_GPS_gain_tmp++) {
        Translation_Fusion_B.Sqrt +=
          Translation_Fusion_P_g.C_Value_f[Translation_Fusion_B.rtb_GPS_gain_tmp]
          * (Translation_Fusion_B.Product_i[Translation_Fusion_B.rtb_GPS_gain_tmp
             + 6] * Translation_Fusion_P_g.C_Value_f[2] +
             (Translation_Fusion_B.Product_i[Translation_Fusion_B.rtb_GPS_gain_tmp
              + 3] * Translation_Fusion_P_g.C_Value_f[1] +
              Translation_Fusion_B.Product_i[Translation_Fusion_B.rtb_GPS_gain_tmp]
              * Translation_Fusion_P_g.C_Value_f[0]));
      }

      Translation_Fusion_B.Sum_ol = (Translation_Fusion_P_g.Gain_Gain_n *
        Translation_Fusion_B.DiscreteTimeIntegrator_ax -
        Translation_Fusion_B.Sqrt) * Translation_Fusion_B.middle_thr;
      if ((!(Translation_Fusion_B.Sum_ol >
             Translation_Fusion_P_g.Constant_Value_n)) && (!rtIsNaNF
           (Translation_Fusion_P_g.Constant_Value_n))) {
        Translation_Fusion_B.Sum_ol = Translation_Fusion_P_g.Constant_Value_n;
      }

      if ((!(Translation_Fusion_B.Sum_ol <
             Translation_Fusion_P_g.AdaptiveCorrection_max_eta)) && (!rtIsNaNF
           (Translation_Fusion_P_g.AdaptiveCorrection_max_eta))) {
        Translation_Fusion_B.Sum_ol =
          Translation_Fusion_P_g.AdaptiveCorrection_max_eta;
      }

      Translation_Fusion_B.GPS_gain *= Translation_Fusion_B.Sum_ol;
    }

    Translation_Fusion_B.Sqrt = 0.0F;
    for (Translation_Fusion_B.rtb_GPS_gain_tmp = 0;
         Translation_Fusion_B.rtb_GPS_gain_tmp < 3;
         Translation_Fusion_B.rtb_GPS_gain_tmp++) {
      Translation_Fusion_B.Sqrt +=
        Translation_Fusion_P_g.C_Value_f[Translation_Fusion_B.rtb_GPS_gain_tmp] *
        (Translation_Fusion_B.Product_i[Translation_Fusion_B.rtb_GPS_gain_tmp +
         6] * Translation_Fusion_P_g.C_Value_f[2] +
         (Translation_Fusion_B.Product_i[Translation_Fusion_B.rtb_GPS_gain_tmp +
          3] * Translation_Fusion_P_g.C_Value_f[1] +
          Translation_Fusion_B.Product_i[Translation_Fusion_B.rtb_GPS_gain_tmp] *
          Translation_Fusion_P_g.C_Value_f[0]));
    }

    Translation_Fusion_B.Sum_ol = 1.0F / (Translation_Fusion_B.Sqrt +
      Translation_Fusion_B.GPS_gain);
    for (Translation_Fusion_B.rtb_GPS_gain_tmp = 0;
         Translation_Fusion_B.rtb_GPS_gain_tmp < 3;
         Translation_Fusion_B.rtb_GPS_gain_tmp++) {
      Translation_Fusion_B.Relay1 =
        Translation_Fusion_B.Product_i[Translation_Fusion_B.rtb_GPS_gain_tmp + 6]
        * (Translation_Fusion_P_g.C_Value_f[2] * Translation_Fusion_B.Sum_ol) +
        (Translation_Fusion_B.Product_i[Translation_Fusion_B.rtb_GPS_gain_tmp +
         3] * (Translation_Fusion_P_g.C_Value_f[1] * Translation_Fusion_B.Sum_ol)
         + Translation_Fusion_P_g.C_Value_f[0] * Translation_Fusion_B.Sum_ol *
         Translation_Fusion_B.Product_i[Translation_Fusion_B.rtb_GPS_gain_tmp]);
      Translation_Fusion_B.Subtract_ia[Translation_Fusion_B.rtb_GPS_gain_tmp] =
        Translation_Fusion_B.IdentityMatrix_j3[Translation_Fusion_B.rtb_GPS_gain_tmp]
        - Translation_Fusion_B.Relay1 * Translation_Fusion_P_g.C_Value_f[0];
      Translation_Fusion_B.Subtract_ia[Translation_Fusion_B.rtb_GPS_gain_tmp + 3]
        =
        Translation_Fusion_B.IdentityMatrix_j3[Translation_Fusion_B.rtb_GPS_gain_tmp
        + 3] - Translation_Fusion_B.Relay1 * Translation_Fusion_P_g.C_Value_f[1];
      Translation_Fusion_B.Subtract_ia[Translation_Fusion_B.rtb_GPS_gain_tmp + 6]
        =
        Translation_Fusion_B.IdentityMatrix_j3[Translation_Fusion_B.rtb_GPS_gain_tmp
        + 6] - Translation_Fusion_B.Relay1 * Translation_Fusion_P_g.C_Value_f[2];
      Translation_Fusion_B.TmpSignalConversionAtMultip[Translation_Fusion_B.rtb_GPS_gain_tmp]
        = Translation_Fusion_B.Relay1;
    }

    for (Translation_Fusion_B.rtb_GPS_gain_tmp = 0;
         Translation_Fusion_B.rtb_GPS_gain_tmp < 3;
         Translation_Fusion_B.rtb_GPS_gain_tmp++) {
      for (Translation_Fusion_B.i = 0; Translation_Fusion_B.i < 3;
           Translation_Fusion_B.i++) {
        Translation_Fusion_B.DataTypeConversion_ew =
          Translation_Fusion_B.rtb_GPS_gain_tmp + 3 * Translation_Fusion_B.i;
        Translation_Fusion_B.rtb_Product_i_b[Translation_Fusion_B.DataTypeConversion_ew]
          = 0.0F;
        Translation_Fusion_B.DataTypeConversion_bx = 3 * Translation_Fusion_B.i
          + Translation_Fusion_B.rtb_GPS_gain_tmp;
        Translation_Fusion_B.rtb_Product_i_b[Translation_Fusion_B.DataTypeConversion_ew]
          =
          Translation_Fusion_B.rtb_Product_i_b[Translation_Fusion_B.DataTypeConversion_bx]
          + Translation_Fusion_B.Product_i[Translation_Fusion_B.rtb_GPS_gain_tmp]
          * Translation_Fusion_B.Subtract_ia[Translation_Fusion_B.i];
        Translation_Fusion_B.rtb_Product_i_b[Translation_Fusion_B.DataTypeConversion_ew]
          =
          Translation_Fusion_B.rtb_Product_i_b[Translation_Fusion_B.DataTypeConversion_bx]
          + Translation_Fusion_B.Product_i[Translation_Fusion_B.rtb_GPS_gain_tmp
          + 3] * Translation_Fusion_B.Subtract_ia[Translation_Fusion_B.i + 3];
        Translation_Fusion_B.rtb_Product_i_b[Translation_Fusion_B.DataTypeConversion_ew]
          =
          Translation_Fusion_B.rtb_Product_i_b[Translation_Fusion_B.DataTypeConversion_bx]
          + Translation_Fusion_B.Product_i[Translation_Fusion_B.rtb_GPS_gain_tmp
          + 6] * Translation_Fusion_B.Subtract_ia[Translation_Fusion_B.i + 6];
      }
    }

    for (Translation_Fusion_B.rtb_GPS_gain_tmp = 0;
         Translation_Fusion_B.rtb_GPS_gain_tmp < 3;
         Translation_Fusion_B.rtb_GPS_gain_tmp++) {
      for (Translation_Fusion_B.i = 0; Translation_Fusion_B.i < 3;
           Translation_Fusion_B.i++) {
        Translation_Fusion_B.v1_tmp = Translation_Fusion_B.rtb_GPS_gain_tmp + 3 *
          Translation_Fusion_B.i;
        Translation_Fusion_B.MatrixMultiply4_n[Translation_Fusion_B.v1_tmp] =
          0.0F;
        Translation_Fusion_B.DataTypeConversion_ew = 3 * Translation_Fusion_B.i
          + Translation_Fusion_B.rtb_GPS_gain_tmp;
        Translation_Fusion_B.MatrixMultiply4_n[Translation_Fusion_B.v1_tmp] =
          Translation_Fusion_B.MatrixMultiply4_n[Translation_Fusion_B.DataTypeConversion_ew]
          + Translation_Fusion_B.rtb_Product_i_b[3 * Translation_Fusion_B.i] *
          Translation_Fusion_B.Subtract_ia[Translation_Fusion_B.rtb_GPS_gain_tmp];
        Translation_Fusion_B.MatrixMultiply4_n[Translation_Fusion_B.v1_tmp] =
          Translation_Fusion_B.rtb_Product_i_b[3 * Translation_Fusion_B.i + 1] *
          Translation_Fusion_B.Subtract_ia[Translation_Fusion_B.rtb_GPS_gain_tmp
          + 3] +
          Translation_Fusion_B.MatrixMultiply4_n[Translation_Fusion_B.DataTypeConversion_ew];
        Translation_Fusion_B.MatrixMultiply4_n[Translation_Fusion_B.v1_tmp] =
          Translation_Fusion_B.rtb_Product_i_b[3 * Translation_Fusion_B.i + 2] *
          Translation_Fusion_B.Subtract_ia[Translation_Fusion_B.rtb_GPS_gain_tmp
          + 6] +
          Translation_Fusion_B.MatrixMultiply4_n[Translation_Fusion_B.DataTypeConversion_ew];
        Translation_Fusion_B.rtb_TmpSignalConversionAtMult_p[Translation_Fusion_B.v1_tmp]
          = Translation_Fusion_B.GPS_gain *
          Translation_Fusion_B.TmpSignalConversionAtMultip[Translation_Fusion_B.i]
          * Translation_Fusion_B.TmpSignalConversionAtMultip[Translation_Fusion_B.rtb_GPS_gain_tmp];
      }
    }

    for (Translation_Fusion_B.rtb_GPS_gain_tmp = 0;
         Translation_Fusion_B.rtb_GPS_gain_tmp < 9;
         Translation_Fusion_B.rtb_GPS_gain_tmp++) {
      Translation_Fusion_B.Add_f[Translation_Fusion_B.rtb_GPS_gain_tmp] =
        Translation_Fusion_B.MatrixMultiply4_n[Translation_Fusion_B.rtb_GPS_gain_tmp]
        + Translation_Fusion_B.rtb_TmpSignalConversionAtMult_p[Translation_Fusion_B.rtb_GPS_gain_tmp];
    }

    Translation_Fusion_B.Sum_ol = Translation_Fusion_B.Relay_e -
      Translation_Fusion_B.Inverse_j;
    Translation_Fusion_B.Add_cg[0] =
      Translation_Fusion_B.TmpSignalConversionAtMultip[0] *
      Translation_Fusion_B.Sum_ol + Translation_Fusion_B.Switch_d[0];
    Translation_Fusion_B.Add_cg[1] =
      Translation_Fusion_B.TmpSignalConversionAtMultip[1] *
      Translation_Fusion_B.Sum_ol + Translation_Fusion_B.Switch_d[1];
    Translation_Fusion_B.Add_cg[2] =
      Translation_Fusion_B.TmpSignalConversionAtMultip[2] *
      Translation_Fusion_B.Sum_ol + Translation_Fusion_B.low_thr;
    Translation_Fusion_DW.Delay_DSTATE_jl =
      Translation_Fusion_B.DiscreteTimeIntegrator_ax;
    Translation_Fusion_DW.Delay1_DSTATE_ot = Translation_Fusion_B.Relay1_a;
    Translation_Fusion_B.Switch_d[0] = Translation_Fusion_B.Add_cg[0];
    Translation_Fusion_B.Switch_d[1] = Translation_Fusion_B.Add_cg[1];
    Translation_Fusion_B.low_thr = Translation_Fusion_B.Add_cg[2];
  }

  if (*rtu_Sensor_GPS_data_Spd_quality >= Translation_Fusion_P_g.u2065_OnVal) {
    Translation_Fusion_DW.u2065_Mode = true;
  } else {
    if (*rtu_Sensor_GPS_data_Spd_quality <= Translation_Fusion_P_g.u2065_OffVal)
    {
      Translation_Fusion_DW.u2065_Mode = false;
    }
  }

  if (Translation_Fusion_DW.u2065_Mode) {
    Translation_Fusion_B.Relay_e = Translation_Fusion_P_g.u2065_YOn;
  } else {
    Translation_Fusion_B.Relay_e = Translation_Fusion_P_g.u2065_YOff;
  }

  if ((Translation_Fusion_B.Relay_e != 0.0F) ||
      (Translation_Fusion_DW.DiscreteTimeIntegrator_PrevR_g2 != 0)) {
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE_c =
      Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_m;
  }

  Translation_Fusion_B.En_VO_Correct = ((real32_T)
    (Translation_Fusion_DW.Delay_DSTATE_jd &&
     (!(Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE_c >=
        Translation_Fusion_P_g.CompareTo2sec_const_e))) +
    Translation_Fusion_B.Relay_e != 0.0F);
  if (Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE_a >=
      Translation_Fusion_P_g.u35085_OnVal) {
    Translation_Fusion_DW.u35085_Mode = true;
  } else {
    if (Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE_a <=
        Translation_Fusion_P_g.u35085_OffVal) {
      Translation_Fusion_DW.u35085_Mode = false;
    }
  }

  if (Translation_Fusion_DW.u35085_Mode) {
    Translation_Fusion_B.Sqrt = Translation_Fusion_P_g.u35085_YOn;
  } else {
    Translation_Fusion_B.Sqrt = Translation_Fusion_P_g.u35085_YOff;
  }

  Translation_Fusion_B.LogicalOperator3_d5 =
    ((!Translation_Fusion_B.En_VO_Correct) && (Translation_Fusion_B.Sqrt != 0.0F)
     && (*rtu_Sensor_Vision_data_type ==
         Translation_Fusion_P_g.CompareToConstant4_const_b));
  Translation_Fusion_B.GPS_Vel_Vaild =
    (((!Translation_Fusion_B.LogicalOperator3_d5) || rtb_LogicalOperator1_n_tmp)
     && (*rtu_Sensor_RTK_Data_rtk_type >=
         Translation_Fusion_P_g.CompareToConstant_const_l5) &&
     (!(rtu_Sensor_RTK_Data_vel_quality[2] <
        Translation_Fusion_P_g.CompareToConstant3_const_is)));
  Translation_Fusion_B.En_Corr_Pz_RTK = (Translation_Fusion_B.GPS_Good &&
    Translation_Fusion_B.GPS_Vel_Vaild);
  if (rtu_Sensor_RTK_Data_vel_quality[2] >= Translation_Fusion_P_g.Relay_OnVal_g)
  {
    Translation_Fusion_DW.Relay_Mode_g = true;
  } else {
    if (rtu_Sensor_RTK_Data_vel_quality[2] <=
        Translation_Fusion_P_g.Relay_OffVal_i) {
      Translation_Fusion_DW.Relay_Mode_g = false;
    }
  }

  if (Translation_Fusion_DW.Relay_Mode_g) {
    Translation_Fusion_B.Sqrt = Translation_Fusion_P_g.Relay_YOn_k;
  } else {
    Translation_Fusion_B.Sqrt = Translation_Fusion_P_g.Relay_YOff_e;
  }

  Translation_Fusion_B.GPS_Vel_Vaild = (Translation_Fusion_B.GPS_Good &&
    (!Translation_Fusion_B.GPS_Vel_Vaild) && (Translation_Fusion_B.Sqrt != 0.0F));
  Translation_Fusion_B.P_RTK_update_flg = (Translation_Fusion_B.En_Corr_Pz_RTK ||
    Translation_Fusion_B.GPS_Vel_Vaild);
  if (Translation_Fusion_B.P_RTK_update_flg ||
      (Translation_Fusion_DW.DiscreteTimeIntegrator_PrevRe_p != 0)) {
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_ag =
      Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_f33;
  }

  Translation_Fusion_B.FixPtRelationalOperator_g =
    (*rtu_Sensor_RTK_Data_Timestamp_m !=
     Translation_Fusion_DW.DelayInput1_DSTATE_p);
  if (Translation_Fusion_B.LogicalOperator1_g &&
      (Translation_Fusion_PrevZCX.x_delay_Reset_ZCE != POS_ZCSIG)) {
    Translation_Fusion_DW.icLoad_g = 1U;
  }

  Translation_Fusion_PrevZCX.x_delay_Reset_ZCE =
    Translation_Fusion_B.LogicalOperator1_g;
  if (Translation_Fusion_DW.icLoad_g != 0) {
    for (Translation_Fusion_B.i = 0; Translation_Fusion_B.i < 40;
         Translation_Fusion_B.i++) {
      Translation_Fusion_DW.x_delay_DSTATE[Translation_Fusion_B.i] =
        Translation_Fusion_B.Switch_d[0];
    }
  }

  if (Translation_Fusion_B.LogicalOperator1_g &&
      (Translation_Fusion_PrevZCX.x_delay1_Reset_ZCE != POS_ZCSIG)) {
    Translation_Fusion_DW.icLoad_kg = 1U;
  }

  Translation_Fusion_PrevZCX.x_delay1_Reset_ZCE =
    Translation_Fusion_B.LogicalOperator1_g;
  if (Translation_Fusion_DW.icLoad_kg != 0) {
    for (Translation_Fusion_B.i = 0; Translation_Fusion_B.i < 140;
         Translation_Fusion_B.i++) {
      Translation_Fusion_DW.x_delay1_DSTATE[Translation_Fusion_B.i] =
        Translation_Fusion_B.Switch_d[1];
    }
  }

  for (Translation_Fusion_B.rtb_GPS_gain_tmp = 0;
       Translation_Fusion_B.rtb_GPS_gain_tmp < 9;
       Translation_Fusion_B.rtb_GPS_gain_tmp++) {
    Translation_Fusion_B.GPS_gain =
      Translation_Fusion_B.Product_i[Translation_Fusion_B.rtb_GPS_gain_tmp];
    if (Translation_Fusion_B.En_GPS_Correct_c) {
      Translation_Fusion_B.GPS_gain =
        Translation_Fusion_B.Add_f[Translation_Fusion_B.rtb_GPS_gain_tmp];
    }

    Translation_Fusion_B.Product_i[Translation_Fusion_B.rtb_GPS_gain_tmp] =
      Translation_Fusion_B.GPS_gain;
  }

  for (Translation_Fusion_B.rtb_GPS_gain_tmp = 0;
       Translation_Fusion_B.rtb_GPS_gain_tmp < 3;
       Translation_Fusion_B.rtb_GPS_gain_tmp++) {
    Translation_Fusion_B.TmpSignalConversionAtMultip[Translation_Fusion_B.rtb_GPS_gain_tmp]
      = rtu_Rotation_M_OB[Translation_Fusion_B.rtb_GPS_gain_tmp + 6] *
      Translation_Fusion_P_g.R_GRTK_B_Value[2] +
      (rtu_Rotation_M_OB[Translation_Fusion_B.rtb_GPS_gain_tmp + 3] *
       Translation_Fusion_P_g.R_GRTK_B_Value[1] +
       rtu_Rotation_M_OB[Translation_Fusion_B.rtb_GPS_gain_tmp] *
       Translation_Fusion_P_g.R_GRTK_B_Value[0]);
  }

  Translation_Fusion_B.rtb_Saturation_fo_tmp = (*rtu_Sensor_RTK_Data_height_m -
    Translation_Fusion_B.rtb_WGS84_pos_ref_idx_2) -
    Translation_Fusion_P_g.Gain1_Gain_f *
    Translation_Fusion_B.TmpSignalConversionAtMultip[2];
  Translation_Fusion_B.LogicalOperator1_g = (*rtu_Sensor_RTK_Data_Timestamp_m !=
    Translation_Fusion_DW.DelayInput1_DSTATE_j);
  if (Translation_Fusion_B.LogicalOperator1_g ||
      (Translation_Fusion_DW.DiscreteTimeIntegrator_PrevR_gd != 0)) {
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_gk =
      Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_gn;
  }

  Translation_Fusion_B.En_GPS_Correct_c = ((int32_T)((uint32_T)
    (Translation_Fusion_DW.Delay_DSTATE_d4 &&
     (!(Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_gk >=
        Translation_Fusion_P_g.CompareTo1sec_const_o))) +
    Translation_Fusion_B.LogicalOperator1_g) != 0);
  Translation_Fusion_B.DiscreteTimeIntegrator_ax =
    Translation_Fusion_DW.Memory1_PreviousInput - (real32_T)
    Translation_Fusion_B.rtb_Saturation_fo_tmp;
  Translation_Fusion_B.Relay1_a = (real32_T)fabs
    ((Translation_Fusion_B.DiscreteTimeIntegrator_ax -
      Translation_Fusion_P_g.Constant_Value_om * Translation_Fusion_B.Switch_d[1])
     * (real32_T)Translation_Fusion_B.En_GPS_Correct_c);
  Translation_Fusion_B.DiscreteTimeIntegrator_ax = (real32_T)fabs
    (Translation_Fusion_B.DiscreteTimeIntegrator_ax);
  Translation_Fusion_B.rtk_pos_valid_h = (((int32_T)
    Translation_Fusion_B.LogicalOperator_l > (int32_T)
    Translation_Fusion_DW.DelayInput1_DSTATE_n) ||
    (((Translation_Fusion_B.gps_pos_valid_m &&
       Translation_Fusion_B.rtk_pos_valid_j &&
       Translation_Fusion_B.rtk_pos_valid_h && ((real32_T)fabs
    (Translation_Fusion_DW.Memory_PreviousInput - *rtu_Sensor_RTK_Data_vel_D) >=
    Translation_Fusion_P_g.CompareToConstant2_const_j) && ((real32_T)fabs
    (*rtu_Sensor_GPS_data_vel_D - *rtu_Sensor_RTK_Data_vel_D) >=
    Translation_Fusion_P_g.CompareToConstant3_const_n)) ||
      (Translation_Fusion_B.Relay1_a >=
       Translation_Fusion_P_g.CompareToConstant1_const_i)) &&
     (Translation_Fusion_B.DiscreteTimeIntegrator_ax >=
      Translation_Fusion_P_g.CompareToConstant4_const_g) &&
     (Translation_Fusion_B.LogicalOperator_d &&
      Translation_Fusion_DW.Delay_DSTATE_jg &&
      Translation_Fusion_DW.Delay1_DSTATE_b0[0])));
  if (Translation_Fusion_B.rtk_pos_valid_h) {
    Translation_Fusion_B.Relay1_a = Translation_Fusion_B.Switch_d[0] - (real32_T)
      Translation_Fusion_B.rtb_Saturation_fo_tmp;
  } else if (Translation_Fusion_B.reset_ref) {
    Translation_Fusion_B.Relay1_a = Translation_Fusion_P_g.Constant_Value_gg;
  } else {
    Translation_Fusion_B.Relay1_a = Translation_Fusion_DW.Memory_PreviousInput_o;
  }

  if (Translation_Fusion_B.Relay1_a >
      Translation_Fusion_P_g.Saturation_UpperSat_g) {
    Translation_Fusion_B.Relay1_a = Translation_Fusion_P_g.Saturation_UpperSat_g;
  } else {
    if (Translation_Fusion_B.Relay1_a <
        Translation_Fusion_P_g.Saturation_LowerSat_o5) {
      Translation_Fusion_B.Relay1_a =
        Translation_Fusion_P_g.Saturation_LowerSat_o5;
    }
  }

  if (Translation_Fusion_DW.DiscreteTimeIntegrator_IC_LOA_b != 0) {
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_pn =
      Translation_Fusion_B.Relay1_a;
  }

  if (Translation_Fusion_B.rtk_pos_valid_h &&
      (Translation_Fusion_DW.DiscreteTimeIntegrator_PrevR_hj <= 0)) {
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_pn =
      Translation_Fusion_B.Relay1_a;
  }

  Translation_Fusion_B.DiscreteTimeIntegrator_ax = (real32_T)
    Translation_Fusion_B.rtb_Saturation_fo_tmp +
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_pn;
  if (Translation_Fusion_B.En_Corr_Pz_RTK) {
    if (Translation_Fusion_B.FixPtRelationalOperator_g) {
      Translation_Fusion_B.Sqrt = 0.0F;
      for (Translation_Fusion_B.rtb_GPS_gain_tmp = 0;
           Translation_Fusion_B.rtb_GPS_gain_tmp < 3;
           Translation_Fusion_B.rtb_GPS_gain_tmp++) {
        Translation_Fusion_B.Sqrt += (Translation_Fusion_B.Product_i[3 *
          Translation_Fusion_B.rtb_GPS_gain_tmp + 2] *
          Translation_Fusion_P_g.Constant_Value_fy[2] +
          (Translation_Fusion_B.Product_i[3 *
           Translation_Fusion_B.rtb_GPS_gain_tmp + 1] *
           Translation_Fusion_P_g.Constant_Value_fy[1] +
           Translation_Fusion_B.Product_i[3 *
           Translation_Fusion_B.rtb_GPS_gain_tmp] *
           Translation_Fusion_P_g.Constant_Value_fy[0])) *
          Translation_Fusion_P_g.Constant_Value_fy[Translation_Fusion_B.rtb_GPS_gain_tmp];
      }

      Translation_Fusion_B.Sum_ol = 1.0F / (Translation_Fusion_B.Sqrt +
        Translation_Fusion_P_g.Constant_Value_ne);
      Translation_Fusion_B.Delay1_f[0] = Translation_Fusion_DW.x_delay_DSTATE[0];
      Translation_Fusion_B.Delay1_f[1] = Translation_Fusion_DW.x_delay1_DSTATE[0];
      Translation_Fusion_B.Delay1_f[2] = Translation_Fusion_B.low_thr;
      Translation_Fusion_B.Sqrt = 0.0F;
      for (Translation_Fusion_B.rtb_GPS_gain_tmp = 0;
           Translation_Fusion_B.rtb_GPS_gain_tmp < 3;
           Translation_Fusion_B.rtb_GPS_gain_tmp++) {
        Translation_Fusion_B.Relay1 =
          (Translation_Fusion_B.Product_i[Translation_Fusion_B.rtb_GPS_gain_tmp
           + 6] * Translation_Fusion_P_g.Constant_Value_fy[2] +
           (Translation_Fusion_B.Product_i[Translation_Fusion_B.rtb_GPS_gain_tmp
            + 3] * Translation_Fusion_P_g.Constant_Value_fy[1] +
            Translation_Fusion_B.Product_i[Translation_Fusion_B.rtb_GPS_gain_tmp]
            * Translation_Fusion_P_g.Constant_Value_fy[0])) *
          Translation_Fusion_B.Sum_ol;
        Translation_Fusion_B.rtb_TmpSignalConversionAtMult_p[Translation_Fusion_B.rtb_GPS_gain_tmp]
          =
          Translation_Fusion_P_g.Constant_Value_g[Translation_Fusion_B.rtb_GPS_gain_tmp]
          - Translation_Fusion_B.Relay1 *
          Translation_Fusion_P_g.Constant_Value_fy[0];
        Translation_Fusion_B.rtb_TmpSignalConversionAtMult_p[Translation_Fusion_B.rtb_GPS_gain_tmp
          + 3] =
          Translation_Fusion_P_g.Constant_Value_g[Translation_Fusion_B.rtb_GPS_gain_tmp
          + 3] - Translation_Fusion_B.Relay1 *
          Translation_Fusion_P_g.Constant_Value_fy[1];
        Translation_Fusion_B.rtb_TmpSignalConversionAtMult_p[Translation_Fusion_B.rtb_GPS_gain_tmp
          + 6] =
          Translation_Fusion_P_g.Constant_Value_g[Translation_Fusion_B.rtb_GPS_gain_tmp
          + 6] - Translation_Fusion_B.Relay1 *
          Translation_Fusion_P_g.Constant_Value_fy[2];
        for (Translation_Fusion_B.i = 0; Translation_Fusion_B.i < 3;
             Translation_Fusion_B.i++) {
          Translation_Fusion_B.DataTypeConversion_ew =
            Translation_Fusion_B.rtb_GPS_gain_tmp + 3 * Translation_Fusion_B.i;
          Translation_Fusion_B.Multiply5[Translation_Fusion_B.DataTypeConversion_ew]
            = 0.0F;
          Translation_Fusion_B.DataTypeConversion_bx = 3 *
            Translation_Fusion_B.i + Translation_Fusion_B.rtb_GPS_gain_tmp;
          Translation_Fusion_B.Multiply5[Translation_Fusion_B.DataTypeConversion_ew]
            =
            Translation_Fusion_B.Multiply5[Translation_Fusion_B.DataTypeConversion_bx]
            + Translation_Fusion_B.Product_i[3 * Translation_Fusion_B.i] *
            Translation_Fusion_B.rtb_TmpSignalConversionAtMult_p[Translation_Fusion_B.rtb_GPS_gain_tmp];
          Translation_Fusion_B.Multiply5[Translation_Fusion_B.DataTypeConversion_ew]
            = Translation_Fusion_B.Product_i[3 * Translation_Fusion_B.i + 1] *
            Translation_Fusion_B.rtb_TmpSignalConversionAtMult_p[Translation_Fusion_B.rtb_GPS_gain_tmp
            + 3] +
            Translation_Fusion_B.Multiply5[Translation_Fusion_B.DataTypeConversion_bx];
          Translation_Fusion_B.Multiply5[Translation_Fusion_B.DataTypeConversion_ew]
            = Translation_Fusion_B.Product_i[3 * Translation_Fusion_B.i + 2] *
            Translation_Fusion_B.rtb_TmpSignalConversionAtMult_p[Translation_Fusion_B.rtb_GPS_gain_tmp
            + 6] +
            Translation_Fusion_B.Multiply5[Translation_Fusion_B.DataTypeConversion_bx];
        }

        Translation_Fusion_B.Sqrt +=
          Translation_Fusion_P_g.Constant_Value_fy[Translation_Fusion_B.rtb_GPS_gain_tmp]
          * Translation_Fusion_B.Delay1_f[Translation_Fusion_B.rtb_GPS_gain_tmp];
        Translation_Fusion_B.DiscreteTimeIntegrator1_ek[Translation_Fusion_B.rtb_GPS_gain_tmp]
          = Translation_Fusion_B.Relay1;
      }

      Translation_Fusion_B.Sum_ol =
        (Translation_Fusion_B.DiscreteTimeIntegrator_ax -
         Translation_Fusion_B.Sqrt) * Translation_Fusion_P_g.Gain_Gain_d;
      Translation_Fusion_B.Multiply[0] =
        Translation_Fusion_B.DiscreteTimeIntegrator1_ek[0] *
        Translation_Fusion_B.Sum_ol;
      Translation_Fusion_B.Multiply[1] =
        Translation_Fusion_B.DiscreteTimeIntegrator1_ek[1] *
        Translation_Fusion_B.Sum_ol;
      Translation_Fusion_B.Multiply[2] =
        Translation_Fusion_B.DiscreteTimeIntegrator1_ek[2] *
        Translation_Fusion_B.Sum_ol;
    }

    for (Translation_Fusion_B.i = 0; Translation_Fusion_B.i < 9;
         Translation_Fusion_B.i++) {
      Translation_Fusion_B.Merge1[Translation_Fusion_B.i] =
        Translation_Fusion_B.Multiply5[Translation_Fusion_B.i];
    }

    Translation_Fusion_B.X_Cor_RTK[0] = Translation_Fusion_B.Multiply[0];
    Translation_Fusion_B.X_Cor_RTK[1] = Translation_Fusion_B.Multiply[1];
    Translation_Fusion_B.X_Cor_RTK[2] = Translation_Fusion_B.Multiply[2];
  }

  Translation_Fusion_B.rtu_Sensor_RTK_Data_vel_N[0] = *rtu_Sensor_RTK_Data_vel_N;
  Translation_Fusion_B.rtu_Sensor_RTK_Data_vel_N[1] = *rtu_Sensor_RTK_Data_vel_E;
  Translation_Fusion_B.rtu_Sensor_RTK_Data_vel_N[2] = *rtu_Sensor_RTK_Data_vel_D;
  Translation_Fusion_B.DiscreteTimeIntegrator1_ek[0] =
    Translation_Fusion_DW.DiscreteTimeIntegrator1_DSTAT_h[0];
  Translation_Fusion_B.Relay1 =
    Translation_Fusion_DW.DiscreteTimeIntegrator1_DSTAT_h[1] *
    Translation_Fusion_P_g.R_GRTK_B_Value[2] -
    Translation_Fusion_DW.DiscreteTimeIntegrator1_DSTAT_h[2] *
    Translation_Fusion_P_g.R_GRTK_B_Value[1];
  Translation_Fusion_B.DiscreteTimeIntegrator1_ek[1] =
    Translation_Fusion_DW.DiscreteTimeIntegrator1_DSTAT_h[1];
  Translation_Fusion_B.middle_thr =
    Translation_Fusion_DW.DiscreteTimeIntegrator1_DSTAT_h[2] *
    Translation_Fusion_P_g.R_GRTK_B_Value[0] -
    Translation_Fusion_DW.DiscreteTimeIntegrator1_DSTAT_h[0] *
    Translation_Fusion_P_g.R_GRTK_B_Value[2];
  Translation_Fusion_B.DiscreteTimeIntegrator1_ek[2] =
    Translation_Fusion_DW.DiscreteTimeIntegrator1_DSTAT_h[2];
  Translation_Fusion_B.Inverse_j =
    Translation_Fusion_DW.DiscreteTimeIntegrator1_DSTAT_h[0] *
    Translation_Fusion_P_g.R_GRTK_B_Value[1] -
    Translation_Fusion_DW.DiscreteTimeIntegrator1_DSTAT_h[1] *
    Translation_Fusion_P_g.R_GRTK_B_Value[0];
  for (Translation_Fusion_B.rtb_GPS_gain_tmp = 0;
       Translation_Fusion_B.rtb_GPS_gain_tmp < 3;
       Translation_Fusion_B.rtb_GPS_gain_tmp++) {
    Translation_Fusion_B.Delay1_f[Translation_Fusion_B.rtb_GPS_gain_tmp] =
      Translation_Fusion_B.rtu_Sensor_RTK_Data_vel_N[Translation_Fusion_B.rtb_GPS_gain_tmp]
      - ((rtu_Rotation_M_OB[Translation_Fusion_B.rtb_GPS_gain_tmp + 3] *
          Translation_Fusion_B.middle_thr +
          rtu_Rotation_M_OB[Translation_Fusion_B.rtb_GPS_gain_tmp] *
          Translation_Fusion_B.Relay1) +
         rtu_Rotation_M_OB[Translation_Fusion_B.rtb_GPS_gain_tmp + 6] *
         Translation_Fusion_B.Inverse_j);
  }

  Translation_Fusion_B.CreateDiagonalMatrix[1] = 0.0F;
  Translation_Fusion_B.CreateDiagonalMatrix[2] = 0.0F;
  Translation_Fusion_B.CreateDiagonalMatrix[0] =
    Translation_Fusion_P_g.process_noise_variance4_Value[0];
  Translation_Fusion_B.CreateDiagonalMatrix[3] =
    Translation_Fusion_P_g.process_noise_variance4_Value[1];
  if (Translation_Fusion_B.GPS_Vel_Vaild) {
    Translation_Fusion_Correct_x(Translation_Fusion_B.FixPtRelationalOperator_g,
      Translation_Fusion_DW.x_delay_DSTATE[0],
      Translation_Fusion_DW.x_delay1_DSTATE[0], Translation_Fusion_B.low_thr,
      Translation_Fusion_B.Product_i, Translation_Fusion_P_g.Constant_Value_cw,
      Translation_Fusion_B.DiscreteTimeIntegrator_ax,
      Translation_Fusion_P_g.Gain_Gain_m * Translation_Fusion_B.Delay1_f[2],
      Translation_Fusion_B.CreateDiagonalMatrix,
      &Translation_Fusion_B.Correct_x_m, &Translation_Fusion_P_g.Correct_x_m);
    for (Translation_Fusion_B.i = 0; Translation_Fusion_B.i < 9;
         Translation_Fusion_B.i++) {
      Translation_Fusion_B.Merge1[Translation_Fusion_B.i] =
        Translation_Fusion_B.Correct_x_m.Multiply5[Translation_Fusion_B.i];
    }

    Translation_Fusion_B.X_Cor_RTK[0] =
      Translation_Fusion_B.Correct_x_m.Multiply[0];
    Translation_Fusion_B.X_Cor_RTK[1] =
      Translation_Fusion_B.Correct_x_m.Multiply[1];
    Translation_Fusion_B.X_Cor_RTK[2] =
      Translation_Fusion_B.Correct_x_m.Multiply[2];
  }

  if (Translation_Fusion_B.P_RTK_update_flg) {
    if (Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_ag >=
        Translation_Fusion_P_g.CompareToConstant_const_o) {
      Translation_Fusion_B.Switch2_pu[0] =
        Translation_Fusion_P_g.Constant1_Value_g;
      Translation_Fusion_B.Switch2_pu[1] =
        Translation_Fusion_P_g.Constant1_Value_g;
      Translation_Fusion_B.Switch2_pu[2] =
        Translation_Fusion_P_g.Constant1_Value_g;
    } else {
      Translation_Fusion_B.Switch2_pu[0] = Translation_Fusion_P_g.Gain_Gain_p *
        Translation_Fusion_B.X_Cor_RTK[0];
      Translation_Fusion_B.Switch2_pu[1] = Translation_Fusion_P_g.Gain_Gain_p *
        Translation_Fusion_B.X_Cor_RTK[1];
      Translation_Fusion_B.Switch2_pu[2] = Translation_Fusion_P_g.Gain_Gain_p *
        Translation_Fusion_B.X_Cor_RTK[2];
    }

    Translation_Fusion_B.Switch2_pu[0] += Translation_Fusion_B.Switch_d[0];
    Translation_Fusion_B.Switch2_pu[1] += Translation_Fusion_B.Switch_d[1];
    Translation_Fusion_B.Switch2_pu[2] += Translation_Fusion_B.low_thr;
  } else {
    Translation_Fusion_B.Switch2_pu[0] = Translation_Fusion_B.Switch_d[0];
    Translation_Fusion_B.Switch2_pu[1] = Translation_Fusion_B.Switch_d[1];
    Translation_Fusion_B.Switch2_pu[2] = Translation_Fusion_B.low_thr;
  }

  Translation_Fusion_B.DiscreteTimeIntegrator_ax =
    *rtu_Sensor_Sonar_data_h_grd_son - Translation_Fusion_DW.UD_DSTATE;
  Translation_Fusion_B.Compare_mn =
    (Translation_Fusion_B.DiscreteTimeIntegrator_ax <=
     Translation_Fusion_P_g.SonarPreprocessor_vMaxUp);
  Translation_Fusion_B.Compare_ep =
    (Translation_Fusion_B.DiscreteTimeIntegrator_ax >=
     Translation_Fusion_P_g.SonarPreprocessor_vMaxDown);
  mw_arm_sqrt_f32(Translation_Fusion_DW.Delay2_DSTATE[0] *
                  Translation_Fusion_DW.Delay2_DSTATE[0] +
                  Translation_Fusion_DW.Delay2_DSTATE[1] *
                  Translation_Fusion_DW.Delay2_DSTATE[1],
                  &Translation_Fusion_B.DiscreteTimeIntegrator_ax);
  Translation_Fusion_B.Compare_afp =
    (Translation_Fusion_B.DiscreteTimeIntegrator_ax >
     Translation_Fusion_P_g.CompareToConstant5_const_b);
  Translation_Fusion_B.DiscreteTimeIntegrator5 =
    Translation_Fusion_DW.DiscreteTimeIntegrator5_DSTATE;
  Translation_Fusion_B.DiscreteTimeIntegrator5_h =
    Translation_Fusion_DW.DiscreteTimeIntegrator5_DSTAT_d;
  Translation_Fusion_B.DiscreteTimeIntegrator_ax = (real32_T)fabs
    (Translation_Fusion_B.DiscreteTimeIntegrator5 -
     Translation_Fusion_B.DiscreteTimeIntegrator5_h);
  Translation_Fusion_B.gps_pos_valid_m =
    (Translation_Fusion_B.DiscreteTimeIntegrator_ax >
     Translation_Fusion_P_g.CompareToConstant2_const_e);
  if (Translation_Fusion_B.gps_pos_valid_m ||
      (Translation_Fusion_DW.DiscreteTimeIntegrator_PrevR_by != 0)) {
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_fa =
      Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_eg;
  }

  Translation_Fusion_B.rtk_pos_valid_j = ((int32_T)((uint32_T)
    (Translation_Fusion_DW.Delay_DSTATE_k1 &&
     (!(Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_fa >=
        Translation_Fusion_P_g.CompareTo1sec_const_h))) +
    Translation_Fusion_B.gps_pos_valid_m) != 0);
  Translation_Fusion_B.GPS_Vel_Vaild =
    (Translation_Fusion_B.DiscreteTimeIntegrator_ax <=
     Translation_Fusion_P_g.CompareToConstant4_const_f);
  Translation_Fusion_B.En_Corr_Pz_RTK = !Translation_Fusion_B.GPS_Vel_Vaild;
  if (Translation_Fusion_B.En_Corr_Pz_RTK ||
      (Translation_Fusion_DW.DiscreteTimeIntegrator_PrevR_gw != 0)) {
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE_m =
      Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_ku;
  }

  Translation_Fusion_B.En_sonar_Correct = ((*rtu_Sensor_Sonar_data_timestamp >
    Translation_Fusion_DW.DelayInput1_DSTATE_j3) &&
    (*rtu_Sensor_Sonar_data_sonar_val) && (Translation_Fusion_B.Compare_mn &&
    Translation_Fusion_B.Compare_ep && (*rtu_Sensor_Sonar_data_h_grd_son >
    Translation_Fusion_P_g.CompareToConstant6_const)) &&
    ((!Translation_Fusion_B.Compare_afp) || (!(*rtu_Sensor_GPS_data_Spd_quality >
    Translation_Fusion_P_g.CompareToConstant3_const_b)) ||
     ((!Translation_Fusion_B.rtk_pos_valid_j) &&
      (Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE_m >
       Translation_Fusion_P_g.CompareToConstant3_const_p))));
  Translation_Fusion_B.NOT1 = ((*rtu_Sensor_RTK_Data_rtk_type <
    Translation_Fusion_P_g.CompareToConstant3_const_n0) ||
    (!Translation_Fusion_B.GPS_Good));
  Translation_Fusion_B.LogicalOperator1_ks = (Translation_Fusion_B.NOT1 &&
    Translation_Fusion_DW.Delay_DSTATE_n);
  Translation_Fusion_B.Compare_mn = (rtb_Reset_TF_tmp ||
    Translation_Fusion_B.LogicalOperator1_ks);
  Translation_Fusion_B.rtb_LogicalOperator_co_idx_0 = (rtb_Reset_TF_tmp ||
    Translation_Fusion_DW.Delay2_DSTATE_a[0]);
  if (Translation_Fusion_DW.Delay1_DSTATE_c[0]) {
    Translation_Fusion_B.rtb_Switch_l_idx_0 =
      Translation_Fusion_DW.Delay3_DSTATE[0];
  } else {
    Translation_Fusion_B.rtb_Switch_l_idx_0 =
      Translation_Fusion_DW.Delay_DSTATE_o[0];
  }

  Translation_Fusion_B.rtb_DiscreteTimeIntegrator1_lt_ =
    Translation_Fusion_DW.Delay_DSTATE_o[0];
  Translation_Fusion_B.rtb_LogicalOperator_co_idx_1 = (rtb_Reset_TF_tmp ||
    Translation_Fusion_DW.Delay2_DSTATE_a[1]);
  Translation_Fusion_B.rtb_DiscreteTimeIntegrator1_l_p =
    Translation_Fusion_DW.Delay_DSTATE_o[1];
  if (Translation_Fusion_DW.Delay1_DSTATE_c[1]) {
    Translation_Fusion_B.DiscreteTimeIntegrator_ax =
      Translation_Fusion_DW.Delay3_DSTATE[1];
  } else {
    Translation_Fusion_B.DiscreteTimeIntegrator_ax =
      Translation_Fusion_DW.Delay_DSTATE_o[1];
  }

  if (Translation_Fusion_DW.DiscreteTimeIntegrator_IC_LO_aj != 0) {
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE_i[0] =
      Translation_Fusion_B.rtb_Switch_l_idx_0;
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE_i[1] =
      Translation_Fusion_B.DiscreteTimeIntegrator_ax;
  }

  if (Translation_Fusion_B.rtb_LogicalOperator_co_idx_0 ||
      (Translation_Fusion_DW.DiscreteTimeIntegrator_PrevR_gg[0] != 0)) {
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE_i[0] =
      Translation_Fusion_B.rtb_Switch_l_idx_0;
  }

  Translation_Fusion_B.rtb_Switch_l_idx_0 =
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE_i[0];
  if (Translation_Fusion_B.rtb_LogicalOperator_co_idx_1 ||
      (Translation_Fusion_DW.DiscreteTimeIntegrator_PrevR_gg[1] != 0)) {
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE_i[1] =
      Translation_Fusion_B.DiscreteTimeIntegrator_ax;
  }

  Translation_Fusion_B.rtb_Switch_l_l =
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE_i[1];
  if ((((Translation_Fusion_PrevZCX.Delay2_Reset_ZCE == POS_ZCSIG) != (int32_T)
        Translation_Fusion_B.Compare_mn) &&
       (Translation_Fusion_PrevZCX.Delay2_Reset_ZCE != UNINITIALIZED_ZCSIG)) ||
      Translation_Fusion_B.Compare_mn) {
    Translation_Fusion_DW.icLoad_gb = 1U;
  }

  Translation_Fusion_PrevZCX.Delay2_Reset_ZCE = Translation_Fusion_B.Compare_mn;
  if (Translation_Fusion_DW.icLoad_gb != 0) {
    if (Translation_Fusion_B.LogicalOperator1_ks) {
      Translation_Fusion_DW.Delay2_DSTATE_e[0] =
        Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE_i[0];
      Translation_Fusion_DW.Delay2_DSTATE_e[1] =
        Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE_i[1];
    } else {
      Translation_Fusion_DW.Delay2_DSTATE_e[0] =
        Translation_Fusion_P_g.x1_Value[0];
      Translation_Fusion_DW.Delay2_DSTATE_e[1] =
        Translation_Fusion_P_g.x1_Value[1];
    }
  }

  rty_Translation_data_POS_xy_O_m[0] = Translation_Fusion_DW.Delay2_DSTATE_e[0];
  Translation_Fusion_B.DiscreteTimeIntegrator_ax =
    rty_Translation_data_POS_xy_O_m[0] * rty_Translation_data_POS_xy_O_m[0];
  rty_Translation_data_POS_xy_O_m[1] = Translation_Fusion_DW.Delay2_DSTATE_e[1];
  Translation_Fusion_B.DiscreteTimeIntegrator_ax +=
    rty_Translation_data_POS_xy_O_m[1] * rty_Translation_data_POS_xy_O_m[1];
  mw_arm_sqrt_f32(Translation_Fusion_B.DiscreteTimeIntegrator_ax,
                  &Translation_Fusion_B.DiscreteTimeIntegrator_ax);
  Translation_Fusion_B.LogicalOperator2_f = (((Translation_Fusion_B.Switch2_pu[1]
    <= Translation_Fusion_P_g.CompareToConstant2_const_k) &&
    Translation_Fusion_B.En_sonar_Correct &&
    (Translation_Fusion_B.DiscreteTimeIntegrator_ax <=
     Translation_Fusion_P_g.CompareToConstant1_const_p) &&
    (!Translation_Fusion_B.P_RTK_update_flg)) || rtb_Reset_TF_tmp);
  mw_arm_sqrt_f32(Translation_Fusion_DW.Delay1_DSTATE_f[0] *
                  Translation_Fusion_DW.Delay1_DSTATE_f[0] +
                  Translation_Fusion_DW.Delay1_DSTATE_f[1] *
                  Translation_Fusion_DW.Delay1_DSTATE_f[1],
                  &Translation_Fusion_B.DiscreteTimeIntegrator_ax);
  if (Translation_Fusion_B.Compare_i ||
      (Translation_Fusion_DW.DiscreteTimeIntegrator_PrevR_bz != 0)) {
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_ab =
      Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_pc;
  }

  Translation_Fusion_B.Compare_mn = ((int32_T)((uint32_T)
    (Translation_Fusion_DW.Delay_DSTATE_pi &&
     (!(Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_ab >=
        Translation_Fusion_P_g.CompareTo1sec_const_he))) +
    Translation_Fusion_B.Compare_i) != 0);
  Translation_Fusion_B.LogicalOperator1_ks =
    (Translation_Fusion_DW.Delay1_DSTATE_g >
     Translation_Fusion_P_g.CompareToConstant_const_on);
  Translation_Fusion_B.Compare_ep = !Translation_Fusion_B.LogicalOperator1_ks;
  if (Translation_Fusion_B.Compare_ep ||
      (Translation_Fusion_DW.DiscreteTimeIntegrator_PrevRe_d != 0)) {
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_gt =
      Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_a3;
  }

  if (Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_gt >=
      Translation_Fusion_P_g.DiscreteTimeIntegrator_Upper_eh) {
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_gt =
      Translation_Fusion_P_g.DiscreteTimeIntegrator_Upper_eh;
  } else {
    if (Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_gt <=
        Translation_Fusion_P_g.DiscreteTimeIntegrator_LowerS_l) {
      Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_gt =
        Translation_Fusion_P_g.DiscreteTimeIntegrator_LowerS_l;
    }
  }

  Translation_Fusion_B.Compare_afp =
    (Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_gt >
     Translation_Fusion_P_g.Validafteraperiod_T_p_n);
  if (((Translation_Fusion_B.DiscreteTimeIntegrator1_f5h >
        Translation_Fusion_P_g.CompareToConstant4_const_o) &&
       (Translation_Fusion_B.DiscreteTimeIntegrator_ax >
        Translation_Fusion_P_g.CompareToConstant2_const_eh)) ||
      (Translation_Fusion_DW.Delay_DSTATE_o1 &&
       (*rtu_Sensor_Sonar_data_sonar_val) && (*rtu_Sensor_Sonar_data_h_grd_son >
        Translation_Fusion_P_g.CompareToConstant_const_bs)) || ((((real32_T)fabs
         (*rtu_Sensor_Sonar_data_h_grd_son -
          Translation_Fusion_DW.Delay_DSTATE_of) >
         Translation_Fusion_P_g.HeightFusionwithaccbias_stage_t) &&
        (*rtu_Sensor_Sonar_data_sonar_val) &&
        Translation_Fusion_DW.Delay1_DSTATE_nb) || ((int32_T)
        *rtu_Sensor_Sonar_data_sonar_val > (int32_T)
        Translation_Fusion_DW.DelayInput1_DSTATE_o)) ||
      Translation_Fusion_B.Compare_mn || rtb_Reset_TF_tmp || ((int32_T)
       Translation_Fusion_B.Compare_afp > (int32_T)
       Translation_Fusion_DW.DelayInput1_DSTATE_f)) {
    Translation_Fusion_B.bias_filtered = Translation_Fusion_B.Switch2_pu[0] -
      *rtu_Sensor_Sonar_data_h_grd_son;
  }

  if ((((Translation_Fusion_PrevZCX.Delay2_Reset_ZCE_b == POS_ZCSIG) != (int32_T)
        Translation_Fusion_B.LogicalOperator2_f) &&
       (Translation_Fusion_PrevZCX.Delay2_Reset_ZCE_b != UNINITIALIZED_ZCSIG)) ||
      Translation_Fusion_B.LogicalOperator2_f) {
    Translation_Fusion_DW.icLoad_gm = 1U;
  }

  Translation_Fusion_PrevZCX.Delay2_Reset_ZCE_b =
    Translation_Fusion_B.LogicalOperator2_f;
  if (Translation_Fusion_DW.icLoad_gm != 0) {
    if (*rtu_Armed) {
      Translation_Fusion_DW.Delay2_DSTATE_b = Translation_Fusion_B.bias_filtered;
    } else {
      Translation_Fusion_DW.Delay2_DSTATE_b =
        Translation_Fusion_P_g.Constant_Value_b;
    }
  }

  Translation_Fusion_B.DiscreteTimeIntegrator_ax =
    Translation_Fusion_DW.Delay2_DSTATE_b;
  Translation_Fusion_B.Relay1 = Translation_Fusion_B.Switch2_pu[0] -
    Translation_Fusion_DW.Delay2_DSTATE_b;
  *rty_Translation_data_h_0_AGL_m = Translation_Fusion_P_g.Gain1_Gain_o *
    Translation_Fusion_B.Relay1;
  if (Translation_Fusion_DW.obj.TunablePropsChanged) {
    Translation_Fusion_DW.obj.TunablePropsChanged = false;
  }

  if (Translation_Fusion_DW.obj.pStatistic->isInitialized != 1) {
    Translation_Fusion_DW.obj.pStatistic->isSetupComplete = false;
    Translation_Fusion_DW.obj.pStatistic->isInitialized = 1;
    Translation_Fusion_DW.obj.pStatistic->pCumSum = 0.0F;
    Translation_Fusion_DW.obj.pStatistic->pCumRevIndex = 1.0F;
    Translation_Fusion_DW.obj.pStatistic->isSetupComplete = true;
    Translation_Fusion_DW.obj.pStatistic->pCumSum = 0.0F;
    memset(&Translation_Fusion_DW.obj.pStatistic->pCumSumRev[0], 0, 401U *
           sizeof(real32_T));
    Translation_Fusion_DW.obj.pStatistic->pCumRevIndex = 1.0F;
  }

  Translation_Fusion_B.Sum_ol =
    Translation_Fusion_DW.obj.pStatistic->pCumRevIndex;
  Translation_Fusion_B.csum = Translation_Fusion_DW.obj.pStatistic->pCumSum;
  for (Translation_Fusion_B.rtb_GPS_gain_tmp = 0;
       Translation_Fusion_B.rtb_GPS_gain_tmp < 401;
       Translation_Fusion_B.rtb_GPS_gain_tmp++) {
    Translation_Fusion_B.csumrev[Translation_Fusion_B.rtb_GPS_gain_tmp] =
      Translation_Fusion_DW.obj.pStatistic->
      pCumSumRev[Translation_Fusion_B.rtb_GPS_gain_tmp];
  }

  Translation_Fusion_B.csum += Translation_Fusion_B.Switch2_pu[1];
  Translation_Fusion_B.rtb_GPS_gain_tmp = (int32_T)Translation_Fusion_B.Sum_ol -
    1;
  Translation_Fusion_B.GPS_gain =
    Translation_Fusion_B.csumrev[Translation_Fusion_B.rtb_GPS_gain_tmp] +
    Translation_Fusion_B.csum;
  Translation_Fusion_B.csumrev[Translation_Fusion_B.rtb_GPS_gain_tmp] =
    Translation_Fusion_B.Switch2_pu[1];
  if (Translation_Fusion_B.Sum_ol != 401.0F) {
    Translation_Fusion_B.Sum_ol++;
  } else {
    Translation_Fusion_B.Sum_ol = 1.0F;
    Translation_Fusion_B.csum = 0.0F;
    for (Translation_Fusion_B.i = 399; Translation_Fusion_B.i >= 0;
         Translation_Fusion_B.i--) {
      Translation_Fusion_B.csumrev[Translation_Fusion_B.i] +=
        Translation_Fusion_B.csumrev[Translation_Fusion_B.i + 1];
    }
  }

  Translation_Fusion_DW.obj.pStatistic->pCumSum = Translation_Fusion_B.csum;
  memcpy(&Translation_Fusion_DW.obj.pStatistic->pCumSumRev[0],
         &Translation_Fusion_B.csumrev[0], 401U * sizeof(real32_T));
  Translation_Fusion_DW.obj.pStatistic->pCumRevIndex =
    Translation_Fusion_B.Sum_ol;
  Translation_Fusion_B.LogicalOperator2_f = (*rtu_Sensor_baro_Timestamp_ms >
    Translation_Fusion_DW.DelayInput1_DSTATE_k);
  if (Translation_Fusion_B.LogicalOperator2_f &&
      (Translation_Fusion_PrevZCX.MovingAverage_Trig_ZCE != POS_ZCSIG)) {
    if (Translation_Fusion_DW.icLoad_b != 0) {
      for (Translation_Fusion_B.i = 0; Translation_Fusion_B.i < 10;
           Translation_Fusion_B.i++) {
        Translation_Fusion_DW.Delay2_DSTATE_n[Translation_Fusion_B.i] =
          *rtu_Sensor_delta_h_baro_m;
      }
    }

    if (Translation_Fusion_DW.icLoad_l != 0) {
      Translation_Fusion_DW.Delay_DSTATE_oc =
        Translation_Fusion_P_g.Gain1_Gain_i * *rtu_Sensor_delta_h_baro_m;
    }

    Translation_Fusion_B.middle_thr = (*rtu_Sensor_delta_h_baro_m -
      Translation_Fusion_DW.Delay2_DSTATE_n[0]) +
      Translation_Fusion_DW.Delay_DSTATE_oc;
    Translation_Fusion_B.Gain = Translation_Fusion_P_g.Gain_Gain_k *
      Translation_Fusion_B.middle_thr;
    Translation_Fusion_DW.icLoad_b = 0U;
    for (Translation_Fusion_B.i = 0; Translation_Fusion_B.i < 9;
         Translation_Fusion_B.i++) {
      Translation_Fusion_DW.Delay2_DSTATE_n[Translation_Fusion_B.i] =
        Translation_Fusion_DW.Delay2_DSTATE_n[Translation_Fusion_B.i + 1];
    }

    Translation_Fusion_DW.Delay2_DSTATE_n[9] = *rtu_Sensor_delta_h_baro_m;
    Translation_Fusion_DW.icLoad_l = 0U;
    Translation_Fusion_DW.Delay_DSTATE_oc = Translation_Fusion_B.middle_thr;
  }

  Translation_Fusion_PrevZCX.MovingAverage_Trig_ZCE =
    Translation_Fusion_B.LogicalOperator2_f;
  Translation_Fusion_B.Sum_ol = Translation_Fusion_B.GPS_gain / 402.0F *
    Translation_Fusion_P_g.ust_orderdelaycompensator1_N_c *
    Translation_Fusion_P_g.SampleTime_WtEt_o;
  if (Translation_Fusion_B.Sum_ol > Translation_Fusion_P_g.Saturation_UpperSat_l)
  {
    Translation_Fusion_B.Sum_ol = Translation_Fusion_P_g.Saturation_UpperSat_l;
  } else {
    if (Translation_Fusion_B.Sum_ol <
        Translation_Fusion_P_g.Saturation_LowerSat_b) {
      Translation_Fusion_B.Sum_ol = Translation_Fusion_P_g.Saturation_LowerSat_b;
    }
  }

  Translation_Fusion_B.middle_thr = Translation_Fusion_B.Sum_ol +
    Translation_Fusion_B.Gain;
  if (Translation_Fusion_DW.obj_p.TunablePropsChanged) {
    Translation_Fusion_DW.obj_p.TunablePropsChanged = false;
  }

  if (Translation_Fusion_DW.obj_p.pStatistic->isInitialized != 1) {
    Translation_Fusion_DW.obj_p.pStatistic->isSetupComplete = false;
    Translation_Fusion_DW.obj_p.pStatistic->isInitialized = 1;
    Translation_Fusion_DW.obj_p.pStatistic->pCumSum = 0.0F;
    Translation_Fusion_DW.obj_p.pStatistic->pCumRevIndex = 1.0F;
    Translation_Fusion_DW.obj_p.pStatistic->isSetupComplete = true;
    Translation_Fusion_DW.obj_p.pStatistic->pCumSum = 0.0F;
    memset(&Translation_Fusion_DW.obj_p.pStatistic->pCumSumRev[0], 0, 99U *
           sizeof(real32_T));
    Translation_Fusion_DW.obj_p.pStatistic->pCumRevIndex = 1.0F;
  }

  Translation_Fusion_B.Sum_ol =
    Translation_Fusion_DW.obj_p.pStatistic->pCumRevIndex;
  Translation_Fusion_B.csum = Translation_Fusion_DW.obj_p.pStatistic->pCumSum;
  for (Translation_Fusion_B.rtb_GPS_gain_tmp = 0;
       Translation_Fusion_B.rtb_GPS_gain_tmp < 99;
       Translation_Fusion_B.rtb_GPS_gain_tmp++) {
    Translation_Fusion_B.csumrev_m[Translation_Fusion_B.rtb_GPS_gain_tmp] =
      Translation_Fusion_DW.obj_p.pStatistic->
      pCumSumRev[Translation_Fusion_B.rtb_GPS_gain_tmp];
  }

  Translation_Fusion_B.csum += Translation_Fusion_B.middle_thr;
  Translation_Fusion_B.rtb_GPS_gain_tmp = (int32_T)Translation_Fusion_B.Sum_ol -
    1;
  Translation_Fusion_B.GPS_gain =
    Translation_Fusion_B.csumrev_m[Translation_Fusion_B.rtb_GPS_gain_tmp] +
    Translation_Fusion_B.csum;
  Translation_Fusion_B.csumrev_m[Translation_Fusion_B.rtb_GPS_gain_tmp] =
    Translation_Fusion_B.middle_thr;
  if (Translation_Fusion_B.Sum_ol != 99.0F) {
    Translation_Fusion_B.Sum_ol++;
  } else {
    Translation_Fusion_B.Sum_ol = 1.0F;
    Translation_Fusion_B.csum = 0.0F;
    for (Translation_Fusion_B.i = 97; Translation_Fusion_B.i >= 0;
         Translation_Fusion_B.i--) {
      Translation_Fusion_B.csumrev_m[Translation_Fusion_B.i] +=
        Translation_Fusion_B.csumrev_m[Translation_Fusion_B.i + 1];
    }
  }

  Translation_Fusion_DW.obj_p.pStatistic->pCumSum = Translation_Fusion_B.csum;
  memcpy(&Translation_Fusion_DW.obj_p.pStatistic->pCumSumRev[0],
         &Translation_Fusion_B.csumrev_m[0], 99U * sizeof(real32_T));
  Translation_Fusion_DW.obj_p.pStatistic->pCumRevIndex =
    Translation_Fusion_B.Sum_ol;
  Translation_Fusion_B.GPS_gain /= 100.0F;
  if (rtb_Reset_TF_tmp) {
    Translation_Fusion_B.In1 = Translation_Fusion_B.GPS_gain;
  }

  Translation_Fusion_B.middle_thr = Translation_Fusion_B.GPS_gain -
    Translation_Fusion_B.In1;
  if (*rtu_Sensor_GPS_data_Pos_quality >= Translation_Fusion_P_g.u9509_OnVal) {
    Translation_Fusion_DW.u9509_Mode = true;
  } else {
    if (*rtu_Sensor_GPS_data_Pos_quality <= Translation_Fusion_P_g.u9509_OffVal)
    {
      Translation_Fusion_DW.u9509_Mode = false;
    }
  }

  if (Translation_Fusion_DW.u9509_Mode) {
    Translation_Fusion_B.Sqrt = Translation_Fusion_P_g.u9509_YOn;
  } else {
    Translation_Fusion_B.Sqrt = Translation_Fusion_P_g.u9509_YOff;
  }

  Translation_Fusion_B.En_GPS_height_Correct = (Translation_Fusion_B.Compare_mr &&
    Translation_Fusion_B.LogicalOperator2_hv && (Translation_Fusion_B.Sqrt !=
    0.0F));
  if (Translation_Fusion_B.En_GPS_height_Correct ||
      (Translation_Fusion_DW.DiscreteTimeIntegrator_PrevRe_a != 0)) {
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_ai =
      Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_b;
  }

  Translation_Fusion_B.LogicalOperator_hz =
    (Translation_Fusion_DW.Delay_DSTATE_l &&
     (!(Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_ai >=
        Translation_Fusion_P_g.CompareTo1sec_const_f)));
  Translation_Fusion_B.GPS_height_enable = (((int32_T)((uint32_T)
    (Translation_Fusion_DW.Delay_DSTATE_l &&
     (!(Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_ai >=
        Translation_Fusion_P_g.CompareTo1sec_const_f))) +
    Translation_Fusion_B.En_GPS_height_Correct) != 0) && (*rtu_Armed));
  Translation_Fusion_B.rtb_DataTypeConversion1_e_tmp = (uint32_T)
    (Translation_Fusion_DW.Delay_DSTATE_by && (*rtu_Armed));
  Translation_Fusion_B.DataTypeConversion1_e = ((int32_T)
    ((Translation_Fusion_B.GPS_height_enable && (*rtu_Armed)) +
     Translation_Fusion_B.rtb_DataTypeConversion1_e_tmp) != 0);
  if (Translation_Fusion_B.DataTypeConversion1_e &&
      (Translation_Fusion_PrevZCX.Delay_Reset_ZCE_o != POS_ZCSIG)) {
    Translation_Fusion_DW.icLoad_d = 1U;
  }

  Translation_Fusion_PrevZCX.Delay_Reset_ZCE_o = (ZCSigState)((int32_T)
    ((Translation_Fusion_B.GPS_height_enable && (*rtu_Armed)) +
     Translation_Fusion_B.rtb_DataTypeConversion1_e_tmp) != 0);
  if (Translation_Fusion_DW.icLoad_d != 0) {
    Translation_Fusion_DW.Delay_DSTATE_m = *rtu_Sensor_GPS_data_GpsHeight -
      Translation_Fusion_B.Switch2_pu[0];
  }

  Translation_Fusion_B.low_thr = Translation_Fusion_DW.Delay_DSTATE_m;
  if (*rtu_Armed) {
    Translation_Fusion_B.GPS_gain = *rtu_Sensor_GPS_data_GpsHeight -
      Translation_Fusion_DW.Delay_DSTATE_m;
  } else {
    Translation_Fusion_B.GPS_gain = Translation_Fusion_P_g.Constant_Value_lm;
  }

  if (rtb_Reset_TF_tmp && (Translation_Fusion_DW.DiscreteTimeIntegrator_PrevR_jg
       <= 0)) {
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_eb =
      Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_d1;
  }

  Translation_Fusion_B.DiscreteTimeIntegrator_bj =
    ((Translation_Fusion_B.GPS_gain +
      Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_eb) +
     Translation_Fusion_B.middle_thr) * Translation_Fusion_P_g.Gain_Gain_p4;
  Translation_Fusion_B.Subtract1 = Translation_Fusion_B.GPS_gain -
    Translation_Fusion_B.DiscreteTimeIntegrator_bj;
  if (Translation_Fusion_DW.DiscreteTimeIntegrator_IC_LOA_f != 0) {
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_i1 =
      Translation_Fusion_B.Subtract1;
  }

  Translation_Fusion_B.Inverse_j = (real32_T)fabs
    (Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_i1);
  Translation_Fusion_B.Subtract2 =
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_eb -
    Translation_Fusion_B.DiscreteTimeIntegrator_bj;
  if (Translation_Fusion_DW.DiscreteTimeIntegrator_IC_LOA_k != 0) {
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_cq =
      Translation_Fusion_B.Subtract2;
  }

  Translation_Fusion_B.Abs1 = (real32_T)fabs
    (Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_cq);
  Translation_Fusion_B.Subtract3 = Translation_Fusion_B.middle_thr -
    Translation_Fusion_B.DiscreteTimeIntegrator_bj;
  if (Translation_Fusion_DW.DiscreteTimeIntegrator_IC_LOA_m != 0) {
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_eq =
      Translation_Fusion_B.Subtract3;
  }

  Translation_Fusion_B.Abs2 = (real32_T)fabs
    (Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_eq);
  Translation_Fusion_B.Compare_ko = rtIsNaNF(Translation_Fusion_B.Abs2);
  if ((Translation_Fusion_B.Inverse_j > Translation_Fusion_B.Abs2) ||
      Translation_Fusion_B.Compare_ko) {
    Translation_Fusion_B.Sum_ol = Translation_Fusion_B.Inverse_j;
  } else {
    Translation_Fusion_B.Sum_ol = Translation_Fusion_B.Abs2;
  }

  tmp = rtIsNaNF(Translation_Fusion_B.Abs1);
  if ((!(Translation_Fusion_B.Sum_ol > Translation_Fusion_B.Abs1)) && (!tmp)) {
    Translation_Fusion_B.Sum_ol = Translation_Fusion_B.Abs1;
  }

  if (Translation_Fusion_B.Sum_ol >=
      Translation_Fusion_P_g.CompareToConstant_const_l) {
    if ((Translation_Fusion_B.Inverse_j < Translation_Fusion_B.Abs1) || tmp) {
      Translation_Fusion_B.DiscreteTimeIntegrator_bj =
        Translation_Fusion_B.Inverse_j;
    } else {
      Translation_Fusion_B.DiscreteTimeIntegrator_bj = Translation_Fusion_B.Abs1;
    }

    if ((!(Translation_Fusion_B.DiscreteTimeIntegrator_bj <
           Translation_Fusion_B.Abs2)) && (!Translation_Fusion_B.Compare_ko)) {
      Translation_Fusion_B.DiscreteTimeIntegrator_bj = Translation_Fusion_B.Abs2;
    }

    Translation_Fusion_B.Sum2_a = (uint8_T)((real32_T)fabs
      (Translation_Fusion_B.Abs2 -
       Translation_Fusion_B.DiscreteTimeIntegrator_bj) <=
      Translation_Fusion_P_g.CompareToConstant1_const_n2 ? (int32_T)
      Translation_Fusion_P_g.Gain3_Gain_j : 0);
    Translation_Fusion_B.Abs1 = (real32_T)fabs(Translation_Fusion_B.Abs1 -
      Translation_Fusion_B.DiscreteTimeIntegrator_bj);
    Translation_Fusion_B.DiscreteTimeIntegrator_bj =
      Translation_Fusion_B.Inverse_j -
      Translation_Fusion_B.DiscreteTimeIntegrator_bj;
    Translation_Fusion_B.DiscreteTimeIntegrator_bj = (real32_T)fabs
      (Translation_Fusion_B.DiscreteTimeIntegrator_bj);
    Translation_Fusion_B.state = (real32_T)(uint8_T)(((((uint32_T)
      (Translation_Fusion_B.Abs1 <=
       Translation_Fusion_P_g.CompareToConstant1_const_n ? (int32_T)
       Translation_Fusion_P_g.Gain2_Gain_kw : 0) << 1) +
      (Translation_Fusion_B.DiscreteTimeIntegrator_bj <=
       Translation_Fusion_P_g.CompareToConstant1_const_c ? (int32_T)
       Translation_Fusion_P_g.Gain1_Gain_je : 0)) + ((uint32_T)
      Translation_Fusion_B.Sum2_a << 1)) >> 1) * 0.015625F;
  } else {
    Translation_Fusion_B.state = Translation_Fusion_P_g.Constant_Value_jp;
  }

  switch ((int32_T)Translation_Fusion_B.state) {
   case 1:
    break;

   case 2:
    Translation_Fusion_B.GPS_height_enable =
      Translation_Fusion_P_g.Constant5_Value_e;
    break;

   case 3:
    Translation_Fusion_B.GPS_height_enable =
      Translation_Fusion_P_g.Constant5_Value_e;
    break;

   default:
    Translation_Fusion_B.GPS_height_enable =
      Translation_Fusion_P_g.Constant4_Value_l;
    break;
  }

  if (Translation_Fusion_B.GPS_height_enable) {
    Translation_Fusion_B.Switch1_k = Translation_Fusion_B.GPS_gain -
      Translation_Fusion_B.middle_thr;
  } else {
    Translation_Fusion_B.Switch1_k = Translation_Fusion_B.Switch2_pu[0] -
      Translation_Fusion_B.middle_thr;
  }

  if (Translation_Fusion_DW.DiscreteTimeIntegrator_IC_LO_ae != 0) {
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_j3 =
      Translation_Fusion_B.Switch1_k;
  }

  if (rtb_Reset_TF_tmp && (Translation_Fusion_DW.DiscreteTimeIntegrator_PrevRe_o
       <= 0)) {
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_j3 =
      Translation_Fusion_B.Switch1_k;
  }

  Translation_Fusion_B.Sum_d = Translation_Fusion_B.middle_thr +
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_j3;
  if (Translation_Fusion_B.P_RTK_update_flg) {
    for (Translation_Fusion_B.rtb_GPS_gain_tmp = 0;
         Translation_Fusion_B.rtb_GPS_gain_tmp < 9;
         Translation_Fusion_B.rtb_GPS_gain_tmp++) {
      Translation_Fusion_B.GPS_gain =
        Translation_Fusion_B.Product_i[Translation_Fusion_B.rtb_GPS_gain_tmp];
      if (Translation_Fusion_B.FixPtRelationalOperator_g) {
        Translation_Fusion_B.GPS_gain =
          Translation_Fusion_B.Merge1[Translation_Fusion_B.rtb_GPS_gain_tmp];
      }

      Translation_Fusion_B.Product_i[Translation_Fusion_B.rtb_GPS_gain_tmp] =
        Translation_Fusion_B.GPS_gain;
    }
  }

  mw_arm_sqrt_f32(Translation_Fusion_DW.DiscreteTimeIntegrator1_DSTAT_f[0] *
                  Translation_Fusion_DW.DiscreteTimeIntegrator1_DSTAT_f[0] +
                  Translation_Fusion_DW.DiscreteTimeIntegrator1_DSTAT_f[1] *
                  Translation_Fusion_DW.DiscreteTimeIntegrator1_DSTAT_f[1],
                  &Translation_Fusion_B.DiscreteTimeIntegrator1_at);
  if (Translation_Fusion_B.Compare_j ||
      (Translation_Fusion_B.DiscreteTimeIntegrator1_at <=
       Translation_Fusion_P_g.CompareToConstant_const_p5)) {
    Translation_Fusion_B.GPS_gain = Translation_Fusion_P_g.sonarnoise_Value;
  } else {
    Translation_Fusion_B.GPS_gain = Translation_Fusion_P_g.sonarnoise1_Value;
  }

  if (Translation_Fusion_B.En_sonar_Correct) {
    Translation_Fusion_B.Inverse_j = (Translation_Fusion_B.bias_filtered +
      *rtu_Sensor_Sonar_data_h_grd_son) - ((Translation_Fusion_P_g.C_Value_n[0] *
      Translation_Fusion_B.Switch2_pu[0] + Translation_Fusion_P_g.C_Value_n[1] *
      Translation_Fusion_B.Switch2_pu[1]) + Translation_Fusion_P_g.C_Value_n[2] *
      Translation_Fusion_B.Switch2_pu[2]);
    Translation_Fusion_B.DiscreteTimeIntegrator_bj =
      (Translation_Fusion_B.Inverse_j * Translation_Fusion_B.Inverse_j +
       Translation_Fusion_DW.Delay_DSTATE_i) -
      Translation_Fusion_DW.Delay1_DSTATE_hr *
      Translation_Fusion_DW.Delay1_DSTATE_hr;
    Translation_Fusion_B.Inverse_h = 1.0F / Translation_Fusion_B.GPS_gain;
    Translation_Fusion_B.MatrixMultiply3 = Translation_Fusion_B.Inverse_h *
      Translation_Fusion_B.Inverse_j * Translation_Fusion_B.Inverse_j;
    if (Translation_Fusion_B.MatrixMultiply3 >
        Translation_Fusion_P_g.AdaptiveCorrection_kai_b) {
      Translation_Fusion_B.Sqrt = 0.0F;
      for (Translation_Fusion_B.rtb_GPS_gain_tmp = 0;
           Translation_Fusion_B.rtb_GPS_gain_tmp < 3;
           Translation_Fusion_B.rtb_GPS_gain_tmp++) {
        Translation_Fusion_B.Sqrt +=
          Translation_Fusion_P_g.C_Value_n[Translation_Fusion_B.rtb_GPS_gain_tmp]
          * (Translation_Fusion_B.Product_i[Translation_Fusion_B.rtb_GPS_gain_tmp
             + 6] * Translation_Fusion_P_g.C_Value_n[2] +
             (Translation_Fusion_B.Product_i[Translation_Fusion_B.rtb_GPS_gain_tmp
              + 3] * Translation_Fusion_P_g.C_Value_n[1] +
              Translation_Fusion_B.Product_i[Translation_Fusion_B.rtb_GPS_gain_tmp]
              * Translation_Fusion_P_g.C_Value_n[0]));
      }

      Translation_Fusion_B.Sum_ol = (Translation_Fusion_P_g.Gain_Gain_h *
        Translation_Fusion_B.DiscreteTimeIntegrator_bj -
        Translation_Fusion_B.Sqrt) * Translation_Fusion_B.Inverse_h;
      if ((!(Translation_Fusion_B.Sum_ol >
             Translation_Fusion_P_g.Constant_Value_lk)) && (!rtIsNaNF
           (Translation_Fusion_P_g.Constant_Value_lk))) {
        Translation_Fusion_B.Sum_ol = Translation_Fusion_P_g.Constant_Value_lk;
      }

      if ((!(Translation_Fusion_B.Sum_ol <
             Translation_Fusion_P_g.AdaptiveCorrection_max_eta_l)) && (!rtIsNaNF
           (Translation_Fusion_P_g.AdaptiveCorrection_max_eta_l))) {
        Translation_Fusion_B.Sum_ol =
          Translation_Fusion_P_g.AdaptiveCorrection_max_eta_l;
      }

      Translation_Fusion_B.GPS_gain *= Translation_Fusion_B.Sum_ol;
    }

    Translation_Fusion_B.Sqrt = 0.0F;
    for (Translation_Fusion_B.rtb_GPS_gain_tmp = 0;
         Translation_Fusion_B.rtb_GPS_gain_tmp < 3;
         Translation_Fusion_B.rtb_GPS_gain_tmp++) {
      Translation_Fusion_B.Sqrt +=
        Translation_Fusion_P_g.C_Value_n[Translation_Fusion_B.rtb_GPS_gain_tmp] *
        (Translation_Fusion_B.Product_i[Translation_Fusion_B.rtb_GPS_gain_tmp +
         6] * Translation_Fusion_P_g.C_Value_n[2] +
         (Translation_Fusion_B.Product_i[Translation_Fusion_B.rtb_GPS_gain_tmp +
          3] * Translation_Fusion_P_g.C_Value_n[1] +
          Translation_Fusion_B.Product_i[Translation_Fusion_B.rtb_GPS_gain_tmp] *
          Translation_Fusion_P_g.C_Value_n[0]));
    }

    Translation_Fusion_B.Sum_ol = 1.0F / (Translation_Fusion_B.Sqrt +
      Translation_Fusion_B.GPS_gain);
    for (Translation_Fusion_B.rtb_GPS_gain_tmp = 0;
         Translation_Fusion_B.rtb_GPS_gain_tmp < 3;
         Translation_Fusion_B.rtb_GPS_gain_tmp++) {
      Translation_Fusion_B.Abs1 =
        Translation_Fusion_B.Product_i[Translation_Fusion_B.rtb_GPS_gain_tmp + 6]
        * (Translation_Fusion_P_g.C_Value_n[2] * Translation_Fusion_B.Sum_ol) +
        (Translation_Fusion_B.Product_i[Translation_Fusion_B.rtb_GPS_gain_tmp +
         3] * (Translation_Fusion_P_g.C_Value_n[1] * Translation_Fusion_B.Sum_ol)
         + Translation_Fusion_P_g.C_Value_n[0] * Translation_Fusion_B.Sum_ol *
         Translation_Fusion_B.Product_i[Translation_Fusion_B.rtb_GPS_gain_tmp]);
      Translation_Fusion_B.Subtract_ia[Translation_Fusion_B.rtb_GPS_gain_tmp] =
        Translation_Fusion_B.IdentityMatrix_m[Translation_Fusion_B.rtb_GPS_gain_tmp]
        - Translation_Fusion_B.Abs1 * Translation_Fusion_P_g.C_Value_n[0];
      Translation_Fusion_B.Subtract_ia[Translation_Fusion_B.rtb_GPS_gain_tmp + 3]
        =
        Translation_Fusion_B.IdentityMatrix_m[Translation_Fusion_B.rtb_GPS_gain_tmp
        + 3] - Translation_Fusion_B.Abs1 * Translation_Fusion_P_g.C_Value_n[1];
      Translation_Fusion_B.Subtract_ia[Translation_Fusion_B.rtb_GPS_gain_tmp + 6]
        =
        Translation_Fusion_B.IdentityMatrix_m[Translation_Fusion_B.rtb_GPS_gain_tmp
        + 6] - Translation_Fusion_B.Abs1 * Translation_Fusion_P_g.C_Value_n[2];
      Translation_Fusion_B.MatrixMultiply4_a[Translation_Fusion_B.rtb_GPS_gain_tmp]
        = Translation_Fusion_B.Abs1;
    }

    for (Translation_Fusion_B.rtb_GPS_gain_tmp = 0;
         Translation_Fusion_B.rtb_GPS_gain_tmp < 3;
         Translation_Fusion_B.rtb_GPS_gain_tmp++) {
      for (Translation_Fusion_B.i = 0; Translation_Fusion_B.i < 3;
           Translation_Fusion_B.i++) {
        Translation_Fusion_B.DataTypeConversion_ew =
          Translation_Fusion_B.rtb_GPS_gain_tmp + 3 * Translation_Fusion_B.i;
        Translation_Fusion_B.rtb_Product_i_b[Translation_Fusion_B.DataTypeConversion_ew]
          = 0.0F;
        Translation_Fusion_B.DataTypeConversion_bx = 3 * Translation_Fusion_B.i
          + Translation_Fusion_B.rtb_GPS_gain_tmp;
        Translation_Fusion_B.rtb_Product_i_b[Translation_Fusion_B.DataTypeConversion_ew]
          =
          Translation_Fusion_B.rtb_Product_i_b[Translation_Fusion_B.DataTypeConversion_bx]
          + Translation_Fusion_B.Product_i[Translation_Fusion_B.rtb_GPS_gain_tmp]
          * Translation_Fusion_B.Subtract_ia[Translation_Fusion_B.i];
        Translation_Fusion_B.rtb_Product_i_b[Translation_Fusion_B.DataTypeConversion_ew]
          =
          Translation_Fusion_B.rtb_Product_i_b[Translation_Fusion_B.DataTypeConversion_bx]
          + Translation_Fusion_B.Product_i[Translation_Fusion_B.rtb_GPS_gain_tmp
          + 3] * Translation_Fusion_B.Subtract_ia[Translation_Fusion_B.i + 3];
        Translation_Fusion_B.rtb_Product_i_b[Translation_Fusion_B.DataTypeConversion_ew]
          =
          Translation_Fusion_B.rtb_Product_i_b[Translation_Fusion_B.DataTypeConversion_bx]
          + Translation_Fusion_B.Product_i[Translation_Fusion_B.rtb_GPS_gain_tmp
          + 6] * Translation_Fusion_B.Subtract_ia[Translation_Fusion_B.i + 6];
      }
    }

    for (Translation_Fusion_B.rtb_GPS_gain_tmp = 0;
         Translation_Fusion_B.rtb_GPS_gain_tmp < 3;
         Translation_Fusion_B.rtb_GPS_gain_tmp++) {
      for (Translation_Fusion_B.i = 0; Translation_Fusion_B.i < 3;
           Translation_Fusion_B.i++) {
        Translation_Fusion_B.v1_tmp = Translation_Fusion_B.rtb_GPS_gain_tmp + 3 *
          Translation_Fusion_B.i;
        Translation_Fusion_B.MatrixMultiply4_n[Translation_Fusion_B.v1_tmp] =
          0.0F;
        Translation_Fusion_B.DataTypeConversion_ew = 3 * Translation_Fusion_B.i
          + Translation_Fusion_B.rtb_GPS_gain_tmp;
        Translation_Fusion_B.MatrixMultiply4_n[Translation_Fusion_B.v1_tmp] =
          Translation_Fusion_B.MatrixMultiply4_n[Translation_Fusion_B.DataTypeConversion_ew]
          + Translation_Fusion_B.rtb_Product_i_b[3 * Translation_Fusion_B.i] *
          Translation_Fusion_B.Subtract_ia[Translation_Fusion_B.rtb_GPS_gain_tmp];
        Translation_Fusion_B.MatrixMultiply4_n[Translation_Fusion_B.v1_tmp] =
          Translation_Fusion_B.rtb_Product_i_b[3 * Translation_Fusion_B.i + 1] *
          Translation_Fusion_B.Subtract_ia[Translation_Fusion_B.rtb_GPS_gain_tmp
          + 3] +
          Translation_Fusion_B.MatrixMultiply4_n[Translation_Fusion_B.DataTypeConversion_ew];
        Translation_Fusion_B.MatrixMultiply4_n[Translation_Fusion_B.v1_tmp] =
          Translation_Fusion_B.rtb_Product_i_b[3 * Translation_Fusion_B.i + 2] *
          Translation_Fusion_B.Subtract_ia[Translation_Fusion_B.rtb_GPS_gain_tmp
          + 6] +
          Translation_Fusion_B.MatrixMultiply4_n[Translation_Fusion_B.DataTypeConversion_ew];
        Translation_Fusion_B.rtb_TmpSignalConversionAtMult_p[Translation_Fusion_B.v1_tmp]
          = Translation_Fusion_B.GPS_gain *
          Translation_Fusion_B.MatrixMultiply4_a[Translation_Fusion_B.i] *
          Translation_Fusion_B.MatrixMultiply4_a[Translation_Fusion_B.rtb_GPS_gain_tmp];
      }
    }

    for (Translation_Fusion_B.rtb_GPS_gain_tmp = 0;
         Translation_Fusion_B.rtb_GPS_gain_tmp < 9;
         Translation_Fusion_B.rtb_GPS_gain_tmp++) {
      Translation_Fusion_B.Add_d[Translation_Fusion_B.rtb_GPS_gain_tmp] =
        Translation_Fusion_B.MatrixMultiply4_n[Translation_Fusion_B.rtb_GPS_gain_tmp]
        + Translation_Fusion_B.rtb_TmpSignalConversionAtMult_p[Translation_Fusion_B.rtb_GPS_gain_tmp];
    }

    Translation_Fusion_B.Add_o[0] = Translation_Fusion_B.MatrixMultiply4_a[0] *
      Translation_Fusion_B.Inverse_j + Translation_Fusion_B.Switch2_pu[0];
    Translation_Fusion_B.Add_o[1] = Translation_Fusion_B.MatrixMultiply4_a[1] *
      Translation_Fusion_B.Inverse_j + Translation_Fusion_B.Switch2_pu[1];
    Translation_Fusion_B.Add_o[2] = Translation_Fusion_B.MatrixMultiply4_a[2] *
      Translation_Fusion_B.Inverse_j + Translation_Fusion_B.Switch2_pu[2];
    Translation_Fusion_DW.Delay_DSTATE_i =
      Translation_Fusion_B.DiscreteTimeIntegrator_bj;
    Translation_Fusion_DW.Delay1_DSTATE_hr = Translation_Fusion_B.Inverse_j;
    Translation_Fusion_B.Switch2_pu[0] = Translation_Fusion_B.Add_o[0];
    Translation_Fusion_B.Switch2_pu[1] = Translation_Fusion_B.Add_o[1];
  }

  Translation_Fusion_B.DiscreteTimeIntegrator_bj =
    Translation_Fusion_B.Switch2_pu[2];
  if (Translation_Fusion_B.En_sonar_Correct) {
    Translation_Fusion_B.DiscreteTimeIntegrator_bj = Translation_Fusion_B.Add_o
      [2];
  }

  for (Translation_Fusion_B.rtb_GPS_gain_tmp = 0;
       Translation_Fusion_B.rtb_GPS_gain_tmp < 9;
       Translation_Fusion_B.rtb_GPS_gain_tmp++) {
    Translation_Fusion_B.GPS_gain =
      Translation_Fusion_B.Product_i[Translation_Fusion_B.rtb_GPS_gain_tmp];
    if (Translation_Fusion_B.En_sonar_Correct) {
      Translation_Fusion_B.GPS_gain =
        Translation_Fusion_B.Add_d[Translation_Fusion_B.rtb_GPS_gain_tmp];
    }

    Translation_Fusion_B.Product_i[Translation_Fusion_B.rtb_GPS_gain_tmp] =
      Translation_Fusion_B.GPS_gain;
  }

  Translation_Fusion_B.DiscreteTimeIntegrator1_at = (real32_T)fabs
    (Translation_Fusion_B.Switch2_pu[0] - Translation_Fusion_B.middle_thr);
  if (Translation_Fusion_DW.DiscreteTimeIntegrator1_IC_LOAD != 0) {
    Translation_Fusion_DW.DiscreteTimeIntegrator1_DSTAT_n = (real32_T)
      (Translation_Fusion_B.DiscreteTimeIntegrator1_at <=
       Translation_Fusion_P_g.CompareToConstant2_const_c);
  }

  Translation_Fusion_B.Compare_ko = !Translation_Fusion_B.Compare_i;
  Translation_Fusion_B.FixPtRelationalOperator_g =
    !Translation_Fusion_B.Compare_ko;
  if (Translation_Fusion_B.FixPtRelationalOperator_g ||
      (Translation_Fusion_DW.DiscreteTimeIntegrator_PrevR_is != 0)) {
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE_l =
      Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_io;
  }

  if (Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE_l >=
      Translation_Fusion_P_g.DiscreteTimeIntegrator_UpperS_b) {
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE_l =
      Translation_Fusion_P_g.DiscreteTimeIntegrator_UpperS_b;
  } else {
    if (Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE_l <=
        Translation_Fusion_P_g.DiscreteTimeIntegrator_LowerS_a) {
      Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE_l =
        Translation_Fusion_P_g.DiscreteTimeIntegrator_LowerS_a;
    }
  }

  Translation_Fusion_B.Compare_bo =
    (Translation_Fusion_DW.Memory_PreviousInput_o3 >=
     Translation_Fusion_P_g.Constant_Value_hc);
  Translation_Fusion_B.LogicalOperator2_hv =
    ((Translation_Fusion_DW.DiscreteTimeIntegrator1_DSTAT_n >=
      Translation_Fusion_P_g.CompareToConstant3_const_h) &&
     (Translation_Fusion_DW.Delay_DSTATE_f != 0.0F) &&
     ((Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE_l >
       Translation_Fusion_P_g.Validafteraperiod_T_p_a) &&
      (*rtu_Sensor_baro_valid) && Translation_Fusion_B.Compare_bo));
  if (Translation_Fusion_B.LogicalOperator2_hv) {
    Translation_Fusion_B.middle_thr = Translation_Fusion_B.Sum_d -
      ((Translation_Fusion_P_g.C_Value_j[0] * Translation_Fusion_B.Switch2_pu[0]
        + Translation_Fusion_P_g.C_Value_j[1] * Translation_Fusion_B.Switch2_pu
        [1]) + Translation_Fusion_P_g.C_Value_j[2] *
       Translation_Fusion_B.DiscreteTimeIntegrator_bj);
    Translation_Fusion_B.Inverse_j = (Translation_Fusion_B.middle_thr *
      Translation_Fusion_B.middle_thr + Translation_Fusion_DW.Delay_DSTATE_ks) -
      Translation_Fusion_DW.Delay1_DSTATE_ky[0] *
      Translation_Fusion_DW.Delay1_DSTATE_ky[0];
    Translation_Fusion_B.Abs1 = 1.0F / Translation_Fusion_P_g.R_Value_g;
    if (Translation_Fusion_B.Abs1 * Translation_Fusion_B.middle_thr *
        Translation_Fusion_B.middle_thr >
        Translation_Fusion_P_g.AdaptiveCorrection_kai_f) {
      Translation_Fusion_B.Sqrt = 0.0F;
      for (Translation_Fusion_B.rtb_GPS_gain_tmp = 0;
           Translation_Fusion_B.rtb_GPS_gain_tmp < 3;
           Translation_Fusion_B.rtb_GPS_gain_tmp++) {
        Translation_Fusion_B.Sqrt +=
          Translation_Fusion_P_g.C_Value_j[Translation_Fusion_B.rtb_GPS_gain_tmp]
          * (Translation_Fusion_B.Product_i[Translation_Fusion_B.rtb_GPS_gain_tmp
             + 6] * Translation_Fusion_P_g.C_Value_j[2] +
             (Translation_Fusion_B.Product_i[Translation_Fusion_B.rtb_GPS_gain_tmp
              + 3] * Translation_Fusion_P_g.C_Value_j[1] +
              Translation_Fusion_B.Product_i[Translation_Fusion_B.rtb_GPS_gain_tmp]
              * Translation_Fusion_P_g.C_Value_j[0]));
      }

      Translation_Fusion_B.Sum_ol = (Translation_Fusion_P_g.Gain_Gain_l *
        Translation_Fusion_B.Inverse_j - Translation_Fusion_B.Sqrt) *
        Translation_Fusion_B.Abs1;
      if ((!(Translation_Fusion_B.Sum_ol >
             Translation_Fusion_P_g.Constant_Value_cf)) && (!rtIsNaNF
           (Translation_Fusion_P_g.Constant_Value_cf))) {
        Translation_Fusion_B.Sum_ol = Translation_Fusion_P_g.Constant_Value_cf;
      }

      if ((!(Translation_Fusion_B.Sum_ol <
             Translation_Fusion_P_g.AdaptiveCorrection_max_eta_h)) && (!rtIsNaNF
           (Translation_Fusion_P_g.AdaptiveCorrection_max_eta_h))) {
        Translation_Fusion_B.Sum_ol =
          Translation_Fusion_P_g.AdaptiveCorrection_max_eta_h;
      }

      Translation_Fusion_B.GPS_gain = Translation_Fusion_B.Sum_ol *
        Translation_Fusion_P_g.R_Value_g;
    } else {
      Translation_Fusion_B.GPS_gain = Translation_Fusion_P_g.R_Value_g;
    }

    Translation_Fusion_B.Sqrt = 0.0F;
    for (Translation_Fusion_B.rtb_GPS_gain_tmp = 0;
         Translation_Fusion_B.rtb_GPS_gain_tmp < 3;
         Translation_Fusion_B.rtb_GPS_gain_tmp++) {
      Translation_Fusion_B.Sqrt +=
        Translation_Fusion_P_g.C_Value_j[Translation_Fusion_B.rtb_GPS_gain_tmp] *
        (Translation_Fusion_B.Product_i[Translation_Fusion_B.rtb_GPS_gain_tmp +
         6] * Translation_Fusion_P_g.C_Value_j[2] +
         (Translation_Fusion_B.Product_i[Translation_Fusion_B.rtb_GPS_gain_tmp +
          3] * Translation_Fusion_P_g.C_Value_j[1] +
          Translation_Fusion_B.Product_i[Translation_Fusion_B.rtb_GPS_gain_tmp] *
          Translation_Fusion_P_g.C_Value_j[0]));
    }

    Translation_Fusion_B.Sum_ol = 1.0F / (Translation_Fusion_B.Sqrt +
      Translation_Fusion_B.GPS_gain);
    for (Translation_Fusion_B.rtb_GPS_gain_tmp = 0;
         Translation_Fusion_B.rtb_GPS_gain_tmp < 3;
         Translation_Fusion_B.rtb_GPS_gain_tmp++) {
      Translation_Fusion_B.Abs1 =
        Translation_Fusion_B.Product_i[Translation_Fusion_B.rtb_GPS_gain_tmp + 6]
        * (Translation_Fusion_P_g.C_Value_j[2] * Translation_Fusion_B.Sum_ol) +
        (Translation_Fusion_B.Product_i[Translation_Fusion_B.rtb_GPS_gain_tmp +
         3] * (Translation_Fusion_P_g.C_Value_j[1] * Translation_Fusion_B.Sum_ol)
         + Translation_Fusion_P_g.C_Value_j[0] * Translation_Fusion_B.Sum_ol *
         Translation_Fusion_B.Product_i[Translation_Fusion_B.rtb_GPS_gain_tmp]);
      Translation_Fusion_B.Subtract_ia[Translation_Fusion_B.rtb_GPS_gain_tmp] =
        Translation_Fusion_B.IdentityMatrix_kr[Translation_Fusion_B.rtb_GPS_gain_tmp]
        - Translation_Fusion_B.Abs1 * Translation_Fusion_P_g.C_Value_j[0];
      Translation_Fusion_B.Subtract_ia[Translation_Fusion_B.rtb_GPS_gain_tmp + 3]
        =
        Translation_Fusion_B.IdentityMatrix_kr[Translation_Fusion_B.rtb_GPS_gain_tmp
        + 3] - Translation_Fusion_B.Abs1 * Translation_Fusion_P_g.C_Value_j[1];
      Translation_Fusion_B.Subtract_ia[Translation_Fusion_B.rtb_GPS_gain_tmp + 6]
        =
        Translation_Fusion_B.IdentityMatrix_kr[Translation_Fusion_B.rtb_GPS_gain_tmp
        + 6] - Translation_Fusion_B.Abs1 * Translation_Fusion_P_g.C_Value_j[2];
      Translation_Fusion_B.MatrixMultiply4_a[Translation_Fusion_B.rtb_GPS_gain_tmp]
        = Translation_Fusion_B.Abs1;
    }

    for (Translation_Fusion_B.rtb_GPS_gain_tmp = 0;
         Translation_Fusion_B.rtb_GPS_gain_tmp < 3;
         Translation_Fusion_B.rtb_GPS_gain_tmp++) {
      for (Translation_Fusion_B.i = 0; Translation_Fusion_B.i < 3;
           Translation_Fusion_B.i++) {
        Translation_Fusion_B.DataTypeConversion_ew =
          Translation_Fusion_B.rtb_GPS_gain_tmp + 3 * Translation_Fusion_B.i;
        Translation_Fusion_B.rtb_Product_i_b[Translation_Fusion_B.DataTypeConversion_ew]
          = 0.0F;
        Translation_Fusion_B.DataTypeConversion_bx = 3 * Translation_Fusion_B.i
          + Translation_Fusion_B.rtb_GPS_gain_tmp;
        Translation_Fusion_B.rtb_Product_i_b[Translation_Fusion_B.DataTypeConversion_ew]
          =
          Translation_Fusion_B.rtb_Product_i_b[Translation_Fusion_B.DataTypeConversion_bx]
          + Translation_Fusion_B.Product_i[Translation_Fusion_B.rtb_GPS_gain_tmp]
          * Translation_Fusion_B.Subtract_ia[Translation_Fusion_B.i];
        Translation_Fusion_B.rtb_Product_i_b[Translation_Fusion_B.DataTypeConversion_ew]
          =
          Translation_Fusion_B.rtb_Product_i_b[Translation_Fusion_B.DataTypeConversion_bx]
          + Translation_Fusion_B.Product_i[Translation_Fusion_B.rtb_GPS_gain_tmp
          + 3] * Translation_Fusion_B.Subtract_ia[Translation_Fusion_B.i + 3];
        Translation_Fusion_B.rtb_Product_i_b[Translation_Fusion_B.DataTypeConversion_ew]
          =
          Translation_Fusion_B.rtb_Product_i_b[Translation_Fusion_B.DataTypeConversion_bx]
          + Translation_Fusion_B.Product_i[Translation_Fusion_B.rtb_GPS_gain_tmp
          + 6] * Translation_Fusion_B.Subtract_ia[Translation_Fusion_B.i + 6];
      }
    }

    for (Translation_Fusion_B.rtb_GPS_gain_tmp = 0;
         Translation_Fusion_B.rtb_GPS_gain_tmp < 3;
         Translation_Fusion_B.rtb_GPS_gain_tmp++) {
      for (Translation_Fusion_B.i = 0; Translation_Fusion_B.i < 3;
           Translation_Fusion_B.i++) {
        Translation_Fusion_B.v1_tmp = Translation_Fusion_B.rtb_GPS_gain_tmp + 3 *
          Translation_Fusion_B.i;
        Translation_Fusion_B.MatrixMultiply4_n[Translation_Fusion_B.v1_tmp] =
          0.0F;
        Translation_Fusion_B.DataTypeConversion_ew = 3 * Translation_Fusion_B.i
          + Translation_Fusion_B.rtb_GPS_gain_tmp;
        Translation_Fusion_B.MatrixMultiply4_n[Translation_Fusion_B.v1_tmp] =
          Translation_Fusion_B.MatrixMultiply4_n[Translation_Fusion_B.DataTypeConversion_ew]
          + Translation_Fusion_B.rtb_Product_i_b[3 * Translation_Fusion_B.i] *
          Translation_Fusion_B.Subtract_ia[Translation_Fusion_B.rtb_GPS_gain_tmp];
        Translation_Fusion_B.MatrixMultiply4_n[Translation_Fusion_B.v1_tmp] =
          Translation_Fusion_B.rtb_Product_i_b[3 * Translation_Fusion_B.i + 1] *
          Translation_Fusion_B.Subtract_ia[Translation_Fusion_B.rtb_GPS_gain_tmp
          + 3] +
          Translation_Fusion_B.MatrixMultiply4_n[Translation_Fusion_B.DataTypeConversion_ew];
        Translation_Fusion_B.MatrixMultiply4_n[Translation_Fusion_B.v1_tmp] =
          Translation_Fusion_B.rtb_Product_i_b[3 * Translation_Fusion_B.i + 2] *
          Translation_Fusion_B.Subtract_ia[Translation_Fusion_B.rtb_GPS_gain_tmp
          + 6] +
          Translation_Fusion_B.MatrixMultiply4_n[Translation_Fusion_B.DataTypeConversion_ew];
        Translation_Fusion_B.rtb_TmpSignalConversionAtMult_p[Translation_Fusion_B.v1_tmp]
          = Translation_Fusion_B.GPS_gain *
          Translation_Fusion_B.MatrixMultiply4_a[Translation_Fusion_B.i] *
          Translation_Fusion_B.MatrixMultiply4_a[Translation_Fusion_B.rtb_GPS_gain_tmp];
      }
    }

    for (Translation_Fusion_B.rtb_GPS_gain_tmp = 0;
         Translation_Fusion_B.rtb_GPS_gain_tmp < 9;
         Translation_Fusion_B.rtb_GPS_gain_tmp++) {
      Translation_Fusion_B.Add_pa[Translation_Fusion_B.rtb_GPS_gain_tmp] =
        Translation_Fusion_B.MatrixMultiply4_n[Translation_Fusion_B.rtb_GPS_gain_tmp]
        + Translation_Fusion_B.rtb_TmpSignalConversionAtMult_p[Translation_Fusion_B.rtb_GPS_gain_tmp];
    }

    Translation_Fusion_B.Add_pl[0] = Translation_Fusion_B.MatrixMultiply4_a[0] *
      Translation_Fusion_B.middle_thr + Translation_Fusion_B.Switch2_pu[0];
    Translation_Fusion_B.Add_pl[1] = Translation_Fusion_B.MatrixMultiply4_a[1] *
      Translation_Fusion_B.middle_thr + Translation_Fusion_B.Switch2_pu[1];
    Translation_Fusion_B.Add_pl[2] = Translation_Fusion_B.MatrixMultiply4_a[2] *
      Translation_Fusion_B.middle_thr +
      Translation_Fusion_B.DiscreteTimeIntegrator_bj;
    Translation_Fusion_DW.Delay_DSTATE_ks = Translation_Fusion_B.Inverse_j;
    Translation_Fusion_DW.Delay1_DSTATE_ky[0] =
      Translation_Fusion_DW.Delay1_DSTATE_ky[1];
    Translation_Fusion_DW.Delay1_DSTATE_ky[1] =
      Translation_Fusion_DW.Delay1_DSTATE_ky[2];
    Translation_Fusion_DW.Delay1_DSTATE_ky[2] =
      Translation_Fusion_DW.Delay1_DSTATE_ky[3];
    Translation_Fusion_DW.Delay1_DSTATE_ky[3] =
      Translation_Fusion_DW.Delay1_DSTATE_ky[4];
    Translation_Fusion_DW.Delay1_DSTATE_ky[4] = Translation_Fusion_B.middle_thr;
    Translation_Fusion_B.MatrixMultiply4_a[0] = Translation_Fusion_B.Add_pl[0];
    Translation_Fusion_B.MatrixMultiply4_a[1] = Translation_Fusion_B.Add_pl[1];
    Translation_Fusion_B.MatrixMultiply4_a[2] = Translation_Fusion_B.Add_pl[2];
  } else {
    Translation_Fusion_B.MatrixMultiply4_a[0] = Translation_Fusion_B.Switch2_pu
      [0];
    Translation_Fusion_B.MatrixMultiply4_a[1] = Translation_Fusion_B.Switch2_pu
      [1];
    Translation_Fusion_B.MatrixMultiply4_a[2] =
      Translation_Fusion_B.DiscreteTimeIntegrator_bj;
  }

  *rty_Translation_data_h_AGL_m = Translation_Fusion_P_g.Gain2_Gain_p *
    Translation_Fusion_B.MatrixMultiply4_a[0];
  Translation_Fusion_B.Sum_ol = Translation_Fusion_P_g.Gain1_Gain_fj *
    Translation_Fusion_DW.DiscreteTimeIntegrator1_DSTA_hw;
  if (Translation_Fusion_B.Sum_ol > Translation_Fusion_P_g.Saturation_UpperSat_d)
  {
    Translation_Fusion_B.Sum_ol = Translation_Fusion_P_g.Saturation_UpperSat_d;
  } else {
    if (Translation_Fusion_B.Sum_ol <
        Translation_Fusion_P_g.Saturation_LowerSat_h) {
      Translation_Fusion_B.Sum_ol = Translation_Fusion_P_g.Saturation_LowerSat_h;
    }
  }

  Translation_Fusion_B.Sum_ol = (real32_T)fabs(Translation_Fusion_B.Sum_ol) *
    Translation_Fusion_DW.DiscreteTimeIntegrator1_DSTA_hw;
  if (Translation_Fusion_B.Sum_ol >
      Translation_Fusion_P_g.Saturation2_UpperSat_d) {
    Translation_Fusion_B.Sum_ol = Translation_Fusion_P_g.Saturation2_UpperSat_d;
  } else {
    if (Translation_Fusion_B.Sum_ol <
        Translation_Fusion_P_g.Saturation2_LowerSat_m) {
      Translation_Fusion_B.Sum_ol =
        Translation_Fusion_P_g.Saturation2_LowerSat_m;
    }
  }

  Translation_Fusion_B.middle_thr = Translation_Fusion_B.Sum_ol +
    Translation_Fusion_B.MatrixMultiply4_a[1];
  *rty_Translation_data_h_dot_mDs = Translation_Fusion_P_g.Gain3_Gain_l *
    Translation_Fusion_B.middle_thr;
  *rty_Translation_data_delta_h_m = Translation_Fusion_P_g.Gain4_Gain_d *
    Translation_Fusion_B.Relay1;
  *rty_Translation_data_Bias_z_mDs = (Translation_Fusion_B.MatrixMultiply4_a[2]
    + Translation_Fusion_B.MovingAverage2_p.MovingAverage2) *
    Translation_Fusion_P_g.Gain5_Gain;
  Translation_Fusion_B.Relay1 =
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_lb;
  Translation_Fusion_B.Inverse_j = Translation_Fusion_P_g.Gain1_Gain_oo *
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_lb;
  Translation_Fusion_B.En_sonar_Correct = (rtb_Reset_TF_tmp ||
    (!Translation_Fusion_B.Compare_j));
  if (Translation_Fusion_B.En_sonar_Correct ||
      (Translation_Fusion_DW.DiscreteTimeIntegrator1_PrevRes != 0)) {
    Translation_Fusion_DW.DiscreteTimeIntegrator1_DSTAT_b =
      Translation_Fusion_P_g.DiscreteTimeIntegrator1_IC_nx;
  }

  Translation_Fusion_B.Abs1 =
    (Translation_Fusion_DW.DiscreteTimeIntegrator1_DSTAT_b -
     Translation_Fusion_DW.DiscreteTimeIntegrator1_DSTA_hw) *
    Translation_Fusion_P_g.Gain_Gain_iv;
  if (Translation_Fusion_DW.DiscreteTimeIntegrator_IC_LO_fn != 0) {
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE_d =
      Translation_Fusion_B.MatrixMultiply4_a[0];
  }

  if (Translation_Fusion_B.En_sonar_Correct ||
      (Translation_Fusion_DW.DiscreteTimeIntegrator_PrevR_iz != 0)) {
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE_d =
      Translation_Fusion_B.MatrixMultiply4_a[0];
  }

  Translation_Fusion_B.GPS_gain = Translation_Fusion_B.MatrixMultiply4_a[0] -
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE_d;
  Translation_Fusion_B.DiscreteTimeIntegrator_bj =
    (Translation_Fusion_P_g.Gain_Gain_b * Translation_Fusion_B.GPS_gain +
     Translation_Fusion_B.MatrixMultiply4_a[1]) +
    Translation_Fusion_DW.DiscreteTimeIntegrator1_DSTAT_b;
  Translation_Fusion_B.Abs2 = Translation_Fusion_P_g.Gain1_Gain_ot *
    Translation_Fusion_B.GPS_gain;
  if (*rtu_Armed) {
    Translation_Fusion_B.Inverse_h = (Translation_Fusion_P_g.Constant_Value_mlz
      - Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_pn) *
      Translation_Fusion_P_g.Gain1_Gain;
    if (Translation_Fusion_B.Inverse_h >
        Translation_Fusion_P_g.Saturation_UpperSat_kb) {
      Translation_Fusion_B.Inverse_h =
        Translation_Fusion_P_g.Saturation_UpperSat_kb;
    } else {
      if (Translation_Fusion_B.Inverse_h <
          Translation_Fusion_P_g.Saturation_LowerSat_l) {
        Translation_Fusion_B.Inverse_h =
          Translation_Fusion_P_g.Saturation_LowerSat_l;
      }
    }
  } else {
    Translation_Fusion_B.Inverse_h = (Translation_Fusion_P_g.Constant_Value_mlz
      - Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_pn) *
      Translation_Fusion_P_g.Gain2_Gain;
  }

  Translation_Fusion_B.DiscreteTimeIntegrator_j =
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_pa;
  Translation_Fusion_B.Gain1_p = Translation_Fusion_P_g.Gain1_Gain_i3 *
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_pa;
  Translation_Fusion_B.Sum_d = (Translation_Fusion_B.Sum_d -
    Translation_Fusion_DW.DiscreteTimeIntegrator1_DSTA_fe) *
    Translation_Fusion_P_g.Gain_Gain_ml;
  Translation_Fusion_B.DiscreteTimeIntegrator_b =
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_a0;
  Translation_Fusion_B.Gain1_i = Translation_Fusion_P_g.Gain1_Gain_nb *
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_a0;
  Translation_Fusion_B.Gain_av = (Translation_Fusion_B.Switch2_pu[0] -
    Translation_Fusion_DW.DiscreteTimeIntegrator1_DSTAT_g) *
    Translation_Fusion_P_g.Gain_Gain_pe;
  for (Translation_Fusion_B.rtb_GPS_gain_tmp = 0;
       Translation_Fusion_B.rtb_GPS_gain_tmp < 9;
       Translation_Fusion_B.rtb_GPS_gain_tmp++) {
    Translation_Fusion_B.GPS_gain =
      Translation_Fusion_B.Product_i[Translation_Fusion_B.rtb_GPS_gain_tmp];
    if (Translation_Fusion_B.LogicalOperator2_hv) {
      Translation_Fusion_B.GPS_gain =
        Translation_Fusion_B.Add_pa[Translation_Fusion_B.rtb_GPS_gain_tmp];
    }

    Translation_Fusion_B.Product_i[Translation_Fusion_B.rtb_GPS_gain_tmp] =
      Translation_Fusion_B.GPS_gain;
  }

  Translation_Fusion_B.LogicalOperator2_hv = ((real32_T)fabs
    (Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_pa -
     Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_a0) <=
    Translation_Fusion_P_g.CompareToConstant_const_os);
  if (Translation_Fusion_DW.DiscreteTimeIntegrator1_IC_LO_n != 0) {
    Translation_Fusion_DW.DiscreteTimeIntegrator1_DSTAT_l =
      Translation_Fusion_B.LogicalOperator2_hv;
  }

  Translation_Fusion_B.GPS_gain = (real32_T)
    Translation_Fusion_B.LogicalOperator2_hv -
    Translation_Fusion_DW.DiscreteTimeIntegrator1_DSTAT_l;
  if (Translation_Fusion_B.GPS_gain > Translation_Fusion_P_g.Switch_Threshold) {
    Translation_Fusion_B.Sum_ol =
      Translation_Fusion_P_g.Ascendanddescendtracking_Tc_asc;
  } else {
    Translation_Fusion_B.Sum_ol =
      Translation_Fusion_P_g.Ascendanddescendtracking_Tc_des;
  }

  Translation_Fusion_B.Product_c = Translation_Fusion_B.GPS_gain /
    Translation_Fusion_B.Sum_ol;
  Translation_Fusion_B.GPS_gain = (real32_T)
    (Translation_Fusion_B.DiscreteTimeIntegrator1_at <=
     Translation_Fusion_P_g.CompareToConstant2_const_c) -
    Translation_Fusion_DW.DiscreteTimeIntegrator1_DSTAT_n;
  if (Translation_Fusion_B.GPS_gain > Translation_Fusion_P_g.Switch_Threshold_b)
  {
    Translation_Fusion_B.Sum_ol =
      Translation_Fusion_P_g.Ascendanddescendtracking2_Tc_as;
  } else {
    Translation_Fusion_B.Sum_ol =
      Translation_Fusion_P_g.Ascendanddescendtracking2_Tc_de;
  }

  Translation_Fusion_B.DiscreteTimeIntegrator1_at =
    Translation_Fusion_B.GPS_gain / Translation_Fusion_B.Sum_ol;
  if (Translation_Fusion_B.Compare_j) {
    Translation_Fusion_B.baro_error_small = Translation_Fusion_P_g.R1_Value;
  } else {
    Translation_Fusion_B.baro_error_small = (real32_T)
      (Translation_Fusion_DW.DiscreteTimeIntegrator1_DSTAT_l >=
       Translation_Fusion_P_g.CompareToConstant1_const_k);
  }

  Translation_Fusion_B.rtb_Transpose_h_idx_0 =
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTA_gt3[0];
  Translation_Fusion_B.rtb_Gain1_o_idx_0 = Translation_Fusion_P_g.Gain1_Gain_nn *
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTA_gt3[0];
  Translation_Fusion_B.rtb_Gain_c_idx_0 = (Translation_Fusion_B.rtb_Int_X_idx_0
    - Translation_Fusion_DW.DiscreteTimeIntegrator1_DSTAT_f[0]) *
    Translation_Fusion_P_g.Gain_Gain_gj;
  Translation_Fusion_B.rtb_Transpose_h_idx_1 =
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTA_gt3[1];
  Translation_Fusion_B.rtb_Gain1_o_idx_1 = Translation_Fusion_P_g.Gain1_Gain_nn *
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTA_gt3[1];
  Translation_Fusion_B.rtb_Gain_c_idx_1 = (Translation_Fusion_B.rtb_Int_X_idx_1
    - Translation_Fusion_DW.DiscreteTimeIntegrator1_DSTAT_f[1]) *
    Translation_Fusion_P_g.Gain_Gain_gj;
  if (Translation_Fusion_B.GPS_height_enable) {
    Translation_Fusion_B.GPS_gain = Translation_Fusion_P_g.Gain3_Gain;
  } else {
    switch ((int32_T)Translation_Fusion_B.state) {
     case 1:
      Translation_Fusion_B.LogicalOperator2_hv =
        Translation_Fusion_P_g.Constant2_Value_e;
      break;

     case 2:
      Translation_Fusion_B.LogicalOperator2_hv =
        (Translation_Fusion_B.DiscreteTimeIntegrator1_f5h >=
         Translation_Fusion_P_g.CompareToConstant1_const_br);
      break;

     case 3:
      Translation_Fusion_B.LogicalOperator2_hv =
        Translation_Fusion_P_g.Constant2_Value_e;
      break;

     default:
      Translation_Fusion_B.LogicalOperator2_hv =
        (Translation_Fusion_B.DiscreteTimeIntegrator1_f5h >=
         Translation_Fusion_P_g.CompareToConstant1_const_br);
      break;
    }

    Translation_Fusion_B.GPS_gain = Translation_Fusion_P_g.Gain_Gain_pg *
      (real32_T)rtb_Reset_TF_tmp + Translation_Fusion_P_g.Gain4_Gain * (real32_T)
      Translation_Fusion_B.LogicalOperator2_hv;
  }

  if (Translation_Fusion_B.GPS_gain > Translation_Fusion_P_g.Switch_Threshold_d)
  {
    Translation_Fusion_B.DiscreteTimeIntegrator1_f5h =
      (Translation_Fusion_B.Switch1_k -
       Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_j3) *
      Translation_Fusion_B.GPS_gain;
  } else {
    Translation_Fusion_B.DiscreteTimeIntegrator1_f5h =
      Translation_Fusion_P_g.Gain_Gain_hf *
      Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_j3;
  }

  Translation_Fusion_B.Subtract1 = (Translation_Fusion_B.Subtract1 -
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_i1) *
    Translation_Fusion_P_g.Gain_Gain_a;
  Translation_Fusion_B.Subtract2 = (Translation_Fusion_B.Subtract2 -
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_cq) *
    Translation_Fusion_P_g.Gain_Gain_lh;
  Translation_Fusion_B.Subtract3 = (Translation_Fusion_B.Subtract3 -
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_eq) *
    Translation_Fusion_P_g.Gain_Gain_d0;
  Translation_Fusion_B.state = Translation_Fusion_B.LogicalOperator1_ks;
  Translation_Fusion_B.LogicalOperator_m = !rtb_Over_15m_tmp;
  if (Translation_Fusion_B.LogicalOperator_m ||
      (Translation_Fusion_DW.DiscreteTimeIntegrator_PrevR_hk != 0)) {
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_n4 =
      Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_h;
  }

  if (Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_n4 >=
      Translation_Fusion_P_g.DiscreteTimeIntegrator_Upper_lw) {
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_n4 =
      Translation_Fusion_P_g.DiscreteTimeIntegrator_Upper_lw;
  } else {
    if (Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_n4 <=
        Translation_Fusion_P_g.DiscreteTimeIntegrator_LowerS_p) {
      Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_n4 =
        Translation_Fusion_P_g.DiscreteTimeIntegrator_LowerS_p;
    }
  }

  Translation_Fusion_B.GPS_height_enable =
    (Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_n4 >
     Translation_Fusion_P_g.Validaperiod_T_p_ik);
  if (Translation_Fusion_DW.DiscreteTimeIntegrator_IC_LO_fw != 0) {
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_lc =
      Translation_Fusion_B.En_VO_Pz_Correct;
  }

  Translation_Fusion_B.Compare_jq =
    (Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_lc >=
     Translation_Fusion_P_g.CompareToConstant4_const_e);
  Translation_Fusion_B.FixPtRelationalOperator_oo = ((int32_T)
    Translation_Fusion_B.Compare_jq > (int32_T)
    Translation_Fusion_DW.DelayInput1_DSTATE_ey);
  Translation_Fusion_B.Switch4 = (Translation_Fusion_B.Switch4 -
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE_o) *
    Translation_Fusion_P_g.Gain_Gain_j;
  Translation_Fusion_B.Switch1_k = (*rtu_Rotation_Psi_dot_fused -
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_oe) *
    Translation_Fusion_P_g.Gain_Gain_a2;
  Translation_Fusion_B.Gain_by = ((real32_T)
    Translation_Fusion_B.En_VO_Pz_Correct -
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_lc) *
    Translation_Fusion_P_g.Gain_Gain_n5;
  if (Translation_Fusion_B.Compare_bo &&
      (Translation_Fusion_PrevZCX.Delay1_Reset_ZCE != POS_ZCSIG)) {
    Translation_Fusion_DW.Delay1_DSTATE_k1 =
      Translation_Fusion_P_g.Delay1_InitialCondition_oq;
  }

  Translation_Fusion_PrevZCX.Delay1_Reset_ZCE = Translation_Fusion_B.Compare_bo;
  Translation_Fusion_B.Add1_p = (uint16_T)((uint32_T)((int32_T)
    Translation_Fusion_B.LogicalOperator2_f > (int32_T)
    Translation_Fusion_DW.DelayInput1_DSTATE_nj) +
    Translation_Fusion_DW.Delay1_DSTATE_k1);
  Translation_Fusion_B.En_VO_Pz_Correct = Translation_Fusion_DW.Delay_DSTATE_pu;
  Translation_Fusion_B.DiscreteTimeIntegrator5_h1 =
    Translation_Fusion_DW.DiscreteTimeIntegrator5_DSTAT_g;
  Translation_Fusion_B.Gain2 = (Translation_Fusion_B.MatrixMultiply4_a[0] -
    Translation_Fusion_B.DiscreteTimeIntegrator5_h1) *
    Translation_Fusion_P_g.Gain2_Gain_n;
  Translation_Fusion_B.Gain2_l = (Translation_Fusion_B.Gain2 -
    Translation_Fusion_B.DiscreteTimeIntegrator5_h) *
    Translation_Fusion_P_g.Gain2_Gain_m;
  Translation_Fusion_B.Compare_bo = (rtb_Over_15m_tmp && ((int32_T)
    Translation_Fusion_DW.Delay_DSTATE_pu > (int32_T)
    Translation_Fusion_DW.DelayInput1_DSTATE_d));
  if (Translation_Fusion_B.Compare_bo ||
      (Translation_Fusion_DW.DiscreteTimeIntegrator5_PrevRes != 0)) {
    Translation_Fusion_DW.DiscreteTimeIntegrator5_DSTAT_j =
      Translation_Fusion_P_g.DiscreteTimeIntegrator5_IC_l3;
  }

  Translation_Fusion_B.DiscreteTimeIntegrator5_i =
    Translation_Fusion_DW.DiscreteTimeIntegrator5_DSTAT_j;
  Translation_Fusion_B.Gain2_f = (*rtu_Sensor_Sonar_data_h_grd_son -
    Translation_Fusion_B.DiscreteTimeIntegrator5_i) *
    Translation_Fusion_P_g.Gain2_Gain_a;
  Translation_Fusion_B.Gain2_ll = (Translation_Fusion_B.Gain2_f -
    Translation_Fusion_B.DiscreteTimeIntegrator5) *
    Translation_Fusion_P_g.Gain2_Gain_ai;
  Translation_Fusion_B.DataTypeConversion_ly =
    Translation_Fusion_B.GPS_Vel_Vaild;
  Translation_Fusion_B.DataTypeConversion_ew = Translation_Fusion_B.Compare_ko;
  Translation_Fusion_B.DiscreteTimeIntegrator_km =
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE_b;
  Translation_Fusion_B.Gain1_l = Translation_Fusion_P_g.Gain1_Gain_b *
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE_b;
  Translation_Fusion_B.Gain_gh = (*rtu_Rotation_Psi_dot_IMU -
    Translation_Fusion_DW.DiscreteTimeIntegrator1_DSTAT_d) *
    Translation_Fusion_P_g.Gain_Gain_e;
  Translation_Fusion_B.Compare_mr = ((real32_T)fabs
    (Translation_Fusion_DW.DiscreteTimeIntegrator1_DSTAT_d) >
    Translation_Fusion_P_g.CompareToConstant4_const_a);
  Translation_Fusion_B.DiscreteTimeIntegrator_gf =
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_ak;
  Translation_Fusion_B.Gain1_lg = Translation_Fusion_P_g.Gain1_Gain_l *
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_ak;
  Translation_Fusion_B.Gain_nx =
    (Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_ce -
     Translation_Fusion_DW.DiscreteTimeIntegrator1_DSTAT_k) *
    Translation_Fusion_P_g.Gain_Gain_ej;
  Translation_Fusion_B.DiscreteTimeIntegrator_j1 =
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_ct;
  Translation_Fusion_B.Gain1_g = Translation_Fusion_P_g.Gain1_Gain_k *
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_ct;
  Translation_Fusion_B.Gain_ce =
    (Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_bn -
     Translation_Fusion_DW.DiscreteTimeIntegrator1_DSTAT_a) *
    Translation_Fusion_P_g.Gain_Gain_b5;
  Translation_Fusion_B.GPS_gain = *rtu_Rotation_Euler_Transforma_k -
    Translation_Fusion_DW.DiscreteTimeIntegrator1_DSTAT_c;
  Translation_Fusion_B.Add_kk = Translation_Fusion_P_g.Gain2_Gain_e *
    Translation_Fusion_B.GPS_gain +
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_ce;
  Translation_Fusion_B.Gain3 = Translation_Fusion_P_g.Gain3_Gain_f *
    Translation_Fusion_B.GPS_gain;
  Translation_Fusion_B.GPS_gain = *rtu_Rotation_Euler_Transforma_h -
    Translation_Fusion_DW.DiscreteTimeIntegrator1_DSTA_l2;
  Translation_Fusion_B.Add_ey = Translation_Fusion_P_g.Gain2_Gain_k *
    Translation_Fusion_B.GPS_gain +
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_bn;
  Translation_Fusion_B.Gain3_m = Translation_Fusion_P_g.Gain3_Gain_fx *
    Translation_Fusion_B.GPS_gain;
  Translation_Fusion_B.DiscreteTimeIntegrator_n =
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_jp;
  Translation_Fusion_B.Gain1_ol = Translation_Fusion_P_g.Gain1_Gain_dh *
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_jp;
  Translation_Fusion_B.Gain_nwa =
    (Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_eh -
     Translation_Fusion_DW.DiscreteTimeIntegrator1_DSTATE) *
    Translation_Fusion_P_g.Gain_Gain_pl;
  Translation_Fusion_B.GPS_gain = *rtu_Rotation_Euler_Transforma_k -
    Translation_Fusion_DW.DiscreteTimeIntegrator1_DSTA_hj;
  Translation_Fusion_B.Add_b = Translation_Fusion_P_g.Gain2_Gain_g *
    Translation_Fusion_B.GPS_gain +
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_eh;
  Translation_Fusion_B.Gain3_p = Translation_Fusion_P_g.Gain3_Gain_a *
    Translation_Fusion_B.GPS_gain;
  for (Translation_Fusion_B.rtb_GPS_gain_tmp = 0;
       Translation_Fusion_B.rtb_GPS_gain_tmp < 3;
       Translation_Fusion_B.rtb_GPS_gain_tmp++) {
    Translation_Fusion_B.Switch2_pu[Translation_Fusion_B.rtb_GPS_gain_tmp] =
      rtu_Rotation_M_OB[Translation_Fusion_B.rtb_GPS_gain_tmp + 6] *
      Translation_Fusion_P_g.R_GCAMERA_B_Value[2] +
      (rtu_Rotation_M_OB[Translation_Fusion_B.rtb_GPS_gain_tmp + 3] *
       Translation_Fusion_P_g.R_GCAMERA_B_Value[1] +
       rtu_Rotation_M_OB[Translation_Fusion_B.rtb_GPS_gain_tmp] *
       Translation_Fusion_P_g.R_GCAMERA_B_Value[0]);
  }

  if (Translation_Fusion_B.LogicalOperator_d) {
    Translation_Fusion_B.rtb_test1_k_idx_0 = Translation_Fusion_P_g.Gain2_Gain_l
      * Translation_Fusion_B.Switch2_pu[2];
  } else {
    Translation_Fusion_B.rtb_test1_k_idx_0 =
      Translation_Fusion_P_g.Constant_Value_l;
  }

  *rty_h_MSL = (real32_T)((Translation_Fusion_B.MatrixMultiply4_a[0] +
    Translation_Fusion_B.rtb_test1_k_idx_0) +
    Translation_Fusion_B.rtb_WGS84_pos_ref_idx_2);
  Translation_Fusion_B.DiscreteTimeIntegrator_or =
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_hp;
  Translation_Fusion_B.Gain1_e = Translation_Fusion_P_g.Gain1_Gain_fa *
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_hp;
  *rty_GPS_logic_log_Status =
    Translation_Fusion_DW.DiscreteTimeIntegrator1_DSTAT_m;
  Translation_Fusion_B.Gain_pi = (*rtu_Sensor_GPS_data_Status -
    *rty_GPS_logic_log_Status) * Translation_Fusion_P_g.Gain_Gain_ep;
  Translation_Fusion_B.DiscreteTimeIntegrator_n5 =
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_pd;
  Translation_Fusion_B.Gain1_lx = Translation_Fusion_P_g.Gain1_Gain_or *
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_pd;
  *rty_GPS_logic_log_Ts_Update =
    Translation_Fusion_DW.DiscreteTimeIntegrator1_DSTAT_p;
  Translation_Fusion_B.Gain_cl = ((real32_T)
    Translation_Fusion_B.FixPtRelationalOperator_p -
    *rty_GPS_logic_log_Ts_Update) * Translation_Fusion_P_g.Gain_Gain_nk;
  Translation_Fusion_B.DiscreteTimeIntegrator_a1 =
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_dc;
  Translation_Fusion_B.Gain1_av = Translation_Fusion_P_g.Gain1_Gain_j *
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_dc;
  Translation_Fusion_B.LogicalOperator1_ks = !Translation_Fusion_B.Over_15m;
  Translation_Fusion_B.FixPtRelationalOperator_p =
    !Translation_Fusion_B.LogicalOperator1_ks;
  if (Translation_Fusion_B.FixPtRelationalOperator_p ||
      (Translation_Fusion_DW.DiscreteTimeIntegrator_PrevR_ix != 0)) {
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_bo =
      Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_kt;
  }

  if (Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_bo >=
      Translation_Fusion_P_g.DiscreteTimeIntegrator_UpperS_h) {
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_bo =
      Translation_Fusion_P_g.DiscreteTimeIntegrator_UpperS_h;
  } else {
    if (Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_bo <=
        Translation_Fusion_P_g.DiscreteTimeIntegrator_LowerS_h) {
      Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_bo =
        Translation_Fusion_P_g.DiscreteTimeIntegrator_LowerS_h;
    }
  }

  Translation_Fusion_B.Compare_ko =
    !(Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_bo >
      Translation_Fusion_P_g.Validafteraperiod_T_p_ab);
  Translation_Fusion_B.LogicalOperator1_im = !Translation_Fusion_B.Compare_ko;
  if (Translation_Fusion_B.LogicalOperator1_im ||
      (Translation_Fusion_DW.DiscreteTimeIntegrator_PrevRe_e != 0)) {
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_ka =
      Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_ng;
  }

  if (Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_ka >=
      Translation_Fusion_P_g.DiscreteTimeIntegrator_UpperS_n) {
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_ka =
      Translation_Fusion_P_g.DiscreteTimeIntegrator_UpperS_n;
  } else {
    if (Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_ka <=
        Translation_Fusion_P_g.DiscreteTimeIntegrator_Lower_gy) {
      Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_ka =
        Translation_Fusion_P_g.DiscreteTimeIntegrator_Lower_gy;
    }
  }

  Translation_Fusion_B.GPS_Vel_Vaild =
    (Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_ka >
     Translation_Fusion_P_g.Validforaperiod1_T_p);
  *rty_GPS_logic_log_En_GPS_Valid =
    Translation_Fusion_DW.DiscreteTimeIntegrator1_DSTA_na;
  Translation_Fusion_B.Gain_l = ((real32_T)Translation_Fusion_B.GPS_Vel_Vaild - *
    rty_GPS_logic_log_En_GPS_Valid) * Translation_Fusion_P_g.Gain_Gain_bv;
  Translation_Fusion_B.DiscreteTimeIntegrator_c =
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_dv;
  Translation_Fusion_B.Gain1_at = Translation_Fusion_P_g.Gain1_Gain_d4 *
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_dv;
  *rty_GPS_logic_log_En_GPS_cor_co =
    Translation_Fusion_DW.DiscreteTimeIntegrator1_DSTA_hy;
  Translation_Fusion_B.Gain_lc = ((real32_T)Translation_Fusion_B.Switch1_ko -
    *rty_GPS_logic_log_En_GPS_cor_co) * Translation_Fusion_P_g.Gain_Gain_lc;
  Translation_Fusion_B.DiscreteTimeIntegrator_h =
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_n2;
  Translation_Fusion_B.Gain1_la = Translation_Fusion_P_g.Gain1_Gain_p *
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_n2;
  if (Translation_Fusion_B.Over_15m ||
      (Translation_Fusion_DW.DiscreteTimeIntegrator_PrevR_fm != 0)) {
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_jr =
      Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_eh;
  }

  Translation_Fusion_B.En_GPS_Correct_RTK = (Translation_Fusion_B.Over_15m &&
    ((Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_jr >=
      Translation_Fusion_P_g.CompareToConstant1_const_nv) ||
     (!Translation_Fusion_B.RTK_Vel_good)));
  *rty_GPS_logic_log_En_GPS_Correc =
    Translation_Fusion_DW.DiscreteTimeIntegrator1_DSTA_lz;
  Translation_Fusion_B.Gain_go = ((real32_T)
    Translation_Fusion_B.En_GPS_Correct_RTK - *rty_GPS_logic_log_En_GPS_Correc) *
    Translation_Fusion_P_g.Gain_Gain_eg;
  Translation_Fusion_B.Gain_b4 = (*rtu_Sensor_Vision_data_Vision_q -
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE_a) *
    Translation_Fusion_P_g.Gain_Gain_ax;
  Translation_Fusion_B.DataTypeConversion_bx =
    Translation_Fusion_B.LogicalOperator1_ks;
  Translation_Fusion_B.DataTypeConversion_i = Translation_Fusion_B.Compare_ko;
  Translation_Fusion_B.GPS_Vel_Vaild = (Translation_Fusion_B.GPS_Vel_Vaild &&
    Translation_Fusion_B.Switch1_ko);
  Translation_Fusion_B.Sum_ol = (Translation_Fusion_P_g.Constant_Value_po -
    *rtu_Sensor_GPS_data_Spd_quality) * Translation_Fusion_P_g.Gain_Gain_ky;
  if (Translation_Fusion_B.Sum_ol > Translation_Fusion_P_g.Saturation_UpperSat_j)
  {
    Translation_Fusion_B.Sum_ol = Translation_Fusion_P_g.Saturation_UpperSat_j;
  } else {
    if (Translation_Fusion_B.Sum_ol <
        Translation_Fusion_P_g.Saturation_LowerSat_ds) {
      Translation_Fusion_B.Sum_ol =
        Translation_Fusion_P_g.Saturation_LowerSat_ds;
    }
  }

  if ((*rtu_Rotation_reset_Yaw) ||
      (Translation_Fusion_DW.DiscreteTimeIntegrator_PrevR_au != 0)) {
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_ny =
      Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_oy;
  }

  Translation_Fusion_B.Switch1_ko = ((int32_T)((uint32_T)
    (Translation_Fusion_DW.Delay_DSTATE_kd &&
     (!(Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_ny >=
        Translation_Fusion_P_g.CompareTo1sec_const_pe))) +
    *rtu_Rotation_reset_Yaw) != 0);
  Translation_Fusion_B.CreateDiagonalMatrix[0] =
    Translation_Fusion_P_g.x0_Value_g[0];
  Translation_Fusion_B.CreateDiagonalMatrix[1] =
    Translation_Fusion_P_g.x0_Value_g[1];
  Translation_Fusion_B.CreateDiagonalMatrix[2] =
    Translation_Fusion_B.MovingAverage_pnae.MovingAverage2;
  Translation_Fusion_B.CreateDiagonalMatrix[3] =
    Translation_Fusion_B.MovingAverage1_pnae.MovingAverage2;
  if ((((Translation_Fusion_PrevZCX.Delay1_Reset_ZCE_i == POS_ZCSIG) != (int32_T)
        rtb_Reset_TF_tmp) && (Translation_Fusion_PrevZCX.Delay1_Reset_ZCE_i !=
        UNINITIALIZED_ZCSIG)) || rtb_Reset_TF_tmp) {
    Translation_Fusion_DW.Delay1_DSTATE_d[0] =
      Translation_Fusion_P_g.Delay1_InitialCondition_o[0];
    Translation_Fusion_DW.Delay1_DSTATE_d[1] =
      Translation_Fusion_P_g.Delay1_InitialCondition_o[1];
    Translation_Fusion_DW.Delay1_DSTATE_d[2] =
      Translation_Fusion_P_g.Delay1_InitialCondition_o[2];
    Translation_Fusion_DW.Delay1_DSTATE_d[3] =
      Translation_Fusion_P_g.Delay1_InitialCondition_o[3];
  }

  Translation_Fusion_PrevZCX.Delay1_Reset_ZCE_i = rtb_Reset_TF_tmp;
  memcpy(&Translation_Fusion_B.P_Kalman[0],
         &Translation_Fusion_P_g.Constant_Value_kx[0], 36U * sizeof(real32_T));
  Translation_Fusion_B.P_Kalman[0] = Translation_Fusion_DW.Delay1_DSTATE_d[0];
  Translation_Fusion_B.P_Kalman[1] = Translation_Fusion_DW.Delay1_DSTATE_d[1];
  Translation_Fusion_B.P_Kalman[6] = Translation_Fusion_DW.Delay1_DSTATE_d[2];
  Translation_Fusion_B.P_Kalman[7] = Translation_Fusion_DW.Delay1_DSTATE_d[3];
  if ((((Translation_Fusion_PrevZCX.Int_P_Reset_ZCE == POS_ZCSIG) != (int32_T)
        Translation_Fusion_B.Reset_TF) &&
       (Translation_Fusion_PrevZCX.Int_P_Reset_ZCE != UNINITIALIZED_ZCSIG)) ||
      Translation_Fusion_B.Reset_TF) {
    Translation_Fusion_DW.icLoad_f = 1U;
  }

  Translation_Fusion_PrevZCX.Int_P_Reset_ZCE = Translation_Fusion_B.Reset_TF;
  if (Translation_Fusion_DW.icLoad_f != 0) {
    memcpy(&Translation_Fusion_DW.Int_P_DSTATE[0],
           &Translation_Fusion_P_g.P0_Value[0], sizeof(real32_T) << 4U);
  }

  for (Translation_Fusion_B.rtb_GPS_gain_tmp = 0;
       Translation_Fusion_B.rtb_GPS_gain_tmp < 4;
       Translation_Fusion_B.rtb_GPS_gain_tmp++) {
    Translation_Fusion_B.v1_tmp = Translation_Fusion_B.rtb_GPS_gain_tmp << 2;
    Translation_Fusion_B.rtb_P_Kalman_tmp = 6 * (2 +
      Translation_Fusion_B.rtb_GPS_gain_tmp);
    Translation_Fusion_B.P_Kalman[2 + Translation_Fusion_B.rtb_P_Kalman_tmp] =
      Translation_Fusion_DW.Int_P_DSTATE[Translation_Fusion_B.v1_tmp];
    Translation_Fusion_B.P_Kalman[3 + Translation_Fusion_B.rtb_P_Kalman_tmp] =
      Translation_Fusion_DW.Int_P_DSTATE[Translation_Fusion_B.v1_tmp + 1];
    Translation_Fusion_B.P_Kalman[4 + Translation_Fusion_B.rtb_P_Kalman_tmp] =
      Translation_Fusion_DW.Int_P_DSTATE[Translation_Fusion_B.v1_tmp + 2];
    Translation_Fusion_B.P_Kalman[5 + Translation_Fusion_B.rtb_P_Kalman_tmp] =
      Translation_Fusion_DW.Int_P_DSTATE[Translation_Fusion_B.v1_tmp + 3];
  }

  Translation_Fusion_B.LogicalOperator1_ks = (*rtu_mode !=
    Translation_Fusion_P_g.CompareToConstant_const_as);
  for (Translation_Fusion_B.i = 0; Translation_Fusion_B.i < 9;
       Translation_Fusion_B.i++) {
    Translation_Fusion_B.MatrixMultiply4_n[Translation_Fusion_B.i] =
      Translation_Fusion_DW.Delay2_DSTATE_l[Translation_Fusion_B.i];
  }

  for (Translation_Fusion_B.rtb_GPS_gain_tmp = 0;
       Translation_Fusion_B.rtb_GPS_gain_tmp < 6;
       Translation_Fusion_B.rtb_GPS_gain_tmp++) {
    for (Translation_Fusion_B.i = 0; Translation_Fusion_B.i < 6;
         Translation_Fusion_B.i++) {
      Translation_Fusion_B.CreateDiagonalMatrix_j[Translation_Fusion_B.i + 6 *
        Translation_Fusion_B.rtb_GPS_gain_tmp] =
        Translation_Fusion_P_g.Ad_Value[6 * Translation_Fusion_B.i +
        Translation_Fusion_B.rtb_GPS_gain_tmp];
    }
  }

  for (Translation_Fusion_B.rtb_GPS_gain_tmp = 0;
       Translation_Fusion_B.rtb_GPS_gain_tmp < 6;
       Translation_Fusion_B.rtb_GPS_gain_tmp++) {
    for (Translation_Fusion_B.i = 0; Translation_Fusion_B.i < 6;
         Translation_Fusion_B.i++) {
      Translation_Fusion_B.v1_tmp = Translation_Fusion_B.i + 6 *
        Translation_Fusion_B.rtb_GPS_gain_tmp;
      Translation_Fusion_B.v1[Translation_Fusion_B.v1_tmp] = 0.0F;
      for (Translation_Fusion_B.rtb_P_Kalman_tmp = 0;
           Translation_Fusion_B.rtb_P_Kalman_tmp < 6;
           Translation_Fusion_B.rtb_P_Kalman_tmp++) {
        Translation_Fusion_B.v1[Translation_Fusion_B.v1_tmp] =
          Translation_Fusion_B.P_Kalman[6 *
          Translation_Fusion_B.rtb_P_Kalman_tmp + Translation_Fusion_B.i] *
          Translation_Fusion_B.CreateDiagonalMatrix_j[6 *
          Translation_Fusion_B.rtb_GPS_gain_tmp +
          Translation_Fusion_B.rtb_P_Kalman_tmp] + Translation_Fusion_B.v1[6 *
          Translation_Fusion_B.rtb_GPS_gain_tmp + Translation_Fusion_B.i];
      }
    }
  }

  Translation_Fusion_B.DiscreteTimeIntegrator1_p =
    Translation_Fusion_DW.DiscreteTimeIntegrator1_DSTA_gu;
  if (Translation_Fusion_B.Switch1_ko || (*rtu_IMU_switch)) {
    Translation_Fusion_B.Switch2_e[0] =
      Translation_Fusion_P_g.process_noise_variance1_Value[0];
    Translation_Fusion_B.Switch2_e[1] =
      Translation_Fusion_P_g.process_noise_variance1_Value[1];
    Translation_Fusion_B.Switch2_e[2] =
      Translation_Fusion_P_g.process_noise_variance1_Value[2];
    Translation_Fusion_B.Switch2_e[3] =
      Translation_Fusion_P_g.process_noise_variance1_Value[3];
  } else {
    Translation_Fusion_B.GPS_gain = (Translation_Fusion_DW.UnitDelay_DSTATE[0] *
      Translation_Fusion_DW.UnitDelay_DSTATE[0] +
      Translation_Fusion_DW.UnitDelay_DSTATE[1] *
      Translation_Fusion_DW.UnitDelay_DSTATE[1]) /
      Translation_Fusion_P_g.Constant_Value_kn;
    Translation_Fusion_B.GPS_gain = Translation_Fusion_B.GPS_gain *
      Translation_Fusion_B.GPS_gain *
      Translation_Fusion_DW.DiscreteTimeIntegrator1_DSTA_gu;
    if (Translation_Fusion_B.GPS_gain >
        Translation_Fusion_P_g.Saturation_UpperSat_o) {
      Translation_Fusion_B.GPS_gain =
        Translation_Fusion_P_g.Saturation_UpperSat_o;
    } else {
      if (Translation_Fusion_B.GPS_gain <
          Translation_Fusion_P_g.Saturation_LowerSat_a) {
        Translation_Fusion_B.GPS_gain =
          Translation_Fusion_P_g.Saturation_LowerSat_a;
      }
    }

    Translation_Fusion_B.Switch2_e[0] =
      Translation_Fusion_P_g.process_noise_variance_Value[0] *
      Translation_Fusion_B.GPS_gain;
    Translation_Fusion_B.Switch2_e[1] =
      Translation_Fusion_P_g.process_noise_variance_Value[1] *
      Translation_Fusion_B.GPS_gain;
    Translation_Fusion_B.Switch2_e[2] =
      Translation_Fusion_P_g.process_noise_variance_Value[2] *
      Translation_Fusion_B.GPS_gain;
    Translation_Fusion_B.Switch2_e[3] =
      Translation_Fusion_P_g.process_noise_variance_Value[3] *
      Translation_Fusion_B.GPS_gain;
  }

  Translation_Fusion_B.DiscreteTimeIntegrator1_ox =
    Translation_Fusion_DW.DiscreteTimeIntegrator1_DSTAT_e;
  if (Translation_Fusion_DW.DiscreteTimeIntegrator1_DSTAT_e >
      Translation_Fusion_P_g.Saturation1_UpperSat_f) {
    Translation_Fusion_B.GPS_gain =
      Translation_Fusion_P_g.Saturation1_UpperSat_f;
  } else if (Translation_Fusion_DW.DiscreteTimeIntegrator1_DSTAT_e <
             Translation_Fusion_P_g.Saturation1_LowerSat_m) {
    Translation_Fusion_B.GPS_gain =
      Translation_Fusion_P_g.Saturation1_LowerSat_m;
  } else {
    Translation_Fusion_B.GPS_gain =
      Translation_Fusion_DW.DiscreteTimeIntegrator1_DSTAT_e;
  }

  for (Translation_Fusion_B.i = 0; Translation_Fusion_B.i < 6;
       Translation_Fusion_B.i++) {
    Translation_Fusion_B.Assignment[Translation_Fusion_B.i] =
      Translation_Fusion_P_g.process_noise_variance3_Value[Translation_Fusion_B.i];
  }

  Translation_Fusion_B.Assignment[2] = Translation_Fusion_B.Switch2_e[0] *
    Translation_Fusion_B.GPS_gain;
  Translation_Fusion_B.Assignment[3] = Translation_Fusion_B.Switch2_e[1] *
    Translation_Fusion_B.GPS_gain;
  Translation_Fusion_B.Assignment[4] = Translation_Fusion_B.Switch2_e[2] *
    Translation_Fusion_B.GPS_gain;
  Translation_Fusion_B.Assignment[5] = Translation_Fusion_B.Switch2_e[3] *
    Translation_Fusion_B.GPS_gain;
  for (Translation_Fusion_B.rtb_GPS_gain_tmp = 0;
       Translation_Fusion_B.rtb_GPS_gain_tmp < 6;
       Translation_Fusion_B.rtb_GPS_gain_tmp++) {
    Translation_Fusion_B.Assignment[Translation_Fusion_B.rtb_GPS_gain_tmp] *=
      Translation_Fusion_P_g.WeightedSampleTime1_WtEt;
  }

  memset(&Translation_Fusion_B.CreateDiagonalMatrix_j[0], 0, 36U * sizeof
         (real32_T));
  for (Translation_Fusion_B.i = 0; Translation_Fusion_B.i < 6;
       Translation_Fusion_B.i++) {
    Translation_Fusion_B.CreateDiagonalMatrix_j[Translation_Fusion_B.i * 7] =
      Translation_Fusion_B.Assignment[Translation_Fusion_B.i];
  }

  for (Translation_Fusion_B.rtb_GPS_gain_tmp = 0;
       Translation_Fusion_B.rtb_GPS_gain_tmp < 6;
       Translation_Fusion_B.rtb_GPS_gain_tmp++) {
    for (Translation_Fusion_B.i = 0; Translation_Fusion_B.i < 6;
         Translation_Fusion_B.i++) {
      Translation_Fusion_B.Sqrt = 0.0F;
      for (Translation_Fusion_B.rtb_P_Kalman_tmp = 0;
           Translation_Fusion_B.rtb_P_Kalman_tmp < 6;
           Translation_Fusion_B.rtb_P_Kalman_tmp++) {
        Translation_Fusion_B.Sqrt += Translation_Fusion_P_g.Ad_Value[6 *
          Translation_Fusion_B.rtb_P_Kalman_tmp + Translation_Fusion_B.i] *
          Translation_Fusion_B.v1[6 * Translation_Fusion_B.rtb_GPS_gain_tmp +
          Translation_Fusion_B.rtb_P_Kalman_tmp];
      }

      Translation_Fusion_B.P_Kalman[Translation_Fusion_B.i + 6 *
        Translation_Fusion_B.rtb_GPS_gain_tmp] =
        Translation_Fusion_B.CreateDiagonalMatrix_j[6 *
        Translation_Fusion_B.rtb_GPS_gain_tmp + Translation_Fusion_B.i] +
        Translation_Fusion_B.Sqrt;
    }
  }

  Translation_Fusion_B.Compare_ko = ((int32_T)Translation_Fusion_B.GPS_Good >
    (int32_T)Translation_Fusion_DW.DelayInput1_DSTATE_jf);
  Translation_Fusion_B.rtb_Sum_ec_idx_0 = (real32_T)fabs
    (Translation_Fusion_DW.Memory_PreviousInput_h[0] -
     *rtu_Sensor_RTK_Data_vel_N);
  Translation_Fusion_B.rtb_Sum_ec_idx_1 = (real32_T)fabs
    (Translation_Fusion_DW.Memory_PreviousInput_h[1] -
     *rtu_Sensor_RTK_Data_vel_E);
  Translation_Fusion_B.GPS_gain = Translation_Fusion_B.rtb_Sum_ec_idx_0;
  if ((!(Translation_Fusion_B.rtb_Sum_ec_idx_0 >
         Translation_Fusion_B.rtb_Sum_ec_idx_1)) && (!rtIsNaNF
       (Translation_Fusion_B.rtb_Sum_ec_idx_1))) {
    Translation_Fusion_B.GPS_gain = Translation_Fusion_B.rtb_Sum_ec_idx_1;
  }

  Translation_Fusion_B.rtb_Sum_ec_idx_0 = (real32_T)fabs
    (*rtu_Sensor_GPS_data_vel_N - *rtu_Sensor_RTK_Data_vel_N);
  Translation_Fusion_B.rtb_Sum_ec_idx_1 = (real32_T)fabs
    (*rtu_Sensor_GPS_data_vel_E - *rtu_Sensor_RTK_Data_vel_E);
  Translation_Fusion_B.DiscreteTimeIntegrator_po =
    Translation_Fusion_B.rtb_Sum_ec_idx_0;
  if ((!(Translation_Fusion_B.rtb_Sum_ec_idx_0 >
         Translation_Fusion_B.rtb_Sum_ec_idx_1)) && (!rtIsNaNF
       (Translation_Fusion_B.rtb_Sum_ec_idx_1))) {
    Translation_Fusion_B.DiscreteTimeIntegrator_po =
      Translation_Fusion_B.rtb_Sum_ec_idx_1;
  }

  Translation_Fusion_B.LogicalOperator1_hk = (*rtu_Sensor_RTK_Data_Timestamp_m
    != Translation_Fusion_DW.DelayInput1_DSTATE_b);
  if (Translation_Fusion_B.LogicalOperator1_hk ||
      (Translation_Fusion_DW.DiscreteTimeIntegrator_PrevR_a0 != 0)) {
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_bc =
      Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_ir;
  }

  Translation_Fusion_B.Sum2_a = (uint8_T)((uint32_T)
    (Translation_Fusion_DW.Delay_DSTATE_e &&
     (!(Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_bc >=
        Translation_Fusion_P_g.CompareTo1sec_const_b))) +
    Translation_Fusion_B.LogicalOperator1_hk);
  Translation_Fusion_B.LogicalOperator2_hv = ((int32_T)((uint32_T)
    (Translation_Fusion_DW.Delay_DSTATE_e &&
     (!(Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_bc >=
        Translation_Fusion_P_g.CompareTo1sec_const_b))) +
    Translation_Fusion_B.LogicalOperator1_hk) != 0);
  rty_Translation_data_ACC_xy_O_m[0] = (*rtu_Armed ? (real32_T)
    Translation_Fusion_B.LogicalOperator1_ks : 0.0F) *
    Translation_Fusion_B.sfor_R_O_mDs2[0] - Translation_Fusion_B.rtb_Int_X_idx_2;
  Translation_Fusion_B.rtb_Sum_ec_idx_1 = rty_Translation_data_ACC_xy_O_m[0] *
    Translation_Fusion_P_g.WeightedSampleTime_WtEt +
    Translation_Fusion_B.rtb_Int_X_idx_0;
  rty_Translation_data_ACC_xy_O_m[1] = (*rtu_Armed ? (real32_T)
    Translation_Fusion_B.LogicalOperator1_ks : 0.0F) *
    Translation_Fusion_B.sfor_R_O_mDs2[1] - Translation_Fusion_B.rtb_Int_X_idx_3;
  Translation_Fusion_B.rtb_Vel_O_idx_1 = rty_Translation_data_ACC_xy_O_m[1] *
    Translation_Fusion_P_g.WeightedSampleTime_WtEt +
    Translation_Fusion_B.rtb_Int_X_idx_1;
  if (Translation_Fusion_B.LogicalOperator2_h &&
      (Translation_Fusion_PrevZCX.y_delay1_Reset_ZCE != POS_ZCSIG)) {
    Translation_Fusion_DW.icLoad_d1 = 1U;
  }

  Translation_Fusion_PrevZCX.y_delay1_Reset_ZCE =
    Translation_Fusion_B.LogicalOperator2_h;
  if (Translation_Fusion_DW.icLoad_d1 != 0) {
    for (Translation_Fusion_B.i = 0; Translation_Fusion_B.i < 140;
         Translation_Fusion_B.i++) {
      Translation_Fusion_DW.y_delay1_DSTATE[Translation_Fusion_B.i] =
        Translation_Fusion_B.rtb_Sum_ec_idx_1;
    }
  }

  if (Translation_Fusion_B.LogicalOperator2_h &&
      (Translation_Fusion_PrevZCX.y_delay2_Reset_ZCE != POS_ZCSIG)) {
    Translation_Fusion_DW.icLoad_o = 1U;
  }

  Translation_Fusion_PrevZCX.y_delay2_Reset_ZCE =
    Translation_Fusion_B.LogicalOperator2_h;
  if (Translation_Fusion_DW.icLoad_o != 0) {
    for (Translation_Fusion_B.i = 0; Translation_Fusion_B.i < 140;
         Translation_Fusion_B.i++) {
      Translation_Fusion_DW.y_delay2_DSTATE[Translation_Fusion_B.i] =
        Translation_Fusion_B.rtb_Vel_O_idx_1;
    }
  }

  if (Translation_Fusion_B.pos_valid > Translation_Fusion_P_g.Switch_Threshold_e)
  {
    Translation_Fusion_B.rtb_test1_k_idx_0 = (*rtu_Sensor_RTK_Data_mue_rad -
      Translation_Fusion_B.rtb_WGS84_pos_ref_idx_0) *
      Translation_Fusion_B.rtb_WGS84_derivatives_idx_0 -
      Translation_Fusion_B.TmpSignalConversionAtMultip[0];
    Translation_Fusion_B.rtb_test1_k_idx_1 = (*rtu_Sensor_RTK_Data_lambda_rad -
      Translation_Fusion_B.rtb_WGS84_pos_ref_idx_1) *
      Translation_Fusion_B.rtb_WGS84_derivatives_idx_1 -
      Translation_Fusion_B.TmpSignalConversionAtMultip[1];
  } else {
    Translation_Fusion_B.rtb_test1_k_idx_0 =
      Translation_Fusion_P_g.Constant_Value_p[0];
    Translation_Fusion_B.rtb_test1_k_idx_1 =
      Translation_Fusion_P_g.Constant_Value_p[1];
  }

  Translation_Fusion_B.rtb_Product_o_idx_0 = (real32_T)
    Translation_Fusion_B.rtb_test1_k_idx_0 -
    Translation_Fusion_DW.Memory1_PreviousInput_c[0];
  Translation_Fusion_B.rtb_pos_xy_O_meas_RTK_idx_0 = (real32_T)
    Translation_Fusion_B.rtb_test1_k_idx_0;
  Translation_Fusion_B.rtb_pos_xy_O_meas_RTK_j = (real32_T)
    Translation_Fusion_B.rtb_test1_k_idx_1;
  Translation_Fusion_B.rtb_Product_o_idx_1 = (real32_T)
    Translation_Fusion_B.rtb_test1_k_idx_1 -
    Translation_Fusion_DW.Memory1_PreviousInput_c[1];
  Translation_Fusion_B.rtb_DiscreteTimeIntegrator_p4_i = (real32_T)fabs
    ((Translation_Fusion_B.rtb_Product_o_idx_0 -
      Translation_Fusion_P_g.Constant_Value_ck *
      Translation_Fusion_DW.y_delay1_DSTATE[0U]) * (real32_T)
     Translation_Fusion_B.LogicalOperator2_hv);
  Translation_Fusion_B.rtb_Sum_ec_idx_0 = (real32_T)fabs
    ((Translation_Fusion_B.rtb_Product_o_idx_1 -
      Translation_Fusion_P_g.Constant_Value_ck *
      Translation_Fusion_DW.y_delay2_DSTATE[0U]) * (real32_T)
     Translation_Fusion_B.LogicalOperator2_hv);
  Translation_Fusion_B.Switch_i2 =
    Translation_Fusion_B.rtb_DiscreteTimeIntegrator_p4_i;
  if ((!(Translation_Fusion_B.rtb_DiscreteTimeIntegrator_p4_i >
         Translation_Fusion_B.rtb_Sum_ec_idx_0)) && (!rtIsNaNF
       (Translation_Fusion_B.rtb_Sum_ec_idx_0))) {
    Translation_Fusion_B.Switch_i2 = Translation_Fusion_B.rtb_Sum_ec_idx_0;
  }

  Translation_Fusion_B.rtb_Pos_O_idx_0 = (Translation_Fusion_P_g.Gain_Gain_o *
    rty_Translation_data_ACC_xy_O_m[0] *
    Translation_Fusion_P_g.WeightedSampleTime3_WtEt +
    Translation_Fusion_B.rtb_Int_X_idx_0) *
    Translation_Fusion_P_g.WeightedSampleTime2_WtEt +
    rty_Translation_data_POS_xy_O_m[0];
  Translation_Fusion_B.rtb_Product_o_idx_0 = (real32_T)fabs
    (Translation_Fusion_B.rtb_Product_o_idx_0);
  Translation_Fusion_B.rtb_Product_o_idx_1 = (real32_T)fabs
    (Translation_Fusion_B.rtb_Product_o_idx_1);
  Translation_Fusion_B.rtb_Pos_O_idx_1 = (Translation_Fusion_P_g.Gain_Gain_o *
    rty_Translation_data_ACC_xy_O_m[1] *
    Translation_Fusion_P_g.WeightedSampleTime3_WtEt +
    Translation_Fusion_B.rtb_Int_X_idx_1) *
    Translation_Fusion_P_g.WeightedSampleTime2_WtEt +
    rty_Translation_data_POS_xy_O_m[1];
  Translation_Fusion_B.DiscreteTimeIntegrator_jc =
    Translation_Fusion_B.rtb_Product_o_idx_0;
  if ((!(Translation_Fusion_B.rtb_Product_o_idx_0 >
         Translation_Fusion_B.rtb_Product_o_idx_1)) && (!rtIsNaNF
       (Translation_Fusion_B.rtb_Product_o_idx_1))) {
    Translation_Fusion_B.DiscreteTimeIntegrator_jc =
      Translation_Fusion_B.rtb_Product_o_idx_1;
  }

  Translation_Fusion_B.LogicalOperator1_ks =
    (((Translation_Fusion_B.gps_pos_valid &&
       Translation_Fusion_B.rtk_pos_valid_m &&
       Translation_Fusion_B.rtk_pos_valid && (Translation_Fusion_B.GPS_gain >=
        Translation_Fusion_P_g.CompareToConstant2_const_c3) &&
       (Translation_Fusion_B.DiscreteTimeIntegrator_po >=
        Translation_Fusion_P_g.CompareToConstant3_const_a)) ||
      (Translation_Fusion_B.Switch_i2 >=
       Translation_Fusion_P_g.CompareToConstant1_const_k3)) &&
     (Translation_Fusion_B.LogicalOperator_d &&
      Translation_Fusion_DW.Delay_DSTATE_ev &&
      Translation_Fusion_DW.Delay1_DSTATE_ci[0]) &&
     (Translation_Fusion_B.DiscreteTimeIntegrator_jc >=
      Translation_Fusion_P_g.CompareToConstant4_const_d));
  Translation_Fusion_B.LogicalOperator2_hv = ((*rtu_Sensor_RTK_Data_Timestamp_m
    != Translation_Fusion_DW.DelayInput1_DSTATE_ap) ||
    (Translation_Fusion_B.Compare_ko || Translation_Fusion_B.LogicalOperator1_ks));
  if (Translation_Fusion_B.LogicalOperator2_h &&
      (Translation_Fusion_PrevZCX.x_delay_Reset_ZCE_a != POS_ZCSIG)) {
    Translation_Fusion_DW.icLoad_c = 1U;
  }

  Translation_Fusion_PrevZCX.x_delay_Reset_ZCE_a =
    Translation_Fusion_B.LogicalOperator2_h;
  if (Translation_Fusion_DW.icLoad_c != 0) {
    for (Translation_Fusion_B.i = 0; Translation_Fusion_B.i < 40;
         Translation_Fusion_B.i++) {
      Translation_Fusion_DW.x_delay_DSTATE_i[Translation_Fusion_B.i] =
        Translation_Fusion_B.rtb_Pos_O_idx_0;
    }
  }

  if (Translation_Fusion_B.LogicalOperator2_h &&
      (Translation_Fusion_PrevZCX.y_delay_Reset_ZCE != POS_ZCSIG)) {
    Translation_Fusion_DW.icLoad_j = 1U;
  }

  Translation_Fusion_PrevZCX.y_delay_Reset_ZCE =
    Translation_Fusion_B.LogicalOperator2_h;
  if (Translation_Fusion_DW.icLoad_j != 0) {
    for (Translation_Fusion_B.i = 0; Translation_Fusion_B.i < 40;
         Translation_Fusion_B.i++) {
      Translation_Fusion_DW.y_delay_DSTATE[Translation_Fusion_B.i] =
        Translation_Fusion_B.rtb_Pos_O_idx_1;
    }
  }

  Translation_Fusion_B.rtb_WGS84_position_idx_1 =
    *rtu_Rotation_Euler_Transforma_k - Translation_Fusion_DW.UnitDelay1_DSTATE[1];
  Translation_Fusion_B.rtb_WGS84_position_idx_2 =
    *rtu_Rotation_Euler_Transformati - Translation_Fusion_DW.UnitDelay1_DSTATE[2];
  Translation_Fusion_B.rtb_DataTypeConversion3_g_idx_2 =
    *rtu_Rotation_Euler_Transforma_h - Translation_Fusion_DW.UnitDelay1_DSTATE[0];
  Translation_Fusion_B.rtb_WGS84_position_idx_0 = cos
    (Translation_Fusion_B.rtb_WGS84_position_idx_2);
  Translation_Fusion_B.rtb_DataTypeConversion3_g_idx_0 = sin
    (Translation_Fusion_B.rtb_WGS84_position_idx_2);
  Translation_Fusion_B.rtb_DataTypeConversion3_g_m =
    Translation_Fusion_B.rtb_WGS84_position_idx_1;
  Translation_Fusion_B.rtb_WGS84_position_idx_1 = cos
    (Translation_Fusion_B.rtb_WGS84_position_idx_1);
  Translation_Fusion_B.rtb_DataTypeConversion3_g_idx_1 = sin
    (Translation_Fusion_B.rtb_DataTypeConversion3_g_m);
  Translation_Fusion_B.rtb_WGS84_position_idx_2 = cos
    (Translation_Fusion_B.rtb_DataTypeConversion3_g_idx_2);
  Translation_Fusion_B.rtb_DataTypeConversion3_g_m = sin
    (Translation_Fusion_B.rtb_DataTypeConversion3_g_idx_2);
  Translation_Fusion_B.VectorConcatenate[0] =
    Translation_Fusion_B.rtb_WGS84_position_idx_1 *
    Translation_Fusion_B.rtb_WGS84_position_idx_0;
  Translation_Fusion_B.rtb_DataTypeConversion3_g_idx_2 =
    Translation_Fusion_B.rtb_DataTypeConversion3_g_m *
    Translation_Fusion_B.rtb_DataTypeConversion3_g_idx_1;
  Translation_Fusion_B.VectorConcatenate[1] =
    Translation_Fusion_B.rtb_DataTypeConversion3_g_idx_2 *
    Translation_Fusion_B.rtb_WGS84_position_idx_0 -
    Translation_Fusion_B.rtb_WGS84_position_idx_2 *
    Translation_Fusion_B.rtb_DataTypeConversion3_g_idx_0;
  Translation_Fusion_B.rtb_VectorConcatenate_tmp =
    Translation_Fusion_B.rtb_WGS84_position_idx_2 *
    Translation_Fusion_B.rtb_DataTypeConversion3_g_idx_1;
  Translation_Fusion_B.VectorConcatenate[2] =
    Translation_Fusion_B.rtb_VectorConcatenate_tmp *
    Translation_Fusion_B.rtb_WGS84_position_idx_0 +
    Translation_Fusion_B.rtb_DataTypeConversion3_g_m *
    Translation_Fusion_B.rtb_DataTypeConversion3_g_idx_0;
  Translation_Fusion_B.VectorConcatenate[3] =
    Translation_Fusion_B.rtb_WGS84_position_idx_1 *
    Translation_Fusion_B.rtb_DataTypeConversion3_g_idx_0;
  Translation_Fusion_B.VectorConcatenate[4] =
    Translation_Fusion_B.rtb_DataTypeConversion3_g_idx_2 *
    Translation_Fusion_B.rtb_DataTypeConversion3_g_idx_0 +
    Translation_Fusion_B.rtb_WGS84_position_idx_2 *
    Translation_Fusion_B.rtb_WGS84_position_idx_0;
  Translation_Fusion_B.VectorConcatenate[5] =
    Translation_Fusion_B.rtb_VectorConcatenate_tmp *
    Translation_Fusion_B.rtb_DataTypeConversion3_g_idx_0 -
    Translation_Fusion_B.rtb_DataTypeConversion3_g_m *
    Translation_Fusion_B.rtb_WGS84_position_idx_0;
  Translation_Fusion_B.VectorConcatenate[6] =
    -Translation_Fusion_B.rtb_DataTypeConversion3_g_idx_1;
  Translation_Fusion_B.VectorConcatenate[7] =
    Translation_Fusion_B.rtb_DataTypeConversion3_g_m *
    Translation_Fusion_B.rtb_WGS84_position_idx_1;
  Translation_Fusion_B.VectorConcatenate[8] =
    Translation_Fusion_B.rtb_WGS84_position_idx_2 *
    Translation_Fusion_B.rtb_WGS84_position_idx_1;
  Translation_Fusion_B.TmpSignalConversionAtMultip[2] =
    Translation_Fusion_P_g.Gain_Gain_ow * Translation_Fusion_DW.Delay_DSTATE_p;
  for (Translation_Fusion_B.rtb_GPS_gain_tmp = 0;
       Translation_Fusion_B.rtb_GPS_gain_tmp < 3;
       Translation_Fusion_B.rtb_GPS_gain_tmp++) {
    Translation_Fusion_B.rtb_VectorConcatenate_f[Translation_Fusion_B.rtb_GPS_gain_tmp]
      = Translation_Fusion_B.VectorConcatenate[3 *
      Translation_Fusion_B.rtb_GPS_gain_tmp + 2] *
      Translation_Fusion_B.TmpSignalConversionAtMultip[2] +
      (Translation_Fusion_B.VectorConcatenate[3 *
       Translation_Fusion_B.rtb_GPS_gain_tmp + 1] *
       Translation_Fusion_B.rtb_Int_X_idx_3 +
       Translation_Fusion_B.VectorConcatenate[3 *
       Translation_Fusion_B.rtb_GPS_gain_tmp] *
       Translation_Fusion_B.rtb_Int_X_idx_2);
  }

  if (Translation_Fusion_B.LogicalOperator1_ks) {
    Translation_Fusion_B.rtb_DiscreteTimeIntegrator_p4_i =
      Translation_Fusion_DW.x_delay_DSTATE_i[0U] - (real32_T)
      Translation_Fusion_B.rtb_test1_k_idx_0;
    Translation_Fusion_B.rtb_Sum_ec_idx_0 =
      Translation_Fusion_DW.y_delay_DSTATE[0U] - (real32_T)
      Translation_Fusion_B.rtb_test1_k_idx_1;
  } else if (Translation_Fusion_B.reset_ref) {
    Translation_Fusion_B.rtb_DiscreteTimeIntegrator_p4_i =
      Translation_Fusion_P_g.Constant_Value_mg;
    Translation_Fusion_B.rtb_Sum_ec_idx_0 =
      Translation_Fusion_P_g.Constant_Value_mg;
  } else {
    Translation_Fusion_B.rtb_DiscreteTimeIntegrator_p4_i =
      Translation_Fusion_DW.Memory_PreviousInput_c[0];
    Translation_Fusion_B.rtb_Sum_ec_idx_0 =
      Translation_Fusion_DW.Memory_PreviousInput_c[1];
  }

  if (Translation_Fusion_B.Compare_i) {
    Translation_Fusion_B.DiscreteTimeIntegrator_po =
      Translation_Fusion_P_g.Constant1_Value_h1;
  } else {
    Translation_Fusion_B.DiscreteTimeIntegrator_po =
      Translation_Fusion_P_g.Constant_Value_a0;
  }

  Translation_Fusion_B.rtb_DiscreteTimeIntegrator_p4_d =
    Translation_Fusion_B.rtb_DiscreteTimeIntegrator_p4_i;
  if (Translation_Fusion_B.rtb_DiscreteTimeIntegrator_p4_i >
      Translation_Fusion_P_g.Saturation_UpperSat_ky) {
    Translation_Fusion_B.rtb_DiscreteTimeIntegrator_p4_d =
      Translation_Fusion_P_g.Saturation_UpperSat_ky;
  } else {
    if (Translation_Fusion_B.rtb_DiscreteTimeIntegrator_p4_i <
        Translation_Fusion_P_g.Saturation_LowerSat_c) {
      Translation_Fusion_B.rtb_DiscreteTimeIntegrator_p4_d =
        Translation_Fusion_P_g.Saturation_LowerSat_c;
    }
  }

  Translation_Fusion_B.rtb_Product_o_idx_1 = (real32_T)fabs
    (Translation_Fusion_DW.Memory1_PreviousInput_l[0]);
  if (Translation_Fusion_DW.Memory1_PreviousInput_l[0] < 0.0F) {
    Translation_Fusion_B.Sqrt = -1.0F;
  } else if (Translation_Fusion_DW.Memory1_PreviousInput_l[0] > 0.0F) {
    Translation_Fusion_B.Sqrt = 1.0F;
  } else if (Translation_Fusion_DW.Memory1_PreviousInput_l[0] == 0.0F) {
    Translation_Fusion_B.Sqrt = 0.0F;
  } else {
    Translation_Fusion_B.Sqrt = (rtNaNF);
  }

  Translation_Fusion_B.rtb_Sum_ec_g = Translation_Fusion_B.Sqrt *
    Translation_Fusion_B.DiscreteTimeIntegrator_po;
  Translation_Fusion_B.GPS_gain = Translation_Fusion_P_g.Gain_Gain_kh *
    Translation_Fusion_B.rtb_Product_o_idx_1;
  if (!(Translation_Fusion_B.rtb_Sum_ec_g < Translation_Fusion_B.GPS_gain)) {
    Translation_Fusion_B.GPS_gain = Translation_Fusion_B.rtb_Sum_ec_g;
  }

  if (Translation_Fusion_B.rtb_Sum_ec_g >
      Translation_Fusion_B.rtb_Product_o_idx_1) {
    Translation_Fusion_B.GPS_gain = Translation_Fusion_B.rtb_Product_o_idx_1;
  }

  if (Translation_Fusion_B.rtb_Product_o_idx_1 >=
      Translation_Fusion_P_g.Attenuation_d) {
    Translation_Fusion_B.rtb_Product_o_idx_0 =
      Translation_Fusion_DW.Memory1_PreviousInput_l[0] -
      Translation_Fusion_B.GPS_gain;
  } else {
    Translation_Fusion_B.rtb_Product_o_idx_0 =
      Translation_Fusion_DW.Memory1_PreviousInput_l[0];
  }

  Translation_Fusion_B.rtb_DiscreteTimeIntegrator_p4_i =
    Translation_Fusion_B.rtb_DiscreteTimeIntegrator_p4_d;
  Translation_Fusion_B.rtb_DiscreteTimeIntegrator_p4_d =
    Translation_Fusion_B.rtb_Sum_ec_idx_0;
  if (Translation_Fusion_B.rtb_Sum_ec_idx_0 >
      Translation_Fusion_P_g.Saturation_UpperSat_ky) {
    Translation_Fusion_B.rtb_DiscreteTimeIntegrator_p4_d =
      Translation_Fusion_P_g.Saturation_UpperSat_ky;
  } else {
    if (Translation_Fusion_B.rtb_Sum_ec_idx_0 <
        Translation_Fusion_P_g.Saturation_LowerSat_c) {
      Translation_Fusion_B.rtb_DiscreteTimeIntegrator_p4_d =
        Translation_Fusion_P_g.Saturation_LowerSat_c;
    }
  }

  Translation_Fusion_B.rtb_Product_o_idx_1 = (real32_T)fabs
    (Translation_Fusion_DW.Memory1_PreviousInput_l[1]);
  if (Translation_Fusion_DW.Memory1_PreviousInput_l[1] < 0.0F) {
    Translation_Fusion_B.Sqrt = -1.0F;
  } else if (Translation_Fusion_DW.Memory1_PreviousInput_l[1] > 0.0F) {
    Translation_Fusion_B.Sqrt = 1.0F;
  } else if (Translation_Fusion_DW.Memory1_PreviousInput_l[1] == 0.0F) {
    Translation_Fusion_B.Sqrt = 0.0F;
  } else {
    Translation_Fusion_B.Sqrt = (rtNaNF);
  }

  Translation_Fusion_B.rtb_Sum_ec_g = Translation_Fusion_B.Sqrt *
    Translation_Fusion_B.DiscreteTimeIntegrator_po;
  Translation_Fusion_B.GPS_gain = Translation_Fusion_P_g.Gain_Gain_kh *
    Translation_Fusion_B.rtb_Product_o_idx_1;
  if (!(Translation_Fusion_B.rtb_Sum_ec_g < Translation_Fusion_B.GPS_gain)) {
    Translation_Fusion_B.GPS_gain = Translation_Fusion_B.rtb_Sum_ec_g;
  }

  if (Translation_Fusion_B.rtb_Sum_ec_g >
      Translation_Fusion_B.rtb_Product_o_idx_1) {
    Translation_Fusion_B.GPS_gain = Translation_Fusion_B.rtb_Product_o_idx_1;
  }

  if (Translation_Fusion_B.rtb_Product_o_idx_1 >=
      Translation_Fusion_P_g.Attenuation_d) {
    Translation_Fusion_B.rtb_Product_o_idx_1 =
      Translation_Fusion_DW.Memory1_PreviousInput_l[1] -
      Translation_Fusion_B.GPS_gain;
  } else {
    Translation_Fusion_B.rtb_Product_o_idx_1 =
      Translation_Fusion_DW.Memory1_PreviousInput_l[1];
  }

  if (Translation_Fusion_B.Compare_ko) {
    Translation_Fusion_B.rtb_Product_o_idx_0 =
      Translation_Fusion_DW.x_delay_DSTATE_i[0U] - ((real32_T)
      Translation_Fusion_B.rtb_test1_k_idx_0 +
      Translation_Fusion_B.rtb_DiscreteTimeIntegrator_p4_i);
    if (Translation_Fusion_B.rtb_Product_o_idx_0 >
        Translation_Fusion_P_g.Saturation_UpperSat_kj) {
      Translation_Fusion_B.rtb_Product_o_idx_0 =
        Translation_Fusion_P_g.Saturation_UpperSat_kj;
    } else {
      if (Translation_Fusion_B.rtb_Product_o_idx_0 <
          Translation_Fusion_P_g.Saturation_LowerSat_ap) {
        Translation_Fusion_B.rtb_Product_o_idx_0 =
          Translation_Fusion_P_g.Saturation_LowerSat_ap;
      }
    }

    Translation_Fusion_B.rtb_Product_o_idx_1 =
      Translation_Fusion_DW.y_delay_DSTATE[0U] - ((real32_T)
      Translation_Fusion_B.rtb_test1_k_idx_1 +
      Translation_Fusion_B.rtb_DiscreteTimeIntegrator_p4_d);
    if (Translation_Fusion_B.rtb_Product_o_idx_1 >
        Translation_Fusion_P_g.Saturation_UpperSat_kj) {
      Translation_Fusion_B.rtb_Product_o_idx_1 =
        Translation_Fusion_P_g.Saturation_UpperSat_kj;
    } else {
      if (Translation_Fusion_B.rtb_Product_o_idx_1 <
          Translation_Fusion_P_g.Saturation_LowerSat_ap) {
        Translation_Fusion_B.rtb_Product_o_idx_1 =
          Translation_Fusion_P_g.Saturation_LowerSat_ap;
      }
    }
  }

  Translation_Fusion_B.rtb_Sum_ec_g =
    Translation_Fusion_B.rtb_DiscreteTimeIntegrator_p4_i +
    Translation_Fusion_B.rtb_Product_o_idx_0;
  Translation_Fusion_B.rtb_Sum1_l_idx_0 = (real32_T)
    Translation_Fusion_B.rtb_test1_k_idx_0 + Translation_Fusion_B.rtb_Sum_ec_g;
  Translation_Fusion_B.rtb_Sum_ec_idx_0 = Translation_Fusion_B.rtb_Sum_ec_g;
  Translation_Fusion_B.rtb_Sum_ec_g =
    Translation_Fusion_B.rtb_DiscreteTimeIntegrator_p4_d +
    Translation_Fusion_B.rtb_Product_o_idx_1;
  Translation_Fusion_B.rtb_Sum1_l_idx_1 = (real32_T)
    Translation_Fusion_B.rtb_test1_k_idx_1 + Translation_Fusion_B.rtb_Sum_ec_g;
  if (*rtu_hover_flag) {
    Translation_Fusion_B.Switch_i2 = Translation_Fusion_P_g.Constant1_Value_n;
  } else {
    Translation_Fusion_B.Switch_i2 = Translation_Fusion_P_g.Constant_Value_d;
  }

  if (Translation_Fusion_DW.DiscreteTimeIntegrator_IC_LOA_d != 0) {
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_mr =
      Translation_Fusion_B.Switch_i2;
  }

  Translation_Fusion_B.DiscreteTimeIntegrator_po =
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_mr;
  if (Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_mr >
      Translation_Fusion_P_g.Saturation_UpperSat_fw) {
    Translation_Fusion_B.DiscreteTimeIntegrator_jc =
      Translation_Fusion_P_g.Saturation_UpperSat_fw;
  } else if (Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_mr <
             Translation_Fusion_P_g.Saturation_LowerSat_cc) {
    Translation_Fusion_B.DiscreteTimeIntegrator_jc =
      Translation_Fusion_P_g.Saturation_LowerSat_cc;
  } else {
    Translation_Fusion_B.DiscreteTimeIntegrator_jc =
      Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_mr;
  }

  Translation_Fusion_B.LogicalOperator1_ks = ((*rtu_Sensor_RTK_Data_rtk_type >=
    Translation_Fusion_P_g.CompareToConstant_const_ih) &&
    ((!Translation_Fusion_B.LogicalOperator3_d5) || rtb_LogicalOperator1_n_tmp));
  Translation_Fusion_B.Compare_ko = (Translation_Fusion_B.GPS_Good &&
    Translation_Fusion_B.LogicalOperator1_ks);
  Translation_Fusion_B.reset_ref = (Translation_Fusion_B.Compare_ko &&
    (!Translation_Fusion_B.RTK_Vel_good));
  if (Translation_Fusion_B.reset_ref) {
    for (Translation_Fusion_B.rtb_GPS_gain_tmp = 0;
         Translation_Fusion_B.rtb_GPS_gain_tmp < 3;
         Translation_Fusion_B.rtb_GPS_gain_tmp++) {
      Translation_Fusion_B.v1_tmp = (Translation_Fusion_B.rtb_GPS_gain_tmp << 1)
        * 6;
      Translation_Fusion_B.Subtract_ia[3 * Translation_Fusion_B.rtb_GPS_gain_tmp]
        = Translation_Fusion_B.P_Kalman[Translation_Fusion_B.v1_tmp];
      Translation_Fusion_B.Subtract_ia[1 + 3 *
        Translation_Fusion_B.rtb_GPS_gain_tmp] =
        Translation_Fusion_B.P_Kalman[Translation_Fusion_B.v1_tmp + 2];
      Translation_Fusion_B.Subtract_ia[2 + 3 *
        Translation_Fusion_B.rtb_GPS_gain_tmp] =
        Translation_Fusion_B.P_Kalman[Translation_Fusion_B.v1_tmp + 4];
      Translation_Fusion_B.sfor_R_O_mDs2[Translation_Fusion_B.rtb_GPS_gain_tmp] =
        Translation_Fusion_P_g.Constant_Value_ho[Translation_Fusion_B.rtb_GPS_gain_tmp
        << 2];
    }

    Translation_Fusion_Correct_x_d(Translation_Fusion_B.LogicalOperator2_hv,
      Translation_Fusion_DW.x_delay_DSTATE_i[0],
      Translation_Fusion_DW.y_delay1_DSTATE[0], (real32_T)
      Translation_Fusion_B.rtb_VectorConcatenate_f[0],
      Translation_Fusion_B.Subtract_ia, Translation_Fusion_B.sfor_R_O_mDs2,
      Translation_Fusion_B.rtb_Sum1_l_idx_0,
      Translation_Fusion_B.DiscreteTimeIntegrator_jc *
      Translation_Fusion_P_g.Constant_Value_ak[0],
      &Translation_Fusion_B.Correct_x_d, &Translation_Fusion_P_g.Correct_x_d);
    memcpy(&Translation_Fusion_B.P_RTK[0],
           &Translation_Fusion_P_g.Constant_Value_av[0], 36U * sizeof(real32_T));
    for (Translation_Fusion_B.rtb_GPS_gain_tmp = 0;
         Translation_Fusion_B.rtb_GPS_gain_tmp < 3;
         Translation_Fusion_B.rtb_GPS_gain_tmp++) {
      Translation_Fusion_B.i = Translation_Fusion_B.rtb_GPS_gain_tmp << 1;
      Translation_Fusion_B.P_RTK_tmp = 6 * Translation_Fusion_B.i;
      Translation_Fusion_B.P_RTK[Translation_Fusion_B.P_RTK_tmp] =
        Translation_Fusion_B.Correct_x_d.Multiply5[3 *
        Translation_Fusion_B.rtb_GPS_gain_tmp];
      Translation_Fusion_B.rtb_P_Kalman_tmp = Translation_Fusion_B.i + 1;
      Translation_Fusion_B.v1_tmp = Translation_Fusion_B.rtb_P_Kalman_tmp * 6;
      Translation_Fusion_B.Subtract_ia[3 * Translation_Fusion_B.rtb_GPS_gain_tmp]
        = Translation_Fusion_B.P_Kalman[Translation_Fusion_B.v1_tmp + 1];
      Translation_Fusion_B.P_RTK[2 + Translation_Fusion_B.P_RTK_tmp] =
        Translation_Fusion_B.Correct_x_d.Multiply5[3 *
        Translation_Fusion_B.rtb_GPS_gain_tmp + 1];
      Translation_Fusion_B.Subtract_ia[1 + 3 *
        Translation_Fusion_B.rtb_GPS_gain_tmp] =
        Translation_Fusion_B.P_Kalman[Translation_Fusion_B.v1_tmp + 3];
      Translation_Fusion_B.P_RTK[4 + Translation_Fusion_B.P_RTK_tmp] =
        Translation_Fusion_B.Correct_x_d.Multiply5[3 *
        Translation_Fusion_B.rtb_GPS_gain_tmp + 2];
      Translation_Fusion_B.Subtract_ia[2 + 3 *
        Translation_Fusion_B.rtb_GPS_gain_tmp] =
        Translation_Fusion_B.P_Kalman[Translation_Fusion_B.v1_tmp + 5];
      Translation_Fusion_B.sfor_R_O_mDs2[Translation_Fusion_B.rtb_GPS_gain_tmp] =
        Translation_Fusion_P_g.Constant_Value_ho
        [(Translation_Fusion_B.rtb_P_Kalman_tmp << 1) + 1];
    }

    Translation_Fusion_Correct_y(Translation_Fusion_B.LogicalOperator2_hv,
      Translation_Fusion_DW.y_delay_DSTATE[0],
      Translation_Fusion_DW.y_delay2_DSTATE[0], (real32_T)
      Translation_Fusion_B.rtb_VectorConcatenate_f[1],
      Translation_Fusion_B.Subtract_ia, Translation_Fusion_B.sfor_R_O_mDs2,
      Translation_Fusion_B.rtb_Sum1_l_idx_1,
      Translation_Fusion_B.DiscreteTimeIntegrator_jc *
      Translation_Fusion_P_g.Constant_Value_ak[3],
      &Translation_Fusion_B.Correct_y_f, &Translation_Fusion_P_g.Correct_y_f);
    for (Translation_Fusion_B.rtb_GPS_gain_tmp = 0;
         Translation_Fusion_B.rtb_GPS_gain_tmp < 3;
         Translation_Fusion_B.rtb_GPS_gain_tmp++) {
      Translation_Fusion_B.i = 6 * (1 + (Translation_Fusion_B.rtb_GPS_gain_tmp <<
        1));
      Translation_Fusion_B.P_RTK[1 + Translation_Fusion_B.i] =
        Translation_Fusion_B.Correct_y_f.Multiply5[3 *
        Translation_Fusion_B.rtb_GPS_gain_tmp];
      Translation_Fusion_B.P_RTK[3 + Translation_Fusion_B.i] =
        Translation_Fusion_B.Correct_y_f.Multiply5[3 *
        Translation_Fusion_B.rtb_GPS_gain_tmp + 1];
      Translation_Fusion_B.P_RTK[5 + Translation_Fusion_B.i] =
        Translation_Fusion_B.Correct_y_f.Multiply5[3 *
        Translation_Fusion_B.rtb_GPS_gain_tmp + 2];
    }

    Translation_Fusion_B.X_Cor_RTK_k[0] =
      Translation_Fusion_B.Correct_x_d.Multiply[0];
    Translation_Fusion_B.X_Cor_RTK_k[1] =
      Translation_Fusion_B.Correct_y_f.Multiply[0];
    Translation_Fusion_B.X_Cor_RTK_k[2] =
      Translation_Fusion_B.Correct_x_d.Multiply[1];
    Translation_Fusion_B.X_Cor_RTK_k[3] =
      Translation_Fusion_B.Correct_y_f.Multiply[1];
    Translation_Fusion_B.X_Cor_RTK_k[4] =
      Translation_Fusion_B.Correct_x_d.Multiply[2];
    Translation_Fusion_B.X_Cor_RTK_k[5] =
      Translation_Fusion_B.Correct_y_f.Multiply[2];
  }

  Translation_Fusion_B.GPS_gain = rtu_Sensor_RTK_Data_vel_quality[0];
  if ((!(rtu_Sensor_RTK_Data_vel_quality[0] < rtu_Sensor_RTK_Data_vel_quality[1]))
      && (!Translation_Fusion_B.rtb_LogicalOperator1_ls_idx_1)) {
    Translation_Fusion_B.GPS_gain = rtu_Sensor_RTK_Data_vel_quality[1];
  }

  if ((!(Translation_Fusion_B.GPS_gain < rtu_Sensor_RTK_Data_vel_quality[2])) &&
      (!rtIsNaNF(rtu_Sensor_RTK_Data_vel_quality[2]))) {
    Translation_Fusion_B.GPS_gain = rtu_Sensor_RTK_Data_vel_quality[2];
  }

  if (Translation_Fusion_B.GPS_gain >=
      Translation_Fusion_P_g.CompareToConstant_const_et) {
    Translation_Fusion_B.Switch2_e[0] =
      Translation_Fusion_P_g.Constant1_Value_e[0];
    Translation_Fusion_B.Switch2_e[3] =
      Translation_Fusion_P_g.Constant1_Value_e[3];
  } else {
    Translation_Fusion_B.Switch2_e[0] =
      Translation_Fusion_P_g.Constant1_Value_h[0];
    Translation_Fusion_B.Switch2_e[3] =
      Translation_Fusion_P_g.Constant1_Value_h[3];
  }

  Translation_Fusion_B.rtk_pos_valid = (Translation_Fusion_B.GPS_Good &&
    (!Translation_Fusion_B.LogicalOperator1_ks));
  if (Translation_Fusion_B.rtk_pos_valid) {
    for (Translation_Fusion_B.rtb_GPS_gain_tmp = 0;
         Translation_Fusion_B.rtb_GPS_gain_tmp < 3;
         Translation_Fusion_B.rtb_GPS_gain_tmp++) {
      Translation_Fusion_B.v1_tmp = (Translation_Fusion_B.rtb_GPS_gain_tmp << 1)
        * 6;
      Translation_Fusion_B.Subtract_ia[3 * Translation_Fusion_B.rtb_GPS_gain_tmp]
        = Translation_Fusion_B.P_Kalman[Translation_Fusion_B.v1_tmp];
      Translation_Fusion_B.Subtract_ia[1 + 3 *
        Translation_Fusion_B.rtb_GPS_gain_tmp] =
        Translation_Fusion_B.P_Kalman[Translation_Fusion_B.v1_tmp + 2];
      Translation_Fusion_B.Subtract_ia[2 + 3 *
        Translation_Fusion_B.rtb_GPS_gain_tmp] =
        Translation_Fusion_B.P_Kalman[Translation_Fusion_B.v1_tmp + 4];
      Translation_Fusion_B.sfor_R_O_mDs2[Translation_Fusion_B.rtb_GPS_gain_tmp] =
        Translation_Fusion_P_g.Constant1_Value_hy[Translation_Fusion_B.rtb_GPS_gain_tmp
        << 2];
    }

    Translation_Fusion_Correct_x_j(Translation_Fusion_B.LogicalOperator2_hv,
      Translation_Fusion_DW.x_delay_DSTATE_i[0],
      Translation_Fusion_DW.y_delay1_DSTATE[0], (real32_T)
      Translation_Fusion_B.rtb_VectorConcatenate_f[0],
      Translation_Fusion_B.Subtract_ia, Translation_Fusion_B.sfor_R_O_mDs2,
      Translation_Fusion_B.Delay1_f[0], Translation_Fusion_B.Switch2_e[0],
      &Translation_Fusion_B.Correct_x_j, &Translation_Fusion_P_g.Correct_x_j);
    memcpy(&Translation_Fusion_B.P_RTK[0],
           &Translation_Fusion_P_g.Constant_Value_mx[0], 36U * sizeof(real32_T));
    for (Translation_Fusion_B.rtb_GPS_gain_tmp = 0;
         Translation_Fusion_B.rtb_GPS_gain_tmp < 3;
         Translation_Fusion_B.rtb_GPS_gain_tmp++) {
      Translation_Fusion_B.i = Translation_Fusion_B.rtb_GPS_gain_tmp << 1;
      Translation_Fusion_B.P_RTK_tmp = 6 * Translation_Fusion_B.i;
      Translation_Fusion_B.P_RTK[Translation_Fusion_B.P_RTK_tmp] =
        Translation_Fusion_B.Correct_x_j.Multiply5[3 *
        Translation_Fusion_B.rtb_GPS_gain_tmp];
      Translation_Fusion_B.rtb_P_Kalman_tmp = Translation_Fusion_B.i + 1;
      Translation_Fusion_B.v1_tmp = Translation_Fusion_B.rtb_P_Kalman_tmp * 6;
      Translation_Fusion_B.Subtract_ia[3 * Translation_Fusion_B.rtb_GPS_gain_tmp]
        = Translation_Fusion_B.P_Kalman[Translation_Fusion_B.v1_tmp + 1];
      Translation_Fusion_B.P_RTK[2 + Translation_Fusion_B.P_RTK_tmp] =
        Translation_Fusion_B.Correct_x_j.Multiply5[3 *
        Translation_Fusion_B.rtb_GPS_gain_tmp + 1];
      Translation_Fusion_B.Subtract_ia[1 + 3 *
        Translation_Fusion_B.rtb_GPS_gain_tmp] =
        Translation_Fusion_B.P_Kalman[Translation_Fusion_B.v1_tmp + 3];
      Translation_Fusion_B.P_RTK[4 + Translation_Fusion_B.P_RTK_tmp] =
        Translation_Fusion_B.Correct_x_j.Multiply5[3 *
        Translation_Fusion_B.rtb_GPS_gain_tmp + 2];
      Translation_Fusion_B.Subtract_ia[2 + 3 *
        Translation_Fusion_B.rtb_GPS_gain_tmp] =
        Translation_Fusion_B.P_Kalman[Translation_Fusion_B.v1_tmp + 5];
      Translation_Fusion_B.sfor_R_O_mDs2[Translation_Fusion_B.rtb_GPS_gain_tmp] =
        Translation_Fusion_P_g.Constant1_Value_hy
        [(Translation_Fusion_B.rtb_P_Kalman_tmp << 1) + 1];
    }

    Translation_Fusion_Correct_x_j(Translation_Fusion_B.LogicalOperator2_hv,
      Translation_Fusion_DW.y_delay_DSTATE[0],
      Translation_Fusion_DW.y_delay2_DSTATE[0], (real32_T)
      Translation_Fusion_B.rtb_VectorConcatenate_f[1],
      Translation_Fusion_B.Subtract_ia, Translation_Fusion_B.sfor_R_O_mDs2,
      Translation_Fusion_B.Delay1_f[1], Translation_Fusion_B.Switch2_e[3],
      &Translation_Fusion_B.Correct_y_c, &Translation_Fusion_P_g.Correct_y_c);
    for (Translation_Fusion_B.rtb_GPS_gain_tmp = 0;
         Translation_Fusion_B.rtb_GPS_gain_tmp < 3;
         Translation_Fusion_B.rtb_GPS_gain_tmp++) {
      Translation_Fusion_B.i = 6 * (1 + (Translation_Fusion_B.rtb_GPS_gain_tmp <<
        1));
      Translation_Fusion_B.P_RTK[1 + Translation_Fusion_B.i] =
        Translation_Fusion_B.Correct_y_c.Multiply5[3 *
        Translation_Fusion_B.rtb_GPS_gain_tmp];
      Translation_Fusion_B.P_RTK[3 + Translation_Fusion_B.i] =
        Translation_Fusion_B.Correct_y_c.Multiply5[3 *
        Translation_Fusion_B.rtb_GPS_gain_tmp + 1];
      Translation_Fusion_B.P_RTK[5 + Translation_Fusion_B.i] =
        Translation_Fusion_B.Correct_y_c.Multiply5[3 *
        Translation_Fusion_B.rtb_GPS_gain_tmp + 2];
    }

    Translation_Fusion_B.X_Cor_RTK_k[0] =
      Translation_Fusion_B.Correct_x_j.Multiply[0];
    Translation_Fusion_B.X_Cor_RTK_k[1] =
      Translation_Fusion_B.Correct_y_c.Multiply[0];
    Translation_Fusion_B.X_Cor_RTK_k[2] =
      Translation_Fusion_B.Correct_x_j.Multiply[1];
    Translation_Fusion_B.X_Cor_RTK_k[3] =
      Translation_Fusion_B.Correct_y_c.Multiply[1];
    Translation_Fusion_B.X_Cor_RTK_k[4] =
      Translation_Fusion_B.Correct_x_j.Multiply[2];
    Translation_Fusion_B.X_Cor_RTK_k[5] =
      Translation_Fusion_B.Correct_y_c.Multiply[2];
  }

  Translation_Fusion_B.RTK_Vel_good = (Translation_Fusion_B.Compare_ko &&
    Translation_Fusion_B.RTK_Vel_good);
  if (Translation_Fusion_B.RTK_Vel_good) {
    for (Translation_Fusion_B.rtb_GPS_gain_tmp = 0;
         Translation_Fusion_B.rtb_GPS_gain_tmp < 3;
         Translation_Fusion_B.rtb_GPS_gain_tmp++) {
      Translation_Fusion_B.rtb_P_Kalman_tmp =
        Translation_Fusion_B.rtb_GPS_gain_tmp << 1;
      Translation_Fusion_B.v1_tmp = Translation_Fusion_B.rtb_P_Kalman_tmp * 6;
      Translation_Fusion_B.Subtract_ia[3 * Translation_Fusion_B.rtb_GPS_gain_tmp]
        = Translation_Fusion_B.P_Kalman[Translation_Fusion_B.v1_tmp];
      Translation_Fusion_B.Subtract_ia[1 + 3 *
        Translation_Fusion_B.rtb_GPS_gain_tmp] =
        Translation_Fusion_B.P_Kalman[Translation_Fusion_B.v1_tmp + 2];
      Translation_Fusion_B.Subtract_ia[2 + 3 *
        Translation_Fusion_B.rtb_GPS_gain_tmp] =
        Translation_Fusion_B.P_Kalman[Translation_Fusion_B.v1_tmp + 4];
      Translation_Fusion_B.v1_tmp = Translation_Fusion_B.rtb_GPS_gain_tmp << 3;
      Translation_Fusion_B.Selector_ai[Translation_Fusion_B.rtb_P_Kalman_tmp] =
        Translation_Fusion_P_g.Constant_Value_i4[Translation_Fusion_B.v1_tmp];
      Translation_Fusion_B.Selector_ai[1 + Translation_Fusion_B.rtb_P_Kalman_tmp]
        = Translation_Fusion_P_g.Constant_Value_i4[Translation_Fusion_B.v1_tmp +
        2];
    }

    for (Translation_Fusion_B.rtb_GPS_gain_tmp = 0;
         Translation_Fusion_B.rtb_GPS_gain_tmp < 4;
         Translation_Fusion_B.rtb_GPS_gain_tmp++) {
      Translation_Fusion_B.v1_tmp = (2 + Translation_Fusion_B.rtb_GPS_gain_tmp) <<
        2;
      Translation_Fusion_B.rtb_P_Kalman_tmp =
        Translation_Fusion_B.rtb_GPS_gain_tmp << 1;
      Translation_Fusion_B.Selector12[Translation_Fusion_B.rtb_P_Kalman_tmp] =
        Translation_Fusion_P_g.Constant_Value_i4[Translation_Fusion_B.v1_tmp + 2];
      Translation_Fusion_B.Selector12[1 + Translation_Fusion_B.rtb_P_Kalman_tmp]
        = Translation_Fusion_P_g.Constant_Value_i4[Translation_Fusion_B.v1_tmp +
        3];
    }

    for (Translation_Fusion_B.rtb_GPS_gain_tmp = 0;
         Translation_Fusion_B.rtb_GPS_gain_tmp < 2;
         Translation_Fusion_B.rtb_GPS_gain_tmp++) {
      Translation_Fusion_B.vel_xy_GPS[Translation_Fusion_B.rtb_GPS_gain_tmp] =
        Translation_Fusion_B.Delay1_f[Translation_Fusion_B.rtb_GPS_gain_tmp] -
        (((Translation_Fusion_B.Selector12[Translation_Fusion_B.rtb_GPS_gain_tmp
           + 2] * Translation_Fusion_DW.y_delay2_DSTATE[0U] +
           Translation_Fusion_B.Selector12[Translation_Fusion_B.rtb_GPS_gain_tmp]
           * Translation_Fusion_DW.y_delay1_DSTATE[0U]) +
          Translation_Fusion_B.Selector12[Translation_Fusion_B.rtb_GPS_gain_tmp
          + 4] * (real32_T)Translation_Fusion_B.rtb_VectorConcatenate_f[0]) +
         Translation_Fusion_B.Selector12[Translation_Fusion_B.rtb_GPS_gain_tmp +
         6] * (real32_T)Translation_Fusion_B.rtb_VectorConcatenate_f[1]);
      Translation_Fusion_B.DiscreteTimeIntegrator_gsh[Translation_Fusion_B.rtb_GPS_gain_tmp]
        =
        Translation_Fusion_DW.Delay1_DSTATE_p[Translation_Fusion_B.rtb_GPS_gain_tmp];
    }

    Translation_Fusion_B.Subtract1_k[0] = (Translation_Fusion_B.vel_xy_GPS[0] *
      Translation_Fusion_B.vel_xy_GPS[0] + Translation_Fusion_DW.Delay_DSTATE_b
      [0]) - Translation_Fusion_B.DiscreteTimeIntegrator_gsh[0] *
      Translation_Fusion_B.DiscreteTimeIntegrator_gsh[0];
    Translation_Fusion_B.Subtract1_k[1] = (Translation_Fusion_B.vel_xy_GPS[1] *
      Translation_Fusion_B.vel_xy_GPS[0] + Translation_Fusion_DW.Delay_DSTATE_b
      [1]) - Translation_Fusion_B.DiscreteTimeIntegrator_gsh[1] *
      Translation_Fusion_B.DiscreteTimeIntegrator_gsh[0];
    Translation_Fusion_B.Subtract1_k[2] = (Translation_Fusion_B.vel_xy_GPS[0] *
      Translation_Fusion_B.vel_xy_GPS[1] + Translation_Fusion_DW.Delay_DSTATE_b
      [2]) - Translation_Fusion_B.DiscreteTimeIntegrator_gsh[0] *
      Translation_Fusion_B.DiscreteTimeIntegrator_gsh[1];
    Translation_Fusion_B.Subtract1_k[3] = (Translation_Fusion_B.vel_xy_GPS[1] *
      Translation_Fusion_B.vel_xy_GPS[1] + Translation_Fusion_DW.Delay_DSTATE_b
      [3]) - Translation_Fusion_B.DiscreteTimeIntegrator_gsh[1] *
      Translation_Fusion_B.DiscreteTimeIntegrator_gsh[1];
    Translation_Fusion_B.Selector13[0] =
      Translation_Fusion_P_g.Constant_Value_fv[10];
    Translation_Fusion_B.Selector13[1] =
      Translation_Fusion_P_g.Constant_Value_fv[11];
    Translation_Fusion_B.Selector13[2] =
      Translation_Fusion_P_g.Constant_Value_fv[14];
    Translation_Fusion_B.Selector13[3] =
      Translation_Fusion_P_g.Constant_Value_fv[15];
    Translation_Fusi_rt_invf2x2_snf(Translation_Fusion_B.Selector13,
      Translation_Fusion_B.Switch2_e);
    if ((Translation_Fusion_B.Switch2_e[0] * Translation_Fusion_B.vel_xy_GPS[0]
         + Translation_Fusion_B.Switch2_e[2] * Translation_Fusion_B.vel_xy_GPS[1])
        * Translation_Fusion_B.vel_xy_GPS[0] + (Translation_Fusion_B.Switch2_e[1]
         * Translation_Fusion_B.vel_xy_GPS[0] + Translation_Fusion_B.Switch2_e[3]
         * Translation_Fusion_B.vel_xy_GPS[1]) *
        Translation_Fusion_B.vel_xy_GPS[1] >
        Translation_Fusion_P_g.CompareToConstant_const_j) {
      for (Translation_Fusion_B.rtb_GPS_gain_tmp = 0;
           Translation_Fusion_B.rtb_GPS_gain_tmp < 4;
           Translation_Fusion_B.rtb_GPS_gain_tmp++) {
        for (Translation_Fusion_B.i = 0; Translation_Fusion_B.i < 2;
             Translation_Fusion_B.i++) {
          Translation_Fusion_B.v1_tmp = Translation_Fusion_B.i << 2;
          Translation_Fusion_B.rtb_P_Kalman_tmp =
            Translation_Fusion_B.rtb_GPS_gain_tmp + Translation_Fusion_B.v1_tmp;
          Translation_Fusion_B.rtb_P_Kalman_c[Translation_Fusion_B.rtb_P_Kalman_tmp]
            = 0.0F;
          Translation_Fusion_B.v1_tmp += Translation_Fusion_B.rtb_GPS_gain_tmp;
          Translation_Fusion_B.rtb_P_Kalman_c[Translation_Fusion_B.rtb_P_Kalman_tmp]
            = Translation_Fusion_B.rtb_P_Kalman_c[Translation_Fusion_B.v1_tmp] +
            Translation_Fusion_B.P_Kalman[Translation_Fusion_B.rtb_GPS_gain_tmp
            + 14] * Translation_Fusion_B.Selector12[Translation_Fusion_B.i];
          Translation_Fusion_B.rtb_P_Kalman_c[Translation_Fusion_B.rtb_P_Kalman_tmp]
            = Translation_Fusion_B.rtb_P_Kalman_c[Translation_Fusion_B.v1_tmp] +
            Translation_Fusion_B.P_Kalman[Translation_Fusion_B.rtb_GPS_gain_tmp
            + 20] * Translation_Fusion_B.Selector12[Translation_Fusion_B.i + 2];
          Translation_Fusion_B.rtb_P_Kalman_c[Translation_Fusion_B.rtb_P_Kalman_tmp]
            = Translation_Fusion_B.rtb_P_Kalman_c[Translation_Fusion_B.v1_tmp] +
            Translation_Fusion_B.P_Kalman[Translation_Fusion_B.rtb_GPS_gain_tmp
            + 26] * Translation_Fusion_B.Selector12[Translation_Fusion_B.i + 4];
          Translation_Fusion_B.rtb_P_Kalman_c[Translation_Fusion_B.rtb_P_Kalman_tmp]
            = Translation_Fusion_B.rtb_P_Kalman_c[Translation_Fusion_B.v1_tmp] +
            Translation_Fusion_B.P_Kalman[Translation_Fusion_B.rtb_GPS_gain_tmp
            + 32] * Translation_Fusion_B.Selector12[Translation_Fusion_B.i + 6];
        }
      }

      for (Translation_Fusion_B.rtb_GPS_gain_tmp = 0;
           Translation_Fusion_B.rtb_GPS_gain_tmp < 2;
           Translation_Fusion_B.rtb_GPS_gain_tmp++) {
        for (Translation_Fusion_B.i = 0; Translation_Fusion_B.i < 2;
             Translation_Fusion_B.i++) {
          Translation_Fusion_B.rtb_P_Kalman_tmp = Translation_Fusion_B.i << 2;
          Translation_Fusion_B.v1_tmp = Translation_Fusion_B.i << 1;
          Translation_Fusion_B.fv0[Translation_Fusion_B.rtb_GPS_gain_tmp +
            Translation_Fusion_B.v1_tmp] =
            Translation_Fusion_B.Subtract1_k[Translation_Fusion_B.v1_tmp +
            Translation_Fusion_B.rtb_GPS_gain_tmp] *
            Translation_Fusion_P_g.Gain_Gain_k4 -
            (((Translation_Fusion_B.rtb_P_Kalman_c[Translation_Fusion_B.rtb_P_Kalman_tmp
               + 1] *
               Translation_Fusion_B.Selector12[Translation_Fusion_B.rtb_GPS_gain_tmp
               + 2] +
               Translation_Fusion_B.rtb_P_Kalman_c[Translation_Fusion_B.rtb_P_Kalman_tmp]
               * Translation_Fusion_B.Selector12[Translation_Fusion_B.rtb_GPS_gain_tmp])
              + Translation_Fusion_B.rtb_P_Kalman_c[Translation_Fusion_B.rtb_P_Kalman_tmp
              + 2] *
              Translation_Fusion_B.Selector12[Translation_Fusion_B.rtb_GPS_gain_tmp
              + 4]) +
             Translation_Fusion_B.rtb_P_Kalman_c[Translation_Fusion_B.rtb_P_Kalman_tmp
             + 3] *
             Translation_Fusion_B.Selector12[Translation_Fusion_B.rtb_GPS_gain_tmp
             + 6]);
        }

        Translation_Fusion_B.CreateDiagonalMatrix_jk[Translation_Fusion_B.rtb_GPS_gain_tmp]
          = 0.0F;
        Translation_Fusion_B.CreateDiagonalMatrix_jk[Translation_Fusion_B.rtb_GPS_gain_tmp]
          += Translation_Fusion_B.fv0[Translation_Fusion_B.rtb_GPS_gain_tmp] *
          Translation_Fusion_B.Switch2_e[0];
        Translation_Fusion_B.GPS_gain =
          Translation_Fusion_B.fv0[Translation_Fusion_B.rtb_GPS_gain_tmp + 2];
        Translation_Fusion_B.CreateDiagonalMatrix_jk[Translation_Fusion_B.rtb_GPS_gain_tmp]
          += Translation_Fusion_B.GPS_gain * Translation_Fusion_B.Switch2_e[1];
        Translation_Fusion_B.CreateDiagonalMatrix_jk[Translation_Fusion_B.rtb_GPS_gain_tmp
          + 2] = 0.0F;
        Translation_Fusion_B.CreateDiagonalMatrix_jk[Translation_Fusion_B.rtb_GPS_gain_tmp
          + 2] += Translation_Fusion_B.fv0[Translation_Fusion_B.rtb_GPS_gain_tmp]
          * Translation_Fusion_B.Switch2_e[2];
        Translation_Fusion_B.CreateDiagonalMatrix_jk[Translation_Fusion_B.rtb_GPS_gain_tmp
          + 2] += Translation_Fusion_B.GPS_gain *
          Translation_Fusion_B.Switch2_e[3];
      }

      Translation_Fusion_B.GPS_gain =
        Translation_Fusion_B.CreateDiagonalMatrix_jk[0];
      Translation_Fusion_B.Compare_ko = rtIsNaNF
        (Translation_Fusion_P_g.Constant_Value_o);
      if ((!(Translation_Fusion_B.CreateDiagonalMatrix_jk[0] >
             Translation_Fusion_P_g.Constant_Value_o)) &&
          (!Translation_Fusion_B.Compare_ko)) {
        Translation_Fusion_B.GPS_gain = Translation_Fusion_P_g.Constant_Value_o;
      }

      tmp = rtIsNaNF(Translation_Fusion_P_g.Constant2_Value_j);
      if ((!(Translation_Fusion_B.GPS_gain <
             Translation_Fusion_P_g.Constant2_Value_j)) && (!tmp)) {
        Translation_Fusion_B.GPS_gain = Translation_Fusion_P_g.Constant2_Value_j;
      }

      Translation_Fusion_B.rtb_Min_l_idx_0 = Translation_Fusion_B.GPS_gain;
      Translation_Fusion_B.GPS_gain =
        Translation_Fusion_B.CreateDiagonalMatrix_jk[3];
      if ((!(Translation_Fusion_B.CreateDiagonalMatrix_jk[3] >
             Translation_Fusion_P_g.Constant_Value_o)) &&
          (!Translation_Fusion_B.Compare_ko)) {
        Translation_Fusion_B.GPS_gain = Translation_Fusion_P_g.Constant_Value_o;
      }

      if ((!(Translation_Fusion_B.GPS_gain <
             Translation_Fusion_P_g.Constant2_Value_j)) && (!tmp)) {
        Translation_Fusion_B.GPS_gain = Translation_Fusion_P_g.Constant2_Value_j;
      }

      Translation_Fusion_B.CreateDiagonalMatrix_jk[1] = 0.0F;
      Translation_Fusion_B.CreateDiagonalMatrix_jk[2] = 0.0F;
      Translation_Fusion_B.CreateDiagonalMatrix_jk[0] =
        Translation_Fusion_B.rtb_Min_l_idx_0;
      Translation_Fusion_B.CreateDiagonalMatrix_jk[3] =
        Translation_Fusion_B.GPS_gain;
      for (Translation_Fusion_B.rtb_GPS_gain_tmp = 0;
           Translation_Fusion_B.rtb_GPS_gain_tmp < 2;
           Translation_Fusion_B.rtb_GPS_gain_tmp++) {
        Translation_Fusion_B.v1_tmp = Translation_Fusion_B.rtb_GPS_gain_tmp << 1;
        Translation_Fusion_B.Switch2_e[Translation_Fusion_B.v1_tmp] = 0.0F;
        Translation_Fusion_B.Switch2_e[Translation_Fusion_B.v1_tmp] +=
          Translation_Fusion_B.Selector13[Translation_Fusion_B.v1_tmp] *
          Translation_Fusion_B.rtb_Min_l_idx_0;
        Translation_Fusion_B.rtb_P_Kalman_tmp = Translation_Fusion_B.v1_tmp + 1;
        Translation_Fusion_B.Switch2_e[Translation_Fusion_B.v1_tmp] +=
          Translation_Fusion_B.Selector13[Translation_Fusion_B.rtb_P_Kalman_tmp]
          * 0.0F;
        Translation_Fusion_B.v1_tmp++;
        Translation_Fusion_B.Switch2_e[Translation_Fusion_B.v1_tmp] = 0.0F;
        Translation_Fusion_B.Switch2_e[Translation_Fusion_B.v1_tmp] =
          Translation_Fusion_B.Switch2_e[Translation_Fusion_B.rtb_P_Kalman_tmp]
          + Translation_Fusion_B.Selector13[Translation_Fusion_B.rtb_GPS_gain_tmp
          << 1] * 0.0F;
        Translation_Fusion_B.Switch2_e[Translation_Fusion_B.v1_tmp] =
          Translation_Fusion_B.Selector13[(Translation_Fusion_B.rtb_GPS_gain_tmp
          << 1) + 1] * Translation_Fusion_B.GPS_gain +
          Translation_Fusion_B.Switch2_e[Translation_Fusion_B.rtb_P_Kalman_tmp];
      }
    } else {
      Translation_Fusion_B.Switch2_e[0] =
        Translation_Fusion_P_g.Constant_Value_fv[10];
      Translation_Fusion_B.Switch2_e[3] =
        Translation_Fusion_P_g.Constant_Value_fv[15];
    }

    memcpy(&Translation_Fusion_B.MatrixMultiply4_l[0],
           &Translation_Fusion_P_g.Constant_Value_fv[0], sizeof(real32_T) << 4U);
    Translation_Fusion_B.MatrixMultiply4_l[10] = Translation_Fusion_B.Switch2_e
      [0];
    Translation_Fusion_B.MatrixMultiply4_l[15] = Translation_Fusion_B.Switch2_e
      [3];
    Translation_Fusion_B.Switch2_e[0] = Translation_Fusion_B.MatrixMultiply4_l[0];
    Translation_Fusion_B.Switch2_e[1] = Translation_Fusion_B.MatrixMultiply4_l[2];
    Translation_Fusion_B.Switch2_e[2] = Translation_Fusion_B.MatrixMultiply4_l[8];
    Translation_Fusion_B.Switch2_e[3] = Translation_Fusion_B.MatrixMultiply4_l
      [10];
    Translation_Fusion_Correct_x(Translation_Fusion_B.LogicalOperator2_hv,
      Translation_Fusion_DW.x_delay_DSTATE_i[0],
      Translation_Fusion_DW.y_delay1_DSTATE[0], (real32_T)
      Translation_Fusion_B.rtb_VectorConcatenate_f[0],
      Translation_Fusion_B.Subtract_ia, Translation_Fusion_B.Selector_ai,
      Translation_Fusion_B.rtb_Sum1_l_idx_0, Translation_Fusion_B.Delay1_f[0],
      Translation_Fusion_B.Switch2_e, &Translation_Fusion_B.Correct_x_a,
      &Translation_Fusion_P_g.Correct_x_a);
    memcpy(&Translation_Fusion_B.P_RTK[0],
           &Translation_Fusion_P_g.Constant_Value_la[0], 36U * sizeof(real32_T));
    for (Translation_Fusion_B.rtb_GPS_gain_tmp = 0;
         Translation_Fusion_B.rtb_GPS_gain_tmp < 3;
         Translation_Fusion_B.rtb_GPS_gain_tmp++) {
      Translation_Fusion_B.i = Translation_Fusion_B.rtb_GPS_gain_tmp << 1;
      Translation_Fusion_B.P_RTK_tmp = 6 * Translation_Fusion_B.i;
      Translation_Fusion_B.P_RTK[Translation_Fusion_B.P_RTK_tmp] =
        Translation_Fusion_B.Correct_x_a.Multiply5[3 *
        Translation_Fusion_B.rtb_GPS_gain_tmp];
      Translation_Fusion_B.rtb_P_Kalman_tmp = Translation_Fusion_B.i + 1;
      Translation_Fusion_B.v1_tmp = Translation_Fusion_B.rtb_P_Kalman_tmp * 6;
      Translation_Fusion_B.Subtract_ia[3 * Translation_Fusion_B.rtb_GPS_gain_tmp]
        = Translation_Fusion_B.P_Kalman[Translation_Fusion_B.v1_tmp + 1];
      Translation_Fusion_B.P_RTK[2 + Translation_Fusion_B.P_RTK_tmp] =
        Translation_Fusion_B.Correct_x_a.Multiply5[3 *
        Translation_Fusion_B.rtb_GPS_gain_tmp + 1];
      Translation_Fusion_B.Subtract_ia[1 + 3 *
        Translation_Fusion_B.rtb_GPS_gain_tmp] =
        Translation_Fusion_B.P_Kalman[Translation_Fusion_B.v1_tmp + 3];
      Translation_Fusion_B.P_RTK[4 + Translation_Fusion_B.P_RTK_tmp] =
        Translation_Fusion_B.Correct_x_a.Multiply5[3 *
        Translation_Fusion_B.rtb_GPS_gain_tmp + 2];
      Translation_Fusion_B.Subtract_ia[2 + 3 *
        Translation_Fusion_B.rtb_GPS_gain_tmp] =
        Translation_Fusion_B.P_Kalman[Translation_Fusion_B.v1_tmp + 5];
      Translation_Fusion_B.v1_tmp = Translation_Fusion_B.rtb_P_Kalman_tmp << 2;
      Translation_Fusion_B.Selector_ai[Translation_Fusion_B.i] =
        Translation_Fusion_P_g.Constant_Value_i4[Translation_Fusion_B.v1_tmp + 1];
      Translation_Fusion_B.Selector_ai[1 + Translation_Fusion_B.i] =
        Translation_Fusion_P_g.Constant_Value_i4[Translation_Fusion_B.v1_tmp + 3];
    }

    Translation_Fusion_B.Switch2_e[0] = Translation_Fusion_B.MatrixMultiply4_l[5];
    Translation_Fusion_B.Switch2_e[1] = Translation_Fusion_B.MatrixMultiply4_l[7];
    Translation_Fusion_B.Switch2_e[2] = Translation_Fusion_B.MatrixMultiply4_l
      [13];
    Translation_Fusion_B.Switch2_e[3] = Translation_Fusion_B.MatrixMultiply4_l
      [15];
    Translation_Fusion_Correct_x(Translation_Fusion_B.LogicalOperator2_hv,
      Translation_Fusion_DW.y_delay_DSTATE[0],
      Translation_Fusion_DW.y_delay2_DSTATE[0], (real32_T)
      Translation_Fusion_B.rtb_VectorConcatenate_f[1],
      Translation_Fusion_B.Subtract_ia, Translation_Fusion_B.Selector_ai,
      Translation_Fusion_B.rtb_Sum1_l_idx_1, Translation_Fusion_B.Delay1_f[1],
      Translation_Fusion_B.Switch2_e, &Translation_Fusion_B.Correct_y_b,
      &Translation_Fusion_P_g.Correct_y_b);
    for (Translation_Fusion_B.rtb_GPS_gain_tmp = 0;
         Translation_Fusion_B.rtb_GPS_gain_tmp < 3;
         Translation_Fusion_B.rtb_GPS_gain_tmp++) {
      Translation_Fusion_B.i = 6 * (1 + (Translation_Fusion_B.rtb_GPS_gain_tmp <<
        1));
      Translation_Fusion_B.P_RTK[1 + Translation_Fusion_B.i] =
        Translation_Fusion_B.Correct_y_b.Multiply5[3 *
        Translation_Fusion_B.rtb_GPS_gain_tmp];
      Translation_Fusion_B.P_RTK[3 + Translation_Fusion_B.i] =
        Translation_Fusion_B.Correct_y_b.Multiply5[3 *
        Translation_Fusion_B.rtb_GPS_gain_tmp + 1];
      Translation_Fusion_B.P_RTK[5 + Translation_Fusion_B.i] =
        Translation_Fusion_B.Correct_y_b.Multiply5[3 *
        Translation_Fusion_B.rtb_GPS_gain_tmp + 2];
    }

    Translation_Fusion_B.X_Cor_RTK_k[0] =
      Translation_Fusion_B.Correct_x_a.Multiply[0];
    Translation_Fusion_B.X_Cor_RTK_k[1] =
      Translation_Fusion_B.Correct_y_b.Multiply[0];
    Translation_Fusion_B.X_Cor_RTK_k[2] =
      Translation_Fusion_B.Correct_x_a.Multiply[1];
    Translation_Fusion_B.X_Cor_RTK_k[3] =
      Translation_Fusion_B.Correct_y_b.Multiply[1];
    Translation_Fusion_B.X_Cor_RTK_k[4] =
      Translation_Fusion_B.Correct_x_a.Multiply[2];
    Translation_Fusion_B.X_Cor_RTK_k[5] =
      Translation_Fusion_B.Correct_y_b.Multiply[2];
    for (Translation_Fusion_B.i = 0; Translation_Fusion_B.i < 4;
         Translation_Fusion_B.i++) {
      Translation_Fusion_DW.Delay_DSTATE_b[Translation_Fusion_B.i] =
        Translation_Fusion_B.Subtract1_k[Translation_Fusion_B.i];
      Translation_Fusion_B.rtb_GPS_gain_tmp = (Translation_Fusion_B.i + 1) << 1;
      Translation_Fusion_B.v1_tmp = Translation_Fusion_B.i << 1;
      Translation_Fusion_DW.Delay1_DSTATE_p[Translation_Fusion_B.v1_tmp] =
        Translation_Fusion_DW.Delay1_DSTATE_p[Translation_Fusion_B.rtb_GPS_gain_tmp];
      Translation_Fusion_DW.Delay1_DSTATE_p[Translation_Fusion_B.v1_tmp + 1] =
        Translation_Fusion_DW.Delay1_DSTATE_p[Translation_Fusion_B.rtb_GPS_gain_tmp
        + 1];
    }

    Translation_Fusion_DW.Delay1_DSTATE_p[8] = Translation_Fusion_B.vel_xy_GPS[0];
    Translation_Fusion_DW.Delay1_DSTATE_p[9] = Translation_Fusion_B.vel_xy_GPS[1];
  }

  Translation_Fusion_B.reset_ref = ((Translation_Fusion_B.reset_ref ||
    Translation_Fusion_B.rtk_pos_valid || Translation_Fusion_B.RTK_Vel_good) &&
    Translation_Fusion_B.LogicalOperator2_hv);
  if (Translation_Fusion_P_g.ManualSwitch1_CurrentSetting != 1) {
    for (Translation_Fusion_B.rtb_GPS_gain_tmp = 0;
         Translation_Fusion_B.rtb_GPS_gain_tmp < 36;
         Translation_Fusion_B.rtb_GPS_gain_tmp++) {
      Translation_Fusion_B.GPS_gain =
        Translation_Fusion_B.P_Kalman[Translation_Fusion_B.rtb_GPS_gain_tmp];
      if (Translation_Fusion_B.reset_ref) {
        Translation_Fusion_B.GPS_gain =
          Translation_Fusion_B.P_RTK[Translation_Fusion_B.rtb_GPS_gain_tmp];
      }

      Translation_Fusion_B.P_Kalman[Translation_Fusion_B.rtb_GPS_gain_tmp] =
        Translation_Fusion_B.GPS_gain;
    }
  }

  if (Translation_Fusion_B.reset_ref ||
      (Translation_Fusion_DW.DiscreteTimeIntegrator_PrevR_ov != 0)) {
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_lv =
      Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_oo;
  }

  for (Translation_Fusion_B.i = 0; Translation_Fusion_B.i < 6;
       Translation_Fusion_B.i++) {
    Translation_Fusion_B.Selector_ai[Translation_Fusion_B.i] =
      Translation_Fusion_P_g.Gain_Gain_a3 *
      Translation_Fusion_B.X_Cor_RTK_k[Translation_Fusion_B.i];
  }

  if (Translation_Fusion_DW.DiscreteTimeIntegrator_IC_LOA_i != 0) {
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_nr[0] =
      Translation_Fusion_B.Selector_ai[0];
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_nr[1] =
      Translation_Fusion_B.Selector_ai[1];
  }

  Translation_Fusion_B.rtb_Min_l_idx_0 =
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_nr[0];
  Translation_Fusion_B.rtb_Min_l_idx_1 =
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_nr[1];
  if (Translation_Fusion_DW.DiscreteTimeIntegrator_IC_LOA_o != 0) {
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_dd[0] =
      Translation_Fusion_B.Selector_ai[2];
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_dd[1] =
      Translation_Fusion_B.Selector_ai[3];
  }

  Translation_Fusion_B.rtb_Sum1_l_idx_0 =
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_dd[0];
  Translation_Fusion_B.rtb_Sum1_l_idx_1 =
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_dd[1];
  if (Translation_Fusion_P_g.ManualSwitch_CurrentSetting == 1) {
    Translation_Fusion_B.ManualSwitch[0] = Translation_Fusion_B.rtb_Pos_O_idx_0;
    Translation_Fusion_B.ManualSwitch[2] = Translation_Fusion_B.rtb_Sum_ec_idx_1;
    Translation_Fusion_B.ManualSwitch[4] = (real32_T)
      Translation_Fusion_B.rtb_VectorConcatenate_f[0];
    Translation_Fusion_B.ManualSwitch[1] = Translation_Fusion_B.rtb_Pos_O_idx_1;
    Translation_Fusion_B.ManualSwitch[3] = Translation_Fusion_B.rtb_Vel_O_idx_1;
    Translation_Fusion_B.ManualSwitch[5] = (real32_T)
      Translation_Fusion_B.rtb_VectorConcatenate_f[1];
  } else {
    Translation_Fusion_B.LogicalOperator2_hv =
      (Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_lv >=
       Translation_Fusion_P_g.CompareToConstant_const_fl);
    if (Translation_Fusion_B.LogicalOperator2_hv) {
      Translation_Fusion_B.GPS_gain = Translation_Fusion_P_g.Constant1_Value_o;
    } else {
      Translation_Fusion_B.GPS_gain =
        Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_nr[0];
    }

    Translation_Fusion_B.ManualSwitch[0] = Translation_Fusion_B.rtb_Pos_O_idx_0
      + Translation_Fusion_B.GPS_gain;
    if (Translation_Fusion_B.LogicalOperator2_hv) {
      Translation_Fusion_B.GPS_gain = Translation_Fusion_P_g.Constant1_Value_o;
    } else {
      Translation_Fusion_B.GPS_gain =
        Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_dd[0];
    }

    Translation_Fusion_B.ManualSwitch[2] = Translation_Fusion_B.rtb_Sum_ec_idx_1
      + Translation_Fusion_B.GPS_gain;
    if (Translation_Fusion_B.LogicalOperator2_hv) {
      Translation_Fusion_B.GPS_gain = Translation_Fusion_P_g.Constant1_Value_o;
    } else {
      Translation_Fusion_B.GPS_gain = Translation_Fusion_B.Selector_ai[4];
    }

    Translation_Fusion_B.ManualSwitch[4] = (real32_T)
      Translation_Fusion_B.rtb_VectorConcatenate_f[0] +
      Translation_Fusion_B.GPS_gain;
    if (Translation_Fusion_B.LogicalOperator2_hv) {
      Translation_Fusion_B.GPS_gain = Translation_Fusion_P_g.Constant1_Value_o;
    } else {
      Translation_Fusion_B.GPS_gain =
        Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_nr[1];
    }

    Translation_Fusion_B.ManualSwitch[1] = Translation_Fusion_B.rtb_Pos_O_idx_1
      + Translation_Fusion_B.GPS_gain;
    if (Translation_Fusion_B.LogicalOperator2_hv) {
      Translation_Fusion_B.GPS_gain = Translation_Fusion_P_g.Constant1_Value_o;
    } else {
      Translation_Fusion_B.GPS_gain =
        Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_dd[1];
    }

    Translation_Fusion_B.ManualSwitch[3] = Translation_Fusion_B.rtb_Vel_O_idx_1
      + Translation_Fusion_B.GPS_gain;
    if (Translation_Fusion_B.LogicalOperator2_hv) {
      Translation_Fusion_B.GPS_gain = Translation_Fusion_P_g.Constant1_Value_o;
    } else {
      Translation_Fusion_B.GPS_gain = Translation_Fusion_B.Selector_ai[5];
    }

    Translation_Fusion_B.ManualSwitch[5] = (real32_T)
      Translation_Fusion_B.rtb_VectorConcatenate_f[1] +
      Translation_Fusion_B.GPS_gain;
  }

  for (Translation_Fusion_B.rtb_GPS_gain_tmp = 0;
       Translation_Fusion_B.rtb_GPS_gain_tmp < 4;
       Translation_Fusion_B.rtb_GPS_gain_tmp++) {
    Translation_Fusion_B.v1_tmp = (2 + Translation_Fusion_B.rtb_GPS_gain_tmp) *
      6;
    Translation_Fusion_B.rtb_P_Kalman_tmp =
      Translation_Fusion_B.rtb_GPS_gain_tmp << 2;
    Translation_Fusion_B.MatrixMultiply4_l[Translation_Fusion_B.rtb_P_Kalman_tmp]
      = Translation_Fusion_B.P_Kalman[Translation_Fusion_B.v1_tmp + 2];
    Translation_Fusion_B.MatrixMultiply4_l[1 +
      Translation_Fusion_B.rtb_P_Kalman_tmp] =
      Translation_Fusion_B.P_Kalman[Translation_Fusion_B.v1_tmp + 3];
    Translation_Fusion_B.MatrixMultiply4_l[2 +
      Translation_Fusion_B.rtb_P_Kalman_tmp] =
      Translation_Fusion_B.P_Kalman[Translation_Fusion_B.v1_tmp + 4];
    Translation_Fusion_B.MatrixMultiply4_l[3 +
      Translation_Fusion_B.rtb_P_Kalman_tmp] =
      Translation_Fusion_B.P_Kalman[Translation_Fusion_B.v1_tmp + 5];
  }

  Translation_Fusion_B.GPS_gain = Translation_Fusion_P_g.SampleTime_WtEt_h;
  Translation_Fusion_Average(rty_Translation_data_ACC_xy_O_m[0],
    &Translation_Fusion_B.MovingAverage_p,
    &Translation_Fusion_DW.MovingAverage_p);
  Translation_Fusion_Average(rty_Translation_data_ACC_xy_O_m[1],
    &Translation_Fusion_B.MovingAverage1, &Translation_Fusion_DW.MovingAverage1);
  Translation_Fusion_B.DataTypeConversion4[0] =
    Translation_Fusion_P_g.ust_orderdelaycompensator1_N_j *
    Translation_Fusion_B.MovingAverage_p.Average * Translation_Fusion_B.GPS_gain
    + *rtu_Sensor_GPS_data_vel_N;
  Translation_Fusion_B.DataTypeConversion4[1] =
    Translation_Fusion_P_g.ust_orderdelaycompensator1_N_j *
    Translation_Fusion_B.MovingAverage1.Average * Translation_Fusion_B.GPS_gain
    + *rtu_Sensor_GPS_data_vel_E;
  Translation_Fusion_B.GPS_gain = Translation_Fusion_B.Sum_ol *
    Translation_Fusion_B.Sum_ol;
  Translation_Fusion_B.Subtract1_k[0] = Translation_Fusion_B.GPS_gain *
    Translation_Fusion_P_g.Constant_Value_nx[0];
  Translation_Fusion_B.Subtract1_k[1] = Translation_Fusion_B.GPS_gain *
    Translation_Fusion_P_g.Constant_Value_nx[1];
  Translation_Fusion_B.Subtract1_k[2] = Translation_Fusion_B.GPS_gain *
    Translation_Fusion_P_g.Constant_Value_nx[2];
  Translation_Fusion_B.Subtract1_k[3] = Translation_Fusion_B.GPS_gain *
    Translation_Fusion_P_g.Constant_Value_nx[3];
  if (Translation_Fusion_B.En_GPS_Correct_RTK) {
    for (Translation_Fusion_B.rtb_GPS_gain_tmp = 0;
         Translation_Fusion_B.rtb_GPS_gain_tmp < 2;
         Translation_Fusion_B.rtb_GPS_gain_tmp++) {
      Translation_Fusion_B.vel_xy_GPS[Translation_Fusion_B.rtb_GPS_gain_tmp] =
        Translation_Fusion_B.DataTypeConversion4[Translation_Fusion_B.rtb_GPS_gain_tmp]
        - (((Translation_Fusion_P_g.MeaMatrix_Value[Translation_Fusion_B.rtb_GPS_gain_tmp
             + 2] * Translation_Fusion_B.ManualSwitch[3] +
             Translation_Fusion_P_g.MeaMatrix_Value[Translation_Fusion_B.rtb_GPS_gain_tmp]
             * Translation_Fusion_B.ManualSwitch[2]) +
            Translation_Fusion_P_g.MeaMatrix_Value[Translation_Fusion_B.rtb_GPS_gain_tmp
            + 4] * Translation_Fusion_B.ManualSwitch[4]) +
           Translation_Fusion_P_g.MeaMatrix_Value[Translation_Fusion_B.rtb_GPS_gain_tmp
           + 6] * Translation_Fusion_B.ManualSwitch[5]);
      Translation_Fusion_B.DiscreteTimeIntegrator_gsh[Translation_Fusion_B.rtb_GPS_gain_tmp]
        =
        Translation_Fusion_DW.Delay1_DSTATE_gi[Translation_Fusion_B.rtb_GPS_gain_tmp];
    }

    Translation_Fusion_B.Selector13[0] = (Translation_Fusion_B.vel_xy_GPS[0] *
      Translation_Fusion_B.vel_xy_GPS[0] +
      Translation_Fusion_DW.Delay_DSTATE_ko[0]) -
      Translation_Fusion_B.DiscreteTimeIntegrator_gsh[0] *
      Translation_Fusion_B.DiscreteTimeIntegrator_gsh[0];
    Translation_Fusion_B.Selector13[1] = (Translation_Fusion_B.vel_xy_GPS[1] *
      Translation_Fusion_B.vel_xy_GPS[0] +
      Translation_Fusion_DW.Delay_DSTATE_ko[1]) -
      Translation_Fusion_B.DiscreteTimeIntegrator_gsh[1] *
      Translation_Fusion_B.DiscreteTimeIntegrator_gsh[0];
    Translation_Fusion_B.Selector13[2] = (Translation_Fusion_B.vel_xy_GPS[0] *
      Translation_Fusion_B.vel_xy_GPS[1] +
      Translation_Fusion_DW.Delay_DSTATE_ko[2]) -
      Translation_Fusion_B.DiscreteTimeIntegrator_gsh[0] *
      Translation_Fusion_B.DiscreteTimeIntegrator_gsh[1];
    Translation_Fusion_B.Selector13[3] = (Translation_Fusion_B.vel_xy_GPS[1] *
      Translation_Fusion_B.vel_xy_GPS[1] +
      Translation_Fusion_DW.Delay_DSTATE_ko[3]) -
      Translation_Fusion_B.DiscreteTimeIntegrator_gsh[1] *
      Translation_Fusion_B.DiscreteTimeIntegrator_gsh[1];
    Translation_Fusi_rt_invf2x2_snf(Translation_Fusion_B.Subtract1_k,
      Translation_Fusion_B.Switch2_e);
    if ((Translation_Fusion_B.Switch2_e[0] * Translation_Fusion_B.vel_xy_GPS[0]
         + Translation_Fusion_B.Switch2_e[2] * Translation_Fusion_B.vel_xy_GPS[1])
        * Translation_Fusion_B.vel_xy_GPS[0] + (Translation_Fusion_B.Switch2_e[1]
         * Translation_Fusion_B.vel_xy_GPS[0] + Translation_Fusion_B.Switch2_e[3]
         * Translation_Fusion_B.vel_xy_GPS[1]) *
        Translation_Fusion_B.vel_xy_GPS[1] >
        Translation_Fusion_P_g.AdaptiveGPSVelocityCorrection_k) {
      for (Translation_Fusion_B.rtb_GPS_gain_tmp = 0;
           Translation_Fusion_B.rtb_GPS_gain_tmp < 4;
           Translation_Fusion_B.rtb_GPS_gain_tmp++) {
        for (Translation_Fusion_B.i = 0; Translation_Fusion_B.i < 2;
             Translation_Fusion_B.i++) {
          Translation_Fusion_B.v1_tmp = Translation_Fusion_B.i << 2;
          Translation_Fusion_B.rtb_P_Kalman_tmp =
            Translation_Fusion_B.rtb_GPS_gain_tmp + Translation_Fusion_B.v1_tmp;
          Translation_Fusion_B.rtb_P_Kalman_c[Translation_Fusion_B.rtb_P_Kalman_tmp]
            = 0.0F;
          Translation_Fusion_B.v1_tmp += Translation_Fusion_B.rtb_GPS_gain_tmp;
          Translation_Fusion_B.rtb_P_Kalman_c[Translation_Fusion_B.rtb_P_Kalman_tmp]
            = Translation_Fusion_B.rtb_P_Kalman_c[Translation_Fusion_B.v1_tmp] +
            Translation_Fusion_B.MatrixMultiply4_l[Translation_Fusion_B.rtb_GPS_gain_tmp]
            * Translation_Fusion_P_g.MeaMatrix_Value[Translation_Fusion_B.i];
          Translation_Fusion_B.rtb_P_Kalman_c[Translation_Fusion_B.rtb_P_Kalman_tmp]
            = Translation_Fusion_B.rtb_P_Kalman_c[Translation_Fusion_B.v1_tmp] +
            Translation_Fusion_B.MatrixMultiply4_l[Translation_Fusion_B.rtb_GPS_gain_tmp
            + 4] * Translation_Fusion_P_g.MeaMatrix_Value[Translation_Fusion_B.i
            + 2];
          Translation_Fusion_B.rtb_P_Kalman_c[Translation_Fusion_B.rtb_P_Kalman_tmp]
            = Translation_Fusion_B.rtb_P_Kalman_c[Translation_Fusion_B.v1_tmp] +
            Translation_Fusion_B.MatrixMultiply4_l[Translation_Fusion_B.rtb_GPS_gain_tmp
            + 8] * Translation_Fusion_P_g.MeaMatrix_Value[Translation_Fusion_B.i
            + 4];
          Translation_Fusion_B.rtb_P_Kalman_c[Translation_Fusion_B.rtb_P_Kalman_tmp]
            = Translation_Fusion_B.rtb_P_Kalman_c[Translation_Fusion_B.v1_tmp] +
            Translation_Fusion_B.MatrixMultiply4_l[Translation_Fusion_B.rtb_GPS_gain_tmp
            + 12] *
            Translation_Fusion_P_g.MeaMatrix_Value[Translation_Fusion_B.i + 6];
        }
      }

      for (Translation_Fusion_B.rtb_GPS_gain_tmp = 0;
           Translation_Fusion_B.rtb_GPS_gain_tmp < 2;
           Translation_Fusion_B.rtb_GPS_gain_tmp++) {
        for (Translation_Fusion_B.i = 0; Translation_Fusion_B.i < 2;
             Translation_Fusion_B.i++) {
          Translation_Fusion_B.rtb_P_Kalman_tmp = Translation_Fusion_B.i << 2;
          Translation_Fusion_B.v1_tmp = Translation_Fusion_B.i << 1;
          Translation_Fusion_B.fv0[Translation_Fusion_B.rtb_GPS_gain_tmp +
            Translation_Fusion_B.v1_tmp] =
            Translation_Fusion_B.Selector13[Translation_Fusion_B.v1_tmp +
            Translation_Fusion_B.rtb_GPS_gain_tmp] *
            Translation_Fusion_P_g.Gain_Gain_k3 -
            (((Translation_Fusion_B.rtb_P_Kalman_c[Translation_Fusion_B.rtb_P_Kalman_tmp
               + 1] *
               Translation_Fusion_P_g.MeaMatrix_Value[Translation_Fusion_B.rtb_GPS_gain_tmp
               + 2] +
               Translation_Fusion_B.rtb_P_Kalman_c[Translation_Fusion_B.rtb_P_Kalman_tmp]
               * Translation_Fusion_P_g.MeaMatrix_Value[Translation_Fusion_B.rtb_GPS_gain_tmp])
              + Translation_Fusion_B.rtb_P_Kalman_c[Translation_Fusion_B.rtb_P_Kalman_tmp
              + 2] *
              Translation_Fusion_P_g.MeaMatrix_Value[Translation_Fusion_B.rtb_GPS_gain_tmp
              + 4]) +
             Translation_Fusion_B.rtb_P_Kalman_c[Translation_Fusion_B.rtb_P_Kalman_tmp
             + 3] *
             Translation_Fusion_P_g.MeaMatrix_Value[Translation_Fusion_B.rtb_GPS_gain_tmp
             + 6]);
        }

        Translation_Fusion_B.CreateDiagonalMatrix_jk[Translation_Fusion_B.rtb_GPS_gain_tmp]
          = 0.0F;
        Translation_Fusion_B.CreateDiagonalMatrix_jk[Translation_Fusion_B.rtb_GPS_gain_tmp]
          += Translation_Fusion_B.fv0[Translation_Fusion_B.rtb_GPS_gain_tmp] *
          Translation_Fusion_B.Switch2_e[0];
        Translation_Fusion_B.GPS_gain =
          Translation_Fusion_B.fv0[Translation_Fusion_B.rtb_GPS_gain_tmp + 2];
        Translation_Fusion_B.CreateDiagonalMatrix_jk[Translation_Fusion_B.rtb_GPS_gain_tmp]
          += Translation_Fusion_B.GPS_gain * Translation_Fusion_B.Switch2_e[1];
        Translation_Fusion_B.CreateDiagonalMatrix_jk[Translation_Fusion_B.rtb_GPS_gain_tmp
          + 2] = 0.0F;
        Translation_Fusion_B.CreateDiagonalMatrix_jk[Translation_Fusion_B.rtb_GPS_gain_tmp
          + 2] += Translation_Fusion_B.fv0[Translation_Fusion_B.rtb_GPS_gain_tmp]
          * Translation_Fusion_B.Switch2_e[2];
        Translation_Fusion_B.CreateDiagonalMatrix_jk[Translation_Fusion_B.rtb_GPS_gain_tmp
          + 2] += Translation_Fusion_B.GPS_gain *
          Translation_Fusion_B.Switch2_e[3];
      }

      Translation_Fusion_B.GPS_gain =
        Translation_Fusion_B.CreateDiagonalMatrix_jk[0];
      Translation_Fusion_B.Compare_ko = rtIsNaNF
        (Translation_Fusion_P_g.Constant_Value_kt);
      if ((!(Translation_Fusion_B.CreateDiagonalMatrix_jk[0] >
             Translation_Fusion_P_g.Constant_Value_kt)) &&
          (!Translation_Fusion_B.Compare_ko)) {
        Translation_Fusion_B.GPS_gain = Translation_Fusion_P_g.Constant_Value_kt;
      }

      tmp = rtIsNaNF(Translation_Fusion_P_g.AdaptiveGPSVelocityCorrection_m);
      if ((!(Translation_Fusion_B.GPS_gain <
             Translation_Fusion_P_g.AdaptiveGPSVelocityCorrection_m)) && (!tmp))
      {
        Translation_Fusion_B.GPS_gain =
          Translation_Fusion_P_g.AdaptiveGPSVelocityCorrection_m;
      }

      Translation_Fusion_B.Min_h[0] = Translation_Fusion_B.GPS_gain;
      Translation_Fusion_B.GPS_gain =
        Translation_Fusion_B.CreateDiagonalMatrix_jk[3];
      if ((!(Translation_Fusion_B.CreateDiagonalMatrix_jk[3] >
             Translation_Fusion_P_g.Constant_Value_kt)) &&
          (!Translation_Fusion_B.Compare_ko)) {
        Translation_Fusion_B.GPS_gain = Translation_Fusion_P_g.Constant_Value_kt;
      }

      if ((!(Translation_Fusion_B.GPS_gain <
             Translation_Fusion_P_g.AdaptiveGPSVelocityCorrection_m)) && (!tmp))
      {
        Translation_Fusion_B.GPS_gain =
          Translation_Fusion_P_g.AdaptiveGPSVelocityCorrection_m;
      }

      for (Translation_Fusion_B.rtb_GPS_gain_tmp = 0;
           Translation_Fusion_B.rtb_GPS_gain_tmp < 2;
           Translation_Fusion_B.rtb_GPS_gain_tmp++) {
        Translation_Fusion_B.v1_tmp = Translation_Fusion_B.rtb_GPS_gain_tmp << 1;
        Translation_Fusion_B.Switch2_e[Translation_Fusion_B.v1_tmp] = 0.0F;
        Translation_Fusion_B.Switch2_e[Translation_Fusion_B.v1_tmp] +=
          Translation_Fusion_B.Subtract1_k[Translation_Fusion_B.v1_tmp] *
          Translation_Fusion_B.Min_h[0];
        Translation_Fusion_B.rtb_P_Kalman_tmp = Translation_Fusion_B.v1_tmp + 1;
        Translation_Fusion_B.Switch2_e[Translation_Fusion_B.v1_tmp] +=
          Translation_Fusion_B.Subtract1_k[Translation_Fusion_B.rtb_P_Kalman_tmp]
          * 0.0F;
        Translation_Fusion_B.v1_tmp++;
        Translation_Fusion_B.Switch2_e[Translation_Fusion_B.v1_tmp] = 0.0F;
        Translation_Fusion_B.Switch2_e[Translation_Fusion_B.v1_tmp] =
          Translation_Fusion_B.Switch2_e[Translation_Fusion_B.rtb_P_Kalman_tmp]
          + Translation_Fusion_B.Subtract1_k[Translation_Fusion_B.rtb_GPS_gain_tmp
          << 1] * 0.0F;
        Translation_Fusion_B.Switch2_e[Translation_Fusion_B.v1_tmp] =
          Translation_Fusion_B.Subtract1_k
          [(Translation_Fusion_B.rtb_GPS_gain_tmp << 1) + 1] *
          Translation_Fusion_B.GPS_gain +
          Translation_Fusion_B.Switch2_e[Translation_Fusion_B.rtb_P_Kalman_tmp];
      }
    } else {
      Translation_Fusion_B.Switch2_e[0] = Translation_Fusion_B.Subtract1_k[0];
      Translation_Fusion_B.Switch2_e[1] = Translation_Fusion_B.Subtract1_k[1];
      Translation_Fusion_B.Switch2_e[2] = Translation_Fusion_B.Subtract1_k[2];
      Translation_Fusion_B.Switch2_e[3] = Translation_Fusion_B.Subtract1_k[3];
    }

    for (Translation_Fusion_B.rtb_GPS_gain_tmp = 0;
         Translation_Fusion_B.rtb_GPS_gain_tmp < 4;
         Translation_Fusion_B.rtb_GPS_gain_tmp++) {
      for (Translation_Fusion_B.i = 0; Translation_Fusion_B.i < 2;
           Translation_Fusion_B.i++) {
        Translation_Fusion_B.v1_tmp = Translation_Fusion_B.i << 2;
        Translation_Fusion_B.rtb_P_Kalman_tmp =
          Translation_Fusion_B.rtb_GPS_gain_tmp + Translation_Fusion_B.v1_tmp;
        Translation_Fusion_B.rtb_P_Kalman_c[Translation_Fusion_B.rtb_P_Kalman_tmp]
          = 0.0F;
        Translation_Fusion_B.v1_tmp += Translation_Fusion_B.rtb_GPS_gain_tmp;
        Translation_Fusion_B.rtb_P_Kalman_c[Translation_Fusion_B.rtb_P_Kalman_tmp]
          = Translation_Fusion_B.rtb_P_Kalman_c[Translation_Fusion_B.v1_tmp] +
          Translation_Fusion_B.MatrixMultiply4_l[Translation_Fusion_B.rtb_GPS_gain_tmp]
          * Translation_Fusion_P_g.MeaMatrix_Value[Translation_Fusion_B.i];
        Translation_Fusion_B.rtb_P_Kalman_c[Translation_Fusion_B.rtb_P_Kalman_tmp]
          = Translation_Fusion_B.rtb_P_Kalman_c[Translation_Fusion_B.v1_tmp] +
          Translation_Fusion_B.MatrixMultiply4_l[Translation_Fusion_B.rtb_GPS_gain_tmp
          + 4] * Translation_Fusion_P_g.MeaMatrix_Value[Translation_Fusion_B.i +
          2];
        Translation_Fusion_B.rtb_P_Kalman_c[Translation_Fusion_B.rtb_P_Kalman_tmp]
          = Translation_Fusion_B.rtb_P_Kalman_c[Translation_Fusion_B.v1_tmp] +
          Translation_Fusion_B.MatrixMultiply4_l[Translation_Fusion_B.rtb_GPS_gain_tmp
          + 8] * Translation_Fusion_P_g.MeaMatrix_Value[Translation_Fusion_B.i +
          4];
        Translation_Fusion_B.rtb_P_Kalman_c[Translation_Fusion_B.rtb_P_Kalman_tmp]
          = Translation_Fusion_B.rtb_P_Kalman_c[Translation_Fusion_B.v1_tmp] +
          Translation_Fusion_B.MatrixMultiply4_l[Translation_Fusion_B.rtb_GPS_gain_tmp
          + 12] * Translation_Fusion_P_g.MeaMatrix_Value[Translation_Fusion_B.i
          + 6];
      }
    }

    for (Translation_Fusion_B.rtb_GPS_gain_tmp = 0;
         Translation_Fusion_B.rtb_GPS_gain_tmp < 2;
         Translation_Fusion_B.rtb_GPS_gain_tmp++) {
      for (Translation_Fusion_B.i = 0; Translation_Fusion_B.i < 2;
           Translation_Fusion_B.i++) {
        Translation_Fusion_B.rtb_P_Kalman_tmp =
          Translation_Fusion_B.rtb_GPS_gain_tmp << 2;
        Translation_Fusion_B.v1_tmp = Translation_Fusion_B.rtb_GPS_gain_tmp << 1;
        Translation_Fusion_B.fv1[Translation_Fusion_B.i +
          Translation_Fusion_B.v1_tmp] =
          (((Translation_Fusion_B.rtb_P_Kalman_c[Translation_Fusion_B.rtb_P_Kalman_tmp
             + 1] *
             Translation_Fusion_P_g.MeaMatrix_Value[Translation_Fusion_B.i + 2]
             + Translation_Fusion_B.rtb_P_Kalman_c[Translation_Fusion_B.rtb_P_Kalman_tmp]
             * Translation_Fusion_P_g.MeaMatrix_Value[Translation_Fusion_B.i]) +
            Translation_Fusion_B.rtb_P_Kalman_c[Translation_Fusion_B.rtb_P_Kalman_tmp
            + 2] * Translation_Fusion_P_g.MeaMatrix_Value[Translation_Fusion_B.i
            + 4]) +
           Translation_Fusion_B.rtb_P_Kalman_c[Translation_Fusion_B.rtb_P_Kalman_tmp
           + 3] * Translation_Fusion_P_g.MeaMatrix_Value[Translation_Fusion_B.i
           + 6]) + Translation_Fusion_B.Switch2_e[Translation_Fusion_B.v1_tmp +
          Translation_Fusion_B.i];
      }
    }

    Translation_Fusion_B.fv0[0] = Translation_Fusion_B.fv1[0];
    Translation_Fusion_B.fv0[1] = Translation_Fusion_B.fv1[1];
    Translation_Fusion_B.fv0[2] = Translation_Fusion_B.fv1[2];
    Translation_Fusion_B.fv0[3] = Translation_Fusion_B.fv1[3];
    Translation_Fusi_rt_invf2x2_snf(Translation_Fusion_B.fv0,
      Translation_Fusion_B.fv1);
    for (Translation_Fusion_B.rtb_GPS_gain_tmp = 0;
         Translation_Fusion_B.rtb_GPS_gain_tmp < 4;
         Translation_Fusion_B.rtb_GPS_gain_tmp++) {
      Translation_Fusion_B.rtb_P_Kalman_c[Translation_Fusion_B.rtb_GPS_gain_tmp]
        = 0.0F;
      Translation_Fusion_B.i = Translation_Fusion_B.rtb_GPS_gain_tmp << 1;
      Translation_Fusion_B.rtb_P_Kalman_c[Translation_Fusion_B.rtb_GPS_gain_tmp]
        += Translation_Fusion_P_g.MeaMatrix_Value[Translation_Fusion_B.i] *
        Translation_Fusion_B.fv1[0];
      Translation_Fusion_B.Sqrt =
        Translation_Fusion_P_g.MeaMatrix_Value[Translation_Fusion_B.i + 1];
      Translation_Fusion_B.rtb_P_Kalman_c[Translation_Fusion_B.rtb_GPS_gain_tmp]
        += Translation_Fusion_B.Sqrt * Translation_Fusion_B.fv1[1];
      Translation_Fusion_B.rtb_P_Kalman_c[Translation_Fusion_B.rtb_GPS_gain_tmp
        + 4] = 0.0F;
      Translation_Fusion_B.rtb_P_Kalman_c[Translation_Fusion_B.rtb_GPS_gain_tmp
        + 4] +=
        Translation_Fusion_P_g.MeaMatrix_Value[Translation_Fusion_B.rtb_GPS_gain_tmp
        << 1] * Translation_Fusion_B.fv1[2];
      Translation_Fusion_B.rtb_P_Kalman_c[Translation_Fusion_B.rtb_GPS_gain_tmp
        + 4] += Translation_Fusion_B.Sqrt * Translation_Fusion_B.fv1[3];
    }

    for (Translation_Fusion_B.rtb_GPS_gain_tmp = 0;
         Translation_Fusion_B.rtb_GPS_gain_tmp < 4;
         Translation_Fusion_B.rtb_GPS_gain_tmp++) {
      for (Translation_Fusion_B.i = 0; Translation_Fusion_B.i < 2;
           Translation_Fusion_B.i++) {
        Translation_Fusion_B.v1_tmp = Translation_Fusion_B.i << 2;
        Translation_Fusion_B.rtb_P_Kalman_tmp =
          Translation_Fusion_B.rtb_GPS_gain_tmp + Translation_Fusion_B.v1_tmp;
        Translation_Fusion_B.Selector12[Translation_Fusion_B.rtb_P_Kalman_tmp] =
          0.0F;
        Translation_Fusion_B.P_RTK_tmp = Translation_Fusion_B.v1_tmp +
          Translation_Fusion_B.rtb_GPS_gain_tmp;
        Translation_Fusion_B.Selector12[Translation_Fusion_B.rtb_P_Kalman_tmp] =
          Translation_Fusion_B.Selector12[Translation_Fusion_B.P_RTK_tmp] +
          Translation_Fusion_B.rtb_P_Kalman_c[Translation_Fusion_B.v1_tmp] *
          Translation_Fusion_B.MatrixMultiply4_l[Translation_Fusion_B.rtb_GPS_gain_tmp];
        Translation_Fusion_B.Selector12[Translation_Fusion_B.rtb_P_Kalman_tmp] =
          Translation_Fusion_B.rtb_P_Kalman_c[Translation_Fusion_B.v1_tmp + 1] *
          Translation_Fusion_B.MatrixMultiply4_l[Translation_Fusion_B.rtb_GPS_gain_tmp
          + 4] + Translation_Fusion_B.Selector12[Translation_Fusion_B.P_RTK_tmp];
        Translation_Fusion_B.Selector12[Translation_Fusion_B.rtb_P_Kalman_tmp] =
          Translation_Fusion_B.rtb_P_Kalman_c[Translation_Fusion_B.v1_tmp + 2] *
          Translation_Fusion_B.MatrixMultiply4_l[Translation_Fusion_B.rtb_GPS_gain_tmp
          + 8] + Translation_Fusion_B.Selector12[Translation_Fusion_B.P_RTK_tmp];
        Translation_Fusion_B.Selector12[Translation_Fusion_B.rtb_P_Kalman_tmp] =
          Translation_Fusion_B.rtb_P_Kalman_c[Translation_Fusion_B.v1_tmp + 3] *
          Translation_Fusion_B.MatrixMultiply4_l[Translation_Fusion_B.rtb_GPS_gain_tmp
          + 12] + Translation_Fusion_B.Selector12[Translation_Fusion_B.P_RTK_tmp];
      }

      for (Translation_Fusion_B.i = 0; Translation_Fusion_B.i < 4;
           Translation_Fusion_B.i++) {
        Translation_Fusion_B.v1_tmp = Translation_Fusion_B.i << 1;
        Translation_Fusion_B.rtb_P_Kalman_tmp = Translation_Fusion_B.i << 2;
        Translation_Fusion_B.MathFunction_ej[Translation_Fusion_B.rtb_GPS_gain_tmp
          + Translation_Fusion_B.rtb_P_Kalman_tmp] =
          Translation_Fusion_B.IdentityMatrix_f[Translation_Fusion_B.rtb_P_Kalman_tmp
          + Translation_Fusion_B.rtb_GPS_gain_tmp] -
          (Translation_Fusion_P_g.MeaMatrix_Value[Translation_Fusion_B.v1_tmp +
           1] *
           Translation_Fusion_B.Selector12[Translation_Fusion_B.rtb_GPS_gain_tmp
           + 4] +
           Translation_Fusion_P_g.MeaMatrix_Value[Translation_Fusion_B.v1_tmp] *
           Translation_Fusion_B.Selector12[Translation_Fusion_B.rtb_GPS_gain_tmp]);
      }
    }

    for (Translation_Fusion_B.rtb_GPS_gain_tmp = 0;
         Translation_Fusion_B.rtb_GPS_gain_tmp < 4;
         Translation_Fusion_B.rtb_GPS_gain_tmp++) {
      for (Translation_Fusion_B.i = 0; Translation_Fusion_B.i < 4;
           Translation_Fusion_B.i++) {
        Translation_Fusion_B.v1_tmp = Translation_Fusion_B.i << 2;
        Translation_Fusion_B.rtb_P_Kalman_tmp =
          Translation_Fusion_B.rtb_GPS_gain_tmp + Translation_Fusion_B.v1_tmp;
        Translation_Fusion_B.rtb_MatrixMultiply4_l_c[Translation_Fusion_B.rtb_P_Kalman_tmp]
          = 0.0F;
        Translation_Fusion_B.v1_tmp += Translation_Fusion_B.rtb_GPS_gain_tmp;
        Translation_Fusion_B.rtb_MatrixMultiply4_l_c[Translation_Fusion_B.rtb_P_Kalman_tmp]
          =
          Translation_Fusion_B.rtb_MatrixMultiply4_l_c[Translation_Fusion_B.v1_tmp]
          + Translation_Fusion_B.MatrixMultiply4_l[Translation_Fusion_B.rtb_GPS_gain_tmp]
          * Translation_Fusion_B.MathFunction_ej[Translation_Fusion_B.i];
        Translation_Fusion_B.rtb_MatrixMultiply4_l_c[Translation_Fusion_B.rtb_P_Kalman_tmp]
          =
          Translation_Fusion_B.rtb_MatrixMultiply4_l_c[Translation_Fusion_B.v1_tmp]
          + Translation_Fusion_B.MatrixMultiply4_l[Translation_Fusion_B.rtb_GPS_gain_tmp
          + 4] * Translation_Fusion_B.MathFunction_ej[Translation_Fusion_B.i + 4];
        Translation_Fusion_B.rtb_MatrixMultiply4_l_c[Translation_Fusion_B.rtb_P_Kalman_tmp]
          =
          Translation_Fusion_B.rtb_MatrixMultiply4_l_c[Translation_Fusion_B.v1_tmp]
          + Translation_Fusion_B.MatrixMultiply4_l[Translation_Fusion_B.rtb_GPS_gain_tmp
          + 8] * Translation_Fusion_B.MathFunction_ej[Translation_Fusion_B.i + 8];
        Translation_Fusion_B.rtb_MatrixMultiply4_l_c[Translation_Fusion_B.rtb_P_Kalman_tmp]
          =
          Translation_Fusion_B.rtb_MatrixMultiply4_l_c[Translation_Fusion_B.v1_tmp]
          + Translation_Fusion_B.MatrixMultiply4_l[Translation_Fusion_B.rtb_GPS_gain_tmp
          + 12] * Translation_Fusion_B.MathFunction_ej[Translation_Fusion_B.i +
          12];
      }
    }

    for (Translation_Fusion_B.rtb_GPS_gain_tmp = 0;
         Translation_Fusion_B.rtb_GPS_gain_tmp < 2;
         Translation_Fusion_B.rtb_GPS_gain_tmp++) {
      for (Translation_Fusion_B.i = 0; Translation_Fusion_B.i < 4;
           Translation_Fusion_B.i++) {
        Translation_Fusion_B.v1_tmp = Translation_Fusion_B.i << 1;
        Translation_Fusion_B.rtb_P_Kalman_tmp =
          Translation_Fusion_B.rtb_GPS_gain_tmp + Translation_Fusion_B.v1_tmp;
        Translation_Fusion_B.rtb_P_Kalman_c[Translation_Fusion_B.rtb_P_Kalman_tmp]
          = 0.0F;
        Translation_Fusion_B.v1_tmp += Translation_Fusion_B.rtb_GPS_gain_tmp;
        Translation_Fusion_B.rtb_P_Kalman_c[Translation_Fusion_B.rtb_P_Kalman_tmp]
          = Translation_Fusion_B.rtb_P_Kalman_c[Translation_Fusion_B.v1_tmp] +
          Translation_Fusion_B.Switch2_e[Translation_Fusion_B.rtb_GPS_gain_tmp] *
          Translation_Fusion_B.Selector12[Translation_Fusion_B.i];
        Translation_Fusion_B.rtb_P_Kalman_c[Translation_Fusion_B.rtb_P_Kalman_tmp]
          = Translation_Fusion_B.rtb_P_Kalman_c[Translation_Fusion_B.v1_tmp] +
          Translation_Fusion_B.Switch2_e[Translation_Fusion_B.rtb_GPS_gain_tmp +
          2] * Translation_Fusion_B.Selector12[Translation_Fusion_B.i + 4];
      }
    }

    for (Translation_Fusion_B.rtb_GPS_gain_tmp = 0;
         Translation_Fusion_B.rtb_GPS_gain_tmp < 4;
         Translation_Fusion_B.rtb_GPS_gain_tmp++) {
      for (Translation_Fusion_B.i = 0; Translation_Fusion_B.i < 4;
           Translation_Fusion_B.i++) {
        Translation_Fusion_B.v1_tmp = Translation_Fusion_B.rtb_GPS_gain_tmp << 2;
        Translation_Fusion_B.rtb_P_Kalman_tmp = Translation_Fusion_B.i +
          Translation_Fusion_B.v1_tmp;
        Translation_Fusion_B.MatrixMultiply4_l[Translation_Fusion_B.rtb_P_Kalman_tmp]
          = 0.0F;
        Translation_Fusion_B.P_RTK_tmp = Translation_Fusion_B.v1_tmp +
          Translation_Fusion_B.i;
        Translation_Fusion_B.MatrixMultiply4_l[Translation_Fusion_B.rtb_P_Kalman_tmp]
          =
          Translation_Fusion_B.MatrixMultiply4_l[Translation_Fusion_B.P_RTK_tmp]
          + Translation_Fusion_B.rtb_MatrixMultiply4_l_c[Translation_Fusion_B.v1_tmp]
          * Translation_Fusion_B.MathFunction_ej[Translation_Fusion_B.i];
        Translation_Fusion_B.MatrixMultiply4_l[Translation_Fusion_B.rtb_P_Kalman_tmp]
          =
          Translation_Fusion_B.rtb_MatrixMultiply4_l_c[Translation_Fusion_B.v1_tmp
          + 1] * Translation_Fusion_B.MathFunction_ej[Translation_Fusion_B.i + 4]
          + Translation_Fusion_B.MatrixMultiply4_l[Translation_Fusion_B.P_RTK_tmp];
        Translation_Fusion_B.MatrixMultiply4_l[Translation_Fusion_B.rtb_P_Kalman_tmp]
          =
          Translation_Fusion_B.rtb_MatrixMultiply4_l_c[Translation_Fusion_B.v1_tmp
          + 2] * Translation_Fusion_B.MathFunction_ej[Translation_Fusion_B.i + 8]
          + Translation_Fusion_B.MatrixMultiply4_l[Translation_Fusion_B.P_RTK_tmp];
        Translation_Fusion_B.MatrixMultiply4_l[Translation_Fusion_B.rtb_P_Kalman_tmp]
          =
          Translation_Fusion_B.rtb_MatrixMultiply4_l_c[Translation_Fusion_B.v1_tmp
          + 3] * Translation_Fusion_B.MathFunction_ej[Translation_Fusion_B.i +
          12] +
          Translation_Fusion_B.MatrixMultiply4_l[Translation_Fusion_B.P_RTK_tmp];
        Translation_Fusion_B.rtb_Selector12_k[Translation_Fusion_B.rtb_P_Kalman_tmp]
          = 0.0F;
        Translation_Fusion_B.v1_tmp = Translation_Fusion_B.rtb_GPS_gain_tmp << 1;
        Translation_Fusion_B.rtb_Selector12_k[Translation_Fusion_B.rtb_P_Kalman_tmp]
          = Translation_Fusion_B.rtb_Selector12_k[Translation_Fusion_B.P_RTK_tmp]
          + Translation_Fusion_B.rtb_P_Kalman_c[Translation_Fusion_B.v1_tmp] *
          Translation_Fusion_B.Selector12[Translation_Fusion_B.i];
        Translation_Fusion_B.rtb_Selector12_k[Translation_Fusion_B.rtb_P_Kalman_tmp]
          = Translation_Fusion_B.rtb_P_Kalman_c[Translation_Fusion_B.v1_tmp + 1]
          * Translation_Fusion_B.Selector12[Translation_Fusion_B.i + 4] +
          Translation_Fusion_B.rtb_Selector12_k[Translation_Fusion_B.P_RTK_tmp];
      }
    }

    for (Translation_Fusion_B.rtb_GPS_gain_tmp = 0;
         Translation_Fusion_B.rtb_GPS_gain_tmp < 16;
         Translation_Fusion_B.rtb_GPS_gain_tmp++) {
      Translation_Fusion_B.Add[Translation_Fusion_B.rtb_GPS_gain_tmp] =
        Translation_Fusion_B.MatrixMultiply4_l[Translation_Fusion_B.rtb_GPS_gain_tmp]
        + Translation_Fusion_B.rtb_Selector12_k[Translation_Fusion_B.rtb_GPS_gain_tmp];
    }

    for (Translation_Fusion_B.rtb_GPS_gain_tmp = 0;
         Translation_Fusion_B.rtb_GPS_gain_tmp < 2;
         Translation_Fusion_B.rtb_GPS_gain_tmp++) {
      Translation_Fusion_B.rtb_DataTypeConversion4_n[Translation_Fusion_B.rtb_GPS_gain_tmp]
        =
        Translation_Fusion_B.DataTypeConversion4[Translation_Fusion_B.rtb_GPS_gain_tmp]
        - (((Translation_Fusion_P_g.MeaMatrix_Value[Translation_Fusion_B.rtb_GPS_gain_tmp
             + 2] * Translation_Fusion_B.ManualSwitch[3] +
             Translation_Fusion_P_g.MeaMatrix_Value[Translation_Fusion_B.rtb_GPS_gain_tmp]
             * Translation_Fusion_B.ManualSwitch[2]) +
            Translation_Fusion_P_g.MeaMatrix_Value[Translation_Fusion_B.rtb_GPS_gain_tmp
            + 4] * Translation_Fusion_B.ManualSwitch[4]) +
           Translation_Fusion_P_g.MeaMatrix_Value[Translation_Fusion_B.rtb_GPS_gain_tmp
           + 6] * Translation_Fusion_B.ManualSwitch[5]);
    }

    for (Translation_Fusion_B.i = 0; Translation_Fusion_B.i < 4;
         Translation_Fusion_B.i++) {
      Translation_Fusion_B.MatrixMultiply1_j[Translation_Fusion_B.i] = 0.0F;
      Translation_Fusion_DW.Delay_DSTATE_ko[Translation_Fusion_B.i] =
        Translation_Fusion_B.Selector13[Translation_Fusion_B.i];
      Translation_Fusion_B.MatrixMultiply1_j[Translation_Fusion_B.i] +=
        Translation_Fusion_B.Selector12[Translation_Fusion_B.i] *
        Translation_Fusion_B.rtb_DataTypeConversion4_n[0];
      Translation_Fusion_B.rtb_GPS_gain_tmp = (Translation_Fusion_B.i + 1) << 1;
      Translation_Fusion_B.v1_tmp = Translation_Fusion_B.i << 1;
      Translation_Fusion_DW.Delay1_DSTATE_gi[Translation_Fusion_B.v1_tmp] =
        Translation_Fusion_DW.Delay1_DSTATE_gi[Translation_Fusion_B.rtb_GPS_gain_tmp];
      Translation_Fusion_B.MatrixMultiply1_j[Translation_Fusion_B.i] +=
        Translation_Fusion_B.Selector12[Translation_Fusion_B.i + 4] *
        Translation_Fusion_B.rtb_DataTypeConversion4_n[1];
      Translation_Fusion_DW.Delay1_DSTATE_gi[Translation_Fusion_B.v1_tmp + 1] =
        Translation_Fusion_DW.Delay1_DSTATE_gi[Translation_Fusion_B.rtb_GPS_gain_tmp
        + 1];
      Translation_Fusion_B.v1_tmp = Translation_Fusion_B.i << 2;
      Translation_Fusion_B.rtb_P_Kalman_tmp = 6 * (2 + Translation_Fusion_B.i);
      Translation_Fusion_B.P_Kalman[2 + Translation_Fusion_B.rtb_P_Kalman_tmp] =
        Translation_Fusion_B.Add[Translation_Fusion_B.v1_tmp];
      Translation_Fusion_B.P_Kalman[3 + Translation_Fusion_B.rtb_P_Kalman_tmp] =
        Translation_Fusion_B.Add[Translation_Fusion_B.v1_tmp + 1];
      Translation_Fusion_B.P_Kalman[4 + Translation_Fusion_B.rtb_P_Kalman_tmp] =
        Translation_Fusion_B.Add[Translation_Fusion_B.v1_tmp + 2];
      Translation_Fusion_B.P_Kalman[5 + Translation_Fusion_B.rtb_P_Kalman_tmp] =
        Translation_Fusion_B.Add[Translation_Fusion_B.v1_tmp + 3];
    }

    Translation_Fusion_DW.Delay1_DSTATE_gi[8] = Translation_Fusion_B.vel_xy_GPS
      [0];
    Translation_Fusion_DW.Delay1_DSTATE_gi[9] = Translation_Fusion_B.vel_xy_GPS
      [1];
  } else {
    for (Translation_Fusion_B.rtb_GPS_gain_tmp = 0;
         Translation_Fusion_B.rtb_GPS_gain_tmp < 4;
         Translation_Fusion_B.rtb_GPS_gain_tmp++) {
      Translation_Fusion_B.v1_tmp = Translation_Fusion_B.rtb_GPS_gain_tmp << 2;
      Translation_Fusion_B.rtb_P_Kalman_tmp = 6 * (2 +
        Translation_Fusion_B.rtb_GPS_gain_tmp);
      Translation_Fusion_B.P_Kalman[2 + Translation_Fusion_B.rtb_P_Kalman_tmp] =
        Translation_Fusion_B.MatrixMultiply4_l[Translation_Fusion_B.v1_tmp];
      Translation_Fusion_B.P_Kalman[3 + Translation_Fusion_B.rtb_P_Kalman_tmp] =
        Translation_Fusion_B.MatrixMultiply4_l[Translation_Fusion_B.v1_tmp + 1];
      Translation_Fusion_B.P_Kalman[4 + Translation_Fusion_B.rtb_P_Kalman_tmp] =
        Translation_Fusion_B.MatrixMultiply4_l[Translation_Fusion_B.v1_tmp + 2];
      Translation_Fusion_B.P_Kalman[5 + Translation_Fusion_B.rtb_P_Kalman_tmp] =
        Translation_Fusion_B.MatrixMultiply4_l[Translation_Fusion_B.v1_tmp + 3];
    }
  }

  Translation_Fusion_B.Assignment[0] = Translation_Fusion_B.ManualSwitch[0];
  Translation_Fusion_B.Assignment[1] = Translation_Fusion_B.ManualSwitch[1];
  if (Translation_Fusion_B.En_GPS_Correct_RTK ||
      (Translation_Fusion_DW.DiscreteTimeIntegrator_Prev_jgs != 0)) {
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_oy =
      Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_f2;
  }

  Translation_Fusion_B.LogicalOperator1_ks =
    (Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_oy >=
     Translation_Fusion_P_g.CompareToConstant_const_br);
  Translation_Fusion_B.Subtract1_k[0] = Translation_Fusion_P_g.Gain_Gain_pc *
    Translation_Fusion_B.MatrixMultiply1_j[0];
  Translation_Fusion_B.Subtract1_k[1] = Translation_Fusion_P_g.Gain_Gain_pc *
    Translation_Fusion_B.MatrixMultiply1_j[1];
  if (Translation_Fusion_DW.DiscreteTimeIntegrator_IC_LOA_h != 0) {
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_cf =
      Translation_Fusion_B.Subtract1_k[0];
  }

  Translation_Fusion_B.DiscreteTimeIntegrator_jc =
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_cf;
  if (Translation_Fusion_DW.DiscreteTimeIntegrator_IC_LO_oj != 0) {
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_mo =
      Translation_Fusion_B.Subtract1_k[1];
  }

  Translation_Fusion_B.DiscreteTimeIntegrator_j1z =
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_mo;
  if (Translation_Fusion_B.LogicalOperator1_ks) {
    Translation_Fusion_B.GPS_gain = Translation_Fusion_P_g.Constant1_Value_b;
  } else {
    Translation_Fusion_B.GPS_gain =
      Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_cf;
  }

  Translation_Fusion_B.Assignment[2] = Translation_Fusion_B.ManualSwitch[2] +
    Translation_Fusion_B.GPS_gain;
  if (Translation_Fusion_B.LogicalOperator1_ks) {
    Translation_Fusion_B.GPS_gain = Translation_Fusion_P_g.Constant1_Value_b;
  } else {
    Translation_Fusion_B.GPS_gain =
      Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_mo;
  }

  Translation_Fusion_B.Assignment[3] = Translation_Fusion_B.ManualSwitch[3] +
    Translation_Fusion_B.GPS_gain;
  if (Translation_Fusion_B.LogicalOperator1_ks) {
    Translation_Fusion_B.GPS_gain = Translation_Fusion_P_g.Constant1_Value_b;
  } else {
    Translation_Fusion_B.GPS_gain = Translation_Fusion_P_g.Gain_Gain_pc *
      Translation_Fusion_B.MatrixMultiply1_j[2];
  }

  Translation_Fusion_B.Assignment[4] = Translation_Fusion_B.ManualSwitch[4] +
    Translation_Fusion_B.GPS_gain;
  if (Translation_Fusion_B.LogicalOperator1_ks) {
    Translation_Fusion_B.GPS_gain = Translation_Fusion_P_g.Constant1_Value_b;
  } else {
    Translation_Fusion_B.GPS_gain = Translation_Fusion_P_g.Gain_Gain_pc *
      Translation_Fusion_B.MatrixMultiply1_j[3];
  }

  Translation_Fusion_B.Assignment[5] = Translation_Fusion_B.ManualSwitch[5] +
    Translation_Fusion_B.GPS_gain;
  for (Translation_Fusion_B.rtb_GPS_gain_tmp = 0;
       Translation_Fusion_B.rtb_GPS_gain_tmp < 4;
       Translation_Fusion_B.rtb_GPS_gain_tmp++) {
    Translation_Fusion_B.v1_tmp = (2 + Translation_Fusion_B.rtb_GPS_gain_tmp) *
      6;
    Translation_Fusion_B.rtb_P_Kalman_tmp =
      Translation_Fusion_B.rtb_GPS_gain_tmp << 2;
    Translation_Fusion_B.MatrixMultiply4_l[Translation_Fusion_B.rtb_P_Kalman_tmp]
      = Translation_Fusion_B.P_Kalman[Translation_Fusion_B.v1_tmp + 2];
    Translation_Fusion_B.MatrixMultiply4_l[1 +
      Translation_Fusion_B.rtb_P_Kalman_tmp] =
      Translation_Fusion_B.P_Kalman[Translation_Fusion_B.v1_tmp + 3];
    Translation_Fusion_B.MatrixMultiply4_l[2 +
      Translation_Fusion_B.rtb_P_Kalman_tmp] =
      Translation_Fusion_B.P_Kalman[Translation_Fusion_B.v1_tmp + 4];
    Translation_Fusion_B.MatrixMultiply4_l[3 +
      Translation_Fusion_B.rtb_P_Kalman_tmp] =
      Translation_Fusion_B.P_Kalman[Translation_Fusion_B.v1_tmp + 5];
  }

  Translation_Fusi_MovingAverage1(rty_Translation_data_ACC_xy_O_m[0],
    &Translation_Fusion_B.MovingAverage_pn,
    &Translation_Fusion_DW.MovingAverage_pn);
  Translation_Fusi_MovingAverage1(rty_Translation_data_ACC_xy_O_m[1],
    &Translation_Fusion_B.MovingAverage1_pn,
    &Translation_Fusion_DW.MovingAverage1_pn);
  Translation_Fusion_B.Min_h[0] =
    Translation_Fusion_P_g.ust_orderdelaycompensator1_N_a *
    Translation_Fusion_B.MovingAverage_pn.MovingAverage1;
  Translation_Fusion_B.Min_h[1] =
    Translation_Fusion_P_g.ust_orderdelaycompensator1_N_a *
    Translation_Fusion_B.MovingAverage1_pn.MovingAverage1;
  Translation_Fusion_B.LogicalOperator2_hv = (*rtu_Sensor_Vision_data_type ==
    Translation_Fusion_P_g.CompareToConstant1_const_d);
  Translation_Fu_MovingAverage1_p(rty_Translation_data_ACC_xy_O_m[0],
    &Translation_Fusion_B.MovingAverage_pna,
    &Translation_Fusion_DW.MovingAverage_pna);
  Translation_Fu_MovingAverage1_p(rty_Translation_data_ACC_xy_O_m[1],
    &Translation_Fusion_B.MovingAverage1_pna,
    &Translation_Fusion_DW.MovingAverage1_pna);
  if (Translation_Fusion_B.LogicalOperator2_hv) {
    Translation_Fusion_B.Min_h[0] = Translation_Fusion_P_g.SampleTime_WtEt_l *
      Translation_Fusion_B.Min_h[0] + rtu_Sensor_Vision_data_vel_xy_O[0];
    Translation_Fusion_B.Min_h[1] = Translation_Fusion_P_g.SampleTime_WtEt_l *
      Translation_Fusion_B.Min_h[1] + rtu_Sensor_Vision_data_vel_xy_O[1];
  } else {
    Translation_Fusion_B.Min_h[0] =
      Translation_Fusion_P_g.ust_orderdelaycompensator1_N_e *
      Translation_Fusion_B.MovingAverage_pna.MovingAverage1 *
      Translation_Fusion_P_g.SampleTime_WtEt + rtu_Sensor_Vision_data_vel_xy_O[0];
    Translation_Fusion_B.Min_h[1] =
      Translation_Fusion_P_g.ust_orderdelaycompensator1_N_e *
      Translation_Fusion_B.MovingAverage1_pna.MovingAverage1 *
      Translation_Fusion_P_g.SampleTime_WtEt + rtu_Sensor_Vision_data_vel_xy_O[1];
  }

  if (*rtu_Sensor_Vision_data_Vision_q >
      Translation_Fusion_P_g.Saturation_UpperSat_n3) {
    Translation_Fusion_B.GPS_gain =
      Translation_Fusion_P_g.Saturation_UpperSat_n3;
  } else if (*rtu_Sensor_Vision_data_Vision_q <
             Translation_Fusion_P_g.Saturation_LowerSat_i) {
    Translation_Fusion_B.GPS_gain = Translation_Fusion_P_g.Saturation_LowerSat_i;
  } else {
    Translation_Fusion_B.GPS_gain = *rtu_Sensor_Vision_data_Vision_q;
  }

  if (*rtu_Sensor_Vision_data_type ==
      Translation_Fusion_P_g.CompareToConstant6_const_f) {
    Translation_Fusion_B.Sum_ol = Translation_Fusion_P_g.indoor7_Value;
  } else if (Translation_Fusion_B.Compare_j || ((real32_T)fabs
              (Translation_Fusion_B.MatrixMultiply4_a[1]) <
              Translation_Fusion_P_g.CompareToConstant1_const_o)) {
    Translation_Fusion_B.Sum_ol = Translation_Fusion_P_g.xy_fusion_sgm_vel_VO;
  } else {
    Translation_Fusion_B.Sum_ol = Translation_Fusion_P_g.indoor4_Value;
  }

  Translation_Fusion_B.GPS_gain = 1.0F / (Translation_Fusion_B.GPS_gain *
    Translation_Fusion_B.GPS_gain) * Translation_Fusion_B.Sum_ol;
  Translation_Fusion_B.GPS_gain *= Translation_Fusion_B.GPS_gain;
  if (Translation_Fusion_B.Compare_l0) {
    Translation_Fusion_B.Selector13[0] =
      Translation_Fusion_P_g.Constant4_Value_g[0];
    Translation_Fusion_B.Selector13[1] =
      Translation_Fusion_P_g.Constant4_Value_g[1];
    Translation_Fusion_B.Selector13[2] =
      Translation_Fusion_P_g.Constant4_Value_g[2];
    Translation_Fusion_B.Selector13[3] =
      Translation_Fusion_P_g.Constant4_Value_g[3];
  } else if (Translation_Fusion_B.Compare_h) {
    Translation_Fusion_B.Selector13[0] =
      Translation_Fusion_P_g.Constant1_Value_b0[0];
    Translation_Fusion_B.Selector13[1] =
      Translation_Fusion_P_g.Constant1_Value_b0[1];
    Translation_Fusion_B.Selector13[2] =
      Translation_Fusion_P_g.Constant1_Value_b0[2];
    Translation_Fusion_B.Selector13[3] =
      Translation_Fusion_P_g.Constant1_Value_b0[3];
  } else if ((Translation_Fusion_B.MatrixMultiply4_a[0] <=
              Translation_Fusion_P_g.CompareToConstant_const_m) &&
             (*rtu_forcedArm)) {
    Translation_Fusion_B.Selector13[0] =
      Translation_Fusion_P_g.Constant2_Value_o[0];
    Translation_Fusion_B.Selector13[1] =
      Translation_Fusion_P_g.Constant2_Value_o[1];
    Translation_Fusion_B.Selector13[2] =
      Translation_Fusion_P_g.Constant2_Value_o[2];
    Translation_Fusion_B.Selector13[3] =
      Translation_Fusion_P_g.Constant2_Value_o[3];
  } else {
    Translation_Fusion_B.Selector13[0] =
      Translation_Fusion_P_g.Constant3_Value_c[0];
    Translation_Fusion_B.Selector13[1] =
      Translation_Fusion_P_g.Constant3_Value_c[1];
    Translation_Fusion_B.Selector13[2] =
      Translation_Fusion_P_g.Constant3_Value_c[2];
    Translation_Fusion_B.Selector13[3] =
      Translation_Fusion_P_g.Constant3_Value_c[3];
  }

  if (Translation_Fusion_DW.DiscreteTimeIntegrator_IC_LO_fm != 0) {
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_jh[0] =
      Translation_Fusion_B.Selector13[0];
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_jh[1] =
      Translation_Fusion_B.Selector13[1];
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_jh[2] =
      Translation_Fusion_B.Selector13[2];
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_jh[3] =
      Translation_Fusion_B.Selector13[3];
  }

  Translation_Fusion_B.CreateDiagonalMatrix_jk[0] =
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_jh[0];
  Translation_Fusion_B.Product_nu[0] = Translation_Fusion_B.GPS_gain *
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_jh[0];
  Translation_Fusion_B.CreateDiagonalMatrix_jk[1] =
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_jh[1];
  Translation_Fusion_B.Product_nu[1] = Translation_Fusion_B.GPS_gain *
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_jh[1];
  Translation_Fusion_B.CreateDiagonalMatrix_jk[2] =
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_jh[2];
  Translation_Fusion_B.Product_nu[2] = Translation_Fusion_B.GPS_gain *
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_jh[2];
  Translation_Fusion_B.CreateDiagonalMatrix_jk[3] =
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_jh[3];
  Translation_Fusion_B.Product_nu[3] = Translation_Fusion_B.GPS_gain *
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_jh[3];
  Translation_Fusion_B.GPS_gain = rtu_Sensor_RTK_Data_vel_quality[0];
  if ((!(rtu_Sensor_RTK_Data_vel_quality[0] < rtu_Sensor_RTK_Data_vel_quality[1]))
      && (!Translation_Fusion_B.rtb_LogicalOperator1_ls_idx_1)) {
    Translation_Fusion_B.GPS_gain = rtu_Sensor_RTK_Data_vel_quality[1];
  }

  *rty_RTK_Pos_Good = (*rtu_Sensor_RTK_Data_rtk_type >=
                       Translation_Fusion_P_g.CompareToConstant7_const);
  Translation_Fusion_B.rtk_pos_valid = ((Translation_Fusion_B.GPS_gain >=
    Translation_Fusion_P_g.CompareToConstant10_const_l) && (*rty_RTK_Pos_Good));
  if (Translation_Fusion_B.Compare_j) {
    Translation_Fusion_B.GPS_gain = Translation_Fusion_P_g.indoor2_Value;
  } else if ((*rtu_Sensor_RTK_Data_rtk_type >=
              Translation_Fusion_P_g.CompareToConstant8_const) ||
             Translation_Fusion_B.Compare_h) {
    if (Translation_Fusion_B.rtk_pos_valid || Translation_Fusion_B.Compare_l0) {
      Translation_Fusion_B.GPS_gain = Translation_Fusion_P_g.indoor6_Value;
    } else {
      Translation_Fusion_B.GPS_gain = Translation_Fusion_P_g.indoor5_Value;
    }
  } else {
    Translation_Fusion_B.GPS_gain = Translation_Fusion_P_g.indoor3_Value;
  }

  Translation_Fusion_B.Compare_l0 = ((*rtu_Sensor_Vision_data_Vision_q >=
    Translation_Fusion_B.GPS_gain) && (*rtu_Sensor_Vision_data_timestam >
    Translation_Fusion_DW.DelayInput1_DSTATE_p1) &&
    Translation_Fusion_B.LogicalOperator2_g);
  if (Translation_Fusion_B.Compare_l0) {
    for (Translation_Fusion_B.rtb_GPS_gain_tmp = 0;
         Translation_Fusion_B.rtb_GPS_gain_tmp < 2;
         Translation_Fusion_B.rtb_GPS_gain_tmp++) {
      Translation_Fusion_B.vel_xy_GPS[Translation_Fusion_B.rtb_GPS_gain_tmp] =
        Translation_Fusion_B.Min_h[Translation_Fusion_B.rtb_GPS_gain_tmp] -
        (((Translation_Fusion_P_g.MeaMatrix_Value_k[Translation_Fusion_B.rtb_GPS_gain_tmp
           + 2] * Translation_Fusion_B.Assignment[3] +
           Translation_Fusion_P_g.MeaMatrix_Value_k[Translation_Fusion_B.rtb_GPS_gain_tmp]
           * Translation_Fusion_B.Assignment[2]) +
          Translation_Fusion_P_g.MeaMatrix_Value_k[Translation_Fusion_B.rtb_GPS_gain_tmp
          + 4] * Translation_Fusion_B.Assignment[4]) +
         Translation_Fusion_P_g.MeaMatrix_Value_k[Translation_Fusion_B.rtb_GPS_gain_tmp
         + 6] * Translation_Fusion_B.Assignment[5]);
    }

    Translation_Fusion_B.Subtract1_c[0] = (Translation_Fusion_B.vel_xy_GPS[0] *
      Translation_Fusion_B.vel_xy_GPS[0] +
      Translation_Fusion_DW.Delay_DSTATE_fh[0]) -
      Translation_Fusion_DW.Delay1_DSTATE_j[0] *
      Translation_Fusion_DW.Delay1_DSTATE_j[0];
    Translation_Fusion_B.Subtract1_c[1] = (Translation_Fusion_B.vel_xy_GPS[1] *
      Translation_Fusion_B.vel_xy_GPS[0] +
      Translation_Fusion_DW.Delay_DSTATE_fh[1]) -
      Translation_Fusion_DW.Delay1_DSTATE_j[1] *
      Translation_Fusion_DW.Delay1_DSTATE_j[0];
    Translation_Fusion_B.Subtract1_c[2] = (Translation_Fusion_B.vel_xy_GPS[0] *
      Translation_Fusion_B.vel_xy_GPS[1] +
      Translation_Fusion_DW.Delay_DSTATE_fh[2]) -
      Translation_Fusion_DW.Delay1_DSTATE_j[0] *
      Translation_Fusion_DW.Delay1_DSTATE_j[1];
    Translation_Fusion_B.Subtract1_c[3] = (Translation_Fusion_B.vel_xy_GPS[1] *
      Translation_Fusion_B.vel_xy_GPS[1] +
      Translation_Fusion_DW.Delay_DSTATE_fh[3]) -
      Translation_Fusion_DW.Delay1_DSTATE_j[1] *
      Translation_Fusion_DW.Delay1_DSTATE_j[1];
    Translation_Fusi_rt_invf2x2_snf(Translation_Fusion_B.Product_nu,
      Translation_Fusion_B.Switch2_e);
    mw_arm_sqrt_f32(Translation_Fusion_B.Assignment[2] *
                    Translation_Fusion_B.Assignment[2] +
                    Translation_Fusion_B.Assignment[3] *
                    Translation_Fusion_B.Assignment[3],
                    &Translation_Fusion_B.Sum_ol);
    if (((Translation_Fusion_B.Switch2_e[0] * Translation_Fusion_B.vel_xy_GPS[0]
          + Translation_Fusion_B.Switch2_e[2] * Translation_Fusion_B.vel_xy_GPS
          [1]) * Translation_Fusion_B.vel_xy_GPS[0] +
         (Translation_Fusion_B.Switch2_e[1] * Translation_Fusion_B.vel_xy_GPS[0]
          + Translation_Fusion_B.Switch2_e[3] * Translation_Fusion_B.vel_xy_GPS
          [1]) * Translation_Fusion_B.vel_xy_GPS[1] >
         Translation_Fusion_P_g.AdaptiveVOVelocityCorrection_ka) ||
        (Translation_Fusion_B.Sum_ol <=
         Translation_Fusion_P_g.CompareToConstant1_const)) {
      for (Translation_Fusion_B.rtb_GPS_gain_tmp = 0;
           Translation_Fusion_B.rtb_GPS_gain_tmp < 4;
           Translation_Fusion_B.rtb_GPS_gain_tmp++) {
        for (Translation_Fusion_B.i = 0; Translation_Fusion_B.i < 2;
             Translation_Fusion_B.i++) {
          Translation_Fusion_B.v1_tmp = Translation_Fusion_B.i << 2;
          Translation_Fusion_B.rtb_P_Kalman_tmp =
            Translation_Fusion_B.rtb_GPS_gain_tmp + Translation_Fusion_B.v1_tmp;
          Translation_Fusion_B.rtb_P_Kalman_c[Translation_Fusion_B.rtb_P_Kalman_tmp]
            = 0.0F;
          Translation_Fusion_B.v1_tmp += Translation_Fusion_B.rtb_GPS_gain_tmp;
          Translation_Fusion_B.rtb_P_Kalman_c[Translation_Fusion_B.rtb_P_Kalman_tmp]
            = Translation_Fusion_B.rtb_P_Kalman_c[Translation_Fusion_B.v1_tmp] +
            Translation_Fusion_B.MatrixMultiply4_l[Translation_Fusion_B.rtb_GPS_gain_tmp]
            * Translation_Fusion_P_g.MeaMatrix_Value_k[Translation_Fusion_B.i];
          Translation_Fusion_B.rtb_P_Kalman_c[Translation_Fusion_B.rtb_P_Kalman_tmp]
            = Translation_Fusion_B.rtb_P_Kalman_c[Translation_Fusion_B.v1_tmp] +
            Translation_Fusion_B.MatrixMultiply4_l[Translation_Fusion_B.rtb_GPS_gain_tmp
            + 4] *
            Translation_Fusion_P_g.MeaMatrix_Value_k[Translation_Fusion_B.i + 2];
          Translation_Fusion_B.rtb_P_Kalman_c[Translation_Fusion_B.rtb_P_Kalman_tmp]
            = Translation_Fusion_B.rtb_P_Kalman_c[Translation_Fusion_B.v1_tmp] +
            Translation_Fusion_B.MatrixMultiply4_l[Translation_Fusion_B.rtb_GPS_gain_tmp
            + 8] *
            Translation_Fusion_P_g.MeaMatrix_Value_k[Translation_Fusion_B.i + 4];
          Translation_Fusion_B.rtb_P_Kalman_c[Translation_Fusion_B.rtb_P_Kalman_tmp]
            = Translation_Fusion_B.rtb_P_Kalman_c[Translation_Fusion_B.v1_tmp] +
            Translation_Fusion_B.MatrixMultiply4_l[Translation_Fusion_B.rtb_GPS_gain_tmp
            + 12] *
            Translation_Fusion_P_g.MeaMatrix_Value_k[Translation_Fusion_B.i + 6];
        }
      }

      for (Translation_Fusion_B.rtb_GPS_gain_tmp = 0;
           Translation_Fusion_B.rtb_GPS_gain_tmp < 2;
           Translation_Fusion_B.rtb_GPS_gain_tmp++) {
        for (Translation_Fusion_B.i = 0; Translation_Fusion_B.i < 2;
             Translation_Fusion_B.i++) {
          Translation_Fusion_B.rtb_P_Kalman_tmp = Translation_Fusion_B.i << 2;
          Translation_Fusion_B.v1_tmp = Translation_Fusion_B.i << 1;
          Translation_Fusion_B.fv0[Translation_Fusion_B.rtb_GPS_gain_tmp +
            Translation_Fusion_B.v1_tmp] =
            Translation_Fusion_B.Subtract1_c[Translation_Fusion_B.v1_tmp +
            Translation_Fusion_B.rtb_GPS_gain_tmp] *
            Translation_Fusion_P_g.Gain_Gain_l5 -
            (((Translation_Fusion_B.rtb_P_Kalman_c[Translation_Fusion_B.rtb_P_Kalman_tmp
               + 1] *
               Translation_Fusion_P_g.MeaMatrix_Value_k[Translation_Fusion_B.rtb_GPS_gain_tmp
               + 2] +
               Translation_Fusion_B.rtb_P_Kalman_c[Translation_Fusion_B.rtb_P_Kalman_tmp]
               * Translation_Fusion_P_g.MeaMatrix_Value_k[Translation_Fusion_B.rtb_GPS_gain_tmp])
              + Translation_Fusion_B.rtb_P_Kalman_c[Translation_Fusion_B.rtb_P_Kalman_tmp
              + 2] *
              Translation_Fusion_P_g.MeaMatrix_Value_k[Translation_Fusion_B.rtb_GPS_gain_tmp
              + 4]) +
             Translation_Fusion_B.rtb_P_Kalman_c[Translation_Fusion_B.rtb_P_Kalman_tmp
             + 3] *
             Translation_Fusion_P_g.MeaMatrix_Value_k[Translation_Fusion_B.rtb_GPS_gain_tmp
             + 6]);
        }

        Translation_Fusion_B.CreateDiagonalMatrix_n[Translation_Fusion_B.rtb_GPS_gain_tmp]
          = 0.0F;
        Translation_Fusion_B.CreateDiagonalMatrix_n[Translation_Fusion_B.rtb_GPS_gain_tmp]
          += Translation_Fusion_B.fv0[Translation_Fusion_B.rtb_GPS_gain_tmp] *
          Translation_Fusion_B.Switch2_e[0];
        Translation_Fusion_B.rtb_Min_c_idx_0 =
          Translation_Fusion_B.fv0[Translation_Fusion_B.rtb_GPS_gain_tmp + 2];
        Translation_Fusion_B.CreateDiagonalMatrix_n[Translation_Fusion_B.rtb_GPS_gain_tmp]
          += Translation_Fusion_B.rtb_Min_c_idx_0 *
          Translation_Fusion_B.Switch2_e[1];
        Translation_Fusion_B.CreateDiagonalMatrix_n[Translation_Fusion_B.rtb_GPS_gain_tmp
          + 2] = 0.0F;
        Translation_Fusion_B.CreateDiagonalMatrix_n[Translation_Fusion_B.rtb_GPS_gain_tmp
          + 2] += Translation_Fusion_B.fv0[Translation_Fusion_B.rtb_GPS_gain_tmp]
          * Translation_Fusion_B.Switch2_e[2];
        Translation_Fusion_B.CreateDiagonalMatrix_n[Translation_Fusion_B.rtb_GPS_gain_tmp
          + 2] += Translation_Fusion_B.rtb_Min_c_idx_0 *
          Translation_Fusion_B.Switch2_e[3];
      }

      Translation_Fusion_B.GPS_gain =
        Translation_Fusion_B.CreateDiagonalMatrix_n[0];
      Translation_Fusion_B.rtb_LogicalOperator1_ls_idx_1 = rtIsNaNF
        (Translation_Fusion_P_g.Constant_Value_lh);
      if ((!(Translation_Fusion_B.CreateDiagonalMatrix_n[0] >
             Translation_Fusion_P_g.Constant_Value_lh)) &&
          (!Translation_Fusion_B.rtb_LogicalOperator1_ls_idx_1)) {
        Translation_Fusion_B.GPS_gain = Translation_Fusion_P_g.Constant_Value_lh;
      }

      Translation_Fusion_B.Compare_ko = rtIsNaNF
        (Translation_Fusion_P_g.AdaptiveVOVelocityCorrection_ma);
      if ((!(Translation_Fusion_B.GPS_gain <
             Translation_Fusion_P_g.AdaptiveVOVelocityCorrection_ma)) &&
          (!Translation_Fusion_B.Compare_ko)) {
        Translation_Fusion_B.GPS_gain =
          Translation_Fusion_P_g.AdaptiveVOVelocityCorrection_ma;
      }

      Translation_Fusion_B.rtb_Min_c_idx_0 = Translation_Fusion_B.GPS_gain;
      Translation_Fusion_B.GPS_gain =
        Translation_Fusion_B.CreateDiagonalMatrix_n[3];
      if ((!(Translation_Fusion_B.CreateDiagonalMatrix_n[3] >
             Translation_Fusion_P_g.Constant_Value_lh)) &&
          (!Translation_Fusion_B.rtb_LogicalOperator1_ls_idx_1)) {
        Translation_Fusion_B.GPS_gain = Translation_Fusion_P_g.Constant_Value_lh;
      }

      if ((!(Translation_Fusion_B.GPS_gain <
             Translation_Fusion_P_g.AdaptiveVOVelocityCorrection_ma)) &&
          (!Translation_Fusion_B.Compare_ko)) {
        Translation_Fusion_B.GPS_gain =
          Translation_Fusion_P_g.AdaptiveVOVelocityCorrection_ma;
      }

      for (Translation_Fusion_B.rtb_GPS_gain_tmp = 0;
           Translation_Fusion_B.rtb_GPS_gain_tmp < 2;
           Translation_Fusion_B.rtb_GPS_gain_tmp++) {
        Translation_Fusion_B.v1_tmp = Translation_Fusion_B.rtb_GPS_gain_tmp << 1;
        Translation_Fusion_B.Switch2_e[Translation_Fusion_B.v1_tmp] = 0.0F;
        Translation_Fusion_B.Switch2_e[Translation_Fusion_B.v1_tmp] +=
          Translation_Fusion_B.Product_nu[Translation_Fusion_B.v1_tmp] *
          Translation_Fusion_B.rtb_Min_c_idx_0;
        Translation_Fusion_B.rtb_P_Kalman_tmp = Translation_Fusion_B.v1_tmp + 1;
        Translation_Fusion_B.Switch2_e[Translation_Fusion_B.v1_tmp] +=
          Translation_Fusion_B.Product_nu[Translation_Fusion_B.rtb_P_Kalman_tmp]
          * 0.0F;
        Translation_Fusion_B.v1_tmp++;
        Translation_Fusion_B.Switch2_e[Translation_Fusion_B.v1_tmp] = 0.0F;
        Translation_Fusion_B.Switch2_e[Translation_Fusion_B.v1_tmp] =
          Translation_Fusion_B.Switch2_e[Translation_Fusion_B.rtb_P_Kalman_tmp]
          + Translation_Fusion_B.Product_nu[Translation_Fusion_B.rtb_GPS_gain_tmp
          << 1] * 0.0F;
        Translation_Fusion_B.Switch2_e[Translation_Fusion_B.v1_tmp] =
          Translation_Fusion_B.Product_nu[(Translation_Fusion_B.rtb_GPS_gain_tmp
          << 1) + 1] * Translation_Fusion_B.GPS_gain +
          Translation_Fusion_B.Switch2_e[Translation_Fusion_B.rtb_P_Kalman_tmp];
      }
    } else {
      Translation_Fusion_B.Switch2_e[0] = Translation_Fusion_B.Product_nu[0];
      Translation_Fusion_B.Switch2_e[1] = Translation_Fusion_B.Product_nu[1];
      Translation_Fusion_B.Switch2_e[2] = Translation_Fusion_B.Product_nu[2];
      Translation_Fusion_B.Switch2_e[3] = Translation_Fusion_B.Product_nu[3];
    }

    for (Translation_Fusion_B.rtb_GPS_gain_tmp = 0;
         Translation_Fusion_B.rtb_GPS_gain_tmp < 4;
         Translation_Fusion_B.rtb_GPS_gain_tmp++) {
      for (Translation_Fusion_B.i = 0; Translation_Fusion_B.i < 2;
           Translation_Fusion_B.i++) {
        Translation_Fusion_B.v1_tmp = Translation_Fusion_B.i << 2;
        Translation_Fusion_B.rtb_P_Kalman_tmp =
          Translation_Fusion_B.rtb_GPS_gain_tmp + Translation_Fusion_B.v1_tmp;
        Translation_Fusion_B.rtb_P_Kalman_c[Translation_Fusion_B.rtb_P_Kalman_tmp]
          = 0.0F;
        Translation_Fusion_B.v1_tmp += Translation_Fusion_B.rtb_GPS_gain_tmp;
        Translation_Fusion_B.rtb_P_Kalman_c[Translation_Fusion_B.rtb_P_Kalman_tmp]
          = Translation_Fusion_B.rtb_P_Kalman_c[Translation_Fusion_B.v1_tmp] +
          Translation_Fusion_B.MatrixMultiply4_l[Translation_Fusion_B.rtb_GPS_gain_tmp]
          * Translation_Fusion_P_g.MeaMatrix_Value_k[Translation_Fusion_B.i];
        Translation_Fusion_B.rtb_P_Kalman_c[Translation_Fusion_B.rtb_P_Kalman_tmp]
          = Translation_Fusion_B.rtb_P_Kalman_c[Translation_Fusion_B.v1_tmp] +
          Translation_Fusion_B.MatrixMultiply4_l[Translation_Fusion_B.rtb_GPS_gain_tmp
          + 4] * Translation_Fusion_P_g.MeaMatrix_Value_k[Translation_Fusion_B.i
          + 2];
        Translation_Fusion_B.rtb_P_Kalman_c[Translation_Fusion_B.rtb_P_Kalman_tmp]
          = Translation_Fusion_B.rtb_P_Kalman_c[Translation_Fusion_B.v1_tmp] +
          Translation_Fusion_B.MatrixMultiply4_l[Translation_Fusion_B.rtb_GPS_gain_tmp
          + 8] * Translation_Fusion_P_g.MeaMatrix_Value_k[Translation_Fusion_B.i
          + 4];
        Translation_Fusion_B.rtb_P_Kalman_c[Translation_Fusion_B.rtb_P_Kalman_tmp]
          = Translation_Fusion_B.rtb_P_Kalman_c[Translation_Fusion_B.v1_tmp] +
          Translation_Fusion_B.MatrixMultiply4_l[Translation_Fusion_B.rtb_GPS_gain_tmp
          + 12] *
          Translation_Fusion_P_g.MeaMatrix_Value_k[Translation_Fusion_B.i + 6];
      }
    }

    for (Translation_Fusion_B.rtb_GPS_gain_tmp = 0;
         Translation_Fusion_B.rtb_GPS_gain_tmp < 2;
         Translation_Fusion_B.rtb_GPS_gain_tmp++) {
      for (Translation_Fusion_B.i = 0; Translation_Fusion_B.i < 2;
           Translation_Fusion_B.i++) {
        Translation_Fusion_B.rtb_P_Kalman_tmp =
          Translation_Fusion_B.rtb_GPS_gain_tmp << 2;
        Translation_Fusion_B.v1_tmp = Translation_Fusion_B.rtb_GPS_gain_tmp << 1;
        Translation_Fusion_B.fv1[Translation_Fusion_B.i +
          Translation_Fusion_B.v1_tmp] =
          (((Translation_Fusion_B.rtb_P_Kalman_c[Translation_Fusion_B.rtb_P_Kalman_tmp
             + 1] *
             Translation_Fusion_P_g.MeaMatrix_Value_k[Translation_Fusion_B.i + 2]
             + Translation_Fusion_B.rtb_P_Kalman_c[Translation_Fusion_B.rtb_P_Kalman_tmp]
             * Translation_Fusion_P_g.MeaMatrix_Value_k[Translation_Fusion_B.i])
            + Translation_Fusion_B.rtb_P_Kalman_c[Translation_Fusion_B.rtb_P_Kalman_tmp
            + 2] *
            Translation_Fusion_P_g.MeaMatrix_Value_k[Translation_Fusion_B.i + 4])
           + Translation_Fusion_B.rtb_P_Kalman_c[Translation_Fusion_B.rtb_P_Kalman_tmp
           + 3] *
           Translation_Fusion_P_g.MeaMatrix_Value_k[Translation_Fusion_B.i + 6])
          + Translation_Fusion_B.Switch2_e[Translation_Fusion_B.v1_tmp +
          Translation_Fusion_B.i];
      }
    }

    Translation_Fusion_B.fv0[0] = Translation_Fusion_B.fv1[0];
    Translation_Fusion_B.fv0[1] = Translation_Fusion_B.fv1[1];
    Translation_Fusion_B.fv0[2] = Translation_Fusion_B.fv1[2];
    Translation_Fusion_B.fv0[3] = Translation_Fusion_B.fv1[3];
    Translation_Fusi_rt_invf2x2_snf(Translation_Fusion_B.fv0,
      Translation_Fusion_B.fv1);
    for (Translation_Fusion_B.rtb_GPS_gain_tmp = 0;
         Translation_Fusion_B.rtb_GPS_gain_tmp < 4;
         Translation_Fusion_B.rtb_GPS_gain_tmp++) {
      Translation_Fusion_B.rtb_P_Kalman_c[Translation_Fusion_B.rtb_GPS_gain_tmp]
        = 0.0F;
      Translation_Fusion_B.i = Translation_Fusion_B.rtb_GPS_gain_tmp << 1;
      Translation_Fusion_B.rtb_P_Kalman_c[Translation_Fusion_B.rtb_GPS_gain_tmp]
        += Translation_Fusion_P_g.MeaMatrix_Value_k[Translation_Fusion_B.i] *
        Translation_Fusion_B.fv1[0];
      Translation_Fusion_B.Sqrt =
        Translation_Fusion_P_g.MeaMatrix_Value_k[Translation_Fusion_B.i + 1];
      Translation_Fusion_B.rtb_P_Kalman_c[Translation_Fusion_B.rtb_GPS_gain_tmp]
        += Translation_Fusion_B.Sqrt * Translation_Fusion_B.fv1[1];
      Translation_Fusion_B.rtb_P_Kalman_c[Translation_Fusion_B.rtb_GPS_gain_tmp
        + 4] = 0.0F;
      Translation_Fusion_B.rtb_P_Kalman_c[Translation_Fusion_B.rtb_GPS_gain_tmp
        + 4] +=
        Translation_Fusion_P_g.MeaMatrix_Value_k[Translation_Fusion_B.rtb_GPS_gain_tmp
        << 1] * Translation_Fusion_B.fv1[2];
      Translation_Fusion_B.rtb_P_Kalman_c[Translation_Fusion_B.rtb_GPS_gain_tmp
        + 4] += Translation_Fusion_B.Sqrt * Translation_Fusion_B.fv1[3];
    }

    for (Translation_Fusion_B.rtb_GPS_gain_tmp = 0;
         Translation_Fusion_B.rtb_GPS_gain_tmp < 4;
         Translation_Fusion_B.rtb_GPS_gain_tmp++) {
      for (Translation_Fusion_B.i = 0; Translation_Fusion_B.i < 2;
           Translation_Fusion_B.i++) {
        Translation_Fusion_B.v1_tmp = Translation_Fusion_B.i << 2;
        Translation_Fusion_B.rtb_P_Kalman_tmp =
          Translation_Fusion_B.rtb_GPS_gain_tmp + Translation_Fusion_B.v1_tmp;
        Translation_Fusion_B.Selector12[Translation_Fusion_B.rtb_P_Kalman_tmp] =
          0.0F;
        Translation_Fusion_B.P_RTK_tmp = Translation_Fusion_B.v1_tmp +
          Translation_Fusion_B.rtb_GPS_gain_tmp;
        Translation_Fusion_B.Selector12[Translation_Fusion_B.rtb_P_Kalman_tmp] =
          Translation_Fusion_B.Selector12[Translation_Fusion_B.P_RTK_tmp] +
          Translation_Fusion_B.rtb_P_Kalman_c[Translation_Fusion_B.v1_tmp] *
          Translation_Fusion_B.MatrixMultiply4_l[Translation_Fusion_B.rtb_GPS_gain_tmp];
        Translation_Fusion_B.Selector12[Translation_Fusion_B.rtb_P_Kalman_tmp] =
          Translation_Fusion_B.rtb_P_Kalman_c[Translation_Fusion_B.v1_tmp + 1] *
          Translation_Fusion_B.MatrixMultiply4_l[Translation_Fusion_B.rtb_GPS_gain_tmp
          + 4] + Translation_Fusion_B.Selector12[Translation_Fusion_B.P_RTK_tmp];
        Translation_Fusion_B.Selector12[Translation_Fusion_B.rtb_P_Kalman_tmp] =
          Translation_Fusion_B.rtb_P_Kalman_c[Translation_Fusion_B.v1_tmp + 2] *
          Translation_Fusion_B.MatrixMultiply4_l[Translation_Fusion_B.rtb_GPS_gain_tmp
          + 8] + Translation_Fusion_B.Selector12[Translation_Fusion_B.P_RTK_tmp];
        Translation_Fusion_B.Selector12[Translation_Fusion_B.rtb_P_Kalman_tmp] =
          Translation_Fusion_B.rtb_P_Kalman_c[Translation_Fusion_B.v1_tmp + 3] *
          Translation_Fusion_B.MatrixMultiply4_l[Translation_Fusion_B.rtb_GPS_gain_tmp
          + 12] + Translation_Fusion_B.Selector12[Translation_Fusion_B.P_RTK_tmp];
      }

      for (Translation_Fusion_B.i = 0; Translation_Fusion_B.i < 4;
           Translation_Fusion_B.i++) {
        Translation_Fusion_B.v1_tmp = Translation_Fusion_B.i << 1;
        Translation_Fusion_B.rtb_P_Kalman_tmp = Translation_Fusion_B.i << 2;
        Translation_Fusion_B.MathFunction_ej[Translation_Fusion_B.rtb_GPS_gain_tmp
          + Translation_Fusion_B.rtb_P_Kalman_tmp] =
          Translation_Fusion_B.IdentityMatrix_k[Translation_Fusion_B.rtb_P_Kalman_tmp
          + Translation_Fusion_B.rtb_GPS_gain_tmp] -
          (Translation_Fusion_P_g.MeaMatrix_Value_k[Translation_Fusion_B.v1_tmp
           + 1] *
           Translation_Fusion_B.Selector12[Translation_Fusion_B.rtb_GPS_gain_tmp
           + 4] +
           Translation_Fusion_P_g.MeaMatrix_Value_k[Translation_Fusion_B.v1_tmp]
           * Translation_Fusion_B.Selector12[Translation_Fusion_B.rtb_GPS_gain_tmp]);
      }
    }

    for (Translation_Fusion_B.rtb_GPS_gain_tmp = 0;
         Translation_Fusion_B.rtb_GPS_gain_tmp < 4;
         Translation_Fusion_B.rtb_GPS_gain_tmp++) {
      for (Translation_Fusion_B.i = 0; Translation_Fusion_B.i < 4;
           Translation_Fusion_B.i++) {
        Translation_Fusion_B.v1_tmp = Translation_Fusion_B.i << 2;
        Translation_Fusion_B.rtb_P_Kalman_tmp =
          Translation_Fusion_B.rtb_GPS_gain_tmp + Translation_Fusion_B.v1_tmp;
        Translation_Fusion_B.rtb_MatrixMultiply4_l_c[Translation_Fusion_B.rtb_P_Kalman_tmp]
          = 0.0F;
        Translation_Fusion_B.v1_tmp += Translation_Fusion_B.rtb_GPS_gain_tmp;
        Translation_Fusion_B.rtb_MatrixMultiply4_l_c[Translation_Fusion_B.rtb_P_Kalman_tmp]
          =
          Translation_Fusion_B.rtb_MatrixMultiply4_l_c[Translation_Fusion_B.v1_tmp]
          + Translation_Fusion_B.MatrixMultiply4_l[Translation_Fusion_B.rtb_GPS_gain_tmp]
          * Translation_Fusion_B.MathFunction_ej[Translation_Fusion_B.i];
        Translation_Fusion_B.rtb_MatrixMultiply4_l_c[Translation_Fusion_B.rtb_P_Kalman_tmp]
          =
          Translation_Fusion_B.rtb_MatrixMultiply4_l_c[Translation_Fusion_B.v1_tmp]
          + Translation_Fusion_B.MatrixMultiply4_l[Translation_Fusion_B.rtb_GPS_gain_tmp
          + 4] * Translation_Fusion_B.MathFunction_ej[Translation_Fusion_B.i + 4];
        Translation_Fusion_B.rtb_MatrixMultiply4_l_c[Translation_Fusion_B.rtb_P_Kalman_tmp]
          =
          Translation_Fusion_B.rtb_MatrixMultiply4_l_c[Translation_Fusion_B.v1_tmp]
          + Translation_Fusion_B.MatrixMultiply4_l[Translation_Fusion_B.rtb_GPS_gain_tmp
          + 8] * Translation_Fusion_B.MathFunction_ej[Translation_Fusion_B.i + 8];
        Translation_Fusion_B.rtb_MatrixMultiply4_l_c[Translation_Fusion_B.rtb_P_Kalman_tmp]
          =
          Translation_Fusion_B.rtb_MatrixMultiply4_l_c[Translation_Fusion_B.v1_tmp]
          + Translation_Fusion_B.MatrixMultiply4_l[Translation_Fusion_B.rtb_GPS_gain_tmp
          + 12] * Translation_Fusion_B.MathFunction_ej[Translation_Fusion_B.i +
          12];
      }
    }

    for (Translation_Fusion_B.rtb_GPS_gain_tmp = 0;
         Translation_Fusion_B.rtb_GPS_gain_tmp < 2;
         Translation_Fusion_B.rtb_GPS_gain_tmp++) {
      for (Translation_Fusion_B.i = 0; Translation_Fusion_B.i < 4;
           Translation_Fusion_B.i++) {
        Translation_Fusion_B.v1_tmp = Translation_Fusion_B.i << 1;
        Translation_Fusion_B.rtb_P_Kalman_tmp =
          Translation_Fusion_B.rtb_GPS_gain_tmp + Translation_Fusion_B.v1_tmp;
        Translation_Fusion_B.rtb_P_Kalman_c[Translation_Fusion_B.rtb_P_Kalman_tmp]
          = 0.0F;
        Translation_Fusion_B.v1_tmp += Translation_Fusion_B.rtb_GPS_gain_tmp;
        Translation_Fusion_B.rtb_P_Kalman_c[Translation_Fusion_B.rtb_P_Kalman_tmp]
          = Translation_Fusion_B.rtb_P_Kalman_c[Translation_Fusion_B.v1_tmp] +
          Translation_Fusion_B.Switch2_e[Translation_Fusion_B.rtb_GPS_gain_tmp] *
          Translation_Fusion_B.Selector12[Translation_Fusion_B.i];
        Translation_Fusion_B.rtb_P_Kalman_c[Translation_Fusion_B.rtb_P_Kalman_tmp]
          = Translation_Fusion_B.rtb_P_Kalman_c[Translation_Fusion_B.v1_tmp] +
          Translation_Fusion_B.Switch2_e[Translation_Fusion_B.rtb_GPS_gain_tmp +
          2] * Translation_Fusion_B.Selector12[Translation_Fusion_B.i + 4];
      }
    }

    for (Translation_Fusion_B.rtb_GPS_gain_tmp = 0;
         Translation_Fusion_B.rtb_GPS_gain_tmp < 4;
         Translation_Fusion_B.rtb_GPS_gain_tmp++) {
      for (Translation_Fusion_B.i = 0; Translation_Fusion_B.i < 4;
           Translation_Fusion_B.i++) {
        Translation_Fusion_B.v1_tmp = Translation_Fusion_B.rtb_GPS_gain_tmp << 2;
        Translation_Fusion_B.rtb_P_Kalman_tmp = Translation_Fusion_B.i +
          Translation_Fusion_B.v1_tmp;
        Translation_Fusion_B.MatrixMultiply4_l[Translation_Fusion_B.rtb_P_Kalman_tmp]
          = 0.0F;
        Translation_Fusion_B.P_RTK_tmp = Translation_Fusion_B.v1_tmp +
          Translation_Fusion_B.i;
        Translation_Fusion_B.MatrixMultiply4_l[Translation_Fusion_B.rtb_P_Kalman_tmp]
          =
          Translation_Fusion_B.MatrixMultiply4_l[Translation_Fusion_B.P_RTK_tmp]
          + Translation_Fusion_B.rtb_MatrixMultiply4_l_c[Translation_Fusion_B.v1_tmp]
          * Translation_Fusion_B.MathFunction_ej[Translation_Fusion_B.i];
        Translation_Fusion_B.MatrixMultiply4_l[Translation_Fusion_B.rtb_P_Kalman_tmp]
          =
          Translation_Fusion_B.rtb_MatrixMultiply4_l_c[Translation_Fusion_B.v1_tmp
          + 1] * Translation_Fusion_B.MathFunction_ej[Translation_Fusion_B.i + 4]
          + Translation_Fusion_B.MatrixMultiply4_l[Translation_Fusion_B.P_RTK_tmp];
        Translation_Fusion_B.MatrixMultiply4_l[Translation_Fusion_B.rtb_P_Kalman_tmp]
          =
          Translation_Fusion_B.rtb_MatrixMultiply4_l_c[Translation_Fusion_B.v1_tmp
          + 2] * Translation_Fusion_B.MathFunction_ej[Translation_Fusion_B.i + 8]
          + Translation_Fusion_B.MatrixMultiply4_l[Translation_Fusion_B.P_RTK_tmp];
        Translation_Fusion_B.MatrixMultiply4_l[Translation_Fusion_B.rtb_P_Kalman_tmp]
          =
          Translation_Fusion_B.rtb_MatrixMultiply4_l_c[Translation_Fusion_B.v1_tmp
          + 3] * Translation_Fusion_B.MathFunction_ej[Translation_Fusion_B.i +
          12] +
          Translation_Fusion_B.MatrixMultiply4_l[Translation_Fusion_B.P_RTK_tmp];
        Translation_Fusion_B.rtb_Selector12_k[Translation_Fusion_B.rtb_P_Kalman_tmp]
          = 0.0F;
        Translation_Fusion_B.v1_tmp = Translation_Fusion_B.rtb_GPS_gain_tmp << 1;
        Translation_Fusion_B.rtb_Selector12_k[Translation_Fusion_B.rtb_P_Kalman_tmp]
          = Translation_Fusion_B.rtb_Selector12_k[Translation_Fusion_B.P_RTK_tmp]
          + Translation_Fusion_B.rtb_P_Kalman_c[Translation_Fusion_B.v1_tmp] *
          Translation_Fusion_B.Selector12[Translation_Fusion_B.i];
        Translation_Fusion_B.rtb_Selector12_k[Translation_Fusion_B.rtb_P_Kalman_tmp]
          = Translation_Fusion_B.rtb_P_Kalman_c[Translation_Fusion_B.v1_tmp + 1]
          * Translation_Fusion_B.Selector12[Translation_Fusion_B.i + 4] +
          Translation_Fusion_B.rtb_Selector12_k[Translation_Fusion_B.P_RTK_tmp];
      }
    }

    for (Translation_Fusion_B.rtb_GPS_gain_tmp = 0;
         Translation_Fusion_B.rtb_GPS_gain_tmp < 16;
         Translation_Fusion_B.rtb_GPS_gain_tmp++) {
      Translation_Fusion_B.P[Translation_Fusion_B.rtb_GPS_gain_tmp] =
        Translation_Fusion_B.MatrixMultiply4_l[Translation_Fusion_B.rtb_GPS_gain_tmp]
        + Translation_Fusion_B.rtb_Selector12_k[Translation_Fusion_B.rtb_GPS_gain_tmp];
    }

    Translation_Fusion_DW.Delay1_DSTATE_j[0] = Translation_Fusion_B.vel_xy_GPS[0];
    Translation_Fusion_DW.Delay1_DSTATE_j[1] = Translation_Fusion_B.vel_xy_GPS[1];
    for (Translation_Fusion_B.i = 0; Translation_Fusion_B.i < 4;
         Translation_Fusion_B.i++) {
      Translation_Fusion_B.MatrixMultiply1[Translation_Fusion_B.i] = 0.0F;
      Translation_Fusion_B.MatrixMultiply1[Translation_Fusion_B.i] +=
        Translation_Fusion_B.Selector12[Translation_Fusion_B.i] *
        Translation_Fusion_B.vel_xy_GPS[0];
      Translation_Fusion_B.MatrixMultiply1[Translation_Fusion_B.i] +=
        Translation_Fusion_B.Selector12[Translation_Fusion_B.i + 4] *
        Translation_Fusion_B.vel_xy_GPS[1];
      Translation_Fusion_DW.Delay_DSTATE_fh[Translation_Fusion_B.i] =
        Translation_Fusion_B.Subtract1_c[Translation_Fusion_B.i];
      Translation_Fusion_B.v1_tmp = Translation_Fusion_B.i << 2;
      Translation_Fusion_B.rtb_P_Kalman_tmp = 6 * (2 + Translation_Fusion_B.i);
      Translation_Fusion_B.P_Kalman[2 + Translation_Fusion_B.rtb_P_Kalman_tmp] =
        Translation_Fusion_B.P[Translation_Fusion_B.v1_tmp];
      Translation_Fusion_B.P_Kalman[3 + Translation_Fusion_B.rtb_P_Kalman_tmp] =
        Translation_Fusion_B.P[Translation_Fusion_B.v1_tmp + 1];
      Translation_Fusion_B.P_Kalman[4 + Translation_Fusion_B.rtb_P_Kalman_tmp] =
        Translation_Fusion_B.P[Translation_Fusion_B.v1_tmp + 2];
      Translation_Fusion_B.P_Kalman[5 + Translation_Fusion_B.rtb_P_Kalman_tmp] =
        Translation_Fusion_B.P[Translation_Fusion_B.v1_tmp + 3];
    }
  } else {
    for (Translation_Fusion_B.rtb_GPS_gain_tmp = 0;
         Translation_Fusion_B.rtb_GPS_gain_tmp < 4;
         Translation_Fusion_B.rtb_GPS_gain_tmp++) {
      Translation_Fusion_B.v1_tmp = Translation_Fusion_B.rtb_GPS_gain_tmp << 2;
      Translation_Fusion_B.rtb_P_Kalman_tmp = 6 * (2 +
        Translation_Fusion_B.rtb_GPS_gain_tmp);
      Translation_Fusion_B.P_Kalman[2 + Translation_Fusion_B.rtb_P_Kalman_tmp] =
        Translation_Fusion_B.MatrixMultiply4_l[Translation_Fusion_B.v1_tmp];
      Translation_Fusion_B.P_Kalman[3 + Translation_Fusion_B.rtb_P_Kalman_tmp] =
        Translation_Fusion_B.MatrixMultiply4_l[Translation_Fusion_B.v1_tmp + 1];
      Translation_Fusion_B.P_Kalman[4 + Translation_Fusion_B.rtb_P_Kalman_tmp] =
        Translation_Fusion_B.MatrixMultiply4_l[Translation_Fusion_B.v1_tmp + 2];
      Translation_Fusion_B.P_Kalman[5 + Translation_Fusion_B.rtb_P_Kalman_tmp] =
        Translation_Fusion_B.MatrixMultiply4_l[Translation_Fusion_B.v1_tmp + 3];
    }
  }

  mw_arm_sqrt_f32(*rtu_Sensor_Vision_data_delta_po *
                  *rtu_Sensor_Vision_data_delta_po +
                  *rtu_Sensor_Vision_data_delta__d *
                  *rtu_Sensor_Vision_data_delta__d, &Translation_Fusion_B.Sqrt);
  Translation_Fusion_B.LogicalOperator1_ks = ((real32_T)fabs
    (Translation_Fusion_B.Sqrt - Translation_Fusion_DW.UnitDelay_DSTATE_h) >=
    Translation_Fusion_P_g.CompareToConstant2_const_i);
  Translation_Fusion_B.LogicalOperator2_g =
    !Translation_Fusion_B.LogicalOperator3_d5;
  Translation_Fusion_B.LogicalOperator3_d5 = !Translation_Fusion_B.Compare_l0;
  Translation_Fusion_B.Compare_h = !Translation_Fusion_B.LogicalOperator3_d5;
  if (Translation_Fusion_B.Compare_h ||
      (Translation_Fusion_DW.DiscreteTimeIntegrator_PrevR_nj != 0)) {
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTA_ppy =
      Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_bh;
  }

  if (Translation_Fusion_DW.DiscreteTimeIntegrator_DSTA_ppy >=
      Translation_Fusion_P_g.DiscreteTimeIntegrator_UpperS_c) {
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTA_ppy =
      Translation_Fusion_P_g.DiscreteTimeIntegrator_UpperS_c;
  } else {
    if (Translation_Fusion_DW.DiscreteTimeIntegrator_DSTA_ppy <=
        Translation_Fusion_P_g.DiscreteTimeIntegrator_Lower_kn) {
      Translation_Fusion_DW.DiscreteTimeIntegrator_DSTA_ppy =
        Translation_Fusion_P_g.DiscreteTimeIntegrator_Lower_kn;
    }
  }

  Translation_Fusion_B.LogicalOperator2_hv =
    !(Translation_Fusion_DW.DiscreteTimeIntegrator_DSTA_ppy >
      Translation_Fusion_P_g.Validaperiod_T_p_c);
  Translation_Fusion_B.Compare_j = !Translation_Fusion_B.LogicalOperator2_hv;
  if (Translation_Fusion_B.Compare_j ||
      (Translation_Fusion_DW.DiscreteTimeIntegrator_PrevRe_k != 0)) {
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_c3 =
      Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_ck;
  }

  if (Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_c3 >=
      Translation_Fusion_P_g.DiscreteTimeIntegrator_Upper_o4) {
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_c3 =
      Translation_Fusion_P_g.DiscreteTimeIntegrator_Upper_o4;
  } else {
    if (Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_c3 <=
        Translation_Fusion_P_g.DiscreteTimeIntegrator_LowerS_d) {
      Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_c3 =
        Translation_Fusion_P_g.DiscreteTimeIntegrator_LowerS_d;
    }
  }

  *rty_Translation_data_VO_Vel_Val =
    (Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_c3 >
     Translation_Fusion_P_g.Validaperiod1_T_p_f);
  Translation_Fusion_B.rtk_pos_valid = ((Translation_Fusion_B.LogicalOperator2_g
    && Translation_Fusion_B.rtk_pos_valid) ||
    Translation_Fusion_DW.Delay1_DSTATE_ls || (!*rty_Translation_data_VO_Vel_Val)
    || ((*rtu_Sensor_Vision_data_Vision_q <
         Translation_Fusion_P_g.CompareToConstant1_const_gb) &&
        Translation_Fusion_B.GPS_Vel_Vaild) || rtb_LogicalOperator1_n_tmp ||
    (*rtu_Sensor_Vision_data_delta_po * *rtu_Sensor_Vision_data_delta_po +
     *rtu_Sensor_Vision_data_delta__d * *rtu_Sensor_Vision_data_delta__d ==
     Translation_Fusion_P_g.CompareToConstant4_const_l) ||
    Translation_Fusion_B.Compare_mr);
  Translation_Fusion_B.LogicalOperator2_g =
    ((!Translation_Fusion_B.LogicalOperator1_ks) &&
     (!Translation_Fusion_B.rtk_pos_valid) && (*rty_Translation_data_VO_Vel_Val)
     && Translation_Fusion_B.Compare_l0 && (*rtu_Sensor_Vision_data_type <
      Translation_Fusion_P_g.CompareToConstant_const_er));
  if (Translation_Fusion_B.LogicalOperator2_g ||
      (Translation_Fusion_DW.DiscreteTimeIntegrator_PrevR_pi != 0)) {
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTA_mos =
      Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_lx;
  }

  Translation_Fusion_B.Compare_ko =
    (Translation_Fusion_DW.DiscreteTimeIntegrator_DSTA_mos >=
     Translation_Fusion_P_g.CompareToConstant_const_ah);
  if (Translation_Fusion_B.Compare_l0 ||
      (Translation_Fusion_DW.DiscreteTimeIntegrator_PrevR_dw != 0)) {
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_hz =
      Translation_Fusion_P_g.DiscreteTimeIntegrator_IC_ln;
  }

  Translation_Fusion_B.Compare_mr =
    (Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_hz >=
     Translation_Fusion_P_g.CompareToConstant_const_el);
  Translation_Fusion_B.Gain_h2[0] = Translation_Fusion_P_g.Gain_Gain_hn *
    Translation_Fusion_B.MatrixMultiply1[0];
  Translation_Fusion_B.Gain_h2[1] = Translation_Fusion_P_g.Gain_Gain_hn *
    Translation_Fusion_B.MatrixMultiply1[1];
  Translation_Fusion_B.Gain_h2[2] = Translation_Fusion_P_g.Gain_Gain_hn *
    Translation_Fusion_B.MatrixMultiply1[2];
  Translation_Fusion_B.Gain_h2[3] = Translation_Fusion_P_g.Gain_Gain_hn *
    Translation_Fusion_B.MatrixMultiply1[3];
  if (Translation_Fusion_DW.DiscreteTimeIntegrator_IC_LO_fo != 0) {
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_bk =
      Translation_Fusion_B.Gain_h2[0];
  }

  Translation_Fusion_B.Sum3 =
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_bk;
  if (Translation_Fusion_DW.DiscreteTimeIntegrator_IC_LO_he != 0) {
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_mu =
      Translation_Fusion_B.Gain_h2[1];
  }

  Translation_Fusion_B.GPS_gain =
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_mu;
  Translation_Fusi_MovingAverage3(Translation_Fusion_B.Gain_h2[2],
    &Translation_Fusion_B.MovingAverage2, &Translation_Fusion_DW.MovingAverage2);
  Translation_Fusi_MovingAverage3(Translation_Fusion_B.Gain_h2[3],
    &Translation_Fusion_B.MovingAverage3, &Translation_Fusion_DW.MovingAverage3);
  if (Translation_Fusion_B.Compare_mr) {
    Translation_Fusion_B.rtb_Min_c_idx_0 =
      Translation_Fusion_P_g.Constant1_Value_om;
  } else {
    Translation_Fusion_B.rtb_Min_c_idx_0 = Translation_Fusion_B.Sum3;
  }

  Translation_Fusion_B.ManualSwitch[2] = Translation_Fusion_B.Assignment[2] +
    Translation_Fusion_B.rtb_Min_c_idx_0;
  if (Translation_Fusion_B.Compare_mr) {
    Translation_Fusion_B.rtb_Min_c_idx_0 =
      Translation_Fusion_P_g.Constant1_Value_om;
  } else {
    Translation_Fusion_B.rtb_Min_c_idx_0 = Translation_Fusion_B.GPS_gain;
  }

  Translation_Fusion_B.ManualSwitch[3] = Translation_Fusion_B.Assignment[3] +
    Translation_Fusion_B.rtb_Min_c_idx_0;
  if (Translation_Fusion_B.Compare_mr) {
    Translation_Fusion_B.rtb_Min_c_idx_0 =
      Translation_Fusion_P_g.Constant1_Value_om;
  } else {
    Translation_Fusion_B.rtb_Min_c_idx_0 =
      Translation_Fusion_B.MovingAverage2.MovingAverage3;
  }

  Translation_Fusion_B.ManualSwitch[4] = Translation_Fusion_B.Assignment[4] +
    Translation_Fusion_B.rtb_Min_c_idx_0;
  if (Translation_Fusion_B.Compare_mr) {
    Translation_Fusion_B.rtb_Min_c_idx_0 =
      Translation_Fusion_P_g.Constant1_Value_om;
  } else {
    Translation_Fusion_B.rtb_Min_c_idx_0 =
      Translation_Fusion_B.MovingAverage3.MovingAverage3;
  }

  Translation_Fusion_B.ManualSwitch[5] = Translation_Fusion_B.Assignment[5] +
    Translation_Fusion_B.rtb_Min_c_idx_0;
  if ((((Translation_Fusion_PrevZCX.x_delay_Reset_ZCE_d == POS_ZCSIG) !=
        (int32_T)Translation_Fusion_B.rtk_pos_valid) &&
       (Translation_Fusion_PrevZCX.x_delay_Reset_ZCE_d != UNINITIALIZED_ZCSIG)) ||
      Translation_Fusion_B.rtk_pos_valid) {
    Translation_Fusion_DW.icLoad_on = 1U;
  }

  Translation_Fusion_PrevZCX.x_delay_Reset_ZCE_d =
    Translation_Fusion_B.rtk_pos_valid;
  if (Translation_Fusion_DW.icLoad_on != 0) {
    for (Translation_Fusion_B.i = 0; Translation_Fusion_B.i < 80;
         Translation_Fusion_B.i++) {
      Translation_Fusion_DW.x_delay_DSTATE_e[Translation_Fusion_B.i] =
        Translation_Fusion_B.ManualSwitch[0];
    }
  }

  for (Translation_Fusion_B.rtb_GPS_gain_tmp = 0;
       Translation_Fusion_B.rtb_GPS_gain_tmp < 3;
       Translation_Fusion_B.rtb_GPS_gain_tmp++) {
    Translation_Fusion_B.v1_tmp = (Translation_Fusion_B.rtb_GPS_gain_tmp << 1) *
      6;
    Translation_Fusion_B.Subtract_ia[3 * Translation_Fusion_B.rtb_GPS_gain_tmp] =
      Translation_Fusion_B.P_Kalman[Translation_Fusion_B.v1_tmp];
    Translation_Fusion_B.Subtract_ia[1 + 3 *
      Translation_Fusion_B.rtb_GPS_gain_tmp] =
      Translation_Fusion_B.P_Kalman[Translation_Fusion_B.v1_tmp + 2];
    Translation_Fusion_B.Subtract_ia[2 + 3 *
      Translation_Fusion_B.rtb_GPS_gain_tmp] =
      Translation_Fusion_B.P_Kalman[Translation_Fusion_B.v1_tmp + 4];
    Translation_Fusion_B.sfor_R_O_mDs2[Translation_Fusion_B.rtb_GPS_gain_tmp] =
      Translation_Fusion_P_g.Constant_Value_l3[Translation_Fusion_B.rtb_GPS_gain_tmp
      << 2];
  }

  Translation_Fusion_B.RTK_Vel_good = (Translation_Fusion_B.LogicalOperator1_ks ||
    Translation_Fusion_B.rtk_pos_valid);
  if ((((Translation_Fusion_PrevZCX.Delay_Reset_ZCE_k == POS_ZCSIG) != (int32_T)
        Translation_Fusion_B.RTK_Vel_good) &&
       (Translation_Fusion_PrevZCX.Delay_Reset_ZCE_k != UNINITIALIZED_ZCSIG)) ||
      Translation_Fusion_B.RTK_Vel_good) {
    Translation_Fusion_DW.icLoad_kr = 1U;
  }

  Translation_Fusion_PrevZCX.Delay_Reset_ZCE_k =
    Translation_Fusion_B.RTK_Vel_good;
  if (Translation_Fusion_DW.icLoad_kr != 0) {
    Translation_Fusion_DW.Delay_DSTATE_mr[0] = *rtu_Sensor_Vision_data_delta_po;
    Translation_Fusion_DW.Delay_DSTATE_mr[1] = *rtu_Sensor_Vision_data_delta__d;
  }

  if ((((Translation_Fusion_PrevZCX.Delay1_Reset_ZCE_b == POS_ZCSIG) != (int32_T)
        Translation_Fusion_B.RTK_Vel_good) &&
       (Translation_Fusion_PrevZCX.Delay1_Reset_ZCE_b != UNINITIALIZED_ZCSIG)) ||
      Translation_Fusion_B.RTK_Vel_good) {
    Translation_Fusion_DW.icLoad_fb = 1U;
  }

  Translation_Fusion_PrevZCX.Delay1_Reset_ZCE_b =
    Translation_Fusion_B.RTK_Vel_good;
  if (Translation_Fusion_DW.icLoad_fb != 0) {
    Translation_Fusion_DW.Delay1_DSTATE_b[0] =
      Translation_Fusion_B.ManualSwitch[0];
    Translation_Fusion_DW.Delay1_DSTATE_b[1] =
      Translation_Fusion_B.ManualSwitch[1];
  }

  Translation_Fusion_B.Sum_ol =
    Translation_Fusion_P_g.uDLookupTable_tableData[plook_u32f_evencka
    (*rtu_Sensor_Vision_data_Vision_q,
     Translation_Fusion_P_g.uDLookupTable_bp01Data[0],
     Translation_Fusion_P_g.uDLookupTable_bp01Data[1] -
     Translation_Fusion_P_g.uDLookupTable_bp01Data[0], 5U)];
  if (Translation_Fusion_B.Sum_ol >
      Translation_Fusion_P_g.Saturation_UpperSat_ct) {
    Translation_Fusion_B.Sum_ol = Translation_Fusion_P_g.Saturation_UpperSat_ct;
  } else {
    if (Translation_Fusion_B.Sum_ol <
        Translation_Fusion_P_g.Saturation_LowerSat_m1) {
      Translation_Fusion_B.Sum_ol =
        Translation_Fusion_P_g.Saturation_LowerSat_m1;
    }
  }

  Translation_Fusion_Correct_x_d(Translation_Fusion_B.LogicalOperator2_g,
    Translation_Fusion_DW.x_delay_DSTATE_e[0],
    Translation_Fusion_B.ManualSwitch[2], Translation_Fusion_B.ManualSwitch[4],
    Translation_Fusion_B.Subtract_ia, Translation_Fusion_B.sfor_R_O_mDs2,
    (*rtu_Sensor_Vision_data_delta_po - Translation_Fusion_DW.Delay_DSTATE_mr[0])
    + Translation_Fusion_DW.Delay1_DSTATE_b[0],
    Translation_Fusion_P_g.Constant_Value_kxd[0] * Translation_Fusion_B.Sum_ol,
    &Translation_Fusion_B.Correct_x, &Translation_Fusion_P_g.Correct_x);
  if ((((Translation_Fusion_PrevZCX.y_delay_Reset_ZCE_p == POS_ZCSIG) !=
        (int32_T)Translation_Fusion_B.rtk_pos_valid) &&
       (Translation_Fusion_PrevZCX.y_delay_Reset_ZCE_p != UNINITIALIZED_ZCSIG)) ||
      Translation_Fusion_B.rtk_pos_valid) {
    Translation_Fusion_DW.icLoad_a = 1U;
  }

  Translation_Fusion_PrevZCX.y_delay_Reset_ZCE_p =
    Translation_Fusion_B.rtk_pos_valid;
  if (Translation_Fusion_DW.icLoad_a != 0) {
    for (Translation_Fusion_B.i = 0; Translation_Fusion_B.i < 80;
         Translation_Fusion_B.i++) {
      Translation_Fusion_DW.y_delay_DSTATE_b[Translation_Fusion_B.i] =
        Translation_Fusion_B.ManualSwitch[1];
    }
  }

  for (Translation_Fusion_B.rtb_GPS_gain_tmp = 0;
       Translation_Fusion_B.rtb_GPS_gain_tmp < 3;
       Translation_Fusion_B.rtb_GPS_gain_tmp++) {
    Translation_Fusion_B.rtb_P_Kalman_tmp =
      (Translation_Fusion_B.rtb_GPS_gain_tmp << 1) + 1;
    Translation_Fusion_B.v1_tmp = Translation_Fusion_B.rtb_P_Kalman_tmp * 6;
    Translation_Fusion_B.Subtract_ia[3 * Translation_Fusion_B.rtb_GPS_gain_tmp] =
      Translation_Fusion_B.P_Kalman[Translation_Fusion_B.v1_tmp + 1];
    Translation_Fusion_B.Subtract_ia[1 + 3 *
      Translation_Fusion_B.rtb_GPS_gain_tmp] =
      Translation_Fusion_B.P_Kalman[Translation_Fusion_B.v1_tmp + 3];
    Translation_Fusion_B.Subtract_ia[2 + 3 *
      Translation_Fusion_B.rtb_GPS_gain_tmp] =
      Translation_Fusion_B.P_Kalman[Translation_Fusion_B.v1_tmp + 5];
    Translation_Fusion_B.sfor_R_O_mDs2[Translation_Fusion_B.rtb_GPS_gain_tmp] =
      Translation_Fusion_P_g.Constant_Value_l3
      [(Translation_Fusion_B.rtb_P_Kalman_tmp << 1) + 1];
  }

  Translation_Fusion_Correct_y(Translation_Fusion_B.LogicalOperator2_g,
    Translation_Fusion_DW.y_delay_DSTATE_b[0],
    Translation_Fusion_B.ManualSwitch[3], Translation_Fusion_B.ManualSwitch[5],
    Translation_Fusion_B.Subtract_ia, Translation_Fusion_B.sfor_R_O_mDs2,
    (*rtu_Sensor_Vision_data_delta__d - Translation_Fusion_DW.Delay_DSTATE_mr[1])
    + Translation_Fusion_DW.Delay1_DSTATE_b[1],
    Translation_Fusion_P_g.Constant_Value_kxd[3] * Translation_Fusion_B.Sum_ol,
    &Translation_Fusion_B.Correct_y, &Translation_Fusion_P_g.Correct_y);
  if (Translation_Fusion_B.LogicalOperator2_g &&
      (!Translation_Fusion_B.Compare_ko)) {
    memcpy(&Translation_Fusion_B.P_Kalman[0],
           &Translation_Fusion_P_g.Constant_Value_cu[0], 36U * sizeof(real32_T));
    for (Translation_Fusion_B.rtb_GPS_gain_tmp = 0;
         Translation_Fusion_B.rtb_GPS_gain_tmp < 3;
         Translation_Fusion_B.rtb_GPS_gain_tmp++) {
      Translation_Fusion_B.v1_tmp = Translation_Fusion_B.rtb_GPS_gain_tmp << 1;
      Translation_Fusion_B.rtb_P_Kalman_tmp = 6 * Translation_Fusion_B.v1_tmp;
      Translation_Fusion_B.P_Kalman[Translation_Fusion_B.rtb_P_Kalman_tmp] =
        Translation_Fusion_B.Correct_x.Multiply5[3 *
        Translation_Fusion_B.rtb_GPS_gain_tmp];
      Translation_Fusion_B.v1_tmp = 6 * (1 + Translation_Fusion_B.v1_tmp);
      Translation_Fusion_B.P_Kalman[1 + Translation_Fusion_B.v1_tmp] =
        Translation_Fusion_B.Correct_y.Multiply5[3 *
        Translation_Fusion_B.rtb_GPS_gain_tmp];
      Translation_Fusion_B.i = 3 * Translation_Fusion_B.rtb_GPS_gain_tmp + 1;
      Translation_Fusion_B.P_Kalman[2 + Translation_Fusion_B.rtb_P_Kalman_tmp] =
        Translation_Fusion_B.Correct_x.Multiply5[Translation_Fusion_B.i];
      Translation_Fusion_B.P_Kalman[3 + Translation_Fusion_B.v1_tmp] =
        Translation_Fusion_B.Correct_y.Multiply5[Translation_Fusion_B.i];
      Translation_Fusion_B.i = 3 * Translation_Fusion_B.rtb_GPS_gain_tmp + 2;
      Translation_Fusion_B.P_Kalman[4 + Translation_Fusion_B.rtb_P_Kalman_tmp] =
        Translation_Fusion_B.Correct_x.Multiply5[Translation_Fusion_B.i];
      Translation_Fusion_B.P_Kalman[5 + Translation_Fusion_B.v1_tmp] =
        Translation_Fusion_B.Correct_y.Multiply5[Translation_Fusion_B.i];
    }
  }

  for (Translation_Fusion_B.rtb_GPS_gain_tmp = 0;
       Translation_Fusion_B.rtb_GPS_gain_tmp < 3;
       Translation_Fusion_B.rtb_GPS_gain_tmp++) {
    Translation_Fusion_B.rtb_Product_i_b[3 *
      Translation_Fusion_B.rtb_GPS_gain_tmp] =
      Translation_Fusion_B.MatrixMultiply4_n[Translation_Fusion_B.rtb_GPS_gain_tmp];
    Translation_Fusion_B.rtb_Product_i_b[1 + 3 *
      Translation_Fusion_B.rtb_GPS_gain_tmp] =
      Translation_Fusion_B.MatrixMultiply4_n[Translation_Fusion_B.rtb_GPS_gain_tmp
      + 3];
    Translation_Fusion_B.rtb_Product_i_b[2 + 3 *
      Translation_Fusion_B.rtb_GPS_gain_tmp] =
      Translation_Fusion_B.MatrixMultiply4_n[Translation_Fusion_B.rtb_GPS_gain_tmp
      + 6];
  }

  for (Translation_Fusion_B.rtb_GPS_gain_tmp = 0;
       Translation_Fusion_B.rtb_GPS_gain_tmp < 9;
       Translation_Fusion_B.rtb_GPS_gain_tmp++) {
    Translation_Fusion_B.MatrixMultiply4_n[Translation_Fusion_B.rtb_GPS_gain_tmp]
      =
      Translation_Fusion_B.rtb_Product_i_b[Translation_Fusion_B.rtb_GPS_gain_tmp];
  }

  for (Translation_Fusion_B.rtb_GPS_gain_tmp = 0;
       Translation_Fusion_B.rtb_GPS_gain_tmp < 3;
       Translation_Fusion_B.rtb_GPS_gain_tmp++) {
    rty_acc_bias_B[Translation_Fusion_B.rtb_GPS_gain_tmp] = 0.0F;
    rty_acc_bias_B[Translation_Fusion_B.rtb_GPS_gain_tmp] +=
      Translation_Fusion_B.MatrixMultiply4_n[Translation_Fusion_B.rtb_GPS_gain_tmp]
      * Translation_Fusion_B.rtb_Int_X_idx_2;
    rty_acc_bias_B[Translation_Fusion_B.rtb_GPS_gain_tmp] +=
      Translation_Fusion_B.MatrixMultiply4_n[Translation_Fusion_B.rtb_GPS_gain_tmp
      + 3] * Translation_Fusion_B.rtb_Int_X_idx_3;
    rty_acc_bias_B[Translation_Fusion_B.rtb_GPS_gain_tmp] +=
      Translation_Fusion_B.MatrixMultiply4_n[Translation_Fusion_B.rtb_GPS_gain_tmp
      + 6] * Translation_Fusion_B.TmpSignalConversionAtMultip[2];
  }

  Translation_Fusion_B.DiscreteTimeIntegrator_gsh[0] =
    Translation_Fusion_B.rtb_Switch_l_idx_0 - rty_Translation_data_POS_xy_O_m[0];
  Translation_Fusion_B.DiscreteTimeIntegrator_gsh[1] =
    Translation_Fusion_B.rtb_Switch_l_l - rty_Translation_data_POS_xy_O_m[1];
  Translation_Fusion_B.gps_pos_valid_mk = (Translation_Fusion_B.gps_pos_valid_mk
    || Translation_Fusion_B.GPS_Good);
  if (Translation_Fusion_B.Compare_ko) {
    for (Translation_Fusion_B.i = 0; Translation_Fusion_B.i < 6;
         Translation_Fusion_B.i++) {
      Translation_Fusion_B.Assignment[Translation_Fusion_B.i] =
        Translation_Fusion_P_g.Constant1_Value_g2;
    }
  } else {
    Translation_Fusion_B.Assignment[0] = Translation_Fusion_P_g.Gain1_Gain_n *
      Translation_Fusion_B.Correct_x.Multiply[0];
    Translation_Fusion_B.Assignment[1] = Translation_Fusion_P_g.Gain1_Gain_n *
      Translation_Fusion_B.Correct_y.Multiply[0];
    Translation_Fusion_B.Assignment[2] = Translation_Fusion_P_g.Gain1_Gain_n *
      Translation_Fusion_B.Correct_x.Multiply[1];
    Translation_Fusion_B.Assignment[3] = Translation_Fusion_P_g.Gain1_Gain_n *
      Translation_Fusion_B.Correct_y.Multiply[1];
    Translation_Fusion_B.Assignment[4] = Translation_Fusion_P_g.Gain1_Gain_n *
      Translation_Fusion_B.Correct_x.Multiply[2];
    Translation_Fusion_B.Assignment[5] = Translation_Fusion_P_g.Gain1_Gain_n *
      Translation_Fusion_B.Correct_y.Multiply[2];
  }

  for (Translation_Fusion_B.rtb_GPS_gain_tmp = 0;
       Translation_Fusion_B.rtb_GPS_gain_tmp < 6;
       Translation_Fusion_B.rtb_GPS_gain_tmp++) {
    Translation_Fusion_B.Assignment[Translation_Fusion_B.rtb_GPS_gain_tmp] +=
      Translation_Fusion_B.ManualSwitch[Translation_Fusion_B.rtb_GPS_gain_tmp];
  }

  Translation_Fusion_B.rtb_Min_c_idx_0 = (real32_T)
    ((*rtu_Sensor_GPS_data_mue_rad -
      Translation_Fusion_B.rtb_WGS84_pos_ref_idx_0) *
     Translation_Fusion_B.rtb_WGS84_derivatives_idx_0);
  Translation_Fusion_B.rtb_Int_X_idx_2 = (real32_T)
    ((*rtu_Sensor_GPS_data_lambda_rad -
      Translation_Fusion_B.rtb_WGS84_pos_ref_idx_1) *
     Translation_Fusion_B.rtb_WGS84_derivatives_idx_1);
  Translation_Fusion_B.rtk_pos_valid = (Translation_Fusion_B.gps_pos_valid_mk &&
    ((real32_T)fabs(Translation_Fusion_B.Assignment[0] -
                    Translation_Fusion_B.rtb_Min_c_idx_0) <=
     Translation_Fusion_P_g.CompareToConstant1_const_is));
  Translation_Fusion_B.rtb_LogicalOperator1_ls_idx_1 =
    (Translation_Fusion_B.gps_pos_valid_mk && ((real32_T)fabs
      (Translation_Fusion_B.Assignment[1] - Translation_Fusion_B.rtb_Int_X_idx_2)
      <= Translation_Fusion_P_g.CompareToConstant1_const_is));
  if (Translation_Fusion_DW.DiscreteTimeIntegrator_IC_LO_mc != 0) {
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_el[0] =
      *rtu_Sensor_GPS_data_Pos_quality;
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_el[1] =
      *rtu_Sensor_GPS_data_Pos_quality;
  }

  if (Translation_Fusion_B.rtk_pos_valid &&
      (Translation_Fusion_DW.DiscreteTimeIntegrator_PrevR_pz[0] <= 0)) {
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_el[0] =
      *rtu_Sensor_GPS_data_Pos_quality;
  }

  if (Translation_Fusion_B.rtb_LogicalOperator1_ls_idx_1 &&
      (Translation_Fusion_DW.DiscreteTimeIntegrator_PrevR_pz[1] <= 0)) {
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_el[1] =
      *rtu_Sensor_GPS_data_Pos_quality;
  }

  mw_arm_sqrt_f32(Translation_Fusion_B.DiscreteTimeIntegrator_gsh[0] *
                  Translation_Fusion_B.DiscreteTimeIntegrator_gsh[0] +
                  Translation_Fusion_B.DiscreteTimeIntegrator_gsh[1] *
                  Translation_Fusion_B.DiscreteTimeIntegrator_gsh[1],
                  &Translation_Fusion_B.rtb_Int_X_idx_3);
  if (Translation_Fusion_DW.DiscreteTimeIntegrator_IC_LOA_l != 0) {
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_g0[0] =
      Translation_Fusion_B.rtb_Int_X_idx_3;
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_g0[1] =
      Translation_Fusion_B.rtb_Int_X_idx_3;
  }

  Translation_Fusion_B.gps_pos_valid_mk = (*rtu_mode ==
    Translation_Fusion_P_g.CompareToConstant2_const_cc);
  Translation_Fusion_B.RTK_Vel_good = ((*rtu_Armed) &&
    Translation_Fusion_B.gps_pos_valid_mk);
  if (Translation_Fusion_B.rtk_pos_valid &&
      (Translation_Fusion_DW.DiscreteTimeIntegrator_PrevR_gr[0] <= 0)) {
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_g0[0] =
      Translation_Fusion_B.rtb_Int_X_idx_3;
  }

  Translation_Fusion_B.rtb_DiscreteTimeIntegrator1_l_l =
    Translation_Fusion_B.rtb_Min_c_idx_0 -
    Translation_Fusion_B.rtb_DiscreteTimeIntegrator1_lt_;
  if (Translation_Fusion_B.rtb_DiscreteTimeIntegrator1_l_l >
      Translation_Fusion_P_g.Saturation_UpperSat_oa) {
    Translation_Fusion_B.rtb_DiscreteTimeIntegrator1_l_l =
      Translation_Fusion_P_g.Saturation_UpperSat_oa;
  } else {
    if (Translation_Fusion_B.rtb_DiscreteTimeIntegrator1_l_l <
        Translation_Fusion_P_g.Saturation_LowerSat_ot) {
      Translation_Fusion_B.rtb_DiscreteTimeIntegrator1_l_l =
        Translation_Fusion_P_g.Saturation_LowerSat_ot;
    }
  }

  Translation_Fusion_B.gps_pos_valid = !rtb_Reset_TF_tmp;
  Translation_Fusion_B.Compare_mr = (Translation_Fusion_B.gps_pos_valid &&
    Translation_Fusion_B.rtk_pos_valid);
  Translation_Fusion_B.LogicalOperator1_ks = ((int32_T)((uint32_T)
    ((((Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_g0[0] >=
        Translation_Fusion_P_g.CompareToConstant1_const_h) &&
       (Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_el[0] >=
        Translation_Fusion_P_g.CompareToConstant_const_d) &&
       Translation_Fusion_B.NOT1) || Translation_Fusion_B.RTK_Vel_good) &&
     Translation_Fusion_B.Compare_mr) + (Translation_Fusion_DW.Delay_DSTATE_pc[0]
    && Translation_Fusion_B.Compare_mr)) != 0);
  Translation_Fusion_B.rtb_DiscreteTimeIntegrator1_lt_ =
    Translation_Fusion_B.rtb_DiscreteTimeIntegrator1_l_l;
  if (Translation_Fusion_B.rtb_LogicalOperator1_ls_idx_1 &&
      (Translation_Fusion_DW.DiscreteTimeIntegrator_PrevR_gr[1] <= 0)) {
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_g0[1] =
      Translation_Fusion_B.rtb_Int_X_idx_3;
  }

  Translation_Fusion_B.rtb_DiscreteTimeIntegrator1_l_l =
    Translation_Fusion_B.rtb_Int_X_idx_2 -
    Translation_Fusion_B.rtb_DiscreteTimeIntegrator1_l_p;
  if (Translation_Fusion_B.rtb_DiscreteTimeIntegrator1_l_l >
      Translation_Fusion_P_g.Saturation_UpperSat_oa) {
    Translation_Fusion_B.rtb_DiscreteTimeIntegrator1_l_l =
      Translation_Fusion_P_g.Saturation_UpperSat_oa;
  } else {
    if (Translation_Fusion_B.rtb_DiscreteTimeIntegrator1_l_l <
        Translation_Fusion_P_g.Saturation_LowerSat_ot) {
      Translation_Fusion_B.rtb_DiscreteTimeIntegrator1_l_l =
        Translation_Fusion_P_g.Saturation_LowerSat_ot;
    }
  }

  Translation_Fusion_B.Compare_mr = (Translation_Fusion_B.gps_pos_valid &&
    Translation_Fusion_B.rtb_LogicalOperator1_ls_idx_1);
  Translation_Fusion_B.Compare_mr = ((int32_T)((uint32_T)
    ((((Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_g0[1] >=
        Translation_Fusion_P_g.CompareToConstant1_const_h) &&
       (Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_el[1] >=
        Translation_Fusion_P_g.CompareToConstant_const_d) &&
       Translation_Fusion_B.NOT1) || Translation_Fusion_B.RTK_Vel_good) &&
     Translation_Fusion_B.Compare_mr) + (Translation_Fusion_DW.Delay_DSTATE_pc[1]
    && Translation_Fusion_B.Compare_mr)) != 0);
  if (Translation_Fusion_DW.obj_a.TunablePropsChanged) {
    Translation_Fusion_DW.obj_a.TunablePropsChanged = false;
  }

  if (Translation_Fusion_DW.obj_a.pStatistic->isInitialized != 1) {
    Translation_Fusion_DW.obj_a.pStatistic->isSetupComplete = false;
    Translation_Fusion_DW.obj_a.pStatistic->isInitialized = 1;
    Translation_Fusion_DW.obj_a.pStatistic->pCumSum = 0.0F;
    Translation_Fusion_DW.obj_a.pStatistic->pCumRevIndex = 1.0F;
    Translation_Fusion_DW.obj_a.pStatistic->isSetupComplete = true;
    Translation_Fusion_DW.obj_a.pStatistic->pCumSum = 0.0F;
    Translation_Fusion_DW.obj_a.pStatistic->pCumSumRev[0] = 0.0F;
    Translation_Fusion_DW.obj_a.pStatistic->pCumSumRev[0] = 0.0F;
    Translation_Fusion_DW.obj_a.pStatistic->pCumSumRev[1] = 0.0F;
    Translation_Fusion_DW.obj_a.pStatistic->pCumSumRev[1] = 0.0F;
    Translation_Fusion_DW.obj_a.pStatistic->pCumSumRev[2] = 0.0F;
    Translation_Fusion_DW.obj_a.pStatistic->pCumSumRev[2] = 0.0F;
    Translation_Fusion_DW.obj_a.pStatistic->pCumRevIndex = 1.0F;
  }

  Translation_Fusion_B.Sum_ol =
    Translation_Fusion_DW.obj_a.pStatistic->pCumRevIndex;
  Translation_Fusion_B.csum = Translation_Fusion_DW.obj_a.pStatistic->pCumSum;
  Translation_Fusion_B.sfor_R_O_mDs2[0] =
    Translation_Fusion_DW.obj_a.pStatistic->pCumSumRev[0];
  Translation_Fusion_B.sfor_R_O_mDs2[1] =
    Translation_Fusion_DW.obj_a.pStatistic->pCumSumRev[1];
  Translation_Fusion_B.sfor_R_O_mDs2[2] =
    Translation_Fusion_DW.obj_a.pStatistic->pCumSumRev[2];
  Translation_Fusion_B.csum += *rtu_Rotation_Psi_dot_fused;
  Translation_Fusion_B.sfor_R_O_mDs2[(int32_T)Translation_Fusion_B.Sum_ol - 1] =
    *rtu_Rotation_Psi_dot_fused;
  if (Translation_Fusion_B.Sum_ol != 3.0F) {
    Translation_Fusion_B.Sum_ol++;
  } else {
    Translation_Fusion_B.Sum_ol = 1.0F;
    Translation_Fusion_B.csum = 0.0F;
    Translation_Fusion_B.sfor_R_O_mDs2[1] += Translation_Fusion_B.sfor_R_O_mDs2
      [2];
    Translation_Fusion_B.sfor_R_O_mDs2[0] += Translation_Fusion_B.sfor_R_O_mDs2
      [1];
  }

  Translation_Fusion_DW.obj_a.pStatistic->pCumSum = Translation_Fusion_B.csum;
  Translation_Fusion_DW.obj_a.pStatistic->pCumSumRev[0] =
    Translation_Fusion_B.sfor_R_O_mDs2[0];
  Translation_Fusion_DW.obj_a.pStatistic->pCumSumRev[1] =
    Translation_Fusion_B.sfor_R_O_mDs2[1];
  Translation_Fusion_DW.obj_a.pStatistic->pCumSumRev[2] =
    Translation_Fusion_B.sfor_R_O_mDs2[2];
  Translation_Fusion_DW.obj_a.pStatistic->pCumRevIndex =
    Translation_Fusion_B.Sum_ol;
  *rty_Translation_data_GPS_Vel_Va = (Translation_Fusion_B.GPS_Vel_Vaild ||
    Translation_Fusion_B.rtk_pos_valid_m);
  if (Translation_Fusion_B.LogicalOperator1_ks) {
    Translation_Fusion_B.rtb_DiscreteTimeIntegrator1_l_p =
      Translation_Fusion_B.rtb_Switch_l_idx_0;
  } else {
    Translation_Fusion_B.rtb_DiscreteTimeIntegrator1_l_p =
      rty_Translation_data_POS_xy_O_m[0];
  }

  Translation_Fusion_B.Min_h[0] =
    Translation_Fusion_B.rtb_DiscreteTimeIntegrator1_l_p -
    Translation_Fusion_B.rtb_Sum_ec_idx_0;
  if (Translation_Fusion_B.Compare_mr) {
    Translation_Fusion_B.rtb_DiscreteTimeIntegrator1_l_p =
      Translation_Fusion_B.rtb_Switch_l_l;
  } else {
    Translation_Fusion_B.rtb_DiscreteTimeIntegrator1_l_p =
      rty_Translation_data_POS_xy_O_m[1];
  }

  Translation_Fusion_B.Min_h[1] =
    Translation_Fusion_B.rtb_DiscreteTimeIntegrator1_l_p -
    Translation_Fusion_B.rtb_Sum_ec_g;
  *rty_Translation_data_POS_reset_ = (Translation_Fusion_B.LogicalOperator2_h ||
    Translation_Fusion_B.Compare_i);
  if (*rty_Pos_Init_flg) {
    if (Translation_Fusion_B.rtb_WGS84_derivatives_idx_0 < 0.0) {
      Translation_Fusion_B.rtb_DataTypeConversion3_g_idx_0 = -1.0;
    } else if (Translation_Fusion_B.rtb_WGS84_derivatives_idx_0 > 0.0) {
      Translation_Fusion_B.rtb_DataTypeConversion3_g_idx_0 = 1.0;
    } else if (Translation_Fusion_B.rtb_WGS84_derivatives_idx_0 == 0.0) {
      Translation_Fusion_B.rtb_DataTypeConversion3_g_idx_0 =
        Translation_Fusion_P_g.Constant_Value_pi;
    } else {
      Translation_Fusion_B.rtb_DataTypeConversion3_g_idx_0 = (rtNaN);
    }

    Translation_Fusion_B.rtb_WGS84_position_idx_0 = fabs
      (Translation_Fusion_B.rtb_WGS84_derivatives_idx_0);
    if (Translation_Fusion_B.rtb_WGS84_position_idx_0 >
        Translation_Fusion_P_g.Saturation_UpperSat_i) {
      Translation_Fusion_B.rtb_WGS84_position_idx_0 =
        Translation_Fusion_P_g.Saturation_UpperSat_i;
    } else {
      if (Translation_Fusion_B.rtb_WGS84_position_idx_0 <
          Translation_Fusion_P_g.Zero_Value_Exclusion_thr_f) {
        Translation_Fusion_B.rtb_WGS84_position_idx_0 =
          Translation_Fusion_P_g.Zero_Value_Exclusion_thr_f;
      }
    }

    Translation_Fusion_B.rtb_test1_k_idx_0 =
      (Translation_Fusion_B.rtb_Switch_l_idx_0 -
       Translation_Fusion_B.rtb_Sum_ec_idx_0) /
      (Translation_Fusion_B.rtb_WGS84_position_idx_0 *
       Translation_Fusion_B.rtb_DataTypeConversion3_g_idx_0);
    if (Translation_Fusion_B.rtb_WGS84_derivatives_idx_1 < 0.0) {
      Translation_Fusion_B.rtb_DataTypeConversion3_g_idx_0 = -1.0;
    } else if (Translation_Fusion_B.rtb_WGS84_derivatives_idx_1 > 0.0) {
      Translation_Fusion_B.rtb_DataTypeConversion3_g_idx_0 = 1.0;
    } else if (Translation_Fusion_B.rtb_WGS84_derivatives_idx_1 == 0.0) {
      Translation_Fusion_B.rtb_DataTypeConversion3_g_idx_0 =
        Translation_Fusion_P_g.Constant_Value_pi;
    } else {
      Translation_Fusion_B.rtb_DataTypeConversion3_g_idx_0 = (rtNaN);
    }

    Translation_Fusion_B.rtb_WGS84_position_idx_0 = fabs
      (Translation_Fusion_B.rtb_WGS84_derivatives_idx_1);
    if (Translation_Fusion_B.rtb_WGS84_position_idx_0 >
        Translation_Fusion_P_g.Saturation_UpperSat_i) {
      Translation_Fusion_B.rtb_WGS84_position_idx_0 =
        Translation_Fusion_P_g.Saturation_UpperSat_i;
    } else {
      if (Translation_Fusion_B.rtb_WGS84_position_idx_0 <
          Translation_Fusion_P_g.Zero_Value_Exclusion_thr_f) {
        Translation_Fusion_B.rtb_WGS84_position_idx_0 =
          Translation_Fusion_P_g.Zero_Value_Exclusion_thr_f;
      }
    }

    Translation_Fusion_B.rtb_test1_k_idx_1 =
      (Translation_Fusion_B.rtb_Switch_l_l - Translation_Fusion_B.rtb_Sum_ec_g) /
      (Translation_Fusion_B.rtb_WGS84_position_idx_0 *
       Translation_Fusion_B.rtb_DataTypeConversion3_g_idx_0);
  } else {
    Translation_Fusion_B.rtb_test1_k_idx_0 =
      Translation_Fusion_P_g.Constant_Value_c[0];
    Translation_Fusion_B.rtb_test1_k_idx_1 =
      Translation_Fusion_P_g.Constant_Value_c[1];
  }

  Translation_Fusion_B.rtb_test1_k_idx_0 +=
    Translation_Fusion_B.rtb_WGS84_pos_ref_idx_0;
  Translation_Fusion_B.rtb_DataTypeConversion3_g_idx_0 =
    Translation_Fusion_B.rtb_test1_k_idx_1 +
    Translation_Fusion_B.rtb_WGS84_pos_ref_idx_1;
  if (Translation_Fusion_B.rtb_test1_k_idx_0 >
      Translation_Fusion_P_g.Saturation_UpperSat_e) {
    *rty_Translation_data_mue_est_ra =
      Translation_Fusion_P_g.Saturation_UpperSat_e;
  } else if (Translation_Fusion_B.rtb_test1_k_idx_0 <
             Translation_Fusion_P_g.Saturation_LowerSat_o) {
    *rty_Translation_data_mue_est_ra =
      Translation_Fusion_P_g.Saturation_LowerSat_o;
  } else {
    *rty_Translation_data_mue_est_ra = Translation_Fusion_B.rtb_test1_k_idx_0;
  }

  if (Translation_Fusion_B.rtb_DataTypeConversion3_g_idx_0 >
      Translation_Fusion_P_g.Saturation1_UpperSat_p) {
    *rty_Translation_data_lambda_est =
      Translation_Fusion_P_g.Saturation1_UpperSat_p;
  } else if (Translation_Fusion_B.rtb_DataTypeConversion3_g_idx_0 <
             Translation_Fusion_P_g.Saturation1_LowerSat_a) {
    *rty_Translation_data_lambda_est =
      Translation_Fusion_P_g.Saturation1_LowerSat_a;
  } else {
    *rty_Translation_data_lambda_est =
      Translation_Fusion_B.rtb_DataTypeConversion3_g_idx_0;
  }

  if (*rty_Pos_Init_flg) {
    if (Translation_Fusion_B.rtb_WGS84_derivatives_idx_0 < 0.0) {
      Translation_Fusion_B.rtb_DataTypeConversion3_g_idx_0 = -1.0;
    } else if (Translation_Fusion_B.rtb_WGS84_derivatives_idx_0 > 0.0) {
      Translation_Fusion_B.rtb_DataTypeConversion3_g_idx_0 = 1.0;
    } else if (Translation_Fusion_B.rtb_WGS84_derivatives_idx_0 == 0.0) {
      Translation_Fusion_B.rtb_DataTypeConversion3_g_idx_0 =
        Translation_Fusion_P_g.Constant_Value_e;
    } else {
      Translation_Fusion_B.rtb_DataTypeConversion3_g_idx_0 = (rtNaN);
    }

    Translation_Fusion_B.rtb_WGS84_position_idx_1 = fabs
      (Translation_Fusion_B.rtb_WGS84_derivatives_idx_0);
    if (Translation_Fusion_B.rtb_WGS84_position_idx_1 >
        Translation_Fusion_P_g.Saturation_UpperSat_k) {
      Translation_Fusion_B.rtb_WGS84_position_idx_1 =
        Translation_Fusion_P_g.Saturation_UpperSat_k;
    } else {
      if (Translation_Fusion_B.rtb_WGS84_position_idx_1 <
          Translation_Fusion_P_g.Zero_Value_Exclusion_thr_a) {
        Translation_Fusion_B.rtb_WGS84_position_idx_1 =
          Translation_Fusion_P_g.Zero_Value_Exclusion_thr_a;
      }
    }

    Translation_Fusion_B.rtb_test1_k_idx_0 = (Translation_Fusion_B.Switch2_pu[0]
      + Translation_Fusion_B.Min_h[0]) /
      (Translation_Fusion_B.rtb_WGS84_position_idx_1 *
       Translation_Fusion_B.rtb_DataTypeConversion3_g_idx_0);
    if (Translation_Fusion_B.rtb_WGS84_derivatives_idx_1 < 0.0) {
      Translation_Fusion_B.rtb_DataTypeConversion3_g_idx_0 = -1.0;
    } else if (Translation_Fusion_B.rtb_WGS84_derivatives_idx_1 > 0.0) {
      Translation_Fusion_B.rtb_DataTypeConversion3_g_idx_0 = 1.0;
    } else if (Translation_Fusion_B.rtb_WGS84_derivatives_idx_1 == 0.0) {
      Translation_Fusion_B.rtb_DataTypeConversion3_g_idx_0 =
        Translation_Fusion_P_g.Constant_Value_e;
    } else {
      Translation_Fusion_B.rtb_DataTypeConversion3_g_idx_0 = (rtNaN);
    }

    Translation_Fusion_B.rtb_WGS84_position_idx_1 = fabs
      (Translation_Fusion_B.rtb_WGS84_derivatives_idx_1);
    if (Translation_Fusion_B.rtb_WGS84_position_idx_1 >
        Translation_Fusion_P_g.Saturation_UpperSat_k) {
      Translation_Fusion_B.rtb_WGS84_position_idx_1 =
        Translation_Fusion_P_g.Saturation_UpperSat_k;
    } else {
      if (Translation_Fusion_B.rtb_WGS84_position_idx_1 <
          Translation_Fusion_P_g.Zero_Value_Exclusion_thr_a) {
        Translation_Fusion_B.rtb_WGS84_position_idx_1 =
          Translation_Fusion_P_g.Zero_Value_Exclusion_thr_a;
      }
    }

    Translation_Fusion_B.rtb_test1_k_idx_1 = (Translation_Fusion_B.Switch2_pu[1]
      + Translation_Fusion_B.Min_h[1]) /
      (Translation_Fusion_B.rtb_WGS84_position_idx_1 *
       Translation_Fusion_B.rtb_DataTypeConversion3_g_idx_0);
  } else {
    Translation_Fusion_B.rtb_test1_k_idx_0 =
      Translation_Fusion_P_g.Constant_Value_i[0];
    Translation_Fusion_B.rtb_test1_k_idx_1 =
      Translation_Fusion_P_g.Constant_Value_i[1];
  }

  Translation_Fusion_B.rtb_test1_k_idx_0 +=
    Translation_Fusion_B.rtb_WGS84_pos_ref_idx_0;
  Translation_Fusion_B.rtb_DataTypeConversion3_g_idx_0 =
    Translation_Fusion_B.rtb_test1_k_idx_1 +
    Translation_Fusion_B.rtb_WGS84_pos_ref_idx_1;
  if (Translation_Fusion_B.rtb_test1_k_idx_0 >
      Translation_Fusion_P_g.Saturation_UpperSat_b) {
    rty_Pos_LL_WGS84_Camera[0] = Translation_Fusion_P_g.Saturation_UpperSat_b;
  } else if (Translation_Fusion_B.rtb_test1_k_idx_0 <
             Translation_Fusion_P_g.Saturation_LowerSat_f) {
    rty_Pos_LL_WGS84_Camera[0] = Translation_Fusion_P_g.Saturation_LowerSat_f;
  } else {
    rty_Pos_LL_WGS84_Camera[0] = Translation_Fusion_B.rtb_test1_k_idx_0;
  }

  if (*rty_Pos_Init_flg) {
    if (Translation_Fusion_B.rtb_WGS84_derivatives_idx_0 < 0.0) {
      Translation_Fusion_B.rtb_WGS84_position_idx_0 = -1.0;
    } else if (Translation_Fusion_B.rtb_WGS84_derivatives_idx_0 > 0.0) {
      Translation_Fusion_B.rtb_WGS84_position_idx_0 = 1.0;
    } else if (Translation_Fusion_B.rtb_WGS84_derivatives_idx_0 == 0.0) {
      Translation_Fusion_B.rtb_WGS84_position_idx_0 =
        Translation_Fusion_P_g.Constant_Value_j;
    } else {
      Translation_Fusion_B.rtb_WGS84_position_idx_0 = (rtNaN);
    }

    Translation_Fusion_B.rtb_WGS84_position_idx_1 = fabs
      (Translation_Fusion_B.rtb_WGS84_derivatives_idx_0);
    if (Translation_Fusion_B.rtb_WGS84_position_idx_1 >
        Translation_Fusion_P_g.Saturation_UpperSat_f) {
      Translation_Fusion_B.rtb_WGS84_position_idx_1 =
        Translation_Fusion_P_g.Saturation_UpperSat_f;
    } else {
      if (Translation_Fusion_B.rtb_WGS84_position_idx_1 <
          Translation_Fusion_P_g.Zero_Value_Exclusion_thr_n) {
        Translation_Fusion_B.rtb_WGS84_position_idx_1 =
          Translation_Fusion_P_g.Zero_Value_Exclusion_thr_n;
      }
    }

    Translation_Fusion_B.rtb_test1_k_idx_0 = Translation_Fusion_B.Min_h[0] /
      (Translation_Fusion_B.rtb_WGS84_position_idx_1 *
       Translation_Fusion_B.rtb_WGS84_position_idx_0);
    if (Translation_Fusion_B.rtb_WGS84_derivatives_idx_1 < 0.0) {
      Translation_Fusion_B.rtb_WGS84_position_idx_0 = -1.0;
    } else if (Translation_Fusion_B.rtb_WGS84_derivatives_idx_1 > 0.0) {
      Translation_Fusion_B.rtb_WGS84_position_idx_0 = 1.0;
    } else if (Translation_Fusion_B.rtb_WGS84_derivatives_idx_1 == 0.0) {
      Translation_Fusion_B.rtb_WGS84_position_idx_0 =
        Translation_Fusion_P_g.Constant_Value_j;
    } else {
      Translation_Fusion_B.rtb_WGS84_position_idx_0 = (rtNaN);
    }

    Translation_Fusion_B.rtb_WGS84_position_idx_1 = fabs
      (Translation_Fusion_B.rtb_WGS84_derivatives_idx_1);
    if (Translation_Fusion_B.rtb_WGS84_position_idx_1 >
        Translation_Fusion_P_g.Saturation_UpperSat_f) {
      Translation_Fusion_B.rtb_WGS84_position_idx_1 =
        Translation_Fusion_P_g.Saturation_UpperSat_f;
    } else {
      if (Translation_Fusion_B.rtb_WGS84_position_idx_1 <
          Translation_Fusion_P_g.Zero_Value_Exclusion_thr_n) {
        Translation_Fusion_B.rtb_WGS84_position_idx_1 =
          Translation_Fusion_P_g.Zero_Value_Exclusion_thr_n;
      }
    }

    Translation_Fusion_B.rtb_test1_k_idx_1 = Translation_Fusion_B.Min_h[1] /
      (Translation_Fusion_B.rtb_WGS84_position_idx_1 *
       Translation_Fusion_B.rtb_WGS84_position_idx_0);
  } else {
    Translation_Fusion_B.rtb_test1_k_idx_0 =
      Translation_Fusion_P_g.Constant_Value_lf[0];
    Translation_Fusion_B.rtb_test1_k_idx_1 =
      Translation_Fusion_P_g.Constant_Value_lf[1];
  }

  Translation_Fusion_B.rtb_test1_k_idx_0 +=
    Translation_Fusion_B.rtb_WGS84_pos_ref_idx_0;
  Translation_Fusion_B.rtb_WGS84_position_idx_0 =
    Translation_Fusion_B.rtb_test1_k_idx_1 +
    Translation_Fusion_B.rtb_WGS84_pos_ref_idx_1;
  if (Translation_Fusion_B.rtb_test1_k_idx_0 >
      Translation_Fusion_P_g.Saturation_UpperSat_eu) {
    *rty_Translation_data_mue_est__e =
      Translation_Fusion_P_g.Saturation_UpperSat_eu;
  } else if (Translation_Fusion_B.rtb_test1_k_idx_0 <
             Translation_Fusion_P_g.Saturation_LowerSat_d) {
    *rty_Translation_data_mue_est__e =
      Translation_Fusion_P_g.Saturation_LowerSat_d;
  } else {
    *rty_Translation_data_mue_est__e = Translation_Fusion_B.rtb_test1_k_idx_0;
  }

  if (Translation_Fusion_B.rtb_WGS84_position_idx_0 >
      Translation_Fusion_P_g.Saturation1_UpperSat_g) {
    *rty_Translation_data_lambda_e_o =
      Translation_Fusion_P_g.Saturation1_UpperSat_g;
  } else if (Translation_Fusion_B.rtb_WGS84_position_idx_0 <
             Translation_Fusion_P_g.Saturation1_LowerSat_f) {
    *rty_Translation_data_lambda_e_o =
      Translation_Fusion_P_g.Saturation1_LowerSat_f;
  } else {
    *rty_Translation_data_lambda_e_o =
      Translation_Fusion_B.rtb_WGS84_position_idx_0;
  }

  if (Translation_Fusion_B.rtb_DataTypeConversion3_g_idx_0 >
      Translation_Fusion_P_g.Saturation1_UpperSat_k) {
    rty_Pos_LL_WGS84_Camera[1] = Translation_Fusion_P_g.Saturation1_UpperSat_k;
  } else if (Translation_Fusion_B.rtb_DataTypeConversion3_g_idx_0 <
             Translation_Fusion_P_g.Saturation1_LowerSat_o) {
    rty_Pos_LL_WGS84_Camera[1] = Translation_Fusion_P_g.Saturation1_LowerSat_o;
  } else {
    rty_Pos_LL_WGS84_Camera[1] =
      Translation_Fusion_B.rtb_DataTypeConversion3_g_idx_0;
  }

  rty_Vel_G[0] = rtu_Rotation_M_OObar[0] * Translation_Fusion_B.rtb_Int_X_idx_0
    + rtu_Rotation_M_OObar[1] * Translation_Fusion_B.rtb_Int_X_idx_1;
  rty_Vel_G[1] = rtu_Rotation_M_OObar[2] * Translation_Fusion_B.rtb_Int_X_idx_0
    + rtu_Rotation_M_OObar[3] * Translation_Fusion_B.rtb_Int_X_idx_1;
  rty_Vel_G[2] = Translation_Fusion_B.middle_thr;
  *rty_Vx_cor = Translation_Fusion_B.MatrixMultiply1_j[0];
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE +=
    Translation_Fusion_P_g.DiscreteTimeIntegrator_gainva_o * (real32_T)
    *rtu_Ongrd_flag;
  if (Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE >=
      Translation_Fusion_P_g.DiscreteTimeIntegrator_UpperSat) {
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE =
      Translation_Fusion_P_g.DiscreteTimeIntegrator_UpperSat;
  } else {
    if (Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE <=
        Translation_Fusion_P_g.DiscreteTimeIntegrator_LowerSat) {
      Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE =
        Translation_Fusion_P_g.DiscreteTimeIntegrator_LowerSat;
    }
  }

  Translation_Fusion_DW.DiscreteTimeIntegrator_PrevRese = (int8_T)
    Translation_Fusion_B.LogicalOperator1;
  Translation_Fusion_DW.Delay2_DSTATE_h[0] =
    Translation_Fusion_DW.Delay2_DSTATE_h[1];
  Translation_Fusion_DW.Delay2_DSTATE_h[1] = *rtu_Rotation_reset_Yaw;
  Translation_Fusion_DW.icLoad = 0U;
  Translation_Fusion_DW.Delay1_DSTATE[0] =
    Translation_Fusion_B.CreateDiagonalMatrix[0];
  Translation_Fusion_DW.Int_X_DSTATE[0] = Translation_Fusion_B.Assignment[2];
  Translation_Fusion_DW.Delay1_DSTATE[1] =
    Translation_Fusion_B.CreateDiagonalMatrix[1];
  Translation_Fusion_DW.Int_X_DSTATE[1] = Translation_Fusion_B.Assignment[3];
  Translation_Fusion_DW.Delay1_DSTATE[2] =
    Translation_Fusion_B.CreateDiagonalMatrix[2];
  Translation_Fusion_DW.Int_X_DSTATE[2] = Translation_Fusion_B.Assignment[4];
  Translation_Fusion_DW.Delay1_DSTATE[3] =
    Translation_Fusion_B.CreateDiagonalMatrix[3];
  Translation_Fusion_DW.Int_X_DSTATE[3] = Translation_Fusion_B.Assignment[5];
  Translation_Fusion_DW.Delay_10_DSTATE[0] = rty_Translation_data_POS_xy_O_m[0];
  Translation_Fusion_DW.Delay_10_DSTATE[1] = rty_Translation_data_POS_xy_O_m[1];
  Translation_Fusion_DW.Delay_2_DSTATE = *rty_Translation_data_h_AGL_m;
  Translation_Fusion_DW.DelayInput1_DSTATE_g = Translation_Fusion_B.Compare_e;
  Translation_Fusion_DW.DelayInput1_DSTATE_k3 = Translation_Fusion_B.Compare_n;
  Translation_Fusion_DW.memory1_PreviousInput[0] =
    Translation_Fusion_B.rtb_WGS84_pos_ref_idx_0;
  Translation_Fusion_DW.memory1_PreviousInput[1] =
    Translation_Fusion_B.rtb_WGS84_pos_ref_idx_1;
  Translation_Fusion_DW.memory1_PreviousInput[2] =
    Translation_Fusion_B.rtb_WGS84_pos_ref_idx_2;
  Translation_Fusion_DW.DelayInput1_DSTATE_g3 =
    Translation_Fusion_B.LogicalOperator3;
  Translation_Fusion_DW.DelayInput1_DSTATE_ku =
    Translation_Fusion_B.LogicalOperator4_a;
  Translation_Fusion_DW.DelayInput1_DSTATE_e =
    Translation_Fusion_B.LogicalOperator_d;
  for (Translation_Fusion_B.i = 0; Translation_Fusion_B.i < 9;
       Translation_Fusion_B.i++) {
    Translation_Fusion_DW.Delay_DSTATE_g[Translation_Fusion_B.i] =
      Translation_Fusion_DW.Delay_DSTATE_g[Translation_Fusion_B.i + 1];
    Translation_Fusion_DW.Delay_DSTATE_j[Translation_Fusion_B.i] =
      Translation_Fusion_B.Product_i[Translation_Fusion_B.i];
  }

  Translation_Fusion_DW.Delay_DSTATE_g[9] = Translation_Fusion_B.Switch3_b2;
  Translation_Fusion_DW.UnitDelay_DSTATE_p = Translation_Fusion_B.Switch3_b2;
  Translation_Fusion_DW.icLoad_k = 0U;
  Translation_Fusion_DW.memory_PreviousInput[0] =
    Translation_Fusion_B.rtb_WGS84_derivatives_idx_0;
  Translation_Fusion_DW.Delay1_DSTATE_n[0] =
    Translation_Fusion_B.MatrixMultiply4_a[0];
  Translation_Fusion_DW.memory_PreviousInput[1] =
    Translation_Fusion_B.rtb_WGS84_derivatives_idx_1;
  Translation_Fusion_DW.Delay1_DSTATE_n[1] =
    Translation_Fusion_B.MatrixMultiply4_a[1];
  Translation_Fusion_DW.memory_PreviousInput[2] =
    Translation_Fusion_B.rtb_WGS84_derivatives_g;
  Translation_Fusion_DW.Delay1_DSTATE_n[2] =
    Translation_Fusion_B.MatrixMultiply4_a[2];
  Translation_Fusion_DW.DelayInput1_DSTATE_bh = *rtu_hover_flag;
  Translation_Fusion_DW.Delay1_DSTATE_l =
    Translation_Fusion_B.FixPtRelationalOperator_oo;
  Translation_Fusion_DW.icLoad_ki = 0U;
  Translation_Fusion_DW.Delay_DSTATE =
    Translation_Fusion_B.DiscreteTimeIntegrator_am;
  Translation_Fusion_DW.icLoad_h = 0U;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE_k +=
    Translation_Fusion_P_g.DiscreteTimeIntegrator_gainva_d * (real32_T)
    Translation_Fusion_B.Compare_epn;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE_g +=
    Translation_Fusion_P_g.DiscreteTimeIntegrator_gainva_g * (real32_T)
    Translation_Fusion_B.Compare_jn;
  Translation_Fusion_DW.DiscreteTimeIntegrator_PrevRe_h = (int8_T)
    Translation_Fusion_B.LogicalOperator_mw;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_k0 +=
    Translation_Fusion_P_g.DiscreteTimeIntegrator_gainv_oa * (real32_T)
    Translation_Fusion_B.Compare_fx;
  Translation_Fusion_DW.DiscreteTimeIntegrator_PrevRe_b = (int8_T)
    Translation_Fusion_B.LogicalOperator_ok;
  Translation_Fusion_DW.DiscreteTimeIntegrator_IC_LOADI = 0U;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE_o +=
    Translation_Fusion_P_g.DiscreteTimeIntegrator_gainva_p *
    Translation_Fusion_B.Switch4;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE_p +=
    Translation_Fusion_P_g.DiscreteTimeIntegrator_gainv_gv * (real32_T)
    Translation_Fusion_B.Compare_bnu;
  if (Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE_p >=
      Translation_Fusion_P_g.DiscreteTimeIntegrator_UpperS_f) {
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE_p =
      Translation_Fusion_P_g.DiscreteTimeIntegrator_UpperS_f;
  } else {
    if (Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE_p <=
        Translation_Fusion_P_g.DiscreteTimeIntegrator_LowerS_k) {
      Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE_p =
        Translation_Fusion_P_g.DiscreteTimeIntegrator_LowerS_k;
    }
  }

  Translation_Fusion_DW.DiscreteTimeIntegrator_PrevR_hl = (int8_T)
    Translation_Fusion_B.LogicalOperator1_f;
  Translation_Fusion_DW.DelayInput1_DSTATE_k2 = *rtu_Sensor_Vision_data_timestam;
  Translation_Fusion_DW.DiscreteTimeIntegrator1_DSTATE +=
    Translation_Fusion_P_g.DiscreteTimeIntegrator1_gainval *
    Translation_Fusion_B.DiscreteTimeIntegrator_n;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE_n +=
    Translation_Fusion_P_g.DiscreteTimeIntegrator_gainva_c * (real32_T)
    Translation_Fusion_B.Compare_gj;
  if (Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE_n >=
      Translation_Fusion_P_g.DiscreteTimeIntegrator_UpperS_o) {
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE_n =
      Translation_Fusion_P_g.DiscreteTimeIntegrator_UpperS_o;
  } else {
    if (Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE_n <=
        Translation_Fusion_P_g.DiscreteTimeIntegrator_LowerS_e) {
      Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE_n =
        Translation_Fusion_P_g.DiscreteTimeIntegrator_LowerS_e;
    }
  }

  Translation_Fusion_DW.DiscreteTimeIntegrator_PrevRe_g = (int8_T)
    Translation_Fusion_B.LogicalOperator1_k;
  Translation_Fusion_DW.DelayInput1_DSTATE = *rtu_Sensor_GPS_data_Timestamp_m;
  Translation_Fusion_DW.Delay_DSTATE_k = Translation_Fusion_B.MatrixMultiply4_a
    [0];
  Translation_Fusion_DW.DiscreteTimeIntegrator_IC_LOA_p = 0U;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE_a +=
    Translation_Fusion_P_g.DiscreteTimeIntegrator_gainva_a *
    Translation_Fusion_B.Gain_b4;
  Translation_Fusion_DW.Delay_DSTATE_p2 =
    Translation_Fusion_B.DataTypeConversion1_p;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE_h +=
    Translation_Fusion_P_g.DiscreteTimeIntegrator_gainv_dv *
    Translation_Fusion_P_g.Constant_Value_d4;
  if (Translation_Fusion_B.Relay > 0.0F) {
    Translation_Fusion_DW.DiscreteTimeIntegrator_PrevRe_n = 1;
  } else if (Translation_Fusion_B.Relay < 0.0F) {
    Translation_Fusion_DW.DiscreteTimeIntegrator_PrevRe_n = -1;
  } else if (Translation_Fusion_B.Relay == 0.0F) {
    Translation_Fusion_DW.DiscreteTimeIntegrator_PrevRe_n = 0;
  } else {
    Translation_Fusion_DW.DiscreteTimeIntegrator_PrevRe_n = 2;
  }

  Translation_Fusion_DW.Delay1_DSTATE_o[0] =
    Translation_Fusion_B.rtb_Int_X_idx_0;
  Translation_Fusion_DW.Delay1_DSTATE_o[1] =
    Translation_Fusion_B.rtb_Int_X_idx_1;
  Translation_Fusion_DW.Delay_DSTATE_o5 = (Translation_Fusion_B.Relay +
    (real32_T)Translation_Fusion_B.LogicalOperator_ob != 0.0F);
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_ax +=
    Translation_Fusion_P_g.DiscreteTimeIntegrator_gainva_n *
    Translation_Fusion_P_g.Constant_Value_j0;
  if (Translation_Fusion_B.Relay > 0.0F) {
    Translation_Fusion_DW.DiscreteTimeIntegrator_PrevR_bx = 1;
  } else if (Translation_Fusion_B.Relay < 0.0F) {
    Translation_Fusion_DW.DiscreteTimeIntegrator_PrevR_bx = -1;
  } else if (Translation_Fusion_B.Relay == 0.0F) {
    Translation_Fusion_DW.DiscreteTimeIntegrator_PrevR_bx = 0;
  } else {
    Translation_Fusion_DW.DiscreteTimeIntegrator_PrevR_bx = 2;
  }

  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE_f +=
    Translation_Fusion_P_g.DiscreteTimeIntegrator_gainv_gl * (real32_T)
    Translation_Fusion_B.Vision_bad;
  if (Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE_f >=
      Translation_Fusion_P_g.DiscreteTimeIntegrator_UpperS_d) {
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE_f =
      Translation_Fusion_P_g.DiscreteTimeIntegrator_UpperS_d;
  } else {
    if (Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE_f <=
        Translation_Fusion_P_g.DiscreteTimeIntegrator_LowerS_f) {
      Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE_f =
        Translation_Fusion_P_g.DiscreteTimeIntegrator_LowerS_f;
    }
  }

  Translation_Fusion_DW.DiscreteTimeIntegrator_PrevRe_f = (int8_T)
    Translation_Fusion_B.Vision_Unvalid;
  Translation_Fusion_DW.Delay_DSTATE_d =
    Translation_Fusion_B.DataTypeConversion1_b;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_nz +=
    Translation_Fusion_P_g.DiscreteTimeIntegrator_gainva_m *
    Translation_Fusion_P_g.Constant_Value_go;
  Translation_Fusion_DW.DiscreteTimeIntegrator_PrevR_n3 = (int8_T)
    Translation_Fusion_B.Compare_k;
  Translation_Fusion_DW.Delay_DSTATE_db = ((int32_T)((uint32_T)
    *rtu_Sensor_Sonar_data_sonar_val + Translation_Fusion_B.LogicalOperator_i)
    != 0);
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_a3 +=
    Translation_Fusion_P_g.DiscreteTimeIntegrator_gainv_o3 *
    Translation_Fusion_P_g.Constant_Value_mf;
  Translation_Fusion_DW.DiscreteTimeIntegrator_PrevRe_c = (int8_T)
    *rtu_Sensor_Sonar_data_sonar_val;
  Translation_Fusion_DW.Delay_DSTATE_c = Translation_Fusion_B.MatrixMultiply4_a
    [0];
  Translation_Fusion_DW.DiscreteTimeIntegrator1_DSTAT_k +=
    Translation_Fusion_P_g.DiscreteTimeIntegrator1_gainv_a *
    Translation_Fusion_B.DiscreteTimeIntegrator_gf;
  Translation_Fusion_DW.Delay_DSTATE_h =
    Translation_Fusion_B.DataTypeConversion1_pq;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_pp +=
    Translation_Fusion_P_g.DiscreteTimeIntegrator_gainva_k *
    Translation_Fusion_P_g.Constant_Value_aj;
  Translation_Fusion_DW.DiscreteTimeIntegrator_PrevRe_m = (int8_T)
    Translation_Fusion_B.Compare_b5;
  Translation_Fusion_DW.DiscreteTimeIntegrator1_DSTAT_a +=
    Translation_Fusion_P_g.DiscreteTimeIntegrator1_gainv_p *
    Translation_Fusion_B.DiscreteTimeIntegrator_j1;
  Translation_Fusion_DW.Delay_DSTATE_ch =
    Translation_Fusion_B.DataTypeConversion1_m;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_o4 +=
    Translation_Fusion_P_g.DiscreteTimeIntegrator_gainva_f *
    Translation_Fusion_P_g.Constant_Value_cx;
  Translation_Fusion_DW.DiscreteTimeIntegrator_PrevR_bd = (int8_T)
    Translation_Fusion_B.Compare_if;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE_e +=
    Translation_Fusion_P_g.DiscreteTimeIntegrator_gainv_ci * (real32_T)
    *rtu_hover_flag;
  if (Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE_e >=
      Translation_Fusion_P_g.DiscreteTimeIntegrator_UpperS_l) {
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE_e =
      Translation_Fusion_P_g.DiscreteTimeIntegrator_UpperS_l;
  } else {
    if (Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE_e <=
        Translation_Fusion_P_g.DiscreteTimeIntegrator_LowerS_g) {
      Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE_e =
        Translation_Fusion_P_g.DiscreteTimeIntegrator_LowerS_g;
    }
  }

  Translation_Fusion_DW.DiscreteTimeIntegrator_PrevR_mc = (int8_T)
    rtb_LogicalOperator1_n_tmp;
  Translation_Fusion_DW.DiscreteTimeIntegrator_IC_LOA_a = 0U;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_oe +=
    Translation_Fusion_P_g.DiscreteTimeIntegrator_gainv_dp *
    Translation_Fusion_B.Switch1_k;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_hu +=
    Translation_Fusion_P_g.DiscreteTimeIntegrator_gainva_l * (real32_T)
    Translation_Fusion_B.Compare_o4;
  if (Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_hu >=
      Translation_Fusion_P_g.DiscreteTimeIntegrator_UpperS_e) {
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_hu =
      Translation_Fusion_P_g.DiscreteTimeIntegrator_UpperS_e;
  } else {
    if (Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_hu <=
        Translation_Fusion_P_g.DiscreteTimeIntegrator_Lower_ec) {
      Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_hu =
        Translation_Fusion_P_g.DiscreteTimeIntegrator_Lower_ec;
    }
  }

  Translation_Fusion_DW.DiscreteTimeIntegrator_PrevR_br = (int8_T)
    Translation_Fusion_B.FixPtRelationalOperator_k;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE_j +=
    Translation_Fusion_P_g.DiscreteTimeIntegrator_gainv_pg * (real32_T)
    Translation_Fusion_B.Switch_dy;
  if (Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE_j >=
      Translation_Fusion_P_g.DiscreteTimeIntegrator_Upper_d0) {
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE_j =
      Translation_Fusion_P_g.DiscreteTimeIntegrator_Upper_d0;
  } else {
    if (Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE_j <=
        Translation_Fusion_P_g.DiscreteTimeIntegrator_LowerS_n) {
      Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE_j =
        Translation_Fusion_P_g.DiscreteTimeIntegrator_LowerS_n;
    }
  }

  Translation_Fusion_DW.DiscreteTimeIntegrator_PrevRe_i = (int8_T)
    Translation_Fusion_B.LogicalOperator1_i;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_hc +=
    Translation_Fusion_P_g.DiscreteTimeIntegrator_gainv_l4 * (real32_T)
    *rtu_hover_flag;
  if (Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_hc >=
      Translation_Fusion_P_g.DiscreteTimeIntegrator_Upper_ex) {
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_hc =
      Translation_Fusion_P_g.DiscreteTimeIntegrator_Upper_ex;
  } else {
    if (Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_hc <=
        Translation_Fusion_P_g.DiscreteTimeIntegrator_LowerS_o) {
      Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_hc =
        Translation_Fusion_P_g.DiscreteTimeIntegrator_LowerS_o;
    }
  }

  Translation_Fusion_DW.DiscreteTimeIntegrator_PrevRe_j = (int8_T)
    rtb_LogicalOperator1_n_tmp;
  Translation_Fusion_DW.DelayInput1_DSTATE_a = *rtu_Sensor_GPS_data_Timestamp_m;
  Translation_Fusion_DW.Delay_DSTATE_jd = Translation_Fusion_B.En_VO_Correct;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE_c +=
    Translation_Fusion_P_g.DiscreteTimeIntegrator_gainv_lw *
    Translation_Fusion_P_g.Constant_Value_nz;
  if (Translation_Fusion_B.Relay_e > 0.0F) {
    Translation_Fusion_DW.DiscreteTimeIntegrator_PrevR_g2 = 1;
  } else if (Translation_Fusion_B.Relay_e < 0.0F) {
    Translation_Fusion_DW.DiscreteTimeIntegrator_PrevR_g2 = -1;
  } else if (Translation_Fusion_B.Relay_e == 0.0F) {
    Translation_Fusion_DW.DiscreteTimeIntegrator_PrevR_g2 = 0;
  } else {
    Translation_Fusion_DW.DiscreteTimeIntegrator_PrevR_g2 = 2;
  }

  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_ag +=
    Translation_Fusion_P_g.DiscreteTimeIntegrator_gainv_pf *
    Translation_Fusion_P_g.Constant_Value_g1;
  Translation_Fusion_DW.DiscreteTimeIntegrator_PrevRe_p = (int8_T)
    Translation_Fusion_B.P_RTK_update_flg;
  Translation_Fusion_DW.DelayInput1_DSTATE_p = *rtu_Sensor_RTK_Data_Timestamp_m;
  Translation_Fusion_DW.icLoad_g = 0U;
  for (Translation_Fusion_B.i = 0; Translation_Fusion_B.i < 39;
       Translation_Fusion_B.i++) {
    Translation_Fusion_DW.x_delay_DSTATE[Translation_Fusion_B.i] =
      Translation_Fusion_DW.x_delay_DSTATE[Translation_Fusion_B.i + 1];
  }

  Translation_Fusion_DW.x_delay_DSTATE[39] = Translation_Fusion_B.Switch_d[0];
  Translation_Fusion_DW.icLoad_kg = 0U;
  for (Translation_Fusion_B.i = 0; Translation_Fusion_B.i < 139;
       Translation_Fusion_B.i++) {
    Translation_Fusion_DW.x_delay1_DSTATE[Translation_Fusion_B.i] =
      Translation_Fusion_DW.x_delay1_DSTATE[Translation_Fusion_B.i + 1];
  }

  Translation_Fusion_DW.x_delay1_DSTATE[139] = Translation_Fusion_B.Switch_d[1];
  Translation_Fusion_DW.DelayInput1_DSTATE_n =
    Translation_Fusion_B.LogicalOperator_l;
  Translation_Fusion_DW.Memory_PreviousInput = *rtu_Sensor_RTK_Data_vel_D;
  Translation_Fusion_DW.DelayInput1_DSTATE_j = *rtu_Sensor_RTK_Data_Timestamp_m;
  Translation_Fusion_DW.Delay_DSTATE_d4 = Translation_Fusion_B.En_GPS_Correct_c;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_gk +=
    Translation_Fusion_P_g.DiscreteTimeIntegrator_gainv_no *
    Translation_Fusion_P_g.Constant_Value_m4;
  Translation_Fusion_DW.DiscreteTimeIntegrator_PrevR_gd = (int8_T)
    Translation_Fusion_B.LogicalOperator1_g;
  Translation_Fusion_DW.Memory1_PreviousInput = (real32_T)
    Translation_Fusion_B.rtb_Saturation_fo_tmp;
  Translation_Fusion_DW.Delay_DSTATE_jg = Translation_Fusion_B.LogicalOperator_d;
  Translation_Fusion_DW.Delay1_DSTATE_b0[0] =
    Translation_Fusion_DW.Delay1_DSTATE_b0[1];
  Translation_Fusion_DW.Delay1_DSTATE_b0[1] =
    Translation_Fusion_B.LogicalOperator_d;
  Translation_Fusion_DW.Memory_PreviousInput_o = Translation_Fusion_B.Relay1_a;
  Translation_Fusion_DW.DiscreteTimeIntegrator_IC_LOA_b = 0U;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_pn +=
    Translation_Fusion_P_g.DiscreteTimeIntegrator_gainv_a4 *
    Translation_Fusion_B.Inverse_h;
  Translation_Fusion_DW.DiscreteTimeIntegrator_PrevR_hj = (int8_T)
    Translation_Fusion_B.rtk_pos_valid_h;
  Translation_Fusion_DW.DiscreteTimeIntegrator1_DSTAT_h[0] +=
    Translation_Fusion_P_g.DiscreteTimeIntegrator1_gainv_n *
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_in[0];
  Translation_Fusion_DW.DiscreteTimeIntegrator1_DSTAT_h[1] +=
    Translation_Fusion_P_g.DiscreteTimeIntegrator1_gainv_n *
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_in[1];
  Translation_Fusion_DW.DiscreteTimeIntegrator1_DSTAT_h[2] +=
    Translation_Fusion_P_g.DiscreteTimeIntegrator1_gainv_n *
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_in[2];
  Translation_Fusion_DW.DelayInput1_DSTATE_j3 = *rtu_Sensor_Sonar_data_timestamp;
  Translation_Fusion_DW.UD_DSTATE = *rtu_Sensor_Sonar_data_h_grd_son;
  Translation_Fusion_DW.DiscreteTimeIntegrator5_DSTATE +=
    Translation_Fusion_P_g.DiscreteTimeIntegrator5_gainval *
    Translation_Fusion_B.Gain2_ll;
  Translation_Fusion_DW.DiscreteTimeIntegrator5_DSTAT_d +=
    Translation_Fusion_P_g.DiscreteTimeIntegrator5_gainv_k *
    Translation_Fusion_B.Gain2_l;
  Translation_Fusion_DW.Delay_DSTATE_k1 = Translation_Fusion_B.rtk_pos_valid_j;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_fa +=
    Translation_Fusion_P_g.DiscreteTimeIntegrator_gainv_cj *
    Translation_Fusion_P_g.Constant_Value_c3;
  Translation_Fusion_DW.DiscreteTimeIntegrator_PrevR_by = (int8_T)
    Translation_Fusion_B.gps_pos_valid_m;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE_m +=
    Translation_Fusion_P_g.DiscreteTimeIntegrator_gainv_pa * (real32_T)
    Translation_Fusion_B.DataTypeConversion_ly;
  Translation_Fusion_DW.DiscreteTimeIntegrator_PrevR_gw = (int8_T)
    Translation_Fusion_B.En_Corr_Pz_RTK;
  Translation_Fusion_DW.Delay_DSTATE_n = Translation_Fusion_B.gps_pos_valid_mk;
  Translation_Fusion_DW.Delay2_DSTATE[0] = Translation_Fusion_B.rtb_Int_X_idx_0;
  Translation_Fusion_DW.Delay2_DSTATE_a[0] = !Translation_Fusion_B.rtk_pos_valid;
  Translation_Fusion_DW.Delay3_DSTATE[0] = Translation_Fusion_B.rtb_Min_c_idx_0;
  Translation_Fusion_DW.Delay1_DSTATE_c[0] = Translation_Fusion_B.rtk_pos_valid;
  Translation_Fusion_DW.Delay2_DSTATE[1] = Translation_Fusion_B.rtb_Int_X_idx_1;
  Translation_Fusion_DW.Delay2_DSTATE_a[1] =
    !Translation_Fusion_B.rtb_LogicalOperator1_ls_idx_1;
  Translation_Fusion_DW.Delay3_DSTATE[1] = Translation_Fusion_B.rtb_Int_X_idx_2;
  Translation_Fusion_DW.Delay1_DSTATE_c[1] =
    Translation_Fusion_B.rtb_LogicalOperator1_ls_idx_1;
  for (Translation_Fusion_B.i = 0; Translation_Fusion_B.i < 99;
       Translation_Fusion_B.i++) {
    Translation_Fusion_B.rtb_GPS_gain_tmp = (Translation_Fusion_B.i + 1) << 1;
    Translation_Fusion_B.DataTypeConversion_ly = Translation_Fusion_B.i << 1;
    Translation_Fusion_DW.Delay_DSTATE_o[Translation_Fusion_B.DataTypeConversion_ly]
      =
      Translation_Fusion_DW.Delay_DSTATE_o[Translation_Fusion_B.rtb_GPS_gain_tmp];
    Translation_Fusion_DW.Delay_DSTATE_o[Translation_Fusion_B.DataTypeConversion_ly
      + 1] =
      Translation_Fusion_DW.Delay_DSTATE_o[Translation_Fusion_B.rtb_GPS_gain_tmp
      + 1];
  }

  Translation_Fusion_DW.DiscreteTimeIntegrator_IC_LO_aj = 0U;
  Translation_Fusion_DW.icLoad_gb = 0U;
  Translation_Fusion_DW.Delay_DSTATE_o[198] =
    Translation_Fusion_B.rtb_Switch_l_idx_0;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE_i[0] +=
    (Translation_Fusion_B.rtb_DiscreteTimeIntegrator1_lt_ * (real32_T)
     Translation_Fusion_B.rtk_pos_valid + Translation_Fusion_B.rtb_Int_X_idx_0) *
    Translation_Fusion_P_g.DiscreteTimeIntegrator_gainv_p1;
  if (Translation_Fusion_B.rtb_LogicalOperator_co_idx_0) {
    Translation_Fusion_DW.DiscreteTimeIntegrator_PrevR_gg[0] = 1;
  } else {
    Translation_Fusion_DW.DiscreteTimeIntegrator_PrevR_gg[0] = 0;
  }

  Translation_Fusion_DW.Delay2_DSTATE_e[0] = Translation_Fusion_B.Assignment[0];
  Translation_Fusion_DW.Delay1_DSTATE_f[0] =
    Translation_Fusion_B.rtb_Int_X_idx_0;
  Translation_Fusion_DW.Delay_DSTATE_o[199] =
    Translation_Fusion_B.rtb_Switch_l_l;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE_i[1] +=
    (Translation_Fusion_B.rtb_DiscreteTimeIntegrator1_l_l * (real32_T)
     Translation_Fusion_B.rtb_LogicalOperator1_ls_idx_1 +
     Translation_Fusion_B.rtb_Int_X_idx_1) *
    Translation_Fusion_P_g.DiscreteTimeIntegrator_gainv_p1;
  if (Translation_Fusion_B.rtb_LogicalOperator_co_idx_1) {
    Translation_Fusion_DW.DiscreteTimeIntegrator_PrevR_gg[1] = 1;
  } else {
    Translation_Fusion_DW.DiscreteTimeIntegrator_PrevR_gg[1] = 0;
  }

  Translation_Fusion_DW.Delay2_DSTATE_e[1] = Translation_Fusion_B.Assignment[1];
  Translation_Fusion_DW.Delay1_DSTATE_f[1] =
    Translation_Fusion_B.rtb_Int_X_idx_1;
  Translation_Fusion_DW.Delay_DSTATE_o1 = Translation_Fusion_B.GPS_height_enable;
  Translation_Fusion_DW.Delay_DSTATE_of = *rtu_Sensor_Sonar_data_h_grd_son;
  Translation_Fusion_DW.Delay1_DSTATE_nb = *rtu_Sensor_Sonar_data_sonar_val;
  Translation_Fusion_DW.DelayInput1_DSTATE_o = *rtu_Sensor_Sonar_data_sonar_val;
  Translation_Fusion_DW.Delay_DSTATE_pi = Translation_Fusion_B.Compare_mn;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_ab +=
    Translation_Fusion_P_g.DiscreteTimeIntegrator_gainv_mg *
    Translation_Fusion_P_g.Constant_Value_cs;
  Translation_Fusion_DW.DiscreteTimeIntegrator_PrevR_bz = (int8_T)
    Translation_Fusion_B.Compare_i;
  Translation_Fusion_DW.Delay1_DSTATE_g = Translation_Fusion_B.MatrixMultiply3;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_gt +=
    Translation_Fusion_P_g.DiscreteTimeIntegrator_gainv_px *
    Translation_Fusion_B.state;
  if (Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_gt >=
      Translation_Fusion_P_g.DiscreteTimeIntegrator_Upper_eh) {
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_gt =
      Translation_Fusion_P_g.DiscreteTimeIntegrator_Upper_eh;
  } else {
    if (Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_gt <=
        Translation_Fusion_P_g.DiscreteTimeIntegrator_LowerS_l) {
      Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_gt =
        Translation_Fusion_P_g.DiscreteTimeIntegrator_LowerS_l;
    }
  }

  Translation_Fusion_DW.DiscreteTimeIntegrator_PrevRe_d = (int8_T)
    Translation_Fusion_B.Compare_ep;
  Translation_Fusion_DW.DelayInput1_DSTATE_f = Translation_Fusion_B.Compare_afp;
  Translation_Fusion_DW.icLoad_gm = 0U;
  Translation_Fusion_DW.Delay2_DSTATE_b =
    Translation_Fusion_B.DiscreteTimeIntegrator_ax;
  Translation_Fusion_DW.DelayInput1_DSTATE_k = *rtu_Sensor_baro_Timestamp_ms;
  Translation_Fusion_DW.Delay_DSTATE_l = ((int32_T)((uint32_T)
    Translation_Fusion_B.En_GPS_height_Correct +
    Translation_Fusion_B.LogicalOperator_hz) != 0);
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_ai +=
    Translation_Fusion_P_g.DiscreteTimeIntegrator_gainv_cw *
    Translation_Fusion_P_g.Constant_Value_ky;
  Translation_Fusion_DW.DiscreteTimeIntegrator_PrevRe_a = (int8_T)
    Translation_Fusion_B.En_GPS_height_Correct;
  Translation_Fusion_DW.Delay_DSTATE_by =
    Translation_Fusion_B.DataTypeConversion1_e;
  Translation_Fusion_DW.icLoad_d = 0U;
  Translation_Fusion_DW.Delay_DSTATE_m = Translation_Fusion_B.low_thr;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_eb +=
    Translation_Fusion_P_g.DiscreteTimeIntegrator_gainv_de *
    Translation_Fusion_B.Sum2;
  Translation_Fusion_DW.DiscreteTimeIntegrator_PrevR_jg = (int8_T)
    rtb_Reset_TF_tmp;
  Translation_Fusion_DW.DiscreteTimeIntegrator_IC_LOA_f = 0U;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_i1 +=
    Translation_Fusion_P_g.DiscreteTimeIntegrator_gainv_mu *
    Translation_Fusion_B.Subtract1;
  Translation_Fusion_DW.DiscreteTimeIntegrator_IC_LOA_k = 0U;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_cq +=
    Translation_Fusion_P_g.DiscreteTimeIntegrator_gainva_b *
    Translation_Fusion_B.Subtract2;
  Translation_Fusion_DW.DiscreteTimeIntegrator_IC_LOA_m = 0U;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_eq +=
    Translation_Fusion_P_g.DiscreteTimeIntegrator_gainv_l5 *
    Translation_Fusion_B.Subtract3;
  Translation_Fusion_DW.DiscreteTimeIntegrator_IC_LO_ae = 0U;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_j3 +=
    Translation_Fusion_P_g.DiscreteTimeIntegrator_gainv_o2 *
    Translation_Fusion_B.DiscreteTimeIntegrator1_f5h;
  Translation_Fusion_DW.DiscreteTimeIntegrator_PrevRe_o = (int8_T)
    rtb_Reset_TF_tmp;
  Translation_Fusion_DW.DiscreteTimeIntegrator1_DSTAT_f[0] +=
    Translation_Fusion_P_g.DiscreteTimeIntegrator1_gainv_h *
    Translation_Fusion_B.rtb_Transpose_h_idx_0;
  Translation_Fusion_DW.DiscreteTimeIntegrator1_DSTAT_f[1] +=
    Translation_Fusion_P_g.DiscreteTimeIntegrator1_gainv_h *
    Translation_Fusion_B.rtb_Transpose_h_idx_1;
  Translation_Fusion_DW.DiscreteTimeIntegrator1_IC_LOAD = 0U;
  Translation_Fusion_DW.DiscreteTimeIntegrator1_DSTAT_n +=
    Translation_Fusion_P_g.DiscreteTimeIntegrator1_gainv_l *
    Translation_Fusion_B.DiscreteTimeIntegrator1_at;
  Translation_Fusion_DW.Delay_DSTATE_f = Translation_Fusion_B.baro_error_small;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE_l +=
    Translation_Fusion_P_g.DiscreteTimeIntegrator_gainv_p2 * (real32_T)
    Translation_Fusion_B.DataTypeConversion_ew;
  if (Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE_l >=
      Translation_Fusion_P_g.DiscreteTimeIntegrator_UpperS_b) {
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE_l =
      Translation_Fusion_P_g.DiscreteTimeIntegrator_UpperS_b;
  } else {
    if (Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE_l <=
        Translation_Fusion_P_g.DiscreteTimeIntegrator_LowerS_a) {
      Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE_l =
        Translation_Fusion_P_g.DiscreteTimeIntegrator_LowerS_a;
    }
  }

  Translation_Fusion_DW.DiscreteTimeIntegrator_PrevR_is = (int8_T)
    Translation_Fusion_B.FixPtRelationalOperator_g;
  Translation_Fusion_DW.Memory_PreviousInput_o3 = Translation_Fusion_B.Add1_p;
  Translation_Fusion_DW.DiscreteTimeIntegrator1_DSTA_hw +=
    Translation_Fusion_P_g.DiscreteTimeIntegrator1_gainv_i *
    Translation_Fusion_B.Relay1;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_lb +=
    (Translation_Fusion_B.Inverse_j + Translation_Fusion_B.Abs1) *
    Translation_Fusion_P_g.DiscreteTimeIntegrator_gainv_ce;
  Translation_Fusion_DW.DiscreteTimeIntegrator1_DSTAT_b +=
    Translation_Fusion_P_g.DiscreteTimeIntegrator1_gain_pl *
    Translation_Fusion_B.Abs2;
  Translation_Fusion_DW.DiscreteTimeIntegrator1_PrevRes = (int8_T)
    Translation_Fusion_B.En_sonar_Correct;
  Translation_Fusion_DW.DiscreteTimeIntegrator_IC_LO_fn = 0U;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE_d +=
    Translation_Fusion_P_g.DiscreteTimeIntegrator_gainva_e *
    Translation_Fusion_B.DiscreteTimeIntegrator_bj;
  Translation_Fusion_DW.DiscreteTimeIntegrator_PrevR_iz = (int8_T)
    Translation_Fusion_B.En_sonar_Correct;
  Translation_Fusion_DW.Delay_DSTATE_p = Translation_Fusion_B.MatrixMultiply4_a
    [2];
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_pa +=
    (Translation_Fusion_B.Gain1_p + Translation_Fusion_B.Sum_d) *
    Translation_Fusion_P_g.DiscreteTimeIntegrator_gainv_f3;
  Translation_Fusion_DW.DiscreteTimeIntegrator1_DSTA_fe +=
    Translation_Fusion_P_g.DiscreteTimeIntegrator1_gainv_o *
    Translation_Fusion_B.DiscreteTimeIntegrator_j;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_a0 +=
    (Translation_Fusion_B.Gain1_i + Translation_Fusion_B.Gain_av) *
    Translation_Fusion_P_g.DiscreteTimeIntegrator_gainv_ah;
  Translation_Fusion_DW.DiscreteTimeIntegrator1_DSTAT_g +=
    Translation_Fusion_P_g.DiscreteTimeIntegrator1_gainv_d *
    Translation_Fusion_B.DiscreteTimeIntegrator_b;
  Translation_Fusion_DW.DiscreteTimeIntegrator1_IC_LO_n = 0U;
  Translation_Fusion_DW.DiscreteTimeIntegrator1_DSTAT_l +=
    Translation_Fusion_P_g.DiscreteTimeIntegrator1_gainv_g *
    Translation_Fusion_B.Product_c;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTA_gt3[0] +=
    (Translation_Fusion_B.rtb_Gain1_o_idx_0 +
     Translation_Fusion_B.rtb_Gain_c_idx_0) *
    Translation_Fusion_P_g.DiscreteTimeIntegrator_gainv_oh;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTA_gt3[1] +=
    (Translation_Fusion_B.rtb_Gain1_o_idx_1 +
     Translation_Fusion_B.rtb_Gain_c_idx_1) *
    Translation_Fusion_P_g.DiscreteTimeIntegrator_gainv_oh;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_n4 +=
    Translation_Fusion_P_g.DiscreteTimeIntegrator_gainv_mn * (real32_T)
    rtb_Over_15m_tmp;
  if (Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_n4 >=
      Translation_Fusion_P_g.DiscreteTimeIntegrator_Upper_lw) {
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_n4 =
      Translation_Fusion_P_g.DiscreteTimeIntegrator_Upper_lw;
  } else {
    if (Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_n4 <=
        Translation_Fusion_P_g.DiscreteTimeIntegrator_LowerS_p) {
      Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_n4 =
        Translation_Fusion_P_g.DiscreteTimeIntegrator_LowerS_p;
    }
  }

  Translation_Fusion_DW.DiscreteTimeIntegrator_PrevR_hk = (int8_T)
    Translation_Fusion_B.LogicalOperator_m;
  Translation_Fusion_DW.DiscreteTimeIntegrator_IC_LO_fw = 0U;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_lc +=
    Translation_Fusion_P_g.DiscreteTimeIntegrator_gainva_j *
    Translation_Fusion_B.Gain_by;
  Translation_Fusion_DW.DelayInput1_DSTATE_ey = Translation_Fusion_B.Compare_jq;
  Translation_Fusion_DW.DelayInput1_DSTATE_nj =
    Translation_Fusion_B.LogicalOperator2_f;
  Translation_Fusion_DW.Delay1_DSTATE_k1 = Translation_Fusion_B.Add1_p;
  Translation_Fusion_DW.Delay_DSTATE_pu = *rtu_Sensor_Sonar_data_sonar_val;
  Translation_Fusion_DW.DelayInput1_DSTATE_d =
    Translation_Fusion_B.En_VO_Pz_Correct;
  Translation_Fusion_DW.DiscreteTimeIntegrator5_DSTAT_g +=
    Translation_Fusion_P_g.DiscreteTimeIntegrator5_gain_ko *
    Translation_Fusion_B.Gain2;
  Translation_Fusion_DW.DiscreteTimeIntegrator5_DSTAT_j +=
    Translation_Fusion_P_g.DiscreteTimeIntegrator5_gainv_d *
    Translation_Fusion_B.Gain2_f;
  Translation_Fusion_DW.DiscreteTimeIntegrator5_PrevRes = (int8_T)
    Translation_Fusion_B.Compare_bo;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTATE_b +=
    (Translation_Fusion_B.Gain1_l + Translation_Fusion_B.Gain_gh) *
    Translation_Fusion_P_g.DiscreteTimeIntegrator_gainv_nq;
  Translation_Fusion_DW.DiscreteTimeIntegrator1_DSTAT_d +=
    Translation_Fusion_P_g.DiscreteTimeIntegrator1_gain_pj *
    Translation_Fusion_B.DiscreteTimeIntegrator_km;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_ak +=
    (Translation_Fusion_B.Gain1_lg + Translation_Fusion_B.Gain_nx) *
    Translation_Fusion_P_g.DiscreteTimeIntegrator_gainv_ov;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_ce +=
    Translation_Fusion_P_g.DiscreteTimeIntegrator_gainv_mz *
    Translation_Fusion_B.Gain3;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_ct +=
    (Translation_Fusion_B.Gain1_g + Translation_Fusion_B.Gain_ce) *
    Translation_Fusion_P_g.DiscreteTimeIntegrator_gain_dez;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_bn +=
    Translation_Fusion_P_g.DiscreteTimeIntegrator_gainv_lc *
    Translation_Fusion_B.Gain3_m;
  Translation_Fusion_DW.DiscreteTimeIntegrator1_DSTAT_c +=
    Translation_Fusion_P_g.DiscreteTimeIntegrator1_gain_ok *
    Translation_Fusion_B.Add_kk;
  Translation_Fusion_DW.DiscreteTimeIntegrator1_DSTA_l2 +=
    Translation_Fusion_P_g.DiscreteTimeIntegrator1_gain_dh *
    Translation_Fusion_B.Add_ey;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_jp +=
    (Translation_Fusion_B.Gain1_ol + Translation_Fusion_B.Gain_nwa) *
    Translation_Fusion_P_g.DiscreteTimeIntegrator_gainv_je;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_eh +=
    Translation_Fusion_P_g.DiscreteTimeIntegrator_gainv_al *
    Translation_Fusion_B.Gain3_p;
  Translation_Fusion_DW.DiscreteTimeIntegrator1_DSTA_hj +=
    Translation_Fusion_P_g.DiscreteTimeIntegrator1_gain_nm *
    Translation_Fusion_B.Add_b;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_hp +=
    (Translation_Fusion_B.Gain1_e + Translation_Fusion_B.Gain_pi) *
    Translation_Fusion_P_g.DiscreteTimeIntegrator_gainv_dr;
  Translation_Fusion_DW.DiscreteTimeIntegrator1_DSTAT_m +=
    Translation_Fusion_P_g.DiscreteTimeIntegrator1_gain_nx *
    Translation_Fusion_B.DiscreteTimeIntegrator_or;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_pd +=
    (Translation_Fusion_B.Gain1_lx + Translation_Fusion_B.Gain_cl) *
    Translation_Fusion_P_g.DiscreteTimeIntegrator_gain_mnf;
  Translation_Fusion_DW.DiscreteTimeIntegrator1_DSTAT_p +=
    Translation_Fusion_P_g.DiscreteTimeIntegrator1_gainv_f *
    Translation_Fusion_B.DiscreteTimeIntegrator_n5;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_dc +=
    (Translation_Fusion_B.Gain1_av + Translation_Fusion_B.Gain_l) *
    Translation_Fusion_P_g.DiscreteTimeIntegrator_gainv_jb;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_bo +=
    Translation_Fusion_P_g.DiscreteTimeIntegrator_gainv_on * (real32_T)
    Translation_Fusion_B.DataTypeConversion_bx;
  if (Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_bo >=
      Translation_Fusion_P_g.DiscreteTimeIntegrator_UpperS_h) {
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_bo =
      Translation_Fusion_P_g.DiscreteTimeIntegrator_UpperS_h;
  } else {
    if (Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_bo <=
        Translation_Fusion_P_g.DiscreteTimeIntegrator_LowerS_h) {
      Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_bo =
        Translation_Fusion_P_g.DiscreteTimeIntegrator_LowerS_h;
    }
  }

  Translation_Fusion_DW.DiscreteTimeIntegrator_PrevR_ix = (int8_T)
    Translation_Fusion_B.FixPtRelationalOperator_p;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_ka +=
    Translation_Fusion_P_g.DiscreteTimeIntegrator_gainv_ko * (real32_T)
    Translation_Fusion_B.DataTypeConversion_i;
  if (Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_ka >=
      Translation_Fusion_P_g.DiscreteTimeIntegrator_UpperS_n) {
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_ka =
      Translation_Fusion_P_g.DiscreteTimeIntegrator_UpperS_n;
  } else {
    if (Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_ka <=
        Translation_Fusion_P_g.DiscreteTimeIntegrator_Lower_gy) {
      Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_ka =
        Translation_Fusion_P_g.DiscreteTimeIntegrator_Lower_gy;
    }
  }

  Translation_Fusion_DW.DiscreteTimeIntegrator_PrevRe_e = (int8_T)
    Translation_Fusion_B.LogicalOperator1_im;
  Translation_Fusion_DW.DiscreteTimeIntegrator1_DSTA_na +=
    Translation_Fusion_P_g.DiscreteTimeIntegrator1_gainv_e *
    Translation_Fusion_B.DiscreteTimeIntegrator_a1;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_dv +=
    (Translation_Fusion_B.Gain1_at + Translation_Fusion_B.Gain_lc) *
    Translation_Fusion_P_g.DiscreteTimeIntegrator_gainv_k4;
  Translation_Fusion_DW.DiscreteTimeIntegrator1_DSTA_hy +=
    Translation_Fusion_P_g.DiscreteTimeIntegrator1_gain_lj *
    Translation_Fusion_B.DiscreteTimeIntegrator_c;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_n2 +=
    (Translation_Fusion_B.Gain1_la + Translation_Fusion_B.Gain_go) *
    Translation_Fusion_P_g.DiscreteTimeIntegrator_gainv_lf;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_jr +=
    Translation_Fusion_P_g.DiscreteTimeIntegrator_gainv_fz *
    Translation_Fusion_P_g.Constant1_Value_p;
  Translation_Fusion_DW.DiscreteTimeIntegrator_PrevR_fm = (int8_T)
    Translation_Fusion_B.Over_15m;
  Translation_Fusion_DW.DiscreteTimeIntegrator1_DSTA_lz +=
    Translation_Fusion_P_g.DiscreteTimeIntegrator1_gain_d1 *
    Translation_Fusion_B.DiscreteTimeIntegrator_h;
  Translation_Fusion_DW.Delay_DSTATE_kd = Translation_Fusion_B.Switch1_ko;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_ny +=
    Translation_Fusion_P_g.DiscreteTimeIntegrator_gainv_ns *
    Translation_Fusion_P_g.Constant_Value_kg;
  Translation_Fusion_DW.DiscreteTimeIntegrator_PrevR_au = (int8_T)
    *rtu_Rotation_reset_Yaw;
  Translation_Fusion_DW.Delay1_DSTATE_d[0] = Translation_Fusion_B.P_Kalman[0];
  Translation_Fusion_DW.Delay1_DSTATE_d[1] = Translation_Fusion_B.P_Kalman[1];
  Translation_Fusion_DW.Delay1_DSTATE_d[2] = Translation_Fusion_B.P_Kalman[6];
  Translation_Fusion_DW.Delay1_DSTATE_d[3] = Translation_Fusion_B.P_Kalman[7];
  Translation_Fusion_DW.icLoad_f = 0U;
  for (Translation_Fusion_B.rtb_GPS_gain_tmp = 0;
       Translation_Fusion_B.rtb_GPS_gain_tmp < 4;
       Translation_Fusion_B.rtb_GPS_gain_tmp++) {
    Translation_Fusion_B.DataTypeConversion_ew = (2 +
      Translation_Fusion_B.rtb_GPS_gain_tmp) * 6;
    Translation_Fusion_B.DataTypeConversion_bx =
      Translation_Fusion_B.rtb_GPS_gain_tmp << 2;
    Translation_Fusion_DW.Int_P_DSTATE[Translation_Fusion_B.DataTypeConversion_bx]
      = Translation_Fusion_B.P_Kalman[Translation_Fusion_B.DataTypeConversion_ew
      + 2];
    Translation_Fusion_DW.Int_P_DSTATE[1 +
      Translation_Fusion_B.DataTypeConversion_bx] =
      Translation_Fusion_B.P_Kalman[Translation_Fusion_B.DataTypeConversion_ew +
      3];
    Translation_Fusion_DW.Int_P_DSTATE[2 +
      Translation_Fusion_B.DataTypeConversion_bx] =
      Translation_Fusion_B.P_Kalman[Translation_Fusion_B.DataTypeConversion_ew +
      4];
    Translation_Fusion_DW.Int_P_DSTATE[3 +
      Translation_Fusion_B.DataTypeConversion_bx] =
      Translation_Fusion_B.P_Kalman[Translation_Fusion_B.DataTypeConversion_ew +
      5];
  }

  for (Translation_Fusion_B.i = 0; Translation_Fusion_B.i < 9;
       Translation_Fusion_B.i++) {
    Translation_Fusion_DW.Delay2_DSTATE_l[Translation_Fusion_B.i] =
      rtu_Rotation_M_OB[Translation_Fusion_B.i];
  }

  Translation_Fusion_DW.DiscreteTimeIntegrator1_DSTA_gu +=
    Translation_Fusion_P_g.DiscreteTimeIntegrator1_gainv_c *
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_gr;
  Translation_Fusion_DW.UnitDelay_DSTATE[0] = Translation_Fusion_B.Delay1_f[0];
  Translation_Fusion_DW.UnitDelay_DSTATE[1] = Translation_Fusion_B.Delay1_f[1];
  Translation_Fusion_DW.DiscreteTimeIntegrator1_DSTAT_e +=
    Translation_Fusion_P_g.DiscreteTimeIntegrator1_gain_ov *
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_bx;
  Translation_Fusion_DW.DelayInput1_DSTATE_ap = *rtu_Sensor_RTK_Data_Timestamp_m;
  Translation_Fusion_DW.DelayInput1_DSTATE_jf = Translation_Fusion_B.GPS_Good;
  Translation_Fusion_DW.Memory_PreviousInput_h[0] = *rtu_Sensor_RTK_Data_vel_N;
  Translation_Fusion_DW.Memory_PreviousInput_h[1] = *rtu_Sensor_RTK_Data_vel_E;
  Translation_Fusion_DW.DelayInput1_DSTATE_b = *rtu_Sensor_RTK_Data_Timestamp_m;
  Translation_Fusion_DW.Delay_DSTATE_e = (Translation_Fusion_B.Sum2_a != 0);
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_bc +=
    Translation_Fusion_P_g.DiscreteTimeIntegrator_gainv_l1 *
    Translation_Fusion_P_g.Constant_Value_hv;
  Translation_Fusion_DW.DiscreteTimeIntegrator_PrevR_a0 = (int8_T)
    Translation_Fusion_B.LogicalOperator1_hk;
  Translation_Fusion_DW.icLoad_d1 = 0U;
  for (Translation_Fusion_B.i = 0; Translation_Fusion_B.i < 139;
       Translation_Fusion_B.i++) {
    Translation_Fusion_DW.y_delay1_DSTATE[Translation_Fusion_B.i] =
      Translation_Fusion_DW.y_delay1_DSTATE[Translation_Fusion_B.i + 1];
    Translation_Fusion_DW.y_delay2_DSTATE[Translation_Fusion_B.i] =
      Translation_Fusion_DW.y_delay2_DSTATE[Translation_Fusion_B.i + 1];
  }

  Translation_Fusion_DW.y_delay1_DSTATE[139] =
    Translation_Fusion_B.rtb_Sum_ec_idx_1;
  Translation_Fusion_DW.icLoad_o = 0U;
  Translation_Fusion_DW.y_delay2_DSTATE[139] =
    Translation_Fusion_B.rtb_Vel_O_idx_1;
  Translation_Fusion_DW.Memory1_PreviousInput_c[0] =
    Translation_Fusion_B.rtb_pos_xy_O_meas_RTK_idx_0;
  Translation_Fusion_DW.Memory1_PreviousInput_c[1] =
    Translation_Fusion_B.rtb_pos_xy_O_meas_RTK_j;
  Translation_Fusion_DW.Delay_DSTATE_ev = Translation_Fusion_B.LogicalOperator_d;
  Translation_Fusion_DW.Delay1_DSTATE_ci[0] =
    Translation_Fusion_DW.Delay1_DSTATE_ci[1];
  Translation_Fusion_DW.Delay1_DSTATE_ci[1] =
    Translation_Fusion_B.LogicalOperator_d;
  Translation_Fusion_DW.icLoad_c = 0U;
  for (Translation_Fusion_B.i = 0; Translation_Fusion_B.i < 39;
       Translation_Fusion_B.i++) {
    Translation_Fusion_DW.x_delay_DSTATE_i[Translation_Fusion_B.i] =
      Translation_Fusion_DW.x_delay_DSTATE_i[Translation_Fusion_B.i + 1];
    Translation_Fusion_DW.y_delay_DSTATE[Translation_Fusion_B.i] =
      Translation_Fusion_DW.y_delay_DSTATE[Translation_Fusion_B.i + 1];
  }

  Translation_Fusion_DW.x_delay_DSTATE_i[39] =
    Translation_Fusion_B.rtb_Pos_O_idx_0;
  Translation_Fusion_DW.icLoad_j = 0U;
  Translation_Fusion_DW.y_delay_DSTATE[39] =
    Translation_Fusion_B.rtb_Pos_O_idx_1;
  Translation_Fusion_DW.UnitDelay1_DSTATE[0] = *rtu_Rotation_Euler_Transforma_h;
  Translation_Fusion_DW.UnitDelay1_DSTATE[1] = *rtu_Rotation_Euler_Transforma_k;
  Translation_Fusion_DW.UnitDelay1_DSTATE[2] = *rtu_Rotation_Euler_Transformati;
  Translation_Fusion_DW.DiscreteTimeIntegrator_IC_LOA_d = 0U;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_mr +=
    (Translation_Fusion_B.Switch_i2 -
     Translation_Fusion_B.DiscreteTimeIntegrator_po) *
    Translation_Fusion_P_g.Gain_Gain_hx *
    Translation_Fusion_P_g.DiscreteTimeIntegrator_gainv_dq;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_lv +=
    Translation_Fusion_P_g.DiscreteTimeIntegrator_gainv_nu *
    Translation_Fusion_P_g.Constant_Value_ep;
  Translation_Fusion_DW.DiscreteTimeIntegrator_PrevR_ov = (int8_T)
    Translation_Fusion_B.reset_ref;
  Translation_Fusion_DW.DiscreteTimeIntegrator_IC_LOA_i = 0U;
  Translation_Fusion_DW.DiscreteTimeIntegrator_IC_LOA_o = 0U;
  Translation_Fusion_DW.Memory_PreviousInput_c[0] =
    Translation_Fusion_B.rtb_DiscreteTimeIntegrator_p4_i;
  Translation_Fusion_DW.Memory1_PreviousInput_l[0] =
    Translation_Fusion_B.rtb_Product_o_idx_0;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_nr[0] +=
    (Translation_Fusion_B.Selector_ai[0] - Translation_Fusion_B.rtb_Min_l_idx_0)
    * Translation_Fusion_P_g.Gain_Gain_mp *
    Translation_Fusion_P_g.DiscreteTimeIntegrator_gainv_c5;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_dd[0] +=
    (Translation_Fusion_B.Selector_ai[2] - Translation_Fusion_B.rtb_Sum1_l_idx_0)
    * Translation_Fusion_P_g.Gain_Gain_ah *
    Translation_Fusion_P_g.DiscreteTimeIntegrator_gainv_mw;
  Translation_Fusion_DW.Memory_PreviousInput_c[1] =
    Translation_Fusion_B.rtb_DiscreteTimeIntegrator_p4_d;
  Translation_Fusion_DW.Memory1_PreviousInput_l[1] =
    Translation_Fusion_B.rtb_Product_o_idx_1;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_nr[1] +=
    (Translation_Fusion_B.Selector_ai[1] - Translation_Fusion_B.rtb_Min_l_idx_1)
    * Translation_Fusion_P_g.Gain_Gain_mp *
    Translation_Fusion_P_g.DiscreteTimeIntegrator_gainv_c5;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_dd[1] +=
    (Translation_Fusion_B.Selector_ai[3] - Translation_Fusion_B.rtb_Sum1_l_idx_1)
    * Translation_Fusion_P_g.Gain_Gain_ah *
    Translation_Fusion_P_g.DiscreteTimeIntegrator_gainv_mw;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_oy +=
    Translation_Fusion_P_g.DiscreteTimeIntegrator_gainv_mh *
    Translation_Fusion_P_g.Constant_Value_mz;
  Translation_Fusion_DW.DiscreteTimeIntegrator_Prev_jgs = (int8_T)
    Translation_Fusion_B.En_GPS_Correct_RTK;
  Translation_Fusion_DW.DiscreteTimeIntegrator_IC_LOA_h = 0U;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_cf +=
    (Translation_Fusion_B.Subtract1_k[0] -
     Translation_Fusion_B.DiscreteTimeIntegrator_jc) *
    Translation_Fusion_P_g.Gain_Gain_kl *
    Translation_Fusion_P_g.DiscreteTimeIntegrator_gain_dqh;
  Translation_Fusion_DW.DiscreteTimeIntegrator_IC_LO_oj = 0U;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_mo +=
    (Translation_Fusion_B.Subtract1_k[1] -
     Translation_Fusion_B.DiscreteTimeIntegrator_j1z) *
    Translation_Fusion_P_g.Gain_Gain_m1 *
    Translation_Fusion_P_g.DiscreteTimeIntegrator_gainva_h;
  Translation_Fusion_DW.DiscreteTimeIntegrator_IC_LO_fm = 0U;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_jh[0] +=
    (Translation_Fusion_B.Selector13[0] -
     Translation_Fusion_B.CreateDiagonalMatrix_jk[0]) *
    Translation_Fusion_P_g.Gain_Gain_jv *
    Translation_Fusion_P_g.DiscreteTimeIntegrator_gainv_dz;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_jh[1] +=
    (Translation_Fusion_B.Selector13[1] -
     Translation_Fusion_B.CreateDiagonalMatrix_jk[1]) *
    Translation_Fusion_P_g.Gain_Gain_jv *
    Translation_Fusion_P_g.DiscreteTimeIntegrator_gainv_dz;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_jh[2] +=
    (Translation_Fusion_B.Selector13[2] -
     Translation_Fusion_B.CreateDiagonalMatrix_jk[2]) *
    Translation_Fusion_P_g.Gain_Gain_jv *
    Translation_Fusion_P_g.DiscreteTimeIntegrator_gainv_dz;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_jh[3] +=
    (Translation_Fusion_B.Selector13[3] -
     Translation_Fusion_B.CreateDiagonalMatrix_jk[3]) *
    Translation_Fusion_P_g.Gain_Gain_jv *
    Translation_Fusion_P_g.DiscreteTimeIntegrator_gainv_dz;
  Translation_Fusion_DW.DelayInput1_DSTATE_p1 = *rtu_Sensor_Vision_data_timestam;
  Translation_Fusion_DW.UnitDelay_DSTATE_h = Translation_Fusion_B.Sqrt;
  Translation_Fusion_DW.Delay1_DSTATE_ls = Translation_Fusion_B.Reset_TF;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTA_ppy +=
    Translation_Fusion_P_g.DiscreteTimeIntegrator_gainv_pr * (real32_T)
    Translation_Fusion_B.LogicalOperator3_d5;
  if (Translation_Fusion_DW.DiscreteTimeIntegrator_DSTA_ppy >=
      Translation_Fusion_P_g.DiscreteTimeIntegrator_UpperS_c) {
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTA_ppy =
      Translation_Fusion_P_g.DiscreteTimeIntegrator_UpperS_c;
  } else {
    if (Translation_Fusion_DW.DiscreteTimeIntegrator_DSTA_ppy <=
        Translation_Fusion_P_g.DiscreteTimeIntegrator_Lower_kn) {
      Translation_Fusion_DW.DiscreteTimeIntegrator_DSTA_ppy =
        Translation_Fusion_P_g.DiscreteTimeIntegrator_Lower_kn;
    }
  }

  Translation_Fusion_DW.DiscreteTimeIntegrator_PrevR_nj = (int8_T)
    Translation_Fusion_B.Compare_h;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_c3 +=
    Translation_Fusion_P_g.DiscreteTimeIntegrator_gainv_kp * (real32_T)
    Translation_Fusion_B.LogicalOperator2_hv;
  if (Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_c3 >=
      Translation_Fusion_P_g.DiscreteTimeIntegrator_Upper_o4) {
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_c3 =
      Translation_Fusion_P_g.DiscreteTimeIntegrator_Upper_o4;
  } else {
    if (Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_c3 <=
        Translation_Fusion_P_g.DiscreteTimeIntegrator_LowerS_d) {
      Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_c3 =
        Translation_Fusion_P_g.DiscreteTimeIntegrator_LowerS_d;
    }
  }

  Translation_Fusion_DW.DiscreteTimeIntegrator_PrevRe_k = (int8_T)
    Translation_Fusion_B.Compare_j;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTA_mos +=
    Translation_Fusion_P_g.DiscreteTimeIntegrator_gainv_ct *
    Translation_Fusion_P_g.Constant_Value_o1;
  Translation_Fusion_DW.DiscreteTimeIntegrator_PrevR_pi = (int8_T)
    Translation_Fusion_B.LogicalOperator2_g;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_hz +=
    Translation_Fusion_P_g.DiscreteTimeIntegrator_gainv_cc *
    Translation_Fusion_P_g.Constant_Value_gu;
  Translation_Fusion_DW.DiscreteTimeIntegrator_PrevR_dw = (int8_T)
    Translation_Fusion_B.Compare_l0;
  Translation_Fusion_DW.DiscreteTimeIntegrator_IC_LO_fo = 0U;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_bk +=
    (Translation_Fusion_B.Gain_h2[0] - Translation_Fusion_B.Sum3) *
    Translation_Fusion_P_g.Gain_Gain_bu *
    Translation_Fusion_P_g.DiscreteTimeIntegrator_gainv_nx;
  Translation_Fusion_DW.DiscreteTimeIntegrator_IC_LO_he = 0U;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_mu +=
    (Translation_Fusion_B.Gain_h2[1] - Translation_Fusion_B.GPS_gain) *
    Translation_Fusion_P_g.Gain_Gain_d3 *
    Translation_Fusion_P_g.DiscreteTimeIntegrator_gainv_kl;
  Translation_Fusion_DW.icLoad_on = 0U;
  for (Translation_Fusion_B.i = 0; Translation_Fusion_B.i < 79;
       Translation_Fusion_B.i++) {
    Translation_Fusion_DW.x_delay_DSTATE_e[Translation_Fusion_B.i] =
      Translation_Fusion_DW.x_delay_DSTATE_e[Translation_Fusion_B.i + 1];
    Translation_Fusion_DW.y_delay_DSTATE_b[Translation_Fusion_B.i] =
      Translation_Fusion_DW.y_delay_DSTATE_b[Translation_Fusion_B.i + 1];
  }

  Translation_Fusion_DW.x_delay_DSTATE_e[79] =
    Translation_Fusion_B.ManualSwitch[0];
  Translation_Fusion_DW.icLoad_kr = 0U;
  Translation_Fusion_DW.icLoad_fb = 0U;
  Translation_Fusion_DW.icLoad_a = 0U;
  Translation_Fusion_DW.y_delay_DSTATE_b[79] =
    Translation_Fusion_B.ManualSwitch[1];
  Translation_Fusion_DW.DiscreteTimeIntegrator_IC_LO_mc = 0U;
  Translation_Fusion_DW.DiscreteTimeIntegrator_IC_LOA_l = 0U;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_el[0] +=
    (*rtu_Sensor_GPS_data_Pos_quality -
     Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_el[0]) *
    Translation_Fusion_P_g.Gain_Gain_lq *
    Translation_Fusion_P_g.DiscreteTimeIntegrator_gainv_n3;
  if (Translation_Fusion_B.rtk_pos_valid) {
    Translation_Fusion_DW.DiscreteTimeIntegrator_PrevR_pz[0] = 1;
    Translation_Fusion_DW.DiscreteTimeIntegrator_PrevR_gr[0] = 1;
  } else {
    Translation_Fusion_DW.DiscreteTimeIntegrator_PrevR_pz[0] = 0;
    Translation_Fusion_DW.DiscreteTimeIntegrator_PrevR_gr[0] = 0;
  }

  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_g0[0] +=
    (Translation_Fusion_B.rtb_Int_X_idx_3 -
     Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_g0[0]) *
    Translation_Fusion_P_g.Gain_Gain_je *
    Translation_Fusion_P_g.DiscreteTimeIntegrator_gainv_kk;
  Translation_Fusion_DW.Delay_DSTATE_pc[0] =
    Translation_Fusion_B.LogicalOperator1_ks;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_el[1] +=
    (*rtu_Sensor_GPS_data_Pos_quality -
     Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_el[1]) *
    Translation_Fusion_P_g.Gain_Gain_lq *
    Translation_Fusion_P_g.DiscreteTimeIntegrator_gainv_n3;
  if (Translation_Fusion_B.rtb_LogicalOperator1_ls_idx_1) {
    Translation_Fusion_DW.DiscreteTimeIntegrator_PrevR_pz[1] = 1;
    Translation_Fusion_DW.DiscreteTimeIntegrator_PrevR_gr[1] = 1;
  } else {
    Translation_Fusion_DW.DiscreteTimeIntegrator_PrevR_pz[1] = 0;
    Translation_Fusion_DW.DiscreteTimeIntegrator_PrevR_gr[1] = 0;
  }

  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_g0[1] +=
    (Translation_Fusion_B.rtb_Int_X_idx_3 -
     Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_g0[1]) *
    Translation_Fusion_P_g.Gain_Gain_je *
    Translation_Fusion_P_g.DiscreteTimeIntegrator_gainv_kk;
  Translation_Fusion_DW.Delay_DSTATE_pc[1] = Translation_Fusion_B.Compare_mr;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_bx += (((real32_T)
    (rtb_LogicalOperator1_n_tmp && (*rty_RTK_Pos_Good)) *
    Translation_Fusion_P_g.Gain1_Gain_ok -
    Translation_Fusion_B.DiscreteTimeIntegrator1_ox) *
    Translation_Fusion_P_g.Gain_Gain_hb + Translation_Fusion_P_g.Gain1_Gain_a *
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_bx) *
    Translation_Fusion_P_g.DiscreteTimeIntegrator_gainv_dt;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_gr += (((real32_T)
    !*rty_RTK_Pos_Good - Translation_Fusion_B.DiscreteTimeIntegrator1_p) *
    Translation_Fusion_P_g.Gain_Gain_f3 + Translation_Fusion_P_g.Gain1_Gain_kg *
    Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_gr) *
    Translation_Fusion_P_g.DiscreteTimeIntegrator_gainv_m5;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_in[0] +=
    ((rtu_Rotation_rot_IB_B_radDs[0] -
      Translation_Fusion_B.DiscreteTimeIntegrator1_ek[0]) *
     Translation_Fusion_P_g.Gain_Gain_er + Translation_Fusion_P_g.Gain1_Gain_jn *
     Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_in[0]) *
    Translation_Fusion_P_g.DiscreteTimeIntegrator_gainv_mq;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_in[1] +=
    ((rtu_Rotation_rot_IB_B_radDs[1] -
      Translation_Fusion_B.DiscreteTimeIntegrator1_ek[1]) *
     Translation_Fusion_P_g.Gain_Gain_er + Translation_Fusion_P_g.Gain1_Gain_jn *
     Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_in[1]) *
    Translation_Fusion_P_g.DiscreteTimeIntegrator_gainv_mq;
  Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_in[2] +=
    ((rtu_Rotation_rot_IB_B_radDs[2] -
      Translation_Fusion_B.DiscreteTimeIntegrator1_ek[2]) *
     Translation_Fusion_P_g.Gain_Gain_er + Translation_Fusion_P_g.Gain1_Gain_jn *
     Translation_Fusion_DW.DiscreteTimeIntegrator_DSTAT_in[2]) *
    Translation_Fusion_P_g.DiscreteTimeIntegrator_gainv_mq;
}

void Translation_Fusion_Term(void)
{
  Translation_MovingAverage2_Term(&Translation_Fusion_DW.MovingAverage_pnae);
  Translation_MovingAverage2_Term(&Translation_Fusion_DW.MovingAverage1_pnae);
  Translation_MovingAverage2_Term(&Translation_Fusion_DW.MovingAverage2_p);
  Translation_Fusion_Average_Term(&Translation_Fusion_DW.Average);
  Translation_Fusi_Average_n_Term(&Translation_Fusion_DW.Average_pna);
  Translation_Fusi_Average_n_Term(&Translation_Fusion_DW.Average_pn);
  matlabCodegenHandle_mat_goquh1b(&Translation_Fusion_DW.obj);
  matlabCodegenHandle_matl_goquh1(&Translation_Fusion_DW.obj_p);
  Translation_Fusion_Average_Term(&Translation_Fusion_DW.MovingAverage_p);
  Translation_Fusion_Average_Term(&Translation_Fusion_DW.MovingAverage1);
  Translation_MovingAverage1_Term(&Translation_Fusion_DW.MovingAverage_pn);
  Translation_MovingAverage1_Term(&Translation_Fusion_DW.MovingAverage1_pn);
  Translati_MovingAverage1_g_Term(&Translation_Fusion_DW.MovingAverage_pna);
  Translati_MovingAverage1_g_Term(&Translation_Fusion_DW.MovingAverage1_pna);
  Translation_MovingAverage3_Term(&Translation_Fusion_DW.MovingAverage2);
  Translation_MovingAverage3_Term(&Translation_Fusion_DW.MovingAverage3);
  matlabCodegenHandle_ma_goquh1bj(&Translation_Fusion_DW.obj_a);
}

void Translation_Fusion_initialize(const char_T **rt_errorStatus)
{
  RT_MODEL_Translation_Fusion_T *const Translation_Fusion_M =
    &(Translation_Fusion_MdlrefDW.rtm);
  rt_InitInfAndNaN(sizeof(real_T));
  Translation_Fusion_P_g.Saturation1_UpperSat_f = rtInfF;
  Translation_Fusion_P_g.Saturation_UpperSat_fw = rtInfF;
  rtmSetErrorStatusPointer(Translation_Fusion_M, rt_errorStatus);
  Translation_Fusion_PrevZCX.Int_X_Reset_ZCE = UNINITIALIZED_ZCSIG;
  Translation_Fusion_PrevZCX.Delay_Reset_ZCE = POS_ZCSIG;
  Translation_Fusion_PrevZCX.x_delay_Reset_ZCE = POS_ZCSIG;
  Translation_Fusion_PrevZCX.x_delay1_Reset_ZCE = POS_ZCSIG;
  Translation_Fusion_PrevZCX.Delay2_Reset_ZCE = UNINITIALIZED_ZCSIG;
  Translation_Fusion_PrevZCX.Delay2_Reset_ZCE_b = UNINITIALIZED_ZCSIG;
  Translation_Fusion_PrevZCX.Delay_Reset_ZCE_o = POS_ZCSIG;
  Translation_Fusion_PrevZCX.Delay1_Reset_ZCE = POS_ZCSIG;
  Translation_Fusion_PrevZCX.Delay1_Reset_ZCE_i = UNINITIALIZED_ZCSIG;
  Translation_Fusion_PrevZCX.Int_P_Reset_ZCE = UNINITIALIZED_ZCSIG;
  Translation_Fusion_PrevZCX.y_delay1_Reset_ZCE = POS_ZCSIG;
  Translation_Fusion_PrevZCX.y_delay2_Reset_ZCE = POS_ZCSIG;
  Translation_Fusion_PrevZCX.x_delay_Reset_ZCE_a = POS_ZCSIG;
  Translation_Fusion_PrevZCX.y_delay_Reset_ZCE = POS_ZCSIG;
  Translation_Fusion_PrevZCX.x_delay_Reset_ZCE_d = UNINITIALIZED_ZCSIG;
  Translation_Fusion_PrevZCX.Delay_Reset_ZCE_k = UNINITIALIZED_ZCSIG;
  Translation_Fusion_PrevZCX.Delay1_Reset_ZCE_b = UNINITIALIZED_ZCSIG;
  Translation_Fusion_PrevZCX.y_delay_Reset_ZCE_p = UNINITIALIZED_ZCSIG;
  Translation_Fusion_PrevZCX.MovingAverage_Trig_ZCE = POS_ZCSIG;
}
