/**************************************************************************************
 *
 * 文件描述：蜂鸣器控制相关接口
 * 创建日期：
 *
 * 备注：
 *
 **************************************************************************************
 */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __BSP_BEEP_H
#define __BSP_BEEP_H

/* Includes ------------------------------------------------------------------*/
#include "stm32h7xx_hal.h"

/* Exported_Macros -----------------------------------------------------------*/



/* Exported_Types ------------------------------------------------------------*/



/* Exported_Variables --------------------------------------------------------*/



/* Exported_Functions --------------------------------------------------------*/
void Clear_Buzzer(void);
uint8_t BuzzOn_time(uint8_t isAlwaysOn,uint8_t nPrioryty,uint8_t nCount,uint32_t nHighTime, uint32_t nLowTime );
void BuzzControl(void);

























#endif
