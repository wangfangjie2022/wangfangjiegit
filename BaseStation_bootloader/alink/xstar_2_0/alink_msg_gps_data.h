// MESSAGE GPS_DATA PACKING

#define ALINK_MSG_ID_GPS_DATA 145

typedef struct __alink_gps_data_t
{
 uint64_t time_gps_usec; /*< Timestamp (microseconds in UBOX format), this is the timestamp which comes from the UBOX module */
 int32_t lat; /*< Latitude in 1E-7 degrees*/
 int32_t lon; /*< Longitude in 1E-7 degrees*/
 int32_t alt; /*< Altitude in 1E-3 meters (millimeters) above MSL*/
 int32_t height; /*< Height above ellipsoid [mm]*/
 int32_t sAcc; /*< speed accuracy estimate m/s*/
 int32_t hAcc; /*< float UBOX HDOP horizontal dilution of position in m*/
 int32_t vAcc; /*< UBOX VDOP horizontal dilution of position in m*/
 uint32_t noise_per_ms; /*< undefined*/
 uint32_t jamming_indicator; /*< undefined*/
 int32_t vel_m_s; /*< UBOX ground speed (m/s) */
 int32_t vel_n_m_s; /*< UBOX ground speed in m/s*/
 int32_t vel_e_m_s; /*< UBOX ground speed in m/s*/
 int32_t vel_d_m_s; /*< UBOX ground speed in m/s*/
 uint32_t headAcc; /*< undefined*/
 int32_t headMot; /*< undefined*/
 int32_t reserved1; /*< reserved1*/
 int32_t reserved2; /*< reserved2*/
 int32_t reserved3; /*< reserved3*/
 int32_t reserved4; /*< reserved4*/
 uint8_t satellites_used; /*< Number of satellites used */
 uint8_t pDOP; /*< undefined*/
 uint8_t vel_ned_valid; /*< Flag to indicate if NED speed is valid */
 uint8_t fix_type; /*< 0-1: no fix, 2: 2D fix, 3: 3D fix. Some applications will not use the value of this field unless it is at least two, so always correctly fill in the fix.*/
 uint8_t satellites_num_over42db; /*< Number of satellites over42db used */
} alink_gps_data_t;

#define ALINK_MSG_ID_GPS_DATA_LEN 89
#define ALINK_MSG_ID_145_LEN 89

#define ALINK_MSG_ID_GPS_DATA_CRC 233
#define ALINK_MSG_ID_145_CRC 233



#define ALINK_MESSAGE_INFO_GPS_DATA { \
	"GPS_DATA", \
	25, \
	{  { "time_gps_usec", NULL, ALINK_TYPE_UINT64_T, 0, 0, offsetof(alink_gps_data_t, time_gps_usec) }, \
         { "lat", NULL, ALINK_TYPE_INT32_T, 0, 8, offsetof(alink_gps_data_t, lat) }, \
         { "lon", NULL, ALINK_TYPE_INT32_T, 0, 12, offsetof(alink_gps_data_t, lon) }, \
         { "alt", NULL, ALINK_TYPE_INT32_T, 0, 16, offsetof(alink_gps_data_t, alt) }, \
         { "height", NULL, ALINK_TYPE_INT32_T, 0, 20, offsetof(alink_gps_data_t, height) }, \
         { "sAcc", NULL, ALINK_TYPE_INT32_T, 0, 24, offsetof(alink_gps_data_t, sAcc) }, \
         { "hAcc", NULL, ALINK_TYPE_INT32_T, 0, 28, offsetof(alink_gps_data_t, hAcc) }, \
         { "vAcc", NULL, ALINK_TYPE_INT32_T, 0, 32, offsetof(alink_gps_data_t, vAcc) }, \
         { "noise_per_ms", NULL, ALINK_TYPE_UINT32_T, 0, 36, offsetof(alink_gps_data_t, noise_per_ms) }, \
         { "jamming_indicator", NULL, ALINK_TYPE_UINT32_T, 0, 40, offsetof(alink_gps_data_t, jamming_indicator) }, \
         { "vel_m_s", NULL, ALINK_TYPE_INT32_T, 0, 44, offsetof(alink_gps_data_t, vel_m_s) }, \
         { "vel_n_m_s", NULL, ALINK_TYPE_INT32_T, 0, 48, offsetof(alink_gps_data_t, vel_n_m_s) }, \
         { "vel_e_m_s", NULL, ALINK_TYPE_INT32_T, 0, 52, offsetof(alink_gps_data_t, vel_e_m_s) }, \
         { "vel_d_m_s", NULL, ALINK_TYPE_INT32_T, 0, 56, offsetof(alink_gps_data_t, vel_d_m_s) }, \
         { "headAcc", NULL, ALINK_TYPE_UINT32_T, 0, 60, offsetof(alink_gps_data_t, headAcc) }, \
         { "headMot", NULL, ALINK_TYPE_INT32_T, 0, 64, offsetof(alink_gps_data_t, headMot) }, \
         { "reserved1", NULL, ALINK_TYPE_INT32_T, 0, 68, offsetof(alink_gps_data_t, reserved1) }, \
         { "reserved2", NULL, ALINK_TYPE_INT32_T, 0, 72, offsetof(alink_gps_data_t, reserved2) }, \
         { "reserved3", NULL, ALINK_TYPE_INT32_T, 0, 76, offsetof(alink_gps_data_t, reserved3) }, \
         { "reserved4", NULL, ALINK_TYPE_INT32_T, 0, 80, offsetof(alink_gps_data_t, reserved4) }, \
         { "satellites_used", NULL, ALINK_TYPE_UINT8_T, 0, 84, offsetof(alink_gps_data_t, satellites_used) }, \
         { "pDOP", NULL, ALINK_TYPE_UINT8_T, 0, 85, offsetof(alink_gps_data_t, pDOP) }, \
         { "vel_ned_valid", NULL, ALINK_TYPE_UINT8_T, 0, 86, offsetof(alink_gps_data_t, vel_ned_valid) }, \
         { "fix_type", NULL, ALINK_TYPE_UINT8_T, 0, 87, offsetof(alink_gps_data_t, fix_type) }, \
         { "satellites_num_over42db", NULL, ALINK_TYPE_UINT8_T, 0, 88, offsetof(alink_gps_data_t, satellites_num_over42db) }, \
         } \
}


