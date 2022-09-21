// MESSAGE RAW_ACTUATOR_INFO PACKING

#define ALINK_MSG_ID_RAW_ACTUATOR_INFO 22

typedef struct __alink_raw_actuator_info_t
{
 uint64_t timestamp; /*< timestamp (microseconds since UNIX epoch or microseconds since system boot)*/
 uint32_t status[8]; /*< Status for actuators*/
 int16_t tilt_angle[8]; /*< The tilt's angle in rad*/
 uint16_t tilt_vol[8]; /*< The tilt's volatile in mv*/
 uint16_t esc_rpm[8]; /*< The esc's rpm*/
 uint16_t esc_vol[8]; /*< The esc's volatile in mv*/
 int16_t esc_cur[8]; /*< The esc's current in ma*/
 int16_t temperature[8]; /*< The temperature in degree*/
} alink_raw_actuator_info_t;

#define ALINK_MSG_ID_RAW_ACTUATOR_INFO_LEN 136
#define ALINK_MSG_ID_22_LEN 136

#define ALINK_MSG_ID_RAW_ACTUATOR_INFO_CRC 59
#define ALINK_MSG_ID_22_CRC 59

#define ALINK_MSG_RAW_ACTUATOR_INFO_FIELD_STATUS_LEN 8
#define ALINK_MSG_RAW_ACTUATOR_INFO_FIELD_TILT_ANGLE_LEN 8
#define ALINK_MSG_RAW_ACTUATOR_INFO_FIELD_TILT_VOL_LEN 8
#define ALINK_MSG_RAW_ACTUATOR_INFO_FIELD_ESC_RPM_LEN 8
#define ALINK_MSG_RAW_ACTUATOR_INFO_FIELD_ESC_VOL_LEN 8
#define ALINK_MSG_RAW_ACTUATOR_INFO_FIELD_ESC_CUR_LEN 8
#define ALINK_MSG_RAW_ACTUATOR_INFO_FIELD_TEMPERATURE_LEN 8

#define ALINK_MESSAGE_INFO_RAW_ACTUATOR_INFO { \
	"RAW_ACTUATOR_INFO", \
	8, \
	{  { "timestamp", NULL, ALINK_TYPE_UINT64_T, 0, 0, offsetof(alink_raw_actuator_info_t, timestamp) }, \
         { "status", NULL, ALINK_TYPE_UINT32_T, 8, 8, offsetof(alink_raw_actuator_info_t, status) }, \
         { "tilt_angle", NULL, ALINK_TYPE_INT16_T, 8, 40, offsetof(alink_raw_actuator_info_t, tilt_angle) }, \
         { "tilt_vol", NULL, ALINK_TYPE_UINT16_T, 8, 56, offsetof(alink_raw_actuator_info_t, tilt_vol) }, \
         { "esc_rpm", NULL, ALINK_TYPE_UINT16_T, 8, 72, offsetof(alink_raw_actuator_info_t, esc_rpm) }, \
         { "esc_vol", NULL, ALINK_TYPE_UINT16_T, 8, 88, offsetof(alink_raw_actuator_info_t, esc_vol) }, \
         { "esc_cur", NULL, ALINK_TYPE_INT16_T, 8, 104, offsetof(alink_raw_actuator_info_t, esc_cur) }, \
         { "temperature", NULL, ALINK_TYPE_INT16_T, 8, 120, offsetof(alink_raw_actuator_info_t, temperature) }, \
         } \
}


