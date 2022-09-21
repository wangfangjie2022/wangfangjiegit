/**************************************************************************************
 *
 * �ļ�������
 * �������ڣ�
 *
 * ��ע��
 *
 **************************************************************************************
 */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __SYS_UTIL_H
#define __SYS_UTIL_H

/* Includes ------------------------------------------------------------------*/
#include "stm32h7xx_hal.h"

/* Exported_Macros -----------------------------------------------------------*/



/* Exported_Types ------------------------------------------------------------*/
typedef struct{
	uint32_t videotran_match : 1;			// ͼ����Ƶ��־��0���Ƕ�Ƶ��1����Ƶ�У�
	uint32_t videotran_mode : 1;			// ͼ��ģʽ��0����ģʽ��1����ģʽ��
	uint32_t videotran_con_ok : 1;		// ͼ������״̬��0��δ���ӣ�1�������ӣ�
	uint32_t videotran_stat_update : 1;	// ͼ��״̬���±�־
}sys_flag_t;



typedef struct{
	sys_flag_t	flag;
	uint16_t match_led_on_tim;			// ͼ����ƵLED����ʱ������λms
	uint16_t match_led_off_tim;			// ͼ����ƵLED�ر�ʱ������λms
	uint16_t match_led_tim_period;	// ͼ����ƵLED��˸���ڣ���λms
}sys_info_t;

extern sys_info_t sys_info;
/* Exported_Variables --------------------------------------------------------*/



/* Exported_Functions --------------------------------------------------------*/


























#endif
