// MESSAGE MOVIDUS_REPORT_TRACK_INFO PACKING

#define ALINK_MSG_ID_MOVIDUS_REPORT_TRACK_INFO 125

typedef struct __alink_movidus_report_track_info_t
{
 uint32_t timestamp; /*< 时间戳*/
 uint32_t camera_zoom_factor; /*< 当前相机变焦倍数*/
 float center_x; /*< 目标中心点x坐标*/
 float center_y; /*< 目标中心点y坐标*/
 float tar_width; /*< 目标宽度*/
 float tar_height; /*< 目标高度*/
 uint32_t tk_status; /*< 跟踪状态*/
} alink_movidus_report_track_info_t;

#define ALINK_MSG_ID_MOVIDUS_REPORT_TRACK_INFO_LEN 28
#define ALINK_MSG_ID_125_LEN 28

#define ALINK_MSG_ID_MOVIDUS_REPORT_TRACK_INFO_CRC 109
#define ALINK_MSG_ID_125_CRC 109



#define ALINK_MESSAGE_INFO_MOVIDUS_REPORT_TRACK_INFO { \
	"MOVIDUS_REPORT_TRACK_INFO", \
	7, \
	{  { "timestamp", NULL, ALINK_TYPE_UINT32_T, 0, 0, offsetof(alink_movidus_report_track_info_t, timestamp) }, \
         { "camera_zoom_factor", NULL, ALINK_TYPE_UINT32_T, 0, 4, offsetof(alink_movidus_report_track_info_t, camera_zoom_factor) }, \
         { "center_x", NULL, ALINK_TYPE_FLOAT, 0, 8, offsetof(alink_movidus_report_track_info_t, center_x) }, \
         { "center_y", NULL, ALINK_TYPE_FLOAT, 0, 12, offsetof(alink_movidus_report_track_info_t, center_y) }, \
         { "tar_width", NULL, ALINK_TYPE_FLOAT, 0, 16, offsetof(alink_movidus_report_track_info_t, tar_width) }, \
         { "tar_height", NULL, ALINK_TYPE_FLOAT, 0, 20, offsetof(alink_movidus_report_track_info_t, tar_height) }, \
         { "tk_status", NULL, ALINK_TYPE_UINT32_T, 0, 24, offsetof(alink_movidus_report_track_info_t, tk_status) }, \
         } \
}


/**
 * @brief Pack a movidus_report_track_info message
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 *
 * @param timestamp 时间戳
 * @param camera_zoom_factor 当前相机变焦倍数
 * @param center_x 目标中心点x坐标
 * @param center_y 目标中心点y坐标
 * @param tar_width 目标宽度
 * @param tar_height 目标高度
 * @param tk_status 跟踪状态
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_movidus_report_track_info_pack(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg,
						       uint32_t timestamp, uint32_t camera_zoom_factor, float center_x, float center_y, float tar_width, float tar_height, uint32_t tk_status)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_MOVIDUS_REPORT_TRACK_INFO_LEN];
	_mav_put_uint32_t(buf, 0, timestamp);
	_mav_put_uint32_t(buf, 4, camera_zoom_factor);
	_mav_put_float(buf, 8, center_x);
	_mav_put_float(buf, 12, center_y);
	_mav_put_float(buf, 16, tar_width);
	_mav_put_float(buf, 20, tar_height);
	_mav_put_uint32_t(buf, 24, tk_status);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_MOVIDUS_REPORT_TRACK_INFO_LEN);
#else
	alink_movidus_report_track_info_t packet;
	packet.timestamp = timestamp;
	packet.camera_zoom_factor = camera_zoom_factor;
	packet.center_x = center_x;
	packet.center_y = center_y;
	packet.tar_width = tar_width;
	packet.tar_height = tar_height;
	packet.tk_status = tk_status;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_MOVIDUS_REPORT_TRACK_INFO_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_MOVIDUS_REPORT_TRACK_INFO;
#if ALINK_CRC_EXTRA
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_MOVIDUS_REPORT_TRACK_INFO_LEN,ALINK_MSG_ID_MOVIDUS_REPORT_TRACK_INFO_CRC);
#else
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_MOVIDUS_REPORT_TRACK_INFO_LEN);
#endif
}

/**
 * @brief Pack a movidus_report_track_info message on a channel
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param timestamp 时间戳
 * @param camera_zoom_factor 当前相机变焦倍数
 * @param center_x 目标中心点x坐标
 * @param center_y 目标中心点y坐标
 * @param tar_width 目标宽度
 * @param tar_height 目标高度
 * @param tk_status 跟踪状态
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_movidus_report_track_info_pack_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan,
							   alink_message_head_t* msg,
						           uint32_t timestamp,uint32_t camera_zoom_factor,float center_x,float center_y,float tar_width,float tar_height,uint32_t tk_status)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_MOVIDUS_REPORT_TRACK_INFO_LEN];
	_mav_put_uint32_t(buf, 0, timestamp);
	_mav_put_uint32_t(buf, 4, camera_zoom_factor);
	_mav_put_float(buf, 8, center_x);
	_mav_put_float(buf, 12, center_y);
	_mav_put_float(buf, 16, tar_width);
	_mav_put_float(buf, 20, tar_height);
	_mav_put_uint32_t(buf, 24, tk_status);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_MOVIDUS_REPORT_TRACK_INFO_LEN);
#else
	alink_movidus_report_track_info_t packet;
	packet.timestamp = timestamp;
	packet.camera_zoom_factor = camera_zoom_factor;
	packet.center_x = center_x;
	packet.center_y = center_y;
	packet.tar_width = tar_width;
	packet.tar_height = tar_height;
	packet.tk_status = tk_status;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_MOVIDUS_REPORT_TRACK_INFO_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_MOVIDUS_REPORT_TRACK_INFO;
#if ALINK_CRC_EXTRA
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_MOVIDUS_REPORT_TRACK_INFO_LEN,ALINK_MSG_ID_MOVIDUS_REPORT_TRACK_INFO_CRC);
#else
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_MOVIDUS_REPORT_TRACK_INFO_LEN);
#endif
}
/**
 * @brief Encode a movidus_report_track_info struct
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 * @param movidus_report_track_info C-struct to read the message contents from
 */
