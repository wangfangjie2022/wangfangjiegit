#include "xstar_fcs.h"
#include "rtwtypes.h"

volatile int IsrOverrun = 0;
static boolean_T OverrunFlag = 0;
void rt_OneStep(void)
{
  if (OverrunFlag++) {
    IsrOverrun = 1;
    OverrunFlag--;
    return;
  }

  __enable_irq();
  xstar_fcs_step();
  __disable_irq();
  OverrunFlag--;
}

volatile boolean_T stopRequested = false;
int main(void)
{
  volatile boolean_T runModel = true;
  float modelBaseRate = 0.01;
  float systemClock = 100;
  SystemCoreClockUpdate();
  rtmSetErrorStatus(xstar_fcs_M, 0);
  xstar_fcs_initialize();
  ARMCM_SysTick_Config(modelBaseRate);
  runModel =
    rtmGetErrorStatus(xstar_fcs_M) == (NULL);
  __enable_irq();
  __enable_irq();
  while (runModel) {
    stopRequested = !(
                      rtmGetErrorStatus(xstar_fcs_M) == (NULL));
    runModel = !(stopRequested);
  }

  xstar_fcs_terminate();
  __disable_irq();
  return 0;
}
