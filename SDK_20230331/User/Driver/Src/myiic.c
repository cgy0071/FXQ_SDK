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
#include "myiic.h"
uint8 i2c_r=2;
const eUSCI_I2C_MasterConfig i2cConfig =
{
	EUSCI_B_I2C_CLOCKSOURCE_SMCLK,          // SMCLK Clock Source
	12000000,                                // SMCLK = 3MHz (default)
	EUSCI_B_I2C_SET_DATA_RATE_1MBPS,      // Desired I2C Clock of 100khz
	0,                                      // No byte counter threshold
	EUSCI_B_I2C_NO_AUTO_STOP                // No Autostop
};
/***********************************************************
@��������Init_I2C
@��ڲ�������
@���ڲ�������
����������MSP432���I2C��ʼ��
@���ߣ�WUST
@���ڣ�2019��01��27��
*************************************************************/
void Init_I2C(void) 
{
	GPIO_setAsOutputPin(GPIO_PORT_P6, GPIO_PIN4);
	GPIO_setAsOutputPin(GPIO_PORT_P6, GPIO_PIN5);
	delay_ms(10);
	GPIO_setOutputHighOnPin(GPIO_PORT_P6,GPIO_PIN4);
	GPIO_setOutputHighOnPin(GPIO_PORT_P6,GPIO_PIN5);
}
///////////////////////////////////////
void SDA_IOOUT(void)
{
	GPIO_setAsOutputPin(GPIO_PORT_P6,GPIO_PIN4);//SDA
}

void SDA_IOIN(void)
{
	GPIO_setAsInputPin(GPIO_PORT_P6,GPIO_PIN4);//SDA
}

//static void I2C_delay(void)
//{
//  //volatile int i = 1;	//7
//  //while (i)
//  //    i--;
//}


//**************************************
void I2C_Start(void)
{
  SDA_IOOUT();
  SCL_H;
  SDA_H;
//  I2C_delay();
  SDA_L;
//  I2C_delay();
}
//**************************************
void I2C_Stop(void)
{
  SDA_IOOUT();
  SCL_L;
//  I2C_delay();
  SDA_L;
//  I2C_delay();
  SCL_H;
//  I2C_delay();
  SDA_H;
//  I2C_delay();
}

//**************************************
unsigned char I2C_SlaveAck(void)
{
  SDA_IOOUT();
  SCL_L;
//  I2C_delay();
  SDA_H;
  
  SDA_IOIN();
//  I2C_delay();
  SCL_H;
  
//  I2C_delay();
  
  if(SDA_read)
  {
    SCL_L;
    return 0;
  }
  SCL_L;
//  I2C_delay();
  return 1;
}

//**************************************
void I2C_SendByte(unsigned char byte)
{
  unsigned char i = 8;
  SDA_IOOUT();
  while (i--)
  {
    SCL_L;
//    I2C_delay();
    if (byte & 0x80)
      SDA_H;
    else
      SDA_L;
    byte <<= 1;
//    I2C_delay();
    SCL_H;
//    I2C_delay();
  }
  SCL_L;
  if(I2C_SlaveAck()==0)
  {
    return ;
  }
}

//**************************************
unsigned char I2C_RecvByte(void)
{
  unsigned char i;
  unsigned char dat = 0;
  SDA_IOIN();
  for (i=0; i<8; i++)
  {
    dat <<= 1;
    SCL_H;
//    I2C_delay();
    dat |= SDA_read;
    SCL_L;
//    I2C_delay();
  }
  return dat;
}

//**************************************

bool OK=0;
unsigned char reg_data;
//void Single_WriteI2C(unsigned char SlaveAddress,unsigned char REG_Address,unsigned char REG_data)
//{
//	I2C_Start();
//  I2C_SendByte(SlaveAddress);
//  I2C_SendByte(REG_Address);
//  I2C_SendByte(REG_data);
//  I2C_Stop();
//}
//unsigned char Single_ReadI2C(unsigned char SlaveAddress,unsigned char REG_Address)
//{
//  unsigned char REG_data;
//  I2C_Start();
//  I2C_SendByte(SlaveAddress);
//  I2C_SendByte(REG_Address);
//  I2C_Start();
//  I2C_SendByte(SlaveAddress+1);
//  REG_data=I2C_RecvByte();
//  I2C_SlaveAck();
//  I2C_Stop();
//  return REG_data;
//}

