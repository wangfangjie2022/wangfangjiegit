#ifndef RTW_HEADER_Translation_Fusion_h_
#define RTW_HEADER_Translation_Fusion_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"
#include <math.h>
#include <string.h>
#ifndef Translation_Fusion_COMMON_INCLUDES_
# define Translation_Fusion_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#endif

#include "multiword_types.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include "mw_cmsis.h"
#include "rtGetInf.h"

typedef struct tag_RTM_Translation_Fusion_T RT_MODEL_Translation_Fusion_T;

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

#ifndef typedef_cell_wrap_Translation_Fusion_T
#define typedef_cell_wrap_Translation_Fusion_T

typedef struct {
  uint32_T f1[8];
} cell_wrap_Translation_Fusion_T;

#endif

#ifndef typedef_dsp_simulink_MovingAverage_Tr_T
#define typedef_dsp_simulink_MovingAverage_Tr_T

typedef struct {
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  boolean_T TunablePropsChanged;
  cell_wrap_Translation_Fusion_T inputVarSize;
  dsp_private_SlidingWindowAver_T *pStatistic;
  int32_T NumChannels;
} dsp_simulink_MovingAverage_Tr_T;

#endif

#ifndef typedef_dsp_private_SlidingWindowAv_h_T
#define typedef_dsp_private_SlidingWindowAv_h_T

typedef struct {
  int32_T isInitialized;
  boolean_T isSetupComplete;
  real32_T pCumSum;
  real32_T pCumSumRev[9];
  real32_T pCumRevIndex;
} dsp_private_SlidingWindowAv_h_T;

#endif

#ifndef typedef_dsp_simulink_MovingAverage_e_T
#define typedef_dsp_simulink_MovingAverage_e_T

typedef struct {
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  boolean_T TunablePropsChanged;
  cell_wrap_Translation_Fusion_T inputVarSize;
  dsp_private_SlidingWindowAv_h_T *pStatistic;
  int32_T NumChannels;
} dsp_simulink_MovingAverage_e_T;

#endif

#ifndef typedef_dsp_private_SlidingWindowA_hg_T
#define typedef_dsp_private_SlidingWindowA_hg_T

typedef struct {
  int32_T isInitialized;
  boolean_T isSetupComplete;
  real32_T pCumSum;
  real32_T pCumSumRev[41];
  real32_T pCumRevIndex;
} dsp_private_SlidingWindowA_hg_T;

#endif

#ifndef typedef_dsp_simulink_MovingAverage_e3_T
#define typedef_dsp_simulink_MovingAverage_e3_T

typedef struct {
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  boolean_T TunablePropsChanged;
  cell_wrap_Translation_Fusion_T inputVarSize;
  dsp_private_SlidingWindowA_hg_T *pStatistic;
  int32_T NumChannels;
} dsp_simulink_MovingAverage_e3_T;

#endif

#ifndef typedef_dsp_private_SlidingWindow_hgv_T
#define typedef_dsp_private_SlidingWindow_hgv_T

typedef struct {
  int32_T isInitialized;
  boolean_T isSetupComplete;
  real32_T pCumSum;
  real32_T pCumSumRev[7];
  real32_T pCumRevIndex;
} dsp_private_SlidingWindow_hgv_T;

#endif

#ifndef typedef_dsp_simulink_MovingAverag_e3x_T
#define typedef_dsp_simulink_MovingAverag_e3x_T

typedef struct {
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  boolean_T TunablePropsChanged;
  cell_wrap_Translation_Fusion_T inputVarSize;
  dsp_private_SlidingWindow_hgv_T *pStatistic;
  int32_T NumChannels;
} dsp_simulink_MovingAverag_e3x_T;

#endif

#ifndef typedef_dsp_private_SlidingWindo_hgvz_T
#define typedef_dsp_private_SlidingWindo_hgvz_T

typedef struct {
  int32_T isInitialized;
  boolean_T isSetupComplete;
  real32_T pCumSum;
  real32_T pCumSumRev[39];
  real32_T pCumRevIndex;
} dsp_private_SlidingWindo_hgvz_T;

#endif

#ifndef typedef_dsp_simulink_MovingAvera_e3xk_T
#define typedef_dsp_simulink_MovingAvera_e3xk_T

typedef struct {
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  boolean_T TunablePropsChanged;
  cell_wrap_Translation_Fusion_T inputVarSize;
  dsp_private_SlidingWindo_hgvz_T *pStatistic;
  int32_T NumChannels;
} dsp_simulink_MovingAvera_e3xk_T;

#endif

#ifndef typedef_dsp_private_SlidingWind_hgvzv_T
#define typedef_dsp_private_SlidingWind_hgvzv_T

typedef struct {
  int32_T isInitialized;
  boolean_T isSetupComplete;
  real32_T pCumSum;
  real32_T pCumSumRev[99];
  real32_T pCumRevIndex;
} dsp_private_SlidingWind_hgvzv_T;

#endif

#ifndef typedef_dsp_simulink_MovingAver_e3xkx_T
#define typedef_dsp_simulink_MovingAver_e3xkx_T

typedef struct {
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  boolean_T TunablePropsChanged;
  cell_wrap_Translation_Fusion_T inputVarSize;
  dsp_private_SlidingWind_hgvzv_T *pStatistic;
  int32_T NumChannels;
} dsp_simulink_MovingAver_e3xkx_T;

#endif

#ifndef typedef_dsp_private_SlidingWin_hgvzvy_T
#define typedef_dsp_private_SlidingWin_hgvzvy_T

typedef struct {
  int32_T isInitialized;
  boolean_T isSetupComplete;
  real32_T pCumSum;
  real32_T pCumSumRev[401];
  real32_T pCumRevIndex;
} dsp_private_SlidingWin_hgvzvy_T;

#endif

#ifndef typedef_dsp_private_SlidingWi_hgvzvyp_T
#define typedef_dsp_private_SlidingWi_hgvzvyp_T

typedef struct {
  int32_T isInitialized;
  boolean_T isSetupComplete;
  real32_T pCumSum;
  real32_T pCumSumRev[3];
  real32_T pCumRevIndex;
} dsp_private_SlidingWi_hgvzvyp_T;

#endif

#ifndef typedef_dsp_simulink_MovingAve_e3xkxm_T
#define typedef_dsp_simulink_MovingAve_e3xkxm_T

typedef struct {
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  boolean_T TunablePropsChanged;
  cell_wrap_Translation_Fusion_T inputVarSize;
  dsp_private_SlidingWin_hgvzvy_T *pStatistic;
  int32_T NumChannels;
} dsp_simulink_MovingAve_e3xkxm_T;

#endif

#ifndef typedef_dsp_simulink_MovingAv_e3xkxms_T
#define typedef_dsp_simulink_MovingAv_e3xkxms_T

typedef struct {
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  boolean_T TunablePropsChanged;
  cell_wrap_Translation_Fusion_T inputVarSize;
  dsp_private_SlidingWi_hgvzvyp_T *pStatistic;
  int32_T NumChannels;
} dsp_simulink_MovingAv_e3xkxms_T;

#endif

#ifndef Translation_Fusion_MDLREF_HIDE_CHILD_

typedef struct {
  real32_T csumrev[19];
  real32_T MovingAverage2;
} B_MovingAverage2_Translation__T;

#endif

#ifndef Translation_Fusion_MDLREF_HIDE_CHILD_

typedef struct {
  dsp_private_SlidingWindowAver_T gobj_0;
  dsp_private_SlidingWindowAver_T gobj_1;
  dsp_simulink_MovingAverage_Tr_T obj;
  boolean_T objisempty;
} DW_MovingAverage2_Translation_T;

#endif

#ifndef Translation_Fusion_MDLREF_HIDE_CHILD_

typedef struct {
  real32_T Average;
} B_Average_Translation_Fusion_T;

#endif

#ifndef Translation_Fusion_MDLREF_HIDE_CHILD_

typedef struct {
  dsp_simulink_MovingAverage_e_T obj;
  dsp_private_SlidingWindowAv_h_T gobj_0;
  dsp_private_SlidingWindowAv_h_T gobj_1;
  boolean_T objisempty;
} DW_Average_Translation_Fusion_T;

#endif

#ifndef Translation_Fusion_MDLREF_HIDE_CHILD_

typedef struct {
  real32_T Multiply5[9];
  real32_T fv0[9];
  real32_T Multiply1[6];
  real32_T rtb_Multiply1_tmp[6];
  real32_T rtu_H[6];
  real32_T rtu_H_m[4];
  real32_T Multiply[3];
} B_Correct_x_Translation_Fusio_T;

#endif

#ifndef Translation_Fusion_MDLREF_HIDE_CHILD_

typedef struct {
  real32_T MatrixInverse_DWORK4[4];
} DW_Correct_x_Translation_Fusi_T;

#endif

#ifndef Translation_Fusion_MDLREF_HIDE_CHILD_

typedef struct {
  real32_T csumrev[41];
  real32_T Average;
} B_Average_Translation_Fusio_c_T;

#endif

#ifndef Translation_Fusion_MDLREF_HIDE_CHILD_

typedef struct {
  dsp_private_SlidingWindowA_hg_T gobj_0;
  dsp_private_SlidingWindowA_hg_T gobj_1;
  dsp_simulink_MovingAverage_e3_T obj;
  boolean_T objisempty;
} DW_Average_Translation_Fusi_f_T;

#endif

#ifndef Translation_Fusion_MDLREF_HIDE_CHILD_

typedef struct {
  real32_T Multiply5[9];
  real32_T fv0[9];
  real32_T Multiply[3];
} B_Correct_x_Translation_Fus_h_T;

#endif

#ifndef Translation_Fusion_MDLREF_HIDE_CHILD_

typedef struct {
  real32_T MatrixInverse_DWORK4;
} DW_Correct_x_Translation_Fu_p_T;

#endif

#ifndef Translation_Fusion_MDLREF_HIDE_CHILD_

typedef struct {
  real32_T Multiply5[9];
  real32_T fv0[9];
  real32_T Multiply[3];
} B_Correct_y_Translation_Fusio_T;

#endif

#ifndef Translation_Fusion_MDLREF_HIDE_CHILD_

typedef struct {
  real32_T MatrixInverse_DWORK4;
} DW_Correct_y_Translation_Fusi_T;

#endif

#ifndef Translation_Fusion_MDLREF_HIDE_CHILD_

typedef struct {
  real32_T Multiply5[9];
  real32_T fv0[9];
  real32_T Multiply[3];
} B_Correct_x_Translation_Fus_o_T;

#endif

#ifndef Translation_Fusion_MDLREF_HIDE_CHILD_

typedef struct {
  real32_T MatrixInverse_DWORK4;
} DW_Correct_x_Translation_F_pb_T;

#endif

#ifndef Translation_Fusion_MDLREF_HIDE_CHILD_

typedef struct {
  real32_T MovingAverage3;
} B_MovingAverage3_Translation__T;

#endif

#ifndef Translation_Fusion_MDLREF_HIDE_CHILD_

typedef struct {
  dsp_simulink_MovingAverag_e3x_T obj;
  dsp_private_SlidingWindow_hgv_T gobj_0;
  dsp_private_SlidingWindow_hgv_T gobj_1;
  boolean_T objisempty;
} DW_MovingAverage3_Translation_T;

#endif

#ifndef Translation_Fusion_MDLREF_HIDE_CHILD_

typedef struct {
  real32_T csumrev[39];
  real32_T MovingAverage1;
} B_MovingAverage1_Translation__T;

#endif

#ifndef Translation_Fusion_MDLREF_HIDE_CHILD_

typedef struct {
  dsp_private_SlidingWindo_hgvz_T gobj_0;
  dsp_private_SlidingWindo_hgvz_T gobj_1;
  dsp_simulink_MovingAvera_e3xk_T obj;
  boolean_T objisempty;
} DW_MovingAverage1_Translation_T;

#endif

#ifndef Translation_Fusion_MDLREF_HIDE_CHILD_

typedef struct {
  real32_T csumrev[99];
  real32_T MovingAverage1;
} B_MovingAverage1_Translatio_c_T;

#endif

#ifndef Translation_Fusion_MDLREF_HIDE_CHILD_

typedef struct {
  dsp_private_SlidingWind_hgvzv_T gobj_0;
  dsp_private_SlidingWind_hgvzv_T gobj_1;
  dsp_simulink_MovingAver_e3xkx_T obj;
  boolean_T objisempty;
} DW_MovingAverage1_Translati_f_T;

#endif

#ifndef Translation_Fusion_MDLREF_HIDE_CHILD_

