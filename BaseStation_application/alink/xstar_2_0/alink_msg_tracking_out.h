// MESSAGE TRACKING_OUT PACKING

#define ALINK_MSG_ID_TRACKING_OUT 96

typedef struct __alink_tracking_out_t
{
 uint64_t timestamp; /*< timestamp (milliseconds since system boot)*/
 float dist1; /*< distance estimation by ywseo s paper*/
 float dist2; /*< smoothed value of dist1*/
 float dist3; /*< distance estimation by similar triangle*/
 float dist4; /*< smoothed value of dist3*/
 int16_t u; /*< pixel coordinate x*/
 int16_t v; /*< pixel coordinate y*/
 int16_t w; /*< width of bounding box of the target*/
 int16_t h; /*< height of bounding box of the target*/
 int16_t status; /*< signal word*/
 int16_t width; /*< image resolution ratio width*/
 int16_t height; /*< image resolution ratio height*/
 int16_t reserve; /*< reserve*/
} alink_tracking_out_t;

#define ALINK_MSG_ID_TRACKING_OUT_LEN 40
#define ALINK_MSG_ID_96_LEN 40

#define ALINK_MSG_ID_TRACKING_OUT_CRC 51
#define ALINK_MSG_ID_96_CRC 51



#define ALINK_MESSAGE_INFO_TRACKING_OUT { \
	"TRACKING_OUT", \
	13, \
	{  { "timestamp", NULL, ALINK_TYPE_UINT64_T, 0, 0, offsetof(alink_tracking_out_t, timestamp) }, \
         { "dist1", NULL, ALINK_TYPE_FLOAT, 0, 8, offsetof(alink_tracking_out_t, dist1) }, \
         { "dist2", NULL, ALINK_TYPE_FLOAT, 0, 12, offsetof(alink_tracking_out_t, dist2) }, \
         { "dist3", NULL, ALINK_TYPE_FLOAT, 0, 16, offsetof(alink_tracking_out_t, dist3) }, \
         { "dist4", NULL, ALINK_TYPE_FLOAT, 0, 20, offsetof(alink_tracking_out_t, dist4) }, \
         { "u", NULL, ALINK_TYPE_INT16_T, 0, 24, offsetof(alink_tracking_out_t, u) }, \
         { "v", NULL, ALINK_TYPE_INT16_T, 0, 26, offsetof(alink_tracking_out_t, v) }, \
         { "w", NULL, ALINK_TYPE_INT16_T, 0, 28, offsetof(alink_tracking_out_t, w) }, \
         { "h", NULL, ALINK_TYPE_INT16_T, 0, 30, offsetof(alink_tracking_out_t, h) }, \
         { "status", NULL, ALINK_TYPE_INT16_T, 0, 32, offsetof(alink_tracking_out_t, status) }, \
         { "width", NULL, ALINK_TYPE_INT16_T, 0, 34, offsetof(alink_tracking_out_t, width) }, \
         { "height", NULL, ALINK_TYPE_INT16_T, 0, 36, offsetof(alink_tracking_out_t, height) }, \
         { "reserve", NULL, ALINK_TYPE_INT16_T, 0, 38, offsetof(alink_tracking_out_t, reserve) }, \
         } \
}


