/* Copyright (c)  2018-2025 Wuhan Nameless Innovation Technology Co.,Ltd. All rights reserved.*/
/*----------------------------------------------------------------------------------------------------------------------/
                ��Դ����������ѣ������ߵ���ʷ�Ѿ�֤�����ڹ�����������£���������Ŀ�Դ������������˰����ߣ��Է��ز�����
								Ŀ���Ƶķ�ʽ�в�ͨ���õĿ�Դ��Ŀ��Ҫ��רְ��Ա�����ۺ�����ְ��ֽ�ѧ��ͳ���û�����������ʵ������ɶԲ�
								Ʒ��һ�δ���������������������ۺϿ��ǣ������ɿؿ�Դ�����У������������˾���漤��ܴ��룬�汾������ʵ��
								���ܣ����ڹ�˾��Ʒ���������������Ӱ��ͻ�ѧϰ���������ȫ�����Ÿ��ͻ�ѧϰ���ͻ���ֲ�Ͷ��ο��������뱣����
								���Ȩ��
-----------------------------------------------------------------------------------------------------------------------/
*               ������ֻ��������ѧϰʹ�ã���Ȩ����Ȩ���������ƴ��Ŷӣ������ƴ��Ŷӽ��ɿس���Դ���ṩ�������ߣ�
*               ������ҪΪ�����ƴ��Ŷ��ṩ������δ��������ɣ����ý�Դ�����ṩ�����ˣ����ý�Դ����ŵ����Ϲ�����������أ� 
*               �������Դ�����Ĳ�����緢��������Ϊ�������ƴ��Ŷӽ���֮�Է��ɽ��������
-----------------------------------------------------------------------------------------------------------------------
*                                                 Ϊʲôѡ���������£�
*                                         �ж����ļ۸�������׵Ŀ�Դ�ɿأ�
*                                         ����ҵ������֮������µ��ۺ����
*                                         ׷�����û����飬��Ч����ѧϰ֮·��
*                                         ���²��ٹµ�������������տ�Դ�߶ȣ�
*                                         ��Ӧ���ҷ�ƶ���٣��ٽ��������ƹ�ƽ��
*                                         ��ʱ���ܶ�����ʣ����������˹�ͬ�塣 
-----------------------------------------------------------------------------------------------------------------------
*               ������Ϣ���ܶ���ֹ��ǰ�����������˳���������
*               ��Դ���ף���ѧ����ϧ��ף������Ϯ�����׳ɹ�������
*               ѧϰ�����ߣ��������Ƽ���DJI��ZEROTECH��XAG��AEE��GDU��AUTEL��EWATT��HIGH GREAT�ȹ�˾��ҵ
*               ��ְ�����뷢�ͣ�15671678205@163.com���豸ע��ְ����λ����λ��������
*               �����ƴ���Դ�ɿ�QQȺ��2��Ⱥ465082224��1��Ⱥ540707961����Ա������
*               CSDN���ͣ�http://blog.csdn.net/u011992534
*               �ſ�ID��NamelessCotrun����С��
*               Bվ��ѧ��Ƶ��https://space.bilibili.com/67803559/#/video
*               �ͻ�ʹ���ĵá��Ľ������������http://www.openedv.com/forum.php?mod=viewthread&tid=234214&extra=page=1
*               �Ա����̣�https://shop348646912.taobao.com/?spm=2013.1.1000126.2.5ce78a88ht1sO2
*               �ٶ�����:�����ƴ���Դ�ɿ�
*               ��˾����:www.nameless.tech
*               �������¹����׿�TI��Դ�ɿ���Ƴ��ԡ�֪��ר��:https://zhuanlan.zhihu.com/p/54471146
*               �޸�����:2021/04/30                    
*               �汾��������PLUS����GankerPilot_V3.0
*               ��Ȩ���У�����ؾ���
*               Copyright(C) 2019-2025 �人�������¿Ƽ����޹�˾ 
*               All rights reserved
-----------------------------------------------------------------------------------------------------------------------
*               ��Ҫ��ʾ��
*               �����Ա�����ת�ֵķɿء��������ѡ�����ѧ�ܵĶ����Խ��ۺ�Ⱥѧϰ������
*               ����ֱ�����������������������ϣ��������´�����������Ȩ�����˲��ý�
*               ���ϴ��봫���Ϲ��������أ�������ı��ΪĿ���������ϴ��룬�����д˲�
*               ���ߣ���˾����ǰ��֪����1���ڼ�ʱ�����������ѧУ����λ����������
*               ������ַ��Ϣ�ᱻ�����ڹ�˾�������ٷ�΢�Ź���ƽ̨���ٷ��������͡�֪��
*               ר���Լ��Ա�������ҳ���Թ�ʾ���棬����������Ϊ�����Ϊ�����۵㣬Ӱ��
*               ��ѧ���ҹ���������������ܿ�ͺ������˻����������������ء�
*               �����Ϊ����˾����ش���ʧ�ߣ����Է���;���������л���ĺ�����лл������
----------------------------------------------------------------------------------------------------------------------*/
#include "Headfile.h"
#include "SYSTEM.h"

