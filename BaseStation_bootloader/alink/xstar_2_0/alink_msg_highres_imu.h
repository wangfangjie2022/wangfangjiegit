// MESSAGE HIGHRES_IMU PACKING

#define ALINK_MSG_ID_HIGHRES_IMU 20

typedef struct __alink_highres_imu_t
{
 uint64_t timestamp; /*< timestamp (microseconds, synced to UNIX time or since system boot)*/
 float xacc; /*< X acceleration (m/s^2)*/
 float yacc; /*< Y acceleration (m/s^2)*/
 float zacc; /*< Z acceleration (m/s^2)*/
 float xgyro; /*< Angular speed around X axis (rad / sec)*/
 float ygyro; /*< Angular speed around Y axis (rad / sec)*/
 float zgyro; /*< Angular speed around Z axis (rad / sec)*/
 float xacc_1; /*< X acceleration (m/s^2)*/
 float yacc_1; /*< Y acceleration (m/s^2)*/
 float zacc_1; /*< Z acceleration (m/s^2)*/
 float xgyro_1; /*< Angular speed around X axis (rad / sec)*/
 float ygyro_1; /*< Angular speed around Y axis (rad / sec)*/
 float zgyro_1; /*< Angular speed around Z axis (rad / sec)*/
 float xmag; /*< X Magnetic field (Gauss)*/
 float ymag; /*< Y Magnetic field (Gauss)*/
 float zmag; /*< Z Magnetic field (Gauss)*/
 float abs_pressure; /*< Absolute pressure in millibar*/
 float temperature; /*< Temperature in degrees celsius*/
 float airspeed_pressure; /*< air speed Pressure*/
 uint32_t fields_updated; /*< Bitmask for fields that have updated since last message, bit 0 = xacc, bit 12: temperature*/
} alink_highres_imu_t;

#define ALINK_MSG_ID_HIGHRES_IMU_LEN 84
#define ALINK_MSG_ID_20_LEN 84

#define ALINK_MSG_ID_HIGHRES_IMU_CRC 59
#define ALINK_MSG_ID_20_CRC 59



#define ALINK_MESSAGE_INFO_HIGHRES_IMU { \
	"HIGHRES_IMU", \
	20, \
	{  { "timestamp", NULL, ALINK_TYPE_UINT64_T, 0, 0, offsetof(alink_highres_imu_t, timestamp) }, \
         { "xacc", NULL, ALINK_TYPE_FLOAT, 0, 8, offsetof(alink_highres_imu_t, xacc) }, \
         { "yacc", NULL, ALINK_TYPE_FLOAT, 0, 12, offsetof(alink_highres_imu_t, yacc) }, \
         { "zacc", NULL, ALINK_TYPE_FLOAT, 0, 16, offsetof(alink_highres_imu_t, zacc) }, \
         { "xgyro", NULL, ALINK_TYPE_FLOAT, 0, 20, offsetof(alink_highres_imu_t, xgyro) }, \
         { "ygyro", NULL, ALINK_TYPE_FLOAT, 0, 24, offsetof(alink_highres_imu_t, ygyro) }, \
         { "zgyro", NULL, ALINK_TYPE_FLOAT, 0, 28, offsetof(alink_highres_imu_t, zgyro) }, \
         { "xacc_1", NULL, ALINK_TYPE_FLOAT, 0, 32, offsetof(alink_highres_imu_t, xacc_1) }, \
         { "yacc_1", NULL, ALINK_TYPE_FLOAT, 0, 36, offsetof(alink_highres_imu_t, yacc_1) }, \
         { "zacc_1", NULL, ALINK_TYPE_FLOAT, 0, 40, offsetof(alink_highres_imu_t, zacc_1) }, \
         { "xgyro_1", NULL, ALINK_TYPE_FLOAT, 0, 44, offsetof(alink_highres_imu_t, xgyro_1) }, \
         { "ygyro_1", NULL, ALINK_TYPE_FLOAT, 0, 48, offsetof(alink_highres_imu_t, ygyro_1) }, \
         { "zgyro_1", NULL, ALINK_TYPE_FLOAT, 0, 52, offsetof(alink_highres_imu_t, zgyro_1) }, \
         { "xmag", NULL, ALINK_TYPE_FLOAT, 0, 56, offsetof(alink_highres_imu_t, xmag) }, \
         { "ymag", NULL, ALINK_TYPE_FLOAT, 0, 60, offsetof(alink_highres_imu_t, ymag) }, \
         { "zmag", NULL, ALINK_TYPE_FLOAT, 0, 64, offsetof(alink_highres_imu_t, zmag) }, \
         { "abs_pressure", NULL, ALINK_TYPE_FLOAT, 0, 68, offsetof(alink_highres_imu_t, abs_pressure) }, \
         { "temperature", NULL, ALINK_TYPE_FLOAT, 0, 72, offsetof(alink_highres_imu_t, temperature) }, \
         { "airspeed_pressure", NULL, ALINK_TYPE_FLOAT, 0, 76, offsetof(alink_highres_imu_t, airspeed_pressure) }, \
         { "fields_updated", NULL, ALINK_TYPE_UINT32_T, 0, 80, offsetof(alink_highres_imu_t, fields_updated) }, \
         } \
}


