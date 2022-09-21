/**************************************************************************************
 *
 * �ļ�������RTK��վ��ȷλ�����ýӿ�
 * �������ڣ�
 *
 * ��ע��
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
/* ��վ��ȷλ����Ϣ��׼�ṹ�� --------------------- */
typedef struct{
  double lat;     // γ��, deg
	double lon;     // ����, deg
	double hgh;     // ���Σ�m
}Pos_t;

/* ��վλ��������Ϣ�����ݶνṹ�� ----------------- */
typedef struct{
  uint8_t type;       // type= 0x01
  uint8_t len;        // len = 0x18 
  union{
    uint8_t bytes[sizeof(Pos_t)];
    Pos_t set_pos;
  }; 
}msg_base_pos_set_t;

/* flash�б����վλ����Ϣ�Ľṹ�� ---------------- */
typedef struct{
  uint32_t magic;   // 0x11223344
  uint32_t crc16;   // ��16bit���Ϊ0
  Pos_t    pos;
}SaveDat_t;

/* ��վ��ȷλ��������صĲ��� --------------------- */
typedef struct{
  Pos_t   set_pos;    // �ⲿ�趨��λ����Ϣ��
  Pos_t   cur_pos;    // RTK������λ����Ϣ��
  uint8_t valid;      // 0: λ����Ч��1: λ����Ч��ָ�ⲿ����λ������Ч��
  uint8_t rtk_updat;  // 0: δ���£�1��RTK�����и��¡�
  uint8_t stat;       // 0: δ���ã�1�������á�
  uint8_t set_updat;  // 0���޸��£�1��λ�������и��¡�
}PosSet_obj;







#pragma pack()


/* Exported_Variables --------------------------------------------------------*/
extern PosSet_obj PosSetObj;
extern uint8_t del_pos_set_flag;

/* Exported_Functions --------------------------------------------------------*/
int32_t base_set_msg_parse(uint8_t chan, alink_message_head_t *pMsg);
void base_pos_set(void);
























#endif
