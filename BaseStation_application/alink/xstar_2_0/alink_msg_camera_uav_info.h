// MESSAGE CAMERA_UAV_INFO PACKING

#define ALINK_MSG_ID_CAMERA_UAV_INFO 111

typedef struct __alink_camera_uav_info_t
{
 uint64_t timestamp; /*< timestamp, ms*/
 double lambda_est_rad; /*< longitude, rad*/
 double mue_est_rad; /*< latitude, rad*/
 float h_MSL_m; /*< altitude above mean sea level, m*/
 float h_AGL_m; /*< altitude, m*/
 float Vel_x_G; /*< drone x speed, m/s*/
 float Vel_y_G; /*< drone y speed, m/s*/
 float Vel_z_G; /*< drone z speed, m/s*/
 float theta_rad; /*< drone pitch, rad*/
 float phi_rad; /*< drone roll, rad*/
 float Psi_star_rad; /*< drone yaw, rad*/
 float lat_sigma; /*< latitude sigma, m*/
 float lon_sigma; /*< longitude sigma, m*/
 float hgt_sigma; /*< altitude sigma, m*/
 int16_t pitch; /*< gimbal pitch angle in 10E-2 degrees*/
 int16_t roll; /*< gimbal roll angel in 10E-2 degrees*/
 int16_t yaw; /*< gimbal yaw angle in 10E-2 degrees*/
} alink_camera_uav_info_t;

#define ALINK_MSG_ID_CAMERA_UAV_INFO_LEN 74
#define ALINK_MSG_ID_111_LEN 74

#define ALINK_MSG_ID_CAMERA_UAV_INFO_CRC 178
#define ALINK_MSG_ID_111_CRC 178



#define ALINK_MESSAGE_INFO_CAMERA_UAV_INFO { \
	"CAMERA_UAV_INFO", \
	17, \
	{  { "timestamp", NULL, ALINK_TYPE_UINT64_T, 0, 0, offsetof(alink_camera_uav_info_t, timestamp) }, \
         { "lambda_est_rad", NULL, ALINK_TYPE_DOUBLE, 0, 8, offsetof(alink_camera_uav_info_t, lambda_est_rad) }, \
         { "mue_est_rad", NULL, ALINK_TYPE_DOUBLE, 0, 16, offsetof(alink_camera_uav_info_t, mue_est_rad) }, \
         { "h_MSL_m", NULL, ALINK_TYPE_FLOAT, 0, 24, offsetof(alink_camera_uav_info_t, h_MSL_m) }, \
         { "h_AGL_m", NULL, ALINK_TYPE_FLOAT, 0, 28, offsetof(alink_camera_uav_info_t, h_AGL_m) }, \
         { "Vel_x_G", NULL, ALINK_TYPE_FLOAT, 0, 32, offsetof(alink_camera_uav_info_t, Vel_x_G) }, \
         { "Vel_y_G", NULL, ALINK_TYPE_FLOAT, 0, 36, offsetof(alink_camera_uav_info_t, Vel_y_G) }, \
         { "Vel_z_G", NULL, ALINK_TYPE_FLOAT, 0, 40, offsetof(alink_camera_uav_info_t, Vel_z_G) }, \
         { "theta_rad", NULL, ALINK_TYPE_FLOAT, 0, 44, offsetof(alink_camera_uav_info_t, theta_rad) }, \
         { "phi_rad", NULL, ALINK_TYPE_FLOAT, 0, 48, offsetof(alink_camera_uav_info_t, phi_rad) }, \
         { "Psi_star_rad", NULL, ALINK_TYPE_FLOAT, 0, 52, offsetof(alink_camera_uav_info_t, Psi_star_rad) }, \
         { "lat_sigma", NULL, ALINK_TYPE_FLOAT, 0, 56, offsetof(alink_camera_uav_info_t, lat_sigma) }, \
         { "lon_sigma", NULL, ALINK_TYPE_FLOAT, 0, 60, offsetof(alink_camera_uav_info_t, lon_sigma) }, \
         { "hgt_sigma", NULL, ALINK_TYPE_FLOAT, 0, 64, offsetof(alink_camera_uav_info_t, hgt_sigma) }, \
         { "pitch", NULL, ALINK_TYPE_INT16_T, 0, 68, offsetof(alink_camera_uav_info_t, pitch) }, \
         { "roll", NULL, ALINK_TYPE_INT16_T, 0, 70, offsetof(alink_camera_uav_info_t, roll) }, \
         { "yaw", NULL, ALINK_TYPE_INT16_T, 0, 72, offsetof(alink_camera_uav_info_t, yaw) }, \
         } \
}


