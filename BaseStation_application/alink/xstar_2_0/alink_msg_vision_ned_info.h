// MESSAGE VISION_NED_INFO PACKING

#define ALINK_MSG_ID_VISION_NED_INFO 71

typedef struct __alink_vision_ned_info_t
{
 uint32_t timestamp; /*< timestamp (milliseconds since system boot)*/
 int32_t lat_est; /*< lattitude estimated in 10E-7 degree*/
 int32_t lon_est; /*< longitude estimated in 10E-7 degree*/
 int32_t ned_x_est; /*< NED x position estimated in 10E-2 meter*/
 int32_t ned_y_est; /*< NED y position estimated in 10E-2 meter*/
 int16_t height_est; /*< height estimated in 10E-2 meter*/
 int16_t vel_ned_est[3]; /*< N/E/D estimated velocity in 10E-3 m/s*/
 int16_t acc_drag_ned[3]; /*< N/E/D drag acceleration in 10E-3 m/s^2 */
 uint8_t valid_flag; /*< 0 - none valid, 1 - position valid, 2 - velocity valid, 3 - both valid */
} alink_vision_ned_info_t;

#define ALINK_MSG_ID_VISION_NED_INFO_LEN 35
#define ALINK_MSG_ID_71_LEN 35

#define ALINK_MSG_ID_VISION_NED_INFO_CRC 110
#define ALINK_MSG_ID_71_CRC 110

#define ALINK_MSG_VISION_NED_INFO_FIELD_VEL_NED_EST_LEN 3
#define ALINK_MSG_VISION_NED_INFO_FIELD_ACC_DRAG_NED_LEN 3

#define ALINK_MESSAGE_INFO_VISION_NED_INFO { \
	"VISION_NED_INFO", \
	9, \
	{  { "timestamp", NULL, ALINK_TYPE_UINT32_T, 0, 0, offsetof(alink_vision_ned_info_t, timestamp) }, \
         { "lat_est", NULL, ALINK_TYPE_INT32_T, 0, 4, offsetof(alink_vision_ned_info_t, lat_est) }, \
         { "lon_est", NULL, ALINK_TYPE_INT32_T, 0, 8, offsetof(alink_vision_ned_info_t, lon_est) }, \
         { "ned_x_est", NULL, ALINK_TYPE_INT32_T, 0, 12, offsetof(alink_vision_ned_info_t, ned_x_est) }, \
         { "ned_y_est", NULL, ALINK_TYPE_INT32_T, 0, 16, offsetof(alink_vision_ned_info_t, ned_y_est) }, \
         { "height_est", NULL, ALINK_TYPE_INT16_T, 0, 20, offsetof(alink_vision_ned_info_t, height_est) }, \
         { "vel_ned_est", NULL, ALINK_TYPE_INT16_T, 3, 22, offsetof(alink_vision_ned_info_t, vel_ned_est) }, \
         { "acc_drag_ned", NULL, ALINK_TYPE_INT16_T, 3, 28, offsetof(alink_vision_ned_info_t, acc_drag_ned) }, \
         { "valid_flag", NULL, ALINK_TYPE_UINT8_T, 0, 34, offsetof(alink_vision_ned_info_t, valid_flag) }, \
         } \
}


