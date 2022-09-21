// MESSAGE MOVIDUS_SOA_REPORT PACKING

#define ALINK_MSG_ID_MOVIDUS_SOA_REPORT 113

typedef struct __alink_movidus_soa_report_t
{
 uint64_t timestamp; /*< timestamp (microseconds since system boot)*/
 uint16_t soa_state; /*<  soa_state: emergency stop*/
 uint16_t front_dist[4]; /*<  Front distance of section0,1,2,3 in cm*/
 uint16_t right_dist[4]; /*<  Right distance of section0,1,2,3 in cm*/
 uint16_t back_dist[4]; /*<  Back distance of section0,1,2,3 in cm*/
 uint16_t left_dist[4]; /*<  Left distance of section0,1,2,3 in cm*/
} alink_movidus_soa_report_t;

#define ALINK_MSG_ID_MOVIDUS_SOA_REPORT_LEN 42
#define ALINK_MSG_ID_113_LEN 42

#define ALINK_MSG_ID_MOVIDUS_SOA_REPORT_CRC 60
#define ALINK_MSG_ID_113_CRC 60

#define ALINK_MSG_MOVIDUS_SOA_REPORT_FIELD_FRONT_DIST_LEN 4
#define ALINK_MSG_MOVIDUS_SOA_REPORT_FIELD_RIGHT_DIST_LEN 4
#define ALINK_MSG_MOVIDUS_SOA_REPORT_FIELD_BACK_DIST_LEN 4
#define ALINK_MSG_MOVIDUS_SOA_REPORT_FIELD_LEFT_DIST_LEN 4

#define ALINK_MESSAGE_INFO_MOVIDUS_SOA_REPORT { \
	"MOVIDUS_SOA_REPORT", \
	6, \
	{  { "timestamp", NULL, ALINK_TYPE_UINT64_T, 0, 0, offsetof(alink_movidus_soa_report_t, timestamp) }, \
         { "soa_state", NULL, ALINK_TYPE_UINT16_T, 0, 8, offsetof(alink_movidus_soa_report_t, soa_state) }, \
         { "front_dist", NULL, ALINK_TYPE_UINT16_T, 4, 10, offsetof(alink_movidus_soa_report_t, front_dist) }, \
         { "right_dist", NULL, ALINK_TYPE_UINT16_T, 4, 18, offsetof(alink_movidus_soa_report_t, right_dist) }, \
         { "back_dist", NULL, ALINK_TYPE_UINT16_T, 4, 26, offsetof(alink_movidus_soa_report_t, back_dist) }, \
         { "left_dist", NULL, ALINK_TYPE_UINT16_T, 4, 34, offsetof(alink_movidus_soa_report_t, left_dist) }, \
         } \
}


/**
 * @brief Pack a movidus_soa_report message
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 *
 * @param timestamp timestamp (microseconds since system boot)
 * @param soa_state  soa_state: emergency stop
 * @param front_dist  Front distance of section0,1,2,3 in cm
 * @param right_dist  Right distance of section0,1,2,3 in cm
 * @param back_dist  Back distance of section0,1,2,3 in cm
 * @param left_dist  Left distance of section0,1,2,3 in cm
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_movidus_soa_report_pack(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg,
						       uint64_t timestamp, uint16_t soa_state, const uint16_t *front_dist, const uint16_t *right_dist, const uint16_t *back_dist, const uint16_t *left_dist)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_MOVIDUS_SOA_REPORT_LEN];
	_mav_put_uint64_t(buf, 0, timestamp);
	_mav_put_uint16_t(buf, 8, soa_state);
	_mav_put_uint16_t_array(buf, 10, front_dist, 4);
	_mav_put_uint16_t_array(buf, 18, right_dist, 4);
	_mav_put_uint16_t_array(buf, 26, back_dist, 4);
	_mav_put_uint16_t_array(buf, 34, left_dist, 4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_MOVIDUS_SOA_REPORT_LEN);
#else
	alink_movidus_soa_report_t packet;
	packet.timestamp = timestamp;
	packet.soa_state = soa_state;
	mav_array_memcpy(packet.front_dist, front_dist, sizeof(uint16_t)*4);
	mav_array_memcpy(packet.right_dist, right_dist, sizeof(uint16_t)*4);
	mav_array_memcpy(packet.back_dist, back_dist, sizeof(uint16_t)*4);
	mav_array_memcpy(packet.left_dist, left_dist, sizeof(uint16_t)*4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_MOVIDUS_SOA_REPORT_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_MOVIDUS_SOA_REPORT;
#if ALINK_CRC_EXTRA
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_MOVIDUS_SOA_REPORT_LEN,ALINK_MSG_ID_MOVIDUS_SOA_REPORT_CRC);
#else
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_MOVIDUS_SOA_REPORT_LEN);
#endif
}

/**
 * @brief Pack a movidus_soa_report message on a channel
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param timestamp timestamp (microseconds since system boot)
 * @param soa_state  soa_state: emergency stop
 * @param front_dist  Front distance of section0,1,2,3 in cm
 * @param right_dist  Right distance of section0,1,2,3 in cm
 * @param back_dist  Back distance of section0,1,2,3 in cm
 * @param left_dist  Left distance of section0,1,2,3 in cm
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_movidus_soa_report_pack_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan,
							   alink_message_head_t* msg,
						           uint64_t timestamp,uint16_t soa_state,const uint16_t *front_dist,const uint16_t *right_dist,const uint16_t *back_dist,const uint16_t *left_dist)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_MOVIDUS_SOA_REPORT_LEN];
	_mav_put_uint64_t(buf, 0, timestamp);
	_mav_put_uint16_t(buf, 8, soa_state);
	_mav_put_uint16_t_array(buf, 10, front_dist, 4);
	_mav_put_uint16_t_array(buf, 18, right_dist, 4);
	_mav_put_uint16_t_array(buf, 26, back_dist, 4);
	_mav_put_uint16_t_array(buf, 34, left_dist, 4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_MOVIDUS_SOA_REPORT_LEN);
#else
	alink_movidus_soa_report_t packet;
	packet.timestamp = timestamp;
	packet.soa_state = soa_state;
	mav_array_memcpy(packet.front_dist, front_dist, sizeof(uint16_t)*4);
	mav_array_memcpy(packet.right_dist, right_dist, sizeof(uint16_t)*4);
	mav_array_memcpy(packet.back_dist, back_dist, sizeof(uint16_t)*4);
	mav_array_memcpy(packet.left_dist, left_dist, sizeof(uint16_t)*4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_MOVIDUS_SOA_REPORT_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_MOVIDUS_SOA_REPORT;
#if ALINK_CRC_EXTRA
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_MOVIDUS_SOA_REPORT_LEN,ALINK_MSG_ID_MOVIDUS_SOA_REPORT_CRC);
#else
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_MOVIDUS_SOA_REPORT_LEN);
#endif
}
/**
 * @brief Encode a movidus_soa_report struct
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 * @param movidus_soa_report C-struct to read the message contents from
 */
