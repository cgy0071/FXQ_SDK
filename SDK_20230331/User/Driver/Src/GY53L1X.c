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
#include "GY53L1x.h"




void GY53L1X_In1_Init(void)
{
  MAP_GPIO_setAsInputPinWithPullDownResistor(GPIO_PORT_P5, GPIO_PIN7);
	GPIO_interruptEdgeSelect(GPIO_PORT_P5,GPIO_PIN7,GPIO_LOW_TO_HIGH_TRANSITION);
	MAP_GPIO_clearInterruptFlag(GPIO_PORT_P5, GPIO_PIN7);
	MAP_GPIO_enableInterrupt(GPIO_PORT_P5, GPIO_PIN7);
	MAP_Interrupt_enableInterrupt(INT_PORT5);	
}


void GY53L1X_In1_UP()//�����ش���
{
  GPIO_setAsInputPinWithPullDownResistor(GPIO_PORT_P5, GPIO_PIN7);
	GPIO_interruptEdgeSelect(GPIO_PORT_P5,GPIO_PIN7,GPIO_LOW_TO_HIGH_TRANSITION); 
  GPIO_clearInterruptFlag(GPIO_PORT_P5, GPIO_PIN7);
}

void GY53L1X_In1_DN()//�½��ش���
{
	GPIO_setAsInputPinWithPullUpResistor(GPIO_PORT_P5, GPIO_PIN7);
	GPIO_interruptEdgeSelect(GPIO_PORT_P5,GPIO_PIN7,GPIO_HIGH_TO_LOW_TRANSITION);
  GPIO_clearInterruptFlag(GPIO_PORT_P5, GPIO_PIN7);	
}



void GY53L1X_In2_Init(void)
{
  MAP_GPIO_setAsInputPinWithPullDownResistor(GPIO_PORT_P3, GPIO_PIN0);
	GPIO_interruptEdgeSelect(GPIO_PORT_P3,GPIO_PIN0,GPIO_LOW_TO_HIGH_TRANSITION);
	MAP_GPIO_clearInterruptFlag(GPIO_PORT_P3, GPIO_PIN0);
	MAP_GPIO_enableInterrupt(GPIO_PORT_P3, GPIO_PIN0);
	MAP_Interrupt_enableInterrupt(INT_PORT3);	
}


void GY53L1X_In2_UP()//�����ش���
{
  GPIO_setAsInputPinWithPullDownResistor(GPIO_PORT_P3, GPIO_PIN0);
	GPIO_interruptEdgeSelect(GPIO_PORT_P3,GPIO_PIN0,GPIO_LOW_TO_HIGH_TRANSITION); 
  GPIO_clearInterruptFlag(GPIO_PORT_P3, GPIO_PIN0);
}

void GY53L1X_In2_DN()//�½��ش���
{
	GPIO_setAsInputPinWithPullUpResistor(GPIO_PORT_P3, GPIO_PIN0);
	GPIO_interruptEdgeSelect(GPIO_PORT_P3,GPIO_PIN0,GPIO_HIGH_TO_LOW_TRANSITION);
  GPIO_clearInterruptFlag(GPIO_PORT_P3, GPIO_PIN0);	
}


void GY53L1X_Init(void)
{
	GY53L1X_In1_Init();
	GY53L1X_In2_Init();
}









vl53l1x_data vl53l1x_in1,vl53l1x_in2;
systime GY53L1_t;
void GY53L1X_In1_IRQHandler(void)
{
	static uint8_t _flag=0; 
	if(_flag==0)//��������
	{
	  vl53l1x_in1.gy53l1x_start_time=10000*(TIME_ISR_CNT+1)-(uint32_t)(Timer32_getValue(TIMER32_BASE+0x00020)/48);//��λus
		GY53L1X_In1_DN();
	  _flag=1;
	}
  else if(_flag==1)//���½���
	{		
	  vl53l1x_in1.gy53l1x_end_time=10000*(TIME_ISR_CNT+1)-(uint32_t)(Timer32_getValue(TIMER32_BASE+0x00020)/48);//��λus
		vl53l1x_in1.gy53l1x_delta=vl53l1x_in1.gy53l1x_end_time-vl53l1x_in1.gy53l1x_start_time;
		vl53l1x_in1.gy53l1x_update_flag=1;		
		GY53L1X_In1_UP();
		_flag=0;
	}		  
}