typedef struct {
  real32_T csumrev[401];
  real32_T csumrev_m[99];
  real32_T P_RTK[36];
  real32_T v1[36];
  real32_T P_Kalman[36];
  real32_T CreateDiagonalMatrix_j[36];
  real_T VectorConcatenate[9];
  real32_T MatrixMultiply4_l[16];
  real32_T MathFunction_ej[16];
  real32_T rtb_MatrixMultiply4_l_c[16];
  real32_T rtb_Selector12_k[16];
  real32_T IdentityMatrix[9];
  real32_T IdentityMatrix_j[9];
  real32_T v1_c[9];
  real32_T Product_i[9];
  real32_T MatrixMultiply4_n[9];
  real32_T Subtract_ia[9];
  real32_T rtb_Product_i_b[9];
  real32_T rtb_TmpSignalConversionAtMult_p[9];
  real32_T Selector12[8];
  real32_T rtb_P_Kalman_c[8];
  real_T rtb_VectorConcatenate_f[3];
  real32_T X_Cor_RTK_k[6];
  real32_T IdentityMatrix_k[16];
  real32_T P[16];
  real32_T ManualSwitch[6];
  real32_T Assignment[6];
  real32_T Selector_ai[6];
  real32_T MatrixMultiply1[4];
  real32_T IdentityMatrix_f[16];
  real32_T Add[16];
  real32_T MatrixMultiply1_j[4];
  real32_T Switch2_e[4];
  real32_T CreateDiagonalMatrix[4];
  real32_T Subtract1_k[4];
  real32_T Selector13[4];
  real32_T CreateDiagonalMatrix_jk[4];
  real32_T Product_nu[4];
  real32_T Subtract1_c[4];
  real32_T CreateDiagonalMatrix_n[4];
  real32_T fv0[4];
  real32_T fv1[4];
  real32_T Gain_h2[4];
  real32_T X_Cor_RTK[3];
  real32_T Add_k[3];
  real32_T IdentityMatrix_i[9];
  real32_T Add_p[9];
  real32_T Add_c[3];
  real32_T MatrixMultiply4_a[3];
  real32_T TmpSignalConversionAtMultip[3];
  real32_T sfor_R_O_mDs2[3];
  real32_T Delay1_f[3];
  real32_T DiscreteTimeIntegrator1_ek[3];
  real32_T Switch_d[3];
  real32_T Switch2_pu[3];
  real32_T rtu_Sensor_RTK_Data_vel_N[3];
  real32_T Add_k_g[3];
  real32_T DiscreteTimeIntegrator_d[3];
  real_T rtb_WGS84_derivatives_g;
  real_T rtb_DataTypeConversion3_g_m;
  real_T rtb_test1_k_idx_1;
  real_T rtb_WGS84_derivatives_idx_1;
  real_T rtb_WGS84_pos_ref_idx_1;
  real_T rtb_WGS84_derivatives_idx_0;
  real_T rtb_WGS84_pos_ref_idx_0;
  real_T rtb_WGS84_position_idx_1;
  real_T rtb_WGS84_position_idx_2;
  real_T rtb_DataTypeConversion3_g_idx_2;
  real_T rtb_DataTypeConversion3_g_idx_1;
  real_T rtb_WGS84_position_idx_0;
  real_T rtb_DataTypeConversion3_g_idx_0;
  real_T rtb_WGS84_pos_ref_idx_2;
  real_T rtb_test1_k_idx_0;
  real_T rtb_Saturation_fo_tmp;
  real_T rtb_VectorConcatenate_tmp;
  real32_T Min_h[2];
  real32_T vel_xy_GPS[2];
  real32_T DataTypeConversion4[2];
  real32_T DiscreteTimeIntegrator_gsh[2];
  real32_T rtb_DataTypeConversion4_n[2];
  real32_T DiscreteTimeIntegrator5;
  real32_T DiscreteTimeIntegrator5_h;
  real32_T Merge1[9];
  real32_T DiscreteTimeIntegrator5_h1;
  real32_T DiscreteTimeIntegrator5_i;
  real32_T Gain;
  real32_T IdentityMatrix_e[9];
  real32_T Add_m[9];
  real32_T bias_filtered;
  real32_T In1;
  real32_T MatrixMultiply3;
  real32_T IdentityMatrix_m[9];
  real32_T Add_d[9];
  real32_T Add_o[3];
  real32_T IdentityMatrix_kr[9];
  real32_T Add_pa[9];
  real32_T Add_pl[3];
  real32_T Multiply5[9];
  real32_T Multiply[3];
  real32_T IdentityMatrix_j3[9];
  real32_T Add_f[9];
  real32_T Add_cg[3];
  real32_T csum;
  real32_T Abs2;
  real32_T Abs1;
  real32_T DiscreteTimeIntegrator_ax;
  real32_T DiscreteTimeIntegrator_am;
  real32_T GPS_gain;
  real32_T Sum2;
  real32_T Switch4;
  real32_T DiscreteTimeIntegrator1_f5h;
  real32_T DiscreteTimeIntegrator_bj;
  real32_T Subtract1;
  real32_T Subtract2;
  real32_T Subtract3;
  real32_T DiscreteTimeIntegrator1_at;
  real32_T state;
  real32_T Switch1_k;
  real32_T DiscreteTimeIntegrator_jc;
  real32_T DiscreteTimeIntegrator_j;
  real32_T Gain1_p;
  real32_T Sum_d;
  real32_T DiscreteTimeIntegrator_b;
  real32_T Gain1_i;
  real32_T Gain_av;
  real32_T Product_c;
  real32_T Gain_by;
  real32_T Gain2;
  real32_T Gain2_l;
  real32_T Gain2_f;
  real32_T Gain2_ll;
  real32_T DiscreteTimeIntegrator_km;
  real32_T Gain1_l;
  real32_T Gain_gh;
  real32_T DiscreteTimeIntegrator_gf;
  real32_T Gain1_lg;
  real32_T Gain_nx;
  real32_T DiscreteTimeIntegrator_j1;
  real32_T Gain1_g;
  real32_T Gain_ce;
  real32_T Gain3;
  real32_T Gain3_m;
  real32_T DiscreteTimeIntegrator_n;
  real32_T Gain1_ol;
  real32_T Gain_nwa;
  real32_T Gain3_p;
  real32_T DiscreteTimeIntegrator_or;
  real32_T Gain1_e;
  real32_T Gain_pi;
  real32_T DiscreteTimeIntegrator_n5;
  real32_T Gain1_lx;
  real32_T Gain_cl;
  real32_T DiscreteTimeIntegrator_a1;
  real32_T Gain1_av;
  real32_T Gain_l;
  real32_T DiscreteTimeIntegrator_c;
  real32_T Gain1_at;
  real32_T Gain_lc;
  real32_T DiscreteTimeIntegrator_h;
  real32_T Gain1_la;
  real32_T Gain_go;
  real32_T Gain_b4;
  real32_T DiscreteTimeIntegrator1_p;
  real32_T DiscreteTimeIntegrator1_ox;
  real32_T DiscreteTimeIntegrator_po;
  real32_T Switch_i2;
  real32_T DiscreteTimeIntegrator_j1z;
  real32_T Sqrt;
  real32_T Sum3;
  real32_T Sum_ol;
  real32_T Add_kk;
  real32_T Add_ey;
  real32_T Add_b;
  real32_T baro_error_small;
  real32_T Relay;
  real32_T Relay_e;
  real32_T low_thr;
  real32_T middle_thr;
  real32_T Relay1;
  real32_T Relay1_a;
  real32_T Inverse_j;
  real32_T Inverse_h;
  real32_T rtb_DiscreteTimeIntegrator1_l_p;
  real32_T rtb_Switch_l_l;
  real32_T rtb_pos_xy_O_meas_RTK_j;
  real32_T rtb_DiscreteTimeIntegrator_p4_d;
  real32_T rtb_Sum_ec_g;
  real32_T rtb_DiscreteTimeIntegrator1_l_l;
  real32_T rtb_Pos_O_idx_1;
  real32_T rtb_Pos_O_idx_0;
  real32_T rtb_Vel_O_idx_1;
  real32_T rtb_Min_c_idx_0;
  real32_T rtb_Sum1_l_idx_1;
  real32_T rtb_Sum1_l_idx_0;
  real32_T rtb_Product_o_idx_1;
  real32_T rtb_Product_o_idx_0;
  real32_T rtb_DiscreteTimeIntegrator_p4_i;
  real32_T rtb_pos_xy_O_meas_RTK_idx_0;
  real32_T rtb_Sum_ec_idx_1;
  real32_T rtb_Sum_ec_idx_0;
  real32_T rtb_Int_X_idx_0;
  real32_T rtb_Int_X_idx_1;
  real32_T rtb_Int_X_idx_2;
  real32_T rtb_Int_X_idx_3;
  real32_T rtb_DiscreteTimeIntegrator1_lt_;
  real32_T rtb_Switch_l_idx_0;
  real32_T rtb_Transpose_h_idx_0;
  real32_T rtb_Transpose_h_idx_1;
  real32_T rtb_Gain1_o_idx_0;
  real32_T rtb_Gain_c_idx_0;
  real32_T rtb_Gain1_o_idx_1;
  real32_T rtb_Gain_c_idx_1;
  real32_T rtb_Min_l_idx_0;
  real32_T rtb_Min_l_idx_1;
  real32_T Subtract;
  real32_T r;
  real32_T t;
  int32_T DataTypeConversion_ly;
  int32_T DataTypeConversion_ew;
  int32_T DataTypeConversion_bx;
  int32_T DataTypeConversion_i;
  int32_T i;
  int32_T v1_tmp;
  int32_T rtb_GPS_gain_tmp;
  int32_T rtb_P_Kalman_tmp;
  int32_T P_RTK_tmp;
  uint32_T rtb_DataTypeConversion1_e_tmp;
  uint16_T Add1_p;
  uint8_T pos_valid;
  uint8_T Sum2_a;
  boolean_T LogicalOperator1;
  boolean_T Compare_i;
  boolean_T Compare_bnu;
  boolean_T Reset_TF;
  boolean_T rtk_pos_valid;
  boolean_T gps_pos_valid_mk;
  boolean_T Compare_fx;
  boolean_T Compare_e;
  boolean_T Compare_jn;
  boolean_T LogicalOperator_d;
  boolean_T Compare_n;
  boolean_T Compare_epn;
  boolean_T reset_ref;
  boolean_T GPS_Good;
  boolean_T LogicalOperator_l;
  boolean_T LogicalOperator3;
  boolean_T LogicalOperator4_a;
  boolean_T rtk_pos_valid_m;
  boolean_T LogicalOperator1_g;
  boolean_T LogicalOperator2_h;
  boolean_T rtk_pos_valid_h;
  boolean_T gps_pos_valid;
  boolean_T gps_pos_valid_m;
  boolean_T rtk_pos_valid_j;
  boolean_T LogicalOperator_m;
  boolean_T LogicalOperator_mw;
  boolean_T Compare_l0;
  boolean_T LogicalOperator_ok;
  boolean_T Compare_h;
  boolean_T LogicalOperator1_f;
  boolean_T Compare_o4;
  boolean_T FixPtRelationalOperator_k;
  boolean_T Compare_gj;
  boolean_T LogicalOperator1_k;
  boolean_T FixPtRelationalOperator_p;
  boolean_T RTK_Vel_good;
  boolean_T Over_15m;
  boolean_T Vision_bad;
  boolean_T Vision_Unvalid;
  boolean_T Switch1_ko;
  boolean_T DataTypeConversion1_p;
  boolean_T LogicalOperator_ob;
  boolean_T Compare_j;
  boolean_T Compare_k;
  boolean_T DataTypeConversion1_b;
  boolean_T LogicalOperator_i;
  boolean_T LogicalOperator2_g;
  boolean_T Compare_b5;
  boolean_T DataTypeConversion1_pq;
  boolean_T Compare_if;
  boolean_T DataTypeConversion1_m;
  boolean_T En_VO_Correct;
  boolean_T LogicalOperator1_i;
  boolean_T En_VO_Pz_Correct;
  boolean_T Compare_mr;
  boolean_T LogicalOperator2_hv;
  boolean_T En_GPS_Correct_c;
  boolean_T LogicalOperator3_d5;
  boolean_T GPS_Vel_Vaild;
  boolean_T En_Corr_Pz_RTK;
  boolean_T P_RTK_update_flg;
  boolean_T FixPtRelationalOperator_g;
  boolean_T Compare_ko;
  boolean_T Compare_mn;
  boolean_T Compare_ep;
  boolean_T Compare_afp;
  boolean_T En_sonar_Correct;
  boolean_T LogicalOperator1_hk;
  boolean_T NOT1;
  boolean_T LogicalOperator1_ks;
  boolean_T LogicalOperator2_f;
  boolean_T En_GPS_height_Correct;
  boolean_T LogicalOperator_hz;
  boolean_T GPS_height_enable;
  boolean_T DataTypeConversion1_e;
  boolean_T Compare_bo;
  boolean_T Compare_jq;
  boolean_T FixPtRelationalOperator_oo;
  boolean_T LogicalOperator1_im;
  boolean_T En_GPS_Correct_RTK;
  boolean_T Switch3_b2;
  boolean_T Switch_dy;
  boolean_T rtb_LogicalOperator_co_idx_0;
  boolean_T rtb_LogicalOperator_co_idx_1;
  boolean_T rtb_LogicalOperator1_ls_idx_1;
  B_Correct_y_Translation_Fusio_T Correct_y;
  B_Correct_x_Translation_Fus_h_T Correct_x;
  B_MovingAverage1_Translatio_c_T MovingAverage_pna;
  B_MovingAverage1_Translatio_c_T MovingAverage1_pna;
  B_MovingAverage1_Translation__T MovingAverage_pn;
  B_MovingAverage1_Translation__T MovingAverage1_pn;
  B_MovingAverage3_Translation__T MovingAverage2;
  B_MovingAverage3_Translation__T MovingAverage3;
  B_Correct_x_Translation_Fus_o_T Correct_y_c;
  B_Correct_x_Translation_Fus_o_T Correct_x_j;
  B_Correct_x_Translation_Fusio_T Correct_y_b;
  B_Correct_x_Translation_Fusio_T Correct_x_a;
  B_Correct_y_Translation_Fusio_T Correct_y_f;
  B_Correct_x_Translation_Fus_h_T Correct_x_d;
  B_Average_Translation_Fusion_T MovingAverage_p;
  B_Average_Translation_Fusion_T MovingAverage1;
  B_Average_Translation_Fusio_c_T Average_pna;
  B_Average_Translation_Fusio_c_T Average_pn;
  B_Correct_x_Translation_Fusio_T Correct_x_m;
  B_Average_Translation_Fusion_T Average;
  B_MovingAverage2_Translation__T MovingAverage_pnae;
  B_MovingAverage2_Translation__T MovingAverage1_pnae;
  B_MovingAverage2_Translation__T MovingAverage2_p;
} B_Translation_Fusion_c_T;

#endif

#ifndef Translation_Fusion_MDLREF_HIDE_CHILD_

