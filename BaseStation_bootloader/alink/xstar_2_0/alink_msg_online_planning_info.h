// MESSAGE ONLINE_PLANNING_INFO PACKING

#define ALINK_MSG_ID_ONLINE_PLANNING_INFO 94

typedef struct __alink_online_planning_info_t
{
 uint32_t timestamp; /*< timestamp (microseconds since system boot)*/
 int32_t from_lat_est; /*< Latitude info of the first point in 10E7 degree*/
 int32_t from_lon_est; /*< Longitude info of the first point in 10E7 degree*/
 int32_t from_alt_est; /*< MSL Altitude info of the first point in mm*/
 int32_t from_radius_est; /*< Radius info of the first point in mm*/
 int32_t to_lat_est; /*< Latitude info of the second point in 10E7 degree*/
 int32_t to_lon_est; /*< Longitude info of the second point in 10E7 degree*/
 int32_t to_alt_est; /*< MSL Altitude info of the second point in mm*/
 int32_t to_radius_est; /*< Radius info of the second point in mm*/
 int32_t home_lat_est; /*< Latitude info of home in 10E7 degree*/
 int32_t home_lon_est; /*< Longitude info of home in 10E7 degree*/
 int32_t home_alt_est; /*< MSL Altitude info the home in mm*/
 int32_t home_radius_est; /*< Radius info of home in mm*/
 int16_t from_yaw_est; /*< Yaw info of the first point in 0.1 degree*/
 int16_t to_yaw_est; /*< Yaw info of the second point in 0.1 degree*/
 int16_t home_yaw_est; /*< Yaw info of home in 0.1 degree*/
 uint8_t planning_typoe; /*< 0:normal 1:RTH*/
} alink_online_planning_info_t;

#define ALINK_MSG_ID_ONLINE_PLANNING_INFO_LEN 59
#define ALINK_MSG_ID_94_LEN 59

#define ALINK_MSG_ID_ONLINE_PLANNING_INFO_CRC 249
#define ALINK_MSG_ID_94_CRC 249



#define ALINK_MESSAGE_INFO_ONLINE_PLANNING_INFO { \
	"ONLINE_PLANNING_INFO", \
	17, \
	{  { "timestamp", NULL, ALINK_TYPE_UINT32_T, 0, 0, offsetof(alink_online_planning_info_t, timestamp) }, \
         { "from_lat_est", NULL, ALINK_TYPE_INT32_T, 0, 4, offsetof(alink_online_planning_info_t, from_lat_est) }, \
         { "from_lon_est", NULL, ALINK_TYPE_INT32_T, 0, 8, offsetof(alink_online_planning_info_t, from_lon_est) }, \
         { "from_alt_est", NULL, ALINK_TYPE_INT32_T, 0, 12, offsetof(alink_online_planning_info_t, from_alt_est) }, \
         { "from_radius_est", NULL, ALINK_TYPE_INT32_T, 0, 16, offsetof(alink_online_planning_info_t, from_radius_est) }, \
         { "to_lat_est", NULL, ALINK_TYPE_INT32_T, 0, 20, offsetof(alink_online_planning_info_t, to_lat_est) }, \
         { "to_lon_est", NULL, ALINK_TYPE_INT32_T, 0, 24, offsetof(alink_online_planning_info_t, to_lon_est) }, \
         { "to_alt_est", NULL, ALINK_TYPE_INT32_T, 0, 28, offsetof(alink_online_planning_info_t, to_alt_est) }, \
         { "to_radius_est", NULL, ALINK_TYPE_INT32_T, 0, 32, offsetof(alink_online_planning_info_t, to_radius_est) }, \
         { "home_lat_est", NULL, ALINK_TYPE_INT32_T, 0, 36, offsetof(alink_online_planning_info_t, home_lat_est) }, \
         { "home_lon_est", NULL, ALINK_TYPE_INT32_T, 0, 40, offsetof(alink_online_planning_info_t, home_lon_est) }, \
         { "home_alt_est", NULL, ALINK_TYPE_INT32_T, 0, 44, offsetof(alink_online_planning_info_t, home_alt_est) }, \
         { "home_radius_est", NULL, ALINK_TYPE_INT32_T, 0, 48, offsetof(alink_online_planning_info_t, home_radius_est) }, \
         { "from_yaw_est", NULL, ALINK_TYPE_INT16_T, 0, 52, offsetof(alink_online_planning_info_t, from_yaw_est) }, \
         { "to_yaw_est", NULL, ALINK_TYPE_INT16_T, 0, 54, offsetof(alink_online_planning_info_t, to_yaw_est) }, \
         { "home_yaw_est", NULL, ALINK_TYPE_INT16_T, 0, 56, offsetof(alink_online_planning_info_t, home_yaw_est) }, \
         { "planning_typoe", NULL, ALINK_TYPE_UINT8_T, 0, 58, offsetof(alink_online_planning_info_t, planning_typoe) }, \
         } \
}


