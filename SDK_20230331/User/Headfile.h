#ifndef __HEADFILE_H__
#define __HEADFILE_H__
/*----------------------------------------------------------------------------------------------------------------------/
*               ������ֻ����Уѧ��ѧϰʹ�ã���Ȩ����Ȩ�����人�Ƽ���ѧ���人�Ƽ���ѧ���ɿس���Դ���ṩ����Уѧ����
*               ��Уѧ��ҪΪ�人�Ƽ���ѧ�ṩ������δ��ѧУ��ɣ����ý�Դ�����ṩ�����ˣ����ý�Դ����ŵ����Ϲ�����������أ� 
*               �������Դ�����Ĳ�����緢��������Ϊ���人�Ƽ���ѧ����֮�Է��ɽ��������
-----------------------------------------------------------------------------------------------------------------------/
*               ������Ϣ���ܶ���ֹ��ǰ�����������˳���������
*               ��Դ���ף���ѧ����ϧ��ף������Ϯ�����׳ɹ�������
*               ѧϰ�����ߣ��������Ƽ���DJI��ZEROTECH��XAG��AEE��GDU��AUTEL��EWATT��HIGH GREAT�ȹ�˾��ҵ
*               ��ְ�����뷢�ͣ�15671678205@163.com���豸ע��ְ����λ����λ��������
*               �����ƴ���Դ�ɿ�QQȺ��540707961
*               CSDN���ͣ�http://blog.csdn.net/u011992534
*               �ſ�ID��NamelessCotrunWUST
*               Bվ��ѧ��Ƶ��https://space.bilibili.com/67803559/#/video
*               �ͻ�ʹ���ĵá��Ľ������������http://www.openedv.com/forum.php?mod=viewthread&tid=234214&extra=page=1
*               �Ա����̣�https://shop348646912.taobao.com/?spm=2013.1.1000126.2.5ce78a88ht1sO2
*               �ٶ�����:�����ƴ���Դ�ɿ�
*               ��˾����:www.nameless.tech
*               �޸�����:2019/4/12
*               �汾����Ӯ�ߡ���CarryPilot_V1.0
*               ��Ȩ���У�����ؾ���
*               Copyright(C) 2017-2025 �人�������¿Ƽ����޹�˾ 
*               All rights reserved
*               ��Ҫ��ʾ��
*               �����Ա�����ת�ֵķɿء��������ѡ�����ѧ�ܵĶ����Խ��ۺ�Ⱥѧϰ������
*               ����ֱ�����������������������ϣ��������´�����������Ȩ�����˲��ý�
*               ���ϴ��봫���Ϲ��������أ�������ı��ΪĿ���������ϴ��룬�����д˲�
*               ѧУ����˾����ǰ��֪����1���ڼ�ʱ�����������ѧУ����λ����������
*               ������ַ��Ϣ�ᱻ�����ڹ�˾�������ٷ�΢�Ź���ƽ̨���ٷ��������͡�֪��
*               ר���Լ��Ա�������ҳ���Թ�ʾ���棬����������Ϊ�����Ϊ�����۵㣬Ӱ��
*               ��ѧ���ҹ���������������ܿ�ͺ������˻����������������ء�
*               �����Ϊ����˾����ش���ʧ�ߣ����Է���;���������л���ĺ�����лл������
----------------------------------------------------------------------------------------------------------------------*/



#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>


#define ABS(X)  (((X)>0)?(X):-(X))
#define MAX(a,b)  ((a)>(b)?(a):(b))


#define Imu_Sampling_Freq  400
#define FC_Control_Freq  400
#define Imu_Sampling_Dt  (1.0f/Imu_Sampling_Freq)


#define WP_Duty_Freq  200
#define WP_Duty_Dt  (1.0f/WP_Duty_Freq)


typedef   signed           char int8;
typedef unsigned           char u8;
typedef unsigned           char uint8;
typedef unsigned           char byte;
typedef   signed short     int int16;
typedef unsigned short     int uint16;
typedef unsigned short     int u16;
typedef unsigned long     int u32; 

