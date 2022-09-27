// MESSAGE VISION_ATTITUDE PACKING

#define ALINK_MSG_ID_VISION_ATTITUDE 70

typedef struct __alink_vision_attitude_t
{
 uint32_t timestamp; /*< timestamp (milliseconds  since system boot)*/
 int16_t q_uav[4]; /*< UAV Quarternion q0(w),q1(x),q2(y),q3(z)*/
 int16_t gimbal_roll; /*< Gimbal Roll angle in 10E-2 deg*/
 int16_t gimbal_pitch; /*< Gimbal Pitch angle in 10E-2 deg*/
 int16_t gimbal_yaw; /*< Gimbal Yaw angle in 10E-2 deg*/
 int16_t reseved; /*< Dont use now*/
 int16_t acc[3]; /*< acceleration x/y/z in 10E-2 m^2/s*/
 int16_t gyr[3]; /*< gyroscope x/y/z in 10E-3 rad/s*/
} alink_vision_attitude_t;

#define ALINK_MSG_ID_VISION_ATTITUDE_LEN 32
#define ALINK_MSG_ID_70_LEN 32

#define ALINK_MSG_ID_VISION_ATTITUDE_CRC 62
#define ALINK_MSG_ID_70_CRC 62

#define ALINK_MSG_VISION_ATTITUDE_FIELD_Q_UAV_LEN 4
#define ALINK_MSG_VISION_ATTITUDE_FIELD_ACC_LEN 3
#define ALINK_MSG_VISION_ATTITUDE_FIELD_GYR_LEN 3

#define ALINK_MESSAGE_INFO_VISION_ATTITUDE { \
	"VISION_ATTITUDE", \
	8, \
	{  { "timestamp", NULL, ALINK_TYPE_UINT32_T, 0, 0, offsetof(alink_vision_attitude_t, timestamp) }, \
         { "q_uav", NULL, ALINK_TYPE_INT16_T, 4, 4, offsetof(alink_vision_attitude_t, q_uav) }, \
         { "gimbal_roll", NULL, ALINK_TYPE_INT16_T, 0, 12, offsetof(alink_vision_attitude_t, gimbal_roll) }, \
         { "gimbal_pitch", NULL, ALINK_TYPE_INT16_T, 0, 14, offsetof(alink_vision_attitude_t, gimbal_pitch) }, \
         { "gimbal_yaw", NULL, ALINK_TYPE_INT16_T, 0, 16, offsetof(alink_vision_attitude_t, gimbal_yaw) }, \
         { "reseved", NULL, ALINK_TYPE_INT16_T, 0, 18, offsetof(alink_vision_attitude_t, reseved) }, \
         { "acc", NULL, ALINK_TYPE_INT16_T, 3, 20, offsetof(alink_vision_attitude_t, acc) }, \
         { "gyr", NULL, ALINK_TYPE_INT16_T, 3, 26, offsetof(alink_vision_attitude_t, gyr) }, \
         } \
}


