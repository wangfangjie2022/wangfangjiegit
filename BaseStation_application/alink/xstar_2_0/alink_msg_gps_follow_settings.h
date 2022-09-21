// MESSAGE GPS_FOLLOW_SETTINGS PACKING

#define ALINK_MSG_ID_GPS_FOLLOW_SETTINGS 86

typedef struct __alink_gps_follow_settings_t
{
 int32_t adjust_mode; /*< adjust_mode*/
 int32_t allow_backward; /*< allow backward*/
 int32_t heading_mode; /*< heading mode*/
 int32_t user_defined_heading; /*< user defined heading*/
 int32_t altitude_mode; /*<  altitude mode */
 int32_t radius; /*< radius */
 int32_t speed; /*<  speed */
 int32_t direction; /*< direction*/
} alink_gps_follow_settings_t;

#define ALINK_MSG_ID_GPS_FOLLOW_SETTINGS_LEN 32
#define ALINK_MSG_ID_86_LEN 32

#define ALINK_MSG_ID_GPS_FOLLOW_SETTINGS_CRC 190
#define ALINK_MSG_ID_86_CRC 190



#define ALINK_MESSAGE_INFO_GPS_FOLLOW_SETTINGS { \
	"GPS_FOLLOW_SETTINGS", \
	8, \
	{  { "adjust_mode", NULL, ALINK_TYPE_INT32_T, 0, 0, offsetof(alink_gps_follow_settings_t, adjust_mode) }, \
         { "allow_backward", NULL, ALINK_TYPE_INT32_T, 0, 4, offsetof(alink_gps_follow_settings_t, allow_backward) }, \
         { "heading_mode", NULL, ALINK_TYPE_INT32_T, 0, 8, offsetof(alink_gps_follow_settings_t, heading_mode) }, \
         { "user_defined_heading", NULL, ALINK_TYPE_INT32_T, 0, 12, offsetof(alink_gps_follow_settings_t, user_defined_heading) }, \
         { "altitude_mode", NULL, ALINK_TYPE_INT32_T, 0, 16, offsetof(alink_gps_follow_settings_t, altitude_mode) }, \
         { "radius", NULL, ALINK_TYPE_INT32_T, 0, 20, offsetof(alink_gps_follow_settings_t, radius) }, \
         { "speed", NULL, ALINK_TYPE_INT32_T, 0, 24, offsetof(alink_gps_follow_settings_t, speed) }, \
         { "direction", NULL, ALINK_TYPE_INT32_T, 0, 28, offsetof(alink_gps_follow_settings_t, direction) }, \
         } \
}


/**
 * @brief Pack a gps_follow_settings message
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 *
 * @param adjust_mode adjust_mode
 * @param allow_backward allow backward
 * @param heading_mode heading mode
 * @param user_defined_heading user defined heading
 * @param altitude_mode  altitude mode 
 * @param radius radius 
 * @param speed  speed 
 * @param direction direction
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_gps_follow_settings_pack(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg,
						       int32_t adjust_mode, int32_t allow_backward, int32_t heading_mode, int32_t user_defined_heading, int32_t altitude_mode, int32_t radius, int32_t speed, int32_t direction)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_GPS_FOLLOW_SETTINGS_LEN];
	_mav_put_int32_t(buf, 0, adjust_mode);
	_mav_put_int32_t(buf, 4, allow_backward);
	_mav_put_int32_t(buf, 8, heading_mode);
	_mav_put_int32_t(buf, 12, user_defined_heading);
	_mav_put_int32_t(buf, 16, altitude_mode);
	_mav_put_int32_t(buf, 20, radius);
	_mav_put_int32_t(buf, 24, speed);
	_mav_put_int32_t(buf, 28, direction);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_GPS_FOLLOW_SETTINGS_LEN);
#else
	alink_gps_follow_settings_t packet;
	packet.adjust_mode = adjust_mode;
	packet.allow_backward = allow_backward;
	packet.heading_mode = heading_mode;
	packet.user_defined_heading = user_defined_heading;
	packet.altitude_mode = altitude_mode;
	packet.radius = radius;
	packet.speed = speed;
	packet.direction = direction;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_GPS_FOLLOW_SETTINGS_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_GPS_FOLLOW_SETTINGS;
#if ALINK_CRC_EXTRA
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_GPS_FOLLOW_SETTINGS_LEN,ALINK_MSG_ID_GPS_FOLLOW_SETTINGS_CRC);
#else
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_GPS_FOLLOW_SETTINGS_LEN);
#endif
}

/**
 * @brief Pack a gps_follow_settings message on a channel
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param adjust_mode adjust_mode
 * @param allow_backward allow backward
 * @param heading_mode heading mode
 * @param user_defined_heading user defined heading
 * @param altitude_mode  altitude mode 
 * @param radius radius 
 * @param speed  speed 
 * @param direction direction
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_gps_follow_settings_pack_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan,
							   alink_message_head_t* msg,
						           int32_t adjust_mode,int32_t allow_backward,int32_t heading_mode,int32_t user_defined_heading,int32_t altitude_mode,int32_t radius,int32_t speed,int32_t direction)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_GPS_FOLLOW_SETTINGS_LEN];
	_mav_put_int32_t(buf, 0, adjust_mode);
	_mav_put_int32_t(buf, 4, allow_backward);
	_mav_put_int32_t(buf, 8, heading_mode);
	_mav_put_int32_t(buf, 12, user_defined_heading);
	_mav_put_int32_t(buf, 16, altitude_mode);
	_mav_put_int32_t(buf, 20, radius);
	_mav_put_int32_t(buf, 24, speed);
	_mav_put_int32_t(buf, 28, direction);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_GPS_FOLLOW_SETTINGS_LEN);
#else
	alink_gps_follow_settings_t packet;
	packet.adjust_mode = adjust_mode;
	packet.allow_backward = allow_backward;
	packet.heading_mode = heading_mode;
	packet.user_defined_heading = user_defined_heading;
	packet.altitude_mode = altitude_mode;
	packet.radius = radius;
	packet.speed = speed;
	packet.direction = direction;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_GPS_FOLLOW_SETTINGS_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_GPS_FOLLOW_SETTINGS;
#if ALINK_CRC_EXTRA
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_GPS_FOLLOW_SETTINGS_LEN,ALINK_MSG_ID_GPS_FOLLOW_SETTINGS_CRC);
#else
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_GPS_FOLLOW_SETTINGS_LEN);
#endif
}
/**
 * @brief Encode a gps_follow_settings struct
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 * @param gps_follow_settings C-struct to read the message contents from
 */