static inline uint16_t alink_msg_movidus_report_track_info_encode(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg, const alink_movidus_report_track_info_t* movidus_report_track_info)
{
	return alink_msg_movidus_report_track_info_pack(dest_id, source_id, msg, movidus_report_track_info->timestamp, movidus_report_track_info->camera_zoom_factor, movidus_report_track_info->center_x, movidus_report_track_info->center_y, movidus_report_track_info->tar_width, movidus_report_track_info->tar_height, movidus_report_track_info->tk_status);
}

/**
 * @brief Encode a movidus_report_track_info struct on a channel
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param movidus_report_track_info C-struct to read the message contents from
 */
static inline uint16_t alink_msg_movidus_report_track_info_encode_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan, alink_message_head_t* msg, const alink_movidus_report_track_info_t* movidus_report_track_info)
{
	return alink_msg_movidus_report_track_info_pack_chan(dest_id, source_id, chan, msg, movidus_report_track_info->timestamp, movidus_report_track_info->camera_zoom_factor, movidus_report_track_info->center_x, movidus_report_track_info->center_y, movidus_report_track_info->tar_width, movidus_report_track_info->tar_height, movidus_report_track_info->tk_status);
}
// MESSAGE MOVIDUS_REPORT_TRACK_INFO UNPACKING


/**
 * @brief Get field timestamp from movidus_report_track_info message
 *
 * @return 时间戳
 */
static inline uint32_t alink_msg_movidus_report_track_info_get_timestamp(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field camera_zoom_factor from movidus_report_track_info message
 *
 * @return 当前相机变焦倍数
 */
static inline uint32_t alink_msg_movidus_report_track_info_get_camera_zoom_factor(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint32_t(msg,  4);
}

/**
 * @brief Get field center_x from movidus_report_track_info message
 *
 * @return 目标中心点x坐标
 */
static inline float alink_msg_movidus_report_track_info_get_center_x(const alink_message_head_t* msg)
{
	return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field center_y from movidus_report_track_info message
 *
 * @return 目标中心点y坐标
 */
static inline float alink_msg_movidus_report_track_info_get_center_y(const alink_message_head_t* msg)
{
	return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field tar_width from movidus_report_track_info message
 *
 * @return 目标宽度
 */
static inline float alink_msg_movidus_report_track_info_get_tar_width(const alink_message_head_t* msg)
{
	return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Get field tar_height from movidus_report_track_info message
 *
 * @return 目标高度
 */
static inline float alink_msg_movidus_report_track_info_get_tar_height(const alink_message_head_t* msg)
{
	return _MAV_RETURN_float(msg,  20);
}

/**
 * @brief Get field tk_status from movidus_report_track_info message
 *
 * @return 跟踪状态
 */
static inline uint32_t alink_msg_movidus_report_track_info_get_tk_status(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint32_t(msg,  24);
}

/**
 * @brief Decode a movidus_report_track_info message into a struct
 *
 * @param msg The message to decode
 * @param movidus_report_track_info C-struct to decode the message contents into
 */
static inline void alink_msg_movidus_report_track_info_decode(const alink_message_head_t* msg, alink_movidus_report_track_info_t* movidus_report_track_info)
{
#if ALINK_NEED_BYTE_SWAP
	movidus_report_track_info->timestamp = alink_msg_movidus_report_track_info_get_timestamp(msg);
	movidus_report_track_info->camera_zoom_factor = alink_msg_movidus_report_track_info_get_camera_zoom_factor(msg);
	movidus_report_track_info->center_x = alink_msg_movidus_report_track_info_get_center_x(msg);
	movidus_report_track_info->center_y = alink_msg_movidus_report_track_info_get_center_y(msg);
	movidus_report_track_info->tar_width = alink_msg_movidus_report_track_info_get_tar_width(msg);
	movidus_report_track_info->tar_height = alink_msg_movidus_report_track_info_get_tar_height(msg);
	movidus_report_track_info->tk_status = alink_msg_movidus_report_track_info_get_tk_status(msg);
#else
	memcpy(movidus_report_track_info, _MAV_PAYLOAD(msg), ALINK_MSG_ID_MOVIDUS_REPORT_TRACK_INFO_LEN);
#endif
}
