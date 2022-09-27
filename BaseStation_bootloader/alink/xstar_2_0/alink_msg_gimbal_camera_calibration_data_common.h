// MESSAGE GIMBAL_CAMERA_CALIBRATION_DATA_COMMON PACKING

#define ALINK_MSG_ID_GIMBAL_CAMERA_CALIBRATION_DATA_COMMON 59

typedef struct __alink_gimbal_camera_calibration_data_common_t
{
 int32_t recv_len; /*< recvived data len */
 uint8_t req_or_resp; /*< request or response, 0: request, 1 : response */
 uint8_t data; /*< for request: 0x0: get common message, 0x1: get recv Calibration data; for response: the result of save Camera Calibration,  success : 0x1, failed : 0x0 */
} alink_gimbal_camera_calibration_data_common_t;

#define ALINK_MSG_ID_GIMBAL_CAMERA_CALIBRATION_DATA_COMMON_LEN 6
#define ALINK_MSG_ID_59_LEN 6

#define ALINK_MSG_ID_GIMBAL_CAMERA_CALIBRATION_DATA_COMMON_CRC 9
#define ALINK_MSG_ID_59_CRC 9



#define ALINK_MESSAGE_INFO_GIMBAL_CAMERA_CALIBRATION_DATA_COMMON { \
	"GIMBAL_CAMERA_CALIBRATION_DATA_COMMON", \
	3, \
	{  { "recv_len", NULL, ALINK_TYPE_INT32_T, 0, 0, offsetof(alink_gimbal_camera_calibration_data_common_t, recv_len) }, \
         { "req_or_resp", NULL, ALINK_TYPE_UINT8_T, 0, 4, offsetof(alink_gimbal_camera_calibration_data_common_t, req_or_resp) }, \
         { "data", NULL, ALINK_TYPE_UINT8_T, 0, 5, offsetof(alink_gimbal_camera_calibration_data_common_t, data) }, \
         } \
}


/**
 * @brief Pack a gimbal_camera_calibration_data_common message
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 *
 * @param req_or_resp request or response, 0: request, 1 : response 
 * @param data for request: 0x0: get common message, 0x1: get recv Calibration data; for response: the result of save Camera Calibration,  success : 0x1, failed : 0x0 
 * @param recv_len recvived data len 
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_gimbal_camera_calibration_data_common_pack(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg,
						       uint8_t req_or_resp, uint8_t data, int32_t recv_len)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_GIMBAL_CAMERA_CALIBRATION_DATA_COMMON_LEN];
	_mav_put_int32_t(buf, 0, recv_len);
	_mav_put_uint8_t(buf, 4, req_or_resp);
	_mav_put_uint8_t(buf, 5, data);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_GIMBAL_CAMERA_CALIBRATION_DATA_COMMON_LEN);
#else
	alink_gimbal_camera_calibration_data_common_t packet;
	packet.recv_len = recv_len;
	packet.req_or_resp = req_or_resp;
	packet.data = data;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_GIMBAL_CAMERA_CALIBRATION_DATA_COMMON_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_GIMBAL_CAMERA_CALIBRATION_DATA_COMMON;
#if ALINK_CRC_EXTRA
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_GIMBAL_CAMERA_CALIBRATION_DATA_COMMON_LEN,ALINK_MSG_ID_GIMBAL_CAMERA_CALIBRATION_DATA_COMMON_CRC);
#else
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_GIMBAL_CAMERA_CALIBRATION_DATA_COMMON_LEN);
#endif
}

/**
 * @brief Pack a gimbal_camera_calibration_data_common message on a channel
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param req_or_resp request or response, 0: request, 1 : response 
 * @param data for request: 0x0: get common message, 0x1: get recv Calibration data; for response: the result of save Camera Calibration,  success : 0x1, failed : 0x0 
 * @param recv_len recvived data len 
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_gimbal_camera_calibration_data_common_pack_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan,
							   alink_message_head_t* msg,
						           uint8_t req_or_resp,uint8_t data,int32_t recv_len)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_GIMBAL_CAMERA_CALIBRATION_DATA_COMMON_LEN];
	_mav_put_int32_t(buf, 0, recv_len);
	_mav_put_uint8_t(buf, 4, req_or_resp);
	_mav_put_uint8_t(buf, 5, data);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_GIMBAL_CAMERA_CALIBRATION_DATA_COMMON_LEN);
#else
	alink_gimbal_camera_calibration_data_common_t packet;
	packet.recv_len = recv_len;
	packet.req_or_resp = req_or_resp;
	packet.data = data;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_GIMBAL_CAMERA_CALIBRATION_DATA_COMMON_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_GIMBAL_CAMERA_CALIBRATION_DATA_COMMON;
#if ALINK_CRC_EXTRA
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_GIMBAL_CAMERA_CALIBRATION_DATA_COMMON_LEN,ALINK_MSG_ID_GIMBAL_CAMERA_CALIBRATION_DATA_COMMON_CRC);
#else
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_GIMBAL_CAMERA_CALIBRATION_DATA_COMMON_LEN);
#endif
}
/**
 * @brief Encode a gimbal_camera_calibration_data_common struct
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 * @param gimbal_camera_calibration_data_common C-struct to read the message contents from
 */
