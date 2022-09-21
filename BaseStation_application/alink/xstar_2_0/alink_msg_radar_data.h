// MESSAGE RADAR_DATA PACKING

#define ALINK_MSG_ID_RADAR_DATA 160

typedef struct __alink_radar_data_t
{
 uint32_t timestamp; /*< timestamp (microseconds since system boot)*/
 int16_t point_pos_x[32]; /*< x coordinate in 10E-2m, actual [-200, +200]*/
 uint16_t point_pos_y[32]; /*< y coordinate in 10E-2m, actual [0, +350]*/
 int16_t point_pos_z[32]; /*< z coordinate in 10E-2m, actual [-200, +200]*/
 int16_t obj_vel_x[32]; /*< x absolute velocity in 10E-2 m/s, actual [-100, +100]*/
 int16_t obj_vel_y[32]; /*< y absolute velocity in 10E-2 m/s, actual [-100, +100]*/
 int16_t obj_vel_z[32]; /*< z absolute velocity in 10E-2 m/s, actual [-100, +100]*/
 int16_t obj_pw[32]; /*< snr of object in 10E-2 dB, actual [-30, +30]*/
 uint8_t existing_prob[32]; /*< tracking existing prob of object in 10E-2, actual [-0, +1]*/
 uint8_t object_num; /*< number of detected objects, maximum is 32*/
} alink_radar_data_t;

#define ALINK_MSG_ID_RADAR_DATA_LEN 485
#define ALINK_MSG_ID_160_LEN 485

#define ALINK_MSG_ID_RADAR_DATA_CRC 95
#define ALINK_MSG_ID_160_CRC 95

#define ALINK_MSG_RADAR_DATA_FIELD_POINT_POS_X_LEN 32
#define ALINK_MSG_RADAR_DATA_FIELD_POINT_POS_Y_LEN 32
#define ALINK_MSG_RADAR_DATA_FIELD_POINT_POS_Z_LEN 32
#define ALINK_MSG_RADAR_DATA_FIELD_OBJ_VEL_X_LEN 32
#define ALINK_MSG_RADAR_DATA_FIELD_OBJ_VEL_Y_LEN 32
#define ALINK_MSG_RADAR_DATA_FIELD_OBJ_VEL_Z_LEN 32
#define ALINK_MSG_RADAR_DATA_FIELD_OBJ_PW_LEN 32
#define ALINK_MSG_RADAR_DATA_FIELD_EXISTING_PROB_LEN 32

#define ALINK_MESSAGE_INFO_RADAR_DATA { \
	"RADAR_DATA", \
	10, \
	{  { "timestamp", NULL, ALINK_TYPE_UINT32_T, 0, 0, offsetof(alink_radar_data_t, timestamp) }, \
         { "point_pos_x", NULL, ALINK_TYPE_INT16_T, 32, 4, offsetof(alink_radar_data_t, point_pos_x) }, \
         { "point_pos_y", NULL, ALINK_TYPE_UINT16_T, 32, 68, offsetof(alink_radar_data_t, point_pos_y) }, \
         { "point_pos_z", NULL, ALINK_TYPE_INT16_T, 32, 132, offsetof(alink_radar_data_t, point_pos_z) }, \
         { "obj_vel_x", NULL, ALINK_TYPE_INT16_T, 32, 196, offsetof(alink_radar_data_t, obj_vel_x) }, \
         { "obj_vel_y", NULL, ALINK_TYPE_INT16_T, 32, 260, offsetof(alink_radar_data_t, obj_vel_y) }, \
         { "obj_vel_z", NULL, ALINK_TYPE_INT16_T, 32, 324, offsetof(alink_radar_data_t, obj_vel_z) }, \
         { "obj_pw", NULL, ALINK_TYPE_INT16_T, 32, 388, offsetof(alink_radar_data_t, obj_pw) }, \
         { "existing_prob", NULL, ALINK_TYPE_UINT8_T, 32, 452, offsetof(alink_radar_data_t, existing_prob) }, \
         { "object_num", NULL, ALINK_TYPE_UINT8_T, 0, 484, offsetof(alink_radar_data_t, object_num) }, \
         } \
}


