// MESSAGE MOVIDUS_REPORT_GOAL_AREA PACKING

#define ALINK_MSG_ID_MOVIDUS_REPORT_GOAL_AREA 123

typedef struct __alink_movidus_report_goal_area_t
{
 uint64_t timestamp; /*< timestamp (microseconds since system boot)*/
 uint32_t number; /*< number of goal areas in this packet,MAX=8*/
 uint32_t total; /*< number of goal areas in the whole frame,MAX=64*/
 float start_x[8]; /*< pixel coordinate x*/
 float start_y[8]; /*< pixel coordinate y*/
 float width[8]; /*< width of 8 bounding box of the target*/
 float height[8]; /*< height of 8 bounding box of the target*/
 float distance[8]; /*< distance to plane of 8 targets*/
 uint32_t status[8]; /*< track status of 8 targets*/
 float confidence[8]; /*< confidence of 8 targets*/
 uint32_t type[8]; /*< type of 8 targets*/
 uint32_t id; /*< frame id*/
 uint32_t resolution_width; /*< image resolution ratio width*/
 uint32_t resolution_height; /*< image resolution ratio height*/
 uint8_t info[128]; /*< info of 8 targets*/
} alink_movidus_report_goal_area_t;

#define ALINK_MSG_ID_MOVIDUS_REPORT_GOAL_AREA_LEN 412
#define ALINK_MSG_ID_123_LEN 412

#define ALINK_MSG_ID_MOVIDUS_REPORT_GOAL_AREA_CRC 219
#define ALINK_MSG_ID_123_CRC 219

#define ALINK_MSG_MOVIDUS_REPORT_GOAL_AREA_FIELD_START_X_LEN 8
#define ALINK_MSG_MOVIDUS_REPORT_GOAL_AREA_FIELD_START_Y_LEN 8
#define ALINK_MSG_MOVIDUS_REPORT_GOAL_AREA_FIELD_WIDTH_LEN 8
#define ALINK_MSG_MOVIDUS_REPORT_GOAL_AREA_FIELD_HEIGHT_LEN 8
#define ALINK_MSG_MOVIDUS_REPORT_GOAL_AREA_FIELD_DISTANCE_LEN 8
#define ALINK_MSG_MOVIDUS_REPORT_GOAL_AREA_FIELD_STATUS_LEN 8
#define ALINK_MSG_MOVIDUS_REPORT_GOAL_AREA_FIELD_CONFIDENCE_LEN 8
#define ALINK_MSG_MOVIDUS_REPORT_GOAL_AREA_FIELD_TYPE_LEN 8
#define ALINK_MSG_MOVIDUS_REPORT_GOAL_AREA_FIELD_INFO_LEN 128

#define ALINK_MESSAGE_INFO_MOVIDUS_REPORT_GOAL_AREA { \
	"MOVIDUS_REPORT_GOAL_AREA", \
	15, \
	{  { "timestamp", NULL, ALINK_TYPE_UINT64_T, 0, 0, offsetof(alink_movidus_report_goal_area_t, timestamp) }, \
         { "number", NULL, ALINK_TYPE_UINT32_T, 0, 8, offsetof(alink_movidus_report_goal_area_t, number) }, \
         { "total", NULL, ALINK_TYPE_UINT32_T, 0, 12, offsetof(alink_movidus_report_goal_area_t, total) }, \
         { "start_x", NULL, ALINK_TYPE_FLOAT, 8, 16, offsetof(alink_movidus_report_goal_area_t, start_x) }, \
         { "start_y", NULL, ALINK_TYPE_FLOAT, 8, 48, offsetof(alink_movidus_report_goal_area_t, start_y) }, \
         { "width", NULL, ALINK_TYPE_FLOAT, 8, 80, offsetof(alink_movidus_report_goal_area_t, width) }, \
         { "height", NULL, ALINK_TYPE_FLOAT, 8, 112, offsetof(alink_movidus_report_goal_area_t, height) }, \
         { "distance", NULL, ALINK_TYPE_FLOAT, 8, 144, offsetof(alink_movidus_report_goal_area_t, distance) }, \
         { "status", NULL, ALINK_TYPE_UINT32_T, 8, 176, offsetof(alink_movidus_report_goal_area_t, status) }, \
         { "confidence", NULL, ALINK_TYPE_FLOAT, 8, 208, offsetof(alink_movidus_report_goal_area_t, confidence) }, \
         { "type", NULL, ALINK_TYPE_UINT32_T, 8, 240, offsetof(alink_movidus_report_goal_area_t, type) }, \
         { "id", NULL, ALINK_TYPE_UINT32_T, 0, 272, offsetof(alink_movidus_report_goal_area_t, id) }, \
         { "resolution_width", NULL, ALINK_TYPE_UINT32_T, 0, 276, offsetof(alink_movidus_report_goal_area_t, resolution_width) }, \
         { "resolution_height", NULL, ALINK_TYPE_UINT32_T, 0, 280, offsetof(alink_movidus_report_goal_area_t, resolution_height) }, \
         { "info", NULL, ALINK_TYPE_UINT8_T, 128, 284, offsetof(alink_movidus_report_goal_area_t, info) }, \
         } \
}


