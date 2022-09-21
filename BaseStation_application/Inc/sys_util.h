/**************************************************************************************
 *
 * 文件描述：
 * 创建日期：
 *
 * 备注：
 *
 **************************************************************************************
 */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __SYS_UTIL_H
#define __SYS_UTIL_H

/* Includes ------------------------------------------------------------------*/
#include "stm32h7xx_hal.h"

/* Exported_Macros -----------------------------------------------------------*/



/* Exported_Types ------------------------------------------------------------*/
typedef struct{
	uint32_t videotran_match : 1;			// 图传对频标志，0：非对频；1：对频中；
	uint32_t videotran_mode : 1;			// 图传模式，0：主模式；1：从模式；
	uint32_t videotran_con_ok : 1;		// 图传连接状态，0：未连接；1：已连接；
	uint32_t videotran_stat_update : 1;	// 图传状态更新标志
}sys_flag_t;



typedef struct{
	sys_flag_t	flag;
	uint16_t match_led_on_tim;			// 图传对频LED开启时长，单位ms
	uint16_t match_led_off_tim;			// 图传对频LED关闭时长，单位ms
	uint16_t match_led_tim_period;	// 图传对频LED闪烁周期，单位ms
}sys_info_t;

extern sys_info_t sys_info;
/* Exported_Variables --------------------------------------------------------*/



/* Exported_Functions --------------------------------------------------------*/


























#endif
