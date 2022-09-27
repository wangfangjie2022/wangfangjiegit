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
#ifndef __BSP_GPIO_H
#define __BSP_GPIO_H

/* Includes ------------------------------------------------------------------*/
#include "stm32h7xx_hal.h"

/* Exported_Macros -----------------------------------------------------------*/

/* 模块复位及其它接口------------------------------------------------- */
#define BUZZ_Pin              GPIO_PIN_2
#define BUZZ_GPIO_Port        GPIOE

#define BEEP_ON()             HAL_GPIO_WritePin(BUZZ_GPIO_Port, BUZZ_Pin, GPIO_PIN_SET)
#define BEEP_OFF()            HAL_GPIO_WritePin(BUZZ_GPIO_Port, BUZZ_Pin, GPIO_PIN_RESET)

#define RTK_RST_Pin           GPIO_PIN_2
#define RTK_RST_GPIO_Port     GPIOH

#define RS485_RE_Pin          GPIO_PIN_4
#define RS485_RE_Port         GPIOC

#define HUB_RST_Pin           GPIO_PIN_6
#define HUB_RST_GPIO_Port     GPIOI


#define RS485_TX_ENABLE       HAL_GPIO_WritePin(RS485_RE_Port, RS485_RE_Pin, GPIO_PIN_SET)
#define RS485_RX_ENABLE       HAL_GPIO_WritePin(RS485_RE_Port, RS485_RE_Pin, GPIO_PIN_RESET)


/* WIFI相关接口------------------------------------------------------- */
#define WIFI_RST_Pin          GPIO_PIN_9
#define WIFI_RST_Port         GPIOH

#define WIFI_EN_Pin           GPIO_PIN_5
#define WIFI_EN_Port          GPIOI

#define WIFI_PWR_ON()         HAL_GPIO_WritePin(WIFI_EN_Port, WIFI_EN_Pin, GPIO_PIN_SET)
#define WIFI_PWR_OFF()        HAL_GPIO_WritePin(WIFI_EN_Port, WIFI_EN_Pin, GPIO_PIN_RESET)





/* IMU相关接口-------------------------------------------------------- */
#define SPI1_MOSI_Pin         GPIO_PIN_7
#define SPI1_MOSI_Port        GPIOD

#define SPI1_MISO_Pin         GPIO_PIN_9
#define SPI1_MISO_Port        GPIOG

#define SPI1_NSS_Pin          GPIO_PIN_10
#define SPI1_NSS_Port         GPIOG

#define SPI1_SCK_Pin          GPIO_PIN_11
#define SPI1_SCK_Port         GPIOG

#define IMU_INT_Pin           GPIO_PIN_12
#define IMU_INT_GPIO_Port     GPIOG









/* ADC相关接口-------------------------------------------------------- */
#define VERSION_ADC_Pin       GPIO_PIN_11   // ADC1_INP2
#define VERSION_ADC_Port      GPIOF

#define TEMP1_ADC_Pin         GPIO_PIN_12   // ADC1_INP6
#define TEMP1_ADC_Port        GPIOF

#define TEMP2_ADC_Pin         GPIO_PIN_13   // ADC2_INP2
#define TEMP2_ADC_Port        GPIOF






/* 电源管理相关接口--------------------------------------------------- */
#define RF_POWON2_Pin         GPIO_PIN_10
#define RF_POWON2_Port        GPIOE

#define MCU_POWON_Pin         GPIO_PIN_12
#define MCU_POWON_Port        GPIOE

#define VBUS_EN_Pin           GPIO_PIN_6
#define VBUS_EN_Port          GPIOG





/* 按键和LED相关接口-------------------------------------------------- */
#define KEY_MATCH_Pin         GPIO_PIN_5
#define KEY_MATCH_Port        GPIOE

#define KEY_PWR_Pin           GPIO_PIN_11
#define KEY_PWR_Port          GPIOE

#define READ_MATCH_KEY				HAL_GPIO_ReadPin(KEY_MATCH_Port, KEY_MATCH_Pin)




#define LED_DEBUG_G_Pin       GPIO_PIN_1
#define LED_DEBUG_G_Port      GPIOC

#define LED_DEBUG_R_Pin       GPIO_PIN_2
#define LED_DEBUG_R_Port      GPIOC

#define LED_RTK_G_Pin         GPIO_PIN_3
#define LED_RTK_G_Port        GPIOC

#define LED_RTK_R_Pin         GPIO_PIN_0
#define LED_RTK_R_Port        GPIOA

#define LED_PWR_R_Pin         GPIO_PIN_1
#define LED_PWR_R_Port        GPIOA

