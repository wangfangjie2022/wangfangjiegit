// MESSAGE CAMERA_CTRL_COMMAND PACKING

#define ALINK_MSG_ID_CAMERA_CTRL_COMMAND 107

typedef struct __alink_camera_ctrl_command_t
{
 uint16_t command; /*< command id*/
 uint8_t camDevId; /*< camera device id*/
 char data; /*< 数据部分，为变长数据，但最大不超过508字节长，注意只能使用alink_finalize_message 进行打包（如：alink_finalize_message(alink_msg, DEV_DSP_RC, DEV_DSP, ALINK_MSG_ID_107_LEN + len - 1, ALINK_MSG_ID_107_CRC)）*/
} alink_camera_ctrl_command_t;

#define ALINK_MSG_ID_CAMERA_CTRL_COMMAND_LEN 4
#define ALINK_MSG_ID_107_LEN 4

#define ALINK_MSG_ID_CAMERA_CTRL_COMMAND_CRC 196
#define ALINK_MSG_ID_107_CRC 196



#define ALINK_MESSAGE_INFO_CAMERA_CTRL_COMMAND { \
	"CAMERA_CTRL_COMMAND", \
	3, \
	{  { "command", NULL, ALINK_TYPE_UINT16_T, 0, 0, offsetof(alink_camera_ctrl_command_t, command) }, \
         { "camDevId", NULL, ALINK_TYPE_UINT8_T, 0, 2, offsetof(alink_camera_ctrl_command_t, camDevId) }, \
         { "data", NULL, ALINK_TYPE_CHAR, 0, 3, offsetof(alink_camera_ctrl_command_t, data) }, \
         } \
}


/**
 * @brief Pack a camera_ctrl_command message
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 *
 * @param camDevId camera device id
 * @param command command id
 * @param data 数据部分，为变长数据，但最大不超过508字节长，注意只能使用alink_finalize_message 进行打包（如：alink_finalize_message(alink_msg, DEV_DSP_RC, DEV_DSP, ALINK_MSG_ID_107_LEN + len - 1, ALINK_MSG_ID_107_CRC)）
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_camera_ctrl_command_pack(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg,
						       uint8_t camDevId, uint16_t command, char data)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_CAMERA_CTRL_COMMAND_LEN];
	_mav_put_uint16_t(buf, 0, command);
	_mav_put_uint8_t(buf, 2, camDevId);
	_mav_put_char(buf, 3, data);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_CAMERA_CTRL_COMMAND_LEN);
#else
	alink_camera_ctrl_command_t packet;
	packet.command = command;
	packet.camDevId = camDevId;
	packet.data = data;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_CAMERA_CTRL_COMMAND_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_CAMERA_CTRL_COMMAND;
#if ALINK_CRC_EXTRA
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_CAMERA_CTRL_COMMAND_LEN,ALINK_MSG_ID_CAMERA_CTRL_COMMAND_CRC);
#else
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_CAMERA_CTRL_COMMAND_LEN);
#endif
}

/**
 * @brief Pack a camera_ctrl_command message on a channel
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param camDevId camera device id
 * @param command command id
 * @param data 数据部分，为变长数据，但最大不超过508字节长，注意只能使用alink_finalize_message 进行打包（如：alink_finalize_message(alink_msg, DEV_DSP_RC, DEV_DSP, ALINK_MSG_ID_107_LEN + len - 1, ALINK_MSG_ID_107_CRC)）
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_camera_ctrl_command_pack_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan,
							   alink_message_head_t* msg,
						           uint8_t camDevId,uint16_t command,char data)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_CAMERA_CTRL_COMMAND_LEN];
	_mav_put_uint16_t(buf, 0, command);
	_mav_put_uint8_t(buf, 2, camDevId);
	_mav_put_char(buf, 3, data);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_CAMERA_CTRL_COMMAND_LEN);
#else
	alink_camera_ctrl_command_t packet;
	packet.command = command;
	packet.camDevId = camDevId;
	packet.data = data;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_CAMERA_CTRL_COMMAND_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_CAMERA_CTRL_COMMAND;
#if ALINK_CRC_EXTRA
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_CAMERA_CTRL_COMMAND_LEN,ALINK_MSG_ID_CAMERA_CTRL_COMMAND_CRC);
#else
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_CAMERA_CTRL_COMMAND_LEN);
#endif
}
/**
 * @brief Encode a camera_ctrl_command struct
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 * @param camera_ctrl_command C-struct to read the message contents from
 */
static inline uint16_t alink_msg_camera_ctrl_command_encode(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg, const alink_camera_ctrl_command_t* camera_ctrl_command)
{
	return alink_msg_camera_ctrl_command_pack(dest_id, source_id, msg, camera_ctrl_command->camDevId, camera_ctrl_command->command, camera_ctrl_command->data);
}

/**
 * @brief Encode a camera_ctrl_command struct on a channel
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param camera_ctrl_command C-struct to read the message contents from
 */
static inline uint16_t alink_msg_camera_ctrl_command_encode_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan, alink_message_head_t* msg, const alink_camera_ctrl_command_t* camera_ctrl_command)
{
	return alink_msg_camera_ctrl_command_pack_chan(dest_id, source_id, chan, msg, camera_ctrl_command->camDevId, camera_ctrl_command->command, camera_ctrl_command->data);
}
// MESSAGE CAMERA_CTRL_COMMAND UNPACKING


/**
 * @brief Get field camDevId from camera_ctrl_command message
 *
 * @return camera device id
 */
static inline uint8_t alink_msg_camera_ctrl_command_get_camDevId(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  2);
}

/**
 * @brief Get field command from camera_ctrl_command message
 *
 * @return command id
 */
static inline uint16_t alink_msg_camera_ctrl_command_get_command(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  0);
}

/**
 * @brief Get field data from camera_ctrl_command message
 *
 * @return 数据部分，为变长数据，但最大不超过508字节长，注意只能使用alink_finalize_message 进行打包（如：alink_finalize_message(alink_msg, DEV_DSP_RC, DEV_DSP, ALINK_MSG_ID_107_LEN + len - 1, ALINK_MSG_ID_107_CRC)）
 */
static inline char alink_msg_camera_ctrl_command_get_data(const alink_message_head_t* msg)
{
	return _MAV_RETURN_char(msg,  3);
}

/**
 * @brief Decode a camera_ctrl_command message into a struct
 *
 * @param msg The message to decode
 * @param camera_ctrl_command C-struct to decode the message contents into
 */
static inline void alink_msg_camera_ctrl_command_decode(const alink_message_head_t* msg, alink_camera_ctrl_command_t* camera_ctrl_command)
{
#if ALINK_NEED_BYTE_SWAP
	camera_ctrl_command->command = alink_msg_camera_ctrl_command_get_command(msg);
	camera_ctrl_command->camDevId = alink_msg_camera_ctrl_command_get_camDevId(msg);
	camera_ctrl_command->data = alink_msg_camera_ctrl_command_get_data(msg);
#else
	memcpy(camera_ctrl_command, _MAV_PAYLOAD(msg), ALINK_MSG_ID_CAMERA_CTRL_COMMAND_LEN);
#endif
}
