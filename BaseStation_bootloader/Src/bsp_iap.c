/**************************************************************************************
 *
 * �ļ�������
 * �������ڣ�
 *
 * ��ע��
 *
 **************************************************************************************
 */

/* Includes ------------------------------------------------------------------*/
#include "bsp_iap.h"
#include "Sys_cfg.h"
#include "includes.h"

/* Private_Defines -----------------------------------------------------------*/



/* Private_TypesDefinitions --------------------------------------------------*/



/* Private_Variables ---------------------------------------------------------*/
typedef  void (*pFunction)(void);
pFunction JumpToApplication;


/* FunctionPrototypes --------------------------------------------------------*/



/* Functions -----------------------------------------------------------------*/

/******************************************************************************
 * ���ܣ���ת��app�����
 * ���룺��          
 * ���أ�
 * ˵����
 *
 *****************************************************************************/
void do_jump(uint32_t vector_addr)
{
  /* �ж��������ַ�ͳ�����ʼ��ַ�Ƿ�Ϸ� */
  if ((*(__IO uint32_t*) vector_addr & RAM_BASE_ADDR) != RAM_BASE_ADDR) return;  
  if ((*(__IO uint32_t*)(vector_addr + 4) & FLASH_BASE_ADDR) != FLASH_BASE_ADDR) return;
  
  /* ����ջָ�벢��ת��boot��app��ʼ��ַȥ���г��� */
	JumpToApplication = *((pFunction*) (vector_addr + 4));
	__set_MSP(*(__IO uint32_t*) vector_addr);
  SCB->VTOR = vector_addr;
	JumpToApplication();
	for (;;) ;
}


void disable_all_irq(void)
{  
  __DISABLE_IRQ();
  MX_USART1_UART_UnInit();
  MX_USART3_UART_UnInit();
  MX_UART8_UART_UnInit();
  HAL_NVIC_DisableIRQ(SysTick_IRQn);
  HAL_NVIC_DisableIRQ(EXTI9_5_IRQn);
  flash_uninit();
  
  
}  
  