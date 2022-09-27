/**************************************************************************************
 *
 * 文件描述：Flash读写相关接口
 * 创建日期：
 *
 * 备注：
 *
 **************************************************************************************
 */

/* Includes ------------------------------------------------------------------*/
#include "bsp_flash.h"
#include "Sys_cfg.h"
#include "stm32_hal_legacy.h"
#include <string.h>

/* Private_Defines -----------------------------------------------------------*/
#define	FLASH_TIMEOUT_VALUE			5000


/* Private_TypesDefinitions --------------------------------------------------*/



/* Private_Variables ---------------------------------------------------------*/
static FLASH_EraseInitTypeDef EraseInitStruct;
static uint32_t FlashWord[8];
static uint32_t FlashWrAddr;
static uint16_t RemainCnt=0;


/* FunctionPrototypes --------------------------------------------------------*/
uint32_t GetSector(uint32_t Address);



/* Functions -----------------------------------------------------------------*/

/******************************************************************************
 * 功能：
 * 输入：无          
 * 返回：
 * 说明：
 *
 *****************************************************************************/
void flash_init(void)
{
    HAL_FLASH_Unlock();
    
    __HAL_FLASH_ENABLE_IT(FLASH_IT_SNECCERR_BANK1 | FLASH_IT_DBECCERR_BANK1);
    __HAL_FLASH_ENABLE_IT(FLASH_IT_SNECCERR_BANK2 | FLASH_IT_DBECCERR_BANK2);
    
    HAL_FLASH_Lock();
    
    /* Set FLASH Interrupt to the lowest priority */
    HAL_NVIC_SetPriority(FLASH_IRQn, 15, 0);

    /* Enable USBFS Interrupt */
    HAL_NVIC_EnableIRQ(FLASH_IRQn);
}

void flash_uninit(void)
{
	HAL_NVIC_DisableIRQ(FLASH_IRQn);
}

/******************************************************************************
 * 功能：Flash中断函数
 * 输入：无          
 * 返回：
 * 说明：
 *
 *****************************************************************************/
void FLASH_IRQHandler(void)
{

  HAL_FLASH_IRQHandler();
  
  if(READ_BIT(FLASH->SR1, FLASH_FLAG_ALL_ERRORS_BANK1)){
		__HAL_FLASH_CLEAR_FLAG_BANK1(FLASH_FLAG_ALL_ERRORS_BANK1);
	}

	if(READ_BIT(FLASH->SR2, FLASH_FLAG_ALL_ERRORS_BANK2)){
		__HAL_FLASH_CLEAR_FLAG_BANK2(FLASH_FLAG_ALL_ERRORS_BANK2);
	}
    
}


/******************************************************************************
 * 功能：开始升级前对起始地址进行初始化。
 * 输入：无          
 * 返回：
 * 说明：
 *
 *****************************************************************************/
void FlashWrite_SetAppStartAddr(void)
{
  FlashWrAddr= FLASH_APPLICATION_ADDR;
  RemainCnt= 0;
}


/******************************************************************************
 * 功能：将升级包写入到flash app区域
 * 输入：address   ---flash目的地址，必须是4byte对齐，且前后2次写入地址必须连贯。
 *       *buf      ---ram源地址，必须是4byte对齐。
 *       bytes     ---待写入字节数，必须是4的倍数。 
 * 返回：返回值>0表示成功，否则为失败。
 * 说明：
 *
 *****************************************************************************/
int FlashWrite_AppWords(uint32_t address, const void *buf, uint32_t bytes)
{
	uint32_t *pdata = (uint32_t*)buf;
	int i, len;

	if( (address < FLASH_APPLICATION_ADDR)
		|| (address+bytes > FLASH_APP_END_ADDR) || ((FlashWrAddr+RemainCnt*4)!=address))
	{
		return -1;
	}

	// check addr if aligned to 32bit
	if(((address & 0x03) != 0) || ((bytes & 0x03) != 0)){
		return -1;
	}

	len=bytes/4;
	
	HAL_FLASH_Unlock();

	for(i=0;i<len;i++)
	{
		FlashWord[RemainCnt]=pdata[i];
		if(++RemainCnt==8)
		{
			RemainCnt=0;
			if(HAL_FLASH_Program(FLASH_TYPEPROGRAM_FLASHWORD, FlashWrAddr, (uint32_t)FlashWord) != HAL_OK)
			{
				return -2;
			}
			FlashWrAddr+=32;
		}
	}

	HAL_FLASH_Lock();

	return (bytes);
}


