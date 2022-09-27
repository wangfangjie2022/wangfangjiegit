// MESSAGE GIMBAL_NORMAL_CMD PACKING

#define ALINK_MSG_ID_GIMBAL_NORMAL_CMD 53

typedef struct __alink_gimbal_normal_cmd_t
{
 uint8_t cmd; /*< 消息号，0X01-云台日志*/
 uint8_t data; /*< 数据部分，为变长数据，但最大不超过510字节长，注意只能使用alink_finalize_message 进行打包（如：alink_finalize_message(alink_msg, DEV_DSP_RC, DEV_DSP, ALINK_MSG_ID_58_LEN + len - 1, ALINK_MSG_ID_58_CRC)）*/
} alink_gimbal_normal_cmd_t;

#define ALINK_MSG_ID_GIMBAL_NORMAL_CMD_LEN 2
#define ALINK_MSG_ID_53_LEN 2

#define ALINK_MSG_ID_GIMBAL_NORMAL_CMD_CRC 159
#define ALINK_MSG_ID_53_CRC 159



#define ALINK_MESSAGE_INFO_GIMBAL_NORMAL_CMD { \
	"GIMBAL_NORMAL_CMD", \
	2, \
	{  { "cmd", NULL, ALINK_TYPE_UINT8_T, 0, 0, offsetof(alink_gimbal_normal_cmd_t, cmd) }, \
         { "data", NULL, ALINK_TYPE_UINT8_T, 0, 1, offsetof(alink_gimbal_normal_cmd_t, data) }, \
         } \
}


/**
 * @brief Pack a gimbal_normal_cmd message
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 *
 * @param cmd 消息号，0X01-云台日志
 * @param data 数据部分，为变长数据，但最大不超过510字节长，注意只能使用alink_finalize_message 进行打包（如：alink_finalize_message(alink_msg, DEV_DSP_RC, DEV_DSP, ALINK_MSG_ID_58_LEN + len - 1, ALINK_MSG_ID_58_CRC)）
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_gimbal_normal_cmd_pack(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg,
						       uint8_t cmd, uint8_t data)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_GIMBAL_NORMAL_CMD_LEN];
	_mav_put_uint8_t(buf, 0, cmd);
	_mav_put_uint8_t(buf, 1, data);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_GIMBAL_NORMAL_CMD_LEN);
#else
	alink_gimbal_normal_cmd_t packet;
	packet.cmd = cmd;
	packet.data = data;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_GIMBAL_NORMAL_CMD_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_GIMBAL_NORMAL_CMD;
#if ALINK_CRC_EXTRA
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_GIMBAL_NORMAL_CMD_LEN,ALINK_MSG_ID_GIMBAL_NORMAL_CMD_CRC);
#else
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_GIMBAL_NORMAL_CMD_LEN);
#endif
}

/**
 * @brief Pack a gimbal_normal_cmd message on a channel
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param cmd 消息号，0X01-云台日志
 * @param data 数据部分，为变长数据，但最大不超过510字节长，注意只能使用alink_finalize_message 进行打包（如：alink_finalize_message(alink_msg, DEV_DSP_RC, DEV_DSP, ALINK_MSG_ID_58_LEN + len - 1, ALINK_MSG_ID_58_CRC)）
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_gimbal_normal_cmd_pack_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan,
							   alink_message_head_t* msg,
						           uint8_t cmd,uint8_t data)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_GIMBAL_NORMAL_CMD_LEN];
	_mav_put_uint8_t(buf, 0, cmd);
	_mav_put_uint8_t(buf, 1, data);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_GIMBAL_NORMAL_CMD_LEN);
#else
	alink_gimbal_normal_cmd_t packet;
	packet.cmd = cmd;
	packet.data = data;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_GIMBAL_NORMAL_CMD_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_GIMBAL_NORMAL_CMD;
#if ALINK_CRC_EXTRA
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_GIMBAL_NORMAL_CMD_LEN,ALINK_MSG_ID_GIMBAL_NORMAL_CMD_CRC);
#else
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_GIMBAL_NORMAL_CMD_LEN);
#endif
}
/**
 * @brief Encode a gimbal_normal_cmd struct
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 * @param gimbal_normal_cmd C-struct to read the message contents from
 */
static inline uint16_t alink_msg_gimbal_normal_cmd_encode(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg, const alink_gimbal_normal_cmd_t* gimbal_normal_cmd)
{
	return alink_msg_gimbal_normal_cmd_pack(dest_id, source_id, msg, gimbal_normal_cmd->cmd, gimbal_normal_cmd->data);
}

/**
 * @brief Encode a gimbal_normal_cmd struct on a channel
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param gimbal_normal_cmd C-struct to read the message contents from
 */
static inline uint16_t alink_msg_gimbal_normal_cmd_encode_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan, alink_message_head_t* msg, const alink_gimbal_normal_cmd_t* gimbal_normal_cmd)
{
	return alink_msg_gimbal_normal_cmd_pack_chan(dest_id, source_id, chan, msg, gimbal_normal_cmd->cmd, gimbal_normal_cmd->data);
}
// MESSAGE GIMBAL_NORMAL_CMD UNPACKING


/**
 * @brief Get field cmd from gimbal_normal_cmd message
 *
 * @return 消息号，0X01-云台日志
 */
static inline uint8_t alink_msg_gimbal_normal_cmd_get_cmd(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field data from gimbal_normal_cmd message
 *
 * @return 数据部分，为变长数据，但最大不超过510字节长，注意只能使用alink_finalize_message 进行打包（如：alink_finalize_message(alink_msg, DEV_DSP_RC, DEV_DSP, ALINK_MSG_ID_58_LEN + len - 1, ALINK_MSG_ID_58_CRC)）
 */
static inline uint8_t alink_msg_gimbal_normal_cmd_get_data(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  1);
}

/**
 * @brief Decode a gimbal_normal_cmd message into a struct
 *
 * @param msg The message to decode
 * @param gimbal_normal_cmd C-struct to decode the message contents into
 */
static inline void alink_msg_gimbal_normal_cmd_decode(const alink_message_head_t* msg, alink_gimbal_normal_cmd_t* gimbal_normal_cmd)
{
#if ALINK_NEED_BYTE_SWAP
	gimbal_normal_cmd->cmd = alink_msg_gimbal_normal_cmd_get_cmd(msg);
	gimbal_normal_cmd->data = alink_msg_gimbal_normal_cmd_get_data(msg);
#else
	memcpy(gimbal_normal_cmd, _MAV_PAYLOAD(msg), ALINK_MSG_ID_GIMBAL_NORMAL_CMD_LEN);
#endif
}
