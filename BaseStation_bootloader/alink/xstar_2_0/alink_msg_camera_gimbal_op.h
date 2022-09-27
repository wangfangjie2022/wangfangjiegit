// MESSAGE CAMERA_GIMBAL_OP PACKING

#define ALINK_MSG_ID_CAMERA_GIMBAL_OP 102

typedef struct __alink_camera_gimbal_op_t
{
 int32_t step_angle; /*< step angle*/
 int32_t total_angle; /*< total angle*/
 int32_t current_step; /*< current_step*/
 int32_t total_step; /*< total step*/
 uint8_t operate; /*< 0:EnterPanorama, 1:ExitPanorama, 2:SetSpinAngle*/
} alink_camera_gimbal_op_t;

#define ALINK_MSG_ID_CAMERA_GIMBAL_OP_LEN 17
#define ALINK_MSG_ID_102_LEN 17

#define ALINK_MSG_ID_CAMERA_GIMBAL_OP_CRC 249
#define ALINK_MSG_ID_102_CRC 249



#define ALINK_MESSAGE_INFO_CAMERA_GIMBAL_OP { \
	"CAMERA_GIMBAL_OP", \
	5, \
	{  { "step_angle", NULL, ALINK_TYPE_INT32_T, 0, 0, offsetof(alink_camera_gimbal_op_t, step_angle) }, \
         { "total_angle", NULL, ALINK_TYPE_INT32_T, 0, 4, offsetof(alink_camera_gimbal_op_t, total_angle) }, \
         { "current_step", NULL, ALINK_TYPE_INT32_T, 0, 8, offsetof(alink_camera_gimbal_op_t, current_step) }, \
         { "total_step", NULL, ALINK_TYPE_INT32_T, 0, 12, offsetof(alink_camera_gimbal_op_t, total_step) }, \
         { "operate", NULL, ALINK_TYPE_UINT8_T, 0, 16, offsetof(alink_camera_gimbal_op_t, operate) }, \
         } \
}


/**
 * @brief Pack a camera_gimbal_op message
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 *
 * @param operate 0:EnterPanorama, 1:ExitPanorama, 2:SetSpinAngle
 * @param step_angle step angle
 * @param total_angle total angle
 * @param current_step current_step
 * @param total_step total step
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_camera_gimbal_op_pack(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg,
						       uint8_t operate, int32_t step_angle, int32_t total_angle, int32_t current_step, int32_t total_step)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_CAMERA_GIMBAL_OP_LEN];
	_mav_put_int32_t(buf, 0, step_angle);
	_mav_put_int32_t(buf, 4, total_angle);
	_mav_put_int32_t(buf, 8, current_step);
	_mav_put_int32_t(buf, 12, total_step);
	_mav_put_uint8_t(buf, 16, operate);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_CAMERA_GIMBAL_OP_LEN);
#else
	alink_camera_gimbal_op_t packet;
	packet.step_angle = step_angle;
	packet.total_angle = total_angle;
	packet.current_step = current_step;
	packet.total_step = total_step;
	packet.operate = operate;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_CAMERA_GIMBAL_OP_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_CAMERA_GIMBAL_OP;
#if ALINK_CRC_EXTRA
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_CAMERA_GIMBAL_OP_LEN,ALINK_MSG_ID_CAMERA_GIMBAL_OP_CRC);
#else
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_CAMERA_GIMBAL_OP_LEN);
#endif
}

/**
 * @brief Pack a camera_gimbal_op message on a channel
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param operate 0:EnterPanorama, 1:ExitPanorama, 2:SetSpinAngle
 * @param step_angle step angle
 * @param total_angle total angle
 * @param current_step current_step
 * @param total_step total step
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_camera_gimbal_op_pack_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan,
							   alink_message_head_t* msg,
						           uint8_t operate,int32_t step_angle,int32_t total_angle,int32_t current_step,int32_t total_step)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_CAMERA_GIMBAL_OP_LEN];
	_mav_put_int32_t(buf, 0, step_angle);
	_mav_put_int32_t(buf, 4, total_angle);
	_mav_put_int32_t(buf, 8, current_step);
	_mav_put_int32_t(buf, 12, total_step);
	_mav_put_uint8_t(buf, 16, operate);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_CAMERA_GIMBAL_OP_LEN);
#else
	alink_camera_gimbal_op_t packet;
	packet.step_angle = step_angle;
	packet.total_angle = total_angle;
	packet.current_step = current_step;
	packet.total_step = total_step;
	packet.operate = operate;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_CAMERA_GIMBAL_OP_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_CAMERA_GIMBAL_OP;
#if ALINK_CRC_EXTRA
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_CAMERA_GIMBAL_OP_LEN,ALINK_MSG_ID_CAMERA_GIMBAL_OP_CRC);
#else
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_CAMERA_GIMBAL_OP_LEN);
#endif
}
/**
 * @brief Encode a camera_gimbal_op struct
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 * @param camera_gimbal_op C-struct to read the message contents from
 */