/**
 * @brief Pack a raw_actuator_info message
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 *
 * @param timestamp timestamp (microseconds since UNIX epoch or microseconds since system boot)
 * @param status Status for actuators
 * @param tilt_angle The tilt's angle in rad
 * @param tilt_vol The tilt's volatile in mv
 * @param esc_rpm The esc's rpm
 * @param esc_vol The esc's volatile in mv
 * @param esc_cur The esc's current in ma
 * @param temperature The temperature in degree
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_raw_actuator_info_pack(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg,
						       uint64_t timestamp, const uint32_t *status, const int16_t *tilt_angle, const uint16_t *tilt_vol, const uint16_t *esc_rpm, const uint16_t *esc_vol, const int16_t *esc_cur, const int16_t *temperature)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_RAW_ACTUATOR_INFO_LEN];
	_mav_put_uint64_t(buf, 0, timestamp);
	_mav_put_uint32_t_array(buf, 8, status, 8);
	_mav_put_int16_t_array(buf, 40, tilt_angle, 8);
	_mav_put_uint16_t_array(buf, 56, tilt_vol, 8);
	_mav_put_uint16_t_array(buf, 72, esc_rpm, 8);
	_mav_put_uint16_t_array(buf, 88, esc_vol, 8);
	_mav_put_int16_t_array(buf, 104, esc_cur, 8);
	_mav_put_int16_t_array(buf, 120, temperature, 8);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_RAW_ACTUATOR_INFO_LEN);
#else
	alink_raw_actuator_info_t packet;
	packet.timestamp = timestamp;
	mav_array_memcpy(packet.status, status, sizeof(uint32_t)*8);
	mav_array_memcpy(packet.tilt_angle, tilt_angle, sizeof(int16_t)*8);
	mav_array_memcpy(packet.tilt_vol, tilt_vol, sizeof(uint16_t)*8);
	mav_array_memcpy(packet.esc_rpm, esc_rpm, sizeof(uint16_t)*8);
	mav_array_memcpy(packet.esc_vol, esc_vol, sizeof(uint16_t)*8);
	mav_array_memcpy(packet.esc_cur, esc_cur, sizeof(int16_t)*8);
	mav_array_memcpy(packet.temperature, temperature, sizeof(int16_t)*8);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_RAW_ACTUATOR_INFO_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_RAW_ACTUATOR_INFO;
#if ALINK_CRC_EXTRA
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_RAW_ACTUATOR_INFO_LEN,ALINK_MSG_ID_RAW_ACTUATOR_INFO_CRC);
#else
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_RAW_ACTUATOR_INFO_LEN);
#endif
}

/**
 * @brief Pack a raw_actuator_info message on a channel
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param timestamp timestamp (microseconds since UNIX epoch or microseconds since system boot)
 * @param status Status for actuators
 * @param tilt_angle The tilt's angle in rad
 * @param tilt_vol The tilt's volatile in mv
 * @param esc_rpm The esc's rpm
 * @param esc_vol The esc's volatile in mv
 * @param esc_cur The esc's current in ma
 * @param temperature The temperature in degree
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_raw_actuator_info_pack_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan,
							   alink_message_head_t* msg,
						           uint64_t timestamp,const uint32_t *status,const int16_t *tilt_angle,const uint16_t *tilt_vol,const uint16_t *esc_rpm,const uint16_t *esc_vol,const int16_t *esc_cur,const int16_t *temperature)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_RAW_ACTUATOR_INFO_LEN];
	_mav_put_uint64_t(buf, 0, timestamp);
	_mav_put_uint32_t_array(buf, 8, status, 8);
	_mav_put_int16_t_array(buf, 40, tilt_angle, 8);
	_mav_put_uint16_t_array(buf, 56, tilt_vol, 8);
	_mav_put_uint16_t_array(buf, 72, esc_rpm, 8);
	_mav_put_uint16_t_array(buf, 88, esc_vol, 8);
	_mav_put_int16_t_array(buf, 104, esc_cur, 8);
	_mav_put_int16_t_array(buf, 120, temperature, 8);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_RAW_ACTUATOR_INFO_LEN);
#else
	alink_raw_actuator_info_t packet;
	packet.timestamp = timestamp;
	mav_array_memcpy(packet.status, status, sizeof(uint32_t)*8);
	mav_array_memcpy(packet.tilt_angle, tilt_angle, sizeof(int16_t)*8);
	mav_array_memcpy(packet.tilt_vol, tilt_vol, sizeof(uint16_t)*8);
	mav_array_memcpy(packet.esc_rpm, esc_rpm, sizeof(uint16_t)*8);
	mav_array_memcpy(packet.esc_vol, esc_vol, sizeof(uint16_t)*8);
	mav_array_memcpy(packet.esc_cur, esc_cur, sizeof(int16_t)*8);
	mav_array_memcpy(packet.temperature, temperature, sizeof(int16_t)*8);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_RAW_ACTUATOR_INFO_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_RAW_ACTUATOR_INFO;
#if ALINK_CRC_EXTRA
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_RAW_ACTUATOR_INFO_LEN,ALINK_MSG_ID_RAW_ACTUATOR_INFO_CRC);
#else
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_RAW_ACTUATOR_INFO_LEN);
#endif
}
/**
 * @brief Encode a raw_actuator_info struct
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 * @param raw_actuator_info C-struct to read the message contents from
 */
static inline uint16_t alink_msg_raw_actuator_info_encode(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg, const alink_raw_actuator_info_t* raw_actuator_info)
{
	return alink_msg_raw_actuator_info_pack(dest_id, source_id, msg, raw_actuator_info->timestamp, raw_actuator_info->status, raw_actuator_info->tilt_angle, raw_actuator_info->tilt_vol, raw_actuator_info->esc_rpm, raw_actuator_info->esc_vol, raw_actuator_info->esc_cur, raw_actuator_info->temperature);
}

/**
 * @brief Encode a raw_actuator_info struct on a channel
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param raw_actuator_info C-struct to read the message contents from
 */
