// MESSAGE RAW_BATTERY PACKING

#define ALINK_MSG_ID_RAW_BATTERY 25

typedef struct __alink_raw_battery_t
{
 uint64_t timestamp; /*< timestamp (microseconds since UNIX epoch or microseconds since system boot)*/
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
 uint16_t vol_cell[16]; /*<  cell voltage in mV*/
 uint16_t reserve; /*<  reserve*/
 int16_t sop; /*< status of power: determines maximum power to use*/
 uint8_t rsoc; /*< percent capacity for battery (%)*/
 uint8_t cell_num; /*< cell number*/
} alink_raw_battery_t;

#define ALINK_MSG_ID_RAW_BATTERY_LEN 74
#define ALINK_MSG_ID_25_LEN 74

#define ALINK_MSG_ID_RAW_BATTERY_CRC 252
#define ALINK_MSG_ID_25_CRC 252

#define ALINK_MSG_RAW_BATTERY_FIELD_VOL_CELL_LEN 16

#define ALINK_MESSAGE_INFO_RAW_BATTERY { \
	"RAW_BATTERY", \
	16, \
	{  { "timestamp", NULL, ALINK_TYPE_UINT64_T, 0, 0, offsetof(alink_raw_battery_t, timestamp) }, \
         { "bat_status", NULL, ALINK_TYPE_UINT32_T, 0, 8, offsetof(alink_raw_battery_t, bat_status) }, \
         { "safe_status", NULL, ALINK_TYPE_UINT32_T, 0, 12, offsetof(alink_raw_battery_t, safe_status) }, \
         { "voltage", NULL, ALINK_TYPE_UINT32_T, 0, 16, offsetof(alink_raw_battery_t, voltage) }, \
         { "current", NULL, ALINK_TYPE_INT32_T, 0, 20, offsetof(alink_raw_battery_t, current) }, \
         { "remain_cap", NULL, ALINK_TYPE_UINT16_T, 0, 24, offsetof(alink_raw_battery_t, remain_cap) }, \
         { "full_cap", NULL, ALINK_TYPE_UINT16_T, 0, 26, offsetof(alink_raw_battery_t, full_cap) }, \
         { "design_cap", NULL, ALINK_TYPE_UINT16_T, 0, 28, offsetof(alink_raw_battery_t, design_cap) }, \
         { "temperature", NULL, ALINK_TYPE_INT16_T, 0, 30, offsetof(alink_raw_battery_t, temperature) }, \
         { "cycle_cnt", NULL, ALINK_TYPE_UINT16_T, 0, 32, offsetof(alink_raw_battery_t, cycle_cnt) }, \
         { "rtte", NULL, ALINK_TYPE_UINT16_T, 0, 34, offsetof(alink_raw_battery_t, rtte) }, \
         { "vol_cell", NULL, ALINK_TYPE_UINT16_T, 16, 36, offsetof(alink_raw_battery_t, vol_cell) }, \
         { "reserve", NULL, ALINK_TYPE_UINT16_T, 0, 68, offsetof(alink_raw_battery_t, reserve) }, \
         { "sop", NULL, ALINK_TYPE_INT16_T, 0, 70, offsetof(alink_raw_battery_t, sop) }, \
         { "rsoc", NULL, ALINK_TYPE_UINT8_T, 0, 72, offsetof(alink_raw_battery_t, rsoc) }, \
         { "cell_num", NULL, ALINK_TYPE_UINT8_T, 0, 73, offsetof(alink_raw_battery_t, cell_num) }, \
         } \
}