#define US100  0
#define TFMINI 1
#define Ground_Distance_Sensor  US100




#define _YAW    0
#define _PITCH  1
#define _ROLL   2

#define Delta 0.0025f
#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
/////////////////////////
#include "WP_DataType.h"
#include "Usart.h"
//#include "uartstdio.h"
#include "Time.h"
#include "Time_Cnt.h"
//#include "Schedule.h"
#include "License.h"
#include "ssd1306.h"
#include "oled.h"
#include "mpu6050.h"
#include "Soft_I2C.h"
#include "ist8310.h"
#include "spl06.h"
#include "PPM.h"
#include "wp_flash.h"
#include "softiic.h"
#include "stflash.h"

#include "PID.h"
#include "ADRC.h"
#include "Ringbuf.h"
#include "WP_PWM.h"
#include "Sensor.h"
#include "Key.h"
#include "Filter.h"
#include "SINS.h"
#include "Calibration.h"
#include "CalibrationRoutines.h"
#include "US_100.h"
#include "GY53L1x.h"
#include "tfmini.h"
#include "NamelessCorun_OpticalFlow.h"
#include "OpticalFlow_LC306.h"
#include "OpticalFlow_Control.h"
#include "NamelessCotrun_SDK.h"
#include "WP_ADC.h"
#include "Bling.h"
#include "GPS.h"
#include "RC.h"
#include "SYSTEM.h"
#include "WP_Ctrl.h"
#include "Developer_Mode.h"
#include "control_config.h"
#include "Temperature_Ctrl.h"
#include "Compass.h"
#include "NCLink.h"

#include "Myfile.h"
#include "My_task.h"
#include "key1.h"
extern SINS NamelessQuad;
extern Sensor WP_Sensor;


#define SDK_HEIGHT 150

#endif

//void Angle_Control()//�ǶȻ���
//{
//  //�Ƕȷ���
//  Total_Controller.Pitch_Angle_Control.FeedBack=(Pitch-Pitch_Offset);
//  PID_Control(&Total_Controller.Pitch_Angle_Control);
//  Total_Controller.Roll_Angle_Control.FeedBack =(Roll-Roll_Offset);
//  PID_Control(&Total_Controller.Roll_Angle_Control);
//  
//  if(Yaw_Control==0)//ƫ����������λ
//  {
//    if(Total_Controller.Yaw_Angle_Control.Expect==0//����ʱ���Ƕ�����ֵ
//       ||Landon_Earth_Flag==1)//�������㴥����������λƫ��������
//    {
//      Total_Controller.Yaw_Angle_Control.Expect=Yaw;
//    }
//    Total_Controller.Yaw_Angle_Control.FeedBack=Yaw;//ƫ���Ƿ���
//    PID_Control_Yaw(&Total_Controller.Yaw_Angle_Control);//ƫ���Ƕȿ���
//    Total_Controller.Yaw_Gyro_Control.Expect=Total_Controller.Yaw_Angle_Control.Control_OutPut;//ƫ�����ٶȻ���������Դ��ƫ���Ƕȿ��������
//    
//    if(Opv_Top_View_Target.line_ctrl_enable==1&&Controler_SDK2_Mode==1)//SDKģʽ�µ�ѭ��ģʽ��ƫ�����ٶ�������Դ��SDK����
//    {
//      Total_Controller.Yaw_Gyro_Control.Expect=3*SDK_Target_Yaw_Gyro;
//      Total_Controller.Yaw_Angle_Control.Expect=0;//ƫ����������0,�����нǶȿ���
//      //SDK_Line.flag=0;
//    }
//  }
//  else//����ƫ������˺�ֻ�����ڻ����ٶȿ���
//  {
//    Total_Controller.Yaw_Angle_Control.Expect=0;//ƫ����������0,�����нǶȿ���
//    Total_Controller.Yaw_Gyro_Control.Expect=Yaw_Control;//ƫ�����ٶȻ�������ֱ����Դ��ң���������
//  }
//}


