// MESSAGE RF_PAIR_RESP PACKING

#define ALINK_MSG_ID_RF_PAIR_RESP 130

typedef struct __alink_rf_pair_resp_t
{
 char rf_pair_resp[4]; /*< RF_PAIR_RESP.*/
} alink_rf_pair_resp_t;

#define ALINK_MSG_ID_RF_PAIR_RESP_LEN 4
#define ALINK_MSG_ID_130_LEN 4

#define ALINK_MSG_ID_RF_PAIR_RESP_CRC 89
#define ALINK_MSG_ID_130_CRC 89

#define ALINK_MSG_RF_PAIR_RESP_FIELD_RF_PAIR_RESP_LEN 4

#define ALINK_MESSAGE_INFO_RF_PAIR_RESP { \
	"RF_PAIR_RESP", \
	1, \
	{  { "rf_pair_resp", NULL, ALINK_TYPE_CHAR, 4, 0, offsetof(alink_rf_pair_resp_t, rf_pair_resp) }, \
         } \
}


/**
 * @brief Pack a rf_pair_resp message
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 *
 * @param rf_pair_resp RF_PAIR_RESP.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_rf_pair_resp_pack(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg,
						       const char *rf_pair_resp)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_RF_PAIR_RESP_LEN];

	_mav_put_char_array(buf, 0, rf_pair_resp, 4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_RF_PAIR_RESP_LEN);
#else
	alink_rf_pair_resp_t packet;

	mav_array_memcpy(packet.rf_pair_resp, rf_pair_resp, sizeof(char)*4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_RF_PAIR_RESP_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_RF_PAIR_RESP;
#if ALINK_CRC_EXTRA
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_RF_PAIR_RESP_LEN,ALINK_MSG_ID_RF_PAIR_RESP_CRC);
#else
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_RF_PAIR_RESP_LEN);
#endif
}

/**
 * @brief Pack a rf_pair_resp message on a channel
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param rf_pair_resp RF_PAIR_RESP.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_rf_pair_resp_pack_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan,
							   alink_message_head_t* msg,
						           const char *rf_pair_resp)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_RF_PAIR_RESP_LEN];

	_mav_put_char_array(buf, 0, rf_pair_resp, 4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_RF_PAIR_RESP_LEN);
#else
	alink_rf_pair_resp_t packet;

	mav_array_memcpy(packet.rf_pair_resp, rf_pair_resp, sizeof(char)*4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_RF_PAIR_RESP_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_RF_PAIR_RESP;
#if ALINK_CRC_EXTRA
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_RF_PAIR_RESP_LEN,ALINK_MSG_ID_RF_PAIR_RESP_CRC);
#else
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_RF_PAIR_RESP_LEN);
#endif
}
/**
 * @brief Encode a rf_pair_resp struct
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 * @param rf_pair_resp C-struct to read the message contents from
 */
static inline uint16_t alink_msg_rf_pair_resp_encode(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg, const alink_rf_pair_resp_t* rf_pair_resp)
{
	return alink_msg_rf_pair_resp_pack(dest_id, source_id, msg, rf_pair_resp->rf_pair_resp);
}

/**
 * @brief Encode a rf_pair_resp struct on a channel
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param rf_pair_resp C-struct to read the message contents from
 */
static inline uint16_t alink_msg_rf_pair_resp_encode_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan, alink_message_head_t* msg, const alink_rf_pair_resp_t* rf_pair_resp)
{
	return alink_msg_rf_pair_resp_pack_chan(dest_id, source_id, chan, msg, rf_pair_resp->rf_pair_resp);
}
// MESSAGE RF_PAIR_RESP UNPACKING


/**
 * @brief Get field rf_pair_resp from rf_pair_resp message
 *
 * @return RF_PAIR_RESP.
 */
static inline uint16_t alink_msg_rf_pair_resp_get_rf_pair_resp(const alink_message_head_t* msg, char *rf_pair_resp)
{
	return _MAV_RETURN_char_array(msg, rf_pair_resp, 4,  0);
}

/**
 * @brief Decode a rf_pair_resp message into a struct
 *
 * @param msg The message to decode
 * @param rf_pair_resp C-struct to decode the message contents into
 */
static inline void alink_msg_rf_pair_resp_decode(const alink_message_head_t* msg, alink_rf_pair_resp_t* rf_pair_resp)
{
#if ALINK_NEED_BYTE_SWAP
	alink_msg_rf_pair_resp_get_rf_pair_resp(msg, rf_pair_resp->rf_pair_resp);
#else
	memcpy(rf_pair_resp, _MAV_PAYLOAD(msg), ALINK_MSG_ID_RF_PAIR_RESP_LEN);
#endif
}
