// MESSAGE FCS_TRACK_CMD PACKING

#define ALINK_MSG_ID_FCS_TRACK_CMD 98

typedef struct __alink_fcs_track_cmd_t
{
 uint32_t timestamp; /*< timestamp*/
 float fsc_cmd[4]; /*< fsc command*/
 uint8_t valid; /*< valid*/
} alink_fcs_track_cmd_t;

#define ALINK_MSG_ID_FCS_TRACK_CMD_LEN 21
#define ALINK_MSG_ID_98_LEN 21

#define ALINK_MSG_ID_FCS_TRACK_CMD_CRC 54
#define ALINK_MSG_ID_98_CRC 54

#define ALINK_MSG_FCS_TRACK_CMD_FIELD_FSC_CMD_LEN 4

#define ALINK_MESSAGE_INFO_FCS_TRACK_CMD { \
	"FCS_TRACK_CMD", \
	3, \
	{  { "timestamp", NULL, ALINK_TYPE_UINT32_T, 0, 0, offsetof(alink_fcs_track_cmd_t, timestamp) }, \
         { "fsc_cmd", NULL, ALINK_TYPE_FLOAT, 4, 4, offsetof(alink_fcs_track_cmd_t, fsc_cmd) }, \
         { "valid", NULL, ALINK_TYPE_UINT8_T, 0, 20, offsetof(alink_fcs_track_cmd_t, valid) }, \
         } \
}


/**
 * @brief Pack a fcs_track_cmd message
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 *
 * @param timestamp timestamp
 * @param fsc_cmd fsc command
 * @param valid valid
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_fcs_track_cmd_pack(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg,
						       uint32_t timestamp, const float *fsc_cmd, uint8_t valid)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_FCS_TRACK_CMD_LEN];
	_mav_put_uint32_t(buf, 0, timestamp);
	_mav_put_uint8_t(buf, 20, valid);
	_mav_put_float_array(buf, 4, fsc_cmd, 4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_FCS_TRACK_CMD_LEN);
#else
	alink_fcs_track_cmd_t packet;
	packet.timestamp = timestamp;
	packet.valid = valid;
	mav_array_memcpy(packet.fsc_cmd, fsc_cmd, sizeof(float)*4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_FCS_TRACK_CMD_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_FCS_TRACK_CMD;
#if ALINK_CRC_EXTRA
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_FCS_TRACK_CMD_LEN,ALINK_MSG_ID_FCS_TRACK_CMD_CRC);
#else
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_FCS_TRACK_CMD_LEN);
#endif
}

/**
 * @brief Pack a fcs_track_cmd message on a channel
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param timestamp timestamp
 * @param fsc_cmd fsc command
 * @param valid valid
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_fcs_track_cmd_pack_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan,
							   alink_message_head_t* msg,
						           uint32_t timestamp,const float *fsc_cmd,uint8_t valid)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_FCS_TRACK_CMD_LEN];
	_mav_put_uint32_t(buf, 0, timestamp);
	_mav_put_uint8_t(buf, 20, valid);
	_mav_put_float_array(buf, 4, fsc_cmd, 4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_FCS_TRACK_CMD_LEN);
#else
	alink_fcs_track_cmd_t packet;
	packet.timestamp = timestamp;
	packet.valid = valid;
	mav_array_memcpy(packet.fsc_cmd, fsc_cmd, sizeof(float)*4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_FCS_TRACK_CMD_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_FCS_TRACK_CMD;
#if ALINK_CRC_EXTRA
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_FCS_TRACK_CMD_LEN,ALINK_MSG_ID_FCS_TRACK_CMD_CRC);
#else
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_FCS_TRACK_CMD_LEN);
#endif
}
/**
 * @brief Encode a fcs_track_cmd struct
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 * @param fcs_track_cmd C-struct to read the message contents from
 */
static inline uint16_t alink_msg_fcs_track_cmd_encode(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg, const alink_fcs_track_cmd_t* fcs_track_cmd)
{
	return alink_msg_fcs_track_cmd_pack(dest_id, source_id, msg, fcs_track_cmd->timestamp, fcs_track_cmd->fsc_cmd, fcs_track_cmd->valid);
}

/**
 * @brief Encode a fcs_track_cmd struct on a channel
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param fcs_track_cmd C-struct to read the message contents from
 */
static inline uint16_t alink_msg_fcs_track_cmd_encode_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan, alink_message_head_t* msg, const alink_fcs_track_cmd_t* fcs_track_cmd)
{
	return alink_msg_fcs_track_cmd_pack_chan(dest_id, source_id, chan, msg, fcs_track_cmd->timestamp, fcs_track_cmd->fsc_cmd, fcs_track_cmd->valid);
}
// MESSAGE FCS_TRACK_CMD UNPACKING


/**
 * @brief Get field timestamp from fcs_track_cmd message
 *
 * @return timestamp
 */
static inline uint32_t alink_msg_fcs_track_cmd_get_timestamp(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field fsc_cmd from fcs_track_cmd message
 *
 * @return fsc command
 */
static inline uint16_t alink_msg_fcs_track_cmd_get_fsc_cmd(const alink_message_head_t* msg, float *fsc_cmd)
{
	return _MAV_RETURN_float_array(msg, fsc_cmd, 4,  4);
}

/**
 * @brief Get field valid from fcs_track_cmd message
 *
 * @return valid
 */
static inline uint8_t alink_msg_fcs_track_cmd_get_valid(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  20);
}

/**
 * @brief Decode a fcs_track_cmd message into a struct
 *
 * @param msg The message to decode
 * @param fcs_track_cmd C-struct to decode the message contents into
 */
static inline void alink_msg_fcs_track_cmd_decode(const alink_message_head_t* msg, alink_fcs_track_cmd_t* fcs_track_cmd)
{
#if ALINK_NEED_BYTE_SWAP
	fcs_track_cmd->timestamp = alink_msg_fcs_track_cmd_get_timestamp(msg);
	alink_msg_fcs_track_cmd_get_fsc_cmd(msg, fcs_track_cmd->fsc_cmd);
	fcs_track_cmd->valid = alink_msg_fcs_track_cmd_get_valid(msg);
#else
	memcpy(fcs_track_cmd, _MAV_PAYLOAD(msg), ALINK_MSG_ID_FCS_TRACK_CMD_LEN);
#endif
}
