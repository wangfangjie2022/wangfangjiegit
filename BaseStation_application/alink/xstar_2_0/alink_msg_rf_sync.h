// MESSAGE RF_SYNC PACKING

#define ALINK_MSG_ID_RF_SYNC 131

typedef struct __alink_rf_sync_t
{
 uint32_t status1; /*< status1*/
 uint32_t status2; /*< status2*/
 int32_t latitude; /*< latitude, in degrees * 1E7*/
 int32_t longitude; /*< longitude, in degrees * 1E7*/
 uint32_t reserve1; /*< reserve1*/
 uint32_t reserve2; /*< reserve2*/
} alink_rf_sync_t;

#define ALINK_MSG_ID_RF_SYNC_LEN 24
#define ALINK_MSG_ID_131_LEN 24

#define ALINK_MSG_ID_RF_SYNC_CRC 82
#define ALINK_MSG_ID_131_CRC 82



#define ALINK_MESSAGE_INFO_RF_SYNC { \
	"RF_SYNC", \
	6, \
	{  { "status1", NULL, ALINK_TYPE_UINT32_T, 0, 0, offsetof(alink_rf_sync_t, status1) }, \
         { "status2", NULL, ALINK_TYPE_UINT32_T, 0, 4, offsetof(alink_rf_sync_t, status2) }, \
         { "latitude", NULL, ALINK_TYPE_INT32_T, 0, 8, offsetof(alink_rf_sync_t, latitude) }, \
         { "longitude", NULL, ALINK_TYPE_INT32_T, 0, 12, offsetof(alink_rf_sync_t, longitude) }, \
         { "reserve1", NULL, ALINK_TYPE_UINT32_T, 0, 16, offsetof(alink_rf_sync_t, reserve1) }, \
         { "reserve2", NULL, ALINK_TYPE_UINT32_T, 0, 20, offsetof(alink_rf_sync_t, reserve2) }, \
         } \
}


/**
 * @brief Pack a rf_sync message
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 *
 * @param status1 status1
 * @param status2 status2
 * @param latitude latitude, in degrees * 1E7
 * @param longitude longitude, in degrees * 1E7
 * @param reserve1 reserve1
 * @param reserve2 reserve2
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_rf_sync_pack(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg,
						       uint32_t status1, uint32_t status2, int32_t latitude, int32_t longitude, uint32_t reserve1, uint32_t reserve2)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_RF_SYNC_LEN];
	_mav_put_uint32_t(buf, 0, status1);
	_mav_put_uint32_t(buf, 4, status2);
	_mav_put_int32_t(buf, 8, latitude);
	_mav_put_int32_t(buf, 12, longitude);
	_mav_put_uint32_t(buf, 16, reserve1);
	_mav_put_uint32_t(buf, 20, reserve2);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_RF_SYNC_LEN);
#else
	alink_rf_sync_t packet;
	packet.status1 = status1;
	packet.status2 = status2;
	packet.latitude = latitude;
	packet.longitude = longitude;
	packet.reserve1 = reserve1;
	packet.reserve2 = reserve2;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_RF_SYNC_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_RF_SYNC;
#if ALINK_CRC_EXTRA
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_RF_SYNC_LEN,ALINK_MSG_ID_RF_SYNC_CRC);
#else
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_RF_SYNC_LEN);
#endif
}

/**
 * @brief Pack a rf_sync message on a channel
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param status1 status1
 * @param status2 status2
 * @param latitude latitude, in degrees * 1E7
 * @param longitude longitude, in degrees * 1E7
 * @param reserve1 reserve1
 * @param reserve2 reserve2
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_rf_sync_pack_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan,
							   alink_message_head_t* msg,
						           uint32_t status1,uint32_t status2,int32_t latitude,int32_t longitude,uint32_t reserve1,uint32_t reserve2)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_RF_SYNC_LEN];
	_mav_put_uint32_t(buf, 0, status1);
	_mav_put_uint32_t(buf, 4, status2);
	_mav_put_int32_t(buf, 8, latitude);
	_mav_put_int32_t(buf, 12, longitude);
	_mav_put_uint32_t(buf, 16, reserve1);
	_mav_put_uint32_t(buf, 20, reserve2);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_RF_SYNC_LEN);
#else
	alink_rf_sync_t packet;
	packet.status1 = status1;
	packet.status2 = status2;
	packet.latitude = latitude;
	packet.longitude = longitude;
	packet.reserve1 = reserve1;
	packet.reserve2 = reserve2;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_RF_SYNC_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_RF_SYNC;
#if ALINK_CRC_EXTRA
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_RF_SYNC_LEN,ALINK_MSG_ID_RF_SYNC_CRC);
#else
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_RF_SYNC_LEN);
#endif
}
/**
 * @brief Encode a rf_sync struct
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 * @param rf_sync C-struct to read the message contents from
 */
