// MESSAGE RADAR_UAV_DATA PACKING

#define ALINK_MSG_ID_RADAR_UAV_DATA 159

typedef struct __alink_radar_uav_data_t
{
 uint32_t timestamp; /*< timestamp (microseconds since system boot)*/
 float att[4]; /*< attitude of uav quaternion*/
 int32_t rel_hight; /*< relative hight in 10E-2 m*/
 int16_t acc[3]; /*< acceleration x/y/z in 10E-2 m^2/s*/
 int16_t gyr[3]; /*< gyroscope x/y/z in 10E-3 rad/s*/
 int16_t vel_ned_est[3]; /*< N/E/D estimated velocity in 10E-3 m/s*/
 int16_t gimbal_angle[3]; /*< gimbal: three axis angle x/y/z in 10E-3 rad*/
} alink_radar_uav_data_t;

#define ALINK_MSG_ID_RADAR_UAV_DATA_LEN 48
#define ALINK_MSG_ID_159_LEN 48

#define ALINK_MSG_ID_RADAR_UAV_DATA_CRC 195
#define ALINK_MSG_ID_159_CRC 195

#define ALINK_MSG_RADAR_UAV_DATA_FIELD_ATT_LEN 4
#define ALINK_MSG_RADAR_UAV_DATA_FIELD_ACC_LEN 3
#define ALINK_MSG_RADAR_UAV_DATA_FIELD_GYR_LEN 3
#define ALINK_MSG_RADAR_UAV_DATA_FIELD_VEL_NED_EST_LEN 3
#define ALINK_MSG_RADAR_UAV_DATA_FIELD_GIMBAL_ANGLE_LEN 3

#define ALINK_MESSAGE_INFO_RADAR_UAV_DATA { \
	"RADAR_UAV_DATA", \
	7, \
	{  { "timestamp", NULL, ALINK_TYPE_UINT32_T, 0, 0, offsetof(alink_radar_uav_data_t, timestamp) }, \
         { "att", NULL, ALINK_TYPE_FLOAT, 4, 4, offsetof(alink_radar_uav_data_t, att) }, \
         { "rel_hight", NULL, ALINK_TYPE_INT32_T, 0, 20, offsetof(alink_radar_uav_data_t, rel_hight) }, \
         { "acc", NULL, ALINK_TYPE_INT16_T, 3, 24, offsetof(alink_radar_uav_data_t, acc) }, \
         { "gyr", NULL, ALINK_TYPE_INT16_T, 3, 30, offsetof(alink_radar_uav_data_t, gyr) }, \
         { "vel_ned_est", NULL, ALINK_TYPE_INT16_T, 3, 36, offsetof(alink_radar_uav_data_t, vel_ned_est) }, \
         { "gimbal_angle", NULL, ALINK_TYPE_INT16_T, 3, 42, offsetof(alink_radar_uav_data_t, gimbal_angle) }, \
         } \
}


