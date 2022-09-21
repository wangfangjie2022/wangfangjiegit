// MESSAGE MOVIDUS_SETTINGS PACKING

#define ALINK_MSG_ID_MOVIDUS_SETTINGS 119

typedef struct __alink_movidus_settings_t
{
 int16_t pointfly_angle; /*<  pointfly angle in 10E-1 deg, range from -90 ~ +90 deg */
 uint8_t obstacle_avoidance_mode; /*<  obstacle avoidance mode */
 uint8_t speed_limit; /*<  speed limit in 10E-1 m/s , range from 0~10m/s*/
 uint8_t pointfly_oa_type; /*<  obstacle avoidance type when point fly  */
 uint8_t followme_oa_enable; /*<  follow me obstacle avoidance enable*/
 uint8_t radar_show_enbale; /*<  radar show (SOA) enable  */
 uint8_t followme_backoff_enable; /*<  followme backoff enable */
 uint8_t landing_protection_enable; /*<  landing protection enable  */
 uint8_t RTH_oa_enable; /*<  RTH obstacle avoidance enable */
 uint8_t visual_positioning_enable; /*<  visual positioning (VIO) enable  */
 uint8_t precise_landing_enable; /*<  precise landing enable */
 uint8_t pointfly_positione_set; /*<  is pointfly position set  */
 uint8_t pointfly_speed; /*< point fly speed in 10E-1 m/s , range from 0~10m/s*/
 uint8_t is_pointfly_started; /*<  is pointfly started  */
 uint8_t terrain_follow_enable; /*< terrain follow enable*/
 uint8_t followme_mode; /*<  followme mode  */
 uint8_t tripod_mode; /*< tripod mode*/
 uint8_t cinera_mode; /*<  cinera mode  */
 uint8_t fixwing_mode; /*<  fixwing mode */
 uint8_t gesture_recognization_enable; /*<  gesture recognization mode */
 uint8_t vision_calibration_enable; /*<  visual calibration mode */
 uint8_t pointfly_inside; /*<  0 - outside , 1 - inside */
 uint8_t pointfly_xscale; /*<  scaled x position on screen [1,99] */
 uint8_t pointfly_yscale; /*<  scaled y position on screen [1,99] */
 uint8_t reserved[7]; /*<  reserved for future use */
} alink_movidus_settings_t;

#define ALINK_MSG_ID_MOVIDUS_SETTINGS_LEN 32
#define ALINK_MSG_ID_119_LEN 32

#define ALINK_MSG_ID_MOVIDUS_SETTINGS_CRC 137
#define ALINK_MSG_ID_119_CRC 137

#define ALINK_MSG_MOVIDUS_SETTINGS_FIELD_RESERVED_LEN 7

