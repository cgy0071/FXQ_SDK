#ifndef __MPUIIC_H
#define __MPUIIC_H
#include "Headfile.h"




//IIC���в�������
void SOFT_IIC_Delay(void);				  //MPU IIC��ʱ����
void IIC_Init(void);				  //��ʼ��IIC��IO��
void SOFT_IIC_Start(void);				  //����IIC��ʼ�ź�
void SOFT_IIC_Stop(void);				  //����IICֹͣ�ź�
void SOFT_IIC_Send_Byte(u8 txd);		  //IIC����һ���ֽ�
u8 SOFT_IIC_Read_Byte(unsigned char ack); //IIC��ȡһ���ֽ�
u8 SOFT_IIC_Wait_Ack(void);				  //IIC�ȴ�ACK�ź�
void SOFT_IIC_Ack(void);				  //IIC����ACK�ź�
void SOFT_IIC_NAck(void);				  //IIC������ACK�ź�

#endif
