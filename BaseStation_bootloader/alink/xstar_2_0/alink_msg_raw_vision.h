// MESSAGE RAW_VISION PACKING

#define ALINK_MSG_ID_RAW_VISION 30

typedef struct __alink_raw_vision_t
{
 float Timestamp_ms; /*< Timestamp (microseconds since UNIX epoch or microseconds since system boot)*/
 uint32_t timestamp_v; /*< timestamp for vision*/
 uint32_t timestamp_s; /*< timestamp for sonar*/
 int16_t delta_pos_x; /*< delta position x location*/
 int16_t delta_pos_y; /*< delta position y location*/
 int16_t delta_pos_z; /*< delta position z location*/
 int16_t vel_x; /*< velocity x*/
 int16_t vel_y; /*< velocity y*/
 int16_t vel_z; /*< velocity z*/
 int16_t delta_q0; /*< quatention 0*/
 int16_t delta_q1; /*< quatention 1*/
 int16_t delta_q2; /*< quatention 2*/
 int16_t delta_q3; /*< quatention 3*/
 uint16_t ground_distance_mm; /*< ground distance (mm)*/
 uint8_t confidence; /*< confidence*/
} alink_raw_vision_t;

#define ALINK_MSG_ID_RAW_VISION_LEN 35
#define ALINK_MSG_ID_30_LEN 35

#define ALINK_MSG_ID_RAW_VISION_CRC 42
#define ALINK_MSG_ID_30_CRC 42



#define ALINK_MESSAGE_INFO_RAW_VISION { \
	"RAW_VISION", \
	15, \
	{  { "Timestamp_ms", NULL, ALINK_TYPE_FLOAT, 0, 0, offsetof(alink_raw_vision_t, Timestamp_ms) }, \
         { "timestamp_v", NULL, ALINK_TYPE_UINT32_T, 0, 4, offsetof(alink_raw_vision_t, timestamp_v) }, \
         { "timestamp_s", NULL, ALINK_TYPE_UINT32_T, 0, 8, offsetof(alink_raw_vision_t, timestamp_s) }, \
         { "delta_pos_x", NULL, ALINK_TYPE_INT16_T, 0, 12, offsetof(alink_raw_vision_t, delta_pos_x) }, \
         { "delta_pos_y", NULL, ALINK_TYPE_INT16_T, 0, 14, offsetof(alink_raw_vision_t, delta_pos_y) }, \
         { "delta_pos_z", NULL, ALINK_TYPE_INT16_T, 0, 16, offsetof(alink_raw_vision_t, delta_pos_z) }, \
         { "vel_x", NULL, ALINK_TYPE_INT16_T, 0, 18, offsetof(alink_raw_vision_t, vel_x) }, \
         { "vel_y", NULL, ALINK_TYPE_INT16_T, 0, 20, offsetof(alink_raw_vision_t, vel_y) }, \
         { "vel_z", NULL, ALINK_TYPE_INT16_T, 0, 22, offsetof(alink_raw_vision_t, vel_z) }, \
         { "delta_q0", NULL, ALINK_TYPE_INT16_T, 0, 24, offsetof(alink_raw_vision_t, delta_q0) }, \
         { "delta_q1", NULL, ALINK_TYPE_INT16_T, 0, 26, offsetof(alink_raw_vision_t, delta_q1) }, \
         { "delta_q2", NULL, ALINK_TYPE_INT16_T, 0, 28, offsetof(alink_raw_vision_t, delta_q2) }, \
         { "delta_q3", NULL, ALINK_TYPE_INT16_T, 0, 30, offsetof(alink_raw_vision_t, delta_q3) }, \
         { "ground_distance_mm", NULL, ALINK_TYPE_UINT16_T, 0, 32, offsetof(alink_raw_vision_t, ground_distance_mm) }, \
         { "confidence", NULL, ALINK_TYPE_UINT8_T, 0, 34, offsetof(alink_raw_vision_t, confidence) }, \
         } \
}


