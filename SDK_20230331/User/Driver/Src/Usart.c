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
#include "Usart.h"
#include "Ringbuf.h"
//����ѭ�����л������ݶ���
RingBuff_t COM0_Rx_Buf,COM1_Rx_Buf,COM2_Rx_Buf,COM3_Rx_Buf,COM4_Rx_Buf,COM5_Rx_Buf,COM6_Rx_Buf,COM7_Rx_Buf;

uint8_t controlTable[512];
//void Serial_Data_Send_Dma(u32 SendBuff,u16 len)//DMA---USART2����
void Serial_Data_Send_Dma(u32 SendBuff,u16 len)//DMA---USART2����
{
	 //![Simple DMA Example]
	/* Configuring DMA module */
	MAP_DMA_enableModule();
	MAP_DMA_setControlBase(controlTable);
	 /* Assigning Channel 2 to EUSCIB1TX0, and Channel 5 to EUSCIB2RX0  and
     * enabling channels 2 and 5*/
	MAP_DMA_assignChannel(DMA_CH4_EUSCIA2TX);
	 /* Disabling channel attributes */
	MAP_DMA_disableChannelAttribute(DMA_CH4_EUSCIA2TX,
																	 UDMA_ATTR_ALTSELECT | UDMA_ATTR_USEBURST |
																	 UDMA_ATTR_HIGH_PRIORITY |
																	 UDMA_ATTR_REQMASK);
	/* Setting Control Indexes */
	MAP_DMA_setChannelControl(UDMA_PRI_SELECT | DMA_CH4_EUSCIA2TX,
					UDMA_SIZE_8 | UDMA_SRC_INC_8 | UDMA_DST_INC_NONE | UDMA_ARB_1);
	
	MAP_DMA_setChannelTransfer(UDMA_PRI_SELECT | DMA_CH4_EUSCIA2TX,
					UDMA_MODE_BASIC, (void*) SendBuff,
					(void*) UART_getTransmitBufferAddressForDMA(EUSCI_A2_BASE), len);
	/* Now that the DMA is primed and setup, enabling the channels. The EUSCI
     * hardware should take over and transfer/receive all bytes */	
	MAP_DMA_enableChannel(4);
}


/*
//UARTA2 Ring Buffer Global Variables
#define UARTA2_BUFFERSIZE 2048
volatile uint8_t UARTA2Data[UARTA2_BUFFERSIZE];
volatile uint32_t UARTA2ReadIndex;
volatile uint32_t UARTA2WriteIndex;
#define UARTA2_ADVANCE_READ_INDEX          MAP_Interrupt_disableMaster(); UARTA2ReadIndex = (UARTA2ReadIndex + 1) % UARTA2_BUFFERSIZE; MAP_Interrupt_enableMaster();
#define UARTA2_ADVANCE_WRITE_INDEX         UARTA2WriteIndex = (UARTA2WriteIndex + 1) % UARTA2_BUFFERSIZE
#define UARTA2_BUFFER_EMPTY                UARTA2ReadIndex == UARTA2WriteIndex ? true : false
#define UARTA2_BUFFER_FULL                 (UARTA2WriteIndex + 1) % UARTA2_BUFFERSIZE == UARTA2ReadIndex ? true : false
*/

/***********************************************************
@��������EUSCIA2_IRQHandler
@��ڲ�������
@���ڲ�������
��������������2���ݽ���
@���ߣ�WUST
@���ڣ�2019��01��27��
*************************************************************/
void EUSCIA2_IRQHandler(void)
{
	uint32_t status = MAP_UART_getEnabledInterruptStatus(EUSCI_A2_BASE);
	if(status & EUSCI_A_UART_RECEIVE_INTERRUPT_FLAG)
	{
		uint8_t data=MAP_UART_receiveData(EUSCI_A2_BASE);
		NCLink_Data_Prase_Prepare(data);//(UCA2RXBUF);
	}	
	MAP_UART_clearInterruptFlag(EUSCI_A2_BASE, status);
}

