// MESSAGE MOVIDUS_HEARTBEAT PACKING

#define ALINK_MSG_ID_MOVIDUS_HEARTBEAT 120

typedef struct __alink_movidus_heartbeat_t
{
 uint32_t alarm_status1; /*< ststem alarm's status 1*/
 uint32_t alarm_status2; /*< ststem alarm's status 2*/
 uint8_t type; /*< Type of the MAV 0: MAV_TYPE_XSTAR2_0*/
 uint8_t vision_mode; /*< Vision mode*/
} alink_movidus_heartbeat_t;

#define ALINK_MSG_ID_MOVIDUS_HEARTBEAT_LEN 10
#define ALINK_MSG_ID_120_LEN 10

#define ALINK_MSG_ID_MOVIDUS_HEARTBEAT_CRC 50
#define ALINK_MSG_ID_120_CRC 50



#define ALINK_MESSAGE_INFO_MOVIDUS_HEARTBEAT { \
	"MOVIDUS_HEARTBEAT", \
	4, \
	{  { "alarm_status1", NULL, ALINK_TYPE_UINT32_T, 0, 0, offsetof(alink_movidus_heartbeat_t, alarm_status1) }, \
         { "alarm_status2", NULL, ALINK_TYPE_UINT32_T, 0, 4, offsetof(alink_movidus_heartbeat_t, alarm_status2) }, \
         { "type", NULL, ALINK_TYPE_UINT8_T, 0, 8, offsetof(alink_movidus_heartbeat_t, type) }, \
         { "vision_mode", NULL, ALINK_TYPE_UINT8_T, 0, 9, offsetof(alink_movidus_heartbeat_t, vision_mode) }, \
         } \
}


/**
 * @brief Pack a movidus_heartbeat message
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 *
 * @param type Type of the MAV 0: MAV_TYPE_XSTAR2_0
 * @param vision_mode Vision mode
 * @param alarm_status1 ststem alarm's status 1
 * @param alarm_status2 ststem alarm's status 2
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_movidus_heartbeat_pack(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg,
						       uint8_t type, uint8_t vision_mode, uint32_t alarm_status1, uint32_t alarm_status2)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_MOVIDUS_HEARTBEAT_LEN];
	_mav_put_uint32_t(buf, 0, alarm_status1);
	_mav_put_uint32_t(buf, 4, alarm_status2);
	_mav_put_uint8_t(buf, 8, type);
	_mav_put_uint8_t(buf, 9, vision_mode);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_MOVIDUS_HEARTBEAT_LEN);
#else
	alink_movidus_heartbeat_t packet;
	packet.alarm_status1 = alarm_status1;
	packet.alarm_status2 = alarm_status2;
	packet.type = type;
	packet.vision_mode = vision_mode;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_MOVIDUS_HEARTBEAT_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_MOVIDUS_HEARTBEAT;
#if ALINK_CRC_EXTRA
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_MOVIDUS_HEARTBEAT_LEN,ALINK_MSG_ID_MOVIDUS_HEARTBEAT_CRC);
#else
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_MOVIDUS_HEARTBEAT_LEN);
#endif
}

/**
 * @brief Pack a movidus_heartbeat message on a channel
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param type Type of the MAV 0: MAV_TYPE_XSTAR2_0
 * @param vision_mode Vision mode
 * @param alarm_status1 ststem alarm's status 1
 * @param alarm_status2 ststem alarm's status 2
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_movidus_heartbeat_pack_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan,
							   alink_message_head_t* msg,
						           uint8_t type,uint8_t vision_mode,uint32_t alarm_status1,uint32_t alarm_status2)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_MOVIDUS_HEARTBEAT_LEN];
	_mav_put_uint32_t(buf, 0, alarm_status1);
	_mav_put_uint32_t(buf, 4, alarm_status2);
	_mav_put_uint8_t(buf, 8, type);
	_mav_put_uint8_t(buf, 9, vision_mode);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_MOVIDUS_HEARTBEAT_LEN);
#else
	alink_movidus_heartbeat_t packet;
	packet.alarm_status1 = alarm_status1;
	packet.alarm_status2 = alarm_status2;
	packet.type = type;
	packet.vision_mode = vision_mode;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_MOVIDUS_HEARTBEAT_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_MOVIDUS_HEARTBEAT;
#if ALINK_CRC_EXTRA
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_MOVIDUS_HEARTBEAT_LEN,ALINK_MSG_ID_MOVIDUS_HEARTBEAT_CRC);
#else
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_MOVIDUS_HEARTBEAT_LEN);
#endif
}
/**
 * @brief Encode a movidus_heartbeat struct
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 * @param movidus_heartbeat C-struct to read the message contents from
 */
static inline uint16_t alink_msg_movidus_heartbeat_encode(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg, const alink_movidus_heartbeat_t* movidus_heartbeat)
{
	return alink_msg_movidus_heartbeat_pack(dest_id, source_id, msg, movidus_heartbeat->type, movidus_heartbeat->vision_mode, movidus_heartbeat->alarm_status1, movidus_heartbeat->alarm_status2);
}

/**
 * @brief Encode a movidus_heartbeat struct on a channel
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param movidus_heartbeat C-struct to read the message contents from
 */
static inline uint16_t alink_msg_movidus_heartbeat_encode_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan, alink_message_head_t* msg, const alink_movidus_heartbeat_t* movidus_heartbeat)
{
	return alink_msg_movidus_heartbeat_pack_chan(dest_id, source_id, chan, msg, movidus_heartbeat->type, movidus_heartbeat->vision_mode, movidus_heartbeat->alarm_status1, movidus_heartbeat->alarm_status2);
}
// MESSAGE MOVIDUS_HEARTBEAT UNPACKING


/**
 * @brief Get field type from movidus_heartbeat message
 *
 * @return Type of the MAV 0: MAV_TYPE_XSTAR2_0
 */
static inline uint8_t alink_msg_movidus_heartbeat_get_type(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  8);
}

/**
 * @brief Get field vision_mode from movidus_heartbeat message
 *
 * @return Vision mode
 */
static inline uint8_t alink_msg_movidus_heartbeat_get_vision_mode(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  9);
}

/**
 * @brief Get field alarm_status1 from movidus_heartbeat message
 *
 * @return ststem alarm's status 1
 */
static inline uint32_t alink_msg_movidus_heartbeat_get_alarm_status1(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field alarm_status2 from movidus_heartbeat message
 *
 * @return ststem alarm's status 2
 */
static inline uint32_t alink_msg_movidus_heartbeat_get_alarm_status2(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint32_t(msg,  4);
}

/**
 * @brief Decode a movidus_heartbeat message into a struct
 *
 * @param msg The message to decode
 * @param movidus_heartbeat C-struct to decode the message contents into
 */
static inline void alink_msg_movidus_heartbeat_decode(const alink_message_head_t* msg, alink_movidus_heartbeat_t* movidus_heartbeat)
{
#if ALINK_NEED_BYTE_SWAP
	movidus_heartbeat->alarm_status1 = alink_msg_movidus_heartbeat_get_alarm_status1(msg);
	movidus_heartbeat->alarm_status2 = alink_msg_movidus_heartbeat_get_alarm_status2(msg);
	movidus_heartbeat->type = alink_msg_movidus_heartbeat_get_type(msg);
	movidus_heartbeat->vision_mode = alink_msg_movidus_heartbeat_get_vision_mode(msg);
#else
	memcpy(movidus_heartbeat, _MAV_PAYLOAD(msg), ALINK_MSG_ID_MOVIDUS_HEARTBEAT_LEN);
#endif
}
