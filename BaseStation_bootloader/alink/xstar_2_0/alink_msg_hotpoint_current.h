// MESSAGE HOTPOINT_CURRENT PACKING

#define ALINK_MSG_ID_HOTPOINT_CURRENT 43

typedef struct __alink_hotpoint_current_t
{
 uint32_t timestamp; /*< timestamp (milliseconds since system boot)*/
 int32_t lat; /*< hot point pos,Latitude (WGS84), in degrees * 1E7*/
 int32_t lon; /*< hot point pos,Longitude (WGS84), in degrees * 1E7*/
 int32_t alt; /*< hot point pos,Altitude , in mm*/
 int16_t speed_set; /*< way point speed set,in 1e-3 m/s*/
 int16_t radius; /*< way point radius,in 1e-3 m*/
 uint8_t centered; /*< hot point be centered or not; 0: not; 1:centered*/
 uint8_t type; /*< hot point type; 0: fixed; 1:moving*/
 uint8_t round_cur; /*< hot point current round*/
 uint8_t status; /*< way point status. 0:pause; 1:running; 2:completed; other:as defiens latter*/
} alink_hotpoint_current_t;

#define ALINK_MSG_ID_HOTPOINT_CURRENT_LEN 24
#define ALINK_MSG_ID_43_LEN 24

#define ALINK_MSG_ID_HOTPOINT_CURRENT_CRC 15
#define ALINK_MSG_ID_43_CRC 15



#define ALINK_MESSAGE_INFO_HOTPOINT_CURRENT { \
	"HOTPOINT_CURRENT", \
	10, \
	{  { "timestamp", NULL, ALINK_TYPE_UINT32_T, 0, 0, offsetof(alink_hotpoint_current_t, timestamp) }, \
         { "lat", NULL, ALINK_TYPE_INT32_T, 0, 4, offsetof(alink_hotpoint_current_t, lat) }, \
         { "lon", NULL, ALINK_TYPE_INT32_T, 0, 8, offsetof(alink_hotpoint_current_t, lon) }, \
         { "alt", NULL, ALINK_TYPE_INT32_T, 0, 12, offsetof(alink_hotpoint_current_t, alt) }, \
         { "speed_set", NULL, ALINK_TYPE_INT16_T, 0, 16, offsetof(alink_hotpoint_current_t, speed_set) }, \
         { "radius", NULL, ALINK_TYPE_INT16_T, 0, 18, offsetof(alink_hotpoint_current_t, radius) }, \
         { "centered", NULL, ALINK_TYPE_UINT8_T, 0, 20, offsetof(alink_hotpoint_current_t, centered) }, \
         { "type", NULL, ALINK_TYPE_UINT8_T, 0, 21, offsetof(alink_hotpoint_current_t, type) }, \
         { "round_cur", NULL, ALINK_TYPE_UINT8_T, 0, 22, offsetof(alink_hotpoint_current_t, round_cur) }, \
         { "status", NULL, ALINK_TYPE_UINT8_T, 0, 23, offsetof(alink_hotpoint_current_t, status) }, \
         } \
}


