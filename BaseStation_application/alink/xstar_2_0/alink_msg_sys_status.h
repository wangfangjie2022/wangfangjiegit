// MESSAGE SYS_STATUS PACKING

#define ALINK_MSG_ID_SYS_STATUS 1

typedef struct __alink_sys_status_t
{
 uint32_t sensors_status1; /*< Bitmask showing whic on board status of sensors 1*/
 uint32_t sensors_status2; /*< Bitmask showing whic on board status of sensors 2*/
 uint32_t flight_mode; /*< Filght mode*/
 uint32_t alarm_status1; /*< system alram's status 1 */
 uint32_t alarm_status2; /*< system alram's status 2*/
} alink_sys_status_t;

#define ALINK_MSG_ID_SYS_STATUS_LEN 20
#define ALINK_MSG_ID_1_LEN 20

#define ALINK_MSG_ID_SYS_STATUS_CRC 187
#define ALINK_MSG_ID_1_CRC 187



#define ALINK_MESSAGE_INFO_SYS_STATUS { \
	"SYS_STATUS", \
	5, \
	{  { "sensors_status1", "0x%04x", ALINK_TYPE_UINT32_T, 0, 0, offsetof(alink_sys_status_t, sensors_status1) }, \
         { "sensors_status2", "0x%04x", ALINK_TYPE_UINT32_T, 0, 4, offsetof(alink_sys_status_t, sensors_status2) }, \
         { "flight_mode", "0x%04x", ALINK_TYPE_UINT32_T, 0, 8, offsetof(alink_sys_status_t, flight_mode) }, \
         { "alarm_status1", "0x%04x", ALINK_TYPE_UINT32_T, 0, 12, offsetof(alink_sys_status_t, alarm_status1) }, \
         { "alarm_status2", "0x%04x", ALINK_TYPE_UINT32_T, 0, 16, offsetof(alink_sys_status_t, alarm_status2) }, \
         } \
}


/**
 * @brief Pack a sys_status message
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 *
 * @param sensors_status1 Bitmask showing whic on board status of sensors 1
 * @param sensors_status2 Bitmask showing whic on board status of sensors 2
 * @param flight_mode Filght mode
 * @param alarm_status1 system alram's status 1 
 * @param alarm_status2 system alram's status 2
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_sys_status_pack(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg,
						       uint32_t sensors_status1, uint32_t sensors_status2, uint32_t flight_mode, uint32_t alarm_status1, uint32_t alarm_status2)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_SYS_STATUS_LEN];
	_mav_put_uint32_t(buf, 0, sensors_status1);
	_mav_put_uint32_t(buf, 4, sensors_status2);
	_mav_put_uint32_t(buf, 8, flight_mode);
	_mav_put_uint32_t(buf, 12, alarm_status1);
	_mav_put_uint32_t(buf, 16, alarm_status2);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_SYS_STATUS_LEN);
#else
	alink_sys_status_t packet;
	packet.sensors_status1 = sensors_status1;
	packet.sensors_status2 = sensors_status2;
	packet.flight_mode = flight_mode;
	packet.alarm_status1 = alarm_status1;
	packet.alarm_status2 = alarm_status2;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_SYS_STATUS_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_SYS_STATUS;
#if ALINK_CRC_EXTRA
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_SYS_STATUS_LEN,ALINK_MSG_ID_SYS_STATUS_CRC);
#else
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_SYS_STATUS_LEN);
#endif
}

/**
 * @brief Pack a sys_status message on a channel
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param sensors_status1 Bitmask showing whic on board status of sensors 1
 * @param sensors_status2 Bitmask showing whic on board status of sensors 2
 * @param flight_mode Filght mode
 * @param alarm_status1 system alram's status 1 
 * @param alarm_status2 system alram's status 2
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_sys_status_pack_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan,
							   alink_message_head_t* msg,
						           uint32_t sensors_status1,uint32_t sensors_status2,uint32_t flight_mode,uint32_t alarm_status1,uint32_t alarm_status2)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_SYS_STATUS_LEN];
	_mav_put_uint32_t(buf, 0, sensors_status1);
	_mav_put_uint32_t(buf, 4, sensors_status2);
	_mav_put_uint32_t(buf, 8, flight_mode);
	_mav_put_uint32_t(buf, 12, alarm_status1);
	_mav_put_uint32_t(buf, 16, alarm_status2);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_SYS_STATUS_LEN);
#else
	alink_sys_status_t packet;
	packet.sensors_status1 = sensors_status1;
	packet.sensors_status2 = sensors_status2;
	packet.flight_mode = flight_mode;
	packet.alarm_status1 = alarm_status1;
	packet.alarm_status2 = alarm_status2;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_SYS_STATUS_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_SYS_STATUS;
#if ALINK_CRC_EXTRA
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_SYS_STATUS_LEN,ALINK_MSG_ID_SYS_STATUS_CRC);
#else
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_SYS_STATUS_LEN);
#endif
}
/**
 * @brief Encode a sys_status struct
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 * @param sys_status C-struct to read the message contents from
 */