/**
 * @brief Pack a gps_data message
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 *
 * @param time_gps_usec Timestamp (microseconds in UBOX format), this is the timestamp which comes from the UBOX module 
 * @param lat Latitude in 1E-7 degrees
 * @param lon Longitude in 1E-7 degrees
 * @param alt Altitude in 1E-3 meters (millimeters) above MSL
 * @param height Height above ellipsoid [mm]
 * @param sAcc speed accuracy estimate m/s
 * @param hAcc float UBOX HDOP horizontal dilution of position in m
 * @param vAcc UBOX VDOP horizontal dilution of position in m
 * @param noise_per_ms undefined
 * @param jamming_indicator undefined
 * @param vel_m_s UBOX ground speed (m/s) 
 * @param vel_n_m_s UBOX ground speed in m/s
 * @param vel_e_m_s UBOX ground speed in m/s
 * @param vel_d_m_s UBOX ground speed in m/s
 * @param headAcc undefined
 * @param headMot undefined
 * @param satellites_used Number of satellites used 
 * @param pDOP undefined
 * @param vel_ned_valid Flag to indicate if NED speed is valid 
 * @param fix_type 0-1: no fix, 2: 2D fix, 3: 3D fix. Some applications will not use the value of this field unless it is at least two, so always correctly fill in the fix.
 * @param satellites_num_over42db Number of satellites over42db used 
 * @param reserved1 reserved1
 * @param reserved2 reserved2
 * @param reserved3 reserved3
 * @param reserved4 reserved4
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_gps_data_pack(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg,
						       uint64_t time_gps_usec, int32_t lat, int32_t lon, int32_t alt, int32_t height, int32_t sAcc, int32_t hAcc, int32_t vAcc, uint32_t noise_per_ms, uint32_t jamming_indicator, int32_t vel_m_s, int32_t vel_n_m_s, int32_t vel_e_m_s, int32_t vel_d_m_s, uint32_t headAcc, int32_t headMot, uint8_t satellites_used, uint8_t pDOP, uint8_t vel_ned_valid, uint8_t fix_type, uint8_t satellites_num_over42db, int32_t reserved1, int32_t reserved2, int32_t reserved3, int32_t reserved4)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_GPS_DATA_LEN];
	_mav_put_uint64_t(buf, 0, time_gps_usec);
	_mav_put_int32_t(buf, 8, lat);
	_mav_put_int32_t(buf, 12, lon);
	_mav_put_int32_t(buf, 16, alt);
	_mav_put_int32_t(buf, 20, height);
	_mav_put_int32_t(buf, 24, sAcc);
	_mav_put_int32_t(buf, 28, hAcc);
	_mav_put_int32_t(buf, 32, vAcc);
	_mav_put_uint32_t(buf, 36, noise_per_ms);
	_mav_put_uint32_t(buf, 40, jamming_indicator);
	_mav_put_int32_t(buf, 44, vel_m_s);
	_mav_put_int32_t(buf, 48, vel_n_m_s);
	_mav_put_int32_t(buf, 52, vel_e_m_s);
	_mav_put_int32_t(buf, 56, vel_d_m_s);
	_mav_put_uint32_t(buf, 60, headAcc);
	_mav_put_int32_t(buf, 64, headMot);
	_mav_put_int32_t(buf, 68, reserved1);
	_mav_put_int32_t(buf, 72, reserved2);
	_mav_put_int32_t(buf, 76, reserved3);
	_mav_put_int32_t(buf, 80, reserved4);
	_mav_put_uint8_t(buf, 84, satellites_used);
	_mav_put_uint8_t(buf, 85, pDOP);
	_mav_put_uint8_t(buf, 86, vel_ned_valid);
	_mav_put_uint8_t(buf, 87, fix_type);
	_mav_put_uint8_t(buf, 88, satellites_num_over42db);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_GPS_DATA_LEN);
#else
	alink_gps_data_t packet;
	packet.time_gps_usec = time_gps_usec;
	packet.lat = lat;
	packet.lon = lon;
	packet.alt = alt;
	packet.height = height;
	packet.sAcc = sAcc;
	packet.hAcc = hAcc;
	packet.vAcc = vAcc;
	packet.noise_per_ms = noise_per_ms;
	packet.jamming_indicator = jamming_indicator;
	packet.vel_m_s = vel_m_s;
	packet.vel_n_m_s = vel_n_m_s;
	packet.vel_e_m_s = vel_e_m_s;
	packet.vel_d_m_s = vel_d_m_s;
	packet.headAcc = headAcc;
	packet.headMot = headMot;
	packet.reserved1 = reserved1;
	packet.reserved2 = reserved2;
	packet.reserved3 = reserved3;
	packet.reserved4 = reserved4;
	packet.satellites_used = satellites_used;
	packet.pDOP = pDOP;
	packet.vel_ned_valid = vel_ned_valid;
	packet.fix_type = fix_type;
	packet.satellites_num_over42db = satellites_num_over42db;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_GPS_DATA_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_GPS_DATA;
#if ALINK_CRC_EXTRA
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_GPS_DATA_LEN,ALINK_MSG_ID_GPS_DATA_CRC);
#else
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_GPS_DATA_LEN);
#endif
}

/**
 * @brief Pack a gps_data message on a channel
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param time_gps_usec Timestamp (microseconds in UBOX format), this is the timestamp which comes from the UBOX module 
 * @param lat Latitude in 1E-7 degrees
 * @param lon Longitude in 1E-7 degrees
 * @param alt Altitude in 1E-3 meters (millimeters) above MSL
 * @param height Height above ellipsoid [mm]
 * @param sAcc speed accuracy estimate m/s
 * @param hAcc float UBOX HDOP horizontal dilution of position in m
 * @param vAcc UBOX VDOP horizontal dilution of position in m
 * @param noise_per_ms undefined
 * @param jamming_indicator undefined
 * @param vel_m_s UBOX ground speed (m/s) 
 * @param vel_n_m_s UBOX ground speed in m/s
 * @param vel_e_m_s UBOX ground speed in m/s
 * @param vel_d_m_s UBOX ground speed in m/s
 * @param headAcc undefined
 * @param headMot undefined
 * @param satellites_used Number of satellites used 
 * @param pDOP undefined
 * @param vel_ned_valid Flag to indicate if NED speed is valid 
 * @param fix_type 0-1: no fix, 2: 2D fix, 3: 3D fix. Some applications will not use the value of this field unless it is at least two, so always correctly fill in the fix.
 * @param satellites_num_over42db Number of satellites over42db used 
 * @param reserved1 reserved1
 * @param reserved2 reserved2
 * @param reserved3 reserved3
 * @param reserved4 reserved4
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_gps_data_pack_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan,
							   alink_message_head_t* msg,
						           uint64_t time_gps_usec,int32_t lat,int32_t lon,int32_t alt,int32_t height,int32_t sAcc,int32_t hAcc,int32_t vAcc,uint32_t noise_per_ms,uint32_t jamming_indicator,int32_t vel_m_s,int32_t vel_n_m_s,int32_t vel_e_m_s,int32_t vel_d_m_s,uint32_t headAcc,int32_t headMot,uint8_t satellites_used,uint8_t pDOP,uint8_t vel_ned_valid,uint8_t fix_type,uint8_t satellites_num_over42db,int32_t reserved1,int32_t reserved2,int32_t reserved3,int32_t reserved4)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_GPS_DATA_LEN];
	_mav_put_uint64_t(buf, 0, time_gps_usec);
	_mav_put_int32_t(buf, 8, lat);
	_mav_put_int32_t(buf, 12, lon);
	_mav_put_int32_t(buf, 16, alt);
	_mav_put_int32_t(buf, 20, height);
	_mav_put_int32_t(buf, 24, sAcc);
	_mav_put_int32_t(buf, 28, hAcc);
	_mav_put_int32_t(buf, 32, vAcc);
	_mav_put_uint32_t(buf, 36, noise_per_ms);
	_mav_put_uint32_t(buf, 40, jamming_indicator);
	_mav_put_int32_t(buf, 44, vel_m_s);
	_mav_put_int32_t(buf, 48, vel_n_m_s);
	_mav_put_int32_t(buf, 52, vel_e_m_s);
	_mav_put_int32_t(buf, 56, vel_d_m_s);
	_mav_put_uint32_t(buf, 60, headAcc);
	_mav_put_int32_t(buf, 64, headMot);
	_mav_put_int32_t(buf, 68, reserved1);
	_mav_put_int32_t(buf, 72, reserved2);
	_mav_put_int32_t(buf, 76, reserved3);
	_mav_put_int32_t(buf, 80, reserved4);
	_mav_put_uint8_t(buf, 84, satellites_used);
	_mav_put_uint8_t(buf, 85, pDOP);
	_mav_put_uint8_t(buf, 86, vel_ned_valid);
	_mav_put_uint8_t(buf, 87, fix_type);
	_mav_put_uint8_t(buf, 88, satellites_num_over42db);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_GPS_DATA_LEN);
#else
	alink_gps_data_t packet;
	packet.time_gps_usec = time_gps_usec;
	packet.lat = lat;
	packet.lon = lon;
	packet.alt = alt;
	packet.height = height;
	packet.sAcc = sAcc;
	packet.hAcc = hAcc;
	packet.vAcc = vAcc;
	packet.noise_per_ms = noise_per_ms;
	packet.jamming_indicator = jamming_indicator;
	packet.vel_m_s = vel_m_s;
	packet.vel_n_m_s = vel_n_m_s;
	packet.vel_e_m_s = vel_e_m_s;
	packet.vel_d_m_s = vel_d_m_s;
	packet.headAcc = headAcc;
	packet.headMot = headMot;
	packet.reserved1 = reserved1;
	packet.reserved2 = reserved2;
	packet.reserved3 = reserved3;
	packet.reserved4 = reserved4;
	packet.satellites_used = satellites_used;
	packet.pDOP = pDOP;
	packet.vel_ned_valid = vel_ned_valid;
	packet.fix_type = fix_type;
	packet.satellites_num_over42db = satellites_num_over42db;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_GPS_DATA_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_GPS_DATA;
#if ALINK_CRC_EXTRA
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_GPS_DATA_LEN,ALINK_MSG_ID_GPS_DATA_CRC);
#else
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_GPS_DATA_LEN);
#endif
}
/**
 * @brief Encode a gps_data struct
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 * @param gps_data C-struct to read the message contents from
 */