/**
 * @brief Pack a camera_uav_info message
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 *
 * @param timestamp timestamp, ms
 * @param lambda_est_rad longitude, rad
 * @param mue_est_rad latitude, rad
 * @param h_MSL_m altitude above mean sea level, m
 * @param h_AGL_m altitude, m
 * @param Vel_x_G drone x speed, m/s
 * @param Vel_y_G drone y speed, m/s
 * @param Vel_z_G drone z speed, m/s
 * @param theta_rad drone pitch, rad
 * @param phi_rad drone roll, rad
 * @param Psi_star_rad drone yaw, rad
 * @param pitch gimbal pitch angle in 10E-2 degrees
 * @param roll gimbal roll angel in 10E-2 degrees
 * @param yaw gimbal yaw angle in 10E-2 degrees
 * @param lat_sigma latitude sigma, m
 * @param lon_sigma longitude sigma, m
 * @param hgt_sigma altitude sigma, m
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_camera_uav_info_pack(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg,
						       uint64_t timestamp, double lambda_est_rad, double mue_est_rad, float h_MSL_m, float h_AGL_m, float Vel_x_G, float Vel_y_G, float Vel_z_G, float theta_rad, float phi_rad, float Psi_star_rad, int16_t pitch, int16_t roll, int16_t yaw, float lat_sigma, float lon_sigma, float hgt_sigma)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_CAMERA_UAV_INFO_LEN];
	_mav_put_uint64_t(buf, 0, timestamp);
	_mav_put_double(buf, 8, lambda_est_rad);
	_mav_put_double(buf, 16, mue_est_rad);
	_mav_put_float(buf, 24, h_MSL_m);
	_mav_put_float(buf, 28, h_AGL_m);
	_mav_put_float(buf, 32, Vel_x_G);
	_mav_put_float(buf, 36, Vel_y_G);
	_mav_put_float(buf, 40, Vel_z_G);
	_mav_put_float(buf, 44, theta_rad);
	_mav_put_float(buf, 48, phi_rad);
	_mav_put_float(buf, 52, Psi_star_rad);
	_mav_put_float(buf, 56, lat_sigma);
	_mav_put_float(buf, 60, lon_sigma);
	_mav_put_float(buf, 64, hgt_sigma);
	_mav_put_int16_t(buf, 68, pitch);
	_mav_put_int16_t(buf, 70, roll);
	_mav_put_int16_t(buf, 72, yaw);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_CAMERA_UAV_INFO_LEN);
#else
	alink_camera_uav_info_t packet;
	packet.timestamp = timestamp;
	packet.lambda_est_rad = lambda_est_rad;
	packet.mue_est_rad = mue_est_rad;
	packet.h_MSL_m = h_MSL_m;
	packet.h_AGL_m = h_AGL_m;
	packet.Vel_x_G = Vel_x_G;
	packet.Vel_y_G = Vel_y_G;
	packet.Vel_z_G = Vel_z_G;
	packet.theta_rad = theta_rad;
	packet.phi_rad = phi_rad;
	packet.Psi_star_rad = Psi_star_rad;
	packet.lat_sigma = lat_sigma;
	packet.lon_sigma = lon_sigma;
	packet.hgt_sigma = hgt_sigma;
	packet.pitch = pitch;
	packet.roll = roll;
	packet.yaw = yaw;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_CAMERA_UAV_INFO_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_CAMERA_UAV_INFO;
#if ALINK_CRC_EXTRA
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_CAMERA_UAV_INFO_LEN,ALINK_MSG_ID_CAMERA_UAV_INFO_CRC);
#else
    return alink_finalize_message(msg, dest_id, source_id,ALINK_MSG_ID_CAMERA_UAV_INFO_LEN);
#endif
}

/**
 * @brief Pack a camera_uav_info message on a channel
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param timestamp timestamp, ms
 * @param lambda_est_rad longitude, rad
 * @param mue_est_rad latitude, rad
 * @param h_MSL_m altitude above mean sea level, m
 * @param h_AGL_m altitude, m
 * @param Vel_x_G drone x speed, m/s
 * @param Vel_y_G drone y speed, m/s
 * @param Vel_z_G drone z speed, m/s
 * @param theta_rad drone pitch, rad
 * @param phi_rad drone roll, rad
 * @param Psi_star_rad drone yaw, rad
 * @param pitch gimbal pitch angle in 10E-2 degrees
 * @param roll gimbal roll angel in 10E-2 degrees
 * @param yaw gimbal yaw angle in 10E-2 degrees
 * @param lat_sigma latitude sigma, m
 * @param lon_sigma longitude sigma, m
 * @param hgt_sigma altitude sigma, m
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t alink_msg_camera_uav_info_pack_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan,
							   alink_message_head_t* msg,
						           uint64_t timestamp,double lambda_est_rad,double mue_est_rad,float h_MSL_m,float h_AGL_m,float Vel_x_G,float Vel_y_G,float Vel_z_G,float theta_rad,float phi_rad,float Psi_star_rad,int16_t pitch,int16_t roll,int16_t yaw,float lat_sigma,float lon_sigma,float hgt_sigma)
{
#if ALINK_NEED_BYTE_SWAP || !ALINK_ALIGNED_FIELDS
	char buf[ALINK_MSG_ID_CAMERA_UAV_INFO_LEN];
	_mav_put_uint64_t(buf, 0, timestamp);
	_mav_put_double(buf, 8, lambda_est_rad);
	_mav_put_double(buf, 16, mue_est_rad);
	_mav_put_float(buf, 24, h_MSL_m);
	_mav_put_float(buf, 28, h_AGL_m);
	_mav_put_float(buf, 32, Vel_x_G);
	_mav_put_float(buf, 36, Vel_y_G);
	_mav_put_float(buf, 40, Vel_z_G);
	_mav_put_float(buf, 44, theta_rad);
	_mav_put_float(buf, 48, phi_rad);
	_mav_put_float(buf, 52, Psi_star_rad);
	_mav_put_float(buf, 56, lat_sigma);
	_mav_put_float(buf, 60, lon_sigma);
	_mav_put_float(buf, 64, hgt_sigma);
	_mav_put_int16_t(buf, 68, pitch);
	_mav_put_int16_t(buf, 70, roll);
	_mav_put_int16_t(buf, 72, yaw);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf,ALINK_MSG_ID_CAMERA_UAV_INFO_LEN);
#else
	alink_camera_uav_info_t packet;
	packet.timestamp = timestamp;
	packet.lambda_est_rad = lambda_est_rad;
	packet.mue_est_rad = mue_est_rad;
	packet.h_MSL_m = h_MSL_m;
	packet.h_AGL_m = h_AGL_m;
	packet.Vel_x_G = Vel_x_G;
	packet.Vel_y_G = Vel_y_G;
	packet.Vel_z_G = Vel_z_G;
	packet.theta_rad = theta_rad;
	packet.phi_rad = phi_rad;
	packet.Psi_star_rad = Psi_star_rad;
	packet.lat_sigma = lat_sigma;
	packet.lon_sigma = lon_sigma;
	packet.hgt_sigma = hgt_sigma;
	packet.pitch = pitch;
	packet.roll = roll;
	packet.yaw = yaw;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet,ALINK_MSG_ID_CAMERA_UAV_INFO_LEN);
#endif

	msg->msgid =ALINK_MSG_ID_CAMERA_UAV_INFO;
#if ALINK_CRC_EXTRA
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_CAMERA_UAV_INFO_LEN,ALINK_MSG_ID_CAMERA_UAV_INFO_CRC);
#else
    return alink_finalize_message_chan(msg, dest_id, source_id, chan,ALINK_MSG_ID_CAMERA_UAV_INFO_LEN);
#endif
}
/**
 * @brief Encode a camera_uav_info struct
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param msg The ALink message to compress the data into
 * @param camera_uav_info C-struct to read the message contents from
 */
