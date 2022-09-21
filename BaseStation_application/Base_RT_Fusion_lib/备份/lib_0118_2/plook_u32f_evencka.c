#include "rtwtypes.h"
#include "plook_u32f_evencka.h"

uint32_T plook_u32f_evencka(real32_T u, real32_T bp0, real32_T bpSpace, uint32_T
  maxIndex)
{
  uint32_T bpIndex;
  real32_T fbpIndex;
  if (u <= bp0) {
    bpIndex = 0U;
  } else {
    fbpIndex = (u - bp0) * (1.0F / bpSpace);
    if (fbpIndex < maxIndex) {
      bpIndex = (uint32_T)fbpIndex;
    } else {
      bpIndex = maxIndex;
    }
  }

  return bpIndex;
}
