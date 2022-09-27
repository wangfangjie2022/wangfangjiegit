// MESSAGE MOVIDUS_PATH_PLANNING_REPORT PACKING

#define ALINK_MSG_ID_MOVIDUS_PATH_PLANNING_REPORT 121

typedef struct __alink_movidus_path_planning_report_t
{
 uint64_t timestamp; /*< timestamp (milliseconds since system boot)*/
 int32_t pos[3]; /*<  xyz position estimated in 10E-3 meter*/
 int32_t rev[3]; /*<  rev field*/
 int16_t vel[3]; /*<  velocity estimated in 10E-3 m/s*/
 int16_t aac[3]; /*<  acceleration x/y/z in 10E-3 m^2/s*/
 int16_t jerk[3]; /*<  jerk x/y/z in 10E-3 m^3/s*/
 int16_t yaw; /*<  Yaw angle in 10E-3 deg*/
 int16_t yaw_speed; /*<  Yaw angle speed in 10E-3 degrees / second*/
 uint8_t mode; /*<  PathPlanning control mode*/
} alink_movidus_path_planning_report_t;

#define ALINK_MSG_ID_MOVIDUS_PATH_PLANNING_REPORT_LEN 55
#define ALINK_MSG_ID_121_LEN 55

#define ALINK_MSG_ID_MOVIDUS_PATH_PLANNING_REPORT_CRC 126
#define ALINK_MSG_ID_121_CRC 126

#define ALINK_MSG_MOVIDUS_PATH_PLANNING_REPORT_FIELD_POS_LEN 3
#define ALINK_MSG_MOVIDUS_PATH_PLANNING_REPORT_FIELD_REV_LEN 3
#define ALINK_MSG_MOVIDUS_PATH_PLANNING_REPORT_FIELD_VEL_LEN 3
#define ALINK_MSG_MOVIDUS_PATH_PLANNING_REPORT_FIELD_AAC_LEN 3
#define ALINK_MSG_MOVIDUS_PATH_PLANNING_REPORT_FIELD_JERK_LEN 3

#define ALINK_MESSAGE_INFO_MOVIDUS_PATH_PLANNING_REPORT { \
	"MOVIDUS_PATH_PLANNING_REPORT", \
	9, \
	{  { "timestamp", NULL, ALINK_TYPE_UINT64_T, 0, 0, offsetof(alink_movidus_path_planning_report_t, timestamp) }, \
         { "pos", NULL, ALINK_TYPE_INT32_T, 3, 8, offsetof(alink_movidus_path_planning_report_t, pos) }, \
         { "rev", NULL, ALINK_TYPE_INT32_T, 3, 20, offsetof(alink_movidus_path_planning_report_t, rev) }, \
         { "vel", NULL, ALINK_TYPE_INT16_T, 3, 32, offsetof(alink_movidus_path_planning_report_t, vel) }, \
         { "aac", NULL, ALINK_TYPE_INT16_T, 3, 38, offsetof(alink_movidus_path_planning_report_t, aac) }, \
         { "jerk", NULL, ALINK_TYPE_INT16_T, 3, 44, offsetof(alink_movidus_path_planning_report_t, jerk) }, \
         { "yaw", NULL, ALINK_TYPE_INT16_T, 0, 50, offsetof(alink_movidus_path_planning_report_t, yaw) }, \
         { "yaw_speed", NULL, ALINK_TYPE_INT16_T, 0, 52, offsetof(alink_movidus_path_planning_report_t, yaw_speed) }, \
         { "mode", NULL, ALINK_TYPE_UINT8_T, 0, 54, offsetof(alink_movidus_path_planning_report_t, mode) }, \
         } \
}


