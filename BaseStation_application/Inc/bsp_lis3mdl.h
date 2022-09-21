/**************************************************************************************
 *
 * 文件描述：磁力计相关接口
 * 创建日期：
 *
 * 备注：
 *
 **************************************************************************************
 */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __BSP_LIS3MDL_H
#define __BSP_LIS3MDL_H

/* Includes ------------------------------------------------------------------*/
#include "stm32h7xx_hal.h"




/* Exported_Macros -----------------------------------------------------------*/

#if 0
/* 磁力计型号：IST8310------------------ */
#define IST8310_ADDRESS               0x0E
#define IST8310_R_W_ADDRESS           0x3D
#define IST_ADDR_WAI                  0x00
#define IST_ADDR_STAT1                0x02
#define IST_ADDR_DATA_OUT_X_LSB       0x03
#define IST_ADDR_DATA_OUT_X_MSB       0x04
#define IST_ADDR_DATA_OUT_Y_LSB       0x05
#define IST_ADDR_DATA_OUT_Y_MSB       0x06
#define IST_ADDR_DATA_OUT_Z_LSB       0x07
#define IST_ADDR_DATA_OUT_Z_MSB       0x08
#define IST_ADDR_STAT2                0x09
#define IST_ADDR_CNTL1                0x0A
#define IST_ADDR_CNTL2                0x0B
#define IST_ADDR_TEMPL                0x1C
#define IST_ADDR_TEMPH                0x1D
  
#define IST_ADDR_STR                  0x0C
#define IST_ADDR_AVR_CNTL             0x41
#define IST_ADDR_PD_CNTL              0x42
#define IST_ADDR_ID                   0x3d
#define IST_Reg_Byte                  1

#else
/* 磁力计型号：LIS3MDL------------------ */
#define LIS3MDL_DEV_ADDR              0x3C
#define LIS3MDL_ADDR_WAI              0x0F
#define LIS3MDL_ADDR_CTRL_REG1		    0x20
#define LIS3MDL_ADDR_CTRL_REG2		    0x21
#define LIS3MDL_ADDR_CTRL_REG3		    0x22
#define LIS3MDL_ADDR_CTRL_REG4		    0x23
#define LIS3MDL_ADDR_CTRL_REG5		    0x24

#define LIS3MDL_ADDR_STATUS_REG		    0x27
#define LIS3MDL_ADDR_OUT_X_L		      0x28
#define LIS3MDL_ADDR_OUT_X_H		      0x29
#define LIS3MDL_ADDR_OUT_Y_L		      0x2a
#define LIS3MDL_ADDR_OUT_Y_H		      0x2b
#define LIS3MDL_ADDR_OUT_Z_L		      0x2c
#define LIS3MDL_ADDR_OUT_Z_H		      0x2d
#define LIS3MDL_ADDR_OUT_T_L		      0x2e
#define LIS3MDL_ADDR_OUT_T_H		      0x2f

#define MODE_REG_CONTINOUS_MODE		    (0 << 0)
#define MODE_REG_SINGLE_MODE		      (1 << 0) /* default */

#define LIS3MDL_ID_A_WHO_AM_I         0x3D

#define LIS3MDL_CNTL2_SRST_SHIFTS     0x00
#define LIS3MDL_CNTL2_SRST            (1 << LIS3MDL_CNTL2_SRST_SHIFTS)

#endif


/* Exported_Types ------------------------------------------------------------*/
typedef struct{
  int16_t mag_x;
  int16_t mag_y;
  int16_t mag_z;
  int16_t temp;
  uint8_t flg_init;
  uint8_t lock;           // 0-未锁，可读；1-已锁，禁止读。
}mag_args_t;

typedef enum{
  eMagReadCmd_NULL= 0,
  eMagReadCmd_DEV_ID,
  eMagReadCmd_STATUS,
  eMagReadCmd_OUT_XYZ,
  
}mag_read_cmd_e;

typedef struct{
  mag_read_cmd_e  cmd;
  uint8_t         reg_addr;
  uint8_t         len;
}mag_reg_read_t;


typedef struct{
  uint8_t   reg_addr;
  uint8_t   val;
}mag_reg_set_t;












/* Exported_Variables --------------------------------------------------------*/
extern I2C_HandleTypeDef hi2c4;
extern mag_args_t mag_args;


extern uint32_t  RAW[7];



/* Exported_Functions --------------------------------------------------------*/

void bsp_mag_init(void);
void mag_idle_task(void);





















#endif
