// MESSAGE CAMERA_STATUS PACKING

#define ALINK_MSG_ID_CAMERA_STATUS 149

typedef struct __alink_camera_status_t
{
 uint16_t resv2; /*< reserved for future use*/
 uint16_t resv3; /*< reserved for future use*/
 uint8_t state; /*< State of camera: 0-Idle; 1-Recording; 2-Capturing */
 uint8_t mode; /*< Mode of camera: 0-Record; 1-Single; 2-Burst; 3-Timelapse; 4-AEB; 5-Panorama; 6-DelayShot; 7-MotionDelayShot; 8-SlowMotionRecord; 9-LoopRecord*/
 uint8_t sdcard_state; /*< State of SDCARD: 0-Ready; 1-Error; 2-LowSpeed; 3-Protected; 4-Full; 5-NoCard; 6-UnknownFileSystem; 7-LoopRecordLackOfSpace*/
 int8_t camera_temperature; /*< Temperature of camera in Celsius Degree*/
 uint8_t resv0; /*< reserved for future use*/
 uint8_t resv1; /*< reserved for future use*/
} alink_camera_status_t;

#define ALINK_MSG_ID_CAMERA_STATUS_LEN 10
#define ALINK_MSG_ID_149_LEN 10

#define ALINK_MSG_ID_CAMERA_STATUS_CRC 243
#define ALINK_MSG_ID_149_CRC 243



#define ALINK_MESSAGE_INFO_CAMERA_STATUS { \
	"CAMERA_STATUS", \
	8, \
	{  { "resv2", NULL, ALINK_TYPE_UINT16_T, 0, 0, offsetof(alink_camera_status_t, resv2) }, \
         { "resv3", NULL, ALINK_TYPE_UINT16_T, 0, 2, offsetof(alink_camera_status_t, resv3) }, \
         { "state", NULL, ALINK_TYPE_UINT8_T, 0, 4, offsetof(alink_camera_status_t, state) }, \
         { "mode", NULL, ALINK_TYPE_UINT8_T, 0, 5, offsetof(alink_camera_status_t, mode) }, \
         { "sdcard_state", NULL, ALINK_TYPE_UINT8_T, 0, 6, offsetof(alink_camera_status_t, sdcard_state) }, \
         { "camera_temperature", NULL, ALINK_TYPE_INT8_T, 0, 7, offsetof(alink_camera_status_t, camera_temperature) }, \
         { "resv0", NULL, ALINK_TYPE_UINT8_T, 0, 8, offsetof(alink_camera_status_t, resv0) }, \
         { "resv1", NULL, ALINK_TYPE_UINT8_T, 0, 9, offsetof(alink_camera_status_t, resv1) }, \
         } \
}


/**
 * @brief Pack a camera_status message
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 *
 * @param state State of camera: 0-Idle; 1-Recording; 2-Capturing 
 * @param mode Mode of camera: 0-Record; 1-Single; 2-Burst; 3-Timelapse; 4-AEB; 5-Panorama; 6-DelayShot; 7-MotionDelayShot; 8-SlowMotionRecord; 9-LoopRecord
 * @param sdcard_state State of SDCARD: 0-Ready; 1-Error; 2-LowSpeed; 3-Protected; 4-Full; 5-NoCard; 6-UnknownFileSystem; 7-LoopRecordLackOfSpace
 * @param camera_temperature Temperature of camera in Celsius Degree
 * @param resv0 reserved for future use
 * @param resv1 reserved for future use
 * @param resv2 reserved for future use
 * @param resv3 reserved for future use
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_camera_status_pack(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg,
						       uint8_t state, uint8_t mode, uint8_t sdcard_state, int8_t camera_temperature, uint8_t resv0, uint8_t resv1, uint16_t resv2, uint16_t resv3)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_CAMERA_STATUS_LEN];
	_mav_put_uint16_t(buf, 0, resv2);
	_mav_put_uint16_t(buf, 2, resv3);
	_mav_put_uint8_t(buf, 4, state);
	_mav_put_uint8_t(buf, 5, mode);
	_mav_put_uint8_t(buf, 6, sdcard_state);
	_mav_put_int8_t(buf, 7, camera_temperature);
	_mav_put_uint8_t(buf, 8, resv0);
	_mav_put_uint8_t(buf, 9, resv1);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_CAMERA_STATUS_LEN);
#else
	alink_camera_status_t packet;
	packet.resv2 = resv2;
	packet.resv3 = resv3;
	packet.state = state;
	packet.mode = mode;
	packet.sdcard_state = sdcard_state;
	packet.camera_temperature = camera_temperature;
	packet.resv0 = resv0;
	packet.resv1 = resv1;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_CAMERA_STATUS_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_CAMERA_STATUS;
#if ALINK_CRC_EXTRA
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_CAMERA_STATUS_LEN,ALINK_MSG_ID_CAMERA_STATUS_CRC);
#else
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_CAMERA_STATUS_LEN);
#endif
}

/**
 * @brief Pack a camera_status message on a channel
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param state State of camera: 0-Idle; 1-Recording; 2-Capturing 
 * @param mode Mode of camera: 0-Record; 1-Single; 2-Burst; 3-Timelapse; 4-AEB; 5-Panorama; 6-DelayShot; 7-MotionDelayShot; 8-SlowMotionRecord; 9-LoopRecord
 * @param sdcard_state State of SDCARD: 0-Ready; 1-Error; 2-LowSpeed; 3-Protected; 4-Full; 5-NoCard; 6-UnknownFileSystem; 7-LoopRecordLackOfSpace
 * @param camera_temperature Temperature of camera in Celsius Degree
 * @param resv0 reserved for future use
 * @param resv1 reserved for future use
 * @param resv2 reserved for future use
 * @param resv3 reserved for future use
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_camera_status_pack_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan,
							   alink_message_head_t* msg,
						           uint8_t state,uint8_t mode,uint8_t sdcard_state,int8_t camera_temperature,uint8_t resv0,uint8_t resv1,uint16_t resv2,uint16_t resv3)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_CAMERA_STATUS_LEN];
	_mav_put_uint16_t(buf, 0, resv2);
	_mav_put_uint16_t(buf, 2, resv3);
	_mav_put_uint8_t(buf, 4, state);
	_mav_put_uint8_t(buf, 5, mode);
	_mav_put_uint8_t(buf, 6, sdcard_state);
	_mav_put_int8_t(buf, 7, camera_temperature);
	_mav_put_uint8_t(buf, 8, resv0);
	_mav_put_uint8_t(buf, 9, resv1);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_CAMERA_STATUS_LEN);
#else
	alink_camera_status_t packet;
	packet.resv2 = resv2;
	packet.resv3 = resv3;
	packet.state = state;
	packet.mode = mode;
	packet.sdcard_state = sdcard_state;
	packet.camera_temperature = camera_temperature;
	packet.resv0 = resv0;
	packet.resv1 = resv1;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_CAMERA_STATUS_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_CAMERA_STATUS;
#if ALINK_CRC_EXTRA
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_CAMERA_STATUS_LEN,ALINK_MSG_ID_CAMERA_STATUS_CRC);
#else
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_CAMERA_STATUS_LEN);
#endif
}
/**
 * @brief Encode a camera_status struct
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 * @param camera_status C-struct to read the message contents from
 */
