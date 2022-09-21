// MESSAGE CAMERA_EVENT_MSG PACKING

#define ALINK_MSG_ID_CAMERA_EVENT_MSG 109

typedef struct __alink_camera_event_msg_t
{
 uint16_t eventID; /*< event id*/
 uint8_t camDevId; /*< camera device id*/
 char data; /*< 数据部分，为变长数据，但最大不超过508字节长，注意只能使用alink_finalize_message 进行打包（如：alink_finalize_message(alink_msg, DEV_DSP_RC, DEV_DSP, ALINK_MSG_ID_109_LEN + len - 1, ALINK_MSG_ID_109_CRC)）*/
} alink_camera_event_msg_t;

#define ALINK_MSG_ID_CAMERA_EVENT_MSG_LEN 4
#define ALINK_MSG_ID_109_LEN 4

#define ALINK_MSG_ID_CAMERA_EVENT_MSG_CRC 75
#define ALINK_MSG_ID_109_CRC 75



#define ALINK_MESSAGE_INFO_CAMERA_EVENT_MSG { \
	"CAMERA_EVENT_MSG", \
	3, \
	{  { "eventID", NULL, ALINK_TYPE_UINT16_T, 0, 0, offsetof(alink_camera_event_msg_t, eventID) }, \
         { "camDevId", NULL, ALINK_TYPE_UINT8_T, 0, 2, offsetof(alink_camera_event_msg_t, camDevId) }, \
         { "data", NULL, ALINK_TYPE_CHAR, 0, 3, offsetof(alink_camera_event_msg_t, data) }, \
         } \
}


/**
 * @brief Pack a camera_event_msg message
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 *
 * @param camDevId camera device id
 * @param eventID event id
 * @param data 数据部分，为变长数据，但最大不超过508字节长，注意只能使用alink_finalize_message 进行打包（如：alink_finalize_message(alink_msg, DEV_DSP_RC, DEV_DSP, ALINK_MSG_ID_109_LEN + len - 1, ALINK_MSG_ID_109_CRC)）
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_camera_event_msg_pack(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg,
						       uint8_t camDevId, uint16_t eventID, char data)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_CAMERA_EVENT_MSG_LEN];
	_mav_put_uint16_t(buf, 0, eventID);
	_mav_put_uint8_t(buf, 2, camDevId);
	_mav_put_char(buf, 3, data);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_CAMERA_EVENT_MSG_LEN);
#else
	alink_camera_event_msg_t packet;
	packet.eventID = eventID;
	packet.camDevId = camDevId;
	packet.data = data;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_CAMERA_EVENT_MSG_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_CAMERA_EVENT_MSG;
#if ALINK_CRC_EXTRA
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_CAMERA_EVENT_MSG_LEN,ALINK_MSG_ID_CAMERA_EVENT_MSG_CRC);
#else
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_CAMERA_EVENT_MSG_LEN);
#endif
}

/**
 * @brief Pack a camera_event_msg message on a channel
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param camDevId camera device id
 * @param eventID event id
 * @param data 数据部分，为变长数据，但最大不超过508字节长，注意只能使用alink_finalize_message 进行打包（如：alink_finalize_message(alink_msg, DEV_DSP_RC, DEV_DSP, ALINK_MSG_ID_109_LEN + len - 1, ALINK_MSG_ID_109_CRC)）
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_camera_event_msg_pack_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan,
							   alink_message_head_t* msg,
						           uint8_t camDevId,uint16_t eventID,char data)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_CAMERA_EVENT_MSG_LEN];
	_mav_put_uint16_t(buf, 0, eventID);
	_mav_put_uint8_t(buf, 2, camDevId);
	_mav_put_char(buf, 3, data);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_CAMERA_EVENT_MSG_LEN);
#else
	alink_camera_event_msg_t packet;
	packet.eventID = eventID;
	packet.camDevId = camDevId;
	packet.data = data;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_CAMERA_EVENT_MSG_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_CAMERA_EVENT_MSG;
#if ALINK_CRC_EXTRA
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_CAMERA_EVENT_MSG_LEN,ALINK_MSG_ID_CAMERA_EVENT_MSG_CRC);
#else
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_CAMERA_EVENT_MSG_LEN);
#endif
}
/**
 * @brief Encode a camera_event_msg struct
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 * @param camera_event_msg C-struct to read the message contents from
 */
static inline uint16_t alink_msg_camera_event_msg_encode(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg, const alink_camera_event_msg_t* camera_event_msg)
{
	return alink_msg_camera_event_msg_pack(dest_id, source_id, msg, camera_event_msg->camDevId, camera_event_msg->eventID, camera_event_msg->data);
}

/**
 * @brief Encode a camera_event_msg struct on a channel
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param camera_event_msg C-struct to read the message contents from
 */
static inline uint16_t alink_msg_camera_event_msg_encode_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan, alink_message_head_t* msg, const alink_camera_event_msg_t* camera_event_msg)
{
	return alink_msg_camera_event_msg_pack_chan(dest_id, source_id, chan, msg, camera_event_msg->camDevId, camera_event_msg->eventID, camera_event_msg->data);
}
// MESSAGE CAMERA_EVENT_MSG UNPACKING


/**
 * @brief Get field camDevId from camera_event_msg message
 *
 * @return camera device id
 */
static inline uint8_t alink_msg_camera_event_msg_get_camDevId(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  2);
}

/**
 * @brief Get field eventID from camera_event_msg message
 *
 * @return event id
 */
static inline uint16_t alink_msg_camera_event_msg_get_eventID(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  0);
}

/**
 * @brief Get field data from camera_event_msg message
 *
 * @return 数据部分，为变长数据，但最大不超过508字节长，注意只能使用alink_finalize_message 进行打包（如：alink_finalize_message(alink_msg, DEV_DSP_RC, DEV_DSP, ALINK_MSG_ID_109_LEN + len - 1, ALINK_MSG_ID_109_CRC)）
 */
static inline char alink_msg_camera_event_msg_get_data(const alink_message_head_t* msg)
{
	return _MAV_RETURN_char(msg,  3);
}

/**
 * @brief Decode a camera_event_msg message into a struct
 *
 * @param msg The message to decode
 * @param camera_event_msg C-struct to decode the message contents into
 */
static inline void alink_msg_camera_event_msg_decode(const alink_message_head_t* msg, alink_camera_event_msg_t* camera_event_msg)
{
#if ALINK_NEED_BYTE_SWAP
	camera_event_msg->eventID = alink_msg_camera_event_msg_get_eventID(msg);
	camera_event_msg->camDevId = alink_msg_camera_event_msg_get_camDevId(msg);
	camera_event_msg->data = alink_msg_camera_event_msg_get_data(msg);
#else
	memcpy(camera_event_msg, _MAV_PAYLOAD(msg), ALINK_MSG_ID_CAMERA_EVENT_MSG_LEN);
#endif
}