static inline uint16_t alink_msg_rf_sync_encode(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg, const alink_rf_sync_t* rf_sync)
{
	return alink_msg_rf_sync_pack(dest_id, source_id, msg, rf_sync->status1, rf_sync->status2, rf_sync->latitude, rf_sync->longitude, rf_sync->reserve1, rf_sync->reserve2);
}

/**
 * @brief Encode a rf_sync struct on a channel
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param rf_sync C-struct to read the message contents from
 */
static inline uint16_t alink_msg_rf_sync_encode_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan, alink_message_head_t* msg, const alink_rf_sync_t* rf_sync)
{
	return alink_msg_rf_sync_pack_chan(dest_id, source_id, chan, msg, rf_sync->status1, rf_sync->status2, rf_sync->latitude, rf_sync->longitude, rf_sync->reserve1, rf_sync->reserve2);
}
// MESSAGE RF_SYNC UNPACKING


/**
 * @brief Get field status1 from rf_sync message
 *
 * @return status1
 */
static inline uint32_t alink_msg_rf_sync_get_status1(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field status2 from rf_sync message
 *
 * @return status2
 */
static inline uint32_t alink_msg_rf_sync_get_status2(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint32_t(msg,  4);
}

/**
 * @brief Get field latitude from rf_sync message
 *
 * @return latitude, in degrees * 1E7
 */
static inline int32_t alink_msg_rf_sync_get_latitude(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  8);
}

/**
 * @brief Get field longitude from rf_sync message
 *
 * @return longitude, in degrees * 1E7
 */
static inline int32_t alink_msg_rf_sync_get_longitude(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  12);
}

/**
 * @brief Get field reserve1 from rf_sync message
 *
 * @return reserve1
 */
static inline uint32_t alink_msg_rf_sync_get_reserve1(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint32_t(msg,  16);
}

/**
 * @brief Get field reserve2 from rf_sync message
 *
 * @return reserve2
 */
static inline uint32_t alink_msg_rf_sync_get_reserve2(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint32_t(msg,  20);
}

/**
 * @brief Decode a rf_sync message into a struct
 *
 * @param msg The message to decode
 * @param rf_sync C-struct to decode the message contents into
 */
static inline void alink_msg_rf_sync_decode(const alink_message_head_t* msg, alink_rf_sync_t* rf_sync)
{
#if ALINK_NEED_BYTE_SWAP
	rf_sync->status1 = alink_msg_rf_sync_get_status1(msg);
	rf_sync->status2 = alink_msg_rf_sync_get_status2(msg);
	rf_sync->latitude = alink_msg_rf_sync_get_latitude(msg);
	rf_sync->longitude = alink_msg_rf_sync_get_longitude(msg);
	rf_sync->reserve1 = alink_msg_rf_sync_get_reserve1(msg);
	rf_sync->reserve2 = alink_msg_rf_sync_get_reserve2(msg);
#else
	memcpy(rf_sync, _MAV_PAYLOAD(msg), ALINK_MSG_ID_RF_SYNC_LEN);
#endif
}
