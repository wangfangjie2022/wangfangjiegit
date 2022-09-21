#include <stdint.h>

// MESSAGE RTK_LOCATION PACKING

#define ALINK_MSG_ID_RTK_LOCATION 169
#pragma pack(1)
typedef struct __alink_rtk_location_t
{
 int32_t latitude; /*< latitude, 10E-7deg*/
 int32_t longitude; /*< longitude, 10E-7deg*/
 int32_t altitude; /*< altitude, 10E-3deg*/
 int16_t vel_X_O; /*< velocity northward, 10E-2m/s*/
 int16_t vel_Y_O; /*< velocity eastward, 10E-2m/s*/
 int16_t vel_Z_O; /*< velocity downward, 10E-2m/s*/
 int16_t pitch; /*< pitch, 10E-3 rad*/
 int16_t roll; /*< roll, 10E-3 rad*/
 int16_t yaw; /*< yaw, 10E-3 rad*/
 int16_t yaw_rate; /*< yaw_rate, 10E-3 rad/s*/
 int16_t ant_heading; /*< heading info of dual antennas, 0.1deg clockwise [0,360)deg*/
 int16_t reserve; /*< reserved*/
 uint8_t pos_type; /*< 位置类型*/
 uint8_t pos_stat; /*< 位置解状态*/
 uint8_t vel_type; /*< 速度类型*/
 uint8_t vel_stat; /*< 速度解状态*/
} alink_rtk_location_t;
#pragma pack()

#define ALINK_MSG_ID_RTK_LOCATION_LEN 34
#define ALINK_MSG_ID_169_LEN 34

#define ALINK_MSG_ID_RTK_LOCATION_CRC 146
#define ALINK_MSG_ID_169_CRC 146



#define ALINK_MESSAGE_INFO_RTK_LOCATION { \
	"RTK_LOCATION", \
	16, \
	{  { "latitude", NULL, ALINK_TYPE_INT32_T, 0, 0, offsetof(alink_rtk_location_t, latitude) }, \
         { "longitude", NULL, ALINK_TYPE_INT32_T, 0, 4, offsetof(alink_rtk_location_t, longitude) }, \
         { "altitude", NULL, ALINK_TYPE_INT32_T, 0, 8, offsetof(alink_rtk_location_t, altitude) }, \
         { "vel_X_O", NULL, ALINK_TYPE_INT16_T, 0, 12, offsetof(alink_rtk_location_t, vel_X_O) }, \
         { "vel_Y_O", NULL, ALINK_TYPE_INT16_T, 0, 14, offsetof(alink_rtk_location_t, vel_Y_O) }, \
         { "vel_Z_O", NULL, ALINK_TYPE_INT16_T, 0, 16, offsetof(alink_rtk_location_t, vel_Z_O) }, \
         { "pitch", NULL, ALINK_TYPE_INT16_T, 0, 18, offsetof(alink_rtk_location_t, pitch) }, \
         { "roll", NULL, ALINK_TYPE_INT16_T, 0, 20, offsetof(alink_rtk_location_t, roll) }, \
         { "yaw", NULL, ALINK_TYPE_INT16_T, 0, 22, offsetof(alink_rtk_location_t, yaw) }, \
         { "yaw_rate", NULL, ALINK_TYPE_INT16_T, 0, 24, offsetof(alink_rtk_location_t, yaw_rate) }, \
         { "ant_heading", NULL, ALINK_TYPE_INT16_T, 0, 26, offsetof(alink_rtk_location_t, ant_heading) }, \
         { "reserve", NULL, ALINK_TYPE_INT16_T, 0, 28, offsetof(alink_rtk_location_t, reserve) }, \
         { "pos_type", NULL, ALINK_TYPE_UINT8_T, 0, 30, offsetof(alink_rtk_location_t, pos_type) }, \
         { "pos_stat", NULL, ALINK_TYPE_UINT8_T, 0, 31, offsetof(alink_rtk_location_t, pos_stat) }, \
         { "vel_type", NULL, ALINK_TYPE_UINT8_T, 0, 32, offsetof(alink_rtk_location_t, vel_type) }, \
         { "vel_stat", NULL, ALINK_TYPE_UINT8_T, 0, 33, offsetof(alink_rtk_location_t, vel_stat) }, \
         } \
}


