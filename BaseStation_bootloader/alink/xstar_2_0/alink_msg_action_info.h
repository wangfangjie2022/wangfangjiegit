// MESSAGE ACTION_INFO PACKING

#define ALINK_MSG_ID_ACTION_INFO 82

typedef struct __alink_action_info_t
{
 int32_t mission_id; /*< mission id*/
 int32_t waypoint_id; /*< waypoint id*/
 int32_t action_id; /*< action id*/
 int32_t action_type; /*<  0 - invalid, 1 - capture, 2 - RecordStart, 3 - RecordStop, 4 - Pause, 5 - RTH, 6 - Land then takeoff*/
 int32_t action_timeout; /*< Timeout of this action*/
 int32_t action_params[7]; /*< parameters of this action*/
} alink_action_info_t;

#define ALINK_MSG_ID_ACTION_INFO_LEN 48
#define ALINK_MSG_ID_82_LEN 48

#define ALINK_MSG_ID_ACTION_INFO_CRC 233
#define ALINK_MSG_ID_82_CRC 233

#define ALINK_MSG_ACTION_INFO_FIELD_ACTION_PARAMS_LEN 7

#define ALINK_MESSAGE_INFO_ACTION_INFO { \
	"ACTION_INFO", \
	6, \
	{  { "mission_id", NULL, ALINK_TYPE_INT32_T, 0, 0, offsetof(alink_action_info_t, mission_id) }, \
         { "waypoint_id", NULL, ALINK_TYPE_INT32_T, 0, 4, offsetof(alink_action_info_t, waypoint_id) }, \
         { "action_id", NULL, ALINK_TYPE_INT32_T, 0, 8, offsetof(alink_action_info_t, action_id) }, \
         { "action_type", NULL, ALINK_TYPE_INT32_T, 0, 12, offsetof(alink_action_info_t, action_type) }, \
         { "action_timeout", NULL, ALINK_TYPE_INT32_T, 0, 16, offsetof(alink_action_info_t, action_timeout) }, \
         { "action_params", NULL, ALINK_TYPE_INT32_T, 7, 20, offsetof(alink_action_info_t, action_params) }, \
         } \
}


/**
 * @brief Pack a action_info message
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 *
 * @param mission_id mission id
 * @param waypoint_id waypoint id
 * @param action_id action id
 * @param action_type  0 - invalid, 1 - capture, 2 - RecordStart, 3 - RecordStop, 4 - Pause, 5 - RTH, 6 - Land then takeoff
 * @param action_timeout Timeout of this action
 * @param action_params parameters of this action
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_action_info_pack(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg,
						       int32_t mission_id, int32_t waypoint_id, int32_t action_id, int32_t action_type, int32_t action_timeout, const int32_t *action_params)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_ACTION_INFO_LEN];
	_mav_put_int32_t(buf, 0, mission_id);
	_mav_put_int32_t(buf, 4, waypoint_id);
	_mav_put_int32_t(buf, 8, action_id);
	_mav_put_int32_t(buf, 12, action_type);
	_mav_put_int32_t(buf, 16, action_timeout);
	_mav_put_int32_t_array(buf, 20, action_params, 7);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_ACTION_INFO_LEN);
#else
	alink_action_info_t packet;
	packet.mission_id = mission_id;
	packet.waypoint_id = waypoint_id;
	packet.action_id = action_id;
	packet.action_type = action_type;
	packet.action_timeout = action_timeout;
	mav_array_memcpy(packet.action_params, action_params, sizeof(int32_t)*7);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_ACTION_INFO_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_ACTION_INFO;
#if ALINK_CRC_EXTRA
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_ACTION_INFO_LEN,ALINK_MSG_ID_ACTION_INFO_CRC);
#else
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_ACTION_INFO_LEN);
#endif
}

/**
 * @brief Pack a action_info message on a channel
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param mission_id mission id
 * @param waypoint_id waypoint id
 * @param action_id action id
 * @param action_type  0 - invalid, 1 - capture, 2 - RecordStart, 3 - RecordStop, 4 - Pause, 5 - RTH, 6 - Land then takeoff
 * @param action_timeout Timeout of this action
 * @param action_params parameters of this action
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_action_info_pack_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan,
							   alink_message_head_t* msg,
						           int32_t mission_id,int32_t waypoint_id,int32_t action_id,int32_t action_type,int32_t action_timeout,const int32_t *action_params)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_ACTION_INFO_LEN];
	_mav_put_int32_t(buf, 0, mission_id);
	_mav_put_int32_t(buf, 4, waypoint_id);
	_mav_put_int32_t(buf, 8, action_id);
	_mav_put_int32_t(buf, 12, action_type);
	_mav_put_int32_t(buf, 16, action_timeout);
	_mav_put_int32_t_array(buf, 20, action_params, 7);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_ACTION_INFO_LEN);
#else
	alink_action_info_t packet;
	packet.mission_id = mission_id;
	packet.waypoint_id = waypoint_id;
	packet.action_id = action_id;
	packet.action_type = action_type;
	packet.action_timeout = action_timeout;
	mav_array_memcpy(packet.action_params, action_params, sizeof(int32_t)*7);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_ACTION_INFO_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_ACTION_INFO;
#if ALINK_CRC_EXTRA
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_ACTION_INFO_LEN,ALINK_MSG_ID_ACTION_INFO_CRC);
#else
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_ACTION_INFO_LEN);
#endif
}
/**
 * @brief Encode a action_info struct
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 * @param action_info C-struct to read the message contents from
 */
