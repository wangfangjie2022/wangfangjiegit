/**************************************************************************************
 *
 * 文件描述：LED相关接口
 * 创建日期：
 *
 * 备注：
 *
 **************************************************************************************
 */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __BSP_LED_H
#define __BSP_LED_H

/* Includes ------------------------------------------------------------------*/
#include "stm32h7xx_hal.h"
#include "bsp_gpio.h"

/* Exported_Macros -----------------------------------------------------------*/
/* BAT LED *******************************/
#define LED_BAT_ALL_ON()        HAL_GPIO_WritePin(LED_PWR_R_Port, LED_PWR_G_Pin|LED_PWR_R_Pin, GPIO_PIN_SET)
#define LED_BAT_ALL_OFF()       HAL_GPIO_WritePin(LED_PWR_R_Port, LED_PWR_G_Pin|LED_PWR_R_Pin, GPIO_PIN_RESET)

#define LED_BAT_G_ON()          LED_BAT_ALL_OFF();HAL_GPIO_WritePin(LED_PWR_G_Port, LED_PWR_G_Pin, GPIO_PIN_SET)
#define LED_BAT_G_OFF()         LED_BAT_ALL_OFF()

#define LED_BAT_R_ON()          LED_BAT_ALL_OFF();HAL_GPIO_WritePin(LED_PWR_R_Port, LED_PWR_R_Pin, GPIO_PIN_SET)
#define LED_BAT_R_OFF()         LED_BAT_ALL_OFF()

#define LED_BAT_Y_ON()          LED_BAT_ALL_ON()
#define LED_BAT_Y_OFF()         LED_BAT_ALL_OFF()

/* RTK LED ******************************/
#define LED_RTK_ALL_ON()        \
  do{ \
    HAL_GPIO_WritePin(LED_RTK_R_Port, LED_RTK_R_Pin, GPIO_PIN_SET);  \
    HAL_GPIO_WritePin(LED_RTK_G_Port, LED_RTK_G_Pin, GPIO_PIN_SET);  \
  }while(0)
  
#define LED_RTK_ALL_OFF()       \
  do{ \
    HAL_GPIO_WritePin(LED_RTK_R_Port, LED_RTK_R_Pin, GPIO_PIN_RESET);  \
    HAL_GPIO_WritePin(LED_RTK_G_Port, LED_RTK_G_Pin, GPIO_PIN_RESET);  \
  }while(0)

#define LED_RTK_G_ON()          LED_RTK_ALL_OFF();HAL_GPIO_WritePin(LED_RTK_G_Port, LED_RTK_G_Pin, GPIO_PIN_SET)
#define LED_RTK_G_OFF()         LED_RTK_ALL_OFF()

#define LED_RTK_R_ON()          LED_RTK_ALL_OFF();HAL_GPIO_WritePin(LED_RTK_R_Port, LED_RTK_R_Pin, GPIO_PIN_SET)
#define LED_RTK_R_OFF()         LED_RTK_ALL_OFF()

#define LED_RTK_Y_ON()          LED_RTK_ALL_ON()
#define LED_RTK_Y_OFF()         LED_RTK_ALL_OFF()

#define LED_MATCH_ON()          HAL_GPIO_WritePin(LED_MATCH_G_Port, LED_MATCH_G_Pin, GPIO_PIN_SET)
#define LED_MATCH_OFF()         HAL_GPIO_WritePin(LED_MATCH_G_Port, LED_MATCH_G_Pin, GPIO_PIN_RESET)








/* Exported_Types ------------------------------------------------------------*/



/* Exported_Variables --------------------------------------------------------*/



/* Exported_Functions --------------------------------------------------------*/


























#endif
