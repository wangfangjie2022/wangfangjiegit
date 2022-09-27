// MESSAGE VISION_GPS_INFO PACKING

#define ALINK_MSG_ID_VISION_GPS_INFO 76

typedef struct __alink_vision_gps_info_t
{
 uint32_t timestamp; /*< timestamp (milliseconds since system boot)*/
 uint32_t gps_time; /*< GPS time of week in seconds*/
 int32_t gps_lat; /*< GPS lattitude in 10E-7 degrees*/
 int32_t gps_lon; /*< GPS longitude in 10E-7 degrees*/
 int32_t gps_alt; /*< GPS height above mean sea level in 10E-3 meter*/
 int32_t vel_ned[3]; /*< Velocity of N/E/D in 10E-3 m/s*/
 uint32_t accuracy_h; /*< accuracy of horizontal in 10E-3 meter*/
 uint32_t accuracy_v; /*< accuracy of vertical in 10E-3 meter*/
 uint32_t accuracy_s; /*< accuracy of speed in 10E-3 m/s*/
 uint8_t GNSS_fix_type; /*< GNSS fix type 0: no fix 1: dead reckoning only 2: 2D fix 3: 3D fix 4: GNSS + Dead Reckoning 5: Time only Fix*/
 uint8_t satellites_num; /*< number of satellites used*/
} alink_vision_gps_info_t;

#define ALINK_MSG_ID_VISION_GPS_INFO_LEN 46
#define ALINK_MSG_ID_76_LEN 46

#define ALINK_MSG_ID_VISION_GPS_INFO_CRC 182
#define ALINK_MSG_ID_76_CRC 182

#define ALINK_MSG_VISION_GPS_INFO_FIELD_VEL_NED_LEN 3

#define ALINK_MESSAGE_INFO_VISION_GPS_INFO { \
	"VISION_GPS_INFO", \
	11, \
	{  { "timestamp", NULL, ALINK_TYPE_UINT32_T, 0, 0, offsetof(alink_vision_gps_info_t, timestamp) }, \
         { "gps_time", NULL, ALINK_TYPE_UINT32_T, 0, 4, offsetof(alink_vision_gps_info_t, gps_time) }, \
         { "gps_lat", NULL, ALINK_TYPE_INT32_T, 0, 8, offsetof(alink_vision_gps_info_t, gps_lat) }, \
         { "gps_lon", NULL, ALINK_TYPE_INT32_T, 0, 12, offsetof(alink_vision_gps_info_t, gps_lon) }, \
         { "gps_alt", NULL, ALINK_TYPE_INT32_T, 0, 16, offsetof(alink_vision_gps_info_t, gps_alt) }, \
         { "vel_ned", NULL, ALINK_TYPE_INT32_T, 3, 20, offsetof(alink_vision_gps_info_t, vel_ned) }, \
         { "accuracy_h", NULL, ALINK_TYPE_UINT32_T, 0, 32, offsetof(alink_vision_gps_info_t, accuracy_h) }, \
         { "accuracy_v", NULL, ALINK_TYPE_UINT32_T, 0, 36, offsetof(alink_vision_gps_info_t, accuracy_v) }, \
         { "accuracy_s", NULL, ALINK_TYPE_UINT32_T, 0, 40, offsetof(alink_vision_gps_info_t, accuracy_s) }, \
         { "GNSS_fix_type", NULL, ALINK_TYPE_UINT8_T, 0, 44, offsetof(alink_vision_gps_info_t, GNSS_fix_type) }, \
         { "satellites_num", NULL, ALINK_TYPE_UINT8_T, 0, 45, offsetof(alink_vision_gps_info_t, satellites_num) }, \
         } \
}


