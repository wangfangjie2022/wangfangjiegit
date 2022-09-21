// MESSAGE CAMERA_CTRL_RESPONSE PACKING

#define ALINK_MSG_ID_CAMERA_CTRL_RESPONSE 108

typedef struct __alink_camera_ctrl_response_t
{
 uint16_t response; /*< response command id*/
 uint8_t camDevId; /*< camera device id*/
 char data; /*< 数据部分，为变长数据，但最大不超过508字节长，注意只能使用alink_finalize_message 进行打包（如：alink_finalize_message(alink_msg, DEV_DSP_RC, DEV_DSP, ALINK_MSG_ID_108_LEN + len - 1, ALINK_MSG_ID_108_CRC)）*/
} alink_camera_ctrl_response_t;

#define ALINK_MSG_ID_CAMERA_CTRL_RESPONSE_LEN 4
#define ALINK_MSG_ID_108_LEN 4

#define ALINK_MSG_ID_CAMERA_CTRL_RESPONSE_CRC 153
#define ALINK_MSG_ID_108_CRC 153



#define ALINK_MESSAGE_INFO_CAMERA_CTRL_RESPONSE { \
	"CAMERA_CTRL_RESPONSE", \
	3, \
	{  { "response", NULL, ALINK_TYPE_UINT16_T, 0, 0, offsetof(alink_camera_ctrl_response_t, response) }, \
         { "camDevId", NULL, ALINK_TYPE_UINT8_T, 0, 2, offsetof(alink_camera_ctrl_response_t, camDevId) }, \
         { "data", NULL, ALINK_TYPE_CHAR, 0, 3, offsetof(alink_camera_ctrl_response_t, data) }, \
         } \
}


/**
 * @brief Pack a camera_ctrl_response message
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 *
 * @param camDevId camera device id
 * @param response response command id
 * @param data 数据部分，为变长数据，但最大不超过508字节长，注意只能使用alink_finalize_message 进行打包（如：alink_finalize_message(alink_msg, DEV_DSP_RC, DEV_DSP, ALINK_MSG_ID_108_LEN + len - 1, ALINK_MSG_ID_108_CRC)）
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_camera_ctrl_response_pack(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg,
						       uint8_t camDevId, uint16_t response, char data)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_CAMERA_CTRL_RESPONSE_LEN];
	_mav_put_uint16_t(buf, 0, response);
	_mav_put_uint8_t(buf, 2, camDevId);
	_mav_put_char(buf, 3, data);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_CAMERA_CTRL_RESPONSE_LEN);
#else
	alink_camera_ctrl_response_t packet;
	packet.response = response;
	packet.camDevId = camDevId;
	packet.data = data;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_CAMERA_CTRL_RESPONSE_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_CAMERA_CTRL_RESPONSE;
#if ALINK_CRC_EXTRA
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_CAMERA_CTRL_RESPONSE_LEN,ALINK_MSG_ID_CAMERA_CTRL_RESPONSE_CRC);
#else
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_CAMERA_CTRL_RESPONSE_LEN);
#endif
}

/**
 * @brief Pack a camera_ctrl_response message on a channel
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param camDevId camera device id
 * @param response response command id
 * @param data 数据部分，为变长数据，但最大不超过508字节长，注意只能使用alink_finalize_message 进行打包（如：alink_finalize_message(alink_msg, DEV_DSP_RC, DEV_DSP, ALINK_MSG_ID_108_LEN + len - 1, ALINK_MSG_ID_108_CRC)）
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_camera_ctrl_response_pack_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan,
							   alink_message_head_t* msg,
						           uint8_t camDevId,uint16_t response,char data)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_CAMERA_CTRL_RESPONSE_LEN];
	_mav_put_uint16_t(buf, 0, response);
	_mav_put_uint8_t(buf, 2, camDevId);
	_mav_put_char(buf, 3, data);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_CAMERA_CTRL_RESPONSE_LEN);
#else
	alink_camera_ctrl_response_t packet;
	packet.response = response;
	packet.camDevId = camDevId;
	packet.data = data;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_CAMERA_CTRL_RESPONSE_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_CAMERA_CTRL_RESPONSE;
#if ALINK_CRC_EXTRA
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_CAMERA_CTRL_RESPONSE_LEN,ALINK_MSG_ID_CAMERA_CTRL_RESPONSE_CRC);
#else
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_CAMERA_CTRL_RESPONSE_LEN);
#endif
}
/**
 * @brief Encode a camera_ctrl_response struct
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 * @param camera_ctrl_response C-struct to read the message contents from
 */
static inline uint16_t alink_msg_camera_ctrl_response_encode(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg, const alink_camera_ctrl_response_t* camera_ctrl_response)
{
	return alink_msg_camera_ctrl_response_pack(dest_id, source_id, msg, camera_ctrl_response->camDevId, camera_ctrl_response->response, camera_ctrl_response->data);
}

/**
 * @brief Encode a camera_ctrl_response struct on a channel
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param camera_ctrl_response C-struct to read the message contents from
 */
static inline uint16_t alink_msg_camera_ctrl_response_encode_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan, alink_message_head_t* msg, const alink_camera_ctrl_response_t* camera_ctrl_response)
{
	return alink_msg_camera_ctrl_response_pack_chan(dest_id, source_id, chan, msg, camera_ctrl_response->camDevId, camera_ctrl_response->response, camera_ctrl_response->data);
}
// MESSAGE CAMERA_CTRL_RESPONSE UNPACKING


/**
 * @brief Get field camDevId from camera_ctrl_response message
 *
 * @return camera device id
 */
static inline uint8_t alink_msg_camera_ctrl_response_get_camDevId(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  2);
}

/**
 * @brief Get field response from camera_ctrl_response message
 *
 * @return response command id
 */
static inline uint16_t alink_msg_camera_ctrl_response_get_response(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  0);
}

/**
 * @brief Get field data from camera_ctrl_response message
 *
 * @return 数据部分，为变长数据，但最大不超过508字节长，注意只能使用alink_finalize_message 进行打包（如：alink_finalize_message(alink_msg, DEV_DSP_RC, DEV_DSP, ALINK_MSG_ID_108_LEN + len - 1, ALINK_MSG_ID_108_CRC)）
 */
static inline char alink_msg_camera_ctrl_response_get_data(const alink_message_head_t* msg)
{
	return _MAV_RETURN_char(msg,  3);
}

/**
 * @brief Decode a camera_ctrl_response message into a struct
 *
 * @param msg The message to decode
 * @param camera_ctrl_response C-struct to decode the message contents into
 */
static inline void alink_msg_camera_ctrl_response_decode(const alink_message_head_t* msg, alink_camera_ctrl_response_t* camera_ctrl_response)
{
#if ALINK_NEED_BYTE_SWAP
	camera_ctrl_response->response = alink_msg_camera_ctrl_response_get_response(msg);
	camera_ctrl_response->camDevId = alink_msg_camera_ctrl_response_get_camDevId(msg);
	camera_ctrl_response->data = alink_msg_camera_ctrl_response_get_data(msg);
#else
	memcpy(camera_ctrl_response, _MAV_PAYLOAD(msg), ALINK_MSG_ID_CAMERA_CTRL_RESPONSE_LEN);
#endif
}