/**
 * @brief Pack a rtk_location message
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 *
 * @param latitude latitude, 10E-7deg
 * @param longitude longitude, 10E-7deg
 * @param altitude altitude, 10E-3deg
 * @param vel_X_O velocity northward, 10E-2m/s
 * @param vel_Y_O velocity eastward, 10E-2m/s
 * @param vel_Z_O velocity downward, 10E-2m/s
 * @param pitch pitch, 10E-3 rad
 * @param roll roll, 10E-3 rad
 * @param yaw yaw, 10E-3 rad
 * @param yaw_rate yaw_rate, 10E-3 rad/s
 * @param ant_heading heading info of dual antennas, 0.1deg clockwise [0,360)deg
 * @param reserve reserved
 * @param pos_type 位置类型
 * @param pos_stat 位置解状态
 * @param vel_type 速度类型
 * @param vel_stat 速度解状态
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_rtk_location_pack(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg,
						       int32_t latitude, int32_t longitude, int32_t altitude, int16_t vel_X_O, int16_t vel_Y_O, int16_t vel_Z_O, int16_t pitch, int16_t roll, int16_t yaw, int16_t yaw_rate, int16_t ant_heading, int16_t reserve, uint8_t pos_type, uint8_t pos_stat, uint8_t vel_type, uint8_t vel_stat)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_RTK_LOCATION_LEN];
	_mav_put_int32_t(buf, 0, latitude);
	_mav_put_int32_t(buf, 4, longitude);
	_mav_put_int32_t(buf, 8, altitude);
	_mav_put_int16_t(buf, 12, vel_X_O);
	_mav_put_int16_t(buf, 14, vel_Y_O);
	_mav_put_int16_t(buf, 16, vel_Z_O);
	_mav_put_int16_t(buf, 18, pitch);
	_mav_put_int16_t(buf, 20, roll);
	_mav_put_int16_t(buf, 22, yaw);
	_mav_put_int16_t(buf, 24, yaw_rate);
	_mav_put_int16_t(buf, 26, ant_heading);
	_mav_put_int16_t(buf, 28, reserve);
	_mav_put_uint8_t(buf, 30, pos_type);
	_mav_put_uint8_t(buf, 31, pos_stat);
	_mav_put_uint8_t(buf, 32, vel_type);
	_mav_put_uint8_t(buf, 33, vel_stat);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_RTK_LOCATION_LEN);
#else
	alink_rtk_location_t packet;
	packet.latitude = latitude;
	packet.longitude = longitude;
	packet.altitude = altitude;
	packet.vel_X_O = vel_X_O;
	packet.vel_Y_O = vel_Y_O;
	packet.vel_Z_O = vel_Z_O;
	packet.pitch = pitch;
	packet.roll = roll;
	packet.yaw = yaw;
	packet.yaw_rate = yaw_rate;
	packet.ant_heading = ant_heading;
	packet.reserve = reserve;
	packet.pos_type = pos_type;
	packet.pos_stat = pos_stat;
	packet.vel_type = vel_type;
	packet.vel_stat = vel_stat;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_RTK_LOCATION_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_RTK_LOCATION;
#if ALINK_CRC_EXTRA
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_RTK_LOCATION_LEN,ALINK_MSG_ID_RTK_LOCATION_CRC);
#else
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_RTK_LOCATION_LEN);
#endif
}

/**
 * @brief Pack a rtk_location message on a channel
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param latitude latitude, 10E-7deg
 * @param longitude longitude, 10E-7deg
 * @param altitude altitude, 10E-3deg
 * @param vel_X_O velocity northward, 10E-2m/s
 * @param vel_Y_O velocity eastward, 10E-2m/s
 * @param vel_Z_O velocity downward, 10E-2m/s
 * @param pitch pitch, 10E-3 rad
 * @param roll roll, 10E-3 rad
 * @param yaw yaw, 10E-3 rad
 * @param yaw_rate yaw_rate, 10E-3 rad/s
 * @param ant_heading heading info of dual antennas, 0.1deg clockwise [0,360)deg
 * @param reserve reserved
 * @param pos_type 位置类型
 * @param pos_stat 位置解状态
 * @param vel_type 速度类型
 * @param vel_stat 速度解状态
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_rtk_location_pack_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan,
							   alink_message_head_t* msg,
						           int32_t latitude,int32_t longitude,int32_t altitude,int16_t vel_X_O,int16_t vel_Y_O,int16_t vel_Z_O,int16_t pitch,int16_t roll,int16_t yaw,int16_t yaw_rate,int16_t ant_heading,int16_t reserve,uint8_t pos_type,uint8_t pos_stat,uint8_t vel_type,uint8_t vel_stat)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_RTK_LOCATION_LEN];
	_mav_put_int32_t(buf, 0, latitude);
	_mav_put_int32_t(buf, 4, longitude);
	_mav_put_int32_t(buf, 8, altitude);
	_mav_put_int16_t(buf, 12, vel_X_O);
	_mav_put_int16_t(buf, 14, vel_Y_O);
	_mav_put_int16_t(buf, 16, vel_Z_O);
	_mav_put_int16_t(buf, 18, pitch);
	_mav_put_int16_t(buf, 20, roll);
	_mav_put_int16_t(buf, 22, yaw);
	_mav_put_int16_t(buf, 24, yaw_rate);
	_mav_put_int16_t(buf, 26, ant_heading);
	_mav_put_int16_t(buf, 28, reserve);
	_mav_put_uint8_t(buf, 30, pos_type);
	_mav_put_uint8_t(buf, 31, pos_stat);
	_mav_put_uint8_t(buf, 32, vel_type);
	_mav_put_uint8_t(buf, 33, vel_stat);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_RTK_LOCATION_LEN);
#else
	alink_rtk_location_t packet;
	packet.latitude = latitude;
	packet.longitude = longitude;
	packet.altitude = altitude;
	packet.vel_X_O = vel_X_O;
	packet.vel_Y_O = vel_Y_O;
	packet.vel_Z_O = vel_Z_O;
	packet.pitch = pitch;
	packet.roll = roll;
	packet.yaw = yaw;
	packet.yaw_rate = yaw_rate;
	packet.ant_heading = ant_heading;
	packet.reserve = reserve;
	packet.pos_type = pos_type;
	packet.pos_stat = pos_stat;
	packet.vel_type = vel_type;
	packet.vel_stat = vel_stat;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_RTK_LOCATION_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_RTK_LOCATION;
#if ALINK_CRC_EXTRA
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_RTK_LOCATION_LEN,ALINK_MSG_ID_RTK_LOCATION_CRC);
#else
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_RTK_LOCATION_LEN);
#endif
}
/**
 * @brief Encode a rtk_location struct
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 * @param rtk_location C-struct to read the message contents from
 */