/**
 * @brief Pack a radar_uav_data message
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 *
 * @param timestamp timestamp (microseconds since system boot)
 * @param att attitude of uav quaternion
 * @param acc acceleration x/y/z in 10E-2 m^2/s
 * @param gyr gyroscope x/y/z in 10E-3 rad/s
 * @param vel_ned_est N/E/D estimated velocity in 10E-3 m/s
 * @param gimbal_angle gimbal: three axis angle x/y/z in 10E-3 rad
 * @param rel_hight relative hight in 10E-2 m
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_radar_uav_data_pack(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg,
						       uint32_t timestamp, const float *att, const int16_t *acc, const int16_t *gyr, const int16_t *vel_ned_est, const int16_t *gimbal_angle, int32_t rel_hight)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_RADAR_UAV_DATA_LEN];
	_mav_put_uint32_t(buf, 0, timestamp);
	_mav_put_int32_t(buf, 20, rel_hight);
	_mav_put_float_array(buf, 4, att, 4);
	_mav_put_int16_t_array(buf, 24, acc, 3);
	_mav_put_int16_t_array(buf, 30, gyr, 3);
	_mav_put_int16_t_array(buf, 36, vel_ned_est, 3);
	_mav_put_int16_t_array(buf, 42, gimbal_angle, 3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_RADAR_UAV_DATA_LEN);
#else
	alink_radar_uav_data_t packet;
	packet.timestamp = timestamp;
	packet.rel_hight = rel_hight;
	mav_array_memcpy(packet.att, att, sizeof(float)*4);
	mav_array_memcpy(packet.acc, acc, sizeof(int16_t)*3);
	mav_array_memcpy(packet.gyr, gyr, sizeof(int16_t)*3);
	mav_array_memcpy(packet.vel_ned_est, vel_ned_est, sizeof(int16_t)*3);
	mav_array_memcpy(packet.gimbal_angle, gimbal_angle, sizeof(int16_t)*3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_RADAR_UAV_DATA_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_RADAR_UAV_DATA;
#if ALINK_CRC_EXTRA
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_RADAR_UAV_DATA_LEN,ALINK_MSG_ID_RADAR_UAV_DATA_CRC);
#else
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_RADAR_UAV_DATA_LEN);
#endif
}

/**
 * @brief Pack a radar_uav_data message on a channel
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param timestamp timestamp (microseconds since system boot)
 * @param att attitude of uav quaternion
 * @param acc acceleration x/y/z in 10E-2 m^2/s
 * @param gyr gyroscope x/y/z in 10E-3 rad/s
 * @param vel_ned_est N/E/D estimated velocity in 10E-3 m/s
 * @param gimbal_angle gimbal: three axis angle x/y/z in 10E-3 rad
 * @param rel_hight relative hight in 10E-2 m
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_radar_uav_data_pack_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan,
							   alink_message_head_t* msg,
						           uint32_t timestamp,const float *att,const int16_t *acc,const int16_t *gyr,const int16_t *vel_ned_est,const int16_t *gimbal_angle,int32_t rel_hight)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_RADAR_UAV_DATA_LEN];
	_mav_put_uint32_t(buf, 0, timestamp);
	_mav_put_int32_t(buf, 20, rel_hight);
	_mav_put_float_array(buf, 4, att, 4);
	_mav_put_int16_t_array(buf, 24, acc, 3);
	_mav_put_int16_t_array(buf, 30, gyr, 3);
	_mav_put_int16_t_array(buf, 36, vel_ned_est, 3);
	_mav_put_int16_t_array(buf, 42, gimbal_angle, 3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_RADAR_UAV_DATA_LEN);
#else
	alink_radar_uav_data_t packet;
	packet.timestamp = timestamp;
	packet.rel_hight = rel_hight;
	mav_array_memcpy(packet.att, att, sizeof(float)*4);
	mav_array_memcpy(packet.acc, acc, sizeof(int16_t)*3);
	mav_array_memcpy(packet.gyr, gyr, sizeof(int16_t)*3);
	mav_array_memcpy(packet.vel_ned_est, vel_ned_est, sizeof(int16_t)*3);
	mav_array_memcpy(packet.gimbal_angle, gimbal_angle, sizeof(int16_t)*3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_RADAR_UAV_DATA_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_RADAR_UAV_DATA;
#if ALINK_CRC_EXTRA
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_RADAR_UAV_DATA_LEN,ALINK_MSG_ID_RADAR_UAV_DATA_CRC);
#else
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_RADAR_UAV_DATA_LEN);
#endif
}
/**
 * @brief Encode a radar_uav_data struct
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 * @param radar_uav_data C-struct to read the message contents from
 */
static inline uint16_t alink_msg_radar_uav_data_encode(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg, const alink_radar_uav_data_t* radar_uav_data)
{
	return alink_msg_radar_uav_data_pack(dest_id, source_id, msg, radar_uav_data->timestamp, radar_uav_data->att, radar_uav_data->acc, radar_uav_data->gyr, radar_uav_data->vel_ned_est, radar_uav_data->gimbal_angle, radar_uav_data->rel_hight);
}

/**
 * @brief Encode a radar_uav_data struct on a channel
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param radar_uav_data C-struct to read the message contents from
 */
