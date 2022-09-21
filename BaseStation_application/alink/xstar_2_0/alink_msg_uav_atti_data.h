// MESSAGE UAV_ATTI_DATA PACKING

#define ALINK_MSG_ID_UAV_ATTI_DATA 48

typedef struct __alink_uav_atti_data_t
{
 float q0; /*< Quarternion q0*/
 float q1; /*< Quarternion q1*/
 float q2; /*< Quarternion q2*/
 float q3; /*< Quarternion q3*/
 uint32_t fcs_state; /*< FCS state bit-defined, bit0: OnGround, Bit1~Bit31: future use)*/
 int16_t acc[3]; /*< acceleration x/y/z in 10E2 m^2/s*/
 int16_t gyr[3]; /*< gyroscope x/y/z in 10E3 rad/s*/
 uint8_t ins_valid_flg; /*< valid flags for navigation Info*/
} alink_uav_atti_data_t;

#define ALINK_MSG_ID_UAV_ATTI_DATA_LEN 33
#define ALINK_MSG_ID_48_LEN 33

#define ALINK_MSG_ID_UAV_ATTI_DATA_CRC 8
#define ALINK_MSG_ID_48_CRC 8

#define ALINK_MSG_UAV_ATTI_DATA_FIELD_ACC_LEN 3
#define ALINK_MSG_UAV_ATTI_DATA_FIELD_GYR_LEN 3

#define ALINK_MESSAGE_INFO_UAV_ATTI_DATA { \
	"UAV_ATTI_DATA", \
	8, \
	{  { "q0", NULL, ALINK_TYPE_FLOAT, 0, 0, offsetof(alink_uav_atti_data_t, q0) }, \
         { "q1", NULL, ALINK_TYPE_FLOAT, 0, 4, offsetof(alink_uav_atti_data_t, q1) }, \
         { "q2", NULL, ALINK_TYPE_FLOAT, 0, 8, offsetof(alink_uav_atti_data_t, q2) }, \
         { "q3", NULL, ALINK_TYPE_FLOAT, 0, 12, offsetof(alink_uav_atti_data_t, q3) }, \
         { "fcs_state", NULL, ALINK_TYPE_UINT32_T, 0, 16, offsetof(alink_uav_atti_data_t, fcs_state) }, \
         { "acc", NULL, ALINK_TYPE_INT16_T, 3, 20, offsetof(alink_uav_atti_data_t, acc) }, \
         { "gyr", NULL, ALINK_TYPE_INT16_T, 3, 26, offsetof(alink_uav_atti_data_t, gyr) }, \
         { "ins_valid_flg", NULL, ALINK_TYPE_UINT8_T, 0, 32, offsetof(alink_uav_atti_data_t, ins_valid_flg) }, \
         } \
}


/**
 * @brief Pack a uav_atti_data message
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 *
 * @param ins_valid_flg valid flags for navigation Info
 * @param q0 Quarternion q0
 * @param q1 Quarternion q1
 * @param q2 Quarternion q2
 * @param q3 Quarternion q3
 * @param fcs_state FCS state bit-defined, bit0: OnGround, Bit1~Bit31: future use)
 * @param acc acceleration x/y/z in 10E2 m^2/s
 * @param gyr gyroscope x/y/z in 10E3 rad/s
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_uav_atti_data_pack(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg,
						       uint8_t ins_valid_flg, float q0, float q1, float q2, float q3, uint32_t fcs_state, const int16_t *acc, const int16_t *gyr)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_UAV_ATTI_DATA_LEN];
	_mav_put_float(buf, 0, q0);
	_mav_put_float(buf, 4, q1);
	_mav_put_float(buf, 8, q2);
	_mav_put_float(buf, 12, q3);
	_mav_put_uint32_t(buf, 16, fcs_state);
	_mav_put_uint8_t(buf, 32, ins_valid_flg);
	_mav_put_int16_t_array(buf, 20, acc, 3);
	_mav_put_int16_t_array(buf, 26, gyr, 3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_UAV_ATTI_DATA_LEN);
#else
	alink_uav_atti_data_t packet;
	packet.q0 = q0;
	packet.q1 = q1;
	packet.q2 = q2;
	packet.q3 = q3;
	packet.fcs_state = fcs_state;
	packet.ins_valid_flg = ins_valid_flg;
	mav_array_memcpy(packet.acc, acc, sizeof(int16_t)*3);
	mav_array_memcpy(packet.gyr, gyr, sizeof(int16_t)*3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_UAV_ATTI_DATA_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_UAV_ATTI_DATA;
#if ALINK_CRC_EXTRA
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_UAV_ATTI_DATA_LEN,ALINK_MSG_ID_UAV_ATTI_DATA_CRC);
#else
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_UAV_ATTI_DATA_LEN);
#endif
}

/**
 * @brief Pack a uav_atti_data message on a channel
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param ins_valid_flg valid flags for navigation Info
 * @param q0 Quarternion q0
 * @param q1 Quarternion q1
 * @param q2 Quarternion q2
 * @param q3 Quarternion q3
 * @param fcs_state FCS state bit-defined, bit0: OnGround, Bit1~Bit31: future use)
 * @param acc acceleration x/y/z in 10E2 m^2/s
 * @param gyr gyroscope x/y/z in 10E3 rad/s
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_uav_atti_data_pack_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan,
							   alink_message_head_t* msg,
						           uint8_t ins_valid_flg,float q0,float q1,float q2,float q3,uint32_t fcs_state,const int16_t *acc,const int16_t *gyr)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_UAV_ATTI_DATA_LEN];
	_mav_put_float(buf, 0, q0);
	_mav_put_float(buf, 4, q1);
	_mav_put_float(buf, 8, q2);
	_mav_put_float(buf, 12, q3);
	_mav_put_uint32_t(buf, 16, fcs_state);
	_mav_put_uint8_t(buf, 32, ins_valid_flg);
	_mav_put_int16_t_array(buf, 20, acc, 3);
	_mav_put_int16_t_array(buf, 26, gyr, 3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_UAV_ATTI_DATA_LEN);
#else
	alink_uav_atti_data_t packet;
	packet.q0 = q0;
	packet.q1 = q1;
	packet.q2 = q2;
	packet.q3 = q3;
	packet.fcs_state = fcs_state;
	packet.ins_valid_flg = ins_valid_flg;
	mav_array_memcpy(packet.acc, acc, sizeof(int16_t)*3);
	mav_array_memcpy(packet.gyr, gyr, sizeof(int16_t)*3);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_UAV_ATTI_DATA_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_UAV_ATTI_DATA;
#if ALINK_CRC_EXTRA
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_UAV_ATTI_DATA_LEN,ALINK_MSG_ID_UAV_ATTI_DATA_CRC);
#else
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_UAV_ATTI_DATA_LEN);
#endif
}
/**
 * @brief Encode a uav_atti_data struct
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 * @param uav_atti_data C-struct to read the message contents from
 */
