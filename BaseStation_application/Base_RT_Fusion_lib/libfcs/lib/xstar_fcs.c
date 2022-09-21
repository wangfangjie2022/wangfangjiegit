#include "xstar_fcs.h"
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

SCAL_PARAMS PARAMS = {
  3U,
  0U,

  { 0.0F, 0.0F, 0.0F },

  { 1.0F, 0.0F, 0.0F, 0.0F, -1.0F, 0.0F, 0.0F, 0.0F, -1.0F },

  { 1.0F, 0.0F, 0.0F, 0.0F, -1.0F, 0.0F, 0.0F, 0.0F, -1.0F },

  { 0.0F, 0.0F, 0.0F },

  { 0.0F, 0.0F, 0.0F },

  { 1.0F, 0.0F, 0.0F, 0.0F, -1.0F, 0.0F, 0.0F, 0.0F, -1.0F },

  { 0.0F, 0.0F, 0.0F },

  { 1.0F, 0.0F, 0.0F, 0.0F, -1.0F, 0.0F, 0.0F, 0.0F, -1.0F },

  { 1.0F, 0.0F, 0.0F, 0.0F, -1.0F, 0.0F, 0.0F, 0.0F, -1.0F },

  { 0.0F, 0.0F, 0.0F },
  22.7074432F,
  113.962395F,
  35.0F,
  18.0F
} ;

boolean_T rtP_eso_log_on = 0;
P_xstar_fcs_T xstar_fcs_P = {
  1.0,
  1.0,
  150,
  150,
  150,
  150,
  150,
  150,
  150,
  4.0F,
  4.0F,
  3.0F,
  0.05F,
  0.1F,
  0.1F,
  0.2F,
  1.0F,
  1.5F,
  60.0F,
  0.02F,
  2.0F,
  0.0F,
  0.1F,
  2.0F,
  0.02F,
  2.0F,
  0.0F,
  0.1F,
  2.0F,
  2.0F,
  1.0F,
  1.0F,
  1.0F,
  0.001F,
  0.001F,
  0.0F,
  1.0F,
  0.21F,
  15.0F,
  0.3F,
  3.0F,
  1.0F,
  0.5F,
  1.0E-6F,
  0.5F,
  0.5F,
  10.0F,
  1.0F,
  1.0F,
  0.0F,
  0.5F,
  0.2F,
  0.5F,
  0.5F,
  0.2F,
  0.1F,
  0.5F,
  5.0F,
  1.0F,
  0.1F,
  0.1F,
  40.0F,
  -40.0F,
  40.0F,
  -40.0F,
  40.0F,
  -40.0F,
  180.0F,
  0.2F,
  0.5F,
  5.0F,
  10.0F,
  0.0F,
  0.0F,
  1.0F,
  1.0F,
  0.0F,
  0.0F,
  1.0F,
  0.0F,
  38.3972435F,
  38.3972435F,
  98.0665F,
  98.0665F,
  -38.3972435F,
  -38.3972435F,
  -98.0665F,
  -98.0665F,
  110000.0F,
  30000.0F,
  80.0F,
  -30.0F,
  1.0E-6F,
  0.02F,
  0.02F,
  0.02F,
  0.02F,
  0.1F,
  0.1F,
  0.1F,
  0.1F,
  0.02F,
  0.02F,
  0.02F,
  0.02F,
  0.1F,
  0.1F,
  0.1F,
  0.1F,
  0.1F,
  0.5F,
  0.5F,
  0.5F,
  0.5F,
  0.5F,
  0.5F,
  0.5F,
  0.5F,
  0.5F,
  0.5F,
  0.5F,
  0.5F,
  0.5F,
  0.5F,
  0.5F,
  0.5F,
  4.4408921E-16F,
  4.4408921E-16F,
  120.0F,
  0.0F,
  0.0F,
  0.0F,
  0.0F,
  0.0F,
  0.0F,
  0.0F,
  0.0F,
  0.0F,
  0.0F,
  0.0F,
  0.0F,
  0.0F,
  0.0F,
  4294901760U,
  65535U,
  200U,
  200U,
  1000U,
  1000U,
  1000000U,
  2000U,
  5000U,
  16U,
  16U,
  0U,
  800U,
  48U,
  8U,
  0U,
  800U,
  200U,
  5000U,
  1500U,
  2000U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0,
  100,
  100,
  -30,
  -30,
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
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  16U,
  50U,
  8U,
  0,
  2,
  2,
  0,
  0,
  1U,
  2U,
  1U,
  4U,
  10U,
  25U,
  10U,
  1U,
  48U,
  0U,

  {
    0.0F,
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
    0U,
    0U,
    0U,
    0U
  },

  {
    0.0F,
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
    0U,
    0U,
    0U,
    0U
  },
  0.0,
  0.0,
  1.0,
  1.0,
  1.0,
  1.0,
  1.0,
  0.0033528131778969143,
  2.0,
  6.378137E+6,
  1.0,
  1.0,
  1.0,
  1.0,
  -1.0,
  1.0,
  0.0033528131778969143,
  2.0,
  6.378137E+6,
  1.0,
  0.017453292519943295,
  0.017453292519943295,
  57.295779513082323,
  90.0,
  -90.0,
  57.295779513082323,
  180.0,
  -180.0,
  0.017453292519943295,
  -1.0,
  0.017453292519943295,
  0.017453292519943295,
  0.017453292519943295,
  -1.0,
  65.536,
  65.536,
  65.536,
  5.7295779513082325E+8,
  5.7295779513082325E+8,
  0.0,
  0.0,
  0.0,
  0.0,
  0,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1111,
  0,
  204800,
  0,
  1099511628,

  { 0.0F, 1.0F, 0.0F, 1.0F, 0.0F, 0.0F, 0.0F, 0.0F, -1.0F },
  0.0F,
  0.01F,
  1.0F,
  0.0F,
  0.01F,
  1.0F,
  0.0F,
  0.01F,
  1.0F,

  { 43.88F, -3.69F, 31.18F },
  0.0F,

  { 1.0F, 0.0F, 0.0F, 0.0F },
  1.0F,
  0.5F,
  2.0F,

  { 0.0F, 1.0F },
  0.5F,
  1.0F,
  0.5F,
  1.0F,
  1.0F,
  1.0F,

  { 0.0F, 1.0F },
  0.5F,
  1.0F,
  0.5F,
  1.0F,
  1.0F,
  1.0F,

  { 0.0F, 1.0F },
  0.5F,
  1.0F,
  0.5F,
  1.0F,
  1.0F,
  1.0F,
  -1.0E-6F,
  0.0F,
  10.0F,
  200.0F,
  360.0F,
  0.0F,
  0.0F,
  273.15F,
  0.0F,
  0.0F,
  120000.0F,
  500.0F,
  -29.2692909F,
  1.0F,
  2.0F,
  0.0F,
  0.01F,
  0.0F,
  0.01F,
  0.0F,
  1000.0F,
  0.0F,
  0.01F,
  0.0F,
  0.01F,
  0.0F,
  0.01F,
  0.0F,
  0.01F,
  0.0F,
  0.01F,
  0.0F,
  0.01F,
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

  { 0.0010642251F, 0.0010642251F, 0.0010642251F },
  0.0F,

  { 0.0F, 1.0F, 0.0F, 1.0F, 0.0F, 0.0F, 0.0F, 0.0F, -1.0F },

  { 0.0010642251F, 0.0010642251F, 0.0010642251F },
  0.01F,
  0.0F,
  0.01F,
  0.0F,
  0.01F,
  0.0F,
  0.01F,
  0.0F,
  0.01F,
  0.0F,
  0.01F,
  0.0F,
  0.01F,
  0.0F,
  0.01F,
  0.0F,
  0.01F,
  0.0F,
  0.01F,
  0.0F,
  0.01F,
  0.0F,

  { 0.0023940627F, 0.0023940627F, 0.0023940627F },
  0.0F,

  { -1.0F, 0.0F, 0.0F, 0.0F, 1.0F, 0.0F, 0.0F, 0.0F, -1.0F },

  { 0.0023940627F, 0.0023940627F, 0.0023940627F },
  0.0F,
  0.0174532924F,
  1.0F,
  0.0122074038F,
  1.5F,
  0.0174532924F,
  1.0F,
  1.0F,
  1.0F,
  1.0F,
  0.0F,
  0.2F,
  0.01F,
  0.0F,
  0.0F,
  1.0F,
  0.01F,
  0.5F,
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
  0.01F,
  20.0F,
  0.01F,
  0.01F,
  0.0F,
  0.01F,
  0.0F,
  0.0F,
  0.01F,
  0.0F,
  0.01F,
  0.0F,
  0.0F,
  2.0F,
  2.0F,
  2.0F,
  2.0F,
  2.0F,
  2.0F,
  0.0F,
  0.0F,

  { 0.00555555569F, 0.00555555569F, 0.00555555569F, 0.00555555569F,
    0.00555555569F, 0.00555555569F, 0.00555555569F, 0.00555555569F,
    0.00555555569F, 0.00555555569F, 0.00555555569F, 0.00555555569F,
    0.00555555569F, 0.00555555569F, 0.00555555569F, 0.00555555569F,
    0.00555555569F, 0.00555555569F, 0.00555555569F, 0.00555555569F,
    0.00555555569F, 0.00555555569F, 0.00555555569F, 0.00555555569F,
    0.00555555569F, 0.00555555569F, 0.00555555569F, 0.00555555569F,
    0.00555555569F, 0.00555555569F, 0.00555555569F, 0.00555555569F,
    0.00555555569F, 0.00555555569F, 0.00555555569F, 0.00555555569F,
    0.00555555569F, 0.00555555569F, 0.00555555569F, 0.00555555569F,
    0.00555555569F, 0.00555555569F, 0.00555555569F, 0.00555555569F,
    0.00555555569F, 0.00555555569F, 0.00555555569F, 0.00555555569F,
    0.00555555569F, 0.00555555569F, 0.00555555569F, 0.00555555569F,
    0.00555555569F, 0.00555555569F, 0.00555555569F, 0.00555555569F,
    0.00555555569F, 0.00555555569F, 0.00555555569F, 0.00555555569F,
    0.00555555569F, 0.00555555569F, 0.00555555569F, 0.00555555569F,
    0.00555555569F, 0.00555555569F, 0.00555555569F, 0.00555555569F,
    0.00555555569F, 0.00555555569F, 0.00555555569F, 0.00555555569F,
    0.00555555569F, 0.00555555569F, 0.00555555569F, 0.00555555569F,
    0.00555555569F, 0.00555555569F, 0.00555555569F, 0.00555555569F,
    0.00555555569F, 0.00555555569F, 0.00555555569F, 0.00555555569F,
    0.00555555569F, 0.00555555569F, 0.00555555569F, 0.00555555569F,
    0.00555555569F, 0.00555555569F, 0.00555555569F, 0.00555555569F,
    0.00555555569F, 0.00555555569F, 0.00555555569F, 0.00555555569F,
    0.00555555569F, 0.00555555569F, 0.00555555569F, 0.00555555569F,
    0.00555555569F, 0.00555555569F, 0.00555555569F, 0.00555555569F,
    0.00555555569F, 0.00555555569F, 0.00555555569F, 0.00555555569F,
    0.00555555569F, 0.00555555569F, 0.00555555569F, 0.00555555569F,
    0.00555555569F, 0.00555555569F, 0.00555555569F, 0.00555555569F,
    0.00555555569F, 0.00555555569F, 0.00555555569F, 0.00555555569F,
    0.00555555569F, 0.00555555569F, 0.00555555569F, 0.00555555569F,
    0.00555555569F, 0.00555555569F, 0.00555555569F, 0.00555555569F,
    0.00555555569F, 0.00555555569F, 0.00555555569F, 0.00555555569F,
    0.00555555569F, 0.00555555569F, 0.00555555569F, 0.00555555569F,
    0.00555555569F, 0.00555555569F, 0.00555555569F, 0.00555555569F,
    0.00555555569F, 0.00555555569F, 0.00555555569F, 0.00555555569F,
    0.00555555569F, 0.00555555569F, 0.00555555569F, 0.00555555569F,
    0.00555555569F, 0.00555555569F, 0.00555555569F, 0.00555555569F,
    0.00555555569F, 0.00555555569F, 0.00555555569F, 0.00555555569F,
    0.00555555569F, 0.00555555569F, 0.00555555569F, 0.00555555569F,
    0.00555555569F, 0.00555555569F, 0.00555555569F, 0.00555555569F,
    0.00555555569F, 0.00555555569F, 0.00555555569F, 0.00555555569F,
    0.00555555569F, 0.00555555569F, 0.00555555569F, 0.00555555569F,
    0.00555555569F, 0.00555555569F, 0.00555555569F, 0.00555555569F,
    0.00555555569F, 0.00555555569F, 0.00555555569F, 0.00555555569F },
  6.0F,
  3.0F,
  6.0F,
  0.333333343F,
  1.0F,
  0.0F,
  1.0F,
  0.01F,
  0.0F,
  0.5F,
  0.01F,
  1.0F,
  0.0F,
  0.0F,
  0.01F,
  0.0F,
  0.0F,
  1.0F,
  3.5F,
  0.4F,
  1.0F,
  0.0F,
  1.0F,
  1.0F,
  0.0F,

  { 3.0F, 3.0F, 5.0F },
  0.5F,
  1.0F,
  0.0F,
  0.01F,
  1.0F,
  0.0F,

  { 1.5F, 1.5F, 2.5F },
  2.0F,
  1.0F,
  0.0F,
  0.01F,
  1.0F,
  0.0F,
  1.0F,
  2.0F,
  2.0F,
  2.0F,
  2.0F,
  2.0F,
  2.0F,
  0.001F,
  0.001F,
  0.001F,
  0.0F,
  0.0F,
  0.0F,
  -1.0F,
  0.0122074038F,
  1.57079637F,
  0.0F,
  0.636619747F,
  1.0F,
  0.2F,
  1.0F,
  1.0F,
  1.0F,
  10.0F,
  0.1F,
  1.0F,
  0.0F,
  0.01F,
  1.0F,
  0.0F,
  180.0F,
  360.0F,
  0.0174532924F,
  0.0F,
  0.01F,

  { 1.0F, 0.0F, 0.0F, 0.0F, 1.0F, 0.0F, 0.0F, 0.0F, 1.0F },
  0.0F,
  -1.0F,
  0.0F,
  -1.0F,
  -1.0F,
  0.0F,
  -1.0F,
  0.0F,
  1.0F,
  0.0F,
  0.0001F,
  0.0001F,
  0.0001F,
  0.0001F,
  0.01F,
  0.0F,
  0.001F,
  0.001F,
  0.1F,
  0.001F,
  0.001F,
  0.001F,
  0.001F,
  0.001F,
  0.001F,
  0.001F,
  0.001F,
  1000.0F,
  100.0F,
  100.0F,
  100.0F,
  1000.0F,
  1000.0F,
  1000.0F,
  1000.0F,
  10.0F,
  0.01F,
  0.0F,
  0.01F,
  0.0F,
  -360.0F,
  40000.0F,
  0.0F,
  0.0F,
  0.0F,
  0.0F,
  0.0F,
  0.0F,
  0.0F,
  1.0F,
  0.01F,
  0.0F,
  -56.5486679F,
  0.75F,
  2.0F,
  1.0F,
  0.0F,
  0.01F,
  986.960449F,
  0.0F,
  1.0F,
  1.0F,
  1.0F,
  0.01F,
  0.0F,
  0.01F,
  0.0F,
  101.0F,
  0.0F,
  0.0F,
  0.0F,
  0.0F,
  0.01F,
  0.0F,
  101.0F,
  0.0F,
  0.01F,
  0.0F,
  101.0F,
  0.0F,
  0.0F,
  1.0F,
  1.0F,
  1.0F,
  1.0F,
  1.0F,
  1.0F,
  1.0F,
  1.0F,
  1.0F,
  1.0F,
  1.0F,
  1.0F,
  1.0F,
  1.0F,
  1.0F,
  1.0F,
  1.0F,
  1.0F,
  1.0F,
  1.0F,
  1.0F,
  1.0F,
  1.0F,
  1.0F,
  1.0F,
  1.0F,
  1.0F,
  0.0F,

  { 1.0F, 0.0F, 0.0F, 0.0F },

  { 1.0F, 1.0F, -1.0F },

  { 1.0F, 1.0F },

  { -1.0F, 1.0F },
  0.0F,
  0.0F,
  1.0F,
  1.0F,
  1.0F,
  0.0F,
  2.0F,
  0.01F,
  0.0F,
  16.666666F,
  3.33333325F,
  0.01F,
  0.0F,
  20.0F,
  3.33333325F,
  0.01F,
  0.0F,
  16.666666F,
  3.33333325F,
  3.33333325F,
  0.0F,
  0.0F,
  0.0F,
  0.0F,
  0.0F,
  1.0F,
  10.0F,
  10.0F,
  1.0F,
  1.0F,
  1.0F,
  10.0F,
  1.0F,
  2748779069U,
  1U,
  0U,
  4294967295U,
  1U,
  1U,
  1U,
  1U,
  1U,
  1U,
  1U,
  0U,
  0U,
  0U,
  0U,
  1U,
  52U,
  1U,
  1U,
  1U,
  1U,
  1U,
  1U,
  1U,
  1U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  0U,
  1U,
  1U,
  1U,
  1U,
  0U,
  1U,
  1U,
  120U,
  1U,
  1U,
  1U,
  1U,
  50U,
  200U,
  150U,
  100U,
  20480,
  16384,
  16777,
  26844,
  16384U,
  0U,
  32768U,
  33554U,
  0U,
  0,
  0,
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
  1,
  2,
  1,
  1,
  2,
  1,
  164U,
  164U,
  164U,
  128U,
  128U,
  128U,
  128U,
  128U,
  2U,
  1U,
  0U,
  0U,
  0U,

  {
    0.0,
    0.0,
    -1.0F,

    { -1.0F, -0.0F, -0.0F, -0.0F, -1.0F, -0.0F, -0.0F, -0.0F, -1.0F }
  }
  ,


  {
    0.0,
    0.0,
    -1.0F,

    { -1.0F, -0.0F, -0.0F, -0.0F, -1.0F, -0.0F, -0.0F, -0.0F, -1.0F }
  }

};

B_xstar_fcs_T xstar_fcs_B;
DW_xstar_fcs_T xstar_fcs_DW;
PrevZCX_xstar_fcs_T xstar_fcs_PrevZCX;
ExtU_xstar_fcs_T xstar_fcs_U;
ExtY_xstar_fcs_T xstar_fcs_Y;
RT_MODEL_xstar_fcs_T xstar_fcs_M_;
RT_MODEL_xstar_fcs_T *const xstar_fcs_M = &xstar_fcs_M_;
static void xstar_fcs_MovingAverage2_Init(DW_MovingAverage2_xstar_fcs_T *localDW);
static void xstar_fcs_MovingAverage2_Reset(DW_MovingAverage2_xstar_fcs_T
  *localDW);
static void xstar_fcs_MovingAverage2_Start(DW_MovingAverage2_xstar_fcs_T
  *localDW);
static void xstar_fcs_MovingAverage2(real32_T rtu_0,
  B_MovingAverage2_xstar_fcs_T *localB, DW_MovingAverage2_xstar_fcs_T *localDW);
static void xstar_fcs_IfWarningError(const real32_T rtu_dcm[9],
  P_IfWarningError_xstar_fcs_T *localP, real_T rtp_action, real32_T
  rtp_tolerance);
static void xstar_fcs_MovingAverage2_Term(DW_MovingAverage2_xstar_fcs_T *localDW);
static void xstar_fcs_SystemCore_release(dsp_simulink_MovingAverage_xs_T *obj);
static void xstar_fcs_SystemCore_delete(dsp_simulink_MovingAverage_xs_T *obj);
static void matlabCodegenHandle_matlabCodeg(dsp_simulink_MovingAverage_xs_T *obj);
static real_T xstar_interp2_dispatch_L7yjKjPr(const real_T V[703], real_T Xq,
  real_T Yq, real_T extrapval);
static real32_T xstar_fcs_rt_atan2f_snf(real32_T u0, real32_T u1);
static uint32_T xstar_fcs_MWDSP_EPH_R_B(boolean_T evt, uint32_T *sta);
static real32_T xstar_fcs_rt_remf_snf(real32_T u0, real32_T u1);
static void xstar_fcs_SystemCore_release(dsp_simulink_MovingAverage_xs_T *obj)
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

static void xstar_fcs_SystemCore_delete(dsp_simulink_MovingAverage_xs_T *obj)
{
  xstar_fcs_SystemCore_release(obj);
}

static void matlabCodegenHandle_matlabCodeg(dsp_simulink_MovingAverage_xs_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    xstar_fcs_SystemCore_delete(obj);
  }
}

static void xstar_fcs_MovingAverage2_Init(DW_MovingAverage2_xstar_fcs_T *localDW)
{
  if (localDW->obj.pStatistic->isInitialized == 1) {
    localDW->obj.pStatistic->pCumSum = 0.0F;
    memset(&localDW->obj.pStatistic->pCumSumRev[0], 0, 19U * sizeof(real32_T));
    localDW->obj.pStatistic->pCumRevIndex = 1.0F;
  }
}

static void xstar_fcs_MovingAverage2_Reset(DW_MovingAverage2_xstar_fcs_T
  *localDW)
{
  if (localDW->obj.pStatistic->isInitialized == 1) {
    localDW->obj.pStatistic->pCumSum = 0.0F;
    memset(&localDW->obj.pStatistic->pCumSumRev[0], 0, 19U * sizeof(real32_T));
    localDW->obj.pStatistic->pCumRevIndex = 1.0F;
  }
}

static void xstar_fcs_MovingAverage2_Start(DW_MovingAverage2_xstar_fcs_T
  *localDW)
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

static void xstar_fcs_MovingAverage2(real32_T rtu_0,
  B_MovingAverage2_xstar_fcs_T *localB, DW_MovingAverage2_xstar_fcs_T *localDW)
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

static void xstar_fcs_MovingAverage2_Term(DW_MovingAverage2_xstar_fcs_T *localDW)
{
  matlabCodegenHandle_matlabCodeg(&localDW->obj);
}

static void xstar_fcs_IfWarningError(const real32_T rtu_dcm[9],
  P_IfWarningError_xstar_fcs_T *localP, real_T rtp_action, real32_T
  rtp_tolerance)
{
  boolean_T tmp;
  boolean_T rtb_Compare_fp[9];
  real32_T rtu_dcm_0[9];
  int32_T i;
  int32_T i_0;
  for (i = 0; i < 3; i++) {
    for (i_0 = 0; i_0 < 3; i_0++) {
      rtu_dcm_0[i + 3 * i_0] = ((rtu_dcm[3 * i + 1] * rtu_dcm[3 * i_0 + 1] +
        rtu_dcm[3 * i] * rtu_dcm[3 * i_0]) + rtu_dcm[3 * i + 2] * rtu_dcm[3 *
        i_0 + 2]) + localP->Bias1_Bias[3 * i_0 + i];
    }
  }

  for (i = 0; i < 9; i++) {
    rtb_Compare_fp[i] = ((real32_T)fabs(rtu_dcm_0[i]) > rtp_tolerance);
  }

  tmp = rtb_Compare_fp[0];
  for (i = 0; i < 8; i++) {
    tmp = (tmp || rtb_Compare_fp[i + 1]);
  }

  if ((real32_T)fabs((((((rtu_dcm[0] * rtu_dcm[4] * rtu_dcm[8] - rtu_dcm[0] *
                          rtu_dcm[5] * rtu_dcm[7]) - rtu_dcm[1] * rtu_dcm[3] *
                         rtu_dcm[8]) + rtu_dcm[2] * rtu_dcm[3] * rtu_dcm[7]) +
                       rtu_dcm[1] * rtu_dcm[5] * rtu_dcm[6]) - rtu_dcm[2] *
                      rtu_dcm[4] * rtu_dcm[6]) + localP->Bias_Bias) >
      rtp_tolerance) {
    if (rtp_action == 2.0) {
      utAssert(localP->Constant1_Value != 0.0);
    } else {
      if (rtp_action == 3.0) {
        utAssert(localP->Constant1_Value != 0.0);
      }
    }
  } else {
    if (tmp) {
      if (rtp_action == 2.0) {
        utAssert(localP->Constant1_Value_g != 0.0);
      } else {
        if (rtp_action == 3.0) {
          utAssert(localP->Constant1_Value_g != 0.0);
        }
      }
    }
  }
}

static real_T xstar_interp2_dispatch_L7yjKjPr(const real_T V[703], real_T Xq,
  real_T Yq, real_T extrapval)
{
  real_T Vq;
  if ((Xq >= -180.0) && (Xq <= 180.0) && (Yq >= -90.0) && (Yq <= 90.0)) {
    xstar_fcs_B.low_i = 1;
    xstar_fcs_B.low_ip1 = 2;
    xstar_fcs_B.high_i = 37;
    while (xstar_fcs_B.high_i > xstar_fcs_B.low_ip1) {
      xstar_fcs_B.b_high_i = (xstar_fcs_B.low_i + xstar_fcs_B.high_i) >> 1;
      if (Xq >= ((real_T)xstar_fcs_B.b_high_i - 1.0) * 10.0 + -180.0) {
        xstar_fcs_B.low_i = xstar_fcs_B.b_high_i;
        xstar_fcs_B.low_ip1 = xstar_fcs_B.b_high_i + 1;
      } else {
        xstar_fcs_B.high_i = xstar_fcs_B.b_high_i;
      }
    }

    xstar_fcs_B.low_ip1 = 1;
    xstar_fcs_B.high_i = 2;
    xstar_fcs_B.b_high_i = 19;
    while (xstar_fcs_B.b_high_i > xstar_fcs_B.high_i) {
      xstar_fcs_B.b_mid_i = (xstar_fcs_B.low_ip1 + xstar_fcs_B.b_high_i) >> 1;
      if (Yq >= ((real_T)xstar_fcs_B.b_mid_i - 1.0) * 10.0 + -90.0) {
        xstar_fcs_B.low_ip1 = xstar_fcs_B.b_mid_i;
        xstar_fcs_B.high_i = xstar_fcs_B.b_mid_i + 1;
      } else {
        xstar_fcs_B.b_high_i = xstar_fcs_B.b_mid_i;
      }
    }

    xstar_fcs_B.x1 = ((real_T)xstar_fcs_B.low_i - 1.0) * 10.0 + -180.0;
    xstar_fcs_B.x2 = 10.0 * (real_T)xstar_fcs_B.low_i + -180.0;
    xstar_fcs_B.b_y1 = ((real_T)xstar_fcs_B.low_ip1 - 1.0) * 10.0 + -90.0;
    xstar_fcs_B.y2 = 10.0 * (real_T)xstar_fcs_B.low_ip1 + -90.0;
    if (Xq == xstar_fcs_B.x1) {
      xstar_fcs_B.x1 = V[((xstar_fcs_B.low_i - 1) * 19 + xstar_fcs_B.low_ip1) -
        1];
      Vq = V[(xstar_fcs_B.low_i - 1) * 19 + xstar_fcs_B.low_ip1];
    } else if (Xq == xstar_fcs_B.x2) {
      xstar_fcs_B.x1 = V[(19 * xstar_fcs_B.low_i + xstar_fcs_B.low_ip1) - 1];
      Vq = V[19 * xstar_fcs_B.low_i + xstar_fcs_B.low_ip1];
    } else {
      xstar_fcs_B.x2 = (Xq - xstar_fcs_B.x1) / (xstar_fcs_B.x2 - xstar_fcs_B.x1);
      xstar_fcs_B.high_i = (xstar_fcs_B.low_i - 1) * 19 + xstar_fcs_B.low_ip1;
      xstar_fcs_B.x1 = V[xstar_fcs_B.high_i - 1];
      xstar_fcs_B.b_high_i = 19 * xstar_fcs_B.low_i + xstar_fcs_B.low_ip1;
      xstar_fcs_B.d0 = V[xstar_fcs_B.b_high_i - 1];
      if (!(xstar_fcs_B.x1 == xstar_fcs_B.d0)) {
        xstar_fcs_B.x1 = xstar_fcs_B.x1 * (1.0 - xstar_fcs_B.x2) +
          xstar_fcs_B.d0 * xstar_fcs_B.x2;
      }

      if (V[xstar_fcs_B.high_i] == V[xstar_fcs_B.b_high_i]) {
        Vq = V[(xstar_fcs_B.low_i - 1) * 19 + xstar_fcs_B.low_ip1];
      } else {
        Vq = V[(xstar_fcs_B.low_i - 1) * 19 + xstar_fcs_B.low_ip1] * (1.0 -
          xstar_fcs_B.x2) + V[19 * xstar_fcs_B.low_i + xstar_fcs_B.low_ip1] *
          xstar_fcs_B.x2;
      }
    }

    if ((Yq == xstar_fcs_B.b_y1) || (xstar_fcs_B.x1 == Vq)) {
      Vq = xstar_fcs_B.x1;
    } else {
      if (!(Yq == xstar_fcs_B.y2)) {
        xstar_fcs_B.b_y1 = (Yq - xstar_fcs_B.b_y1) / (xstar_fcs_B.y2 -
          xstar_fcs_B.b_y1);
        Vq = (1.0 - xstar_fcs_B.b_y1) * xstar_fcs_B.x1 + xstar_fcs_B.b_y1 * Vq;
      }
    }
  } else {
    Vq = extrapval;
  }

  return Vq;
}

static real32_T xstar_fcs_rt_atan2f_snf(real32_T u0, real32_T u1)
{
  real32_T y;
  if (rtIsNaNF(u0) || rtIsNaNF(u1)) {
    y = (rtNaNF);
  } else if (rtIsInfF(u0) && rtIsInfF(u1)) {
    if (u0 > 0.0F) {
      xstar_fcs_B.u0_ld = 1;
    } else {
      xstar_fcs_B.u0_ld = -1;
    }

    if (u1 > 0.0F) {
      xstar_fcs_B.u1_d = 1;
    } else {
      xstar_fcs_B.u1_d = -1;
    }

    y = (real32_T)atan2((real32_T)xstar_fcs_B.u0_ld, (real32_T)xstar_fcs_B.u1_d);
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

static uint32_T xstar_fcs_MWDSP_EPH_R_B(boolean_T evt, uint32_T *sta)
{
  uint32_T retVal;
  xstar_fcs_B.previousState = *sta;
  retVal = 0U;
  xstar_fcs_B.lastzcevent = 0;
  xstar_fcs_B.newState = 5;
  xstar_fcs_B.newStateR = 5;
  if (evt) {
    xstar_fcs_B.curState = 2;
  } else {
    xstar_fcs_B.curState = 1;
  }

  if (*sta == 5U) {
    xstar_fcs_B.newStateR = xstar_fcs_B.curState;
  } else {
    if ((uint32_T)xstar_fcs_B.curState != *sta) {
      if (*sta == 3U) {
        if ((uint32_T)xstar_fcs_B.curState == 1U) {
          xstar_fcs_B.newStateR = 1;
        } else {
          xstar_fcs_B.lastzcevent = 2;
          xstar_fcs_B.previousState = 1U;
        }
      }

      if (xstar_fcs_B.previousState == 4U) {
        if ((uint32_T)xstar_fcs_B.curState == 1U) {
          xstar_fcs_B.newStateR = 1;
        } else {
          xstar_fcs_B.lastzcevent = 3;
          xstar_fcs_B.previousState = 1U;
        }
      }

      if ((xstar_fcs_B.previousState == 1U) && ((uint32_T)xstar_fcs_B.curState ==
           2U)) {
        retVal = 2U;
      }

      if (xstar_fcs_B.previousState == 0U) {
        retVal = 2U;
      }

      if (retVal == (uint32_T)xstar_fcs_B.lastzcevent) {
        retVal = 0U;
      }

      if (((uint32_T)xstar_fcs_B.curState == 1U) && (retVal == 2U)) {
        xstar_fcs_B.newState = 3;
      } else {
        xstar_fcs_B.newState = xstar_fcs_B.curState;
      }
    }
  }

  if ((uint32_T)xstar_fcs_B.newStateR != 5U) {
    *sta = (uint32_T)xstar_fcs_B.newStateR;
    retVal = 0U;
  }

  if ((uint32_T)xstar_fcs_B.newState != 5U) {
    *sta = (uint32_T)xstar_fcs_B.newState;
  }

  return retVal;
}

static real32_T xstar_fcs_rt_remf_snf(real32_T u0, real32_T u1)
{
  real32_T y;
  if (rtIsNaNF(u0) || rtIsInfF(u0) || (rtIsNaNF(u1) || rtIsInfF(u1))) {
    y = (rtNaNF);
  } else {
    if (u1 < 0.0F) {
      xstar_fcs_B.u1_g = (real32_T)ceil(u1);
    } else {
      xstar_fcs_B.u1_g = (real32_T)floor(u1);
    }

    if ((u1 != 0.0F) && (u1 != xstar_fcs_B.u1_g)) {
      xstar_fcs_B.u1_g = (real32_T)fabs(u0 / u1);
      if ((real32_T)fabs(xstar_fcs_B.u1_g - (real32_T)floor(xstar_fcs_B.u1_g +
            0.5F)) <= FLT_EPSILON * xstar_fcs_B.u1_g) {
        y = 0.0F * u0;
      } else {
        y = (real32_T)fmod(u0, u1);
      }
    } else {
      y = (real32_T)fmod(u0, u1);
    }
  }

  return y;
}

void xstar_fcs_step(void)
{
  static const real_T b[703] = { 54.751296544923, 60.8219582807122,
    63.2736428044968, 62.1065028661705, 58.6218445830597, 54.0486174151378,
    48.8415736871016, 43.2272422414039, 37.9045331100083, 34.1348821212969,
    32.8559835393798, 34.0367990181378, 37.285189662854, 42.2874110610021,
    48.3732322436004, 53.9685490226853, 57.2715065993778, 57.810205922268,
    56.6251856430178, 54.751296544923, 60.2070934933594, 61.9838709962904,
    60.2386996475869, 56.3714969116248, 51.6300979125819, 46.4704101750377,
    41.1410932583374, 36.3388150303746, 33.2390280038973, 32.5772525631712,
    34.1134647268905, 37.4241471498384, 42.3694527094025, 48.4366806129221,
    53.9924422012005, 57.17760488311, 57.6763895903743, 56.6251856430178,
    54.751296544923, 59.4376968356069, 60.5190840612035, 58.2705368124749,
    54.099951983491, 49.2318713576022, 44.1366100107218, 39.1097388222932,
    34.8536144816069, 32.432685644468, 32.4066304163892, 34.4230905656941,
    38.0334583483165, 43.1063289811699, 49.1094955058188, 54.3978511814734,
    57.239868192896, 57.5653029514576, 56.6251856430178, 54.751296544923,
    58.5347515945767, 58.9014585861291, 56.2201079977937, 51.8342424406321,
    46.8798076486892, 41.8399680808496, 37.1057305184325, 33.4218487617385,
    31.7280178345281, 32.3978669486336, 35.003438608093, 39.0848221299836,
    44.411770238902, 50.290040276328, 55.1053610250831, 57.4193179381705,
    57.4711717439484, 56.6251856430178, 54.751296544923, 57.5190358621232,
    57.1380597137834, 54.0610453741416, 49.5394640036454, 44.5633330578926,
    39.600130273331, 35.1629096314159, 32.0804219324197, 31.1858213790309,
    32.6558517495657, 35.9488995868774, 40.5591303040321, 46.1347546170462,
    51.7971580575914, 55.994708647562, 57.6645874326474, 57.3844999200117,
    56.6251856430178, 54.751296544923, 56.4121984223684, 55.2297270679689,
    51.7339754817662, 47.1144013445555, 42.210062306141, 37.4246359062908,
    33.3480560628017, 30.8899158842752, 30.8164322612757, 33.1443989174895,
    37.1837884188939, 42.3074348719787, 48.0451666860134, 53.4026420936418,
    56.9230308619404, 57.9172279885731, 57.2936564266774, 56.6251856430178,
    54.751296544923, 55.2380541689542, 53.184834820973, 49.1815860231325,
    44.4296139916105, 39.6861181244448, 35.2540412027046, 31.6811405162928,
    29.8821017676353, 30.5931668810741, 33.7486549649341, 38.5211558578767,
    44.1031549673367, 49.899799405202, 54.888990229333, 57.7501107818609,
    58.1175762929524, 57.1864803248042, 56.6251856430178, 54.751296544923,
    54.0235222030154, 51.0331275668368, 46.397548215317, 41.4110158185319,
    36.8655876543903, 32.9607558055944, 30.0692703042379, 29.0017282811732,
    30.4682664580314, 34.364822826098, 39.7701044659291, 45.7146204366136,
    51.4791532413138, 56.0722279279272, 58.3519447589979, 58.2099576194622,
    57.051902488433, 56.6251856430178, 54.751296544923, 52.798709080469,
    48.8326602528226, 43.461890916554, 38.1190780313031, 33.7289927826894,
    30.417468718699, 28.3244062040725, 28.0798177739192, 30.2932838730695,
    34.7900750823536, 40.6467425797445, 46.8402018839041, 52.5355545152928,
    56.7771010447727, 58.6210429941542, 58.1475216098748, 56.8815730143464,
    56.6251856430178, 54.751296544923, 51.5959482882296, 46.6649483224807,
    40.5384603911814, 34.7738597707327, 30.4506776933279, 27.6660814823935,
    26.3723480663316, 26.9785034211789, 29.8573720948199, 34.7268567933644,
    40.7953253915868, 47.1264793529433, 52.7919999419459, 56.8349179934043,
    58.4735393297155, 57.898521855881, 56.671409209212, 56.6251856430178,
    54.751296544923, 50.4480444472072, 44.6191555037872, 37.8309031638552,
    31.7074713455754, 27.4227360207352, 25.0631922668235, 24.4575716437098,
    25.7701626165998, 29.0830272922987, 34.040347392218, 40.0570946049892,
    46.389357079336, 52.0881045655304, 56.1570806461295, 57.8771375796687,
    57.4543614538842, 56.4228619693494, 56.6251856430178, 54.751296544923,
    49.3863348406204, 42.7720926932179, 35.5153199814585, 29.2489937916713,
    25.1327616250167, 23.1713738656445, 23.0518242033487, 24.723476072624,
    28.1098185224187, 32.8761509385862, 38.6120822000669, 44.7936672439533,
    50.5476812702389, 54.8315940143324, 56.8834019440681, 56.836048850426,
    56.1436103196619, 56.6251856430178, 54.751296544923, 48.4392763614326,
    41.1734353467308, 33.6804128805425, 27.577271351319, 23.890529564383,
    22.3812467555038, 22.5260737246734, 24.1519173511074, 27.2177514270245,
    31.550789770984, 36.8813563394645, 42.8228690179835, 48.5930498538088,
    53.1372228528497, 55.6307010258363, 56.0940957297362, 55.8474231510924,
    56.6251856430178, 54.751296544923, 47.6320215406481, 39.8433530565237,
    32.3064801622762, 26.6261237325344, 23.5904704748049, 22.5729463486504,
    22.8611257110725, 24.2552019962051, 26.7694735255967, 30.4945351037159,
    35.3851543278451, 41.0673102274527, 46.7523271735559, 51.4322460583301,
    54.3040232881912, 55.2999560113868, 55.5531006297682, 56.6251856430178,
    54.751296544923, 46.9869653003579, 38.7836959423822, 31.2983740643414,
    26.133292910454, 23.7908011304587, 23.2483111641211, 23.7191896964837,
    25.0198832709395, 27.051877532779, 30.1019280735851, 34.5099492228765,
    39.9047888020328, 45.3781051180859, 49.9951254408271, 53.0763462271295,
    54.5324042959803, 55.2826502116383, 56.6251856430178, 54.751296544923,
    46.5247520470306, 37.9970731332369, 30.5565683079466, 25.8130932134227,
    24.0564863330696, 24.0089018706954, 24.8384463057344, 26.2810075326878,
    28.0132229331637, 30.4216504457078, 34.2936779092967, 39.3551470753122,
    44.5427726738385, 48.9544697332385, 52.0714722478409, 53.8648070795107,
    55.0590361754209, 56.6251856430178, 54.751296544923, 46.2649661573432,
    37.5042652691156, 30.0465143101251, 25.5149660608876, 24.1761136204258,
    24.7325594097303, 26.1693262650545, 27.869705608287, 29.3457947014116,
    31.195489776298, 34.5769180776148, 39.3104602475769, 44.2036013619691,
    48.3429499728269, 51.3613955173041, 53.3571447621333, 54.9038825678242,
    56.6251856430178, 54.751296544923, 46.2258124180117, 37.351456361502,
    29.8315038386231, 25.2797215776448, 24.1291523604134, 25.3343253501989,
    27.5590586842175, 29.5554028106923, 30.7559667228556, 32.1765580240008,
    35.2490375297455, 39.7399665065931, 44.341569685587, 48.1562845854356,
    50.9770310419476, 53.0529932482941, 54.8354157304596, 56.6251856430178,
    54.751296544923, 46.422484563304, 37.6037805260545, 30.0590183878876,
    25.3239489039628, 24.0458194198766, 25.6628271286748, 28.6046374871265,
    30.9396814558751, 31.9917765907201, 33.1933897788491, 36.1762922658377,
    40.5456323144271, 44.874982298333, 48.339762013477, 50.9157187939297,
    52.9801497242265, 54.8667760645328, 56.6251856430178, 54.751296544923,
    46.8644423585275, 38.3277524376993, 30.9099143003866, 25.9867116187656,
    24.2892994630833, 25.8053316524507, 29.0571841417445, 31.6791471050603,
    32.8173902707573, 34.0647512985452, 37.1289202543771, 41.4812549253833,
    45.6116896648483, 48.7899227810153, 51.1558161553723, 53.1536443154867,
    55.0046890277707, 56.6251856430178, 54.751296544923, 47.5522506633799,
    39.5695392021277, 32.5300296237132, 27.610522556506, 25.4370747780846,
    26.3369362955647, 29.2399736958171, 31.8297697319, 33.159997906717,
    34.7080423705198, 38.0090672607486, 42.4103610368646, 46.4224698453539,
    49.4365926690909, 51.6842103889416, 53.578826468849, 55.248424554596,
    56.6251856430178, 54.751296544923, 48.4748170770151, 41.3370665099812,
    34.9728656478756, 30.3765735676815, 27.9736956992769, 28.0621147643351,
    29.9827127864619, 31.9777697974604, 33.3273474803029, 35.2947881916772,
    38.9509976772009, 43.4227549881571, 47.3523526080598, 50.3046133590786,
    52.5126268661931, 54.2507426844778, 55.5890308779297, 56.6251856430178,
    54.751296544923, 49.6077614095672, 43.5913147455728, 38.1783712649649,
    34.2140275487794, 31.9531020541573, 31.4241404488822, 32.1122823066714,
    33.0019805894629, 33.9434396213557, 36.103022614576, 40.0272255921762,
    44.5691452911527, 48.4842557165303, 51.4647586207585, 53.6587360482798,
    55.1476062263574, 56.0089928492197, 56.6251856430178, 54.751296544923,
    50.9133469226252, 46.2475446126989, 41.9891658200465, 38.8409171520756,
    36.9738441931737, 36.1410005265278, 35.7477952820724, 35.3216456506226,
    35.3671535313895, 37.199387497059, 41.1048825673079, 45.7401791495827,
    49.8125123452119, 52.9416403353191, 55.1033069614922, 56.2210789745395,
    56.482646890037, 56.6251856430178, 54.751296544923, 52.3420477315052,
    49.183578541648, 46.1857518497652, 43.8740622178861, 42.4104546640363,
    41.4111441680126, 40.1617586254715, 38.4642950929607, 37.3506125427603,
    38.4651211967035, 42.1212639956133, 46.8871914579171, 51.2883867152139,
    54.6698103087005, 56.7557281223324, 57.3900579138707, 56.9777417803095,
    56.6251856430178, 54.751296544923, 53.8355419104876, 52.2514114955318,
    50.5211858289379, 48.9365649967279, 47.6856805278194, 46.4346222657653,
    44.4557553268223, 41.6663036889117, 39.4401932066446, 39.7817675805338,
    43.1496357798466, 48.0637521927698, 52.8422548013222, 56.4902167493337,
    58.4482502990983, 58.5440851085298, 57.4583615370017, 56.6251856430178,
    54.751296544923, 55.3307486962773, 55.289830279502, 54.7435134141317,
    53.71243394522, 52.4126088882414, 50.7138048706852, 48.0418262693253,
    44.3854144466926, 41.2693360543106, 40.9706460318387, 44.1297462053077,
    49.2080852459347, 54.3139690560864, 58.1621065703778, 59.9600169450716,
    59.5581548234476, 57.8890406442033, 56.6251856430178, 54.751296544923,
    56.7644401925365, 58.1377492419867, 58.6071900361526, 57.9347245222801,
    56.3452430243529, 53.9623567842668, 50.5039907677995, 46.1243243425031,
    42.4136699187201, 41.7372854729994, 44.8357498874554, 50.0990795875036,
    55.4438332571129, 59.4007554252576, 61.0619872366505, 60.3157853350383,
    58.2394449589779, 56.6251856430178, 54.751296544923, 58.0779025623971,
    60.6488360298529, 61.8877438525658, 61.3657583249659, 59.3039936777596,
    56.0344671332731, 51.6235537620401, 46.5602867225953, 42.5564008836936,
    41.8479188639457, 45.0421867897564, 50.4604823701927, 55.9317246997117,
    59.936761339955, 61.5703921451985, 60.7340612655503, 58.4886563122252,
    56.6251856430178, 54.751296544923, 59.2210847182472, 62.706668392697,
    64.4101763106443, 63.8279081302579, 61.2146318977197, 57.0591821058478,
    51.731904024082, 46.0773762829803, 41.9338101430048, 41.3017194792086,
    44.5509871837152, 49.9967078054413, 55.5016294738177, 59.5858930810543,
    61.3968645083503, 60.7833814534447, 58.6280378329757, 56.6251856430178,
    54.751296544923, 60.155692847649, 64.2371587658281, 66.0809743519662,
    65.2561689351657, 62.1410031433033, 57.3592201703727, 51.4544096818567,
    45.4208719402675, 41.0771897025056, 40.2468867211684, 43.244178082215,
    48.5183034701983, 54.029178250515, 58.3309334416516, 60.5827014883035,
    60.4954720643476, 58.6619263135259, 56.6251856430178, 54.751296544923,
    60.8568217815364, 65.2139901321353, 66.9016529798579, 65.7086482066477,
    62.2160973674586, 57.130467224255, 51.0075387877506, 44.7878814323662,
    40.154774450579, 38.8349860250639, 41.2668926863496, 46.1781078230321,
    51.6962788805952, 56.3770640901844, 59.2997466206402, 59.9559030654234,
    58.6059385660158, 56.6251856430178, 54.751296544923, 61.3129698871023,
    65.6549109689335, 66.9534364601034, 65.3248797009656, 61.5692086579241,
    56.3772530675717, 50.2032509124219, 43.8973629869654, 39.0300203116484,
    37.2290673136587, 39.024337651964, 43.4717856153773, 48.9719906688908,
    54.1065448209209, 57.8050723866835, 59.2822997828549, 58.4833255242745,
    56.6251856430178, 54.751296544923, 61.5245991051021, 65.61056415897,
    66.3636123013517, 64.2701128530723, 60.3117365767751, 55.0941352921901,
    48.9440657804423, 42.6526772843853, 37.7202527557151, 35.6470764319945,
    36.9463665423054, 40.9479599486467, 46.3839144182053, 51.9324310814573,
    56.3631778059407, 58.5955323830388, 58.3203307136565, 56.6251856430178,
    54.751296544923, 61.5016685312086, 65.1501524553739, 65.2729158104967,
    62.7028048692283, 58.5481424609022, 53.3308854053197, 47.2922206174645,
    41.1729713838711, 36.3964661124282, 34.3134155021503, 35.3389138524758,
    38.982244872163, 44.30656153493, 50.1602088390782, 55.1770899280097,
    57.9946538628079, 58.1417017780082, 56.6251856430178, 54.751296544923,
    61.2607044726592, 64.3480804639269, 63.8150940448696, 60.772457594402,
    56.4053327084956, 51.187199211929, 45.3338844586574, 39.5522103305369,
    35.1812296988061, 33.3809414591595, 34.3743719700655, 37.7583258750421,
    42.9238381575358, 48.9521910090147, 54.3634859789156, 57.5437597067657,
    57.9672931353667, 56.6251856430178, 54.751296544923, 60.8219582807122,
    63.2736428044968, 62.1065028661705, 58.6218445830597, 54.0486174151378,
    48.8415736871016, 43.2272422414039, 37.9045331100083, 34.1348821212969,
    32.8559835393798, 34.0367990181378, 37.285189662854, 42.2874110610021,
    48.3732322436004, 53.9685490226853, 57.2715065993778, 57.810205922268,
    56.6251856430178 };

  static const real_T c[703] = { 149.441934480294, 129.83938401268,
    85.6178691653145, 47.478459310354, 30.841263373489, 22.2603682574363,
    16.7940714165507, 13.1471121690492, 10.9017400751229, 9.69720922906667,
    8.9763000823192, 8.0478191954886, 6.50835258423884, 4.68972829229497,
    3.33660881947591, 2.69998957132601, 2.25621279503629, 1.20196205827812,
    179.22437519761, 139.441934480294, 117.555187719847, 77.6616234386284,
    46.2282195632411, 31.0993600753794, 22.7813813014267, 17.2576345027363,
    13.3819938156653, 10.8459559991556, 9.48568331260444, 9.00152025944674,
    8.87871228225241, 8.58485423728019, 8.02523555771386, 7.59815639635857,
    7.58225179883797, 7.64947322744145, 6.50177118981142, -170.77562480239,
    129.441934480294, 106.383451787998, 71.2837958557006, 44.7678407408905,
    30.8683846906636, 22.8788333172396, 17.4727146800693, 13.5302692689905,
    10.7787701451358, 9.22471636353736, 8.81079781926678, 9.25453519541691,
    10.0690474196017, 10.8135799135963, 11.4152952791129, 12.0883138830604,
    12.7142682945795, 11.3989553985087, -160.77562480239, 119.441934480294,
    96.1761882218878, 65.8499699069884, 43.3370555023773, 30.4713043934244,
    22.7332441599349, 17.5025160778326, 13.6540079029205, 10.8699808240579,
    9.27237655729545, 8.97491672004838, 9.81592665792689, 11.3510361602351,
    13.0225517824967, 14.5052219219675, 15.8988256349413, 17.1252629692123,
    15.3161536341303, -150.77562480239, 109.441934480294, 86.7463307606336,
    60.9458329030504, 42.0097575311569, 30.1539201286971, 22.4958545498629,
    17.28334208564, 13.52678629481, 10.8227949045955, 9.31229342474192,
    9.2050490012812, 10.3586938874521, 12.2799932986528, 14.4264002187647,
    16.5183857156697, 18.5994658989677, 20.4039222326932, 17.2646192613853,
    -140.77562480239, 99.4419344802937, 77.9093894571764, 56.2454357631152,
    40.6693765272157, 30.0262175256251, 22.3727587851961, 16.9138792797803,
    13.0790546836896, 10.4433385111433, 9.03774324424675, 9.05612139761944,
    10.3602853284813, 12.4110241508816, 14.6884528113657, 17.0693923432791,
    19.6366728234692, 21.7544160198319, 15.2636061796069, -130.77562480239,
    89.4419344802937, 69.5044432427975, 51.4770423903913, 39.0111772817474,
    29.9136069872632, 22.462981165997, 16.6396066132441, 12.5611177604995,
    9.94753891673606, 8.60764293881958, 8.55158796097246, 9.65679014497193,
    11.4694789444364, 13.5118284017762, 15.7316194746614, 18.2321943373694,
    19.7838720286029, 5.37364827994246, -120.77562480239, 79.4419344802937,
    61.4028432636687, 46.4351658842076, 36.6363572707223, 29.2966537374853,
    22.4846105136689, 16.5120782497395, 12.1938376449796, 9.5264995333146,
    8.08546501679169, 7.62335390380734, 8.06236409057114, 9.16346135373464,
    10.5222418910745, 11.9624604709174, 13.3495543851161, 12.3034158312232,
    -15.9368940361265, -110.77562480239, 69.4419344802937, 53.5098190858332,
    41.0046048866794, 33.2069512208965, 27.4586600936383, 21.6125813904055,
    15.8673390813216, 11.4049280266877, 8.50567592950251, 6.6723625299712,
    5.50198517461485, 4.9619025983154, 5.01302550377024, 5.29665585491185,
    5.3225685663549, 4.27854340904822, -2.106215400447, -38.4143270015203,
    -100.77562480239, 59.4419344802937, 45.7613453574383, 35.1745909914431,
    28.5796587538105, 23.7898860130308, 18.7193899092754, 13.3092336967326,
    8.73537499447644, 5.49539947123167, 3.21212140271286, 1.42184492270639,
    0.0284110732643994, -0.953444508093477, -1.86845405848742, -3.51400194871963,
    -7.48654921623891, -18.9104641541623, -49.5912179967142, -90.7756248023901,
    49.4419344802937, 38.117351218414, 29.0336091306525, 22.8766518766181,
    18.1031734286971, 13.044899747661, 7.65344460061574, 3.00663145058406,
    -0.309014311579861, -2.57429175440127, -4.36471188890269, -5.98289314048954,
    -7.49562490714635, -9.21470273405304, -12.0185961361875, -17.7411009608653,
    -30.2154148898861, -51.9539141580336, -80.7756248023901, 39.4419344802937,
    30.5522686072055, 22.7419188240091, 16.4890229996117, 10.8443609158365,
    4.89131351999105, -0.858704458416754, -5.30629077714281, -8.06093429029875,
    -9.57816417614371, -10.5877683596669, -11.5660847805448, -12.7418827375713,
    -14.4683860536311, -17.5460069396888, -23.5140880304051, -34.5557627856711,
    -49.7409192756645, -70.7756248023901, 29.4419344802937, 23.0444642769973,
    16.4814375734693, 9.99491608997526, 3.07775646886499, -4.14957594085119,
    -10.1542773511039, -13.8976069542462, -15.5392115442138, -15.8469334115509,
    -15.5734493975805, -15.2524749024129, -15.3912351606798, -16.5459076588078,
    -19.3898070085344, -24.9528018251579, -34.2030828516859, -45.1411917068649,
    -60.7756248023901, 19.4419344802937, 15.5667827130868, 10.3895797121088,
    3.97428722276356, -3.90320409824282, -11.9743480177632, -17.6831646520088,
    -20.3670441371633, -20.7109333232282, -19.6288150475232, -17.9105340537135,
    -16.2099748912961, -15.2825654862286, -15.8284427391028, -18.355898017294,
    -23.4040528609246, -31.1230161349028, -39.2053396365048, -50.7756248023901,
    9.44193448029371, 8.08070460451011, 4.49680019953963, -1.23240156830657,
    -9.20889981253835, -17.3390827533812, -22.3639043686384, -23.8975855478515,
    -22.7684882877114, -20.1337041198792, -17.1643809961029, -14.6284583756299,
    -13.1698095882189, -13.3589434385016, -15.5749672762283, -20.0694199747102,
    -26.4859926434176, -32.4763608205225, -40.7756248023901, -0.558065519706295,
    0.535991869053869, -1.30206495508509, -5.70051836164862, -12.7593694721813,
    -20.3462163432427, -24.7460742186998, -25.0050018710393, -21.9443416542153,
    -17.6809294836967, -13.9831411748904, -11.3614997397981, -9.95301205229987,
    -10.020103606571, -11.8947900867789, -15.7556480331401, -20.96424121136,
    -25.2620977385194, -30.7756248023901, -10.5580655197063, -7.12399245350351,
    -7.21893777590909, -9.91418225057749, -15.2244629229659, -21.7482369112778,
    -25.5999596656952, -24.2596306553099, -18.9740554133463, -13.4472691940733,
    -9.60755467324346, -7.33336552726549, -6.23199237796391, -6.29895091633714,
    -7.82934310909661, -10.9773716768087, -14.9625509409058, -17.7538651784444,
    -20.7756248023901, -20.5580655197063, -14.9532839481442, -13.4908114283464,
    -14.5454400965696, -17.7049890024229, -22.2682953027485, -24.8155973627105,
    -21.4718074138947, -14.6506681578154, -8.91831440585403, -5.42634683181983,
    -3.5264306870472, -2.6361619610473, -2.65306143799746, -3.79244248788955,
    -6.0994361191259, -8.74373937096726, -10.0824007599976, -10.7756248023901,
    -30.5580655197063, -22.9942208851983, -20.2842226200175, -20.1206768370984,
    -21.3353860279756, -22.9870532673254, -22.372959215435, -16.6244893268155,
    -9.73129179198608, -5.03273613629083, -2.31045450910776, -0.739085237139782,
    0.135868558094139, 0.362564779900068, -0.186000355647946, -1.39401564420924,
    -2.48963843428706, -2.34712799271102, -0.7756248023901, -40.5580655197063,
    -31.2719003114071, -27.6354406332055, -26.767597979733, -26.7096926517577,
    -25.5538991410779, -20.3635595267291, -11.5244491061924, -5.11071272830527,
    -1.8091204466765, -0.0244584957828951, 1.13755403928388, 1.99055903395519,
    2.54902207367941, 2.80294770930211, 2.99284399598712, 3.66853164196582,
    5.36613184679746, 9.22437519760991, -50.5580655197063, -39.7943144420684,
    -35.4519957193492, -34.1971133834261, -33.4525477810601, -30.487163535865,
    -21.5192374703988, -9.14692495985045, -2.02362987760876, 0.741867223267169,
    1.93017785609649, 2.69251808848724, 3.39646844081018, 4.19248147547429,
    5.29817568114385, 7.04354649928307, 9.62109601806315, 12.9717394801603,
    19.2243751976099, -60.5580655197063, -48.5580693690456, -43.5639338004461,
    -41.9000063910994, -40.5483763122853, -36.3743141309907, -25.4324835323719,
    -10.6807882909958, -1.77422721989459, 1.68207880087104, 2.98141640192716,
    3.67293159260652, 4.36387660603436, 5.46112568587727, 7.45494417586041,
    10.7526029180166, 15.236398364775, 20.3707824827921, 29.2243751976099,
    -70.5580655197063, -57.557806494227, -51.7912738180735, -49.3804907267863,
    -47.0292340138091, -41.4925700443328, -29.5503730649259, -14.3483901465594,
    -4.22825360944499, 0.337579303189909, 2.25319951432805, 3.30079410896851,
    4.3790627276388, 6.13205409092889, 9.18766749040008, 13.9766457667834,
    20.3072992967568, 27.4336271358336, 39.2243751976099, -80.5580655197063,
    -66.7967938212204, -59.9980530840233, -56.2781829138226, -52.255340667761,
    -44.7892674271102, -31.8561154181464, -17.2567546108248, -7.18736553637564,
    -2.03453312848667, 0.42505319668824, 1.91301706436097, 3.5382752923008,
    6.11151973269744, 10.2554570669444, 16.3819296786708, 24.4966200566939,
    33.9722418346222, 49.2243751976099, -90.5580655197063, -76.2965659969203,
    -68.1223950101545, -62.3731400088744, -55.8133567193966, -45.6813289267,
    -31.4659503833643, -17.7521710832089, -8.59868695943881, -3.59446589260863,
    -0.974100826657488, 0.723796776088461, 2.63318452376287, 5.65525908159926,
    10.4375430007279, 17.4843815535719, 27.2716003160734, 39.6893527799458,
    59.2243751976099, -100.558065519706, -86.1043793580069, -76.1890381343058,
    -67.5347911356264, -57.3499960672545, -43.8099303191493, -28.3879948415668,
    -15.9298036781918, -8.23932604666685, -3.965540655894, -1.55763285305071,
    0.115516859326541, 1.98460825423869, 4.88100756634295, 9.51918326947874,
    16.7045205143456, 27.8033638329544, 44.0757375968085, 69.2243751976099,
    -110.558065519706, -96.2978916080377, -84.3188015856198, -71.6434345681673,
    -56.405616174231, -38.9454890164752, -23.0462062734345, -12.3970276033428,
    -6.51386693994156, -3.39793063587684, -1.59722456155929, -0.237144766898065,
    1.29970183971714, 3.58209278313178, 7.26509747627218, 13.4662154071351,
    24.8745813335369, 46.1934105239935, 79.2243751976099, -120.558065519706,
    -106.98627104801, -92.7544191322972, -74.4647209260133, -52.2199542781238,
    -31.1106800924125, -16.0927784437053, -7.65734258319773, -3.61337904055669,
    -1.85441476499618, -1.04875976865862, -0.449882136408548, 0.324915239035241,
    1.52664721424569, 3.56049836964238, 7.53247570839313, 17.2088302174202,
    44.247810235203, 89.2243751976099, -130.558065519706, -118.305427261713,
    -101.935819315914, -75.3960608459829, -43.7299694867056, -21.2726734712591,
    -9.01538197761433, -3.05432122798975, -0.652690898826454, -0.123886496952384,
    -0.400394364857748, -0.835508219764187, -1.16711205594583, -1.36761837388326,
    -1.33055386577678, -0.309854859792186, 5.27922850931222, 35.2052748808348,
    99.2243751976099, -140.558065519706, -130.402043764445, -112.700550373612,
    -72.7420754172457, -30.3847510879658, -11.4547847090586, -3.48175909574009,
    -0.126262187997179, 0.839747268642045, 0.465874958250376, -0.59617337782627,
    -1.90823985311502, -3.29996822546793, -4.81917905639997, -6.50501879612033,
    -7.95695349741629, -6.72377623500602, 17.5094277989924, 109.22437519761,
    -150.558065519706, -143.397665598443, -126.804135145864, -60.8109297123481,
    -13.9256854006666, -3.0501537674303, 0.461406341631644, 1.45969717970436,
    1.22571817758342, 0.231848541495735, -1.30776116796795, -3.23501887552935,
    -5.43971067455608, -7.88946644240026, -10.5623661670236, -13.199853011667,
    -14.4015155727936, -0.921000287960726, 119.22437519761, -160.558065519706,
    -157.325352597478, -148.088793733252, -21.5199131010046, 1.69789742132898,
    3.95391486978843, 3.92016160209719, 3.22585948499654, 2.20109092794355,
    0.81133057222975, -1.09716923606094, -3.55881244838462, -6.40470473161935,
    -9.40542953792285, -12.3901297110131, -15.1690932021743, -17.0928386585431,
    -11.0981222364897, 129.22437519761, -170.558065519706, -172.048521555299,
    177.98970343471, 25.5949991877706, 13.7252928154454, 9.90026950483082,
    7.46216509092049, 5.70470526517457, 4.25288333218933, 2.67356641523659,
    0.535619394751164, -2.30997295862294, -5.58446376652822, -8.84392893795485,
    -11.7735478669602, -14.2475855058453, -16.141669249072, -13.8908753598544,
    139.22437519761, 179.441934480294, 172.790211880887, 139.154915313425,
    42.1874610438563, 21.8713419349998, 14.8090649194084, 10.8488992913764,
    8.34642679755204, 6.61694057608971, 5.03264467798731, 2.96798842433252,
    0.119265049914563, -3.23341029079973, -6.50010086767736, -9.21729885539963,
    -11.2823088943571, -12.9187707596642, -12.4731375344914, 149.22437519761,
    169.441934480294, 157.71923737559, 112.459705145398, 47.0752851859076,
    26.8972453526091, 18.5302424170096, 13.7018662966348, 10.6719184884684,
    8.75598561571019, 7.31371926806477, 5.61089700812309, 3.1433812865072,
    0.0456271419960516, -3.03188354549276, -5.45296581882219, -7.08983362621163,
    -8.39062948779411, -8.83570204173632, 159.22437519761, 159.441934480294,
    143.276665552784, 96.3505707893558, 48.0658815028425, 29.6429950290303,
    20.9678348813225, 15.7130478588715, 12.3444584537077, 10.3014875046876,
    9.04643163321852, 7.85778125344673, 6.06411083590659, 3.54238680490875,
    0.887680002404719, -1.11719985090339, -2.28925027961885, -3.19203336305879,
    -4.06337403484817, 169.22437519761, 149.441934480294, 129.83938401268,
    85.6178691653145, 47.478459310354, 30.841263373489, 22.2603682574363,
    16.7940714165507, 13.1471121690492, 10.9017400751229, 9.69720922906667,
    8.9763000823192, 8.04781919548859, 6.50835258423883, 4.68972829229497,
    3.33660881947591, 2.699989571326, 2.25621279503629, 1.20196205827812,
    179.22437519761 };

  static const real_T d[703] = { -72.1426970490461, -78.4077012551083,
    -81.0166985695901, -77.562307042515, -71.6124581685133, -64.3561758741196,
    -54.9277137042664, -42.1102978454202, -25.1367127222467, -4.99896330820727,
    14.8670994921615, 31.1698814412766, 43.4468300142217, 53.1477388645991,
    61.939521086861, 70.6425628931937, 78.9381646484269, 86.1007341186352,
    88.0808547416329, -72.1426970490461, -77.6461137360935, -79.1926445086176,
    -75.5566830761938, -69.6807919921195, -62.4005776421435, -52.827985201887,
    -39.7021248822875, -22.2338518632063, -1.63824993131358, 18.249640278654,
    34.0539045448378, 45.5167352742853, 54.3935196918738, 62.6458762952691,
    71.1026783875331, 79.2351433900942, 86.2142615945006, 88.0808547416329,
    -72.1426970490461, -76.7262059592679, -77.3622926249336, -73.6331985909082,
    -67.8128495536942, -60.46243396636, -50.7380279374075, -37.433557182916,
    -19.8005917974504, 0.83651279092766, 20.5685011895211, 36.1155316608928,
    47.2786462290341, 55.8392667188065, 63.810295936511, 72.0045450160469,
    79.832894212019, 86.4712340086889, 88.0808547416329, -72.1426970490461,
    -75.6900261763261, -75.5064833109354, -71.733679172611, -65.9846677837741,
    -58.5168951185022, -48.5571072384298, -35.060649677523, -17.4043107529785,
    3.02137748233044, 22.4139750498897, 37.7349367273393, 48.8602886780389,
    57.463724482641, 65.3688456091342, 73.290627780208, 80.6932688117041,
    86.8539014119162, 88.0808547416329, -72.1426970490461, -74.5738128767123,
    -73.5964986476236, -69.7692698589021, -64.136884542142, -56.574460935513,
    -46.3167997189378, -32.5354761620936, -14.8223861839771, 5.3599255370131,
    24.3811494119018, 39.4733017712082, 50.6022624995404, 59.336617617698,
    67.2424171926673, 74.8709240134786, 81.7605575069545, 87.333297786027,
    88.0808547416329, -72.1426970490461, -73.4105951912, -71.6123883604195,
    -67.6348679975892, -62.1521983645132, -54.6265717671992, -44.1515400650889,
    -30.0657102210554, -12.2505412248398, 7.7245417252792, 26.454269703431,
    41.4158675725945, 52.5857291166866, 61.4229412070196, 69.3019926907494,
    76.6210233441591, 82.9571694448901, 87.8597501495903, 88.0808547416329,
    -72.1426970490461, -72.2329092962163, -69.5614900920069, -65.2521320970002,
    -59.867127256624, -52.5500290398243, -42.0817194551777, -27.7864213723263,
    -9.82872667224122, 10.0196954986407, 28.5401208275942, 43.446856355,
    54.6858028069622, 63.5773498979104, 71.3743787700629, 78.3804684544368,
    84.1693488790623, 88.3332783482458, 88.0808547416329, -72.1426970490461,
    -71.0742341102692, -67.4922352634155, -62.6305844806411, -57.1584370540586,
    -50.0952347463743, -39.798989664825, -25.3284372257666, -7.07518353531028,
    12.7533646906163, 30.9562423435258, 45.605448024437, 56.7590276300197,
    65.5965405308237, 73.2388077806548, 79.9304174825759, 85.2098402957956,
    88.5498657493613, 88.0808547416329, -72.1426970490461, -69.9685273061743,
    -65.4962756082933, -59.9150243498898, -54.0855168336237, -47.0751406382934,
    -36.8277044395928, -22.023415926993, -3.34767765134467, 16.3082721703629,
    33.7607308562786, 47.7002473757916, 58.4841004812356, 67.1398182031294,
    74.5725954548835, 80.9565910630997, 85.7762170050811, 88.3156378165624,
    88.0808547416329, -72.1426970490461, -68.9479580498733, -63.6946686018314,
    -57.3893013200438, -51.0206004283603, -43.757599860537, -33.270696570616,
    -18.0427931943792, 0.79825278647429, 19.7983099455141, 36.0682661006284,
    49.0011367746283, 59.2617141980649, 67.708865392024, 74.9698903560872,
    81.1158296087179, 85.5873935811067, 87.7395468737978, 88.0808547416329,
    -72.1426970490461, -68.0395903552239, -62.208952368132, -55.4182086503093,
    -48.6559617446122, -41.138035697541, -30.4589264277239, -15.1955721990972,
    3.21426913853773, 21.2979551574211, 36.5404118790712, 48.6831726595458,
    58.5603707822374, 66.93599685817, 74.2045130457481, 80.3168196916672,
    84.7228907818675, 87.0205591420387, 88.0808547416329, -72.1426970490461,
    -67.2622486834181, -61.1241868850415, -54.3236149751842, -47.769096133209,
    -40.6170608219277, -30.4876319253527, -16.0831892340299, 1.4210563687155,
    19.01289895022, 34.1375405612309, 46.2854583798726, 56.2867453329049,
    64.9311850498085, 72.4997294709822, 78.8576197443603, 83.5153129836817,
    86.2688054028448, 88.0808547416329, -72.1426970490461, -66.6249025744842,
    -60.4575886987586, -54.2311342896123, -48.7629027230831, -42.9738638668216,
    -34.4398229867307, -21.8270798042978, -5.52892992368521, 12.1751415403002,
    28.3738481575445, 41.7671668093832, 52.8031202696478, 62.2399020261615,
    70.3875333756011, 77.1689566113044, 82.2359316181614, 85.5419665810133,
    88.0808547416329, -72.1426970490461, -66.1274961808788, -60.1489998853289,
    -54.9794904049554, -51.322390255028, -47.5605251307732, -41.1220205254112,
    -30.7846028624068, -16.1793364304649, 1.59650277043016, 19.7154454762554,
    35.6679410117888, 48.7771878717153, 59.5058298702747, 68.3703947306777,
    75.5817365569961, 81.0454504547548, 84.8759398614958, 88.0808547416329,
    -72.1426970490461, -65.7642695192398, -60.0823497603493, -56.1744998143224,
    -54.5864838913875, -52.8884912189955, -48.3516270399803, -40.205252685346,
    -27.6150577064916, -10.1972643366511, 10.0014903293594, 29.1942105839897,
    44.9444337371964, 57.1801314647786, 66.7427653873479, 74.2813023188506,
    80.0321533169033, 84.295489105311, 88.0808547416329, -72.1426970490461,
    -65.5285864347809, -60.1314818520706, -57.3621644167885, -57.6599708342004,
    -57.8039544800926, -54.822286874861, -48.3493089275799, -37.2832761380731,
    -20.160770358333, 1.72082259659543, 23.7422163783556, 41.8752637738838,
    55.4676833612988, 65.6094604317195, 73.3413498019983, 79.2384024030079,
    83.8178953087091, 88.0808547416329, -72.1426970490461, -65.4175821980786,
    -60.2096607637838, -58.2073783871192, -59.941010776179, -61.8099163114035,
    -60.2934711197268, -54.8033632882146, -44.0869897901817, -26.5578961693036,
    -3.4366261386988, 20.3449459660574, 39.9946907439432, 54.4899880095224,
    64.9947181702546, 72.7699812040029, 78.6759421691195, 83.4546660020433,
    88.0808547416329, -72.1426970490461, -65.4349499368626, -60.300415020869,
    -58.591726365425, -61.1322332812486, -64.6093469450569, -64.6782326848597,
    -59.6285293924044, -48.1742455431423, -29.4997291480602, -5.3131229878721,
    19.3108453365109, 39.5307945363022, 54.3307985770703, 64.8865578564924,
    72.5355915981126, 78.3363966777783, 83.2128755694625, 88.0808547416329,
    -72.1426970490461, -65.5909154094512, -60.4586638489208, -58.6231311330156,
    -61.2038465528344, -65.78506614531, -67.4049371091977, -62.5862671762816,
    -50.0803506219327, -30.1585812784767, -5.07182385263941, 19.9361185329568,
    40.1761596693027, 54.8479698567593, 65.1855431115266, 72.5728500788337,
    78.2002522957367, 83.0965013510853, 88.0808547416329, -72.1426970490461,
    -65.8995304264036, -60.7860398795053, -58.5841626293637, -60.4790032470905,
    -65.1481858946198, -67.7948914292282, -63.2166597432757, -50.0627296443241,
    -29.4367575702435, -3.90993550338497, 21.1915370723048, 41.2808393524348,
    55.6885973180897, 65.7083263523268, 72.7983110600416, 78.246445707332,
    83.1076443259552, 88.0808547416329, -72.1426970490461, -66.3743257070996,
    -61.3935940688849, -58.8312960009267, -59.6595636979571, -63.3002202171287,
    -65.9298211869635, -61.4483919806996, -48.0352906596728, -27.2083387204854,
    -1.78419914602983, 22.9373206055063, 42.5988713721664, 56.6218521546574,
    66.3048163491903, 73.1469906074209, 78.4618642547827, 83.247322372798,
    88.0808547416329, -72.1426970490461, -67.0237457874613, -62.3667275800025,
    -59.6633864321641, -59.5477750423767, -61.5978602195664, -63.0097840530951,
    -58.0587993579258, -44.32370232298, -23.344735443883, 1.67906497148683,
    25.4814008533185, 44.2395878935087, 57.6258420176035, 66.9294713112183,
    73.6002702561172, 78.8466555178861, 83.5154987934781, 88.0808547416329,
    -72.1426970490461, -67.847593472744, -63.7437233762719, -61.219674021038,
    -60.6117550680829, -61.280794251305, -60.8633403353013, -54.7524461130702,
    -40.4862403823516, -19.2875189226073, 5.32361667325577, 28.1252162835239,
    45.8884116529088, 58.602696041517, 67.5789357462174, 74.1780293007772,
    79.4112101553729, 83.910140985875, 88.0808547416329, -72.1426970490461,
    -68.8351404450363, -65.5123146554124, -63.464672208972, -62.8186828445202,
    -62.6465348862738, -60.5962474203365, -53.121218872946, -38.3118334284343,
    -17.002753174666, 7.35550714876427, 29.6301095480778, 46.9010086720742,
    59.3267445958523, 68.2330543070869, 74.906964343506, 80.1642917663935,
    84.4253254852192, 88.0808547416329, -72.1426970490461, -69.9649088224993,
    -67.6206980473539, -66.2492031336386, -65.8095377575841, -65.1544182717149,
    -61.871077704132, -53.2181163052385, -37.9327445027544, -16.5782369721158,
    7.7019134164632, 29.895092487045, 47.1734037020246, 59.739123725208,
    68.8817173950909, 75.7884425887219, 81.0949329972943, 85.0485489069957,
    88.0808547416329, -72.1426970490461, -71.2056442104967, -69.9944617982352,
    -69.3910868290027, -69.1568684723848, -68.019488631607, -63.6791284477604,
    -54.0846500189723, -38.4007856354, -16.9574094433233, 7.3956504357345,
    29.6989724776333, 47.148869568855, 60.0079352850892, 69.5328812038406,
    76.7689592691977, 82.1501779653558, 85.757203913867, 88.0808547416329,
    -72.1426970490461, -72.517807001091, -72.551195160815, -72.7296843334896,
    -72.5160412543396, -70.6208198405923, -65.2151378313224, -54.9344641667097,
    -39.0792464875206, -17.6528474782287, 6.84214232572466, 29.4160491483873,
    47.1214270307223, 60.2672747877527, 70.1478202363861, 77.7107608872519,
    83.2077055633764, 86.513186156705, 88.0808547416329, -72.142697049046,
    -73.8549957872532, -75.2083521092898, -76.1393048828847, -75.6227480000124,
    -72.5357682286991, -65.9559500174976, -55.1174588647564, -39.2578557012413,
    -18.0502619287427, 6.40493184628654, 29.1893912169247, 47.1342127105147,
    60.4861719141297, 70.5872847078081, 78.3801852066036, 84.0478442433561,
    87.2519097526347, 88.0808547416329, -72.1426970490461, -75.1650029386787,
    -77.8838059479252, -79.5123710809196, -78.201828927651, -73.4914408465844,
    -65.6453906387703, -54.1721436145441, -38.2003730326887, -17.2756840330384,
    6.74937179093955, 29.2653405920845, 47.1380499016319, 60.4918087776492,
    70.6214712402973, 78.5004399289864, 84.3802333754523, 87.858374851796,
    88.0808547416329, -72.1426970490461, -76.3906271326824, -80.4889885290014,
    -82.7278783363759, -79.9308651348184, -73.5312092076959, -64.6318757426698,
    -52.5950892977004, -36.4759173889911, -15.8829801867624, 7.4198577952646,
    29.2719471628134, 46.7903540474337, 59.9783507219968, 70.01382520743,
    77.9035601830357, 84.036032561006, 88.1500281597585, 88.0808547416329,
    -72.1426970490461, -77.4709446925632, -82.9074115724946, -85.5660845235654,
    -80.5725017036341, -73.0100665323756, -63.599050628471, -51.4210757752234,
    -35.4971400672734, -15.4586296065887, 7.09765499421041, 28.3816421422969,
    45.6215080589228, 58.6929506420127, 68.6903882398, 76.6712346680951,
    83.1535316858831, 88.0140109849051, 88.0808547416329, -72.1426970490461,
    -78.3444367262922, -84.9273414428859, -87.2376516524346, -80.1771062574827,
    -72.2126584491088, -62.7790594731892, -50.8194335150314, -35.3683468105677,
    -16.0318063490474, 5.81280069558746, 26.6504874797745, 43.7108722819044,
    56.7653847761215, 66.8627270452208, 75.08984655624, 82.0309837660706,
    87.5952535906137, 88.0808547416329, -72.1426970490461, -78.9556598897692,
    -86.0819267465185, -86.33863675164, -79.0335428155743, -71.1748256678895,
    -61.8908651924868, -50.1096637864448, -34.9459900928056, -16.1266143056531,
    4.97722154654652, 25.1241771474921, 41.7717134579302, 54.712626659092,
    64.9373793373094, 73.4882507161091, 80.9210048315143, 87.1034545316243,
    88.0808547416329, -72.1426970490461, -79.2656508973888, -85.8310315061931,
    -84.1982471855392, -77.4323416251154, -69.8401525656115, -60.6666130879315,
    -48.8509162778231, -33.6134766755804, -14.9512782358619, 5.49231747972438,
    24.6764803345368, 40.542694368315, 53.0977184739161, 63.3074292569712,
    72.1249020221605, 79.9859308074997, 86.6616620629643, 88.0808547416329,
    -72.1426970490461, -79.2621857899914, -84.5245062939919, -81.9060794893259,
    -75.5730550476135, -68.1983876406599, -59.0364147903689, -47.0132863852792,
    -31.407754640498, -12.5341656350938, 7.48342796170624, 25.636625839302,
    40.434183077723, 52.2742538386567, 62.2215349200302, 71.1569805533382,
    79.3183546771535, 86.3305618669748, 88.0808547416329, -72.1426970490461,
    -78.9628652104417, -82.8229049313331, -79.6787758067477, -73.5971519080705,
    -66.3237809937813, -57.0581901655681, -44.6677748077172, -28.4243938035254,
    -8.98828710880849, 10.8632093827164, 28.0052637137574, 41.5222680428321,
    52.3397939595523, 61.7722289282373, 70.6567825427191, 78.9640414357923,
    86.1395950056571, 88.0808547416329, -72.1426970490461, -78.4077012551083,
    -81.0166985695901, -77.562307042515, -71.6124581685133, -64.3561758741196,
    -54.9277137042664, -42.1102978454202, -25.1367127222467, -4.99896330820727,
    14.8670994921615, 31.1698814412766, 43.4468300142217, 53.1477388645991,
    61.939521086861, 70.6425628931936, 78.9381646484269, 86.1007341186352,
    88.0808547416329 };

  xstar_fcs_B.h_dot_mDs = xstar_fcs_DW.Memory1_1_PreviousInput;
  xstar_fcs_B.gyro_x = xstar_fcs_U.sensors.MPU6500.gyro_x;
  if (xstar_fcs_U.sensors.MPU6500.gyro_x != xstar_fcs_DW.DelayInput1_DSTATE_pq)
  {
    xstar_fcs_DW.DiscreteTimeIntegrator2_DSTATE =
      xstar_fcs_P.DiscreteTimeIntegrator2_IC;
  }

  xstar_fcs_B.Armed = ((xstar_fcs_DW.Discrete_Time_Integrator_DSTATE >
                        xstar_fcs_P.CompareToConstant_const) &&
                       xstar_fcs_DW.Delay4_DSTATE_h);
  if (rtP_eso_log_on) {
    xstar_fcs_B.On_grd = false;
  } else {
    xstar_fcs_B.On_grd = !xstar_fcs_B.Armed;
  }

  xstar_fcs_B.gyro_y = xstar_fcs_U.sensors.MPU6500.gyro_y;
  if (xstar_fcs_U.sensors.MPU6500.gyro_y != xstar_fcs_DW.DelayInput1_DSTATE_fe)
  {
    xstar_fcs_DW.DiscreteTimeIntegrator2_DSTAT_i =
      xstar_fcs_P.DiscreteTimeIntegrator2_IC_a;
  }

  xstar_fcs_B.gyro_z = xstar_fcs_U.sensors.MPU6500.gyro_z;
  if (xstar_fcs_U.sensors.MPU6500.gyro_z != xstar_fcs_DW.DelayInput1_DSTATE_pk)
  {
    xstar_fcs_DW.DiscreteTimeIntegrator2_DSTAT_d =
      xstar_fcs_P.DiscreteTimeIntegrator2_IC_h;
  }

  xstar_fcs_B.Timestamp_ms_c = xstar_fcs_U.sensors.MPU6500.Timestamp_ms;
  if (xstar_fcs_U.sensors.MPU6500.Timestamp_ms !=
      xstar_fcs_DW.DelayInput1_DSTATE) {
    xstar_fcs_DW.DiscreteTimeIntegrator2_DSTAT_a =
      xstar_fcs_P.DiscreteTimeIntegrator2_IC_l;
  }

  if (xstar_fcs_B.On_grd) {
    xstar_fcs_B.LogicalOperator7 = (xstar_fcs_DW.DiscreteTimeIntegrator2_DSTATE <
      xstar_fcs_P.Subsystem_time_judge_on_grd);
    xstar_fcs_B.LogicalOperator18 =
      (xstar_fcs_DW.DiscreteTimeIntegrator2_DSTAT_i <
       xstar_fcs_P.Subsystem1_time_judge_on_grd);
    xstar_fcs_B.LogicalOperator10 =
      (xstar_fcs_DW.DiscreteTimeIntegrator2_DSTAT_d <
       xstar_fcs_P.Subsystem2_time_judge_on_grd);
    xstar_fcs_B.Compare_dq = (xstar_fcs_DW.DiscreteTimeIntegrator2_DSTAT_a <
      xstar_fcs_P.Subsystem6_time_judge_on_grd);
  } else {
    xstar_fcs_B.LogicalOperator7 = (xstar_fcs_DW.DiscreteTimeIntegrator2_DSTATE <
      xstar_fcs_P.Subsystem_time_judge_in_air);
    xstar_fcs_B.LogicalOperator18 =
      (xstar_fcs_DW.DiscreteTimeIntegrator2_DSTAT_i <
       xstar_fcs_P.Subsystem1_time_judge_in_air);
    xstar_fcs_B.LogicalOperator10 =
      (xstar_fcs_DW.DiscreteTimeIntegrator2_DSTAT_d <
       xstar_fcs_P.Subsystem2_time_judge_in_air);
    xstar_fcs_B.Compare_dq = (xstar_fcs_DW.DiscreteTimeIntegrator2_DSTAT_a <
      xstar_fcs_P.Subsystem6_time_judge_in_air);
  }

  if (xstar_fcs_B.LogicalOperator7 && xstar_fcs_B.LogicalOperator18 &&
      xstar_fcs_B.LogicalOperator10 && xstar_fcs_B.Compare_dq) {
    xstar_fcs_DW.DiscreteTimeIntegrator_DSTATE =
      xstar_fcs_P.DiscreteTimeIntegrator_IC;
  }

  xstar_fcs_B.Armed_p = ((!rtP_eso_log_on) && xstar_fcs_B.Armed);
  if (xstar_fcs_B.Armed_p) {
    xstar_fcs_B.Armed = (xstar_fcs_DW.DiscreteTimeIntegrator_DSTATE >
                         xstar_fcs_P.CompareToConstant_const_d);
  } else {
    xstar_fcs_B.Armed = (xstar_fcs_DW.DiscreteTimeIntegrator_DSTATE >
                         xstar_fcs_P.CompareToConstant1_const);
  }

  if (xstar_fcs_B.Armed || (xstar_fcs_DW.DiscreteTimeIntegrator_PrevRese != 0))
  {
    xstar_fcs_DW.DiscreteTimeIntegrator_DSTATE_h =
      xstar_fcs_P.DiscreteTimeIntegrator_IC_b;
  }

  xstar_fcs_B.LogicalOperator_c = (xstar_fcs_DW.Delay_DSTATE_a &&
    (!(xstar_fcs_DW.DiscreteTimeIntegrator_DSTATE_h >=
       xstar_fcs_P.CompareTo1sec_const)));
  if (xstar_fcs_U.sensors.ICM20602.gyro_x != xstar_fcs_DW.DelayInput1_DSTATE_d5)
  {
    xstar_fcs_DW.DiscreteTimeIntegrator2_DSTA_ab =
      xstar_fcs_P.DiscreteTimeIntegrator2_IC_d;
  }

  if (xstar_fcs_U.sensors.ICM20602.gyro_y != xstar_fcs_DW.DelayInput1_DSTATE_e)
  {
    xstar_fcs_DW.DiscreteTimeIntegrator2_DSTAT_m =
      xstar_fcs_P.DiscreteTimeIntegrator2_IC_dc;
  }

  if (xstar_fcs_U.sensors.ICM20602.gyro_z != xstar_fcs_DW.DelayInput1_DSTATE_ei)
  {
    xstar_fcs_DW.DiscreteTimeIntegrator2_DSTAT_n =
      xstar_fcs_P.DiscreteTimeIntegrator2_IC_e;
  }

  if (xstar_fcs_U.sensors.ICM20602.Timestamp_ms !=
      xstar_fcs_DW.DelayInput1_DSTATE_b) {
    xstar_fcs_DW.DiscreteTimeIntegrator2_DSTAT_h =
      xstar_fcs_P.DiscreteTimeIntegrator2_IC_le;
  }

  if (xstar_fcs_B.On_grd) {
    xstar_fcs_B.LogicalOperator7 = (xstar_fcs_DW.DiscreteTimeIntegrator2_DSTA_ab
      < xstar_fcs_P.Subsystem7_time_judge_on_grd);
    xstar_fcs_B.LogicalOperator18 =
      (xstar_fcs_DW.DiscreteTimeIntegrator2_DSTAT_m <
       xstar_fcs_P.Subsystem8_time_judge_on_grd);
    xstar_fcs_B.LogicalOperator10 =
      (xstar_fcs_DW.DiscreteTimeIntegrator2_DSTAT_n <
       xstar_fcs_P.Subsystem9_time_judge_on_grd);
    xstar_fcs_B.Compare_dq = (xstar_fcs_DW.DiscreteTimeIntegrator2_DSTAT_h <
      xstar_fcs_P.Subsystem13_time_judge_on_grd);
  } else {
    xstar_fcs_B.LogicalOperator7 = (xstar_fcs_DW.DiscreteTimeIntegrator2_DSTA_ab
      < xstar_fcs_P.Subsystem7_time_judge_in_air);
    xstar_fcs_B.LogicalOperator18 =
      (xstar_fcs_DW.DiscreteTimeIntegrator2_DSTAT_m <
       xstar_fcs_P.Subsystem8_time_judge_in_air);
    xstar_fcs_B.LogicalOperator10 =
      (xstar_fcs_DW.DiscreteTimeIntegrator2_DSTAT_n <
       xstar_fcs_P.Subsystem9_time_judge_in_air);
    xstar_fcs_B.Compare_dq = (xstar_fcs_DW.DiscreteTimeIntegrator2_DSTAT_h <
      xstar_fcs_P.Subsystem13_time_judge_in_air);
  }

  if (xstar_fcs_B.LogicalOperator7 && xstar_fcs_B.LogicalOperator18 &&
      xstar_fcs_B.LogicalOperator10 && xstar_fcs_B.Compare_dq) {
    xstar_fcs_DW.DiscreteTimeIntegrator1_DSTATE =
      xstar_fcs_P.DiscreteTimeIntegrator1_IC;
  }

  if (xstar_fcs_B.Armed_p) {
    xstar_fcs_B.LogicalOperator2 = !(xstar_fcs_DW.DiscreteTimeIntegrator1_DSTATE
      > xstar_fcs_P.CompareToConstant2_const);
  } else {
    xstar_fcs_B.LogicalOperator2 = !(xstar_fcs_DW.DiscreteTimeIntegrator1_DSTATE
      > xstar_fcs_P.CompareToConstant3_const);
  }

  if (rtP_eso_log_on) {
    xstar_fcs_B.Switch1_l = xstar_fcs_P.Constant1_Value_me;
  } else if (((int32_T)((uint32_T)(xstar_fcs_DW.Delay_DSTATE_a &&
                (!(xstar_fcs_DW.DiscreteTimeIntegrator_DSTATE_h >=
                   xstar_fcs_P.CompareTo1sec_const))) + xstar_fcs_B.Armed) != 0)
             && xstar_fcs_B.LogicalOperator2) {
    xstar_fcs_B.Switch1_l = xstar_fcs_P.Constant_Value_fc;
  } else {
    xstar_fcs_B.Switch1_l = xstar_fcs_P.Constant1_Value_l;
  }

  xstar_fcs_B.Gain_p = xstar_fcs_P.Gyro_ScaleFactor1_Value[0] * (real32_T)
    xstar_fcs_U.sensors.MPU6500.gyro_x;
  xstar_fcs_B.rtb_Product9_idx_0 = xstar_fcs_B.Gain_p - PARAMS.GMPU_Bias[0];
  xstar_fcs_B.rtb_Product8_idx_0 = xstar_fcs_B.Gain_p;
  xstar_fcs_B.Gain_p = xstar_fcs_P.Gyro_ScaleFactor1_Value[1] * (real32_T)
    xstar_fcs_U.sensors.MPU6500.gyro_y;
  xstar_fcs_B.rtb_Product9_idx_1 = xstar_fcs_B.Gain_p - PARAMS.GMPU_Bias[1];
  xstar_fcs_B.rtb_Product8_idx_1 = xstar_fcs_B.Gain_p;
  xstar_fcs_B.Gain_p = xstar_fcs_P.Gyro_ScaleFactor1_Value[2] * (real32_T)
    xstar_fcs_U.sensors.MPU6500.gyro_z;
  xstar_fcs_B.rtb_Product8_idx_2 = xstar_fcs_B.Gain_p - PARAMS.GMPU_Bias[2];
  xstar_fcs_B.VectorConcatenate3[0] = xstar_fcs_U.sensors.ICM20602.gyro_x;
  xstar_fcs_B.VectorConcatenate3[1] = xstar_fcs_U.sensors.ICM20602.gyro_y;
  xstar_fcs_B.VectorConcatenate3[2] = xstar_fcs_U.sensors.ICM20602.gyro_z;
  for (xstar_fcs_B.Sum_mz = 0; xstar_fcs_B.Sum_mz < 3; xstar_fcs_B.Sum_mz++) {
    xstar_fcs_B.rtb_v_idx_0 =
      xstar_fcs_P.Gyro_ScaleFactor_Value[xstar_fcs_B.Sum_mz] * (real32_T)
      xstar_fcs_B.VectorConcatenate3[xstar_fcs_B.Sum_mz];
    xstar_fcs_B.sfor_R_B_mDs2_main[xstar_fcs_B.Sum_mz] = xstar_fcs_B.rtb_v_idx_0
      - PARAMS.GICM_Bias[xstar_fcs_B.Sum_mz];
    xstar_fcs_B.Product2_h[xstar_fcs_B.Sum_mz] = xstar_fcs_B.rtb_v_idx_0;
    xstar_fcs_B.rot_IB_B_raw_radDs1[xstar_fcs_B.Sum_mz] =
      PARAMS.GMPU_Rotation[xstar_fcs_B.Sum_mz + 6] *
      xstar_fcs_B.rtb_Product8_idx_2 + (PARAMS.GMPU_Rotation[xstar_fcs_B.Sum_mz
      + 3] * xstar_fcs_B.rtb_Product9_idx_1 +
      PARAMS.GMPU_Rotation[xstar_fcs_B.Sum_mz] * xstar_fcs_B.rtb_Product9_idx_0);
  }

  for (xstar_fcs_B.Sum_mz = 0; xstar_fcs_B.Sum_mz < 3; xstar_fcs_B.Sum_mz++) {
    xstar_fcs_B.rot_IB_B_raw_radDs2[xstar_fcs_B.Sum_mz] =
      xstar_fcs_P.Gyro_Rotation2_Value[xstar_fcs_B.Sum_mz + 6] *
      xstar_fcs_B.sfor_R_B_mDs2_main[2] +
      (xstar_fcs_P.Gyro_Rotation2_Value[xstar_fcs_B.Sum_mz + 3] *
       xstar_fcs_B.sfor_R_B_mDs2_main[1] +
       xstar_fcs_P.Gyro_Rotation2_Value[xstar_fcs_B.Sum_mz] *
       xstar_fcs_B.sfor_R_B_mDs2_main[0]);
  }

  if (xstar_fcs_B.Switch1_l == 1) {
    xstar_fcs_B.rot_IB_B_raw_radDs[0] = xstar_fcs_B.rot_IB_B_raw_radDs1[0] -
      xstar_fcs_DW.Delay7_DSTATE[0];
    xstar_fcs_B.rot_IB_B_raw_radDs[1] = xstar_fcs_B.rot_IB_B_raw_radDs1[1] -
      xstar_fcs_DW.Delay7_DSTATE[1];
    xstar_fcs_B.rot_IB_B_raw_radDs[2] = xstar_fcs_B.rot_IB_B_raw_radDs1[2] -
      xstar_fcs_DW.Delay7_DSTATE[2];
  } else {
    xstar_fcs_B.rot_IB_B_raw_radDs[0] = xstar_fcs_B.rot_IB_B_raw_radDs2[0] -
      xstar_fcs_DW.Delay_DSTATE[0];
    xstar_fcs_B.rot_IB_B_raw_radDs[1] = xstar_fcs_B.rot_IB_B_raw_radDs2[1] -
      xstar_fcs_DW.Delay_DSTATE[1];
    xstar_fcs_B.rot_IB_B_raw_radDs[2] = xstar_fcs_B.rot_IB_B_raw_radDs2[2] -
      xstar_fcs_DW.Delay_DSTATE[2];
  }

  xstar_fcs_B.acc_x = xstar_fcs_U.sensors.MPU6500.acc_x;
  xstar_fcs_B.FixPtRelationalOperator_d0 = (xstar_fcs_U.sensors.MPU6500.acc_x !=
    xstar_fcs_DW.DelayInput1_DSTATE_ip);
  if (xstar_fcs_B.FixPtRelationalOperator_d0) {
    xstar_fcs_DW.DiscreteTimeIntegrator2_DSTA_ih =
      xstar_fcs_P.DiscreteTimeIntegrator2_IC_ed;
  }

  xstar_fcs_B.acc_y = xstar_fcs_U.sensors.MPU6500.acc_y;
  xstar_fcs_B.FixPtRelationalOperator_n1 = (xstar_fcs_U.sensors.MPU6500.acc_y !=
    xstar_fcs_DW.DelayInput1_DSTATE_k);
  if (xstar_fcs_B.FixPtRelationalOperator_n1) {
    xstar_fcs_DW.DiscreteTimeIntegrator2_DSTAT_j =
      xstar_fcs_P.DiscreteTimeIntegrator2_IC_h2;
  }

  xstar_fcs_B.acc_z = xstar_fcs_U.sensors.MPU6500.acc_z;
  xstar_fcs_B.FixPtRelationalOperator_fv = (xstar_fcs_U.sensors.MPU6500.acc_z !=
    xstar_fcs_DW.DelayInput1_DSTATE_n);
  if (xstar_fcs_B.FixPtRelationalOperator_fv) {
    xstar_fcs_DW.DiscreteTimeIntegrator2_DSTA_jl =
      xstar_fcs_P.DiscreteTimeIntegrator2_IC_ak;
  }

  xstar_fcs_B.FixPtRelationalOperator_fs =
    (xstar_fcs_U.sensors.MPU6500.Timestamp_ms !=
     xstar_fcs_DW.DelayInput1_DSTATE_a);
  if (xstar_fcs_B.FixPtRelationalOperator_fs) {
    xstar_fcs_DW.DiscreteTimeIntegrator2_DSTAT_e =
      xstar_fcs_P.DiscreteTimeIntegrator2_IC_n;
  }

  if (xstar_fcs_B.On_grd) {
    xstar_fcs_B.LogicalOperator7 = (xstar_fcs_DW.DiscreteTimeIntegrator2_DSTA_ih
      < xstar_fcs_P.Subsystem21_time_judge_on_grd);
    xstar_fcs_B.LogicalOperator18 =
      (xstar_fcs_DW.DiscreteTimeIntegrator2_DSTAT_j <
       xstar_fcs_P.Subsystem22_time_judge_on_grd);
    xstar_fcs_B.LogicalOperator10 =
      (xstar_fcs_DW.DiscreteTimeIntegrator2_DSTA_jl <
       xstar_fcs_P.Subsystem23_time_judge_on_grd);
    xstar_fcs_B.Compare_dq = (xstar_fcs_DW.DiscreteTimeIntegrator2_DSTAT_e <
      xstar_fcs_P.Subsystem24_time_judge_on_grd);
  } else {
    xstar_fcs_B.LogicalOperator7 = (xstar_fcs_DW.DiscreteTimeIntegrator2_DSTA_ih
      < xstar_fcs_P.Subsystem21_time_judge_in_air);
    xstar_fcs_B.LogicalOperator18 =
      (xstar_fcs_DW.DiscreteTimeIntegrator2_DSTAT_j <
       xstar_fcs_P.Subsystem22_time_judge_in_air);
    xstar_fcs_B.LogicalOperator10 =
      (xstar_fcs_DW.DiscreteTimeIntegrator2_DSTA_jl <
       xstar_fcs_P.Subsystem23_time_judge_in_air);
    xstar_fcs_B.Compare_dq = (xstar_fcs_DW.DiscreteTimeIntegrator2_DSTAT_e <
      xstar_fcs_P.Subsystem24_time_judge_in_air);
  }

  if (xstar_fcs_B.LogicalOperator7 && xstar_fcs_B.LogicalOperator18 &&
      xstar_fcs_B.LogicalOperator10 && xstar_fcs_B.Compare_dq) {
    xstar_fcs_DW.DiscreteTimeIntegrator2_DSTA_h1 =
      xstar_fcs_P.DiscreteTimeIntegrator2_IC_b;
  }

  if (xstar_fcs_B.Armed_p) {
    xstar_fcs_B.flag_IMU1_acc_loss =
      (xstar_fcs_DW.DiscreteTimeIntegrator2_DSTA_h1 >
       xstar_fcs_P.CompareToConstant4_const);
  } else {
    xstar_fcs_B.flag_IMU1_acc_loss =
      (xstar_fcs_DW.DiscreteTimeIntegrator2_DSTA_h1 >
       xstar_fcs_P.CompareToConstant5_const);
  }

  if (xstar_fcs_B.flag_IMU1_acc_loss ||
      (xstar_fcs_DW.DiscreteTimeIntegrator_PrevRe_l != 0)) {
    xstar_fcs_DW.DiscreteTimeIntegrator_DSTATE_m =
      xstar_fcs_P.DiscreteTimeIntegrator_IC_o;
  }

  xstar_fcs_B.LogicalOperator_j = (xstar_fcs_DW.Delay_DSTATE_k &&
    (!(xstar_fcs_DW.DiscreteTimeIntegrator_DSTATE_m >=
       xstar_fcs_P.CompareTo1sec_const_j)));
  xstar_fcs_B.FixPtRelationalOperator_kg = (xstar_fcs_U.sensors.ICM20602.acc_x
    != xstar_fcs_DW.DelayInput1_DSTATE_kc);
  if (xstar_fcs_B.FixPtRelationalOperator_kg) {
    xstar_fcs_DW.DiscreteTimeIntegrator2_DSTAT_l =
      xstar_fcs_P.DiscreteTimeIntegrator2_IC_g;
  }

  xstar_fcs_B.FixPtRelationalOperator_ks = (xstar_fcs_U.sensors.ICM20602.acc_y
    != xstar_fcs_DW.DelayInput1_DSTATE_b1);
  if (xstar_fcs_B.FixPtRelationalOperator_ks) {
    xstar_fcs_DW.DiscreteTimeIntegrator2_DSTAT_c =
      xstar_fcs_P.DiscreteTimeIntegrator2_IC_k;
  }

  xstar_fcs_B.FixPtRelationalOperator_kt = (xstar_fcs_U.sensors.ICM20602.acc_z
    != xstar_fcs_DW.DelayInput1_DSTATE_el);
  if (xstar_fcs_B.FixPtRelationalOperator_kt) {
    xstar_fcs_DW.DiscreteTimeIntegrator2_DSTA_cc =
      xstar_fcs_P.DiscreteTimeIntegrator2_IC_c;
  }

  xstar_fcs_B.FixPtRelationalOperator_e =
    (xstar_fcs_U.sensors.ICM20602.Timestamp_ms !=
     xstar_fcs_DW.DelayInput1_DSTATE_m);
  if (xstar_fcs_B.FixPtRelationalOperator_e) {
    xstar_fcs_DW.DiscreteTimeIntegrator2_DSTAT_g =
      xstar_fcs_P.DiscreteTimeIntegrator2_IC_cy;
  }

  if (xstar_fcs_B.On_grd) {
    xstar_fcs_B.LogicalOperator7 = (xstar_fcs_DW.DiscreteTimeIntegrator2_DSTAT_l
      < xstar_fcs_P.Subsystem16_time_judge_on_grd);
    xstar_fcs_B.LogicalOperator18 =
      (xstar_fcs_DW.DiscreteTimeIntegrator2_DSTAT_c <
       xstar_fcs_P.Subsystem17_time_judge_on_grd);
    xstar_fcs_B.LogicalOperator10 =
      (xstar_fcs_DW.DiscreteTimeIntegrator2_DSTA_cc <
       xstar_fcs_P.Subsystem18_time_judge_on_grd);
    xstar_fcs_B.Compare_dq = (xstar_fcs_DW.DiscreteTimeIntegrator2_DSTAT_g <
      xstar_fcs_P.Subsystem19_time_judge_on_grd);
  } else {
    xstar_fcs_B.LogicalOperator7 = (xstar_fcs_DW.DiscreteTimeIntegrator2_DSTAT_l
      < xstar_fcs_P.Subsystem16_time_judge_in_air);
    xstar_fcs_B.LogicalOperator18 =
      (xstar_fcs_DW.DiscreteTimeIntegrator2_DSTAT_c <
       xstar_fcs_P.Subsystem17_time_judge_in_air);
    xstar_fcs_B.LogicalOperator10 =
      (xstar_fcs_DW.DiscreteTimeIntegrator2_DSTA_cc <
       xstar_fcs_P.Subsystem18_time_judge_in_air);
    xstar_fcs_B.Compare_dq = (xstar_fcs_DW.DiscreteTimeIntegrator2_DSTAT_g <
      xstar_fcs_P.Subsystem19_time_judge_in_air);
  }

  if (xstar_fcs_B.LogicalOperator7 && xstar_fcs_B.LogicalOperator18 &&
      xstar_fcs_B.LogicalOperator10 && xstar_fcs_B.Compare_dq) {
    xstar_fcs_DW.DiscreteTimeIntegrator3_DSTATE =
      xstar_fcs_P.DiscreteTimeIntegrator3_IC;
  }

  if (xstar_fcs_B.Armed_p) {
    xstar_fcs_B.LogicalOperator7 = !(xstar_fcs_DW.DiscreteTimeIntegrator3_DSTATE
      > xstar_fcs_P.CompareToConstant6_const);
  } else {
    xstar_fcs_B.LogicalOperator7 = !(xstar_fcs_DW.DiscreteTimeIntegrator3_DSTATE
      > xstar_fcs_P.CompareToConstant7_const);
  }

  if (rtP_eso_log_on) {
    xstar_fcs_B.Switch2 = xstar_fcs_P.Constant2_Value_dg;
  } else if (((int32_T)((uint32_T)(xstar_fcs_DW.Delay_DSTATE_k &&
                (!(xstar_fcs_DW.DiscreteTimeIntegrator_DSTATE_m >=
                   xstar_fcs_P.CompareTo1sec_const_j))) +
                        xstar_fcs_B.flag_IMU1_acc_loss) != 0) &&
             xstar_fcs_B.LogicalOperator7) {
    xstar_fcs_B.Switch2 = xstar_fcs_P.Constant4_Value_cr;
  } else {
    xstar_fcs_B.Switch2 = xstar_fcs_P.Constant5_Value_me;
  }

  xstar_fcs_B.rtb_Product8_idx_2 = xstar_fcs_P.Acc_ScaleFactor1_Value[0] *
    (real32_T)xstar_fcs_U.sensors.MPU6500.acc_x;
  xstar_fcs_B.rtb_v_idx_0 = xstar_fcs_B.rtb_Product8_idx_2 - PARAMS.AMPU_Bias[0];
  xstar_fcs_B.rtb_Product9_idx_0 = xstar_fcs_B.rtb_Product8_idx_2;
  xstar_fcs_B.rtb_Product8_idx_2 = xstar_fcs_P.Acc_ScaleFactor1_Value[1] *
    (real32_T)xstar_fcs_U.sensors.MPU6500.acc_y;
  xstar_fcs_B.rtb_v_idx_1 = xstar_fcs_B.rtb_Product8_idx_2 - PARAMS.AMPU_Bias[1];
  xstar_fcs_B.rtb_Product9_idx_1 = xstar_fcs_B.rtb_Product8_idx_2;
  xstar_fcs_B.rtb_Product8_idx_2 = xstar_fcs_P.Acc_ScaleFactor1_Value[2] *
    (real32_T)xstar_fcs_U.sensors.MPU6500.acc_z;
  xstar_fcs_B.DiscreteTimeIntegrator2_oo = xstar_fcs_B.rtb_Product8_idx_2 -
    PARAMS.AMPU_Bias[2];
  for (xstar_fcs_B.Sum_mz = 0; xstar_fcs_B.Sum_mz < 3; xstar_fcs_B.Sum_mz++) {
    xstar_fcs_B.sfor_R_B_mDs2_main[xstar_fcs_B.Sum_mz] =
      PARAMS.AMPU_Rotation[xstar_fcs_B.Sum_mz + 6] *
      xstar_fcs_B.DiscreteTimeIntegrator2_oo +
      (PARAMS.AMPU_Rotation[xstar_fcs_B.Sum_mz + 3] * xstar_fcs_B.rtb_v_idx_1 +
       PARAMS.AMPU_Rotation[xstar_fcs_B.Sum_mz] * xstar_fcs_B.rtb_v_idx_0);
  }

  xstar_fcs_B.DiscreteTimeIntegrator_d0 = -0.0F;
  for (xstar_fcs_B.Sum_mz = 0; xstar_fcs_B.Sum_mz < 9; xstar_fcs_B.Sum_mz++) {
    xstar_fcs_B.DiscreteTimeIntegrator_d0 += (real32_T)fabs
      (PARAMS.AICM_Rotation[xstar_fcs_B.Sum_mz] -
       xstar_fcs_P.Accel_Rotation5_Value[xstar_fcs_B.Sum_mz]);
  }

  xstar_fcs_B.LogicalOperator18 = ((xstar_fcs_B.DiscreteTimeIntegrator_d0 >
    xstar_fcs_P.CompareToConstant4_const_m) && ((PARAMS.AICM_Rotation[3] !=
    xstar_fcs_P.CompareToConstant3_const_e) && (PARAMS.AICM_Rotation[1] !=
    xstar_fcs_P.CompareToConstant5_const_p) && (PARAMS.AICM_Rotation[4] !=
    xstar_fcs_P.CompareToConstant6_const_k)));
  xstar_fcs_B.rtb_v_idx_0 = xstar_fcs_P.Acc_ScaleFactor_Value[0] * (real32_T)
    xstar_fcs_U.sensors.ICM20602.acc_x;
  xstar_fcs_B.rtb_v_idx_1 = xstar_fcs_P.Acc_ScaleFactor_Value[1] * (real32_T)
    xstar_fcs_U.sensors.ICM20602.acc_y;
  xstar_fcs_B.rtb_v_idx_2 = xstar_fcs_P.Acc_ScaleFactor_Value[2] * (real32_T)
    xstar_fcs_U.sensors.ICM20602.acc_z;
  for (xstar_fcs_B.Sum_mz = 0; xstar_fcs_B.Sum_mz < 9; xstar_fcs_B.Sum_mz++) {
    if (xstar_fcs_B.LogicalOperator18) {
      xstar_fcs_B.Sum_i5[xstar_fcs_B.Sum_mz] =
        PARAMS.AICM_Rotation[xstar_fcs_B.Sum_mz];
    } else {
      xstar_fcs_B.Sum_i5[xstar_fcs_B.Sum_mz] =
        xstar_fcs_P.Gyro_Rotation4_Value[xstar_fcs_B.Sum_mz];
    }
  }

  xstar_fcs_B.DiscreteTimeIntegrator_d0 = xstar_fcs_B.rtb_v_idx_0 -
    PARAMS.AICM_Bias[0];
  xstar_fcs_B.Product2_mi = xstar_fcs_B.rtb_v_idx_1 - PARAMS.AICM_Bias[1];
  xstar_fcs_B.raw_sona_h = xstar_fcs_B.rtb_v_idx_2 - PARAMS.AICM_Bias[2];
  for (xstar_fcs_B.Sum_mz = 0; xstar_fcs_B.Sum_mz < 3; xstar_fcs_B.Sum_mz++) {
    xstar_fcs_B.sfor_R_B_mDs2_m[xstar_fcs_B.Sum_mz] =
      xstar_fcs_B.Sum_i5[xstar_fcs_B.Sum_mz + 6] * xstar_fcs_B.raw_sona_h +
      (xstar_fcs_B.Sum_i5[xstar_fcs_B.Sum_mz + 3] * xstar_fcs_B.Product2_mi +
       xstar_fcs_B.Sum_i5[xstar_fcs_B.Sum_mz] *
       xstar_fcs_B.DiscreteTimeIntegrator_d0);
  }

  if (xstar_fcs_B.Switch2 == 1) {
    xstar_fcs_B.sfor_R_B_mDs2[0] = xstar_fcs_B.sfor_R_B_mDs2_main[0];
    xstar_fcs_B.sfor_R_B_mDs2[1] = xstar_fcs_B.sfor_R_B_mDs2_main[1];
    xstar_fcs_B.sfor_R_B_mDs2[2] = xstar_fcs_B.sfor_R_B_mDs2_main[2];
  } else {
    xstar_fcs_B.sfor_R_B_mDs2[0] = xstar_fcs_DW.Delay9_DSTATE[0] +
      xstar_fcs_B.sfor_R_B_mDs2_m[0];
    xstar_fcs_B.sfor_R_B_mDs2[1] = xstar_fcs_DW.Delay9_DSTATE[1] +
      xstar_fcs_B.sfor_R_B_mDs2_m[1];
    xstar_fcs_B.sfor_R_B_mDs2[2] = xstar_fcs_DW.Delay9_DSTATE[2] +
      xstar_fcs_B.sfor_R_B_mDs2_m[2];
  }

  if (xstar_fcs_U.sensors.MPU6500.Timestamp_ms !=
      xstar_fcs_DW.DelayInput1_DSTATE_bk) {
    xstar_fcs_DW.DiscreteTimeIntegrator_DSTAT_jp =
      xstar_fcs_P.DiscreteTimeIntegrator_IC_p;
  }

  xstar_fcs_B.LogicalOperator18 = ((xstar_fcs_P.IMU_detection1_min1 <
    xstar_fcs_B.rot_IB_B_raw_radDs1[0]) && (xstar_fcs_B.rot_IB_B_raw_radDs1[0] <
    xstar_fcs_P.IMU_detection1_max1) && ((xstar_fcs_P.IMU_detection1_min1 <
    xstar_fcs_B.rot_IB_B_raw_radDs1[1]) && (xstar_fcs_B.rot_IB_B_raw_radDs1[1] <
    xstar_fcs_P.IMU_detection1_max1)) && ((xstar_fcs_P.IMU_detection1_min1 <
    xstar_fcs_B.rot_IB_B_raw_radDs1[2]) && (xstar_fcs_B.rot_IB_B_raw_radDs1[2] <
    xstar_fcs_P.IMU_detection1_max1)) && ((xstar_fcs_P.IMU_detection1_min2 <
    xstar_fcs_B.sfor_R_B_mDs2_main[0]) && (xstar_fcs_B.sfor_R_B_mDs2_main[0] <
    xstar_fcs_P.IMU_detection1_max2) && ((xstar_fcs_P.IMU_detection1_min2 <
    xstar_fcs_B.sfor_R_B_mDs2_main[1]) && (xstar_fcs_B.sfor_R_B_mDs2_main[1] <
    xstar_fcs_P.IMU_detection1_max2)) && ((xstar_fcs_P.IMU_detection1_min2 <
    xstar_fcs_B.sfor_R_B_mDs2_main[2]) && (xstar_fcs_B.sfor_R_B_mDs2_main[2] <
    xstar_fcs_P.IMU_detection1_max2))) && ((xstar_fcs_P.IMU_detection1_temp_min <
    xstar_fcs_U.sensors.MPU6500.Temperature_deg) &&
    (xstar_fcs_U.sensors.MPU6500.Temperature_deg <
     xstar_fcs_P.IMU_detection1_temp_max)) &&
    (xstar_fcs_DW.DiscreteTimeIntegrator_DSTAT_jp <
     xstar_fcs_P.IMU_detection1_Time_out) &&
    (xstar_fcs_U.sensors.MPU6500.Timestamp_ms >=
     xstar_fcs_P.CompareToConstant_const_a));
  xstar_fcs_B.LogicalOperator10 = ((!xstar_fcs_B.Armed) &&
    xstar_fcs_B.LogicalOperator18);
  if (xstar_fcs_U.sensors.ICM20602.Timestamp_ms !=
      xstar_fcs_DW.DelayInput1_DSTATE_l) {
    xstar_fcs_DW.DiscreteTimeIntegrator_DSTAT_kr =
      xstar_fcs_P.DiscreteTimeIntegrator_IC_i;
  }

  xstar_fcs_B.LogicalOperator13 = ((xstar_fcs_P.IMU_detection_min1 <
    xstar_fcs_B.rot_IB_B_raw_radDs2[0]) && (xstar_fcs_B.rot_IB_B_raw_radDs2[0] <
    xstar_fcs_P.IMU_detection_max1) && ((xstar_fcs_P.IMU_detection_min1 <
    xstar_fcs_B.rot_IB_B_raw_radDs2[1]) && (xstar_fcs_B.rot_IB_B_raw_radDs2[1] <
    xstar_fcs_P.IMU_detection_max1)) && ((xstar_fcs_P.IMU_detection_min1 <
    xstar_fcs_B.rot_IB_B_raw_radDs2[2]) && (xstar_fcs_B.rot_IB_B_raw_radDs2[2] <
    xstar_fcs_P.IMU_detection_max1)) && ((xstar_fcs_P.IMU_detection_min2 <
    xstar_fcs_B.sfor_R_B_mDs2_m[0]) && (xstar_fcs_B.sfor_R_B_mDs2_m[0] <
    xstar_fcs_P.IMU_detection_max2) && ((xstar_fcs_P.IMU_detection_min2 <
    xstar_fcs_B.sfor_R_B_mDs2_m[1]) && (xstar_fcs_B.sfor_R_B_mDs2_m[1] <
    xstar_fcs_P.IMU_detection_max2)) && ((xstar_fcs_P.IMU_detection_min2 <
    xstar_fcs_B.sfor_R_B_mDs2_m[2]) && (xstar_fcs_B.sfor_R_B_mDs2_m[2] <
    xstar_fcs_P.IMU_detection_max2))) && ((xstar_fcs_P.IMU_detection_temp_min <
    xstar_fcs_U.sensors.ICM20602.Temperature_deg) &&
    (xstar_fcs_U.sensors.ICM20602.Temperature_deg <
     xstar_fcs_P.IMU_detection_temp_max)) &&
    (xstar_fcs_DW.DiscreteTimeIntegrator_DSTAT_kr <
     xstar_fcs_P.IMU_detection_Time_out) &&
    (xstar_fcs_U.sensors.ICM20602.Timestamp_ms >=
     xstar_fcs_P.CompareToConstant_const_dz));
  xstar_fcs_B.LogicalOperator2 = (xstar_fcs_B.LogicalOperator2 &&
    xstar_fcs_B.LogicalOperator13);
  xstar_fcs_B.LogicalOperator18 = ((!xstar_fcs_B.flag_IMU1_acc_loss) &&
    xstar_fcs_B.LogicalOperator18);
  xstar_fcs_B.LogicalOperator13 = (xstar_fcs_B.LogicalOperator7 &&
    xstar_fcs_B.LogicalOperator13);
  xstar_fcs_B.IMU_valid = ((xstar_fcs_B.LogicalOperator10 ||
    xstar_fcs_B.LogicalOperator2) && (xstar_fcs_B.LogicalOperator18 ||
    xstar_fcs_B.LogicalOperator13));
  for (xstar_fcs_B.Sum_mz = 0; xstar_fcs_B.Sum_mz < 9; xstar_fcs_B.Sum_mz++) {
    xstar_fcs_B.M_OB[xstar_fcs_B.Sum_mz] =
      xstar_fcs_DW.Memory_95_PreviousInput[xstar_fcs_B.Sum_mz];
  }

  xstar_fcs_B.mue_rad = xstar_fcs_P.Scalefactor1_Gain_a *
    xstar_fcs_U.sensors.RTK_Base.lat;
  xstar_fcs_B.lambda_rad = xstar_fcs_P.Scalefactor2_Gain *
    xstar_fcs_U.sensors.RTK_Base.lon;
  xstar_fcs_B.UnitDelay = xstar_fcs_DW.UnitDelay_DSTATE;
  xstar_fcs_B.DiscreteTimeIntegrator_d0 = (real32_T)floor((real32_T)
    xstar_fcs_P.Gain1_Gain_k * 9.09494702E-13F * (real32_T)
    xstar_fcs_DW.UnitDelay_DSTATE);
  xstar_fcs_B.Compare_d = (uint8_T)(xstar_fcs_U.sensors.RTK_Base.pos_type ==
    xstar_fcs_P.CompareToConstant1_const_p);
  xstar_fcs_B.Product2_mi = (real32_T)((xstar_fcs_B.DiscreteTimeIntegrator_d0 !=
    0.0F) && (xstar_fcs_B.Compare_d != 0)) +
    xstar_fcs_B.DiscreteTimeIntegrator_d0;
  xstar_fcs_B.LogicalOperator2 = (xstar_fcs_B.Product2_mi >
    xstar_fcs_P.CompareToConstant_const_e);
  if (xstar_fcs_B.LogicalOperator2 &&
      (xstar_fcs_PrevZCX.WGS_Linearization_Trig_ZCE_f != POS_ZCSIG)) {
    xstar_fcs_B.lambda_0_WGS84_rad = xstar_fcs_P.Scalefactor_Gain *
      xstar_fcs_B.lambda_rad;
    xstar_fcs_B.mue_0_WGS84_rad = xstar_fcs_P.Scalefactor1_Gain *
      xstar_fcs_B.mue_rad;
    xstar_fcs_B.rtb_TmpSignalConversionAtSFun_k = cos
      (xstar_fcs_B.mue_0_WGS84_rad);
    xstar_fcs_B.Sum2 = (xstar_fcs_P.constant_Value - xstar_fcs_P.f_Value) *
      xstar_fcs_P.f_Value;
    xstar_fcs_B.Subtract2_b = xstar_fcs_P.constant2_Value -
      xstar_fcs_B.rtb_TmpSignalConversionAtSFun_k *
      xstar_fcs_B.rtb_TmpSignalConversionAtSFun_k * xstar_fcs_B.Sum2;
    xstar_fcs_B.u1_n = sin(xstar_fcs_B.mue_0_WGS84_rad);
    xstar_fcs_B.Sum2 = xstar_fcs_P.a_Value / sqrt(xstar_fcs_P.a1_Value -
      xstar_fcs_B.u1_n * xstar_fcs_B.u1_n * xstar_fcs_B.Sum2);
    xstar_fcs_B.Add_a = xstar_fcs_B.Subtract2_b * xstar_fcs_B.Sum2 +
      xstar_fcs_U.sensors.RTK_Base.hgt;
    xstar_fcs_B.Sum2 += xstar_fcs_U.sensors.RTK_Base.hgt;
    xstar_fcs_B.Product4_h = xstar_fcs_B.Sum2 *
      xstar_fcs_B.rtb_TmpSignalConversionAtSFun_k;
  }

  xstar_fcs_PrevZCX.WGS_Linearization_Trig_ZCE_f = xstar_fcs_B.LogicalOperator2;
  xstar_fcs_B.Compare = (xstar_fcs_B.Product2_mi <
    xstar_fcs_P.CompareToConstant_const_a2);
  if ((int32_T)xstar_fcs_B.Compare < (int32_T)xstar_fcs_DW.DelayInput1_DSTATE_g1)
  {
    xstar_fcs_B.rtb_TmpSignalConversionAtSFun_k = xstar_fcs_P.Gain_Gain *
      xstar_fcs_B.mue_0_WGS84_rad;
    if (xstar_fcs_B.rtb_TmpSignalConversionAtSFun_k >
        xstar_fcs_P.Saturation_UpperSat) {
      xstar_fcs_B.rtb_TmpSignalConversionAtSFun_k =
        xstar_fcs_P.Saturation_UpperSat;
    } else {
      if (xstar_fcs_B.rtb_TmpSignalConversionAtSFun_k <
          xstar_fcs_P.Saturation_LowerSat) {
        xstar_fcs_B.rtb_TmpSignalConversionAtSFun_k =
          xstar_fcs_P.Saturation_LowerSat;
      }
    }

    xstar_fcs_B.Sum2 = xstar_fcs_P.Gain_Gain_j * xstar_fcs_B.lambda_0_WGS84_rad;
    if (xstar_fcs_B.Sum2 > xstar_fcs_P.Saturation1_UpperSat) {
      xstar_fcs_B.Sum2 = xstar_fcs_P.Saturation1_UpperSat;
    } else {
      if (xstar_fcs_B.Sum2 < xstar_fcs_P.Saturation1_LowerSat) {
        xstar_fcs_B.Sum2 = xstar_fcs_P.Saturation1_LowerSat;
      }
    }

    xstar_fcs_B.y[0] = (real32_T)xstar_interp2_dispatch_L7yjKjPr(b,
      xstar_fcs_B.Sum2, xstar_fcs_B.rtb_TmpSignalConversionAtSFun_k, (rtNaN));
    xstar_fcs_B.y[1] = (real32_T)xstar_interp2_dispatch_L7yjKjPr(c,
      xstar_fcs_B.Sum2, xstar_fcs_B.rtb_TmpSignalConversionAtSFun_k, (rtNaN));
    xstar_fcs_B.y[2] = (real32_T)xstar_interp2_dispatch_L7yjKjPr(d,
      xstar_fcs_B.Sum2, xstar_fcs_B.rtb_TmpSignalConversionAtSFun_k, (rtNaN));
    xstar_fcs_DW.Memory_PreviousInput_d[0] = xstar_fcs_B.y[0];
    xstar_fcs_DW.Memory_PreviousInput_d[1] = xstar_fcs_B.y[1];
    xstar_fcs_DW.Memory_PreviousInput_d[2] = xstar_fcs_B.y[2];
  }

  xstar_fcs_B.TmpSignalConversionAtProduc[0] = xstar_fcs_P.Gain3_Gain_l1 *
    xstar_fcs_B.y[1];
  xstar_fcs_B.Product10[0] = arm_cos_f32
    (xstar_fcs_B.TmpSignalConversionAtProduc[0]);
  xstar_fcs_B.TmpSignalConversionAtProduc[0] = arm_sin_f32
    (xstar_fcs_B.TmpSignalConversionAtProduc[0]);
  xstar_fcs_B.DiscreteTimeIntegrator_d0 = arm_cos_f32(0.0F);
  xstar_fcs_B.raw_sona_h = arm_sin_f32(0.0F);
  xstar_fcs_B.Sum_i5[0] = xstar_fcs_B.DiscreteTimeIntegrator_d0 *
    xstar_fcs_B.Product10[0];
  xstar_fcs_B.h_AGL_m = xstar_fcs_B.raw_sona_h * xstar_fcs_B.raw_sona_h;
  xstar_fcs_B.Sum_i5[1] = xstar_fcs_B.h_AGL_m * xstar_fcs_B.Product10[0] -
    xstar_fcs_B.DiscreteTimeIntegrator_d0 *
    xstar_fcs_B.TmpSignalConversionAtProduc[0];
  xstar_fcs_B.DiscreteTimeIntegrator5 = xstar_fcs_B.DiscreteTimeIntegrator_d0 *
    xstar_fcs_B.raw_sona_h;
  xstar_fcs_B.Sum_i5[2] = xstar_fcs_B.DiscreteTimeIntegrator5 *
    xstar_fcs_B.Product10[0] + xstar_fcs_B.raw_sona_h *
    xstar_fcs_B.TmpSignalConversionAtProduc[0];
  xstar_fcs_B.Sum_i5[3] = xstar_fcs_B.DiscreteTimeIntegrator_d0 *
    xstar_fcs_B.TmpSignalConversionAtProduc[0];
  xstar_fcs_B.Sum_i5[4] = xstar_fcs_B.h_AGL_m *
    xstar_fcs_B.TmpSignalConversionAtProduc[0] +
    xstar_fcs_B.DiscreteTimeIntegrator_d0 * xstar_fcs_B.Product10[0];
  xstar_fcs_B.Sum_i5[5] = xstar_fcs_B.DiscreteTimeIntegrator5 *
    xstar_fcs_B.TmpSignalConversionAtProduc[0] - xstar_fcs_B.raw_sona_h *
    xstar_fcs_B.Product10[0];
  xstar_fcs_B.Sum_i5[6] = -xstar_fcs_B.raw_sona_h;
  xstar_fcs_B.Sum_i5[7] = xstar_fcs_B.raw_sona_h *
    xstar_fcs_B.DiscreteTimeIntegrator_d0;
  xstar_fcs_B.Sum_i5[8] = xstar_fcs_B.DiscreteTimeIntegrator_d0 *
    xstar_fcs_B.DiscreteTimeIntegrator_d0;
  xstar_fcs_B.VectorConcatenate3[0] = xstar_fcs_U.sensors.HMC5x83.mag_x;
  xstar_fcs_B.VectorConcatenate3[1] = xstar_fcs_U.sensors.HMC5x83.mag_y;
  xstar_fcs_B.VectorConcatenate3[2] = xstar_fcs_U.sensors.HMC5x83.mag_z;
  if (xstar_fcs_U.sensors.HMC5x83.mag_x < 0) {
    xstar_fcs_B.SumofElements = (int16_T)-xstar_fcs_U.sensors.HMC5x83.mag_x;
  } else {
    xstar_fcs_B.SumofElements = xstar_fcs_U.sensors.HMC5x83.mag_x;
  }

  if (xstar_fcs_U.sensors.HMC5x83.mag_y < 0) {
    xstar_fcs_B.rtb_Switch_delta_pos_y = (int16_T)
      -xstar_fcs_U.sensors.HMC5x83.mag_y;
  } else {
    xstar_fcs_B.rtb_Switch_delta_pos_y = xstar_fcs_U.sensors.HMC5x83.mag_y;
  }

  if (xstar_fcs_U.sensors.HMC5x83.mag_z < 0) {
    xstar_fcs_B.rtb_Switch_delta_pos_z = (int16_T)
      -xstar_fcs_U.sensors.HMC5x83.mag_z;
  } else {
    xstar_fcs_B.rtb_Switch_delta_pos_z = xstar_fcs_U.sensors.HMC5x83.mag_z;
  }

  if ((xstar_fcs_U.sensors.HMC5x83.Timestamp_ms !=
       xstar_fcs_DW.DelayInput1_DSTATE_c) && ((int16_T)
       ((xstar_fcs_B.SumofElements + xstar_fcs_B.rtb_Switch_delta_pos_y) +
        xstar_fcs_B.rtb_Switch_delta_pos_z) >
       xstar_fcs_P.CompareToConstant_const_es)) {
    xstar_fcs_DW.DiscreteTimeIntegrator_DSTATE_c =
      xstar_fcs_P.DiscreteTimeIntegrator_IC_nk;
  }

  xstar_fcs_B.LogicalOperator4_jz = (xstar_fcs_P.Constant1_Value_p &&
    (xstar_fcs_DW.DiscreteTimeIntegrator_DSTATE_c <
     xstar_fcs_P.Mag_Detection_Time_out));
  for (xstar_fcs_B.Sum_mz = 0; xstar_fcs_B.Sum_mz < 3; xstar_fcs_B.Sum_mz++) {
    xstar_fcs_B.Product10[xstar_fcs_B.Sum_mz] =
      (((xstar_fcs_P.Mag_ScaleFactor_Value * (real32_T)
         xstar_fcs_B.VectorConcatenate3[0] *
         PARAMS.Mag_Rotation[xstar_fcs_B.Sum_mz] +
         PARAMS.Mag_Rotation[xstar_fcs_B.Sum_mz + 3] *
         (xstar_fcs_P.Mag_ScaleFactor_Value * (real32_T)
          xstar_fcs_B.VectorConcatenate3[1])) +
        PARAMS.Mag_Rotation[xstar_fcs_B.Sum_mz + 6] *
        (xstar_fcs_P.Mag_ScaleFactor_Value * (real32_T)
         xstar_fcs_B.VectorConcatenate3[2])) -
       PARAMS.Mag_Offset[xstar_fcs_B.Sum_mz]) * (real32_T)
      xstar_fcs_B.LogicalOperator4_jz;
  }

  if ((xstar_fcs_P.Constant1_Value_i > xstar_fcs_B.y[0]) || rtIsNaNF
      (xstar_fcs_B.y[0])) {
    xstar_fcs_B.rtb_Mag_Q_idx_0 = xstar_fcs_P.Constant1_Value_i;
  } else {
    xstar_fcs_B.rtb_Mag_Q_idx_0 = xstar_fcs_B.y[0];
  }

  xstar_fcs_B.rtb_Mag_Q_idx_0 = 1.0F / xstar_fcs_B.rtb_Mag_Q_idx_0;
  for (xstar_fcs_B.Sum_mz = 0; xstar_fcs_B.Sum_mz < 3; xstar_fcs_B.Sum_mz++) {
    xstar_fcs_B.sincos_o2[xstar_fcs_B.Sum_mz] =
      xstar_fcs_DW.Memory_95_PreviousInput[xstar_fcs_B.Sum_mz + 6] *
      (xstar_fcs_B.rtb_Mag_Q_idx_0 * xstar_fcs_B.Product10[2]) +
      (xstar_fcs_DW.Memory_95_PreviousInput[xstar_fcs_B.Sum_mz + 3] *
       (xstar_fcs_B.rtb_Mag_Q_idx_0 * xstar_fcs_B.Product10[1]) +
       xstar_fcs_B.rtb_Mag_Q_idx_0 * xstar_fcs_B.Product10[0] *
       xstar_fcs_DW.Memory_95_PreviousInput[xstar_fcs_B.Sum_mz]);
  }

  for (xstar_fcs_B.Sum_mz = 0; xstar_fcs_B.Sum_mz < 3; xstar_fcs_B.Sum_mz++) {
    xstar_fcs_B.TmpSignalConversionAtProduc[xstar_fcs_B.Sum_mz] =
      xstar_fcs_B.Sum_i5[xstar_fcs_B.Sum_mz + 6] * xstar_fcs_B.sincos_o2[2] +
      (xstar_fcs_B.Sum_i5[xstar_fcs_B.Sum_mz + 3] * xstar_fcs_B.sincos_o2[1] +
       xstar_fcs_B.Sum_i5[xstar_fcs_B.Sum_mz] * xstar_fcs_B.sincos_o2[0]);
  }

  for (xstar_fcs_B.Sum_mz = 0; xstar_fcs_B.Sum_mz < 3; xstar_fcs_B.Sum_mz++) {
    xstar_fcs_B.Product2[xstar_fcs_B.Sum_mz] = 0.0F;
    xstar_fcs_B.Product2[xstar_fcs_B.Sum_mz] +=
      xstar_fcs_DW.Memory_95_PreviousInput[3 * xstar_fcs_B.Sum_mz] *
      xstar_fcs_B.TmpSignalConversionAtProduc[0];
    xstar_fcs_B.Product2[xstar_fcs_B.Sum_mz] +=
      xstar_fcs_DW.Memory_95_PreviousInput[3 * xstar_fcs_B.Sum_mz + 1] *
      xstar_fcs_B.TmpSignalConversionAtProduc[1];
    xstar_fcs_B.Product2[xstar_fcs_B.Sum_mz] +=
      xstar_fcs_DW.Memory_95_PreviousInput[3 * xstar_fcs_B.Sum_mz + 2] *
      xstar_fcs_B.TmpSignalConversionAtProduc[2];
  }

  mw_arm_sqrt_f32(xstar_fcs_B.sincos_o2[0] * xstar_fcs_B.sincos_o2[0] +
                  xstar_fcs_B.sincos_o2[1] * xstar_fcs_B.sincos_o2[1],
                  &xstar_fcs_B.DiscreteTimeIntegrator_d0);
  xstar_fcs_B.DiscreteTimeIntegrator_d0 = xstar_fcs_rt_atan2f_snf
    (xstar_fcs_B.sincos_o2[2], xstar_fcs_B.DiscreteTimeIntegrator_d0);
  xstar_fcs_B.DiscreteTimeIntegrator_pl = (real32_T)fabs
    (xstar_fcs_P.Gain1_Gain_a * xstar_fcs_B.y[2] -
     xstar_fcs_B.DiscreteTimeIntegrator_d0);
  xstar_fcs_B.sincos_o2[0] *= xstar_fcs_B.sincos_o2[0];
  xstar_fcs_B.sincos_o2[1] *= xstar_fcs_B.sincos_o2[1];
  mw_arm_sqrt_f32((xstar_fcs_B.sincos_o2[0] + xstar_fcs_B.sincos_o2[1]) +
                  xstar_fcs_B.sincos_o2[2] * xstar_fcs_B.sincos_o2[2],
                  &xstar_fcs_B.DiscreteTimeIntegrator2_oo);
  xstar_fcs_B.DiscreteTimeIntegrator2_oo = xstar_fcs_P.Nominal_Magnitude_Value -
    xstar_fcs_B.DiscreteTimeIntegrator2_oo;
  xstar_fcs_B.DiscreteTimeIntegrator2_oo = (real32_T)fabs
    (xstar_fcs_B.DiscreteTimeIntegrator2_oo);
  xstar_fcs_B.DiscreteTimeIntegrator2_oo = xstar_fcs_P.Constant1_Value_ij -
    xstar_fcs_B.DiscreteTimeIntegrator2_oo;
  if (xstar_fcs_B.DiscreteTimeIntegrator2_oo >
      xstar_fcs_P.Saturation1_UpperSat_j) {
    xstar_fcs_B.DiscreteTimeIntegrator2_oo = xstar_fcs_P.Saturation1_UpperSat_j;
  } else {
    if (xstar_fcs_B.DiscreteTimeIntegrator2_oo <
        xstar_fcs_P.Saturation1_LowerSat_a) {
      xstar_fcs_B.DiscreteTimeIntegrator2_oo =
        xstar_fcs_P.Saturation1_LowerSat_a;
    }
  }

  xstar_fcs_B.u0_l = xstar_fcs_P.Constant2_Value_b - xstar_fcs_P.Gain2_Gain_ol *
    xstar_fcs_B.DiscreteTimeIntegrator_pl;
  if ((!(xstar_fcs_B.u0_l < xstar_fcs_B.DiscreteTimeIntegrator2_oo)) &&
      (!rtIsNaNF(xstar_fcs_B.DiscreteTimeIntegrator2_oo))) {
    xstar_fcs_B.u0_l = xstar_fcs_B.DiscreteTimeIntegrator2_oo;
  }

  if ((!(xstar_fcs_B.u0_l > xstar_fcs_P.Constant3_Value)) && (!rtIsNaNF
       (xstar_fcs_P.Constant3_Value))) {
    xstar_fcs_B.u0_l = xstar_fcs_P.Constant3_Value;
  }

  xstar_fcs_B.Product4_m = xstar_fcs_B.u0_l * (real32_T)
    xstar_fcs_B.LogicalOperator4_jz;
  xstar_fcs_B.DiscreteTimeIntegrator1 =
    xstar_fcs_DW.DiscreteTimeIntegrator1_DSTAT_n;
  xstar_fcs_B.u1_n = xstar_fcs_P.Deg2Rad_Gain *
    xstar_fcs_U.sensors.RTK_Base.trk_gnd;
  xstar_fcs_B.Sum2 = cos(xstar_fcs_B.u1_n);
  xstar_fcs_B.u1_n = sin(xstar_fcs_B.u1_n);
  xstar_fcs_B.Gain2_p = (real32_T)(xstar_fcs_U.sensors.RTK_Base.hor_spd *
    xstar_fcs_B.Sum2);
  xstar_fcs_B.sample_sum_a = (real32_T)(xstar_fcs_U.sensors.RTK_Base.hor_spd *
    xstar_fcs_B.u1_n);
  xstar_fcs_B.DiscreteTimeIntegrator_d0 = xstar_fcs_DW.Memory_101_PreviousInput
    [0] * xstar_fcs_B.Gain2_p + xstar_fcs_DW.Memory_101_PreviousInput[1] *
    xstar_fcs_B.sample_sum_a;
  xstar_fcs_B.sample_sum_a = xstar_fcs_DW.Memory_101_PreviousInput[2] *
    xstar_fcs_B.Gain2_p + xstar_fcs_DW.Memory_101_PreviousInput[3] *
    xstar_fcs_B.sample_sum_a;
  xstar_fcs_B.Product1[0] = 0.0F;
  xstar_fcs_B.Product1[0] += xstar_fcs_DW.Memory_101_PreviousInput[0] *
    xstar_fcs_B.DiscreteTimeIntegrator_d0;
  xstar_fcs_B.Product1[0] += xstar_fcs_DW.Memory_101_PreviousInput[2] *
    xstar_fcs_B.sample_sum_a;
  xstar_fcs_B.Product1[1] = 0.0F;
  xstar_fcs_B.Product1[1] += xstar_fcs_DW.Memory_101_PreviousInput[1] *
    xstar_fcs_B.DiscreteTimeIntegrator_d0;
  xstar_fcs_B.Product1[1] += xstar_fcs_DW.Memory_101_PreviousInput[3] *
    xstar_fcs_B.sample_sum_a;
  xstar_fcs_B.Gain = (real32_T)(xstar_fcs_P.Gain_Gain_m *
    xstar_fcs_U.sensors.RTK_Base.vert_spd);
  xstar_fcs_B.ant_heading = xstar_fcs_P.Scalefactor5_Gain *
    xstar_fcs_U.sensors.RTK_Base.heading;
  xstar_fcs_B.Timestamp_ms_hd = xstar_fcs_U.sensors.RTK_Base.Timestamp_ms_hd;
  if (xstar_fcs_B.Timestamp_ms_hd != xstar_fcs_DW.DelayInput1_DSTATE_i) {
    xstar_fcs_DW.DiscreteTimeIntegrator_DSTAT_mz =
      xstar_fcs_P.DiscreteTimeIntegrator_IC_mi;
  }

  xstar_fcs_B.LogicalOperator = ((xstar_fcs_U.sensors.RTK_Base.pos_type_hd ==
    xstar_fcs_P.CompareToConstant_const_ly) &&
    (xstar_fcs_U.sensors.RTK_Base.sol_s_hd == xstar_fcs_P.Constant_Value_i) &&
    (xstar_fcs_DW.DiscreteTimeIntegrator_DSTAT_mz <
     xstar_fcs_P.CompareToConstant4_const_a));
  if (xstar_fcs_U.sensors.Vision.confidence >
      xstar_fcs_P.CompareToConstant1_const_o) {
    xstar_fcs_B.In1 = xstar_fcs_U.sensors.Vision;
  }

  xstar_fcs_B.Compare_dq = (xstar_fcs_DW.Memory_54_PreviousInput ||
    (xstar_fcs_U.sensors.Vision.confidence >
     xstar_fcs_P.CompareToConstant3_const_l));
  xstar_fcs_B.DataTypeConversion = xstar_fcs_B.Compare_dq;
  if (xstar_fcs_DW.DiscreteTimeIntegrator1_IC_LOAD != 0) {
    xstar_fcs_DW.DiscreteTimeIntegrator1_DSTAT_b = xstar_fcs_B.Compare_dq;
  }

  xstar_fcs_B.DiscreteTimeIntegrator1_m =
    xstar_fcs_DW.DiscreteTimeIntegrator1_DSTAT_b;
  if (xstar_fcs_U.sensors.Vision.confidence <=
      xstar_fcs_P.CompareToConstant_const_k) {
    xstar_fcs_B.Sum_mz = xstar_fcs_P.Gain_Gain_bf *
      xstar_fcs_U.sensors.Vision.confidence;
    if (xstar_fcs_B.Sum_mz > xstar_fcs_P.Saturation_UpperSat_k) {
      xstar_fcs_B.Sum_mz = xstar_fcs_P.Saturation_UpperSat_k;
    } else {
      if (xstar_fcs_B.Sum_mz < xstar_fcs_P.Saturation_LowerSat_b) {
        xstar_fcs_B.Sum_mz = xstar_fcs_P.Saturation_LowerSat_b;
      }
    }

    xstar_fcs_B.BusAssignment = xstar_fcs_U.sensors.Vision;
    xstar_fcs_B.BusAssignment.confidence = (uint8_T)(xstar_fcs_B.Sum_mz >> 11);
  }

  if (xstar_fcs_DW.DiscreteTimeIntegrator1_DSTAT_b >
      xstar_fcs_P.Switch_Threshold) {
    xstar_fcs_B.DiscreteTimeIntegrator_d0 = xstar_fcs_B.In1.Timestamp_ms;
    xstar_fcs_B.SumofElements = xstar_fcs_B.In1.delta_pos_x;
    xstar_fcs_B.rtb_Switch_delta_pos_y = xstar_fcs_B.In1.delta_pos_y;
    xstar_fcs_B.rtb_Switch_delta_pos_z = xstar_fcs_B.In1.delta_pos_z;
    xstar_fcs_B.rtb_VectorConcatenate1_c_idx_0 = xstar_fcs_B.In1.vel_x;
    xstar_fcs_B.rtb_VectorConcatenate1_c_idx_1 = xstar_fcs_B.In1.vel_y;
    xstar_fcs_B.rtb_VectorConcatenate1_c_idx_2 = xstar_fcs_B.In1.vel_z;
    xstar_fcs_B.rtb_Switch_delta_q0 = xstar_fcs_B.In1.delta_q0;
    xstar_fcs_B.rtb_Switch_delta_q1 = xstar_fcs_B.In1.delta_q1;
    xstar_fcs_B.rtb_Switch_delta_q2 = xstar_fcs_B.In1.delta_q2;
    xstar_fcs_B.rtb_Switch_delta_q3 = xstar_fcs_B.In1.delta_q3;
    xstar_fcs_B.FixPtRelationalOperator = xstar_fcs_B.In1.confidence;
    xstar_fcs_B.rtb_Switch_timestamp_v = xstar_fcs_B.In1.timestamp_v;
  } else {
    xstar_fcs_B.DiscreteTimeIntegrator_d0 =
      xstar_fcs_B.BusAssignment.Timestamp_ms;
    xstar_fcs_B.SumofElements = xstar_fcs_B.BusAssignment.delta_pos_x;
    xstar_fcs_B.rtb_Switch_delta_pos_y = xstar_fcs_B.BusAssignment.delta_pos_y;
    xstar_fcs_B.rtb_Switch_delta_pos_z = xstar_fcs_B.BusAssignment.delta_pos_z;
    xstar_fcs_B.rtb_VectorConcatenate1_c_idx_0 = xstar_fcs_B.BusAssignment.vel_x;
    xstar_fcs_B.rtb_VectorConcatenate1_c_idx_1 = xstar_fcs_B.BusAssignment.vel_y;
    xstar_fcs_B.rtb_VectorConcatenate1_c_idx_2 = xstar_fcs_B.BusAssignment.vel_z;
    xstar_fcs_B.rtb_Switch_delta_q0 = xstar_fcs_B.BusAssignment.delta_q0;
    xstar_fcs_B.rtb_Switch_delta_q1 = xstar_fcs_B.BusAssignment.delta_q1;
    xstar_fcs_B.rtb_Switch_delta_q2 = xstar_fcs_B.BusAssignment.delta_q2;
    xstar_fcs_B.rtb_Switch_delta_q3 = xstar_fcs_B.BusAssignment.delta_q3;
    xstar_fcs_B.FixPtRelationalOperator = xstar_fcs_B.BusAssignment.confidence;
    xstar_fcs_B.rtb_Switch_timestamp_v = xstar_fcs_B.BusAssignment.timestamp_v;
  }

  xstar_fcs_B.raw_sona_h = (real32_T)xstar_fcs_P.Gain4_Gain_d * 2.98023224E-8F *
    (real32_T)xstar_fcs_U.sensors.Vision.ground_distance_mm;
  xstar_fcs_B.h_AGL_m = xstar_fcs_DW.Memory_118_PreviousInput;
  xstar_fcs_B.DiscreteTimeIntegrator5 =
    xstar_fcs_DW.DiscreteTimeIntegrator5_DSTATE;
  xstar_fcs_B.DiscreteTimeIntegrator5_d =
    xstar_fcs_DW.DiscreteTimeIntegrator5_DSTAT_i;
  xstar_fcs_B.LogicalOperator2 = (xstar_fcs_DW.DiscreteTimeIntegrator5_DSTAT_i <=
    xstar_fcs_P.CompareToConstant2_const_m);
  if (xstar_fcs_B.LogicalOperator2 ||
      (xstar_fcs_DW.DiscreteTimeIntegrator_PrevRe_n != 0)) {
    xstar_fcs_DW.DiscreteTimeIntegrator_DSTATE_d =
      xstar_fcs_P.DiscreteTimeIntegrator_IC_g;
  }

  xstar_fcs_B.LogicalOperator7 = ((int32_T)((uint32_T)
    (xstar_fcs_DW.Delay_DSTATE_kf &&
     (!(xstar_fcs_DW.DiscreteTimeIntegrator_DSTATE_d >=
        xstar_fcs_P.CompareTo1sec_const_n))) + xstar_fcs_B.LogicalOperator2) !=
    0);
  xstar_fcs_B.DiscreteTimeIntegrator5_i =
    xstar_fcs_DW.DiscreteTimeIntegrator5_DSTAT_b;
  xstar_fcs_B.LogicalOperator10 = xstar_fcs_DW.Delay_DSTATE_p[0];
  xstar_fcs_B.Compare_ld = ((real32_T)fabs(xstar_fcs_B.raw_sona_h -
    xstar_fcs_DW.Delay_DSTATE_c) >= xstar_fcs_P.CompareToConstant_const_n);
  if (xstar_fcs_DW.DiscreteTimeIntegrator5_IC_LOAD != 0) {
    xstar_fcs_DW.DiscreteTimeIntegrator5_DSTAT_a = xstar_fcs_B.raw_sona_h;
  }

  if (xstar_fcs_B.Compare_ld && (xstar_fcs_DW.DiscreteTimeIntegrator5_PrevRes <=
       0)) {
    xstar_fcs_DW.DiscreteTimeIntegrator5_DSTAT_a = xstar_fcs_B.raw_sona_h;
  }

  xstar_fcs_B.Gain2_d = (xstar_fcs_B.raw_sona_h -
    xstar_fcs_DW.DiscreteTimeIntegrator5_DSTAT_a) * xstar_fcs_P.Gain2_Gain_b;
  if ((real32_T)fabs(xstar_fcs_B.Gain2_d) >
      xstar_fcs_P.CompareToConstant_const_c) {
    xstar_fcs_B.Switch_m = 0.0F;
  } else {
    xstar_fcs_B.Switch_m = xstar_fcs_B.Gain2_d;
  }

  if (xstar_fcs_DW.DiscreteTimeIntegrator5_IC_LO_b != 0) {
    xstar_fcs_DW.DiscreteTimeIntegrator5_DSTAT_o = xstar_fcs_B.Switch_m;
  }

  if (xstar_fcs_DW.Delay_DSTATE_p[0U] &&
      (xstar_fcs_DW.DiscreteTimeIntegrator5_PrevR_c <= 0)) {
    xstar_fcs_DW.DiscreteTimeIntegrator5_DSTAT_o = xstar_fcs_B.Switch_m;
  }

  xstar_fcs_B.DiscreteTimeIntegrator5_c =
    xstar_fcs_DW.DiscreteTimeIntegrator5_DSTAT_o;
  xstar_fcs_B.DiscreteTimeIntegrator5_b =
    xstar_fcs_DW.DiscreteTimeIntegrator5_DSTA_ac;
  xstar_fcs_B.DiscreteTimeIntegrator5_e =
    xstar_fcs_DW.DiscreteTimeIntegrator5_DSTAT_n;
  if (xstar_fcs_DW.Memory_134_PreviousInput || ((real32_T)fabs
       (xstar_fcs_DW.Delay1_DSTATE - xstar_fcs_B.raw_sona_h) !=
       xstar_fcs_P.CompareToConstant5_const_k)) {
    xstar_fcs_DW.DiscreteTimeIntegrator1_DSTAT_e =
      xstar_fcs_P.DiscreteTimeIntegrator1_IC_c;
  }

  xstar_fcs_B.timestamp_s = xstar_fcs_U.sensors.Vision.timestamp_s;
  if (xstar_fcs_B.timestamp_s > xstar_fcs_DW.DelayInput1_DSTATE_d) {
    xstar_fcs_DW.DiscreteTimeIntegrator_DSTAT_dk =
      xstar_fcs_P.DiscreteTimeIntegrator_IC_j;
  }

  xstar_fcs_B.f4 = ((xstar_fcs_B.raw_sona_h >
                     xstar_fcs_P.CompareToConstant1_const_j) &&
                    (xstar_fcs_DW.DiscreteTimeIntegrator_DSTAT_dk <
                     xstar_fcs_P.CompareToConstant3_const_c));
  if (rtP_eso_log_on) {
    xstar_fcs_B.Switch1_a = false;
  } else {
    xstar_fcs_B.Switch1_a = (((!(xstar_fcs_B.raw_sona_h <
      xstar_fcs_P.CompareToConstant2_const_a)) ||
      ((!(xstar_fcs_DW.Memory_118_PreviousInput >=
          xstar_fcs_P.CompareToConstant1_const_c)) ||
       (!(xstar_fcs_DW.DiscreteTimeIntegrator5_DSTATE <=
          xstar_fcs_P.CompareToConstant_const_f)))) &&
      ((xstar_fcs_B.LogicalOperator7 && ((xstar_fcs_B.raw_sona_h <=
      xstar_fcs_P.CompareToConstant_const_al) && (xstar_fcs_B.raw_sona_h >
      xstar_fcs_P.CompareToConstant1_const_n))) || (xstar_fcs_B.raw_sona_h >
      xstar_fcs_P.CompareToConstant3_const_j)) && (((real32_T)fabs
      (xstar_fcs_DW.DiscreteTimeIntegrator5_DSTAT_b -
       xstar_fcs_DW.DiscreteTimeIntegrator5_DSTAT_o) <
      xstar_fcs_P.CompareToConstant8_const) || ((real32_T)fabs
      (xstar_fcs_DW.DiscreteTimeIntegrator5_DSTA_ac -
       xstar_fcs_DW.DiscreteTimeIntegrator5_DSTAT_n) <
      xstar_fcs_P.CompareToConstant8_const_k)) &&
      (xstar_fcs_DW.DiscreteTimeIntegrator1_DSTAT_e <
       xstar_fcs_P.CompareToConstant6_const_b) && xstar_fcs_B.f4);
  }

  xstar_fcs_B.Delay_d = xstar_fcs_DW.Delay_DSTATE_h;
  if (xstar_fcs_B.Switch1_a) {
    xstar_fcs_B.h_grd_sonar = xstar_fcs_B.raw_sona_h;
  } else {
    xstar_fcs_B.h_grd_sonar = xstar_fcs_B.Delay_d;
  }

  xstar_fcs_B.delta_t = (int32_T)(real32_T)floor
    (xstar_fcs_B.DiscreteTimeIntegrator_d0) - (int32_T)
    xstar_fcs_B.rtb_Switch_timestamp_v;
  if (xstar_fcs_B.delta_t > xstar_fcs_P.delay_delay_of) {
    xstar_fcs_B.Sum_mz = xstar_fcs_P.delay_delay_of;
  } else if (xstar_fcs_B.delta_t < xstar_fcs_P.Saturation2_LowerSat) {
    xstar_fcs_B.Sum_mz = xstar_fcs_P.Saturation2_LowerSat;
  } else {
    xstar_fcs_B.Sum_mz = xstar_fcs_B.delta_t;
  }

  if (xstar_fcs_B.delta_t > xstar_fcs_P.delay_delay_of) {
    xstar_fcs_B.cff = xstar_fcs_P.delay_delay_of;
  } else if (xstar_fcs_B.delta_t < xstar_fcs_P.Saturation2_LowerSat) {
    xstar_fcs_B.cff = xstar_fcs_P.Saturation2_LowerSat;
  } else {
    xstar_fcs_B.cff = xstar_fcs_B.delta_t;
  }

  if (xstar_fcs_B.delta_t > xstar_fcs_P.delay1_delay_of) {
    xstar_fcs_B.i0 = xstar_fcs_P.delay1_delay_of;
  } else if (xstar_fcs_B.delta_t < xstar_fcs_P.Saturation2_LowerSat_e) {
    xstar_fcs_B.i0 = xstar_fcs_P.Saturation2_LowerSat_e;
  } else {
    xstar_fcs_B.i0 = xstar_fcs_B.delta_t;
  }

  if (xstar_fcs_B.delta_t > xstar_fcs_P.delay1_delay_of) {
    xstar_fcs_B.i1 = xstar_fcs_P.delay1_delay_of;
  } else if (xstar_fcs_B.delta_t < xstar_fcs_P.Saturation2_LowerSat_e) {
    xstar_fcs_B.i1 = xstar_fcs_P.Saturation2_LowerSat_e;
  } else {
    xstar_fcs_B.i1 = xstar_fcs_B.delta_t;
  }

  if (xstar_fcs_B.delta_t > xstar_fcs_P.delay2_delay_of) {
    xstar_fcs_B.i2 = xstar_fcs_P.delay2_delay_of;
  } else if (xstar_fcs_B.delta_t < xstar_fcs_P.Saturation2_LowerSat_n) {
    xstar_fcs_B.i2 = xstar_fcs_P.Saturation2_LowerSat_n;
  } else {
    xstar_fcs_B.i2 = xstar_fcs_B.delta_t;
  }

  if (xstar_fcs_B.delta_t > xstar_fcs_P.delay2_delay_of) {
    xstar_fcs_B.i3 = xstar_fcs_P.delay2_delay_of;
  } else if (xstar_fcs_B.delta_t < xstar_fcs_P.Saturation2_LowerSat_n) {
    xstar_fcs_B.i3 = xstar_fcs_P.Saturation2_LowerSat_n;
  } else {
    xstar_fcs_B.i3 = xstar_fcs_B.delta_t;
  }

  if (xstar_fcs_B.delta_t > xstar_fcs_P.delay3_delay_of) {
    xstar_fcs_B.i4 = xstar_fcs_P.delay3_delay_of;
  } else if (xstar_fcs_B.delta_t < xstar_fcs_P.Saturation2_LowerSat_a) {
    xstar_fcs_B.i4 = xstar_fcs_P.Saturation2_LowerSat_a;
  } else {
    xstar_fcs_B.i4 = xstar_fcs_B.delta_t;
  }

  if (xstar_fcs_B.delta_t > xstar_fcs_P.delay3_delay_of) {
    xstar_fcs_B.i5 = xstar_fcs_P.delay3_delay_of;
  } else if (xstar_fcs_B.delta_t < xstar_fcs_P.Saturation2_LowerSat_a) {
    xstar_fcs_B.i5 = xstar_fcs_P.Saturation2_LowerSat_a;
  } else {
    xstar_fcs_B.i5 = xstar_fcs_B.delta_t;
  }

  mw_arm_sqrt_f32(((xstar_fcs_DW.TappedDelay2_X[xstar_fcs_B.Sum_mz - 1] *
                    xstar_fcs_DW.TappedDelay2_X[xstar_fcs_B.cff - 1] +
                    xstar_fcs_DW.TappedDelay2_X_c[xstar_fcs_B.i0 - 1] *
                    xstar_fcs_DW.TappedDelay2_X_c[xstar_fcs_B.i1 - 1]) +
                   xstar_fcs_DW.TappedDelay2_X_k[xstar_fcs_B.i2 - 1] *
                   xstar_fcs_DW.TappedDelay2_X_k[xstar_fcs_B.i3 - 1]) +
                  xstar_fcs_DW.TappedDelay2_X_i[xstar_fcs_B.i4 - 1] *
                  xstar_fcs_DW.TappedDelay2_X_i[xstar_fcs_B.i5 - 1],
                  &xstar_fcs_B.Product1_g_b);
  if (xstar_fcs_B.delta_t > xstar_fcs_P.delay_delay_of) {
    xstar_fcs_B.Sum_mz = xstar_fcs_P.delay_delay_of;
  } else if (xstar_fcs_B.delta_t < xstar_fcs_P.Saturation2_LowerSat) {
    xstar_fcs_B.Sum_mz = xstar_fcs_P.Saturation2_LowerSat;
  } else {
    xstar_fcs_B.Sum_mz = xstar_fcs_B.delta_t;
  }

  xstar_fcs_B.DiscreteTimeIntegrator_ee =
    xstar_fcs_DW.TappedDelay2_X[xstar_fcs_B.Sum_mz - 1] /
    xstar_fcs_B.Product1_g_b;
  if (xstar_fcs_B.delta_t > xstar_fcs_P.delay1_delay_of) {
    xstar_fcs_B.Sum_mz = xstar_fcs_P.delay1_delay_of;
  } else if (xstar_fcs_B.delta_t < xstar_fcs_P.Saturation2_LowerSat_e) {
    xstar_fcs_B.Sum_mz = xstar_fcs_P.Saturation2_LowerSat_e;
  } else {
    xstar_fcs_B.Sum_mz = xstar_fcs_B.delta_t;
  }

  xstar_fcs_B.DiscreteTimeIntegrator3_n =
    xstar_fcs_DW.TappedDelay2_X_c[xstar_fcs_B.Sum_mz - 1] /
    xstar_fcs_B.Product1_g_b;
  if (xstar_fcs_B.delta_t > xstar_fcs_P.delay2_delay_of) {
    xstar_fcs_B.Sum_mz = xstar_fcs_P.delay2_delay_of;
  } else if (xstar_fcs_B.delta_t < xstar_fcs_P.Saturation2_LowerSat_n) {
    xstar_fcs_B.Sum_mz = xstar_fcs_P.Saturation2_LowerSat_n;
  } else {
    xstar_fcs_B.Sum_mz = xstar_fcs_B.delta_t;
  }

  xstar_fcs_B.Product3_l = xstar_fcs_DW.TappedDelay2_X_k[xstar_fcs_B.Sum_mz - 1]
    / xstar_fcs_B.Product1_g_b;
  if (xstar_fcs_B.delta_t > xstar_fcs_P.delay3_delay_of) {
    xstar_fcs_B.Sum_mz = xstar_fcs_P.delay3_delay_of;
  } else if (xstar_fcs_B.delta_t < xstar_fcs_P.Saturation2_LowerSat_a) {
    xstar_fcs_B.Sum_mz = xstar_fcs_P.Saturation2_LowerSat_a;
  } else {
    xstar_fcs_B.Sum_mz = xstar_fcs_B.delta_t;
  }

  xstar_fcs_B.Product1_g_b = xstar_fcs_DW.TappedDelay2_X_i[xstar_fcs_B.Sum_mz -
    1] / xstar_fcs_B.Product1_g_b;
  xstar_fcs_B.Sum_i5[0] = ((xstar_fcs_B.DiscreteTimeIntegrator_ee *
    xstar_fcs_B.DiscreteTimeIntegrator_ee +
    xstar_fcs_B.DiscreteTimeIntegrator3_n *
    xstar_fcs_B.DiscreteTimeIntegrator3_n) - xstar_fcs_B.Product3_l *
    xstar_fcs_B.Product3_l) - xstar_fcs_B.Product1_g_b *
    xstar_fcs_B.Product1_g_b;
  xstar_fcs_B.Sum_i5[1] = (xstar_fcs_B.DiscreteTimeIntegrator3_n *
    xstar_fcs_B.Product3_l - xstar_fcs_B.Product1_g_b *
    xstar_fcs_B.DiscreteTimeIntegrator_ee) * xstar_fcs_P.Gain_Gain_a;
  xstar_fcs_B.Sum_i5[2] = (xstar_fcs_B.DiscreteTimeIntegrator_ee *
    xstar_fcs_B.Product3_l + xstar_fcs_B.DiscreteTimeIntegrator3_n *
    xstar_fcs_B.Product1_g_b) * xstar_fcs_P.Gain_Gain_ki;
  xstar_fcs_B.Sum_i5[3] = (xstar_fcs_B.Product1_g_b *
    xstar_fcs_B.DiscreteTimeIntegrator_ee +
    xstar_fcs_B.DiscreteTimeIntegrator3_n * xstar_fcs_B.Product3_l) *
    xstar_fcs_P.Gain_Gain_h;
  xstar_fcs_B.Sum_i5[4] = ((xstar_fcs_B.DiscreteTimeIntegrator_ee *
    xstar_fcs_B.DiscreteTimeIntegrator_ee -
    xstar_fcs_B.DiscreteTimeIntegrator3_n *
    xstar_fcs_B.DiscreteTimeIntegrator3_n) + xstar_fcs_B.Product3_l *
    xstar_fcs_B.Product3_l) - xstar_fcs_B.Product1_g_b *
    xstar_fcs_B.Product1_g_b;
  xstar_fcs_B.Sum_i5[5] = (xstar_fcs_B.Product3_l * xstar_fcs_B.Product1_g_b -
    xstar_fcs_B.DiscreteTimeIntegrator_ee *
    xstar_fcs_B.DiscreteTimeIntegrator3_n) * xstar_fcs_P.Gain_Gain_ar;
  xstar_fcs_B.Sum_i5[6] = (xstar_fcs_B.DiscreteTimeIntegrator3_n *
    xstar_fcs_B.Product1_g_b - xstar_fcs_B.DiscreteTimeIntegrator_ee *
    xstar_fcs_B.Product3_l) * xstar_fcs_P.Gain_Gain_ft;
  xstar_fcs_B.Sum_i5[7] = (xstar_fcs_B.DiscreteTimeIntegrator_ee *
    xstar_fcs_B.DiscreteTimeIntegrator3_n + xstar_fcs_B.Product3_l *
    xstar_fcs_B.Product1_g_b) * xstar_fcs_P.Gain_Gain_ap;
  xstar_fcs_B.Sum_i5[8] = ((xstar_fcs_B.DiscreteTimeIntegrator_ee *
    xstar_fcs_B.DiscreteTimeIntegrator_ee -
    xstar_fcs_B.DiscreteTimeIntegrator3_n *
    xstar_fcs_B.DiscreteTimeIntegrator3_n) - xstar_fcs_B.Product3_l *
    xstar_fcs_B.Product3_l) + xstar_fcs_B.Product1_g_b *
    xstar_fcs_B.Product1_g_b;
  if (xstar_fcs_B.DiscreteTimeIntegrator_d0 > xstar_fcs_DW.DelayInput1_DSTATE_j)
  {
    for (xstar_fcs_B.Sum_mz = 0; xstar_fcs_B.Sum_mz < 9; xstar_fcs_B.Sum_mz++) {
      xstar_fcs_B.In1_d[xstar_fcs_B.Sum_mz] =
        xstar_fcs_B.Sum_i5[xstar_fcs_B.Sum_mz];
    }
  }

  xstar_fcs_B.u0_l = (real32_T)xstar_fcs_P.Gain2_Gain_g * 5.96046448E-8F;
  xstar_fcs_B.sincos_o2[0] = xstar_fcs_B.u0_l * (real32_T)
    xstar_fcs_B.rtb_VectorConcatenate1_c_idx_0;
  xstar_fcs_B.sincos_o2[1] = xstar_fcs_B.u0_l * (real32_T)
    xstar_fcs_B.rtb_VectorConcatenate1_c_idx_1;
  xstar_fcs_B.sincos_o2[2] = xstar_fcs_B.u0_l * (real32_T)
    xstar_fcs_B.rtb_VectorConcatenate1_c_idx_2;
  for (xstar_fcs_B.Sum_mz = 0; xstar_fcs_B.Sum_mz < 3; xstar_fcs_B.Sum_mz++) {
    xstar_fcs_B.mul5[xstar_fcs_B.Sum_mz] = 0.0F;
    xstar_fcs_B.mul5[xstar_fcs_B.Sum_mz] += xstar_fcs_B.In1_d[xstar_fcs_B.Sum_mz]
      * xstar_fcs_B.sincos_o2[0];
    xstar_fcs_B.mul5[xstar_fcs_B.Sum_mz] += xstar_fcs_B.In1_d[xstar_fcs_B.Sum_mz
      + 3] * xstar_fcs_B.sincos_o2[1];
    xstar_fcs_B.mul5[xstar_fcs_B.Sum_mz] += xstar_fcs_B.In1_d[xstar_fcs_B.Sum_mz
      + 6] * xstar_fcs_B.sincos_o2[2];
    xstar_fcs_B.rot_IB_B_radDs[xstar_fcs_B.Sum_mz] =
      xstar_fcs_DW.Memory_97_PreviousInput[xstar_fcs_B.Sum_mz];
  }

  xstar_fcs_B.DiscreteTimeIntegrator3_n = xstar_fcs_B.rot_IB_B_radDs[0] *
    xstar_fcs_P.u80_Coefficients[0];
  xstar_fcs_B.cff = 1;
  xstar_fcs_B.Sum_mz = xstar_fcs_DW.u80_circBuf;
  while (xstar_fcs_B.Sum_mz < 179) {
    xstar_fcs_B.DiscreteTimeIntegrator3_n +=
      xstar_fcs_DW.u80_states[xstar_fcs_B.Sum_mz] *
      xstar_fcs_P.u80_Coefficients[xstar_fcs_B.cff];
    xstar_fcs_B.cff++;
    xstar_fcs_B.Sum_mz++;
  }

  xstar_fcs_B.Sum_mz = 0;
  while (xstar_fcs_B.Sum_mz < xstar_fcs_DW.u80_circBuf) {
    xstar_fcs_B.DiscreteTimeIntegrator3_n +=
      xstar_fcs_DW.u80_states[xstar_fcs_B.Sum_mz] *
      xstar_fcs_P.u80_Coefficients[xstar_fcs_B.cff];
    xstar_fcs_B.cff++;
    xstar_fcs_B.Sum_mz++;
  }

  xstar_fcs_B.TmpSignalConversionAtProduc[0] =
    xstar_fcs_B.DiscreteTimeIntegrator3_n *
    xstar_fcs_B.DiscreteTimeIntegrator3_n;
  xstar_fcs_B.DiscreteTimeIntegrator3_n = xstar_fcs_B.rot_IB_B_radDs[1] *
    xstar_fcs_P.u80_Coefficients[0];
  xstar_fcs_B.cff = 1;
  xstar_fcs_B.Sum_mz = xstar_fcs_DW.u80_circBuf;
  while (xstar_fcs_B.Sum_mz < 179) {
    xstar_fcs_B.DiscreteTimeIntegrator3_n += xstar_fcs_DW.u80_states[179 +
      xstar_fcs_B.Sum_mz] * xstar_fcs_P.u80_Coefficients[xstar_fcs_B.cff];
    xstar_fcs_B.cff++;
    xstar_fcs_B.Sum_mz++;
  }

  xstar_fcs_B.Sum_mz = 0;
  while (xstar_fcs_B.Sum_mz < xstar_fcs_DW.u80_circBuf) {
    xstar_fcs_B.DiscreteTimeIntegrator3_n += xstar_fcs_DW.u80_states[179 +
      xstar_fcs_B.Sum_mz] * xstar_fcs_P.u80_Coefficients[xstar_fcs_B.cff];
    xstar_fcs_B.cff++;
    xstar_fcs_B.Sum_mz++;
  }

  xstar_fcs_B.TmpSignalConversionAtProduc[1] =
    xstar_fcs_B.DiscreteTimeIntegrator3_n *
    xstar_fcs_B.DiscreteTimeIntegrator3_n;
  xstar_fcs_B.DiscreteTimeIntegrator3_n = xstar_fcs_B.rot_IB_B_radDs[2] *
    xstar_fcs_P.u80_Coefficients[0];
  xstar_fcs_B.cff = 1;
  xstar_fcs_B.Sum_mz = xstar_fcs_DW.u80_circBuf;
  while (xstar_fcs_B.Sum_mz < 179) {
    xstar_fcs_B.DiscreteTimeIntegrator3_n += xstar_fcs_DW.u80_states[358 +
      xstar_fcs_B.Sum_mz] * xstar_fcs_P.u80_Coefficients[xstar_fcs_B.cff];
    xstar_fcs_B.cff++;
    xstar_fcs_B.Sum_mz++;
  }

  xstar_fcs_B.Sum_mz = 0;
  while (xstar_fcs_B.Sum_mz < xstar_fcs_DW.u80_circBuf) {
    xstar_fcs_B.DiscreteTimeIntegrator3_n += xstar_fcs_DW.u80_states[358 +
      xstar_fcs_B.Sum_mz] * xstar_fcs_P.u80_Coefficients[xstar_fcs_B.cff];
    xstar_fcs_B.cff++;
    xstar_fcs_B.Sum_mz++;
  }

  xstar_fcs_B.DiscreteTimeIntegrator_ee =
    (xstar_fcs_B.TmpSignalConversionAtProduc[0] +
     xstar_fcs_B.TmpSignalConversionAtProduc[1]) +
    xstar_fcs_B.DiscreteTimeIntegrator3_n *
    xstar_fcs_B.DiscreteTimeIntegrator3_n;
  if (xstar_fcs_B.DiscreteTimeIntegrator_ee > xstar_fcs_P.Saturation2_UpperSat)
  {
    xstar_fcs_B.DiscreteTimeIntegrator_ee = xstar_fcs_P.Saturation2_UpperSat;
  } else {
    if (xstar_fcs_B.DiscreteTimeIntegrator_ee <
        xstar_fcs_P.Saturation2_LowerSat_eg) {
      xstar_fcs_B.DiscreteTimeIntegrator_ee =
        xstar_fcs_P.Saturation2_LowerSat_eg;
    }
  }

  if ((xstar_fcs_B.DiscreteTimeIntegrator_d0 >
       xstar_fcs_DW.DelayInput1_DSTATE_it) &&
      (xstar_fcs_B.rtb_Switch_timestamp_v > xstar_fcs_DW.DelayInput1_DSTATE_lh))
  {
    xstar_fcs_DW.DiscreteTimeIntegrator3_DSTAT_g =
      xstar_fcs_P.DiscreteTimeIntegrator3_IC_f;
  }

  xstar_fcs_B.Compare_gw = (xstar_fcs_DW.DiscreteTimeIntegrator3_DSTAT_g <
    xstar_fcs_P.CompareToConstant7_const_h);
  xstar_fcs_B.Gain2_p = (real32_T)xstar_fcs_P.Gain2_Gain_f * 6.10351563E-5F *
    (real32_T)xstar_fcs_B.FixPtRelationalOperator;
  if (xstar_fcs_DW.DiscreteTimeIntegrator1_DSTAT_b >
      xstar_fcs_P.Switch1_Threshold) {
    xstar_fcs_B.Switch1 = xstar_fcs_P.Constant_Value_g;
  } else {
    xstar_fcs_B.Switch1 = xstar_fcs_P.Constant1_Value_bm;
  }

  xstar_fcs_B.Compare_ot = (xstar_fcs_B.Gain2_p >=
    xstar_fcs_P.CompareToConstant10_const);
  if (xstar_fcs_DW.DiscreteTimeIntegrator1_IC_LO_e != 0) {
    xstar_fcs_DW.DiscreteTimeIntegrator1_DSTAT_h = (real32_T)
      (xstar_fcs_B.Compare_gw && (xstar_fcs_B.Gain2_p >=
        xstar_fcs_P.CompareToConstant10_const));
  }

  xstar_fcs_B.DiscreteTimeIntegrator3_n =
    xstar_fcs_DW.DiscreteTimeIntegrator1_DSTAT_h;
  if (xstar_fcs_B.Switch1 == xstar_fcs_P.CompareToConstant9_const_e) {
    xstar_fcs_B.Switch_i = (xstar_fcs_B.Compare_gw && (xstar_fcs_B.Gain2_p >=
      xstar_fcs_P.CompareToConstant_const_o));
  } else {
    xstar_fcs_B.Switch_i = (xstar_fcs_DW.DiscreteTimeIntegrator1_DSTAT_h >
      xstar_fcs_P.CompareToConstant8_const_kb);
  }

  xstar_fcs_B.Saturation7 = (uint16_T)((uint32_T)xstar_fcs_P.Gain3_Gain_f *
    xstar_fcs_B.FixPtRelationalOperator);
  if (xstar_fcs_B.Saturation7 > xstar_fcs_P.Saturation7_UpperSat) {
    xstar_fcs_B.Saturation7 = xstar_fcs_P.Saturation7_UpperSat;
  } else {
    if (xstar_fcs_B.Saturation7 < xstar_fcs_P.Saturation7_LowerSat) {
      xstar_fcs_B.Saturation7 = xstar_fcs_P.Saturation7_LowerSat;
    }
  }

  xstar_fcs_B.u0_l = (xstar_fcs_P.Constant2_Value_c -
                      xstar_fcs_B.DiscreteTimeIntegrator_ee) *
    xstar_fcs_P.Gain1_Gain_mp;
  if (xstar_fcs_B.u0_l > xstar_fcs_P.Saturation5_UpperSat) {
    xstar_fcs_B.u0_l = xstar_fcs_P.Saturation5_UpperSat;
  } else {
    if (xstar_fcs_B.u0_l < xstar_fcs_P.Saturation5_LowerSat) {
      xstar_fcs_B.u0_l = xstar_fcs_P.Saturation5_LowerSat;
    }
  }

  xstar_fcs_B.u0_l = xstar_fcs_B.u0_l * xstar_fcs_P.Constant2_Value_e *
    (real32_T)xstar_fcs_B.Switch_i * ((real32_T)xstar_fcs_B.Saturation7 *
    6.10351563E-5F);
  if (xstar_fcs_B.u0_l > xstar_fcs_P.Saturation1_UpperSat_m) {
    xstar_fcs_B.Vision_quality = xstar_fcs_P.Saturation1_UpperSat_m;
  } else if (xstar_fcs_B.u0_l < xstar_fcs_P.Saturation1_LowerSat_k) {
    xstar_fcs_B.Vision_quality = xstar_fcs_P.Saturation1_LowerSat_k;
  } else {
    xstar_fcs_B.Vision_quality = xstar_fcs_B.u0_l;
  }

  xstar_fcs_B.h_AGL_m_l = xstar_fcs_DW.Delay_118_DSTATE;
  xstar_fcs_B.LogicalOperator_f = ((xstar_fcs_B.Switch1_l !=
    xstar_fcs_DW.DelayInput1_DSTATE_kct) || (xstar_fcs_B.Switch2 !=
    xstar_fcs_DW.DelayInput1_DSTATE_gg));
  if (xstar_fcs_B.LogicalOperator_f ||
      (xstar_fcs_DW.DiscreteTimeIntegrator_PrevRe_p != 0)) {
    xstar_fcs_DW.DiscreteTimeIntegrator_DSTATE_n =
      xstar_fcs_P.DiscreteTimeIntegrator_IC_e;
  }

  xstar_fcs_B.DataTypeConversion1_n = ((int32_T)((uint32_T)
    (xstar_fcs_DW.Delay_DSTATE_hm &&
     (!(xstar_fcs_DW.DiscreteTimeIntegrator_DSTATE_n >=
        xstar_fcs_P.CompareTo1sec_const_k))) + xstar_fcs_B.LogicalOperator_f) !=
    0);
  xstar_fcs_B.Delay1_d = xstar_fcs_DW.Delay1_DSTATE_g;
  xstar_fcs_B.Delay2[0] = xstar_fcs_DW.Delay2_DSTATE[0];
  xstar_fcs_B.Delay2[1] = xstar_fcs_DW.Delay2_DSTATE[1];
  xstar_fcs_B.Delay2[2] = xstar_fcs_DW.Delay2_DSTATE[2];
  xstar_fcs_B.Delay10 = xstar_fcs_DW.Delay10_DSTATE;
  Rotation_AHRS_GPS(&xstar_fcs_B.h_dot_mDs, &xstar_fcs_B.rot_IB_B_raw_radDs[0],
                    &xstar_fcs_B.sfor_R_B_mDs2[0], &xstar_fcs_B.IMU_valid,
                    &xstar_fcs_B.Product2[0], &xstar_fcs_B.Product4_m,
                    &xstar_fcs_B.DiscreteTimeIntegrator1, &xstar_fcs_B.Product1
                    [0], &xstar_fcs_B.Product1[1], &xstar_fcs_B.Gain,
                    &xstar_fcs_B.ant_heading, &xstar_fcs_B.LogicalOperator,
                    &xstar_fcs_B.Timestamp_ms_hd, &xstar_fcs_B.Switch1_a,
                    &xstar_fcs_B.h_grd_sonar, &xstar_fcs_B.mul5[0],
                    &xstar_fcs_B.Vision_quality, &xstar_fcs_B.mul5[2],
                    &xstar_fcs_B.Switch1, &xstar_fcs_P.Constant_Value_jr,
                    &xstar_fcs_P.Constant1_Value_k,
                    &xstar_fcs_P.Constant4_Value_d, &xstar_fcs_B.h_AGL_m_l,
                    &xstar_fcs_P.Constant1_Value_m, &xstar_fcs_B.Armed_p,
                    &xstar_fcs_B.DataTypeConversion1_n, &xstar_fcs_B.Delay1_d,
                    &xstar_fcs_B.Delay2[0], &xstar_fcs_B.Delay10,
                    &xstar_fcs_B.vel_O_O[0], &xstar_fcs_B.ATT_quat_OB[0],
                    &xstar_fcs_B.M_OB_g[0], &xstar_fcs_B.att_Oz_B[0],
                    &xstar_fcs_B.rot_IB_B_radDs_c[0],
                    &xstar_fcs_B.sfor_R_B_mDs2_c[0], &xstar_fcs_B.yaw_mag,
                    &xstar_fcs_B.Psi_dot_IMU, &xstar_fcs_B.M_OObar[0],
                    &xstar_fcs_B.Psi_star_rad, &xstar_fcs_B.phi_rad,
                    &xstar_fcs_B.sin_phi, &xstar_fcs_B.cos_phi,
                    &xstar_fcs_B.theta_rad, &xstar_fcs_B.sin_theta,
                    &xstar_fcs_B.cos_theta, &xstar_fcs_B.Heading_Quality,
                    &xstar_fcs_B.Mag_Quality, &xstar_fcs_B.Bias_gyro_radDs[0],
                    &xstar_fcs_B.standstill, &xstar_fcs_B.reset_Yaw,
                    &xstar_fcs_B.All_reset_Yaw_flag, &xstar_fcs_B.rp_init_reset,
                    &xstar_fcs_B.heading_init,
                    &xstar_fcs_B.Rotation_AHRS_GPS_o25,
                    &xstar_fcs_B.Rotation_AHRS_GPS_o26,
                    &xstar_fcs_B.Rotation_AHRS_GPS_o27,
                    &xstar_fcs_B.Rotation_AHRS_GPS_o28,
                    &xstar_fcs_B.Rotation_AHRS_GPS_o29, &xstar_fcs_B.yaw_mag_p,
                    &xstar_fcs_B.Rotation_AHRS_GPS_o31,
                    &xstar_fcs_B.Rotation_AHRS_GPS_o32[0],
                    &xstar_fcs_B.Rotation_AHRS_GPS_o33);
  xstar_fcs_B.Compare_dq = ((xstar_fcs_P.delta_Height_pressure_min <
    xstar_fcs_U.sensors.MS5611.Pressure_Pa) &&
    (xstar_fcs_U.sensors.MS5611.Pressure_Pa <
     xstar_fcs_P.delta_Height_pressure_max) &&
    ((xstar_fcs_P.delta_Height_temp_min <
      xstar_fcs_U.sensors.MS5611.Temperature_deg) &&
     (xstar_fcs_U.sensors.MS5611.Temperature_deg <
      xstar_fcs_P.delta_Height_temp_max)));
  xstar_fcs_B.DiscreteTimeIntegrator_ee =
    xstar_fcs_U.sensors.MS5611.Timestamp_ms;
  xstar_fcs_B.Switch_l = (xstar_fcs_U.sensors.MS5611.Timestamp_ms !=
    xstar_fcs_DW.DelayInput1_DSTATE_jl);
  xstar_fcs_B.Sum_mz = (((xstar_fcs_B.Compare_dq && xstar_fcs_B.Switch_l) ||
    (xstar_fcs_DW.Memory2_PreviousInput > xstar_fcs_P.Constant_Value_kd)) &&
                        (xstar_fcs_DW.Memory2_PreviousInput <
    xstar_fcs_P.CompareToConstant_const_ep));
  xstar_fcs_B.qY_d = xstar_fcs_B.Sum_mz + xstar_fcs_DW.Memory2_PreviousInput;
  if (xstar_fcs_B.qY_d < (uint32_T)xstar_fcs_B.Sum_mz) {
    xstar_fcs_B.qY_d = MAX_uint32_T;
  }

  xstar_fcs_B.LogicalOperator3_f = ((xstar_fcs_B.qY_d >=
    xstar_fcs_P.delta_Height_s_first) && (xstar_fcs_B.qY_d <=
    xstar_fcs_P.delta_Height_s_last));
  if (xstar_fcs_B.Switch_l) {
    xstar_fcs_DW.DiscreteTimeIntegrator_DSTAT_fh =
      xstar_fcs_P.DiscreteTimeIntegrator_IC_pv;
  }

  xstar_fcs_B.LogicalOperator4 = ((xstar_fcs_B.qY_d >
    xstar_fcs_P.delta_Height_s_last) &&
    (xstar_fcs_DW.DiscreteTimeIntegrator_DSTAT_fh <
     xstar_fcs_P.CompareToConstant4_const_e) && xstar_fcs_B.Compare_dq);
  if (xstar_fcs_B.LogicalOperator3_f) {
    if (!xstar_fcs_DW.Reference_and_Gradient_MODE) {
      xstar_fcs_DW.Memory_PreviousInput = xstar_fcs_P.Memory_InitialCondition_i;
      xstar_fcs_DW.Memory2_PreviousInput_c =
        xstar_fcs_P.Memory2_InitialCondition;
      xstar_fcs_DW.Memory1_PreviousInput_i =
        xstar_fcs_P.Memory1_InitialCondition;
      xstar_fcs_DW.Reference_and_Gradient_MODE = true;
    }

    xstar_fcs_B.Gain2_p = xstar_fcs_U.sensors.MS5611.Pressure_Pa +
      xstar_fcs_DW.Memory_PreviousInput;
    xstar_fcs_B.qY = xstar_fcs_P.Constant1_Value_n +
      xstar_fcs_DW.Memory2_PreviousInput_c;
    if (xstar_fcs_B.qY < xstar_fcs_P.Constant1_Value_n) {
      xstar_fcs_B.qY = MAX_uint32_T;
    }

    if (xstar_fcs_B.qY > xstar_fcs_P.Saturation1_UpperSat_o) {
      xstar_fcs_B.DiscreteTimeIntegrator_h3 = xstar_fcs_P.Saturation1_UpperSat_o;
    } else if (xstar_fcs_B.qY < xstar_fcs_P.Saturation1_LowerSat_o) {
      xstar_fcs_B.DiscreteTimeIntegrator_h3 = xstar_fcs_P.Saturation1_LowerSat_o;
    } else {
      xstar_fcs_B.DiscreteTimeIntegrator_h3 = xstar_fcs_B.qY;
    }

    xstar_fcs_B.Divide = xstar_fcs_B.Gain2_p / (real32_T)
      xstar_fcs_B.DiscreteTimeIntegrator_h3;
    xstar_fcs_B.sample_sum_a = (xstar_fcs_P.Constant2_Value_m +
      xstar_fcs_U.sensors.MS5611.Temperature_deg) +
      xstar_fcs_DW.Memory1_PreviousInput_i;
    if (xstar_fcs_B.Divide > xstar_fcs_P.Saturation_UpperSat_g) {
      xstar_fcs_B.rtb_Mag_Q_idx_0 = xstar_fcs_P.Saturation_UpperSat_g;
    } else if (xstar_fcs_B.Divide < xstar_fcs_P.Saturation_LowerSat_l) {
      xstar_fcs_B.rtb_Mag_Q_idx_0 = xstar_fcs_P.Saturation_LowerSat_l;
    } else {
      xstar_fcs_B.rtb_Mag_Q_idx_0 = xstar_fcs_B.Divide;
    }

    xstar_fcs_B.g_M_d_R = xstar_fcs_B.sample_sum_a / (real32_T)
      xstar_fcs_B.DiscreteTimeIntegrator_h3 / xstar_fcs_B.rtb_Mag_Q_idx_0 *
      xstar_fcs_P.g_M_d_R_Gain;
    xstar_fcs_DW.Memory_PreviousInput = xstar_fcs_B.Gain2_p;
    xstar_fcs_DW.Memory2_PreviousInput_c = xstar_fcs_B.qY;
    xstar_fcs_DW.Memory1_PreviousInput_i = xstar_fcs_B.sample_sum_a;
  } else {
    if (xstar_fcs_DW.Reference_and_Gradient_MODE) {
      xstar_fcs_DW.Reference_and_Gradient_MODE = false;
    }
  }

  if (xstar_fcs_B.LogicalOperator3_f || (!xstar_fcs_B.LogicalOperator4)) {
    xstar_fcs_B.u0_l = xstar_fcs_U.sensors.MS5611.Pressure_Pa;
  } else {
    xstar_fcs_B.u0_l = xstar_fcs_B.Divide;
  }

  xstar_fcs_B.Product1_g = (xstar_fcs_U.sensors.MS5611.Pressure_Pa -
    xstar_fcs_B.u0_l) * xstar_fcs_B.g_M_d_R;
  xstar_fcs_B.baro_Timestamp_ms = xstar_fcs_P.Gain_Gain_apa *
    xstar_fcs_U.sensors.MS5611.Timestamp_ms;
  if (xstar_fcs_U.sensors.RTK_Base.Timestamp_ms_pos !=
      xstar_fcs_DW.DelayInput1_DSTATE_h) {
    xstar_fcs_DW.DiscreteTimeIntegrator_DSTAT_ng =
      xstar_fcs_P.DiscreteTimeIntegrator_IC_iz;
  }

  xstar_fcs_B.rtb_Mag_Q_idx_0 = xstar_fcs_U.sensors.RTK_Base.lat_stddev;
  xstar_fcs_B.Add_n = xstar_fcs_U.sensors.RTK_Base.lon_stddev;
  mw_arm_sqrt_f32(xstar_fcs_U.sensors.RTK_Base.lat_stddev *
                  xstar_fcs_U.sensors.RTK_Base.lat_stddev +
                  xstar_fcs_U.sensors.RTK_Base.lon_stddev *
                  xstar_fcs_U.sensors.RTK_Base.lon_stddev,
                  &xstar_fcs_B.Product3_l);
  xstar_fcs_B.u0_l = (xstar_fcs_P.Constant1_Value_f - xstar_fcs_B.Product3_l) *
    xstar_fcs_P.Gain2_Gain_op;
  if (xstar_fcs_B.u0_l > xstar_fcs_P.Saturation1_UpperSat_k) {
    xstar_fcs_B.u0_l = xstar_fcs_P.Saturation1_UpperSat_k;
  } else {
    if (xstar_fcs_B.u0_l < xstar_fcs_P.Saturation1_LowerSat_e) {
      xstar_fcs_B.u0_l = xstar_fcs_P.Saturation1_LowerSat_e;
    }
  }

  xstar_fcs_B.Double1 = (real32_T)(xstar_fcs_DW.DiscreteTimeIntegrator_DSTAT_ng <
    xstar_fcs_P.CompareToConstant4_const_j) * xstar_fcs_B.u0_l * (real32_T)
    (xstar_fcs_B.Product2_mi > xstar_fcs_P.CompareToConstant2_const_g);
  xstar_fcs_B.Status = xstar_fcs_P.Gain8_Gain * xstar_fcs_B.Product2_mi;
  xstar_fcs_B.Timestamp_ms = xstar_fcs_P.Scalefactor6_Gain *
    xstar_fcs_U.sensors.RTK_Base.Timestamp_ms_pos;
  xstar_fcs_B.GpsHeight = (real32_T)xstar_fcs_U.sensors.RTK_Base.hgt;
  xstar_fcs_B.Compare_dq = ((!xstar_fcs_DW.UnitDelay_1_DSTATE) &&
    (xstar_fcs_DW.UnitDelay_3_DSTATE >= xstar_fcs_P.CompareToConstant9_const));
  if (xstar_fcs_B.Compare_dq) {
    xstar_fcs_B.Switch_l = (xstar_fcs_U.sensors.RTK.RTKP.pos_type >=
      xstar_fcs_P.CompareToConstant1_const_k);
  } else {
    xstar_fcs_B.Switch_l = (xstar_fcs_U.sensors.RTK.RTKP.pos_type >=
      xstar_fcs_P.CompareToConstant2_const_h);
  }

  xstar_fcs_B.qY = (uint32_T)xstar_fcs_U.sensors.RTK.RTKP.timestamp_ms;
  if (xstar_fcs_B.qY != xstar_fcs_DW.DelayInput1_DSTATE_g) {
    xstar_fcs_DW.DiscreteTimeIntegrator_DSTAT_fw =
      xstar_fcs_P.DiscreteTimeIntegrator_IC_gq;
  }

  if (xstar_fcs_B.Compare_dq) {
    xstar_fcs_B.Compare_dq = (xstar_fcs_U.sensors.RTK.RTKV.vel_type >=
      xstar_fcs_P.CompareToConstant1_const_g);
  } else {
    xstar_fcs_B.Compare_dq = (xstar_fcs_U.sensors.RTK.RTKV.vel_type >=
      xstar_fcs_P.CompareToConstant2_const_j);
  }

  xstar_fcs_B.Cast1 = (uint32_T)xstar_fcs_U.sensors.RTK.RTKV.timestamp_ms;
  if (xstar_fcs_B.Cast1 != xstar_fcs_DW.DelayInput1_DSTATE_p) {
    xstar_fcs_DW.DiscreteTimeIntegrator1_DSTA_hf =
      xstar_fcs_P.DiscreteTimeIntegrator1_IC_k;
  }

  xstar_fcs_B.Cast2 = (uint32_T)xstar_fcs_U.sensors.RTK.RTKH.timestamp_ms;
  if (xstar_fcs_B.Cast2 != xstar_fcs_DW.DelayInput1_DSTATE_mh) {
    xstar_fcs_DW.DiscreteTimeIntegrator2_DSTA_hw =
      xstar_fcs_P.DiscreteTimeIntegrator2_IC_gc;
  }

  xstar_fcs_B.Sum = (uint8_T)(((uint32_T)(xstar_fcs_B.Switch_l &&
    (xstar_fcs_U.sensors.RTK.RTKP.sol_status ==
     xstar_fcs_P.CompareToConstant_const_l) &&
    (xstar_fcs_DW.DiscreteTimeIntegrator_DSTAT_fw <
     xstar_fcs_P.CompareToConstant4_const_i) ? (int32_T)((uint32_T)
    xstar_fcs_P.Gain_Gain_e4 >> 7) : 0) + (xstar_fcs_B.Compare_dq &&
    (xstar_fcs_U.sensors.RTK.RTKV.sol_status ==
     xstar_fcs_P.CompareToConstant_const_m) &&
    (xstar_fcs_DW.DiscreteTimeIntegrator1_DSTA_hf <
     xstar_fcs_P.CompareToConstant5_const_b) ? (int32_T)((uint32_T)
    xstar_fcs_P.Gain1_Gain_ga >> 6) : 0)) + ((xstar_fcs_U.sensors.RTK.RTKH.pos_t
    >= xstar_fcs_P.CompareToConstant1_const_ge) &&
    (xstar_fcs_U.sensors.RTK.RTKH.sol_s ==
     xstar_fcs_P.CompareToConstant_const_ai) &&
    (xstar_fcs_DW.DiscreteTimeIntegrator2_DSTA_hw <
     xstar_fcs_P.CompareToConstant8_const_p) ? (int32_T)((uint32_T)
    xstar_fcs_P.Gain2_Gain_lg >> 5) : 0));
  xstar_fcs_B.LogicalOperator3_b = ((xstar_fcs_B.Sum &
    xstar_fcs_P.BitwiseAND_BitMask_e) > xstar_fcs_P.Constant_Value_en);
  xstar_fcs_B.Switch_l = !xstar_fcs_B.LogicalOperator3_b;
  xstar_fcs_B.u0_l = (xstar_fcs_P.Constant_Value_e[0] -
                      xstar_fcs_U.sensors.RTK.RTKP.lat_sigma) *
    xstar_fcs_P.Gain_Gain_o;
  if (xstar_fcs_B.u0_l > xstar_fcs_P.Saturation_UpperSat_de) {
    xstar_fcs_B.u0_l = xstar_fcs_P.Saturation_UpperSat_de;
  } else {
    if (xstar_fcs_B.u0_l < xstar_fcs_P.Saturation_LowerSat_p) {
      xstar_fcs_B.u0_l = xstar_fcs_P.Saturation_LowerSat_p;
    }
  }

  xstar_fcs_B.u0 = (xstar_fcs_P.Constant_Value_e[1] -
                    xstar_fcs_U.sensors.RTK.RTKP.lon_sigma) *
    xstar_fcs_P.Gain_Gain_o;
  if (xstar_fcs_B.u0 > xstar_fcs_P.Saturation_UpperSat_de) {
    xstar_fcs_B.u0 = xstar_fcs_P.Saturation_UpperSat_de;
  } else {
    if (xstar_fcs_B.u0 < xstar_fcs_P.Saturation_LowerSat_p) {
      xstar_fcs_B.u0 = xstar_fcs_P.Saturation_LowerSat_p;
    }
  }

  xstar_fcs_B.u0_p = (xstar_fcs_P.Constant_Value_e[2] -
                      xstar_fcs_U.sensors.RTK.RTKP.hgt_sigma) *
    xstar_fcs_P.Gain_Gain_o;
  if (xstar_fcs_B.u0_p > xstar_fcs_P.Saturation_UpperSat_de) {
    xstar_fcs_B.u0_p = xstar_fcs_P.Saturation_UpperSat_de;
  } else {
    if (xstar_fcs_B.u0_p < xstar_fcs_P.Saturation_LowerSat_p) {
      xstar_fcs_B.u0_p = xstar_fcs_P.Saturation_LowerSat_p;
    }
  }

  if (xstar_fcs_DW.DiscreteTimeIntegrator5_IC_LO_f != 0) {
    xstar_fcs_DW.DiscreteTimeIntegrator5_DSTAT_g[0] = xstar_fcs_B.u0_l;
    xstar_fcs_DW.DiscreteTimeIntegrator5_DSTAT_g[1] = xstar_fcs_B.u0;
    xstar_fcs_DW.DiscreteTimeIntegrator5_DSTAT_g[2] = xstar_fcs_B.u0_p;
  }

  if (xstar_fcs_B.Switch_l || (xstar_fcs_DW.DiscreteTimeIntegrator5_PrevR_h != 0))
  {
    xstar_fcs_DW.DiscreteTimeIntegrator5_DSTAT_g[0] = xstar_fcs_B.u0_l;
    xstar_fcs_DW.DiscreteTimeIntegrator5_DSTAT_g[1] = xstar_fcs_B.u0;
    xstar_fcs_DW.DiscreteTimeIntegrator5_DSTAT_g[2] = xstar_fcs_B.u0_p;
  }

  xstar_fcs_B.rtb_DiscreteTimeIntegrator5_bi_ =
    xstar_fcs_DW.DiscreteTimeIntegrator5_DSTAT_g[0];
  xstar_fcs_B.DiscreteTimeIntegrator1_i =
    xstar_fcs_DW.DiscreteTimeIntegrator5_DSTAT_g[0] * (real32_T)
    xstar_fcs_B.LogicalOperator3_b;
  if (xstar_fcs_B.DiscreteTimeIntegrator1_i > xstar_fcs_P.Saturation1_UpperSat_e)
  {
    xstar_fcs_B.Saturation1[0] = xstar_fcs_P.Saturation1_UpperSat_e;
  } else if (xstar_fcs_B.DiscreteTimeIntegrator1_i <
             xstar_fcs_P.Saturation1_LowerSat_n) {
    xstar_fcs_B.Saturation1[0] = xstar_fcs_P.Saturation1_LowerSat_n;
  } else {
    xstar_fcs_B.Saturation1[0] = xstar_fcs_B.DiscreteTimeIntegrator1_i;
  }

  xstar_fcs_B.rtb_DiscreteTimeIntegrator5_b_f =
    xstar_fcs_DW.DiscreteTimeIntegrator5_DSTAT_g[1];
  xstar_fcs_B.DiscreteTimeIntegrator1_i =
    xstar_fcs_DW.DiscreteTimeIntegrator5_DSTAT_g[1] * (real32_T)
    xstar_fcs_B.LogicalOperator3_b;
  if (xstar_fcs_B.DiscreteTimeIntegrator1_i > xstar_fcs_P.Saturation1_UpperSat_e)
  {
    xstar_fcs_B.Saturation1[1] = xstar_fcs_P.Saturation1_UpperSat_e;
  } else if (xstar_fcs_B.DiscreteTimeIntegrator1_i <
             xstar_fcs_P.Saturation1_LowerSat_n) {
    xstar_fcs_B.Saturation1[1] = xstar_fcs_P.Saturation1_LowerSat_n;
  } else {
    xstar_fcs_B.Saturation1[1] = xstar_fcs_B.DiscreteTimeIntegrator1_i;
  }

  xstar_fcs_B.rtb_DiscreteTimeIntegrator5_b_g =
    xstar_fcs_DW.DiscreteTimeIntegrator5_DSTAT_g[2];
  xstar_fcs_B.DiscreteTimeIntegrator1_i =
    xstar_fcs_DW.DiscreteTimeIntegrator5_DSTAT_g[2] * (real32_T)
    xstar_fcs_B.LogicalOperator3_b;
  if (xstar_fcs_B.DiscreteTimeIntegrator1_i > xstar_fcs_P.Saturation1_UpperSat_e)
  {
    xstar_fcs_B.Saturation1[2] = xstar_fcs_P.Saturation1_UpperSat_e;
  } else if (xstar_fcs_B.DiscreteTimeIntegrator1_i <
             xstar_fcs_P.Saturation1_LowerSat_n) {
    xstar_fcs_B.Saturation1[2] = xstar_fcs_P.Saturation1_LowerSat_n;
  } else {
    xstar_fcs_B.Saturation1[2] = xstar_fcs_B.DiscreteTimeIntegrator1_i;
  }

  xstar_fcs_B.LogicalOperator3_b = ((xstar_fcs_B.Sum &
    xstar_fcs_P.BitwiseAND2_BitMask) > xstar_fcs_P.Constant_Value_ej);
  xstar_fcs_B.Compare_dq = !xstar_fcs_B.LogicalOperator3_b;
  xstar_fcs_B.DiscreteTimeIntegrator_h3 = (xstar_fcs_U.sensors.RTK.RTKV.vel_std
    & xstar_fcs_P.BitwiseAND_BitMask) >> 16;
  xstar_fcs_B.Product2_mi = (real32_T)xstar_fcs_P.Gain_Gain_do * 3.63797881E-12F;
  xstar_fcs_B.rtb_Saturation_j_idx_0 = (xstar_fcs_P.Constant_Value_d0[0] -
    xstar_fcs_B.Product2_mi * (real32_T)xstar_fcs_B.DiscreteTimeIntegrator_h3) *
    xstar_fcs_P.Gain1_Gain_k4;
  if (xstar_fcs_B.rtb_Saturation_j_idx_0 > xstar_fcs_P.Saturation_UpperSat_p) {
    xstar_fcs_B.rtb_Saturation_j_idx_0 = xstar_fcs_P.Saturation_UpperSat_p;
  } else {
    if (xstar_fcs_B.rtb_Saturation_j_idx_0 < xstar_fcs_P.Saturation_LowerSat_n)
    {
      xstar_fcs_B.rtb_Saturation_j_idx_0 = xstar_fcs_P.Saturation_LowerSat_n;
    }
  }

  xstar_fcs_B.rtb_Saturation_j_idx_1 = (xstar_fcs_P.Constant_Value_d0[1] -
    xstar_fcs_B.Product2_mi * (real32_T)xstar_fcs_B.DiscreteTimeIntegrator_h3) *
    xstar_fcs_P.Gain1_Gain_k4;
  if (xstar_fcs_B.rtb_Saturation_j_idx_1 > xstar_fcs_P.Saturation_UpperSat_p) {
    xstar_fcs_B.rtb_Saturation_j_idx_1 = xstar_fcs_P.Saturation_UpperSat_p;
  } else {
    if (xstar_fcs_B.rtb_Saturation_j_idx_1 < xstar_fcs_P.Saturation_LowerSat_n)
    {
      xstar_fcs_B.rtb_Saturation_j_idx_1 = xstar_fcs_P.Saturation_LowerSat_n;
    }
  }

  xstar_fcs_B.rtb_Saturation_j_idx_2 = (xstar_fcs_P.Constant_Value_d0[2] -
    xstar_fcs_B.Product2_mi * (real32_T)(xstar_fcs_U.sensors.RTK.RTKV.vel_std &
    xstar_fcs_P.BitwiseAND1_BitMask)) * xstar_fcs_P.Gain1_Gain_k4;
  if (xstar_fcs_B.rtb_Saturation_j_idx_2 > xstar_fcs_P.Saturation_UpperSat_p) {
    xstar_fcs_B.rtb_Saturation_j_idx_2 = xstar_fcs_P.Saturation_UpperSat_p;
  } else {
    if (xstar_fcs_B.rtb_Saturation_j_idx_2 < xstar_fcs_P.Saturation_LowerSat_n)
    {
      xstar_fcs_B.rtb_Saturation_j_idx_2 = xstar_fcs_P.Saturation_LowerSat_n;
    }
  }

  if (xstar_fcs_DW.DiscreteTimeIntegrator5_IC_L_bz != 0) {
    xstar_fcs_DW.DiscreteTimeIntegrator5_DSTAT_d[0] =
      xstar_fcs_B.rtb_Saturation_j_idx_0;
    xstar_fcs_DW.DiscreteTimeIntegrator5_DSTAT_d[1] =
      xstar_fcs_B.rtb_Saturation_j_idx_1;
    xstar_fcs_DW.DiscreteTimeIntegrator5_DSTAT_d[2] =
      xstar_fcs_B.rtb_Saturation_j_idx_2;
  }

  if (xstar_fcs_B.Compare_dq || (xstar_fcs_DW.DiscreteTimeIntegrator5_PrevR_m !=
       0)) {
    xstar_fcs_DW.DiscreteTimeIntegrator5_DSTAT_d[0] =
      xstar_fcs_B.rtb_Saturation_j_idx_0;
    xstar_fcs_DW.DiscreteTimeIntegrator5_DSTAT_d[1] =
      xstar_fcs_B.rtb_Saturation_j_idx_1;
    xstar_fcs_DW.DiscreteTimeIntegrator5_DSTAT_d[2] =
      xstar_fcs_B.rtb_Saturation_j_idx_2;
  }

  xstar_fcs_B.rtb_DiscreteTimeIntegrator5_j_i =
    xstar_fcs_DW.DiscreteTimeIntegrator5_DSTAT_d[0];
  xstar_fcs_B.DiscreteTimeIntegrator1_i =
    xstar_fcs_DW.DiscreteTimeIntegrator5_DSTAT_d[0] * (real32_T)
    xstar_fcs_B.LogicalOperator3_b;
  if (xstar_fcs_B.DiscreteTimeIntegrator1_i > xstar_fcs_P.Saturation1_UpperSat_h)
  {
    xstar_fcs_B.Saturation1_d[0] = xstar_fcs_P.Saturation1_UpperSat_h;
  } else if (xstar_fcs_B.DiscreteTimeIntegrator1_i <
             xstar_fcs_P.Saturation1_LowerSat_km) {
    xstar_fcs_B.Saturation1_d[0] = xstar_fcs_P.Saturation1_LowerSat_km;
  } else {
    xstar_fcs_B.Saturation1_d[0] = xstar_fcs_B.DiscreteTimeIntegrator1_i;
  }

  xstar_fcs_B.rtb_DiscreteTimeIntegrator5_j_m =
    xstar_fcs_DW.DiscreteTimeIntegrator5_DSTAT_d[1];
  xstar_fcs_B.DiscreteTimeIntegrator1_i =
    xstar_fcs_DW.DiscreteTimeIntegrator5_DSTAT_d[1] * (real32_T)
    xstar_fcs_B.LogicalOperator3_b;
  if (xstar_fcs_B.DiscreteTimeIntegrator1_i > xstar_fcs_P.Saturation1_UpperSat_h)
  {
    xstar_fcs_B.Saturation1_d[1] = xstar_fcs_P.Saturation1_UpperSat_h;
  } else if (xstar_fcs_B.DiscreteTimeIntegrator1_i <
             xstar_fcs_P.Saturation1_LowerSat_km) {
    xstar_fcs_B.Saturation1_d[1] = xstar_fcs_P.Saturation1_LowerSat_km;
  } else {
    xstar_fcs_B.Saturation1_d[1] = xstar_fcs_B.DiscreteTimeIntegrator1_i;
  }

  xstar_fcs_B.rtb_DiscreteTimeIntegrator5_j_n =
    xstar_fcs_DW.DiscreteTimeIntegrator5_DSTAT_d[2];
  xstar_fcs_B.DiscreteTimeIntegrator1_i =
    xstar_fcs_DW.DiscreteTimeIntegrator5_DSTAT_d[2] * (real32_T)
    xstar_fcs_B.LogicalOperator3_b;
  if (xstar_fcs_B.DiscreteTimeIntegrator1_i > xstar_fcs_P.Saturation1_UpperSat_h)
  {
    xstar_fcs_B.Saturation1_d[2] = xstar_fcs_P.Saturation1_UpperSat_h;
  } else if (xstar_fcs_B.DiscreteTimeIntegrator1_i <
             xstar_fcs_P.Saturation1_LowerSat_km) {
    xstar_fcs_B.Saturation1_d[2] = xstar_fcs_P.Saturation1_LowerSat_km;
  } else {
    xstar_fcs_B.Saturation1_d[2] = xstar_fcs_B.DiscreteTimeIntegrator1_i;
  }

  xstar_fcs_B.pos_type = xstar_fcs_U.sensors.RTK.RTKP.pos_type;
  xstar_fcs_B.mue_rad_i = xstar_fcs_P.Scalefactor1_Gain_l *
    xstar_fcs_U.sensors.RTK.RTKP.lat;
  xstar_fcs_B.Add = xstar_fcs_U.sensors.RTK.RTKP.hgt +
    xstar_fcs_U.sensors.RTK.RTKP.undulation;
  xstar_fcs_B.Pos_valid = (uint8_T)(xstar_fcs_B.Sum &
    xstar_fcs_P.BitwiseAND_BitMask_p);
  if ((xstar_fcs_B.Pos_valid > 0) &&
      (xstar_fcs_PrevZCX.WGS_Linearization_Trig_ZCE != POS_ZCSIG)) {
    xstar_fcs_B.dz_dh = xstar_fcs_P.constant1_Value;
    xstar_fcs_B.rtb_TmpSignalConversionAtSFun_k = cos(xstar_fcs_B.mue_rad_i);
    xstar_fcs_B.Sum2 = (xstar_fcs_P.constant_Value_l - xstar_fcs_P.f_Value_g) *
      xstar_fcs_P.f_Value_g;
    xstar_fcs_B.Subtract2_b = xstar_fcs_P.constant2_Value_e -
      xstar_fcs_B.rtb_TmpSignalConversionAtSFun_k *
      xstar_fcs_B.rtb_TmpSignalConversionAtSFun_k * xstar_fcs_B.Sum2;
    xstar_fcs_B.u1_n = sin(xstar_fcs_B.mue_rad_i);
    xstar_fcs_B.Sum2 = xstar_fcs_P.a1_Value_m - xstar_fcs_B.u1_n *
      xstar_fcs_B.u1_n * xstar_fcs_B.Sum2;
    if (xstar_fcs_B.Sum2 < 0.0) {
      xstar_fcs_B.Sum2 = -sqrt(fabs(xstar_fcs_B.Sum2));
    } else {
      xstar_fcs_B.Sum2 = sqrt(xstar_fcs_B.Sum2);
    }

    xstar_fcs_B.Sum2 = xstar_fcs_P.a_Value_f / xstar_fcs_B.Sum2;
    xstar_fcs_B.Add_g = xstar_fcs_B.Subtract2_b * xstar_fcs_B.Sum2 +
      xstar_fcs_B.Add;
    xstar_fcs_B.Product4 = (xstar_fcs_B.Sum2 + xstar_fcs_B.Add) *
      xstar_fcs_B.rtb_TmpSignalConversionAtSFun_k;
  }

  xstar_fcs_PrevZCX.WGS_Linearization_Trig_ZCE = (ZCSigState)
    (xstar_fcs_B.Pos_valid > 0);
  xstar_fcs_B.lambda_rad_f = xstar_fcs_P.Scalefactor2_Gain_b *
    xstar_fcs_U.sensors.RTK.RTKP.lon;
  xstar_fcs_B.Sum2 = xstar_fcs_P.Deg2Rad_Gain_c *
    xstar_fcs_U.sensors.RTK.RTKV.trk_gnd;
  xstar_fcs_B.Multiply = (real32_T)(xstar_fcs_U.sensors.RTK.RTKV.hor_spd * cos
    (xstar_fcs_B.Sum2));
  xstar_fcs_B.Sum2 = sin(xstar_fcs_B.Sum2);
  xstar_fcs_B.Multiply1 = (real32_T)(xstar_fcs_U.sensors.RTK.RTKV.hor_spd *
    xstar_fcs_B.Sum2);
  xstar_fcs_B.Gain_k = (real32_T)(xstar_fcs_P.Gain_Gain_f *
    xstar_fcs_U.sensors.RTK.RTKV.vert_spd);
  xstar_fcs_B.Cast = xstar_fcs_B.qY;
  xstar_fcs_B.timestamp_ms = (uint32_T)(xstar_fcs_P.Gain_Gain_e *
    xstar_fcs_B.DiscreteTimeIntegrator_d0);
  xstar_fcs_B.Product3_l = (real32_T)xstar_fcs_P.Gain13_Gain_j * 3.7252903E-9F;
  xstar_fcs_B.sample_sum_a = xstar_fcs_B.Product3_l * (real32_T)
    xstar_fcs_B.rtb_Switch_delta_q0;
  xstar_fcs_B.Product1_g_b = xstar_fcs_B.Product3_l * (real32_T)
    xstar_fcs_B.rtb_Switch_delta_q1;
  xstar_fcs_B.Product2_mi = xstar_fcs_B.Product3_l * (real32_T)
    xstar_fcs_B.rtb_Switch_delta_q2;
  xstar_fcs_B.Gain2_p = xstar_fcs_B.Product3_l * (real32_T)
    xstar_fcs_B.rtb_Switch_delta_q3;
  xstar_fcs_B.LogicalOperator3_f = (((xstar_fcs_B.sample_sum_a *
    xstar_fcs_B.sample_sum_a + xstar_fcs_B.Product1_g_b *
    xstar_fcs_B.Product1_g_b) + xstar_fcs_B.Product2_mi *
    xstar_fcs_B.Product2_mi) + xstar_fcs_B.Gain2_p * xstar_fcs_B.Gain2_p <=
    xstar_fcs_P.CompareToConstant_const_a0);
  if (xstar_fcs_B.LogicalOperator3_f) {
    xstar_fcs_B.sample_sum_a = xstar_fcs_P.Constant_Value[0];
    xstar_fcs_B.Product1_g_b = xstar_fcs_P.Constant_Value[1];
    xstar_fcs_B.Product2_mi = xstar_fcs_P.Constant_Value[2];
    xstar_fcs_B.Gain2_p = xstar_fcs_P.Constant_Value[3];
  }

  mw_arm_sqrt_f32(((xstar_fcs_B.sample_sum_a * xstar_fcs_B.sample_sum_a +
                    xstar_fcs_B.Product1_g_b * xstar_fcs_B.Product1_g_b) +
                   xstar_fcs_B.Product2_mi * xstar_fcs_B.Product2_mi) +
                  xstar_fcs_B.Gain2_p * xstar_fcs_B.Gain2_p,
                  &xstar_fcs_B.Product3_l);
  xstar_fcs_B.fcn3 = xstar_fcs_B.sample_sum_a / xstar_fcs_B.Product3_l;
  xstar_fcs_B.Product1_g_b /= xstar_fcs_B.Product3_l;
  xstar_fcs_B.Product2_mi /= xstar_fcs_B.Product3_l;
  xstar_fcs_B.Product3_l = xstar_fcs_B.Gain2_p / xstar_fcs_B.Product3_l;
  mw_arm_sqrt_f32(((xstar_fcs_B.fcn3 * xstar_fcs_B.fcn3 +
                    xstar_fcs_B.Product1_g_b * xstar_fcs_B.Product1_g_b) +
                   xstar_fcs_B.Product2_mi * xstar_fcs_B.Product2_mi) +
                  xstar_fcs_B.Product3_l * xstar_fcs_B.Product3_l,
                  &xstar_fcs_B.DiscreteTimeIntegrator1_i);
  xstar_fcs_B.Sum_f = xstar_fcs_B.fcn3 / xstar_fcs_B.DiscreteTimeIntegrator1_i;
  xstar_fcs_B.sample_sum_a = xstar_fcs_B.Product1_g_b /
    xstar_fcs_B.DiscreteTimeIntegrator1_i;
  xstar_fcs_B.MathFunction_g = xstar_fcs_B.Product2_mi /
    xstar_fcs_B.DiscreteTimeIntegrator1_i;
  xstar_fcs_B.DiscreteTimeIntegrator1_i = xstar_fcs_B.Product3_l /
    xstar_fcs_B.DiscreteTimeIntegrator1_i;
  xstar_fcs_B.VectorConcatenate_l[0] = ((xstar_fcs_B.Sum_f * xstar_fcs_B.Sum_f +
    xstar_fcs_B.sample_sum_a * xstar_fcs_B.sample_sum_a) -
    xstar_fcs_B.MathFunction_g * xstar_fcs_B.MathFunction_g) -
    xstar_fcs_B.DiscreteTimeIntegrator1_i *
    xstar_fcs_B.DiscreteTimeIntegrator1_i;
  xstar_fcs_B.VectorConcatenate_l[1] = (xstar_fcs_B.sample_sum_a *
    xstar_fcs_B.MathFunction_g - xstar_fcs_B.DiscreteTimeIntegrator1_i *
    xstar_fcs_B.Sum_f) * xstar_fcs_P.Gain_Gain_hc;
  xstar_fcs_B.VectorConcatenate_l[2] = (xstar_fcs_B.Sum_f *
    xstar_fcs_B.MathFunction_g + xstar_fcs_B.sample_sum_a *
    xstar_fcs_B.DiscreteTimeIntegrator1_i) * xstar_fcs_P.Gain_Gain_k3;
  xstar_fcs_B.VectorConcatenate_l[3] = (xstar_fcs_B.DiscreteTimeIntegrator1_i *
    xstar_fcs_B.Sum_f + xstar_fcs_B.sample_sum_a * xstar_fcs_B.MathFunction_g) *
    xstar_fcs_P.Gain_Gain_kd;
  xstar_fcs_B.VectorConcatenate_l[4] = ((xstar_fcs_B.Sum_f * xstar_fcs_B.Sum_f -
    xstar_fcs_B.sample_sum_a * xstar_fcs_B.sample_sum_a) +
    xstar_fcs_B.MathFunction_g * xstar_fcs_B.MathFunction_g) -
    xstar_fcs_B.DiscreteTimeIntegrator1_i *
    xstar_fcs_B.DiscreteTimeIntegrator1_i;
  xstar_fcs_B.VectorConcatenate_l[5] = (xstar_fcs_B.MathFunction_g *
    xstar_fcs_B.DiscreteTimeIntegrator1_i - xstar_fcs_B.Sum_f *
    xstar_fcs_B.sample_sum_a) * xstar_fcs_P.Gain_Gain_pz;
  xstar_fcs_B.VectorConcatenate_l[6] = (xstar_fcs_B.sample_sum_a *
    xstar_fcs_B.DiscreteTimeIntegrator1_i - xstar_fcs_B.Sum_f *
    xstar_fcs_B.MathFunction_g) * xstar_fcs_P.Gain_Gain_ad;
  xstar_fcs_B.VectorConcatenate_l[7] = (xstar_fcs_B.Sum_f *
    xstar_fcs_B.sample_sum_a + xstar_fcs_B.MathFunction_g *
    xstar_fcs_B.DiscreteTimeIntegrator1_i) * xstar_fcs_P.Gain_Gain_pi;
  xstar_fcs_B.VectorConcatenate_l[8] = ((xstar_fcs_B.Sum_f * xstar_fcs_B.Sum_f -
    xstar_fcs_B.sample_sum_a * xstar_fcs_B.sample_sum_a) -
    xstar_fcs_B.MathFunction_g * xstar_fcs_B.MathFunction_g) +
    xstar_fcs_B.DiscreteTimeIntegrator1_i *
    xstar_fcs_B.DiscreteTimeIntegrator1_i;
  xstar_fcs_B.Sum_f = xstar_fcs_P.Gain11_Gain * (real32_T)
    xstar_fcs_B.rtb_Switch_delta_pos_z;
  xstar_fcs_B.Gain2_p = xstar_fcs_P.Gain9_Gain * (real32_T)
    xstar_fcs_B.SumofElements;
  xstar_fcs_B.sample_sum_a = xstar_fcs_P.Gain10_Gain * (real32_T)
    xstar_fcs_B.rtb_Switch_delta_pos_y;
  for (xstar_fcs_B.Sum_mz = 0; xstar_fcs_B.Sum_mz < 3; xstar_fcs_B.Sum_mz++) {
    xstar_fcs_B.TmpSignalConversionAtProduc[xstar_fcs_B.Sum_mz] =
      xstar_fcs_B.VectorConcatenate_l[xstar_fcs_B.Sum_mz + 6] *
      xstar_fcs_B.Sum_f + (xstar_fcs_B.VectorConcatenate_l[xstar_fcs_B.Sum_mz +
      3] * xstar_fcs_B.sample_sum_a +
      xstar_fcs_B.VectorConcatenate_l[xstar_fcs_B.Sum_mz] * xstar_fcs_B.Gain2_p);
  }

  for (xstar_fcs_B.Sum_mz = 0; xstar_fcs_B.Sum_mz < 3; xstar_fcs_B.Sum_mz++) {
    xstar_fcs_B.Product1_ko[xstar_fcs_B.Sum_mz] =
      xstar_fcs_B.In1_d[xstar_fcs_B.Sum_mz + 6] *
      xstar_fcs_B.TmpSignalConversionAtProduc[2] +
      (xstar_fcs_B.In1_d[xstar_fcs_B.Sum_mz + 3] *
       xstar_fcs_B.TmpSignalConversionAtProduc[1] +
       xstar_fcs_B.In1_d[xstar_fcs_B.Sum_mz] *
       xstar_fcs_B.TmpSignalConversionAtProduc[0]);
  }

  xstar_fcs_B.MathFunction_g = xstar_fcs_B.Product1_ko[0] -
    xstar_fcs_DW.Delay_DSTATE_m;
  if (xstar_fcs_MWDSP_EPH_R_B(xstar_fcs_P.Constant_Value_fs,
       &xstar_fcs_DW.Counter_RstEphState) != 0U) {
    xstar_fcs_DW.Counter_Count = xstar_fcs_P.Counter_InitialCount;
  }

  if (xstar_fcs_MWDSP_EPH_R_B(xstar_fcs_B.MathFunction_g >
       xstar_fcs_P.CompareToConstant_const_fu, &xstar_fcs_DW.Counter_ClkEphState)
      != 0U) {
    if (xstar_fcs_DW.Counter_Count < 1000) {
      xstar_fcs_DW.Counter_Count++;
    } else {
      xstar_fcs_DW.Counter_Count = 0U;
    }
  }

  if (xstar_fcs_MWDSP_EPH_R_B(xstar_fcs_P.Constant_Value_fs,
       &xstar_fcs_DW.Counter1_RstEphState) != 0U) {
    xstar_fcs_DW.Counter1_Count = xstar_fcs_P.Counter1_InitialCount;
  }

  if (xstar_fcs_MWDSP_EPH_R_B(xstar_fcs_B.MathFunction_g <
       xstar_fcs_P.CompareToConstant1_const_a,
       &xstar_fcs_DW.Counter1_ClkEphState) != 0U) {
    if (xstar_fcs_DW.Counter1_Count < 1000) {
      xstar_fcs_DW.Counter1_Count++;
    } else {
      xstar_fcs_DW.Counter1_Count = 0U;
    }
  }

  xstar_fcs_B.Sum1 = xstar_fcs_B.Product1_ko[0] - (real32_T)(((real_T)
    xstar_fcs_DW.Counter_Count - (real_T)xstar_fcs_DW.Counter1_Count) *
    xstar_fcs_P.Gain2_Gain);
  xstar_fcs_B.MathFunction_g = xstar_fcs_B.Product1_ko[1] -
    xstar_fcs_DW.Delay_DSTATE_g;
  if (xstar_fcs_MWDSP_EPH_R_B(xstar_fcs_P.Constant_Value_c,
       &xstar_fcs_DW.Counter_RstEphState_c) != 0U) {
    xstar_fcs_DW.Counter_Count_g = xstar_fcs_P.Counter_InitialCount_i;
  }

  if (xstar_fcs_MWDSP_EPH_R_B(xstar_fcs_B.MathFunction_g >
       xstar_fcs_P.CompareToConstant_const_j,
       &xstar_fcs_DW.Counter_ClkEphState_m) != 0U) {
    if (xstar_fcs_DW.Counter_Count_g < 1000) {
      xstar_fcs_DW.Counter_Count_g++;
    } else {
      xstar_fcs_DW.Counter_Count_g = 0U;
    }
  }

  if (xstar_fcs_MWDSP_EPH_R_B(xstar_fcs_P.Constant_Value_c,
       &xstar_fcs_DW.Counter1_RstEphState_n) != 0U) {
    xstar_fcs_DW.Counter1_Count_h = xstar_fcs_P.Counter1_InitialCount_d;
  }

  if (xstar_fcs_MWDSP_EPH_R_B(xstar_fcs_B.MathFunction_g <
       xstar_fcs_P.CompareToConstant1_const_d,
       &xstar_fcs_DW.Counter1_ClkEphState_d) != 0U) {
    if (xstar_fcs_DW.Counter1_Count_h < 1000) {
      xstar_fcs_DW.Counter1_Count_h++;
    } else {
      xstar_fcs_DW.Counter1_Count_h = 0U;
    }
  }

  xstar_fcs_B.Sum1_i = xstar_fcs_B.Product1_ko[1] - (real32_T)(((real_T)
    xstar_fcs_DW.Counter_Count_g - (real_T)xstar_fcs_DW.Counter1_Count_h) *
    xstar_fcs_P.Gain2_Gain_l);
  xstar_fcs_B.MathFunction_g = xstar_fcs_B.Sum_f - xstar_fcs_DW.Delay_DSTATE_f;
  if (xstar_fcs_MWDSP_EPH_R_B(xstar_fcs_P.Constant_Value_h1,
       &xstar_fcs_DW.Counter_RstEphState_i) != 0U) {
    xstar_fcs_DW.Counter_Count_h = xstar_fcs_P.Counter_InitialCount_m;
  }

  if (xstar_fcs_MWDSP_EPH_R_B(xstar_fcs_B.MathFunction_g >
       xstar_fcs_P.CompareToConstant_const_b,
       &xstar_fcs_DW.Counter_ClkEphState_my) != 0U) {
    if (xstar_fcs_DW.Counter_Count_h < 1000) {
      xstar_fcs_DW.Counter_Count_h++;
    } else {
      xstar_fcs_DW.Counter_Count_h = 0U;
    }
  }

  if (xstar_fcs_MWDSP_EPH_R_B(xstar_fcs_P.Constant_Value_h1,
       &xstar_fcs_DW.Counter1_RstEphState_a) != 0U) {
    xstar_fcs_DW.Counter1_Count_k = xstar_fcs_P.Counter1_InitialCount_o;
  }

  if (xstar_fcs_MWDSP_EPH_R_B(xstar_fcs_B.MathFunction_g <
       xstar_fcs_P.CompareToConstant1_const_e,
       &xstar_fcs_DW.Counter1_ClkEphState_h) != 0U) {
    if (xstar_fcs_DW.Counter1_Count_k < 1000) {
      xstar_fcs_DW.Counter1_Count_k++;
    } else {
      xstar_fcs_DW.Counter1_Count_k = 0U;
    }
  }

  xstar_fcs_B.delta_pos_z = (xstar_fcs_B.Sum_f - (real32_T)(((real_T)
    xstar_fcs_DW.Counter_Count_h - (real_T)xstar_fcs_DW.Counter1_Count_k) *
    xstar_fcs_P.Gain2_Gain_o)) * xstar_fcs_P.Gain1_Gain_mq;
  xstar_fcs_B.GPS_Vel_Vaild = xstar_fcs_DW.Memory1_12_PreviousInput;
  xstar_fcs_B.VO_Vel_Valid = xstar_fcs_DW.Memory1_13_PreviousInput;
  if (xstar_fcs_B.GPS_Vel_Vaild || xstar_fcs_B.VO_Vel_Valid) {
    xstar_fcs_B.switchtoATTI = xstar_fcs_P.Constant5_Value;
  } else {
    xstar_fcs_B.switchtoATTI = xstar_fcs_P.Constant7_Value;
  }

  Translation_Fusion(&xstar_fcs_B.M_OB_g[0], &xstar_fcs_B.rot_IB_B_radDs_c[0],
                     &xstar_fcs_B.sfor_R_B_mDs2_c[0], &xstar_fcs_B.yaw_mag,
                     &xstar_fcs_B.Psi_dot_IMU, &xstar_fcs_B.M_OObar[0],
                     &xstar_fcs_B.Psi_star_rad, &xstar_fcs_B.phi_rad,
                     &xstar_fcs_B.theta_rad, &xstar_fcs_B.standstill,
                     &xstar_fcs_B.reset_Yaw, &xstar_fcs_B.Product1_g,
                     &xstar_fcs_B.LogicalOperator4,
                     &xstar_fcs_B.baro_Timestamp_ms, &xstar_fcs_B.Compare,
                     &xstar_fcs_B.DiscreteTimeIntegrator1, &xstar_fcs_B.Double1,
                     &xstar_fcs_B.Status, &xstar_fcs_B.Add_a,
                     &xstar_fcs_B.Product4_h, &xstar_fcs_B.mue_rad,
                     &xstar_fcs_B.lambda_rad, &xstar_fcs_B.Product1[0],
                     &xstar_fcs_B.Product1[1], &xstar_fcs_B.Gain,
                     &xstar_fcs_B.Timestamp_ms, &xstar_fcs_B.GpsHeight,
                     &xstar_fcs_B.Sum, &xstar_fcs_B.Saturation1[0],
                     &xstar_fcs_B.Saturation1_d[0], &xstar_fcs_B.pos_type,
                     &xstar_fcs_B.Add_g, &xstar_fcs_B.Product4,
                     &xstar_fcs_B.dz_dh, &xstar_fcs_B.mue_rad_i,
                     &xstar_fcs_B.lambda_rad_f, &xstar_fcs_B.Add,
                     &xstar_fcs_B.Multiply, &xstar_fcs_B.Multiply1,
                     &xstar_fcs_B.Gain_k, &xstar_fcs_B.Cast,
                     &xstar_fcs_B.Switch1_a, &xstar_fcs_B.h_grd_sonar,
                     &xstar_fcs_B.timestamp_s, &xstar_fcs_B.mul5[0],
                     &xstar_fcs_B.Vision_quality, &xstar_fcs_B.Switch_i,
                     &xstar_fcs_B.timestamp_ms, &xstar_fcs_B.mul5[2],
                     &xstar_fcs_B.Sum1, &xstar_fcs_B.Sum1_i,
                     &xstar_fcs_B.delta_pos_z, &xstar_fcs_B.Switch1,
                     &xstar_fcs_B.Armed_p, &xstar_fcs_B.On_grd,
                     &xstar_fcs_P.Constant5_Value_m, &xstar_fcs_B.switchtoATTI,
                     &xstar_fcs_P.Constant1_Value_m,
                     &xstar_fcs_B.DataTypeConversion1_n,
                     &xstar_fcs_B.h_dot_mDs_c, &xstar_fcs_B.h_AGL_m_a,
                     &xstar_fcs_B.h_0_AGL_m, &xstar_fcs_B.h_MSL,
                     &xstar_fcs_B.Bias_z_mDs2, &xstar_fcs_B.VEL_xy_O_mDs[0],
                     &xstar_fcs_B.Pos_Init_flg[0], &xstar_fcs_B.mue_est_rad,
                     &xstar_fcs_B.lambda_est_rad, &xstar_fcs_B.POS_xy_O_m[0],
                     &xstar_fcs_B.POS_reset_signal, &xstar_fcs_B.GPS_Vel_Vaild_d,
                     &xstar_fcs_B.VO_Vel_Valid_m, &xstar_fcs_B.mue_est_rad_fc,
                     &xstar_fcs_B.lambda_est_rad_fc,
                     &xstar_fcs_B.Translation_Fusion_o16[0],
                     &xstar_fcs_B.Translation_Fusion_o17, &xstar_fcs_B.h_MSL_g,
                     &xstar_fcs_B.Translation_Fusion_o19[0],
                     &xstar_fcs_B.Translation_Fusion_o20[0],
                     &xstar_fcs_B.Pos_Init_flg_p,
                     &xstar_fcs_B.Translation_Fusion_o22, &xstar_fcs_B.Status_d,
                     &xstar_fcs_B.Ts_Update, &xstar_fcs_B.En_GPS_cor_core,
                     &xstar_fcs_B.En_GPS_Valid, &xstar_fcs_B.En_GPS_Correct_RTK,
                     &xstar_fcs_B.Translation_Fusion_o28);
  xstar_fcs_Y.INS_Base.phi_rad = xstar_fcs_B.phi_rad;
  xstar_fcs_Y.INS_Base.theta_rad = xstar_fcs_B.theta_rad;
  xstar_fcs_Y.INS_Base.Psi_star_rad = xstar_fcs_B.Psi_star_rad;
  xstar_fcs_Y.INS_Base.h_AGL_m = xstar_fcs_B.h_AGL_m_a;
  xstar_fcs_Y.INS_Base.delta_h_m = xstar_fcs_B.h_MSL;
  xstar_fcs_Y.INS_Base.h_dot_mDs = xstar_fcs_B.h_dot_mDs_c;
  xstar_fcs_Y.INS_Base.M_OObar[0] = xstar_fcs_B.M_OObar[0];
  xstar_fcs_Y.INS_Base.M_OObar[1] = xstar_fcs_B.M_OObar[1];
  xstar_fcs_Y.INS_Base.M_OObar[2] = xstar_fcs_B.M_OObar[2];
  xstar_fcs_Y.INS_Base.M_OObar[3] = xstar_fcs_B.M_OObar[3];
  xstar_fcs_Y.INS_Base.mue_est_rad = xstar_fcs_B.mue_est_rad;
  xstar_fcs_Y.INS_Base.lambda_est_rad = xstar_fcs_B.lambda_est_rad;
  xstar_fcs_Y.INS_Base.Status = xstar_fcs_B.Status;
  xstar_fcs_Y.INS_Base.dx_dmue = xstar_fcs_B.Add_a;
  xstar_fcs_Y.INS_Base.dy_dlambda = xstar_fcs_B.Product4_h;
  xstar_fcs_Y.INS_Base.VEL_xy_O_mDs[0] = xstar_fcs_B.VEL_xy_O_mDs[0];
  xstar_fcs_Y.INS_Base.VEL_xy_O_mDs[1] = xstar_fcs_B.VEL_xy_O_mDs[1];
  xstar_fcs_Y.INS_Base.sonar_valid = xstar_fcs_B.Switch1_a;
  xstar_fcs_Y.INS_Base.Vision_quality = xstar_fcs_B.Vision_quality;
  xstar_fcs_Y.INS_Base.Vision_valid = xstar_fcs_B.Switch_i;
  xstar_fcs_Y.INS_Base.IMU_valid = xstar_fcs_B.IMU_valid;
  xstar_fcs_Y.INS_Base.Mag_Quality = xstar_fcs_B.Product4_m;
  xstar_fcs_Y.INS_Base.baro_valid = xstar_fcs_B.LogicalOperator4;
  xstar_fcs_Y.INS_Base.Heading_Quality = xstar_fcs_B.Heading_Quality;
  xstar_fcs_Y.INS_Base.Spd_quality = xstar_fcs_B.DiscreteTimeIntegrator1;
  xstar_fcs_Y.INS_Base.Pos_quality = xstar_fcs_B.Double1;
  xstar_fcs_Y.INS_Base.Armed = xstar_fcs_B.Armed_p;
  xstar_fcs_Y.INS_Base.On_grd = xstar_fcs_B.On_grd;
  xstar_fcs_Y.INS_Base.Tilt_Over_flag = xstar_fcs_P.Constant5_Value_nm;
  xstar_fcs_Y.INS_Base.ground_condition = xstar_fcs_P.Constant7_Value_p;
  xstar_fcs_Y.INS_Base.magnitude_uT = xstar_fcs_B.y[0];
  xstar_fcs_Y.INS_Base.standstill = xstar_fcs_B.standstill;
  xstar_fcs_Y.INS_Base.GPS_Vel_Vaild = xstar_fcs_B.GPS_Vel_Vaild_d;
  xstar_fcs_Y.INS_Base.VO_Vel_Valid = xstar_fcs_B.VO_Vel_Valid_m;
  xstar_fcs_Y.INS_Base.h_0_AGL_m = xstar_fcs_B.h_0_AGL_m;
  xstar_fcs_Y.INS_Base.h_grd_sonar = xstar_fcs_B.h_grd_sonar;
  xstar_fcs_Y.INS_Base.mue_est_rad_fc = xstar_fcs_B.mue_est_rad_fc;
  xstar_fcs_Y.INS_Base.lambda_est_rad_fc = xstar_fcs_B.lambda_est_rad_fc;
  xstar_fcs_Y.INS_Base.att_Oz_B[0] = xstar_fcs_B.att_Oz_B[0];
  xstar_fcs_Y.INS_Base.att_Oz_B[1] = xstar_fcs_B.att_Oz_B[1];
  xstar_fcs_Y.INS_Base.att_Oz_B[2] = xstar_fcs_B.att_Oz_B[2];
  xstar_fcs_Y.INS_Base.Oz_rotation = (xstar_fcs_B.att_Oz_B[0] *
    xstar_fcs_B.rot_IB_B_radDs_c[0] + xstar_fcs_B.att_Oz_B[1] *
    xstar_fcs_B.rot_IB_B_radDs_c[1]) + xstar_fcs_B.att_Oz_B[2] *
    xstar_fcs_B.rot_IB_B_radDs_c[2];
  xstar_fcs_Y.INS_Base.POS_xy_O_m[0] = xstar_fcs_B.POS_xy_O_m[0];
  xstar_fcs_Y.INS_Base.POS_xy_O_m[1] = xstar_fcs_B.POS_xy_O_m[1];
  xstar_fcs_B.Gain2_p = (real32_T)xstar_fcs_B.VectorConcatenate3[0] *
    xstar_fcs_P.Mag_ScaleFactor_Value_l;
  xstar_fcs_B.sample_sum_a = xstar_fcs_B.Gain2_p * xstar_fcs_B.Gain2_p;
  xstar_fcs_B.Gain2_p = (real32_T)xstar_fcs_B.VectorConcatenate3[1] *
    xstar_fcs_P.Mag_ScaleFactor_Value_l;
  xstar_fcs_B.MathFunction_g = xstar_fcs_B.Gain2_p * xstar_fcs_B.Gain2_p;
  xstar_fcs_B.Gain2_p = (real32_T)xstar_fcs_B.VectorConcatenate3[2] *
    xstar_fcs_P.Mag_ScaleFactor_Value_l;
  xstar_fcs_B.Gain2_p *= xstar_fcs_B.Gain2_p;
  mw_arm_sqrt_f32((xstar_fcs_B.sample_sum_a + xstar_fcs_B.MathFunction_g) +
                  xstar_fcs_B.Gain2_p, &xstar_fcs_B.MathFunction_g);
  if (xstar_fcs_B.DiscreteTimeIntegrator_pl > xstar_fcs_P.Saturation_UpperSat_p4)
  {
    xstar_fcs_B.DiscreteTimeIntegrator_pl = xstar_fcs_P.Saturation_UpperSat_p4;
  } else {
    if (xstar_fcs_B.DiscreteTimeIntegrator_pl <
        xstar_fcs_P.Saturation_LowerSat_c) {
      xstar_fcs_B.DiscreteTimeIntegrator_pl = xstar_fcs_P.Saturation_LowerSat_c;
    }
  }

  xstar_fcs_B.u1 = xstar_fcs_P.Constant4_Value - xstar_fcs_P.Gain3_Gain_i *
    xstar_fcs_B.DiscreteTimeIntegrator_pl;
  if ((!(xstar_fcs_B.DiscreteTimeIntegrator2_oo < xstar_fcs_B.u1)) && (!rtIsNaNF
       (xstar_fcs_B.u1))) {
    xstar_fcs_B.DiscreteTimeIntegrator2_oo = xstar_fcs_B.u1;
  }

  xstar_fcs_Y.Data_out.Mag_Q[0] = (real32_T)((xstar_fcs_P.IntervalTest_lowlimit <=
    xstar_fcs_B.MathFunction_g) && (xstar_fcs_B.MathFunction_g <=
    xstar_fcs_P.IntervalTest_uplimit));
  if ((xstar_fcs_B.DiscreteTimeIntegrator2_oo > xstar_fcs_P.Constant5_Value_n) ||
      rtIsNaNF(xstar_fcs_P.Constant5_Value_n)) {
    xstar_fcs_Y.Data_out.Mag_Q[1] = xstar_fcs_B.DiscreteTimeIntegrator2_oo;
  } else {
    xstar_fcs_Y.Data_out.Mag_Q[1] = xstar_fcs_P.Constant5_Value_n;
  }

  xstar_fcs_Y.Data_out.reset_yaw = xstar_fcs_B.Rotation_AHRS_GPS_o26;
  xstar_fcs_Y.Data_out.att_init_done = xstar_fcs_B.Rotation_AHRS_GPS_o28;
  xstar_fcs_Y.Data_out.sensors_forlog.imu_gyro_id_process =
    (xstar_fcs_B.Switch1_l == xstar_fcs_P.CompareToConstant_const_h);
  xstar_fcs_Y.Data_out.sensors_forlog.imu_acc_id_process = (xstar_fcs_B.Switch2 ==
    xstar_fcs_P.CompareToConstant1_const_pz);
  xstar_fcs_Y.Data_out.yaw_mag = xstar_fcs_B.yaw_mag_p;
  xstar_fcs_Y.Data_out.imu_data_for_calibrate.rot_IB_B_raw_radDs_1[0] =
    xstar_fcs_B.rtb_Product8_idx_0;
  xstar_fcs_Y.Data_out.imu_data_for_calibrate.sfor_R_B_mDs2_1[0] =
    xstar_fcs_B.rtb_Product9_idx_0;
  xstar_fcs_Y.Data_out.imu_data_for_calibrate.rot_IB_B_raw_radDs_2[0] =
    xstar_fcs_B.Product2_h[0];
  xstar_fcs_Y.Data_out.imu_data_for_calibrate.sfor_R_B_mDs2_2[0] =
    xstar_fcs_B.rtb_v_idx_0;
  xstar_fcs_Y.Data_out.imu_data_for_calibrate.rot_IB_B_raw_radDs_1[1] =
    xstar_fcs_B.rtb_Product8_idx_1;
  xstar_fcs_Y.Data_out.imu_data_for_calibrate.sfor_R_B_mDs2_1[1] =
    xstar_fcs_B.rtb_Product9_idx_1;
  xstar_fcs_Y.Data_out.imu_data_for_calibrate.rot_IB_B_raw_radDs_2[1] =
    xstar_fcs_B.Product2_h[1];
  xstar_fcs_Y.Data_out.imu_data_for_calibrate.sfor_R_B_mDs2_2[1] =
    xstar_fcs_B.rtb_v_idx_1;
  xstar_fcs_Y.Data_out.imu_data_for_calibrate.rot_IB_B_raw_radDs_1[2] =
    xstar_fcs_B.Gain_p;
  xstar_fcs_Y.Data_out.imu_data_for_calibrate.sfor_R_B_mDs2_1[2] =
    xstar_fcs_B.rtb_Product8_idx_2;
  xstar_fcs_Y.Data_out.imu_data_for_calibrate.rot_IB_B_raw_radDs_2[2] =
    xstar_fcs_B.Product2_h[2];
  xstar_fcs_Y.Data_out.imu_data_for_calibrate.sfor_R_B_mDs2_2[2] =
    xstar_fcs_B.rtb_v_idx_2;
  xstar_fcs_Y.Data_out.roll_pitch_rate_bias[0] =
    xstar_fcs_B.Rotation_AHRS_GPS_o32[0];
  xstar_fcs_Y.Data_out.roll_pitch_rate_bias[1] =
    xstar_fcs_B.Rotation_AHRS_GPS_o32[1];
  xstar_fcs_Y.Data_out.yaw_rate_bias = xstar_fcs_B.Rotation_AHRS_GPS_o31;
  xstar_fcs_Y.Data_out.RTK_Pos_Good = xstar_fcs_B.Translation_Fusion_o17;
  xstar_fcs_Y.Data_out.h_MSL = xstar_fcs_B.h_MSL_g;
  xstar_fcs_Y.Data_out.Vel_G[0] = xstar_fcs_B.Translation_Fusion_o19[0];
  xstar_fcs_Y.Data_out.Vel_G[1] = xstar_fcs_B.Translation_Fusion_o19[1];
  xstar_fcs_Y.Data_out.Vel_G[2] = xstar_fcs_B.Translation_Fusion_o19[2];
  xstar_fcs_Y.Data_out.Pos_Init_flg = xstar_fcs_B.Pos_Init_flg_p;
  xstar_fcs_Y.Data_out.h_0_m_MSL = xstar_fcs_B.Translation_Fusion_o22;
  xstar_fcs_Y.Data_out.Pos_LL_WGS84_Camera[0] =
    xstar_fcs_B.Translation_Fusion_o20[0];
  xstar_fcs_Y.Data_out.Pos_LL_WGS84_Camera[1] =
    xstar_fcs_B.Translation_Fusion_o20[1];
  mw_arm_sqrt_f32(xstar_fcs_B.rtb_Mag_Q_idx_0 * xstar_fcs_B.rtb_Mag_Q_idx_0 +
                  xstar_fcs_B.Add_n * xstar_fcs_B.Add_n,
                  &xstar_fcs_B.MathFunction_g);
  xstar_fcs_B.HorizontalAccuracy = xstar_fcs_P.Scalefactor4_Gain *
    xstar_fcs_B.MathFunction_g;
  xstar_fcs_B.VerticalAccuracy = xstar_fcs_P.Scalefactor3_Gain *
    xstar_fcs_U.sensors.RTK_Base.hgt_stddev;
  mw_arm_sqrt_f32((xstar_fcs_U.sensors.RTK_Base.Vx_stddev *
                   xstar_fcs_U.sensors.RTK_Base.Vx_stddev +
                   xstar_fcs_U.sensors.RTK_Base.Vy_stddev *
                   xstar_fcs_U.sensors.RTK_Base.Vy_stddev) +
                  xstar_fcs_U.sensors.RTK_Base.Vz_stddev *
                  xstar_fcs_U.sensors.RTK_Base.Vz_stddev, &xstar_fcs_B.Sqrt);
  xstar_fcs_B.pos_type_m = xstar_fcs_U.sensors.RTK_Base.pos_type;
  xstar_fcs_B.sol_s_pos = xstar_fcs_U.sensors.RTK_Base.sol_s_pos;
  xstar_fcs_B.vel_type = xstar_fcs_U.sensors.RTK_Base.vel_type;
  xstar_fcs_B.sol_s_vel = xstar_fcs_U.sensors.RTK_Base.sol_s_vel;
  xstar_fcs_Y.Sensor_data.GPS_data.GPS_reset = xstar_fcs_B.Compare;
  xstar_fcs_Y.Sensor_data.GPS_data.Spd_quality =
    xstar_fcs_B.DiscreteTimeIntegrator1;
  xstar_fcs_Y.Sensor_data.GPS_data.Pos_quality = xstar_fcs_B.Double1;
  xstar_fcs_Y.Sensor_data.GPS_data.Status = xstar_fcs_B.Status;
  xstar_fcs_Y.Sensor_data.GPS_data.lambda_0_WGS84_rad =
    xstar_fcs_B.lambda_0_WGS84_rad;
  xstar_fcs_Y.Sensor_data.GPS_data.mue_0_WGS84_rad = xstar_fcs_B.mue_0_WGS84_rad;
  xstar_fcs_Y.Sensor_data.GPS_data.dx_dmue = xstar_fcs_B.Add_a;
  xstar_fcs_Y.Sensor_data.GPS_data.dy_dlambda = xstar_fcs_B.Product4_h;
  xstar_fcs_Y.Sensor_data.GPS_data.mue_rad = xstar_fcs_B.mue_rad;
  xstar_fcs_Y.Sensor_data.GPS_data.lambda_rad = xstar_fcs_B.lambda_rad;
  xstar_fcs_Y.Sensor_data.GPS_data.vel_N = xstar_fcs_B.Product1[0];
  xstar_fcs_Y.Sensor_data.GPS_data.vel_E = xstar_fcs_B.Product1[1];
  xstar_fcs_Y.Sensor_data.GPS_data.vel_D = xstar_fcs_B.Gain;
  xstar_fcs_Y.Sensor_data.GPS_data.Timestamp_ms = xstar_fcs_B.Timestamp_ms;
  xstar_fcs_Y.Sensor_data.GPS_data.HorizontalAccuracy =
    xstar_fcs_B.HorizontalAccuracy;
  xstar_fcs_Y.Sensor_data.GPS_data.VerticalAccuracy =
    xstar_fcs_B.VerticalAccuracy;
  xstar_fcs_Y.Sensor_data.GPS_data.SpeedAccuracy = xstar_fcs_B.Sqrt;
  xstar_fcs_Y.Sensor_data.GPS_data.GpsHeight = xstar_fcs_B.GpsHeight;
  xstar_fcs_Y.Sensor_data.GPS_data.pos_type = xstar_fcs_B.pos_type_m;
  xstar_fcs_Y.Sensor_data.GPS_data.sol_s_pos = xstar_fcs_B.sol_s_pos;
  xstar_fcs_Y.Sensor_data.GPS_data.vel_type = xstar_fcs_B.vel_type;
  xstar_fcs_Y.Sensor_data.GPS_data.sol_s_vel = xstar_fcs_B.sol_s_vel;
  xstar_fcs_Y.Sensor_data.GPS_data.ant_heading = xstar_fcs_B.ant_heading;
  xstar_fcs_Y.Sensor_data.GPS_data.heading_valid = xstar_fcs_B.LogicalOperator;
  xstar_fcs_Y.Sensor_data.GPS_data.Timestamp_ms_hd = xstar_fcs_B.Timestamp_ms_hd;
  xstar_fcs_B.LogicalOperator3_b = ((xstar_fcs_B.Sum &
    xstar_fcs_P.BitwiseAND2_BitMask_n) > xstar_fcs_P.Constant_Value_ch);
  xstar_fcs_B.LogicalOperator3_f = !xstar_fcs_B.LogicalOperator3_b;
  xstar_fcs_B.DiscreteTimeIntegrator_pl = (xstar_fcs_P.Constant_Value_eb -
    xstar_fcs_U.sensors.RTK.RTKH.hdgstddev) * xstar_fcs_P.Gain1_Gain_j;
  if (xstar_fcs_B.DiscreteTimeIntegrator_pl > xstar_fcs_P.Saturation_UpperSat_e)
  {
    xstar_fcs_B.DiscreteTimeIntegrator_pl = xstar_fcs_P.Saturation_UpperSat_e;
  } else {
    if (xstar_fcs_B.DiscreteTimeIntegrator_pl <
        xstar_fcs_P.Saturation_LowerSat_o) {
      xstar_fcs_B.DiscreteTimeIntegrator_pl = xstar_fcs_P.Saturation_LowerSat_o;
    }
  }

  if (xstar_fcs_DW.DiscreteTimeIntegrator5_IC_LO_c != 0) {
    xstar_fcs_DW.DiscreteTimeIntegrator5_DSTAT_f =
      xstar_fcs_B.DiscreteTimeIntegrator_pl;
  }

  if (xstar_fcs_B.LogicalOperator3_f ||
      (xstar_fcs_DW.DiscreteTimeIntegrator5_PrevR_f != 0)) {
    xstar_fcs_DW.DiscreteTimeIntegrator5_DSTAT_f =
      xstar_fcs_B.DiscreteTimeIntegrator_pl;
  }

  xstar_fcs_B.Gain2_p = xstar_fcs_DW.DiscreteTimeIntegrator5_DSTAT_f;
  xstar_fcs_B.DiscreteTimeIntegrator1_i =
    xstar_fcs_DW.DiscreteTimeIntegrator5_DSTAT_f * (real32_T)
    xstar_fcs_B.LogicalOperator3_b;
  if (xstar_fcs_B.DiscreteTimeIntegrator1_i > xstar_fcs_P.Saturation1_UpperSat_f)
  {
    xstar_fcs_B.Saturation1_g = xstar_fcs_P.Saturation1_UpperSat_f;
  } else if (xstar_fcs_B.DiscreteTimeIntegrator1_i <
             xstar_fcs_P.Saturation1_LowerSat_f) {
    xstar_fcs_B.Saturation1_g = xstar_fcs_P.Saturation1_LowerSat_f;
  } else {
    xstar_fcs_B.Saturation1_g = xstar_fcs_B.DiscreteTimeIntegrator1_i;
  }

  xstar_fcs_B.MathFunction_g = xstar_fcs_rt_remf_snf
    (xstar_fcs_U.sensors.RTK.RTKH.heading + xstar_fcs_P.Constant1_Value_f2,
     xstar_fcs_P.Constant2_Value_k);
  if (xstar_fcs_B.MathFunction_g > xstar_fcs_P.CompareToConstant_const_p) {
    xstar_fcs_B.MathFunction_g -= xstar_fcs_P.Constant_Value_kp;
  }

  xstar_fcs_B.deg2rad = xstar_fcs_P.deg2rad_Gain * xstar_fcs_B.MathFunction_g;
  xstar_fcs_B.SVs = xstar_fcs_U.sensors.RTK.RTKP.SVs;
  xstar_fcs_Y.Sensor_data.RTK_Data.RTK_status = xstar_fcs_B.Sum;
  xstar_fcs_Y.Sensor_data.RTK_Data.pos_quality[0] = xstar_fcs_B.Saturation1[0];
  xstar_fcs_Y.Sensor_data.RTK_Data.vel_quality[0] = xstar_fcs_B.Saturation1_d[0];
  xstar_fcs_Y.Sensor_data.RTK_Data.pos_quality[1] = xstar_fcs_B.Saturation1[1];
  xstar_fcs_Y.Sensor_data.RTK_Data.vel_quality[1] = xstar_fcs_B.Saturation1_d[1];
  xstar_fcs_Y.Sensor_data.RTK_Data.pos_quality[2] = xstar_fcs_B.Saturation1[2];
  xstar_fcs_Y.Sensor_data.RTK_Data.vel_quality[2] = xstar_fcs_B.Saturation1_d[2];
  xstar_fcs_Y.Sensor_data.RTK_Data.heading_quality = xstar_fcs_B.Saturation1_g;
  xstar_fcs_Y.Sensor_data.RTK_Data.rtk_type = xstar_fcs_B.pos_type;
  xstar_fcs_Y.Sensor_data.RTK_Data.dx_dmue = xstar_fcs_B.Add_g;
  xstar_fcs_Y.Sensor_data.RTK_Data.dy_dlambda = xstar_fcs_B.Product4;
  xstar_fcs_Y.Sensor_data.RTK_Data.dz_dh = xstar_fcs_B.dz_dh;
  xstar_fcs_Y.Sensor_data.RTK_Data.mue_rad = xstar_fcs_B.mue_rad_i;
  xstar_fcs_Y.Sensor_data.RTK_Data.lambda_rad = xstar_fcs_B.lambda_rad_f;
  xstar_fcs_Y.Sensor_data.RTK_Data.height_m = xstar_fcs_B.Add;
  xstar_fcs_Y.Sensor_data.RTK_Data.vel_N = xstar_fcs_B.Multiply;
  xstar_fcs_Y.Sensor_data.RTK_Data.vel_E = xstar_fcs_B.Multiply1;
  xstar_fcs_Y.Sensor_data.RTK_Data.vel_D = xstar_fcs_B.Gain_k;
  xstar_fcs_Y.Sensor_data.RTK_Data.heading = xstar_fcs_B.deg2rad;
  xstar_fcs_Y.Sensor_data.RTK_Data.numSV = xstar_fcs_B.SVs;
  xstar_fcs_Y.Sensor_data.RTK_Data.Timestamp_ms = xstar_fcs_B.Cast;
  xstar_fcs_B.LogicalOperator3_b = !xstar_fcs_B.Switch1_a;
  xstar_fcs_B.DiscreteTimeIntegrator2_oo = xstar_fcs_DW.Memory1_PreviousInput -
    xstar_fcs_B.raw_sona_h;
  if (xstar_fcs_DW.DiscreteTimeIntegrator5_IC_LO_g != 0) {
    xstar_fcs_DW.DiscreteTimeIntegrator5_DSTAT_j =
      xstar_fcs_B.DiscreteTimeIntegrator2_oo;
  }

  if (xstar_fcs_B.LogicalOperator3_b ||
      (xstar_fcs_DW.DiscreteTimeIntegrator5_PrevR_o != 0)) {
    xstar_fcs_DW.DiscreteTimeIntegrator5_DSTAT_j =
      xstar_fcs_B.DiscreteTimeIntegrator2_oo;
  }

  xstar_fcs_B.delta_h_m = xstar_fcs_B.raw_sona_h +
    xstar_fcs_DW.DiscreteTimeIntegrator5_DSTAT_j;
  xstar_fcs_B.sonar_reset = !xstar_fcs_B.f4;
  xstar_fcs_Y.Sensor_data.Sonar_data.h_sonar = xstar_fcs_B.delta_h_m;
  xstar_fcs_Y.Sensor_data.Sonar_data.sonar_valid = xstar_fcs_B.Switch1_a;
  xstar_fcs_Y.Sensor_data.Sonar_data.sonar_reset = xstar_fcs_B.sonar_reset;
  xstar_fcs_Y.Sensor_data.Sonar_data.h_grd_sonar = xstar_fcs_B.h_grd_sonar;
  xstar_fcs_Y.Sensor_data.Sonar_data.timestamp_s = xstar_fcs_B.timestamp_s;
  if (xstar_fcs_B.delta_t > xstar_fcs_P.delay_delay_of_i) {
    xstar_fcs_B.Sum_mz = xstar_fcs_P.delay_delay_of_i;
  } else if (xstar_fcs_B.delta_t < xstar_fcs_P.Saturation2_LowerSat_i) {
    xstar_fcs_B.Sum_mz = xstar_fcs_P.Saturation2_LowerSat_i;
  } else {
    xstar_fcs_B.Sum_mz = xstar_fcs_B.delta_t;
  }

  xstar_fcs_B.rtb_v_idx_1 = xstar_fcs_DW.TappedDelay2_X_m[xstar_fcs_B.Sum_mz - 1]
    * xstar_fcs_P.Gain_Gain_lv;
  xstar_fcs_B.Sum_i5[0] = xstar_fcs_P.Constant_Value_f;
  xstar_fcs_B.Sum_i5[1] = xstar_fcs_P.Constant3_Value_o;
  xstar_fcs_B.Sum_i5[2] = xstar_fcs_P.Gain_Gain_m5 * xstar_fcs_B.rtb_v_idx_1;
  xstar_fcs_B.Sum_i5[3] = xstar_fcs_P.Gain1_Gain_ge *
    xstar_fcs_P.Constant3_Value_o;
  xstar_fcs_B.Sum_i5[4] = xstar_fcs_P.Constant1_Value_b;
  if (xstar_fcs_B.delta_t > xstar_fcs_P.delay1_delay_of_b) {
    xstar_fcs_B.Sum_mz = xstar_fcs_P.delay1_delay_of_b;
  } else if (xstar_fcs_B.delta_t < xstar_fcs_P.Saturation2_LowerSat_d) {
    xstar_fcs_B.Sum_mz = xstar_fcs_P.Saturation2_LowerSat_d;
  } else {
    xstar_fcs_B.Sum_mz = xstar_fcs_B.delta_t;
  }

  xstar_fcs_B.Sum_i5[5] = xstar_fcs_DW.TappedDelay2_X_l[xstar_fcs_B.Sum_mz - 1];
  xstar_fcs_B.Sum_i5[6] = xstar_fcs_B.rtb_v_idx_1;
  if (xstar_fcs_B.delta_t > xstar_fcs_P.delay1_delay_of_b) {
    xstar_fcs_B.Sum_mz = xstar_fcs_P.delay1_delay_of_b;
  } else if (xstar_fcs_B.delta_t < xstar_fcs_P.Saturation2_LowerSat_d) {
    xstar_fcs_B.Sum_mz = xstar_fcs_P.Saturation2_LowerSat_d;
  } else {
    xstar_fcs_B.Sum_mz = xstar_fcs_B.delta_t;
  }

  xstar_fcs_B.Sum_i5[7] = xstar_fcs_DW.TappedDelay2_X_l[xstar_fcs_B.Sum_mz - 1] *
    xstar_fcs_P.Gain2_Gain_a;
  xstar_fcs_B.Sum_i5[8] = xstar_fcs_P.Constant2_Value_er;
  if (xstar_fcs_B.delta_t > xstar_fcs_P.delay2_delay_of_g) {
    xstar_fcs_B.Sum_mz = xstar_fcs_P.delay2_delay_of_g;
  } else if (xstar_fcs_B.delta_t < xstar_fcs_P.Saturation2_LowerSat_k) {
    xstar_fcs_B.Sum_mz = xstar_fcs_P.Saturation2_LowerSat_k;
  } else {
    xstar_fcs_B.Sum_mz = xstar_fcs_B.delta_t;
  }

  xstar_fcs_B.DiscreteTimeIntegrator2_oo =
    xstar_fcs_DW.TappedDelay2_X_f[xstar_fcs_B.Sum_mz - 1] +
    xstar_fcs_P.Constant1_Value_c;
  if (xstar_fcs_B.DiscreteTimeIntegrator2_oo > xstar_fcs_P.Switch_Threshold_p) {
    if (xstar_fcs_P.Zero_Value_Exclusion_thr >
        xstar_fcs_B.DiscreteTimeIntegrator2_oo) {
      xstar_fcs_B.sample_sum_a = xstar_fcs_P.Zero_Value_Exclusion_thr;
    } else {
      xstar_fcs_B.sample_sum_a = xstar_fcs_B.DiscreteTimeIntegrator2_oo;
    }
  } else if ((xstar_fcs_B.DiscreteTimeIntegrator2_oo <
              xstar_fcs_P.Constant2_Value_f) || rtIsNaNF
             (xstar_fcs_P.Constant2_Value_f)) {
    xstar_fcs_B.sample_sum_a = xstar_fcs_B.DiscreteTimeIntegrator2_oo;
  } else {
    xstar_fcs_B.sample_sum_a = xstar_fcs_P.Constant2_Value_f;
  }

  for (xstar_fcs_B.Sum_mz = 0; xstar_fcs_B.Sum_mz < 3; xstar_fcs_B.Sum_mz++) {
    for (xstar_fcs_B.cff = 0; xstar_fcs_B.cff < 3; xstar_fcs_B.cff++) {
      xstar_fcs_B.i0 = 3 * xstar_fcs_B.Sum_mz + xstar_fcs_B.cff;
      xstar_fcs_B.fv0[xstar_fcs_B.cff + 3 * xstar_fcs_B.Sum_mz] =
        ((xstar_fcs_B.Sum_i5[3 * xstar_fcs_B.Sum_mz + 1] *
          xstar_fcs_B.Sum_i5[xstar_fcs_B.cff + 3] + xstar_fcs_B.Sum_i5[3 *
          xstar_fcs_B.Sum_mz] * xstar_fcs_B.Sum_i5[xstar_fcs_B.cff]) +
         xstar_fcs_B.Sum_i5[3 * xstar_fcs_B.Sum_mz + 2] *
         xstar_fcs_B.Sum_i5[xstar_fcs_B.cff + 6]) / xstar_fcs_B.sample_sum_a +
        (xstar_fcs_P.Constant_Value_p[xstar_fcs_B.i0] +
         xstar_fcs_B.Sum_i5[xstar_fcs_B.i0]);
    }
  }

  for (xstar_fcs_B.Sum_mz = 0; xstar_fcs_B.Sum_mz < 9; xstar_fcs_B.Sum_mz++) {
    xstar_fcs_B.Sum_i5[xstar_fcs_B.Sum_mz] = xstar_fcs_B.fv0[xstar_fcs_B.Sum_mz];
  }

  for (xstar_fcs_B.Sum_mz = 0; xstar_fcs_B.Sum_mz < 3; xstar_fcs_B.Sum_mz++) {
    xstar_fcs_B.mul3[xstar_fcs_B.Sum_mz] = 0.0F;
    xstar_fcs_B.mul3[xstar_fcs_B.Sum_mz] +=
      xstar_fcs_B.Sum_i5[xstar_fcs_B.Sum_mz] * xstar_fcs_B.sincos_o2[0];
    xstar_fcs_B.mul3[xstar_fcs_B.Sum_mz] +=
      xstar_fcs_B.Sum_i5[xstar_fcs_B.Sum_mz + 3] * xstar_fcs_B.sincos_o2[1];
    xstar_fcs_B.mul3[xstar_fcs_B.Sum_mz] +=
      xstar_fcs_B.Sum_i5[xstar_fcs_B.Sum_mz + 6] * xstar_fcs_B.sincos_o2[2];
  }

  xstar_fcs_B.q0 = xstar_fcs_P.Gain4_Gain_n * (real32_T)
    xstar_fcs_B.rtb_Switch_delta_q0;
  xstar_fcs_B.q1 = xstar_fcs_P.Gain6_Gain * (real32_T)
    xstar_fcs_B.rtb_Switch_delta_q1;
  xstar_fcs_B.q2 = xstar_fcs_P.Gain7_Gain * (real32_T)
    xstar_fcs_B.rtb_Switch_delta_q2;
  xstar_fcs_B.q3 = xstar_fcs_P.Gain8_Gain_m * (real32_T)
    xstar_fcs_B.rtb_Switch_delta_q3;
  xstar_fcs_Y.Sensor_data.Vision_data.vel_xy_Ostar_OF[0] = xstar_fcs_B.mul3[0];
  xstar_fcs_Y.Sensor_data.Vision_data.vel_xy_O_OF[0] = xstar_fcs_B.mul5[0];
  xstar_fcs_Y.Sensor_data.Vision_data.vel_xy_Ostar_OF[1] = xstar_fcs_B.mul3[1];
  xstar_fcs_Y.Sensor_data.Vision_data.vel_xy_O_OF[1] = xstar_fcs_B.mul5[1];
  xstar_fcs_Y.Sensor_data.Vision_data.Vision_quality =
    xstar_fcs_B.Vision_quality;
  xstar_fcs_Y.Sensor_data.Vision_data.Vision_valid = xstar_fcs_B.Switch_i;
  xstar_fcs_Y.Sensor_data.Vision_data.delta_t = xstar_fcs_B.delta_t;
  xstar_fcs_Y.Sensor_data.Vision_data.timestamp_ms = xstar_fcs_B.timestamp_ms;
  xstar_fcs_Y.Sensor_data.Vision_data.vel_z_O_OF = xstar_fcs_B.mul5[2];
  xstar_fcs_Y.Sensor_data.Vision_data.q0 = xstar_fcs_B.q0;
  xstar_fcs_Y.Sensor_data.Vision_data.q1 = xstar_fcs_B.q1;
  xstar_fcs_Y.Sensor_data.Vision_data.q2 = xstar_fcs_B.q2;
  xstar_fcs_Y.Sensor_data.Vision_data.q3 = xstar_fcs_B.q3;
  xstar_fcs_Y.Sensor_data.Vision_data.delta_pos_x = xstar_fcs_B.Sum1;
  xstar_fcs_Y.Sensor_data.Vision_data.delta_pos_y = xstar_fcs_B.Sum1_i;
  xstar_fcs_Y.Sensor_data.Vision_data.delta_pos_z = xstar_fcs_B.delta_pos_z;
  xstar_fcs_Y.Sensor_data.Vision_data.type = xstar_fcs_B.Switch1;
  xstar_fcs_B.rtb_Product8_idx_0 = (real32_T)xstar_fcs_P.Gain1_Gain_kj *
    3.05175781E-5F;
  xstar_fcs_B.rpm[0] = xstar_fcs_B.rtb_Product8_idx_0 * (real32_T)
    xstar_fcs_U.sensors.ESC.rpm1;
  xstar_fcs_B.rpm[1] = xstar_fcs_B.rtb_Product8_idx_0 * (real32_T)
    xstar_fcs_U.sensors.ESC.rpm2;
  xstar_fcs_B.rpm[2] = xstar_fcs_B.rtb_Product8_idx_0 * (real32_T)
    xstar_fcs_U.sensors.ESC.rpm3;
  xstar_fcs_B.rpm[3] = xstar_fcs_B.rtb_Product8_idx_0 * (real32_T)
    xstar_fcs_U.sensors.ESC.rpm4;
  if (xstar_fcs_U.sensors.ESC.Timestamp_ms > xstar_fcs_DW.DelayInput1_DSTATE_f)
  {
    xstar_fcs_DW.DiscreteTimeIntegrator_DSTATE_f =
      xstar_fcs_P.DiscreteTimeIntegrator_IC_k;
  }

  if (xstar_fcs_DW.DiscreteTimeIntegrator_DSTATE_f <
      xstar_fcs_P.CompareToConstant3_const_i) {
    xstar_fcs_B.Switch = xstar_fcs_U.sensors.ESC.esc_status;
  } else {
    xstar_fcs_B.Switch = 0U;
  }

  xstar_fcs_B.status = (real32_T)xstar_fcs_U.sensors.Battery.status;
  xstar_fcs_B.Capacity = xstar_fcs_U.sensors.Battery.Capacity;
  xstar_fcs_B.Voltage = xstar_fcs_P.Gain1_Gain_f * (real32_T)
    xstar_fcs_U.sensors.Battery.Voltage;
  xstar_fcs_B.Current = (real32_T)fabs(xstar_fcs_P.Gain4_Gain_l * (real32_T)
    xstar_fcs_U.sensors.Battery.Current);
  xstar_fcs_B.Temperature = xstar_fcs_P.Gain5_Gain * (real32_T)
    xstar_fcs_U.sensors.Battery.Temperature;
  xstar_fcs_B.CycleCount = xstar_fcs_U.sensors.Battery.CycleCount;
  xstar_fcs_B.DesignCap = xstar_fcs_U.sensors.Battery.DesignCap;
  xstar_fcs_B.FullChgCap = xstar_fcs_U.sensors.Battery.FullChgCap;
  xstar_fcs_B.RSOC = xstar_fcs_U.sensors.Battery.RSOC;
  xstar_fcs_B.Cell_1_V = xstar_fcs_P.Gain10_Gain_f * (real32_T)
    xstar_fcs_U.sensors.Battery.Cell_1_V;
  xstar_fcs_B.Cell_2_V = xstar_fcs_P.Gain11_Gain_k * (real32_T)
    xstar_fcs_U.sensors.Battery.Cell_2_V;
  xstar_fcs_B.Cell_3_V = xstar_fcs_P.Gain12_Gain * (real32_T)
    xstar_fcs_U.sensors.Battery.Cell_3_V;
  xstar_fcs_B.Cell_4_V = xstar_fcs_P.Gain13_Gain * (real32_T)
    xstar_fcs_U.sensors.Battery.Cell_4_V;
  xstar_fcs_B.Cell_5_V = xstar_fcs_P.Gain14_Gain * (real32_T)
    xstar_fcs_U.sensors.Battery.Cell_5_V;
  xstar_fcs_B.Cell_6_V = xstar_fcs_P.Gain15_Gain * (real32_T)
    xstar_fcs_U.sensors.Battery.Cell_6_V;
  xstar_fcs_B.Cell_7_V = xstar_fcs_P.Gain16_Gain * (real32_T)
    xstar_fcs_U.sensors.Battery.Cell_7_V;
  xstar_fcs_B.Cell_8_V = xstar_fcs_P.Gain17_Gain * (real32_T)
    xstar_fcs_U.sensors.Battery.Cell_8_V;
  xstar_fcs_Y.Sensor_data.Battery_Data.status = xstar_fcs_B.status;
  xstar_fcs_Y.Sensor_data.Battery_Data.Capacity = xstar_fcs_B.Capacity;
  xstar_fcs_Y.Sensor_data.Battery_Data.Voltage = xstar_fcs_B.Voltage;
  xstar_fcs_Y.Sensor_data.Battery_Data.Current = xstar_fcs_B.Current;
  xstar_fcs_Y.Sensor_data.Battery_Data.Temperature = xstar_fcs_B.Temperature;
  xstar_fcs_Y.Sensor_data.Battery_Data.CycleCount = xstar_fcs_B.CycleCount;
  xstar_fcs_Y.Sensor_data.Battery_Data.DesignCap = xstar_fcs_B.DesignCap;
  xstar_fcs_Y.Sensor_data.Battery_Data.FullChgCap = xstar_fcs_B.FullChgCap;
  xstar_fcs_Y.Sensor_data.Battery_Data.RSOC = xstar_fcs_B.RSOC;
  xstar_fcs_Y.Sensor_data.Battery_Data.Cell_1_V = xstar_fcs_B.Cell_1_V;
  xstar_fcs_Y.Sensor_data.Battery_Data.Cell_2_V = xstar_fcs_B.Cell_2_V;
  xstar_fcs_Y.Sensor_data.Battery_Data.Cell_3_V = xstar_fcs_B.Cell_3_V;
  xstar_fcs_Y.Sensor_data.Battery_Data.Cell_4_V = xstar_fcs_B.Cell_4_V;
  xstar_fcs_Y.Sensor_data.Battery_Data.Cell_5_V = xstar_fcs_B.Cell_5_V;
  xstar_fcs_Y.Sensor_data.Battery_Data.Cell_6_V = xstar_fcs_B.Cell_6_V;
  xstar_fcs_Y.Sensor_data.Battery_Data.Cell_7_V = xstar_fcs_B.Cell_7_V;
  xstar_fcs_Y.Sensor_data.Battery_Data.Cell_8_V = xstar_fcs_B.Cell_8_V;
  xstar_fcs_Y.Sensor_data.Battery_Data.Timestamp_ms =
    xstar_fcs_U.sensors.Battery.Timestamp_ms;
  xstar_fcs_Y.Sensor_data.IMU_valid = xstar_fcs_B.IMU_valid;
  xstar_fcs_Y.Sensor_data.rot_IB_B_raw_radDs[0] =
    xstar_fcs_B.rot_IB_B_raw_radDs[0];
  xstar_fcs_Y.Sensor_data.sfor_R_B_mDs2[0] = xstar_fcs_B.sfor_R_B_mDs2[0];
  xstar_fcs_Y.Sensor_data.h_R_B[0] = xstar_fcs_B.Product2[0];
  xstar_fcs_Y.Sensor_data.rot_IB_B_raw_radDs[1] =
    xstar_fcs_B.rot_IB_B_raw_radDs[1];
  xstar_fcs_Y.Sensor_data.sfor_R_B_mDs2[1] = xstar_fcs_B.sfor_R_B_mDs2[1];
  xstar_fcs_Y.Sensor_data.h_R_B[1] = xstar_fcs_B.Product2[1];
  xstar_fcs_Y.Sensor_data.rot_IB_B_raw_radDs[2] =
    xstar_fcs_B.rot_IB_B_raw_radDs[2];
  xstar_fcs_Y.Sensor_data.sfor_R_B_mDs2[2] = xstar_fcs_B.sfor_R_B_mDs2[2];
  xstar_fcs_Y.Sensor_data.h_R_B[2] = xstar_fcs_B.Product2[2];
  xstar_fcs_Y.Sensor_data.Mag_Quality = xstar_fcs_B.Product4_m;
  xstar_fcs_Y.Sensor_data.magnitude_uT = xstar_fcs_B.y[0];
  xstar_fcs_Y.Sensor_data.delta_h_baro_m = xstar_fcs_B.Product1_g;
  xstar_fcs_Y.Sensor_data.baro_valid = xstar_fcs_B.LogicalOperator4;
  xstar_fcs_Y.Sensor_data.baro_Timestamp_ms = xstar_fcs_B.baro_Timestamp_ms;
  xstar_fcs_Y.Sensor_data.Heading_Quality = xstar_fcs_P.constant1_Value_c;
  xstar_fcs_Y.Sensor_data.rpm[0] = xstar_fcs_B.rpm[0];
  xstar_fcs_Y.Sensor_data.rpm[1] = xstar_fcs_B.rpm[1];
  xstar_fcs_Y.Sensor_data.rpm[2] = xstar_fcs_B.rpm[2];
  xstar_fcs_Y.Sensor_data.rpm[3] = xstar_fcs_B.rpm[3];
  xstar_fcs_Y.Sensor_data.esc_status = xstar_fcs_B.Switch;
  xstar_fcs_Y.Sys_status.Tilt_Over_flag = xstar_fcs_P.Constant5_Value_nm;
  xstar_fcs_Y.Sys_status.ground_condition = xstar_fcs_P.Constant7_Value_p;
  xstar_fcs_Y.Sys_status.On_grd = xstar_fcs_B.On_grd;
  xstar_fcs_Y.Sys_status.Armed = xstar_fcs_B.Armed_p;
  xstar_fcs_Y.Sys_status.forcedArm = xstar_fcs_P.Constant1_Value_m;
  xstar_fcs_Y.Mag_valid = xstar_fcs_B.LogicalOperator4_jz;
  xstar_fcs_Y.h_R_B_raw[0] = xstar_fcs_B.Product10[0];
  xstar_fcs_Y.h_R_B_raw[1] = xstar_fcs_B.Product10[1];
  xstar_fcs_Y.h_R_B_raw[2] = xstar_fcs_B.Product10[2];
  xstar_fcs_Y.att_init = (uint8_T)((((uint32_T)xstar_fcs_B.heading_init << 6) +
    (xstar_fcs_B.rp_init_reset ? (int32_T)xstar_fcs_P.Gain_Gain_pz2 : 0)) >> 6);
  xstar_fcs_Y.alink_rtk_location.latitude = (int32_T)floor
    (xstar_fcs_P.Gain_Gain_p * xstar_fcs_B.mue_rad);
  xstar_fcs_Y.alink_rtk_location.longitude = (int32_T)floor
    (xstar_fcs_P.Gain1_Gain * xstar_fcs_B.lambda_rad);
  xstar_fcs_Y.alink_rtk_location.altitude = (int32_T)(real32_T)floor
    (xstar_fcs_P.Gain2_Gain_p * xstar_fcs_B.GpsHeight);
  xstar_fcs_Y.alink_rtk_location.vel_X_O = (int16_T)(real32_T)floor
    (xstar_fcs_P.Gain3_Gain_d * xstar_fcs_B.Product1[0]);
  xstar_fcs_Y.alink_rtk_location.vel_Y_O = (int16_T)(real32_T)floor
    (xstar_fcs_P.Gain4_Gain_o * xstar_fcs_B.Product1[1]);
  xstar_fcs_Y.alink_rtk_location.vel_Z_O = (int16_T)(real32_T)floor
    (xstar_fcs_P.Gain5_Gain_p * xstar_fcs_B.Gain);
  xstar_fcs_Y.alink_rtk_location.pitch = (int16_T)(real32_T)floor
    (xstar_fcs_P.Gain6_Gain_h * xstar_fcs_B.theta_rad);
  xstar_fcs_Y.alink_rtk_location.roll = (int16_T)(real32_T)floor
    (xstar_fcs_P.Gain7_Gain_a * xstar_fcs_B.phi_rad);
  xstar_fcs_Y.alink_rtk_location.yaw = (int16_T)(real32_T)floor
    (xstar_fcs_P.Gain8_Gain_d * xstar_fcs_B.Psi_star_rad);
  xstar_fcs_Y.alink_rtk_location.yaw_rate = (int16_T)(real32_T)floor
    (xstar_fcs_P.Gain11_Gain_h * xstar_fcs_B.yaw_mag);
  xstar_fcs_Y.alink_rtk_location.ant_heading = (int16_T)(real32_T)floor
    (xstar_fcs_P.Gain10_Gain_h * xstar_fcs_B.ant_heading);
  xstar_fcs_Y.alink_rtk_location.reserve = (int16_T)
    ((((xstar_fcs_B.LogicalOperator ? (int32_T)((uint32_T)
         xstar_fcs_P.Gain12_Gain_m >> 6) : 0) + xstar_fcs_B.Armed_p) *
      xstar_fcs_P.Gain9_Gain_b) >> 14);
  xstar_fcs_Y.alink_rtk_location.pos_type = (uint8_T)xstar_fcs_B.pos_type_m;
  xstar_fcs_Y.alink_rtk_location.pos_stat = (uint8_T)xstar_fcs_B.sol_s_pos;
  xstar_fcs_Y.alink_rtk_location.vel_type = (uint8_T)xstar_fcs_B.vel_type;
  xstar_fcs_Y.alink_rtk_location.vel_stat = (uint8_T)xstar_fcs_B.sol_s_vel;
  xstar_fcs_Y.GPS_logic_log.Status = xstar_fcs_B.Status_d;
  xstar_fcs_Y.GPS_logic_log.Ts_Update = xstar_fcs_B.Ts_Update;
  xstar_fcs_Y.GPS_logic_log.En_GPS_cor_core = xstar_fcs_B.En_GPS_cor_core;
  xstar_fcs_Y.GPS_logic_log.En_GPS_Valid = xstar_fcs_B.En_GPS_Valid;
  xstar_fcs_Y.GPS_logic_log.En_GPS_Correct_RTK = xstar_fcs_B.En_GPS_Correct_RTK;
  xstar_fcs_Y.Vx_cor = xstar_fcs_DW.DiscreteTimeIntegrator1_DSTA_hy;
  xstar_fcs_B.sample_sum_a = xstar_fcs_DW.DiscreteTimeIntegrator_DSTATE_j;
  xstar_fcs_B.MathFunction_g = xstar_fcs_P.Gain1_Gain_fo *
    xstar_fcs_DW.DiscreteTimeIntegrator_DSTATE_j;
  xstar_fcs_B.Gain_p = (xstar_fcs_B.Translation_Fusion_o28 -
                        xstar_fcs_DW.DiscreteTimeIntegrator1_DSTA_hy) *
    xstar_fcs_P.Gain_Gain_cx;
  xstar_fcs_B.POS_reset_signal_k = xstar_fcs_DW.Memory1_11_PreviousInput;
  xstar_fcs_B.mue_est_rad_fc_d = xstar_fcs_DW.Memory1_14_PreviousInput;
  xstar_fcs_B.lambda_est_rad_fc_g = xstar_fcs_DW.Memory1_15_PreviousInput;
  xstar_fcs_B.h_AGL_m_n = xstar_fcs_DW.Memory1_2_PreviousInput;
  xstar_fcs_B.h_0_AGL_m_m = xstar_fcs_DW.Memory1_3_PreviousInput;
  xstar_fcs_B.delta_h_m_g = xstar_fcs_DW.Memory1_4_PreviousInput;
  xstar_fcs_B.Bias_z_mDs2_g = xstar_fcs_DW.Memory1_5_PreviousInput;
  xstar_fcs_B.POS_xy_O_m_c[0] = xstar_fcs_DW.Memory1_10_PreviousInput[0];
  xstar_fcs_B.VEL_xy_O_mDs_i[0] = xstar_fcs_DW.Memory1_6_PreviousInput[0];
  xstar_fcs_B.ACC_xy_O_mDs[0] = xstar_fcs_DW.Memory1_7_PreviousInput[0];
  xstar_fcs_B.POS_xy_O_m_c[1] = xstar_fcs_DW.Memory1_10_PreviousInput[1];
  xstar_fcs_B.VEL_xy_O_mDs_i[1] = xstar_fcs_DW.Memory1_6_PreviousInput[1];
  xstar_fcs_B.ACC_xy_O_mDs[1] = xstar_fcs_DW.Memory1_7_PreviousInput[1];
  xstar_fcs_B.mue_est_rad_b = xstar_fcs_DW.Memory1_8_PreviousInput;
  xstar_fcs_B.lambda_est_rad_o = xstar_fcs_DW.Memory1_9_PreviousInput;
  xstar_fcs_B.DiscreteTimeIntegrator_b =
    xstar_fcs_DW.DiscreteTimeIntegrator_DSTATE_b;
  xstar_fcs_B.Gain1_g = xstar_fcs_P.Gain1_Gain_i *
    xstar_fcs_DW.DiscreteTimeIntegrator_DSTATE_b;
  if (xstar_fcs_U.sensors.RTK_Base.Timestamp_ms_vel !=
      xstar_fcs_DW.DelayInput1_DSTATE_li) {
    xstar_fcs_DW.DiscreteTimeIntegrator_DSTAT_jd =
      xstar_fcs_P.DiscreteTimeIntegrator_IC_l;
  }

  mw_arm_sqrt_f32((xstar_fcs_U.sensors.RTK_Base.Vx_stddev *
                   xstar_fcs_U.sensors.RTK_Base.Vx_stddev +
                   xstar_fcs_U.sensors.RTK_Base.Vy_stddev *
                   xstar_fcs_U.sensors.RTK_Base.Vy_stddev) +
                  xstar_fcs_U.sensors.RTK_Base.Vz_stddev *
                  xstar_fcs_U.sensors.RTK_Base.Vz_stddev,
                  &xstar_fcs_B.DiscreteTimeIntegrator1_i);
  xstar_fcs_B.DiscreteTimeIntegrator1_i = (xstar_fcs_P.Constant7_Value_j -
    xstar_fcs_B.DiscreteTimeIntegrator1_i) * xstar_fcs_P.Gain3_Gain_o;
  if (xstar_fcs_B.DiscreteTimeIntegrator1_i > xstar_fcs_P.Saturation_UpperSat_kw)
  {
    xstar_fcs_B.DiscreteTimeIntegrator1_i = xstar_fcs_P.Saturation_UpperSat_kw;
  } else {
    if (xstar_fcs_B.DiscreteTimeIntegrator1_i <
        xstar_fcs_P.Saturation_LowerSat_k) {
      xstar_fcs_B.DiscreteTimeIntegrator1_i = xstar_fcs_P.Saturation_LowerSat_k;
    }
  }

  xstar_fcs_B.DiscreteTimeIntegrator2_oo = (real32_T)
    (xstar_fcs_DW.DiscreteTimeIntegrator_DSTAT_jd <
     xstar_fcs_P.CompareToConstant4_const_b) *
    xstar_fcs_B.DiscreteTimeIntegrator1_i * (real32_T)
    ((xstar_fcs_U.sensors.RTK_Base.vel_type ==
      xstar_fcs_P.CompareToConstant2_const_gs) >
     xstar_fcs_P.CompareToConstant1_const_ap);
  if (xstar_fcs_DW.DiscreteTimeIntegrator1_IC_LO_g != 0) {
    xstar_fcs_DW.DiscreteTimeIntegrator1_DSTAT_f =
      xstar_fcs_B.DiscreteTimeIntegrator2_oo;
  }

  xstar_fcs_B.DiscreteTimeIntegrator1_i =
    (xstar_fcs_DW.DiscreteTimeIntegrator1_DSTAT_f -
     xstar_fcs_B.DiscreteTimeIntegrator1) * xstar_fcs_P.Gain_Gain_am;
  xstar_fcs_B.DiscreteTimeIntegrator2_oo -=
    xstar_fcs_DW.DiscreteTimeIntegrator1_DSTAT_f;
  if (xstar_fcs_B.DiscreteTimeIntegrator2_oo > xstar_fcs_P.Switch_Threshold_j) {
    xstar_fcs_B.rtb_Product8_idx_0 = xstar_fcs_P.Ascendanddescendtracking_Tc_asc;
  } else {
    xstar_fcs_B.rtb_Product8_idx_0 = xstar_fcs_P.Ascendanddescendtracking_Tc_des;
  }

  xstar_fcs_B.Product_cm = xstar_fcs_B.DiscreteTimeIntegrator2_oo /
    xstar_fcs_B.rtb_Product8_idx_0;
  mw_arm_sqrt_f32(xstar_fcs_B.rtb_Mag_Q_idx_0 * xstar_fcs_B.rtb_Mag_Q_idx_0 +
                  xstar_fcs_B.Add_n * xstar_fcs_B.Add_n,
                  &xstar_fcs_B.DiscreteTimeIntegrator2_oo);
  xstar_fcs_B.UnitDelay += ((xstar_fcs_B.DiscreteTimeIntegrator2_oo <
    xstar_fcs_P.CompareToConstant_const_pb) && (xstar_fcs_B.Compare_d != 0));
  if (xstar_fcs_B.UnitDelay > xstar_fcs_P.Saturation_UpperSat_d) {
    xstar_fcs_B.UnitDelay = xstar_fcs_P.Saturation_UpperSat_d;
  } else {
    if (xstar_fcs_B.UnitDelay < xstar_fcs_P.Saturation_LowerSat_m) {
      xstar_fcs_B.UnitDelay = xstar_fcs_P.Saturation_LowerSat_m;
    }
  }

  if (xstar_fcs_B.FixPtRelationalOperator_n1 &&
      xstar_fcs_B.FixPtRelationalOperator_fv &&
      xstar_fcs_B.FixPtRelationalOperator_fs &&
      xstar_fcs_B.FixPtRelationalOperator_d0 &&
      xstar_fcs_B.FixPtRelationalOperator_kg &&
      xstar_fcs_B.FixPtRelationalOperator_ks &&
      xstar_fcs_B.FixPtRelationalOperator_kt &&
      xstar_fcs_B.FixPtRelationalOperator_e) {
    xstar_fcs_DW.DiscreteTimeIntegrator2_DSTAT_p =
      xstar_fcs_P.DiscreteTimeIntegrator2_IC_au;
  }

  xstar_fcs_B.LogicalOperator18 = (xstar_fcs_B.LogicalOperator18 &&
    xstar_fcs_B.LogicalOperator13 &&
    (xstar_fcs_DW.DiscreteTimeIntegrator2_DSTAT_p <
     xstar_fcs_P.Subsystem3_time_judge_in_air));
  xstar_fcs_B.FixPtRelationalOperator_fv = !xstar_fcs_B.Rotation_AHRS_GPS_o27;
  if (xstar_fcs_B.FixPtRelationalOperator_fv ||
      (xstar_fcs_DW.DiscreteTimeIntegrator_PrevRe_i != 0)) {
    xstar_fcs_DW.DiscreteTimeIntegrator_DSTAT_b0 =
      xstar_fcs_P.DiscreteTimeIntegrator_IC_n;
  }

  if (xstar_fcs_DW.DiscreteTimeIntegrator_DSTAT_b0 >=
      xstar_fcs_P.DiscreteTimeIntegrator_UpperSat) {
    xstar_fcs_DW.DiscreteTimeIntegrator_DSTAT_b0 =
      xstar_fcs_P.DiscreteTimeIntegrator_UpperSat;
  } else {
    if (xstar_fcs_DW.DiscreteTimeIntegrator_DSTAT_b0 <=
        xstar_fcs_P.DiscreteTimeIntegrator_LowerSat) {
      xstar_fcs_DW.DiscreteTimeIntegrator_DSTAT_b0 =
        xstar_fcs_P.DiscreteTimeIntegrator_LowerSat;
    }
  }

  xstar_fcs_B.FixPtRelationalOperator_d0 = (xstar_fcs_B.LogicalOperator18 &&
    (xstar_fcs_DW.DiscreteTimeIntegrator_DSTAT_b0 >
     xstar_fcs_P.Validaperiod1_T_p) && xstar_fcs_DW.Delay3_DSTATE_n);
  if (xstar_fcs_B.FixPtRelationalOperator_d0 &&
      (xstar_fcs_PrevZCX.Delay1_Reset_ZCE != POS_ZCSIG)) {
    xstar_fcs_DW.icLoad = 1U;
  }

  xstar_fcs_PrevZCX.Delay1_Reset_ZCE = xstar_fcs_B.FixPtRelationalOperator_d0;
  if (xstar_fcs_DW.icLoad != 0) {
    xstar_fcs_DW.Delay1_DSTATE_e[0] = xstar_fcs_DW.Delay8_DSTATE[0];
    xstar_fcs_DW.Delay1_DSTATE_e[1] = xstar_fcs_DW.Delay8_DSTATE[1];
    xstar_fcs_DW.Delay1_DSTATE_e[2] = xstar_fcs_DW.Delay8_DSTATE[2];
  }

  xstar_fcs_B.rtb_Product8_idx_0 = xstar_fcs_DW.Delay1_DSTATE_e[0];
  xstar_fcs_B.rtb_v_idx_0 = xstar_fcs_DW.Delay2_DSTATE_k[0];
  xstar_fcs_B.rtb_Product8_idx_1 = xstar_fcs_DW.Delay1_DSTATE_e[1];
  xstar_fcs_B.rtb_v_idx_1 = xstar_fcs_DW.Delay2_DSTATE_k[1];
  xstar_fcs_B.rtb_Product8_idx_2 = xstar_fcs_DW.Delay1_DSTATE_e[2];
  xstar_fcs_B.rtb_v_idx_2 = xstar_fcs_DW.Delay2_DSTATE_k[2];
  if (xstar_fcs_B.FixPtRelationalOperator_fv ||
      (xstar_fcs_DW.DiscreteTimeIntegrator_PrevRe_o != 0)) {
    xstar_fcs_DW.DiscreteTimeIntegrator_DSTAT_hp =
      xstar_fcs_P.DiscreteTimeIntegrator_IC_mz;
  }

  if (xstar_fcs_DW.DiscreteTimeIntegrator_DSTAT_hp >=
      xstar_fcs_P.DiscreteTimeIntegrator_UpperS_l) {
    xstar_fcs_DW.DiscreteTimeIntegrator_DSTAT_hp =
      xstar_fcs_P.DiscreteTimeIntegrator_UpperS_l;
  } else {
    if (xstar_fcs_DW.DiscreteTimeIntegrator_DSTAT_hp <=
        xstar_fcs_P.DiscreteTimeIntegrator_LowerS_a) {
      xstar_fcs_DW.DiscreteTimeIntegrator_DSTAT_hp =
        xstar_fcs_P.DiscreteTimeIntegrator_LowerS_a;
    }
  }

  xstar_fcs_B.FixPtRelationalOperator_n1 =
    (xstar_fcs_DW.DiscreteTimeIntegrator_DSTAT_hp > xstar_fcs_P.Validaperiod_T_p);
  if (xstar_fcs_B.FixPtRelationalOperator_n1) {
    xstar_fcs_DW.icLoad_p = 1U;
  }

  if (xstar_fcs_DW.icLoad_p != 0) {
    xstar_fcs_DW.Delay4_DSTATE[0] = xstar_fcs_DW.Delay3_DSTATE[0];
    xstar_fcs_DW.Delay4_DSTATE[1] = xstar_fcs_DW.Delay3_DSTATE[1];
    xstar_fcs_DW.Delay4_DSTATE[2] = xstar_fcs_DW.Delay3_DSTATE[2];
  }

  xstar_fcs_B.Product2_h[0] = xstar_fcs_DW.Delay4_DSTATE[0];
  xstar_fcs_B.Product2_h[1] = xstar_fcs_DW.Delay4_DSTATE[1];
  xstar_fcs_B.Product2_h[2] = xstar_fcs_DW.Delay4_DSTATE[2];
  if (xstar_fcs_B.FixPtRelationalOperator_fv ||
      (xstar_fcs_DW.DiscreteTimeIntegrator_PrevR_iy != 0)) {
    xstar_fcs_DW.DiscreteTimeIntegrator_DSTATE_k =
      xstar_fcs_P.DiscreteTimeIntegrator_IC_b3;
  }

  if (xstar_fcs_DW.DiscreteTimeIntegrator_DSTATE_k >=
      xstar_fcs_P.DiscreteTimeIntegrator_UpperS_k) {
    xstar_fcs_DW.DiscreteTimeIntegrator_DSTATE_k =
      xstar_fcs_P.DiscreteTimeIntegrator_UpperS_k;
  } else {
    if (xstar_fcs_DW.DiscreteTimeIntegrator_DSTATE_k <=
        xstar_fcs_P.DiscreteTimeIntegrator_LowerS_g) {
      xstar_fcs_DW.DiscreteTimeIntegrator_DSTATE_k =
        xstar_fcs_P.DiscreteTimeIntegrator_LowerS_g;
    }
  }

  if (xstar_fcs_DW.DiscreteTimeIntegrator_DSTATE_k >
      xstar_fcs_P.Validaperiod2_T_p) {
    xstar_fcs_DW.icLoad_pg = 1U;
  }

  if (xstar_fcs_DW.icLoad_pg != 0) {
    xstar_fcs_DW.Delay5_DSTATE[0] = xstar_fcs_DW.Delay6_DSTATE[0];
    xstar_fcs_DW.Delay5_DSTATE[1] = xstar_fcs_DW.Delay6_DSTATE[1];
    xstar_fcs_DW.Delay5_DSTATE[2] = xstar_fcs_DW.Delay6_DSTATE[2];
  }

  xstar_fcs_B.rtb_Product9_idx_0 = xstar_fcs_DW.Delay5_DSTATE[0];
  xstar_fcs_B.rtb_Product9_idx_1 = xstar_fcs_DW.Delay5_DSTATE[1];
  xstar_fcs_B.DiscreteTimeIntegrator2_oo = xstar_fcs_DW.Delay5_DSTATE[2];
  if (xstar_fcs_B.Rotation_AHRS_GPS_o27) {
    if (!xstar_fcs_DW.GyroBiasEstimation_MODE) {
      xstar_fcs_DW.DiscreteTimeIntegrator_IC_LOA_p = 1U;
      xstar_fcs_MovingAverage2_Reset(&xstar_fcs_DW.MovingAverage);
      xstar_fcs_MovingAverage2_Reset(&xstar_fcs_DW.MovingAverage1);
      xstar_fcs_MovingAverage2_Reset(&xstar_fcs_DW.MovingAverage2);
      xstar_fcs_DW.GyroBiasEstimation_MODE = true;
    }

    if (xstar_fcs_DW.DiscreteTimeIntegrator_IC_LOA_p != 0) {
      xstar_fcs_DW.DiscreteTimeIntegrator_DSTAT_ge[0] =
        xstar_fcs_B.rot_IB_B_raw_radDs2[0];
      xstar_fcs_DW.DiscreteTimeIntegrator_DSTAT_ge[1] =
        xstar_fcs_B.rot_IB_B_raw_radDs2[1];
      xstar_fcs_DW.DiscreteTimeIntegrator_DSTAT_ge[2] =
        xstar_fcs_B.rot_IB_B_raw_radDs2[2];
    }

    xstar_fcs_B.DiscreteTimeIntegrator_dj[0] =
      xstar_fcs_DW.DiscreteTimeIntegrator_DSTAT_ge[0];
    xstar_fcs_B.DiscreteTimeIntegrator_dj[1] =
      xstar_fcs_DW.DiscreteTimeIntegrator_DSTAT_ge[1];
    xstar_fcs_B.DiscreteTimeIntegrator_dj[2] =
      xstar_fcs_DW.DiscreteTimeIntegrator_DSTAT_ge[2];
    xstar_fcs_MovingAverage2(xstar_fcs_B.DiscreteTimeIntegrator_dj[0],
      &xstar_fcs_B.MovingAverage, &xstar_fcs_DW.MovingAverage);
    xstar_fcs_MovingAverage2(xstar_fcs_B.DiscreteTimeIntegrator_dj[1],
      &xstar_fcs_B.MovingAverage1, &xstar_fcs_DW.MovingAverage1);
    xstar_fcs_MovingAverage2(xstar_fcs_B.DiscreteTimeIntegrator_dj[2],
      &xstar_fcs_B.MovingAverage2, &xstar_fcs_DW.MovingAverage2);
    xstar_fcs_DW.DiscreteTimeIntegrator_IC_LOA_p = 0U;
    xstar_fcs_DW.DiscreteTimeIntegrator_DSTAT_ge[0] +=
      (xstar_fcs_B.rot_IB_B_raw_radDs2[0] -
       xstar_fcs_B.DiscreteTimeIntegrator_dj[0]) * xstar_fcs_P.Gain_Gain_g *
      xstar_fcs_P.DiscreteTimeIntegrator_gainval;
    xstar_fcs_DW.DiscreteTimeIntegrator_DSTAT_ge[1] +=
      (xstar_fcs_B.rot_IB_B_raw_radDs2[1] -
       xstar_fcs_B.DiscreteTimeIntegrator_dj[1]) * xstar_fcs_P.Gain_Gain_g *
      xstar_fcs_P.DiscreteTimeIntegrator_gainval;
    xstar_fcs_DW.DiscreteTimeIntegrator_DSTAT_ge[2] +=
      (xstar_fcs_B.rot_IB_B_raw_radDs2[2] -
       xstar_fcs_B.DiscreteTimeIntegrator_dj[2]) * xstar_fcs_P.Gain_Gain_g *
      xstar_fcs_P.DiscreteTimeIntegrator_gainval;
  } else {
    if (xstar_fcs_DW.GyroBiasEstimation_MODE) {
      xstar_fcs_DW.GyroBiasEstimation_MODE = false;
    }
  }

  if (xstar_fcs_B.LogicalOperator18 && xstar_fcs_B.Rotation_AHRS_GPS_o27) {
    if (!xstar_fcs_DW.GyroBiasEstimation1_MODE) {
      xstar_fcs_DW.DiscreteTimeIntegrator_IC_LOA_e = 1U;
      xstar_fcs_MovingAverage2_Reset(&xstar_fcs_DW.MovingAverage_p);
      xstar_fcs_MovingAverage2_Reset(&xstar_fcs_DW.MovingAverage1_p);
      xstar_fcs_MovingAverage2_Reset(&xstar_fcs_DW.MovingAverage2_p);
      xstar_fcs_DW.GyroBiasEstimation1_MODE = true;
    }

    if (xstar_fcs_DW.DiscreteTimeIntegrator_IC_LOA_e != 0) {
      xstar_fcs_DW.DiscreteTimeIntegrator_DSTATE_g[0] = xstar_fcs_B.rtb_v_idx_0;
      xstar_fcs_DW.DiscreteTimeIntegrator_DSTATE_g[1] = xstar_fcs_B.rtb_v_idx_1;
      xstar_fcs_DW.DiscreteTimeIntegrator_DSTATE_g[2] = xstar_fcs_B.rtb_v_idx_2;
    }

    xstar_fcs_B.DiscreteTimeIntegrator_id[0] =
      xstar_fcs_DW.DiscreteTimeIntegrator_DSTATE_g[0];
    xstar_fcs_B.DiscreteTimeIntegrator_id[1] =
      xstar_fcs_DW.DiscreteTimeIntegrator_DSTATE_g[1];
    xstar_fcs_B.DiscreteTimeIntegrator_id[2] =
      xstar_fcs_DW.DiscreteTimeIntegrator_DSTATE_g[2];
    xstar_fcs_MovingAverage2(xstar_fcs_B.DiscreteTimeIntegrator_id[0],
      &xstar_fcs_B.MovingAverage_p, &xstar_fcs_DW.MovingAverage_p);
    xstar_fcs_MovingAverage2(xstar_fcs_B.DiscreteTimeIntegrator_id[1],
      &xstar_fcs_B.MovingAverage1_p, &xstar_fcs_DW.MovingAverage1_p);
    xstar_fcs_MovingAverage2(xstar_fcs_B.DiscreteTimeIntegrator_id[2],
      &xstar_fcs_B.MovingAverage2_p, &xstar_fcs_DW.MovingAverage2_p);
    xstar_fcs_DW.DiscreteTimeIntegrator_IC_LOA_e = 0U;
    xstar_fcs_DW.DiscreteTimeIntegrator_DSTATE_g[0] += (xstar_fcs_B.rtb_v_idx_0
      - xstar_fcs_B.DiscreteTimeIntegrator_id[0]) * xstar_fcs_P.Gain_Gain_c *
      xstar_fcs_P.DiscreteTimeIntegrator_gainva_n;
    xstar_fcs_DW.DiscreteTimeIntegrator_DSTATE_g[1] += (xstar_fcs_B.rtb_v_idx_1
      - xstar_fcs_B.DiscreteTimeIntegrator_id[1]) * xstar_fcs_P.Gain_Gain_c *
      xstar_fcs_P.DiscreteTimeIntegrator_gainva_n;
    xstar_fcs_DW.DiscreteTimeIntegrator_DSTATE_g[2] += (xstar_fcs_B.rtb_v_idx_2
      - xstar_fcs_B.DiscreteTimeIntegrator_id[2]) * xstar_fcs_P.Gain_Gain_c *
      xstar_fcs_P.DiscreteTimeIntegrator_gainva_n;
  } else {
    if (xstar_fcs_DW.GyroBiasEstimation1_MODE) {
      xstar_fcs_DW.GyroBiasEstimation1_MODE = false;
    }
  }

  if (xstar_fcs_B.Rotation_AHRS_GPS_o27) {
    if (xstar_fcs_DW.DiscreteTimeIntegrator_IC_LOADI != 0) {
      xstar_fcs_DW.DiscreteTimeIntegrator_DSTAT_dv[0] =
        xstar_fcs_B.rot_IB_B_raw_radDs1[0];
      xstar_fcs_DW.DiscreteTimeIntegrator_DSTAT_dv[1] =
        xstar_fcs_B.rot_IB_B_raw_radDs1[1];
      xstar_fcs_DW.DiscreteTimeIntegrator_DSTAT_dv[2] =
        xstar_fcs_B.rot_IB_B_raw_radDs1[2];
    }

    xstar_fcs_B.DiscreteTimeIntegrator_er[0] =
      xstar_fcs_DW.DiscreteTimeIntegrator_DSTAT_dv[0];
    xstar_fcs_B.DiscreteTimeIntegrator_er[1] =
      xstar_fcs_DW.DiscreteTimeIntegrator_DSTAT_dv[1];
    xstar_fcs_B.DiscreteTimeIntegrator_er[2] =
      xstar_fcs_DW.DiscreteTimeIntegrator_DSTAT_dv[2];
    xstar_fcs_MovingAverage2(xstar_fcs_B.DiscreteTimeIntegrator_er[0],
      &xstar_fcs_B.MovingAverage_pn, &xstar_fcs_DW.MovingAverage_pn);
    xstar_fcs_MovingAverage2(xstar_fcs_B.DiscreteTimeIntegrator_er[1],
      &xstar_fcs_B.MovingAverage1_pn, &xstar_fcs_DW.MovingAverage1_pn);
    xstar_fcs_MovingAverage2(xstar_fcs_B.DiscreteTimeIntegrator_er[2],
      &xstar_fcs_B.MovingAverage2_pn, &xstar_fcs_DW.MovingAverage2_pn);
    xstar_fcs_DW.DiscreteTimeIntegrator_IC_LOADI = 0U;
    xstar_fcs_DW.DiscreteTimeIntegrator_DSTAT_dv[0] +=
      (xstar_fcs_B.rot_IB_B_raw_radDs1[0] -
       xstar_fcs_B.DiscreteTimeIntegrator_er[0]) * xstar_fcs_P.Gain_Gain_k *
      xstar_fcs_P.DiscreteTimeIntegrator_gainva_p;
    xstar_fcs_DW.DiscreteTimeIntegrator_DSTAT_dv[1] +=
      (xstar_fcs_B.rot_IB_B_raw_radDs1[1] -
       xstar_fcs_B.DiscreteTimeIntegrator_er[1]) * xstar_fcs_P.Gain_Gain_k *
      xstar_fcs_P.DiscreteTimeIntegrator_gainva_p;
    xstar_fcs_DW.DiscreteTimeIntegrator_DSTAT_dv[2] +=
      (xstar_fcs_B.rot_IB_B_raw_radDs1[2] -
       xstar_fcs_B.DiscreteTimeIntegrator_er[2]) * xstar_fcs_P.Gain_Gain_k *
      xstar_fcs_P.DiscreteTimeIntegrator_gainva_p;
  }

  mw_arm_sqrt_f32(((xstar_fcs_B.fcn3 * xstar_fcs_B.fcn3 +
                    xstar_fcs_B.Product1_g_b * xstar_fcs_B.Product1_g_b) +
                   xstar_fcs_B.Product2_mi * xstar_fcs_B.Product2_mi) +
                  xstar_fcs_B.Product3_l * xstar_fcs_B.Product3_l,
                  &xstar_fcs_B.f0);
  xstar_fcs_B.DataTypeConversion -= xstar_fcs_B.DiscreteTimeIntegrator1_m;
  if (xstar_fcs_B.DataTypeConversion > xstar_fcs_P.Switch_Threshold_e) {
    xstar_fcs_B.rtb_DataTypeConversion_j =
      xstar_fcs_P.Ascendanddescendtracking_Tc_a_e;
  } else {
    xstar_fcs_B.rtb_DataTypeConversion_j =
      xstar_fcs_P.Ascendanddescendtracking_Tc_d_l;
  }

  xstar_fcs_B.Product2_mi = xstar_fcs_B.DataTypeConversion /
    xstar_fcs_B.rtb_DataTypeConversion_j;
  if (xstar_fcs_P.DirectionCosineMatrixtoQuaterni != 1.0) {
    xstar_fcs_IfWarningError(xstar_fcs_B.M_OB, &xstar_fcs_P.IfWarningError,
      xstar_fcs_P.DirectionCosineMatrixtoQuaterni,
      xstar_fcs_P.DirectionCosineMatrixtoQuater_e);
  }

  xstar_fcs_B.Add_n = (xstar_fcs_B.M_OB[0] + xstar_fcs_B.M_OB[4]) +
    xstar_fcs_B.M_OB[8];
  if (xstar_fcs_B.Add_n > 0.0F) {
    mw_arm_sqrt_f32(xstar_fcs_B.Add_n + xstar_fcs_P.Constant_Value_m,
                    &xstar_fcs_B.Add_n);
    xstar_fcs_B.Merge[0] = xstar_fcs_P.Gain_Gain_i * xstar_fcs_B.Add_n;
    xstar_fcs_B.Add_n *= xstar_fcs_P.Gain1_Gain_m;
    xstar_fcs_B.Merge[1] = (xstar_fcs_B.M_OB[7] - xstar_fcs_B.M_OB[5]) /
      xstar_fcs_B.Add_n;
    xstar_fcs_B.Merge[2] = (xstar_fcs_B.M_OB[2] - xstar_fcs_B.M_OB[6]) /
      xstar_fcs_B.Add_n;
    xstar_fcs_B.Merge[3] = (xstar_fcs_B.M_OB[3] - xstar_fcs_B.M_OB[1]) /
      xstar_fcs_B.Add_n;
  } else if ((xstar_fcs_B.M_OB[4] > xstar_fcs_B.M_OB[0]) && (xstar_fcs_B.M_OB[4]
              > xstar_fcs_B.M_OB[8])) {
    mw_arm_sqrt_f32(((xstar_fcs_B.M_OB[4] - xstar_fcs_B.M_OB[0]) -
                     xstar_fcs_B.M_OB[8]) + xstar_fcs_P.Constant_Value_d,
                    &xstar_fcs_B.Add_n);
    xstar_fcs_B.Merge[2] = xstar_fcs_P.Gain_Gain_l * xstar_fcs_B.Add_n;
    if (xstar_fcs_B.Add_n != 0.0F) {
      xstar_fcs_B.rtb_Mag_Q_idx_0 = xstar_fcs_P.Constant1_Value;
    } else {
      xstar_fcs_B.rtb_Mag_Q_idx_0 = xstar_fcs_P.Constant2_Value[0];
      xstar_fcs_B.Add_n = xstar_fcs_P.Constant2_Value[1];
    }

    xstar_fcs_B.Add_n = xstar_fcs_B.rtb_Mag_Q_idx_0 / xstar_fcs_B.Add_n;
    xstar_fcs_B.Merge[1] = (xstar_fcs_B.M_OB[1] + xstar_fcs_B.M_OB[3]) *
      xstar_fcs_B.Add_n * xstar_fcs_P.Gain1_Gain_l;
    xstar_fcs_B.Merge[3] = (xstar_fcs_B.M_OB[5] + xstar_fcs_B.M_OB[7]) *
      xstar_fcs_B.Add_n * xstar_fcs_P.Gain3_Gain;
    xstar_fcs_B.Merge[0] = (xstar_fcs_B.M_OB[2] - xstar_fcs_B.M_OB[6]) *
      xstar_fcs_B.Add_n * xstar_fcs_P.Gain4_Gain;
  } else if (xstar_fcs_B.M_OB[8] > xstar_fcs_B.M_OB[0]) {
    mw_arm_sqrt_f32(((xstar_fcs_B.M_OB[8] - xstar_fcs_B.M_OB[0]) -
                     xstar_fcs_B.M_OB[4]) + xstar_fcs_P.Constant_Value_l,
                    &xstar_fcs_B.Add_n);
    xstar_fcs_B.Merge[3] = xstar_fcs_P.Gain_Gain_b * xstar_fcs_B.Add_n;
    if (xstar_fcs_B.Add_n != 0.0F) {
      xstar_fcs_B.rtb_Mag_Q_idx_0 = xstar_fcs_P.Constant1_Value_g;
    } else {
      xstar_fcs_B.rtb_Mag_Q_idx_0 = xstar_fcs_P.Constant2_Value_l[0];
      xstar_fcs_B.Add_n = xstar_fcs_P.Constant2_Value_l[1];
    }

    xstar_fcs_B.Add_n = xstar_fcs_B.rtb_Mag_Q_idx_0 / xstar_fcs_B.Add_n;
    xstar_fcs_B.Merge[1] = (xstar_fcs_B.M_OB[2] + xstar_fcs_B.M_OB[6]) *
      xstar_fcs_B.Add_n * xstar_fcs_P.Gain1_Gain_mu;
    xstar_fcs_B.Merge[2] = (xstar_fcs_B.M_OB[5] + xstar_fcs_B.M_OB[7]) *
      xstar_fcs_B.Add_n * xstar_fcs_P.Gain2_Gain_k;
    xstar_fcs_B.Merge[0] = (xstar_fcs_B.M_OB[3] - xstar_fcs_B.M_OB[1]) *
      xstar_fcs_B.Add_n * xstar_fcs_P.Gain3_Gain_l;
  } else {
    mw_arm_sqrt_f32(((xstar_fcs_B.M_OB[0] - xstar_fcs_B.M_OB[4]) -
                     xstar_fcs_B.M_OB[8]) + xstar_fcs_P.Constant_Value_k,
                    &xstar_fcs_B.Add_n);
    xstar_fcs_B.Merge[1] = xstar_fcs_P.Gain_Gain_k1 * xstar_fcs_B.Add_n;
    if (xstar_fcs_B.Add_n != 0.0F) {
      xstar_fcs_B.rtb_Mag_Q_idx_0 = xstar_fcs_P.Constant1_Value_e;
    } else {
      xstar_fcs_B.rtb_Mag_Q_idx_0 = xstar_fcs_P.Constant2_Value_d[0];
      xstar_fcs_B.Add_n = xstar_fcs_P.Constant2_Value_d[1];
    }

    xstar_fcs_B.Add_n = xstar_fcs_B.rtb_Mag_Q_idx_0 / xstar_fcs_B.Add_n;
    xstar_fcs_B.Merge[2] = (xstar_fcs_B.M_OB[1] + xstar_fcs_B.M_OB[3]) *
      xstar_fcs_B.Add_n * xstar_fcs_P.Gain1_Gain_g;
    xstar_fcs_B.Merge[3] = (xstar_fcs_B.M_OB[2] + xstar_fcs_B.M_OB[6]) *
      xstar_fcs_B.Add_n * xstar_fcs_P.Gain2_Gain_of;
    xstar_fcs_B.Merge[0] = (xstar_fcs_B.M_OB[7] - xstar_fcs_B.M_OB[5]) *
      xstar_fcs_B.Add_n * xstar_fcs_P.Gain3_Gain_e;
  }

  xstar_fcs_B.Selector1[0] = xstar_fcs_B.M_OB[2];
  xstar_fcs_B.Selector1[1] = xstar_fcs_B.M_OB[5];
  xstar_fcs_B.Selector1[2] = xstar_fcs_B.M_OB[8];
  if (xstar_fcs_P.DirectionCosineMatrixtoRotation != 1.0) {
    xstar_fcs_IfWarningError(xstar_fcs_B.VectorConcatenate_l,
      &xstar_fcs_P.IfWarningError_n, xstar_fcs_P.DirectionCosineMatrixtoRotation,
      xstar_fcs_P.DirectionCosineMatrixtoRotati_b);
  }

  xstar_fcs_B.DataTypeConversion = (real32_T)(xstar_fcs_B.Compare_gw &&
    xstar_fcs_B.Compare_ot) - xstar_fcs_B.DiscreteTimeIntegrator3_n;
  xstar_fcs_B.DiscreteTimeIntegrator3_n = (xstar_fcs_B.h_AGL_m -
    xstar_fcs_DW.DiscreteTimeIntegrator5_DSTAT_k) * xstar_fcs_P.Gain2_Gain_kj;
  xstar_fcs_B.Delay_d = (xstar_fcs_B.Delay_d -
    xstar_fcs_DW.DiscreteTimeIntegrator5_DSTA_k1) * xstar_fcs_P.Gain2_Gain_kd;
  xstar_fcs_B.h_AGL_m = (xstar_fcs_B.h_AGL_m -
    xstar_fcs_DW.DiscreteTimeIntegrator5_DSTAT_e) * xstar_fcs_P.Gain2_Gain_h;
  xstar_fcs_B.DiscreteTimeIntegrator5_d = (real32_T)
    ((((((((((xstar_fcs_B.raw_sona_h == xstar_fcs_DW.Delay5_DSTATE_f[0]) +
             (xstar_fcs_B.raw_sona_h == xstar_fcs_DW.Delay4_DSTATE_j[0])) +
            (xstar_fcs_DW.Delay5_DSTATE_f[0] == xstar_fcs_DW.Delay4_DSTATE_j[0]))
           + (xstar_fcs_B.raw_sona_h == xstar_fcs_DW.Delay3_DSTATE_e[0])) +
          (xstar_fcs_DW.Delay5_DSTATE_f[0] == xstar_fcs_DW.Delay3_DSTATE_e[0]))
         + (xstar_fcs_DW.Delay4_DSTATE_j[0] == xstar_fcs_DW.Delay3_DSTATE_e[0]))
        + (xstar_fcs_B.raw_sona_h == xstar_fcs_DW.Delay2_DSTATE_g[0])) +
       (xstar_fcs_DW.Delay5_DSTATE_f[0] == xstar_fcs_DW.Delay2_DSTATE_g[0])) +
      (xstar_fcs_DW.Delay4_DSTATE_j[0] == xstar_fcs_DW.Delay2_DSTATE_g[0])) +
     (xstar_fcs_DW.Delay3_DSTATE_e[0] == xstar_fcs_DW.Delay2_DSTATE_g[0])) -
    xstar_fcs_B.DiscreteTimeIntegrator5_d;
  if (xstar_fcs_B.DiscreteTimeIntegrator5_d > xstar_fcs_P.Switch_Threshold_c) {
    xstar_fcs_B.DiscreteTimeIntegrator5_d *= xstar_fcs_P.Gain1_Gain_my;
  } else {
    xstar_fcs_B.DiscreteTimeIntegrator5_d *= xstar_fcs_P.Gain2_Gain_ll;
  }

  xstar_fcs_DW.Memory1_1_PreviousInput = xstar_fcs_B.h_dot_mDs_c;
  xstar_fcs_DW.DelayInput1_DSTATE_pq = xstar_fcs_B.gyro_x;
  xstar_fcs_DW.DiscreteTimeIntegrator2_DSTATE +=
    xstar_fcs_P.DiscreteTimeIntegrator2_gainval * xstar_fcs_P.Constant4_Value_f;
  xstar_fcs_DW.Discrete_Time_Integrator_DSTATE += (real32_T)
    ((xstar_fcs_U.sensors.MPU6500.acc_x != 0) &&
     (xstar_fcs_U.sensors.MPU6500.acc_y != 0) &&
     (xstar_fcs_U.sensors.MPU6500.acc_z != 0)) *
    xstar_fcs_P.Discrete_Time_Integrator_gainva;
  if (xstar_fcs_DW.Discrete_Time_Integrator_DSTATE >=
      xstar_fcs_P.Discrete_Time_Integrator_UpperS) {
    xstar_fcs_DW.Discrete_Time_Integrator_DSTATE =
      xstar_fcs_P.Discrete_Time_Integrator_UpperS;
  } else {
    if (xstar_fcs_DW.Discrete_Time_Integrator_DSTATE <=
        xstar_fcs_P.Discrete_Time_Integrator_LowerS) {
      xstar_fcs_DW.Discrete_Time_Integrator_DSTATE =
        xstar_fcs_P.Discrete_Time_Integrator_LowerS;
    }
  }

  xstar_fcs_DW.Delay4_DSTATE_h = xstar_fcs_B.Rotation_AHRS_GPS_o28;
  xstar_fcs_DW.DelayInput1_DSTATE_fe = xstar_fcs_B.gyro_y;
  xstar_fcs_DW.DiscreteTimeIntegrator2_DSTAT_i +=
    xstar_fcs_P.DiscreteTimeIntegrator2_gainv_p * xstar_fcs_P.Constant4_Value_e;
  xstar_fcs_DW.DelayInput1_DSTATE_pk = xstar_fcs_B.gyro_z;
  xstar_fcs_DW.DiscreteTimeIntegrator2_DSTAT_d +=
    xstar_fcs_P.DiscreteTimeIntegrator2_gainv_g * xstar_fcs_P.Constant4_Value_c;
  xstar_fcs_DW.DelayInput1_DSTATE = xstar_fcs_B.Timestamp_ms_c;
  xstar_fcs_DW.DiscreteTimeIntegrator2_DSTAT_a +=
    xstar_fcs_P.DiscreteTimeIntegrator2_gainv_c * xstar_fcs_P.Constant4_Value_lf;
  xstar_fcs_DW.DiscreteTimeIntegrator_DSTATE +=
    xstar_fcs_P.DiscreteTimeIntegrator_gainva_k * xstar_fcs_P.Constant2_Value_fo;
  xstar_fcs_DW.Delay_DSTATE_a = ((int32_T)((uint32_T)xstar_fcs_B.Armed +
    xstar_fcs_B.LogicalOperator_c) != 0);
  xstar_fcs_DW.DiscreteTimeIntegrator_DSTATE_h +=
    xstar_fcs_P.DiscreteTimeIntegrator_gainv_pm * xstar_fcs_P.Constant_Value_kf;
  xstar_fcs_DW.DiscreteTimeIntegrator_PrevRese = (int8_T)xstar_fcs_B.Armed;
  xstar_fcs_DW.DelayInput1_DSTATE_d5 = xstar_fcs_U.sensors.ICM20602.gyro_x;
  xstar_fcs_DW.DiscreteTimeIntegrator2_DSTA_ab +=
    xstar_fcs_P.DiscreteTimeIntegrator2_gainv_b * xstar_fcs_P.Constant4_Value_g;
  xstar_fcs_DW.DelayInput1_DSTATE_e = xstar_fcs_U.sensors.ICM20602.gyro_y;
  xstar_fcs_DW.DiscreteTimeIntegrator2_DSTAT_m +=
    xstar_fcs_P.DiscreteTimeIntegrator2_gain_cx * xstar_fcs_P.Constant4_Value_h4;
  xstar_fcs_DW.DelayInput1_DSTATE_ei = xstar_fcs_U.sensors.ICM20602.gyro_z;
  xstar_fcs_DW.DiscreteTimeIntegrator2_DSTAT_n +=
    xstar_fcs_P.DiscreteTimeIntegrator2_gainv_o * xstar_fcs_P.Constant4_Value_m;
  xstar_fcs_DW.DelayInput1_DSTATE_b = xstar_fcs_U.sensors.ICM20602.Timestamp_ms;
  xstar_fcs_DW.DiscreteTimeIntegrator2_DSTAT_h +=
    xstar_fcs_P.DiscreteTimeIntegrator2_gainv_h * xstar_fcs_P.Constant4_Value_h;
  xstar_fcs_DW.DiscreteTimeIntegrator1_DSTATE +=
    xstar_fcs_P.DiscreteTimeIntegrator1_gainval * xstar_fcs_P.Constant3_Value_i;
  xstar_fcs_DW.DelayInput1_DSTATE_ip = xstar_fcs_B.acc_x;
  xstar_fcs_DW.DiscreteTimeIntegrator2_DSTA_ih +=
    xstar_fcs_P.DiscreteTimeIntegrator2_gainv_i * xstar_fcs_P.Constant4_Value_fr;
  xstar_fcs_DW.DelayInput1_DSTATE_k = xstar_fcs_B.acc_y;
  xstar_fcs_DW.DiscreteTimeIntegrator2_DSTAT_j +=
    xstar_fcs_P.DiscreteTimeIntegrator2_gainv_f * xstar_fcs_P.Constant4_Value_a;
  xstar_fcs_DW.DelayInput1_DSTATE_n = xstar_fcs_B.acc_z;
  xstar_fcs_DW.DiscreteTimeIntegrator2_DSTA_jl +=
    xstar_fcs_P.DiscreteTimeIntegrator2_gain_b3 * xstar_fcs_P.Constant4_Value_n;
  xstar_fcs_DW.DelayInput1_DSTATE_a = xstar_fcs_B.Timestamp_ms_c;
  xstar_fcs_DW.DiscreteTimeIntegrator2_DSTAT_e +=
    xstar_fcs_P.DiscreteTimeIntegrator2_gain_bf * xstar_fcs_P.Constant4_Value_kq;
  xstar_fcs_DW.DiscreteTimeIntegrator2_DSTA_h1 +=
    xstar_fcs_P.DiscreteTimeIntegrator2_gain_g4 * xstar_fcs_P.Constant6_Value;
  xstar_fcs_DW.Delay_DSTATE_k = ((int32_T)((uint32_T)
    xstar_fcs_B.flag_IMU1_acc_loss + xstar_fcs_B.LogicalOperator_j) != 0);
  xstar_fcs_DW.DiscreteTimeIntegrator_DSTATE_m +=
    xstar_fcs_P.DiscreteTimeIntegrator_gainva_m * xstar_fcs_P.Constant_Value_d0g;
  xstar_fcs_DW.DiscreteTimeIntegrator_PrevRe_l = (int8_T)
    xstar_fcs_B.flag_IMU1_acc_loss;
  xstar_fcs_DW.DelayInput1_DSTATE_kc = xstar_fcs_U.sensors.ICM20602.acc_x;
  xstar_fcs_DW.DiscreteTimeIntegrator2_DSTAT_l +=
    xstar_fcs_P.DiscreteTimeIntegrator2_gainv_e * xstar_fcs_P.Constant4_Value_i;
  xstar_fcs_DW.DelayInput1_DSTATE_b1 = xstar_fcs_U.sensors.ICM20602.acc_y;
  xstar_fcs_DW.DiscreteTimeIntegrator2_DSTAT_c +=
    xstar_fcs_P.DiscreteTimeIntegrator2_gainv_l * xstar_fcs_P.Constant4_Value_l;
  xstar_fcs_DW.DelayInput1_DSTATE_el = xstar_fcs_U.sensors.ICM20602.acc_z;
  xstar_fcs_DW.DiscreteTimeIntegrator2_DSTA_cc +=
    xstar_fcs_P.DiscreteTimeIntegrator2_gain_p1 * xstar_fcs_P.Constant4_Value_h0;
  xstar_fcs_DW.DelayInput1_DSTATE_m = xstar_fcs_U.sensors.ICM20602.Timestamp_ms;
  xstar_fcs_DW.DiscreteTimeIntegrator2_DSTAT_g +=
    xstar_fcs_P.DiscreteTimeIntegrator2_gainv_n * xstar_fcs_P.Constant4_Value_k;
  xstar_fcs_DW.DiscreteTimeIntegrator3_DSTATE +=
    xstar_fcs_P.DiscreteTimeIntegrator3_gainval * xstar_fcs_P.Constant7_Value_a;
  xstar_fcs_DW.Delay7_DSTATE[0] = xstar_fcs_B.rtb_Product9_idx_0;
  xstar_fcs_DW.Delay_DSTATE[0] = xstar_fcs_B.Product2_h[0];
  xstar_fcs_DW.Delay9_DSTATE[0] = xstar_fcs_B.rtb_Product8_idx_0;
  xstar_fcs_DW.Delay7_DSTATE[1] = xstar_fcs_B.rtb_Product9_idx_1;
  xstar_fcs_DW.Delay_DSTATE[1] = xstar_fcs_B.Product2_h[1];
  xstar_fcs_DW.Delay9_DSTATE[1] = xstar_fcs_B.rtb_Product8_idx_1;
  xstar_fcs_DW.Delay7_DSTATE[2] = xstar_fcs_B.DiscreteTimeIntegrator2_oo;
  xstar_fcs_DW.Delay_DSTATE[2] = xstar_fcs_B.Product2_h[2];
  xstar_fcs_DW.Delay9_DSTATE[2] = xstar_fcs_B.rtb_Product8_idx_2;
  xstar_fcs_DW.DelayInput1_DSTATE_bk = xstar_fcs_B.Timestamp_ms_c;
  xstar_fcs_B.rtb_Mag_Q_idx_0 = (real32_T)
    xstar_fcs_DW.DiscreteTimeIntegrator_DSTAT_jp + xstar_fcs_P.Constant_Value_bu;
  if (xstar_fcs_B.rtb_Mag_Q_idx_0 < 4.2949673E+9F) {
    if (xstar_fcs_B.rtb_Mag_Q_idx_0 >= 0.0F) {
      xstar_fcs_DW.DiscreteTimeIntegrator_DSTAT_jp = (uint32_T)
        xstar_fcs_B.rtb_Mag_Q_idx_0;
    } else {
      xstar_fcs_DW.DiscreteTimeIntegrator_DSTAT_jp = 0U;
    }
  } else {
    xstar_fcs_DW.DiscreteTimeIntegrator_DSTAT_jp = MAX_uint32_T;
  }

  xstar_fcs_DW.DelayInput1_DSTATE_l = xstar_fcs_U.sensors.ICM20602.Timestamp_ms;
  xstar_fcs_B.rtb_Mag_Q_idx_0 = (real32_T)
    xstar_fcs_DW.DiscreteTimeIntegrator_DSTAT_kr + xstar_fcs_P.Constant_Value_b;
  if (xstar_fcs_B.rtb_Mag_Q_idx_0 < 4.2949673E+9F) {
    if (xstar_fcs_B.rtb_Mag_Q_idx_0 >= 0.0F) {
      xstar_fcs_DW.DiscreteTimeIntegrator_DSTAT_kr = (uint32_T)
        xstar_fcs_B.rtb_Mag_Q_idx_0;
    } else {
      xstar_fcs_DW.DiscreteTimeIntegrator_DSTAT_kr = 0U;
    }
  } else {
    xstar_fcs_DW.DiscreteTimeIntegrator_DSTAT_kr = MAX_uint32_T;
  }

  for (xstar_fcs_B.Sum_mz = 0; xstar_fcs_B.Sum_mz < 9; xstar_fcs_B.Sum_mz++) {
    xstar_fcs_DW.Memory_95_PreviousInput[xstar_fcs_B.Sum_mz] =
      xstar_fcs_B.M_OB_g[xstar_fcs_B.Sum_mz];
  }

  xstar_fcs_DW.UnitDelay_DSTATE = xstar_fcs_B.UnitDelay;
  xstar_fcs_DW.DelayInput1_DSTATE_g1 = xstar_fcs_B.Compare;
  xstar_fcs_DW.DelayInput1_DSTATE_c = xstar_fcs_U.sensors.HMC5x83.Timestamp_ms;
  xstar_fcs_B.rtb_Mag_Q_idx_0 = (real32_T)
    xstar_fcs_DW.DiscreteTimeIntegrator_DSTATE_c + xstar_fcs_P.Constant_Value_pm;
  if (xstar_fcs_B.rtb_Mag_Q_idx_0 < 4.2949673E+9F) {
    if (xstar_fcs_B.rtb_Mag_Q_idx_0 >= 0.0F) {
      xstar_fcs_DW.DiscreteTimeIntegrator_DSTATE_c = (uint32_T)
        xstar_fcs_B.rtb_Mag_Q_idx_0;
    } else {
      xstar_fcs_DW.DiscreteTimeIntegrator_DSTATE_c = 0U;
    }
  } else {
    xstar_fcs_DW.DiscreteTimeIntegrator_DSTATE_c = MAX_uint32_T;
  }

  xstar_fcs_DW.DiscreteTimeIntegrator1_DSTAT_n +=
    xstar_fcs_P.DiscreteTimeIntegrator1_gainv_g *
    xstar_fcs_B.DiscreteTimeIntegrator_b;
  xstar_fcs_DW.Memory_101_PreviousInput[0] = xstar_fcs_B.M_OObar[0];
  xstar_fcs_DW.Memory_101_PreviousInput[1] = xstar_fcs_B.M_OObar[1];
  xstar_fcs_DW.Memory_101_PreviousInput[2] = xstar_fcs_B.M_OObar[2];
  xstar_fcs_DW.Memory_101_PreviousInput[3] = xstar_fcs_B.M_OObar[3];
  xstar_fcs_DW.DelayInput1_DSTATE_i = xstar_fcs_B.Timestamp_ms_hd;
  xstar_fcs_B.rtb_Mag_Q_idx_0 = (real32_T)
    xstar_fcs_DW.DiscreteTimeIntegrator_DSTAT_mz +
    xstar_fcs_P.Constant1_Value_ek;
  if (xstar_fcs_B.rtb_Mag_Q_idx_0 < 4.2949673E+9F) {
    if (xstar_fcs_B.rtb_Mag_Q_idx_0 >= 0.0F) {
      xstar_fcs_DW.DiscreteTimeIntegrator_DSTAT_mz = (uint32_T)
        xstar_fcs_B.rtb_Mag_Q_idx_0;
    } else {
      xstar_fcs_DW.DiscreteTimeIntegrator_DSTAT_mz = 0U;
    }
  } else {
    xstar_fcs_DW.DiscreteTimeIntegrator_DSTAT_mz = MAX_uint32_T;
  }

  xstar_fcs_DW.Memory_54_PreviousInput = xstar_fcs_B.Switch1_a;
  xstar_fcs_DW.DiscreteTimeIntegrator1_IC_LOAD = 0U;
  xstar_fcs_DW.DiscreteTimeIntegrator1_DSTAT_b +=
    xstar_fcs_P.DiscreteTimeIntegrator1_gainv_p * xstar_fcs_B.Product2_mi;
  xstar_fcs_DW.Memory_118_PreviousInput = xstar_fcs_B.h_AGL_m_a;
  xstar_fcs_DW.DiscreteTimeIntegrator5_DSTATE += ((real32_T)
    xstar_fcs_P.Gain1_Gain_ms * 6.10351563E-5F * (real32_T)
    xstar_fcs_B.FixPtRelationalOperator - xstar_fcs_B.DiscreteTimeIntegrator5) *
    xstar_fcs_P.Gain2_Gain_c * xstar_fcs_P.DiscreteTimeIntegrator5_gainval;
  xstar_fcs_DW.DiscreteTimeIntegrator5_DSTAT_i +=
    xstar_fcs_P.DiscreteTimeIntegrator5_gainv_d *
    xstar_fcs_B.DiscreteTimeIntegrator5_d;
  xstar_fcs_DW.Delay_DSTATE_kf = xstar_fcs_B.LogicalOperator7;
  xstar_fcs_DW.DiscreteTimeIntegrator_DSTATE_d +=
    xstar_fcs_P.DiscreteTimeIntegrator_gainva_e * xstar_fcs_P.Constant_Value_n;
  xstar_fcs_DW.DiscreteTimeIntegrator_PrevRe_n = (int8_T)
    xstar_fcs_B.LogicalOperator2;
  xstar_fcs_DW.DiscreteTimeIntegrator5_DSTAT_b += (xstar_fcs_B.h_AGL_m -
    xstar_fcs_B.DiscreteTimeIntegrator5_i) * xstar_fcs_P.Gain2_Gain_ml *
    xstar_fcs_P.DiscreteTimeIntegrator5_gainv_e;
  for (xstar_fcs_B.UnitDelay = 0; xstar_fcs_B.UnitDelay < 51;
       xstar_fcs_B.UnitDelay++) {
    xstar_fcs_DW.Delay_DSTATE_p[xstar_fcs_B.UnitDelay] =
      xstar_fcs_DW.Delay_DSTATE_p[xstar_fcs_B.UnitDelay + 1];
  }

  xstar_fcs_DW.Delay_DSTATE_p[51] = xstar_fcs_B.Compare_ld;
  xstar_fcs_DW.Delay_DSTATE_c = xstar_fcs_B.raw_sona_h;
  xstar_fcs_DW.DiscreteTimeIntegrator5_IC_LOAD = 0U;
  xstar_fcs_DW.DiscreteTimeIntegrator5_DSTAT_a +=
    xstar_fcs_P.DiscreteTimeIntegrator5_gainv_g * xstar_fcs_B.Gain2_d;
  xstar_fcs_DW.DiscreteTimeIntegrator5_PrevRes = (int8_T)xstar_fcs_B.Compare_ld;
  xstar_fcs_DW.DiscreteTimeIntegrator5_IC_LO_b = 0U;
  xstar_fcs_DW.DiscreteTimeIntegrator5_DSTAT_o += (xstar_fcs_B.Switch_m -
    xstar_fcs_B.DiscreteTimeIntegrator5_c) * xstar_fcs_P.Gain2_Gain_mf *
    xstar_fcs_P.DiscreteTimeIntegrator5_gainv_c;
  xstar_fcs_DW.DiscreteTimeIntegrator5_PrevR_c = (int8_T)
    xstar_fcs_B.LogicalOperator10;
  xstar_fcs_DW.DiscreteTimeIntegrator5_DSTA_ac +=
    (xstar_fcs_B.DiscreteTimeIntegrator3_n -
     xstar_fcs_B.DiscreteTimeIntegrator5_b) * xstar_fcs_P.Gain2_Gain_ab *
    xstar_fcs_P.DiscreteTimeIntegrator5_gainv_a;
  if ((real32_T)fabs(xstar_fcs_B.Delay_d) >
      xstar_fcs_P.CompareToConstant_const_i) {
    xstar_fcs_B.rtb_Mag_Q_idx_0 = 0.0F;
  } else {
    xstar_fcs_B.rtb_Mag_Q_idx_0 = xstar_fcs_B.Delay_d;
  }

  xstar_fcs_DW.DiscreteTimeIntegrator5_DSTAT_n += (xstar_fcs_B.rtb_Mag_Q_idx_0 -
    xstar_fcs_B.DiscreteTimeIntegrator5_e) * xstar_fcs_P.Gain2_Gain_m *
    xstar_fcs_P.DiscreteTimeIntegrator5_gain_ax;
  xstar_fcs_DW.Memory_134_PreviousInput = xstar_fcs_B.On_grd;
  xstar_fcs_DW.Delay1_DSTATE = xstar_fcs_B.raw_sona_h;
  xstar_fcs_DW.DiscreteTimeIntegrator1_DSTAT_e +=
    xstar_fcs_P.DiscreteTimeIntegrator1_gainv_h * xstar_fcs_P.Constant4_Value_j;
  xstar_fcs_DW.DelayInput1_DSTATE_d = xstar_fcs_B.timestamp_s;
  xstar_fcs_DW.DiscreteTimeIntegrator_DSTAT_dk +=
    xstar_fcs_P.DiscreteTimeIntegrator_gainva_c * xstar_fcs_P.Constant3_Value_e;
  xstar_fcs_DW.Delay_DSTATE_h = xstar_fcs_B.h_grd_sonar;
  for (xstar_fcs_B.Sum_mz = 0; xstar_fcs_B.Sum_mz < 149; xstar_fcs_B.Sum_mz++) {
    xstar_fcs_DW.TappedDelay2_X[149 - xstar_fcs_B.Sum_mz] =
      xstar_fcs_DW.TappedDelay2_X[148 - xstar_fcs_B.Sum_mz];
    xstar_fcs_DW.TappedDelay2_X_c[149 - xstar_fcs_B.Sum_mz] =
      xstar_fcs_DW.TappedDelay2_X_c[148 - xstar_fcs_B.Sum_mz];
    xstar_fcs_DW.TappedDelay2_X_k[149 - xstar_fcs_B.Sum_mz] =
      xstar_fcs_DW.TappedDelay2_X_k[148 - xstar_fcs_B.Sum_mz];
    xstar_fcs_DW.TappedDelay2_X_i[149 - xstar_fcs_B.Sum_mz] =
      xstar_fcs_DW.TappedDelay2_X_i[148 - xstar_fcs_B.Sum_mz];
  }

  xstar_fcs_DW.TappedDelay2_X[0] = xstar_fcs_B.Merge[0];
  xstar_fcs_DW.TappedDelay2_X_c[0] = xstar_fcs_B.Merge[1];
  xstar_fcs_DW.TappedDelay2_X_k[0] = xstar_fcs_B.Merge[2];
  xstar_fcs_DW.TappedDelay2_X_i[0] = xstar_fcs_B.Merge[3];
  xstar_fcs_DW.DelayInput1_DSTATE_j = xstar_fcs_B.DiscreteTimeIntegrator_d0;
  xstar_fcs_DW.Memory_97_PreviousInput[0] = xstar_fcs_B.rot_IB_B_radDs_c[0];
  xstar_fcs_DW.Memory_97_PreviousInput[1] = xstar_fcs_B.rot_IB_B_radDs_c[1];
  xstar_fcs_DW.Memory_97_PreviousInput[2] = xstar_fcs_B.rot_IB_B_radDs_c[2];
  xstar_fcs_DW.u80_circBuf--;
  if (xstar_fcs_DW.u80_circBuf < 0) {
    xstar_fcs_DW.u80_circBuf = 178;
  }

  xstar_fcs_DW.DelayInput1_DSTATE_it = xstar_fcs_B.DiscreteTimeIntegrator_d0;
  xstar_fcs_DW.DelayInput1_DSTATE_lh = xstar_fcs_B.rtb_Switch_timestamp_v;
  xstar_fcs_DW.DiscreteTimeIntegrator3_DSTAT_g +=
    xstar_fcs_P.DiscreteTimeIntegrator3_gainv_i * xstar_fcs_P.Constant2_Value_j;
  xstar_fcs_DW.DiscreteTimeIntegrator1_IC_LO_e = 0U;
  if (xstar_fcs_B.DataTypeConversion > xstar_fcs_P.Switch_Threshold_jn) {
    xstar_fcs_B.rtb_DataTypeConversion_j =
      xstar_fcs_P.Ascendanddescendtracking_Tc_a_h;
  } else {
    xstar_fcs_B.rtb_DataTypeConversion_j =
      xstar_fcs_P.Ascendanddescendtracking_Tc_d_f;
  }

  xstar_fcs_DW.DiscreteTimeIntegrator1_DSTAT_h += xstar_fcs_B.DataTypeConversion
    / xstar_fcs_B.rtb_DataTypeConversion_j *
    xstar_fcs_P.DiscreteTimeIntegrator1_gainv_e;
  xstar_fcs_DW.Delay_118_DSTATE = xstar_fcs_B.h_AGL_m_a;
  xstar_fcs_DW.DelayInput1_DSTATE_kct = xstar_fcs_B.Switch1_l;
  xstar_fcs_DW.DelayInput1_DSTATE_gg = xstar_fcs_B.Switch2;
  xstar_fcs_DW.Delay_DSTATE_hm = xstar_fcs_B.DataTypeConversion1_n;
  xstar_fcs_DW.DiscreteTimeIntegrator_DSTATE_n +=
    xstar_fcs_P.DiscreteTimeIntegrator_gainva_o * xstar_fcs_P.Constant_Value_pz;
  xstar_fcs_DW.DiscreteTimeIntegrator_PrevRe_p = (int8_T)
    xstar_fcs_B.LogicalOperator_f;
  xstar_fcs_DW.Delay1_DSTATE_g = xstar_fcs_P.Constant3_Value_n;
  xstar_fcs_DW.Delay10_DSTATE = xstar_fcs_B.FixPtRelationalOperator_n1;
  xstar_fcs_DW.DelayInput1_DSTATE_jl = xstar_fcs_B.DiscreteTimeIntegrator_ee;
  xstar_fcs_DW.Memory2_PreviousInput = xstar_fcs_B.qY_d;
  xstar_fcs_B.rtb_Mag_Q_idx_0 = (real32_T)
    xstar_fcs_DW.DiscreteTimeIntegrator_DSTAT_fh + xstar_fcs_P.Constant_Value_j;
  if (xstar_fcs_B.rtb_Mag_Q_idx_0 < 4.2949673E+9F) {
    if (xstar_fcs_B.rtb_Mag_Q_idx_0 >= 0.0F) {
      xstar_fcs_DW.DiscreteTimeIntegrator_DSTAT_fh = (uint32_T)
        xstar_fcs_B.rtb_Mag_Q_idx_0;
    } else {
      xstar_fcs_DW.DiscreteTimeIntegrator_DSTAT_fh = 0U;
    }
  } else {
    xstar_fcs_DW.DiscreteTimeIntegrator_DSTAT_fh = MAX_uint32_T;
  }

  xstar_fcs_DW.DelayInput1_DSTATE_h =
    xstar_fcs_U.sensors.RTK_Base.Timestamp_ms_pos;
  xstar_fcs_B.rtb_Mag_Q_idx_0 = (real32_T)
    xstar_fcs_DW.DiscreteTimeIntegrator_DSTAT_ng + xstar_fcs_P.Constant_Value_lx;
  if (xstar_fcs_B.rtb_Mag_Q_idx_0 < 4.2949673E+9F) {
    if (xstar_fcs_B.rtb_Mag_Q_idx_0 >= 0.0F) {
      xstar_fcs_DW.DiscreteTimeIntegrator_DSTAT_ng = (uint32_T)
        xstar_fcs_B.rtb_Mag_Q_idx_0;
    } else {
      xstar_fcs_DW.DiscreteTimeIntegrator_DSTAT_ng = 0U;
    }
  } else {
    xstar_fcs_DW.DiscreteTimeIntegrator_DSTAT_ng = MAX_uint32_T;
  }

  xstar_fcs_DW.UnitDelay_1_DSTATE = xstar_fcs_B.Compare;
  xstar_fcs_DW.UnitDelay_3_DSTATE = xstar_fcs_B.Double1;
  xstar_fcs_DW.DelayInput1_DSTATE_g = xstar_fcs_B.qY;
  xstar_fcs_B.rtb_Mag_Q_idx_0 = (real32_T)
    xstar_fcs_DW.DiscreteTimeIntegrator_DSTAT_fw + xstar_fcs_P.Constant_Value_h;
  if (xstar_fcs_B.rtb_Mag_Q_idx_0 < 4.2949673E+9F) {
    if (xstar_fcs_B.rtb_Mag_Q_idx_0 >= 0.0F) {
      xstar_fcs_DW.DiscreteTimeIntegrator_DSTAT_fw = (uint32_T)
        xstar_fcs_B.rtb_Mag_Q_idx_0;
    } else {
      xstar_fcs_DW.DiscreteTimeIntegrator_DSTAT_fw = 0U;
    }
  } else {
    xstar_fcs_DW.DiscreteTimeIntegrator_DSTAT_fw = MAX_uint32_T;
  }

  xstar_fcs_DW.DelayInput1_DSTATE_p = xstar_fcs_B.Cast1;
  xstar_fcs_B.rtb_Mag_Q_idx_0 = (real32_T)
    xstar_fcs_DW.DiscreteTimeIntegrator1_DSTA_hf + xstar_fcs_P.Constant1_Value_o;
  if (xstar_fcs_B.rtb_Mag_Q_idx_0 < 4.2949673E+9F) {
    if (xstar_fcs_B.rtb_Mag_Q_idx_0 >= 0.0F) {
      xstar_fcs_DW.DiscreteTimeIntegrator1_DSTA_hf = (uint32_T)
        xstar_fcs_B.rtb_Mag_Q_idx_0;
    } else {
      xstar_fcs_DW.DiscreteTimeIntegrator1_DSTA_hf = 0U;
    }
  } else {
    xstar_fcs_DW.DiscreteTimeIntegrator1_DSTA_hf = MAX_uint32_T;
  }

  xstar_fcs_DW.DelayInput1_DSTATE_mh = xstar_fcs_B.Cast2;
  xstar_fcs_B.rtb_Mag_Q_idx_0 = (real32_T)
    xstar_fcs_DW.DiscreteTimeIntegrator2_DSTA_hw +
    xstar_fcs_P.Constant2_Value_db;
  if (xstar_fcs_B.rtb_Mag_Q_idx_0 < 4.2949673E+9F) {
    if (xstar_fcs_B.rtb_Mag_Q_idx_0 >= 0.0F) {
      xstar_fcs_DW.DiscreteTimeIntegrator2_DSTA_hw = (uint32_T)
        xstar_fcs_B.rtb_Mag_Q_idx_0;
    } else {
      xstar_fcs_DW.DiscreteTimeIntegrator2_DSTA_hw = 0U;
    }
  } else {
    xstar_fcs_DW.DiscreteTimeIntegrator2_DSTA_hw = MAX_uint32_T;
  }

  xstar_fcs_DW.DiscreteTimeIntegrator5_IC_LO_f = 0U;
  xstar_fcs_DW.DiscreteTimeIntegrator5_PrevR_h = (int8_T)xstar_fcs_B.Switch_l;
  xstar_fcs_DW.DiscreteTimeIntegrator5_IC_L_bz = 0U;
  xstar_fcs_DW.u80_states[xstar_fcs_DW.u80_circBuf] =
    xstar_fcs_B.rot_IB_B_radDs[0];
  xstar_fcs_DW.Delay2_DSTATE[0] = xstar_fcs_B.Translation_Fusion_o16[0];
  xstar_fcs_DW.DiscreteTimeIntegrator5_DSTAT_g[0] += (xstar_fcs_B.u0_l -
    xstar_fcs_B.rtb_DiscreteTimeIntegrator5_bi_) * xstar_fcs_P.Gain2_Gain_kt *
    xstar_fcs_P.DiscreteTimeIntegrator5_gainv_o;
  xstar_fcs_DW.DiscreteTimeIntegrator5_DSTAT_d[0] +=
    (xstar_fcs_B.rtb_Saturation_j_idx_0 -
     xstar_fcs_B.rtb_DiscreteTimeIntegrator5_j_i) * xstar_fcs_P.Gain2_Gain_ks *
    xstar_fcs_P.DiscreteTimeIntegrator5_gain_gu;
  xstar_fcs_DW.u80_states[xstar_fcs_DW.u80_circBuf + 179] =
    xstar_fcs_B.rot_IB_B_radDs[1];
  xstar_fcs_DW.Delay2_DSTATE[1] = xstar_fcs_B.Translation_Fusion_o16[1];
  xstar_fcs_DW.DiscreteTimeIntegrator5_DSTAT_g[1] += (xstar_fcs_B.u0 -
    xstar_fcs_B.rtb_DiscreteTimeIntegrator5_b_f) * xstar_fcs_P.Gain2_Gain_kt *
    xstar_fcs_P.DiscreteTimeIntegrator5_gainv_o;
  xstar_fcs_DW.DiscreteTimeIntegrator5_DSTAT_d[1] +=
    (xstar_fcs_B.rtb_Saturation_j_idx_1 -
     xstar_fcs_B.rtb_DiscreteTimeIntegrator5_j_m) * xstar_fcs_P.Gain2_Gain_ks *
    xstar_fcs_P.DiscreteTimeIntegrator5_gain_gu;
  xstar_fcs_DW.u80_states[xstar_fcs_DW.u80_circBuf + 358] =
    xstar_fcs_B.rot_IB_B_radDs[2];
  xstar_fcs_DW.Delay2_DSTATE[2] = xstar_fcs_B.Translation_Fusion_o16[2];
  xstar_fcs_DW.DiscreteTimeIntegrator5_DSTAT_g[2] += (xstar_fcs_B.u0_p -
    xstar_fcs_B.rtb_DiscreteTimeIntegrator5_b_g) * xstar_fcs_P.Gain2_Gain_kt *
    xstar_fcs_P.DiscreteTimeIntegrator5_gainv_o;
  xstar_fcs_DW.DiscreteTimeIntegrator5_DSTAT_d[2] +=
    (xstar_fcs_B.rtb_Saturation_j_idx_2 -
     xstar_fcs_B.rtb_DiscreteTimeIntegrator5_j_n) * xstar_fcs_P.Gain2_Gain_ks *
    xstar_fcs_P.DiscreteTimeIntegrator5_gain_gu;
  xstar_fcs_DW.DiscreteTimeIntegrator5_PrevR_m = (int8_T)xstar_fcs_B.Compare_dq;
  xstar_fcs_DW.Delay_DSTATE_m = xstar_fcs_B.Product1_ko[0];
  xstar_fcs_DW.Delay_DSTATE_g = xstar_fcs_B.Product1_ko[1];
  xstar_fcs_DW.Delay_DSTATE_f = xstar_fcs_B.Sum_f;
  xstar_fcs_DW.Memory1_12_PreviousInput = xstar_fcs_B.GPS_Vel_Vaild_d;
  xstar_fcs_DW.Memory1_13_PreviousInput = xstar_fcs_B.VO_Vel_Valid_m;
  xstar_fcs_DW.DiscreteTimeIntegrator5_IC_LO_c = 0U;
  xstar_fcs_DW.DiscreteTimeIntegrator5_DSTAT_f +=
    (xstar_fcs_B.DiscreteTimeIntegrator_pl - xstar_fcs_B.Gain2_p) *
    xstar_fcs_P.Gain2_Gain_d * xstar_fcs_P.DiscreteTimeIntegrator5_gainv_f;
  xstar_fcs_DW.DiscreteTimeIntegrator5_PrevR_f = (int8_T)
    xstar_fcs_B.LogicalOperator3_f;
  xstar_fcs_DW.Memory1_PreviousInput = xstar_fcs_B.delta_h_m;
  xstar_fcs_DW.DiscreteTimeIntegrator5_IC_LO_g = 0U;
  xstar_fcs_DW.DiscreteTimeIntegrator5_DSTAT_j +=
    xstar_fcs_P.DiscreteTimeIntegrator5_gainv_p * xstar_fcs_P.Constant4_Value_hu;
  xstar_fcs_DW.DiscreteTimeIntegrator5_PrevR_o = (int8_T)
    xstar_fcs_B.LogicalOperator3_b;
  for (xstar_fcs_B.Sum_mz = 0; xstar_fcs_B.Sum_mz < 149; xstar_fcs_B.Sum_mz++) {
    xstar_fcs_DW.TappedDelay2_X_l[149 - xstar_fcs_B.Sum_mz] =
      xstar_fcs_DW.TappedDelay2_X_l[148 - xstar_fcs_B.Sum_mz];
    xstar_fcs_DW.TappedDelay2_X_m[149 - xstar_fcs_B.Sum_mz] =
      xstar_fcs_DW.TappedDelay2_X_m[148 - xstar_fcs_B.Sum_mz];
    xstar_fcs_DW.TappedDelay2_X_f[149 - xstar_fcs_B.Sum_mz] =
      xstar_fcs_DW.TappedDelay2_X_f[148 - xstar_fcs_B.Sum_mz];
  }

  xstar_fcs_DW.TappedDelay2_X_l[0] = xstar_fcs_B.Selector1[1];
  xstar_fcs_DW.TappedDelay2_X_m[0] = xstar_fcs_B.Selector1[0];
  xstar_fcs_DW.TappedDelay2_X_f[0] = xstar_fcs_B.Selector1[2];
  xstar_fcs_DW.DelayInput1_DSTATE_f = xstar_fcs_U.sensors.ESC.Timestamp_ms;
  xstar_fcs_DW.DiscreteTimeIntegrator_DSTATE_f +=
    xstar_fcs_P.DiscreteTimeIntegrator_gainv_ka * xstar_fcs_P.Constant3_Value_a;
  xstar_fcs_DW.DiscreteTimeIntegrator1_DSTA_hy +=
    xstar_fcs_P.DiscreteTimeIntegrator1_gainv_b * xstar_fcs_B.sample_sum_a;
  xstar_fcs_DW.DiscreteTimeIntegrator_DSTATE_j += (xstar_fcs_B.MathFunction_g +
    xstar_fcs_B.Gain_p) * xstar_fcs_P.DiscreteTimeIntegrator_gainva_j;
  xstar_fcs_DW.Delay3_DSTATE_n = xstar_fcs_B.Rotation_AHRS_GPS_o33;
  xstar_fcs_DW.Memory1_11_PreviousInput = xstar_fcs_B.POS_reset_signal;
  xstar_fcs_DW.Memory1_14_PreviousInput = xstar_fcs_B.mue_est_rad_fc;
  xstar_fcs_DW.Memory1_15_PreviousInput = xstar_fcs_B.lambda_est_rad_fc;
  xstar_fcs_DW.Memory1_2_PreviousInput = xstar_fcs_B.h_AGL_m_a;
  xstar_fcs_DW.Memory1_3_PreviousInput = xstar_fcs_B.h_0_AGL_m;
  xstar_fcs_DW.Memory1_4_PreviousInput = xstar_fcs_B.h_MSL;
  xstar_fcs_DW.Memory1_5_PreviousInput = xstar_fcs_B.Bias_z_mDs2;
  xstar_fcs_DW.Memory1_10_PreviousInput[0] = xstar_fcs_B.POS_xy_O_m[0];
  xstar_fcs_DW.Memory1_6_PreviousInput[0] = xstar_fcs_B.VEL_xy_O_mDs[0];
  xstar_fcs_DW.Memory1_7_PreviousInput[0] = xstar_fcs_B.Pos_Init_flg[0];
  xstar_fcs_DW.Memory1_10_PreviousInput[1] = xstar_fcs_B.POS_xy_O_m[1];
  xstar_fcs_DW.Memory1_6_PreviousInput[1] = xstar_fcs_B.VEL_xy_O_mDs[1];
  xstar_fcs_DW.Memory1_7_PreviousInput[1] = xstar_fcs_B.Pos_Init_flg[1];
  xstar_fcs_DW.Memory1_8_PreviousInput = xstar_fcs_B.mue_est_rad;
  xstar_fcs_DW.Memory1_9_PreviousInput = xstar_fcs_B.lambda_est_rad;
  xstar_fcs_DW.DiscreteTimeIntegrator_DSTATE_b += (xstar_fcs_B.Gain1_g +
    xstar_fcs_B.DiscreteTimeIntegrator1_i) *
    xstar_fcs_P.DiscreteTimeIntegrator_gainv_jc;
  xstar_fcs_DW.DelayInput1_DSTATE_li =
    xstar_fcs_U.sensors.RTK_Base.Timestamp_ms_vel;
  xstar_fcs_B.rtb_Mag_Q_idx_0 = (real32_T)
    xstar_fcs_DW.DiscreteTimeIntegrator_DSTAT_jd + xstar_fcs_P.Constant_Value_a;
  if (xstar_fcs_B.rtb_Mag_Q_idx_0 < 4.2949673E+9F) {
    if (xstar_fcs_B.rtb_Mag_Q_idx_0 >= 0.0F) {
      xstar_fcs_DW.DiscreteTimeIntegrator_DSTAT_jd = (uint32_T)
        xstar_fcs_B.rtb_Mag_Q_idx_0;
    } else {
      xstar_fcs_DW.DiscreteTimeIntegrator_DSTAT_jd = 0U;
    }
  } else {
    xstar_fcs_DW.DiscreteTimeIntegrator_DSTAT_jd = MAX_uint32_T;
  }

  xstar_fcs_DW.DiscreteTimeIntegrator1_IC_LO_g = 0U;
  xstar_fcs_DW.DiscreteTimeIntegrator1_DSTAT_f +=
    xstar_fcs_P.DiscreteTimeIntegrator1_gainv_j * xstar_fcs_B.Product_cm;
  xstar_fcs_DW.DiscreteTimeIntegrator2_DSTAT_p +=
    xstar_fcs_P.DiscreteTimeIntegrator2_gain_ll * xstar_fcs_P.Constant4_Value_cc;
  xstar_fcs_DW.DiscreteTimeIntegrator_DSTAT_b0 +=
    xstar_fcs_P.DiscreteTimeIntegrator_gainv_ol * (real32_T)
    xstar_fcs_B.Rotation_AHRS_GPS_o27;
  if (xstar_fcs_DW.DiscreteTimeIntegrator_DSTAT_b0 >=
      xstar_fcs_P.DiscreteTimeIntegrator_UpperSat) {
    xstar_fcs_DW.DiscreteTimeIntegrator_DSTAT_b0 =
      xstar_fcs_P.DiscreteTimeIntegrator_UpperSat;
  } else {
    if (xstar_fcs_DW.DiscreteTimeIntegrator_DSTAT_b0 <=
        xstar_fcs_P.DiscreteTimeIntegrator_LowerSat) {
      xstar_fcs_DW.DiscreteTimeIntegrator_DSTAT_b0 =
        xstar_fcs_P.DiscreteTimeIntegrator_LowerSat;
    }
  }

  xstar_fcs_DW.DiscreteTimeIntegrator_PrevRe_i = (int8_T)
    xstar_fcs_B.FixPtRelationalOperator_fv;
  xstar_fcs_DW.Delay8_DSTATE[0] = xstar_fcs_B.MovingAverage_p.MovingAverage2;
  xstar_fcs_DW.Delay8_DSTATE[1] = xstar_fcs_B.MovingAverage1_p.MovingAverage2;
  xstar_fcs_DW.Delay8_DSTATE[2] = xstar_fcs_B.MovingAverage2_p.MovingAverage2;
  xstar_fcs_DW.icLoad = 0U;
  xstar_fcs_DW.Delay1_DSTATE_e[0] = xstar_fcs_B.rtb_Product8_idx_0;
  xstar_fcs_DW.Delay1_DSTATE_e[1] = xstar_fcs_B.rtb_Product8_idx_1;
  xstar_fcs_DW.Delay1_DSTATE_e[2] = xstar_fcs_B.rtb_Product8_idx_2;
  for (xstar_fcs_B.UnitDelay = 0; xstar_fcs_B.UnitDelay < 119;
       xstar_fcs_B.UnitDelay++) {
    xstar_fcs_B.Sum_mz = (xstar_fcs_B.UnitDelay + 1) * 3;
    xstar_fcs_DW.Delay2_DSTATE_k[xstar_fcs_B.UnitDelay * 3] =
      xstar_fcs_DW.Delay2_DSTATE_k[xstar_fcs_B.Sum_mz];
    xstar_fcs_DW.Delay2_DSTATE_k[xstar_fcs_B.UnitDelay * 3 + 1] =
      xstar_fcs_DW.Delay2_DSTATE_k[xstar_fcs_B.Sum_mz + 1];
    xstar_fcs_DW.Delay2_DSTATE_k[xstar_fcs_B.UnitDelay * 3 + 2] =
      xstar_fcs_DW.Delay2_DSTATE_k[xstar_fcs_B.Sum_mz + 2];
  }

  xstar_fcs_DW.Delay2_DSTATE_k[357] = xstar_fcs_B.sfor_R_B_mDs2_main[0] -
    xstar_fcs_B.sfor_R_B_mDs2_m[0];
  xstar_fcs_DW.Delay2_DSTATE_k[358] = xstar_fcs_B.sfor_R_B_mDs2_main[1] -
    xstar_fcs_B.sfor_R_B_mDs2_m[1];
  xstar_fcs_DW.Delay2_DSTATE_k[359] = xstar_fcs_B.sfor_R_B_mDs2_main[2] -
    xstar_fcs_B.sfor_R_B_mDs2_m[2];
  xstar_fcs_DW.Delay3_DSTATE[0] = xstar_fcs_B.MovingAverage.MovingAverage2;
  xstar_fcs_DW.Delay3_DSTATE[1] = xstar_fcs_B.MovingAverage1.MovingAverage2;
  xstar_fcs_DW.Delay3_DSTATE[2] = xstar_fcs_B.MovingAverage2.MovingAverage2;
  xstar_fcs_DW.DiscreteTimeIntegrator_DSTAT_hp +=
    xstar_fcs_P.DiscreteTimeIntegrator_gainva_g * (real32_T)
    xstar_fcs_B.Rotation_AHRS_GPS_o27;
  if (xstar_fcs_DW.DiscreteTimeIntegrator_DSTAT_hp >=
      xstar_fcs_P.DiscreteTimeIntegrator_UpperS_l) {
    xstar_fcs_DW.DiscreteTimeIntegrator_DSTAT_hp =
      xstar_fcs_P.DiscreteTimeIntegrator_UpperS_l;
  } else {
    if (xstar_fcs_DW.DiscreteTimeIntegrator_DSTAT_hp <=
        xstar_fcs_P.DiscreteTimeIntegrator_LowerS_a) {
      xstar_fcs_DW.DiscreteTimeIntegrator_DSTAT_hp =
        xstar_fcs_P.DiscreteTimeIntegrator_LowerS_a;
    }
  }

  xstar_fcs_DW.DiscreteTimeIntegrator_PrevRe_o = (int8_T)
    xstar_fcs_B.FixPtRelationalOperator_fv;
  xstar_fcs_DW.icLoad_p = 0U;
  xstar_fcs_DW.Delay4_DSTATE[0] = xstar_fcs_B.Product2_h[0];
  xstar_fcs_DW.Delay4_DSTATE[1] = xstar_fcs_B.Product2_h[1];
  xstar_fcs_DW.Delay4_DSTATE[2] = xstar_fcs_B.Product2_h[2];
  xstar_fcs_DW.DiscreteTimeIntegrator_DSTATE_k +=
    xstar_fcs_P.DiscreteTimeIntegrator_gainv_p5 * (real32_T)
    xstar_fcs_B.Rotation_AHRS_GPS_o27;
  if (xstar_fcs_DW.DiscreteTimeIntegrator_DSTATE_k >=
      xstar_fcs_P.DiscreteTimeIntegrator_UpperS_k) {
    xstar_fcs_DW.DiscreteTimeIntegrator_DSTATE_k =
      xstar_fcs_P.DiscreteTimeIntegrator_UpperS_k;
  } else {
    if (xstar_fcs_DW.DiscreteTimeIntegrator_DSTATE_k <=
        xstar_fcs_P.DiscreteTimeIntegrator_LowerS_g) {
      xstar_fcs_DW.DiscreteTimeIntegrator_DSTATE_k =
        xstar_fcs_P.DiscreteTimeIntegrator_LowerS_g;
    }
  }

  xstar_fcs_DW.DiscreteTimeIntegrator_PrevR_iy = (int8_T)
    xstar_fcs_B.FixPtRelationalOperator_fv;
  xstar_fcs_DW.Delay6_DSTATE[0] = xstar_fcs_B.MovingAverage_pn.MovingAverage2;
  xstar_fcs_DW.Delay6_DSTATE[1] = xstar_fcs_B.MovingAverage1_pn.MovingAverage2;
  xstar_fcs_DW.Delay6_DSTATE[2] = xstar_fcs_B.MovingAverage2_pn.MovingAverage2;
  xstar_fcs_DW.icLoad_pg = 0U;
  xstar_fcs_DW.Delay5_DSTATE[0] = xstar_fcs_B.rtb_Product9_idx_0;
  xstar_fcs_DW.Delay5_DSTATE[1] = xstar_fcs_B.rtb_Product9_idx_1;
  xstar_fcs_DW.Delay5_DSTATE[2] = xstar_fcs_B.DiscreteTimeIntegrator2_oo;
  xstar_fcs_DW.DiscreteTimeIntegrator5_DSTAT_k +=
    xstar_fcs_P.DiscreteTimeIntegrator5_gainv_m *
    xstar_fcs_B.DiscreteTimeIntegrator3_n;
  xstar_fcs_DW.DiscreteTimeIntegrator5_DSTA_k1 +=
    xstar_fcs_P.DiscreteTimeIntegrator5_gain_ct * xstar_fcs_B.Delay_d;
  xstar_fcs_DW.DiscreteTimeIntegrator5_DSTAT_e +=
    xstar_fcs_P.DiscreteTimeIntegrator5_gain_el * xstar_fcs_B.h_AGL_m;
  for (xstar_fcs_B.UnitDelay = 0; xstar_fcs_B.UnitDelay < 49;
       xstar_fcs_B.UnitDelay++) {
    xstar_fcs_DW.Delay2_DSTATE_g[xstar_fcs_B.UnitDelay] =
      xstar_fcs_DW.Delay2_DSTATE_g[xstar_fcs_B.UnitDelay + 1];
  }

  xstar_fcs_DW.Delay2_DSTATE_g[49] = xstar_fcs_B.raw_sona_h;
  for (xstar_fcs_B.UnitDelay = 0; xstar_fcs_B.UnitDelay < 199;
       xstar_fcs_B.UnitDelay++) {
    xstar_fcs_DW.Delay5_DSTATE_f[xstar_fcs_B.UnitDelay] =
      xstar_fcs_DW.Delay5_DSTATE_f[xstar_fcs_B.UnitDelay + 1];
  }

  xstar_fcs_DW.Delay5_DSTATE_f[199] = xstar_fcs_B.raw_sona_h;
  for (xstar_fcs_B.UnitDelay = 0; xstar_fcs_B.UnitDelay < 149;
       xstar_fcs_B.UnitDelay++) {
    xstar_fcs_DW.Delay4_DSTATE_j[xstar_fcs_B.UnitDelay] =
      xstar_fcs_DW.Delay4_DSTATE_j[xstar_fcs_B.UnitDelay + 1];
  }

  xstar_fcs_DW.Delay4_DSTATE_j[149] = xstar_fcs_B.raw_sona_h;
  for (xstar_fcs_B.UnitDelay = 0; xstar_fcs_B.UnitDelay < 99;
       xstar_fcs_B.UnitDelay++) {
    xstar_fcs_DW.Delay3_DSTATE_e[xstar_fcs_B.UnitDelay] =
      xstar_fcs_DW.Delay3_DSTATE_e[xstar_fcs_B.UnitDelay + 1];
  }

  xstar_fcs_DW.Delay3_DSTATE_e[99] = xstar_fcs_B.raw_sona_h;
}

void xstar_fcs_initialize(void)
{
  rt_InitInfAndNaN(sizeof(real_T));
  xstar_fcs_P.CompareTo1sec_const = rtInfF;
  xstar_fcs_P.CompareTo1sec_const_j = rtInfF;
  Rotation_AHRS_GPS_initialize(rtmGetErrorStatusPointer(xstar_fcs_M));
  Translation_Fusion_initialize(rtmGetErrorStatusPointer(xstar_fcs_M));
  Rotation_AHRS_GPS_Start(&xstar_fcs_B.vel_O_O[0]);
  Translation_Fusion_Start();
  xstar_fcs_MovingAverage2_Start(&xstar_fcs_DW.MovingAverage);
  xstar_fcs_MovingAverage2_Start(&xstar_fcs_DW.MovingAverage1);
  xstar_fcs_MovingAverage2_Start(&xstar_fcs_DW.MovingAverage2);
  xstar_fcs_MovingAverage2_Start(&xstar_fcs_DW.MovingAverage_p);
  xstar_fcs_MovingAverage2_Start(&xstar_fcs_DW.MovingAverage1_p);
  xstar_fcs_MovingAverage2_Start(&xstar_fcs_DW.MovingAverage2_p);
  xstar_fcs_MovingAverage2_Start(&xstar_fcs_DW.MovingAverage_pn);
  xstar_fcs_MovingAverage2_Start(&xstar_fcs_DW.MovingAverage1_pn);
  xstar_fcs_MovingAverage2_Start(&xstar_fcs_DW.MovingAverage2_pn);
  xstar_fcs_PrevZCX.Delay1_Reset_ZCE = POS_ZCSIG;
  xstar_fcs_PrevZCX.WGS_Linearization_Trig_ZCE_f = POS_ZCSIG;
  xstar_fcs_PrevZCX.WGS_Linearization_Trig_ZCE = POS_ZCSIG;
  xstar_fcs_DW.Memory1_1_PreviousInput = xstar_fcs_P.Memory1_1_InitialCondition;
  xstar_fcs_DW.DelayInput1_DSTATE_pq = xstar_fcs_P.DetectChange_vinit_f;
  xstar_fcs_DW.DiscreteTimeIntegrator2_DSTATE =
    xstar_fcs_P.DiscreteTimeIntegrator2_IC;
  xstar_fcs_DW.Discrete_Time_Integrator_DSTATE =
    xstar_fcs_P.Discrete_Time_Integrator_IC;
  xstar_fcs_DW.Delay4_DSTATE_h = xstar_fcs_P.Delay4_InitialCondition_k;
  xstar_fcs_DW.DelayInput1_DSTATE_fe = xstar_fcs_P.DetectChange1_vinit_m;
  xstar_fcs_DW.DiscreteTimeIntegrator2_DSTAT_i =
    xstar_fcs_P.DiscreteTimeIntegrator2_IC_a;
  xstar_fcs_DW.DelayInput1_DSTATE_pk = xstar_fcs_P.DetectChange2_vinit_c;
  xstar_fcs_DW.DiscreteTimeIntegrator2_DSTAT_d =
    xstar_fcs_P.DiscreteTimeIntegrator2_IC_h;
  xstar_fcs_DW.DelayInput1_DSTATE = xstar_fcs_P.DetectChange6_vinit;
  xstar_fcs_DW.DiscreteTimeIntegrator2_DSTAT_a =
    xstar_fcs_P.DiscreteTimeIntegrator2_IC_l;
  xstar_fcs_DW.DiscreteTimeIntegrator_DSTATE =
    xstar_fcs_P.DiscreteTimeIntegrator_IC;
  xstar_fcs_DW.Delay_DSTATE_a = xstar_fcs_P.Delay_InitialCondition_o;
  xstar_fcs_DW.DiscreteTimeIntegrator_DSTATE_h =
    xstar_fcs_P.DiscreteTimeIntegrator_IC_b;
  xstar_fcs_DW.DelayInput1_DSTATE_d5 = xstar_fcs_P.DetectChange7_vinit;
  xstar_fcs_DW.DiscreteTimeIntegrator2_DSTA_ab =
    xstar_fcs_P.DiscreteTimeIntegrator2_IC_d;
  xstar_fcs_DW.DelayInput1_DSTATE_e = xstar_fcs_P.DetectChange8_vinit;
  xstar_fcs_DW.DiscreteTimeIntegrator2_DSTAT_m =
    xstar_fcs_P.DiscreteTimeIntegrator2_IC_dc;
  xstar_fcs_DW.DelayInput1_DSTATE_ei = xstar_fcs_P.DetectChange9_vinit;
  xstar_fcs_DW.DiscreteTimeIntegrator2_DSTAT_n =
    xstar_fcs_P.DiscreteTimeIntegrator2_IC_e;
  xstar_fcs_DW.DelayInput1_DSTATE_b = xstar_fcs_P.DetectChange13_vinit;
  xstar_fcs_DW.DiscreteTimeIntegrator2_DSTAT_h =
    xstar_fcs_P.DiscreteTimeIntegrator2_IC_le;
  xstar_fcs_DW.DiscreteTimeIntegrator1_DSTATE =
    xstar_fcs_P.DiscreteTimeIntegrator1_IC;
  xstar_fcs_DW.DelayInput1_DSTATE_ip = xstar_fcs_P.DetectChange21_vinit;
  xstar_fcs_DW.DiscreteTimeIntegrator2_DSTA_ih =
    xstar_fcs_P.DiscreteTimeIntegrator2_IC_ed;
  xstar_fcs_DW.DelayInput1_DSTATE_k = xstar_fcs_P.DetectChange22_vinit;
  xstar_fcs_DW.DiscreteTimeIntegrator2_DSTAT_j =
    xstar_fcs_P.DiscreteTimeIntegrator2_IC_h2;
  xstar_fcs_DW.DelayInput1_DSTATE_n = xstar_fcs_P.DetectChange23_vinit;
  xstar_fcs_DW.DiscreteTimeIntegrator2_DSTA_jl =
    xstar_fcs_P.DiscreteTimeIntegrator2_IC_ak;
  xstar_fcs_DW.DelayInput1_DSTATE_a = xstar_fcs_P.DetectChange24_vinit;
  xstar_fcs_DW.DiscreteTimeIntegrator2_DSTAT_e =
    xstar_fcs_P.DiscreteTimeIntegrator2_IC_n;
  xstar_fcs_DW.DiscreteTimeIntegrator2_DSTA_h1 =
    xstar_fcs_P.DiscreteTimeIntegrator2_IC_b;
  xstar_fcs_DW.Delay_DSTATE_k = xstar_fcs_P.Delay_InitialCondition_l;
  xstar_fcs_DW.DiscreteTimeIntegrator_DSTATE_m =
    xstar_fcs_P.DiscreteTimeIntegrator_IC_o;
  xstar_fcs_DW.DelayInput1_DSTATE_kc = xstar_fcs_P.DetectChange16_vinit;
  xstar_fcs_DW.DiscreteTimeIntegrator2_DSTAT_l =
    xstar_fcs_P.DiscreteTimeIntegrator2_IC_g;
  xstar_fcs_DW.DelayInput1_DSTATE_b1 = xstar_fcs_P.DetectChange17_vinit;
  xstar_fcs_DW.DiscreteTimeIntegrator2_DSTAT_c =
    xstar_fcs_P.DiscreteTimeIntegrator2_IC_k;
  xstar_fcs_DW.DelayInput1_DSTATE_el = xstar_fcs_P.DetectChange18_vinit;
  xstar_fcs_DW.DiscreteTimeIntegrator2_DSTA_cc =
    xstar_fcs_P.DiscreteTimeIntegrator2_IC_c;
  xstar_fcs_DW.DelayInput1_DSTATE_m = xstar_fcs_P.DetectChange19_vinit;
  xstar_fcs_DW.DiscreteTimeIntegrator2_DSTAT_g =
    xstar_fcs_P.DiscreteTimeIntegrator2_IC_cy;
  xstar_fcs_DW.DiscreteTimeIntegrator3_DSTATE =
    xstar_fcs_P.DiscreteTimeIntegrator3_IC;
  xstar_fcs_DW.Delay7_DSTATE[0] = xstar_fcs_P.Delay7_InitialCondition;
  xstar_fcs_DW.Delay_DSTATE[0] = xstar_fcs_P.Delay_InitialCondition;
  xstar_fcs_DW.Delay9_DSTATE[0] = xstar_fcs_P.Delay9_InitialCondition;
  xstar_fcs_DW.Delay7_DSTATE[1] = xstar_fcs_P.Delay7_InitialCondition;
  xstar_fcs_DW.Delay_DSTATE[1] = xstar_fcs_P.Delay_InitialCondition;
  xstar_fcs_DW.Delay9_DSTATE[1] = xstar_fcs_P.Delay9_InitialCondition;
  xstar_fcs_DW.Delay7_DSTATE[2] = xstar_fcs_P.Delay7_InitialCondition;
  xstar_fcs_DW.Delay_DSTATE[2] = xstar_fcs_P.Delay_InitialCondition;
  xstar_fcs_DW.Delay9_DSTATE[2] = xstar_fcs_P.Delay9_InitialCondition;
  xstar_fcs_DW.DelayInput1_DSTATE_bk = xstar_fcs_P.DetectChange_vinit;
  xstar_fcs_DW.DiscreteTimeIntegrator_DSTAT_jp =
    xstar_fcs_P.DiscreteTimeIntegrator_IC_p;
  xstar_fcs_DW.DelayInput1_DSTATE_l = xstar_fcs_P.DetectChange_vinit_p;
  xstar_fcs_DW.DiscreteTimeIntegrator_DSTAT_kr =
    xstar_fcs_P.DiscreteTimeIntegrator_IC_i;
  for (xstar_fcs_B.i = 0; xstar_fcs_B.i < 9; xstar_fcs_B.i++) {
    xstar_fcs_DW.Memory_95_PreviousInput[xstar_fcs_B.i] =
      xstar_fcs_P.Memory_95_InitialCondition;
  }

  xstar_fcs_DW.UnitDelay_DSTATE = xstar_fcs_P.UnitDelay_InitialCondition;
  xstar_fcs_DW.DelayInput1_DSTATE_g1 = xstar_fcs_P.DetectDecrease_vinit;
  xstar_fcs_DW.DelayInput1_DSTATE_c = xstar_fcs_P.DetectChange_vinit_d;
  xstar_fcs_DW.DiscreteTimeIntegrator_DSTATE_c =
    xstar_fcs_P.DiscreteTimeIntegrator_IC_nk;
  xstar_fcs_DW.DiscreteTimeIntegrator1_DSTAT_n =
    xstar_fcs_P.DiscreteTimeIntegrator1_IC_p;
  xstar_fcs_DW.Memory_101_PreviousInput[0] =
    xstar_fcs_P.Memory_101_InitialCondition;
  xstar_fcs_DW.Memory_101_PreviousInput[1] =
    xstar_fcs_P.Memory_101_InitialCondition;
  xstar_fcs_DW.Memory_101_PreviousInput[2] =
    xstar_fcs_P.Memory_101_InitialCondition;
  xstar_fcs_DW.Memory_101_PreviousInput[3] =
    xstar_fcs_P.Memory_101_InitialCondition;
  xstar_fcs_DW.DelayInput1_DSTATE_i = xstar_fcs_P.DetectChange_vinit_o;
  xstar_fcs_DW.DiscreteTimeIntegrator_DSTAT_mz =
    xstar_fcs_P.DiscreteTimeIntegrator_IC_mi;
  xstar_fcs_DW.Memory_54_PreviousInput = xstar_fcs_P.Memory_54_InitialCondition;
  xstar_fcs_DW.DiscreteTimeIntegrator1_IC_LOAD = 1U;
  xstar_fcs_DW.Memory_118_PreviousInput =
    xstar_fcs_P.Memory_118_InitialCondition;
  xstar_fcs_DW.DiscreteTimeIntegrator5_DSTATE =
    xstar_fcs_P.DiscreteTimeIntegrator5_IC;
  xstar_fcs_DW.DiscreteTimeIntegrator5_DSTAT_i =
    xstar_fcs_P.DiscreteTimeIntegrator5_IC_o;
  xstar_fcs_DW.Delay_DSTATE_kf = xstar_fcs_P.Delay_InitialCondition_bc;
  xstar_fcs_DW.DiscreteTimeIntegrator_DSTATE_d =
    xstar_fcs_P.DiscreteTimeIntegrator_IC_g;
  xstar_fcs_DW.DiscreteTimeIntegrator5_DSTAT_b =
    xstar_fcs_P.DiscreteTimeIntegrator5_IC_f;
  for (xstar_fcs_B.i = 0; xstar_fcs_B.i < 52; xstar_fcs_B.i++) {
    xstar_fcs_DW.Delay_DSTATE_p[xstar_fcs_B.i] =
      xstar_fcs_P.Delay_InitialCondition_bd;
  }

  xstar_fcs_DW.Delay_DSTATE_c = xstar_fcs_P.Delay_InitialCondition_b;
  xstar_fcs_DW.DiscreteTimeIntegrator5_IC_LOAD = 1U;
  xstar_fcs_DW.DiscreteTimeIntegrator5_PrevRes = 2;
  xstar_fcs_DW.DiscreteTimeIntegrator5_IC_LO_b = 1U;
  xstar_fcs_DW.DiscreteTimeIntegrator5_PrevR_c = 2;
  xstar_fcs_DW.DiscreteTimeIntegrator5_DSTA_ac =
    xstar_fcs_P.DiscreteTimeIntegrator5_IC_g;
  xstar_fcs_DW.DiscreteTimeIntegrator5_DSTAT_n =
    xstar_fcs_P.DiscreteTimeIntegrator5_IC_b;
  xstar_fcs_DW.Memory_134_PreviousInput =
    xstar_fcs_P.Memory_134_InitialCondition;
  xstar_fcs_DW.Delay1_DSTATE = xstar_fcs_P.Delay1_InitialCondition;
  xstar_fcs_DW.DiscreteTimeIntegrator1_DSTAT_e =
    xstar_fcs_P.DiscreteTimeIntegrator1_IC_c;
  xstar_fcs_DW.DelayInput1_DSTATE_d = xstar_fcs_P.DetectIncrease_vinit_i;
  xstar_fcs_DW.DiscreteTimeIntegrator_DSTAT_dk =
    xstar_fcs_P.DiscreteTimeIntegrator_IC_j;
  xstar_fcs_DW.Delay_DSTATE_h = xstar_fcs_P.Delay_InitialCondition_h;
  for (xstar_fcs_B.i = 0; xstar_fcs_B.i < 150; xstar_fcs_B.i++) {
    xstar_fcs_DW.TappedDelay2_X[xstar_fcs_B.i] = xstar_fcs_P.delay_init;
    xstar_fcs_DW.TappedDelay2_X_c[xstar_fcs_B.i] = xstar_fcs_P.delay1_init;
    xstar_fcs_DW.TappedDelay2_X_k[xstar_fcs_B.i] = xstar_fcs_P.delay2_init;
    xstar_fcs_DW.TappedDelay2_X_i[xstar_fcs_B.i] = xstar_fcs_P.delay3_init;
  }

  xstar_fcs_DW.DelayInput1_DSTATE_j = xstar_fcs_P.DetectIncrease_vinit;
  xstar_fcs_DW.Memory_97_PreviousInput[0] =
    xstar_fcs_P.Memory_97_InitialCondition;
  xstar_fcs_DW.Memory_97_PreviousInput[1] =
    xstar_fcs_P.Memory_97_InitialCondition;
  xstar_fcs_DW.Memory_97_PreviousInput[2] =
    xstar_fcs_P.Memory_97_InitialCondition;
  for (xstar_fcs_B.i = 0; xstar_fcs_B.i < 537; xstar_fcs_B.i++) {
    xstar_fcs_DW.u80_states[xstar_fcs_B.i] = xstar_fcs_P.u80_InitialStates;
  }

  xstar_fcs_DW.DelayInput1_DSTATE_it = xstar_fcs_P.DetectIncrease1_vinit;
  xstar_fcs_DW.DelayInput1_DSTATE_lh = xstar_fcs_P.DetectIncrease2_vinit;
  xstar_fcs_DW.DiscreteTimeIntegrator3_DSTAT_g =
    xstar_fcs_P.DiscreteTimeIntegrator3_IC_f;
  xstar_fcs_DW.DiscreteTimeIntegrator1_IC_LO_e = 1U;
  xstar_fcs_DW.Delay_118_DSTATE = xstar_fcs_P.Delay_118_InitialCondition;
  xstar_fcs_DW.DelayInput1_DSTATE_kct = xstar_fcs_P.DetectChange_vinit_n;
  xstar_fcs_DW.DelayInput1_DSTATE_gg = xstar_fcs_P.DetectChange1_vinit_n;
  xstar_fcs_DW.Delay_DSTATE_hm = xstar_fcs_P.Delay_InitialCondition_lq;
  xstar_fcs_DW.DiscreteTimeIntegrator_DSTATE_n =
    xstar_fcs_P.DiscreteTimeIntegrator_IC_e;
  xstar_fcs_DW.Delay1_DSTATE_g = xstar_fcs_P.Delay1_InitialCondition_m;
  xstar_fcs_DW.Delay2_DSTATE[0] = xstar_fcs_P.Delay2_InitialCondition;
  xstar_fcs_DW.Delay2_DSTATE[1] = xstar_fcs_P.Delay2_InitialCondition;
  xstar_fcs_DW.Delay2_DSTATE[2] = xstar_fcs_P.Delay2_InitialCondition;
  xstar_fcs_DW.Delay10_DSTATE = xstar_fcs_P.Delay10_InitialCondition;
  xstar_fcs_DW.DelayInput1_DSTATE_jl = xstar_fcs_P.DetectChange_vinit_k;
  xstar_fcs_DW.Memory2_PreviousInput = xstar_fcs_P.Memory2_InitialCondition_p;
  xstar_fcs_DW.DiscreteTimeIntegrator_DSTAT_fh =
    xstar_fcs_P.DiscreteTimeIntegrator_IC_pv;
  xstar_fcs_DW.DelayInput1_DSTATE_h = xstar_fcs_P.DetectChange_vinit_kj;
  xstar_fcs_DW.DiscreteTimeIntegrator_DSTAT_ng =
    xstar_fcs_P.DiscreteTimeIntegrator_IC_iz;
  xstar_fcs_DW.UnitDelay_1_DSTATE = xstar_fcs_P.UnitDelay_1_InitialCondition;
  xstar_fcs_DW.UnitDelay_3_DSTATE = xstar_fcs_P.UnitDelay_3_InitialCondition;
  xstar_fcs_DW.DelayInput1_DSTATE_g = xstar_fcs_P.DetectChange_vinit_o5;
  xstar_fcs_DW.DiscreteTimeIntegrator_DSTAT_fw =
    xstar_fcs_P.DiscreteTimeIntegrator_IC_gq;
  xstar_fcs_DW.DelayInput1_DSTATE_p = xstar_fcs_P.DetectChange1_vinit;
  xstar_fcs_DW.DiscreteTimeIntegrator1_DSTA_hf =
    xstar_fcs_P.DiscreteTimeIntegrator1_IC_k;
  xstar_fcs_DW.DelayInput1_DSTATE_mh = xstar_fcs_P.DetectChange2_vinit;
  xstar_fcs_DW.DiscreteTimeIntegrator2_DSTA_hw =
    xstar_fcs_P.DiscreteTimeIntegrator2_IC_gc;
  xstar_fcs_DW.DiscreteTimeIntegrator5_IC_LO_f = 1U;
  xstar_fcs_DW.DiscreteTimeIntegrator5_IC_L_bz = 1U;
  xstar_fcs_DW.Delay_DSTATE_m = xstar_fcs_P.Delay_InitialCondition_bp;
  xstar_fcs_DW.Counter_ClkEphState = 5U;
  xstar_fcs_DW.Counter_RstEphState = 5U;
  xstar_fcs_DW.Counter_Count = xstar_fcs_P.Counter_InitialCount;
  xstar_fcs_DW.Counter1_ClkEphState = 5U;
  xstar_fcs_DW.Counter1_RstEphState = 5U;
  xstar_fcs_DW.Counter1_Count = xstar_fcs_P.Counter1_InitialCount;
  xstar_fcs_DW.Delay_DSTATE_g = xstar_fcs_P.Delay_InitialCondition_i;
  xstar_fcs_DW.Counter_ClkEphState_m = 5U;
  xstar_fcs_DW.Counter_RstEphState_c = 5U;
  xstar_fcs_DW.Counter_Count_g = xstar_fcs_P.Counter_InitialCount_i;
  xstar_fcs_DW.Counter1_ClkEphState_d = 5U;
  xstar_fcs_DW.Counter1_RstEphState_n = 5U;
  xstar_fcs_DW.Counter1_Count_h = xstar_fcs_P.Counter1_InitialCount_d;
  xstar_fcs_DW.Delay_DSTATE_f = xstar_fcs_P.Delay_InitialCondition_a;
  xstar_fcs_DW.Counter_ClkEphState_my = 5U;
  xstar_fcs_DW.Counter_RstEphState_i = 5U;
  xstar_fcs_DW.Counter_Count_h = xstar_fcs_P.Counter_InitialCount_m;
  xstar_fcs_DW.Counter1_ClkEphState_h = 5U;
  xstar_fcs_DW.Counter1_RstEphState_a = 5U;
  xstar_fcs_DW.Counter1_Count_k = xstar_fcs_P.Counter1_InitialCount_o;
  xstar_fcs_DW.Memory1_12_PreviousInput =
    xstar_fcs_P.Memory1_12_InitialCondition;
  xstar_fcs_DW.Memory1_13_PreviousInput =
    xstar_fcs_P.Memory1_13_InitialCondition;
  xstar_fcs_DW.DiscreteTimeIntegrator5_IC_LO_c = 1U;
  xstar_fcs_DW.Memory1_PreviousInput = xstar_fcs_P.Memory1_InitialCondition_g;
  xstar_fcs_DW.DiscreteTimeIntegrator5_IC_LO_g = 1U;
  for (xstar_fcs_B.i = 0; xstar_fcs_B.i < 150; xstar_fcs_B.i++) {
    xstar_fcs_DW.TappedDelay2_X_l[xstar_fcs_B.i] = xstar_fcs_P.delay1_init_f;
    xstar_fcs_DW.TappedDelay2_X_m[xstar_fcs_B.i] = xstar_fcs_P.delay_init_j;
    xstar_fcs_DW.TappedDelay2_X_f[xstar_fcs_B.i] = xstar_fcs_P.delay2_init_i;
  }

  xstar_fcs_DW.DelayInput1_DSTATE_f = xstar_fcs_P.DetectIncrease_vinit_c;
  xstar_fcs_DW.DiscreteTimeIntegrator_DSTATE_f =
    xstar_fcs_P.DiscreteTimeIntegrator_IC_k;
  xstar_fcs_DW.DiscreteTimeIntegrator1_DSTA_hy =
    xstar_fcs_P.DiscreteTimeIntegrator1_IC_j;
  xstar_fcs_DW.DiscreteTimeIntegrator_DSTATE_j =
    xstar_fcs_P.DiscreteTimeIntegrator_IC_h;
  xstar_fcs_DW.Delay3_DSTATE_n = xstar_fcs_P.Delay3_InitialCondition_l;
  xstar_fcs_DW.Memory1_11_PreviousInput =
    xstar_fcs_P.Memory1_11_InitialCondition;
  xstar_fcs_DW.Memory1_14_PreviousInput =
    xstar_fcs_P.Memory1_14_InitialCondition;
  xstar_fcs_DW.Memory1_15_PreviousInput =
    xstar_fcs_P.Memory1_15_InitialCondition;
  xstar_fcs_DW.Memory1_2_PreviousInput = xstar_fcs_P.Memory1_2_InitialCondition;
  xstar_fcs_DW.Memory1_3_PreviousInput = xstar_fcs_P.Memory1_3_InitialCondition;
  xstar_fcs_DW.Memory1_4_PreviousInput = xstar_fcs_P.Memory1_4_InitialCondition;
  xstar_fcs_DW.Memory1_5_PreviousInput = xstar_fcs_P.Memory1_5_InitialCondition;
  xstar_fcs_DW.Memory1_10_PreviousInput[0] =
    xstar_fcs_P.Memory1_10_InitialCondition;
  xstar_fcs_DW.Memory1_6_PreviousInput[0] =
    xstar_fcs_P.Memory1_6_InitialCondition;
  xstar_fcs_DW.Memory1_7_PreviousInput[0] =
    xstar_fcs_P.Memory1_7_InitialCondition;
  xstar_fcs_DW.Memory1_10_PreviousInput[1] =
    xstar_fcs_P.Memory1_10_InitialCondition;
  xstar_fcs_DW.Memory1_6_PreviousInput[1] =
    xstar_fcs_P.Memory1_6_InitialCondition;
  xstar_fcs_DW.Memory1_7_PreviousInput[1] =
    xstar_fcs_P.Memory1_7_InitialCondition;
  xstar_fcs_DW.Memory1_8_PreviousInput = xstar_fcs_P.Memory1_8_InitialCondition;
  xstar_fcs_DW.Memory1_9_PreviousInput = xstar_fcs_P.Memory1_9_InitialCondition;
  xstar_fcs_DW.DiscreteTimeIntegrator_DSTATE_b =
    xstar_fcs_P.DiscreteTimeIntegrator_IC_m;
  xstar_fcs_DW.DelayInput1_DSTATE_li = xstar_fcs_P.DetectChange_vinit_c;
  xstar_fcs_DW.DiscreteTimeIntegrator_DSTAT_jd =
    xstar_fcs_P.DiscreteTimeIntegrator_IC_l;
  xstar_fcs_DW.DiscreteTimeIntegrator1_IC_LO_g = 1U;
  xstar_fcs_DW.DiscreteTimeIntegrator2_DSTAT_p =
    xstar_fcs_P.DiscreteTimeIntegrator2_IC_au;
  xstar_fcs_DW.DiscreteTimeIntegrator_DSTAT_b0 =
    xstar_fcs_P.DiscreteTimeIntegrator_IC_n;
  xstar_fcs_DW.Delay8_DSTATE[0] = xstar_fcs_P.Delay8_InitialCondition;
  xstar_fcs_DW.Delay8_DSTATE[1] = xstar_fcs_P.Delay8_InitialCondition;
  xstar_fcs_DW.Delay8_DSTATE[2] = xstar_fcs_P.Delay8_InitialCondition;
  xstar_fcs_DW.icLoad = 1U;
  for (xstar_fcs_B.i = 0; xstar_fcs_B.i < 360; xstar_fcs_B.i++) {
    xstar_fcs_DW.Delay2_DSTATE_k[xstar_fcs_B.i] =
      xstar_fcs_P.Delay2_InitialCondition_c;
  }

  xstar_fcs_DW.DiscreteTimeIntegrator_DSTAT_hp =
    xstar_fcs_P.DiscreteTimeIntegrator_IC_mz;
  xstar_fcs_DW.icLoad_p = 1U;
  xstar_fcs_DW.DiscreteTimeIntegrator_DSTATE_k =
    xstar_fcs_P.DiscreteTimeIntegrator_IC_b3;
  xstar_fcs_DW.Delay3_DSTATE[0] = xstar_fcs_P.Delay3_InitialCondition;
  xstar_fcs_DW.Delay6_DSTATE[0] = xstar_fcs_P.Delay6_InitialCondition;
  xstar_fcs_DW.Delay3_DSTATE[1] = xstar_fcs_P.Delay3_InitialCondition;
  xstar_fcs_DW.Delay6_DSTATE[1] = xstar_fcs_P.Delay6_InitialCondition;
  xstar_fcs_DW.Delay3_DSTATE[2] = xstar_fcs_P.Delay3_InitialCondition;
  xstar_fcs_DW.Delay6_DSTATE[2] = xstar_fcs_P.Delay6_InitialCondition;
  xstar_fcs_DW.icLoad_pg = 1U;
  xstar_fcs_DW.DiscreteTimeIntegrator5_DSTAT_k =
    xstar_fcs_P.DiscreteTimeIntegrator5_IC_k;
  xstar_fcs_DW.DiscreteTimeIntegrator5_DSTA_k1 =
    xstar_fcs_P.DiscreteTimeIntegrator5_IC_gn;
  xstar_fcs_DW.DiscreteTimeIntegrator5_DSTAT_e =
    xstar_fcs_P.DiscreteTimeIntegrator5_IC_a;
  for (xstar_fcs_B.i = 0; xstar_fcs_B.i < 50; xstar_fcs_B.i++) {
    xstar_fcs_DW.Delay2_DSTATE_g[xstar_fcs_B.i] =
      xstar_fcs_P.Delay2_InitialCondition_o;
  }

  for (xstar_fcs_B.i = 0; xstar_fcs_B.i < 200; xstar_fcs_B.i++) {
    xstar_fcs_DW.Delay5_DSTATE_f[xstar_fcs_B.i] =
      xstar_fcs_P.Delay5_InitialCondition;
  }

  for (xstar_fcs_B.i = 0; xstar_fcs_B.i < 150; xstar_fcs_B.i++) {
    xstar_fcs_DW.Delay4_DSTATE_j[xstar_fcs_B.i] =
      xstar_fcs_P.Delay4_InitialCondition;
  }

  for (xstar_fcs_B.i = 0; xstar_fcs_B.i < 100; xstar_fcs_B.i++) {
    xstar_fcs_DW.Delay3_DSTATE_e[xstar_fcs_B.i] =
      xstar_fcs_P.Delay3_InitialCondition_k;
  }

  xstar_fcs_B.lambda_0_WGS84_rad = xstar_fcs_P.lambda_0_rad_Y0;
  xstar_fcs_B.mue_0_WGS84_rad = xstar_fcs_P.mue_0_rad_Y0;
  xstar_fcs_B.Add_a = xstar_fcs_P.dx_dmue_Y0;
  xstar_fcs_B.Product4_h = xstar_fcs_P.dy_dlambda_Y0;
  xstar_fcs_DW.Memory_PreviousInput_d[0] = xstar_fcs_P.Memory_InitialCondition;
  xstar_fcs_B.y[0] = xstar_fcs_P.y_Y0[0];
  xstar_fcs_DW.Memory_PreviousInput_d[1] = xstar_fcs_P.Memory_InitialCondition;
  xstar_fcs_B.y[1] = xstar_fcs_P.y_Y0[1];
  xstar_fcs_DW.Memory_PreviousInput_d[2] = xstar_fcs_P.Memory_InitialCondition;
  xstar_fcs_B.y[2] = xstar_fcs_P.y_Y0[2];
  xstar_fcs_B.In1 = xstar_fcs_P.Out1_Y0_o;
  xstar_fcs_B.BusAssignment = xstar_fcs_P.Out1_Y0;
  for (xstar_fcs_B.i = 0; xstar_fcs_B.i < 9; xstar_fcs_B.i++) {
    xstar_fcs_B.In1_d[xstar_fcs_B.i] = xstar_fcs_P.Out1_Y0_i;
  }

  Rotation_AHRS_GPS_Init();
  xstar_fcs_DW.Memory_PreviousInput = xstar_fcs_P.Memory_InitialCondition_i;
  xstar_fcs_DW.Memory2_PreviousInput_c = xstar_fcs_P.Memory2_InitialCondition;
  xstar_fcs_DW.Memory1_PreviousInput_i = xstar_fcs_P.Memory1_InitialCondition;
  xstar_fcs_B.Divide = xstar_fcs_P.p_ref_Y0;
  xstar_fcs_B.g_M_d_R = xstar_fcs_P.dh_dp_Y0;
  xstar_fcs_B.Add_g = xstar_fcs_P.dx_dmue_Y0_k;
  xstar_fcs_B.Product4 = xstar_fcs_P.dy_dlambda_Y0_g;
  xstar_fcs_B.dz_dh = xstar_fcs_P.dz_dh_Y0;
  Translation_Fusion_Init(&xstar_fcs_B.Translation_Fusion_o28);
  xstar_fcs_DW.DiscreteTimeIntegrator_IC_LOA_p = 1U;
  xstar_fcs_MovingAverage2_Init(&xstar_fcs_DW.MovingAverage);
  xstar_fcs_MovingAverage2_Init(&xstar_fcs_DW.MovingAverage1);
  xstar_fcs_MovingAverage2_Init(&xstar_fcs_DW.MovingAverage2);
  xstar_fcs_B.MovingAverage.MovingAverage2 = xstar_fcs_P.gyro_bias_body_Y0;
  xstar_fcs_B.MovingAverage1.MovingAverage2 = xstar_fcs_P.gyro_bias_body_Y0;
  xstar_fcs_B.MovingAverage2.MovingAverage2 = xstar_fcs_P.gyro_bias_body_Y0;
  xstar_fcs_DW.DiscreteTimeIntegrator_IC_LOA_e = 1U;
  xstar_fcs_MovingAverage2_Init(&xstar_fcs_DW.MovingAverage_p);
  xstar_fcs_MovingAverage2_Init(&xstar_fcs_DW.MovingAverage1_p);
  xstar_fcs_MovingAverage2_Init(&xstar_fcs_DW.MovingAverage2_p);
  xstar_fcs_B.MovingAverage_p.MovingAverage2 = xstar_fcs_P.acc_bias_body_Y0;
  xstar_fcs_B.MovingAverage1_p.MovingAverage2 = xstar_fcs_P.acc_bias_body_Y0;
  xstar_fcs_B.MovingAverage2_p.MovingAverage2 = xstar_fcs_P.acc_bias_body_Y0;
  xstar_fcs_DW.DiscreteTimeIntegrator_IC_LOADI = 1U;
  xstar_fcs_MovingAverage2_Init(&xstar_fcs_DW.MovingAverage_pn);
  xstar_fcs_MovingAverage2_Init(&xstar_fcs_DW.MovingAverage1_pn);
  xstar_fcs_MovingAverage2_Init(&xstar_fcs_DW.MovingAverage2_pn);
  xstar_fcs_B.MovingAverage_pn.MovingAverage2 = xstar_fcs_P.gyro_bias_body_Y0_c;
  xstar_fcs_B.MovingAverage1_pn.MovingAverage2 = xstar_fcs_P.gyro_bias_body_Y0_c;
  xstar_fcs_B.MovingAverage2_pn.MovingAverage2 = xstar_fcs_P.gyro_bias_body_Y0_c;
  xstar_fcs_B.Merge[0] = xstar_fcs_P.Merge_InitialOutput[0];
  xstar_fcs_B.Merge[1] = xstar_fcs_P.Merge_InitialOutput[1];
  xstar_fcs_B.Merge[2] = xstar_fcs_P.Merge_InitialOutput[2];
  xstar_fcs_B.Merge[3] = xstar_fcs_P.Merge_InitialOutput[3];
}

void xstar_fcs_terminate(void)
{
  Rotation_AHRS_GPS_Term();
  Translation_Fusion_Term();
  xstar_fcs_MovingAverage2_Term(&xstar_fcs_DW.MovingAverage);
  xstar_fcs_MovingAverage2_Term(&xstar_fcs_DW.MovingAverage1);
  xstar_fcs_MovingAverage2_Term(&xstar_fcs_DW.MovingAverage2);
  xstar_fcs_MovingAverage2_Term(&xstar_fcs_DW.MovingAverage_p);
  xstar_fcs_MovingAverage2_Term(&xstar_fcs_DW.MovingAverage1_p);
  xstar_fcs_MovingAverage2_Term(&xstar_fcs_DW.MovingAverage2_p);
  xstar_fcs_MovingAverage2_Term(&xstar_fcs_DW.MovingAverage_pn);
  xstar_fcs_MovingAverage2_Term(&xstar_fcs_DW.MovingAverage1_pn);
  xstar_fcs_MovingAverage2_Term(&xstar_fcs_DW.MovingAverage2_pn);
}
