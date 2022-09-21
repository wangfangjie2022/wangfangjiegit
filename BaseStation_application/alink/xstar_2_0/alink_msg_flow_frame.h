// MESSAGE FLOW_FRAME PACKING

#define ALINK_MSG_ID_FLOW_FRAME 97

typedef struct __alink_flow_frame_t
{
 uint32_t integration_timespan; /*< Integration timespan*/
 uint32_t sonar_timestamp; /*< Sonar timestamp*/
 int16_t pixel_flow_x_integral; /*< Pixel flow X integral*/
 int16_t pixel_flow_y_integral; /*< Pixel flow Y integral*/
 uint16_t ground_distance; /*< Ground distance*/
 uint8_t quality_x; /*< Pixel flow X confidence*/
 uint8_t quality_y; /*< Pixel flow Y confidence*/
} alink_flow_frame_t;

#define ALINK_MSG_ID_FLOW_FRAME_LEN 16
#define ALINK_MSG_ID_97_LEN 16

#define ALINK_MSG_ID_FLOW_FRAME_CRC 142
#define ALINK_MSG_ID_97_CRC 142



#define ALINK_MESSAGE_INFO_FLOW_FRAME { \
	"FLOW_FRAME", \
	7, \
	{  { "integration_timespan", NULL, ALINK_TYPE_UINT32_T, 0, 0, offsetof(alink_flow_frame_t, integration_timespan) }, \
         { "sonar_timestamp", NULL, ALINK_TYPE_UINT32_T, 0, 4, offsetof(alink_flow_frame_t, sonar_timestamp) }, \
         { "pixel_flow_x_integral", NULL, ALINK_TYPE_INT16_T, 0, 8, offsetof(alink_flow_frame_t, pixel_flow_x_integral) }, \
         { "pixel_flow_y_integral", NULL, ALINK_TYPE_INT16_T, 0, 10, offsetof(alink_flow_frame_t, pixel_flow_y_integral) }, \
         { "ground_distance", NULL, ALINK_TYPE_UINT16_T, 0, 12, offsetof(alink_flow_frame_t, ground_distance) }, \
         { "quality_x", NULL, ALINK_TYPE_UINT8_T, 0, 14, offsetof(alink_flow_frame_t, quality_x) }, \
         { "quality_y", NULL, ALINK_TYPE_UINT8_T, 0, 15, offsetof(alink_flow_frame_t, quality_y) }, \
         } \
}


/**
 * @brief Pack a flow_frame message
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 *
 * @param integration_timespan Integration timespan
 * @param pixel_flow_x_integral Pixel flow X integral
 * @param pixel_flow_y_integral Pixel flow Y integral
 * @param quality_x Pixel flow X confidence
 * @param quality_y Pixel flow Y confidence
 * @param sonar_timestamp Sonar timestamp
 * @param ground_distance Ground distance
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_flow_frame_pack(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg,
						       uint32_t integration_timespan, int16_t pixel_flow_x_integral, int16_t pixel_flow_y_integral, uint8_t quality_x, uint8_t quality_y, uint32_t sonar_timestamp, uint16_t ground_distance)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_FLOW_FRAME_LEN];
	_mav_put_uint32_t(buf, 0, integration_timespan);
	_mav_put_uint32_t(buf, 4, sonar_timestamp);
	_mav_put_int16_t(buf, 8, pixel_flow_x_integral);
	_mav_put_int16_t(buf, 10, pixel_flow_y_integral);
	_mav_put_uint16_t(buf, 12, ground_distance);
	_mav_put_uint8_t(buf, 14, quality_x);
	_mav_put_uint8_t(buf, 15, quality_y);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_FLOW_FRAME_LEN);
#else
	alink_flow_frame_t packet;
	packet.integration_timespan = integration_timespan;
	packet.sonar_timestamp = sonar_timestamp;
	packet.pixel_flow_x_integral = pixel_flow_x_integral;
	packet.pixel_flow_y_integral = pixel_flow_y_integral;
	packet.ground_distance = ground_distance;
	packet.quality_x = quality_x;
	packet.quality_y = quality_y;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_FLOW_FRAME_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_FLOW_FRAME;
#if ALINK_CRC_EXTRA
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_FLOW_FRAME_LEN,ALINK_MSG_ID_FLOW_FRAME_CRC);
#else
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_FLOW_FRAME_LEN);
#endif
}

/**
 * @brief Pack a flow_frame message on a channel
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param integration_timespan Integration timespan
 * @param pixel_flow_x_integral Pixel flow X integral
 * @param pixel_flow_y_integral Pixel flow Y integral
 * @param quality_x Pixel flow X confidence
 * @param quality_y Pixel flow Y confidence
 * @param sonar_timestamp Sonar timestamp
 * @param ground_distance Ground distance
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_flow_frame_pack_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan,
							   alink_message_head_t* msg,
						           uint32_t integration_timespan,int16_t pixel_flow_x_integral,int16_t pixel_flow_y_integral,uint8_t quality_x,uint8_t quality_y,uint32_t sonar_timestamp,uint16_t ground_distance)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_FLOW_FRAME_LEN];
	_mav_put_uint32_t(buf, 0, integration_timespan);
	_mav_put_uint32_t(buf, 4, sonar_timestamp);
	_mav_put_int16_t(buf, 8, pixel_flow_x_integral);
	_mav_put_int16_t(buf, 10, pixel_flow_y_integral);
	_mav_put_uint16_t(buf, 12, ground_distance);
	_mav_put_uint8_t(buf, 14, quality_x);
	_mav_put_uint8_t(buf, 15, quality_y);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_FLOW_FRAME_LEN);
#else
	alink_flow_frame_t packet;
	packet.integration_timespan = integration_timespan;
	packet.sonar_timestamp = sonar_timestamp;
	packet.pixel_flow_x_integral = pixel_flow_x_integral;
	packet.pixel_flow_y_integral = pixel_flow_y_integral;
	packet.ground_distance = ground_distance;
	packet.quality_x = quality_x;
	packet.quality_y = quality_y;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_FLOW_FRAME_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_FLOW_FRAME;
#if ALINK_CRC_EXTRA
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_FLOW_FRAME_LEN,ALINK_MSG_ID_FLOW_FRAME_CRC);
#else
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_FLOW_FRAME_LEN);
#endif
}
/**
 * @brief Encode a flow_frame struct
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 * @param flow_frame C-struct to read the message contents from
 */
