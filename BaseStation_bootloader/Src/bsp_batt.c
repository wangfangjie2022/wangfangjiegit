/**************************************************************************************
 *
 * 文件描述：电池通讯相关接口
 * 创建日期：
 *
 * 备注：快充基站的电池由原来的I2C通讯更改为UART1串口通讯，电池自带自放电及均衡功能（动力电芯）。
 *
 **************************************************************************************
 */

/* Includes ------------------------------------------------------------------*/

#include "includes.h"



/* Private_Defines -----------------------------------------------------------*/



/* Private_TypesDefinitions --------------------------------------------------*/



/* Private_Variables ---------------------------------------------------------*/

uint8_t gBattery_Percent = 50;
uint8_t bat_info_updated = 0;
uint32_t batt_msg_tim = 0;

batt_info_t batt_info[BAT_DEV_TOTAL_NUM];

extern alink_message_head_t alink_txmsg;


///* 电池唤醒和休眠消息 ------------------------------------------- */
//const uint8_t batt_wakeup_msg[]={
//  0xfd, 0x01, 0x00, 0x4d, 0x2c, 0x1c, 0x03, 0x96, 0xa0, 0x49, 0x7b
//};

//const uint8_t batt_sleep_msg[]={
//  0xfd, 0x01, 0x00, 0x4e, 0x2c, 0x1c, 0x03, 0x97, 0xa1, 0x23, 0x90
//};


/* FunctionPrototypes --------------------------------------------------------*/



/* Functions -----------------------------------------------------------------*/

/******************************************************************************
 * 功能：
 * 输入：无          
 * 返回：
 * 说明：
 *
 *****************************************************************************/

#if 0
/******************************************************************************
 * 功能：以200ms间隔发送电池唤醒消息。
 * 输入：无          
 * 返回：无
 * 说明：唤醒操作需发送2次才能真正唤醒电池并发出电量信息。
 *
 *****************************************************************************/
void batt_wakeup(uint8_t flag)
{
  static uint32_t gap_tim=0;
  
  if(GET_PASTTICK(gap_tim)>200 || flag)
  {
    serial_send(&com_obj[COM1], (uint8_t*)batt_wakeup_msg, sizeof(batt_wakeup_msg));
    gap_tim= GET_CURTICK;
  }
 
}

/******************************************************************************
 * 功能：发送电池休眠消息。
 * 输入：无          
 * 返回：无
 * 说明：在基站关机前先向电池发送休眠消息，使其进入低功耗模式再关机。
 *
 *****************************************************************************/
void batt_sleep(void)
{
  serial_send(&com_obj[COM1], (uint8_t*)batt_sleep_msg, sizeof(batt_sleep_msg));
}




uint8_t is_timout_batt_msg(void)
{
  if(GET_PASTTICK(batt_msg_tim)>2000)
  {
    return 1;
  }
  return 0;
}
#endif

/******************************************************************************
 * 功能：电池消息接收和解析
 * 输入：无          
 * 返回：0--未完成； 1--已完成
 * 说明：
 *
 *****************************************************************************/
void batt_msg_parse(alink_message_head_t *pMsg)
{
  uint8_t msgid = pMsg->msgid;
  alink_muti_bat_data_t *batt_msg = NULL;
  uint8_t batt_percent = 0;
  
  switch(msgid)
  {
    case ALINK_MSG_ID_MUTI_BAT_DATA:		// 0x40
      batt_msg= (void*)pMsg->payload64;
			uint8_t sn= batt_msg->bat_status & BAT_DEV_SN_MASK;
			if(sn < BAT_DEV_SN_START || sn > BAT_DEV_SN_MAX)break;
			sn -= BAT_DEV_SN_START;
			memcpy(&batt_info[sn].batt_dat, batt_msg, sizeof(alink_muti_bat_data_t));
			batt_info[sn].flg_bat_valid= 1;
			batt_info[sn].flg_dat_update= 1;
		  batt_info[sn].cnt_bat_msg++;
      batt_info[sn].cnt_timout= 0;
      break;
    
    default:
      break;
  }
}