/**
 * @brief Pack a tracking_out message
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 *
 * @param timestamp timestamp (milliseconds since system boot)
 * @param u pixel coordinate x
 * @param v pixel coordinate y
 * @param w width of bounding box of the target
 * @param h height of bounding box of the target
 * @param status signal word
 * @param width image resolution ratio width
 * @param height image resolution ratio height
 * @param reserve reserve
 * @param dist1 distance estimation by ywseo s paper
 * @param dist2 smoothed value of dist1
 * @param dist3 distance estimation by similar triangle
 * @param dist4 smoothed value of dist3
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_tracking_out_pack(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg,
						       uint64_t timestamp, int16_t u, int16_t v, int16_t w, int16_t h, int16_t status, int16_t width, int16_t height, int16_t reserve, float dist1, float dist2, float dist3, float dist4)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_TRACKING_OUT_LEN];
	_mav_put_uint64_t(buf, 0, timestamp);
	_mav_put_float(buf, 8, dist1);
	_mav_put_float(buf, 12, dist2);
	_mav_put_float(buf, 16, dist3);
	_mav_put_float(buf, 20, dist4);
	_mav_put_int16_t(buf, 24, u);
	_mav_put_int16_t(buf, 26, v);
	_mav_put_int16_t(buf, 28, w);
	_mav_put_int16_t(buf, 30, h);
	_mav_put_int16_t(buf, 32, status);
	_mav_put_int16_t(buf, 34, width);
	_mav_put_int16_t(buf, 36, height);
	_mav_put_int16_t(buf, 38, reserve);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_TRACKING_OUT_LEN);
#else
	alink_tracking_out_t packet;
	packet.timestamp = timestamp;
	packet.dist1 = dist1;
	packet.dist2 = dist2;
	packet.dist3 = dist3;
	packet.dist4 = dist4;
	packet.u = u;
	packet.v = v;
	packet.w = w;
	packet.h = h;
	packet.status = status;
	packet.width = width;
	packet.height = height;
	packet.reserve = reserve;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_TRACKING_OUT_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_TRACKING_OUT;
#if ALINK_CRC_EXTRA
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_TRACKING_OUT_LEN,ALINK_MSG_ID_TRACKING_OUT_CRC);
#else
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_TRACKING_OUT_LEN);
#endif
}

/**
 * @brief Pack a tracking_out message on a channel
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param timestamp timestamp (milliseconds since system boot)
 * @param u pixel coordinate x
 * @param v pixel coordinate y
 * @param w width of bounding box of the target
 * @param h height of bounding box of the target
 * @param status signal word
 * @param width image resolution ratio width
 * @param height image resolution ratio height
 * @param reserve reserve
 * @param dist1 distance estimation by ywseo s paper
 * @param dist2 smoothed value of dist1
 * @param dist3 distance estimation by similar triangle
 * @param dist4 smoothed value of dist3
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_tracking_out_pack_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan,
							   alink_message_head_t* msg,
						           uint64_t timestamp,int16_t u,int16_t v,int16_t w,int16_t h,int16_t status,int16_t width,int16_t height,int16_t reserve,float dist1,float dist2,float dist3,float dist4)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_TRACKING_OUT_LEN];
	_mav_put_uint64_t(buf, 0, timestamp);
	_mav_put_float(buf, 8, dist1);
	_mav_put_float(buf, 12, dist2);
	_mav_put_float(buf, 16, dist3);
	_mav_put_float(buf, 20, dist4);
	_mav_put_int16_t(buf, 24, u);
	_mav_put_int16_t(buf, 26, v);
	_mav_put_int16_t(buf, 28, w);
	_mav_put_int16_t(buf, 30, h);
	_mav_put_int16_t(buf, 32, status);
	_mav_put_int16_t(buf, 34, width);
	_mav_put_int16_t(buf, 36, height);
	_mav_put_int16_t(buf, 38, reserve);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_TRACKING_OUT_LEN);
#else
	alink_tracking_out_t packet;
	packet.timestamp = timestamp;
	packet.dist1 = dist1;
	packet.dist2 = dist2;
	packet.dist3 = dist3;
	packet.dist4 = dist4;
	packet.u = u;
	packet.v = v;
	packet.w = w;
	packet.h = h;
	packet.status = status;
	packet.width = width;
	packet.height = height;
	packet.reserve = reserve;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_TRACKING_OUT_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_TRACKING_OUT;
#if ALINK_CRC_EXTRA
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_TRACKING_OUT_LEN,ALINK_MSG_ID_TRACKING_OUT_CRC);
#else
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_TRACKING_OUT_LEN);
#endif
}
/**
 * @brief Encode a tracking_out struct
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 * @param tracking_out C-struct to read the message contents from
 */
static inline uint16_t alink_msg_tracking_out_encode(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg, const alink_tracking_out_t* tracking_out)
{
	return alink_msg_tracking_out_pack(dest_id, source_id, msg, tracking_out->timestamp, tracking_out->u, tracking_out->v, tracking_out->w, tracking_out->h, tracking_out->status, tracking_out->width, tracking_out->height, tracking_out->reserve, tracking_out->dist1, tracking_out->dist2, tracking_out->dist3, tracking_out->dist4);
}

/**
 * @brief Encode a tracking_out struct on a channel
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param tracking_out C-struct to read the message contents from
 */
