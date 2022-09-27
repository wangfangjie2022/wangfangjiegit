// MESSAGE MOVIDUS_SET_GOAL_AREA PACKING

#define ALINK_MSG_ID_MOVIDUS_SET_GOAL_AREA 122

typedef struct __alink_movidus_set_goal_area_t
{
 float start_x; /*< pixel coordinate x*/
 float start_y; /*< pixel coordinate y*/
 float width; /*< bounding box of the target*/
 float height; /*< bounding box of the target*/
 float confidence; /*< confidence of target*/
 uint32_t type; /*< type of target*/
} alink_movidus_set_goal_area_t;

#define ALINK_MSG_ID_MOVIDUS_SET_GOAL_AREA_LEN 24
#define ALINK_MSG_ID_122_LEN 24

#define ALINK_MSG_ID_MOVIDUS_SET_GOAL_AREA_CRC 46
#define ALINK_MSG_ID_122_CRC 46



#define ALINK_MESSAGE_INFO_MOVIDUS_SET_GOAL_AREA { \
	"MOVIDUS_SET_GOAL_AREA", \
	6, \
	{  { "start_x", NULL, ALINK_TYPE_FLOAT, 0, 0, offsetof(alink_movidus_set_goal_area_t, start_x) }, \
         { "start_y", NULL, ALINK_TYPE_FLOAT, 0, 4, offsetof(alink_movidus_set_goal_area_t, start_y) }, \
         { "width", NULL, ALINK_TYPE_FLOAT, 0, 8, offsetof(alink_movidus_set_goal_area_t, width) }, \
         { "height", NULL, ALINK_TYPE_FLOAT, 0, 12, offsetof(alink_movidus_set_goal_area_t, height) }, \
         { "confidence", NULL, ALINK_TYPE_FLOAT, 0, 16, offsetof(alink_movidus_set_goal_area_t, confidence) }, \
         { "type", NULL, ALINK_TYPE_UINT32_T, 0, 20, offsetof(alink_movidus_set_goal_area_t, type) }, \
         } \
}


/**
 * @brief Pack a movidus_set_goal_area message
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 *
 * @param start_x pixel coordinate x
 * @param start_y pixel coordinate y
 * @param width bounding box of the target
 * @param height bounding box of the target
 * @param confidence confidence of target
 * @param type type of target
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_movidus_set_goal_area_pack(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg,
						       float start_x, float start_y, float width, float height, float confidence, uint32_t type)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_MOVIDUS_SET_GOAL_AREA_LEN];
	_mav_put_float(buf, 0, start_x);
	_mav_put_float(buf, 4, start_y);
	_mav_put_float(buf, 8, width);
	_mav_put_float(buf, 12, height);
	_mav_put_float(buf, 16, confidence);
	_mav_put_uint32_t(buf, 20, type);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_MOVIDUS_SET_GOAL_AREA_LEN);
#else
	alink_movidus_set_goal_area_t packet;
	packet.start_x = start_x;
	packet.start_y = start_y;
	packet.width = width;
	packet.height = height;
	packet.confidence = confidence;
	packet.type = type;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_MOVIDUS_SET_GOAL_AREA_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_MOVIDUS_SET_GOAL_AREA;
#if ALINK_CRC_EXTRA
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_MOVIDUS_SET_GOAL_AREA_LEN,ALINK_MSG_ID_MOVIDUS_SET_GOAL_AREA_CRC);
#else
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_MOVIDUS_SET_GOAL_AREA_LEN);
#endif
}

/**
 * @brief Pack a movidus_set_goal_area message on a channel
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param start_x pixel coordinate x
 * @param start_y pixel coordinate y
 * @param width bounding box of the target
 * @param height bounding box of the target
 * @param confidence confidence of target
 * @param type type of target
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_movidus_set_goal_area_pack_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan,
							   alink_message_head_t* msg,
						           float start_x,float start_y,float width,float height,float confidence,uint32_t type)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_MOVIDUS_SET_GOAL_AREA_LEN];
	_mav_put_float(buf, 0, start_x);
	_mav_put_float(buf, 4, start_y);
	_mav_put_float(buf, 8, width);
	_mav_put_float(buf, 12, height);
	_mav_put_float(buf, 16, confidence);
	_mav_put_uint32_t(buf, 20, type);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_MOVIDUS_SET_GOAL_AREA_LEN);
#else
	alink_movidus_set_goal_area_t packet;
	packet.start_x = start_x;
	packet.start_y = start_y;
	packet.width = width;
	packet.height = height;
	packet.confidence = confidence;
	packet.type = type;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_MOVIDUS_SET_GOAL_AREA_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_MOVIDUS_SET_GOAL_AREA;
#if ALINK_CRC_EXTRA
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_MOVIDUS_SET_GOAL_AREA_LEN,ALINK_MSG_ID_MOVIDUS_SET_GOAL_AREA_CRC);
#else
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_MOVIDUS_SET_GOAL_AREA_LEN);
#endif
}
/**
 * @brief Encode a movidus_set_goal_area struct
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 * @param movidus_set_goal_area C-struct to read the message contents from
 */
