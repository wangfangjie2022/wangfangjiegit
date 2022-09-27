// MESSAGE PANORAMA_INFO PACKING

#define ALINK_MSG_ID_PANORAMA_INFO 85

typedef struct __alink_panorama_info_t
{
 int32_t mission_id; /*< mission id*/
 int32_t waypoint_id; /*< waypoint id*/
 int32_t number_rows; /*< number of rows*/
 int32_t number_columns; /*< number of columns*/
 int32_t heading_begin; /*<  cycles of this orbit */
 int32_t heading_end; /*< remain part of the cycles in deg */
 int32_t rotate_direction; /*<  0 -clockwise, 1 - counter-clockwise , 2 - auto minized */
 int32_t nadir_number; /*<  number of captures in nadir */
 int32_t pitch_max; /*< pitch max*/
 int32_t pitch_min; /*< pitch min*/
} alink_panorama_info_t;

#define ALINK_MSG_ID_PANORAMA_INFO_LEN 40
#define ALINK_MSG_ID_85_LEN 40

#define ALINK_MSG_ID_PANORAMA_INFO_CRC 119
#define ALINK_MSG_ID_85_CRC 119



#define ALINK_MESSAGE_INFO_PANORAMA_INFO { \
	"PANORAMA_INFO", \
	10, \
	{  { "mission_id", NULL, ALINK_TYPE_INT32_T, 0, 0, offsetof(alink_panorama_info_t, mission_id) }, \
         { "waypoint_id", NULL, ALINK_TYPE_INT32_T, 0, 4, offsetof(alink_panorama_info_t, waypoint_id) }, \
         { "number_rows", NULL, ALINK_TYPE_INT32_T, 0, 8, offsetof(alink_panorama_info_t, number_rows) }, \
         { "number_columns", NULL, ALINK_TYPE_INT32_T, 0, 12, offsetof(alink_panorama_info_t, number_columns) }, \
         { "heading_begin", NULL, ALINK_TYPE_INT32_T, 0, 16, offsetof(alink_panorama_info_t, heading_begin) }, \
         { "heading_end", NULL, ALINK_TYPE_INT32_T, 0, 20, offsetof(alink_panorama_info_t, heading_end) }, \
         { "rotate_direction", NULL, ALINK_TYPE_INT32_T, 0, 24, offsetof(alink_panorama_info_t, rotate_direction) }, \
         { "nadir_number", NULL, ALINK_TYPE_INT32_T, 0, 28, offsetof(alink_panorama_info_t, nadir_number) }, \
         { "pitch_max", NULL, ALINK_TYPE_INT32_T, 0, 32, offsetof(alink_panorama_info_t, pitch_max) }, \
         { "pitch_min", NULL, ALINK_TYPE_INT32_T, 0, 36, offsetof(alink_panorama_info_t, pitch_min) }, \
         } \
}


