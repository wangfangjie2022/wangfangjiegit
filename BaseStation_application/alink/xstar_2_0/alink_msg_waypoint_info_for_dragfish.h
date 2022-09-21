// MESSAGE WAYPOINT_INFO_FOR_DRAGFISH PACKING

#define ALINK_MSG_ID_WAYPOINT_INFO_FOR_DRAGFISH 91

typedef struct __alink_waypoint_info_for_dragfish_t
{
 int32_t mission_id; /*< mission id*/
 int32_t waypoint_id; /*< waypoint id*/
 int32_t waypoint_type; /*<  0-Normal 1-Orbit 2-Cylinder 3-Panorama 4-TakeOff 5-LoiterTime 6-LoiterTurns 7-Landing 8-Interest 9-Mapping 10-Emergency 11-homepoint*/
 int32_t lattitude; /*< lattitude of waypoint in 10E-7 degree*/
 int32_t longitude; /*< longitude of waypoint in 10E-7 degree*/
 int32_t altitude; /*< altitude of waypoint in mm*/
 float speed; /*< speed in m/s*/
 int32_t param1; /*< param1*/
 int32_t param2; /*< param2*/
 int32_t param3; /*< param3*/
 int32_t param4; /*< param4*/
 int32_t param5; /*< param5*/
 int32_t param6; /*< param6*/
 int32_t param7; /*< param7*/
 int32_t altitude_priority; /*<  0 - elevate as approach , 1 - elevate first then approach */
 int32_t heading_mode; /*<  0 - invalid, 1 - next waypoint, 2 - initial , 3 - user defined*/
 int32_t user_defined_heading; /*<  N/E/D estimated velocity in 10E-3 m/s*/
 int32_t camera_yaw; /*<  yaw of camera/gimbal*/
 int32_t camera_pitch; /*<   pitch of camera/gimbal */
 int32_t number_actions; /*<  number of actions belong to this waypoint */
} alink_waypoint_info_for_dragfish_t;

#define ALINK_MSG_ID_WAYPOINT_INFO_FOR_DRAGFISH_LEN 80
#define ALINK_MSG_ID_91_LEN 80

#define ALINK_MSG_ID_WAYPOINT_INFO_FOR_DRAGFISH_CRC 158
#define ALINK_MSG_ID_91_CRC 158



#define ALINK_MESSAGE_INFO_WAYPOINT_INFO_FOR_DRAGFISH { \
	"WAYPOINT_INFO_FOR_DRAGFISH", \
	20, \
	{  { "mission_id", NULL, ALINK_TYPE_INT32_T, 0, 0, offsetof(alink_waypoint_info_for_dragfish_t, mission_id) }, \
         { "waypoint_id", NULL, ALINK_TYPE_INT32_T, 0, 4, offsetof(alink_waypoint_info_for_dragfish_t, waypoint_id) }, \
         { "waypoint_type", NULL, ALINK_TYPE_INT32_T, 0, 8, offsetof(alink_waypoint_info_for_dragfish_t, waypoint_type) }, \
         { "lattitude", NULL, ALINK_TYPE_INT32_T, 0, 12, offsetof(alink_waypoint_info_for_dragfish_t, lattitude) }, \
         { "longitude", NULL, ALINK_TYPE_INT32_T, 0, 16, offsetof(alink_waypoint_info_for_dragfish_t, longitude) }, \
         { "altitude", NULL, ALINK_TYPE_INT32_T, 0, 20, offsetof(alink_waypoint_info_for_dragfish_t, altitude) }, \
         { "speed", NULL, ALINK_TYPE_FLOAT, 0, 24, offsetof(alink_waypoint_info_for_dragfish_t, speed) }, \
         { "param1", NULL, ALINK_TYPE_INT32_T, 0, 28, offsetof(alink_waypoint_info_for_dragfish_t, param1) }, \
         { "param2", NULL, ALINK_TYPE_INT32_T, 0, 32, offsetof(alink_waypoint_info_for_dragfish_t, param2) }, \
         { "param3", NULL, ALINK_TYPE_INT32_T, 0, 36, offsetof(alink_waypoint_info_for_dragfish_t, param3) }, \
         { "param4", NULL, ALINK_TYPE_INT32_T, 0, 40, offsetof(alink_waypoint_info_for_dragfish_t, param4) }, \
         { "param5", NULL, ALINK_TYPE_INT32_T, 0, 44, offsetof(alink_waypoint_info_for_dragfish_t, param5) }, \
         { "param6", NULL, ALINK_TYPE_INT32_T, 0, 48, offsetof(alink_waypoint_info_for_dragfish_t, param6) }, \
         { "param7", NULL, ALINK_TYPE_INT32_T, 0, 52, offsetof(alink_waypoint_info_for_dragfish_t, param7) }, \
         { "altitude_priority", NULL, ALINK_TYPE_INT32_T, 0, 56, offsetof(alink_waypoint_info_for_dragfish_t, altitude_priority) }, \
         { "heading_mode", NULL, ALINK_TYPE_INT32_T, 0, 60, offsetof(alink_waypoint_info_for_dragfish_t, heading_mode) }, \
         { "user_defined_heading", NULL, ALINK_TYPE_INT32_T, 0, 64, offsetof(alink_waypoint_info_for_dragfish_t, user_defined_heading) }, \
         { "camera_yaw", NULL, ALINK_TYPE_INT32_T, 0, 68, offsetof(alink_waypoint_info_for_dragfish_t, camera_yaw) }, \
         { "camera_pitch", NULL, ALINK_TYPE_INT32_T, 0, 72, offsetof(alink_waypoint_info_for_dragfish_t, camera_pitch) }, \
         { "number_actions", NULL, ALINK_TYPE_INT32_T, 0, 76, offsetof(alink_waypoint_info_for_dragfish_t, number_actions) }, \
         } \
}