/**
 * @brief Pack a hotpoint_current message
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 *
 * @param timestamp timestamp (milliseconds since system boot)
 * @param lat hot point pos,Latitude (WGS84), in degrees * 1E7
 * @param lon hot point pos,Longitude (WGS84), in degrees * 1E7
 * @param alt hot point pos,Altitude , in mm
 * @param centered hot point be centered or not; 0: not; 1:centered
 * @param type hot point type; 0: fixed; 1:moving
 * @param round_cur hot point current round
 * @param status way point status. 0:pause; 1:running; 2:completed; other:as defiens latter
 * @param speed_set way point speed set,in 1e-3 m/s
 * @param radius way point radius,in 1e-3 m
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_hotpoint_current_pack(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg,
						       uint32_t timestamp, int32_t lat, int32_t lon, int32_t alt, uint8_t centered, uint8_t type, uint8_t round_cur, uint8_t status, int16_t speed_set, int16_t radius)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_HOTPOINT_CURRENT_LEN];
	_mav_put_uint32_t(buf, 0, timestamp);
	_mav_put_int32_t(buf, 4, lat);
	_mav_put_int32_t(buf, 8, lon);
	_mav_put_int32_t(buf, 12, alt);
	_mav_put_int16_t(buf, 16, speed_set);
	_mav_put_int16_t(buf, 18, radius);
	_mav_put_uint8_t(buf, 20, centered);
	_mav_put_uint8_t(buf, 21, type);
	_mav_put_uint8_t(buf, 22, round_cur);
	_mav_put_uint8_t(buf, 23, status);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_HOTPOINT_CURRENT_LEN);
#else
	alink_hotpoint_current_t packet;
	packet.timestamp = timestamp;
	packet.lat = lat;
	packet.lon = lon;
	packet.alt = alt;
	packet.speed_set = speed_set;
	packet.radius = radius;
	packet.centered = centered;
	packet.type = type;
	packet.round_cur = round_cur;
	packet.status = status;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_HOTPOINT_CURRENT_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_HOTPOINT_CURRENT;
#if ALINK_CRC_EXTRA
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_HOTPOINT_CURRENT_LEN,ALINK_MSG_ID_HOTPOINT_CURRENT_CRC);
#else
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_HOTPOINT_CURRENT_LEN);
#endif
}

/**
 * @brief Pack a hotpoint_current message on a channel
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param timestamp timestamp (milliseconds since system boot)
 * @param lat hot point pos,Latitude (WGS84), in degrees * 1E7
 * @param lon hot point pos,Longitude (WGS84), in degrees * 1E7
 * @param alt hot point pos,Altitude , in mm
 * @param centered hot point be centered or not; 0: not; 1:centered
 * @param type hot point type; 0: fixed; 1:moving
 * @param round_cur hot point current round
 * @param status way point status. 0:pause; 1:running; 2:completed; other:as defiens latter
 * @param speed_set way point speed set,in 1e-3 m/s
 * @param radius way point radius,in 1e-3 m
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_hotpoint_current_pack_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan,
							   alink_message_head_t* msg,
						           uint32_t timestamp,int32_t lat,int32_t lon,int32_t alt,uint8_t centered,uint8_t type,uint8_t round_cur,uint8_t status,int16_t speed_set,int16_t radius)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_HOTPOINT_CURRENT_LEN];
	_mav_put_uint32_t(buf, 0, timestamp);
	_mav_put_int32_t(buf, 4, lat);
	_mav_put_int32_t(buf, 8, lon);
	_mav_put_int32_t(buf, 12, alt);
	_mav_put_int16_t(buf, 16, speed_set);
	_mav_put_int16_t(buf, 18, radius);
	_mav_put_uint8_t(buf, 20, centered);
	_mav_put_uint8_t(buf, 21, type);
	_mav_put_uint8_t(buf, 22, round_cur);
	_mav_put_uint8_t(buf, 23, status);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_HOTPOINT_CURRENT_LEN);
#else
	alink_hotpoint_current_t packet;
	packet.timestamp = timestamp;
	packet.lat = lat;
	packet.lon = lon;
	packet.alt = alt;
	packet.speed_set = speed_set;
	packet.radius = radius;
	packet.centered = centered;
	packet.type = type;
	packet.round_cur = round_cur;
	packet.status = status;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_HOTPOINT_CURRENT_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_HOTPOINT_CURRENT;
#if ALINK_CRC_EXTRA
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_HOTPOINT_CURRENT_LEN,ALINK_MSG_ID_HOTPOINT_CURRENT_CRC);
#else
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_HOTPOINT_CURRENT_LEN);
#endif
}
/**
 * @brief Encode a hotpoint_current struct
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 * @param hotpoint_current C-struct to read the message contents from
 */
static inline uint16_t alink_msg_hotpoint_current_encode(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg, const alink_hotpoint_current_t* hotpoint_current)
{
	return alink_msg_hotpoint_current_pack(dest_id, source_id, msg, hotpoint_current->timestamp, hotpoint_current->lat, hotpoint_current->lon, hotpoint_current->alt, hotpoint_current->centered, hotpoint_current->type, hotpoint_current->round_cur, hotpoint_current->status, hotpoint_current->speed_set, hotpoint_current->radius);
}

/**
 * @brief Encode a hotpoint_current struct on a channel
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param hotpoint_current C-struct to read the message contents from
 */
