// MESSAGE RC_NORMAL_CMD PACKING

#define ALINK_MSG_ID_RC_NORMAL_CMD 147

typedef struct __alink_rc_normal_cmd_t
{
 uint8_t cmd; /*< 命令类型.*/
 char data[511]; /*< Payload data bytes.*/
} alink_rc_normal_cmd_t;

#define ALINK_MSG_ID_RC_NORMAL_CMD_LEN 512
#define ALINK_MSG_ID_147_LEN 512

#define ALINK_MSG_ID_RC_NORMAL_CMD_CRC 138
#define ALINK_MSG_ID_147_CRC 138

#define ALINK_MSG_RC_NORMAL_CMD_FIELD_DATA_LEN 511

#define ALINK_MESSAGE_INFO_RC_NORMAL_CMD { \
	"RC_NORMAL_CMD", \
	2, \
	{  { "cmd", NULL, ALINK_TYPE_UINT8_T, 0, 0, offsetof(alink_rc_normal_cmd_t, cmd) }, \
         { "data", NULL, ALINK_TYPE_CHAR, 511, 1, offsetof(alink_rc_normal_cmd_t, data) }, \
         } \
}


/**
 * @brief Pack a rc_normal_cmd message
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 *
 * @param cmd 命令类型.
 * @param data Payload data bytes.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_rc_normal_cmd_pack(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg,
						       uint8_t cmd, const char *data)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_RC_NORMAL_CMD_LEN];
	_mav_put_uint8_t(buf, 0, cmd);
	_mav_put_char_array(buf, 1, data, 511);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_RC_NORMAL_CMD_LEN);
#else
	alink_rc_normal_cmd_t packet;
	packet.cmd = cmd;
	mav_array_memcpy(packet.data, data, sizeof(char)*511);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_RC_NORMAL_CMD_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_RC_NORMAL_CMD;
#if ALINK_CRC_EXTRA
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_RC_NORMAL_CMD_LEN,ALINK_MSG_ID_RC_NORMAL_CMD_CRC);
#else
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_RC_NORMAL_CMD_LEN);
#endif
}

/**
 * @brief Pack a rc_normal_cmd message on a channel
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param cmd 命令类型.
 * @param data Payload data bytes.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_rc_normal_cmd_pack_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan,
							   alink_message_head_t* msg,
						           uint8_t cmd,const char *data)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_RC_NORMAL_CMD_LEN];
	_mav_put_uint8_t(buf, 0, cmd);
	_mav_put_char_array(buf, 1, data, 511);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_RC_NORMAL_CMD_LEN);
#else
	alink_rc_normal_cmd_t packet;
	packet.cmd = cmd;
	mav_array_memcpy(packet.data, data, sizeof(char)*511);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_RC_NORMAL_CMD_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_RC_NORMAL_CMD;
#if ALINK_CRC_EXTRA
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_RC_NORMAL_CMD_LEN,ALINK_MSG_ID_RC_NORMAL_CMD_CRC);
#else
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_RC_NORMAL_CMD_LEN);
#endif
}
/**
 * @brief Encode a rc_normal_cmd struct
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 * @param rc_normal_cmd C-struct to read the message contents from
 */
static inline uint16_t alink_msg_rc_normal_cmd_encode(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg, const alink_rc_normal_cmd_t* rc_normal_cmd)
{
	return alink_msg_rc_normal_cmd_pack(dest_id, source_id, msg, rc_normal_cmd->cmd, rc_normal_cmd->data);
}

/**
 * @brief Encode a rc_normal_cmd struct on a channel
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param rc_normal_cmd C-struct to read the message contents from
 */
static inline uint16_t alink_msg_rc_normal_cmd_encode_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan, alink_message_head_t* msg, const alink_rc_normal_cmd_t* rc_normal_cmd)
{
	return alink_msg_rc_normal_cmd_pack_chan(dest_id, source_id, chan, msg, rc_normal_cmd->cmd, rc_normal_cmd->data);
}
// MESSAGE RC_NORMAL_CMD UNPACKING


/**
 * @brief Get field cmd from rc_normal_cmd message
 *
 * @return 命令类型.
 */
static inline uint8_t alink_msg_rc_normal_cmd_get_cmd(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field data from rc_normal_cmd message
 *
 * @return Payload data bytes.
 */
static inline uint16_t alink_msg_rc_normal_cmd_get_data(const alink_message_head_t* msg, char *data)
{
	return _MAV_RETURN_char_array(msg, data, 511,  1);
}

/**
 * @brief Decode a rc_normal_cmd message into a struct
 *
 * @param msg The message to decode
 * @param rc_normal_cmd C-struct to decode the message contents into
 */
static inline void alink_msg_rc_normal_cmd_decode(const alink_message_head_t* msg, alink_rc_normal_cmd_t* rc_normal_cmd)
{
#if ALINK_NEED_BYTE_SWAP
	rc_normal_cmd->cmd = alink_msg_rc_normal_cmd_get_cmd(msg);
	alink_msg_rc_normal_cmd_get_data(msg, rc_normal_cmd->data);
#else
	memcpy(rc_normal_cmd, _MAV_PAYLOAD(msg), ALINK_MSG_ID_RC_NORMAL_CMD_LEN);
#endif
}
