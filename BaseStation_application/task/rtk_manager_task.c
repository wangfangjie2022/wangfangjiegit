/**
  ******************************************************************************
  * File Name          : rtk_manager_task.c
  * Description        : 
**/

/* Includes ------------------------------------------------------------------*/

#include "rtk_manager_task.h"
#include "includes.h"
#include "xstar_fcs.h"
#include "stdio.h"
#include "string.h"
#include "stdarg.h"

/*================================================================================*
 *                                   �궨��                                       *
 *================================================================================*/
#define ALINK_LENGTH_MAX 					512
#define RTCM_HEAD_LEN							3
#define RTCM_CRC_LEN							3
#define RTCM_MAX_LEN							1029
#define RTKMSG_MAX_LEN						512

/*================================================================================*
 *                                ȫ�ֱ�������                                    *
 *================================================================================*/
uint8_t nDealRTKTaskID;
uint8_t RTCM_buf[RTCM_MAX_LEN];
uint8_t rtkcom1_txbuf[256];
uint8_t rtkmsg[RTKMSG_MAX_LEN];
rtkmsg_info_t rtkmsg_info;

/*================================================================================*
 *                               �ֲ���������                                     *
 *================================================================================*/
static uint8_t IsRTKinitOK = 0; 
static uint8_t rtk_init_cnt = 0;
const uint16_t RTK_CFG_DELAY_MS = 200;



static alink_message_head_t msg_rtk;

const char *rtk_com1_bps_cfg[] = 
{ 
	"COM COM1 460800\r\n"           
};

const char *config_options[] = 
{
	"UNLOG\r\n"                     ,
//	"UNLOG COM1\r\n"                ,
	"mode base time 60 1.5 2.5\r\n" ,
	"rtcm1006 com1 10\r\n"          ,
	"rtcm1033 com1 10\r\n"          ,
	"rtcm1074 com1 1\r\n"           ,
	"rtcm1124 com1 1\r\n"           ,
//	"rtcm1084 com1 1\r\n"           ,
//	"rtcm1094 com1 1\r\n"           ,
	"saveconfig\r\n"                ,
};


/* �ƶ���վģʽ����ְ�5HZ��λ����Ϣ10Hz */
const char *cfg_options_movingbase[] = 
{  
	"UNLOGALL\r\n"                  ,
//	"COM COM1 460800\r\n"           ,
	"COM COM2 115200\r\n"           ,
	
#if 1	
	/* �ƶ���վ���� */
	"mode movingbase\r\n"           ,
	"rtcm1006 com2 10\r\n"          ,
	"rtcm1033 com2 10\r\n"          ,
	"rtcm1074 com2 0.2\r\n"         ,
	"rtcm1124 com2 0.2\r\n"         ,
//	"rtcm1084 com1 1\r\n"           ,
//	"rtcm1094 com1 1\r\n"           ,
  "config msm 32\r\n"             ,
  "config bd3 disable\r\n"        ,
#else
	/* �̶���վ���� */
	"mode base time 60 1.5 2.5\r\n" ,	
	"rtcm1006 com2 10\r\n"          ,
	"rtcm1033 com2 10\r\n"          ,
	"rtcm1074 com2 1\r\n"         ,
	"rtcm1124 com2 1\r\n"         ,
//	"rtcm1084 com1 1\r\n"           ,
//	"rtcm1094 com1 1\r\n"           ,
#endif

	/* λ���ٶȼ�HEADINGģʽ���ã�10Hz */
	"LOG BESTVELB ONTIME 0.1\r\n"   ,
	"LOG BESTXYZB ONTIME 0.1\r\n"   ,
	"LOG HEADINGB ONTIME 0.1\r\n"   ,
	"LOG BESTPOSB ONTIME 0.1\r\n"   ,
	"LOG FWINFOB ONCE\r\n"   ,
	//"version\r\n"						,
	"saveconfig\r\n"                , 
};





uint8_t gRtkQuality = 0; //RTK����,ֻ��0��5��������û���յ�RTK��������Ϊ0��
static uint8_t rtk_soln_svs=0;




/*================================================================================*
 *                                 ��������                                       *
 *================================================================================*/
void rtk_led_ctrl(void);
uint32_t rtk_rtcm_msg_proc(void);
void rtk_log_send(RTK_Base_Bus *rtk_info, alink_RTK_Bus *alink_rtk);
/*================================================================================*
 *                                 ����ԭ��                                       *
 *================================================================================*/

void RTK_Uninit(void)
{
		IsRTKinitOK = 0;
}
 
/*================================================================================*
 * ��������:    void init_RTK(void)
 * ��������:    RTK��ʼ������
 * ��    ��:
 * �������:
 * �������:
 * �� �� ֵ:
 * ����˵��:
 * ������ʷ:
 *
 *================================================================================*/
void init_RTK(void)
{
	static uint32_t nRTKInitTimer = 0;
	
	if (rtk_init_cnt < 1)//��ʼ��һ�β��У���Ҫ��ʼ������
	{
		if(init_Hexinxintong() == 1)
		{
			rtk_init_cnt++;
			nRTKInitTimer = GET_CURTICK;
		}
	}
	if(rtk_init_cnt >= 1)
	{
		if( GET_PASTTICK(nRTKInitTimer)>=100 )
		{
			IsRTKinitOK = 1;
		}
	}
}
/*================================================================================*
 * ��������:    uint8_t GetIsInitRTK(void)
 * ��������:    ��ȡ��ǰRTK�Ƿ��Ѿ���ʼ��
 * ��    ��:
 * �������:
 * �������:
 * �� �� ֵ:
 * ����˵��:
 * ������ʷ:
 *
 *================================================================================*/