/**
 * @brief Pack a radar_data message
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 *
 * @param timestamp timestamp (microseconds since system boot)
 * @param point_pos_x x coordinate in 10E-2m, actual [-200, +200]
 * @param point_pos_y y coordinate in 10E-2m, actual [0, +350]
 * @param point_pos_z z coordinate in 10E-2m, actual [-200, +200]
 * @param obj_vel_x x absolute velocity in 10E-2 m/s, actual [-100, +100]
 * @param obj_vel_y y absolute velocity in 10E-2 m/s, actual [-100, +100]
 * @param obj_vel_z z absolute velocity in 10E-2 m/s, actual [-100, +100]
 * @param obj_pw snr of object in 10E-2 dB, actual [-30, +30]
 * @param existing_prob tracking existing prob of object in 10E-2, actual [-0, +1]
 * @param object_num number of detected objects, maximum is 32
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_radar_data_pack(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg,
						       uint32_t timestamp, const int16_t *point_pos_x, const uint16_t *point_pos_y, const int16_t *point_pos_z, const int16_t *obj_vel_x, const int16_t *obj_vel_y, const int16_t *obj_vel_z, const int16_t *obj_pw, const uint8_t *existing_prob, uint8_t object_num)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_RADAR_DATA_LEN];
	_mav_put_uint32_t(buf, 0, timestamp);
	_mav_put_uint8_t(buf, 484, object_num);
	_mav_put_int16_t_array(buf, 4, point_pos_x, 32);
	_mav_put_uint16_t_array(buf, 68, point_pos_y, 32);
	_mav_put_int16_t_array(buf, 132, point_pos_z, 32);
	_mav_put_int16_t_array(buf, 196, obj_vel_x, 32);
	_mav_put_int16_t_array(buf, 260, obj_vel_y, 32);
	_mav_put_int16_t_array(buf, 324, obj_vel_z, 32);
	_mav_put_int16_t_array(buf, 388, obj_pw, 32);
	_mav_put_uint8_t_array(buf, 452, existing_prob, 32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_RADAR_DATA_LEN);
#else
	alink_radar_data_t packet;
	packet.timestamp = timestamp;
	packet.object_num = object_num;
	mav_array_memcpy(packet.point_pos_x, point_pos_x, sizeof(int16_t)*32);
	mav_array_memcpy(packet.point_pos_y, point_pos_y, sizeof(uint16_t)*32);
	mav_array_memcpy(packet.point_pos_z, point_pos_z, sizeof(int16_t)*32);
	mav_array_memcpy(packet.obj_vel_x, obj_vel_x, sizeof(int16_t)*32);
	mav_array_memcpy(packet.obj_vel_y, obj_vel_y, sizeof(int16_t)*32);
	mav_array_memcpy(packet.obj_vel_z, obj_vel_z, sizeof(int16_t)*32);
	mav_array_memcpy(packet.obj_pw, obj_pw, sizeof(int16_t)*32);
	mav_array_memcpy(packet.existing_prob, existing_prob, sizeof(uint8_t)*32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_RADAR_DATA_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_RADAR_DATA;
#if ALINK_CRC_EXTRA
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_RADAR_DATA_LEN,ALINK_MSG_ID_RADAR_DATA_CRC);
#else
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_RADAR_DATA_LEN);
#endif
}

/**
 * @brief Pack a radar_data message on a channel
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param timestamp timestamp (microseconds since system boot)
 * @param point_pos_x x coordinate in 10E-2m, actual [-200, +200]
 * @param point_pos_y y coordinate in 10E-2m, actual [0, +350]
 * @param point_pos_z z coordinate in 10E-2m, actual [-200, +200]
 * @param obj_vel_x x absolute velocity in 10E-2 m/s, actual [-100, +100]
 * @param obj_vel_y y absolute velocity in 10E-2 m/s, actual [-100, +100]
 * @param obj_vel_z z absolute velocity in 10E-2 m/s, actual [-100, +100]
 * @param obj_pw snr of object in 10E-2 dB, actual [-30, +30]
 * @param existing_prob tracking existing prob of object in 10E-2, actual [-0, +1]
 * @param object_num number of detected objects, maximum is 32
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_radar_data_pack_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan,
							   alink_message_head_t* msg,
						           uint32_t timestamp,const int16_t *point_pos_x,const uint16_t *point_pos_y,const int16_t *point_pos_z,const int16_t *obj_vel_x,const int16_t *obj_vel_y,const int16_t *obj_vel_z,const int16_t *obj_pw,const uint8_t *existing_prob,uint8_t object_num)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_RADAR_DATA_LEN];
	_mav_put_uint32_t(buf, 0, timestamp);
	_mav_put_uint8_t(buf, 484, object_num);
	_mav_put_int16_t_array(buf, 4, point_pos_x, 32);
	_mav_put_uint16_t_array(buf, 68, point_pos_y, 32);
	_mav_put_int16_t_array(buf, 132, point_pos_z, 32);
	_mav_put_int16_t_array(buf, 196, obj_vel_x, 32);
	_mav_put_int16_t_array(buf, 260, obj_vel_y, 32);
	_mav_put_int16_t_array(buf, 324, obj_vel_z, 32);
	_mav_put_int16_t_array(buf, 388, obj_pw, 32);
	_mav_put_uint8_t_array(buf, 452, existing_prob, 32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_RADAR_DATA_LEN);
#else
	alink_radar_data_t packet;
	packet.timestamp = timestamp;
	packet.object_num = object_num;
	mav_array_memcpy(packet.point_pos_x, point_pos_x, sizeof(int16_t)*32);
	mav_array_memcpy(packet.point_pos_y, point_pos_y, sizeof(uint16_t)*32);
	mav_array_memcpy(packet.point_pos_z, point_pos_z, sizeof(int16_t)*32);
	mav_array_memcpy(packet.obj_vel_x, obj_vel_x, sizeof(int16_t)*32);
	mav_array_memcpy(packet.obj_vel_y, obj_vel_y, sizeof(int16_t)*32);
	mav_array_memcpy(packet.obj_vel_z, obj_vel_z, sizeof(int16_t)*32);
	mav_array_memcpy(packet.obj_pw, obj_pw, sizeof(int16_t)*32);
	mav_array_memcpy(packet.existing_prob, existing_prob, sizeof(uint8_t)*32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_RADAR_DATA_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_RADAR_DATA;
#if ALINK_CRC_EXTRA
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_RADAR_DATA_LEN,ALINK_MSG_ID_RADAR_DATA_CRC);
#else
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_RADAR_DATA_LEN);
#endif
}
/**
 * @brief Encode a radar_data struct
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 * @param radar_data C-struct to read the message contents from
 */
