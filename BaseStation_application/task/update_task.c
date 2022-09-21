/**************************************************************************************
 *
 * 文件描述：
 * 创建日期：
 *
 * 备注：
 *
 **************************************************************************************
 */

/* Includes ------------------------------------------------------------------*/

#include "update_task.h"

#include "includes.h"


/* Private_Defines -----------------------------------------------------------*/



/* Private_TypesDefinitions --------------------------------------------------*/



/* Private_Variables ---------------------------------------------------------*/
uint8_t nUpdateTaskID;

boot_config_t g_boot_cfg;

static uint8_t FirstUpdatePacketFlag = 0;
static uint32_t sResetFlag = 0;
static uint32_t sAppRecvTimer = 0;
static uint32_t nWriteLen = 0;


alink_message_head_t uart8_recv_msg;

static alink_message_head_t pAlinkMsg;

uint8_t msg_channel= ANT_MCU_COM;

/* FunctionPrototypes --------------------------------------------------------*/



/* Functions -----------------------------------------------------------------*/


//int32_t GetDMACountRegister(DMA_HandleTypeDef *hdma)
//{
//	return hdma->Instance->CNDTR;
//}

//void RCC_AHBPeriphClockCmd(uint32_t RCC_AHBPeriph, uint32_t NewState)
//{
//	if (NewState != DISABLE)
//  {
//    RCC->AHBENR |= RCC_AHBPeriph;
//  }
//  else
//  {
//    RCC->AHBENR &= ~RCC_AHBPeriph;
//  }
//}


/*================================================================================*
 * 函数名称:    int8_t WifiUpgrade(uint8_t chan, alink_message_head_t *msg)
 * 功能描述:    RC升级
 * 作    者:
 * 输入参数:    chan: 通道
                msg:  Alink消息
 * 输出参数:
 * 返 回 值:
 * 其他说明:
 * 创建历史:
 *
 *================================================================================*/