/////////////////////////////////
//int16_t Double_ReadI2C(unsigned char SlaveAddress,unsigned char REG_Address)
//{
//  uint8_t msb , lsb ;
//  msb = Single_ReadI2C(SlaveAddress,REG_Address);
//  lsb = Single_ReadI2C(SlaveAddress,REG_Address+1);
//  return ((msb<< 8 )+ lsb) ;
//}

//unsigned long int Three_ReadI2C(unsigned char SlaveAddress,unsigned char REG_Address)
//{
//  unsigned char msb , lsb,xlsb;
//  msb = Single_ReadI2C(SlaveAddress,REG_Address);
//  lsb = Single_ReadI2C(SlaveAddress,REG_Address+1);
//  xlsb= Single_ReadI2C(SlaveAddress,REG_Address+2);
//  return (((unsigned long int)msb<< 16)|((unsigned long int)lsb<<8)|xlsb) ;
//}



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#define ack 1      //��Ӧ��
#define no_ack 0   //��Ӧ��

#define SCL1()         GPIO_setOutputHighOnPin(GPIO_PORT_P6,GPIO_PIN5)
#define SCL0()         GPIO_setOutputLowOnPin(GPIO_PORT_P6,GPIO_PIN5)
#define SDA1()         GPIO_setOutputHighOnPin(GPIO_PORT_P6,GPIO_PIN4)
#define SDA0()         GPIO_setOutputLowOnPin(GPIO_PORT_P6,GPIO_PIN4)
#define SDA      			 GPIO_getInputPinValue(GPIO_PORT_P6,GPIO_PIN4)

//-------------------------------------------------------------------------------------------------------------------
//  @brief      ģ��IIC��ʱ
//  @return     void						
//  @since      v1.0
//  Sample usage:				���IICͨѶʧ�ܿ��Գ�������j��ֵ
//-------------------------------------------------------------------------------------------------------------------
static void nc_iic_delay(void)
{
	//j=10ͨѶ���ʴ�ԼΪ100K ���ں�Ƶ��40M��
  //j=0 ͨѶ���ʴ�ԼΪ140K ���ں�Ƶ��40M��
  //uint16_t j=10;   
	//while(j--);
}

//�ڲ�ʹ�ã��û��������
void IIC_start(void)
{
	SDA1();
	SCL1();
	nc_iic_delay();
	SDA0();
	nc_iic_delay();
	SCL0();
}

//�ڲ�ʹ�ã��û��������
void IIC_stop(void)
{
	SDA0();
	SCL0();
	nc_iic_delay();
	SCL1();
	nc_iic_delay();
	SDA1();
	nc_iic_delay();
}

//��Ӧ��(����ack:SDA=0��no_ack:SDA=0)
//�ڲ�ʹ�ã��û��������
static void I2C_SendACK(unsigned char ack_dat)
{
    SCL0();
    nc_iic_delay();
		SDA_IOOUT();
    if(ack_dat) SDA0();
    else   SDA1();

    SCL1();
    nc_iic_delay();
    SCL0();
    nc_iic_delay();
}

static int WaitAck(void)
{
    SCL0();
    SDA_IOIN();
    nc_iic_delay();
    SCL1();
    nc_iic_delay();
    if(SDA)           //Ӧ��Ϊ�ߵ�ƽ���쳣��ͨ��ʧ��
    {
			SDA_IOOUT();
			SCL0();
			return 0;
    }
    SDA_IOOUT();
    SCL0();
    nc_iic_delay();
    return 1;
}

//�ֽڷ��ͳ���
//����c(����������Ҳ���ǵ�ַ)���������մ�Ӧ��
//�����Ǵ�Ӧ��λ
//�ڲ�ʹ�ã��û��������
void send_ch(uint8_t c)
{
    uint8_t i = 8;
    while(i--)
    {
        if(c & 0x80)	      SDA1();//SDA �������
        else		      SDA0();
        c <<= 1;
        nc_iic_delay();
        SCL1();                //SCL ���ߣ��ɼ��ź�
        nc_iic_delay();
        SCL0();                //SCL ʱ��������
    }
	WaitAck();
}

