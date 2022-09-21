// MESSAGE HEARTBEAT PACKING

#define ALINK_MSG_ID_HEARTBEAT 0

typedef struct __alink_heartbeat_t
{
 uint32_t alarm_status1; /*< ststem alarm's status 1*/
 uint32_t alarm_status2; /*< ststem alarm's status 2*/
 uint32_t alarm_status3; /*< ststem alarm's status 3*/
 uint32_t alarm_status4; /*< ststem alarm's status 4*/
 uint8_t type; /*< Type of the MAV 0: MAV_TYPE_XSTAR2_0*/
 uint8_t flight_mode; /*< Flight mode*/
} alink_heartbeat_t;

#define ALINK_MSG_ID_HEARTBEAT_LEN 18
#define ALINK_MSG_ID_0_LEN 18

#define ALINK_MSG_ID_HEARTBEAT_CRC 104
#define ALINK_MSG_ID_0_CRC 104



#define ALINK_MESSAGE_INFO_HEARTBEAT { \
	"HEARTBEAT", \
	6, \
	{  { "alarm_status1", NULL, ALINK_TYPE_UINT32_T, 0, 0, offsetof(alink_heartbeat_t, alarm_status1) }, \
         { "alarm_status2", NULL, ALINK_TYPE_UINT32_T, 0, 4, offsetof(alink_heartbeat_t, alarm_status2) }, \
         { "alarm_status3", NULL, ALINK_TYPE_UINT32_T, 0, 8, offsetof(alink_heartbeat_t, alarm_status3) }, \
         { "alarm_status4", NULL, ALINK_TYPE_UINT32_T, 0, 12, offsetof(alink_heartbeat_t, alarm_status4) }, \
         { "type", NULL, ALINK_TYPE_UINT8_T, 0, 16, offsetof(alink_heartbeat_t, type) }, \
         { "flight_mode", NULL, ALINK_TYPE_UINT8_T, 0, 17, offsetof(alink_heartbeat_t, flight_mode) }, \
         } \
}


/**
 * @brief Pack a heartbeat message
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 *
 * @param type Type of the MAV 0: MAV_TYPE_XSTAR2_0
 * @param flight_mode Flight mode
 * @param alarm_status1 ststem alarm's status 1
 * @param alarm_status2 ststem alarm's status 2
 * @param alarm_status3 ststem alarm's status 3
 * @param alarm_status4 ststem alarm's status 4
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_heartbeat_pack(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg,
						       uint8_t type, uint8_t flight_mode, uint32_t alarm_status1, uint32_t alarm_status2, uint32_t alarm_status3, uint32_t alarm_status4)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_HEARTBEAT_LEN];
	_mav_put_uint32_t(buf, 0, alarm_status1);
	_mav_put_uint32_t(buf, 4, alarm_status2);
	_mav_put_uint32_t(buf, 8, alarm_status3);
	_mav_put_uint32_t(buf, 12, alarm_status4);
	_mav_put_uint8_t(buf, 16, type);
	_mav_put_uint8_t(buf, 17, flight_mode);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_HEARTBEAT_LEN);
#else
	alink_heartbeat_t packet;
	packet.alarm_status1 = alarm_status1;
	packet.alarm_status2 = alarm_status2;
	packet.alarm_status3 = alarm_status3;
	packet.alarm_status4 = alarm_status4;
	packet.type = type;
	packet.flight_mode = flight_mode;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_HEARTBEAT_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_HEARTBEAT;
#if ALINK_CRC_EXTRA
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_HEARTBEAT_LEN,ALINK_MSG_ID_HEARTBEAT_CRC);
#else
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_HEARTBEAT_LEN);
#endif
}

/**
 * @brief Pack a heartbeat message on a channel
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param type Type of the MAV 0: MAV_TYPE_XSTAR2_0
 * @param flight_mode Flight mode
 * @param alarm_status1 ststem alarm's status 1
 * @param alarm_status2 ststem alarm's status 2
 * @param alarm_status3 ststem alarm's status 3
 * @param alarm_status4 ststem alarm's status 4
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_heartbeat_pack_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan,
							   alink_message_head_t* msg,
						           uint8_t type,uint8_t flight_mode,uint32_t alarm_status1,uint32_t alarm_status2,uint32_t alarm_status3,uint32_t alarm_status4)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_HEARTBEAT_LEN];
	_mav_put_uint32_t(buf, 0, alarm_status1);
	_mav_put_uint32_t(buf, 4, alarm_status2);
	_mav_put_uint32_t(buf, 8, alarm_status3);
	_mav_put_uint32_t(buf, 12, alarm_status4);
	_mav_put_uint8_t(buf, 16, type);
	_mav_put_uint8_t(buf, 17, flight_mode);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_HEARTBEAT_LEN);
#else
	alink_heartbeat_t packet;
	packet.alarm_status1 = alarm_status1;
	packet.alarm_status2 = alarm_status2;
	packet.alarm_status3 = alarm_status3;
	packet.alarm_status4 = alarm_status4;
	packet.type = type;
	packet.flight_mode = flight_mode;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_HEARTBEAT_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_HEARTBEAT;
#if ALINK_CRC_EXTRA
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_HEARTBEAT_LEN,ALINK_MSG_ID_HEARTBEAT_CRC);
#else
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_HEARTBEAT_LEN);
#endif
}
/**
 * @brief Encode a heartbeat struct
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 * @param heartbeat C-struct to read the message contents from
 */
