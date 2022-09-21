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
#include "bsp_timer.h"
#include "bsp_beep.h"
#include "bsp_adc.h"
#include "bsp_i2c.h"
#include "bsp_i2c_hw.h"
#include "bsp_uart.h"
#include "bsp_flash.h"
#include "bsp_iap.h"
#include "bsp_led.h"
#include "bsp_batt.h"
#include "bsp_lis3mdl.h"
#include "bsp_mpu6500.h"
#include "bsp_crc.h"

#include "Sys_cfg.h"
#include "cqueue.h"
#include "Apitool.h"


#include "SystemTask.h"
#include "bat_manager_task.h"
#include "power_task.h"
#include "rtk_manager_task.h"
#include "rtk_pos_set.h"
#include "update_task.h"
#include "imagelink_task.h"
#include "sys_util.h"

#include "main.h"



#pragma clang diagnostic pop




/* Exported_Macros -----------------------------------------------------------*/
#define IRQnPriority_I2C2_EV      10
#define IRQnPriority_I2C2_ER      10

#define IRQnPriority_I2C4_EV      11
#define IRQnPriority_I2C4_ER      11

#define IRQnPriority_SPI1         10


/* Exported_Types ------------------------------------------------------------*/



/* Exported_Variables --------------------------------------------------------*/



/* Exported_Functions --------------------------------------------------------*/


























#endif