static inline uint16_t alink_msg_tracking_out_encode_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan, alink_message_head_t* msg, const alink_tracking_out_t* tracking_out)
{
	return alink_msg_tracking_out_pack_chan(dest_id, source_id, chan, msg, tracking_out->timestamp, tracking_out->u, tracking_out->v, tracking_out->w, tracking_out->h, tracking_out->status, tracking_out->width, tracking_out->height, tracking_out->reserve, tracking_out->dist1, tracking_out->dist2, tracking_out->dist3, tracking_out->dist4);
}
// MESSAGE TRACKING_OUT UNPACKING


/**
 * @brief Get field timestamp from tracking_out message
 *
 * @return timestamp (milliseconds since system boot)
 */
static inline uint64_t alink_msg_tracking_out_get_timestamp(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field u from tracking_out message
 *
 * @return pixel coordinate x
 */
static inline int16_t alink_msg_tracking_out_get_u(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  24);
}

/**
 * @brief Get field v from tracking_out message
 *
 * @return pixel coordinate y
 */
static inline int16_t alink_msg_tracking_out_get_v(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  26);
}

/**
 * @brief Get field w from tracking_out message
 *
 * @return width of bounding box of the target
 */
static inline int16_t alink_msg_tracking_out_get_w(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  28);
}

/**
 * @brief Get field h from tracking_out message
 *
 * @return height of bounding box of the target
 */
static inline int16_t alink_msg_tracking_out_get_h(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  30);
}

/**
 * @brief Get field status from tracking_out message
 *
 * @return signal word
 */
static inline int16_t alink_msg_tracking_out_get_status(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  32);
}

/**
 * @brief Get field width from tracking_out message
 *
 * @return image resolution ratio width
 */
static inline int16_t alink_msg_tracking_out_get_width(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  34);
}

/**
 * @brief Get field height from tracking_out message
 *
 * @return image resolution ratio height
 */
static inline int16_t alink_msg_tracking_out_get_height(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  36);
}

/**
 * @brief Get field reserve from tracking_out message
 *
 * @return reserve
 */
static inline int16_t alink_msg_tracking_out_get_reserve(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  38);
}

/**
 * @brief Get field dist1 from tracking_out message
 *
 * @return distance estimation by ywseo s paper
 */
static inline float alink_msg_tracking_out_get_dist1(const alink_message_head_t* msg)
{
	return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field dist2 from tracking_out message
 *
 * @return smoothed value of dist1
 */
static inline float alink_msg_tracking_out_get_dist2(const alink_message_head_t* msg)
{
	return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field dist3 from tracking_out message
 *
 * @return distance estimation by similar triangle
 */
static inline float alink_msg_tracking_out_get_dist3(const alink_message_head_t* msg)
{
	return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Get field dist4 from tracking_out message
 *
 * @return smoothed value of dist3
 */
static inline float alink_msg_tracking_out_get_dist4(const alink_message_head_t* msg)
{
	return _MAV_RETURN_float(msg,  20);
}

/**
 * @brief Decode a tracking_out message into a struct
 *
 * @param msg The message to decode
 * @param tracking_out C-struct to decode the message contents into
 */
static inline void alink_msg_tracking_out_decode(const alink_message_head_t* msg, alink_tracking_out_t* tracking_out)
{
#if ALINK_NEED_BYTE_SWAP
	tracking_out->timestamp = alink_msg_tracking_out_get_timestamp(msg);
	tracking_out->dist1 = alink_msg_tracking_out_get_dist1(msg);
	tracking_out->dist2 = alink_msg_tracking_out_get_dist2(msg);
	tracking_out->dist3 = alink_msg_tracking_out_get_dist3(msg);
	tracking_out->dist4 = alink_msg_tracking_out_get_dist4(msg);
	tracking_out->u = alink_msg_tracking_out_get_u(msg);
	tracking_out->v = alink_msg_tracking_out_get_v(msg);
	tracking_out->w = alink_msg_tracking_out_get_w(msg);
	tracking_out->h = alink_msg_tracking_out_get_h(msg);
	tracking_out->status = alink_msg_tracking_out_get_status(msg);
	tracking_out->width = alink_msg_tracking_out_get_width(msg);
	tracking_out->height = alink_msg_tracking_out_get_height(msg);
	tracking_out->reserve = alink_msg_tracking_out_get_reserve(msg);
#else
	memcpy(tracking_out, _MAV_PAYLOAD(msg), ALINK_MSG_ID_TRACKING_OUT_LEN);
#endif
}
