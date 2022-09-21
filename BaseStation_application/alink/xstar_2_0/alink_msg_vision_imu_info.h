// MESSAGE VISION_IMU_INFO PACKING

#define ALINK_MSG_ID_VISION_IMU_INFO 73

typedef struct __alink_vision_imu_info_t
{
 uint32_t timestamp; /*< timestamp (milliseconds since system boot)*/
 int16_t acc[3]; /*< acceleration x/y/z in 10E-2 m^2/s*/
 int16_t gyr[3]; /*< gyroscope x/y/z in 10E-3 rad/s*/
} alink_vision_imu_info_t;

#define ALINK_MSG_ID_VISION_IMU_INFO_LEN 16
#define ALINK_MSG_ID_73_LEN 16

#define ALINK_MSG_ID_VISION_IMU_INFO_CRC 196
#define ALINK_MSG_ID_73_CRC 196

#define ALINK_MSG_VISION_IMU_INFO_FIELD_ACC_LEN 3
#define ALINK_MSG_VISION_IMU_INFO_FIELD_GYR_LEN 3

#define ALINK_MESSAGE_INFO_VISION_IMU_INFO { \
	"VISION_IMU_INFO", \
	3, \
	{  { "timestamp", NULL, ALINK_TYPE_UINT32_T, 0, 0, offsetof(alink_vision_imu_info_t, timestamp) }, \
         { "acc", NULL, ALINK_TYPE_INT16_T, 3, 4, offsetof(alink_vision_imu_info_t, acc) }, \
         { "gyr", NULL, ALINK_TYPE_INT16_T, 3, 10, offsetof(alink_vision_imu_info_t, gyr) }, \
         } \
}


/**
 * @brief Pack a vision_imu_info message
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 *
 * @param timestamp timestamp (milliseconds since system boot)
 * @param acc acceleration x/y/z in 10E-2 m^2/s
 * @param gyr gyroscope x/y/z in 10E-3 rad/s
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_vision_imu_info_pack(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg,
						       uint32_t timestamp, const int16_t *acc, const int16_t *gyr)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_VISION_IMU_INFO_LEN];
	_mav_put_uint32_t(buf, 0, timestamp);
	_mav_put_int16_t_array(buf, 4, acc, 3);
	_mav_put_int16_t_array(buf, 10, gyr, 3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_VISION_IMU_INFO_LEN);
#else
	alink_vision_imu_info_t packet;
	packet.timestamp = timestamp;
	mav_array_memcpy(packet.acc, acc, sizeof(int16_t)*3);
	mav_array_memcpy(packet.gyr, gyr, sizeof(int16_t)*3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_VISION_IMU_INFO_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_VISION_IMU_INFO;
#if ALINK_CRC_EXTRA
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_VISION_IMU_INFO_LEN,ALINK_MSG_ID_VISION_IMU_INFO_CRC);
#else
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_VISION_IMU_INFO_LEN);
#endif
}

/**
 * @brief Pack a vision_imu_info message on a channel
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param timestamp timestamp (milliseconds since system boot)
 * @param acc acceleration x/y/z in 10E-2 m^2/s
 * @param gyr gyroscope x/y/z in 10E-3 rad/s
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_vision_imu_info_pack_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan,
							   alink_message_head_t* msg,
						           uint32_t timestamp,const int16_t *acc,const int16_t *gyr)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_VISION_IMU_INFO_LEN];
	_mav_put_uint32_t(buf, 0, timestamp);
	_mav_put_int16_t_array(buf, 4, acc, 3);
	_mav_put_int16_t_array(buf, 10, gyr, 3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_VISION_IMU_INFO_LEN);
#else
	alink_vision_imu_info_t packet;
	packet.timestamp = timestamp;
	mav_array_memcpy(packet.acc, acc, sizeof(int16_t)*3);
	mav_array_memcpy(packet.gyr, gyr, sizeof(int16_t)*3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_VISION_IMU_INFO_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_VISION_IMU_INFO;
#if ALINK_CRC_EXTRA
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_VISION_IMU_INFO_LEN,ALINK_MSG_ID_VISION_IMU_INFO_CRC);
#else
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_VISION_IMU_INFO_LEN);
#endif
}
/**
 * @brief Encode a vision_imu_info struct
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 * @param vision_imu_info C-struct to read the message contents from
 */
static inline uint16_t alink_msg_vision_imu_info_encode(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg, const alink_vision_imu_info_t* vision_imu_info)
{
	return alink_msg_vision_imu_info_pack(dest_id, source_id, msg, vision_imu_info->timestamp, vision_imu_info->acc, vision_imu_info->gyr);
}

/**
 * @brief Encode a vision_imu_info struct on a channel
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param vision_imu_info C-struct to read the message contents from
 */
static inline uint16_t alink_msg_vision_imu_info_encode_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan, alink_message_head_t* msg, const alink_vision_imu_info_t* vision_imu_info)
{
	return alink_msg_vision_imu_info_pack_chan(dest_id, source_id, chan, msg, vision_imu_info->timestamp, vision_imu_info->acc, vision_imu_info->gyr);
}
// MESSAGE VISION_IMU_INFO UNPACKING


/**
 * @brief Get field timestamp from vision_imu_info message
 *
 * @return timestamp (milliseconds since system boot)
 */
static inline uint32_t alink_msg_vision_imu_info_get_timestamp(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field acc from vision_imu_info message
 *
 * @return acceleration x/y/z in 10E-2 m^2/s
 */
static inline uint16_t alink_msg_vision_imu_info_get_acc(const alink_message_head_t* msg, int16_t *acc)
{
	return _MAV_RETURN_int16_t_array(msg, acc, 3,  4);
}

/**
 * @brief Get field gyr from vision_imu_info message
 *
 * @return gyroscope x/y/z in 10E-3 rad/s
 */
static inline uint16_t alink_msg_vision_imu_info_get_gyr(const alink_message_head_t* msg, int16_t *gyr)
{
	return _MAV_RETURN_int16_t_array(msg, gyr, 3,  10);
}

/**
 * @brief Decode a vision_imu_info message into a struct
 *
 * @param msg The message to decode
 * @param vision_imu_info C-struct to decode the message contents into
 */
static inline void alink_msg_vision_imu_info_decode(const alink_message_head_t* msg, alink_vision_imu_info_t* vision_imu_info)
{
#if ALINK_NEED_BYTE_SWAP
	vision_imu_info->timestamp = alink_msg_vision_imu_info_get_timestamp(msg);
	alink_msg_vision_imu_info_get_acc(msg, vision_imu_info->acc);
	alink_msg_vision_imu_info_get_gyr(msg, vision_imu_info->gyr);
#else
	memcpy(vision_imu_info, _MAV_PAYLOAD(msg), ALINK_MSG_ID_VISION_IMU_INFO_LEN);
#endif
}
