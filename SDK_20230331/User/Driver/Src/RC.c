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
#include "RC.h"


rc RC_Data;


uint16 Throttle_Control=0;
int16 Pitch_Control=0,Roll_Control=0,Yaw_Control=0;
int16 Target_Angle[2]={0};
uint16_t Controler_State=0,Last_Controler_State=0;
int16_t Auto_ReLock_Cnt=0;//�Զ�����������
uint8_t Auto_Relock_Flag=0;
uint8_t RC_Return_Flag=0;
uint16_t Unlock_Makesure_Cnt=0,Lock_Makesure_Cnt=0;
uint16_t Unwanted_Lock_Flag=0;
uint16_t Forced_Lock_Makesure_Cnt=0;
int16_t TRPY[4]={0};

uint16_t RC_Buttom=1000,RC_Top=2000,RC_Middle=1500,RC_Deadband=100;
uint16_t RC_Deadzone_Buttom=0,RC_Deadzone_Top=0;
Butter_BufferData RC_LPF_Buf[8];
uint16_t PPM_LPF_Databuf[4];

int16_t constrain_int16_t(int16_t amt, int16_t low, int16_t high){
  return ((amt)<(low)?(low):((amt)>(high)?(high):(amt)));
}

/***********************************************************
@��������RC_Data_LPF_Filter
@��ڲ�������
@���ڲ�������
����������ң����ԭʼ�����˲�
@���ߣ�WUST
@���ڣ�2019��01��27��
*************************************************************/
void RC_Data_LPF_Filter()
{
  uint16_t i=0;
  for(i=0;i<8;i++)//��ң����ǰ�ĸ�ͨ���˲�����
  {
    PPM_LPF_Databuf[i]=(uint16_t)(LPButterworth(PPM_Databuf[i],&RC_LPF_Buf[i],&Butter_5HZ_Parameter_RC));
  }
}


/***********************************************************
@��������RC_Scale_Set
@��ڲ�����Vector_RC *rc_date
@���ڲ�������
����������ң����ͨ���г̻�ȡ
@���ߣ�WUST
@���ڣ�2019��01��27��
*************************************************************/
void RC_Scale_Set(Vector_RC *rc_date)
{
  RC_Buttom=(uint16_t)(rc_date->min);
  RC_Top=(uint16_t)(rc_date->max);
  RC_Middle=(uint16_t)(rc_date->middle);
  RC_Deadband=(uint16_t)(rc_date->deadband);
  RC_Deadzone_Buttom=RC_Middle-RC_Deadband/2;
  RC_Deadzone_Top=RC_Middle+RC_Deadband/2;
}


void Reset_Lock_Cnt(void)
{
	Unlock_Makesure_Cnt=0;
	Lock_Makesure_Cnt=0;
	Forced_Lock_Makesure_Cnt=0;
	RC_Return_Flag=0;
	Auto_Relock_Flag=0;
	Auto_ReLock_Cnt=0;
}




float Remote_Data_Remap(rc *data,uint16_t ch,float max_down,float max_up,bool reverse_flag)
{
  float value=0;
  if(data->rcdata[ch]<=data->cal[ch].middle-0.5f*data->cal[ch].deadband)
  value=(data->cal[ch].middle-0.5f*data->cal[ch].deadband-data->rcdata[ch])*max_down
												  /data->cal[ch].scale;
	else if(data->rcdata[ch]>=data->cal[ch].middle+0.5f*data->cal[ch].deadband)
  value=(data->cal[ch].middle+0.5f*data->cal[ch].deadband-data->rcdata[ch])*max_up
												  /data->cal[ch].scale;	
  else value=0;
	
	if(reverse_flag)  value*=(-1);
  return 	value;
}



