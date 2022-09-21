// MESSAGE ADSB_VEHICLE PACKING

#define ALINK_MSG_ID_ADSB_VEHICLE 246

typedef struct __alink_adsb_vehicle_t
{
 uint32_t ICAO_address; /*< ICAO address*/
 int32_t lat; /*< Latitude*/
 int32_t lon; /*< Longitude*/
 int32_t altitude; /*< Altitude(ASL)*/
 uint16_t heading; /*< Course over ground*/
 uint16_t hor_velocity; /*< The horizontal velocity*/
 int16_t ver_velocity; /*< The vertical velocity. Positive is up*/
 uint16_t flags; /*< Bitmap to indicate various statuses including valid data fields*/
 uint16_t squawk; /*< Squawk code*/
 uint8_t altitude_type; /*< ADSB altitude type.*/
 char callsign[9]; /*< The callsign, 8+null*/
 uint8_t emitter_type; /*< ADSB emitter type.*/
 uint8_t tslc; /*< Time since last communication in seconds*/
} alink_adsb_vehicle_t;

#define ALINK_MSG_ID_ADSB_VEHICLE_LEN 38
#define ALINK_MSG_ID_246_LEN 38

#define ALINK_MSG_ID_ADSB_VEHICLE_CRC 184
#define ALINK_MSG_ID_246_CRC 184

#define ALINK_MSG_ADSB_VEHICLE_FIELD_CALLSIGN_LEN 9

#define ALINK_MESSAGE_INFO_ADSB_VEHICLE { \
	"ADSB_VEHICLE", \
	13, \
	{  { "ICAO_address", NULL, ALINK_TYPE_UINT32_T, 0, 0, offsetof(alink_adsb_vehicle_t, ICAO_address) }, \
         { "lat", NULL, ALINK_TYPE_INT32_T, 0, 4, offsetof(alink_adsb_vehicle_t, lat) }, \
         { "lon", NULL, ALINK_TYPE_INT32_T, 0, 8, offsetof(alink_adsb_vehicle_t, lon) }, \
         { "altitude", NULL, ALINK_TYPE_INT32_T, 0, 12, offsetof(alink_adsb_vehicle_t, altitude) }, \
         { "heading", NULL, ALINK_TYPE_UINT16_T, 0, 16, offsetof(alink_adsb_vehicle_t, heading) }, \
         { "hor_velocity", NULL, ALINK_TYPE_UINT16_T, 0, 18, offsetof(alink_adsb_vehicle_t, hor_velocity) }, \
         { "ver_velocity", NULL, ALINK_TYPE_INT16_T, 0, 20, offsetof(alink_adsb_vehicle_t, ver_velocity) }, \
         { "flags", NULL, ALINK_TYPE_UINT16_T, 0, 22, offsetof(alink_adsb_vehicle_t, flags) }, \
         { "squawk", NULL, ALINK_TYPE_UINT16_T, 0, 24, offsetof(alink_adsb_vehicle_t, squawk) }, \
         { "altitude_type", NULL, ALINK_TYPE_UINT8_T, 0, 26, offsetof(alink_adsb_vehicle_t, altitude_type) }, \
         { "callsign", NULL, ALINK_TYPE_CHAR, 9, 27, offsetof(alink_adsb_vehicle_t, callsign) }, \
         { "emitter_type", NULL, ALINK_TYPE_UINT8_T, 0, 36, offsetof(alink_adsb_vehicle_t, emitter_type) }, \
         { "tslc", NULL, ALINK_TYPE_UINT8_T, 0, 37, offsetof(alink_adsb_vehicle_t, tslc) }, \
         } \
}


