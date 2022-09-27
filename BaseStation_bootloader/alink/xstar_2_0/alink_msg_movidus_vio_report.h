// MESSAGE MOVIDUS_VIO_REPORT PACKING

#define ALINK_MSG_ID_MOVIDUS_VIO_REPORT 112

typedef struct __alink_movidus_vio_report_t
{
 uint32_t timestamp; /*< timestamp (milliseconds since system boot)*/
 int16_t delta_pos[3]; /*<  delta position of X,Y,Z in body frame in 10E-3 meters, Float to int16 scale is 1000*/
 int16_t delta_vel[3]; /*<  delta velocity of X,Y,Z in body frame in 10E-3 m/s, Float to int16 scale is 1000*/
 int16_t delta_q[4]; /*<  delta attitude q0,q1,q2,q3 in quaternion format, Float to int16 scale is 10000*/
 uint8_t confidence; /*<  confidence in [0,1],  float to uint8 scale is 100*/
} alink_movidus_vio_report_t;

#define ALINK_MSG_ID_MOVIDUS_VIO_REPORT_LEN 25
#define ALINK_MSG_ID_112_LEN 25

#define ALINK_MSG_ID_MOVIDUS_VIO_REPORT_CRC 39
#define ALINK_MSG_ID_112_CRC 39

#define ALINK_MSG_MOVIDUS_VIO_REPORT_FIELD_DELTA_POS_LEN 3
#define ALINK_MSG_MOVIDUS_VIO_REPORT_FIELD_DELTA_VEL_LEN 3
#define ALINK_MSG_MOVIDUS_VIO_REPORT_FIELD_DELTA_Q_LEN 4

#define ALINK_MESSAGE_INFO_MOVIDUS_VIO_REPORT { \
	"MOVIDUS_VIO_REPORT", \
	5, \
	{  { "timestamp", NULL, ALINK_TYPE_UINT32_T, 0, 0, offsetof(alink_movidus_vio_report_t, timestamp) }, \
         { "delta_pos", NULL, ALINK_TYPE_INT16_T, 3, 4, offsetof(alink_movidus_vio_report_t, delta_pos) }, \
         { "delta_vel", NULL, ALINK_TYPE_INT16_T, 3, 10, offsetof(alink_movidus_vio_report_t, delta_vel) }, \
         { "delta_q", NULL, ALINK_TYPE_INT16_T, 4, 16, offsetof(alink_movidus_vio_report_t, delta_q) }, \
         { "confidence", NULL, ALINK_TYPE_UINT8_T, 0, 24, offsetof(alink_movidus_vio_report_t, confidence) }, \
         } \
}


/**
 * @brief Pack a movidus_vio_report message
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 *
 * @param timestamp timestamp (milliseconds since system boot)
 * @param delta_pos  delta position of X,Y,Z in body frame in 10E-3 meters, Float to int16 scale is 1000
 * @param delta_vel  delta velocity of X,Y,Z in body frame in 10E-3 m/s, Float to int16 scale is 1000
 * @param delta_q  delta attitude q0,q1,q2,q3 in quaternion format, Float to int16 scale is 10000
 * @param confidence  confidence in [0,1],  float to uint8 scale is 100
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_movidus_vio_report_pack(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg,
						       uint32_t timestamp, const int16_t *delta_pos, const int16_t *delta_vel, const int16_t *delta_q, uint8_t confidence)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_MOVIDUS_VIO_REPORT_LEN];
	_mav_put_uint32_t(buf, 0, timestamp);
	_mav_put_uint8_t(buf, 24, confidence);
	_mav_put_int16_t_array(buf, 4, delta_pos, 3);
	_mav_put_int16_t_array(buf, 10, delta_vel, 3);
	_mav_put_int16_t_array(buf, 16, delta_q, 4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_MOVIDUS_VIO_REPORT_LEN);
#else
	alink_movidus_vio_report_t packet;
	packet.timestamp = timestamp;
	packet.confidence = confidence;
	mav_array_memcpy(packet.delta_pos, delta_pos, sizeof(int16_t)*3);
	mav_array_memcpy(packet.delta_vel, delta_vel, sizeof(int16_t)*3);
	mav_array_memcpy(packet.delta_q, delta_q, sizeof(int16_t)*4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_MOVIDUS_VIO_REPORT_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_MOVIDUS_VIO_REPORT;
#if ALINK_CRC_EXTRA
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_MOVIDUS_VIO_REPORT_LEN,ALINK_MSG_ID_MOVIDUS_VIO_REPORT_CRC);
#else
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_MOVIDUS_VIO_REPORT_LEN);
#endif
}

/**
 * @brief Pack a movidus_vio_report message on a channel
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param timestamp timestamp (milliseconds since system boot)
 * @param delta_pos  delta position of X,Y,Z in body frame in 10E-3 meters, Float to int16 scale is 1000
 * @param delta_vel  delta velocity of X,Y,Z in body frame in 10E-3 m/s, Float to int16 scale is 1000
 * @param delta_q  delta attitude q0,q1,q2,q3 in quaternion format, Float to int16 scale is 10000
 * @param confidence  confidence in [0,1],  float to uint8 scale is 100
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_movidus_vio_report_pack_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan,
							   alink_message_head_t* msg,
						           uint32_t timestamp,const int16_t *delta_pos,const int16_t *delta_vel,const int16_t *delta_q,uint8_t confidence)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_MOVIDUS_VIO_REPORT_LEN];
	_mav_put_uint32_t(buf, 0, timestamp);
	_mav_put_uint8_t(buf, 24, confidence);
	_mav_put_int16_t_array(buf, 4, delta_pos, 3);
	_mav_put_int16_t_array(buf, 10, delta_vel, 3);
	_mav_put_int16_t_array(buf, 16, delta_q, 4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_MOVIDUS_VIO_REPORT_LEN);
#else
	alink_movidus_vio_report_t packet;
	packet.timestamp = timestamp;
	packet.confidence = confidence;
	mav_array_memcpy(packet.delta_pos, delta_pos, sizeof(int16_t)*3);
	mav_array_memcpy(packet.delta_vel, delta_vel, sizeof(int16_t)*3);
	mav_array_memcpy(packet.delta_q, delta_q, sizeof(int16_t)*4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_MOVIDUS_VIO_REPORT_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_MOVIDUS_VIO_REPORT;
#if ALINK_CRC_EXTRA
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_MOVIDUS_VIO_REPORT_LEN,ALINK_MSG_ID_MOVIDUS_VIO_REPORT_CRC);
#else
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_MOVIDUS_VIO_REPORT_LEN);
#endif
}
/**
 * @brief Encode a movidus_vio_report struct
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 * @param movidus_vio_report C-struct to read the message contents from
 */
