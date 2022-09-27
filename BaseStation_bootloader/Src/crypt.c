/******************** (C) COPYRIGHT 2015 Autel Robot.,LTD ***********************
* File Name         : crypt.h
* Author            : fangz
* Date First Issued : 2015/07/15
* Description       : Protocol 协议应用层
********************************************************************************
* History:
*   1. 25/08/2015, ver. 1.0.0, by fangz,
*       a. 创建文件
*
*   2.
*
*******************************************************************************/
#if 0
/* Includes ------------------------------------------------------------------------------*/
#include "crypt.h"

/* Private typedef -----------------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------------------*/

/* Initialization Vector, used only in non-ECB modes */
const uint8_t g_iv_buf[CRL_AES_BLOCK] ={
    0xf0 , 0xf1 , 0xf2 , 0xf3 , 0xf4 , 0xf5 , 0xf6 , 0xf7,
    0xf8 , 0xf9 , 0xfa , 0xfb , 0xfc , 0xfd , 0xfe , 0xff
};

const uint8_t g_key_buf[CRL_AES128_KEY] =
{
    0x2b, 0x7e, 0x15, 0x16, 0x28, 0xae, 0xd2, 0xa6,
    0xab, 0xf7, 0x15, 0x88, 0x09, 0xcf, 0x4f, 0x3c
};


/* Private function prototypes -----------------------------------------------------------*/

/* Private functions ---------------------------------------------------------------------*/

/* Public functions ----------------------------------------------------------------------*/

/******************************************************************************/
/* AES加密模块初始化
函数名: crypt_init
入  参: None
出  参: None
返回值: None
修改人: fangz
日  期: 2015.08.25
*//****************************************************************************/
void crypt_init(void)
{
	/* DeInitialize STM32 Cryptographic Library */
	Crypto_DeInit();
}


/******************************************************************************/
/* AES加密
函数名: crypt_aes_encrypt
入  参: None
出  参: None
返回值: None
修改人: fangz
日  期: 2015.08.25
*//****************************************************************************/
int crypt_aes_encrypt(aes_mode_e mode,
						uint8_t *input_message,
						uint32_t input_length,
						uint8_t *aes128_key,
						uint8_t *output_message,
						uint32_t *output_length)
{
	AESCTRctx_stt AESctx;

	uint32_t error_status = AES_SUCCESS;

	int32_t outputLength = 0;

	/* Set flag field to default value */
	AESctx.mFlags = E_SK_DEFAULT;

	/* Set key size to 16 (corresponding to AES-128) */
	AESctx.mKeySize = 16;

	/* Set iv size field to IvLength*/
	AESctx.mIvSize = sizeof(g_iv_buf);

	if(mode == AES_CTR){
		/* Initialize the operation, by passing the key.
		* Third parameter is NULL because CTR doesn't use any IV */
		error_status = AES_CTR_Encrypt_Init(&AESctx, aes128_key, g_iv_buf);

		/* check for initialization errors */
		if (error_status == AES_SUCCESS){
			/* Encrypt Data */
			error_status = AES_CTR_Encrypt_Append(&AESctx, input_message, input_length,
												  output_message, &outputLength);
			if (error_status == AES_SUCCESS){
				*output_length = outputLength;
				/* Do the Finalization */
				error_status = AES_CTR_Encrypt_Finish(&AESctx, output_message + *output_length, &outputLength);
				/* Add data written to the information to be returned */
				*output_length += outputLength;
			}
		}
	}else if(mode == AES_CBC){
		error_status = AES_CBC_Encrypt_Init(&AESctx, aes128_key, g_iv_buf);
		if (error_status == AES_SUCCESS){
			error_status = AES_CBC_Encrypt_Append(&AESctx, input_message, input_length,
												  output_message, &outputLength);
			if (error_status == AES_SUCCESS){
				*output_length = outputLength;
				error_status = AES_CBC_Encrypt_Finish(&AESctx, output_message + *output_length, &outputLength);
				*output_length += outputLength;
			}
		}
	}else if(mode == AES_ECB){
		error_status = AES_ECB_Encrypt_Init(&AESctx, aes128_key, NULL);
		if (error_status == AES_SUCCESS){
			error_status = AES_ECB_Encrypt_Append(&AESctx, input_message, input_length,
												  output_message, &outputLength);
			if (error_status == AES_SUCCESS){
				*output_length = outputLength;
				error_status = AES_ECB_Encrypt_Finish(&AESctx, output_message + *output_length, &outputLength);
				*output_length += outputLength;
			}
		}
	}else{
		return AES_ERR_BAD_PARAMETER;
	}

	return error_status;
}

