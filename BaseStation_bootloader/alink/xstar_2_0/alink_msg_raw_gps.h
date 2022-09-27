// MESSAGE RAW_GPS PACKING

#define ALINK_MSG_ID_RAW_GPS 24

typedef struct __alink_raw_gps_t
{
 uint64_t timestamp; /*< timestamp (microseconds since UNIX epoch or microseconds since system boot)*/
 int32_t lat; /*< Latitude (WGS84), in degrees * 1E7*/
 int32_t lon; /*< Longitude (WGS84), in degrees * 1E7*/
 int32_t alt; /*< Altitude (AMSL, NOT WGS84), in meters * 1000 (positive for up). Note that virtually all GPS modules provide the AMSL altitude in addition to the WGS84 altitude.*/
 int32_t hmsl; /*< Height above ellipsoid [mm].*/
 int32_t velN; /*< GPS ground speed in m/s*/
 int32_t velE; /*< GPS ground speed in m/s*/
 int32_t velD; /*< GPS ground speed in m/s*/
 int32_t gspd; /*< GPS ground speed (m/s)*/
 int32_t hAcc; /*< GPS HDOP horizontal dilution of position (unitless). If unknown, set to: UINT16_MAX*/
 int32_t vAcc; /*< GPS VDOP vertical dilution of position (unitless). If unknown, set to: UINT16_MAX*/
 int32_t sAcc; /*< GPS ground speed (m/s * 100). If unknown, set to: UINT16_MAX*/
 float time_usec; /*< timestamp microseconds in GPS format*/
 uint8_t vel_ned_valid; /*< Flag to indicate if NED speed is valid*/
 uint8_t fixtype; /*< 0-1: no fix, 2: 2D fix, 3: 3D fix. Some applications will not use the value of this field unless it is at least two, so always correctly fill in the fix.*/
 uint8_t satellites_used; /*< timestamp microseconds in GPS format, this is the timestamp which comes from the gps module*/
} alink_raw_gps_t;

#define ALINK_MSG_ID_RAW_GPS_LEN 59
#define ALINK_MSG_ID_24_LEN 59

#define ALINK_MSG_ID_RAW_GPS_CRC 128
#define ALINK_MSG_ID_24_CRC 128



#define ALINK_MESSAGE_INFO_RAW_GPS { \
	"RAW_GPS", \
	16, \
	{  { "timestamp", NULL, ALINK_TYPE_UINT64_T, 0, 0, offsetof(alink_raw_gps_t, timestamp) }, \
         { "lat", NULL, ALINK_TYPE_INT32_T, 0, 8, offsetof(alink_raw_gps_t, lat) }, \
         { "lon", NULL, ALINK_TYPE_INT32_T, 0, 12, offsetof(alink_raw_gps_t, lon) }, \
         { "alt", NULL, ALINK_TYPE_INT32_T, 0, 16, offsetof(alink_raw_gps_t, alt) }, \
         { "hmsl", NULL, ALINK_TYPE_INT32_T, 0, 20, offsetof(alink_raw_gps_t, hmsl) }, \
         { "velN", NULL, ALINK_TYPE_INT32_T, 0, 24, offsetof(alink_raw_gps_t, velN) }, \
         { "velE", NULL, ALINK_TYPE_INT32_T, 0, 28, offsetof(alink_raw_gps_t, velE) }, \
         { "velD", NULL, ALINK_TYPE_INT32_T, 0, 32, offsetof(alink_raw_gps_t, velD) }, \
         { "gspd", NULL, ALINK_TYPE_INT32_T, 0, 36, offsetof(alink_raw_gps_t, gspd) }, \
         { "hAcc", NULL, ALINK_TYPE_INT32_T, 0, 40, offsetof(alink_raw_gps_t, hAcc) }, \
         { "vAcc", NULL, ALINK_TYPE_INT32_T, 0, 44, offsetof(alink_raw_gps_t, vAcc) }, \
         { "sAcc", NULL, ALINK_TYPE_INT32_T, 0, 48, offsetof(alink_raw_gps_t, sAcc) }, \
         { "time_usec", NULL, ALINK_TYPE_FLOAT, 0, 52, offsetof(alink_raw_gps_t, time_usec) }, \
         { "vel_ned_valid", NULL, ALINK_TYPE_UINT8_T, 0, 56, offsetof(alink_raw_gps_t, vel_ned_valid) }, \
         { "fixtype", NULL, ALINK_TYPE_UINT8_T, 0, 57, offsetof(alink_raw_gps_t, fixtype) }, \
         { "satellites_used", NULL, ALINK_TYPE_UINT8_T, 0, 58, offsetof(alink_raw_gps_t, satellites_used) }, \
         } \
}


