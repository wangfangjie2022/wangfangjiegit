#ifndef RTW_HEADER_Rotation_AHRS_GPS_h_
#define RTW_HEADER_Rotation_AHRS_GPS_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"
#include <float.h>
#include <math.h>
#ifndef Rotation_AHRS_GPS_COMMON_INCLUDES_
# define Rotation_AHRS_GPS_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#endif

#include "multiword_types.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include "mw_cmsis.h"
#include "rt_defines.h"
#include "rtGetInf.h"

typedef struct tag_RTM_Rotation_AHRS_GPS_T RT_MODEL_Rotation_AHRS_GPS_T;

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
  real32_T pCumSumRev[9];
  real32_T pCumRevIndex;
} dsp_private_SlidingWindowAver_T;

#endif

#ifndef typedef_cell_wrap_Rotation_AHRS_GPS_T
#define typedef_cell_wrap_Rotation_AHRS_GPS_T

typedef struct {
  uint32_T f1[8];
} cell_wrap_Rotation_AHRS_GPS_T;

#endif

#ifndef typedef_dsp_simulink_MovingAverage_Ro_T
#define typedef_dsp_simulink_MovingAverage_Ro_T

typedef struct {
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  boolean_T TunablePropsChanged;
  cell_wrap_Rotation_AHRS_GPS_T inputVarSize;
  dsp_private_SlidingWindowAver_T *pStatistic;
  int32_T NumChannels;
} dsp_simulink_MovingAverage_Ro_T;

#endif

#ifndef Rotation_AHRS_GPS_MDLREF_HIDE_CHILD_

typedef struct {
  real32_T MovingAverage2;
} B_MovingAverage2_Rotation_AHR_T;

#endif

#ifndef Rotation_AHRS_GPS_MDLREF_HIDE_CHILD_

typedef struct {
  dsp_simulink_MovingAverage_Ro_T obj;
  dsp_private_SlidingWindowAver_T gobj_0;
  dsp_private_SlidingWindowAver_T gobj_1;
  boolean_T objisempty;
} DW_MovingAverage2_Rotation_AH_T;

#endif

#ifndef Rotation_AHRS_GPS_MDLREF_HIDE_CHILD_

typedef struct {
  real32_T MathFunction2[9];
  real32_T VectorConcatenate_p[9];
  real32_T MathFunction3[9];
  real32_T VectorConcatenate_i[9];
  real32_T rtb_MathFunction2_m[9];
  real32_T Switch_c[7];
  real32_T u[7];
  real32_T TmpSignalConversionAtDelayI[7];
  real32_T VectorConcatenate_k[4];
  real32_T Divide3[4];
  real32_T acc_body[3];
  real32_T DiscreteTimeIntegrator[3];
  real32_T In1[7];
  real32_T Gain10[3];
  real32_T Delay_h[3];
  real32_T Subtract_m[3];
  real32_T omg_O[3];
  real32_T DiscreteTimeIntegrator1_e[3];
  real32_T MatrixMultiply_m[3];
  real32_T DiscreteFIRFilter1[3];
  real32_T DiscreteFIRFilter[3];
  real32_T DiscreteTimeIntegrator_c[3];
  real32_T DiscreteTimeIntegrator_a[3];
  real32_T CaliYawMAG[3];
  real32_T Product_e[3];
  real32_T rtb_MatrixMultiply2_p_tmp[3];
  real32_T fv0[3];
  real32_T Gain1_i[3];
  real32_T Saturation;
  real32_T TrigonometricFunction;
  real32_T Sum;
  real32_T Sum_e;
  real32_T Sum_h;
  real32_T Sum_hp;
  real32_T Switch[7];
  real32_T VectorConcatenate[3];
  real32_T DiscreteTimeIntegrator1_k;
  real32_T Saturation1;
  real32_T DiscreteTimeIntegrator_pd;
  real32_T DiscreteTimeIntegrator_gg;
  real32_T atan1;
  real32_T fcn5;
  real32_T Product2_jx;
  real32_T Product2_eb;
  real32_T Abs_o;
  real32_T Divide1_i;
  real32_T DiscreteTimeIntegrator_if;
  real32_T DiscreteTimeIntegrator_io;
  real32_T DiscreteTimeIntegrator_oa;
  real32_T relay;
  real32_T det_yaw_mag_c;
  real32_T DataTypeConversion;
  real32_T DiscreteTimeIntegrator1_m;
  real32_T Gain_n;
  real32_T DiscreteTimeIntegrator1_f;
  real32_T mag_gain2_l;
  real32_T DiscreteTimeIntegrator_h;
  real32_T DiscreteTimeIntegrator_g5;
  real32_T DiscreteTimeIntegrator_mg;
  real32_T Product_hu;
  real32_T DataTypeConversion_p;
  real32_T Subtract_kk;
  real32_T Product_dn;
  real32_T Product2_n2;
  real32_T Product3_k;
  real32_T Product_ge;
  real32_T Product1_h1;
  real32_T Product2_lr;
  real32_T Product3_jr;
  real32_T Sum_e_k;
  real32_T Sum_d2e;
  real32_T u0;
  real32_T rtb_Product_e_c;
  real32_T rtb_VectorConcatenate1_b;
  real32_T rtb_Divide2_p;
  real32_T rtb_Product_em_idx_3;
  real32_T rtb_Product_em_idx_0;
  real32_T rtb_VectorConcatenate1_idx_0;
  real32_T rtb_Sum_jx_idx_0;
  real32_T rtb_DiscreteTimeIntegrator1_i_i;
  real32_T rtb_DiscreteTimeIntegrator1_i_f;
  real32_T rtb_acc_GPS_est_idx_0;
  real32_T rtb_acc_GPS_est_idx_1;
  real32_T rtb_Sum_jx_idx_1;
  real32_T rtb_Product_em_idx_1;
  real32_T rtb_Product_em_idx_2;
  real32_T rtb_Divide2_idx_0;
  real32_T rtb_Divide2_idx_1;
  real32_T rtb_DiscreteTimeIntegrator_fl_i;
  real32_T rtb_DiscreteTimeIntegrator_fl_g;
  real32_T rtb_DiscreteTimeIntegrator_fr_i;
  real32_T rtb_DiscreteTimeIntegrator_fr_n;
  real32_T rtb_DiscreteTimeIntegrator_l4_i;
  real32_T rtb_DiscreteTimeIntegrator_l4_l;
  real32_T rtb_DiscreteTimeIntegrator_l4_j;
  real32_T rtb_Divide_idx_0;
  real32_T rtb_Divide_idx_1;
  real32_T rtb_Divide_idx_2;
  real32_T rtb_DiscreteTimeIntegrator1_idx;
  real32_T rtb_DiscreteTimeIntegrator1_i_g;
  real32_T rtb_Multiply1_idx_0;
  real32_T rtb_Sum_b_idx_0;
  real32_T rtb_Multiply1_idx_1;
  real32_T rtb_Sum_b_idx_1;
  real32_T rtb_Multiply1_idx_2;
  real32_T rtb_Sum_b_idx_2;
  real32_T rtb_MathFunction_l_idx_0;
  real32_T y;
  real32_T y_l;
  real32_T rtb_DiscreteTimeIntegrator_mg_t;
  real32_T q;
  int32_T j;
  int32_T i;
  int32_T rtb_MathFunction2_tmp;
  int32_T rtb_MathFunction2_tmp_d;
  int32_T u0_l;
  int32_T u1;
  uint8_T Sum2_j;
  boolean_T LogicalOperator8_e;
  boolean_T trigger_reset;
  boolean_T Compare_huc;
  boolean_T DataTypeConversion1_j;
  boolean_T LogicalOperator1;
  boolean_T Memory2;
  boolean_T Compare_on;
  boolean_T DataTypeConversion1_ba;
  boolean_T LogicalOperator_e;
  boolean_T LogicalOperator6_m;
  boolean_T Compare_g;
  boolean_T Compare_b;
  boolean_T mag_reset2;
  boolean_T enable;
  boolean_T Compare_m;
  boolean_T LogicalOperator18;
  boolean_T LogicalOperator1_i;
  boolean_T Compare_if;
  boolean_T FixPtRelationalOperator_m;
  boolean_T LogicalOperator_f;
  boolean_T Compare_ep;
  boolean_T LogicalOperator3_f;
  boolean_T LogicalOperator_h;
  boolean_T Compare_go;
  boolean_T need_to_compensate;
  boolean_T Delay_p;
  boolean_T Compare_nc;
  boolean_T LogicalOperator1_c;
  boolean_T Compare_bk;
  boolean_T Delay4_e;
  boolean_T Delay_m;
  boolean_T DataTypeConversion1_e;
  boolean_T LogicalOperator6_d;
  boolean_T LogicalOperator_a;
  boolean_T LogicalOperator8_d;
  boolean_T Uk1;
  boolean_T LogicalOperator2_p;
  boolean_T Compare_c2;
  boolean_T Compare_c;
  boolean_T Compare_g4;
  boolean_T FixPtRelationalOperator_ke;
  boolean_T LogicalOperator1_hy;
  B_MovingAverage2_Rotation_AHR_T MovingAverage3;
  B_MovingAverage2_Rotation_AHR_T MovingAverage1;
  B_MovingAverage2_Rotation_AHR_T MovingAverage2;
} B_Rotation_AHRS_GPS_c_T;

