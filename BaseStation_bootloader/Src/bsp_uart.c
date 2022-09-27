/**************************************************************************************
 *
 * �ļ�������UART��ؽӿ�
 * �������ڣ�
 *
 * ��ע��
 *
 **************************************************************************************
 */

/* Includes ------------------------------------------------------------------*/
#include "bsp_uart.h"
#include "Sys_cfg.h"
#include "alink_helpers.h"
#include "update_task.h"
#include "bsp_gpio.h"

/* Private_Defines -----------------------------------------------------------*/



/* Private_TypesDefinitions --------------------------------------------------*/



/* Private_Variables ---------------------------------------------------------*/
serial_obj_t com_obj[3];

DMA_HandleTypeDef hdma_usart1_rx;
DMA_HandleTypeDef hdma_usart1_tx;
DMA_HandleTypeDef hdma_usart3_rx;
DMA_HandleTypeDef hdma_usart3_tx;
DMA_HandleTypeDef hdma_uart8_rx;
DMA_HandleTypeDef hdma_uart8_tx;

/* FIFO���е�buf */
uint8_t uart1_rx_buf[USART1_RX_BUFFER_MAX];
uint8_t uart3_rx_buf[USART3_RX_BUFFER_MAX];
uint8_t uart8_rx_buf[UART8_RX_BUFFER_MAX];

/* ����DMA RX buf */
uint8_t Uart1_pData[USART1_RX_BUFFER_MAX];
uint8_t Uart3_pData[USART3_RX_BUFFER_MAX];
uint8_t Uart8_pData[UART8_RX_BUFFER_MAX];

/* FIFO���е�TX buf */
uint8_t uart1_tx_buf[UART1_TX_FIFO_MAX];
uint8_t uart3_tx_buf[UART3_TX_FIFO_MAX];
uint8_t uart8_tx_buf[UART8_TX_FIFO_MAX];

/* ����DMA TX buf */
uint8_t Uart1_TxDmaBuf[UART1_TX_DMABUF_MAX];
uint8_t Uart3_TxDmaBuf[UART3_TX_DMABUF_MAX];
uint8_t Uart8_TxDmaBuf[UART8_TX_DMABUF_MAX];



const uint8_t alinkmsg_crcs[256] = ALINK_MESSAGE_CRCS;
/* FunctionPrototypes --------------------------------------------------------*/



/* Functions -----------------------------------------------------------------*/

/******************************************************************************
 * ���ܣ�
 * ���룺��          
 * ���أ�
 * ˵����USART1����ͨѶ
 *
 *****************************************************************************/
