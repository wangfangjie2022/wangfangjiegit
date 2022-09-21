// MESSAGE MOVIDUS_REPORT_TRACK_STATUS PACKING

#define ALINK_MSG_ID_MOVIDUS_REPORT_TRACK_STATUS 124

typedef struct __alink_movidus_report_track_status_t
{
 uint64_t timestamp; /*< timestamp (microseconds since system boot)*/
 float start_x; /*< pixel coordinate x*/
 float start_y; /*< pixel coordinate y*/
 float width; /*< bounding box of the target*/
 float height; /*< bounding box of the target*/
 float confidence; /*< confidence of target*/
 float distance; /*< distance between camera and target*/
 uint32_t status; /*< status of tracking*/
 uint32_t type; /*< type of tracking targets*/
 uint32_t resolution_width; /*< image resolution ratio width*/
 uint32_t resolution_height; /*< image resolution ratio height*/
 uint32_t id; /*< packetid*/
} alink_movidus_report_track_status_t;

#define ALINK_MSG_ID_MOVIDUS_REPORT_TRACK_STATUS_LEN 52
#define ALINK_MSG_ID_124_LEN 52

#define ALINK_MSG_ID_MOVIDUS_REPORT_TRACK_STATUS_CRC 8
#define ALINK_MSG_ID_124_CRC 8



#define ALINK_MESSAGE_INFO_MOVIDUS_REPORT_TRACK_STATUS { \
	"MOVIDUS_REPORT_TRACK_STATUS", \
	12, \
	{  { "timestamp", NULL, ALINK_TYPE_UINT64_T, 0, 0, offsetof(alink_movidus_report_track_status_t, timestamp) }, \
         { "start_x", NULL, ALINK_TYPE_FLOAT, 0, 8, offsetof(alink_movidus_report_track_status_t, start_x) }, \
         { "start_y", NULL, ALINK_TYPE_FLOAT, 0, 12, offsetof(alink_movidus_report_track_status_t, start_y) }, \
         { "width", NULL, ALINK_TYPE_FLOAT, 0, 16, offsetof(alink_movidus_report_track_status_t, width) }, \
         { "height", NULL, ALINK_TYPE_FLOAT, 0, 20, offsetof(alink_movidus_report_track_status_t, height) }, \
         { "confidence", NULL, ALINK_TYPE_FLOAT, 0, 24, offsetof(alink_movidus_report_track_status_t, confidence) }, \
         { "distance", NULL, ALINK_TYPE_FLOAT, 0, 28, offsetof(alink_movidus_report_track_status_t, distance) }, \
         { "status", NULL, ALINK_TYPE_UINT32_T, 0, 32, offsetof(alink_movidus_report_track_status_t, status) }, \
         { "type", NULL, ALINK_TYPE_UINT32_T, 0, 36, offsetof(alink_movidus_report_track_status_t, type) }, \
         { "resolution_width", NULL, ALINK_TYPE_UINT32_T, 0, 40, offsetof(alink_movidus_report_track_status_t, resolution_width) }, \
         { "resolution_height", NULL, ALINK_TYPE_UINT32_T, 0, 44, offsetof(alink_movidus_report_track_status_t, resolution_height) }, \
         { "id", NULL, ALINK_TYPE_UINT32_T, 0, 48, offsetof(alink_movidus_report_track_status_t, id) }, \
         } \
}


