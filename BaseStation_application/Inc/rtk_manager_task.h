/**
  ******************************************************************************
  * File Name          : 
  * Description        : 
  *
  ******************************************************************************
  */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __RTK_MANAGER_TASK_H__
#define __RTK_MANAGER_TASK_H__

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "sys_cfg.h"

#define RTK_MSGID_BESTPOS   42
#define RTK_MSGID_BESTVEL   99
#define RTK_MSGID_BESTXYZ   241
#define RTK_MSGID_HEADING   971
#define RTK_MSGID_HEADING2  1335

typedef union 
{
	unsigned char temp[4];
	int data;
}uInt_t;

typedef union 
{
	unsigned char temp[4];
	float data;
}uFloat_t;

typedef union 
{
	unsigned char temp[8];
	double data;
}uDouble_t;

typedef enum{
	eMsgIdx_Sync1= 0,
	eMsgIdx_Sync2= 1,
	eMsgIdx_Sync3= 2,
	eMsgIdx_HeadLen= 3,
	eMsgIdx_MsgID_Lo= 4,
	eMsgIdx_MsgID_Hi= 5,
	eMsgIdx_MsgLen_Lo= 8,
	eMsgIdx_MsgLen_Hi= 9,

}rtkmsg_idx_e;

typedef struct{
	uint8_t headlen;
	uint8_t msgid_lo;
	uint8_t msgid_hi;
	uint8_t msglen_lo;
	uint8_t msglen_hi;
	uint8_t crc[4];
	uint16_t msglen;
	uint16_t msgid;
	uint16_t crc_idx;			// CRC��ʼλ��
	uint32_t crc32;
}rtkmsg_info_t;

#pragma pack(1)
typedef struct{
  int32_t  lat;         // γ��, ��λ10e-7deg
  int32_t  lon;         // ����, ��λ10e-7deg
  int32_t  hgh;         // ���Σ���λ10e-3m
  uint8_t  pos_type;    // λ������
  uint8_t  pos_stat;    // λ�ý�״̬
  uint8_t  vel_type;    // �ٶ�����
  uint8_t  vel_stat;    // �ٶȽ�״̬
  int16_t  vert_spd;    // ��ֱ�ٶȣ�0.01m/s
  int16_t  hor_spd;     // ˮƽ�ٶȣ�0.01m/s
  int16_t  rtk_gnd;     // ��������˶�����0.1deg��˳ʱ��Ϊ0-360.0deg
  int16_t  reserve;     // ����
}rtk_pos_vel_t;
#pragma pack()

extern uint8_t gRtkQuality;




void RTK_Uninit(void);
void init_RTK(void);
uint8_t init_Hexinxintong(void);
uint8_t GetIsInitRTK(void);
uint8_t rtk_comm_running();	 
	 
void AddDealRTKTask(void);
int32_t DealRTKTaskInit(void);
void DealRTKTask(void);
int32_t DealRTKTaskUninit(void);

double uint8_to_double(const uint8_t str[]);
uint8_t get_rtk_star_number(void);
void rtk_state_msg_send(void);	 



#ifdef __cplusplus
}
#endif
#endif 


/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/


