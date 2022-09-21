// MESSAGE PUSH_GIMBAL_LASER_MSG PACKING

#define ALINK_MSG_ID_PUSH_GIMBAL_LASER_MSG 54

typedef struct __alink_push_gimbal_laser_msg_t
{
 int32_t target_latitude; /*< 目标纬度 ，单位 10-E7*/
 int32_t target_longitude; /*< 目标经度，单位 10-E7*/
 uint16_t target_dis; /*< 目标距离** 10-E1*/
 int16_t target_alt; /*< 目标高度* 10-E3*/
 int16_t target_speed; /*< 目标速度* 10-E3*/
 uint8_t data[12]; /*< 备用*/
} alink_push_gimbal_laser_msg_t;

#define ALINK_MSG_ID_PUSH_GIMBAL_LASER_MSG_LEN 26
#define ALINK_MSG_ID_54_LEN 26

#define ALINK_MSG_ID_PUSH_GIMBAL_LASER_MSG_CRC 130
#define ALINK_MSG_ID_54_CRC 130

#define ALINK_MSG_PUSH_GIMBAL_LASER_MSG_FIELD_DATA_LEN 12

#define ALINK_MESSAGE_INFO_PUSH_GIMBAL_LASER_MSG { \
	"PUSH_GIMBAL_LASER_MSG", \
	6, \
	{  { "target_latitude", NULL, ALINK_TYPE_INT32_T, 0, 0, offsetof(alink_push_gimbal_laser_msg_t, target_latitude) }, \
         { "target_longitude", NULL, ALINK_TYPE_INT32_T, 0, 4, offsetof(alink_push_gimbal_laser_msg_t, target_longitude) }, \
         { "target_dis", NULL, ALINK_TYPE_UINT16_T, 0, 8, offsetof(alink_push_gimbal_laser_msg_t, target_dis) }, \
         { "target_alt", NULL, ALINK_TYPE_INT16_T, 0, 10, offsetof(alink_push_gimbal_laser_msg_t, target_alt) }, \
         { "target_speed", NULL, ALINK_TYPE_INT16_T, 0, 12, offsetof(alink_push_gimbal_laser_msg_t, target_speed) }, \
         { "data", NULL, ALINK_TYPE_UINT8_T, 12, 14, offsetof(alink_push_gimbal_laser_msg_t, data) }, \
         } \
}


/**
 * @brief Pack a push_gimbal_laser_msg message
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 *
 * @param target_latitude 目标纬度 ，单位 10-E7
 * @param target_longitude 目标经度，单位 10-E7
 * @param target_dis 目标距离** 10-E1
 * @param target_alt 目标高度* 10-E3
 * @param target_speed 目标速度* 10-E3
 * @param data 备用
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_push_gimbal_laser_msg_pack(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg,
						       int32_t target_latitude, int32_t target_longitude, uint16_t target_dis, int16_t target_alt, int16_t target_speed, const uint8_t *data)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_PUSH_GIMBAL_LASER_MSG_LEN];
	_mav_put_int32_t(buf, 0, target_latitude);
	_mav_put_int32_t(buf, 4, target_longitude);
	_mav_put_uint16_t(buf, 8, target_dis);
	_mav_put_int16_t(buf, 10, target_alt);
	_mav_put_int16_t(buf, 12, target_speed);
	_mav_put_uint8_t_array(buf, 14, data, 12);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_PUSH_GIMBAL_LASER_MSG_LEN);
#else
	alink_push_gimbal_laser_msg_t packet;
	packet.target_latitude = target_latitude;
	packet.target_longitude = target_longitude;
	packet.target_dis = target_dis;
	packet.target_alt = target_alt;
	packet.target_speed = target_speed;
	mav_array_memcpy(packet.data, data, sizeof(uint8_t)*12);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_PUSH_GIMBAL_LASER_MSG_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_PUSH_GIMBAL_LASER_MSG;
#if ALINK_CRC_EXTRA
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_PUSH_GIMBAL_LASER_MSG_LEN,ALINK_MSG_ID_PUSH_GIMBAL_LASER_MSG_CRC);
#else
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_PUSH_GIMBAL_LASER_MSG_LEN);
#endif
}

/**
 * @brief Pack a push_gimbal_laser_msg message on a channel
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param target_latitude 目标纬度 ，单位 10-E7
 * @param target_longitude 目标经度，单位 10-E7
 * @param target_dis 目标距离** 10-E1
 * @param target_alt 目标高度* 10-E3
 * @param target_speed 目标速度* 10-E3
 * @param data 备用
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_push_gimbal_laser_msg_pack_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan,
							   alink_message_head_t* msg,
						           int32_t target_latitude,int32_t target_longitude,uint16_t target_dis,int16_t target_alt,int16_t target_speed,const uint8_t *data)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_PUSH_GIMBAL_LASER_MSG_LEN];
	_mav_put_int32_t(buf, 0, target_latitude);
	_mav_put_int32_t(buf, 4, target_longitude);
	_mav_put_uint16_t(buf, 8, target_dis);
	_mav_put_int16_t(buf, 10, target_alt);
	_mav_put_int16_t(buf, 12, target_speed);
	_mav_put_uint8_t_array(buf, 14, data, 12);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_PUSH_GIMBAL_LASER_MSG_LEN);
#else
	alink_push_gimbal_laser_msg_t packet;
	packet.target_latitude = target_latitude;
	packet.target_longitude = target_longitude;
	packet.target_dis = target_dis;
	packet.target_alt = target_alt;
	packet.target_speed = target_speed;
	mav_array_memcpy(packet.data, data, sizeof(uint8_t)*12);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_PUSH_GIMBAL_LASER_MSG_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_PUSH_GIMBAL_LASER_MSG;
#if ALINK_CRC_EXTRA
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_PUSH_GIMBAL_LASER_MSG_LEN,ALINK_MSG_ID_PUSH_GIMBAL_LASER_MSG_CRC);
#else
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_PUSH_GIMBAL_LASER_MSG_LEN);
#endif
}
/**
 * @brief Encode a push_gimbal_laser_msg struct
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 * @param push_gimbal_laser_msg C-struct to read the message contents from
 */
