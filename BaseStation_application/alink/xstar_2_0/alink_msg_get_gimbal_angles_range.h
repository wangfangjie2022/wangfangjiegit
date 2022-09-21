// MESSAGE GET_GIMBAL_ANGLES_RANGE PACKING

#define ALINK_MSG_ID_GET_GIMBAL_ANGLES_RANGE 51

typedef struct __alink_get_gimbal_angles_range_t
{
 int16_t roll_min; /*< Roll min angle in degrees*/
 int16_t roll_max; /*< Roll max angle in degrees*/
 int16_t pitch_min; /*< Pitch min angle in degrees*/
 int16_t pitch_max; /*< Pitch max angle in degrees*/
 int16_t yaw_min; /*< Yaw min angle in degrees*/
 int16_t yaw_max; /*< Yaw max angle in degrees*/
} alink_get_gimbal_angles_range_t;

#define ALINK_MSG_ID_GET_GIMBAL_ANGLES_RANGE_LEN 12
#define ALINK_MSG_ID_51_LEN 12

#define ALINK_MSG_ID_GET_GIMBAL_ANGLES_RANGE_CRC 122
#define ALINK_MSG_ID_51_CRC 122



#define ALINK_MESSAGE_INFO_GET_GIMBAL_ANGLES_RANGE { \
	"GET_GIMBAL_ANGLES_RANGE", \
	6, \
	{  { "roll_min", NULL, ALINK_TYPE_INT16_T, 0, 0, offsetof(alink_get_gimbal_angles_range_t, roll_min) }, \
         { "roll_max", NULL, ALINK_TYPE_INT16_T, 0, 2, offsetof(alink_get_gimbal_angles_range_t, roll_max) }, \
         { "pitch_min", NULL, ALINK_TYPE_INT16_T, 0, 4, offsetof(alink_get_gimbal_angles_range_t, pitch_min) }, \
         { "pitch_max", NULL, ALINK_TYPE_INT16_T, 0, 6, offsetof(alink_get_gimbal_angles_range_t, pitch_max) }, \
         { "yaw_min", NULL, ALINK_TYPE_INT16_T, 0, 8, offsetof(alink_get_gimbal_angles_range_t, yaw_min) }, \
         { "yaw_max", NULL, ALINK_TYPE_INT16_T, 0, 10, offsetof(alink_get_gimbal_angles_range_t, yaw_max) }, \
         } \
}


/**
 * @brief Pack a get_gimbal_angles_range message
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 *
 * @param roll_min Roll min angle in degrees
 * @param roll_max Roll max angle in degrees
 * @param pitch_min Pitch min angle in degrees
 * @param pitch_max Pitch max angle in degrees
 * @param yaw_min Yaw min angle in degrees
 * @param yaw_max Yaw max angle in degrees
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_get_gimbal_angles_range_pack(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg,
						       int16_t roll_min, int16_t roll_max, int16_t pitch_min, int16_t pitch_max, int16_t yaw_min, int16_t yaw_max)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_GET_GIMBAL_ANGLES_RANGE_LEN];
	_mav_put_int16_t(buf, 0, roll_min);
	_mav_put_int16_t(buf, 2, roll_max);
	_mav_put_int16_t(buf, 4, pitch_min);
	_mav_put_int16_t(buf, 6, pitch_max);
	_mav_put_int16_t(buf, 8, yaw_min);
	_mav_put_int16_t(buf, 10, yaw_max);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_GET_GIMBAL_ANGLES_RANGE_LEN);
#else
	alink_get_gimbal_angles_range_t packet;
	packet.roll_min = roll_min;
	packet.roll_max = roll_max;
	packet.pitch_min = pitch_min;
	packet.pitch_max = pitch_max;
	packet.yaw_min = yaw_min;
	packet.yaw_max = yaw_max;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_GET_GIMBAL_ANGLES_RANGE_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_GET_GIMBAL_ANGLES_RANGE;
#if ALINK_CRC_EXTRA
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_GET_GIMBAL_ANGLES_RANGE_LEN,ALINK_MSG_ID_GET_GIMBAL_ANGLES_RANGE_CRC);
#else
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_GET_GIMBAL_ANGLES_RANGE_LEN);
#endif
}

/**
 * @brief Pack a get_gimbal_angles_range message on a channel
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param roll_min Roll min angle in degrees
 * @param roll_max Roll max angle in degrees
 * @param pitch_min Pitch min angle in degrees
 * @param pitch_max Pitch max angle in degrees
 * @param yaw_min Yaw min angle in degrees
 * @param yaw_max Yaw max angle in degrees
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_get_gimbal_angles_range_pack_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan,
							   alink_message_head_t* msg,
						           int16_t roll_min,int16_t roll_max,int16_t pitch_min,int16_t pitch_max,int16_t yaw_min,int16_t yaw_max)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_GET_GIMBAL_ANGLES_RANGE_LEN];
	_mav_put_int16_t(buf, 0, roll_min);
	_mav_put_int16_t(buf, 2, roll_max);
	_mav_put_int16_t(buf, 4, pitch_min);
	_mav_put_int16_t(buf, 6, pitch_max);
	_mav_put_int16_t(buf, 8, yaw_min);
	_mav_put_int16_t(buf, 10, yaw_max);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_GET_GIMBAL_ANGLES_RANGE_LEN);
#else
	alink_get_gimbal_angles_range_t packet;
	packet.roll_min = roll_min;
	packet.roll_max = roll_max;
	packet.pitch_min = pitch_min;
	packet.pitch_max = pitch_max;
	packet.yaw_min = yaw_min;
	packet.yaw_max = yaw_max;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_GET_GIMBAL_ANGLES_RANGE_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_GET_GIMBAL_ANGLES_RANGE;
#if ALINK_CRC_EXTRA
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_GET_GIMBAL_ANGLES_RANGE_LEN,ALINK_MSG_ID_GET_GIMBAL_ANGLES_RANGE_CRC);
#else
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_GET_GIMBAL_ANGLES_RANGE_LEN);
#endif
}
/**
 * @brief Encode a get_gimbal_angles_range struct
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 * @param get_gimbal_angles_range C-struct to read the message contents from
 */
