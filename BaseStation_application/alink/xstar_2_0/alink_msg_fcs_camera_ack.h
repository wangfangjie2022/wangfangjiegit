// MESSAGE FCS_CAMERA_ACK PACKING

#define ALINK_MSG_ID_FCS_CAMERA_ACK 101

typedef struct __alink_fcs_camera_ack_t
{
 uint8_t operate; /*< 0:EnterPanorama, 1:ExitPanorama, 2:SetHaltSpeed, 3:HaltDone, 4:AbortExitPanorama*/
 uint8_t result; /*< 0:fail 1:success*/
} alink_fcs_camera_ack_t;

#define ALINK_MSG_ID_FCS_CAMERA_ACK_LEN 2
#define ALINK_MSG_ID_101_LEN 2

#define ALINK_MSG_ID_FCS_CAMERA_ACK_CRC 143
#define ALINK_MSG_ID_101_CRC 143



#define ALINK_MESSAGE_INFO_FCS_CAMERA_ACK { \
	"FCS_CAMERA_ACK", \
	2, \
	{  { "operate", NULL, ALINK_TYPE_UINT8_T, 0, 0, offsetof(alink_fcs_camera_ack_t, operate) }, \
         { "result", NULL, ALINK_TYPE_UINT8_T, 0, 1, offsetof(alink_fcs_camera_ack_t, result) }, \
         } \
}


/**
 * @brief Pack a fcs_camera_ack message
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 *
 * @param operate 0:EnterPanorama, 1:ExitPanorama, 2:SetHaltSpeed, 3:HaltDone, 4:AbortExitPanorama
 * @param result 0:fail 1:success
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_fcs_camera_ack_pack(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg,
						       uint8_t operate, uint8_t result)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_FCS_CAMERA_ACK_LEN];
	_mav_put_uint8_t(buf, 0, operate);
	_mav_put_uint8_t(buf, 1, result);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_FCS_CAMERA_ACK_LEN);
#else
	alink_fcs_camera_ack_t packet;
	packet.operate = operate;
	packet.result = result;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_FCS_CAMERA_ACK_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_FCS_CAMERA_ACK;
#if ALINK_CRC_EXTRA
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_FCS_CAMERA_ACK_LEN,ALINK_MSG_ID_FCS_CAMERA_ACK_CRC);
#else
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_FCS_CAMERA_ACK_LEN);
#endif
}

/**
 * @brief Pack a fcs_camera_ack message on a channel
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param operate 0:EnterPanorama, 1:ExitPanorama, 2:SetHaltSpeed, 3:HaltDone, 4:AbortExitPanorama
 * @param result 0:fail 1:success
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_fcs_camera_ack_pack_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan,
							   alink_message_head_t* msg,
						           uint8_t operate,uint8_t result)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_FCS_CAMERA_ACK_LEN];
	_mav_put_uint8_t(buf, 0, operate);
	_mav_put_uint8_t(buf, 1, result);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_FCS_CAMERA_ACK_LEN);
#else
	alink_fcs_camera_ack_t packet;
	packet.operate = operate;
	packet.result = result;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_FCS_CAMERA_ACK_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_FCS_CAMERA_ACK;
#if ALINK_CRC_EXTRA
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_FCS_CAMERA_ACK_LEN,ALINK_MSG_ID_FCS_CAMERA_ACK_CRC);
#else
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_FCS_CAMERA_ACK_LEN);
#endif
}
/**
 * @brief Encode a fcs_camera_ack struct
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 * @param fcs_camera_ack C-struct to read the message contents from
 */
static inline uint16_t alink_msg_fcs_camera_ack_encode(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg, const alink_fcs_camera_ack_t* fcs_camera_ack)
{
	return alink_msg_fcs_camera_ack_pack(dest_id, source_id, msg, fcs_camera_ack->operate, fcs_camera_ack->result);
}

/**
 * @brief Encode a fcs_camera_ack struct on a channel
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param fcs_camera_ack C-struct to read the message contents from
 */
static inline uint16_t alink_msg_fcs_camera_ack_encode_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan, alink_message_head_t* msg, const alink_fcs_camera_ack_t* fcs_camera_ack)
{
	return alink_msg_fcs_camera_ack_pack_chan(dest_id, source_id, chan, msg, fcs_camera_ack->operate, fcs_camera_ack->result);
}
// MESSAGE FCS_CAMERA_ACK UNPACKING


/**
 * @brief Get field operate from fcs_camera_ack message
 *
 * @return 0:EnterPanorama, 1:ExitPanorama, 2:SetHaltSpeed, 3:HaltDone, 4:AbortExitPanorama
 */
static inline uint8_t alink_msg_fcs_camera_ack_get_operate(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field result from fcs_camera_ack message
 *
 * @return 0:fail 1:success
 */
static inline uint8_t alink_msg_fcs_camera_ack_get_result(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  1);
}

/**
 * @brief Decode a fcs_camera_ack message into a struct
 *
 * @param msg The message to decode
 * @param fcs_camera_ack C-struct to decode the message contents into
 */
static inline void alink_msg_fcs_camera_ack_decode(const alink_message_head_t* msg, alink_fcs_camera_ack_t* fcs_camera_ack)
{
#if ALINK_NEED_BYTE_SWAP
	fcs_camera_ack->operate = alink_msg_fcs_camera_ack_get_operate(msg);
	fcs_camera_ack->result = alink_msg_fcs_camera_ack_get_result(msg);
#else
	memcpy(fcs_camera_ack, _MAV_PAYLOAD(msg), ALINK_MSG_ID_FCS_CAMERA_ACK_LEN);
#endif
}
