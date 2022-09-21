/**************************************************************************************
 *
 * 文件描述：
 * 创建日期：
 *
 * 备注：
 *
 **************************************************************************************
 */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __BSP_CRC_H
#define __BSP_CRC_H

/* Includes ------------------------------------------------------------------*/
#include "stm32h7xx_hal.h"

/* Exported_Macros -----------------------------------------------------------*/



/* Exported_Types ------------------------------------------------------------*/



/* Exported_Variables --------------------------------------------------------*/



/* Exported_Functions --------------------------------------------------------*/
void bsp_crc_init(void);
void HAL_CRC_MspInit(CRC_HandleTypeDef *hcrc);
void HAL_CRC_MspDeInit(CRC_HandleTypeDef *hcrc);
uint32_t hw_crc32_calc(uint8_t* buf, uint32_t len);
























#endif
