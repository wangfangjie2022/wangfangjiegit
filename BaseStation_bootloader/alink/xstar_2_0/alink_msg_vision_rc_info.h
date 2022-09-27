// MESSAGE VISION_RC_INFO PACKING

#define ALINK_MSG_ID_VISION_RC_INFO 77

typedef struct __alink_vision_rc_info_t
{
 uint32_t timestamp; /*< timestamp (milliseconds since system boot)*/
 int16_t button; /*< Button command, 625 : arm button 1157: go home button 1423: Pause_Button 891:  Takeoff Landing button */
 int16_t mode; /*< Main mode, 1024: ATT 1689: IOC 359: GPS*/
 int16_t gimbal_pitch; /*< gimbal pitch control, */
 int8_t roll; /*< Stick Command normalized to [-1, 1], float to int8 scale is 100*/
 int8_t pitch; /*< Stick Command normalized to [-1, 1], float to int8 scale is 100*/
 int8_t yaw; /*< Stick Command normalized to [-1, 1], float to int8 scale is 100*/
 int8_t thrust; /*< Thrust command, normalized to [-1, 1], float to int8 scale is 100*/
} alink_vision_rc_info_t;

#define ALINK_MSG_ID_VISION_RC_INFO_LEN 14
#define ALINK_MSG_ID_77_LEN 14

#define ALINK_MSG_ID_VISION_RC_INFO_CRC 64
#define ALINK_MSG_ID_77_CRC 64



#define ALINK_MESSAGE_INFO_VISION_RC_INFO { \
	"VISION_RC_INFO", \
	8, \
	{  { "timestamp", NULL, ALINK_TYPE_UINT32_T, 0, 0, offsetof(alink_vision_rc_info_t, timestamp) }, \
         { "button", NULL, ALINK_TYPE_INT16_T, 0, 4, offsetof(alink_vision_rc_info_t, button) }, \
         { "mode", NULL, ALINK_TYPE_INT16_T, 0, 6, offsetof(alink_vision_rc_info_t, mode) }, \
         { "gimbal_pitch", NULL, ALINK_TYPE_INT16_T, 0, 8, offsetof(alink_vision_rc_info_t, gimbal_pitch) }, \
         { "roll", NULL, ALINK_TYPE_INT8_T, 0, 10, offsetof(alink_vision_rc_info_t, roll) }, \
         { "pitch", NULL, ALINK_TYPE_INT8_T, 0, 11, offsetof(alink_vision_rc_info_t, pitch) }, \
         { "yaw", NULL, ALINK_TYPE_INT8_T, 0, 12, offsetof(alink_vision_rc_info_t, yaw) }, \
         { "thrust", NULL, ALINK_TYPE_INT8_T, 0, 13, offsetof(alink_vision_rc_info_t, thrust) }, \
         } \
}


/**
 * @brief Pack a vision_rc_info message
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 *
 * @param timestamp timestamp (milliseconds since system boot)
 * @param roll Stick Command normalized to [-1, 1], float to int8 scale is 100
 * @param pitch Stick Command normalized to [-1, 1], float to int8 scale is 100
 * @param yaw Stick Command normalized to [-1, 1], float to int8 scale is 100
 * @param thrust Thrust command, normalized to [-1, 1], float to int8 scale is 100
 * @param button Button command, 625 : arm button 1157: go home button 1423: Pause_Button 891:  Takeoff Landing button 
 * @param mode Main mode, 1024: ATT 1689: IOC 359: GPS
 * @param gimbal_pitch gimbal pitch control, 
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_vision_rc_info_pack(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg,
						       uint32_t timestamp, int8_t roll, int8_t pitch, int8_t yaw, int8_t thrust, int16_t button, int16_t mode, int16_t gimbal_pitch)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_VISION_RC_INFO_LEN];
	_mav_put_uint32_t(buf, 0, timestamp);
	_mav_put_int16_t(buf, 4, button);
	_mav_put_int16_t(buf, 6, mode);
	_mav_put_int16_t(buf, 8, gimbal_pitch);
	_mav_put_int8_t(buf, 10, roll);
	_mav_put_int8_t(buf, 11, pitch);
	_mav_put_int8_t(buf, 12, yaw);
	_mav_put_int8_t(buf, 13, thrust);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_VISION_RC_INFO_LEN);
#else
	alink_vision_rc_info_t packet;
	packet.timestamp = timestamp;
	packet.button = button;
	packet.mode = mode;
	packet.gimbal_pitch = gimbal_pitch;
	packet.roll = roll;
	packet.pitch = pitch;
	packet.yaw = yaw;
	packet.thrust = thrust;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_VISION_RC_INFO_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_VISION_RC_INFO;
#if ALINK_CRC_EXTRA
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_VISION_RC_INFO_LEN,ALINK_MSG_ID_VISION_RC_INFO_CRC);
#else
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_VISION_RC_INFO_LEN);
#endif
}

/**
 * @brief Pack a vision_rc_info message on a channel
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param timestamp timestamp (milliseconds since system boot)
 * @param roll Stick Command normalized to [-1, 1], float to int8 scale is 100
 * @param pitch Stick Command normalized to [-1, 1], float to int8 scale is 100
 * @param yaw Stick Command normalized to [-1, 1], float to int8 scale is 100
 * @param thrust Thrust command, normalized to [-1, 1], float to int8 scale is 100
 * @param button Button command, 625 : arm button 1157: go home button 1423: Pause_Button 891:  Takeoff Landing button 
 * @param mode Main mode, 1024: ATT 1689: IOC 359: GPS
 * @param gimbal_pitch gimbal pitch control, 
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_vision_rc_info_pack_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan,
							   alink_message_head_t* msg,
						           uint32_t timestamp,int8_t roll,int8_t pitch,int8_t yaw,int8_t thrust,int16_t button,int16_t mode,int16_t gimbal_pitch)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_VISION_RC_INFO_LEN];
	_mav_put_uint32_t(buf, 0, timestamp);
	_mav_put_int16_t(buf, 4, button);
	_mav_put_int16_t(buf, 6, mode);
	_mav_put_int16_t(buf, 8, gimbal_pitch);
	_mav_put_int8_t(buf, 10, roll);
	_mav_put_int8_t(buf, 11, pitch);
	_mav_put_int8_t(buf, 12, yaw);
	_mav_put_int8_t(buf, 13, thrust);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_VISION_RC_INFO_LEN);
#else
	alink_vision_rc_info_t packet;
	packet.timestamp = timestamp;
	packet.button = button;
	packet.mode = mode;
	packet.gimbal_pitch = gimbal_pitch;
	packet.roll = roll;
	packet.pitch = pitch;
	packet.yaw = yaw;
	packet.thrust = thrust;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_VISION_RC_INFO_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_VISION_RC_INFO;
#if ALINK_CRC_EXTRA
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_VISION_RC_INFO_LEN,ALINK_MSG_ID_VISION_RC_INFO_CRC);
#else
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_VISION_RC_INFO_LEN);
#endif
}
/**
 * @brief Encode a vision_rc_info struct
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 * @param vision_rc_info C-struct to read the message contents from
 */
