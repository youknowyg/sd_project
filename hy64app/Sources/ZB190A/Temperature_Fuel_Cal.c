
#include "main.h"
#include "Temperature_Fuel_Cal.h"




unsigned char Fuel_ge;
unsigned char sw_ge;

static unsigned long int temp_a,temp_b;
									/* 40°  */
const unsigned char  temp_dial[10]={ 0, 80, 96,104,120,128,144,152,160,170};
const unsigned int temp_angle[10]={ 0,288,576,288,576,288,576,288,288,3};

//const unsigned int  fuel_dial[12]={ 730, 699,  682,  644,  596, 558, 498, 421, 383, 341, 0};
//const unsigned int fuel_angle[12]={   0, 288,  288,  288,  288, 288, 288, 288, 288, 200,  0};
const unsigned int  fuel_dial[10]={ 90, 93,  236,  485, 658, 670};
const unsigned int fuel_angle[10]={  0,288, 288,  1125,1140, 10};

const unsigned int  fuel_step[12]={   0, 288,  576,  864, 1152, 1440,1728,2016,2304, 2504,0};
const unsigned int fuel_meter[12]={   0,7000, 8000, 6500, 6000, 5500,7000,6000,5500, 3500, 0};




static void Calculate_Temperature_Display(void)
{
    unsigned char temp_char;
	
	temp_char=(unsigned char)(sms_new/288);
	if(temp_char<sw_ge)
	{
		temp_char=(unsigned char)((sms_new+10)/288);
	}
	
	if(sw_ge!=temp_char)
	{
		sw_ge=temp_char;
		//if(sw_ge<9)
		//{
			//Display_Temp(sw_ge);//LCD_Write_data(4,&fuel_led[sw_ge], 1);
		//}
	}
}


/* 水温控制 */
/**
 * [Calculate_Temperature description]
 * @Author       JianFeng
 * @Version:
 * @DateTime     2020.1.16
 * @Description: 1、显示范囿40 - 120°
 * 				2、水温表100-120°刻度线为红色
				3、C(40)\80\100\H(120)
				4?0-报警炿显示90°
				5、水渿>= 103°旿报警灯点亮、STOP紧急停车灯点亮
					水温<=101°时指示灯熄灭，蜂鸣器停止报警
				6、连绿秒收不到总线数据，归零，点亮水温过高指示灯、STOP紧急停车灯点亮
 */
void Calculate_Temperature(unsigned int EngCoolTemp)
{
	unsigned int temp,com;
	
	temp = EngCoolTemp;
	if(temp<temp_dial[1])
		temp=temp_dial[1];
	com=0;
	for(temp_a=1;temp_a<10;temp_a++)
	{
		if(temp<=temp_dial[temp_a])
		{
		 	temp=temp-temp_dial[temp_a-1];
		 	temp_b=temp;
		 	temp_b=temp_b*temp_angle[temp_a];
			temp_b= temp_b/(temp_dial[temp_a]-temp_dial[temp_a-1]);

			//sms_inp=(unsigned int)(temp_b+com);
			sms_new=(unsigned int)(temp_b+com);
			break;
		}
		com=com+temp_angle[temp_a];
	}
	
	Calculate_Temperature_Display();
	
#if 0
	if(pro_start>0)
	{
		if(sms_new>2016)
		{
			sw_bj_modea=1;
			tempalarm_sum=1;  //用于水温报警
		}
		else
		{
			if(sms_new<1976)
			{
				sw_bj_modea=0;
				tempalarm_sum=0;
			}
		}

		if(sw_bj_modea==0 )
		{
			if( (stop_ID281) ||(sw_bj_modeb>1))
				out_temperature=1;
			else
				out_temperature=0;
		}

		if(sw_bj_modea==1)
		{
    	    out_temperature = g_ucFrequency_1HZ;
		}
	}
#endif
}


static void Calculate_Fuel_Display(void)
{
    unsigned char temp_char;
	
	temp_char=(unsigned char)(smr_new/288);
	if(temp_char<Fuel_ge)
	{
		temp_char=(unsigned char)((smr_new+10)/288);
	}
	
	if(Fuel_ge!=temp_char)
	{
		Fuel_ge=temp_char;
		if(Fuel_ge<9)
		{
			//Display_Temp(sw_ge);//LCD_Write_data(4,&fuel_led[sw_ge], 1);
		}
	}
}


void Calculate_Fuel(unsigned int temp_adc)
{
	unsigned int com;
	com=0;
	if(temp_adc < fuel_dial[0])
	{
		temp_adc =fuel_dial[0];
	}

	for(temp_a=1;temp_a<12;temp_a++)
	{
		if(temp_adc<=fuel_dial[temp_a])
		{
			temp_adc = fuel_dial[temp_a-1]- temp_adc;
			temp_b = temp_adc;
			temp_b = temp_b*fuel_angle[temp_a];
			temp_b = temp_b/(fuel_dial[temp_a-1]-fuel_dial[temp_a]);
			
			//smr_inp = temp_b+com;
			smr_new = temp_b+com;
			
		#if 0
			// 燃油没有错误才记录数捿
			if( (fuel_failure_enable==0)  &&(fuel_failure_statuea==0) )
			{
				fuel_cy=( unsigned int)temp_b;

				if( (second_1s-second_220)>220)
				{
					second_220=second_1s;
					fuel_current_loop++;
					fuel_current_loop=((fuel_current_loop )&0x03);
					fuel_current[fuel_current_loop]=fuel_cy;
				}
			}
		#endif
			break;
		}
		com=com+fuel_angle[temp_a];
	}

	Calculate_Fuel_Display();
}


