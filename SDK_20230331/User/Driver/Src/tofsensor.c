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
#include "tofsensor.h"

void Tofsensor_In1_Init(void)
{
  MAP_GPIO_setAsInputPinWithPullDownResistor(GPIO_PORT_P5, GPIO_PIN7);
	GPIO_interruptEdgeSelect(GPIO_PORT_P5,GPIO_PIN7,GPIO_LOW_TO_HIGH_TRANSITION);
	MAP_GPIO_clearInterruptFlag(GPIO_PORT_P5, GPIO_PIN7);
	MAP_GPIO_enableInterrupt(GPIO_PORT_P5, GPIO_PIN7);
	MAP_Interrupt_enableInterrupt(INT_PORT5);	
}


void Tofsensor_In1_UP()//�����ش���
{
  GPIO_setAsInputPinWithPullDownResistor(GPIO_PORT_P5, GPIO_PIN7);
	GPIO_interruptEdgeSelect(GPIO_PORT_P5,GPIO_PIN7,GPIO_LOW_TO_HIGH_TRANSITION); 
  GPIO_clearInterruptFlag(GPIO_PORT_P5, GPIO_PIN7);
}

void Tofsensor_In1_DN()//�½��ش���
{
	GPIO_setAsInputPinWithPullUpResistor(GPIO_PORT_P5, GPIO_PIN7);
	GPIO_interruptEdgeSelect(GPIO_PORT_P5,GPIO_PIN7,GPIO_HIGH_TO_LOW_TRANSITION);
  GPIO_clearInterruptFlag(GPIO_PORT_P5, GPIO_PIN7);	
}



void Tofsensor_In2_Init(void)
{
  MAP_GPIO_setAsInputPinWithPullDownResistor(GPIO_PORT_P3, GPIO_PIN0);
	GPIO_interruptEdgeSelect(GPIO_PORT_P3,GPIO_PIN0,GPIO_LOW_TO_HIGH_TRANSITION);
	MAP_GPIO_clearInterruptFlag(GPIO_PORT_P3, GPIO_PIN0);
	MAP_GPIO_enableInterrupt(GPIO_PORT_P3, GPIO_PIN0);
	MAP_Interrupt_enableInterrupt(INT_PORT3);	
}


void Tofsensor_In2_UP()//�����ش���
{
  GPIO_setAsInputPinWithPullDownResistor(GPIO_PORT_P3, GPIO_PIN0);
	GPIO_interruptEdgeSelect(GPIO_PORT_P3,GPIO_PIN0,GPIO_LOW_TO_HIGH_TRANSITION); 
  GPIO_clearInterruptFlag(GPIO_PORT_P3, GPIO_PIN0);
}

void Tofsensor_In2_DN()//�½��ش���
{
	GPIO_setAsInputPinWithPullUpResistor(GPIO_PORT_P3, GPIO_PIN0);
	GPIO_interruptEdgeSelect(GPIO_PORT_P3,GPIO_PIN0,GPIO_HIGH_TO_LOW_TRANSITION);
  GPIO_clearInterruptFlag(GPIO_PORT_P3, GPIO_PIN0);	
}


void Tofsensor_Init(void)
{
	Tofsensor_In1_Init();
	Tofsensor_In2_Init();
}









Tofsensor_Init_data Tofsensor_Init_in1,Tofsensor_Init_in2;
systime Tofsensor_t;
void Tofsensor_In1_IRQHandler(void)
{
	static uint8_t _flag=0; 
	if(_flag==0)//��������
	{
	  Tofsensor_Init_in1.Tofsensor_start_time=10000*(TIME_ISR_CNT+1)-(uint32_t)(Timer32_getValue(TIMER32_BASE+0x00020)/48);//��λus
		Tofsensor_In1_DN();
	  _flag=1;
	}
  else if(_flag==1)//���½���
	{		
	  Tofsensor_Init_in1.Tofsensor_end_time=10000*(TIME_ISR_CNT+1)-(uint32_t)(Timer32_getValue(TIMER32_BASE+0x00020)/48);//��λus
		Tofsensor_Init_in1.Tofsensor_delta=Tofsensor_Init_in1.Tofsensor_end_time-Tofsensor_Init_in1.Tofsensor_start_time;
		Tofsensor_Init_in1.Tofsensor_update_flag=1;		
		Tofsensor_In1_UP();
		_flag=0;
	}		  
}



