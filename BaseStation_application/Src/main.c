/**************************************************************************************
 *
 * 文件描述：基于STM32H743的RTK追踪天线基站应用程序
 * 创建日期：
 *
 * 备注：
 *
 *
 * MCU: STM32H743IIK6: 
 *
 * USART1 ---电池通讯RS485，PC4收发使能控制端
 * USART2 ---RTK COM1
 * USART3 ---WIFI AR9342（基本不用）
 * UART4  ---未使用
 * UART5  ---未使用
 * USART6 ---未使用
 * UART7  ---未使用
 * UART8  ---天线端MCU
 * 
 * I2C2   ---未使用
 * I2C3   ---未使用
 * I2C4   ---磁力计LIS3MDL
 * SPI1   ---IMU6500
 * SDIO   ---未使用
 * USB    ---未使用
 *
 * RTK_COM2 ---天线端图传COM3
 *
 * DMA问题：
 * 0x20000000是DTCM段，DMA无法进行访问，从而导致DMA传输时无法读写数据。
 * 0x24000000是AXI SRAM区域，支持DMA访问，应将DMA操作的内存区域定义到该区域。
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 **************************************************************************************
 */
 
 
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32h7xx_hal.h"
#include "Sys_cfg.h"
#include "bsp_gpio.h"
#include "includes.h"
#include <stdio.h>
#include "string.h"

#include "xstar_fcs.h"
#include "rtwtypes.h"

/* Private variables ---------------------------------------------------------*/
IWDG_HandleTypeDef hiwdg;

uint8_t update_flag = 0;
uint32_t wifi_rst_cnt= 0;
uint8_t wifi_rst_flag = 0;


//extern UART_HandleTypeDef huart1;
//extern uint8_t gBattery_Percent;

volatile boolean_T stopRequested = false;




/* Private_Defines -----------------------------------------------------------*/



/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
void MPU_Config(void);
void rt_OneStep(void);


/* Private function prototypes -----------------------------------------------*/



//#define DEBUG_PRINT
//#define PUTCHAR_PROTOTYPE int fputc(int ch,FILE* f)
//	
//#ifdef DEBUG_PRINT
//PUTCHAR_PROTOTYPE
//{
////	HAL_UART_Transmit(&huart1,(uint8_t*)&ch,1,0xffff);
//	HAL_UART_Transmit(&com_obj[COM1].uart,(uint8_t*)&ch,1,0xffff);
//	return ch;
//}
//#else
//PUTCHAR_PROTOTYPE {return 0;}
//#endif

#if 0
  // ARM Compiler V5
  __IO uint32_t gGotoLoaderFlag   __attribute__((at(RAM_BASE_ADDR)))=0;
  __IO uint32_t gLoderResetFlag   __attribute__((at(RAM_BASE_ADDR+4)));
#else
  // ARM Compiler V6
  __IO uint32_t gGotoLoaderFlag   __attribute__((section(".ARM.__at_0x24000000")))=0;
  __IO uint32_t gLoderResetFlag   __attribute__((section(".ARM.__at_0x24000004")));
#endif


/******************************************************************************
 * 功能：延时函数，ms
 * 输入：t---需延迟的ms数          
 * 返回：
 * 说明：
 *
 *****************************************************************************/
void delay_ms(uint32_t t)
{
  uint32_t nCurTimer;
  nCurTimer = GET_CURTICK;

  while(GET_PASTTICK(nCurTimer)<t);
}


static void CPU_CACHE_Enable(void)
{
  SCB_EnableICache();
  SCB_EnableDCache();
}


//uint8_t testbuf[1024];

//static void uart_test(void)
//{
//  static uint8_t flag_init=0;
//  static uint32_t runtim= 0;

//  if(!flag_init)
//  {
//    for(uint16_t i=0; i<1024; i++){
//      testbuf[i]= i;
//    }
//    flag_init= 1;
//  }
//  
//  if(GET_PASTTICK(runtim) > 100)
//  {
//    runtim= GET_CURTICK;
//    
//    serial_send(&com_obj[COM7], testbuf, UART7_TX_FIFO_MAX/2);
//  
//  }
//}