void GY53L1X_In2_IRQHandler(void)
{
	static uint8_t _flag=0; 
	if(_flag==0)//��������
	{
		Get_Systime(&GY53L1_t);
	  vl53l1x_in2.gy53l1x_start_time=10000*(TIME_ISR_CNT+1)-(uint32_t)(Timer32_getValue(TIMER32_BASE+0x00020)/48);//��λus
		GY53L1X_In2_DN();
	  _flag=1;
	}
  else if(_flag==1)//���½���
	{		
	  vl53l1x_in2.gy53l1x_end_time=10000*(TIME_ISR_CNT+1)-(uint32_t)(Timer32_getValue(TIMER32_BASE+0x00020)/48);//��λus
		vl53l1x_in2.gy53l1x_delta=vl53l1x_in2.gy53l1x_end_time-vl53l1x_in2.gy53l1x_start_time;
		vl53l1x_in2.gy53l1x_update_flag=1;		
		GY53L1X_In2_UP();
		_flag=0;
	}		  
}



void PORT3_IRQHandler(void)
{
	uint32_t status= MAP_GPIO_getEnabledInterruptStatus(GPIO_PORT_P3);
	MAP_GPIO_clearInterruptFlag(GPIO_PORT_P3, status);
	if(status & GPIO_PIN0)
  {
    GY53L1X_In2_IRQHandler();
  }
}

void PORT5_IRQHandler(void)
{
	uint32_t status= MAP_GPIO_getEnabledInterruptStatus(GPIO_PORT_P5);
	MAP_GPIO_clearInterruptFlag(GPIO_PORT_P5, status);
	if(status & GPIO_PIN7)
  {
    GY53L1X_In1_IRQHandler();
  }
}



void GY53L1X_Data_Update()
{	
	static uint16_t _cnt=0;
	static uint8_t fault_flag=0;
	if(vl53l1x_in1.gy53l1x_update_flag==1)
	{
		vl53l1x_in1.pre_last_distance=vl53l1x_in1.last_distance;//���ϴθ߶�
		vl53l1x_in1.last_distance=vl53l1x_in1.distance;//�ϴθ߶�
		vl53l1x_in1.distance=vl53l1x_in1.gy53l1x_delta/100.0f;//���θ߶�		
    vl53l1x_in1.last_vel=vl53l1x_in1.vel;
		vl53l1x_in1.vel=(vl53l1x_in1.distance-vl53l1x_in1.last_distance)/0.05f;
		vl53l1x_in1.acc=(vl53l1x_in1.vel-vl53l1x_in1.last_vel)/0.05f;
		
			//����Ϊ�������쳣����
			if(vl53l1x_in1.distance>180||ABS(vl53l1x_in1.last_distance-vl53l1x_in1.distance)>30)
			{Ground_Distance=vl53l1x_in1.last_true_distance;}
			else
			{
			Ground_Distance=vl53l1x_in1.distance;
			vl53l1x_in1.last_true_distance=Ground_Distance;
			}
			

				
				Ground_Distance_Div=vl53l1x_in1.vel;
				Ground_Distance_Acc=vl53l1x_in1.acc;
							
			
		

		_cnt++;		
		vl53l1x_in1.gy53l1x_update_flag=0; 		
	}
	
	if(_cnt>=2)
	{
		WP_Sensor.us100_updtate_flag=1;
		_cnt=0;
	}
	
	
	if(vl53l1x_in2.gy53l1x_update_flag==1)//�����ѽ�������������
	{
		vl53l1x_in2.distance=vl53l1x_in2.gy53l1x_delta/100.0f;		
		vl53l1x_in2.gy53l1x_update_flag=0;	
	}	
	
  if(Ground_Distance<=380&&Ground_Distance>0)  Sensor_Flag.Ground_Health=1;
  else  Sensor_Flag.Ground_Health=0; 
}





/////////////////////////////////////////////////////