uint8_t GetIsInitRTK(void)
{
	return IsRTKinitOK;
}

/*================================================================================*
 * ��������:    uint8_t init_Hexinxintong(void)
 * ��������:    ��ʼ��RTK
 * ��    ��:
 * �������:
 * �������:
 * �� �� ֵ:
 * ����˵��:
 * ������ʷ:
 *
 *================================================================================*/
uint8_t init_Hexinxintong(void)
{
	uint8_t ret = 0;
	static uint8_t sInit = 0;
	static uint32_t nInitRTKTimer=0;
	static uint8_t flg_rtk_bps_sw=0;
	
	/* ���л�RTK COM1������ */
	if(flg_rtk_bps_sw == 0)
	{
		nInitRTKTimer = GET_CURTICK;
		memcpy(rtkcom1_txbuf, rtk_com1_bps_cfg[0], strlen(rtk_com1_bps_cfg[0]));
		serial_send(&com_obj[RTK_COM1], rtkcom1_txbuf, strlen(rtk_com1_bps_cfg[0]));
		flg_rtk_bps_sw= 1;
		ret = 0;
	}
	else if(flg_rtk_bps_sw == 1)
	{
		if(GET_PASTTICK(nInitRTKTimer)>= 1000)
		{
			UARTx_BaudRate_Config(RTK_COM1, 460800);
			nInitRTKTimer = GET_CURTICK;
			flg_rtk_bps_sw= 2;
		}
		ret = 0;
	}
	
	/* �ƶ���վģʽ�ĳ�ʼ�� */
	else if(sInit<sizeof(cfg_options_movingbase)/sizeof(cfg_options_movingbase[0]))
	{
		if( GET_PASTTICK(nInitRTKTimer)>=RTK_CFG_DELAY_MS )
		{
			nInitRTKTimer = GET_CURTICK;
			memcpy(rtkcom1_txbuf, cfg_options_movingbase[sInit], strlen(cfg_options_movingbase[sInit]));
      serial_send(&com_obj[RTK_COM1], rtkcom1_txbuf, strlen(cfg_options_movingbase[sInit]));
			sInit++;
		}
	}
	if(sInit >= sizeof(cfg_options_movingbase)/sizeof(cfg_options_movingbase[0]))
	{
		sInit = 0;
		ret = 1;
	}
	return ret;
}
/*================================================================================*
 * ��������:    int Str_Find(uint8_t* strFrom,uint8_t* strFind,uint32_t ntotalLen,uint32_t nfindLen) 
 * ��������:    �����ض��ַ�
 * ��    ��:
 * �������:
 * �������:
 * �� �� ֵ:
 * ����˵��:
 * ������ʷ:
 *================================================================================*/ 
int Str_Find(uint8_t* strFrom,uint8_t* strFind,uint32_t ntotalLen,uint32_t nfindLen) 
{
	int ret = -1;
	int i = 0,findLen = 0;
	uint8_t* pCur = strFrom;
	while(i<ntotalLen)
	{
		if( *pCur == strFind[0] )
		{
			findLen = memcmp(pCur,strFind,nfindLen);
			if(findLen == 0)
			{
				ret = i;	//���ز��ҵ���λ��		
				break;
			}
			pCur += nfindLen;
			i+=nfindLen;
		}
		pCur++;
		i++;
	}
	return ret;
}


int uint8_to_int(const uint8_t str[])
{
	uInt_t ustr;
	int ret = 0;
	int i = 0;
	for ( i = 0; i < 4; i++)
	{
		ustr.temp[i] = str[i];
	}
	ret = ustr.data;
	return ret;
}

float uint8_to_float(const uint8_t str[])
{
	uFloat_t ustr;
	float ret = 0;
	int i = 0;
	for ( i = 0; i < 4; i++)
	{
		ustr.temp[i] = str[i];
	}
	ret = ustr.data;
	return ret;
}

double uint8_to_double(const uint8_t str[])
{
	uDouble_t ustr;
	double ret = 0;
	int i = 0;
	for ( i = 0; i < 8; i++)
	{
		ustr.temp[i] = str[i];
	}
	ret = ustr.data;
	return ret;
}

/******************************************************************************
 * ���ܣ�RTK��������Ϣ��������
 * ���룺rtk_msg ---���ڴ�Ž�����ɵ�RTK��Ϣ
 *       dat     ---��������RTK���ֽ�����
 * ���أ�0---�����У�1---�ɹ���-1---ʧ�ܡ�
 * ˵����
 *
 *****************************************************************************/
