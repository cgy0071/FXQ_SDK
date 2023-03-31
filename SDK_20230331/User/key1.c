#include "Headfile.h"
#include "key1.h"
#include "time.h"


int zuobiao1_x,zuobiao2_x,zuobiao1_y,zuobiao2_y,cnt;

void Key1_Init()
{
    GPIO_setAsOutputPin(GPIO_PORT_P8,GPIO_PIN5);
	GPIO_setAsOutputPin(GPIO_PORT_P9,GPIO_PIN0);
	GPIO_setAsOutputPin(GPIO_PORT_P8,GPIO_PIN4);
	GPIO_setAsOutputPin(GPIO_PORT_P6,GPIO_PIN2);



    GPIO_setAsInputPin(GPIO_PORT_P7,GPIO_PIN3);
	GPIO_setAsInputPin(GPIO_PORT_P7,GPIO_PIN1);
	GPIO_setAsInputPin(GPIO_PORT_P8,GPIO_PIN6);
	GPIO_setAsInputPin(GPIO_PORT_P8,GPIO_PIN7);


    /*
	GPIO_setAsOutputPin(GPIO_PORT_P4,GPIO_PIN1);  R1 R2 R3 R4:8.5 9.0 8.4 6.2    C1 C2 C3 C4:  7.3 7.1 8.6 8.7
    GPIO_setAsOutputPin(GPIO_PORT_P4,GPIO_PIN3);

    GPIO_setAsInputPin(GPIO_PORT_P1,GPIO_PIN5);
    GPIO_setAsInputPin(GPIO_PORT_P4,GPIO_PIN6);
    GPIO_setAsInputPin(GPIO_PORT_P6,GPIO_PIN5);
    GPIO_setAsInputPin(GPIO_PORT_P6,GPIO_PIN4);
    */

    GPIO_setAsInputPinWithPullDownResistor(GPIO_PORT_P7,GPIO_PIN3);
	GPIO_setAsInputPinWithPullDownResistor(GPIO_PORT_P7,GPIO_PIN1);
	GPIO_setAsInputPinWithPullDownResistor(GPIO_PORT_P8,GPIO_PIN6);
	GPIO_setAsInputPinWithPullDownResistor(GPIO_PORT_P8,GPIO_PIN7);

	GPIO_setOutputHighOnPin(GPIO_PORT_P8,GPIO_PIN5);
	GPIO_setOutputHighOnPin(GPIO_PORT_P9,GPIO_PIN0);
	GPIO_setOutputHighOnPin(GPIO_PORT_P8,GPIO_PIN4);
	GPIO_setOutputHighOnPin(GPIO_PORT_P6,GPIO_PIN2);


    

}


