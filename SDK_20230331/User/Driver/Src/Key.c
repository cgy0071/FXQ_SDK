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
#include "Key.h"
/***********************************************************
@��������Key_Init
@��ڲ�������
@���ڲ�������
����������������ʼ��
@���ߣ�WUST
@���ڣ�2019��01��27��
*************************************************************/



rc_buttton _button;
void Key_Init(void)
{
  MAP_GPIO_setAsInputPinWithPullUpResistor(GPIO_PORT_P1, GPIO_PIN1);
	MAP_GPIO_setAsInputPinWithPullUpResistor(GPIO_PORT_P1, GPIO_PIN4);
	
	_button.state[UP].port=GPIO_PORT_P1;
	_button.state[UP].pin=GPIO_PIN1;
	_button.state[UP].value=1;
	_button.state[UP].last_value=1;

	_button.state[DOWN].port=GPIO_PORT_P1;
	_button.state[DOWN].pin=GPIO_PIN4;
	_button.state[DOWN].value=1;
	_button.state[DOWN].last_value=1;	
}


void Read_Button_State_One(button_state *button)
{
  button->value=MAP_GPIO_getInputPinValue(button->port,button->pin);
	if(button->value==0)
	{
		if(button->last_value==1)//�״ΰ���
		{
			button->press_time=millis();//��¼���µ�ʱ���
			button->in_time=millis();//��¼���µ�ʱ���
			button->in_press_cnt=0;
		}
		else
		{
			if(millis()-button->in_time>IN_PRESS_LIMIT)//��������
			{
				button->in_time=millis();
				button->press=IN_PRESS;
				//rc_beep.time=1;
				//Bling_Set(&Light_3,200,50,0.1,0,GPIO_PORT_PJ,GPIO_PIN5,0);//��ɫ
				if(button->press==IN_PRESS)  button->in_press_cnt++;
			}
		}
	}
  else
	{
		if(button->last_value==0)//���º��ͷ�
		{
			button->release_time=millis();//��¼�ͷ�ʱ��ʱ��
			
			if(button->release_time-button->press_time>LONG_PRESS_LIMIT)
			{
			   button->press=LONG_PRESS;
				 button->state_lock_time=0;//5ms*300=1.5S
				 //rc_beep.time=50;
				//Bling_Set(&Light_3,500,100,0.5,0,GPIO_PORT_PJ,GPIO_PIN5,0);//��ɫ
			}
			else
			{
			   button->press=SHORT_PRESS;
				 button->state_lock_time=0;//5ms*300=1.5S
				 //rc_beep.time=10;
				//Bling_Set(&Light_3,200,100,0.5,0,GPIO_PORT_PJ,GPIO_PIN5,0);//��ɫ
			}
		}
	}
	button->last_value=button->value;
	
	
	if(button->press==LONG_PRESS
	 ||button->press==SHORT_PRESS)//�����ͷź󣬳����̨1.5S������Ӧ����λ����״̬
	{
	  button->state_lock_time++;
		if(button->state_lock_time>=300)
		{			
			 button->press=NO_PRESS;
			 button->state_lock_time=0;
		}
	}
}


void Read_Button_State_All(void)
{
  for(uint16_t i=0;i<BUTTON_NUM;i++)
	{
	  Read_Button_State_One(&_button.state[i]);
	}
}



void key_delay(int32_t period)
{
  while(period--)
  {
    delay_us(1);  
  }
}

#define LONG_PRESS_MAX  2000
int16_t Page_Number=0;
uint8_t Key_Right_Release=0;
uint8_t Oled_Show_Enable=1;
/***********************************************************
@��������Key_Scan
@��ڲ�����release
@���ڲ�����bool
��������������ɨ�裬��ڲ���release�����Ƿ񿪷Ű���ɨ��Ȩ��
����ɨ�践��TRUE����������ʱΪ�͵�ƽ���ͷź�IO���õ�������
����ģʽ������Ϊ�ߵ�ƽ
@���ߣ�WUST
@���ڣ�2019��01��27��
*************************************************************/
bool Key_Scan(uint8_t release)
{
  uint16_t long_press_cnt=0;
  if(release==1)  return false;	
	if(_button.state[UP].press==SHORT_PRESS)
	{
		Page_Number--;
		if(Page_Number<0) Page_Number=13;
		_button.state[UP].press=NO_PRESS;
		LCD_CLS();
	}

	if(_button.state[DOWN].press==SHORT_PRESS)
	{
		Page_Number++;
		if(Page_Number>13) Page_Number=0;
		_button.state[DOWN].press=NO_PRESS;
		LCD_CLS();
	}
	

		if(Controler_State==Lock_Controler
		  &&Throttle_Control<=(1000+Buttom_Safe_Deadband)
		  &&Yaw_Control>=Yaw_Max*Scale_Pecent_Max
			&&Roll_Control<-Pit_Rol_Max*Scale_Pecent_Max&&Pitch_Control==0)
		{
			while(Controler_State==Lock_Controler
					&&Throttle_Control<=(1000+Buttom_Safe_Deadband)
					&&Yaw_Control>=Yaw_Max*Scale_Pecent_Max
					&&Roll_Control<-Pit_Rol_Max*Scale_Pecent_Max&&Pitch_Control==0)
			{
				long_press_cnt++;
				key_delay(10);
				if(long_press_cnt>=LONG_PRESS_MAX)
				{
					Page_Number++;
					if(Page_Number>13) Page_Number=0;
					LCD_CLS();
					return true;
				}
			}
		}

		
		if(Controler_State==Lock_Controler
		  &&Throttle_Control<=(1000+Buttom_Safe_Deadband)
			&&Yaw_Control>=Yaw_Max*Scale_Pecent_Max
		  &&Roll_Control>Pit_Rol_Max*Scale_Pecent_Max&&Pitch_Control==0)
		{
			while(Controler_State==Lock_Controler
					&&Throttle_Control<=(1000+Buttom_Safe_Deadband)
					&&Yaw_Control>=Yaw_Max*Scale_Pecent_Max
					&&Roll_Control>Pit_Rol_Max*Scale_Pecent_Max&&Pitch_Control==0) 
			{
				long_press_cnt++;
				key_delay(10);
				if(long_press_cnt>=LONG_PRESS_MAX)
				{
					Page_Number--;
					if(Page_Number<0) Page_Number=13;
					LCD_CLS();
					return true;
				}
			}
		}
  return TRUE;	
}





