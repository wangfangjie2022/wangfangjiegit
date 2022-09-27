// MESSAGE MOVIDUS_STATUS_REPORT PACKING

#define ALINK_MSG_ID_MOVIDUS_STATUS_REPORT 116

typedef struct __alink_movidus_status_report_t
{
 uint8_t status; /*<  movidus status:  0 - fault, 1 - working */
 uint8_t reasoncode; /*< Reason code*/
} alink_movidus_status_report_t;

#define ALINK_MSG_ID_MOVIDUS_STATUS_REPORT_LEN 2
#define ALINK_MSG_ID_116_LEN 2

#define ALINK_MSG_ID_MOVIDUS_STATUS_REPORT_CRC 125
#define ALINK_MSG_ID_116_CRC 125



#define ALINK_MESSAGE_INFO_MOVIDUS_STATUS_REPORT { \
	"MOVIDUS_STATUS_REPORT", \
	2, \
	{  { "status", NULL, ALINK_TYPE_UINT8_T, 0, 0, offsetof(alink_movidus_status_report_t, status) }, \
         { "reasoncode", NULL, ALINK_TYPE_UINT8_T, 0, 1, offsetof(alink_movidus_status_report_t, reasoncode) }, \
         } \
}


/**
 * @brief Pack a movidus_status_report message
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 *
 * @param status  movidus status:  0 - fault, 1 - working 
 * @param reasoncode Reason code
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_movidus_status_report_pack(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg,
						       uint8_t status, uint8_t reasoncode)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_MOVIDUS_STATUS_REPORT_LEN];
	_mav_put_uint8_t(buf, 0, status);
	_mav_put_uint8_t(buf, 1, reasoncode);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_MOVIDUS_STATUS_REPORT_LEN);
#else
	alink_movidus_status_report_t packet;
	packet.status = status;
	packet.reasoncode = reasoncode;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_MOVIDUS_STATUS_REPORT_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_MOVIDUS_STATUS_REPORT;
#if ALINK_CRC_EXTRA
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_MOVIDUS_STATUS_REPORT_LEN,ALINK_MSG_ID_MOVIDUS_STATUS_REPORT_CRC);
#else
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_MOVIDUS_STATUS_REPORT_LEN);
#endif
}

/**
 * @brief Pack a movidus_status_report message on a channel
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param status  movidus status:  0 - fault, 1 - working 
 * @param reasoncode Reason code
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_movidus_status_report_pack_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan,
							   alink_message_head_t* msg,
						           uint8_t status,uint8_t reasoncode)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_MOVIDUS_STATUS_REPORT_LEN];
	_mav_put_uint8_t(buf, 0, status);
	_mav_put_uint8_t(buf, 1, reasoncode);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_MOVIDUS_STATUS_REPORT_LEN);
#else
	alink_movidus_status_report_t packet;
	packet.status = status;
	packet.reasoncode = reasoncode;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_MOVIDUS_STATUS_REPORT_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_MOVIDUS_STATUS_REPORT;
#if ALINK_CRC_EXTRA
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_MOVIDUS_STATUS_REPORT_LEN,ALINK_MSG_ID_MOVIDUS_STATUS_REPORT_CRC);
#else
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_MOVIDUS_STATUS_REPORT_LEN);
#endif
}
/**
 * @brief Encode a movidus_status_report struct
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 * @param movidus_status_report C-struct to read the message contents from
 */
static inline uint16_t alink_msg_movidus_status_report_encode(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg, const alink_movidus_status_report_t* movidus_status_report)
{
	return alink_msg_movidus_status_report_pack(dest_id, source_id, msg, movidus_status_report->status, movidus_status_report->reasoncode);
}

/**
 * @brief Encode a movidus_status_report struct on a channel
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param movidus_status_report C-struct to read the message contents from
 */
static inline uint16_t alink_msg_movidus_status_report_encode_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan, alink_message_head_t* msg, const alink_movidus_status_report_t* movidus_status_report)
{
	return alink_msg_movidus_status_report_pack_chan(dest_id, source_id, chan, msg, movidus_status_report->status, movidus_status_report->reasoncode);
}
// MESSAGE MOVIDUS_STATUS_REPORT UNPACKING


/**
 * @brief Get field status from movidus_status_report message
 *
 * @return  movidus status:  0 - fault, 1 - working 
 */
static inline uint8_t alink_msg_movidus_status_report_get_status(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field reasoncode from movidus_status_report message
 *
 * @return Reason code
 */
static inline uint8_t alink_msg_movidus_status_report_get_reasoncode(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  1);
}

/**
 * @brief Decode a movidus_status_report message into a struct
 *
 * @param msg The message to decode
 * @param movidus_status_report C-struct to decode the message contents into
 */
static inline void alink_msg_movidus_status_report_decode(const alink_message_head_t* msg, alink_movidus_status_report_t* movidus_status_report)
{
#if ALINK_NEED_BYTE_SWAP
	movidus_status_report->status = alink_msg_movidus_status_report_get_status(msg);
	movidus_status_report->reasoncode = alink_msg_movidus_status_report_get_reasoncode(msg);
#else
	memcpy(movidus_status_report, _MAV_PAYLOAD(msg), ALINK_MSG_ID_MOVIDUS_STATUS_REPORT_LEN);
#endif
}