static inline uint16_t alink_msg_movidus_vio_report_encode(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg, const alink_movidus_vio_report_t* movidus_vio_report)
{
	return alink_msg_movidus_vio_report_pack(dest_id, source_id, msg, movidus_vio_report->timestamp, movidus_vio_report->delta_pos, movidus_vio_report->delta_vel, movidus_vio_report->delta_q, movidus_vio_report->confidence);
}

/**
 * @brief Encode a movidus_vio_report struct on a channel
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param movidus_vio_report C-struct to read the message contents from
 */
static inline uint16_t alink_msg_movidus_vio_report_encode_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan, alink_message_head_t* msg, const alink_movidus_vio_report_t* movidus_vio_report)
{
	return alink_msg_movidus_vio_report_pack_chan(dest_id, source_id, chan, msg, movidus_vio_report->timestamp, movidus_vio_report->delta_pos, movidus_vio_report->delta_vel, movidus_vio_report->delta_q, movidus_vio_report->confidence);
}
// MESSAGE MOVIDUS_VIO_REPORT UNPACKING


/**
 * @brief Get field timestamp from movidus_vio_report message
 *
 * @return timestamp (milliseconds since system boot)
 */
static inline uint32_t alink_msg_movidus_vio_report_get_timestamp(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field delta_pos from movidus_vio_report message
 *
 * @return  delta position of X,Y,Z in body frame in 10E-3 meters, Float to int16 scale is 1000
 */
static inline uint16_t alink_msg_movidus_vio_report_get_delta_pos(const alink_message_head_t* msg, int16_t *delta_pos)
{
	return _MAV_RETURN_int16_t_array(msg, delta_pos, 3,  4);
}

/**
 * @brief Get field delta_vel from movidus_vio_report message
 *
 * @return  delta velocity of X,Y,Z in body frame in 10E-3 m/s, Float to int16 scale is 1000
 */
static inline uint16_t alink_msg_movidus_vio_report_get_delta_vel(const alink_message_head_t* msg, int16_t *delta_vel)
{
	return _MAV_RETURN_int16_t_array(msg, delta_vel, 3,  10);
}

/**
 * @brief Get field delta_q from movidus_vio_report message
 *
 * @return  delta attitude q0,q1,q2,q3 in quaternion format, Float to int16 scale is 10000
 */
static inline uint16_t alink_msg_movidus_vio_report_get_delta_q(const alink_message_head_t* msg, int16_t *delta_q)
{
	return _MAV_RETURN_int16_t_array(msg, delta_q, 4,  16);
}

/**
 * @brief Get field confidence from movidus_vio_report message
 *
 * @return  confidence in [0,1],  float to uint8 scale is 100
 */
static inline uint8_t alink_msg_movidus_vio_report_get_confidence(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  24);
}

/**
 * @brief Decode a movidus_vio_report message into a struct
 *
 * @param msg The message to decode
 * @param movidus_vio_report C-struct to decode the message contents into
 */
static inline void alink_msg_movidus_vio_report_decode(const alink_message_head_t* msg, alink_movidus_vio_report_t* movidus_vio_report)
{
#if ALINK_NEED_BYTE_SWAP
	movidus_vio_report->timestamp = alink_msg_movidus_vio_report_get_timestamp(msg);
	alink_msg_movidus_vio_report_get_delta_pos(msg, movidus_vio_report->delta_pos);
	alink_msg_movidus_vio_report_get_delta_vel(msg, movidus_vio_report->delta_vel);
	alink_msg_movidus_vio_report_get_delta_q(msg, movidus_vio_report->delta_q);
	movidus_vio_report->confidence = alink_msg_movidus_vio_report_get_confidence(msg);
#else
	memcpy(movidus_vio_report, _MAV_PAYLOAD(msg), ALINK_MSG_ID_MOVIDUS_VIO_REPORT_LEN);
#endif
}