typedef struct {
  dsp_private_SlidingWin_hgvzvy_T gobj_0;
  dsp_private_SlidingWin_hgvzvy_T gobj_1;
  dsp_private_SlidingWind_hgvzv_T gobj_0_b;
  dsp_private_SlidingWind_hgvzv_T gobj_1_h;
  dsp_simulink_MovingAve_e3xkxm_T obj;
  dsp_simulink_MovingAver_e3xkx_T obj_p;
  dsp_simulink_MovingAv_e3xkxms_T obj_a;
  dsp_private_SlidingWi_hgvzvyp_T gobj_0_e;
  dsp_private_SlidingWi_hgvzvyp_T gobj_1_f;
  real_T memory1_PreviousInput[3];
  real_T memory_PreviousInput[3];
  real32_T DiscreteTimeIntegrator_DSTATE;
  real32_T Delay1_DSTATE[4];
  real32_T Int_X_DSTATE[4];
  real32_T Delay_10_DSTATE[2];
  real32_T Delay_2_DSTATE;
  real32_T Delay1_DSTATE_n[3];
  real32_T Delay_DSTATE;
  real32_T Delay_DSTATE_j[9];
  real32_T DiscreteTimeIntegrator_DSTATE_k;
  real32_T DiscreteTimeIntegrator_DSTATE_g;
  real32_T DiscreteTimeIntegrator_DSTAT_k0;
  real32_T DiscreteTimeIntegrator_DSTATE_o;
  real32_T DiscreteTimeIntegrator_DSTATE_p;
  real32_T DiscreteTimeIntegrator1_DSTATE;
  real32_T DiscreteTimeIntegrator_DSTATE_n;
  real32_T DelayInput1_DSTATE;
  real32_T Delay_DSTATE_k;
  real32_T DiscreteTimeIntegrator_DSTATE_a;
  real32_T DiscreteTimeIntegrator_DSTATE_h;
  real32_T Delay1_DSTATE_o[2];
  real32_T DiscreteTimeIntegrator_DSTAT_ax;
  real32_T DiscreteTimeIntegrator_DSTATE_f;
  real32_T DiscreteTimeIntegrator_DSTAT_nz;
  real32_T DiscreteTimeIntegrator_DSTAT_a3;
  real32_T Delay_DSTATE_c;
  real32_T DiscreteTimeIntegrator1_DSTAT_k;
  real32_T DiscreteTimeIntegrator_DSTAT_pp;
  real32_T DiscreteTimeIntegrator1_DSTAT_a;
  real32_T DiscreteTimeIntegrator_DSTAT_o4;
  real32_T DiscreteTimeIntegrator_DSTATE_e;
  real32_T DiscreteTimeIntegrator_DSTAT_oe;
  real32_T DiscreteTimeIntegrator_DSTAT_hu;
  real32_T DiscreteTimeIntegrator_DSTATE_j;
  real32_T DiscreteTimeIntegrator_DSTAT_hc;
  real32_T DelayInput1_DSTATE_a;
  real32_T DiscreteTimeIntegrator_DSTATE_c;
  real32_T DiscreteTimeIntegrator_DSTAT_ag;
  real32_T x_delay_DSTATE[40];
  real32_T x_delay1_DSTATE[140];
  real32_T DiscreteTimeIntegrator_DSTAT_gk;
  real32_T DiscreteTimeIntegrator_DSTAT_pn;
  real32_T DiscreteTimeIntegrator1_DSTAT_h[3];
  real32_T UD_DSTATE;
  real32_T Delay2_DSTATE[2];
  real32_T DiscreteTimeIntegrator5_DSTATE;
  real32_T DiscreteTimeIntegrator5_DSTAT_d;
  real32_T DiscreteTimeIntegrator_DSTAT_fa;
  real32_T DiscreteTimeIntegrator_DSTATE_m;
  real32_T Delay3_DSTATE[2];
  real32_T Delay_DSTATE_o[200];
  real32_T DiscreteTimeIntegrator_DSTATE_i[2];
  real32_T Delay2_DSTATE_e[2];
  real32_T Delay1_DSTATE_f[2];
  real32_T Delay_DSTATE_of;
  real32_T DiscreteTimeIntegrator_DSTAT_ab;
  real32_T Delay1_DSTATE_g;
  real32_T DiscreteTimeIntegrator_DSTAT_gt;
  real32_T Delay2_DSTATE_b;
  real32_T DelayInput1_DSTATE_k;
  real32_T DiscreteTimeIntegrator_DSTAT_ai;
  real32_T Delay_DSTATE_m;
  real32_T DiscreteTimeIntegrator_DSTAT_eb;
  real32_T DiscreteTimeIntegrator_DSTAT_i1;
  real32_T DiscreteTimeIntegrator_DSTAT_cq;
  real32_T DiscreteTimeIntegrator_DSTAT_eq;
  real32_T DiscreteTimeIntegrator_DSTAT_j3;
  real32_T DiscreteTimeIntegrator1_DSTAT_f[2];
  real32_T DiscreteTimeIntegrator1_DSTAT_n;
  real32_T Delay_DSTATE_f;
  real32_T DiscreteTimeIntegrator_DSTATE_l;
  real32_T DiscreteTimeIntegrator1_DSTA_hw;
  real32_T DiscreteTimeIntegrator_DSTAT_lb;
  real32_T DiscreteTimeIntegrator1_DSTAT_b;
  real32_T DiscreteTimeIntegrator_DSTATE_d;
  real32_T Delay_DSTATE_p;
  real32_T DiscreteTimeIntegrator_DSTAT_pa;
  real32_T DiscreteTimeIntegrator1_DSTA_fe;
  real32_T DiscreteTimeIntegrator_DSTAT_a0;
  real32_T DiscreteTimeIntegrator1_DSTAT_g;
  real32_T DiscreteTimeIntegrator1_DSTAT_l;
  real32_T DiscreteTimeIntegrator_DSTA_gt3[2];
  real32_T DiscreteTimeIntegrator_DSTAT_n4;
  real32_T DiscreteTimeIntegrator_DSTAT_lc;
  real32_T DiscreteTimeIntegrator5_DSTAT_g;
  real32_T DiscreteTimeIntegrator5_DSTAT_j;
  real32_T DiscreteTimeIntegrator_DSTATE_b;
  real32_T DiscreteTimeIntegrator1_DSTAT_d;
  real32_T DiscreteTimeIntegrator_DSTAT_ak;
  real32_T DiscreteTimeIntegrator_DSTAT_ce;
  real32_T DiscreteTimeIntegrator_DSTAT_ct;
  real32_T DiscreteTimeIntegrator_DSTAT_bn;
  real32_T DiscreteTimeIntegrator1_DSTAT_c;
  real32_T DiscreteTimeIntegrator1_DSTA_l2;
  real32_T DiscreteTimeIntegrator_DSTAT_jp;
  real32_T DiscreteTimeIntegrator_DSTAT_eh;
  real32_T DiscreteTimeIntegrator1_DSTA_hj;
  real32_T DiscreteTimeIntegrator_DSTAT_hp;
  real32_T DiscreteTimeIntegrator1_DSTAT_m;
  real32_T DiscreteTimeIntegrator_DSTAT_pd;
  real32_T DiscreteTimeIntegrator1_DSTAT_p;
  real32_T DiscreteTimeIntegrator_DSTAT_dc;
  real32_T DiscreteTimeIntegrator_DSTAT_bo;
  real32_T DiscreteTimeIntegrator_DSTAT_ka;
  real32_T DiscreteTimeIntegrator1_DSTA_na;
  real32_T DiscreteTimeIntegrator_DSTAT_dv;
  real32_T DiscreteTimeIntegrator1_DSTA_hy;
  real32_T DiscreteTimeIntegrator_DSTAT_n2;
  real32_T DiscreteTimeIntegrator_DSTAT_jr;
  real32_T DiscreteTimeIntegrator1_DSTA_lz;
  real32_T DiscreteTimeIntegrator_DSTAT_ny;
  real32_T Delay1_DSTATE_d[4];
  real32_T Int_P_DSTATE[16];
  real32_T Delay2_DSTATE_l[9];
  real32_T DiscreteTimeIntegrator1_DSTA_gu;
  real32_T UnitDelay_DSTATE[2];
  real32_T DiscreteTimeIntegrator1_DSTAT_e;
  real32_T DiscreteTimeIntegrator_DSTAT_bc;
  real32_T y_delay1_DSTATE[140];
  real32_T y_delay2_DSTATE[140];
  real32_T x_delay_DSTATE_i[40];
  real32_T y_delay_DSTATE[40];
  real32_T UnitDelay1_DSTATE[3];
  real32_T DiscreteTimeIntegrator_DSTAT_mr;
  real32_T DiscreteTimeIntegrator_DSTAT_lv;
  real32_T DiscreteTimeIntegrator_DSTAT_nr[2];
  real32_T DiscreteTimeIntegrator_DSTAT_dd[2];
  real32_T DiscreteTimeIntegrator_DSTAT_oy;
  real32_T DiscreteTimeIntegrator_DSTAT_cf;
  real32_T DiscreteTimeIntegrator_DSTAT_mo;
  real32_T DiscreteTimeIntegrator_DSTAT_jh[4];
  real32_T UnitDelay_DSTATE_h;
  real32_T DiscreteTimeIntegrator_DSTA_ppy;
  real32_T DiscreteTimeIntegrator_DSTAT_c3;
  real32_T DiscreteTimeIntegrator_DSTA_mos;
  real32_T DiscreteTimeIntegrator_DSTAT_hz;
  real32_T DiscreteTimeIntegrator_DSTAT_bk;
  real32_T DiscreteTimeIntegrator_DSTAT_mu;
  real32_T x_delay_DSTATE_e[80];
  real32_T Delay_DSTATE_mr[2];
  real32_T Delay1_DSTATE_b[2];
  real32_T y_delay_DSTATE_b[80];
  real32_T DiscreteTimeIntegrator_DSTAT_el[2];
  real32_T DiscreteTimeIntegrator_DSTAT_g0[2];
  real32_T DiscreteTimeIntegrator_DSTAT_bx;
  real32_T DiscreteTimeIntegrator_DSTAT_gr;
  real32_T DiscreteTimeIntegrator_DSTAT_in[3];
  real32_T Delay_DSTATE_fh[4];
  real32_T Delay1_DSTATE_j[2];
  real32_T Delay_DSTATE_b[4];
  real32_T Delay1_DSTATE_p[10];
  real32_T Delay_DSTATE_ko[4];
  real32_T Delay1_DSTATE_gi[10];
  real32_T Delay2_DSTATE_n[10];
  real32_T Delay_DSTATE_oc;
  real32_T Delay_DSTATE_cc;
  real32_T Delay1_DSTATE_k;
  real32_T Delay_DSTATE_j3;
  real32_T Delay1_DSTATE_h;
  real32_T Delay_DSTATE_i;
  real32_T Delay1_DSTATE_hr;
  real32_T Delay_DSTATE_ks;
  real32_T Delay1_DSTATE_ky[5];
  real32_T Delay_DSTATE_jl;
  real32_T Delay1_DSTATE_ot;
  real32_T DiscreteTimeIntegrator_DSTAT_i2[3];
  uint32_T DelayInput1_DSTATE_k2;
  uint32_T DelayInput1_DSTATE_p;
  uint32_T DelayInput1_DSTATE_j;
  uint32_T DelayInput1_DSTATE_j3;
  uint32_T DelayInput1_DSTATE_ap;
  uint32_T DelayInput1_DSTATE_b;
  uint32_T DelayInput1_DSTATE_p1;
  real32_T Memory_PreviousInput;
  real32_T Memory1_PreviousInput;
  real32_T Memory_PreviousInput_o;
  real32_T Memory_PreviousInput_h[2];
  real32_T Memory1_PreviousInput_c[2];
  real32_T Memory_PreviousInput_c[2];
  real32_T Memory1_PreviousInput_l[2];
  real32_T Inverse_DWORK4[4];
  real32_T MatrixInverse_DWORK4[4];
  real32_T Inverse_DWORK4_j[4];
  real32_T Inverse_DWORK4_d[4];
  real32_T MatrixInverse_DWORK4_c[4];
  real32_T Inverse_DWORK4_e;
  real32_T MatrixInverse_DWORK4_f;
  real32_T Inverse_DWORK4_p;
  real32_T MatrixInverse_DWORK4_l;
  real32_T Inverse_DWORK4_o;
  real32_T MatrixInverse_DWORK4_i;
  real32_T Inverse_DWORK4_ew;
  real32_T MatrixInverse_DWORK4_j;
  real32_T MatrixInverse_DWORK4_h;
  real32_T Inverse_DWORK4_o0;
  real32_T MatrixInverse_DWORK4_p;
  uint16_T Delay1_DSTATE_k1;
  uint16_T Memory_PreviousInput_o3;
  boolean_T Delay2_DSTATE_h[2];
  boolean_T DelayInput1_DSTATE_g;
  boolean_T DelayInput1_DSTATE_k3;
  boolean_T DelayInput1_DSTATE_g3;
  boolean_T DelayInput1_DSTATE_ku;
  boolean_T DelayInput1_DSTATE_e;
  boolean_T Delay_DSTATE_g[10];
  boolean_T UnitDelay_DSTATE_p;
  boolean_T DelayInput1_DSTATE_bh;
  boolean_T Delay1_DSTATE_l;
  boolean_T Delay_DSTATE_p2;
  boolean_T Delay_DSTATE_o5;
  boolean_T Delay_DSTATE_d;
  boolean_T Delay_DSTATE_db;
  boolean_T Delay_DSTATE_h;
  boolean_T Delay_DSTATE_ch;
  boolean_T Delay_DSTATE_jd;
  boolean_T DelayInput1_DSTATE_n;
  boolean_T Delay_DSTATE_d4;
  boolean_T Delay_DSTATE_jg;
  boolean_T Delay1_DSTATE_b0[2];
  boolean_T Delay_DSTATE_k1;
  boolean_T Delay_DSTATE_n;
  boolean_T Delay2_DSTATE_a[2];
  boolean_T Delay1_DSTATE_c[2];
  boolean_T Delay_DSTATE_o1;
  boolean_T Delay1_DSTATE_nb;
  boolean_T DelayInput1_DSTATE_o;
  boolean_T Delay_DSTATE_pi;
  boolean_T DelayInput1_DSTATE_f;
  boolean_T Delay_DSTATE_l;
  boolean_T Delay_DSTATE_by;
  boolean_T DelayInput1_DSTATE_ey;
  boolean_T DelayInput1_DSTATE_nj;
  boolean_T Delay_DSTATE_pu;
  boolean_T DelayInput1_DSTATE_d;
  boolean_T Delay_DSTATE_kd;
  boolean_T DelayInput1_DSTATE_jf;
  boolean_T Delay_DSTATE_e;
  boolean_T Delay_DSTATE_ev;
  boolean_T Delay1_DSTATE_ci[2];
  boolean_T Delay1_DSTATE_ls;
  boolean_T Delay_DSTATE_pc[2];
  int8_T DiscreteTimeIntegrator_PrevRese;
  int8_T DiscreteTimeIntegrator_PrevRe_h;
  int8_T DiscreteTimeIntegrator_PrevRe_b;
  int8_T DiscreteTimeIntegrator_PrevR_hl;
  int8_T DiscreteTimeIntegrator_PrevRe_g;
  int8_T DiscreteTimeIntegrator_PrevRe_n;
  int8_T DiscreteTimeIntegrator_PrevR_bx;
  int8_T DiscreteTimeIntegrator_PrevRe_f;
  int8_T DiscreteTimeIntegrator_PrevR_n3;
  int8_T DiscreteTimeIntegrator_PrevRe_c;
  int8_T DiscreteTimeIntegrator_PrevRe_m;
  int8_T DiscreteTimeIntegrator_PrevR_bd;
  int8_T DiscreteTimeIntegrator_PrevR_mc;
  int8_T DiscreteTimeIntegrator_PrevR_br;
  int8_T DiscreteTimeIntegrator_PrevRe_i;
  int8_T DiscreteTimeIntegrator_PrevRe_j;
  int8_T DiscreteTimeIntegrator_PrevR_g2;
  int8_T DiscreteTimeIntegrator_PrevRe_p;
  int8_T DiscreteTimeIntegrator_PrevR_gd;
  int8_T DiscreteTimeIntegrator_PrevR_hj;
  int8_T DiscreteTimeIntegrator_PrevR_by;
  int8_T DiscreteTimeIntegrator_PrevR_gw;
  int8_T DiscreteTimeIntegrator_PrevR_gg[2];
  int8_T DiscreteTimeIntegrator_PrevR_bz;
  int8_T DiscreteTimeIntegrator_PrevRe_d;
  int8_T DiscreteTimeIntegrator_PrevRe_a;
  int8_T DiscreteTimeIntegrator_PrevR_jg;
  int8_T DiscreteTimeIntegrator_PrevRe_o;
  int8_T DiscreteTimeIntegrator_PrevR_is;
  int8_T DiscreteTimeIntegrator1_PrevRes;
  int8_T DiscreteTimeIntegrator_PrevR_iz;
  int8_T DiscreteTimeIntegrator_PrevR_hk;
  int8_T DiscreteTimeIntegrator5_PrevRes;
  int8_T DiscreteTimeIntegrator_PrevR_ix;
  int8_T DiscreteTimeIntegrator_PrevRe_e;
  int8_T DiscreteTimeIntegrator_PrevR_fm;
  int8_T DiscreteTimeIntegrator_PrevR_au;
  int8_T DiscreteTimeIntegrator_PrevR_a0;
  int8_T DiscreteTimeIntegrator_PrevR_ov;
  int8_T DiscreteTimeIntegrator_Prev_jgs;
  int8_T DiscreteTimeIntegrator_PrevR_nj;
  int8_T DiscreteTimeIntegrator_PrevRe_k;
  int8_T DiscreteTimeIntegrator_PrevR_pi;
  int8_T DiscreteTimeIntegrator_PrevR_dw;
  int8_T DiscreteTimeIntegrator_PrevR_pz[2];
  int8_T DiscreteTimeIntegrator_PrevR_gr[2];
  uint8_T icLoad;
  uint8_T icLoad_k;
  uint8_T icLoad_ki;
  uint8_T icLoad_h;
  uint8_T DiscreteTimeIntegrator_IC_LOADI;
  uint8_T DiscreteTimeIntegrator_IC_LOA_p;
  uint8_T DiscreteTimeIntegrator_IC_LOA_a;
  uint8_T icLoad_g;
  uint8_T icLoad_kg;
  uint8_T DiscreteTimeIntegrator_IC_LOA_b;
  uint8_T DiscreteTimeIntegrator_IC_LO_aj;
  uint8_T icLoad_gb;
  uint8_T icLoad_gm;
  uint8_T icLoad_d;
  uint8_T DiscreteTimeIntegrator_IC_LOA_f;
  uint8_T DiscreteTimeIntegrator_IC_LOA_k;
  uint8_T DiscreteTimeIntegrator_IC_LOA_m;
  uint8_T DiscreteTimeIntegrator_IC_LO_ae;
  uint8_T DiscreteTimeIntegrator1_IC_LOAD;
  uint8_T DiscreteTimeIntegrator_IC_LO_fn;
  uint8_T DiscreteTimeIntegrator1_IC_LO_n;
  uint8_T DiscreteTimeIntegrator_IC_LO_fw;
  uint8_T icLoad_f;
  uint8_T icLoad_d1;
  uint8_T icLoad_o;
  uint8_T icLoad_c;
  uint8_T icLoad_j;
  uint8_T DiscreteTimeIntegrator_IC_LOA_d;
  uint8_T DiscreteTimeIntegrator_IC_LOA_i;
  uint8_T DiscreteTimeIntegrator_IC_LOA_o;
  uint8_T DiscreteTimeIntegrator_IC_LOA_h;
  uint8_T DiscreteTimeIntegrator_IC_LO_oj;
  uint8_T DiscreteTimeIntegrator_IC_LO_fm;
  uint8_T DiscreteTimeIntegrator_IC_LO_fo;
  uint8_T DiscreteTimeIntegrator_IC_LO_he;
  uint8_T icLoad_on;
  uint8_T icLoad_kr;
  uint8_T icLoad_fb;
  uint8_T icLoad_a;
  uint8_T DiscreteTimeIntegrator_IC_LO_mc;
  uint8_T DiscreteTimeIntegrator_IC_LOA_l;
  uint8_T icLoad_b;
  uint8_T icLoad_l;
  uint8_T DiscreteTimeIntegrator_IC_LO_oh;
  boolean_T Relay2_Mode;
  boolean_T Relay1_Mode;
  boolean_T Relay_Mode;
  boolean_T Relay2_Mode_e;
  boolean_T Relay1_Mode_k;
  boolean_T Relay_Mode_m;
  boolean_T Relay2_Mode_e3;
  boolean_T Relay1_Mode_p;
  boolean_T Relay_Mode_md;
  boolean_T u05065_Mode;
  boolean_T u0104_Mode;
  boolean_T u0505_Mode;
  boolean_T u0504_Mode;
  boolean_T u2065_Mode;
  boolean_T u35085_Mode;
  boolean_T Relay_Mode_g;
  boolean_T u9509_Mode;
  boolean_T objisempty;
  boolean_T objisempty_d;
  boolean_T objisempty_i;
  DW_Correct_y_Translation_Fusi_T Correct_y;
  DW_Correct_x_Translation_Fu_p_T Correct_x;
  DW_MovingAverage1_Translati_f_T MovingAverage_pna;
  DW_MovingAverage1_Translati_f_T MovingAverage1_pna;
  DW_MovingAverage1_Translation_T MovingAverage_pn;
  DW_MovingAverage1_Translation_T MovingAverage1_pn;
  DW_MovingAverage3_Translation_T MovingAverage2;
  DW_MovingAverage3_Translation_T MovingAverage3;
  DW_Correct_x_Translation_F_pb_T Correct_y_c;
  DW_Correct_x_Translation_F_pb_T Correct_x_j;
  DW_Correct_x_Translation_Fusi_T Correct_y_b;
  DW_Correct_x_Translation_Fusi_T Correct_x_a;
  DW_Correct_y_Translation_Fusi_T Correct_y_f;
  DW_Correct_x_Translation_Fu_p_T Correct_x_d;
  DW_Average_Translation_Fusion_T MovingAverage_p;
  DW_Average_Translation_Fusion_T MovingAverage1;
  DW_Average_Translation_Fusi_f_T Average_pna;
  DW_Average_Translation_Fusi_f_T Average_pn;
  DW_Correct_x_Translation_Fusi_T Correct_x_m;
  DW_Average_Translation_Fusion_T Average;
  DW_MovingAverage2_Translation_T MovingAverage_pnae;
  DW_MovingAverage2_Translation_T MovingAverage1_pnae;
  DW_MovingAverage2_Translation_T MovingAverage2_p;
} DW_Translation_Fusion_f_T;

