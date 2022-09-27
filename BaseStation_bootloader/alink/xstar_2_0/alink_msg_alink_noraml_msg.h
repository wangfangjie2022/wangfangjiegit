// MESSAGE ALINK_NORAML_MSG PACKING

#define ALINK_MSG_ID_ALINK_NORAML_MSG 110

typedef struct __alink_alink_noraml_msg_t
{
 uint16_t msgid; /*< message id*/
 char data; /*< 数据部分，为变长数据，但最大不超过509字节长，注意只能使用alink_finalize_message 进行打包（如：alink_finalize_message(alink_msg, DEV_DSP_RC, DEV_DSP, ALINK_MSG_ID_110_LEN + len - 1, ALINK_MSG_ID_110_CRC)）*/
} alink_alink_noraml_msg_t;

#define ALINK_MSG_ID_ALINK_NORAML_MSG_LEN 3
#define ALINK_MSG_ID_110_LEN 3

#define ALINK_MSG_ID_ALINK_NORAML_MSG_CRC 183
#define ALINK_MSG_ID_110_CRC 183



#define ALINK_MESSAGE_INFO_ALINK_NORAML_MSG { \
	"ALINK_NORAML_MSG", \
	2, \
	{  { "msgid", NULL, ALINK_TYPE_UINT16_T, 0, 0, offsetof(alink_alink_noraml_msg_t, msgid) }, \
         { "data", NULL, ALINK_TYPE_CHAR, 0, 2, offsetof(alink_alink_noraml_msg_t, data) }, \
         } \
}


/**
 * @brief Pack a alink_noraml_msg message
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 *
 * @param msgid message id
 * @param data 数据部分，为变长数据，但最大不超过509字节长，注意只能使用alink_finalize_message 进行打包（如：alink_finalize_message(alink_msg, DEV_DSP_RC, DEV_DSP, ALINK_MSG_ID_110_LEN + len - 1, ALINK_MSG_ID_110_CRC)）
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_alink_noraml_msg_pack(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg,
						       uint16_t msgid, char data)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_ALINK_NORAML_MSG_LEN];
	_mav_put_uint16_t(buf, 0, msgid);
	_mav_put_char(buf, 2, data);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_ALINK_NORAML_MSG_LEN);
#else
	alink_alink_noraml_msg_t packet;
	packet.msgid = msgid;
	packet.data = data;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_ALINK_NORAML_MSG_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_ALINK_NORAML_MSG;
#if ALINK_CRC_EXTRA
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_ALINK_NORAML_MSG_LEN,ALINK_MSG_ID_ALINK_NORAML_MSG_CRC);
#else
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_ALINK_NORAML_MSG_LEN);
#endif
}

/**
 * @brief Pack a alink_noraml_msg message on a channel
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param msgid message id
 * @param data 数据部分，为变长数据，但最大不超过509字节长，注意只能使用alink_finalize_message 进行打包（如：alink_finalize_message(alink_msg, DEV_DSP_RC, DEV_DSP, ALINK_MSG_ID_110_LEN + len - 1, ALINK_MSG_ID_110_CRC)）
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_alink_noraml_msg_pack_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan,
							   alink_message_head_t* msg,
						           uint16_t msgid,char data)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_ALINK_NORAML_MSG_LEN];
	_mav_put_uint16_t(buf, 0, msgid);
	_mav_put_char(buf, 2, data);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_ALINK_NORAML_MSG_LEN);
#else
	alink_alink_noraml_msg_t packet;
	packet.msgid = msgid;
	packet.data = data;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_ALINK_NORAML_MSG_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_ALINK_NORAML_MSG;
#if ALINK_CRC_EXTRA
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_ALINK_NORAML_MSG_LEN,ALINK_MSG_ID_ALINK_NORAML_MSG_CRC);
#else
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_ALINK_NORAML_MSG_LEN);
#endif
}
/**
 * @brief Encode a alink_noraml_msg struct
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 * @param alink_noraml_msg C-struct to read the message contents from
 */
static inline uint16_t alink_msg_alink_noraml_msg_encode(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg, const alink_alink_noraml_msg_t* alink_noraml_msg)
{
	return alink_msg_alink_noraml_msg_pack(dest_id, source_id, msg, alink_noraml_msg->msgid, alink_noraml_msg->data);
}

/**
 * @brief Encode a alink_noraml_msg struct on a channel
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param alink_noraml_msg C-struct to read the message contents from
 */
static inline uint16_t alink_msg_alink_noraml_msg_encode_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan, alink_message_head_t* msg, const alink_alink_noraml_msg_t* alink_noraml_msg)
{
	return alink_msg_alink_noraml_msg_pack_chan(dest_id, source_id, chan, msg, alink_noraml_msg->msgid, alink_noraml_msg->data);
}
// MESSAGE ALINK_NORAML_MSG UNPACKING


/**
 * @brief Get field msgid from alink_noraml_msg message
 *
 * @return message id
 */
static inline uint16_t alink_msg_alink_noraml_msg_get_msgid(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  0);
}

/**
 * @brief Get field data from alink_noraml_msg message
 *
 * @return 数据部分，为变长数据，但最大不超过509字节长，注意只能使用alink_finalize_message 进行打包（如：alink_finalize_message(alink_msg, DEV_DSP_RC, DEV_DSP, ALINK_MSG_ID_110_LEN + len - 1, ALINK_MSG_ID_110_CRC)）
 */
static inline char alink_msg_alink_noraml_msg_get_data(const alink_message_head_t* msg)
{
	return _MAV_RETURN_char(msg,  2);
}

/**
 * @brief Decode a alink_noraml_msg message into a struct
 *
 * @param msg The message to decode
 * @param alink_noraml_msg C-struct to decode the message contents into
 */
static inline void alink_msg_alink_noraml_msg_decode(const alink_message_head_t* msg, alink_alink_noraml_msg_t* alink_noraml_msg)
{
#if ALINK_NEED_BYTE_SWAP
	alink_noraml_msg->msgid = alink_msg_alink_noraml_msg_get_msgid(msg);
	alink_noraml_msg->data = alink_msg_alink_noraml_msg_get_data(msg);
#else
	memcpy(alink_noraml_msg, _MAV_PAYLOAD(msg), ALINK_MSG_ID_ALINK_NORAML_MSG_LEN);
#endif
}
