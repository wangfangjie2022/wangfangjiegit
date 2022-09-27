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

/*================================================================================*
 * 函数名称:    void Charge_Led_Control(void)
 * 功能描述:    充电状态下LED控制
 * 作    者:
 * 输入参数:
 * 输出参数:
 * 返 回 值:
 * 其他说明:
 * 创建历史:
 *================================================================================*/
//void Charge_Led_Control(void)
//{
//	static uint32_t nChrLedTimer;	
//	static uint8_t charge_led_cnt;
//  uint8_t percent =  gBattery_Percent;  //当期电量百分比状态，

//	if(Get_Cur_ChargeState() ==ENUM_POWER_ON_CHARGE || Get_Cur_ChargeState() ==ENUM_POWER_OFF_CHARGE || Get_Cur_ChargeState() ==ENUM_POWER_COMPELETED_CHARGE)
//	{
//		if ( GET_PASTTICK(nChrLedTimer)>250 )
//		{
//			nChrLedTimer = GET_CURTICK;

//      if((percent == 0) && (bat_info_updated==0))
//      {
//        LED_BAT_ALL_OFF();
//      }
//      else if(charge_led_cnt < 2)
//      {
//        if (percent <= 30)
//        {
//          LED_BAT_R_ON();
//        }
//        else if (percent <= 60)
//        {
//          LED_BAT_Y_ON();
//        }
//        else  // > 60%
//        {
//          LED_BAT_G_ON();
//        }
//      }
//      else if (percent < PERCENT_BattChargeFull)  // 98%以上为充满状态，不闪烁
//      {
//        LED_BAT_ALL_OFF();
//      }
//      
//      if(++charge_led_cnt > 3) charge_led_cnt= 0;
//			
//		}
//	}		
//}







/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