alink_rtk_location_t rtk_location;

/******************************************************************************
 * 功能：主函数
 * 输入：       
 * 返回：
 * 说明：
 *
 *****************************************************************************/
int main(void)
{
	volatile boolean_T runModel = true;
	
	/* IWDG 1s 超时溢出 */ 
  //MX_IWDG_Init(IWDG_PRESCALER_128,2500);
	//128/40*3125 = 10s
  //64/40*3125= 5s
  /* 启动独立看门狗 */
  //HAL_IWDG_Start(&hiwdg);
  
  MPU_Config();
  CPU_CACHE_Enable();
  
  HAL_Init();
  SystemClock_Config();
  HAL_SYSTICK_Config(400000);

  MX_GPIO_Init();
  MCU_POW_OUT_ON();
  
  boot_info_init();
	if(gLoderResetFlag == (RC_UPDATE_FLAG|0xFF) ) //判断是不是升级完成然后重启的
	{
    RF_Init();
    update_flag = 1;
    gLoderResetFlag = 0;
    gTogglePowerSate();
	}else{
    poweron_proc();
  }
  
  MX_USART1_UART_Init();
	DBG_UART_Init();
  bsp_adc_init();
  bsp_crc_init();
	
  if(update_flag)
  {
    MX_USART2_UART_Init();
    MX_USART3_UART_Init();
		MX_UART8_UART_Init();
    wifi_rst_flag= 1;
  } 
  
	TaskInit();
	AddPowerTask(); 
	AddChargeTask();
	AddDealRTKTask();
	AddUpdateTask();
  AddUartCommonTask();

  wifi_rst_cnt= GET_CURTICK;
  __ENABLE_IRQ();
	
	bsp_mag_init();
	rtmSetErrorStatus(xstar_fcs_M, 0);
	xstar_fcs_initialize();
	runModel = rtmGetErrorStatus(xstar_fcs_M) == (NULL);
	bsp_imu_init();
	
  while (1)
  {
    stopRequested = !(rtmGetErrorStatus(xstar_fcs_M) == (NULL));
    runModel = !(stopRequested);
    TaskRun();
    //HAL_IWDG_Refresh(&hiwdg);
    
    bsp_adc_data_proc();
    imu_idle_task();
    mag_idle_task();
    DealRTKTask();
		imagelink_task();
		
		if(runModel)
		{
      rt_OneStep();
		}
    
    //uart_test();

  }
}



