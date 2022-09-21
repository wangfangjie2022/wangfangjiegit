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
#ifndef __BSP_MPU6500_H
#define __BSP_MPU6500_H

/* Includes ------------------------------------------------------------------*/
#include "stm32h7xx_hal.h"
#include "bsp_gpio.h"


/* Exported_Macros -----------------------------------------------------------*/

#define SPI1_CS_ENABLE()			  HAL_GPIO_WritePin(SPI1_NSS_Port, SPI1_NSS_Pin, GPIO_PIN_RESET)
#define SPI1_CS_DISABLE()		    HAL_GPIO_WritePin(SPI1_NSS_Port, SPI1_NSS_Pin, GPIO_PIN_SET)

#define IMU_CS_ENABLE()         SPI1_CS_ENABLE()
#define IMU_CS_DISABLE()        SPI1_CS_DISABLE()





// 选择对应的加速度量程
//#define A_SCALE_FACTOR			16384.00		// ±2g
//#define A_SCALE_FACTOR			8192.00			// ±4g
#define A_SCALE_FACTOR			4096.00			// ±8g
//#define A_SCALE_FACTOR			2048.00			// ±16g

// 选择对应的陀螺仪量程
//#define G_SCALE_FACTOR			131.00			// ±250deg/s
//#define G_SCALE_FACTOR			65.50			// ±500deg/s
//#define G_SCALE_FACTOR			32.80			// ±1000deg/s
#define G_SCALE_FACTOR			16.40			// ±2000deg/s

// 温度的Scale
#define T_SCALE_FACTOR			333.87f			// LSB/℃



#define MPU6500_DEVICE_ID		0x70

// 寄存器读写指令
#define REG_W					0x00
#define REG_R					0x80



#define ImuRegAddr_SELF_TEST_X_GYRO			0x00
#define ImuRegAddr_SELF_TEST_Y_GYRO			0x01
#define ImuRegAddr_SELF_TEST_Z_GYRO			0x02

#define ImuRegAddr_SELF_TEST_X_ACCEL		0x0D
#define ImuRegAddr_SELF_TEST_Y_ACCEL		0x0E
#define ImuRegAddr_SELF_TEST_Z_ACCEL		0x0F

#define ImuRegAddr_XG_OFFS_USRH				0x13
#define ImuRegAddr_XG_OFFS_USRL				0x14
#define ImuRegAddr_YG_OFFS_USRH				0x15
#define ImuRegAddr_YG_OFFS_USRL				0x16
#define ImuRegAddr_ZG_OFFS_USRH				0x17
#define ImuRegAddr_ZG_OFFS_USRL				0x18

#define ImuRegAddr_SMPLRT_DIV				0x19
#define ImuRegAddr_CONFIG					0x1A
#define ImuRegAddr_GYRO_CONFIG				0x1B
#define ImuRegAddr_ACCEL_CONFIG				0x1C
#define ImuRegAddr_ACCEL_CONFIG_2			0x1D
#define ImuRegAddr_LP_MODE_CFG				0x1E
#define ImuRegAddr_ACCEL_WOM_THR			0x1F
#define ImuRegAddr_FIFO_EN					0x23

//#define ImuRegAddr_FSYNC_INT				0x36
#define ImuRegAddr_INT_PIN_CFG				0x37
#define ImuRegAddr_INT_ENABLE				0x38
//#define ImuRegAddr_DMP_INT_STATUS			0x39
#define ImuRegAddr_INT_STATUS				0x3A

#define ImuRegAddr_ACCEL_XOUT_H				0x3B
#define ImuRegAddr_ACCEL_XOUT_L				0x3C
#define ImuRegAddr_ACCEL_YOUT_H				0x3D
#define ImuRegAddr_ACCEL_YOUT_L				0x3E
#define ImuRegAddr_ACCEL_ZOUT_H				0x3F
#define ImuRegAddr_ACCEL_ZOUT_L				0x40