/**
 * @brief Pack a raw_vision message
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 *
 * @param Timestamp_ms Timestamp (microseconds since UNIX epoch or microseconds since system boot)
 * @param delta_pos_x delta position x location
 * @param delta_pos_y delta position y location
 * @param delta_pos_z delta position z location
 * @param vel_x velocity x
 * @param vel_y velocity y
 * @param vel_z velocity z
 * @param delta_q0 quatention 0
 * @param delta_q1 quatention 1
 * @param delta_q2 quatention 2
 * @param delta_q3 quatention 3
 * @param confidence confidence
 * @param timestamp_v timestamp for vision
 * @param ground_distance_mm ground distance (mm)
 * @param timestamp_s timestamp for sonar
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_raw_vision_pack(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg,
						       float Timestamp_ms, int16_t delta_pos_x, int16_t delta_pos_y, int16_t delta_pos_z, int16_t vel_x, int16_t vel_y, int16_t vel_z, int16_t delta_q0, int16_t delta_q1, int16_t delta_q2, int16_t delta_q3, uint8_t confidence, uint32_t timestamp_v, uint16_t ground_distance_mm, uint32_t timestamp_s)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_RAW_VISION_LEN];
	_mav_put_float(buf, 0, Timestamp_ms);
	_mav_put_uint32_t(buf, 4, timestamp_v);
	_mav_put_uint32_t(buf, 8, timestamp_s);
	_mav_put_int16_t(buf, 12, delta_pos_x);
	_mav_put_int16_t(buf, 14, delta_pos_y);
	_mav_put_int16_t(buf, 16, delta_pos_z);
	_mav_put_int16_t(buf, 18, vel_x);
	_mav_put_int16_t(buf, 20, vel_y);
	_mav_put_int16_t(buf, 22, vel_z);
	_mav_put_int16_t(buf, 24, delta_q0);
	_mav_put_int16_t(buf, 26, delta_q1);
	_mav_put_int16_t(buf, 28, delta_q2);
	_mav_put_int16_t(buf, 30, delta_q3);
	_mav_put_uint16_t(buf, 32, ground_distance_mm);
	_mav_put_uint8_t(buf, 34, confidence);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_RAW_VISION_LEN);
#else
	alink_raw_vision_t packet;
	packet.Timestamp_ms = Timestamp_ms;
	packet.timestamp_v = timestamp_v;
	packet.timestamp_s = timestamp_s;
	packet.delta_pos_x = delta_pos_x;
	packet.delta_pos_y = delta_pos_y;
	packet.delta_pos_z = delta_pos_z;
	packet.vel_x = vel_x;
	packet.vel_y = vel_y;
	packet.vel_z = vel_z;
	packet.delta_q0 = delta_q0;
	packet.delta_q1 = delta_q1;
	packet.delta_q2 = delta_q2;
	packet.delta_q3 = delta_q3;
	packet.ground_distance_mm = ground_distance_mm;
	packet.confidence = confidence;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_RAW_VISION_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_RAW_VISION;
#if ALINK_CRC_EXTRA
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_RAW_VISION_LEN,ALINK_MSG_ID_RAW_VISION_CRC);
#else
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_RAW_VISION_LEN);
#endif
}

/**
 * @brief Pack a raw_vision message on a channel
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param Timestamp_ms Timestamp (microseconds since UNIX epoch or microseconds since system boot)
 * @param delta_pos_x delta position x location
 * @param delta_pos_y delta position y location
 * @param delta_pos_z delta position z location
 * @param vel_x velocity x
 * @param vel_y velocity y
 * @param vel_z velocity z
 * @param delta_q0 quatention 0
 * @param delta_q1 quatention 1
 * @param delta_q2 quatention 2
 * @param delta_q3 quatention 3
 * @param confidence confidence
 * @param timestamp_v timestamp for vision
 * @param ground_distance_mm ground distance (mm)
 * @param timestamp_s timestamp for sonar
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_raw_vision_pack_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan,
							   alink_message_head_t* msg,
						           float Timestamp_ms,int16_t delta_pos_x,int16_t delta_pos_y,int16_t delta_pos_z,int16_t vel_x,int16_t vel_y,int16_t vel_z,int16_t delta_q0,int16_t delta_q1,int16_t delta_q2,int16_t delta_q3,uint8_t confidence,uint32_t timestamp_v,uint16_t ground_distance_mm,uint32_t timestamp_s)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_RAW_VISION_LEN];
	_mav_put_float(buf, 0, Timestamp_ms);
	_mav_put_uint32_t(buf, 4, timestamp_v);
	_mav_put_uint32_t(buf, 8, timestamp_s);
	_mav_put_int16_t(buf, 12, delta_pos_x);
	_mav_put_int16_t(buf, 14, delta_pos_y);
	_mav_put_int16_t(buf, 16, delta_pos_z);
	_mav_put_int16_t(buf, 18, vel_x);
	_mav_put_int16_t(buf, 20, vel_y);
	_mav_put_int16_t(buf, 22, vel_z);
	_mav_put_int16_t(buf, 24, delta_q0);
	_mav_put_int16_t(buf, 26, delta_q1);
	_mav_put_int16_t(buf, 28, delta_q2);
	_mav_put_int16_t(buf, 30, delta_q3);
	_mav_put_uint16_t(buf, 32, ground_distance_mm);
	_mav_put_uint8_t(buf, 34, confidence);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_RAW_VISION_LEN);
#else
	alink_raw_vision_t packet;
	packet.Timestamp_ms = Timestamp_ms;
	packet.timestamp_v = timestamp_v;
	packet.timestamp_s = timestamp_s;
	packet.delta_pos_x = delta_pos_x;
	packet.delta_pos_y = delta_pos_y;
	packet.delta_pos_z = delta_pos_z;
	packet.vel_x = vel_x;
	packet.vel_y = vel_y;
	packet.vel_z = vel_z;
	packet.delta_q0 = delta_q0;
	packet.delta_q1 = delta_q1;
	packet.delta_q2 = delta_q2;
	packet.delta_q3 = delta_q3;
	packet.ground_distance_mm = ground_distance_mm;
	packet.confidence = confidence;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_RAW_VISION_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_RAW_VISION;
#if ALINK_CRC_EXTRA
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_RAW_VISION_LEN,ALINK_MSG_ID_RAW_VISION_CRC);
#else
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_RAW_VISION_LEN);
#endif
}
/**
 * @brief Encode a raw_vision struct
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 * @param raw_vision C-struct to read the message contents from
 */
