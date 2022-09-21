/**************************************************************************************
 *
 * 文件描述：ADC相关接口
 * 创建日期：
 *
 * 备注：
 *
 **************************************************************************************
 */

/* Includes ------------------------------------------------------------------*/
#include "bsp_adc.h"
#include "bsp_gpio.h"
#include "Sys_cfg.h"
#include <math.h>

/* Private_Defines -----------------------------------------------------------*/
#define ADC_CH_Nmbr               eADC_CH_Nmbr

#define SAMPLINGTIME              ADC_SAMPLETIME_32CYCLES_5
#define OVERSAMPLING_RATIO        1024                                /* 16-oversampling */                                      
#define RIGHTBITSHIFT             ADC_RIGHTBITSHIFT_10                /* 4-bit right shift of the oversampled summation */          
#define TRIGGEREDMODE             ADC_TRIGGEREDMODE_SINGLE_TRIGGER    /* A single trigger for all channel oversampled conversions */
#define OVERSAMPLINGSTOPRESET     ADC_REGOVERSAMPLING_CONTINUED_MODE  /* Oversampling buffer maintained during injection sequence */



/* Private_TypesDefinitions --------------------------------------------------*/



/* Private_Variables ---------------------------------------------------------*/

ADC_HandleTypeDef   hadc1,hadc2;
AdcChannel_e        AdcChan=0;

__IO uint32_t adcval_last[ADC_CH_Nmbr];
__IO uint32_t adc_val[ADC_CH_Nmbr];
__IO uint16_t adc_mv[ADC_CH_Nmbr];

uint16_t typec_vbus_voltage= 0;
ntc_args_type ntc_args[2];

/* FunctionPrototypes --------------------------------------------------------*/



/* Functions -----------------------------------------------------------------*/



/******************************************************************************
 * 功能：配置ADC转换通道
 * 输入：无          
 * 返回：
 * 说明：
 *
 *****************************************************************************/
void bsp_adc_seq_cfg(ADC_HandleTypeDef *hadc, uint32_t Channel, uint32_t Rank)
{
  ADC_ChannelConfTypeDef   sConfig;
  
  sConfig.Channel      = Channel;                     /* Sampled channel number */
  sConfig.Rank         = Rank;                        /* Rank of sampled channel number ADCx_CHANNEL */
  sConfig.SamplingTime = SAMPLINGTIME;                /* Sampling time (number of clock cycles unit) */
  sConfig.SingleDiff   = ADC_SINGLE_ENDED;            /* Single-ended input channel */
  sConfig.OffsetNumber = ADC_OFFSET_NONE;             /* No offset subtraction */ 
  sConfig.Offset = 0;                                 /* Parameter discarded because offset correction is disabled */
  HAL_ADC_ConfigChannel(hadc, &sConfig);
}




/******************************************************************************
 * 功能：ADC初始化
 * 输入：无          
 * 返回：
 * 说明：
 *
 *****************************************************************************/
