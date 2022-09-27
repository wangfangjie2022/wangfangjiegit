/**
  ******************************************************************************
  * @file    UART/UART_HyperTerminal_DMA/Src/stm32h7xx_hal_msp.c
  * @author  MCD Application Team
  * @brief   HAL MSP module.
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
#include "stm32h7xx_hal.h"
#include "bsp_gpio.h"
#include "bsp_uart.h"

/** @addtogroup STM32H7xx_HAL_Examples
  * @{
  */

/** @defgroup UART_HyperTerminal_DMA
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/** @defgroup HAL_MSP_Private_Functions
  * @{
  */
  
/**
  * @brief  Initializes the Global MSP.
  * @retval None
  */
void HAL_MspInit(void)
{

}

/**
  * @brief  DeInitializes the Global MSP.
  * @retval None
  */
void HAL_MspDeInit(void)
{

}

/**
  * @brief  Initializes the PPP MSP.
  * @retval None
  */
void HAL_PPP_MspInit(void)
{

}

/**
  * @brief  DeInitializes the PPP MSP.
  * @retval None
  */
void HAL_PPP_MspDeInit(void)
{

}  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  

/**
  * @brief UART MSP Initialization
  *        This function configures the hardware resources used in this example:
  *           - Peripheral's clock enable
  *           - Peripheral's GPIO Configuration
  *           - DMA configuration for transmission request by peripheral
  *           - NVIC configuration for DMA interrupt request enable
  * @param huart: UART handle pointer
  * @retval None
  */