static inline uint16_t alink_msg_vision_rc_info_encode(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg, const alink_vision_rc_info_t* vision_rc_info)
{
	return alink_msg_vision_rc_info_pack(dest_id, source_id, msg, vision_rc_info->timestamp, vision_rc_info->roll, vision_rc_info->pitch, vision_rc_info->yaw, vision_rc_info->thrust, vision_rc_info->button, vision_rc_info->mode, vision_rc_info->gimbal_pitch);
}

/**
 * @brief Encode a vision_rc_info struct on a channel
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param vision_rc_info C-struct to read the message contents from
 */
static inline uint16_t alink_msg_vision_rc_info_encode_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan, alink_message_head_t* msg, const alink_vision_rc_info_t* vision_rc_info)
{
	return alink_msg_vision_rc_info_pack_chan(dest_id, source_id, chan, msg, vision_rc_info->timestamp, vision_rc_info->roll, vision_rc_info->pitch, vision_rc_info->yaw, vision_rc_info->thrust, vision_rc_info->button, vision_rc_info->mode, vision_rc_info->gimbal_pitch);
}
// MESSAGE VISION_RC_INFO UNPACKING


/**
 * @brief Get field timestamp from vision_rc_info message
 *
 * @return timestamp (milliseconds since system boot)
 */
static inline uint32_t alink_msg_vision_rc_info_get_timestamp(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field roll from vision_rc_info message
 *
 * @return Stick Command normalized to [-1, 1], float to int8 scale is 100
 */
static inline int8_t alink_msg_vision_rc_info_get_roll(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int8_t(msg,  10);
}

/**
 * @brief Get field pitch from vision_rc_info message
 *
 * @return Stick Command normalized to [-1, 1], float to int8 scale is 100
 */
static inline int8_t alink_msg_vision_rc_info_get_pitch(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int8_t(msg,  11);
}

/**
 * @brief Get field yaw from vision_rc_info message
 *
 * @return Stick Command normalized to [-1, 1], float to int8 scale is 100
 */
static inline int8_t alink_msg_vision_rc_info_get_yaw(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int8_t(msg,  12);
}

/**
 * @brief Get field thrust from vision_rc_info message
 *
 * @return Thrust command, normalized to [-1, 1], float to int8 scale is 100
 */
static inline int8_t alink_msg_vision_rc_info_get_thrust(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int8_t(msg,  13);
}

/**
 * @brief Get field button from vision_rc_info message
 *
 * @return Button command, 625 : arm button 1157: go home button 1423: Pause_Button 891:  Takeoff Landing button 
 */
static inline int16_t alink_msg_vision_rc_info_get_button(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  4);
}

/**
 * @brief Get field mode from vision_rc_info message
 *
 * @return Main mode, 1024: ATT 1689: IOC 359: GPS
 */
static inline int16_t alink_msg_vision_rc_info_get_mode(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  6);
}

/**
 * @brief Get field gimbal_pitch from vision_rc_info message
 *
 * @return gimbal pitch control, 
 */
static inline int16_t alink_msg_vision_rc_info_get_gimbal_pitch(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  8);
}

/**
 * @brief Decode a vision_rc_info message into a struct
 *
 * @param msg The message to decode
 * @param vision_rc_info C-struct to decode the message contents into
 */
static inline void alink_msg_vision_rc_info_decode(const alink_message_head_t* msg, alink_vision_rc_info_t* vision_rc_info)
{
#if ALINK_NEED_BYTE_SWAP
	vision_rc_info->timestamp = alink_msg_vision_rc_info_get_timestamp(msg);
	vision_rc_info->button = alink_msg_vision_rc_info_get_button(msg);
	vision_rc_info->mode = alink_msg_vision_rc_info_get_mode(msg);
	vision_rc_info->gimbal_pitch = alink_msg_vision_rc_info_get_gimbal_pitch(msg);
	vision_rc_info->roll = alink_msg_vision_rc_info_get_roll(msg);
	vision_rc_info->pitch = alink_msg_vision_rc_info_get_pitch(msg);
	vision_rc_info->yaw = alink_msg_vision_rc_info_get_yaw(msg);
	vision_rc_info->thrust = alink_msg_vision_rc_info_get_thrust(msg);
#else
	memcpy(vision_rc_info, _MAV_PAYLOAD(msg), ALINK_MSG_ID_VISION_RC_INFO_LEN);
#endif
}