/**
 * @brief Pack a waypoint_info_for_dragfish message
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 *
 * @param mission_id mission id
 * @param waypoint_id waypoint id
 * @param waypoint_type  0-Normal 1-Orbit 2-Cylinder 3-Panorama 4-TakeOff 5-LoiterTime 6-LoiterTurns 7-Landing 8-Interest 9-Mapping 10-Emergency 11-homepoint
 * @param lattitude lattitude of waypoint in 10E-7 degree
 * @param longitude longitude of waypoint in 10E-7 degree
 * @param altitude altitude of waypoint in mm
 * @param speed speed in m/s
 * @param param1 param1
 * @param param2 param2
 * @param param3 param3
 * @param param4 param4
 * @param param5 param5
 * @param param6 param6
 * @param param7 param7
 * @param altitude_priority  0 - elevate as approach , 1 - elevate first then approach 
 * @param heading_mode  0 - invalid, 1 - next waypoint, 2 - initial , 3 - user defined
 * @param user_defined_heading  N/E/D estimated velocity in 10E-3 m/s
 * @param camera_yaw  yaw of camera/gimbal
 * @param camera_pitch   pitch of camera/gimbal 
 * @param number_actions  number of actions belong to this waypoint 
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_waypoint_info_for_dragfish_pack(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg,
						       int32_t mission_id, int32_t waypoint_id, int32_t waypoint_type, int32_t lattitude, int32_t longitude, int32_t altitude, float speed, int32_t param1, int32_t param2, int32_t param3, int32_t param4, int32_t param5, int32_t param6, int32_t param7, int32_t altitude_priority, int32_t heading_mode, int32_t user_defined_heading, int32_t camera_yaw, int32_t camera_pitch, int32_t number_actions)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_WAYPOINT_INFO_FOR_DRAGFISH_LEN];
	_mav_put_int32_t(buf, 0, mission_id);
	_mav_put_int32_t(buf, 4, waypoint_id);
	_mav_put_int32_t(buf, 8, waypoint_type);
	_mav_put_int32_t(buf, 12, lattitude);
	_mav_put_int32_t(buf, 16, longitude);
	_mav_put_int32_t(buf, 20, altitude);
	_mav_put_float(buf, 24, speed);
	_mav_put_int32_t(buf, 28, param1);
	_mav_put_int32_t(buf, 32, param2);
	_mav_put_int32_t(buf, 36, param3);
	_mav_put_int32_t(buf, 40, param4);
	_mav_put_int32_t(buf, 44, param5);
	_mav_put_int32_t(buf, 48, param6);
	_mav_put_int32_t(buf, 52, param7);
	_mav_put_int32_t(buf, 56, altitude_priority);
	_mav_put_int32_t(buf, 60, heading_mode);
	_mav_put_int32_t(buf, 64, user_defined_heading);
	_mav_put_int32_t(buf, 68, camera_yaw);
	_mav_put_int32_t(buf, 72, camera_pitch);
	_mav_put_int32_t(buf, 76, number_actions);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_WAYPOINT_INFO_FOR_DRAGFISH_LEN);
#else
	alink_waypoint_info_for_dragfish_t packet;
	packet.mission_id = mission_id;
	packet.waypoint_id = waypoint_id;
	packet.waypoint_type = waypoint_type;
	packet.lattitude = lattitude;
	packet.longitude = longitude;
	packet.altitude = altitude;
	packet.speed = speed;
	packet.param1 = param1;
	packet.param2 = param2;
	packet.param3 = param3;
	packet.param4 = param4;
	packet.param5 = param5;
	packet.param6 = param6;
	packet.param7 = param7;
	packet.altitude_priority = altitude_priority;
	packet.heading_mode = heading_mode;
	packet.user_defined_heading = user_defined_heading;
	packet.camera_yaw = camera_yaw;
	packet.camera_pitch = camera_pitch;
	packet.number_actions = number_actions;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_WAYPOINT_INFO_FOR_DRAGFISH_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_WAYPOINT_INFO_FOR_DRAGFISH;
#if ALINK_CRC_EXTRA
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_WAYPOINT_INFO_FOR_DRAGFISH_LEN,ALINK_MSG_ID_WAYPOINT_INFO_FOR_DRAGFISH_CRC);
#else
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_WAYPOINT_INFO_FOR_DRAGFISH_LEN);
#endif
}

/**
 * @brief Pack a waypoint_info_for_dragfish message on a channel
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param mission_id mission id
 * @param waypoint_id waypoint id
 * @param waypoint_type  0-Normal 1-Orbit 2-Cylinder 3-Panorama 4-TakeOff 5-LoiterTime 6-LoiterTurns 7-Landing 8-Interest 9-Mapping 10-Emergency 11-homepoint
 * @param lattitude lattitude of waypoint in 10E-7 degree
 * @param longitude longitude of waypoint in 10E-7 degree
 * @param altitude altitude of waypoint in mm
 * @param speed speed in m/s
 * @param param1 param1
 * @param param2 param2
 * @param param3 param3
 * @param param4 param4
 * @param param5 param5
 * @param param6 param6
 * @param param7 param7
 * @param altitude_priority  0 - elevate as approach , 1 - elevate first then approach 
 * @param heading_mode  0 - invalid, 1 - next waypoint, 2 - initial , 3 - user defined
 * @param user_defined_heading  N/E/D estimated velocity in 10E-3 m/s
 * @param camera_yaw  yaw of camera/gimbal
 * @param camera_pitch   pitch of camera/gimbal 
 * @param number_actions  number of actions belong to this waypoint 
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_waypoint_info_for_dragfish_pack_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan,
							   alink_message_head_t* msg,
						           int32_t mission_id,int32_t waypoint_id,int32_t waypoint_type,int32_t lattitude,int32_t longitude,int32_t altitude,float speed,int32_t param1,int32_t param2,int32_t param3,int32_t param4,int32_t param5,int32_t param6,int32_t param7,int32_t altitude_priority,int32_t heading_mode,int32_t user_defined_heading,int32_t camera_yaw,int32_t camera_pitch,int32_t number_actions)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_WAYPOINT_INFO_FOR_DRAGFISH_LEN];
	_mav_put_int32_t(buf, 0, mission_id);
	_mav_put_int32_t(buf, 4, waypoint_id);
	_mav_put_int32_t(buf, 8, waypoint_type);
	_mav_put_int32_t(buf, 12, lattitude);
	_mav_put_int32_t(buf, 16, longitude);
	_mav_put_int32_t(buf, 20, altitude);
	_mav_put_float(buf, 24, speed);
	_mav_put_int32_t(buf, 28, param1);
	_mav_put_int32_t(buf, 32, param2);
	_mav_put_int32_t(buf, 36, param3);
	_mav_put_int32_t(buf, 40, param4);
	_mav_put_int32_t(buf, 44, param5);
	_mav_put_int32_t(buf, 48, param6);
	_mav_put_int32_t(buf, 52, param7);
	_mav_put_int32_t(buf, 56, altitude_priority);
	_mav_put_int32_t(buf, 60, heading_mode);
	_mav_put_int32_t(buf, 64, user_defined_heading);
	_mav_put_int32_t(buf, 68, camera_yaw);
	_mav_put_int32_t(buf, 72, camera_pitch);
	_mav_put_int32_t(buf, 76, number_actions);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_WAYPOINT_INFO_FOR_DRAGFISH_LEN);
#else
	alink_waypoint_info_for_dragfish_t packet;
	packet.mission_id = mission_id;
	packet.waypoint_id = waypoint_id;
	packet.waypoint_type = waypoint_type;
	packet.lattitude = lattitude;
	packet.longitude = longitude;
	packet.altitude = altitude;
	packet.speed = speed;
	packet.param1 = param1;
	packet.param2 = param2;
	packet.param3 = param3;
	packet.param4 = param4;
	packet.param5 = param5;
	packet.param6 = param6;
	packet.param7 = param7;
	packet.altitude_priority = altitude_priority;
	packet.heading_mode = heading_mode;
	packet.user_defined_heading = user_defined_heading;
	packet.camera_yaw = camera_yaw;
	packet.camera_pitch = camera_pitch;
	packet.number_actions = number_actions;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_WAYPOINT_INFO_FOR_DRAGFISH_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_WAYPOINT_INFO_FOR_DRAGFISH;
#if ALINK_CRC_EXTRA
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_WAYPOINT_INFO_FOR_DRAGFISH_LEN,ALINK_MSG_ID_WAYPOINT_INFO_FOR_DRAGFISH_CRC);
#else
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_WAYPOINT_INFO_FOR_DRAGFISH_LEN);
#endif
}
/**
 * @brief Encode a waypoint_info_for_dragfish struct
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 * @param waypoint_info_for_dragfish C-struct to read the message contents from
 */
