#ifndef __SYS_CFG_H
#define __SYS_CFG_H

#include "stdint.h"
#include "stm32h7xx_hal.h"



#define     CUR_LOADER_VERSION                  0x05000000
#define     CUR_HD_VERSION                      0x05000000
#define     ALINK_CUR_VERSION                   0x010C0100

#define     MAGIC_VALUE						              0xBEEF1234
#define     BOOT_UPDATE_FLAG					          0x12345678
#define     RC_UPDATE_FLAG                      0x12345600
#define     RESET_TO_BOOT_FLAG                  0x11223344

#define     RAM_BASE_ADDR                       0x24000000
#define     RAM_ATTRIBUTE_SIZE                  0x00000000
#define     RAM_VECTORTABLE_SIZE                0x000000C0

/*------------------FLASH------------------------------------------------------*/
#define     FLASH_BASE_ADDR                     0x08000000
#define     FLASH_END_ADDR                      0x081FFFFF

/* Boot Address 128K */        //(128K)
#define     FLASH_BOOTLOADER_ADDR               0x08000000
/* APP Info Address 128K */    //(128K)   
#define     FLASH_BOOTINFO_ADDR                 0x08020000

/* APP Address 512K */         //(512K)
#define     FLASH_APPLICATION_ADDR              0x08040000
#define     FLASH_APP_END_ADDR                  0x080DFFFF
#define     FLASH_APP_SIZE                      (1+FLASH_APP_END_ADDR - FLASH_APPLICATION_ADDR)	 
#define     FLASH_PAGE_SIZE                     ((uint32_t)0x20000)

/* Config Info Address 128K*/  //(128K)
//#define     FLASH_CFGINFO_ADDR1                 0x081C0000
/* Config Info Address 128K*/  //(128K)
#define     FLASH_CFGINFO_ADDR1                 0x081E0000


#define 		SERIAL_NUM_LEN                      96	 
#define     pBOOTCONFIG		                      ((boot_config_t *)FLASH_BOOTINFO_ADDR) 
#define     DATA_BLOCK_SIZE		                  16	
#define     BOOT_BLOCK_SIZE			               	240 /* 对下载的数据分块处理（如：加解密、写进Flash） */


#define TIMOUT_PACKEGEWrite			    ((uint16_t)8000)      //((uint16_t)2000)
#define PACKEGE_RetryTimes			    ((uint16_t)3)         //((uint16_t)3)
#define PACKEGE_Size				        ((uint16_t)240)       //((uint16_t)240)
#define TIMOUT_EraseFireware		    ((uint16_t)8)         //((uint16_t)4)
#define TIMOUT_ChkCRC				        ((uint16_t)5)         //((uint16_t)5)
#define TIMOUT_AppGo				        ((uint16_t)5)         //((uint16_t)5)
#define TIMOUT_EnterBoot			      ((uint16_t)4)         //((uint16_t)2)
#define TIMOUT_other				        ((uint16_t)2000)      //((uint16_t)500)



#pragma pack(1)
typedef struct {
	uint32_t magic;				    /* 													*/
	uint32_t device_id;			  /* 设备ID，用于区分不同的设备，具有唯一性			*/
	uint32_t hw_version;		  /* 硬件版本号										*/
	uint32_t boot_version;		/* Bootloader软件版本号								*/
	uint32_t boot_size;				/* 保留												*/
	uint32_t boot_crc32;			/* 保留												*/
	uint32_t rev3;				    /* 保留												*/
	uint32_t app_version;		  /* App软件版本号									*/
	uint32_t app_size;			  /* App大小（字节）									*/
	uint32_t app_crc32;			  /* App区CRC32检验值									*/
	uint32_t min_hw_version;	/* 固件支持的最低硬件版本号（包含）					*/
	uint32_t max_hw_version;	/* 固件支持的最高硬件版本号	（包含）				*/
	uint8_t  firm[64];			  /* 生产厂商信息										*/
	uint8_t  sn[96];			    /* 产品序列号										*/
} boot_config_t;
#pragma pack()



#define   ENTER_CRITICAL()                __disable_fault_irq
#define   EXIT_CRITICAL()		              __enable_fault_irq

#define __DISABLE_IRQ()                   __set_PRIMASK(1)
#define __ENABLE_IRQ()                    __set_PRIMASK(0)



#define   GET_CURTICK                     nSysTick
#define   GET_PASTTICK(tick)              (uint32_t)((nSysTick >= tick)? (nSysTick-tick) : (0xffffffff - tick + nSysTick))

#define   GET_TIMESTAMP                   nSysTimestamp
#define   GET_TIMESTAMP_PASTTICK(tick)    (uint32_t)(nSysTimestamp-tick)



extern volatile uint32_t nSysTick;
extern volatile uint64_t nSysTimestamp;
extern __IO uint32_t gGotoLoaderFlag;
extern __IO uint32_t gLoderResetFlag;
//extern __IO uint32_t gBatPercent;


uint8_t Sys_delay_ms(uint32_t* pvar,uint32_t time);
void delay_ms(uint32_t t);

#endif