/**
 * @brief Pack a raw_gps message
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 *
 * @param timestamp timestamp (microseconds since UNIX epoch or microseconds since system boot)
 * @param lat Latitude (WGS84), in degrees * 1E7
 * @param lon Longitude (WGS84), in degrees * 1E7
 * @param alt Altitude (AMSL, NOT WGS84), in meters * 1000 (positive for up). Note that virtually all GPS modules provide the AMSL altitude in addition to the WGS84 altitude.
 * @param hmsl Height above ellipsoid [mm].
 * @param velN GPS ground speed in m/s
 * @param velE GPS ground speed in m/s
 * @param velD GPS ground speed in m/s
 * @param gspd GPS ground speed (m/s)
 * @param vel_ned_valid Flag to indicate if NED speed is valid
 * @param hAcc GPS HDOP horizontal dilution of position (unitless). If unknown, set to: UINT16_MAX
 * @param vAcc GPS VDOP vertical dilution of position (unitless). If unknown, set to: UINT16_MAX
 * @param sAcc GPS ground speed (m/s * 100). If unknown, set to: UINT16_MAX
 * @param time_usec timestamp microseconds in GPS format
 * @param fixtype 0-1: no fix, 2: 2D fix, 3: 3D fix. Some applications will not use the value of this field unless it is at least two, so always correctly fill in the fix.
 * @param satellites_used timestamp microseconds in GPS format, this is the timestamp which comes from the gps module
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_raw_gps_pack(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg,
						       uint64_t timestamp, int32_t lat, int32_t lon, int32_t alt, int32_t hmsl, int32_t velN, int32_t velE, int32_t velD, int32_t gspd, uint8_t vel_ned_valid, int32_t hAcc, int32_t vAcc, int32_t sAcc, float time_usec, uint8_t fixtype, uint8_t satellites_used)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_RAW_GPS_LEN];
	_mav_put_uint64_t(buf, 0, timestamp);
	_mav_put_int32_t(buf, 8, lat);
	_mav_put_int32_t(buf, 12, lon);
	_mav_put_int32_t(buf, 16, alt);
	_mav_put_int32_t(buf, 20, hmsl);
	_mav_put_int32_t(buf, 24, velN);
	_mav_put_int32_t(buf, 28, velE);
	_mav_put_int32_t(buf, 32, velD);
	_mav_put_int32_t(buf, 36, gspd);
	_mav_put_int32_t(buf, 40, hAcc);
	_mav_put_int32_t(buf, 44, vAcc);
	_mav_put_int32_t(buf, 48, sAcc);
	_mav_put_float(buf, 52, time_usec);
	_mav_put_uint8_t(buf, 56, vel_ned_valid);
	_mav_put_uint8_t(buf, 57, fixtype);
	_mav_put_uint8_t(buf, 58, satellites_used);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_RAW_GPS_LEN);
#else
	alink_raw_gps_t packet;
	packet.timestamp = timestamp;
	packet.lat = lat;
	packet.lon = lon;
	packet.alt = alt;
	packet.hmsl = hmsl;
	packet.velN = velN;
	packet.velE = velE;
	packet.velD = velD;
	packet.gspd = gspd;
	packet.hAcc = hAcc;
	packet.vAcc = vAcc;
	packet.sAcc = sAcc;
	packet.time_usec = time_usec;
	packet.vel_ned_valid = vel_ned_valid;
	packet.fixtype = fixtype;
	packet.satellites_used = satellites_used;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_RAW_GPS_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_RAW_GPS;
#if ALINK_CRC_EXTRA
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_RAW_GPS_LEN,ALINK_MSG_ID_RAW_GPS_CRC);
#else
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_RAW_GPS_LEN);
#endif
}

/**
 * @brief Pack a raw_gps message on a channel
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param timestamp timestamp (microseconds since UNIX epoch or microseconds since system boot)
 * @param lat Latitude (WGS84), in degrees * 1E7
 * @param lon Longitude (WGS84), in degrees * 1E7
 * @param alt Altitude (AMSL, NOT WGS84), in meters * 1000 (positive for up). Note that virtually all GPS modules provide the AMSL altitude in addition to the WGS84 altitude.
 * @param hmsl Height above ellipsoid [mm].
 * @param velN GPS ground speed in m/s
 * @param velE GPS ground speed in m/s
 * @param velD GPS ground speed in m/s
 * @param gspd GPS ground speed (m/s)
 * @param vel_ned_valid Flag to indicate if NED speed is valid
 * @param hAcc GPS HDOP horizontal dilution of position (unitless). If unknown, set to: UINT16_MAX
 * @param vAcc GPS VDOP vertical dilution of position (unitless). If unknown, set to: UINT16_MAX
 * @param sAcc GPS ground speed (m/s * 100). If unknown, set to: UINT16_MAX
 * @param time_usec timestamp microseconds in GPS format
 * @param fixtype 0-1: no fix, 2: 2D fix, 3: 3D fix. Some applications will not use the value of this field unless it is at least two, so always correctly fill in the fix.
 * @param satellites_used timestamp microseconds in GPS format, this is the timestamp which comes from the gps module
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_raw_gps_pack_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan,
							   alink_message_head_t* msg,
						           uint64_t timestamp,int32_t lat,int32_t lon,int32_t alt,int32_t hmsl,int32_t velN,int32_t velE,int32_t velD,int32_t gspd,uint8_t vel_ned_valid,int32_t hAcc,int32_t vAcc,int32_t sAcc,float time_usec,uint8_t fixtype,uint8_t satellites_used)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_RAW_GPS_LEN];
	_mav_put_uint64_t(buf, 0, timestamp);
	_mav_put_int32_t(buf, 8, lat);
	_mav_put_int32_t(buf, 12, lon);
	_mav_put_int32_t(buf, 16, alt);
	_mav_put_int32_t(buf, 20, hmsl);
	_mav_put_int32_t(buf, 24, velN);
	_mav_put_int32_t(buf, 28, velE);
	_mav_put_int32_t(buf, 32, velD);
	_mav_put_int32_t(buf, 36, gspd);
	_mav_put_int32_t(buf, 40, hAcc);
	_mav_put_int32_t(buf, 44, vAcc);
	_mav_put_int32_t(buf, 48, sAcc);
	_mav_put_float(buf, 52, time_usec);
	_mav_put_uint8_t(buf, 56, vel_ned_valid);
	_mav_put_uint8_t(buf, 57, fixtype);
	_mav_put_uint8_t(buf, 58, satellites_used);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_RAW_GPS_LEN);
#else
	alink_raw_gps_t packet;
	packet.timestamp = timestamp;
	packet.lat = lat;
	packet.lon = lon;
	packet.alt = alt;
	packet.hmsl = hmsl;
	packet.velN = velN;
	packet.velE = velE;
	packet.velD = velD;
	packet.gspd = gspd;
	packet.hAcc = hAcc;
	packet.vAcc = vAcc;
	packet.sAcc = sAcc;
	packet.time_usec = time_usec;
	packet.vel_ned_valid = vel_ned_valid;
	packet.fixtype = fixtype;
	packet.satellites_used = satellites_used;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_RAW_GPS_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_RAW_GPS;
#if ALINK_CRC_EXTRA
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_RAW_GPS_LEN,ALINK_MSG_ID_RAW_GPS_CRC);
#else
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_RAW_GPS_LEN);
#endif
}
/**
 * @brief Encode a raw_gps struct
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 * @param raw_gps C-struct to read the message contents from
 */
