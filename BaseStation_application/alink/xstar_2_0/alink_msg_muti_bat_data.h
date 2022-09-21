// MESSAGE MUTI_BAT_DATA PACKING

#define ALINK_MSG_ID_MUTI_BAT_DATA 64

typedef struct __alink_muti_bat_data_t
{
 uint32_t bat_status; /*< bat status (%)*/
 uint32_t safe_status; /*< safety status (%)*/
 uint32_t voltage; /*< total battery voltage in mV, support maximum > 65536mV*/
 int32_t current; /*< current for battery in mA, support maximum > 65536mA*/
 uint16_t remain_cap; /*< capacity for battery in mAh*/
 uint16_t full_cap; /*< full charge capacity for battery in mAh*/
 uint16_t design_cap; /*< design capacity for battery in mAh*/
 int16_t temperature; /*< temperature for battery (0.1 degree centigrade)*/
 uint16_t cycle_cnt; /*< cycle count*/
 uint16_t rtte; /*< remain time to empty in seconds*/
 int16_t sop; /*< status of power: determines maximum power to use*/
 uint8_t rsoc; /*< percent capacity for battery (%)*/
 uint8_t cell_num; /*< cell number*/
} alink_muti_bat_data_t;

#define ALINK_MSG_ID_MUTI_BAT_DATA_LEN 32
#define ALINK_MSG_ID_64_LEN 32

#define ALINK_MSG_ID_MUTI_BAT_DATA_CRC 141
#define ALINK_MSG_ID_64_CRC 141



#define ALINK_MESSAGE_INFO_MUTI_BAT_DATA { \
	"MUTI_BAT_DATA", \
	13, \
	{  { "bat_status", NULL, ALINK_TYPE_UINT32_T, 0, 0, offsetof(alink_muti_bat_data_t, bat_status) }, \
         { "safe_status", NULL, ALINK_TYPE_UINT32_T, 0, 4, offsetof(alink_muti_bat_data_t, safe_status) }, \
         { "voltage", NULL, ALINK_TYPE_UINT32_T, 0, 8, offsetof(alink_muti_bat_data_t, voltage) }, \
         { "current", NULL, ALINK_TYPE_INT32_T, 0, 12, offsetof(alink_muti_bat_data_t, current) }, \
         { "remain_cap", NULL, ALINK_TYPE_UINT16_T, 0, 16, offsetof(alink_muti_bat_data_t, remain_cap) }, \
         { "full_cap", NULL, ALINK_TYPE_UINT16_T, 0, 18, offsetof(alink_muti_bat_data_t, full_cap) }, \
         { "design_cap", NULL, ALINK_TYPE_UINT16_T, 0, 20, offsetof(alink_muti_bat_data_t, design_cap) }, \
         { "temperature", NULL, ALINK_TYPE_INT16_T, 0, 22, offsetof(alink_muti_bat_data_t, temperature) }, \
         { "cycle_cnt", NULL, ALINK_TYPE_UINT16_T, 0, 24, offsetof(alink_muti_bat_data_t, cycle_cnt) }, \
         { "rtte", NULL, ALINK_TYPE_UINT16_T, 0, 26, offsetof(alink_muti_bat_data_t, rtte) }, \
         { "sop", NULL, ALINK_TYPE_INT16_T, 0, 28, offsetof(alink_muti_bat_data_t, sop) }, \
         { "rsoc", NULL, ALINK_TYPE_UINT8_T, 0, 30, offsetof(alink_muti_bat_data_t, rsoc) }, \
         { "cell_num", NULL, ALINK_TYPE_UINT8_T, 0, 31, offsetof(alink_muti_bat_data_t, cell_num) }, \
         } \
}