static inline uint16_t alink_msg_radar_uav_data_encode_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan, alink_message_head_t* msg, const alink_radar_uav_data_t* radar_uav_data)
{
	return alink_msg_radar_uav_data_pack_chan(dest_id, source_id, chan, msg, radar_uav_data->timestamp, radar_uav_data->att, radar_uav_data->acc, radar_uav_data->gyr, radar_uav_data->vel_ned_est, radar_uav_data->gimbal_angle, radar_uav_data->rel_hight);
}
// MESSAGE RADAR_UAV_DATA UNPACKING


/**
 * @brief Get field timestamp from radar_uav_data message
 *
 * @return timestamp (microseconds since system boot)
 */
static inline uint32_t alink_msg_radar_uav_data_get_timestamp(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field att from radar_uav_data message
 *
 * @return attitude of uav quaternion
 */
static inline uint16_t alink_msg_radar_uav_data_get_att(const alink_message_head_t* msg, float *att)
{
	return _MAV_RETURN_float_array(msg, att, 4,  4);
}

/**
 * @brief Get field acc from radar_uav_data message
 *
 * @return acceleration x/y/z in 10E-2 m^2/s
 */
static inline uint16_t alink_msg_radar_uav_data_get_acc(const alink_message_head_t* msg, int16_t *acc)
{
	return _MAV_RETURN_int16_t_array(msg, acc, 3,  24);
}

/**
 * @brief Get field gyr from radar_uav_data message
 *
 * @return gyroscope x/y/z in 10E-3 rad/s
 */
static inline uint16_t alink_msg_radar_uav_data_get_gyr(const alink_message_head_t* msg, int16_t *gyr)
{
	return _MAV_RETURN_int16_t_array(msg, gyr, 3,  30);
}

/**
 * @brief Get field vel_ned_est from radar_uav_data message
 *
 * @return N/E/D estimated velocity in 10E-3 m/s
 */
static inline uint16_t alink_msg_radar_uav_data_get_vel_ned_est(const alink_message_head_t* msg, int16_t *vel_ned_est)
{
	return _MAV_RETURN_int16_t_array(msg, vel_ned_est, 3,  36);
}

/**
 * @brief Get field gimbal_angle from radar_uav_data message
 *
 * @return gimbal: three axis angle x/y/z in 10E-3 rad
 */
static inline uint16_t alink_msg_radar_uav_data_get_gimbal_angle(const alink_message_head_t* msg, int16_t *gimbal_angle)
{
	return _MAV_RETURN_int16_t_array(msg, gimbal_angle, 3,  42);
}

/**
 * @brief Get field rel_hight from radar_uav_data message
 *
 * @return relative hight in 10E-2 m
 */
static inline int32_t alink_msg_radar_uav_data_get_rel_hight(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  20);
}

/**
 * @brief Decode a radar_uav_data message into a struct
 *
 * @param msg The message to decode
 * @param radar_uav_data C-struct to decode the message contents into
 */
static inline void alink_msg_radar_uav_data_decode(const alink_message_head_t* msg, alink_radar_uav_data_t* radar_uav_data)
{
#if ALINK_NEED_BYTE_SWAP
	radar_uav_data->timestamp = alink_msg_radar_uav_data_get_timestamp(msg);
	alink_msg_radar_uav_data_get_att(msg, radar_uav_data->att);
	radar_uav_data->rel_hight = alink_msg_radar_uav_data_get_rel_hight(msg);
	alink_msg_radar_uav_data_get_acc(msg, radar_uav_data->acc);
	alink_msg_radar_uav_data_get_gyr(msg, radar_uav_data->gyr);
	alink_msg_radar_uav_data_get_vel_ned_est(msg, radar_uav_data->vel_ned_est);
	alink_msg_radar_uav_data_get_gimbal_angle(msg, radar_uav_data->gimbal_angle);
#else
	memcpy(radar_uav_data, _MAV_PAYLOAD(msg), ALINK_MSG_ID_RADAR_UAV_DATA_LEN);
#endif
}
