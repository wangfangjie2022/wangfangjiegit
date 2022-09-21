// MESSAGE CAMERA_RESPONSE PACKING

#define ALINK_MSG_ID_CAMERA_RESPONSE 105

typedef struct __alink_camera_response_t
{
 uint8_t cam_type; /*< camera type*/
 uint8_t response; /*< response id*/
 char data[254]; /*< Payload data bytes.*/
} alink_camera_response_t;

#define ALINK_MSG_ID_CAMERA_RESPONSE_LEN 256
#define ALINK_MSG_ID_105_LEN 256

#define ALINK_MSG_ID_CAMERA_RESPONSE_CRC 232
#define ALINK_MSG_ID_105_CRC 232

#define ALINK_MSG_CAMERA_RESPONSE_FIELD_DATA_LEN 254

#define ALINK_MESSAGE_INFO_CAMERA_RESPONSE { \
	"CAMERA_RESPONSE", \
	3, \
	{  { "cam_type", NULL, ALINK_TYPE_UINT8_T, 0, 0, offsetof(alink_camera_response_t, cam_type) }, \
         { "response", NULL, ALINK_TYPE_UINT8_T, 0, 1, offsetof(alink_camera_response_t, response) }, \
         { "data", NULL, ALINK_TYPE_CHAR, 254, 2, offsetof(alink_camera_response_t, data) }, \
         } \
}


/**
 * @brief Pack a camera_response message
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 *
 * @param cam_type camera type
 * @param response response id
 * @param data Payload data bytes.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_camera_response_pack(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg,
						       uint8_t cam_type, uint8_t response, const char *data)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_CAMERA_RESPONSE_LEN];
	_mav_put_uint8_t(buf, 0, cam_type);
	_mav_put_uint8_t(buf, 1, response);
	_mav_put_char_array(buf, 2, data, 254);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_CAMERA_RESPONSE_LEN);
#else
	alink_camera_response_t packet;
	packet.cam_type = cam_type;
	packet.response = response;
	mav_array_memcpy(packet.data, data, sizeof(char)*254);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_CAMERA_RESPONSE_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_CAMERA_RESPONSE;
#if ALINK_CRC_EXTRA
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_CAMERA_RESPONSE_LEN,ALINK_MSG_ID_CAMERA_RESPONSE_CRC);
#else
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_CAMERA_RESPONSE_LEN);
#endif
}

/**
 * @brief Pack a camera_response message on a channel
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param cam_type camera type
 * @param response response id
 * @param data Payload data bytes.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_camera_response_pack_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan,
							   alink_message_head_t* msg,
						           uint8_t cam_type,uint8_t response,const char *data)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_CAMERA_RESPONSE_LEN];
	_mav_put_uint8_t(buf, 0, cam_type);
	_mav_put_uint8_t(buf, 1, response);
	_mav_put_char_array(buf, 2, data, 254);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_CAMERA_RESPONSE_LEN);
#else
	alink_camera_response_t packet;
	packet.cam_type = cam_type;
	packet.response = response;
	mav_array_memcpy(packet.data, data, sizeof(char)*254);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_CAMERA_RESPONSE_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_CAMERA_RESPONSE;
#if ALINK_CRC_EXTRA
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_CAMERA_RESPONSE_LEN,ALINK_MSG_ID_CAMERA_RESPONSE_CRC);
#else
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_CAMERA_RESPONSE_LEN);
#endif
}
/**
 * @brief Encode a camera_response struct
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 * @param camera_response C-struct to read the message contents from
 */
static inline uint16_t alink_msg_camera_response_encode(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg, const alink_camera_response_t* camera_response)
{
	return alink_msg_camera_response_pack(dest_id, source_id, msg, camera_response->cam_type, camera_response->response, camera_response->data);
}

/**
 * @brief Encode a camera_response struct on a channel
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param camera_response C-struct to read the message contents from
 */
static inline uint16_t alink_msg_camera_response_encode_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan, alink_message_head_t* msg, const alink_camera_response_t* camera_response)
{
	return alink_msg_camera_response_pack_chan(dest_id, source_id, chan, msg, camera_response->cam_type, camera_response->response, camera_response->data);
}
// MESSAGE CAMERA_RESPONSE UNPACKING


/**
 * @brief Get field cam_type from camera_response message
 *
 * @return camera type
 */
static inline uint8_t alink_msg_camera_response_get_cam_type(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field response from camera_response message
 *
 * @return response id
 */
static inline uint8_t alink_msg_camera_response_get_response(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  1);
}

/**
 * @brief Get field data from camera_response message
 *
 * @return Payload data bytes.
 */
static inline uint16_t alink_msg_camera_response_get_data(const alink_message_head_t* msg, char *data)
{
	return _MAV_RETURN_char_array(msg, data, 254,  2);
}

/**
 * @brief Decode a camera_response message into a struct
 *
 * @param msg The message to decode
 * @param camera_response C-struct to decode the message contents into
 */
static inline void alink_msg_camera_response_decode(const alink_message_head_t* msg, alink_camera_response_t* camera_response)
{
#if ALINK_NEED_BYTE_SWAP
	camera_response->cam_type = alink_msg_camera_response_get_cam_type(msg);
	camera_response->response = alink_msg_camera_response_get_response(msg);
	alink_msg_camera_response_get_data(msg, camera_response->data);
#else
	memcpy(camera_response, _MAV_PAYLOAD(msg), ALINK_MSG_ID_CAMERA_RESPONSE_LEN);
#endif
}