/**
 * @brief Pack a online_planning_info message
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 *
 * @param timestamp timestamp (microseconds since system boot)
 * @param from_lat_est Latitude info of the first point in 10E7 degree
 * @param from_lon_est Longitude info of the first point in 10E7 degree
 * @param from_alt_est MSL Altitude info of the first point in mm
 * @param from_radius_est Radius info of the first point in mm
 * @param to_lat_est Latitude info of the second point in 10E7 degree
 * @param to_lon_est Longitude info of the second point in 10E7 degree
 * @param to_alt_est MSL Altitude info of the second point in mm
 * @param to_radius_est Radius info of the second point in mm
 * @param home_lat_est Latitude info of home in 10E7 degree
 * @param home_lon_est Longitude info of home in 10E7 degree
 * @param home_alt_est MSL Altitude info the home in mm
 * @param home_radius_est Radius info of home in mm
 * @param from_yaw_est Yaw info of the first point in 0.1 degree
 * @param to_yaw_est Yaw info of the second point in 0.1 degree
 * @param home_yaw_est Yaw info of home in 0.1 degree
 * @param planning_typoe 0:normal 1:RTH
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_online_planning_info_pack(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg,
						       uint32_t timestamp, int32_t from_lat_est, int32_t from_lon_est, int32_t from_alt_est, int32_t from_radius_est, int32_t to_lat_est, int32_t to_lon_est, int32_t to_alt_est, int32_t to_radius_est, int32_t home_lat_est, int32_t home_lon_est, int32_t home_alt_est, int32_t home_radius_est, int16_t from_yaw_est, int16_t to_yaw_est, int16_t home_yaw_est, uint8_t planning_typoe)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_ONLINE_PLANNING_INFO_LEN];
	_mav_put_uint32_t(buf, 0, timestamp);
	_mav_put_int32_t(buf, 4, from_lat_est);
	_mav_put_int32_t(buf, 8, from_lon_est);
	_mav_put_int32_t(buf, 12, from_alt_est);
	_mav_put_int32_t(buf, 16, from_radius_est);
	_mav_put_int32_t(buf, 20, to_lat_est);
	_mav_put_int32_t(buf, 24, to_lon_est);
	_mav_put_int32_t(buf, 28, to_alt_est);
	_mav_put_int32_t(buf, 32, to_radius_est);
	_mav_put_int32_t(buf, 36, home_lat_est);
	_mav_put_int32_t(buf, 40, home_lon_est);
	_mav_put_int32_t(buf, 44, home_alt_est);
	_mav_put_int32_t(buf, 48, home_radius_est);
	_mav_put_int16_t(buf, 52, from_yaw_est);
	_mav_put_int16_t(buf, 54, to_yaw_est);
	_mav_put_int16_t(buf, 56, home_yaw_est);
	_mav_put_uint8_t(buf, 58, planning_typoe);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_ONLINE_PLANNING_INFO_LEN);
#else
	alink_online_planning_info_t packet;
	packet.timestamp = timestamp;
	packet.from_lat_est = from_lat_est;
	packet.from_lon_est = from_lon_est;
	packet.from_alt_est = from_alt_est;
	packet.from_radius_est = from_radius_est;
	packet.to_lat_est = to_lat_est;
	packet.to_lon_est = to_lon_est;
	packet.to_alt_est = to_alt_est;
	packet.to_radius_est = to_radius_est;
	packet.home_lat_est = home_lat_est;
	packet.home_lon_est = home_lon_est;
	packet.home_alt_est = home_alt_est;
	packet.home_radius_est = home_radius_est;
	packet.from_yaw_est = from_yaw_est;
	packet.to_yaw_est = to_yaw_est;
	packet.home_yaw_est = home_yaw_est;
	packet.planning_typoe = planning_typoe;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_ONLINE_PLANNING_INFO_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_ONLINE_PLANNING_INFO;
#if ALINK_CRC_EXTRA
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_ONLINE_PLANNING_INFO_LEN,ALINK_MSG_ID_ONLINE_PLANNING_INFO_CRC);
#else
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_ONLINE_PLANNING_INFO_LEN);
#endif
}

/**
 * @brief Pack a online_planning_info message on a channel
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param timestamp timestamp (microseconds since system boot)
 * @param from_lat_est Latitude info of the first point in 10E7 degree
 * @param from_lon_est Longitude info of the first point in 10E7 degree
 * @param from_alt_est MSL Altitude info of the first point in mm
 * @param from_radius_est Radius info of the first point in mm
 * @param to_lat_est Latitude info of the second point in 10E7 degree
 * @param to_lon_est Longitude info of the second point in 10E7 degree
 * @param to_alt_est MSL Altitude info of the second point in mm
 * @param to_radius_est Radius info of the second point in mm
 * @param home_lat_est Latitude info of home in 10E7 degree
 * @param home_lon_est Longitude info of home in 10E7 degree
 * @param home_alt_est MSL Altitude info the home in mm
 * @param home_radius_est Radius info of home in mm
 * @param from_yaw_est Yaw info of the first point in 0.1 degree
 * @param to_yaw_est Yaw info of the second point in 0.1 degree
 * @param home_yaw_est Yaw info of home in 0.1 degree
 * @param planning_typoe 0:normal 1:RTH
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_online_planning_info_pack_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan,
							   alink_message_head_t* msg,
						           uint32_t timestamp,int32_t from_lat_est,int32_t from_lon_est,int32_t from_alt_est,int32_t from_radius_est,int32_t to_lat_est,int32_t to_lon_est,int32_t to_alt_est,int32_t to_radius_est,int32_t home_lat_est,int32_t home_lon_est,int32_t home_alt_est,int32_t home_radius_est,int16_t from_yaw_est,int16_t to_yaw_est,int16_t home_yaw_est,uint8_t planning_typoe)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_ONLINE_PLANNING_INFO_LEN];
	_mav_put_uint32_t(buf, 0, timestamp);
	_mav_put_int32_t(buf, 4, from_lat_est);
	_mav_put_int32_t(buf, 8, from_lon_est);
	_mav_put_int32_t(buf, 12, from_alt_est);
	_mav_put_int32_t(buf, 16, from_radius_est);
	_mav_put_int32_t(buf, 20, to_lat_est);
	_mav_put_int32_t(buf, 24, to_lon_est);
	_mav_put_int32_t(buf, 28, to_alt_est);
	_mav_put_int32_t(buf, 32, to_radius_est);
	_mav_put_int32_t(buf, 36, home_lat_est);
	_mav_put_int32_t(buf, 40, home_lon_est);
	_mav_put_int32_t(buf, 44, home_alt_est);
	_mav_put_int32_t(buf, 48, home_radius_est);
	_mav_put_int16_t(buf, 52, from_yaw_est);
	_mav_put_int16_t(buf, 54, to_yaw_est);
	_mav_put_int16_t(buf, 56, home_yaw_est);
	_mav_put_uint8_t(buf, 58, planning_typoe);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_ONLINE_PLANNING_INFO_LEN);
#else
	alink_online_planning_info_t packet;
	packet.timestamp = timestamp;
	packet.from_lat_est = from_lat_est;
	packet.from_lon_est = from_lon_est;
	packet.from_alt_est = from_alt_est;
	packet.from_radius_est = from_radius_est;
	packet.to_lat_est = to_lat_est;
	packet.to_lon_est = to_lon_est;
	packet.to_alt_est = to_alt_est;
	packet.to_radius_est = to_radius_est;
	packet.home_lat_est = home_lat_est;
	packet.home_lon_est = home_lon_est;
	packet.home_alt_est = home_alt_est;
	packet.home_radius_est = home_radius_est;
	packet.from_yaw_est = from_yaw_est;
	packet.to_yaw_est = to_yaw_est;
	packet.home_yaw_est = home_yaw_est;
	packet.planning_typoe = planning_typoe;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_ONLINE_PLANNING_INFO_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_ONLINE_PLANNING_INFO;
#if ALINK_CRC_EXTRA
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_ONLINE_PLANNING_INFO_LEN,ALINK_MSG_ID_ONLINE_PLANNING_INFO_CRC);
#else
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_ONLINE_PLANNING_INFO_LEN);
#endif
}
/**
 * @brief Encode a online_planning_info struct
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 * @param online_planning_info C-struct to read the message contents from
 */
