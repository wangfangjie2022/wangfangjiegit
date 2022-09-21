// MESSAGE SET_GIMBAL_ANGLES_SPEED PACKING

#define ALINK_MSG_ID_SET_GIMBAL_ANGLES_SPEED 49

typedef struct __alink_set_gimbal_angles_speed_t
{
 int16_t roll_speed; /*< Roll angle speed in 10E-2 degrees / second, if INT16_MAX dont set*/
 int16_t pitch_speed; /*< Pitch angle speed in 10E-2 degrees / second, if INT16_MAX dont set*/
 int16_t yaw_speed; /*< Yaw angle speed in 10E-2 degrees / second, if INT16_MAX dont set*/
} alink_set_gimbal_angles_speed_t;

#define ALINK_MSG_ID_SET_GIMBAL_ANGLES_SPEED_LEN 6
#define ALINK_MSG_ID_49_LEN 6

#define ALINK_MSG_ID_SET_GIMBAL_ANGLES_SPEED_CRC 12
#define ALINK_MSG_ID_49_CRC 12



#define ALINK_MESSAGE_INFO_SET_GIMBAL_ANGLES_SPEED { \
	"SET_GIMBAL_ANGLES_SPEED", \
	3, \
	{  { "roll_speed", NULL, ALINK_TYPE_INT16_T, 0, 0, offsetof(alink_set_gimbal_angles_speed_t, roll_speed) }, \
         { "pitch_speed", NULL, ALINK_TYPE_INT16_T, 0, 2, offsetof(alink_set_gimbal_angles_speed_t, pitch_speed) }, \
         { "yaw_speed", NULL, ALINK_TYPE_INT16_T, 0, 4, offsetof(alink_set_gimbal_angles_speed_t, yaw_speed) }, \
         } \
}


/**
 * @brief Pack a set_gimbal_angles_speed message
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 *
 * @param roll_speed Roll angle speed in 10E-2 degrees / second, if INT16_MAX dont set
 * @param pitch_speed Pitch angle speed in 10E-2 degrees / second, if INT16_MAX dont set
 * @param yaw_speed Yaw angle speed in 10E-2 degrees / second, if INT16_MAX dont set
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_set_gimbal_angles_speed_pack(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg,
						       int16_t roll_speed, int16_t pitch_speed, int16_t yaw_speed)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_SET_GIMBAL_ANGLES_SPEED_LEN];
	_mav_put_int16_t(buf, 0, roll_speed);
	_mav_put_int16_t(buf, 2, pitch_speed);
	_mav_put_int16_t(buf, 4, yaw_speed);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_SET_GIMBAL_ANGLES_SPEED_LEN);
#else
	alink_set_gimbal_angles_speed_t packet;
	packet.roll_speed = roll_speed;
	packet.pitch_speed = pitch_speed;
	packet.yaw_speed = yaw_speed;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_SET_GIMBAL_ANGLES_SPEED_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_SET_GIMBAL_ANGLES_SPEED;
#if ALINK_CRC_EXTRA
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_SET_GIMBAL_ANGLES_SPEED_LEN,ALINK_MSG_ID_SET_GIMBAL_ANGLES_SPEED_CRC);
#else
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_SET_GIMBAL_ANGLES_SPEED_LEN);
#endif
}

/**
 * @brief Pack a set_gimbal_angles_speed message on a channel
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param roll_speed Roll angle speed in 10E-2 degrees / second, if INT16_MAX dont set
 * @param pitch_speed Pitch angle speed in 10E-2 degrees / second, if INT16_MAX dont set
 * @param yaw_speed Yaw angle speed in 10E-2 degrees / second, if INT16_MAX dont set
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_set_gimbal_angles_speed_pack_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan,
							   alink_message_head_t* msg,
						           int16_t roll_speed,int16_t pitch_speed,int16_t yaw_speed)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_SET_GIMBAL_ANGLES_SPEED_LEN];
	_mav_put_int16_t(buf, 0, roll_speed);
	_mav_put_int16_t(buf, 2, pitch_speed);
	_mav_put_int16_t(buf, 4, yaw_speed);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_SET_GIMBAL_ANGLES_SPEED_LEN);
#else
	alink_set_gimbal_angles_speed_t packet;
	packet.roll_speed = roll_speed;
	packet.pitch_speed = pitch_speed;
	packet.yaw_speed = yaw_speed;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_SET_GIMBAL_ANGLES_SPEED_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_SET_GIMBAL_ANGLES_SPEED;
#if ALINK_CRC_EXTRA
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_SET_GIMBAL_ANGLES_SPEED_LEN,ALINK_MSG_ID_SET_GIMBAL_ANGLES_SPEED_CRC);
#else
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_SET_GIMBAL_ANGLES_SPEED_LEN);
#endif
}
/**
 * @brief Encode a set_gimbal_angles_speed struct
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 * @param set_gimbal_angles_speed C-struct to read the message contents from
 */