static inline uint16_t alink_msg_waypoint_info_for_dragfish_encode(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg, const alink_waypoint_info_for_dragfish_t* waypoint_info_for_dragfish)
{
	return alink_msg_waypoint_info_for_dragfish_pack(dest_id, source_id, msg, waypoint_info_for_dragfish->mission_id, waypoint_info_for_dragfish->waypoint_id, waypoint_info_for_dragfish->waypoint_type, waypoint_info_for_dragfish->lattitude, waypoint_info_for_dragfish->longitude, waypoint_info_for_dragfish->altitude, waypoint_info_for_dragfish->speed, waypoint_info_for_dragfish->param1, waypoint_info_for_dragfish->param2, waypoint_info_for_dragfish->param3, waypoint_info_for_dragfish->param4, waypoint_info_for_dragfish->param5, waypoint_info_for_dragfish->param6, waypoint_info_for_dragfish->param7, waypoint_info_for_dragfish->altitude_priority, waypoint_info_for_dragfish->heading_mode, waypoint_info_for_dragfish->user_defined_heading, waypoint_info_for_dragfish->camera_yaw, waypoint_info_for_dragfish->camera_pitch, waypoint_info_for_dragfish->number_actions);
}

/**
 * @brief Encode a waypoint_info_for_dragfish struct on a channel
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param waypoint_info_for_dragfish C-struct to read the message contents from
 */
