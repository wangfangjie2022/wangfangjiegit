/**************************************************************************************
 *
 * 文件描述：MPU6500相关接口
 * 创建日期：
 *
 * 备注：MPU6500的SPI接口配置阶段建议1MHz时钟频率，只读模式下时钟频率建议＜20MHz
 *
 **************************************************************************************
 */

/* Includes ------------------------------------------------------------------*/
#include "bsp_mpu6500.h"
#include "includes.h"
#include "xstar_fcs.h"

/* Private_Defines -----------------------------------------------------------*/



/* Private_TypesDefinitions --------------------------------------------------*/



/* Private_Variables ---------------------------------------------------------*/
SPI_HandleTypeDef hspi1;

spi_obj_t spi1_obj={
  .flg_busy= 0,  
};

tImuData imu_data={
  .flg_init= 0,
};


/* FunctionPrototypes --------------------------------------------------------*/



/* Functions -----------------------------------------------------------------*/

/******************************************************************************
 * 功能：
 * 输入：无          
 * 返回：
 * 说明：
 *
 *****************************************************************************/
void wait_nms(uint16_t ms)
{
  uint32_t tim= GET_CURTICK;
  
  while(1){
    if(GET_PASTTICK(tim) >= ms)break;
  }
}



/******************************************************************************
 * 功能：选择SPI接口的时钟速率
 * 输入：baudrate  --SPI接口的波特率。         
 * 返回：
 * 说明：
 *
 *****************************************************************************/
uint32_t msp_spix_baudrate_select(eSpixBaudrate rate)
{
	uint32_t BaudRatePrescaler;

	if(rate == SPI_BUS_SPEED_781KHZ)
		BaudRatePrescaler = SPI_BAUDRATEPRESCALER_256;
	else if(rate == SPI_BUS_SPEED_1_5MHZ)
		BaudRatePrescaler = SPI_BAUDRATEPRESCALER_128;
	else if(rate == SPI_BUS_SPEED_3_1MHZ)
		BaudRatePrescaler = SPI_BAUDRATEPRESCALER_64;
	else if(rate == SPI_BUS_SPEED_6_2MHZ)
		BaudRatePrescaler = SPI_BAUDRATEPRESCALER_32;
	else if(rate == SPI_BUS_SPEED_12_5MHZ)
		BaudRatePrescaler = SPI_BAUDRATEPRESCALER_16;
	else if(rate == SPI_BUS_SPEED_25MHZ)
		BaudRatePrescaler = SPI_BAUDRATEPRESCALER_8;
	else if(rate == SPI_BUS_SPEED_50MHZ)
		BaudRatePrescaler = SPI_BAUDRATEPRESCALER_4;
	else if(rate == SPI_BUS_SPEED_100MHZ)
		BaudRatePrescaler = SPI_BAUDRATEPRESCALER_2;
	else
		BaudRatePrescaler = SPI_BAUDRATEPRESCALER_32;

	return BaudRatePrescaler;
}


/******************************************************************************
 * 功能：SPI1接口的初始化
 * 输入：baudrate  --SPI接口的波特率。          
 * 返回：
 * 说明：
 *
 *****************************************************************************/
