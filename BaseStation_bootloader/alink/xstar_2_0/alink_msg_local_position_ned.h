// MESSAGE LOCAL_POSITION_NED PACKING

#define ALINK_MSG_ID_LOCAL_POSITION_NED 41

typedef struct __alink_local_position_ned_t
{
 uint32_t timestamp; /*< timestamp (milliseconds since system boot)*/
 int32_t lat; /*< Latitude (WGS84), in degrees * 1E7*/
 int32_t lon; /*< Longitude (WGS84), in degrees * 1E7*/
 int32_t rel_alt; /*< realative alt, in cm*/
 int32_t alt; /*< alt, in cm*/
 int32_t home_lat; /*< home Latitude (WGS84), in degrees * 1E7*/
 int32_t home_lon; /*< home Longitude (WGS84), in degrees * 1E7*/
 int32_t home_alt; /*< home alt, in mm*/
 float vxyz; /*< Absolute Speed, root of square X/Y/Z 's sum*/
 float airspeed; /*< airspeed, m/s*/
 uint16_t distance; /*< distance*/
} alink_local_position_ned_t;

#define ALINK_MSG_ID_LOCAL_POSITION_NED_LEN 42
#define ALINK_MSG_ID_41_LEN 42

#define ALINK_MSG_ID_LOCAL_POSITION_NED_CRC 111
#define ALINK_MSG_ID_41_CRC 111



#define ALINK_MESSAGE_INFO_LOCAL_POSITION_NED { \
	"LOCAL_POSITION_NED", \
	11, \
	{  { "timestamp", NULL, ALINK_TYPE_UINT32_T, 0, 0, offsetof(alink_local_position_ned_t, timestamp) }, \
         { "lat", NULL, ALINK_TYPE_INT32_T, 0, 4, offsetof(alink_local_position_ned_t, lat) }, \
         { "lon", NULL, ALINK_TYPE_INT32_T, 0, 8, offsetof(alink_local_position_ned_t, lon) }, \
         { "rel_alt", NULL, ALINK_TYPE_INT32_T, 0, 12, offsetof(alink_local_position_ned_t, rel_alt) }, \
         { "alt", NULL, ALINK_TYPE_INT32_T, 0, 16, offsetof(alink_local_position_ned_t, alt) }, \
         { "home_lat", NULL, ALINK_TYPE_INT32_T, 0, 20, offsetof(alink_local_position_ned_t, home_lat) }, \
         { "home_lon", NULL, ALINK_TYPE_INT32_T, 0, 24, offsetof(alink_local_position_ned_t, home_lon) }, \
         { "home_alt", NULL, ALINK_TYPE_INT32_T, 0, 28, offsetof(alink_local_position_ned_t, home_alt) }, \
         { "vxyz", NULL, ALINK_TYPE_FLOAT, 0, 32, offsetof(alink_local_position_ned_t, vxyz) }, \
         { "airspeed", NULL, ALINK_TYPE_FLOAT, 0, 36, offsetof(alink_local_position_ned_t, airspeed) }, \
         { "distance", NULL, ALINK_TYPE_UINT16_T, 0, 40, offsetof(alink_local_position_ned_t, distance) }, \
         } \
}