/**
 * @brief Pack a vision_ned_info message
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 *
 * @param timestamp timestamp (milliseconds since system boot)
 * @param lat_est lattitude estimated in 10E-7 degree
 * @param lon_est longitude estimated in 10E-7 degree
 * @param ned_x_est NED x position estimated in 10E-2 meter
 * @param ned_y_est NED y position estimated in 10E-2 meter
 * @param height_est height estimated in 10E-2 meter
 * @param vel_ned_est N/E/D estimated velocity in 10E-3 m/s
 * @param acc_drag_ned N/E/D drag acceleration in 10E-3 m/s^2 
 * @param valid_flag 0 - none valid, 1 - position valid, 2 - velocity valid, 3 - both valid 
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_vision_ned_info_pack(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg,
						       uint32_t timestamp, int32_t lat_est, int32_t lon_est, int32_t ned_x_est, int32_t ned_y_est, int16_t height_est, const int16_t *vel_ned_est, const int16_t *acc_drag_ned, uint8_t valid_flag)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_VISION_NED_INFO_LEN];
	_mav_put_uint32_t(buf, 0, timestamp);
	_mav_put_int32_t(buf, 4, lat_est);
	_mav_put_int32_t(buf, 8, lon_est);
	_mav_put_int32_t(buf, 12, ned_x_est);
	_mav_put_int32_t(buf, 16, ned_y_est);
	_mav_put_int16_t(buf, 20, height_est);
	_mav_put_uint8_t(buf, 34, valid_flag);
	_mav_put_int16_t_array(buf, 22, vel_ned_est, 3);
	_mav_put_int16_t_array(buf, 28, acc_drag_ned, 3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_VISION_NED_INFO_LEN);
#else
	alink_vision_ned_info_t packet;
	packet.timestamp = timestamp;
	packet.lat_est = lat_est;
	packet.lon_est = lon_est;
	packet.ned_x_est = ned_x_est;
	packet.ned_y_est = ned_y_est;
	packet.height_est = height_est;
	packet.valid_flag = valid_flag;
	mav_array_memcpy(packet.vel_ned_est, vel_ned_est, sizeof(int16_t)*3);
	mav_array_memcpy(packet.acc_drag_ned, acc_drag_ned, sizeof(int16_t)*3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_VISION_NED_INFO_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_VISION_NED_INFO;
#if ALINK_CRC_EXTRA
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_VISION_NED_INFO_LEN,ALINK_MSG_ID_VISION_NED_INFO_CRC);
#else
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_VISION_NED_INFO_LEN);
#endif
}

/**
 * @brief Pack a vision_ned_info message on a channel
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param timestamp timestamp (milliseconds since system boot)
 * @param lat_est lattitude estimated in 10E-7 degree
 * @param lon_est longitude estimated in 10E-7 degree
 * @param ned_x_est NED x position estimated in 10E-2 meter
 * @param ned_y_est NED y position estimated in 10E-2 meter
 * @param height_est height estimated in 10E-2 meter
 * @param vel_ned_est N/E/D estimated velocity in 10E-3 m/s
 * @param acc_drag_ned N/E/D drag acceleration in 10E-3 m/s^2 
 * @param valid_flag 0 - none valid, 1 - position valid, 2 - velocity valid, 3 - both valid 
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_vision_ned_info_pack_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan,
							   alink_message_head_t* msg,
						           uint32_t timestamp,int32_t lat_est,int32_t lon_est,int32_t ned_x_est,int32_t ned_y_est,int16_t height_est,const int16_t *vel_ned_est,const int16_t *acc_drag_ned,uint8_t valid_flag)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_VISION_NED_INFO_LEN];
	_mav_put_uint32_t(buf, 0, timestamp);
	_mav_put_int32_t(buf, 4, lat_est);
	_mav_put_int32_t(buf, 8, lon_est);
	_mav_put_int32_t(buf, 12, ned_x_est);
	_mav_put_int32_t(buf, 16, ned_y_est);
	_mav_put_int16_t(buf, 20, height_est);
	_mav_put_uint8_t(buf, 34, valid_flag);
	_mav_put_int16_t_array(buf, 22, vel_ned_est, 3);
	_mav_put_int16_t_array(buf, 28, acc_drag_ned, 3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_VISION_NED_INFO_LEN);
#else
	alink_vision_ned_info_t packet;
	packet.timestamp = timestamp;
	packet.lat_est = lat_est;
	packet.lon_est = lon_est;
	packet.ned_x_est = ned_x_est;
	packet.ned_y_est = ned_y_est;
	packet.height_est = height_est;
	packet.valid_flag = valid_flag;
	mav_array_memcpy(packet.vel_ned_est, vel_ned_est, sizeof(int16_t)*3);
	mav_array_memcpy(packet.acc_drag_ned, acc_drag_ned, sizeof(int16_t)*3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_VISION_NED_INFO_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_VISION_NED_INFO;
#if ALINK_CRC_EXTRA
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_VISION_NED_INFO_LEN,ALINK_MSG_ID_VISION_NED_INFO_CRC);
#else
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_VISION_NED_INFO_LEN);
#endif
}
/**
 * @brief Encode a vision_ned_info struct
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 * @param vision_ned_info C-struct to read the message contents from
 */
static inline uint16_t alink_msg_vision_ned_info_encode(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg, const alink_vision_ned_info_t* vision_ned_info)
{
	return alink_msg_vision_ned_info_pack(dest_id, source_id, msg, vision_ned_info->timestamp, vision_ned_info->lat_est, vision_ned_info->lon_est, vision_ned_info->ned_x_est, vision_ned_info->ned_y_est, vision_ned_info->height_est, vision_ned_info->vel_ned_est, vision_ned_info->acc_drag_ned, vision_ned_info->valid_flag);
}

/**
 * @brief Encode a vision_ned_info struct on a channel
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param vision_ned_info C-struct to read the message contents from
 */
