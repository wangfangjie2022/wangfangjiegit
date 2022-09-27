// MESSAGE SERVO_OUTPUT_RAW PACKING

#define ALINK_MSG_ID_SERVO_OUTPUT_RAW 19

typedef struct __alink_servo_output_raw_t
{
 uint64_t timestamp; /*< timestamp (microseconds since system boot)*/
 uint16_t motor1_raw; /*< Motor output 1 value, in microseconds*/
 uint16_t motor2_raw; /*< Motor output 2 value, in microseconds*/
 uint16_t motor3_raw; /*< Motor output 3 value, in microseconds*/
 uint16_t motor4_raw; /*< Motor output 4 value, in microseconds*/
 uint16_t servo1_raw; /*< Servo output 1 value, in microseconds*/
 uint16_t servo2_raw; /*< Servo output 2 value, in microseconds*/
 uint16_t servo3_raw; /*< Servo output 3 value, in microseconds*/
 uint16_t servo4_raw; /*< Servo output 4 value, in microseconds*/
} alink_servo_output_raw_t;

#define ALINK_MSG_ID_SERVO_OUTPUT_RAW_LEN 24
#define ALINK_MSG_ID_19_LEN 24

#define ALINK_MSG_ID_SERVO_OUTPUT_RAW_CRC 213
#define ALINK_MSG_ID_19_CRC 213



#define ALINK_MESSAGE_INFO_SERVO_OUTPUT_RAW { \
	"SERVO_OUTPUT_RAW", \
	9, \
	{  { "timestamp", NULL, ALINK_TYPE_UINT64_T, 0, 0, offsetof(alink_servo_output_raw_t, timestamp) }, \
         { "motor1_raw", NULL, ALINK_TYPE_UINT16_T, 0, 8, offsetof(alink_servo_output_raw_t, motor1_raw) }, \
         { "motor2_raw", NULL, ALINK_TYPE_UINT16_T, 0, 10, offsetof(alink_servo_output_raw_t, motor2_raw) }, \
         { "motor3_raw", NULL, ALINK_TYPE_UINT16_T, 0, 12, offsetof(alink_servo_output_raw_t, motor3_raw) }, \
         { "motor4_raw", NULL, ALINK_TYPE_UINT16_T, 0, 14, offsetof(alink_servo_output_raw_t, motor4_raw) }, \
         { "servo1_raw", NULL, ALINK_TYPE_UINT16_T, 0, 16, offsetof(alink_servo_output_raw_t, servo1_raw) }, \
         { "servo2_raw", NULL, ALINK_TYPE_UINT16_T, 0, 18, offsetof(alink_servo_output_raw_t, servo2_raw) }, \
         { "servo3_raw", NULL, ALINK_TYPE_UINT16_T, 0, 20, offsetof(alink_servo_output_raw_t, servo3_raw) }, \
         { "servo4_raw", NULL, ALINK_TYPE_UINT16_T, 0, 22, offsetof(alink_servo_output_raw_t, servo4_raw) }, \
         } \
}