/**
  * @brief  System Clock Configuration
  *         The system Clock is configured as follow : 
  *            System Clock source            = PLL (HSE)
  *            SYSCLK(Hz)                     = 400000000 (CPU Clock)
  *            HCLK(Hz)                       = 200000000 (AXI and AHBs Clock)
  *            AHB Prescaler                  = 2
  *            D1 APB3 Prescaler              = 2 (APB3 Clock  100MHz)
  *            D2 APB1 Prescaler              = 2 (APB1 Clock  100MHz)
  *            D2 APB2 Prescaler              = 2 (APB2 Clock  100MHz)
  *            D3 APB4 Prescaler              = 2 (APB4 Clock  100MHz)
  *            HSE Frequency(Hz)              = 25000000
  *            PLL_M                          = 5
  *            PLL_N                          = 160
  *            PLL_P                          = 2
  *            PLL_Q                          = 4
  *            PLL_R                          = 2
  *            VDD(V)                         = 3.3
  *            Flash Latency(WS)              = 4
  * @param  None
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_ClkInitTypeDef RCC_ClkInitStruct;
  RCC_OscInitTypeDef RCC_OscInitStruct;
  HAL_StatusTypeDef ret = HAL_OK;
  
  /*!< Supply configuration update enable */
  HAL_PWREx_ConfigSupply(PWR_LDO_SUPPLY);

  /* The voltage scaling allows optimizing the power consumption when the device is
     clocked below the maximum system frequency, to update the voltage scaling value
     regarding system frequency refer to product datasheet.  */
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  while(!__HAL_PWR_GET_FLAG(PWR_FLAG_VOSRDY)) {}
  
  /* Enable HSE Oscillator and activate PLL with HSE as source */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSIState = RCC_HSI_OFF;
  RCC_OscInitStruct.CSIState = RCC_CSI_OFF;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  
  RCC_OscInitStruct.PLL.PLLM = 5;
  RCC_OscInitStruct.PLL.PLLN = 160;
  RCC_OscInitStruct.PLL.PLLFRACN = 0;
  RCC_OscInitStruct.PLL.PLLP = 2;
  RCC_OscInitStruct.PLL.PLLR = 2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
   
  RCC_OscInitStruct.PLL.PLLVCOSEL = RCC_PLL1VCOWIDE;
  RCC_OscInitStruct.PLL.PLLRGE = RCC_PLL1VCIRANGE_2;
  ret = HAL_RCC_OscConfig(&RCC_OscInitStruct);
  if(ret != HAL_OK)
  {
    while(1) { ; }
  }  
  
  /* Select PLL as system clock source and configure  bus clocks dividers */
  RCC_ClkInitStruct.ClockType = (RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_D1PCLK1 | RCC_CLOCKTYPE_PCLK1 | \
                                 RCC_CLOCKTYPE_PCLK2  | RCC_CLOCKTYPE_D3PCLK1);
  
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.SYSCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB3CLKDivider = RCC_APB3_DIV2;  
  RCC_ClkInitStruct.APB1CLKDivider = RCC_APB1_DIV2; 
  RCC_ClkInitStruct.APB2CLKDivider = RCC_APB2_DIV2; 
  RCC_ClkInitStruct.APB4CLKDivider = RCC_APB4_DIV2; 
  ret = HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_4);
  if(ret != HAL_OK)
  {
    while(1) { ; }
  } 
}


unsigned int run_time(void)
{
	return (nSysTick * 1000);
}



/**
  * 函数功能: 独立看门狗初始化配置
  * 输入参数: Tout = prv/40 * rlv (s) prv可以是[4,8,16,32,64,128,256]
  *            prv:预分频器值，取值如下：
  *            参数 IWDG_PRESCALER_4: IWDG prescaler set to 4
  *            参数 IWDG_PRESCALER_8: IWDG prescaler set to 8
  *            参数 IWDG_PRESCALER_16: IWDG prescaler set to 16
  *            参数 IWDG_PRESCALER_32: IWDG prescaler set to 32
  *            参数 IWDG_PRESCALER_64: IWDG prescaler set to 64
  *            参数 IWDG_PRESCALER_128: IWDG prescaler set to 128
  *            参数 IWDG_PRESCALER_256: IWDG prescaler set to 256
  *
  *            rlv:预分频器值，取值范围为：0-0XFFF
  * 返 回 值: 无
  * 说    明：函数调用举例：
  *           IWDG_Config(IWDG_Prescaler_64 ,625);  // IWDG 1s 超时溢出
  */
void MX_IWDG_Init(uint8_t prv ,uint16_t rlv)
{

//  hiwdg.Instance = IWDG;
//  hiwdg.Init.Prescaler = prv;
//  hiwdg.Init.Reload = rlv;
//  HAL_IWDG_Init(&hiwdg);

}


/******************************************************************************
 * 功能：统一设置DMA优先级
 * 输入：无          
 * 返回：
 * 说明：
 *
 *****************************************************************************/
static void MX_DMA_Init(void) 
{
  /* DMA controller clock enable */
  __HAL_RCC_DMA1_CLK_ENABLE();
  __HAL_RCC_DMA2_CLK_ENABLE();
  
}


/******************************************************************************
 * 功能：GPIO统一初始化
 * 输入：无          
 * 返回：
 * 说明：
 *
 *****************************************************************************/
