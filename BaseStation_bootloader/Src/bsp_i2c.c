/**************************************************************************************
 *
 * 文件描述：I2C底层驱动接口(GPIO软件模拟)
 * 创建日期：
 *
 * 备注：
 *
 **************************************************************************************
 */

/* Includes ------------------------------------------------------------------*/
#include "bsp_i2c.h"
#include "Sys_cfg.h"


/* Private_Defines -----------------------------------------------------------*/
#define I2C_TIMEOUT                       ((uint32_t)0x1000)
#define I2C_LONG_TIMEOUT                  ((uint32_t)(10 * I2C_TIMEOUT))


/* Private_TypesDefinitions --------------------------------------------------*/



/* Private_Variables ---------------------------------------------------------*/



/* FunctionPrototypes --------------------------------------------------------*/



/* Functions -----------------------------------------------------------------*/

/******************************************************************************
 * 功能：
 * 输入：无          
 * 返回：
 * 说明：
 *
 *****************************************************************************/
/******************************************************************************
 * 功能：
 * 输入：无          
 * 返回：
 * 说明：
 *
 *****************************************************************************/
void delay_nms(uint32_t nms)
{
  uint32_t tim= GET_CURTICK;
  
  while (GET_PASTTICK(tim) < nms );
}




/******************************************************************************
 * 功能：I2C专用延时程序。
 * 输入：无          
 * 返回：
 * 说明：
 *
 *****************************************************************************/
void I2C_Delay(uint32_t cnt)
{
  uint32_t i,j;

  for(i=0; i<cnt; i++)
  {
    for(j=0; j<257; j++){;}
  }
  
  
  
}

/******************************************************************************
 * 功能：I2C SDA设置为输入
 * 输入：无          
 * 返回：
 * 说明：
 *
 *****************************************************************************/
void I2C_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct;
  __HAL_RCC_GPIOF_CLK_ENABLE();
  
  GPIO_InitStruct.Pin = I2C_Pin_SDA | I2C_Pin_SCL;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_OD;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(PWR_I2C_Port, &GPIO_InitStruct);
  
}

/******************************************************************************
 * 功能：I2C SDA设置为输入
 * 输入：无          
 * 返回：
 * 说明：
 *
 *****************************************************************************/
void I2C_SDA_IN(void)
{
  GPIO_InitTypeDef GPIO_InitStruct;
  __HAL_RCC_GPIOF_CLK_ENABLE();
  
  GPIO_InitStruct.Pin = I2C_Pin_SDA;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(PWR_I2C_Port, &GPIO_InitStruct);

}

/******************************************************************************
 * 功能：I2C SDA设置为输出
 * 输入：无          
 * 返回：
 * 说明：
 *
 *****************************************************************************/
void I2C_SDA_OUT(void)
{
  GPIO_InitTypeDef GPIO_InitStruct;
  __HAL_RCC_GPIOF_CLK_ENABLE();
  
  GPIO_InitStruct.Pin = I2C_Pin_SDA;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_OD;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(PWR_I2C_Port, &GPIO_InitStruct);

}

/******************************************************************************
 * 功能：I2C产生起始位。
 * 输入：无          
 * 返回：ENABLE --成功；DISABLE --失败。
 * 说明：
 *
 *****************************************************************************/
int I2C_START(void)
{
  uint32_t cnt=0;
  I2C_SDA_OUT();
  
  SDA_H;
  SCL_H;
  while(!SCL_R)
  {if(cnt++ > 10000)break;}
  
  I2C_Delay(3);
  if(!SDA_R)
  {
    return DISABLE;
  }
  
  SDA_L;
  I2C_Delay(3);// 3us
  if(SDA_R)
  {
    return DISABLE;
  }
  
  SCL_L;
  
  return ENABLE;
}


/******************************************************************************
 * 功能：I2C产生停止位。
 * 输入：无          
 * 返回：
 * 说明：
 *
 *****************************************************************************/
void I2C_STOP(void)
{
  uint32_t cnt=0;
  I2C_SDA_OUT();
  
  SCL_L;
  SDA_L;
  I2C_Delay(1);// 1us
  SCL_H;
  while(!SCL_R)
  {
    if(cnt++ > 10000)
    {
      SDA_H;
      break;
    }
  }
  I2C_Delay(5);// 5us
  SDA_H;
  I2C_Delay(1);// 5us
}


/******************************************************************************
 * 功能：I2C产生应答位。
 * 输入：无          
 * 返回：
 * 说明：
 *
 *****************************************************************************/
void I2C_ACK(void)
{
  SCL_L;
  I2C_SDA_OUT();
  
  SDA_L;
  I2C_Delay(4);// us
  SCL_H;
  I2C_Delay(4);// us
  SCL_L;  
}

/******************************************************************************
 * 功能：I2C产生非应答位。
 * 输入：无          
 * 返回：
 * 说明：
 *
 *****************************************************************************/
void I2C_NACK(void)
{
  SCL_L;
  I2C_SDA_OUT();
  
  SDA_H;
  I2C_Delay(3);// us
  SCL_H;
  I2C_Delay(3);// us
  SCL_L;
  I2C_Delay(3);// us

}

