/**************************************************************************************
 *
 * 文件描述：UART相关接口
 * 创建日期：
 *
 * 备注：
 *
 **************************************************************************************
 */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __BSP_UART_H
#define __BSP_UART_H

/* Includes ------------------------------------------------------------------*/
#include "stm32h7xx_hal.h"
#include "cqueue.h"
#include "alink.h"
#include "alink_types.h"

/* Exported_Macros -----------------------------------------------------------*/ 
#define UART1_RX_BUFFER_MAX   512
#define UART2_RX_BUFFER_MAX   2048
#define UART3_RX_BUFFER_MAX   512
#define UART4_RX_BUFFER_MAX   64
#define UART6_RX_BUFFER_MAX   64
#define UART7_RX_BUFFER_MAX   64
#define UART8_RX_BUFFER_MAX   2048

#define UART1_TX_FIFO_MAX     256
#define UART2_TX_FIFO_MAX     512
#define UART3_TX_FIFO_MAX     256
#define UART4_TX_FIFO_MAX     64
#define UART6_TX_FIFO_MAX     1024
#define UART7_TX_FIFO_MAX     64
#define UART8_TX_FIFO_MAX     2048

#define UART1_TX_DMABUF_MAX   64
#define UART2_TX_DMABUF_MAX   64
#define UART3_TX_DMABUF_MAX   64
#define UART4_TX_DMABUF_MAX   64
#define UART6_TX_DMABUF_MAX   64
#define UART7_TX_DMABUF_MAX   64
//#define UART8_TX_DMABUF_MAX   64
#define UART8_TX_DMABUF_MAX   1024








#define USART1_TX_DMA_STREAM        DMA1_Stream0
#define USART1_RX_DMA_STREAM        DMA1_Stream1
#define USART1_TX_DMA_IRQn          DMA1_Stream0_IRQn
#define USART1_RX_DMA_IRQn          DMA1_Stream1_IRQn
#define USART1_DMA_TX_IRQHandler    DMA1_Stream0_IRQHandler
#define USART1_DMA_RX_IRQHandler    DMA1_Stream1_IRQHandler



#define USART2_TX_DMA_STREAM        DMA1_Stream2
#define USART2_RX_DMA_STREAM        DMA1_Stream3
#define USART2_TX_DMA_IRQn          DMA1_Stream2_IRQn
#define USART2_RX_DMA_IRQn          DMA1_Stream3_IRQn
#define USART2_DMA_TX_IRQHandler    DMA1_Stream2_IRQHandler
#define USART2_DMA_RX_IRQHandler    DMA1_Stream3_IRQHandler


#define USART3_TX_DMA_STREAM        DMA1_Stream4
#define USART3_RX_DMA_STREAM        DMA1_Stream5
#define USART3_TX_DMA_IRQn          DMA1_Stream4_IRQn
#define USART3_RX_DMA_IRQn          DMA1_Stream5_IRQn
#define USART3_DMA_TX_IRQHandler    DMA1_Stream4_IRQHandler
#define USART3_DMA_RX_IRQHandler    DMA1_Stream5_IRQHandler


#define UART4_TX_DMA_STREAM         DMA1_Stream6
#define UART4_RX_DMA_STREAM         DMA1_Stream7
#define UART4_TX_DMA_IRQn           DMA1_Stream6_IRQn
#define UART4_RX_DMA_IRQn           DMA1_Stream7_IRQn
#define UART4_DMA_TX_IRQHandler     DMA1_Stream6_IRQHandler
#define UART4_DMA_RX_IRQHandler     DMA1_Stream7_IRQHandler

//#define UART5_TX_DMA_STREAM         DMA2_Stream0
//#define UART5_RX_DMA_STREAM         DMA2_Stream1
//#define UART5_TX_DMA_IRQn           DMA2_Stream0_IRQn
//#define UART5_RX_DMA_IRQn           DMA2_Stream1_IRQn

#define USART6_TX_DMA_STREAM        DMA2_Stream2
#define USART6_RX_DMA_STREAM        DMA2_Stream3
#define USART6_TX_DMA_IRQn          DMA2_Stream2_IRQn
#define USART6_RX_DMA_IRQn          DMA2_Stream3_IRQn
#define USART6_DMA_TX_IRQHandler    DMA2_Stream2_IRQHandler
#define USART6_DMA_RX_IRQHandler    DMA2_Stream3_IRQHandler

#define UART7_TX_DMA_STREAM         DMA2_Stream4
#define UART7_RX_DMA_STREAM         DMA2_Stream5
#define UART7_TX_DMA_IRQn           DMA2_Stream4_IRQn
#define UART7_RX_DMA_IRQn           DMA2_Stream5_IRQn
#define UART7_DMA_TX_IRQHandler     DMA2_Stream4_IRQHandler
#define UART7_DMA_RX_IRQHandler     DMA2_Stream5_IRQHandler


