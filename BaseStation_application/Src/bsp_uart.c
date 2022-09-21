/**************************************************************************************
 *
 * 文件描述：UART相关接口
 * 创建日期：
 *
 * 备注：
 *
 **************************************************************************************
 */

/* Includes ------------------------------------------------------------------*/
#include "includes.h"

/* Private_Defines -----------------------------------------------------------*/



/* Private_TypesDefinitions --------------------------------------------------*/



/* Private_Variables ---------------------------------------------------------*/
serial_obj_t com_obj[COM_N];
DMA_HandleTypeDef hdma_usart1_rx;
DMA_HandleTypeDef hdma_usart1_tx;
DMA_HandleTypeDef hdma_usart2_rx;
DMA_HandleTypeDef hdma_usart2_tx;
DMA_HandleTypeDef hdma_usart3_rx;
DMA_HandleTypeDef hdma_usart3_tx;
DMA_HandleTypeDef hdma_uart4_rx;
DMA_HandleTypeDef hdma_uart4_tx;
DMA_HandleTypeDef hdma_usart6_rx;
DMA_HandleTypeDef hdma_usart6_tx;
DMA_HandleTypeDef hdma_uart7_rx;
DMA_HandleTypeDef hdma_uart7_tx;
DMA_HandleTypeDef hdma_uart8_rx;
DMA_HandleTypeDef hdma_uart8_tx;

/* FIFO队列的RX buf */
uint8_t uart1_rx_buf[UART1_RX_BUFFER_MAX];
uint8_t uart2_rx_buf[UART2_RX_BUFFER_MAX];
uint8_t uart3_rx_buf[UART3_RX_BUFFER_MAX];
uint8_t uart4_rx_buf[UART4_RX_BUFFER_MAX];
uint8_t uart6_rx_buf[UART6_RX_BUFFER_MAX];
uint8_t uart7_rx_buf[UART7_RX_BUFFER_MAX];
uint8_t uart8_rx_buf[UART8_RX_BUFFER_MAX];

/* FIFO队列的TX buf */
uint8_t uart1_tx_buf[UART1_TX_FIFO_MAX];
uint8_t uart2_tx_buf[UART2_TX_FIFO_MAX];
uint8_t uart3_tx_buf[UART3_TX_FIFO_MAX];
uint8_t uart4_tx_buf[UART4_TX_FIFO_MAX];
uint8_t uart6_tx_buf[UART6_TX_FIFO_MAX];
uint8_t uart7_tx_buf[UART7_TX_FIFO_MAX];
uint8_t uart8_tx_buf[UART8_TX_FIFO_MAX];

/* 用于DMA RX buf */
uint8_t Uart1_pData[UART1_RX_BUFFER_MAX];
uint8_t Uart2_pData[UART2_RX_BUFFER_MAX];
uint8_t Uart3_pData[UART3_RX_BUFFER_MAX];
uint8_t Uart4_pData[UART4_RX_BUFFER_MAX];
uint8_t Uart6_pData[UART6_RX_BUFFER_MAX];
uint8_t Uart7_pData[UART7_RX_BUFFER_MAX];
uint8_t Uart8_pData[UART8_RX_BUFFER_MAX];

/* 用于DMA TX buf */
uint8_t Uart1_TxDmaBuf[UART1_TX_DMABUF_MAX];
uint8_t Uart2_TxDmaBuf[UART2_TX_DMABUF_MAX];
uint8_t Uart3_TxDmaBuf[UART3_TX_DMABUF_MAX];
uint8_t Uart4_TxDmaBuf[UART4_TX_DMABUF_MAX];
uint8_t Uart6_TxDmaBuf[UART6_TX_DMABUF_MAX];
uint8_t Uart7_TxDmaBuf[UART7_TX_DMABUF_MAX];
uint8_t Uart8_TxDmaBuf[UART8_TX_DMABUF_MAX];



const uint8_t alinkmsg_crcs[256] = ALINK_MESSAGE_CRCS;

char dbg_str[DBG_STR_LEN];

/* FunctionPrototypes --------------------------------------------------------*/



/* Functions -----------------------------------------------------------------*/



