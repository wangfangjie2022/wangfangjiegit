// MESSAGE VISION_FLIGHT_STATUS PACKING

#define ALINK_MSG_ID_VISION_FLIGHT_STATUS 72

typedef struct __alink_vision_flight_status_t
{
 uint32_t timestamp; /*< timestamp (milliseconds since system boot)*/
 uint8_t armed; /*< Basic flight status armed*/
 uint8_t ground_condition; /*< Basic flight status ground_condition*/
 uint8_t battery_percentage; /*< Basic flight status battery_warning*/
 uint8_t flight_mode; /*< Basic flight status flight_mode*/
} alink_vision_flight_status_t;

#define ALINK_MSG_ID_VISION_FLIGHT_STATUS_LEN 8
#define ALINK_MSG_ID_72_LEN 8

#define ALINK_MSG_ID_VISION_FLIGHT_STATUS_CRC 137
#define ALINK_MSG_ID_72_CRC 137



#define ALINK_MESSAGE_INFO_VISION_FLIGHT_STATUS { \
	"VISION_FLIGHT_STATUS", \
	5, \
	{  { "timestamp", NULL, ALINK_TYPE_UINT32_T, 0, 0, offsetof(alink_vision_flight_status_t, timestamp) }, \
         { "armed", NULL, ALINK_TYPE_UINT8_T, 0, 4, offsetof(alink_vision_flight_status_t, armed) }, \
         { "ground_condition", NULL, ALINK_TYPE_UINT8_T, 0, 5, offsetof(alink_vision_flight_status_t, ground_condition) }, \
         { "battery_percentage", NULL, ALINK_TYPE_UINT8_T, 0, 6, offsetof(alink_vision_flight_status_t, battery_percentage) }, \
         { "flight_mode", NULL, ALINK_TYPE_UINT8_T, 0, 7, offsetof(alink_vision_flight_status_t, flight_mode) }, \
         } \
}


/**
 * @brief Pack a vision_flight_status message
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 *
 * @param timestamp timestamp (milliseconds since system boot)
 * @param armed Basic flight status armed
 * @param ground_condition Basic flight status ground_condition
 * @param battery_percentage Basic flight status battery_warning
 * @param flight_mode Basic flight status flight_mode
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_vision_flight_status_pack(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg,
						       uint32_t timestamp, uint8_t armed, uint8_t ground_condition, uint8_t battery_percentage, uint8_t flight_mode)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_VISION_FLIGHT_STATUS_LEN];
	_mav_put_uint32_t(buf, 0, timestamp);
	_mav_put_uint8_t(buf, 4, armed);
	_mav_put_uint8_t(buf, 5, ground_condition);
	_mav_put_uint8_t(buf, 6, battery_percentage);
	_mav_put_uint8_t(buf, 7, flight_mode);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_VISION_FLIGHT_STATUS_LEN);
#else
	alink_vision_flight_status_t packet;
	packet.timestamp = timestamp;
	packet.armed = armed;
	packet.ground_condition = ground_condition;
	packet.battery_percentage = battery_percentage;
	packet.flight_mode = flight_mode;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_VISION_FLIGHT_STATUS_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_VISION_FLIGHT_STATUS;
#if ALINK_CRC_EXTRA
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_VISION_FLIGHT_STATUS_LEN,ALINK_MSG_ID_VISION_FLIGHT_STATUS_CRC);
#else
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_VISION_FLIGHT_STATUS_LEN);
#endif
}

/**
 * @brief Pack a vision_flight_status message on a channel
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param timestamp timestamp (milliseconds since system boot)
 * @param armed Basic flight status armed
 * @param ground_condition Basic flight status ground_condition
 * @param battery_percentage Basic flight status battery_warning
 * @param flight_mode Basic flight status flight_mode
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_vision_flight_status_pack_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan,
							   alink_message_head_t* msg,
						           uint32_t timestamp,uint8_t armed,uint8_t ground_condition,uint8_t battery_percentage,uint8_t flight_mode)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_VISION_FLIGHT_STATUS_LEN];
	_mav_put_uint32_t(buf, 0, timestamp);
	_mav_put_uint8_t(buf, 4, armed);
	_mav_put_uint8_t(buf, 5, ground_condition);
	_mav_put_uint8_t(buf, 6, battery_percentage);
	_mav_put_uint8_t(buf, 7, flight_mode);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_VISION_FLIGHT_STATUS_LEN);
#else
	alink_vision_flight_status_t packet;
	packet.timestamp = timestamp;
	packet.armed = armed;
	packet.ground_condition = ground_condition;
	packet.battery_percentage = battery_percentage;
	packet.flight_mode = flight_mode;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_VISION_FLIGHT_STATUS_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_VISION_FLIGHT_STATUS;
#if ALINK_CRC_EXTRA
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_VISION_FLIGHT_STATUS_LEN,ALINK_MSG_ID_VISION_FLIGHT_STATUS_CRC);
#else
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_VISION_FLIGHT_STATUS_LEN);
#endif
}
/**
 * @brief Encode a vision_flight_status struct
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 * @param vision_flight_status C-struct to read the message contents from
 */
