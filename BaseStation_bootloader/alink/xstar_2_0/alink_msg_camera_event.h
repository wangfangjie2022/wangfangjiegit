// MESSAGE CAMERA_EVENT PACKING

#define ALINK_MSG_ID_CAMERA_EVENT 106

typedef struct __alink_camera_event_t
{
 uint8_t cam_type; /*< camera type*/
 uint8_t event; /*< event id*/
 char data[62]; /*< Payload data bytes.*/
} alink_camera_event_t;

#define ALINK_MSG_ID_CAMERA_EVENT_LEN 64
#define ALINK_MSG_ID_106_LEN 64

#define ALINK_MSG_ID_CAMERA_EVENT_CRC 171
#define ALINK_MSG_ID_106_CRC 171

#define ALINK_MSG_CAMERA_EVENT_FIELD_DATA_LEN 62

#define ALINK_MESSAGE_INFO_CAMERA_EVENT { \
	"CAMERA_EVENT", \
	3, \
	{  { "cam_type", NULL, ALINK_TYPE_UINT8_T, 0, 0, offsetof(alink_camera_event_t, cam_type) }, \
         { "event", NULL, ALINK_TYPE_UINT8_T, 0, 1, offsetof(alink_camera_event_t, event) }, \
         { "data", NULL, ALINK_TYPE_CHAR, 62, 2, offsetof(alink_camera_event_t, data) }, \
         } \
}


/**
 * @brief Pack a camera_event message
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 *
 * @param cam_type camera type
 * @param event event id
 * @param data Payload data bytes.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_camera_event_pack(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg,
						       uint8_t cam_type, uint8_t event, const char *data)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_CAMERA_EVENT_LEN];
	_mav_put_uint8_t(buf, 0, cam_type);
	_mav_put_uint8_t(buf, 1, event);
	_mav_put_char_array(buf, 2, data, 62);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_CAMERA_EVENT_LEN);
#else
	alink_camera_event_t packet;
	packet.cam_type = cam_type;
	packet.event = event;
	mav_array_memcpy(packet.data, data, sizeof(char)*62);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_CAMERA_EVENT_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_CAMERA_EVENT;
#if ALINK_CRC_EXTRA
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_CAMERA_EVENT_LEN,ALINK_MSG_ID_CAMERA_EVENT_CRC);
#else
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_CAMERA_EVENT_LEN);
#endif
}

/**
 * @brief Pack a camera_event message on a channel
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param cam_type camera type
 * @param event event id
 * @param data Payload data bytes.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_camera_event_pack_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan,
							   alink_message_head_t* msg,
						           uint8_t cam_type,uint8_t event,const char *data)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_CAMERA_EVENT_LEN];
	_mav_put_uint8_t(buf, 0, cam_type);
	_mav_put_uint8_t(buf, 1, event);
	_mav_put_char_array(buf, 2, data, 62);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_CAMERA_EVENT_LEN);
#else
	alink_camera_event_t packet;
	packet.cam_type = cam_type;
	packet.event = event;
	mav_array_memcpy(packet.data, data, sizeof(char)*62);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_CAMERA_EVENT_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_CAMERA_EVENT;
#if ALINK_CRC_EXTRA
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_CAMERA_EVENT_LEN,ALINK_MSG_ID_CAMERA_EVENT_CRC);
#else
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_CAMERA_EVENT_LEN);
#endif
}
/**
 * @brief Encode a camera_event struct
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 * @param camera_event C-struct to read the message contents from
 */
static inline uint16_t alink_msg_camera_event_encode(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg, const alink_camera_event_t* camera_event)
{
	return alink_msg_camera_event_pack(dest_id, source_id, msg, camera_event->cam_type, camera_event->event, camera_event->data);
}

/**
 * @brief Encode a camera_event struct on a channel
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param camera_event C-struct to read the message contents from
 */
static inline uint16_t alink_msg_camera_event_encode_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan, alink_message_head_t* msg, const alink_camera_event_t* camera_event)
{
	return alink_msg_camera_event_pack_chan(dest_id, source_id, chan, msg, camera_event->cam_type, camera_event->event, camera_event->data);
}
// MESSAGE CAMERA_EVENT UNPACKING


/**
 * @brief Get field cam_type from camera_event message
 *
 * @return camera type
 */
static inline uint8_t alink_msg_camera_event_get_cam_type(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field event from camera_event message
 *
 * @return event id
 */
static inline uint8_t alink_msg_camera_event_get_event(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  1);
}

/**
 * @brief Get field data from camera_event message
 *
 * @return Payload data bytes.
 */
static inline uint16_t alink_msg_camera_event_get_data(const alink_message_head_t* msg, char *data)
{
	return _MAV_RETURN_char_array(msg, data, 62,  2);
}

/**
 * @brief Decode a camera_event message into a struct
 *
 * @param msg The message to decode
 * @param camera_event C-struct to decode the message contents into
 */
static inline void alink_msg_camera_event_decode(const alink_message_head_t* msg, alink_camera_event_t* camera_event)
{
#if ALINK_NEED_BYTE_SWAP
	camera_event->cam_type = alink_msg_camera_event_get_cam_type(msg);
	camera_event->event = alink_msg_camera_event_get_event(msg);
	alink_msg_camera_event_get_data(msg, camera_event->data);
#else
	memcpy(camera_event, _MAV_PAYLOAD(msg), ALINK_MSG_ID_CAMERA_EVENT_LEN);
#endif
}
