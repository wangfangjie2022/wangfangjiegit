/**************************************************************************************
 *
 * �ļ�������I2C�ײ������ӿ�(Ӳ��I2C)
 * �������ڣ�
 *
 * ��ע��
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
 * ���ܣ�I2C�ӿڳ�ʼ��
 * ���룺I2Cx  --I2C2 or I2C4          
 * ���أ�
 * ˵����
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
 * ���ܣ�I2C�ӿڽ����ʼ��
 * ���룺��          
 * ���أ�
 * ˵����
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
 * ���ܣ�I2C�ӿڸ�λ����
 * ���룺��          
 * ���أ�
 * ˵����һ����I2C�����쳣ʱ���и�λ����
 *
 *****************************************************************************/
void msp_i2c_reset(I2C_TypeDef* I2Cx)
{  
  msp_i2c_uninit(I2Cx);
  msp_i2c_init(I2Cx);     
} 


 
 
/******************************************************************************
 * ���ܣ�I2C��ѯ��д�ӿں���
 * ���룺i2cobj    --I2C��д��ر����ļ���
 *       dev_addr  --I2C�豸��ַ
 *       txbuf     --���ͻ�����
 *       rxbuf     --���ջ�����
 *       txlen     --�����͵����ݳ���
 *       rxlen     --�����յ����ݳ���
 *       timout    --�ȴ�ʱ�䣬��λms
 *
 * ���أ�0--�ɹ���-1--ʧ�ܡ�
 * ˵����
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
 * ���ܣ�I2C�ж϶�д�ӿں���
 * ���룺i2cobj    --I2C��д��ر����ļ���
 *       dev_addr  --I2C�豸��ַ
 *       ptxbuf    --���ͻ�����
 *       prxbuf    --���ջ�����
 *       txlen     --�����͵����ݳ���
 *       rxlen     --�����յ����ݳ���
 *
 * ���أ�0--�ɹ���-1--ʧ�ܡ�
 * ˵�����ú����������������̣����ڷ�������ж��м���Ƿ���Ҫ�����������̡�
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
 * ���ܣ���I2C��������ж��м�鲢�����������̡�
 * ���룺i2cobj    --I2C��д��ر����ļ���
 *                 
 * ���أ�0--�ɹ���-1--ʧ�ܡ�
 * ˵��������I2C��������ж��е��á�
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
 * ���ܣ�I2C�շ�����жϴ����߼���
 * ���룺��          
 * ���أ�
 * ˵������Ҫ��I2C�շ�����ж��н��е��ã�����ִ��δ����շ��߼���
 *
 *****************************************************************************/
void msp_i2c_transfer_cplt_it_proc( i2c_obj_t* i2cobj)
{
  /* ������ɵ��շ����д���--------------------- */
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
 * ���ܣ�
 * ���룺��          
 * ���أ�
 * ˵����
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
 * ���ܣ�
 * ���룺��          
 * ���أ�
 * ˵����
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
 * ���ܣ�
 * ���룺��          
 * ���أ�
 * ˵����
 *
 *****************************************************************************/
void HAL_I2C_ErrorCallback(I2C_HandleTypeDef *hi2c)
{
  msp_i2c_reset(hi2c->Instance);
} 
 
 
 
/******************************************************************************
 * ���ܣ�
 * ���룺��          
 * ���أ�
 * ˵����
 *
 *****************************************************************************/




/*********************************** END OF FILE *************************************/