int8_t WifiUpgrade(uint8_t chan, alink_message_head_t *msg)
{
	  uint8_t nPacklen = 0;
    uint8_t IsNeedAck = 0;
		uint16_t i = 0;

    uint8_t *pBuf = (uint8_t *)msg->payload64;
    uint8_t *pPacketbuf = (uint8_t *)pAlinkMsg.payload64;
    uint16_t *phalfword = (uint16_t *)pAlinkMsg.payload64;
	  
    if(msg == NULL)return -1;

    switch(msg->msgid)
    {
			
			case 0x03:
        {
          if(pBuf[0] == 0x52)
          {
              // 来自图传的蜂鸣提示指令，pBuf[1]中的值定义了鸣叫次数。
              BuzzOn_time(0,0,pBuf[1],100,100);
              pPacketbuf[nPacklen++] = pBuf[0];
              pPacketbuf[nPacklen++] = 0;
              IsNeedAck = 1;
          }
        }		
        break;	
      
      case MAV_SYSTEM_CMD_GET_TIMEOUT_RETRYTIMES:     //0xDE  
        {				
          phalfword[0] = TIMOUT_PACKEGEWrite;
          phalfword[1] = PACKEGE_RetryTimes;
          phalfword[2] = PACKEGE_Size;
          phalfword[3] = TIMOUT_EraseFireware;
          phalfword[4] = TIMOUT_ChkCRC;
          phalfword[5] = TIMOUT_AppGo;
          phalfword[6] = TIMOUT_EnterBoot;
          phalfword[7] = TIMOUT_other;
          
          nPacklen= 16;
          IsNeedAck = 1;
        }break;
			
      case MAV_SYSTEM_CMD_RESET:                                                                          //0xD1系统复位
        {             
          if((*(uint16_t *)pBuf == 0x55AA) &&
            (*(uint16_t *)(pBuf+2) == 0x0002))
          {
            // 仅响应升级复位
            gGotoLoaderFlag = RC_UPDATE_FLAG | 0x0002;
            sAppRecvTimer = GET_CURTICK;
            sResetFlag = RESET_TO_BOOT_FLAG;
            pPacketbuf[nPacklen++] = ACK_TYPE_SUCCESS;                
          }
          else
          {
            pPacketbuf[nPacklen++] = ACK_TYPE_PARAM_ERR;
          }
          IsNeedAck = 1;           
        }break;
						
      case MAV_SYSTEM_CMD_FACTORY_RESET:                                                                   //0xD2      恢复出厂设置
        {
          if(*(uint16_t *)pBuf == 0x55AA)
          {
            pPacketbuf[nPacklen++] = ACK_TYPE_SUCCESS;
            pPacketbuf[nPacklen++] = 0x00;
          }
          else
          {
            pPacketbuf[nPacklen++] = ACK_TYPE_PARAM_ERR;
            pPacketbuf[nPacklen++] = 0x00;
          }
          IsNeedAck = 1;
        }break;
            
      case MAV_SYSTEM_CMD_SET_SN:                                                                         //0xD4  设置序列号
        {
          if(msg->len <= 96)
          {
            memset(&g_boot_cfg.sn[0],0,96);
            memcpy(&g_boot_cfg.sn[0],pBuf,msg->len);

            FlashErase_BootCfgSectors();
            FlashWrite_BootCfg(FLASH_BOOTINFO_ADDR, (uint8_t*)&g_boot_cfg, sizeof(boot_config_t));
            pPacketbuf[nPacklen++] = ACK_TYPE_SUCCESS;
          }else{
            pPacketbuf[nPacklen++] = ACK_TYPE_GENERAL_ERR;
          }
          IsNeedAck = 1;
        }break;
            
      case MAV_SYSTEM_CMD_GET_SN:         //0xD5  获取序列号
        {
          memcpy(pPacketbuf, g_boot_cfg.sn, sizeof(g_boot_cfg.sn));
          nPacklen = SERIAL_NUM_LEN;
          IsNeedAck = 1;
        }break;
            
      case MAV_SYSTEM_CMD_GET_APP_FLASH_SIZE:                                                             //0xD6      获取固件分区大小
        {
          uint32_t nFirmSize = FLASH_APP_SIZE;
          pPacketbuf[nPacklen++] = nFirmSize;
          pPacketbuf[nPacklen++] = nFirmSize>>8;
          pPacketbuf[nPacklen++] = nFirmSize>>16;
          pPacketbuf[nPacklen++] = nFirmSize>>24;
          IsNeedAck = 1;
        }
        break;
						
      case MAV_SYSTEM_CMD_SET_HW_VERSION:                                                                     //0xDA       设置硬件版本
        {		
          uint32_t nHardwareVer;
          nHardwareVer = *(uint32_t *)pBuf;
          g_boot_cfg.hw_version = nHardwareVer;
          FlashErase_BootCfgSectors();
          FlashWrite_BootCfg(FLASH_BOOTINFO_ADDR, (uint8_t*)&g_boot_cfg, sizeof(boot_config_t));
          pPacketbuf[nPacklen++] = ACK_TYPE_SUCCESS;
          pPacketbuf[nPacklen++] = 0x00;
          IsNeedAck = 1;
        }
        break;
						
      case MAV_SYSTEM_CMD_GET_VERSIONS:                                                                       //0xDB      获取版本信息
        {												
          if(g_boot_cfg.magic == MAGIC_VALUE)
          {
            pPacketbuf[0] = g_boot_cfg.app_version & 0xFF;
            pPacketbuf[1] = (g_boot_cfg.app_version >> 8) & 0xFF;
            pPacketbuf[2] = (g_boot_cfg.app_version >> 16) & 0xFF;
            pPacketbuf[3] = (g_boot_cfg.app_version >> 24) & 0xFF;          
          }else{
            pPacketbuf[0] = 0;
            pPacketbuf[1] = 0;
            pPacketbuf[2] = 0;
            pPacketbuf[3] = 0;
          }
          pPacketbuf[4] = g_boot_cfg.boot_version & 0xFF;
          pPacketbuf[5] = (g_boot_cfg.boot_version >> 8) & 0xFF;
          pPacketbuf[6] = (g_boot_cfg.boot_version >> 16) & 0xFF;
          pPacketbuf[7] = (g_boot_cfg.boot_version >> 24) & 0xFF;
          pPacketbuf[8] = g_boot_cfg.hw_version & 0xFF;
          pPacketbuf[9] = (g_boot_cfg.hw_version >> 8) & 0xFF;
          pPacketbuf[10] = (g_boot_cfg.hw_version >> 16) & 0xFF;
          pPacketbuf[11] = (g_boot_cfg.hw_version >> 24) & 0xFF;
          pPacketbuf[12] = 0;
          pPacketbuf[13] = 0;
          pPacketbuf[14] = 0;
          pPacketbuf[15] = 0;
          
          nPacklen = 16;
          IsNeedAck = 1;
        }
        break;
						
      default:
				{
          pPacketbuf[nPacklen++] = ACK_TYPE_GENERAL_ERR;
          IsNeedAck = 1;
				}break;

    }
    if(IsNeedAck)
    {
        pAlinkMsg.sourceid =DEV_BASESTATION ;
				pAlinkMsg.destid = msg->sourceid;
        pAlinkMsg.msgid = msg->msgid;
        pAlinkMsg.len = nPacklen;
        AlinkPacket_Reply(chan, &pAlinkMsg);
    }
    return 0;
}