static inline uint16_t alink_msg_sys_status_encode(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg, const alink_sys_status_t* sys_status)
{
	return alink_msg_sys_status_pack(dest_id, source_id, msg, sys_status->sensors_status1, sys_status->sensors_status2, sys_status->flight_mode, sys_status->alarm_status1, sys_status->alarm_status2);
}

/**
 * @brief Encode a sys_status struct on a channel
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param sys_status C-struct to read the message contents from
 */
static inline uint16_t alink_msg_sys_status_encode_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan, alink_message_head_t* msg, const alink_sys_status_t* sys_status)
{
	return alink_msg_sys_status_pack_chan(dest_id, source_id, chan, msg, sys_status->sensors_status1, sys_status->sensors_status2, sys_status->flight_mode, sys_status->alarm_status1, sys_status->alarm_status2);
}
// MESSAGE SYS_STATUS UNPACKING


/**
 * @brief Get field sensors_status1 from sys_status message
 *
 * @return Bitmask showing whic on board status of sensors 1
 */
static inline uint32_t alink_msg_sys_status_get_sensors_status1(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field sensors_status2 from sys_status message
 *
 * @return Bitmask showing whic on board status of sensors 2
 */
static inline uint32_t alink_msg_sys_status_get_sensors_status2(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint32_t(msg,  4);
}

/**
 * @brief Get field flight_mode from sys_status message
 *
 * @return Filght mode
 */
static inline uint32_t alink_msg_sys_status_get_flight_mode(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint32_t(msg,  8);
}

/**
 * @brief Get field alarm_status1 from sys_status message
 *
 * @return system alram's status 1 
 */
static inline uint32_t alink_msg_sys_status_get_alarm_status1(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint32_t(msg,  12);
}

/**
 * @brief Get field alarm_status2 from sys_status message
 *
 * @return system alram's status 2
 */
static inline uint32_t alink_msg_sys_status_get_alarm_status2(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint32_t(msg,  16);
}

/**
 * @brief Decode a sys_status message into a struct
 *
 * @param msg The message to decode
 * @param sys_status C-struct to decode the message contents into
 */
static inline void alink_msg_sys_status_decode(const alink_message_head_t* msg, alink_sys_status_t* sys_status)
{
#if ALINK_NEED_BYTE_SWAP
	sys_status->sensors_status1 = alink_msg_sys_status_get_sensors_status1(msg);
	sys_status->sensors_status2 = alink_msg_sys_status_get_sensors_status2(msg);
	sys_status->flight_mode = alink_msg_sys_status_get_flight_mode(msg);
	sys_status->alarm_status1 = alink_msg_sys_status_get_alarm_status1(msg);
	sys_status->alarm_status2 = alink_msg_sys_status_get_alarm_status2(msg);
#else
	memcpy(sys_status, _MAV_PAYLOAD(msg), ALINK_MSG_ID_SYS_STATUS_LEN);
#endif
}