int Matrix_Key_Scan()
{
	//u8 temp = 0;
	uint16_t key_val=-1;
	//GPIO_ResetBits(GPIOB,GPIO_Pin_8|GPIO_Pin_9|GPIO_Pin_10|GPIO_Pin_11);			//拉低行线
    extern int cnt;
    extern int zuobiao1_x;
    extern int zuobiao1_y;
    extern int zuobiao2_x;
    extern int zuobiao2_y;
    
	Delay_Us(10);
 
	//temp=(GPIO_ReadInputData(GPIOB) >> 8)&0xff;	
	
	//没有按键按下时扫描
	if (GPIO_getInputPinValue(GPIO_PORT_P7,GPIO_PIN3)==0
		   &GPIO_getInputPinValue(GPIO_PORT_P7,GPIO_PIN1)==0
	      &GPIO_getInputPinValue(GPIO_PORT_P8,GPIO_PIN6)==0
	       &GPIO_getInputPinValue(GPIO_PORT_P8,GPIO_PIN7)==0) 
	{
            if(cnt<=11)
            {
                Delay_Ms(300); 

                //GPIO_ResetBits(GPIOB,GPIO_Pin_8|GPIO_Pin_9|GPIO_Pin_10|GPIO_Pin_11);			//拉低行线


                Delay_Us(10);


            }
			
			//temp=(GPIO_ReadInputData(GPIOB) >> 8)&0xff;	
		
			if (~(GPIO_getInputPinValue(GPIO_PORT_P7,GPIO_PIN3)==0
		      	 &GPIO_getInputPinValue(GPIO_PORT_P7,GPIO_PIN1)==0
				      &GPIO_getInputPinValue(GPIO_PORT_P8,GPIO_PIN6)==0
			         &GPIO_getInputPinValue(GPIO_PORT_P8,GPIO_PIN7)==0) ) //按键按下时，对键值进行赋值
			{
				//第一行
				
				if(GPIO_getInputPinValue(GPIO_PORT_P7,GPIO_PIN3)==1)
				{
						Delay_Ms(20);//消抖
 
						if(GPIO_getInputPinValue(GPIO_PORT_P7,GPIO_PIN3)==1)
						{
							GPIO_setOutputLowOnPin(GPIO_PORT_P8,GPIO_PIN5);
							GPIO_setOutputHighOnPin(GPIO_PORT_P9,GPIO_PIN0);
							GPIO_setOutputHighOnPin(GPIO_PORT_P8,GPIO_PIN4);
							GPIO_setOutputHighOnPin(GPIO_PORT_P6,GPIO_PIN2);
							if(GPIO_getInputPinValue(GPIO_PORT_P7,GPIO_PIN3)==0)
							{
                                //one[0]=9;
								key_val=1;
							}
							GPIO_setOutputHighOnPin(GPIO_PORT_P8,GPIO_PIN5);
							GPIO_setOutputLowOnPin(GPIO_PORT_P9,GPIO_PIN0);
							GPIO_setOutputHighOnPin(GPIO_PORT_P8,GPIO_PIN4);
							GPIO_setOutputHighOnPin(GPIO_PORT_P6,GPIO_PIN2);
							if(GPIO_getInputPinValue(GPIO_PORT_P7,GPIO_PIN3)==0)
							{
								key_val=4;
							}
							GPIO_setOutputHighOnPin(GPIO_PORT_P8,GPIO_PIN5);
							GPIO_setOutputHighOnPin(GPIO_PORT_P9,GPIO_PIN0);
							GPIO_setOutputLowOnPin(GPIO_PORT_P8,GPIO_PIN4);
							GPIO_setOutputHighOnPin(GPIO_PORT_P6,GPIO_PIN2);
							if(GPIO_getInputPinValue(GPIO_PORT_P7,GPIO_PIN3)==0)
							{
								key_val=7;
							}
							GPIO_setOutputHighOnPin(GPIO_PORT_P8,GPIO_PIN5);
							GPIO_setOutputHighOnPin(GPIO_PORT_P9,GPIO_PIN0);
							GPIO_setOutputHighOnPin(GPIO_PORT_P8,GPIO_PIN4);
							GPIO_setOutputHighOnPin(GPIO_PORT_P6,GPIO_PIN2);
                            //one[0]=key_val;
                            if(cnt==0)
                            {
                               zuobiao1_x=zuobiao1_x+key_val*100;
                            }
                            else if(cnt==1)
                            {
                                zuobiao1_x=zuobiao1_x+key_val*10;
                            }
                            else if(cnt==2)
                            {
                                zuobiao1_x=zuobiao1_x+key_val*1;
                            }
                            else if(cnt==3)
                            {
                                zuobiao1_y=zuobiao1_y+key_val*100;
                            }
                            else if(cnt==4)
                            {
                                zuobiao1_y=zuobiao1_y+key_val*10;
                            }
                            else if(cnt==5)
                            {
                                zuobiao1_y=zuobiao1_y+key_val*1;
                            }
                            else if(cnt==6)
                            {
                               zuobiao2_x=zuobiao2_x+key_val*100;
                            }
                            else if(cnt==7)
                            {
                                zuobiao2_x=zuobiao2_x+key_val*10;
                            }
                            else if(cnt==8)
                            {
                                zuobiao2_x=zuobiao2_x+key_val*1;
                            }
                            else if(cnt==9)
                            {
                                zuobiao2_y=zuobiao2_y+key_val*100;
                            }
                            else if(cnt==10)
                            {
                                zuobiao2_y=zuobiao2_y+key_val*10;
                            }
                            else if(cnt==11)
                            {
                                zuobiao2_y=zuobiao2_y+key_val*1;
                            }
                            cnt=cnt+1;
						}
				}


				else if(GPIO_getInputPinValue(GPIO_PORT_P7,GPIO_PIN1)==1)
				{
					Delay_Ms(20);//消抖
 
						if(GPIO_getInputPinValue(GPIO_PORT_P7,GPIO_PIN1)==1)
						{
							GPIO_setOutputLowOnPin(GPIO_PORT_P8,GPIO_PIN5);
							GPIO_setOutputHighOnPin(GPIO_PORT_P9,GPIO_PIN0);
							GPIO_setOutputHighOnPin(GPIO_PORT_P8,GPIO_PIN4);
							GPIO_setOutputHighOnPin(GPIO_PORT_P6,GPIO_PIN2);
							if(GPIO_getInputPinValue(GPIO_PORT_P7,GPIO_PIN1)==0)
							{
								key_val=2;
							}
							GPIO_setOutputHighOnPin(GPIO_PORT_P8,GPIO_PIN5);
							GPIO_setOutputLowOnPin(GPIO_PORT_P9,GPIO_PIN0);
							GPIO_setOutputHighOnPin(GPIO_PORT_P8,GPIO_PIN4);
							GPIO_setOutputHighOnPin(GPIO_PORT_P6,GPIO_PIN2);
							if(GPIO_getInputPinValue(GPIO_PORT_P7,GPIO_PIN1)==0)
							{
								key_val=5;
							}
							GPIO_setOutputHighOnPin(GPIO_PORT_P8,GPIO_PIN5);
							GPIO_setOutputHighOnPin(GPIO_PORT_P9,GPIO_PIN0);
							GPIO_setOutputLowOnPin(GPIO_PORT_P8,GPIO_PIN4);
							GPIO_setOutputHighOnPin(GPIO_PORT_P6,GPIO_PIN2);
							if(GPIO_getInputPinValue(GPIO_PORT_P7,GPIO_PIN1)==0)
							{
								key_val=8;
							}
							GPIO_setOutputHighOnPin(GPIO_PORT_P8,GPIO_PIN5);
							GPIO_setOutputHighOnPin(GPIO_PORT_P9,GPIO_PIN0);
							GPIO_setOutputHighOnPin(GPIO_PORT_P8,GPIO_PIN4);
							GPIO_setOutputLowOnPin(GPIO_PORT_P6,GPIO_PIN2);
							if(GPIO_getInputPinValue(GPIO_PORT_P7,GPIO_PIN1)==0)
							{
								key_val=0;
							}
							GPIO_setOutputHighOnPin(GPIO_PORT_P8,GPIO_PIN5);
							GPIO_setOutputHighOnPin(GPIO_PORT_P9,GPIO_PIN0);
							GPIO_setOutputHighOnPin(GPIO_PORT_P8,GPIO_PIN4);
							GPIO_setOutputHighOnPin(GPIO_PORT_P6,GPIO_PIN2);
                            if(cnt==0)
                            {
                               zuobiao1_x=zuobiao1_x+key_val*100;
                            }
                            else if(cnt==1)
                            {
                                zuobiao1_x=zuobiao1_x+key_val*10;
                            }
                            else if(cnt==2)
                            {
                                zuobiao1_x=zuobiao1_x+key_val*1;
                            }
                            else if(cnt==3)
                            {
                                zuobiao1_y=zuobiao1_y+key_val*100;
                            }
                            else if(cnt==4)
                            {
                                zuobiao1_y=zuobiao1_y+key_val*10;
                            }
                            else if(cnt==5)
                            {
                                zuobiao1_y=zuobiao1_y+key_val*1;
                            }
                            else if(cnt==6)
                            {
                               zuobiao2_x=zuobiao2_x+key_val*100;
                            }
                            else if(cnt==7)
                            {
                                zuobiao2_x=zuobiao2_x+key_val*10;
                            }
                            else if(cnt==8)
                            {
                                zuobiao2_x=zuobiao2_x+key_val*1;
                            }
                            else if(cnt==9)
                            {
                                zuobiao2_y=zuobiao2_y+key_val*100;
                            }
                            else if(cnt==10)
                            {
                                zuobiao2_y=zuobiao2_y+key_val*10;
                            }
                            else if(cnt==11)
                            {
                                zuobiao2_y=zuobiao2_y+key_val*1;
                            }
                            cnt=cnt+1;

						}

				}

				else if(GPIO_getInputPinValue(GPIO_PORT_P8,GPIO_PIN6)==1)
				{
					Delay_Ms(20);//消抖
 
						if(GPIO_getInputPinValue(GPIO_PORT_P8,GPIO_PIN6)==1)
						{
							GPIO_setOutputLowOnPin(GPIO_PORT_P8,GPIO_PIN5);
							GPIO_setOutputHighOnPin(GPIO_PORT_P9,GPIO_PIN0);
							GPIO_setOutputHighOnPin(GPIO_PORT_P8,GPIO_PIN4);
							GPIO_setOutputHighOnPin(GPIO_PORT_P6,GPIO_PIN2);
							if(GPIO_getInputPinValue(GPIO_PORT_P8,GPIO_PIN6)==0)
							{
								key_val=3;
							}
							GPIO_setOutputHighOnPin(GPIO_PORT_P8,GPIO_PIN5);
							GPIO_setOutputLowOnPin(GPIO_PORT_P9,GPIO_PIN0);
							GPIO_setOutputHighOnPin(GPIO_PORT_P8,GPIO_PIN4);
							GPIO_setOutputHighOnPin(GPIO_PORT_P6,GPIO_PIN2);
							if(GPIO_getInputPinValue(GPIO_PORT_P8,GPIO_PIN6)==0)
							{
								key_val=6;
							}
							GPIO_setOutputHighOnPin(GPIO_PORT_P8,GPIO_PIN5);
							GPIO_setOutputHighOnPin(GPIO_PORT_P9,GPIO_PIN0);
							GPIO_setOutputLowOnPin(GPIO_PORT_P8,GPIO_PIN4);
							GPIO_setOutputHighOnPin(GPIO_PORT_P6,GPIO_PIN2);
							if(GPIO_getInputPinValue(GPIO_PORT_P8,GPIO_PIN6)==0)
							{
								key_val=9;
							}

							GPIO_setOutputHighOnPin(GPIO_PORT_P8,GPIO_PIN5);
							GPIO_setOutputHighOnPin(GPIO_PORT_P9,GPIO_PIN0);
							GPIO_setOutputHighOnPin(GPIO_PORT_P8,GPIO_PIN4);
							GPIO_setOutputHighOnPin(GPIO_PORT_P6,GPIO_PIN2);
                            if(cnt==0)
                            {
                               zuobiao1_x=zuobiao1_x+key_val*100;
                            }
                            else if(cnt==1)
                            {
                                zuobiao1_x=zuobiao1_x+key_val*10;
                            }
                            else if(cnt==2)
                            {
                                zuobiao1_x=zuobiao1_x+key_val*1;
                            }
                            else if(cnt==3)
                            {
                                zuobiao1_y=zuobiao1_y+key_val*100;
                            }
                            else if(cnt==4)
                            {
                                zuobiao1_y=zuobiao1_y+key_val*10;
                            }
                            else if(cnt==5)
                            {
                                zuobiao1_y=zuobiao1_y+key_val*1;
                            }
                            else if(cnt==6)
                            {
                               zuobiao2_x=zuobiao2_x+key_val*100;
                            }
                            else if(cnt==7)
                            {
                                zuobiao2_x=zuobiao2_x+key_val*10;
                            }
                            else if(cnt==8)
                            {
                                zuobiao2_x=zuobiao2_x+key_val*1;
                            }
                            else if(cnt==9)
                            {
                                zuobiao2_y=zuobiao2_y+key_val*100;
                            }
                            else if(cnt==10)
                            {
                                zuobiao2_y=zuobiao2_y+key_val*10;
                            }
                            else if(cnt==11)
                            {
                                zuobiao2_y=zuobiao2_y+key_val*1;
                            }
                            cnt=cnt+1;
							
						}

				}
				
				}
			}
			
	
	return key_val;
 
}

