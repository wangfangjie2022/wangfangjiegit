// MESSAGE MISSION_INFO_FOR_DRAGFISH PACKING

#define ALINK_MSG_ID_MISSION_INFO_FOR_DRAGFISH 90

typedef struct __alink_mission_info_for_dragfish_t
{
 int32_t mission_id; /*< mission id*/
 int32_t mission_type; /*< 0-None 1-Waypoint 2-Orbit 3-Cylinder 4-Panorama 5-GPS Follow 6-Mapping*/
 int32_t number_waypoints; /*< waypoints number*/
 int32_t finish_action; /*<  0 - invalid, 1 - pend, 2 - RTH, 3 - Landing 4 - Return to 1st waypoint, 5 - pend and selectable */
 int32_t obstacle_avoidance_mode; /*<  0 - invalid, 1 - hover, 2 - left/right first, 3 - Climb first */
 int32_t obstacle_avoidance_timeout; /*< seconds before take next action*/
 int32_t lost_control_action; /*< 0 - invalid, 1 - RTH, 2 - go on till fuel's up */
 int32_t geography_follow; /*< 0 - no geography follow, 1 - geography follow*/
 int32_t max_altitude; /*< max altitude */
 int32_t min_altitude; /*< min altitude*/
} alink_mission_info_for_dragfish_t;

#define ALINK_MSG_ID_MISSION_INFO_FOR_DRAGFISH_LEN 40
#define ALINK_MSG_ID_90_LEN 40

#define ALINK_MSG_ID_MISSION_INFO_FOR_DRAGFISH_CRC 136
#define ALINK_MSG_ID_90_CRC 136



#define ALINK_MESSAGE_INFO_MISSION_INFO_FOR_DRAGFISH { \
	"MISSION_INFO_FOR_DRAGFISH", \
	10, \
	{  { "mission_id", NULL, ALINK_TYPE_INT32_T, 0, 0, offsetof(alink_mission_info_for_dragfish_t, mission_id) }, \
         { "mission_type", NULL, ALINK_TYPE_INT32_T, 0, 4, offsetof(alink_mission_info_for_dragfish_t, mission_type) }, \
         { "number_waypoints", NULL, ALINK_TYPE_INT32_T, 0, 8, offsetof(alink_mission_info_for_dragfish_t, number_waypoints) }, \
         { "finish_action", NULL, ALINK_TYPE_INT32_T, 0, 12, offsetof(alink_mission_info_for_dragfish_t, finish_action) }, \
         { "obstacle_avoidance_mode", NULL, ALINK_TYPE_INT32_T, 0, 16, offsetof(alink_mission_info_for_dragfish_t, obstacle_avoidance_mode) }, \
         { "obstacle_avoidance_timeout", NULL, ALINK_TYPE_INT32_T, 0, 20, offsetof(alink_mission_info_for_dragfish_t, obstacle_avoidance_timeout) }, \
         { "lost_control_action", NULL, ALINK_TYPE_INT32_T, 0, 24, offsetof(alink_mission_info_for_dragfish_t, lost_control_action) }, \
         { "geography_follow", NULL, ALINK_TYPE_INT32_T, 0, 28, offsetof(alink_mission_info_for_dragfish_t, geography_follow) }, \
         { "max_altitude", NULL, ALINK_TYPE_INT32_T, 0, 32, offsetof(alink_mission_info_for_dragfish_t, max_altitude) }, \
         { "min_altitude", NULL, ALINK_TYPE_INT32_T, 0, 36, offsetof(alink_mission_info_for_dragfish_t, min_altitude) }, \
         } \
}


