
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef _USART_TASK_H_
#define _USART_TASK_H_

#ifdef __cplusplus
 extern "C" {
#endif
#include "Sys_cfg.h"
#include "bsp_uart.h"

extern alink_message_head_t alink_txmsg;


int packet_receive(serial_obj_t *pcom, alink_message_head_t *pmsg, uint32_t timeout);
int packet_transmit(serial_obj_t *pcom, alink_message_head_t *pmsg);
void comm_running(void);
//int packet_send(serial_obj_t *pcom, alink_message_head_t *pmsg);
	 
void AddUartCommonTask(void);
int32_t UartCommonTaskInit(void);	 
void UartCommonTask(void);
int32_t UartCommonTaskUninit(void);
	 
#ifdef __cplusplus
}
#endif

#endif /* __USBD_DESC__H__ */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