#define ImuRegAddr_TEMP_OUT_H				0x41
#define ImuRegAddr_TEMP_OUT_L				0x42

#define ImuRegAddr_GYRO_XOUT_H				0x43
#define ImuRegAddr_GYRO_XOUT_L				0x44
#define ImuRegAddr_GYRO_YOUT_H				0x45
#define ImuRegAddr_GYRO_YOUT_L				0x46
#define ImuRegAddr_GYRO_ZOUT_H				0x47
#define ImuRegAddr_GYRO_ZOUT_L				0x48

#define ImuRegAddr_SIGNAL_PATH_RESET		0x68
#define ImuRegAddr_ACCEL_INTEL_CTRL			0x69
#define ImuRegAddr_USER_CTRL				0x6A
#define ImuRegAddr_PWR_MGMT_1				0x6B
#define ImuRegAddr_PWR_MGMT_2				0x6C

#define ImuRegAddr_FIFO_COUNTH				0x72
#define ImuRegAddr_FIFO_COUNTL				0x73
#define ImuRegAddr_FIFO_R_W					0x74
#define ImuRegAddr_WHO_AM_I					0x75

#define ImuRegAddr_XA_OFFSET_H				0x77
#define ImuRegAddr_XA_OFFSET_L				0x78
#define ImuRegAddr_YA_OFFSET_H				0x7A
#define ImuRegAddr_YA_OFFSET_L				0x7B
#define ImuRegAddr_ZA_OFFSET_H				0x7D
#define ImuRegAddr_ZA_OFFSET_L				0x7E


/* Exported_Types ------------------------------------------------------------*/
typedef enum{
	SPI_BUS_SPEED_781KHZ,
	SPI_BUS_SPEED_1_5MHZ,
	SPI_BUS_SPEED_3_1MHZ,
	SPI_BUS_SPEED_6_2MHZ,
	SPI_BUS_SPEED_12_5MHZ,
	SPI_BUS_SPEED_25MHZ,
	SPI_BUS_SPEED_50MHZ,
	SPI_BUS_SPEED_100MHZ
}eSpixBaudrate;

typedef struct{
  uint8_t  flg_busy;   // 0-空闲；1-忙碌中。
  uint8_t  flg_cplt;   // 0-未完；1-完成。
  uint8_t* txbuf;
  uint8_t* rxbuf;
  uint16_t len;
  uint32_t tx_start_tim;
  uint32_t timout;
}spi_obj_t;



typedef struct{
	int16_t accel_s16[3];
  int16_t temp_s16;
	int16_t gyro_s16[3];	
}tSensor_s16;

typedef struct{
	float accel_f[3];
	float gyro_f[3];
	float temp_f;
}tSensor_f;

typedef struct{
  uint8_t   flg_init;
	uint16_t  tempx10;		// 温度值放大10倍,用于调试时观测温度变化情况
	tSensor_s16 val;		  // 读取到的Sensor原始数据，十六位有符号数
	tSensor_s16 offset;		// Sensor的0刻度偏移量，用于修正零点
	tSensor_f scale;		  // 满量程修正系数
	tSensor_f Sensor;		  // 处理前的Sensor数据，已经转化为g、弧度/s、℃为单位的浮点数
}tImuData;

typedef union{
	int16_t dat16;
	int8_t  dat8[2];
}tRegData;

typedef struct{
	int16_t ax,ay,az;
	int16_t gx,gy,gz;
	float	wx,wy,wz;		// 角速度：弧度/sec
	float	mx,my,mz;
	float	temp;			// 温度：℃
	float	pit,rol,yaw;	// 欧拉角
}imu_t;


/* Exported_Variables --------------------------------------------------------*/
extern tImuData imu_data;
extern SPI_HandleTypeDef hspi1;

/* Exported_Functions --------------------------------------------------------*/
uint8_t bsp_imu_init(void);
void msp_spi1_uninit(void);
void imu_idle_task(void);
void imu_realtime_task(void);























#endif