/***********************************************************
@��������QuadShow
@��ڲ�������
@���ڲ�������
������������ʾ��ˢ�£�ÿһҳÿһ�����ݽ��ʹ��˵�������ۿ���
��������ҳ���ϰ���ɨ����ʵ��
@���ߣ�����С��
@���ڣ�2019��01��27��
*************************************************************/
int chioce=1;
void QuadShow(uint8_t show_enable)
{
  uint16_t i=0;
	
	if(show_enable==1)
	{


		
		if(Roll_Control>=20)
		{chioce=chioce+1;}
		else if(Roll_Control<-20)
		{chioce=chioce-1;}
		
		if(chioce>4) {chioce=1;}
		else if(chioce<1) {chioce=4;}
		
 
		
		if(Page_Number==-1)	//ң��������pid����
	{
				LCD_clear_L(0,chioce);  LCD_P6x8Str(80,chioce,"<---");  
	if(Pitch_Control>=25)
	{
		if(chioce==1) {Total_Controller.High_Acce_Control.Kp+=0.1;	}
		if(chioce==2) {Total_Controller.High_Acce_Control.Ki+=0.1;	}
		if(chioce==3) {Total_Controller.High_Acce_Control.Kd+=0.02;	}
		if(chioce==4) {Total_Controller.Roll_Gyro_Control.Kp+=1;	}
		LCD_CLS();
	}
	else if(Pitch_Control>=5&&Pitch_Control<20)
			{
		if(chioce==1) {Total_Controller.High_Acce_Control.Kp+=0.1;	}
		if(chioce==2) {Total_Controller.High_Acce_Control.Ki+=0.1;	}
		if(chioce==3) {Total_Controller.High_Acce_Control.Kd+=0.02;	}
		if(chioce==4) {Total_Controller.Roll_Gyro_Control.Kp+=1;	}
		LCD_CLS();
	}
	else if(Pitch_Control<-25)
			{
		if(chioce==1) {Total_Controller.High_Acce_Control.Kp-=0.1;	}
		if(chioce==2) {Total_Controller.High_Acce_Control.Ki-=0.1;	}
		if(chioce==3) {Total_Controller.High_Acce_Control.Kd-=0.02;	}
		if(chioce==4) {Total_Controller.Roll_Gyro_Control.Kp-=1;	}
		LCD_CLS();
	}
	else if(Pitch_Control<=-5&&Pitch_Control>=-20)
			{
		if(chioce==1) {Total_Controller.High_Acce_Control.Kp-=0.1;	}
		if(chioce==2) {Total_Controller.High_Acce_Control.Ki-=0.1;	}
		if(chioce==3) {Total_Controller.High_Acce_Control.Kd-=0.02;	}
		if(chioce==4) {Total_Controller.Roll_Gyro_Control.Kp-=1;	}
		LCD_CLS();
	}
			
	
	  LCD_clear_L(0,1);  LCD_P6x8Str(0,1,"Kp:");            					write_6_8_number(40,1,Total_Controller.High_Acce_Control.Kp);  
		LCD_clear_L(0,2);  LCD_P6x8Str(0,2,"Ki:");          					write_6_8_number(40,2,Total_Controller.High_Acce_Control.Ki);                                    
		LCD_clear_L(0,3);  LCD_P6x8Str(0,3,"Kd:");           					write_6_8_number(40,3,Total_Controller.High_Acce_Control.Kd);  
		LCD_clear_L(0,4);  LCD_P6x8Str(0,4,"Kd_a:");           					write_6_8_number(40,4,Total_Controller.Roll_Gyro_Control.Kp);  
		LCD_clear_L(0,5);  LCD_P6x8Str(0,5,"Pitch_Control:");           					write_6_8_number(80,5,Pitch_Control);  
		LCD_clear_L(0,6);  LCD_P6x8Str(0,6,"Roll_Control:");           					write_6_8_number(80,6,Roll_Control);  
	}
	
	
		else if(Page_Number==0)
		{
			LCD_clear_L(0,0);  write_6_8_number(0,0,extern_remain_time/100);    
												 write_6_8_number(40,0,Time0_Delta.Time_Delta);
												 write_6_8_number(70,0,Page_Number+1);
												 write_6_8_number(90,0,Battery_Voltage);
			LCD_clear_L(0,1);  LCD_P6x8Str(0,1,"Yaw:");            					write_6_8_number(40,1,Yaw);                                          write_6_8_number(90,1,Yaw_Gyro);
			LCD_clear_L(0,2);  LCD_P6x8Str(0,2,"Pitch:");          					write_6_8_number(40,2,Pitch);                                        write_6_8_number(90,2,Pitch_Gyro);
			LCD_clear_L(0,3);  LCD_P6x8Str(0,3,"Roll:");           					write_6_8_number(40,3,Roll);                            					    write_6_8_number(90,3,Roll_Gyro);
			LCD_clear_L(0,4);  LCD_P6x8Str(0,4,"DUTY:");           					write_6_8_number(45,4,(uint32_t)(SDK_Duty_Cnt));    
			if(ready_flag)	LCD_P6x8Str(80,4,"ready!!!");
			LCD_clear_L(0,5);  LCD_P6x8Str(0,5,"US100:");          					write_6_8_number(40,5,Ground_Distance);               			          write_6_8_number(80,5,NamelessQuad.Position[_YAW]);
			LCD_clear_L(0,6);  LCD_P6x8Str(0,6,"VL53:");           					write_6_8_number(40,6,vl53l1x_in1.distance);                    		  write_6_8_number(80,6,NamelessQuad.Speed[_YAW]);
			LCD_clear_L(0,7);  																		 					write_6_8_number(0,7,SDK1_Mode_Setup);
																																			write_6_8_number(20,7,Gyro_Safety_Calibration_Flag);  
																																			write_6_8_number(30,7,WP_Sensor.temperature);          
																																			write_6_8_number(75,7,NamelessQuad.Origion_Acceleration[_YAW]);
				if(_button.state[DOWN].press==LONG_PRESS)
	{
		Page_Number=-1;
		_button.state[DOWN].press=NO_PRESS;
		LCD_CLS();
	}
	else if(_button.state[UP].press==LONG_PRESS)
			{
		Page_Number=0;
		_button.state[DOWN].press=NO_PRESS;
		LCD_CLS();
	}
			


	
	}
	
		
	
		
		else  if(Page_Number==1)
		{
			LCD_clear_L(0,0);  LCD_P6x8Str(0,0,"Accel:");write_6_8_number(100,0,Page_Number+1);
			if(Accel_Simple_Mode==0)  LCD_P6x8Str(50,0,"6-Side");
			else LCD_P6x8Str(50,0,"Simple");
			
			if(Pitch_Control>=Scale_Pecent_Max*Pit_Rol_Max)
			{
				delay_ms(10);
				if(Pitch_Control>=Scale_Pecent_Max*Pit_Rol_Max)
				{
					while(Pitch_Control>=Scale_Pecent_Max*Pit_Rol_Max);
					if(Accel_Simple_Mode==0) Accel_Simple_Mode=1;
					else if(Accel_Simple_Mode==1) Accel_Simple_Mode=0;
					WriteFlashParameter(ACCEL_SIMPLE_MODE,Accel_Simple_Mode,&Table_Parameter);
					Bling_Set(&Light_3,1000,200,0.5,0,GPIO_PORT_PJ,GPIO_PIN5,0);
				}
			}
			
			if(_button.state[DOWN].press==LONG_PRESS)
			{
					_button.state[DOWN].press=NO_PRESS;
					if(Accel_Simple_Mode==0) Accel_Simple_Mode=1;
					else if(Accel_Simple_Mode==1) Accel_Simple_Mode=0;
					WriteFlashParameter(ACCEL_SIMPLE_MODE,Accel_Simple_Mode,&Table_Parameter);
					Bling_Set(&Light_3,1000,200,0.5,0,GPIO_PORT_PJ,GPIO_PIN5,0);				
			}		
			
			LCD_clear_L(0,1);  LCD_P6x8Str(0,1,"X:");              write_6_8_number(15,1,K[0]);   write_6_8_number(55,1,B[0]);   write_6_8_number(95,1,Accel_Hor_Read.x);
			LCD_clear_L(0,2);  LCD_P6x8Str(0,2,"Y:");              write_6_8_number(15,2,K[1]);   write_6_8_number(55,2,B[1]);   write_6_8_number(95,2,Accel_Hor_Read.y);
			LCD_clear_L(0,3);  LCD_P6x8Str(0,3,"Z:");              write_6_8_number(15,3,K[2]);   write_6_8_number(55,3,B[2]);   write_6_8_number(95,3,Accel_Hor_Read.z);
			LCD_clear_L(0,4);  LCD_P6x8Str(0,4,"Mag /T:");    		 write_6_8_number(40,4,WP_Sensor.mag_intensity);
																														 LCD_P6x8Str(80,4,"P/R_Off:");
			//LCD_clear_L(0,5);  LCD_P6x8Str(0,5,"MX_OFF:");         write_6_8_number(40,5,Mag_Offset_Read.x);  write_6_8_number(80,5,Pitch_Offset);
			//LCD_clear_L(0,6);  LCD_P6x8Str(0,6,"MY_OFF:");         write_6_8_number(40,6,Mag_Offset_Read.y);  write_6_8_number(80,6,Roll_Offset);
			//LCD_clear_L(0,7);  LCD_P6x8Str(0,7,"MZ_OFF:");         write_6_8_number(40,7,Mag_Offset_Read.z);
			LCD_clear_L(0,5);  LCD_P6x8Str(0,5,"COOR1");           		write_6_8_number(40,5,zuobiao1_x);                                           write_6_8_number(80,5,zuobiao1_y);
			LCD_clear_L(0,6);  LCD_P6x8Str(0,6,"COOR2");          					write_6_8_number(40,6,zuobiao2_x);               			          write_6_8_number(80,6,zuobiao2_y);
			LCD_clear_L(0,7);  LCD_P6x8Str(0,7,"CNT");           					write_6_8_number(40,7,cnt);
		}
		else  if(Page_Number==2)
		{
			LCD_clear_L(0,0);  LCD_P6x8Str(0,0,"RC Data");         write_6_8_number(90,0,Page_Number+1);
			LCD_clear_L(0,1);  LCD_P6x8Str(0,1,"Yaw:");            write_6_8_number(40,1,Yaw_Control);                     write_6_8_number(90,1,PPM_Databuf[3]);
			LCD_clear_L(0,2);  LCD_P6x8Str(0,2,"Pitch:");          write_6_8_number(40,2,Pitch_Control);                   write_6_8_number(90,2,PPM_Databuf[1]);
			LCD_clear_L(0,3);  LCD_P6x8Str(0,3,"Roll:");           write_6_8_number(40,3,Roll_Control);                    write_6_8_number(90,3,PPM_Databuf[0]);
			LCD_clear_L(0,4);  LCD_P6x8Str(0,4,"Thr:");            write_6_8_number(40,4,Throttle_Control);                write_6_8_number(90,4,PPM_Databuf[2]);
			LCD_clear_L(0,5);  LCD_P6x8Str(0,5,"ch5-6:");          write_6_8_number(40,5,PPM_Databuf[4]);                  write_6_8_number(90,5,PPM_Databuf[5]);
			LCD_clear_L(0,6);  LCD_P6x8Str(0,6,"ch7-8:");          write_6_8_number(40,6,PPM_Databuf[6]);                  write_6_8_number(90,6,PPM_Databuf[7]);
			
			LCD_clear_L(0,7);  LCD_P6x8Str(0,7,"mode");             
			if(Controler_High_Mode==1)        LCD_P6x8Str(30,7,"Manual_Ctrl_Alt");
			else if(Controler_High_Mode==2&&Controler_Horizontal_Mode==1)   LCD_P6x8Str(30,7,"Auto_Ctrl_Alt");
			else if(Controler_High_Mode==2&&Controler_Horizontal_Mode==2)   LCD_P6x8Str(30,7,"Auto_Ctrl_Hover");
			else LCD_P6x8Str(30,7,"Manual_Ctrl_Alt"); 
		}
		else if(Page_Number==3)
		{   
			LCD_clear_L(0,0);  LCD_P6x8Str(0,0,"Ctrl Data P  I");  write_6_8_number(100,0,Page_Number+1);
			LCD_clear_L(0,1);  LCD_P6x8Str(0,1,"Pit_Ang:");        write_6_8_number(50,1,Total_Controller.Pitch_Angle_Control.Kp);           write_6_8_number(90,1,Total_Controller.Pitch_Angle_Control.Ki); 
			LCD_clear_L(0,2);  LCD_P6x8Str(0,2,"Rol_Ang:");        write_6_8_number(50,2,Total_Controller.Roll_Angle_Control.Kp);            write_6_8_number(90,2,Total_Controller.Roll_Angle_Control.Ki);    
			LCD_clear_L(0,3);  LCD_P6x8Str(0,3,"Yaw_Ang:");        write_6_8_number(50,3,Total_Controller.Yaw_Angle_Control.Kp);             write_6_8_number(90,3,Total_Controller.Yaw_Angle_Control.Ki);    
			LCD_clear_L(0,4);  LCD_P6x8Str(0,4,"Pit_Gyr:");        write_6_8_number(50,4,Total_Controller.Pitch_Gyro_Control.Kp);            write_6_8_number(90,4,Total_Controller.Pitch_Gyro_Control.Ki);    
			LCD_clear_L(0,5);  LCD_P6x8Str(0,5,"Rol_Gyr:");        write_6_8_number(50,5,Total_Controller.Roll_Gyro_Control.Kp);             write_6_8_number(90,5,Total_Controller.Roll_Gyro_Control.Ki);    
			LCD_clear_L(0,6);  LCD_P6x8Str(0,6,"Yaw_Gyr:");        write_6_8_number(50,6,Total_Controller.Yaw_Gyro_Control.Kp);              write_6_8_number(90,6,Total_Controller.Yaw_Gyro_Control.Ki);
			LCD_clear_L(0,7);  LCD_P6x8Str(0,7,"Gyro_D:");         write_6_8_number(40,7,Total_Controller.Pitch_Gyro_Control.Kd);            write_6_8_number(70,7,Total_Controller.Roll_Gyro_Control.Kd);                  write_6_8_number(95,7,Total_Controller.Yaw_Gyro_Control.Kd);
		}
		else if(Page_Number==4)
		{
			LCD_clear_L(0,0); LCD_clear_L(0,1);  
			LCD_P6x8Str(0,0,"UART3_SDK_Mode:");write_6_8_number(100,0,SDK1_Mode_Setup);
			
			LCD_clear_L(0,2); 
			if(SDK1_Mode_Setup==0x00)     			LCD_P6x8Str(0,2,"NCQ_SDK_Run");		//Ĭ��ģʽ
			else if(SDK1_Mode_Setup==0x01)     LCD_P6x8Str(0,2,"Color_Block");//ɫ��׷��ģʽ
			else if(SDK1_Mode_Setup==0x02)     LCD_P6x8Str(0,2,"Top_APrilTag");//AprilTag׷��ģʽ
			else if(SDK1_Mode_Setup==0x03)     LCD_P6x8Str(0,2,"Track_Control");
			else if(SDK1_Mode_Setup==0x04)     LCD_P6x8Str(0,2,"Front_AprilTag");
			else 
			{
				LCD_P6x8Str(0,2,"User SDK:");
				write_6_8_number(70,2,SDK1_Mode_Setup-3);
			}

			LCD_clear_L(0,6);LCD_P6x8Str(0,6,"Now_SDK1_Mode:");write_6_8_number(100,6,Opv_Top_View_Target.sdk_mode-0xA0);		

			
			if(Pitch_Control>=Scale_Pecent_Max*Pit_Rol_Max)
			{
				delay_ms(10);
				if(Pitch_Control>=Scale_Pecent_Max*Pit_Rol_Max)
				{
					while(Pitch_Control>=Scale_Pecent_Max*Pit_Rol_Max);
					SDK1_Mode_Setup++;
					if(SDK1_Mode_Setup>16) SDK1_Mode_Setup=0;
					SDK_DT_Send_Check(SDK1_Mode_Setup,UART3_SDK);
					WriteFlashParameter(SDK1_MODE_DEFAULT,SDK1_Mode_Setup,&Table_Parameter);
					Bling_Set(&Light_3,1000,200,0.5,0,GPIO_PORT_PJ,GPIO_PIN5,0);	
				}
			}
			
			if(_button.state[DOWN].press==LONG_PRESS)
			{
					_button.state[DOWN].press=NO_PRESS;
					SDK1_Mode_Setup++;
					if(SDK1_Mode_Setup>16) SDK1_Mode_Setup=0;
					SDK_DT_Send_Check(SDK1_Mode_Setup,UART3_SDK);
					WriteFlashParameter(SDK1_MODE_DEFAULT,SDK1_Mode_Setup,&Table_Parameter);	
					Bling_Set(&Light_3,1000,200,0.5,0,GPIO_PORT_PJ,GPIO_PIN5,0);					
			}		
			
//			if(Pitch_Control<=-Scale_Pecent_Max*Pit_Rol_Max)
//			{
//				delay_ms(10);
//				if(Pitch_Control<=-Scale_Pecent_Max*Pit_Rol_Max)
//				{
//					while(Pitch_Control<=-Scale_Pecent_Max*Pit_Rol_Max);
//					SDK1_Mode_Setup--;
//					if(SDK1_Mode_Setup<0) SDK1_Mode_Setup=16;
//					SDK_DT_Send_Check(SDK1_Mode_Setup,UART3_SDK);
//					WriteFlashParameter(SDK1_MODE_DEFAULT,SDK1_Mode_Setup,&Table_Parameter);
//				}
//			} 
		}
		else if(Page_Number==5)
		{
			LCD_clear_L(0,0); LCD_clear_L(0,1);  
			LCD_P6x8Str(0,0,"UART1_SDK_Mode:");write_6_8_number(100,0,SDK2_Mode_Setup);
			
			LCD_clear_L(0,6);LCD_P6x8Str(0,6,"Now_SDK2_Mode:");write_6_8_number(100,6,Opv_Front_View_Target.sdk_mode-0xA0);		

			
			if(Pitch_Control>=Scale_Pecent_Max*Pit_Rol_Max)
			{
				delay_ms(10);
				if(Pitch_Control>=Scale_Pecent_Max*Pit_Rol_Max)
				{
					while(Pitch_Control>=Scale_Pecent_Max*Pit_Rol_Max);
					SDK2_Mode_Setup++;
					if(SDK2_Mode_Setup>16) SDK2_Mode_Setup=0;
					SDK_DT_Send_Check(SDK2_Mode_Setup,UART1_SDK);
					WriteFlashParameter(SDK2_MODE_DEFAULT,SDK2_Mode_Setup,&Table_Parameter);
				}
			}
			
			if(_button.state[DOWN].press==LONG_PRESS)
			{
					_button.state[DOWN].press=NO_PRESS;
					SDK2_Mode_Setup++;
					if(SDK2_Mode_Setup>16) SDK2_Mode_Setup=0;
					SDK_DT_Send_Check(SDK2_Mode_Setup,UART1_SDK);
					WriteFlashParameter(SDK2_MODE_DEFAULT,SDK2_Mode_Setup,&Table_Parameter);
					Bling_Set(&Light_3,1000,200,0.5,0,GPIO_PORT_PJ,GPIO_PIN5,0);					
			}					
//			if(Pitch_Control<=-Scale_Pecent_Max*Pit_Rol_Max)
//			{
//				delay_ms(10);
//				if(Pitch_Control<=-Scale_Pecent_Max*Pit_Rol_Max)
//				{
//					while(Pitch_Control<=-Scale_Pecent_Max*Pit_Rol_Max);
//					SDK2_Mode_Setup--;
//					if(SDK2_Mode_Setup<0) SDK2_Mode_Setup=16;
//					SDK_DT_Send_Check(SDK2_Mode_Setup,UART1_SDK);
//					WriteFlashParameter(SDK2_MODE_DEFAULT,SDK2_Mode_Setup,&Table_Parameter);
//				}
//			} 
		}		
		else if(Page_Number==6)
		{
			LCD_clear_L(0,0);  LCD_P6x8Str(0,0,"Optical");  			write_6_8_number(100,0,Page_Number+1);
			LCD_clear_L(0,1);  LCD_P6x8Str(0,1,"flow_x:");        write_6_8_number(50,1,opt_origin_data.pixel_flow_x_integral);             write_6_8_number(90,1,opt_gyro_data.x); 
			LCD_clear_L(0,2);  LCD_P6x8Str(0,2,"flow_y:");        write_6_8_number(50,2,opt_origin_data.pixel_flow_y_integral);             write_6_8_number(90,2,opt_gyro_data.y);    
			LCD_clear_L(0,3);  LCD_P6x8Str(0,3,"time:");       		write_6_8_number(50,3,opt_origin_data.integration_timespan);              write_6_8_number(90,3,opt_data.dt);    
			LCD_clear_L(0,4);  LCD_P6x8Str(0,4,"qual:");      		write_6_8_number(50,4,opt_origin_data.qual);            									  
			LCD_clear_L(0,5);  LCD_P6x8Str(0,5,"gyro_x:");        write_6_8_number(50,5,opt_gyro_data.x);              
			LCD_clear_L(0,6);  LCD_P6x8Str(0,6,"gyro_y:");        write_6_8_number(50,6,opt_gyro_data.y);           
			LCD_clear_L(0,7);  LCD_P6x8Str(0,7,"opt_flow:");      write_6_8_number(40,7,opt_gyro_filter_data.x);            write_6_8_number(70,7,opt_gyro_filter_data.y);                
		}
		else if(Page_Number==7)
		{
			uint16_t x,y,x1,y1;
			ssd1306_clear_display();
			ssd1306_draw_line(32,32,96,32,WHITE);
			ssd1306_draw_line(64,0,64,64,WHITE);
			ssd1306_draw_circle(64,32,32,WHITE);
			x1=64-32*Sin_Yaw;
			y1=32-32*Cos_Yaw;
			ssd1306_draw_line(64,32,x1,y1,WHITE);
			y=32+32*constrain_float(Pitch,-90,90)/90;
			x=64+32*constrain_float(Roll,-90,90)/90;
			ssd1306_fill_circle(x,y,5,WHITE);
			ssd1306_display();
			LCD_P6x8Str(60,0,"N");
			LCD_P6x8Str(60,7,"S");
			LCD_P6x8Str(0,1,"Yaw:");            write_6_8_number(90,1,Yaw);                             
			LCD_P6x8Str(0,2,"Pitch:");          write_6_8_number(90,2,Pitch); 
			LCD_P6x8Str(0,3,"Roll:");           write_6_8_number(90,3,Roll);  
		}
		else if(Page_Number==8)
		{
			ssd1306_clear_display();
			ssd1306_draw_line(0,32,128,32,WHITE);
			ssd1306_draw_line(64,0,64,64,WHITE);			
			uint16_t x,y;
			y=32-32*constrain_float(0.5*Opv_Top_View_Target.height-Opv_Top_View_Target.y,-50,50)/50.0f;
			x=64-32*constrain_float(0.5*Opv_Top_View_Target.width-Opv_Top_View_Target.x,-50,50)/50.0f;
      if(Opv_Top_View_Target.flag==1)			ssd1306_fill_circle(x,y,5,WHITE);
			else ssd1306_draw_circle(x,y,5,WHITE);			
			
			ssd1306_display();
			LCD_P6x8Str(0,0,"point_x:");  write_6_8_number(95,0,Opv_Top_View_Target.x);
			LCD_P6x8Str(0,1,"point_y::"); write_6_8_number(95,1,Opv_Top_View_Target.y);
			LCD_P6x8Str(0,2,"point_s:");  write_6_8_number(95,2,Opv_Top_View_Target.pixel);
			LCD_P6x8Str(0,3,"point_f:");  write_6_8_number(95,3,Opv_Top_View_Target.flag);
			LCD_P6x8Str(0,4,"Tar_x:");    write_6_8_number(95,4,Opv_Top_View_Target.sdk_target.x);
			LCD_P6x8Str(0,5,"Tar_y:");    write_6_8_number(95,5,Opv_Top_View_Target.sdk_target.y); 
			LCD_P6x8Str(0,6,"FPS:");      write_6_8_number(95,6,Opv_Top_View_Target.fps);
			LCD_P6x8Str(0,7,"Dis:");      write_6_8_number(30,7,Opv_Top_View_Target.sdk_target.x);
																		write_6_8_number(95,7,Opv_Top_View_Target.sdk_target.y);
		}
		else if(Page_Number==9)
		{
			ssd1306_clear_display();
			ssd1306_draw_line(0,32,128,32,WHITE);
			ssd1306_draw_line(64,0,64,64,WHITE);
			
			uint16_t x,y;
			y=32-32*constrain_float(0.5*Opv_Front_View_Target.height-Opv_Front_View_Target.y,-50,50)/50.0f;
			x=64-32*constrain_float(0.5*Opv_Front_View_Target.width-Opv_Front_View_Target.x,-50,50)/50.0f;
      if(Opv_Front_View_Target.flag==1)			ssd1306_fill_circle(x,y,5,WHITE);
			else ssd1306_draw_circle(x,y,5,WHITE);			
			
			ssd1306_display();
			LCD_P6x8Str(0,0,"point_x:");  write_6_8_number(95,0,Opv_Front_View_Target.x);
			LCD_P6x8Str(0,1,"point_y::"); write_6_8_number(95,1,Opv_Front_View_Target.y);
			LCD_P6x8Str(0,2,"point_s:");  write_6_8_number(95,2,Opv_Front_View_Target.pixel);
			LCD_P6x8Str(0,3,"point_f:");  write_6_8_number(95,3,Opv_Front_View_Target.flag);
			LCD_P6x8Str(0,4,"Tar_x:");    write_6_8_number(95,4,Opv_Front_View_Target.sdk_target.x);
			LCD_P6x8Str(0,5,"Tar_y:");    write_6_8_number(95,5,Opv_Front_View_Target.sdk_target.y); 
			LCD_P6x8Str(0,6,"FPS:");      write_6_8_number(95,6,Opv_Front_View_Target.fps);
			LCD_P6x8Str(0,7,"Dis:");      write_6_8_number(30,7,Opv_Front_View_Target.apriltag_distance);
		}
		else if(Page_Number==10)
		{
			LCD_clear_L(0,0);
			LCD_P6x8Str(10,0,"Accel_Correct");
			write_6_8_number(100,0,flight_direction);write_6_8_number(110,0,Page_Number+1);
			LCD_clear_L(0,1);
			write_6_8_number(0,1,acce_sample[0].x);
			write_6_8_number(40,1,acce_sample[0].y);
			write_6_8_number(70,1,acce_sample[0].z);
			LCD_clear_L(0,2);
			write_6_8_number(0,2,acce_sample[1].x);
			write_6_8_number(40,2,acce_sample[1].y);
			write_6_8_number(70,2,acce_sample[1].z);
			LCD_clear_L(0,3);
			write_6_8_number(0,3,acce_sample[2].x);
			write_6_8_number(40,3,acce_sample[2].y);
			write_6_8_number(70,3,acce_sample[2].z);
			LCD_clear_L(0,4);
			write_6_8_number(0,4,acce_sample[3].x);
			write_6_8_number(40,4,acce_sample[3].y);
			write_6_8_number(70,4,acce_sample[3].z);
			LCD_clear_L(0,5);
			write_6_8_number(0,5,acce_sample[4].x);
			write_6_8_number(40,5,acce_sample[4].y);
			write_6_8_number(70,5,acce_sample[4].z);
			LCD_clear_L(0,6);
			write_6_8_number(0,6,acce_sample[5].x);
			write_6_8_number(40,6,acce_sample[5].y);
			write_6_8_number(70,6,acce_sample[5].z);
		}
		else if(Page_Number==11)
		{
			LCD_clear_L(0,0);
			LCD_P6x8Str(10,0,"Mag_Correct");
			write_6_8_number(90,0,Mag_Calibration_Mode);write_6_8_number(100,0,Page_Number+1);
			LCD_clear_L(0,1);
			write_6_8_number(0,1, (int16_t)(WP_Sensor.accel_raw.x));
			write_6_8_number(40,1,(int16_t)(WP_Sensor.accel_raw.y));
			write_6_8_number(70,1,(int16_t)(WP_Sensor.accel_raw.z));
			LCD_clear_L(0,2);
			LCD_P6x8Str(0,2,"0 To 360");
			write_6_8_number(70,2,Yaw_Correct);
			LCD_clear_L(0,3);
			LCD_P6x8Str(0,3,"Mag Is Okay?");
			write_6_8_number(80,3,Mag_Is_Okay_Flag[0]);
			write_6_8_number(90,3,Mag_Is_Okay_Flag[1]);
			write_6_8_number(105,3,Mag_Is_Okay_Flag[2]);
			LCD_clear_L(0,4);
			for(i=0;i<12;i++)
			{
				write_6_8_number(10*i,4,Mag_360_Flag[0][3*i]);
			}
			LCD_clear_L(0,5);
			for(i=0;i<12;i++)
			{
				write_6_8_number(10*i,5,Mag_360_Flag[1][3*i]);
			}
			LCD_clear_L(0,6);
			for(i=0;i<12;i++)
			{
				write_6_8_number(10*i,6,Mag_360_Flag[2][3*i]);
			}
			LCD_clear_L(0,7);
			if(Mag_Calibration_Mode==0) LCD_P6x8Str(0,7,"Make Z+ Upside Sky");
			else if(Mag_Calibration_Mode==1) LCD_P6x8Str(0,7,"Make Y+ Upside Sky");
			else if(Mag_Calibration_Mode==2) LCD_P6x8Str(0,7,"Make X+ Upside Sky");
			else if(Mag_Calibration_Mode==3) LCD_P6x8Str(0,7,"Start With Yaw Move"); 
		}
		else if(Page_Number==12)
		{
			
			LCD_clear_L(0,0);  LCD_P6x8Str(0,0,"ch1:");write_6_8_number(25,0,PPM_Databuf[0]);write_6_8_number(55,0,RC_Data.cal[0].max);write_6_8_number(90,0,RC_Data.cal[0].min);
			LCD_clear_L(0,1);  LCD_P6x8Str(0,1,"ch2:");write_6_8_number(25,1,PPM_Databuf[1]);write_6_8_number(55,1,RC_Data.cal[1].max);write_6_8_number(90,1,RC_Data.cal[1].min);
			LCD_clear_L(0,2);  LCD_P6x8Str(0,2,"ch3:");write_6_8_number(25,2,PPM_Databuf[2]);write_6_8_number(55,2,RC_Data.cal[2].max);write_6_8_number(90,2,RC_Data.cal[2].min);
			LCD_clear_L(0,3);  LCD_P6x8Str(0,3,"ch4:");write_6_8_number(25,3,PPM_Databuf[3]);write_6_8_number(55,3,RC_Data.cal[3].max);write_6_8_number(90,3,RC_Data.cal[3].min);
			LCD_clear_L(0,4);  LCD_P6x8Str(0,4,"ch5:");write_6_8_number(25,4,PPM_Databuf[4]);write_6_8_number(55,4,RC_Data.cal[4].max);write_6_8_number(90,4,RC_Data.cal[4].min);
			LCD_clear_L(0,5);  LCD_P6x8Str(0,5,"ch6:");write_6_8_number(25,5,PPM_Databuf[5]);write_6_8_number(55,5,RC_Data.cal[5].max);write_6_8_number(90,5,RC_Data.cal[5].min);
			LCD_clear_L(0,6);  LCD_P6x8Str(0,6,"ch7:");write_6_8_number(25,6,PPM_Databuf[6]);write_6_8_number(55,6,RC_Data.cal[6].max);write_6_8_number(90,6,RC_Data.cal[6].min);
			LCD_clear_L(0,7);  LCD_P6x8Str(0,7,"ch8:");write_6_8_number(25,7,PPM_Databuf[7]);write_6_8_number(55,7,RC_Data.cal[7].max);write_6_8_number(90,7,RC_Data.cal[7].min);
//			LCD_clear_L(0,0);
//			LCD_P6x8Str(10,0,"Sensor Data");   write_6_8_number(100,0,Page_Number+1);
//			LCD_clear_L(0,2);LCD_P6x8Str(0,2,"mag:");
//			write_6_8_number(30,2,WP_Sensor.mag_raw.x);
//			write_6_8_number(65,2,WP_Sensor.mag_raw.y);
//			write_6_8_number(100,2,WP_Sensor.mag_raw.z);
//			LCD_clear_L(0,3);LCD_P6x8Str(0,3,"acc:");
//			write_6_8_number(30,3,WP_Sensor.accel_raw.x);
//			write_6_8_number(65,3,WP_Sensor.accel_raw.y);
//			write_6_8_number(100,3,WP_Sensor.accel_raw.z);
//			LCD_clear_L(0,4);LCD_P6x8Str(0,4,"gyr:");
//			write_6_8_number(30,4,WP_Sensor.gyro_raw.x);
//			write_6_8_number(65,4,WP_Sensor.gyro_raw.y);
//			write_6_8_number(100,4,WP_Sensor.gyro_raw.z);
//			LCD_clear_L(0,5);LCD_P6x8Str(0,5,"bar:");
//			write_6_8_number(30,5,WP_Sensor.baro_pressure_raw);
//			write_6_8_number(65,5,WP_Sensor.baro_temp_raw);
//			LCD_clear_L(0,6);LCD_P6x8Str(0,6,"opt:");
//			write_6_8_number(30,6,opt_origin_data.pixel_flow_x_integral);
//			write_6_8_number(65,6,opt_origin_data.pixel_flow_y_integral);
//			LCD_clear_L(0,7);LCD_P6x8Str(0,7,"tfm:");
//			write_6_8_number(30,7,tfdata.distance);
//			write_6_8_number(65,7,tfdata.strength);
//			write_6_8_number(100,7,tfdata.temperature);
		}
		else if(Page_Number==13)
		{
//			LCD_clear_L(0,0);LCD_P6x8Str(0,0,"High_Acce.Kp:");write_6_8_number(95,0,Total_Controller.High_Acce_Control.Kp);
//			LCD_clear_L(0,1);LCD_P6x8Str(0,1,"High_Acce.Ki:");write_6_8_number(95,1,Total_Controller.High_Acce_Control.Ki);
//			LCD_clear_L(0,2);LCD_P6x8Str(0,2,"Optical_Pos.Kp:");write_6_8_number(95,2,Total_Controller.Optical_Position_Control.Kp);
//			LCD_clear_L(0,3);LCD_P6x8Str(0,3,"Optical_Pos.Ki:");write_6_8_number(95,3,Total_Controller.Optical_Position_Control.Ki);
//			LCD_clear_L(0,4);LCD_P6x8Str(0,4,"Optical_Speed.Kp:");write_6_8_number(95,4,Total_Controller.Optical_Speed_Control.Kp);
//			LCD_clear_L(0,5);LCD_P6x8Str(0,5,"Optical_Speed.Ki:");write_6_8_number(95,5,Total_Controller.Optical_Speed_Control.Ki);
//			LCD_clear_L(0,6);
//			LCD_clear_L(0,7);
			
			
			LCD_clear_L(0,0);  LCD_P6x8Str(0,0,"ch1:");write_6_8_number(25,0,PPM_Databuf[0]);write_6_8_number(55,0,RC_Data.cal[0].max);write_6_8_number(90,0,RC_Data.cal[0].min);
			LCD_clear_L(0,1);  LCD_P6x8Str(0,1,"ch2:");write_6_8_number(25,1,PPM_Databuf[1]);write_6_8_number(55,1,RC_Data.cal[1].max);write_6_8_number(90,1,RC_Data.cal[1].min);
			LCD_clear_L(0,2);  LCD_P6x8Str(0,2,"ch3:");write_6_8_number(25,2,PPM_Databuf[2]);write_6_8_number(55,2,RC_Data.cal[2].max);write_6_8_number(90,2,RC_Data.cal[2].min);
			LCD_clear_L(0,3);  LCD_P6x8Str(0,3,"ch4:");write_6_8_number(25,3,PPM_Databuf[3]);write_6_8_number(55,3,RC_Data.cal[3].max);write_6_8_number(90,3,RC_Data.cal[3].min);
			LCD_clear_L(0,4);  LCD_P6x8Str(0,4,"ch5:");write_6_8_number(25,4,PPM_Databuf[4]);write_6_8_number(55,4,RC_Data.cal[4].max);write_6_8_number(90,4,RC_Data.cal[4].min);
			LCD_clear_L(0,5);  LCD_P6x8Str(0,5,"ch6:");write_6_8_number(25,5,PPM_Databuf[5]);write_6_8_number(55,5,RC_Data.cal[5].max);write_6_8_number(90,5,RC_Data.cal[5].min);
			LCD_clear_L(0,6);  LCD_P6x8Str(0,6,"ch7:");write_6_8_number(25,6,PPM_Databuf[6]);write_6_8_number(55,6,RC_Data.cal[6].max);write_6_8_number(90,6,RC_Data.cal[6].min);
			LCD_clear_L(0,7);  LCD_P6x8Str(0,7,"ch8:");write_6_8_number(25,7,PPM_Databuf[7]);write_6_8_number(55,7,RC_Data.cal[7].max);write_6_8_number(90,7,RC_Data.cal[7].min);
		}
		else if(Page_Number==14)
		{
			LCD_clear_L(0,0);LCD_clear_L(0,1);LCD_P8x16Str(0,0,"Please Move Thr");
			LCD_clear_L(0,2);LCD_clear_L(0,3);LCD_P8x16Str(0,2,"Up And Pull Out");
			LCD_clear_L(0,4);LCD_clear_L(0,5);LCD_P8x16Str(0,4,"The Power Supply");
			LCD_clear_L(0,6);LCD_clear_L(0,7);LCD_P8x16Str(0,6,"ESC Calibration");
		}
		else if(Page_Number==15)
		{
			Copyright_Show();
		}


  }
}

/* Copyright (c)  2018-2025 Wuhan Nameless Innovation Technology Co.,Ltd. All rights reserved.*/
