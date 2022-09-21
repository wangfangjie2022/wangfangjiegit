// MESSAGE PARAM_VALUE PACKING

#define ALINK_MSG_ID_PARAM_VALUE 17

typedef struct __alink_param_value_t
{
 float param_value; /*< Onboard parameter value*/
 uint16_t param_count; /*< Total number of onboard parameters*/
 uint16_t param_index; /*< Index of this onboard parameter*/
 char param_id[16]; /*< Onboard parameter id, terminated by NULL if the length is less than 16 human-readable chars and WITHOUT null
                                                      termination (NULL) byte if the length is exactly 16 chars - applications have to provide 16+1 bytes storage
                                                      if the ID is stored as string*/
 uint8_t param_type; /*< Onboard parameter type: see the MAV_PARAM_TYPE enum for supported data types.*/
} alink_param_value_t;

#define ALINK_MSG_ID_PARAM_VALUE_LEN 25
#define ALINK_MSG_ID_17_LEN 25

#define ALINK_MSG_ID_PARAM_VALUE_CRC 220
#define ALINK_MSG_ID_17_CRC 220

#define ALINK_MSG_PARAM_VALUE_FIELD_PARAM_ID_LEN 16

#define ALINK_MESSAGE_INFO_PARAM_VALUE { \
	"PARAM_VALUE", \
	5, \
	{  { "param_value", NULL, ALINK_TYPE_FLOAT, 0, 0, offsetof(alink_param_value_t, param_value) }, \
         { "param_count", NULL, ALINK_TYPE_UINT16_T, 0, 4, offsetof(alink_param_value_t, param_count) }, \
         { "param_index", NULL, ALINK_TYPE_UINT16_T, 0, 6, offsetof(alink_param_value_t, param_index) }, \
         { "param_id", NULL, ALINK_TYPE_CHAR, 16, 8, offsetof(alink_param_value_t, param_id) }, \
         { "param_type", NULL, ALINK_TYPE_UINT8_T, 0, 24, offsetof(alink_param_value_t, param_type) }, \
         } \
}


/**
 * @brief Pack a param_value message
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 *
 * @param param_id Onboard parameter id, terminated by NULL if the length is less than 16 human-readable chars and WITHOUT null
                                                      termination (NULL) byte if the length is exactly 16 chars - applications have to provide 16+1 bytes storage
                                                      if the ID is stored as string
 * @param param_value Onboard parameter value
 * @param param_type Onboard parameter type: see the MAV_PARAM_TYPE enum for supported data types.
 * @param param_count Total number of onboard parameters
 * @param param_index Index of this onboard parameter
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_param_value_pack(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg,
						       const char *param_id, float param_value, uint8_t param_type, uint16_t param_count, uint16_t param_index)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_PARAM_VALUE_LEN];
	_mav_put_float(buf, 0, param_value);
	_mav_put_uint16_t(buf, 4, param_count);
	_mav_put_uint16_t(buf, 6, param_index);
	_mav_put_uint8_t(buf, 24, param_type);
	_mav_put_char_array(buf, 8, param_id, 16);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_PARAM_VALUE_LEN);
#else
	alink_param_value_t packet;
	packet.param_value = param_value;
	packet.param_count = param_count;
	packet.param_index = param_index;
	packet.param_type = param_type;
	mav_array_memcpy(packet.param_id, param_id, sizeof(char)*16);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_PARAM_VALUE_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_PARAM_VALUE;
#if ALINK_CRC_EXTRA
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_PARAM_VALUE_LEN,ALINK_MSG_ID_PARAM_VALUE_CRC);
#else
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_PARAM_VALUE_LEN);
#endif
}

/**
 * @brief Pack a param_value message on a channel
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param param_id Onboard parameter id, terminated by NULL if the length is less than 16 human-readable chars and WITHOUT null
                                                      termination (NULL) byte if the length is exactly 16 chars - applications have to provide 16+1 bytes storage
                                                      if the ID is stored as string
 * @param param_value Onboard parameter value
 * @param param_type Onboard parameter type: see the MAV_PARAM_TYPE enum for supported data types.
 * @param param_count Total number of onboard parameters
 * @param param_index Index of this onboard parameter
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_param_value_pack_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan,
							   alink_message_head_t* msg,
						           const char *param_id,float param_value,uint8_t param_type,uint16_t param_count,uint16_t param_index)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_PARAM_VALUE_LEN];
	_mav_put_float(buf, 0, param_value);
	_mav_put_uint16_t(buf, 4, param_count);
	_mav_put_uint16_t(buf, 6, param_index);
	_mav_put_uint8_t(buf, 24, param_type);
	_mav_put_char_array(buf, 8, param_id, 16);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_PARAM_VALUE_LEN);
#else
	alink_param_value_t packet;
	packet.param_value = param_value;
	packet.param_count = param_count;
	packet.param_index = param_index;
	packet.param_type = param_type;
	mav_array_memcpy(packet.param_id, param_id, sizeof(char)*16);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_PARAM_VALUE_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_PARAM_VALUE;
#if ALINK_CRC_EXTRA
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_PARAM_VALUE_LEN,ALINK_MSG_ID_PARAM_VALUE_CRC);
#else
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_PARAM_VALUE_LEN);
#endif
}
/**
 * @brief Encode a param_value struct
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 * @param param_value C-struct to read the message contents from
 */
