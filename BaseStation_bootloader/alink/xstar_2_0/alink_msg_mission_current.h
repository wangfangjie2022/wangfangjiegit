// MESSAGE MISSION_CURRENT PACKING

#define ALINK_MSG_ID_MISSION_CURRENT 42

typedef struct __alink_mission_current_t
{
 uint32_t timestamp; /*< timestamp (milliseconds since system boot)*/
 uint32_t mission_id; /*< current mission id*/
 uint32_t remain_length; /*< mission remain length*/
 uint32_t remain_time; /*<  mission remain time*/
 uint32_t path_seq; /*< little way point seq*/
 uint32_t photo_sum; /*< the sum of photos in this flight*/
 int16_t speed_set; /*< way point speed set,in 1e-3 m/s*/
 uint8_t wp_seq; /*< way point seq*/
 uint8_t arrived; /*< way point arrived or not; 0: not; 1:arrived*/
 uint8_t directting; /*< directting next wp or not; 0: not; 1:yes*/
 uint8_t status; /*< way point status. 0:pause; 1:running; 2:completed; other:as defiens latter*/
 uint8_t action_seq; /*< action seq*/
 uint8_t fly_circle; /*< fly circle*/
} alink_mission_current_t;

#define ALINK_MSG_ID_MISSION_CURRENT_LEN 32
#define ALINK_MSG_ID_42_LEN 32

#define ALINK_MSG_ID_MISSION_CURRENT_CRC 33
#define ALINK_MSG_ID_42_CRC 33



#define ALINK_MESSAGE_INFO_MISSION_CURRENT { \
	"MISSION_CURRENT", \
	13, \
	{  { "timestamp", NULL, ALINK_TYPE_UINT32_T, 0, 0, offsetof(alink_mission_current_t, timestamp) }, \
         { "mission_id", NULL, ALINK_TYPE_UINT32_T, 0, 4, offsetof(alink_mission_current_t, mission_id) }, \
         { "remain_length", NULL, ALINK_TYPE_UINT32_T, 0, 8, offsetof(alink_mission_current_t, remain_length) }, \
         { "remain_time", NULL, ALINK_TYPE_UINT32_T, 0, 12, offsetof(alink_mission_current_t, remain_time) }, \
         { "path_seq", NULL, ALINK_TYPE_UINT32_T, 0, 16, offsetof(alink_mission_current_t, path_seq) }, \
         { "photo_sum", NULL, ALINK_TYPE_UINT32_T, 0, 20, offsetof(alink_mission_current_t, photo_sum) }, \
         { "speed_set", NULL, ALINK_TYPE_INT16_T, 0, 24, offsetof(alink_mission_current_t, speed_set) }, \
         { "wp_seq", NULL, ALINK_TYPE_UINT8_T, 0, 26, offsetof(alink_mission_current_t, wp_seq) }, \
         { "arrived", NULL, ALINK_TYPE_UINT8_T, 0, 27, offsetof(alink_mission_current_t, arrived) }, \
         { "directting", NULL, ALINK_TYPE_UINT8_T, 0, 28, offsetof(alink_mission_current_t, directting) }, \
         { "status", NULL, ALINK_TYPE_UINT8_T, 0, 29, offsetof(alink_mission_current_t, status) }, \
         { "action_seq", NULL, ALINK_TYPE_UINT8_T, 0, 30, offsetof(alink_mission_current_t, action_seq) }, \
         { "fly_circle", NULL, ALINK_TYPE_UINT8_T, 0, 31, offsetof(alink_mission_current_t, fly_circle) }, \
         } \
}