/******************************************************************************
 * 功能：
 * 输入：无          
 * 返回：
 * 说明：USART1与电池RS485通讯
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
  com_obj[COM1].uart.FifoMode = UART_FIFOMODE_ENABLE;
  if (HAL_UART_Init( &(com_obj[COM1].uart) ) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }
	com_obj[COM1].com = COM1;
	queue_create(&com_obj[COM1].rx_queue, uart1_rx_buf, sizeof(uart1_rx_buf));
  queue_create(&com_obj[COM1].tx_queue, uart1_tx_buf, sizeof(uart1_tx_buf));
  
  HAL_UART_Receive_DMA(&com_obj[COM1].uart,Uart1_pData,UART1_RX_BUFFER_MAX);
	__HAL_UART_ENABLE_IT(&com_obj[COM1].uart,UART_IT_IDLE);
  
  HAL_NVIC_SetPriority(USART1_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(USART1_IRQn);
  
  HAL_NVIC_SetPriority(USART1_TX_DMA_IRQn, 0, 1);
  HAL_NVIC_EnableIRQ(USART1_TX_DMA_IRQn);
  HAL_NVIC_SetPriority(USART1_RX_DMA_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(USART1_RX_DMA_IRQn);
  
  com_obj[COM1].flg_init= 1;
}


/******************************************************************************
 * 功能：
 * 输入：无          
 * 返回：
 * 说明：USART2与RTK COM1通讯
 *
 *****************************************************************************/
void MX_USART2_UART_Init(void)
{
  com_obj[COM2].uart.Instance = USART2;
  com_obj[COM2].uart.Init.BaudRate = 115200;
  com_obj[COM2].uart.Init.WordLength = UART_WORDLENGTH_8B;
  com_obj[COM2].uart.Init.StopBits = UART_STOPBITS_1;
  com_obj[COM2].uart.Init.Parity = UART_PARITY_NONE;
  com_obj[COM2].uart.Init.Mode = UART_MODE_TX_RX;
  com_obj[COM2].uart.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  com_obj[COM2].uart.Init.OverSampling = UART_OVERSAMPLING_8;
  com_obj[COM2].uart.FifoMode = UART_FIFOMODE_ENABLE;
  if (HAL_UART_Init( &(com_obj[COM2].uart) ) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }
	com_obj[COM2].com = COM2;
	queue_create(&com_obj[COM2].rx_queue, uart2_rx_buf, sizeof(uart2_rx_buf));
  queue_create(&com_obj[COM2].tx_queue, uart2_tx_buf, sizeof(uart2_tx_buf));
  
  HAL_UART_Receive_DMA(&com_obj[COM2].uart,Uart2_pData,UART2_RX_BUFFER_MAX);
	__HAL_UART_ENABLE_IT(&com_obj[COM2].uart,UART_IT_IDLE);
  
  HAL_NVIC_SetPriority(USART2_IRQn, 6, 0);
  HAL_NVIC_EnableIRQ(USART2_IRQn);
  
  HAL_NVIC_SetPriority(USART2_TX_DMA_IRQn, 1, 1);
  HAL_NVIC_EnableIRQ(USART2_TX_DMA_IRQn);
  HAL_NVIC_SetPriority(USART2_RX_DMA_IRQn, 1, 0);
  HAL_NVIC_EnableIRQ(USART2_RX_DMA_IRQn);
  
  com_obj[COM2].flg_init= 1;
}



/******************************************************************************
 * 功能：
 * 输入：无          
 * 返回：
 * 说明：USART3与WIFI AR9342通讯
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
  com_obj[COM3].uart.FifoMode = UART_FIFOMODE_ENABLE;
  if (HAL_UART_Init(&com_obj[COM3].uart) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }
	com_obj[COM3].com = COM3;
	queue_create(&com_obj[COM3].rx_queue, uart3_rx_buf, sizeof(uart3_rx_buf));
  queue_create(&com_obj[COM3].tx_queue, uart3_tx_buf, sizeof(uart3_tx_buf));
  
  HAL_UART_Receive_DMA(&com_obj[COM3].uart,Uart3_pData,UART3_RX_BUFFER_MAX);
	__HAL_UART_ENABLE_IT(&com_obj[COM3].uart,UART_IT_IDLE);
  
  HAL_NVIC_SetPriority(USART3_IRQn, 6, 0);
  HAL_NVIC_EnableIRQ(USART3_IRQn);
  
  HAL_NVIC_SetPriority(USART3_TX_DMA_IRQn, 1, 1);
  HAL_NVIC_EnableIRQ(USART3_TX_DMA_IRQn);
  HAL_NVIC_SetPriority(USART3_RX_DMA_IRQn, 1, 0);
  HAL_NVIC_EnableIRQ(USART3_RX_DMA_IRQn);
  
  com_obj[COM3].flg_init= 1;
}


/******************************************************************************
 * 功能：
 * 输入：无          
 * 返回：
 * 说明：UART4备用
 *
 *****************************************************************************/
