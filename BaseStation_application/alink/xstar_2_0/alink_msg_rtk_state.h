// MESSAGE RTK_STATE PACKING

#define ALINK_MSG_ID_RTK_STATE 170

typedef struct __alink_rtk_state_t
{
 uint16_t rtk_satellite_num; /*< rtk satellite number*/
 uint16_t reserved1; /*< reserved1*/
 uint16_t reserved2; /*< reserved2*/
 uint8_t bat_percent; /*< base station battery percent 0-100*/
 uint8_t rtk_sig_percent; /*< RTK signal percent 0-5*/
} alink_rtk_state_t;

#define ALINK_MSG_ID_RTK_STATE_LEN 8
#define ALINK_MSG_ID_170_LEN 8

#define ALINK_MSG_ID_RTK_STATE_CRC 20
#define ALINK_MSG_ID_170_CRC 20



#define ALINK_MESSAGE_INFO_RTK_STATE { \
	"RTK_STATE", \
	5, \
	{  { "rtk_satellite_num", NULL, ALINK_TYPE_UINT16_T, 0, 0, offsetof(alink_rtk_state_t, rtk_satellite_num) }, \
         { "reserved1", NULL, ALINK_TYPE_UINT16_T, 0, 2, offsetof(alink_rtk_state_t, reserved1) }, \
         { "reserved2", NULL, ALINK_TYPE_UINT16_T, 0, 4, offsetof(alink_rtk_state_t, reserved2) }, \
         { "bat_percent", NULL, ALINK_TYPE_UINT8_T, 0, 6, offsetof(alink_rtk_state_t, bat_percent) }, \
         { "rtk_sig_percent", NULL, ALINK_TYPE_UINT8_T, 0, 7, offsetof(alink_rtk_state_t, rtk_sig_percent) }, \
         } \
}


/**
 * @brief Pack a rtk_state message
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 *
 * @param bat_percent base station battery percent 0-100
 * @param rtk_sig_percent RTK signal percent 0-5
 * @param rtk_satellite_num rtk satellite number
 * @param reserved1 reserved1
 * @param reserved2 reserved2
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_rtk_state_pack(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg,
						       uint8_t bat_percent, uint8_t rtk_sig_percent, uint16_t rtk_satellite_num, uint16_t reserved1, uint16_t reserved2)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_RTK_STATE_LEN];
	_mav_put_uint16_t(buf, 0, rtk_satellite_num);
	_mav_put_uint16_t(buf, 2, reserved1);
	_mav_put_uint16_t(buf, 4, reserved2);
	_mav_put_uint8_t(buf, 6, bat_percent);
	_mav_put_uint8_t(buf, 7, rtk_sig_percent);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_RTK_STATE_LEN);
#else
	alink_rtk_state_t packet;
	packet.rtk_satellite_num = rtk_satellite_num;
	packet.reserved1 = reserved1;
	packet.reserved2 = reserved2;
	packet.bat_percent = bat_percent;
	packet.rtk_sig_percent = rtk_sig_percent;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_RTK_STATE_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_RTK_STATE;
#if ALINK_CRC_EXTRA
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_RTK_STATE_LEN,ALINK_MSG_ID_RTK_STATE_CRC);
#else
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_RTK_STATE_LEN);
#endif
}

/**
 * @brief Pack a rtk_state message on a channel
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param bat_percent base station battery percent 0-100
 * @param rtk_sig_percent RTK signal percent 0-5
 * @param rtk_satellite_num rtk satellite number
 * @param reserved1 reserved1
 * @param reserved2 reserved2
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_rtk_state_pack_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan,
							   alink_message_head_t* msg,
						           uint8_t bat_percent,uint8_t rtk_sig_percent,uint16_t rtk_satellite_num,uint16_t reserved1,uint16_t reserved2)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_RTK_STATE_LEN];
	_mav_put_uint16_t(buf, 0, rtk_satellite_num);
	_mav_put_uint16_t(buf, 2, reserved1);
	_mav_put_uint16_t(buf, 4, reserved2);
	_mav_put_uint8_t(buf, 6, bat_percent);
	_mav_put_uint8_t(buf, 7, rtk_sig_percent);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_RTK_STATE_LEN);
#else
	alink_rtk_state_t packet;
	packet.rtk_satellite_num = rtk_satellite_num;
	packet.reserved1 = reserved1;
	packet.reserved2 = reserved2;
	packet.bat_percent = bat_percent;
	packet.rtk_sig_percent = rtk_sig_percent;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_RTK_STATE_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_RTK_STATE;
#if ALINK_CRC_EXTRA
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_RTK_STATE_LEN,ALINK_MSG_ID_RTK_STATE_CRC);
#else
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_RTK_STATE_LEN);
#endif
}
/**
 * @brief Encode a rtk_state struct
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 * @param rtk_state C-struct to read the message contents from
 */