/**
 * @brief Pack a mission_current message
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 *
 * @param timestamp timestamp (milliseconds since system boot)
 * @param mission_id current mission id
 * @param remain_length mission remain length
 * @param remain_time  mission remain time
 * @param path_seq little way point seq
 * @param photo_sum the sum of photos in this flight
 * @param wp_seq way point seq
 * @param arrived way point arrived or not; 0: not; 1:arrived
 * @param directting directting next wp or not; 0: not; 1:yes
 * @param status way point status. 0:pause; 1:running; 2:completed; other:as defiens latter
 * @param speed_set way point speed set,in 1e-3 m/s
 * @param action_seq action seq
 * @param fly_circle fly circle
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_mission_current_pack(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg,
						       uint32_t timestamp, uint32_t mission_id, uint32_t remain_length, uint32_t remain_time, uint32_t path_seq, uint32_t photo_sum, uint8_t wp_seq, uint8_t arrived, uint8_t directting, uint8_t status, int16_t speed_set, uint8_t action_seq, uint8_t fly_circle)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_MISSION_CURRENT_LEN];
	_mav_put_uint32_t(buf, 0, timestamp);
	_mav_put_uint32_t(buf, 4, mission_id);
	_mav_put_uint32_t(buf, 8, remain_length);
	_mav_put_uint32_t(buf, 12, remain_time);
	_mav_put_uint32_t(buf, 16, path_seq);
	_mav_put_uint32_t(buf, 20, photo_sum);
	_mav_put_int16_t(buf, 24, speed_set);
	_mav_put_uint8_t(buf, 26, wp_seq);
	_mav_put_uint8_t(buf, 27, arrived);
	_mav_put_uint8_t(buf, 28, directting);
	_mav_put_uint8_t(buf, 29, status);
	_mav_put_uint8_t(buf, 30, action_seq);
	_mav_put_uint8_t(buf, 31, fly_circle);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_MISSION_CURRENT_LEN);
#else
	alink_mission_current_t packet;
	packet.timestamp = timestamp;
	packet.mission_id = mission_id;
	packet.remain_length = remain_length;
	packet.remain_time = remain_time;
	packet.path_seq = path_seq;
	packet.photo_sum = photo_sum;
	packet.speed_set = speed_set;
	packet.wp_seq = wp_seq;
	packet.arrived = arrived;
	packet.directting = directting;
	packet.status = status;
	packet.action_seq = action_seq;
	packet.fly_circle = fly_circle;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_MISSION_CURRENT_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_MISSION_CURRENT;
#if ALINK_CRC_EXTRA
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_MISSION_CURRENT_LEN,ALINK_MSG_ID_MISSION_CURRENT_CRC);
#else
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_MISSION_CURRENT_LEN);
#endif
}

/**
 * @brief Pack a mission_current message on a channel
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param timestamp timestamp (milliseconds since system boot)
 * @param mission_id current mission id
 * @param remain_length mission remain length
 * @param remain_time  mission remain time
 * @param path_seq little way point seq
 * @param photo_sum the sum of photos in this flight
 * @param wp_seq way point seq
 * @param arrived way point arrived or not; 0: not; 1:arrived
 * @param directting directting next wp or not; 0: not; 1:yes
 * @param status way point status. 0:pause; 1:running; 2:completed; other:as defiens latter
 * @param speed_set way point speed set,in 1e-3 m/s
 * @param action_seq action seq
 * @param fly_circle fly circle
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_mission_current_pack_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan,
							   alink_message_head_t* msg,
						           uint32_t timestamp,uint32_t mission_id,uint32_t remain_length,uint32_t remain_time,uint32_t path_seq,uint32_t photo_sum,uint8_t wp_seq,uint8_t arrived,uint8_t directting,uint8_t status,int16_t speed_set,uint8_t action_seq,uint8_t fly_circle)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_MISSION_CURRENT_LEN];
	_mav_put_uint32_t(buf, 0, timestamp);
	_mav_put_uint32_t(buf, 4, mission_id);
	_mav_put_uint32_t(buf, 8, remain_length);
	_mav_put_uint32_t(buf, 12, remain_time);
	_mav_put_uint32_t(buf, 16, path_seq);
	_mav_put_uint32_t(buf, 20, photo_sum);
	_mav_put_int16_t(buf, 24, speed_set);
	_mav_put_uint8_t(buf, 26, wp_seq);
	_mav_put_uint8_t(buf, 27, arrived);
	_mav_put_uint8_t(buf, 28, directting);
	_mav_put_uint8_t(buf, 29, status);
	_mav_put_uint8_t(buf, 30, action_seq);
	_mav_put_uint8_t(buf, 31, fly_circle);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_MISSION_CURRENT_LEN);
#else
	alink_mission_current_t packet;
	packet.timestamp = timestamp;
	packet.mission_id = mission_id;
	packet.remain_length = remain_length;
	packet.remain_time = remain_time;
	packet.path_seq = path_seq;
	packet.photo_sum = photo_sum;
	packet.speed_set = speed_set;
	packet.wp_seq = wp_seq;
	packet.arrived = arrived;
	packet.directting = directting;
	packet.status = status;
	packet.action_seq = action_seq;
	packet.fly_circle = fly_circle;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_MISSION_CURRENT_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_MISSION_CURRENT;
#if ALINK_CRC_EXTRA
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_MISSION_CURRENT_LEN,ALINK_MSG_ID_MISSION_CURRENT_CRC);
#else
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_MISSION_CURRENT_LEN);
#endif
}
/**
 * @brief Encode a mission_current struct
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 * @param mission_current C-struct to read the message contents from
 */
static inline uint16_t alink_msg_mission_current_encode(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg, const alink_mission_current_t* mission_current)
{
	return alink_msg_mission_current_pack(dest_id, source_id, msg, mission_current->timestamp, mission_current->mission_id, mission_current->remain_length, mission_current->remain_time, mission_current->path_seq, mission_current->photo_sum, mission_current->wp_seq, mission_current->arrived, mission_current->directting, mission_current->status, mission_current->speed_set, mission_current->action_seq, mission_current->fly_circle);
}

