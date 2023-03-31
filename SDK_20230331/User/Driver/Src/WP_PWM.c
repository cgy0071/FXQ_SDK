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


#include "WP_PWM.h"

Timer_A_PWMConfig pwmConfig1 =
{
	TIMER_A_CLOCKSOURCE_SMCLK,
	TIMER_A_CLOCKSOURCE_DIVIDER_12,//12/12M=1M=1us
	2500-1,//2.5ms
	TIMER_A_CAPTURECOMPARE_REGISTER_1,
	TIMER_A_OUTPUTMODE_RESET_SET,
	0
};
Timer_A_PWMConfig pwmConfig2 =
{
	TIMER_A_CLOCKSOURCE_SMCLK,
	TIMER_A_CLOCKSOURCE_DIVIDER_12,
	2500-1,
	TIMER_A_CAPTURECOMPARE_REGISTER_2,
	TIMER_A_OUTPUTMODE_RESET_SET,
	0
};
Timer_A_PWMConfig pwmConfig3 =
{
	TIMER_A_CLOCKSOURCE_SMCLK,
	TIMER_A_CLOCKSOURCE_DIVIDER_12,
	2500-1,
	TIMER_A_CAPTURECOMPARE_REGISTER_3,
	TIMER_A_OUTPUTMODE_RESET_SET,
	0
};
Timer_A_PWMConfig pwmConfig4 =
{
	TIMER_A_CLOCKSOURCE_SMCLK,
	TIMER_A_CLOCKSOURCE_DIVIDER_12,
	2500-1,
	TIMER_A_CAPTURECOMPARE_REGISTER_4,
	TIMER_A_OUTPUTMODE_RESET_SET,
	0
};



void PWM_GPIO_Init(void )
{
	MAP_GPIO_setAsPeripheralModuleFunctionOutputPin(GPIO_PORT_P10,
            GPIO_PIN5, GPIO_PRIMARY_MODULE_FUNCTION);
	MAP_GPIO_setAsPeripheralModuleFunctionOutputPin(GPIO_PORT_P8,
					GPIO_PIN2, GPIO_PRIMARY_MODULE_FUNCTION);
	MAP_GPIO_setAsPeripheralModuleFunctionOutputPin(GPIO_PORT_P9,
            GPIO_PIN2 | GPIO_PIN3 , GPIO_PRIMARY_MODULE_FUNCTION);
	
}
/***********************************************************
@��������Init_PWM
@��ڲ�������
@���ڲ�������
@����������PWM��ʼ��
@���ߣ�WUST
@���ڣ�2019��01��27��
*************************************************************/
void Init_PWM(void)
{
  PWM_GPIO_Init();
	/* Configuring Timer_A1 for UpDown Mode and starting */
	MAP_Timer_A_generatePWM(TIMER_A3_BASE, &pwmConfig1);
	MAP_Timer_A_generatePWM(TIMER_A3_BASE, &pwmConfig2);
	MAP_Timer_A_generatePWM(TIMER_A3_BASE, &pwmConfig3);
	MAP_Timer_A_generatePWM(TIMER_A3_BASE, &pwmConfig4);
	PWM_Output(1000,1000,1000,1000);
	Init_EPWM();
}


/***********************************************************
@��������PWM_Output
@��ڲ�����uint16_t width1,uint16_t width2,uint16_t width3,
uint16_t width4,uint16_t width5,uint16_t width6,
uint16_t width7,uint16_t width8
@���ڲ�������
@����������PWM���
@���ߣ�WUST
@���ڣ�2019��01��27��
*************************************************************/
void PWM_Output(uint16_t width1,uint16_t width2,uint16_t width3,uint16_t width4)
{
  MAP_Timer_A_setCompareValue(TIMER_A3_BASE,TIMER_A_CAPTURECOMPARE_REGISTER_1,width1);
	MAP_Timer_A_setCompareValue(TIMER_A3_BASE,TIMER_A_CAPTURECOMPARE_REGISTER_2,width2);
	MAP_Timer_A_setCompareValue(TIMER_A3_BASE,TIMER_A_CAPTURECOMPARE_REGISTER_3,width3);
	MAP_Timer_A_setCompareValue(TIMER_A3_BASE,TIMER_A_CAPTURECOMPARE_REGISTER_4,width4);

//	EPWM_Output(width1,width2,width3,width4);
	EPWM_Output(width4,width3,width2,width1);
}






//////////////////////////////////////////////////////////////////
Timer_A_PWMConfig pwmConfig5 =
{
	TIMER_A_CLOCKSOURCE_SMCLK,
	TIMER_A_CLOCKSOURCE_DIVIDER_12,
	2500-1,
	TIMER_A_CAPTURECOMPARE_REGISTER_1,
	TIMER_A_OUTPUTMODE_RESET_SET,
	0
};
Timer_A_PWMConfig pwmConfig6 =
{
	TIMER_A_CLOCKSOURCE_SMCLK,
	TIMER_A_CLOCKSOURCE_DIVIDER_12,
	2500-1,
	TIMER_A_CAPTURECOMPARE_REGISTER_2,
	TIMER_A_OUTPUTMODE_RESET_SET,
	0
};
Timer_A_PWMConfig pwmConfig7 =
{
	TIMER_A_CLOCKSOURCE_SMCLK,
	TIMER_A_CLOCKSOURCE_DIVIDER_12,
	2500-1,
	TIMER_A_CAPTURECOMPARE_REGISTER_3,
	TIMER_A_OUTPUTMODE_RESET_SET,
	0
};
Timer_A_PWMConfig pwmConfig8 =
{
	TIMER_A_CLOCKSOURCE_SMCLK,
	TIMER_A_CLOCKSOURCE_DIVIDER_12,
	2500-1,
	TIMER_A_CAPTURECOMPARE_REGISTER_4,
	TIMER_A_OUTPUTMODE_RESET_SET,
	0
};



void EPWM_GPIO_Init(void)
{
	MAP_GPIO_setAsPeripheralModuleFunctionOutputPin(GPIO_PORT_P2,
					GPIO_PIN4 | GPIO_PIN5 | GPIO_PIN6 | GPIO_PIN7 , GPIO_PRIMARY_MODULE_FUNCTION);
}


void EPWM_Output(uint16_t width1,uint16_t width2,uint16_t width3,uint16_t width4)
{
  MAP_Timer_A_setCompareValue(TIMER_A0_BASE,TIMER_A_CAPTURECOMPARE_REGISTER_1,width1);
	MAP_Timer_A_setCompareValue(TIMER_A0_BASE,TIMER_A_CAPTURECOMPARE_REGISTER_2,width2);
	MAP_Timer_A_setCompareValue(TIMER_A0_BASE,TIMER_A_CAPTURECOMPARE_REGISTER_3,width3);
	MAP_Timer_A_setCompareValue(TIMER_A0_BASE,TIMER_A_CAPTURECOMPARE_REGISTER_4,width4);
}


void Init_EPWM(void)
{
  EPWM_GPIO_Init();
	/* Configuring Timer_A1 for UpDown Mode and starting */
	MAP_Timer_A_generatePWM(TIMER_A0_BASE, &pwmConfig5);
	MAP_Timer_A_generatePWM(TIMER_A0_BASE, &pwmConfig6);
	MAP_Timer_A_generatePWM(TIMER_A0_BASE, &pwmConfig7);
	MAP_Timer_A_generatePWM(TIMER_A0_BASE, &pwmConfig8);
	EPWM_Output(1000,1000,1000,1000);
}
/* Copyright (c)  2018-2025 Wuhan Nameless Innovation Technology Co.,Ltd. All rights reserved.*/