static inline uint16_t alink_msg_rtk_location_encode(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg, const alink_rtk_location_t* rtk_location)
{
	return alink_msg_rtk_location_pack(dest_id, source_id, msg, rtk_location->latitude, rtk_location->longitude, rtk_location->altitude, rtk_location->vel_X_O, rtk_location->vel_Y_O, rtk_location->vel_Z_O, rtk_location->pitch, rtk_location->roll, rtk_location->yaw, rtk_location->yaw_rate, rtk_location->ant_heading, rtk_location->reserve, rtk_location->pos_type, rtk_location->pos_stat, rtk_location->vel_type, rtk_location->vel_stat);
}

/**
 * @brief Encode a rtk_location struct on a channel
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param rtk_location C-struct to read the message contents from
 */
static inline uint16_t alink_msg_rtk_location_encode_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan, alink_message_head_t* msg, const alink_rtk_location_t* rtk_location)
{
	return alink_msg_rtk_location_pack_chan(dest_id, source_id, chan, msg, rtk_location->latitude, rtk_location->longitude, rtk_location->altitude, rtk_location->vel_X_O, rtk_location->vel_Y_O, rtk_location->vel_Z_O, rtk_location->pitch, rtk_location->roll, rtk_location->yaw, rtk_location->yaw_rate, rtk_location->ant_heading, rtk_location->reserve, rtk_location->pos_type, rtk_location->pos_stat, rtk_location->vel_type, rtk_location->vel_stat);
}
// MESSAGE RTK_LOCATION UNPACKING


/**
 * @brief Get field latitude from rtk_location message
 *
 * @return latitude, 10E-7deg
 */
static inline int32_t alink_msg_rtk_location_get_latitude(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  0);
}

/**
 * @brief Get field longitude from rtk_location message
 *
 * @return longitude, 10E-7deg
 */
static inline int32_t alink_msg_rtk_location_get_longitude(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  4);
}

/**
 * @brief Get field altitude from rtk_location message
 *
 * @return altitude, 10E-3deg
 */
static inline int32_t alink_msg_rtk_location_get_altitude(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  8);
}

/**
 * @brief Get field vel_X_O from rtk_location message
 *
 * @return velocity northward, 10E-2m/s
 */