//�ֽڽ��ճ���
//�����������������ݣ��˳���Ӧ���|��Ӧ����|IIC_ack_main()ʹ��
//�ڲ�ʹ�ã��û��������
uint8_t read_ch(uint8_t ack_x)
{
    uint8_t i;
    uint8_t c;
    c=0;
    SCL0();
    nc_iic_delay();
    SDA1();             //��������Ϊ���뷽ʽ
    SDA_IOIN();
    for(i=0;i<8;i++)
    {
        nc_iic_delay();
        SCL0();         //��ʱ����Ϊ�ͣ�׼����������λ
        nc_iic_delay();
        SCL1();         //��ʱ����Ϊ�ߣ�ʹ��������������Ч
        nc_iic_delay();
        c<<=1;
        if(SDA) c+=1;   //������λ�������յ����ݴ�c
    }
    SDA_IOOUT();
    SCL0();
    nc_iic_delay();
    I2C_SendACK(ack_x);
	
    return c;
}


//-------------------------------------------------------------------------------------------------------------------
//  @brief      ģ��IICд���ݵ��豸�Ĵ�������
//  @param      dev_add			�豸��ַ(����λ��ַ)
//  @param      reg				�Ĵ�����ַ
//  @param      dat				д�������
//  @return     void						
//  @since      v1.0
//  Sample usage:				
//-------------------------------------------------------------------------------------------------------------------
void nc_iic_write_reg(uint8_t dev_add, uint8_t reg, uint8_t dat)
{
    IIC_start();
    send_ch( (dev_add<<1) | 0x00);   //����������ַ��дλ
    send_ch( reg );   				 //���ʹӻ��Ĵ�����ַ
    send_ch( dat );   				 //������Ҫд�������
    IIC_stop();
}
//-------------------------------------------------------------------------------------------------------------------
//  @brief      ģ��IIC���豸�Ĵ�����ȡ����
//  @param      dev_add			�豸��ַ(����λ��ַ)
//  @param      reg				�Ĵ�����ַ
//  @param      type			ѡ��ͨ�ŷ�ʽ��IIC  ���� SCCB
//  @return     uint8_t			���ؼĴ���������			
//  @since      v1.0
//  Sample usage:				
//-------------------------------------------------------------------------------------------------------------------
uint8_t nc_iic_read_reg(uint8_t dev_add, uint8_t reg)
{
    uint8_t dat;
    IIC_start();
    send_ch( (dev_add<<1) | 0x00);  //����������ַ��дλ
    send_ch( reg );   				//���ʹӻ��Ĵ�����ַ
	
	IIC_start();
	send_ch( (dev_add<<1) | 0x01);  //����������ַ�Ӷ�λ
	dat = read_ch(no_ack);   				//������Ҫд�������
	IIC_stop();
	
	return dat;
}
//  @brief      ģ��IIC��ȡ���ֽ�����
//  @param      dev_add			�豸��ַ(����λ��ַ)
//  @param      reg				�Ĵ�����ַ
//  @param      dat_add			���ݱ���ĵ�ַָ��
//  @param      num				��ȡ�ֽ�����
//  @param      type			ѡ��ͨ�ŷ�ʽ��IIC  ���� SCCB
//  @return     uint8			���ؼĴ���������			
//  @since      v1.0
//  Sample usage:				
//-------------------------------------------------------------------------------------------------------------------
void nc_iic_read_regs(uint8_t dev_add, uint8_t reg, uint8_t *dat_add, uint8_t num)
{
	IIC_start();
    send_ch( (dev_add<<1) | 0x00);  //����������ַ��дλ
	send_ch( reg );   				//���ʹӻ��Ĵ�����ַ
	
	
	IIC_start();
	send_ch( (dev_add<<1) | 0x01);  //����������ַ�Ӷ�λ
    while(--num)
    {
        *dat_add = read_ch(ack); //��ȡ����
        dat_add++;
    }
    *dat_add = read_ch(no_ack); //��ȡ����
	IIC_stop();
}
//-------------------------------------------------------------------------------------------------------------------
//  @brief      ģ��IIC�˿ڳ�ʼ��
//  @param      NULL
//  @return     void	
//  @since      v1.0
//  Sample usage:				
//-------------------------------------------------------------------------------------------------------------------