static inline uint16_t alink_msg_camera_uav_info_encode(uint8_t dest_id, uint8_t source_id, alink_message_head_t* msg, const alink_camera_uav_info_t* camera_uav_info)
{
	return alink_msg_camera_uav_info_pack(dest_id, source_id, msg, camera_uav_info->timestamp, camera_uav_info->lambda_est_rad, camera_uav_info->mue_est_rad, camera_uav_info->h_MSL_m, camera_uav_info->h_AGL_m, camera_uav_info->Vel_x_G, camera_uav_info->Vel_y_G, camera_uav_info->Vel_z_G, camera_uav_info->theta_rad, camera_uav_info->phi_rad, camera_uav_info->Psi_star_rad, camera_uav_info->pitch, camera_uav_info->roll, camera_uav_info->yaw, camera_uav_info->lat_sigma, camera_uav_info->lon_sigma, camera_uav_info->hgt_sigma);
}

/**
 * @brief Encode a camera_uav_info struct on a channel
 *
 * @param dest_id ID of this system
 * @param source_id ID of this component (e.g. 200 for IMU)
 * @param chan The ALink channel this message will be sent over
 * @param msg The ALink message to compress the data into
 * @param camera_uav_info C-struct to read the message contents from
 */
static inline uint16_t alink_msg_camera_uav_info_encode_chan(uint8_t dest_id, uint8_t source_id, uint8_t chan, alink_message_head_t* msg, const alink_camera_uav_info_t* camera_uav_info)
{
	return alink_msg_camera_uav_info_pack_chan(dest_id, source_id, chan, msg, camera_uav_info->timestamp, camera_uav_info->lambda_est_rad, camera_uav_info->mue_est_rad, camera_uav_info->h_MSL_m, camera_uav_info->h_AGL_m, camera_uav_info->Vel_x_G, camera_uav_info->Vel_y_G, camera_uav_info->Vel_z_G, camera_uav_info->theta_rad, camera_uav_info->phi_rad, camera_uav_info->Psi_star_rad, camera_uav_info->pitch, camera_uav_info->roll, camera_uav_info->yaw, camera_uav_info->lat_sigma, camera_uav_info->lon_sigma, camera_uav_info->hgt_sigma);
}
// MESSAGE CAMERA_UAV_INFO UNPACKING


