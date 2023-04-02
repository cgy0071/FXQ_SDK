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
#include "Earth_Declination.h"
#include "SINS.h"

/***********************************************************
@��������Vector_From_BodyFrame2EarthFrame
@��ڲ�����Vector3f *bf,Vector3f *ef
@���ڲ�������
��������������ϵ�򵼺�ϵת��
@���ߣ�����С��
@���ڣ�2019��01��27��
*************************************************************/
void Vector_From_BodyFrame2EarthFrame(Vector3f *bf,Vector3f *ef)
{
  ef->x=rMat[0][0]*bf->x+rMat[0][1]*bf->y+rMat[0][2]*bf->z;
  ef->y=rMat[1][0]*bf->x+rMat[1][1]*bf->y+rMat[1][2]*bf->z;
  ef->z=rMat[2][0]*bf->x+rMat[2][1]*bf->y+rMat[2][2]*bf->z;
}

/***********************************************************
@��������Vector_From_EarthFrame2BodyFrame
@��ڲ�����Vector3f *ef,Vector3f *bf
@���ڲ�������
��������������ϵ������ϵת��
@���ߣ�����С��
@���ڣ�2019��01��27��
*************************************************************/
void Vector_From_EarthFrame2BodyFrame(Vector3f *ef,Vector3f *bf)
{
  bf->x=rMat[0][0]*ef->x+rMat[1][0]*ef->y+rMat[2][0]*ef->z;
  bf->y=rMat[0][1]*ef->x+rMat[1][1]*ef->y+rMat[2][1]*ef->z;
  bf->z=rMat[0][2]*ef->x+rMat[1][2]*ef->y+rMat[2][2]*ef->z;
}

