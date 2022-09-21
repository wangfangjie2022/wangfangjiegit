// MESSAGE RAW_OF PACKING

#define ALINK_MSG_ID_RAW_OF 31

typedef struct __alink_raw_of_t
{
 uint64_t timestamp; /*< timestamp (microseconds since UNIX epoch or microseconds since system boot)*/
 float timespan; /*< accumulation timespan in microseconds*/
 float x; /*< accumulated optical flow in radians around x axis*/
 float y; /*< accumulated optical flow in radians around y axis*/
 float dh; /*< Altitude / distance to ground in meters*/
 float radar; /*< distance to front*/
 uint8_t quality; /*< Average of quality of accumulated frames, 0: bad quality, 255: maximum quality*/
} alink_raw_of_t;

#define ALINK_MSG_ID_RAW_OF_LEN 29
#define ALINK_MSG_ID_31_LEN 29

#define ALINK_MSG_ID_RAW_OF_CRC 107
#define ALINK_MSG_ID_31_CRC 107



#define ALINK_MESSAGE_INFO_RAW_OF { \
	"RAW_OF", \
	7, \
	{  { "timestamp", NULL, ALINK_TYPE_UINT64_T, 0, 0, offsetof(alink_raw_of_t, timestamp) }, \
         { "timespan", NULL, ALINK_TYPE_FLOAT, 0, 8, offsetof(alink_raw_of_t, timespan) }, \
         { "x", NULL, ALINK_TYPE_FLOAT, 0, 12, offsetof(alink_raw_of_t, x) }, \
         { "y", NULL, ALINK_TYPE_FLOAT, 0, 16, offsetof(alink_raw_of_t, y) }, \
         { "dh", NULL, ALINK_TYPE_FLOAT, 0, 20, offsetof(alink_raw_of_t, dh) }, \
         { "radar", NULL, ALINK_TYPE_FLOAT, 0, 24, offsetof(alink_raw_of_t, radar) }, \
         { "quality", NULL, ALINK_TYPE_UINT8_T, 0, 28, offsetof(alink_raw_of_t, quality) }, \
         } \
}


/**
 * @brief Pack a raw_of message
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 *
 * @param timestamp timestamp (microseconds since UNIX epoch or microseconds since system boot)
 * @param timespan accumulation timespan in microseconds
 * @param x accumulated optical flow in radians around x axis
 * @param y accumulated optical flow in radians around y axis
 * @param quality Average of quality of accumulated frames, 0: bad quality, 255: maximum quality
 * @param dh Altitude / distance to ground in meters
 * @param radar distance to front
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_raw_of_pack(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg,
						       uint64_t timestamp, float timespan, float x, float y, uint8_t quality, float dh, float radar)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_RAW_OF_LEN];
	_mav_put_uint64_t(buf, 0, timestamp);
	_mav_put_float(buf, 8, timespan);
	_mav_put_float(buf, 12, x);
	_mav_put_float(buf, 16, y);
	_mav_put_float(buf, 20, dh);
	_mav_put_float(buf, 24, radar);
	_mav_put_uint8_t(buf, 28, quality);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_RAW_OF_LEN);
#else
	alink_raw_of_t packet;
	packet.timestamp = timestamp;
	packet.timespan = timespan;
	packet.x = x;
	packet.y = y;
	packet.dh = dh;
	packet.radar = radar;
	packet.quality = quality;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_RAW_OF_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_RAW_OF;
#if ALINK_CRC_EXTRA
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_RAW_OF_LEN,ALINK_MSG_ID_RAW_OF_CRC);
#else
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_RAW_OF_LEN);
#endif
}

/**
 * @brief Pack a raw_of message on a channel
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param timestamp timestamp (microseconds since UNIX epoch or microseconds since system boot)
 * @param timespan accumulation timespan in microseconds
 * @param x accumulated optical flow in radians around x axis
 * @param y accumulated optical flow in radians around y axis
 * @param quality Average of quality of accumulated frames, 0: bad quality, 255: maximum quality
 * @param dh Altitude / distance to ground in meters
 * @param radar distance to front
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_raw_of_pack_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan,
							   alink_message_head_t* msg,
						           uint64_t timestamp,float timespan,float x,float y,uint8_t quality,float dh,float radar)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_RAW_OF_LEN];
	_mav_put_uint64_t(buf, 0, timestamp);
	_mav_put_float(buf, 8, timespan);
	_mav_put_float(buf, 12, x);
	_mav_put_float(buf, 16, y);
	_mav_put_float(buf, 20, dh);
	_mav_put_float(buf, 24, radar);
	_mav_put_uint8_t(buf, 28, quality);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_RAW_OF_LEN);
#else
	alink_raw_of_t packet;
	packet.timestamp = timestamp;
	packet.timespan = timespan;
	packet.x = x;
	packet.y = y;
	packet.dh = dh;
	packet.radar = radar;
	packet.quality = quality;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_RAW_OF_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_RAW_OF;
#if ALINK_CRC_EXTRA
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_RAW_OF_LEN,ALINK_MSG_ID_RAW_OF_CRC);
#else
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_RAW_OF_LEN);
#endif
}
/**
 * @brief Encode a raw_of struct
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 * @param raw_of C-struct to read the message contents from
 */
