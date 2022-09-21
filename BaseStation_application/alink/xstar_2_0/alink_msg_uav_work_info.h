// MESSAGE UAV_WORK_INFO PACKING

#define ALINK_MSG_ID_UAV_WORK_INFO 45

typedef struct __alink_uav_work_info_t
{
 uint32_t timestamp; /*< timestamp (milliseconds since system boot)*/
 uint32_t fly_turns; /*<  */
 uint32_t fly_time_total; /*< */
 uint32_t fly_time_current; /*< */
 uint32_t reserve1; /*< */
 uint32_t reserve2; /*< */
} alink_uav_work_info_t;

#define ALINK_MSG_ID_UAV_WORK_INFO_LEN 24
#define ALINK_MSG_ID_45_LEN 24

#define ALINK_MSG_ID_UAV_WORK_INFO_CRC 55
#define ALINK_MSG_ID_45_CRC 55



#define ALINK_MESSAGE_INFO_UAV_WORK_INFO { \
	"UAV_WORK_INFO", \
	6, \
	{  { "timestamp", NULL, ALINK_TYPE_UINT32_T, 0, 0, offsetof(alink_uav_work_info_t, timestamp) }, \
         { "fly_turns", NULL, ALINK_TYPE_UINT32_T, 0, 4, offsetof(alink_uav_work_info_t, fly_turns) }, \
         { "fly_time_total", NULL, ALINK_TYPE_UINT32_T, 0, 8, offsetof(alink_uav_work_info_t, fly_time_total) }, \
         { "fly_time_current", NULL, ALINK_TYPE_UINT32_T, 0, 12, offsetof(alink_uav_work_info_t, fly_time_current) }, \
         { "reserve1", NULL, ALINK_TYPE_UINT32_T, 0, 16, offsetof(alink_uav_work_info_t, reserve1) }, \
         { "reserve2", NULL, ALINK_TYPE_UINT32_T, 0, 20, offsetof(alink_uav_work_info_t, reserve2) }, \
         } \
}


/**
 * @brief Pack a uav_work_info message
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 *
 * @param timestamp timestamp (milliseconds since system boot)
 * @param fly_turns  
 * @param fly_time_total 
 * @param fly_time_current 
 * @param reserve1 
 * @param reserve2 
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_uav_work_info_pack(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg,
						       uint32_t timestamp, uint32_t fly_turns, uint32_t fly_time_total, uint32_t fly_time_current, uint32_t reserve1, uint32_t reserve2)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_UAV_WORK_INFO_LEN];
	_mav_put_uint32_t(buf, 0, timestamp);
	_mav_put_uint32_t(buf, 4, fly_turns);
	_mav_put_uint32_t(buf, 8, fly_time_total);
	_mav_put_uint32_t(buf, 12, fly_time_current);
	_mav_put_uint32_t(buf, 16, reserve1);
	_mav_put_uint32_t(buf, 20, reserve2);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_UAV_WORK_INFO_LEN);
#else
	alink_uav_work_info_t packet;
	packet.timestamp = timestamp;
	packet.fly_turns = fly_turns;
	packet.fly_time_total = fly_time_total;
	packet.fly_time_current = fly_time_current;
	packet.reserve1 = reserve1;
	packet.reserve2 = reserve2;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_UAV_WORK_INFO_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_UAV_WORK_INFO;
#if ALINK_CRC_EXTRA
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_UAV_WORK_INFO_LEN,ALINK_MSG_ID_UAV_WORK_INFO_CRC);
#else
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_UAV_WORK_INFO_LEN);
#endif
}

/**
 * @brief Pack a uav_work_info message on a channel
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param timestamp timestamp (milliseconds since system boot)
 * @param fly_turns  
 * @param fly_time_total 
 * @param fly_time_current 
 * @param reserve1 
 * @param reserve2 
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_uav_work_info_pack_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan,
							   alink_message_head_t* msg,
						           uint32_t timestamp,uint32_t fly_turns,uint32_t fly_time_total,uint32_t fly_time_current,uint32_t reserve1,uint32_t reserve2)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_UAV_WORK_INFO_LEN];
	_mav_put_uint32_t(buf, 0, timestamp);
	_mav_put_uint32_t(buf, 4, fly_turns);
	_mav_put_uint32_t(buf, 8, fly_time_total);
	_mav_put_uint32_t(buf, 12, fly_time_current);
	_mav_put_uint32_t(buf, 16, reserve1);
	_mav_put_uint32_t(buf, 20, reserve2);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_UAV_WORK_INFO_LEN);
#else
	alink_uav_work_info_t packet;
	packet.timestamp = timestamp;
	packet.fly_turns = fly_turns;
	packet.fly_time_total = fly_time_total;
	packet.fly_time_current = fly_time_current;
	packet.reserve1 = reserve1;
	packet.reserve2 = reserve2;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_UAV_WORK_INFO_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_UAV_WORK_INFO;
#if ALINK_CRC_EXTRA
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_UAV_WORK_INFO_LEN,ALINK_MSG_ID_UAV_WORK_INFO_CRC);
#else
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_UAV_WORK_INFO_LEN);
#endif
}
/**
 * @brief Encode a uav_work_info struct
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 * @param uav_work_info C-struct to read the message contents from
 */
