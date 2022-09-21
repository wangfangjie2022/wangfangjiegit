// MESSAGE RAW_RTK PACKING

#define ALINK_MSG_ID_RAW_RTK 21

typedef struct __alink_raw_rtk_t
{
 uint64_t timestamp; /*< timestamp (microseconds since UNIX epoch or microseconds since system boot)*/
 int32_t gspd; /*< GPS ground speed (m/s)*/
 int32_t velN; /*< GPS ground speed in m/s*/
 int32_t velE; /*< GPS ground speed in m/s*/
 int32_t velD; /*< GPS ground speed in m/s*/
 int32_t velN_sigma; /*< GPS ground speed quality in sigma*/
 int32_t velE_sigma; /*< GPS ground speed quality in sigma*/
 int32_t velD_sigma; /*< GPS ground speed quality in sigma*/
 int32_t vel_latench; /*< GPS ground speed latench*/
 int32_t posN; /*< GPS location X in m*/
 int32_t posE; /*< GPS location Y in m*/
 int32_t posD; /*< GPS location Z in m*/
 int32_t posN_sigma; /*< GPS location X quality in sigma*/
 int32_t posE_sigma; /*< GPS location Y quality in sigma*/
 int32_t posD_sigma; /*< GPS location Z quality in sigma*/
 uint8_t Svs; /*< GPS satellites*/
 uint8_t slon_Svs; /*< GPS satellites by used*/
 uint8_t pos_status; /*< GPS position status: 0-SOLCOMPUTED,1-INSUFFICIENT_OBS,3-COVTRAC*/
 uint8_t pos_type; /*< GPS position type: 0-NONE, 1-FIXEDPOS*/
 uint8_t vel_status; /*< GPS velocity status: 0-SOLCOMPUTED,1-INSUFFICIENT_OBS,3-COVTRAC*/
 uint8_t vel_type; /*< GPS velocity type: 0-NONE,2-DOPPLER_VELOCITY*/
} alink_raw_rtk_t;

#define ALINK_MSG_ID_RAW_RTK_LEN 70
#define ALINK_MSG_ID_21_LEN 70

#define ALINK_MSG_ID_RAW_RTK_CRC 158
#define ALINK_MSG_ID_21_CRC 158



