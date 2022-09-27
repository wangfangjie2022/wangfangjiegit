/*================================================================================*
 * Copyright(c) 2015-2017, Autel Intelligent Technology Corp., Ltd
 * All rights reserved
 *================================================================================*
 *
 * 文件名称: Apitool.c
 *
 * 文件描述: apitool.c
 * 作    者:
 * 创建时间:
 * 文件版本:
 * 修改历史:
 *
 *================================================================================*/

/*================================================================================*
 *                                 头文件包含                                     *
 *================================================================================*/
#include "Sys_cfg.h"
#include "Apitool.h"
#include "math.h"
/*================================================================================*
 *                                   宏定义                                       *
 *================================================================================*/

/*================================================================================*
 *                                全局变量定义                                    *
 *================================================================================*/



/*================================================================================*
 *                               局部变量定义                                     *
 *================================================================================*/


/*================================================================================*
 *                                 函数声明                                       *
 *================================================================================*/


/*================================================================================*
 * 函数名称:    void delay0_25us(void)
 * 功能描述:
 * 作    者:
 * 输入参数:
 * 输出参数:
 * 返 回 值:
 * 其他说明:    18 NOP--->3us        ,此时是1us
 * 创建历史:
 *
 *================================================================================*/
void delay0_25us(void)
{
		__NOP();
		__NOP();
		__NOP();
		__NOP();
		__NOP();
		__NOP();
		__NOP();
		__NOP();
		__NOP();
		__NOP();
		__NOP();
		__NOP();
		__NOP();
		__NOP();
		__NOP();

}
/*
 *  有初始值的CRC校验 8位
 *
 *  输入:  crc---->初始CRC值
 *         pData-->数据内容
 *         nLen--->数据长度
 *
 *  返回:  8位CRC校验值
 */
uint8_t CheckCrc8WithInitial(uint8_t crc, uint8_t *pData, uint32_t Datalen)
{
  uint8_t i;

	while(Datalen--)
	{
		crc^=*pData++;
		for(i=0; i<8; i++)
		{
			if (crc & 0x80)
				crc = (crc << 1)^0x07 ;
			else
				crc <<= 1;
		}
	}

	return crc;
}

/*
 *  有初始值的CRC校验 32位
 *
 *  输入:  crc---->初始CRC值
 *         pData-->数据内容
 *         nLen--->数据长度
 *
 *  返回:  32位CRC校验值
 */
uint32_t CheckCrc32WithInitial(uint8_t *ucBuf, uint32_t uiLen, uint32_t uiSeed)
{
  uint32_t i,j;
	uint32_t crc = uiSeed;/*0x00000000;*/
	if (NULL == ucBuf || uiLen <= 0)
	{
	    return crc;
	}
	//如果不是unsigned int的整数倍则用0xff补齐

	uint8_t *ucOld = ucBuf;
	uint32_t rem = uiLen % sizeof(unsigned int);
	if (rem > 0) {
		int n = sizeof(unsigned int) - rem;
		for (i = 0; i < n; i ++) {
			ucOld[uiLen+i] = 0xff;
		}
		uiLen += n;
	}

	uint32_t uiCount = uiLen/sizeof(unsigned int);
	for (i = 0; i < uiCount; i ++) {
		uint32_t uiTemp = *(uint32_t *)ucOld;
		for (j = 0; j < 32; j ++) {
			if ((crc^uiTemp) & 0x80000000) {
				crc = 0x04C11DB7^(crc<<1);
			} else {
				crc <<= 1;
			}
			uiTemp <<= 1;
		}
		ucOld += sizeof(unsigned int);
	}

	return crc;
}

/*================================================================================*
 * 函数名称:    int32_t CheckFlashAppCode(uint32_t nCrc, uint32_t nSize)
 * 功能描述:    检测片内代码
 * 作    者:
 * 输入参数:

 * 输出参数:
 * 返 回 值:    0成功   <0失败
 * 其他说明:
 * 创建历史:
 *
 *================================================================================*/
