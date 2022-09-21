/**************************************************************************************
 *
 * �ļ����������RS485ͨѶ��ؽӿ�
 * �������ڣ�
 *
 * ��ע��
 *
 **************************************************************************************
 */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __BSP_BATT_H
#define __BSP_BATT_H

/* Includes ------------------------------------------------------------------*/
#include "stm32h7xx_hal.h"
#include "alink_types.h"
#include "xstar_2_0.h"

/* Exported_Macros -----------------------------------------------------------*/
#define ALINK_CHAN_BAT  				ALINK_COMM_1


/* RS485���������豸��̬��Ϣ�������ԣ��;�̬��Ϣ�����Σ����� */
#define RS485_CMD_GET_DEV_DYNAMIC_INFO						0xC9
#define RS485_CMD_GET_DEV_STATIC_INFO						  0xCA


/* RS485����ͨѶ��ʱʱ�� --------------------------*/
#define RS485_TIMOUT_ms				    200

/*-------------------------------------------------*/
/* RS485�����豸�Ŷ��� ----------------------------*/
/* ���� */
#define RS485_DEV_SN_MAIN					0	

/* ����豸 */
#define RS485_DEV_SN_BAT_1			  1
#define RS485_DEV_SN_BAT_2				2
#define RS485_DEV_SN_BAT_3			  3
#define RS485_DEV_SN_BAT_4				4

#define BAT_DEV_SN_START					1
#define BAT_DEV_TOTAL_NUM					4
#define BAT_DEV_SN_MAX						(BAT_DEV_SN_START + BAT_DEV_TOTAL_NUM -1)

/* ������� */
#define RS485_DEV_SN_KEY_LED			10


/* ���豸������ ------------------------------------*/
/* ����豸������ */
#define SUB_CMD_GET_BAT_DATA			0

/* ������������� */
#define SUB_CMD_GET_KEY_DATA			0

/* ����豸������� */
#define BAT_DEV_SN_MASK						0x000F



/* Exported_Types ------------------------------------------------------------*/
typedef enum{
	eDevSN_Master		=	0,
	eDevSN_Batt_1		= 1,
	eDevSN_Batt_2,
	eDevSN_Batt_3,
	eDevSN_Batt_4,
	eDevSN_KeyLed		= 10,
	eDevSN_Idle			= 255,
}rs485_dev_num_e;


typedef struct{
	uint8_t  cmd;
	uint8_t  dev_num;
	uint8_t  sub_cmd;	
}rs485_req_data_t;


typedef struct{
	alink_muti_bat_data_t batt_dat;	
	uint32_t cnt_bat_msg;									// ͳ�����յ��ĵ����Ϣ��
	uint8_t  cnt_timout;									// ͨѶ��ʱ������
	uint8_t  flg_dat_update;							// ��������и���
	uint8_t  flg_bat_valid;								// �����Ч��־������5��δ�յ��������
}batt_info_t;





/* Exported_Variables --------------------------------------------------------*/
extern uint8_t bat_info_updated;
extern batt_info_t batt_info[];

/* Exported_Functions --------------------------------------------------------*/
void batt_msg_parse(alink_message_head_t *pMsg);
void batt_wakeup(uint8_t flag);
void batt_sleep(void);
uint8_t is_timout_batt_msg(void);
uint8_t get_bat_percent(void);
void rs485_comm_task(void);
























#endif