/**
 * @brief Pack a vision_gps_info message
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 *
 * @param timestamp timestamp (milliseconds since system boot)
 * @param gps_time GPS time of week in seconds
 * @param gps_lat GPS lattitude in 10E-7 degrees
 * @param gps_lon GPS longitude in 10E-7 degrees
 * @param gps_alt GPS height above mean sea level in 10E-3 meter
 * @param vel_ned Velocity of N/E/D in 10E-3 m/s
 * @param accuracy_h accuracy of horizontal in 10E-3 meter
 * @param accuracy_v accuracy of vertical in 10E-3 meter
 * @param accuracy_s accuracy of speed in 10E-3 m/s
 * @param GNSS_fix_type GNSS fix type 0: no fix 1: dead reckoning only 2: 2D fix 3: 3D fix 4: GNSS + Dead Reckoning 5: Time only Fix
 * @param satellites_num number of satellites used
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_vision_gps_info_pack(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg,
						       uint32_t timestamp, uint32_t gps_time, int32_t gps_lat, int32_t gps_lon, int32_t gps_alt, const int32_t *vel_ned, uint32_t accuracy_h, uint32_t accuracy_v, uint32_t accuracy_s, uint8_t GNSS_fix_type, uint8_t satellites_num)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_VISION_GPS_INFO_LEN];
	_mav_put_uint32_t(buf, 0, timestamp);
	_mav_put_uint32_t(buf, 4, gps_time);
	_mav_put_int32_t(buf, 8, gps_lat);
	_mav_put_int32_t(buf, 12, gps_lon);
	_mav_put_int32_t(buf, 16, gps_alt);
	_mav_put_uint32_t(buf, 32, accuracy_h);
	_mav_put_uint32_t(buf, 36, accuracy_v);
	_mav_put_uint32_t(buf, 40, accuracy_s);
	_mav_put_uint8_t(buf, 44, GNSS_fix_type);
	_mav_put_uint8_t(buf, 45, satellites_num);
	_mav_put_int32_t_array(buf, 20, vel_ned, 3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_VISION_GPS_INFO_LEN);
#else
	alink_vision_gps_info_t packet;
	packet.timestamp = timestamp;
	packet.gps_time = gps_time;
	packet.gps_lat = gps_lat;
	packet.gps_lon = gps_lon;
	packet.gps_alt = gps_alt;
	packet.accuracy_h = accuracy_h;
	packet.accuracy_v = accuracy_v;
	packet.accuracy_s = accuracy_s;
	packet.GNSS_fix_type = GNSS_fix_type;
	packet.satellites_num = satellites_num;
	mav_array_memcpy(packet.vel_ned, vel_ned, sizeof(int32_t)*3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_VISION_GPS_INFO_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_VISION_GPS_INFO;
#if ALINK_CRC_EXTRA
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_VISION_GPS_INFO_LEN,ALINK_MSG_ID_VISION_GPS_INFO_CRC);
#else
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_VISION_GPS_INFO_LEN);
#endif
}

/**
 * @brief Pack a vision_gps_info message on a channel
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param timestamp timestamp (milliseconds since system boot)
 * @param gps_time GPS time of week in seconds
 * @param gps_lat GPS lattitude in 10E-7 degrees
 * @param gps_lon GPS longitude in 10E-7 degrees
 * @param gps_alt GPS height above mean sea level in 10E-3 meter
 * @param vel_ned Velocity of N/E/D in 10E-3 m/s
 * @param accuracy_h accuracy of horizontal in 10E-3 meter
 * @param accuracy_v accuracy of vertical in 10E-3 meter
 * @param accuracy_s accuracy of speed in 10E-3 m/s
 * @param GNSS_fix_type GNSS fix type 0: no fix 1: dead reckoning only 2: 2D fix 3: 3D fix 4: GNSS + Dead Reckoning 5: Time only Fix
 * @param satellites_num number of satellites used
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_vision_gps_info_pack_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan,
							   alink_message_head_t* msg,
						           uint32_t timestamp,uint32_t gps_time,int32_t gps_lat,int32_t gps_lon,int32_t gps_alt,const int32_t *vel_ned,uint32_t accuracy_h,uint32_t accuracy_v,uint32_t accuracy_s,uint8_t GNSS_fix_type,uint8_t satellites_num)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_VISION_GPS_INFO_LEN];
	_mav_put_uint32_t(buf, 0, timestamp);
	_mav_put_uint32_t(buf, 4, gps_time);
	_mav_put_int32_t(buf, 8, gps_lat);
	_mav_put_int32_t(buf, 12, gps_lon);
	_mav_put_int32_t(buf, 16, gps_alt);
	_mav_put_uint32_t(buf, 32, accuracy_h);
	_mav_put_uint32_t(buf, 36, accuracy_v);
	_mav_put_uint32_t(buf, 40, accuracy_s);
	_mav_put_uint8_t(buf, 44, GNSS_fix_type);
	_mav_put_uint8_t(buf, 45, satellites_num);
	_mav_put_int32_t_array(buf, 20, vel_ned, 3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_VISION_GPS_INFO_LEN);
#else
	alink_vision_gps_info_t packet;
	packet.timestamp = timestamp;
	packet.gps_time = gps_time;
	packet.gps_lat = gps_lat;
	packet.gps_lon = gps_lon;
	packet.gps_alt = gps_alt;
	packet.accuracy_h = accuracy_h;
	packet.accuracy_v = accuracy_v;
	packet.accuracy_s = accuracy_s;
	packet.GNSS_fix_type = GNSS_fix_type;
	packet.satellites_num = satellites_num;
	mav_array_memcpy(packet.vel_ned, vel_ned, sizeof(int32_t)*3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_VISION_GPS_INFO_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_VISION_GPS_INFO;
#if ALINK_CRC_EXTRA
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_VISION_GPS_INFO_LEN,ALINK_MSG_ID_VISION_GPS_INFO_CRC);
#else
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_VISION_GPS_INFO_LEN);
#endif
}
/**
 * @brief Encode a vision_gps_info struct
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 * @param vision_gps_info C-struct to read the message contents from
 */
