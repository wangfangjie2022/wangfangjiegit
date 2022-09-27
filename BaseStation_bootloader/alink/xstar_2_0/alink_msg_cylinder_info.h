// MESSAGE CYLINDER_INFO PACKING

#define ALINK_MSG_ID_CYLINDER_INFO 84

typedef struct __alink_cylinder_info_t
{
 int32_t mission_id; /*< mission id*/
 int32_t waypoint_id; /*< waypoint id*/
 int32_t speed; /*< speed in m/s*/
 int32_t radius; /*< radius in m/s*/
 int32_t cycles; /*<  cycles of this orbit */
 int32_t remain_deg; /*< remain part of the cycles in deg */
 int32_t rotate_direction; /*<  0 -clockwise, 1 - counter-clockwise */
 int32_t heading_direction; /*<  0 - invalid, 1 - forward, 2 - center, 3 - outer, 4 - backward, 5 - user defined */
 int32_t lat_center; /*< lattitude of center in 10E-7 degree*/
 int32_t lon_center; /*< longitude of center in 10E-7 degree*/
 int32_t alt_center; /*< altitude of center in mm*/
 int32_t entry_direction; /*<  0 - nearest, 1 - Northest, 2 - Southest, 3 - Eastest, 4 - Westest */
} alink_cylinder_info_t;

#define ALINK_MSG_ID_CYLINDER_INFO_LEN 48
#define ALINK_MSG_ID_84_LEN 48

#define ALINK_MSG_ID_CYLINDER_INFO_CRC 110
#define ALINK_MSG_ID_84_CRC 110



#define ALINK_MESSAGE_INFO_CYLINDER_INFO { \
	"CYLINDER_INFO", \
	12, \
	{  { "mission_id", NULL, ALINK_TYPE_INT32_T, 0, 0, offsetof(alink_cylinder_info_t, mission_id) }, \
         { "waypoint_id", NULL, ALINK_TYPE_INT32_T, 0, 4, offsetof(alink_cylinder_info_t, waypoint_id) }, \
         { "speed", NULL, ALINK_TYPE_INT32_T, 0, 8, offsetof(alink_cylinder_info_t, speed) }, \
         { "radius", NULL, ALINK_TYPE_INT32_T, 0, 12, offsetof(alink_cylinder_info_t, radius) }, \
         { "cycles", NULL, ALINK_TYPE_INT32_T, 0, 16, offsetof(alink_cylinder_info_t, cycles) }, \
         { "remain_deg", NULL, ALINK_TYPE_INT32_T, 0, 20, offsetof(alink_cylinder_info_t, remain_deg) }, \
         { "rotate_direction", NULL, ALINK_TYPE_INT32_T, 0, 24, offsetof(alink_cylinder_info_t, rotate_direction) }, \
         { "heading_direction", NULL, ALINK_TYPE_INT32_T, 0, 28, offsetof(alink_cylinder_info_t, heading_direction) }, \
         { "lat_center", NULL, ALINK_TYPE_INT32_T, 0, 32, offsetof(alink_cylinder_info_t, lat_center) }, \
         { "lon_center", NULL, ALINK_TYPE_INT32_T, 0, 36, offsetof(alink_cylinder_info_t, lon_center) }, \
         { "alt_center", NULL, ALINK_TYPE_INT32_T, 0, 40, offsetof(alink_cylinder_info_t, alt_center) }, \
         { "entry_direction", NULL, ALINK_TYPE_INT32_T, 0, 44, offsetof(alink_cylinder_info_t, entry_direction) }, \
         } \
}