#define ALINK_MESSAGE_INFO_MOVIDUS_SETTINGS { \
	"MOVIDUS_SETTINGS", \
	25, \
	{  { "pointfly_angle", NULL, ALINK_TYPE_INT16_T, 0, 0, offsetof(alink_movidus_settings_t, pointfly_angle) }, \
         { "obstacle_avoidance_mode", NULL, ALINK_TYPE_UINT8_T, 0, 2, offsetof(alink_movidus_settings_t, obstacle_avoidance_mode) }, \
         { "speed_limit", NULL, ALINK_TYPE_UINT8_T, 0, 3, offsetof(alink_movidus_settings_t, speed_limit) }, \
         { "pointfly_oa_type", NULL, ALINK_TYPE_UINT8_T, 0, 4, offsetof(alink_movidus_settings_t, pointfly_oa_type) }, \
         { "followme_oa_enable", NULL, ALINK_TYPE_UINT8_T, 0, 5, offsetof(alink_movidus_settings_t, followme_oa_enable) }, \
         { "radar_show_enbale", NULL, ALINK_TYPE_UINT8_T, 0, 6, offsetof(alink_movidus_settings_t, radar_show_enbale) }, \
         { "followme_backoff_enable", NULL, ALINK_TYPE_UINT8_T, 0, 7, offsetof(alink_movidus_settings_t, followme_backoff_enable) }, \
         { "landing_protection_enable", NULL, ALINK_TYPE_UINT8_T, 0, 8, offsetof(alink_movidus_settings_t, landing_protection_enable) }, \
         { "RTH_oa_enable", NULL, ALINK_TYPE_UINT8_T, 0, 9, offsetof(alink_movidus_settings_t, RTH_oa_enable) }, \
         { "visual_positioning_enable", NULL, ALINK_TYPE_UINT8_T, 0, 10, offsetof(alink_movidus_settings_t, visual_positioning_enable) }, \
         { "precise_landing_enable", NULL, ALINK_TYPE_UINT8_T, 0, 11, offsetof(alink_movidus_settings_t, precise_landing_enable) }, \
         { "pointfly_positione_set", NULL, ALINK_TYPE_UINT8_T, 0, 12, offsetof(alink_movidus_settings_t, pointfly_positione_set) }, \
         { "pointfly_speed", NULL, ALINK_TYPE_UINT8_T, 0, 13, offsetof(alink_movidus_settings_t, pointfly_speed) }, \
         { "is_pointfly_started", NULL, ALINK_TYPE_UINT8_T, 0, 14, offsetof(alink_movidus_settings_t, is_pointfly_started) }, \
         { "terrain_follow_enable", NULL, ALINK_TYPE_UINT8_T, 0, 15, offsetof(alink_movidus_settings_t, terrain_follow_enable) }, \
         { "followme_mode", NULL, ALINK_TYPE_UINT8_T, 0, 16, offsetof(alink_movidus_settings_t, followme_mode) }, \
         { "tripod_mode", NULL, ALINK_TYPE_UINT8_T, 0, 17, offsetof(alink_movidus_settings_t, tripod_mode) }, \
         { "cinera_mode", NULL, ALINK_TYPE_UINT8_T, 0, 18, offsetof(alink_movidus_settings_t, cinera_mode) }, \
         { "fixwing_mode", NULL, ALINK_TYPE_UINT8_T, 0, 19, offsetof(alink_movidus_settings_t, fixwing_mode) }, \
         { "gesture_recognization_enable", NULL, ALINK_TYPE_UINT8_T, 0, 20, offsetof(alink_movidus_settings_t, gesture_recognization_enable) }, \
         { "vision_calibration_enable", NULL, ALINK_TYPE_UINT8_T, 0, 21, offsetof(alink_movidus_settings_t, vision_calibration_enable) }, \
         { "pointfly_inside", NULL, ALINK_TYPE_UINT8_T, 0, 22, offsetof(alink_movidus_settings_t, pointfly_inside) }, \
         { "pointfly_xscale", NULL, ALINK_TYPE_UINT8_T, 0, 23, offsetof(alink_movidus_settings_t, pointfly_xscale) }, \
         { "pointfly_yscale", NULL, ALINK_TYPE_UINT8_T, 0, 24, offsetof(alink_movidus_settings_t, pointfly_yscale) }, \
         { "reserved", NULL, ALINK_TYPE_UINT8_T, 7, 25, offsetof(alink_movidus_settings_t, reserved) }, \
         } \
}