static inline uint16_t alink_msg_get_gimbal_angles_range_encode(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg, const alink_get_gimbal_angles_range_t* get_gimbal_angles_range)
{
	return alink_msg_get_gimbal_angles_range_pack(dest_id, source_id, msg, get_gimbal_angles_range->roll_min, get_gimbal_angles_range->roll_max, get_gimbal_angles_range->pitch_min, get_gimbal_angles_range->pitch_max, get_gimbal_angles_range->yaw_min, get_gimbal_angles_range->yaw_max);
}

/**
 * @brief Encode a get_gimbal_angles_range struct on a channel
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param get_gimbal_angles_range C-struct to read the message contents from
 */
static inline uint16_t alink_msg_get_gimbal_angles_range_encode_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan, alink_message_head_t* msg, const alink_get_gimbal_angles_range_t* get_gimbal_angles_range)
{
	return alink_msg_get_gimbal_angles_range_pack_chan(dest_id, source_id, chan, msg, get_gimbal_angles_range->roll_min, get_gimbal_angles_range->roll_max, get_gimbal_angles_range->pitch_min, get_gimbal_angles_range->pitch_max, get_gimbal_angles_range->yaw_min, get_gimbal_angles_range->yaw_max);
}
// MESSAGE GET_GIMBAL_ANGLES_RANGE UNPACKING


/**
 * @brief Get field roll_min from get_gimbal_angles_range message
 *
 * @return Roll min angle in degrees
 */
static inline int16_t alink_msg_get_gimbal_angles_range_get_roll_min(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  0);
}

/**
 * @brief Get field roll_max from get_gimbal_angles_range message
 *
 * @return Roll max angle in degrees
 */
static inline int16_t alink_msg_get_gimbal_angles_range_get_roll_max(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  2);
}

/**
 * @brief Get field pitch_min from get_gimbal_angles_range message
 *
 * @return Pitch min angle in degrees
 */
static inline int16_t alink_msg_get_gimbal_angles_range_get_pitch_min(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  4);
}

/**
 * @brief Get field pitch_max from get_gimbal_angles_range message
 *
 * @return Pitch max angle in degrees
 */
static inline int16_t alink_msg_get_gimbal_angles_range_get_pitch_max(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  6);
}

/**
 * @brief Get field yaw_min from get_gimbal_angles_range message
 *
 * @return Yaw min angle in degrees
 */
static inline int16_t alink_msg_get_gimbal_angles_range_get_yaw_min(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  8);
}

/**
 * @brief Get field yaw_max from get_gimbal_angles_range message
 *
 * @return Yaw max angle in degrees
 */
static inline int16_t alink_msg_get_gimbal_angles_range_get_yaw_max(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  10);
}

/**
 * @brief Decode a get_gimbal_angles_range message into a struct
 *
 * @param msg The message to decode
 * @param get_gimbal_angles_range C-struct to decode the message contents into
 */
static inline void alink_msg_get_gimbal_angles_range_decode(const alink_message_head_t* msg, alink_get_gimbal_angles_range_t* get_gimbal_angles_range)
{
#if ALINK_NEED_BYTE_SWAP
	get_gimbal_angles_range->roll_min = alink_msg_get_gimbal_angles_range_get_roll_min(msg);
	get_gimbal_angles_range->roll_max = alink_msg_get_gimbal_angles_range_get_roll_max(msg);
	get_gimbal_angles_range->pitch_min = alink_msg_get_gimbal_angles_range_get_pitch_min(msg);
	get_gimbal_angles_range->pitch_max = alink_msg_get_gimbal_angles_range_get_pitch_max(msg);
	get_gimbal_angles_range->yaw_min = alink_msg_get_gimbal_angles_range_get_yaw_min(msg);
	get_gimbal_angles_range->yaw_max = alink_msg_get_gimbal_angles_range_get_yaw_max(msg);
#else
	memcpy(get_gimbal_angles_range, _MAV_PAYLOAD(msg), ALINK_MSG_ID_GET_GIMBAL_ANGLES_RANGE_LEN);
#endif
}