/**
 * @brief Pack a local_position_ned message
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 *
 * @param timestamp timestamp (milliseconds since system boot)
 * @param distance distance
 * @param lat Latitude (WGS84), in degrees * 1E7
 * @param lon Longitude (WGS84), in degrees * 1E7
 * @param rel_alt realative alt, in cm
 * @param alt alt, in cm
 * @param home_lat home Latitude (WGS84), in degrees * 1E7
 * @param home_lon home Longitude (WGS84), in degrees * 1E7
 * @param home_alt home alt, in mm
 * @param vxyz Absolute Speed, root of square X/Y/Z 's sum
 * @param airspeed airspeed, m/s
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_local_position_ned_pack(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg,
						       uint32_t timestamp, uint16_t distance, int32_t lat, int32_t lon, int32_t rel_alt, int32_t alt, int32_t home_lat, int32_t home_lon, int32_t home_alt, float vxyz, float airspeed)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_LOCAL_POSITION_NED_LEN];
	_mav_put_uint32_t(buf, 0, timestamp);
	_mav_put_int32_t(buf, 4, lat);
	_mav_put_int32_t(buf, 8, lon);
	_mav_put_int32_t(buf, 12, rel_alt);
	_mav_put_int32_t(buf, 16, alt);
	_mav_put_int32_t(buf, 20, home_lat);
	_mav_put_int32_t(buf, 24, home_lon);
	_mav_put_int32_t(buf, 28, home_alt);
	_mav_put_float(buf, 32, vxyz);
	_mav_put_float(buf, 36, airspeed);
	_mav_put_uint16_t(buf, 40, distance);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_LOCAL_POSITION_NED_LEN);
#else
	alink_local_position_ned_t packet;
	packet.timestamp = timestamp;
	packet.lat = lat;
	packet.lon = lon;
	packet.rel_alt = rel_alt;
	packet.alt = alt;
	packet.home_lat = home_lat;
	packet.home_lon = home_lon;
	packet.home_alt = home_alt;
	packet.vxyz = vxyz;
	packet.airspeed = airspeed;
	packet.distance = distance;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_LOCAL_POSITION_NED_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_LOCAL_POSITION_NED;
#if ALINK_CRC_EXTRA
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_LOCAL_POSITION_NED_LEN,ALINK_MSG_ID_LOCAL_POSITION_NED_CRC);
#else
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_LOCAL_POSITION_NED_LEN);
#endif
}

/**
 * @brief Pack a local_position_ned message on a channel
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param timestamp timestamp (milliseconds since system boot)
 * @param distance distance
 * @param lat Latitude (WGS84), in degrees * 1E7
 * @param lon Longitude (WGS84), in degrees * 1E7
 * @param rel_alt realative alt, in cm
 * @param alt alt, in cm
 * @param home_lat home Latitude (WGS84), in degrees * 1E7
 * @param home_lon home Longitude (WGS84), in degrees * 1E7
 * @param home_alt home alt, in mm
 * @param vxyz Absolute Speed, root of square X/Y/Z 's sum
 * @param airspeed airspeed, m/s
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_local_position_ned_pack_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan,
							   alink_message_head_t* msg,
						           uint32_t timestamp,uint16_t distance,int32_t lat,int32_t lon,int32_t rel_alt,int32_t alt,int32_t home_lat,int32_t home_lon,int32_t home_alt,float vxyz,float airspeed)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_LOCAL_POSITION_NED_LEN];
	_mav_put_uint32_t(buf, 0, timestamp);
	_mav_put_int32_t(buf, 4, lat);
	_mav_put_int32_t(buf, 8, lon);
	_mav_put_int32_t(buf, 12, rel_alt);
	_mav_put_int32_t(buf, 16, alt);
	_mav_put_int32_t(buf, 20, home_lat);
	_mav_put_int32_t(buf, 24, home_lon);
	_mav_put_int32_t(buf, 28, home_alt);
	_mav_put_float(buf, 32, vxyz);
	_mav_put_float(buf, 36, airspeed);
	_mav_put_uint16_t(buf, 40, distance);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_LOCAL_POSITION_NED_LEN);
#else
	alink_local_position_ned_t packet;
	packet.timestamp = timestamp;
	packet.lat = lat;
	packet.lon = lon;
	packet.rel_alt = rel_alt;
	packet.alt = alt;
	packet.home_lat = home_lat;
	packet.home_lon = home_lon;
	packet.home_alt = home_alt;
	packet.vxyz = vxyz;
	packet.airspeed = airspeed;
	packet.distance = distance;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_LOCAL_POSITION_NED_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_LOCAL_POSITION_NED;
#if ALINK_CRC_EXTRA
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_LOCAL_POSITION_NED_LEN,ALINK_MSG_ID_LOCAL_POSITION_NED_CRC);
#else
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_LOCAL_POSITION_NED_LEN);
#endif
}
/**
 * @brief Encode a local_position_ned struct
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 * @param local_position_ned C-struct to read the message contents from
 */
static inline uint16_t alink_msg_local_position_ned_encode(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg, const alink_local_position_ned_t* local_position_ned)
{
	return alink_msg_local_position_ned_pack(dest_id, source_id, msg, local_position_ned->timestamp, local_position_ned->distance, local_position_ned->lat, local_position_ned->lon, local_position_ned->rel_alt, local_position_ned->alt, local_position_ned->home_lat, local_position_ned->home_lon, local_position_ned->home_alt, local_position_ned->vxyz, local_position_ned->airspeed);
}

/**
 * @brief Encode a local_position_ned struct on a channel
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param local_position_ned C-struct to read the message contents from
 */