/**
 * @brief Pack a mission_info_for_dragfish message
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 *
 * @param mission_id mission id
 * @param mission_type 0-None 1-Waypoint 2-Orbit 3-Cylinder 4-Panorama 5-GPS Follow 6-Mapping
 * @param number_waypoints waypoints number
 * @param finish_action  0 - invalid, 1 - pend, 2 - RTH, 3 - Landing 4 - Return to 1st waypoint, 5 - pend and selectable 
 * @param obstacle_avoidance_mode  0 - invalid, 1 - hover, 2 - left/right first, 3 - Climb first 
 * @param obstacle_avoidance_timeout seconds before take next action
 * @param lost_control_action 0 - invalid, 1 - RTH, 2 - go on till fuel's up 
 * @param geography_follow 0 - no geography follow, 1 - geography follow
 * @param max_altitude max altitude 
 * @param min_altitude min altitude
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_mission_info_for_dragfish_pack(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg,
						       int32_t mission_id, int32_t mission_type, int32_t number_waypoints, int32_t finish_action, int32_t obstacle_avoidance_mode, int32_t obstacle_avoidance_timeout, int32_t lost_control_action, int32_t geography_follow, int32_t max_altitude, int32_t min_altitude)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_MISSION_INFO_FOR_DRAGFISH_LEN];
	_mav_put_int32_t(buf, 0, mission_id);
	_mav_put_int32_t(buf, 4, mission_type);
	_mav_put_int32_t(buf, 8, number_waypoints);
	_mav_put_int32_t(buf, 12, finish_action);
	_mav_put_int32_t(buf, 16, obstacle_avoidance_mode);
	_mav_put_int32_t(buf, 20, obstacle_avoidance_timeout);
	_mav_put_int32_t(buf, 24, lost_control_action);
	_mav_put_int32_t(buf, 28, geography_follow);
	_mav_put_int32_t(buf, 32, max_altitude);
	_mav_put_int32_t(buf, 36, min_altitude);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_MISSION_INFO_FOR_DRAGFISH_LEN);
#else
	alink_mission_info_for_dragfish_t packet;
	packet.mission_id = mission_id;
	packet.mission_type = mission_type;
	packet.number_waypoints = number_waypoints;
	packet.finish_action = finish_action;
	packet.obstacle_avoidance_mode = obstacle_avoidance_mode;
	packet.obstacle_avoidance_timeout = obstacle_avoidance_timeout;
	packet.lost_control_action = lost_control_action;
	packet.geography_follow = geography_follow;
	packet.max_altitude = max_altitude;
	packet.min_altitude = min_altitude;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_MISSION_INFO_FOR_DRAGFISH_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_MISSION_INFO_FOR_DRAGFISH;
#if ALINK_CRC_EXTRA
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_MISSION_INFO_FOR_DRAGFISH_LEN,ALINK_MSG_ID_MISSION_INFO_FOR_DRAGFISH_CRC);
#else
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_MISSION_INFO_FOR_DRAGFISH_LEN);
#endif
}

/**
 * @brief Pack a mission_info_for_dragfish message on a channel
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param mission_id mission id
 * @param mission_type 0-None 1-Waypoint 2-Orbit 3-Cylinder 4-Panorama 5-GPS Follow 6-Mapping
 * @param number_waypoints waypoints number
 * @param finish_action  0 - invalid, 1 - pend, 2 - RTH, 3 - Landing 4 - Return to 1st waypoint, 5 - pend and selectable 
 * @param obstacle_avoidance_mode  0 - invalid, 1 - hover, 2 - left/right first, 3 - Climb first 
 * @param obstacle_avoidance_timeout seconds before take next action
 * @param lost_control_action 0 - invalid, 1 - RTH, 2 - go on till fuel's up 
 * @param geography_follow 0 - no geography follow, 1 - geography follow
 * @param max_altitude max altitude 
 * @param min_altitude min altitude
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_mission_info_for_dragfish_pack_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan,
							   alink_message_head_t* msg,
						           int32_t mission_id,int32_t mission_type,int32_t number_waypoints,int32_t finish_action,int32_t obstacle_avoidance_mode,int32_t obstacle_avoidance_timeout,int32_t lost_control_action,int32_t geography_follow,int32_t max_altitude,int32_t min_altitude)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_MISSION_INFO_FOR_DRAGFISH_LEN];
	_mav_put_int32_t(buf, 0, mission_id);
	_mav_put_int32_t(buf, 4, mission_type);
	_mav_put_int32_t(buf, 8, number_waypoints);
	_mav_put_int32_t(buf, 12, finish_action);
	_mav_put_int32_t(buf, 16, obstacle_avoidance_mode);
	_mav_put_int32_t(buf, 20, obstacle_avoidance_timeout);
	_mav_put_int32_t(buf, 24, lost_control_action);
	_mav_put_int32_t(buf, 28, geography_follow);
	_mav_put_int32_t(buf, 32, max_altitude);
	_mav_put_int32_t(buf, 36, min_altitude);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_MISSION_INFO_FOR_DRAGFISH_LEN);
#else
	alink_mission_info_for_dragfish_t packet;
	packet.mission_id = mission_id;
	packet.mission_type = mission_type;
	packet.number_waypoints = number_waypoints;
	packet.finish_action = finish_action;
	packet.obstacle_avoidance_mode = obstacle_avoidance_mode;
	packet.obstacle_avoidance_timeout = obstacle_avoidance_timeout;
	packet.lost_control_action = lost_control_action;
	packet.geography_follow = geography_follow;
	packet.max_altitude = max_altitude;
	packet.min_altitude = min_altitude;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_MISSION_INFO_FOR_DRAGFISH_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_MISSION_INFO_FOR_DRAGFISH;
#if ALINK_CRC_EXTRA
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_MISSION_INFO_FOR_DRAGFISH_LEN,ALINK_MSG_ID_MISSION_INFO_FOR_DRAGFISH_CRC);
#else
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_MISSION_INFO_FOR_DRAGFISH_LEN);
#endif
}
/**
 * @brief Encode a mission_info_for_dragfish struct
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 * @param mission_info_for_dragfish C-struct to read the message contents from
 */