/**
 * @brief Pack a raw_battery message
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 *
 * @param timestamp timestamp (microseconds since UNIX epoch or microseconds since system boot)
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
 * @param vol_cell  cell voltage in mV
 * @param reserve  reserve
 * @param sop status of power: determines maximum power to use
 * @param rsoc percent capacity for battery (%)
 * @param cell_num cell number
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_raw_battery_pack(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg,
						       uint64_t timestamp, uint32_t bat_status, uint32_t safe_status, uint32_t voltage, int32_t current, uint16_t remain_cap, uint16_t full_cap, uint16_t design_cap, int16_t temperature, uint16_t cycle_cnt, uint16_t rtte, const uint16_t *vol_cell, uint16_t reserve, int16_t sop, uint8_t rsoc, uint8_t cell_num)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_RAW_BATTERY_LEN];
	_mav_put_uint64_t(buf, 0, timestamp);
	_mav_put_uint32_t(buf, 8, bat_status);
	_mav_put_uint32_t(buf, 12, safe_status);
	_mav_put_uint32_t(buf, 16, voltage);
	_mav_put_int32_t(buf, 20, current);
	_mav_put_uint16_t(buf, 24, remain_cap);
	_mav_put_uint16_t(buf, 26, full_cap);
	_mav_put_uint16_t(buf, 28, design_cap);
	_mav_put_int16_t(buf, 30, temperature);
	_mav_put_uint16_t(buf, 32, cycle_cnt);
	_mav_put_uint16_t(buf, 34, rtte);
	_mav_put_uint16_t(buf, 68, reserve);
	_mav_put_int16_t(buf, 70, sop);
	_mav_put_uint8_t(buf, 72, rsoc);
	_mav_put_uint8_t(buf, 73, cell_num);
	_mav_put_uint16_t_array(buf, 36, vol_cell, 16);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_RAW_BATTERY_LEN);
#else
	alink_raw_battery_t packet;
	packet.timestamp = timestamp;
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
	packet.reserve = reserve;
	packet.sop = sop;
	packet.rsoc = rsoc;
	packet.cell_num = cell_num;
	mav_array_memcpy(packet.vol_cell, vol_cell, sizeof(uint16_t)*16);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_RAW_BATTERY_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_RAW_BATTERY;
#if ALINK_CRC_EXTRA
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_RAW_BATTERY_LEN,ALINK_MSG_ID_RAW_BATTERY_CRC);
#else
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_RAW_BATTERY_LEN);
#endif
}

/**
 * @brief Pack a raw_battery message on a channel
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param timestamp timestamp (microseconds since UNIX epoch or microseconds since system boot)
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
 * @param vol_cell  cell voltage in mV
 * @param reserve  reserve
 * @param sop status of power: determines maximum power to use
 * @param rsoc percent capacity for battery (%)
 * @param cell_num cell number
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_raw_battery_pack_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan,
							   alink_message_head_t* msg,
						           uint64_t timestamp,uint32_t bat_status,uint32_t safe_status,uint32_t voltage,int32_t current,uint16_t remain_cap,uint16_t full_cap,uint16_t design_cap,int16_t temperature,uint16_t cycle_cnt,uint16_t rtte,const uint16_t *vol_cell,uint16_t reserve,int16_t sop,uint8_t rsoc,uint8_t cell_num)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_RAW_BATTERY_LEN];
	_mav_put_uint64_t(buf, 0, timestamp);
	_mav_put_uint32_t(buf, 8, bat_status);
	_mav_put_uint32_t(buf, 12, safe_status);
	_mav_put_uint32_t(buf, 16, voltage);
	_mav_put_int32_t(buf, 20, current);
	_mav_put_uint16_t(buf, 24, remain_cap);
	_mav_put_uint16_t(buf, 26, full_cap);
	_mav_put_uint16_t(buf, 28, design_cap);
	_mav_put_int16_t(buf, 30, temperature);
	_mav_put_uint16_t(buf, 32, cycle_cnt);
	_mav_put_uint16_t(buf, 34, rtte);
	_mav_put_uint16_t(buf, 68, reserve);
	_mav_put_int16_t(buf, 70, sop);
	_mav_put_uint8_t(buf, 72, rsoc);
	_mav_put_uint8_t(buf, 73, cell_num);
	_mav_put_uint16_t_array(buf, 36, vol_cell, 16);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_RAW_BATTERY_LEN);
#else
	alink_raw_battery_t packet;
	packet.timestamp = timestamp;
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
	packet.reserve = reserve;
	packet.sop = sop;
	packet.rsoc = rsoc;
	packet.cell_num = cell_num;
	mav_array_memcpy(packet.vol_cell, vol_cell, sizeof(uint16_t)*16);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_RAW_BATTERY_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_RAW_BATTERY;
#if ALINK_CRC_EXTRA
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_RAW_BATTERY_LEN,ALINK_MSG_ID_RAW_BATTERY_CRC);
#else
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_RAW_BATTERY_LEN);
#endif
}
/**
 * @brief Encode a raw_battery struct
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 * @param raw_battery C-struct to read the message contents from
 */
static inline uint16_t alink_msg_raw_battery_encode(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg, const alink_raw_battery_t* raw_battery)
{
	return alink_msg_raw_battery_pack(dest_id, source_id, msg, raw_battery->timestamp, raw_battery->bat_status, raw_battery->safe_status, raw_battery->voltage, raw_battery->current, raw_battery->remain_cap, raw_battery->full_cap, raw_battery->design_cap, raw_battery->temperature, raw_battery->cycle_cnt, raw_battery->rtte, raw_battery->vol_cell, raw_battery->reserve, raw_battery->sop, raw_battery->rsoc, raw_battery->cell_num);
}

/**
 * @brief Encode a raw_battery struct on a channel
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param raw_battery C-struct to read the message contents from
 */
static inline uint16_t alink_msg_raw_battery_encode_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan, alink_message_head_t* msg, const alink_raw_battery_t* raw_battery)
{
	return alink_msg_raw_battery_pack_chan(dest_id, source_id, chan, msg, raw_battery->timestamp, raw_battery->bat_status, raw_battery->safe_status, raw_battery->voltage, raw_battery->current, raw_battery->remain_cap, raw_battery->full_cap, raw_battery->design_cap, raw_battery->temperature, raw_battery->cycle_cnt, raw_battery->rtte, raw_battery->vol_cell, raw_battery->reserve, raw_battery->sop, raw_battery->rsoc, raw_battery->cell_num);
}
// MESSAGE RAW_BATTERY UNPACKING


/**
 * @brief Get field timestamp from raw_battery message
 *
 * @return timestamp (microseconds since UNIX epoch or microseconds since system boot)
 */
