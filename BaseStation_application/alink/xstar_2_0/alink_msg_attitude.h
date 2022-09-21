// MESSAGE ATTITUDE PACKING

#define ALINK_MSG_ID_ATTITUDE 40

typedef struct __alink_attitude_t
{
 uint32_t timestamp; /*< timestamp (milliseconds since system boot)*/
 float roll; /*< Roll angle (rad, -pi..+pi)*/
 float pitch; /*< Pitch angle (rad, -pi..+pi)*/
 float yaw; /*< Yaw angle (rad, -pi..+pi)*/
 float rollspeed; /*< Roll angular speed (rad/s)*/
 float pitchspeed; /*< Pitch angular speed (rad/s)*/
 float yawspeed; /*< Yaw angular speed (rad/s)*/
} alink_attitude_t;

#define ALINK_MSG_ID_ATTITUDE_LEN 28
#define ALINK_MSG_ID_40_LEN 28

#define ALINK_MSG_ID_ATTITUDE_CRC 133
#define ALINK_MSG_ID_40_CRC 133



#define ALINK_MESSAGE_INFO_ATTITUDE { \
	"ATTITUDE", \
	7, \
	{  { "timestamp", NULL, ALINK_TYPE_UINT32_T, 0, 0, offsetof(alink_attitude_t, timestamp) }, \
         { "roll", NULL, ALINK_TYPE_FLOAT, 0, 4, offsetof(alink_attitude_t, roll) }, \
         { "pitch", NULL, ALINK_TYPE_FLOAT, 0, 8, offsetof(alink_attitude_t, pitch) }, \
         { "yaw", NULL, ALINK_TYPE_FLOAT, 0, 12, offsetof(alink_attitude_t, yaw) }, \
         { "rollspeed", NULL, ALINK_TYPE_FLOAT, 0, 16, offsetof(alink_attitude_t, rollspeed) }, \
         { "pitchspeed", NULL, ALINK_TYPE_FLOAT, 0, 20, offsetof(alink_attitude_t, pitchspeed) }, \
         { "yawspeed", NULL, ALINK_TYPE_FLOAT, 0, 24, offsetof(alink_attitude_t, yawspeed) }, \
         } \
}


/**
 * @brief Pack a attitude message
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 *
 * @param timestamp timestamp (milliseconds since system boot)
 * @param roll Roll angle (rad, -pi..+pi)
 * @param pitch Pitch angle (rad, -pi..+pi)
 * @param yaw Yaw angle (rad, -pi..+pi)
 * @param rollspeed Roll angular speed (rad/s)
 * @param pitchspeed Pitch angular speed (rad/s)
 * @param yawspeed Yaw angular speed (rad/s)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_attitude_pack(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg,
						       uint32_t timestamp, float roll, float pitch, float yaw, float rollspeed, float pitchspeed, float yawspeed)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_ATTITUDE_LEN];
	_mav_put_uint32_t(buf, 0, timestamp);
	_mav_put_float(buf, 4, roll);
	_mav_put_float(buf, 8, pitch);
	_mav_put_float(buf, 12, yaw);
	_mav_put_float(buf, 16, rollspeed);
	_mav_put_float(buf, 20, pitchspeed);
	_mav_put_float(buf, 24, yawspeed);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_ATTITUDE_LEN);
#else
	alink_attitude_t packet;
	packet.timestamp = timestamp;
	packet.roll = roll;
	packet.pitch = pitch;
	packet.yaw = yaw;
	packet.rollspeed = rollspeed;
	packet.pitchspeed = pitchspeed;
	packet.yawspeed = yawspeed;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_ATTITUDE_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_ATTITUDE;
#if ALINK_CRC_EXTRA
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_ATTITUDE_LEN,ALINK_MSG_ID_ATTITUDE_CRC);
#else
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_ATTITUDE_LEN);
#endif
}

/**
 * @brief Pack a attitude message on a channel
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param timestamp timestamp (milliseconds since system boot)
 * @param roll Roll angle (rad, -pi..+pi)
 * @param pitch Pitch angle (rad, -pi..+pi)
 * @param yaw Yaw angle (rad, -pi..+pi)
 * @param rollspeed Roll angular speed (rad/s)
 * @param pitchspeed Pitch angular speed (rad/s)
 * @param yawspeed Yaw angular speed (rad/s)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_attitude_pack_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan,
							   alink_message_head_t* msg,
						           uint32_t timestamp,float roll,float pitch,float yaw,float rollspeed,float pitchspeed,float yawspeed)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_ATTITUDE_LEN];
	_mav_put_uint32_t(buf, 0, timestamp);
	_mav_put_float(buf, 4, roll);
	_mav_put_float(buf, 8, pitch);
	_mav_put_float(buf, 12, yaw);
	_mav_put_float(buf, 16, rollspeed);
	_mav_put_float(buf, 20, pitchspeed);
	_mav_put_float(buf, 24, yawspeed);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_ATTITUDE_LEN);
#else
	alink_attitude_t packet;
	packet.timestamp = timestamp;
	packet.roll = roll;
	packet.pitch = pitch;
	packet.yaw = yaw;
	packet.rollspeed = rollspeed;
	packet.pitchspeed = pitchspeed;
	packet.yawspeed = yawspeed;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_ATTITUDE_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_ATTITUDE;
#if ALINK_CRC_EXTRA
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_ATTITUDE_LEN,ALINK_MSG_ID_ATTITUDE_CRC);
#else
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_ATTITUDE_LEN);
#endif
}
/**
 * @brief Encode a attitude struct
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 * @param attitude C-struct to read the message contents from
 */
