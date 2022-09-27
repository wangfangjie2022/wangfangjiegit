// MESSAGE BAT_AUTHEN PACKING

#define ALINK_MSG_ID_BAT_AUTHEN 66

typedef struct __alink_bat_authen_t
{
 uint8_t len; /*< The battery authenticate code length*/
 uint8_t data[32]; /*< The battery authenticate code*/
} alink_bat_authen_t;

#define ALINK_MSG_ID_BAT_AUTHEN_LEN 33
#define ALINK_MSG_ID_66_LEN 33

#define ALINK_MSG_ID_BAT_AUTHEN_CRC 31
#define ALINK_MSG_ID_66_CRC 31

#define ALINK_MSG_BAT_AUTHEN_FIELD_DATA_LEN 32

#define ALINK_MESSAGE_INFO_BAT_AUTHEN { \
	"BAT_AUTHEN", \
	2, \
	{  { "len", NULL, ALINK_TYPE_UINT8_T, 0, 0, offsetof(alink_bat_authen_t, len) }, \
         { "data", NULL, ALINK_TYPE_UINT8_T, 32, 1, offsetof(alink_bat_authen_t, data) }, \
         } \
}


/**
 * @brief Pack a bat_authen message
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 *
 * @param len The battery authenticate code length
 * @param data The battery authenticate code
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_bat_authen_pack(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg,
						       uint8_t len, const uint8_t *data)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_BAT_AUTHEN_LEN];
	_mav_put_uint8_t(buf, 0, len);
	_mav_put_uint8_t_array(buf, 1, data, 32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_BAT_AUTHEN_LEN);
#else
	alink_bat_authen_t packet;
	packet.len = len;
	mav_array_memcpy(packet.data, data, sizeof(uint8_t)*32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_BAT_AUTHEN_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_BAT_AUTHEN;
#if ALINK_CRC_EXTRA
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_BAT_AUTHEN_LEN,ALINK_MSG_ID_BAT_AUTHEN_CRC);
#else
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_BAT_AUTHEN_LEN);
#endif
}

/**
 * @brief Pack a bat_authen message on a channel
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param len The battery authenticate code length
 * @param data The battery authenticate code
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_bat_authen_pack_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan,
							   alink_message_head_t* msg,
						           uint8_t len,const uint8_t *data)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_BAT_AUTHEN_LEN];
	_mav_put_uint8_t(buf, 0, len);
	_mav_put_uint8_t_array(buf, 1, data, 32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_BAT_AUTHEN_LEN);
#else
	alink_bat_authen_t packet;
	packet.len = len;
	mav_array_memcpy(packet.data, data, sizeof(uint8_t)*32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_BAT_AUTHEN_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_BAT_AUTHEN;
#if ALINK_CRC_EXTRA
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_BAT_AUTHEN_LEN,ALINK_MSG_ID_BAT_AUTHEN_CRC);
#else
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_BAT_AUTHEN_LEN);
#endif
}
/**
 * @brief Encode a bat_authen struct
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 * @param bat_authen C-struct to read the message contents from
 */
static inline uint16_t alink_msg_bat_authen_encode(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg, const alink_bat_authen_t* bat_authen)
{
	return alink_msg_bat_authen_pack(dest_id, source_id, msg, bat_authen->len, bat_authen->data);
}

/**
 * @brief Encode a bat_authen struct on a channel
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param bat_authen C-struct to read the message contents from
 */
static inline uint16_t alink_msg_bat_authen_encode_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan, alink_message_head_t* msg, const alink_bat_authen_t* bat_authen)
{
	return alink_msg_bat_authen_pack_chan(dest_id, source_id, chan, msg, bat_authen->len, bat_authen->data);
}
// MESSAGE BAT_AUTHEN UNPACKING


/**
 * @brief Get field len from bat_authen message
 *
 * @return The battery authenticate code length
 */
static inline uint8_t alink_msg_bat_authen_get_len(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field data from bat_authen message
 *
 * @return The battery authenticate code
 */
static inline uint16_t alink_msg_bat_authen_get_data(const alink_message_head_t* msg, uint8_t *data)
{
	return _MAV_RETURN_uint8_t_array(msg, data, 32,  1);
}

/**
 * @brief Decode a bat_authen message into a struct
 *
 * @param msg The message to decode
 * @param bat_authen C-struct to decode the message contents into
 */
static inline void alink_msg_bat_authen_decode(const alink_message_head_t* msg, alink_bat_authen_t* bat_authen)
{
#if ALINK_NEED_BYTE_SWAP
	bat_authen->len = alink_msg_bat_authen_get_len(msg);
	alink_msg_bat_authen_get_data(msg, bat_authen->data);
#else
	memcpy(bat_authen, _MAV_PAYLOAD(msg), ALINK_MSG_ID_BAT_AUTHEN_LEN);
#endif
}