static void MX_GPIO_Init(void)
{

  GPIO_InitTypeDef GPIO_InitStruct;

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOE_CLK_ENABLE();
  __HAL_RCC_GPIOF_CLK_ENABLE();
  __HAL_RCC_GPIOG_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOI_CLK_ENABLE();

  HAL_GPIO_WritePin(GPIOA, LED_RTK_R_Pin | LED_PWR_R_Pin | LED_PWR_G_Pin, GPIO_PIN_RESET);
                          
  HAL_GPIO_WritePin(GPIOC, LED_DEBUG_G_Pin | LED_DEBUG_R_Pin | LED_RTK_G_Pin | RS485_RE_Pin, GPIO_PIN_RESET);
  
  HAL_GPIO_WritePin(GPIOE, BUZZ_Pin | MCU_POWON_Pin, GPIO_PIN_RESET);
  HAL_GPIO_WritePin(GPIOE, MCU_POWON_Pin | RF_POWON2_Pin, GPIO_PIN_SET);  // 防止升级重启时图传掉电 
                          
  HAL_GPIO_WritePin(GPIOG, LED_R_WARNING_Pin | LED_G_RUN_Pin | VBUS_EN_Pin, GPIO_PIN_SET);                        
                          
  HAL_GPIO_WritePin(GPIOH, RTK_RST_Pin | LED_MATCH_G_Pin, GPIO_PIN_RESET);

  //HAL_GPIO_WritePin(GPIOI, /*HUB_RST_Pin | WIFI_RST_Pin | WIFI_EN_Pin | */, GPIO_PIN_RESET);

  /* GPIOA output */
  GPIO_InitStruct.Pin = LED_RTK_R_Pin | LED_PWR_R_Pin | LED_PWR_G_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /* GPIOC output */
  GPIO_InitStruct.Pin = LED_DEBUG_G_Pin | LED_DEBUG_R_Pin | LED_RTK_G_Pin | RS485_RE_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);
  
  /* GPIOD output */
  GPIO_InitStruct.Pin = DBG_GPIO_Pin1 | DBG_GPIO_Pin2 | DBG_GPIO_Pin3;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);
  

  /* GPIOE output */
  GPIO_InitStruct.Pin = BUZZ_Pin | MCU_POWON_Pin | RF_POWON2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

  /* GPIOE input */
  GPIO_InitStruct.Pin = KEY_PWR_Pin | KEY_MATCH_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

  /* GPIOG output */
  GPIO_InitStruct.Pin = LED_R_WARNING_Pin | LED_G_RUN_Pin | VBUS_EN_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOG, &GPIO_InitStruct);

  /* GPIOG input */
  GPIO_InitStruct.Pin = IMU_INT_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOG, &GPIO_InitStruct);

  /* GPIOH output */
  GPIO_InitStruct.Pin = RTK_RST_Pin | LED_MATCH_G_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOH, &GPIO_InitStruct);
	
	/* GPIOH input */
  GPIO_InitStruct.Pin = MAG2_INT_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOH, &GPIO_InitStruct);

  /* GPIOI output */
  GPIO_InitStruct.Pin = /* HUB_RST_Pin | WIFI_RST_Pin | */ WIFI_EN_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOI, &GPIO_InitStruct);
    
  /* WIFI上电 */
  WIFI_PWR_ON();
  
  /* PH9 WIFI复位脚暂时设置为输入状态，避免影响WIFI功能 */
  GPIO_InitStruct.Pin = HUB_RST_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOI, &GPIO_InitStruct);
  
  GPIO_InitStruct.Pin = WIFI_RST_Pin;
  HAL_GPIO_Init(GPIOH, &GPIO_InitStruct);

  /* ADC输入 */
  GPIO_InitStruct.Pin = VERSION_ADC_Pin | TEMP1_ADC_Pin | TEMP2_ADC_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOF, &GPIO_InitStruct);
	
	/* SPI和I2C在各自功能模块中初始化 */
  /* SPI1 IMU接口
   * MOSI ---PD7
   * MISO ---PG9
   * NSS  ---PG10
   * SCK  ---PG11
   * INT  ---PG12 （未使用）
   */
  GPIO_InitStruct.Pin       = SPI1_SCK_Pin;
  GPIO_InitStruct.Mode      = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull      = GPIO_PULLDOWN;
  GPIO_InitStruct.Speed     = GPIO_SPEED_FREQ_HIGH;
  GPIO_InitStruct.Alternate = GPIO_AF5_SPI1;
  HAL_GPIO_Init(SPI1_SCK_Port, &GPIO_InitStruct);
  
  GPIO_InitStruct.Pin = SPI1_MISO_Pin;
  GPIO_InitStruct.Alternate = GPIO_AF5_SPI1;
  HAL_GPIO_Init(SPI1_MISO_Port, &GPIO_InitStruct);

  GPIO_InitStruct.Pin = SPI1_MOSI_Pin;
  GPIO_InitStruct.Alternate = GPIO_AF5_SPI1;
  HAL_GPIO_Init(SPI1_MOSI_Port, &GPIO_InitStruct);
  
  GPIO_InitStruct.Pin = SPI1_NSS_Pin;
  GPIO_InitStruct.Mode      = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull      = GPIO_NOPULL;
  GPIO_InitStruct.Speed     = GPIO_SPEED_FREQ_HIGH;
  GPIO_InitStruct.Alternate = GPIO_AF5_SPI1;
  HAL_GPIO_Init(SPI1_NSS_Port, &GPIO_InitStruct);
  
  /* I2C4 磁力计接口
   * SCL  ---PH11
   * SDA  ---PH12
   */
  GPIO_InitStruct.Pin       = I2C4_SCL_Pin;
  GPIO_InitStruct.Mode      = GPIO_MODE_AF_OD;
  GPIO_InitStruct.Pull      = GPIO_PULLUP;
  GPIO_InitStruct.Speed     = GPIO_SPEED_FREQ_LOW;
  GPIO_InitStruct.Alternate = GPIO_AF4_I2C4;
  HAL_GPIO_Init(I2C4_SCL_Port, &GPIO_InitStruct);
    
  /* I2C RX GPIO pin configuration  */
  GPIO_InitStruct.Pin       = I2C4_SDA_Pin;
  GPIO_InitStruct.Alternate = GPIO_AF4_I2C4;
  HAL_GPIO_Init(I2C4_SDA_Port, &GPIO_InitStruct);
}


