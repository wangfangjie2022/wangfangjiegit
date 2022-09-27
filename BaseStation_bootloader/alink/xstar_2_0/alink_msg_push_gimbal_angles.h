// MESSAGE PUSH_GIMBAL_ANGLES PACKING

#define ALINK_MSG_ID_PUSH_GIMBAL_ANGLES 55

typedef struct __alink_push_gimbal_angles_t
{
 uint32_t timestamp; /*< timestamp (milliseconds since system boot)*/
 uint32_t gimbal_state; /*< gimbal state bit-defined, bit0: OverTemperature, Bit1: Hardware failure, Bit2~Bit31: future use)*/
 int16_t roll; /*< Roll angle in 10E-2 degrees*/
 int16_t pitch; /*< Pitch angle in 10E-2 degrees*/
 int16_t yaw; /*< Yaw angle in 10E-2 degrees*/
 int16_t roll_speed; /*< Roll angular speed in 10E-2 degrees / second*/
 int16_t pitch_speed; /*< Pitch angular speed in 10E-2 degrees / second*/
 int16_t yaw_speed; /*< Yaw angular speed in 10E-2 degrees / second*/
 int16_t q_uav[4]; /*< UAV Quarternion q0(w),q1(x),q2(y),q3(z)*/
} alink_push_gimbal_angles_t;

#define ALINK_MSG_ID_PUSH_GIMBAL_ANGLES_LEN 28
#define ALINK_MSG_ID_55_LEN 28

#define ALINK_MSG_ID_PUSH_GIMBAL_ANGLES_CRC 251
#define ALINK_MSG_ID_55_CRC 251

#define ALINK_MSG_PUSH_GIMBAL_ANGLES_FIELD_Q_UAV_LEN 4

#define ALINK_MESSAGE_INFO_PUSH_GIMBAL_ANGLES { \
	"PUSH_GIMBAL_ANGLES", \
	9, \
	{  { "timestamp", NULL, ALINK_TYPE_UINT32_T, 0, 0, offsetof(alink_push_gimbal_angles_t, timestamp) }, \
         { "gimbal_state", NULL, ALINK_TYPE_UINT32_T, 0, 4, offsetof(alink_push_gimbal_angles_t, gimbal_state) }, \
         { "roll", NULL, ALINK_TYPE_INT16_T, 0, 8, offsetof(alink_push_gimbal_angles_t, roll) }, \
         { "pitch", NULL, ALINK_TYPE_INT16_T, 0, 10, offsetof(alink_push_gimbal_angles_t, pitch) }, \
         { "yaw", NULL, ALINK_TYPE_INT16_T, 0, 12, offsetof(alink_push_gimbal_angles_t, yaw) }, \
         { "roll_speed", NULL, ALINK_TYPE_INT16_T, 0, 14, offsetof(alink_push_gimbal_angles_t, roll_speed) }, \
         { "pitch_speed", NULL, ALINK_TYPE_INT16_T, 0, 16, offsetof(alink_push_gimbal_angles_t, pitch_speed) }, \
         { "yaw_speed", NULL, ALINK_TYPE_INT16_T, 0, 18, offsetof(alink_push_gimbal_angles_t, yaw_speed) }, \
         { "q_uav", NULL, ALINK_TYPE_INT16_T, 4, 20, offsetof(alink_push_gimbal_angles_t, q_uav) }, \
         } \
}