static inline uint16_t alink_msg_gimbal_camera_calibration_data_common_encode(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg, const alink_gimbal_camera_calibration_data_common_t* gimbal_camera_calibration_data_common)
{
	return alink_msg_gimbal_camera_calibration_data_common_pack(dest_id, source_id, msg, gimbal_camera_calibration_data_common->req_or_resp, gimbal_camera_calibration_data_common->data, gimbal_camera_calibration_data_common->recv_len);
}

/**
 * @brief Encode a gimbal_camera_calibration_data_common struct on a channel
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param gimbal_camera_calibration_data_common C-struct to read the message contents from
 */
static inline uint16_t alink_msg_gimbal_camera_calibration_data_common_encode_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan, alink_message_head_t* msg, const alink_gimbal_camera_calibration_data_common_t* gimbal_camera_calibration_data_common)
{
	return alink_msg_gimbal_camera_calibration_data_common_pack_chan(dest_id, source_id, chan, msg, gimbal_camera_calibration_data_common->req_or_resp, gimbal_camera_calibration_data_common->data, gimbal_camera_calibration_data_common->recv_len);
}
// MESSAGE GIMBAL_CAMERA_CALIBRATION_DATA_COMMON UNPACKING


/**
 * @brief Get field req_or_resp from gimbal_camera_calibration_data_common message
 *
 * @return request or response, 0: request, 1 : response 
 */
static inline uint8_t alink_msg_gimbal_camera_calibration_data_common_get_req_or_resp(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  4);
}

/**
 * @brief Get field data from gimbal_camera_calibration_data_common message
 *
 * @return for request: 0x0: get common message, 0x1: get recv Calibration data; for response: the result of save Camera Calibration,  success : 0x1, failed : 0x0 
 */
static inline uint8_t alink_msg_gimbal_camera_calibration_data_common_get_data(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  5);
}

/**
 * @brief Get field recv_len from gimbal_camera_calibration_data_common message
 *
 * @return recvived data len 
 */
static inline int32_t alink_msg_gimbal_camera_calibration_data_common_get_recv_len(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  0);
}

/**
 * @brief Decode a gimbal_camera_calibration_data_common message into a struct
 *
 * @param msg The message to decode
 * @param gimbal_camera_calibration_data_common C-struct to decode the message contents into
 */
static inline void alink_msg_gimbal_camera_calibration_data_common_decode(const alink_message_head_t* msg, alink_gimbal_camera_calibration_data_common_t* gimbal_camera_calibration_data_common)
{
#if ALINK_NEED_BYTE_SWAP
	gimbal_camera_calibration_data_common->recv_len = alink_msg_gimbal_camera_calibration_data_common_get_recv_len(msg);
	gimbal_camera_calibration_data_common->req_or_resp = alink_msg_gimbal_camera_calibration_data_common_get_req_or_resp(msg);
	gimbal_camera_calibration_data_common->data = alink_msg_gimbal_camera_calibration_data_common_get_data(msg);
#else
	memcpy(gimbal_camera_calibration_data_common, _MAV_PAYLOAD(msg), ALINK_MSG_ID_GIMBAL_CAMERA_CALIBRATION_DATA_COMMON_LEN);
#endif
}
