// MESSAGE RC_CMD PACKING

#define ALINK_MSG_ID_RC_CMD 148

typedef struct __alink_rc_cmd_t
{
 uint16_t right_stick_h; /*< right stick h value*/
 uint16_t right_stick_v; /*< right stick v value*/
 uint16_t left_stick_h; /*< left stick h value*/
 uint16_t left_stick_v; /*< left stick v value*/
 uint16_t gimbal_pitch; /*< gimbal pitch value*/
 uint16_t general_key; /*< general key value*/
 uint16_t combined_key; /*< combined key value*/
} alink_rc_cmd_t;

#define ALINK_MSG_ID_RC_CMD_LEN 14
#define ALINK_MSG_ID_148_LEN 14

#define ALINK_MSG_ID_RC_CMD_CRC 237
#define ALINK_MSG_ID_148_CRC 237



#define ALINK_MESSAGE_INFO_RC_CMD { \
	"RC_CMD", \
	7, \
	{  { "right_stick_h", NULL, ALINK_TYPE_UINT16_T, 0, 0, offsetof(alink_rc_cmd_t, right_stick_h) }, \
         { "right_stick_v", NULL, ALINK_TYPE_UINT16_T, 0, 2, offsetof(alink_rc_cmd_t, right_stick_v) }, \
         { "left_stick_h", NULL, ALINK_TYPE_UINT16_T, 0, 4, offsetof(alink_rc_cmd_t, left_stick_h) }, \
         { "left_stick_v", NULL, ALINK_TYPE_UINT16_T, 0, 6, offsetof(alink_rc_cmd_t, left_stick_v) }, \
         { "gimbal_pitch", NULL, ALINK_TYPE_UINT16_T, 0, 8, offsetof(alink_rc_cmd_t, gimbal_pitch) }, \
         { "general_key", NULL, ALINK_TYPE_UINT16_T, 0, 10, offsetof(alink_rc_cmd_t, general_key) }, \
         { "combined_key", NULL, ALINK_TYPE_UINT16_T, 0, 12, offsetof(alink_rc_cmd_t, combined_key) }, \
         } \
}


/**
 * @brief Pack a rc_cmd message
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 *
 * @param right_stick_h right stick h value
 * @param right_stick_v right stick v value
 * @param left_stick_h left stick h value
 * @param left_stick_v left stick v value
 * @param gimbal_pitch gimbal pitch value
 * @param general_key general key value
 * @param combined_key combined key value
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_rc_cmd_pack(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg,
						       uint16_t right_stick_h, uint16_t right_stick_v, uint16_t left_stick_h, uint16_t left_stick_v, uint16_t gimbal_pitch, uint16_t general_key, uint16_t combined_key)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_RC_CMD_LEN];
	_mav_put_uint16_t(buf, 0, right_stick_h);
	_mav_put_uint16_t(buf, 2, right_stick_v);
	_mav_put_uint16_t(buf, 4, left_stick_h);
	_mav_put_uint16_t(buf, 6, left_stick_v);
	_mav_put_uint16_t(buf, 8, gimbal_pitch);
	_mav_put_uint16_t(buf, 10, general_key);
	_mav_put_uint16_t(buf, 12, combined_key);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_RC_CMD_LEN);
#else
	alink_rc_cmd_t packet;
	packet.right_stick_h = right_stick_h;
	packet.right_stick_v = right_stick_v;
	packet.left_stick_h = left_stick_h;
	packet.left_stick_v = left_stick_v;
	packet.gimbal_pitch = gimbal_pitch;
	packet.general_key = general_key;
	packet.combined_key = combined_key;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_RC_CMD_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_RC_CMD;
#if ALINK_CRC_EXTRA
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_RC_CMD_LEN,ALINK_MSG_ID_RC_CMD_CRC);
#else
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_RC_CMD_LEN);
#endif
}

/**
 * @brief Pack a rc_cmd message on a channel
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param right_stick_h right stick h value
 * @param right_stick_v right stick v value
 * @param left_stick_h left stick h value
 * @param left_stick_v left stick v value
 * @param gimbal_pitch gimbal pitch value
 * @param general_key general key value
 * @param combined_key combined key value
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_rc_cmd_pack_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan,
							   alink_message_head_t* msg,
						           uint16_t right_stick_h,uint16_t right_stick_v,uint16_t left_stick_h,uint16_t left_stick_v,uint16_t gimbal_pitch,uint16_t general_key,uint16_t combined_key)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_RC_CMD_LEN];
	_mav_put_uint16_t(buf, 0, right_stick_h);
	_mav_put_uint16_t(buf, 2, right_stick_v);
	_mav_put_uint16_t(buf, 4, left_stick_h);
	_mav_put_uint16_t(buf, 6, left_stick_v);
	_mav_put_uint16_t(buf, 8, gimbal_pitch);
	_mav_put_uint16_t(buf, 10, general_key);
	_mav_put_uint16_t(buf, 12, combined_key);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_RC_CMD_LEN);
#else
	alink_rc_cmd_t packet;
	packet.right_stick_h = right_stick_h;
	packet.right_stick_v = right_stick_v;
	packet.left_stick_h = left_stick_h;
	packet.left_stick_v = left_stick_v;
	packet.gimbal_pitch = gimbal_pitch;
	packet.general_key = general_key;
	packet.combined_key = combined_key;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_RC_CMD_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_RC_CMD;
#if ALINK_CRC_EXTRA
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_RC_CMD_LEN,ALINK_MSG_ID_RC_CMD_CRC);
#else
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_RC_CMD_LEN);
#endif
}
/**
 * @brief Encode a rc_cmd struct
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 * @param rc_cmd C-struct to read the message contents from
 */