#endif

#ifndef Rotation_AHRS_GPS_MDLREF_HIDE_CHILD_

typedef struct {
  real32_T Delay17_DSTATE[7];
  real32_T Delay16_DSTATE[7];
  real32_T DiscreteTimeIntegrator_DSTATE;
  real32_T DiscreteTimeIntegrator_DSTATE_a[2];
  real32_T DiscreteTimeIntegrator_DSTATE_g[2];
  real32_T DiscreteTimeIntegrator1_DSTATE;
  real32_T DiscreteTimeIntegrator_DSTATE_o;
  real32_T Delay13_DSTATE[7];
  real32_T Delay12_DSTATE[7];
  real32_T DiscreteTimeIntegrator1_DSTAT_c;
  real32_T DiscreteTimeIntegrator_DSTATE_i;
  real32_T Delay_DSTATE[7];
  real32_T DiscreteFIRFilter1_states[12];
  real32_T DiscreteTimeIntegrator_DSTAT_gs;
  real32_T DiscreteTimeIntegrator_DSTAT_oe[3];
  real32_T DiscreteFIRFilter_states[12];
  real32_T DiscreteTimeIntegrator_DSTATE_m;
  real32_T DiscreteTimeIntegrator_DSTATE_b;
  real32_T Delay2_DSTATE[7];
  real32_T Delay1_DSTATE[7];
  real32_T Delay_DSTATE_n[7];
  real32_T DiscreteTimeIntegrator_DSTAT_ab;
  real32_T Delay1_DSTATE_o[15];
  real32_T Delay3_DSTATE[75];
  real32_T DiscreteTimeIntegrator1_DSTAT_o[3];
  real32_T DiscreteTimeIntegrator_DSTATE_k[3];
  real32_T DiscreteTimeIntegrator_DSTATE_n[3];
  real32_T DiscreteTimeIntegrator_DSTATE_c[3];
  real32_T DiscreteTimeIntegrator_DSTATE_l[3];
  real32_T DiscreteTimeIntegrator1_DSTAT_j;
  real32_T DiscreteTimeIntegrator_DSTAT_if;
  real32_T DiscreteTimeIntegrator_DSTAT_cq;
  real32_T Delay_DSTATE_i[3];
  real32_T DiscreteTimeIntegrator_DSTATE_p;
  real32_T DiscreteTimeIntegrator_DSTAT_o1;
  real32_T DiscreteTimeIntegrator_DSTAT_og;
  real32_T DiscreteTimeIntegrator_DSTAT_ka;
  real32_T DiscreteTimeIntegrator_DSTAT_it[3];
  real32_T Delay_DSTATE_f[100];
  real32_T DelayInput1_DSTATE;
  real32_T DiscreteTimeIntegrator1_DSTAT_p[2];
  real32_T DiscreteTimeIntegrator1_DSTAT_f[2];
  real32_T DiscreteFIRFilter_states_e[29];
  real32_T DiscreteTimeIntegrator_DSTAT_g4;
  real32_T DiscreteTimeIntegrator_DSTATE_j;
  real32_T DiscreteTimeIntegrator_DSTAT_jn;
  real32_T DiscreteTimeIntegrator_DSTA_ifx;
  real32_T DelayInput1_DSTATE_f;
  real32_T DiscreteTimeIntegrator1_DSTAT_b;
  real32_T Delay3_DSTATE_p;
  real32_T Delay2_DSTATE_l;
  real32_T Delay_DSTATE_b;
  real32_T Delay1_DSTATE_i;
  real32_T DiscreteTimeIntegrator_DSTAT_m0;
  real32_T DiscreteTimeIntegrator1_DSTAT_d;
  real32_T DiscreteTimeIntegrator_DSTAT_on;
  real32_T DiscreteTimeIntegrator_DSTAT_c0;
  real32_T DiscreteTimeIntegrator_DSTAT_na;
  real32_T DiscreteTimeIntegrator1_DSTA_fu;
  real32_T DiscreteTimeIntegrator_DSTAT_jy;
  real32_T DiscreteTimeIntegrator_DSTAT_g0;
  real32_T DiscreteTimeIntegrator1_DSTA_ft;
  real32_T DiscreteTimeIntegrator_DSTATE_e;
  real32_T DiscreteTimeIntegrator_DSTAT_ep;
  real32_T DiscreteTimeIntegrator1_DSTA_pn;
  real32_T DiscreteTimeIntegrator1_DSTAT_i[3];
  real32_T DiscreteTimeIntegrator1_DSTAT_l;
  real32_T DiscreteTimeIntegrator1_DSTA_cp;
  real32_T DiscreteTimeIntegrator_DSTATE_d[2];
  real32_T DiscreteTimeIntegrator1_DSTA_ii;
  real32_T DiscreteTimeIntegrator_DSTAT_lk[3];
  real32_T DiscreteTimeIntegrator_DSTAT_b3[3];
  real32_T DiscreteTimeIntegrator1_DSTA_pc[3];
  real32_T DiscreteTimeIntegrator1_DSTAT_g[3];
  real32_T DiscreteTimeIntegrator_DSTAT_a1[2];
  real32_T DiscreteTimeIntegrator_DSTAT_l3[2];
  real32_T DiscreteTimeIntegrator_DSTAT_aj;
  real32_T DiscreteTimeIntegrator_DSTATE_h;
  real32_T DiscreteTimeIntegrator_DSTA_lk2;
  real32_T DiscreteTimeIntegrator_DSTAT_m4;
  real32_T DiscreteTimeIntegrator_DSTAT_gr;
  real32_T DiscreteTimeIntegrator_DSTAT_bu;
  real32_T DiscreteTimeIntegrator_DSTAT_cf;
  real32_T DiscreteTimeIntegrator_DSTAT_ez;
  real32_T DiscreteTimeIntegrator_DSTAT_di;
  real32_T DiscreteTimeIntegrator_DSTAT_cz;
  real32_T UD_DSTATE;
  real32_T DiscreteTimeIntegrator_DSTA_og2[3];
  real32_T DiscreteTimeIntegrator_DSTAT_ol;
  real32_T Delay_DSTATE_ih;
  real32_T Delay11_DSTATE;
  real32_T Delay5_DSTATE;
  real32_T Delay4_DSTATE;
  real32_T Delay6_DSTATE;
  real32_T DiscreteTimeIntegrator_DSTATE_f;
  real32_T DiscreteTimeIntegrator1_DSTA_la;
  real32_T DiscreteTimeIntegrator_DSTAT_jd;
  real32_T Delay_DSTATE_l[4];
  real32_T DiscreteTimeIntegrator_DSTAT_dm[4];
  real32_T DiscreteTimeIntegrator_DSTAT_hz[3];
  int32_T DiscreteFIRFilter1_circBuf;
  int32_T DiscreteFIRFilter_circBuf;
  int32_T DiscreteFIRFilter_circBuf_d;
  boolean_T Delay4_DSTATE_p[2];
  boolean_T Delay5_DSTATE_b;
  boolean_T Delay6_DSTATE_m[2];
  boolean_T Delay_DSTATE_g;
  boolean_T Delay_DSTATE_m;
  boolean_T DelayInput1_DSTATE_p;
  boolean_T Delay_DSTATE_p;
  boolean_T Delay_DSTATE_k;
  boolean_T DelayInput1_DSTATE_i;
  boolean_T DelayInput1_DSTATE_g;
  boolean_T DelayInput1_DSTATE_i5;
  boolean_T DelayInput1_DSTATE_b;
  boolean_T DelayInput1_DSTATE_h;
  boolean_T Delay_DSTATE_c;
  boolean_T DelayInput1_DSTATE_ft;
  boolean_T Delay_DSTATE_e;
  boolean_T DelayInput1_DSTATE_n;
  boolean_T DelayInput1_DSTATE_a;
  boolean_T DelayInput1_DSTATE_d;
  boolean_T DelayInput1_DSTATE_bg;
  boolean_T Delay_DSTATE_n1;
  boolean_T Delay_DSTATE_by;
  boolean_T Delay_DSTATE_ez[102];
  boolean_T DelayInput1_DSTATE_o;
  boolean_T Delay4_DSTATE_j;
  boolean_T DelayInput1_DSTATE_fa;
  boolean_T DelayInput1_DSTATE_oe;
  boolean_T Delay_DSTATE_na;
  boolean_T DelayInput1_DSTATE_pc;
  boolean_T Delay_DSTATE_kq;
  boolean_T DelayInput1_DSTATE_nh;
  boolean_T Delay_DSTATE_iz;
  boolean_T DelayInput1_DSTATE_dq;
  boolean_T DelayInput1_DSTATE_hh;
  boolean_T DelayInput1_DSTATE_bh;
  boolean_T DelayInput1_DSTATE_ip;
  boolean_T Delay_DSTATE_d;
  boolean_T Delay_DSTATE_e1;
  boolean_T DelayInput1_DSTATE_m;
  boolean_T Delay_DSTATE_ig;
  boolean_T DelayInput1_DSTATE_aq;
  boolean_T Delay_DSTATE_o;
  boolean_T DelayInput1_DSTATE_c;
  boolean_T DelayInput1_DSTATE_ne;
  boolean_T DelayInput1_DSTATE_j;
  boolean_T Delay_DSTATE_gd;
  boolean_T Delay_DSTATE_ef;
  boolean_T DelayInput1_DSTATE_fq;
  boolean_T Delay7_DSTATE;
  boolean_T DelayInput1_DSTATE_ms;
  boolean_T DelayInput1_DSTATE_bu;
  boolean_T DelayInput1_DSTATE_dc;
  boolean_T DelayInput1_DSTATE_n5;
  boolean_T Delay_DSTATE_j;
  boolean_T DelayInput1_DSTATE_px;
  boolean_T DelayInput1_DSTATE_by;
  int8_T DiscreteTimeIntegrator_PrevRese;
  int8_T DiscreteTimeIntegrator1_PrevRes;
  int8_T DiscreteTimeIntegrator_PrevRe_a;
  int8_T DiscreteTimeIntegrator_PrevRe_f;
  int8_T DiscreteTimeIntegrator_PrevRe_d;
  int8_T DiscreteTimeIntegrator_PrevRe_k;
  int8_T DiscreteTimeIntegrator_PrevRe_j;
  int8_T DiscreteTimeIntegrator1_PrevR_l;
  int8_T DiscreteTimeIntegrator_PrevRe_n;
  int8_T DiscreteTimeIntegrator1_PrevR_g;
  int8_T DiscreteTimeIntegrator_PrevR_fh;
  int8_T DiscreteTimeIntegrator_PrevR_aq;
  int8_T DiscreteTimeIntegrator_PrevRe_h;
  int8_T DiscreteTimeIntegrator_PrevR_nh;
  int8_T DiscreteTimeIntegrator_PrevRe_e;
  int8_T DiscreteTimeIntegrator_PrevR_dh;
  int8_T DiscreteTimeIntegrator_PrevR_du;
  int8_T DiscreteTimeIntegrator_PrevRe_c;
  int8_T DiscreteTimeIntegrator_PrevR_je;
  int8_T DiscreteTimeIntegrator_PrevRe_m;
  int8_T DiscreteTimeIntegrator_PrevRe_o;
  int8_T DiscreteTimeIntegrator_PrevRe_l;
  int8_T DiscreteTimeIntegrator_PrevR_m4;
  uint8_T icLoad;
  uint8_T DiscreteTimeIntegrator_IC_LOADI;
  uint8_T DiscreteTimeIntegrator_IC_LOA_b;
  uint8_T DiscreteTimeIntegrator1_IC_LOAD;
  uint8_T icLoad_h;
  uint8_T DiscreteTimeIntegrator_IC_LOA_d;
  uint8_T DiscreteTimeIntegrator_IC_LOA_h;
  uint8_T icLoad_b;
  uint8_T icLoad_m;
  uint8_T DiscreteTimeIntegrator_IC_LOA_c;
  uint8_T DiscreteTimeIntegrator_IC_LO_by;
  uint8_T DiscreteTimeIntegrator1_IC_LO_n;
  uint8_T DiscreteTimeIntegrator_IC_LOA_g;
  uint8_T DiscreteTimeIntegrator_IC_LOA_k;
  uint8_T DiscreteTimeIntegrator_IC_LOA_i;
  uint8_T DiscreteTimeIntegrator_IC_LO_gv;
  uint8_T DiscreteTimeIntegrator1_IC_LO_c;
  uint8_T DiscreteTimeIntegrator_IC_LO_bw;
  uint8_T DiscreteTimeIntegrator_IC_LOA_o;
  uint8_T DiscreteTimeIntegrator1_IC_LO_b;
  uint8_T icLoad_d;
  uint8_T icLoad_f;
  uint8_T icLoad_hh;
  uint8_T DiscreteTimeIntegrator_IC_LOA_j;
  uint8_T DiscreteTimeIntegrator1_IC_LO_h;
  uint8_T DiscreteTimeIntegrator_IC_LO_jh;
  uint8_T DiscreteTimeIntegrator1_IC_L_nd;
  uint8_T DiscreteTimeIntegrator_IC_LOA_m;
  uint8_T DiscreteTimeIntegrator_IC_LO_i4;
  uint8_T DiscreteTimeIntegrator1_IC_LO_m;
  uint8_T DiscreteTimeIntegrator_IC_LO_jz;
  uint8_T DiscreteTimeIntegrator_IC_LO_b4;
  uint8_T DiscreteTimeIntegrator1_IC_LO_g;
  uint8_T DiscreteTimeIntegrator1_IC_LO_k;
  uint8_T DiscreteTimeIntegrator_IC_LOA_n;
  uint8_T DiscreteTimeIntegrator1_IC_L_bf;
  uint8_T DiscreteTimeIntegrator_IC_LO_gi;
  uint8_T DiscreteTimeIntegrator_IC_LO_hx;
  uint8_T icLoad_o;
  uint8_T icLoad_i;
  uint8_T icLoad_n;
  uint8_T DiscreteTimeIntegrator_IC_LO_md;
  uint8_T DiscreteTimeIntegrator_IC_LOA_e;
  boolean_T Relay1_Mode;
  boolean_T Memory2_PreviousInput;
  boolean_T Relay_Mode;
  DW_MovingAverage2_Rotation_AH_T MovingAverage3;
  DW_MovingAverage2_Rotation_AH_T MovingAverage1;
  DW_MovingAverage2_Rotation_AH_T MovingAverage2;
} DW_Rotation_AHRS_GPS_f_T;