/**
 * @brief Pack a servo_output_raw message
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 *
 * @param timestamp timestamp (microseconds since system boot)
 * @param motor1_raw Motor output 1 value, in microseconds
 * @param motor2_raw Motor output 2 value, in microseconds
 * @param motor3_raw Motor output 3 value, in microseconds
 * @param motor4_raw Motor output 4 value, in microseconds
 * @param servo1_raw Servo output 1 value, in microseconds
 * @param servo2_raw Servo output 2 value, in microseconds
 * @param servo3_raw Servo output 3 value, in microseconds
 * @param servo4_raw Servo output 4 value, in microseconds
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_servo_output_raw_pack(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg,
						       uint64_t timestamp, uint16_t motor1_raw, uint16_t motor2_raw, uint16_t motor3_raw, uint16_t motor4_raw, uint16_t servo1_raw, uint16_t servo2_raw, uint16_t servo3_raw, uint16_t servo4_raw)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_SERVO_OUTPUT_RAW_LEN];
	_mav_put_uint64_t(buf, 0, timestamp);
	_mav_put_uint16_t(buf, 8, motor1_raw);
	_mav_put_uint16_t(buf, 10, motor2_raw);
	_mav_put_uint16_t(buf, 12, motor3_raw);
	_mav_put_uint16_t(buf, 14, motor4_raw);
	_mav_put_uint16_t(buf, 16, servo1_raw);
	_mav_put_uint16_t(buf, 18, servo2_raw);
	_mav_put_uint16_t(buf, 20, servo3_raw);
	_mav_put_uint16_t(buf, 22, servo4_raw);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_SERVO_OUTPUT_RAW_LEN);
#else
	alink_servo_output_raw_t packet;
	packet.timestamp = timestamp;
	packet.motor1_raw = motor1_raw;
	packet.motor2_raw = motor2_raw;
	packet.motor3_raw = motor3_raw;
	packet.motor4_raw = motor4_raw;
	packet.servo1_raw = servo1_raw;
	packet.servo2_raw = servo2_raw;
	packet.servo3_raw = servo3_raw;
	packet.servo4_raw = servo4_raw;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_SERVO_OUTPUT_RAW_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_SERVO_OUTPUT_RAW;
#if ALINK_CRC_EXTRA
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_SERVO_OUTPUT_RAW_LEN,ALINK_MSG_ID_SERVO_OUTPUT_RAW_CRC);
#else
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_SERVO_OUTPUT_RAW_LEN);
#endif
}

/**
 * @brief Pack a servo_output_raw message on a channel
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param timestamp timestamp (microseconds since system boot)
 * @param motor1_raw Motor output 1 value, in microseconds
 * @param motor2_raw Motor output 2 value, in microseconds
 * @param motor3_raw Motor output 3 value, in microseconds
 * @param motor4_raw Motor output 4 value, in microseconds
 * @param servo1_raw Servo output 1 value, in microseconds
 * @param servo2_raw Servo output 2 value, in microseconds
 * @param servo3_raw Servo output 3 value, in microseconds
 * @param servo4_raw Servo output 4 value, in microseconds
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_servo_output_raw_pack_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan,
							   alink_message_head_t* msg,
						           uint64_t timestamp,uint16_t motor1_raw,uint16_t motor2_raw,uint16_t motor3_raw,uint16_t motor4_raw,uint16_t servo1_raw,uint16_t servo2_raw,uint16_t servo3_raw,uint16_t servo4_raw)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_SERVO_OUTPUT_RAW_LEN];
	_mav_put_uint64_t(buf, 0, timestamp);
	_mav_put_uint16_t(buf, 8, motor1_raw);
	_mav_put_uint16_t(buf, 10, motor2_raw);
	_mav_put_uint16_t(buf, 12, motor3_raw);
	_mav_put_uint16_t(buf, 14, motor4_raw);
	_mav_put_uint16_t(buf, 16, servo1_raw);
	_mav_put_uint16_t(buf, 18, servo2_raw);
	_mav_put_uint16_t(buf, 20, servo3_raw);
	_mav_put_uint16_t(buf, 22, servo4_raw);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_SERVO_OUTPUT_RAW_LEN);
#else
	alink_servo_output_raw_t packet;
	packet.timestamp = timestamp;
	packet.motor1_raw = motor1_raw;
	packet.motor2_raw = motor2_raw;
	packet.motor3_raw = motor3_raw;
	packet.motor4_raw = motor4_raw;
	packet.servo1_raw = servo1_raw;
	packet.servo2_raw = servo2_raw;
	packet.servo3_raw = servo3_raw;
	packet.servo4_raw = servo4_raw;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_SERVO_OUTPUT_RAW_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_SERVO_OUTPUT_RAW;
#if ALINK_CRC_EXTRA
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_SERVO_OUTPUT_RAW_LEN,ALINK_MSG_ID_SERVO_OUTPUT_RAW_CRC);
#else
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_SERVO_OUTPUT_RAW_LEN);
#endif
}
/**
 * @brief Encode a servo_output_raw struct
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 * @param servo_output_raw C-struct to read the message contents from
 */
static inline uint16_t alink_msg_servo_output_raw_encode(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg, const alink_servo_output_raw_t* servo_output_raw)
{
	return alink_msg_servo_output_raw_pack(dest_id, source_id, msg, servo_output_raw->timestamp, servo_output_raw->motor1_raw, servo_output_raw->motor2_raw, servo_output_raw->motor3_raw, servo_output_raw->motor4_raw, servo_output_raw->servo1_raw, servo_output_raw->servo2_raw, servo_output_raw->servo3_raw, servo_output_raw->servo4_raw);
}