static inline uint16_t alink_msg_gps_data_encode(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg, const alink_gps_data_t* gps_data)
{
	return alink_msg_gps_data_pack(dest_id, source_id, msg, gps_data->time_gps_usec, gps_data->lat, gps_data->lon, gps_data->alt, gps_data->height, gps_data->sAcc, gps_data->hAcc, gps_data->vAcc, gps_data->noise_per_ms, gps_data->jamming_indicator, gps_data->vel_m_s, gps_data->vel_n_m_s, gps_data->vel_e_m_s, gps_data->vel_d_m_s, gps_data->headAcc, gps_data->headMot, gps_data->satellites_used, gps_data->pDOP, gps_data->vel_ned_valid, gps_data->fix_type, gps_data->satellites_num_over42db, gps_data->reserved1, gps_data->reserved2, gps_data->reserved3, gps_data->reserved4);
}

/**
 * @brief Encode a gps_data struct on a channel
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param gps_data C-struct to read the message contents from
 */
static inline uint16_t alink_msg_gps_data_encode_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan, alink_message_head_t* msg, const alink_gps_data_t* gps_data)
{
	return alink_msg_gps_data_pack_chan(dest_id, source_id, chan, msg, gps_data->time_gps_usec, gps_data->lat, gps_data->lon, gps_data->alt, gps_data->height, gps_data->sAcc, gps_data->hAcc, gps_data->vAcc, gps_data->noise_per_ms, gps_data->jamming_indicator, gps_data->vel_m_s, gps_data->vel_n_m_s, gps_data->vel_e_m_s, gps_data->vel_d_m_s, gps_data->headAcc, gps_data->headMot, gps_data->satellites_used, gps_data->pDOP, gps_data->vel_ned_valid, gps_data->fix_type, gps_data->satellites_num_over42db, gps_data->reserved1, gps_data->reserved2, gps_data->reserved3, gps_data->reserved4);
}
// MESSAGE GPS_DATA UNPACKING


