#ifndef __MPUIIC_H
#define __MPUIIC_H
#include "Headfile.h"




//IIC所有操作函数
void SOFT_IIC_Delay(void);				  //MPU IIC延时函数
void IIC_Init(void);				  //初始化IIC的IO口
void SOFT_IIC_Start(void);				  //发送IIC开始信号
void SOFT_IIC_Stop(void);				  //发送IIC停止信号
void SOFT_IIC_Send_Byte(u8 txd);		  //IIC发送一个字节
u8 SOFT_IIC_Read_Byte(unsigned char ack); //IIC读取一个字节
u8 SOFT_IIC_Wait_Ack(void);				  //IIC等待ACK信号
void SOFT_IIC_Ack(void);				  //IIC发送ACK信号
void SOFT_IIC_NAck(void);				  //IIC不发送ACK信号

#endif
