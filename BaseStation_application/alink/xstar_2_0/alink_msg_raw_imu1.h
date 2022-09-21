// MESSAGE RAW_IMU1 PACKING

#define ALINK_MSG_ID_RAW_IMU1 27

typedef struct __alink_raw_imu1_t
{
 uint64_t timestamp; /*< timestamp (microseconds since UNIX epoch or microseconds since system boot)*/
 int16_t xacc; /*< X acceleration (raw)*/
 int16_t yacc; /*< Y acceleration (raw)*/
 int16_t zacc; /*< Z acceleration (raw)*/
 int16_t xgyro; /*< Angular speed around X axis (raw)*/
 int16_t ygyro; /*< Angular speed around Y axis (raw)*/
 int16_t zgyro; /*< Angular speed around Z axis (raw)*/
 int16_t temperature; /*< tempeature of sensor degree*/
} alink_raw_imu1_t;

#define ALINK_MSG_ID_RAW_IMU1_LEN 22
#define ALINK_MSG_ID_27_LEN 22

#define ALINK_MSG_ID_RAW_IMU1_CRC 46
#define ALINK_MSG_ID_27_CRC 46



#define ALINK_MESSAGE_INFO_RAW_IMU1 { \
	"RAW_IMU1", \
	8, \
	{  { "timestamp", NULL, ALINK_TYPE_UINT64_T, 0, 0, offsetof(alink_raw_imu1_t, timestamp) }, \
         { "xacc", NULL, ALINK_TYPE_INT16_T, 0, 8, offsetof(alink_raw_imu1_t, xacc) }, \
         { "yacc", NULL, ALINK_TYPE_INT16_T, 0, 10, offsetof(alink_raw_imu1_t, yacc) }, \
         { "zacc", NULL, ALINK_TYPE_INT16_T, 0, 12, offsetof(alink_raw_imu1_t, zacc) }, \
         { "xgyro", NULL, ALINK_TYPE_INT16_T, 0, 14, offsetof(alink_raw_imu1_t, xgyro) }, \
         { "ygyro", NULL, ALINK_TYPE_INT16_T, 0, 16, offsetof(alink_raw_imu1_t, ygyro) }, \
         { "zgyro", NULL, ALINK_TYPE_INT16_T, 0, 18, offsetof(alink_raw_imu1_t, zgyro) }, \
         { "temperature", NULL, ALINK_TYPE_INT16_T, 0, 20, offsetof(alink_raw_imu1_t, temperature) }, \
         } \
}


/**
 * @brief Pack a raw_imu1 message
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 *
 * @param timestamp timestamp (microseconds since UNIX epoch or microseconds since system boot)
 * @param xacc X acceleration (raw)
 * @param yacc Y acceleration (raw)
 * @param zacc Z acceleration (raw)
 * @param xgyro Angular speed around X axis (raw)
 * @param ygyro Angular speed around Y axis (raw)
 * @param zgyro Angular speed around Z axis (raw)
 * @param temperature tempeature of sensor degree
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_raw_imu1_pack(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg,
						       uint64_t timestamp, int16_t xacc, int16_t yacc, int16_t zacc, int16_t xgyro, int16_t ygyro, int16_t zgyro, int16_t temperature)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_RAW_IMU1_LEN];
	_mav_put_uint64_t(buf, 0, timestamp);
	_mav_put_int16_t(buf, 8, xacc);
	_mav_put_int16_t(buf, 10, yacc);
	_mav_put_int16_t(buf, 12, zacc);
	_mav_put_int16_t(buf, 14, xgyro);
	_mav_put_int16_t(buf, 16, ygyro);
	_mav_put_int16_t(buf, 18, zgyro);
	_mav_put_int16_t(buf, 20, temperature);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_RAW_IMU1_LEN);
#else
	alink_raw_imu1_t packet;
	packet.timestamp = timestamp;
	packet.xacc = xacc;
	packet.yacc = yacc;
	packet.zacc = zacc;
	packet.xgyro = xgyro;
	packet.ygyro = ygyro;
	packet.zgyro = zgyro;
	packet.temperature = temperature;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_RAW_IMU1_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_RAW_IMU1;
#if ALINK_CRC_EXTRA
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_RAW_IMU1_LEN,ALINK_MSG_ID_RAW_IMU1_CRC);
#else
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_RAW_IMU1_LEN);
#endif
}

/**
 * @brief Pack a raw_imu1 message on a channel
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param timestamp timestamp (microseconds since UNIX epoch or microseconds since system boot)
 * @param xacc X acceleration (raw)
 * @param yacc Y acceleration (raw)
 * @param zacc Z acceleration (raw)
 * @param xgyro Angular speed around X axis (raw)
 * @param ygyro Angular speed around Y axis (raw)
 * @param zgyro Angular speed around Z axis (raw)
 * @param temperature tempeature of sensor degree
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_raw_imu1_pack_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan,
							   alink_message_head_t* msg,
						           uint64_t timestamp,int16_t xacc,int16_t yacc,int16_t zacc,int16_t xgyro,int16_t ygyro,int16_t zgyro,int16_t temperature)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_RAW_IMU1_LEN];
	_mav_put_uint64_t(buf, 0, timestamp);
	_mav_put_int16_t(buf, 8, xacc);
	_mav_put_int16_t(buf, 10, yacc);
	_mav_put_int16_t(buf, 12, zacc);
	_mav_put_int16_t(buf, 14, xgyro);
	_mav_put_int16_t(buf, 16, ygyro);
	_mav_put_int16_t(buf, 18, zgyro);
	_mav_put_int16_t(buf, 20, temperature);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_RAW_IMU1_LEN);
#else
	alink_raw_imu1_t packet;
	packet.timestamp = timestamp;
	packet.xacc = xacc;
	packet.yacc = yacc;
	packet.zacc = zacc;
	packet.xgyro = xgyro;
	packet.ygyro = ygyro;
	packet.zgyro = zgyro;
	packet.temperature = temperature;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_RAW_IMU1_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_RAW_IMU1;
#if ALINK_CRC_EXTRA
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_RAW_IMU1_LEN,ALINK_MSG_ID_RAW_IMU1_CRC);
#else
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_RAW_IMU1_LEN);
#endif
}
/**
 * @brief Encode a raw_imu1 struct
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 * @param raw_imu1 C-struct to read the message contents from
 */