void msp_spi1_init(eSpixBaudrate baudrate)
{
  uint32_t BaudRatePrescaler= msp_spix_baudrate_select(baudrate);
  
  __HAL_RCC_SPI1_CLK_ENABLE();
  
  hspi1.Instance                = SPI1;
  hspi1.Init.Mode               = SPI_MODE_MASTER;
  hspi1.Init.Direction          = SPI_DIRECTION_2LINES;
  hspi1.Init.DataSize           = SPI_DATASIZE_8BIT;
  hspi1.Init.CLKPolarity        = SPI_POLARITY_HIGH;
  hspi1.Init.CLKPhase           = SPI_PHASE_2EDGE;
  hspi1.Init.NSS                = SPI_NSS_SOFT;
  hspi1.Init.BaudRatePrescaler  = BaudRatePrescaler;
  hspi1.Init.FirstBit           = SPI_FIRSTBIT_MSB;
  hspi1.Init.TIMode             = SPI_TIMODE_DISABLE;
  hspi1.Init.CRCCalculation     = SPI_CRCCALCULATION_DISABLE; 
  hspi1.Init.NSSPMode           = SPI_NSS_PULSE_DISABLE;
  
  hspi1.Init.NSSPolarity        = SPI_NSS_POLARITY_LOW;
	hspi1.Init.FifoThreshold      = SPI_FIFO_THRESHOLD_01DATA;
  hspi1.Init.MasterSSIdleness   = SPI_MASTER_SS_IDLENESS_00CYCLE;
	hspi1.Init.MasterInterDataIdleness  = SPI_MASTER_INTERDATA_IDLENESS_00CYCLE;
	hspi1.Init.MasterReceiverAutoSusp   = SPI_MASTER_RX_AUTOSUSP_DISABLE;
	hspi1.Init.MasterKeepIOState  = SPI_MASTER_KEEP_IO_STATE_ENABLE;
	hspi1.Init.IOSwap             = SPI_IO_SWAP_DISABLE;
    
  HAL_SPI_Init(&hspi1);
  
  HAL_NVIC_SetPriority(SPI1_IRQn, IRQnPriority_SPI1, 0); 
  HAL_NVIC_EnableIRQ(SPI1_IRQn); 
}



void msp_spi1_uninit(void)
{
	HAL_SPI_DeInit(&hspi1);
	__HAL_RCC_SPI1_CLK_DISABLE();
	HAL_NVIC_DisableIRQ(SPI1_IRQn);
}

/******************************************************************************
 * 功能：SPI1中断方式收发接口，仅启动发送
 * 输入：txbuf -发送缓冲区；rxbuf -接收缓冲区；len -收发的字节数。          
 * 返回：0：成功；-1：失败。
 * 说明：
 *
 *****************************************************************************/
int msp_spi1_it_tx_rx(uint8_t* txbuf, uint8_t* rxbuf, uint16_t len)
{  
  
  if (spi1_obj.flg_busy) return -1;
  
  spi1_obj.flg_busy= 1;
  spi1_obj.flg_cplt= 0;
  spi1_obj.rxbuf= rxbuf;
  spi1_obj.len= len;
  spi1_obj.tx_start_tim= GET_CURTICK;
  
  SPI1_CS_ENABLE();
  if(HAL_SPI_TransmitReceive_IT(&hspi1, txbuf, rxbuf, len) != HAL_OK)
  {
    SPI1_CS_DISABLE();
    spi1_obj.flg_busy= 0;
    return -1;
  }
  
  return 0;
}


/******************************************************************************
 * 功能：SPI收发完成中断回调函数
 * 输入：无          
 * 返回：无
 * 说明：无
 *
 *****************************************************************************/
void HAL_SPI_TxRxCpltCallback(SPI_HandleTypeDef *hspi)
{
  if(hspi->Instance == SPI1)
  {
    SPI1_CS_DISABLE();
    spi1_obj.flg_busy= 0;
    spi1_obj.flg_cplt= 1;
  }
}


/******************************************************************************
 * 功能：SPI错误中断回调函数
 * 输入：无          
 * 返回：无
 * 说明：无
 *
 *****************************************************************************/
void HAL_SPI_ErrorCallback(SPI_HandleTypeDef *hspi)
{
  
}

/******************************************************************************
 * 函数功能：MPU6500的寄存器写接口
 * 输入：regaddr	---寄存器地址
 * 		 val		---待写入的数据
 * 输出：无
 * 备注：无
 *****************************************************************************/
void mpu6500_regwrite(uint8_t regaddr, uint8_t val)
{
  uint8_t buf[2];
  
	IMU_CS_ENABLE(); 
  buf[0]= regaddr | REG_W;
  buf[1]= val; 
  HAL_SPI_Transmit(&hspi1, buf, 2, 2);
	IMU_CS_DISABLE();
}

/******************************************************************************
 * 函数功能：MPU6500的寄存器读接口
 * 输入：regaddr	---寄存器地址
 * 输出：uint8_t	---读取到的数据
 * 备注：无
 *****************************************************************************/
