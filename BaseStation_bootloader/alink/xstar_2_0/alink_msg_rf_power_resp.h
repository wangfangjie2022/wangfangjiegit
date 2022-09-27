// MESSAGE RF_POWER_RESP PACKING

#define ALINK_MSG_ID_RF_POWER_RESP 134

typedef struct __alink_rf_power_resp_t
{
 char rf_power_resp[8]; /*< RF_POWER_RESP.*/
} alink_rf_power_resp_t;

#define ALINK_MSG_ID_RF_POWER_RESP_LEN 8
#define ALINK_MSG_ID_134_LEN 8

#define ALINK_MSG_ID_RF_POWER_RESP_CRC 81
#define ALINK_MSG_ID_134_CRC 81

#define ALINK_MSG_RF_POWER_RESP_FIELD_RF_POWER_RESP_LEN 8

#define ALINK_MESSAGE_INFO_RF_POWER_RESP { \
	"RF_POWER_RESP", \
	1, \
	{  { "rf_power_resp", NULL, ALINK_TYPE_CHAR, 8, 0, offsetof(alink_rf_power_resp_t, rf_power_resp) }, \
         } \
}


/**
 * @brief Pack a rf_power_resp message
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 *
 * @param rf_power_resp RF_POWER_RESP.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_rf_power_resp_pack(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg,
						       const char *rf_power_resp)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_RF_POWER_RESP_LEN];

	_mav_put_char_array(buf, 0, rf_power_resp, 8);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_RF_POWER_RESP_LEN);
#else
	alink_rf_power_resp_t packet;

	mav_array_memcpy(packet.rf_power_resp, rf_power_resp, sizeof(char)*8);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_RF_POWER_RESP_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_RF_POWER_RESP;
#if ALINK_CRC_EXTRA
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_RF_POWER_RESP_LEN,ALINK_MSG_ID_RF_POWER_RESP_CRC);
#else
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_RF_POWER_RESP_LEN);
#endif
}

/**
 * @brief Pack a rf_power_resp message on a channel
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param rf_power_resp RF_POWER_RESP.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_rf_power_resp_pack_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan,
							   alink_message_head_t* msg,
						           const char *rf_power_resp)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_RF_POWER_RESP_LEN];

	_mav_put_char_array(buf, 0, rf_power_resp, 8);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_RF_POWER_RESP_LEN);
#else
	alink_rf_power_resp_t packet;

	mav_array_memcpy(packet.rf_power_resp, rf_power_resp, sizeof(char)*8);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_RF_POWER_RESP_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_RF_POWER_RESP;
#if ALINK_CRC_EXTRA
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_RF_POWER_RESP_LEN,ALINK_MSG_ID_RF_POWER_RESP_CRC);
#else
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_RF_POWER_RESP_LEN);
#endif
}
/**
 * @brief Encode a rf_power_resp struct
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 * @param rf_power_resp C-struct to read the message contents from
 */
static inline uint16_t alink_msg_rf_power_resp_encode(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg, const alink_rf_power_resp_t* rf_power_resp)
{
	return alink_msg_rf_power_resp_pack(dest_id, source_id, msg, rf_power_resp->rf_power_resp);
}

/**
 * @brief Encode a rf_power_resp struct on a channel
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param rf_power_resp C-struct to read the message contents from
 */
static inline uint16_t alink_msg_rf_power_resp_encode_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan, alink_message_head_t* msg, const alink_rf_power_resp_t* rf_power_resp)
{
	return alink_msg_rf_power_resp_pack_chan(dest_id, source_id, chan, msg, rf_power_resp->rf_power_resp);
}
// MESSAGE RF_POWER_RESP UNPACKING


/**
 * @brief Get field rf_power_resp from rf_power_resp message
 *
 * @return RF_POWER_RESP.
 */
static inline uint16_t alink_msg_rf_power_resp_get_rf_power_resp(const alink_message_head_t* msg, char *rf_power_resp)
{
	return _MAV_RETURN_char_array(msg, rf_power_resp, 8,  0);
}

/**
 * @brief Decode a rf_power_resp message into a struct
 *
 * @param msg The message to decode
 * @param rf_power_resp C-struct to decode the message contents into
 */
static inline void alink_msg_rf_power_resp_decode(const alink_message_head_t* msg, alink_rf_power_resp_t* rf_power_resp)
{
#if ALINK_NEED_BYTE_SWAP
	alink_msg_rf_power_resp_get_rf_power_resp(msg, rf_power_resp->rf_power_resp);
#else
	memcpy(rf_power_resp, _MAV_PAYLOAD(msg), ALINK_MSG_ID_RF_POWER_RESP_LEN);
#endif
}