/**
 * @brief Pack a adsb_vehicle message
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 *
 * @param ICAO_address ICAO address
 * @param lat Latitude
 * @param lon Longitude
 * @param altitude_type ADSB altitude type.
 * @param altitude Altitude(ASL)
 * @param heading Course over ground
 * @param hor_velocity The horizontal velocity
 * @param ver_velocity The vertical velocity. Positive is up
 * @param callsign The callsign, 8+null
 * @param emitter_type ADSB emitter type.
 * @param tslc Time since last communication in seconds
 * @param flags Bitmap to indicate various statuses including valid data fields
 * @param squawk Squawk code
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_adsb_vehicle_pack(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg,
						       uint32_t ICAO_address, int32_t lat, int32_t lon, uint8_t altitude_type, int32_t altitude, uint16_t heading, uint16_t hor_velocity, int16_t ver_velocity, const char *callsign, uint8_t emitter_type, uint8_t tslc, uint16_t flags, uint16_t squawk)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_ADSB_VEHICLE_LEN];
	_mav_put_uint32_t(buf, 0, ICAO_address);
	_mav_put_int32_t(buf, 4, lat);
	_mav_put_int32_t(buf, 8, lon);
	_mav_put_int32_t(buf, 12, altitude);
	_mav_put_uint16_t(buf, 16, heading);
	_mav_put_uint16_t(buf, 18, hor_velocity);
	_mav_put_int16_t(buf, 20, ver_velocity);
	_mav_put_uint16_t(buf, 22, flags);
	_mav_put_uint16_t(buf, 24, squawk);
	_mav_put_uint8_t(buf, 26, altitude_type);
	_mav_put_uint8_t(buf, 36, emitter_type);
	_mav_put_uint8_t(buf, 37, tslc);
	_mav_put_char_array(buf, 27, callsign, 9);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_ADSB_VEHICLE_LEN);
#else
	alink_adsb_vehicle_t packet;
	packet.ICAO_address = ICAO_address;
	packet.lat = lat;
	packet.lon = lon;
	packet.altitude = altitude;
	packet.heading = heading;
	packet.hor_velocity = hor_velocity;
	packet.ver_velocity = ver_velocity;
	packet.flags = flags;
	packet.squawk = squawk;
	packet.altitude_type = altitude_type;
	packet.emitter_type = emitter_type;
	packet.tslc = tslc;
	mav_array_memcpy(packet.callsign, callsign, sizeof(char)*9);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_ADSB_VEHICLE_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_ADSB_VEHICLE;
#if ALINK_CRC_EXTRA
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_ADSB_VEHICLE_LEN,ALINK_MSG_ID_ADSB_VEHICLE_CRC);
#else
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_ADSB_VEHICLE_LEN);
#endif
}

/**
 * @brief Pack a adsb_vehicle message on a channel
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param ICAO_address ICAO address
 * @param lat Latitude
 * @param lon Longitude
 * @param altitude_type ADSB altitude type.
 * @param altitude Altitude(ASL)
 * @param heading Course over ground
 * @param hor_velocity The horizontal velocity
 * @param ver_velocity The vertical velocity. Positive is up
 * @param callsign The callsign, 8+null
 * @param emitter_type ADSB emitter type.
 * @param tslc Time since last communication in seconds
 * @param flags Bitmap to indicate various statuses including valid data fields
 * @param squawk Squawk code
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_adsb_vehicle_pack_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan,
							   alink_message_head_t* msg,
						           uint32_t ICAO_address,int32_t lat,int32_t lon,uint8_t altitude_type,int32_t altitude,uint16_t heading,uint16_t hor_velocity,int16_t ver_velocity,const char *callsign,uint8_t emitter_type,uint8_t tslc,uint16_t flags,uint16_t squawk)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_ADSB_VEHICLE_LEN];
	_mav_put_uint32_t(buf, 0, ICAO_address);
	_mav_put_int32_t(buf, 4, lat);
	_mav_put_int32_t(buf, 8, lon);
	_mav_put_int32_t(buf, 12, altitude);
	_mav_put_uint16_t(buf, 16, heading);
	_mav_put_uint16_t(buf, 18, hor_velocity);
	_mav_put_int16_t(buf, 20, ver_velocity);
	_mav_put_uint16_t(buf, 22, flags);
	_mav_put_uint16_t(buf, 24, squawk);
	_mav_put_uint8_t(buf, 26, altitude_type);
	_mav_put_uint8_t(buf, 36, emitter_type);
	_mav_put_uint8_t(buf, 37, tslc);
	_mav_put_char_array(buf, 27, callsign, 9);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_ADSB_VEHICLE_LEN);
#else
	alink_adsb_vehicle_t packet;
	packet.ICAO_address = ICAO_address;
	packet.lat = lat;
	packet.lon = lon;
	packet.altitude = altitude;
	packet.heading = heading;
	packet.hor_velocity = hor_velocity;
	packet.ver_velocity = ver_velocity;
	packet.flags = flags;
	packet.squawk = squawk;
	packet.altitude_type = altitude_type;
	packet.emitter_type = emitter_type;
	packet.tslc = tslc;
	mav_array_memcpy(packet.callsign, callsign, sizeof(char)*9);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_ADSB_VEHICLE_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_ADSB_VEHICLE;
#if ALINK_CRC_EXTRA
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_ADSB_VEHICLE_LEN,ALINK_MSG_ID_ADSB_VEHICLE_CRC);
#else
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_ADSB_VEHICLE_LEN);
#endif
}
/**
 * @brief Encode a adsb_vehicle struct
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 * @param adsb_vehicle C-struct to read the message contents from
 */
