// MESSAGE RAW_MAG1 PACKING

#define ALINK_MSG_ID_RAW_MAG1 33

typedef struct __alink_raw_mag1_t
{
 uint64_t timestamp; /*< timestamp (microseconds since UNIX epoch or microseconds since system boot)*/
 int16_t xmag; /*< X Magnetic field (raw)*/
 int16_t ymag; /*< Y Magnetic field (raw)*/
 int16_t zmag; /*< Z Magnetic field (raw)*/
} alink_raw_mag1_t;

#define ALINK_MSG_ID_RAW_MAG1_LEN 14
#define ALINK_MSG_ID_33_LEN 14

#define ALINK_MSG_ID_RAW_MAG1_CRC 193
#define ALINK_MSG_ID_33_CRC 193



#define ALINK_MESSAGE_INFO_RAW_MAG1 { \
	"RAW_MAG1", \
	4, \
	{  { "timestamp", NULL, ALINK_TYPE_UINT64_T, 0, 0, offsetof(alink_raw_mag1_t, timestamp) }, \
         { "xmag", NULL, ALINK_TYPE_INT16_T, 0, 8, offsetof(alink_raw_mag1_t, xmag) }, \
         { "ymag", NULL, ALINK_TYPE_INT16_T, 0, 10, offsetof(alink_raw_mag1_t, ymag) }, \
         { "zmag", NULL, ALINK_TYPE_INT16_T, 0, 12, offsetof(alink_raw_mag1_t, zmag) }, \
         } \
}


/**
 * @brief Pack a raw_mag1 message
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 *
 * @param timestamp timestamp (microseconds since UNIX epoch or microseconds since system boot)
 * @param xmag X Magnetic field (raw)
 * @param ymag Y Magnetic field (raw)
 * @param zmag Z Magnetic field (raw)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_raw_mag1_pack(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg,
						       uint64_t timestamp, int16_t xmag, int16_t ymag, int16_t zmag)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_RAW_MAG1_LEN];
	_mav_put_uint64_t(buf, 0, timestamp);
	_mav_put_int16_t(buf, 8, xmag);
	_mav_put_int16_t(buf, 10, ymag);
	_mav_put_int16_t(buf, 12, zmag);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_RAW_MAG1_LEN);
#else
	alink_raw_mag1_t packet;
	packet.timestamp = timestamp;
	packet.xmag = xmag;
	packet.ymag = ymag;
	packet.zmag = zmag;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_RAW_MAG1_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_RAW_MAG1;
#if ALINK_CRC_EXTRA
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_RAW_MAG1_LEN,ALINK_MSG_ID_RAW_MAG1_CRC);
#else
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_RAW_MAG1_LEN);
#endif
}

/**
 * @brief Pack a raw_mag1 message on a channel
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param timestamp timestamp (microseconds since UNIX epoch or microseconds since system boot)
 * @param xmag X Magnetic field (raw)
 * @param ymag Y Magnetic field (raw)
 * @param zmag Z Magnetic field (raw)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_raw_mag1_pack_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan,
							   alink_message_head_t* msg,
						           uint64_t timestamp,int16_t xmag,int16_t ymag,int16_t zmag)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_RAW_MAG1_LEN];
	_mav_put_uint64_t(buf, 0, timestamp);
	_mav_put_int16_t(buf, 8, xmag);
	_mav_put_int16_t(buf, 10, ymag);
	_mav_put_int16_t(buf, 12, zmag);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_RAW_MAG1_LEN);
#else
	alink_raw_mag1_t packet;
	packet.timestamp = timestamp;
	packet.xmag = xmag;
	packet.ymag = ymag;
	packet.zmag = zmag;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_RAW_MAG1_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_RAW_MAG1;
#if ALINK_CRC_EXTRA
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_RAW_MAG1_LEN,ALINK_MSG_ID_RAW_MAG1_CRC);
#else
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_RAW_MAG1_LEN);
#endif
}
/**
 * @brief Encode a raw_mag1 struct
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 * @param raw_mag1 C-struct to read the message contents from
 */
static inline uint16_t alink_msg_raw_mag1_encode(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg, const alink_raw_mag1_t* raw_mag1)
{
	return alink_msg_raw_mag1_pack(dest_id, source_id, msg, raw_mag1->timestamp, raw_mag1->xmag, raw_mag1->ymag, raw_mag1->zmag);
}

/**
 * @brief Encode a raw_mag1 struct on a channel
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param raw_mag1 C-struct to read the message contents from
 */
static inline uint16_t alink_msg_raw_mag1_encode_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan, alink_message_head_t* msg, const alink_raw_mag1_t* raw_mag1)
{
	return alink_msg_raw_mag1_pack_chan(dest_id, source_id, chan, msg, raw_mag1->timestamp, raw_mag1->xmag, raw_mag1->ymag, raw_mag1->zmag);
}
// MESSAGE RAW_MAG1 UNPACKING


/**
 * @brief Get field timestamp from raw_mag1 message
 *
 * @return timestamp (microseconds since UNIX epoch or microseconds since system boot)
 */
static inline uint64_t alink_msg_raw_mag1_get_timestamp(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field xmag from raw_mag1 message
 *
 * @return X Magnetic field (raw)
 */
static inline int16_t alink_msg_raw_mag1_get_xmag(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  8);
}

/**
 * @brief Get field ymag from raw_mag1 message
 *
 * @return Y Magnetic field (raw)
 */
static inline int16_t alink_msg_raw_mag1_get_ymag(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  10);
}

/**
 * @brief Get field zmag from raw_mag1 message
 *
 * @return Z Magnetic field (raw)
 */
static inline int16_t alink_msg_raw_mag1_get_zmag(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  12);
}

/**
 * @brief Decode a raw_mag1 message into a struct
 *
 * @param msg The message to decode
 * @param raw_mag1 C-struct to decode the message contents into
 */
static inline void alink_msg_raw_mag1_decode(const alink_message_head_t* msg, alink_raw_mag1_t* raw_mag1)
{
#if ALINK_NEED_BYTE_SWAP
	raw_mag1->timestamp = alink_msg_raw_mag1_get_timestamp(msg);
	raw_mag1->xmag = alink_msg_raw_mag1_get_xmag(msg);
	raw_mag1->ymag = alink_msg_raw_mag1_get_ymag(msg);
	raw_mag1->zmag = alink_msg_raw_mag1_get_zmag(msg);
#else
	memcpy(raw_mag1, _MAV_PAYLOAD(msg), ALINK_MSG_ID_RAW_MAG1_LEN);
#endif
}