int rtk_msg_parse(uint8_t* rtk_msg, uint8_t dat)
{
	static rtkmsg_idx_e rtkmsg_idx= 0;
	int ret= 0;
	//rtkmsg_info
	
	switch(rtkmsg_idx)
	{
	case eMsgIdx_Sync1:
		{
			if(dat == 0xAA) {
				rtk_msg[rtkmsg_idx++]= dat;
			}
		}break;
		
	case eMsgIdx_Sync2:
		{
			if(dat == 0x44) {
				rtk_msg[rtkmsg_idx++]= dat;
			}else{
				rtkmsg_idx= eMsgIdx_Sync1;
			}
		}break;
		
	case eMsgIdx_Sync3:
		{
			if(dat == 0x12) {
				rtk_msg[rtkmsg_idx++]= dat;
			}else{
				rtkmsg_idx= eMsgIdx_Sync1;
			}
		}break;
		
	case eMsgIdx_HeadLen:
		{
			rtk_msg[rtkmsg_idx++]= dat;
			rtkmsg_info.headlen= dat;
		}break;
		
	case eMsgIdx_MsgID_Lo:
		{
			rtk_msg[rtkmsg_idx++]= dat;
			rtkmsg_info.msgid_lo= dat;
		}break;
		
	case eMsgIdx_MsgID_Hi:
		{
			rtk_msg[rtkmsg_idx++]= dat;
			rtkmsg_info.msgid_hi= dat;
			rtkmsg_info.msgid= rtkmsg_info.msgid_hi*256 + rtkmsg_info.msgid_lo;
		}break;		
		
	case eMsgIdx_MsgLen_Lo:
		{
			rtk_msg[rtkmsg_idx++]= dat;
			rtkmsg_info.msglen_lo= dat;
		}break;		
		
	case eMsgIdx_MsgLen_Hi:
		{
			rtk_msg[rtkmsg_idx++]= dat;
			rtkmsg_info.msglen_hi= dat;
			rtkmsg_info.msglen= rtkmsg_info.msglen_hi*256 + rtkmsg_info.msglen_lo;
			rtkmsg_info.crc_idx= rtkmsg_info.headlen + rtkmsg_info.msglen;			
		}break;	
		
	default:
		{
			if (rtkmsg_idx >= RTKMSG_MAX_LEN)
			{
				rtkmsg_idx= 0;	// ��ֹ��Ϣ̫����Խ��
			}
			else if (rtkmsg_idx < rtkmsg_info.headlen)
			{
				rtk_msg[rtkmsg_idx++]= dat;
			}
			else if (rtkmsg_idx < rtkmsg_info.crc_idx)
			{
				rtk_msg[rtkmsg_idx++]= dat;
			}
			else if (rtkmsg_idx < rtkmsg_info.crc_idx+1)
			{
				rtk_msg[rtkmsg_idx++]= dat;
				rtkmsg_info.crc[0]= dat;
			}
			else if (rtkmsg_idx < rtkmsg_info.crc_idx+2)
			{
				rtk_msg[rtkmsg_idx++]= dat;
				rtkmsg_info.crc[1]= dat;
			}
			else if (rtkmsg_idx < rtkmsg_info.crc_idx+3)
			{
				rtk_msg[rtkmsg_idx++]= dat;
				rtkmsg_info.crc[2]= dat;
			}
			else if (rtkmsg_idx < rtkmsg_info.crc_idx+4)
			{
				rtk_msg[rtkmsg_idx]= dat;
				rtkmsg_idx= 0;
				rtkmsg_info.crc[3]= dat;
				rtkmsg_info.crc32= ((uint32_t)rtkmsg_info.crc[0]) \
												 + ((uint32_t)rtkmsg_info.crc[1]<<8) \
												 + ((uint32_t)rtkmsg_info.crc[2]<<16) \
												 + ((uint32_t)rtkmsg_info.crc[3]<<24);
				
				uint32_t crc= hw_crc32_calc(rtk_msg, rtkmsg_info.crc_idx);
				if (rtkmsg_info.crc32 == crc)
				{
					ret= 1; 
				}else{
					ret= -1;
				}			
			}
			else
			{
				rtkmsg_idx= 0;
			}		
		}break;	
	}
	
	return ret;	
}

//uint8_t rtk_test_dat[]={
//0xAA, 0x44, 0x12, 0x1C, 0xCB, 0x03, 0x00, 0x01, 0x2C, 0x00, 0x00, 0x00, 0x23, 0xA0, 0xAC, 0x08, 0x98, 
//0xF3, 0x04, 0x06, 0x86, 0xF4, 0x03, 0x00, 0x00, 0x00, 0x12, 0x00, 0x00, 0x00, 0x00, 0x00, 0x22, 0x00, 
//0x00, 0x00, 0x86, 0x8C, 0x3D, 0x3F, 0x07, 0xF8, 0x11, 0x43, 0x7D, 0x18, 0xF5, 0xC0, 0x00, 0x00, 0x00, 
//0x00, 0xE5, 0x66, 0xC4, 0x40, 0x60, 0x16, 0x5E, 0x41, 0x39, 0x39, 0x39, 0x00, 0x1A, 0x16, 0x16, 0x0F, 
//0x03, 0x00, 0x03, 0xF3, 0x5F, 0xEE, 0x2B, 0x97
//};
//void rtk_msg_parse_test(void)
//{
//	uint16_t i=0;
//	
//	for (i=0; i< sizeof(rtk_test_dat); i++)
//	{
//		rtk_msg_parse(rtkmsg, rtk_test_dat[i]);	
//	}
//}




#if 1
/******************************************************************************
 * ���ܣ���ȡRTKλ�ü��ٶ���Ϣ�������ƶ�վģʽ��
 * ���룺��          
 * ���أ�0---�ɹ���-1---ʧ�ܡ�
 * ˵����
 *
 *****************************************************************************/