void bsp_adc_init(void)
{
  GPIO_InitTypeDef          GPIO_InitStruct;
  
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOF_CLK_ENABLE();
  
  __HAL_RCC_ADC_CONFIG(RCC_ADCCLKSOURCE_CLKP);
  __HAL_RCC_ADC12_CLK_ENABLE();
  
  GPIO_InitStruct.Pin = VERSION_ADC_Pin | TEMP1_ADC_Pin | TEMP2_ADC_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOF, &GPIO_InitStruct);
  
  
  /* ADC1 -------------------------------------------------------------- */
  hadc1.Instance= ADC1; 
  HAL_ADC_DeInit(&hadc1);
   
  hadc1.Init.ClockPrescaler           = ADC_CLOCK_ASYNC_DIV2;             /* Asynchronous clock mode, input ADC clock divided by 2*/
  hadc1.Init.Resolution               = ADC_RESOLUTION_16B;               /* 16-bit resolution for converted data */
  hadc1.Init.ScanConvMode             = DISABLE;                           /* Sequencer disabled (ADC conversion on only 1 channel: channel set on rank 1) */
  hadc1.Init.EOCSelection             = ADC_EOC_SEQ_CONV;                 /* EOC flag picked-up to indicate conversion end */
  hadc1.Init.LowPowerAutoWait         = DISABLE;                          /* Auto-delayed conversion feature disabled */
  hadc1.Init.ContinuousConvMode       = DISABLE;                           /* Continuous mode enabled (automatic conversion restart after each conversion) */
  hadc1.Init.NbrOfConversion          = 1;                                /* Parameter discarded because sequencer is disabled */
  hadc1.Init.DiscontinuousConvMode    = DISABLE;                          /* Parameter discarded because sequencer is disabled */
  hadc1.Init.NbrOfDiscConversion      = 1;                                /* Parameter discarded because sequencer is disabled */
  hadc1.Init.ExternalTrigConv         = ADC_SOFTWARE_START;               /* Software start to trig the 1st conversion manually, without external event */
  hadc1.Init.ExternalTrigConvEdge     = ADC_EXTERNALTRIGCONVEDGE_NONE;    /* Parameter discarded because software trigger chosen */
  hadc1.Init.ConversionDataManagement = ADC_CONVERSIONDATA_DR;            /* DR mode selected */
  hadc1.Init.Overrun                  = ADC_OVR_DATA_OVERWRITTEN;         /* DR register is overwritten with the last conversion result in case of overrun */
  hadc1.Init.OversamplingMode         = ENABLE;                           /* Oversampling enabled */
  hadc1.Init.Oversampling.Ratio                 = OVERSAMPLING_RATIO;     /* Oversampling ratio */
  hadc1.Init.Oversampling.RightBitShift         = RIGHTBITSHIFT;          /* Right shift of the oversampled summation */
  hadc1.Init.Oversampling.TriggeredMode         = TRIGGEREDMODE;          /* Specifies whether or not a trigger is needed for each sample */
  hadc1.Init.Oversampling.OversamplingStopReset = OVERSAMPLINGSTOPRESET;  /* Specifies whether or not the oversampling buffer is maintained during injection sequence */    
  
  HAL_ADC_Init(&hadc1);
  
  bsp_adc_seq_cfg(&hadc1, ADC_CHANNEL_2, ADC_REGULAR_RANK_1);
  //bsp_adc_seq_cfg(&hadc1, ADC_CHANNEL_6, ADC_REGULAR_RANK_2);
  //bsp_adc_seq_cfg(&hadc1, ADC_CHANNEL_7, ADC_REGULAR_RANK_3);
  
  HAL_ADCEx_Calibration_Start(&hadc1, ADC_CALIB_OFFSET, ADC_SINGLE_ENDED);
  //HAL_ADC_Start(&hadc1);
  HAL_ADC_Start_IT(&hadc1);

  /* ADC2 -------------------------------------------------------------- */
  hadc2.Instance= ADC2; 
  HAL_ADC_DeInit(&hadc2);
   
  hadc2.Init.ClockPrescaler           = ADC_CLOCK_ASYNC_DIV2;             /* Asynchronous clock mode, input ADC clock divided by 2*/
  hadc2.Init.Resolution               = ADC_RESOLUTION_16B;               /* 16-bit resolution for converted data */
  hadc2.Init.ScanConvMode             = DISABLE;                           /* Sequencer disabled (ADC conversion on only 1 channel: channel set on rank 1) */
  hadc2.Init.EOCSelection             = ADC_EOC_SEQ_CONV;                 /* EOC flag picked-up to indicate conversion end */
  hadc2.Init.LowPowerAutoWait         = DISABLE;                          /* Auto-delayed conversion feature disabled */
  hadc2.Init.ContinuousConvMode       = DISABLE;                           /* Continuous mode enabled (automatic conversion restart after each conversion) */
  hadc2.Init.NbrOfConversion          = 1;                                /* Parameter discarded because sequencer is disabled */
  hadc2.Init.DiscontinuousConvMode    = DISABLE;                          /* Parameter discarded because sequencer is disabled */
  hadc2.Init.NbrOfDiscConversion      = 1;                                /* Parameter discarded because sequencer is disabled */
  hadc2.Init.ExternalTrigConv         = ADC_SOFTWARE_START;               /* Software start to trig the 1st conversion manually, without external event */
  hadc2.Init.ExternalTrigConvEdge     = ADC_EXTERNALTRIGCONVEDGE_NONE;    /* Parameter discarded because software trigger chosen */
  hadc2.Init.ConversionDataManagement = ADC_CONVERSIONDATA_DR;            /* DR mode selected */
  hadc2.Init.Overrun                  = ADC_OVR_DATA_OVERWRITTEN;         /* DR register is overwritten with the last conversion result in case of overrun */
  hadc2.Init.OversamplingMode         = ENABLE;                           /* Oversampling enabled */
  hadc2.Init.Oversampling.Ratio                 = OVERSAMPLING_RATIO;     /* Oversampling ratio */
  hadc2.Init.Oversampling.RightBitShift         = RIGHTBITSHIFT;          /* Right shift of the oversampled summation */
  hadc2.Init.Oversampling.TriggeredMode         = TRIGGEREDMODE;          /* Specifies whether or not a trigger is needed for each sample */
  hadc2.Init.Oversampling.OversamplingStopReset = OVERSAMPLINGSTOPRESET;  /* Specifies whether or not the oversampling buffer is maintained during injection sequence */    
  
  HAL_ADC_Init(&hadc2);
  
  bsp_adc_seq_cfg(&hadc2, ADC_CHANNEL_2, ADC_REGULAR_RANK_1);
  //bsp_adc_seq_cfg(&hadc2, ADC_CHANNEL_6, ADC_REGULAR_RANK_2);
  
  HAL_ADCEx_Calibration_Start(&hadc2, ADC_CALIB_OFFSET, ADC_SINGLE_ENDED);
  //HAL_ADC_Start(&hadc2);
  //HAL_ADC_Start_IT(&hadc2);

  /* ------------------------------------------------------------------ */
  AdcChan= 0;
  
  HAL_NVIC_SetPriority(ADC_IRQn, 0, 1);
  HAL_NVIC_EnableIRQ(ADC_IRQn);

}


