/**************************************************************************************
 *
 * 文件描述：
 * 创建日期：
 *
 * 备注：
 *
 **************************************************************************************
 */

/* Includes ------------------------------------------------------------------*/
#include "includes.h"

/* Private_Defines -----------------------------------------------------------*/



/* Private_TypesDefinitions --------------------------------------------------*/



/* Private_Variables ---------------------------------------------------------*/
TIM_HandleTypeDef    TimHandle;
TIM_OC_InitTypeDef 	 sConfig;


/* FunctionPrototypes --------------------------------------------------------*/



/* Functions -----------------------------------------------------------------*/
#define MATCH_LED_TIMx                 	TIM5
#define MATCH_LED_TIMx_CLK_ENABLE()    	__HAL_RCC_TIM5_CLK_ENABLE()
#define MATCH_LED_TIMx_IRQn							TIM5_IRQn
#define MATCH_LED_TIMx_IRQHandler				TIM5_IRQHandler
#define MATCH_LED_TIM_PERIOD_DEF				(20000-1)


/******************************************************************************
 * 功能：图传对频灯闪烁定时器
 * 输入：无          
 * 返回：
 * 说明：
 *
 *****************************************************************************/
void match_led_tim_init(void)
{
	uint32_t uwPrescalerValue = 0;
	
	MATCH_LED_TIMx_CLK_ENABLE();
	
	uwPrescalerValue = (uint32_t)(SystemCoreClock / (2*10000)) - 1;
	
	TimHandle.Instance 							 = MATCH_LED_TIMx;
	TimHandle.Init.Period            = MATCH_LED_TIM_PERIOD_DEF;
  TimHandle.Init.Prescaler         = uwPrescalerValue;
  TimHandle.Init.ClockDivision     = 0;
  TimHandle.Init.CounterMode       = TIM_COUNTERMODE_UP;
  TimHandle.Init.RepetitionCounter = 0;
	
	HAL_TIM_PWM_Init(&TimHandle);
	
	sConfig.OCMode       = TIM_OCMODE_PWM1;
  sConfig.OCPolarity   = TIM_OCPOLARITY_HIGH;
  sConfig.OCFastMode   = TIM_OCFAST_DISABLE;
  sConfig.OCNPolarity  = TIM_OCNPOLARITY_HIGH;
  sConfig.OCNIdleState = TIM_OCNIDLESTATE_RESET;

  sConfig.OCIdleState  = TIM_OCIDLESTATE_RESET;
	sConfig.Pulse = 0;
	
	HAL_TIM_PWM_ConfigChannel(&TimHandle, &sConfig, TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&TimHandle, TIM_CHANNEL_1);
	
	HAL_TIM_Base_Start_IT(&TimHandle);
	HAL_TIM_IC_Start_IT(&TimHandle, TIM_CHANNEL_1);
	
	HAL_NVIC_SetPriority(MATCH_LED_TIMx_IRQn, 5, 0);
  HAL_NVIC_EnableIRQ(MATCH_LED_TIMx_IRQn);
		
}


void match_led_tim_uninit(void)
{
	HAL_TIM_PWM_DeInit(&TimHandle);
	__HAL_RCC_TIM5_CLK_DISABLE();
	HAL_NVIC_DisableIRQ(MATCH_LED_TIMx_IRQn);
}


void HAL_TIM_PWM_PulseFinishedCallback(TIM_HandleTypeDef *htim)
{
	static uint16_t pulse1_last= 0;
	
	if (htim->Instance == MATCH_LED_TIMx)
	{
		LED_MATCH_OFF();
		
		if(pulse1_last != sys_info.match_led_on_tim)
		{
			htim->Instance->CCR1 = sys_info.match_led_on_tim*10;
			pulse1_last = sys_info.match_led_on_tim;
		}
	}
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	static uint16_t period_last= 0;
	
	if (htim->Instance == MATCH_LED_TIMx)
	{
		if (sys_info.match_led_on_tim>=5) {
			LED_MATCH_ON();
		} else {
			LED_MATCH_OFF();
		}
		
		if (period_last != sys_info.match_led_tim_period)
		{
			htim->Instance->ARR = sys_info.match_led_tim_period*10;
			period_last = sys_info.match_led_tim_period;
		}
	}
}


void MATCH_LED_TIMx_IRQHandler(void)
{
	
	HAL_TIM_IRQHandler(&TimHandle);
}








/*********************************** END OF FILE *************************************/