int GetRtkPacket(void)
{
	static volatile RTK_Base_Bus rtk_base;
	static uint8_t flag_pos_update= 0;
	static uint8_t flag_heading_update= 0;
  
	static alink_message_head_t msg_rtk_GPS;
  alink_rtk_location_t alink_rtk_info;
	uint8_t dat;
	
	while (queue_pop (&com_obj[RTK_COM1].rx_queue, &dat))
	{
		if (1 == rtk_msg_parse(rtkmsg, dat))
		{
			uint8_t* rtk_dat= &rtkmsg[rtkmsg_info.headlen];
			
			switch (rtkmsg_info.msgid)
			{
				/* λ����Ϣ ---------------------------------------------------*/
				case RTK_MSGID_BESTPOS:
					{												
						/* ��վ�ߵ��㷨�������� */
						rtk_base.sol_s_pos = (uint16_T)uint8_to_int(&rtk_dat[0]);
						rtk_base.pos_type = (uint16_T)uint8_to_int(&rtk_dat[4]);
						rtk_base.lat = uint8_to_double(&rtk_dat[8]);
						rtk_base.lon = uint8_to_double(&rtk_dat[16]);
						rtk_base.hgt = uint8_to_double(&rtk_dat[24]);
						rtk_base.lat_stddev = uint8_to_float(&rtk_dat[40]);
						rtk_base.lon_stddev = uint8_to_float(&rtk_dat[44]);
						rtk_base.hgt_stddev = uint8_to_float(&rtk_dat[48]);
						rtk_base.Timestamp_ms_pos = GET_CURTICK;
						
						/* ����ȷ���ⲿ���õĻ�վλ���Ƿ�׼ȷ��λ����Ϣ */
						PosSetObj.cur_pos.lat = rtk_base.lat;
						PosSetObj.cur_pos.lon = rtk_base.lon;
						PosSetObj.cur_pos.hgh = rtk_base.hgt;
						PosSetObj.rtk_updat = 1;
						
						/* ��վ��Ч��������Ϣ */
						rtk_soln_svs = rtk_dat[65];
						
						flag_pos_update= 1;
						
					}break;
					
				/* �ٶ���Ϣ ---------------------------------------------------*/
				case RTK_MSGID_BESTVEL:
					{
						/* ��վ�ߵ��㷨�������� */
						rtk_base.sol_s_vel = (uint16_T)uint8_to_int(&rtk_dat[0]);
						rtk_base.vel_type = (uint16_T)uint8_to_int(&rtk_dat[4]);
						rtk_base.hor_spd = uint8_to_double(&rtk_dat[16]);
						rtk_base.trk_gnd = uint8_to_double(&rtk_dat[24]);
						rtk_base.vert_spd = uint8_to_double(&rtk_dat[32]);
						rtk_base.Timestamp_ms_vel = GET_CURTICK;
						
					}break;
						
				/* ���λ�ú��ٶ� ---------------------------------------------*/
				case RTK_MSGID_BESTXYZ:
					{
						/* ��վ�ߵ��㷨�������� */
						rtk_base.Vx_stddev = uint8_to_float(&rtk_dat[76]);
						rtk_base.Vy_stddev = uint8_to_float(&rtk_dat[80]);
						rtk_base.Vz_stddev = uint8_to_float(&rtk_dat[84]);
						
					}break;
						
				/* HEADING������Ϣ --------------------------------------------*/
				case RTK_MSGID_HEADING:
					{
						/* ��վ�ߵ��㷨�������� */
						rtk_base.sol_s_hd =    (uint16_T)uint8_to_int (&rtk_dat[0]);//sol stat
						rtk_base.pos_type_hd = (uint16_T)uint8_to_int (&rtk_dat[4]);//pos type
						rtk_base.heading =      uint8_to_float (&rtk_dat[12]);//heading
						rtk_base.hdg_stddev =   uint8_to_float (&rtk_dat[24]);
						rtk_base.Timestamp_ms_hd = GET_CURTICK;
						
						flag_heading_update= 1;
						
					}break;
						
				default:
					{
						
					}break;
			}
		}		
	}
	
	if(!flag_pos_update) return -1;
	if(!flag_heading_update) return -1;
	
	flag_pos_update= 0;
	flag_heading_update= 0;
	
	/* ��RTK��Ϣ���ݸ���վ�ߵ��㷨 */
	memcpy((char *)&xstar_fcs_U.sensors.RTK_Base, (char *)&rtk_base, sizeof(rtk_base));
 
	/* ���ߵ��㷨����Ļ�վλ�á��ٶȡ���̬���������Ϣȡ���������͵��ɿض� */
	memcpy((char *)&alink_rtk_info, (char *)&xstar_fcs_Y.alink_rtk_location, sizeof(xstar_fcs_Y.alink_rtk_location));
	alink_rtk_info.pos_type |= 0x80;
 
	alink_msg_rtk_location_encode(DEV_UAV, DEV_BASESTATION,&msg_rtk_GPS,(alink_rtk_location_t*)&alink_rtk_info);
	packet_transmit(&com_obj[ANT_MCU_COM],&msg_rtk_GPS);   // ͨ��ͼ�����ɿ�  

	rtk_log_send((void*)&rtk_base, &xstar_fcs_Y.alink_rtk_location);
	
	return 0;		
}

#else

const uint8_t RtkBestPosHeader[] = {0xAA,0x44,0x12,0x1C,0x2A,0x00};
const uint8_t RtkBestVelHeader[] = {0xAA,0x44,0x12,0x1C,0x63,0x00};
const uint8_t RtkBestXyzHeader[] = {0xAA,0x44,0x12,0x1C,0xF1,0x00};
const uint8_t RtkHeadingHeader[] = {0xAA,0x44,0x12,0x1C,0xCB,0x03};

static uint8_t array_BestVel[76];
static uint8_t array_BestPos[104];
static uint8_t array_Bestxyz[144];
static uint8_t array_Heading[76];

static uint16_t msg_len[4];

/******************************************************************************
 * ���ܣ���ȡRTKλ�ü��ٶ���Ϣ�������ƶ�վģʽ��
 * ���룺��          
 * ���أ�0---�ɹ���-1---ʧ�ܡ�
 * ˵����
 *
 *****************************************************************************/