static inline uint16_t alink_msg_vision_ned_info_encode_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan, alink_message_head_t* msg, const alink_vision_ned_info_t* vision_ned_info)
{
	return alink_msg_vision_ned_info_pack_chan(dest_id, source_id, chan, msg, vision_ned_info->timestamp, vision_ned_info->lat_est, vision_ned_info->lon_est, vision_ned_info->ned_x_est, vision_ned_info->ned_y_est, vision_ned_info->height_est, vision_ned_info->vel_ned_est, vision_ned_info->acc_drag_ned, vision_ned_info->valid_flag);
}
// MESSAGE VISION_NED_INFO UNPACKING


/**
 * @brief Get field timestamp from vision_ned_info message
 *
 * @return timestamp (milliseconds since system boot)
 */
static inline uint32_t alink_msg_vision_ned_info_get_timestamp(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field lat_est from vision_ned_info message
 *
 * @return lattitude estimated in 10E-7 degree
 */
static inline int32_t alink_msg_vision_ned_info_get_lat_est(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  4);
}

/**
 * @brief Get field lon_est from vision_ned_info message
 *
 * @return longitude estimated in 10E-7 degree
 */
static inline int32_t alink_msg_vision_ned_info_get_lon_est(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  8);
}

/**
 * @brief Get field ned_x_est from vision_ned_info message
 *
 * @return NED x position estimated in 10E-2 meter
 */
static inline int32_t alink_msg_vision_ned_info_get_ned_x_est(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  12);
}

/**
 * @brief Get field ned_y_est from vision_ned_info message
 *
 * @return NED y position estimated in 10E-2 meter
 */
static inline int32_t alink_msg_vision_ned_info_get_ned_y_est(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  16);
}

/**
 * @brief Get field height_est from vision_ned_info message
 *
 * @return height estimated in 10E-2 meter
 */
static inline int16_t alink_msg_vision_ned_info_get_height_est(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  20);
}

/**
 * @brief Get field vel_ned_est from vision_ned_info message
 *
 * @return N/E/D estimated velocity in 10E-3 m/s
 */
static inline uint16_t alink_msg_vision_ned_info_get_vel_ned_est(const alink_message_head_t* msg, int16_t *vel_ned_est)
{
	return _MAV_RETURN_int16_t_array(msg, vel_ned_est, 3,  22);
}

/**
 * @brief Get field acc_drag_ned from vision_ned_info message
 *
 * @return N/E/D drag acceleration in 10E-3 m/s^2 
 */
static inline uint16_t alink_msg_vision_ned_info_get_acc_drag_ned(const alink_message_head_t* msg, int16_t *acc_drag_ned)
{
	return _MAV_RETURN_int16_t_array(msg, acc_drag_ned, 3,  28);
}

/**
 * @brief Get field valid_flag from vision_ned_info message
 *
 * @return 0 - none valid, 1 - position valid, 2 - velocity valid, 3 - both valid 
 */
static inline uint8_t alink_msg_vision_ned_info_get_valid_flag(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  34);
}

/**
 * @brief Decode a vision_ned_info message into a struct
 *
 * @param msg The message to decode
 * @param vision_ned_info C-struct to decode the message contents into
 */
static inline void alink_msg_vision_ned_info_decode(const alink_message_head_t* msg, alink_vision_ned_info_t* vision_ned_info)
{
#if ALINK_NEED_BYTE_SWAP
	vision_ned_info->timestamp = alink_msg_vision_ned_info_get_timestamp(msg);
	vision_ned_info->lat_est = alink_msg_vision_ned_info_get_lat_est(msg);
	vision_ned_info->lon_est = alink_msg_vision_ned_info_get_lon_est(msg);
	vision_ned_info->ned_x_est = alink_msg_vision_ned_info_get_ned_x_est(msg);
	vision_ned_info->ned_y_est = alink_msg_vision_ned_info_get_ned_y_est(msg);
	vision_ned_info->height_est = alink_msg_vision_ned_info_get_height_est(msg);
	alink_msg_vision_ned_info_get_vel_ned_est(msg, vision_ned_info->vel_ned_est);
	alink_msg_vision_ned_info_get_acc_drag_ned(msg, vision_ned_info->acc_drag_ned);
	vision_ned_info->valid_flag = alink_msg_vision_ned_info_get_valid_flag(msg);
#else
	memcpy(vision_ned_info, _MAV_PAYLOAD(msg), ALINK_MSG_ID_VISION_NED_INFO_LEN);
#endif
}
