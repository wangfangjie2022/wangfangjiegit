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
#include "Sys_cfg.h"
#include "main.h"
#include "includes.h"


/*================================================================================*
 *                                   宏定义                                       *
 *================================================================================*/

/*================================================================================*
 *                                全局变量定义                                    *
 *================================================================================*/
uint8_t nUpdateTaskID;
uint8_t gIsUpdate = 0;


//TEXTINFO gTextInfo;
uint8_t g_crc32_buf[1024];

boot_params_t g_boot= {
  .file_size= 0,
  .download_count= 0,
  .upgrade_allow_flag= 0,  
};

/*================================================================================*
 *                               局部变量定义                                     *
 *================================================================================*/
extern uint8_t gBattery_Percent;
static uint8_t FirstUpdatePacketFlag = 0;
//uint8_t sResetFlag = 0;
//uint32_t sBootRecvTimer = 0;

static uint8_t sCodeDecodeBuf[300];
boot_config_t g_boot_cfg;
static alink_message_head_t pAlinkMsg;
static alink_message_head_t uart8_recv_msg;
//static alink_status_t uart2_status;

uint8_t msg_channel= ANT_MCU_COM;

/*================================================================================*
 *                                 函数声明                                       *
 *================================================================================*/
static uint32_t boot_crc_calc( uint32_t* pWrdData, uint32_t nLen ,uint32_t crc);


uint8_t Get_Is_Update(void)
{
	return gIsUpdate;
}