void MX_USART1_UART_Init(void)
{
  com_obj[COM1].uart.Instance = USART1;
  com_obj[COM1].uart.Init.BaudRate = 115200;
  com_obj[COM1].uart.Init.WordLength = UART_WORDLENGTH_8B;
  com_obj[COM1].uart.Init.StopBits = UART_STOPBITS_1;
  com_obj[COM1].uart.Init.Parity = UART_PARITY_NONE;
  com_obj[COM1].uart.Init.Mode = UART_MODE_TX_RX;
  com_obj[COM1].uart.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  com_obj[COM1].uart.Init.OverSampling = UART_OVERSAMPLING_8;
  if (HAL_UART_Init( &(com_obj[COM1].uart) ) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }
	com_obj[COM1].com = COM1;
	queue_create(&com_obj[COM1].rx_queue, uart1_rx_buf, sizeof(uart1_rx_buf));
  queue_create(&com_obj[COM1].tx_queue, uart1_tx_buf, sizeof(uart1_tx_buf));
  
  HAL_UART_Receive_DMA(&com_obj[COM1].uart,Uart1_pData,USART1_RX_BUFFER_MAX);
	__HAL_UART_ENABLE_IT(&com_obj[COM1].uart,UART_IT_IDLE);
  
  HAL_NVIC_SetPriority(USART1_IRQn, 6, 0);
  HAL_NVIC_EnableIRQ(USART1_IRQn);
  
  HAL_NVIC_SetPriority(USART1_TX_DMA_IRQn, 0, 1);
  HAL_NVIC_EnableIRQ(USART1_TX_DMA_IRQn);
  HAL_NVIC_SetPriority(USART1_RX_DMA_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(USART1_RX_DMA_IRQn);
  
  com_obj[COM1].flg_init= 1;
}


/******************************************************************************
 * ���ܣ�
 * ���룺��          
 * ���أ�
 * ˵����USART3��WIFI AR9342ͨѶ
 *
 *****************************************************************************/
void MX_USART3_UART_Init(void)
{

  com_obj[COM3].uart.Instance = USART3;
  com_obj[COM3].uart.Init.BaudRate = 115200;
  com_obj[COM3].uart.Init.WordLength = UART_WORDLENGTH_8B;
  com_obj[COM3].uart.Init.StopBits = UART_STOPBITS_1;
  com_obj[COM3].uart.Init.Parity = UART_PARITY_NONE;
  com_obj[COM3].uart.Init.Mode = UART_MODE_TX_RX;
  com_obj[COM3].uart.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  com_obj[COM3].uart.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&com_obj[COM3].uart) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }
	com_obj[COM3].com = COM3;
	queue_create(&com_obj[COM3].rx_queue, uart3_rx_buf, sizeof(uart3_rx_buf));
  queue_create(&com_obj[COM3].tx_queue, uart3_tx_buf, sizeof(uart3_tx_buf));
  
  HAL_UART_Receive_DMA(&com_obj[COM3].uart,Uart3_pData,USART3_RX_BUFFER_MAX);
	__HAL_UART_ENABLE_IT(&com_obj[COM3].uart,UART_IT_IDLE);
  
  HAL_NVIC_SetPriority(USART3_IRQn, 6, 0);
  HAL_NVIC_EnableIRQ(USART3_IRQn);
  
  HAL_NVIC_SetPriority(USART3_TX_DMA_IRQn, 0, 1);
  HAL_NVIC_EnableIRQ(USART3_TX_DMA_IRQn);
  HAL_NVIC_SetPriority(USART3_RX_DMA_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(USART3_RX_DMA_IRQn);
  
  com_obj[COM3].flg_init= 1;
}


/******************************************************************************
 * ���ܣ�
 * ���룺��          
 * ���أ�
 * ˵����UART8�����߶�MCUͨѶ
 *
 *****************************************************************************/
void MX_UART8_UART_Init(void)
{

  com_obj[COM8].uart.Instance = UART8;
  com_obj[COM8].uart.Init.BaudRate = 2000000;
  com_obj[COM8].uart.Init.WordLength = UART_WORDLENGTH_8B;
  com_obj[COM8].uart.Init.StopBits = UART_STOPBITS_1;
  com_obj[COM8].uart.Init.Parity = UART_PARITY_NONE;
  com_obj[COM8].uart.Init.Mode = UART_MODE_TX_RX;
  com_obj[COM8].uart.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  com_obj[COM8].uart.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&com_obj[COM8].uart) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }
	com_obj[COM8].com = COM8;
	queue_create(&com_obj[COM8].rx_queue, uart8_rx_buf, sizeof(uart8_rx_buf));
  queue_create(&com_obj[COM8].tx_queue, uart8_tx_buf, sizeof(uart8_tx_buf));
  
  HAL_UART_Receive_DMA(&com_obj[COM8].uart,Uart8_pData,UART8_RX_BUFFER_MAX);
	__HAL_UART_ENABLE_IT(&com_obj[COM8].uart,UART_IT_IDLE);
  
  HAL_NVIC_SetPriority(UART8_IRQn, 6, 0);
  HAL_NVIC_EnableIRQ(UART8_IRQn);
  
  HAL_NVIC_SetPriority(UART8_TX_DMA_IRQn, 0, 1);
  HAL_NVIC_EnableIRQ(UART8_TX_DMA_IRQn);
  HAL_NVIC_SetPriority(UART8_RX_DMA_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(UART8_RX_DMA_IRQn);
  
  com_obj[COM8].flg_init= 1;
}


