// MESSAGE GIMBAL_CMD_FCS PACKING

#define ALINK_MSG_ID_GIMBAL_CMD_FCS 47

typedef struct __alink_gimbal_cmd_fcs_t
{
 uint32_t reserved1; /*< reserved1*/
 uint32_t reserved2; /*< reserved2*/
 uint32_t reserved3; /*< reserved3*/
 int16_t pitch_cmd; /*< pitch cmd in 10E2 degree*/
 int16_t roll_cmd; /*< roll cmd in 10E2 degree*/
 int16_t yaw_cmd; /*< yaw cmd in 10E2 degree*/
 uint8_t cmd_valid; /*< cmd valid for PITCH CMD, ROLL CMD and YAW CMD respectively by bit*/
} alink_gimbal_cmd_fcs_t;

#define ALINK_MSG_ID_GIMBAL_CMD_FCS_LEN 19
#define ALINK_MSG_ID_47_LEN 19

#define ALINK_MSG_ID_GIMBAL_CMD_FCS_CRC 51
#define ALINK_MSG_ID_47_CRC 51



#define ALINK_MESSAGE_INFO_GIMBAL_CMD_FCS { \
	"GIMBAL_CMD_FCS", \
	7, \
	{  { "reserved1", NULL, ALINK_TYPE_UINT32_T, 0, 0, offsetof(alink_gimbal_cmd_fcs_t, reserved1) }, \
         { "reserved2", NULL, ALINK_TYPE_UINT32_T, 0, 4, offsetof(alink_gimbal_cmd_fcs_t, reserved2) }, \
         { "reserved3", NULL, ALINK_TYPE_UINT32_T, 0, 8, offsetof(alink_gimbal_cmd_fcs_t, reserved3) }, \
         { "pitch_cmd", NULL, ALINK_TYPE_INT16_T, 0, 12, offsetof(alink_gimbal_cmd_fcs_t, pitch_cmd) }, \
         { "roll_cmd", NULL, ALINK_TYPE_INT16_T, 0, 14, offsetof(alink_gimbal_cmd_fcs_t, roll_cmd) }, \
         { "yaw_cmd", NULL, ALINK_TYPE_INT16_T, 0, 16, offsetof(alink_gimbal_cmd_fcs_t, yaw_cmd) }, \
         { "cmd_valid", NULL, ALINK_TYPE_UINT8_T, 0, 18, offsetof(alink_gimbal_cmd_fcs_t, cmd_valid) }, \
         } \
}


/**
 * @brief Pack a gimbal_cmd_fcs message
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 *
 * @param cmd_valid cmd valid for PITCH CMD, ROLL CMD and YAW CMD respectively by bit
 * @param pitch_cmd pitch cmd in 10E2 degree
 * @param roll_cmd roll cmd in 10E2 degree
 * @param yaw_cmd yaw cmd in 10E2 degree
 * @param reserved1 reserved1
 * @param reserved2 reserved2
 * @param reserved3 reserved3
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_gimbal_cmd_fcs_pack(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg,
						       uint8_t cmd_valid, int16_t pitch_cmd, int16_t roll_cmd, int16_t yaw_cmd, uint32_t reserved1, uint32_t reserved2, uint32_t reserved3)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_GIMBAL_CMD_FCS_LEN];
	_mav_put_uint32_t(buf, 0, reserved1);
	_mav_put_uint32_t(buf, 4, reserved2);
	_mav_put_uint32_t(buf, 8, reserved3);
	_mav_put_int16_t(buf, 12, pitch_cmd);
	_mav_put_int16_t(buf, 14, roll_cmd);
	_mav_put_int16_t(buf, 16, yaw_cmd);
	_mav_put_uint8_t(buf, 18, cmd_valid);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_GIMBAL_CMD_FCS_LEN);
#else
	alink_gimbal_cmd_fcs_t packet;
	packet.reserved1 = reserved1;
	packet.reserved2 = reserved2;
	packet.reserved3 = reserved3;
	packet.pitch_cmd = pitch_cmd;
	packet.roll_cmd = roll_cmd;
	packet.yaw_cmd = yaw_cmd;
	packet.cmd_valid = cmd_valid;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_GIMBAL_CMD_FCS_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_GIMBAL_CMD_FCS;
#if ALINK_CRC_EXTRA
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_GIMBAL_CMD_FCS_LEN,ALINK_MSG_ID_GIMBAL_CMD_FCS_CRC);
#else
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_GIMBAL_CMD_FCS_LEN);
#endif
}

/**
 * @brief Pack a gimbal_cmd_fcs message on a channel
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param cmd_valid cmd valid for PITCH CMD, ROLL CMD and YAW CMD respectively by bit
 * @param pitch_cmd pitch cmd in 10E2 degree
 * @param roll_cmd roll cmd in 10E2 degree
 * @param yaw_cmd yaw cmd in 10E2 degree
 * @param reserved1 reserved1
 * @param reserved2 reserved2
 * @param reserved3 reserved3
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_gimbal_cmd_fcs_pack_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan,
							   alink_message_head_t* msg,
						           uint8_t cmd_valid,int16_t pitch_cmd,int16_t roll_cmd,int16_t yaw_cmd,uint32_t reserved1,uint32_t reserved2,uint32_t reserved3)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_GIMBAL_CMD_FCS_LEN];
	_mav_put_uint32_t(buf, 0, reserved1);
	_mav_put_uint32_t(buf, 4, reserved2);
	_mav_put_uint32_t(buf, 8, reserved3);
	_mav_put_int16_t(buf, 12, pitch_cmd);
	_mav_put_int16_t(buf, 14, roll_cmd);
	_mav_put_int16_t(buf, 16, yaw_cmd);
	_mav_put_uint8_t(buf, 18, cmd_valid);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_GIMBAL_CMD_FCS_LEN);
#else
	alink_gimbal_cmd_fcs_t packet;
	packet.reserved1 = reserved1;
	packet.reserved2 = reserved2;
	packet.reserved3 = reserved3;
	packet.pitch_cmd = pitch_cmd;
	packet.roll_cmd = roll_cmd;
	packet.yaw_cmd = yaw_cmd;
	packet.cmd_valid = cmd_valid;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_GIMBAL_CMD_FCS_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_GIMBAL_CMD_FCS;
#if ALINK_CRC_EXTRA
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_GIMBAL_CMD_FCS_LEN,ALINK_MSG_ID_GIMBAL_CMD_FCS_CRC);
#else
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_GIMBAL_CMD_FCS_LEN);
#endif
}
/**
 * @brief Encode a gimbal_cmd_fcs struct
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 * @param gimbal_cmd_fcs C-struct to read the message contents from
 */