void MX_UART4_UART_Init(void)
{

  com_obj[COM4].uart.Instance = UART4;
  com_obj[COM4].uart.Init.BaudRate = 115200;
  com_obj[COM4].uart.Init.WordLength = UART_WORDLENGTH_8B;
  com_obj[COM4].uart.Init.StopBits = UART_STOPBITS_1;
  com_obj[COM4].uart.Init.Parity = UART_PARITY_NONE;
  com_obj[COM4].uart.Init.Mode = UART_MODE_TX;
  com_obj[COM4].uart.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  com_obj[COM4].uart.Init.OverSampling = UART_OVERSAMPLING_16;
  com_obj[COM4].uart.FifoMode = UART_FIFOMODE_ENABLE;
  if (HAL_UART_Init(&com_obj[COM4].uart) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }
	com_obj[COM4].com = COM4;
	queue_create(&com_obj[COM4].rx_queue, uart4_rx_buf, sizeof(uart4_rx_buf));
  queue_create(&com_obj[COM4].tx_queue, uart4_tx_buf, sizeof(uart4_tx_buf));
  
  HAL_UART_Receive_DMA(&com_obj[COM4].uart,Uart4_pData,UART4_RX_BUFFER_MAX);
	__HAL_UART_ENABLE_IT(&com_obj[COM4].uart,UART_IT_IDLE);
  
  HAL_NVIC_SetPriority(UART4_IRQn, 6, 0);
  HAL_NVIC_EnableIRQ(UART4_IRQn);
  
  HAL_NVIC_SetPriority(UART4_TX_DMA_IRQn, 1, 1);
  HAL_NVIC_EnableIRQ(UART4_TX_DMA_IRQn);
  HAL_NVIC_SetPriority(UART4_RX_DMA_IRQn, 1, 0);
  HAL_NVIC_EnableIRQ(UART4_RX_DMA_IRQn);
  
  com_obj[COM4].flg_init= 1;
}


/******************************************************************************
 * 功能：
 * 输入：无          
 * 返回：
 * 说明：USART6用作调试串口
 *
 *****************************************************************************/
void MX_USART6_UART_Init(void)
{

  com_obj[COM6].uart.Instance = USART6;
  com_obj[COM6].uart.Init.BaudRate = 460800;
  com_obj[COM6].uart.Init.WordLength = UART_WORDLENGTH_8B;
  com_obj[COM6].uart.Init.StopBits = UART_STOPBITS_1;
  com_obj[COM6].uart.Init.Parity = UART_PARITY_NONE;
  com_obj[COM6].uart.Init.Mode = UART_MODE_TX_RX;
  com_obj[COM6].uart.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  com_obj[COM6].uart.Init.OverSampling = UART_OVERSAMPLING_16;
  com_obj[COM6].uart.FifoMode = UART_FIFOMODE_ENABLE;
  if (HAL_UART_Init(&com_obj[COM6].uart) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }
	com_obj[COM6].com = COM6;
	queue_create(&com_obj[COM6].rx_queue, uart6_rx_buf, sizeof(uart6_rx_buf));
  queue_create(&com_obj[COM6].tx_queue, uart6_tx_buf, sizeof(uart6_tx_buf));
  
  HAL_UART_Receive_DMA(&com_obj[COM6].uart,Uart6_pData,UART6_RX_BUFFER_MAX);
	__HAL_UART_ENABLE_IT(&com_obj[COM6].uart,UART_IT_IDLE);
  
  HAL_NVIC_SetPriority(USART6_IRQn, 6, 0);
  HAL_NVIC_EnableIRQ(USART6_IRQn);
  
  HAL_NVIC_SetPriority(USART6_TX_DMA_IRQn, 1, 1);
  HAL_NVIC_EnableIRQ(USART6_TX_DMA_IRQn);
  HAL_NVIC_SetPriority(USART6_RX_DMA_IRQn, 1, 0);
  HAL_NVIC_EnableIRQ(USART6_RX_DMA_IRQn);
  
  com_obj[COM6].flg_init= 1;
  
}


/******************************************************************************
 * 功能：
 * 输入：无          
 * 返回：
 * 说明：UART7备用
 *
 *****************************************************************************/