static inline uint16_t alink_msg_rc_cmd_encode(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg, const alink_rc_cmd_t* rc_cmd)
{
	return alink_msg_rc_cmd_pack(dest_id, source_id, msg, rc_cmd->right_stick_h, rc_cmd->right_stick_v, rc_cmd->left_stick_h, rc_cmd->left_stick_v, rc_cmd->gimbal_pitch, rc_cmd->general_key, rc_cmd->combined_key);
}

/**
 * @brief Encode a rc_cmd struct on a channel
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param rc_cmd C-struct to read the message contents from
 */
static inline uint16_t alink_msg_rc_cmd_encode_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan, alink_message_head_t* msg, const alink_rc_cmd_t* rc_cmd)
{
	return alink_msg_rc_cmd_pack_chan(dest_id, source_id, chan, msg, rc_cmd->right_stick_h, rc_cmd->right_stick_v, rc_cmd->left_stick_h, rc_cmd->left_stick_v, rc_cmd->gimbal_pitch, rc_cmd->general_key, rc_cmd->combined_key);
}
// MESSAGE RC_CMD UNPACKING


/**
 * @brief Get field right_stick_h from rc_cmd message
 *
 * @return right stick h value
 */
static inline uint16_t alink_msg_rc_cmd_get_right_stick_h(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  0);
}

/**
 * @brief Get field right_stick_v from rc_cmd message
 *
 * @return right stick v value
 */
static inline uint16_t alink_msg_rc_cmd_get_right_stick_v(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  2);
}

/**
 * @brief Get field left_stick_h from rc_cmd message
 *
 * @return left stick h value
 */
static inline uint16_t alink_msg_rc_cmd_get_left_stick_h(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  4);
}

/**
 * @brief Get field left_stick_v from rc_cmd message
 *
 * @return left stick v value
 */
static inline uint16_t alink_msg_rc_cmd_get_left_stick_v(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  6);
}

/**
 * @brief Get field gimbal_pitch from rc_cmd message
 *
 * @return gimbal pitch value
 */
static inline uint16_t alink_msg_rc_cmd_get_gimbal_pitch(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  8);
}

/**
 * @brief Get field general_key from rc_cmd message
 *
 * @return general key value
 */
static inline uint16_t alink_msg_rc_cmd_get_general_key(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  10);
}

/**
 * @brief Get field combined_key from rc_cmd message
 *
 * @return combined key value
 */
static inline uint16_t alink_msg_rc_cmd_get_combined_key(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  12);
}

/**
 * @brief Decode a rc_cmd message into a struct
 *
 * @param msg The message to decode
 * @param rc_cmd C-struct to decode the message contents into
 */
static inline void alink_msg_rc_cmd_decode(const alink_message_head_t* msg, alink_rc_cmd_t* rc_cmd)
{
#if ALINK_NEED_BYTE_SWAP
	rc_cmd->right_stick_h = alink_msg_rc_cmd_get_right_stick_h(msg);
	rc_cmd->right_stick_v = alink_msg_rc_cmd_get_right_stick_v(msg);
	rc_cmd->left_stick_h = alink_msg_rc_cmd_get_left_stick_h(msg);
	rc_cmd->left_stick_v = alink_msg_rc_cmd_get_left_stick_v(msg);
	rc_cmd->gimbal_pitch = alink_msg_rc_cmd_get_gimbal_pitch(msg);
	rc_cmd->general_key = alink_msg_rc_cmd_get_general_key(msg);
	rc_cmd->combined_key = alink_msg_rc_cmd_get_combined_key(msg);
#else
	memcpy(rc_cmd, _MAV_PAYLOAD(msg), ALINK_MSG_ID_RC_CMD_LEN);
#endif
}