uint8_t nc_iic_read_len(uint8_t dev_add, uint8_t reg, uint8_t len, uint8_t *dat)
{
	uint8_t i;

	IIC_start();
    send_ch( (dev_add<<1) | 0x00);  //����������ַ��дλ
	send_ch( reg );   				//���ʹӻ��Ĵ�����ַ
	IIC_start();
	send_ch( (dev_add<<1) | 0x01);  //����������ַ�Ӷ�λ
	for (i = 0; i < len-1; i++)
	{
		dat[i] = read_ch(1);	//������Ҫд�������
	}
	dat[i] = read_ch(0);	//������Ҫд�������
	IIC_stop();
	
	return 0;
}



uint8_t nc_iic_write_len(uint8_t dev_add, uint8_t reg, uint8_t len,uint8_t  *dat)
{
	uint8_t i;
	
	IIC_start();
    send_ch( (dev_add<<1) | 0x00);   //����������ַ��дλ
	send_ch( reg );   				 //���ʹӻ��Ĵ�����ַ
	for (i = 0; i < len; i++)
	{
		send_ch(dat[i]);   				 //������Ҫд�������
	}
	IIC_stop();
	
	return 0;
}


void Single_WriteI2C(unsigned char SlaveAddress,unsigned char REG_Address,unsigned char REG_data)
{
	nc_iic_write_reg(SlaveAddress,REG_Address,REG_data);
}

unsigned char Single_ReadI2C(unsigned char SlaveAddress,unsigned char REG_Address)
{
	return nc_iic_read_reg(SlaveAddress,REG_Address);
}

///////////////////////////////
int16_t Double_ReadI2C(unsigned char SlaveAddress,unsigned char REG_Address)
{
	uint8_t buf[2];
	nc_iic_read_len(SlaveAddress,REG_Address,2,buf);
  return ((buf[0]<< 8 )+ buf[1]) ;
}

unsigned long int Three_ReadI2C(unsigned char SlaveAddress,unsigned char REG_Address)
{
	uint8_t buf[3];
	nc_iic_read_len(SlaveAddress,REG_Address,3,buf);
  return (((unsigned long int)buf[2]<< 16)|((unsigned long int)buf[1]<<8)|buf[0]) ;
}

void Nbyte_ReadI2C(unsigned char SlaveAddress,unsigned char REG_Address,uint16_t N,uint8_t *buf)
{
	nc_iic_read_len(SlaveAddress,REG_Address,N,buf);
}




















static void I2C_Delay_Adjust(void)
{
  volatile int i = 1;	//7
  while (i)
    i--;
}


//**************************************
void I2C_Start_Adjust(void)
{
  SDA_IOOUT();
  SCL_H;
  SDA_H;
  I2C_Delay_Adjust();
  SDA_L;
  I2C_Delay_Adjust();
}
//**************************************
void I2C_Stop_Adjust(void)
{
  SDA_IOOUT();
  SCL_L;
  I2C_Delay_Adjust();
  SDA_L;
  I2C_Delay_Adjust();
  SCL_H;
  I2C_Delay_Adjust();
  SDA_H;
  I2C_Delay_Adjust();
}

//**************************************
unsigned char I2C_SlaveAck_Adjust(void)
{
  SDA_IOOUT();
  SCL_L;
  I2C_Delay_Adjust();
  SDA_H;
  
  SDA_IOIN();
  I2C_Delay_Adjust();
  SCL_H;
  
  I2C_Delay_Adjust();
  
  if(SDA_read)
  {
    SCL_L;
    return 0;
  }
  SCL_L;
  I2C_Delay_Adjust();
  return 1;
}

//**************************************
void I2C_SendByte_Adjust(unsigned char byte)
{
  unsigned char i = 8;
  SDA_IOOUT();
  while (i--)
  {
    SCL_L;
    I2C_Delay_Adjust();
    if (byte & 0x80)
      SDA_H;
    else
      SDA_L;
    byte <<= 1;
    I2C_Delay_Adjust();
    SCL_H;
    I2C_Delay_Adjust();
  }
  SCL_L;
  if(I2C_SlaveAck_Adjust()==0)
  {
    return ;
  }
}