/******************************************************************************
 * 功能：升级完成时将剩余的缓存数据写入到flash中，不足32byte的将填充为0xFF。
 * 输入：无          
 * 返回：
 * 说明：H743的flash，必须擦除后才能写入，同一个区域第二次写入会导致ECC错误。
 *
 *****************************************************************************/
int FlashWrite_ChkAppRemainWords(void)
{
	int i;
	
	if(RemainCnt==0)
	{
		return 0;
	}

	for(i=RemainCnt;i<8;i++)
	{
		FlashWord[i]=0xFFFFFFFF;
	}
	
	
	HAL_FLASH_Unlock();

	if(HAL_FLASH_Program(FLASH_TYPEPROGRAM_FLASHWORD, FlashWrAddr, (uint32_t)FlashWord) != HAL_OK)
	{
		return -2;
	}

	HAL_FLASH_Lock();

	return RemainCnt;
}


/******************************************************************************
 * 功能：将boot信息写入到特定的flash区域。
 * 输入：address   ---flash目的地址，必须是4byte对齐。
 *       *buf      ---ram源地址，必须是4byte对齐。
 *       bytes     ---待写入字节数，必须是4的倍数。         
 * 返回：
 * 说明：
 *
 *****************************************************************************/
int FlashWrite_BootCfg(uint32_t address, const void *buf, uint32_t bytes)
{
	uint32_t *pdata = (uint32_t*)buf;
	int i, len, CntRemain=0;

	if((bytes !=sizeof(boot_config_t)) || !( address >= FLASH_BOOTINFO_ADDR && address <= (FLASH_BOOTINFO_ADDR + 0x20000 - sizeof(boot_config_t) ) ) )
	{
		return -1;
	}
  
  // check addr if aligned to 32bit
	if(((address & 0x03) != 0) || ((bytes & 0x03) != 0)){
		return -1;
	}

	len=bytes/4;
	
	HAL_FLASH_Unlock();

	for(i=0;i<len;i++)
	{
		FlashWord[CntRemain]=pdata[i];
		if(++CntRemain==8)
		{
			CntRemain=0;
			if(HAL_FLASH_Program(FLASH_TYPEPROGRAM_FLASHWORD, address, (uint32_t)FlashWord) != HAL_OK)
			{
				return -2;
			}
			address+=32;
		}
	}

	if(CntRemain>0)
	{
		for(i=CntRemain;i<8;i++)
		{
			FlashWord[i]=0xffffffff;
		}
		
		if(HAL_FLASH_Program(FLASH_TYPEPROGRAM_FLASHWORD, address, (uint32_t)FlashWord) != HAL_OK)
		{
			return -2;
		}
	}
	
	HAL_FLASH_Lock();

	return bytes;
}


/******************************************************************************
 * 功能：将config信息写入到特定的flash区域。
 * 输入：address   ---flash目的地址，必须是4byte对齐。
 *       *buf      ---ram源地址，必须是4byte对齐。
 *       bytes     ---待写入字节数，必须是4的倍数。         
 * 返回：
 * 说明：
 *
 *****************************************************************************/
int FlashWrite_CfgInfo(uint32_t address, const void *buf, uint32_t bytes)
{
	uint32_t *pdata = (uint32_t*)buf;
	int i, len, CntRemain=0;
  
  // check addr if aligned to 32bit
	if((bytes >= 0x20000) || ((address & 0x03) != 0) || ((bytes & 0x03) != 0)){
		return -1;
	}

	len=bytes/4;
	
	HAL_FLASH_Unlock();

	for(i=0;i<len;i++)
	{
		FlashWord[CntRemain]=pdata[i];
		if(++CntRemain==8)
		{
			CntRemain=0;
			if(HAL_FLASH_Program(FLASH_TYPEPROGRAM_FLASHWORD, address, (uint32_t)FlashWord) != HAL_OK)
			{
				return -2;
			}
			address+=32;
		}
	}

	if(CntRemain>0)
	{
		for(i=CntRemain;i<8;i++)
		{
			FlashWord[i]=0xffffffff;
		}
		
		if(HAL_FLASH_Program(FLASH_TYPEPROGRAM_FLASHWORD, address, (uint32_t)FlashWord) != HAL_OK)
		{
			return -2;
		}
	}
	
	HAL_FLASH_Lock();

	return bytes;
}


/*================================================================================*
 * 功能描述: 读取flash中的数据
 * 输入参数: addr: flash地址
 *           pdata: 存放读出数据的目的地
 *           size：要读取的字节数，注意必须是4的倍数。
 * 输出参数: 
 * 返 回 值: 
 * 其他说明: 
 *================================================================================*/
