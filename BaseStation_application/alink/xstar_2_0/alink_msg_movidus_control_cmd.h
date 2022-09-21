// MESSAGE MOVIDUS_CONTROL_CMD PACKING

#define ALINK_MSG_ID_MOVIDUS_CONTROL_CMD 115

typedef struct __alink_movidus_control_cmd_t
{
 uint32_t timestamp; /*< timestamp (milliseconds since system boot)*/
 int16_t ctrl_cmd[4]; /*<  ctrl_mode=1: roll angle(in 10E-3 rad)/pitch angle(in 10E-3 rad)/yaw rate(in 10E-3 rad/s)/Normalized thrust command [0,1] Float to int16 scale is 1000
                                                          ctrl_mode=2: roll angle(in 10E-3 rad)/pitch angle(in 10E-3 rad)/yaw rate(in 10E-3 rad/s)/vertical velocity command(in 10E-3 m/s),positive is upward direction Float to int16 scale is 1000
                                                          ctrl_mode=3: forward/backward body-level velocity command(in 10E-3 m/s).Positive is relative to forward direction of vehicle.
                                                                       left/right body-level velocity command(in 10E-3 m/s). Positive is relative to right direction of vehicle
                                                                       vertical velocity(in 10E-3 m/s). Positive is Down direction
                                                                       yaw rate command(in 10E-3 rad/s) Float to int16 scale is 1000*/
 uint8_t ctrl_mode; /*<  0 - Nothing, 1 for thrust; 2 for att; 3 for vel */
} alink_movidus_control_cmd_t;

#define ALINK_MSG_ID_MOVIDUS_CONTROL_CMD_LEN 13
#define ALINK_MSG_ID_115_LEN 13

#define ALINK_MSG_ID_MOVIDUS_CONTROL_CMD_CRC 0
#define ALINK_MSG_ID_115_CRC 0

#define ALINK_MSG_MOVIDUS_CONTROL_CMD_FIELD_CTRL_CMD_LEN 4

#define ALINK_MESSAGE_INFO_MOVIDUS_CONTROL_CMD { \
	"MOVIDUS_CONTROL_CMD", \
	3, \
	{  { "timestamp", NULL, ALINK_TYPE_UINT32_T, 0, 0, offsetof(alink_movidus_control_cmd_t, timestamp) }, \
         { "ctrl_cmd", NULL, ALINK_TYPE_INT16_T, 4, 4, offsetof(alink_movidus_control_cmd_t, ctrl_cmd) }, \
         { "ctrl_mode", NULL, ALINK_TYPE_UINT8_T, 0, 12, offsetof(alink_movidus_control_cmd_t, ctrl_mode) }, \
         } \
}


/**
 * @brief Pack a movidus_control_cmd message
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 *
 * @param timestamp timestamp (milliseconds since system boot)
 * @param ctrl_mode  0 - Nothing, 1 for thrust; 2 for att; 3 for vel 
 * @param ctrl_cmd  ctrl_mode=1: roll angle(in 10E-3 rad)/pitch angle(in 10E-3 rad)/yaw rate(in 10E-3 rad/s)/Normalized thrust command [0,1] Float to int16 scale is 1000
                                                          ctrl_mode=2: roll angle(in 10E-3 rad)/pitch angle(in 10E-3 rad)/yaw rate(in 10E-3 rad/s)/vertical velocity command(in 10E-3 m/s),positive is upward direction Float to int16 scale is 1000
                                                          ctrl_mode=3: forward/backward body-level velocity command(in 10E-3 m/s).Positive is relative to forward direction of vehicle.
                                                                       left/right body-level velocity command(in 10E-3 m/s). Positive is relative to right direction of vehicle
                                                                       vertical velocity(in 10E-3 m/s). Positive is Down direction
                                                                       yaw rate command(in 10E-3 rad/s) Float to int16 scale is 1000
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_movidus_control_cmd_pack(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg,
						       uint32_t timestamp, uint8_t ctrl_mode, const int16_t *ctrl_cmd)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_MOVIDUS_CONTROL_CMD_LEN];
	_mav_put_uint32_t(buf, 0, timestamp);
	_mav_put_uint8_t(buf, 12, ctrl_mode);
	_mav_put_int16_t_array(buf, 4, ctrl_cmd, 4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_MOVIDUS_CONTROL_CMD_LEN);
#else
	alink_movidus_control_cmd_t packet;
	packet.timestamp = timestamp;
	packet.ctrl_mode = ctrl_mode;
	mav_array_memcpy(packet.ctrl_cmd, ctrl_cmd, sizeof(int16_t)*4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_MOVIDUS_CONTROL_CMD_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_MOVIDUS_CONTROL_CMD;
#if ALINK_CRC_EXTRA
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_MOVIDUS_CONTROL_CMD_LEN,ALINK_MSG_ID_MOVIDUS_CONTROL_CMD_CRC);
#else
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_MOVIDUS_CONTROL_CMD_LEN);
#endif
}

/**
 * @brief Pack a movidus_control_cmd message on a channel
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param timestamp timestamp (milliseconds since system boot)
 * @param ctrl_mode  0 - Nothing, 1 for thrust; 2 for att; 3 for vel 
 * @param ctrl_cmd  ctrl_mode=1: roll angle(in 10E-3 rad)/pitch angle(in 10E-3 rad)/yaw rate(in 10E-3 rad/s)/Normalized thrust command [0,1] Float to int16 scale is 1000
                                                          ctrl_mode=2: roll angle(in 10E-3 rad)/pitch angle(in 10E-3 rad)/yaw rate(in 10E-3 rad/s)/vertical velocity command(in 10E-3 m/s),positive is upward direction Float to int16 scale is 1000
                                                          ctrl_mode=3: forward/backward body-level velocity command(in 10E-3 m/s).Positive is relative to forward direction of vehicle.
                                                                       left/right body-level velocity command(in 10E-3 m/s). Positive is relative to right direction of vehicle
                                                                       vertical velocity(in 10E-3 m/s). Positive is Down direction
                                                                       yaw rate command(in 10E-3 rad/s) Float to int16 scale is 1000
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_movidus_control_cmd_pack_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan,
							   alink_message_head_t* msg,
						           uint32_t timestamp,uint8_t ctrl_mode,const int16_t *ctrl_cmd)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_MOVIDUS_CONTROL_CMD_LEN];
	_mav_put_uint32_t(buf, 0, timestamp);
	_mav_put_uint8_t(buf, 12, ctrl_mode);
	_mav_put_int16_t_array(buf, 4, ctrl_cmd, 4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_MOVIDUS_CONTROL_CMD_LEN);
#else
	alink_movidus_control_cmd_t packet;
	packet.timestamp = timestamp;
	packet.ctrl_mode = ctrl_mode;
	mav_array_memcpy(packet.ctrl_cmd, ctrl_cmd, sizeof(int16_t)*4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_MOVIDUS_CONTROL_CMD_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_MOVIDUS_CONTROL_CMD;
#if ALINK_CRC_EXTRA
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_MOVIDUS_CONTROL_CMD_LEN,ALINK_MSG_ID_MOVIDUS_CONTROL_CMD_CRC);
#else
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_MOVIDUS_CONTROL_CMD_LEN);
#endif
}
/**
 * @brief Encode a movidus_control_cmd struct
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 * @param movidus_control_cmd C-struct to read the message contents from
 */