static inline uint16_t alink_msg_local_position_ned_encode_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan, alink_message_head_t* msg, const alink_local_position_ned_t* local_position_ned)
{
	return alink_msg_local_position_ned_pack_chan(dest_id, source_id, chan, msg, local_position_ned->timestamp, local_position_ned->distance, local_position_ned->lat, local_position_ned->lon, local_position_ned->rel_alt, local_position_ned->alt, local_position_ned->home_lat, local_position_ned->home_lon, local_position_ned->home_alt, local_position_ned->vxyz, local_position_ned->airspeed);
}
// MESSAGE LOCAL_POSITION_NED UNPACKING


/**
 * @brief Get field timestamp from local_position_ned message
 *
 * @return timestamp (milliseconds since system boot)
 */
static inline uint32_t alink_msg_local_position_ned_get_timestamp(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field distance from local_position_ned message
 *
 * @return distance
 */
static inline uint16_t alink_msg_local_position_ned_get_distance(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  40);
}

/**
 * @brief Get field lat from local_position_ned message
 *
 * @return Latitude (WGS84), in degrees * 1E7
 */
static inline int32_t alink_msg_local_position_ned_get_lat(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  4);
}

/**
 * @brief Get field lon from local_position_ned message
 *
 * @return Longitude (WGS84), in degrees * 1E7
 */
static inline int32_t alink_msg_local_position_ned_get_lon(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  8);
}

/**
 * @brief Get field rel_alt from local_position_ned message
 *
 * @return realative alt, in cm
 */
static inline int32_t alink_msg_local_position_ned_get_rel_alt(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  12);
}

/**
 * @brief Get field alt from local_position_ned message
 *
 * @return alt, in cm
 */
static inline int32_t alink_msg_local_position_ned_get_alt(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  16);
}

/**
 * @brief Get field home_lat from local_position_ned message
 *
 * @return home Latitude (WGS84), in degrees * 1E7
 */
static inline int32_t alink_msg_local_position_ned_get_home_lat(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  20);
}

/**
 * @brief Get field home_lon from local_position_ned message
 *
 * @return home Longitude (WGS84), in degrees * 1E7
 */
static inline int32_t alink_msg_local_position_ned_get_home_lon(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  24);
}

/**
 * @brief Get field home_alt from local_position_ned message
 *
 * @return home alt, in mm
 */
static inline int32_t alink_msg_local_position_ned_get_home_alt(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  28);
}

/**
 * @brief Get field vxyz from local_position_ned message
 *
 * @return Absolute Speed, root of square X/Y/Z 's sum
 */
static inline float alink_msg_local_position_ned_get_vxyz(const alink_message_head_t* msg)
{
	return _MAV_RETURN_float(msg,  32);
}

/**
 * @brief Get field airspeed from local_position_ned message
 *
 * @return airspeed, m/s
 */
static inline float alink_msg_local_position_ned_get_airspeed(const alink_message_head_t* msg)
{
	return _MAV_RETURN_float(msg,  36);
}

/**
 * @brief Decode a local_position_ned message into a struct
 *
 * @param msg The message to decode
 * @param local_position_ned C-struct to decode the message contents into
 */
static inline void alink_msg_local_position_ned_decode(const alink_message_head_t* msg, alink_local_position_ned_t* local_position_ned)
{
#if ALINK_NEED_BYTE_SWAP
	local_position_ned->timestamp = alink_msg_local_position_ned_get_timestamp(msg);
	local_position_ned->lat = alink_msg_local_position_ned_get_lat(msg);
	local_position_ned->lon = alink_msg_local_position_ned_get_lon(msg);
	local_position_ned->rel_alt = alink_msg_local_position_ned_get_rel_alt(msg);
	local_position_ned->alt = alink_msg_local_position_ned_get_alt(msg);
	local_position_ned->home_lat = alink_msg_local_position_ned_get_home_lat(msg);
	local_position_ned->home_lon = alink_msg_local_position_ned_get_home_lon(msg);
	local_position_ned->home_alt = alink_msg_local_position_ned_get_home_alt(msg);
	local_position_ned->vxyz = alink_msg_local_position_ned_get_vxyz(msg);
	local_position_ned->airspeed = alink_msg_local_position_ned_get_airspeed(msg);
	local_position_ned->distance = alink_msg_local_position_ned_get_distance(msg);
#else
	memcpy(local_position_ned, _MAV_PAYLOAD(msg), ALINK_MSG_ID_LOCAL_POSITION_NED_LEN);
#endif
}