static inline uint16_t alink_msg_radar_data_encode(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg, const alink_radar_data_t* radar_data)
{
	return alink_msg_radar_data_pack(dest_id, source_id, msg, radar_data->timestamp, radar_data->point_pos_x, radar_data->point_pos_y, radar_data->point_pos_z, radar_data->obj_vel_x, radar_data->obj_vel_y, radar_data->obj_vel_z, radar_data->obj_pw, radar_data->existing_prob, radar_data->object_num);
}

/**
 * @brief Encode a radar_data struct on a channel
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param radar_data C-struct to read the message contents from
 */
static inline uint16_t alink_msg_radar_data_encode_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan, alink_message_head_t* msg, const alink_radar_data_t* radar_data)
{
	return alink_msg_radar_data_pack_chan(dest_id, source_id, chan, msg, radar_data->timestamp, radar_data->point_pos_x, radar_data->point_pos_y, radar_data->point_pos_z, radar_data->obj_vel_x, radar_data->obj_vel_y, radar_data->obj_vel_z, radar_data->obj_pw, radar_data->existing_prob, radar_data->object_num);
}
// MESSAGE RADAR_DATA UNPACKING


/**
 * @brief Get field timestamp from radar_data message
 *
 * @return timestamp (microseconds since system boot)
 */
