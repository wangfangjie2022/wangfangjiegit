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
 *                                   宏定义                                       *
 *================================================================================*/

/*================================================================================*
 *                                全局变量定义                                    *
 *================================================================================*/
uint8_t nPowerTaskID;

/*================================================================================*
 *                               局部变量定义                                     *
 *================================================================================*/

uint8_t  gKey_Pressed_Flag = 0;//按键是否有按下
uint8_t  gKey_Long_Pressed_Flag = 0;//按键是否有按下
uint8_t  gKey_Type = 0;//1:长按开关机，2：关机短按
uint32_t gKey_Pressed_Time = 0;
uint32_t gLong_Press_Lose_Time = 0;//长按松开时间，用于解决偶尔长按后检测到短按的bug

const uint16_t PRESS_DELAY = 500;
static uint8_t sPowerState= ENUM_POWER_OFF;

#define LONG_PRESS_POWER_ON_TIME 1000

/*================================================================================*
 *                                 函数声明                                       *
 *================================================================================*/

/*================================================================================*
 *                                 函数原型                                       *
 *================================================================================*/
/*================================================================================*
 * 函数名称:    void gTogglePowerSate()
 * 功能描述:    改变开关机状态
 * 作    者:
 * 输入参数:
 * 输出参数:
 * 返 回 值:
 * 其他说明:
 * 创建历史:
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
 * 函数名称:    uint8_t gGetCurPowerState()
 * 功能描述:    获取当前开关机状态
 * 作    者:
 * 输入参数:
 * 输出参数:
 * 返 回 值:
 * 其他说明:
 * 创建历史:
 *
 *================================================================================*/
uint8_t gGetCurPowerState(void)
{
	return sPowerState;
}
/*================================================================================*
 * 函数名称:    void RF_Init(void)
 * 功能描述:    初始化射频模块电源
 * 作    者:
 * 输入参数:
 * 输出参数:
 * 返 回 值:
 * 其他说明:
 * 创建历史:
 *
 *================================================================================*/
void RF_Init(void)
{
	RF_POW2_OUT_ON();
}
/*================================================================================*
 * 函数名称:    void RF_DeInit(void)
 * 功能描述:    关闭射频模块电源
 * 作    者:
 * 输入参数:
 * 输出参数:
 * 返 回 值:
 * 其他说明:
 * 创建历史:
 *
 *================================================================================*/
void RF_DeInit(void)
{
	RF_POW2_OUT_OFF();
} 


/*================================================================================*
 * 函数名称:    uint32_t Get_Key(void)
 * 功能描述:    开关机及关机短按处理，通过gKey_Type变量管理当前是否有按键按下
 * 作    者:
 * 输入参数:
 * 输出参数:
 * 返 回 值:   检测到长按返回1，检测到短按返回2，没有按键按下返回0(返回值暂时没用，利用return结束程序)
 * 其他说明:
 * 创建历史:
 *
 *================================================================================*/
uint32_t Get_Key(void)
{
	uint32_t nkey_time = 0;//按键从按下到松开时间
	
	if( GPIO_PIN_RESET == HAL_GPIO_ReadPin(KEY_PWR_Port, KEY_PWR_Pin) && gKey_Pressed_Flag ==0 )//如果检测按键有按下，记录按键按下时间
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
      if( nkey_time > 1 && nkey_time<LONG_PRESS_POWER_ON_TIME && ENUM_POWER_OFF == gGetCurPowerState())//如果按下大于10ms,关闭状态
			{
				gKey_Type = 2;
				return 2;
			}
		}
    /* 检测到按键被按下后500ms后判断按键是否仍被按下 */
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
 * 功能：MCU上电后的按键检测及电源使能控制。
 * 输入：无          
 * 返回：
 * 说明：在GPIO初始化之后调用，解决短按显示电量功能不稳定的问题。
 *
 *****************************************************************************/
void poweron_proc(void)
{
  if( GPIO_PIN_RESET == HAL_GPIO_ReadPin(KEY_PWR_Port, KEY_PWR_Pin) && gKey_Pressed_Flag ==0 )//如果检测按键有按下，记录按键按下时间
	{
		gKey_Pressed_Flag = 1;
		gKey_Pressed_Time = GET_CURTICK;
		MCU_POW_OUT_ON();	
	}
}

/*================================================================================*
 * 函数名称:    void PowerKey_Process(void)
 * 功能描述:    处理检测到的按键
 * 作    者:
 * 输入参数:
 * 输出参数:
 * 返 回 值:   
 * 其他说明:
 * 创建历史:
 *
 *================================================================================*/
void PowerKey_Process(void)
{
  static uint32_t tim=0;
  static uint8_t sys_sleep= 0;
  
  Get_Key();

	if(gKey_Type!=0 )
	{
		if(gKey_Type == 1)//按键长按
		{
			gTogglePowerSate();
			if(ENUM_POWER_ON == gGetCurPowerState() ) //准备开机
			{					
				MCU_POW_OUT_ON();
				RF_Init();

        BEEP_ON();
				delay_ms(300);
				BEEP_OFF();	
				gKey_Type = 0;
        sys_sleep= 0;
			}
			else if(ENUM_POWER_OFF == gGetCurPowerState() )  //准备关机
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
		else if(gKey_Type == 2)//关机短按
		{			
			if( GET_PASTTICK(gKey_Pressed_Time) < 5000)
      {
        MCU_POW_OUT_ON();
      }
		}
    else if(gKey_Type == 3) // 长按5s
    {
      gKey_Type = 0;
    }  
	}
  
  
  /* 关机 */
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
 * 函数名称:    void Power_Control(void)
 * 功能描述:    按键管理
 * 作    者:
 * 输入参数:
 * 输出参数:
 * 返 回 值:
 * 其他说明:
 * 创建历史:
 *
 *================================================================================*/
void Power_Control(void)
{
  PowerKey_Process();  
}
 
/*================================================================================*
 * 函数名称:    void AddPowerTask()
 * 功能描述:    增加任务
 * 作    者:
 * 输入参数:
 * 输出参数:
 * 返 回 值:
 * 其他说明:
 * 创建历史:
 *
 *================================================================================*/
void AddPowerTask(void)
{
  nPowerTaskID = AddTask(PowerTaskInit, PowerTask, PowerTaskUninit);
}

/*================================================================================*
 * 函数名称:    uint32_t PowerTaskInit(void)
 * 功能描述:    任务初始化
 * 作    者:
 * 输入参数:
 * 输出参数:
 * 返 回 值:
 * 其他说明:
 * 创建历史:
 *================================================================================*/
int32_t PowerTaskInit(void)
{
  PowerCtrlInit();  
  
  return 0;
}


/*================================================================================*
 * 函数名称:    void PowerTask()
 * 功能描述:    
 * 作    者:
 * 输入参数:
 * 输出参数:
 * 返 回 值:
 * 其他说明:    
 * 创建历史:
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
int32_t PowerTaskUninit(void)
{
  return 0;
}