#define ALINK_MESSAGE_INFO_RAW_RTK { \
	"RAW_RTK", \
	21, \
	{  { "timestamp", NULL, ALINK_TYPE_UINT64_T, 0, 0, offsetof(alink_raw_rtk_t, timestamp) }, \
         { "gspd", NULL, ALINK_TYPE_INT32_T, 0, 8, offsetof(alink_raw_rtk_t, gspd) }, \
         { "velN", NULL, ALINK_TYPE_INT32_T, 0, 12, offsetof(alink_raw_rtk_t, velN) }, \
         { "velE", NULL, ALINK_TYPE_INT32_T, 0, 16, offsetof(alink_raw_rtk_t, velE) }, \
         { "velD", NULL, ALINK_TYPE_INT32_T, 0, 20, offsetof(alink_raw_rtk_t, velD) }, \
         { "velN_sigma", NULL, ALINK_TYPE_INT32_T, 0, 24, offsetof(alink_raw_rtk_t, velN_sigma) }, \
         { "velE_sigma", NULL, ALINK_TYPE_INT32_T, 0, 28, offsetof(alink_raw_rtk_t, velE_sigma) }, \
         { "velD_sigma", NULL, ALINK_TYPE_INT32_T, 0, 32, offsetof(alink_raw_rtk_t, velD_sigma) }, \
         { "vel_latench", NULL, ALINK_TYPE_INT32_T, 0, 36, offsetof(alink_raw_rtk_t, vel_latench) }, \
         { "posN", NULL, ALINK_TYPE_INT32_T, 0, 40, offsetof(alink_raw_rtk_t, posN) }, \
         { "posE", NULL, ALINK_TYPE_INT32_T, 0, 44, offsetof(alink_raw_rtk_t, posE) }, \
         { "posD", NULL, ALINK_TYPE_INT32_T, 0, 48, offsetof(alink_raw_rtk_t, posD) }, \
         { "posN_sigma", NULL, ALINK_TYPE_INT32_T, 0, 52, offsetof(alink_raw_rtk_t, posN_sigma) }, \
         { "posE_sigma", NULL, ALINK_TYPE_INT32_T, 0, 56, offsetof(alink_raw_rtk_t, posE_sigma) }, \
         { "posD_sigma", NULL, ALINK_TYPE_INT32_T, 0, 60, offsetof(alink_raw_rtk_t, posD_sigma) }, \
         { "Svs", NULL, ALINK_TYPE_UINT8_T, 0, 64, offsetof(alink_raw_rtk_t, Svs) }, \
         { "slon_Svs", NULL, ALINK_TYPE_UINT8_T, 0, 65, offsetof(alink_raw_rtk_t, slon_Svs) }, \
         { "pos_status", NULL, ALINK_TYPE_UINT8_T, 0, 66, offsetof(alink_raw_rtk_t, pos_status) }, \
         { "pos_type", NULL, ALINK_TYPE_UINT8_T, 0, 67, offsetof(alink_raw_rtk_t, pos_type) }, \
         { "vel_status", NULL, ALINK_TYPE_UINT8_T, 0, 68, offsetof(alink_raw_rtk_t, vel_status) }, \
         { "vel_type", NULL, ALINK_TYPE_UINT8_T, 0, 69, offsetof(alink_raw_rtk_t, vel_type) }, \
         } \
}