void MPU_Config(void)
{
	MPU_Region_InitTypeDef MPU_InitStruct;
	HAL_MPU_Disable();
	MPU_InitStruct.Enable           = MPU_REGION_ENABLE;
	MPU_InitStruct.BaseAddress      = 0x24000000;
	MPU_InitStruct.Size             = MPU_REGION_SIZE_512KB;
	MPU_InitStruct.AccessPermission = MPU_REGION_FULL_ACCESS;
	MPU_InitStruct.IsBufferable     = MPU_ACCESS_NOT_BUFFERABLE;
	MPU_InitStruct.IsCacheable      = MPU_ACCESS_NOT_CACHEABLE;
	MPU_InitStruct.IsShareable      = MPU_ACCESS_NOT_SHAREABLE;
	MPU_InitStruct.Number           = MPU_REGION_NUMBER0;
	MPU_InitStruct.TypeExtField     = MPU_TEX_LEVEL1;
	MPU_InitStruct.SubRegionDisable = 0x00;
	MPU_InitStruct.DisableExec      = MPU_INSTRUCTION_ACCESS_ENABLE;
	HAL_MPU_ConfigRegion(&MPU_InitStruct);
	HAL_MPU_Enable(MPU_PRIVILEGED_DEFAULT);
}




/**
  * @brief  This function is executed in case of error occurrence.
  * @param  file: The file name as string.
  * @param  line: The line in file as a number.
  * @retval None
  */
void _Error_Handler(char *file, int line)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  while(1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}



#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{ 
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