static inline uint16_t alink_msg_flow_frame_encode(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg, const alink_flow_frame_t* flow_frame)
{
	return alink_msg_flow_frame_pack(dest_id, source_id, msg, flow_frame->integration_timespan, flow_frame->pixel_flow_x_integral, flow_frame->pixel_flow_y_integral, flow_frame->quality_x, flow_frame->quality_y, flow_frame->sonar_timestamp, flow_frame->ground_distance);
}

/**
 * @brief Encode a flow_frame struct on a channel
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param flow_frame C-struct to read the message contents from
 */
static inline uint16_t alink_msg_flow_frame_encode_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan, alink_message_head_t* msg, const alink_flow_frame_t* flow_frame)
{
	return alink_msg_flow_frame_pack_chan(dest_id, source_id, chan, msg, flow_frame->integration_timespan, flow_frame->pixel_flow_x_integral, flow_frame->pixel_flow_y_integral, flow_frame->quality_x, flow_frame->quality_y, flow_frame->sonar_timestamp, flow_frame->ground_distance);
}
// MESSAGE FLOW_FRAME UNPACKING


/**
 * @brief Get field integration_timespan from flow_frame message
 *
 * @return Integration timespan
 */
static inline uint32_t alink_msg_flow_frame_get_integration_timespan(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field pixel_flow_x_integral from flow_frame message
 *
 * @return Pixel flow X integral
 */
static inline int16_t alink_msg_flow_frame_get_pixel_flow_x_integral(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  8);
}

/**
 * @brief Get field pixel_flow_y_integral from flow_frame message
 *
 * @return Pixel flow Y integral
 */
static inline int16_t alink_msg_flow_frame_get_pixel_flow_y_integral(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  10);
}

/**
 * @brief Get field quality_x from flow_frame message
 *
 * @return Pixel flow X confidence
 */
static inline uint8_t alink_msg_flow_frame_get_quality_x(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  14);
}

/**
 * @brief Get field quality_y from flow_frame message
 *
 * @return Pixel flow Y confidence
 */
static inline uint8_t alink_msg_flow_frame_get_quality_y(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  15);
}

/**
 * @brief Get field sonar_timestamp from flow_frame message
 *
 * @return Sonar timestamp
 */
static inline uint32_t alink_msg_flow_frame_get_sonar_timestamp(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint32_t(msg,  4);
}

/**
 * @brief Get field ground_distance from flow_frame message
 *
 * @return Ground distance
 */
static inline uint16_t alink_msg_flow_frame_get_ground_distance(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  12);
}

/**
 * @brief Decode a flow_frame message into a struct
 *
 * @param msg The message to decode
 * @param flow_frame C-struct to decode the message contents into
 */
static inline void alink_msg_flow_frame_decode(const alink_message_head_t* msg, alink_flow_frame_t* flow_frame)
{
#if ALINK_NEED_BYTE_SWAP
	flow_frame->integration_timespan = alink_msg_flow_frame_get_integration_timespan(msg);
	flow_frame->sonar_timestamp = alink_msg_flow_frame_get_sonar_timestamp(msg);
	flow_frame->pixel_flow_x_integral = alink_msg_flow_frame_get_pixel_flow_x_integral(msg);
	flow_frame->pixel_flow_y_integral = alink_msg_flow_frame_get_pixel_flow_y_integral(msg);
	flow_frame->ground_distance = alink_msg_flow_frame_get_ground_distance(msg);
	flow_frame->quality_x = alink_msg_flow_frame_get_quality_x(msg);
	flow_frame->quality_y = alink_msg_flow_frame_get_quality_y(msg);
#else
	memcpy(flow_frame, _MAV_PAYLOAD(msg), ALINK_MSG_ID_FLOW_FRAME_LEN);
#endif
}