static inline uint16_t alink_msg_action_info_encode(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg, const alink_action_info_t* action_info)
{
	return alink_msg_action_info_pack(dest_id, source_id, msg, action_info->mission_id, action_info->waypoint_id, action_info->action_id, action_info->action_type, action_info->action_timeout, action_info->action_params);
}

/**
 * @brief Encode a action_info struct on a channel
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param action_info C-struct to read the message contents from
 */
static inline uint16_t alink_msg_action_info_encode_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan, alink_message_head_t* msg, const alink_action_info_t* action_info)
{
	return alink_msg_action_info_pack_chan(dest_id, source_id, chan, msg, action_info->mission_id, action_info->waypoint_id, action_info->action_id, action_info->action_type, action_info->action_timeout, action_info->action_params);
}
// MESSAGE ACTION_INFO UNPACKING


/**
 * @brief Get field mission_id from action_info message
 *
 * @return mission id
 */
static inline int32_t alink_msg_action_info_get_mission_id(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  0);
}

/**
 * @brief Get field waypoint_id from action_info message
 *
 * @return waypoint id
 */
static inline int32_t alink_msg_action_info_get_waypoint_id(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  4);
}

/**
 * @brief Get field action_id from action_info message
 *
 * @return action id
 */
static inline int32_t alink_msg_action_info_get_action_id(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  8);
}

/**
 * @brief Get field action_type from action_info message
 *
 * @return  0 - invalid, 1 - capture, 2 - RecordStart, 3 - RecordStop, 4 - Pause, 5 - RTH, 6 - Land then takeoff
 */
static inline int32_t alink_msg_action_info_get_action_type(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  12);
}

/**
 * @brief Get field action_timeout from action_info message
 *
 * @return Timeout of this action
 */
static inline int32_t alink_msg_action_info_get_action_timeout(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  16);
}

/**
 * @brief Get field action_params from action_info message
 *
 * @return parameters of this action
 */
static inline uint16_t alink_msg_action_info_get_action_params(const alink_message_head_t* msg, int32_t *action_params)
{
	return _MAV_RETURN_int32_t_array(msg, action_params, 7,  20);
}

/**
 * @brief Decode a action_info message into a struct
 *
 * @param msg The message to decode
 * @param action_info C-struct to decode the message contents into
 */
static inline void alink_msg_action_info_decode(const alink_message_head_t* msg, alink_action_info_t* action_info)
{
#if ALINK_NEED_BYTE_SWAP
	action_info->mission_id = alink_msg_action_info_get_mission_id(msg);
	action_info->waypoint_id = alink_msg_action_info_get_waypoint_id(msg);
	action_info->action_id = alink_msg_action_info_get_action_id(msg);
	action_info->action_type = alink_msg_action_info_get_action_type(msg);
	action_info->action_timeout = alink_msg_action_info_get_action_timeout(msg);
	alink_msg_action_info_get_action_params(msg, action_info->action_params);
#else
	memcpy(action_info, _MAV_PAYLOAD(msg), ALINK_MSG_ID_ACTION_INFO_LEN);
#endif
}