/*	
	  if(UARTA2_BUFFER_FULL)
		{
				//TODO: Buffer Overflow, add handler here
		}
		else
		{
				UARTA2Data[UARTA2WriteIndex] = data;
				UARTA2_ADVANCE_WRITE_INDEX;
		}
*/
/********************************************/
//�����ʼ��㹫ʽ��
// N=ʱ����Ƶ/������
// ��� N<16  UCBRx=INT(N),UCBRF=0;
// ��� N>16  UCBRx=INT(N/16),UCBRF=INT{[(N/16)-INT(N/16)]*16}
// UCBRS ȡֵ��MSP432 USER'S GUIDE P731
// ���� ʹ�ü����� 
// software-dl.ti.com/msp430/msp430_public_sw/mcu/msp430/MSP430BaudRateConverter/index.html
/********************************************/
const eUSCI_UART_Config uartConfig =
{
	EUSCI_A_UART_CLOCKSOURCE_SMCLK,          // SMCLK Clock Source
	6,                                       // BRDIV = 13   6
	8,                                       // UCxBRF = 0   8
	0x20,                                       // UCxBRS = 0   32
	EUSCI_A_UART_NO_PARITY,                  // No Parity
	EUSCI_A_UART_LSB_FIRST,                  // MSB First
	EUSCI_A_UART_ONE_STOP_BIT,               // One stop bit
	EUSCI_A_UART_MODE,                       // UART mode
	EUSCI_A_UART_OVERSAMPLING_BAUDRATE_GENERATION  // Oversampling
	//EUSCI_A_UART_LOW_FREQUENCY_BAUDRATE_GENERATION
};
/***********************************************************
@��������USART2_Init
@��ڲ�������
@���ڲ�������
��������������2���ã����ϱ�עΪUART3��������115200
@���ߣ�WUST
@���ڣ�2019��01��27��
*************************************************************/
void USART2_Init()
{
  MAP_GPIO_setAsPeripheralModuleFunctionInputPin(GPIO_PORT_P3,
             GPIO_PIN2 | GPIO_PIN3, GPIO_PRIMARY_MODULE_FUNCTION);
	/* Configuring UART Module */
	MAP_UART_initModule(EUSCI_A2_BASE, &uartConfig);

	/* Enable UART module */
	MAP_UART_enableModule(EUSCI_A2_BASE);

	//MAP_UART_clearInterruptFlag (EUSCI_A2_BASE);
	/* Enabling interrupts */
	MAP_UART_enableInterrupt(EUSCI_A2_BASE, EUSCI_A_UART_RECEIVE_INTERRUPT);
	MAP_Interrupt_enableInterrupt(INT_EUSCIA2);
}

/***********************************************************
@��������USART2_Send
@��ڲ�����uint8_t *pui8Buffer, uint32_t ui32Count
@���ڲ�������
��������������2����N���ֽ�����
@���ߣ�WUST
@���ڣ�2019��01��27��
*************************************************************/
void USART2_Send(uint8_t *pui8Buffer, uint32_t ui32Count)
{
  while(ui32Count--)
	{
		MAP_UART_transmitData(EUSCI_A2_BASE, *pui8Buffer);
		pui8Buffer++;
	}
}
/***********************************************************
@��������wust_sendware
@��ڲ�����unsigned char *wareaddr, int16_t waresize
@���ڲ�������
����������ɽ������ʾ��������
@���ߣ�WUST
@���ڣ�2019��01��27��
*************************************************************/
void wust_sendware(unsigned char *wareaddr, int16_t waresize)//ɽ�ⷢ�Ͳ���
{
#define CMD_WARE     3
  uint8 cmdf[2] = {CMD_WARE, ~CMD_WARE};//֡ͷ
  uint8 cmdr[2] = {~CMD_WARE, CMD_WARE};//֡β
  USART2_Send(cmdf, sizeof(cmdf));
  USART2_Send(wareaddr, waresize);
  USART2_Send(cmdr, sizeof(cmdr));
}


float VCAN_DataBuf[8];
DMA_Vcan_Buff  Vcan_Buff;
extern float Value10;
extern Target_Check Opv_Top_View_Target;
extern int ccnt;
extern int sdk_cnt;
 
