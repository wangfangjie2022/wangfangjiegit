/**************************************************************************************
 *
 * 文件描述：I2C底层驱动接口(GPIO软件模拟)
 * 创建日期：
 *
 * 备注：
 *
 **************************************************************************************
 */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __BSP_I2C_H
#define __BSP_I2C_H

/* Includes ------------------------------------------------------------------*/
#include "stm32h7xx_hal.h"
#include "bsp_gpio.h"

/* Exported_Macros -----------------------------------------------------------*/
#undef NULL  
#define NULL 0

#define  I2C_Pin_SCL          I2C2_SCL_Pin
#define  I2C_Pin_SDA          I2C2_SDA_Pin
#define  PWR_I2C_Port         I2C2_SDA_Port


#define  SCL_H                (PWR_I2C_Port->BSRR = I2C_Pin_SCL)
#define  SCL_L                (PWR_I2C_Port->BSRR = I2C_Pin_SCL<<16)
#define  SDA_H                (PWR_I2C_Port->BSRR = I2C_Pin_SDA)
#define  SDA_L                (PWR_I2C_Port->BSRR = I2C_Pin_SDA<<16)
#define  SCL_R                (PWR_I2C_Port->IDR  & I2C_Pin_SCL)
#define  SDA_R                (PWR_I2C_Port->IDR  & I2C_Pin_SDA)

#define  ACK        0
#define  NACK       1

/* Exported_Types ------------------------------------------------------------*/
typedef enum{
  eI2C_OK = 0,
  eI2C_ERR,
  eI2C_BUSY,
  eI2C_TIMOUT,  
}I2cSta_t;



/* Exported_Variables --------------------------------------------------------*/



/* Exported_Functions --------------------------------------------------------*/
void delay_nms(uint32_t nms);
void I2C_GPIO_Init(void);
I2cSta_t I2C_R_Nbyte( uint8_t I2C_Addr, uint8_t reg_addr, uint8_t *buf, uint16_t num, uint8_t mode);
I2cSta_t I2C_W_Nbyte( uint8_t I2C_Addr, uint8_t reg_addr, uint8_t *buf, uint16_t num, uint8_t mode);

























#endif