static inline uint16_t alink_msg_param_value_encode(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg, const alink_param_value_t* param_value)
{
	return alink_msg_param_value_pack(dest_id, source_id, msg, param_value->param_id, param_value->param_value, param_value->param_type, param_value->param_count, param_value->param_index);
}

/**
 * @brief Encode a param_value struct on a channel
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param param_value C-struct to read the message contents from
 */
static inline uint16_t alink_msg_param_value_encode_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan, alink_message_head_t* msg, const alink_param_value_t* param_value)
{
	return alink_msg_param_value_pack_chan(dest_id, source_id, chan, msg, param_value->param_id, param_value->param_value, param_value->param_type, param_value->param_count, param_value->param_index);
}
// MESSAGE PARAM_VALUE UNPACKING


/**
 * @brief Get field param_id from param_value message
 *
 * @return Onboard parameter id, terminated by NULL if the length is less than 16 human-readable chars and WITHOUT null
                                                      termination (NULL) byte if the length is exactly 16 chars - applications have to provide 16+1 bytes storage
                                                      if the ID is stored as string
 */
static inline uint16_t alink_msg_param_value_get_param_id(const alink_message_head_t* msg, char *param_id)
{
	return _MAV_RETURN_char_array(msg, param_id, 16,  8);
}

/**
 * @brief Get field param_value from param_value message
 *
 * @return Onboard parameter value
 */
static inline float alink_msg_param_value_get_param_value(const alink_message_head_t* msg)
{
	return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field param_type from param_value message
 *
 * @return Onboard parameter type: see the MAV_PARAM_TYPE enum for supported data types.
 */
static inline uint8_t alink_msg_param_value_get_param_type(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  24);
}

/**
 * @brief Get field param_count from param_value message
 *
 * @return Total number of onboard parameters
 */
static inline uint16_t alink_msg_param_value_get_param_count(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  4);
}

/**
 * @brief Get field param_index from param_value message
 *
 * @return Index of this onboard parameter
 */
static inline uint16_t alink_msg_param_value_get_param_index(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  6);
}

/**
 * @brief Decode a param_value message into a struct
 *
 * @param msg The message to decode
 * @param param_value C-struct to decode the message contents into
 */
static inline void alink_msg_param_value_decode(const alink_message_head_t* msg, alink_param_value_t* param_value)
{
#if ALINK_NEED_BYTE_SWAP
	param_value->param_value = alink_msg_param_value_get_param_value(msg);
	param_value->param_count = alink_msg_param_value_get_param_count(msg);
	param_value->param_index = alink_msg_param_value_get_param_index(msg);
	alink_msg_param_value_get_param_id(msg, param_value->param_id);
	param_value->param_type = alink_msg_param_value_get_param_type(msg);
#else
	memcpy(param_value, _MAV_PAYLOAD(msg), ALINK_MSG_ID_PARAM_VALUE_LEN);
#endif
}
