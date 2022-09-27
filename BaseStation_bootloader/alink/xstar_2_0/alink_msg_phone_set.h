// MESSAGE PHONE_SET PACKING

#define ALINK_MSG_ID_PHONE_SET 150

typedef struct __alink_phone_set_t
{
 uint8_t type; /*< command*/
 uint8_t length; /*< parameter length*/
 uint8_t set_data[22]; /*< parameters*/
} alink_phone_set_t;

#define ALINK_MSG_ID_PHONE_SET_LEN 24
#define ALINK_MSG_ID_150_LEN 24

#define ALINK_MSG_ID_PHONE_SET_CRC 36
#define ALINK_MSG_ID_150_CRC 36

#define ALINK_MSG_PHONE_SET_FIELD_SET_DATA_LEN 22

#define ALINK_MESSAGE_INFO_PHONE_SET { \
	"PHONE_SET", \
	3, \
	{  { "type", NULL, ALINK_TYPE_UINT8_T, 0, 0, offsetof(alink_phone_set_t, type) }, \
         { "length", NULL, ALINK_TYPE_UINT8_T, 0, 1, offsetof(alink_phone_set_t, length) }, \
         { "set_data", NULL, ALINK_TYPE_UINT8_T, 22, 2, offsetof(alink_phone_set_t, set_data) }, \
         } \
}


/**
 * @brief Pack a phone_set message
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 *
 * @param type command
 * @param length parameter length
 * @param set_data parameters
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_phone_set_pack(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg,
						       uint8_t type, uint8_t length, const uint8_t *set_data)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_PHONE_SET_LEN];
	_mav_put_uint8_t(buf, 0, type);
	_mav_put_uint8_t(buf, 1, length);
	_mav_put_uint8_t_array(buf, 2, set_data, 22);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_PHONE_SET_LEN);
#else
	alink_phone_set_t packet;
	packet.type = type;
	packet.length = length;
	mav_array_memcpy(packet.set_data, set_data, sizeof(uint8_t)*22);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_PHONE_SET_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_PHONE_SET;
#if ALINK_CRC_EXTRA
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_PHONE_SET_LEN,ALINK_MSG_ID_PHONE_SET_CRC);
#else
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_PHONE_SET_LEN);
#endif
}

/**
 * @brief Pack a phone_set message on a channel
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param type command
 * @param length parameter length
 * @param set_data parameters
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_phone_set_pack_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan,
							   alink_message_head_t* msg,
						           uint8_t type,uint8_t length,const uint8_t *set_data)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_PHONE_SET_LEN];
	_mav_put_uint8_t(buf, 0, type);
	_mav_put_uint8_t(buf, 1, length);
	_mav_put_uint8_t_array(buf, 2, set_data, 22);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_PHONE_SET_LEN);
#else
	alink_phone_set_t packet;
	packet.type = type;
	packet.length = length;
	mav_array_memcpy(packet.set_data, set_data, sizeof(uint8_t)*22);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_PHONE_SET_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_PHONE_SET;
#if ALINK_CRC_EXTRA
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_PHONE_SET_LEN,ALINK_MSG_ID_PHONE_SET_CRC);
#else
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_PHONE_SET_LEN);
#endif
}
/**
 * @brief Encode a phone_set struct
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 * @param phone_set C-struct to read the message contents from
 */
static inline uint16_t alink_msg_phone_set_encode(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg, const alink_phone_set_t* phone_set)
{
	return alink_msg_phone_set_pack(dest_id, source_id, msg, phone_set->type, phone_set->length, phone_set->set_data);
}

/**
 * @brief Encode a phone_set struct on a channel
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param phone_set C-struct to read the message contents from
 */
static inline uint16_t alink_msg_phone_set_encode_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan, alink_message_head_t* msg, const alink_phone_set_t* phone_set)
{
	return alink_msg_phone_set_pack_chan(dest_id, source_id, chan, msg, phone_set->type, phone_set->length, phone_set->set_data);
}
// MESSAGE PHONE_SET UNPACKING


/**
 * @brief Get field type from phone_set message
 *
 * @return command
 */
static inline uint8_t alink_msg_phone_set_get_type(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field length from phone_set message
 *
 * @return parameter length
 */
static inline uint8_t alink_msg_phone_set_get_length(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  1);
}

/**
 * @brief Get field set_data from phone_set message
 *
 * @return parameters
 */
static inline uint16_t alink_msg_phone_set_get_set_data(const alink_message_head_t* msg, uint8_t *set_data)
{
	return _MAV_RETURN_uint8_t_array(msg, set_data, 22,  2);
}

/**
 * @brief Decode a phone_set message into a struct
 *
 * @param msg The message to decode
 * @param phone_set C-struct to decode the message contents into
 */
static inline void alink_msg_phone_set_decode(const alink_message_head_t* msg, alink_phone_set_t* phone_set)
{
#if ALINK_NEED_BYTE_SWAP
	phone_set->type = alink_msg_phone_set_get_type(msg);
	phone_set->length = alink_msg_phone_set_get_length(msg);
	alink_msg_phone_set_get_set_data(msg, phone_set->set_data);
#else
	memcpy(phone_set, _MAV_PAYLOAD(msg), ALINK_MSG_ID_PHONE_SET_LEN);
#endif
}
