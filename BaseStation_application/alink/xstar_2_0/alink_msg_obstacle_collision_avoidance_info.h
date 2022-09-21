// MESSAGE OBSTACLE_COLLISION_AVOIDANCE_INFO PACKING

#define ALINK_MSG_ID_OBSTACLE_COLLISION_AVOIDANCE_INFO 93

typedef struct __alink_obstacle_collision_avoidance_info_t
{
 uint64_t timestamp; /*< timestamp (microseconds since system boot)*/
 uint16_t Distance[4]; /*< distances between UAV and obstacle in different direction, dm*/
 uint8_t Source[4]; /*< the source of the obstacle info*/
 uint8_t Maneuver; /*< maneuver for obstacle collsion avoidance*/
} alink_obstacle_collision_avoidance_info_t;

#define ALINK_MSG_ID_OBSTACLE_COLLISION_AVOIDANCE_INFO_LEN 21
#define ALINK_MSG_ID_93_LEN 21

#define ALINK_MSG_ID_OBSTACLE_COLLISION_AVOIDANCE_INFO_CRC 62
#define ALINK_MSG_ID_93_CRC 62

#define ALINK_MSG_OBSTACLE_COLLISION_AVOIDANCE_INFO_FIELD_DISTANCE_LEN 4
#define ALINK_MSG_OBSTACLE_COLLISION_AVOIDANCE_INFO_FIELD_SOURCE_LEN 4

#define ALINK_MESSAGE_INFO_OBSTACLE_COLLISION_AVOIDANCE_INFO { \
	"OBSTACLE_COLLISION_AVOIDANCE_INFO", \
	4, \
	{  { "timestamp", NULL, ALINK_TYPE_UINT64_T, 0, 0, offsetof(alink_obstacle_collision_avoidance_info_t, timestamp) }, \
         { "Distance", NULL, ALINK_TYPE_UINT16_T, 4, 8, offsetof(alink_obstacle_collision_avoidance_info_t, Distance) }, \
         { "Source", NULL, ALINK_TYPE_UINT8_T, 4, 16, offsetof(alink_obstacle_collision_avoidance_info_t, Source) }, \
         { "Maneuver", NULL, ALINK_TYPE_UINT8_T, 0, 20, offsetof(alink_obstacle_collision_avoidance_info_t, Maneuver) }, \
         } \
}


/**
 * @brief Pack a obstacle_collision_avoidance_info message
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 *
 * @param timestamp timestamp (microseconds since system boot)
 * @param Distance distances between UAV and obstacle in different direction, dm
 * @param Source the source of the obstacle info
 * @param Maneuver maneuver for obstacle collsion avoidance
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_obstacle_collision_avoidance_info_pack(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg,
						       uint64_t timestamp, const uint16_t *Distance, const uint8_t *Source, uint8_t Maneuver)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_OBSTACLE_COLLISION_AVOIDANCE_INFO_LEN];
	_mav_put_uint64_t(buf, 0, timestamp);
	_mav_put_uint8_t(buf, 20, Maneuver);
	_mav_put_uint16_t_array(buf, 8, Distance, 4);
	_mav_put_uint8_t_array(buf, 16, Source, 4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_OBSTACLE_COLLISION_AVOIDANCE_INFO_LEN);
#else
	alink_obstacle_collision_avoidance_info_t packet;
	packet.timestamp = timestamp;
	packet.Maneuver = Maneuver;
	mav_array_memcpy(packet.Distance, Distance, sizeof(uint16_t)*4);
	mav_array_memcpy(packet.Source, Source, sizeof(uint8_t)*4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_OBSTACLE_COLLISION_AVOIDANCE_INFO_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_OBSTACLE_COLLISION_AVOIDANCE_INFO;
#if ALINK_CRC_EXTRA
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_OBSTACLE_COLLISION_AVOIDANCE_INFO_LEN,ALINK_MSG_ID_OBSTACLE_COLLISION_AVOIDANCE_INFO_CRC);
#else
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_OBSTACLE_COLLISION_AVOIDANCE_INFO_LEN);
#endif
}

/**
 * @brief Pack a obstacle_collision_avoidance_info message on a channel
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param timestamp timestamp (microseconds since system boot)
 * @param Distance distances between UAV and obstacle in different direction, dm
 * @param Source the source of the obstacle info
 * @param Maneuver maneuver for obstacle collsion avoidance
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_obstacle_collision_avoidance_info_pack_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan,
							   alink_message_head_t* msg,
						           uint64_t timestamp,const uint16_t *Distance,const uint8_t *Source,uint8_t Maneuver)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_OBSTACLE_COLLISION_AVOIDANCE_INFO_LEN];
	_mav_put_uint64_t(buf, 0, timestamp);
	_mav_put_uint8_t(buf, 20, Maneuver);
	_mav_put_uint16_t_array(buf, 8, Distance, 4);
	_mav_put_uint8_t_array(buf, 16, Source, 4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_OBSTACLE_COLLISION_AVOIDANCE_INFO_LEN);
#else
	alink_obstacle_collision_avoidance_info_t packet;
	packet.timestamp = timestamp;
	packet.Maneuver = Maneuver;
	mav_array_memcpy(packet.Distance, Distance, sizeof(uint16_t)*4);
	mav_array_memcpy(packet.Source, Source, sizeof(uint8_t)*4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_OBSTACLE_COLLISION_AVOIDANCE_INFO_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_OBSTACLE_COLLISION_AVOIDANCE_INFO;
#if ALINK_CRC_EXTRA
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_OBSTACLE_COLLISION_AVOIDANCE_INFO_LEN,ALINK_MSG_ID_OBSTACLE_COLLISION_AVOIDANCE_INFO_CRC);
#else
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_OBSTACLE_COLLISION_AVOIDANCE_INFO_LEN);
#endif
}
/**
 * @brief Encode a obstacle_collision_avoidance_info struct
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 * @param obstacle_collision_avoidance_info C-struct to read the message contents from
 */