static inline uint16_t alink_msg_adsb_vehicle_encode(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg, const alink_adsb_vehicle_t* adsb_vehicle)
{
	return alink_msg_adsb_vehicle_pack(dest_id, source_id, msg, adsb_vehicle->ICAO_address, adsb_vehicle->lat, adsb_vehicle->lon, adsb_vehicle->altitude_type, adsb_vehicle->altitude, adsb_vehicle->heading, adsb_vehicle->hor_velocity, adsb_vehicle->ver_velocity, adsb_vehicle->callsign, adsb_vehicle->emitter_type, adsb_vehicle->tslc, adsb_vehicle->flags, adsb_vehicle->squawk);
}

/**
 * @brief Encode a adsb_vehicle struct on a channel
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param adsb_vehicle C-struct to read the message contents from
 */
static inline uint16_t alink_msg_adsb_vehicle_encode_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan, alink_message_head_t* msg, const alink_adsb_vehicle_t* adsb_vehicle)
{
	return alink_msg_adsb_vehicle_pack_chan(dest_id, source_id, chan, msg, adsb_vehicle->ICAO_address, adsb_vehicle->lat, adsb_vehicle->lon, adsb_vehicle->altitude_type, adsb_vehicle->altitude, adsb_vehicle->heading, adsb_vehicle->hor_velocity, adsb_vehicle->ver_velocity, adsb_vehicle->callsign, adsb_vehicle->emitter_type, adsb_vehicle->tslc, adsb_vehicle->flags, adsb_vehicle->squawk);
}
// MESSAGE ADSB_VEHICLE UNPACKING


/**
 * @brief Get field ICAO_address from adsb_vehicle message
 *
 * @return ICAO address
 */
static inline uint32_t alink_msg_adsb_vehicle_get_ICAO_address(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field lat from adsb_vehicle message
 *
 * @return Latitude
 */
static inline int32_t alink_msg_adsb_vehicle_get_lat(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  4);
}

/**
 * @brief Get field lon from adsb_vehicle message
 *
 * @return Longitude
 */
static inline int32_t alink_msg_adsb_vehicle_get_lon(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  8);
}

/**
 * @brief Get field altitude_type from adsb_vehicle message
 *
 * @return ADSB altitude type.
 */
static inline uint8_t alink_msg_adsb_vehicle_get_altitude_type(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  26);
}

