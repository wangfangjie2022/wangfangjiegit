// MESSAGE VISION_MAG_INFO PACKING

#define ALINK_MSG_ID_VISION_MAG_INFO 74

typedef struct __alink_vision_mag_info_t
{
 uint32_t timestamp; /*< timestamp (milliseconds since system boot)*/
 int16_t mag[3]; /*< Magnetometer raw x/y/z in uT*/
} alink_vision_mag_info_t;

#define ALINK_MSG_ID_VISION_MAG_INFO_LEN 10
#define ALINK_MSG_ID_74_LEN 10

#define ALINK_MSG_ID_VISION_MAG_INFO_CRC 190
#define ALINK_MSG_ID_74_CRC 190

#define ALINK_MSG_VISION_MAG_INFO_FIELD_MAG_LEN 3

#define ALINK_MESSAGE_INFO_VISION_MAG_INFO { \
	"VISION_MAG_INFO", \
	2, \
	{  { "timestamp", NULL, ALINK_TYPE_UINT32_T, 0, 0, offsetof(alink_vision_mag_info_t, timestamp) }, \
         { "mag", NULL, ALINK_TYPE_INT16_T, 3, 4, offsetof(alink_vision_mag_info_t, mag) }, \
         } \
}


/**
 * @brief Pack a vision_mag_info message
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 *
 * @param timestamp timestamp (milliseconds since system boot)
 * @param mag Magnetometer raw x/y/z in uT
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_vision_mag_info_pack(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg,
						       uint32_t timestamp, const int16_t *mag)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_VISION_MAG_INFO_LEN];
	_mav_put_uint32_t(buf, 0, timestamp);
	_mav_put_int16_t_array(buf, 4, mag, 3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_VISION_MAG_INFO_LEN);
#else
	alink_vision_mag_info_t packet;
	packet.timestamp = timestamp;
	mav_array_memcpy(packet.mag, mag, sizeof(int16_t)*3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_VISION_MAG_INFO_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_VISION_MAG_INFO;
#if ALINK_CRC_EXTRA
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_VISION_MAG_INFO_LEN,ALINK_MSG_ID_VISION_MAG_INFO_CRC);
#else
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_VISION_MAG_INFO_LEN);
#endif
}

/**
 * @brief Pack a vision_mag_info message on a channel
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param timestamp timestamp (milliseconds since system boot)
 * @param mag Magnetometer raw x/y/z in uT
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_vision_mag_info_pack_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan,
							   alink_message_head_t* msg,
						           uint32_t timestamp,const int16_t *mag)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_VISION_MAG_INFO_LEN];
	_mav_put_uint32_t(buf, 0, timestamp);
	_mav_put_int16_t_array(buf, 4, mag, 3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_VISION_MAG_INFO_LEN);
#else
	alink_vision_mag_info_t packet;
	packet.timestamp = timestamp;
	mav_array_memcpy(packet.mag, mag, sizeof(int16_t)*3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_VISION_MAG_INFO_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_VISION_MAG_INFO;
#if ALINK_CRC_EXTRA
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_VISION_MAG_INFO_LEN,ALINK_MSG_ID_VISION_MAG_INFO_CRC);
#else
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_VISION_MAG_INFO_LEN);
#endif
}
/**
 * @brief Encode a vision_mag_info struct
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 * @param vision_mag_info C-struct to read the message contents from
 */
static inline uint16_t alink_msg_vision_mag_info_encode(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg, const alink_vision_mag_info_t* vision_mag_info)
{
	return alink_msg_vision_mag_info_pack(dest_id, source_id, msg, vision_mag_info->timestamp, vision_mag_info->mag);
}

/**
 * @brief Encode a vision_mag_info struct on a channel
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param vision_mag_info C-struct to read the message contents from
 */
static inline uint16_t alink_msg_vision_mag_info_encode_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan, alink_message_head_t* msg, const alink_vision_mag_info_t* vision_mag_info)
{
	return alink_msg_vision_mag_info_pack_chan(dest_id, source_id, chan, msg, vision_mag_info->timestamp, vision_mag_info->mag);
}
// MESSAGE VISION_MAG_INFO UNPACKING


/**
 * @brief Get field timestamp from vision_mag_info message
 *
 * @return timestamp (milliseconds since system boot)
 */
static inline uint32_t alink_msg_vision_mag_info_get_timestamp(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field mag from vision_mag_info message
 *
 * @return Magnetometer raw x/y/z in uT
 */
static inline uint16_t alink_msg_vision_mag_info_get_mag(const alink_message_head_t* msg, int16_t *mag)
{
	return _MAV_RETURN_int16_t_array(msg, mag, 3,  4);
}

/**
 * @brief Decode a vision_mag_info message into a struct
 *
 * @param msg The message to decode
 * @param vision_mag_info C-struct to decode the message contents into
 */
static inline void alink_msg_vision_mag_info_decode(const alink_message_head_t* msg, alink_vision_mag_info_t* vision_mag_info)
{
#if ALINK_NEED_BYTE_SWAP
	vision_mag_info->timestamp = alink_msg_vision_mag_info_get_timestamp(msg);
	alink_msg_vision_mag_info_get_mag(msg, vision_mag_info->mag);
#else
	memcpy(vision_mag_info, _MAV_PAYLOAD(msg), ALINK_MSG_ID_VISION_MAG_INFO_LEN);
#endif
}