static inline uint16_t alink_msg_raw_actuator_info_encode_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan, alink_message_head_t* msg, const alink_raw_actuator_info_t* raw_actuator_info)
{
	return alink_msg_raw_actuator_info_pack_chan(dest_id, source_id, chan, msg, raw_actuator_info->timestamp, raw_actuator_info->status, raw_actuator_info->tilt_angle, raw_actuator_info->tilt_vol, raw_actuator_info->esc_rpm, raw_actuator_info->esc_vol, raw_actuator_info->esc_cur, raw_actuator_info->temperature);
}
// MESSAGE RAW_ACTUATOR_INFO UNPACKING


/**
 * @brief Get field timestamp from raw_actuator_info message
 *
 * @return timestamp (microseconds since UNIX epoch or microseconds since system boot)
 */
static inline uint64_t alink_msg_raw_actuator_info_get_timestamp(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field status from raw_actuator_info message
 *
 * @return Status for actuators
 */
static inline uint16_t alink_msg_raw_actuator_info_get_status(const alink_message_head_t* msg, uint32_t *status)
{
	return _MAV_RETURN_uint32_t_array(msg, status, 8,  8);
}

/**
 * @brief Get field tilt_angle from raw_actuator_info message
 *
 * @return The tilt's angle in rad
 */
static inline uint16_t alink_msg_raw_actuator_info_get_tilt_angle(const alink_message_head_t* msg, int16_t *tilt_angle)
{
	return _MAV_RETURN_int16_t_array(msg, tilt_angle, 8,  40);
}

/**
 * @brief Get field tilt_vol from raw_actuator_info message
 *
 * @return The tilt's volatile in mv
 */
static inline uint16_t alink_msg_raw_actuator_info_get_tilt_vol(const alink_message_head_t* msg, uint16_t *tilt_vol)
{
	return _MAV_RETURN_uint16_t_array(msg, tilt_vol, 8,  56);
}

/**
 * @brief Get field esc_rpm from raw_actuator_info message
 *
 * @return The esc's rpm
 */
static inline uint16_t alink_msg_raw_actuator_info_get_esc_rpm(const alink_message_head_t* msg, uint16_t *esc_rpm)
{
	return _MAV_RETURN_uint16_t_array(msg, esc_rpm, 8,  72);
}

/**
 * @brief Get field esc_vol from raw_actuator_info message
 *
 * @return The esc's volatile in mv
 */
static inline uint16_t alink_msg_raw_actuator_info_get_esc_vol(const alink_message_head_t* msg, uint16_t *esc_vol)
{
	return _MAV_RETURN_uint16_t_array(msg, esc_vol, 8,  88);
}

/**
 * @brief Get field esc_cur from raw_actuator_info message
 *
 * @return The esc's current in ma
 */
static inline uint16_t alink_msg_raw_actuator_info_get_esc_cur(const alink_message_head_t* msg, int16_t *esc_cur)
{
	return _MAV_RETURN_int16_t_array(msg, esc_cur, 8,  104);
}

/**
 * @brief Get field temperature from raw_actuator_info message
 *
 * @return The temperature in degree
 */
static inline uint16_t alink_msg_raw_actuator_info_get_temperature(const alink_message_head_t* msg, int16_t *temperature)
{
	return _MAV_RETURN_int16_t_array(msg, temperature, 8,  120);
}

/**
 * @brief Decode a raw_actuator_info message into a struct
 *
 * @param msg The message to decode
 * @param raw_actuator_info C-struct to decode the message contents into
 */
static inline void alink_msg_raw_actuator_info_decode(const alink_message_head_t* msg, alink_raw_actuator_info_t* raw_actuator_info)
{
#if ALINK_NEED_BYTE_SWAP
	raw_actuator_info->timestamp = alink_msg_raw_actuator_info_get_timestamp(msg);
	alink_msg_raw_actuator_info_get_status(msg, raw_actuator_info->status);
	alink_msg_raw_actuator_info_get_tilt_angle(msg, raw_actuator_info->tilt_angle);
	alink_msg_raw_actuator_info_get_tilt_vol(msg, raw_actuator_info->tilt_vol);
	alink_msg_raw_actuator_info_get_esc_rpm(msg, raw_actuator_info->esc_rpm);
	alink_msg_raw_actuator_info_get_esc_vol(msg, raw_actuator_info->esc_vol);
	alink_msg_raw_actuator_info_get_esc_cur(msg, raw_actuator_info->esc_cur);
	alink_msg_raw_actuator_info_get_temperature(msg, raw_actuator_info->temperature);
#else
	memcpy(raw_actuator_info, _MAV_PAYLOAD(msg), ALINK_MSG_ID_RAW_ACTUATOR_INFO_LEN);
#endif
}