void Tofsensor_In2_IRQHandler(void)
{
	static uint8_t _flag=0; 
	if(_flag==0)//��������
	{
		Get_Systime(&Tofsensor_t);
	  Tofsensor_Init_in2.Tofsensor_start_time=10000*(TIME_ISR_CNT+1)-(uint32_t)(Timer32_getValue(TIMER32_BASE+0x00020)/48);//��λus
		Tofsensor_In2_DN();
	  _flag=1;
	}
  else if(_flag==1)//���½���
	{		
	  Tofsensor_Init_in2.Tofsensor_end_time=10000*(TIME_ISR_CNT+1)-(uint32_t)(Timer32_getValue(TIMER32_BASE+0x00020)/48);//��λus
		Tofsensor_Init_in2.Tofsensor_delta=Tofsensor_Init_in2.Tofsensor_end_time-Tofsensor_Init_in2.Tofsensor_start_time;
		Tofsensor_Init_in2.Tofsensor_update_flag=1;		
		Tofsensor_In2_UP();
		_flag=0;
	}		  
}



void PORT3_IRQHandler(void)
{
	uint32_t status= MAP_GPIO_getEnabledInterruptStatus(GPIO_PORT_P3);
	MAP_GPIO_clearInterruptFlag(GPIO_PORT_P3, status);
	if(status & GPIO_PIN0)
  {
    Tofsensor_In2_IRQHandler();
  }
}

void PORT5_IRQHandler(void)
{
	uint32_t status= MAP_GPIO_getEnabledInterruptStatus(GPIO_PORT_P5);
	MAP_GPIO_clearInterruptFlag(GPIO_PORT_P5, status);
	if(status & GPIO_PIN7)
  {
    Tofsensor_In1_IRQHandler();
  }
}


void Tofsensor_Data_Update()
{	
	static uint16_t _cnt=0;
	static uint8_t fault_flag=0;
	if(Tofsensor_Init_in2.Tofsensor_update_flag==1)
	{
		Tofsensor_Init_in2.pre_last_distance=Tofsensor_Init_in2.last_distance;//���ϴθ߶�
		Tofsensor_Init_in2.last_distance=Tofsensor_Init_in2.distance;//�ϴθ߶�
		Tofsensor_Init_in2.distance=Tofsensor_Init_in2.Tofsensor_delta*3.0f;//���θ߶�		
    Tofsensor_Init_in2.last_vel=Tofsensor_Init_in2.vel;
		Tofsensor_Init_in2.vel=(Tofsensor_Init_in2.distance-Tofsensor_Init_in2.last_distance)/0.05f;
		Tofsensor_Init_in2.acc=(Tofsensor_Init_in2.vel-Tofsensor_Init_in2.last_vel)/0.05f;
		
		if(ABS(Tofsensor_Init_in2.vel)<1000)
		{
			if(fault_flag==1&&Tofsensor_Init_in2.distance==Tofsensor_Init_in2.pre_last_distance)//����=���ϴ�
			{
				fault_flag=1;
			}			
			else if(fault_flag==1&&Tofsensor_Init_in2.distance==Tofsensor_Init_in2.last_distance)//����=�ϴ�
			{
				fault_flag=1;
			}
			else if(fault_flag==1&&Tofsensor_Init_in2.last_distance==Tofsensor_Init_in2.pre_last_distance)//�ϴ�=���ϴ�
			{
			  fault_flag=1;		
			}
			//����Ϊ�������쳣����
			else
			{
				Ground_Distance=Tofsensor_Init_in2.distance;
				Ground_Distance_Div=Tofsensor_Init_in2.vel;
				Ground_Distance_Acc=Tofsensor_Init_in2.acc;
							
			}
		}
		else
		{
			fault_flag=1;		
		}
		_cnt++;		
		Tofsensor_Init_in2.Tofsensor_update_flag=0; 		
	}
	
	
	
	if(Tofsensor_Init_in2.Tofsensor_update_flag==1)//�����ѽ�������������
	{
		Tofsensor_Init_in2.distance=Tofsensor_Init_in2.Tofsensor_delta/100.0f;		
		Tofsensor_Init_in2.Tofsensor_update_flag=0;	
	}	
	
  if(Ground_Distance<=380&&Ground_Distance>0)  Sensor_Flag.Ground_Health=1;
  else  Sensor_Flag.Ground_Health=0; 
}