/**
 * @brief Get field time_gps_usec from gps_data message
 *
 * @return Timestamp (microseconds in UBOX format), this is the timestamp which comes from the UBOX module 
 */
static inline uint64_t alink_msg_gps_data_get_time_gps_usec(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field lat from gps_data message
 *
 * @return Latitude in 1E-7 degrees
 */
static inline int32_t alink_msg_gps_data_get_lat(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  8);
}

/**
 * @brief Get field lon from gps_data message
 *
 * @return Longitude in 1E-7 degrees
 */
static inline int32_t alink_msg_gps_data_get_lon(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  12);
}

/**
 * @brief Get field alt from gps_data message
 *
 * @return Altitude in 1E-3 meters (millimeters) above MSL
 */
static inline int32_t alink_msg_gps_data_get_alt(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  16);
}

/**
 * @brief Get field height from gps_data message
 *
 * @return Height above ellipsoid [mm]
 */
static inline int32_t alink_msg_gps_data_get_height(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  20);
}

/**
 * @brief Get field sAcc from gps_data message
 *
 * @return speed accuracy estimate m/s
 */
static inline int32_t alink_msg_gps_data_get_sAcc(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  24);
}

/**
 * @brief Get field hAcc from gps_data message
 *
 * @return float UBOX HDOP horizontal dilution of position in m
 */