/******************************************************************************
 * ���ܣ�
 * ���룺��          
 * ���أ�
 * ˵����
 *
 *****************************************************************************/
void MX_USART1_UART_UnInit(void)
{
  com_obj[COM1].flg_init= 0;
  
  HAL_UART_DeInit( &(com_obj[COM1].uart));
  
  HAL_NVIC_DisableIRQ(USART1_IRQn);
  HAL_NVIC_DisableIRQ(USART1_TX_DMA_IRQn);
  HAL_NVIC_DisableIRQ(USART1_RX_DMA_IRQn);
}


/******************************************************************************
 * ���ܣ�
 * ���룺��          
 * ���أ�
 * ˵����
 *
 *****************************************************************************/
void MX_USART3_UART_UnInit(void)
{
  com_obj[COM3].flg_init= 0;
  
  HAL_UART_DeInit( &(com_obj[COM3].uart));
  
  HAL_NVIC_DisableIRQ(USART3_IRQn);
  HAL_NVIC_DisableIRQ(USART3_TX_DMA_IRQn);
  HAL_NVIC_DisableIRQ(USART3_RX_DMA_IRQn);
}


/******************************************************************************
 * ���ܣ�
 * ���룺��          
 * ���أ�
 * ˵����
 *
 *****************************************************************************/
void MX_UART8_UART_UnInit(void)
{
  com_obj[COM8].flg_init= 0;
  
  HAL_UART_DeInit( &(com_obj[COM8].uart));
  
  HAL_NVIC_DisableIRQ(UART8_IRQn);
  HAL_NVIC_DisableIRQ(UART8_TX_DMA_IRQn);
  HAL_NVIC_DisableIRQ(UART8_RX_DMA_IRQn);
}


/******************************************************************************
 * ���ܣ�
 * ���룺��          
 * ���أ�
 * ˵����
 *
 *****************************************************************************/
int serial_send(serial_obj_t *pcom, void *buf, uint16_t len)
{
	uint16_t txlen=0;
  int32_t  queue_len=0;
  
  /* USART1 ---------------------------------------------------------------- */
	if( pcom->com == COM1 && com_obj[COM1].flg_init)
	{
    queue_push_buf(&com_obj[COM1].tx_queue, buf, len);
        
    if (com_obj[COM1].uart.gState == HAL_UART_STATE_READY)
    {
			RS485_TX_ENABLE;
      queue_len= queue_size(&com_obj[COM1].tx_queue);
      queue_len= (queue_len>0)? queue_len : 0;
      txlen= (UART1_TX_DMABUF_MAX < queue_len)? UART1_TX_DMABUF_MAX : queue_len;
      
      queue_pop_buf(&com_obj[COM1].tx_queue, Uart1_TxDmaBuf, txlen);     
      HAL_UART_Transmit_DMA(&com_obj[COM1].uart, Uart1_TxDmaBuf, txlen);
    }	
	}
  
  /* USART3 ---------------------------------------------------------------- */
	else if( pcom->com == COM3 && com_obj[COM3].flg_init)
	{
		queue_push_buf(&com_obj[COM3].tx_queue, buf, len);
        
    if (com_obj[COM3].uart.gState == HAL_UART_STATE_READY)
    {
      queue_len= queue_size(&com_obj[COM3].tx_queue);
      queue_len= (queue_len>0)? queue_len : 0;
      txlen= (UART3_TX_DMABUF_MAX < queue_len)? UART3_TX_DMABUF_MAX : queue_len;
      
      queue_pop_buf(&com_obj[COM3].tx_queue, Uart3_TxDmaBuf, txlen);     
      HAL_UART_Transmit_DMA(&com_obj[COM3].uart, Uart3_TxDmaBuf, txlen);
    }	
	}
  
  /* UART8 ----------------------------------------------------------------- */
	else if( pcom->com == COM8 && com_obj[COM8].flg_init)
	{
    static uint8_t uart8tx_timout= 0;
		queue_push_buf(&com_obj[COM8].tx_queue, buf, len);
        
    if (com_obj[COM8].uart.gState == HAL_UART_STATE_READY)
    {
      uart8tx_timout= 0;
      queue_len= queue_size(&com_obj[COM8].tx_queue);
      queue_len= (queue_len>0)? queue_len : 0;
      txlen= (UART8_TX_DMABUF_MAX < queue_len)? UART8_TX_DMABUF_MAX : queue_len;
      
      queue_pop_buf(&com_obj[COM8].tx_queue, Uart8_TxDmaBuf, txlen);     
      HAL_UART_Transmit_DMA(&com_obj[COM8].uart, Uart8_TxDmaBuf, txlen);
    }else{
      if (++uart8tx_timout > 10)
      {
        com_obj[COM8].uart.gState = HAL_UART_STATE_READY;
      }
    }
	}

	return len;
}