/**
 * @brief Pack a movidus_report_track_status message
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 *
 * @param start_x pixel coordinate x
 * @param start_y pixel coordinate y
 * @param width bounding box of the target
 * @param height bounding box of the target
 * @param confidence confidence of target
 * @param distance distance between camera and target
 * @param status status of tracking
 * @param type type of tracking targets
 * @param resolution_width image resolution ratio width
 * @param resolution_height image resolution ratio height
 * @param id packetid
 * @param timestamp timestamp (microseconds since system boot)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_movidus_report_track_status_pack(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg,
						       float start_x, float start_y, float width, float height, float confidence, float distance, uint32_t status, uint32_t type, uint32_t resolution_width, uint32_t resolution_height, uint32_t id, uint64_t timestamp)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_MOVIDUS_REPORT_TRACK_STATUS_LEN];
	_mav_put_uint64_t(buf, 0, timestamp);
	_mav_put_float(buf, 8, start_x);
	_mav_put_float(buf, 12, start_y);
	_mav_put_float(buf, 16, width);
	_mav_put_float(buf, 20, height);
	_mav_put_float(buf, 24, confidence);
	_mav_put_float(buf, 28, distance);
	_mav_put_uint32_t(buf, 32, status);
	_mav_put_uint32_t(buf, 36, type);
	_mav_put_uint32_t(buf, 40, resolution_width);
	_mav_put_uint32_t(buf, 44, resolution_height);
	_mav_put_uint32_t(buf, 48, id);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_MOVIDUS_REPORT_TRACK_STATUS_LEN);
#else
	alink_movidus_report_track_status_t packet;
	packet.timestamp = timestamp;
	packet.start_x = start_x;
	packet.start_y = start_y;
	packet.width = width;
	packet.height = height;
	packet.confidence = confidence;
	packet.distance = distance;
	packet.status = status;
	packet.type = type;
	packet.resolution_width = resolution_width;
	packet.resolution_height = resolution_height;
	packet.id = id;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_MOVIDUS_REPORT_TRACK_STATUS_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_MOVIDUS_REPORT_TRACK_STATUS;
#if ALINK_CRC_EXTRA
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_MOVIDUS_REPORT_TRACK_STATUS_LEN,ALINK_MSG_ID_MOVIDUS_REPORT_TRACK_STATUS_CRC);
#else
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_MOVIDUS_REPORT_TRACK_STATUS_LEN);
#endif
}

/**
 * @brief Pack a movidus_report_track_status message on a channel
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param start_x pixel coordinate x
 * @param start_y pixel coordinate y
 * @param width bounding box of the target
 * @param height bounding box of the target
 * @param confidence confidence of target
 * @param distance distance between camera and target
 * @param status status of tracking
 * @param type type of tracking targets
 * @param resolution_width image resolution ratio width
 * @param resolution_height image resolution ratio height
 * @param id packetid
 * @param timestamp timestamp (microseconds since system boot)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_movidus_report_track_status_pack_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan,
							   alink_message_head_t* msg,
						           float start_x,float start_y,float width,float height,float confidence,float distance,uint32_t status,uint32_t type,uint32_t resolution_width,uint32_t resolution_height,uint32_t id,uint64_t timestamp)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_MOVIDUS_REPORT_TRACK_STATUS_LEN];
	_mav_put_uint64_t(buf, 0, timestamp);
	_mav_put_float(buf, 8, start_x);
	_mav_put_float(buf, 12, start_y);
	_mav_put_float(buf, 16, width);
	_mav_put_float(buf, 20, height);
	_mav_put_float(buf, 24, confidence);
	_mav_put_float(buf, 28, distance);
	_mav_put_uint32_t(buf, 32, status);
	_mav_put_uint32_t(buf, 36, type);
	_mav_put_uint32_t(buf, 40, resolution_width);
	_mav_put_uint32_t(buf, 44, resolution_height);
	_mav_put_uint32_t(buf, 48, id);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_MOVIDUS_REPORT_TRACK_STATUS_LEN);
#else
	alink_movidus_report_track_status_t packet;
	packet.timestamp = timestamp;
	packet.start_x = start_x;
	packet.start_y = start_y;
	packet.width = width;
	packet.height = height;
	packet.confidence = confidence;
	packet.distance = distance;
	packet.status = status;
	packet.type = type;
	packet.resolution_width = resolution_width;
	packet.resolution_height = resolution_height;
	packet.id = id;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_MOVIDUS_REPORT_TRACK_STATUS_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_MOVIDUS_REPORT_TRACK_STATUS;
#if ALINK_CRC_EXTRA
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_MOVIDUS_REPORT_TRACK_STATUS_LEN,ALINK_MSG_ID_MOVIDUS_REPORT_TRACK_STATUS_CRC);
#else
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_MOVIDUS_REPORT_TRACK_STATUS_LEN);
#endif
}
/**
 * @brief Encode a movidus_report_track_status struct
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 * @param movidus_report_track_status C-struct to read the message contents from
 */
static inline uint16_t alink_msg_movidus_report_track_status_encode(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg, const alink_movidus_report_track_status_t* movidus_report_track_status)
{
	return alink_msg_movidus_report_track_status_pack(dest_id, source_id, msg, movidus_report_track_status->start_x, movidus_report_track_status->start_y, movidus_report_track_status->width, movidus_report_track_status->height, movidus_report_track_status->confidence, movidus_report_track_status->distance, movidus_report_track_status->status, movidus_report_track_status->type, movidus_report_track_status->resolution_width, movidus_report_track_status->resolution_height, movidus_report_track_status->id, movidus_report_track_status->timestamp);
}

/**
 * @brief Encode a movidus_report_track_status struct on a channel
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param movidus_report_track_status C-struct to read the message contents from
 */
static inline uint16_t alink_msg_movidus_report_track_status_encode_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan, alink_message_head_t* msg, const alink_movidus_report_track_status_t* movidus_report_track_status)
{
	return alink_msg_movidus_report_track_status_pack_chan(dest_id, source_id, chan, msg, movidus_report_track_status->start_x, movidus_report_track_status->start_y, movidus_report_track_status->width, movidus_report_track_status->height, movidus_report_track_status->confidence, movidus_report_track_status->distance, movidus_report_track_status->status, movidus_report_track_status->type, movidus_report_track_status->resolution_width, movidus_report_track_status->resolution_height, movidus_report_track_status->id, movidus_report_track_status->timestamp);
}
// MESSAGE MOVIDUS_REPORT_TRACK_STATUS UNPACKING