/**
 * @brief Get field timestamp from camera_uav_info message
 *
 * @return timestamp, ms
 */
static inline uint64_t alink_msg_camera_uav_info_get_timestamp(const alink_message_head_t* msg)
{
	return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field lambda_est_rad from camera_uav_info message
 *
 * @return longitude, rad
 */
static inline double alink_msg_camera_uav_info_get_lambda_est_rad(const alink_message_head_t* msg)
{
	return _MAV_RETURN_double(msg,  8);
}

/**
 * @brief Get field mue_est_rad from camera_uav_info message
 *
 * @return latitude, rad
 */
static inline double alink_msg_camera_uav_info_get_mue_est_rad(const alink_message_head_t* msg)
{
	return _MAV_RETURN_double(msg,  16);
}

/**
 * @brief Get field h_MSL_m from camera_uav_info message
 *
 * @return altitude above mean sea level, m
 */
static inline float alink_msg_camera_uav_info_get_h_MSL_m(const alink_message_head_t* msg)
{
	return _MAV_RETURN_float(msg,  24);
}

/**
 * @brief Get field h_AGL_m from camera_uav_info message
 *
 * @return altitude, m
 */
static inline float alink_msg_camera_uav_info_get_h_AGL_m(const alink_message_head_t* msg)
{
	return _MAV_RETURN_float(msg,  28);
}

/**
 * @brief Get field Vel_x_G from camera_uav_info message
 *
 * @return drone x speed, m/s
 */
static inline float alink_msg_camera_uav_info_get_Vel_x_G(const alink_message_head_t* msg)
{
	return _MAV_RETURN_float(msg,  32);
}

/**
 * @brief Get field Vel_y_G from camera_uav_info message
 *
 * @return drone y speed, m/s
 */
static inline float alink_msg_camera_uav_info_get_Vel_y_G(const alink_message_head_t* msg)
{
	return _MAV_RETURN_float(msg,  36);
}

/**
 * @brief Get field Vel_z_G from camera_uav_info message
 *
 * @return drone z speed, m/s
 */
static inline float alink_msg_camera_uav_info_get_Vel_z_G(const alink_message_head_t* msg)
{
	return _MAV_RETURN_float(msg,  40);
}

/**
 * @brief Get field theta_rad from camera_uav_info message
 *
 * @return drone pitch, rad
 */
static inline float alink_msg_camera_uav_info_get_theta_rad(const alink_message_head_t* msg)
{
	return _MAV_RETURN_float(msg,  44);
}

/**
 * @brief Get field phi_rad from camera_uav_info message
 *
 * @return drone roll, rad
 */
static inline float alink_msg_camera_uav_info_get_phi_rad(const alink_message_head_t* msg)
{
	return _MAV_RETURN_float(msg,  48);
}

/**
 * @brief Get field Psi_star_rad from camera_uav_info message
 *
 * @return drone yaw, rad
 */
static inline float alink_msg_camera_uav_info_get_Psi_star_rad(const alink_message_head_t* msg)
{
	return _MAV_RETURN_float(msg,  52);
}

/**
 * @brief Get field pitch from camera_uav_info message
 *
 * @return gimbal pitch angle in 10E-2 degrees
 */
static inline int16_t alink_msg_camera_uav_info_get_pitch(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  68);
}

