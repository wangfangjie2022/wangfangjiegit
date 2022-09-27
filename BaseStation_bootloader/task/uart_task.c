/**
  ******************************************************************************
  * File Name          : common.c
  * Description        : This file provides code for uart receive and parse
  ******************************************************************************
  ******************************************************************************
  */
/* Includes ------------------------------------------------------------------*/
#include "usart_task.h"
#include "Sys_cfg.h"

/* USER CODE BEGIN 0 */

/*================================================================================*
 *                                   宏定义                                       *
 *================================================================================*/

/*================================================================================*
 *                                全局变量定义                                    *
 *================================================================================*/
uint8_t nUartCommonTaskID;

/*================================================================================*
 *                               局部变量定义                                     *
 *================================================================================*/
static uint8_t send_buf[1024];
static alink_message_head_t msg;
alink_message_head_t alink_txmsg;
static alink_status_t status;
extern serial_obj_t com_obj[3];
/*================================================================================*
 *                                 函数声明                                       *
 *================================================================================*/


/*================================================================================*
 *                                 函数原型                                       *
 *================================================================================*/


int packet_receive(serial_obj_t *pcom, alink_message_head_t *pmsg, uint32_t timeout)
{
	uint8_t ch;
	uint8_t ret = 0;
	uint8_t chan; 
	if( serial_getchar(pcom, &ch, timeout) > 0)
	{
		if(pcom->com == ANT_MCU_COM) {
			chan= ALINK_COMM_0;
		} else if(pcom->com == WIFI_COM) {
			chan= ALINK_COMM_1;
		} else {
			chan= ALINK_COMM_2;
		}
		
		ret = alink_parse_char(chan, ch, pmsg, &status);
		return ret;
	}
	return 0;
}


/******************************************************************************************
 Function Name: 转发消息函数
 Description  : 发送消息
 Input Params : @pcom		串口对象指针
				@pmsg		需转发的消息指针
 Output Params: @return		成功返回1，失败返回负数
 Global	List  : None
 Note         : 调用该函数时发送包序列号会自动增1
 Usage        : None
******************************************************************************************/
int packet_transmit(serial_obj_t *pcom, alink_message_head_t *pmsg)
{
	uint16_t len;
	len = alink_msg_to_send_buffer(send_buf, pmsg);
	serial_send(pcom, send_buf, len);
	return 1;
}


static void transmit_data(alink_message_head_t *pmsg)
{
//	switch(pmsg->destid)
//	{
//		case DEV_UAV:            //飞控数据
//		case DEV_RC:			//遥控器
//		case DEV_APP:			//App ��Android or iOS��
//		case DEV_PC:            //电脑
//		case DEV_GIMBAL:	    //云台数据，通过串口3发送出去，
//		case DEV_RADAR:         //雷达数据，发送出去
//			//printf("transmit !!!\r\n");
//			//packet_transmit(&com_obj[COM1], pmsg); //通过869M发送出去
//			break;
//		case DEV_SONAR:        //超声数据，发送出去
//		case DEV_DSP:			//地面图传
//		case DEV_DSP_RC:		//地面图传
//		case DEV_MOVIDIUS_1:
//		case DEV_MOVIDIUS_2:
//		case DEV_MOVIDIUS_3:
//		case DEV_TOF:
//			packet_transmit(&com_obj[COM7], pmsg);
//			break;
//		default:
//			break;
//	}
}


void comm_running(void)
{
  /* USART1 与电池通讯，获取基站电量信息，开机时需唤醒电池，唤醒消息发送间隔200ms */
	if(packet_receive(&com_obj[COM1], &msg, 0) > 0)
	{
    batt_msg_parse(&msg);  
	}
  rs485_comm_task();
  
  /* UART8 与天线端MCU（接图传）进行Alink消息的交互 */
//	if(packet_receive(&com_obj[COM8], &dsp_msg, 0) > 0)
//	{
//		transmit_data(&dsp_msg);
//	}


  
}

//int packet_send(serial_obj_t *pcom, alink_message_head_t *pmsg)
//{
//	uint16_t len;
//	if(pmsg == NULL)
//	{
//		return -1;
//	}
//	//alink_finalize_message_chan(pmsg, pmsg->destid, pmsg->sourceid, pcom->com, pmsg->len, 0);
//	len = alink_msg_to_send_buffer(send_buf, pmsg);
//	serial_send(pcom, send_buf, len);
//	return 1;
//}

 
/*================================================================================*
 * 函数名称:    void AddUartCommonTask()
 * 功能描述:    增加任务
 * 作    者:
 * 输入参数:
 * 输出参数:
 * 返 回 值:
 * 其他说明:
 * 创建历史:
 *
 *================================================================================*/
void AddUartCommonTask(void)
{
    nUartCommonTaskID = AddTask(UartCommonTaskInit, UartCommonTask, UartCommonTaskUninit);
//		printf("AddUartCommonTask !!!nUartCommonTaskID = %d\r\n",nUartCommonTaskID);
}

/*================================================================================*
 * 函数名称:    uint32_t UartCommonTaskInit(void)
 * 功能描述:    任务初始化
 * 作    者:
 * 输入参数:
 * 输出参数:
 * 返 回 值:
 * 其他说明:
 * 创建历史:
 *================================================================================*/
int32_t UartCommonTaskInit(void)
{
    return 0;
}


/*================================================================================*
 * 函数名称:    void UartCommonTask()
 * 功能描述:    
 * 作    者:
 * 输入参数:
 * 输出参数:
 * 返 回 值:
 * 其他说明:    
 * 创建历史:
 *
 *================================================================================*/
void UartCommonTask(void)
{
	  comm_running();
}

/*================================================================================*
 * 函数名称:    uint32_t UartCommonTaskUninit(void)
 * 功能描述:   
 * 作    者:
 * 输入参数:
 * 输出参数:
 * 返 回 值:
 * 其他说明:
 * 创建历史:
 *
 *================================================================================*/
int32_t UartCommonTaskUninit(void)
{
    return 0;
}


/* USER CODE END 0 */



/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