static inline uint16_t alink_msg_push_gimbal_laser_msg_encode(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg, const alink_push_gimbal_laser_msg_t* push_gimbal_laser_msg)
{
	return alink_msg_push_gimbal_laser_msg_pack(dest_id, source_id, msg, push_gimbal_laser_msg->target_latitude, push_gimbal_laser_msg->target_longitude, push_gimbal_laser_msg->target_dis, push_gimbal_laser_msg->target_alt, push_gimbal_laser_msg->target_speed, push_gimbal_laser_msg->data);
}

/**
 * @brief Encode a push_gimbal_laser_msg struct on a channel
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param push_gimbal_laser_msg C-struct to read the message contents from
 */
static inline uint16_t alink_msg_push_gimbal_laser_msg_encode_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan, alink_message_head_t* msg, const alink_push_gimbal_laser_msg_t* push_gimbal_laser_msg)
{
	return alink_msg_push_gimbal_laser_msg_pack_chan(dest_id, source_id, chan, msg, push_gimbal_laser_msg->target_latitude, push_gimbal_laser_msg->target_longitude, push_gimbal_laser_msg->target_dis, push_gimbal_laser_msg->target_alt, push_gimbal_laser_msg->target_speed, push_gimbal_laser_msg->data);
}
// MESSAGE PUSH_GIMBAL_LASER_MSG UNPACKING


/**
 * @brief Get field target_latitude from push_gimbal_laser_msg message
 *
 * @return 目标纬度 ，单位 10-E7
 */
static inline int32_t alink_msg_push_gimbal_laser_msg_get_target_latitude(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  0);
}

/**
 * @brief Get field target_longitude from push_gimbal_laser_msg message
 *
 * @return 目标经度，单位 10-E7
 */
static inline int32_t alink_msg_push_gimbal_laser_msg_get_target_longitude(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  4);
}

/**
 * @brief Get field target_dis from push_gimbal_laser_msg message
 *
 * @return 目标距离** 10-E1
 */
static inline uint16_t alink_msg_push_gimbal_laser_msg_get_target_dis(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  8);
}

/**
 * @brief Get field target_alt from push_gimbal_laser_msg message
 *
 * @return 目标高度* 10-E3
 */
static inline int16_t alink_msg_push_gimbal_laser_msg_get_target_alt(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  10);
}

/**
 * @brief Get field target_speed from push_gimbal_laser_msg message
 *
 * @return 目标速度* 10-E3
 */
static inline int16_t alink_msg_push_gimbal_laser_msg_get_target_speed(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  12);
}

/**
 * @brief Get field data from push_gimbal_laser_msg message
 *
 * @return 备用
 */
static inline uint16_t alink_msg_push_gimbal_laser_msg_get_data(const alink_message_head_t* msg, uint8_t *data)
{
	return _MAV_RETURN_uint8_t_array(msg, data, 12,  14);
}

/**
 * @brief Decode a push_gimbal_laser_msg message into a struct
 *
 * @param msg The message to decode
 * @param push_gimbal_laser_msg C-struct to decode the message contents into
 */
static inline void alink_msg_push_gimbal_laser_msg_decode(const alink_message_head_t* msg, alink_push_gimbal_laser_msg_t* push_gimbal_laser_msg)
{
#if ALINK_NEED_BYTE_SWAP
	push_gimbal_laser_msg->target_latitude = alink_msg_push_gimbal_laser_msg_get_target_latitude(msg);
	push_gimbal_laser_msg->target_longitude = alink_msg_push_gimbal_laser_msg_get_target_longitude(msg);
	push_gimbal_laser_msg->target_dis = alink_msg_push_gimbal_laser_msg_get_target_dis(msg);
	push_gimbal_laser_msg->target_alt = alink_msg_push_gimbal_laser_msg_get_target_alt(msg);
	push_gimbal_laser_msg->target_speed = alink_msg_push_gimbal_laser_msg_get_target_speed(msg);
	alink_msg_push_gimbal_laser_msg_get_data(msg, push_gimbal_laser_msg->data);
#else
	memcpy(push_gimbal_laser_msg, _MAV_PAYLOAD(msg), ALINK_MSG_ID_PUSH_GIMBAL_LASER_MSG_LEN);
#endif
}
