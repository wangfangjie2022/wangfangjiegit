// MESSAGE SYSTEM_BINDING PACKING

#define ALINK_MSG_ID_SYSTEM_BINDING 151

typedef struct __alink_system_binding_t
{
 int8_t data; /*< 0 – 表示对主遥控器, 1 – 表示对从遥控器, 回复时，0 - 表示收到消息， 1 - 表示配对失败， 2 - 表示配对成功.*/
} alink_system_binding_t;

#define ALINK_MSG_ID_SYSTEM_BINDING_LEN 1
#define ALINK_MSG_ID_151_LEN 1

#define ALINK_MSG_ID_SYSTEM_BINDING_CRC 238
#define ALINK_MSG_ID_151_CRC 238



#define ALINK_MESSAGE_INFO_SYSTEM_BINDING { \
	"SYSTEM_BINDING", \
	1, \
	{  { "data", NULL, ALINK_TYPE_INT8_T, 0, 0, offsetof(alink_system_binding_t, data) }, \
         } \
}


/**
 * @brief Pack a system_binding message
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 *
 * @param data 0 – 表示对主遥控器, 1 – 表示对从遥控器, 回复时，0 - 表示收到消息， 1 - 表示配对失败， 2 - 表示配对成功.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_system_binding_pack(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg,
						       int8_t data)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_SYSTEM_BINDING_LEN];
	_mav_put_int8_t(buf, 0, data);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_SYSTEM_BINDING_LEN);
#else
	alink_system_binding_t packet;
	packet.data = data;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_SYSTEM_BINDING_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_SYSTEM_BINDING;
#if ALINK_CRC_EXTRA
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_SYSTEM_BINDING_LEN,ALINK_MSG_ID_SYSTEM_BINDING_CRC);
#else
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_SYSTEM_BINDING_LEN);
#endif
}

/**
 * @brief Pack a system_binding message on a channel
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param data 0 – 表示对主遥控器, 1 – 表示对从遥控器, 回复时，0 - 表示收到消息， 1 - 表示配对失败， 2 - 表示配对成功.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_system_binding_pack_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan,
							   alink_message_head_t* msg,
						           int8_t data)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_SYSTEM_BINDING_LEN];
	_mav_put_int8_t(buf, 0, data);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_SYSTEM_BINDING_LEN);
#else
	alink_system_binding_t packet;
	packet.data = data;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_SYSTEM_BINDING_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_SYSTEM_BINDING;
#if ALINK_CRC_EXTRA
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_SYSTEM_BINDING_LEN,ALINK_MSG_ID_SYSTEM_BINDING_CRC);
#else
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_SYSTEM_BINDING_LEN);
#endif
}
/**
 * @brief Encode a system_binding struct
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 * @param system_binding C-struct to read the message contents from
 */
static inline uint16_t alink_msg_system_binding_encode(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg, const alink_system_binding_t* system_binding)
{
	return alink_msg_system_binding_pack(dest_id, source_id, msg, system_binding->data);
}

/**
 * @brief Encode a system_binding struct on a channel
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param system_binding C-struct to read the message contents from
 */
static inline uint16_t alink_msg_system_binding_encode_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan, alink_message_head_t* msg, const alink_system_binding_t* system_binding)
{
	return alink_msg_system_binding_pack_chan(dest_id, source_id, chan, msg, system_binding->data);
}
// MESSAGE SYSTEM_BINDING UNPACKING


/**
 * @brief Get field data from system_binding message
 *
 * @return 0 – 表示对主遥控器, 1 – 表示对从遥控器, 回复时，0 - 表示收到消息， 1 - 表示配对失败， 2 - 表示配对成功.
 */
static inline int8_t alink_msg_system_binding_get_data(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int8_t(msg,  0);
}

/**
 * @brief Decode a system_binding message into a struct
 *
 * @param msg The message to decode
 * @param system_binding C-struct to decode the message contents into
 */
static inline void alink_msg_system_binding_decode(const alink_message_head_t* msg, alink_system_binding_t* system_binding)
{
#if ALINK_NEED_BYTE_SWAP
	system_binding->data = alink_msg_system_binding_get_data(msg);
#else
	memcpy(system_binding, _MAV_PAYLOAD(msg), ALINK_MSG_ID_SYSTEM_BINDING_LEN);
#endif
}
