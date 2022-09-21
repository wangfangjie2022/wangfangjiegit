// MESSAGE MOVIDUS_CALIBRATION PACKING

#define ALINK_MSG_ID_MOVIDUS_CALIBRATION 118

typedef struct __alink_movidus_calibration_t
{
 uint32_t frame_num; /*<  frame number of the calibration data, if -1 the last frame */
 uint8_t data[1]; /*<  calinbration data / calibration result start offset */
} alink_movidus_calibration_t;

#define ALINK_MSG_ID_MOVIDUS_CALIBRATION_LEN 5
#define ALINK_MSG_ID_118_LEN 5

#define ALINK_MSG_ID_MOVIDUS_CALIBRATION_CRC 79
#define ALINK_MSG_ID_118_CRC 79

#define ALINK_MSG_MOVIDUS_CALIBRATION_FIELD_DATA_LEN 1

#define ALINK_MESSAGE_INFO_MOVIDUS_CALIBRATION { \
	"MOVIDUS_CALIBRATION", \
	2, \
	{  { "frame_num", NULL, ALINK_TYPE_UINT32_T, 0, 0, offsetof(alink_movidus_calibration_t, frame_num) }, \
         { "data", NULL, ALINK_TYPE_UINT8_T, 1, 4, offsetof(alink_movidus_calibration_t, data) }, \
         } \
}


/**
 * @brief Pack a movidus_calibration message
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 *
 * @param frame_num  frame number of the calibration data, if -1 the last frame 
 * @param data  calinbration data / calibration result start offset 
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_movidus_calibration_pack(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg,
						       uint32_t frame_num, const uint8_t *data)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_MOVIDUS_CALIBRATION_LEN];
	_mav_put_uint32_t(buf, 0, frame_num);
	_mav_put_uint8_t_array(buf, 4, data, 1);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_MOVIDUS_CALIBRATION_LEN);
#else
	alink_movidus_calibration_t packet;
	packet.frame_num = frame_num;
	mav_array_memcpy(packet.data, data, sizeof(uint8_t)*1);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_MOVIDUS_CALIBRATION_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_MOVIDUS_CALIBRATION;
#if ALINK_CRC_EXTRA
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_MOVIDUS_CALIBRATION_LEN,ALINK_MSG_ID_MOVIDUS_CALIBRATION_CRC);
#else
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_MOVIDUS_CALIBRATION_LEN);
#endif
}

/**
 * @brief Pack a movidus_calibration message on a channel
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param frame_num  frame number of the calibration data, if -1 the last frame 
 * @param data  calinbration data / calibration result start offset 
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_movidus_calibration_pack_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan,
							   alink_message_head_t* msg,
						           uint32_t frame_num,const uint8_t *data)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_MOVIDUS_CALIBRATION_LEN];
	_mav_put_uint32_t(buf, 0, frame_num);
	_mav_put_uint8_t_array(buf, 4, data, 1);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_MOVIDUS_CALIBRATION_LEN);
#else
	alink_movidus_calibration_t packet;
	packet.frame_num = frame_num;
	mav_array_memcpy(packet.data, data, sizeof(uint8_t)*1);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_MOVIDUS_CALIBRATION_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_MOVIDUS_CALIBRATION;
#if ALINK_CRC_EXTRA
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_MOVIDUS_CALIBRATION_LEN,ALINK_MSG_ID_MOVIDUS_CALIBRATION_CRC);
#else
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_MOVIDUS_CALIBRATION_LEN);
#endif
}
/**
 * @brief Encode a movidus_calibration struct
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 * @param movidus_calibration C-struct to read the message contents from
 */
static inline uint16_t alink_msg_movidus_calibration_encode(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg, const alink_movidus_calibration_t* movidus_calibration)
{
	return alink_msg_movidus_calibration_pack(dest_id, source_id, msg, movidus_calibration->frame_num, movidus_calibration->data);
}

/**
 * @brief Encode a movidus_calibration struct on a channel
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param movidus_calibration C-struct to read the message contents from
 */
static inline uint16_t alink_msg_movidus_calibration_encode_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan, alink_message_head_t* msg, const alink_movidus_calibration_t* movidus_calibration)
{
	return alink_msg_movidus_calibration_pack_chan(dest_id, source_id, chan, msg, movidus_calibration->frame_num, movidus_calibration->data);
}
// MESSAGE MOVIDUS_CALIBRATION UNPACKING


/**
 * @brief Get field frame_num from movidus_calibration message
 *
 * @return  frame number of the calibration data, if -1 the last frame 
 */
static inline uint32_t alink_msg_movidus_calibration_get_frame_num(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field data from movidus_calibration message
 *
 * @return  calinbration data / calibration result start offset 
 */
static inline uint16_t alink_msg_movidus_calibration_get_data(const alink_message_head_t* msg, uint8_t *data)
{
	return _MAV_RETURN_uint8_t_array(msg, data, 1,  4);
}

/**
 * @brief Decode a movidus_calibration message into a struct
 *
 * @param msg The message to decode
 * @param movidus_calibration C-struct to decode the message contents into
 */
static inline void alink_msg_movidus_calibration_decode(const alink_message_head_t* msg, alink_movidus_calibration_t* movidus_calibration)
{
#if ALINK_NEED_BYTE_SWAP
	movidus_calibration->frame_num = alink_msg_movidus_calibration_get_frame_num(msg);
	alink_msg_movidus_calibration_get_data(msg, movidus_calibration->data);
#else
	memcpy(movidus_calibration, _MAV_PAYLOAD(msg), ALINK_MSG_ID_MOVIDUS_CALIBRATION_LEN);
#endif
}