uint8_t get_bat_percent(void)
{
  //return gBattery_Percent;
	uint8_t i, bat_percent_max=0;

	for(i=0; i< BAT_DEV_TOTAL_NUM; i++)
	{	
		if(batt_info[i].flg_bat_valid == 1 && batt_info[i].batt_dat.rsoc > bat_percent_max)
		{
			bat_percent_max= batt_info[i].batt_dat.rsoc;
		}
	}
	
	return bat_percent_max;
}


/******************************************************************************
 * 功能：RS485总线上请求电池数据
 * 输入：电池序号，有效范围0-3          
 * 返回：0--发送成功； -1--发送失败
 * 说明：
 *
 *****************************************************************************/
int32_t rs485_request_data(uint8_t cmd, rs485_dev_num_e dev_num, uint8_t sub_cmd)
{
	uint16_t i=0, len=0;
	rs485_req_data_t rs485_req_data;
	
	rs485_req_data.cmd 				= cmd;
	rs485_req_data.dev_num 		= dev_num;
	rs485_req_data.sub_cmd 		= sub_cmd;
	
	len= sizeof(rs485_req_data_t);
	memcpy((void*)&alink_txmsg.payload64[0], (void*)&rs485_req_data, len);
	
	alink_txmsg.msgid= 0x03;
	
	len = alink_finalize_message_chan(&alink_txmsg, DEV_BATTERY, DEV_BASESTATION, ALINK_CHAN_BAT, len, alinkmsg_crcs[alink_txmsg.msgid]);

  if(serial_send(&com_obj[BAT_COM], &alink_txmsg.magic, len) < 0)
  {
    return -1;
  }

  return 0;
}



/******************************************************************************
 * 功能：RS485总线上请求电池数据
 * 输入：电池序号，有效范围0-3          
 * 返回：0--发送成功； -1--发送失败
 * 说明：
 *
 *****************************************************************************/
void rs485_comm_task(void)
{
	static uint32_t runtim=0, timout=0;
	static uint8_t dev_num= eDevSN_Idle;
	static uint8_t flg_request= 0;
	
	switch(dev_num)
	{
	case eDevSN_Batt_1:
		{
			if(flg_request == 0)
			{
				batt_info[0].flg_dat_update= 0;
				flg_request= 1;
				rs485_request_data(RS485_CMD_GET_DEV_DYNAMIC_INFO, eDevSN_Batt_1, SUB_CMD_GET_BAT_DATA);
				timout= GET_CURTICK;
			}
			if(batt_info[0].flg_dat_update || GET_PASTTICK(timout) > RS485_TIMOUT_ms)
			{
				if(GET_PASTTICK(timout) > RS485_TIMOUT_ms)
				{
					if(batt_info[0].cnt_timout++ >= 3)
					{
						batt_info[0].flg_bat_valid= 0;
					}
				}
				
				if(GET_PASTTICK(timout) > 50)
				{
					dev_num= eDevSN_Batt_2;	
					flg_request= 0;
				}
			}			
		}break;
		
	case eDevSN_Batt_2:
		{
			if(flg_request == 0)
			{
				batt_info[1].flg_dat_update= 0;
				flg_request= 1;
				rs485_request_data(RS485_CMD_GET_DEV_DYNAMIC_INFO, eDevSN_Batt_2, SUB_CMD_GET_BAT_DATA);
				timout= GET_CURTICK;
			}
			if(batt_info[1].flg_dat_update || GET_PASTTICK(timout) > RS485_TIMOUT_ms)
			{
				if(GET_PASTTICK(timout) > RS485_TIMOUT_ms)
				{
					if(batt_info[1].cnt_timout++ >= 3)
					{
						batt_info[1].flg_bat_valid= 0;
					}
				}
				if(GET_PASTTICK(timout) > 50)
				{
					dev_num= eDevSN_Idle;	
					flg_request= 0;
				}
			}			
		}break;
		
	case eDevSN_Batt_3:
			
		break;
		
	case eDevSN_Batt_4:
			
		break;
		
	case eDevSN_KeyLed:
			
		break;
	
	case eDevSN_Idle:
	default:
		if(GET_PASTTICK(runtim) > 1000)
		{
			runtim= GET_CURTICK;
			dev_num= eDevSN_Batt_1;	
			flg_request= 0;
		}	
		break;
	}
	
	
}


















/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