int32_t CheckFlashAppCode(uint32_t nCrc, uint32_t nSize)
{

    uint32_t ComputedCRC = 0;
    uint32_t suAppCrcInitial = 0x00000000;

    ComputedCRC = CheckCrc32WithInitial((uint8_t *)FLASH_APPLICATION_ADDR, nSize, suAppCrcInitial);
		
    if(nCrc != ComputedCRC)
    {
        return -1;
    }
    return 0;
}

/*================================================================================*
 * 函数名称: ByteToInt16(*)
 * 功能描述: 字节转换成16数据
 * 作    者:
 * 输入参数: pBuf输入，低字节在低位
 * 输出参数:
 * 返 回 值:
 * 其他说明:    pBuf[0] || pBuf[1]<<8
 * 创建历史:
 *================================================================================*/
uint32_t ByteToInt16(uint8_t *pBuf)
{
	uint16_t usData = 0;
	if(NULL == pBuf)
	{
		return 0;
	}
	usData = pBuf[0];
	usData = ((uint16_t)pBuf[1]<<8)|usData;
	return usData;
}
/*================================================================================*
 * 函数名称: ByteToInt16(*)
 * 功能描述: 字节转换成16数据
 * 作    者:
 * 输入参数: pBuf输入，高字节在低位
 * 输出参数:
 * 返 回 值:
 * 其他说明:    pBuf[0]<<8 || pBuf[1]
 * 创建历史:
 *================================================================================*/
uint16_t EByteToInt16(uint8_t *pBuf)
{
	uint16_t usData = 0;
	if(NULL == pBuf)
	{
		return 0;
	}
	usData = pBuf[1];
	usData = ((uint16_t)pBuf[0]<<8)|usData;
	return usData;
}
/*================================================================================*
 * 函数名称: void Int32ToByte(uint32_t usIn, uint8_t *pOut)
 * 功能描述: 字转换成4个字节
 * 作    者:
 * 输入参数:    usIn 输入
                pOut 输出
 * 输出参数:
 * 返 回 值:
 * 其他说明:
 * 创建历史:
 *================================================================================*/
void Int32ToByte(uint32_t usIn, uint8_t *pOut)
{
    pOut[0] = usIn;
    pOut[1] = usIn>>8;
    pOut[2] = usIn>>16;
    pOut[3] = usIn>>24;
}

/*================================================================================*
 * 函数名称: void Int16ToByte(uint32_t usIn, uint8_t *pOut)
 * 功能描述: 半字转换成2个字节
 * 作    者:
 * 输入参数:    usIn 输入
                pOut 输出
 * 输出参数:
 * 返 回 值:
 * 其他说明:
 * 创建历史:
 *================================================================================*/
void Int16ToByte(uint16_t usIn, uint8_t *pOut)
{
    pOut[0] = usIn;
    pOut[1] = usIn>>8;
}

/*================================================================================*
 * 函数名称: inline uint8_t Char_Hex2BCD(uint8_t *pData)
 * 功能描述: 单个字节Hex转化成BCD码
 * 作    者:
 * 输入参数:

 * 输出参数:
 * 返 回 值:
 * 其他说明:    转化值域:  0-99           ,单个字节
 * 创建历史:
 *================================================================================*/
inline uint8_t Int8_Hex2BCD(uint8_t *pData)
{
    if(*pData > 99)
    {
        return 99;
    }
    return ((*pData / 10) << 4) | (*pData % 10);
}

/*================================================================================*
 * 函数名称: inline uint16_t Int16_Hex2BCD(uint16_t *pData)
 * 功能描述: Hex转化成BCD码
 * 作    者:
 * 输入参数:

 * 输出参数:
 * 返 回 值:
 * 其他说明:    转化值域:  0-9999           ,两个字节
 * 创建历史:
 *================================================================================*/
inline uint16_t Int16_Hex2BCD(uint8_t *Data)
{
    uint16_t DataTemp = 0;

    DataTemp = *(uint16_t*)Data;
    return (DataTemp / 1000) << 12 | (DataTemp % 1000 / 100) << 8 | (DataTemp % 100 / 10) << 4 | (DataTemp % 10);
}


/*================================================================================*
 *                                End of file                                     *
 *================================================================================*/