static inline uint32_t alink_msg_radar_data_get_timestamp(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field point_pos_x from radar_data message
 *
 * @return x coordinate in 10E-2m, actual [-200, +200]
 */
static inline uint16_t alink_msg_radar_data_get_point_pos_x(const alink_message_head_t* msg, int16_t *point_pos_x)
{
	return _MAV_RETURN_int16_t_array(msg, point_pos_x, 32,  4);
}

/**
 * @brief Get field point_pos_y from radar_data message
 *
 * @return y coordinate in 10E-2m, actual [0, +350]
 */
static inline uint16_t alink_msg_radar_data_get_point_pos_y(const alink_message_head_t* msg, uint16_t *point_pos_y)
{
	return _MAV_RETURN_uint16_t_array(msg, point_pos_y, 32,  68);
}

/**
 * @brief Get field point_pos_z from radar_data message
 *
 * @return z coordinate in 10E-2m, actual [-200, +200]
 */
static inline uint16_t alink_msg_radar_data_get_point_pos_z(const alink_message_head_t* msg, int16_t *point_pos_z)
{
	return _MAV_RETURN_int16_t_array(msg, point_pos_z, 32,  132);
}

/**
 * @brief Get field obj_vel_x from radar_data message
 *
 * @return x absolute velocity in 10E-2 m/s, actual [-100, +100]
 */
static inline uint16_t alink_msg_radar_data_get_obj_vel_x(const alink_message_head_t* msg, int16_t *obj_vel_x)
{
	return _MAV_RETURN_int16_t_array(msg, obj_vel_x, 32,  196);
}

/**
 * @brief Get field obj_vel_y from radar_data message
 *
 * @return y absolute velocity in 10E-2 m/s, actual [-100, +100]
 */
static inline uint16_t alink_msg_radar_data_get_obj_vel_y(const alink_message_head_t* msg, int16_t *obj_vel_y)
{
	return _MAV_RETURN_int16_t_array(msg, obj_vel_y, 32,  260);
}

/**
 * @brief Get field obj_vel_z from radar_data message
 *
 * @return z absolute velocity in 10E-2 m/s, actual [-100, +100]
 */
static inline uint16_t alink_msg_radar_data_get_obj_vel_z(const alink_message_head_t* msg, int16_t *obj_vel_z)
{
	return _MAV_RETURN_int16_t_array(msg, obj_vel_z, 32,  324);
}

/**
 * @brief Get field obj_pw from radar_data message
 *
 * @return snr of object in 10E-2 dB, actual [-30, +30]
 */
static inline uint16_t alink_msg_radar_data_get_obj_pw(const alink_message_head_t* msg, int16_t *obj_pw)
{
	return _MAV_RETURN_int16_t_array(msg, obj_pw, 32,  388);
}

/**
 * @brief Get field existing_prob from radar_data message
 *
 * @return tracking existing prob of object in 10E-2, actual [-0, +1]
 */
static inline uint16_t alink_msg_radar_data_get_existing_prob(const alink_message_head_t* msg, uint8_t *existing_prob)
{
	return _MAV_RETURN_uint8_t_array(msg, existing_prob, 32,  452);
}

/**
 * @brief Get field object_num from radar_data message
 *
 * @return number of detected objects, maximum is 32
 */
static inline uint8_t alink_msg_radar_data_get_object_num(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  484);
}

/**
 * @brief Decode a radar_data message into a struct
 *
 * @param msg The message to decode
 * @param radar_data C-struct to decode the message contents into
 */
static inline void alink_msg_radar_data_decode(const alink_message_head_t* msg, alink_radar_data_t* radar_data)
{
#if ALINK_NEED_BYTE_SWAP
	radar_data->timestamp = alink_msg_radar_data_get_timestamp(msg);
	alink_msg_radar_data_get_point_pos_x(msg, radar_data->point_pos_x);
	alink_msg_radar_data_get_point_pos_y(msg, radar_data->point_pos_y);
	alink_msg_radar_data_get_point_pos_z(msg, radar_data->point_pos_z);
	alink_msg_radar_data_get_obj_vel_x(msg, radar_data->obj_vel_x);
	alink_msg_radar_data_get_obj_vel_y(msg, radar_data->obj_vel_y);
	alink_msg_radar_data_get_obj_vel_z(msg, radar_data->obj_vel_z);
	alink_msg_radar_data_get_obj_pw(msg, radar_data->obj_pw);
	alink_msg_radar_data_get_existing_prob(msg, radar_data->existing_prob);
	radar_data->object_num = alink_msg_radar_data_get_object_num(msg);
#else
	memcpy(radar_data, _MAV_PAYLOAD(msg), ALINK_MSG_ID_RADAR_DATA_LEN);
#endif
}