static inline uint16_t alink_msg_vision_gps_info_encode(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg, const alink_vision_gps_info_t* vision_gps_info)
{
	return alink_msg_vision_gps_info_pack(dest_id, source_id, msg, vision_gps_info->timestamp, vision_gps_info->gps_time, vision_gps_info->gps_lat, vision_gps_info->gps_lon, vision_gps_info->gps_alt, vision_gps_info->vel_ned, vision_gps_info->accuracy_h, vision_gps_info->accuracy_v, vision_gps_info->accuracy_s, vision_gps_info->GNSS_fix_type, vision_gps_info->satellites_num);
}

/**
 * @brief Encode a vision_gps_info struct on a channel
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param vision_gps_info C-struct to read the message contents from
 */
static inline uint16_t alink_msg_vision_gps_info_encode_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan, alink_message_head_t* msg, const alink_vision_gps_info_t* vision_gps_info)
{
	return alink_msg_vision_gps_info_pack_chan(dest_id, source_id, chan, msg, vision_gps_info->timestamp, vision_gps_info->gps_time, vision_gps_info->gps_lat, vision_gps_info->gps_lon, vision_gps_info->gps_alt, vision_gps_info->vel_ned, vision_gps_info->accuracy_h, vision_gps_info->accuracy_v, vision_gps_info->accuracy_s, vision_gps_info->GNSS_fix_type, vision_gps_info->satellites_num);
}
// MESSAGE VISION_GPS_INFO UNPACKING


/**
 * @brief Get field timestamp from vision_gps_info message
 *
 * @return timestamp (milliseconds since system boot)
 */
static inline uint32_t alink_msg_vision_gps_info_get_timestamp(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field gps_time from vision_gps_info message
 *
 * @return GPS time of week in seconds
 */
static inline uint32_t alink_msg_vision_gps_info_get_gps_time(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint32_t(msg,  4);
}

/**
 * @brief Get field gps_lat from vision_gps_info message
 *
 * @return GPS lattitude in 10E-7 degrees
 */
static inline int32_t alink_msg_vision_gps_info_get_gps_lat(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  8);
}

