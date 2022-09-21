#ifndef _BAT_MANAGER_TASK_H_
#define _BAT_MANAGER_TASK_H_
#ifdef __cplusplus
 extern "C" {
#endif
/* Includes ------------------------------------------------------------------*/
#include "sys_cfg.h"


typedef struct
{
	int CurChargeState;
	int CurBatteryVoltageState;
}Battery_state_t;

typedef enum
{
	ENUM_CHARGE_NONE,//NO CHARGE
	ENUM_POWER_ON_CHARGE,
	ENUM_POWER_OFF_CHARGE,
	ENUM_POWER_COMPELETED_CHARGE,
	ENUM_CHARGE_MAX,
}CHARGE_STATE;

typedef enum
{
	ENUM_BATTERY_VOLTAGE_LESS_LIMITED,//battery voltage too low
	ENUM_BATTERY_CHARGING,
	ENUM_BATTERY_FULL,
}BATTERY_VOLTAGE_STATE;

extern uint16_t gChargeState;   //µç³Ø×´Ì¬


void Battery_Manager_Task(void *pvParameters );
void AddChargeTask(void);
int32_t ChargeTaskInit(void);
void ChargeTask(void);
int32_t ChargeTaskUninit(void);

uint8_t Get_Bat_Percent_Stat(void);
void Normal_Led_Control(void);

void All_Led_Off(void);

#ifdef __cplusplus
}
#endif
#endif /*__ adc_H */

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