static inline uint16_t alink_msg_attitude_encode(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg, const alink_attitude_t* attitude)
{
	return alink_msg_attitude_pack(dest_id, source_id, msg, attitude->timestamp, attitude->roll, attitude->pitch, attitude->yaw, attitude->rollspeed, attitude->pitchspeed, attitude->yawspeed);
}

/**
 * @brief Encode a attitude struct on a channel
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param attitude C-struct to read the message contents from
 */
static inline uint16_t alink_msg_attitude_encode_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan, alink_message_head_t* msg, const alink_attitude_t* attitude)
{
	return alink_msg_attitude_pack_chan(dest_id, source_id, chan, msg, attitude->timestamp, attitude->roll, attitude->pitch, attitude->yaw, attitude->rollspeed, attitude->pitchspeed, attitude->yawspeed);
}
// MESSAGE ATTITUDE UNPACKING


/**
 * @brief Get field timestamp from attitude message
 *
 * @return timestamp (milliseconds since system boot)
 */
static inline uint32_t alink_msg_attitude_get_timestamp(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field roll from attitude message
 *
 * @return Roll angle (rad, -pi..+pi)
 */
static inline float alink_msg_attitude_get_roll(const alink_message_head_t* msg)
{
	return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field pitch from attitude message
 *
 * @return Pitch angle (rad, -pi..+pi)
 */
static inline float alink_msg_attitude_get_pitch(const alink_message_head_t* msg)
{
	return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field yaw from attitude message
 *
 * @return Yaw angle (rad, -pi..+pi)
 */
static inline float alink_msg_attitude_get_yaw(const alink_message_head_t* msg)
{
	return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field rollspeed from attitude message
 *
 * @return Roll angular speed (rad/s)
 */
static inline float alink_msg_attitude_get_rollspeed(const alink_message_head_t* msg)
{
	return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Get field pitchspeed from attitude message
 *
 * @return Pitch angular speed (rad/s)
 */
static inline float alink_msg_attitude_get_pitchspeed(const alink_message_head_t* msg)
{
	return _MAV_RETURN_float(msg,  20);
}

/**
 * @brief Get field yawspeed from attitude message
 *
 * @return Yaw angular speed (rad/s)
 */
static inline float alink_msg_attitude_get_yawspeed(const alink_message_head_t* msg)
{
	return _MAV_RETURN_float(msg,  24);
}

/**
 * @brief Decode a attitude message into a struct
 *
 * @param msg The message to decode
 * @param attitude C-struct to decode the message contents into
 */
static inline void alink_msg_attitude_decode(const alink_message_head_t* msg, alink_attitude_t* attitude)
{
#if ALINK_NEED_BYTE_SWAP
	attitude->timestamp = alink_msg_attitude_get_timestamp(msg);
	attitude->roll = alink_msg_attitude_get_roll(msg);
	attitude->pitch = alink_msg_attitude_get_pitch(msg);
	attitude->yaw = alink_msg_attitude_get_yaw(msg);
	attitude->rollspeed = alink_msg_attitude_get_rollspeed(msg);
	attitude->pitchspeed = alink_msg_attitude_get_pitchspeed(msg);
	attitude->yawspeed = alink_msg_attitude_get_yawspeed(msg);
#else
	memcpy(attitude, _MAV_PAYLOAD(msg), ALINK_MSG_ID_ATTITUDE_LEN);
#endif
}