/*================================================================================*
 *                                 函数原型                                       *
 *================================================================================*/
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
  uint32_t nPacklen = 0, i=0;
  uint32_t len, blocks, bytes;
  boot_config_t *pbootcfg;
  uint32_t crc32= 0;
  uint32_t nUsedItem;
  uint32_t nDecodeLen;
  
  uint8_t IsNeedAck = 0;
  uint8_t *pbyte = (uint8_t *)msg->payload64;
  uint8_t *pPacketbuf = (uint8_t *)pAlinkMsg.payload64;
  uint16_t *phalfword = (uint16_t *)pAlinkMsg.payload64;
  
  static uint8_t  bootcfg_packet_flag = 0; //第一包数据为配置区数据，未加密
	static uint32_t index = 0;
	static uint8_t last_seq = 0, curr_seq = 0;

  if(msg == NULL){
      return -1;
  }
  
  if((msg->msgid == MAV_SYSTEM_CMD_ERASE_APP_FLASH) || \
     (msg->msgid == MAV_SYSTEM_CMD_DOWNLOADING))
  {
    last_seq = curr_seq;
    curr_seq = msg->seq; 
  }
  
  switch(msg->msgid)
  {
    case MAV_SYSTEM_CMD_GET_TIMEOUT_RETRYTIMES:     
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
        if(pbyte[0]== 0xAA && pbyte[1]==0x55)
        {
          pPacketbuf[nPacklen++] = ACK_TYPE_SUCCESS;
        }else{
          pPacketbuf[nPacklen++] = ACK_TYPE_GENERAL_ERR;
        }
        IsNeedAck = 1;
      }break;
          
      
    case MAV_SYSTEM_CMD_FACTORY_RESET:                                                                   //0xD2      恢复出厂设置
      {
        pPacketbuf[nPacklen++] = ACK_TYPE_SUCCESS;
        IsNeedAck = 1;
      }break;
      

    case MAV_SYSTEM_CMD_GET_SN:                                                                         //0xD5  获取序列号
      {
        for(i=0; i<96; i++){
          pPacketbuf[i] = g_boot_cfg.sn[i];
        }
        nPacklen = 96;
        IsNeedAck = 1;
      }break;     
      
          
    case MAV_SYSTEM_CMD_SET_SN:                                                                         //0xD4  设置序列号
      {
        if(msg->len <= 96)
        {
          memset(&g_boot_cfg.sn[0],0,96);
          memcpy(&g_boot_cfg.sn[0],pbyte,msg->len);

          FlashErase_BootCfgSectors();
          FlashWrite_BootCfg(FLASH_BOOTINFO_ADDR, (uint8_t*)&g_boot_cfg, sizeof(boot_config_t));
          pPacketbuf[nPacklen++] = ACK_TYPE_SUCCESS;
        }else{
          pPacketbuf[nPacklen++] = ACK_TYPE_GENERAL_ERR;
        }
        IsNeedAck = 1;
      }break;         

          
    case MAV_SYSTEM_CMD_GET_APP_FLASH_SIZE:                                                             //0xD6      获取固件分区大小
      {
        uint32_t nFirmSize = FLASH_APP_SIZE;
        pPacketbuf[0] = nFirmSize;
        pPacketbuf[1] = nFirmSize>>8;
        pPacketbuf[2] = nFirmSize>>16;
        pPacketbuf[3] = nFirmSize>>24;
        nPacklen= 4;
        IsNeedAck = 1;
      }
      break;
      

    case MAV_SYSTEM_CMD_SET_HW_VERSION:                                                                     //0xDA       设置硬件版本
      {	
        if(msg->len == 4)
        {
          g_boot_cfg.hw_version= *(volatile uint32_t *)(&pbyte[0]);
          FlashErase_BootCfgSectors();
          FlashWrite_BootCfg(FLASH_BOOTINFO_ADDR, (uint8_t*)&g_boot_cfg, sizeof(boot_config_t));
          pPacketbuf[nPacklen++] = ACK_TYPE_SUCCESS;          
        }else{
          pPacketbuf[nPacklen++] = ACK_TYPE_GENERAL_ERR;
        }
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

      
    case MAV_SYSTEM_CMD_REQUEST_UPGRADE:                                                                  //0xD7      请求固件升级
      {
        g_boot.download_count= 0;
        g_boot.upgrade_allow_flag= 1;
        bootcfg_packet_flag= 1;
        index= 0;
        
        
        pPacketbuf[nPacklen++] = ACK_TYPE_SUCCESS;
        IsNeedAck = 1;
      }break;
          
          
    case MAV_SYSTEM_CMD_ERASE_APP_FLASH:                                                                        //0xD8      擦除固件分区
      {
        if(g_boot.upgrade_allow_flag)
        {
          g_boot.file_size= *(volatile uint32_t *)(&pbyte[0]);        
          if((g_boot.file_size != 0) && ((g_boot.file_size - BOOT_BLOCK_SIZE) < FLASH_APP_SIZE))
          {
#if 0            
            g_boot_cfg.magic = RC_UPDATE_FLAG;
            FlashErase_BootCfgSectors();
            FlashWrite_BootCfg(FLASH_BOOTINFO_ADDR, (uint8_t*)&g_boot_cfg, sizeof(boot_config_t));
            
            HAL_GPIO_WritePin(DBG_GPIO_Port, DBG_GPIO_Pin1, GPIO_PIN_SET);////////
            FlashErase_AppSectors();	
            HAL_GPIO_WritePin(DBG_GPIO_Port, DBG_GPIO_Pin1, GPIO_PIN_RESET);////////
            
#endif      
            FlashWrite_SetAppStartAddr();
            pPacketbuf[nPacklen++] = ACK_TYPE_SUCCESS;													

          } else{
            pPacketbuf[nPacklen++] = ACK_TYPE_GENERAL_ERR;
          }
          IsNeedAck = 1;	
        }        
      }
      break;
      
          
    case MAV_SYSTEM_CMD_DOWNLOADING:    //0xD9			下载固件数据
      {
        if(g_boot.upgrade_allow_flag)
        {
          /* 包序号与上一包相同则直接应答ACK */
          if(curr_seq == last_seq)
          {
            pPacketbuf[nPacklen++] = ACK_TYPE_SUCCESS;
            IsNeedAck = 1;
            break;
          }else if(curr_seq != (uint8_t)(last_seq + 1))
          {
            pPacketbuf[nPacklen++] = ACK_TYPE_GENERAL_ERR;
            IsNeedAck = 1;
            break;
          }

          /* 将接收到的数据拷贝到download_buf数组中 */
          if((index + msg->len) <= sizeof(g_boot.download_buf)){
            memcpy(&g_boot.download_buf[index], msg->payload64, msg->len);
            index += msg->len;
          }

          /* 第一个数据包为配置区数据，未加密 */
          if(bootcfg_packet_flag)
          {
            if(index == BOOT_BLOCK_SIZE)
            {
              index = 0;
              bootcfg_packet_flag = 0;
              pbootcfg = (boot_config_t *)g_boot.download_buf;
              
							/* 升级包中包含了适用的硬件版本范围信息，相符才能进行升级 */
              if((g_boot_cfg.hw_version >= pbootcfg->min_hw_version) \
                && (g_boot_cfg.hw_version <= pbootcfg->max_hw_version))
              {
#if 1           
                /* 验证硬件版本相符才擦除Flash */
                g_boot_cfg.magic = RC_UPDATE_FLAG;
                FlashErase_BootCfgSectors();
                FlashWrite_BootCfg(FLASH_BOOTINFO_ADDR, (uint8_t*)&g_boot_cfg, sizeof(boot_config_t));
								
								HAL_GPIO_WritePin(DBG_GPIO_Port, DBG_GPIO_Pin1, GPIO_PIN_SET);////////
                FlashErase_AppSectors();
								HAL_GPIO_WritePin(DBG_GPIO_Port, DBG_GPIO_Pin1, GPIO_PIN_RESET);////////
								
#endif                           
                g_boot_cfg.app_size = pbootcfg->app_size;
                g_boot_cfg.app_crc32 = pbootcfg->app_crc32;
                g_boot_cfg.app_version = pbootcfg->app_version;
                pPacketbuf[nPacklen++] = ACK_TYPE_SUCCESS;
                IsNeedAck = 1;              
              }
              else
              {
                g_boot.upgrade_allow_flag= 0;
                pPacketbuf[nPacklen++] = ACK_TYPE_FILE_MATCH_ERR;
                IsNeedAck = 1;
              }
            }
          }
          else
          {            
            /* 第二个数据包开始为实际的固件内容 */
            if(g_boot.download_count > g_boot_cfg.app_size)
            {
              pPacketbuf[nPacklen++] = ACK_TYPE_GENERAL_ERR;
              IsNeedAck = 1;
              break;
            }
            
            /* 最后一包，将剩余空间填充为0xFF */
            if(index < BOOT_BLOCK_SIZE){
              memset(&g_boot.download_buf[index], 0xff, BOOT_BLOCK_SIZE-index);
            }
#if 0            
            /* 解密需要16的整数倍数据 */
            nUsedItem= index;
            if((nUsedItem & 0x0f) != 0)
            {
              nUsedItem = (nUsedItem&0xFFF0)+16;
            }
  
            for(i=0; i<nUsedItem; i+=DATA_BLOCK_SIZE)
            {
              if(AES_SUCCESS != crypt_aes_decrypt(AES_ECB, g_boot.download_buf+i, DATA_BLOCK_SIZE, \
                (uint8_t *)g_key_buf, sCodeDecodeBuf+i, &nDecodeLen))
              {
                g_boot.upgrade_allow_flag= 0;
                pPacketbuf[nPacklen++] = ACK_TYPE_GENERAL_ERR;
                IsNeedAck = 1;
                break;
              }
            }
            
            /* 将解密后的数据写入Flash */
            if (FlashWrite(FLASH_APPLICATION_ADDR + g_boot.download_count ,
                sCodeDecodeBuf, index ) != 0)
#else
            /* 将收到的数据写入Flash */
            if (FlashWrite_AppWords(FLASH_APPLICATION_ADDR + g_boot.download_count ,g_boot.download_buf, index ) < 0)
#endif
            {
              pPacketbuf[nPacklen++] = ACK_TYPE_GENERAL_ERR;
              IsNeedAck = 1;
              break;
            }

            g_boot.download_count += index;  
            index = 0;	//处理完一块数据后索引值归0
            pPacketbuf[nPacklen++] = ACK_TYPE_SUCCESS;
            IsNeedAck = 1;           
          }
        }
        else{
          pPacketbuf[nPacklen++] = ACK_TYPE_GENERAL_ERR;
          IsNeedAck = 1;
        } 
        

      }
      break;              
    
     
  case MAV_SYSTEM_CMD_CRC_CHECK:        //0XDC      校验固件数据
    {       
      if(g_boot.upgrade_allow_flag)
      {
        FlashWrite_ChkAppRemainWords();   // 升级结束，将剩余未32byte对齐的数据写入到flash中。
        
        /* 校验已写进Flash的app CRC32值 */
        len = 0;
        blocks = g_boot_cfg.app_size / sizeof(g_crc32_buf);
        bytes = g_boot_cfg.app_size % sizeof(g_crc32_buf);
        for(i=0; i<blocks; i++)
        {
          FlashRead(FLASH_APPLICATION_ADDR + len, g_crc32_buf, sizeof(g_crc32_buf));
          len += sizeof(g_crc32_buf);
          crc32 = boot_crc_calc((uint32_t *)g_crc32_buf, sizeof(g_crc32_buf)>>2,crc32);
        }
        if(bytes > 0)
        {
          FlashRead(FLASH_APPLICATION_ADDR + len, g_crc32_buf, bytes);
          if((bytes % 4) != 0){
            memset(&g_crc32_buf[bytes], 0xFF, 3); //最后不足4字节对齐时用0xFF补齐
          }
          crc32 = boot_crc_calc((uint32_t *)g_crc32_buf, ((bytes+3)>>2),crc32);
        }

        /* 升级完成，修改bootcfg配置区信息 */
        if(crc32 == g_boot_cfg.app_crc32){
          g_boot_cfg.magic = MAGIC_VALUE;
          FlashErase_BootCfgSectors();
          FlashWrite_BootCfg(FLASH_BOOTINFO_ADDR, (uint8_t*)&g_boot_cfg, sizeof(boot_config_t));
          pPacketbuf[nPacklen++] = ACK_TYPE_SUCCESS;//CRC32校验成功，返回ACK
        }else{
          pPacketbuf[nPacklen++] = ACK_TYPE_GENERAL_ERR;
        }
      }else{
        pPacketbuf[nPacklen++] = ACK_TYPE_GENERAL_ERR; 
      }
      IsNeedAck = 1;        
    }
    break;
          
          
  case MAV_SYSTEM_CMD_APP_GO:
    {	
      gLoderResetFlag = (RC_UPDATE_FLAG | 0xFF);
      gGotoLoaderFlag = 0;     
      pPacketbuf[nPacklen++] = ACK_TYPE_SUCCESS;
      IsNeedAck = 1;
    }break;
            
      
  default:
    pPacketbuf[nPacklen++] = ACK_TYPE_GENERAL_ERR;
    IsNeedAck = 1;
    break;
  }
  
  if(IsNeedAck)
  {
    pAlinkMsg.sourceid = DEV_BASESTATION;
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
			default:
				if(Msgid == 0x98)
				{
					//HAL_UART_Transmit_IT(&com_obj[COM4].uart,&pByte[0],9);
          //wifi_run_flag= 1;
				}
				if(( Msgid >=0xD0 && Msgid <= 0xFF )|| Msgid== 0x03)
				{
						/* 基站升级处理 */
						WifiUpgrade(chan,pMsg);
				}
			break;
    }
    return 0;
}