static inline uint16_t alink_msg_uav_work_info_encode(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg, const alink_uav_work_info_t* uav_work_info)
{
	return alink_msg_uav_work_info_pack(dest_id, source_id, msg, uav_work_info->timestamp, uav_work_info->fly_turns, uav_work_info->fly_time_total, uav_work_info->fly_time_current, uav_work_info->reserve1, uav_work_info->reserve2);
}

/**
 * @brief Encode a uav_work_info struct on a channel
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param uav_work_info C-struct to read the message contents from
 */
static inline uint16_t alink_msg_uav_work_info_encode_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan, alink_message_head_t* msg, const alink_uav_work_info_t* uav_work_info)
{
	return alink_msg_uav_work_info_pack_chan(dest_id, source_id, chan, msg, uav_work_info->timestamp, uav_work_info->fly_turns, uav_work_info->fly_time_total, uav_work_info->fly_time_current, uav_work_info->reserve1, uav_work_info->reserve2);
}
// MESSAGE UAV_WORK_INFO UNPACKING


/**
 * @brief Get field timestamp from uav_work_info message
 *
 * @return timestamp (milliseconds since system boot)
 */
static inline uint32_t alink_msg_uav_work_info_get_timestamp(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field fly_turns from uav_work_info message
 *
 * @return  
 */
static inline uint32_t alink_msg_uav_work_info_get_fly_turns(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint32_t(msg,  4);
}

/**
 * @brief Get field fly_time_total from uav_work_info message
 *
 * @return 
 */
static inline uint32_t alink_msg_uav_work_info_get_fly_time_total(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint32_t(msg,  8);
}

/**
 * @brief Get field fly_time_current from uav_work_info message
 *
 * @return 
 */
static inline uint32_t alink_msg_uav_work_info_get_fly_time_current(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint32_t(msg,  12);
}

/**
 * @brief Get field reserve1 from uav_work_info message
 *
 * @return 
 */
static inline uint32_t alink_msg_uav_work_info_get_reserve1(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint32_t(msg,  16);
}

/**
 * @brief Get field reserve2 from uav_work_info message
 *
 * @return 
 */
static inline uint32_t alink_msg_uav_work_info_get_reserve2(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint32_t(msg,  20);
}

/**
 * @brief Decode a uav_work_info message into a struct
 *
 * @param msg The message to decode
 * @param uav_work_info C-struct to decode the message contents into
 */
static inline void alink_msg_uav_work_info_decode(const alink_message_head_t* msg, alink_uav_work_info_t* uav_work_info)
{
#if ALINK_NEED_BYTE_SWAP
	uav_work_info->timestamp = alink_msg_uav_work_info_get_timestamp(msg);
	uav_work_info->fly_turns = alink_msg_uav_work_info_get_fly_turns(msg);
	uav_work_info->fly_time_total = alink_msg_uav_work_info_get_fly_time_total(msg);
	uav_work_info->fly_time_current = alink_msg_uav_work_info_get_fly_time_current(msg);
	uav_work_info->reserve1 = alink_msg_uav_work_info_get_reserve1(msg);
	uav_work_info->reserve2 = alink_msg_uav_work_info_get_reserve2(msg);
#else
	memcpy(uav_work_info, _MAV_PAYLOAD(msg), ALINK_MSG_ID_UAV_WORK_INFO_LEN);
#endif
}