static inline uint16_t alink_msg_movidus_control_cmd_encode(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg, const alink_movidus_control_cmd_t* movidus_control_cmd)
{
	return alink_msg_movidus_control_cmd_pack(dest_id, source_id, msg, movidus_control_cmd->timestamp, movidus_control_cmd->ctrl_mode, movidus_control_cmd->ctrl_cmd);
}

/**
 * @brief Encode a movidus_control_cmd struct on a channel
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param movidus_control_cmd C-struct to read the message contents from
 */
static inline uint16_t alink_msg_movidus_control_cmd_encode_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan, alink_message_head_t* msg, const alink_movidus_control_cmd_t* movidus_control_cmd)
{
	return alink_msg_movidus_control_cmd_pack_chan(dest_id, source_id, chan, msg, movidus_control_cmd->timestamp, movidus_control_cmd->ctrl_mode, movidus_control_cmd->ctrl_cmd);
}
// MESSAGE MOVIDUS_CONTROL_CMD UNPACKING


/**
 * @brief Get field timestamp from movidus_control_cmd message
 *
 * @return timestamp (milliseconds since system boot)
 */
static inline uint32_t alink_msg_movidus_control_cmd_get_timestamp(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field ctrl_mode from movidus_control_cmd message
 *
 * @return  0 - Nothing, 1 for thrust; 2 for att; 3 for vel 
 */
static inline uint8_t alink_msg_movidus_control_cmd_get_ctrl_mode(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  12);
}

/**
 * @brief Get field ctrl_cmd from movidus_control_cmd message
 *
 * @return  ctrl_mode=1: roll angle(in 10E-3 rad)/pitch angle(in 10E-3 rad)/yaw rate(in 10E-3 rad/s)/Normalized thrust command [0,1] Float to int16 scale is 1000
                                                          ctrl_mode=2: roll angle(in 10E-3 rad)/pitch angle(in 10E-3 rad)/yaw rate(in 10E-3 rad/s)/vertical velocity command(in 10E-3 m/s),positive is upward direction Float to int16 scale is 1000
                                                          ctrl_mode=3: forward/backward body-level velocity command(in 10E-3 m/s).Positive is relative to forward direction of vehicle.
                                                                       left/right body-level velocity command(in 10E-3 m/s). Positive is relative to right direction of vehicle
                                                                       vertical velocity(in 10E-3 m/s). Positive is Down direction
                                                                       yaw rate command(in 10E-3 rad/s) Float to int16 scale is 1000
 */
static inline uint16_t alink_msg_movidus_control_cmd_get_ctrl_cmd(const alink_message_head_t* msg, int16_t *ctrl_cmd)
{
	return _MAV_RETURN_int16_t_array(msg, ctrl_cmd, 4,  4);
}

/**
 * @brief Decode a movidus_control_cmd message into a struct
 *
 * @param msg The message to decode
 * @param movidus_control_cmd C-struct to decode the message contents into
 */
static inline void alink_msg_movidus_control_cmd_decode(const alink_message_head_t* msg, alink_movidus_control_cmd_t* movidus_control_cmd)
{
#if ALINK_NEED_BYTE_SWAP
	movidus_control_cmd->timestamp = alink_msg_movidus_control_cmd_get_timestamp(msg);
	alink_msg_movidus_control_cmd_get_ctrl_cmd(msg, movidus_control_cmd->ctrl_cmd);
	movidus_control_cmd->ctrl_mode = alink_msg_movidus_control_cmd_get_ctrl_mode(msg);
#else
	memcpy(movidus_control_cmd, _MAV_PAYLOAD(msg), ALINK_MSG_ID_MOVIDUS_CONTROL_CMD_LEN);
#endif
}
