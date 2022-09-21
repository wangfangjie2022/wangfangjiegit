// MESSAGE CAMERA_FCS_OP PACKING

#define ALINK_MSG_ID_CAMERA_FCS_OP 100

typedef struct __alink_camera_fcs_op_t
{
 float speed; /*< speed*/
 uint8_t operate; /*< 0:EnterPanorama, 1:ExitPanorama, 2:SetHaltSpeed*/
} alink_camera_fcs_op_t;

#define ALINK_MSG_ID_CAMERA_FCS_OP_LEN 5
#define ALINK_MSG_ID_100_LEN 5

#define ALINK_MSG_ID_CAMERA_FCS_OP_CRC 65
#define ALINK_MSG_ID_100_CRC 65



#define ALINK_MESSAGE_INFO_CAMERA_FCS_OP { \
	"CAMERA_FCS_OP", \
	2, \
	{  { "speed", NULL, ALINK_TYPE_FLOAT, 0, 0, offsetof(alink_camera_fcs_op_t, speed) }, \
         { "operate", NULL, ALINK_TYPE_UINT8_T, 0, 4, offsetof(alink_camera_fcs_op_t, operate) }, \
         } \
}


/**
 * @brief Pack a camera_fcs_op message
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 *
 * @param operate 0:EnterPanorama, 1:ExitPanorama, 2:SetHaltSpeed
 * @param speed speed
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_camera_fcs_op_pack(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg,
						       uint8_t operate, float speed)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_CAMERA_FCS_OP_LEN];
	_mav_put_float(buf, 0, speed);
	_mav_put_uint8_t(buf, 4, operate);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_CAMERA_FCS_OP_LEN);
#else
	alink_camera_fcs_op_t packet;
	packet.speed = speed;
	packet.operate = operate;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_CAMERA_FCS_OP_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_CAMERA_FCS_OP;
#if ALINK_CRC_EXTRA
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_CAMERA_FCS_OP_LEN,ALINK_MSG_ID_CAMERA_FCS_OP_CRC);
#else
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_CAMERA_FCS_OP_LEN);
#endif
}

/**
 * @brief Pack a camera_fcs_op message on a channel
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param operate 0:EnterPanorama, 1:ExitPanorama, 2:SetHaltSpeed
 * @param speed speed
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_camera_fcs_op_pack_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan,
							   alink_message_head_t* msg,
						           uint8_t operate,float speed)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_CAMERA_FCS_OP_LEN];
	_mav_put_float(buf, 0, speed);
	_mav_put_uint8_t(buf, 4, operate);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_CAMERA_FCS_OP_LEN);
#else
	alink_camera_fcs_op_t packet;
	packet.speed = speed;
	packet.operate = operate;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_CAMERA_FCS_OP_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_CAMERA_FCS_OP;
#if ALINK_CRC_EXTRA
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_CAMERA_FCS_OP_LEN,ALINK_MSG_ID_CAMERA_FCS_OP_CRC);
#else
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_CAMERA_FCS_OP_LEN);
#endif
}
/**
 * @brief Encode a camera_fcs_op struct
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 * @param camera_fcs_op C-struct to read the message contents from
 */
static inline uint16_t alink_msg_camera_fcs_op_encode(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg, const alink_camera_fcs_op_t* camera_fcs_op)
{
	return alink_msg_camera_fcs_op_pack(dest_id, source_id, msg, camera_fcs_op->operate, camera_fcs_op->speed);
}

/**
 * @brief Encode a camera_fcs_op struct on a channel
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param camera_fcs_op C-struct to read the message contents from
 */
static inline uint16_t alink_msg_camera_fcs_op_encode_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan, alink_message_head_t* msg, const alink_camera_fcs_op_t* camera_fcs_op)
{
	return alink_msg_camera_fcs_op_pack_chan(dest_id, source_id, chan, msg, camera_fcs_op->operate, camera_fcs_op->speed);
}
// MESSAGE CAMERA_FCS_OP UNPACKING


/**
 * @brief Get field operate from camera_fcs_op message
 *
 * @return 0:EnterPanorama, 1:ExitPanorama, 2:SetHaltSpeed
 */
static inline uint8_t alink_msg_camera_fcs_op_get_operate(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  4);
}

/**
 * @brief Get field speed from camera_fcs_op message
 *
 * @return speed
 */
static inline float alink_msg_camera_fcs_op_get_speed(const alink_message_head_t* msg)
{
	return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Decode a camera_fcs_op message into a struct
 *
 * @param msg The message to decode
 * @param camera_fcs_op C-struct to decode the message contents into
 */
static inline void alink_msg_camera_fcs_op_decode(const alink_message_head_t* msg, alink_camera_fcs_op_t* camera_fcs_op)
{
#if ALINK_NEED_BYTE_SWAP
	camera_fcs_op->speed = alink_msg_camera_fcs_op_get_speed(msg);
	camera_fcs_op->operate = alink_msg_camera_fcs_op_get_operate(msg);
#else
	memcpy(camera_fcs_op, _MAV_PAYLOAD(msg), ALINK_MSG_ID_CAMERA_FCS_OP_LEN);
#endif
}