/**
 * @brief Pack a raw_rtk message
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 *
 * @param timestamp timestamp (microseconds since UNIX epoch or microseconds since system boot)
 * @param gspd GPS ground speed (m/s)
 * @param velN GPS ground speed in m/s
 * @param velE GPS ground speed in m/s
 * @param velD GPS ground speed in m/s
 * @param velN_sigma GPS ground speed quality in sigma
 * @param velE_sigma GPS ground speed quality in sigma
 * @param velD_sigma GPS ground speed quality in sigma
 * @param vel_latench GPS ground speed latench
 * @param posN GPS location X in m
 * @param posE GPS location Y in m
 * @param posD GPS location Z in m
 * @param posN_sigma GPS location X quality in sigma
 * @param posE_sigma GPS location Y quality in sigma
 * @param posD_sigma GPS location Z quality in sigma
 * @param Svs GPS satellites
 * @param slon_Svs GPS satellites by used
 * @param pos_status GPS position status: 0-SOLCOMPUTED,1-INSUFFICIENT_OBS,3-COVTRAC
 * @param pos_type GPS position type: 0-NONE, 1-FIXEDPOS
 * @param vel_status GPS velocity status: 0-SOLCOMPUTED,1-INSUFFICIENT_OBS,3-COVTRAC
 * @param vel_type GPS velocity type: 0-NONE,2-DOPPLER_VELOCITY
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_raw_rtk_pack(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg,
						       uint64_t timestamp, int32_t gspd, int32_t velN, int32_t velE, int32_t velD, int32_t velN_sigma, int32_t velE_sigma, int32_t velD_sigma, int32_t vel_latench, int32_t posN, int32_t posE, int32_t posD, int32_t posN_sigma, int32_t posE_sigma, int32_t posD_sigma, uint8_t Svs, uint8_t slon_Svs, uint8_t pos_status, uint8_t pos_type, uint8_t vel_status, uint8_t vel_type)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_RAW_RTK_LEN];
	_mav_put_uint64_t(buf, 0, timestamp);
	_mav_put_int32_t(buf, 8, gspd);
	_mav_put_int32_t(buf, 12, velN);
	_mav_put_int32_t(buf, 16, velE);
	_mav_put_int32_t(buf, 20, velD);
	_mav_put_int32_t(buf, 24, velN_sigma);
	_mav_put_int32_t(buf, 28, velE_sigma);
	_mav_put_int32_t(buf, 32, velD_sigma);
	_mav_put_int32_t(buf, 36, vel_latench);
	_mav_put_int32_t(buf, 40, posN);
	_mav_put_int32_t(buf, 44, posE);
	_mav_put_int32_t(buf, 48, posD);
	_mav_put_int32_t(buf, 52, posN_sigma);
	_mav_put_int32_t(buf, 56, posE_sigma);
	_mav_put_int32_t(buf, 60, posD_sigma);
	_mav_put_uint8_t(buf, 64, Svs);
	_mav_put_uint8_t(buf, 65, slon_Svs);
	_mav_put_uint8_t(buf, 66, pos_status);
	_mav_put_uint8_t(buf, 67, pos_type);
	_mav_put_uint8_t(buf, 68, vel_status);
	_mav_put_uint8_t(buf, 69, vel_type);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_RAW_RTK_LEN);
#else
	alink_raw_rtk_t packet;
	packet.timestamp = timestamp;
	packet.gspd = gspd;
	packet.velN = velN;
	packet.velE = velE;
	packet.velD = velD;
	packet.velN_sigma = velN_sigma;
	packet.velE_sigma = velE_sigma;
	packet.velD_sigma = velD_sigma;
	packet.vel_latench = vel_latench;
	packet.posN = posN;
	packet.posE = posE;
	packet.posD = posD;
	packet.posN_sigma = posN_sigma;
	packet.posE_sigma = posE_sigma;
	packet.posD_sigma = posD_sigma;
	packet.Svs = Svs;
	packet.slon_Svs = slon_Svs;
	packet.pos_status = pos_status;
	packet.pos_type = pos_type;
	packet.vel_status = vel_status;
	packet.vel_type = vel_type;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_RAW_RTK_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_RAW_RTK;
#if ALINK_CRC_EXTRA
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_RAW_RTK_LEN,ALINK_MSG_ID_RAW_RTK_CRC);
#else
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_RAW_RTK_LEN);
#endif
}

/**
 * @brief Pack a raw_rtk message on a channel
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param timestamp timestamp (microseconds since UNIX epoch or microseconds since system boot)
 * @param gspd GPS ground speed (m/s)
 * @param velN GPS ground speed in m/s
 * @param velE GPS ground speed in m/s
 * @param velD GPS ground speed in m/s
 * @param velN_sigma GPS ground speed quality in sigma
 * @param velE_sigma GPS ground speed quality in sigma
 * @param velD_sigma GPS ground speed quality in sigma
 * @param vel_latench GPS ground speed latench
 * @param posN GPS location X in m
 * @param posE GPS location Y in m
 * @param posD GPS location Z in m
 * @param posN_sigma GPS location X quality in sigma
 * @param posE_sigma GPS location Y quality in sigma
 * @param posD_sigma GPS location Z quality in sigma
 * @param Svs GPS satellites
 * @param slon_Svs GPS satellites by used
 * @param pos_status GPS position status: 0-SOLCOMPUTED,1-INSUFFICIENT_OBS,3-COVTRAC
 * @param pos_type GPS position type: 0-NONE, 1-FIXEDPOS
 * @param vel_status GPS velocity status: 0-SOLCOMPUTED,1-INSUFFICIENT_OBS,3-COVTRAC
 * @param vel_type GPS velocity type: 0-NONE,2-DOPPLER_VELOCITY
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_raw_rtk_pack_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan,
							   alink_message_head_t* msg,
						           uint64_t timestamp,int32_t gspd,int32_t velN,int32_t velE,int32_t velD,int32_t velN_sigma,int32_t velE_sigma,int32_t velD_sigma,int32_t vel_latench,int32_t posN,int32_t posE,int32_t posD,int32_t posN_sigma,int32_t posE_sigma,int32_t posD_sigma,uint8_t Svs,uint8_t slon_Svs,uint8_t pos_status,uint8_t pos_type,uint8_t vel_status,uint8_t vel_type)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_RAW_RTK_LEN];
	_mav_put_uint64_t(buf, 0, timestamp);
	_mav_put_int32_t(buf, 8, gspd);
	_mav_put_int32_t(buf, 12, velN);
	_mav_put_int32_t(buf, 16, velE);
	_mav_put_int32_t(buf, 20, velD);
	_mav_put_int32_t(buf, 24, velN_sigma);
	_mav_put_int32_t(buf, 28, velE_sigma);
	_mav_put_int32_t(buf, 32, velD_sigma);
	_mav_put_int32_t(buf, 36, vel_latench);
	_mav_put_int32_t(buf, 40, posN);
	_mav_put_int32_t(buf, 44, posE);
	_mav_put_int32_t(buf, 48, posD);
	_mav_put_int32_t(buf, 52, posN_sigma);
	_mav_put_int32_t(buf, 56, posE_sigma);
	_mav_put_int32_t(buf, 60, posD_sigma);
	_mav_put_uint8_t(buf, 64, Svs);
	_mav_put_uint8_t(buf, 65, slon_Svs);
	_mav_put_uint8_t(buf, 66, pos_status);
	_mav_put_uint8_t(buf, 67, pos_type);
	_mav_put_uint8_t(buf, 68, vel_status);
	_mav_put_uint8_t(buf, 69, vel_type);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_RAW_RTK_LEN);
#else
	alink_raw_rtk_t packet;
	packet.timestamp = timestamp;
	packet.gspd = gspd;
	packet.velN = velN;
	packet.velE = velE;
	packet.velD = velD;
	packet.velN_sigma = velN_sigma;
	packet.velE_sigma = velE_sigma;
	packet.velD_sigma = velD_sigma;
	packet.vel_latench = vel_latench;
	packet.posN = posN;
	packet.posE = posE;
	packet.posD = posD;
	packet.posN_sigma = posN_sigma;
	packet.posE_sigma = posE_sigma;
	packet.posD_sigma = posD_sigma;
	packet.Svs = Svs;
	packet.slon_Svs = slon_Svs;
	packet.pos_status = pos_status;
	packet.pos_type = pos_type;
	packet.vel_status = vel_status;
	packet.vel_type = vel_type;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_RAW_RTK_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_RAW_RTK;
#if ALINK_CRC_EXTRA
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_RAW_RTK_LEN,ALINK_MSG_ID_RAW_RTK_CRC);
#else
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_RAW_RTK_LEN);
#endif
}
/**
 * @brief Encode a raw_rtk struct
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 * @param raw_rtk C-struct to read the message contents from
 */