/**
 * @brief Pack a panorama_info message
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 *
 * @param mission_id mission id
 * @param waypoint_id waypoint id
 * @param number_rows number of rows
 * @param number_columns number of columns
 * @param heading_begin  cycles of this orbit 
 * @param heading_end remain part of the cycles in deg 
 * @param rotate_direction  0 -clockwise, 1 - counter-clockwise , 2 - auto minized 
 * @param nadir_number  number of captures in nadir 
 * @param pitch_max pitch max
 * @param pitch_min pitch min
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_panorama_info_pack(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg,
						       int32_t mission_id, int32_t waypoint_id, int32_t number_rows, int32_t number_columns, int32_t heading_begin, int32_t heading_end, int32_t rotate_direction, int32_t nadir_number, int32_t pitch_max, int32_t pitch_min)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_PANORAMA_INFO_LEN];
	_mav_put_int32_t(buf, 0, mission_id);
	_mav_put_int32_t(buf, 4, waypoint_id);
	_mav_put_int32_t(buf, 8, number_rows);
	_mav_put_int32_t(buf, 12, number_columns);
	_mav_put_int32_t(buf, 16, heading_begin);
	_mav_put_int32_t(buf, 20, heading_end);
	_mav_put_int32_t(buf, 24, rotate_direction);
	_mav_put_int32_t(buf, 28, nadir_number);
	_mav_put_int32_t(buf, 32, pitch_max);
	_mav_put_int32_t(buf, 36, pitch_min);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_PANORAMA_INFO_LEN);
#else
	alink_panorama_info_t packet;
	packet.mission_id = mission_id;
	packet.waypoint_id = waypoint_id;
	packet.number_rows = number_rows;
	packet.number_columns = number_columns;
	packet.heading_begin = heading_begin;
	packet.heading_end = heading_end;
	packet.rotate_direction = rotate_direction;
	packet.nadir_number = nadir_number;
	packet.pitch_max = pitch_max;
	packet.pitch_min = pitch_min;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_PANORAMA_INFO_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_PANORAMA_INFO;
#if ALINK_CRC_EXTRA
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_PANORAMA_INFO_LEN,ALINK_MSG_ID_PANORAMA_INFO_CRC);
#else
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_PANORAMA_INFO_LEN);
#endif
}

/**
 * @brief Pack a panorama_info message on a channel
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param mission_id mission id
 * @param waypoint_id waypoint id
 * @param number_rows number of rows
 * @param number_columns number of columns
 * @param heading_begin  cycles of this orbit 
 * @param heading_end remain part of the cycles in deg 
 * @param rotate_direction  0 -clockwise, 1 - counter-clockwise , 2 - auto minized 
 * @param nadir_number  number of captures in nadir 
 * @param pitch_max pitch max
 * @param pitch_min pitch min
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_panorama_info_pack_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan,
							   alink_message_head_t* msg,
						           int32_t mission_id,int32_t waypoint_id,int32_t number_rows,int32_t number_columns,int32_t heading_begin,int32_t heading_end,int32_t rotate_direction,int32_t nadir_number,int32_t pitch_max,int32_t pitch_min)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_PANORAMA_INFO_LEN];
	_mav_put_int32_t(buf, 0, mission_id);
	_mav_put_int32_t(buf, 4, waypoint_id);
	_mav_put_int32_t(buf, 8, number_rows);
	_mav_put_int32_t(buf, 12, number_columns);
	_mav_put_int32_t(buf, 16, heading_begin);
	_mav_put_int32_t(buf, 20, heading_end);
	_mav_put_int32_t(buf, 24, rotate_direction);
	_mav_put_int32_t(buf, 28, nadir_number);
	_mav_put_int32_t(buf, 32, pitch_max);
	_mav_put_int32_t(buf, 36, pitch_min);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_PANORAMA_INFO_LEN);
#else
	alink_panorama_info_t packet;
	packet.mission_id = mission_id;
	packet.waypoint_id = waypoint_id;
	packet.number_rows = number_rows;
	packet.number_columns = number_columns;
	packet.heading_begin = heading_begin;
	packet.heading_end = heading_end;
	packet.rotate_direction = rotate_direction;
	packet.nadir_number = nadir_number;
	packet.pitch_max = pitch_max;
	packet.pitch_min = pitch_min;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_PANORAMA_INFO_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_PANORAMA_INFO;
#if ALINK_CRC_EXTRA
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_PANORAMA_INFO_LEN,ALINK_MSG_ID_PANORAMA_INFO_CRC);
#else
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_PANORAMA_INFO_LEN);
#endif
}
/**
 * @brief Encode a panorama_info struct
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 * @param panorama_info C-struct to read the message contents from
 */
static inline uint16_t alink_msg_panorama_info_encode(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg, const alink_panorama_info_t* panorama_info)
{
	return alink_msg_panorama_info_pack(dest_id, source_id, msg, panorama_info->mission_id, panorama_info->waypoint_id, panorama_info->number_rows, panorama_info->number_columns, panorama_info->heading_begin, panorama_info->heading_end, panorama_info->rotate_direction, panorama_info->nadir_number, panorama_info->pitch_max, panorama_info->pitch_min);
}

