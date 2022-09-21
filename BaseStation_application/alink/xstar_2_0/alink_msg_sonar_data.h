// MESSAGE SONAR_DATA PACKING

#define ALINK_MSG_ID_SONAR_DATA 161

typedef struct __alink_sonar_data_t
{
 uint32_t timestamp; /*< timestamp (milliseconds since system boot)*/
 uint16_t valid_distance; /*< valid distance in 10E-3 m*/
 uint16_t amplitude; /*< echo amplitude/magtitude*/
 uint16_t precision; /*< echo thresh grade/measurement noise approximation*/
 int16_t state; /*< signal process state*/
} alink_sonar_data_t;

#define ALINK_MSG_ID_SONAR_DATA_LEN 12
#define ALINK_MSG_ID_161_LEN 12

#define ALINK_MSG_ID_SONAR_DATA_CRC 95
#define ALINK_MSG_ID_161_CRC 95



#define ALINK_MESSAGE_INFO_SONAR_DATA { \
	"SONAR_DATA", \
	5, \
	{  { "timestamp", NULL, ALINK_TYPE_UINT32_T, 0, 0, offsetof(alink_sonar_data_t, timestamp) }, \
         { "valid_distance", NULL, ALINK_TYPE_UINT16_T, 0, 4, offsetof(alink_sonar_data_t, valid_distance) }, \
         { "amplitude", NULL, ALINK_TYPE_UINT16_T, 0, 6, offsetof(alink_sonar_data_t, amplitude) }, \
         { "precision", NULL, ALINK_TYPE_UINT16_T, 0, 8, offsetof(alink_sonar_data_t, precision) }, \
         { "state", NULL, ALINK_TYPE_INT16_T, 0, 10, offsetof(alink_sonar_data_t, state) }, \
         } \
}


/**
 * @brief Pack a sonar_data message
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 *
 * @param timestamp timestamp (milliseconds since system boot)
 * @param valid_distance valid distance in 10E-3 m
 * @param amplitude echo amplitude/magtitude
 * @param precision echo thresh grade/measurement noise approximation
 * @param state signal process state
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_sonar_data_pack(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg,
						       uint32_t timestamp, uint16_t valid_distance, uint16_t amplitude, uint16_t precision, int16_t state)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_SONAR_DATA_LEN];
	_mav_put_uint32_t(buf, 0, timestamp);
	_mav_put_uint16_t(buf, 4, valid_distance);
	_mav_put_uint16_t(buf, 6, amplitude);
	_mav_put_uint16_t(buf, 8, precision);
	_mav_put_int16_t(buf, 10, state);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_SONAR_DATA_LEN);
#else
	alink_sonar_data_t packet;
	packet.timestamp = timestamp;
	packet.valid_distance = valid_distance;
	packet.amplitude = amplitude;
	packet.precision = precision;
	packet.state = state;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_SONAR_DATA_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_SONAR_DATA;
#if ALINK_CRC_EXTRA
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_SONAR_DATA_LEN,ALINK_MSG_ID_SONAR_DATA_CRC);
#else
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_SONAR_DATA_LEN);
#endif
}

/**
 * @brief Pack a sonar_data message on a channel
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param timestamp timestamp (milliseconds since system boot)
 * @param valid_distance valid distance in 10E-3 m
 * @param amplitude echo amplitude/magtitude
 * @param precision echo thresh grade/measurement noise approximation
 * @param state signal process state
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_sonar_data_pack_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan,
							   alink_message_head_t* msg,
						           uint32_t timestamp,uint16_t valid_distance,uint16_t amplitude,uint16_t precision,int16_t state)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_SONAR_DATA_LEN];
	_mav_put_uint32_t(buf, 0, timestamp);
	_mav_put_uint16_t(buf, 4, valid_distance);
	_mav_put_uint16_t(buf, 6, amplitude);
	_mav_put_uint16_t(buf, 8, precision);
	_mav_put_int16_t(buf, 10, state);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_SONAR_DATA_LEN);
#else
	alink_sonar_data_t packet;
	packet.timestamp = timestamp;
	packet.valid_distance = valid_distance;
	packet.amplitude = amplitude;
	packet.precision = precision;
	packet.state = state;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_SONAR_DATA_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_SONAR_DATA;
#if ALINK_CRC_EXTRA
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_SONAR_DATA_LEN,ALINK_MSG_ID_SONAR_DATA_CRC);
#else
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_SONAR_DATA_LEN);
#endif
}
/**
 * @brief Encode a sonar_data struct
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 * @param sonar_data C-struct to read the message contents from
 */
static inline uint16_t alink_msg_sonar_data_encode(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg, const alink_sonar_data_t* sonar_data)
{
	return alink_msg_sonar_data_pack(dest_id, source_id, msg, sonar_data->timestamp, sonar_data->valid_distance, sonar_data->amplitude, sonar_data->precision, sonar_data->state);
}

/**
 * @brief Encode a sonar_data struct on a channel
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param sonar_data C-struct to read the message contents from
 */
static inline uint16_t alink_msg_sonar_data_encode_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan, alink_message_head_t* msg, const alink_sonar_data_t* sonar_data)
{
	return alink_msg_sonar_data_pack_chan(dest_id, source_id, chan, msg, sonar_data->timestamp, sonar_data->valid_distance, sonar_data->amplitude, sonar_data->precision, sonar_data->state);
}
// MESSAGE SONAR_DATA UNPACKING


/**
 * @brief Get field timestamp from sonar_data message
 *
 * @return timestamp (milliseconds since system boot)
 */
static inline uint32_t alink_msg_sonar_data_get_timestamp(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field valid_distance from sonar_data message
 *
 * @return valid distance in 10E-3 m
 */
static inline uint16_t alink_msg_sonar_data_get_valid_distance(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  4);
}

/**
 * @brief Get field amplitude from sonar_data message
 *
 * @return echo amplitude/magtitude
 */
static inline uint16_t alink_msg_sonar_data_get_amplitude(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  6);
}

/**
 * @brief Get field precision from sonar_data message
 *
 * @return echo thresh grade/measurement noise approximation
 */
static inline uint16_t alink_msg_sonar_data_get_precision(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  8);
}

/**
 * @brief Get field state from sonar_data message
 *
 * @return signal process state
 */
static inline int16_t alink_msg_sonar_data_get_state(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  10);
}

/**
 * @brief Decode a sonar_data message into a struct
 *
 * @param msg The message to decode
 * @param sonar_data C-struct to decode the message contents into
 */
static inline void alink_msg_sonar_data_decode(const alink_message_head_t* msg, alink_sonar_data_t* sonar_data)
{
#if ALINK_NEED_BYTE_SWAP
	sonar_data->timestamp = alink_msg_sonar_data_get_timestamp(msg);
	sonar_data->valid_distance = alink_msg_sonar_data_get_valid_distance(msg);
	sonar_data->amplitude = alink_msg_sonar_data_get_amplitude(msg);
	sonar_data->precision = alink_msg_sonar_data_get_precision(msg);
	sonar_data->state = alink_msg_sonar_data_get_state(msg);
#else
	memcpy(sonar_data, _MAV_PAYLOAD(msg), ALINK_MSG_ID_SONAR_DATA_LEN);
#endif
}