//**************************************
unsigned char I2C_RecvByte_Adjust(void)
{
  unsigned char i;
  unsigned char dat = 0;
  SDA_IOIN();
  for (i=0; i<8; i++)
  {
    dat <<= 1;
    SCL_H;
    I2C_Delay_Adjust();
    dat |= SDA_read;
    SCL_L;
    I2C_Delay_Adjust();
  }
  return dat;
}

//**************************************
void Single_WriteI2C_Adjust(unsigned char SlaveAddress,unsigned char REG_Address,unsigned char REG_data)
{
	MAP_I2C_setSlaveAddress(EUSCI_B1_BASE, SlaveAddress>>1);
	while (MAP_I2C_masterIsStopSent(EUSCI_B1_BASE));
	/* Send out EEPROM Mock Read Cmd (2 databytes) */
	MAP_I2C_masterSendMultiByteStart(EUSCI_B1_BASE, REG_Address);  // Start + 1Byte
	MAP_I2C_masterSendMultiByteFinish(EUSCI_B1_BASE, REG_data); // Poll for TXINT,Send 1Byte
}

//**************************************
unsigned char Single_ReadI2C_Adjust(unsigned char SlaveAddress,unsigned char REG_Address)
{
  unsigned char REG_data;
	OK=0;
	MAP_I2C_setSlaveAddress(EUSCI_B1_BASE, SlaveAddress>>1);
	while (MAP_I2C_masterIsStopSent(EUSCI_B1_BASE));
	/* Send out EEPROM Mock Read Cmd (2 databytes) */
	MAP_I2C_masterSendMultiByteStart(EUSCI_B1_BASE, REG_Address);  // Start + 1Byte
	/* Now we need to initiate the read */
	/* Wait until 2nd Byte has been output to shift register */
	while(!(EUSCI_B1->IFG & EUSCI_B_IFG_TXIFG0));
	// Send the restart condition, read one byte, send the stop condition right away
	EUSCI_B1->CTLW0 &= ~(EUSCI_B_CTLW0_TR);
	EUSCI_B1->CTLW0 |= EUSCI_B_CTLW0_TXSTT;
	while(MAP_I2C_masterIsStartSent(EUSCI_B1_BASE));
	EUSCI_B1->CTLW0 |= EUSCI_B_CTLW0_TXSTP;
	while(!OK);
	REG_data=reg_data;
  return REG_data;
}

unsigned short int Double_ReadI2C_Adjust(unsigned char SlaveAddress,unsigned char REG_Address)
{
  unsigned char msb , lsb ;
  msb = Single_ReadI2C_Adjust(SlaveAddress,REG_Address);
  lsb = Single_ReadI2C_Adjust(SlaveAddress,REG_Address+1);
  return ( ((unsigned short int)msb) << 8 | lsb) ;
}

unsigned long int Three_ReadI2C_Adjust(unsigned char SlaveAddress,unsigned char REG_Address)
{
  unsigned char msb , lsb,xlsb;
  msb = Single_ReadI2C_Adjust(SlaveAddress,REG_Address);
  lsb = Single_ReadI2C_Adjust(SlaveAddress,REG_Address+1);
  xlsb= Single_ReadI2C_Adjust(SlaveAddress,REG_Address+2);
  return (((unsigned long int)msb<< 16)|((unsigned long int)lsb<<8)|xlsb) ;
}
void EUSCIB1_IRQHandler(void)
{
    uint_fast16_t status;

    status = MAP_I2C_getEnabledInterruptStatus(EUSCI_B1_BASE);
    MAP_I2C_clearInterruptFlag(EUSCI_B1_BASE, status);

    /* Receives bytes into the receive buffer. If we have received all bytes,
     * send a STOP condition */
    if (status & EUSCI_B_I2C_RECEIVE_INTERRUPT0)
    {
        // One-byte Read
			reg_data = MAP_I2C_masterReceiveSingle(EUSCI_B1_BASE);
			OK=1;
			
    }
}

/* Copyright (c)  2018-2025 Wuhan Nameless Innovation Technology Co.,Ltd. All rights reserved.*/

