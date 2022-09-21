#ifndef RTW_HEADER_xstar_fcs_h_
#define RTW_HEADER_xstar_fcs_h_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include <float.h>
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef xstar_fcs_COMMON_INCLUDES_
# define xstar_fcs_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#endif

#define Translation_Fusion_MDLREF_HIDE_CHILD_
#include "Translation_Fusion.h"
#define Rotation_AHRS_GPS_MDLREF_HIDE_CHILD_
#include "Rotation_AHRS_GPS.h"
#include "MW_target_hardware_resources.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"
#include "mw_cmsis.h"
#include "rt_assert.h"
#include "rt_defines.h"

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetErrorStatusPointer
# define rtmGetErrorStatusPointer(rtm) ((const char_T **)(&((rtm)->errorStatus)))
#endif

typedef struct tag_RTM_xstar_fcs_T RT_MODEL_xstar_fcs_T;

#ifndef DEFINED_TYPEDEF_FOR_IMU_Bus_
#define DEFINED_TYPEDEF_FOR_IMU_Bus_

typedef struct {
  int16_T gyro_x;
  int16_T gyro_y;
  int16_T gyro_z;
  int16_T acc_x;
  int16_T acc_y;
  int16_T acc_z;
  int16_T Temperature_deg;
  real32_T Timestamp_ms;
} IMU_Bus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_MS5611_Bus_
#define DEFINED_TYPEDEF_FOR_MS5611_Bus_

typedef struct {
  real32_T Pressure_Pa;
  real32_T Temperature_deg;
  real32_T Timestamp_ms;
} MS5611_Bus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_HMC5x83_Bus_
#define DEFINED_TYPEDEF_FOR_HMC5x83_Bus_

typedef struct {
  int16_T mag_x;
  int16_T mag_y;
  int16_T mag_z;
  int16_T Temperature_deg;
  real32_T Timestamp_ms;
} HMC5x83_Bus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_RTK_Base_Bus_
#define DEFINED_TYPEDEF_FOR_RTK_Base_Bus_

typedef struct {
  uint16_T pos_type;
  uint16_T sol_s_pos;
  real_T lat;
  real_T lon;
  real_T hgt;
  real32_T lat_stddev;
  real32_T lon_stddev;
  real32_T hgt_stddev;
  real32_T Timestamp_ms_pos;
  uint16_T vel_type;
  uint16_T sol_s_vel;
  real_T hor_spd;
  real_T trk_gnd;
  real_T vert_spd;
  real32_T Timestamp_ms_vel;
  real32_T Vx_stddev;
  real32_T Vy_stddev;
  real32_T Vz_stddev;
  uint16_T pos_type_hd;
  uint16_T sol_s_hd;
  real32_T heading;
  real32_T hdg_stddev;
  real32_T Timestamp_ms_hd;
} RTK_Base_Bus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_Vision_Bus_
#define DEFINED_TYPEDEF_FOR_Vision_Bus_

typedef struct {
  real32_T Timestamp_ms;
  int16_T delta_pos_x;
  int16_T delta_pos_y;
  int16_T delta_pos_z;
  int16_T vel_x;
  int16_T vel_y;
  int16_T vel_z;
  int16_T delta_q0;
  int16_T delta_q1;
  int16_T delta_q2;
  int16_T delta_q3;
  uint8_T confidence;
  uint32_T timestamp_v;
  uint16_T ground_distance_mm;
  uint32_T timestamp_s;
} Vision_Bus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_ESC_Bus_
#define DEFINED_TYPEDEF_FOR_ESC_Bus_

typedef struct {
  real32_T Timestamp_ms;
  uint8_T esc_channel;
  uint8_T esc_status;
  uint16_T rpm1;
  uint16_T rpm2;
  uint16_T rpm3;
  uint16_T rpm4;
} ESC_Bus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_Battery_Bus_
#define DEFINED_TYPEDEF_FOR_Battery_Bus_

typedef struct {
  uint32_T status;
  uint16_T Capacity;
  uint32_T Voltage;
  int32_T Current;
  int16_T Temperature;
  int16_T CycleCount;
  uint16_T DesignCap;
  uint16_T FullChgCap;
  uint16_T RSOC;
  int16_T Cell_1_V;
  int16_T Cell_2_V;
  int16_T Cell_3_V;
  int16_T Cell_4_V;
  int16_T Cell_5_V;
  int16_T Cell_6_V;
  int16_T Cell_7_V;
  int16_T Cell_8_V;
  real32_T Timestamp_ms;
} Battery_Bus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_RTKP_Bus_
#define DEFINED_TYPEDEF_FOR_RTKP_Bus_

typedef struct {
  real32_T timestamp_ms;
  uint32_T sol_status;
  uint32_T pos_type;
  real_T lat;
  real_T lon;
  real_T hgt;
  real32_T undulation;
  uint32_T datum_id;
  real32_T lat_sigma;
  real32_T lon_sigma;
  real32_T hgt_sigma;
  uint8_T stn_id0;
  uint8_T stn_id1;
  uint8_T stn_id2;
  uint8_T stn_id3;
  real32_T diff_age;
  real32_T sol_age;
  uint8_T SVs;
  uint8_T solnSVs;
  uint8_T ext_sol_stat;
  uint8_T sig_mask;
  boolean_T RTK_On_Hardware;
} RTKP_Bus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_RTKV_Bus_
#define DEFINED_TYPEDEF_FOR_RTKV_Bus_

typedef struct {
  real32_T timestamp_ms;
  uint32_T sol_status;
  uint32_T vel_type;
  real32_T latency;
  real32_T age;
  real_T hor_spd;
  real_T trk_gnd;
  real_T vert_spd;
  uint32_T vel_std;
} RTKV_Bus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_RTKH_Bus_
#define DEFINED_TYPEDEF_FOR_RTKH_Bus_

typedef struct {
  real32_T timestamp_ms;
  real32_T heading;
  real32_T length;
  real32_T hdgstddev;
  uint8_T sol_s;
  uint8_T pos_t;
} RTKH_Bus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_RTK_Bus_
#define DEFINED_TYPEDEF_FOR_RTK_Bus_

typedef struct {
  RTKP_Bus RTKP;
  RTKV_Bus RTKV;
  RTKH_Bus RTKH;
} RTK_Bus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_Sensors_Bus_
#define DEFINED_TYPEDEF_FOR_Sensors_Bus_

typedef struct {
  IMU_Bus MPU6500;
  IMU_Bus ICM20602;
  MS5611_Bus MS5611;
  HMC5x83_Bus HMC5x83;
  RTK_Base_Bus RTK_Base;
  Vision_Bus Vision;
  ESC_Bus ESC;
  Battery_Bus Battery;
  RTK_Bus RTK;
} Sensors_Bus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_alink_RTK_Bus_
#define DEFINED_TYPEDEF_FOR_alink_RTK_Bus_

typedef struct {
  int32_T latitude;
  int32_T longitude;
  int32_T altitude;
  int16_T vel_X_O;
  int16_T vel_Y_O;
  int16_T vel_Z_O;
  int16_T pitch;
  int16_T roll;
  int16_T yaw;
  int16_T yaw_rate;
  int16_T ant_heading;
  int16_T reserve;
  uint8_T pos_type;
  uint8_T pos_stat;
  uint8_T vel_type;
  uint8_T vel_stat;
} alink_RTK_Bus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_Translation_data_Bus_
#define DEFINED_TYPEDEF_FOR_Translation_data_Bus_

typedef struct {
  real32_T h_dot_mDs;
  real32_T h_AGL_m;
  real32_T h_0_AGL_m;
  real32_T delta_h_m;
  real32_T Bias_z_mDs2;
  real32_T VEL_xy_O_mDs[2];
  real32_T ACC_xy_O_mDs[2];
  real_T mue_est_rad;
  real_T lambda_est_rad;
  real32_T POS_xy_O_m[2];
  boolean_T POS_reset_signal;
  boolean_T GPS_Vel_Vaild;
  boolean_T VO_Vel_Valid;
  real_T mue_est_rad_fc;
  real_T lambda_est_rad_fc;
} Translation_data_Bus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_GPS_data_Bus_
#define DEFINED_TYPEDEF_FOR_GPS_data_Bus_

typedef struct {
  boolean_T GPS_reset;
  real32_T Spd_quality;
  real32_T Pos_quality;
  real32_T Status;
  real_T lambda_0_WGS84_rad;
  real_T mue_0_WGS84_rad;
  real_T dx_dmue;
  real_T dy_dlambda;
  real_T mue_rad;
  real_T lambda_rad;
  real32_T vel_N;
  real32_T vel_E;
  real32_T vel_D;
  real32_T Timestamp_ms;
  real32_T HorizontalAccuracy;
  real32_T VerticalAccuracy;
  real32_T SpeedAccuracy;
  real32_T GpsHeight;
  uint16_T pos_type;
  uint16_T sol_s_pos;
  uint16_T vel_type;
  uint16_T sol_s_vel;
  real32_T ant_heading;
  boolean_T heading_valid;
  real32_T Timestamp_ms_hd;
} GPS_data_Bus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_RTK_Data_Bus_
#define DEFINED_TYPEDEF_FOR_RTK_Data_Bus_

typedef struct {
  uint8_T RTK_status;
  real32_T pos_quality[3];
  real32_T vel_quality[3];
  real32_T heading_quality;
  uint32_T rtk_type;
  real_T dx_dmue;
  real_T dy_dlambda;
  real_T dz_dh;
  real_T mue_rad;
  real_T lambda_rad;
  real_T height_m;
  real32_T vel_N;
  real32_T vel_E;
  real32_T vel_D;
  real32_T heading;
  uint8_T numSV;
  uint32_T Timestamp_ms;
} RTK_Data_Bus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_Sonar_data_Bus_
#define DEFINED_TYPEDEF_FOR_Sonar_data_Bus_

typedef struct {
  real32_T h_sonar;
  boolean_T sonar_valid;
  boolean_T sonar_reset;
  real32_T h_grd_sonar;
  uint32_T timestamp_s;
} Sonar_data_Bus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_Vision_data_Bus_
#define DEFINED_TYPEDEF_FOR_Vision_data_Bus_

typedef struct {
  real32_T vel_xy_Ostar_OF[2];
  real32_T vel_xy_O_OF[2];
  real32_T Vision_quality;
  boolean_T Vision_valid;
  int32_T delta_t;
  uint32_T timestamp_ms;
  real32_T vel_z_O_OF;
  real32_T q0;
  real32_T q1;
  real32_T q2;
  real32_T q3;
  real32_T delta_pos_x;
  real32_T delta_pos_y;
  real32_T delta_pos_z;
  uint8_T type;
} Vision_data_Bus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_Battery_Data_Bus_
#define DEFINED_TYPEDEF_FOR_Battery_Data_Bus_