/******************************************************************************
 * ���ܣ�
 * ���룺��          
 * ���أ�
 * ˵����
 *
 *****************************************************************************/
int serial_getchar(serial_obj_t *pcom, uint8_t *ch, uint32_t timeout)
{
	uint8_t temp = 0;
	if((pcom == NULL) || (ch == NULL))
	{
		return -1;
	}
	while( queue_empty(&pcom->rx_queue) && timeout)
	{
			if(timeout-- == 0)
			{
				return -2;
			}
	}
	if( queue_empty(&pcom->rx_queue) == 0 )
	{
		queue_pop(&pcom->rx_queue, (uint8_t *)ch);
		return 1;
	}
	return -1;
}


/******************************************************************************
 * ���ܣ�ϵͳ����ʱ��Ӧ����Ϣ
 * ���룺��          
 * ���أ�
 * ˵����
 *
 *****************************************************************************/
int32_t AlinkPacket_Reply(uint8_t chan, alink_message_head_t *pmsg)
{
  uint16_t len, i;
  uint8_t send_buf[512];

  if(pmsg == NULL)return -1;

  //alink_finalize_message_chan(pmsg, pmsg->destid, pmsg->sourceid, chan, pmsg->len,0);// alink_message_crcs[pmsg->msgid]);   //
  alink_finalize_message_chan(pmsg, pmsg->destid, pmsg->sourceid, chan, pmsg->len, alinkmsg_crcs[pmsg->msgid]);
  len = alink_msg_to_send_buffer(send_buf, pmsg);

  /* �������� */
  //if(PACKET_SEND(send_buf, len) < 0)  
  if(serial_send(&com_obj[msg_channel], send_buf, len) < 0) return -3;

  return 1;
}


/******************************************************************************
 * ���ܣ�ֹͣUART DMA����
 * ���룺��          
 * ���أ�
 * ˵����
 *
 *****************************************************************************/
HAL_StatusTypeDef HAL_UART_DMAStopRx(UART_HandleTypeDef *huart)
{

  if ((HAL_IS_BIT_SET(huart->Instance->CR3, USART_CR3_DMAR)) &&
      (huart->RxState == HAL_UART_STATE_BUSY_RX))
  {
    CLEAR_BIT(huart->Instance->CR3, USART_CR3_DMAR);

    /* Abort the UART DMA Rx channel */
    if (huart->hdmarx != NULL)
    {
      if (HAL_DMA_Abort(huart->hdmarx) != HAL_OK)
      {
        if (HAL_DMA_GetError(huart->hdmarx) == HAL_DMA_ERROR_TIMEOUT)
        {
          /* Set error code to DMA */
          huart->ErrorCode = HAL_UART_ERROR_DMA;

          return HAL_TIMEOUT;
        }
      }
    }

    /* Disable RXNE, PE and ERR (Frame error, noise error, overrun error) interrupts */
    CLEAR_BIT(huart->Instance->CR1, (USART_CR1_RXNEIE_RXFNEIE | USART_CR1_PEIE));
    CLEAR_BIT(huart->Instance->CR3, (USART_CR3_EIE | USART_CR3_RXFTIE));

    /* At end of Rx process, restore huart->RxState to Ready */
    huart->RxState = HAL_UART_STATE_READY;

    /* Reset RxIsr function pointer */
    huart->RxISR = NULL;
  }

  return HAL_OK;
}


