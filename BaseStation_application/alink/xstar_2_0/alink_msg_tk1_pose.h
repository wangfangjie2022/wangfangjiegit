// MESSAGE TK1_POSE PACKING

#define ALINK_MSG_ID_TK1_POSE 99

typedef struct __alink_tk1_pose_t
{
 uint64_t timestamp; /*< timestamp one*/
 float pos[3]; /*< position*/
 float vel[3]; /*< vel*/
 float rpy[3]; /*< rpy*/
} alink_tk1_pose_t;

#define ALINK_MSG_ID_TK1_POSE_LEN 44
#define ALINK_MSG_ID_99_LEN 44

#define ALINK_MSG_ID_TK1_POSE_CRC 164
#define ALINK_MSG_ID_99_CRC 164

#define ALINK_MSG_TK1_POSE_FIELD_POS_LEN 3
#define ALINK_MSG_TK1_POSE_FIELD_VEL_LEN 3
#define ALINK_MSG_TK1_POSE_FIELD_RPY_LEN 3

#define ALINK_MESSAGE_INFO_TK1_POSE { \
	"TK1_POSE", \
	4, \
	{  { "timestamp", NULL, ALINK_TYPE_UINT64_T, 0, 0, offsetof(alink_tk1_pose_t, timestamp) }, \
         { "pos", NULL, ALINK_TYPE_FLOAT, 3, 8, offsetof(alink_tk1_pose_t, pos) }, \
         { "vel", NULL, ALINK_TYPE_FLOAT, 3, 20, offsetof(alink_tk1_pose_t, vel) }, \
         { "rpy", NULL, ALINK_TYPE_FLOAT, 3, 32, offsetof(alink_tk1_pose_t, rpy) }, \
         } \
}


/**
 * @brief Pack a tk1_pose message
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 *
 * @param timestamp timestamp one
 * @param pos position
 * @param vel vel
 * @param rpy rpy
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_tk1_pose_pack(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg,
						       uint64_t timestamp, const float *pos, const float *vel, const float *rpy)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_TK1_POSE_LEN];
	_mav_put_uint64_t(buf, 0, timestamp);
	_mav_put_float_array(buf, 8, pos, 3);
	_mav_put_float_array(buf, 20, vel, 3);
	_mav_put_float_array(buf, 32, rpy, 3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_TK1_POSE_LEN);
#else
	alink_tk1_pose_t packet;
	packet.timestamp = timestamp;
	mav_array_memcpy(packet.pos, pos, sizeof(float)*3);
	mav_array_memcpy(packet.vel, vel, sizeof(float)*3);
	mav_array_memcpy(packet.rpy, rpy, sizeof(float)*3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_TK1_POSE_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_TK1_POSE;
#if ALINK_CRC_EXTRA
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_TK1_POSE_LEN,ALINK_MSG_ID_TK1_POSE_CRC);
#else
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_TK1_POSE_LEN);
#endif
}

/**
 * @brief Pack a tk1_pose message on a channel
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param timestamp timestamp one
 * @param pos position
 * @param vel vel
 * @param rpy rpy
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_tk1_pose_pack_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan,
							   alink_message_head_t* msg,
						           uint64_t timestamp,const float *pos,const float *vel,const float *rpy)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_TK1_POSE_LEN];
	_mav_put_uint64_t(buf, 0, timestamp);
	_mav_put_float_array(buf, 8, pos, 3);
	_mav_put_float_array(buf, 20, vel, 3);
	_mav_put_float_array(buf, 32, rpy, 3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_TK1_POSE_LEN);
#else
	alink_tk1_pose_t packet;
	packet.timestamp = timestamp;
	mav_array_memcpy(packet.pos, pos, sizeof(float)*3);
	mav_array_memcpy(packet.vel, vel, sizeof(float)*3);
	mav_array_memcpy(packet.rpy, rpy, sizeof(float)*3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_TK1_POSE_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_TK1_POSE;
#if ALINK_CRC_EXTRA
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_TK1_POSE_LEN,ALINK_MSG_ID_TK1_POSE_CRC);
#else
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_TK1_POSE_LEN);
#endif
}
/**
 * @brief Encode a tk1_pose struct
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 * @param tk1_pose C-struct to read the message contents from
 */
static inline uint16_t alink_msg_tk1_pose_encode(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg, const alink_tk1_pose_t* tk1_pose)
{
	return alink_msg_tk1_pose_pack(dest_id, source_id, msg, tk1_pose->timestamp, tk1_pose->pos, tk1_pose->vel, tk1_pose->rpy);
}

/**
 * @brief Encode a tk1_pose struct on a channel
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param tk1_pose C-struct to read the message contents from
 */
static inline uint16_t alink_msg_tk1_pose_encode_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan, alink_message_head_t* msg, const alink_tk1_pose_t* tk1_pose)
{
	return alink_msg_tk1_pose_pack_chan(dest_id, source_id, chan, msg, tk1_pose->timestamp, tk1_pose->pos, tk1_pose->vel, tk1_pose->rpy);
}
// MESSAGE TK1_POSE UNPACKING


/**
 * @brief Get field timestamp from tk1_pose message
 *
 * @return timestamp one
 */
static inline uint64_t alink_msg_tk1_pose_get_timestamp(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field pos from tk1_pose message
 *
 * @return position
 */
static inline uint16_t alink_msg_tk1_pose_get_pos(const alink_message_head_t* msg, float *pos)
{
	return _MAV_RETURN_float_array(msg, pos, 3,  8);
}

/**
 * @brief Get field vel from tk1_pose message
 *
 * @return vel
 */
static inline uint16_t alink_msg_tk1_pose_get_vel(const alink_message_head_t* msg, float *vel)
{
	return _MAV_RETURN_float_array(msg, vel, 3,  20);
}

/**
 * @brief Get field rpy from tk1_pose message
 *
 * @return rpy
 */
static inline uint16_t alink_msg_tk1_pose_get_rpy(const alink_message_head_t* msg, float *rpy)
{
	return _MAV_RETURN_float_array(msg, rpy, 3,  32);
}

/**
 * @brief Decode a tk1_pose message into a struct
 *
 * @param msg The message to decode
 * @param tk1_pose C-struct to decode the message contents into
 */
static inline void alink_msg_tk1_pose_decode(const alink_message_head_t* msg, alink_tk1_pose_t* tk1_pose)
{
#if ALINK_NEED_BYTE_SWAP
	tk1_pose->timestamp = alink_msg_tk1_pose_get_timestamp(msg);
	alink_msg_tk1_pose_get_pos(msg, tk1_pose->pos);
	alink_msg_tk1_pose_get_vel(msg, tk1_pose->vel);
	alink_msg_tk1_pose_get_rpy(msg, tk1_pose->rpy);
#else
	memcpy(tk1_pose, _MAV_PAYLOAD(msg), ALINK_MSG_ID_TK1_POSE_LEN);
#endif
}