/**
 * @brief Get field altitude from adsb_vehicle message
 *
 * @return Altitude(ASL)
 */
static inline int32_t alink_msg_adsb_vehicle_get_altitude(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  12);
}

/**
 * @brief Get field heading from adsb_vehicle message
 *
 * @return Course over ground
 */
static inline uint16_t alink_msg_adsb_vehicle_get_heading(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  16);
}

/**
 * @brief Get field hor_velocity from adsb_vehicle message
 *
 * @return The horizontal velocity
 */
static inline uint16_t alink_msg_adsb_vehicle_get_hor_velocity(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  18);
}

/**
 * @brief Get field ver_velocity from adsb_vehicle message
 *
 * @return The vertical velocity. Positive is up
 */
static inline int16_t alink_msg_adsb_vehicle_get_ver_velocity(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  20);
}

/**
 * @brief Get field callsign from adsb_vehicle message
 *
 * @return The callsign, 8+null
 */
static inline uint16_t alink_msg_adsb_vehicle_get_callsign(const alink_message_head_t* msg, char *callsign)
{
	return _MAV_RETURN_char_array(msg, callsign, 9,  27);
}

/**
 * @brief Get field emitter_type from adsb_vehicle message
 *
 * @return ADSB emitter type.
 */
static inline uint8_t alink_msg_adsb_vehicle_get_emitter_type(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  36);
}

/**
 * @brief Get field tslc from adsb_vehicle message
 *
 * @return Time since last communication in seconds
 */
static inline uint8_t alink_msg_adsb_vehicle_get_tslc(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  37);
}

/**
 * @brief Get field flags from adsb_vehicle message
 *
 * @return Bitmap to indicate various statuses including valid data fields
 */
static inline uint16_t alink_msg_adsb_vehicle_get_flags(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  22);
}

/**
 * @brief Get field squawk from adsb_vehicle message
 *
 * @return Squawk code
 */
static inline uint16_t alink_msg_adsb_vehicle_get_squawk(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  24);
}

/**
 * @brief Decode a adsb_vehicle message into a struct
 *
 * @param msg The message to decode
 * @param adsb_vehicle C-struct to decode the message contents into
 */
static inline void alink_msg_adsb_vehicle_decode(const alink_message_head_t* msg, alink_adsb_vehicle_t* adsb_vehicle)
{
#if ALINK_NEED_BYTE_SWAP
	adsb_vehicle->ICAO_address = alink_msg_adsb_vehicle_get_ICAO_address(msg);
	adsb_vehicle->lat = alink_msg_adsb_vehicle_get_lat(msg);
	adsb_vehicle->lon = alink_msg_adsb_vehicle_get_lon(msg);
	adsb_vehicle->altitude = alink_msg_adsb_vehicle_get_altitude(msg);
	adsb_vehicle->heading = alink_msg_adsb_vehicle_get_heading(msg);
	adsb_vehicle->hor_velocity = alink_msg_adsb_vehicle_get_hor_velocity(msg);
	adsb_vehicle->ver_velocity = alink_msg_adsb_vehicle_get_ver_velocity(msg);
	adsb_vehicle->flags = alink_msg_adsb_vehicle_get_flags(msg);
	adsb_vehicle->squawk = alink_msg_adsb_vehicle_get_squawk(msg);
	adsb_vehicle->altitude_type = alink_msg_adsb_vehicle_get_altitude_type(msg);
	alink_msg_adsb_vehicle_get_callsign(msg, adsb_vehicle->callsign);
	adsb_vehicle->emitter_type = alink_msg_adsb_vehicle_get_emitter_type(msg);
	adsb_vehicle->tslc = alink_msg_adsb_vehicle_get_tslc(msg);
#else
	memcpy(adsb_vehicle, _MAV_PAYLOAD(msg), ALINK_MSG_ID_ADSB_VEHICLE_LEN);
#endif
}
