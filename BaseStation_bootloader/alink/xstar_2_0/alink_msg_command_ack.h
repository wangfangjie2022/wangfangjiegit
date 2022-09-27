// MESSAGE COMMAND_ACK PACKING

#define ALINK_MSG_ID_COMMAND_ACK 4

typedef struct __alink_command_ack_t
{
 uint8_t command; /*< commande id*/
 char data[511]; /*< Payload data bytes.*/
} alink_command_ack_t;

#define ALINK_MSG_ID_COMMAND_ACK_LEN 512
#define ALINK_MSG_ID_4_LEN 512

#define ALINK_MSG_ID_COMMAND_ACK_CRC 233
#define ALINK_MSG_ID_4_CRC 233

#define ALINK_MSG_COMMAND_ACK_FIELD_DATA_LEN 511

#define ALINK_MESSAGE_INFO_COMMAND_ACK { \
	"COMMAND_ACK", \
	2, \
	{  { "command", NULL, ALINK_TYPE_UINT8_T, 0, 0, offsetof(alink_command_ack_t, command) }, \
         { "data", NULL, ALINK_TYPE_CHAR, 511, 1, offsetof(alink_command_ack_t, data) }, \
         } \
}


/**
 * @brief Pack a command_ack message
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 *
 * @param command commande id
 * @param data Payload data bytes.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_command_ack_pack(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg,
						       uint8_t command, const char *data)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_COMMAND_ACK_LEN];
	_mav_put_uint8_t(buf, 0, command);
	_mav_put_char_array(buf, 1, data, 511);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_COMMAND_ACK_LEN);
#else
	alink_command_ack_t packet;
	packet.command = command;
	mav_array_memcpy(packet.data, data, sizeof(char)*511);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_COMMAND_ACK_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_COMMAND_ACK;
#if ALINK_CRC_EXTRA
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_COMMAND_ACK_LEN,ALINK_MSG_ID_COMMAND_ACK_CRC);
#else
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_COMMAND_ACK_LEN);
#endif
}

/**
 * @brief Pack a command_ack message on a channel
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param command commande id
 * @param data Payload data bytes.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_command_ack_pack_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan,
							   alink_message_head_t* msg,
						           uint8_t command,const char *data)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_COMMAND_ACK_LEN];
	_mav_put_uint8_t(buf, 0, command);
	_mav_put_char_array(buf, 1, data, 511);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_COMMAND_ACK_LEN);
#else
	alink_command_ack_t packet;
	packet.command = command;
	mav_array_memcpy(packet.data, data, sizeof(char)*511);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_COMMAND_ACK_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_COMMAND_ACK;
#if ALINK_CRC_EXTRA
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_COMMAND_ACK_LEN,ALINK_MSG_ID_COMMAND_ACK_CRC);
#else
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_COMMAND_ACK_LEN);
#endif
}
/**
 * @brief Encode a command_ack struct
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 * @param command_ack C-struct to read the message contents from
 */
static inline uint16_t alink_msg_command_ack_encode(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg, const alink_command_ack_t* command_ack)
{
	return alink_msg_command_ack_pack(dest_id, source_id, msg, command_ack->command, command_ack->data);
}

/**
 * @brief Encode a command_ack struct on a channel
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param command_ack C-struct to read the message contents from
 */
static inline uint16_t alink_msg_command_ack_encode_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan, alink_message_head_t* msg, const alink_command_ack_t* command_ack)
{
	return alink_msg_command_ack_pack_chan(dest_id, source_id, chan, msg, command_ack->command, command_ack->data);
}
// MESSAGE COMMAND_ACK UNPACKING


/**
 * @brief Get field command from command_ack message
 *
 * @return commande id
 */
static inline uint8_t alink_msg_command_ack_get_command(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field data from command_ack message
 *
 * @return Payload data bytes.
 */
static inline uint16_t alink_msg_command_ack_get_data(const alink_message_head_t* msg, char *data)
{
	return _MAV_RETURN_char_array(msg, data, 511,  1);
}

/**
 * @brief Decode a command_ack message into a struct
 *
 * @param msg The message to decode
 * @param command_ack C-struct to decode the message contents into
 */
static inline void alink_msg_command_ack_decode(const alink_message_head_t* msg, alink_command_ack_t* command_ack)
{
#if ALINK_NEED_BYTE_SWAP
	command_ack->command = alink_msg_command_ack_get_command(msg);
	alink_msg_command_ack_get_data(msg, command_ack->data);
#else
	memcpy(command_ack, _MAV_PAYLOAD(msg), ALINK_MSG_ID_COMMAND_ACK_LEN);
#endif
}