#endif

#ifndef Rotation_AHRS_GPS_MDLREF_HIDE_CHILD_

typedef struct {
  ZCSigState Delay16_Reset_ZCE;
  ZCSigState Delay12_Reset_ZCE;
  ZCSigState Delay3_Reset_ZCE;
  ZCSigState Delay2_Reset_ZCE;
  ZCSigState Delay1_Reset_ZCE;
  ZCSigState Delay_Reset_ZCE;
  ZCSigState Delay4_Reset_ZCE;
  ZCSigState Delay6_Reset_ZCE;
} ZCE_Rotation_AHRS_GPS_T;

#endif

#ifndef Rotation_AHRS_GPS_MDLREF_HIDE_CHILD_

struct P_Rotation_AHRS_GPS_T_ {
  real32_T Difference_ICPrevInput;
  real32_T Normalization_Min_Mag;
  real32_T Normalization_Min_Mag_d;
  real32_T Normalization1_Min_Mag;
  real32_T Normalization_Min_Mag_j;
  real32_T Validaperiod_T_p;
  real32_T Validaperiod_T_p_n;
  real32_T Validaperiod_T_p_j;
  real32_T Validaperiod_T_p_c;
  real32_T Validaperiod_T_p_a;
  real32_T Validaperiod1_T_p;
  real32_T Ascendanddescendtracking1_Tc_as;
  real32_T Ascendanddescendtracking1_Tc__a;
  real32_T Ascendanddescendtracking2_Tc_as;
  real32_T Ascendanddescendtracking_Tc_asc;
  real32_T Ascendanddescendtracking1_Tc__m;
  real32_T Ascendanddescendtracking1_Tc__l;
  real32_T Ascendanddescendtracking1_Tc__b;
  real32_T Ascendanddescendtracking_Tc_a_m;
  real32_T Ascendanddescendtracking1_Tc_de;
  real32_T Ascendanddescendtracking1_Tc__g;
  real32_T Ascendanddescendtracking2_Tc_de;
  real32_T Ascendanddescendtracking_Tc_des;
  real32_T Ascendanddescendtracking1_Tc__n;
  real32_T Ascendanddescendtracking1_Tc__e;
  real32_T Ascendanddescendtracking1_Tc__j;
  real32_T Ascendanddescendtracking_Tc_d_i;
  real32_T CompareToConstant_const;
  real32_T CompareToConstant1_const;
  real32_T CompareToConstant_const_h;
  real32_T CompareToConstant6_const;
  real32_T CompareToConstant4_const;
  real32_T CompareToConstant_const_i;
  real32_T CompareToConstant2_const;
  real32_T CompareToConstant1_const_l;
  real32_T CompareToConstant_const_j;
  real32_T CompareToConstant3_const;
  real32_T CompareTo1sec_const;
  real32_T CompareToConstant1_const_k;
  real32_T CompareTo11ms_const;
  real32_T CompareToConstant_const_l;
  real32_T CompareToConstant1_const_m;
  real32_T CompareToConstant_const_e;
  real32_T CompareToConstant7_const;
  real32_T CompareToConstant8_const;
  real32_T CompareToConstant_const_n;
  real32_T CompareToConstant_const_p;
  real32_T CompareToConstant_const_k;
  real32_T CompareToConstant9_const;
  real32_T CompareToConstant1_const_o;
  real32_T CompareToConstant8_const_l;
  real32_T CompareToConstant_const_j3;
  real32_T CompareToConstant_const_g;
  real32_T CompareToConstant5_const;
  real32_T CompareToConstant1_const_i;
  real32_T CompareToConstant2_const_p;
  real32_T CompareToConstant6_const_c;
  real32_T CompareToConstant3_const_m;
  real32_T CompareToConstant4_const_c;
  real32_T CompareToConstant5_const_f;
  real32_T CompareToConstant2_const_n;
  real32_T CompareToConstant3_const_g;
  real32_T CompareToConstant7_const_m;
  real32_T CompareToConstant8_const_p;
  real32_T CompareToConstant7_const_o;
  real32_T CompareToConstant8_const_p4;
  real32_T CompareToConstant_const_f;
  real32_T CompareToConstant17_const;
  real32_T CompareToConstant2_const_e;
  real32_T CompareToConstant1_const_b;
  real32_T CompareToConstant15_const;
  real32_T CompareToConstant16_const;
  real32_T CompareToConstant20_const;
  real32_T CompareToConstant9_const_c;
  real32_T CompareTo1sec_const_o;
  real32_T CompareTo1sec_const_p;
  real32_T CompareTo1sec_const_d;
  real32_T CompareTo1sec_const_j;
  real32_T CompareToConstant_const_he;
  real32_T CompareToConstant1_const_d;
  real32_T CompareToConstant2_const_eg;
  real32_T CompareToConstant1_const_p;
  real32_T CompareToConstant1_const_h;
  real32_T CompareToConstant3_const_m4;
  real32_T CompareToConstant_const_e5;
  real32_T CompareToConstant2_const_h;
  real32_T CompareToConstant_const_hz;
  real32_T CompareToConstant1_const_hs;
  real32_T CompareToConstant2_const_b;
  real32_T CompareToConstant3_const_n;
  real32_T CompareToConstant5_const_i;
  real32_T CompareToConstant7_const_b;
  real32_T CompareToConstant8_const_e;
  real32_T CompareTo1sec_const_n;
  real32_T CompareToConstant_const_g3;
  real32_T IntervalTest_lowlimit;
  real32_T IntervalTest_uplimit;
  real32_T DetectIncrease_vinit;
  real32_T DetectIncrease3_vinit;
  real32_T AttitudeFusion_wn_acc_vert;
  real32_T AttitudeFusion_wn_acc_yaw;
  real32_T AttitudeFusion_wn_mag;
  real32_T Linearinterp1_x_l;
  real32_T Linearinterp_x_l;
  real32_T Linearinterp1_x_l_k;
  real32_T Linearinterp1_x_l_o;
  real32_T Linearinterp2_x_l;
  real32_T Linearinterp2_x_l_c;
  real32_T Linearinterp_x_l_o;
  real32_T Linearinterp2_x_l_a;
  real32_T Linearinterp1_x_r;
  real32_T Linearinterp_x_r;
  real32_T Linearinterp1_x_r_a;
  real32_T Linearinterp1_x_r_b;
  real32_T Linearinterp2_x_r;
  real32_T Linearinterp2_x_r_e;
  real32_T Linearinterp_x_r_e;
  real32_T Linearinterp2_x_r_a;
  real32_T Linearinterp1_y_l;
  real32_T Linearinterp_y_l;
  real32_T Linearinterp1_y_l_c;
  real32_T Linearinterp2_y_l;
  real32_T Linearinterp1_y_l_cr;
  real32_T Linearinterp2_y_l_b;
  real32_T Linearinterp_y_l_a;
  real32_T Linearinterp2_y_l_m;
  real32_T Linearinterp1_y_r;
  real32_T Linearinterp_y_r;
  real32_T Linearinterp1_y_r_l;
  real32_T Linearinterp2_y_r;
  real32_T Linearinterp1_y_r_d;
  real32_T Linearinterp2_y_r_p;
  real32_T Linearinterp_y_r_a;
  real32_T Linearinterp2_y_r_g;
  boolean_T DetectIncrease5_vinit;
  boolean_T DetectIncrease1_vinit;
  boolean_T DetectIncrease2_vinit;
  boolean_T DetectIncrease3_vinit_n;
  boolean_T DetectRisePositive2_vinit;
  boolean_T DetectRisePositive_vinit;
  boolean_T DetectIncrease_vinit_n;
  boolean_T DetectIncrease1_vinit_c;
  boolean_T DetectIncrease8_vinit;
  boolean_T DetectIncrease1_vinit_h;
  boolean_T DetectIncrease6_vinit;
  boolean_T DetectIncrease_vinit_j;
  boolean_T DetectIncrease1_vinit_o;
  boolean_T DetectIncrease1_vinit_h0;
  boolean_T DetectIncrease2_vinit_p;
  boolean_T DetectIncrease_vinit_g;
  boolean_T DetectIncrease_vinit_c;
  boolean_T DetectIncrease3_vinit_m;
  boolean_T DetectIncrease1_vinit_j;
  boolean_T DetectIncrease6_vinit_l;
  boolean_T DetectIncrease_vinit_i;
  boolean_T DetectIncrease1_vinit_e;
  boolean_T DetectIncrease11_vinit;
  boolean_T DetectIncrease12_vinit;
  boolean_T DetectIncrease2_vinit_c;
  boolean_T DetectIncrease1_vinit_g;
  boolean_T DetectIncrease5_vinit_e;
  boolean_T DetectIncrease7_vinit;
  boolean_T DetectIncrease3_vinit_a;
  boolean_T DetectIncrease_vinit_p;
  boolean_T DetectIncrease_vinit_l;
  boolean_T DetectIncrease3_vinit_j;
  uint8_T CompareToConstant_const_o;
  real32_T Constant_Value[3];
  real32_T Constant_Value_o[3];
  real32_T Constant1_Value;
  real32_T Constant_Value_e;
  real32_T Saturation_UpperSat;
  real32_T Saturation_LowerSat;
  real32_T Constant1_Value_a;
  real32_T Saturation_UpperSat_d;
  real32_T Saturation_LowerSat_l;
  real32_T Constant3_Value;
  real32_T Constant2_Value;
  real32_T Saturation_UpperSat_l;
  real32_T Saturation_LowerSat_k;
  real32_T Constant1_Value_j;
  real32_T Constant_Value_oo;
  real32_T DeadZone1_Start;
  real32_T DeadZone1_End;
  real32_T DeadZone_Start;
  real32_T DeadZone_End;
  real32_T Gain5_Gain;
  real32_T Constant_Value_a;
  real32_T Constant1_Value_c;
  real32_T One6_Value;
  real32_T One1_Value;
  real32_T Saturation_UpperSat_lu;
  real32_T Saturation_LowerSat_i;
  real32_T Constant3_Value_l;
  real32_T Constant1_Value_ax;
  real32_T Saturation_UpperSat_p;
  real32_T Saturation_LowerSat_n;
  real32_T Constant4_Value;
  real32_T Constant_Value_h;
  real32_T Gain_Gain;
  real32_T Gain_Gain_m;
  real32_T Constant_Value_d;
  real32_T Constant_Value_ec;
  real32_T Bias_Bias;
  real32_T Out1_Y0;
  real32_T Constant_Value_m;
  real32_T Constant2_Value_p;
  real32_T Constant3_Value_a;
  real32_T Gain_Gain_n;
  real32_T corr_gain_Gain;
  real32_T Constant_Value_mj;
  real32_T Constant_Value_c[7];
  real32_T Constant_Value_b;
  real32_T Gain1_Gain;
  real32_T Gain_Gain_b;
  real32_T Saturation_UpperSat_e;
  real32_T Saturation_LowerSat_n2;
  real32_T Zero_Yaw_Value;
  real32_T u2_Gain;
  real32_T Gain_Gain_g;
  real32_T Gain_Gain_nz;
  real32_T Gain_Gain_f;
  real32_T Gain_Gain_c;
  real32_T Gain_Gain_fu;
  real32_T Gain_Gain_bo;
  real32_T Gain_Gain_h;
  real32_T Gain_Gain_ct;
  real32_T Constant_Value_f;
  real32_T Gain_Gain_j;
  real32_T Gain_Gain_d;
  real32_T Gain_Gain_dp;
  real32_T Gain_Gain_fw;
  real32_T Gain_Gain_k;
  real32_T Gain_Gain_c3;
  real32_T Gain_Gain_ja;
  real32_T Gain_Gain_nk;
  real32_T x0_Y0;
  real32_T Out1_Y0_d;
  real32_T det_yaw12_Y0;
  real32_T Constant_Value_p;
  real32_T Gain_Gain_p;
  real32_T Gain_Gain_ck;
  real32_T Gain_Gain_jan;
  real32_T Gain_Gain_pk;
  real32_T Gain_Gain_i;
  real32_T Gain_Gain_g2;
  real32_T Gain_Gain_pp;
  real32_T Gain_Gain_kc;
  real32_T Out1_Y0_p;
  real32_T DiscreteTimeIntegrator_gainval;
  real32_T Gain_Gain_ca;
  real32_T Delay17_InitialCondition;
  real32_T DiscreteTimeIntegrator_gainva_p;
  real32_T DiscreteTimeIntegrator_IC;
  real32_T DiscreteTimeIntegrator_UpperSat;
  real32_T DiscreteTimeIntegrator_LowerSat;
  real32_T DiscreteTimeIntegrator_gainv_p2;
  real32_T DiscreteTimeIntegrator_gainva_k;
  real32_T Saturation1_UpperSat;
  real32_T Saturation1_LowerSat;
  real32_T DiscreteTimeIntegrator1_gainval;
  real32_T Relay1_OnVal;
  real32_T Relay1_OffVal;
  real32_T Relay1_YOn;
  real32_T Relay1_YOff;
  real32_T DiscreteTimeIntegrator_gainv_kh;
  real32_T DiscreteTimeIntegrator_IC_k;
  real32_T DiscreteTimeIntegrator_UpperS_g;
  real32_T DiscreteTimeIntegrator_LowerS_f;
  real32_T Delay13_InitialCondition;
  real32_T Constant_Value_n;
  real32_T DiscreteTimeIntegrator1_gainv_b;
  real32_T DiscreteTimeIntegrator1_IC;
  real32_T DiscreteTimeIntegrator_gainva_f;
  real32_T DiscreteTimeIntegrator_IC_j;
  real32_T Delay_InitialCondition[7];
  real32_T DiscreteFIRFilter1_InitialState;
  real32_T DiscreteFIRFilter1_Coefficients[5];
  real32_T DiscreteTimeIntegrator_gainva_m;
  real32_T Saturation_UpperSat_h;
  real32_T Saturation_LowerSat_e;
  real32_T Gain_Gain_f5[3];
  real32_T DiscreteTimeIntegrator_gainva_l;
  real32_T Bias_Bias_c;
  real32_T Bias1_Bias;
  real32_T DiscreteFIRFilter_InitialStates;
  real32_T DiscreteFIRFilter_Coefficients[5];
  real32_T Constant1_Value_p[3];
  real32_T DiscreteTimeIntegrator_gainva_j;
  real32_T DiscreteTimeIntegrator_IC_d;
  real32_T DiscreteTimeIntegrator_gainv_fl;
  real32_T DiscreteTimeIntegrator_IC_l;
  real32_T Delay2_InitialCondition;
  real32_T DiscreteTimeIntegrator_gainv_me;
  real32_T DiscreteTimeIntegrator_IC_lf;
  real32_T Constant_Value_l[2];
  real32_T Constant6_Value;
  real32_T Constant7_Value;
  real32_T Gain_Gain_fp;
  real32_T zero_Value;
  real32_T Delay1_InitialCondition;
  real32_T Gain1_Gain_j;
  real32_T Gain_Gain_o;
  real32_T Gain_Gain_cw;
  real32_T Gain_Gain_a;
  real32_T Gain_Gain_gv;
  real32_T Gain_Gain_p5;
  real32_T Gain_Gain_nq;
  real32_T Delay3_InitialCondition;
  real32_T DiscreteTimeIntegrator1_gainv_j;
  real32_T DiscreteTimeIntegrator1_IC_f[3];
  real32_T DiscreteTimeIntegrator_gainva_b;
  real32_T DiscreteTimeIntegrator_IC_h;
  real32_T DiscreteTimeIntegrator_gainva_o;
  real32_T DiscreteTimeIntegrator_IC_hz;
  real32_T Switch1_Threshold;
  real32_T g0_Value[3];
  real32_T Constant1_Value_jo;
  real32_T DiscreteTimeIntegrator_gainva_h;
  real32_T Gain1_Gain_o[3];
  real32_T One2_Value;
  real32_T DiscreteTimeIntegrator_gainv_li;
  real32_T DiscreteTimeIntegrator1_gain_jp;
  real32_T DiscreteTimeIntegrator_gainv_pf;
  real32_T DiscreteTimeIntegrator_IC_e;
  real32_T DiscreteTimeIntegrator_UpperS_n;
  real32_T DiscreteTimeIntegrator_LowerS_k;
  real32_T DiscreteTimeIntegrator_gainva_i;
  real32_T DiscreteTimeIntegrator_IC_lw;
  real32_T One1_Value_i;
  real32_T One_Value;
  real32_T Delay_InitialCondition_h;
  real32_T DiscreteTimeIntegrator_gainv_of;
  real32_T DiscreteTimeIntegrator_gainv_hk;
  real32_T DiscreteTimeIntegrator_gainva_g;
  real32_T Gain3_Gain;
  real32_T Saturation_UpperSat_m;
  real32_T Saturation_LowerSat_lu;
  real32_T DiscreteTimeIntegrator_gainv_mh;
  real32_T DiscreteTimeIntegrator_gainv_bl;
  real32_T DiscreteTimeIntegrator_IC_n;
  real32_T DiscreteTimeIntegrator_UpperS_m;
  real32_T DiscreteTimeIntegrator_LowerS_m;
  real32_T Gain10_Gain[3];
  real32_T Gain_Gain_fk;
  real32_T Delay_InitialCondition_m;
  real32_T Constant_Value_ak;
  real32_T Gain_Gain_gw;
  real32_T Gain1_Gain_g[3];
  real32_T DiscreteTimeIntegrator1_gainv_g;
  real32_T DiscreteTimeIntegrator1_IC_m;
  real32_T DiscreteTimeIntegrator1_gainv_e;
  real32_T Constant_Value_by;
  real32_T Gain_Gain_e;
  real32_T Constant_Value_j;
  real32_T Gain2_Gain;
  real32_T DeadZone_Start_c;
  real32_T DeadZone_End_d;
  real32_T Constant_Value_o5;
  real32_T Gain1_Gain_f;
  real32_T Saturation_UpperSat_l5;
  real32_T Saturation_LowerSat_li;
  real32_T Saturation1_UpperSat_b;
  real32_T Saturation1_LowerSat_l;
  real32_T Constant1_Value_o;
  real32_T Constant_Value_i;
  real32_T Gain_Gain_g3;
  real32_T Saturation_UpperSat_l3;
  real32_T Saturation_LowerSat_g;
  real32_T DiscreteFIRFilter_InitialStat_e;
  real32_T DiscreteFIRFilter_Coefficient_n[30];
  real32_T Saturation2_UpperSat;
  real32_T Saturation2_LowerSat;
  real32_T DiscreteTimeIntegrator_gainva_a;
  real32_T Constant1_Value_l;
  real32_T DiscreteTimeIntegrator_gainv_o5;
  real32_T Gain_Gain_ia;
  real32_T Saturation_UpperSat_i;
  real32_T Saturation_LowerSat_d;
  real32_T Saturation_UpperSat_b;
  real32_T Saturation_LowerSat_n3;
  real32_T Gain_Gain_mt;
  real32_T DiscreteTimeIntegrator_gainva_n;
  real32_T DiscreteTimeIntegrator_IC_c;
  real32_T DiscreteTimeIntegrator_gainv_oe;
  real32_T DiscreteTimeIntegrator_IC_ly;
  real32_T DiscreteTimeIntegrator_UpperS_a;
  real32_T DiscreteTimeIntegrator_LowerS_b;
  real32_T Relay_OnVal;
  real32_T Relay_OffVal;
  real32_T Relay_YOn;
  real32_T Relay_YOff;
  real32_T Gain_Gain_kr;
  real32_T DiscreteTimeIntegrator1_gainv_f;
  real32_T Delay_InitialCondition_f;
  real32_T DiscreteTimeIntegrator_gainv_pz;
  real32_T DiscreteTimeIntegrator1_gainv_p;
  real32_T DiscreteTimeIntegrator_gainv_oq;
  real32_T DiscreteTimeIntegrator_IC_c3;
  real32_T DiscreteTimeIntegrator_UpperS_f;
  real32_T DiscreteTimeIntegrator_LowerS_h;
  real32_T DiscreteTimeIntegrator_gainva_d;
  real32_T DiscreteTimeIntegrator_IC_dg;
  real32_T Switch_Threshold;
  real32_T Gain3_Gain_o;
  real32_T One5_Value[3];
  real32_T Constant1_Value_b;
  real32_T DeadZone_Start_j;
  real32_T DeadZone_End_h;
  real32_T Saturation1_UpperSat_p;
  real32_T Saturation1_LowerSat_m;
  real32_T DiscreteTimeIntegrator_gainv_ft;
  real32_T DiscreteTimeIntegrator1_gainv_l;
  real32_T DiscreteTimeIntegrator_gainva_c;
  real32_T Gain_Gain_fg;
  real32_T DiscreteTimeIntegrator_gainv_ps;
  real32_T DiscreteTimeIntegrator1_gain_ew;
  real32_T DiscreteTimeIntegrator_gainva_e;
  real32_T Gain_Gain_l;
  real32_T DiscreteTimeIntegrator_gainv_he;
  real32_T DiscreteTimeIntegrator1_gainv_h;
  real32_T DiscreteTimeIntegrator1_gain_pw;
  real32_T DiscreteTimeIntegrator1_IC_m5;
  real32_T DiscreteTimeIntegrator1_gain_lj;
  real32_T DiscreteTimeIntegrator1_IC_fk;
  real32_T DiscreteTimeIntegrator1_gain_pm;
  real32_T Saturation_UpperSat_j;
  real32_T Saturation_LowerSat_o;
  real32_T DiscreteTimeIntegrator_gainv_d3;
  real32_T Gain9_Gain;
  real32_T Saturation_UpperSat_hv;
  real32_T Saturation_LowerSat_ic;
  real32_T DiscreteTimeIntegrator1_gainv_n;
  real32_T DiscreteTimeIntegrator_gainv_kb;
  real32_T DiscreteTimeIntegrator_IC_ny;
  real32_T DiscreteTimeIntegrator_UpperS_e;
  real32_T DiscreteTimeIntegrator_Lower_hp;
  real32_T Saturation_UpperSat_bj;
  real32_T Saturation_LowerSat_e1;
  real32_T Constant4_Value_m;
  real32_T one_Value;
  real32_T const_Value;
  real32_T WeightedSampleTime_WtEt;
  real32_T Gain_Gain_bn;
  real32_T Gain1_Gain_gn;
  real32_T Gain2_Gain_e;
  real32_T Gain3_Gain_k;
  real32_T Gain4_Gain;
  real32_T Gain5_Gain_c;
  real32_T Gain3_Gain_i;
  real32_T Gain5_Gain_b;
  real32_T Saturation1_UpperSat_o;
  real32_T Saturation1_LowerSat_h;
  real32_T Constant1_Value_bu;
  real32_T Gain2_Gain_p;
  real32_T Constant2_Value_n;
  real32_T Constant4_Value_d;
  real32_T Constant3_Value_i;
  real32_T Constant5_Value;
  real32_T Gain1_Gain_n;
  real32_T Gain1_Gain_a;
  real32_T DiscreteTimeIntegrator_gainv_id;
  real32_T DiscreteTimeIntegrator_IC_dz;
  real32_T Gain1_Gain_fg;
  real32_T Gain_Gain_ca1;
  real32_T DiscreteTimeIntegrator1_gain_el;
  real32_T DiscreteTimeIntegrator1_IC_o;
  real32_T Gain2_Gain_m;
  real32_T Gain3_Gain_a;
  real32_T DiscreteTimeIntegrator1_gain_p5;
  real32_T DiscreteTimeIntegrator1_IC_e;
  real32_T Gain2_Gain_o;
  real32_T Gain3_Gain_oz;
  real32_T Gain6_Gain;
  real32_T Gain11_Gain;
  real32_T Gain_Gain_ay[3];
  real32_T Switch_Threshold_l;
  real32_T Constant_Value_i4;
  real32_T Gain_Gain_kl;
  real32_T Gain_Gain_pg;
  real32_T Gain_Gain_ka;
  real32_T Gain_Gain_ml;
  real32_T Gain_Gain_fx;
  real32_T Gain_Gain_jr;
  real32_T DiscreteTimeIntegrator_gainv_fg;
  real32_T DiscreteTimeIntegrator_IC_cq;
  real32_T Gain1_Gain_h;
  real32_T Gain_Gain_oe;
  real32_T DiscreteTimeIntegrator_gainv_ne;
  real32_T DiscreteTimeIntegrator_IC_i;
  real32_T Gain1_Gain_nz;
  real32_T Gain_Gain_eb;
  real32_T Gain2_Gain_c;
  real32_T Saturation5_UpperSat;
  real32_T Saturation5_LowerSat;
  real32_T DiscreteTimeIntegrator_gainv_cp;
  real32_T DiscreteTimeIntegrator_IC_hx;
  real32_T DiscreteTimeIntegrator_gainv_m3;
  real32_T DiscreteTimeIntegrator_IC_e4;
  real32_T DiscreteTimeIntegrator_gainv_hn;
  real32_T DiscreteTimeIntegrator_IC_lx;
  real32_T DiscreteTimeIntegrator_Upper_a0;
  real32_T DiscreteTimeIntegrator_LowerS_c;
  real32_T DiscreteTimeIntegrator_gainv_il;
  real32_T DiscreteTimeIntegrator_IC_o;
  real32_T DiscreteTimeIntegrator_UpperS_h;
  real32_T DiscreteTimeIntegrator_Lower_mq;
  real32_T DiscreteTimeIntegrator_gainv_jv;
  real32_T DiscreteTimeIntegrator_IC_ob;
  real32_T DiscreteTimeIntegrator_gainv_fi;
  real32_T DiscreteTimeIntegrator_IC_hn;
  real32_T DiscreteTimeIntegrator_gainv_kj;
  real32_T DiscreteTimeIntegrator_IC_j0;
  real32_T Constant_Value_jg;
  real32_T Constant_Value_jf;
  real32_T Constant_Value_b3;
  real32_T Gain_Gain_oc;
  real32_T Gain_Gain_n5;
  real32_T DiscreteTimeIntegrator_gainv_gl;
  real32_T DiscreteTimeIntegrator_gainv_a4;
  real32_T Switch_Threshold_a;
  real32_T Switch_Threshold_d;
  real32_T Gain1_Gain_c;
  real32_T Gain8_Gain;
  real32_T Gain5_Gain_o;
  real32_T Constant2_Value_f;
  real32_T Gain_Gain_f5p;
  real32_T Gain_Gain_br;
  real32_T Gain_Gain_jv;
  real32_T DiscreteTimeIntegrator_gain_hkc;
  real32_T DiscreteTimeIntegrator_IC_b;
  real32_T Gain1_Gain_m;
  real32_T Gain1_Gain_k;
  real32_T Constant_Value_p3;
  real32_T Switch_Threshold_j;
  real32_T Gain2_Gain_mr;
  real32_T Gain_Gain_nw;
  real32_T DiscreteTimeIntegrator_gainv_a0;
  real32_T DiscreteTimeIntegrator_IC_iy;
  real32_T Gain1_Gain_nv;
  real32_T Gain_Gain_jy;
  real32_T Switch_Threshold_m;
  real32_T DiscreteTimeIntegrator_gainv_f3;
  real32_T DiscreteTimeIntegrator_IC_a;
  real32_T Gain1_Gain_ny;
  real32_T Gain_Gain_ks;
  real32_T Switch_Threshold_aq;
  real32_T Gain_Gain_cj;
  real32_T Switch_Threshold_h;
  real32_T Constant_Value_dc;
  real32_T Gain_Gain_hd;
  real32_T Switch_Threshold_f;
  real32_T Gain_Gain_gy;
  real32_T Delay11_InitialCondition;
  real32_T Delay5_InitialCondition;
  real32_T Gain_Gain_n1;
  real32_T Constant_Value_id;
  real32_T Gain_Gain_fxn;
  real32_T Constant_Value_ij;
  real32_T Constant_Value_nk;
  real32_T Switch_Threshold_e;
  real32_T Gain_Gain_bv;
  real32_T Gain_Gain_ff;
  real32_T Constant_Value_cu;
  real32_T DiscreteTimeIntegrator_gainv_lh;
  real32_T DiscreteTimeIntegrator_IC_o0;
  real32_T Gain1_Gain_gu;
  real32_T DiscreteTimeIntegrator1_gainv_a;
  real32_T DiscreteTimeIntegrator1_IC_a;
  real32_T Gain_Gain_il;
  real32_T Gain_Gain_it;
  real32_T Constant_Value_jz[3];
  real32_T Constant4_Value_p[4];
  real32_T Gain3_Gain_l;
  real32_T Gain2_Gain_k;
  real32_T Constant1_Value_g;
  real32_T Gain_Gain_ok;
  real32_T Constant2_Value_l;
  real32_T Constant3_Value_d;
  real32_T Gain1_Gain_e;
  real32_T DiscreteTimeIntegrator_gainv_el;
  real32_T DiscreteTimeIntegrator_IC_lq;
  real32_T Delay_InitialCondition_e;
  real32_T DiscreteTimeIntegrator_gainv_gn;
  real32_T Gain_Gain_c0;
  real32_T Constant_Value_av;
  real32_T Gain_Gain_boy;
  real32_T Constant_Value_el;
  real32_T Saturation_UpperSat_k;
  real32_T Saturation_LowerSat_eo;
  real32_T Constant_Value_mg;
  real32_T Saturation_UpperSat_hi;
  real32_T Saturation_LowerSat_oc;
  real32_T Gain_Gain_mn;
  real32_T Constant_Value_p2;
  uint32_T Delay4_DelayLength;
  uint32_T Delay5_DelayLength;
  uint32_T Delay6_DelayLength;
  uint32_T Delay_DelayLength;
  uint32_T Delay17_DelayLength;
  uint32_T Delay16_DelayLength;
  uint32_T Delay_DelayLength_i;
  uint32_T Delay_DelayLength_a;
  uint32_T Delay13_DelayLength;
  uint32_T Delay12_DelayLength;
  uint32_T Delay_DelayLength_n;
  uint32_T Delay_DelayLength_m;
  uint32_T Delay_DelayLength_o;
  uint32_T Delay_DelayLength_k;
  uint32_T Delay2_DelayLength;
  uint32_T Delay1_DelayLength;
  uint32_T Delay_DelayLength_f;
  uint32_T Delay_DelayLength_e;
  uint32_T Delay1_DelayLength_j;
  uint32_T Delay3_DelayLength;
  uint32_T Delay_DelayLength_ib;
  uint32_T Delay_DelayLength_no;
  uint32_T Delay_DelayLength_j;
  uint32_T Delay_DelayLength_l;
  uint32_T Delay4_DelayLength_i;
  uint32_T Delay_DelayLength_mh;
  uint32_T Delay_DelayLength_e5;
  uint32_T Delay3_DelayLength_e;
  uint32_T Delay2_DelayLength_h;
  uint32_T Delay_DelayLength_c;
  uint32_T Delay1_DelayLength_d;
  uint32_T Delay_DelayLength_od;
  uint32_T Delay_DelayLength_os;
  uint32_T Delay_DelayLength_ee;
  uint32_T Delay_DelayLength_fi;
  uint32_T Delay_DelayLength_p;
  uint32_T Delay_DelayLength_b;
  uint32_T Delay_DelayLength_ph;
  uint32_T Delay_DelayLength_d;
  uint32_T Delay11_DelayLength;
  uint32_T Delay7_DelayLength;
  uint32_T Delay5_DelayLength_m;
  uint32_T Delay4_DelayLength_b;
  uint32_T Delay6_DelayLength_a;
  uint32_T Delay_DelayLength_lw;
  uint32_T Delay_DelayLength_h;
  boolean_T Constant_Value_g;
  boolean_T Delay4_InitialCondition;
  boolean_T Delay5_InitialCondition_p;
  boolean_T Delay6_InitialCondition;
  boolean_T Delay_InitialCondition_g;
  boolean_T Delay_InitialCondition_b;
  boolean_T Delay_InitialCondition_a;
  boolean_T Delay_InitialCondition_ax;
  boolean_T Memory2_InitialCondition;
  boolean_T Constant_Value_ek;
  boolean_T Constant_Value_mgr;
  boolean_T Delay_InitialCondition_bz;
  boolean_T Delay_InitialCondition_p;
  boolean_T Delay_InitialCondition_o;
  boolean_T Delay_InitialCondition_az;
  boolean_T Delay_InitialCondition_gf;
  boolean_T Delay4_InitialCondition_d;
  boolean_T Delay_InitialCondition_l;
  boolean_T Delay_InitialCondition_h5;
  boolean_T Delay_InitialCondition_b5;
  boolean_T Delay_InitialCondition_i;
  boolean_T Delay_InitialCondition_k;
  boolean_T Delay_InitialCondition_gn;
  boolean_T Delay_InitialCondition_ez;
  boolean_T Delay_InitialCondition_j;
  boolean_T Delay_InitialCondition_kr;
  boolean_T Delay7_InitialCondition;
  boolean_T Delay_InitialCondition_oa;
  uint8_T Gain6_Gain_n;
};

