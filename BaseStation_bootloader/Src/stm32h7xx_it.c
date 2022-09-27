/**
  ******************************************************************************
  * @file    UART/UART_HyperTerminal_DMA/Src/stm32h7xx_it.c
  * @author  MCD Application Team
  * @brief   Main Interrupt Service Routines.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2017 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32h7xx_it.h"
#include "stm32h7xx_hal.h"
#include "bsp_gpio.h"
#include "bsp_uart.h"

/** @addtogroup STM32H7xx_HAL_Examples
  * @{
  */

/** @addtogroup UART_HyperTerminal_DMA
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
volatile uint32_t nSysTick=0;





/* UART handler declared in "main.c" file */
extern UART_HandleTypeDef UartHandle;
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/******************************************************************************/
/*            Cortex-M7 Processor Exceptions Handlers                         */
/******************************************************************************/

/**
  * @brief  This function handles NMI exception.
  * @param  None
  * @retval None
  */
void NMI_Handler(void)
{
}

/**
  * @brief  This function handles Hard Fault exception.
  * @param  None
  * @retval None
  */
void HardFault_Handler(void)
{
  /* Go to infinite loop when Hard Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Memory Manage exception.
  * @param  None
  * @retval None
  */
void MemManage_Handler(void)
{
  /* Go to infinite loop when Memory Manage exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Bus Fault exception.
  * @param  None
  * @retval None
  */
void BusFault_Handler(void)
{
  /* Go to infinite loop when Bus Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Usage Fault exception.
  * @param  None
  * @retval None
  */
void UsageFault_Handler(void)
{
  /* Go to infinite loop when Usage Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles SVCall exception.
  * @param  None
  * @retval None
  */
void SVC_Handler(void)
{
}

/**
  * @brief  This function handles Debug Monitor exception.
  * @param  None
  * @retval None
  */
void DebugMon_Handler(void)
{
}

/**
  * @brief  This function handles PendSVC exception.
  * @param  None
  * @retval None
  */
void PendSV_Handler(void)
{
}

/**
  * @brief  This function handles SysTick Handler.
  * @param  None
  * @retval None
  */
void SysTick_Handler(void)
{
  HAL_IncTick();
  nSysTick++;
  
  BuzzControl();
}


void Default_Handler(void)
{
  while (1)
  {
  }
}
/******************************************************************************/
/*                 STM32H7xx Peripherals Interrupt Handlers                   */
/*  Add here the Interrupt Handler for the used peripheral(s) (PPP), for the  */
/*  available peripheral interrupt handler's name please refer to the startup */
/*  file (startup_stm32h7xx.s).                                               */
/******************************************************************************/

#include "bsp_uart.h"

/******************************************************************************
 * 功能：UART 空闲中断函数
 * 输入：无          
 * 返回：
 * 说明：
 *
 *****************************************************************************/
void USART1_IRQHandler(void)
{
	UartReceive_IDLE(&com_obj[COM1].uart);
  HAL_UART_IRQHandler(&com_obj[COM1].uart);
}



void USART3_IRQHandler(void)
{
	UartReceive_IDLE(&com_obj[COM3].uart);
  HAL_UART_IRQHandler(&com_obj[COM3].uart);
}



void UART8_IRQHandler(void)
{
  UartReceive_IDLE(&com_obj[COM8].uart);
  HAL_UART_IRQHandler(&com_obj[COM8].uart);
}



/******************************************************************************
 * 功能：UART DMA发送完成中断函数
 * 输入：无          
 * 返回：
 * 说明：
 *
 *****************************************************************************/
void USART1_DMA_TX_IRQHandler(void)
{
  HAL_DMA_IRQHandler(&hdma_usart1_tx);
}  


void USART3_DMA_TX_IRQHandler(void)
{
  HAL_DMA_IRQHandler(&hdma_usart3_tx);
}  


void UART8_DMA_TX_IRQHandler(void)
{
  HAL_DMA_IRQHandler(&hdma_uart8_tx);
}  







/******************************************************************************
 * 功能：UART DMA接收完成中断函数
 * 输入：无          
 * 返回：
 * 说明：
 *
 *****************************************************************************/
void USART1_DMA_RX_IRQHandler(void)
{
  HAL_DMA_IRQHandler(&hdma_usart1_rx);
} 


void USART3_DMA_RX_IRQHandler(void)
{
  HAL_DMA_IRQHandler(&hdma_usart3_rx);
} 


void UART8_DMA_RX_IRQHandler(void)
{
  HAL_DMA_IRQHandler(&hdma_uart8_rx);
}







/**
  * @brief  This function handles PPP interrupt request.
  * @param  None
  * @retval None
  */
/*void PPP_IRQHandler(void)
{
}*/

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