/**
 * @brief Pack a movidus_settings message
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 *
 * @param obstacle_avoidance_mode  obstacle avoidance mode 
 * @param speed_limit  speed limit in 10E-1 m/s , range from 0~10m/s
 * @param pointfly_oa_type  obstacle avoidance type when point fly  
 * @param followme_oa_enable  follow me obstacle avoidance enable
 * @param radar_show_enbale  radar show (SOA) enable  
 * @param followme_backoff_enable  followme backoff enable 
 * @param landing_protection_enable  landing protection enable  
 * @param RTH_oa_enable  RTH obstacle avoidance enable 
 * @param visual_positioning_enable  visual positioning (VIO) enable  
 * @param precise_landing_enable  precise landing enable 
 * @param pointfly_positione_set  is pointfly position set  
 * @param pointfly_speed point fly speed in 10E-1 m/s , range from 0~10m/s
 * @param is_pointfly_started  is pointfly started  
 * @param terrain_follow_enable terrain follow enable
 * @param followme_mode  followme mode  
 * @param tripod_mode tripod mode
 * @param cinera_mode  cinera mode  
 * @param fixwing_mode  fixwing mode 
 * @param gesture_recognization_enable  gesture recognization mode 
 * @param vision_calibration_enable  visual calibration mode 
 * @param pointfly_angle  pointfly angle in 10E-1 deg, range from -90 ~ +90 deg 
 * @param pointfly_inside  0 - outside , 1 - inside 
 * @param pointfly_xscale  scaled x position on screen [1,99] 
 * @param pointfly_yscale  scaled y position on screen [1,99] 
 * @param reserved  reserved for future use 
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_movidus_settings_pack(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg,
						       uint8_t obstacle_avoidance_mode, uint8_t speed_limit, uint8_t pointfly_oa_type, uint8_t followme_oa_enable, uint8_t radar_show_enbale, uint8_t followme_backoff_enable, uint8_t landing_protection_enable, uint8_t RTH_oa_enable, uint8_t visual_positioning_enable, uint8_t precise_landing_enable, uint8_t pointfly_positione_set, uint8_t pointfly_speed, uint8_t is_pointfly_started, uint8_t terrain_follow_enable, uint8_t followme_mode, uint8_t tripod_mode, uint8_t cinera_mode, uint8_t fixwing_mode, uint8_t gesture_recognization_enable, uint8_t vision_calibration_enable, int16_t pointfly_angle, uint8_t pointfly_inside, uint8_t pointfly_xscale, uint8_t pointfly_yscale, const uint8_t *reserved)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_MOVIDUS_SETTINGS_LEN];
	_mav_put_int16_t(buf, 0, pointfly_angle);
	_mav_put_uint8_t(buf, 2, obstacle_avoidance_mode);
	_mav_put_uint8_t(buf, 3, speed_limit);
	_mav_put_uint8_t(buf, 4, pointfly_oa_type);
	_mav_put_uint8_t(buf, 5, followme_oa_enable);
	_mav_put_uint8_t(buf, 6, radar_show_enbale);
	_mav_put_uint8_t(buf, 7, followme_backoff_enable);
	_mav_put_uint8_t(buf, 8, landing_protection_enable);
	_mav_put_uint8_t(buf, 9, RTH_oa_enable);
	_mav_put_uint8_t(buf, 10, visual_positioning_enable);
	_mav_put_uint8_t(buf, 11, precise_landing_enable);
	_mav_put_uint8_t(buf, 12, pointfly_positione_set);
	_mav_put_uint8_t(buf, 13, pointfly_speed);
	_mav_put_uint8_t(buf, 14, is_pointfly_started);
	_mav_put_uint8_t(buf, 15, terrain_follow_enable);
	_mav_put_uint8_t(buf, 16, followme_mode);
	_mav_put_uint8_t(buf, 17, tripod_mode);
	_mav_put_uint8_t(buf, 18, cinera_mode);
	_mav_put_uint8_t(buf, 19, fixwing_mode);
	_mav_put_uint8_t(buf, 20, gesture_recognization_enable);
	_mav_put_uint8_t(buf, 21, vision_calibration_enable);
	_mav_put_uint8_t(buf, 22, pointfly_inside);
	_mav_put_uint8_t(buf, 23, pointfly_xscale);
	_mav_put_uint8_t(buf, 24, pointfly_yscale);
	_mav_put_uint8_t_array(buf, 25, reserved, 7);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_MOVIDUS_SETTINGS_LEN);
#else
	alink_movidus_settings_t packet;
	packet.pointfly_angle = pointfly_angle;
	packet.obstacle_avoidance_mode = obstacle_avoidance_mode;
	packet.speed_limit = speed_limit;
	packet.pointfly_oa_type = pointfly_oa_type;
	packet.followme_oa_enable = followme_oa_enable;
	packet.radar_show_enbale = radar_show_enbale;
	packet.followme_backoff_enable = followme_backoff_enable;
	packet.landing_protection_enable = landing_protection_enable;
	packet.RTH_oa_enable = RTH_oa_enable;
	packet.visual_positioning_enable = visual_positioning_enable;
	packet.precise_landing_enable = precise_landing_enable;
	packet.pointfly_positione_set = pointfly_positione_set;
	packet.pointfly_speed = pointfly_speed;
	packet.is_pointfly_started = is_pointfly_started;
	packet.terrain_follow_enable = terrain_follow_enable;
	packet.followme_mode = followme_mode;
	packet.tripod_mode = tripod_mode;
	packet.cinera_mode = cinera_mode;
	packet.fixwing_mode = fixwing_mode;
	packet.gesture_recognization_enable = gesture_recognization_enable;
	packet.vision_calibration_enable = vision_calibration_enable;
	packet.pointfly_inside = pointfly_inside;
	packet.pointfly_xscale = pointfly_xscale;
	packet.pointfly_yscale = pointfly_yscale;
	mav_array_memcpy(packet.reserved, reserved, sizeof(uint8_t)*7);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_MOVIDUS_SETTINGS_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_MOVIDUS_SETTINGS;
#if ALINK_CRC_EXTRA
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_MOVIDUS_SETTINGS_LEN,ALINK_MSG_ID_MOVIDUS_SETTINGS_CRC);
#else
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_MOVIDUS_SETTINGS_LEN);
#endif
}

/**
 * @brief Pack a movidus_settings message on a channel
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param obstacle_avoidance_mode  obstacle avoidance mode 
 * @param speed_limit  speed limit in 10E-1 m/s , range from 0~10m/s
 * @param pointfly_oa_type  obstacle avoidance type when point fly  
 * @param followme_oa_enable  follow me obstacle avoidance enable
 * @param radar_show_enbale  radar show (SOA) enable  
 * @param followme_backoff_enable  followme backoff enable 
 * @param landing_protection_enable  landing protection enable  
 * @param RTH_oa_enable  RTH obstacle avoidance enable 
 * @param visual_positioning_enable  visual positioning (VIO) enable  
 * @param precise_landing_enable  precise landing enable 
 * @param pointfly_positione_set  is pointfly position set  
 * @param pointfly_speed point fly speed in 10E-1 m/s , range from 0~10m/s
 * @param is_pointfly_started  is pointfly started  
 * @param terrain_follow_enable terrain follow enable
 * @param followme_mode  followme mode  
 * @param tripod_mode tripod mode
 * @param cinera_mode  cinera mode  
 * @param fixwing_mode  fixwing mode 
 * @param gesture_recognization_enable  gesture recognization mode 
 * @param vision_calibration_enable  visual calibration mode 
 * @param pointfly_angle  pointfly angle in 10E-1 deg, range from -90 ~ +90 deg 
 * @param pointfly_inside  0 - outside , 1 - inside 
 * @param pointfly_xscale  scaled x position on screen [1,99] 
 * @param pointfly_yscale  scaled y position on screen [1,99] 
 * @param reserved  reserved for future use 
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_movidus_settings_pack_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan,
							   alink_message_head_t* msg,
						           uint8_t obstacle_avoidance_mode,uint8_t speed_limit,uint8_t pointfly_oa_type,uint8_t followme_oa_enable,uint8_t radar_show_enbale,uint8_t followme_backoff_enable,uint8_t landing_protection_enable,uint8_t RTH_oa_enable,uint8_t visual_positioning_enable,uint8_t precise_landing_enable,uint8_t pointfly_positione_set,uint8_t pointfly_speed,uint8_t is_pointfly_started,uint8_t terrain_follow_enable,uint8_t followme_mode,uint8_t tripod_mode,uint8_t cinera_mode,uint8_t fixwing_mode,uint8_t gesture_recognization_enable,uint8_t vision_calibration_enable,int16_t pointfly_angle,uint8_t pointfly_inside,uint8_t pointfly_xscale,uint8_t pointfly_yscale,const uint8_t *reserved)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_MOVIDUS_SETTINGS_LEN];
	_mav_put_int16_t(buf, 0, pointfly_angle);
	_mav_put_uint8_t(buf, 2, obstacle_avoidance_mode);
	_mav_put_uint8_t(buf, 3, speed_limit);
	_mav_put_uint8_t(buf, 4, pointfly_oa_type);
	_mav_put_uint8_t(buf, 5, followme_oa_enable);
	_mav_put_uint8_t(buf, 6, radar_show_enbale);
	_mav_put_uint8_t(buf, 7, followme_backoff_enable);
	_mav_put_uint8_t(buf, 8, landing_protection_enable);
	_mav_put_uint8_t(buf, 9, RTH_oa_enable);
	_mav_put_uint8_t(buf, 10, visual_positioning_enable);
	_mav_put_uint8_t(buf, 11, precise_landing_enable);
	_mav_put_uint8_t(buf, 12, pointfly_positione_set);
	_mav_put_uint8_t(buf, 13, pointfly_speed);
	_mav_put_uint8_t(buf, 14, is_pointfly_started);
	_mav_put_uint8_t(buf, 15, terrain_follow_enable);
	_mav_put_uint8_t(buf, 16, followme_mode);
	_mav_put_uint8_t(buf, 17, tripod_mode);
	_mav_put_uint8_t(buf, 18, cinera_mode);
	_mav_put_uint8_t(buf, 19, fixwing_mode);
	_mav_put_uint8_t(buf, 20, gesture_recognization_enable);
	_mav_put_uint8_t(buf, 21, vision_calibration_enable);
	_mav_put_uint8_t(buf, 22, pointfly_inside);
	_mav_put_uint8_t(buf, 23, pointfly_xscale);
	_mav_put_uint8_t(buf, 24, pointfly_yscale);
	_mav_put_uint8_t_array(buf, 25, reserved, 7);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_MOVIDUS_SETTINGS_LEN);
#else
	alink_movidus_settings_t packet;
	packet.pointfly_angle = pointfly_angle;
	packet.obstacle_avoidance_mode = obstacle_avoidance_mode;
	packet.speed_limit = speed_limit;
	packet.pointfly_oa_type = pointfly_oa_type;
	packet.followme_oa_enable = followme_oa_enable;
	packet.radar_show_enbale = radar_show_enbale;
	packet.followme_backoff_enable = followme_backoff_enable;
	packet.landing_protection_enable = landing_protection_enable;
	packet.RTH_oa_enable = RTH_oa_enable;
	packet.visual_positioning_enable = visual_positioning_enable;
	packet.precise_landing_enable = precise_landing_enable;
	packet.pointfly_positione_set = pointfly_positione_set;
	packet.pointfly_speed = pointfly_speed;
	packet.is_pointfly_started = is_pointfly_started;
	packet.terrain_follow_enable = terrain_follow_enable;
	packet.followme_mode = followme_mode;
	packet.tripod_mode = tripod_mode;
	packet.cinera_mode = cinera_mode;
	packet.fixwing_mode = fixwing_mode;
	packet.gesture_recognization_enable = gesture_recognization_enable;
	packet.vision_calibration_enable = vision_calibration_enable;
	packet.pointfly_inside = pointfly_inside;
	packet.pointfly_xscale = pointfly_xscale;
	packet.pointfly_yscale = pointfly_yscale;
	mav_array_memcpy(packet.reserved, reserved, sizeof(uint8_t)*7);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_MOVIDUS_SETTINGS_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_MOVIDUS_SETTINGS;
#if ALINK_CRC_EXTRA
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_MOVIDUS_SETTINGS_LEN,ALINK_MSG_ID_MOVIDUS_SETTINGS_CRC);
#else
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_MOVIDUS_SETTINGS_LEN);
#endif
}
/**
 * @brief Encode a movidus_settings struct
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 * @param movidus_settings C-struct to read the message contents from
 */
