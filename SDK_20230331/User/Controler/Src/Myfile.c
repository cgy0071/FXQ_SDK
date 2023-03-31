#include "Headfile.h"
#include "Myfile.h"

/*********myflag*********/
uint8_t Flag1 = 0;
uint8_t Flag2 = 0;
uint8_t Flag3 = 0;

float Value1 = 0;
float Value2 = 0;
float Value3 = 0;

uint16_t PID_count=0;


//��ʼ����openmv��־
uint8_t SDK_Ground_updata=0;
uint8_t SDK_Front_updata=0;
uint8_t Ground_OPENMV_mode=0;
uint8_t Front_OPENMV_mode=0;
/***********************************************************
@��������SDK_OPENMV_Config
@��ڲ�����uint8_t *updata�����±�־����
@���ڲ�������
@����������OPENMV��ģʽ����
@���ߣ�PJC
@���ڣ�2021��10��29��
*************************************************************/
void SDK_OPENMV_Config(uint8_t *updata,uint8_t mode,COM_SDK com)
{
	if(*updata==1)
	{
     SDK_DT_Send_Check(mode,com);
		  *updata=0;
	}		
}

/*****************
     ���ƺ���
********************/


//��45��Ϊ����ƫ����λ
float control_yaw_delta_max(float delta_yaw_target,float delta_max)
{
	 int_least16_t Polarity;
	 uint8_t overflow_flag=0;
	
		//delta_yaw_targetΪ��������ʱ��ת��
		//delta_yaw_targetΪ������˳ʱ��ת��
	if(delta_yaw_target>0)
		Polarity=1;//��
	else
		Polarity=-1;//˳

		if(ABS(delta_yaw_target)>delta_max)//���,��������Ϊdelta_max
		{
			Total_Controller.Yaw_Angle_Control.Expect+=(delta_max*Polarity);
			overflow_flag=1;
		}
		else
			Total_Controller.Yaw_Angle_Control.Expect+=delta_yaw_target;
			
		//���ڻ�ƫ���Ƕ�
		if(Total_Controller.Yaw_Angle_Control.Expect>=360)
			Total_Controller.Yaw_Angle_Control.Expect-=360;
		if(Total_Controller.Yaw_Angle_Control.Expect<=0)
			Total_Controller.Yaw_Angle_Control.Expect+=360;
		
		if(Total_Controller.Yaw_Angle_Control.Expect==0&&Total_Controller.Yaw_Angle_Control.Expect==360)
			Total_Controller.Yaw_Angle_Control.Expect+=(float)0.05;
	
		if(overflow_flag==1)  //�����������ͷ������ֵ
		{
				if(Polarity==1)   //���ľͼ�
				{
					delta_yaw_target-=delta_max;
					return delta_yaw_target;
				}
				if(Polarity==-1)   //���ľͼ�
				{
					delta_yaw_target+=delta_max;
					return delta_yaw_target;
				}	
		}
		else
				 return 0; //û��������ͷ���0
		return 0;
}

uint8_t control_yaw_delta(float delta_yaw_target)
{
		float overflow_yaw=0;
	  static float set_yaw_flag=1;
	 
	  if(set_yaw_flag)//���ÿ���ƫ����
		{
		overflow_yaw=control_yaw_delta_max(delta_yaw_target,45);
		set_yaw_flag=0;
		}
		//������õ�ƫ����
		if(ABS(Total_Controller.Yaw_Angle_Control.Expect-Yaw)<=5)
		{
			if(overflow_yaw!=0)//�������������Ҫ��������
				{
					set_yaw_flag=1;
					return 0;
				}
				else           //�������������Ҫ��������
					return 1;
		}
		return 0;
}

uint8_t control_yaw(float delta_yaw_target,float yaw_vel,float delta,SDK_Status *Status,uint16_t number)
{

		static uint8_t end_flag=0;	
	
		static float end_time=0;
	  Testime dt;
		Test_Period(&dt);
	
		ncq_control_althold();//�߶ȿ�����Ȼ����
		OpticalFlow_Control_Pure(0);//���֮�󣬽��й�����ͣ
	  if(Status->Status[number].Start_Flag==1
     &&Status->Status[number].Execute_Flag==1
					 &&Status->Status[number].End_flag==1)
		{									
			return 1;
		}
		else
		{		//��ʼ��ֻ����һ��
				if(Status->Status[number].Start_Flag==0) 
				{					
					if(delta_yaw_target==0)//�ٶȿ��ƣ�һ��������ֻ����һ��
					{
						end_flag=1;
					}
					else//�Ƕȿ���
					{
	
					
						end_flag=2;
					}				
						end_time=dt.Now_Time+delta;//��λms 
						Status->Status[number].Start_Flag=1;				
					
				}

				if(end_flag==1)//���ٶȿ���
				{  
					if(dt.Now_Time>end_time)//��������
					{ 
						end_flag=0;
						end_time=0;
						Status->Status[number].Execute_Flag=1;
						Status->Status[number].End_flag=1;
						Status->Transition_Time[number]=2000;//200*5=1��
						return 1;//�������
					}
					Status->Status[number].Execute_Flag=1;
				}
				else if(end_flag==2) //�Ƕȿ���
				{
						if(ABS(Total_Controller.Yaw_Angle_Control.Expect-Yaw)<=5)
						{
							Status->Status[number].Execute_Flag=1;
							Status->Status[number].End_flag=1;
							Status->Transition_Time[number]=2000;//1000*5ms			
							
							return 1;//�������					
						}
						Status->Status[number].Execute_Flag=1;									
				}						
		}
		return 0;		
}

uint8_t control_yaw_rotate(float delta_yaw_target,SDK_Status *Status,uint16_t number)
{

		ncq_control_althold();//�߶ȿ�����Ȼ����
		OpticalFlow_Control_Pure(0);//���֮�󣬽��й�����ͣ
	  if(Status->Status[number].Start_Flag==1
     &&Status->Status[number].Execute_Flag==1
					 &&Status->Status[number].End_flag==1)
		{									
			return 1;
		}
		else
		{		
				if(Status->Status[number].Start_Flag==0) 
				{
					//delta_yaw_targetΪ��������ʱ��ת��
					//delta_yaw_targetΪ������˳ʱ��ת��
					Total_Controller.Yaw_Angle_Control.Expect+=delta_yaw_target;
					//���ڻ�ƫ���Ƕ�
					if(Total_Controller.Yaw_Angle_Control.Expect>=360)
						Total_Controller.Yaw_Angle_Control.Expect-=360;
					if(Total_Controller.Yaw_Angle_Control.Expect<=0)
						Total_Controller.Yaw_Angle_Control.Expect+=360;
					if(Total_Controller.Yaw_Angle_Control.Expect==0&&Total_Controller.Yaw_Angle_Control.Expect==360)
						Total_Controller.Yaw_Angle_Control.Expect+=(float)0.05;		
					
					Status->Status[number].Start_Flag=1;
				}
				
				if(ABS(Total_Controller.Yaw_Angle_Control.Expect-Yaw)<=5)
				{
					Status->Status[number].Execute_Flag=1;
					Status->Status[number].End_flag=1;
					Status->Transition_Time[number]=2000;//1000*5ms			
					
					return 1;//�������					
				}
				else
				{
				Status->Status[number].Execute_Flag=1;				
					return 0;
				}							
		}
				
}