int GetRtkPacket_1(void)
{
  static volatile RTK_Base_Bus rtk_base;
  static uint8_t flag_pos_update= 0;
	static uint8_t flag_heading_update= 0;
  uint8_t packet[6] = {0};
	static alink_message_head_t msg_rtk_GPS;
  alink_rtk_location_t alink_rtk_info;
  
  static int16_t rtk_message_id = 0;

	int i = 0;
	int ret = 0;
	if( queue_empty(&com_obj[RTK_COM1].rx_queue) == 0 )
	{
		memset(packet,0,sizeof(packet) );
		while(1)
		{
			queue_pop(&com_obj[RTK_COM1].rx_queue,&packet[i++]);
			if( packet[0] ==  0xaa)
			{
				queue_pop(&com_obj[RTK_COM1].rx_queue,&packet[i++]);
				if( packet[1] ==  0x44 )
        {
          queue_pop_buf(&com_obj[RTK_COM1].rx_queue,&packet[2],4);
          if( packet[2] ==  0x12 && packet[3] ==  0x1C)
          {
            rtk_message_id = packet[4] + packet[5] * 256;
            /* λ����Ϣ ---------------------------------------------------*/
            if(rtk_message_id == RTK_MSGID_BESTPOS)
            {
              memset(array_BestPos,0,sizeof(array_BestPos) );
              memcpy(array_BestPos,RtkBestPosHeader,6);
              msg_len[0]= queue_pop_buf(&com_obj[RTK_COM1].rx_queue,&array_BestPos[6],sizeof(array_BestPos)-6);

              /* ��վ�ߵ��㷨�������� */
              rtk_base.sol_s_pos = (uint16_T)uint8_to_int(&array_BestPos[28 + 0]);
              rtk_base.pos_type = (uint16_T)uint8_to_int(&array_BestPos[28 + 4]);
              rtk_base.lat = uint8_to_double(&array_BestPos[28 + 8]);
              rtk_base.lon = uint8_to_double(&array_BestPos[28 + 16]);
              rtk_base.hgt = uint8_to_double(&array_BestPos[28 + 24]);
              rtk_base.lat_stddev = uint8_to_float(&array_BestPos[28 + 40]);
              rtk_base.lon_stddev = uint8_to_float(&array_BestPos[28 + 44]);
              rtk_base.hgt_stddev = uint8_to_float(&array_BestPos[28 + 48]);
              rtk_base.Timestamp_ms_pos = GET_CURTICK;
              
              /* ����ȷ���ⲿ���õĻ�վλ���Ƿ�׼ȷ��λ����Ϣ */
              PosSetObj.cur_pos.lat = rtk_base.lat;
              PosSetObj.cur_pos.lon = rtk_base.lon;
              PosSetObj.cur_pos.hgh = rtk_base.hgt;
              PosSetObj.rtk_updat = 1;
              
              /* ��վ��Ч��������Ϣ */
              rtk_soln_svs = array_BestPos[28 + 65];
              
              flag_pos_update= 1;
              break;
            }
            
            /* �ٶ���Ϣ ---------------------------------------------------*/
            else if(rtk_message_id == RTK_MSGID_BESTVEL)
            {
              memset(array_BestVel,0,sizeof(array_BestVel) );
              memcpy(array_BestVel,RtkBestVelHeader,6);
              msg_len[1]= queue_pop_buf(&com_obj[RTK_COM1].rx_queue,&array_BestVel[6],sizeof(array_BestVel)-6);
              
              /* ��վ�ߵ��㷨�������� */
              rtk_base.sol_s_vel = (uint16_T)uint8_to_int(&array_BestVel[28 + 0]);
              rtk_base.vel_type = (uint16_T)uint8_to_int(&array_BestVel[28 + 4]);
              rtk_base.hor_spd = uint8_to_double(&array_BestVel[28 + 16]);
              rtk_base.trk_gnd = uint8_to_double(&array_BestVel[28 + 24]);
              rtk_base.vert_spd = uint8_to_double(&array_BestVel[28 + 32]);
              rtk_base.Timestamp_ms_vel = GET_CURTICK;
              
//              if(rtk_base.vel_type == 0){
//               BuzzOn_time(0,0,3,100,100); 
//              }
              
              break;
            }

            /* ���λ�ú��ٶ� ---------------------------------------------------*/
            else if(rtk_message_id == RTK_MSGID_BESTXYZ)
            {
              memset(array_Bestxyz,0,sizeof(array_Bestxyz) );
              memcpy(array_Bestxyz,RtkBestXyzHeader,6);
              msg_len[2]= queue_pop_buf(&com_obj[RTK_COM1].rx_queue,&array_Bestxyz[6],sizeof(array_Bestxyz)-6);

              /* ��վ�ߵ��㷨�������� */
              rtk_base.Vx_stddev = uint8_to_float(&array_Bestxyz[28 + 76]);
              rtk_base.Vy_stddev = uint8_to_float(&array_Bestxyz[28 + 80]);
              rtk_base.Vz_stddev = uint8_to_float(&array_Bestxyz[28 + 84]);               
              break;
            }

            //HEADING������Ϣ
            else if(rtk_message_id == RTK_MSGID_HEADING)
            {
              memset(array_Heading,0,sizeof(array_Heading) );
              memcpy(array_Heading,RtkHeadingHeader,6);
              msg_len[3]= queue_pop_buf(&com_obj[RTK_COM1].rx_queue,&array_Heading[6],sizeof(array_Heading)-6);
              
              /* ��վ�ߵ��㷨�������� */
              rtk_base.sol_s_hd = (uint16_T)uint8_to_int(&array_Heading[28 + 0]);//sol stat
              rtk_base.pos_type_hd = (uint16_T)uint8_to_int(&array_Heading[28 + 4]);//pos type
              rtk_base.heading = uint8_to_float(&array_Heading[28 + 12]);//heading
              rtk_base.hdg_stddev = uint8_to_float(&array_Heading[28 + 24]);
              rtk_base.Timestamp_ms_hd = GET_CURTICK;
							
							flag_heading_update= 1;
              break;
            }

            else
            {;}
          }
        }else{
//					goto RTCM_PARSE;
				}					
			}else{
//RTCM_PARSE:	
//				rtk_rtcm_msg_proc();
			}
			i = 0;
      packet[0]= packet[1] = 0;

			if( queue_empty(&com_obj[RTK_COM1].rx_queue) == 1 ) return -1;
		}		
    
    //if(!flag_pos_update) return -1;
		if(!flag_heading_update) return -1;
    flag_pos_update= 0;
		flag_heading_update= 0;
    
    /* ��RTK��Ϣ���ݸ���վ�ߵ��㷨 */
    memcpy((char *)&xstar_fcs_U.sensors.RTK_Base, (char *)&rtk_base, sizeof(rtk_base));
   
    /* ���ߵ��㷨����Ļ�վλ�á��ٶȡ���̬���������Ϣȡ���������͵��ɿض� */
    memcpy((char *)&alink_rtk_info, (char *)&xstar_fcs_Y.alink_rtk_location, sizeof(xstar_fcs_Y.alink_rtk_location));
    alink_rtk_info.pos_type |= 0x80;
   
    alink_msg_rtk_location_encode(DEV_UAV, DEV_BASESTATION,&msg_rtk_GPS,(alink_rtk_location_t*)&alink_rtk_info);
    packet_transmit(&com_obj[ANT_MCU_COM],&msg_rtk_GPS);   // ͨ��ͼ�����ɿ�  

		rtk_log_send((void*)&rtk_base, &xstar_fcs_Y.alink_rtk_location);
		
		return 0;		
	}
	else
		return -1;
}