static inline uint16_t alink_msg_waypoint_info_for_dragfish_encode_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan, alink_message_head_t* msg, const alink_waypoint_info_for_dragfish_t* waypoint_info_for_dragfish)
{
	return alink_msg_waypoint_info_for_dragfish_pack_chan(dest_id, source_id, chan, msg, waypoint_info_for_dragfish->mission_id, waypoint_info_for_dragfish->waypoint_id, waypoint_info_for_dragfish->waypoint_type, waypoint_info_for_dragfish->lattitude, waypoint_info_for_dragfish->longitude, waypoint_info_for_dragfish->altitude, waypoint_info_for_dragfish->speed, waypoint_info_for_dragfish->param1, waypoint_info_for_dragfish->param2, waypoint_info_for_dragfish->param3, waypoint_info_for_dragfish->param4, waypoint_info_for_dragfish->param5, waypoint_info_for_dragfish->param6, waypoint_info_for_dragfish->param7, waypoint_info_for_dragfish->altitude_priority, waypoint_info_for_dragfish->heading_mode, waypoint_info_for_dragfish->user_defined_heading, waypoint_info_for_dragfish->camera_yaw, waypoint_info_for_dragfish->camera_pitch, waypoint_info_for_dragfish->number_actions);
}
// MESSAGE WAYPOINT_INFO_FOR_DRAGFISH UNPACKING