#endif

typedef struct P_Rotation_AHRS_GPS_T_ P_Rotation_AHRS_GPS_T;

#ifndef Rotation_AHRS_GPS_MDLREF_HIDE_CHILD_

struct tag_RTM_Rotation_AHRS_GPS_T {
  const char_T **errorStatus;
};

#endif

#ifndef Rotation_AHRS_GPS_MDLREF_HIDE_CHILD_

typedef struct {
  RT_MODEL_Rotation_AHRS_GPS_T rtm;
} MdlrefDW_Rotation_AHRS_GPS_T;

#endif

#ifndef Rotation_AHRS_GPS_MDLREF_HIDE_CHILD_

extern P_Rotation_AHRS_GPS_T Rotation_AHRS_GPS_P_g;

#endif

extern void Rotation_AHRS_GPS_Init(void);
extern void Rotation_AHRS_GPS_Reset(void);
extern void Rotation_AHRS_GPS_Start(real32_T rty_Rotation_data_vel_O_O[3]);
extern void Rotation_AHRS_GPS(const real32_T *rtu_translation_data_h_dot_mDs,
  const real32_T rtu_Sensor_data_rot_IB_B_raw_ra[3], const real32_T
  rtu_Sensor_data_sfor_R_B_mDs2[3], const boolean_T *rtu_Sensor_data_IMU_valid,
  const real32_T rtu_Sensor_data_h_R_B[3], const real32_T
  *rtu_Sensor_data_Mag_Quality, const real32_T *rtu_Sensor_data_GPS_data_Spd_qu,
  const real32_T *rtu_Sensor_data_GPS_data_vel_N, const real32_T
  *rtu_Sensor_data_GPS_data_vel_E, const real32_T
  *rtu_Sensor_data_GPS_data_vel_D, const real32_T
  *rtu_Sensor_data_GPS_data_ant_he, const boolean_T
  *rtu_Sensor_data_GPS_data_headin, const real32_T
  *rtu_Sensor_data_GPS_data_Timest, const boolean_T
  *rtu_Sensor_data_Sonar_data_sona, const real32_T
  *rtu_Sensor_data_Sonar_data_h_gr, const real32_T
  rtu_Sensor_data_Vision_data_vel[2], const real32_T
  *rtu_Sensor_data_Vision_data_Vis, const real32_T
  *rtu_Sensor_data_Vision_data_v_d, const uint8_T
  *rtu_Sensor_data_Vision_data_typ, const boolean_T *rtu_orbit_flag, const
  boolean_T *rtu_dont_reset_yaw, const boolean_T *rtu_hover_flag, const real32_T
  *rtu_h, const boolean_T *rtu_forcedArm, const boolean_T *rtu_Armed, const
  boolean_T *rtu_IMU_switched, const boolean_T *rtu_brake, const real32_T
  rtu_acc_bias_B_est[3], const boolean_T *rtu_stand_still_for_four_second,
  real32_T rty_Rotation_data_vel_O_O[3], real32_T rty_Rotation_data_ATT_quat_OB
  [4], real32_T rty_Rotation_data_M_OB[9], real32_T rty_Rotation_data_att_Oz_B[3],
  real32_T rty_Rotation_data_rot_IB_B_radD[3], real32_T
  rty_Rotation_data_sfor_R_B_mDs2[3], real32_T *rty_Rotation_data_Psi_dot_fused,
  real32_T *rty_Rotation_data_Psi_dot_IMU, real32_T rty_Rotation_data_M_OObar[4],
  real32_T *rty_Rotation_data_Euler_Transfo, real32_T
  *rty_Rotation_data_Euler_Trans_k, real32_T *rty_Rotation_data_Euler_Trans_e,
  real32_T *rty_Rotation_data_Euler_Trans_c, real32_T
  *rty_Rotation_data_Euler_Tran_ez, real32_T *rty_Rotation_data_Euler_Trans_o,
  real32_T *rty_Rotation_data_Euler_Trans_p, real32_T
  *rty_Rotation_data_Heading_Quali, real32_T *rty_Rotation_data_Mag_Quality,
  real32_T rty_Rotation_data_Bias_gyro_rad[3], real32_T
  *rty_Rotation_data_standstill, boolean_T *rty_Rotation_data_reset_Yaw,
  boolean_T *rty_Rotation_data_All_reset_Yaw, boolean_T
  *rty_Rotation_data_rp_init_reset, boolean_T *rty_Rotation_data_heading_init,
  real32_T *rty_det_yaw_gohome, boolean_T *rty_reset_yaw_flag, boolean_T
  *rty_stand_still, boolean_T *rty_att_init_done, boolean_T *rty_rp_init_done,
  real32_T *rty_yaw_mag, real32_T *rty_yaw_rate_bias, real32_T
  rty_roll_pitch_rate_bias[2], boolean_T *rty_once_stand_still);