static inline uint16_t alink_msg_heartbeat_encode(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg, const alink_heartbeat_t* heartbeat)
{
	return alink_msg_heartbeat_pack(dest_id, source_id, msg, heartbeat->type, heartbeat->flight_mode, heartbeat->alarm_status1, heartbeat->alarm_status2, heartbeat->alarm_status3, heartbeat->alarm_status4);
}

/**
 * @brief Encode a heartbeat struct on a channel
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param heartbeat C-struct to read the message contents from
 */
static inline uint16_t alink_msg_heartbeat_encode_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan, alink_message_head_t* msg, const alink_heartbeat_t* heartbeat)
{
	return alink_msg_heartbeat_pack_chan(dest_id, source_id, chan, msg, heartbeat->type, heartbeat->flight_mode, heartbeat->alarm_status1, heartbeat->alarm_status2, heartbeat->alarm_status3, heartbeat->alarm_status4);
}
// MESSAGE HEARTBEAT UNPACKING


/**
 * @brief Get field type from heartbeat message
 *
 * @return Type of the MAV 0: MAV_TYPE_XSTAR2_0
 */
static inline uint8_t alink_msg_heartbeat_get_type(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  16);
}

/**
 * @brief Get field flight_mode from heartbeat message
 *
 * @return Flight mode
 */
static inline uint8_t alink_msg_heartbeat_get_flight_mode(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  17);
}

/**
 * @brief Get field alarm_status1 from heartbeat message
 *
 * @return ststem alarm's status 1
 */
static inline uint32_t alink_msg_heartbeat_get_alarm_status1(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field alarm_status2 from heartbeat message
 *
 * @return ststem alarm's status 2
 */
static inline uint32_t alink_msg_heartbeat_get_alarm_status2(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint32_t(msg,  4);
}

/**
 * @brief Get field alarm_status3 from heartbeat message
 *
 * @return ststem alarm's status 3
 */
static inline uint32_t alink_msg_heartbeat_get_alarm_status3(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint32_t(msg,  8);
}

/**
 * @brief Get field alarm_status4 from heartbeat message
 *
 * @return ststem alarm's status 4
 */
static inline uint32_t alink_msg_heartbeat_get_alarm_status4(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint32_t(msg,  12);
}

/**
 * @brief Decode a heartbeat message into a struct
 *
 * @param msg The message to decode
 * @param heartbeat C-struct to decode the message contents into
 */
static inline void alink_msg_heartbeat_decode(const alink_message_head_t* msg, alink_heartbeat_t* heartbeat)
{
#if ALINK_NEED_BYTE_SWAP
	heartbeat->alarm_status1 = alink_msg_heartbeat_get_alarm_status1(msg);
	heartbeat->alarm_status2 = alink_msg_heartbeat_get_alarm_status2(msg);
	heartbeat->alarm_status3 = alink_msg_heartbeat_get_alarm_status3(msg);
	heartbeat->alarm_status4 = alink_msg_heartbeat_get_alarm_status4(msg);
	heartbeat->type = alink_msg_heartbeat_get_type(msg);
	heartbeat->flight_mode = alink_msg_heartbeat_get_flight_mode(msg);
#else
	memcpy(heartbeat, _MAV_PAYLOAD(msg), ALINK_MSG_ID_HEARTBEAT_LEN);
#endif
}