SINS NamelessQuad;
Butter_BufferData accel_feedback_filter_buf[3];
float Acceleration_Feedback[3];
Vector2f SINS_Accel_Body={0,0};
/***********************************************************
@��������SINS_Prepare
@��ڲ�������
@���ڲ�������
�����������ߵ����ٶ�׼��
@���ߣ�����С��
@���ڣ�2019��01��27��
*************************************************************/
void  SINS_Prepare(void)
{
  Vector2f SINS_Accel_Earth={0,0};
  Vector3f Body_Frame,Earth_Frame;
  /*Z-Y-Xŷ����ת�������Ҿ���
  //Pitch Roll  Yaw �ֱ��Ӧ�� �� ��  
  X����ת����
  R������
  {1      0        0    }
  {0      cos��    sin��}
  {0    -sin��    cos�� }
  
  Y����ת����
  R���ȣ�
  {cos��     0        -sin��}
  {0         1        0     }
  {sin��     0        cos��}
  
  Z����ת����
  R���ȣ�
  {cos��      sin��       0}
  {-sin��     cos��       0}
  {0          0           1 }
  
  ��Z-Y-X˳����:
  ��������ϵ����������ϵ����ת����R(b2n)
  R(b2n) =R(��)^T*R(��)^T*R(��)^T
  
  R=
  {cos��*cos��     -cos��*sin��+sin��*sin��*cos��        sin��*sin��+cos��*sin��*cos��}
  {cos��*sin��     cos��*cos�� +sin��*sin��*sin��       -cos��*sin��+cos��*sin��*sin��}
  {-sin��          cos��sin ��                          cos��cos��                   }
  */
  Body_Frame.x=ins_accel_filter.x;
  Body_Frame.y=ins_accel_filter.y;
  Body_Frame.z=ins_accel_filter.z;
  Vector_From_BodyFrame2EarthFrame(&Body_Frame,&Earth_Frame);
  NamelessQuad.Origion_Acceleration[_YAW]=Earth_Frame.z;
  NamelessQuad.Origion_Acceleration[_PITCH]=Earth_Frame.x;
  NamelessQuad.Origion_Acceleration[_ROLL]=Earth_Frame.y;
  
  
  NamelessQuad.Origion_Acceleration[_YAW]*=AcceGravity/AcceMax;
  NamelessQuad.Origion_Acceleration[_YAW]-=AcceGravity;//��ȥ�������ٶ�
  NamelessQuad.Origion_Acceleration[_YAW]*=100;//���ٶ�cm/s^2
  
  NamelessQuad.Origion_Acceleration[_PITCH]*=AcceGravity/AcceMax;
  NamelessQuad.Origion_Acceleration[_PITCH]*=100;//���ٶ�cm/s^2
  
  NamelessQuad.Origion_Acceleration[_ROLL]*=AcceGravity/AcceMax;
  NamelessQuad.Origion_Acceleration[_ROLL]*=100;//���ٶ�cm/s^2
  
  /******************************************************************************/
  //�����˻��ڵ�������ϵ�µ���������������������˶����ٶ���ת����ǰ������˶����ٶ�:��ͷ(����)+���
  
  SINS_Accel_Earth.x=NamelessQuad.Origion_Acceleration[_PITCH];//�ص�������ϵ�����������˶����ٶ�,��λΪCM
  SINS_Accel_Earth.y=NamelessQuad.Origion_Acceleration[_ROLL];//�ص�������ϵ�����������˶����ٶ�,��λΪCM
  
  SINS_Accel_Body.x= SINS_Accel_Earth.x*Cos_Yaw+SINS_Accel_Earth.y*Sin_Yaw;  //��������˶����ٶ�  X������
  SINS_Accel_Body.y=-SINS_Accel_Earth.x*Sin_Yaw+SINS_Accel_Earth.y*Cos_Yaw; //��ͷ�����˶����ٶ�  Y������
  
  
  Body_Frame.x=LPButterworth(accel.x,&accel_feedback_filter_buf[0],&Butter_5HZ_Parameter_Acce);
  Body_Frame.y=LPButterworth(accel.y,&accel_feedback_filter_buf[1],&Butter_5HZ_Parameter_Acce);
  Body_Frame.z=LPButterworth(accel.z,&accel_feedback_filter_buf[2],&Butter_5HZ_Parameter_Acce);
//	Body_Frame.x=accel.x;
//	Body_Frame.y=accel.y;
//	Body_Frame.z=accel.z;		
  Vector_From_BodyFrame2EarthFrame(&Body_Frame,&Earth_Frame);
  Acceleration_Feedback[_YAW]=Earth_Frame.z;
  Acceleration_Feedback[_PITCH]=Earth_Frame.x;
  Acceleration_Feedback[_ROLL]=Earth_Frame.y;
  Acceleration_Feedback[_YAW]*=AcceGravity/AcceMax;
  Acceleration_Feedback[_YAW]-=AcceGravity;//��ȥ�������ٶ�
  Acceleration_Feedback[_YAW]*=100;//���ٶ�cm/s^2
  Acceleration_Feedback[_PITCH]*=AcceGravity/AcceMax;
  Acceleration_Feedback[_PITCH]*=100;//���ٶ�cm/s^2
  Acceleration_Feedback[_ROLL]*=AcceGravity/AcceMax;
  Acceleration_Feedback[_ROLL]*=100;//���ٶ�cm/s^2
}





#define Ra  1.0f//1.0 0.5
#define KALMAN_DT 0.1f
float Q[2]={0.5f*Ra*KALMAN_DT*KALMAN_DT,Ra*KALMAN_DT};//{1.0e-6f,5.0e-4f};{5.0e-6f,6.0e-4f}

float R_Baro=15;//80
float R_Ground=1.0;//1.5
float R=1.0;// 15  5  30  10  500

