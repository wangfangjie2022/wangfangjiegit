// MESSAGE CALIB_PROCESS_INFO PACKING

#define ALINK_MSG_ID_CALIB_PROCESS_INFO 92

typedef struct __alink_calib_process_info_t
{
 uint64_t timestamp; /*< timestamp*/
 uint16_t mag_calib_process; /*< 0-100*/
 uint16_t airspeed_calib_process; /*< 0-100*/
 uint16_t reserve; /*< */
} alink_calib_process_info_t;

#define ALINK_MSG_ID_CALIB_PROCESS_INFO_LEN 14
#define ALINK_MSG_ID_92_LEN 14

#define ALINK_MSG_ID_CALIB_PROCESS_INFO_CRC 91
#define ALINK_MSG_ID_92_CRC 91



#define ALINK_MESSAGE_INFO_CALIB_PROCESS_INFO { \
	"CALIB_PROCESS_INFO", \
	4, \
	{  { "timestamp", NULL, ALINK_TYPE_UINT64_T, 0, 0, offsetof(alink_calib_process_info_t, timestamp) }, \
         { "mag_calib_process", NULL, ALINK_TYPE_UINT16_T, 0, 8, offsetof(alink_calib_process_info_t, mag_calib_process) }, \
         { "airspeed_calib_process", NULL, ALINK_TYPE_UINT16_T, 0, 10, offsetof(alink_calib_process_info_t, airspeed_calib_process) }, \
         { "reserve", NULL, ALINK_TYPE_UINT16_T, 0, 12, offsetof(alink_calib_process_info_t, reserve) }, \
         } \
}


/**
 * @brief Pack a calib_process_info message
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 *
 * @param timestamp timestamp
 * @param mag_calib_process 0-100
 * @param airspeed_calib_process 0-100
 * @param reserve 
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_calib_process_info_pack(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg,
						       uint64_t timestamp, uint16_t mag_calib_process, uint16_t airspeed_calib_process, uint16_t reserve)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_CALIB_PROCESS_INFO_LEN];
	_mav_put_uint64_t(buf, 0, timestamp);
	_mav_put_uint16_t(buf, 8, mag_calib_process);
	_mav_put_uint16_t(buf, 10, airspeed_calib_process);
	_mav_put_uint16_t(buf, 12, reserve);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_CALIB_PROCESS_INFO_LEN);
#else
	alink_calib_process_info_t packet;
	packet.timestamp = timestamp;
	packet.mag_calib_process = mag_calib_process;
	packet.airspeed_calib_process = airspeed_calib_process;
	packet.reserve = reserve;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_CALIB_PROCESS_INFO_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_CALIB_PROCESS_INFO;
#if ALINK_CRC_EXTRA
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_CALIB_PROCESS_INFO_LEN,ALINK_MSG_ID_CALIB_PROCESS_INFO_CRC);
#else
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_CALIB_PROCESS_INFO_LEN);
#endif
}

/**
 * @brief Pack a calib_process_info message on a channel
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param timestamp timestamp
 * @param mag_calib_process 0-100
 * @param airspeed_calib_process 0-100
 * @param reserve 
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_calib_process_info_pack_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan,
							   alink_message_head_t* msg,
						           uint64_t timestamp,uint16_t mag_calib_process,uint16_t airspeed_calib_process,uint16_t reserve)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_CALIB_PROCESS_INFO_LEN];
	_mav_put_uint64_t(buf, 0, timestamp);
	_mav_put_uint16_t(buf, 8, mag_calib_process);
	_mav_put_uint16_t(buf, 10, airspeed_calib_process);
	_mav_put_uint16_t(buf, 12, reserve);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_CALIB_PROCESS_INFO_LEN);
#else
	alink_calib_process_info_t packet;
	packet.timestamp = timestamp;
	packet.mag_calib_process = mag_calib_process;
	packet.airspeed_calib_process = airspeed_calib_process;
	packet.reserve = reserve;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_CALIB_PROCESS_INFO_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_CALIB_PROCESS_INFO;
#if ALINK_CRC_EXTRA
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_CALIB_PROCESS_INFO_LEN,ALINK_MSG_ID_CALIB_PROCESS_INFO_CRC);
#else
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_CALIB_PROCESS_INFO_LEN);
#endif
}
/**
 * @brief Encode a calib_process_info struct
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 * @param calib_process_info C-struct to read the message contents from
 */
static inline uint16_t alink_msg_calib_process_info_encode(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg, const alink_calib_process_info_t* calib_process_info)
{
	return alink_msg_calib_process_info_pack(dest_id, source_id, msg, calib_process_info->timestamp, calib_process_info->mag_calib_process, calib_process_info->airspeed_calib_process, calib_process_info->reserve);
}

/**
 * @brief Encode a calib_process_info struct on a channel
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param calib_process_info C-struct to read the message contents from
 */
static inline uint16_t alink_msg_calib_process_info_encode_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan, alink_message_head_t* msg, const alink_calib_process_info_t* calib_process_info)
{
	return alink_msg_calib_process_info_pack_chan(dest_id, source_id, chan, msg, calib_process_info->timestamp, calib_process_info->mag_calib_process, calib_process_info->airspeed_calib_process, calib_process_info->reserve);
}
// MESSAGE CALIB_PROCESS_INFO UNPACKING


/**
 * @brief Get field timestamp from calib_process_info message
 *
 * @return timestamp
 */
static inline uint64_t alink_msg_calib_process_info_get_timestamp(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field mag_calib_process from calib_process_info message
 *
 * @return 0-100
 */
static inline uint16_t alink_msg_calib_process_info_get_mag_calib_process(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  8);
}

/**
 * @brief Get field airspeed_calib_process from calib_process_info message
 *
 * @return 0-100
 */
static inline uint16_t alink_msg_calib_process_info_get_airspeed_calib_process(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  10);
}

/**
 * @brief Get field reserve from calib_process_info message
 *
 * @return 
 */
static inline uint16_t alink_msg_calib_process_info_get_reserve(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  12);
}

/**
 * @brief Decode a calib_process_info message into a struct
 *
 * @param msg The message to decode
 * @param calib_process_info C-struct to decode the message contents into
 */
static inline void alink_msg_calib_process_info_decode(const alink_message_head_t* msg, alink_calib_process_info_t* calib_process_info)
{
#if ALINK_NEED_BYTE_SWAP
	calib_process_info->timestamp = alink_msg_calib_process_info_get_timestamp(msg);
	calib_process_info->mag_calib_process = alink_msg_calib_process_info_get_mag_calib_process(msg);
	calib_process_info->airspeed_calib_process = alink_msg_calib_process_info_get_airspeed_calib_process(msg);
	calib_process_info->reserve = alink_msg_calib_process_info_get_reserve(msg);
#else
	memcpy(calib_process_info, _MAV_PAYLOAD(msg), ALINK_MSG_ID_CALIB_PROCESS_INFO_LEN);
#endif
}