#endif

#ifndef Translation_Fusion_MDLREF_HIDE_CHILD_

typedef struct {
  ZCSigState Int_X_Reset_ZCE;
  ZCSigState Delay_Reset_ZCE;
  ZCSigState x_delay_Reset_ZCE;
  ZCSigState x_delay1_Reset_ZCE;
  ZCSigState Delay2_Reset_ZCE;
  ZCSigState Delay2_Reset_ZCE_b;
  ZCSigState Delay_Reset_ZCE_o;
  ZCSigState Delay1_Reset_ZCE;
  ZCSigState Delay1_Reset_ZCE_i;
  ZCSigState Int_P_Reset_ZCE;
  ZCSigState y_delay1_Reset_ZCE;
  ZCSigState y_delay2_Reset_ZCE;
  ZCSigState x_delay_Reset_ZCE_a;
  ZCSigState y_delay_Reset_ZCE;
  ZCSigState x_delay_Reset_ZCE_d;
  ZCSigState Delay_Reset_ZCE_k;
  ZCSigState Delay1_Reset_ZCE_b;
  ZCSigState y_delay_Reset_ZCE_p;
  ZCSigState MovingAverage_Trig_ZCE;
} ZCE_Translation_Fusion_T;

#endif

#ifndef Translation_Fusion_MDLREF_HIDE_CHILD_

struct P_Correct_x_Translation_Fusio_T_ {
  real32_T X_Cor_Y0;
  real32_T P_next_Y0;
  real32_T Constant_Value[9];
  real32_T Saturation1_UpperSat[2];
  real32_T Saturation1_LowerSat[2];
};

#endif

typedef struct P_Correct_x_Translation_Fusio_T_ P_Correct_x_Translation_Fusio_T;

#ifndef Translation_Fusion_MDLREF_HIDE_CHILD_

struct P_Correct_x_Translation_Fus_j_T_ {
  real32_T P_next_Y0;
  real32_T X_Cor_Y0;
  real32_T Constant_Value[9];
  real32_T Saturation1_UpperSat;
  real32_T Saturation1_LowerSat;
  real32_T Gain_Gain;
};

#endif

typedef struct P_Correct_x_Translation_Fus_j_T_ P_Correct_x_Translation_Fus_j_T;

#ifndef Translation_Fusion_MDLREF_HIDE_CHILD_

struct P_Correct_y_Translation_Fusio_T_ {
  real32_T P_next_Y0;
  real32_T X_Cor_Y0;
  real32_T Constant_Value[9];
  real32_T Saturation2_UpperSat;
  real32_T Saturation2_LowerSat;
  real32_T Gain_Gain;
};

#endif

typedef struct P_Correct_y_Translation_Fusio_T_ P_Correct_y_Translation_Fusio_T;

#ifndef Translation_Fusion_MDLREF_HIDE_CHILD_

struct P_Correct_x_Translation_Fus_m_T_ {
  real32_T X_Cor_Y0;
  real32_T P_next_Y0;
  real32_T Constant_Value[9];
};

#endif

typedef struct P_Correct_x_Translation_Fus_m_T_ P_Correct_x_Translation_Fus_m_T;

#ifndef Translation_Fusion_MDLREF_HIDE_CHILD_