static inline uint16_t alink_msg_raw_gps_encode(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg, const alink_raw_gps_t* raw_gps)
{
	return alink_msg_raw_gps_pack(dest_id, source_id, msg, raw_gps->timestamp, raw_gps->lat, raw_gps->lon, raw_gps->alt, raw_gps->hmsl, raw_gps->velN, raw_gps->velE, raw_gps->velD, raw_gps->gspd, raw_gps->vel_ned_valid, raw_gps->hAcc, raw_gps->vAcc, raw_gps->sAcc, raw_gps->time_usec, raw_gps->fixtype, raw_gps->satellites_used);
}

/**
 * @brief Encode a raw_gps struct on a channel
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param raw_gps C-struct to read the message contents from
 */
static inline uint16_t alink_msg_raw_gps_encode_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan, alink_message_head_t* msg, const alink_raw_gps_t* raw_gps)
{
	return alink_msg_raw_gps_pack_chan(dest_id, source_id, chan, msg, raw_gps->timestamp, raw_gps->lat, raw_gps->lon, raw_gps->alt, raw_gps->hmsl, raw_gps->velN, raw_gps->velE, raw_gps->velD, raw_gps->gspd, raw_gps->vel_ned_valid, raw_gps->hAcc, raw_gps->vAcc, raw_gps->sAcc, raw_gps->time_usec, raw_gps->fixtype, raw_gps->satellites_used);
}
// MESSAGE RAW_GPS UNPACKING


/**
 * @brief Get field timestamp from raw_gps message
 *
 * @return timestamp (microseconds since UNIX epoch or microseconds since system boot)
 */
static inline uint64_t alink_msg_raw_gps_get_timestamp(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field lat from raw_gps message
 *
 * @return Latitude (WGS84), in degrees * 1E7
 */
static inline int32_t alink_msg_raw_gps_get_lat(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  8);
}

/**
 * @brief Get field lon from raw_gps message
 *
 * @return Longitude (WGS84), in degrees * 1E7
 */
static inline int32_t alink_msg_raw_gps_get_lon(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  12);
}

/**
 * @brief Get field alt from raw_gps message
 *
 * @return Altitude (AMSL, NOT WGS84), in meters * 1000 (positive for up). Note that virtually all GPS modules provide the AMSL altitude in addition to the WGS84 altitude.
 */
