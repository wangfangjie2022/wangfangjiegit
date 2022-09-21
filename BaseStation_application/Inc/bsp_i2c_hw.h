/**************************************************************************************
 *
 * 文件描述：I2C底层驱动接口(硬件I2C)
 * 创建日期：
 *
 * 备注：
 *
 **************************************************************************************
 */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __BSP_I2C_HW_H
#define __BSP_I2C_HW_H

/* Includes ------------------------------------------------------------------*/
#include "stm32h7xx_hal.h"
#include "bsp_gpio.h"

/* Exported_Macros -----------------------------------------------------------*/



/* Exported_Types ------------------------------------------------------------*/
typedef struct{
  I2C_HandleTypeDef hi2c;
  uint8_t  flg_init;
  uint8_t  dev_addr;
  uint8_t* txbuf;
  uint8_t* rxbuf;
  uint16_t txlen;
  uint16_t rxlen;
  uint8_t  errcnt;
  uint8_t  lock;          // 0-未锁；1-已锁。
  uint8_t  flg_tx_cplt;   // 0-未完；1-完成。
  uint8_t  flg_rx_cplt;
  uint32_t tx_start_tim;
  uint32_t rx_start_tim;
}i2c_obj_t;



/* Exported_Variables --------------------------------------------------------*/
extern I2C_HandleTypeDef hi2c4;
extern i2c_obj_t i2c2_obj, i2c4_obj;











/* Exported_Functions --------------------------------------------------------*/

void msp_i2c_init(I2C_TypeDef* I2Cx);
void msp_i2c_uninit(I2C_TypeDef* I2Cx);
void msp_i2c_reset(I2C_TypeDef* I2Cx);

int msp_i2c_polling_tx_rx( i2c_obj_t* i2cobj, uint8_t dev_addr, \
                            uint8_t* txbuf, uint8_t* rxbuf, \
                            uint16_t txlen, uint16_t rxlen, uint32_t timout);

int msp_i2c_it_tx_rx( i2c_obj_t* i2cobj, uint8_t dev_addr, \
                        uint8_t* txbuf, uint8_t* rxbuf, \
                        uint16_t txlen, uint16_t rxlen);















#endif