/**
 * @brief Pack a highres_imu message
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 *
 * @param timestamp timestamp (microseconds, synced to UNIX time or since system boot)
 * @param xacc X acceleration (m/s^2)
 * @param yacc Y acceleration (m/s^2)
 * @param zacc Z acceleration (m/s^2)
 * @param xgyro Angular speed around X axis (rad / sec)
 * @param ygyro Angular speed around Y axis (rad / sec)
 * @param zgyro Angular speed around Z axis (rad / sec)
 * @param xacc_1 X acceleration (m/s^2)
 * @param yacc_1 Y acceleration (m/s^2)
 * @param zacc_1 Z acceleration (m/s^2)
 * @param xgyro_1 Angular speed around X axis (rad / sec)
 * @param ygyro_1 Angular speed around Y axis (rad / sec)
 * @param zgyro_1 Angular speed around Z axis (rad / sec)
 * @param xmag X Magnetic field (Gauss)
 * @param ymag Y Magnetic field (Gauss)
 * @param zmag Z Magnetic field (Gauss)
 * @param abs_pressure Absolute pressure in millibar
 * @param temperature Temperature in degrees celsius
 * @param airspeed_pressure air speed Pressure
 * @param fields_updated Bitmask for fields that have updated since last message, bit 0 = xacc, bit 12: temperature
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_highres_imu_pack(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg,
						       uint64_t timestamp, float xacc, float yacc, float zacc, float xgyro, float ygyro, float zgyro, float xacc_1, float yacc_1, float zacc_1, float xgyro_1, float ygyro_1, float zgyro_1, float xmag, float ymag, float zmag, float abs_pressure, float temperature, float airspeed_pressure, uint32_t fields_updated)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_HIGHRES_IMU_LEN];
	_mav_put_uint64_t(buf, 0, timestamp);
	_mav_put_float(buf, 8, xacc);
	_mav_put_float(buf, 12, yacc);
	_mav_put_float(buf, 16, zacc);
	_mav_put_float(buf, 20, xgyro);
	_mav_put_float(buf, 24, ygyro);
	_mav_put_float(buf, 28, zgyro);
	_mav_put_float(buf, 32, xacc_1);
	_mav_put_float(buf, 36, yacc_1);
	_mav_put_float(buf, 40, zacc_1);
	_mav_put_float(buf, 44, xgyro_1);
	_mav_put_float(buf, 48, ygyro_1);
	_mav_put_float(buf, 52, zgyro_1);
	_mav_put_float(buf, 56, xmag);
	_mav_put_float(buf, 60, ymag);
	_mav_put_float(buf, 64, zmag);
	_mav_put_float(buf, 68, abs_pressure);
	_mav_put_float(buf, 72, temperature);
	_mav_put_float(buf, 76, airspeed_pressure);
	_mav_put_uint32_t(buf, 80, fields_updated);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_HIGHRES_IMU_LEN);
#else
	alink_highres_imu_t packet;
	packet.timestamp = timestamp;
	packet.xacc = xacc;
	packet.yacc = yacc;
	packet.zacc = zacc;
	packet.xgyro = xgyro;
	packet.ygyro = ygyro;
	packet.zgyro = zgyro;
	packet.xacc_1 = xacc_1;
	packet.yacc_1 = yacc_1;
	packet.zacc_1 = zacc_1;
	packet.xgyro_1 = xgyro_1;
	packet.ygyro_1 = ygyro_1;
	packet.zgyro_1 = zgyro_1;
	packet.xmag = xmag;
	packet.ymag = ymag;
	packet.zmag = zmag;
	packet.abs_pressure = abs_pressure;
	packet.temperature = temperature;
	packet.airspeed_pressure = airspeed_pressure;
	packet.fields_updated = fields_updated;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_HIGHRES_IMU_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_HIGHRES_IMU;
#if ALINK_CRC_EXTRA
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_HIGHRES_IMU_LEN,ALINK_MSG_ID_HIGHRES_IMU_CRC);
#else
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_HIGHRES_IMU_LEN);
#endif
}

/**
 * @brief Pack a highres_imu message on a channel
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param timestamp timestamp (microseconds, synced to UNIX time or since system boot)
 * @param xacc X acceleration (m/s^2)
 * @param yacc Y acceleration (m/s^2)
 * @param zacc Z acceleration (m/s^2)
 * @param xgyro Angular speed around X axis (rad / sec)
 * @param ygyro Angular speed around Y axis (rad / sec)
 * @param zgyro Angular speed around Z axis (rad / sec)
 * @param xacc_1 X acceleration (m/s^2)
 * @param yacc_1 Y acceleration (m/s^2)
 * @param zacc_1 Z acceleration (m/s^2)
 * @param xgyro_1 Angular speed around X axis (rad / sec)
 * @param ygyro_1 Angular speed around Y axis (rad / sec)
 * @param zgyro_1 Angular speed around Z axis (rad / sec)
 * @param xmag X Magnetic field (Gauss)
 * @param ymag Y Magnetic field (Gauss)
 * @param zmag Z Magnetic field (Gauss)
 * @param abs_pressure Absolute pressure in millibar
 * @param temperature Temperature in degrees celsius
 * @param airspeed_pressure air speed Pressure
 * @param fields_updated Bitmask for fields that have updated since last message, bit 0 = xacc, bit 12: temperature
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_highres_imu_pack_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan,
							   alink_message_head_t* msg,
						           uint64_t timestamp,float xacc,float yacc,float zacc,float xgyro,float ygyro,float zgyro,float xacc_1,float yacc_1,float zacc_1,float xgyro_1,float ygyro_1,float zgyro_1,float xmag,float ymag,float zmag,float abs_pressure,float temperature,float airspeed_pressure,uint32_t fields_updated)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_HIGHRES_IMU_LEN];
	_mav_put_uint64_t(buf, 0, timestamp);
	_mav_put_float(buf, 8, xacc);
	_mav_put_float(buf, 12, yacc);
	_mav_put_float(buf, 16, zacc);
	_mav_put_float(buf, 20, xgyro);
	_mav_put_float(buf, 24, ygyro);
	_mav_put_float(buf, 28, zgyro);
	_mav_put_float(buf, 32, xacc_1);
	_mav_put_float(buf, 36, yacc_1);
	_mav_put_float(buf, 40, zacc_1);
	_mav_put_float(buf, 44, xgyro_1);
	_mav_put_float(buf, 48, ygyro_1);
	_mav_put_float(buf, 52, zgyro_1);
	_mav_put_float(buf, 56, xmag);
	_mav_put_float(buf, 60, ymag);
	_mav_put_float(buf, 64, zmag);
	_mav_put_float(buf, 68, abs_pressure);
	_mav_put_float(buf, 72, temperature);
	_mav_put_float(buf, 76, airspeed_pressure);
	_mav_put_uint32_t(buf, 80, fields_updated);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_HIGHRES_IMU_LEN);
#else
	alink_highres_imu_t packet;
	packet.timestamp = timestamp;
	packet.xacc = xacc;
	packet.yacc = yacc;
	packet.zacc = zacc;
	packet.xgyro = xgyro;
	packet.ygyro = ygyro;
	packet.zgyro = zgyro;
	packet.xacc_1 = xacc_1;
	packet.yacc_1 = yacc_1;
	packet.zacc_1 = zacc_1;
	packet.xgyro_1 = xgyro_1;
	packet.ygyro_1 = ygyro_1;
	packet.zgyro_1 = zgyro_1;
	packet.xmag = xmag;
	packet.ymag = ymag;
	packet.zmag = zmag;
	packet.abs_pressure = abs_pressure;
	packet.temperature = temperature;
	packet.airspeed_pressure = airspeed_pressure;
	packet.fields_updated = fields_updated;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_HIGHRES_IMU_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_HIGHRES_IMU;
#if ALINK_CRC_EXTRA
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_HIGHRES_IMU_LEN,ALINK_MSG_ID_HIGHRES_IMU_CRC);
#else
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_HIGHRES_IMU_LEN);
#endif
}
/**
 * @brief Encode a highres_imu struct
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 * @param highres_imu C-struct to read the message contents from
 */