/***********************************************************
@��������Vcan_Send
@��ڲ�������
@���ڲ�������
����������ɽ�����ݷ��ͺ�����Ĭ�Ϸ���8��ͨ������������Ϊfloat
��ÿ��ͨ�����ݿ����Լ�����
@���ߣ�WUST
@���ڣ�2019��01��27��
*************************************************************/
void Vcan_Send(void)//ɽ�����վ����
{
 static float DataBuf[8];	

  //static float DataBuf[8];	
	//Vcan_Buff.Head=0xfc030000;     
	
//  DataBuf[0]=Vcan_Buff.DataBuf[0]=NamelessQuad.Position[_YAW];//�ߵ��߶�
//  DataBuf[1]=Vcan_Buff.DataBuf[1]=NamelessQuad.Speed[_YAW];//�ߵ��ٶ�
//  DataBuf[2]=Vcan_Buff.DataBuf[2]=observation_div;//NamelessQuad.Acceleration[_YAW];;//�ߵ����ٶ�
//  DataBuf[3]=Vcan_Buff.DataBuf[3]=Observation_Altitude;//��ѹ�Ƹ߶�
//  DataBuf[4]=Vcan_Buff.DataBuf[4]=observation_acc;
//  DataBuf[5]=Vcan_Buff.DataBuf[5]=tfdata.distance;
//  DataBuf[6]=Vcan_Buff.DataBuf[6]=tfdata.div;
//  DataBuf[7]=Vcan_Buff.DataBuf[7]=Ground_Distance;  
 
	DataBuf[0]=Opv_Top_View_Target.target_ctrl_enable;
	DataBuf[1]=Ground_Distance;//ccnt ;
	DataBuf[2]=OpticalFlow_Position.y;//Ground_Distance; 
  DataBuf[3]=OpticalFlow_Position.x;//observation_div;//NamelessQuad.Acceleration[_YAW];;//�ߵ����ٶ�
  DataBuf[4]=Total_Controller.SDK_Roll_Position_Control.FeedBack;//Observation_Altitude;//��ѹ�Ƹ߶�
  DataBuf[5]=Opv_Top_View_Target.target_ctrl_enable;//Opv_Top_View_Target.sdk_target.y;//observation_acc;
	DataBuf[6]=Opv_Top_View_Target.sdk_target.x;//Roll-Roll_Offset;//OpticalFlow_Position.x;//Total_Controller.Optical_Speed_Control.Kd*100;//PPM_Databuf[6];//tfdata.div;
  DataBuf[7]=Opv_Top_View_Target.sdk_target.y ;//SDK_Duty_Cnt;//OpticalFlow_Position.y;//Total_Controller.Pitch_Angle_Control.Kp*100;//tfdata.distance;  

    
	//Vcan_Buff.End=0x000003fc;
  //Serial_Data_Send_Dma((u32)(&Vcan_Buff),sizeof(Vcan_Buff));
	wust_sendware((unsigned char *)DataBuf,sizeof(DataBuf));
}

/* Copyright (c)  2018-2025 WUST All rights reserved.*/





void EUSCIA0_IRQHandler(void)
{
	uint32_t status = MAP_UART_getEnabledInterruptStatus(EUSCI_A0_BASE);

	if(status & EUSCI_A_UART_RECEIVE_INTERRUPT_FLAG)
	{
		RingBuf_Write(MAP_UART_receiveData(EUSCI_A0_BASE),&COM0_Rx_Buf,FLOW_BUF_CNT);//�����ζ�������д����
	}
	MAP_UART_clearInterruptFlag(EUSCI_A0_BASE, status);
}


void USART0_Send(uint8_t *pui8Buffer, uint32_t ui32Count)
{
  while(ui32Count--)
	{
		MAP_UART_transmitData(EUSCI_A0_BASE, *pui8Buffer);
		pui8Buffer++;
	}
}

void USART0_Send_Byte(uint8_t ch)
{
	MAP_UART_transmitData(EUSCI_A0_BASE, ch);
}

/* Current setting: 19200 bps */
const eUSCI_UART_Config uart0Config = {
		EUSCI_A_UART_CLOCKSOURCE_SMCLK,          // SMCLK Clock Source
		39,                                      // BRDIV
		1,                                       // UCxBRF
		0,                                       // UCxBRS
		EUSCI_A_UART_NO_PARITY,                  // No Parity
		EUSCI_A_UART_LSB_FIRST,                  // LSB First
		EUSCI_A_UART_ONE_STOP_BIT,               // One stop bit
		EUSCI_A_UART_MODE,                       // UART mode
		EUSCI_A_UART_OVERSAMPLING_BAUDRATE_GENERATION  // Oversampling
		};