uint8_t mpu6500_regread(uint8_t regaddr)
{
  uint8_t txbuf[2],rxbuf[2];
  
	IMU_CS_ENABLE();  
  txbuf[0]= regaddr | REG_R;
  txbuf[1]= 0;
  HAL_SPI_TransmitReceive(&hspi1, txbuf, rxbuf, 2, 2); 
	IMU_CS_DISABLE();
  
	return rxbuf[1];
}


/******************************************************************************
 * 函数功能：设置MPU6500的数字低通滤波器
 * 输入：lpf	---数字低通滤波频率(Hz)
 * 输出：无
 * 备注：无
 *****************************************************************************/
void mpu_set_lpf(uint8_t regaddr, uint16_t lpf)
{
	uint8_t data=0;

	if(lpf>=188)data=1;
	else if(lpf>=98)data=2;
	else if(lpf>=42)data=3;
	else if(lpf>=20)data=4;
	else if(lpf>=10)data=5;
	else data=6;

	mpu6500_regwrite(regaddr, data);//设置数字低通滤波器
}


/******************************************************************************
 * 函数功能：设置MPU6500的采样率(假定Fs=1KHz)
 * 输入：rate	---采样率，4~1000(Hz)
 * 输出：无
 * 备注：无
 *****************************************************************************/
void mpu_set_sample_rate(uint16_t rate)
{
	uint8_t data;

	if(rate>1000)rate=1000; //最大1khz采样率
	if(rate<4)rate=4;
	data=1000/rate-1; //根据公式算出得

	mpu6500_regwrite(ImuRegAddr_SMPLRT_DIV, data);//设置采样率
}






/******************************************************************************
 * 功能：系统上电后对IMU进行初始化设置，配置工作模式等。
 * 输入：无
 * 返回：0：初始化未完成；1：初始化已完成。
 * 备注：无
 *****************************************************************************/
uint8_t bsp_imu_init(void)
{
  msp_spi1_init(SPI_BUS_SPEED_3_1MHZ);

	// reset internal registers to default setting
	mpu6500_regwrite(ImuRegAddr_PWR_MGMT_1, 0x80);
	wait_nms(100);

	// wait device ready
	uint16_t i=0;
	do{
		if(MPU6500_DEVICE_ID == mpu6500_regread(ImuRegAddr_WHO_AM_I))break;
		wait_nms(10);
		if(++i > 100)return 0;		// 1000ms timeout
	}while(1);

	// reset internal registers to default setting
	mpu6500_regwrite(ImuRegAddr_PWR_MGMT_1, 0x80);
	wait_nms(100);

	// Accel, Temp digital signal path reset
	mpu6500_regwrite(ImuRegAddr_SIGNAL_PATH_RESET, 0x07);
	wait_nms(100);

	// Wake up device and select GyroZ clock.
	mpu6500_regwrite(ImuRegAddr_PWR_MGMT_1, 0x03);
	wait_nms(10);

	// Disable I2C bus (recommended on datasheet)
	mpu6500_regwrite(ImuRegAddr_USER_CTRL, 0x10);
	wait_nms(10);

	mpu_set_sample_rate(1000);	// 设置采样率1000Hz
	wait_nms(10);

	// Gyro, DLPF = 30Hz
	mpu_set_lpf(ImuRegAddr_CONFIG, 30);
	wait_nms(10);

	// Accel, DLPF = 10Hz
	mpu_set_lpf(ImuRegAddr_ACCEL_CONFIG_2, 10);
	wait_nms(10);

	// Gyro scale 2000 deg/s
	mpu6500_regwrite(ImuRegAddr_GYRO_CONFIG, 0x18);
	wait_nms(10);

	// Accel scale ±8g
	mpu6500_regwrite(ImuRegAddr_ACCEL_CONFIG, 0x10);
	wait_nms(10);

	// INT CFG => Interrupt on Data Ready
	mpu6500_regwrite(ImuRegAddr_INT_ENABLE, 0x01);
	wait_nms(10);

	// INT: Clear on any read
	mpu6500_regwrite(ImuRegAddr_INT_PIN_CFG, 0x10);
	wait_nms(10);
	
	imu_data.flg_init= 1;
  
  return 1;

}