#endif






 
 


/*================================================================================*
 * ��������:    ��վRTK������״̬��Ϣ����
 * ��    ��:
 * �������:
 * �������:
 * �� �� ֵ:
 * ����˵��:
 * ������ʷ:
 *================================================================================*/ 
void rtk_state_msg_send(void)
{
  static uint8_t  msg[30]; 
  alink_rtk_state_t basestation_info;
  alink_message_head_t *pmsg= (void*)msg;

	basestation_info.rtk_satellite_num = get_rtk_star_number();
	basestation_info.reserved1 = (gGetCurPowerState()==ENUM_POWER_OFF)? 1:0;
	basestation_info.reserved2 = 0;
  basestation_info.bat_percent = get_bat_percent();
	basestation_info.rtk_sig_percent = gRtkQuality;
  
	alink_msg_rtk_state_encode(DEV_APP, DEV_BASESTATION, pmsg, &basestation_info);
	packet_transmit(&com_obj[ANT_MCU_COM], pmsg);
  //packet_transmit(&com_obj[WIFI_COM], pmsg);
}


/*================================================================================*
 * ��������:  RTK RTCM��Ϣ������ת������
 * �������:
 * �������:
 * �� �� ֵ:  1--�յ�������RTCM��Ϣ��0--������
 * ����˵��:
 * ������ʷ:
 *================================================================================*/ 
uint32_t rtk_rtcm_msg_proc(void)
{	
	static uint32_t runtim= 0;
	static uint16_t rtcm_msg_len= 0;
	static uint16_t rtcm_remain_len= 0;
	static uint16_t i= 0;
	uint32_t ret= 0;
	uint16_t len= 0;
	uint8_t ch;
	uint8_t * pdata =(uint8_t *)&msg_rtk.payload64;
	
	queue_get_element(&com_obj[RTK_COM1].rx_queue, 1, &ch);
	
	/* �����ϴ�δ���RTCM��Ϣ */
	if(rtcm_remain_len > 0)
	{
		RTCM_buf[i++]= ch;
		rtcm_remain_len--;
		
		len= queue_pop_buf(&com_obj[RTK_COM1].rx_queue, &RTCM_buf[i], rtcm_remain_len);
		i += len;
		rtcm_remain_len -= len;
		if(rtcm_remain_len == 0)
		{
			i= 0;
			ret= 1;
			runtim= GET_CURTICK;
			//DEBUG_GPIO_L(DBG_GPIO_Pin1);////////////////
		}			
	}
	
	/* �����µ�RTCM��Ϣ */
	else if(ch == 0xD3)
	{
		i= 0;
		RTCM_buf[i++]= ch;
		
		if(0 >= queue_pop(&com_obj[RTK_COM1].rx_queue, &ch)) return 0;
		
		if((ch & 0xFC) ==  0x00 )
		{
			//DEBUG_GPIO_H(DBG_GPIO_Pin1);////////////////
			
			RTCM_buf[i++]= ch;
			rtcm_msg_len= (ch & 0x03) * 256;
			
			if(0 >= queue_pop(&com_obj[RTK_COM1].rx_queue, &ch)) return 0;
			RTCM_buf[i++]= ch;

			rtcm_msg_len += (ch + RTCM_CRC_LEN + RTCM_HEAD_LEN);
			rtcm_remain_len= rtcm_msg_len - i;
			
			ENTER_CRITICAL();
			len= queue_pop_buf(&com_obj[RTK_COM1].rx_queue, &RTCM_buf[i], rtcm_remain_len);
			i += len;
			rtcm_remain_len -= len;
			EXIT_CRITICAL();
			
			if(rtcm_remain_len == 0)
			{
				i= 0;
				ret= 1;
				runtim= GET_CURTICK;
				//DEBUG_GPIO_L(DBG_GPIO_Pin1);////////////////
			}	
		}
	}

	/* �쳣���� */
	if ( rtcm_remain_len > RTCM_MAX_LEN || GET_PASTTICK(runtim) > 3000)
	{
		rtcm_remain_len= 0;
		i= 0;
		ret= 0;
	}
	
	/* �յ�����RTCM��Ϣ���װ������ */
	if(ret == 1)
	{
		msg_rtk.msgid= ALINK_MSG_ID_RTK_SOL;
		
		len= rtcm_msg_len;
		uint16_t j=0;
		while(len)
		{
			if(len > ALINK_LENGTH_MAX)
			{
				//DEBUG_GPIO_H(DBG_GPIO_Pin2);////////////////
				memcpy(pdata, &RTCM_buf[j], ALINK_LENGTH_MAX);
				alink_finalize_message_chan(&msg_rtk, DEV_DSP, DEV_BASESTATION,0, ALINK_LENGTH_MAX, ALINK_MSG_ID_RTK_SOL_CRC);
				packet_transmit(&com_obj[ANT_MCU_COM],&msg_rtk);
				
				j += ALINK_LENGTH_MAX;
				len -= ALINK_LENGTH_MAX;
				//DEBUG_GPIO_L(DBG_GPIO_Pin2);////////////////
			}
			else
			{
				//DEBUG_GPIO_H(DBG_GPIO_Pin2);////////////////
				memcpy(pdata, &RTCM_buf[j], len);
				alink_finalize_message_chan(&msg_rtk, DEV_DSP, DEV_BASESTATION,0, len, ALINK_MSG_ID_RTK_SOL_CRC);
				packet_transmit(&com_obj[ANT_MCU_COM],&msg_rtk);
				j= 0;
				len= 0;
				//DEBUG_GPIO_L(DBG_GPIO_Pin2);////////////////
			}			
		}		
	}
	return ret;
}