typedef struct {
  real32_T status;
  real32_T Capacity;
  real32_T Voltage;
  real32_T Current;
  real32_T Temperature;
  real32_T CycleCount;
  real32_T DesignCap;
  real32_T FullChgCap;
  real32_T RSOC;
  real32_T Cell_1_V;
  real32_T Cell_2_V;
  real32_T Cell_3_V;
  real32_T Cell_4_V;
  real32_T Cell_5_V;
  real32_T Cell_6_V;
  real32_T Cell_7_V;
  real32_T Cell_8_V;
  real32_T Timestamp_ms;
} Battery_Data_Bus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_Sensor_data_Bus_
#define DEFINED_TYPEDEF_FOR_Sensor_data_Bus_

typedef struct {
  real32_T rot_IB_B_raw_radDs[3];
  real32_T sfor_R_B_mDs2[3];
  boolean_T IMU_valid;
  real32_T h_R_B[3];
  real32_T Mag_Quality;
  real32_T magnitude_uT;
  real32_T delta_h_baro_m;
  boolean_T baro_valid;
  real32_T baro_Timestamp_ms;
  real32_T Heading_Quality;
  GPS_data_Bus GPS_data;
  RTK_Data_Bus RTK_Data;
  Sonar_data_Bus Sonar_data;
  Vision_data_Bus Vision_data;
  real32_T rpm[4];
  uint8_T esc_status;
  Battery_Data_Bus Battery_Data;
} Sensor_data_Bus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_Euler_Transformations_Bus_
#define DEFINED_TYPEDEF_FOR_Euler_Transformations_Bus_

typedef struct {
  real32_T Psi_star_rad;
  real32_T phi_rad;
  real32_T sin_phi;
  real32_T cos_phi;
  real32_T theta_rad;
  real32_T sin_theta;
  real32_T cos_theta;
} Euler_Transformations_Bus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_Rotation_data_Bus_
#define DEFINED_TYPEDEF_FOR_Rotation_data_Bus_

typedef struct {
  real32_T vel_O_O[3];
  real32_T ATT_quat_OB[4];
  real32_T M_OB[9];
  real32_T att_Oz_B[3];
  real32_T rot_IB_B_radDs[3];
  real32_T sfor_R_B_mDs2[3];
  real32_T Psi_dot_fused;
  real32_T Psi_dot_IMU;
  real32_T M_OObar[4];
  Euler_Transformations_Bus Euler_Transformations;
  real32_T Heading_Quality;
  real32_T Mag_Quality;
  real32_T Bias_gyro_radDs[3];
  real32_T standstill;
  boolean_T reset_Yaw;
  boolean_T All_reset_Yaw_flag;
  boolean_T rp_init_reset;
  boolean_T heading_init;
} Rotation_data_Bus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SCAL_PARAMS_
#define DEFINED_TYPEDEF_FOR_SCAL_PARAMS_

typedef struct {
  uint32_T FCS_VERSION;
  uint32_T Thrus_Mode;
  real32_T GMPU_Bias[3];
  real32_T GMPU_Rotation[9];
  real32_T AMPU_Rotation[9];
  real32_T AMPU_Bias[3];
  real32_T GICM_Bias[3];
  real32_T GICM_Rotation[9];
  real32_T AICM_Bias[3];
  real32_T AICM_Rotation[9];
  real32_T Mag_Rotation[9];
  real32_T Mag_Offset[3];
  real32_T Lat;
  real32_T Lon;
  real32_T max_tilt_deg;
  real32_T vel_max;
} SCAL_PARAMS;

#endif

#ifndef DEFINED_TYPEDEF_FOR_GPSLogic_Log_Bus_
#define DEFINED_TYPEDEF_FOR_GPSLogic_Log_Bus_

typedef struct {
  real32_T Status;
  real32_T Ts_Update;
  real32_T En_GPS_cor_core;
  real32_T En_GPS_Valid;
  real32_T En_GPS_Correct_RTK;
} GPSLogic_Log_Bus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_IMU_id_Bus_
#define DEFINED_TYPEDEF_FOR_IMU_id_Bus_

typedef struct {
  boolean_T imu_gyro_id_process;
  boolean_T imu_acc_id_process;
} IMU_id_Bus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_IMU_data_raw_Bus_
#define DEFINED_TYPEDEF_FOR_IMU_data_raw_Bus_

typedef struct {
  real32_T rot_IB_B_raw_radDs_1[3];
  real32_T sfor_R_B_mDs2_1[3];
  real32_T rot_IB_B_raw_radDs_2[3];
  real32_T sfor_R_B_mDs2_2[3];
} IMU_data_raw_Bus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_System_Status_Bus_
#define DEFINED_TYPEDEF_FOR_System_Status_Bus_

typedef struct {
  boolean_T Tilt_Over_flag;
  boolean_T ground_condition;
  boolean_T On_grd;
  boolean_T Armed;
  boolean_T forcedArm;
} System_Status_Bus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_INS_Base_Bus_
#define DEFINED_TYPEDEF_FOR_INS_Base_Bus_

typedef struct {
  real32_T phi_rad;
  real32_T theta_rad;
  real32_T Psi_star_rad;
  real32_T h_AGL_m;
  real32_T delta_h_m;
  real32_T h_dot_mDs;
  real32_T M_OObar[4];
  real_T mue_est_rad;
  real_T lambda_est_rad;
  real32_T Status;
  real_T dx_dmue;
  real_T dy_dlambda;
  real32_T VEL_xy_O_mDs[2];
  boolean_T sonar_valid;
  real32_T Vision_quality;
  boolean_T Vision_valid;
  boolean_T IMU_valid;
  real32_T Mag_Quality;
  boolean_T baro_valid;
  real32_T Heading_Quality;
  real32_T Spd_quality;
  real32_T Pos_quality;
  boolean_T Armed;
  boolean_T On_grd;
  boolean_T Tilt_Over_flag;
  boolean_T ground_condition;
  real32_T magnitude_uT;
  real32_T standstill;
  boolean_T GPS_Vel_Vaild;
  boolean_T VO_Vel_Valid;
  real32_T h_0_AGL_m;
  real32_T h_grd_sonar;
  real_T mue_est_rad_fc;
  real_T lambda_est_rad_fc;
  real32_T att_Oz_B[3];
  real32_T Oz_rotation;
  real32_T POS_xy_O_m[2];
} INS_Base_Bus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_Data_Base_Bus_
#define DEFINED_TYPEDEF_FOR_Data_Base_Bus_

typedef struct {
  real32_T Mag_Q[2];
  boolean_T reset_yaw;
  boolean_T att_init_done;
  IMU_id_Bus sensors_forlog;
  real32_T yaw_mag;
  IMU_data_raw_Bus imu_data_for_calibrate;
  real32_T roll_pitch_rate_bias[2];
  real32_T yaw_rate_bias;
  boolean_T RTK_Pos_Good;
  real32_T h_MSL;
  real32_T Vel_G[3];
  real_T Pos_LL_WGS84_Camera[2];
  boolean_T Pos_Init_flg;
  real32_T h_0_m_MSL;
} Data_Base_Bus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_XiESQcJND8c0bAWmJ4r1wG_
#define DEFINED_TYPEDEF_FOR_struct_XiESQcJND8c0bAWmJ4r1wG_

typedef struct {
  real_T Ts;
  real_T g;
  real_T pq_ad_on;
  real_T mot_mapping;
  real_T nz_max;
  uint8_T uav_id;
  uint8_T imu_id;
  uint8_T mag_id;
  real_T Mag_ScaleFactor;
  real_T GMPU_ScaleFactor[3];
  real_T GICM_ScaleFactor[3];
  real_T AMPU_ScaleFactor[3];
  real_T AICM_ScaleFactor[3];
  real32_T Mag_Rotation_Cal[9];
  real_T Acc_feedback_gain;
  real_T Acc_feedback_max;
  real_T Gyro_bias_gain;
  real_T Acc_feedback_gain_grd;
  real_T Acc_feedback_max_grd;
  real_T Gyro_bias_gain_grd;
  real_T Baro_filter_time_const;
  real_T kp_p;
  real_T kd_p;
  real_T kp_q;
  real_T kd_q;
  real_T kd_dt;
  real_T kp_dt;
  real_T k_ad;
  real_T kp_ozx;
  real_T kp_ozy;
  real_T max_yaw;
  real_T kp_r;
  real_T kd_r;
  real_T kp_psi;
  real_T h_dot_max;
  real_T h_dot_min;
  real_T kp_hdot;
  real_T ki_hdot;
  real_T kd_hdot;
  real_T kp_h;
  real_T delta_fz_on;
  real_T kp_vxy_ref;
  real_T kp_vxy;
  real_T ki_vxy;
  real_T DT2_Nu[3];
  real_T DT2_De[3];
  uint8_T wmm_mag[629];
  int8_T wmm_dec[629];
  int8_T wmm_inc[629];
} struct_XiESQcJND8c0bAWmJ4r1wG;

#endif

#ifndef typedef_dsp_private_SlidingWindowAver_T
#define typedef_dsp_private_SlidingWindowAver_T

typedef struct {
  int32_T isInitialized;
  boolean_T isSetupComplete;
  real32_T pCumSum;
  real32_T pCumSumRev[19];
  real32_T pCumRevIndex;
} dsp_private_SlidingWindowAver_T;

#endif

#ifndef typedef_cell_wrap_xstar_fcs_T
#define typedef_cell_wrap_xstar_fcs_T

typedef struct {
  uint32_T f1[8];
} cell_wrap_xstar_fcs_T;

#endif

#ifndef typedef_dsp_simulink_MovingAverage_xs_T
#define typedef_dsp_simulink_MovingAverage_xs_T

typedef struct {
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  boolean_T TunablePropsChanged;
  cell_wrap_xstar_fcs_T inputVarSize;
  dsp_private_SlidingWindowAver_T *pStatistic;
  int32_T NumChannels;
} dsp_simulink_MovingAverage_xs_T;

#endif

typedef struct {
  real32_T csumrev[19];
  real32_T MovingAverage2;
} B_MovingAverage2_xstar_fcs_T;

typedef struct {
  dsp_private_SlidingWindowAver_T gobj_0;
  dsp_private_SlidingWindowAver_T gobj_1;
  dsp_simulink_MovingAverage_xs_T obj;
  boolean_T objisempty;
} DW_MovingAverage2_xstar_fcs_T;

typedef struct {
  void* Assertion_slioAccessor;
  void* Assertion_slioAccessor_f;
  void* Assertion_slioAccessor_n;
  void* Assertion_slioAccessor_c;
} DW_IfWarningError_xstar_fcs_T;

