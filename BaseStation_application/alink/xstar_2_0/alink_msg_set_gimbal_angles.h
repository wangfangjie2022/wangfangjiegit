// MESSAGE SET_GIMBAL_ANGLES PACKING

#define ALINK_MSG_ID_SET_GIMBAL_ANGLES 50

typedef struct __alink_set_gimbal_angles_t
{
 int16_t roll; /*< Roll angle in 10E-2 degrees, if INT16_MAX dont set*/
 int16_t pitch; /*< Pitch angle in 10E-2 degrees, if INT16_MAX dont set*/
 int16_t yaw; /*< Yaw angle in 10E-2 degrees, if INT16_MAX dont set*/
} alink_set_gimbal_angles_t;

#define ALINK_MSG_ID_SET_GIMBAL_ANGLES_LEN 6
#define ALINK_MSG_ID_50_LEN 6

#define ALINK_MSG_ID_SET_GIMBAL_ANGLES_CRC 194
#define ALINK_MSG_ID_50_CRC 194



#define ALINK_MESSAGE_INFO_SET_GIMBAL_ANGLES { \
	"SET_GIMBAL_ANGLES", \
	3, \
	{  { "roll", NULL, ALINK_TYPE_INT16_T, 0, 0, offsetof(alink_set_gimbal_angles_t, roll) }, \
         { "pitch", NULL, ALINK_TYPE_INT16_T, 0, 2, offsetof(alink_set_gimbal_angles_t, pitch) }, \
         { "yaw", NULL, ALINK_TYPE_INT16_T, 0, 4, offsetof(alink_set_gimbal_angles_t, yaw) }, \
         } \
}


/**
 * @brief Pack a set_gimbal_angles message
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 *
 * @param roll Roll angle in 10E-2 degrees, if INT16_MAX dont set
 * @param pitch Pitch angle in 10E-2 degrees, if INT16_MAX dont set
 * @param yaw Yaw angle in 10E-2 degrees, if INT16_MAX dont set
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_set_gimbal_angles_pack(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg,
						       int16_t roll, int16_t pitch, int16_t yaw)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_SET_GIMBAL_ANGLES_LEN];
	_mav_put_int16_t(buf, 0, roll);
	_mav_put_int16_t(buf, 2, pitch);
	_mav_put_int16_t(buf, 4, yaw);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_SET_GIMBAL_ANGLES_LEN);
#else
	alink_set_gimbal_angles_t packet;
	packet.roll = roll;
	packet.pitch = pitch;
	packet.yaw = yaw;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_SET_GIMBAL_ANGLES_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_SET_GIMBAL_ANGLES;
#if ALINK_CRC_EXTRA
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_SET_GIMBAL_ANGLES_LEN,ALINK_MSG_ID_SET_GIMBAL_ANGLES_CRC);
#else
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_SET_GIMBAL_ANGLES_LEN);
#endif
}

/**
 * @brief Pack a set_gimbal_angles message on a channel
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param roll Roll angle in 10E-2 degrees, if INT16_MAX dont set
 * @param pitch Pitch angle in 10E-2 degrees, if INT16_MAX dont set
 * @param yaw Yaw angle in 10E-2 degrees, if INT16_MAX dont set
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_set_gimbal_angles_pack_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan,
							   alink_message_head_t* msg,
						           int16_t roll,int16_t pitch,int16_t yaw)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_SET_GIMBAL_ANGLES_LEN];
	_mav_put_int16_t(buf, 0, roll);
	_mav_put_int16_t(buf, 2, pitch);
	_mav_put_int16_t(buf, 4, yaw);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_SET_GIMBAL_ANGLES_LEN);
#else
	alink_set_gimbal_angles_t packet;
	packet.roll = roll;
	packet.pitch = pitch;
	packet.yaw = yaw;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_SET_GIMBAL_ANGLES_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_SET_GIMBAL_ANGLES;
#if ALINK_CRC_EXTRA
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_SET_GIMBAL_ANGLES_LEN,ALINK_MSG_ID_SET_GIMBAL_ANGLES_CRC);
#else
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_SET_GIMBAL_ANGLES_LEN);
#endif
}
/**
 * @brief Encode a set_gimbal_angles struct
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 * @param set_gimbal_angles C-struct to read the message contents from
 */
static inline uint16_t alink_msg_set_gimbal_angles_encode(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg, const alink_set_gimbal_angles_t* set_gimbal_angles)
{
	return alink_msg_set_gimbal_angles_pack(dest_id, source_id, msg, set_gimbal_angles->roll, set_gimbal_angles->pitch, set_gimbal_angles->yaw);
}

/**
 * @brief Encode a set_gimbal_angles struct on a channel
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param set_gimbal_angles C-struct to read the message contents from
 */
static inline uint16_t alink_msg_set_gimbal_angles_encode_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan, alink_message_head_t* msg, const alink_set_gimbal_angles_t* set_gimbal_angles)
{
	return alink_msg_set_gimbal_angles_pack_chan(dest_id, source_id, chan, msg, set_gimbal_angles->roll, set_gimbal_angles->pitch, set_gimbal_angles->yaw);
}
// MESSAGE SET_GIMBAL_ANGLES UNPACKING


/**
 * @brief Get field roll from set_gimbal_angles message
 *
 * @return Roll angle in 10E-2 degrees, if INT16_MAX dont set
 */
static inline int16_t alink_msg_set_gimbal_angles_get_roll(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  0);
}

/**
 * @brief Get field pitch from set_gimbal_angles message
 *
 * @return Pitch angle in 10E-2 degrees, if INT16_MAX dont set
 */
static inline int16_t alink_msg_set_gimbal_angles_get_pitch(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  2);
}

/**
 * @brief Get field yaw from set_gimbal_angles message
 *
 * @return Yaw angle in 10E-2 degrees, if INT16_MAX dont set
 */
static inline int16_t alink_msg_set_gimbal_angles_get_yaw(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  4);
}

/**
 * @brief Decode a set_gimbal_angles message into a struct
 *
 * @param msg The message to decode
 * @param set_gimbal_angles C-struct to decode the message contents into
 */
static inline void alink_msg_set_gimbal_angles_decode(const alink_message_head_t* msg, alink_set_gimbal_angles_t* set_gimbal_angles)
{
#if ALINK_NEED_BYTE_SWAP
	set_gimbal_angles->roll = alink_msg_set_gimbal_angles_get_roll(msg);
	set_gimbal_angles->pitch = alink_msg_set_gimbal_angles_get_pitch(msg);
	set_gimbal_angles->yaw = alink_msg_set_gimbal_angles_get_yaw(msg);
#else
	memcpy(set_gimbal_angles, _MAV_PAYLOAD(msg), ALINK_MSG_ID_SET_GIMBAL_ANGLES_LEN);
#endif
}