void MX_UART7_UART_Init(void)
{

  com_obj[COM7].uart.Instance = UART7;
  com_obj[COM7].uart.Init.BaudRate = 115200;
  com_obj[COM7].uart.Init.WordLength = UART_WORDLENGTH_8B;
  com_obj[COM7].uart.Init.StopBits = UART_STOPBITS_1;
  com_obj[COM7].uart.Init.Parity = UART_PARITY_NONE;
  com_obj[COM7].uart.Init.Mode = UART_MODE_TX_RX;
  com_obj[COM7].uart.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  com_obj[COM7].uart.Init.OverSampling = UART_OVERSAMPLING_16;
  com_obj[COM7].uart.FifoMode = UART_FIFOMODE_ENABLE;
  if (HAL_UART_Init(&com_obj[COM7].uart) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }
	com_obj[COM7].com = COM7;
	queue_create(&com_obj[COM7].rx_queue, uart7_rx_buf, sizeof(uart7_rx_buf));
  queue_create(&com_obj[COM7].tx_queue, uart7_tx_buf, sizeof(uart7_tx_buf));
  
  HAL_UART_Receive_DMA(&com_obj[COM7].uart,Uart7_pData,UART7_RX_BUFFER_MAX);
	__HAL_UART_ENABLE_IT(&com_obj[COM7].uart,UART_IT_IDLE);
  
  HAL_NVIC_SetPriority(UART7_IRQn, 6, 0);
  HAL_NVIC_EnableIRQ(UART7_IRQn);
  
  HAL_NVIC_SetPriority(UART7_TX_DMA_IRQn, 1, 1);
  HAL_NVIC_EnableIRQ(UART7_TX_DMA_IRQn);
  HAL_NVIC_SetPriority(UART7_RX_DMA_IRQn, 1, 0);
  HAL_NVIC_EnableIRQ(UART7_RX_DMA_IRQn);
  
  com_obj[COM7].flg_init= 1;
}


/******************************************************************************
 * 功能：
 * 输入：无          
 * 返回：
 * 说明：UART8与天线端MCU通讯
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
  com_obj[COM8].uart.FifoMode = UART_FIFOMODE_ENABLE;
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
  
  HAL_NVIC_SetPriority(UART8_TX_DMA_IRQn, 1, 1);
  HAL_NVIC_EnableIRQ(UART8_TX_DMA_IRQn);
  HAL_NVIC_SetPriority(UART8_RX_DMA_IRQn, 1, 0);
  HAL_NVIC_EnableIRQ(UART8_RX_DMA_IRQn);
  
  com_obj[COM8].flg_init= 1;
}


/******************************************************************************
 * 功能：UARTx波特率设置
 * 输入：无          
 * 返回：
 * 说明：
 *
 *****************************************************************************/
void UARTx_BaudRate_Config(serial_com_e COMx, uint32_t bps)
{
	if(COMx == COM2)
	{
		com_obj[COM2].uart.Instance = USART2;
		com_obj[COM2].uart.Init.BaudRate = bps;
		com_obj[COM2].uart.Init.WordLength = UART_WORDLENGTH_8B;
		com_obj[COM2].uart.Init.StopBits = UART_STOPBITS_1;
		com_obj[COM2].uart.Init.Parity = UART_PARITY_NONE;
		com_obj[COM2].uart.Init.Mode = UART_MODE_TX_RX;
		com_obj[COM2].uart.Init.HwFlowCtl = UART_HWCONTROL_NONE;
		com_obj[COM2].uart.Init.OverSampling = UART_OVERSAMPLING_8;
		com_obj[COM2].uart.FifoMode = UART_FIFOMODE_ENABLE;
		if (HAL_UART_Init( &(com_obj[COM2].uart) ) != HAL_OK)
		{
			_Error_Handler(__FILE__, __LINE__);
		}
	}
}



/******************************************************************************
 * 功能：
 * 输入：无          
 * 返回：
 * 说明：
 *
 *****************************************************************************/
void MX_USART1_UART_UnInit(void)
{
  com_obj[COM1].flg_init= 0;
  
  HAL_UART_DeInit( &(com_obj[COM1].uart));
  
  HAL_NVIC_DisableIRQ(USART1_TX_DMA_IRQn);
  HAL_NVIC_DisableIRQ(USART1_RX_DMA_IRQn);
  HAL_NVIC_DisableIRQ(USART1_IRQn);
}


/******************************************************************************
 * 功能：
 * 输入：无          
 * 返回：
 * 说明：
 *
 *****************************************************************************/
