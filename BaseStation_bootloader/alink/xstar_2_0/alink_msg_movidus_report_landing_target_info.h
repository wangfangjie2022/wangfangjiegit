// MESSAGE MOVIDUS_REPORT_LANDING_TARGET_INFO PACKING

#define ALINK_MSG_ID_MOVIDUS_REPORT_LANDING_TARGET_INFO 126

typedef struct __alink_movidus_report_landing_target_info_t
{
 uint64_t timestamp; /*< timestamp (microseconds since system boot)*/
 float Position[3]; /*< XYZ position coordinate in camera fixed coordinate system, m*/
 float Velocity[3]; /*< XYZ velocity coordinate in camera fixed coordinate system, m/s*/
 uint16_t confidence; /*< confidence of the landing target info, multiplied by 100*/
 int16_t quaternion[4]; /*< quaternion, multiplied by 10000*/
} alink_movidus_report_landing_target_info_t;

#define ALINK_MSG_ID_MOVIDUS_REPORT_LANDING_TARGET_INFO_LEN 42
#define ALINK_MSG_ID_126_LEN 42

#define ALINK_MSG_ID_MOVIDUS_REPORT_LANDING_TARGET_INFO_CRC 13
#define ALINK_MSG_ID_126_CRC 13

#define ALINK_MSG_MOVIDUS_REPORT_LANDING_TARGET_INFO_FIELD_POSITION_LEN 3
#define ALINK_MSG_MOVIDUS_REPORT_LANDING_TARGET_INFO_FIELD_VELOCITY_LEN 3
#define ALINK_MSG_MOVIDUS_REPORT_LANDING_TARGET_INFO_FIELD_QUATERNION_LEN 4

#define ALINK_MESSAGE_INFO_MOVIDUS_REPORT_LANDING_TARGET_INFO { \
	"MOVIDUS_REPORT_LANDING_TARGET_INFO", \
	5, \
	{  { "timestamp", NULL, ALINK_TYPE_UINT64_T, 0, 0, offsetof(alink_movidus_report_landing_target_info_t, timestamp) }, \
         { "Position", NULL, ALINK_TYPE_FLOAT, 3, 8, offsetof(alink_movidus_report_landing_target_info_t, Position) }, \
         { "Velocity", NULL, ALINK_TYPE_FLOAT, 3, 20, offsetof(alink_movidus_report_landing_target_info_t, Velocity) }, \
         { "confidence", NULL, ALINK_TYPE_UINT16_T, 0, 32, offsetof(alink_movidus_report_landing_target_info_t, confidence) }, \
         { "quaternion", NULL, ALINK_TYPE_INT16_T, 4, 34, offsetof(alink_movidus_report_landing_target_info_t, quaternion) }, \
         } \
}


/**
 * @brief Pack a movidus_report_landing_target_info message
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 *
 * @param timestamp timestamp (microseconds since system boot)
 * @param Position XYZ position coordinate in camera fixed coordinate system, m
 * @param Velocity XYZ velocity coordinate in camera fixed coordinate system, m/s
 * @param confidence confidence of the landing target info, multiplied by 100
 * @param quaternion quaternion, multiplied by 10000
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_movidus_report_landing_target_info_pack(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg,
						       uint64_t timestamp, const float *Position, const float *Velocity, uint16_t confidence, const int16_t *quaternion)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_MOVIDUS_REPORT_LANDING_TARGET_INFO_LEN];
	_mav_put_uint64_t(buf, 0, timestamp);
	_mav_put_uint16_t(buf, 32, confidence);
	_mav_put_float_array(buf, 8, Position, 3);
	_mav_put_float_array(buf, 20, Velocity, 3);
	_mav_put_int16_t_array(buf, 34, quaternion, 4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_MOVIDUS_REPORT_LANDING_TARGET_INFO_LEN);
#else
	alink_movidus_report_landing_target_info_t packet;
	packet.timestamp = timestamp;
	packet.confidence = confidence;
	mav_array_memcpy(packet.Position, Position, sizeof(float)*3);
	mav_array_memcpy(packet.Velocity, Velocity, sizeof(float)*3);
	mav_array_memcpy(packet.quaternion, quaternion, sizeof(int16_t)*4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_MOVIDUS_REPORT_LANDING_TARGET_INFO_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_MOVIDUS_REPORT_LANDING_TARGET_INFO;
#if ALINK_CRC_EXTRA
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_MOVIDUS_REPORT_LANDING_TARGET_INFO_LEN,ALINK_MSG_ID_MOVIDUS_REPORT_LANDING_TARGET_INFO_CRC);
#else
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_MOVIDUS_REPORT_LANDING_TARGET_INFO_LEN);
#endif
}

/**
 * @brief Pack a movidus_report_landing_target_info message on a channel
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param timestamp timestamp (microseconds since system boot)
 * @param Position XYZ position coordinate in camera fixed coordinate system, m
 * @param Velocity XYZ velocity coordinate in camera fixed coordinate system, m/s
 * @param confidence confidence of the landing target info, multiplied by 100
 * @param quaternion quaternion, multiplied by 10000
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_movidus_report_landing_target_info_pack_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan,
							   alink_message_head_t* msg,
						           uint64_t timestamp,const float *Position,const float *Velocity,uint16_t confidence,const int16_t *quaternion)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_MOVIDUS_REPORT_LANDING_TARGET_INFO_LEN];
	_mav_put_uint64_t(buf, 0, timestamp);
	_mav_put_uint16_t(buf, 32, confidence);
	_mav_put_float_array(buf, 8, Position, 3);
	_mav_put_float_array(buf, 20, Velocity, 3);
	_mav_put_int16_t_array(buf, 34, quaternion, 4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_MOVIDUS_REPORT_LANDING_TARGET_INFO_LEN);
#else
	alink_movidus_report_landing_target_info_t packet;
	packet.timestamp = timestamp;
	packet.confidence = confidence;
	mav_array_memcpy(packet.Position, Position, sizeof(float)*3);
	mav_array_memcpy(packet.Velocity, Velocity, sizeof(float)*3);
	mav_array_memcpy(packet.quaternion, quaternion, sizeof(int16_t)*4);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_MOVIDUS_REPORT_LANDING_TARGET_INFO_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_MOVIDUS_REPORT_LANDING_TARGET_INFO;
#if ALINK_CRC_EXTRA
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_MOVIDUS_REPORT_LANDING_TARGET_INFO_LEN,ALINK_MSG_ID_MOVIDUS_REPORT_LANDING_TARGET_INFO_CRC);
#else
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_MOVIDUS_REPORT_LANDING_TARGET_INFO_LEN);
#endif
}
/**
 * @brief Encode a movidus_report_landing_target_info struct
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 * @param movidus_report_landing_target_info C-struct to read the message contents from
 */