#if 0
/*================================================================================*
 * ��������:    uint8_t rtk_comm_running()
 * ��������:    RTKת������
 * ��    ��:
 * �������:
 * �������:
 * �� �� ֵ:
 * ����˵��:
 * ������ʷ:
 *================================================================================*/ 
uint8_t rtk_comm_running()
{
	uint8_t ret = 0;
  uint8_t * pdata =(uint8_t *)&msg_rtk.payload64;
	uint16_t   count,i,len;
	uint8_t    value;

	msg_rtk.msgid= ALINK_MSG_ID_RTK_SOL;

	if(queue_size(&com_obj[RTK_COM1].rx_queue) > 0)
	{
		if(queue_size(&com_obj[RTK_COM1].rx_queue) > ALINK_LENGTH_MAX )
		{
			ENTER_CRITICAL();
			queue_pop_buf(&com_obj[RTK_COM1].rx_queue,RTCM_buf,ALINK_LENGTH_MAX);
			for(i = 0 ; i< ALINK_LENGTH_MAX ; i++ ){
				pdata[i] = RTCM_buf[i];
			}
			EXIT_CRITICAL();
			len = alink_finalize_message_chan(&msg_rtk, DEV_DSP, DEV_BASESTATION,0, ALINK_LENGTH_MAX, ALINK_MSG_ID_RTK_SOL_CRC);	

			packet_transmit(&com_obj[ANT_MCU_COM],&msg_rtk);
      //packet_transmit(&com_obj[WIFI_COM],&msg_rtk);
      
			ret = 1;
		}
		else
		{
			ENTER_CRITICAL();
			count = queue_size(&com_obj[RTK_COM1].rx_queue);
			queue_pop_buf(&com_obj[RTK_COM1].rx_queue,RTCM_buf,count);
			for(i = 0 ; i< count ; i++ ){
				pdata[i] = RTCM_buf[i];
			}
			EXIT_CRITICAL();
			len = alink_finalize_message_chan(&msg_rtk, DEV_DSP, DEV_BASESTATION,0, count, ALINK_MSG_ID_RTK_SOL_CRC);
     
			packet_transmit(&com_obj[ANT_MCU_COM],&msg_rtk);
      //packet_transmit(&com_obj[WIFI_COM],&msg_rtk);
			ret = 1;
		}
	}
	return ret;
}
#endif

/*================================================================================*
 * ��������:    void AddDealRTKTask()
 * ��������:    ��������
 * ��    ��:
 * �������:
 * �������:
 * �� �� ֵ:
 * ����˵��:
 * ������ʷ:
 *
 *================================================================================*/
void AddDealRTKTask(void)
{
    nDealRTKTaskID = AddTask(DealRTKTaskInit, DealRTKTask, DealRTKTaskUninit);
}

/*================================================================================*
 * ��������:    uint32_t DealRTKTaskInit(void)
 * ��������:    �����ʼ��
 * ��    ��:
 * �������:
 * �������:
 * �� �� ֵ:
 * ����˵��:
 * ������ʷ:
 *================================================================================*/
int32_t DealRTKTaskInit(void)
{
    return 0;
}

/*================================================================================*
 * ��������:    void DealRTKTask()
 * ��������:    
 * ��    ��:
 * �������:
 * �������:
 * �� �� ֵ:
 * ����˵��:    
 * ������ʷ:
 *
 *================================================================================*/
