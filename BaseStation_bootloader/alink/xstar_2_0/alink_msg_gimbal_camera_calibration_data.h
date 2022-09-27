// MESSAGE GIMBAL_CAMERA_CALIBRATION_DATA PACKING

#define ALINK_MSG_ID_GIMBAL_CAMERA_CALIBRATION_DATA 58

typedef struct __alink_gimbal_camera_calibration_data_t
{
 int16_t packageid; /*< current package id */
 int16_t data_len; /*< current package data length */
 uint8_t data[240]; /*< Calibration file data */
} alink_gimbal_camera_calibration_data_t;

#define ALINK_MSG_ID_GIMBAL_CAMERA_CALIBRATION_DATA_LEN 244
#define ALINK_MSG_ID_58_LEN 244

#define ALINK_MSG_ID_GIMBAL_CAMERA_CALIBRATION_DATA_CRC 57
#define ALINK_MSG_ID_58_CRC 57

#define ALINK_MSG_GIMBAL_CAMERA_CALIBRATION_DATA_FIELD_DATA_LEN 240

#define ALINK_MESSAGE_INFO_GIMBAL_CAMERA_CALIBRATION_DATA { \
	"GIMBAL_CAMERA_CALIBRATION_DATA", \
	3, \
	{  { "packageid", NULL, ALINK_TYPE_INT16_T, 0, 0, offsetof(alink_gimbal_camera_calibration_data_t, packageid) }, \
         { "data_len", NULL, ALINK_TYPE_INT16_T, 0, 2, offsetof(alink_gimbal_camera_calibration_data_t, data_len) }, \
         { "data", NULL, ALINK_TYPE_UINT8_T, 240, 4, offsetof(alink_gimbal_camera_calibration_data_t, data) }, \
         } \
}


/**
 * @brief Pack a gimbal_camera_calibration_data message
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 *
 * @param packageid current package id 
 * @param data_len current package data length 
 * @param data Calibration file data 
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_gimbal_camera_calibration_data_pack(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg,
						       int16_t packageid, int16_t data_len, const uint8_t *data)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_GIMBAL_CAMERA_CALIBRATION_DATA_LEN];
	_mav_put_int16_t(buf, 0, packageid);
	_mav_put_int16_t(buf, 2, data_len);
	_mav_put_uint8_t_array(buf, 4, data, 240);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_GIMBAL_CAMERA_CALIBRATION_DATA_LEN);
#else
	alink_gimbal_camera_calibration_data_t packet;
	packet.packageid = packageid;
	packet.data_len = data_len;
	mav_array_memcpy(packet.data, data, sizeof(uint8_t)*240);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_GIMBAL_CAMERA_CALIBRATION_DATA_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_GIMBAL_CAMERA_CALIBRATION_DATA;
#if ALINK_CRC_EXTRA
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_GIMBAL_CAMERA_CALIBRATION_DATA_LEN,ALINK_MSG_ID_GIMBAL_CAMERA_CALIBRATION_DATA_CRC);
#else
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_GIMBAL_CAMERA_CALIBRATION_DATA_LEN);
#endif
}

/**
 * @brief Pack a gimbal_camera_calibration_data message on a channel
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param packageid current package id 
 * @param data_len current package data length 
 * @param data Calibration file data 
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_gimbal_camera_calibration_data_pack_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan,
							   alink_message_head_t* msg,
						           int16_t packageid,int16_t data_len,const uint8_t *data)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_GIMBAL_CAMERA_CALIBRATION_DATA_LEN];
	_mav_put_int16_t(buf, 0, packageid);
	_mav_put_int16_t(buf, 2, data_len);
	_mav_put_uint8_t_array(buf, 4, data, 240);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_GIMBAL_CAMERA_CALIBRATION_DATA_LEN);
#else
	alink_gimbal_camera_calibration_data_t packet;
	packet.packageid = packageid;
	packet.data_len = data_len;
	mav_array_memcpy(packet.data, data, sizeof(uint8_t)*240);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_GIMBAL_CAMERA_CALIBRATION_DATA_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_GIMBAL_CAMERA_CALIBRATION_DATA;
#if ALINK_CRC_EXTRA
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_GIMBAL_CAMERA_CALIBRATION_DATA_LEN,ALINK_MSG_ID_GIMBAL_CAMERA_CALIBRATION_DATA_CRC);
#else
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_GIMBAL_CAMERA_CALIBRATION_DATA_LEN);
#endif
}
/**
 * @brief Encode a gimbal_camera_calibration_data struct
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 * @param gimbal_camera_calibration_data C-struct to read the message contents from
 */
static inline uint16_t alink_msg_gimbal_camera_calibration_data_encode(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg, const alink_gimbal_camera_calibration_data_t* gimbal_camera_calibration_data)
{
	return alink_msg_gimbal_camera_calibration_data_pack(dest_id, source_id, msg, gimbal_camera_calibration_data->packageid, gimbal_camera_calibration_data->data_len, gimbal_camera_calibration_data->data);
}

/**
 * @brief Encode a gimbal_camera_calibration_data struct on a channel
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param gimbal_camera_calibration_data C-struct to read the message contents from
 */
static inline uint16_t alink_msg_gimbal_camera_calibration_data_encode_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan, alink_message_head_t* msg, const alink_gimbal_camera_calibration_data_t* gimbal_camera_calibration_data)
{
	return alink_msg_gimbal_camera_calibration_data_pack_chan(dest_id, source_id, chan, msg, gimbal_camera_calibration_data->packageid, gimbal_camera_calibration_data->data_len, gimbal_camera_calibration_data->data);
}
// MESSAGE GIMBAL_CAMERA_CALIBRATION_DATA UNPACKING


/**
 * @brief Get field packageid from gimbal_camera_calibration_data message
 *
 * @return current package id 
 */
static inline int16_t alink_msg_gimbal_camera_calibration_data_get_packageid(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  0);
}

/**
 * @brief Get field data_len from gimbal_camera_calibration_data message
 *
 * @return current package data length 
 */
static inline int16_t alink_msg_gimbal_camera_calibration_data_get_data_len(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  2);
}

/**
 * @brief Get field data from gimbal_camera_calibration_data message
 *
 * @return Calibration file data 
 */
static inline uint16_t alink_msg_gimbal_camera_calibration_data_get_data(const alink_message_head_t* msg, uint8_t *data)
{
	return _MAV_RETURN_uint8_t_array(msg, data, 240,  4);
}

/**
 * @brief Decode a gimbal_camera_calibration_data message into a struct
 *
 * @param msg The message to decode
 * @param gimbal_camera_calibration_data C-struct to decode the message contents into
 */
static inline void alink_msg_gimbal_camera_calibration_data_decode(const alink_message_head_t* msg, alink_gimbal_camera_calibration_data_t* gimbal_camera_calibration_data)
{
#if ALINK_NEED_BYTE_SWAP
	gimbal_camera_calibration_data->packageid = alink_msg_gimbal_camera_calibration_data_get_packageid(msg);
	gimbal_camera_calibration_data->data_len = alink_msg_gimbal_camera_calibration_data_get_data_len(msg);
	alink_msg_gimbal_camera_calibration_data_get_data(msg, gimbal_camera_calibration_data->data);
#else
	memcpy(gimbal_camera_calibration_data, _MAV_PAYLOAD(msg), ALINK_MSG_ID_GIMBAL_CAMERA_CALIBRATION_DATA_LEN);
#endif
}