typedef struct {
  Vision_Bus In1;
  Vision_Bus BusAssignment;
  real32_T VectorConcatenate_l[9];
  real32_T M_OB[9];
  real32_T Sum_i5[9];
  real32_T fv0[9];
  real32_T M_OB_g[9];
  real_T Translation_Fusion_o20[2];
  real32_T M_OObar[4];
  real32_T ATT_quat_OB[4];
  real32_T sfor_R_B_mDs2[3];
  real32_T Product2[3];
  real32_T TmpSignalConversionAtProduc[3];
  real32_T sincos_o2[3];
  real32_T Product1_ko[3];
  real32_T Product10[3];
  real32_T rot_IB_B_raw_radDs1[3];
  real32_T Product2_h[3];
  real32_T rot_IB_B_raw_radDs2[3];
  real32_T sfor_R_B_mDs2_main[3];
  real32_T sfor_R_B_mDs2_m[3];
  real32_T Translation_Fusion_o16[3];
  real32_T rot_IB_B_radDs_c[3];
  real32_T DiscreteTimeIntegrator_er[3];
  real32_T DiscreteTimeIntegrator_id[3];
  real32_T DiscreteTimeIntegrator_dj[3];
  real32_T Translation_Fusion_o19[3];
  real32_T att_Oz_B[3];
  real32_T Delay2[3];
  real32_T Bias_gyro_radDs[3];
  real32_T sfor_R_B_mDs2_c[3];
  real_T mue_rad;
  real_T lambda_rad;
  real_T mue_rad_i;
  real_T Add;
  real_T lambda_rad_f;
  real_T dz_dh;
  real_T Add_g;
  real_T Product4;
  real_T lambda_0_WGS84_rad;
  real_T mue_0_WGS84_rad;
  real_T Add_a;
  real_T Product4_h;
  real_T Sum2;
  real_T u1_n;
  real_T Subtract2_b;
  real_T rtb_TmpSignalConversionAtSFun_k;
  real_T lambda_est_rad;
  real_T mue_est_rad;
  real_T lambda_est_rad_fc;
  real_T mue_est_rad_fc;
  real_T lambda_est_rad_o;
  real_T mue_est_rad_b;
  real_T lambda_est_rad_fc_g;
  real_T mue_est_rad_fc_d;
  real_T x1;
  real_T x2;
  real_T b_y1;
  real_T y2;
  real_T d0;
  real32_T Pos_Init_flg[2];
  real32_T VEL_xy_O_mDs[2];
  real32_T POS_xy_O_m[2];
  real32_T ACC_xy_O_mDs[2];
  real32_T VEL_xy_O_mDs_i[2];
  real32_T POS_xy_O_m_c[2];
  real32_T Rotation_AHRS_GPS_o32[2];
  int16_T VectorConcatenate3[3];
  real32_T Product4_m;
  real32_T DiscreteTimeIntegrator1;
  real32_T Product1[2];
  real32_T Gain;
  real32_T ant_heading;
  real32_T Timestamp_ms_hd;
  real32_T h_grd_sonar;
  real32_T mul5[3];
  real32_T rot_IB_B_radDs[3];
  real32_T Vision_quality;
  real32_T vel_O_O[3];
  real32_T Product1_g;
  real32_T baro_Timestamp_ms;
  real32_T Double1;
  real32_T Status;
  real32_T Timestamp_ms;
  real32_T GpsHeight;
  real32_T Saturation1[3];
  real32_T Saturation1_d[3];
  real32_T Multiply;
  real32_T Multiply1;
  real32_T Gain_k;
  real32_T Sum1;
  real32_T Sum1_i;
  real32_T delta_pos_z;
  real32_T HorizontalAccuracy;
  real32_T VerticalAccuracy;
  real32_T Sqrt;
  real32_T Saturation1_g;
  real32_T deg2rad;
  real32_T delta_h_m;
  real32_T mul3[3];
  real32_T q0;
  real32_T q1;
  real32_T q2;
  real32_T q3;
  real32_T rpm[4];
  real32_T status;
  real32_T Capacity;
  real32_T Voltage;
  real32_T Current;
  real32_T Temperature;
  real32_T CycleCount;
  real32_T DesignCap;
  real32_T FullChgCap;
  real32_T RSOC;
  real32_T Cell_1_V;
  real32_T Cell_2_V;
  real32_T Cell_3_V;
  real32_T Cell_4_V;
  real32_T Cell_5_V;
  real32_T Cell_6_V;
  real32_T Cell_7_V;
  real32_T Cell_8_V;
  real32_T Merge[4];
  real32_T Selector1[3];
  real32_T Divide;
  real32_T g_M_d_R;
  real32_T In1_d[9];
  real32_T y[3];
  real32_T Timestamp_ms_c;
  real32_T DiscreteTimeIntegrator_d0;
  real32_T Product2_mi;
  real32_T DiscreteTimeIntegrator_pl;
  real32_T DiscreteTimeIntegrator2_oo;
  real32_T DiscreteTimeIntegrator1_m;
  real32_T DataTypeConversion;
  real32_T raw_sona_h;
  real32_T h_AGL_m;
  real32_T DiscreteTimeIntegrator5;
  real32_T DiscreteTimeIntegrator5_d;
  real32_T DiscreteTimeIntegrator5_i;
  real32_T Gain2_d;
  real32_T Switch_m;
  real32_T DiscreteTimeIntegrator5_c;
  real32_T DiscreteTimeIntegrator5_b;
  real32_T DiscreteTimeIntegrator5_e;
  real32_T Product1_g_b;
  real32_T Product3_l;
  real32_T DiscreteTimeIntegrator3_n;
  real32_T DiscreteTimeIntegrator_ee;
  real32_T Gain2_p;
  real32_T Sum_f;
  real32_T fcn3;
  real32_T DiscreteTimeIntegrator1_i;
  real32_T MathFunction_g;
  real32_T Gain_p;
  real32_T DiscreteTimeIntegrator_b;
  real32_T Gain1_g;
  real32_T Product_cm;
  real32_T Add_n;
  real32_T Delay_d;
  real32_T sample_sum_a;
  real32_T rtb_v_idx_2;
  real32_T rtb_Mag_Q_idx_0;
  real32_T rtb_Saturation_j_idx_0;
  real32_T rtb_Saturation_j_idx_1;
  real32_T rtb_Saturation_j_idx_2;
  real32_T rtb_v_idx_0;
  real32_T rtb_v_idx_1;
  real32_T rtb_Product8_idx_0;
  real32_T rtb_Product8_idx_1;
  real32_T rtb_Product8_idx_2;
  real32_T rtb_Product9_idx_0;
  real32_T rtb_Product9_idx_1;
  real32_T rtb_DiscreteTimeIntegrator5_bi_;
  real32_T rtb_DiscreteTimeIntegrator5_b_f;
  real32_T rtb_DiscreteTimeIntegrator5_b_g;
  real32_T rtb_DiscreteTimeIntegrator5_j_i;
  real32_T rtb_DiscreteTimeIntegrator5_j_m;
  real32_T rtb_DiscreteTimeIntegrator5_j_n;
  real32_T u0;
  real32_T u0_p;
  real32_T u0_l;
  real32_T u1;
  real32_T rtb_DataTypeConversion_j;
  real32_T f0;
  real32_T switchtoATTI;
  real32_T yaw_mag;
  real32_T Psi_star_rad;
  real32_T phi_rad;
  real32_T theta_rad;
  real32_T Translation_Fusion_o28;
  real32_T En_GPS_Correct_RTK;
  real32_T En_GPS_Valid;
  real32_T En_GPS_cor_core;
  real32_T Ts_Update;
  real32_T Status_d;
  real32_T Translation_Fusion_o22;
  real32_T h_MSL_g;
  real32_T Rotation_AHRS_GPS_o31;
  real32_T yaw_mag_p;
  real32_T h_AGL_m_a;
  real32_T Bias_z_mDs2;
  real32_T h_MSL;
  real32_T h_0_AGL_m;
  real32_T h_dot_mDs_c;
  real32_T h_AGL_m_l;
  real32_T Bias_z_mDs2_g;
  real32_T delta_h_m_g;
  real32_T h_0_AGL_m_m;
  real32_T h_AGL_m_n;
  real32_T standstill;
  real32_T Heading_Quality;
  real32_T Mag_Quality;
  real32_T cos_theta;
  real32_T sin_theta;
  real32_T cos_phi;
  real32_T sin_phi;
  real32_T Psi_dot_IMU;
  real32_T Rotation_AHRS_GPS_o25;
  real32_T h_dot_mDs;
  real32_T u1_g;
  int32_T delta_t;
  int32_T cff;
  int32_T UnitDelay;
  int32_T Sum_mz;
  int32_T i0;
  int32_T i1;
  int32_T i2;
  int32_T i3;
  int32_T i4;
  int32_T i5;
  int32_T low_i;
  int32_T low_ip1;
  int32_T high_i;
  int32_T b_high_i;
  int32_T b_mid_i;
  int32_T i;
  int32_T curState;
  int32_T newState;
  int32_T newStateR;
  int32_T lastzcevent;
  int32_T u0_ld;
  int32_T u1_d;
  uint32_T timestamp_s;
  uint32_T pos_type;
  uint32_T Cast;
  uint32_T timestamp_ms;
  real32_T rot_IB_B_raw_radDs[3];
  uint32_T rtb_Switch_timestamp_v;
  uint32_T Cast1;
  uint32_T Cast2;
  uint32_T DiscreteTimeIntegrator_h3;
  uint32_T qY;
  uint32_T qY_d;
  uint32_T previousState;
  int16_T gyro_x;
  int16_T gyro_y;
  int16_T gyro_z;
  int16_T acc_x;
  int16_T acc_y;
  int16_T acc_z;
  int16_T SumofElements;
  int16_T rtb_Switch_delta_pos_y;
  int16_T rtb_Switch_delta_pos_z;
  int16_T rtb_Switch_delta_q0;
  int16_T rtb_Switch_delta_q1;
  int16_T rtb_Switch_delta_q2;
  int16_T rtb_Switch_delta_q3;
  int16_T rtb_VectorConcatenate1_c_idx_0;
  int16_T rtb_VectorConcatenate1_c_idx_1;
  int16_T rtb_VectorConcatenate1_c_idx_2;
  uint16_T pos_type_m;
  uint16_T sol_s_pos;
  uint16_T vel_type;
  uint16_T sol_s_vel;
  uint16_T Saturation7;
  int8_T Switch1_l;
  int8_T Switch2;
  uint8_T Switch1;
  uint8_T Sum;
  uint8_T SVs;
  uint8_T Switch;
  uint8_T Compare_d;
  uint8_T FixPtRelationalOperator;
  uint8_T Pos_valid;
  boolean_T IMU_valid;
  boolean_T Compare;
  boolean_T LogicalOperator;
  boolean_T Switch1_a;
  boolean_T Switch_i;
  boolean_T LogicalOperator4;
  boolean_T sonar_reset;
  boolean_T Armed;
  boolean_T Switch_l;
  boolean_T LogicalOperator4_jz;
  boolean_T LogicalOperator13;
  boolean_T LogicalOperator18;
  boolean_T LogicalOperator_c;
  boolean_T LogicalOperator2;
  boolean_T FixPtRelationalOperator_d0;
  boolean_T FixPtRelationalOperator_n1;
  boolean_T FixPtRelationalOperator_fv;
  boolean_T FixPtRelationalOperator_fs;
  boolean_T flag_IMU1_acc_loss;
  boolean_T LogicalOperator_j;
  boolean_T FixPtRelationalOperator_kg;
  boolean_T FixPtRelationalOperator_ks;
  boolean_T FixPtRelationalOperator_kt;
  boolean_T FixPtRelationalOperator_e;
  boolean_T LogicalOperator7;
  boolean_T LogicalOperator10;
  boolean_T Compare_dq;
  boolean_T Compare_ld;
  boolean_T f4;
  boolean_T Compare_gw;
  boolean_T Compare_ot;
  boolean_T LogicalOperator_f;
  boolean_T LogicalOperator3_f;
  boolean_T LogicalOperator3_b;
  boolean_T Armed_p;
  boolean_T rp_init_reset;
  boolean_T Rotation_AHRS_GPS_o27;
  boolean_T heading_init;
  boolean_T VO_Vel_Valid;
  boolean_T GPS_Vel_Vaild;
  boolean_T Pos_Init_flg_p;
  boolean_T Translation_Fusion_o17;
  boolean_T Rotation_AHRS_GPS_o28;
  boolean_T Rotation_AHRS_GPS_o26;
  boolean_T Rotation_AHRS_GPS_o33;
  boolean_T DataTypeConversion1_n;
  boolean_T POS_reset_signal;
  boolean_T VO_Vel_Valid_m;
  boolean_T GPS_Vel_Vaild_d;
  boolean_T On_grd;
  boolean_T Delay10;
  boolean_T Delay1_d;
  boolean_T POS_reset_signal_k;
  boolean_T All_reset_Yaw_flag;
  boolean_T reset_Yaw;
  boolean_T Rotation_AHRS_GPS_o29;
  B_MovingAverage2_xstar_fcs_T MovingAverage_pn;
  B_MovingAverage2_xstar_fcs_T MovingAverage1_pn;
  B_MovingAverage2_xstar_fcs_T MovingAverage2_pn;
  B_MovingAverage2_xstar_fcs_T MovingAverage_p;
  B_MovingAverage2_xstar_fcs_T MovingAverage1_p;
  B_MovingAverage2_xstar_fcs_T MovingAverage2_p;
  B_MovingAverage2_xstar_fcs_T MovingAverage;
  B_MovingAverage2_xstar_fcs_T MovingAverage1;
  B_MovingAverage2_xstar_fcs_T MovingAverage2;
} B_xstar_fcs_T;

