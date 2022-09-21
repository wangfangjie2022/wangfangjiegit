/**************************************************************************************
 *
 * 文件描述：磁力计相关接口
 * 创建日期：
 *
 * 备注：磁力计芯片实际为ST公司的LIS3MDL
 *
 **************************************************************************************
 */

/* Includes ------------------------------------------------------------------*/
#include "includes.h"



/* Private_Defines -----------------------------------------------------------*/





/* Private_TypesDefinitions --------------------------------------------------*/







/* Private_Variables ---------------------------------------------------------*/
mag_args_t mag_args={
  .flg_init= 0,
};

/* 磁力计寄存器初始化参数 */
mag_reg_set_t mag_init_args[]=
{
  {LIS3MDL_ADDR_CTRL_REG1,  0x7C  },  /* ODR: 80Hz，XY-Mode: UHP */
  {LIS3MDL_ADDR_CTRL_REG2,  0x00  },  /* Scale: ±4 gauss */
  {LIS3MDL_ADDR_CTRL_REG3,  0x01  },  /* Single-conversion mode */
  {LIS3MDL_ADDR_CTRL_REG4,  0x0C  },  /* Z-Mode: UHP */
};

/* 磁力计寄存器读取命令相关参数 */
mag_reg_read_t  mag_read_args[]=
{
  {eMagReadCmd_DEV_ID,  LIS3MDL_ADDR_WAI,     1},
  {eMagReadCmd_OUT_XYZ, LIS3MDL_ADDR_OUT_X_L, 6},
};

/* FunctionPrototypes --------------------------------------------------------*/



/* Functions -----------------------------------------------------------------*/

/******************************************************************************
 * 功能：磁力计芯片初始化
 * 输入：无          
 * 返回：
 * 说明：注意芯片初始化时对寄存器的读写采用了非中断读写方式。
 *
 *****************************************************************************/
void bsp_mag_init(void)
{
  uint8_t i, items, buf[10], cnt=0;
  msp_i2c_init(I2C4);

  /* 读取芯片ID */
  buf[0]= LIS3MDL_ADDR_WAI;
  if(0== msp_i2c_polling_tx_rx( &i2c4_obj, LIS3MDL_DEV_ADDR, buf, buf, 1, 1, 2))
  {
    /* 芯片ID合法则对芯片进行初始化 */
    if(buf[0] == LIS3MDL_ID_A_WHO_AM_I)
    {
      items=  sizeof(mag_init_args)/ sizeof(mag_reg_set_t);
      
      for(i=0; i<items; i++)
      {
        msp_i2c_polling_tx_rx( &i2c4_obj, LIS3MDL_DEV_ADDR, (void*)&mag_init_args[i], buf, 2, 0, 2);
      }
      mag_args.flg_init= 1;
    }   
  } 
}


/******************************************************************************
 * 功能：磁力计非实时任务逻辑
 * 输入：无          
 * 返回：无
 * 说明：在main()函数的主循环中调用。
 *
 *****************************************************************************/
extern unsigned char g_open_flag;
//extern FIL file;
void mag_idle_task(void)
{
  static uint32_t runtim=0;
  static uint8_t i2cbuf[10];
  char buffer[1024] = {0};
  unsigned int bw = 0;
  
  /* 磁力计接口初始化--------------------- */
  if(mag_args.flg_init == 0)
  {
    bsp_mag_init();
    return;
  }
  
  /* 周期性读取3轴磁力计数据，间隔10ms--------------------- */
  if(GET_PASTTICK(runtim) >= 10)
  {
    runtim= GET_CURTICK;
//    xstar_fcs_U.sensors.HMC5x83.Temperature_deg = 20.0;
//    xstar_fcs_U.sensors.HMC5x83.Timestamp_ms = run_time() / 1000000.0;//GET_CURTICK;
    i2cbuf[0]= LIS3MDL_ADDR_OUT_X_L;
    msp_i2c_it_tx_rx( &i2c4_obj, LIS3MDL_DEV_ADDR, i2cbuf, i2cbuf, 1, 8);  
  } 
  /* 读取完成保存数据，并启动下一次转换 */  
  if(i2c4_obj.flg_rx_cplt)
  {
    mag_args.lock= 1;
    memcpy((void*)&mag_args.mag_x, i2cbuf, 8);
//    memcpy((char *)&xstar_fcs_U.sensors.HMC5x83.mag_x, (char *)&mag_args.mag_x, 8);
    mag_args.lock= 0;

//    if (1 == g_open_flag)
//    {
//        //__disable_irq();
//        sprintf(buffer,
//            "MAG\t%d\t%d\t%d\t%.2f\t%.6f\r\n",
//            xstar_fcs_U.sensors.HMC5x83.mag_x,
//            xstar_fcs_U.sensors.HMC5x83.mag_y,
//            xstar_fcs_U.sensors.HMC5x83.mag_z,
//            (float)xstar_fcs_U.sensors.HMC5x83.Temperature_deg,
//            xstar_fcs_U.sensors.HMC5x83.Timestamp_ms);
//        f_write(&file, buffer, strlen(buffer), &bw);
//        //f_sync(&file);
//        //__enable_irq();
//    }

    i2cbuf[0]= LIS3MDL_ADDR_CTRL_REG3;
    i2cbuf[1]= 0x01;
    msp_i2c_it_tx_rx( &i2c4_obj, LIS3MDL_DEV_ADDR, i2cbuf, i2cbuf, 2, 0);
  }
  
  /* 磁力计数据处理 */ 
  
}






/*********************************** END OF FILE *************************************/