static inline uint16_t alink_msg_movidus_settings_encode(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg, const alink_movidus_settings_t* movidus_settings)
{
	return alink_msg_movidus_settings_pack(dest_id, source_id, msg, movidus_settings->obstacle_avoidance_mode, movidus_settings->speed_limit, movidus_settings->pointfly_oa_type, movidus_settings->followme_oa_enable, movidus_settings->radar_show_enbale, movidus_settings->followme_backoff_enable, movidus_settings->landing_protection_enable, movidus_settings->RTH_oa_enable, movidus_settings->visual_positioning_enable, movidus_settings->precise_landing_enable, movidus_settings->pointfly_positione_set, movidus_settings->pointfly_speed, movidus_settings->is_pointfly_started, movidus_settings->terrain_follow_enable, movidus_settings->followme_mode, movidus_settings->tripod_mode, movidus_settings->cinera_mode, movidus_settings->fixwing_mode, movidus_settings->gesture_recognization_enable, movidus_settings->vision_calibration_enable, movidus_settings->pointfly_angle, movidus_settings->pointfly_inside, movidus_settings->pointfly_xscale, movidus_settings->pointfly_yscale, movidus_settings->reserved);
}

/**
 * @brief Encode a movidus_settings struct on a channel
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param movidus_settings C-struct to read the message contents from
 */