static inline uint16_t alink_msg_highres_imu_encode(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg, const alink_highres_imu_t* highres_imu)
{
	return alink_msg_highres_imu_pack(dest_id, source_id, msg, highres_imu->timestamp, highres_imu->xacc, highres_imu->yacc, highres_imu->zacc, highres_imu->xgyro, highres_imu->ygyro, highres_imu->zgyro, highres_imu->xacc_1, highres_imu->yacc_1, highres_imu->zacc_1, highres_imu->xgyro_1, highres_imu->ygyro_1, highres_imu->zgyro_1, highres_imu->xmag, highres_imu->ymag, highres_imu->zmag, highres_imu->abs_pressure, highres_imu->temperature, highres_imu->airspeed_pressure, highres_imu->fields_updated);
}

/**
 * @brief Encode a highres_imu struct on a channel
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param highres_imu C-struct to read the message contents from
 */
static inline uint16_t alink_msg_highres_imu_encode_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan, alink_message_head_t* msg, const alink_highres_imu_t* highres_imu)
{
	return alink_msg_highres_imu_pack_chan(dest_id, source_id, chan, msg, highres_imu->timestamp, highres_imu->xacc, highres_imu->yacc, highres_imu->zacc, highres_imu->xgyro, highres_imu->ygyro, highres_imu->zgyro, highres_imu->xacc_1, highres_imu->yacc_1, highres_imu->zacc_1, highres_imu->xgyro_1, highres_imu->ygyro_1, highres_imu->zgyro_1, highres_imu->xmag, highres_imu->ymag, highres_imu->zmag, highres_imu->abs_pressure, highres_imu->temperature, highres_imu->airspeed_pressure, highres_imu->fields_updated);
}
// MESSAGE HIGHRES_IMU UNPACKING