//void opv_modeselect()
//{
//  extern int zuobiao1_x;
//  extern int zuobiao1_y;
//  extern int zuobiao2_x;
//  extern int zuobiao2_y;
//  extern int opv_mode1;
//  extern int opv_mode2;
//	
//	//坐标1的opv模式选择
//  if((zuobiao1_x==350&&zuobiao1_y==275)||(zuobiao1_x==275&&zuobiao1_y==50))  opv_mode1=1;
//  if((zuobiao1_x==125&&zuobiao1_y==50)||(zuobiao1_x==125&&zuobiao1_y==200))  opv_mode1=2;
//	if((zuobiao1_x==50&&zuobiao1_y==125)||(zuobiao1_x==200&&zuobiao1_y==-25))  opv_mode1=3;
//	if((zuobiao1_x==200&&zuobiao1_y==275)||(zuobiao1_x==350&&zuobiao1_y==125)) opv_mode1=4;
//	if((zuobiao1_x==50&&zuobiao1_y==275)||(zuobiao1_x==200&&zuobiao1_y==125))  opv_mode1=5;
//	if((zuobiao1_x==275&&zuobiao1_y==200)||(zuobiao1_x==350&&zuobiao1_y==-25)) opv_mode1=6;

//	
//	
//	//坐标2的opv模式选择	
//	if((zuobiao2_x==350&&zuobiao2_y==275)||(zuobiao2_x==275&&zuobiao2_y==50))  opv_mode2=1;
//  if((zuobiao2_x==125&&zuobiao2_y==50)||(zuobiao2_x==125&&zuobiao2_y==200))  opv_mode2=2;
//	if((zuobiao2_x==50&&zuobiao2_y==125)||(zuobiao2_x==200&&zuobiao2_y==-25))  opv_mode2=3;
//	if((zuobiao2_x==200&&zuobiao2_y==275)||(zuobiao2_x==350&&zuobiao2_y==125)) opv_mode2=4;
//	if((zuobiao2_x==50&&zuobiao2_y==275)||(zuobiao2_x==200&&zuobiao2_y==125))  opv_mode2=5;
//	if((zuobiao2_x==275&&zuobiao2_y==200)||(zuobiao2_x==350&&zuobiao2_y==-25)) opv_mode2=6;
//	
//}
