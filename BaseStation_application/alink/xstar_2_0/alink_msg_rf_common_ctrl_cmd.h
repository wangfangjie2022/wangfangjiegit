// MESSAGE RF_COMMON_CTRL_CMD PACKING

#define ALINK_MSG_ID_RF_COMMON_CTRL_CMD 135

typedef struct __alink_rf_common_ctrl_cmd_t
{
 char cmd; /*< Cmd/操作命令，0-获取，1-设置，2-重置.*/
 char ret_value; /*< Ret/执行结果，0-成功，1-失败，2-无效命令 .*/
 char data[64]; /*< 数据信息.*/
} alink_rf_common_ctrl_cmd_t;

#define ALINK_MSG_ID_RF_COMMON_CTRL_CMD_LEN 66
#define ALINK_MSG_ID_135_LEN 66

#define ALINK_MSG_ID_RF_COMMON_CTRL_CMD_CRC 250
#define ALINK_MSG_ID_135_CRC 250

#define ALINK_MSG_RF_COMMON_CTRL_CMD_FIELD_DATA_LEN 64

#define ALINK_MESSAGE_INFO_RF_COMMON_CTRL_CMD { \
	"RF_COMMON_CTRL_CMD", \
	3, \
	{  { "cmd", NULL, ALINK_TYPE_CHAR, 0, 0, offsetof(alink_rf_common_ctrl_cmd_t, cmd) }, \
         { "ret_value", NULL, ALINK_TYPE_CHAR, 0, 1, offsetof(alink_rf_common_ctrl_cmd_t, ret_value) }, \
         { "data", NULL, ALINK_TYPE_CHAR, 64, 2, offsetof(alink_rf_common_ctrl_cmd_t, data) }, \
         } \
}


/**
 * @brief Pack a rf_common_ctrl_cmd message
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 *
 * @param cmd Cmd/操作命令，0-获取，1-设置，2-重置.
 * @param ret_value Ret/执行结果，0-成功，1-失败，2-无效命令 .
 * @param data 数据信息.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_rf_common_ctrl_cmd_pack(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg,
						       char cmd, char ret_value, const char *data)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_RF_COMMON_CTRL_CMD_LEN];
	_mav_put_char(buf, 0, cmd);
	_mav_put_char(buf, 1, ret_value);
	_mav_put_char_array(buf, 2, data, 64);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_RF_COMMON_CTRL_CMD_LEN);
#else
	alink_rf_common_ctrl_cmd_t packet;
	packet.cmd = cmd;
	packet.ret_value = ret_value;
	mav_array_memcpy(packet.data, data, sizeof(char)*64);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_RF_COMMON_CTRL_CMD_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_RF_COMMON_CTRL_CMD;
#if ALINK_CRC_EXTRA
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_RF_COMMON_CTRL_CMD_LEN,ALINK_MSG_ID_RF_COMMON_CTRL_CMD_CRC);
#else
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_RF_COMMON_CTRL_CMD_LEN);
#endif
}

/**
 * @brief Pack a rf_common_ctrl_cmd message on a channel
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param cmd Cmd/操作命令，0-获取，1-设置，2-重置.
 * @param ret_value Ret/执行结果，0-成功，1-失败，2-无效命令 .
 * @param data 数据信息.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_rf_common_ctrl_cmd_pack_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan,
							   alink_message_head_t* msg,
						           char cmd,char ret_value,const char *data)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_RF_COMMON_CTRL_CMD_LEN];
	_mav_put_char(buf, 0, cmd);
	_mav_put_char(buf, 1, ret_value);
	_mav_put_char_array(buf, 2, data, 64);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_RF_COMMON_CTRL_CMD_LEN);
#else
	alink_rf_common_ctrl_cmd_t packet;
	packet.cmd = cmd;
	packet.ret_value = ret_value;
	mav_array_memcpy(packet.data, data, sizeof(char)*64);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_RF_COMMON_CTRL_CMD_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_RF_COMMON_CTRL_CMD;
#if ALINK_CRC_EXTRA
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_RF_COMMON_CTRL_CMD_LEN,ALINK_MSG_ID_RF_COMMON_CTRL_CMD_CRC);
#else
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_RF_COMMON_CTRL_CMD_LEN);
#endif
}
/**
 * @brief Encode a rf_common_ctrl_cmd struct
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 * @param rf_common_ctrl_cmd C-struct to read the message contents from
 */
static inline uint16_t alink_msg_rf_common_ctrl_cmd_encode(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg, const alink_rf_common_ctrl_cmd_t* rf_common_ctrl_cmd)
{
	return alink_msg_rf_common_ctrl_cmd_pack(dest_id, source_id, msg, rf_common_ctrl_cmd->cmd, rf_common_ctrl_cmd->ret_value, rf_common_ctrl_cmd->data);
}

/**
 * @brief Encode a rf_common_ctrl_cmd struct on a channel
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param rf_common_ctrl_cmd C-struct to read the message contents from
 */
static inline uint16_t alink_msg_rf_common_ctrl_cmd_encode_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan, alink_message_head_t* msg, const alink_rf_common_ctrl_cmd_t* rf_common_ctrl_cmd)
{
	return alink_msg_rf_common_ctrl_cmd_pack_chan(dest_id, source_id, chan, msg, rf_common_ctrl_cmd->cmd, rf_common_ctrl_cmd->ret_value, rf_common_ctrl_cmd->data);
}
// MESSAGE RF_COMMON_CTRL_CMD UNPACKING


/**
 * @brief Get field cmd from rf_common_ctrl_cmd message
 *
 * @return Cmd/操作命令，0-获取，1-设置，2-重置.
 */
static inline char alink_msg_rf_common_ctrl_cmd_get_cmd(const alink_message_head_t* msg)
{
	return _MAV_RETURN_char(msg,  0);
}

/**
 * @brief Get field ret_value from rf_common_ctrl_cmd message
 *
 * @return Ret/执行结果，0-成功，1-失败，2-无效命令 .
 */
static inline char alink_msg_rf_common_ctrl_cmd_get_ret_value(const alink_message_head_t* msg)
{
	return _MAV_RETURN_char(msg,  1);
}

/**
 * @brief Get field data from rf_common_ctrl_cmd message
 *
 * @return 数据信息.
 */
static inline uint16_t alink_msg_rf_common_ctrl_cmd_get_data(const alink_message_head_t* msg, char *data)
{
	return _MAV_RETURN_char_array(msg, data, 64,  2);
}

/**
 * @brief Decode a rf_common_ctrl_cmd message into a struct
 *
 * @param msg The message to decode
 * @param rf_common_ctrl_cmd C-struct to decode the message contents into
 */
static inline void alink_msg_rf_common_ctrl_cmd_decode(const alink_message_head_t* msg, alink_rf_common_ctrl_cmd_t* rf_common_ctrl_cmd)
{
#if ALINK_NEED_BYTE_SWAP
	rf_common_ctrl_cmd->cmd = alink_msg_rf_common_ctrl_cmd_get_cmd(msg);
	rf_common_ctrl_cmd->ret_value = alink_msg_rf_common_ctrl_cmd_get_ret_value(msg);
	alink_msg_rf_common_ctrl_cmd_get_data(msg, rf_common_ctrl_cmd->data);
#else
	memcpy(rf_common_ctrl_cmd, _MAV_PAYLOAD(msg), ALINK_MSG_ID_RF_COMMON_CTRL_CMD_LEN);
#endif
}
