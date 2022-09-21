/**************************************************************************************
 *
 * 文件描述：RTK基站精确位置设置接口
 * 创建日期：
 *
 * 备注：
 *
 **************************************************************************************
 */

/* Includes ------------------------------------------------------------------*/
#include "rtk_pos_set.h"
#include "stdio.h"
#include "checksum.h"
#include "bsp_flash.h"
#include "string.h"

/* Private_Defines -----------------------------------------------------------*/
#define sBasePosSetting     "Mode base %.11f %.11f %.4f \r\n"
#define sBaseSaveCfg        "saveconfig\r\n"


/* Private_TypesDefinitions --------------------------------------------------*/



/* Private_Variables ---------------------------------------------------------*/
PosSet_obj PosSetObj={
  .valid= 0,
  .stat= 0,
  .set_updat= 0
};

uint8_t del_pos_set_flag= 0;

/* FunctionPrototypes --------------------------------------------------------*/
int32_t base_pos_check(void);
int32_t read_base_pos_from_flash(void);
int32_t save_base_pos_to_flash(Pos_t *pos);

/* Functions -----------------------------------------------------------------*/

/******************************************************************************
 * 功能：基站精确位置设置
 * 输入：无          
 * 返回：
 * 说明：
 *
 *****************************************************************************/
void base_pos_set(void)
{
	static uint8_t step= 0;
  static uint32_t tim=0;
  uint8_t buf[200],len;
  
  switch(step)
  {
  case 0:
    if(1== base_pos_check())
    {
      step=1;
      BuzzOn_time(0,0,1,100,100);
    }
    break;    
    
  case 1:
    len= sprintf((void*)buf, sBasePosSetting, PosSetObj.set_pos.lat, PosSetObj.set_pos.lon, PosSetObj.set_pos.hgh);
    serial_send(&com_obj[RTK_COM1], buf, len);
    tim= GET_CURTICK;
    step= 2;
    break;
  
  case 2:
    if(GET_PASTTICK(tim)>1000)
    {
      len= sprintf((void*)buf, sBaseSaveCfg);
      serial_send(&com_obj[RTK_COM1], buf, len);
      PosSetObj.stat= 1;
      step= 3;
    }
    break;
  
  default:

    break;
  }
  
  if(PosSetObj.set_updat)
  {
    PosSetObj.valid= 1;
    PosSetObj.set_updat= 0 ;
    PosSetObj.stat= 0;
    step= 0;
  }
  
  if(del_pos_set_flag)
  {
    /* 删除基站位置设置信息 */
    FlashErase_Cfg1Sectors();
    PosSetObj.valid= 0;
    PosSetObj.stat= 0;
    step= 0;
    del_pos_set_flag= 0;
  }
  
}


/******************************************************************************
 * 功能：基站精确位置检查
 * 输入：无          
 * 返回：0：无效；1：位置有效；
 * 说明：
 *
 *****************************************************************************/
#define M_PER_DEG                   (double)111120.0       // m/deg
#define MAX_ANGLE_ERROR_DEG         (double)(MAX_POS_ERROR_M/M_PER_DEG)

int32_t base_pos_check(void)
{
  static uint8_t flag_init= 0;
  
  if(flag_init == 0)
  {
    read_base_pos_from_flash();
    flag_init= 1;
  }    
  
  if(PosSetObj.valid)
  {    
    /* 检查经度偏差 */
    if(MAX_ANGLE_ERROR_DEG < (PosSetObj.set_pos.lat - PosSetObj.cur_pos.lat)) return 0;
    if(-MAX_ANGLE_ERROR_DEG > (PosSetObj.set_pos.lat - PosSetObj.cur_pos.lat)) return 0;
    
    /* 检查纬度偏差 */
    if(MAX_ANGLE_ERROR_DEG < (PosSetObj.set_pos.lon - PosSetObj.cur_pos.lon)) return 0;
    if(-MAX_ANGLE_ERROR_DEG > (PosSetObj.set_pos.lon - PosSetObj.cur_pos.lon)) return 0;
    
    /* 检查高度偏差 */
    if(MAX_POS_ERROR_M < (PosSetObj.set_pos.hgh - PosSetObj.cur_pos.hgh)) return 0;
    if(-MAX_POS_ERROR_M > (PosSetObj.set_pos.hgh - PosSetObj.cur_pos.hgh)) return 0;  
  }else{
    return 0;
  }
  
  return 1;
}


