// MESSAGE CAMERA_COMMAND PACKING

#define ALINK_MSG_ID_CAMERA_COMMAND 104

typedef struct __alink_camera_command_t
{
 uint8_t cam_type; /*< camera type*/
 uint8_t command; /*< command id*/
 char data[62]; /*< Payload data bytes.*/
} alink_camera_command_t;

#define ALINK_MSG_ID_CAMERA_COMMAND_LEN 64
#define ALINK_MSG_ID_104_LEN 64

#define ALINK_MSG_ID_CAMERA_COMMAND_CRC 145
#define ALINK_MSG_ID_104_CRC 145

#define ALINK_MSG_CAMERA_COMMAND_FIELD_DATA_LEN 62

#define ALINK_MESSAGE_INFO_CAMERA_COMMAND { \
	"CAMERA_COMMAND", \
	3, \
	{  { "cam_type", NULL, ALINK_TYPE_UINT8_T, 0, 0, offsetof(alink_camera_command_t, cam_type) }, \
         { "command", NULL, ALINK_TYPE_UINT8_T, 0, 1, offsetof(alink_camera_command_t, command) }, \
         { "data", NULL, ALINK_TYPE_CHAR, 62, 2, offsetof(alink_camera_command_t, data) }, \
         } \
}


/**
 * @brief Pack a camera_command message
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 *
 * @param cam_type camera type
 * @param command command id
 * @param data Payload data bytes.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_camera_command_pack(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg,
						       uint8_t cam_type, uint8_t command, const char *data)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_CAMERA_COMMAND_LEN];
	_mav_put_uint8_t(buf, 0, cam_type);
	_mav_put_uint8_t(buf, 1, command);
	_mav_put_char_array(buf, 2, data, 62);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_CAMERA_COMMAND_LEN);
#else
	alink_camera_command_t packet;
	packet.cam_type = cam_type;
	packet.command = command;
	mav_array_memcpy(packet.data, data, sizeof(char)*62);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_CAMERA_COMMAND_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_CAMERA_COMMAND;
#if ALINK_CRC_EXTRA
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_CAMERA_COMMAND_LEN,ALINK_MSG_ID_CAMERA_COMMAND_CRC);
#else
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_CAMERA_COMMAND_LEN);
#endif
}

/**
 * @brief Pack a camera_command message on a channel
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param cam_type camera type
 * @param command command id
 * @param data Payload data bytes.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_camera_command_pack_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan,
							   alink_message_head_t* msg,
						           uint8_t cam_type,uint8_t command,const char *data)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_CAMERA_COMMAND_LEN];
	_mav_put_uint8_t(buf, 0, cam_type);
	_mav_put_uint8_t(buf, 1, command);
	_mav_put_char_array(buf, 2, data, 62);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_CAMERA_COMMAND_LEN);
#else
	alink_camera_command_t packet;
	packet.cam_type = cam_type;
	packet.command = command;
	mav_array_memcpy(packet.data, data, sizeof(char)*62);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_CAMERA_COMMAND_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_CAMERA_COMMAND;
#if ALINK_CRC_EXTRA
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_CAMERA_COMMAND_LEN,ALINK_MSG_ID_CAMERA_COMMAND_CRC);
#else
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_CAMERA_COMMAND_LEN);
#endif
}
/**
 * @brief Encode a camera_command struct
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 * @param camera_command C-struct to read the message contents from
 */
static inline uint16_t alink_msg_camera_command_encode(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg, const alink_camera_command_t* camera_command)
{
	return alink_msg_camera_command_pack(dest_id, source_id, msg, camera_command->cam_type, camera_command->command, camera_command->data);
}

/**
 * @brief Encode a camera_command struct on a channel
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param camera_command C-struct to read the message contents from
 */
static inline uint16_t alink_msg_camera_command_encode_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan, alink_message_head_t* msg, const alink_camera_command_t* camera_command)
{
	return alink_msg_camera_command_pack_chan(dest_id, source_id, chan, msg, camera_command->cam_type, camera_command->command, camera_command->data);
}
// MESSAGE CAMERA_COMMAND UNPACKING


/**
 * @brief Get field cam_type from camera_command message
 *
 * @return camera type
 */
static inline uint8_t alink_msg_camera_command_get_cam_type(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field command from camera_command message
 *
 * @return command id
 */
static inline uint8_t alink_msg_camera_command_get_command(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  1);
}

/**
 * @brief Get field data from camera_command message
 *
 * @return Payload data bytes.
 */
static inline uint16_t alink_msg_camera_command_get_data(const alink_message_head_t* msg, char *data)
{
	return _MAV_RETURN_char_array(msg, data, 62,  2);
}

/**
 * @brief Decode a camera_command message into a struct
 *
 * @param msg The message to decode
 * @param camera_command C-struct to decode the message contents into
 */
static inline void alink_msg_camera_command_decode(const alink_message_head_t* msg, alink_camera_command_t* camera_command)
{
#if ALINK_NEED_BYTE_SWAP
	camera_command->cam_type = alink_msg_camera_command_get_cam_type(msg);
	camera_command->command = alink_msg_camera_command_get_command(msg);
	alink_msg_camera_command_get_data(msg, camera_command->data);
#else
	memcpy(camera_command, _MAV_PAYLOAD(msg), ALINK_MSG_ID_CAMERA_COMMAND_LEN);
#endif
}
