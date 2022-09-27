// MESSAGE MAG_DATA PACKING

#define ALINK_MSG_ID_MAG_DATA 146

typedef struct __alink_mag_data_t
{
 int16_t mag[3]; /*< gps info mag data.*/
} alink_mag_data_t;

#define ALINK_MSG_ID_MAG_DATA_LEN 6
#define ALINK_MSG_ID_146_LEN 6

#define ALINK_MSG_ID_MAG_DATA_CRC 146
#define ALINK_MSG_ID_146_CRC 146

#define ALINK_MSG_MAG_DATA_FIELD_MAG_LEN 3

#define ALINK_MESSAGE_INFO_MAG_DATA { \
	"MAG_DATA", \
	1, \
	{  { "mag", NULL, ALINK_TYPE_INT16_T, 3, 0, offsetof(alink_mag_data_t, mag) }, \
         } \
}


/**
 * @brief Pack a mag_data message
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 *
 * @param mag gps info mag data.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_mag_data_pack(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg,
						       const int16_t *mag)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_MAG_DATA_LEN];

	_mav_put_int16_t_array(buf, 0, mag, 3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_MAG_DATA_LEN);
#else
	alink_mag_data_t packet;

	mav_array_memcpy(packet.mag, mag, sizeof(int16_t)*3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_MAG_DATA_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_MAG_DATA;
#if ALINK_CRC_EXTRA
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_MAG_DATA_LEN,ALINK_MSG_ID_MAG_DATA_CRC);
#else
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_MAG_DATA_LEN);
#endif
}

/**
 * @brief Pack a mag_data message on a channel
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param mag gps info mag data.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_mag_data_pack_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan,
							   alink_message_head_t* msg,
						           const int16_t *mag)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_MAG_DATA_LEN];

	_mav_put_int16_t_array(buf, 0, mag, 3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_MAG_DATA_LEN);
#else
	alink_mag_data_t packet;

	mav_array_memcpy(packet.mag, mag, sizeof(int16_t)*3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_MAG_DATA_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_MAG_DATA;
#if ALINK_CRC_EXTRA
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_MAG_DATA_LEN,ALINK_MSG_ID_MAG_DATA_CRC);
#else
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_MAG_DATA_LEN);
#endif
}
/**
 * @brief Encode a mag_data struct
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 * @param mag_data C-struct to read the message contents from
 */
static inline uint16_t alink_msg_mag_data_encode(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg, const alink_mag_data_t* mag_data)
{
	return alink_msg_mag_data_pack(dest_id, source_id, msg, mag_data->mag);
}

/**
 * @brief Encode a mag_data struct on a channel
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param mag_data C-struct to read the message contents from
 */
static inline uint16_t alink_msg_mag_data_encode_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan, alink_message_head_t* msg, const alink_mag_data_t* mag_data)
{
	return alink_msg_mag_data_pack_chan(dest_id, source_id, chan, msg, mag_data->mag);
}
// MESSAGE MAG_DATA UNPACKING


/**
 * @brief Get field mag from mag_data message
 *
 * @return gps info mag data.
 */
static inline uint16_t alink_msg_mag_data_get_mag(const alink_message_head_t* msg, int16_t *mag)
{
	return _MAV_RETURN_int16_t_array(msg, mag, 3,  0);
}

/**
 * @brief Decode a mag_data message into a struct
 *
 * @param msg The message to decode
 * @param mag_data C-struct to decode the message contents into
 */
static inline void alink_msg_mag_data_decode(const alink_message_head_t* msg, alink_mag_data_t* mag_data)
{
#if ALINK_NEED_BYTE_SWAP
	alink_msg_mag_data_get_mag(msg, mag_data->mag);
#else
	memcpy(mag_data, _MAV_PAYLOAD(msg), ALINK_MSG_ID_MAG_DATA_LEN);
#endif
}