static inline int32_t alink_msg_gps_data_get_hAcc(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  28);
}

/**
 * @brief Get field vAcc from gps_data message
 *
 * @return UBOX VDOP horizontal dilution of position in m
 */
static inline int32_t alink_msg_gps_data_get_vAcc(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  32);
}

/**
 * @brief Get field noise_per_ms from gps_data message
 *
 * @return undefined
 */
static inline uint32_t alink_msg_gps_data_get_noise_per_ms(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint32_t(msg,  36);
}

/**
 * @brief Get field jamming_indicator from gps_data message
 *
 * @return undefined
 */
static inline uint32_t alink_msg_gps_data_get_jamming_indicator(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint32_t(msg,  40);
}

/**
 * @brief Get field vel_m_s from gps_data message
 *
 * @return UBOX ground speed (m/s) 
 */
static inline int32_t alink_msg_gps_data_get_vel_m_s(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  44);
}

/**
 * @brief Get field vel_n_m_s from gps_data message
 *
 * @return UBOX ground speed in m/s
 */
static inline int32_t alink_msg_gps_data_get_vel_n_m_s(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  48);
}

/**
 * @brief Get field vel_e_m_s from gps_data message
 *
 * @return UBOX ground speed in m/s
 */
static inline int32_t alink_msg_gps_data_get_vel_e_m_s(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  52);
}

/**
 * @brief Get field vel_d_m_s from gps_data message
 *
 * @return UBOX ground speed in m/s
 */
static inline int32_t alink_msg_gps_data_get_vel_d_m_s(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  56);
}

/**
 * @brief Get field headAcc from gps_data message
 *
 * @return undefined
 */
static inline uint32_t alink_msg_gps_data_get_headAcc(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint32_t(msg,  60);
}

/**
 * @brief Get field headMot from gps_data message
 *
 * @return undefined
 */
static inline int32_t alink_msg_gps_data_get_headMot(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  64);
}

/**
 * @brief Get field satellites_used from gps_data message
 *
 * @return Number of satellites used 
 */