/**
 * @brief Get field start_x from movidus_report_track_status message
 *
 * @return pixel coordinate x
 */
static inline float alink_msg_movidus_report_track_status_get_start_x(const alink_message_head_t* msg)
{
	return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field start_y from movidus_report_track_status message
 *
 * @return pixel coordinate y
 */
static inline float alink_msg_movidus_report_track_status_get_start_y(const alink_message_head_t* msg)
{
	return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field width from movidus_report_track_status message
 *
 * @return bounding box of the target
 */
static inline float alink_msg_movidus_report_track_status_get_width(const alink_message_head_t* msg)
{
	return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Get field height from movidus_report_track_status message
 *
 * @return bounding box of the target
 */
static inline float alink_msg_movidus_report_track_status_get_height(const alink_message_head_t* msg)
{
	return _MAV_RETURN_float(msg,  20);
}

/**
 * @brief Get field confidence from movidus_report_track_status message
 *
 * @return confidence of target
 */
static inline float alink_msg_movidus_report_track_status_get_confidence(const alink_message_head_t* msg)
{
	return _MAV_RETURN_float(msg,  24);
}

/**
 * @brief Get field distance from movidus_report_track_status message
 *
 * @return distance between camera and target
 */
static inline float alink_msg_movidus_report_track_status_get_distance(const alink_message_head_t* msg)
{
	return _MAV_RETURN_float(msg,  28);
}

/**
 * @brief Get field status from movidus_report_track_status message
 *
 * @return status of tracking
 */
static inline uint32_t alink_msg_movidus_report_track_status_get_status(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint32_t(msg,  32);
}

/**
 * @brief Get field type from movidus_report_track_status message
 *
 * @return type of tracking targets
 */
static inline uint32_t alink_msg_movidus_report_track_status_get_type(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint32_t(msg,  36);
}

/**
 * @brief Get field resolution_width from movidus_report_track_status message
 *
 * @return image resolution ratio width
 */
static inline uint32_t alink_msg_movidus_report_track_status_get_resolution_width(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint32_t(msg,  40);
}

/**
 * @brief Get field resolution_height from movidus_report_track_status message
 *
 * @return image resolution ratio height
 */
static inline uint32_t alink_msg_movidus_report_track_status_get_resolution_height(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint32_t(msg,  44);
}

/**
 * @brief Get field id from movidus_report_track_status message
 *
 * @return packetid
 */
static inline uint32_t alink_msg_movidus_report_track_status_get_id(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint32_t(msg,  48);
}

/**
 * @brief Get field timestamp from movidus_report_track_status message
 *
 * @return timestamp (microseconds since system boot)
 */
static inline uint64_t alink_msg_movidus_report_track_status_get_timestamp(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Decode a movidus_report_track_status message into a struct
 *
 * @param msg The message to decode
 * @param movidus_report_track_status C-struct to decode the message contents into
 */
static inline void alink_msg_movidus_report_track_status_decode(const alink_message_head_t* msg, alink_movidus_report_track_status_t* movidus_report_track_status)
{
#if ALINK_NEED_BYTE_SWAP
	movidus_report_track_status->timestamp = alink_msg_movidus_report_track_status_get_timestamp(msg);
	movidus_report_track_status->start_x = alink_msg_movidus_report_track_status_get_start_x(msg);
	movidus_report_track_status->start_y = alink_msg_movidus_report_track_status_get_start_y(msg);
	movidus_report_track_status->width = alink_msg_movidus_report_track_status_get_width(msg);
	movidus_report_track_status->height = alink_msg_movidus_report_track_status_get_height(msg);
	movidus_report_track_status->confidence = alink_msg_movidus_report_track_status_get_confidence(msg);
	movidus_report_track_status->distance = alink_msg_movidus_report_track_status_get_distance(msg);
	movidus_report_track_status->status = alink_msg_movidus_report_track_status_get_status(msg);
	movidus_report_track_status->type = alink_msg_movidus_report_track_status_get_type(msg);
	movidus_report_track_status->resolution_width = alink_msg_movidus_report_track_status_get_resolution_width(msg);
	movidus_report_track_status->resolution_height = alink_msg_movidus_report_track_status_get_resolution_height(msg);
	movidus_report_track_status->id = alink_msg_movidus_report_track_status_get_id(msg);
#else
	memcpy(movidus_report_track_status, _MAV_PAYLOAD(msg), ALINK_MSG_ID_MOVIDUS_REPORT_TRACK_STATUS_LEN);
#endif
}