static inline uint16_t alink_msg_vision_flight_status_encode(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg, const alink_vision_flight_status_t* vision_flight_status)
{
	return alink_msg_vision_flight_status_pack(dest_id, source_id, msg, vision_flight_status->timestamp, vision_flight_status->armed, vision_flight_status->ground_condition, vision_flight_status->battery_percentage, vision_flight_status->flight_mode);
}

/**
 * @brief Encode a vision_flight_status struct on a channel
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param vision_flight_status C-struct to read the message contents from
 */
static inline uint16_t alink_msg_vision_flight_status_encode_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan, alink_message_head_t* msg, const alink_vision_flight_status_t* vision_flight_status)
{
	return alink_msg_vision_flight_status_pack_chan(dest_id, source_id, chan, msg, vision_flight_status->timestamp, vision_flight_status->armed, vision_flight_status->ground_condition, vision_flight_status->battery_percentage, vision_flight_status->flight_mode);
}
// MESSAGE VISION_FLIGHT_STATUS UNPACKING


/**
 * @brief Get field timestamp from vision_flight_status message
 *
 * @return timestamp (milliseconds since system boot)
 */
static inline uint32_t alink_msg_vision_flight_status_get_timestamp(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field armed from vision_flight_status message
 *
 * @return Basic flight status armed
 */
static inline uint8_t alink_msg_vision_flight_status_get_armed(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  4);
}

/**
 * @brief Get field ground_condition from vision_flight_status message
 *
 * @return Basic flight status ground_condition
 */
static inline uint8_t alink_msg_vision_flight_status_get_ground_condition(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  5);
}

/**
 * @brief Get field battery_percentage from vision_flight_status message
 *
 * @return Basic flight status battery_warning
 */
static inline uint8_t alink_msg_vision_flight_status_get_battery_percentage(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  6);
}

/**
 * @brief Get field flight_mode from vision_flight_status message
 *
 * @return Basic flight status flight_mode
 */
static inline uint8_t alink_msg_vision_flight_status_get_flight_mode(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  7);
}

/**
 * @brief Decode a vision_flight_status message into a struct
 *
 * @param msg The message to decode
 * @param vision_flight_status C-struct to decode the message contents into
 */
static inline void alink_msg_vision_flight_status_decode(const alink_message_head_t* msg, alink_vision_flight_status_t* vision_flight_status)
{
#if ALINK_NEED_BYTE_SWAP
	vision_flight_status->timestamp = alink_msg_vision_flight_status_get_timestamp(msg);
	vision_flight_status->armed = alink_msg_vision_flight_status_get_armed(msg);
	vision_flight_status->ground_condition = alink_msg_vision_flight_status_get_ground_condition(msg);
	vision_flight_status->battery_percentage = alink_msg_vision_flight_status_get_battery_percentage(msg);
	vision_flight_status->flight_mode = alink_msg_vision_flight_status_get_flight_mode(msg);
#else
	memcpy(vision_flight_status, _MAV_PAYLOAD(msg), ALINK_MSG_ID_VISION_FLIGHT_STATUS_LEN);
#endif
}
