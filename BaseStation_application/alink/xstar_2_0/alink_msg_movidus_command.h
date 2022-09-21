// MESSAGE MOVIDUS_COMMAND PACKING

#define ALINK_MSG_ID_MOVIDUS_COMMAND 117

typedef struct __alink_movidus_command_t
{
 uint8_t command; /*<  movidus command:   */
 uint8_t data[31]; /*< command data / response code*/
} alink_movidus_command_t;

#define ALINK_MSG_ID_MOVIDUS_COMMAND_LEN 32
#define ALINK_MSG_ID_117_LEN 32

#define ALINK_MSG_ID_MOVIDUS_COMMAND_CRC 23
#define ALINK_MSG_ID_117_CRC 23

#define ALINK_MSG_MOVIDUS_COMMAND_FIELD_DATA_LEN 31

#define ALINK_MESSAGE_INFO_MOVIDUS_COMMAND { \
	"MOVIDUS_COMMAND", \
	2, \
	{  { "command", NULL, ALINK_TYPE_UINT8_T, 0, 0, offsetof(alink_movidus_command_t, command) }, \
         { "data", NULL, ALINK_TYPE_UINT8_T, 31, 1, offsetof(alink_movidus_command_t, data) }, \
         } \
}


/**
 * @brief Pack a movidus_command message
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 *
 * @param command  movidus command:   
 * @param data command data / response code
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_movidus_command_pack(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg,
						       uint8_t command, const uint8_t *data)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_MOVIDUS_COMMAND_LEN];
	_mav_put_uint8_t(buf, 0, command);
	_mav_put_uint8_t_array(buf, 1, data, 31);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_MOVIDUS_COMMAND_LEN);
#else
	alink_movidus_command_t packet;
	packet.command = command;
	mav_array_memcpy(packet.data, data, sizeof(uint8_t)*31);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_MOVIDUS_COMMAND_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_MOVIDUS_COMMAND;
#if ALINK_CRC_EXTRA
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_MOVIDUS_COMMAND_LEN,ALINK_MSG_ID_MOVIDUS_COMMAND_CRC);
#else
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_MOVIDUS_COMMAND_LEN);
#endif
}

/**
 * @brief Pack a movidus_command message on a channel
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param command  movidus command:   
 * @param data command data / response code
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_movidus_command_pack_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan,
							   alink_message_head_t* msg,
						           uint8_t command,const uint8_t *data)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_MOVIDUS_COMMAND_LEN];
	_mav_put_uint8_t(buf, 0, command);
	_mav_put_uint8_t_array(buf, 1, data, 31);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_MOVIDUS_COMMAND_LEN);
#else
	alink_movidus_command_t packet;
	packet.command = command;
	mav_array_memcpy(packet.data, data, sizeof(uint8_t)*31);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_MOVIDUS_COMMAND_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_MOVIDUS_COMMAND;
#if ALINK_CRC_EXTRA
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_MOVIDUS_COMMAND_LEN,ALINK_MSG_ID_MOVIDUS_COMMAND_CRC);
#else
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_MOVIDUS_COMMAND_LEN);
#endif
}
/**
 * @brief Encode a movidus_command struct
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 * @param movidus_command C-struct to read the message contents from
 */
static inline uint16_t alink_msg_movidus_command_encode(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg, const alink_movidus_command_t* movidus_command)
{
	return alink_msg_movidus_command_pack(dest_id, source_id, msg, movidus_command->command, movidus_command->data);
}

/**
 * @brief Encode a movidus_command struct on a channel
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param movidus_command C-struct to read the message contents from
 */
static inline uint16_t alink_msg_movidus_command_encode_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan, alink_message_head_t* msg, const alink_movidus_command_t* movidus_command)
{
	return alink_msg_movidus_command_pack_chan(dest_id, source_id, chan, msg, movidus_command->command, movidus_command->data);
}
// MESSAGE MOVIDUS_COMMAND UNPACKING


/**
 * @brief Get field command from movidus_command message
 *
 * @return  movidus command:   
 */
static inline uint8_t alink_msg_movidus_command_get_command(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field data from movidus_command message
 *
 * @return command data / response code
 */
static inline uint16_t alink_msg_movidus_command_get_data(const alink_message_head_t* msg, uint8_t *data)
{
	return _MAV_RETURN_uint8_t_array(msg, data, 31,  1);
}

/**
 * @brief Decode a movidus_command message into a struct
 *
 * @param msg The message to decode
 * @param movidus_command C-struct to decode the message contents into
 */
static inline void alink_msg_movidus_command_decode(const alink_message_head_t* msg, alink_movidus_command_t* movidus_command)
{
#if ALINK_NEED_BYTE_SWAP
	movidus_command->command = alink_msg_movidus_command_get_command(msg);
	alink_msg_movidus_command_get_data(msg, movidus_command->data);
#else
	memcpy(movidus_command, _MAV_PAYLOAD(msg), ALINK_MSG_ID_MOVIDUS_COMMAND_LEN);
#endif
}