/**
 * @brief Pack a movidus_path_planning_report message
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 *
 * @param timestamp timestamp (milliseconds since system boot)
 * @param mode  PathPlanning control mode
 * @param pos  xyz position estimated in 10E-3 meter
 * @param vel  velocity estimated in 10E-3 m/s
 * @param aac  acceleration x/y/z in 10E-3 m^2/s
 * @param jerk  jerk x/y/z in 10E-3 m^3/s
 * @param yaw  Yaw angle in 10E-3 deg
 * @param yaw_speed  Yaw angle speed in 10E-3 degrees / second
 * @param rev  rev field
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_movidus_path_planning_report_pack(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg,
						       uint64_t timestamp, uint8_t mode, const int32_t *pos, const int16_t *vel, const int16_t *aac, const int16_t *jerk, int16_t yaw, int16_t yaw_speed, const int32_t *rev)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_MOVIDUS_PATH_PLANNING_REPORT_LEN];
	_mav_put_uint64_t(buf, 0, timestamp);
	_mav_put_int16_t(buf, 50, yaw);
	_mav_put_int16_t(buf, 52, yaw_speed);
	_mav_put_uint8_t(buf, 54, mode);
	_mav_put_int32_t_array(buf, 8, pos, 3);
	_mav_put_int32_t_array(buf, 20, rev, 3);
	_mav_put_int16_t_array(buf, 32, vel, 3);
	_mav_put_int16_t_array(buf, 38, aac, 3);
	_mav_put_int16_t_array(buf, 44, jerk, 3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_MOVIDUS_PATH_PLANNING_REPORT_LEN);
#else
	alink_movidus_path_planning_report_t packet;
	packet.timestamp = timestamp;
	packet.yaw = yaw;
	packet.yaw_speed = yaw_speed;
	packet.mode = mode;
	mav_array_memcpy(packet.pos, pos, sizeof(int32_t)*3);
	mav_array_memcpy(packet.rev, rev, sizeof(int32_t)*3);
	mav_array_memcpy(packet.vel, vel, sizeof(int16_t)*3);
	mav_array_memcpy(packet.aac, aac, sizeof(int16_t)*3);
	mav_array_memcpy(packet.jerk, jerk, sizeof(int16_t)*3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_MOVIDUS_PATH_PLANNING_REPORT_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_MOVIDUS_PATH_PLANNING_REPORT;
#if ALINK_CRC_EXTRA
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_MOVIDUS_PATH_PLANNING_REPORT_LEN,ALINK_MSG_ID_MOVIDUS_PATH_PLANNING_REPORT_CRC);
#else
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_MOVIDUS_PATH_PLANNING_REPORT_LEN);
#endif
}

/**
 * @brief Pack a movidus_path_planning_report message on a channel
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param timestamp timestamp (milliseconds since system boot)
 * @param mode  PathPlanning control mode
 * @param pos  xyz position estimated in 10E-3 meter
 * @param vel  velocity estimated in 10E-3 m/s
 * @param aac  acceleration x/y/z in 10E-3 m^2/s
 * @param jerk  jerk x/y/z in 10E-3 m^3/s
 * @param yaw  Yaw angle in 10E-3 deg
 * @param yaw_speed  Yaw angle speed in 10E-3 degrees / second
 * @param rev  rev field
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_movidus_path_planning_report_pack_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan,
							   alink_message_head_t* msg,
						           uint64_t timestamp,uint8_t mode,const int32_t *pos,const int16_t *vel,const int16_t *aac,const int16_t *jerk,int16_t yaw,int16_t yaw_speed,const int32_t *rev)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_MOVIDUS_PATH_PLANNING_REPORT_LEN];
	_mav_put_uint64_t(buf, 0, timestamp);
	_mav_put_int16_t(buf, 50, yaw);
	_mav_put_int16_t(buf, 52, yaw_speed);
	_mav_put_uint8_t(buf, 54, mode);
	_mav_put_int32_t_array(buf, 8, pos, 3);
	_mav_put_int32_t_array(buf, 20, rev, 3);
	_mav_put_int16_t_array(buf, 32, vel, 3);
	_mav_put_int16_t_array(buf, 38, aac, 3);
	_mav_put_int16_t_array(buf, 44, jerk, 3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_MOVIDUS_PATH_PLANNING_REPORT_LEN);
#else
	alink_movidus_path_planning_report_t packet;
	packet.timestamp = timestamp;
	packet.yaw = yaw;
	packet.yaw_speed = yaw_speed;
	packet.mode = mode;
	mav_array_memcpy(packet.pos, pos, sizeof(int32_t)*3);
	mav_array_memcpy(packet.rev, rev, sizeof(int32_t)*3);
	mav_array_memcpy(packet.vel, vel, sizeof(int16_t)*3);
	mav_array_memcpy(packet.aac, aac, sizeof(int16_t)*3);
	mav_array_memcpy(packet.jerk, jerk, sizeof(int16_t)*3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_MOVIDUS_PATH_PLANNING_REPORT_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_MOVIDUS_PATH_PLANNING_REPORT;
#if ALINK_CRC_EXTRA
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_MOVIDUS_PATH_PLANNING_REPORT_LEN,ALINK_MSG_ID_MOVIDUS_PATH_PLANNING_REPORT_CRC);
#else
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_MOVIDUS_PATH_PLANNING_REPORT_LEN);
#endif
}
/**
 * @brief Encode a movidus_path_planning_report struct
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 * @param movidus_path_planning_report C-struct to read the message contents from
 */
static inline uint16_t alink_msg_movidus_path_planning_report_encode(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg, const alink_movidus_path_planning_report_t* movidus_path_planning_report)
{
	return alink_msg_movidus_path_planning_report_pack(dest_id, source_id, msg, movidus_path_planning_report->timestamp, movidus_path_planning_report->mode, movidus_path_planning_report->pos, movidus_path_planning_report->vel, movidus_path_planning_report->aac, movidus_path_planning_report->jerk, movidus_path_planning_report->yaw, movidus_path_planning_report->yaw_speed, movidus_path_planning_report->rev);
}

/**
 * @brief Encode a movidus_path_planning_report struct on a channel
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param movidus_path_planning_report C-struct to read the message contents from
 */