/******************************************************************************
 * 功能：解除ADC初始化
 * 输入：无          
 * 返回：
 * 说明：
 *
 *****************************************************************************/
void bsp_adc_uninit(void)
{
  __HAL_RCC_ADC12_FORCE_RESET();
  __HAL_RCC_ADC12_RELEASE_RESET();
  __HAL_RCC_ADC12_CLK_DISABLE();

  HAL_GPIO_DeInit(VERSION_ADC_Port, VERSION_ADC_Pin);
  HAL_GPIO_DeInit(TEMP1_ADC_Port, TEMP1_ADC_Pin);
  HAL_GPIO_DeInit(TEMP2_ADC_Port, TEMP2_ADC_Pin);
   
  HAL_NVIC_DisableIRQ(ADC_IRQn);
}



uint32_t get_max_temp_val(void)
{
  float temp_max=0;

  if(temp_max < ntc_args[0].temp)
    temp_max = ntc_args[0].temp;
  
  if(temp_max < ntc_args[1].temp)
    temp_max = ntc_args[1].temp;
  
  return (uint32_t)temp_max;
}




/******************************************************************************
 * 功能：将NTC电路的电压值转换为对应的温度值
 * 输入：volt_mv---NTC测温电路的输出电压值，单位mV          
 * 返回：返回摄氏温度值。
 * 说明：该函数在STM32H743上的运行耗时为2.75us。
 *
 *****************************************************************************/
const float Rp = 10000.0;		    // 10K，NTC在25℃时的标称电阻值
const float Rdown = 10000.0;	  // NTC分压电路的下分压电阻
const float T2 = (273.15 + 25.0);	// 25℃时的K氏温度
const float Bx = 3435.0;			  // 热敏电阻系数
const float Ka = 273.15;
const float Vref_mv = 3300;		  // NTC高边电压

