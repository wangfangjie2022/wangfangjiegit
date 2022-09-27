// MESSAGE TARGET_INFO PACKING

#define ALINK_MSG_ID_TARGET_INFO 46

typedef struct __alink_target_info_t
{
 uint32_t timestamp; /*< timestamp (milliseconds since system boot)*/
 int32_t target_lat_est; /*< lattitude of target estimated in 10E7 degree*/
 int32_t target_lon_est; /*< longitude of target estimated in 10E7 degree*/
 uint8_t tracking_status; /*< tracking status in target tracking mode. 0: Quit target tracking; 1:tracking now; 2:target lost*/
} alink_target_info_t;

#define ALINK_MSG_ID_TARGET_INFO_LEN 13
#define ALINK_MSG_ID_46_LEN 13

#define ALINK_MSG_ID_TARGET_INFO_CRC 14
#define ALINK_MSG_ID_46_CRC 14



#define ALINK_MESSAGE_INFO_TARGET_INFO { \
	"TARGET_INFO", \
	4, \
	{  { "timestamp", NULL, ALINK_TYPE_UINT32_T, 0, 0, offsetof(alink_target_info_t, timestamp) }, \
         { "target_lat_est", NULL, ALINK_TYPE_INT32_T, 0, 4, offsetof(alink_target_info_t, target_lat_est) }, \
         { "target_lon_est", NULL, ALINK_TYPE_INT32_T, 0, 8, offsetof(alink_target_info_t, target_lon_est) }, \
         { "tracking_status", NULL, ALINK_TYPE_UINT8_T, 0, 12, offsetof(alink_target_info_t, tracking_status) }, \
         } \
}


/**
 * @brief Pack a target_info message
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 *
 * @param timestamp timestamp (milliseconds since system boot)
 * @param target_lat_est lattitude of target estimated in 10E7 degree
 * @param target_lon_est longitude of target estimated in 10E7 degree
 * @param tracking_status tracking status in target tracking mode. 0: Quit target tracking; 1:tracking now; 2:target lost
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_target_info_pack(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg,
						       uint32_t timestamp, int32_t target_lat_est, int32_t target_lon_est, uint8_t tracking_status)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_TARGET_INFO_LEN];
	_mav_put_uint32_t(buf, 0, timestamp);
	_mav_put_int32_t(buf, 4, target_lat_est);
	_mav_put_int32_t(buf, 8, target_lon_est);
	_mav_put_uint8_t(buf, 12, tracking_status);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_TARGET_INFO_LEN);
#else
	alink_target_info_t packet;
	packet.timestamp = timestamp;
	packet.target_lat_est = target_lat_est;
	packet.target_lon_est = target_lon_est;
	packet.tracking_status = tracking_status;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_TARGET_INFO_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_TARGET_INFO;
#if ALINK_CRC_EXTRA
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_TARGET_INFO_LEN,ALINK_MSG_ID_TARGET_INFO_CRC);
#else
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_TARGET_INFO_LEN);
#endif
}

/**
 * @brief Pack a target_info message on a channel
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param timestamp timestamp (milliseconds since system boot)
 * @param target_lat_est lattitude of target estimated in 10E7 degree
 * @param target_lon_est longitude of target estimated in 10E7 degree
 * @param tracking_status tracking status in target tracking mode. 0: Quit target tracking; 1:tracking now; 2:target lost
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_target_info_pack_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan,
							   alink_message_head_t* msg,
						           uint32_t timestamp,int32_t target_lat_est,int32_t target_lon_est,uint8_t tracking_status)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_TARGET_INFO_LEN];
	_mav_put_uint32_t(buf, 0, timestamp);
	_mav_put_int32_t(buf, 4, target_lat_est);
	_mav_put_int32_t(buf, 8, target_lon_est);
	_mav_put_uint8_t(buf, 12, tracking_status);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_TARGET_INFO_LEN);
#else
	alink_target_info_t packet;
	packet.timestamp = timestamp;
	packet.target_lat_est = target_lat_est;
	packet.target_lon_est = target_lon_est;
	packet.tracking_status = tracking_status;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_TARGET_INFO_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_TARGET_INFO;
#if ALINK_CRC_EXTRA
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_TARGET_INFO_LEN,ALINK_MSG_ID_TARGET_INFO_CRC);
#else
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_TARGET_INFO_LEN);
#endif
}
/**
 * @brief Encode a target_info struct
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 * @param target_info C-struct to read the message contents from
 */
static inline uint16_t alink_msg_target_info_encode(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg, const alink_target_info_t* target_info)
{
	return alink_msg_target_info_pack(dest_id, source_id, msg, target_info->timestamp, target_info->target_lat_est, target_info->target_lon_est, target_info->tracking_status);
}

/**
 * @brief Encode a target_info struct on a channel
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param target_info C-struct to read the message contents from
 */
static inline uint16_t alink_msg_target_info_encode_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan, alink_message_head_t* msg, const alink_target_info_t* target_info)
{
	return alink_msg_target_info_pack_chan(dest_id, source_id, chan, msg, target_info->timestamp, target_info->target_lat_est, target_info->target_lon_est, target_info->tracking_status);
}
// MESSAGE TARGET_INFO UNPACKING


/**
 * @brief Get field timestamp from target_info message
 *
 * @return timestamp (milliseconds since system boot)
 */
static inline uint32_t alink_msg_target_info_get_timestamp(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field target_lat_est from target_info message
 *
 * @return lattitude of target estimated in 10E7 degree
 */
static inline int32_t alink_msg_target_info_get_target_lat_est(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  4);
}

/**
 * @brief Get field target_lon_est from target_info message
 *
 * @return longitude of target estimated in 10E7 degree
 */
static inline int32_t alink_msg_target_info_get_target_lon_est(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  8);
}

/**
 * @brief Get field tracking_status from target_info message
 *
 * @return tracking status in target tracking mode. 0: Quit target tracking; 1:tracking now; 2:target lost
 */
static inline uint8_t alink_msg_target_info_get_tracking_status(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  12);
}

/**
 * @brief Decode a target_info message into a struct
 *
 * @param msg The message to decode
 * @param target_info C-struct to decode the message contents into
 */
static inline void alink_msg_target_info_decode(const alink_message_head_t* msg, alink_target_info_t* target_info)
{
#if ALINK_NEED_BYTE_SWAP
	target_info->timestamp = alink_msg_target_info_get_timestamp(msg);
	target_info->target_lat_est = alink_msg_target_info_get_target_lat_est(msg);
	target_info->target_lon_est = alink_msg_target_info_get_target_lon_est(msg);
	target_info->tracking_status = alink_msg_target_info_get_tracking_status(msg);
#else
	memcpy(target_info, _MAV_PAYLOAD(msg), ALINK_MSG_ID_TARGET_INFO_LEN);
#endif
}