static inline uint16_t alink_msg_hotpoint_current_encode_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan, alink_message_head_t* msg, const alink_hotpoint_current_t* hotpoint_current)
{
	return alink_msg_hotpoint_current_pack_chan(dest_id, source_id, chan, msg, hotpoint_current->timestamp, hotpoint_current->lat, hotpoint_current->lon, hotpoint_current->alt, hotpoint_current->centered, hotpoint_current->type, hotpoint_current->round_cur, hotpoint_current->status, hotpoint_current->speed_set, hotpoint_current->radius);
}
// MESSAGE HOTPOINT_CURRENT UNPACKING


/**
 * @brief Get field timestamp from hotpoint_current message
 *
 * @return timestamp (milliseconds since system boot)
 */
static inline uint32_t alink_msg_hotpoint_current_get_timestamp(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field lat from hotpoint_current message
 *
 * @return hot point pos,Latitude (WGS84), in degrees * 1E7
 */
static inline int32_t alink_msg_hotpoint_current_get_lat(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  4);
}

/**
 * @brief Get field lon from hotpoint_current message
 *
 * @return hot point pos,Longitude (WGS84), in degrees * 1E7
 */
static inline int32_t alink_msg_hotpoint_current_get_lon(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  8);
}

/**
 * @brief Get field alt from hotpoint_current message
 *
 * @return hot point pos,Altitude , in mm
 */
static inline int32_t alink_msg_hotpoint_current_get_alt(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  12);
}

/**
 * @brief Get field centered from hotpoint_current message
 *
 * @return hot point be centered or not; 0: not; 1:centered
 */
static inline uint8_t alink_msg_hotpoint_current_get_centered(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  20);
}

/**
 * @brief Get field type from hotpoint_current message
 *
 * @return hot point type; 0: fixed; 1:moving
 */
static inline uint8_t alink_msg_hotpoint_current_get_type(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  21);
}

/**
 * @brief Get field round_cur from hotpoint_current message
 *
 * @return hot point current round
 */
static inline uint8_t alink_msg_hotpoint_current_get_round_cur(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  22);
}

/**
 * @brief Get field status from hotpoint_current message
 *
 * @return way point status. 0:pause; 1:running; 2:completed; other:as defiens latter
 */
static inline uint8_t alink_msg_hotpoint_current_get_status(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  23);
}

/**
 * @brief Get field speed_set from hotpoint_current message
 *
 * @return way point speed set,in 1e-3 m/s
 */
static inline int16_t alink_msg_hotpoint_current_get_speed_set(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  16);
}

/**
 * @brief Get field radius from hotpoint_current message
 *
 * @return way point radius,in 1e-3 m
 */
static inline int16_t alink_msg_hotpoint_current_get_radius(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  18);
}

/**
 * @brief Decode a hotpoint_current message into a struct
 *
 * @param msg The message to decode
 * @param hotpoint_current C-struct to decode the message contents into
 */
static inline void alink_msg_hotpoint_current_decode(const alink_message_head_t* msg, alink_hotpoint_current_t* hotpoint_current)
{
#if ALINK_NEED_BYTE_SWAP
	hotpoint_current->timestamp = alink_msg_hotpoint_current_get_timestamp(msg);
	hotpoint_current->lat = alink_msg_hotpoint_current_get_lat(msg);
	hotpoint_current->lon = alink_msg_hotpoint_current_get_lon(msg);
	hotpoint_current->alt = alink_msg_hotpoint_current_get_alt(msg);
	hotpoint_current->speed_set = alink_msg_hotpoint_current_get_speed_set(msg);
	hotpoint_current->radius = alink_msg_hotpoint_current_get_radius(msg);
	hotpoint_current->centered = alink_msg_hotpoint_current_get_centered(msg);
	hotpoint_current->type = alink_msg_hotpoint_current_get_type(msg);
	hotpoint_current->round_cur = alink_msg_hotpoint_current_get_round_cur(msg);
	hotpoint_current->status = alink_msg_hotpoint_current_get_status(msg);
#else
	memcpy(hotpoint_current, _MAV_PAYLOAD(msg), ALINK_MSG_ID_HOTPOINT_CURRENT_LEN);
#endif
}