static inline uint64_t alink_msg_raw_battery_get_timestamp(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field bat_status from raw_battery message
 *
 * @return bat status (%)
 */
static inline uint32_t alink_msg_raw_battery_get_bat_status(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint32_t(msg,  8);
}

/**
 * @brief Get field safe_status from raw_battery message
 *
 * @return safety status (%)
 */
static inline uint32_t alink_msg_raw_battery_get_safe_status(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint32_t(msg,  12);
}

/**
 * @brief Get field voltage from raw_battery message
 *
 * @return total battery voltage in mV, support maximum > 65536mV
 */
static inline uint32_t alink_msg_raw_battery_get_voltage(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint32_t(msg,  16);
}

/**
 * @brief Get field current from raw_battery message
 *
 * @return current for battery in mA, support maximum > 65536mA
 */
static inline int32_t alink_msg_raw_battery_get_current(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  20);
}

/**
 * @brief Get field remain_cap from raw_battery message
 *
 * @return capacity for battery in mAh
 */
static inline uint16_t alink_msg_raw_battery_get_remain_cap(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  24);
}

/**
 * @brief Get field full_cap from raw_battery message
 *
 * @return full charge capacity for battery in mAh
 */
static inline uint16_t alink_msg_raw_battery_get_full_cap(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  26);
}

/**
 * @brief Get field design_cap from raw_battery message
 *
 * @return design capacity for battery in mAh
 */
static inline uint16_t alink_msg_raw_battery_get_design_cap(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  28);
}

/**
 * @brief Get field temperature from raw_battery message
 *
 * @return temperature for battery (0.1 degree centigrade)
 */
static inline int16_t alink_msg_raw_battery_get_temperature(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  30);
}

/**
 * @brief Get field cycle_cnt from raw_battery message
 *
 * @return cycle count
 */
static inline uint16_t alink_msg_raw_battery_get_cycle_cnt(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  32);
}

/**
 * @brief Get field rtte from raw_battery message
 *
 * @return remain time to empty in seconds
 */
static inline uint16_t alink_msg_raw_battery_get_rtte(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  34);
}

/**
 * @brief Get field vol_cell from raw_battery message
 *
 * @return  cell voltage in mV
 */
static inline uint16_t alink_msg_raw_battery_get_vol_cell(const alink_message_head_t* msg, uint16_t *vol_cell)
{
	return _MAV_RETURN_uint16_t_array(msg, vol_cell, 16,  36);
}

/**
 * @brief Get field reserve from raw_battery message
 *
 * @return  reserve
 */
static inline uint16_t alink_msg_raw_battery_get_reserve(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint16_t(msg,  68);
}

/**
 * @brief Get field sop from raw_battery message
 *
 * @return status of power: determines maximum power to use
 */
static inline int16_t alink_msg_raw_battery_get_sop(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  70);
}

/**
 * @brief Get field rsoc from raw_battery message
 *
 * @return percent capacity for battery (%)
 */
static inline uint8_t alink_msg_raw_battery_get_rsoc(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  72);
}

/**
 * @brief Get field cell_num from raw_battery message
 *
 * @return cell number
 */
static inline uint8_t alink_msg_raw_battery_get_cell_num(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  73);
}

/**
 * @brief Decode a raw_battery message into a struct
 *
 * @param msg The message to decode
 * @param raw_battery C-struct to decode the message contents into
 */
static inline void alink_msg_raw_battery_decode(const alink_message_head_t* msg, alink_raw_battery_t* raw_battery)
{
#if ALINK_NEED_BYTE_SWAP
	raw_battery->timestamp = alink_msg_raw_battery_get_timestamp(msg);
	raw_battery->bat_status = alink_msg_raw_battery_get_bat_status(msg);
	raw_battery->safe_status = alink_msg_raw_battery_get_safe_status(msg);
	raw_battery->voltage = alink_msg_raw_battery_get_voltage(msg);
	raw_battery->current = alink_msg_raw_battery_get_current(msg);
	raw_battery->remain_cap = alink_msg_raw_battery_get_remain_cap(msg);
	raw_battery->full_cap = alink_msg_raw_battery_get_full_cap(msg);
	raw_battery->design_cap = alink_msg_raw_battery_get_design_cap(msg);
	raw_battery->temperature = alink_msg_raw_battery_get_temperature(msg);
	raw_battery->cycle_cnt = alink_msg_raw_battery_get_cycle_cnt(msg);
	raw_battery->rtte = alink_msg_raw_battery_get_rtte(msg);
	alink_msg_raw_battery_get_vol_cell(msg, raw_battery->vol_cell);
	raw_battery->reserve = alink_msg_raw_battery_get_reserve(msg);
	raw_battery->sop = alink_msg_raw_battery_get_sop(msg);
	raw_battery->rsoc = alink_msg_raw_battery_get_rsoc(msg);
	raw_battery->cell_num = alink_msg_raw_battery_get_cell_num(msg);
#else
	memcpy(raw_battery, _MAV_PAYLOAD(msg), ALINK_MSG_ID_RAW_BATTERY_LEN);
#endif
}
