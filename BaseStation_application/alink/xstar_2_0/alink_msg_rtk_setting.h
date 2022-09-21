// MESSAGE RTK_SETTING PACKING

#define ALINK_MSG_ID_RTK_SETTING 171

typedef struct __alink_rtk_setting_t
{
 char rtk_setting[32]; /*< RTK setting.*/
} alink_rtk_setting_t;

#define ALINK_MSG_ID_RTK_SETTING_LEN 32
#define ALINK_MSG_ID_171_LEN 32

#define ALINK_MSG_ID_RTK_SETTING_CRC 204
#define ALINK_MSG_ID_171_CRC 204

#define ALINK_MSG_RTK_SETTING_FIELD_RTK_SETTING_LEN 32

#define ALINK_MESSAGE_INFO_RTK_SETTING { \
	"RTK_SETTING", \
	1, \
	{  { "rtk_setting", NULL, ALINK_TYPE_CHAR, 32, 0, offsetof(alink_rtk_setting_t, rtk_setting) }, \
         } \
}


/**
 * @brief Pack a rtk_setting message
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 *
 * @param rtk_setting RTK setting.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_rtk_setting_pack(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg,
						       const char *rtk_setting)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_RTK_SETTING_LEN];

	_mav_put_char_array(buf, 0, rtk_setting, 32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_RTK_SETTING_LEN);
#else
	alink_rtk_setting_t packet;

	mav_array_memcpy(packet.rtk_setting, rtk_setting, sizeof(char)*32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_RTK_SETTING_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_RTK_SETTING;
#if ALINK_CRC_EXTRA
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_RTK_SETTING_LEN,ALINK_MSG_ID_RTK_SETTING_CRC);
#else
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_RTK_SETTING_LEN);
#endif
}

/**
 * @brief Pack a rtk_setting message on a channel
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param rtk_setting RTK setting.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_rtk_setting_pack_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan,
							   alink_message_head_t* msg,
						           const char *rtk_setting)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_RTK_SETTING_LEN];

	_mav_put_char_array(buf, 0, rtk_setting, 32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_RTK_SETTING_LEN);
#else
	alink_rtk_setting_t packet;

	mav_array_memcpy(packet.rtk_setting, rtk_setting, sizeof(char)*32);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_RTK_SETTING_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_RTK_SETTING;
#if ALINK_CRC_EXTRA
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_RTK_SETTING_LEN,ALINK_MSG_ID_RTK_SETTING_CRC);
#else
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_RTK_SETTING_LEN);
#endif
}
/**
 * @brief Encode a rtk_setting struct
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 * @param rtk_setting C-struct to read the message contents from
 */
static inline uint16_t alink_msg_rtk_setting_encode(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg, const alink_rtk_setting_t* rtk_setting)
{
	return alink_msg_rtk_setting_pack(dest_id, source_id, msg, rtk_setting->rtk_setting);
}

/**
 * @brief Encode a rtk_setting struct on a channel
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param rtk_setting C-struct to read the message contents from
 */
static inline uint16_t alink_msg_rtk_setting_encode_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan, alink_message_head_t* msg, const alink_rtk_setting_t* rtk_setting)
{
	return alink_msg_rtk_setting_pack_chan(dest_id, source_id, chan, msg, rtk_setting->rtk_setting);
}
// MESSAGE RTK_SETTING UNPACKING


/**
 * @brief Get field rtk_setting from rtk_setting message
 *
 * @return RTK setting.
 */
static inline uint16_t alink_msg_rtk_setting_get_rtk_setting(const alink_message_head_t* msg, char *rtk_setting)
{
	return _MAV_RETURN_char_array(msg, rtk_setting, 32,  0);
}

/**
 * @brief Decode a rtk_setting message into a struct
 *
 * @param msg The message to decode
 * @param rtk_setting C-struct to decode the message contents into
 */
static inline void alink_msg_rtk_setting_decode(const alink_message_head_t* msg, alink_rtk_setting_t* rtk_setting)
{
#if ALINK_NEED_BYTE_SWAP
	alink_msg_rtk_setting_get_rtk_setting(msg, rtk_setting->rtk_setting);
#else
	memcpy(rtk_setting, _MAV_PAYLOAD(msg), ALINK_MSG_ID_RTK_SETTING_LEN);
#endif
}
