#include "Headfile.h"
#include "My_task.h"
float Value10=0;
extern int sdk_cnt;

uint8_t find_black(uint16_t transition_time,SDK_Status *Status,uint16_t number)
{
	Flight_Alt_Hold_Control(ALTHOLD_AUTO_POS_CTRL, SDK_HEIGHT, 0);//高度控制
//  OpticalFlow_Control_Pure(0);//不需要光流定点
	
	static uint8_t bling_flag=1;
	static uint16_t makesure_cnt=0;
	
		if(Status->Status[number].Start_Flag==1
     &&Status->Status[number].Execute_Flag==1
       &&Status->Status[number].End_flag==1)
		{
//				if(bling_flag==1)
//				{
//					Bling_Set(&Light_1,3000,1000,0.5,0,GPIO_PORT_P5,GPIO_PIN6,0);
//					bling_flag=0;
//				}
			OpticalFlow_Control_Pure(0);
			return 1;
		}
	 else
		{		
			Color_Block_Control_Pliot();//色块识别
			
			
		  if(Status->Status[number].Start_Flag==0) //初始
      {  
				
        Status->Status[number].Start_Flag=1;
      }
			Value10=pythagorous2((Total_Controller.SDK_Roll_Position_Control.FeedBack-Total_Controller.SDK_Roll_Position_Control.Expect),
											(Total_Controller.SDK_Pitch_Position_Control.FeedBack-Total_Controller.SDK_Pitch_Position_Control.Expect));
			
				if(pythagorous2((Total_Controller.SDK_Roll_Position_Control.FeedBack-Total_Controller.SDK_Roll_Position_Control.Expect),
											(Total_Controller.SDK_Pitch_Position_Control.FeedBack-Total_Controller.SDK_Pitch_Position_Control.Expect))<=6.0f
													&&Opv_Top_View_Target.flag
														//&&(Total_Controller.SDK_Roll_Position_Control.FeedBack!=0||Total_Controller.SDK_Pitch_Position_Control.FeedBack!=0)
				)//完成任务
				{
					makesure_cnt++;
					Flag3=makesure_cnt;
					if(makesure_cnt>=100)//
					{
						makesure_cnt=0;
						Status->Status[number].Execute_Flag=1;
						Status->Status[number].End_flag=1;
							
						Status->Transition_Time[number]=transition_time;//200*5=1秒
							
						OpticalFlow_Control_Pure(1);//完成之后，进行光流悬停
						OpticalFlow_Pos_Ctrl_Expect.x=0;
						OpticalFlow_Pos_Ctrl_Expect.y=0;
						return 1;			
					}
					else
					{
					Status->Status[number].Execute_Flag=1; 
					return 0;
					}				
				}
				else
				{
					Status->Status[number].Execute_Flag=1; 
					return 0;
				}

		}
}

