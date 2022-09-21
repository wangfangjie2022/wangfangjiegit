// MESSAGE RTK_SOL PACKING

#define ALINK_MSG_ID_RTK_SOL 168

typedef struct __alink_rtk_sol_t
{
 char rtk_solution[512]; /*< RTK solution.*/
} alink_rtk_sol_t;

#define ALINK_MSG_ID_RTK_SOL_LEN 512
#define ALINK_MSG_ID_168_LEN 512

#define ALINK_MSG_ID_RTK_SOL_CRC 194
#define ALINK_MSG_ID_168_CRC 194

#define ALINK_MSG_RTK_SOL_FIELD_RTK_SOLUTION_LEN 512

#define ALINK_MESSAGE_INFO_RTK_SOL { \
	"RTK_SOL", \
	1, \
	{  { "rtk_solution", NULL, ALINK_TYPE_CHAR, 512, 0, offsetof(alink_rtk_sol_t, rtk_solution) }, \
         } \
}


/**
 * @brief Pack a rtk_sol message
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 *
 * @param rtk_solution RTK solution.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_rtk_sol_pack(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg,
						       const char *rtk_solution)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_RTK_SOL_LEN];

	_mav_put_char_array(buf, 0, rtk_solution, 512);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_RTK_SOL_LEN);
#else
	alink_rtk_sol_t packet;

	mav_array_memcpy(packet.rtk_solution, rtk_solution, sizeof(char)*512);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_RTK_SOL_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_RTK_SOL;
#if ALINK_CRC_EXTRA
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_RTK_SOL_LEN,ALINK_MSG_ID_RTK_SOL_CRC);
#else
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_RTK_SOL_LEN);
#endif
}

/**
 * @brief Pack a rtk_sol message on a channel
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param rtk_solution RTK solution.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_rtk_sol_pack_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan,
							   alink_message_head_t* msg,
						           const char *rtk_solution)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_RTK_SOL_LEN];

	_mav_put_char_array(buf, 0, rtk_solution, 512);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_RTK_SOL_LEN);
#else
	alink_rtk_sol_t packet;

	mav_array_memcpy(packet.rtk_solution, rtk_solution, sizeof(char)*512);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_RTK_SOL_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_RTK_SOL;
#if ALINK_CRC_EXTRA
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_RTK_SOL_LEN,ALINK_MSG_ID_RTK_SOL_CRC);
#else
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_RTK_SOL_LEN);
#endif
}
/**
 * @brief Encode a rtk_sol struct
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 * @param rtk_sol C-struct to read the message contents from
 */
static inline uint16_t alink_msg_rtk_sol_encode(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg, const alink_rtk_sol_t* rtk_sol)
{
	return alink_msg_rtk_sol_pack(dest_id, source_id, msg, rtk_sol->rtk_solution);
}

/**
 * @brief Encode a rtk_sol struct on a channel
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param rtk_sol C-struct to read the message contents from
 */
static inline uint16_t alink_msg_rtk_sol_encode_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan, alink_message_head_t* msg, const alink_rtk_sol_t* rtk_sol)
{
	return alink_msg_rtk_sol_pack_chan(dest_id, source_id, chan, msg, rtk_sol->rtk_solution);
}
// MESSAGE RTK_SOL UNPACKING


/**
 * @brief Get field rtk_solution from rtk_sol message
 *
 * @return RTK solution.
 */
static inline uint16_t alink_msg_rtk_sol_get_rtk_solution(const alink_message_head_t* msg, char *rtk_solution)
{
	return _MAV_RETURN_char_array(msg, rtk_solution, 512,  0);
}

/**
 * @brief Decode a rtk_sol message into a struct
 *
 * @param msg The message to decode
 * @param rtk_sol C-struct to decode the message contents into
 */
static inline void alink_msg_rtk_sol_decode(const alink_message_head_t* msg, alink_rtk_sol_t* rtk_sol)
{
#if ALINK_NEED_BYTE_SWAP
	alink_msg_rtk_sol_get_rtk_solution(msg, rtk_sol->rtk_solution);
#else
	memcpy(rtk_sol, _MAV_PAYLOAD(msg), ALINK_MSG_ID_RTK_SOL_LEN);
#endif
}
