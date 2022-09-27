// MESSAGE SRVESC_INFO PACKING

#define ALINK_MSG_ID_SRVESC_INFO 136

typedef struct __alink_srvesc_info_t
{
 char srvesc_info[32]; /*< SRVESC_INFO.*/
} alink_srvesc_info_t;

#define ALINK_MSG_ID_SRVESC_INFO_LEN 32
#define ALINK_MSG_ID_136_LEN 32

#define ALINK_MSG_ID_SRVESC_INFO_CRC 96
#define ALINK_MSG_ID_136_CRC 96

#define ALINK_MSG_SRVESC_INFO_FIELD_SRVESC_INFO_LEN 32

#define ALINK_MESSAGE_INFO_SRVESC_INFO { \
	"SRVESC_INFO", \
	1, \
	{  { "srvesc_info", NULL, ALINK_TYPE_CHAR, 32, 0, offsetof(alink_srvesc_info_t, srvesc_info) }, \
         } \
}


/**
 * @brief Pack a srvesc_info message
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 *
 * @param srvesc_info SRVESC_INFO.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_srvesc_info_pack(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg,
						       const char *srvesc_info)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_SRVESC_INFO_LEN];

	_mav_put_char_array(buf, 0, srvesc_info, 32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_SRVESC_INFO_LEN);
#else
	alink_srvesc_info_t packet;

	mav_array_memcpy(packet.srvesc_info, srvesc_info, sizeof(char)*32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_SRVESC_INFO_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_SRVESC_INFO;
#if ALINK_CRC_EXTRA
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_SRVESC_INFO_LEN,ALINK_MSG_ID_SRVESC_INFO_CRC);
#else
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_SRVESC_INFO_LEN);
#endif
}

/**
 * @brief Pack a srvesc_info message on a channel
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param srvesc_info SRVESC_INFO.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_srvesc_info_pack_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan,
							   alink_message_head_t* msg,
						           const char *srvesc_info)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_SRVESC_INFO_LEN];

	_mav_put_char_array(buf, 0, srvesc_info, 32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_SRVESC_INFO_LEN);
#else
	alink_srvesc_info_t packet;

	mav_array_memcpy(packet.srvesc_info, srvesc_info, sizeof(char)*32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_SRVESC_INFO_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_SRVESC_INFO;
#if ALINK_CRC_EXTRA
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_SRVESC_INFO_LEN,ALINK_MSG_ID_SRVESC_INFO_CRC);
#else
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_SRVESC_INFO_LEN);
#endif
}
/**
 * @brief Encode a srvesc_info struct
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 * @param srvesc_info C-struct to read the message contents from
 */
static inline uint16_t alink_msg_srvesc_info_encode(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg, const alink_srvesc_info_t* srvesc_info)
{
	return alink_msg_srvesc_info_pack(dest_id, source_id, msg, srvesc_info->srvesc_info);
}

/**
 * @brief Encode a srvesc_info struct on a channel
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param srvesc_info C-struct to read the message contents from
 */
static inline uint16_t alink_msg_srvesc_info_encode_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan, alink_message_head_t* msg, const alink_srvesc_info_t* srvesc_info)
{
	return alink_msg_srvesc_info_pack_chan(dest_id, source_id, chan, msg, srvesc_info->srvesc_info);
}
// MESSAGE SRVESC_INFO UNPACKING


/**
 * @brief Get field srvesc_info from srvesc_info message
 *
 * @return SRVESC_INFO.
 */
static inline uint16_t alink_msg_srvesc_info_get_srvesc_info(const alink_message_head_t* msg, char *srvesc_info)
{
	return _MAV_RETURN_char_array(msg, srvesc_info, 32,  0);
}

/**
 * @brief Decode a srvesc_info message into a struct
 *
 * @param msg The message to decode
 * @param srvesc_info C-struct to decode the message contents into
 */
static inline void alink_msg_srvesc_info_decode(const alink_message_head_t* msg, alink_srvesc_info_t* srvesc_info)
{
#if ALINK_NEED_BYTE_SWAP
	alink_msg_srvesc_info_get_srvesc_info(msg, srvesc_info->srvesc_info);
#else
	memcpy(srvesc_info, _MAV_PAYLOAD(msg), ALINK_MSG_ID_SRVESC_INFO_LEN);
#endif
}
