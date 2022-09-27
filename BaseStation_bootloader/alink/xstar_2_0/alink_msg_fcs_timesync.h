// MESSAGE FCS_TIMESYNC PACKING

#define ALINK_MSG_ID_FCS_TIMESYNC 127

typedef struct __alink_fcs_timesync_t
{
 uint32_t timestamp; /*< fcs to vision timesync*/
} alink_fcs_timesync_t;

#define ALINK_MSG_ID_FCS_TIMESYNC_LEN 4
#define ALINK_MSG_ID_127_LEN 4

#define ALINK_MSG_ID_FCS_TIMESYNC_CRC 56
#define ALINK_MSG_ID_127_CRC 56



#define ALINK_MESSAGE_INFO_FCS_TIMESYNC { \
	"FCS_TIMESYNC", \
	1, \
	{  { "timestamp", NULL, ALINK_TYPE_UINT32_T, 0, 0, offsetof(alink_fcs_timesync_t, timestamp) }, \
         } \
}


/**
 * @brief Pack a fcs_timesync message
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 *
 * @param timestamp fcs to vision timesync
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_fcs_timesync_pack(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg,
						       uint32_t timestamp)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_FCS_TIMESYNC_LEN];
	_mav_put_uint32_t(buf, 0, timestamp);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_FCS_TIMESYNC_LEN);
#else
	alink_fcs_timesync_t packet;
	packet.timestamp = timestamp;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_FCS_TIMESYNC_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_FCS_TIMESYNC;
#if ALINK_CRC_EXTRA
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_FCS_TIMESYNC_LEN,ALINK_MSG_ID_FCS_TIMESYNC_CRC);
#else
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_FCS_TIMESYNC_LEN);
#endif
}

/**
 * @brief Pack a fcs_timesync message on a channel
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param timestamp fcs to vision timesync
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_fcs_timesync_pack_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan,
							   alink_message_head_t* msg,
						           uint32_t timestamp)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_FCS_TIMESYNC_LEN];
	_mav_put_uint32_t(buf, 0, timestamp);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_FCS_TIMESYNC_LEN);
#else
	alink_fcs_timesync_t packet;
	packet.timestamp = timestamp;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_FCS_TIMESYNC_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_FCS_TIMESYNC;
#if ALINK_CRC_EXTRA
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_FCS_TIMESYNC_LEN,ALINK_MSG_ID_FCS_TIMESYNC_CRC);
#else
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_FCS_TIMESYNC_LEN);
#endif
}
/**
 * @brief Encode a fcs_timesync struct
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 * @param fcs_timesync C-struct to read the message contents from
 */
static inline uint16_t alink_msg_fcs_timesync_encode(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg, const alink_fcs_timesync_t* fcs_timesync)
{
	return alink_msg_fcs_timesync_pack(dest_id, source_id, msg, fcs_timesync->timestamp);
}

/**
 * @brief Encode a fcs_timesync struct on a channel
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param fcs_timesync C-struct to read the message contents from
 */
static inline uint16_t alink_msg_fcs_timesync_encode_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan, alink_message_head_t* msg, const alink_fcs_timesync_t* fcs_timesync)
{
	return alink_msg_fcs_timesync_pack_chan(dest_id, source_id, chan, msg, fcs_timesync->timestamp);
}
// MESSAGE FCS_TIMESYNC UNPACKING


/**
 * @brief Get field timestamp from fcs_timesync message
 *
 * @return fcs to vision timesync
 */
static inline uint32_t alink_msg_fcs_timesync_get_timestamp(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Decode a fcs_timesync message into a struct
 *
 * @param msg The message to decode
 * @param fcs_timesync C-struct to decode the message contents into
 */
static inline void alink_msg_fcs_timesync_decode(const alink_message_head_t* msg, alink_fcs_timesync_t* fcs_timesync)
{
#if ALINK_NEED_BYTE_SWAP
	fcs_timesync->timestamp = alink_msg_fcs_timesync_get_timestamp(msg);
#else
	memcpy(fcs_timesync, _MAV_PAYLOAD(msg), ALINK_MSG_ID_FCS_TIMESYNC_LEN);
#endif
}
