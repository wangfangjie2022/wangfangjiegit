/**************************************************************************************
 *
 * �ļ�������������������ؽӿ�
 * �������ڣ�
 *
 * ��ע��
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
static uint8_t sisAlwaysOn = 0;//�������Ƿ�һֱ��
static uint8_t sPrioryty =0;
static uint8_t sbeepCount = 0;//�켸��
static uint8_t sBuzzStat = 0;//ָʾ��ǰ��������״̬��0������1������
static uint32_t sHighTime = 0;
static uint32_t sLowTime = 0;
static uint32_t sStartHighTime=0, sStartLowTime=0;


/* FunctionPrototypes --------------------------------------------------------*/



/* Functions -----------------------------------------------------------------*/

/******************************************************************************
 * ���ܣ�
 * ���룺��          
 * ���أ�
 * ˵����
 *
 *****************************************************************************/
uint8_t Get_Beep_Count(void)
{
	return sbeepCount;
}


/******************************************************************************
 * ���ܣ�
 * ���룺��          
 * ���أ�
 * ˵����
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
 * ���ܣ���������������
 * ���룺
 *   isAlwaysOn:�Ƿ�һֱ��
 *   nPrioryty�����ȼ���Ĭ��Ϊ0������Խ�����ȼ�Խ��
 *   nCount��ѭ������
 *   nHighTime���ߵ�ƽʱ��
 *   nLowTime���͵�ƽʱ��
 * ���أ�
 * ˵���������ȼ��ķ�������Ҫ��ϸ����ȼ��ı����ȵ���Clear_Buzzer��������
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
 * ���ܣ������������߼�
 * ���룺��          
 * ���أ�
 * ˵����
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
			BEEP_OFF();//���ʱ����ɣ��ط�����
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
			BEEP_OFF();//���ʱ����ɣ��ط�����
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