/******************************************************************************
 * ���ܣ�ֹͣUART DMA����
 * ���룺��          
 * ���أ�
 * ˵����
 *
 *****************************************************************************/
HAL_StatusTypeDef HAL_UART_DMAStopTx(UART_HandleTypeDef *huart)
{

  /* Stop UART DMA Tx request if ongoing */
  if ((HAL_IS_BIT_SET(huart->Instance->CR3, USART_CR3_DMAT)) &&
      (huart->gState == HAL_UART_STATE_BUSY_TX))
  {
    CLEAR_BIT(huart->Instance->CR3, USART_CR3_DMAT);

    /* Abort the UART DMA Tx channel */
    if (huart->hdmatx != NULL)
    {
      if (HAL_DMA_Abort(huart->hdmatx) != HAL_OK)
      {
        if (HAL_DMA_GetError(huart->hdmatx) == HAL_DMA_ERROR_TIMEOUT)
        {
          /* Set error code to DMA */
          huart->ErrorCode = HAL_UART_ERROR_DMA;

          return HAL_TIMEOUT;
        }
      }
    }

    /* Disable TXEIE, TCIE, TXFT interrupts */
    CLEAR_BIT(huart->Instance->CR1, (USART_CR1_TXEIE_TXFNFIE | USART_CR1_TCIE));
    CLEAR_BIT(huart->Instance->CR3, (USART_CR3_TXFTIE));

    /* At end of Tx process, restore huart->gState to Ready */
    huart->gState = HAL_UART_STATE_READY;
  }

  return HAL_OK;
}


/******************************************************************************
 * ���ܣ�UART�����жϴ�����
 * ���룺��          
 * ���أ�
 * ˵������Ҫ���ΰ봫���ж�__HAL_DMA_ENABLE_IT(hdma, (DMA_IT_TC | DMA_IT_HT | DMA_IT_TE));////��DMA_IT_HTȥ��
 *
 *****************************************************************************/
void UartReceive_IDLE(UART_HandleTypeDef* huart)
{
	int i = 0,j=0;
  
  if(!__HAL_UART_GET_FLAG(huart,UART_FLAG_IDLE) )return;
  __HAL_UART_CLEAR_IDLEFLAG(huart);
  
  /* ����2������̵ܶ��������������� */
  if(__HAL_USART_GET_FLAG(huart, USART_FLAG_BUSY))return;
   
	if(huart->Instance == USART1)
	{
		i = USART1_RX_DMA_STREAM->NDTR;
    if(USART1_RX_BUFFER_MAX-i)
    {
      HAL_UART_DMAStopRx(huart);
      queue_push_buf(&com_obj[COM1].rx_queue,Uart1_pData,USART1_RX_BUFFER_MAX-i);
      memset(Uart1_pData,0,sizeof(Uart1_pData));     
    }else{
      READ_REG(USART1->RDR);
      __HAL_UART_CLEAR_OREFLAG(huart);
    }
    HAL_UART_Receive_DMA(huart,Uart1_pData,USART1_RX_BUFFER_MAX);
    __HAL_UART_DISABLE_IT(huart, UART_IT_ERR);
    __HAL_UART_DISABLE_IT(huart, UART_IT_PE);
	}
  
	if(huart->Instance == USART3)
	{
		i = USART3_RX_DMA_STREAM->NDTR;
    if(USART3_RX_BUFFER_MAX-i)
    {
      HAL_UART_DMAStopRx(huart);
      queue_push_buf(&com_obj[COM3].rx_queue,Uart3_pData,USART3_RX_BUFFER_MAX-i);
      memset(Uart3_pData,0,sizeof(Uart3_pData));
    }else{
      READ_REG(USART3->RDR);
      __HAL_UART_CLEAR_OREFLAG(huart);
    }
    HAL_UART_Receive_DMA(huart,Uart3_pData,USART3_RX_BUFFER_MAX);
    __HAL_UART_DISABLE_IT(huart, UART_IT_ERR);
    __HAL_UART_DISABLE_IT(huart, UART_IT_PE);
	}
	
	if(huart->Instance == UART8)
	{
		i = UART8_RX_DMA_STREAM->NDTR;
    if(UART8_RX_BUFFER_MAX-i)
    {
      HAL_UART_DMAStopRx(huart);		
      queue_push_buf(&com_obj[COM8].rx_queue,Uart8_pData,UART8_RX_BUFFER_MAX-i);
      memset(Uart8_pData,0,sizeof(Uart8_pData));
    }else{
      READ_REG(UART8->RDR);
      __HAL_UART_CLEAR_OREFLAG(huart);
    }
    HAL_UART_Receive_DMA(huart,Uart8_pData,UART8_RX_BUFFER_MAX);
    __HAL_UART_DISABLE_IT(huart, UART_IT_ERR);
    __HAL_UART_DISABLE_IT(huart, UART_IT_PE);
	}
	
	
}