/******************************************************************************
 * 功能：I2C获取应答位。
 * 输入：无          
 * 返回：
 * 说明：
 *
 *****************************************************************************/
uint8_t I2C_GET_ACK(void)
{
  uint8_t time= 0;
  uint32_t timout;
  
  I2C_SDA_IN();
  SDA_H;
  I2C_Delay(2);
  SCL_H;
  timout= 0;
  while(!SCL_R)
  {
    if(timout++ > 60000)
    {
      I2C_SDA_OUT();
      break;
    }
  }
  
  I2C_Delay(1);// us
  while(SDA_R)
  {
    time++;
    if(time > 10)
    {
      SCL_L;
      return DISABLE;
    }
  }
  I2C_Delay(2);// us
  SCL_L;
  return ENABLE; 
}


/******************************************************************************
 * 功能：I2C主机读单字节。
 * 输入：0 --应答； 1--非应答。          
 * 返回：读取到的数据。
 * 说明：
 *
 *****************************************************************************/
uint8_t I2C_R_Byte(uint8_t ack)
{
  uint8_t cnt, dat;
  uint32_t timout;
  I2C_SDA_IN();
  
  for(cnt=0; cnt<8; cnt++)
  {
    SCL_L;
    I2C_Delay(4);// us
    
    SCL_H;
    timout= 0;
    while(!SCL_R)
    {
      if(timout++ > 60000)
      {
        I2C_SDA_OUT();
        break;
      }
    }

    dat <<= 1;
    if(SDA_R)
    {
      dat |= 0x01;
    }
    I2C_Delay(4);// us
  } 
  SCL_L;
  if(ack){
    I2C_NACK();
  }else{
    I2C_ACK();
  }
  
  return dat;  
}

/******************************************************************************
 * 功能：I2C主机写单字节。
 * 输入：无          
 * 返回：
 * 说明：
 *
 *****************************************************************************/
void I2C_W_Byte(uint8_t dat)
{
  uint8_t cnt;
  uint32_t timout;
  I2C_SDA_OUT();
  
  for(cnt=0; cnt<8; cnt++)
  {
    SCL_L;
    if(dat & 0x80){
      SDA_H;
    }else{
      SDA_L;
    }
    dat <<= 1;
    I2C_Delay(4);// us
    SCL_H;
    I2C_Delay(4);// us
    timout= 0;
    while(!SCL_R)
    {if(timout++ > 60000)break;}
    
  }    
  SCL_L;
  SDA_H;
  I2C_Delay(1);// us
}


/******************************************************************************
 * 功能：I2C多字节读取。
 * 输入：无          
 * 返回：
 * 说明：
 *
 *****************************************************************************/
I2cSta_t I2C_R_Nbyte( uint8_t I2C_Addr, uint8_t reg_addr, uint8_t *buf, uint16_t num, uint8_t mode)
{
  I2C_START();
  I2C_W_Byte(I2C_Addr);
  if(!I2C_GET_ACK())
  {
    I2C_STOP();
    return eI2C_ERR;
  }
  
  if (mode == 0)
  {
    /* mode 0 先发送设备地址和寄存器地址，再发送设备地址，再读取数据。*/
    I2C_W_Byte(reg_addr);
    if(!I2C_GET_ACK())
    {
      I2C_STOP();
      return eI2C_ERR;
    }
    I2C_STOP();
    
    I2C_START();
    I2C_W_Byte(I2C_Addr | 0x01);
    if(!I2C_GET_ACK())
    {
      I2C_STOP();
      return eI2C_ERR;
    }
  }
  else
  {
    /* mode 1 仅发送设备地址，然后直接读取数据。 */
    
  }
  
  while(num)
  {
    if(num==1)
    {
      *buf = I2C_R_Byte(NACK);
    }else{
      *buf = I2C_R_Byte(ACK);
    }
    buf++;
    num--;
  }
  I2C_STOP();
  return eI2C_OK;
}


/******************************************************************************
 * 功能：I2C多字节写操作。
 * 输入：无          
 * 返回：
 * 说明：
 *
 *****************************************************************************/
I2cSta_t I2C_W_Nbyte( uint8_t I2C_Addr, uint8_t reg_addr, uint8_t *buf, uint16_t num, uint8_t mode)
{
  I2C_START();
  I2C_W_Byte(I2C_Addr);
  if(!I2C_GET_ACK())
  {
    I2C_STOP();
    return eI2C_ERR;
  }
  
  if (mode == 0)
  {
    /* mode 0 先发送设备地址和寄存器地址，再写数据。*/
    I2C_W_Byte(reg_addr);
    if(!I2C_GET_ACK())
    {
      I2C_STOP();
      return eI2C_ERR;
    }
  }
  else
  {
    /* mode 1 仅发送设备地址，然后直接写数据。 */	
  }
  
  while(num)
  {
    I2C_W_Byte(*buf);
    if(!I2C_GET_ACK() && num >1)
    {
      I2C_STOP();
      return eI2C_ERR;
    }

    buf++;
    num--;
  }
  I2C_STOP();
  return eI2C_OK;
}






/*********************************** END OF FILE *************************************/