static inline uint16_t alink_msg_movidus_set_goal_area_encode(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg, const alink_movidus_set_goal_area_t* movidus_set_goal_area)
{
	return alink_msg_movidus_set_goal_area_pack(dest_id, source_id, msg, movidus_set_goal_area->start_x, movidus_set_goal_area->start_y, movidus_set_goal_area->width, movidus_set_goal_area->height, movidus_set_goal_area->confidence, movidus_set_goal_area->type);
}

/**
 * @brief Encode a movidus_set_goal_area struct on a channel
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param movidus_set_goal_area C-struct to read the message contents from
 */
static inline uint16_t alink_msg_movidus_set_goal_area_encode_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan, alink_message_head_t* msg, const alink_movidus_set_goal_area_t* movidus_set_goal_area)
{
	return alink_msg_movidus_set_goal_area_pack_chan(dest_id, source_id, chan, msg, movidus_set_goal_area->start_x, movidus_set_goal_area->start_y, movidus_set_goal_area->width, movidus_set_goal_area->height, movidus_set_goal_area->confidence, movidus_set_goal_area->type);
}
// MESSAGE MOVIDUS_SET_GOAL_AREA UNPACKING


/**
 * @brief Get field start_x from movidus_set_goal_area message
 *
 * @return pixel coordinate x
 */
static inline float alink_msg_movidus_set_goal_area_get_start_x(const alink_message_head_t* msg)
{
	return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field start_y from movidus_set_goal_area message
 *
 * @return pixel coordinate y
 */
static inline float alink_msg_movidus_set_goal_area_get_start_y(const alink_message_head_t* msg)
{
	return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field width from movidus_set_goal_area message
 *
 * @return bounding box of the target
 */
static inline float alink_msg_movidus_set_goal_area_get_width(const alink_message_head_t* msg)
{
	return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field height from movidus_set_goal_area message
 *
 * @return bounding box of the target
 */
static inline float alink_msg_movidus_set_goal_area_get_height(const alink_message_head_t* msg)
{
	return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field confidence from movidus_set_goal_area message
 *
 * @return confidence of target
 */
static inline float alink_msg_movidus_set_goal_area_get_confidence(const alink_message_head_t* msg)
{
	return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Get field type from movidus_set_goal_area message
 *
 * @return type of target
 */
static inline uint32_t alink_msg_movidus_set_goal_area_get_type(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint32_t(msg,  20);
}

/**
 * @brief Decode a movidus_set_goal_area message into a struct
 *
 * @param msg The message to decode
 * @param movidus_set_goal_area C-struct to decode the message contents into
 */
static inline void alink_msg_movidus_set_goal_area_decode(const alink_message_head_t* msg, alink_movidus_set_goal_area_t* movidus_set_goal_area)
{
#if ALINK_NEED_BYTE_SWAP
	movidus_set_goal_area->start_x = alink_msg_movidus_set_goal_area_get_start_x(msg);
	movidus_set_goal_area->start_y = alink_msg_movidus_set_goal_area_get_start_y(msg);
	movidus_set_goal_area->width = alink_msg_movidus_set_goal_area_get_width(msg);
	movidus_set_goal_area->height = alink_msg_movidus_set_goal_area_get_height(msg);
	movidus_set_goal_area->confidence = alink_msg_movidus_set_goal_area_get_confidence(msg);
	movidus_set_goal_area->type = alink_msg_movidus_set_goal_area_get_type(msg);
#else
	memcpy(movidus_set_goal_area, _MAV_PAYLOAD(msg), ALINK_MSG_ID_MOVIDUS_SET_GOAL_AREA_LEN);
#endif
}