static inline uint16_t alink_msg_raw_vision_encode(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg, const alink_raw_vision_t* raw_vision)
{
	return alink_msg_raw_vision_pack(dest_id, source_id, msg, raw_vision->Timestamp_ms, raw_vision->delta_pos_x, raw_vision->delta_pos_y, raw_vision->delta_pos_z, raw_vision->vel_x, raw_vision->vel_y, raw_vision->vel_z, raw_vision->delta_q0, raw_vision->delta_q1, raw_vision->delta_q2, raw_vision->delta_q3, raw_vision->confidence, raw_vision->timestamp_v, raw_vision->ground_distance_mm, raw_vision->timestamp_s);
}

/**
 * @brief Encode a raw_vision struct on a channel
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param raw_vision C-struct to read the message contents from
 */
static inline uint16_t alink_msg_raw_vision_encode_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan, alink_message_head_t* msg, const alink_raw_vision_t* raw_vision)
{
	return alink_msg_raw_vision_pack_chan(dest_id, source_id, chan, msg, raw_vision->Timestamp_ms, raw_vision->delta_pos_x, raw_vision->delta_pos_y, raw_vision->delta_pos_z, raw_vision->vel_x, raw_vision->vel_y, raw_vision->vel_z, raw_vision->delta_q0, raw_vision->delta_q1, raw_vision->delta_q2, raw_vision->delta_q3, raw_vision->confidence, raw_vision->timestamp_v, raw_vision->ground_distance_mm, raw_vision->timestamp_s);
}
// MESSAGE RAW_VISION UNPACKING


/**
 * @brief Get field Timestamp_ms from raw_vision message
 *
 * @return Timestamp (microseconds since UNIX epoch or microseconds since system boot)
 */
static inline float alink_msg_raw_vision_get_Timestamp_ms(const alink_message_head_t* msg)
{
	return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field delta_pos_x from raw_vision message
 *
 * @return delta position x location
 */
static inline int16_t alink_msg_raw_vision_get_delta_pos_x(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  12);
}

/**
 * @brief Get field delta_pos_y from raw_vision message
 *
 * @return delta position y location
 */
static inline int16_t alink_msg_raw_vision_get_delta_pos_y(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  14);
}