void HAL_UART_MspInit(UART_HandleTypeDef *huart)
{
  //static DMA_HandleTypeDef hdma_tx;
  //static DMA_HandleTypeDef hdma_rx;

  GPIO_InitTypeDef  GPIO_InitStruct;

  RCC_PeriphCLKInitTypeDef RCC_PeriphClkInit;

  if(huart->Instance == USART1)
  {
    /*##-1- Enable peripherals and GPIO Clocks #################################*/
    __HAL_RCC_GPIOA_CLK_ENABLE();
    
    RCC_PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_USART1;
    RCC_PeriphClkInit.Usart16ClockSelection = RCC_USART1CLKSOURCE_D2PCLK2;
    HAL_RCCEx_PeriphCLKConfig(&RCC_PeriphClkInit);
    
    __HAL_RCC_USART1_CLK_ENABLE();
    __HAL_RCC_DMA1_CLK_ENABLE();

    /*##-2- Configure peripheral GPIO ##########################################*/
    /* UART TX GPIO pin configuration  */
    GPIO_InitStruct.Pin       = GPIO_PIN_9;
    GPIO_InitStruct.Mode      = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull      = GPIO_PULLUP;
    GPIO_InitStruct.Speed     = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF7_USART1;

    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    /* UART RX GPIO pin configuration  */
    GPIO_InitStruct.Pin = GPIO_PIN_10;
    GPIO_InitStruct.Alternate = GPIO_AF7_USART1;

    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    /*##-3- Configure the DMA ##################################################*/
    /* Configure the DMA handler for Transmission process */
    hdma_usart1_tx.Instance                 = USART1_TX_DMA_STREAM;
    hdma_usart1_tx.Init.Request             = DMA_REQUEST_USART1_TX;
    hdma_usart1_tx.Init.Direction           = DMA_MEMORY_TO_PERIPH;
    hdma_usart1_tx.Init.PeriphInc           = DMA_PINC_DISABLE;
    hdma_usart1_tx.Init.MemInc              = DMA_MINC_ENABLE;
    hdma_usart1_tx.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
    hdma_usart1_tx.Init.MemDataAlignment    = DMA_MDATAALIGN_BYTE;
    hdma_usart1_tx.Init.Mode                = DMA_NORMAL;
    hdma_usart1_tx.Init.Priority            = DMA_PRIORITY_LOW;
    hdma_usart1_tx.Init.FIFOMode            = DMA_FIFOMODE_DISABLE;
    hdma_usart1_tx.Init.FIFOThreshold       = DMA_FIFO_THRESHOLD_FULL;
    hdma_usart1_tx.Init.MemBurst            = DMA_MBURST_INC4;
    hdma_usart1_tx.Init.PeriphBurst         = DMA_PBURST_INC4;

    HAL_DMA_Init(&hdma_usart1_tx);

    /* Associate the initialized DMA handle to the UART handle */
    __HAL_LINKDMA(huart, hdmatx, hdma_usart1_tx);

    /* Configure the DMA handler for reception process */
    hdma_usart1_rx.Instance                 = USART1_RX_DMA_STREAM;
    hdma_usart1_rx.Init.Request             = DMA_REQUEST_USART1_RX;
    hdma_usart1_rx.Init.Direction           = DMA_PERIPH_TO_MEMORY;
    hdma_usart1_rx.Init.PeriphInc           = DMA_PINC_DISABLE;
    hdma_usart1_rx.Init.MemInc              = DMA_MINC_ENABLE;
    hdma_usart1_rx.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
    hdma_usart1_rx.Init.MemDataAlignment    = DMA_MDATAALIGN_BYTE;
    hdma_usart1_rx.Init.Mode                = DMA_NORMAL;
    hdma_usart1_rx.Init.Priority            = DMA_PRIORITY_HIGH;
    hdma_usart1_rx.Init.FIFOMode            = DMA_FIFOMODE_DISABLE;
    hdma_usart1_rx.Init.FIFOThreshold       = DMA_FIFO_THRESHOLD_FULL;
    hdma_usart1_rx.Init.MemBurst            = DMA_MBURST_INC4;
    hdma_usart1_rx.Init.PeriphBurst         = DMA_PBURST_INC4;

    HAL_DMA_Init(&hdma_usart1_rx);

    /* Associate the initialized DMA handle to the the UART handle */
    __HAL_LINKDMA(huart, hdmarx, hdma_usart1_rx);
      
  }
  else if(huart->Instance == USART2)
  {
    
  }
  else if(huart->Instance == USART3)
  {
    /*##-1- Enable peripherals and GPIO Clocks #################################*/
    __HAL_RCC_GPIOD_CLK_ENABLE();

    RCC_PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_USART3;
    RCC_PeriphClkInit.Usart234578ClockSelection = RCC_USART3CLKSOURCE_D2PCLK1;
    HAL_RCCEx_PeriphCLKConfig(&RCC_PeriphClkInit);
    
    __HAL_RCC_USART3_CLK_ENABLE();
    __HAL_RCC_DMA1_CLK_ENABLE();

    /*##-2- Configure peripheral GPIO ##########################################*/
    /* UART TX GPIO pin configuration  */
    GPIO_InitStruct.Pin       = GPIO_PIN_8;
    GPIO_InitStruct.Mode      = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull      = GPIO_PULLUP;
    GPIO_InitStruct.Speed     = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF7_USART3;

    HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

    /* UART RX GPIO pin configuration  */
    GPIO_InitStruct.Pin = GPIO_PIN_9;
    GPIO_InitStruct.Alternate = GPIO_AF7_USART3;

    HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

    /*##-3- Configure the DMA ##################################################*/
    /* Configure the DMA handler for Transmission process */
    hdma_usart3_tx.Instance                 = USART3_TX_DMA_STREAM;
    hdma_usart3_tx.Init.Request             = DMA_REQUEST_USART3_TX;
    hdma_usart3_tx.Init.Direction           = DMA_MEMORY_TO_PERIPH;
    hdma_usart3_tx.Init.PeriphInc           = DMA_PINC_DISABLE;
    hdma_usart3_tx.Init.MemInc              = DMA_MINC_ENABLE;
    hdma_usart3_tx.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
    hdma_usart3_tx.Init.MemDataAlignment    = DMA_MDATAALIGN_BYTE;
    hdma_usart3_tx.Init.Mode                = DMA_NORMAL;
    hdma_usart3_tx.Init.Priority            = DMA_PRIORITY_LOW;
    hdma_usart3_tx.Init.FIFOMode            = DMA_FIFOMODE_DISABLE;
    hdma_usart3_tx.Init.FIFOThreshold       = DMA_FIFO_THRESHOLD_FULL;
    hdma_usart3_tx.Init.MemBurst            = DMA_MBURST_INC4;
    hdma_usart3_tx.Init.PeriphBurst         = DMA_PBURST_INC4;

    HAL_DMA_Init(&hdma_usart3_tx);

    /* Associate the initialized DMA handle to the UART handle */
    __HAL_LINKDMA(huart, hdmatx, hdma_usart3_tx);

    /* Configure the DMA handler for reception process */
    hdma_usart3_rx.Instance                 = USART3_RX_DMA_STREAM;
    hdma_usart3_rx.Init.Request             = DMA_REQUEST_USART3_RX;
    hdma_usart3_rx.Init.Direction           = DMA_PERIPH_TO_MEMORY;
    hdma_usart3_rx.Init.PeriphInc           = DMA_PINC_DISABLE;
    hdma_usart3_rx.Init.MemInc              = DMA_MINC_ENABLE;
    hdma_usart3_rx.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
    hdma_usart3_rx.Init.MemDataAlignment    = DMA_MDATAALIGN_BYTE;
    hdma_usart3_rx.Init.Mode                = DMA_NORMAL;
    hdma_usart3_rx.Init.Priority            = DMA_PRIORITY_HIGH;
    hdma_usart3_rx.Init.FIFOMode            = DMA_FIFOMODE_DISABLE;
    hdma_usart3_rx.Init.FIFOThreshold       = DMA_FIFO_THRESHOLD_FULL;
    hdma_usart3_rx.Init.MemBurst            = DMA_MBURST_INC4;
    hdma_usart3_rx.Init.PeriphBurst         = DMA_PBURST_INC4;

    HAL_DMA_Init(&hdma_usart3_rx);

    /* Associate the initialized DMA handle to the the UART handle */
    __HAL_LINKDMA(huart, hdmarx, hdma_usart3_rx);

  }
  else if(huart->Instance == UART4)
  {
    
  }
  else if(huart->Instance == UART5)
  {
    
  }
  else if(huart->Instance == USART6)
  {
    
  }
  else if(huart->Instance == UART7)
  {

  }
  else if(huart->Instance == UART8)
  {
    /*##-1- Enable peripherals and GPIO Clocks #################################*/
    __HAL_RCC_GPIOE_CLK_ENABLE();

    RCC_PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_UART8;
    RCC_PeriphClkInit.Usart234578ClockSelection = RCC_UART8CLKSOURCE_D2PCLK1;
    HAL_RCCEx_PeriphCLKConfig(&RCC_PeriphClkInit);
    
    __HAL_RCC_UART8_CLK_ENABLE();
    __HAL_RCC_DMA2_CLK_ENABLE();

    /*##-2- Configure peripheral GPIO ##########################################*/
    /* UART TX GPIO pin configuration  */
    GPIO_InitStruct.Pin       = GPIO_PIN_1;
    GPIO_InitStruct.Mode      = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull      = GPIO_PULLUP;
    GPIO_InitStruct.Speed     = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF8_UART8;

    HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

    /* UART RX GPIO pin configuration  */
    GPIO_InitStruct.Pin = GPIO_PIN_0;
    GPIO_InitStruct.Alternate = GPIO_AF8_UART8;
    HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

    /*##-3- Configure the DMA ##################################################*/
    /* Configure the DMA handler for Transmission process */
    hdma_uart8_tx.Instance                 = UART8_TX_DMA_STREAM;
    hdma_uart8_tx.Init.Request             = DMA_REQUEST_UART8_TX;
    hdma_uart8_tx.Init.Direction           = DMA_MEMORY_TO_PERIPH;
    hdma_uart8_tx.Init.PeriphInc           = DMA_PINC_DISABLE;
    hdma_uart8_tx.Init.MemInc              = DMA_MINC_ENABLE;
    hdma_uart8_tx.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
    hdma_uart8_tx.Init.MemDataAlignment    = DMA_MDATAALIGN_BYTE;
    hdma_uart8_tx.Init.Mode                = DMA_NORMAL;
    hdma_uart8_tx.Init.Priority            = DMA_PRIORITY_LOW;
    hdma_uart8_tx.Init.FIFOMode            = DMA_FIFOMODE_DISABLE;
    hdma_uart8_tx.Init.FIFOThreshold       = DMA_FIFO_THRESHOLD_FULL;
    hdma_uart8_tx.Init.MemBurst            = DMA_MBURST_INC4;
    hdma_uart8_tx.Init.PeriphBurst         = DMA_PBURST_INC4;

    HAL_DMA_Init(&hdma_uart8_tx);

    /* Associate the initialized DMA handle to the UART handle */
    __HAL_LINKDMA(huart, hdmatx, hdma_uart8_tx);

    /* Configure the DMA handler for reception process */
    hdma_uart8_rx.Instance                 = UART8_RX_DMA_STREAM;
    hdma_uart8_rx.Init.Request             = DMA_REQUEST_UART8_RX;
    hdma_uart8_rx.Init.Direction           = DMA_PERIPH_TO_MEMORY;
    hdma_uart8_rx.Init.PeriphInc           = DMA_PINC_DISABLE;
    hdma_uart8_rx.Init.MemInc              = DMA_MINC_ENABLE;
    hdma_uart8_rx.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
    hdma_uart8_rx.Init.MemDataAlignment    = DMA_MDATAALIGN_BYTE;
    hdma_uart8_rx.Init.Mode                = DMA_NORMAL;
    hdma_uart8_rx.Init.Priority            = DMA_PRIORITY_HIGH;
    hdma_uart8_rx.Init.FIFOMode            = DMA_FIFOMODE_DISABLE;
    hdma_uart8_rx.Init.FIFOThreshold       = DMA_FIFO_THRESHOLD_FULL;
    hdma_uart8_rx.Init.MemBurst            = DMA_MBURST_INC4;
    hdma_uart8_rx.Init.PeriphBurst         = DMA_PBURST_INC4;

    HAL_DMA_Init(&hdma_uart8_rx);

    /* Associate the initialized DMA handle to the the UART handle */
    __HAL_LINKDMA(huart, hdmarx, hdma_uart8_rx);
  } 
}