static inline uint16_t alink_msg_movidus_report_landing_target_info_encode(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg, const alink_movidus_report_landing_target_info_t* movidus_report_landing_target_info)
{
	return alink_msg_movidus_report_landing_target_info_pack(dest_id, source_id, msg, movidus_report_landing_target_info->timestamp, movidus_report_landing_target_info->Position, movidus_report_landing_target_info->Velocity, movidus_report_landing_target_info->confidence, movidus_report_landing_target_info->quaternion);
}

/**
 * @brief Encode a movidus_report_landing_target_info struct on a channel
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param movidus_report_landing_target_info C-struct to read the message contents from
 */
static inline uint16_t alink_msg_movidus_report_landing_target_info_encode_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan, alink_message_head_t* msg, const alink_movidus_report_landing_target_info_t* movidus_report_landing_target_info)
{
	return alink_msg_movidus_report_landing_target_info_pack_chan(dest_id, source_id, chan, msg, movidus_report_landing_target_info->timestamp, movidus_report_landing_target_info->Position, movidus_report_landing_target_info->Velocity, movidus_report_landing_target_info->confidence, movidus_report_landing_target_info->quaternion);
}
// MESSAGE MOVIDUS_REPORT_LANDING_TARGET_INFO UNPACKING


/**
 * @brief Get field timestamp from movidus_report_landing_target_info message
 *
 * @return timestamp (microseconds since system boot)
 */
static inline uint64_t alink_msg_movidus_report_landing_target_info_get_timestamp(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field Position from movidus_report_landing_target_info message
 *
 * @return XYZ position coordinate in camera fixed coordinate system, m
 */
static inline uint16_t alink_msg_movidus_report_landing_target_info_get_Position(const alink_message_head_t* msg, float *Position)
{
	return _MAV_RETURN_float_array(msg, Position, 3,  8);
}

/**
 * @brief Get field Velocity from movidus_report_landing_target_info message
 *
 * @return XYZ velocity coordinate in camera fixed coordinate system, m/s
 */
static inline uint16_t alink_msg_movidus_report_landing_target_info_get_Velocity(const alink_message_head_t* msg, float *Velocity)
{
	return _MAV_RETURN_float_array(msg, Velocity, 3,  20);
}

/**
 * @brief Get field confidence from movidus_report_landing_target_info message
 *
 * @return confidence of the landing target info, multiplied by 100
 */
static inline uint16_t alink_msg_movidus_report_landing_target_info_get_confidence(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  32);
}

/**
 * @brief Get field quaternion from movidus_report_landing_target_info message
 *
 * @return quaternion, multiplied by 10000
 */
static inline uint16_t alink_msg_movidus_report_landing_target_info_get_quaternion(const alink_message_head_t* msg, int16_t *quaternion)
{
	return _MAV_RETURN_int16_t_array(msg, quaternion, 4,  34);
}

/**
 * @brief Decode a movidus_report_landing_target_info message into a struct
 *
 * @param msg The message to decode
 * @param movidus_report_landing_target_info C-struct to decode the message contents into
 */
static inline void alink_msg_movidus_report_landing_target_info_decode(const alink_message_head_t* msg, alink_movidus_report_landing_target_info_t* movidus_report_landing_target_info)
{
#if ALINK_NEED_BYTE_SWAP
	movidus_report_landing_target_info->timestamp = alink_msg_movidus_report_landing_target_info_get_timestamp(msg);
	alink_msg_movidus_report_landing_target_info_get_Position(msg, movidus_report_landing_target_info->Position);
	alink_msg_movidus_report_landing_target_info_get_Velocity(msg, movidus_report_landing_target_info->Velocity);
	movidus_report_landing_target_info->confidence = alink_msg_movidus_report_landing_target_info_get_confidence(msg);
	alink_msg_movidus_report_landing_target_info_get_quaternion(msg, movidus_report_landing_target_info->quaternion);
#else
	memcpy(movidus_report_landing_target_info, _MAV_PAYLOAD(msg), ALINK_MSG_ID_MOVIDUS_REPORT_LANDING_TARGET_INFO_LEN);
#endif
}
