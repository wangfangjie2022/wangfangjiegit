/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H__
#define __MAIN_H__

/* Includes ------------------------------------------------------------------*/
#include "fun_opt.h"




/* Private define ------------------------------------------------------------*/
#define WIFI_RST_DELAY_MS             5000


void MPU_Config(void);
void _Error_Handler(char *, int);
unsigned int run_time(void);


#define Error_Handler() _Error_Handler(__FILE__, __LINE__)


#endif /* __MAIN_H__ */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