/**
 * @brief Pack a movidus_report_goal_area message
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 *
 * @param number number of goal areas in this packet,MAX=8
 * @param total number of goal areas in the whole frame,MAX=64
 * @param timestamp timestamp (microseconds since system boot)
 * @param start_x pixel coordinate x
 * @param start_y pixel coordinate y
 * @param width width of 8 bounding box of the target
 * @param height height of 8 bounding box of the target
 * @param distance distance to plane of 8 targets
 * @param status track status of 8 targets
 * @param confidence confidence of 8 targets
 * @param type type of 8 targets
 * @param info info of 8 targets
 * @param id frame id
 * @param resolution_width image resolution ratio width
 * @param resolution_height image resolution ratio height
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_movidus_report_goal_area_pack(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg,
						       uint32_t number, uint32_t total, uint64_t timestamp, const float *start_x, const float *start_y, const float *width, const float *height, const float *distance, const uint32_t *status, const float *confidence, const uint32_t *type, const uint8_t *info, uint32_t id, uint32_t resolution_width, uint32_t resolution_height)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_MOVIDUS_REPORT_GOAL_AREA_LEN];
	_mav_put_uint64_t(buf, 0, timestamp);
	_mav_put_uint32_t(buf, 8, number);
	_mav_put_uint32_t(buf, 12, total);
	_mav_put_uint32_t(buf, 272, id);
	_mav_put_uint32_t(buf, 276, resolution_width);
	_mav_put_uint32_t(buf, 280, resolution_height);
	_mav_put_float_array(buf, 16, start_x, 8);
	_mav_put_float_array(buf, 48, start_y, 8);
	_mav_put_float_array(buf, 80, width, 8);
	_mav_put_float_array(buf, 112, height, 8);
	_mav_put_float_array(buf, 144, distance, 8);
	_mav_put_uint32_t_array(buf, 176, status, 8);
	_mav_put_float_array(buf, 208, confidence, 8);
	_mav_put_uint32_t_array(buf, 240, type, 8);
	_mav_put_uint8_t_array(buf, 284, info, 128);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_MOVIDUS_REPORT_GOAL_AREA_LEN);
#else
	alink_movidus_report_goal_area_t packet;
	packet.timestamp = timestamp;
	packet.number = number;
	packet.total = total;
	packet.id = id;
	packet.resolution_width = resolution_width;
	packet.resolution_height = resolution_height;
	mav_array_memcpy(packet.start_x, start_x, sizeof(float)*8);
	mav_array_memcpy(packet.start_y, start_y, sizeof(float)*8);
	mav_array_memcpy(packet.width, width, sizeof(float)*8);
	mav_array_memcpy(packet.height, height, sizeof(float)*8);
	mav_array_memcpy(packet.distance, distance, sizeof(float)*8);
	mav_array_memcpy(packet.status, status, sizeof(uint32_t)*8);
	mav_array_memcpy(packet.confidence, confidence, sizeof(float)*8);
	mav_array_memcpy(packet.type, type, sizeof(uint32_t)*8);
	mav_array_memcpy(packet.info, info, sizeof(uint8_t)*128);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_MOVIDUS_REPORT_GOAL_AREA_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_MOVIDUS_REPORT_GOAL_AREA;
#if ALINK_CRC_EXTRA
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_MOVIDUS_REPORT_GOAL_AREA_LEN,ALINK_MSG_ID_MOVIDUS_REPORT_GOAL_AREA_CRC);
#else
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_MOVIDUS_REPORT_GOAL_AREA_LEN);
#endif
}

/**
 * @brief Pack a movidus_report_goal_area message on a channel
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param number number of goal areas in this packet,MAX=8
 * @param total number of goal areas in the whole frame,MAX=64
 * @param timestamp timestamp (microseconds since system boot)
 * @param start_x pixel coordinate x
 * @param start_y pixel coordinate y
 * @param width width of 8 bounding box of the target
 * @param height height of 8 bounding box of the target
 * @param distance distance to plane of 8 targets
 * @param status track status of 8 targets
 * @param confidence confidence of 8 targets
 * @param type type of 8 targets
 * @param info info of 8 targets
 * @param id frame id
 * @param resolution_width image resolution ratio width
 * @param resolution_height image resolution ratio height
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_movidus_report_goal_area_pack_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan,
							   alink_message_head_t* msg,
						           uint32_t number,uint32_t total,uint64_t timestamp,const float *start_x,const float *start_y,const float *width,const float *height,const float *distance,const uint32_t *status,const float *confidence,const uint32_t *type,const uint8_t *info,uint32_t id,uint32_t resolution_width,uint32_t resolution_height)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_MOVIDUS_REPORT_GOAL_AREA_LEN];
	_mav_put_uint64_t(buf, 0, timestamp);
	_mav_put_uint32_t(buf, 8, number);
	_mav_put_uint32_t(buf, 12, total);
	_mav_put_uint32_t(buf, 272, id);
	_mav_put_uint32_t(buf, 276, resolution_width);
	_mav_put_uint32_t(buf, 280, resolution_height);
	_mav_put_float_array(buf, 16, start_x, 8);
	_mav_put_float_array(buf, 48, start_y, 8);
	_mav_put_float_array(buf, 80, width, 8);
	_mav_put_float_array(buf, 112, height, 8);
	_mav_put_float_array(buf, 144, distance, 8);
	_mav_put_uint32_t_array(buf, 176, status, 8);
	_mav_put_float_array(buf, 208, confidence, 8);
	_mav_put_uint32_t_array(buf, 240, type, 8);
	_mav_put_uint8_t_array(buf, 284, info, 128);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_MOVIDUS_REPORT_GOAL_AREA_LEN);
#else
	alink_movidus_report_goal_area_t packet;
	packet.timestamp = timestamp;
	packet.number = number;
	packet.total = total;
	packet.id = id;
	packet.resolution_width = resolution_width;
	packet.resolution_height = resolution_height;
	mav_array_memcpy(packet.start_x, start_x, sizeof(float)*8);
	mav_array_memcpy(packet.start_y, start_y, sizeof(float)*8);
	mav_array_memcpy(packet.width, width, sizeof(float)*8);
	mav_array_memcpy(packet.height, height, sizeof(float)*8);
	mav_array_memcpy(packet.distance, distance, sizeof(float)*8);
	mav_array_memcpy(packet.status, status, sizeof(uint32_t)*8);
	mav_array_memcpy(packet.confidence, confidence, sizeof(float)*8);
	mav_array_memcpy(packet.type, type, sizeof(uint32_t)*8);
	mav_array_memcpy(packet.info, info, sizeof(uint8_t)*128);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_MOVIDUS_REPORT_GOAL_AREA_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_MOVIDUS_REPORT_GOAL_AREA;
#if ALINK_CRC_EXTRA
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_MOVIDUS_REPORT_GOAL_AREA_LEN,ALINK_MSG_ID_MOVIDUS_REPORT_GOAL_AREA_CRC);
#else
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_MOVIDUS_REPORT_GOAL_AREA_LEN);
#endif
}
/**
 * @brief Encode a movidus_report_goal_area struct
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 * @param movidus_report_goal_area C-struct to read the message contents from
 */