static inline uint16_t alink_msg_raw_rtk_encode(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg, const alink_raw_rtk_t* raw_rtk)
{
	return alink_msg_raw_rtk_pack(dest_id, source_id, msg, raw_rtk->timestamp, raw_rtk->gspd, raw_rtk->velN, raw_rtk->velE, raw_rtk->velD, raw_rtk->velN_sigma, raw_rtk->velE_sigma, raw_rtk->velD_sigma, raw_rtk->vel_latench, raw_rtk->posN, raw_rtk->posE, raw_rtk->posD, raw_rtk->posN_sigma, raw_rtk->posE_sigma, raw_rtk->posD_sigma, raw_rtk->Svs, raw_rtk->slon_Svs, raw_rtk->pos_status, raw_rtk->pos_type, raw_rtk->vel_status, raw_rtk->vel_type);
}

/**
 * @brief Encode a raw_rtk struct on a channel
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param raw_rtk C-struct to read the message contents from
 */
static inline uint16_t alink_msg_raw_rtk_encode_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan, alink_message_head_t* msg, const alink_raw_rtk_t* raw_rtk)
{
	return alink_msg_raw_rtk_pack_chan(dest_id, source_id, chan, msg, raw_rtk->timestamp, raw_rtk->gspd, raw_rtk->velN, raw_rtk->velE, raw_rtk->velD, raw_rtk->velN_sigma, raw_rtk->velE_sigma, raw_rtk->velD_sigma, raw_rtk->vel_latench, raw_rtk->posN, raw_rtk->posE, raw_rtk->posD, raw_rtk->posN_sigma, raw_rtk->posE_sigma, raw_rtk->posD_sigma, raw_rtk->Svs, raw_rtk->slon_Svs, raw_rtk->pos_status, raw_rtk->pos_type, raw_rtk->vel_status, raw_rtk->vel_type);
}
// MESSAGE RAW_RTK UNPACKING


