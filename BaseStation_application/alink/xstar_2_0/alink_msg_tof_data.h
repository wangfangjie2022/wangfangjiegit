// MESSAGE TOF_DATA PACKING

#define ALINK_MSG_ID_TOF_DATA 162

typedef struct __alink_tof_data_t
{
 uint32_t timestamp; /*< timestamp (milliseconds since system boot)*/
 uint16_t distance[8]; /*< distances of the targets in 10E-2 m*/
 uint16_t amplitude[8]; /*< amplitude of the targets (unitless)*/
 uint8_t sensor_type[8]; /*< each byte represents the sensor type: 0 - INVALID, 1 - TOP, 2 - BOTTOM, 3 - FRONT, 4 - REAR, 5 - LEFT, 6 - RIGHT*/
} alink_tof_data_t;

#define ALINK_MSG_ID_TOF_DATA_LEN 44
#define ALINK_MSG_ID_162_LEN 44

#define ALINK_MSG_ID_TOF_DATA_CRC 115
#define ALINK_MSG_ID_162_CRC 115

#define ALINK_MSG_TOF_DATA_FIELD_DISTANCE_LEN 8
#define ALINK_MSG_TOF_DATA_FIELD_AMPLITUDE_LEN 8
#define ALINK_MSG_TOF_DATA_FIELD_SENSOR_TYPE_LEN 8

#define ALINK_MESSAGE_INFO_TOF_DATA { \
	"TOF_DATA", \
	4, \
	{  { "timestamp", NULL, ALINK_TYPE_UINT32_T, 0, 0, offsetof(alink_tof_data_t, timestamp) }, \
         { "distance", NULL, ALINK_TYPE_UINT16_T, 8, 4, offsetof(alink_tof_data_t, distance) }, \
         { "amplitude", NULL, ALINK_TYPE_UINT16_T, 8, 20, offsetof(alink_tof_data_t, amplitude) }, \
         { "sensor_type", NULL, ALINK_TYPE_UINT8_T, 8, 36, offsetof(alink_tof_data_t, sensor_type) }, \
         } \
}


/**
 * @brief Pack a tof_data message
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 *
 * @param timestamp timestamp (milliseconds since system boot)
 * @param sensor_type each byte represents the sensor type: 0 - INVALID, 1 - TOP, 2 - BOTTOM, 3 - FRONT, 4 - REAR, 5 - LEFT, 6 - RIGHT
 * @param distance distances of the targets in 10E-2 m
 * @param amplitude amplitude of the targets (unitless)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_tof_data_pack(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg,
						       uint32_t timestamp, const uint8_t *sensor_type, const uint16_t *distance, const uint16_t *amplitude)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_TOF_DATA_LEN];
	_mav_put_uint32_t(buf, 0, timestamp);
	_mav_put_uint16_t_array(buf, 4, distance, 8);
	_mav_put_uint16_t_array(buf, 20, amplitude, 8);
	_mav_put_uint8_t_array(buf, 36, sensor_type, 8);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_TOF_DATA_LEN);
#else
	alink_tof_data_t packet;
	packet.timestamp = timestamp;
	mav_array_memcpy(packet.distance, distance, sizeof(uint16_t)*8);
	mav_array_memcpy(packet.amplitude, amplitude, sizeof(uint16_t)*8);
	mav_array_memcpy(packet.sensor_type, sensor_type, sizeof(uint8_t)*8);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_TOF_DATA_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_TOF_DATA;
#if ALINK_CRC_EXTRA
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_TOF_DATA_LEN,ALINK_MSG_ID_TOF_DATA_CRC);
#else
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_TOF_DATA_LEN);
#endif
}

/**
 * @brief Pack a tof_data message on a channel
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param timestamp timestamp (milliseconds since system boot)
 * @param sensor_type each byte represents the sensor type: 0 - INVALID, 1 - TOP, 2 - BOTTOM, 3 - FRONT, 4 - REAR, 5 - LEFT, 6 - RIGHT
 * @param distance distances of the targets in 10E-2 m
 * @param amplitude amplitude of the targets (unitless)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_tof_data_pack_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan,
							   alink_message_head_t* msg,
						           uint32_t timestamp,const uint8_t *sensor_type,const uint16_t *distance,const uint16_t *amplitude)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_TOF_DATA_LEN];
	_mav_put_uint32_t(buf, 0, timestamp);
	_mav_put_uint16_t_array(buf, 4, distance, 8);
	_mav_put_uint16_t_array(buf, 20, amplitude, 8);
	_mav_put_uint8_t_array(buf, 36, sensor_type, 8);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_TOF_DATA_LEN);
#else
	alink_tof_data_t packet;
	packet.timestamp = timestamp;
	mav_array_memcpy(packet.distance, distance, sizeof(uint16_t)*8);
	mav_array_memcpy(packet.amplitude, amplitude, sizeof(uint16_t)*8);
	mav_array_memcpy(packet.sensor_type, sensor_type, sizeof(uint8_t)*8);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_TOF_DATA_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_TOF_DATA;
#if ALINK_CRC_EXTRA
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_TOF_DATA_LEN,ALINK_MSG_ID_TOF_DATA_CRC);
#else
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_TOF_DATA_LEN);
#endif
}
/**
 * @brief Encode a tof_data struct
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 * @param tof_data C-struct to read the message contents from
 */