#define  Observation_Err_Max   500//cm
float Acce_Bias_Gain_Ki[3]={
  0.025,//0.075    0.005
  0.0005,//0.001
  0.0005,//0.001
};
float Acce_Bias_Gain_Kp={
  0.03,//0.1~0.75
};
float Pre_conv[4]=
{
  0.5,0.25,
  0.25,0.5
};//��һ��Э����
/***********************************************************
@��������KalmanFilter
@��ڲ�����float Observation,//λ�ù۲���
					 uint16 Pos_Delay_Cnt,//�۲⴫������ʱ��
					 SINS *Ins_Kf,//�ߵ��ṹ��
					 float System_drive,//ϵͳԭʼ���������ߵ����ٶ�
					 float *R,
					 float Q,
					 float dt,
					 uint16 N,
					 uint8_t update_flag
@���ڲ�������
�����������߶ȷ���ߵ��������˲�
@���ߣ�����С��
@���ڣ�2019��01��27��
*************************************************************/
float observation_div=0;
float last_observation=0;
float observation_acc;
uint8_t observation_reset_flag=0;
void  KalmanFilter(float Observation,//λ�ù۲���
                   uint16 Pos_Delay_Cnt,//�۲⴫������ʱ��
                   SINS *Ins_Kf,//�ߵ��ṹ��
                   float System_drive,//ϵͳԭʼ���������ߵ����ٶ�
                   float *R,
                   float Q,
                   float dt,
                   uint16 N,
                   uint8_t *update_flag)
{
  uint16 Cnt=0;
  static uint16 Speed_Sync_Cnt=0;
	float Q_Temp=0;
  float Temp_conv[4]={0};//����Э����
  float Conv_Z=0,Z_Cor=0;
  float k[2]={0};//�������
  float Ctemp=0;

	Q_Temp=constrain_float(Q,0,1500);
  //����״̬
  Ins_Kf->Acceleration[N]=System_drive;
  Ins_Kf->Acceleration[N]=Ins_Kf->Acce_Bias_All[N]+Ins_Kf->Acceleration[N];
  Ins_Kf->Position[N] +=Ins_Kf->Speed[N]*dt+(Ins_Kf->Acceleration[N]*dt*dt)/2.0f;
  Ins_Kf->Speed[N]+=Ins_Kf->Acceleration[N]*dt;
  if(*update_flag==1)
  {
    //����Э����
    Ctemp=Pre_conv[1]+Pre_conv[3]*KALMAN_DT;
    Temp_conv[0]=Pre_conv[0]+Pre_conv[2]*KALMAN_DT+Ctemp*KALMAN_DT+R[0];
    Temp_conv[1]=Ctemp;
    Temp_conv[2]=Pre_conv[2]+Pre_conv[3]*KALMAN_DT;;
    Temp_conv[3]=Pre_conv[3]+R[1];
    //���㿨��������
    Conv_Z=Temp_conv[0]+Q_Temp;
    k[0]=Temp_conv[0]/Conv_Z;
    k[1]=Temp_conv[2]/Conv_Z;
    //�ں��������
//		Z_Cor=constrain_float(Observation-Ins_Kf->Pos_History[N][Pos_Delay_Cnt],-Observation_Err_Max,Observation_Err_Max);	
		Z_Cor=Observation-Ins_Kf->Pos_History[N][Pos_Delay_Cnt];	
    Ins_Kf->Position[N] +=k[0]*Z_Cor;
    Ins_Kf->Speed[N] +=k[1]*Z_Cor;
    Ins_Kf->Acce_Bias[N]+=Acce_Bias_Gain_Ki[_YAW]*Z_Cor;
		Ins_Kf->Acce_Bias[N]=constrain_float(Ins_Kf->Acce_Bias[N],-100,100);
		Ins_Kf->Acce_Bias_All[N]=Acce_Bias_Gain_Kp*Z_Cor+Ins_Kf->Acce_Bias[N];
		
		
    //����״̬Э�������
    Pre_conv[0]=(1-k[0])*Temp_conv[0];
    Pre_conv[1]=(1-k[0])*Temp_conv[1];
    Pre_conv[2]=Temp_conv[2]-k[1]*Temp_conv[0];
    Pre_conv[3]=Temp_conv[3]-k[1]*Temp_conv[1]; 
		*update_flag=0;
  }
  
  for(Cnt=Num-1;Cnt>0;Cnt--)//5ms����һ��
  {
    Ins_Kf->Pos_History[N][Cnt]=Ins_Kf->Pos_History[N][Cnt-1];
  }
  Ins_Kf->Pos_History[N][0]=Ins_Kf->Position[N];
  
  Speed_Sync_Cnt++;
  if(Speed_Sync_Cnt>=2)//10ms����һ��
  {
    for(Cnt=Num-1;Cnt>0;Cnt--)
    {
      Ins_Kf->Vel_History[N][Cnt]=Ins_Kf->Vel_History[N][Cnt-1];
    }
    Speed_Sync_Cnt=0;
  }
  Ins_Kf->Vel_History[N][0]=Ins_Kf->Speed[N];
}