/***********************************************************
@��������USART2_Init
@��ڲ�������
@���ڲ�������
��������������2���ã����ϱ�עΪUART3��������115200
@���ߣ�WUST
@���ڣ�2019��01��27��
*************************************************************/
void USART0_Init()
{
  MAP_GPIO_setAsPeripheralModuleFunctionInputPin(GPIO_PORT_P1,
             GPIO_PIN2 | GPIO_PIN3, GPIO_PRIMARY_MODULE_FUNCTION);
	/* Configuring UART Module */
	MAP_UART_initModule(EUSCI_A0_BASE, &uart0Config);

	/* Enable UART module */
	MAP_UART_enableModule(EUSCI_A0_BASE);
	//MAP_UART_clearInterruptFlag (EUSCI_A2_BASE);
	/* Enabling interrupts */
	MAP_UART_enableInterrupt(EUSCI_A0_BASE, EUSCI_A_UART_RECEIVE_INTERRUPT);  
	
	OpticalFlow_Init();//�����˲�������ʼ�� 
	OpticalFlow_Is_Work=Config_Init_Uart();	
	MAP_Interrupt_enableInterrupt(INT_EUSCIA0);
}



void EUSCIA1_IRQHandler(void)
{
	uint32_t status = MAP_UART_getEnabledInterruptStatus(EUSCI_A1_BASE);

	if(status & EUSCI_A_UART_RECEIVE_INTERRUPT_FLAG)
	{
		RingBuf_Write(MAP_UART_receiveData(EUSCI_A1_BASE),&COM1_Rx_Buf,SDK_Target_Length*2);//�����ζ�������д����
		if(COM1_Rx_Buf.Ring_Buff[0]!=0xFF)
		{
			COM1_Rx_Buf.Head=1;
			COM1_Rx_Buf.Tail=0; 
		}	
	}
	MAP_UART_clearInterruptFlag(EUSCI_A1_BASE, status);	
}


void USART1_Send(uint8_t *pui8Buffer, uint32_t ui32Count)
{
  while(ui32Count--)
	{
		MAP_UART_transmitData(EUSCI_A1_BASE, *pui8Buffer);
		pui8Buffer++;
	}
}

void USART1_Send_Byte(uint8_t ch)
{
	MAP_UART_transmitData(EUSCI_A1_BASE, ch);
}

/* Current setting: 921600 bps */
const eUSCI_UART_Config uart1Config = {
		EUSCI_A_UART_CLOCKSOURCE_SMCLK,          // SMCLK Clock Source
		13,                                      // BRDIV = 13   6
		0,                                       // UCxBRF = 0   8
		0,                                       // UCxBRS = 0   32
		EUSCI_A_UART_NO_PARITY,                  // No Parity
		EUSCI_A_UART_LSB_FIRST,                  // MSB First
		EUSCI_A_UART_ONE_STOP_BIT,               // One stop bit
		EUSCI_A_UART_MODE,                       // UART mode
		EUSCI_A_UART_LOW_FREQUENCY_BAUDRATE_GENERATION
	
//#if  (Ground_Distance_Sensor==US100)		
//			EUSCI_A_UART_CLOCKSOURCE_SMCLK,          // SMCLK Clock Source
//			78,                                      // BRDIV
//			2,                                       // UCxBRF
//			0,                                       // UCxBRS
//			EUSCI_A_UART_NO_PARITY,                  // No Parity
//			EUSCI_A_UART_LSB_FIRST,                  // LSB First
//			EUSCI_A_UART_ONE_STOP_BIT,               // One stop bit
//			EUSCI_A_UART_MODE,                       // UART mode
//			EUSCI_A_UART_OVERSAMPLING_BAUDRATE_GENERATION  // Oversampling
//#else	
//			EUSCI_A_UART_CLOCKSOURCE_SMCLK,          // SMCLK Clock Source
//			6,                                       // BRDIV = 13
//			8,                                       // UCxBRF = 0
//			32,                                    // UCxBRS = 37 0X20
//			EUSCI_A_UART_NO_PARITY,                  // No Parity
//			EUSCI_A_UART_LSB_FIRST,                  // MSB First
//			EUSCI_A_UART_ONE_STOP_BIT,               // One stop bit
//			EUSCI_A_UART_MODE,                       // UART mode
//			EUSCI_A_UART_OVERSAMPLING_BAUDRATE_GENERATION  // Oversampling
//#endif
};
/***********************************************************
@��������USART1_Init
@��ڲ�������
@���ڲ�������
��������������1���ã����ϱ�עΪUART1��������921600
@���ߣ�WUST
@���ڣ�2019��01��27��
*************************************************************/
		
