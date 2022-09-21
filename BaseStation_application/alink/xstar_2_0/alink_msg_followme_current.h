// MESSAGE FOLLOWME_CURRENT PACKING

#define ALINK_MSG_ID_FOLLOWME_CURRENT 44

typedef struct __alink_followme_current_t
{
 uint32_t timestamp; /*< timestamp (milliseconds since system boot)*/
 uint8_t status; /*< way point status. 0:pause; 1:running; 2:completed; other:as defiens latter*/
} alink_followme_current_t;

#define ALINK_MSG_ID_FOLLOWME_CURRENT_LEN 5
#define ALINK_MSG_ID_44_LEN 5

#define ALINK_MSG_ID_FOLLOWME_CURRENT_CRC 5
#define ALINK_MSG_ID_44_CRC 5



#define ALINK_MESSAGE_INFO_FOLLOWME_CURRENT { \
	"FOLLOWME_CURRENT", \
	2, \
	{  { "timestamp", NULL, ALINK_TYPE_UINT32_T, 0, 0, offsetof(alink_followme_current_t, timestamp) }, \
         { "status", NULL, ALINK_TYPE_UINT8_T, 0, 4, offsetof(alink_followme_current_t, status) }, \
         } \
}


/**
 * @brief Pack a followme_current message
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 *
 * @param timestamp timestamp (milliseconds since system boot)
 * @param status way point status. 0:pause; 1:running; 2:completed; other:as defiens latter
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_followme_current_pack(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg,
						       uint32_t timestamp, uint8_t status)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_FOLLOWME_CURRENT_LEN];
	_mav_put_uint32_t(buf, 0, timestamp);
	_mav_put_uint8_t(buf, 4, status);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_FOLLOWME_CURRENT_LEN);
#else
	alink_followme_current_t packet;
	packet.timestamp = timestamp;
	packet.status = status;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_FOLLOWME_CURRENT_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_FOLLOWME_CURRENT;
#if ALINK_CRC_EXTRA
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_FOLLOWME_CURRENT_LEN,ALINK_MSG_ID_FOLLOWME_CURRENT_CRC);
#else
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_FOLLOWME_CURRENT_LEN);
#endif
}

/**
 * @brief Pack a followme_current message on a channel
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param timestamp timestamp (milliseconds since system boot)
 * @param status way point status. 0:pause; 1:running; 2:completed; other:as defiens latter
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_followme_current_pack_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan,
							   alink_message_head_t* msg,
						           uint32_t timestamp,uint8_t status)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_FOLLOWME_CURRENT_LEN];
	_mav_put_uint32_t(buf, 0, timestamp);
	_mav_put_uint8_t(buf, 4, status);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_FOLLOWME_CURRENT_LEN);
#else
	alink_followme_current_t packet;
	packet.timestamp = timestamp;
	packet.status = status;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_FOLLOWME_CURRENT_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_FOLLOWME_CURRENT;
#if ALINK_CRC_EXTRA
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_FOLLOWME_CURRENT_LEN,ALINK_MSG_ID_FOLLOWME_CURRENT_CRC);
#else
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_FOLLOWME_CURRENT_LEN);
#endif
}
/**
 * @brief Encode a followme_current struct
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 * @param followme_current C-struct to read the message contents from
 */
static inline uint16_t alink_msg_followme_current_encode(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg, const alink_followme_current_t* followme_current)
{
	return alink_msg_followme_current_pack(dest_id, source_id, msg, followme_current->timestamp, followme_current->status);
}

/**
 * @brief Encode a followme_current struct on a channel
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param followme_current C-struct to read the message contents from
 */
static inline uint16_t alink_msg_followme_current_encode_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan, alink_message_head_t* msg, const alink_followme_current_t* followme_current)
{
	return alink_msg_followme_current_pack_chan(dest_id, source_id, chan, msg, followme_current->timestamp, followme_current->status);
}
// MESSAGE FOLLOWME_CURRENT UNPACKING


/**
 * @brief Get field timestamp from followme_current message
 *
 * @return timestamp (milliseconds since system boot)
 */
static inline uint32_t alink_msg_followme_current_get_timestamp(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field status from followme_current message
 *
 * @return way point status. 0:pause; 1:running; 2:completed; other:as defiens latter
 */
static inline uint8_t alink_msg_followme_current_get_status(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  4);
}

/**
 * @brief Decode a followme_current message into a struct
 *
 * @param msg The message to decode
 * @param followme_current C-struct to decode the message contents into
 */
static inline void alink_msg_followme_current_decode(const alink_message_head_t* msg, alink_followme_current_t* followme_current)
{
#if ALINK_NEED_BYTE_SWAP
	followme_current->timestamp = alink_msg_followme_current_get_timestamp(msg);
	followme_current->status = alink_msg_followme_current_get_status(msg);
#else
	memcpy(followme_current, _MAV_PAYLOAD(msg), ALINK_MSG_ID_FOLLOWME_CURRENT_LEN);
#endif
}