static inline uint16_t alink_msg_raw_imu1_encode(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg, const alink_raw_imu1_t* raw_imu1)
{
	return alink_msg_raw_imu1_pack(dest_id, source_id, msg, raw_imu1->timestamp, raw_imu1->xacc, raw_imu1->yacc, raw_imu1->zacc, raw_imu1->xgyro, raw_imu1->ygyro, raw_imu1->zgyro, raw_imu1->temperature);
}

/**
 * @brief Encode a raw_imu1 struct on a channel
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param raw_imu1 C-struct to read the message contents from
 */
static inline uint16_t alink_msg_raw_imu1_encode_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan, alink_message_head_t* msg, const alink_raw_imu1_t* raw_imu1)
{
	return alink_msg_raw_imu1_pack_chan(dest_id, source_id, chan, msg, raw_imu1->timestamp, raw_imu1->xacc, raw_imu1->yacc, raw_imu1->zacc, raw_imu1->xgyro, raw_imu1->ygyro, raw_imu1->zgyro, raw_imu1->temperature);
}
// MESSAGE RAW_IMU1 UNPACKING


/**
 * @brief Get field timestamp from raw_imu1 message
 *
 * @return timestamp (microseconds since UNIX epoch or microseconds since system boot)
 */
static inline uint64_t alink_msg_raw_imu1_get_timestamp(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field xacc from raw_imu1 message
 *
 * @return X acceleration (raw)
 */
static inline int16_t alink_msg_raw_imu1_get_xacc(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  8);
}

/**
 * @brief Get field yacc from raw_imu1 message
 *
 * @return Y acceleration (raw)
 */
static inline int16_t alink_msg_raw_imu1_get_yacc(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  10);
}

/**
 * @brief Get field zacc from raw_imu1 message
 *
 * @return Z acceleration (raw)
 */
static inline int16_t alink_msg_raw_imu1_get_zacc(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  12);
}

/**
 * @brief Get field xgyro from raw_imu1 message
 *
 * @return Angular speed around X axis (raw)
 */
static inline int16_t alink_msg_raw_imu1_get_xgyro(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  14);
}

/**
 * @brief Get field ygyro from raw_imu1 message
 *
 * @return Angular speed around Y axis (raw)
 */
static inline int16_t alink_msg_raw_imu1_get_ygyro(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  16);
}

/**
 * @brief Get field zgyro from raw_imu1 message
 *
 * @return Angular speed around Z axis (raw)
 */
static inline int16_t alink_msg_raw_imu1_get_zgyro(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  18);
}

/**
 * @brief Get field temperature from raw_imu1 message
 *
 * @return tempeature of sensor degree
 */
static inline int16_t alink_msg_raw_imu1_get_temperature(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  20);
}

/**
 * @brief Decode a raw_imu1 message into a struct
 *
 * @param msg The message to decode
 * @param raw_imu1 C-struct to decode the message contents into
 */
static inline void alink_msg_raw_imu1_decode(const alink_message_head_t* msg, alink_raw_imu1_t* raw_imu1)
{
#if ALINK_NEED_BYTE_SWAP
	raw_imu1->timestamp = alink_msg_raw_imu1_get_timestamp(msg);
	raw_imu1->xacc = alink_msg_raw_imu1_get_xacc(msg);
	raw_imu1->yacc = alink_msg_raw_imu1_get_yacc(msg);
	raw_imu1->zacc = alink_msg_raw_imu1_get_zacc(msg);
	raw_imu1->xgyro = alink_msg_raw_imu1_get_xgyro(msg);
	raw_imu1->ygyro = alink_msg_raw_imu1_get_ygyro(msg);
	raw_imu1->zgyro = alink_msg_raw_imu1_get_zgyro(msg);
	raw_imu1->temperature = alink_msg_raw_imu1_get_temperature(msg);
#else
	memcpy(raw_imu1, _MAV_PAYLOAD(msg), ALINK_MSG_ID_RAW_IMU1_LEN);
#endif
}