static inline uint16_t alink_msg_rtk_state_encode(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg, const alink_rtk_state_t* rtk_state)
{
	return alink_msg_rtk_state_pack(dest_id, source_id, msg, rtk_state->bat_percent, rtk_state->rtk_sig_percent, rtk_state->rtk_satellite_num, rtk_state->reserved1, rtk_state->reserved2);
}

/**
 * @brief Encode a rtk_state struct on a channel
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param rtk_state C-struct to read the message contents from
 */
static inline uint16_t alink_msg_rtk_state_encode_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan, alink_message_head_t* msg, const alink_rtk_state_t* rtk_state)
{
	return alink_msg_rtk_state_pack_chan(dest_id, source_id, chan, msg, rtk_state->bat_percent, rtk_state->rtk_sig_percent, rtk_state->rtk_satellite_num, rtk_state->reserved1, rtk_state->reserved2);
}
// MESSAGE RTK_STATE UNPACKING


/**
 * @brief Get field bat_percent from rtk_state message
 *
 * @return base station battery percent 0-100
 */
static inline uint8_t alink_msg_rtk_state_get_bat_percent(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  6);
}

/**
 * @brief Get field rtk_sig_percent from rtk_state message
 *
 * @return RTK signal percent 0-5
 */
static inline uint8_t alink_msg_rtk_state_get_rtk_sig_percent(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  7);
}

/**
 * @brief Get field rtk_satellite_num from rtk_state message
 *
 * @return rtk satellite number
 */
static inline uint16_t alink_msg_rtk_state_get_rtk_satellite_num(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  0);
}

/**
 * @brief Get field reserved1 from rtk_state message
 *
 * @return reserved1
 */
static inline uint16_t alink_msg_rtk_state_get_reserved1(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  2);
}

/**
 * @brief Get field reserved2 from rtk_state message
 *
 * @return reserved2
 */
static inline uint16_t alink_msg_rtk_state_get_reserved2(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  4);
}

/**
 * @brief Decode a rtk_state message into a struct
 *
 * @param msg The message to decode
 * @param rtk_state C-struct to decode the message contents into
 */
static inline void alink_msg_rtk_state_decode(const alink_message_head_t* msg, alink_rtk_state_t* rtk_state)
{
#if ALINK_NEED_BYTE_SWAP
	rtk_state->rtk_satellite_num = alink_msg_rtk_state_get_rtk_satellite_num(msg);
	rtk_state->reserved1 = alink_msg_rtk_state_get_reserved1(msg);
	rtk_state->reserved2 = alink_msg_rtk_state_get_reserved2(msg);
	rtk_state->bat_percent = alink_msg_rtk_state_get_bat_percent(msg);
	rtk_state->rtk_sig_percent = alink_msg_rtk_state_get_rtk_sig_percent(msg);
#else
	memcpy(rtk_state, _MAV_PAYLOAD(msg), ALINK_MSG_ID_RTK_STATE_LEN);
#endif
}