/**
 * @brief Get field timestamp from raw_rtk message
 *
 * @return timestamp (microseconds since UNIX epoch or microseconds since system boot)
 */
static inline uint64_t alink_msg_raw_rtk_get_timestamp(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field gspd from raw_rtk message
 *
 * @return GPS ground speed (m/s)
 */
static inline int32_t alink_msg_raw_rtk_get_gspd(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  8);
}

/**
 * @brief Get field velN from raw_rtk message
 *
 * @return GPS ground speed in m/s
 */
static inline int32_t alink_msg_raw_rtk_get_velN(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  12);
}

/**
 * @brief Get field velE from raw_rtk message
 *
 * @return GPS ground speed in m/s
 */
static inline int32_t alink_msg_raw_rtk_get_velE(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  16);
}

/**
 * @brief Get field velD from raw_rtk message
 *
 * @return GPS ground speed in m/s
 */
static inline int32_t alink_msg_raw_rtk_get_velD(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  20);
}

/**
 * @brief Get field velN_sigma from raw_rtk message
 *
 * @return GPS ground speed quality in sigma
 */
static inline int32_t alink_msg_raw_rtk_get_velN_sigma(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  24);
}

/**
 * @brief Get field velE_sigma from raw_rtk message
 *
 * @return GPS ground speed quality in sigma
 */
static inline int32_t alink_msg_raw_rtk_get_velE_sigma(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  28);
}

/**
 * @brief Get field velD_sigma from raw_rtk message
 *
 * @return GPS ground speed quality in sigma
 */
static inline int32_t alink_msg_raw_rtk_get_velD_sigma(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  32);
}

/**
 * @brief Get field vel_latench from raw_rtk message
 *
 * @return GPS ground speed latench
 */
static inline int32_t alink_msg_raw_rtk_get_vel_latench(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  36);
}

/**
 * @brief Get field posN from raw_rtk message
 *
 * @return GPS location X in m
 */
static inline int32_t alink_msg_raw_rtk_get_posN(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  40);
}

/**
 * @brief Get field posE from raw_rtk message
 *
 * @return GPS location Y in m
 */
static inline int32_t alink_msg_raw_rtk_get_posE(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  44);
}

/**
 * @brief Get field posD from raw_rtk message
 *
 * @return GPS location Z in m
 */
static inline int32_t alink_msg_raw_rtk_get_posD(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  48);
}

/**
 * @brief Get field posN_sigma from raw_rtk message
 *
 * @return GPS location X quality in sigma
 */
static inline int32_t alink_msg_raw_rtk_get_posN_sigma(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  52);
}

/**
 * @brief Get field posE_sigma from raw_rtk message
 *
 * @return GPS location Y quality in sigma
 */
static inline int32_t alink_msg_raw_rtk_get_posE_sigma(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  56);
}

/**
 * @brief Get field posD_sigma from raw_rtk message
 *
 * @return GPS location Z quality in sigma
 */
static inline int32_t alink_msg_raw_rtk_get_posD_sigma(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  60);
}

