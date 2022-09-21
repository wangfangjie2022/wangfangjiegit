/**************************************************************************************
 *
 * 文件描述：I2C底层驱动接口(硬件I2C)
 * 创建日期：
 *
 * 备注：
 *
 **************************************************************************************
 */

/* Includes ------------------------------------------------------------------*/
#include "includes.h"


/* Private_Defines -----------------------------------------------------------*/
#define I2C2_TIMING                 0x30907878  // 100KHz
#define I2C4_TIMING                 0x30906060  // 124KHz


/* Private_TypesDefinitions --------------------------------------------------*/



/* Private_Variables ---------------------------------------------------------*/
//I2C_HandleTypeDef hi2c4, hi2c2;
i2c_obj_t i2c2_obj={.flg_init=0,.errcnt=0}, i2c4_obj={.flg_init=0,.errcnt=0};






/* FunctionPrototypes --------------------------------------------------------*/



/* Functions -----------------------------------------------------------------*/



 /******************************************************************************
 * 功能：I2C接口初始化
 * 输入：I2Cx  --I2C2 or I2C4          
 * 返回：
 * 说明：
 *
 *****************************************************************************/
void msp_i2c_init(I2C_TypeDef* I2Cx)
{
  if (I2Cx == I2C2)
  {
    __HAL_RCC_I2C2_CLK_ENABLE();

    i2c2_obj.hi2c.Instance             = I2C2;
    i2c2_obj.hi2c.Init.Timing          = I2C2_TIMING;
    i2c2_obj.hi2c.Init.OwnAddress1     = 0xFF;
    i2c2_obj.hi2c.Init.AddressingMode  = I2C_ADDRESSINGMODE_7BIT;
    i2c2_obj.hi2c.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
    i2c2_obj.hi2c.Init.OwnAddress2     = 0xFF;
    i2c2_obj.hi2c.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
    i2c2_obj.hi2c.Init.NoStretchMode   = I2C_NOSTRETCH_DISABLE;    
    HAL_I2C_Init(&i2c2_obj.hi2c);
    
    HAL_I2CEx_ConfigAnalogFilter(&i2c2_obj.hi2c,I2C_ANALOGFILTER_ENABLE);
    HAL_I2CEx_ConfigDigitalFilter(&i2c2_obj.hi2c, 0);
    
    HAL_NVIC_SetPriority(I2C2_ER_IRQn, IRQnPriority_I2C2_ER, 0);
    HAL_NVIC_SetPriority(I2C2_EV_IRQn, IRQnPriority_I2C2_EV, 0);
    
    HAL_NVIC_EnableIRQ(I2C2_ER_IRQn); // error interrupt
    HAL_NVIC_EnableIRQ(I2C2_EV_IRQn); // event interrupt
    
    i2c2_obj.txlen= 0;
    i2c2_obj.rxlen= 0; 
    i2c2_obj.flg_init= 1;
  }
  
  if (I2Cx == I2C4)
  {
    __HAL_RCC_I2C4_CLK_ENABLE();

    i2c4_obj.hi2c.Instance             = I2C4;
    i2c4_obj.hi2c.Init.Timing          = I2C4_TIMING;
    i2c4_obj.hi2c.Init.OwnAddress1     = 0xFF;
    i2c4_obj.hi2c.Init.AddressingMode  = I2C_ADDRESSINGMODE_7BIT;
    i2c4_obj.hi2c.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
    i2c4_obj.hi2c.Init.OwnAddress2     = 0xFF;
    i2c4_obj.hi2c.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
    i2c4_obj.hi2c.Init.NoStretchMode   = I2C_NOSTRETCH_DISABLE;    
    HAL_I2C_Init(&i2c4_obj.hi2c);
    
    HAL_I2CEx_ConfigAnalogFilter(&i2c4_obj.hi2c,I2C_ANALOGFILTER_ENABLE);
    HAL_I2CEx_ConfigDigitalFilter(&i2c4_obj.hi2c, 0);
    
    HAL_NVIC_SetPriority(I2C4_ER_IRQn, IRQnPriority_I2C4_ER, 0);
    HAL_NVIC_SetPriority(I2C4_EV_IRQn, IRQnPriority_I2C4_EV, 0);
    
    HAL_NVIC_EnableIRQ(I2C4_ER_IRQn); // error interrupt
    HAL_NVIC_EnableIRQ(I2C4_EV_IRQn); // event interrupt
    
    i2c4_obj.txlen= 0;
    i2c4_obj.rxlen= 0;
    i2c4_obj.flg_init= 1;
  }
  
} 
 
 
 