static inline uint16_t alink_msg_movidus_soa_report_encode(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg, const alink_movidus_soa_report_t* movidus_soa_report)
{
	return alink_msg_movidus_soa_report_pack(dest_id, source_id, msg, movidus_soa_report->timestamp, movidus_soa_report->soa_state, movidus_soa_report->front_dist, movidus_soa_report->right_dist, movidus_soa_report->back_dist, movidus_soa_report->left_dist);
}

/**
 * @brief Encode a movidus_soa_report struct on a channel
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param movidus_soa_report C-struct to read the message contents from
 */
static inline uint16_t alink_msg_movidus_soa_report_encode_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan, alink_message_head_t* msg, const alink_movidus_soa_report_t* movidus_soa_report)
{
	return alink_msg_movidus_soa_report_pack_chan(dest_id, source_id, chan, msg, movidus_soa_report->timestamp, movidus_soa_report->soa_state, movidus_soa_report->front_dist, movidus_soa_report->right_dist, movidus_soa_report->back_dist, movidus_soa_report->left_dist);
}
// MESSAGE MOVIDUS_SOA_REPORT UNPACKING


/**
 * @brief Get field timestamp from movidus_soa_report message
 *
 * @return timestamp (microseconds since system boot)
 */
static inline uint64_t alink_msg_movidus_soa_report_get_timestamp(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field soa_state from movidus_soa_report message
 *
 * @return  soa_state: emergency stop
 */
static inline uint16_t alink_msg_movidus_soa_report_get_soa_state(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  8);
}

/**
 * @brief Get field front_dist from movidus_soa_report message
 *
 * @return  Front distance of section0,1,2,3 in cm
 */
static inline uint16_t alink_msg_movidus_soa_report_get_front_dist(const alink_message_head_t* msg, uint16_t *front_dist)
{
	return _MAV_RETURN_uint16_t_array(msg, front_dist, 4,  10);
}

/**
 * @brief Get field right_dist from movidus_soa_report message
 *
 * @return  Right distance of section0,1,2,3 in cm
 */
static inline uint16_t alink_msg_movidus_soa_report_get_right_dist(const alink_message_head_t* msg, uint16_t *right_dist)
{
	return _MAV_RETURN_uint16_t_array(msg, right_dist, 4,  18);
}

/**
 * @brief Get field back_dist from movidus_soa_report message
 *
 * @return  Back distance of section0,1,2,3 in cm
 */
static inline uint16_t alink_msg_movidus_soa_report_get_back_dist(const alink_message_head_t* msg, uint16_t *back_dist)
{
	return _MAV_RETURN_uint16_t_array(msg, back_dist, 4,  26);
}

/**
 * @brief Get field left_dist from movidus_soa_report message
 *
 * @return  Left distance of section0,1,2,3 in cm
 */
static inline uint16_t alink_msg_movidus_soa_report_get_left_dist(const alink_message_head_t* msg, uint16_t *left_dist)
{
	return _MAV_RETURN_uint16_t_array(msg, left_dist, 4,  34);
}

/**
 * @brief Decode a movidus_soa_report message into a struct
 *
 * @param msg The message to decode
 * @param movidus_soa_report C-struct to decode the message contents into
 */
static inline void alink_msg_movidus_soa_report_decode(const alink_message_head_t* msg, alink_movidus_soa_report_t* movidus_soa_report)
{
#if ALINK_NEED_BYTE_SWAP
	movidus_soa_report->timestamp = alink_msg_movidus_soa_report_get_timestamp(msg);
	movidus_soa_report->soa_state = alink_msg_movidus_soa_report_get_soa_state(msg);
	alink_msg_movidus_soa_report_get_front_dist(msg, movidus_soa_report->front_dist);
	alink_msg_movidus_soa_report_get_right_dist(msg, movidus_soa_report->right_dist);
	alink_msg_movidus_soa_report_get_back_dist(msg, movidus_soa_report->back_dist);
	alink_msg_movidus_soa_report_get_left_dist(msg, movidus_soa_report->left_dist);
#else
	memcpy(movidus_soa_report, _MAV_PAYLOAD(msg), ALINK_MSG_ID_MOVIDUS_SOA_REPORT_LEN);
#endif
}
