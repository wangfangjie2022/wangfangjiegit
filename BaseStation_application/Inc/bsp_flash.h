/**************************************************************************************
 *
 * 文件描述：Flash读写相关接口
 * 创建日期：
 *
 * 备注：
 *
 **************************************************************************************
 */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __BSP_FLASH_H
#define __BSP_FLASH_H

/* Includes ------------------------------------------------------------------*/
#include "stm32h7xx_hal.h"
#include "Sys_cfg.h"

/* Exported_Macros -----------------------------------------------------------*/


/* Base address of the Flash sectors Bank 1 */
#define ADDR_FLASH_SECTOR_0_BANK1     ((uint32_t)0x08000000) /* Base @ of Sector 0, 128 Kbytes */
#define ADDR_FLASH_SECTOR_1_BANK1     ((uint32_t)0x08020000) /* Base @ of Sector 1, 128 Kbytes */
#define ADDR_FLASH_SECTOR_2_BANK1     ((uint32_t)0x08040000) /* Base @ of Sector 2, 128 Kbytes */
#define ADDR_FLASH_SECTOR_3_BANK1     ((uint32_t)0x08060000) /* Base @ of Sector 3, 128 Kbytes */
#define ADDR_FLASH_SECTOR_4_BANK1     ((uint32_t)0x08080000) /* Base @ of Sector 4, 128 Kbytes */
#define ADDR_FLASH_SECTOR_5_BANK1     ((uint32_t)0x080A0000) /* Base @ of Sector 5, 128 Kbytes */
#define ADDR_FLASH_SECTOR_6_BANK1     ((uint32_t)0x080C0000) /* Base @ of Sector 6, 128 Kbytes */
#define ADDR_FLASH_SECTOR_7_BANK1     ((uint32_t)0x080E0000) /* Base @ of Sector 7, 128 Kbytes */

/* Base address of the Flash sectors Bank 2 */
#define ADDR_FLASH_SECTOR_0_BANK2     ((uint32_t)0x08100000) /* Base @ of Sector 0, 128 Kbytes */
#define ADDR_FLASH_SECTOR_1_BANK2     ((uint32_t)0x08120000) /* Base @ of Sector 1, 128 Kbytes */
#define ADDR_FLASH_SECTOR_2_BANK2     ((uint32_t)0x08140000) /* Base @ of Sector 2, 128 Kbytes */
#define ADDR_FLASH_SECTOR_3_BANK2     ((uint32_t)0x08160000) /* Base @ of Sector 3, 128 Kbytes */
#define ADDR_FLASH_SECTOR_4_BANK2     ((uint32_t)0x08180000) /* Base @ of Sector 4, 128 Kbytes */
#define ADDR_FLASH_SECTOR_5_BANK2     ((uint32_t)0x081A0000) /* Base @ of Sector 5, 128 Kbytes */
#define ADDR_FLASH_SECTOR_6_BANK2     ((uint32_t)0x081C0000) /* Base @ of Sector 6, 128 Kbytes */
#define ADDR_FLASH_SECTOR_7_BANK2     ((uint32_t)0x081E0000) /* Base @ of Sector 7, 128 Kbytes */

/* Exported_Types ------------------------------------------------------------*/



/* Exported_Variables --------------------------------------------------------*/



/* Exported_Functions --------------------------------------------------------*/
void flash_init(void);
void FlashWrite_SetAppStartAddr(void);
int FlashWrite_AppWords(uint32_t address, const void *buf, uint32_t bytes);
int FlashWrite_ChkAppRemainWords(void);
int FlashWrite_BootCfg(uint32_t address, const void *buf, uint32_t bytes);
int FlashWrite_CfgInfo(uint32_t address, const void *buf, uint32_t bytes);
void FlashRead(uint32_t addr, uint8_t *pdata, uint32_t size);
int32_t FlashErase_AppSectors(void);
int32_t FlashErase_BootCfgSectors(void);
int32_t FlashErase_Cfg1Sectors(void);
int32_t FlashErase_Cfg2Sectors(void);

















#endif