static inline uint16_t alink_msg_online_planning_info_encode(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg, const alink_online_planning_info_t* online_planning_info)
{
	return alink_msg_online_planning_info_pack(dest_id, source_id, msg, online_planning_info->timestamp, online_planning_info->from_lat_est, online_planning_info->from_lon_est, online_planning_info->from_alt_est, online_planning_info->from_radius_est, online_planning_info->to_lat_est, online_planning_info->to_lon_est, online_planning_info->to_alt_est, online_planning_info->to_radius_est, online_planning_info->home_lat_est, online_planning_info->home_lon_est, online_planning_info->home_alt_est, online_planning_info->home_radius_est, online_planning_info->from_yaw_est, online_planning_info->to_yaw_est, online_planning_info->home_yaw_est, online_planning_info->planning_typoe);
}

/**
 * @brief Encode a online_planning_info struct on a channel
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param online_planning_info C-struct to read the message contents from
 */
static inline uint16_t alink_msg_online_planning_info_encode_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan, alink_message_head_t* msg, const alink_online_planning_info_t* online_planning_info)
{
	return alink_msg_online_planning_info_pack_chan(dest_id, source_id, chan, msg, online_planning_info->timestamp, online_planning_info->from_lat_est, online_planning_info->from_lon_est, online_planning_info->from_alt_est, online_planning_info->from_radius_est, online_planning_info->to_lat_est, online_planning_info->to_lon_est, online_planning_info->to_alt_est, online_planning_info->to_radius_est, online_planning_info->home_lat_est, online_planning_info->home_lon_est, online_planning_info->home_alt_est, online_planning_info->home_radius_est, online_planning_info->from_yaw_est, online_planning_info->to_yaw_est, online_planning_info->home_yaw_est, online_planning_info->planning_typoe);
}
// MESSAGE ONLINE_PLANNING_INFO UNPACKING


