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
#include "US_100.h"




float Ground_Distance=0,Last_Ground_Distance=0,Ground_Distance_Div=0,Last_Ground_Distance_Div=0;
float Ground_Distance_Acc=0;



void US100_Init(void)
{
  MAP_GPIO_setAsInputPinWithPullDownResistor(GPIO_PORT_P6, GPIO_PIN6);
	GPIO_interruptEdgeSelect(GPIO_PORT_P6,GPIO_PIN6,GPIO_LOW_TO_HIGH_TRANSITION);
	MAP_GPIO_clearInterruptFlag(GPIO_PORT_P6, GPIO_PIN6);
//	MAP_GPIO_enableInterrupt(GPIO_PORT_P6, GPIO_PIN6);
//	MAP_Interrupt_enableInterrupt(INT_PORT6);	
	GPIO_setAsOutputPin(GPIO_PORT_P6, GPIO_PIN7);
  GPIO_setOutputLowOnPin(GPIO_PORT_P6, GPIO_PIN7);
}


void US100_UP()
{
  GPIO_setAsInputPinWithPullDownResistor(GPIO_PORT_P6, GPIO_PIN6);
	GPIO_interruptEdgeSelect(GPIO_PORT_P6,GPIO_PIN6,GPIO_LOW_TO_HIGH_TRANSITION); 
  GPIO_clearInterruptFlag(GPIO_PORT_P6, GPIO_PIN6);
}

void US100_DN()
{
	GPIO_setAsInputPinWithPullUpResistor(GPIO_PORT_P6, GPIO_PIN6);
	GPIO_interruptEdgeSelect(GPIO_PORT_P6,GPIO_PIN6,GPIO_HIGH_TO_LOW_TRANSITION);
  GPIO_clearInterruptFlag(GPIO_PORT_P6, GPIO_PIN6);	
}

us100_data us100;
static uint8_t _flag=0;
void US100_IRQHandler(void)
{
	
	if(_flag==0)//��������
	{
	  us100.us100_start_time=10000*(TIME_ISR_CNT+1)-(uint32_t)(Timer32_getValue(TIMER32_BASE+0x00020)/48);//��λus
		US100_DN();
	  _flag=1;
	}
  else if(_flag==1)//���½���
	{
	  us100.us100_end_time=10000*(TIME_ISR_CNT+1)-(uint32_t)(Timer32_getValue(TIMER32_BASE+0x00020)/48);//��λus
		MAP_GPIO_disableInterrupt(GPIO_PORT_P6, GPIO_PIN6);
		us100.us100_delta=us100.us100_end_time-us100.us100_start_time;
		us100.us100_update_flag=1;
		us100.us100_rssi_cnt=100;		
	}		  
}



void US100_Trigger_Conversion(void)
{
	static uint16_t _cnt=0;
	_cnt++;
	if(_cnt>=20)//100ms
	{	
		_cnt=0;
		US100_UP();
		MAP_GPIO_enableInterrupt(GPIO_PORT_P6, GPIO_PIN6);
		GPIO_setOutputHighOnPin(GPIO_PORT_P6, GPIO_PIN7);
		delay_us(20);
		GPIO_setOutputLowOnPin(GPIO_PORT_P6, GPIO_PIN7);	
    us100.us100_update_flag=0;
		_flag=0;		
	}
	if(us100.us100_rssi_cnt>0) us100.us100_rssi_cnt--;	
	us100.us100_rssi_cnt=us100.us100_rssi_cnt/100.0f;
}




/***********************************************************
@��������US_100_Statemachine
@��ڲ�������
@���ڲ�������
@�������������������ݽ���״̬��
@���ߣ�����С��
@���ڣ�2019��01��27��
*************************************************************/
void US_100_Statemachine(void)
{
  US100_Trigger_Conversion();
	static uint8_t fault_flag=0;
	if(us100.us100_update_flag==1)
	{
		us100.pre_last_distance=us100.last_distance;//���ϴθ߶�
		us100.last_distance=us100.distance;//�ϴθ߶�
		us100.distance=us100.us100_delta*(340)/20000.0f;//���θ߶�		
    us100.last_vel=us100.vel;
		us100.vel=(us100.distance-us100.last_distance)/0.1f;
		us100.acc=(us100.vel-us100.last_vel)/0.1f;
		

			if(us100.distance>200||ABS(us100.last_distance-us100.distance)>30)
			{Ground_Distance=150;}
			else
			{Ground_Distance=us100.distance;}

			Ground_Distance_Div=us100.vel;
			Ground_Distance_Acc=us100.acc;		
			
		
		us100.us100_update_flag=0;
		WP_Sensor.us100_updtate_flag=1;
	}	
  if(Ground_Distance<=User_Height_Max&&Ground_Distance>0)  Sensor_Flag.Ground_Health=1;
  else  Sensor_Flag.Ground_Health=0; 
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
