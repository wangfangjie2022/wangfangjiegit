// MESSAGE ESC_STATE PACKING

#define ALINK_MSG_ID_ESC_STATE 61

typedef struct __alink_esc_state_t
{
 float speed; /*< The ESC current speed in RPM*/
 uint8_t state; /*< The ESC current state*/
} alink_esc_state_t;

#define ALINK_MSG_ID_ESC_STATE_LEN 5
#define ALINK_MSG_ID_61_LEN 5

#define ALINK_MSG_ID_ESC_STATE_CRC 138
#define ALINK_MSG_ID_61_CRC 138



#define ALINK_MESSAGE_INFO_ESC_STATE { \
	"ESC_STATE", \
	2, \
	{  { "speed", NULL, ALINK_TYPE_FLOAT, 0, 0, offsetof(alink_esc_state_t, speed) }, \
         { "state", NULL, ALINK_TYPE_UINT8_T, 0, 4, offsetof(alink_esc_state_t, state) }, \
         } \
}


/**
 * @brief Pack a esc_state message
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 *
 * @param speed The ESC current speed in RPM
 * @param state The ESC current state
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_esc_state_pack(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg,
						       float speed, uint8_t state)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_ESC_STATE_LEN];
	_mav_put_float(buf, 0, speed);
	_mav_put_uint8_t(buf, 4, state);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_ESC_STATE_LEN);
#else
	alink_esc_state_t packet;
	packet.speed = speed;
	packet.state = state;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_ESC_STATE_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_ESC_STATE;
#if ALINK_CRC_EXTRA
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_ESC_STATE_LEN,ALINK_MSG_ID_ESC_STATE_CRC);
#else
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_ESC_STATE_LEN);
#endif
}

/**
 * @brief Pack a esc_state message on a channel
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param speed The ESC current speed in RPM
 * @param state The ESC current state
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_esc_state_pack_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan,
							   alink_message_head_t* msg,
						           float speed,uint8_t state)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_ESC_STATE_LEN];
	_mav_put_float(buf, 0, speed);
	_mav_put_uint8_t(buf, 4, state);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_ESC_STATE_LEN);
#else
	alink_esc_state_t packet;
	packet.speed = speed;
	packet.state = state;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_ESC_STATE_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_ESC_STATE;
#if ALINK_CRC_EXTRA
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_ESC_STATE_LEN,ALINK_MSG_ID_ESC_STATE_CRC);
#else
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_ESC_STATE_LEN);
#endif
}
/**
 * @brief Encode a esc_state struct
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 * @param esc_state C-struct to read the message contents from
 */
static inline uint16_t alink_msg_esc_state_encode(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg, const alink_esc_state_t* esc_state)
{
	return alink_msg_esc_state_pack(dest_id, source_id, msg, esc_state->speed, esc_state->state);
}

/**
 * @brief Encode a esc_state struct on a channel
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param esc_state C-struct to read the message contents from
 */
static inline uint16_t alink_msg_esc_state_encode_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan, alink_message_head_t* msg, const alink_esc_state_t* esc_state)
{
	return alink_msg_esc_state_pack_chan(dest_id, source_id, chan, msg, esc_state->speed, esc_state->state);
}
// MESSAGE ESC_STATE UNPACKING


/**
 * @brief Get field speed from esc_state message
 *
 * @return The ESC current speed in RPM
 */
static inline float alink_msg_esc_state_get_speed(const alink_message_head_t* msg)
{
	return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field state from esc_state message
 *
 * @return The ESC current state
 */
static inline uint8_t alink_msg_esc_state_get_state(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  4);
}

/**
 * @brief Decode a esc_state message into a struct
 *
 * @param msg The message to decode
 * @param esc_state C-struct to decode the message contents into
 */
static inline void alink_msg_esc_state_decode(const alink_message_head_t* msg, alink_esc_state_t* esc_state)
{
#if ALINK_NEED_BYTE_SWAP
	esc_state->speed = alink_msg_esc_state_get_speed(msg);
	esc_state->state = alink_msg_esc_state_get_state(msg);
#else
	memcpy(esc_state, _MAV_PAYLOAD(msg), ALINK_MSG_ID_ESC_STATE_LEN);
#endif
}