struct P_Translation_Fusion_T_ {
  real_T CompareToConstant_const;
  real_T Zero_Value_Exclusion_thr;
  real_T Zero_Value_Exclusion_thr_f;
  real_T Zero_Value_Exclusion_thr_a;
  real_T Zero_Value_Exclusion_thr_n;
  real32_T Difference_ICPrevInput;
  real32_T ust_orderdelaycompensator_N;
  real32_T ust_orderdelaycompensator1_N;
  real32_T ust_orderdelaycompensator_N_i;
  real32_T ust_orderdelaycompensator1_N_c;
  real32_T ust_orderdelaycompensator1_N_j;
  real32_T ust_orderdelaycompensator1_N_a;
  real32_T ust_orderdelaycompensator1_N_e;
  real32_T Validafteraperiod_T_p;
  real32_T Validaperiod_T_p;
  real32_T Validaperiod_T_p_p;
  real32_T Validaperiod_T_p_j;
  real32_T Validaperiod1_T_p;
  real32_T Validaperiod2_T_p;
  real32_T Validaperiod1_T_p_m;
  real32_T Validaperiod_T_p_i;
  real32_T Validafteraperiod_T_p_n;
  real32_T Validafteraperiod_T_p_a;
  real32_T Validaperiod_T_p_ik;
  real32_T Validafteraperiod_T_p_ab;
  real32_T Validforaperiod1_T_p;
  real32_T Validaperiod_T_p_c;
  real32_T Validaperiod1_T_p_f;
  real32_T Ascendanddescendtracking_Tc_asc;
  real32_T Ascendanddescendtracking2_Tc_as;
  real32_T Ascendanddescendtracking_Tc_des;
  real32_T Ascendanddescendtracking2_Tc_de;
  real32_T CompareToConstant_const_j;
  real32_T CompareToConstant1_const;
  real32_T CompareToConstant_const_f;
  real32_T CompareToConstant5_const;
  real32_T CompareToConstant5_const_e;
  real32_T CompareToConstant_const_g;
  real32_T CompareToConstant4_const;
  real32_T CompareToConstant_const_p;
  real32_T CompareToConstant_const_j4;
  real32_T CompareToConstant3_const;
  real32_T CompareToConstant2_const;
  real32_T CompareToConstant_const_e;
  real32_T CompareToConstant1_const_b;
  real32_T CompareToConstant_const_f5;
  real32_T CompareToConstant10_const;
  real32_T CompareToConstant1_const_l;
  real32_T CompareToConstant3_const_o;
  real32_T CompareToConstant2_const_d;
  real32_T CompareTo3sec_const;
  real32_T CompareToConstant_const_a;
  real32_T CompareTo2sec_const;
  real32_T CompareToConstant2_const_l;
  real32_T CompareTo1sec_const;
  real32_T CompareToConstant3_const_i;
  real32_T CompareTo1sec_const_p;
  real32_T CompareToConstant_const_k;
  real32_T CompareToConstant_const_pn;
  real32_T CompareTo1sec_const_c;
  real32_T CompareToConstant1_const_g;
  real32_T CompareTo1sec_const_g;
  real32_T CompareToConstant3_const_g;
  real32_T CompareToConstant2_const_lv;
  real32_T CompareToConstant_const_b;
  real32_T CompareToConstant_const_i;
  real32_T CompareTo2sec_const_e;
  real32_T CompareToConstant3_const_is;
  real32_T CompareToConstant_const_o;
  real32_T CompareToConstant2_const_j;
  real32_T CompareToConstant3_const_n;
  real32_T CompareTo1sec_const_o;
  real32_T CompareToConstant1_const_i;
  real32_T CompareToConstant4_const_g;
  real32_T CompareToConstant2_const_k;
  real32_T CompareToConstant6_const;
  real32_T CompareToConstant5_const_b;
  real32_T CompareToConstant3_const_b;
  real32_T CompareToConstant2_const_e;
  real32_T CompareTo1sec_const_h;
  real32_T CompareToConstant4_const_f;
  real32_T CompareToConstant3_const_p;
  real32_T CompareToConstant1_const_p;
  real32_T CompareToConstant4_const_o;
  real32_T CompareToConstant2_const_eh;
  real32_T CompareToConstant_const_bs;
  real32_T CompareTo1sec_const_he;
  real32_T CompareToConstant_const_on;
  real32_T CompareTo1sec_const_f;
  real32_T CompareToConstant1_const_c;
  real32_T CompareToConstant1_const_n;
  real32_T CompareToConstant1_const_n2;
  real32_T CompareToConstant_const_l;
  real32_T CompareToConstant_const_p5;
  real32_T CompareToConstant2_const_c;
  real32_T CompareToConstant3_const_h;
  real32_T CompareToConstant_const_os;
  real32_T CompareToConstant1_const_k;
  real32_T CompareToConstant1_const_br;
  real32_T CompareToConstant4_const_e;
  real32_T CompareToConstant4_const_a;
  real32_T CompareToConstant1_const_nv;
  real32_T CompareTo1sec_const_pe;
  real32_T CompareToConstant_const_as;
  real32_T CompareToConstant2_const_c3;
  real32_T CompareToConstant3_const_a;
  real32_T CompareTo1sec_const_b;
  real32_T CompareToConstant1_const_k3;
  real32_T CompareToConstant4_const_d;
  real32_T CompareToConstant_const_et;
  real32_T CompareToConstant_const_fl;
  real32_T CompareToConstant_const_br;
  real32_T CompareToConstant1_const_o;
  real32_T CompareToConstant_const_m;
  real32_T CompareToConstant10_const_l;
  real32_T CompareToConstant2_const_i;
  real32_T CompareToConstant1_const_gb;
  real32_T CompareToConstant4_const_l;
  real32_T CompareToConstant_const_ah;
  real32_T CompareToConstant_const_el;
  real32_T CompareToConstant1_const_is;
  real32_T CompareToConstant_const_d;
  real32_T CompareToConstant1_const_h;
  real32_T CompareToConstant2_const_cc;
  real32_T Attenuation_d;
  real32_T AdaptiveCorrection_kai;
  real32_T AdaptiveCorrection_kai_f;
  real32_T AdaptiveCorrection_kai_b;
  real32_T AdaptiveCorrection_kai_a;
  real32_T AdaptiveCorrection1_kai;
  real32_T AdaptiveGPSVelocityCorrection_k;
  real32_T AdaptiveVOVelocityCorrection_ka;
  real32_T AdaptiveCorrection_max_eta;
  real32_T AdaptiveCorrection_max_eta_h;
  real32_T AdaptiveCorrection_max_eta_l;
  real32_T AdaptiveCorrection_max_eta_c;
  real32_T AdaptiveCorrection1_max_eta;
  real32_T AdaptiveGPSVelocityCorrection_m;
  real32_T AdaptiveVOVelocityCorrection_ma;
  real32_T Initialization_p0[9];
  real32_T xy_fusion_sgm_vel_VO;
  real32_T HeightFusionwithaccbias_stage_t;
  real32_T SonarPreprocessor_vMaxDown;
  real32_T SonarPreprocessor_vMaxUp;
  real32_T DetectUpdate1_vinit;
  real32_T DetectUpdate1_vinit_e;
  real32_T DetectUpdate_vinit;
  uint32_T CompareToConstant_const_c;
  uint32_T CompareToConstant_const_h;
  uint32_T CompareToConstant_const_l5;
  uint32_T CompareToConstant3_const_n0;
  uint32_T CompareToConstant_const_ih;
  uint32_T CompareToConstant7_const;
  uint32_T CompareToConstant8_const;
  uint32_T DetectIncrease_vinit;
  uint32_T DetectChange_vinit;
  uint32_T DetectChange_vinit_d;
  uint32_T DetectIncrease_vinit_h;
  uint32_T DetectChange_vinit_g;
  uint32_T DetectChange_vinit_o;
  uint32_T DetectIncrease_vinit_i;
  boolean_T DetectRisePositive3_vinit;
  boolean_T DetectRisePositive2_vinit;
  boolean_T DetectIncrease_vinit_a;
  boolean_T DetectIncrease1_vinit;
  boolean_T DetectIncrease2_vinit;
  boolean_T DetectIncrease1_vinit_h;
  boolean_T DetectIncrease_vinit_k;
  boolean_T DetectIncrease_vinit_ax;
  boolean_T DetectIncrease_vinit_kk;
  boolean_T DetectIncrease_vinit_f;
  boolean_T DetectIncrease_vinit_iv;
  boolean_T DetectIncrease1_vinit_b;
  boolean_T DetectIncrease_vinit_g;
  uint8_T BitwiseAND_BitMask;
  uint8_T BitwiseAND1_BitMask;
  uint8_T CompareToConstant_const_fa;
  uint8_T CompareToConstant5_const_h;
  uint8_T CompareToConstant1_const_f;
  uint8_T CompareToConstant4_const_b;
  uint8_T CompareToConstant1_const_d;
  uint8_T CompareToConstant6_const_f;
  uint8_T CompareToConstant_const_er;
  real_T Constant_Value;
  real_T Constant_Value_m[2];
  real_T Saturation_UpperSat;
  real_T Saturation_LowerSat;
  real_T Saturation1_UpperSat;
  real_T Saturation1_LowerSat;
  real_T Constant_Value_f;
  real_T Constant_Value_l;
  real_T Constant_Value_p[2];
  real_T Constant_Value_c[2];
  real_T Constant_Value_pi;
  real_T Constant_Value_i[2];
  real_T Constant_Value_e;
  real_T Constant_Value_lf[2];
  real_T Constant_Value_j;
  real_T Saturation_UpperSat_c;
  real_T memory1_InitialCondition;
  real_T Constant_Value_i3;
  real_T memory_InitialCondition;
  real_T Saturation_UpperSat_i;
  real_T Saturation_UpperSat_e;
  real_T Saturation_LowerSat_o;
  real_T Saturation1_UpperSat_p;
  real_T Saturation1_LowerSat_a;
  real_T Saturation_UpperSat_k;
  real_T Saturation_UpperSat_b;
  real_T Saturation_LowerSat_f;
  real_T Saturation1_UpperSat_k;
  real_T Saturation1_LowerSat_o;
  real_T Saturation_UpperSat_f;
  real_T Saturation_UpperSat_eu;
  real_T Saturation_LowerSat_d;
  real_T Saturation1_UpperSat_g;
  real_T Saturation1_LowerSat_f;
  real32_T acc_bias_O_Y0;
  real32_T acc_bias_B_Y0;
  real32_T DiscreteTimeIntegrator_gainval;
  real32_T Gain_Gain;
  real32_T Constant_Value_cc;
  real32_T Constant1_Value;
  real32_T Constant3_Value;
  real32_T Constant5_Value;
  real32_T Constant2_Value;
  real32_T Switch2_Threshold;
  real32_T Switch1_Threshold;
  real32_T Constant_Value_fb;
  real32_T Constant1_Value_l;
  real32_T Constant3_Value_j;
  real32_T Constant5_Value_b;
  real32_T Constant2_Value_n;
  real32_T Switch2_Threshold_h;
  real32_T Switch1_Threshold_g;
  real32_T Gain_Gain_g;
  real32_T Constant_Value_n;
  real32_T Gain_Gain_n;
  real32_T x_Y0;
  real32_T P_Y0;
  real32_T Delay_InitialCondition;
  real32_T Delay1_InitialCondition;
  real32_T Qc1_Value[3];
  real32_T Qc_Value[3];
  real32_T Qc2_Value[3];
  real32_T Gain_Gain_p;
  real32_T Constant1_Value_g;
  real32_T P_next_Y0;
  real32_T X_Cor_Y0;
  real32_T Constant_Value_g[9];
  real32_T Gain_Gain_d;
  real32_T Constant_Value_gg;
  real32_T Gain2_Gain;
  real32_T Gain1_Gain;
  real32_T Saturation_UpperSat_kb;
  real32_T Saturation_LowerSat_l;
  real32_T R1_Value;
  real32_T Constant_Value_cf;
  real32_T Gain_Gain_l;
  real32_T x_Y0_c;
  real32_T P_Y0_l;
  real32_T Delay_InitialCondition_n;
  real32_T Delay1_InitialCondition_f;
  real32_T sonarnoise1_Value;
  real32_T sonarnoise_Value;
  real32_T Constant_Value_lk;
  real32_T Gain_Gain_h;
  real32_T x_Y0_o;
  real32_T P_Y0_g;
  real32_T Eta_Y0;
  real32_T Delay_InitialCondition_nx;
  real32_T Delay1_InitialCondition_l;
  real32_T Gain4_Gain;
  real32_T Gain_Gain_pg;
  real32_T Gain3_Gain;
  real32_T Gain_Gain_hf;
  real32_T Constant_Value_lm;
  real32_T Out1_Y0;
  real32_T Constant_Value_jp;
  real32_T Constant_Value_b;
  real32_T bias_Y0;
  real32_T R3_Value;
  real32_T R2_Value;
  real32_T Constant_Value_a;
  real32_T Gain_Gain_i;
  real32_T x_Y0_l;
  real32_T P_Y0_p;
  real32_T Delay_InitialCondition_j;
  real32_T Delay1_InitialCondition_k;
  real32_T Constant_Value_k;
  real32_T Gain_Gain_n0;
  real32_T x_Y0_h;
  real32_T P_Y0_d;
  real32_T Delay_InitialCondition_k;
  real32_T Delay1_InitialCondition_g;
  real32_T R1_Value_n;
  real32_T R_Value;
  real32_T Constant1_Value_g3;
  real32_T Constant4_Value;
  real32_T y_Y0;
  real32_T Gain1_Gain_i;
  real32_T Gain_Gain_k;
  real32_T Gain2_Gain_l;
  real32_T x0_Value[4];
  real32_T Constant_Value_kt;
  real32_T Gain_Gain_k3;
  real32_T P_Y0_da;
  real32_T X_Cor_Y0_g;
  real32_T Delay_InitialCondition_a;
  real32_T Delay1_InitialCondition_n;
  real32_T Constant1_Value_b;
  real32_T x1_Value[2];
  real32_T Constant_Value_kn;
  real32_T Saturation_UpperSat_o;
  real32_T Saturation_LowerSat_a;
  real32_T process_noise_variance_Value[4];
  real32_T process_noise_variance1_Value[4];
  real32_T Constant1_Value_o;
  real32_T Constant_Value_av[36];
  real32_T Constant2_Value_j;
  real32_T Constant_Value_o;
  real32_T Gain_Gain_k4;
  real32_T Constant_Value_la[36];
  real32_T Delay_InitialCondition_i;
  real32_T Delay1_InitialCondition_f0;
  real32_T Constant_Value_mx[36];
  real32_T Constant1_Value_h[4];
  real32_T Constant1_Value_e[4];
  real32_T Constant_Value_d;
  real32_T Constant1_Value_n;
  real32_T Constant_Value_mg;
  real32_T Saturation_UpperSat_kj;
  real32_T Saturation_LowerSat_ap;
  real32_T Constant_Value_a0;
  real32_T Constant1_Value_h1;
  real32_T Constant_Value_cu[36];
  real32_T Constant_Value_lh;
  real32_T Gain_Gain_l5;
  real32_T P_Y0_gk;
  real32_T X_Cor_Y0_m;
  real32_T Delay_InitialCondition_m;
  real32_T Delay1_InitialCondition_h;
  real32_T Constant1_Value_om;
  real32_T Gain1_Gain_n;
  real32_T Constant1_Value_g2;
  real32_T SampleTime_WtEt;
  real32_T SampleTime_WtEt_l;
  real32_T Constant3_Value_c[4];
  real32_T Constant2_Value_o[4];
  real32_T Constant1_Value_b0[4];
  real32_T Constant4_Value_g[4];
  real32_T indoor4_Value;
  real32_T indoor7_Value;
  real32_T indoor3_Value;
  real32_T indoor5_Value;
  real32_T indoor6_Value;
  real32_T indoor2_Value;
  real32_T DiscreteTimeIntegrator_gainva_o;
  real32_T DiscreteTimeIntegrator_IC;
  real32_T DiscreteTimeIntegrator_UpperSat;
  real32_T DiscreteTimeIntegrator_LowerSat;
  real32_T Constant2_Value_p;
  real32_T Delay1_InitialCondition_i;
  real32_T Relay2_OnVal;
  real32_T Relay2_OffVal;
  real32_T Relay2_YOn;
  real32_T Relay2_YOff;
  real32_T Delay_10_InitialCondition;
  real32_T Delay_2_InitialCondition;
  real32_T Relay1_OnVal;
  real32_T Relay1_OffVal;
  real32_T Relay1_YOn;
  real32_T Relay1_YOff;
  real32_T Relay_OnVal;
  real32_T Relay_OffVal;
  real32_T Relay_YOn;
  real32_T Relay_YOff;
  real32_T Relay2_OnVal_i;
  real32_T Relay2_OffVal_k;
  real32_T Relay2_YOn_j;
  real32_T Relay2_YOff_h;
  real32_T Relay1_OnVal_c;
  real32_T Relay1_OffVal_b;
  real32_T Relay1_YOn_i;
  real32_T Relay1_YOff_j;
  real32_T Relay_OnVal_k;
  real32_T Relay_OffVal_f;
  real32_T Relay_YOn_m;
  real32_T Relay_YOff_p;
  real32_T Constant4_Value_p;
  real32_T Saturation_UpperSat_h;
  real32_T Saturation_LowerSat_m;
  real32_T Constant_Value_dr;
  real32_T Constant_Value_ml;
  real32_T Constant_Value_nr;
  real32_T Relay2_OnVal_p;
  real32_T Relay2_OffVal_d;
  real32_T Relay2_YOn_c;
  real32_T Relay2_YOff_m;
  real32_T Relay1_OnVal_p;
  real32_T Relay1_OffVal_j;
  real32_T Relay1_YOn_g;
  real32_T Relay1_YOff_c;
  real32_T Relay_OnVal_m;
  real32_T Relay_OffVal_h;
  real32_T Relay_YOn_j;
  real32_T Relay_YOff_b;
  real32_T Saturation2_UpperSat;
  real32_T Saturation2_LowerSat;
  real32_T Constant4_Value_a;
  real32_T Saturation_UpperSat_hn;
  real32_T Saturation_LowerSat_j;
  real32_T Constant_Value_ig;
  real32_T Constant_Value_gs;
  real32_T Saturation1_UpperSat_a;
  real32_T Saturation1_LowerSat_g;
  real32_T Constant_Value_ac;
  real32_T Constant_Value_h;
  real32_T Constant_Value_ea;
  real32_T Constant_Value_kw;
  real32_T Constant_Value_el;
  real32_T Constant_Value_hg;
  real32_T SampleTime_WtEt_e;
  real32_T Constant1_Value_no[3];
  real32_T Gain4_Gain_o;
  real32_T SampleTime_WtEt_p;
  real32_T Ac_Value[9];
  real32_T SampleTime_WtEt_f;
  real32_T Gain_Gain_f;
  real32_T Gain1_Gain_g;
  real32_T Bc_Value[3];
  real32_T SampleTime_WtEt_g;
  real32_T Gain1_Gain_c;
  real32_T Gain_Gain_gc;
  real32_T zero_Value;
  real32_T Gain_Gain_ht;
  real32_T DiscreteTimeIntegrator_gainva_d;
  real32_T DiscreteTimeIntegrator_IC_e;
  real32_T C_Value[3];
  real32_T DiscreteTimeIntegrator_gainva_g;
  real32_T DiscreteTimeIntegrator_IC_c;
  real32_T DiscreteTimeIntegrator_gainv_oa;
  real32_T DiscreteTimeIntegrator_IC_a;
  real32_T DiscreteTimeIntegrator_gainva_p;
  real32_T DiscreteTimeIntegrator_gainv_gv;
  real32_T DiscreteTimeIntegrator_IC_l;
  real32_T DiscreteTimeIntegrator_UpperS_f;
  real32_T DiscreteTimeIntegrator_LowerS_k;
  real32_T DiscreteTimeIntegrator1_gainval;
  real32_T DiscreteTimeIntegrator1_IC;
  real32_T Gain_Gain_hz;
  real32_T DiscreteTimeIntegrator_gainva_c;
  real32_T DiscreteTimeIntegrator_IC_p;
  real32_T DiscreteTimeIntegrator_UpperS_o;
  real32_T DiscreteTimeIntegrator_LowerS_e;
  real32_T u05065_OnVal;
  real32_T u05065_OffVal;
  real32_T u05065_YOn;
  real32_T u05065_YOff;
  real32_T u0104_OnVal;
  real32_T u0104_OffVal;
  real32_T u0104_YOn;
  real32_T u0104_YOff;
  real32_T Delay_InitialCondition_kg;
  real32_T DiscreteTimeIntegrator_gainva_a;
  real32_T u0505_OnVal;
  real32_T u0505_OffVal;
  real32_T u0505_YOn;
  real32_T u0505_YOff;
  real32_T DiscreteTimeIntegrator_gainv_dv;
  real32_T DiscreteTimeIntegrator_IC_g;
  real32_T Delay1_InitialCondition_hr;
  real32_T DiscreteTimeIntegrator_gainva_n;
  real32_T DiscreteTimeIntegrator_IC_k;
  real32_T DiscreteTimeIntegrator_gainv_gl;
  real32_T DiscreteTimeIntegrator_IC_lj;
  real32_T DiscreteTimeIntegrator_UpperS_d;
  real32_T DiscreteTimeIntegrator_LowerS_f;
  real32_T DiscreteTimeIntegrator_gainva_m;
  real32_T DiscreteTimeIntegrator_IC_o;
  real32_T DiscreteTimeIntegrator_gainv_o3;
  real32_T DiscreteTimeIntegrator_IC_d;
  real32_T Delay_InitialCondition_jx;
  real32_T DiscreteTimeIntegrator1_gainv_a;
  real32_T DiscreteTimeIntegrator1_IC_j;
  real32_T Gain_Gain_fc;
  real32_T DiscreteTimeIntegrator_gainva_k;
  real32_T DiscreteTimeIntegrator_IC_n;
  real32_T DiscreteTimeIntegrator1_gainv_p;
  real32_T DiscreteTimeIntegrator1_IC_js;
  real32_T Gain1_Gain_n1;
  real32_T DiscreteTimeIntegrator_gainva_f;
  real32_T DiscreteTimeIntegrator_IC_i;
  real32_T DiscreteTimeIntegrator_gainv_ci;
  real32_T DiscreteTimeIntegrator_IC_cm;
  real32_T DiscreteTimeIntegrator_UpperS_l;
  real32_T DiscreteTimeIntegrator_LowerS_g;
  real32_T C1_Value[3];
  real32_T DiscreteTimeIntegrator_gainv_dp;
  real32_T DiscreteTimeIntegrator_gainva_l;
  real32_T DiscreteTimeIntegrator_IC_ce;
  real32_T DiscreteTimeIntegrator_UpperS_e;
  real32_T DiscreteTimeIntegrator_Lower_ec;
  real32_T DiscreteTimeIntegrator_gainv_pg;
  real32_T DiscreteTimeIntegrator_IC_f;
  real32_T DiscreteTimeIntegrator_Upper_d0;
  real32_T DiscreteTimeIntegrator_LowerS_n;
  real32_T DiscreteTimeIntegrator_gainv_l4;
  real32_T DiscreteTimeIntegrator_IC_f3;
  real32_T DiscreteTimeIntegrator_Upper_ex;
  real32_T DiscreteTimeIntegrator_LowerS_o;
  real32_T C_Value_f[3];
  real32_T Gain_Gain_kx;
  real32_T Constant_Value_gk;
  real32_T Gain_Gain_gy;
  real32_T Saturation_UpperSat_n;
  real32_T Saturation_LowerSat_lz;
  real32_T Gain1_Gain_d;
  real32_T u0504_OnVal;
  real32_T u0504_OffVal;
  real32_T u0504_YOn;
  real32_T u0504_YOff;
  real32_T u2065_OnVal;
  real32_T u2065_OffVal;
  real32_T u2065_YOn;
  real32_T u2065_YOff;
  real32_T DiscreteTimeIntegrator_gainv_lw;
  real32_T DiscreteTimeIntegrator_IC_m;
  real32_T u35085_OnVal;
  real32_T u35085_OffVal;
  real32_T u35085_YOn;
  real32_T u35085_YOff;
  real32_T Relay_OnVal_g;
  real32_T Relay_OffVal_i;
  real32_T Relay_YOn_k;
  real32_T Relay_YOff_e;
  real32_T DiscreteTimeIntegrator_gainv_pf;
  real32_T DiscreteTimeIntegrator_IC_f33;
  real32_T Constant_Value_fy[3];
  real32_T R_GRTK_B_Value[3];
  real32_T Gain1_Gain_f;
  real32_T Memory_InitialCondition;
  real32_T DiscreteTimeIntegrator_gainv_no;
  real32_T DiscreteTimeIntegrator_IC_gn;
  real32_T Constant_Value_om;
  real32_T Memory1_InitialCondition;
  real32_T Memory_InitialCondition_k;
  real32_T Saturation_UpperSat_g;
  real32_T Saturation_LowerSat_o5;
  real32_T DiscreteTimeIntegrator_gainv_a4;
  real32_T Constant_Value_ne;
  real32_T Constant_Value_cw[6];
  real32_T DiscreteTimeIntegrator1_gainv_n;
  real32_T DiscreteTimeIntegrator1_IC_n;
  real32_T Gain_Gain_m;
  real32_T process_noise_variance4_Value[2];
  real32_T Merge_InitialOutput;
  real32_T Delay2_InitialCondition;
  real32_T DiscreteTimeIntegrator5_gainval;
  real32_T DiscreteTimeIntegrator5_IC;
  real32_T DiscreteTimeIntegrator5_gainv_k;
  real32_T DiscreteTimeIntegrator5_IC_l;
  real32_T DiscreteTimeIntegrator_gainv_cj;
  real32_T DiscreteTimeIntegrator_IC_eg;
  real32_T DiscreteTimeIntegrator_gainv_pa;
  real32_T DiscreteTimeIntegrator_IC_ku;
  real32_T Delay3_InitialCondition;
  real32_T Delay_InitialCondition_o;
  real32_T DiscreteTimeIntegrator_gainv_p1;
  real32_T Delay1_InitialCondition_e;
  real32_T Delay_InitialCondition_b;
  real32_T DiscreteTimeIntegrator_gainv_mg;
  real32_T DiscreteTimeIntegrator_IC_pc;
  real32_T Delay1_InitialCondition_d;
  real32_T DiscreteTimeIntegrator_gainv_px;
  real32_T DiscreteTimeIntegrator_IC_a3;
  real32_T DiscreteTimeIntegrator_Upper_eh;
  real32_T DiscreteTimeIntegrator_LowerS_l;
  real32_T Gain1_Gain_o;
  real32_T SampleTime_WtEt_o;
  real32_T Saturation_UpperSat_l;
  real32_T Saturation_LowerSat_b;
  real32_T u9509_OnVal;
  real32_T u9509_OffVal;
  real32_T u9509_YOn;
  real32_T u9509_YOff;
  real32_T DiscreteTimeIntegrator_gainv_cw;
  real32_T DiscreteTimeIntegrator_IC_b;
  real32_T DiscreteTimeIntegrator_gainv_de;
  real32_T DiscreteTimeIntegrator_IC_d1;
  real32_T Gain_Gain_p4;
  real32_T DiscreteTimeIntegrator_gainv_mu;
  real32_T DiscreteTimeIntegrator_gainva_b;
  real32_T DiscreteTimeIntegrator_gainv_l5;
  real32_T DiscreteTimeIntegrator_gainv_o2;
  real32_T Merge1_InitialOutput;
  real32_T C_Value_n[3];
  real32_T DiscreteTimeIntegrator1_gainv_h;
  real32_T DiscreteTimeIntegrator1_IC_a;
  real32_T C_Value_j[3];
  real32_T R_Value_g;
  real32_T DiscreteTimeIntegrator1_gainv_l;
  real32_T Delay_InitialCondition_d;
  real32_T DiscreteTimeIntegrator_gainv_p2;
  real32_T DiscreteTimeIntegrator_IC_io;
  real32_T DiscreteTimeIntegrator_UpperS_b;
  real32_T DiscreteTimeIntegrator_LowerS_a;
  real32_T Gain2_Gain_p;
  real32_T DiscreteTimeIntegrator1_gainv_i;
  real32_T DiscreteTimeIntegrator1_IC_l;
  real32_T Gain1_Gain_fj;
  real32_T Saturation_UpperSat_d;
  real32_T Saturation_LowerSat_h;
  real32_T Saturation2_UpperSat_d;
  real32_T Saturation2_LowerSat_m;
  real32_T Gain3_Gain_l;
  real32_T Gain4_Gain_d;
  real32_T Gain5_Gain;
  real32_T DiscreteTimeIntegrator_gainv_ce;
  real32_T DiscreteTimeIntegrator_IC_pp;
  real32_T Gain1_Gain_oo;
  real32_T DiscreteTimeIntegrator1_gain_pl;
  real32_T DiscreteTimeIntegrator1_IC_nx;
  real32_T Gain_Gain_iv;
  real32_T DiscreteTimeIntegrator_gainva_e;
  real32_T Gain_Gain_b;
  real32_T Gain1_Gain_ot;
  real32_T Delay_InitialCondition_p;
  real32_T Constant_Value_g1;
  real32_T Constant_Value_m4;
  real32_T Constant_Value_mlz;
  real32_T DiscreteTimeIntegrator_gainv_f3;
  real32_T DiscreteTimeIntegrator_IC_kux;
  real32_T Gain1_Gain_i3;
  real32_T DiscreteTimeIntegrator1_gainv_o;
  real32_T DiscreteTimeIntegrator1_IC_p;
  real32_T Gain_Gain_ml;
  real32_T DiscreteTimeIntegrator_gainv_ah;
  real32_T DiscreteTimeIntegrator_IC_j;
  real32_T Gain1_Gain_nb;
  real32_T DiscreteTimeIntegrator1_gainv_d;
  real32_T DiscreteTimeIntegrator1_IC_m;
  real32_T Gain_Gain_pe;
  real32_T DiscreteTimeIntegrator1_gainv_g;
  real32_T Switch_Threshold;
  real32_T Switch_Threshold_b;
  real32_T DiscreteTimeIntegrator_gainv_oh;
  real32_T DiscreteTimeIntegrator_IC_ll;
  real32_T Gain1_Gain_nn;
  real32_T Gain_Gain_gj;
  real32_T Switch_Threshold_d;
  real32_T Constant_Value_ky;
  real32_T Gain_Gain_a;
  real32_T Gain_Gain_lh;
  real32_T Gain_Gain_d0;
  real32_T DiscreteTimeIntegrator_gainv_mn;
  real32_T DiscreteTimeIntegrator_IC_h;
  real32_T DiscreteTimeIntegrator_Upper_lw;
  real32_T DiscreteTimeIntegrator_LowerS_p;
  real32_T Constant_Value_cs;
  real32_T DiscreteTimeIntegrator_gainva_j;
  real32_T Gain_Gain_j;
  real32_T Gain_Gain_a2;
  real32_T Gain_Gain_n5;
  real32_T DiscreteTimeIntegrator5_gain_ko;
  real32_T DiscreteTimeIntegrator5_IC_c;
  real32_T Gain2_Gain_n;
  real32_T Gain2_Gain_m;
  real32_T DiscreteTimeIntegrator5_gainv_d;
  real32_T DiscreteTimeIntegrator5_IC_l3;
  real32_T Gain2_Gain_a;
  real32_T Gain2_Gain_ai;
  real32_T Constant_Value_c3;
  real32_T DiscreteTimeIntegrator_gainv_nq;
  real32_T DiscreteTimeIntegrator_IC_ao;
  real32_T Gain1_Gain_b;
  real32_T DiscreteTimeIntegrator1_gain_pj;
  real32_T DiscreteTimeIntegrator1_IC_f;
  real32_T Gain_Gain_e;
  real32_T DiscreteTimeIntegrator_gainv_ov;
  real32_T DiscreteTimeIntegrator_IC_dh;
  real32_T Gain1_Gain_l;
  real32_T DiscreteTimeIntegrator_gainv_mz;
  real32_T DiscreteTimeIntegrator_IC_db;
  real32_T Gain_Gain_ej;
  real32_T DiscreteTimeIntegrator_gain_dez;
  real32_T DiscreteTimeIntegrator_IC_lc;
  real32_T Gain1_Gain_k;
  real32_T DiscreteTimeIntegrator_gainv_lc;
  real32_T DiscreteTimeIntegrator_IC_hd;
  real32_T Gain_Gain_b5;
  real32_T DiscreteTimeIntegrator1_gain_ok;
  real32_T DiscreteTimeIntegrator1_IC_f2;
  real32_T Gain2_Gain_e;
  real32_T Gain3_Gain_f;
  real32_T DiscreteTimeIntegrator1_gain_dh;
  real32_T DiscreteTimeIntegrator1_IC_d;
  real32_T Gain2_Gain_k;
  real32_T Gain3_Gain_fx;
  real32_T Constant_Value_aj;
  real32_T Constant_Value_cx;
  real32_T DiscreteTimeIntegrator_gainv_je;
  real32_T DiscreteTimeIntegrator_IC_hv;
  real32_T Gain1_Gain_dh;
  real32_T DiscreteTimeIntegrator_gainv_al;
  real32_T DiscreteTimeIntegrator_IC_aj;
  real32_T Gain_Gain_pl;
  real32_T DiscreteTimeIntegrator1_gain_nm;
  real32_T DiscreteTimeIntegrator1_IC_jh;
  real32_T Gain2_Gain_g;
  real32_T Gain3_Gain_a;
  real32_T R_GCAMERA_B_Value[3];
  real32_T DiscreteTimeIntegrator_gainv_dr;
  real32_T DiscreteTimeIntegrator_IC_jv;
  real32_T Gain1_Gain_fa;
  real32_T DiscreteTimeIntegrator1_gain_nx;
  real32_T DiscreteTimeIntegrator1_IC_e;
  real32_T Gain_Gain_ep;
  real32_T DiscreteTimeIntegrator_gain_mnf;
  real32_T DiscreteTimeIntegrator_IC_je;
  real32_T Gain1_Gain_or;
  real32_T DiscreteTimeIntegrator1_gainv_f;
  real32_T DiscreteTimeIntegrator1_IC_i;
  real32_T Gain_Gain_nk;
  real32_T DiscreteTimeIntegrator_gainv_jb;
  real32_T DiscreteTimeIntegrator_IC_jp;
  real32_T Gain1_Gain_j;
  real32_T DiscreteTimeIntegrator_gainv_on;
  real32_T DiscreteTimeIntegrator_IC_kt;
  real32_T DiscreteTimeIntegrator_UpperS_h;
  real32_T DiscreteTimeIntegrator_LowerS_h;
  real32_T DiscreteTimeIntegrator_gainv_ko;
  real32_T DiscreteTimeIntegrator_IC_ng;
  real32_T DiscreteTimeIntegrator_UpperS_n;
  real32_T DiscreteTimeIntegrator_Lower_gy;
  real32_T DiscreteTimeIntegrator1_gainv_e;
  real32_T DiscreteTimeIntegrator1_IC_pg;
  real32_T Gain_Gain_bv;
  real32_T DiscreteTimeIntegrator_gainv_k4;
  real32_T DiscreteTimeIntegrator_IC_li;
  real32_T Gain1_Gain_d4;
  real32_T DiscreteTimeIntegrator1_gain_lj;
  real32_T DiscreteTimeIntegrator1_IC_fa;
  real32_T Gain_Gain_lc;
  real32_T DiscreteTimeIntegrator_gainv_lf;
  real32_T DiscreteTimeIntegrator_IC_bz;
  real32_T Gain1_Gain_p;
  real32_T DiscreteTimeIntegrator_gainv_fz;
  real32_T DiscreteTimeIntegrator_IC_eh;
  real32_T DiscreteTimeIntegrator1_gain_d1;
  real32_T DiscreteTimeIntegrator1_IC_lf;
  real32_T Gain_Gain_eg;
  real32_T Constant_Value_po;
  real32_T Constant1_Value_p;
  real32_T Gain_Gain_ax;
  real32_T Constant_Value_j0;
  real32_T Constant_Value_nz;
  real32_T Constant_Value_d4;
  real32_T Gain_Gain_ky;
  real32_T Saturation_UpperSat_j;
  real32_T Saturation_LowerSat_ds;
  real32_T P0_Value[16];
  real32_T x0_Value_g[2];
  real32_T DiscreteTimeIntegrator_gainv_ns;
  real32_T DiscreteTimeIntegrator_IC_oy;
  real32_T Constant_Value_kg;
  real32_T Constant_Value_kx[36];
  real32_T Delay1_InitialCondition_o[4];
  real32_T Delay2_InitialCondition_i;
  real32_T Ad_Value[36];
  real32_T WeightedSampleTime1_WtEt;
  real32_T process_noise_variance3_Value[6];
  real32_T DiscreteTimeIntegrator1_gainv_c;
  real32_T DiscreteTimeIntegrator1_IC_p4;
  real32_T UnitDelay_InitialCondition;
  real32_T DiscreteTimeIntegrator1_gain_ov;
  real32_T DiscreteTimeIntegrator1_IC_nw;
  real32_T Saturation1_UpperSat_f;
  real32_T Saturation1_LowerSat_m;
  real32_T Memory_InitialCondition_h;
  real32_T DiscreteTimeIntegrator_gainv_l1;
  real32_T DiscreteTimeIntegrator_IC_ir;
  real32_T Constant_Value_ck;
  real32_T WeightedSampleTime_WtEt;
  real32_T Memory1_InitialCondition_f;
  real32_T Gain_Gain_o;
  real32_T WeightedSampleTime3_WtEt;
  real32_T WeightedSampleTime2_WtEt;
  real32_T UnitDelay1_InitialCondition;
  real32_T Gain_Gain_ow;
  real32_T Constant_Value_ho[12];
  real32_T Memory_InitialCondition_n[2];
  real32_T Saturation_UpperSat_ky;
  real32_T Saturation_LowerSat_c;
  real32_T Memory1_InitialCondition_e[2];
  real32_T Gain_Gain_kh;
  real32_T DiscreteTimeIntegrator_gainv_dq;
  real32_T Saturation_UpperSat_fw;
  real32_T Saturation_LowerSat_cc;
  real32_T Constant_Value_ak[4];
  real32_T Constant1_Value_hy[12];
  real32_T Constant_Value_i4[24];
  real32_T Constant_Value_fv[16];
  real32_T Merge1_InitialOutput_k;
  real32_T DiscreteTimeIntegrator_gainv_nu;
  real32_T DiscreteTimeIntegrator_IC_oo;
  real32_T Merge_InitialOutput_k;
  real32_T Gain_Gain_a3;
  real32_T DiscreteTimeIntegrator_gainv_c5;
  real32_T DiscreteTimeIntegrator_gainv_mw;
  real32_T MeaMatrix_Value[8];
  real32_T SampleTime_WtEt_h;
  real32_T Constant_Value_nx[4];
  real32_T DiscreteTimeIntegrator_gainv_mh;
  real32_T DiscreteTimeIntegrator_IC_f2;
  real32_T Gain_Gain_pc;
  real32_T DiscreteTimeIntegrator_gain_dqh;
  real32_T DiscreteTimeIntegrator_gainva_h;
  real32_T MeaMatrix_Value_k[8];
  real32_T Saturation_UpperSat_n3;
  real32_T Saturation_LowerSat_i;
  real32_T DiscreteTimeIntegrator_gainv_dz;
  real32_T UnitDelay_InitialCondition_e;
  real32_T DiscreteTimeIntegrator_gainv_pr;
  real32_T DiscreteTimeIntegrator_IC_bh;
  real32_T DiscreteTimeIntegrator_UpperS_c;
  real32_T DiscreteTimeIntegrator_Lower_kn;
  real32_T DiscreteTimeIntegrator_gainv_kp;
  real32_T DiscreteTimeIntegrator_IC_ck;
  real32_T DiscreteTimeIntegrator_Upper_o4;
  real32_T DiscreteTimeIntegrator_LowerS_d;
  real32_T DiscreteTimeIntegrator_gainv_ct;
  real32_T DiscreteTimeIntegrator_IC_lx;
  real32_T DiscreteTimeIntegrator_gainv_cc;
  real32_T DiscreteTimeIntegrator_IC_ln;
  real32_T Gain_Gain_hn;
  real32_T DiscreteTimeIntegrator_gainv_nx;
  real32_T DiscreteTimeIntegrator_gainv_kl;
  real32_T Constant_Value_l3[12];
  real32_T Constant_Value_kxd[4];
  real32_T uDLookupTable_tableData[6];
  real32_T uDLookupTable_bp01Data[6];
  real32_T Saturation_UpperSat_ct;
  real32_T Saturation_LowerSat_m1;
  real32_T Constant_Value_mz;
  real32_T Gain_Gain_kl;
  real32_T Gain_Gain_m1;
  real32_T DiscreteTimeIntegrator_gainv_n3;
  real32_T DiscreteTimeIntegrator_gainv_kk;
  real32_T Saturation_UpperSat_oa;
  real32_T Saturation_LowerSat_ot;
  real32_T Gain_Gain_lq;
  real32_T Gain_Gain_je;
  real32_T DiscreteTimeIntegrator_gainv_dt;
  real32_T DiscreteTimeIntegrator_IC_k4;
  real32_T Gain1_Gain_a;
  real32_T Gain1_Gain_ok;
  real32_T Gain_Gain_hb;
  real32_T DiscreteTimeIntegrator_gainv_m5;
  real32_T DiscreteTimeIntegrator_IC_m1;
  real32_T Gain1_Gain_kg;
  real32_T Gain_Gain_f3;
  real32_T Constant_Value_ep;
  real32_T Gain_Gain_mp;
  real32_T Gain_Gain_ah;
  real32_T DiscreteTimeIntegrator_gainv_mq;
  real32_T DiscreteTimeIntegrator_IC_ds;
  real32_T Gain1_Gain_jn;
  real32_T Gain_Gain_er;
  real32_T Constant_Value_hv;
  real32_T Gain_Gain_hx;
  real32_T Constant_Value_gu;
  real32_T Gain_Gain_bu;
  real32_T Gain_Gain_d3;
  real32_T Constant_Value_o1;
  real32_T Gain_Gain_jv;
  real32_T Constant_Value_go;
  real32_T Constant_Value_mf;
  uint32_T Delay_DelayLength;
  uint32_T Delay1_DelayLength;
  uint32_T Delay_DelayLength_n;
  uint32_T Delay1_DelayLength_d;
  uint32_T Delay_DelayLength_i;
  uint32_T Delay1_DelayLength_k;
  uint32_T Delay_DelayLength_l;
  uint32_T Delay1_DelayLength_i;
  uint32_T Delay_DelayLength_a;
  uint32_T Delay1_DelayLength_io;
  uint32_T Delay2_DelayLength;
  uint32_T Delay_DelayLength_lh;
  uint32_T Delay_DelayLength_m;
  uint32_T Delay1_DelayLength_l;
  uint32_T Delay_DelayLength_lf;
  uint32_T Delay1_DelayLength_b;
  uint32_T Delay_DelayLength_lg;
  uint32_T Delay1_DelayLength_c;
  uint32_T Delay2_DelayLength_k;
  uint32_T Delay1_DelayLength_bu;
  uint32_T Int_X_DelayLength;
  uint32_T Delay_10_DelayLength;
  uint32_T Delay_2_DelayLength;
  uint32_T Delay_DelayLength_k;
  uint32_T Delay1_DelayLength_e;
  uint32_T Delay1_DelayLength_o;
  uint32_T Delay_DelayLength_j;
  uint32_T Delay_DelayLength_e;
  uint32_T Delay_DelayLength_p;
  uint32_T Delay_DelayLength_kx;
  uint32_T Delay1_DelayLength_lv;
  uint32_T Delay_DelayLength_d;
  uint32_T Delay_DelayLength_az;
  uint32_T Delay_DelayLength_ne;
  uint32_T Delay_DelayLength_dk;
  uint32_T Delay_DelayLength_lr;
  uint32_T Delay_DelayLength_la;
  uint32_T Delay_DelayLength_pq;
  uint32_T x_delay_DelayLength;
  uint32_T x_delay1_DelayLength;
  uint32_T Delay_DelayLength_kk;
  uint32_T Delay_DelayLength_g;
  uint32_T Delay1_DelayLength_od;
  uint32_T Delay2_DelayLength_p;
  uint32_T Delay_DelayLength_mc;
  uint32_T Delay_DelayLength_kk4;
  uint32_T Delay2_DelayLength_kx;
  uint32_T Delay3_DelayLength;
  uint32_T Delay1_DelayLength_bj;
  uint32_T Delay_DelayLength_pc;
  uint32_T Delay2_DelayLength_a;
  uint32_T Delay1_DelayLength_a;
  uint32_T Delay_DelayLength_p3;
  uint32_T Delay_DelayLength_ei;
  uint32_T Delay1_DelayLength_m;
  uint32_T Delay_DelayLength_em;
  uint32_T Delay1_DelayLength_j;
  uint32_T Delay2_DelayLength_l;
  uint32_T Delay_DelayLength_nb;
  uint32_T Delay_DelayLength_dy;
  uint32_T Delay_DelayLength_o;
  uint32_T Delay_DelayLength_c;
  uint32_T Delay_DelayLength_ob;
  uint32_T Delay1_DelayLength_ja;
  uint32_T Delay_DelayLength_n0;
  uint32_T Delay_DelayLength_ol;
  uint32_T Delay1_DelayLength_n;
  uint32_T Int_P_DelayLength;
  uint32_T Delay2_DelayLength_m;
  uint32_T Delay_DelayLength_b;
  uint32_T y_delay1_DelayLength;
  uint32_T y_delay2_DelayLength;
  uint32_T Delay_DelayLength_lw;
  uint32_T Delay1_DelayLength_mx;
  uint32_T x_delay_DelayLength_e;
  uint32_T y_delay_DelayLength;
  uint32_T Delay1_DelayLength_ev;
  uint32_T x_delay_DelayLength_c;
  uint32_T Delay_DelayLength_kg;
  uint32_T Delay1_DelayLength_cb;
  uint32_T y_delay_DelayLength_k;
  uint32_T Delay_DelayLength_a5;
  uint16_T Memory_InitialCondition_n4;
  uint16_T Constant_Value_hc;
  uint16_T Delay1_InitialCondition_oq;
  boolean_T Constant_Value_d4d;
  boolean_T Constant4_Value_l;
  boolean_T Constant_Value_er;
  boolean_T Delay2_InitialCondition_h;
  boolean_T Constant_Value_fw;
  boolean_T Constant_Value_lk5;
  boolean_T Constant_Value_l1;
  boolean_T Delay_InitialCondition_l;
  boolean_T UnitDelay_InitialCondition_f;
  boolean_T Delay1_InitialCondition_p;
  boolean_T Delay_InitialCondition_i0;
  boolean_T Delay_InitialCondition_ib;
  boolean_T Delay_InitialCondition_b2;
  boolean_T Delay_InitialCondition_n2;
  boolean_T Delay_InitialCondition_lu;
  boolean_T Delay_InitialCondition_mv;
  boolean_T Delay_InitialCondition_h;
  boolean_T Delay_InitialCondition_k1;
  boolean_T Delay_InitialCondition_jp;
  boolean_T Delay1_InitialCondition_j;
  boolean_T Delay_InitialCondition_o1;
  boolean_T Delay_InitialCondition_f;
  boolean_T Delay2_InitialCondition_f;
  boolean_T Delay1_InitialCondition_dl;
  boolean_T Delay_InitialCondition_mb;
  boolean_T Delay1_InitialCondition_di;
  boolean_T Delay_InitialCondition_d5;
  boolean_T Delay_InitialCondition_al;
  boolean_T Delay_InitialCondition_e;
  boolean_T Constant5_Value_e;
  boolean_T Constant2_Value_e;
  boolean_T Delay_InitialCondition_ps;
  boolean_T Delay_InitialCondition_lg;
  boolean_T Delay_InitialCondition_c;
  boolean_T Delay_InitialCondition_fp;
  boolean_T Delay1_InitialCondition_lq;
  boolean_T Delay1_InitialCondition_c;
  boolean_T Delay_InitialCondition_h3;
  uint8_T Gain3_Gain_j;
  uint8_T Gain2_Gain_kw;
  uint8_T Gain1_Gain_je;
  uint8_T Switch_Threshold_g;
  uint8_T Switch_Threshold_l;
  uint8_T Switch_Threshold_e;
  uint8_T ManualSwitch1_CurrentSetting;
  uint8_T ManualSwitch_CurrentSetting;
  P_Correct_y_Translation_Fusio_T Correct_y;
  P_Correct_x_Translation_Fus_j_T Correct_x;
  P_Correct_x_Translation_Fus_m_T Correct_y_c;
  P_Correct_x_Translation_Fus_m_T Correct_x_j;
  P_Correct_x_Translation_Fusio_T Correct_y_b;
  P_Correct_x_Translation_Fusio_T Correct_x_a;
  P_Correct_y_Translation_Fusio_T Correct_y_f;
  P_Correct_x_Translation_Fus_j_T Correct_x_d;
  P_Correct_x_Translation_Fusio_T Correct_x_m;
};