/***********************************************************
@��������Remote_Control
@��ڲ�������
@���ڲ�������
����������ң��������ת��
@���ߣ�WUST
@���ڣ�2019��01��27��
*************************************************************/
void Remote_Control(void )
{
	if(ppm_update_flag==1||rc_update_flag==1)
	{
		  ppm_update_flag=0;
		  rc_update_flag=0;
		  RC_Data_LPF_Filter();
		
			memcpy(RC_Data.rcdata,PPM_LPF_Databuf,8*sizeof(uint16_t));//����ÿ��ͨ��ң��������
			RC_Data.rc_rpyt[RC_ROLL]	=Remote_Data_Remap(&RC_Data ,RC_ROLL_CHANNEL	,Pit_Rol_Max,Pit_Rol_Max,true);
			RC_Data.rc_rpyt[RC_PITCH] =Remote_Data_Remap(&RC_Data ,RC_PITCH_CHANNEL ,Pit_Rol_Max,Pit_Rol_Max,true);
			RC_Data.rc_rpyt[RC_YAW]		=Remote_Data_Remap(&RC_Data ,RC_YAW_CHANNEL	  ,Yaw_Max		,Yaw_Max    ,false);
			RC_Data.rc_rpyt[RC_THR]		=Remote_Data_Remap(&RC_Data ,RC_THR_CHANNEL	  ,Climb_Down_Speed_Max,Climb_Up_Speed_Max,true);

		
			RC_Scale_Set(&RC_Data.cal[0]);
			if(PPM_Databuf[0]<=RC_Deadzone_Buttom)  Roll_Control=(RC_Deadzone_Buttom-PPM_LPF_Databuf[0])*Pit_Rol_Max/(RC_Deadzone_Buttom-RC_Buttom);//����г̿�����+-45
			else if(PPM_Databuf[0]>=RC_Deadzone_Top)  Roll_Control=(RC_Deadzone_Top-PPM_LPF_Databuf[0])*Pit_Rol_Max/(RC_Top-RC_Deadzone_Top);
			else Roll_Control=0;
			Roll_Control=constrain_int16_t(Roll_Control,-Pit_Rol_Max,Pit_Rol_Max);
			
			RC_Scale_Set(&RC_Data.cal[1]);
			if(PPM_Databuf[1]<=RC_Deadzone_Buttom)  Pitch_Control=(RC_Deadzone_Buttom-PPM_LPF_Databuf[1])*Pit_Rol_Max/(RC_Deadzone_Buttom-RC_Buttom);//����г̿�����+-45
			else if(PPM_Databuf[1]>=RC_Deadzone_Top)  Pitch_Control=(RC_Deadzone_Top-PPM_LPF_Databuf[1])*Pit_Rol_Max/(RC_Top-RC_Deadzone_Top);
			else Pitch_Control=0;
			Pitch_Control=constrain_int16_t(Pitch_Control,-Pit_Rol_Max,Pit_Rol_Max);
			

		  int16_t _thr=0;
			RC_Scale_Set(&RC_Data.cal[2]);
			_thr=1000*(PPM_LPF_Databuf[2]-RC_Buttom)/(RC_Top-RC_Buttom);//Ϊ�˰�ȫ�����Ÿ˵�λ����ΪButtom_Safe_Deadband
			Throttle_Control=constrain_int16_t(_thr,0,1000);
			
			
			
			RC_Scale_Set(&RC_Data.cal[3]);
			if(PPM_Databuf[3]<=RC_Deadzone_Buttom)  Yaw_Control=-(PPM_LPF_Databuf[3]-RC_Deadzone_Buttom)*Yaw_Max/(RC_Deadzone_Buttom-RC_Buttom);//ƫ������г̿�����+-150
			else if(PPM_Databuf[3]>=RC_Deadzone_Top)  Yaw_Control=-(PPM_LPF_Databuf[3]-RC_Deadzone_Top)*Yaw_Max/(RC_Top-RC_Deadzone_Top);
			else Yaw_Control=0;
			Yaw_Control=constrain_int16_t(Yaw_Control,-Yaw_Max,Yaw_Max);
			TRPY[3]=Yaw_Control;
			
			/***********ң�����޸�PIDӳ��**********/
			if(Page_Number==13)
			{
				    if(Pitch_Control||Roll_Control)
							PID_count++;
					if(Pitch_Control!=0&&PID_count==20)
					{
							float add;
							add=(float)0.001*(float)Pitch_Control;
							Total_Controller.High_Acce_Control.Kp+=add;	
						  PID_count=0;
					}
					if(Roll_Control>=10&&Roll_Control<=-10&&PID_count==20)
					{
							float add;
						if(Roll_Control>=10)
							add=(float)0.001*(float)(Roll_Control-10);
						else
							add=(float)0.001*(float)(Roll_Control+10);
							Total_Controller.High_Acce_Control.Ki+=add;	
						PID_count=0;
					}
			}
					
			TRPY[0]=Throttle_Control;//ң������ԭʼ�г���
			Throttle_Control=1000+Throttle_Control;			
			
			
			/***************************************************************
			��������ʱ��ң�����������������ҡ�˴��ڵ�λ�����ڲ���
			��������ʱ��ң�����������������ҡ�˴��ڵ�λ���������
			***************************************************************/
			if(Throttle_Control<=(1000+Buttom_Safe_Deadband)
				 &&Yaw_Control>=Yaw_Max*Scale_Pecent_Max
				 &&Roll_Control==0
				 &&Pitch_Control==0)
			{
				Lock_Makesure_Cnt++;
				if(Forced_Lock_Makesure_Cnt<2000) Forced_Lock_Makesure_Cnt++;
			}
			else
			{
			  Lock_Makesure_Cnt/=2;
			  Forced_Lock_Makesure_Cnt/=2;
			}
			
			if(Throttle_Control<=(1000+Buttom_Safe_Deadband)
				 &&Yaw_Control<=-Yaw_Max*Scale_Pecent_Max
					 &&Roll_Control==0
						 &&Pitch_Control==0)
				Unlock_Makesure_Cnt++;
			else Unlock_Makesure_Cnt/=2;	

      Last_Controler_State=Controler_State;
//���������ж�  			
			if((Throttle_Control<=(1000+Buttom_Safe_Deadband)
				 &&Yaw_Control>=Yaw_Max*Scale_Pecent_Max
					 &&Roll_Control==0
						 &&Pitch_Control==0
							 &&(Lock_Makesure_Cnt>50//����2.0S   //*************************
									||Forced_Lock_Makesure_Cnt>=50*5))
									||unlock_flag==0)//����
			{
				Controler_State=Lock_Controler;
				Unwanted_Lock_Flag=0;
				Reset_Lock_Cnt();
				Bling_Set(&Light_1,3000,200,0.5,0,GPIO_PORT_P5,GPIO_PIN6,0);
				Bling_Mode=0;
				Page_Number=0;//OLED�ָ���ҳ
				Reset_All_Calibartion();
			}
//���������ж�						
			if((Throttle_Control<=(1000+Buttom_Safe_Deadband)
				 &&Yaw_Control<=-Yaw_Max*Scale_Pecent_Max
					 &&Roll_Control==0
						 &&Pitch_Control==0
							 &&Unlock_Makesure_Cnt>50*2.0//����2.0S
								 &&Gyro_Safety_Calibration_Flag==1
									&&Check_Calibration_Flag()==0x00)
									||unlock_flag==1)//����
			{
				Controler_State=Unlock_Controler;
				if(Controler_High_Mode==2)//������ڶ���ģʽ�½��� 
				{  
					 Unwanted_Lock_Flag=1;   //����Ҫ�Զ���������ģʽ
		#if    (YAW_Pos_Control_Accel_Disable==1)
					Total_Controller.High_Speed_Control.Integrate=-Total_Controller.High_Speed_Control.Integrate_Max;
		#else
					Total_Controller.High_Acce_Control.Integrate=-Total_Controller.High_Acce_Control.Integrate_Max;
		#endif
				}
				else Unwanted_Lock_Flag=0;
				Reset_Lock_Cnt();
				Bling_Set(&Light_1,3000,1000,0.5,0,GPIO_PORT_P5,GPIO_PIN6,0);
				Bling_Mode=0;
//				Page_Number=0;//OLED�ָ���ҳ
				Reset_All_Calibartion();
				Auto_ReLock_Cnt=50*6;//����6S
			}
					
			//�ɿ��Զ������ж�			
			if(Controler_State==Unlock_Controler
				 &&Last_Controler_State==Lock_Controler
				 &&Unwanted_Lock_Flag==0)
			{
				Auto_Relock_Flag=1;//�����Զ�������־λ
				Auto_ReLock_Cnt=300;//���ý������κβ�����6����Զ�����
			}
			
			if(Auto_Relock_Flag==1)//�������Զ������߼��ж�
			{
				if(Throttle_Control<=(1000+Buttom_Safe_Deadband)
					 &&Pitch_Control==0
					 &&Roll_Control==0
					 &&Yaw_Control==0)//������ң�л���
					{  
						if(Auto_ReLock_Cnt>0) Auto_ReLock_Cnt--;
					  if(Auto_ReLock_Cnt==0)
						{
							Controler_State=Lock_Controler;//�ٴ�����
							Reset_Lock_Cnt();
							Bling_Set(&Light_1,3000,200,0.5,0,GPIO_PORT_P5,GPIO_PIN6,0);
							Bling_Mode=0;
						}
						RC_Return_Flag=1;//���ж�����־λ
					}
					
					if((Throttle_Control>(1000+Buttom_Safe_Deadband)
							||ABS(Pitch_Control)>=0.1f*Pit_Rol_Max
								||ABS(Roll_Control)>=0.1f*Pit_Rol_Max
									||ABS(Yaw_Control)>=0.5f*Yaw_Max)
									&&Auto_ReLock_Cnt>0//�Զ�����������
					        &&RC_Return_Flag==1)
					{
						Auto_Relock_Flag=0;//ֻҪң���ж��������ν������Զ������Ͳ�����
						Auto_ReLock_Cnt=0;
						Bling_Set(&Light_1,3000,1000,0.5,0,GPIO_PORT_P5,GPIO_PIN6,0);
						Bling_Mode=0;
					}				
			}
	}	
	
	if(shutdown_now_cal_flag==1)
	{
		Reset_All_Calibartion();
		shutdown_now_cal_flag=0;
		Bling_Set(&Light_1,0,1000,0.3,0,GPIO_PORT_P5,GPIO_PIN6,0);
		Page_Number=0;//OLED�ָ���ҳ
	}
}

/* Copyright (c)  2018-2025 Wuhan Nameless Innovation Technology Co.,Ltd. All rights reserved.*/

