// MESSAGE ESC_COMM_TYPE PACKING

#define ALINK_MSG_ID_ESC_COMM_TYPE 60

typedef struct __alink_esc_comm_type_t
{
 uint8_t comm_type; /*< 0:I2C, 1:CAN, 2:UART*/
} alink_esc_comm_type_t;

#define ALINK_MSG_ID_ESC_COMM_TYPE_LEN 1
#define ALINK_MSG_ID_60_LEN 1

#define ALINK_MSG_ID_ESC_COMM_TYPE_CRC 147
#define ALINK_MSG_ID_60_CRC 147



#define ALINK_MESSAGE_INFO_ESC_COMM_TYPE { \
	"ESC_COMM_TYPE", \
	1, \
	{  { "comm_type", NULL, ALINK_TYPE_UINT8_T, 0, 0, offsetof(alink_esc_comm_type_t, comm_type) }, \
         } \
}


/**
 * @brief Pack a esc_comm_type message
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 *
 * @param comm_type 0:I2C, 1:CAN, 2:UART
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_esc_comm_type_pack(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg,
						       uint8_t comm_type)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_ESC_COMM_TYPE_LEN];
	_mav_put_uint8_t(buf, 0, comm_type);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_ESC_COMM_TYPE_LEN);
#else
	alink_esc_comm_type_t packet;
	packet.comm_type = comm_type;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_ESC_COMM_TYPE_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_ESC_COMM_TYPE;
#if ALINK_CRC_EXTRA
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_ESC_COMM_TYPE_LEN,ALINK_MSG_ID_ESC_COMM_TYPE_CRC);
#else
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_ESC_COMM_TYPE_LEN);
#endif
}

/**
 * @brief Pack a esc_comm_type message on a channel
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param comm_type 0:I2C, 1:CAN, 2:UART
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_esc_comm_type_pack_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan,
							   alink_message_head_t* msg,
						           uint8_t comm_type)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_ESC_COMM_TYPE_LEN];
	_mav_put_uint8_t(buf, 0, comm_type);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_ESC_COMM_TYPE_LEN);
#else
	alink_esc_comm_type_t packet;
	packet.comm_type = comm_type;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_ESC_COMM_TYPE_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_ESC_COMM_TYPE;
#if ALINK_CRC_EXTRA
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_ESC_COMM_TYPE_LEN,ALINK_MSG_ID_ESC_COMM_TYPE_CRC);
#else
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_ESC_COMM_TYPE_LEN);
#endif
}
/**
 * @brief Encode a esc_comm_type struct
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 * @param esc_comm_type C-struct to read the message contents from
 */
static inline uint16_t alink_msg_esc_comm_type_encode(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg, const alink_esc_comm_type_t* esc_comm_type)
{
	return alink_msg_esc_comm_type_pack(dest_id, source_id, msg, esc_comm_type->comm_type);
}

/**
 * @brief Encode a esc_comm_type struct on a channel
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param esc_comm_type C-struct to read the message contents from
 */
static inline uint16_t alink_msg_esc_comm_type_encode_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan, alink_message_head_t* msg, const alink_esc_comm_type_t* esc_comm_type)
{
	return alink_msg_esc_comm_type_pack_chan(dest_id, source_id, chan, msg, esc_comm_type->comm_type);
}
// MESSAGE ESC_COMM_TYPE UNPACKING


/**
 * @brief Get field comm_type from esc_comm_type message
 *
 * @return 0:I2C, 1:CAN, 2:UART
 */
static inline uint8_t alink_msg_esc_comm_type_get_comm_type(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Decode a esc_comm_type message into a struct
 *
 * @param msg The message to decode
 * @param esc_comm_type C-struct to decode the message contents into
 */
static inline void alink_msg_esc_comm_type_decode(const alink_message_head_t* msg, alink_esc_comm_type_t* esc_comm_type)
{
#if ALINK_NEED_BYTE_SWAP
	esc_comm_type->comm_type = alink_msg_esc_comm_type_get_comm_type(msg);
#else
	memcpy(esc_comm_type, _MAV_PAYLOAD(msg), ALINK_MSG_ID_ESC_COMM_TYPE_LEN);
#endif
}
