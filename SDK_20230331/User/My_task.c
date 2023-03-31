#include "Headfile.h"
#include "My_task.h"
float Value10=0;
extern int sdk_cnt;

uint8_t find_black(uint16_t transition_time,SDK_Status *Status,uint16_t number)
{
	Flight_Alt_Hold_Control(ALTHOLD_AUTO_POS_CTRL, SDK_HEIGHT, 0);//高度控制
//  OpticalFlow_Control_Pure(0);//不需要光流定点
	
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





uint8_t move_xy_find(float pos_x_target,float pos_y_target,SDK_Status *Status,uint16_t number)
{
	static float r_distance = 0;
	static uint16_t makesure_cnt=0;
  //static Vector2f pos_base;
  //ncq_control_althold();//高度控制依然进行
	Flight_Alt_Hold_Control(ALTHOLD_AUTO_POS_CTRL, 150, 0);
  if(Status->Status[number].Start_Flag==0) 
  {
    //pos_base.x=OpticalFlow_SINS.Position[_PITCH];
    //pos_base.y=OpticalFlow_SINS.Position[_ROLL];
    OpticalFlow_Pos_Ctrl_Expect.x=OpticalFlow_SINS.Position[_PITCH]+pos_x_target;
    OpticalFlow_Pos_Ctrl_Expect.y=OpticalFlow_SINS.Position[_ROLL]+pos_y_target;
    Status->Status[number].Start_Flag=1;
  }
  
  if(Status->Status[number].Start_Flag==1
     &&Status->Status[number].Execute_Flag==1
       &&Status->Status[number].End_flag==1)
  {
     OpticalFlow_Control_Pure(0);//完成之后，进行光流悬停
     return 1;
  }
  else
  {    
		r_distance = pythagorous2(OpticalFlow_Pos_Ctrl_Expect.x-OpticalFlow_SINS.Position[_PITCH],
                    OpticalFlow_Pos_Ctrl_Expect.y-OpticalFlow_SINS.Position[_ROLL]);
    if(r_distance<=5.0f)
    {
      Status->Status[number].Execute_Flag=1;
      Status->Status[number].End_flag=1;
      //pos_base.x=0;
      //pos_base.y=0;
//      OpticalFlow_Pos_Ctrl_Expect.x=0;
//      OpticalFlow_Pos_Ctrl_Expect.y=0;
      Status->Transition_Time[number]=300;
      OpticalFlow_Control_Pure(1);//完成之后，进行光流悬停
//      OpticalFlow_Pos_Ctrl_Expect.x=0;
//      OpticalFlow_Pos_Ctrl_Expect.y=0;
      return 1;
    }
		else if(Opv_Top_View_Target.flag && r_distance <= 30.0f)
		{
			makesure_cnt++;
			if(makesure_cnt>5)
			{
				Status->Status[number].Execute_Flag=1;
				Status->Status[number].End_flag=1;
				Status->Transition_Time[number]=20;
				OpticalFlow_Control_Pure(1);//完成之后，进行光流悬停
				return 1;
			}
		}
    else
    { 
      Status->Status[number].Execute_Flag=1; 
      OpticalFlow_Pos_Control();//光流位置控制
      OpticalFlow_Vel_Control(OpticalFlow_Pos_Ctrl_Output);//光流速度控制 
      return 0;
    }
  }
}