uint16 SPL06_Sync_Cnt=5;//5  30
uint16 HCSR04_Sync_Cnt=5;//0
uint16 High_Delay_Cnt=0;
float Observation_Altitude=0;
uint8_t altitude_updtate_flag=0;
/***********************************************************
@��������Observation_Tradeoff
@��ڲ�����uint8_t HC_SR04_Enable
@���ڲ�������
�����������߶ȷ���۲⴫���������л�
@���ߣ�����С��
@���ڣ�2019��01��27��
*************************************************************/
void Observation_Tradeoff(uint8_t HC_SR04_Enable)
{
  static uint8_t observation_flag=1,last_observation_flag=1;
  uint16 Cnt=0;
  last_observation_flag=observation_flag;
  if(HC_SR04_Enable==0)//�޳�����/�Եش���������
  {
    Observation_Altitude=WP_Sensor.baro_altitude;//�߶ȹ۲���
    High_Delay_Cnt=SPL06_Sync_Cnt;
		observation_div=WP_Sensor.baro_altitude_div;
		observation_acc=WP_Sensor.baro_altitude_acc;
		if(WP_Sensor.baro_updtate_flag==1)
		{
			altitude_updtate_flag=WP_Sensor.baro_updtate_flag;
			WP_Sensor.baro_updtate_flag=0;
		}
		R=R_Baro;
  }
  else//�г�����/�Եش���������
  {
#if Ground_Distance_Sensor==US100    
    if(Sensor_Flag.Ground_Health==1)
    {
			float _US_Distance=Ground_Distance*Cos_Pitch*Cos_Roll;
      Observation_Altitude=_US_Distance;
      High_Delay_Cnt=HCSR04_Sync_Cnt;
      observation_flag=2;
			observation_div=Ground_Distance_Div;
			observation_acc=Ground_Distance_Acc;
			if(WP_Sensor.us100_updtate_flag==1)
			{
				altitude_updtate_flag=WP_Sensor.us100_updtate_flag;
				WP_Sensor.us100_updtate_flag=0;
			}
			R=R_Ground;
    }
#else		
    if(tfdata.health==1)
    {
      Observation_Altitude=tfdata.distance;
      High_Delay_Cnt=5;
      observation_flag=2;
			observation_div=tfdata.div;
			observation_acc=tfdata.acc;
			if(WP_Sensor.tfmini_updtate_flag==1)
			{
				altitude_updtate_flag=WP_Sensor.tfmini_updtate_flag;
				WP_Sensor.tfmini_updtate_flag=0;
			}
			R=R_Ground;
    }
#endif		
		
    else
    {
      Observation_Altitude=WP_Sensor.baro_altitude;//�߶ȹ۲���
      High_Delay_Cnt=SPL06_Sync_Cnt;
			observation_div=WP_Sensor.baro_altitude_div;
			observation_acc=WP_Sensor.baro_altitude_acc;
			if(WP_Sensor.baro_updtate_flag==1)
			{
				altitude_updtate_flag=WP_Sensor.baro_updtate_flag;
				WP_Sensor.baro_updtate_flag=0;
			}
			R=R_Baro;
    } 
    
    if(observation_flag==2&&last_observation_flag==1)//��ѹ���г�����
    {
#if Ground_Distance_Sensor==US100
			float _US_Distance=Ground_Distance*Cos_Pitch*Cos_Roll;			
      NamelessQuad.Position[_YAW]=_US_Distance;
      for(Cnt=Num-1;Cnt>0;Cnt--){NamelessQuad.Pos_History[_YAW][Cnt]=_US_Distance;}
      NamelessQuad.Pos_History[_YAW][0]=_US_Distance;
      Total_Controller.High_Position_Control.Expect=_US_Distance;//���ߵ��߶�����Ϊ�����߶ȣ����ҽ�����һ��
      
      NamelessQuad.Position[_YAW]=_US_Distance;
      NamelessQuad.Speed[_YAW]=0;
#else	
      NamelessQuad.Position[_YAW]=tfdata.distance;
      for(Cnt=Num-1;Cnt>0;Cnt--){NamelessQuad.Pos_History[_YAW][Cnt]=tfdata.distance;}
      NamelessQuad.Pos_History[_YAW][0]=tfdata.distance;
      Total_Controller.High_Position_Control.Expect=tfdata.distance;//���ߵ��߶�����Ϊ�����߶ȣ����ҽ�����һ��
      
      Origion_NamelessQuad.Position[_YAW]=tfdata.distance;
      Origion_NamelessQuad.Speed[_YAW]=0;
#endif
			R=R_Ground;
    }
    else if(observation_flag==1&&last_observation_flag==2)//����������ѹ��
    {
      NamelessQuad.Position[_YAW]=Observation_Altitude;
      for(Cnt=Num-1;Cnt>0;Cnt--){NamelessQuad.Pos_History[_YAW][Cnt]=Observation_Altitude;}
      NamelessQuad.Pos_History[_YAW][0]=Observation_Altitude;
      Total_Controller.High_Position_Control.Expect=Observation_Altitude;//���ߵ��߶�����Ϊ�����߶ȣ����ҽ�����һ��
      NamelessQuad.Position[_YAW]=Observation_Altitude;
      NamelessQuad.Speed[_YAW]=0;
			R=R_Baro;
    }
  }
}