#endif

typedef struct P_Translation_Fusion_T_ P_Translation_Fusion_T;

#ifndef Translation_Fusion_MDLREF_HIDE_CHILD_

struct tag_RTM_Translation_Fusion_T {
  const char_T **errorStatus;
};

#endif

#ifndef Translation_Fusion_MDLREF_HIDE_CHILD_

typedef struct {
  RT_MODEL_Translation_Fusion_T rtm;
} MdlrefDW_Translation_Fusion_T;

#endif

#ifndef Translation_Fusion_MDLREF_HIDE_CHILD_

extern P_Translation_Fusion_T Translation_Fusion_P_g;

#endif

extern void Translation_Fusion_Init(real32_T *rty_Vx_cor);
extern void Translation_Fusion_Reset(void);
extern void Translation_Fusion_Start(void);
extern void Translation_Fusion_Disable(void);
extern void Translation_Fusion(const real32_T rtu_Rotation_M_OB[9], const
  real32_T rtu_Rotation_rot_IB_B_radDs[3], const real32_T
  rtu_Rotation_sfor_R_B_mDs2[3], const real32_T *rtu_Rotation_Psi_dot_fused,
  const real32_T *rtu_Rotation_Psi_dot_IMU, const real32_T rtu_Rotation_M_OObar
  [4], const real32_T *rtu_Rotation_Euler_Transformati, const real32_T
  *rtu_Rotation_Euler_Transforma_h, const real32_T
  *rtu_Rotation_Euler_Transforma_k, const real32_T *rtu_Rotation_standstill,
  const boolean_T *rtu_Rotation_reset_Yaw, const real32_T
  *rtu_Sensor_delta_h_baro_m, const boolean_T *rtu_Sensor_baro_valid, const
  real32_T *rtu_Sensor_baro_Timestamp_ms, const boolean_T
  *rtu_Sensor_GPS_data_GPS_reset, const real32_T
  *rtu_Sensor_GPS_data_Spd_quality, const real32_T
  *rtu_Sensor_GPS_data_Pos_quality, const real32_T *rtu_Sensor_GPS_data_Status,
  const real_T *rtu_Sensor_GPS_data_dx_dmue, const real_T
  *rtu_Sensor_GPS_data_dy_dlambda, const real_T *rtu_Sensor_GPS_data_mue_rad,
  const real_T *rtu_Sensor_GPS_data_lambda_rad, const real32_T
  *rtu_Sensor_GPS_data_vel_N, const real32_T *rtu_Sensor_GPS_data_vel_E, const
  real32_T *rtu_Sensor_GPS_data_vel_D, const real32_T
  *rtu_Sensor_GPS_data_Timestamp_m, const real32_T
  *rtu_Sensor_GPS_data_GpsHeight, const uint8_T *rtu_Sensor_RTK_Data_RTK_status,
  const real32_T rtu_Sensor_RTK_Data_pos_quality[3], const real32_T
  rtu_Sensor_RTK_Data_vel_quality[3], const uint32_T
  *rtu_Sensor_RTK_Data_rtk_type, const real_T *rtu_Sensor_RTK_Data_dx_dmue,
  const real_T *rtu_Sensor_RTK_Data_dy_dlambda, const real_T
  *rtu_Sensor_RTK_Data_dz_dh, const real_T *rtu_Sensor_RTK_Data_mue_rad, const
  real_T *rtu_Sensor_RTK_Data_lambda_rad, const real_T
  *rtu_Sensor_RTK_Data_height_m, const real32_T *rtu_Sensor_RTK_Data_vel_N,
  const real32_T *rtu_Sensor_RTK_Data_vel_E, const real32_T
  *rtu_Sensor_RTK_Data_vel_D, const uint32_T *rtu_Sensor_RTK_Data_Timestamp_m,
  const boolean_T *rtu_Sensor_Sonar_data_sonar_val, const real32_T
  *rtu_Sensor_Sonar_data_h_grd_son, const uint32_T
  *rtu_Sensor_Sonar_data_timestamp, const real32_T
  rtu_Sensor_Vision_data_vel_xy_O[2], const real32_T
  *rtu_Sensor_Vision_data_Vision_q, const boolean_T
  *rtu_Sensor_Vision_data_Vision_v, const uint32_T
  *rtu_Sensor_Vision_data_timestam, const real32_T
  *rtu_Sensor_Vision_data_vel_z_O_, const real32_T
  *rtu_Sensor_Vision_data_delta_po, const real32_T
  *rtu_Sensor_Vision_data_delta__d, const real32_T
  *rtu_Sensor_Vision_data_delta__m, const uint8_T *rtu_Sensor_Vision_data_type,
  const boolean_T *rtu_Armed, const boolean_T *rtu_Ongrd_flag, const boolean_T
  *rtu_hover_flag, const real32_T *rtu_mode, const boolean_T *rtu_forcedArm,
  const boolean_T *rtu_IMU_switch, real32_T *rty_Translation_data_h_dot_mDs,
  real32_T *rty_Translation_data_h_AGL_m, real32_T
  *rty_Translation_data_h_0_AGL_m, real32_T *rty_Translation_data_delta_h_m,
  real32_T *rty_Translation_data_Bias_z_mDs, real32_T
  rty_Translation_data_VEL_xy_O_m[2], real32_T rty_Translation_data_ACC_xy_O_m[2],
  real_T *rty_Translation_data_mue_est_ra, real_T
  *rty_Translation_data_lambda_est, real32_T rty_Translation_data_POS_xy_O_m[2],
  boolean_T *rty_Translation_data_POS_reset_, boolean_T
  *rty_Translation_data_GPS_Vel_Va, boolean_T *rty_Translation_data_VO_Vel_Val,
  real_T *rty_Translation_data_mue_est__e, real_T
  *rty_Translation_data_lambda_e_o, real32_T rty_acc_bias_B[3], boolean_T
  *rty_RTK_Pos_Good, real32_T *rty_h_MSL, real32_T rty_Vel_G[3], real_T
  rty_Pos_LL_WGS84_Camera[2], boolean_T *rty_Pos_Init_flg, real32_T
  *rty_h_0_m_MSL, real32_T *rty_GPS_logic_log_Status, real32_T
  *rty_GPS_logic_log_Ts_Update, real32_T *rty_GPS_logic_log_En_GPS_cor_co,
  real32_T *rty_GPS_logic_log_En_GPS_Valid, real32_T
  *rty_GPS_logic_log_En_GPS_Correc, real32_T *rty_Vx_cor);