/**
 * @brief Pack a cylinder_info message
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 *
 * @param mission_id mission id
 * @param waypoint_id waypoint id
 * @param speed speed in m/s
 * @param radius radius in m/s
 * @param cycles  cycles of this orbit 
 * @param remain_deg remain part of the cycles in deg 
 * @param rotate_direction  0 -clockwise, 1 - counter-clockwise 
 * @param heading_direction  0 - invalid, 1 - forward, 2 - center, 3 - outer, 4 - backward, 5 - user defined 
 * @param lat_center lattitude of center in 10E-7 degree
 * @param lon_center longitude of center in 10E-7 degree
 * @param alt_center altitude of center in mm
 * @param entry_direction  0 - nearest, 1 - Northest, 2 - Southest, 3 - Eastest, 4 - Westest 
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_cylinder_info_pack(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg,
						       int32_t mission_id, int32_t waypoint_id, int32_t speed, int32_t radius, int32_t cycles, int32_t remain_deg, int32_t rotate_direction, int32_t heading_direction, int32_t lat_center, int32_t lon_center, int32_t alt_center, int32_t entry_direction)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_CYLINDER_INFO_LEN];
	_mav_put_int32_t(buf, 0, mission_id);
	_mav_put_int32_t(buf, 4, waypoint_id);
	_mav_put_int32_t(buf, 8, speed);
	_mav_put_int32_t(buf, 12, radius);
	_mav_put_int32_t(buf, 16, cycles);
	_mav_put_int32_t(buf, 20, remain_deg);
	_mav_put_int32_t(buf, 24, rotate_direction);
	_mav_put_int32_t(buf, 28, heading_direction);
	_mav_put_int32_t(buf, 32, lat_center);
	_mav_put_int32_t(buf, 36, lon_center);
	_mav_put_int32_t(buf, 40, alt_center);
	_mav_put_int32_t(buf, 44, entry_direction);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_CYLINDER_INFO_LEN);
#else
	alink_cylinder_info_t packet;
	packet.mission_id = mission_id;
	packet.waypoint_id = waypoint_id;
	packet.speed = speed;
	packet.radius = radius;
	packet.cycles = cycles;
	packet.remain_deg = remain_deg;
	packet.rotate_direction = rotate_direction;
	packet.heading_direction = heading_direction;
	packet.lat_center = lat_center;
	packet.lon_center = lon_center;
	packet.alt_center = alt_center;
	packet.entry_direction = entry_direction;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_CYLINDER_INFO_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_CYLINDER_INFO;
#if ALINK_CRC_EXTRA
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_CYLINDER_INFO_LEN,ALINK_MSG_ID_CYLINDER_INFO_CRC);
#else
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_CYLINDER_INFO_LEN);
#endif
}

/**
 * @brief Pack a cylinder_info message on a channel
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param mission_id mission id
 * @param waypoint_id waypoint id
 * @param speed speed in m/s
 * @param radius radius in m/s
 * @param cycles  cycles of this orbit 
 * @param remain_deg remain part of the cycles in deg 
 * @param rotate_direction  0 -clockwise, 1 - counter-clockwise 
 * @param heading_direction  0 - invalid, 1 - forward, 2 - center, 3 - outer, 4 - backward, 5 - user defined 
 * @param lat_center lattitude of center in 10E-7 degree
 * @param lon_center longitude of center in 10E-7 degree
 * @param alt_center altitude of center in mm
 * @param entry_direction  0 - nearest, 1 - Northest, 2 - Southest, 3 - Eastest, 4 - Westest 
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_cylinder_info_pack_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan,
							   alink_message_head_t* msg,
						           int32_t mission_id,int32_t waypoint_id,int32_t speed,int32_t radius,int32_t cycles,int32_t remain_deg,int32_t rotate_direction,int32_t heading_direction,int32_t lat_center,int32_t lon_center,int32_t alt_center,int32_t entry_direction)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_CYLINDER_INFO_LEN];
	_mav_put_int32_t(buf, 0, mission_id);
	_mav_put_int32_t(buf, 4, waypoint_id);
	_mav_put_int32_t(buf, 8, speed);
	_mav_put_int32_t(buf, 12, radius);
	_mav_put_int32_t(buf, 16, cycles);
	_mav_put_int32_t(buf, 20, remain_deg);
	_mav_put_int32_t(buf, 24, rotate_direction);
	_mav_put_int32_t(buf, 28, heading_direction);
	_mav_put_int32_t(buf, 32, lat_center);
	_mav_put_int32_t(buf, 36, lon_center);
	_mav_put_int32_t(buf, 40, alt_center);
	_mav_put_int32_t(buf, 44, entry_direction);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_CYLINDER_INFO_LEN);
#else
	alink_cylinder_info_t packet;
	packet.mission_id = mission_id;
	packet.waypoint_id = waypoint_id;
	packet.speed = speed;
	packet.radius = radius;
	packet.cycles = cycles;
	packet.remain_deg = remain_deg;
	packet.rotate_direction = rotate_direction;
	packet.heading_direction = heading_direction;
	packet.lat_center = lat_center;
	packet.lon_center = lon_center;
	packet.alt_center = alt_center;
	packet.entry_direction = entry_direction;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_CYLINDER_INFO_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_CYLINDER_INFO;
#if ALINK_CRC_EXTRA
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_CYLINDER_INFO_LEN,ALINK_MSG_ID_CYLINDER_INFO_CRC);
#else
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_CYLINDER_INFO_LEN);
#endif
}
/**
 * @brief Encode a cylinder_info struct
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 * @param cylinder_info C-struct to read the message contents from
 */
static inline uint16_t alink_msg_cylinder_info_encode(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg, const alink_cylinder_info_t* cylinder_info)
{
	return alink_msg_cylinder_info_pack(dest_id, source_id, msg, cylinder_info->mission_id, cylinder_info->waypoint_id, cylinder_info->speed, cylinder_info->radius, cylinder_info->cycles, cylinder_info->remain_deg, cylinder_info->rotate_direction, cylinder_info->heading_direction, cylinder_info->lat_center, cylinder_info->lon_center, cylinder_info->alt_center, cylinder_info->entry_direction);
}

/**
 * @brief Encode a cylinder_info struct on a channel
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param cylinder_info C-struct to read the message contents from
 */