/**
  * @brief UART MSP De-Initialization
  *        This function frees the hardware resources used in this example:
  *          - Disable the Peripheral's clock
  *          - Revert GPIO, DMA and NVIC configuration to their default state
  * @param huart: UART handle pointer
  * @retval None
  */
void HAL_UART_MspDeInit(UART_HandleTypeDef *huart)
{ 
  GPIO_InitTypeDef  GPIO_InitStruct;

  RCC_PeriphCLKInitTypeDef RCC_PeriphClkInit;

  if(huart->Instance == USART1)
  {
    /*##-1- Reset peripherals ##################################################*/
    __HAL_RCC_USART1_FORCE_RESET();
    __HAL_RCC_USART1_RELEASE_RESET();

    /*##-2- Disable peripherals and GPIO Clocks ################################*/
    /* Configure UART Tx as alternate function  */
    HAL_GPIO_DeInit(USART1_TX_Port, USART1_TX_Pin);
    /* Configure UART Rx as alternate function  */
    HAL_GPIO_DeInit(USART1_RX_Port, USART1_RX_Pin);
    
    /*##-3- Disable the DMA Streams ############################################*/
    /* De-Initialize the DMA Stream associated to transmission process */
    HAL_DMA_DeInit(&hdma_usart1_tx);
    /* De-Initialize the DMA Stream associated to reception process */
    HAL_DMA_DeInit(&hdma_usart1_rx);

    /*##-4- Disable the NVIC for DMA ###########################################*/
    
  }
  else if(huart->Instance == USART2)
  {
    
  }
  else if(huart->Instance == USART3)
  {
    /*##-1- Reset peripherals ##################################################*/
    __HAL_RCC_USART3_FORCE_RESET();
    __HAL_RCC_USART3_RELEASE_RESET();

    /*##-2- Disable peripherals and GPIO Clocks ################################*/
    /* Configure UART Tx as alternate function  */
    HAL_GPIO_DeInit(USART3_TX_Port, USART3_TX_Pin);
    /* Configure UART Rx as alternate function  */
    HAL_GPIO_DeInit(USART3_RX_Port, USART3_RX_Pin);
    
    /*##-3- Disable the DMA Streams ############################################*/
    /* De-Initialize the DMA Stream associated to transmission process */
    HAL_DMA_DeInit(&hdma_usart3_tx);
    /* De-Initialize the DMA Stream associated to reception process */
    HAL_DMA_DeInit(&hdma_usart3_rx);

    /*##-4- Disable the NVIC for DMA ###########################################*/
    
  }
  else if(huart->Instance == UART4)
  {
    // 未使用
  }
  else if(huart->Instance == UART5)
  {
    // 未使用
  }
  else if(huart->Instance == USART6)
  {
    // 未使用    
  }
  else if(huart->Instance == UART7)
  {
    // 未使用
  }
  else if(huart->Instance == UART8)
  {
    /*##-1- Reset peripherals ##################################################*/
    __HAL_RCC_UART8_FORCE_RESET();
    __HAL_RCC_UART8_RELEASE_RESET();

    /*##-2- Disable peripherals and GPIO Clocks ################################*/
    /* Configure UART Tx as alternate function  */
    HAL_GPIO_DeInit(UART8_TX_Port, UART8_TX_Pin);
    /* Configure UART Rx as alternate function  */
    HAL_GPIO_DeInit(UART8_RX_Port, UART8_RX_Pin);
    
    /*##-3- Disable the DMA Streams ############################################*/
    /* De-Initialize the DMA Stream associated to transmission process */
    HAL_DMA_DeInit(&hdma_uart8_tx);
    /* De-Initialize the DMA Stream associated to reception process */
    HAL_DMA_DeInit(&hdma_uart8_rx);

    /*##-4- Disable the NVIC for DMA ###########################################*/
  } 


}

















/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