/**
 * @brief Pack a push_gimbal_angles message
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 *
 * @param timestamp timestamp (milliseconds since system boot)
 * @param gimbal_state gimbal state bit-defined, bit0: OverTemperature, Bit1: Hardware failure, Bit2~Bit31: future use)
 * @param roll Roll angle in 10E-2 degrees
 * @param pitch Pitch angle in 10E-2 degrees
 * @param yaw Yaw angle in 10E-2 degrees
 * @param roll_speed Roll angular speed in 10E-2 degrees / second
 * @param pitch_speed Pitch angular speed in 10E-2 degrees / second
 * @param yaw_speed Yaw angular speed in 10E-2 degrees / second
 * @param q_uav UAV Quarternion q0(w),q1(x),q2(y),q3(z)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_push_gimbal_angles_pack(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg,
						       uint32_t timestamp, uint32_t gimbal_state, int16_t roll, int16_t pitch, int16_t yaw, int16_t roll_speed, int16_t pitch_speed, int16_t yaw_speed, const int16_t *q_uav)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_PUSH_GIMBAL_ANGLES_LEN];
	_mav_put_uint32_t(buf, 0, timestamp);
	_mav_put_uint32_t(buf, 4, gimbal_state);
	_mav_put_int16_t(buf, 8, roll);
	_mav_put_int16_t(buf, 10, pitch);
	_mav_put_int16_t(buf, 12, yaw);
	_mav_put_int16_t(buf, 14, roll_speed);
	_mav_put_int16_t(buf, 16, pitch_speed);
	_mav_put_int16_t(buf, 18, yaw_speed);
	_mav_put_int16_t_array(buf, 20, q_uav, 4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_PUSH_GIMBAL_ANGLES_LEN);
#else
	alink_push_gimbal_angles_t packet;
	packet.timestamp = timestamp;
	packet.gimbal_state = gimbal_state;
	packet.roll = roll;
	packet.pitch = pitch;
	packet.yaw = yaw;
	packet.roll_speed = roll_speed;
	packet.pitch_speed = pitch_speed;
	packet.yaw_speed = yaw_speed;
	mav_array_memcpy(packet.q_uav, q_uav, sizeof(int16_t)*4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_PUSH_GIMBAL_ANGLES_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_PUSH_GIMBAL_ANGLES;
#if ALINK_CRC_EXTRA
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_PUSH_GIMBAL_ANGLES_LEN,ALINK_MSG_ID_PUSH_GIMBAL_ANGLES_CRC);
#else
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_PUSH_GIMBAL_ANGLES_LEN);
#endif
}

/**
 * @brief Pack a push_gimbal_angles message on a channel
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param timestamp timestamp (milliseconds since system boot)
 * @param gimbal_state gimbal state bit-defined, bit0: OverTemperature, Bit1: Hardware failure, Bit2~Bit31: future use)
 * @param roll Roll angle in 10E-2 degrees
 * @param pitch Pitch angle in 10E-2 degrees
 * @param yaw Yaw angle in 10E-2 degrees
 * @param roll_speed Roll angular speed in 10E-2 degrees / second
 * @param pitch_speed Pitch angular speed in 10E-2 degrees / second
 * @param yaw_speed Yaw angular speed in 10E-2 degrees / second
 * @param q_uav UAV Quarternion q0(w),q1(x),q2(y),q3(z)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_push_gimbal_angles_pack_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan,
							   alink_message_head_t* msg,
						           uint32_t timestamp,uint32_t gimbal_state,int16_t roll,int16_t pitch,int16_t yaw,int16_t roll_speed,int16_t pitch_speed,int16_t yaw_speed,const int16_t *q_uav)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_PUSH_GIMBAL_ANGLES_LEN];
	_mav_put_uint32_t(buf, 0, timestamp);
	_mav_put_uint32_t(buf, 4, gimbal_state);
	_mav_put_int16_t(buf, 8, roll);
	_mav_put_int16_t(buf, 10, pitch);
	_mav_put_int16_t(buf, 12, yaw);
	_mav_put_int16_t(buf, 14, roll_speed);
	_mav_put_int16_t(buf, 16, pitch_speed);
	_mav_put_int16_t(buf, 18, yaw_speed);
	_mav_put_int16_t_array(buf, 20, q_uav, 4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_PUSH_GIMBAL_ANGLES_LEN);
#else
	alink_push_gimbal_angles_t packet;
	packet.timestamp = timestamp;
	packet.gimbal_state = gimbal_state;
	packet.roll = roll;
	packet.pitch = pitch;
	packet.yaw = yaw;
	packet.roll_speed = roll_speed;
	packet.pitch_speed = pitch_speed;
	packet.yaw_speed = yaw_speed;
	mav_array_memcpy(packet.q_uav, q_uav, sizeof(int16_t)*4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_PUSH_GIMBAL_ANGLES_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_PUSH_GIMBAL_ANGLES;
#if ALINK_CRC_EXTRA
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_PUSH_GIMBAL_ANGLES_LEN,ALINK_MSG_ID_PUSH_GIMBAL_ANGLES_CRC);
#else
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_PUSH_GIMBAL_ANGLES_LEN);
#endif
}
/**
 * @brief Encode a push_gimbal_angles struct
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 * @param push_gimbal_angles C-struct to read the message contents from
 */
static inline uint16_t alink_msg_push_gimbal_angles_encode(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg, const alink_push_gimbal_angles_t* push_gimbal_angles)
{
	return alink_msg_push_gimbal_angles_pack(dest_id, source_id, msg, push_gimbal_angles->timestamp, push_gimbal_angles->gimbal_state, push_gimbal_angles->roll, push_gimbal_angles->pitch, push_gimbal_angles->yaw, push_gimbal_angles->roll_speed, push_gimbal_angles->pitch_speed, push_gimbal_angles->yaw_speed, push_gimbal_angles->q_uav);
}

/**
 * @brief Encode a push_gimbal_angles struct on a channel
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param push_gimbal_angles C-struct to read the message contents from
 */