static inline uint16_t alink_msg_obstacle_collision_avoidance_info_encode(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg, const alink_obstacle_collision_avoidance_info_t* obstacle_collision_avoidance_info)
{
	return alink_msg_obstacle_collision_avoidance_info_pack(dest_id, source_id, msg, obstacle_collision_avoidance_info->timestamp, obstacle_collision_avoidance_info->Distance, obstacle_collision_avoidance_info->Source, obstacle_collision_avoidance_info->Maneuver);
}

/**
 * @brief Encode a obstacle_collision_avoidance_info struct on a channel
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param obstacle_collision_avoidance_info C-struct to read the message contents from
 */
static inline uint16_t alink_msg_obstacle_collision_avoidance_info_encode_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan, alink_message_head_t* msg, const alink_obstacle_collision_avoidance_info_t* obstacle_collision_avoidance_info)
{
	return alink_msg_obstacle_collision_avoidance_info_pack_chan(dest_id, source_id, chan, msg, obstacle_collision_avoidance_info->timestamp, obstacle_collision_avoidance_info->Distance, obstacle_collision_avoidance_info->Source, obstacle_collision_avoidance_info->Maneuver);
}
// MESSAGE OBSTACLE_COLLISION_AVOIDANCE_INFO UNPACKING


/**
 * @brief Get field timestamp from obstacle_collision_avoidance_info message
 *
 * @return timestamp (microseconds since system boot)
 */
static inline uint64_t alink_msg_obstacle_collision_avoidance_info_get_timestamp(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field Distance from obstacle_collision_avoidance_info message
 *
 * @return distances between UAV and obstacle in different direction, dm
 */
static inline uint16_t alink_msg_obstacle_collision_avoidance_info_get_Distance(const alink_message_head_t* msg, uint16_t *Distance)
{
	return _MAV_RETURN_uint16_t_array(msg, Distance, 4,  8);
}

/**
 * @brief Get field Source from obstacle_collision_avoidance_info message
 *
 * @return the source of the obstacle info
 */
static inline uint16_t alink_msg_obstacle_collision_avoidance_info_get_Source(const alink_message_head_t* msg, uint8_t *Source)
{
	return _MAV_RETURN_uint8_t_array(msg, Source, 4,  16);
}

/**
 * @brief Get field Maneuver from obstacle_collision_avoidance_info message
 *
 * @return maneuver for obstacle collsion avoidance
 */
static inline uint8_t alink_msg_obstacle_collision_avoidance_info_get_Maneuver(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  20);
}

/**
 * @brief Decode a obstacle_collision_avoidance_info message into a struct
 *
 * @param msg The message to decode
 * @param obstacle_collision_avoidance_info C-struct to decode the message contents into
 */
static inline void alink_msg_obstacle_collision_avoidance_info_decode(const alink_message_head_t* msg, alink_obstacle_collision_avoidance_info_t* obstacle_collision_avoidance_info)
{
#if ALINK_NEED_BYTE_SWAP
	obstacle_collision_avoidance_info->timestamp = alink_msg_obstacle_collision_avoidance_info_get_timestamp(msg);
	alink_msg_obstacle_collision_avoidance_info_get_Distance(msg, obstacle_collision_avoidance_info->Distance);
	alink_msg_obstacle_collision_avoidance_info_get_Source(msg, obstacle_collision_avoidance_info->Source);
	obstacle_collision_avoidance_info->Maneuver = alink_msg_obstacle_collision_avoidance_info_get_Maneuver(msg);
#else
	memcpy(obstacle_collision_avoidance_info, _MAV_PAYLOAD(msg), ALINK_MSG_ID_OBSTACLE_COLLISION_AVOIDANCE_INFO_LEN);
#endif
}
