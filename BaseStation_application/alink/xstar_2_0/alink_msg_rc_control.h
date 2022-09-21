// MESSAGE RC_CONTROL PACKING

#define ALINK_MSG_ID_RC_CONTROL 152

typedef struct __alink_rc_control_t
{
 uint8_t key[9]; /*< rc control key(0-8)bytes*/
} alink_rc_control_t;

#define ALINK_MSG_ID_RC_CONTROL_LEN 9
#define ALINK_MSG_ID_152_LEN 9

#define ALINK_MSG_ID_RC_CONTROL_CRC 130
#define ALINK_MSG_ID_152_CRC 130

#define ALINK_MSG_RC_CONTROL_FIELD_KEY_LEN 9

#define ALINK_MESSAGE_INFO_RC_CONTROL { \
	"RC_CONTROL", \
	1, \
	{  { "key", NULL, ALINK_TYPE_UINT8_T, 9, 0, offsetof(alink_rc_control_t, key) }, \
         } \
}


/**
 * @brief Pack a rc_control message
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 *
 * @param key rc control key(0-8)bytes
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_rc_control_pack(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg,
						       const uint8_t *key)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_RC_CONTROL_LEN];

	_mav_put_uint8_t_array(buf, 0, key, 9);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_RC_CONTROL_LEN);
#else
	alink_rc_control_t packet;

	mav_array_memcpy(packet.key, key, sizeof(uint8_t)*9);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_RC_CONTROL_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_RC_CONTROL;
#if ALINK_CRC_EXTRA
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_RC_CONTROL_LEN,ALINK_MSG_ID_RC_CONTROL_CRC);
#else
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_RC_CONTROL_LEN);
#endif
}

/**
 * @brief Pack a rc_control message on a channel
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param key rc control key(0-8)bytes
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_rc_control_pack_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan,
							   alink_message_head_t* msg,
						           const uint8_t *key)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_RC_CONTROL_LEN];

	_mav_put_uint8_t_array(buf, 0, key, 9);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_RC_CONTROL_LEN);
#else
	alink_rc_control_t packet;

	mav_array_memcpy(packet.key, key, sizeof(uint8_t)*9);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_RC_CONTROL_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_RC_CONTROL;
#if ALINK_CRC_EXTRA
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_RC_CONTROL_LEN,ALINK_MSG_ID_RC_CONTROL_CRC);
#else
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_RC_CONTROL_LEN);
#endif
}
/**
 * @brief Encode a rc_control struct
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 * @param rc_control C-struct to read the message contents from
 */
static inline uint16_t alink_msg_rc_control_encode(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg, const alink_rc_control_t* rc_control)
{
	return alink_msg_rc_control_pack(dest_id, source_id, msg, rc_control->key);
}

/**
 * @brief Encode a rc_control struct on a channel
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param rc_control C-struct to read the message contents from
 */
static inline uint16_t alink_msg_rc_control_encode_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan, alink_message_head_t* msg, const alink_rc_control_t* rc_control)
{
	return alink_msg_rc_control_pack_chan(dest_id, source_id, chan, msg, rc_control->key);
}
// MESSAGE RC_CONTROL UNPACKING


/**
 * @brief Get field key from rc_control message
 *
 * @return rc control key(0-8)bytes
 */
static inline uint16_t alink_msg_rc_control_get_key(const alink_message_head_t* msg, uint8_t *key)
{
	return _MAV_RETURN_uint8_t_array(msg, key, 9,  0);
}

/**
 * @brief Decode a rc_control message into a struct
 *
 * @param msg The message to decode
 * @param rc_control C-struct to decode the message contents into
 */
static inline void alink_msg_rc_control_decode(const alink_message_head_t* msg, alink_rc_control_t* rc_control)
{
#if ALINK_NEED_BYTE_SWAP
	alink_msg_rc_control_get_key(msg, rc_control->key);
#else
	memcpy(rc_control, _MAV_PAYLOAD(msg), ALINK_MSG_ID_RC_CONTROL_LEN);
#endif
}
