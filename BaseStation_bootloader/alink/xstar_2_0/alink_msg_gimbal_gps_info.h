// MESSAGE GIMBAL_GPS_INFO PACKING

#define ALINK_MSG_ID_GIMBAL_GPS_INFO 52

typedef struct __alink_gimbal_gps_info_t
{
 uint32_t timestamp; /*< timestamp (milliseconds since system boot)*/
 int32_t vel_ned[3]; /*< Velocity of N/E/D in 10E-3 m/s*/
 uint32_t accuracy_s; /*< accuracy of speed in 10E-3 m/s*/
} alink_gimbal_gps_info_t;

#define ALINK_MSG_ID_GIMBAL_GPS_INFO_LEN 20
#define ALINK_MSG_ID_52_LEN 20

#define ALINK_MSG_ID_GIMBAL_GPS_INFO_CRC 11
#define ALINK_MSG_ID_52_CRC 11

#define ALINK_MSG_GIMBAL_GPS_INFO_FIELD_VEL_NED_LEN 3

#define ALINK_MESSAGE_INFO_GIMBAL_GPS_INFO { \
	"GIMBAL_GPS_INFO", \
	3, \
	{  { "timestamp", NULL, ALINK_TYPE_UINT32_T, 0, 0, offsetof(alink_gimbal_gps_info_t, timestamp) }, \
         { "vel_ned", NULL, ALINK_TYPE_INT32_T, 3, 4, offsetof(alink_gimbal_gps_info_t, vel_ned) }, \
         { "accuracy_s", NULL, ALINK_TYPE_UINT32_T, 0, 16, offsetof(alink_gimbal_gps_info_t, accuracy_s) }, \
         } \
}


/**
 * @brief Pack a gimbal_gps_info message
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 *
 * @param timestamp timestamp (milliseconds since system boot)
 * @param vel_ned Velocity of N/E/D in 10E-3 m/s
 * @param accuracy_s accuracy of speed in 10E-3 m/s
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_gimbal_gps_info_pack(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg,
						       uint32_t timestamp, const int32_t *vel_ned, uint32_t accuracy_s)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_GIMBAL_GPS_INFO_LEN];
	_mav_put_uint32_t(buf, 0, timestamp);
	_mav_put_uint32_t(buf, 16, accuracy_s);
	_mav_put_int32_t_array(buf, 4, vel_ned, 3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_GIMBAL_GPS_INFO_LEN);
#else
	alink_gimbal_gps_info_t packet;
	packet.timestamp = timestamp;
	packet.accuracy_s = accuracy_s;
	mav_array_memcpy(packet.vel_ned, vel_ned, sizeof(int32_t)*3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_GIMBAL_GPS_INFO_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_GIMBAL_GPS_INFO;
#if ALINK_CRC_EXTRA
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_GIMBAL_GPS_INFO_LEN,ALINK_MSG_ID_GIMBAL_GPS_INFO_CRC);
#else
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_GIMBAL_GPS_INFO_LEN);
#endif
}

/**
 * @brief Pack a gimbal_gps_info message on a channel
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param timestamp timestamp (milliseconds since system boot)
 * @param vel_ned Velocity of N/E/D in 10E-3 m/s
 * @param accuracy_s accuracy of speed in 10E-3 m/s
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_gimbal_gps_info_pack_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan,
							   alink_message_head_t* msg,
						           uint32_t timestamp,const int32_t *vel_ned,uint32_t accuracy_s)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_GIMBAL_GPS_INFO_LEN];
	_mav_put_uint32_t(buf, 0, timestamp);
	_mav_put_uint32_t(buf, 16, accuracy_s);
	_mav_put_int32_t_array(buf, 4, vel_ned, 3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_GIMBAL_GPS_INFO_LEN);
#else
	alink_gimbal_gps_info_t packet;
	packet.timestamp = timestamp;
	packet.accuracy_s = accuracy_s;
	mav_array_memcpy(packet.vel_ned, vel_ned, sizeof(int32_t)*3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_GIMBAL_GPS_INFO_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_GIMBAL_GPS_INFO;
#if ALINK_CRC_EXTRA
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_GIMBAL_GPS_INFO_LEN,ALINK_MSG_ID_GIMBAL_GPS_INFO_CRC);
#else
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_GIMBAL_GPS_INFO_LEN);
#endif
}
/**
 * @brief Encode a gimbal_gps_info struct
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 * @param gimbal_gps_info C-struct to read the message contents from
 */
static inline uint16_t alink_msg_gimbal_gps_info_encode(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg, const alink_gimbal_gps_info_t* gimbal_gps_info)
{
	return alink_msg_gimbal_gps_info_pack(dest_id, source_id, msg, gimbal_gps_info->timestamp, gimbal_gps_info->vel_ned, gimbal_gps_info->accuracy_s);
}

/**
 * @brief Encode a gimbal_gps_info struct on a channel
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param gimbal_gps_info C-struct to read the message contents from
 */
static inline uint16_t alink_msg_gimbal_gps_info_encode_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan, alink_message_head_t* msg, const alink_gimbal_gps_info_t* gimbal_gps_info)
{
	return alink_msg_gimbal_gps_info_pack_chan(dest_id, source_id, chan, msg, gimbal_gps_info->timestamp, gimbal_gps_info->vel_ned, gimbal_gps_info->accuracy_s);
}
// MESSAGE GIMBAL_GPS_INFO UNPACKING


/**
 * @brief Get field timestamp from gimbal_gps_info message
 *
 * @return timestamp (milliseconds since system boot)
 */
static inline uint32_t alink_msg_gimbal_gps_info_get_timestamp(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field vel_ned from gimbal_gps_info message
 *
 * @return Velocity of N/E/D in 10E-3 m/s
 */
static inline uint16_t alink_msg_gimbal_gps_info_get_vel_ned(const alink_message_head_t* msg, int32_t *vel_ned)
{
	return _MAV_RETURN_int32_t_array(msg, vel_ned, 3,  4);
}

/**
 * @brief Get field accuracy_s from gimbal_gps_info message
 *
 * @return accuracy of speed in 10E-3 m/s
 */
static inline uint32_t alink_msg_gimbal_gps_info_get_accuracy_s(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint32_t(msg,  16);
}

/**
 * @brief Decode a gimbal_gps_info message into a struct
 *
 * @param msg The message to decode
 * @param gimbal_gps_info C-struct to decode the message contents into
 */
static inline void alink_msg_gimbal_gps_info_decode(const alink_message_head_t* msg, alink_gimbal_gps_info_t* gimbal_gps_info)
{
#if ALINK_NEED_BYTE_SWAP
	gimbal_gps_info->timestamp = alink_msg_gimbal_gps_info_get_timestamp(msg);
	alink_msg_gimbal_gps_info_get_vel_ned(msg, gimbal_gps_info->vel_ned);
	gimbal_gps_info->accuracy_s = alink_msg_gimbal_gps_info_get_accuracy_s(msg);
#else
	memcpy(gimbal_gps_info, _MAV_PAYLOAD(msg), ALINK_MSG_ID_GIMBAL_GPS_INFO_LEN);
#endif
}