extern void Translation_Fusion_Term(void);
extern void Translation_Fusion_initialize(const char_T **rt_errorStatus);

#ifndef Translation_Fusion_MDLREF_HIDE_CHILD_

extern void Translation_MovingAverage2_Init(DW_MovingAverage2_Translation_T
  *localDW);
extern void Translatio_MovingAverage2_Start(DW_MovingAverage2_Translation_T
  *localDW);
extern void Translation_Fusi_MovingAverage2(real32_T rtu_0,
  B_MovingAverage2_Translation__T *localB, DW_MovingAverage2_Translation_T
  *localDW);
extern void Translation_Fusion_Average_Init(DW_Average_Translation_Fusion_T
  *localDW);
extern void Translation_Fusio_Average_Reset(DW_Average_Translation_Fusion_T
  *localDW);
extern void Translation_Fusio_Average_Start(DW_Average_Translation_Fusion_T
  *localDW);
extern void Translation_Fusion_Average(real32_T rtu_0,
  B_Average_Translation_Fusion_T *localB, DW_Average_Translation_Fusion_T
  *localDW);
extern void Translation_Fusi_Correct_x_Init(B_Correct_x_Translation_Fusio_T
  *localB, P_Correct_x_Translation_Fusio_T *localP);
extern void Translation_Fusion_Correct_x(boolean_T rtu_Enable, real32_T
  rtu_Delay_X, real32_T rtu_Delay_X_a, real32_T rtu_Delay_X_h, const real32_T
  rtu_P[9], const real32_T rtu_H[6], real32_T rtu_Z, real32_T rtu_Z_o, const
  real32_T rtu_R[4], B_Correct_x_Translation_Fusio_T *localB,
  P_Correct_x_Translation_Fusio_T *localP);