static inline uint16_t alink_msg_movidus_settings_encode_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan, alink_message_head_t* msg, const alink_movidus_settings_t* movidus_settings)
{
	return alink_msg_movidus_settings_pack_chan(dest_id, source_id, chan, msg, movidus_settings->obstacle_avoidance_mode, movidus_settings->speed_limit, movidus_settings->pointfly_oa_type, movidus_settings->followme_oa_enable, movidus_settings->radar_show_enbale, movidus_settings->followme_backoff_enable, movidus_settings->landing_protection_enable, movidus_settings->RTH_oa_enable, movidus_settings->visual_positioning_enable, movidus_settings->precise_landing_enable, movidus_settings->pointfly_positione_set, movidus_settings->pointfly_speed, movidus_settings->is_pointfly_started, movidus_settings->terrain_follow_enable, movidus_settings->followme_mode, movidus_settings->tripod_mode, movidus_settings->cinera_mode, movidus_settings->fixwing_mode, movidus_settings->gesture_recognization_enable, movidus_settings->vision_calibration_enable, movidus_settings->pointfly_angle, movidus_settings->pointfly_inside, movidus_settings->pointfly_xscale, movidus_settings->pointfly_yscale, movidus_settings->reserved);
}
// MESSAGE MOVIDUS_SETTINGS UNPACKING


