/**
  ******************************************************************************
  * File Name          : power.c
  * Description        : 
**/
/* Includes ------------------------------------------------------------------*/
#include "power_task.h"
#include "bat_manager_task.h"
#include "Sys_cfg.h"
#include "main.h"
#include "includes.h"

/*================================================================================*
 *                                   �궨��                                       *
 *================================================================================*/

/*================================================================================*
 *                                ȫ�ֱ�������                                    *
 *================================================================================*/
uint8_t nPowerTaskID;

/*================================================================================*
 *                               �ֲ���������                                     *
 *================================================================================*/

uint8_t  gKey_Pressed_Flag = 0;//�����Ƿ��а���
uint8_t  gKey_Long_Pressed_Flag = 0;//�����Ƿ��а���
uint8_t  gKey_Type = 0;//1:�������ػ���2���ػ��̰�
uint32_t gKey_Pressed_Time = 0;
uint32_t gLong_Press_Lose_Time = 0;//�����ɿ�ʱ�䣬���ڽ��ż���������⵽�̰���bug

const uint16_t PRESS_DELAY = 500;
static uint8_t sPowerState= ENUM_POWER_OFF;

#define LONG_PRESS_POWER_ON_TIME 1000

/*================================================================================*
 *                                 ��������                                       *
 *================================================================================*/

/*================================================================================*
 *                                 ����ԭ��                                       *
 *================================================================================*/
/*================================================================================*
 * ��������:    void gTogglePowerSate()
 * ��������:    �ı俪�ػ�״̬
 * ��    ��:
 * �������:
 * �������:
 * �� �� ֵ:
 * ����˵��:
 * ������ʷ:
 *
 *================================================================================*/
void gTogglePowerSate(void)
{
	if(ENUM_POWER_ON == sPowerState)
		 sPowerState = ENUM_POWER_OFF;
	else if(ENUM_POWER_OFF == sPowerState)
		 sPowerState = ENUM_POWER_ON;
}

/*================================================================================*
 * ��������:    uint8_t gGetCurPowerState()
 * ��������:    ��ȡ��ǰ���ػ�״̬
 * ��    ��:
 * �������:
 * �������:
 * �� �� ֵ:
 * ����˵��:
 * ������ʷ:
 *
 *================================================================================*/
uint8_t gGetCurPowerState(void)
{
	return sPowerState;
}
/*================================================================================*
 * ��������:    void RF_Init(void)
 * ��������:    ��ʼ����Ƶģ���Դ
 * ��    ��:
 * �������:
 * �������:
 * �� �� ֵ:
 * ����˵��:
 * ������ʷ:
 *
 *================================================================================*/
void RF_Init(void)
{
	RF_POW2_OUT_ON();
}
/*================================================================================*
 * ��������:    void RF_DeInit(void)
 * ��������:    �ر���Ƶģ���Դ
 * ��    ��:
 * �������:
 * �������:
 * �� �� ֵ:
 * ����˵��:
 * ������ʷ:
 *
 *================================================================================*/
void RF_DeInit(void)
{
	RF_POW2_OUT_OFF();
} 


/*================================================================================*
 * ��������:    uint32_t Get_Key(void)
 * ��������:    ���ػ����ػ��̰�����ͨ��gKey_Type��������ǰ�Ƿ��а�������
 * ��    ��:
 * �������:
 * �������:
 * �� �� ֵ:   ��⵽��������1����⵽�̰�����2��û�а������·���0(����ֵ��ʱû�ã�����return��������)
 * ����˵��:
 * ������ʷ:
 *
 *================================================================================*/
uint32_t Get_Key(void)
{
	uint32_t nkey_time = 0;//�����Ӱ��µ��ɿ�ʱ��
	
	if( GPIO_PIN_RESET == HAL_GPIO_ReadPin(KEY_PWR_Port, KEY_PWR_Pin) && gKey_Pressed_Flag ==0 )//�����ⰴ���а��£���¼��������ʱ��
	{
		gKey_Pressed_Flag = 1;
		gKey_Pressed_Time = GET_CURTICK;	
	}
	if(gKey_Pressed_Flag == 1)
	{
		if( GPIO_PIN_SET == HAL_GPIO_ReadPin(KEY_PWR_Port, KEY_PWR_Pin)  )
		{
			nkey_time = GET_PASTTICK(gKey_Pressed_Time);
			gKey_Pressed_Flag = 0;
			gKey_Long_Pressed_Flag = 0;
      if( nkey_time > 1 && nkey_time<LONG_PRESS_POWER_ON_TIME && ENUM_POWER_OFF == gGetCurPowerState())//������´���10ms,�ر�״̬
			{
				gKey_Type = 2;
				return 2;
			}
		}
    /* ��⵽���������º�500ms���жϰ����Ƿ��Ա����� */
		if(GET_PASTTICK(gKey_Pressed_Time) >LONG_PRESS_POWER_ON_TIME && GPIO_PIN_RESET == HAL_GPIO_ReadPin(KEY_PWR_Port, KEY_PWR_Pin) && gKey_Long_Pressed_Flag ==0)//
		{
			gKey_Long_Pressed_Flag = 1;
			gKey_Type = 1;
			gLong_Press_Lose_Time = GET_CURTICK;	
			return 1;
		}   
	}
	return 0;
	
}



