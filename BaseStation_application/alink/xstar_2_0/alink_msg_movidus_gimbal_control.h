// MESSAGE MOVIDUS_GIMBAL_CONTROL PACKING

#define ALINK_MSG_ID_MOVIDUS_GIMBAL_CONTROL 114

typedef struct __alink_movidus_gimbal_control_t
{
 uint32_t timestamp; /*< timestamp (milliseconds since system boot)*/
 int16_t roll_dot; /*<  roll angle rate in 10E-3 rad/s */
 int16_t pitch_dot; /*<  pitch angle rate in 10E-3 rad/s */
 int16_t yaw_dot; /*<  yaw angle rate in 10E-3 rad/s */
} alink_movidus_gimbal_control_t;

#define ALINK_MSG_ID_MOVIDUS_GIMBAL_CONTROL_LEN 10
#define ALINK_MSG_ID_114_LEN 10

#define ALINK_MSG_ID_MOVIDUS_GIMBAL_CONTROL_CRC 34
#define ALINK_MSG_ID_114_CRC 34



#define ALINK_MESSAGE_INFO_MOVIDUS_GIMBAL_CONTROL { \
	"MOVIDUS_GIMBAL_CONTROL", \
	4, \
	{  { "timestamp", NULL, ALINK_TYPE_UINT32_T, 0, 0, offsetof(alink_movidus_gimbal_control_t, timestamp) }, \
         { "roll_dot", NULL, ALINK_TYPE_INT16_T, 0, 4, offsetof(alink_movidus_gimbal_control_t, roll_dot) }, \
         { "pitch_dot", NULL, ALINK_TYPE_INT16_T, 0, 6, offsetof(alink_movidus_gimbal_control_t, pitch_dot) }, \
         { "yaw_dot", NULL, ALINK_TYPE_INT16_T, 0, 8, offsetof(alink_movidus_gimbal_control_t, yaw_dot) }, \
         } \
}


/**
 * @brief Pack a movidus_gimbal_control message
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 *
 * @param timestamp timestamp (milliseconds since system boot)
 * @param roll_dot  roll angle rate in 10E-3 rad/s 
 * @param pitch_dot  pitch angle rate in 10E-3 rad/s 
 * @param yaw_dot  yaw angle rate in 10E-3 rad/s 
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_movidus_gimbal_control_pack(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg,
						       uint32_t timestamp, int16_t roll_dot, int16_t pitch_dot, int16_t yaw_dot)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_MOVIDUS_GIMBAL_CONTROL_LEN];
	_mav_put_uint32_t(buf, 0, timestamp);
	_mav_put_int16_t(buf, 4, roll_dot);
	_mav_put_int16_t(buf, 6, pitch_dot);
	_mav_put_int16_t(buf, 8, yaw_dot);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_MOVIDUS_GIMBAL_CONTROL_LEN);
#else
	alink_movidus_gimbal_control_t packet;
	packet.timestamp = timestamp;
	packet.roll_dot = roll_dot;
	packet.pitch_dot = pitch_dot;
	packet.yaw_dot = yaw_dot;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_MOVIDUS_GIMBAL_CONTROL_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_MOVIDUS_GIMBAL_CONTROL;
#if ALINK_CRC_EXTRA
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_MOVIDUS_GIMBAL_CONTROL_LEN,ALINK_MSG_ID_MOVIDUS_GIMBAL_CONTROL_CRC);
#else
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_MOVIDUS_GIMBAL_CONTROL_LEN);
#endif
}

/**
 * @brief Pack a movidus_gimbal_control message on a channel
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param timestamp timestamp (milliseconds since system boot)
 * @param roll_dot  roll angle rate in 10E-3 rad/s 
 * @param pitch_dot  pitch angle rate in 10E-3 rad/s 
 * @param yaw_dot  yaw angle rate in 10E-3 rad/s 
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_movidus_gimbal_control_pack_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan,
							   alink_message_head_t* msg,
						           uint32_t timestamp,int16_t roll_dot,int16_t pitch_dot,int16_t yaw_dot)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_MOVIDUS_GIMBAL_CONTROL_LEN];
	_mav_put_uint32_t(buf, 0, timestamp);
	_mav_put_int16_t(buf, 4, roll_dot);
	_mav_put_int16_t(buf, 6, pitch_dot);
	_mav_put_int16_t(buf, 8, yaw_dot);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_MOVIDUS_GIMBAL_CONTROL_LEN);
#else
	alink_movidus_gimbal_control_t packet;
	packet.timestamp = timestamp;
	packet.roll_dot = roll_dot;
	packet.pitch_dot = pitch_dot;
	packet.yaw_dot = yaw_dot;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_MOVIDUS_GIMBAL_CONTROL_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_MOVIDUS_GIMBAL_CONTROL;
#if ALINK_CRC_EXTRA
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_MOVIDUS_GIMBAL_CONTROL_LEN,ALINK_MSG_ID_MOVIDUS_GIMBAL_CONTROL_CRC);
#else
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_MOVIDUS_GIMBAL_CONTROL_LEN);
#endif
}
/**
 * @brief Encode a movidus_gimbal_control struct
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 * @param movidus_gimbal_control C-struct to read the message contents from
 */