static inline uint16_t alink_msg_camera_gimbal_op_encode(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg, const alink_camera_gimbal_op_t* camera_gimbal_op)
{
	return alink_msg_camera_gimbal_op_pack(dest_id, source_id, msg, camera_gimbal_op->operate, camera_gimbal_op->step_angle, camera_gimbal_op->total_angle, camera_gimbal_op->current_step, camera_gimbal_op->total_step);
}

/**
 * @brief Encode a camera_gimbal_op struct on a channel
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param camera_gimbal_op C-struct to read the message contents from
 */
static inline uint16_t alink_msg_camera_gimbal_op_encode_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan, alink_message_head_t* msg, const alink_camera_gimbal_op_t* camera_gimbal_op)
{
	return alink_msg_camera_gimbal_op_pack_chan(dest_id, source_id, chan, msg, camera_gimbal_op->operate, camera_gimbal_op->step_angle, camera_gimbal_op->total_angle, camera_gimbal_op->current_step, camera_gimbal_op->total_step);
}
// MESSAGE CAMERA_GIMBAL_OP UNPACKING


/**
 * @brief Get field operate from camera_gimbal_op message
 *
 * @return 0:EnterPanorama, 1:ExitPanorama, 2:SetSpinAngle
 */
static inline uint8_t alink_msg_camera_gimbal_op_get_operate(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  16);
}

/**
 * @brief Get field step_angle from camera_gimbal_op message
 *
 * @return step angle
 */
static inline int32_t alink_msg_camera_gimbal_op_get_step_angle(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  0);
}

/**
 * @brief Get field total_angle from camera_gimbal_op message
 *
 * @return total angle
 */
static inline int32_t alink_msg_camera_gimbal_op_get_total_angle(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  4);
}

/**
 * @brief Get field current_step from camera_gimbal_op message
 *
 * @return current_step
 */
static inline int32_t alink_msg_camera_gimbal_op_get_current_step(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  8);
}

/**
 * @brief Get field total_step from camera_gimbal_op message
 *
 * @return total step
 */
static inline int32_t alink_msg_camera_gimbal_op_get_total_step(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  12);
}

/**
 * @brief Decode a camera_gimbal_op message into a struct
 *
 * @param msg The message to decode
 * @param camera_gimbal_op C-struct to decode the message contents into
 */
static inline void alink_msg_camera_gimbal_op_decode(const alink_message_head_t* msg, alink_camera_gimbal_op_t* camera_gimbal_op)
{
#if ALINK_NEED_BYTE_SWAP
	camera_gimbal_op->step_angle = alink_msg_camera_gimbal_op_get_step_angle(msg);
	camera_gimbal_op->total_angle = alink_msg_camera_gimbal_op_get_total_angle(msg);
	camera_gimbal_op->current_step = alink_msg_camera_gimbal_op_get_current_step(msg);
	camera_gimbal_op->total_step = alink_msg_camera_gimbal_op_get_total_step(msg);
	camera_gimbal_op->operate = alink_msg_camera_gimbal_op_get_operate(msg);
#else
	memcpy(camera_gimbal_op, _MAV_PAYLOAD(msg), ALINK_MSG_ID_CAMERA_GIMBAL_OP_LEN);
#endif
}
