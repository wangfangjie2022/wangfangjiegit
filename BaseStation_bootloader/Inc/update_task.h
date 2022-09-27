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
#ifndef _UPDATE_TASK_H_
#define _UPDATE_TASK_H_

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "Sys_cfg.h"

	 
typedef struct
{
    uint32_t file_size;
    uint32_t download_count;    //下载数据长度
    uint8_t download_buf[BOOT_BLOCK_SIZE];
    uint8_t decryp_buf[BOOT_BLOCK_SIZE];
    uint8_t upgrade_allow_flag;             //遥控控制板升级标志   0不允许    1允许
}boot_params_t;


typedef enum
{
    ACK_TYPE_SUCCESS = 0,
    ACK_TYPE_GENERAL_ERR = 1,
    ACK_TYPE_BUSY_ERR = 2,
    ACK_TYPE_PARAM_ERR = 3,
    ACK_TYPE_PARSEMSG_ERR = 4,
    ACK_TYPE_UNKNOWNMSG_ERR = 5,
    ACK_TYPE_SUBSCRIBEMORE_ERR = 6,
	  ACK_TYPE_NOTSUP_ERR = 8,
    ACK_TYPE_FILE_MATCH_ERR = 9,
}EN_UPDATE_ACKTYPE;


extern boot_config_t g_boot_cfg;
extern uint8_t msg_channel;


uint8_t Get_Is_Update(void);
void AddUpdateTask(void);
int32_t UpdateTaskInit(void);
void UpdateTask(void);
int32_t UpdateTaskUninit(void);
uint8_t Get_Is_Update(void);
void boot_info_init(void);
int32_t CheckAppCode(void);


#ifdef __cplusplus
}
#endif
#endif /*__ adc_H */

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/