/*================================================================================*
 * 函数名称:    int32_t DevDSP_AlinkMsgParse(uint8_t chan, alink_message_head_t *pMsg)
 * 功能描述:    DSP解析
 * 作    者:
 * 输入参数:
 * 输出参数:
 * 返 回 值:    -1失败  0成功
 * 其他说明:
 * 创建历史:
 *================================================================================*/
int32_t DevDSP_AlinkMsgParse(uint8_t chan, alink_message_head_t *pMsg)
{
  uint8_t Msgid = pMsg->msgid;
  uint8_t AckSts = 1;
  uint8_t *pByte = NULL;
  pByte = (uint8_t*)pMsg->payload64;
	
  switch(Msgid)
  {
    case 0x91:
			/* 图传信号状态消息 */
			sys_info.flag.videotran_con_ok= (pByte[0] > 0)? 1:0;
			sys_info.flag.videotran_mode= (pByte[3] > 0)? 1:0;
			sys_info.flag.videotran_stat_update= 1;
			break;
		
		case 0x93:
			if (pMsg->destid == DEV_BASESTATION)
			{
				if (pByte[0] == 0x01 && pMsg->len >= 5)
				{
					/* 图传LED状态消息 */
					uint16_t dat1= pByte[2]*256 + pByte[1];
					uint16_t dat2= pByte[4]*256 + pByte[3];
					uint32_t sum= dat1+dat2;
					
					if (dat1 == 0xffff)	// 对频灯常亮
					{
						sys_info.match_led_on_tim= 2000;
						sys_info.match_led_off_tim= 0;
						sys_info.match_led_tim_period= 2000;
					}
					else if (dat2 == 0xffff)	// 对频灯常灭
					{
						sys_info.match_led_on_tim= 0;
						sys_info.match_led_off_tim= 2000;
						sys_info.match_led_tim_period= 2000;
					}
					else if (sum <= 5000)	// 对频灯闪烁，周期小于5s
					{
						sys_info.match_led_on_tim= dat1;
						sys_info.match_led_off_tim= dat2;
						sys_info.match_led_tim_period= sum;
					}
					else	// 非法数据，灭灯
					{
						sys_info.match_led_on_tim= 0;
						sys_info.match_led_off_tim= 2000;
						sys_info.match_led_tim_period= 2000;
					}										
				}
			}
			break;
			
		case 0x97:
			/* 图传配对应答消息，0：收到；1：配对失败；2：配对成功； */
			if(pByte[0] > 0) {
				sys_info.flag.videotran_match= 0;
			}
			break;
		
		case 0x98:
      /* 转发RC数据到图传COM1 */
      //serial_send(&com_obj[DSP_COM1],&pByte[0],9);
      break;
    
    case 0xAB:    // CRC_0xCC
      /* 基站参数设置消息的解析处理 */
      base_set_msg_parse(chan,pMsg);
      break;
    
    default:
      /* 基站升级处理 */
      if ((Msgid >=0xD0 && Msgid <= 0xFF)  || Msgid == 0x03)
      {
        WifiUpgrade(chan,pMsg);
      }
      break;
  }
  return 0;
}


/*================================================================================*
 * 函数名称:    int32_t DevWIFI_AlinkMsgParse(uint8_t chan, alink_message_head_t *pMsg)
 * 功能描述:    WIFI消息解析
 * 作    者:
 * 输入参数:
 * 输出参数:
 * 返 回 值:    -1失败  0成功
 * 其他说明:
 * 创建历史:
 *================================================================================*/
int32_t DevWIFI_AlinkMsgParse(uint8_t chan, alink_message_head_t *pMsg)
{
  uint8_t Msgid = pMsg->msgid;
  uint8_t AckSts = 1;
  uint8_t *pByte = NULL;
  pByte = (uint8_t*)pMsg->payload64;
  switch(Msgid)
  {
    case 0x98:
      /* 转发RC数据到图传COM1 */
      //serial_send(&com_obj[DSP_COM1],&pByte[0],9);
      break;
    
    case 0xAB:    // CRC_0xCC
      /* 基站参数设置消息的解析处理 */
      base_set_msg_parse(chan,pMsg);
      break;
    
    default:
      /* 基站升级处理 */
      if ((Msgid >=0xD0 && Msgid <= 0xFF)  || Msgid == 0x03)
      {
        WifiUpgrade(chan,pMsg);
      }
      break;
  }
  return 0;
}


