/**************************************************************************************
 *
 * 文件描述：RTK基站精确位置设置接口
 * 创建日期：
 *
 * 备注：
 *
 **************************************************************************************
 */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __RTK_POS_SET_H
#define __RTK_POS_SET_H

/* Includes ------------------------------------------------------------------*/
#include "stm32h7xx_hal.h"
#include "includes.h"
#include "fun_opt.h"

/* Exported_Macros -----------------------------------------------------------*/
#define MAGIC_POS_VALID           0x11223344
#define MAX_POS_ERROR_M           10.00

/* Exported_Types ------------------------------------------------------------*/
#pragma pack(1)
/* 基站精确位置信息标准结构体 --------------------- */
typedef struct{
  double lat;     // 纬度, deg
	double lon;     // 经度, deg
	double hgh;     // 海拔，m
}Pos_t;

/* 基站位置设置消息的数据段结构体 ----------------- */
typedef struct{
  uint8_t type;       // type= 0x01
  uint8_t len;        // len = 0x18 
  union{
    uint8_t bytes[sizeof(Pos_t)];
    Pos_t set_pos;
  }; 
}msg_base_pos_set_t;

/* flash中保存基站位置信息的结构体 ---------------- */
typedef struct{
  uint32_t magic;   // 0x11223344
  uint32_t crc16;   // 高16bit填充为0
  Pos_t    pos;
}SaveDat_t;

/* 基站精确位置设置相关的参数 --------------------- */
typedef struct{
  Pos_t   set_pos;    // 外部设定的位置信息。
  Pos_t   cur_pos;    // RTK产生的位置信息。
  uint8_t valid;      // 0: 位置无效；1: 位置有效。指外部设置位置有无效。
  uint8_t rtk_updat;  // 0: 未更新；1：RTK数据有更新。
  uint8_t stat;       // 0: 未设置；1：已设置。
  uint8_t set_updat;  // 0：无更新；1：位置设置有更新。
}PosSet_obj;







#pragma pack()


/* Exported_Variables --------------------------------------------------------*/
extern PosSet_obj PosSetObj;
extern uint8_t del_pos_set_flag;

/* Exported_Functions --------------------------------------------------------*/
int32_t base_set_msg_parse(uint8_t chan, alink_message_head_t *pMsg);
void base_pos_set(void);
























#endif
