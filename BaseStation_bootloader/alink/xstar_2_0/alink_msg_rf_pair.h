// MESSAGE RF_PAIR PACKING

#define ALINK_MSG_ID_RF_PAIR 129

typedef struct __alink_rf_pair_t
{
 char rf_pair[32]; /*< RF_PAIR.*/
} alink_rf_pair_t;

#define ALINK_MSG_ID_RF_PAIR_LEN 32
#define ALINK_MSG_ID_129_LEN 32

#define ALINK_MSG_ID_RF_PAIR_CRC 57
#define ALINK_MSG_ID_129_CRC 57

#define ALINK_MSG_RF_PAIR_FIELD_RF_PAIR_LEN 32

#define ALINK_MESSAGE_INFO_RF_PAIR { \
	"RF_PAIR", \
	1, \
	{  { "rf_pair", NULL, ALINK_TYPE_CHAR, 32, 0, offsetof(alink_rf_pair_t, rf_pair) }, \
         } \
}


/**
 * @brief Pack a rf_pair message
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 *
 * @param rf_pair RF_PAIR.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_rf_pair_pack(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg,
						       const char *rf_pair)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_RF_PAIR_LEN];

	_mav_put_char_array(buf, 0, rf_pair, 32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_RF_PAIR_LEN);
#else
	alink_rf_pair_t packet;

	mav_array_memcpy(packet.rf_pair, rf_pair, sizeof(char)*32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_RF_PAIR_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_RF_PAIR;
#if ALINK_CRC_EXTRA
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_RF_PAIR_LEN,ALINK_MSG_ID_RF_PAIR_CRC);
#else
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_RF_PAIR_LEN);
#endif
}

/**
 * @brief Pack a rf_pair message on a channel
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param rf_pair RF_PAIR.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_rf_pair_pack_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan,
							   alink_message_head_t* msg,
						           const char *rf_pair)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_RF_PAIR_LEN];

	_mav_put_char_array(buf, 0, rf_pair, 32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_RF_PAIR_LEN);
#else
	alink_rf_pair_t packet;

	mav_array_memcpy(packet.rf_pair, rf_pair, sizeof(char)*32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_RF_PAIR_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_RF_PAIR;
#if ALINK_CRC_EXTRA
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_RF_PAIR_LEN,ALINK_MSG_ID_RF_PAIR_CRC);
#else
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_RF_PAIR_LEN);
#endif
}
/**
 * @brief Encode a rf_pair struct
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 * @param rf_pair C-struct to read the message contents from
 */
static inline uint16_t alink_msg_rf_pair_encode(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg, const alink_rf_pair_t* rf_pair)
{
	return alink_msg_rf_pair_pack(dest_id, source_id, msg, rf_pair->rf_pair);
}

/**
 * @brief Encode a rf_pair struct on a channel
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param rf_pair C-struct to read the message contents from
 */
static inline uint16_t alink_msg_rf_pair_encode_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan, alink_message_head_t* msg, const alink_rf_pair_t* rf_pair)
{
	return alink_msg_rf_pair_pack_chan(dest_id, source_id, chan, msg, rf_pair->rf_pair);
}
// MESSAGE RF_PAIR UNPACKING


/**
 * @brief Get field rf_pair from rf_pair message
 *
 * @return RF_PAIR.
 */
static inline uint16_t alink_msg_rf_pair_get_rf_pair(const alink_message_head_t* msg, char *rf_pair)
{
	return _MAV_RETURN_char_array(msg, rf_pair, 32,  0);
}

/**
 * @brief Decode a rf_pair message into a struct
 *
 * @param msg The message to decode
 * @param rf_pair C-struct to decode the message contents into
 */
static inline void alink_msg_rf_pair_decode(const alink_message_head_t* msg, alink_rf_pair_t* rf_pair)
{
#if ALINK_NEED_BYTE_SWAP
	alink_msg_rf_pair_get_rf_pair(msg, rf_pair->rf_pair);
#else
	memcpy(rf_pair, _MAV_PAYLOAD(msg), ALINK_MSG_ID_RF_PAIR_LEN);
#endif
}
