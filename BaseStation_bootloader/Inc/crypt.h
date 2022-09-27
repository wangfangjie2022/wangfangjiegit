/******************** (C) COPYRIGHT 2015 Autel Robot.,LTD ***********************
* File Name         : crypt.h
* Author            : fangz
* Date First Issued : 2015/07/15
* Description       : crypt 头文件
********************************************************************************
* History:
*   1. 25/08/2015, ver. 1.0.0, by fangz,
*       a. 创建文件
*
*   2.
*
*******************************************************************************/
#ifndef __CRYPT_H__
#define __CRYPT_H__

/* Includes ------------------------------------------------------------------------------*/
#include "crypto.h"

/* Exported macros -----------------------------------------------------------------------*/
#define DATA_BLOCK_SIZE		16

/* Exported typedef ----------------------------------------------------------------------*/
typedef enum {
	AES_ECB,
	AES_CBC,
	AES_CTR,
	AES_GCM,
	AES_KEY,
	AES_CCM,
	AES_CMAC
}aes_mode_e;

/* Globle viables */
extern const uint8_t g_key_buf[CRL_AES128_KEY];
extern const uint8_t g_iv_buf[CRL_AES_BLOCK];

/* Exported functions --------------------------------------------------------------------*/
extern void crypt_init(void);
extern int crypt_aes_encrypt(aes_mode_e mode,
						uint8_t *input_message,
						uint32_t input_length,
						uint8_t *aes128_key,
						uint8_t *output_message,
						uint32_t *output_length);
extern int crypt_aes_decrypt(aes_mode_e mode,
						uint8_t *input_message,
						uint32_t input_length,
						uint8_t *aes128_key,
						uint8_t *output_message,
						uint32_t *output_length);
#endif /*__CRYPT_H__*/
/*--------------------------------- The End ----------------------------------------------*/