static inline uint16_t alink_msg_movidus_path_planning_report_encode_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan, alink_message_head_t* msg, const alink_movidus_path_planning_report_t* movidus_path_planning_report)
{
	return alink_msg_movidus_path_planning_report_pack_chan(dest_id, source_id, chan, msg, movidus_path_planning_report->timestamp, movidus_path_planning_report->mode, movidus_path_planning_report->pos, movidus_path_planning_report->vel, movidus_path_planning_report->aac, movidus_path_planning_report->jerk, movidus_path_planning_report->yaw, movidus_path_planning_report->yaw_speed, movidus_path_planning_report->rev);
}
// MESSAGE MOVIDUS_PATH_PLANNING_REPORT UNPACKING


/**
 * @brief Get field timestamp from movidus_path_planning_report message
 *
 * @return timestamp (milliseconds since system boot)
 */
static inline uint64_t alink_msg_movidus_path_planning_report_get_timestamp(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field mode from movidus_path_planning_report message
 *
 * @return  PathPlanning control mode
 */
static inline uint8_t alink_msg_movidus_path_planning_report_get_mode(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  54);
}

/**
 * @brief Get field pos from movidus_path_planning_report message
 *
 * @return  xyz position estimated in 10E-3 meter
 */
static inline uint16_t alink_msg_movidus_path_planning_report_get_pos(const alink_message_head_t* msg, int32_t *pos)
{
	return _MAV_RETURN_int32_t_array(msg, pos, 3,  8);
}

/**
 * @brief Get field vel from movidus_path_planning_report message
 *
 * @return  velocity estimated in 10E-3 m/s
 */
static inline uint16_t alink_msg_movidus_path_planning_report_get_vel(const alink_message_head_t* msg, int16_t *vel)
{
	return _MAV_RETURN_int16_t_array(msg, vel, 3,  32);
}

/**
 * @brief Get field aac from movidus_path_planning_report message
 *
 * @return  acceleration x/y/z in 10E-3 m^2/s
 */
static inline uint16_t alink_msg_movidus_path_planning_report_get_aac(const alink_message_head_t* msg, int16_t *aac)
{
	return _MAV_RETURN_int16_t_array(msg, aac, 3,  38);
}

/**
 * @brief Get field jerk from movidus_path_planning_report message
 *
 * @return  jerk x/y/z in 10E-3 m^3/s
 */
static inline uint16_t alink_msg_movidus_path_planning_report_get_jerk(const alink_message_head_t* msg, int16_t *jerk)
{
	return _MAV_RETURN_int16_t_array(msg, jerk, 3,  44);
}

/**
 * @brief Get field yaw from movidus_path_planning_report message
 *
 * @return  Yaw angle in 10E-3 deg
 */
static inline int16_t alink_msg_movidus_path_planning_report_get_yaw(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  50);
}

/**
 * @brief Get field yaw_speed from movidus_path_planning_report message
 *
 * @return  Yaw angle speed in 10E-3 degrees / second
 */
static inline int16_t alink_msg_movidus_path_planning_report_get_yaw_speed(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  52);
}

/**
 * @brief Get field rev from movidus_path_planning_report message
 *
 * @return  rev field
 */
static inline uint16_t alink_msg_movidus_path_planning_report_get_rev(const alink_message_head_t* msg, int32_t *rev)
{
	return _MAV_RETURN_int32_t_array(msg, rev, 3,  20);
}

/**
 * @brief Decode a movidus_path_planning_report message into a struct
 *
 * @param msg The message to decode
 * @param movidus_path_planning_report C-struct to decode the message contents into
 */
static inline void alink_msg_movidus_path_planning_report_decode(const alink_message_head_t* msg, alink_movidus_path_planning_report_t* movidus_path_planning_report)
{
#if ALINK_NEED_BYTE_SWAP
	movidus_path_planning_report->timestamp = alink_msg_movidus_path_planning_report_get_timestamp(msg);
	alink_msg_movidus_path_planning_report_get_pos(msg, movidus_path_planning_report->pos);
	alink_msg_movidus_path_planning_report_get_rev(msg, movidus_path_planning_report->rev);
	alink_msg_movidus_path_planning_report_get_vel(msg, movidus_path_planning_report->vel);
	alink_msg_movidus_path_planning_report_get_aac(msg, movidus_path_planning_report->aac);
	alink_msg_movidus_path_planning_report_get_jerk(msg, movidus_path_planning_report->jerk);
	movidus_path_planning_report->yaw = alink_msg_movidus_path_planning_report_get_yaw(msg);
	movidus_path_planning_report->yaw_speed = alink_msg_movidus_path_planning_report_get_yaw_speed(msg);
	movidus_path_planning_report->mode = alink_msg_movidus_path_planning_report_get_mode(msg);
#else
	memcpy(movidus_path_planning_report, _MAV_PAYLOAD(msg), ALINK_MSG_ID_MOVIDUS_PATH_PLANNING_REPORT_LEN);
#endif
}
