/**************************************************************************************
 *
 * �ļ�������ADC��ؽӿ�
 * �������ڣ�
 *
 * ��ע��
 *
 **************************************************************************************
 */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __BSP_ADC_H
#define __BSP_ADC_H

/* Includes ------------------------------------------------------------------*/
#include "stm32h7xx_hal.h"

/* Exported_Macros -----------------------------------------------------------*/



/* Exported_Types ------------------------------------------------------------*/
typedef struct {
	uint32_t adc_val;
	float volt;					  // mv��ѹ
	float volt_flt;				// mv���˲�ֵ
	float temp;					  // ���¶�ֵ
	float temp_flt;				// ���¶��˲�ֵ
} ntc_args_type;


typedef enum{
  eAdcSta_INIT= 0,
  eAdcSta_WAIT_EOC,
  eAdcSta_PROC,

}AdcRunStat_e;

typedef enum{
  eADC_CH_A1C2_HW_VERSION= 0,
  eADC_CH_A1C6_PCB_TEMP1, 
  eADC_CH_A2C2_PCB_TEMP2,
  eADC_CH_Nmbr, 
  
}AdcChannel_e;


/* Exported_Variables --------------------------------------------------------*/



/* Exported_Functions --------------------------------------------------------*/
void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef *hadc);

void bsp_adc_init(void);
void bsp_adc_uninit(void);
void bsp_adc_data_proc(void);

uint32_t get_max_temp_val(void);

























#endif
