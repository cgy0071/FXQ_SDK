#ifndef _MYFILE_H_
#define _MYFILE_H_


/*************************
******����debug��flag*****
*************************/
extern uint8_t Flag1;
extern uint8_t Flag2;
extern uint8_t Flag3;

extern float Value1;
extern float Value2;
extern float Value3;

extern uint16_t PID_count;


/*ƫ������*/

extern float control_yaw_delta_max(float delta_yaw_target,float delta_max);
extern uint8_t control_yaw_delta(float delta_yaw_target);

extern uint8_t control_yaw_rotate(float delta_yaw_target,SDK_Status *Status,uint16_t number);
extern uint8_t control_yaw(float delta_yaw_target,float yaw_vel,float delta,SDK_Status *Status,uint16_t number);




/***************OPENMVģʽ���ã�����*******************/
extern uint8_t SDK_Ground_updata;
extern uint8_t SDK_Front_updata;
extern uint8_t Ground_OPENMV_mode;
extern uint8_t Front_OPENMV_mode;
extern void SDK_OPENMV_Config(uint8_t *updata,uint8_t mode,COM_SDK com);

/*********************��ֲ������******************/
extern uint8_t gyro_expect_sdk_ctrl_mode;
extern float gyro_expect_sdk;




#endif