/**
 * @brief Get field timestamp from online_planning_info message
 *
 * @return timestamp (microseconds since system boot)
 */
static inline uint32_t alink_msg_online_planning_info_get_timestamp(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field from_lat_est from online_planning_info message
 *
 * @return Latitude info of the first point in 10E7 degree
 */
static inline int32_t alink_msg_online_planning_info_get_from_lat_est(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  4);
}

/**
 * @brief Get field from_lon_est from online_planning_info message
 *
 * @return Longitude info of the first point in 10E7 degree
 */
static inline int32_t alink_msg_online_planning_info_get_from_lon_est(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  8);
}

/**
 * @brief Get field from_alt_est from online_planning_info message
 *
 * @return MSL Altitude info of the first point in mm
 */
static inline int32_t alink_msg_online_planning_info_get_from_alt_est(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  12);
}

/**
 * @brief Get field from_radius_est from online_planning_info message
 *
 * @return Radius info of the first point in mm
 */
static inline int32_t alink_msg_online_planning_info_get_from_radius_est(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  16);
}

/**
 * @brief Get field to_lat_est from online_planning_info message
 *
 * @return Latitude info of the second point in 10E7 degree
 */
static inline int32_t alink_msg_online_planning_info_get_to_lat_est(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  20);
}

/**
 * @brief Get field to_lon_est from online_planning_info message
 *
 * @return Longitude info of the second point in 10E7 degree
 */
static inline int32_t alink_msg_online_planning_info_get_to_lon_est(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  24);
}

/**
 * @brief Get field to_alt_est from online_planning_info message
 *
 * @return MSL Altitude info of the second point in mm
 */
static inline int32_t alink_msg_online_planning_info_get_to_alt_est(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  28);
}