#define UART8_TX_DMA_STREAM         DMA2_Stream6
#define UART8_RX_DMA_STREAM         DMA2_Stream7
#define UART8_TX_DMA_IRQn           DMA2_Stream6_IRQn
#define UART8_RX_DMA_IRQn           DMA2_Stream7_IRQn
#define UART8_DMA_TX_IRQHandler     DMA2_Stream6_IRQHandler
#define UART8_DMA_RX_IRQHandler     DMA2_Stream7_IRQHandler



/* Exported_Types ------------------------------------------------------------*/
typedef enum {
	COM1 = 0,
  COM2,
	COM3,
	COM4,
	COM6,
	COM7,
	COM8,
	COM_N,
} serial_com_e;

#define BAT_COM           COM1
#define RTK_COM1          COM2
#define WIFI_COM          COM3
#define ANT_MCU_COM       COM8
#define DBG_COM						COM6



typedef struct {
	serial_com_e com;
	UART_HandleTypeDef uart;
	queue_t rx_queue;
  queue_t tx_queue;
  uint8_t flg_init;
} serial_obj_t;

#define     PACKET_SEND(buf,len)    serial_send(&com_obj[ANT_MCU_COM],buf, len)






/* Exported_Variables --------------------------------------------------------*/
extern DMA_HandleTypeDef hdma_usart1_rx;
extern DMA_HandleTypeDef hdma_usart1_tx;
extern DMA_HandleTypeDef hdma_usart2_rx;
extern DMA_HandleTypeDef hdma_usart2_tx;
extern DMA_HandleTypeDef hdma_usart3_rx;
extern DMA_HandleTypeDef hdma_usart3_tx;
extern DMA_HandleTypeDef hdma_uart4_rx;
extern DMA_HandleTypeDef hdma_uart4_tx;
extern DMA_HandleTypeDef hdma_usart6_rx;
extern DMA_HandleTypeDef hdma_usart6_tx;
extern DMA_HandleTypeDef hdma_uart7_rx;
extern DMA_HandleTypeDef hdma_uart7_tx;
extern DMA_HandleTypeDef hdma_uart8_rx;
extern DMA_HandleTypeDef hdma_uart8_tx;

extern uint8_t Uart1_pData[];
extern uint8_t Uart2_pData[];
extern uint8_t Uart3_pData[];
extern uint8_t Uart4_pData[];
extern uint8_t Uart6_pData[];
extern uint8_t Uart7_pData[];
extern uint8_t Uart8_pData[];

extern serial_obj_t com_obj[];

extern uint8_t msg_channel;

extern const uint8_t alinkmsg_crcs[];


#define DBG_STR_LEN			512
extern char dbg_str[];

/* Exported_Functions --------------------------------------------------------*/
extern void _Error_Handler(char *, int);


void MX_USART1_UART_Init(void);
void MX_USART2_UART_Init(void);
void MX_USART3_UART_Init(void);
void MX_UART4_UART_Init(void);
void MX_USART6_UART_Init(void);
void MX_UART7_UART_Init(void);
void MX_UART8_UART_Init(void);

void MX_USART1_UART_UnInit(void);
void MX_USART2_UART_UnInit(void);
void MX_USART3_UART_UnInit(void);
void MX_UART4_UART_UnInit(void);
void MX_USART6_UART_UnInit(void);
void MX_UART7_UART_UnInit(void);
void MX_UART8_UART_UnInit(void);

void UARTx_BaudRate_Config(serial_com_e COMx, uint32_t bps);

#define DBG_UART_Init()			MX_USART6_UART_Init()
#define DBG_UART_UnInit()		MX_USART6_UART_UnInit()


int serial_getchar(serial_obj_t *pcom, uint8_t *ch, uint32_t timeout);
int serial_send(serial_obj_t *pcom, void *buf, uint16_t len);
int32_t AlinkPacket_Reply(uint8_t chan, alink_message_head_t *pmsg);

HAL_StatusTypeDef HAL_UART_DMAStopRx(UART_HandleTypeDef *huart);
void UartReceive_IDLE(UART_HandleTypeDef* huart);
void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart);
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart);
void HAL_UART_ErrorCallback(UART_HandleTypeDef *huart);




int packet_receive(serial_obj_t *pcom, alink_message_head_t *pmsg, uint32_t timeout);
int packet_transmit(serial_obj_t *pcom, alink_message_head_t *pmsg);
void comm_running(void);
	 
void AddUartCommonTask(void);
int32_t UartCommonTaskInit(void);	 
void UartCommonTask(void);
int32_t UartCommonTaskUninit(void);
void debug_print(char* str);
void debug_send(void *buf, uint16_t len);
void syserr_print(char* str);







#endif