static inline uint16_t alink_msg_gimbal_cmd_fcs_encode(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg, const alink_gimbal_cmd_fcs_t* gimbal_cmd_fcs)
{
	return alink_msg_gimbal_cmd_fcs_pack(dest_id, source_id, msg, gimbal_cmd_fcs->cmd_valid, gimbal_cmd_fcs->pitch_cmd, gimbal_cmd_fcs->roll_cmd, gimbal_cmd_fcs->yaw_cmd, gimbal_cmd_fcs->reserved1, gimbal_cmd_fcs->reserved2, gimbal_cmd_fcs->reserved3);
}

/**
 * @brief Encode a gimbal_cmd_fcs struct on a channel
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param gimbal_cmd_fcs C-struct to read the message contents from
 */
static inline uint16_t alink_msg_gimbal_cmd_fcs_encode_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan, alink_message_head_t* msg, const alink_gimbal_cmd_fcs_t* gimbal_cmd_fcs)
{
	return alink_msg_gimbal_cmd_fcs_pack_chan(dest_id, source_id, chan, msg, gimbal_cmd_fcs->cmd_valid, gimbal_cmd_fcs->pitch_cmd, gimbal_cmd_fcs->roll_cmd, gimbal_cmd_fcs->yaw_cmd, gimbal_cmd_fcs->reserved1, gimbal_cmd_fcs->reserved2, gimbal_cmd_fcs->reserved3);
}
// MESSAGE GIMBAL_CMD_FCS UNPACKING


/**
 * @brief Get field cmd_valid from gimbal_cmd_fcs message
 *
 * @return cmd valid for PITCH CMD, ROLL CMD and YAW CMD respectively by bit
 */
static inline uint8_t alink_msg_gimbal_cmd_fcs_get_cmd_valid(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  18);
}

/**
 * @brief Get field pitch_cmd from gimbal_cmd_fcs message
 *
 * @return pitch cmd in 10E2 degree
 */
static inline int16_t alink_msg_gimbal_cmd_fcs_get_pitch_cmd(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  12);
}

/**
 * @brief Get field roll_cmd from gimbal_cmd_fcs message
 *
 * @return roll cmd in 10E2 degree
 */
static inline int16_t alink_msg_gimbal_cmd_fcs_get_roll_cmd(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  14);
}

/**
 * @brief Get field yaw_cmd from gimbal_cmd_fcs message
 *
 * @return yaw cmd in 10E2 degree
 */
static inline int16_t alink_msg_gimbal_cmd_fcs_get_yaw_cmd(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  16);
}

/**
 * @brief Get field reserved1 from gimbal_cmd_fcs message
 *
 * @return reserved1
 */
static inline uint32_t alink_msg_gimbal_cmd_fcs_get_reserved1(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field reserved2 from gimbal_cmd_fcs message
 *
 * @return reserved2
 */
static inline uint32_t alink_msg_gimbal_cmd_fcs_get_reserved2(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint32_t(msg,  4);
}

/**
 * @brief Get field reserved3 from gimbal_cmd_fcs message
 *
 * @return reserved3
 */
static inline uint32_t alink_msg_gimbal_cmd_fcs_get_reserved3(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint32_t(msg,  8);
}

/**
 * @brief Decode a gimbal_cmd_fcs message into a struct
 *
 * @param msg The message to decode
 * @param gimbal_cmd_fcs C-struct to decode the message contents into
 */
static inline void alink_msg_gimbal_cmd_fcs_decode(const alink_message_head_t* msg, alink_gimbal_cmd_fcs_t* gimbal_cmd_fcs)
{
#if ALINK_NEED_BYTE_SWAP
	gimbal_cmd_fcs->reserved1 = alink_msg_gimbal_cmd_fcs_get_reserved1(msg);
	gimbal_cmd_fcs->reserved2 = alink_msg_gimbal_cmd_fcs_get_reserved2(msg);
	gimbal_cmd_fcs->reserved3 = alink_msg_gimbal_cmd_fcs_get_reserved3(msg);
	gimbal_cmd_fcs->pitch_cmd = alink_msg_gimbal_cmd_fcs_get_pitch_cmd(msg);
	gimbal_cmd_fcs->roll_cmd = alink_msg_gimbal_cmd_fcs_get_roll_cmd(msg);
	gimbal_cmd_fcs->yaw_cmd = alink_msg_gimbal_cmd_fcs_get_yaw_cmd(msg);
	gimbal_cmd_fcs->cmd_valid = alink_msg_gimbal_cmd_fcs_get_cmd_valid(msg);
#else
	memcpy(gimbal_cmd_fcs, _MAV_PAYLOAD(msg), ALINK_MSG_ID_GIMBAL_CMD_FCS_LEN);
#endif
}