static inline uint16_t alink_msg_gps_follow_settings_encode(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg, const alink_gps_follow_settings_t* gps_follow_settings)
{
	return alink_msg_gps_follow_settings_pack(dest_id, source_id, msg, gps_follow_settings->adjust_mode, gps_follow_settings->allow_backward, gps_follow_settings->heading_mode, gps_follow_settings->user_defined_heading, gps_follow_settings->altitude_mode, gps_follow_settings->radius, gps_follow_settings->speed, gps_follow_settings->direction);
}

/**
 * @brief Encode a gps_follow_settings struct on a channel
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param gps_follow_settings C-struct to read the message contents from
 */
static inline uint16_t alink_msg_gps_follow_settings_encode_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan, alink_message_head_t* msg, const alink_gps_follow_settings_t* gps_follow_settings)
{
	return alink_msg_gps_follow_settings_pack_chan(dest_id, source_id, chan, msg, gps_follow_settings->adjust_mode, gps_follow_settings->allow_backward, gps_follow_settings->heading_mode, gps_follow_settings->user_defined_heading, gps_follow_settings->altitude_mode, gps_follow_settings->radius, gps_follow_settings->speed, gps_follow_settings->direction);
}
// MESSAGE GPS_FOLLOW_SETTINGS UNPACKING


/**
 * @brief Get field adjust_mode from gps_follow_settings message
 *
 * @return adjust_mode
 */
static inline int32_t alink_msg_gps_follow_settings_get_adjust_mode(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  0);
}

/**
 * @brief Get field allow_backward from gps_follow_settings message
 *
 * @return allow backward
 */
static inline int32_t alink_msg_gps_follow_settings_get_allow_backward(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  4);
}

/**
 * @brief Get field heading_mode from gps_follow_settings message
 *
 * @return heading mode
 */
static inline int32_t alink_msg_gps_follow_settings_get_heading_mode(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  8);
}

/**
 * @brief Get field user_defined_heading from gps_follow_settings message
 *
 * @return user defined heading
 */
static inline int32_t alink_msg_gps_follow_settings_get_user_defined_heading(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  12);
}

/**
 * @brief Get field altitude_mode from gps_follow_settings message
 *
 * @return  altitude mode 
 */
static inline int32_t alink_msg_gps_follow_settings_get_altitude_mode(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  16);
}

/**
 * @brief Get field radius from gps_follow_settings message
 *
 * @return radius 
 */
static inline int32_t alink_msg_gps_follow_settings_get_radius(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  20);
}

/**
 * @brief Get field speed from gps_follow_settings message
 *
 * @return  speed 
 */
static inline int32_t alink_msg_gps_follow_settings_get_speed(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  24);
}

/**
 * @brief Get field direction from gps_follow_settings message
 *
 * @return direction
 */
static inline int32_t alink_msg_gps_follow_settings_get_direction(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  28);
}

/**
 * @brief Decode a gps_follow_settings message into a struct
 *
 * @param msg The message to decode
 * @param gps_follow_settings C-struct to decode the message contents into
 */
static inline void alink_msg_gps_follow_settings_decode(const alink_message_head_t* msg, alink_gps_follow_settings_t* gps_follow_settings)
{
#if ALINK_NEED_BYTE_SWAP
	gps_follow_settings->adjust_mode = alink_msg_gps_follow_settings_get_adjust_mode(msg);
	gps_follow_settings->allow_backward = alink_msg_gps_follow_settings_get_allow_backward(msg);
	gps_follow_settings->heading_mode = alink_msg_gps_follow_settings_get_heading_mode(msg);
	gps_follow_settings->user_defined_heading = alink_msg_gps_follow_settings_get_user_defined_heading(msg);
	gps_follow_settings->altitude_mode = alink_msg_gps_follow_settings_get_altitude_mode(msg);
	gps_follow_settings->radius = alink_msg_gps_follow_settings_get_radius(msg);
	gps_follow_settings->speed = alink_msg_gps_follow_settings_get_speed(msg);
	gps_follow_settings->direction = alink_msg_gps_follow_settings_get_direction(msg);
#else
	memcpy(gps_follow_settings, _MAV_PAYLOAD(msg), ALINK_MSG_ID_GPS_FOLLOW_SETTINGS_LEN);
#endif
}