void FlashRead(uint32_t addr, uint8_t *pdata, uint32_t size)
{
  uint32_t i;
  uint32_t *pdw_flash_read = (uint32_t *)addr;
  uint32_t dwTemp;

  while(READ_BIT(FLASH->SR1, FLASH_FLAG_ALL_ERRORS_BANK1)){
		__HAL_FLASH_CLEAR_FLAG_BANK1(FLASH_FLAG_ALL_ERRORS_BANK1);
	}

	while(READ_BIT(FLASH->SR2, FLASH_FLAG_ALL_ERRORS_BANK2)){
		__HAL_FLASH_CLEAR_FLAG_BANK2(FLASH_FLAG_ALL_ERRORS_BANK2);
	}

	HAL_FLASH_Unlock();
  
  for (i=0; i<size; i+=4)
  {
    dwTemp = *pdw_flash_read++;
    pdata[i+0] = (uint8_t)(dwTemp);
    
    if((i+1)>=size)break;
    pdata[i+1] = (uint8_t)(dwTemp>>8);
    
    if((i+2)>=size)break;
    pdata[i+2] = (uint8_t)(dwTemp>>16);
    
    if((i+3)>=size)break;
    pdata[i+3] = (uint8_t)(dwTemp>>24);
  }
  
  HAL_FLASH_Lock();
}


/*================================================================================*
 * 功能描述: 擦除flash N个扇区
 * 输入参数: FirstSector: flash擦除起始扇区，0-7
 *           NbOfSectors: 要擦除的扇区数，小于8
 *           Banks：FLASH_BANK_1 或 FLASH_BANK_2
 * 输出参数: 
 * 返 回 值: 0:擦除成功   非0:擦除失败
 * 其他说明: 
 *================================================================================*/
int32_t FlashErase_NSectors(uint32_t FirstSector, uint32_t NbOfSectors, uint32_t Banks)
{
  uint32_t SECTORError = 0;
  int32_t ret = 0;

  if (NbOfSectors == 0 || NbOfSectors > 8) return -1;
  if (Banks != FLASH_BANK_1 && Banks != FLASH_BANK_2) return -1;
  
  while(READ_BIT(FLASH->SR1, FLASH_FLAG_ALL_ERRORS_BANK1)){
		__HAL_FLASH_CLEAR_FLAG_BANK1(FLASH_FLAG_ALL_ERRORS_BANK1);
	}

	while(READ_BIT(FLASH->SR2, FLASH_FLAG_ALL_ERRORS_BANK2)){
		__HAL_FLASH_CLEAR_FLAG_BANK2(FLASH_FLAG_ALL_ERRORS_BANK2);
	}

  HAL_FLASH_Unlock();

  EraseInitStruct.TypeErase     = FLASH_TYPEERASE_SECTORS;
  EraseInitStruct.VoltageRange  = FLASH_VOLTAGE_RANGE_3;
  EraseInitStruct.Banks         = FLASH_BANK_1;
  EraseInitStruct.Sector        = FirstSector;
  EraseInitStruct.NbSectors     = NbOfSectors;
  
  if (HAL_OK != HAL_FLASHEx_Erase(&EraseInitStruct, &SECTORError))
  {
    ret = -1;
  }
  if (HAL_OK != FLASH_WaitForLastOperation(FLASH_TIMEOUT_VALUE, Banks)){
		ret = -1;
	}
  HAL_FLASH_Lock();
  return ret;  
      
}


/*================================================================================*
 * 功能描述: 擦除flash中的App区域
 * 输入参数: 
 * 输出参数: 
 * 返 回 值: 0:擦除成功   非0:擦除失败
 * 其他说明: 
 *================================================================================*/
int32_t FlashErase_AppSectors(void)
{
  uint32_t FirstSector, NbOfSectors;
  
  FirstSector = GetSector(FLASH_APPLICATION_ADDR);
  NbOfSectors = GetSector(FLASH_APP_END_ADDR) - FirstSector + 1;
  
  return FlashErase_NSectors(FirstSector, NbOfSectors, FLASH_BANK_1); 
}


/*================================================================================*
 * 功能描述: 擦除flash中的boot配置区域
 * 输入参数: 
 * 输出参数: 
 * 返 回 值: 0:擦除成功   非0:擦除失败
 * 其他说明: 
 *================================================================================*/
int32_t FlashErase_BootCfgSectors(void)
{
  uint32_t FirstSector, NbOfSectors;
  
  FirstSector = GetSector(FLASH_BOOTINFO_ADDR);
  NbOfSectors = 1;
  
  return FlashErase_NSectors(FirstSector, NbOfSectors, FLASH_BANK_1);  
}