extern void Rotation_AHRS_GPS_Term(void);
extern void Rotation_AHRS_GPS_initialize(const char_T **rt_errorStatus);

#ifndef Rotation_AHRS_GPS_MDLREF_HIDE_CHILD_

extern void Rotation_AH_MovingAverage2_Init(DW_MovingAverage2_Rotation_AH_T
  *localDW);
extern void Rotation_A_MovingAverage2_Reset(DW_MovingAverage2_Rotation_AH_T
  *localDW);
extern void Rotation_A_MovingAverage2_Start(DW_MovingAverage2_Rotation_AH_T
  *localDW);
extern void Rotation_AHRS_GP_MovingAverage2(real32_T rtu_0,
  B_MovingAverage2_Rotation_AHR_T *localB, DW_MovingAverage2_Rotation_AH_T
  *localDW);
extern void Rotation_AH_MovingAverage2_Term(DW_MovingAverage2_Rotation_AH_T
  *localDW);

#endif

#ifndef Rotation_AHRS_GPS_MDLREF_HIDE_CHILD_

extern MdlrefDW_Rotation_AHRS_GPS_T Rotation_AHRS_GPS_MdlrefDW;

#endif

#ifndef Rotation_AHRS_GPS_MDLREF_HIDE_CHILD_

extern B_Rotation_AHRS_GPS_c_T Rotation_AHRS_GPS_B;
extern DW_Rotation_AHRS_GPS_f_T Rotation_AHRS_GPS_DW;
extern ZCE_Rotation_AHRS_GPS_T Rotation_AHRS_GPS_PrevZCX;

#endif
#endif