/**
 * @brief Get field timestamp from highres_imu message
 *
 * @return timestamp (microseconds, synced to UNIX time or since system boot)
 */
static inline uint64_t alink_msg_highres_imu_get_timestamp(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field xacc from highres_imu message
 *
 * @return X acceleration (m/s^2)
 */
static inline float alink_msg_highres_imu_get_xacc(const alink_message_head_t* msg)
{
	return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field yacc from highres_imu message
 *
 * @return Y acceleration (m/s^2)
 */
static inline float alink_msg_highres_imu_get_yacc(const alink_message_head_t* msg)
{
	return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field zacc from highres_imu message
 *
 * @return Z acceleration (m/s^2)
 */
static inline float alink_msg_highres_imu_get_zacc(const alink_message_head_t* msg)
{
	return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Get field xgyro from highres_imu message
 *
 * @return Angular speed around X axis (rad / sec)
 */
static inline float alink_msg_highres_imu_get_xgyro(const alink_message_head_t* msg)
{
	return _MAV_RETURN_float(msg,  20);
}

/**
 * @brief Get field ygyro from highres_imu message
 *
 * @return Angular speed around Y axis (rad / sec)
 */
static inline float alink_msg_highres_imu_get_ygyro(const alink_message_head_t* msg)
{
	return _MAV_RETURN_float(msg,  24);
}

/**
 * @brief Get field zgyro from highres_imu message
 *
 * @return Angular speed around Z axis (rad / sec)
 */
static inline float alink_msg_highres_imu_get_zgyro(const alink_message_head_t* msg)
{
	return _MAV_RETURN_float(msg,  28);
}

/**
 * @brief Get field xacc_1 from highres_imu message
 *
 * @return X acceleration (m/s^2)
 */
static inline float alink_msg_highres_imu_get_xacc_1(const alink_message_head_t* msg)
{
	return _MAV_RETURN_float(msg,  32);
}

/**
 * @brief Get field yacc_1 from highres_imu message
 *
 * @return Y acceleration (m/s^2)
 */
static inline float alink_msg_highres_imu_get_yacc_1(const alink_message_head_t* msg)
{
	return _MAV_RETURN_float(msg,  36);
}

/**
 * @brief Get field zacc_1 from highres_imu message
 *
 * @return Z acceleration (m/s^2)
 */
static inline float alink_msg_highres_imu_get_zacc_1(const alink_message_head_t* msg)
{
	return _MAV_RETURN_float(msg,  40);
}

/**
 * @brief Get field xgyro_1 from highres_imu message
 *
 * @return Angular speed around X axis (rad / sec)
 */
static inline float alink_msg_highres_imu_get_xgyro_1(const alink_message_head_t* msg)
{
	return _MAV_RETURN_float(msg,  44);
}

/**
 * @brief Get field ygyro_1 from highres_imu message
 *
 * @return Angular speed around Y axis (rad / sec)
 */
static inline float alink_msg_highres_imu_get_ygyro_1(const alink_message_head_t* msg)
{
	return _MAV_RETURN_float(msg,  48);
}

/**
 * @brief Get field zgyro_1 from highres_imu message
 *
 * @return Angular speed around Z axis (rad / sec)
 */
static inline float alink_msg_highres_imu_get_zgyro_1(const alink_message_head_t* msg)
{
	return _MAV_RETURN_float(msg,  52);
}

/**
 * @brief Get field xmag from highres_imu message
 *
 * @return X Magnetic field (Gauss)
 */
static inline float alink_msg_highres_imu_get_xmag(const alink_message_head_t* msg)
{
	return _MAV_RETURN_float(msg,  56);
}

/**
 * @brief Get field ymag from highres_imu message
 *
 * @return Y Magnetic field (Gauss)
 */
static inline float alink_msg_highres_imu_get_ymag(const alink_message_head_t* msg)
{
	return _MAV_RETURN_float(msg,  60);
}

/**
 * @brief Get field zmag from highres_imu message
 *
 * @return Z Magnetic field (Gauss)
 */
static inline float alink_msg_highres_imu_get_zmag(const alink_message_head_t* msg)
{
	return _MAV_RETURN_float(msg,  64);
}

/**
 * @brief Get field abs_pressure from highres_imu message
 *
 * @return Absolute pressure in millibar
 */
static inline float alink_msg_highres_imu_get_abs_pressure(const alink_message_head_t* msg)
{
	return _MAV_RETURN_float(msg,  68);
}

/**
 * @brief Get field temperature from highres_imu message
 *
 * @return Temperature in degrees celsius
 */
static inline float alink_msg_highres_imu_get_temperature(const alink_message_head_t* msg)
{
	return _MAV_RETURN_float(msg,  72);
}

/**
 * @brief Get field airspeed_pressure from highres_imu message
 *
 * @return air speed Pressure
 */
static inline float alink_msg_highres_imu_get_airspeed_pressure(const alink_message_head_t* msg)
{
	return _MAV_RETURN_float(msg,  76);
}

/**
 * @brief Get field fields_updated from highres_imu message
 *
 * @return Bitmask for fields that have updated since last message, bit 0 = xacc, bit 12: temperature
 */
static inline uint32_t alink_msg_highres_imu_get_fields_updated(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint32_t(msg,  80);
}

/**
 * @brief Decode a highres_imu message into a struct
 *
 * @param msg The message to decode
 * @param highres_imu C-struct to decode the message contents into
 */
static inline void alink_msg_highres_imu_decode(const alink_message_head_t* msg, alink_highres_imu_t* highres_imu)
{
#if ALINK_NEED_BYTE_SWAP
	highres_imu->timestamp = alink_msg_highres_imu_get_timestamp(msg);
	highres_imu->xacc = alink_msg_highres_imu_get_xacc(msg);
	highres_imu->yacc = alink_msg_highres_imu_get_yacc(msg);
	highres_imu->zacc = alink_msg_highres_imu_get_zacc(msg);
	highres_imu->xgyro = alink_msg_highres_imu_get_xgyro(msg);
	highres_imu->ygyro = alink_msg_highres_imu_get_ygyro(msg);
	highres_imu->zgyro = alink_msg_highres_imu_get_zgyro(msg);
	highres_imu->xacc_1 = alink_msg_highres_imu_get_xacc_1(msg);
	highres_imu->yacc_1 = alink_msg_highres_imu_get_yacc_1(msg);
	highres_imu->zacc_1 = alink_msg_highres_imu_get_zacc_1(msg);
	highres_imu->xgyro_1 = alink_msg_highres_imu_get_xgyro_1(msg);
	highres_imu->ygyro_1 = alink_msg_highres_imu_get_ygyro_1(msg);
	highres_imu->zgyro_1 = alink_msg_highres_imu_get_zgyro_1(msg);
	highres_imu->xmag = alink_msg_highres_imu_get_xmag(msg);
	highres_imu->ymag = alink_msg_highres_imu_get_ymag(msg);
	highres_imu->zmag = alink_msg_highres_imu_get_zmag(msg);
	highres_imu->abs_pressure = alink_msg_highres_imu_get_abs_pressure(msg);
	highres_imu->temperature = alink_msg_highres_imu_get_temperature(msg);
	highres_imu->airspeed_pressure = alink_msg_highres_imu_get_airspeed_pressure(msg);
	highres_imu->fields_updated = alink_msg_highres_imu_get_fields_updated(msg);
#else
	memcpy(highres_imu, _MAV_PAYLOAD(msg), ALINK_MSG_ID_HIGHRES_IMU_LEN);
#endif
}