Testime SINS_High_Delta;
/***********************************************************
@��������Strapdown_INS_High_Kalman
@��ڲ�������
@���ڲ�������
�����������߶ȷ��򿨶����˲�
@���ߣ�����С��
@���ڣ�2019��01��27��
*************************************************************/
void Strapdown_INS_High_Kalman(void)
{
	float Delta_T;
  Test_Period(&SINS_High_Delta);
  Delta_T=SINS_High_Delta.Time_Delta/1000.0f;
  if(Delta_T>2*WP_Duty_Dt||Delta_T<WP_Duty_Dt||isnan(Delta_T)!=0)   Delta_T=WP_Duty_Dt;
  Observation_Tradeoff(1);
	if(Gyro_Safety_Calibration_Flag==1)
	{
		KalmanFilter(Observation_Altitude,//λ�ù۲���
								 High_Delay_Cnt,//�۲⴫������ʱ��
								 &NamelessQuad,//�ߵ��ṹ��
								 NamelessQuad.Origion_Acceleration[_YAW],//ϵͳԭʼ���������ߵ����ٶ�
								 Q,
								 R,
								 Delta_T,
								 _YAW,
								 &altitude_updtate_flag);
	}
}







void Strapdown_INS_Reset(SINS *Ins,uint8_t Axis,float Pos_Target,float Vel_Target)
{
  uint16_t Cnt=0;
  Ins->Position[Axis]=Pos_Target;//λ������
  Ins->Speed[Axis]=Vel_Target;//�ٶ�����
  Ins->Acceleration[Axis]=0.0f;//���ٶ�����
  Ins->Acce_Bias[Axis]=0.0f;
  for(Cnt=Num-1;Cnt>0;Cnt--)//��ʷλ��ֵ��ȫ��װ��Ϊ��ǰ�۲�ֵ
  {
    Ins->Pos_History[Axis][Cnt]=Pos_Target;
  }
  Ins->Pos_History[Axis][0]=Pos_Target;
  for(Cnt=Num-1;Cnt>0;Cnt--)//��ʷ�ٶ�ֵ��ȫ��װ��Ϊ��ǰ�۲�ֵ
  {
    Ins->Vel_History[Axis][Cnt]=Vel_Target;
  }
  Ins->Vel_History[Axis][0]=Vel_Target;
}


