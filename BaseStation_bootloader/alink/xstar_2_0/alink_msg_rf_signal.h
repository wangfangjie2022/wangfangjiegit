// MESSAGE RF_SIGNAL PACKING

#define ALINK_MSG_ID_RF_SIGNAL 128

typedef struct __alink_rf_signal_t
{
 char rf_position[16]; /*< RF_SIGNAL.*/
} alink_rf_signal_t;

#define ALINK_MSG_ID_RF_SIGNAL_LEN 16
#define ALINK_MSG_ID_128_LEN 16

#define ALINK_MSG_ID_RF_SIGNAL_CRC 151
#define ALINK_MSG_ID_128_CRC 151

#define ALINK_MSG_RF_SIGNAL_FIELD_RF_POSITION_LEN 16

#define ALINK_MESSAGE_INFO_RF_SIGNAL { \
	"RF_SIGNAL", \
	1, \
	{  { "rf_position", NULL, ALINK_TYPE_CHAR, 16, 0, offsetof(alink_rf_signal_t, rf_position) }, \
         } \
}


/**
 * @brief Pack a rf_signal message
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 *
 * @param rf_position RF_SIGNAL.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_rf_signal_pack(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg,
						       const char *rf_position)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_RF_SIGNAL_LEN];

	_mav_put_char_array(buf, 0, rf_position, 16);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_RF_SIGNAL_LEN);
#else
	alink_rf_signal_t packet;

	mav_array_memcpy(packet.rf_position, rf_position, sizeof(char)*16);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_RF_SIGNAL_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_RF_SIGNAL;
#if ALINK_CRC_EXTRA
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_RF_SIGNAL_LEN,ALINK_MSG_ID_RF_SIGNAL_CRC);
#else
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_RF_SIGNAL_LEN);
#endif
}

/**
 * @brief Pack a rf_signal message on a channel
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param rf_position RF_SIGNAL.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_rf_signal_pack_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan,
							   alink_message_head_t* msg,
						           const char *rf_position)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_RF_SIGNAL_LEN];

	_mav_put_char_array(buf, 0, rf_position, 16);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_RF_SIGNAL_LEN);
#else
	alink_rf_signal_t packet;

	mav_array_memcpy(packet.rf_position, rf_position, sizeof(char)*16);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_RF_SIGNAL_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_RF_SIGNAL;
#if ALINK_CRC_EXTRA
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_RF_SIGNAL_LEN,ALINK_MSG_ID_RF_SIGNAL_CRC);
#else
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_RF_SIGNAL_LEN);
#endif
}
/**
 * @brief Encode a rf_signal struct
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 * @param rf_signal C-struct to read the message contents from
 */
static inline uint16_t alink_msg_rf_signal_encode(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg, const alink_rf_signal_t* rf_signal)
{
	return alink_msg_rf_signal_pack(dest_id, source_id, msg, rf_signal->rf_position);
}

/**
 * @brief Encode a rf_signal struct on a channel
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param rf_signal C-struct to read the message contents from
 */
static inline uint16_t alink_msg_rf_signal_encode_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan, alink_message_head_t* msg, const alink_rf_signal_t* rf_signal)
{
	return alink_msg_rf_signal_pack_chan(dest_id, source_id, chan, msg, rf_signal->rf_position);
}
// MESSAGE RF_SIGNAL UNPACKING


/**
 * @brief Get field rf_position from rf_signal message
 *
 * @return RF_SIGNAL.
 */
static inline uint16_t alink_msg_rf_signal_get_rf_position(const alink_message_head_t* msg, char *rf_position)
{
	return _MAV_RETURN_char_array(msg, rf_position, 16,  0);
}

/**
 * @brief Decode a rf_signal message into a struct
 *
 * @param msg The message to decode
 * @param rf_signal C-struct to decode the message contents into
 */
static inline void alink_msg_rf_signal_decode(const alink_message_head_t* msg, alink_rf_signal_t* rf_signal)
{
#if ALINK_NEED_BYTE_SWAP
	alink_msg_rf_signal_get_rf_position(msg, rf_signal->rf_position);
#else
	memcpy(rf_signal, _MAV_PAYLOAD(msg), ALINK_MSG_ID_RF_SIGNAL_LEN);
#endif
}