static inline int32_t alink_msg_raw_gps_get_alt(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  16);
}

/**
 * @brief Get field hmsl from raw_gps message
 *
 * @return Height above ellipsoid [mm].
 */
static inline int32_t alink_msg_raw_gps_get_hmsl(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  20);
}

/**
 * @brief Get field velN from raw_gps message
 *
 * @return GPS ground speed in m/s
 */
static inline int32_t alink_msg_raw_gps_get_velN(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  24);
}

/**
 * @brief Get field velE from raw_gps message
 *
 * @return GPS ground speed in m/s
 */
static inline int32_t alink_msg_raw_gps_get_velE(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  28);
}

/**
 * @brief Get field velD from raw_gps message
 *
 * @return GPS ground speed in m/s
 */
static inline int32_t alink_msg_raw_gps_get_velD(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  32);
}

/**
 * @brief Get field gspd from raw_gps message
 *
 * @return GPS ground speed (m/s)
 */
static inline int32_t alink_msg_raw_gps_get_gspd(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  36);
}

/**
 * @brief Get field vel_ned_valid from raw_gps message
 *
 * @return Flag to indicate if NED speed is valid
 */
static inline uint8_t alink_msg_raw_gps_get_vel_ned_valid(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  56);
}

/**
 * @brief Get field hAcc from raw_gps message
 *
 * @return GPS HDOP horizontal dilution of position (unitless). If unknown, set to: UINT16_MAX
 */
static inline int32_t alink_msg_raw_gps_get_hAcc(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  40);
}

/**
 * @brief Get field vAcc from raw_gps message
 *
 * @return GPS VDOP vertical dilution of position (unitless). If unknown, set to: UINT16_MAX
 */
static inline int32_t alink_msg_raw_gps_get_vAcc(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  44);
}

/**
 * @brief Get field sAcc from raw_gps message
 *
 * @return GPS ground speed (m/s * 100). If unknown, set to: UINT16_MAX
 */
static inline int32_t alink_msg_raw_gps_get_sAcc(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  48);
}

/**
 * @brief Get field time_usec from raw_gps message
 *
 * @return timestamp microseconds in GPS format
 */
static inline float alink_msg_raw_gps_get_time_usec(const alink_message_head_t* msg)
{
	return _MAV_RETURN_float(msg,  52);
}

/**
 * @brief Get field fixtype from raw_gps message
 *
 * @return 0-1: no fix, 2: 2D fix, 3: 3D fix. Some applications will not use the value of this field unless it is at least two, so always correctly fill in the fix.
 */
static inline uint8_t alink_msg_raw_gps_get_fixtype(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  57);
}

/**
 * @brief Get field satellites_used from raw_gps message
 *
 * @return timestamp microseconds in GPS format, this is the timestamp which comes from the gps module
 */
static inline uint8_t alink_msg_raw_gps_get_satellites_used(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  58);
}

/**
 * @brief Decode a raw_gps message into a struct
 *
 * @param msg The message to decode
 * @param raw_gps C-struct to decode the message contents into
 */
static inline void alink_msg_raw_gps_decode(const alink_message_head_t* msg, alink_raw_gps_t* raw_gps)
{
#if ALINK_NEED_BYTE_SWAP
	raw_gps->timestamp = alink_msg_raw_gps_get_timestamp(msg);
	raw_gps->lat = alink_msg_raw_gps_get_lat(msg);
	raw_gps->lon = alink_msg_raw_gps_get_lon(msg);
	raw_gps->alt = alink_msg_raw_gps_get_alt(msg);
	raw_gps->hmsl = alink_msg_raw_gps_get_hmsl(msg);
	raw_gps->velN = alink_msg_raw_gps_get_velN(msg);
	raw_gps->velE = alink_msg_raw_gps_get_velE(msg);
	raw_gps->velD = alink_msg_raw_gps_get_velD(msg);
	raw_gps->gspd = alink_msg_raw_gps_get_gspd(msg);
	raw_gps->hAcc = alink_msg_raw_gps_get_hAcc(msg);
	raw_gps->vAcc = alink_msg_raw_gps_get_vAcc(msg);
	raw_gps->sAcc = alink_msg_raw_gps_get_sAcc(msg);
	raw_gps->time_usec = alink_msg_raw_gps_get_time_usec(msg);
	raw_gps->vel_ned_valid = alink_msg_raw_gps_get_vel_ned_valid(msg);
	raw_gps->fixtype = alink_msg_raw_gps_get_fixtype(msg);
	raw_gps->satellites_used = alink_msg_raw_gps_get_satellites_used(msg);
#else
	memcpy(raw_gps, _MAV_PAYLOAD(msg), ALINK_MSG_ID_RAW_GPS_LEN);
#endif
}