/******************************************************************************
 * ���ܣ�UART DMA��������жϻص�����
 * ���룺��          
 * ���أ�
 * ˵����������
 *
 *****************************************************************************/
void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart)
{
  uint16_t txlen=0;
  int32_t  queue_len=0;
  
  /* USART1 ---------------------------------------------------------------- */
  if(huart->Instance == USART1)
	{
    if (0 < queue_size(&com_obj[COM1].tx_queue))
    {
      queue_len= queue_size(&com_obj[COM1].tx_queue);
      txlen= (UART1_TX_DMABUF_MAX < queue_len)? UART1_TX_DMABUF_MAX : queue_len;
      
      queue_pop_buf(&com_obj[COM1].tx_queue, Uart1_TxDmaBuf, txlen);     
      HAL_UART_Transmit_DMA(&com_obj[COM1].uart, Uart1_TxDmaBuf, txlen);
    }
    else{
      HAL_UART_DMAStopTx(huart);
			RS485_RX_ENABLE;
    }  
  }
  
  /* USART3 ---------------------------------------------------------------- */
  if(huart->Instance == USART3)
	{
    if (0 < queue_size(&com_obj[COM3].tx_queue))
    {
      queue_len= queue_size(&com_obj[COM3].tx_queue);
      txlen= (UART3_TX_DMABUF_MAX < queue_len)? UART3_TX_DMABUF_MAX : queue_len;
      
      queue_pop_buf(&com_obj[COM3].tx_queue, Uart3_TxDmaBuf, txlen);     
      HAL_UART_Transmit_DMA(&com_obj[COM3].uart, Uart3_TxDmaBuf, txlen);
    }
    else{
      HAL_UART_DMAStopTx(huart);
    }
  }
  
  /* UART8 ----------------------------------------------------------------- */
  if(huart->Instance == UART8)
	{
    if (0 < queue_size(&com_obj[COM8].tx_queue))
    {
      queue_len= queue_size(&com_obj[COM8].tx_queue);
      txlen= (UART8_TX_DMABUF_MAX < queue_len)? UART8_TX_DMABUF_MAX : queue_len;
      
      queue_pop_buf(&com_obj[COM8].tx_queue, Uart8_TxDmaBuf, txlen);     
      HAL_UART_Transmit_DMA(&com_obj[COM8].uart, Uart8_TxDmaBuf, txlen);
    }
    else{
      HAL_UART_DMAStopTx(huart);
    }
  }
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
  
}

void HAL_UART_ErrorCallback(UART_HandleTypeDef *huart)
{

}

/*********************************** END OF FILE *************************************/
