/**************************************************************************************
 *
 * 文件描述：头文件合集
 * 创建日期：
 *
 * 备注：
 *
 **************************************************************************************
 */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __INCLUDES_H
#define __INCLUDES_H

/* Includes ------------------------------------------------------------------*/
#include "stm32h7xx_hal.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored"-Waddress-of-packed-member"

#include "alink.h"
#include "alink_types.h"
#include "alink_helpers.h"

#include "bsp_gpio.h"
#include "bsp_beep.h"
#include "bsp_adc.h"
#include "bsp_i2c.h"
#include "bsp_uart.h"
#include "bsp_flash.h"
#include "bsp_iap.h"
#include "bsp_led.h"
#include "bsp_batt.h"

#include "Sys_cfg.h"
#include "cqueue.h"
#include "Apitool.h"
#include "crypt.h"


#include "SystemTask.h"
#include "bat_manager_task.h"
#include "power_task.h"

#include "main.h"



#pragma clang diagnostic pop




/* Exported_Macros -----------------------------------------------------------*/




/* Exported_Types ------------------------------------------------------------*/



/* Exported_Variables --------------------------------------------------------*/



/* Exported_Functions --------------------------------------------------------*/


























#endif
