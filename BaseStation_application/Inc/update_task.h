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
#include "includes.h"
	 
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
  ACK_TYPE_GENERAL_ERR,
  ACK_TYPE_BUSY_ERR,
  ACK_TYPE_PARAM_ERR,
  ACK_TYPE_PARSEMSG_ERR,
  ACK_TYPE_UNKNOWNMSG_ERR,
  ACK_TYPE_SUBSCRIBEMORE_ERR,
}EN_UPDATE_ACKTYPE;


extern uint8_t msg_channel;



void update_comm_running();
void AddUpdateTask(void);
void UpdateTask(void);
void boot_info_init(void);

int8_t WifiUpgrade(uint8_t chan, alink_message_head_t *msg);
int32_t DevDSP_AlinkMsgParse(uint8_t chan, alink_message_head_t *pMsg);
int32_t UpdateTaskInit(void);
int32_t UpdateTaskUninit(void);
 


#ifdef __cplusplus
}
#endif
#endif



/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/