static inline uint16_t alink_msg_push_gimbal_angles_encode_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan, alink_message_head_t* msg, const alink_push_gimbal_angles_t* push_gimbal_angles)
{
	return alink_msg_push_gimbal_angles_pack_chan(dest_id, source_id, chan, msg, push_gimbal_angles->timestamp, push_gimbal_angles->gimbal_state, push_gimbal_angles->roll, push_gimbal_angles->pitch, push_gimbal_angles->yaw, push_gimbal_angles->roll_speed, push_gimbal_angles->pitch_speed, push_gimbal_angles->yaw_speed, push_gimbal_angles->q_uav);
}
// MESSAGE PUSH_GIMBAL_ANGLES UNPACKING


/**
 * @brief Get field timestamp from push_gimbal_angles message
 *
 * @return timestamp (milliseconds since system boot)
 */
static inline uint32_t alink_msg_push_gimbal_angles_get_timestamp(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field gimbal_state from push_gimbal_angles message
 *
 * @return gimbal state bit-defined, bit0: OverTemperature, Bit1: Hardware failure, Bit2~Bit31: future use)
 */
static inline uint32_t alink_msg_push_gimbal_angles_get_gimbal_state(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint32_t(msg,  4);
}

/**
 * @brief Get field roll from push_gimbal_angles message
 *
 * @return Roll angle in 10E-2 degrees
 */
static inline int16_t alink_msg_push_gimbal_angles_get_roll(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  8);
}

/**
 * @brief Get field pitch from push_gimbal_angles message
 *
 * @return Pitch angle in 10E-2 degrees
 */
static inline int16_t alink_msg_push_gimbal_angles_get_pitch(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  10);
}

/**
 * @brief Get field yaw from push_gimbal_angles message
 *
 * @return Yaw angle in 10E-2 degrees
 */
static inline int16_t alink_msg_push_gimbal_angles_get_yaw(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  12);
}

/**
 * @brief Get field roll_speed from push_gimbal_angles message
 *
 * @return Roll angular speed in 10E-2 degrees / second
 */
static inline int16_t alink_msg_push_gimbal_angles_get_roll_speed(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  14);
}

/**
 * @brief Get field pitch_speed from push_gimbal_angles message
 *
 * @return Pitch angular speed in 10E-2 degrees / second
 */
static inline int16_t alink_msg_push_gimbal_angles_get_pitch_speed(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  16);
}

/**
 * @brief Get field yaw_speed from push_gimbal_angles message
 *
 * @return Yaw angular speed in 10E-2 degrees / second
 */
static inline int16_t alink_msg_push_gimbal_angles_get_yaw_speed(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  18);
}

/**
 * @brief Get field q_uav from push_gimbal_angles message
 *
 * @return UAV Quarternion q0(w),q1(x),q2(y),q3(z)
 */
static inline uint16_t alink_msg_push_gimbal_angles_get_q_uav(const alink_message_head_t* msg, int16_t *q_uav)
{
	return _MAV_RETURN_int16_t_array(msg, q_uav, 4,  20);
}

/**
 * @brief Decode a push_gimbal_angles message into a struct
 *
 * @param msg The message to decode
 * @param push_gimbal_angles C-struct to decode the message contents into
 */
static inline void alink_msg_push_gimbal_angles_decode(const alink_message_head_t* msg, alink_push_gimbal_angles_t* push_gimbal_angles)
{
#if ALINK_NEED_BYTE_SWAP
	push_gimbal_angles->timestamp = alink_msg_push_gimbal_angles_get_timestamp(msg);
	push_gimbal_angles->gimbal_state = alink_msg_push_gimbal_angles_get_gimbal_state(msg);
	push_gimbal_angles->roll = alink_msg_push_gimbal_angles_get_roll(msg);
	push_gimbal_angles->pitch = alink_msg_push_gimbal_angles_get_pitch(msg);
	push_gimbal_angles->yaw = alink_msg_push_gimbal_angles_get_yaw(msg);
	push_gimbal_angles->roll_speed = alink_msg_push_gimbal_angles_get_roll_speed(msg);
	push_gimbal_angles->pitch_speed = alink_msg_push_gimbal_angles_get_pitch_speed(msg);
	push_gimbal_angles->yaw_speed = alink_msg_push_gimbal_angles_get_yaw_speed(msg);
	alink_msg_push_gimbal_angles_get_q_uav(msg, push_gimbal_angles->q_uav);
#else
	memcpy(push_gimbal_angles, _MAV_PAYLOAD(msg), ALINK_MSG_ID_PUSH_GIMBAL_ANGLES_LEN);
#endif
}