typedef struct {
  real_T Memory1_14_PreviousInput;
  real_T Memory1_15_PreviousInput;
  real_T Memory1_8_PreviousInput;
  real_T Memory1_9_PreviousInput;
  real32_T DiscreteTimeIntegrator2_DSTATE;
  real32_T Discrete_Time_Integrator_DSTATE;
  real32_T DiscreteTimeIntegrator2_DSTAT_i;
  real32_T DiscreteTimeIntegrator2_DSTAT_d;
  real32_T DelayInput1_DSTATE;
  real32_T DiscreteTimeIntegrator2_DSTAT_a;
  real32_T DiscreteTimeIntegrator_DSTATE;
  real32_T DiscreteTimeIntegrator_DSTATE_h;
  real32_T DiscreteTimeIntegrator2_DSTA_ab;
  real32_T DiscreteTimeIntegrator2_DSTAT_m;
  real32_T DiscreteTimeIntegrator2_DSTAT_n;
  real32_T DelayInput1_DSTATE_b;
  real32_T DiscreteTimeIntegrator2_DSTAT_h;
  real32_T DiscreteTimeIntegrator1_DSTATE;
  real32_T Delay7_DSTATE[3];
  real32_T Delay_DSTATE[3];
  real32_T DiscreteTimeIntegrator2_DSTA_ih;
  real32_T DiscreteTimeIntegrator2_DSTAT_j;
  real32_T DiscreteTimeIntegrator2_DSTA_jl;
  real32_T DelayInput1_DSTATE_a;
  real32_T DiscreteTimeIntegrator2_DSTAT_e;
  real32_T DiscreteTimeIntegrator2_DSTA_h1;
  real32_T DiscreteTimeIntegrator_DSTATE_m;
  real32_T DiscreteTimeIntegrator2_DSTAT_l;
  real32_T DiscreteTimeIntegrator2_DSTAT_c;
  real32_T DiscreteTimeIntegrator2_DSTA_cc;
  real32_T DelayInput1_DSTATE_m;
  real32_T DiscreteTimeIntegrator2_DSTAT_g;
  real32_T DiscreteTimeIntegrator3_DSTATE;
  real32_T Delay9_DSTATE[3];
  real32_T DelayInput1_DSTATE_bk;
  real32_T DelayInput1_DSTATE_l;
  real32_T DelayInput1_DSTATE_c;
  real32_T DiscreteTimeIntegrator1_DSTAT_n;
  real32_T DelayInput1_DSTATE_i;
  real32_T DiscreteTimeIntegrator1_DSTAT_b;
  real32_T DiscreteTimeIntegrator5_DSTATE;
  real32_T DiscreteTimeIntegrator5_DSTAT_i;
  real32_T DiscreteTimeIntegrator_DSTATE_d;
  real32_T DiscreteTimeIntegrator5_DSTAT_b;
  real32_T Delay_DSTATE_c;
  real32_T DiscreteTimeIntegrator5_DSTAT_a;
  real32_T DiscreteTimeIntegrator5_DSTAT_o;
  real32_T DiscreteTimeIntegrator5_DSTA_ac;
  real32_T DiscreteTimeIntegrator5_DSTAT_n;
  real32_T Delay1_DSTATE;
  real32_T DiscreteTimeIntegrator1_DSTAT_e;
  real32_T DiscreteTimeIntegrator_DSTAT_dk;
  real32_T Delay_DSTATE_h;
  real32_T TappedDelay2_X[150];
  real32_T TappedDelay2_X_c[150];
  real32_T TappedDelay2_X_k[150];
  real32_T TappedDelay2_X_i[150];
  real32_T DelayInput1_DSTATE_j;
  real32_T u80_states[537];
  real32_T DelayInput1_DSTATE_it;
  real32_T DiscreteTimeIntegrator3_DSTAT_g;
  real32_T DiscreteTimeIntegrator1_DSTAT_h;
  real32_T Delay_118_DSTATE;
  real32_T DiscreteTimeIntegrator_DSTATE_n;
  real32_T Delay2_DSTATE[3];
  real32_T DelayInput1_DSTATE_jl;
  real32_T DelayInput1_DSTATE_h;
  real32_T UnitDelay_3_DSTATE;
  real32_T DiscreteTimeIntegrator5_DSTAT_g[3];
  real32_T DiscreteTimeIntegrator5_DSTAT_d[3];
  real32_T Delay_DSTATE_m;
  real32_T Delay_DSTATE_g;
  real32_T Delay_DSTATE_f;
  real32_T DiscreteTimeIntegrator5_DSTAT_f;
  real32_T DiscreteTimeIntegrator5_DSTAT_j;
  real32_T TappedDelay2_X_l[150];
  real32_T TappedDelay2_X_m[150];
  real32_T TappedDelay2_X_f[150];
  real32_T DelayInput1_DSTATE_f;
  real32_T DiscreteTimeIntegrator_DSTATE_f;
  real32_T DiscreteTimeIntegrator1_DSTA_hy;
  real32_T DiscreteTimeIntegrator_DSTATE_j;
  real32_T DiscreteTimeIntegrator_DSTATE_b;
  real32_T DelayInput1_DSTATE_li;
  real32_T DiscreteTimeIntegrator1_DSTAT_f;
  real32_T DiscreteTimeIntegrator2_DSTAT_p;
  real32_T DiscreteTimeIntegrator_DSTAT_b0;
  real32_T Delay8_DSTATE[3];
  real32_T Delay1_DSTATE_e[3];
  real32_T Delay2_DSTATE_k[360];
  real32_T Delay3_DSTATE[3];
  real32_T DiscreteTimeIntegrator_DSTAT_hp;
  real32_T Delay4_DSTATE[3];
  real32_T DiscreteTimeIntegrator_DSTATE_k;
  real32_T Delay6_DSTATE[3];
  real32_T Delay5_DSTATE[3];
  real32_T DiscreteTimeIntegrator5_DSTAT_k;
  real32_T DiscreteTimeIntegrator5_DSTA_k1;
  real32_T DiscreteTimeIntegrator5_DSTAT_e;
  real32_T Delay2_DSTATE_g[50];
  real32_T Delay5_DSTATE_f[200];
  real32_T Delay4_DSTATE_j[150];
  real32_T Delay3_DSTATE_e[100];
  real32_T DiscreteTimeIntegrator_DSTAT_dv[3];
  real32_T DiscreteTimeIntegrator_DSTATE_g[3];
  real32_T DiscreteTimeIntegrator_DSTAT_ge[3];
  int32_T UnitDelay_DSTATE;
  int32_T u80_circBuf;
  uint32_T DiscreteTimeIntegrator_DSTAT_jp;
  uint32_T DiscreteTimeIntegrator_DSTAT_kr;
  uint32_T DiscreteTimeIntegrator_DSTATE_c;
  uint32_T DiscreteTimeIntegrator_DSTAT_mz;
  uint32_T DelayInput1_DSTATE_d;
  uint32_T DelayInput1_DSTATE_lh;
  uint32_T DiscreteTimeIntegrator_DSTAT_fh;
  uint32_T DiscreteTimeIntegrator_DSTAT_ng;
  uint32_T DelayInput1_DSTATE_g;
  uint32_T DiscreteTimeIntegrator_DSTAT_fw;
  uint32_T DelayInput1_DSTATE_p;
  uint32_T DiscreteTimeIntegrator1_DSTA_hf;
  uint32_T DelayInput1_DSTATE_mh;
  uint32_T DiscreteTimeIntegrator2_DSTA_hw;
  uint32_T DiscreteTimeIntegrator_DSTAT_jd;
  real32_T Memory1_1_PreviousInput;
  real32_T Memory_95_PreviousInput[9];
  real32_T Memory_101_PreviousInput[4];
  real32_T Memory_118_PreviousInput;
  real32_T Memory_97_PreviousInput[3];
  real32_T Memory1_PreviousInput;
  real32_T Memory1_10_PreviousInput[2];
  real32_T Memory1_2_PreviousInput;
  real32_T Memory1_3_PreviousInput;
  real32_T Memory1_4_PreviousInput;
  real32_T Memory1_5_PreviousInput;
  real32_T Memory1_6_PreviousInput[2];
  real32_T Memory1_7_PreviousInput[2];
  real32_T Memory_PreviousInput;
  real32_T Memory1_PreviousInput_i;
  real32_T Memory_PreviousInput_d[3];
  uint32_T Memory2_PreviousInput;
  uint32_T Counter_ClkEphState;
  uint32_T Counter_RstEphState;
  uint32_T Counter1_ClkEphState;
  uint32_T Counter1_RstEphState;
  uint32_T Counter_ClkEphState_m;
  uint32_T Counter_RstEphState_c;
  uint32_T Counter1_ClkEphState_d;
  uint32_T Counter1_RstEphState_n;
  uint32_T Counter_ClkEphState_my;
  uint32_T Counter_RstEphState_i;
  uint32_T Counter1_ClkEphState_h;
  uint32_T Counter1_RstEphState_a;
  uint32_T Memory2_PreviousInput_c;
  int16_T DelayInput1_DSTATE_pq;
  int16_T DelayInput1_DSTATE_fe;
  int16_T DelayInput1_DSTATE_pk;
  int16_T DelayInput1_DSTATE_d5;
  int16_T DelayInput1_DSTATE_e;
  int16_T DelayInput1_DSTATE_ei;
  int16_T DelayInput1_DSTATE_ip;
  int16_T DelayInput1_DSTATE_k;
  int16_T DelayInput1_DSTATE_n;
  int16_T DelayInput1_DSTATE_kc;
  int16_T DelayInput1_DSTATE_b1;
  int16_T DelayInput1_DSTATE_el;
  uint16_T Counter_Count;
  uint16_T Counter1_Count;
  uint16_T Counter_Count_g;
  uint16_T Counter1_Count_h;
  uint16_T Counter_Count_h;
  uint16_T Counter1_Count_k;
  int8_T DelayInput1_DSTATE_kct;
  int8_T DelayInput1_DSTATE_gg;
  boolean_T Delay4_DSTATE_h;
  boolean_T Delay_DSTATE_a;
  boolean_T Delay_DSTATE_k;
  boolean_T DelayInput1_DSTATE_g1;
  boolean_T Delay_DSTATE_kf;
  boolean_T Delay_DSTATE_p[52];
  boolean_T Delay_DSTATE_hm;
  boolean_T Delay1_DSTATE_g;
  boolean_T Delay10_DSTATE;
  boolean_T UnitDelay_1_DSTATE;
  boolean_T Delay3_DSTATE_n;
  int8_T DiscreteTimeIntegrator_PrevRese;
  int8_T DiscreteTimeIntegrator_PrevRe_l;
  int8_T DiscreteTimeIntegrator_PrevRe_n;
  int8_T DiscreteTimeIntegrator5_PrevRes;
  int8_T DiscreteTimeIntegrator5_PrevR_c;
  int8_T DiscreteTimeIntegrator_PrevRe_p;
  int8_T DiscreteTimeIntegrator5_PrevR_h;
  int8_T DiscreteTimeIntegrator5_PrevR_m;
  int8_T DiscreteTimeIntegrator5_PrevR_f;
  int8_T DiscreteTimeIntegrator5_PrevR_o;
  int8_T DiscreteTimeIntegrator_PrevRe_i;
  int8_T DiscreteTimeIntegrator_PrevRe_o;
  int8_T DiscreteTimeIntegrator_PrevR_iy;
  uint8_T DiscreteTimeIntegrator1_IC_LOAD;
  uint8_T DiscreteTimeIntegrator5_IC_LOAD;
  uint8_T DiscreteTimeIntegrator5_IC_LO_b;
  uint8_T DiscreteTimeIntegrator1_IC_LO_e;
  uint8_T DiscreteTimeIntegrator5_IC_LO_f;
  uint8_T DiscreteTimeIntegrator5_IC_L_bz;
  uint8_T DiscreteTimeIntegrator5_IC_LO_c;
  uint8_T DiscreteTimeIntegrator5_IC_LO_g;
  uint8_T DiscreteTimeIntegrator1_IC_LO_g;
  uint8_T icLoad;
  uint8_T icLoad_p;
  uint8_T icLoad_pg;
  uint8_T DiscreteTimeIntegrator_IC_LOADI;
  uint8_T DiscreteTimeIntegrator_IC_LOA_e;
  uint8_T DiscreteTimeIntegrator_IC_LOA_p;
  boolean_T Memory_54_PreviousInput;
  boolean_T Memory_134_PreviousInput;
  boolean_T Memory1_12_PreviousInput;
  boolean_T Memory1_13_PreviousInput;
  boolean_T Memory1_11_PreviousInput;
  boolean_T Reference_and_Gradient_MODE;
  boolean_T GyroBiasEstimation1_MODE;
  boolean_T GyroBiasEstimation_MODE;
  DW_IfWarningError_xstar_fcs_T IfWarningError_n;
  DW_IfWarningError_xstar_fcs_T IfWarningError;
  DW_MovingAverage2_xstar_fcs_T MovingAverage_pn;
  DW_MovingAverage2_xstar_fcs_T MovingAverage1_pn;
  DW_MovingAverage2_xstar_fcs_T MovingAverage2_pn;
  DW_MovingAverage2_xstar_fcs_T MovingAverage_p;
  DW_MovingAverage2_xstar_fcs_T MovingAverage1_p;
  DW_MovingAverage2_xstar_fcs_T MovingAverage2_p;
  DW_MovingAverage2_xstar_fcs_T MovingAverage;
  DW_MovingAverage2_xstar_fcs_T MovingAverage1;
  DW_MovingAverage2_xstar_fcs_T MovingAverage2;
} DW_xstar_fcs_T;