/******************************************************************************
 * 功能：将基站精确位置信息保存到flash中
 * 输入：无          
 * 返回：0：无效；1：保存成功。
 * 说明：
 *
 *****************************************************************************/
int32_t save_base_pos_to_flash(Pos_t *pos)
{
  SaveDat_t save_dat;
  uint8_t *pDat= (void*)&save_dat.pos;
  uint16_t len= sizeof(Pos_t);
  
  save_dat.magic = MAGIC_POS_VALID;
  memcpy((void*)&save_dat.pos, (void*)pos, sizeof(Pos_t));
  save_dat.crc16= crc_calculate(pDat, len);
   
  FlashErase_Cfg1Sectors();
  FlashWrite_CfgInfo(FLASH_CFGINFO_ADDR1, (uint8_t *)&save_dat, sizeof(SaveDat_t));
  return 1;
}


/******************************************************************************
 * 功能：从flash中读取基站精确位置信息
 * 输入：无          
 * 返回：0：无效；1：读取成功。
 * 说明：
 *
 *****************************************************************************/
int32_t read_base_pos_from_flash(void)
{
  SaveDat_t save_dat;
  uint8_t *pDat= (void*)&save_dat.pos;
  uint16_t len= sizeof(Pos_t);
  
  PosSetObj.valid= 0;
  
  FlashRead(FLASH_CFGINFO_ADDR1, (uint8_t*)&save_dat, sizeof(SaveDat_t));
  if(save_dat.magic != MAGIC_POS_VALID){
    return 0;
  }
  if(save_dat.crc16 != crc_calculate(pDat, len)){
    return 0;
  }
  memcpy((void*)&PosSetObj.set_pos, (void*)&save_dat.pos, sizeof(Pos_t));
  PosSetObj.valid= 1;
  
  return 1;
}




/******************************************************************************
 * 功能：解析基站设置消息
 * 输入：无         
 * 返回：0：无效；1：成功。
 * 说明：
 *
 *****************************************************************************/
int32_t base_set_msg_parse(uint8_t chan, alink_message_head_t *pMsg)
{
  uint8_t *pData;
  uint8_t nPacketLen=0;
  uint8_t nAppSetType;
  uint8_t nAppDataLen;
  uint8_t *packetBuf;
  uint8_t IsNeedAck = 0;
  alink_message_head_t Alink_msg;
  uint8_t nMsgId = pMsg->msgid;

  if(nMsgId != ALINK_MSG_ID_RTK_SETTING)
  {
      return 0;
  }

  pData = (uint8_t *)pMsg->payload64;
  nAppSetType = pData[0];
  nAppDataLen = pData[1];
  pData = pData + 2;

  packetBuf = (uint8_t *)Alink_msg.payload64;
  memset(packetBuf, 0 , 24);

  switch(nAppSetType)
  {
    case 1: //基站精确位置设置
    {
      if (nAppDataLen < sizeof(Pos_t))
      {
        return 0;
      }     
      memcpy((void*)&PosSetObj.set_pos, pData, sizeof(Pos_t));
      save_base_pos_to_flash(&PosSetObj.set_pos);
      PosSetObj.set_updat= 1;
      
      nPacketLen=0;
      packetBuf[nPacketLen++] = nAppSetType;
      packetBuf[nPacketLen++] = 0;
      packetBuf[nPacketLen++] = 0;  // 0:ack; 1:nack;
      packetBuf[1] = nPacketLen - 2;
      IsNeedAck = 1;

      BuzzOn_time(0,0,2,100,100);
    }break;
    
    default:
      
      break;
  }
  if(IsNeedAck)
	{
		Alink_msg.sourceid = DEV_BASESTATION;
		Alink_msg.destid = pMsg->sourceid;
		Alink_msg.msgid = nMsgId;
		Alink_msg.len = nPacketLen;
		AlinkPacket_Reply(chan, &Alink_msg);
	}

	return 1;
  

}

/*********************************** END OF FILE *************************************/
