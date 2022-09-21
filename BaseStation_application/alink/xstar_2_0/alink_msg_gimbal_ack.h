// MESSAGE GIMBAL_ACK PACKING

#define ALINK_MSG_ID_GIMBAL_ACK 56

typedef struct __alink_gimbal_ack_t
{
 int32_t data[4]; /*< response data*/
 uint8_t ack; /*< 1:ack, 0:nack*/
} alink_gimbal_ack_t;

#define ALINK_MSG_ID_GIMBAL_ACK_LEN 17
#define ALINK_MSG_ID_56_LEN 17

#define ALINK_MSG_ID_GIMBAL_ACK_CRC 247
#define ALINK_MSG_ID_56_CRC 247

#define ALINK_MSG_GIMBAL_ACK_FIELD_DATA_LEN 4

#define ALINK_MESSAGE_INFO_GIMBAL_ACK { \
	"GIMBAL_ACK", \
	2, \
	{  { "data", NULL, ALINK_TYPE_INT32_T, 4, 0, offsetof(alink_gimbal_ack_t, data) }, \
         { "ack", NULL, ALINK_TYPE_UINT8_T, 0, 16, offsetof(alink_gimbal_ack_t, ack) }, \
         } \
}


/**
 * @brief Pack a gimbal_ack message
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 *
 * @param ack 1:ack, 0:nack
 * @param data response data
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_gimbal_ack_pack(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg,
						       uint8_t ack, const int32_t *data)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_GIMBAL_ACK_LEN];
	_mav_put_uint8_t(buf, 16, ack);
	_mav_put_int32_t_array(buf, 0, data, 4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_GIMBAL_ACK_LEN);
#else
	alink_gimbal_ack_t packet;
	packet.ack = ack;
	mav_array_memcpy(packet.data, data, sizeof(int32_t)*4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_GIMBAL_ACK_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_GIMBAL_ACK;
#if ALINK_CRC_EXTRA
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_GIMBAL_ACK_LEN,ALINK_MSG_ID_GIMBAL_ACK_CRC);
#else
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_GIMBAL_ACK_LEN);
#endif
}

/**
 * @brief Pack a gimbal_ack message on a channel
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param ack 1:ack, 0:nack
 * @param data response data
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_gimbal_ack_pack_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan,
							   alink_message_head_t* msg,
						           uint8_t ack,const int32_t *data)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_GIMBAL_ACK_LEN];
	_mav_put_uint8_t(buf, 16, ack);
	_mav_put_int32_t_array(buf, 0, data, 4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_GIMBAL_ACK_LEN);
#else
	alink_gimbal_ack_t packet;
	packet.ack = ack;
	mav_array_memcpy(packet.data, data, sizeof(int32_t)*4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_GIMBAL_ACK_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_GIMBAL_ACK;
#if ALINK_CRC_EXTRA
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_GIMBAL_ACK_LEN,ALINK_MSG_ID_GIMBAL_ACK_CRC);
#else
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_GIMBAL_ACK_LEN);
#endif
}
/**
 * @brief Encode a gimbal_ack struct
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 * @param gimbal_ack C-struct to read the message contents from
 */
static inline uint16_t alink_msg_gimbal_ack_encode(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg, const alink_gimbal_ack_t* gimbal_ack)
{
	return alink_msg_gimbal_ack_pack(dest_id, source_id, msg, gimbal_ack->ack, gimbal_ack->data);
}

/**
 * @brief Encode a gimbal_ack struct on a channel
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param gimbal_ack C-struct to read the message contents from
 */
static inline uint16_t alink_msg_gimbal_ack_encode_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan, alink_message_head_t* msg, const alink_gimbal_ack_t* gimbal_ack)
{
	return alink_msg_gimbal_ack_pack_chan(dest_id, source_id, chan, msg, gimbal_ack->ack, gimbal_ack->data);
}
// MESSAGE GIMBAL_ACK UNPACKING


/**
 * @brief Get field ack from gimbal_ack message
 *
 * @return 1:ack, 0:nack
 */
static inline uint8_t alink_msg_gimbal_ack_get_ack(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  16);
}

/**
 * @brief Get field data from gimbal_ack message
 *
 * @return response data
 */
static inline uint16_t alink_msg_gimbal_ack_get_data(const alink_message_head_t* msg, int32_t *data)
{
	return _MAV_RETURN_int32_t_array(msg, data, 4,  0);
}

/**
 * @brief Decode a gimbal_ack message into a struct
 *
 * @param msg The message to decode
 * @param gimbal_ack C-struct to decode the message contents into
 */
static inline void alink_msg_gimbal_ack_decode(const alink_message_head_t* msg, alink_gimbal_ack_t* gimbal_ack)
{
#if ALINK_NEED_BYTE_SWAP
	alink_msg_gimbal_ack_get_data(msg, gimbal_ack->data);
	gimbal_ack->ack = alink_msg_gimbal_ack_get_ack(msg);
#else
	memcpy(gimbal_ack, _MAV_PAYLOAD(msg), ALINK_MSG_ID_GIMBAL_ACK_LEN);
#endif
}