/**
 * @brief Get field obstacle_avoidance_mode from movidus_settings message
 *
 * @return  obstacle avoidance mode 
 */
static inline uint8_t alink_msg_movidus_settings_get_obstacle_avoidance_mode(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  2);
}

/**
 * @brief Get field speed_limit from movidus_settings message
 *
 * @return  speed limit in 10E-1 m/s , range from 0~10m/s
 */
static inline uint8_t alink_msg_movidus_settings_get_speed_limit(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  3);
}

/**
 * @brief Get field pointfly_oa_type from movidus_settings message
 *
 * @return  obstacle avoidance type when point fly  
 */
static inline uint8_t alink_msg_movidus_settings_get_pointfly_oa_type(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  4);
}

/**
 * @brief Get field followme_oa_enable from movidus_settings message
 *
 * @return  follow me obstacle avoidance enable
 */
static inline uint8_t alink_msg_movidus_settings_get_followme_oa_enable(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  5);
}

/**
 * @brief Get field radar_show_enbale from movidus_settings message
 *
 * @return  radar show (SOA) enable  
 */
static inline uint8_t alink_msg_movidus_settings_get_radar_show_enbale(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  6);
}

/**
 * @brief Get field followme_backoff_enable from movidus_settings message
 *
 * @return  followme backoff enable 
 */