static inline uint16_t alink_msg_tof_data_encode(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg, const alink_tof_data_t* tof_data)
{
	return alink_msg_tof_data_pack(dest_id, source_id, msg, tof_data->timestamp, tof_data->sensor_type, tof_data->distance, tof_data->amplitude);
}

/**
 * @brief Encode a tof_data struct on a channel
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param tof_data C-struct to read the message contents from
 */
static inline uint16_t alink_msg_tof_data_encode_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan, alink_message_head_t* msg, const alink_tof_data_t* tof_data)
{
	return alink_msg_tof_data_pack_chan(dest_id, source_id, chan, msg, tof_data->timestamp, tof_data->sensor_type, tof_data->distance, tof_data->amplitude);
}
// MESSAGE TOF_DATA UNPACKING


/**
 * @brief Get field timestamp from tof_data message
 *
 * @return timestamp (milliseconds since system boot)
 */
static inline uint32_t alink_msg_tof_data_get_timestamp(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field sensor_type from tof_data message
 *
 * @return each byte represents the sensor type: 0 - INVALID, 1 - TOP, 2 - BOTTOM, 3 - FRONT, 4 - REAR, 5 - LEFT, 6 - RIGHT
 */
static inline uint16_t alink_msg_tof_data_get_sensor_type(const alink_message_head_t* msg, uint8_t *sensor_type)
{
	return _MAV_RETURN_uint8_t_array(msg, sensor_type, 8,  36);
}

/**
 * @brief Get field distance from tof_data message
 *
 * @return distances of the targets in 10E-2 m
 */
static inline uint16_t alink_msg_tof_data_get_distance(const alink_message_head_t* msg, uint16_t *distance)
{
	return _MAV_RETURN_uint16_t_array(msg, distance, 8,  4);
}

/**
 * @brief Get field amplitude from tof_data message
 *
 * @return amplitude of the targets (unitless)
 */
static inline uint16_t alink_msg_tof_data_get_amplitude(const alink_message_head_t* msg, uint16_t *amplitude)
{
	return _MAV_RETURN_uint16_t_array(msg, amplitude, 8,  20);
}

/**
 * @brief Decode a tof_data message into a struct
 *
 * @param msg The message to decode
 * @param tof_data C-struct to decode the message contents into
 */
static inline void alink_msg_tof_data_decode(const alink_message_head_t* msg, alink_tof_data_t* tof_data)
{
#if ALINK_NEED_BYTE_SWAP
	tof_data->timestamp = alink_msg_tof_data_get_timestamp(msg);
	alink_msg_tof_data_get_distance(msg, tof_data->distance);
	alink_msg_tof_data_get_amplitude(msg, tof_data->amplitude);
	alink_msg_tof_data_get_sensor_type(msg, tof_data->sensor_type);
#else
	memcpy(tof_data, _MAV_PAYLOAD(msg), ALINK_MSG_ID_TOF_DATA_LEN);
#endif
}