/**************************************************************************************
 * 函数功能：读取IMU加速度计和陀螺仪的数据，一般会周期性读取（推荐100Hz以上）。
 * 输入：无
 * 输出：无
 * 备注：无
 *****************************************************************************/
void imu_read(void)
{
	uint8_t rxbuf[15],txbuf[15];
	uint8_t i=0;
  
  IMU_CS_ENABLE();
  txbuf[0]= ImuRegAddr_ACCEL_XOUT_H  | REG_R;
  memset(&txbuf[1], 0, 14);
  memset(&rxbuf[0], 0, 15);
  
  HAL_SPI_TransmitReceive(&hspi1, txbuf, rxbuf, 15, 10);
  IMU_CS_DISABLE();
  
	imu_data.val.accel_s16[0]= rxbuf[1]*256 + rxbuf[2];
	imu_data.val.accel_s16[1]= rxbuf[3]*256 + rxbuf[4];
	imu_data.val.accel_s16[2]= rxbuf[5]*256 + rxbuf[6];
	imu_data.val.temp_s16= rxbuf[7]*256 + rxbuf[8];
	imu_data.val.gyro_s16[0]= rxbuf[9]*256 + rxbuf[10];
	imu_data.val.gyro_s16[1]= rxbuf[11]*256 + rxbuf[12];
	imu_data.val.gyro_s16[2]= rxbuf[13]*256 + rxbuf[14];

}


/******************************************************************************
 * 功能：IMU数据的拷贝
 * 输入：dst-目的地址；src-源地址。         
 * 返回：无
 * 说明：IMU读出数据为大端模式，拷贝时会转换为小端模式。
 *
 *****************************************************************************/
void imu_data_copy(uint8_t* dst, uint8_t* src, uint16_t len)
{  
  for (uint8_t i=0; i<len; i+=2)
  {
    dst[i+1]= src[i];
    dst[i]= src[i+1];
  }
}

/******************************************************************************
 * 功能：IMU非实时任务的运行
 * 输入：无          
 * 返回：无
 * 说明：周期性调用即可
 *
 *****************************************************************************/
extern unsigned char g_open_flag;

void imu_idle_task(void)
{
  static uint8_t txbuf[20], rxbuf[20];
  static uint32_t runtim=0;

  if (!imu_data.flg_init) return;
  if (GET_PASTTICK(runtim) < 10) return;
  runtim = GET_CURTICK;

  xstar_fcs_U.sensors.MPU6500.Timestamp_ms = run_time() / 1000000.0;//GET_CURTICK;

  HAL_GPIO_WritePin(LED_G_RUN_Port, LED_G_RUN_Pin, GPIO_PIN_RESET);
  /* 保存读取到的IMU数据 */
  if (spi1_obj.flg_cplt)
  {
    imu_data_copy((void*)&imu_data.val, (void*)&rxbuf[1], sizeof(tSensor_s16));
    spi1_obj.flg_cplt= 0;

    memcpy((char *)&xstar_fcs_U.sensors.MPU6500.acc_x, (char *)&imu_data.val.accel_s16, 6);
    memcpy((char *)&xstar_fcs_U.sensors.MPU6500.gyro_x, (char *)&imu_data.val.gyro_s16, 6);
    memcpy((char *)&xstar_fcs_U.sensors.MPU6500.Temperature_deg, (char *)&imu_data.val.temp_s16, 2);


  }

  /* 读取IMU数据 */
  txbuf[0]= ImuRegAddr_ACCEL_XOUT_H  | REG_R;
  memset(&txbuf[1], 0, sizeof(tSensor_s16));
  memset(&rxbuf[0], 0, sizeof(tSensor_s16)+1);
  msp_spi1_it_tx_rx(txbuf, rxbuf, sizeof(tSensor_s16) + 1);

  HAL_GPIO_WritePin(LED_G_RUN_Port, LED_G_RUN_Pin, GPIO_PIN_SET);
}  






/******************************************************************************
 * 功能：IMU实时任务的运行
 * 输入：无          
 * 返回：无
 * 说明：需在1ms中断中调用，高实时。
 *
 *****************************************************************************/
void imu_realtime_task(void)
{
  
}





/*********************************** END OF FILE *************************************/