static inline uint16_t alink_msg_set_gimbal_angles_speed_encode(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg, const alink_set_gimbal_angles_speed_t* set_gimbal_angles_speed)
{
	return alink_msg_set_gimbal_angles_speed_pack(dest_id, source_id, msg, set_gimbal_angles_speed->roll_speed, set_gimbal_angles_speed->pitch_speed, set_gimbal_angles_speed->yaw_speed);
}

/**
 * @brief Encode a set_gimbal_angles_speed struct on a channel
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param set_gimbal_angles_speed C-struct to read the message contents from
 */
static inline uint16_t alink_msg_set_gimbal_angles_speed_encode_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan, alink_message_head_t* msg, const alink_set_gimbal_angles_speed_t* set_gimbal_angles_speed)
{
	return alink_msg_set_gimbal_angles_speed_pack_chan(dest_id, source_id, chan, msg, set_gimbal_angles_speed->roll_speed, set_gimbal_angles_speed->pitch_speed, set_gimbal_angles_speed->yaw_speed);
}
// MESSAGE SET_GIMBAL_ANGLES_SPEED UNPACKING


/**
 * @brief Get field roll_speed from set_gimbal_angles_speed message
 *
 * @return Roll angle speed in 10E-2 degrees / second, if INT16_MAX dont set
 */
static inline int16_t alink_msg_set_gimbal_angles_speed_get_roll_speed(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  0);
}

/**
 * @brief Get field pitch_speed from set_gimbal_angles_speed message
 *
 * @return Pitch angle speed in 10E-2 degrees / second, if INT16_MAX dont set
 */
static inline int16_t alink_msg_set_gimbal_angles_speed_get_pitch_speed(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  2);
}

/**
 * @brief Get field yaw_speed from set_gimbal_angles_speed message
 *
 * @return Yaw angle speed in 10E-2 degrees / second, if INT16_MAX dont set
 */
static inline int16_t alink_msg_set_gimbal_angles_speed_get_yaw_speed(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  4);
}

/**
 * @brief Decode a set_gimbal_angles_speed message into a struct
 *
 * @param msg The message to decode
 * @param set_gimbal_angles_speed C-struct to decode the message contents into
 */
static inline void alink_msg_set_gimbal_angles_speed_decode(const alink_message_head_t* msg, alink_set_gimbal_angles_speed_t* set_gimbal_angles_speed)
{
#if ALINK_NEED_BYTE_SWAP
	set_gimbal_angles_speed->roll_speed = alink_msg_set_gimbal_angles_speed_get_roll_speed(msg);
	set_gimbal_angles_speed->pitch_speed = alink_msg_set_gimbal_angles_speed_get_pitch_speed(msg);
	set_gimbal_angles_speed->yaw_speed = alink_msg_set_gimbal_angles_speed_get_yaw_speed(msg);
#else
	memcpy(set_gimbal_angles_speed, _MAV_PAYLOAD(msg), ALINK_MSG_ID_SET_GIMBAL_ANGLES_SPEED_LEN);
#endif
}