/**
 * @brief Pack a vision_attitude message
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 *
 * @param timestamp timestamp (milliseconds  since system boot)
 * @param q_uav UAV Quarternion q0(w),q1(x),q2(y),q3(z)
 * @param gimbal_roll Gimbal Roll angle in 10E-2 deg
 * @param gimbal_pitch Gimbal Pitch angle in 10E-2 deg
 * @param gimbal_yaw Gimbal Yaw angle in 10E-2 deg
 * @param reseved Dont use now
 * @param acc acceleration x/y/z in 10E-2 m^2/s
 * @param gyr gyroscope x/y/z in 10E-3 rad/s
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_vision_attitude_pack(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg,
						       uint32_t timestamp, const int16_t *q_uav, int16_t gimbal_roll, int16_t gimbal_pitch, int16_t gimbal_yaw, int16_t reseved, const int16_t *acc, const int16_t *gyr)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_VISION_ATTITUDE_LEN];
	_mav_put_uint32_t(buf, 0, timestamp);
	_mav_put_int16_t(buf, 12, gimbal_roll);
	_mav_put_int16_t(buf, 14, gimbal_pitch);
	_mav_put_int16_t(buf, 16, gimbal_yaw);
	_mav_put_int16_t(buf, 18, reseved);
	_mav_put_int16_t_array(buf, 4, q_uav, 4);
	_mav_put_int16_t_array(buf, 20, acc, 3);
	_mav_put_int16_t_array(buf, 26, gyr, 3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_VISION_ATTITUDE_LEN);
#else
	alink_vision_attitude_t packet;
	packet.timestamp = timestamp;
	packet.gimbal_roll = gimbal_roll;
	packet.gimbal_pitch = gimbal_pitch;
	packet.gimbal_yaw = gimbal_yaw;
	packet.reseved = reseved;
	mav_array_memcpy(packet.q_uav, q_uav, sizeof(int16_t)*4);
	mav_array_memcpy(packet.acc, acc, sizeof(int16_t)*3);
	mav_array_memcpy(packet.gyr, gyr, sizeof(int16_t)*3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_VISION_ATTITUDE_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_VISION_ATTITUDE;
#if ALINK_CRC_EXTRA
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_VISION_ATTITUDE_LEN,ALINK_MSG_ID_VISION_ATTITUDE_CRC);
#else
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_VISION_ATTITUDE_LEN);
#endif
}

/**
 * @brief Pack a vision_attitude message on a channel
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param timestamp timestamp (milliseconds  since system boot)
 * @param q_uav UAV Quarternion q0(w),q1(x),q2(y),q3(z)
 * @param gimbal_roll Gimbal Roll angle in 10E-2 deg
 * @param gimbal_pitch Gimbal Pitch angle in 10E-2 deg
 * @param gimbal_yaw Gimbal Yaw angle in 10E-2 deg
 * @param reseved Dont use now
 * @param acc acceleration x/y/z in 10E-2 m^2/s
 * @param gyr gyroscope x/y/z in 10E-3 rad/s
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_vision_attitude_pack_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan,
							   alink_message_head_t* msg,
						           uint32_t timestamp,const int16_t *q_uav,int16_t gimbal_roll,int16_t gimbal_pitch,int16_t gimbal_yaw,int16_t reseved,const int16_t *acc,const int16_t *gyr)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_VISION_ATTITUDE_LEN];
	_mav_put_uint32_t(buf, 0, timestamp);
	_mav_put_int16_t(buf, 12, gimbal_roll);
	_mav_put_int16_t(buf, 14, gimbal_pitch);
	_mav_put_int16_t(buf, 16, gimbal_yaw);
	_mav_put_int16_t(buf, 18, reseved);
	_mav_put_int16_t_array(buf, 4, q_uav, 4);
	_mav_put_int16_t_array(buf, 20, acc, 3);
	_mav_put_int16_t_array(buf, 26, gyr, 3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_VISION_ATTITUDE_LEN);
#else
	alink_vision_attitude_t packet;
	packet.timestamp = timestamp;
	packet.gimbal_roll = gimbal_roll;
	packet.gimbal_pitch = gimbal_pitch;
	packet.gimbal_yaw = gimbal_yaw;
	packet.reseved = reseved;
	mav_array_memcpy(packet.q_uav, q_uav, sizeof(int16_t)*4);
	mav_array_memcpy(packet.acc, acc, sizeof(int16_t)*3);
	mav_array_memcpy(packet.gyr, gyr, sizeof(int16_t)*3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_VISION_ATTITUDE_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_VISION_ATTITUDE;
#if ALINK_CRC_EXTRA
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_VISION_ATTITUDE_LEN,ALINK_MSG_ID_VISION_ATTITUDE_CRC);
#else
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_VISION_ATTITUDE_LEN);
#endif
}
/**
 * @brief Encode a vision_attitude struct
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 * @param vision_attitude C-struct to read the message contents from
 */
static inline uint16_t alink_msg_vision_attitude_encode(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg, const alink_vision_attitude_t* vision_attitude)
{
	return alink_msg_vision_attitude_pack(dest_id, source_id, msg, vision_attitude->timestamp, vision_attitude->q_uav, vision_attitude->gimbal_roll, vision_attitude->gimbal_pitch, vision_attitude->gimbal_yaw, vision_attitude->reseved, vision_attitude->acc, vision_attitude->gyr);
}

