/**************************************************************************************
 *
 * �ļ�������ͼ���������
 * �������ڣ�
 *
 * ��ע��
 *
 **************************************************************************************
 */

/* Includes ------------------------------------------------------------------*/
#include "includes.h"

/* Private_Defines -----------------------------------------------------------*/



/* Private_TypesDefinitions --------------------------------------------------*/



/* Private_Variables ---------------------------------------------------------*/



/* FunctionPrototypes --------------------------------------------------------*/
void match_key_process(void);
void send_match_msg(void);
void match_led_ctrl(void);



/* Functions -----------------------------------------------------------------*/

/******************************************************************************
 * ���ܣ�ͼ���������
 * ���룺��          
 * ���أ�
 * ˵����
 *
 *****************************************************************************/
void imagelink_task(void)
{
	match_key_process();
	
	match_led_ctrl();
	
}



/******************************************************************************
 * ���ܣ���Ƶ����⼰��������
 * ���룺��          
 * ���أ�
 * ˵����
 *
 *****************************************************************************/
void match_key_process(void)
{
#define KEY_LONG_PRESS_TIM				3000
#define KEY_SHORT_PRESS_TIM				200	
	
	static uint32_t runtim= 0;
	static uint32_t press_start_tim= 0;
	static uint32_t key_stat_last= 0;
	static uint8_t  key_val= 0;		// 0����Ч��1���̰���2��������3���ȴ�����
	static uint32_t msg_gap_tim= 0;
	static uint16_t msg_cnt= 0;

	if (GET_PASTTICK(runtim) < 10) return;
	runtim= GET_CURTICK;

	/* ������� ------------------------------------------*/
	uint8_t key_stat= !READ_MATCH_KEY;
	
	if (key_stat)	// ����
	{
		if (!key_stat_last) {
			press_start_tim= GET_CURTICK;	// �հ���
		} 
		else if (key_val == 0 && GET_PASTTICK(press_start_tim) > KEY_LONG_PRESS_TIM) {
			key_val= 2;	// ����
		}
	}
	else	// ����
	{
		if (!key_stat_last || key_val) {
			key_val= 0;
		}
		else if (GET_PASTTICK(press_start_tim) > KEY_SHORT_PRESS_TIM) {
			key_val= 1;	// �̰�
		}
		press_start_tim= GET_CURTICK;
	}
	key_stat_last= key_stat;
	
	/* �������� ------------------------------------------*/
	if (key_val == 1)
	{
		/* �����̰�����ͼ��������Ƶģʽ */
		key_val= 0;
		sys_info.flag.videotran_match= 1;
		sys_info.flag.videotran_mode= 0;		// 0����ģʽ�� 1����ģʽ
		msg_cnt= 0;
	}
	else if (key_val == 2)
	{
		/* ����������;������ */
		key_val= 3;
	}
	
	/* ���Ͷ�Ƶ��Ϣ --------------------------------------*/	
	if (sys_info.flag.videotran_match && GET_PASTTICK(msg_gap_tim) >= 1000)
	{
		msg_gap_tim= GET_CURTICK;
		
		send_match_msg();	
		
		/* ��ʱ�˳���Ƶģʽ */
		if (++msg_cnt >= 15) {
			msg_cnt= 0;
			sys_info.flag.videotran_match= 0;
		}
		
	}
}


/******************************************************************************
 * ���ܣ����Ͷ�Ƶ��Ϣ
 * ���룺��          
 * ���أ�
 * ˵����
 *
 *****************************************************************************/
void send_match_msg(void)
{
	uint8_t msg_buf[30];
	alink_message_head_t* alink_msg= (void*)msg_buf;
	uint8_t *pBuf = (uint8_t *)alink_msg->payload64;
	
	alink_msg->msgid= ALINK_MSG_ID_SYSTEM_BINDING;
	pBuf[0]= (sys_info.flag.videotran_mode)? 1:0;
	uint16_t len= 1;

	alink_finalize_message(alink_msg, DEV_DSP_STATION, DEV_BASESTATION, len, ALINK_MSG_ID_SYSTEM_BINDING_CRC);
	packet_transmit(&com_obj[ANT_MCU_COM],alink_msg);   // ͨ��ͼ�����ɿ�  
}


/******************************************************************************
 * ���ܣ���ƵLED����
 * ���룺��          
 * ���أ�
 * ˵����
 *
 *****************************************************************************/
void match_led_ctrl(void)
{
	static uint8_t  flag_init= 0;
	
	if (!flag_init)
	{
		sys_info.match_led_on_tim= 0;
		sys_info.match_led_off_tim= 2000;
		sys_info.match_led_tim_period= 2000;
		
		match_led_tim_init();
		flag_init= 1;
	}
		
}




/*********************************** END OF FILE *************************************/
