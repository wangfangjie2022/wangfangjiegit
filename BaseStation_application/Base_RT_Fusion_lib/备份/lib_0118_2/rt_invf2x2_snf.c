#include "rtwtypes.h"
#include <math.h>
#include "rt_invf2x2_snf.h"

void rt_invf2x2_snf(const real32_T u[4], real32_T y[4])
{
  real32_T r;
  real32_T t;
  if ((real32_T)fabs(u[1]) > (real32_T)fabs(u[0])) {
    r = u[0] / u[1];
    t = 1.0F / (r * u[3] - u[2]);
    y[0] = u[3] / u[1] * t;
    y[1] = -t;
    y[2] = -u[2] / u[1] * t;
    y[3] = r * t;
  } else {
    r = u[1] / u[0];
    t = 1.0F / (u[3] - r * u[2]);
    y[0] = u[3] / u[0] * t;
    y[1] = -r * t;
    y[2] = -u[2] / u[0] * t;
    y[3] = t;
  }
}