typedef struct {
  ZCSigState Delay1_Reset_ZCE;
  ZCSigState WGS_Linearization_Trig_ZCE;
  ZCSigState WGS_Linearization_Trig_ZCE_f;
} PrevZCX_xstar_fcs_T;

typedef struct {
  Sensors_Bus sensors;
} ExtU_xstar_fcs_T;

typedef struct {
  INS_Base_Bus INS_Base;
  Data_Base_Bus Data_out;
  Sensor_data_Bus Sensor_data;
  System_Status_Bus Sys_status;
  boolean_T Mag_valid;
  real32_T h_R_B_raw[3];
  uint8_T att_init;
  alink_RTK_Bus alink_rtk_location;
  GPSLogic_Log_Bus GPS_logic_log;
  real32_T Vx_cor;
} ExtY_xstar_fcs_T;

struct P_IfWarningError_xstar_fcs_T_ {
  real_T Constant1_Value;
  real_T Constant1_Value_g;
  real32_T Bias_Bias;
  real32_T Bias1_Bias[9];
};

typedef struct P_IfWarningError_xstar_fcs_T_ P_IfWarningError_xstar_fcs_T;
struct P_xstar_fcs_T_ {
  real_T DirectionCosineMatrixtoQuaterni;
  real_T DirectionCosineMatrixtoRotation;
  int32_T delay_delay_of;
  int32_T delay1_delay_of;
  int32_T delay2_delay_of;
  int32_T delay3_delay_of;
  int32_T delay1_delay_of_b;
  int32_T delay_delay_of_i;
  int32_T delay2_delay_of_g;
  real32_T Validaperiod1_T_p;
  real32_T Validaperiod_T_p;
  real32_T Validaperiod2_T_p;
  real32_T Ascendanddescendtracking_Tc_asc;
  real32_T Ascendanddescendtracking_Tc_a_e;
  real32_T Ascendanddescendtracking_Tc_a_h;
  real32_T Ascendanddescendtracking_Tc_des;
  real32_T Ascendanddescendtracking_Tc_d_l;
  real32_T Ascendanddescendtracking_Tc_d_f;
  real32_T CompareToConstant_const;
  real32_T CompareToConstant_const_d;
  real32_T CompareToConstant1_const;
  real32_T CompareTo1sec_const;
  real32_T CompareToConstant2_const;
  real32_T CompareToConstant3_const;
  real32_T CompareToConstant4_const;
  real32_T CompareToConstant5_const;
  real32_T CompareTo1sec_const_j;
  real32_T CompareToConstant6_const;
  real32_T CompareToConstant7_const;
  real32_T CompareToConstant4_const_m;
  real32_T CompareToConstant3_const_e;
  real32_T CompareToConstant5_const_p;
  real32_T CompareToConstant6_const_k;
  real32_T CompareToConstant_const_a;
  real32_T CompareToConstant_const_dz;
  real32_T CompareToConstant_const_e;
  real32_T CompareToConstant_const_a2;
  real32_T CompareToConstant2_const_a;
  real32_T CompareToConstant1_const_c;
  real32_T CompareToConstant_const_f;
  real32_T CompareToConstant2_const_m;
  real32_T CompareTo1sec_const_n;
  real32_T CompareToConstant_const_al;
  real32_T CompareToConstant1_const_n;
  real32_T CompareToConstant3_const_j;
  real32_T CompareToConstant_const_n;
  real32_T CompareToConstant_const_c;
  real32_T CompareToConstant8_const;
  real32_T CompareToConstant8_const_k;
  real32_T CompareToConstant5_const_k;
  real32_T CompareToConstant6_const_b;
  real32_T CompareToConstant1_const_j;
  real32_T CompareToConstant3_const_c;
  real32_T CompareToConstant7_const_h;
  real32_T CompareToConstant_const_o;
  real32_T CompareToConstant10_const;
  real32_T CompareToConstant8_const_kb;
  real32_T CompareTo1sec_const_k;
  real32_T CompareToConstant2_const_g;
  real32_T CompareToConstant9_const;
  real32_T CompareToConstant_const_a0;
  real32_T CompareToConstant_const_fu;
  real32_T CompareToConstant1_const_a;
  real32_T CompareToConstant_const_j;
  real32_T CompareToConstant1_const_d;
  real32_T CompareToConstant_const_b;
  real32_T CompareToConstant1_const_e;
  real32_T CompareToConstant_const_p;
  real32_T CompareToConstant3_const_i;
  real32_T CompareToConstant1_const_ap;
  real32_T CompareToConstant_const_pb;
  real32_T CompareToConstant_const_i;
  real32_T delay_init;
  real32_T delay1_init;
  real32_T delay2_init;
  real32_T delay3_init;
  real32_T delay1_init_f;
  real32_T delay_init_j;
  real32_T delay2_init_i;
  real32_T IntervalTest_lowlimit;
  real32_T IMU_detection1_max1;
  real32_T IMU_detection_max1;
  real32_T IMU_detection1_max2;
  real32_T IMU_detection_max2;
  real32_T IMU_detection1_min1;
  real32_T IMU_detection_min1;
  real32_T IMU_detection1_min2;
  real32_T IMU_detection_min2;
  real32_T delta_Height_pressure_max;
  real32_T delta_Height_pressure_min;
  real32_T delta_Height_temp_max;
  real32_T delta_Height_temp_min;
  real32_T Zero_Value_Exclusion_thr;
  real32_T Subsystem_time_judge_in_air;
  real32_T Subsystem1_time_judge_in_air;
  real32_T Subsystem2_time_judge_in_air;
  real32_T Subsystem6_time_judge_in_air;
  real32_T Subsystem7_time_judge_in_air;
  real32_T Subsystem8_time_judge_in_air;
  real32_T Subsystem9_time_judge_in_air;
  real32_T Subsystem13_time_judge_in_air;
  real32_T Subsystem21_time_judge_in_air;
  real32_T Subsystem22_time_judge_in_air;
  real32_T Subsystem23_time_judge_in_air;
  real32_T Subsystem24_time_judge_in_air;
  real32_T Subsystem16_time_judge_in_air;
  real32_T Subsystem17_time_judge_in_air;
  real32_T Subsystem18_time_judge_in_air;
  real32_T Subsystem19_time_judge_in_air;
  real32_T Subsystem3_time_judge_in_air;
  real32_T Subsystem_time_judge_on_grd;
  real32_T Subsystem1_time_judge_on_grd;
  real32_T Subsystem2_time_judge_on_grd;
  real32_T Subsystem6_time_judge_on_grd;
  real32_T Subsystem7_time_judge_on_grd;
  real32_T Subsystem8_time_judge_on_grd;
  real32_T Subsystem9_time_judge_on_grd;
  real32_T Subsystem13_time_judge_on_grd;
  real32_T Subsystem21_time_judge_on_grd;
  real32_T Subsystem22_time_judge_on_grd;
  real32_T Subsystem23_time_judge_on_grd;
  real32_T Subsystem24_time_judge_on_grd;
  real32_T Subsystem16_time_judge_on_grd;
  real32_T Subsystem17_time_judge_on_grd;
  real32_T Subsystem18_time_judge_on_grd;
  real32_T Subsystem19_time_judge_on_grd;
  real32_T DirectionCosineMatrixtoQuater_e;
  real32_T DirectionCosineMatrixtoRotati_b;
  real32_T IntervalTest_uplimit;
  real32_T DetectChange6_vinit;
  real32_T DetectChange13_vinit;
  real32_T DetectChange24_vinit;
  real32_T DetectChange19_vinit;
  real32_T DetectChange_vinit;
  real32_T DetectChange_vinit_p;
  real32_T DetectChange_vinit_d;
  real32_T DetectChange_vinit_o;
  real32_T DetectIncrease_vinit;
  real32_T DetectIncrease1_vinit;
  real32_T DetectChange_vinit_k;
  real32_T DetectChange_vinit_kj;
  real32_T DetectIncrease_vinit_c;
  real32_T DetectChange_vinit_c;
  uint32_T BitwiseAND_BitMask;
  uint32_T BitwiseAND1_BitMask;
  uint32_T IMU_detection1_Time_out;
  uint32_T IMU_detection_Time_out;
  uint32_T Mag_Detection_Time_out;
  uint32_T CompareToConstant4_const_a;
  uint32_T CompareToConstant_const_ep;
  uint32_T CompareToConstant4_const_e;
  uint32_T CompareToConstant4_const_j;
  uint32_T CompareToConstant1_const_k;
  uint32_T CompareToConstant2_const_h;
  uint32_T CompareToConstant_const_l;
  uint32_T CompareToConstant4_const_i;
  uint32_T CompareToConstant1_const_g;
  uint32_T CompareToConstant2_const_j;
  uint32_T CompareToConstant_const_m;
  uint32_T CompareToConstant5_const_b;
  uint32_T CompareToConstant8_const_p;
  uint32_T CompareToConstant4_const_b;
  uint32_T delta_Height_s_first;
  uint32_T delta_Height_s_last;
  uint32_T DetectIncrease_vinit_i;
  uint32_T DetectIncrease2_vinit;
  uint32_T DetectChange_vinit_o5;
  uint32_T DetectChange1_vinit;
  uint32_T DetectChange2_vinit;
  int16_T CompareToConstant_const_es;
  int16_T IMU_detection1_temp_max;
  int16_T IMU_detection_temp_max;
  int16_T IMU_detection1_temp_min;
  int16_T IMU_detection_temp_min;
  int16_T DetectChange_vinit_f;
  int16_T DetectChange1_vinit_m;
  int16_T DetectChange2_vinit_c;
  int16_T DetectChange7_vinit;
  int16_T DetectChange8_vinit;
  int16_T DetectChange9_vinit;
  int16_T DetectChange21_vinit;
  int16_T DetectChange22_vinit;
  int16_T DetectChange23_vinit;
  int16_T DetectChange16_vinit;
  int16_T DetectChange17_vinit;
  int16_T DetectChange18_vinit;
  uint16_T Counter_InitialCount;
  uint16_T Counter1_InitialCount;
  uint16_T Counter_InitialCount_i;
  uint16_T Counter1_InitialCount_d;
  uint16_T Counter_InitialCount_m;
  uint16_T Counter1_InitialCount_o;
  uint16_T CompareToConstant1_const_p;
  uint16_T CompareToConstant_const_ly;
  uint16_T CompareToConstant2_const_gs;
  boolean_T DetectDecrease_vinit;
  int8_T CompareToConstant_const_h;
  int8_T CompareToConstant1_const_pz;
  int8_T DetectChange_vinit_n;
  int8_T DetectChange1_vinit_n;
  uint8_T BitwiseAND_BitMask_e;
  uint8_T BitwiseAND2_BitMask;
  uint8_T BitwiseAND_BitMask_p;
  uint8_T BitwiseAND2_BitMask_n;
  uint8_T CompareToConstant1_const_o;
  uint8_T CompareToConstant3_const_l;
  uint8_T CompareToConstant_const_k;
  uint8_T CompareToConstant9_const_e;
  uint8_T CompareToConstant1_const_ge;
  uint8_T CompareToConstant_const_ai;
  Vision_Bus Out1_Y0;
  Vision_Bus Out1_Y0_o;
  real_T lambda_0_rad_Y0;
  real_T mue_0_rad_Y0;
  real_T dx_dmue_Y0;
  real_T dy_dlambda_Y0;
  real_T Scalefactor_Gain;
  real_T Scalefactor1_Gain;
  real_T constant2_Value;
  real_T f_Value;
  real_T constant_Value;
  real_T a_Value;
  real_T a1_Value;
  real_T dx_dmue_Y0_k;
  real_T dy_dlambda_Y0_g;
  real_T dz_dh_Y0;
  real_T constant1_Value;
  real_T constant2_Value_e;
  real_T f_Value_g;
  real_T constant_Value_l;
  real_T a_Value_f;
  real_T a1_Value_m;
  real_T Scalefactor1_Gain_a;
  real_T Scalefactor2_Gain;
  real_T Gain_Gain;
  real_T Saturation_UpperSat;
  real_T Saturation_LowerSat;
  real_T Gain_Gain_j;
  real_T Saturation1_UpperSat;
  real_T Saturation1_LowerSat;
  real_T Deg2Rad_Gain;
  real_T Gain_Gain_m;
  real_T Scalefactor1_Gain_l;
  real_T Scalefactor2_Gain_b;
  real_T Deg2Rad_Gain_c;
  real_T Gain_Gain_f;
  real_T Gain2_Gain;
  real_T Gain2_Gain_l;
  real_T Gain2_Gain_o;
  real_T Gain_Gain_p;
  real_T Gain1_Gain;
  real_T Memory1_14_InitialCondition;
  real_T Memory1_15_InitialCondition;
  real_T Memory1_8_InitialCondition;
  real_T Memory1_9_InitialCondition;
  int32_T UnitDelay_InitialCondition;
  int32_T Saturation2_LowerSat;
  int32_T Saturation2_LowerSat_e;
  int32_T Saturation2_LowerSat_n;
  int32_T Saturation2_LowerSat_a;
  int32_T Saturation2_LowerSat_d;
  int32_T Saturation2_LowerSat_i;
  int32_T Saturation2_LowerSat_k;
  int32_T Saturation_UpperSat_d;
  int32_T Saturation_LowerSat_m;
  int32_T Saturation_UpperSat_k;
  int32_T Saturation_LowerSat_b;
  int32_T Gain1_Gain_k;
  real32_T Gyro_Rotation4_Value[9];
  real32_T gyro_bias_body_Y0;
  real32_T DiscreteTimeIntegrator_gainval;
  real32_T Gain_Gain_g;
  real32_T acc_bias_body_Y0;
  real32_T DiscreteTimeIntegrator_gainva_n;
  real32_T Gain_Gain_c;
  real32_T gyro_bias_body_Y0_c;
  real32_T DiscreteTimeIntegrator_gainva_p;
  real32_T Gain_Gain_k;
  real32_T y_Y0[3];
  real32_T Memory_InitialCondition;
  real32_T Constant_Value[4];
  real32_T Constant_Value_m;
  real32_T Gain_Gain_i;
  real32_T Gain1_Gain_m;
  real32_T Constant2_Value[2];
  real32_T Constant1_Value;
  real32_T Constant_Value_d;
  real32_T Gain_Gain_l;
  real32_T Gain1_Gain_l;
  real32_T Gain3_Gain;
  real32_T Gain4_Gain;
  real32_T Constant2_Value_l[2];
  real32_T Constant1_Value_g;
  real32_T Constant_Value_l;
  real32_T Gain_Gain_b;
  real32_T Gain1_Gain_mu;
  real32_T Gain2_Gain_k;
  real32_T Gain3_Gain_l;
  real32_T Constant2_Value_d[2];
  real32_T Constant1_Value_e;
  real32_T Constant_Value_k;
  real32_T Gain_Gain_k1;
  real32_T Gain1_Gain_g;
  real32_T Gain2_Gain_of;
  real32_T Gain3_Gain_e;
  real32_T Constant2_Value_f;
  real32_T Out1_Y0_i;
  real32_T Gain2_Gain_ll;
  real32_T Gain1_Gain_my;
  real32_T Constant_Value_kp;
  real32_T p_ref_Y0;
  real32_T dh_dp_Y0;
  real32_T Constant2_Value_m;
  real32_T Memory_InitialCondition_i;
  real32_T Memory1_InitialCondition;
  real32_T Saturation_UpperSat_g;
  real32_T Saturation_LowerSat_l;
  real32_T g_M_d_R_Gain;
  real32_T Constant7_Value;
  real32_T Constant5_Value;
  real32_T Memory1_1_InitialCondition;
  real32_T DiscreteTimeIntegrator2_gainval;
  real32_T DiscreteTimeIntegrator2_IC;
  real32_T Discrete_Time_Integrator_gainva;
  real32_T Discrete_Time_Integrator_IC;
  real32_T Discrete_Time_Integrator_UpperS;
  real32_T Discrete_Time_Integrator_LowerS;
  real32_T DiscreteTimeIntegrator2_gainv_p;
  real32_T DiscreteTimeIntegrator2_IC_a;
  real32_T DiscreteTimeIntegrator2_gainv_g;
  real32_T DiscreteTimeIntegrator2_IC_h;
  real32_T DiscreteTimeIntegrator2_gainv_c;
  real32_T DiscreteTimeIntegrator2_IC_l;
  real32_T DiscreteTimeIntegrator_gainva_k;
  real32_T DiscreteTimeIntegrator_IC;
  real32_T DiscreteTimeIntegrator_gainv_pm;
  real32_T DiscreteTimeIntegrator_IC_b;
  real32_T DiscreteTimeIntegrator2_gainv_b;
  real32_T DiscreteTimeIntegrator2_IC_d;
  real32_T DiscreteTimeIntegrator2_gain_cx;
  real32_T DiscreteTimeIntegrator2_IC_dc;
  real32_T DiscreteTimeIntegrator2_gainv_o;
  real32_T DiscreteTimeIntegrator2_IC_e;
  real32_T DiscreteTimeIntegrator2_gainv_h;
  real32_T DiscreteTimeIntegrator2_IC_le;
  real32_T DiscreteTimeIntegrator1_gainval;
  real32_T DiscreteTimeIntegrator1_IC;
  real32_T Delay7_InitialCondition;
  real32_T Gyro_ScaleFactor1_Value[3];
  real32_T Delay_InitialCondition;
  real32_T Gyro_Rotation2_Value[9];
  real32_T Gyro_ScaleFactor_Value[3];
  real32_T DiscreteTimeIntegrator2_gainv_i;
  real32_T DiscreteTimeIntegrator2_IC_ed;
  real32_T DiscreteTimeIntegrator2_gainv_f;
  real32_T DiscreteTimeIntegrator2_IC_h2;
  real32_T DiscreteTimeIntegrator2_gain_b3;
  real32_T DiscreteTimeIntegrator2_IC_ak;
  real32_T DiscreteTimeIntegrator2_gain_bf;
  real32_T DiscreteTimeIntegrator2_IC_n;
  real32_T DiscreteTimeIntegrator2_gain_g4;
  real32_T DiscreteTimeIntegrator2_IC_b;
  real32_T DiscreteTimeIntegrator_gainva_m;
  real32_T DiscreteTimeIntegrator_IC_o;
  real32_T DiscreteTimeIntegrator2_gainv_e;
  real32_T DiscreteTimeIntegrator2_IC_g;
  real32_T DiscreteTimeIntegrator2_gainv_l;
  real32_T DiscreteTimeIntegrator2_IC_k;
  real32_T DiscreteTimeIntegrator2_gain_p1;
  real32_T DiscreteTimeIntegrator2_IC_c;
  real32_T DiscreteTimeIntegrator2_gainv_n;
  real32_T DiscreteTimeIntegrator2_IC_cy;
  real32_T DiscreteTimeIntegrator3_gainval;
  real32_T DiscreteTimeIntegrator3_IC;
  real32_T Acc_ScaleFactor1_Value[3];
  real32_T Delay9_InitialCondition;
  real32_T Accel_Rotation5_Value[9];
  real32_T Acc_ScaleFactor_Value[3];
  real32_T Memory_95_InitialCondition;
  real32_T Gain3_Gain_l1;
  real32_T Constant1_Value_i;
  real32_T Mag_ScaleFactor_Value;
  real32_T Constant2_Value_b;
  real32_T Gain1_Gain_a;
  real32_T Gain2_Gain_ol;
  real32_T Constant1_Value_ij;
  real32_T Nominal_Magnitude_Value;
  real32_T Saturation1_UpperSat_j;
  real32_T Saturation1_LowerSat_a;
  real32_T Constant3_Value;
  real32_T DiscreteTimeIntegrator1_gainv_g;
  real32_T DiscreteTimeIntegrator1_IC_p;
  real32_T Memory_101_InitialCondition;
  real32_T Scalefactor5_Gain;
  real32_T DiscreteTimeIntegrator1_gainv_p;
  real32_T Switch_Threshold;
  real32_T Memory_118_InitialCondition;
  real32_T DiscreteTimeIntegrator5_gainval;
  real32_T DiscreteTimeIntegrator5_IC;
  real32_T DiscreteTimeIntegrator5_gainv_d;
  real32_T DiscreteTimeIntegrator5_IC_o;
  real32_T DiscreteTimeIntegrator_gainva_e;
  real32_T DiscreteTimeIntegrator_IC_g;
  real32_T DiscreteTimeIntegrator5_gainv_e;
  real32_T DiscreteTimeIntegrator5_IC_f;
  real32_T Delay_InitialCondition_b;
  real32_T DiscreteTimeIntegrator5_gainv_g;
  real32_T Gain2_Gain_b;
  real32_T DiscreteTimeIntegrator5_gainv_c;
  real32_T DiscreteTimeIntegrator5_gainv_a;
  real32_T DiscreteTimeIntegrator5_IC_g;
  real32_T DiscreteTimeIntegrator5_gain_ax;
  real32_T DiscreteTimeIntegrator5_IC_b;
  real32_T Delay1_InitialCondition;
  real32_T DiscreteTimeIntegrator1_gainv_h;
  real32_T DiscreteTimeIntegrator1_IC_c;
  real32_T DiscreteTimeIntegrator_gainva_c;
  real32_T DiscreteTimeIntegrator_IC_j;
  real32_T Delay_InitialCondition_h;
  real32_T Gain_Gain_a;
  real32_T Gain_Gain_ki;
  real32_T Gain_Gain_h;
  real32_T Gain_Gain_ar;
  real32_T Gain_Gain_ft;
  real32_T Gain_Gain_ap;
  real32_T Memory_97_InitialCondition;
  real32_T u80_InitialStates;
  real32_T u80_Coefficients[180];
  real32_T Saturation2_UpperSat;
  real32_T Saturation2_LowerSat_eg;
  real32_T Constant2_Value_c;
  real32_T Gain1_Gain_mp;
  real32_T Saturation5_UpperSat;
  real32_T Saturation5_LowerSat;
  real32_T Constant2_Value_e;
  real32_T DiscreteTimeIntegrator3_gainv_i;
  real32_T DiscreteTimeIntegrator3_IC_f;
  real32_T Switch1_Threshold;
  real32_T DiscreteTimeIntegrator1_gainv_e;
  real32_T Saturation1_UpperSat_m;
  real32_T Saturation1_LowerSat_k;
  real32_T Delay_118_InitialCondition;
  real32_T DiscreteTimeIntegrator_gainva_o;
  real32_T DiscreteTimeIntegrator_IC_e;
  real32_T Delay2_InitialCondition;
  real32_T Gain_Gain_apa;
  real32_T Constant1_Value_f;
  real32_T Gain2_Gain_op;
  real32_T Saturation1_UpperSat_k;
  real32_T Saturation1_LowerSat_e;
  real32_T Gain8_Gain;
  real32_T Scalefactor6_Gain;
  real32_T UnitDelay_3_InitialCondition;
  real32_T Constant_Value_e[3];
  real32_T Gain_Gain_o;
  real32_T Saturation_UpperSat_de;
  real32_T Saturation_LowerSat_p;
  real32_T DiscreteTimeIntegrator5_gainv_o;
  real32_T Saturation1_UpperSat_e;
  real32_T Saturation1_LowerSat_n;
  real32_T Constant_Value_d0[3];
  real32_T Gain1_Gain_k4;
  real32_T Saturation_UpperSat_p;
  real32_T Saturation_LowerSat_n;
  real32_T DiscreteTimeIntegrator5_gain_gu;
  real32_T Saturation1_UpperSat_h;
  real32_T Saturation1_LowerSat_km;
  real32_T Gain_Gain_e;
  real32_T Gain_Gain_hc;
  real32_T Gain_Gain_k3;
  real32_T Gain_Gain_kd;
  real32_T Gain_Gain_pz;
  real32_T Gain_Gain_ad;
  real32_T Gain_Gain_pi;
  real32_T Gain9_Gain;
  real32_T Gain10_Gain;
  real32_T Gain11_Gain;
  real32_T Delay_InitialCondition_bp;
  real32_T Delay_InitialCondition_i;
  real32_T Delay_InitialCondition_a;
  real32_T Gain1_Gain_mq;
  real32_T Mag_ScaleFactor_Value_l;
  real32_T Saturation_UpperSat_p4;
  real32_T Saturation_LowerSat_c;
  real32_T Gain3_Gain_i;
  real32_T Constant4_Value;
  real32_T Constant5_Value_n;
  real32_T constant1_Value_c;
  real32_T Scalefactor4_Gain;
  real32_T Scalefactor3_Gain;
  real32_T Constant_Value_eb;
  real32_T Gain1_Gain_j;
  real32_T Saturation_UpperSat_e;
  real32_T Saturation_LowerSat_o;
  real32_T DiscreteTimeIntegrator5_gainv_f;
  real32_T Saturation1_UpperSat_f;
  real32_T Saturation1_LowerSat_f;
  real32_T Constant1_Value_f2;
  real32_T Constant2_Value_k;
  real32_T deg2rad_Gain;
  real32_T Memory1_InitialCondition_g;
  real32_T DiscreteTimeIntegrator5_gainv_p;
  real32_T Constant_Value_p[9];
  real32_T Constant_Value_f;
  real32_T Gain_Gain_lv;
  real32_T Constant3_Value_o;
  real32_T Gain_Gain_m5;
  real32_T Gain1_Gain_ge;
  real32_T Constant1_Value_b;
  real32_T Gain2_Gain_a;
  real32_T Constant2_Value_er;
  real32_T Constant1_Value_c;
  real32_T Switch_Threshold_p;
  real32_T Gain4_Gain_n;
  real32_T Gain6_Gain;
  real32_T Gain7_Gain;
  real32_T Gain8_Gain_m;
  real32_T DiscreteTimeIntegrator_gainv_ka;
  real32_T DiscreteTimeIntegrator_IC_k;
  real32_T Gain1_Gain_f;
  real32_T Gain4_Gain_l;
  real32_T Gain5_Gain;
  real32_T Gain10_Gain_f;
  real32_T Gain11_Gain_k;
  real32_T Gain12_Gain;
  real32_T Gain13_Gain;
  real32_T Gain14_Gain;
  real32_T Gain15_Gain;
  real32_T Gain16_Gain;
  real32_T Gain17_Gain;
  real32_T Gain2_Gain_p;
  real32_T Gain3_Gain_d;
  real32_T Gain4_Gain_o;
  real32_T Gain5_Gain_p;
  real32_T Gain6_Gain_h;
  real32_T Gain7_Gain_a;
  real32_T Gain8_Gain_d;
  real32_T Gain11_Gain_h;
  real32_T Gain10_Gain_h;
  real32_T DiscreteTimeIntegrator1_gainv_b;
  real32_T DiscreteTimeIntegrator1_IC_j;
  real32_T DiscreteTimeIntegrator_gainva_j;
  real32_T DiscreteTimeIntegrator_IC_h;
  real32_T Gain1_Gain_fo;
  real32_T Gain_Gain_cx;
  real32_T Memory1_10_InitialCondition;
  real32_T Memory1_2_InitialCondition;
  real32_T Memory1_3_InitialCondition;
  real32_T Memory1_4_InitialCondition;
  real32_T Memory1_5_InitialCondition;
  real32_T Memory1_6_InitialCondition;
  real32_T Memory1_7_InitialCondition;
  real32_T Constant3_Value_a;
  real32_T DiscreteTimeIntegrator_gainv_jc;
  real32_T DiscreteTimeIntegrator_IC_m;
  real32_T Gain1_Gain_i;
  real32_T Constant7_Value_j;
  real32_T Gain3_Gain_o;
  real32_T Saturation_UpperSat_kw;
  real32_T Saturation_LowerSat_k;
  real32_T DiscreteTimeIntegrator1_gainv_j;
  real32_T Gain_Gain_am;
  real32_T Switch_Threshold_j;
  real32_T Constant_Value_lx;
  real32_T Constant_Value_a;
  real32_T Constant1_Value_ek;
  real32_T DiscreteTimeIntegrator2_gain_ll;
  real32_T DiscreteTimeIntegrator2_IC_au;
  real32_T DiscreteTimeIntegrator_gainv_ol;
  real32_T DiscreteTimeIntegrator_IC_n;
  real32_T DiscreteTimeIntegrator_UpperSat;
  real32_T DiscreteTimeIntegrator_LowerSat;
  real32_T Delay8_InitialCondition;
  real32_T Delay2_InitialCondition_c;
  real32_T Delay3_InitialCondition;
  real32_T DiscreteTimeIntegrator_gainva_g;
  real32_T DiscreteTimeIntegrator_IC_mz;
  real32_T DiscreteTimeIntegrator_UpperS_l;
  real32_T DiscreteTimeIntegrator_LowerS_a;
  real32_T DiscreteTimeIntegrator_gainv_p5;
  real32_T DiscreteTimeIntegrator_IC_b3;
  real32_T DiscreteTimeIntegrator_UpperS_k;
  real32_T DiscreteTimeIntegrator_LowerS_g;
  real32_T Delay6_InitialCondition;
  real32_T Constant_Value_b;
  real32_T Constant_Value_bu;
  real32_T Constant2_Value_fo;
  real32_T Constant3_Value_i;
  real32_T Constant6_Value;
  real32_T Constant7_Value_a;
  real32_T Constant4_Value_f;
  real32_T Constant4_Value_e;
  real32_T Constant4_Value_h;
  real32_T Constant4_Value_i;
  real32_T Constant4_Value_l;
  real32_T Constant4_Value_h0;
  real32_T Constant4_Value_k;
  real32_T Constant4_Value_c;
  real32_T Constant4_Value_fr;
  real32_T Constant4_Value_a;
  real32_T Constant4_Value_n;
  real32_T Constant4_Value_kq;
  real32_T Constant4_Value_cc;
  real32_T Constant4_Value_lf;
  real32_T Constant4_Value_g;
  real32_T Constant4_Value_h4;
  real32_T Constant4_Value_m;
  real32_T Constant_Value_kf;
  real32_T Constant_Value_d0g;
  real32_T Constant_Value_pz;
  real32_T Constant_Value_pm;
  real32_T Switch_Threshold_e;
  real32_T Merge_InitialOutput[4];
  real32_T Gain1_Gain_c[3];
  real32_T Gain2_Gain_ld[2];
  real32_T Gain3_Gain_g[2];
  real32_T Gain_Gain_d;
  real32_T Switch_Threshold_jn;
  real32_T Constant2_Value_j;
  real32_T Constant3_Value_e;
  real32_T Constant4_Value_j;
  real32_T Constant4_Value_hu;
  real32_T Gain2_Gain_c;
  real32_T DiscreteTimeIntegrator5_gainv_m;
  real32_T DiscreteTimeIntegrator5_IC_k;
  real32_T Gain2_Gain_kj;
  real32_T Gain2_Gain_ab;
  real32_T DiscreteTimeIntegrator5_gain_ct;
  real32_T DiscreteTimeIntegrator5_IC_gn;
  real32_T Gain2_Gain_kd;
  real32_T Gain2_Gain_m;
  real32_T DiscreteTimeIntegrator5_gain_el;
  real32_T DiscreteTimeIntegrator5_IC_a;
  real32_T Gain2_Gain_h;
  real32_T Gain2_Gain_ml;
  real32_T Gain2_Gain_mf;
  real32_T Delay2_InitialCondition_o;
  real32_T Delay5_InitialCondition;
  real32_T Delay4_InitialCondition;
  real32_T Delay3_InitialCondition_k;
  real32_T Switch_Threshold_c;
  real32_T Constant_Value_n;
  real32_T Gain2_Gain_d;
  real32_T Gain2_Gain_kt;
  real32_T Constant_Value_h;
  real32_T Constant1_Value_o;
  real32_T Constant2_Value_db;
  real32_T Gain2_Gain_ks;
  real32_T Constant_Value_j;
  uint32_T Gain_Gain_do;
  uint32_T Constant1_Value_n;
  uint32_T Memory2_InitialCondition;
  uint32_T Saturation1_UpperSat_o;
  uint32_T Saturation1_LowerSat_o;
  uint32_T Delay4_DelayLength;
  uint32_T Delay_DelayLength;
  uint32_T Delay7_DelayLength;
  uint32_T Delay_DelayLength_m;
  uint32_T Delay_DelayLength_f;
  uint32_T Delay9_DelayLength;
  uint32_T DiscreteTimeIntegrator_IC_p;
  uint32_T DiscreteTimeIntegrator_IC_i;
  uint32_T DiscreteTimeIntegrator_IC_nk;
  uint32_T DiscreteTimeIntegrator_IC_mi;
  uint32_T Delay_DelayLength_f3;
  uint32_T Delay_DelayLength_p;
  uint32_T Delay_DelayLength_e;
  uint32_T Delay1_DelayLength;
  uint32_T Delay_DelayLength_a;
  uint32_T Delay_118_DelayLength;
  uint32_T Delay_DelayLength_j;
  uint32_T Delay1_DelayLength_i;
  uint32_T Delay2_DelayLength;
  uint32_T Delay10_DelayLength;
  uint32_T Memory2_InitialCondition_p;
  uint32_T Constant_Value_kd;
  uint32_T DiscreteTimeIntegrator_IC_pv;
  uint32_T DiscreteTimeIntegrator_IC_iz;
  uint32_T DiscreteTimeIntegrator_IC_gq;
  uint32_T DiscreteTimeIntegrator1_IC_k;
  uint32_T DiscreteTimeIntegrator2_IC_gc;
  uint32_T Delay_DelayLength_c;
  uint32_T Delay_DelayLength_jw;
  uint32_T Delay_DelayLength_l;
  uint32_T Delay3_DelayLength;
  uint32_T DiscreteTimeIntegrator_IC_l;
  uint32_T Delay8_DelayLength;
  uint32_T Delay1_DelayLength_b;
  uint32_T Delay2_DelayLength_j;
  uint32_T Delay3_DelayLength_b;
  uint32_T Delay4_DelayLength_p;
  uint32_T Delay6_DelayLength;
  uint32_T Delay5_DelayLength;
  uint32_T Delay2_DelayLength_b;
  uint32_T Delay5_DelayLength_e;
  uint32_T Delay4_DelayLength_o;
  uint32_T Delay3_DelayLength_n;
  int16_T Gain_Gain_bf;
  int16_T Gain9_Gain_b;
  int16_T Gain2_Gain_g;
  int16_T Gain13_Gain_j;
  uint16_T Saturation7_UpperSat;
  uint16_T Saturation7_LowerSat;
  uint16_T Gain1_Gain_kj;
  uint16_T Gain4_Gain_d;
  uint16_T Constant_Value_i;
  boolean_T Delay4_InitialCondition_k;
  boolean_T Delay_InitialCondition_o;
  boolean_T Delay_InitialCondition_l;
  boolean_T Constant1_Value_p;
  boolean_T Memory_54_InitialCondition;
  boolean_T Delay_InitialCondition_bc;
  boolean_T Delay_InitialCondition_bd;
  boolean_T Memory_134_InitialCondition;
  boolean_T Constant_Value_jr;
  boolean_T Constant1_Value_k;
  boolean_T Constant4_Value_d;
  boolean_T Constant1_Value_m;
  boolean_T Delay_InitialCondition_lq;
  boolean_T Delay1_InitialCondition_m;
  boolean_T Delay10_InitialCondition;
  boolean_T UnitDelay_1_InitialCondition;
  boolean_T Constant_Value_fs;
  boolean_T Constant_Value_c;
  boolean_T Constant_Value_h1;
  boolean_T Constant5_Value_m;
  boolean_T Memory1_12_InitialCondition;
  boolean_T Memory1_13_InitialCondition;
  boolean_T Constant5_Value_nm;
  boolean_T Constant7_Value_p;
  boolean_T Constant3_Value_n;
  boolean_T Delay3_InitialCondition_l;
  boolean_T Memory1_11_InitialCondition;
  int8_T Constant5_Value_me;
  int8_T Constant4_Value_cr;
  int8_T Constant2_Value_dg;
  int8_T Constant1_Value_l;
  int8_T Constant_Value_fc;
  int8_T Constant1_Value_me;
  uint8_T Gain2_Gain_f;
  uint8_T Gain3_Gain_f;
  uint8_T Gain1_Gain_ms;
  uint8_T Gain2_Gain_lg;
  uint8_T Gain1_Gain_ga;
  uint8_T Gain_Gain_pz2;
  uint8_T Gain12_Gain_m;
  uint8_T Gain_Gain_e4;
  uint8_T Constant1_Value_bm;
  uint8_T Constant_Value_g;
  uint8_T Constant_Value_en;
  uint8_T Constant_Value_ej;
  uint8_T Constant_Value_ch;
  P_IfWarningError_xstar_fcs_T IfWarningError_n;
  P_IfWarningError_xstar_fcs_T IfWarningError;
};

typedef struct P_xstar_fcs_T_ P_xstar_fcs_T;
struct tag_RTM_xstar_fcs_T {
  const char_T *errorStatus;
};

extern P_xstar_fcs_T xstar_fcs_P;
extern B_xstar_fcs_T xstar_fcs_B;
extern DW_xstar_fcs_T xstar_fcs_DW;
extern ExtU_xstar_fcs_T xstar_fcs_U;
extern ExtY_xstar_fcs_T xstar_fcs_Y;
extern boolean_T rtP_eso_log_on;
extern SCAL_PARAMS PARAMS;
extern void xstar_fcs_initialize(void);
extern void xstar_fcs_step(void);
extern void xstar_fcs_terminate(void);
extern RT_MODEL_xstar_fcs_T *const xstar_fcs_M;

#endif