/*================================================================================*
 * 函数名称:    void update_comm_running()
 * 功能描述:    
 * 作    者:
 * 输入参数:
 * 输出参数:
 * 返 回 值:
 * 其他说明:
 * 创建历史:
 *================================================================================*/ 
void update_comm_running()
{
	uint16_t   count,i,len;

	if(queue_size(&com_obj[ANT_MCU_COM].rx_queue) != 0)
	{
		if(packet_receive(&com_obj[ANT_MCU_COM], &uart8_recv_msg, 0) > 0)
		{
      msg_channel= ANT_MCU_COM;
			switch(uart8_recv_msg.destid)
			{
				case DEV_BASESTATION:
				{
					DevDSP_AlinkMsgParse(0,&uart8_recv_msg);
				}
				break;
				default:
					break;
			}
		}
	}
  
  if(queue_size(&com_obj[WIFI_COM].rx_queue) != 0)
	{
		if(packet_receive(&com_obj[WIFI_COM], &uart8_recv_msg, 0) > 0)
		{
      msg_channel= WIFI_COM;
			switch(uart8_recv_msg.destid)
			{
				case DEV_BASESTATION:
				{
					DevWIFI_AlinkMsgParse(0,&uart8_recv_msg);
				}
				break;
				default:
					break;
			}
		}
	}
} 
 

/*================================================================================*
 * 函数名称:    void AddUpdateTask()
 * 功能描述:    增加任务
 * 作    者:
 * 输入参数:
 * 输出参数:
 * 返 回 值:
 * 其他说明:
 * 创建历史:
 *
 *================================================================================*/
void AddUpdateTask(void)
{
    nUpdateTaskID = AddTask(UpdateTaskInit, UpdateTask, UpdateTaskUninit);
}

/*================================================================================*
 * 函数名称:    uint32_t UpdateTaskInit(void)
 * 功能描述:    任务初始化
 * 作    者:
 * 输入参数:
 * 输出参数:
 * 返 回 值:
 * 其他说明:
 * 创建历史:
 *================================================================================*/
int32_t UpdateTaskInit(void)
{
    return 0;
}

/*================================================================================*
 * 函数名称:    void UpdateTask()
 * 功能描述:    
 * 作    者:
 * 输入参数:
 * 输出参数:
 * 返 回 值:
 * 其他说明:    
 * 创建历史:
 *
 *================================================================================*/
void UpdateTask(void)
{
	static uint32_t nUpdateTaskTimer = 0;
  
	if(GET_PASTTICK(nUpdateTaskTimer)>=1)
	{
		nUpdateTaskTimer = GET_CURTICK;
		update_comm_running();
	}
  
  
	if(GET_PASTTICK(sAppRecvTimer)>=5 && sResetFlag == RESET_TO_BOOT_FLAG)
	{
    /* 跳转到boot必须关闭所有中断 */
    __DISABLE_IRQ(); 
    
    MX_USART1_UART_UnInit();
    MX_USART2_UART_UnInit();
    MX_USART3_UART_UnInit();
		DBG_UART_UnInit();
//    MX_UART4_UART_UnInit();	
//    MX_USART6_UART_UnInit();
//    MX_UART7_UART_UnInit();
		MX_UART8_UART_UnInit();
    bsp_adc_uninit();
    HAL_NVIC_DisableIRQ(EXTI9_5_IRQn);
    HAL_NVIC_DisableIRQ(SysTick_IRQn);
		msp_spi1_uninit();
		match_led_tim_uninit();
		msp_i2c_uninit(I2C2);
		msp_i2c_uninit(I2C4);
      
    do_jump(FLASH_BOOTLOADER_ADDR);
   
	}
}

/*================================================================================*
 * 函数名称:    uint32_t UpdateTaskUninit(void)
 * 功能描述:   
 * 作    者:
 * 输入参数:
 * 输出参数:
 * 返 回 值:
 * 其他说明:
 * 创建历史:
 *
 *================================================================================*/
int32_t UpdateTaskUninit(void)
{
    return 0;
}



void boot_info_init(void)
{
  FlashRead((uint32_t)pBOOTCONFIG, (void*)&g_boot_cfg, sizeof(g_boot_cfg));
}



