/*================================================================================*
 * 功能描述: 擦除flash中的参数配置1区域
 * 输入参数: 
 * 输出参数: 
 * 返 回 值: 0:擦除成功   非0:擦除失败
 * 其他说明: 
 *================================================================================*/
int32_t FlashErase_Cfg1Sectors(void)
{
  uint32_t FirstSector, NbOfSectors;
  
  FirstSector = GetSector(FLASH_CFGINFO_ADDR1);
  NbOfSectors = 1;
  
  return FlashErase_NSectors(FirstSector, NbOfSectors, FLASH_BANK_2);  
}


/*================================================================================*
 * 功能描述: 擦除flash中的参数配置2区域
 * 输入参数: 
 * 输出参数: 
 * 返 回 值: 0:擦除成功   非0:擦除失败
 * 其他说明: 
 *================================================================================*/
//int32_t FlashErase_Cfg2Sectors(void)
//{
//  uint32_t FirstSector, NbOfSectors;
//  
//  FirstSector = GetSector(FLASH_CFGINFO_ADDR2);
//  NbOfSectors = 1;
//  
//  return FlashErase_NSectors(FirstSector, NbOfSectors, FLASH_BANK_2);
//}


/*================================================================================*
 * 功能描述: 通过flash地址获取flash扇区号
 * 输入参数: Address：flash地址
 * 输出参数: 
 * 返 回 值: 返回扇区号0-7
 * 其他说明: 
 *================================================================================*/
uint32_t GetSector(uint32_t Address)
{
  uint32_t sector = 0;
  
  if(((Address < ADDR_FLASH_SECTOR_1_BANK1) && (Address >= ADDR_FLASH_SECTOR_0_BANK1)) || \
     ((Address < ADDR_FLASH_SECTOR_1_BANK2) && (Address >= ADDR_FLASH_SECTOR_0_BANK2)))    
  {
    sector = FLASH_SECTOR_0;  
  }
  else if(((Address < ADDR_FLASH_SECTOR_2_BANK1) && (Address >= ADDR_FLASH_SECTOR_1_BANK1)) || \
          ((Address < ADDR_FLASH_SECTOR_2_BANK2) && (Address >= ADDR_FLASH_SECTOR_1_BANK2)))    
  {
    sector = FLASH_SECTOR_1;  
  }
  else if(((Address < ADDR_FLASH_SECTOR_3_BANK1) && (Address >= ADDR_FLASH_SECTOR_2_BANK1)) || \
          ((Address < ADDR_FLASH_SECTOR_3_BANK2) && (Address >= ADDR_FLASH_SECTOR_2_BANK2)))    
  {
    sector = FLASH_SECTOR_2;  
  }
  else if(((Address < ADDR_FLASH_SECTOR_4_BANK1) && (Address >= ADDR_FLASH_SECTOR_3_BANK1)) || \
          ((Address < ADDR_FLASH_SECTOR_4_BANK2) && (Address >= ADDR_FLASH_SECTOR_3_BANK2)))    
  {
    sector = FLASH_SECTOR_3;  
  }
  else if(((Address < ADDR_FLASH_SECTOR_5_BANK1) && (Address >= ADDR_FLASH_SECTOR_4_BANK1)) || \
          ((Address < ADDR_FLASH_SECTOR_5_BANK2) && (Address >= ADDR_FLASH_SECTOR_4_BANK2)))    
  {
    sector = FLASH_SECTOR_4;  
  }
  else if(((Address < ADDR_FLASH_SECTOR_6_BANK1) && (Address >= ADDR_FLASH_SECTOR_5_BANK1)) || \
          ((Address < ADDR_FLASH_SECTOR_6_BANK2) && (Address >= ADDR_FLASH_SECTOR_5_BANK2)))    
  {
    sector = FLASH_SECTOR_5;  
  }
  else if(((Address < ADDR_FLASH_SECTOR_7_BANK1) && (Address >= ADDR_FLASH_SECTOR_6_BANK1)) || \
          ((Address < ADDR_FLASH_SECTOR_7_BANK2) && (Address >= ADDR_FLASH_SECTOR_6_BANK2)))    
  {
    sector = FLASH_SECTOR_6;  
  }
  else if(((Address < ADDR_FLASH_SECTOR_0_BANK2) && (Address >= ADDR_FLASH_SECTOR_7_BANK1)) || \
          ((Address < FLASH_END_ADDR) && (Address >= ADDR_FLASH_SECTOR_7_BANK2)))
  {
     sector = FLASH_SECTOR_7;  
  }
  else
  {
    sector = FLASH_SECTOR_7;
  }

  return sector;
}








/*********************************** END OF FILE *************************************/