void MX_USART2_UART_UnInit(void)
{
  com_obj[COM2].flg_init= 0;
  
  HAL_UART_DeInit( &(com_obj[COM2].uart));
  
  HAL_NVIC_DisableIRQ(USART2_TX_DMA_IRQn);
  HAL_NVIC_DisableIRQ(USART2_RX_DMA_IRQn);
  HAL_NVIC_DisableIRQ(USART2_IRQn);
}


/******************************************************************************
 * 功能：
 * 输入：无          
 * 返回：
 * 说明：
 *
 *****************************************************************************/
void MX_USART3_UART_UnInit(void)
{
  com_obj[COM3].flg_init= 0;
  
  HAL_UART_DeInit( &(com_obj[COM3].uart));
  
  HAL_NVIC_DisableIRQ(USART3_TX_DMA_IRQn);
  HAL_NVIC_DisableIRQ(USART3_RX_DMA_IRQn);
  HAL_NVIC_DisableIRQ(USART3_IRQn);
}


/******************************************************************************
 * 功能：
 * 输入：无          
 * 返回：
 * 说明：
 *
 *****************************************************************************/
void MX_UART4_UART_UnInit(void)
{
  com_obj[COM4].flg_init= 0;
  
  HAL_UART_DeInit( &(com_obj[COM4].uart));
  
  HAL_NVIC_DisableIRQ(UART4_TX_DMA_IRQn);
  HAL_NVIC_DisableIRQ(UART4_RX_DMA_IRQn);
  HAL_NVIC_DisableIRQ(UART4_IRQn);  
}


/******************************************************************************
 * 功能：
 * 输入：无          
 * 返回：
 * 说明：
 *
 *****************************************************************************/
void MX_USART6_UART_UnInit(void)
{
  com_obj[COM6].flg_init= 0;
  
  HAL_UART_DeInit( &(com_obj[COM6].uart));
  
  HAL_NVIC_DisableIRQ(USART6_TX_DMA_IRQn);
  HAL_NVIC_DisableIRQ(USART6_RX_DMA_IRQn);
  HAL_NVIC_DisableIRQ(USART6_IRQn);
}


/******************************************************************************
 * 功能：
 * 输入：无          
 * 返回：
 * 说明：
 *
 *****************************************************************************/
void MX_UART7_UART_UnInit(void)
{
  com_obj[COM7].flg_init= 0;
  
  HAL_UART_DeInit( &(com_obj[COM7].uart));
  
  HAL_NVIC_DisableIRQ(UART7_TX_DMA_IRQn);
  HAL_NVIC_DisableIRQ(UART7_RX_DMA_IRQn);
  HAL_NVIC_DisableIRQ(UART7_IRQn);
}


/******************************************************************************
 * 功能：
 * 输入：无          
 * 返回：
 * 说明：
 *
 *****************************************************************************/
void MX_UART8_UART_UnInit(void)
{
  com_obj[COM8].flg_init= 0;
  
  HAL_UART_DeInit( &(com_obj[COM8].uart));
  
  HAL_NVIC_DisableIRQ(UART8_TX_DMA_IRQn);
  HAL_NVIC_DisableIRQ(UART8_RX_DMA_IRQn);
  HAL_NVIC_DisableIRQ(UART8_IRQn);
}