static inline int16_t alink_msg_rtk_location_get_vel_X_O(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  12);
}

/**
 * @brief Get field vel_Y_O from rtk_location message
 *
 * @return velocity eastward, 10E-2m/s
 */
static inline int16_t alink_msg_rtk_location_get_vel_Y_O(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  14);
}

/**
 * @brief Get field vel_Z_O from rtk_location message
 *
 * @return velocity downward, 10E-2m/s
 */
static inline int16_t alink_msg_rtk_location_get_vel_Z_O(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  16);
}

/**
 * @brief Get field pitch from rtk_location message
 *
 * @return pitch, 10E-3 rad
 */
static inline int16_t alink_msg_rtk_location_get_pitch(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  18);
}

/**
 * @brief Get field roll from rtk_location message
 *
 * @return roll, 10E-3 rad
 */
static inline int16_t alink_msg_rtk_location_get_roll(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  20);
}

/**
 * @brief Get field yaw from rtk_location message
 *
 * @return yaw, 10E-3 rad
 */
static inline int16_t alink_msg_rtk_location_get_yaw(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  22);
}

/**
 * @brief Get field yaw_rate from rtk_location message
 *
 * @return yaw_rate, 10E-3 rad/s
 */
static inline int16_t alink_msg_rtk_location_get_yaw_rate(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  24);
}

/**
 * @brief Get field ant_heading from rtk_location message
 *
 * @return heading info of dual antennas, 0.1deg clockwise [0,360)deg
 */
static inline int16_t alink_msg_rtk_location_get_ant_heading(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  26);
}

/**
 * @brief Get field reserve from rtk_location message
 *
 * @return reserved
 */
static inline int16_t alink_msg_rtk_location_get_reserve(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  28);
}

/**
 * @brief Get field pos_type from rtk_location message
 *
 * @return 位置类型
 */
static inline uint8_t alink_msg_rtk_location_get_pos_type(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  30);
}

/**
 * @brief Get field pos_stat from rtk_location message
 *
 * @return 位置解状态
 */
static inline uint8_t alink_msg_rtk_location_get_pos_stat(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  31);
}

/**
 * @brief Get field vel_type from rtk_location message
 *
 * @return 速度类型
 */
static inline uint8_t alink_msg_rtk_location_get_vel_type(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  32);
}

/**
 * @brief Get field vel_stat from rtk_location message
 *
 * @return 速度解状态
 */
static inline uint8_t alink_msg_rtk_location_get_vel_stat(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  33);
}

/**
 * @brief Decode a rtk_location message into a struct
 *
 * @param msg The message to decode
 * @param rtk_location C-struct to decode the message contents into
 */
static inline void alink_msg_rtk_location_decode(const alink_message_head_t* msg, alink_rtk_location_t* rtk_location)
{
#if ALINK_NEED_BYTE_SWAP
	rtk_location->latitude = alink_msg_rtk_location_get_latitude(msg);
	rtk_location->longitude = alink_msg_rtk_location_get_longitude(msg);
	rtk_location->altitude = alink_msg_rtk_location_get_altitude(msg);
	rtk_location->vel_X_O = alink_msg_rtk_location_get_vel_X_O(msg);
	rtk_location->vel_Y_O = alink_msg_rtk_location_get_vel_Y_O(msg);
	rtk_location->vel_Z_O = alink_msg_rtk_location_get_vel_Z_O(msg);
	rtk_location->pitch = alink_msg_rtk_location_get_pitch(msg);
	rtk_location->roll = alink_msg_rtk_location_get_roll(msg);
	rtk_location->yaw = alink_msg_rtk_location_get_yaw(msg);
	rtk_location->yaw_rate = alink_msg_rtk_location_get_yaw_rate(msg);
	rtk_location->ant_heading = alink_msg_rtk_location_get_ant_heading(msg);
	rtk_location->reserve = alink_msg_rtk_location_get_reserve(msg);
	rtk_location->pos_type = alink_msg_rtk_location_get_pos_type(msg);
	rtk_location->pos_stat = alink_msg_rtk_location_get_pos_stat(msg);
	rtk_location->vel_type = alink_msg_rtk_location_get_vel_type(msg);
	rtk_location->vel_stat = alink_msg_rtk_location_get_vel_stat(msg);
#else
	memcpy(rtk_location, _MAV_PAYLOAD(msg), ALINK_MSG_ID_RTK_LOCATION_LEN);
#endif
}