/**
 * @brief Pack a muti_bat_data message
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 *
 * @param bat_status bat status (%)
 * @param safe_status safety status (%)
 * @param voltage total battery voltage in mV, support maximum > 65536mV
 * @param current current for battery in mA, support maximum > 65536mA
 * @param remain_cap capacity for battery in mAh
 * @param full_cap full charge capacity for battery in mAh
 * @param design_cap design capacity for battery in mAh
 * @param temperature temperature for battery (0.1 degree centigrade)
 * @param cycle_cnt cycle count
 * @param rtte remain time to empty in seconds
 * @param sop status of power: determines maximum power to use
 * @param rsoc percent capacity for battery (%)
 * @param cell_num cell number
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_muti_bat_data_pack(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg,
						       uint32_t bat_status, uint32_t safe_status, uint32_t voltage, int32_t current, uint16_t remain_cap, uint16_t full_cap, uint16_t design_cap, int16_t temperature, uint16_t cycle_cnt, uint16_t rtte, int16_t sop, uint8_t rsoc, uint8_t cell_num)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_MUTI_BAT_DATA_LEN];
	_mav_put_uint32_t(buf, 0, bat_status);
	_mav_put_uint32_t(buf, 4, safe_status);
	_mav_put_uint32_t(buf, 8, voltage);
	_mav_put_int32_t(buf, 12, current);
	_mav_put_uint16_t(buf, 16, remain_cap);
	_mav_put_uint16_t(buf, 18, full_cap);
	_mav_put_uint16_t(buf, 20, design_cap);
	_mav_put_int16_t(buf, 22, temperature);
	_mav_put_uint16_t(buf, 24, cycle_cnt);
	_mav_put_uint16_t(buf, 26, rtte);
	_mav_put_int16_t(buf, 28, sop);
	_mav_put_uint8_t(buf, 30, rsoc);
	_mav_put_uint8_t(buf, 31, cell_num);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_MUTI_BAT_DATA_LEN);
#else
	alink_muti_bat_data_t packet;
	packet.bat_status = bat_status;
	packet.safe_status = safe_status;
	packet.voltage = voltage;
	packet.current = current;
	packet.remain_cap = remain_cap;
	packet.full_cap = full_cap;
	packet.design_cap = design_cap;
	packet.temperature = temperature;
	packet.cycle_cnt = cycle_cnt;
	packet.rtte = rtte;
	packet.sop = sop;
	packet.rsoc = rsoc;
	packet.cell_num = cell_num;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_MUTI_BAT_DATA_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_MUTI_BAT_DATA;
#if ALINK_CRC_EXTRA
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_MUTI_BAT_DATA_LEN,ALINK_MSG_ID_MUTI_BAT_DATA_CRC);
#else
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_MUTI_BAT_DATA_LEN);
#endif
}

/**
 * @brief Pack a muti_bat_data message on a channel
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param bat_status bat status (%)
 * @param safe_status safety status (%)
 * @param voltage total battery voltage in mV, support maximum > 65536mV
 * @param current current for battery in mA, support maximum > 65536mA
 * @param remain_cap capacity for battery in mAh
 * @param full_cap full charge capacity for battery in mAh
 * @param design_cap design capacity for battery in mAh
 * @param temperature temperature for battery (0.1 degree centigrade)
 * @param cycle_cnt cycle count
 * @param rtte remain time to empty in seconds
 * @param sop status of power: determines maximum power to use
 * @param rsoc percent capacity for battery (%)
 * @param cell_num cell number
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_muti_bat_data_pack_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan,
							   alink_message_head_t* msg,
						           uint32_t bat_status,uint32_t safe_status,uint32_t voltage,int32_t current,uint16_t remain_cap,uint16_t full_cap,uint16_t design_cap,int16_t temperature,uint16_t cycle_cnt,uint16_t rtte,int16_t sop,uint8_t rsoc,uint8_t cell_num)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_MUTI_BAT_DATA_LEN];
	_mav_put_uint32_t(buf, 0, bat_status);
	_mav_put_uint32_t(buf, 4, safe_status);
	_mav_put_uint32_t(buf, 8, voltage);
	_mav_put_int32_t(buf, 12, current);
	_mav_put_uint16_t(buf, 16, remain_cap);
	_mav_put_uint16_t(buf, 18, full_cap);
	_mav_put_uint16_t(buf, 20, design_cap);
	_mav_put_int16_t(buf, 22, temperature);
	_mav_put_uint16_t(buf, 24, cycle_cnt);
	_mav_put_uint16_t(buf, 26, rtte);
	_mav_put_int16_t(buf, 28, sop);
	_mav_put_uint8_t(buf, 30, rsoc);
	_mav_put_uint8_t(buf, 31, cell_num);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_MUTI_BAT_DATA_LEN);
#else
	alink_muti_bat_data_t packet;
	packet.bat_status = bat_status;
	packet.safe_status = safe_status;
	packet.voltage = voltage;
	packet.current = current;
	packet.remain_cap = remain_cap;
	packet.full_cap = full_cap;
	packet.design_cap = design_cap;
	packet.temperature = temperature;
	packet.cycle_cnt = cycle_cnt;
	packet.rtte = rtte;
	packet.sop = sop;
	packet.rsoc = rsoc;
	packet.cell_num = cell_num;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_MUTI_BAT_DATA_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_MUTI_BAT_DATA;
#if ALINK_CRC_EXTRA
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_MUTI_BAT_DATA_LEN,ALINK_MSG_ID_MUTI_BAT_DATA_CRC);
#else
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_MUTI_BAT_DATA_LEN);
#endif
}
/**
 * @brief Encode a muti_bat_data struct
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 * @param muti_bat_data C-struct to read the message contents from
 */
static inline uint16_t alink_msg_muti_bat_data_encode(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg, const alink_muti_bat_data_t* muti_bat_data)
{
	return alink_msg_muti_bat_data_pack(dest_id, source_id, msg, muti_bat_data->bat_status, muti_bat_data->safe_status, muti_bat_data->voltage, muti_bat_data->current, muti_bat_data->remain_cap, muti_bat_data->full_cap, muti_bat_data->design_cap, muti_bat_data->temperature, muti_bat_data->cycle_cnt, muti_bat_data->rtte, muti_bat_data->sop, muti_bat_data->rsoc, muti_bat_data->cell_num);
}

/**
 * @brief Encode a muti_bat_data struct on a channel
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param muti_bat_data C-struct to read the message contents from
 */