float calc_ntc_temp(float volt_mv) {
	// NTC热敏电阻温度计算公式：
	// T1= ln(Rntc/Rp)/Bx+1/T2;

	float Rntc;		// NTC在当前温度下的电阻值
	float a;		// 临时变量
    
#if 0
  // NTC电阻在上臂
	Rntc = (Vref_mv * Rdown) / volt_mv - Rdown;
#else
  // NTC电阻在下臂
  Rntc = (volt_mv * Rdown) / (Vref_mv - volt_mv);
#endif  
	a = Rntc / Rp;
	a = log(a);
	a /= Bx;
	a += (1 / T2);
	a = 1 / a;
	a -= Ka;
  
	return a;
}



/******************************************************************************
 * 功能：ADC转换完成后的数据处理函数
 * 输入：无          
 * 返回：
 * 说明：1、该函数不需实时调用，在任务循环中调用即可。
 *       2、该函数仅对发生变化的ADC采样数据进行处理。
 *
 *****************************************************************************/
void bsp_adc_data_proc(void)
{
  uint8_t i;
  
  for (i=0; i<eADC_CH_Nmbr; i++)
  {
    /* 仅对变化的数据进行处理 */
    if(adcval_last[i] != adc_val[i])
    {
      adcval_last[i]= adc_val[i];
      adc_mv[i]= adc_val[i] * 3300 / 0xffff;
      
      switch(i)
      {
      case eADC_CH_A1C2_HW_VERSION:
        
        break;
        
      case eADC_CH_A1C6_PCB_TEMP1:
        ntc_args[0].temp = calc_ntc_temp(adc_mv[i]*1.0);
        break;
        
      case eADC_CH_A2C2_PCB_TEMP2:
        ntc_args[1].temp = calc_ntc_temp(adc_mv[i]*1.0);      
        break;
        
      default:
        break;

      }       
    }
  }  
}





/******************************************************************************
 * 功能：ADC转换完成回调函数
 * 输入：无          
 * 返回：
 * 说明：该函数在HAL_ADC_IRQHandler中被调用。
 *
 *****************************************************************************/
void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef *hadc)
{
  adc_val[AdcChan]= hadc->Instance->DR;
  
  switch(AdcChan)
  {
    case eADC_CH_A1C2_HW_VERSION:
      bsp_adc_seq_cfg(&hadc1, ADC_CHANNEL_6, ADC_REGULAR_RANK_1); 
      HAL_ADC_Start_IT(&hadc1);
      AdcChan = eADC_CH_A1C6_PCB_TEMP1;
      break;
      
    case eADC_CH_A1C6_PCB_TEMP1:
      HAL_ADC_Stop_IT(&hadc1);
      bsp_adc_seq_cfg(&hadc2, ADC_CHANNEL_2, ADC_REGULAR_RANK_1);
      HAL_ADC_Start_IT(&hadc2);  
      AdcChan = eADC_CH_A2C2_PCB_TEMP2;
      break;
      
    case eADC_CH_A2C2_PCB_TEMP2:   
      HAL_ADC_Stop_IT(&hadc2);
      bsp_adc_seq_cfg(&hadc1, ADC_CHANNEL_2, ADC_REGULAR_RANK_1);
      HAL_ADC_Start_IT(&hadc1); 
      AdcChan = eADC_CH_A1C2_HW_VERSION;
      break;
      
    default:
      break;
  }
}


/******************************************************************************
 * 功能：ADC1和ADC2的中断函数
 * 输入：无          
 * 返回：
 * 说明：采用1024倍过采样方式，中断间隔约2.63ms，中断执行时间8-13us。
 *
 *****************************************************************************/
void ADC_IRQHandler(void)
{  
  HAL_ADC_IRQHandler(&hadc1);
  HAL_ADC_IRQHandler(&hadc2);
}








/*********************************** END OF FILE *************************************/
