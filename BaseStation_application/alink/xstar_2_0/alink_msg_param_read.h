// MESSAGE PARAM_READ PACKING

#define ALINK_MSG_ID_PARAM_READ 15

typedef struct __alink_param_read_t
{
 int16_t param_index; /*< Parameter index. Send -1 to use the param ID field as identifier (else the param id will be ignored)
                                                      Send -1 and the param ID empty, all parameters are emitted.*/
 char param_id[16]; /*< Onboard parameter id, terminated by NULL if the length is less than 16 human-readable chars and WITHOUT
                                                      null termination (NULL) byte if the length is exactly 16 chars - applications have to provide 16+1 bytes
                                                      storage if the ID is stored as string*/
} alink_param_read_t;

#define ALINK_MSG_ID_PARAM_READ_LEN 18
#define ALINK_MSG_ID_15_LEN 18

#define ALINK_MSG_ID_PARAM_READ_CRC 142
#define ALINK_MSG_ID_15_CRC 142

#define ALINK_MSG_PARAM_READ_FIELD_PARAM_ID_LEN 16

#define ALINK_MESSAGE_INFO_PARAM_READ { \
	"PARAM_READ", \
	2, \
	{  { "param_index", NULL, ALINK_TYPE_INT16_T, 0, 0, offsetof(alink_param_read_t, param_index) }, \
         { "param_id", NULL, ALINK_TYPE_CHAR, 16, 2, offsetof(alink_param_read_t, param_id) }, \
         } \
}


/**
 * @brief Pack a param_read message
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 *
 * @param param_id Onboard parameter id, terminated by NULL if the length is less than 16 human-readable chars and WITHOUT
                                                      null termination (NULL) byte if the length is exactly 16 chars - applications have to provide 16+1 bytes
                                                      storage if the ID is stored as string
 * @param param_index Parameter index. Send -1 to use the param ID field as identifier (else the param id will be ignored)
                                                      Send -1 and the param ID empty, all parameters are emitted.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_param_read_pack(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg,
						       const char *param_id, int16_t param_index)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_PARAM_READ_LEN];
	_mav_put_int16_t(buf, 0, param_index);
	_mav_put_char_array(buf, 2, param_id, 16);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_PARAM_READ_LEN);
#else
	alink_param_read_t packet;
	packet.param_index = param_index;
	mav_array_memcpy(packet.param_id, param_id, sizeof(char)*16);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_PARAM_READ_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_PARAM_READ;
#if ALINK_CRC_EXTRA
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_PARAM_READ_LEN,ALINK_MSG_ID_PARAM_READ_CRC);
#else
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_PARAM_READ_LEN);
#endif
}

/**
 * @brief Pack a param_read message on a channel
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param param_id Onboard parameter id, terminated by NULL if the length is less than 16 human-readable chars and WITHOUT
                                                      null termination (NULL) byte if the length is exactly 16 chars - applications have to provide 16+1 bytes
                                                      storage if the ID is stored as string
 * @param param_index Parameter index. Send -1 to use the param ID field as identifier (else the param id will be ignored)
                                                      Send -1 and the param ID empty, all parameters are emitted.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_param_read_pack_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan,
							   alink_message_head_t* msg,
						           const char *param_id,int16_t param_index)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_PARAM_READ_LEN];
	_mav_put_int16_t(buf, 0, param_index);
	_mav_put_char_array(buf, 2, param_id, 16);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_PARAM_READ_LEN);
#else
	alink_param_read_t packet;
	packet.param_index = param_index;
	mav_array_memcpy(packet.param_id, param_id, sizeof(char)*16);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_PARAM_READ_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_PARAM_READ;
#if ALINK_CRC_EXTRA
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_PARAM_READ_LEN,ALINK_MSG_ID_PARAM_READ_CRC);
#else
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_PARAM_READ_LEN);
#endif
}
/**
 * @brief Encode a param_read struct
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 * @param param_read C-struct to read the message contents from
 */
static inline uint16_t alink_msg_param_read_encode(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg, const alink_param_read_t* param_read)
{
	return alink_msg_param_read_pack(dest_id, source_id, msg, param_read->param_id, param_read->param_index);
}

/**
 * @brief Encode a param_read struct on a channel
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param param_read C-struct to read the message contents from
 */
static inline uint16_t alink_msg_param_read_encode_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan, alink_message_head_t* msg, const alink_param_read_t* param_read)
{
	return alink_msg_param_read_pack_chan(dest_id, source_id, chan, msg, param_read->param_id, param_read->param_index);
}
// MESSAGE PARAM_READ UNPACKING


/**
 * @brief Get field param_id from param_read message
 *
 * @return Onboard parameter id, terminated by NULL if the length is less than 16 human-readable chars and WITHOUT
                                                      null termination (NULL) byte if the length is exactly 16 chars - applications have to provide 16+1 bytes
                                                      storage if the ID is stored as string
 */
static inline uint16_t alink_msg_param_read_get_param_id(const alink_message_head_t* msg, char *param_id)
{
	return _MAV_RETURN_char_array(msg, param_id, 16,  2);
}

/**
 * @brief Get field param_index from param_read message
 *
 * @return Parameter index. Send -1 to use the param ID field as identifier (else the param id will be ignored)
                                                      Send -1 and the param ID empty, all parameters are emitted.
 */
static inline int16_t alink_msg_param_read_get_param_index(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  0);
}

/**
 * @brief Decode a param_read message into a struct
 *
 * @param msg The message to decode
 * @param param_read C-struct to decode the message contents into
 */
static inline void alink_msg_param_read_decode(const alink_message_head_t* msg, alink_param_read_t* param_read)
{
#if ALINK_NEED_BYTE_SWAP
	param_read->param_index = alink_msg_param_read_get_param_index(msg);
	alink_msg_param_read_get_param_id(msg, param_read->param_id);
#else
	memcpy(param_read, _MAV_PAYLOAD(msg), ALINK_MSG_ID_PARAM_READ_LEN);
#endif
}
