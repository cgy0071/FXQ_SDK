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
#include "Time_Cnt.h"



const Timer_A_UpModeConfig upConfig2 =
{
	TIMER_A_CLOCKSOURCE_SMCLK,              // SMCLK Clock Source
	TIMER_A_CLOCKSOURCE_DIVIDER_12,         // SMCLK/1 = 3MHz
	2500,                           				// 2500 tick period
	TIMER_A_TAIE_INTERRUPT_DISABLE,         // Disable Timer interrupt
	TIMER_A_CCIE_CCR0_INTERRUPT_ENABLE ,    // Enable CCR0 interrupt
	TIMER_A_DO_CLEAR                        // Clear value
};
void TIMER_A2_Configuration(void)
{
   /* Configuring Timer_A1 for Up Mode */
	MAP_Timer_A_configureUpMode(TIMER_A2_BASE, &upConfig2);

	/* Enabling interrupts and starting the timer */
	MAP_Timer_A_clearCaptureCompareInterrupt(TIMER_A2_BASE,TIMER_A_CAPTURECOMPARE_REGISTER_0);
	MAP_Interrupt_enableInterrupt(INT_TA2_0);
	MAP_Timer_A_startCounter(TIMER_A2_BASE, TIMER_A_UP_MODE);
}

/***************************************************
������: void NVIC_Configuration(void)
˵��:	�ж����ȼ�����
���:	��
����:	��
��ע:	ϵͳ�ж�ʱ�����������ʱ����ȫ�����Թ��������
      ȷ�������˶����Ƚ���        
ע���ߣ�WUST
****************************************************/
void NVIC_Configuration(void)
{
  sysTickUptime=0;
	Interrupt_setPriorityGrouping(4);
  MAP_Interrupt_setPriority(FAULT_SYSTICK,0x00);	
	MAP_Interrupt_setPriority(INT_T32_INT2,0x00);
	MAP_Interrupt_setPriority(INT_EUSCIA2 ,0x20);//����2  ����վ ������921600
	MAP_Interrupt_setPriority(INT_PORT6   ,0x20);//PPM  US100
	MAP_Interrupt_setPriority(INT_PORT3   ,0x40);//GY53L1X_IN2
	MAP_Interrupt_setPriority(INT_PORT5   ,0x40);//GY53L1X_IN2
	
	MAP_Interrupt_setPriority(INT_EUSCIA3 ,0x60);//����3  OPENMV ������921600
	MAP_Interrupt_setPriority(INT_EUSCIA0 ,0x80);//����0  LC306  ������19200
	MAP_Interrupt_setPriority(INT_EUSCIB1 ,0xa0);//����1  OPENMV ������921600	
	
	MAP_Interrupt_setPriority(INT_ADC14   ,0xc0);
	MAP_Interrupt_setPriority(INT_TA2_0   ,0xe0);//���������
		
}
/***********************************************************
@��������Time_init
@��ڲ�������
@���ڲ�������
@����������ϵͳ���ȶ�ʱ����ʼ��
@���ߣ�WUST
@���ڣ�2019��01��27��
*************************************************************/
void Time_init(void)//ϵͳ���ȶ�ʱ����ʼ��
{
  Timer32_init();							 //�����ʱ��ʱ��
  TIMER_A2_Configuration();    //TIMER_A2������ȶ�ʱ��
  NVIC_Configuration();        //�ж����ȼ�����
}








void Task_200hz_Thread(void)
{

	
	Get_Status_Feedback();					//��ȡ��̬���ݡ�ˮƽ����ֱ����ߵ�����
	GankerPilot_Control();					//�ܿ�����
}


void Task_400hz_Thread(void)
{

	
  Remote_Control();								//ң�������ݽ���
#if (Ground_Distance_Sensor==US100)	
		US_100_Statemachine();			  //������������״̬������
#else
		TFmini_Statemachine();        //����TFMINI_PLUS������״̬������
#endif
	GY53L1X_Data_Update();
	Optflow_Statemachine();					//����״̬������ʼ��ʱ���ڹ�������
	SDK_Data_Prase_1();							//SDK���ݽ���
	SDK_Data_Prase_2();			
	Check_All_Calibartion();
  Bling_Working(Bling_Mode);			//״ָ̬ʾ������
	
		// ����������ť��������
  // Ȼ������5ͨ���ܴ�ʱ������������վ�޸�PID����
	  Vcan_Send();
	
  //		//�������¿�Դ����վ����������http://nameless.tech/download.html	
	Get_Battery_Voltage();		      //������ص�ѹ	
	Read_Button_State_All();

}

Sensor WP_Sensor;
Testime Time0_Delta;
Testime Time0_Delta1;
float test_time;
/***********************************************************
@��������TA2_0_IRQHandler
@��ڲ�������
@���ڲ�������
@����������ϵͳ���ȶ�ʱ���жϷ���������Ҫ����ң����������
�������ݲɼ��������˲�����̬���㡢���Ե��������Ƶȶ�������
�ϸ�Ҫ��ĺ���
@���ߣ�WUST
@���ڣ�2019��01��27��
*************************************************************/
void TA2_0_IRQHandler(void)//5msˢ��һ��
{
	Test_Period(&Time0_Delta);
	static uint16_t _cnt_200hz=0,_cnt_400hz=0;
	_cnt_200hz++;
	_cnt_400hz++;
	if(_cnt_200hz>=1)
	{
		_cnt_200hz=0;
	  Task_200hz_Thread();
	}
	
	if(_cnt_400hz>=2)
	{
		_cnt_400hz=0;
	  Task_400hz_Thread();
	}
	Test_Period(&Time0_Delta1);
	if(Time0_Delta1.Now_Time-Time0_Delta.Now_Time>test_time)    test_time=Time0_Delta1.Now_Time-Time0_Delta.Now_Time; 	
	MAP_Timer_A_clearCaptureCompareInterrupt(TIMER_A2_BASE,TIMER_A_CAPTURECOMPARE_REGISTER_0);	
	
}


/* Copyright (c)  2018-2025 Wuhan Nameless Innovation Technology Co.,Ltd. All rights reserved.*/