/**
 * @brief Get field mission_id from waypoint_info_for_dragfish message
 *
 * @return mission id
 */
static inline int32_t alink_msg_waypoint_info_for_dragfish_get_mission_id(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  0);
}

/**
 * @brief Get field waypoint_id from waypoint_info_for_dragfish message
 *
 * @return waypoint id
 */
static inline int32_t alink_msg_waypoint_info_for_dragfish_get_waypoint_id(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  4);
}

/**
 * @brief Get field waypoint_type from waypoint_info_for_dragfish message
 *
 * @return  0-Normal 1-Orbit 2-Cylinder 3-Panorama 4-TakeOff 5-LoiterTime 6-LoiterTurns 7-Landing 8-Interest 9-Mapping 10-Emergency 11-homepoint
 */
static inline int32_t alink_msg_waypoint_info_for_dragfish_get_waypoint_type(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  8);
}

/**
 * @brief Get field lattitude from waypoint_info_for_dragfish message
 *
 * @return lattitude of waypoint in 10E-7 degree
 */
static inline int32_t alink_msg_waypoint_info_for_dragfish_get_lattitude(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  12);
}

/**
 * @brief Get field longitude from waypoint_info_for_dragfish message
 *
 * @return longitude of waypoint in 10E-7 degree
 */
static inline int32_t alink_msg_waypoint_info_for_dragfish_get_longitude(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  16);
}

/**
 * @brief Get field altitude from waypoint_info_for_dragfish message
 *
 * @return altitude of waypoint in mm
 */
static inline int32_t alink_msg_waypoint_info_for_dragfish_get_altitude(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  20);
}

/**
 * @brief Get field speed from waypoint_info_for_dragfish message
 *
 * @return speed in m/s
 */
static inline float alink_msg_waypoint_info_for_dragfish_get_speed(const alink_message_head_t* msg)
{
	return _MAV_RETURN_float(msg,  24);
}

/**
 * @brief Get field param1 from waypoint_info_for_dragfish message
 *
 * @return param1
 */
static inline int32_t alink_msg_waypoint_info_for_dragfish_get_param1(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  28);
}

/**
 * @brief Get field param2 from waypoint_info_for_dragfish message
 *
 * @return param2
 */
static inline int32_t alink_msg_waypoint_info_for_dragfish_get_param2(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  32);
}

/**
 * @brief Get field param3 from waypoint_info_for_dragfish message
 *
 * @return param3
 */
static inline int32_t alink_msg_waypoint_info_for_dragfish_get_param3(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  36);
}

/**
 * @brief Get field param4 from waypoint_info_for_dragfish message
 *
 * @return param4
 */
static inline int32_t alink_msg_waypoint_info_for_dragfish_get_param4(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  40);
}

/**
 * @brief Get field param5 from waypoint_info_for_dragfish message
 *
 * @return param5
 */
static inline int32_t alink_msg_waypoint_info_for_dragfish_get_param5(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  44);
}

/**
 * @brief Get field param6 from waypoint_info_for_dragfish message
 *
 * @return param6
 */
static inline int32_t alink_msg_waypoint_info_for_dragfish_get_param6(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  48);
}

/**
 * @brief Get field param7 from waypoint_info_for_dragfish message
 *
 * @return param7
 */
static inline int32_t alink_msg_waypoint_info_for_dragfish_get_param7(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  52);
}

/**
 * @brief Get field altitude_priority from waypoint_info_for_dragfish message
 *
 * @return  0 - elevate as approach , 1 - elevate first then approach 
 */
static inline int32_t alink_msg_waypoint_info_for_dragfish_get_altitude_priority(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  56);
}

/**
 * @brief Get field heading_mode from waypoint_info_for_dragfish message
 *
 * @return  0 - invalid, 1 - next waypoint, 2 - initial , 3 - user defined
 */
static inline int32_t alink_msg_waypoint_info_for_dragfish_get_heading_mode(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  60);
}