static inline uint8_t alink_msg_movidus_settings_get_followme_backoff_enable(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  7);
}

/**
 * @brief Get field landing_protection_enable from movidus_settings message
 *
 * @return  landing protection enable  
 */
static inline uint8_t alink_msg_movidus_settings_get_landing_protection_enable(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  8);
}

/**
 * @brief Get field RTH_oa_enable from movidus_settings message
 *
 * @return  RTH obstacle avoidance enable 
 */
static inline uint8_t alink_msg_movidus_settings_get_RTH_oa_enable(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  9);
}

/**
 * @brief Get field visual_positioning_enable from movidus_settings message
 *
 * @return  visual positioning (VIO) enable  
 */
static inline uint8_t alink_msg_movidus_settings_get_visual_positioning_enable(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  10);
}

/**
 * @brief Get field precise_landing_enable from movidus_settings message
 *
 * @return  precise landing enable 
 */
static inline uint8_t alink_msg_movidus_settings_get_precise_landing_enable(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  11);
}

/**
 * @brief Get field pointfly_positione_set from movidus_settings message
 *
 * @return  is pointfly position set  
 */
static inline uint8_t alink_msg_movidus_settings_get_pointfly_positione_set(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  12);
}

/**
 * @brief Get field pointfly_speed from movidus_settings message
 *
 * @return point fly speed in 10E-1 m/s , range from 0~10m/s
 */
static inline uint8_t alink_msg_movidus_settings_get_pointfly_speed(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  13);
}

/**
 * @brief Get field is_pointfly_started from movidus_settings message
 *
 * @return  is pointfly started  
 */
static inline uint8_t alink_msg_movidus_settings_get_is_pointfly_started(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  14);
}

/**
 * @brief Get field terrain_follow_enable from movidus_settings message
 *
 * @return terrain follow enable
 */
static inline uint8_t alink_msg_movidus_settings_get_terrain_follow_enable(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  15);
}

/**
 * @brief Get field followme_mode from movidus_settings message
 *
 * @return  followme mode  
 */
static inline uint8_t alink_msg_movidus_settings_get_followme_mode(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  16);
}

/**
 * @brief Get field tripod_mode from movidus_settings message
 *
 * @return tripod mode
 */
static inline uint8_t alink_msg_movidus_settings_get_tripod_mode(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  17);
}

/**
 * @brief Get field cinera_mode from movidus_settings message
 *
 * @return  cinera mode  
 */
static inline uint8_t alink_msg_movidus_settings_get_cinera_mode(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  18);
}

/**
 * @brief Get field fixwing_mode from movidus_settings message
 *
 * @return  fixwing mode 
 */
static inline uint8_t alink_msg_movidus_settings_get_fixwing_mode(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  19);
}

/**
 * @brief Get field gesture_recognization_enable from movidus_settings message
 *
 * @return  gesture recognization mode 
 */
static inline uint8_t alink_msg_movidus_settings_get_gesture_recognization_enable(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  20);
}

/**
 * @brief Get field vision_calibration_enable from movidus_settings message
 *
 * @return  visual calibration mode 
 */
static inline uint8_t alink_msg_movidus_settings_get_vision_calibration_enable(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  21);
}

/**
 * @brief Get field pointfly_angle from movidus_settings message
 *
 * @return  pointfly angle in 10E-1 deg, range from -90 ~ +90 deg 
 */
static inline int16_t alink_msg_movidus_settings_get_pointfly_angle(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  0);
}

/**
 * @brief Get field pointfly_inside from movidus_settings message
 *
 * @return  0 - outside , 1 - inside 
 */
static inline uint8_t alink_msg_movidus_settings_get_pointfly_inside(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  22);
}

/**
 * @brief Get field pointfly_xscale from movidus_settings message
 *
 * @return  scaled x position on screen [1,99] 
 */