static inline uint16_t alink_msg_muti_bat_data_encode_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan, alink_message_head_t* msg, const alink_muti_bat_data_t* muti_bat_data)
{
	return alink_msg_muti_bat_data_pack_chan(dest_id, source_id, chan, msg, muti_bat_data->bat_status, muti_bat_data->safe_status, muti_bat_data->voltage, muti_bat_data->current, muti_bat_data->remain_cap, muti_bat_data->full_cap, muti_bat_data->design_cap, muti_bat_data->temperature, muti_bat_data->cycle_cnt, muti_bat_data->rtte, muti_bat_data->sop, muti_bat_data->rsoc, muti_bat_data->cell_num);
}
// MESSAGE MUTI_BAT_DATA UNPACKING


/**
 * @brief Get field bat_status from muti_bat_data message
 *
 * @return bat status (%)
 */
static inline uint32_t alink_msg_muti_bat_data_get_bat_status(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field safe_status from muti_bat_data message
 *
 * @return safety status (%)
 */
static inline uint32_t alink_msg_muti_bat_data_get_safe_status(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint32_t(msg,  4);
}

/**
 * @brief Get field voltage from muti_bat_data message
 *
 * @return total battery voltage in mV, support maximum > 65536mV
 */
static inline uint32_t alink_msg_muti_bat_data_get_voltage(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint32_t(msg,  8);
}

/**
 * @brief Get field current from muti_bat_data message
 *
 * @return current for battery in mA, support maximum > 65536mA
 */
static inline int32_t alink_msg_muti_bat_data_get_current(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  12);
}

/**
 * @brief Get field remain_cap from muti_bat_data message
 *
 * @return capacity for battery in mAh
 */
static inline uint16_t alink_msg_muti_bat_data_get_remain_cap(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  16);
}

/**
 * @brief Get field full_cap from muti_bat_data message
 *
 * @return full charge capacity for battery in mAh
 */
static inline uint16_t alink_msg_muti_bat_data_get_full_cap(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  18);
}

/**
 * @brief Get field design_cap from muti_bat_data message
 *
 * @return design capacity for battery in mAh
 */
static inline uint16_t alink_msg_muti_bat_data_get_design_cap(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  20);
}

/**
 * @brief Get field temperature from muti_bat_data message
 *
 * @return temperature for battery (0.1 degree centigrade)
 */
static inline int16_t alink_msg_muti_bat_data_get_temperature(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  22);
}

/**
 * @brief Get field cycle_cnt from muti_bat_data message
 *
 * @return cycle count
 */
static inline uint16_t alink_msg_muti_bat_data_get_cycle_cnt(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  24);
}

/**
 * @brief Get field rtte from muti_bat_data message
 *
 * @return remain time to empty in seconds
 */
static inline uint16_t alink_msg_muti_bat_data_get_rtte(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  26);
}

/**
 * @brief Get field sop from muti_bat_data message
 *
 * @return status of power: determines maximum power to use
 */
static inline int16_t alink_msg_muti_bat_data_get_sop(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  28);
}

/**
 * @brief Get field rsoc from muti_bat_data message
 *
 * @return percent capacity for battery (%)
 */
static inline uint8_t alink_msg_muti_bat_data_get_rsoc(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  30);
}

/**
 * @brief Get field cell_num from muti_bat_data message
 *
 * @return cell number
 */
static inline uint8_t alink_msg_muti_bat_data_get_cell_num(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  31);
}

/**
 * @brief Decode a muti_bat_data message into a struct
 *
 * @param msg The message to decode
 * @param muti_bat_data C-struct to decode the message contents into
 */
static inline void alink_msg_muti_bat_data_decode(const alink_message_head_t* msg, alink_muti_bat_data_t* muti_bat_data)
{
#if ALINK_NEED_BYTE_SWAP
	muti_bat_data->bat_status = alink_msg_muti_bat_data_get_bat_status(msg);
	muti_bat_data->safe_status = alink_msg_muti_bat_data_get_safe_status(msg);
	muti_bat_data->voltage = alink_msg_muti_bat_data_get_voltage(msg);
	muti_bat_data->current = alink_msg_muti_bat_data_get_current(msg);
	muti_bat_data->remain_cap = alink_msg_muti_bat_data_get_remain_cap(msg);
	muti_bat_data->full_cap = alink_msg_muti_bat_data_get_full_cap(msg);
	muti_bat_data->design_cap = alink_msg_muti_bat_data_get_design_cap(msg);
	muti_bat_data->temperature = alink_msg_muti_bat_data_get_temperature(msg);
	muti_bat_data->cycle_cnt = alink_msg_muti_bat_data_get_cycle_cnt(msg);
	muti_bat_data->rtte = alink_msg_muti_bat_data_get_rtte(msg);
	muti_bat_data->sop = alink_msg_muti_bat_data_get_sop(msg);
	muti_bat_data->rsoc = alink_msg_muti_bat_data_get_rsoc(msg);
	muti_bat_data->cell_num = alink_msg_muti_bat_data_get_cell_num(msg);
#else
	memcpy(muti_bat_data, _MAV_PAYLOAD(msg), ALINK_MSG_ID_MUTI_BAT_DATA_LEN);
#endif
}