static inline uint16_t alink_msg_uav_atti_data_encode(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg, const alink_uav_atti_data_t* uav_atti_data)
{
	return alink_msg_uav_atti_data_pack(dest_id, source_id, msg, uav_atti_data->ins_valid_flg, uav_atti_data->q0, uav_atti_data->q1, uav_atti_data->q2, uav_atti_data->q3, uav_atti_data->fcs_state, uav_atti_data->acc, uav_atti_data->gyr);
}

/**
 * @brief Encode a uav_atti_data struct on a channel
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param uav_atti_data C-struct to read the message contents from
 */
static inline uint16_t alink_msg_uav_atti_data_encode_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan, alink_message_head_t* msg, const alink_uav_atti_data_t* uav_atti_data)
{
	return alink_msg_uav_atti_data_pack_chan(dest_id, source_id, chan, msg, uav_atti_data->ins_valid_flg, uav_atti_data->q0, uav_atti_data->q1, uav_atti_data->q2, uav_atti_data->q3, uav_atti_data->fcs_state, uav_atti_data->acc, uav_atti_data->gyr);
}
// MESSAGE UAV_ATTI_DATA UNPACKING


/**
 * @brief Get field ins_valid_flg from uav_atti_data message
 *
 * @return valid flags for navigation Info
 */
static inline uint8_t alink_msg_uav_atti_data_get_ins_valid_flg(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  32);
}

/**
 * @brief Get field q0 from uav_atti_data message
 *
 * @return Quarternion q0
 */
static inline float alink_msg_uav_atti_data_get_q0(const alink_message_head_t* msg)
{
	return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field q1 from uav_atti_data message
 *
 * @return Quarternion q1
 */
static inline float alink_msg_uav_atti_data_get_q1(const alink_message_head_t* msg)
{
	return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field q2 from uav_atti_data message
 *
 * @return Quarternion q2
 */
static inline float alink_msg_uav_atti_data_get_q2(const alink_message_head_t* msg)
{
	return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field q3 from uav_atti_data message
 *
 * @return Quarternion q3
 */
static inline float alink_msg_uav_atti_data_get_q3(const alink_message_head_t* msg)
{
	return _MAV_RETURN_float(msg,  12);
}

/**
 * @brief Get field fcs_state from uav_atti_data message
 *
 * @return FCS state bit-defined, bit0: OnGround, Bit1~Bit31: future use)
 */
static inline uint32_t alink_msg_uav_atti_data_get_fcs_state(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint32_t(msg,  16);
}

/**
 * @brief Get field acc from uav_atti_data message
 *
 * @return acceleration x/y/z in 10E2 m^2/s
 */
static inline uint16_t alink_msg_uav_atti_data_get_acc(const alink_message_head_t* msg, int16_t *acc)
{
	return _MAV_RETURN_int16_t_array(msg, acc, 3,  20);
}

/**
 * @brief Get field gyr from uav_atti_data message
 *
 * @return gyroscope x/y/z in 10E3 rad/s
 */
static inline uint16_t alink_msg_uav_atti_data_get_gyr(const alink_message_head_t* msg, int16_t *gyr)
{
	return _MAV_RETURN_int16_t_array(msg, gyr, 3,  26);
}

/**
 * @brief Decode a uav_atti_data message into a struct
 *
 * @param msg The message to decode
 * @param uav_atti_data C-struct to decode the message contents into
 */
static inline void alink_msg_uav_atti_data_decode(const alink_message_head_t* msg, alink_uav_atti_data_t* uav_atti_data)
{
#if ALINK_NEED_BYTE_SWAP
	uav_atti_data->q0 = alink_msg_uav_atti_data_get_q0(msg);
	uav_atti_data->q1 = alink_msg_uav_atti_data_get_q1(msg);
	uav_atti_data->q2 = alink_msg_uav_atti_data_get_q2(msg);
	uav_atti_data->q3 = alink_msg_uav_atti_data_get_q3(msg);
	uav_atti_data->fcs_state = alink_msg_uav_atti_data_get_fcs_state(msg);
	alink_msg_uav_atti_data_get_acc(msg, uav_atti_data->acc);
	alink_msg_uav_atti_data_get_gyr(msg, uav_atti_data->gyr);
	uav_atti_data->ins_valid_flg = alink_msg_uav_atti_data_get_ins_valid_flg(msg);
#else
	memcpy(uav_atti_data, _MAV_PAYLOAD(msg), ALINK_MSG_ID_UAV_ATTI_DATA_LEN);
#endif
}
