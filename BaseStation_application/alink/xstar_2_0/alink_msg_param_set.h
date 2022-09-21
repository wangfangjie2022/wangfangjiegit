// MESSAGE PARAM_SET PACKING

#define ALINK_MSG_ID_PARAM_SET 18

typedef struct __alink_param_set_t
{
 float param_value; /*< Onboard parameter value*/
 char param_id[16]; /*< Onboard parameter id, terminated by NULL if the length is less than 16 human-readable chars and WITHOUT null
                                                      termination (NULL) byte if the length is exactly 16 chars - applications have to provide 16+1 bytes storage
                                                      if the ID is stored as string*/
 uint8_t param_type; /*< Onboard parameter type: see the MAV_PARAM_TYPE enum for supported data types.*/
} alink_param_set_t;

#define ALINK_MSG_ID_PARAM_SET_LEN 21
#define ALINK_MSG_ID_18_LEN 21

#define ALINK_MSG_ID_PARAM_SET_CRC 22
#define ALINK_MSG_ID_18_CRC 22

#define ALINK_MSG_PARAM_SET_FIELD_PARAM_ID_LEN 16

#define ALINK_MESSAGE_INFO_PARAM_SET { \
	"PARAM_SET", \
	3, \
	{  { "param_value", NULL, ALINK_TYPE_FLOAT, 0, 0, offsetof(alink_param_set_t, param_value) }, \
         { "param_id", NULL, ALINK_TYPE_CHAR, 16, 4, offsetof(alink_param_set_t, param_id) }, \
         { "param_type", NULL, ALINK_TYPE_UINT8_T, 0, 20, offsetof(alink_param_set_t, param_type) }, \
         } \
}


/**
 * @brief Pack a param_set message
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 *
 * @param param_id Onboard parameter id, terminated by NULL if the length is less than 16 human-readable chars and WITHOUT null
                                                      termination (NULL) byte if the length is exactly 16 chars - applications have to provide 16+1 bytes storage
                                                      if the ID is stored as string
 * @param param_value Onboard parameter value
 * @param param_type Onboard parameter type: see the MAV_PARAM_TYPE enum for supported data types.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_param_set_pack(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg,
						       const char *param_id, float param_value, uint8_t param_type)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_PARAM_SET_LEN];
	_mav_put_float(buf, 0, param_value);
	_mav_put_uint8_t(buf, 20, param_type);
	_mav_put_char_array(buf, 4, param_id, 16);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_PARAM_SET_LEN);
#else
	alink_param_set_t packet;
	packet.param_value = param_value;
	packet.param_type = param_type;
	mav_array_memcpy(packet.param_id, param_id, sizeof(char)*16);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_PARAM_SET_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_PARAM_SET;
#if ALINK_CRC_EXTRA
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_PARAM_SET_LEN,ALINK_MSG_ID_PARAM_SET_CRC);
#else
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_PARAM_SET_LEN);
#endif
}

/**
 * @brief Pack a param_set message on a channel
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param param_id Onboard parameter id, terminated by NULL if the length is less than 16 human-readable chars and WITHOUT null
                                                      termination (NULL) byte if the length is exactly 16 chars - applications have to provide 16+1 bytes storage
                                                      if the ID is stored as string
 * @param param_value Onboard parameter value
 * @param param_type Onboard parameter type: see the MAV_PARAM_TYPE enum for supported data types.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_param_set_pack_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan,
							   alink_message_head_t* msg,
						           const char *param_id,float param_value,uint8_t param_type)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_PARAM_SET_LEN];
	_mav_put_float(buf, 0, param_value);
	_mav_put_uint8_t(buf, 20, param_type);
	_mav_put_char_array(buf, 4, param_id, 16);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_PARAM_SET_LEN);
#else
	alink_param_set_t packet;
	packet.param_value = param_value;
	packet.param_type = param_type;
	mav_array_memcpy(packet.param_id, param_id, sizeof(char)*16);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_PARAM_SET_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_PARAM_SET;
#if ALINK_CRC_EXTRA
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_PARAM_SET_LEN,ALINK_MSG_ID_PARAM_SET_CRC);
#else
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_PARAM_SET_LEN);
#endif
}
/**
 * @brief Encode a param_set struct
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 * @param param_set C-struct to read the message contents from
 */
static inline uint16_t alink_msg_param_set_encode(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg, const alink_param_set_t* param_set)
{
	return alink_msg_param_set_pack(dest_id, source_id, msg, param_set->param_id, param_set->param_value, param_set->param_type);
}

/**
 * @brief Encode a param_set struct on a channel
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param param_set C-struct to read the message contents from
 */
static inline uint16_t alink_msg_param_set_encode_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan, alink_message_head_t* msg, const alink_param_set_t* param_set)
{
	return alink_msg_param_set_pack_chan(dest_id, source_id, chan, msg, param_set->param_id, param_set->param_value, param_set->param_type);
}
// MESSAGE PARAM_SET UNPACKING


/**
 * @brief Get field param_id from param_set message
 *
 * @return Onboard parameter id, terminated by NULL if the length is less than 16 human-readable chars and WITHOUT null
                                                      termination (NULL) byte if the length is exactly 16 chars - applications have to provide 16+1 bytes storage
                                                      if the ID is stored as string
 */
static inline uint16_t alink_msg_param_set_get_param_id(const alink_message_head_t* msg, char *param_id)
{
	return _MAV_RETURN_char_array(msg, param_id, 16,  4);
}

/**
 * @brief Get field param_value from param_set message
 *
 * @return Onboard parameter value
 */
static inline float alink_msg_param_set_get_param_value(const alink_message_head_t* msg)
{
	return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field param_type from param_set message
 *
 * @return Onboard parameter type: see the MAV_PARAM_TYPE enum for supported data types.
 */
static inline uint8_t alink_msg_param_set_get_param_type(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  20);
}

/**
 * @brief Decode a param_set message into a struct
 *
 * @param msg The message to decode
 * @param param_set C-struct to decode the message contents into
 */
static inline void alink_msg_param_set_decode(const alink_message_head_t* msg, alink_param_set_t* param_set)
{
#if ALINK_NEED_BYTE_SWAP
	param_set->param_value = alink_msg_param_set_get_param_value(msg);
	alink_msg_param_set_get_param_id(msg, param_set->param_id);
	param_set->param_type = alink_msg_param_set_get_param_type(msg);
#else
	memcpy(param_set, _MAV_PAYLOAD(msg), ALINK_MSG_ID_PARAM_SET_LEN);
#endif
}