void USART1_Init()
{
  MAP_GPIO_setAsPeripheralModuleFunctionInputPin(GPIO_PORT_P2,
             GPIO_PIN2 | GPIO_PIN3, GPIO_PRIMARY_MODULE_FUNCTION);
	/* Configuring UART Module */
	MAP_UART_initModule(EUSCI_A1_BASE, &uart1Config);

	/* Enable UART module */
	MAP_UART_enableModule(EUSCI_A1_BASE);
	/* Enabling interrupts */
	MAP_UART_enableInterrupt(EUSCI_A1_BASE, EUSCI_A_UART_RECEIVE_INTERRUPT);  	
  MAP_Interrupt_enableInterrupt(INT_EUSCIA1);
}



///////////////////////////////////////////
void EUSCIA3_IRQHandler(void)
{
	uint32_t status = MAP_UART_getEnabledInterruptStatus(EUSCI_A3_BASE);

	if(status & EUSCI_A_UART_RECEIVE_INTERRUPT_FLAG)
	{
		RingBuf_Write(MAP_UART_receiveData(EUSCI_A3_BASE),&COM3_Rx_Buf,SDK_Target_Length*2);//�����ζ�������д����
		if(COM3_Rx_Buf.Ring_Buff[0]!=0xFF)
		{
			COM3_Rx_Buf.Head=1;
			COM3_Rx_Buf.Tail=0; 
		}		
	}
	
	
	MAP_UART_clearInterruptFlag(EUSCI_A3_BASE, status);
}


void USART3_Send(uint8_t *pui8Buffer, uint32_t ui32Count)
{
  while(ui32Count--)
	{
		MAP_UART_transmitData(EUSCI_A3_BASE, *pui8Buffer);
		pui8Buffer++;
	}
}

void USART3_Send_Byte(uint8_t ch)
{
	MAP_UART_transmitData(EUSCI_A3_BASE, ch);
}

/* Current setting: 9600 bps */
const eUSCI_UART_Config uart3Config = {
//		EUSCI_A_UART_CLOCKSOURCE_SMCLK,          // SMCLK Clock Source
//		6,                                       // BRDIV = 13
//		8,                                       // UCxBRF = 0
//		32,                                    // UCxBRS = 37 0X20
//		EUSCI_A_UART_NO_PARITY,                  // No Parity
//		EUSCI_A_UART_LSB_FIRST,                  // MSB First
//		EUSCI_A_UART_ONE_STOP_BIT,               // One stop bit
//		EUSCI_A_UART_MODE,                       // UART mode
//		EUSCI_A_UART_OVERSAMPLING_BAUDRATE_GENERATION  // Oversampling
		EUSCI_A_UART_CLOCKSOURCE_SMCLK,          // SMCLK Clock Source
		13,                                       // BRDIV = 13   6
		0,                                       // UCxBRF = 0   8
		0,                                       // UCxBRS = 0   32
		EUSCI_A_UART_NO_PARITY,                  // No Parity
		EUSCI_A_UART_LSB_FIRST,                  // MSB First
		EUSCI_A_UART_ONE_STOP_BIT,               // One stop bit
		EUSCI_A_UART_MODE,                       // UART mode
		//EUSCI_A_UART_OVERSAMPLING_BAUDRATE_GENERATION  // Oversampling
		EUSCI_A_UART_LOW_FREQUENCY_BAUDRATE_GENERATION
};
/***********************************************************
@��������USART2_Init
@��ڲ�������
@���ڲ�������
��������������2���ã����ϱ�עΪUART3��������115200
@���ߣ�WUST
@���ڣ�2019��01��27��
*************************************************************/
void USART3_Init()
{
  MAP_GPIO_setAsPeripheralModuleFunctionInputPin(GPIO_PORT_P9,
             GPIO_PIN6 | GPIO_PIN7, GPIO_PRIMARY_MODULE_FUNCTION);
	/* Configuring UART Module */
	MAP_UART_initModule(EUSCI_A3_BASE, &uart3Config);

	/* Enable UART module */
	MAP_UART_enableModule(EUSCI_A3_BASE);
	/* Enabling interrupts */
	MAP_UART_enableInterrupt(EUSCI_A3_BASE, EUSCI_A_UART_RECEIVE_INTERRUPT);  	
  MAP_Interrupt_enableInterrupt(INT_EUSCIA3);
}
/* Copyright (c)  2018-2025 Wuhan Nameless Innovation Technology Co.,Ltd. All rights reserved.*/