/**
 * @brief Get field gps_lon from vision_gps_info message
 *
 * @return GPS longitude in 10E-7 degrees
 */
static inline int32_t alink_msg_vision_gps_info_get_gps_lon(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  12);
}

/**
 * @brief Get field gps_alt from vision_gps_info message
 *
 * @return GPS height above mean sea level in 10E-3 meter
 */
static inline int32_t alink_msg_vision_gps_info_get_gps_alt(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  16);
}

/**
 * @brief Get field vel_ned from vision_gps_info message
 *
 * @return Velocity of N/E/D in 10E-3 m/s
 */
static inline uint16_t alink_msg_vision_gps_info_get_vel_ned(const alink_message_head_t* msg, int32_t *vel_ned)
{
	return _MAV_RETURN_int32_t_array(msg, vel_ned, 3,  20);
}

/**
 * @brief Get field accuracy_h from vision_gps_info message
 *
 * @return accuracy of horizontal in 10E-3 meter
 */
static inline uint32_t alink_msg_vision_gps_info_get_accuracy_h(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint32_t(msg,  32);
}

/**
 * @brief Get field accuracy_v from vision_gps_info message
 *
 * @return accuracy of vertical in 10E-3 meter
 */
static inline uint32_t alink_msg_vision_gps_info_get_accuracy_v(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint32_t(msg,  36);
}

/**
 * @brief Get field accuracy_s from vision_gps_info message
 *
 * @return accuracy of speed in 10E-3 m/s
 */
static inline uint32_t alink_msg_vision_gps_info_get_accuracy_s(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint32_t(msg,  40);
}

/**
 * @brief Get field GNSS_fix_type from vision_gps_info message
 *
 * @return GNSS fix type 0: no fix 1: dead reckoning only 2: 2D fix 3: 3D fix 4: GNSS + Dead Reckoning 5: Time only Fix
 */
static inline uint8_t alink_msg_vision_gps_info_get_GNSS_fix_type(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  44);
}

/**
 * @brief Get field satellites_num from vision_gps_info message
 *
 * @return number of satellites used
 */
static inline uint8_t alink_msg_vision_gps_info_get_satellites_num(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  45);
}

/**
 * @brief Decode a vision_gps_info message into a struct
 *
 * @param msg The message to decode
 * @param vision_gps_info C-struct to decode the message contents into
 */
static inline void alink_msg_vision_gps_info_decode(const alink_message_head_t* msg, alink_vision_gps_info_t* vision_gps_info)
{
#if ALINK_NEED_BYTE_SWAP
	vision_gps_info->timestamp = alink_msg_vision_gps_info_get_timestamp(msg);
	vision_gps_info->gps_time = alink_msg_vision_gps_info_get_gps_time(msg);
	vision_gps_info->gps_lat = alink_msg_vision_gps_info_get_gps_lat(msg);
	vision_gps_info->gps_lon = alink_msg_vision_gps_info_get_gps_lon(msg);
	vision_gps_info->gps_alt = alink_msg_vision_gps_info_get_gps_alt(msg);
	alink_msg_vision_gps_info_get_vel_ned(msg, vision_gps_info->vel_ned);
	vision_gps_info->accuracy_h = alink_msg_vision_gps_info_get_accuracy_h(msg);
	vision_gps_info->accuracy_v = alink_msg_vision_gps_info_get_accuracy_v(msg);
	vision_gps_info->accuracy_s = alink_msg_vision_gps_info_get_accuracy_s(msg);
	vision_gps_info->GNSS_fix_type = alink_msg_vision_gps_info_get_GNSS_fix_type(msg);
	vision_gps_info->satellites_num = alink_msg_vision_gps_info_get_satellites_num(msg);
#else
	memcpy(vision_gps_info, _MAV_PAYLOAD(msg), ALINK_MSG_ID_VISION_GPS_INFO_LEN);
#endif
}