/******************************************************************************/
/* AES解密
函数名: crypt_aes_decrypt
入  参: None
出  参: None
返回值: None
修改人: fangz
日  期: 2015.08.25
*//****************************************************************************/
int crypt_aes_decrypt(aes_mode_e mode,
						uint8_t *input_message,
						uint32_t input_length,
						uint8_t *aes128_key,
						uint8_t *output_message,
						uint32_t *output_length)
{
	AESCBCctx_stt AESctx;

	uint32_t error_status = AES_SUCCESS;

	int32_t outputLength = 0;

	/* Set flag field to default value */
	AESctx.mFlags = E_SK_DEFAULT;

	/* Set key size to 16 (corresponding to AES-128) */
	AESctx.mKeySize = 16;

	/* Set iv size field to IvLength*/
	AESctx.mIvSize = sizeof(g_iv_buf);

	if(mode == AES_CTR){
		/* Initialize the operation, by passing the key.
		* Third parameter is NULL because CTR doesn't use any IV */
		error_status = AES_CTR_Decrypt_Init(&AESctx, aes128_key, g_iv_buf);
		if (error_status == AES_SUCCESS){
			/* Decrypt Data */
			error_status = AES_CTR_Decrypt_Append(&AESctx, input_message, input_length,
												  output_message, &outputLength);

			if (error_status == AES_SUCCESS){
				/* Write the number of data written*/
				*output_length = outputLength;
				/* Do the Finalization */
				error_status = AES_CTR_Decrypt_Finish(&AESctx,
				                          output_message + *output_length, &outputLength);
				/* Add data written to the information to be returned */
				*output_length += outputLength;
			}
		}
	}else if(mode == AES_CBC){
		error_status = AES_CBC_Decrypt_Init(&AESctx, aes128_key, g_iv_buf);
		if (error_status == AES_SUCCESS){
			error_status = AES_CBC_Decrypt_Append(&AESctx, input_message, input_length,
			                                            output_message, &outputLength);
			if(error_status == AES_SUCCESS){
				/* Write the number of data written*/
				*output_length = outputLength;
				/* Do the Finalization */
				error_status = AES_CBC_Decrypt_Finish(&AESctx,
				                  output_message + *output_length, &outputLength);
				/* Add data written to the information to be returned */
				*output_length += outputLength;
			}
		}
	}else if(mode == AES_ECB){
		error_status = AES_ECB_Decrypt_Init(&AESctx, aes128_key, NULL);
		if (error_status == AES_SUCCESS){
			error_status = AES_ECB_Decrypt_Append(&AESctx, input_message, input_length,
			                                            output_message, &outputLength);
			if(error_status == AES_SUCCESS){
				/* Write the number of data written*/
				*output_length = outputLength;
				/* Do the Finalization */
				error_status = AES_ECB_Decrypt_Finish(&AESctx,
				                  output_message + *output_length, &outputLength);
				/* Add data written to the information to be returned */
				*output_length += outputLength;
			}
		}
	}else {
		return AES_ERR_BAD_PARAMETER;
	}

	return error_status;
}

#endif
/*--------------------------------- The End ----------------------------------------------*/



