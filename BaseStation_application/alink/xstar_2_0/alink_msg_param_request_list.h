// MESSAGE PARAM_REQUEST_LIST PACKING

#define ALINK_MSG_ID_PARAM_REQUEST_LIST 16

typedef struct __alink_param_request_list_t
{
 uint8_t target_system; /*< System ID*/
 uint8_t target_component; /*< Component ID*/
} alink_param_request_list_t;

#define ALINK_MSG_ID_PARAM_REQUEST_LIST_LEN 2
#define ALINK_MSG_ID_16_LEN 2

#define ALINK_MSG_ID_PARAM_REQUEST_LIST_CRC 159
#define ALINK_MSG_ID_16_CRC 159



#define ALINK_MESSAGE_INFO_PARAM_REQUEST_LIST { \
	"PARAM_REQUEST_LIST", \
	2, \
	{  { "target_system", NULL, ALINK_TYPE_UINT8_T, 0, 0, offsetof(alink_param_request_list_t, target_system) }, \
         { "target_component", NULL, ALINK_TYPE_UINT8_T, 0, 1, offsetof(alink_param_request_list_t, target_component) }, \
         } \
}


/**
 * @brief Pack a param_request_list message
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 *
 * @param target_system System ID
 * @param target_component Component ID
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_param_request_list_pack(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg,
						       uint8_t target_system, uint8_t target_component)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_PARAM_REQUEST_LIST_LEN];
	_mav_put_uint8_t(buf, 0, target_system);
	_mav_put_uint8_t(buf, 1, target_component);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_PARAM_REQUEST_LIST_LEN);
#else
	alink_param_request_list_t packet;
	packet.target_system = target_system;
	packet.target_component = target_component;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_PARAM_REQUEST_LIST_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_PARAM_REQUEST_LIST;
#if ALINK_CRC_EXTRA
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_PARAM_REQUEST_LIST_LEN,ALINK_MSG_ID_PARAM_REQUEST_LIST_CRC);
#else
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_PARAM_REQUEST_LIST_LEN);
#endif
}

/**
 * @brief Pack a param_request_list message on a channel
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param target_system System ID
 * @param target_component Component ID
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_param_request_list_pack_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan,
							   alink_message_head_t* msg,
						           uint8_t target_system,uint8_t target_component)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_PARAM_REQUEST_LIST_LEN];
	_mav_put_uint8_t(buf, 0, target_system);
	_mav_put_uint8_t(buf, 1, target_component);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_PARAM_REQUEST_LIST_LEN);
#else
	alink_param_request_list_t packet;
	packet.target_system = target_system;
	packet.target_component = target_component;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_PARAM_REQUEST_LIST_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_PARAM_REQUEST_LIST;
#if ALINK_CRC_EXTRA
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_PARAM_REQUEST_LIST_LEN,ALINK_MSG_ID_PARAM_REQUEST_LIST_CRC);
#else
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_PARAM_REQUEST_LIST_LEN);
#endif
}
/**
 * @brief Encode a param_request_list struct
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 * @param param_request_list C-struct to read the message contents from
 */
static inline uint16_t alink_msg_param_request_list_encode(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg, const alink_param_request_list_t* param_request_list)
{
	return alink_msg_param_request_list_pack(dest_id, source_id, msg, param_request_list->target_system, param_request_list->target_component);
}

/**
 * @brief Encode a param_request_list struct on a channel
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param param_request_list C-struct to read the message contents from
 */
static inline uint16_t alink_msg_param_request_list_encode_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan, alink_message_head_t* msg, const alink_param_request_list_t* param_request_list)
{
	return alink_msg_param_request_list_pack_chan(dest_id, source_id, chan, msg, param_request_list->target_system, param_request_list->target_component);
}
// MESSAGE PARAM_REQUEST_LIST UNPACKING


/**
 * @brief Get field target_system from param_request_list message
 *
 * @return System ID
 */
static inline uint8_t alink_msg_param_request_list_get_target_system(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field target_component from param_request_list message
 *
 * @return Component ID
 */
static inline uint8_t alink_msg_param_request_list_get_target_component(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  1);
}

/**
 * @brief Decode a param_request_list message into a struct
 *
 * @param msg The message to decode
 * @param param_request_list C-struct to decode the message contents into
 */
static inline void alink_msg_param_request_list_decode(const alink_message_head_t* msg, alink_param_request_list_t* param_request_list)
{
#if ALINK_NEED_BYTE_SWAP
	param_request_list->target_system = alink_msg_param_request_list_get_target_system(msg);
	param_request_list->target_component = alink_msg_param_request_list_get_target_component(msg);
#else
	memcpy(param_request_list, _MAV_PAYLOAD(msg), ALINK_MSG_ID_PARAM_REQUEST_LIST_LEN);
#endif
}