/******************************************************************************
 * ���ܣ�MCU�ϵ��İ�����⼰��Դʹ�ܿ��ơ�
 * ���룺��          
 * ���أ�
 * ˵������GPIO��ʼ��֮����ã�����̰���ʾ�������ܲ��ȶ������⡣
 *
 *****************************************************************************/
void poweron_proc(void)
{
  if( GPIO_PIN_RESET == HAL_GPIO_ReadPin(KEY_PWR_Port, KEY_PWR_Pin) && gKey_Pressed_Flag ==0 )//�����ⰴ���а��£���¼��������ʱ��
	{
		gKey_Pressed_Flag = 1;
		gKey_Pressed_Time = GET_CURTICK;
		MCU_POW_OUT_ON();	
	}
}

/*================================================================================*
 * ��������:    void PowerKey_Process(void)
 * ��������:    �����⵽�İ���
 * ��    ��:
 * �������:
 * �������:
 * �� �� ֵ:   
 * ����˵��:
 * ������ʷ:
 *
 *================================================================================*/
void PowerKey_Process(void)
{
  static uint32_t tim=0;
  static uint8_t sys_sleep= 0;
  
  Get_Key();

	if(gKey_Type!=0 )
	{
		if(gKey_Type == 1)//��������
		{
			gTogglePowerSate();
			if(ENUM_POWER_ON == gGetCurPowerState() ) //׼������
			{					
				MCU_POW_OUT_ON();
				RF_Init();

        BEEP_ON();
				delay_ms(300);
				BEEP_OFF();	
				gKey_Type = 0;
        sys_sleep= 0;
			}
			else if(ENUM_POWER_OFF == gGetCurPowerState() )  //׼���ػ�
			{
				BEEP_ON();	
				delay_ms(300);
        BEEP_OFF();	
				LED_BAT_ALL_OFF();
				LED_RTK_ALL_OFF();
				RF_POW2_OUT_OFF();       
        MCU_POW_OUT_OFF();
        
				gKey_Type = 0;					
			}
		}
		else if(gKey_Type == 2)//�ػ��̰�
		{			
			if( GET_PASTTICK(gKey_Pressed_Time) < 5000)
      {
        MCU_POW_OUT_ON();
      }
		}
    else if(gKey_Type == 3) // ����5s
    {
      gKey_Type = 0;
    }  
	}
  
  
  /* �ػ� */
  if(sPowerState == ENUM_POWER_OFF)
  {
		RF_POW2_OUT_OFF();

		if(sys_sleep == 0 && GET_PASTTICK(gKey_Pressed_Time) > 3000)
		{
			LED_BAT_ALL_OFF();
			LED_RTK_ALL_OFF();
			MCU_POW_OUT_OFF();
			sys_sleep= 1;
		}
  } 
}



void PowerCtrlInit(void)
{  

}



/*================================================================================*
 * ��������:    void Power_Control(void)
 * ��������:    ��������
 * ��    ��:
 * �������:
 * �������:
 * �� �� ֵ:
 * ����˵��:
 * ������ʷ:
 *
 *================================================================================*/
void Power_Control(void)
{
  PowerKey_Process();  
}
 
/*================================================================================*
 * ��������:    void AddPowerTask()
 * ��������:    ��������
 * ��    ��:
 * �������:
 * �������:
 * �� �� ֵ:
 * ����˵��:
 * ������ʷ:
 *
 *================================================================================*/
void AddPowerTask(void)
{
  nPowerTaskID = AddTask(PowerTaskInit, PowerTask, PowerTaskUninit);
}

/*================================================================================*
 * ��������:    uint32_t PowerTaskInit(void)
 * ��������:    �����ʼ��
 * ��    ��:
 * �������:
 * �������:
 * �� �� ֵ:
 * ����˵��:
 * ������ʷ:
 *================================================================================*/
int32_t PowerTaskInit(void)
{
  PowerCtrlInit();  
  
  return 0;
}


/*================================================================================*
 * ��������:    void PowerTask()
 * ��������:    
 * ��    ��:
 * �������:
 * �������:
 * �� �� ֵ:
 * ����˵��:    
 * ������ʷ:
 *
 *================================================================================*/
void PowerTask(void)
{
	static uint32_t nPowerTaskTimer = 0;
	//BuzzControl();
	if(GET_PASTTICK(nPowerTaskTimer)>=5)
	{
		nPowerTaskTimer = GET_CURTICK;
		Power_Control();
	}
}

/*================================================================================*
 * ��������:    uint32_t PowerTaskUninit(void)
 * ��������:   
 * ��    ��:
 * �������:
 * �������:
 * �� �� ֵ:
 * ����˵��:
 * ������ʷ:
 *
 *================================================================================*/
int32_t PowerTaskUninit(void)
{
  return 0;
}



