/**************************************************************************************
 *
 * �ļ���������������ؽӿ�
 * �������ڣ�
 *
 * ��ע��������оƬʵ��ΪST��˾��LIS3MDL
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

/* �����ƼĴ�����ʼ������ */
mag_reg_set_t mag_init_args[]=
{
  {LIS3MDL_ADDR_CTRL_REG1,  0x7C  },  /* ODR: 80Hz��XY-Mode: UHP */
  {LIS3MDL_ADDR_CTRL_REG2,  0x00  },  /* Scale: ��4 gauss */
  {LIS3MDL_ADDR_CTRL_REG3,  0x01  },  /* Single-conversion mode */
  {LIS3MDL_ADDR_CTRL_REG4,  0x0C  },  /* Z-Mode: UHP */
};

/* �����ƼĴ�����ȡ������ز��� */
mag_reg_read_t  mag_read_args[]=
{
  {eMagReadCmd_DEV_ID,  LIS3MDL_ADDR_WAI,     1},
  {eMagReadCmd_OUT_XYZ, LIS3MDL_ADDR_OUT_X_L, 6},
};

/* FunctionPrototypes --------------------------------------------------------*/



/* Functions -----------------------------------------------------------------*/

/******************************************************************************
 * ���ܣ�������оƬ��ʼ��
 * ���룺��          
 * ���أ�
 * ˵����ע��оƬ��ʼ��ʱ�ԼĴ����Ķ�д�����˷��ж϶�д��ʽ��
 *
 *****************************************************************************/
void bsp_mag_init(void)
{
  uint8_t i, items, buf[10], cnt=0;
  msp_i2c_init(I2C4);

  /* ��ȡоƬID */
  buf[0]= LIS3MDL_ADDR_WAI;
  if(0== msp_i2c_polling_tx_rx( &i2c4_obj, LIS3MDL_DEV_ADDR, buf, buf, 1, 1, 2))
  {
    /* оƬID�Ϸ����оƬ���г�ʼ�� */
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
 * ���ܣ������Ʒ�ʵʱ�����߼�
 * ���룺��          
 * ���أ���
 * ˵������main()��������ѭ���е��á�
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
  
  /* �����ƽӿڳ�ʼ��--------------------- */
  if(mag_args.flg_init == 0)
  {
    bsp_mag_init();
    return;
  }
  
  /* �����Զ�ȡ3����������ݣ����10ms--------------------- */
  if(GET_PASTTICK(runtim) >= 10)
  {
    runtim= GET_CURTICK;
//    xstar_fcs_U.sensors.HMC5x83.Temperature_deg = 20.0;
//    xstar_fcs_U.sensors.HMC5x83.Timestamp_ms = run_time() / 1000000.0;//GET_CURTICK;
    i2cbuf[0]= LIS3MDL_ADDR_OUT_X_L;
    msp_i2c_it_tx_rx( &i2c4_obj, LIS3MDL_DEV_ADDR, i2cbuf, i2cbuf, 1, 8);  
  } 
  /* ��ȡ��ɱ������ݣ���������һ��ת�� */  
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
  
  /* ���������ݴ��� */ 
  
}






/*********************************** END OF FILE *************************************/