static inline uint16_t alink_msg_movidus_gimbal_control_encode(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg, const alink_movidus_gimbal_control_t* movidus_gimbal_control)
{
	return alink_msg_movidus_gimbal_control_pack(dest_id, source_id, msg, movidus_gimbal_control->timestamp, movidus_gimbal_control->roll_dot, movidus_gimbal_control->pitch_dot, movidus_gimbal_control->yaw_dot);
}

/**
 * @brief Encode a movidus_gimbal_control struct on a channel
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param movidus_gimbal_control C-struct to read the message contents from
 */
static inline uint16_t alink_msg_movidus_gimbal_control_encode_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan, alink_message_head_t* msg, const alink_movidus_gimbal_control_t* movidus_gimbal_control)
{
	return alink_msg_movidus_gimbal_control_pack_chan(dest_id, source_id, chan, msg, movidus_gimbal_control->timestamp, movidus_gimbal_control->roll_dot, movidus_gimbal_control->pitch_dot, movidus_gimbal_control->yaw_dot);
}
// MESSAGE MOVIDUS_GIMBAL_CONTROL UNPACKING


/**
 * @brief Get field timestamp from movidus_gimbal_control message
 *
 * @return timestamp (milliseconds since system boot)
 */
static inline uint32_t alink_msg_movidus_gimbal_control_get_timestamp(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field roll_dot from movidus_gimbal_control message
 *
 * @return  roll angle rate in 10E-3 rad/s 
 */
static inline int16_t alink_msg_movidus_gimbal_control_get_roll_dot(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  4);
}

/**
 * @brief Get field pitch_dot from movidus_gimbal_control message
 *
 * @return  pitch angle rate in 10E-3 rad/s 
 */
static inline int16_t alink_msg_movidus_gimbal_control_get_pitch_dot(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  6);
}

/**
 * @brief Get field yaw_dot from movidus_gimbal_control message
 *
 * @return  yaw angle rate in 10E-3 rad/s 
 */
static inline int16_t alink_msg_movidus_gimbal_control_get_yaw_dot(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  8);
}

/**
 * @brief Decode a movidus_gimbal_control message into a struct
 *
 * @param msg The message to decode
 * @param movidus_gimbal_control C-struct to decode the message contents into
 */
static inline void alink_msg_movidus_gimbal_control_decode(const alink_message_head_t* msg, alink_movidus_gimbal_control_t* movidus_gimbal_control)
{
#if ALINK_NEED_BYTE_SWAP
	movidus_gimbal_control->timestamp = alink_msg_movidus_gimbal_control_get_timestamp(msg);
	movidus_gimbal_control->roll_dot = alink_msg_movidus_gimbal_control_get_roll_dot(msg);
	movidus_gimbal_control->pitch_dot = alink_msg_movidus_gimbal_control_get_pitch_dot(msg);
	movidus_gimbal_control->yaw_dot = alink_msg_movidus_gimbal_control_get_yaw_dot(msg);
#else
	memcpy(movidus_gimbal_control, _MAV_PAYLOAD(msg), ALINK_MSG_ID_MOVIDUS_GIMBAL_CONTROL_LEN);
#endif
}