static inline uint16_t alink_msg_cylinder_info_encode_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan, alink_message_head_t* msg, const alink_cylinder_info_t* cylinder_info)
{
	return alink_msg_cylinder_info_pack_chan(dest_id, source_id, chan, msg, cylinder_info->mission_id, cylinder_info->waypoint_id, cylinder_info->speed, cylinder_info->radius, cylinder_info->cycles, cylinder_info->remain_deg, cylinder_info->rotate_direction, cylinder_info->heading_direction, cylinder_info->lat_center, cylinder_info->lon_center, cylinder_info->alt_center, cylinder_info->entry_direction);
}
// MESSAGE CYLINDER_INFO UNPACKING


/**
 * @brief Get field mission_id from cylinder_info message
 *
 * @return mission id
 */
static inline int32_t alink_msg_cylinder_info_get_mission_id(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  0);
}

/**
 * @brief Get field waypoint_id from cylinder_info message
 *
 * @return waypoint id
 */
static inline int32_t alink_msg_cylinder_info_get_waypoint_id(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  4);
}

/**
 * @brief Get field speed from cylinder_info message
 *
 * @return speed in m/s
 */
static inline int32_t alink_msg_cylinder_info_get_speed(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  8);
}

/**
 * @brief Get field radius from cylinder_info message
 *
 * @return radius in m/s
 */
static inline int32_t alink_msg_cylinder_info_get_radius(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  12);
}

/**
 * @brief Get field cycles from cylinder_info message
 *
 * @return  cycles of this orbit 
 */
static inline int32_t alink_msg_cylinder_info_get_cycles(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  16);
}

/**
 * @brief Get field remain_deg from cylinder_info message
 *
 * @return remain part of the cycles in deg 
 */
static inline int32_t alink_msg_cylinder_info_get_remain_deg(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  20);
}

/**
 * @brief Get field rotate_direction from cylinder_info message
 *
 * @return  0 -clockwise, 1 - counter-clockwise 
 */
static inline int32_t alink_msg_cylinder_info_get_rotate_direction(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  24);
}

/**
 * @brief Get field heading_direction from cylinder_info message
 *
 * @return  0 - invalid, 1 - forward, 2 - center, 3 - outer, 4 - backward, 5 - user defined 
 */
static inline int32_t alink_msg_cylinder_info_get_heading_direction(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  28);
}

/**
 * @brief Get field lat_center from cylinder_info message
 *
 * @return lattitude of center in 10E-7 degree
 */
static inline int32_t alink_msg_cylinder_info_get_lat_center(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  32);
}

/**
 * @brief Get field lon_center from cylinder_info message
 *
 * @return longitude of center in 10E-7 degree
 */
static inline int32_t alink_msg_cylinder_info_get_lon_center(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  36);
}

/**
 * @brief Get field alt_center from cylinder_info message
 *
 * @return altitude of center in mm
 */
static inline int32_t alink_msg_cylinder_info_get_alt_center(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  40);
}

/**
 * @brief Get field entry_direction from cylinder_info message
 *
 * @return  0 - nearest, 1 - Northest, 2 - Southest, 3 - Eastest, 4 - Westest 
 */
static inline int32_t alink_msg_cylinder_info_get_entry_direction(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  44);
}

/**
 * @brief Decode a cylinder_info message into a struct
 *
 * @param msg The message to decode
 * @param cylinder_info C-struct to decode the message contents into
 */
static inline void alink_msg_cylinder_info_decode(const alink_message_head_t* msg, alink_cylinder_info_t* cylinder_info)
{
#if ALINK_NEED_BYTE_SWAP
	cylinder_info->mission_id = alink_msg_cylinder_info_get_mission_id(msg);
	cylinder_info->waypoint_id = alink_msg_cylinder_info_get_waypoint_id(msg);
	cylinder_info->speed = alink_msg_cylinder_info_get_speed(msg);
	cylinder_info->radius = alink_msg_cylinder_info_get_radius(msg);
	cylinder_info->cycles = alink_msg_cylinder_info_get_cycles(msg);
	cylinder_info->remain_deg = alink_msg_cylinder_info_get_remain_deg(msg);
	cylinder_info->rotate_direction = alink_msg_cylinder_info_get_rotate_direction(msg);
	cylinder_info->heading_direction = alink_msg_cylinder_info_get_heading_direction(msg);
	cylinder_info->lat_center = alink_msg_cylinder_info_get_lat_center(msg);
	cylinder_info->lon_center = alink_msg_cylinder_info_get_lon_center(msg);
	cylinder_info->alt_center = alink_msg_cylinder_info_get_alt_center(msg);
	cylinder_info->entry_direction = alink_msg_cylinder_info_get_entry_direction(msg);
#else
	memcpy(cylinder_info, _MAV_PAYLOAD(msg), ALINK_MSG_ID_CYLINDER_INFO_LEN);
#endif
}
