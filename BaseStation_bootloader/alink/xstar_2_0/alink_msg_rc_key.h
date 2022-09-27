// MESSAGE RC_KEY PACKING

#define ALINK_MSG_ID_RC_KEY 144

typedef struct __alink_rc_key_t
{
 uint8_t key_id; /*< take photo 0x4  video 0x5*/
 uint8_t key_time; /*< short press 0x0 long press 0x1*/
 uint8_t key_value; /*< key value*/
 uint8_t key_status; /*< key status*/
 uint8_t key_free[4]; /*< key free*/
} alink_rc_key_t;

#define ALINK_MSG_ID_RC_KEY_LEN 8
#define ALINK_MSG_ID_144_LEN 8

#define ALINK_MSG_ID_RC_KEY_CRC 224
#define ALINK_MSG_ID_144_CRC 224

#define ALINK_MSG_RC_KEY_FIELD_KEY_FREE_LEN 4

#define ALINK_MESSAGE_INFO_RC_KEY { \
	"RC_KEY", \
	5, \
	{  { "key_id", NULL, ALINK_TYPE_UINT8_T, 0, 0, offsetof(alink_rc_key_t, key_id) }, \
         { "key_time", NULL, ALINK_TYPE_UINT8_T, 0, 1, offsetof(alink_rc_key_t, key_time) }, \
         { "key_value", NULL, ALINK_TYPE_UINT8_T, 0, 2, offsetof(alink_rc_key_t, key_value) }, \
         { "key_status", NULL, ALINK_TYPE_UINT8_T, 0, 3, offsetof(alink_rc_key_t, key_status) }, \
         { "key_free", NULL, ALINK_TYPE_UINT8_T, 4, 4, offsetof(alink_rc_key_t, key_free) }, \
         } \
}


/**
 * @brief Pack a rc_key message
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 *
 * @param key_id take photo 0x4  video 0x5
 * @param key_time short press 0x0 long press 0x1
 * @param key_value key value
 * @param key_status key status
 * @param key_free key free
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_rc_key_pack(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg,
						       uint8_t key_id, uint8_t key_time, uint8_t key_value, uint8_t key_status, const uint8_t *key_free)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_RC_KEY_LEN];
	_mav_put_uint8_t(buf, 0, key_id);
	_mav_put_uint8_t(buf, 1, key_time);
	_mav_put_uint8_t(buf, 2, key_value);
	_mav_put_uint8_t(buf, 3, key_status);
	_mav_put_uint8_t_array(buf, 4, key_free, 4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_RC_KEY_LEN);
#else
	alink_rc_key_t packet;
	packet.key_id = key_id;
	packet.key_time = key_time;
	packet.key_value = key_value;
	packet.key_status = key_status;
	mav_array_memcpy(packet.key_free, key_free, sizeof(uint8_t)*4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_RC_KEY_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_RC_KEY;
#if ALINK_CRC_EXTRA
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_RC_KEY_LEN,ALINK_MSG_ID_RC_KEY_CRC);
#else
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_RC_KEY_LEN);
#endif
}

/**
 * @brief Pack a rc_key message on a channel
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param key_id take photo 0x4  video 0x5
 * @param key_time short press 0x0 long press 0x1
 * @param key_value key value
 * @param key_status key status
 * @param key_free key free
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_rc_key_pack_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan,
							   alink_message_head_t* msg,
						           uint8_t key_id,uint8_t key_time,uint8_t key_value,uint8_t key_status,const uint8_t *key_free)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_RC_KEY_LEN];
	_mav_put_uint8_t(buf, 0, key_id);
	_mav_put_uint8_t(buf, 1, key_time);
	_mav_put_uint8_t(buf, 2, key_value);
	_mav_put_uint8_t(buf, 3, key_status);
	_mav_put_uint8_t_array(buf, 4, key_free, 4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_RC_KEY_LEN);
#else
	alink_rc_key_t packet;
	packet.key_id = key_id;
	packet.key_time = key_time;
	packet.key_value = key_value;
	packet.key_status = key_status;
	mav_array_memcpy(packet.key_free, key_free, sizeof(uint8_t)*4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_RC_KEY_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_RC_KEY;
#if ALINK_CRC_EXTRA
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_RC_KEY_LEN,ALINK_MSG_ID_RC_KEY_CRC);
#else
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_RC_KEY_LEN);
#endif
}
/**
 * @brief Encode a rc_key struct
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 * @param rc_key C-struct to read the message contents from
 */
static inline uint16_t alink_msg_rc_key_encode(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg, const alink_rc_key_t* rc_key)
{
	return alink_msg_rc_key_pack(dest_id, source_id, msg, rc_key->key_id, rc_key->key_time, rc_key->key_value, rc_key->key_status, rc_key->key_free);
}

/**
 * @brief Encode a rc_key struct on a channel
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param rc_key C-struct to read the message contents from
 */
static inline uint16_t alink_msg_rc_key_encode_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan, alink_message_head_t* msg, const alink_rc_key_t* rc_key)
{
	return alink_msg_rc_key_pack_chan(dest_id, source_id, chan, msg, rc_key->key_id, rc_key->key_time, rc_key->key_value, rc_key->key_status, rc_key->key_free);
}
// MESSAGE RC_KEY UNPACKING


/**
 * @brief Get field key_id from rc_key message
 *
 * @return take photo 0x4  video 0x5
 */
static inline uint8_t alink_msg_rc_key_get_key_id(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field key_time from rc_key message
 *
 * @return short press 0x0 long press 0x1
 */
static inline uint8_t alink_msg_rc_key_get_key_time(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  1);
}

/**
 * @brief Get field key_value from rc_key message
 *
 * @return key value
 */
static inline uint8_t alink_msg_rc_key_get_key_value(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  2);
}

/**
 * @brief Get field key_status from rc_key message
 *
 * @return key status
 */
static inline uint8_t alink_msg_rc_key_get_key_status(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  3);
}

/**
 * @brief Get field key_free from rc_key message
 *
 * @return key free
 */
static inline uint16_t alink_msg_rc_key_get_key_free(const alink_message_head_t* msg, uint8_t *key_free)
{
	return _MAV_RETURN_uint8_t_array(msg, key_free, 4,  4);
}

/**
 * @brief Decode a rc_key message into a struct
 *
 * @param msg The message to decode
 * @param rc_key C-struct to decode the message contents into
 */
static inline void alink_msg_rc_key_decode(const alink_message_head_t* msg, alink_rc_key_t* rc_key)
{
#if ALINK_NEED_BYTE_SWAP
	rc_key->key_id = alink_msg_rc_key_get_key_id(msg);
	rc_key->key_time = alink_msg_rc_key_get_key_time(msg);
	rc_key->key_value = alink_msg_rc_key_get_key_value(msg);
	rc_key->key_status = alink_msg_rc_key_get_key_status(msg);
	alink_msg_rc_key_get_key_free(msg, rc_key->key_free);
#else
	memcpy(rc_key, _MAV_PAYLOAD(msg), ALINK_MSG_ID_RC_KEY_LEN);
#endif
}