/**
 * @brief Encode a mission_current struct on a channel
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param mission_current C-struct to read the message contents from
 */
static inline uint16_t alink_msg_mission_current_encode_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan, alink_message_head_t* msg, const alink_mission_current_t* mission_current)
{
	return alink_msg_mission_current_pack_chan(dest_id, source_id, chan, msg, mission_current->timestamp, mission_current->mission_id, mission_current->remain_length, mission_current->remain_time, mission_current->path_seq, mission_current->photo_sum, mission_current->wp_seq, mission_current->arrived, mission_current->directting, mission_current->status, mission_current->speed_set, mission_current->action_seq, mission_current->fly_circle);
}
// MESSAGE MISSION_CURRENT UNPACKING


/**
 * @brief Get field timestamp from mission_current message
 *
 * @return timestamp (milliseconds since system boot)
 */
static inline uint32_t alink_msg_mission_current_get_timestamp(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field mission_id from mission_current message
 *
 * @return current mission id
 */
static inline uint32_t alink_msg_mission_current_get_mission_id(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint32_t(msg,  4);
}

/**
 * @brief Get field remain_length from mission_current message
 *
 * @return mission remain length
 */
static inline uint32_t alink_msg_mission_current_get_remain_length(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint32_t(msg,  8);
}

/**
 * @brief Get field remain_time from mission_current message
 *
 * @return  mission remain time
 */
static inline uint32_t alink_msg_mission_current_get_remain_time(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint32_t(msg,  12);
}

/**
 * @brief Get field path_seq from mission_current message
 *
 * @return little way point seq
 */
static inline uint32_t alink_msg_mission_current_get_path_seq(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint32_t(msg,  16);
}

/**
 * @brief Get field photo_sum from mission_current message
 *
 * @return the sum of photos in this flight
 */
static inline uint32_t alink_msg_mission_current_get_photo_sum(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint32_t(msg,  20);
}

/**
 * @brief Get field wp_seq from mission_current message
 *
 * @return way point seq
 */
static inline uint8_t alink_msg_mission_current_get_wp_seq(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  26);
}

/**
 * @brief Get field arrived from mission_current message
 *
 * @return way point arrived or not; 0: not; 1:arrived
 */
static inline uint8_t alink_msg_mission_current_get_arrived(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  27);
}

/**
 * @brief Get field directting from mission_current message
 *
 * @return directting next wp or not; 0: not; 1:yes
 */
static inline uint8_t alink_msg_mission_current_get_directting(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  28);
}

/**
 * @brief Get field status from mission_current message
 *
 * @return way point status. 0:pause; 1:running; 2:completed; other:as defiens latter
 */
static inline uint8_t alink_msg_mission_current_get_status(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  29);
}

/**
 * @brief Get field speed_set from mission_current message
 *
 * @return way point speed set,in 1e-3 m/s
 */
static inline int16_t alink_msg_mission_current_get_speed_set(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  24);
}

/**
 * @brief Get field action_seq from mission_current message
 *
 * @return action seq
 */
static inline uint8_t alink_msg_mission_current_get_action_seq(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  30);
}

/**
 * @brief Get field fly_circle from mission_current message
 *
 * @return fly circle
 */
static inline uint8_t alink_msg_mission_current_get_fly_circle(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  31);
}

/**
 * @brief Decode a mission_current message into a struct
 *
 * @param msg The message to decode
 * @param mission_current C-struct to decode the message contents into
 */
static inline void alink_msg_mission_current_decode(const alink_message_head_t* msg, alink_mission_current_t* mission_current)
{
#if ALINK_NEED_BYTE_SWAP
	mission_current->timestamp = alink_msg_mission_current_get_timestamp(msg);
	mission_current->mission_id = alink_msg_mission_current_get_mission_id(msg);
	mission_current->remain_length = alink_msg_mission_current_get_remain_length(msg);
	mission_current->remain_time = alink_msg_mission_current_get_remain_time(msg);
	mission_current->path_seq = alink_msg_mission_current_get_path_seq(msg);
	mission_current->photo_sum = alink_msg_mission_current_get_photo_sum(msg);
	mission_current->speed_set = alink_msg_mission_current_get_speed_set(msg);
	mission_current->wp_seq = alink_msg_mission_current_get_wp_seq(msg);
	mission_current->arrived = alink_msg_mission_current_get_arrived(msg);
	mission_current->directting = alink_msg_mission_current_get_directting(msg);
	mission_current->status = alink_msg_mission_current_get_status(msg);
	mission_current->action_seq = alink_msg_mission_current_get_action_seq(msg);
	mission_current->fly_circle = alink_msg_mission_current_get_fly_circle(msg);
#else
	memcpy(mission_current, _MAV_PAYLOAD(msg), ALINK_MSG_ID_MISSION_CURRENT_LEN);
#endif
}