void DealRTKTask(void)
{
  static uint32_t InitTimer= 0;
	static uint32_t nDealRTKTaskTimer = 0;
	static uint32_t nLastReceiveRTK = 0;
	static alink_rtk_location_t rtk_location;
  
  if(gGetCurPowerState() == ENUM_POWER_ON)
  {
    if(GetIsInitRTK() != 1) 
    {
      if(InitTimer == 0) InitTimer= GET_CURTICK;
      if(GET_PASTTICK(InitTimer) > 6000){
        init_RTK();   // �ϵ���ӳ�6s������RTK����������ʧ��
      }		
    }
    //RTK����ÿ5ms����һ��   
    if( GetRtkPacket()== 0)
    {       
      nLastReceiveRTK = GET_CURTICK;
      
      if(rtk_soln_svs > 15) 
        gRtkQuality = 5;
      else if(rtk_soln_svs > 12) 
        gRtkQuality = 4;
      else if(rtk_soln_svs > 8) 
        gRtkQuality = 3;
      else if(rtk_soln_svs > 5) 
        gRtkQuality = 2;
      else if(rtk_soln_svs > 0) 
        gRtkQuality = 1;
      else 
        gRtkQuality = 0; 
    }
    if( GET_PASTTICK(nLastReceiveRTK) > 3000)//����״̬�������3sû���յ�RTK���ݣ�RTK��ɫ����
    {
      gRtkQuality = 0;
      rtk_soln_svs= 0;
    }
    
    
    if(GET_PASTTICK(nDealRTKTaskTimer)>1000 )
    {
      nDealRTKTaskTimer = GET_CURTICK;	
      rtk_state_msg_send();
    }
    
    //base_pos_set();
  }else{
    IsRTKinitOK = 0;
    rtk_init_cnt = 0;
    InitTimer= GET_CURTICK;
  }
  
  rtk_led_ctrl(); 
}

/******************************************************************************
 * ���ܣ���ȡRTKʹ�������ǿ�����
 * ���룺��          
 * ���أ�
 * ˵����
 *
 *****************************************************************************/
uint8_t get_rtk_star_number(void)
{
  return rtk_soln_svs;
}


/*================================================================================*
 * ��������:    uint32_t DealRTKTaskUninit(void)
 * ��������:   
 * ��    ��:
 * �������:
 * �������:
 * �� �� ֵ:
 * ����˵��:
 * ������ʷ:
 *
 *================================================================================*/
int32_t DealRTKTaskUninit(void)
{
    return 0;
}


/******************************************************************************
 * ���ܣ�RTK״ָ̬ʾ�ƵĿ��ơ�
 * ���룺��          
 * ���أ�
 * ˵�������ݶ�λ���ǵĿ�����ָʾRTK״̬��������ʱֱ����ơ�
 *
 *****************************************************************************/
void rtk_led_ctrl(void)
{
  static uint32_t ledtimer= 0;
  static uint32_t ledcnt= 0;
  uint8_t star_num= rtk_soln_svs;
   
  if( gGetCurPowerState() == ENUM_POWER_OFF )
	{
    LED_RTK_ALL_OFF();
	}
  else if ( GET_PASTTICK(ledtimer)>250 )
  {
    ledtimer = GET_CURTICK;
    
#if 1 
    /* ��վ��ȷλ��ģʽ��LED���� */
    if(ledcnt < 8)
    {
      if(star_num > 16){
        LED_RTK_G_ON();
      }
      else if (star_num > 5){
        LED_RTK_Y_ON();
      }
      else if (star_num >= 1)
      {
        LED_RTK_R_ON();
      }
      else{
        LED_RTK_ALL_OFF();
      }
    }else if(PosSetObj.stat){
      LED_RTK_ALL_OFF();
    }
    if(++ledcnt > 8)ledcnt= 0;
#else 
    /* �±�׼�������ƶ���---2020.10.16 */
    if(star_num > 16){
      LED_RTK_G_ON();
    }
    
    else if (star_num > 5){
      LED_RTK_Y_ON();
    }
    
    else if (star_num >= 1)
    {
      if(ledcnt < 2){
        LED_RTK_R_ON();
      }else{
        LED_RTK_R_OFF();
      }
      
      if(++ledcnt > 3)ledcnt= 0;
    }
    else{
      LED_RTK_ALL_OFF();
    }
    
#endif    
    
  }   
}




static uint32_t get_inter_tim(void)
{
	static uint32_t runtim= 0;
	
	uint32_t tim= GET_PASTTICK(runtim);
	runtim= GET_CURTICK;
	return tim;
}

const char RTK_Title[] = "RTK\theading\tTim_ms\tTim_int\thdg_stddev\tsol_s_hd\tpos_t_hd\tant_heading\tsoln_svs\terr_stat\r\n";  

#define RTK_LOG		"RTK\t%.1f\t%d\t%d\t%f\t%d\t%d\t%.1f\t%d\t%s\r\n"

void rtk_log_send(RTK_Base_Bus *rtk_info, alink_RTK_Bus *alink_rtk)
{
	static uint8_t init_flag= 0;
	char *str= "ok";
	
	if ((rtk_info->heading == 0)\
	|| (alink_rtk->ant_heading == 0))
	{
		str="err";
	}
	
	if (!init_flag)
	{
		init_flag= 1;
		debug_print((char*)&RTK_Title[0]);
	}
	else
	{
		snprintf(dbg_str, DBG_STR_LEN, RTK_LOG, 
					rtk_info->heading,					/* heading      */
					GET_CURTICK,								/* Systick  		*/
					get_inter_tim(),						/* Tim					*/			
					rtk_info->hdg_stddev,				/* hdg_stddev   */
					rtk_info->sol_s_hd,					/* sol_s_hd     */
					rtk_info->pos_type_hd,			/* pos_t_hd     */
					alink_rtk->ant_heading/0.1,	/* ant_heading  */
					rtk_soln_svs,								/* soln_svs     */
					str													/* err_stat     */
				);
			
		debug_print(dbg_str);
	}
}



