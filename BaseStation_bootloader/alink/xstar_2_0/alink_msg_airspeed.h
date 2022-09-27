// MESSAGE AIRSPEED PACKING

#define ALINK_MSG_ID_AIRSPEED 137

typedef struct __alink_airspeed_t
{
 char airspeed[32]; /*< AIRSPEED.*/
} alink_airspeed_t;

#define ALINK_MSG_ID_AIRSPEED_LEN 32
#define ALINK_MSG_ID_137_LEN 32

#define ALINK_MSG_ID_AIRSPEED_CRC 132
#define ALINK_MSG_ID_137_CRC 132

#define ALINK_MSG_AIRSPEED_FIELD_AIRSPEED_LEN 32

#define ALINK_MESSAGE_INFO_AIRSPEED { \
	"AIRSPEED", \
	1, \
	{  { "airspeed", NULL, ALINK_TYPE_CHAR, 32, 0, offsetof(alink_airspeed_t, airspeed) }, \
         } \
}


/**
 * @brief Pack a airspeed message
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 *
 * @param airspeed AIRSPEED.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_airspeed_pack(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg,
						       const char *airspeed)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_AIRSPEED_LEN];

	_mav_put_char_array(buf, 0, airspeed, 32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_AIRSPEED_LEN);
#else
	alink_airspeed_t packet;

	mav_array_memcpy(packet.airspeed, airspeed, sizeof(char)*32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_AIRSPEED_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_AIRSPEED;
#if ALINK_CRC_EXTRA
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_AIRSPEED_LEN,ALINK_MSG_ID_AIRSPEED_CRC);
#else
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_AIRSPEED_LEN);
#endif
}

/**
 * @brief Pack a airspeed message on a channel
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param airspeed AIRSPEED.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_airspeed_pack_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan,
							   alink_message_head_t* msg,
						           const char *airspeed)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_AIRSPEED_LEN];

	_mav_put_char_array(buf, 0, airspeed, 32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_AIRSPEED_LEN);
#else
	alink_airspeed_t packet;

	mav_array_memcpy(packet.airspeed, airspeed, sizeof(char)*32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_AIRSPEED_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_AIRSPEED;
#if ALINK_CRC_EXTRA
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_AIRSPEED_LEN,ALINK_MSG_ID_AIRSPEED_CRC);
#else
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_AIRSPEED_LEN);
#endif
}
/**
 * @brief Encode a airspeed struct
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 * @param airspeed C-struct to read the message contents from
 */
static inline uint16_t alink_msg_airspeed_encode(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg, const alink_airspeed_t* airspeed)
{
	return alink_msg_airspeed_pack(dest_id, source_id, msg, airspeed->airspeed);
}

/**
 * @brief Encode a airspeed struct on a channel
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param airspeed C-struct to read the message contents from
 */
static inline uint16_t alink_msg_airspeed_encode_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan, alink_message_head_t* msg, const alink_airspeed_t* airspeed)
{
	return alink_msg_airspeed_pack_chan(dest_id, source_id, chan, msg, airspeed->airspeed);
}
// MESSAGE AIRSPEED UNPACKING


/**
 * @brief Get field airspeed from airspeed message
 *
 * @return AIRSPEED.
 */
static inline uint16_t alink_msg_airspeed_get_airspeed(const alink_message_head_t* msg, char *airspeed)
{
	return _MAV_RETURN_char_array(msg, airspeed, 32,  0);
}

/**
 * @brief Decode a airspeed message into a struct
 *
 * @param msg The message to decode
 * @param airspeed C-struct to decode the message contents into
 */
static inline void alink_msg_airspeed_decode(const alink_message_head_t* msg, alink_airspeed_t* airspeed)
{
#if ALINK_NEED_BYTE_SWAP
	alink_msg_airspeed_get_airspeed(msg, airspeed->airspeed);
#else
	memcpy(airspeed, _MAV_PAYLOAD(msg), ALINK_MSG_ID_AIRSPEED_LEN);
#endif
}
