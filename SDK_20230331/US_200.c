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
#include "US_200.h"




float Front_Distance=0,
	  Last_Front_Distance=0,
      Front_Distance_Div=0,
      Last_Front_Distance_Div=0,
      Front_Distance_Acc=0;

uint8_t US200_INF_flag=0;


void US200_Init(void)
{
  MAP_GPIO_setAsInputPinWithPullDownResistor(GPIO_PORT_P1, GPIO_PIN6);
	GPIO_interruptEdgeSelect(GPIO_PORT_P1,GPIO_PIN6,GPIO_LOW_TO_HIGH_TRANSITION);
	MAP_GPIO_clearInterruptFlag(GPIO_PORT_P1, GPIO_PIN6);
	MAP_GPIO_enableInterrupt(GPIO_PORT_P1, GPIO_PIN6);
	MAP_Interrupt_enableInterrupt(INT_PORT1);

//	MAP_GPIO_enableInterrupt(GPIO_PORT_P6, GPIO_PIN6);
//	MAP_Interrupt_enableInterrupt(INT_PORT6);	
	GPIO_setAsOutputPin(GPIO_PORT_P1, GPIO_PIN7);
  GPIO_setOutputLowOnPin(GPIO_PORT_P1, GPIO_PIN7);		//	3.0bian1.6//5.7bian1.7
}


void US200_UP()
{
  GPIO_setAsInputPinWithPullDownResistor(GPIO_PORT_P1, GPIO_PIN6);
	GPIO_interruptEdgeSelect(GPIO_PORT_P1,GPIO_PIN6,GPIO_LOW_TO_HIGH_TRANSITION); 
  GPIO_clearInterruptFlag(GPIO_PORT_P1, GPIO_PIN6);
}

void US200_DN()
{
	GPIO_setAsInputPinWithPullUpResistor(GPIO_PORT_P1, GPIO_PIN6);
	GPIO_interruptEdgeSelect(GPIO_PORT_P1,GPIO_PIN6,GPIO_HIGH_TO_LOW_TRANSITION);
  GPIO_clearInterruptFlag(GPIO_PORT_P1, GPIO_PIN6);	
}

us200_data us200;
static uint8_t _flag=0;
void US200_IRQHandler(void)
{
	
	if(_flag==0)//��������
	{
	  us200.us200_start_time=10000*(TIME_ISR_CNT+1)-(uint32_t)(Timer32_getValue(TIMER32_BASE+0x00020)/48);//��λus
		US200_DN();
	  _flag=1;
	}
  else if(_flag==1)//���½���
	{
	  us200.us200_end_time=10000*(TIME_ISR_CNT+1)-(uint32_t)(Timer32_getValue(TIMER32_BASE+0x00020)/48);//��λus
		MAP_GPIO_disableInterrupt(GPIO_PORT_P1, GPIO_PIN6);
		us200.us200_delta=us200.us200_end_time-us200.us200_start_time;
		us200.us200_update_flag=1;
		us200.us200_rssi_cnt=100;		
	}		  
}



void US200_Trigger_Conversion(void)
{
	static uint16_t _cnt=0;
	_cnt++;
	if(_cnt>=20)//100ms
	{	
		_cnt=0;

		US200_UP();
		MAP_GPIO_enableInterrupt(GPIO_PORT_P1, GPIO_PIN6);
		GPIO_setOutputHighOnPin(GPIO_PORT_P1, GPIO_PIN7);
		delay_us(20);
		GPIO_setOutputLowOnPin(GPIO_PORT_P1, GPIO_PIN7);	
    us200.us200_update_flag=0;
		_flag=0;		
	}
	if(us200.us200_rssi_cnt>0) us200.us200_rssi_cnt--;	
	us200.us200_rssi_cnt=us200.us200_rssi_cnt/100.0f;
}




/***********************************************************
@��������US_100_Statemachine
@��ڲ�������
@���ڲ�������
@�������������������ݽ���״̬��
@���ߣ�����С��
@���ڣ�2019��01��27��
*************************************************************/
void US_200_Statemachine(void)
{
	US200_Trigger_Conversion();
	static uint8_t fault_flag=0;
	
	static uint8_t fault_cnt=0;
	
	if(us200.us200_update_flag==1)
	{
		us200.pre_last_distance=us200.last_distance;//���ϴθ߶�
		us200.last_distance=us200.distance;//�ϴθ߶�
		us200.distance=us200.us200_delta*(340)/20000.0f;//���θ߶�		
		us200.last_vel=us200.vel;
		us200.vel=(us200.distance-us200.last_distance)/0.1f;
		us200.acc=(us200.vel-us200.last_vel)/0.1f;
		
		if(ABS(us200.vel)<1000)
		{
			if(fault_flag==1&&us200.distance==us200.pre_last_distance)//����=���ϴ�
			{
				fault_flag=1;
			}			
			else if(fault_flag==1&&us200.distance==us200.last_distance)//����=�ϴ�
			{
				fault_flag=1;
			}
			else if(fault_flag==1&&us200.last_distance==us200.pre_last_distance)//�ϴ�=���ϴ�
			{
			  fault_flag=1;		
			}
			//����Ϊ�������쳣����
			else
			{
				
				Front_Distance=us200.distance;
				Front_Distance_Div=us200.vel;
				Front_Distance_Acc=us200.acc;		
				
			}
		}
		else
		{
			fault_flag=1;		
		}
		us200.us200_update_flag=0;
		//WP_Sensor.us200_updtate_flag=1;
	}	
  if(Front_Distance<=500&&Front_Distance>0)  Sensor_Flag.Front_Health=1;//250ԭ����500
  else  Sensor_Flag.Front_Health=0; 
  
	//�ж�������û�з����ı�
	if(Front_Distance==Last_Front_Distance) fault_cnt++;
	else   fault_cnt=0;
	
	if(fault_cnt>=50)
	{
		US200_INF_flag=1;
		fault_cnt=50;
	}
	else	US200_INF_flag=0;
	
	Last_Front_Distance=Front_Distance;
}




void PORT1_IRQHandler(void)
{
	uint32_t status= MAP_GPIO_getEnabledInterruptStatus(GPIO_PORT_P1);
	MAP_GPIO_clearInterruptFlag(GPIO_PORT_P1, status);
	if(status & GPIO_PIN6)
  {
    US200_IRQHandler();
	  
  }
}







//	if(us100_in.us100_update_flag==1)
//	{
//		Ground_Distance=us100_in.us100_delta*(340)/20000.0f;	
//		WP_Sensor.us100_updtate_flag=1;		
//		Ground_Distance_Div=(Ground_Distance-Last_Ground_Distance)/0.1f;
//		Ground_Distance_Acc=(Ground_Distance_Div-Last_Ground_Distance_Div)/0.1f;
//		Last_Ground_Distance_Div=Ground_Distance_Div;
//		us100_in.us100_update_flag=0;
//	}	
/* Copyright (c)  2018-2025 Wuhan Nameless Innovation Technology Co.,Ltd. All rights reserved.*/