/*================================================================================*
 *                                 函数原型                                       *
 *================================================================================*/
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
  
//  if(queue_size(&com_obj[WIFI_COM].rx_queue) != 0)
//	{
//		if(packet_receive(&com_obj[WIFI_COM], &uart8_recv_msg, 0) > 0)
//		{
//      msg_channel= WIFI_COM;
//			switch(uart8_recv_msg.destid)
//			{
//				case DEV_BASESTATION:
//				{
//					DevWIFI_AlinkMsgParse(0,&uart8_recv_msg);
//				}
//				break;
//				default:
//					break;
//			}
//		}
//	}
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
	update_comm_running();
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


/******************************************************************************
 * 函数功能：计算CRC校验码
 * 输入：*pWrdData      ---指向待计算的数据，注意是u32数据类型。
 *       nLen           ---待计算的数据个数。
 *       crc            ---crc初始值。
 * 输出：返回crc计算结果。
 * 备注：无
 *****************************************************************************/
static uint32_t boot_crc_calc( uint32_t* pWrdData, uint32_t nLen ,uint32_t crc)
{
	uint32_t nData, i, j;

	if (NULL == pWrdData || nLen == 0)
	{
		return crc;
	}

	for (i=0; i<nLen; i++)
	{
		nData = pWrdData[i];

		for (j=0; j<32; j++)
		{
			if ((crc^nData) & 0x80000000){
				crc = 0x04C11DB7^(crc<<1);
			}else{
				crc <<= 1;
			}
			nData <<= 1;
		}
	}

	return crc;
}