/******************************************************************************
 * 功能：I2C接口解除初始化
 * 输入：无          
 * 返回：
 * 说明：
 *
 *****************************************************************************/
void msp_i2c_uninit(I2C_TypeDef* I2Cx)
{  
  if (I2Cx == I2C2)
  {
    __HAL_RCC_I2C2_FORCE_RESET();
    __HAL_RCC_I2C2_RELEASE_RESET();
    
    HAL_I2C_DeInit(&i2c2_obj.hi2c);
    
    HAL_NVIC_DisableIRQ(I2C2_ER_IRQn);
    HAL_NVIC_DisableIRQ(I2C2_EV_IRQn);
    
    i2c2_obj.flg_init= 0;
  } 

  if (I2Cx == I2C4)
  {
    __HAL_RCC_I2C4_FORCE_RESET();
    __HAL_RCC_I2C4_RELEASE_RESET();
    
    HAL_I2C_DeInit(&i2c4_obj.hi2c);
    
    HAL_NVIC_DisableIRQ(I2C4_ER_IRQn);
    HAL_NVIC_DisableIRQ(I2C4_EV_IRQn); 
    
    i2c4_obj.flg_init= 0;
  }    
} 

 
 
/******************************************************************************
 * 功能：I2C接口复位处理
 * 输入：无          
 * 返回：
 * 说明：一般在I2C出现异常时进行复位处理。
 *
 *****************************************************************************/
void msp_i2c_reset(I2C_TypeDef* I2Cx)
{  
  msp_i2c_uninit(I2Cx);
  msp_i2c_init(I2Cx);     
} 


 
 
/******************************************************************************
 * 功能：I2C轮询读写接口函数
 * 输入：i2cobj    --I2C读写相关变量的集合
 *       dev_addr  --I2C设备地址
 *       txbuf     --发送缓冲区
 *       rxbuf     --接收缓冲区
 *       txlen     --待发送的数据长度
 *       rxlen     --待接收的数据长度
 *       timout    --等待时间，单位ms
 *
 * 返回：0--成功；-1--失败。
 * 说明：
 *
 *****************************************************************************/
int msp_i2c_polling_tx_rx( i2c_obj_t* i2cobj, uint8_t dev_addr, \
                            uint8_t* txbuf, uint8_t* rxbuf, \
                            uint16_t txlen, uint16_t rxlen, uint32_t timout)
{
  int ret = -1;
  
  if(i2cobj->lock || txbuf==NULL || rxbuf==NULL || txlen==0 || i2cobj->flg_init==0) return ret;  
  i2cobj->lock= 1;
  
  do{
    if(txlen){
      if(HAL_OK != HAL_I2C_Master_Transmit(&i2cobj->hi2c, (uint16_t)dev_addr, txbuf, txlen, timout)){
        i2cobj->errcnt++;
        break;
      }
    }

    if(rxlen){
      if(HAL_OK != HAL_I2C_Master_Receive(&i2cobj->hi2c, (uint16_t)dev_addr, rxbuf, rxlen, timout))
        break;
    }
    ret = 0;
    
  }while(0);
  
  READ_REG(i2cobj->hi2c.Instance->RXDR);
  
  i2cobj->lock= 0;
  
  if(i2cobj->errcnt >= 10)
  {
    i2cobj->errcnt= 0;
    msp_i2c_reset(i2cobj->hi2c.Instance);    
  }
  
  return ret;
}





/******************************************************************************
 * 功能：I2C中断读写接口函数
 * 输入：i2cobj    --I2C读写相关变量的集合
 *       dev_addr  --I2C设备地址
 *       ptxbuf    --发送缓冲区
 *       prxbuf    --接收缓冲区
 *       txlen     --待发送的数据长度
 *       rxlen     --待接收的数据长度
 *
 * 返回：0--成功；-1--失败。
 * 说明：该函数仅启动发送流程，需在发送完成中断中检测是否需要启动接收流程。
 *
 *****************************************************************************/