/**
 * @brief Get field user_defined_heading from waypoint_info_for_dragfish message
 *
 * @return  N/E/D estimated velocity in 10E-3 m/s
 */
static inline int32_t alink_msg_waypoint_info_for_dragfish_get_user_defined_heading(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  64);
}

/**
 * @brief Get field camera_yaw from waypoint_info_for_dragfish message
 *
 * @return  yaw of camera/gimbal
 */
static inline int32_t alink_msg_waypoint_info_for_dragfish_get_camera_yaw(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  68);
}

/**
 * @brief Get field camera_pitch from waypoint_info_for_dragfish message
 *
 * @return   pitch of camera/gimbal 
 */
static inline int32_t alink_msg_waypoint_info_for_dragfish_get_camera_pitch(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  72);
}

/**
 * @brief Get field number_actions from waypoint_info_for_dragfish message
 *
 * @return  number of actions belong to this waypoint 
 */
static inline int32_t alink_msg_waypoint_info_for_dragfish_get_number_actions(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  76);
}

/**
 * @brief Decode a waypoint_info_for_dragfish message into a struct
 *
 * @param msg The message to decode
 * @param waypoint_info_for_dragfish C-struct to decode the message contents into
 */
static inline void alink_msg_waypoint_info_for_dragfish_decode(const alink_message_head_t* msg, alink_waypoint_info_for_dragfish_t* waypoint_info_for_dragfish)
{
#if ALINK_NEED_BYTE_SWAP
	waypoint_info_for_dragfish->mission_id = alink_msg_waypoint_info_for_dragfish_get_mission_id(msg);
	waypoint_info_for_dragfish->waypoint_id = alink_msg_waypoint_info_for_dragfish_get_waypoint_id(msg);
	waypoint_info_for_dragfish->waypoint_type = alink_msg_waypoint_info_for_dragfish_get_waypoint_type(msg);
	waypoint_info_for_dragfish->lattitude = alink_msg_waypoint_info_for_dragfish_get_lattitude(msg);
	waypoint_info_for_dragfish->longitude = alink_msg_waypoint_info_for_dragfish_get_longitude(msg);
	waypoint_info_for_dragfish->altitude = alink_msg_waypoint_info_for_dragfish_get_altitude(msg);
	waypoint_info_for_dragfish->speed = alink_msg_waypoint_info_for_dragfish_get_speed(msg);
	waypoint_info_for_dragfish->param1 = alink_msg_waypoint_info_for_dragfish_get_param1(msg);
	waypoint_info_for_dragfish->param2 = alink_msg_waypoint_info_for_dragfish_get_param2(msg);
	waypoint_info_for_dragfish->param3 = alink_msg_waypoint_info_for_dragfish_get_param3(msg);
	waypoint_info_for_dragfish->param4 = alink_msg_waypoint_info_for_dragfish_get_param4(msg);
	waypoint_info_for_dragfish->param5 = alink_msg_waypoint_info_for_dragfish_get_param5(msg);
	waypoint_info_for_dragfish->param6 = alink_msg_waypoint_info_for_dragfish_get_param6(msg);
	waypoint_info_for_dragfish->param7 = alink_msg_waypoint_info_for_dragfish_get_param7(msg);
	waypoint_info_for_dragfish->altitude_priority = alink_msg_waypoint_info_for_dragfish_get_altitude_priority(msg);
	waypoint_info_for_dragfish->heading_mode = alink_msg_waypoint_info_for_dragfish_get_heading_mode(msg);
	waypoint_info_for_dragfish->user_defined_heading = alink_msg_waypoint_info_for_dragfish_get_user_defined_heading(msg);
	waypoint_info_for_dragfish->camera_yaw = alink_msg_waypoint_info_for_dragfish_get_camera_yaw(msg);
	waypoint_info_for_dragfish->camera_pitch = alink_msg_waypoint_info_for_dragfish_get_camera_pitch(msg);
	waypoint_info_for_dragfish->number_actions = alink_msg_waypoint_info_for_dragfish_get_number_actions(msg);
#else
	memcpy(waypoint_info_for_dragfish, _MAV_PAYLOAD(msg), ALINK_MSG_ID_WAYPOINT_INFO_FOR_DRAGFISH_LEN);
#endif
}