/**
 * @brief Encode a vision_attitude struct on a channel
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param vision_attitude C-struct to read the message contents from
 */
static inline uint16_t alink_msg_vision_attitude_encode_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan, alink_message_head_t* msg, const alink_vision_attitude_t* vision_attitude)
{
	return alink_msg_vision_attitude_pack_chan(dest_id, source_id, chan, msg, vision_attitude->timestamp, vision_attitude->q_uav, vision_attitude->gimbal_roll, vision_attitude->gimbal_pitch, vision_attitude->gimbal_yaw, vision_attitude->reseved, vision_attitude->acc, vision_attitude->gyr);
}
// MESSAGE VISION_ATTITUDE UNPACKING


/**
 * @brief Get field timestamp from vision_attitude message
 *
 * @return timestamp (milliseconds  since system boot)
 */
static inline uint32_t alink_msg_vision_attitude_get_timestamp(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field q_uav from vision_attitude message
 *
 * @return UAV Quarternion q0(w),q1(x),q2(y),q3(z)
 */
static inline uint16_t alink_msg_vision_attitude_get_q_uav(const alink_message_head_t* msg, int16_t *q_uav)
{
	return _MAV_RETURN_int16_t_array(msg, q_uav, 4,  4);
}

/**
 * @brief Get field gimbal_roll from vision_attitude message
 *
 * @return Gimbal Roll angle in 10E-2 deg
 */
static inline int16_t alink_msg_vision_attitude_get_gimbal_roll(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  12);
}

/**
 * @brief Get field gimbal_pitch from vision_attitude message
 *
 * @return Gimbal Pitch angle in 10E-2 deg
 */
static inline int16_t alink_msg_vision_attitude_get_gimbal_pitch(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  14);
}

/**
 * @brief Get field gimbal_yaw from vision_attitude message
 *
 * @return Gimbal Yaw angle in 10E-2 deg
 */
static inline int16_t alink_msg_vision_attitude_get_gimbal_yaw(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  16);
}

/**
 * @brief Get field reseved from vision_attitude message
 *
 * @return Dont use now
 */
static inline int16_t alink_msg_vision_attitude_get_reseved(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  18);
}

/**
 * @brief Get field acc from vision_attitude message
 *
 * @return acceleration x/y/z in 10E-2 m^2/s
 */
static inline uint16_t alink_msg_vision_attitude_get_acc(const alink_message_head_t* msg, int16_t *acc)
{
	return _MAV_RETURN_int16_t_array(msg, acc, 3,  20);
}

/**
 * @brief Get field gyr from vision_attitude message
 *
 * @return gyroscope x/y/z in 10E-3 rad/s
 */
static inline uint16_t alink_msg_vision_attitude_get_gyr(const alink_message_head_t* msg, int16_t *gyr)
{
	return _MAV_RETURN_int16_t_array(msg, gyr, 3,  26);
}

/**
 * @brief Decode a vision_attitude message into a struct
 *
 * @param msg The message to decode
 * @param vision_attitude C-struct to decode the message contents into
 */
static inline void alink_msg_vision_attitude_decode(const alink_message_head_t* msg, alink_vision_attitude_t* vision_attitude)
{
#if ALINK_NEED_BYTE_SWAP
	vision_attitude->timestamp = alink_msg_vision_attitude_get_timestamp(msg);
	alink_msg_vision_attitude_get_q_uav(msg, vision_attitude->q_uav);
	vision_attitude->gimbal_roll = alink_msg_vision_attitude_get_gimbal_roll(msg);
	vision_attitude->gimbal_pitch = alink_msg_vision_attitude_get_gimbal_pitch(msg);
	vision_attitude->gimbal_yaw = alink_msg_vision_attitude_get_gimbal_yaw(msg);
	vision_attitude->reseved = alink_msg_vision_attitude_get_reseved(msg);
	alink_msg_vision_attitude_get_acc(msg, vision_attitude->acc);
	alink_msg_vision_attitude_get_gyr(msg, vision_attitude->gyr);
#else
	memcpy(vision_attitude, _MAV_PAYLOAD(msg), ALINK_MSG_ID_VISION_ATTITUDE_LEN);
#endif
}