/**
 * @brief Get field Svs from raw_rtk message
 *
 * @return GPS satellites
 */
static inline uint8_t alink_msg_raw_rtk_get_Svs(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  64);
}

/**
 * @brief Get field slon_Svs from raw_rtk message
 *
 * @return GPS satellites by used
 */
static inline uint8_t alink_msg_raw_rtk_get_slon_Svs(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  65);
}

/**
 * @brief Get field pos_status from raw_rtk message
 *
 * @return GPS position status: 0-SOLCOMPUTED,1-INSUFFICIENT_OBS,3-COVTRAC
 */
static inline uint8_t alink_msg_raw_rtk_get_pos_status(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  66);
}

/**
 * @brief Get field pos_type from raw_rtk message
 *
 * @return GPS position type: 0-NONE, 1-FIXEDPOS
 */
static inline uint8_t alink_msg_raw_rtk_get_pos_type(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  67);
}

/**
 * @brief Get field vel_status from raw_rtk message
 *
 * @return GPS velocity status: 0-SOLCOMPUTED,1-INSUFFICIENT_OBS,3-COVTRAC
 */
static inline uint8_t alink_msg_raw_rtk_get_vel_status(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  68);
}

/**
 * @brief Get field vel_type from raw_rtk message
 *
 * @return GPS velocity type: 0-NONE,2-DOPPLER_VELOCITY
 */
static inline uint8_t alink_msg_raw_rtk_get_vel_type(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  69);
}

/**
 * @brief Decode a raw_rtk message into a struct
 *
 * @param msg The message to decode
 * @param raw_rtk C-struct to decode the message contents into
 */
static inline void alink_msg_raw_rtk_decode(const alink_message_head_t* msg, alink_raw_rtk_t* raw_rtk)
{
#if ALINK_NEED_BYTE_SWAP
	raw_rtk->timestamp = alink_msg_raw_rtk_get_timestamp(msg);
	raw_rtk->gspd = alink_msg_raw_rtk_get_gspd(msg);
	raw_rtk->velN = alink_msg_raw_rtk_get_velN(msg);
	raw_rtk->velE = alink_msg_raw_rtk_get_velE(msg);
	raw_rtk->velD = alink_msg_raw_rtk_get_velD(msg);
	raw_rtk->velN_sigma = alink_msg_raw_rtk_get_velN_sigma(msg);
	raw_rtk->velE_sigma = alink_msg_raw_rtk_get_velE_sigma(msg);
	raw_rtk->velD_sigma = alink_msg_raw_rtk_get_velD_sigma(msg);
	raw_rtk->vel_latench = alink_msg_raw_rtk_get_vel_latench(msg);
	raw_rtk->posN = alink_msg_raw_rtk_get_posN(msg);
	raw_rtk->posE = alink_msg_raw_rtk_get_posE(msg);
	raw_rtk->posD = alink_msg_raw_rtk_get_posD(msg);
	raw_rtk->posN_sigma = alink_msg_raw_rtk_get_posN_sigma(msg);
	raw_rtk->posE_sigma = alink_msg_raw_rtk_get_posE_sigma(msg);
	raw_rtk->posD_sigma = alink_msg_raw_rtk_get_posD_sigma(msg);
	raw_rtk->Svs = alink_msg_raw_rtk_get_Svs(msg);
	raw_rtk->slon_Svs = alink_msg_raw_rtk_get_slon_Svs(msg);
	raw_rtk->pos_status = alink_msg_raw_rtk_get_pos_status(msg);
	raw_rtk->pos_type = alink_msg_raw_rtk_get_pos_type(msg);
	raw_rtk->vel_status = alink_msg_raw_rtk_get_vel_status(msg);
	raw_rtk->vel_type = alink_msg_raw_rtk_get_vel_type(msg);
#else
	memcpy(raw_rtk, _MAV_PAYLOAD(msg), ALINK_MSG_ID_RAW_RTK_LEN);
#endif
}