static inline uint16_t alink_msg_mission_info_for_dragfish_encode(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg, const alink_mission_info_for_dragfish_t* mission_info_for_dragfish)
{
	return alink_msg_mission_info_for_dragfish_pack(dest_id, source_id, msg, mission_info_for_dragfish->mission_id, mission_info_for_dragfish->mission_type, mission_info_for_dragfish->number_waypoints, mission_info_for_dragfish->finish_action, mission_info_for_dragfish->obstacle_avoidance_mode, mission_info_for_dragfish->obstacle_avoidance_timeout, mission_info_for_dragfish->lost_control_action, mission_info_for_dragfish->geography_follow, mission_info_for_dragfish->max_altitude, mission_info_for_dragfish->min_altitude);
}

/**
 * @brief Encode a mission_info_for_dragfish struct on a channel
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param mission_info_for_dragfish C-struct to read the message contents from
 */
static inline uint16_t alink_msg_mission_info_for_dragfish_encode_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan, alink_message_head_t* msg, const alink_mission_info_for_dragfish_t* mission_info_for_dragfish)
{
	return alink_msg_mission_info_for_dragfish_pack_chan(dest_id, source_id, chan, msg, mission_info_for_dragfish->mission_id, mission_info_for_dragfish->mission_type, mission_info_for_dragfish->number_waypoints, mission_info_for_dragfish->finish_action, mission_info_for_dragfish->obstacle_avoidance_mode, mission_info_for_dragfish->obstacle_avoidance_timeout, mission_info_for_dragfish->lost_control_action, mission_info_for_dragfish->geography_follow, mission_info_for_dragfish->max_altitude, mission_info_for_dragfish->min_altitude);
}
// MESSAGE MISSION_INFO_FOR_DRAGFISH UNPACKING


/**
 * @brief Get field mission_id from mission_info_for_dragfish message
 *
 * @return mission id
 */
static inline int32_t alink_msg_mission_info_for_dragfish_get_mission_id(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  0);
}

/**
 * @brief Get field mission_type from mission_info_for_dragfish message
 *
 * @return 0-None 1-Waypoint 2-Orbit 3-Cylinder 4-Panorama 5-GPS Follow 6-Mapping
 */
static inline int32_t alink_msg_mission_info_for_dragfish_get_mission_type(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  4);
}