static inline uint8_t alink_msg_gps_data_get_satellites_used(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  84);
}

/**
 * @brief Get field pDOP from gps_data message
 *
 * @return undefined
 */
static inline uint8_t alink_msg_gps_data_get_pDOP(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  85);
}

/**
 * @brief Get field vel_ned_valid from gps_data message
 *
 * @return Flag to indicate if NED speed is valid 
 */
static inline uint8_t alink_msg_gps_data_get_vel_ned_valid(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  86);
}

/**
 * @brief Get field fix_type from gps_data message
 *
 * @return 0-1: no fix, 2: 2D fix, 3: 3D fix. Some applications will not use the value of this field unless it is at least two, so always correctly fill in the fix.
 */
static inline uint8_t alink_msg_gps_data_get_fix_type(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  87);
}

/**
 * @brief Get field satellites_num_over42db from gps_data message
 *
 * @return Number of satellites over42db used 
 */
static inline uint8_t alink_msg_gps_data_get_satellites_num_over42db(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  88);
}

/**
 * @brief Get field reserved1 from gps_data message
 *
 * @return reserved1
 */
static inline int32_t alink_msg_gps_data_get_reserved1(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  68);
}

/**
 * @brief Get field reserved2 from gps_data message
 *
 * @return reserved2
 */
static inline int32_t alink_msg_gps_data_get_reserved2(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  72);
}

/**
 * @brief Get field reserved3 from gps_data message
 *
 * @return reserved3
 */
static inline int32_t alink_msg_gps_data_get_reserved3(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  76);
}

/**
 * @brief Get field reserved4 from gps_data message
 *
 * @return reserved4
 */
static inline int32_t alink_msg_gps_data_get_reserved4(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  80);
}

/**
 * @brief Decode a gps_data message into a struct
 *
 * @param msg The message to decode
 * @param gps_data C-struct to decode the message contents into
 */
static inline void alink_msg_gps_data_decode(const alink_message_head_t* msg, alink_gps_data_t* gps_data)
{
#if ALINK_NEED_BYTE_SWAP
	gps_data->time_gps_usec = alink_msg_gps_data_get_time_gps_usec(msg);
	gps_data->lat = alink_msg_gps_data_get_lat(msg);
	gps_data->lon = alink_msg_gps_data_get_lon(msg);
	gps_data->alt = alink_msg_gps_data_get_alt(msg);
	gps_data->height = alink_msg_gps_data_get_height(msg);
	gps_data->sAcc = alink_msg_gps_data_get_sAcc(msg);
	gps_data->hAcc = alink_msg_gps_data_get_hAcc(msg);
	gps_data->vAcc = alink_msg_gps_data_get_vAcc(msg);
	gps_data->noise_per_ms = alink_msg_gps_data_get_noise_per_ms(msg);
	gps_data->jamming_indicator = alink_msg_gps_data_get_jamming_indicator(msg);
	gps_data->vel_m_s = alink_msg_gps_data_get_vel_m_s(msg);
	gps_data->vel_n_m_s = alink_msg_gps_data_get_vel_n_m_s(msg);
	gps_data->vel_e_m_s = alink_msg_gps_data_get_vel_e_m_s(msg);
	gps_data->vel_d_m_s = alink_msg_gps_data_get_vel_d_m_s(msg);
	gps_data->headAcc = alink_msg_gps_data_get_headAcc(msg);
	gps_data->headMot = alink_msg_gps_data_get_headMot(msg);
	gps_data->reserved1 = alink_msg_gps_data_get_reserved1(msg);
	gps_data->reserved2 = alink_msg_gps_data_get_reserved2(msg);
	gps_data->reserved3 = alink_msg_gps_data_get_reserved3(msg);
	gps_data->reserved4 = alink_msg_gps_data_get_reserved4(msg);
	gps_data->satellites_used = alink_msg_gps_data_get_satellites_used(msg);
	gps_data->pDOP = alink_msg_gps_data_get_pDOP(msg);
	gps_data->vel_ned_valid = alink_msg_gps_data_get_vel_ned_valid(msg);
	gps_data->fix_type = alink_msg_gps_data_get_fix_type(msg);
	gps_data->satellites_num_over42db = alink_msg_gps_data_get_satellites_num_over42db(msg);
#else
	memcpy(gps_data, _MAV_PAYLOAD(msg), ALINK_MSG_ID_GPS_DATA_LEN);
#endif
}
