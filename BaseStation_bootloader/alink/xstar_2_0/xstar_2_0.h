/** @file
 *	@brief ALINK comm protocol generated from xstar_2_0.xml
 *	
 */
#ifndef ALINK_XSTAR_2_0_H
#define ALINK_XSTAR_2_0_H

#ifndef ALINK_H
    #error Wrong include order: ALINK_XSTAR_2_0.H MUST NOT BE DIRECTLY USED. Include alink.h from the same directory instead or set ALL AND EVERY defines from ALINK.H manually accordingly, including the #define ALINK_H call.
#endif

#ifdef __cplusplus
extern "C" {
#endif

// MESSAGE LENGTHS AND CRCS

#ifndef ALINK_MESSAGE_LENGTHS
#define ALINK_MESSAGE_LENGTHS {18, 20, 0, 512, 512, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 18, 2, 25, 21, 24, 84, 70, 136, 0, 59, 74, 22, 22, 14, 14, 35, 29, 22, 14, 0, 0, 0, 0, 0, 0, 28, 42, 32, 24, 5, 24, 13, 19, 33, 6, 6, 12, 20, 2, 26, 28, 17, 17, 244, 6, 1, 5, 0, 0, 32, 0, 33, 0, 0, 0, 32, 35, 8, 16, 10, 12, 46, 14, 0, 0, 0, 0, 48, 48, 48, 40, 32, 16, 0, 0, 40, 80, 14, 21, 59, 0, 40, 16, 21, 44, 5, 2, 17, 2, 64, 256, 64, 4, 4, 4, 3, 74, 25, 42, 10, 13, 2, 32, 5, 32, 10, 55, 24, 412, 52, 28, 42, 4, 16, 32, 4, 24, 4, 8, 8, 66, 32, 32, 0, 0, 0, 0, 0, 0, 8, 89, 6, 512, 14, 10, 24, 1, 9, 0, 0, 0, 0, 0, 0, 48, 485, 12, 44, 0, 0, 0, 0, 0, 512, 34, 8, 32, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 38, 0, 0, 0, 0, 0, 0, 0, 0, 0}
#endif

#ifndef ALINK_MESSAGE_CRCS
#define ALINK_MESSAGE_CRCS {104, 187, 0, 18, 233, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 142, 159, 220, 22, 213, 59, 158, 59, 0, 128, 252, 148, 46, 196, 142, 42, 107, 27, 193, 0, 0, 0, 0, 0, 0, 133, 111, 33, 15, 5, 55, 14, 51, 8, 12, 194, 122, 11, 159, 130, 251, 247, 7, 57, 9, 147, 138, 0, 0, 141, 0, 31, 0, 0, 0, 62, 110, 137, 196, 190, 234, 182, 64, 0, 0, 0, 0, 233, 158, 110, 119, 190, 149, 0, 0, 136, 158, 91, 62, 249, 0, 51, 142, 54, 164, 65, 143, 249, 244, 145, 232, 171, 196, 153, 75, 183, 178, 39, 60, 34, 0, 125, 23, 79, 137, 50, 126, 46, 219, 8, 109, 13, 56, 151, 57, 89, 82, 66, 81, 81, 250, 96, 132, 0, 0, 0, 0, 0, 0, 224, 233, 146, 138, 237, 243, 36, 238, 130, 0, 0, 0, 0, 0, 0, 195, 95, 95, 115, 0, 0, 0, 0, 0, 194, 146, 20, 204, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 184, 0, 0, 0, 0, 0, 0, 0, 0, 0}
#endif

#ifndef ALINK_MESSAGE_INFO
#define ALINK_MESSAGE_INFO {ALINK_MESSAGE_INFO_HEARTBEAT, ALINK_MESSAGE_INFO_SYS_STATUS, {"EMPTY",0,{{"","",ALINK_TYPE_CHAR,0,0,0}}}, ALINK_MESSAGE_INFO_COMMAND, ALINK_MESSAGE_INFO_COMMAND_ACK, {"EMPTY",0,{{"","",ALINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",ALINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",ALINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",ALINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",ALINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",ALINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",ALINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",ALINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",ALINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",ALINK_TYPE_CHAR,0,0,0}}}, ALINK_MESSAGE_INFO_PARAM_READ, ALINK_MESSAGE_INFO_PARAM_REQUEST_LIST, ALINK_MESSAGE_INFO_PARAM_VALUE, ALINK_MESSAGE_INFO_PARAM_SET, ALINK_MESSAGE_INFO_SERVO_OUTPUT_RAW, ALINK_MESSAGE_INFO_HIGHRES_IMU, ALINK_MESSAGE_INFO_RAW_RTK, ALINK_MESSAGE_INFO_RAW_ACTUATOR_INFO, {"EMPTY",0,{{"","",ALINK_TYPE_CHAR,0,0,0}}}, ALINK_MESSAGE_INFO_RAW_GPS, ALINK_MESSAGE_INFO_RAW_BATTERY, ALINK_MESSAGE_INFO_RAW_IMU0, ALINK_MESSAGE_INFO_RAW_IMU1, ALINK_MESSAGE_INFO_RAW_BARO, ALINK_MESSAGE_INFO_RAW_MAG, ALINK_MESSAGE_INFO_RAW_VISION, ALINK_MESSAGE_INFO_RAW_OF, ALINK_MESSAGE_INFO_RC_CHANNELS_RAW, ALINK_MESSAGE_INFO_RAW_MAG1, {"EMPTY",0,{{"","",ALINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",ALINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",ALINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",ALINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",ALINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",ALINK_TYPE_CHAR,0,0,0}}}, ALINK_MESSAGE_INFO_ATTITUDE, ALINK_MESSAGE_INFO_LOCAL_POSITION_NED, ALINK_MESSAGE_INFO_MISSION_CURRENT, ALINK_MESSAGE_INFO_HOTPOINT_CURRENT, ALINK_MESSAGE_INFO_FOLLOWME_CURRENT, ALINK_MESSAGE_INFO_UAV_WORK_INFO, ALINK_MESSAGE_INFO_TARGET_INFO, ALINK_MESSAGE_INFO_GIMBAL_CMD_FCS, ALINK_MESSAGE_INFO_UAV_ATTI_DATA, ALINK_MESSAGE_INFO_SET_GIMBAL_ANGLES_SPEED, ALINK_MESSAGE_INFO_SET_GIMBAL_ANGLES, ALINK_MESSAGE_INFO_GET_GIMBAL_ANGLES_RANGE, ALINK_MESSAGE_INFO_GIMBAL_GPS_INFO, ALINK_MESSAGE_INFO_GIMBAL_NORMAL_CMD, ALINK_MESSAGE_INFO_PUSH_GIMBAL_LASER_MSG, ALINK_MESSAGE_INFO_PUSH_GIMBAL_ANGLES, ALINK_MESSAGE_INFO_GIMBAL_ACK, ALINK_MESSAGE_INFO_GIMBAL_CMD, ALINK_MESSAGE_INFO_GIMBAL_CAMERA_CALIBRATION_DATA, ALINK_MESSAGE_INFO_GIMBAL_CAMERA_CALIBRATION_DATA_COMMON, ALINK_MESSAGE_INFO_ESC_COMM_TYPE, ALINK_MESSAGE_INFO_ESC_STATE, {"EMPTY",0,{{"","",ALINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",ALINK_TYPE_CHAR,0,0,0}}}, ALINK_MESSAGE_INFO_MUTI_BAT_DATA, {"EMPTY",0,{{"","",ALINK_TYPE_CHAR,0,0,0}}}, ALINK_MESSAGE_INFO_BAT_AUTHEN, {"EMPTY",0,{{"","",ALINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",ALINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",ALINK_TYPE_CHAR,0,0,0}}}, ALINK_MESSAGE_INFO_VISION_ATTITUDE, ALINK_MESSAGE_INFO_VISION_NED_INFO, ALINK_MESSAGE_INFO_VISION_FLIGHT_STATUS, ALINK_MESSAGE_INFO_VISION_IMU_INFO, ALINK_MESSAGE_INFO_VISION_MAG_INFO, ALINK_MESSAGE_INFO_VISION_BARO_INFO, ALINK_MESSAGE_INFO_VISION_GPS_INFO, ALINK_MESSAGE_INFO_VISION_RC_INFO, {"EMPTY",0,{{"","",ALINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",ALINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",ALINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",ALINK_TYPE_CHAR,0,0,0}}}, ALINK_MESSAGE_INFO_ACTION_INFO, ALINK_MESSAGE_INFO_ORBIT_INFO, ALINK_MESSAGE_INFO_CYLINDER_INFO, ALINK_MESSAGE_INFO_PANORAMA_INFO, ALINK_MESSAGE_INFO_GPS_FOLLOW_SETTINGS, ALINK_MESSAGE_INFO_GPS_FOLLOW_TARGET, {"EMPTY",0,{{"","",ALINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",ALINK_TYPE_CHAR,0,0,0}}}, ALINK_MESSAGE_INFO_MISSION_INFO_FOR_DRAGFISH, ALINK_MESSAGE_INFO_WAYPOINT_INFO_FOR_DRAGFISH, ALINK_MESSAGE_INFO_CALIB_PROCESS_INFO, ALINK_MESSAGE_INFO_OBSTACLE_COLLISION_AVOIDANCE_INFO, ALINK_MESSAGE_INFO_ONLINE_PLANNING_INFO, {"EMPTY",0,{{"","",ALINK_TYPE_CHAR,0,0,0}}}, ALINK_MESSAGE_INFO_TRACKING_OUT, ALINK_MESSAGE_INFO_FLOW_FRAME, ALINK_MESSAGE_INFO_FCS_TRACK_CMD, ALINK_MESSAGE_INFO_TK1_POSE, ALINK_MESSAGE_INFO_CAMERA_FCS_OP, ALINK_MESSAGE_INFO_FCS_CAMERA_ACK, ALINK_MESSAGE_INFO_CAMERA_GIMBAL_OP, ALINK_MESSAGE_INFO_GIMBAL_CAMERA_ACK, ALINK_MESSAGE_INFO_CAMERA_COMMAND, ALINK_MESSAGE_INFO_CAMERA_RESPONSE, ALINK_MESSAGE_INFO_CAMERA_EVENT, ALINK_MESSAGE_INFO_CAMERA_CTRL_COMMAND, ALINK_MESSAGE_INFO_CAMERA_CTRL_RESPONSE, ALINK_MESSAGE_INFO_CAMERA_EVENT_MSG, ALINK_MESSAGE_INFO_ALINK_NORAML_MSG, ALINK_MESSAGE_INFO_CAMERA_UAV_INFO, ALINK_MESSAGE_INFO_MOVIDUS_VIO_REPORT, ALINK_MESSAGE_INFO_MOVIDUS_SOA_REPORT, ALINK_MESSAGE_INFO_MOVIDUS_GIMBAL_CONTROL, ALINK_MESSAGE_INFO_MOVIDUS_CONTROL_CMD, ALINK_MESSAGE_INFO_MOVIDUS_STATUS_REPORT, ALINK_MESSAGE_INFO_MOVIDUS_COMMAND, ALINK_MESSAGE_INFO_MOVIDUS_CALIBRATION, ALINK_MESSAGE_INFO_MOVIDUS_SETTINGS, ALINK_MESSAGE_INFO_MOVIDUS_HEARTBEAT, ALINK_MESSAGE_INFO_MOVIDUS_PATH_PLANNING_REPORT, ALINK_MESSAGE_INFO_MOVIDUS_SET_GOAL_AREA, ALINK_MESSAGE_INFO_MOVIDUS_REPORT_GOAL_AREA, ALINK_MESSAGE_INFO_MOVIDUS_REPORT_TRACK_STATUS, ALINK_MESSAGE_INFO_MOVIDUS_REPORT_TRACK_INFO, ALINK_MESSAGE_INFO_MOVIDUS_REPORT_LANDING_TARGET_INFO, ALINK_MESSAGE_INFO_FCS_TIMESYNC, ALINK_MESSAGE_INFO_RF_SIGNAL, ALINK_MESSAGE_INFO_RF_PAIR, ALINK_MESSAGE_INFO_RF_PAIR_RESP, ALINK_MESSAGE_INFO_RF_SYNC, ALINK_MESSAGE_INFO_RF_SYNC_RESP, ALINK_MESSAGE_INFO_RF_POWER, ALINK_MESSAGE_INFO_RF_POWER_RESP, ALINK_MESSAGE_INFO_RF_COMMON_CTRL_CMD, ALINK_MESSAGE_INFO_SRVESC_INFO, ALINK_MESSAGE_INFO_AIRSPEED, {"EMPTY",0,{{"","",ALINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",ALINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",ALINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",ALINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",ALINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",ALINK_TYPE_CHAR,0,0,0}}}, ALINK_MESSAGE_INFO_RC_KEY, ALINK_MESSAGE_INFO_GPS_DATA, ALINK_MESSAGE_INFO_MAG_DATA, ALINK_MESSAGE_INFO_RC_NORMAL_CMD, ALINK_MESSAGE_INFO_RC_CMD, ALINK_MESSAGE_INFO_CAMERA_STATUS, ALINK_MESSAGE_INFO_PHONE_SET, ALINK_MESSAGE_INFO_SYSTEM_BINDING, ALINK_MESSAGE_INFO_RC_CONTROL, {"EMPTY",0,{{"","",ALINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",ALINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",ALINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",ALINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",ALINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",ALINK_TYPE_CHAR,0,0,0}}}, ALINK_MESSAGE_INFO_RADAR_UAV_DATA, ALINK_MESSAGE_INFO_RADAR_DATA, ALINK_MESSAGE_INFO_SONAR_DATA, ALINK_MESSAGE_INFO_TOF_DATA, {"EMPTY",0,{{"","",ALINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",ALINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",ALINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",ALINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",ALINK_TYPE_CHAR,0,0,0}}}, ALINK_MESSAGE_INFO_RTK_SOL, ALINK_MESSAGE_INFO_RTK_LOCATION, ALINK_MESSAGE_INFO_RTK_STATE, ALINK_MESSAGE_INFO_RTK_SETTING, {"EMPTY",0,{{"","",ALINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",ALINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",ALINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",ALINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",ALINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",ALINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",ALINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",ALINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",ALINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",ALINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",ALINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",ALINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",ALINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",ALINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",ALINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",ALINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",ALINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",ALINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",ALINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",ALINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",ALINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",ALINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",ALINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",ALINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",ALINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",ALINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",ALINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",ALINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",ALINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",ALINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",ALINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",ALINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",ALINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",ALINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",ALINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",ALINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",ALINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",ALINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",ALINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",ALINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",ALINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",ALINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",ALINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",ALINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",ALINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",ALINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",ALINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",ALINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",ALINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",ALINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",ALINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",ALINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",ALINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",ALINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",ALINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",ALINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",ALINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",ALINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",ALINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",ALINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",ALINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",ALINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",ALINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",ALINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",ALINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",ALINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",ALINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",ALINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",ALINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",ALINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",ALINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",ALINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",ALINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",ALINK_TYPE_CHAR,0,0,0}}}, ALINK_MESSAGE_INFO_ADSB_VEHICLE, {"EMPTY",0,{{"","",ALINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",ALINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",ALINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",ALINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",ALINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",ALINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",ALINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",ALINK_TYPE_CHAR,0,0,0}}}, {"EMPTY",0,{{"","",ALINK_TYPE_CHAR,0,0,0}}}}
#endif

#include "../protocol.h"

#define ALINK_ENABLED_XSTAR_2_0

// ENUM DEFINITIONS


/** @brief  */
#ifndef HAVE_ENUM_MAV_VERSION
#define HAVE_ENUM_MAV_VERSION
typedef enum MAV_VERSION
{
	MAV_VERSION_RELEASE=17563656, /* 
                    Release version of this protocol : V1.13.1.2
                    Support various cameras / visca change to sensorchip
                     | */
	MAV_VERSION_ENUM_END=17563657, /*  | */
} MAV_VERSION;
#endif

/** @brief  */
#ifndef HAVE_ENUM_MAV_TYPE
#define HAVE_ENUM_MAV_TYPE
typedef enum MAV_TYPE
{
	MAV_TYPE_XSTAR2_0=0, /* Generic micro air vehicle. | */
	MAV_TYPE_GEN2=1, /* Generic 2nd micro air vehicle. | */
	MAV_TYPE_DG_5TOL=2, /* Dragon fish 5 VTOL vehicle. | */
	MAV_TYPE_DG_7_5TOL=3, /* Dragon fish 7.5 VTOL vehicle. | */
	MAV_TYPE_DG_15TOL=4, /* Dragon fish 15 VTOL vehicle. | */
	MAV_TYPE_DG_30TOL=5, /* Dragon fish 30 VTOL vehicle. | */
	MAV_TYPE_ENUM_END=6, /*  | */
} MAV_TYPE;
#endif

/** @brief  */
#ifndef HAVE_ENUM_MAV_COMPONENT
#define HAVE_ENUM_MAV_COMPONENT
typedef enum MAV_COMPONENT
{
	DEV_NONE=0, /*  | */
	DEV_UAV=1, /*  | */
	DEV_DSP=2, /*  | */
	DEV_DSP_RC=3, /*  | */
	DEV_RC_PLAYER=4, /*  | */
	DEV_BASESTATION=5, /*  | */
	DEV_ESC_PITCH=7, /*  | */
	DEV_ESC_ROLL=8, /*  | */
	DEV_ESC_YAW=9, /*  | */
	DEV_BATTERY=10, /*  | */
	DEV_GIMBAL=11, /*  | */
	DEV_TOF=12, /*  | */
	DEV_RC_ANDROID=13, /*  | */
	DEV_RC=14, /*  | */
	DEV_SONAR=15, /*  | */
	DEV_RADAR=16, /*  | */
	DEV_ESC1=20, /*  | */
	DEV_ESC2=21, /*  | */
	DEV_ESC3=22, /*  | */
	DEV_ESC4=23, /*  | */
	DEV_SWITCHER=24, /*  | */
	DEV_MOVIDIUS_1=25, /*  | */
	DEV_MOVIDIUS_2=26, /*  | */
	DEV_MOVIDIUS_3=27, /*  | */
	DEV_PC=28, /*  | */
	DEV_APP=32, /*  | */
	DEV_CAMERA=33, /*  | */
	DEV_SRVESC1=34, /*  | */
	DEV_SRVESC2=35, /*  | */
	DEV_SRVESC3=36, /*  | */
	DEV_SRVESC4=37, /*  | */
	DEV_CHARGE_HUB=38, /*  | */
	DEV_BATTERY_HUB=39, /*  | */
	DEV_TRACE_ANTENNA=40, /*  | */
	DEV_RF58G_A=41, /*  | */
	DEV_RF58G_G=42, /*  | */
	DEV_AIRSPEED=43, /*  | */
	DEV_DSP_STATION=44, /*  | */
	DEV_GPS=60, /*  | */
	DEV_ADSB=252, /*  | */
	DEV_MULTICAST=254, /*  | */
	DEV_BROADCAST=255, /*  | */
	MAV_COMPONENT_ENUM_END=256, /*  | */
} MAV_COMPONENT;
#endif

/** @brief  */
#ifndef HAVE_ENUM_MAV_CMD
#define HAVE_ENUM_MAV_CMD
typedef enum MAV_CMD
{
	MAV_CMD_NAV_LAND=0, /* Land at location | */
	MAV_CMD_NAV_TAKEOFF=1, /* Takeoff from ground / hand | */
	MAV_CMD_NAV_ARM_DISARM=2, /* Arms / Disarms a component |1 to arm, 0 to disarm|  */
	MAV_CMD_DO_SET_HOME=3, /* Changes the home location either to the current location or a specified location. |Use current (1=use current location, 0=use specified location)| Latitude| Longitude| Altitude|  */
	MAV_CMD_DO_PAUSE_CONTINUE=4, /* If in a GPS controlled position mode, hold the current position or continue. |0: Pause current mission or reposition command, hold current position. 1: Continue mission. A VTOL capable vehicle should enter hover mode (multicopter and VTOL planes). A plane should loiter with the default loiter radius.|  */
	MAV_CMD_GO_HOME=5, /* Enable go home mode for the vehicle. | */
	MAV_CMD_MAG_CALIBRATION=6, /* Enter magnet calibration. | */
	MAV_CMD_LANDINGGEAR=7, /* LandingGear ON/OFF. | */
	MAV_CMD_SAVE_PARAMETER=10, /* Save parameter to flash. | */
	MAV_CMD_WP_START=20, /* start to waypoint mission. | */
	MAV_CMD_WP_END=21, /* end waypoint mission. | */
	MAV_CMD_FM_START=22, /* start to followme mission. | */
	MAV_CMD_FM_END=23, /* end followme mission. | */
	MAV_CMD_OB_START=24, /* start to orbit mission. | */
	MAV_CMD_OB_END=25, /* end orbit mission. | */
	MAV_CMD_FOLLOW=26, /* Vehicle following, i.e. this waypoint represents the position of a moving vehicle |Following logic to use (e.g. loitering or sinusoidal following) - depends on specific autopilot implementation| Ground speed of vehicle to be followed| Radius around MISSION, in meters. If positive loiter clockwise, else counter-clockwise| Desired yaw angle.| Latitude| Longitude| Altitude|  */
	MAV_CMD_DO_FOLLOW_TARGET=27, /* Reposition the MAV after a follow target command has been sent |Camera q1 (where 0 is on the ray from the camera to the tracking device)| Camera q2| Camera q3| Camera q4| altitude offset from target (m)| X offset from target (m)| Y offset from target (m)|  */
	MAV_CMD_ENTERY_UPGRADE=252, /* Request enter or exit upgrade mode. |1: ENTERY upgrade mode, 0: Exit upgrade mode.|  */
	MAV_CMD_DO_REBOOT=253, /* Request the reboot or shutdown of system components. |0: Do nothing for autopilot, 1: Reboot autopilot to start usb storage mode, 2: Reboot autopilot and keep it in the bootloader until upgraded.|  */
	MAV_CMD_SET_DEBUG=254, /* Enable device to debug mod. | */
	MAV_CMD_ENUM_END=255, /*  | */
} MAV_CMD;
#endif

/** @brief  */
#ifndef HAVE_ENUM_NAV_CMD
#define HAVE_ENUM_NAV_CMD
typedef enum NAV_CMD
{
	NAV_CMD_NONE=0, /* Do nothing | */
	NAV_CMD_CALIBRATION_COMPASS=1, /* Calibration compass | */
	NAV_CMD_TAKE_OFF=2, /* Take off | */
	NAV_CMD_AUTO_LAND=3, /* Auto land / cancel auto land. |1 to cancel, 0 to auto land|  */
	NAV_CMD_ARM_DISARM=4, /* Arms / Disarms a component |1 to arm, 0 to disarm|  */
	NAV_CMD_GO_HOME=5, /* Enable go home mode for the vehicle. |1 to cancel, 0 to go home|  */
	NAV_CMD_LIGHT_CONTROL=6, /* Light control. |bit0: head light ; bit1: real light, 0 - off 1 - on|  */
	NAV_CMD_SET_HOME=7, /* Changes the home location either to the current location or a specified location. |Use current (0=use current location, 1=use specified location)| Latitude| Longitude| Altitude|  */
	NAV_CMD_ENABLE_USB=8, /* Enable usb port. |1 to enable, 0 to disable|  */
	NAV_CMD_BATTERY_INFO=9, /* query battery information. | */
	NAV_CMD_SET_BATTERY_DISCHARGE=10, /* Set battery discharge days. |battery discharge days, [1,10]|  */
	NAV_CMD_QUERY_LIGHT_STATUS=11, /* query light status. | */
	NAV_CMD_CLEAN_BATTERY_RECYCLE=12, /* Clean battery recycle . | */
	NAV_CMD_MISSION=13, /* Mission commands. |0 - require data, 1 - data sucessful, 2 - clean data,
                                     3 - start mission, 4 - stop mission, 5 - pause mission,
                                     6 - continue mission, 7 - send mission data complete |  */
	NAV_CMD_ENTER_UPGRADE=14, /* enter upgrade. |0 to enter, 1 to cancel |  */
	NAV_CMD_REQUIRE_DATA=16, /* Require mission data. |0 - all data
                                     1 - mission data
                                     2 - waypoint data
                                     3 - action data
                                     4 - orbit data
                                     5 - cylinder data
                                     6 - panorama data | index of waypoint/orbit/cylinder/panorama data | index of action data |  */
	NAV_CMD_DATA_COMPLETE=17, /* Mission data synchronzation complete. | */
	NAV_CMD_DATA_SUCCESS=18, /* Sucessfully get mission data. |0 - all mission data
                                     1 - single orbit data
                                     2 - GPS follow settings data
                                     3 - GPS target information data |  */
	NAV_CMD_CLEAN_DATA=19, /* Clean mission data. | */
	NAV_CMD_START_MISSION=20, /* Start mission commands. |0 - none
                                     1 - waypoint mission
                                     2 - orbit mission
                                     3 - GPS follow mission |  */
	NAV_CMD_STOP_MISSION=21, /* Stop current mission commands. | */
	NAV_CMD_PAUSE_MISSION=22, /* Pause current mission commands. | */
	NAV_CMD_CONTINUE_MISSION=23, /* Continue current mission commands. | */
	MAV_CMD_NAV_FORCE_TAKEOFF=24, /* Force takeoff commands. | */
	MAV_CMD_NAV_GET_TAKEOFF=25, /* Get the status of takeoff command. | */
	NAV_CMD_CALIBRATION_AIRSPEED=32, /* Calibration airspeed. | */
	NAV_CMD_GET_AIRSPD_CALIB_DATA=33, /* Get airspeed calibration data. | */
	NAV_CMD_GET_MAG_CALIB_DATA=34, /* Get mag calibration data. | */
	MAV_CMD_GET_MULTIBATTERY_INFO=48, /* MAV_CMD_GET_MULTIBATTERY_INFO | */
	MAV_CMD_SET_MULTIBATTERY_DISCHARGEDAYS=49, /* SET_MULTIBATTERY_DISCHARGEDAYS | */
	MAV_CMD_GET_MULTIBATTERY_VERSION=50, /* GET MULTIBATTERY VERSION. | */
	MAV_CMD_GET_MULTIBATTERY_SN=51, /* GET MULTIBATTERY SN. | */
	MAV_CMD_GET_INS_IO_VERSION=52, /* GET INS and IO VERSION. | */
	MAV_CMD_GET_ESC_WORK_TIME=53, /* SET Power System Work Time. | */
	MAV_CMD_RESET_ESC_WORK_TIME=54, /* Reset Power System Work Time. | */
	MAV_CMD_SET_GIMBAL_ANGLE=55, /* SET Gimbal Angle. | */
	MAV_CMD_START_AUTO_CHECK=64, /* start auto check. | */
	MAV_CMD_GET_CHECK_RESULT=65, /* get auto check results. | */
	MAV_CMD_FLYMODE_SWITCH=80, /* fly mode swtich. | */
	MAV_CMD_SYSTEM_ACTIVATE=81, /* System device activate. | */
	MAV_CMD_BUZZER=82, /* System Buzzer. | */
	MAV_CMD_MC_TAKEOFF=83, /* MC FAST TAKEOFF. | */
	MAV_CMD_MC_LANDING=84, /* MC FAST LANDING. | */
	MAV_CMD_SYSTEM_NET_STATUS=85, /* System Net Status. | */
	MAV_CMD_FORCED_LAND=86, /* Forced land. | */
	MAV_CMD_VISION_AIDED_LAND=87, /* Vision aided land. | */
	MAV_CMD_UPDATE_FILE=88, /* Updating File finished. | */
	MAV_CMD_ADSB_CMD_SET_ICAO=89, /* Tx: 32-bit parameter for ICAO | */
	MAV_CMD_ADSB_CMD_GET_ICAO=90, /* Rx: 32-bit parameter in common command ack message. | */
	MAV_CMD_ADSB_CMD_ENABLE_TX=91, /* Tx: 32-bit Enable/Disable ADSB Broadcast message. | */
	MAV_CMD_VISION_TRACKING_STOP=92, /* Stop Vision tracking function. | */
	MAV_CMD_AIRCRAFT_TRACKING=93, /* Enable Aircraft intellgent tracking mode. | */
	MAV_CMD_TEMP_SURVEY=94, /* Enable and disable the temp survey function.  | */
	MAV_CMD_EMERGENCY_MODE=95, /* Enable the emergency mode.  | */
	MAV_CMD_SWITCH_WAYPOINT=96, /* switch waypoint.  | */
	MAV_CMD_PULL_BAT_INFO=97, /* pull battery all static info.  | */
	NAV_CMD_ENUM_END=98, /*  | */
} NAV_CMD;
#endif

/** @brief Specifies the datatype of a MAVLink parameter. */
#ifndef HAVE_ENUM_MAV_PARAM_TYPE
#define HAVE_ENUM_MAV_PARAM_TYPE
typedef enum MAV_PARAM_TYPE
{
	MAV_PARAM_TYPE_UINT8=1, /* 8-bit unsigned integer | */
	MAV_PARAM_TYPE_INT8=2, /* 8-bit signed integer | */
	MAV_PARAM_TYPE_UINT16=3, /* 16-bit unsigned integer | */
	MAV_PARAM_TYPE_INT16=4, /* 16-bit signed integer | */
	MAV_PARAM_TYPE_UINT32=5, /* 32-bit unsigned integer | */
	MAV_PARAM_TYPE_INT32=6, /* 32-bit signed integer | */
	MAV_PARAM_TYPE_UINT64=7, /* 64-bit unsigned integer | */
	MAV_PARAM_TYPE_INT64=8, /* 64-bit signed integer | */
	MAV_PARAM_TYPE_REAL32=9, /* 32-bit floating-point | */
	MAV_PARAM_TYPE_REAL64=10, /* 64-bit floating-point | */
	MAV_PARAM_TYPE_ENUM_END=11, /*  | */
} MAV_PARAM_TYPE;
#endif

/** @brief result from a mavlink command */
#ifndef HAVE_ENUM_MAV_RESULT
#define HAVE_ENUM_MAV_RESULT
typedef enum MAV_RESULT
{
	MAV_RESULT_ACCEPTED=0, /* Command ACCEPTED and EXECUTED | */
	MAV_RESULT_TEMPORARILY_REJECTED=1, /* Command TEMPORARY REJECTED/DENIED | */
	MAV_RESULT_DENIED=2, /* Command PERMANENTLY DENIED | */
	MAV_RESULT_UNSUPPORTED=3, /* Command UNKNOWN/UNSUPPORTED | */
	MAV_RESULT_FAILED=4, /* Command executed, but failed | */
	MAV_RESULT_ENUM_END=5, /*  | */
} MAV_RESULT;
#endif

/** @brief mission type */
#ifndef HAVE_ENUM_MISSION_TYPE
#define HAVE_ENUM_MISSION_TYPE
typedef enum MISSION_TYPE
{
	MISSION_TYPE_None=0, /* Invalid mission type | */
	MISSION_TYPE_Waypoint=1, /* Waypoint mission type | */
	MISSION_TYPE_Orbit=2, /* Orbit mission type | */
	MISSION_TYPE_Cylinder=3, /* Cylinder mission type | */
	MISSION_TYPE_Panorama=4, /* Panorama mission type | */
	MISSION_TYPE_GPS_Follow=5, /* GPS_Follow mission type | */
	MISSION_TYPE_Mapping_Rectangle=6, /* DrawPoint mission type rectangle | */
	MISSION_TYPE_Mapping_Polygon=7, /* DrawPoint mission type polygon | */
	MISSION_TYPE_ENUM_END=8, /*  | */
} MISSION_TYPE;
#endif

/** @brief waypoint type */
#ifndef HAVE_ENUM_WAYPOINT_TYPE
#define HAVE_ENUM_WAYPOINT_TYPE
typedef enum WAYPOINT_TYPE
{
	WAYPOINT_TYPE_Normal=0, /* Normal waypoint type | */
	WAYPOINT_TYPE_Orbit=1, /* Orbit waypoint type | */
	WAYPOINT_TYPE_Cylinder=2, /* Cylinder waypoint type | */
	WAYPOINT_TYPE_Panorama=3, /* Panorama waypoint type | */
	WAYPOINT_TYPE_TakeOff=4, /* TakeOff waypoint type | */
	WAYPOINT_TYPE_LoiterTime=5, /* LoiterTime waypoint type | */
	WAYPOINT_TYPE_LoiterTurns=6, /* LoiterTurns waypoint type | */
	WAYPOINT_TYPE_Landing=7, /* Landing waypoint type | */
	WAYPOINT_TYPE_Interest=8, /* Interest waypoint type | */
	WAYPOINT_TYPE_Mapping=9, /* Mapping waypoint type | */
	WAYPOINT_TYPE_Emergency=10, /* Emergency waypoint type | */
	WAYPOINT_TYPE_HOME=11, /* Home waypoint type | */
	WAYPOINT_TYPE_ENUM_END=12, /*  | */
} WAYPOINT_TYPE;
#endif

/** @brief mission data type */
#ifndef HAVE_ENUM_MISSION_DATA_TYPE
#define HAVE_ENUM_MISSION_DATA_TYPE
typedef enum MISSION_DATA_TYPE
{
	MISSION_DATA_None=0, /* Invalid mission type | */
	MISSION_DATA_AllInfo=1, /* All mission info | */
	MISSION_DATA_MissionInfo=2, /* Mission mission info | */
	MISSION_DATA_WaypointInfo=3, /* Waypoint mission info | */
	MISSION_DATA_ActionInfo=4, /* Action mission info | */
	MISSION_DATA_OrbitInfo=5, /* Orbit mission info | */
	MISSION_DATA_CylinderInfo=6, /* Cylinder mission info | */
	MISSION_DATA_PanoramaInfo=7, /* Panorama mission info | */
	MISSION_DATA_TYPE_ENUM_END=8, /*  | */
} MISSION_DATA_TYPE;
#endif

/** @brief System commands */
#ifndef HAVE_ENUM_MAV_SYSTEM_CMD
#define HAVE_ENUM_MAV_SYSTEM_CMD
typedef enum MAV_SYSTEM_CMD
{
	MAV_SYSTEM_CMD_HEARTBEAT=208, /* Heartbeat | */
	MAV_SYSTEM_CMD_RESET=209, /* Reset the target system | */
	MAV_SYSTEM_CMD_FACTORY_RESET=210, /* Factory reset the component | */
	MAV_SYSTEM_CMD_SET_SN=212, /* Set the serial number. | */
	MAV_SYSTEM_CMD_GET_SN=213, /* Get the serial number. | */
	MAV_SYSTEM_CMD_GET_APP_FLASH_SIZE=214, /* Get the application usable flash size. | */
	MAV_SYSTEM_CMD_REQUEST_UPGRADE=215, /* Request to upgrade. | */
	MAV_SYSTEM_CMD_ERASE_APP_FLASH=216, /* Erasing the application flash. | */
	MAV_SYSTEM_CMD_DOWNLOADING=217, /* Downloading firmware data. | */
	MAV_SYSTEM_CMD_SET_HW_VERSION=218, /* Set the hardware version. | */
	MAV_SYSTEM_CMD_GET_VERSIONS=219, /* Get the all versions. | */
	MAV_SYSTEM_CMD_CRC_CHECK=220, /* Check the application CRC32 value. | */
	MAV_SYSTEM_CMD_APP_GO=221, /* Running application. | */
	MAV_SYSTEM_CMD_GET_TIMEOUT_RETRYTIMES=222, /* Get timeout times and Retry times. | */
	MAV_SYSTEM_CMD_QUERY_DEVICE=224, /* Query device device status. | */
	MAV_SYSTEM_CMD_REPORT_LOG=229, /* Report system log. | */
	MAV_SYSTEM_CMD_DEBUG_DEVICE=230, /* Debug the device. | */
	MAV_SYSTEM_CMD_SUBSCRIBE_MESSAGE=231, /* Subscribe message. | */
	MAV_SYSTEM_CMD_USER_STRING=232, /* Set printable string. | */
	MAV_SYSTEM_CMD_SEND_FILE_DETAIL=240, /* Send file detail. | */
	MAV_SYSTEM_CMD_SEND_FILE_DATA=241, /* send file data. | */
	MAV_SYSTEM_CMD_QUERY_FILE_EXIST=242, /* Query file exist? | */
	MAV_SYSTEM_CMD_ENUM_END=243, /*  | */
} MAV_SYSTEM_CMD;
#endif

/** @brief System commands */
#ifndef HAVE_ENUM_MAV_DEBUG_CMD
#define HAVE_ENUM_MAV_DEBUG_CMD
typedef enum MAV_DEBUG_CMD
{
	MAV_DEBUG_CMD_ECHO=0, /* Reply with received | */
	MAV_DEBUG_CMD_TIME_SYNC=1, /* Time synchronization | */
	MAV_DEBUG_CMD_SET_LOOPBACK=2, /* Set message loopback. | */
	MAV_DEBUG_CMD_CLEAR_STATISTICS=3, /* Clear all statistics | */
	MAV_DEBUG_CMD_GET_RX_BYTES=4, /* Get all received bytes. | */
	MAV_DEBUG_CMD_GET_RX_FRAMES=5, /* Get all received frames. | */
	MAV_DEBUG_CMD_GET_RX_MESSAGES=6, /* Get all received messages. | */
	MAV_DEBUG_CMD_GET_RX_CRC_FAILS=7, /* Get all received crc failures. | */
	MAV_DEBUG_CMD_GET_RX_LENGTH_FAILS=8, /* Get all received length failures. | */
	MAV_DEBUG_CMD_GET_RX_INVALID_FAILS=9, /* Get all received invalid failures. | */
	MAV_DEBUG_CMD_GET_RX_NO_BUF_FAILS=10, /* Get all received no buffer failures. | */
	MAV_DEBUG_CMD_GET_RX_DUP_SEQ_FAILS=11, /* Get all received dup sequence failures. | */
	MAV_DEBUG_CMD_GET_TX_BYTES=12, /* Get all send bytes. | */
	MAV_DEBUG_CMD_GET_TX_FRAMES=13, /* Get all send frames. | */
	MAV_DEBUG_CMD_GET_TX_MESSAGES=14, /* Get all send messages. | */
	MAV_DEBUG_CMD_GET_TX_FAILS=15, /* Get all send failures. | */
	MAV_DEBUG_CMD_GET_TX_NO_BUF_FAILS=16, /* Get all send no buffer failures. | */
	MAV_DEBUG_CMD_GET_TX_RETRY_FAILS=17, /* Get all send retry failures | */
	MAV_DEBUG_CMD_GET_HANDLE_FAILS=18, /* Get all handle failures | */
	MAV_DEBUG_CMD_GET_RELAYED_MESSAGES=19, /* Get all relayed messages | */
	MAV_DEBUG_CMD_GET_RELAYED_FAILS=20, /* Get all relayed failures. | */
	MAV_DEBUG_CMD_GET_CPU_USAGES=32, /* Get cpu usages. | */
	MAV_DEBUG_CMD_GET_MEM_USAGES=33, /* Get memory usages. | */
	MAV_DEBUG_CMD_ENUM_END=34, /*  | */
} MAV_DEBUG_CMD;
#endif

/** @brief  */
#ifndef HAVE_ENUM_MOV_CMD
#define HAVE_ENUM_MOV_CMD
typedef enum MOV_CMD
{
	MOV_CMD_GET_SETTINGS=0, /* Get movidus settings | */
	MOV_CMD_ENABLE_iFLY=1, /* Enable/Disable iFLY |1 to enable, 0 to disable|  */
	MOV_CMD_iFLY_SPEEDLIMIT=2, /* Speed limit under iFLY mode |speed limit in m/s|  */
	MOV_CMD_PointFLY_OA_TYPE=3, /* Obstacle avoidance under point fly |1 to left/right avoidance, 0 to other action|  */
	MOV_CMD_FollowMe_OA_ENABLE=4, /* Obstacle avoidance under follow me |1 to enable, 0 to disable|  */
	MOV_CMD_SOA_DISPLAY_ENABLE=5, /* Display SOA information or not |1 to turn on display, 0 to turn off display|  */
	MOV_CMD_FollowMe_BACKOFF_ENABLE=6, /* If allow backoff under followme mode. |0: not allow. 1: allow.|  */
	MOV_CMD_LANDING_PROTECTION_ENABLE=7, /* Enable landing protection. |1 to enable, 0 to disable|  */
	MOV_CMD_RTH_OA_ENABLE=8, /* Enable obstacle avoidance when RTH . |1 to enable, 0 to disable|  */
	MOV_CMD_VIO_ENABLE=9, /* Enable VIO stablization. |1 to enable, 0 to disable|  */
	MOV_CMD_PRECISE_RTH_ENABLE=10, /* Enable RTH precisely. |1 to enable, 0 to disable|  */
	MOV_CMD_SET_PointFLY_WP=11, /* Set point fly parameters. |Angle of target and UAV heading|  */
	MOV_CMD_SET_PointFLY_SPEED=12, /* Set point fly speed. |speed in m/s|  */
	MOV_CMD_PointFLY_START=13, /* start to point fly mission. |1 to start, 0 to stop|  */
	MOV_CMD_TERRAIN_FOLLOW_ENABLE=14, /* Enable terrain follow. |1 to enable, 0 to disable|  */
	MOV_CMD_SET_FollowMe_MODE=15, /* Set follow me mode. |0 to none, 1 to fix mode , 2 to lock mode , 3 to parallel mode|  */
	MOV_CMD_TRIPOD_MODE_ENABLE=16, /* Enable tripod mode. |1 to enable, 0 to disable|  */
	MOV_CMD_CINEMA_MODE_ENABLE=17, /* Enable cinema mode. |1 to enable, 0 to disable|  */
	MOV_CMD_FIXWING_MODE_ENABLE=18, /* Enable fix wing mode. |1 to enable, 0 to disable|  */
	MOV_CMD_GESTURE_RECOGNIZATION_ENABLE=19, /* Enable gesture recognization mode. |1 to enable, 0 to disable|  */
	MOV_CMD_VISION_CALIBRATION=20, /* Start/stop vision calibration. |1 to start, 0 to stop|  */
	MOV_CMD_SET_PointFLY_INSIDE=21, /* Set pointfly inside. |1 to inside, 0 to outside |  */
	MOV_CMD_ENUM_END=22, /*  | */
} MOV_CMD;
#endif

/** @brief  */
#ifndef HAVE_ENUM_GIMBAL_CMD
#define HAVE_ENUM_GIMBAL_CMD
typedef enum GIMBAL_CMD
{
	GIMBAL_CMD_NONE=0, /* Null command | */
	GIMBAL_CMD_GET_ANGLE_INFO=1, /* Get current angle or angle speed of Roll/Pitch/Yaw | */
	GIMBAL_CMD_GET_RANGE_INFO=2, /* Get range of Roll/Pitch/Yaw | */
	GIMBAL_CMD_GET_WORKMODE=3, /* Get current workmode | */
	GIMBAL_CMD_SET_WORKMODE=4, /* Set workmode |0 - idle, 1 - attitude-lock, 2 - Yaw-follow, 3 - FPV mode, 4 - Panorama mode|  */
	GIMBAL_CMD_SET_ROLL_ADJUSTMENT=5, /* Set roll adjustment |[-1000, +1000] => [-10 deg, +10 deg], step 10E-2 deg|  */
	GIMBAL_CMD_GET_ROLL_ADJUSTMENT=6, /* Get roll adjustment. | */
	GIMBAL_CMD_RESET_ANGLE=7, /* Reset angle. |0 to ignore, 1 to reset roll | 0 to ignore, 1 to reset pitch | 0 to ignore, 1 to reset yaw |  */
	GIMBAL_CMD_SET_ANGLE_MAX=8, /* Reset angle. |0 to ignore, 1 to set maximum roll | 0 to ignore, 1 to set maximum pitch | 0 to ignore, 1 to set maximum yaw |  */
	GIMBAL_CMD_SET_ANGLE_MIN=9, /* Reset angle. |0 to ignore, 1 to set minimum roll | 0 to ignore, 1 to set minimum pitch | 0 to ignore, 1 to set minimum yaw |  */
	GIMBAL_CMD_ENUM_END=10, /*  | */
} GIMBAL_CMD;
#endif

/** @brief  */
#ifndef HAVE_ENUM_RC_CMD
#define HAVE_ENUM_RC_CMD
typedef enum RC_CMD
{
	RC_CMD_NONE=0, /* Null command | */
	RC_CMD_SET_GIMBAL_SPEED=1, /* Set gimbal speed |gimbal speed value from 0 to 100, when response 0 - success, 1 failure |  */
	RC_CMD_GET_GIMBAL_SPEED=2, /* Get gimbal speed |current gimbal speed value from 0 to 100 |  */
	RC_CMD_SET_LANGUAGE=3, /* Set language |Set language, 0 - English 1 - Chinese , when response 0 - success, 1 failure |  */
	RC_CMD_GET_LANGUAGE=4, /* Get language |Current language| Number of supported languages| Supported languages list|  */
	RC_CMD_SET_ROLE=9, /* Set role of the RC |0 - None, 1 - Master, 2 - Newbie , when response 0 - success, 1 failure |  */
	RC_CMD_GET_ROLE=10, /* Get role of the RC |0 - None, 1 - Master, 2 - Newbie , when response 0 - success, 1 failure |  */
	RC_CMD_SET_GIMBAL_PITCH=11, /* Set gimbal pitch settings |[-100, 100]: the * of pitch, [110, 200] the range of pitch , equals [0,90] deg , when response return between [110, 200] |  */
	RC_CMD_GET_GIMBAL=12, /* Get gimbal angles. |4B pitch angle value| 4B yaw angle value|  */
	RC_CMD_CALIBRATION=13, /* RC calibration. | 0 - exit calibration, 1 - enter calibration, 2 - set middle, 3 - set range |  when response 0 - success, 1 failure  |  */
	RC_CMD_RAW_DATA=14, /* Get raw data. |1 to enable, 0 to disable. when response , return raw data of 9 channels total 18B every 100ms |  */
	RC_CMD_GET_STATUS=15, /* Get RC battery / signal status etc . report every seconds |RC battery percentage [0, 100], 0xFF means not availabe| not used | signal strength| calibration status|  */
	RC_CMD_GET_VERSION=16, /* Get rc version. |not used|  */
	RC_CMD_SET_STYLE=17, /* Set display style: kilometers vs miles , setting every seconds until RC responses . |1 to miles, 0 to kilometers|  */
	RC_CMD_SET_MODE=18, /* Set mode of RC. |0 - American, 1 - Chinese, 2 - Japanese, when response 0 - success, 1 failure|  */
	RC_CMD_GET_MODE=19, /* Get mode of RC. |0 - American, 1 - Chinese, 2 - Japanese|  */
	RC_CMD_GET_STYLE=20, /* Get display style: kilometers vs miles  |1 to miles, 0 to kilometers|  */
	RC_CMD_SET_PHONE_COMPASS_ANGLE=22, /* Set phone compass angle. every 100 ms |2B [0, 360]|  */
	RC_CMD_SET_GIMBAL_YAW=24, /* Set gimbal yaw settings |[-100, 100]: the * of yaw, [110, 650] the range of pitch , equals [-270,270] deg|  */
	RC_CMD_ENUM_END=25, /*  | */
} RC_CMD;
#endif

/** @brief Enumeration of the ADSB altimeter types */
#ifndef HAVE_ENUM_ADSB_ALTITUDE_TYPE
#define HAVE_ENUM_ADSB_ALTITUDE_TYPE
typedef enum ADSB_ALTITUDE_TYPE
{
	ADSB_ALTITUDE_TYPE_PRESSURE_QNH=0, /* Altitude reported from a Baro source using QNH reference | */
	ADSB_ALTITUDE_TYPE_GEOMETRIC=1, /* Altitude reported from a GNSS source | */
	ADSB_ALTITUDE_TYPE_ENUM_END=2, /*  | */
} ADSB_ALTITUDE_TYPE;
#endif

/** @brief ADSB classification for the type of vehicle emitting the transponder signal */
#ifndef HAVE_ENUM_ADSB_EMITTER_TYPE
#define HAVE_ENUM_ADSB_EMITTER_TYPE
typedef enum ADSB_EMITTER_TYPE
{
	ADSB_EMITTER_TYPE_NO_INFO=0, /*  | */
	ADSB_EMITTER_TYPE_LIGHT=1, /*  | */
	ADSB_EMITTER_TYPE_SMALL=2, /*  | */
	ADSB_EMITTER_TYPE_LARGE=3, /*  | */
	ADSB_EMITTER_TYPE_HIGH_VORTEX_LARGE=4, /*  | */
	ADSB_EMITTER_TYPE_HEAVY=5, /*  | */
	ADSB_EMITTER_TYPE_HIGHLY_MANUV=6, /*  | */
	ADSB_EMITTER_TYPE_ROTOCRAFT=7, /*  | */
	ADSB_EMITTER_TYPE_UNASSIGNED=8, /*  | */
	ADSB_EMITTER_TYPE_GLIDER=9, /*  | */
	ADSB_EMITTER_TYPE_LIGHTER_AIR=10, /*  | */
	ADSB_EMITTER_TYPE_PARACHUTE=11, /*  | */
	ADSB_EMITTER_TYPE_ULTRA_LIGHT=12, /*  | */
	ADSB_EMITTER_TYPE_UNASSIGNED2=13, /*  | */
	ADSB_EMITTER_TYPE_UAV=14, /*  | */
	ADSB_EMITTER_TYPE_SPACE=15, /*  | */
	ADSB_EMITTER_TYPE_UNASSGINED3=16, /*  | */
	ADSB_EMITTER_TYPE_EMERGENCY_SURFACE=17, /*  | */
	ADSB_EMITTER_TYPE_SERVICE_SURFACE=18, /*  | */
	ADSB_EMITTER_TYPE_POINT_OBSTACLE=19, /*  | */
	ADSB_EMITTER_TYPE_ENUM_END=20, /*  | */
} ADSB_EMITTER_TYPE;
#endif

/** @brief These flags indicate status such as data validity of each data source. Set = data valid */
#ifndef HAVE_ENUM_ADSB_FLAGS
#define HAVE_ENUM_ADSB_FLAGS
typedef enum ADSB_FLAGS
{
	ADSB_FLAGS_VALID_COORDS=1, /*  | */
	ADSB_FLAGS_VALID_ALTITUDE=2, /*  | */
	ADSB_FLAGS_VALID_HEADING=4, /*  | */
	ADSB_FLAGS_VALID_VELOCITY=8, /*  | */
	ADSB_FLAGS_VALID_CALLSIGN=16, /*  | */
	ADSB_FLAGS_VALID_SQUAWK=32, /*  | */
	ADSB_FLAGS_SIMULATED=64, /*  | */
	ADSB_FLAGS_VERTICAL_VELOCITY_VALID=128, /*  | */
	ADSB_FLAGS_BARO_VALID=256, /*  | */
	ADSB_FLAGS_SOURCE_UAT=32768, /*  | */
	ADSB_FLAGS_ENUM_END=32769, /*  | */
} ADSB_FLAGS;
#endif



// ALINK VERSION

#ifndef ALINK_VERSION
#define ALINK_VERSION 3
#endif

#if (ALINK_VERSION == 0)
#undef ALINK_VERSION
#define ALINK_VERSION 3
#endif

// MESSAGE DEFINITIONS
#include "./alink_msg_heartbeat.h"
#include "./alink_msg_sys_status.h"
#include "./alink_msg_command.h"
#include "./alink_msg_command_ack.h"
#include "./alink_msg_param_read.h"
#include "./alink_msg_param_request_list.h"
#include "./alink_msg_param_value.h"
#include "./alink_msg_param_set.h"
#include "./alink_msg_servo_output_raw.h"
#include "./alink_msg_highres_imu.h"
#include "./alink_msg_raw_rtk.h"
#include "./alink_msg_raw_actuator_info.h"
#include "./alink_msg_raw_gps.h"
#include "./alink_msg_raw_battery.h"
#include "./alink_msg_raw_imu0.h"
#include "./alink_msg_raw_imu1.h"
#include "./alink_msg_raw_baro.h"
#include "./alink_msg_raw_mag.h"
#include "./alink_msg_raw_vision.h"
#include "./alink_msg_raw_of.h"
#include "./alink_msg_rc_channels_raw.h"
#include "./alink_msg_raw_mag1.h"
#include "./alink_msg_attitude.h"
#include "./alink_msg_local_position_ned.h"
#include "./alink_msg_mission_current.h"
#include "./alink_msg_hotpoint_current.h"
#include "./alink_msg_followme_current.h"
#include "./alink_msg_uav_work_info.h"
#include "./alink_msg_target_info.h"
#include "./alink_msg_gimbal_cmd_fcs.h"
#include "./alink_msg_uav_atti_data.h"
#include "./alink_msg_set_gimbal_angles_speed.h"
#include "./alink_msg_set_gimbal_angles.h"
#include "./alink_msg_get_gimbal_angles_range.h"
#include "./alink_msg_gimbal_gps_info.h"
#include "./alink_msg_gimbal_normal_cmd.h"
#include "./alink_msg_push_gimbal_laser_msg.h"
#include "./alink_msg_push_gimbal_angles.h"
#include "./alink_msg_gimbal_ack.h"
#include "./alink_msg_gimbal_cmd.h"
#include "./alink_msg_gimbal_camera_calibration_data.h"
#include "./alink_msg_gimbal_camera_calibration_data_common.h"
#include "./alink_msg_esc_comm_type.h"
#include "./alink_msg_esc_state.h"
#include "./alink_msg_muti_bat_data.h"
#include "./alink_msg_bat_authen.h"
#include "./alink_msg_vision_attitude.h"
#include "./alink_msg_vision_ned_info.h"
#include "./alink_msg_vision_flight_status.h"
#include "./alink_msg_vision_imu_info.h"
#include "./alink_msg_vision_mag_info.h"
#include "./alink_msg_vision_baro_info.h"
#include "./alink_msg_vision_gps_info.h"
#include "./alink_msg_vision_rc_info.h"
#include "./alink_msg_mission_info_for_dragfish.h"
#include "./alink_msg_waypoint_info_for_dragfish.h"
#include "./alink_msg_calib_process_info.h"
#include "./alink_msg_action_info.h"
#include "./alink_msg_orbit_info.h"
#include "./alink_msg_cylinder_info.h"
#include "./alink_msg_panorama_info.h"
#include "./alink_msg_gps_follow_settings.h"
#include "./alink_msg_gps_follow_target.h"
#include "./alink_msg_tracking_out.h"
#include "./alink_msg_flow_frame.h"
#include "./alink_msg_fcs_track_cmd.h"
#include "./alink_msg_tk1_pose.h"
#include "./alink_msg_camera_fcs_op.h"
#include "./alink_msg_fcs_camera_ack.h"
#include "./alink_msg_camera_gimbal_op.h"
#include "./alink_msg_gimbal_camera_ack.h"
#include "./alink_msg_camera_command.h"
#include "./alink_msg_camera_response.h"
#include "./alink_msg_camera_event.h"
#include "./alink_msg_camera_ctrl_command.h"
#include "./alink_msg_camera_ctrl_response.h"
#include "./alink_msg_camera_event_msg.h"
#include "./alink_msg_alink_noraml_msg.h"
#include "./alink_msg_camera_uav_info.h"
#include "./alink_msg_movidus_vio_report.h"
#include "./alink_msg_movidus_soa_report.h"
#include "./alink_msg_movidus_gimbal_control.h"
#include "./alink_msg_movidus_control_cmd.h"
#include "./alink_msg_movidus_status_report.h"
#include "./alink_msg_movidus_command.h"
#include "./alink_msg_movidus_calibration.h"
#include "./alink_msg_movidus_settings.h"
#include "./alink_msg_movidus_heartbeat.h"
#include "./alink_msg_movidus_path_planning_report.h"
#include "./alink_msg_movidus_set_goal_area.h"
#include "./alink_msg_movidus_report_goal_area.h"
#include "./alink_msg_movidus_report_track_status.h"
#include "./alink_msg_movidus_report_track_info.h"
#include "./alink_msg_movidus_report_landing_target_info.h"
#include "./alink_msg_fcs_timesync.h"
#include "./alink_msg_obstacle_collision_avoidance_info.h"
#include "./alink_msg_online_planning_info.h"
#include "./alink_msg_rc_key.h"
#include "./alink_msg_mag_data.h"
#include "./alink_msg_rc_normal_cmd.h"
#include "./alink_msg_rc_cmd.h"
#include "./alink_msg_camera_status.h"
#include "./alink_msg_phone_set.h"
#include "./alink_msg_system_binding.h"
#include "./alink_msg_rc_control.h"
#include "./alink_msg_radar_uav_data.h"
#include "./alink_msg_radar_data.h"
#include "./alink_msg_sonar_data.h"
#include "./alink_msg_tof_data.h"
#include "./alink_msg_rtk_sol.h"
#include "./alink_msg_rtk_location.h"
#include "./alink_msg_rtk_state.h"
#include "./alink_msg_rtk_setting.h"
#include "./alink_msg_rf_signal.h"
#include "./alink_msg_rf_pair.h"
#include "./alink_msg_rf_pair_resp.h"
#include "./alink_msg_rf_sync.h"
#include "./alink_msg_rf_sync_resp.h"
#include "./alink_msg_rf_power.h"
#include "./alink_msg_rf_power_resp.h"
#include "./alink_msg_rf_common_ctrl_cmd.h"
#include "./alink_msg_srvesc_info.h"
#include "./alink_msg_airspeed.h"
#include "./alink_msg_gps_data.h"
#include "./alink_msg_adsb_vehicle.h"

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // ALINK_XSTAR_2_0_H
