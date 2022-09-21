// MESSAGE VISION_BARO_INFO PACKING

#define ALINK_MSG_ID_VISION_BARO_INFO 75

typedef struct __alink_vision_baro_info_t
{
 uint32_t timestamp; /*< timestamp (milliseconds since system boot)*/
 float baro; /*< Barometer in Pa*/
 float temp; /*< Tempture in cesious degrees*/
} alink_vision_baro_info_t;

#define ALINK_MSG_ID_VISION_BARO_INFO_LEN 12
#define ALINK_MSG_ID_75_LEN 12

#define ALINK_MSG_ID_VISION_BARO_INFO_CRC 234
#define ALINK_MSG_ID_75_CRC 234



#define ALINK_MESSAGE_INFO_VISION_BARO_INFO { \
	"VISION_BARO_INFO", \
	3, \
	{  { "timestamp", NULL, ALINK_TYPE_UINT32_T, 0, 0, offsetof(alink_vision_baro_info_t, timestamp) }, \
         { "baro", NULL, ALINK_TYPE_FLOAT, 0, 4, offsetof(alink_vision_baro_info_t, baro) }, \
         { "temp", NULL, ALINK_TYPE_FLOAT, 0, 8, offsetof(alink_vision_baro_info_t, temp) }, \
         } \
}


/**
 * @brief Pack a vision_baro_info message
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 *
 * @param timestamp timestamp (milliseconds since system boot)
 * @param baro Barometer in Pa
 * @param temp Tempture in cesious degrees
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_vision_baro_info_pack(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg,
						       uint32_t timestamp, float baro, float temp)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_VISION_BARO_INFO_LEN];
	_mav_put_uint32_t(buf, 0, timestamp);
	_mav_put_float(buf, 4, baro);
	_mav_put_float(buf, 8, temp);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_VISION_BARO_INFO_LEN);
#else
	alink_vision_baro_info_t packet;
	packet.timestamp = timestamp;
	packet.baro = baro;
	packet.temp = temp;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_VISION_BARO_INFO_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_VISION_BARO_INFO;
#if ALINK_CRC_EXTRA
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_VISION_BARO_INFO_LEN,ALINK_MSG_ID_VISION_BARO_INFO_CRC);
#else
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_VISION_BARO_INFO_LEN);
#endif
}

/**
 * @brief Pack a vision_baro_info message on a channel
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param timestamp timestamp (milliseconds since system boot)
 * @param baro Barometer in Pa
 * @param temp Tempture in cesious degrees
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_vision_baro_info_pack_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan,
							   alink_message_head_t* msg,
						           uint32_t timestamp,float baro,float temp)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_VISION_BARO_INFO_LEN];
	_mav_put_uint32_t(buf, 0, timestamp);
	_mav_put_float(buf, 4, baro);
	_mav_put_float(buf, 8, temp);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_VISION_BARO_INFO_LEN);
#else
	alink_vision_baro_info_t packet;
	packet.timestamp = timestamp;
	packet.baro = baro;
	packet.temp = temp;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_VISION_BARO_INFO_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_VISION_BARO_INFO;
#if ALINK_CRC_EXTRA
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_VISION_BARO_INFO_LEN,ALINK_MSG_ID_VISION_BARO_INFO_CRC);
#else
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_VISION_BARO_INFO_LEN);
#endif
}
/**
 * @brief Encode a vision_baro_info struct
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 * @param vision_baro_info C-struct to read the message contents from
 */
static inline uint16_t alink_msg_vision_baro_info_encode(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg, const alink_vision_baro_info_t* vision_baro_info)
{
	return alink_msg_vision_baro_info_pack(dest_id, source_id, msg, vision_baro_info->timestamp, vision_baro_info->baro, vision_baro_info->temp);
}

/**
 * @brief Encode a vision_baro_info struct on a channel
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param vision_baro_info C-struct to read the message contents from
 */
static inline uint16_t alink_msg_vision_baro_info_encode_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan, alink_message_head_t* msg, const alink_vision_baro_info_t* vision_baro_info)
{
	return alink_msg_vision_baro_info_pack_chan(dest_id, source_id, chan, msg, vision_baro_info->timestamp, vision_baro_info->baro, vision_baro_info->temp);
}
// MESSAGE VISION_BARO_INFO UNPACKING


/**
 * @brief Get field timestamp from vision_baro_info message
 *
 * @return timestamp (milliseconds since system boot)
 */
static inline uint32_t alink_msg_vision_baro_info_get_timestamp(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field baro from vision_baro_info message
 *
 * @return Barometer in Pa
 */
static inline float alink_msg_vision_baro_info_get_baro(const alink_message_head_t* msg)
{
	return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field temp from vision_baro_info message
 *
 * @return Tempture in cesious degrees
 */
static inline float alink_msg_vision_baro_info_get_temp(const alink_message_head_t* msg)
{
	return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Decode a vision_baro_info message into a struct
 *
 * @param msg The message to decode
 * @param vision_baro_info C-struct to decode the message contents into
 */
static inline void alink_msg_vision_baro_info_decode(const alink_message_head_t* msg, alink_vision_baro_info_t* vision_baro_info)
{
#if ALINK_NEED_BYTE_SWAP
	vision_baro_info->timestamp = alink_msg_vision_baro_info_get_timestamp(msg);
	vision_baro_info->baro = alink_msg_vision_baro_info_get_baro(msg);
	vision_baro_info->temp = alink_msg_vision_baro_info_get_temp(msg);
#else
	memcpy(vision_baro_info, _MAV_PAYLOAD(msg), ALINK_MSG_ID_VISION_BARO_INFO_LEN);
#endif
}