/******************************************************************************
 * 函数功能：检查应用程序合法性函数
 * 输入：无
 * 输出：应用程序可用返回1，应用程序不可用返回-1
 * 备注：无
 *****************************************************************************/
int32_t CheckAppCode(void)
{
  uint32_t i, len, blocks, bytes;
	uint32_t crc32 = 0;

	if(g_boot_cfg.magic == RC_UPDATE_FLAG)
  {
		return -1; //强制进入Bootloader
	}

	/* 判断app是否已经写入到Flash */
	if(*(volatile uint32_t *)FLASH_APPLICATION_ADDR == 0xFFFFFFFF)
  {
		g_boot_cfg.magic = RC_UPDATE_FLAG;
		return -2;
	}

	/* 判断Flash中的app CRC32校验值 */
	len = 0;
	blocks = g_boot_cfg.app_size / sizeof(g_crc32_buf);
	bytes = g_boot_cfg.app_size % sizeof(g_crc32_buf);
  
	for(i=0; i<blocks; i++)
  {
		FlashRead(FLASH_APPLICATION_ADDR + len, g_crc32_buf, sizeof(g_crc32_buf));
    len += sizeof(g_crc32_buf);
		crc32 = boot_crc_calc((uint32_t *)g_crc32_buf, sizeof(g_crc32_buf)>>2,crc32);
	}
  
	if(bytes > 0)
  {
		FlashRead(FLASH_APPLICATION_ADDR + len, g_crc32_buf, bytes);
		if((bytes % 4) != 0)
    {
			memset(&g_crc32_buf[bytes], 0xFF, 3); //最后不足4字节对齐时用0xFF补齐
		}
		crc32 = boot_crc_calc((uint32_t *)g_crc32_buf, ((bytes+3)>>2),crc32);
	}
  
	if(crc32 != g_boot_cfg.app_crc32)
  {
		g_boot_cfg.magic = RC_UPDATE_FLAG;
		return -4;
	}

	/* Application is valid, go applicatin now! */
	return 1;
  
}