#define LED_PWR_G_Pin         GPIO_PIN_2
#define LED_PWR_G_Port        GPIOA

#define LED_MATCH_G_Pin       GPIO_PIN_4
#define LED_MATCH_G_Port      GPIOH

#define LED_R_WARNING_Pin     GPIO_PIN_0
#define LED_R_WARNING_Port    GPIOG

#define LED_G_RUN_Pin         GPIO_PIN_1
#define LED_G_RUN_Port        GPIOG





/* I2C相关接口-------------------------------------------------------- */
/* I2C2 磁力计1接口（备用） */
#define I2C2_SDA_Pin          GPIO_PIN_0
#define I2C2_SDA_Port         GPIOF

#define I2C2_SCL_Pin          GPIO_PIN_1
#define I2C2_SCL_Port         GPIOF

/* I2C3 编码器接口（备用） */
#define I2C3_SDA_Pin          GPIO_PIN_8
#define I2C3_SDA_Port         GPIOH

#define I2C3_SCL_Pin          GPIO_PIN_7
#define I2C3_SCL_Port         GPIOH

/* I2C4 磁力计2接口 */
#define I2C4_SDA_Pin          GPIO_PIN_12
#define I2C4_SDA_Port         GPIOH

#define I2C4_SCL_Pin          GPIO_PIN_11
#define I2C4_SCL_Port         GPIOH

/* 辅助接口 */
#define MAG1_INT_Pin          GPIO_PIN_2
#define MAG1_INT_Port         GPIOF

#define MAG2_INT_Pin          GPIO_PIN_10
#define MAG2_INT_Port         GPIOH






/* UART相关接口------------------------------------------------------- */

// USART1 ---电池通讯RS485接口
#define USART1_RX_Pin         GPIO_PIN_10
#define USART1_RX_Port        GPIOA
#define USART1_TX_Pin         GPIO_PIN_9
#define USART1_TX_Port        GPIOA

// USART2 ---RTK COM1
#define USART2_RX_Pin         GPIO_PIN_6    
#define USART2_RX_Port        GPIOD
#define USART2_TX_Pin         GPIO_PIN_5   
#define USART2_TX_Port        GPIOD

// USART3 ---WIFI AR9342
#define USART3_RX_Pin         GPIO_PIN_9
#define USART3_RX_Port        GPIOD
#define USART3_TX_Pin         GPIO_PIN_8
#define USART3_TX_Port        GPIOD

// USART6 ---备用
#define USART6_RX_Pin         GPIO_PIN_7    
#define USART6_RX_Port        GPIOC
#define USART6_TX_Pin         GPIO_PIN_6    
#define USART6_TX_Port        GPIOC

// UART8  ---接天线端MCU
#define UART8_RX_Pin          GPIO_PIN_0
#define UART8_RX_Port         GPIOE
#define UART8_TX_Pin          GPIO_PIN_1
#define UART8_TX_Port         GPIOE

// RTK COM2(PPK)<-->图传COM2

// WIFI USB <--> 图传USB


//// UART4  ---图传COM1
//#define UART4_RX_Pin          GPIO_PIN_11   
//#define UART4_RX_Port         GPIOA
//#define UART4_TX_Pin          GPIO_PIN_12   
//#define UART4_TX_Port         GPIOA



//// UART7  ---图传COM2
//#define UART7_RX_Pin          GPIO_PIN_7
//#define UART7_RX_Port         GPIOE
//#define UART7_TX_Pin          GPIO_PIN_8
//#define UART7_TX_Port         GPIOE







/* USB相关接口-------------------------------------------------------- */




/* Debug相关接口------------------------------------------------------ */




#define DBG_GPIO_Pin1         GPIO_PIN_13
#define DBG_GPIO_Port         GPIOD

#define DBG_GPIO_Pin2         GPIO_PIN_14

#define DBG_GPIO_Pin3         GPIO_PIN_15


#define DEBUG_GPIO_TOGGLE(GPIO_PINx) 			HAL_GPIO_TogglePin(DBG_GPIO_Port, GPIO_PINx)
#define DEBUG_GPIO_H(GPIO_PINx) 			    HAL_GPIO_WritePin(DBG_GPIO_Port, GPIO_PINx, GPIO_PIN_SET)
#define DEBUG_GPIO_L(GPIO_PINx) 			    HAL_GPIO_WritePin(DBG_GPIO_Port, GPIO_PINx, GPIO_PIN_RESET)

/* Exported_Types ------------------------------------------------------------*/



/* Exported_Variables --------------------------------------------------------*/



/* Exported_Functions --------------------------------------------------------*/






















#endif