int msp_i2c_it_tx_rx( i2c_obj_t* i2cobj, uint8_t dev_addr, \
                        uint8_t* txbuf, uint8_t* rxbuf, \
                        uint16_t txlen, uint16_t rxlen)
{
  int ret = -1;

  if(i2cobj->lock || txbuf==NULL || rxbuf==NULL || txlen==0 || i2cobj->flg_init==0) return ret;
  i2cobj->lock= 1;
  
  do{
    i2cobj->dev_addr= dev_addr;
    i2cobj->rxbuf= rxbuf;
    i2cobj->rxlen= rxlen;
    i2cobj->flg_tx_cplt= 0;
    i2cobj->flg_rx_cplt= 0;
    i2cobj->tx_start_tim= GET_CURTICK;
    
    if (HAL_OK == HAL_I2C_Master_Transmit_IT(&i2cobj->hi2c, (uint16_t)dev_addr, txbuf, txlen)) 
      ret= 0; 
    else
      i2cobj->lock= 0;
    
  }while(0);
  
  return ret;
}





/******************************************************************************
 * 功能：在I2C发送完成中断中检查并启动接收流程。
 * 输入：i2cobj    --I2C读写相关变量的集合
 *                 
 * 返回：0--成功；-1--失败。
 * 说明：需在I2C发送完成中断中调用。
 *
 *****************************************************************************/
int msp_i2c_it_rx_start( i2c_obj_t* i2cobj)
{
  int ret = -1;
  
  if(i2cobj->rxbuf==NULL || i2cobj->rxlen==0) {
    i2cobj->lock= 0;
    return ret;
  }
  
  do{
    i2cobj->flg_rx_cplt= 0;
    i2cobj->rx_start_tim= GET_CURTICK;
    
    if (HAL_OK == HAL_I2C_Master_Receive_IT(&i2cobj->hi2c, (uint16_t)i2cobj->dev_addr, i2cobj->rxbuf, i2cobj->rxlen))
      ret= 0;
    
  }while(0);
   
  return ret;
}


/******************************************************************************
 * 功能：I2C收发完成中断处理逻辑。
 * 输入：无          
 * 返回：
 * 说明：主要在I2C收发完成中断中进行调用，用于执行未完的收发逻辑。
 *
 *****************************************************************************/
void msp_i2c_transfer_cplt_it_proc( i2c_obj_t* i2cobj)
{
  /* 对已完成的收发进行处理--------------------- */
  if(i2cobj->flg_tx_cplt)
  {
    i2cobj->flg_tx_cplt= 0;
    if (0!=msp_i2c_it_rx_start(i2cobj))
      i2cobj->lock= 0;   
  }
  
  if(i2cobj->flg_rx_cplt)
  {
    i2cobj->lock= 0;
    i2cobj->rxlen= 0;
  }
}
 
 
 
 
 
/******************************************************************************
 * 功能：
 * 输入：无          
 * 返回：
 * 说明：
 *
 *****************************************************************************/
void HAL_I2C_MasterTxCpltCallback(I2C_HandleTypeDef *hi2c)
{
  if(hi2c->Instance == I2C2)
  {
    i2c2_obj.flg_tx_cplt= 1;
    msp_i2c_transfer_cplt_it_proc(&i2c2_obj);
  }
  else if(hi2c->Instance == I2C4)
  {
    i2c4_obj.flg_tx_cplt= 1;
    msp_i2c_transfer_cplt_it_proc(&i2c4_obj);
  }
}


/******************************************************************************
 * 功能：
 * 输入：无          
 * 返回：
 * 说明：
 *
 *****************************************************************************/
void HAL_I2C_MasterRxCpltCallback(I2C_HandleTypeDef *hi2c)
{
  if(hi2c->Instance == I2C2)
  {
    i2c2_obj.flg_rx_cplt= 1;
    msp_i2c_transfer_cplt_it_proc(&i2c2_obj);
  }
  else if(hi2c->Instance == I2C4)
  {
    i2c4_obj.flg_rx_cplt= 1;
    msp_i2c_transfer_cplt_it_proc(&i2c4_obj);
  }
}


/******************************************************************************
 * 功能：
 * 输入：无          
 * 返回：
 * 说明：
 *
 *****************************************************************************/
void HAL_I2C_ErrorCallback(I2C_HandleTypeDef *hi2c)
{
  msp_i2c_reset(hi2c->Instance);
} 
 
 
 
/******************************************************************************
 * 功能：
 * 输入：无          
 * 返回：
 * 说明：
 *
 *****************************************************************************/




/*********************************** END OF FILE *************************************/
