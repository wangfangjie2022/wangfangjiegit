// MESSAGE GPS_FOLLOW_TARGET PACKING

#define ALINK_MSG_ID_GPS_FOLLOW_TARGET 87

typedef struct __alink_gps_follow_target_t
{
 int32_t latitude; /*< target latitude*/
 int32_t longitude; /*< target longitude*/
 int32_t altitude; /*< target altitude*/
 int32_t precision; /*< precision of position information*/
} alink_gps_follow_target_t;

#define ALINK_MSG_ID_GPS_FOLLOW_TARGET_LEN 16
#define ALINK_MSG_ID_87_LEN 16

#define ALINK_MSG_ID_GPS_FOLLOW_TARGET_CRC 149
#define ALINK_MSG_ID_87_CRC 149



#define ALINK_MESSAGE_INFO_GPS_FOLLOW_TARGET { \
	"GPS_FOLLOW_TARGET", \
	4, \
	{  { "latitude", NULL, ALINK_TYPE_INT32_T, 0, 0, offsetof(alink_gps_follow_target_t, latitude) }, \
         { "longitude", NULL, ALINK_TYPE_INT32_T, 0, 4, offsetof(alink_gps_follow_target_t, longitude) }, \
         { "altitude", NULL, ALINK_TYPE_INT32_T, 0, 8, offsetof(alink_gps_follow_target_t, altitude) }, \
         { "precision", NULL, ALINK_TYPE_INT32_T, 0, 12, offsetof(alink_gps_follow_target_t, precision) }, \
         } \
}


/**
 * @brief Pack a gps_follow_target message
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 *
 * @param latitude target latitude
 * @param longitude target longitude
 * @param altitude target altitude
 * @param precision precision of position information
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_gps_follow_target_pack(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg,
						       int32_t latitude, int32_t longitude, int32_t altitude, int32_t precision)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_GPS_FOLLOW_TARGET_LEN];
	_mav_put_int32_t(buf, 0, latitude);
	_mav_put_int32_t(buf, 4, longitude);
	_mav_put_int32_t(buf, 8, altitude);
	_mav_put_int32_t(buf, 12, precision);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_GPS_FOLLOW_TARGET_LEN);
#else
	alink_gps_follow_target_t packet;
	packet.latitude = latitude;
	packet.longitude = longitude;
	packet.altitude = altitude;
	packet.precision = precision;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_GPS_FOLLOW_TARGET_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_GPS_FOLLOW_TARGET;
#if ALINK_CRC_EXTRA
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_GPS_FOLLOW_TARGET_LEN,ALINK_MSG_ID_GPS_FOLLOW_TARGET_CRC);
#else
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_GPS_FOLLOW_TARGET_LEN);
#endif
}

/**
 * @brief Pack a gps_follow_target message on a channel
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param latitude target latitude
 * @param longitude target longitude
 * @param altitude target altitude
 * @param precision precision of position information
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_gps_follow_target_pack_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan,
							   alink_message_head_t* msg,
						           int32_t latitude,int32_t longitude,int32_t altitude,int32_t precision)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_GPS_FOLLOW_TARGET_LEN];
	_mav_put_int32_t(buf, 0, latitude);
	_mav_put_int32_t(buf, 4, longitude);
	_mav_put_int32_t(buf, 8, altitude);
	_mav_put_int32_t(buf, 12, precision);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_GPS_FOLLOW_TARGET_LEN);
#else
	alink_gps_follow_target_t packet;
	packet.latitude = latitude;
	packet.longitude = longitude;
	packet.altitude = altitude;
	packet.precision = precision;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_GPS_FOLLOW_TARGET_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_GPS_FOLLOW_TARGET;
#if ALINK_CRC_EXTRA
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_GPS_FOLLOW_TARGET_LEN,ALINK_MSG_ID_GPS_FOLLOW_TARGET_CRC);
#else
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_GPS_FOLLOW_TARGET_LEN);
#endif
}
/**
 * @brief Encode a gps_follow_target struct
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 * @param gps_follow_target C-struct to read the message contents from
 */
static inline uint16_t alink_msg_gps_follow_target_encode(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg, const alink_gps_follow_target_t* gps_follow_target)
{
	return alink_msg_gps_follow_target_pack(dest_id, source_id, msg, gps_follow_target->latitude, gps_follow_target->longitude, gps_follow_target->altitude, gps_follow_target->precision);
}

/**
 * @brief Encode a gps_follow_target struct on a channel
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param gps_follow_target C-struct to read the message contents from
 */
static inline uint16_t alink_msg_gps_follow_target_encode_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan, alink_message_head_t* msg, const alink_gps_follow_target_t* gps_follow_target)
{
	return alink_msg_gps_follow_target_pack_chan(dest_id, source_id, chan, msg, gps_follow_target->latitude, gps_follow_target->longitude, gps_follow_target->altitude, gps_follow_target->precision);
}
// MESSAGE GPS_FOLLOW_TARGET UNPACKING


/**
 * @brief Get field latitude from gps_follow_target message
 *
 * @return target latitude
 */
static inline int32_t alink_msg_gps_follow_target_get_latitude(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  0);
}

/**
 * @brief Get field longitude from gps_follow_target message
 *
 * @return target longitude
 */
static inline int32_t alink_msg_gps_follow_target_get_longitude(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  4);
}

/**
 * @brief Get field altitude from gps_follow_target message
 *
 * @return target altitude
 */
static inline int32_t alink_msg_gps_follow_target_get_altitude(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  8);
}

/**
 * @brief Get field precision from gps_follow_target message
 *
 * @return precision of position information
 */
static inline int32_t alink_msg_gps_follow_target_get_precision(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  12);
}

/**
 * @brief Decode a gps_follow_target message into a struct
 *
 * @param msg The message to decode
 * @param gps_follow_target C-struct to decode the message contents into
 */
static inline void alink_msg_gps_follow_target_decode(const alink_message_head_t* msg, alink_gps_follow_target_t* gps_follow_target)
{
#if ALINK_NEED_BYTE_SWAP
	gps_follow_target->latitude = alink_msg_gps_follow_target_get_latitude(msg);
	gps_follow_target->longitude = alink_msg_gps_follow_target_get_longitude(msg);
	gps_follow_target->altitude = alink_msg_gps_follow_target_get_altitude(msg);
	gps_follow_target->precision = alink_msg_gps_follow_target_get_precision(msg);
#else
	memcpy(gps_follow_target, _MAV_PAYLOAD(msg), ALINK_MSG_ID_GPS_FOLLOW_TARGET_LEN);
#endif
}