static inline uint16_t alink_msg_raw_of_encode(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg, const alink_raw_of_t* raw_of)
{
	return alink_msg_raw_of_pack(dest_id, source_id, msg, raw_of->timestamp, raw_of->timespan, raw_of->x, raw_of->y, raw_of->quality, raw_of->dh, raw_of->radar);
}

/**
 * @brief Encode a raw_of struct on a channel
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param raw_of C-struct to read the message contents from
 */
static inline uint16_t alink_msg_raw_of_encode_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan, alink_message_head_t* msg, const alink_raw_of_t* raw_of)
{
	return alink_msg_raw_of_pack_chan(dest_id, source_id, chan, msg, raw_of->timestamp, raw_of->timespan, raw_of->x, raw_of->y, raw_of->quality, raw_of->dh, raw_of->radar);
}
// MESSAGE RAW_OF UNPACKING


/**
 * @brief Get field timestamp from raw_of message
 *
 * @return timestamp (microseconds since UNIX epoch or microseconds since system boot)
 */
static inline uint64_t alink_msg_raw_of_get_timestamp(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field timespan from raw_of message
 *
 * @return accumulation timespan in microseconds
 */
static inline float alink_msg_raw_of_get_timespan(const alink_message_head_t* msg)
{
	return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field x from raw_of message
 *
 * @return accumulated optical flow in radians around x axis
 */
static inline float alink_msg_raw_of_get_x(const alink_message_head_t* msg)
{
	return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field y from raw_of message
 *
 * @return accumulated optical flow in radians around y axis
 */
static inline float alink_msg_raw_of_get_y(const alink_message_head_t* msg)
{
	return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Get field quality from raw_of message
 *
 * @return Average of quality of accumulated frames, 0: bad quality, 255: maximum quality
 */
static inline uint8_t alink_msg_raw_of_get_quality(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  28);
}

/**
 * @brief Get field dh from raw_of message
 *
 * @return Altitude / distance to ground in meters
 */
static inline float alink_msg_raw_of_get_dh(const alink_message_head_t* msg)
{
	return _MAV_RETURN_float(msg,  20);
}

/**
 * @brief Get field radar from raw_of message
 *
 * @return distance to front
 */
static inline float alink_msg_raw_of_get_radar(const alink_message_head_t* msg)
{
	return _MAV_RETURN_float(msg,  24);
}

/**
 * @brief Decode a raw_of message into a struct
 *
 * @param msg The message to decode
 * @param raw_of C-struct to decode the message contents into
 */
static inline void alink_msg_raw_of_decode(const alink_message_head_t* msg, alink_raw_of_t* raw_of)
{
#if ALINK_NEED_BYTE_SWAP
	raw_of->timestamp = alink_msg_raw_of_get_timestamp(msg);
	raw_of->timespan = alink_msg_raw_of_get_timespan(msg);
	raw_of->x = alink_msg_raw_of_get_x(msg);
	raw_of->y = alink_msg_raw_of_get_y(msg);
	raw_of->dh = alink_msg_raw_of_get_dh(msg);
	raw_of->radar = alink_msg_raw_of_get_radar(msg);
	raw_of->quality = alink_msg_raw_of_get_quality(msg);
#else
	memcpy(raw_of, _MAV_PAYLOAD(msg), ALINK_MSG_ID_RAW_OF_LEN);
#endif
}
