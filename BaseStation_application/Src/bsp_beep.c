/**************************************************************************************
 *
 * 文件描述：蜂鸣器控制相关接口
 * 创建日期：
 *
 * 备注：
 *
 **************************************************************************************
 */

/* Includes ------------------------------------------------------------------*/
#include "bsp_gpio.h"
#include "bsp_beep.h"
#include "Sys_cfg.h"

/* Private_Defines -----------------------------------------------------------*/



/* Private_TypesDefinitions --------------------------------------------------*/



/* Private_Variables ---------------------------------------------------------*/
static uint8_t sisAlwaysOn = 0;//蜂鸣器是否一直响
static uint8_t sPrioryty =0;
static uint8_t sbeepCount = 0;//响几次
static uint8_t sBuzzStat = 0;//指示当前蜂鸣器的状态，0代表灭，1代表响
static uint32_t sHighTime = 0;
static uint32_t sLowTime = 0;
static uint32_t sStartHighTime=0, sStartLowTime=0;


/* FunctionPrototypes --------------------------------------------------------*/



/* Functions -----------------------------------------------------------------*/

/******************************************************************************
 * 功能：
 * 输入：无          
 * 返回：
 * 说明：
 *
 *****************************************************************************/
uint8_t Get_Beep_Count(void)
{
	return sbeepCount;
}


/******************************************************************************
 * 功能：
 * 输入：无          
 * 返回：
 * 说明：
 *
 *****************************************************************************/
void Clear_Buzzer(void)
{
		sisAlwaysOn = 0;
		sbeepCount = 0;
		sHighTime = 0;
		sLowTime = 0;
		sBuzzStat = 0;
		BEEP_OFF();
}


/******************************************************************************
 * 功能：蜂鸣器发音控制
 * 输入：
 *   isAlwaysOn:是否一直叫
 *   nPrioryty：优先级，默认为0，数字越大优先级越高
 *   nCount：循环几次
 *   nHighTime：高电平时间
 *   nLowTime：低电平时间
 * 返回：
 * 说明：低优先级的蜂鸣器想要打断高优先级的必须先调用Clear_Buzzer（）函数
 *
 *****************************************************************************/
uint8_t BuzzOn_time(uint8_t isAlwaysOn,uint8_t nPrioryty,uint8_t nCount,uint32_t nHighTime, uint32_t nLowTime )
{
	if(nPrioryty <= sPrioryty && sbeepCount == 0)
	{
		sisAlwaysOn = isAlwaysOn;
		sbeepCount = nCount;
		if(sisAlwaysOn == 1)
			sbeepCount = 0XFF;
		sHighTime = nHighTime;
		sLowTime = nLowTime;
		sStartHighTime = GET_CURTICK;
		if( sbeepCount >0 && sisAlwaysOn !=1 )
		{
			sBuzzStat = 1;
			BEEP_ON();
			sbeepCount--;
		}
	}
	else if(nPrioryty > sPrioryty)
	{
		sisAlwaysOn = isAlwaysOn;
		sbeepCount = nCount;
		sHighTime = nHighTime;
		sLowTime = nLowTime;
		sStartHighTime = GET_CURTICK;
		if( sbeepCount >0 )
		{
			sBuzzStat = 1;
			BEEP_ON();
			sbeepCount--;
		}
	}
	return sbeepCount;
}


/******************************************************************************
 * 功能：蜂鸣器控制逻辑
 * 输入：无          
 * 返回：
 * 说明：
 *
 *****************************************************************************/
void BuzzControl(void)
{
	if(sisAlwaysOn == 1)
	{
		if( GET_PASTTICK(sStartHighTime) >= sHighTime && sBuzzStat == 1)
		{			
			sStartLowTime = GET_CURTICK;
			sBuzzStat = 0;
			BEEP_OFF();//响的时间完成，关蜂鸣器
		}
		if( GET_PASTTICK(sStartLowTime) >= sLowTime && sBuzzStat == 0)
		{			
			sStartHighTime = GET_CURTICK;
			sBuzzStat = 1;
			BEEP_ON();
		}
	}
	else
	{
		if( GET_PASTTICK(sStartHighTime) >= sHighTime && sBuzzStat == 1 && sbeepCount>=0)
		{			
			sStartLowTime = GET_CURTICK;
			sBuzzStat = 0;
			BEEP_OFF();//响的时间完成，关蜂鸣器
		}
		if( GET_PASTTICK(sStartLowTime) >= sLowTime && sBuzzStat == 0 && sbeepCount>0)
		{			
			sStartHighTime = GET_CURTICK;
			sBuzzStat = 1;
			BEEP_ON();
			sbeepCount--;
		}
	}
}






/*********************************** END OF FILE *************************************/