/**
 * @brief Encode a servo_output_raw struct on a channel
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param servo_output_raw C-struct to read the message contents from
 */
static inline uint16_t alink_msg_servo_output_raw_encode_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan, alink_message_head_t* msg, const alink_servo_output_raw_t* servo_output_raw)
{
	return alink_msg_servo_output_raw_pack_chan(dest_id, source_id, chan, msg, servo_output_raw->timestamp, servo_output_raw->motor1_raw, servo_output_raw->motor2_raw, servo_output_raw->motor3_raw, servo_output_raw->motor4_raw, servo_output_raw->servo1_raw, servo_output_raw->servo2_raw, servo_output_raw->servo3_raw, servo_output_raw->servo4_raw);
}
// MESSAGE SERVO_OUTPUT_RAW UNPACKING


/**
 * @brief Get field timestamp from servo_output_raw message
 *
 * @return timestamp (microseconds since system boot)
 */
static inline uint64_t alink_msg_servo_output_raw_get_timestamp(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field motor1_raw from servo_output_raw message
 *
 * @return Motor output 1 value, in microseconds
 */
static inline uint16_t alink_msg_servo_output_raw_get_motor1_raw(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  8);
}

/**
 * @brief Get field motor2_raw from servo_output_raw message
 *
 * @return Motor output 2 value, in microseconds
 */
static inline uint16_t alink_msg_servo_output_raw_get_motor2_raw(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  10);
}

/**
 * @brief Get field motor3_raw from servo_output_raw message
 *
 * @return Motor output 3 value, in microseconds
 */
static inline uint16_t alink_msg_servo_output_raw_get_motor3_raw(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  12);
}

/**
 * @brief Get field motor4_raw from servo_output_raw message
 *
 * @return Motor output 4 value, in microseconds
 */
static inline uint16_t alink_msg_servo_output_raw_get_motor4_raw(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  14);
}

/**
 * @brief Get field servo1_raw from servo_output_raw message
 *
 * @return Servo output 1 value, in microseconds
 */
static inline uint16_t alink_msg_servo_output_raw_get_servo1_raw(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  16);
}

/**
 * @brief Get field servo2_raw from servo_output_raw message
 *
 * @return Servo output 2 value, in microseconds
 */
static inline uint16_t alink_msg_servo_output_raw_get_servo2_raw(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  18);
}

/**
 * @brief Get field servo3_raw from servo_output_raw message
 *
 * @return Servo output 3 value, in microseconds
 */
static inline uint16_t alink_msg_servo_output_raw_get_servo3_raw(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  20);
}

/**
 * @brief Get field servo4_raw from servo_output_raw message
 *
 * @return Servo output 4 value, in microseconds
 */
static inline uint16_t alink_msg_servo_output_raw_get_servo4_raw(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  22);
}

/**
 * @brief Decode a servo_output_raw message into a struct
 *
 * @param msg The message to decode
 * @param servo_output_raw C-struct to decode the message contents into
 */
static inline void alink_msg_servo_output_raw_decode(const alink_message_head_t* msg, alink_servo_output_raw_t* servo_output_raw)
{
#if ALINK_NEED_BYTE_SWAP
	servo_output_raw->timestamp = alink_msg_servo_output_raw_get_timestamp(msg);
	servo_output_raw->motor1_raw = alink_msg_servo_output_raw_get_motor1_raw(msg);
	servo_output_raw->motor2_raw = alink_msg_servo_output_raw_get_motor2_raw(msg);
	servo_output_raw->motor3_raw = alink_msg_servo_output_raw_get_motor3_raw(msg);
	servo_output_raw->motor4_raw = alink_msg_servo_output_raw_get_motor4_raw(msg);
	servo_output_raw->servo1_raw = alink_msg_servo_output_raw_get_servo1_raw(msg);
	servo_output_raw->servo2_raw = alink_msg_servo_output_raw_get_servo2_raw(msg);
	servo_output_raw->servo3_raw = alink_msg_servo_output_raw_get_servo3_raw(msg);
	servo_output_raw->servo4_raw = alink_msg_servo_output_raw_get_servo4_raw(msg);
#else
	memcpy(servo_output_raw, _MAV_PAYLOAD(msg), ALINK_MSG_ID_SERVO_OUTPUT_RAW_LEN);
#endif
}