extern void Translation_Fusi_Average_a_Init(DW_Average_Translation_Fusi_f_T
  *localDW);
extern void Translation_Fus_Average_d_Reset(DW_Average_Translation_Fusi_f_T
  *localDW);
extern void Translation_Fus_Average_m_Start(DW_Average_Translation_Fusi_f_T
  *localDW);
extern void Translation_Fusion_Average_p(real32_T rtu_0,
  B_Average_Translation_Fusio_c_T *localB, DW_Average_Translation_Fusi_f_T
  *localDW);
extern void Translation_Fu_Correct_x_e_Init(B_Correct_x_Translation_Fus_h_T
  *localB, P_Correct_x_Translation_Fus_j_T *localP);
extern void Translation_Fusion_Correct_x_d(boolean_T rtu_Enable, real32_T
  rtu_Delay_X, real32_T rtu_Delay_X_l, real32_T rtu_Delay_X_o, const real32_T
  rtu_P[9], const real32_T rtu_H[3], real32_T rtu_Z, real32_T rtu_R,
  B_Correct_x_Translation_Fus_h_T *localB, P_Correct_x_Translation_Fus_j_T
  *localP);
extern void Translation_Fusi_Correct_y_Init(B_Correct_y_Translation_Fusio_T
  *localB, P_Correct_y_Translation_Fusio_T *localP);
extern void Translation_Fusion_Correct_y(boolean_T rtu_Enable, real32_T
  rtu_Delay_X, real32_T rtu_Delay_X_c, real32_T rtu_Delay_X_l, const real32_T
  rtu_P[9], const real32_T rtu_H[3], real32_T rtu_Z, real32_T rtu_R,
  B_Correct_y_Translation_Fusio_T *localB, P_Correct_y_Translation_Fusio_T
  *localP);
extern void Translation_Fu_Correct_x_l_Init(B_Correct_x_Translation_Fus_o_T
  *localB, P_Correct_x_Translation_Fus_m_T *localP);
extern void Translation_Fusion_Correct_x_j(boolean_T rtu_Enable, real32_T
  rtu_Delay_X, real32_T rtu_Delay_X_j, real32_T rtu_Delay_X_d, const real32_T
  rtu_P[9], const real32_T rtu_H[3], real32_T rtu_Z, real32_T rtu_R,
  B_Correct_x_Translation_Fus_o_T *localB, P_Correct_x_Translation_Fus_m_T
  *localP);
extern void Translation_MovingAverage3_Init(DW_MovingAverage3_Translation_T
  *localDW);
extern void Translatio_MovingAverage3_Reset(DW_MovingAverage3_Translation_T
  *localDW);
extern void Translatio_MovingAverage3_Start(DW_MovingAverage3_Translation_T
  *localDW);
extern void Translation_Fusi_MovingAverage3(real32_T rtu_0,
  B_MovingAverage3_Translation__T *localB, DW_MovingAverage3_Translation_T
  *localDW);
extern void Translation_MovingAverage1_Init(DW_MovingAverage1_Translation_T
  *localDW);
extern void Translatio_MovingAverage1_Reset(DW_MovingAverage1_Translation_T
  *localDW);
extern void Translatio_MovingAverage1_Start(DW_MovingAverage1_Translation_T
  *localDW);
extern void Translation_Fusi_MovingAverage1(real32_T rtu_0,
  B_MovingAverage1_Translation__T *localB, DW_MovingAverage1_Translation_T
  *localDW);
extern void Translati_MovingAverage1_a_Init(DW_MovingAverage1_Translati_f_T
  *localDW);
extern void Translat_MovingAverage1_o_Reset(DW_MovingAverage1_Translati_f_T
  *localDW);
extern void Translat_MovingAverage1_p_Start(DW_MovingAverage1_Translati_f_T
  *localDW);
extern void Translation_Fu_MovingAverage1_p(real32_T rtu_0,
  B_MovingAverage1_Translatio_c_T *localB, DW_MovingAverage1_Translati_f_T
  *localDW);
extern void Translation_MovingAverage2_Term(DW_MovingAverage2_Translation_T
  *localDW);
extern void Translation_Fusion_Average_Term(DW_Average_Translation_Fusion_T
  *localDW);
extern void Translation_Fusi_Average_n_Term(DW_Average_Translation_Fusi_f_T
  *localDW);
extern void Translation_MovingAverage3_Term(DW_MovingAverage3_Translation_T
  *localDW);
extern void Translation_MovingAverage1_Term(DW_MovingAverage1_Translation_T
  *localDW);
extern void Translati_MovingAverage1_g_Term(DW_MovingAverage1_Translati_f_T
  *localDW);

#endif

#ifndef Translation_Fusion_MDLREF_HIDE_CHILD_

extern MdlrefDW_Translation_Fusion_T Translation_Fusion_MdlrefDW;

#endif

#ifndef Translation_Fusion_MDLREF_HIDE_CHILD_

extern B_Translation_Fusion_c_T Translation_Fusion_B;
extern DW_Translation_Fusion_f_T Translation_Fusion_DW;
extern ZCE_Translation_Fusion_T Translation_Fusion_PrevZCX;

#endif
#endif