static inline uint16_t alink_msg_movidus_report_goal_area_encode(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg, const alink_movidus_report_goal_area_t* movidus_report_goal_area)
{
	return alink_msg_movidus_report_goal_area_pack(dest_id, source_id, msg, movidus_report_goal_area->number, movidus_report_goal_area->total, movidus_report_goal_area->timestamp, movidus_report_goal_area->start_x, movidus_report_goal_area->start_y, movidus_report_goal_area->width, movidus_report_goal_area->height, movidus_report_goal_area->distance, movidus_report_goal_area->status, movidus_report_goal_area->confidence, movidus_report_goal_area->type, movidus_report_goal_area->info, movidus_report_goal_area->id, movidus_report_goal_area->resolution_width, movidus_report_goal_area->resolution_height);
}

/**
 * @brief Encode a movidus_report_goal_area struct on a channel
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param movidus_report_goal_area C-struct to read the message contents from
 */
static inline uint16_t alink_msg_movidus_report_goal_area_encode_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan, alink_message_head_t* msg, const alink_movidus_report_goal_area_t* movidus_report_goal_area)
{
	return alink_msg_movidus_report_goal_area_pack_chan(dest_id, source_id, chan, msg, movidus_report_goal_area->number, movidus_report_goal_area->total, movidus_report_goal_area->timestamp, movidus_report_goal_area->start_x, movidus_report_goal_area->start_y, movidus_report_goal_area->width, movidus_report_goal_area->height, movidus_report_goal_area->distance, movidus_report_goal_area->status, movidus_report_goal_area->confidence, movidus_report_goal_area->type, movidus_report_goal_area->info, movidus_report_goal_area->id, movidus_report_goal_area->resolution_width, movidus_report_goal_area->resolution_height);
}
// MESSAGE MOVIDUS_REPORT_GOAL_AREA UNPACKING


