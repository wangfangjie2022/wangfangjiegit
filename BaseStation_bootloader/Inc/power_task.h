/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef _POWER_TASK_H_
#define _POWER_TASK_H_
#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/

#include "Sys_cfg.h"
#include "bsp_gpio.h"
typedef enum
{
	ENUM_POWER_OFF,
	ENUM_POWER_ON,
}POWER_STATE;

#define MCU_POW_OUT_ON()				HAL_GPIO_WritePin(MCU_POWON_Port, MCU_POWON_Pin, GPIO_PIN_SET)	     //PB8		
#define MCU_POW_OUT_OFF()				HAL_GPIO_WritePin(MCU_POWON_Port, MCU_POWON_Pin, GPIO_PIN_RESET)
#define MCU_POW_OUT_TOGGLE()		HAL_GPIO_TogglePin(MCU_POWON_Port, MCU_POWON_Pin)

#define RF_POW2_OUT_ON()				HAL_GPIO_WritePin(RF_POWON2_Port, RF_POWON2_Pin, GPIO_PIN_SET)	     //PE10		
#define RF_POW2_OUT_OFF()				HAL_GPIO_WritePin(RF_POWON2_Port, RF_POWON2_Pin, GPIO_PIN_RESET)
#define RF_POW2_OUT_TOGGLE()		HAL_GPIO_TogglePin(RF_POWON2_Port, RF_POWON2_Pin)

extern uint16_t VbusVal;


uint8_t gGetCurPowerState(void);
//void Power_Manager_Task(void *pvParameters );
void gTogglePowerSate(void);
uint8_t Send_Message_To_Init_RTK(void);
void LedPowRedAndGreenShark(uint32_t interval);

void PowerCtrlInit(void);
void AddPowerTask(void);
int32_t PowerTaskInit(void);
void PowerTask(void);
int32_t PowerTaskUninit(void);
void poweron_proc(void);

void LedPowGreenShark(uint32_t interval);
void LedPowRedShark(uint32_t interval);

void Power_Control(void);
uint8_t BuzzOn_time(uint8_t nAlwaysOn,uint8_t buzzstat,uint8_t nCount,uint32_t nHighTime, uint32_t nLowTime);
void BuzzControl(void);
uint8_t Get_Beep_Count(void);

void RF_Init(void);
void RF_DeInit(void);
void PowerKey_Process(void);
uint8_t Led_Pow_Short_On(void);
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