/**
 * @brief Get field number_waypoints from mission_info_for_dragfish message
 *
 * @return waypoints number
 */
static inline int32_t alink_msg_mission_info_for_dragfish_get_number_waypoints(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  8);
}

/**
 * @brief Get field finish_action from mission_info_for_dragfish message
 *
 * @return  0 - invalid, 1 - pend, 2 - RTH, 3 - Landing 4 - Return to 1st waypoint, 5 - pend and selectable 
 */
static inline int32_t alink_msg_mission_info_for_dragfish_get_finish_action(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  12);
}

/**
 * @brief Get field obstacle_avoidance_mode from mission_info_for_dragfish message
 *
 * @return  0 - invalid, 1 - hover, 2 - left/right first, 3 - Climb first 
 */
static inline int32_t alink_msg_mission_info_for_dragfish_get_obstacle_avoidance_mode(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  16);
}

/**
 * @brief Get field obstacle_avoidance_timeout from mission_info_for_dragfish message
 *
 * @return seconds before take next action
 */
static inline int32_t alink_msg_mission_info_for_dragfish_get_obstacle_avoidance_timeout(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  20);
}

/**
 * @brief Get field lost_control_action from mission_info_for_dragfish message
 *
 * @return 0 - invalid, 1 - RTH, 2 - go on till fuel's up 
 */
static inline int32_t alink_msg_mission_info_for_dragfish_get_lost_control_action(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  24);
}

/**
 * @brief Get field geography_follow from mission_info_for_dragfish message
 *
 * @return 0 - no geography follow, 1 - geography follow
 */
static inline int32_t alink_msg_mission_info_for_dragfish_get_geography_follow(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  28);
}

/**
 * @brief Get field max_altitude from mission_info_for_dragfish message
 *
 * @return max altitude 
 */
static inline int32_t alink_msg_mission_info_for_dragfish_get_max_altitude(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  32);
}

/**
 * @brief Get field min_altitude from mission_info_for_dragfish message
 *
 * @return min altitude
 */
static inline int32_t alink_msg_mission_info_for_dragfish_get_min_altitude(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  36);
}

/**
 * @brief Decode a mission_info_for_dragfish message into a struct
 *
 * @param msg The message to decode
 * @param mission_info_for_dragfish C-struct to decode the message contents into
 */
static inline void alink_msg_mission_info_for_dragfish_decode(const alink_message_head_t* msg, alink_mission_info_for_dragfish_t* mission_info_for_dragfish)
{
#if ALINK_NEED_BYTE_SWAP
	mission_info_for_dragfish->mission_id = alink_msg_mission_info_for_dragfish_get_mission_id(msg);
	mission_info_for_dragfish->mission_type = alink_msg_mission_info_for_dragfish_get_mission_type(msg);
	mission_info_for_dragfish->number_waypoints = alink_msg_mission_info_for_dragfish_get_number_waypoints(msg);
	mission_info_for_dragfish->finish_action = alink_msg_mission_info_for_dragfish_get_finish_action(msg);
	mission_info_for_dragfish->obstacle_avoidance_mode = alink_msg_mission_info_for_dragfish_get_obstacle_avoidance_mode(msg);
	mission_info_for_dragfish->obstacle_avoidance_timeout = alink_msg_mission_info_for_dragfish_get_obstacle_avoidance_timeout(msg);
	mission_info_for_dragfish->lost_control_action = alink_msg_mission_info_for_dragfish_get_lost_control_action(msg);
	mission_info_for_dragfish->geography_follow = alink_msg_mission_info_for_dragfish_get_geography_follow(msg);
	mission_info_for_dragfish->max_altitude = alink_msg_mission_info_for_dragfish_get_max_altitude(msg);
	mission_info_for_dragfish->min_altitude = alink_msg_mission_info_for_dragfish_get_min_altitude(msg);
#else
	memcpy(mission_info_for_dragfish, _MAV_PAYLOAD(msg), ALINK_MSG_ID_MISSION_INFO_FOR_DRAGFISH_LEN);
#endif
}