/**
 * @brief Get field number from movidus_report_goal_area message
 *
 * @return number of goal areas in this packet,MAX=8
 */
static inline uint32_t alink_msg_movidus_report_goal_area_get_number(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint32_t(msg,  8);
}

/**
 * @brief Get field total from movidus_report_goal_area message
 *
 * @return number of goal areas in the whole frame,MAX=64
 */
static inline uint32_t alink_msg_movidus_report_goal_area_get_total(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint32_t(msg,  12);
}

/**
 * @brief Get field timestamp from movidus_report_goal_area message
 *
 * @return timestamp (microseconds since system boot)
 */
static inline uint64_t alink_msg_movidus_report_goal_area_get_timestamp(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field start_x from movidus_report_goal_area message
 *
 * @return pixel coordinate x
 */
static inline uint16_t alink_msg_movidus_report_goal_area_get_start_x(const alink_message_head_t* msg, float *start_x)
{
	return _MAV_RETURN_float_array(msg, start_x, 8,  16);
}

/**
 * @brief Get field start_y from movidus_report_goal_area message
 *
 * @return pixel coordinate y
 */
static inline uint16_t alink_msg_movidus_report_goal_area_get_start_y(const alink_message_head_t* msg, float *start_y)
{
	return _MAV_RETURN_float_array(msg, start_y, 8,  48);
}

/**
 * @brief Get field width from movidus_report_goal_area message
 *
 * @return width of 8 bounding box of the target
 */
static inline uint16_t alink_msg_movidus_report_goal_area_get_width(const alink_message_head_t* msg, float *width)
{
	return _MAV_RETURN_float_array(msg, width, 8,  80);
}

/**
 * @brief Get field height from movidus_report_goal_area message
 *
 * @return height of 8 bounding box of the target
 */
static inline uint16_t alink_msg_movidus_report_goal_area_get_height(const alink_message_head_t* msg, float *height)
{
	return _MAV_RETURN_float_array(msg, height, 8,  112);
}

/**
 * @brief Get field distance from movidus_report_goal_area message
 *
 * @return distance to plane of 8 targets
 */
static inline uint16_t alink_msg_movidus_report_goal_area_get_distance(const alink_message_head_t* msg, float *distance)
{
	return _MAV_RETURN_float_array(msg, distance, 8,  144);
}

/**
 * @brief Get field status from movidus_report_goal_area message
 *
 * @return track status of 8 targets
 */
static inline uint16_t alink_msg_movidus_report_goal_area_get_status(const alink_message_head_t* msg, uint32_t *status)
{
	return _MAV_RETURN_uint32_t_array(msg, status, 8,  176);
}

/**
 * @brief Get field confidence from movidus_report_goal_area message
 *
 * @return confidence of 8 targets
 */
static inline uint16_t alink_msg_movidus_report_goal_area_get_confidence(const alink_message_head_t* msg, float *confidence)
{
	return _MAV_RETURN_float_array(msg, confidence, 8,  208);
}

/**
 * @brief Get field type from movidus_report_goal_area message
 *
 * @return type of 8 targets
 */
static inline uint16_t alink_msg_movidus_report_goal_area_get_type(const alink_message_head_t* msg, uint32_t *type)
{
	return _MAV_RETURN_uint32_t_array(msg, type, 8,  240);
}

/**
 * @brief Get field info from movidus_report_goal_area message
 *
 * @return info of 8 targets
 */
static inline uint16_t alink_msg_movidus_report_goal_area_get_info(const alink_message_head_t* msg, uint8_t *info)
{
	return _MAV_RETURN_uint8_t_array(msg, info, 128,  284);
}

/**
 * @brief Get field id from movidus_report_goal_area message
 *
 * @return frame id
 */
static inline uint32_t alink_msg_movidus_report_goal_area_get_id(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint32_t(msg,  272);
}

/**
 * @brief Get field resolution_width from movidus_report_goal_area message
 *
 * @return image resolution ratio width
 */
static inline uint32_t alink_msg_movidus_report_goal_area_get_resolution_width(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint32_t(msg,  276);
}

/**
 * @brief Get field resolution_height from movidus_report_goal_area message
 *
 * @return image resolution ratio height
 */
static inline uint32_t alink_msg_movidus_report_goal_area_get_resolution_height(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint32_t(msg,  280);
}

/**
 * @brief Decode a movidus_report_goal_area message into a struct
 *
 * @param msg The message to decode
 * @param movidus_report_goal_area C-struct to decode the message contents into
 */
static inline void alink_msg_movidus_report_goal_area_decode(const alink_message_head_t* msg, alink_movidus_report_goal_area_t* movidus_report_goal_area)
{
#if ALINK_NEED_BYTE_SWAP
	movidus_report_goal_area->timestamp = alink_msg_movidus_report_goal_area_get_timestamp(msg);
	movidus_report_goal_area->number = alink_msg_movidus_report_goal_area_get_number(msg);
	movidus_report_goal_area->total = alink_msg_movidus_report_goal_area_get_total(msg);
	alink_msg_movidus_report_goal_area_get_start_x(msg, movidus_report_goal_area->start_x);
	alink_msg_movidus_report_goal_area_get_start_y(msg, movidus_report_goal_area->start_y);
	alink_msg_movidus_report_goal_area_get_width(msg, movidus_report_goal_area->width);
	alink_msg_movidus_report_goal_area_get_height(msg, movidus_report_goal_area->height);
	alink_msg_movidus_report_goal_area_get_distance(msg, movidus_report_goal_area->distance);
	alink_msg_movidus_report_goal_area_get_status(msg, movidus_report_goal_area->status);
	alink_msg_movidus_report_goal_area_get_confidence(msg, movidus_report_goal_area->confidence);
	alink_msg_movidus_report_goal_area_get_type(msg, movidus_report_goal_area->type);
	movidus_report_goal_area->id = alink_msg_movidus_report_goal_area_get_id(msg);
	movidus_report_goal_area->resolution_width = alink_msg_movidus_report_goal_area_get_resolution_width(msg);
	movidus_report_goal_area->resolution_height = alink_msg_movidus_report_goal_area_get_resolution_height(msg);
	alink_msg_movidus_report_goal_area_get_info(msg, movidus_report_goal_area->info);
#else
	memcpy(movidus_report_goal_area, _MAV_PAYLOAD(msg), ALINK_MSG_ID_MOVIDUS_REPORT_GOAL_AREA_LEN);
#endif
}