/**
 * @brief Get field roll from camera_uav_info message
 *
 * @return gimbal roll angel in 10E-2 degrees
 */
static inline int16_t alink_msg_camera_uav_info_get_roll(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  70);
}

/**
 * @brief Get field yaw from camera_uav_info message
 *
 * @return gimbal yaw angle in 10E-2 degrees
 */
static inline int16_t alink_msg_camera_uav_info_get_yaw(const alink_message_head_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  72);
}

/**
 * @brief Get field lat_sigma from camera_uav_info message
 *
 * @return latitude sigma, m
 */
static inline float alink_msg_camera_uav_info_get_lat_sigma(const alink_message_head_t* msg)
{
	return _MAV_RETURN_float(msg,  56);
}

/**
 * @brief Get field lon_sigma from camera_uav_info message
 *
 * @return longitude sigma, m
 */
static inline float alink_msg_camera_uav_info_get_lon_sigma(const alink_message_head_t* msg)
{
	return _MAV_RETURN_float(msg,  60);
}

/**
 * @brief Get field hgt_sigma from camera_uav_info message
 *
 * @return altitude sigma, m
 */
static inline float alink_msg_camera_uav_info_get_hgt_sigma(const alink_message_head_t* msg)
{
	return _MAV_RETURN_float(msg,  64);
}

/**
 * @brief Decode a camera_uav_info message into a struct
 *
 * @param msg The message to decode
 * @param camera_uav_info C-struct to decode the message contents into
 */
static inline void alink_msg_camera_uav_info_decode(const alink_message_head_t* msg, alink_camera_uav_info_t* camera_uav_info)
{
#if ALINK_NEED_BYTE_SWAP
	camera_uav_info->timestamp = alink_msg_camera_uav_info_get_timestamp(msg);
	camera_uav_info->lambda_est_rad = alink_msg_camera_uav_info_get_lambda_est_rad(msg);
	camera_uav_info->mue_est_rad = alink_msg_camera_uav_info_get_mue_est_rad(msg);
	camera_uav_info->h_MSL_m = alink_msg_camera_uav_info_get_h_MSL_m(msg);
	camera_uav_info->h_AGL_m = alink_msg_camera_uav_info_get_h_AGL_m(msg);
	camera_uav_info->Vel_x_G = alink_msg_camera_uav_info_get_Vel_x_G(msg);
	camera_uav_info->Vel_y_G = alink_msg_camera_uav_info_get_Vel_y_G(msg);
	camera_uav_info->Vel_z_G = alink_msg_camera_uav_info_get_Vel_z_G(msg);
	camera_uav_info->theta_rad = alink_msg_camera_uav_info_get_theta_rad(msg);
	camera_uav_info->phi_rad = alink_msg_camera_uav_info_get_phi_rad(msg);
	camera_uav_info->Psi_star_rad = alink_msg_camera_uav_info_get_Psi_star_rad(msg);
	camera_uav_info->lat_sigma = alink_msg_camera_uav_info_get_lat_sigma(msg);
	camera_uav_info->lon_sigma = alink_msg_camera_uav_info_get_lon_sigma(msg);
	camera_uav_info->hgt_sigma = alink_msg_camera_uav_info_get_hgt_sigma(msg);
	camera_uav_info->pitch = alink_msg_camera_uav_info_get_pitch(msg);
	camera_uav_info->roll = alink_msg_camera_uav_info_get_roll(msg);
	camera_uav_info->yaw = alink_msg_camera_uav_info_get_yaw(msg);
#else
	memcpy(camera_uav_info, _MAV_PAYLOAD(msg), ALINK_MSG_ID_CAMERA_UAV_INFO_LEN);
#endif
}
