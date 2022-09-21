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
CRC_HandleTypeDef   CrcHandle;

//uint8_t test_dat[]={
//0xAA, 0x44, 0x12, 0x1C, 0xCB, 0x03, 0x00, 0x01, 0x2C, 0x00, 0x00, 0x00, 0x23, 0xA0, 0xAC, 0x08, 0x98, 
//0xF3, 0x04, 0x06, 0x86, 0xF4, 0x03, 0x00, 0x00, 0x00, 0x12, 0x00, 0x00, 0x00, 0x00, 0x00, 0x22, 0x00, 
//0x00, 0x00, 0x86, 0x8C, 0x3D, 0x3F, 0x07, 0xF8, 0x11, 0x43, 0x7D, 0x18, 0xF5, 0xC0, 0x00, 0x00, 0x00, 
//0x00, 0xE5, 0x66, 0xC4, 0x40, 0x60, 0x16, 0x5E, 0x41, 0x39, 0x39, 0x39, 0x00, 0x1A, 0x16, 0x16, 0x0F, 
//0x03, 0x00, 0x03, 0xF3
//};

uint32_t crc32_val= 0x972BEE5F;

/* FunctionPrototypes --------------------------------------------------------*/
uint32_t crc_test(void);


/* Functions -----------------------------------------------------------------*/

/******************************************************************************
 * 功能：硬件CRC32模块初始化函数
 * 输入：无          
 * 返回：
 * 说明：
 *
 *****************************************************************************/
void bsp_crc_init(void)
{
  CrcHandle.Instance = CRC;

  CrcHandle.Init.DefaultPolynomialUse    = DEFAULT_POLYNOMIAL_ENABLE;
  CrcHandle.Init.DefaultInitValueUse     = DEFAULT_INIT_VALUE_DISABLE;
	CrcHandle.Init.InitValue							 = 0x00000000;

  CrcHandle.Init.InputDataInversionMode  = CRC_INPUTDATA_INVERSION_BYTE;
  CrcHandle.Init.OutputDataInversionMode = CRC_OUTPUTDATA_INVERSION_ENABLE;
  CrcHandle.InputDataFormat              = CRC_INPUTDATA_FORMAT_BYTES;

  if (HAL_CRC_Init(&CrcHandle) != HAL_OK)
  {
    syserr_print("CRC Initialization Error!\r\n");
  }
	
	//crc_test();
}


//uint32_t crc_test(void)
//{
//	uint32_t crc= 0;
//	
//	crc= hw_crc32_calc((void*)test_dat, sizeof(test_dat));

//	if(crc == crc32_val){
//		return 1;
//	}else{
//		return 0;
//	}
//}

/******************************************************************************
 * 功能：硬件CRC32计算函数, 多项式： 0x4C11DB7
 * 输入：无          
 * 返回：
 * 说明：输入数据格式为8位数据，数据长度指字节数
 *****************************************************************************/
uint32_t hw_crc32_calc(uint8_t* buf, uint32_t len)
{	
	return HAL_CRC_Calculate(&CrcHandle, (void*)buf, len);	
}







void HAL_CRC_MspInit(CRC_HandleTypeDef *hcrc)
{
  /* CRC Peripheral clock enable */
  __HAL_RCC_CRC_CLK_ENABLE();
}

/**
  * @brief CRC MSP De-Initialization
  *        This function freeze the hardware resources used in this example:
  *          - Disable the Peripherals clock
  * @param hcrc: CRC handle pointer
  * @retval None
  */
void HAL_CRC_MspDeInit(CRC_HandleTypeDef *hcrc)
{
  /* Enable CRC reset state */
  __HAL_RCC_CRC_FORCE_RESET();

  /* Release CRC from reset state */
  __HAL_RCC_CRC_RELEASE_RESET();
}




/*********************************** END OF FILE *************************************/
