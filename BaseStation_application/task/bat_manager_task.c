/**
  ******************************************************************************
  * File Name          : bat_manager_task.c
  * Description        : This file provides code for the charge battery
  ******************************************************************************
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "bat_manager_task.h"
#include "Sys_cfg.h"
#include "includes.h"


/* Private_Defines -----------------------------------------------------------*/
#define PERCENT_BattChargeFull        98


/* Private_Variables ---------------------------------------------------------*/
uint8_t  nChargeTaskID;
uint8_t  BatFullFlag = 0;//充电时才会用到,电量大于96%超过500ms，默认为充电完成,0:电量低于96%，1：电量等于97%，2：电量等于98%，3：电量等于99%，4：电量等于100%
uint16_t gChargeState;   //电池状态

static uint32_t sLastReadBatTimer = 0;//充电时才会用到



/* Exported_Variables --------------------------------------------------------*/

extern uint8_t gBattery_Percent;
extern uint8_t update_flag;


//static void InitBatteryState(void);
void Charge_Control(void);
 
/*================================================================================*
 * 函数名称:    void AddChargeTask()
 * 功能描述:    增加任务
 * 作    者:
 * 输入参数:
 * 输出参数:
 * 返 回 值:
 * 其他说明:
 * 创建历史:
 *
 *================================================================================*/
void AddChargeTask(void)
{
    nChargeTaskID = AddTask(ChargeTaskInit, ChargeTask, ChargeTaskUninit);
}

/*================================================================================*
 * 函数名称:    uint32_t ChargeTaskInit(void)
 * 功能描述:    任务初始化
 * 作    者:
 * 输入参数:
 * 输出参数:
 * 返 回 值:
 * 其他说明:
 * 创建历史:
 *================================================================================*/
int32_t ChargeTaskInit(void)
{
//	InitBatteryState();
  return 0;
}


/*================================================================================*
 * 函数名称:    void ChargeTask()
 * 功能描述:    
 * 作    者:
 * 输入参数:
 * 输出参数:
 * 返 回 值:
 * 其他说明:    
 * 创建历史:
 *
 *================================================================================*/
void ChargeTask(void)
{
	static uint32_t nChargeTaskTimer = 0;
	Charge_Control();
	Normal_Led_Control();

	if(GET_PASTTICK(nChargeTaskTimer)>=1000)
	{
		nChargeTaskTimer = GET_CURTICK;	
	}
}



/*================================================================================*
 * 函数名称:    uint32_t PowerTaskUninit(void)
 * 功能描述:   
 * 作    者:
 * 输入参数:
 * 输出参数:
 * 返 回 值:
 * 其他说明:
 * 创建历史:
 *
 *================================================================================*/
int32_t ChargeTaskUninit(void)
{
    return 0;
}



/*================================================================================*
 * 函数名称:    void Charge_Control(void)
 * 功能描述:    充电控制和开机电量控制，控制充电时的LED和低电时的蜂鸣器
 * 作    者:
 * 输入参数:
 * 输出参数:
 * 返 回 值:
 * 其他说明:
 * 创建历史:
 *================================================================================*/
void Charge_Control(void)
{
	/* 实际是电池电量监控 */
	if(gGetCurPowerState() == ENUM_POWER_ON)
	{	
		if(gBattery_Percent < 5 && bat_info_updated)
		{
			if(update_flag ==1)
			{
				static uint32_t time = 0;
				if(GET_PASTTICK (time)>10000){
					update_flag =0;
				}
			}
			else{
				static uint8_t lowpwr= 0;
				if(lowpwr == 0){
					Clear_Buzzer();
					BuzzOn_time(0,0,34,300,300);  //20s左右
					lowpwr= 1;
				}
				if(  Get_Beep_Count() <= 1 && gGetCurPowerState() == ENUM_POWER_ON)//时间到，关机
				{
					BEEP_ON();	
					delay_ms(300);
					BEEP_OFF();
					gTogglePowerSate();
				}
			}
		}
		else if(gBattery_Percent >= 5 && gBattery_Percent < 10)
		{
			BuzzOn_time(0,0,20,200,9800);
		}
//					else if(gBattery_Percent >= 10 && gBattery_Percent <= 20)
//					{
//						BuzzOn_time(1,0,20,200,9800);
//					}
	}
	gChargeState = ENUM_CHARGE_NONE;

}

/*================================================================================*
 * 函数名称:    void Normal_Led_Control(void)
 * 功能描述:    开机状态下LED的控制函数
 * 作    者:
 * 输入参数:   
 * 输出参数:
 * 返 回 值:    
 * 其他说明:    
 * 创建历史:
 *
 *================================================================================*/

extern uint8_t  gKey_Type;
void Normal_Led_Control(void)
{
  uint8_t percent =  get_bat_percent();  //当期电量百分比状态，
  static uint32_t ledtimer= 0;
  static uint32_t ledcnt= 0;
  
  if(( gGetCurPowerState() == ENUM_POWER_ON ) || gKey_Type==2)
  {
    if ( GET_PASTTICK(ledtimer)>100 )
    {
      ledtimer = GET_CURTICK;
    
      if((percent == 0) && (bat_info_updated==0))
      {
        LED_BAT_ALL_OFF();
      }
      else if(percent < 10)
      {
        if(ledcnt < 1)
        {
          LED_BAT_R_ON();
        }else{
          LED_BAT_R_OFF();
        }
        
        if(++ledcnt > 19)ledcnt= 0;
      }
      else if (percent <= 30)
      {
        LED_BAT_R_ON();
      }
      else if (percent <= 60)
      {
        LED_BAT_Y_ON();
      }
      else  // > 60%
      {
        LED_BAT_G_ON();
      }
    }
  }
}
























/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