/******************************************************************************
 * 功能：
 * 输入：无          
 * 返回：
 * 说明：
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
  
  /* USART2 ---------------------------------------------------------------- */
  else if( pcom->com == COM2 && com_obj[COM2].flg_init)
	{    
    queue_push_buf(&com_obj[COM2].tx_queue, buf, len);
        
    if (com_obj[COM2].uart.gState == HAL_UART_STATE_READY)
    {
      queue_len= queue_size(&com_obj[COM2].tx_queue);
      queue_len= (queue_len>0)? queue_len : 0;
      txlen= (UART2_TX_DMABUF_MAX < queue_len)? UART2_TX_DMABUF_MAX : queue_len;
      
      queue_pop_buf(&com_obj[COM2].tx_queue, Uart2_TxDmaBuf, txlen);     
      HAL_UART_Transmit_DMA(&com_obj[COM2].uart, Uart2_TxDmaBuf, txlen);
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
  
  /* UART4 ----------------------------------------------------------------- */
  else if( pcom->com == COM4 && com_obj[COM4].flg_init)
	{
    static uint8_t uart4tx_timout= 0;
		queue_push_buf(&com_obj[COM4].tx_queue, buf, len);
        
    if (com_obj[COM4].uart.gState == HAL_UART_STATE_READY)
    {
      uart4tx_timout= 0;
      queue_len= queue_size(&com_obj[COM4].tx_queue);
      queue_len= (queue_len>0)? queue_len : 0;
      txlen= (UART4_TX_DMABUF_MAX < queue_len)? UART4_TX_DMABUF_MAX : queue_len;
      
      queue_pop_buf(&com_obj[COM4].tx_queue, Uart4_TxDmaBuf, txlen);     
      HAL_UART_Transmit_DMA(&com_obj[COM4].uart, Uart4_TxDmaBuf, txlen);
    }else{
      if (++uart4tx_timout > 10)
      {
        com_obj[COM4].uart.gState = HAL_UART_STATE_READY;
      }
    }      
	}
  
  /* USART6 ---------------------------------------------------------------- */
  else if( pcom->com == COM6 && com_obj[COM6].flg_init)
	{
		queue_push_buf(&com_obj[COM6].tx_queue, buf, len);
        
    if (com_obj[COM6].uart.gState == HAL_UART_STATE_READY)
    {
      queue_len= queue_size(&com_obj[COM6].tx_queue);
      queue_len= (queue_len>0)? queue_len : 0;
      txlen= (UART6_TX_DMABUF_MAX < queue_len)? UART6_TX_DMABUF_MAX : queue_len;
      
      queue_pop_buf(&com_obj[COM6].tx_queue, Uart6_TxDmaBuf, txlen);     
      HAL_UART_Transmit_DMA(&com_obj[COM6].uart, Uart6_TxDmaBuf, txlen);
    }
	}
  
  /* UART7 ----------------------------------------------------------------- */
	else if( pcom->com == COM7 && com_obj[COM7].flg_init)
	{
    static uint8_t uart7tx_timout= 0;
		queue_push_buf(&com_obj[COM7].tx_queue, buf, len);
        
    if (com_obj[COM7].uart.gState == HAL_UART_STATE_READY)
    {
      uart7tx_timout= 0;
      queue_len= queue_size(&com_obj[COM7].tx_queue);
      queue_len= (queue_len>0)? queue_len : 0;
      txlen= (UART7_TX_DMABUF_MAX < queue_len)? UART7_TX_DMABUF_MAX : queue_len;
      
      queue_pop_buf(&com_obj[COM7].tx_queue, Uart7_TxDmaBuf, txlen);     
      HAL_UART_Transmit_DMA(&com_obj[COM7].uart, Uart7_TxDmaBuf, txlen);
    }else{
      if (++uart7tx_timout > 10)
      {
        com_obj[COM7].uart.gState = HAL_UART_STATE_READY;
      }
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
 * 功能：
 * 输入：无          
 * 返回：
 * 说明：
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
 * 功能：系统升级时的应答消息
 * 输入：无          
 * 返回：
 * 说明：
 *
 *****************************************************************************/
int32_t AlinkPacket_Reply(uint8_t chan, alink_message_head_t *pmsg)
{
  uint16_t len, i;
  uint8_t send_buf[512];

  if(pmsg == NULL){
    return -1;
  }

  //alink_finalize_message_chan(pmsg, pmsg->destid, pmsg->sourceid, chan, pmsg->len,0);// alink_message_crcs[pmsg->msgid]);   //
  alink_finalize_message_chan(pmsg, pmsg->destid, pmsg->sourceid, chan, pmsg->len, alinkmsg_crcs[pmsg->msgid]);

  len = alink_msg_to_send_buffer(send_buf, pmsg);

  /* 发送数据 */
  //if(PACKET_SEND(send_buf, len) < 0)
  if(serial_send(&com_obj[msg_channel], send_buf, len) < 0)
  {
    return -3;
  }

  return 1;
}


/******************************************************************************
 * 功能：停止UART DMA接收
 * 输入：无          
 * 返回：
 * 说明：
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
 * 功能：停止UART DMA发送
 * 输入：无          
 * 返回：
 * 说明：
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
 * 功能：UART空闲中断处理函数
 * 输入：无          
 * 返回：
 * 说明：需要屏蔽半传输中断__HAL_DMA_ENABLE_IT(hdma, (DMA_IT_TC | DMA_IT_HT | DMA_IT_TE));////将DMA_IT_HT去掉
 *
 *****************************************************************************/
void UartReceive_IDLE(UART_HandleTypeDef* huart)
{
	int i = 0,j=0;
  
  if(!__HAL_UART_GET_FLAG(huart,UART_FLAG_IDLE) )return;
  __HAL_UART_CLEAR_IDLEFLAG(huart);
  
  /* 出现2包间隔很短的情况，则继续接收 */
  if(__HAL_USART_GET_FLAG(huart, USART_FLAG_BUSY))return;
   
	if(huart->Instance == USART1)
	{
		i = USART1_RX_DMA_STREAM->NDTR;
    if(UART1_RX_BUFFER_MAX-i)
    {
      HAL_UART_DMAStopRx(huart);
      queue_push_buf(&com_obj[COM1].rx_queue,Uart1_pData,UART1_RX_BUFFER_MAX-i);
      memset(Uart1_pData,0,sizeof(Uart1_pData));     
    }else{
      READ_REG(USART1->RDR);
      __HAL_UART_CLEAR_OREFLAG(huart);
    }
    HAL_UART_Receive_DMA(huart,Uart1_pData,UART1_RX_BUFFER_MAX);
    __HAL_UART_DISABLE_IT(huart, UART_IT_ERR);
    __HAL_UART_DISABLE_IT(huart, UART_IT_PE);
	}
  
  else if(huart->Instance == USART2)
	{
		i = USART2_RX_DMA_STREAM->NDTR;
    if(UART2_RX_BUFFER_MAX-i)
    {
      HAL_UART_DMAStopRx(huart);
      queue_push_buf(&com_obj[COM2].rx_queue,Uart2_pData,UART2_RX_BUFFER_MAX-i);
      memset(Uart2_pData,0,sizeof(Uart2_pData));
    }else{
      READ_REG(USART2->RDR);
      __HAL_UART_CLEAR_OREFLAG(huart);
    }
    HAL_UART_Receive_DMA(huart,Uart2_pData,UART2_RX_BUFFER_MAX);
    __HAL_UART_DISABLE_IT(huart, UART_IT_ERR);
    __HAL_UART_DISABLE_IT(huart, UART_IT_PE);
	}
  
	else if(huart->Instance == USART3)
	{
		i = USART3_RX_DMA_STREAM->NDTR;
    if(UART3_RX_BUFFER_MAX-i)
    {
      HAL_UART_DMAStopRx(huart);
      queue_push_buf(&com_obj[COM3].rx_queue,Uart3_pData,UART3_RX_BUFFER_MAX-i);
      memset(Uart3_pData,0,sizeof(Uart3_pData));
    }else{
      READ_REG(USART3->RDR);
      __HAL_UART_CLEAR_OREFLAG(huart);
    }
    HAL_UART_Receive_DMA(huart,Uart3_pData,UART3_RX_BUFFER_MAX);
    __HAL_UART_DISABLE_IT(huart, UART_IT_ERR);
    __HAL_UART_DISABLE_IT(huart, UART_IT_PE);
	}
  
	else if(huart->Instance == UART4)
	{
		i = UART4_RX_DMA_STREAM->NDTR;
    if(UART4_RX_BUFFER_MAX-i)
    {
      HAL_UART_DMAStopRx(huart);		
      queue_push_buf(&com_obj[COM4].rx_queue,Uart4_pData,UART4_RX_BUFFER_MAX-i);
      memset(Uart4_pData,0,sizeof(Uart4_pData));
    }else{
      READ_REG(UART4->RDR);
      __HAL_UART_CLEAR_OREFLAG(huart);
    }
    HAL_UART_Receive_DMA(huart,Uart4_pData,UART4_RX_BUFFER_MAX);
    __HAL_UART_DISABLE_IT(huart, UART_IT_ERR);
    __HAL_UART_DISABLE_IT(huart, UART_IT_PE);
	}
  
  else if(huart->Instance == USART6)
	{
		i = USART6_RX_DMA_STREAM->NDTR;
    if(UART6_RX_BUFFER_MAX-i)
    {      
      HAL_UART_DMAStopRx(huart);		
      queue_push_buf(&com_obj[COM6].rx_queue,Uart6_pData,UART6_RX_BUFFER_MAX-i);
      memset(Uart6_pData,0,sizeof(Uart6_pData));
    }else{
      READ_REG(USART6->RDR);
      __HAL_UART_CLEAR_OREFLAG(huart);
    }
    HAL_UART_Receive_DMA(huart,Uart6_pData,UART6_RX_BUFFER_MAX);
    __HAL_UART_DISABLE_IT(huart, UART_IT_ERR);
    __HAL_UART_DISABLE_IT(huart, UART_IT_PE);
	}
	
	else if(huart->Instance == UART7)
	{
		i = UART7_RX_DMA_STREAM->NDTR;
    if(UART7_RX_BUFFER_MAX-i)
    {
      HAL_UART_DMAStopRx(huart);		
      queue_push_buf(&com_obj[COM7].rx_queue,Uart7_pData,UART7_RX_BUFFER_MAX-i);
      memset(Uart7_pData,0,sizeof(Uart7_pData));
    }else{
      READ_REG(UART7->RDR);
      __HAL_UART_CLEAR_OREFLAG(huart);
    }
    HAL_UART_Receive_DMA(huart,Uart7_pData,UART7_RX_BUFFER_MAX);
    __HAL_UART_DISABLE_IT(huart, UART_IT_ERR);
    __HAL_UART_DISABLE_IT(huart, UART_IT_PE);
	}
	
	else if(huart->Instance == UART8)
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
 * 功能：UART DMA发送完成中断回调函数
 * 输入：无          
 * 返回：
 * 说明：待完善
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
 
  /* USART2 ---------------------------------------------------------------- */ 
  if(huart->Instance == USART2)
	{
    if (0 < queue_size(&com_obj[COM2].tx_queue))
    {
      queue_len= queue_size(&com_obj[COM2].tx_queue);
      txlen= (UART2_TX_DMABUF_MAX < queue_len)? UART2_TX_DMABUF_MAX : queue_len;
      
      queue_pop_buf(&com_obj[COM2].tx_queue, Uart2_TxDmaBuf, txlen);     
      HAL_UART_Transmit_DMA(&com_obj[COM2].uart, Uart2_TxDmaBuf, txlen);
    }
    else{
      HAL_UART_DMAStopTx(huart);
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
  
  /* UART4 ----------------------------------------------------------------- */ 
  if(huart->Instance == UART4)
	{
    if (0 < queue_size(&com_obj[COM4].tx_queue))
    {
      queue_len= queue_size(&com_obj[COM4].tx_queue);
      txlen= (UART4_TX_DMABUF_MAX < queue_len)? UART4_TX_DMABUF_MAX : queue_len;
      
      queue_pop_buf(&com_obj[COM4].tx_queue, Uart4_TxDmaBuf, txlen);     
      HAL_UART_Transmit_DMA(&com_obj[COM4].uart, Uart4_TxDmaBuf, txlen);
    }
    else{
      HAL_UART_DMAStopTx(huart);
    }
  }
  
  /* USART6 ---------------------------------------------------------------- */ 
  if(huart->Instance == USART6)
	{
    if (0 < queue_size(&com_obj[COM6].tx_queue))
    {
      queue_len= queue_size(&com_obj[COM6].tx_queue);
      txlen= (UART6_TX_DMABUF_MAX < queue_len)? UART6_TX_DMABUF_MAX : queue_len;
      
      queue_pop_buf(&com_obj[COM6].tx_queue, Uart6_TxDmaBuf, txlen);     
      HAL_UART_Transmit_DMA(&com_obj[COM6].uart, Uart6_TxDmaBuf, txlen);
    }
    else{
      HAL_UART_DMAStopTx(huart);
    }  
  }
  
  /* UART7 ----------------------------------------------------------------- */ 
  if(huart->Instance == UART7)
	{
    if (0 < queue_size(&com_obj[COM7].tx_queue))
    {
      queue_len= queue_size(&com_obj[COM7].tx_queue);
      txlen= (UART7_TX_DMABUF_MAX < queue_len)? UART7_TX_DMABUF_MAX : queue_len;
      
      queue_pop_buf(&com_obj[COM7].tx_queue, Uart7_TxDmaBuf, txlen);     
      HAL_UART_Transmit_DMA(&com_obj[COM7].uart, Uart7_TxDmaBuf, txlen);
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


/******************************************************************************
 * 功能：UART DMA接收完成中断回调函数
 * 输入：无          
 * 返回：
 * 说明：待完善
 *
 *****************************************************************************/
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
  
}


/******************************************************************************
 * 功能：UART DMA错误中断回调函数
 * 输入：无          
 * 返回：
 * 说明：待完善
 *
 *****************************************************************************/
void HAL_UART_ErrorCallback(UART_HandleTypeDef *huart)
{

}



void debug_print(char* str)
{	
	serial_send(&com_obj[DBG_COM], str, strlen(str));	
}

void debug_send(void *buf, uint16_t len)
{
	serial_send(&com_obj[DBG_COM], buf, len);
}


void syserr_print(char* str)
{
#if OPT_SYS_ERR_PRINT_EN	
	serial_send(&com_obj[DBG_COM], str, strlen(str));	
#endif	
}

/*********************************** END OF FILE *************************************/
