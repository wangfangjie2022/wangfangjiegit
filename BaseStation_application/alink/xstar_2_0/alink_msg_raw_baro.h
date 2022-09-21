// MESSAGE RAW_BARO PACKING

#define ALINK_MSG_ID_RAW_BARO 28

typedef struct __alink_raw_baro_t
{
 uint64_t timestamp; /*< timestamp (microseconds since UNIX epoch or microseconds since system boot)*/
 float pbaro; /*< Pressure baro (mpa)*/
 int16_t tbaro; /*< Temperature baro*/
} alink_raw_baro_t;

#define ALINK_MSG_ID_RAW_BARO_LEN 14
#define ALINK_MSG_ID_28_LEN 14

#define ALINK_MSG_ID_RAW_BARO_CRC 196
#define ALINK_MSG_ID_28_CRC 196



#define ALINK_MESSAGE_INFO_RAW_BARO { \
	"RAW_BARO", \
	3, \
	{  { "timestamp", NULL, ALINK_TYPE_UINT64_T, 0, 0, offsetof(alink_raw_baro_t, timestamp) }, \
         { "pbaro", NULL, ALINK_TYPE_FLOAT, 0, 8, offsetof(alink_raw_baro_t, pbaro) }, \
         { "tbaro", NULL, ALINK_TYPE_INT16_T, 0, 12, offsetof(alink_raw_baro_t, tbaro) }, \
         } \
}


/**
 * @brief Pack a raw_baro message
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 *
 * @param timestamp timestamp (microseconds since UNIX epoch or microseconds since system boot)
 * @param pbaro Pressure baro (mpa)
 * @param tbaro Temperature baro
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_raw_baro_pack(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg,
						       uint64_t timestamp, float pbaro, int16_t tbaro)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_RAW_BARO_LEN];
	_mav_put_uint64_t(buf, 0, timestamp);
	_mav_put_float(buf, 8, pbaro);
	_mav_put_int16_t(buf, 12, tbaro);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_RAW_BARO_LEN);
#else
	alink_raw_baro_t packet;
	packet.timestamp = timestamp;
	packet.pbaro = pbaro;
	packet.tbaro = tbaro;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_RAW_BARO_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_RAW_BARO;
#if ALINK_CRC_EXTRA
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_RAW_BARO_LEN,ALINK_MSG_ID_RAW_BARO_CRC);
#else
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_RAW_BARO_LEN);
#endif
}

/**
 * @brief Pack a raw_baro message on a channel
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param timestamp timestamp (microseconds since UNIX epoch or microseconds since system boot)
 * @param pbaro Pressure baro (mpa)
 * @param tbaro Temperature baro
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_raw_baro_pack_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan,
							   alink_message_head_t* msg,
						           uint64_t timestamp,float pbaro,int16_t tbaro)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_RAW_BARO_LEN];
	_mav_put_uint64_t(buf, 0, timestamp);
	_mav_put_float(buf, 8, pbaro);
	_mav_put_int16_t(buf, 12, tbaro);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_RAW_BARO_LEN);
#else
	alink_raw_baro_t packet;
	packet.timestamp = timestamp;
	packet.pbaro = pbaro;
	packet.tbaro = tbaro;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_RAW_BARO_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_RAW_BARO;
#if ALINK_CRC_EXTRA
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_RAW_BARO_LEN,ALINK_MSG_ID_RAW_BARO_CRC);
#else
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_RAW_BARO_LEN);
#endif
}
/**
 * @brief Encode a raw_baro struct
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 * @param raw_baro C-struct to read the message contents from
 */
static inline uint16_t alink_msg_raw_baro_encode(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg, const alink_raw_baro_t* raw_baro)
{
	return alink_msg_raw_baro_pack(dest_id, source_id, msg, raw_baro->timestamp, raw_baro->pbaro, raw_baro->tbaro);
}

/**
 * @brief Encode a raw_baro struct on a channel
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param raw_baro C-struct to read the message contents from
 */
static inline uint16_t alink_msg_raw_baro_encode_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan, alink_message_head_t* msg, const alink_raw_baro_t* raw_baro)
{
	return alink_msg_raw_baro_pack_chan(dest_id, source_id, chan, msg, raw_baro->timestamp, raw_baro->pbaro, raw_baro->tbaro);
}
// MESSAGE RAW_BARO UNPACKING


/**
 * @brief Get field timestamp from raw_baro message
 *
 * @return timestamp (microseconds since UNIX epoch or microseconds since system boot)
 */
static inline uint64_t alink_msg_raw_baro_get_timestamp(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field pbaro from raw_baro message
 *
 * @return Pressure baro (mpa)
 */
static inline float alink_msg_raw_baro_get_pbaro(const alink_message_head_t* msg)
{
	return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field tbaro from raw_baro message
 *
 * @return Temperature baro
 */
static inline int16_t alink_msg_raw_baro_get_tbaro(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  12);
}

/**
 * @brief Decode a raw_baro message into a struct
 *
 * @param msg The message to decode
 * @param raw_baro C-struct to decode the message contents into
 */
static inline void alink_msg_raw_baro_decode(const alink_message_head_t* msg, alink_raw_baro_t* raw_baro)
{
#if ALINK_NEED_BYTE_SWAP
	raw_baro->timestamp = alink_msg_raw_baro_get_timestamp(msg);
	raw_baro->pbaro = alink_msg_raw_baro_get_pbaro(msg);
	raw_baro->tbaro = alink_msg_raw_baro_get_tbaro(msg);
#else
	memcpy(raw_baro, _MAV_PAYLOAD(msg), ALINK_MSG_ID_RAW_BARO_LEN);
#endif
}