static inline uint16_t alink_msg_camera_status_encode(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg, const alink_camera_status_t* camera_status)
{
	return alink_msg_camera_status_pack(dest_id, source_id, msg, camera_status->state, camera_status->mode, camera_status->sdcard_state, camera_status->camera_temperature, camera_status->resv0, camera_status->resv1, camera_status->resv2, camera_status->resv3);
}

/**
 * @brief Encode a camera_status struct on a channel
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param camera_status C-struct to read the message contents from
 */
static inline uint16_t alink_msg_camera_status_encode_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan, alink_message_head_t* msg, const alink_camera_status_t* camera_status)
{
	return alink_msg_camera_status_pack_chan(dest_id, source_id, chan, msg, camera_status->state, camera_status->mode, camera_status->sdcard_state, camera_status->camera_temperature, camera_status->resv0, camera_status->resv1, camera_status->resv2, camera_status->resv3);
}
// MESSAGE CAMERA_STATUS UNPACKING


/**
 * @brief Get field state from camera_status message
 *
 * @return State of camera: 0-Idle; 1-Recording; 2-Capturing 
 */
static inline uint8_t alink_msg_camera_status_get_state(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  4);
}

/**
 * @brief Get field mode from camera_status message
 *
 * @return Mode of camera: 0-Record; 1-Single; 2-Burst; 3-Timelapse; 4-AEB; 5-Panorama; 6-DelayShot; 7-MotionDelayShot; 8-SlowMotionRecord; 9-LoopRecord
 */
static inline uint8_t alink_msg_camera_status_get_mode(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  5);
}

/**
 * @brief Get field sdcard_state from camera_status message
 *
 * @return State of SDCARD: 0-Ready; 1-Error; 2-LowSpeed; 3-Protected; 4-Full; 5-NoCard; 6-UnknownFileSystem; 7-LoopRecordLackOfSpace
 */
static inline uint8_t alink_msg_camera_status_get_sdcard_state(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  6);
}

/**
 * @brief Get field camera_temperature from camera_status message
 *
 * @return Temperature of camera in Celsius Degree
 */
static inline int8_t alink_msg_camera_status_get_camera_temperature(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int8_t(msg,  7);
}

/**
 * @brief Get field resv0 from camera_status message
 *
 * @return reserved for future use
 */
static inline uint8_t alink_msg_camera_status_get_resv0(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  8);
}

/**
 * @brief Get field resv1 from camera_status message
 *
 * @return reserved for future use
 */
static inline uint8_t alink_msg_camera_status_get_resv1(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  9);
}

/**
 * @brief Get field resv2 from camera_status message
 *
 * @return reserved for future use
 */
static inline uint16_t alink_msg_camera_status_get_resv2(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  0);
}

/**
 * @brief Get field resv3 from camera_status message
 *
 * @return reserved for future use
 */
static inline uint16_t alink_msg_camera_status_get_resv3(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  2);
}

/**
 * @brief Decode a camera_status message into a struct
 *
 * @param msg The message to decode
 * @param camera_status C-struct to decode the message contents into
 */
static inline void alink_msg_camera_status_decode(const alink_message_head_t* msg, alink_camera_status_t* camera_status)
{
#if ALINK_NEED_BYTE_SWAP
	camera_status->resv2 = alink_msg_camera_status_get_resv2(msg);
	camera_status->resv3 = alink_msg_camera_status_get_resv3(msg);
	camera_status->state = alink_msg_camera_status_get_state(msg);
	camera_status->mode = alink_msg_camera_status_get_mode(msg);
	camera_status->sdcard_state = alink_msg_camera_status_get_sdcard_state(msg);
	camera_status->camera_temperature = alink_msg_camera_status_get_camera_temperature(msg);
	camera_status->resv0 = alink_msg_camera_status_get_resv0(msg);
	camera_status->resv1 = alink_msg_camera_status_get_resv1(msg);
#else
	memcpy(camera_status, _MAV_PAYLOAD(msg), ALINK_MSG_ID_CAMERA_STATUS_LEN);
#endif
}