/***********************************************************
@��������HardWave_Init
@��ڲ�������
@���ڲ�������
������������ϵͳоƬ��Դ����Ӳ����Դ����һϵ�г�ʼ���������
����ʼ�����ע��
@���ߣ�WUST
@���ڣ�2019��01��27��
*************************************************************/
void HardWave_Init(void)
{
  System_Init();												//ϵͳʱ�ӳ�ʼ����δ����
	USART1_Init();												//ǰ��OPENMV 921600		
	USART2_Init(); 												//�����ڳ�ʼ��(�������µ���վ&ɽ�����վ)������115200
	USART0_Init(); 												//����   19200
	USART3_Init(); 												//����OPENMV 921600
	ADC_Init();    												//оƬAD����ʼ��
  Butterworth_Parameter_Init();					//�˲���������ʼ��
  Bling_Init();													//LED״ָ̬ʾ�Ƴ�ʼ��
  Quad_Start_Bling();										//����LEDԤ��ʾ
	Simulation_PWM_Init();								//ģ��PWM��ʼ��
  Key_Init();														//���ذ�����ʼ��
  RC_Calibration_Trigger();							//ң�����г̱궨���
  Horizontal_Calibration_Init();				//����ˮƽ�궨��ʼ��
  PID_Paramter_Init_With_Flash();				//PID������ʼ��
	Other_Parameter_Init();         			//����������ʼ��
	ADRC_Init(&ADRC_Alt_Vel_Controller,2);//�Կ��ſ�������ʼ��
	delay_ms(1000);												//��ʼ����ʱ
  Init_MPU6050();												//MPU6050�����ǡ����ٶȼ����ó�ʼ��
  SPL06_Init();													//SPL06��ѹ�����ó�ʼ��
	//US100_Init();													//���������ó�ʼ��
	GY53L1X_Init();												//�����ഫ�������ó�ʼ��
	//Compass_Init();                 			//�����Ƴ�ʼ��
  Parameter_Init();											//���ٶȼ�У׼������ʼ��
  WP_Quad_Init();												//���ݹ۲⴫�������ٶȼƶ���̬��Ԫ����ʼ��
	delay_ms(2500);												//������ʱ�ȴ�openmv������λ�����ڳ�ʼ����openmv����ģʽ
	SDK_Init();														//SDKģʽ��ʼ��
	Temperature_Ctrl_Init();							//�¶ȿ�������ʼ��
  Time_init();													//�ɿص��ȶ�ʱ����ʼ��
	LCD_CLS();
	
	//*************PID������ʼ��**************//
	
	//�������ٶ�
	Total_Controller.Pitch_Gyro_Control.Kp=2.00;//1.90//2.50;//�������ٶ�
	Total_Controller.Pitch_Gyro_Control.Ki=0.80;//0.80;
	Total_Controller.Pitch_Gyro_Control.Kd=0.44;//0.50;//0.48
	
	//�������ٶȻ�
	Total_Controller.Roll_Gyro_Control.Kp=2.20;//2.60;//������ٶ�
	Total_Controller.Roll_Gyro_Control.Ki=1.00;//1.00;
	Total_Controller.Roll_Gyro_Control.Kd=0.42;//0.45//0.43
	
	//ƫ�����ٶȻ� 
	Total_Controller.Yaw_Gyro_Control.Kp = 1.50;//1.2
	Total_Controller.Yaw_Gyro_Control.Ki = 1.10;//1.1
	Total_Controller.Yaw_Gyro_Control.Kd = 0.00;	
	
	//�Ƕ��⻷,Ĭ�ϵ��Ѿ�����ˣ��Ͳ���΢��
	
	Total_Controller.Pitch_Angle_Control.Kp=4.20;//5.00;//�����Ƕ�
	Total_Controller.Pitch_Angle_Control.Ki=0.00;//0.00;
	Total_Controller.Pitch_Angle_Control.Kd=0.00;//0.00;
	
	Total_Controller.Roll_Angle_Control.Kp=4.20;//5.00;//����Ƕ�
	Total_Controller.Roll_Angle_Control.Ki=0.00;//0.00
	Total_Controller.Roll_Angle_Control.Kd=0.00;//0.00
	/*
	Total_Controller.Yaw_Angle_Control.Kp=5.00;//5.00;//5.00;//ƫ���Ƕ�
	Total_Controller.Yaw_Angle_Control.Ki=0.00;//0.00;
	Total_Controller.Yaw_Angle_Control.Kd=0.00;//0.00;//0.03;
	*/
	
	//�߶��ٶ�
	/*
	Total_Controller.High_Speed_Control.Kp=4.745;//3.00;//���������ٶ�
	Total_Controller.High_Speed_Control.Ki=0.05;//0.05;
	Total_Controller.High_Speed_Control.Kd=0.0551;//0.15;
	
	//�߶�λ��
	Total_Controller.High_Position_Control.Kp=0.50;//2.50;//���θ߶�λ��
	Total_Controller.High_Position_Control.Ki=0.00;//0.35;
	Total_Controller.High_Position_Control.Kd=0.025;//0.30;
	*/

	//�߶ȼ��ٶ�
	Total_Controller.High_Acce_Control.Kp = 0.28;//0.29;0.17//�߶ȼ��ٶ�
	Total_Controller.High_Acce_Control.Ki = 2.50;//2.20;
	Total_Controller.High_Acce_Control.Kd = 0.00;//0.00;	
	
	
	//����λ�û�
	/*
	Total_Controller.Optical_Position_Control.Kp=0.1;//0.18//����λ��
	Total_Controller.Optical_Position_Control.Ki=0.00;//0.00
	Total_Controller.Optical_Position_Control.Kd=0.00;//0.00
	*/
	
	//�����ٶȻ�
	Total_Controller.Optical_Speed_Control.Kp =6.90;//5.80//6.9
	Total_Controller.Optical_Speed_Control.Ki = 0.01;//0.01
	Total_Controller.Optical_Speed_Control.Kd = 1.00;//1.00
	//��������Ȩ��Ҳ��Ӱ��ǰ��//�����ڻ���0.04ʱ�ȶ�
	//���ǹ��ﻥ��Ȩ��Ӱ����Ϊ�ľ��룬��Ӧ���ù��ﻥ��Ȩ�������ȶ�
	
	//SDK
	/*
	Total_Controller.SDK_Roll_Position_Control.Kp=0.35;
	Total_Controller.SDK_Roll_Position_Control.Ki=0.05;//0.05;
	Total_Controller.SDK_Roll_Position_Control.Kd=0.05;//1.00;

	Total_Controller.SDK_Pitch_Position_Control.Kp=0.35;
	Total_Controller.SDK_Pitch_Position_Control.Ki=0.05;//0.05;
	Total_Controller.SDK_Pitch_Position_Control.Kd=0.05;//1.00;
	*/
	
	
}

/* Copyright (c)  2018-2025 Wuhan Nameless Innovation Technology Co.,Ltd. All rights reserved.*/
