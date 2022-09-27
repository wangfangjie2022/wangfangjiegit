/**************************************************************************************
 *
 * �ļ�������Flash��д��ؽӿ�
 * �������ڣ�
 *
 * ��ע��
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
 * ���ܣ�
 * ���룺��          
 * ���أ�
 * ˵����
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
 * ���ܣ�Flash�жϺ���
 * ���룺��          
 * ���أ�
 * ˵����
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
 * ���ܣ���ʼ����ǰ����ʼ��ַ���г�ʼ����
 * ���룺��          
 * ���أ�
 * ˵����
 *
 *****************************************************************************/
void FlashWrite_SetAppStartAddr(void)
{
  FlashWrAddr= FLASH_APPLICATION_ADDR;
  RemainCnt= 0;
}


/******************************************************************************
 * ���ܣ���������д�뵽flash app����
 * ���룺address   ---flashĿ�ĵ�ַ��������4byte���룬��ǰ��2��д���ַ�������ᡣ
 *       *buf      ---ramԴ��ַ��������4byte���롣
 *       bytes     ---��д���ֽ�����������4�ı����� 
 * ���أ�����ֵ>0��ʾ�ɹ�������Ϊʧ�ܡ�
 * ˵����
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
 * ���ܣ��������ʱ��ʣ��Ļ�������д�뵽flash�У�����32byte�Ľ����Ϊ0xFF��
 * ���룺��          
 * ���أ�
 * ˵����H743��flash��������������д�룬ͬһ������ڶ���д��ᵼ��ECC����
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
 * ���ܣ���boot��Ϣд�뵽�ض���flash����
 * ���룺address   ---flashĿ�ĵ�ַ��������4byte���롣
 *       *buf      ---ramԴ��ַ��������4byte���롣
 *       bytes     ---��д���ֽ�����������4�ı�����         
 * ���أ�
 * ˵����
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
 * ���ܣ���config��Ϣд�뵽�ض���flash����
 * ���룺address   ---flashĿ�ĵ�ַ��������4byte���롣
 *       *buf      ---ramԴ��ַ��������4byte���롣
 *       bytes     ---��д���ֽ�����������4�ı�����         
 * ���أ�
 * ˵����
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
 * ��������: ��ȡflash�е�����
 * �������: addr: flash��ַ
 *           pdata: ��Ŷ������ݵ�Ŀ�ĵ�
 *           size��Ҫ��ȡ���ֽ�����ע�������4�ı�����
 * �������: 
 * �� �� ֵ: 
 * ����˵��: 
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
 * ��������: ����flash N������
 * �������: FirstSector: flash������ʼ������0-7
 *           NbOfSectors: Ҫ��������������С��8
 *           Banks��FLASH_BANK_1 �� FLASH_BANK_2
 * �������: 
 * �� �� ֵ: 0:�����ɹ�   ��0:����ʧ��
 * ����˵��: 
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
 * ��������: ����flash�е�App����
 * �������: 
 * �������: 
 * �� �� ֵ: 0:�����ɹ�   ��0:����ʧ��
 * ����˵��: 
 *================================================================================*/
int32_t FlashErase_AppSectors(void)
{
  uint32_t FirstSector, NbOfSectors;
  
  FirstSector = GetSector(FLASH_APPLICATION_ADDR);
  NbOfSectors = GetSector(FLASH_APP_END_ADDR) - FirstSector + 1;
  
  return FlashErase_NSectors(FirstSector, NbOfSectors, FLASH_BANK_1); 
}


/*================================================================================*
 * ��������: ����flash�е�boot��������
 * �������: 
 * �������: 
 * �� �� ֵ: 0:�����ɹ�   ��0:����ʧ��
 * ����˵��: 
 *================================================================================*/
int32_t FlashErase_BootCfgSectors(void)
{
  uint32_t FirstSector, NbOfSectors;
  
  FirstSector = GetSector(FLASH_BOOTINFO_ADDR);
  NbOfSectors = 1;
  
  return FlashErase_NSectors(FirstSector, NbOfSectors, FLASH_BANK_1);  
}


/*================================================================================*
 * ��������: ����flash�еĲ�������1����
 * �������: 
 * �������: 
 * �� �� ֵ: 0:�����ɹ�   ��0:����ʧ��
 * ����˵��: 
 *================================================================================*/
int32_t FlashErase_Cfg1Sectors(void)
{
  uint32_t FirstSector, NbOfSectors;
  
  FirstSector = GetSector(FLASH_CFGINFO_ADDR1);
  NbOfSectors = 1;
  
  return FlashErase_NSectors(FirstSector, NbOfSectors, FLASH_BANK_2);  
}


/*================================================================================*
 * ��������: ����flash�еĲ�������2����
 * �������: 
 * �������: 
 * �� �� ֵ: 0:�����ɹ�   ��0:����ʧ��
 * ����˵��: 
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
 * ��������: ͨ��flash��ַ��ȡflash������
 * �������: Address��flash��ַ
 * �������: 
 * �� �� ֵ: ����������0-7
 * ����˵��: 
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