static inline uint8_t alink_msg_movidus_settings_get_pointfly_xscale(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  23);
}

/**
 * @brief Get field pointfly_yscale from movidus_settings message
 *
 * @return  scaled y position on screen [1,99] 
 */
static inline uint8_t alink_msg_movidus_settings_get_pointfly_yscale(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  24);
}

/**
 * @brief Get field reserved from movidus_settings message
 *
 * @return  reserved for future use 
 */
static inline uint16_t alink_msg_movidus_settings_get_reserved(const alink_message_head_t* msg, uint8_t *reserved)
{
	return _MAV_RETURN_uint8_t_array(msg, reserved, 7,  25);
}

/**
 * @brief Decode a movidus_settings message into a struct
 *
 * @param msg The message to decode
 * @param movidus_settings C-struct to decode the message contents into
 */
static inline void alink_msg_movidus_settings_decode(const alink_message_head_t* msg, alink_movidus_settings_t* movidus_settings)
{
#if ALINK_NEED_BYTE_SWAP
	movidus_settings->pointfly_angle = alink_msg_movidus_settings_get_pointfly_angle(msg);
	movidus_settings->obstacle_avoidance_mode = alink_msg_movidus_settings_get_obstacle_avoidance_mode(msg);
	movidus_settings->speed_limit = alink_msg_movidus_settings_get_speed_limit(msg);
	movidus_settings->pointfly_oa_type = alink_msg_movidus_settings_get_pointfly_oa_type(msg);
	movidus_settings->followme_oa_enable = alink_msg_movidus_settings_get_followme_oa_enable(msg);
	movidus_settings->radar_show_enbale = alink_msg_movidus_settings_get_radar_show_enbale(msg);
	movidus_settings->followme_backoff_enable = alink_msg_movidus_settings_get_followme_backoff_enable(msg);
	movidus_settings->landing_protection_enable = alink_msg_movidus_settings_get_landing_protection_enable(msg);
	movidus_settings->RTH_oa_enable = alink_msg_movidus_settings_get_RTH_oa_enable(msg);
	movidus_settings->visual_positioning_enable = alink_msg_movidus_settings_get_visual_positioning_enable(msg);
	movidus_settings->precise_landing_enable = alink_msg_movidus_settings_get_precise_landing_enable(msg);
	movidus_settings->pointfly_positione_set = alink_msg_movidus_settings_get_pointfly_positione_set(msg);
	movidus_settings->pointfly_speed = alink_msg_movidus_settings_get_pointfly_speed(msg);
	movidus_settings->is_pointfly_started = alink_msg_movidus_settings_get_is_pointfly_started(msg);
	movidus_settings->terrain_follow_enable = alink_msg_movidus_settings_get_terrain_follow_enable(msg);
	movidus_settings->followme_mode = alink_msg_movidus_settings_get_followme_mode(msg);
	movidus_settings->tripod_mode = alink_msg_movidus_settings_get_tripod_mode(msg);
	movidus_settings->cinera_mode = alink_msg_movidus_settings_get_cinera_mode(msg);
	movidus_settings->fixwing_mode = alink_msg_movidus_settings_get_fixwing_mode(msg);
	movidus_settings->gesture_recognization_enable = alink_msg_movidus_settings_get_gesture_recognization_enable(msg);
	movidus_settings->vision_calibration_enable = alink_msg_movidus_settings_get_vision_calibration_enable(msg);
	movidus_settings->pointfly_inside = alink_msg_movidus_settings_get_pointfly_inside(msg);
	movidus_settings->pointfly_xscale = alink_msg_movidus_settings_get_pointfly_xscale(msg);
	movidus_settings->pointfly_yscale = alink_msg_movidus_settings_get_pointfly_yscale(msg);
	alink_msg_movidus_settings_get_reserved(msg, movidus_settings->reserved);
#else
	memcpy(movidus_settings, _MAV_PAYLOAD(msg), ALINK_MSG_ID_MOVIDUS_SETTINGS_LEN);
#endif
}