/**
 * @brief Encode a panorama_info struct on a channel
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param panorama_info C-struct to read the message contents from
 */
static inline uint16_t alink_msg_panorama_info_encode_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan, alink_message_head_t* msg, const alink_panorama_info_t* panorama_info)
{
	return alink_msg_panorama_info_pack_chan(dest_id, source_id, chan, msg, panorama_info->mission_id, panorama_info->waypoint_id, panorama_info->number_rows, panorama_info->number_columns, panorama_info->heading_begin, panorama_info->heading_end, panorama_info->rotate_direction, panorama_info->nadir_number, panorama_info->pitch_max, panorama_info->pitch_min);
}
// MESSAGE PANORAMA_INFO UNPACKING


/**
 * @brief Get field mission_id from panorama_info message
 *
 * @return mission id
 */
static inline int32_t alink_msg_panorama_info_get_mission_id(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  0);
}

/**
 * @brief Get field waypoint_id from panorama_info message
 *
 * @return waypoint id
 */
static inline int32_t alink_msg_panorama_info_get_waypoint_id(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  4);
}

/**
 * @brief Get field number_rows from panorama_info message
 *
 * @return number of rows
 */
static inline int32_t alink_msg_panorama_info_get_number_rows(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  8);
}

/**
 * @brief Get field number_columns from panorama_info message
 *
 * @return number of columns
 */
static inline int32_t alink_msg_panorama_info_get_number_columns(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  12);
}

/**
 * @brief Get field heading_begin from panorama_info message
 *
 * @return  cycles of this orbit 
 */
static inline int32_t alink_msg_panorama_info_get_heading_begin(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  16);
}

/**
 * @brief Get field heading_end from panorama_info message
 *
 * @return remain part of the cycles in deg 
 */
static inline int32_t alink_msg_panorama_info_get_heading_end(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  20);
}

/**
 * @brief Get field rotate_direction from panorama_info message
 *
 * @return  0 -clockwise, 1 - counter-clockwise , 2 - auto minized 
 */
static inline int32_t alink_msg_panorama_info_get_rotate_direction(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  24);
}

/**
 * @brief Get field nadir_number from panorama_info message
 *
 * @return  number of captures in nadir 
 */
static inline int32_t alink_msg_panorama_info_get_nadir_number(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  28);
}

/**
 * @brief Get field pitch_max from panorama_info message
 *
 * @return pitch max
 */
static inline int32_t alink_msg_panorama_info_get_pitch_max(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  32);
}

/**
 * @brief Get field pitch_min from panorama_info message
 *
 * @return pitch min
 */
static inline int32_t alink_msg_panorama_info_get_pitch_min(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  36);
}

/**
 * @brief Decode a panorama_info message into a struct
 *
 * @param msg The message to decode
 * @param panorama_info C-struct to decode the message contents into
 */
static inline void alink_msg_panorama_info_decode(const alink_message_head_t* msg, alink_panorama_info_t* panorama_info)
{
#if ALINK_NEED_BYTE_SWAP
	panorama_info->mission_id = alink_msg_panorama_info_get_mission_id(msg);
	panorama_info->waypoint_id = alink_msg_panorama_info_get_waypoint_id(msg);
	panorama_info->number_rows = alink_msg_panorama_info_get_number_rows(msg);
	panorama_info->number_columns = alink_msg_panorama_info_get_number_columns(msg);
	panorama_info->heading_begin = alink_msg_panorama_info_get_heading_begin(msg);
	panorama_info->heading_end = alink_msg_panorama_info_get_heading_end(msg);
	panorama_info->rotate_direction = alink_msg_panorama_info_get_rotate_direction(msg);
	panorama_info->nadir_number = alink_msg_panorama_info_get_nadir_number(msg);
	panorama_info->pitch_max = alink_msg_panorama_info_get_pitch_max(msg);
	panorama_info->pitch_min = alink_msg_panorama_info_get_pitch_min(msg);
#else
	memcpy(panorama_info, _MAV_PAYLOAD(msg), ALINK_MSG_ID_PANORAMA_INFO_LEN);
#endif
}