/**
 * @brief Get field delta_pos_z from raw_vision message
 *
 * @return delta position z location
 */
static inline int16_t alink_msg_raw_vision_get_delta_pos_z(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  16);
}

/**
 * @brief Get field vel_x from raw_vision message
 *
 * @return velocity x
 */
static inline int16_t alink_msg_raw_vision_get_vel_x(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  18);
}

/**
 * @brief Get field vel_y from raw_vision message
 *
 * @return velocity y
 */
static inline int16_t alink_msg_raw_vision_get_vel_y(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  20);
}

/**
 * @brief Get field vel_z from raw_vision message
 *
 * @return velocity z
 */
static inline int16_t alink_msg_raw_vision_get_vel_z(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  22);
}

/**
 * @brief Get field delta_q0 from raw_vision message
 *
 * @return quatention 0
 */
static inline int16_t alink_msg_raw_vision_get_delta_q0(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  24);
}

/**
 * @brief Get field delta_q1 from raw_vision message
 *
 * @return quatention 1
 */
static inline int16_t alink_msg_raw_vision_get_delta_q1(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  26);
}

/**
 * @brief Get field delta_q2 from raw_vision message
 *
 * @return quatention 2
 */
static inline int16_t alink_msg_raw_vision_get_delta_q2(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  28);
}

/**
 * @brief Get field delta_q3 from raw_vision message
 *
 * @return quatention 3
 */
static inline int16_t alink_msg_raw_vision_get_delta_q3(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  30);
}

/**
 * @brief Get field confidence from raw_vision message
 *
 * @return confidence
 */
static inline uint8_t alink_msg_raw_vision_get_confidence(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  34);
}

/**
 * @brief Get field timestamp_v from raw_vision message
 *
 * @return timestamp for vision
 */
static inline uint32_t alink_msg_raw_vision_get_timestamp_v(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint32_t(msg,  4);
}

/**
 * @brief Get field ground_distance_mm from raw_vision message
 *
 * @return ground distance (mm)
 */
static inline uint16_t alink_msg_raw_vision_get_ground_distance_mm(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  32);
}

/**
 * @brief Get field timestamp_s from raw_vision message
 *
 * @return timestamp for sonar
 */
static inline uint32_t alink_msg_raw_vision_get_timestamp_s(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint32_t(msg,  8);
}

/**
 * @brief Decode a raw_vision message into a struct
 *
 * @param msg The message to decode
 * @param raw_vision C-struct to decode the message contents into
 */
static inline void alink_msg_raw_vision_decode(const alink_message_head_t* msg, alink_raw_vision_t* raw_vision)
{
#if ALINK_NEED_BYTE_SWAP
	raw_vision->Timestamp_ms = alink_msg_raw_vision_get_Timestamp_ms(msg);
	raw_vision->timestamp_v = alink_msg_raw_vision_get_timestamp_v(msg);
	raw_vision->timestamp_s = alink_msg_raw_vision_get_timestamp_s(msg);
	raw_vision->delta_pos_x = alink_msg_raw_vision_get_delta_pos_x(msg);
	raw_vision->delta_pos_y = alink_msg_raw_vision_get_delta_pos_y(msg);
	raw_vision->delta_pos_z = alink_msg_raw_vision_get_delta_pos_z(msg);
	raw_vision->vel_x = alink_msg_raw_vision_get_vel_x(msg);
	raw_vision->vel_y = alink_msg_raw_vision_get_vel_y(msg);
	raw_vision->vel_z = alink_msg_raw_vision_get_vel_z(msg);
	raw_vision->delta_q0 = alink_msg_raw_vision_get_delta_q0(msg);
	raw_vision->delta_q1 = alink_msg_raw_vision_get_delta_q1(msg);
	raw_vision->delta_q2 = alink_msg_raw_vision_get_delta_q2(msg);
	raw_vision->delta_q3 = alink_msg_raw_vision_get_delta_q3(msg);
	raw_vision->ground_distance_mm = alink_msg_raw_vision_get_ground_distance_mm(msg);
	raw_vision->confidence = alink_msg_raw_vision_get_confidence(msg);
#else
	memcpy(raw_vision, _MAV_PAYLOAD(msg), ALINK_MSG_ID_RAW_VISION_LEN);
#endif
}
