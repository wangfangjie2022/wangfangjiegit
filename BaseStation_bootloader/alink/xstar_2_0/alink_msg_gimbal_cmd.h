// MESSAGE GIMBAL_CMD PACKING

#define ALINK_MSG_ID_GIMBAL_CMD 57

typedef struct __alink_gimbal_cmd_t
{
 int32_t data[4]; /*< params*/
 uint8_t cmd; /*< cmd 0x01 - PUSH_GIMBAL_ANGLES, 0x02 - GET_GIMBAL_ANGLES_RANGE, 0x03 - CMD_GET_WORK_MODE , 0x04 - CMD_SET_WORK_MODE */
} alink_gimbal_cmd_t;

#define ALINK_MSG_ID_GIMBAL_CMD_LEN 17
#define ALINK_MSG_ID_57_LEN 17

#define ALINK_MSG_ID_GIMBAL_CMD_CRC 7
#define ALINK_MSG_ID_57_CRC 7

#define ALINK_MSG_GIMBAL_CMD_FIELD_DATA_LEN 4

#define ALINK_MESSAGE_INFO_GIMBAL_CMD { \
	"GIMBAL_CMD", \
	2, \
	{  { "data", NULL, ALINK_TYPE_INT32_T, 4, 0, offsetof(alink_gimbal_cmd_t, data) }, \
         { "cmd", NULL, ALINK_TYPE_UINT8_T, 0, 16, offsetof(alink_gimbal_cmd_t, cmd) }, \
         } \
}


/**
 * @brief Pack a gimbal_cmd message
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 *
 * @param cmd cmd 0x01 - PUSH_GIMBAL_ANGLES, 0x02 - GET_GIMBAL_ANGLES_RANGE, 0x03 - CMD_GET_WORK_MODE , 0x04 - CMD_SET_WORK_MODE 
 * @param data params
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_gimbal_cmd_pack(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg,
						       uint8_t cmd, const int32_t *data)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_GIMBAL_CMD_LEN];
	_mav_put_uint8_t(buf, 16, cmd);
	_mav_put_int32_t_array(buf, 0, data, 4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_GIMBAL_CMD_LEN);
#else
	alink_gimbal_cmd_t packet;
	packet.cmd = cmd;
	mav_array_memcpy(packet.data, data, sizeof(int32_t)*4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_GIMBAL_CMD_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_GIMBAL_CMD;
#if ALINK_CRC_EXTRA
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_GIMBAL_CMD_LEN,ALINK_MSG_ID_GIMBAL_CMD_CRC);
#else
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_GIMBAL_CMD_LEN);
#endif
}

/**
 * @brief Pack a gimbal_cmd message on a channel
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param cmd cmd 0x01 - PUSH_GIMBAL_ANGLES, 0x02 - GET_GIMBAL_ANGLES_RANGE, 0x03 - CMD_GET_WORK_MODE , 0x04 - CMD_SET_WORK_MODE 
 * @param data params
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_gimbal_cmd_pack_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan,
							   alink_message_head_t* msg,
						           uint8_t cmd,const int32_t *data)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_GIMBAL_CMD_LEN];
	_mav_put_uint8_t(buf, 16, cmd);
	_mav_put_int32_t_array(buf, 0, data, 4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_GIMBAL_CMD_LEN);
#else
	alink_gimbal_cmd_t packet;
	packet.cmd = cmd;
	mav_array_memcpy(packet.data, data, sizeof(int32_t)*4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_GIMBAL_CMD_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_GIMBAL_CMD;
#if ALINK_CRC_EXTRA
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_GIMBAL_CMD_LEN,ALINK_MSG_ID_GIMBAL_CMD_CRC);
#else
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_GIMBAL_CMD_LEN);
#endif
}
/**
 * @brief Encode a gimbal_cmd struct
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 * @param gimbal_cmd C-struct to read the message contents from
 */
static inline uint16_t alink_msg_gimbal_cmd_encode(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg, const alink_gimbal_cmd_t* gimbal_cmd)
{
	return alink_msg_gimbal_cmd_pack(dest_id, source_id, msg, gimbal_cmd->cmd, gimbal_cmd->data);
}

/**
 * @brief Encode a gimbal_cmd struct on a channel
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param gimbal_cmd C-struct to read the message contents from
 */
static inline uint16_t alink_msg_gimbal_cmd_encode_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan, alink_message_head_t* msg, const alink_gimbal_cmd_t* gimbal_cmd)
{
	return alink_msg_gimbal_cmd_pack_chan(dest_id, source_id, chan, msg, gimbal_cmd->cmd, gimbal_cmd->data);
}
// MESSAGE GIMBAL_CMD UNPACKING


/**
 * @brief Get field cmd from gimbal_cmd message
 *
 * @return cmd 0x01 - PUSH_GIMBAL_ANGLES, 0x02 - GET_GIMBAL_ANGLES_RANGE, 0x03 - CMD_GET_WORK_MODE , 0x04 - CMD_SET_WORK_MODE 
 */
static inline uint8_t alink_msg_gimbal_cmd_get_cmd(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  16);
}

/**
 * @brief Get field data from gimbal_cmd message
 *
 * @return params
 */
static inline uint16_t alink_msg_gimbal_cmd_get_data(const alink_message_head_t* msg, int32_t *data)
{
	return _MAV_RETURN_int32_t_array(msg, data, 4,  0);
}

/**
 * @brief Decode a gimbal_cmd message into a struct
 *
 * @param msg The message to decode
 * @param gimbal_cmd C-struct to decode the message contents into
 */
static inline void alink_msg_gimbal_cmd_decode(const alink_message_head_t* msg, alink_gimbal_cmd_t* gimbal_cmd)
{
#if ALINK_NEED_BYTE_SWAP
	alink_msg_gimbal_cmd_get_data(msg, gimbal_cmd->data);
	gimbal_cmd->cmd = alink_msg_gimbal_cmd_get_cmd(msg);
#else
	memcpy(gimbal_cmd, _MAV_PAYLOAD(msg), ALINK_MSG_ID_GIMBAL_CMD_LEN);
#endif
}