/**
 * @brief Get field to_radius_est from online_planning_info message
 *
 * @return Radius info of the second point in mm
 */
static inline int32_t alink_msg_online_planning_info_get_to_radius_est(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  32);
}

/**
 * @brief Get field home_lat_est from online_planning_info message
 *
 * @return Latitude info of home in 10E7 degree
 */
static inline int32_t alink_msg_online_planning_info_get_home_lat_est(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  36);
}

/**
 * @brief Get field home_lon_est from online_planning_info message
 *
 * @return Longitude info of home in 10E7 degree
 */
static inline int32_t alink_msg_online_planning_info_get_home_lon_est(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  40);
}

/**
 * @brief Get field home_alt_est from online_planning_info message
 *
 * @return MSL Altitude info the home in mm
 */
static inline int32_t alink_msg_online_planning_info_get_home_alt_est(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  44);
}

/**
 * @brief Get field home_radius_est from online_planning_info message
 *
 * @return Radius info of home in mm
 */
static inline int32_t alink_msg_online_planning_info_get_home_radius_est(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  48);
}

/**
 * @brief Get field from_yaw_est from online_planning_info message
 *
 * @return Yaw info of the first point in 0.1 degree
 */
static inline int16_t alink_msg_online_planning_info_get_from_yaw_est(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  52);
}

/**
 * @brief Get field to_yaw_est from online_planning_info message
 *
 * @return Yaw info of the second point in 0.1 degree
 */
static inline int16_t alink_msg_online_planning_info_get_to_yaw_est(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  54);
}

/**
 * @brief Get field home_yaw_est from online_planning_info message
 *
 * @return Yaw info of home in 0.1 degree
 */
static inline int16_t alink_msg_online_planning_info_get_home_yaw_est(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  56);
}

/**
 * @brief Get field planning_typoe from online_planning_info message
 *
 * @return 0:normal 1:RTH
 */
static inline uint8_t alink_msg_online_planning_info_get_planning_typoe(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  58);
}

/**
 * @brief Decode a online_planning_info message into a struct
 *
 * @param msg The message to decode
 * @param online_planning_info C-struct to decode the message contents into
 */
static inline void alink_msg_online_planning_info_decode(const alink_message_head_t* msg, alink_online_planning_info_t* online_planning_info)
{
#if ALINK_NEED_BYTE_SWAP
	online_planning_info->timestamp = alink_msg_online_planning_info_get_timestamp(msg);
	online_planning_info->from_lat_est = alink_msg_online_planning_info_get_from_lat_est(msg);
	online_planning_info->from_lon_est = alink_msg_online_planning_info_get_from_lon_est(msg);
	online_planning_info->from_alt_est = alink_msg_online_planning_info_get_from_alt_est(msg);
	online_planning_info->from_radius_est = alink_msg_online_planning_info_get_from_radius_est(msg);
	online_planning_info->to_lat_est = alink_msg_online_planning_info_get_to_lat_est(msg);
	online_planning_info->to_lon_est = alink_msg_online_planning_info_get_to_lon_est(msg);
	online_planning_info->to_alt_est = alink_msg_online_planning_info_get_to_alt_est(msg);
	online_planning_info->to_radius_est = alink_msg_online_planning_info_get_to_radius_est(msg);
	online_planning_info->home_lat_est = alink_msg_online_planning_info_get_home_lat_est(msg);
	online_planning_info->home_lon_est = alink_msg_online_planning_info_get_home_lon_est(msg);
	online_planning_info->home_alt_est = alink_msg_online_planning_info_get_home_alt_est(msg);
	online_planning_info->home_radius_est = alink_msg_online_planning_info_get_home_radius_est(msg);
	online_planning_info->from_yaw_est = alink_msg_online_planning_info_get_from_yaw_est(msg);
	online_planning_info->to_yaw_est = alink_msg_online_planning_info_get_to_yaw_est(msg);
	online_planning_info->home_yaw_est = alink_msg_online_planning_info_get_home_yaw_est(msg);
	online_planning_info->planning_typoe = alink_msg_online_planning_info_get_planning_typoe(msg);
#else
	memcpy(online_planning_info, _MAV_PAYLOAD(msg), ALINK_MSG_ID_ONLINE_PLANNING_INFO_LEN);
#endif
}
