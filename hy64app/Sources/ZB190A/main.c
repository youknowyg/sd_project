/*****************************************************************************
VECTOR ADDRESS 0x14F0  T_clock
VECTOR ADDRESS 0x14A2  TIM1CH6_ISR
VECTOR ADDRESS 0x14A4  TIM1CH5_ISR
VECTOR ADDRESS 0x14A6  TIM1CH4_ISR
VECTOR ADDRESS 0x14AE  TIM1CH0_ISR
VECTOR ADDRESS 0x149E  TIM1OVER_ISR
VECTOR ADDRESS 0x14B8  FSL_ISR_Handler
VECTOR ADDRESS 0x14B2  Can_receive_ISR

VECTOR ADDRESS 0x14B6  CAN_WakeUp
VECTOR ADDRESS 0x14E2  TIM0CH6_ISR
VECTOR ADDRESS 0x14EA  T0_2_ISR
VECTOR ADDRESS 0x14D6  Lin_receive_ISR
VECTOR ADDRESS 0x14FA  Vcop_ISR
VECTOR ADDRESS 0x14FC  Vclkmon_ISR

VECTOR ADDRESS 0x148A  Vlvi_ISR


1、网络需求
1.1、仪表连续20秒收不到任何CAN报文，则需要在液晶屏上显示“网络故障”

2、自检需求
全部信号片上的信号灯（LED灯）亮3秒后依据实际信号状况点亮相应指示灯



1、增加仪表自检功能（主要针对的是上IG电时仪表所有的LED灯点亮），自检时间为3S
自检的时候所有warning LED全部点亮3秒，转速、水温、燃油指示灯不点亮，自检结束后正常显示

2、增加转速、水温、燃油指示灯自检结束后才能正常显示

3、将转速报文丢失500ms（50个报文周期）后转速回到零位，转速连续50个周期的原始值超过0xFAFF也将转速回到零位

4、增加水温报文丢失5秒失效回到零位，超过0xFA连续5次失效，回到零位，失效时报警灯处理还没有做

5、增加尿素信号丢失5000ms (5个信号周期)，显示归零，超过5个周期大于0xFA判断信号失效

6、增加尿素信号失效时报警灯点亮功能

2020 02 24
7、更改门锁的原始值
8、增加12V\5V输出控制（控制策略是，点火初始化打开12V和5V输出控制开关，并且置12V/5V输出状态为1，程序正常运行后对ADC反馈值进行判断，如果输出电压低于1V并且连续5次采样都是低于1V，那么关闭输出，并置输出状态为0）



****************************************************************************/
#define   AUTO_GEAR   //自动挡
#define   WATCH_EN
#define   MAIN_C


#define 	BUZZER_PWMDTY		PWMDTY7		// 蜂鸣器驱动 占空比
#define 	BUZZER_PWMPER		PWMPER7 	// 蜂鸣器驱动 频率
#define 	BUZZER_Enable      	PWME_PWME7=1;
#define 	BUZZER_Disable     	PWME_PWME7=0;



#define 	BT815_SDOUT       PTIV_PTIV0

#define		PORTB_DIRECTION		DDRB = 0x02	/* 0000 0010 */
#define 	MCU_I_KEY1_PB7		PORTB_PB7
#define 	MCU_I_KEY2_PB6		PORTB_PB6
#define 	MCU_I_KEY3_PB5		PORTB_PB5
#define 	MCU_I_KEY4_PB4		PORTB_PB4
#define 	MCU_I_KEY5_PB3		PORTB_PB3
#define 	MCU_I_KEY6_PB2		PORTB_PB2
#define 	MCU_O_LED_POWER_PB1	PORTB_PB1
#define 	MCU_I_P_GEAR_PB0	PORTB_PB0


#define		PORTA_DIRECTION		DDRA = 0xFF	/* 1111 1111 */
#define 	DSC_PA7				PORTA_PA7
#define 	MCU_O_OILVOLT1_PA6	PORTA_PA6
#define 	STCPA_PA4			PORTA_PA4
#define 	SCHPA_PA3			PORTA_PA3
#define		DSA_PA2				PORTA_PA2
#define		SCHPC_PA1			PORTA_PA1
#define		STCPC_PA0			PORTA_PA0


#define		PORTR_DIRECTION		DDRR = 0x53		/* 0101 0011 */
#define		MCU_I_HIGH_GEAR_PR7 PTR_PTR7
//#define		//SMGA1_PR6			PTR_PTR6	/* PR6悬空 */
#define		HC165OUTDATA_B_PR5	PTR_PTR5
#define		MCU_O_12V_PR4		PTR_PTR4
#define		MCU_I_LOWMBEAM_PR3	PTR_PTR3
#define		MCU_I_DOOR_PR2		PTR_PTR2
#define		MCU_BEEP_POWER_PR1	PTR_PTR1
#define		V_CAN_PR0			PTR_PTR0


#define		PORTH_DIRECTION		DDRH = 0x00		/* 0000 0000 */
#define		MCU_I_R_GEAR_PH7	PTH_PTH7
#define		MCU_I_LOW_GEAR_PH6	PTH_PTH6
#define		MCU_I_REARFOG_PH5	PTH_PTH5
#define		MCU_I_BWL_PH4		PTH_PTH4
#define		MCU_I_TURNL_TRAILER_PH3 PTH_PTH3
#define		MCU_I_TURNR_TRAILER_PH2 PTH_PTH2
#define		MCU_I_TURNL_PH1		PTH_PTH1
#define		MCU_I_TURNR_PH0		PTH_PTH0

#define		PORTT_DIRECTION		DDRT = 0x76		/* 0111 0110 */
#define		HC165OUTDATA_A_PT7	PTT_PTT7
#define		DS1_PT6				PTT_PTT6
#define		STCP1_PT5			PTT_PTT5
#define		SCHP1_PT4			PTT_PTT4
#define		MCU_I_N_GEAR_PT3	PTT_PTT3
#define 	V_POW2_PT2			PTT_PTT2
#define		V_POW1_PT1			PTT_PTT1
#define		MCU_I_SPEED_PT0		PTT_PTT0
//#define     lc_input_bit    	PTT_PTT0



#define		PORTP_DIRECTION		DDRP = 0x3B		/* 00111011 */
#define		MCU_I_FRONTFOG_PP7	PTP_PTP7
#define		MCU_I_POWER_PP6		PTP_PTP6//1//PTP_PTP6
#define		HC165EN_CLK_PP5		PTP_PTP5
#define		HC165_CLK_PP4		PTP_PTP4
#define		HC165_SHLD_PP3		PTP_PTP3
#define		MCU_I_ILL_PP2		PTP_PTP2
#define		MCU_O_BLACK_LIGHT_PP1	PTP_PTP1	/* 可能需要PWM功能 */
#define		MCU_O_TFT_PWM_PP0	PTP_PTP0


#define		PORTS_DIRECTION		DDRS = 0xEB			/* 11101011 */
#define		DSB_PS7				PTS_PTS7
#define		SCHPB_PS6			PTS_PTS6
#define		STCPB_PS5			PTS_PTS5
#define		MCU_I_HIGHBEAM_PS4	PTS_PTS4
/* CAN通讯占用PS3 PS2 */
#define		MCU_O_BEEP_PWM_PS1	PTS_PTS1
#define		SMGA2_PS0			PTS_PTS0


#define		PORTV_DIRECTION		DDRV = 0xFE			/* 11111110 */
#define		SMGA1_PV7			PTV_PTV7
#define		MCU_O_TFT_POWER_PV6	PTV_PTV6
/* PV5 PV4暂时悬空 */
#define		MCU_815_CS_PV3		PTV_PTV3
#define		MCU_815_SCK_PV2		PTV_PTV2
#define		MCU_815_MOSI_PV1	PTV_PTV1
#define		MCU_815_MISO_PV0	PTV_PTV0


#define		PORTU_DIRECTION		DDRU = 0xA0			/* 10100000 */
#define		SMGA3_PU7			PTU_PTU7
#define		MCU_815_IO5_PU6		PTU_PTU6
#define		MCU_815_PD_PU5		PTU_PTU5
#define		MCU_815_INT			PTU_PTU4
#define		MCU_815_IO4_PU3		PTU_PTU3
#define		MCU_815_IO3_PU2		PTU_PTU2
#define		MCU_815_IO2_PU1		PTU_PTU1
/* PU0悬空 */						//PTU_PTU0



#define T_596   1

#define		LC_DZ       159700//190161L //
#define		LC_LITTLE   770 	 //      445*8






#include <hidef.h>  /* also includes boolean definitions in stdtypes.h     */
#include <MC9S12HY64.h>     /* derivative information */
#include "target.h"
#include "S12HY_peripherals.h" /* includes peripherals definitions and FSL data types */
#include "ee_emulation.h"
#include "main.h"
#include "smc.h"
#include "common_Q20.h"

#include "EVE_APP.h"
#include "LCDDriver.h"
#include "LCDDisplay.h"

#include "Temperature_Fuel_Cal.h"

//#include "Yvc641_SPI.H"
/************************* typedefs ******************************************/

/************************* #defines ******************************************/

/************************* Constants *****************************************/
#pragma CODE_SEG default
#define     BOOTLOADER      1

#define TIM1_Set20ms   2500 //  20ms  
#define TIM1_Set10ms   1250 //  10ms  

const BWord Word24x24[] = 
{0};


/************************* Global Variables **********************************/
#pragma DATA_SEG DEFAULT

SmControlStu	Smeter[Mc_MAX];


struct{

union {
	u32 Byte;
	struct {
		u32  LED1000		 :1;				
		u32  LED1001		 :1;				
		u32  LED1002		 :1;				
		u32  LED1003		 :1;				
		u32  LED1004		 :1;				
		u32  LED1005		 :1;				
		u32  LED1006		 :1;				
		u32  LED1007		 :1;

		u32  LED28		 :1;
		u32  LED27		 :1;
		u32  LED26		 :1;
		u32  LED25		 :1;
		u32  LED11		 :1;
		u32  LED12		 :1;
		u32  LED13		 :1;
		u32  LED14		 :1;
		
		u32  LED24		 :1;
		u32  LED23		 :1;
		u32  LED22		 :1;
		u32  LED21		 :1;
		u32  LED7		 :1;
		u32  LED8		 :1;
		u32  LED9		 :1;
		u32  LED10		 :1;

		u32  LED20		 :1;				
		u32  LED19		 :1;				
		u32  LED18		 :1;				
		u32  LED17		 :1;				
		u32  LED3		 :1;				
		u32  LED4		 :1;				
		u32  LED5		 :1;				
		u32  LED6		 :1;				

		
	} Bits;
} C596A;





union {
	u32 Byte;
	struct {
		u32  LED1010		 :1;
		u32  LED1011		 :1;
		u32  LED1012		 :1;
		u32  LED1013		 :1;
		u32  LED1014		 :1;
		u32  LED1015		 :1;
		u32  LED1016		 :1;
		u32  LED1017		 :1;

		u32  LED68		 :1;
		u32  LED51		 :1;
		u32  LED52		 :1;
		u32  LED69		 :1;
		u32  LED70		 :1;
		u32  LED15		 :1;
		u32  LED29		 :1;
		u32  LED30		 :1;

		u32  LED60		 :1;
		u32  LED61		 :1;
		u32  LED62		 :1;
		u32  LED63		 :1;
		u32  LED64		 :1;
		u32  LED65		 :1;
		u32  LED66		 :1;
		u32  LED67		 :1;

		u32  LED72		 :1;									   /* Port B Bit 0 */
		u32  LED53		 :1;									   /* Port B Bit 1 */
		u32  LED54		 :1;									   /* Port B Bit 2 */
		u32  LED55		 :1;									   /* Port B Bit 3 */
		u32  LED56		 :1;									   /* Port B Bit 4 */
		u32  LED57		 :1;									   /* Port B Bit 5 */
		u32  LED58		 :1;									   /* Port B Bit 6 */
		u32  LED59		 :1;									   /* Port B Bit 7 */
	} Bits;
} C596B;


union {
	u32 Byte;
	struct {
		u32  LED1020		 :1;
		u32  LED1021		 :1;
		u32  LED1022		 :1;
		u32  LED1023		 :1;
		u32  LED1024		 :1;
		u32  LED1025		 :1;
		u32  LED1026		 :1;
		u32  LED1027		 :1;
	
		u32  LED46		 :1;
		u32  LED47		 :1;
		u32  LED48		 :1;
		u32  LED49		 :1;
		u32  LED50		 :1;
		u32  LED1		 :1;
		u32  LED2		 :1;
		u32  LED16		 :1;

		u32  LED38		 :1;
		u32  LED39		 :1;
		u32  LED40		 :1;
		u32  LED41		 :1;
		u32  LED42		 :1;
		u32  LED43		 :1;
		u32  LED44		 :1;
		u32  LED45		 :1;

		u32  LED71		 :1;									
		u32  LED31		 :1;									
		u32  LED32		 :1;									
		u32  LED33		 :1;									
		u32  LED34		 :1;
		u32  LED35		 :1;
		u32  LED36		 :1;									
		u32  LED37		 :1;									
	} Bits;
} C596C;

}C596;

#define	LED_20 		C596.C596A.Bits.LED20
#define	LED_19 		C596.C596A.Bits.LED19
#define	LED_18 		C596.C596A.Bits.LED18
#define	LED_17 		C596.C596A.Bits.LED17
#define	LED_3		C596.C596A.Bits.LED3
#define	LED_4		C596.C596A.Bits.LED4
#define	LED_5		C596.C596A.Bits.LED5
#define	LED_6		C596.C596A.Bits.LED6

#define	LED_24		C596.C596A.Bits.LED24
#define	LED_23		C596.C596A.Bits.LED23
#define	LED_22		C596.C596A.Bits.LED22
#define	LED_21		C596.C596A.Bits.LED21
#define	LED_7		C596.C596A.Bits.LED7
#define	LED_8		C596.C596A.Bits.LED8
#define	LED_9		C596.C596A.Bits.LED9
#define	LED_10		C596.C596A.Bits.LED10
#if 1
#define	LED_28		C596.C596A.Bits.LED28
#define	LED_27		C596.C596A.Bits.LED27
#define	LED_26		C596.C596A.Bits.LED26
#define	LED_25		C596.C596A.Bits.LED25
#define	LED_11		C596.C596A.Bits.LED11
#define	LED_12		C596.C596A.Bits.LED12
#define	LED_13		C596.C596A.Bits.LED13
#define	LED_14		C596.C596A.Bits.LED14
#endif

#define	LED_72		C596.C596B.Bits.LED72
#define	LED_51		C596.C596B.Bits.LED51
#define	LED_52		C596.C596B.Bits.LED52
#define	LED_53		C596.C596B.Bits.LED53
#define	LED_54		C596.C596B.Bits.LED54
#define	LED_55		C596.C596B.Bits.LED55
#define	LED_56		C596.C596B.Bits.LED56
#define	LED_57		C596.C596B.Bits.LED57

#define	LED_58		C596.C596B.Bits.LED58
#define	LED_59		C596.C596B.Bits.LED59
#define	LED_60		C596.C596B.Bits.LED60
#define	LED_61		C596.C596B.Bits.LED61
#define	LED_62		C596.C596B.Bits.LED62
#define	LED_63		C596.C596B.Bits.LED63
#define	LED_64		C596.C596B.Bits.LED64
#define	LED_65		C596.C596B.Bits.LED65

#define	LED_66		C596.C596B.Bits.LED66
#define	LED_67		C596.C596B.Bits.LED67
#define	LED_68		C596.C596B.Bits.LED68
#define	LED_69		C596.C596B.Bits.LED69
#define	LED_70		C596.C596B.Bits.LED70
#define	LED_15		C596.C596B.Bits.LED15
#define	LED_29		C596.C596B.Bits.LED29
#define	LED_30		C596.C596B.Bits.LED30

#define	LED_71 		C596.C596C.Bits.LED71
#define	LED_31 		C596.C596C.Bits.LED31
#define	LED_32 		C596.C596C.Bits.LED32
#define	LED_33 		C596.C596C.Bits.LED33
#define	LED_34 		C596.C596C.Bits.LED34
#define	LED_35 		C596.C596C.Bits.LED35
#define	LED_36 		C596.C596C.Bits.LED36
#define	LED_37 		C596.C596C.Bits.LED37

#define	LED_38 		C596.C596C.Bits.LED38
#define	LED_39 		C596.C596C.Bits.LED39
#define	LED_40 		C596.C596C.Bits.LED40
#define	LED_41 		C596.C596C.Bits.LED41
#define	LED_42 		C596.C596C.Bits.LED42
#define	LED_43 		C596.C596C.Bits.LED43
#define	LED_44 		C596.C596C.Bits.LED44
#define	LED_45 		C596.C596C.Bits.LED45

#define	LED_46 		C596.C596C.Bits.LED46
#define	LED_47 		C596.C596C.Bits.LED47
#define	LED_48 		C596.C596C.Bits.LED48
#define	LED_49 		C596.C596C.Bits.LED49
#define	LED_50 		C596.C596C.Bits.LED50
#define	LED_1 		C596.C596C.Bits.LED1
#define	LED_2 		C596.C596C.Bits.LED2
#define	LED_16 		C596.C596C.Bits.LED16

typedef struct{
union {
	u16 Byte;
	struct {
		u16  LED00		 :1;		/* 冷却液位低(L) */
		u16  LED01		 :1;		/* ASR(L/CAN) */
		u16  LED02		 :1;		/* 低档指示(L) */
		u16  LED03		 :1;		/* 高档指示(L) */
		u16  LED04		 :1;		/* EBS故障指示灯(L/CAN) */
		u16  LED05		 :1;		/* 轮间差速指示(L) */
		u16  LED06		 :1;		/* 轴间差速指示(L) */
		u16  LED07		 :1;		/* 巡航控制指示灯 */
	
		u16  LED08		 :1;		/* DPF 再生指示灯 黄色 */
		u16  LED09		 :1;		/* DPF 再生指示灯 绿色 */
		u16  LED010		 :1;		/* 驾驶员报警系统指示灯 */
		u16  LED011		 :1;		/* 驾驶性能限制系统指示灯 */
		u16  LED012		 :1;		/* 自动大灯 */
		u16  LED013		 :1;		/* 尿素液位 */
		u16  LED014		 :1;
		u16  LED015		 :1;				
	} Bits;
} LED;

}LCD_Indicate;


LCD_Indicate LCD_Display_LED;






#if 1
struct{
union {
	u32 Byte;
	struct {
		u32  NXP74HC165A_0		:1;
		u32  NXP74HC165A_1		:1;
		u32  NXP74HC165A_2		:1;
		u32  NXP74HC165A_3		:1;
		u32  NXP74HC165A_4		:1;
		u32  NXP74HC165A_5		:1;
		u32  NXP74HC165A_6		:1;
		u32  NXP74HC165A_7		:1;
	
		u32  I_SITBELT		 			:1;									   /* Port B Bit 0 */
		u32  I_CHARGING		 			:1;									   /* Port B Bit 1 */
		u32  INPUT_K3_A		 			:1;									   /* Port B Bit 2 */
		u32  I_Between_Axes_Speed_H		:1;									   /* Port B Bit 3 */
		u32  I_Between_Axes_Speed_L		:1;									   /* Port B Bit 4 */
		u32  I_STOP		 				:1;									   /* Port B Bit 5 */
		u32  I_Between_Wheels_Speed_H	:1;									   /* Port B Bit 6 */
		u32  I_METER_LIGHT		 		:1;									   /* Port B Bit 7 */

		u32  INPUT_K9		 			:1;
		u32  INPUT_K10		 			:1;
		u32  INPUT_K11		 			:1;
		u32  INPUT_K12		 			:1;
		u32  I_EBS		 				:1;
		u32  I_Between_Wheels_Speed_L	:1;
		u32  INPUT_K15		 			:1;
		u32  INPUT_K16		 			:1;

		u32  I_BACK_AIR_PRESSURE_H		:1;
		u32  I_ECAS		 				:1;
		u32  I_FUEL_PREHEATING		 	:1;
		u32  I_TANK_CHANGE		 		:1;
		u32  I_CAR_LIFT		 			:1;
		u32  I_AIRBAG_L		 			:1;
		u32  I_CAB_LOCK		 			:1;
		u32  I_EBS_L		 			:1;
	} Bits;
} NXP74HC165A;

union {
	u32 Byte;
	struct {
		u32  NXP74HC165B_0		:1;
		u32  NXP74HC165B_1		:1;
		u32  NXP74HC165B_2		:1;
		u32  NXP74HC165B_3		:1;
		u32  NXP74HC165B_4		:1;
		u32  NXP74HC165B_5		:1;
		u32  NXP74HC165B_6		:1;
		u32  NXP74HC165B_7		:1;
	
		u32  INPUT_K1		 		:1;									   /* Port B Bit 0 */
		u32  INPUT_K2		 		:1;									   /* Port B Bit 1 */
		u32  INPUT_K3			 	:1;									   /* Port B Bit 2 */
		u32  INPUT_K4		 		:1;									   /* Port B Bit 3 */
		u32  INPUT_K5		 		:1;									   /* Port B Bit 4 */
		u32  INPUT_K6		 		:1;									   /* Port B Bit 5 */
		u32  INPUT_NONE		 		:1;									   /* Port B Bit 6 */
		u32  INPUT_K8		 		:1;									   /* Port B Bit 7 */

		u32  I_MAIN_TANL_OIL			:1;
		u32  I_BACK_AIR_PRESSURE_L		:1;
		u32  I_AIRBAG_H		 			:1;
		u32  I_Retarder		 			:1;
		u32  I_POWER_LIGHT_L		 	:1;
		u32  I_POWER_LIGHT_H		 	:1;
		u32  I_FLOATING_BRIDGE		 	:1;
		u32  I_POWER_OUT		 		:1;

		u32  I_POWER_TAKE_OFF		 	:1;
		u32  I_AIR_FILTRATION_PLUG		:1;
		u32  I_LOW_COOLING_LEVEL		:1;
		u32  I_MAIN_ABS		 			:1;
		u32  I_BrakePadPear		 		:1;
		u32  I_Trailer_ABS		 		:1;
		u32  I_Exhaust_Brake		 	:1;
		u32  I_ASR		 				:1;
	} Bits;
} NXP74HC165B;

}NXP74HC165;



#define	Hardware_I_SITBELT		 				NXP74HC165.NXP74HC165A.Bits.I_SITBELT
#define	Hardware_I_CHARGING		 				NXP74HC165.NXP74HC165A.Bits.I_CHARGING
#define	Hardware_INPUT_K3_A		 				NXP74HC165.NXP74HC165A.Bits.INPUT_K3_A
#define	Hardware_I_Between_Axes_Speed_H			NXP74HC165.NXP74HC165A.Bits.I_Between_Axes_Speed_H
#define	Hardware_I_Between_Axes_Speed_L			NXP74HC165.NXP74HC165A.Bits.I_Between_Axes_Speed_L
#define	Hardware_I_STOP		 					NXP74HC165.NXP74HC165A.Bits.I_STOP
#define	Hardware_I_Between_Wheels_Speed_H		NXP74HC165.NXP74HC165A.Bits.I_Between_Wheels_Speed_H
#define	Hardware_I_METER_LIGHT		 			NXP74HC165.NXP74HC165A.Bits.I_METER_LIGHT

#define	Hardware_INPUT_K9		 				NXP74HC165.NXP74HC165A.Bits.INPUT_K9
#define	Hardware_INPUT_K10		 				NXP74HC165.NXP74HC165A.Bits.INPUT_K10
#define	Hardware_INPUT_K11		 				NXP74HC165.NXP74HC165A.Bits.INPUT_K11
#define	Hardware_INPUT_K12		 				NXP74HC165.NXP74HC165A.Bits.INPUT_K12
#define	Hardware_I_EBS		 					NXP74HC165.NXP74HC165A.Bits.I_EBS	
#define	Hardware_I_Between_Wheels_Speed_L		NXP74HC165.NXP74HC165A.Bits.I_Between_Wheels_Speed_L
#define	Hardware_INPUT_K15		 				NXP74HC165.NXP74HC165A.Bits.INPUT_K15
#define	Hardware_INPUT_K16		 				NXP74HC165.NXP74HC165A.Bits.INPUT_K16

#define	Hardware_I_BACK_AIR_PRESSURE	_H		NXP74HC165.NXP74HC165A.Bits.I_BACK_AIR_PRESSURE_H	
#define	Hardware_I_ECAS		 					NXP74HC165.NXP74HC165A.Bits.I_ECAS
#define	Hardware_I_FUEL_PREHEATING		 		NXP74HC165.NXP74HC165A.Bits.I_FUEL_PREHEATING
#define	Hardware_I_TANK_CHANGE		 			NXP74HC165.NXP74HC165A.Bits.I_TANK_CHANGE
#define	Hardware_I_CAR_LIFT		 				NXP74HC165.NXP74HC165A.Bits.I_CAR_LIFT
#define	Hardware_I_AIRBAG_L		 				NXP74HC165.NXP74HC165A.Bits.I_AIRBAG
#define	Hardware_I_CAB_LOCK		 				NXP74HC165.NXP74HC165A.Bits.I_CAB_LOCK	
#define	Hardware_I_EBS_L		 				NXP74HC165.NXP74HC165A.Bits.I_EBS_L


#define	Hardware_INPUT_K1		 				NXP74HC165.NXP74HC165B.Bits.INPUT_K1
#define	Hardware_INPUT_K2		 				NXP74HC165.NXP74HC165B.Bits.INPUT_K2
#define	Hardware_INPUT_K3			 			NXP74HC165.NXP74HC165B.Bits.INPUT_K3
#define	Hardware_INPUT_K4		 				NXP74HC165.NXP74HC165B.Bits.INPUT_K4
#define	Hardware_INPUT_K5		 				NXP74HC165.NXP74HC165B.Bits.INPUT_K5
#define	Hardware_INPUT_K6		 				NXP74HC165.NXP74HC165B.Bits.INPUT_K6
#define	Hardware_INPUT_NONE		 				NXP74HC165.NXP74HC165B.Bits.INPUT_NONE
#define	Hardware_INPUT_K8		 				NXP74HC165.NXP74HC165B.Bits.INPUT_K8

#define	Hardware_I_MAIN_TANL_OIL				NXP74HC165.NXP74HC165B.Bits.I_MAIN_TANL_OIL	
#define	Hardware_I_BACK_AIR_PRESSURE_L			NXP74HC165.NXP74HC165B.Bits.I_BACK_AIR_PRESSURE_L	
#define	Hardware_I_AIRBAG_H		 				NXP74HC165.NXP74HC165B.Bits.I_AIRBAG_H
#define	Hardware_I_Retarder		 				NXP74HC165.NXP74HC165B.Bits.I_Retarder
#define	Hardware_I_POWER_LIGHT_L				NXP74HC165.NXP74HC165B.Bits.I_POWER_LIGHT_L	
#define	Hardware_I_POWER_LIGHT_H				NXP74HC165.NXP74HC165B.Bits.I_POWER_LIGHT_H	
#define	Hardware_I_FLOATING_BRIDGE				NXP74HC165.NXP74HC165B.Bits.I_FLOATING_BRIDGE	
#define	Hardware_I_POWER_OUT		 			NXP74HC165.NXP74HC165B.Bits.I_POWER_OUT

#define	Hardware_I_POWER_TAKE_OFF				NXP74HC165.NXP74HC165B.Bits.I_POWER_TAKE_OFF
#define	Hardware_I_AIR_FILTRATION_PLUG			NXP74HC165.NXP74HC165B.Bits.I_AIR_FILTRATION_PLUG
#define	Hardware_I_LOW_COOLING_LEVEL			NXP74HC165.NXP74HC165B.Bits.I_LOW_COOLING_LEVEL	
#define	Hardware_I_MAIN_ABS		 				NXP74HC165.NXP74HC165B.Bits.I_MAIN_ABS
#define	Hardware_I_BrakePadPear		 			NXP74HC165.NXP74HC165B.Bits.I_BrakePadPear
#define	Hardware_I_Trailer_ABS		 			NXP74HC165.NXP74HC165B.Bits.I_Trailer_ABS
#define	Hardware_I_Exhaust_Brake				NXP74HC165.NXP74HC165B.Bits.I_Exhaust_Brake	
#define	Hardware_I_ASR		 					NXP74HC165.NXP74HC165B.Bits.I_ASR




#endif


typedef enum{
	OIL2_NUM,
	OIL1_NUM,
	RA_PRE_NUM,
	FA_PRE_NUM,
	BAT_NUM,
	OUT12V0_NUM,
	OUT5V0_NUM,
	BP_VOLT,
	AD_MAX
}ADC_NUM;

struct car2p
{
	unsigned int  ad_result;
	unsigned int    ad_dial;
}carf[AD_MAX];


CanFrameDef	CanFrame_Rx[IDMAX];


unsigned char  studyEn,study_ID301, study_ID5A1,study_ID300,study_ID258,study_ID320,study_ID631;
unsigned char GoToPowerOffEn;
long	smc_pt1,  smc_pt2, smc_clc1, smc_clc2;
int 	smc_inp,  smc_new,  smc_old,smc_acc,smc_velo;
unsigned int lc_fact;

long	sml_pt1,  sml_pt2, sml_clc1, sml_clc2;
int 	sml_inp,  sml_new,sml_old;

long	sms_pt1,  sms_pt2, sms_clc1, sms_clc2;
int	    sms_inp,  sms_new, sms_old;

long	smr_pt1,  smr_pt2, smr_clc1, smr_clc2;
int	    smr_inp,  smr_new, smr_old,smr_new_bak,B_POINT;



unsigned char	 smc_dn,sml_dn,sms_dn,smr_dn;
char     smc_vmax,sml_vmax,sms_vmax,smr_vmax;

unsigned long key,seedkey;
unsigned char CommunicationNormalControl_en; //==0:允许应用报文收发，==1:禁止应用报文收发
unsigned char CommunicationNetworkControl_en;//==0:允许网络报文收发，==1:禁止网络报文收发


unsigned char diag_disp_en;



unsigned char door_enable;
//unsigned char diag_lcdExit_cnt,diag_ledExit_cnt,diag_buzzExit_cnt;
//unsigned char curise_speed,curise_speed_bak;
unsigned int yytest,yytest1,yytest2;
unsigned int u8_dz=65535;
unsigned char key_lianxu_en;
unsigned char 	second_lc,ee_loop,clockNoDvd_set_en,KeyPressHandleEn,KeyPressHandleWattingCnt,
time_change,can_ok,can_sleep1;
unsigned long int diag_comm;
unsigned char outLed_Door_Vual,outLed_Insulate_Vual,outLed_CdConnect_Vual,outLed_BatHot_Vual,outLed_BatFault_Vual;

unsigned char no_key_c,no_keyr_c,keyTure_cnt,clock_set_en
    ,keyTure_mode,ign_jsq,ms_flash;
unsigned int   	second_1s,
				second_speed_out,
				second_500s,
				second_20ms,
				second_100ms,
				second_CANTx_100ms,
				second_CANTx_150ms,
				second_250ms,
				second_tft_1s,
				second_501ms,
				second_lamp_time,
				second_Buzzer,
				second_21ms;
unsigned int maintenance,second_ig,lc_odo;

unsigned char rolling_count,rolling_count433,gear_UpDown,trip_sum_enable;//25



unsigned char   belt_enable,belt_beep_sum,loop_loop,
                zkb_beep_sum;

unsigned char tft_start,tripaStorEn;
unsigned long int tripa_sum,tripb_sum;
unsigned long lc_run_sum;
unsigned char securityAccess;
unsigned char Extended_default_Session;


unsigned char display[6];
unsigned char can_diag[9];
unsigned char can_diag7DF[9];
//ad
unsigned char 	lc_little_total,
				clr_bit,
				keyClear256KmEn,
				clear_256,
				main_sleep,
				gear,
				pro_start,
				pro_start_dtc,
				pro_start_ry;

unsigned char 	overspeed_beep_sum,
				ready_beep_sum,
				set_over_speed;


unsigned char radarDataL,radarDataM,radarDataR,radarDataDispSum,radarDataLGe,radarDataMGe,radarDataRGe;

unsigned  char  lamp_lever_sum,lamp_lever_sum_bak;
unsigned  char  Dis_LampLever_En;

unsigned char diag_mode_out,diag_IndicatorsControl_en,diag_Dtc_set,diag_buzz_en,
    diag_sms_inp,diag_disp_en,diag_smr_inp,diag_sml_inp,diag_smc_inp;
unsigned char diag_IndicatorsControl_en;
unsigned char diag_trouble_num,tmps_enable;


unsigned char 	DispClockSet,functionPage,PageClear,CanTxBatOver6vEn;
unsigned char 	*p ;
unsigned char  *l_p;


unsigned char ramdown[6];
unsigned char ramup_a[6];

unsigned  int stop_enableB,stop_enableA;
packet_16bit disp_en;
packet_8bit L1,L2;

packet_16bit config_data[4],diag_trouble_code,diag_canloss_code;
unsigned int  diag_lamp_en,diag_tft_en;


unsigned char outDispReady;
unsigned int Get_Soc_fact,Get_vol_fact,Get_curr_fact,Get_Err_fact,Get_Mtemp_fact,Get_Ctemp_fact,
    Get_BatHtemp_fact,Get_BatLtemp_fact,Get_CellHtemp_fact,Get_CellLtemp_fact,Get_ChgSts_fact,
    Get_Speed_Value,Get_Tacho_Value,Get_gear_data,Get_ChargStuData,Get_ChargTime;       

/*
平均油耗
x（油脉冲）*0.1532*4273.8/y  =6547.4x/y
*/

UINT16 returnCode;
UINT16 readAddr;
UINT16 erasingCycles;
UINT16 ee_read_write[EED_DATA_VALUE_SIZE/EED_MIN_PROG_SIZE];

unsigned long int temp_a,temp_b;
unsigned char lc_loop;
unsigned int  	lc_high,
				lc_low,lc[256],
				lc_num,
				lc_pulsenum,
				lc_trip_sum;
struct car1p			//频率采样存储结构体
{	
	UINT8 	loop,high_time;
    UINT16 	low_time;        
}car[3];

unsigned char yg_test=0;


#pragma DATA_SEG DATA_PERSISTENT

unsigned char second_second,second_min,second_hour,second_hour_bak,second_hour_bak;

#pragma DATA_SEG DEFAULT

#pragma DATA_SEG BOOT_PERSISTENT
unsigned int boot_flag;
#pragma DATA_SEG DEFAULT
/************************* function prototypes *******************************/
//#pragma CODE_SEG DEFAULT
/************************* Functions *****************************************/

#pragma CODE_SEG DEFAULT


void LED_Process(void);
void SMG_Driver(void);
void PRE_Warning_Process(void);



void delay_mu(unsigned int time)
{   time=5;
	for(;time>0;time--)
	{   
	  	__RESET_WATCHDOG();
	}
}
void DelayXms(unsigned int data)
{
	unsigned int temp,temp1;
    for(temp=0;temp<data;temp++)
	{
		for(temp1=0;temp1<2766;temp1++) // 2766
		__RESET_WATCHDOG();
	}
}

void Delayus(unsigned int data)
{
	unsigned int temp,temp1;
	temp1=data<<2;

	for(temp=0;temp<temp1;temp++)
	{
		__RESET_WATCHDOG() ;
	}
}




#pragma CODE_SEG NON_BANKED
#pragma TRAP_PROC
void  interrupt  T_clock(void)
{
    second_250ms++;
    if( second_250ms<17175)
    	second_second++;
    else
    	second_250ms=0;
    if(second_second>239) //239
    {
    	if(clock_set_en==0)
	    {	//(YY:can总线发送时间功能？)
			if(IG_IN==1)
				time_change=1;
           
             
			second_second=0;
			second_min++;
			if(second_min>59)
			{
    			second_min=0;
    			second_hour++;
    			if(second_hour>23)
    			second_hour=0;
			}
	    }
    }

    if(CPMUCLKS_RTIOSCSEL==0)
	{
		CPMUPROT=0x26;
		CPMUCLKS_RTIOSCSEL =1;	// 	//1 RTI clock source is OSCCLK.
		CPMUPROT=0x01;
	}
    CPMUFLG =   0x80;
}
#pragma CODE_SEG DEFAULT
/*
#pragma CODE_SEG NON_BANKED
#pragma TRAP_PROC
void  interrupt  Oscillator_Interrupt(void)
{

	//init_clock();
	//yytest=6543;
	CPMUFLG = 0x02;
}
#pragma CODE_SEG default
*/


#pragma CODE_SEG NON_BANKED
#pragma TRAP_PROC
#if BOOTLOADER
void  interrupt  T0_2_ISR(void)
#else
__interrupt  VectorNumber_Vflash void T0_2_ISR(void)
#endif
{

	TIM0_TFLG1 = TIM0_TFLG1_C2F_MASK;
}
#pragma CODE_SEG DEFAULT


#pragma CODE_SEG NON_BANKED
#pragma TRAP_PROC
void  interrupt  Lin_receive_ISR(void)

{
    SCIASR1_BKDIF = 1;
    SCIASR1_RXEDGIF = 1;
}
#pragma CODE_SEG DEFAULT


#pragma CODE_SEG NON_BANKED
#pragma TRAP_PROC
void  interrupt  CAN_WakeUp(void)
 {

	can_ok=1;
	CANCTL0 =  0x00;
	CANRIER=0x01;//
	CAN_DRV_ON;
	CANRFLG_WUPIF=1;
}
#pragma CODE_SEG DEFAULT
unsigned int tachodata;
#define	RX_TachoSpeed	(CanFrame_Rx[ID0CF00400].data[4].pp<<8 + CanFrame_Rx[ID0CF00400].data[3].pp)
#define	RX_Temperature	(CanFrame_Rx[ID18FEEE00].data[0].pp)	/* 水温 */
#define	RX_NiaoSu		(CanFrame_Rx[ID18FE5600].data[0].pp)	/* 尿素 */

#define	RX_EngOilPress	(CanFrame_Rx[ID18FEEF00].data[3].pp)	/* 机油压力 */



#define	RX_LowBeamSt			(CanFrame_Rx[ID18FED921].data[0].pp&0x03)		/* 近光灯 1.1-1.2 */
#define	RX_PostionLightSt		((CanFrame_Rx[ID18FED921].data[0].pp&0x0C)>>2)	/* PostionLightSt 小灯输出状态 1.3-1.4 */
#define	RX_RightTurnLightSt		((CanFrame_Rx[ID18FED921].data[0].pp&0xC0)>>6)	/* 右转向灯 1.7-1.8 */
#define	RX_LeftTurnLightSt		(CanFrame_Rx[ID18FED921].data[1].pp&0x03)		/* 左转向灯 2.1-2.2 */
#define	RX_HighBeamSt			((CanFrame_Rx[ID18FED921].data[1].pp&0x0C)>>2)	/* 远光灯 2.3-2.4 */
#define	RX_OvertakeLightSt		((CanFrame_Rx[ID18FED921].data[1].pp&0x30)>>4)	/* OvertakeLightSt 超车灯输出状态 2.5-2.6 */
#define	RX_FrontFogSt			((CanFrame_Rx[ID18FED921].data[2].pp&0x0C)>>2)	/* FrontFogSt 前雾灯输出状态 3.3-3.4 */
#define	RX_RearFogSt			((CanFrame_Rx[ID18FED921].data[2].pp&0x30)>>4)	/* RearFogSt 后雾灯输出状态 3.5-3.6 */
#define	RX_HazardSt				((CanFrame_Rx[ID18FED921].data[3].pp&0x0C)>>2)	/* HazardSt 危险报警灯输出状态 4.3-4.4 */
#define	RX_LeftDayLightSt		((CanFrame_Rx[ID18FED921].data[3].pp&0x30)>>4)	/* LeftDayLightSt 左昼行灯输出状态 4.5-4.6 */
#define	RX_RightDayLightSt		((CanFrame_Rx[ID18FED921].data[3].pp&0xC0)>>6)	/* RightDayLightSt 右昼行灯输出状态 4.7-4.8 */

//#define	RX_StopLightSt			(CanFrame_Rx[ID18FED921].data[1].pp&0x03)		/* 制动灯 */




#define	RX_TrailerBrakeSw	((CanFrame_Rx[ID18FF0B21].data[0].pp&0xC0)>>6)	/* 挂车手制动开关 */
#define	RX_ReverseSw		(CanFrame_Rx[ID18FF0B21].data[1].pp&0x03)		/* 变速箱倒挡开关 */
#define	RX_TrailerFuncSw	((CanFrame_Rx[ID18FF0B21].data[1].pp&0xC0)>>6)	/* 挂车功能开关 */
#define	RX_CabLockSw		(CanFrame_Rx[ID18FF0B21].data[2].pp&0x03)		/* 驾驶室锁止开关 */
#define	RX_SeatBeltSw		(CanFrame_Rx[ID18FF0B21].data[1].pp&0x03)		/* 安全带 2.1-2.2 */
//#define	RX_DriverDoorOpenSw	((CanFrame_Rx[ID18FF0B21].data[3].pp&0x0C)>>2)	/* 驾驶员侧门碰开关   */
//#define	RX_PassengerDoorOpenSw	((CanFrame_Rx[ID18FF0B21].data[3].pp&0x30)>>4)	/*乘客侧门碰开关*/

#define	RX_LeftLockSt	((CanFrame_Rx[ID18FF0C21].data[0].pp&0x30)>>4)	/* 左门锁反馈信号 */
#define	RX_RightLockSt	((CanFrame_Rx[ID18FF0C21].data[0].pp&0xC0)>>6)	/* 右门锁反馈信号 */	


#define	RX_ABS_EBSAmberWarningSignal	((CanFrame_Rx[ID18F0010B].data[5].pp&0x30)>>4)		/* 主车ABS指示灯 6.5-6.6 */
#define RX_EBS_EBSRedWarningSignal		((CanFrame_Rx[ID18F0010B].data[5].pp&0x0C)>>2)		/* EBS故障指示灯(L/CAN) */

//#define RX_EngOilPress		(CanFrame_Rx[ID18FEEF00].data[3].pp)

#define	RX_BCM_PTO_Err					(CanFrame_Rx[ID18FF2221].data[0].pp&0x03)			/* 取力器电磁阀故障状态 */
#define	RX_BCM_CabRolloverErr			((CanFrame_Rx[ID18FF2221].data[1].pp&0x30)>>4)		/* 驾驶室翻转故障状态 */

#define	RX_EMS_WaterInFuelIndicator		(CanFrame_Rx[ID18FEFF00].data[0].pp&0x03)			/* 燃油含水指示 */

#define	RX_EMS_RedStopLampState			((CanFrame_Rx[ID18FECA00].data[0].pp&0x30)>>4)		/* 发动机停车报警灯 */

#define	RX_EBS_AmberWarningLampStatus	((CanFrame_Rx[ID18FECA0B].data[0].pp&0xC0)>>2)		/* 主车ABS */

#define	RX_EMS_OBDMalfunctionIndicatorLampCmd	((CanFrame_Rx[ID18FD0700].data[0].pp&0xC0)>>6)	/* OBD故障指示灯 */

#define	RX_IC_TrailerABSfullyoperational	(CanFrame_Rx[ID18FED917].data[0].pp&0x03)
#define	RX_IC_TrailerABSdtcted				((CanFrame_Rx[ID18FED917].data[0].pp&0x0C)>>2)
#define	RX_IC_Trailercncted					((CanFrame_Rx[ID18FED917].data[0].pp&0x30)>>4)

#define	RX_TPMS_TireLocation			(CanFrame_Rx[ID18FEF433].data[0].pp)		/* 轮胎位置 */
#define	RX_TPMS_TirePressure			(CanFrame_Rx[ID18FEF433].data[1].pp)		/* 胎压 */
#define	RX_TPMS_TireTemperature			(CanFrame_Rx[ID18FEF433].data[3].pp<<8 + CanFrame_Rx[ID18FEF433].data[2].pp)		/* 胎温 */
#define	RX_TPMS_SafetyDeviceSensorSstatus (CanFrame_Rx[ID18FEF433].data[4].pp&&0x03)	/* 车轮及爆胎应急安全装置传感器状态 */
#define	RX_TPMS_CTITireStatus			((CanFrame_Rx[ID18FEF433].data[4].pp&&0x0C)>>2)	/* 车轮状态 */
#define	RX_TPMS_SensorTemperatureStatus	((CanFrame_Rx[ID18FEF433].data[4].pp&&0x30)>>4)	/* 胎压传感器温度状态 */
#define	RX_TPMS_SensorVoltageStatus		((CanFrame_Rx[ID18FEF433].data[4].pp&&0xC0)>>6)	/* 胎压传感器电压状态 */
#define	RX_TPMS_TirePressureThresholdDetection	(CanFrame_Rx[ID18FEF433].data[7].pp)	/* 轮胎压力检测状态 */




/* 驾驶员报警系统指示灯 */




/* intel格式，高字节在后，低字节在前 */
#pragma CODE_SEG NON_BANKED
#pragma TRAP_PROC
void  interrupt  Can_receive_ISR(void)
{
      
      //if(MSCANGetMsg(&msg_get))
      //{
      //		CANComm_Recv(); //在中断中停留时间太长，会导致程序异常
      //}

	//u16 CAN_TEST = 0;
	u16 temp_Tacho_L,temp_Tacho_H;
	static u8 TachoData_Count = 0;
	static u8 TempratureData_Count = 0;
	static u8 NiaoSuData_Count = 0;
	static u8 EngOilPressData_Count = 0;

	if((CANRXIDR0 == 0x67)&&(CANRXIDR1 == 0x98)&&(CANRXIDR2==0x08)&&(CANRXIDR3==0x00))	//转速 0x0CF00400
	{
		CanFrame_Rx[ID0CF00400].TOnLineFlg = 1;
		CanFrame_Rx[ID0CF00400].NoComTimeCnt = second_1s;
		//CanFrame_Rx[ID0CF00400].data[3].pp = CANRXDSR3;
		//CanFrame_Rx[ID0CF00400].data[4].pp = CANRXDSR4;		//0.125 rpm/bit, 0 offset

		temp_Tacho_H = CANRXDSR4;//CanFrame_Rx[ID0CF00400].data[4].pp;	
		temp_Tacho_L = CANRXDSR3;//CanFrame_Rx[ID0CF00400].data[3].pp;
		tachodata = (temp_Tacho_H<<8) + temp_Tacho_L;
		if(tachodata > 0xFAFF)
		{
			TachoData_Count++;
			if(TachoData_Count >= 50)
			{
				TachoData_Count = 50;	/* 限制50的上线，防止超出256出现问题 */
				tachodata = 0;
			}
		}
		else
		{
			TachoData_Count = 0;
		}
	}
	else if((CANRXIDR0 == 0xC7)&&(CANRXIDR1 == 0xFD)&&(CANRXIDR2==0xDC)&&(CANRXIDR3==0x00))	// 0x18FEEE00
	{
		CanFrame_Rx[ID18FEEE00].TOnLineFlg = 1;
		CanFrame_Rx[ID18FEEE00].NoComTimeCnt = second_1s;
		yg_test = CanFrame_Rx[ID18FEEE00].data[0].pp = CANRXDSR0;		/* 水温  偏移量-40 */
		if(CanFrame_Rx[ID18FEEE00].data[0].pp > 0xFA)
		{
			TempratureData_Count++;
			if(TempratureData_Count >= 5)
			{
				TempratureData_Count = 5;
				CanFrame_Rx[ID18FEEE00].data[0].pp = 0;
				CanFrame_Rx[ID18FEEE00].TOnLineFlg = 0;
			}
		}
		else
		{
			TempratureData_Count = 0;
		}
	}
	else if((CANRXIDR0 == 0xC7)&&(CANRXIDR1 == 0xFC)&&(CANRXIDR2==0xAC)&&(CANRXIDR3==0x00))	// 0x18FE5600
	{
		CanFrame_Rx[ID18FE5600].TOnLineFlg = 1;
		CanFrame_Rx[ID18FE5600].NoComTimeCnt = second_1s;
		CanFrame_Rx[ID18FE5600].data[0].pp = CANRXDSR0;		/* 尿素量 */

		if(CanFrame_Rx[ID18FE5600].data[0].pp > 0xFA)
		{
			NiaoSuData_Count++;
			if(NiaoSuData_Count >= 5)
			{
				NiaoSuData_Count = 5;
				CanFrame_Rx[ID18FE5600].data[0].pp = 0;
				CanFrame_Rx[ID18FE5600].TOnLineFlg = 0;
			}
		}
		else
		{
			NiaoSuData_Count = 0;
		}
	}
	else if((CANRXIDR0 == 0xC7)&&(CANRXIDR1 == 0xFD)&&(CANRXIDR2==0xDE)&&(CANRXIDR3==0x00))	// 0x18FEEF00
	{
		CanFrame_Rx[ID18FEEF00].TOnLineFlg = 1;
		CanFrame_Rx[ID18FEEF00].NoComTimeCnt = second_1s;
		CanFrame_Rx[ID18FEEF00].data[3].pp = CANRXDSR3;		/* 机油压力 */

		if(CanFrame_Rx[ID18FEEF00].data[3].pp > 0xFA)
		{
			EngOilPressData_Count++;
			if(EngOilPressData_Count >= 5)
			{
				EngOilPressData_Count = 5;
				CanFrame_Rx[ID18FEEF00].data[3].pp = 0;
				CanFrame_Rx[ID18FEEF00].TOnLineFlg = 0;
			}
		}
		else
		{
			EngOilPressData_Count = 0;
		}
	}
	else if((CANRXIDR0 == 0xC7)&&(CANRXIDR1 == 0xFD)&&(CANRXIDR2==0xD2)&&(CANRXIDR3==0x00))	// 0x18FEE900
	{
		CanFrame_Rx[ID18FEE900].TOnLineFlg = 1;
		CanFrame_Rx[ID18FEE900].NoComTimeCnt = second_1s;
		CanFrame_Rx[ID18FEE900].data[0].pp = CANRXDSR0;		/* 发动机小计燃油消耗量 */
		CanFrame_Rx[ID18FEE900].data[1].pp = CANRXDSR1;
		CanFrame_Rx[ID18FEE900].data[2].pp = CANRXDSR2;
		CanFrame_Rx[ID18FEE900].data[3].pp = CANRXDSR3;
		CanFrame_Rx[ID18FEE900].data[4].pp = CANRXDSR4;		/* 发动机累计燃油消耗量 */
		CanFrame_Rx[ID18FEE900].data[5].pp = CANRXDSR5;
		CanFrame_Rx[ID18FEE900].data[6].pp = CANRXDSR6;
		CanFrame_Rx[ID18FEE900].data[7].pp = CANRXDSR7;
	}
	else if((CANRXIDR0 == 0xC7)&&(CANRXIDR1 == 0xFD)&&(CANRXIDR2==0xCA)&&(CANRXIDR3==0x00))	// 0x18FEE500
	{
		CanFrame_Rx[ID18FEE500].TOnLineFlg = 1;
		CanFrame_Rx[ID18FEE500].NoComTimeCnt = second_1s;
		CanFrame_Rx[ID18FEE500].data[0].pp = CANRXDSR0;		/* 发动机总工作时间 */
		CanFrame_Rx[ID18FEE500].data[1].pp = CANRXDSR1;
		CanFrame_Rx[ID18FEE500].data[2].pp = CANRXDSR2;
		CanFrame_Rx[ID18FEE500].data[3].pp = CANRXDSR3;
	}
	else if((CANRXIDR0 == 0xC7)&&(CANRXIDR1 == 0xFD)&&(CANRXIDR2==0x94)&&(CANRXIDR3==0x00))	// 0x18FECA00
	{
		CanFrame_Rx[ID18FECA00].TOnLineFlg = 1;
		CanFrame_Rx[ID18FECA00].NoComTimeCnt = second_1s;
		CanFrame_Rx[ID18FECA00].data[0].pp = CANRXDSR0;		/* 发动机总工作时间 */
		CanFrame_Rx[ID18FECA00].data[1].pp = CANRXDSR1;
	}
	else if((CANRXIDR0 == 0xC7)&&(CANRXIDR1 == 0x79)&&(CANRXIDR2==0xFE)&&(CANRXIDR3==0x00))	// 0x18ECFF00
	{
		CanFrame_Rx[ID18ECFF00].NoComTimeCnt = second_1s;
	}
	else if((CANRXIDR0 == 0xC7)&&(CANRXIDR1 == 0x5F)&&(CANRXIDR2==0xFE)&&(CANRXIDR3==0x00))	// 0x18EBFF00
	{
		CanFrame_Rx[ID18EBFF00].NoComTimeCnt = second_1s;
	}
	else if((CANRXIDR0 == 0xC7)&&(CANRXIDR1 == 0xFD)&&(CANRXIDR2==0x94)&&(CANRXIDR3==0x7A))	// 0x18FECA3D
	{
		CanFrame_Rx[ID18FECA3D].NoComTimeCnt = second_1s;
	}
	else if((CANRXIDR0 == 0xC7)&&(CANRXIDR1 == 0x79)&&(CANRXIDR2==0xFE)&&(CANRXIDR3==0x7A))	// 0x18ECFF3D	       
	{
		CanFrame_Rx[ID18ECFF3D].NoComTimeCnt = second_1s;
	}
	else if((CANRXIDR0 == 0xC7)&&(CANRXIDR1 == 0x5F)&&(CANRXIDR2==0xFE)&&(CANRXIDR3==0x7A))	// 0x18EBFF3D	       
	{
		CanFrame_Rx[ID18EBFF3D].NoComTimeCnt = second_1s;
	}
	else if((CANRXIDR0 == 0xC7)&&(CANRXIDR1 == 0xFD)&&(CANRXIDR2==0x94)&&(CANRXIDR3==0x16))	// 0x18FECA0B	       
	{
		CanFrame_Rx[ID18FECA0B].TOnLineFlg = 1;
		CanFrame_Rx[ID18FECA0B].NoComTimeCnt = second_1s;
		CanFrame_Rx[ID18FECA0B].data[0].pp = CANRXDSR0;	
	}
	else if((CANRXIDR0 == 0xC7)&&(CANRXIDR1 == 0x79)&&(CANRXIDR2==0xFE)&&(CANRXIDR3==0x16))	// 0x18ECFF0B	       
	{
		CanFrame_Rx[ID18ECFF0B].NoComTimeCnt = second_1s;
	}
	else if((CANRXIDR0 == 0xC7)&&(CANRXIDR1 == 0x5F)&&(CANRXIDR2==0xFE)&&(CANRXIDR3==0x16))	// 0x18EBFF0B	       
	{
		CanFrame_Rx[ID18EBFF0B].NoComTimeCnt = second_1s;
	}
	else if((CANRXIDR0 == 0x67)&&(CANRXIDR1 == 0x98)&&(CANRXIDR2==0x06)&&(CANRXIDR3==0x00))	// 0x0CF00300	       
	{
		CanFrame_Rx[ID0CF00300].TOnLineFlg = 1;
		CanFrame_Rx[ID0CF00300].NoComTimeCnt = second_1s;
		CanFrame_Rx[ID0CF00300].data[1].pp = CANRXDSR1;		/* 油门踏板开度 */
	}
	else if((CANRXIDR0 == 0xC7)&&(CANRXIDR1 == 0xFD)&&(CANRXIDR2==0xB2)&&(CANRXIDR3==0x42))	// 0x18FED921	       
	{
		CanFrame_Rx[ID18FED921].TOnLineFlg = 1;
		CanFrame_Rx[ID18FED921].NoComTimeCnt = second_1s;
		CanFrame_Rx[ID18FED921].data[0].pp = CANRXDSR0;		/* 1.1-1.2 近光灯 */
		CanFrame_Rx[ID18FED921].data[1].pp = CANRXDSR1;		/* 2.1-2.2 制动灯 2.3-2.4 右转向灯 2.5-2.6 左转向灯 */
		CanFrame_Rx[ID18FED921].data[2].pp = CANRXDSR2;		/* 3.7-3.8 远光灯 */
		//CanFrame_Rx[ID18FED921].data[0].pp = CANRXDSR0;
	}
	else if((CANRXIDR0 == 0xC7)&&(CANRXIDR1 == 0xFE)&&(CANRXIDR2==0x18)&&(CANRXIDR3==0x42))	// 0x18FF0C21	       
	{
		CanFrame_Rx[ID18FF0C21].TOnLineFlg = 1;
		CanFrame_Rx[ID18FF0C21].NoComTimeCnt = second_1s;
		CanFrame_Rx[ID18FF0C21].data[0].pp = CANRXDSR0;		/* 1.1-1.3 左门锁反馈信号 */
		CanFrame_Rx[ID18FF0C21].data[1].pp = CANRXDSR1;		/* 2.1-2.3 右门锁反馈信号 */


	}
	else if((CANRXIDR0 == 0xC7)&&(CANRXIDR1 == 0xFE)&&(CANRXIDR2==0x16)&&(CANRXIDR3==0x42))	// 0x18FF0B21		   
	{
		CanFrame_Rx[ID18FF0B21].TOnLineFlg = 1;
		CanFrame_Rx[ID18FF0B21].NoComTimeCnt = second_1s;
		CanFrame_Rx[ID18FF0B21].data[0].pp = CANRXDSR0;		/* 1.7-1.8 挂车手制动开关 */
		CanFrame_Rx[ID18FF0B21].data[1].pp = CANRXDSR1;		/* 2.1-2.2 变速箱倒挡开关     	2.7-2.8 挂车功能开关*/
		CanFrame_Rx[ID18FF0B21].data[2].pp = CANRXDSR2;		/* 3.1-3.2 驾驶室锁止开关 3.6-3.7 安全带 */
		CanFrame_Rx[ID18FF0B21].data[3].pp = CANRXDSR3;		/* 4.3-4.4 驾驶员侧门碰开关  4.5-4.6 乘客侧门碰开关 */

	}
	else if((CANRXIDR0 == 0xC7)&&(CANRXIDR1 == 0x98)&&(CANRXIDR2==0x00)&&(CANRXIDR3==0x1E))	// 0x18F0000F	    
	{
		CanFrame_Rx[ID18F0000F].NoComTimeCnt = second_1s;
	}
	else if((CANRXIDR0 == 0xC7)&&(CANRXIDR1 == 0x98)&&(CANRXIDR2==0x02)&&(CANRXIDR3==0x16))	// 0x18F0010B	    
	{
		CanFrame_Rx[ID18F0010B].TOnLineFlg = 1;
		CanFrame_Rx[ID18F0010B].NoComTimeCnt = second_1s;
		CanFrame_Rx[ID18F0010B].data[5].pp = CANRXDSR5;		/* 6.5-6.6 主车ABS指示灯 */

	}
	else if((CANRXIDR0 == 0xC7)&&(CANRXIDR1 == 0xFD)&&(CANRXIDR2==0xFE)&&(CANRXIDR3==0x00))	// 0x18FEFF00	    
	{
		CanFrame_Rx[ID18FEFF00].TOnLineFlg = 1;
		CanFrame_Rx[ID18FEFF00].NoComTimeCnt = second_1s;
		CanFrame_Rx[ID18FEFF00].data[0].pp = CANRXDSR0;
	}
	else if((CANRXIDR0 == 0xC7)&&(CANRXIDR1 == 0xFD)&&(CANRXIDR2==0xE2)&&(CANRXIDR3==0x00))	// 0x18FEF100	    
	{
		CanFrame_Rx[ID18FEF100].NoComTimeCnt = second_1s;
	}
	else if((CANRXIDR0 == 0xC7)&&(CANRXIDR1 == 0xFD)&&(CANRXIDR2==0xC8)&&(CANRXIDR3==0x00))	// 0x18FEE400	       
	{
		CanFrame_Rx[ID18FEE400].NoComTimeCnt = second_1s;
	}
	else if((CANRXIDR0 == 0xC7)&&(CANRXIDR1 == 0xFA)&&(CANRXIDR2==0xF8)&&(CANRXIDR3==0x00))	// 0x18FD7C00	       
	{
		CanFrame_Rx[ID18FD7C00].NoComTimeCnt = second_1s;
	}
	else if((CANRXIDR0 == 0xC7)&&(CANRXIDR1 == 0xFE)&&(CANRXIDR2==0x22)&&(CANRXIDR3==0x20))	// 0x18FF1110	       
	{
		CanFrame_Rx[ID18FF1110].NoComTimeCnt = second_1s;
	}
	else if((CANRXIDR0 == 0xC7)&&(CANRXIDR1 == 0xFD)&&(CANRXIDR2==0xE6)&&(CANRXIDR3==0x00))	// 0x18FEF300    	   
	{
		CanFrame_Rx[ID18FEF300].NoComTimeCnt = second_1s;
	}
	else if((CANRXIDR0 == 0xC7)&&(CANRXIDR1 == 0xFD)&&(CANRXIDR2==0xE8)&&(CANRXIDR3==0x6E))	// 0x18FEF437	       
	{
		CanFrame_Rx[ID18FEF437].NoComTimeCnt = second_1s;
	}
	else if((CANRXIDR0 == 0xC7)&&(CANRXIDR1 == 0xFC)&&(CANRXIDR2==0x49)&&(CANRXIDR3==0xDC))	// 0x18FE24EE	       
	{
		CanFrame_Rx[ID18FE24EE].NoComTimeCnt = second_1s;
	}
	else if((CANRXIDR0 == 0xC7)&&(CANRXIDR1 == 0xFE)&&(CANRXIDR2==0x42)&&(CANRXIDR3==0x42))	//	0x18FF2121
	{
		CanFrame_Rx[ID18FF2121].NoComTimeCnt = second_1s;
	}	
	else if((CANRXIDR0 == 0xC7)&&(CANRXIDR1 == 0xFE)&&(CANRXIDR2==0x44)&&(CANRXIDR3==0x42))	// 0x18FF2221
	{
		CanFrame_Rx[ID18FF2221].TOnLineFlg = 1;
		CanFrame_Rx[ID18FF2221].NoComTimeCnt = second_1s;
		CanFrame_Rx[ID18FF2221].data[0].pp = CANRXDSR0;		
		CanFrame_Rx[ID18FF2221].data[1].pp = CANRXDSR1;		
	}
	else if((CANRXIDR0 == 0xC7)&&(CANRXIDR1 == 0xFA)&&(CANRXIDR2==0x0E)&&(CANRXIDR3==0x00))// 0x18FD0700
	{
		CanFrame_Rx[ID18FD0700].TOnLineFlg = 1;
		CanFrame_Rx[ID18FD0700].NoComTimeCnt = second_1s;
		CanFrame_Rx[ID18FD0700].data[0].pp = CANRXDSR0;
	}
	else if((CANRXIDR0 == 0xC7)&&(CANRXIDR1 == 0xFD)&&(CANRXIDR2==0xE8)&&(CANRXIDR3==0x66))// 0x18FEF433	0x?C7 0xFD 0xE8 0x66
	{
		CanFrame_Rx[ID18FEF433].TOnLineFlg = 1;
		CanFrame_Rx[ID18FEF433].NoComTimeCnt = second_1s;
		CanFrame_Rx[ID18FEF433].data[0].pp = CANRXDSR0;			/* 胎压 */
		CanFrame_Rx[ID18FEF433].data[1].pp = CANRXDSR1;
		CanFrame_Rx[ID18FEF433].data[2].pp = CANRXDSR2;
		CanFrame_Rx[ID18FEF433].data[3].pp = CANRXDSR3;
		CanFrame_Rx[ID18FEF433].data[4].pp = CANRXDSR4;
		CanFrame_Rx[ID18FEF433].data[5].pp = CANRXDSR5;
		CanFrame_Rx[ID18FEF433].data[6].pp = CANRXDSR6;
		CanFrame_Rx[ID18FEF433].data[7].pp = CANRXDSR7;
	}
	else if((CANRXIDR0 == 0xC7)&&(CANRXIDR1 == 0xFD)&&(CANRXIDR2==0xB2)&&(CANRXIDR3==0x2E))// 0x18FED917	0xC7 0xFD 0xB2 0x2E
	{
		CanFrame_Rx[ID18FED917].TOnLineFlg = 1;
		CanFrame_Rx[ID18FED917].NoComTimeCnt = second_1s;
		CanFrame_Rx[ID18FED917].data[0].pp = CANRXDSR0;	
		CanFrame_Rx[ID18FED917].data[1].pp = CANRXDSR1;
	}
	else
	{
		/* do nothing */
	}

	CANRFLG_RXF = 1;        /* Clear RXF 清中断标志*/
	CANRFLG=0xff;
}
#pragma CODE_SEG DEFAULT


#pragma CODE_SEG NON_BANKED
#pragma TRAP_PROC
void  interrupt  TIM1CH5_ISR(void)
{
		//8U 的定时
		TIM1_TC5 =TIM1_TC5 + 30000;//u8_dz;
        #if 0
		if(u8_dz>62500)
		{
			ECU_OUT=0;
		}
		else
		ECU_OUT=!ECU_OUT;
        #endif
		TIM1_TFLG1 = TIM1_TFLG1_C5F_MASK; //Clear channel 6 flag.
}
#pragma CODE_SEG DEFAULT




#pragma CODE_SEG NON_BANKED
#pragma TRAP_PROC
void  interrupt  TIM0CH6_ISR(void)
{
  //	//1ms 的定时
	TIM0_TC6 =TIM0_TC6 + 250; // 250  1ms
	second_1s++;
    SM_Calculate(); //电机运算
    SMG_Driver();

	TIM0_TFLG1 = TIM0_TFLG1_C6F_MASK; //Clear channel 6 flag.
}
#pragma CODE_SEG DEFAULT



#pragma CODE_SEG NON_BANKED
#pragma TRAP_PROC
void  interrupt  TIM1CH4_ISR(void)
{
#if 0
	  
	if( (second_lc-car[0].high_time)<2 ) 
    {
        car[0].loop++;
        if(  TIM1_TC4<  car[0].low_time) 
        {
			lc[car[0].loop]=  (TIM1_TC4-car[0].low_time)>>1;
        }
        else 
        {
			lc[car[0].loop]=  ((TIM1_TC4-car[0].low_time)>>1)+((second_lc-car[0].high_time)<<13);
        }
            
        //lc_num++;
		//if( (lc_num&0x01)==1 )
			//ECU_OUT=!ECU_OUT;			

		car[0].high_time=second_lc;  
        car[0].low_time =TIM1_TC4;
    } 
    else 
    {
        car[0].low_time =TIM1_TC4;
        car[0].high_time=second_lc;     
    }
#else
    unsigned int time1,time2;
    static unsigned char lc_input_bak,lc_li;
   
    unsigned int lc_temp,lc_temp1;
    unsigned int speed_T_cnt;
    //if(TIM0_TFLG1_C5F==0)
    //{
    //    return;
    //}
    if( MCU_I_SPEED_PT0 != lc_input_bak )	
  	{
		 lc_input_bak=MCU_I_SPEED_PT0;	
		 if( (lc_li&0x01) == 1 )
		 {
            	
	        if( (second_lc-car[0].high_time)<2 )  //单沿捕获
            {
                
                if(  TIM1_TC4<  car[0].low_time) 
                {
				    lc_high=  (TIM1_TC4-car[0].low_time)>>1;
                }
                else 
                {
				    lc_high=  ((TIM1_TC4-car[0].low_time)>>1)+((second_lc-car[0].high_time)<<13);
                }
            
                			
                car[0].high_time=second_lc;  
                car[0].low_time =TIM1_TC4;
            }
            
            else 
            {
                car[0].high_time=second_lc;  
                car[0].low_time =TIM1_TC4;
            }
                    #if 1
                    if(lc_high > 40) 	  //T > 30*4*4us =480us	频率小于 2.08K 正常计数
			        		;
			    	else			  //T < 480us F > 2Khz屏蔽
			    	{
				    	lc_li++;
			    	}	
                    #endif
		}
        else
		{
           
			if( (second_lc-car[0].high_time)<2 )  //单沿捕获
            {
                car[0].loop++;
                if(  TIM1_TC4<  car[0].low_time) 
                {
				    lc_low=  (TIM1_TC4-car[0].low_time)>>1;
                }
                else 
                {
				    lc_low=  ((TIM1_TC4-car[0].low_time)>>1)+((second_lc-car[0].high_time)<<13);
                }
                car[0].high_time=second_lc;  
                car[0].low_time =TIM1_TC4;
            }
            else 
            {
                car[0].high_time=second_lc;  
                car[0].low_time =TIM1_TC4;
            }	
            
            if(lc_low>40)   //T > 60*4*4us =960us   约500hz 以上滤除 
            {
                lc_loop++;
                lc[lc_loop]=lc_high+lc_low;
			    lc_num++;	

                //ECU_OUT=!ECU_OUT; 
			    
            }
            else
            {
                
                lc_li++;
            }
			
		}
        
        
        
        
		lc_li++;
    }
	TIM1_TFLG1 = TIM1_TFLG1_C4F_MASK; //Clear channel 4 flag.
#endif
}
#pragma CODE_SEG DEFAULT

#pragma CODE_SEG NON_BANKED
#pragma TRAP_PROC
void  interrupt  TIM1CH0_ISR(void)
{
	//8us


	TIM1_TFLG1 = TIM1_TFLG1_C0F_MASK; //Clear channel 7 flag.
}
#pragma CODE_SEG DEFAULT


#pragma CODE_SEG NON_BANKED
#pragma TRAP_PROC
void  interrupt  TIM1CH6_ISR(void)
{
   /*
        if( (second_lc-car[0].high_time)<2 )
        {
            car[0].loop++;
            car[0].loop=car[0].loop&0x03;

            if(  TIM1_TC6<  car[0].low_time)
            {

            lc[car[0].loop]=  (TIM1_TC6-car[0].low_time)>>2;
            }
            else
            {

            lc[car[0].loop]=  ((TIM1_TC6-car[0].low_time)>>2)+((second_lc-car[0].high_time)<<14);
            }

            lc_num++;
            car[0].high_time=second_lc;
            car[0].low_time =TIM1_TC6;
        }
        else
        {
            car[0].high_time=second_lc;  car[0].low_time =TIM1_TC6;

        }
		*/
		
        TIM1_TFLG1 = TIM1_TFLG1_C6F_MASK; //Clear channel 7 flag.
}
#pragma CODE_SEG DEFAULT


#pragma CODE_SEG NON_BANKED
#pragma TRAP_PROC
void  interrupt  FSL_ISR_Handler(void)
{
    UINT8  registerValue;    /* store data read from flash register */
    /* Disable all flash interrupts */
    FlashInterruptSet(CCIE_INTERRUPT_DISABLE);

    /*Sector erase operation completed */
    /* Check error bits */
    /*Get flash status register value */
    registerValue = REG_READ(SSD_MCU_REGISTER_BASE + FLASH_FSTAT_OFFSET);
    /* checking access error */
    if(0 != (registerValue & FLASH_FSTAT_ACCERR))
    {
        gEE_Error = SGF_ERR_ACCERR;
        eraseStatusFlag = FAIL;
    }
    /* checking protection error */
    else if(0 != (registerValue & FLASH_FSTAT_FPVIOL))
    {
        gEE_Error = SGF_ERR_PVIOL;
        eraseStatusFlag = FAIL;
    }
    /* checking MGSTAT1 error */
    else if(0 != (registerValue & FLASH_FSTAT_MGSTAT1))
    {
        gEE_Error = SGF_ERR_MGSTAT1;
        eraseStatusFlag = FAIL;
    }
    /* checking MGSTAT0 non-correctable error */
    else if(0 != (registerValue & FLASH_FSTAT_MGSTAT0))
    {
        gEE_Error = SGF_ERR_MGSTAT0;
        eraseStatusFlag = FAIL;
    }
    else
    {
        eraseStatusFlag = DONE;
    }
}

#pragma CODE_SEG DEFAULT


#pragma CODE_SEG NON_BANKED
#pragma TRAP_PROC
void  interrupt  TIM1OVER_ISR(void)
{
		//输入捕获时间溢出524.288ms
		second_lc++;
		TIM1_TFLG2 = 0x80;
}


#pragma CODE_SEG DEFAULT

#pragma CODE_SEG NON_BANKED
#pragma TRAP_PROC
void SSD_SGF18_NEAR ExceptionAll(void)
{
    for(;;)
    {
        ;
    }
}
#pragma CODE_SEG DEFAULT



#pragma CODE_SEG NON_BANKED
#pragma TRAP_PROC
void  interrupt  Vcop_ISR(void)
{
	_Startup();
}
#pragma CODE_SEG DEFAULT

#pragma CODE_SEG NON_BANKED
#pragma TRAP_PROC
void  interrupt  Vclkmon_ISR(void)
{
	_Startup();
}
#pragma CODE_SEG DEFAULT


#pragma CODE_SEG NON_BANKED
#pragma TRAP_PROC
void  interrupt  Vlvi_ISR(void)
{
	_Startup();
}
#pragma CODE_SEG DEFAULT



void  ErrorTrap(void)
{
     for(;;)
     ;
}


void CallBackFunc(void)
{
	;
}


/* 单数码管驱动 */
void  SMG_Single_Driver(unsigned        int data)
{
	unsigned char temp_char;
	for( temp_char=0; temp_char<16; temp_char++ )
	{
		//STCP1_PT5=0;
		SCHP1_PT4=0;
		if( (data&0x8000) == 0 )
			DS1_PT6	= 0;
		else
			DS1_PT6	= 1;
		
		__asm(nop);
		__asm(nop);
		
		Delayus(T_596);
		
		//STCP1_PT5=1;
		SCHP1_PT4=1;
		data=data<<1;
		__asm(nop);
		Delayus(T_596);
	}
	//STCP1_PT5=0;
	SCHP1_PT4=0;
	//SCHP1_PT4=1;
	STCP1_PT5=1;
	__asm(nop);__asm(nop);
	Delayus(T_596);
	
	//SCHP1_PT4=0;
	STCP1_PT5=0;
}

/*
//如果带小数点就在高位或上一个0X80
//不带小数点
0: 0x3f
1: 0x06
2: 0x5b
3: 0x4f
4: 0x66
5: 0x6d
6: 0x7d
7: 0x07
8: 0x7f
9: 0x6f
*/

u16 SMG_Dispaly[3];
				   /*  0    1    2    3    4    5    6    7    8    9 */
u16 SMG_Table[10] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};




/* 整个三段数码管驱动 */
void SMG_Driver(void)
{
	static unsigned char SMG_Loop = 0;
	if(SMG_Loop == 0)/* 最高位 */
	{	
		SMG_Single_Driver(0x0000);  //消隐
		SMG_Loop = 1;
		SMGA1_PV7 = 0;
		SMGA2_PS0 = 1;
		SMGA3_PU7 = 1;
		SMG_Single_Driver(SMG_Dispaly[2]);
	}
	else if(SMG_Loop == 1)
	{
		SMG_Single_Driver(0x0000);  //消隐
		SMG_Loop = 2;
		SMGA1_PV7 = 1;
		SMGA2_PS0 = 0;
		SMGA3_PU7 = 1;
		SMG_Single_Driver(SMG_Dispaly[1]);
	}
	else if(SMG_Loop == 2)	/* 最低位 */
	{
		SMG_Single_Driver(0x0000);  //消隐
		SMG_Loop = 0;
		SMGA1_PV7 = 1;
		SMGA2_PS0 = 1;
		SMGA3_PU7 = 0;
		SMG_Single_Driver(SMG_Dispaly[0]);
	}
}


void SMG_Display_Clear(void)
{
	u8 i;
	SMG_Dispaly[0] = 0;
	SMG_Dispaly[1] = 0;
	SMG_Dispaly[2] = 0;

	for(i=0; i<3; i++)
	{
		SMG_Driver();
	}
}


/* 该参数中只有低24位有效，高8位无效 */
void C596A_Driver(u32 Data )
{
	unsigned char temp_char;
	//jcheng7_test1 = 0x00000001;
	for( temp_char=0; temp_char<24; temp_char++ )
	{
		//jcheng7_test2 = temp_char;
		//STCPA_PA4 = 0;
		SCHPA_PA3 = 0;
		if( (Data&0x800000) == 0 )
		//if((temp_char&0x01) == 0)
			DSA_PA2	= 0;
		else
			DSA_PA2	= 1;
		
		__asm(nop);
		__asm(nop);
		
		Delayus(T_596);
		
		//STCPA_PA4 = 1;
		SCHPA_PA3 = 1;
		Data = Data<<1;
		__asm(nop);
		Delayus(T_596);
	}
	//STCPA_PA4 = 0;
	SCHPA_PA3 = 0;
	//SCHPA_PA3 = 1;
	STCPA_PA4 = 1;
	__asm(nop);__asm(nop);
	Delayus(T_596);
	
	//SCHPA_PA3 = 0;
	STCPA_PA4 = 0;
}

void C596X_Driver(u16 Data )
{
	unsigned char temp_char;
	for( temp_char=0; temp_char<16; temp_char++ )
	{
		//STCPA_PA4 =0;
		SCHPA_PA3 = 0;
		if( (Data&0x8000) == 0 )
			DSA_PA2	= 0;
		else
			DSA_PA2	= 1;
		
		__asm(nop);
		__asm(nop);
		
		Delayus(T_596);
		
		//STCPA_PA4 = 1;
		SCHPA_PA3 = 1;
		Data = Data<<1;
		__asm(nop);
		Delayus(T_596);
	}
	//STCPA_PA4 = 0;
	SCHPA_PA3 = 0;
	//SCHPA_PA3 = 1;
	STCPA_PA4 = 1;
	__asm(nop);__asm(nop);
	Delayus(T_596);
	
	//SCHPA_PA3 = 0;
	STCPA_PA4 = 0;
}


void C596B_Driver(u32 Data )
{
	unsigned char temp_char;
	for( temp_char=0; temp_char<24; temp_char++ )
	{
		//STCPB_PS5 =0;
		SCHPB_PS6 = 0;
		if( (Data&0x800000) == 0 )
			DSB_PS7	= 0;
		else
			DSB_PS7	= 1;
		
		__asm(nop);
		__asm(nop);
		
		Delayus(T_596);
		
		//STCPB_PS5 = 1;
		SCHPB_PS6 = 1;
		Data = Data<<1;
		__asm(nop);
		Delayus(T_596);
	}
	//STCPB_PS5 = 0;
	SCHPB_PS6 = 0;
	
	//SCHPB_PS6 = 1;
	STCPB_PS5 = 1;
	__asm(nop);__asm(nop);
	Delayus(T_596);
	
	//SCHPB_PS6 = 0;
	STCPB_PS5 = 0;
}

void C596C_Driver(u32 Data )
{
	unsigned char temp_char;

	for( temp_char=0; temp_char<24; temp_char++ )
	{
		//STCPC_PA0 =0;
		SCHPC_PA1 = 0;
		if( (Data&0x800000) == 0 )
			DSC_PA7	= 0;
		else
			DSC_PA7	= 1;
		
		__asm(nop);
		__asm(nop);
		
		Delayus(T_596);
		
		//STCPC_PA0 = 1;
		SCHPC_PA1 = 1;
		Data = Data<<1;
		__asm(nop);
		Delayus(T_596);
	}
	//STCPC_PA0 = 0;
	SCHPC_PA1 = 0;
	//SCHPC_PA1 = 1;
	STCPC_PA0 = 1;
	__asm(nop);__asm(nop);
	Delayus(T_596);
	
	//SCHPC_PA1 = 0;
	STCPC_PA0 = 0;
}



//#define	HC165_PL	HC165_SHLD_PP3	//PL 并行数据输入使能，低电平有效
//#define	HC165_CLK	HC165_CLK_PP4	//CP 时钟，上升沿触发
//#define	HC165_OUT_A	HC165OUTDATA_A_PT7	//Q7 串行数据输出		
//#define	HC165_OUT_B	HC165OUTDATA_B_PR5	//Q7 串行数据输出		
//#define	HC165_CE	HC165EN_CLK_PP5	//CE 时钟使能，低电平有效

/* 74HC165初始化 */
void NXP74HC165_init(void)
{
	HC165EN_CLK_PP5 = 0; //初始化使能时钟，后面就不需再使能
	HC165_SHLD_PP3 = 1; //PL拉高，不读取按键状态
	HC165_CLK_PP4 = 1; //时钟拉高，便于产生上升沿
}


/* 测试一：单独读取U22的数据没有问题，且数据位正常 */
/* 测试二：单独读取U27的数据，读取出来的数据是没有问题，但是数据反应有点迟钝，会不会和布板有关系 */
u8 NXP74HC165A_DATA_Test;
u8 NXP74HC165B_DATA_Test;

void Receive_74CH165_Read_Byte_Test(void)
{   
	unsigned char i,data=0;
	//u8 dataA = 0;
	u8 dataB = 0;

	HC165EN_CLK_PP5 = 0;
	HC165_SHLD_PP3 = 0;
	HC165_SHLD_PP3 = 1;
	//HC165_CLK_ON;
	HC165_CLK_PP4 = 1;

	for(i = 0; i < 8; i++ ) 
	{
		//HC165_CLK_OFF;
		HC165_CLK_PP4 = 0;
		//HC165_CLK_ON;
		HC165_CLK_PP4 = 1;
	
		//if(HC165OUTDATA_A_PT7 == 0) 
		//{
			//dataA = dataA|0x01;
		//}

		if(HC165OUTDATA_B_PR5 == 0) 
		{
			dataB = dataB|0x01;
		}

		if(i != 7)
		{
			//dataA = dataA<<1;
			dataB = dataB<<1;
		}
		
		//HC165_CLK_ON;
	}
	//HC165_CLK_ON;
	HC165_CLK_PP4 = 1;
	//HC165_SHLD_ON;
	HC165_SHLD_PP3 = 1;

	//NXP74HC165A_DATA_Test = dataA;
	NXP74HC165B_DATA_Test = dataB;
	//NXP74HC165.NXP74HC165A.Byte = dataA;
	//NXP74HC165.NXP74HC165B.Byte = dataB;
}


u32 	NXP74HC165A_DATA;
u32 	NXP74HC165B_DATA;

#if 1
void Receive_74CH165A_Byte(void)
{   
	unsigned char i;//data=0;
	u32 dataA = 0;
	//u32 dataB = 0;

	HC165EN_CLK_PP5 = 0;
	HC165_SHLD_PP3 = 0;
	HC165_SHLD_PP3 = 1;
	//HC165_CLK_ON;
	HC165_CLK_PP4 = 1;

	for(i = 0; i < 24; i++ ) 
	{
		//HC165_CLK_OFF;
		HC165_CLK_PP4 = 0;
		//HC165_CLK_ON;
		HC165_CLK_PP4 = 1;
	
		if(HC165OUTDATA_A_PT7 == 0) 
		{
			dataA = dataA|0x01;
		}

		//if(HC165OUTDATA_B_PR5 == 0) 
		//{
			//dataB = dataB|0x01;
		//}

		if(i != 23)
		{
			dataA = dataA<<1;
			//dataB = dataB<<1;
		}
		
		//HC165_CLK_ON;
	}
	//HC165_CLK_ON;
	HC165_CLK_PP4 = 1;
	//HC165_SHLD_ON;
	HC165_SHLD_PP3 = 1;

	NXP74HC165A_DATA = dataA;
	//NXP74HC165B_DATA = dataB;
	NXP74HC165.NXP74HC165A.Byte = dataA;
	//NXP74HC165.NXP74HC165B.Byte = dataB;
}

void Receive_74CH165B_Byte(void)
{   
	unsigned char i;//data=0;
	//u32 dataA = 0;
	u32 dataB = 0;

	HC165EN_CLK_PP5 = 0;
	HC165_SHLD_PP3 = 0;
	HC165_SHLD_PP3 = 1;
	//HC165_CLK_ON;
	HC165_CLK_PP4 = 1;

	for(i = 0; i < 24; i++ ) 
	{
		//HC165_CLK_OFF;
		HC165_CLK_PP4 = 0;
		//HC165_CLK_ON;
		HC165_CLK_PP4 = 1;
	
		//if(HC165OUTDATA_A_PT7 == 0) 
		//{
			//dataA = dataA|0x01;
		//}

		if(HC165OUTDATA_B_PR5 == 0) 
		{
			dataB = dataB|0x01;
		}

		if(i != 23)
		{
			//dataA = dataA<<1;
			dataB = dataB<<1;
		}
		
		//HC165_CLK_ON;
	}
	//HC165_CLK_ON;
	HC165_CLK_PP4 = 1;
	//HC165_SHLD_ON;
	HC165_SHLD_PP3 = 1;

	//NXP74HC165A_DATA = dataA;
	NXP74HC165B_DATA = dataB;
	//NXP74HC165.NXP74HC165A.Byte = dataA;
	NXP74HC165.NXP74HC165B.Byte = dataB;
}


void Receive_74CH165_Byte(void)
{
#if 1
	static u8 Roll_Counter = 0;

	if(Roll_Counter == 0)
	{
		Roll_Counter = 1;
		Receive_74CH165A_Byte();
	}
	else
	{
		Roll_Counter = 0;
		Receive_74CH165B_Byte();
	}

#else
	unsigned char i,data=0;
	u32 dataA = 0;
	u32 dataB = 0;

	HC165EN_CLK_PP5 = 0;
	HC165_SHLD_PP3 = 0;
	HC165_SHLD_PP3 = 1;
	//HC165_CLK_ON;
	HC165_CLK_PP4 = 1;

	for(i = 0; i < 24; i++ ) 
	{
		//HC165_CLK_OFF;
		HC165_CLK_PP4 = 0;
		//HC165_CLK_ON;
		HC165_CLK_PP4 = 1;
	
		if(HC165OUTDATA_A_PT7 == 0) 
		{
			dataA = dataA|0x01;
		}

		if(HC165OUTDATA_B_PR5 == 0) 
		{
			dataB = dataB|0x01;
		}

		if(i != 23)
		{
			dataA = dataA<<1;
			dataB = dataB<<1;
		}
		
		//HC165_CLK_ON;
	}
	//HC165_CLK_ON;
	HC165_CLK_PP4 = 1;
	//HC165_SHLD_ON;
	HC165_SHLD_PP3 = 1;

	NXP74HC165A_DATA = dataA;
	NXP74HC165B_DATA = dataB;
	NXP74HC165.NXP74HC165A.Byte = dataA;
	NXP74HC165.NXP74HC165B.Byte = dataB;

#endif
}

#else
void Receive_74CH165A_Byte(void)
{   
	unsigned char i,data=0;
	u32 dataA = 0;
	u32 dataB = 0;

	HC165EN_CLK_PP5 = 0;
	HC165_SHLD_PP3 = 0;
	HC165_SHLD_PP3 = 1;
	//HC165_CLK_ON;
	HC165_CLK_PP4 = 1;

	if(HC165OUTDATA_A_PT7 == 0) 
	{
		dataA = dataA|0x01;
	}

	if(HC165OUTDATA_B_PR5 == 0) 
	{
		dataB = dataB|0x01;
	}

	for(i = 0; i < 23; i++ ) 
	{
		// if(i != 23)
		// {
		// 	dataA = dataA<<1;
		// 	dataB = dataB<<1;
		// }

		dataA = dataA<<1;
		dataB = dataB<<1;
		//HC165_CLK_OFF;
		HC165_CLK_PP4 = 0;
		//HC165_CLK_ON;
		HC165_CLK_PP4 = 1;
	
		if(HC165OUTDATA_A_PT7 == 0) 
		{
			dataA = dataA|0x01;
		}

		if(HC165OUTDATA_B_PR5 == 0) 
		{
			dataB = dataB|0x01;
		}
		//HC165_CLK_ON;
	}
	//dataA = dataA<<1;
	//HC165_CLK_ON;
	HC165_CLK_PP4 = 1;
	//HC165_SHLD_ON;
	HC165_SHLD_PP3 = 1;

	NXP74HC165.NXP74HC165A.Byte = dataA;
	NXP74HC165.NXP74HC165B.Byte = dataB;
}
#endif


#define	Tacho_0_Ge	{LED_31=0;LED_32=0;LED_33=0;LED_34=0;LED_35=0;LED_36=0;LED_37=0;LED_38=0;LED_39=0;LED_40=0;LED_41=0;LED_42=0;LED_43=0;LED_44=0;LED_45=0;LED_46=0;LED_47=0;LED_48=0;LED_49=0;LED_50=0;}
#define	Tacho_1_Ge	{LED_31=1;LED_32=0;LED_33=0;LED_34=0;LED_35=0;LED_36=0;LED_37=0;LED_38=0;LED_39=0;LED_40=0;LED_41=0;LED_42=0;LED_43=0;LED_44=0;LED_45=0;LED_46=0;LED_47=0;LED_48=0;LED_49=0;LED_50=0;}
#define	Tacho_2_Ge	{LED_31=1;LED_32=1;LED_33=0;LED_34=0;LED_35=0;LED_36=0;LED_37=0;LED_38=0;LED_39=0;LED_40=0;LED_41=0;LED_42=0;LED_43=0;LED_44=0;LED_45=0;LED_46=0;LED_47=0;LED_48=0;LED_49=0;LED_50=0;}
#define	Tacho_3_Ge	{LED_31=1;LED_32=1;LED_33=1;LED_34=0;LED_35=0;LED_36=0;LED_37=0;LED_38=0;LED_39=0;LED_40=0;LED_41=0;LED_42=0;LED_43=0;LED_44=0;LED_45=0;LED_46=0;LED_47=0;LED_48=0;LED_49=0;LED_50=0;}
#define	Tacho_4_Ge	{LED_31=1;LED_32=1;LED_33=1;LED_34=1;LED_35=0;LED_36=0;LED_37=0;LED_38=0;LED_39=0;LED_40=0;LED_41=0;LED_42=0;LED_43=0;LED_44=0;LED_45=0;LED_46=0;LED_47=0;LED_48=0;LED_49=0;LED_50=0;}
#define	Tacho_5_Ge	{LED_31=1;LED_32=1;LED_33=1;LED_34=1;LED_35=1;LED_36=0;LED_37=0;LED_38=0;LED_39=0;LED_40=0;LED_41=0;LED_42=0;LED_43=0;LED_44=0;LED_45=0;LED_46=0;LED_47=0;LED_48=0;LED_49=0;LED_50=0;}
#define	Tacho_6_Ge	{LED_31=1;LED_32=1;LED_33=1;LED_34=1;LED_35=1;LED_36=1;LED_37=0;LED_38=0;LED_39=0;LED_40=0;LED_41=0;LED_42=0;LED_43=0;LED_44=0;LED_45=0;LED_46=0;LED_47=0;LED_48=0;LED_49=0;LED_50=0;}
#define	Tacho_7_Ge	{LED_31=1;LED_32=1;LED_33=1;LED_34=1;LED_35=1;LED_36=1;LED_37=1;LED_38=0;LED_39=0;LED_40=0;LED_41=0;LED_42=0;LED_43=0;LED_44=0;LED_45=0;LED_46=0;LED_47=0;LED_48=0;LED_49=0;LED_50=0;}
#define	Tacho_8_Ge	{LED_31=1;LED_32=1;LED_33=1;LED_34=1;LED_35=1;LED_36=1;LED_37=1;LED_38=1;LED_39=0;LED_40=0;LED_41=0;LED_42=0;LED_43=0;LED_44=0;LED_45=0;LED_46=0;LED_47=0;LED_48=0;LED_49=0;LED_50=0;}
#define	Tacho_9_Ge	{LED_31=1;LED_32=1;LED_33=1;LED_34=1;LED_35=1;LED_36=1;LED_37=1;LED_38=1;LED_39=1;LED_40=0;LED_41=0;LED_42=0;LED_43=0;LED_44=0;LED_45=0;LED_46=0;LED_47=0;LED_48=0;LED_49=0;LED_50=0;}
#define	Tacho_10_Ge	{LED_31=1;LED_32=1;LED_33=1;LED_34=1;LED_35=1;LED_36=1;LED_37=1;LED_38=1;LED_39=1;LED_40=1;LED_41=0;LED_42=0;LED_43=0;LED_44=0;LED_45=0;LED_46=0;LED_47=0;LED_48=0;LED_49=0;LED_50=0;}
#define	Tacho_11_Ge	{LED_31=1;LED_32=1;LED_33=1;LED_34=1;LED_35=1;LED_36=1;LED_37=1;LED_38=1;LED_39=1;LED_40=1;LED_41=1;LED_42=0;LED_43=0;LED_44=0;LED_45=0;LED_46=0;LED_47=0;LED_48=0;LED_49=0;LED_50=0;}
#define	Tacho_12_Ge	{LED_31=1;LED_32=1;LED_33=1;LED_34=1;LED_35=1;LED_36=1;LED_37=1;LED_38=1;LED_39=1;LED_40=1;LED_41=1;LED_42=1;LED_43=0;LED_44=0;LED_45=0;LED_46=0;LED_47=0;LED_48=0;LED_49=0;LED_50=0;}
#define	Tacho_13_Ge	{LED_31=1;LED_32=1;LED_33=1;LED_34=1;LED_35=1;LED_36=1;LED_37=1;LED_38=1;LED_39=1;LED_40=1;LED_41=1;LED_42=1;LED_43=1;LED_44=0;LED_45=0;LED_46=0;LED_47=0;LED_48=0;LED_49=0;LED_50=0;}
#define	Tacho_14_Ge	{LED_31=1;LED_32=1;LED_33=1;LED_34=1;LED_35=1;LED_36=1;LED_37=1;LED_38=1;LED_39=1;LED_40=1;LED_41=1;LED_42=1;LED_43=1;LED_44=1;LED_45=0;LED_46=0;LED_47=0;LED_48=0;LED_49=0;LED_50=0;}
#define	Tacho_15_Ge	{LED_31=1;LED_32=1;LED_33=1;LED_34=1;LED_35=1;LED_36=1;LED_37=1;LED_38=1;LED_39=1;LED_40=1;LED_41=1;LED_42=1;LED_43=1;LED_44=1;LED_45=1;LED_46=0;LED_47=0;LED_48=0;LED_49=0;LED_50=0;}
#define	Tacho_16_Ge	{LED_31=1;LED_32=1;LED_33=1;LED_34=1;LED_35=1;LED_36=1;LED_37=1;LED_38=1;LED_39=1;LED_40=1;LED_41=1;LED_42=1;LED_43=1;LED_44=1;LED_45=1;LED_46=1;LED_47=0;LED_48=0;LED_49=0;LED_50=0;}
#define	Tacho_17_Ge	{LED_31=1;LED_32=1;LED_33=1;LED_34=1;LED_35=1;LED_36=1;LED_37=1;LED_38=1;LED_39=1;LED_40=1;LED_41=1;LED_42=1;LED_43=1;LED_44=1;LED_45=1;LED_46=1;LED_47=1;LED_48=0;LED_49=0;LED_50=0;}
#define	Tacho_18_Ge	{LED_31=1;LED_32=1;LED_33=1;LED_34=1;LED_35=1;LED_36=1;LED_37=1;LED_38=1;LED_39=1;LED_40=1;LED_41=1;LED_42=1;LED_43=1;LED_44=1;LED_45=1;LED_46=1;LED_47=1;LED_48=1;LED_49=0;LED_50=0;}
#define	Tacho_19_Ge	{LED_31=1;LED_32=1;LED_33=1;LED_34=1;LED_35=1;LED_36=1;LED_37=1;LED_38=1;LED_39=1;LED_40=1;LED_41=1;LED_42=1;LED_43=1;LED_44=1;LED_45=1;LED_46=1;LED_47=1;LED_48=1;LED_49=1;LED_50=0;}
#define	Tacho_20_Ge	{LED_31=1;LED_32=1;LED_33=1;LED_34=1;LED_35=1;LED_36=1;LED_37=1;LED_38=1;LED_39=1;LED_40=1;LED_41=1;LED_42=1;LED_43=1;LED_44=1;LED_45=1;LED_46=1;LED_47=1;LED_48=1;LED_49=1;LED_50=1;}



/* 转速需要自检结束之后才能显示 */
void zs_control(void)
{
	unsigned int temp_CJF1,temp_CJF2;
	unsigned char temp_0,temp_1,temp_2;
if(pro_start > 0)
{
	//temp_CJF1=	CanFrame_Rx[ID0CF00400].data[4].pp;		/* 已经直接在CAN接收中断中获取了转速值 */
	//temp_CJF2=	CanFrame_Rx[ID0CF00400].data[3].pp;
	//tachodata = (temp_CJF1<<8) + temp_CJF2;
	tachodata = tachodata/80;			/* 0.125的分辨率，显示值为100r/min 此处放大10倍*/
	
	//if(tachodata>99)
		//tachodata=99;

	if(tachodata>300)
		tachodata=300;
	
	Smeter[Mc_Tacho].inp=tachodata;			/* 转速显示目标值 */

	temp_CJF1 = Smeter[Mc_Tacho].m_new;
	//temp_CJF1 = NXP74HC165A_DATA_Test;
	//temp_CJF1 = NXP74HC165B_DATA_Test;
	//temp_CJF1 = (NXP74HC165A_DATA&0x000000FF);
	
	temp_0 = temp_CJF1%10; 	temp_CJF1 = temp_CJF1/10;
	temp_1 = temp_CJF1%10; 	temp_CJF1 = temp_CJF1/10;
	temp_2 = temp_CJF1%10;
	
	SMG_Dispaly[0] = (SMG_Dispaly[0]&0xFF00)|SMG_Table[temp_0];
	SMG_Dispaly[1] = (SMG_Dispaly[1]&0xFF00)|(SMG_Table[temp_1]|0x80);/* 增加一个小数点 */
	SMG_Dispaly[2] = (SMG_Dispaly[2]&0xFF00)|SMG_Table[temp_2];

	temp_CJF1 = Smeter[Mc_Tacho].m_new;
	
	if(temp_CJF1 <= 17)
	{ Tacho_0_Ge }
	else if(temp_CJF1 <= 34)
	{ Tacho_1_Ge }
	else if(temp_CJF1 <= 51)
	{ Tacho_2_Ge }
	else if(temp_CJF1 <= 68)
	{ Tacho_3_Ge }
	else if(temp_CJF1 <= 85)
	{ Tacho_4_Ge }
	else if(temp_CJF1 <= 102)
	{ Tacho_5_Ge }
	else if(temp_CJF1 <= 120)
	{ Tacho_6_Ge }

	else if(temp_CJF1 <= 132)
	{ Tacho_7_Ge }
	else if(temp_CJF1 <= 144)
	{ Tacho_8_Ge }
	else if(temp_CJF1 <= 156)
	{ Tacho_9_Ge }
	else if(temp_CJF1 <= 168)
	{ Tacho_10_Ge }
	else if(temp_CJF1 <= 180)
	{ Tacho_11_Ge }

	else if(temp_CJF1 <= 195)
	{ Tacho_12_Ge }
	else if(temp_CJF1 <= 210)
	{ Tacho_13_Ge }
	else if(temp_CJF1 <= 225)
	{ Tacho_14_Ge }
	else if(temp_CJF1 <= 240)
	{ Tacho_15_Ge }

	else if(temp_CJF1 <= 255)
	{ Tacho_16_Ge }
	else if(temp_CJF1 <= 270)
	{ Tacho_17_Ge }
	else if(temp_CJF1 <= 285)
	{ Tacho_18_Ge }
	else if(temp_CJF1 <= 290)
	{ Tacho_19_Ge }
	else if(temp_CJF1 <= 300)
	{ Tacho_20_Ge }
	else
	{/* 超出显示范围或者网络出问题 */}
#if 0
	if(temp_CJF1 <= 17)
	{
		/* 1200转速内部有7个灯，需要做均分显示 */
	}
	else if(temp_CJF1 <= 18)
	{
		/* 满足该条件需要将1200转速内的7个灯全部点亮 
		   12-18内有5个灯，需要做均分显示 */
	}
	else if(temp_CJF1 <= 24)
	{
		/* 显示原则同上 18-24之间有4个灯，做均分显示 */
	}
	else if(temp_CJF1 <= 30)
	{
		/* 显示原则同上 24-30之间有4个灯，做均分显示 */
	}
	else
	{
		/* 超出显示范围或者有错误 */
	}
#endif
}
}


void lc_control(void)
{
	u8 temp_9;
	u16 maxx,minx;
	u8 gg_loop,array_sum=0;
	u32 input=0,inputA=0;				
	gg_loop=lc_loop-7;
	maxx=lc[gg_loop];minx=lc[gg_loop];

	for(temp_9=((u8)(gg_loop+1));temp_9<((u8)(gg_loop+8));temp_9++)
	{	
		if(lc[temp_9]>maxx)
			maxx=lc[temp_9];
		if(lc[temp_9]<minx)
			minx=lc[temp_9];		
	}	
	
	if(minx>30)
	{
		if(minx<6000)
			minx=maxx>>2;
		else
			minx=maxx>>1;

		input=0;
		for(temp_9=((u8)(gg_loop+1));temp_9<((u8)(gg_loop+8));temp_9++)	
		{	
			if( (maxx-lc[temp_9])<minx )
			{
				input=input+lc[temp_9];
				array_sum++;
			}
		}
		if(array_sum>4)		
		{	
			array_sum--;
			input=input-maxx;					
			input=input/array_sum;
			//yytest =	input;
			if( input<15624  )		// 	 4HZ
			{			 									
				inputA=(unsigned long int)(LC_DZ/input);
                //inputA/=3;
                if(inputA>720)inputA=720;
                Smeter[Mc_Speed].inp=inputA;
                
                /*
				if(sml_inp>24)
				{
					sml_inp = sml_inp+48;
				}	
				
				if(sml_inp>5000)
					sml_inp=5000;	
				*/
			} 
			else
			{			
		 		Smeter[Mc_Speed].inp = 0;	
		 	} 		 		
		}			 							
	}
		
	    if( (second_lc-car[0].high_time)>1 )
		{	  	
                lc_loop++;
				lc[lc_loop]=50000;	
				Smeter[Mc_Speed].inp=0;	
		}
		else
		{					
			while(minx!=TIM1_TCNT)
			minx=TIM1_TCNT;
			
			if(  minx<  car[0].low_time) 
            {
				maxx=  (minx-car[0].low_time)>>1;
            }
            else 
            {        
				maxx=  ((minx-car[0].low_time)>>1)+((second_lc-car[0].high_time)<<13);
            }
  
			   
			if( maxx>50000 )
            {
					Smeter[Mc_Speed].inp=0;
                    lc_loop++;
                    
					lc[lc_loop]=50000;	
            }   
            else
            {	
					
					if( maxx>( lc[lc_loop]+500) )
                    {	
              				lc_loop++;
				        	lc[lc_loop]=maxx;	
				        	lc_loop++;
				        	lc[lc_loop]=maxx;
                      	
				     }      	
            }  
		}
		
		
	//if( (second_1s-second_speed_out)>300 )
	//{	
		//second_speed_out=second_1s;
		//speed_out_pro();		//求u8_dz的值
	//}	
}


/* 机油压力处理 */
u16 RX_EngOilPress_Bak;

void EngOilPress_Control(void)
{
	u16 temp;
	u8 temp_0,temp_1,temp_2;
	//static u16 RX_EngOilPress_Bak;
	
	temp = RX_EngOilPress;
	temp = (temp<<2);			// 转换成实际的机油压力值，单位位kPa
	//temp = temp/10;			// 将kPa转换成bar , 0.1Bar

	if(temp > RX_EngOilPress_Bak)
        RX_EngOilPress_Bak++;
    else if(temp < RX_EngOilPress_Bak)
        RX_EngOilPress_Bak--;
	else
		;

	temp = RX_EngOilPress_Bak;
	if(temp<100)
		temp=0;
	temp_0 = temp%10; 	temp = temp/10;
	temp_1 = temp%10; 	temp = temp/10;
	temp_2 = temp%10;
	
	SMG_Dispaly[0] = (SMG_Dispaly[0]&0x00FF)|(SMG_Table[temp_0]<<8);
	SMG_Dispaly[1] = (SMG_Dispaly[1]&0x00FF)|(SMG_Table[temp_1]<<8);		
	SMG_Dispaly[2] = (SMG_Dispaly[2]&0x00FF)|((SMG_Table[temp_2]|0x80)<<8);	// 增加一个小数点 ,直接就把kPa转换成Bar

}



void EngOilPress_Warning_Process(void)
{
#if 1
	if((RX_EngOilPress_Bak < 80)||(CanFrame_Rx[ID18FEEF00].TOnLineFlg == 0) )	/* 机油压力低于80kPa或者数据丢失则进行报警 */
	{
		//LED_23 = 1;
		LED_23 = 0;	//暂时屏蔽
	}
	else if(RX_EngOilPress_Bak > 90)
	{
		LED_23 = 0;
	}
#endif
}



/* LED初始化 */
void LED_INT(void)
{
	C596.C596A.Byte = 0x00FFFFFF;	
	C596.C596B.Byte = 0x00200000;
	C596.C596C.Byte = 0x00E00000;

	C596A_Driver(C596.C596A.Byte);
	C596B_Driver(C596.C596B.Byte);
	C596C_Driver(C596.C596C.Byte);
}

/* LED全部熄灭 */
void LED_Clear(void)
{
	C596.C596A.Byte = 0x00000000;	
	C596.C596B.Byte = 0x00000000;
	C596.C596C.Byte = 0x00000000;
	//LED_Process();
	C596A_Driver(C596.C596A.Byte);
	C596B_Driver(C596.C596B.Byte);
	C596C_Driver(C596.C596C.Byte);
}



#define	Fuel_0_Ge	{LED_63=0;LED_64=0;LED_65=0;LED_66=0;LED_67=0;LED_68=0;LED_51=0;LED_52=0;LED_69=0;LED_70=0;}
#define	Fuel_1_Ge	{LED_63=1;LED_64=0;LED_65=0;LED_66=0;LED_67=0;LED_68=0;LED_51=0;LED_52=0;LED_69=0;LED_70=0;}
#define	Fuel_2_Ge	{LED_63=1;LED_64=1;LED_65=0;LED_66=0;LED_67=0;LED_68=0;LED_51=0;LED_52=0;LED_69=0;LED_70=0;}
#define	Fuel_3_Ge	{LED_63=1;LED_64=1;LED_65=1;LED_66=0;LED_67=0;LED_68=0;LED_51=0;LED_52=0;LED_69=0;LED_70=0;}
#define	Fuel_4_Ge	{LED_63=1;LED_64=1;LED_65=1;LED_66=1;LED_67=0;LED_68=0;LED_51=0;LED_52=0;LED_69=0;LED_70=0;}
#define	Fuel_5_Ge	{LED_63=1;LED_64=1;LED_65=1;LED_66=1;LED_67=1;LED_68=0;LED_51=0;LED_52=0;LED_69=0;LED_70=0;}
#define	Fuel_6_Ge	{LED_63=1;LED_64=1;LED_65=1;LED_66=1;LED_67=1;LED_68=1;LED_51=0;LED_52=0;LED_69=0;LED_70=0;}
#define	Fuel_7_Ge	{LED_63=1;LED_64=1;LED_65=1;LED_66=1;LED_67=1;LED_68=1;LED_51=1;LED_52=0;LED_69=0;LED_70=0;}
#define	Fuel_8_Ge	{LED_63=1;LED_64=1;LED_65=1;LED_66=1;LED_67=1;LED_68=1;LED_51=1;LED_52=1;LED_69=0;LED_70=0;}
#define	Fuel_9_Ge	{LED_63=1;LED_64=1;LED_65=1;LED_66=1;LED_67=1;LED_68=1;LED_51=1;LED_52=1;LED_69=1;LED_70=0;}
#define	Fuel_10_Ge	{LED_63=1;LED_64=1;LED_65=1;LED_66=1;LED_67=1;LED_68=1;LED_51=1;LED_52=1;LED_69=1;LED_70=1;}


#define	Sw_0_Ge		{LED_53=0;LED_54=0;LED_55=0;LED_56=0;LED_57=0;LED_58=0;LED_59=0;LED_60=0;LED_61=0;LED_62=0;}
#define	Sw_1_Ge		{LED_53=1;LED_54=0;LED_55=0;LED_56=0;LED_57=0;LED_58=0;LED_59=0;LED_60=0;LED_61=0;LED_62=0;}
#define	Sw_2_Ge		{LED_53=1;LED_54=1;LED_55=0;LED_56=0;LED_57=0;LED_58=0;LED_59=0;LED_60=0;LED_61=0;LED_62=0;}
#define	Sw_3_Ge		{LED_53=1;LED_54=1;LED_55=1;LED_56=0;LED_57=0;LED_58=0;LED_59=0;LED_60=0;LED_61=0;LED_62=0;}
#define	Sw_4_Ge		{LED_53=1;LED_54=1;LED_55=1;LED_56=1;LED_57=0;LED_58=0;LED_59=0;LED_60=0;LED_61=0;LED_62=0;}
#define	Sw_5_Ge		{LED_53=1;LED_54=1;LED_55=1;LED_56=1;LED_57=1;LED_58=0;LED_59=0;LED_60=0;LED_61=0;LED_62=0;}
#define	Sw_6_Ge		{LED_53=1;LED_54=1;LED_55=1;LED_56=1;LED_57=1;LED_58=1;LED_59=0;LED_60=0;LED_61=0;LED_62=0;}
#define	Sw_7_Ge		{LED_53=1;LED_54=1;LED_55=1;LED_56=1;LED_57=1;LED_58=1;LED_59=1;LED_60=0;LED_61=0;LED_62=0;}
#define	Sw_8_Ge		{LED_53=1;LED_54=1;LED_55=1;LED_56=1;LED_57=1;LED_58=1;LED_59=1;LED_60=1;LED_61=0;LED_62=0;}
#define	Sw_9_Ge		{LED_53=1;LED_54=1;LED_55=1;LED_56=1;LED_57=1;LED_58=1;LED_59=1;LED_60=1;LED_61=1;LED_62=0;}
#define	Sw_10_Ge	{LED_53=1;LED_54=1;LED_55=1;LED_56=1;LED_57=1;LED_58=1;LED_59=1;LED_60=1;LED_61=1;LED_62=1;}

//#define Sw_Ge(ge)	Sw_##ge
//#define Fuel_Ge(ge)	Fuel_##ge


void LED_Temp_Fuel_Signal_Process(void)
{
	static unsigned char Fuel_ge_Bak = 0;
	static unsigned char sw_ge_Bak = 0;

	if(Fuel_ge != Fuel_ge_Bak)
	{
		Fuel_ge_Bak = Fuel_ge;
		if(Fuel_ge_Bak == 0)
			{Fuel_0_Ge}
		else if(Fuel_ge_Bak == 1)
			{Fuel_1_Ge}
		else if(Fuel_ge_Bak == 2)
			{Fuel_2_Ge}
		else if(Fuel_ge_Bak == 3)
			{Fuel_3_Ge}
		else if(Fuel_ge_Bak == 4)
			{Fuel_4_Ge}
		else if(Fuel_ge_Bak == 5)
			{Fuel_5_Ge}
		else if(Fuel_ge_Bak == 6)
			{Fuel_6_Ge}
		else if(Fuel_ge_Bak == 7)
			{Fuel_7_Ge}
		else if(Fuel_ge_Bak == 8)
			{Fuel_8_Ge}
		else if(Fuel_ge_Bak == 9)
			{Fuel_9_Ge}
		else if(Fuel_ge_Bak == 10)
			{Fuel_10_Ge}
		else
			{Fuel_0_Ge}
		
			
		
	}

	if(sw_ge != sw_ge_Bak)
	{
		sw_ge_Bak = sw_ge;
		if(sw_ge_Bak == 0)
			{Sw_0_Ge}
		else if(sw_ge_Bak == 1)
			{Sw_1_Ge}
		else if(sw_ge_Bak == 2)
			{Sw_2_Ge}
		else if(sw_ge_Bak == 3)
			{Sw_3_Ge}
		else if(sw_ge_Bak == 4)
			{Sw_4_Ge}
		else if(sw_ge_Bak == 5)
			{Sw_5_Ge}
		else if(sw_ge_Bak == 6)
			{Sw_6_Ge}
		else if(sw_ge_Bak == 7)
			{Sw_7_Ge}
		else if(sw_ge_Bak == 8)
			{Sw_8_Ge}
		else if(sw_ge_Bak == 9)
			{Sw_9_Ge}
		else if(sw_ge_Bak == 10)
			{Sw_10_Ge}
		else
			{Sw_0_Ge}
	}

}


u8 Loop_500ms;
u8 Loop_500ms_Count;

void LED_Signal_Process(void)
{
	LED_Temp_Fuel_Signal_Process();

#if 0
	if(Loop_500ms != 0)
	{
		LED_6 = 1;
	}
	else
	{
		LED_6 = 0;
	}
#endif
	
	/* 近光灯 */
	if(RX_LowBeamSt == 1)
	{
		LED_6 = 1;
	}
	else	
	{
		LED_6 = 0;
	}

	/* 制动灯状态 驻车制动(L/CAN) */
#if 1
	if(Hardware_I_STOP==0)
		//LED_11=1;
		LED_11=0;	// 暂时屏蔽
	else
		LED_11=0;
#endif


	/* 位置灯 示宽灯 */
	if(RX_PostionLightSt == 1)
	{
		LED_5 = 1;
		PWMDTY0 = 50;		// 表盘背光
		PWMDTY1 = 50;		// LCD背光
	}
	else
	{
		LED_5 = 0;
		PWMDTY0 = 250;		// 表盘背光
		PWMDTY1 = 250;		// LCD背光
	}
	

	/* 右转向灯 */
	if(RX_RightTurnLightSt == 1)
	{
		LED_15 = 1;
	}
	else
	{
		LED_15 = 0;
	}

	/* 左转向灯 */
	if(RX_LeftTurnLightSt == 1)
	{
		LED_1 = 1;
	}
	else
	{
		LED_1 = 0;
	}

	/* 远光指示灯 */
	if(RX_HighBeamSt == 1)
	{
		LED_7 = 1;
	}
	else
	{
		LED_7 = 0;
	}

	/* 超车状态指示 */
	/*
	if(RX_OvertakeLightSt == 1)
	{
	
	}
	else
	{
	
	}*/

	/* 前雾指示灯 */
	if(RX_FrontFogSt == 1)
	{
		LED_4 = 1;
	}
	else
	{
		LED_4 = 0;
	}

	/* 后雾指示灯 */
	if(RX_RearFogSt == 1)
	{
		LED_3 = 1;
	}
	else
	{
		LED_3 = 0;
	}

	

	/* 车门开指示(L/CAN)   车门未关指示灯*/
	if(((RX_LeftLockSt == 0)||(RX_RightLockSt == 0))&&CanFrame_Rx[ID18FF0C21].TOnLineFlg==1)
	{
		LED_10 = 1;	/* 点亮门开指示灯 */
	}
	else
	{
		LED_10 = 0;
	}

	/* 后工作指示灯(直接接IO口)*/
	if(MCU_I_BWL_PH4==1)
		LED_14=1;
	else
		LED_14=0;
	


	/* 制动蹄片磨损报警灯*/
	if(Hardware_I_BrakePadPear==1)
		LED_18=1;
	else
		LED_18=0;

	/* 冷却液位低指示灯(液晶显示) */
	// if(Hardware_I_LOW_COOLING_LEVEL==0)
	// 	LED_19=1;
	// else
	// 	LED_19=0;
	
	

	/* 挂车左转向(H/CAN) */
	LED_16 = 0;
#if 0
	if(MCU_I_TURNL_TRAILER_PH3 = 1)
		LED_16 = 1;
	else
		LED_16 = 0;
#endif

	/* 挂车右转向(H/CAN) */
	LED_28 = 0;
#if 0
	if(MCU_I_TURNR_TRAILER_PH2 = 1)
		LED_28 = 1;
	else
		LED_28 = 0;
#endif

	/* 主车ABS指示灯 */
#if 0
	if(Hardware_I_MAIN_ABS==0)
		LED_22=1;
	else
		LED_22=0;
#else
	if(RX_EBS_AmberWarningLampStatus==1)
		LED_22=1;
	else
		LED_22=0;
#endif

	/* 挂车ABS指示灯 */ /* 挂车ABS指示灯可能需要确认 */
	if((RX_IC_TrailerABSfullyoperational==1)&&(RX_IC_TrailerABSdtcted==1)&&(RX_IC_Trailercncted==1))
		LED_21=1;
	else
		LED_21=0;

	/* 取力器指示灯 */
#if 0
	/* 硬线取力器 取力器电磁阀故障状态 */
	if(Hardware_I_POWER_TAKE_OFF==0)
		LED_24=1;
	else
		LED_24=0;
#else
	/* CAN线取力器 */
	if(RX_BCM_PTO_Err != 0)
		LED_24=1;
	else
		LED_24=0;
#endif	



	
	/* 排气制动指示灯 */
#if 1
	if(Hardware_I_Exhaust_Brake==0)
		LED_8=1;
	else
		LED_8=0;
#else
	/* 预留CAN网络信号 */
#endif



	/* 后工作灯(H) */
	if(MCU_I_BWL_PH4 == 1)
		LED_14 = 1;
	else
		LED_14 = 0;

	/* 车箱举升(H) */
	if(Hardware_I_CAR_LIFT == 1)
		LED_17 = 1;
	else
		LED_17 = 0;

	/* 燃油预热指示(H/CAN) */
#if 1
	if(Hardware_I_FUEL_PREHEATING == 1)
		//LED_27 = 1;
		LED_27 = 0;
	else
		LED_27 = 0;
#endif

	/* 安全带指示(L) */
#if 0
	if(Hardware_I_SITBELT == 0)
		LED_9 = 1;
	else
		LED_9 = 0;
#else
	if(RX_SeatBeltSw == 1)
		LED_9 = 1;
	else
		LED_9 = 0;	
#endif

	
	/* EBS故障指示灯(L/CAN) */
#if 0
#else
	//if()
#endif

	/* 油中有水报警灯 */
	if( RX_EMS_WaterInFuelIndicator == 1 )
		LED_26 = 1;
	else
		LED_26 = 0;


	/* 发动机停车报警灯 */
	if(RX_EMS_RedStopLampState == 1)
		LED_20 = 1;
	else
		LED_20 = 0;

	/* 驾驶室翻转指示灯 */
	if(RX_BCM_CabRolloverErr != 0)
		LED_12 = 1;
	else
		LED_12 = 0;

	/* OBD故障指示灯命令 */
	if(RX_EMS_OBDMalfunctionIndicatorLampCmd == 1)
		LED_25 = 1;
	else
		LED_25 = 0;
		
	
	/* 液力缓速器指示(H) */
	
	/* 制动气压低报警 */
	PRE_Warning_Process();
	/* EBS故障指示灯(L/CAN)  LCD 中显示*/
	/* 轮间差速指示(L) LCD中显示 */
	/* 轴间差速指示(L) LCD中显示 */
	/* 胎压报警 */
	LED_19 = 0;
	
	/* DPF 再生指示灯 */
	/* 机油压力报警灯 */
	EngOilPress_Warning_Process();

	/* 预热指示----冷启动指示 目前PCB没有该指示灯 */
	/* 电池充电指示 目前PCB没有该指示灯 */

	/* 巡航控制指示灯 LCD中显示 */
	
	/* 尿素液位低报警灯  */
#if 1
	if((RX_NiaoSu <= 25)||(CanFrame_Rx[ID18FE5600].TOnLineFlg == 0))	/* 小于等于10%报警,或者信号失效报警 */
	{
		//LED_13 = 1;
		LED_13 = 0;
	}
	else if(RX_NiaoSu >= 30)	/* 大于等于12%解除报警 */
	{
		LED_13 = 0;
	}
#endif

	

	/* 驾驶员报警系统指示灯 LCD中显示 */
	/* 驾驶性能限制系统指示灯 LCD中显示 */
	/* 自动大灯 LCD中显示 */
	/* 尿素液位 LCD中显示 */

}


void LED_Process(void)
{
	LED_Signal_Process();
	
	C596A_Driver(C596.C596A.Byte);
	C596B_Driver(C596.C596B.Byte);
	C596C_Driver(C596.C596C.Byte);
}

									/* 0.5V 1.86v 2.05V 3.22v 3.88V */
const unsigned int  RA_PRE_dial[10]={ 0, 93, 349, 385, 603, 727, 740};
const unsigned int 	RA_PRE_angle[10]={ 0,  0, 500, 100, 400, 200,  3};

unsigned int RA_Press,FA_Press;

/* 后桥气压表处理 */
void RA_PRE_Process(unsigned int ADC_Press)
{
	unsigned int temp,com;
	
	temp = ADC_Press;
	if(temp<RA_PRE_dial[1])
		temp=RA_PRE_dial[1];
	com=0;
	for(temp_a=1;temp_a<10;temp_a++)
	{
		if(temp<=RA_PRE_dial[temp_a])
		{
		 	temp=temp-RA_PRE_dial[temp_a-1];
		 	temp_b=temp;
		 	temp_b=temp_b*RA_PRE_angle[temp_a];
			temp_b= temp_b/(RA_PRE_dial[temp_a]-RA_PRE_dial[temp_a-1]);

			//sms_inp=(unsigned int)(temp_b+com);
			Smeter[Mc_Press2].inp=(unsigned int)(temp_b+com);
			RA_Press = Smeter[Mc_Press2].inp;
			break;
		}
		com=com+RA_PRE_angle[temp_a];
	}
}

/* 前桥气压表处理 */
void FA_PRE_Process(unsigned int ADC_Press)
{
	unsigned int temp,com;
	
	temp = ADC_Press;
	if(temp<RA_PRE_dial[1])
		temp=RA_PRE_dial[1];
	com=0;
	for(temp_a=1;temp_a<10;temp_a++)
	{
		if(temp<=RA_PRE_dial[temp_a])
		{
		 	temp=temp-RA_PRE_dial[temp_a-1];
		 	temp_b=temp;
		 	temp_b=temp_b*RA_PRE_angle[temp_a];
			temp_b= temp_b/(RA_PRE_dial[temp_a]-RA_PRE_dial[temp_a-1]);

			//sms_inp=(unsigned int)(temp_b+com);
			Smeter[Mc_Press1].inp=(unsigned int)(temp_b+com);
			FA_Press = Smeter[Mc_Press1].inp;
			break;
		}
		com=com+RA_PRE_angle[temp_a];
	}
}

void PRE_Warning_Process(void)
{
#if 1
	LED_2 = 0;	// 暂时屏蔽
	if( (FA_Press<=560) || (RA_Press<=560))
	{
		//LED_2 = 1;
		LED_2 = 0;
	}
	else if((FA_Press>600) && (RA_Press>600))
	{
		LED_2 = 0;
	}
#endif
}

/* 电源电压处理，计算出来后LCD进行显示 */
void BAT_V_Process(void)
{
	
}

#define V_Power_On	1
#define V_Power_Off	0

u8 V_12V_Status,V_5V_Status;


/* 控制逻辑设计，初始化时打开12V和5V的输出
	程序正常运行时对12V和5V的电压进行判断，如果异常那么本次点火周期不再打开电压输出，
	下次点火再次打开，再进行判断*/

/* 上部电压正常情况下为12V,分压电阻为10K 和4.7k 取4.7k上面的电压
	目前暂定为小于1V时关闭12V的输出 */
void V_Power_12V_Turn_On_Off(u8 Switch)
{
	if(Switch == V_Power_On)
	{
		V_12V_Status = 1;
	}
	else
	{
		V_12V_Status = 0;
	}
	
	V_POW1_PT1 = Switch;
}


/* 上部电压正常情况下为5V,分压电阻为10K 和4.7k 取4.7k上面的电压
	目前暂定为小于1V时关闭5V的输出 */
void V_Power_5V_Turn_On_Off(u8 Switch)
{
	if(Switch == V_Power_On)
	{
		V_5V_Status = 1;
	}
	else
	{
		V_5V_Status = 0;
	}
	V_POW2_PT2 = Switch;
}

/* 上部电压正常情况下为12V,分压电阻为10K 和4.7k 取4.7k上面的电压
	目前暂定为小于1V时关闭12V的输出 
	1、正常12V时ADC采样值为786
	2、1V时ADC采样值为65.4
	*/
void V_Power_12V_Control(u16 ADC_12V)
{
	static u8 V_12V_ADC_Count = 0;
	if((ADC_12V <= 66)&&(V_12V_Status == 1))
	{
		V_12V_ADC_Count++;
		if(V_12V_ADC_Count > 5)
		{
			 V_Power_12V_Turn_On_Off(V_Power_Off); 
		}
	}
	else
	{
		V_12V_ADC_Count = 0;
	}

}


/* 上部电压正常情况下为5V,分压电阻为10K 和4.7k 取4.7k上面的电压
	目前暂定为小于1V时关闭5V的输出 
	1、正常5V时采样值为327
	2、1V时ADC采样值为65.4*/

void V_Power_5V_Control(u16 ADC_5V)
{
	static u8 V_5V_ADC_Count = 0;
	if((ADC_5V <= 66)&&(V_5V_Status == 1))
	{
		V_5V_ADC_Count++;
		if(V_5V_ADC_Count > 5)
		{
			 V_Power_5V_Turn_On_Off(V_Power_Off); 
		}
	}
	else
	{
		V_5V_ADC_Count = 0;
	}
}



void ADC_Process(void )
{
	static unsigned char ad_sum = 0;
	static unsigned char ad_td = 0;		/* AD采样通道索引号 */
	unsigned char i;
	unsigned int temp;

	if(ATDSTAT0_SCF)
	{
		temp=ATDDR0;
		switch(ad_td)
		{
		case 0:
			carf[OIL2_NUM].ad_result=carf[OIL2_NUM].ad_result+ temp;
			ad_td=1;
			ATDCTL5=1;
			break;

		case 1:
			carf[OIL1_NUM].ad_result=carf[OIL1_NUM].ad_result+ temp;
			ad_td=2;
			ATDCTL5=2;
			break;

		case 2:
		 	carf[RA_PRE_NUM].ad_result=carf[RA_PRE_NUM].ad_result+ temp;
			ad_td=3;
			ATDCTL5=3;
			break;

		case 3:
			carf[FA_PRE_NUM].ad_result=carf[FA_PRE_NUM].ad_result+ temp;
			ad_td=4;
			ATDCTL5=4;
			break;

		case 4:
			carf[BAT_NUM].ad_result=carf[BAT_NUM].ad_result+ temp;
			ad_td = 5;
			ATDCTL5 = 5;
			break;
	#if 1
		case 5:
			carf[OUT12V0_NUM].ad_result=carf[OUT12V0_NUM].ad_result+ temp;
			ad_td=6;
			ATDCTL5=6;
			break;

		case 6:
			carf[OUT5V0_NUM].ad_result=carf[OUT5V0_NUM].ad_result+ temp;
			ad_td=7;
			ATDCTL5=7;
			break;

		case 7:
			carf[BP_VOLT].ad_result=carf[BP_VOLT].ad_result+ temp;
			ad_td=0;
			ATDCTL5=0;
	#endif

			ad_sum++;
			if( ad_sum>31 )
			{
				carf[OIL2_NUM].ad_dial=(carf[OIL2_NUM].ad_result>>5);// 外电压
				carf[OIL1_NUM].ad_dial=(carf[OIL1_NUM].ad_result>>5);// 5v
				carf[RA_PRE_NUM].ad_dial=(carf[RA_PRE_NUM].ad_result>>5);// 燃油
				carf[FA_PRE_NUM].ad_dial=(carf[FA_PRE_NUM].ad_result>>5);
				carf[BAT_NUM].ad_dial=(carf[BAT_NUM].ad_result>>5);
				carf[OUT12V0_NUM].ad_dial=(carf[OUT12V0_NUM].ad_result>>5);
				carf[OUT5V0_NUM].ad_dial=(carf[OUT5V0_NUM].ad_result>>5);
				carf[BP_VOLT].ad_dial=(carf[BP_VOLT].ad_result>>5);			/* 制动气压 */

				for(i = 0; i < AD_MAX; i++)	/* 清空所有采样结果 */
					carf[i].ad_result=0;
				
				ad_sum=0;

				FA_PRE_Process(carf[FA_PRE_NUM].ad_dial);
				RA_PRE_Process(carf[RA_PRE_NUM].ad_dial);
				V_Power_12V_Control(carf[OUT12V0_NUM].ad_dial);
				V_Power_5V_Control(carf[OUT5V0_NUM].ad_dial);

				/* 水温和燃油需要自检结束后才能计算，并显示 */
				if(pro_start > 0)
				{
					Calculate_Fuel(carf[OIL2_NUM].ad_dial);
					Calculate_Temperature(RX_Temperature);
				}
			}
			break;
		default:
		    break;
		}
	}

	//Control_DTC_12Vol(carf[AD_12V].ad_dial);
	//Calculate_Fuel(carf[AD_RY].ad_dial, carf[AD_5V].ad_dial);

	//Calculate_Temperature(RX_TachoSpeed);

	// 水温
	//Calculate_Temperature();
	/* 行车过程中，燃油的控制 */
	//Control_Fuel();
}

void CAN_ComCycTime_Init(void)
{
	CanFrame_Rx[ID0CF00400].ComCycTime = 10;
	CanFrame_Rx[ID18FEEE00].ComCycTime = 1000;
	CanFrame_Rx[ID18FE5600].ComCycTime = 1000;
	CanFrame_Rx[ID18FEEF00].ComCycTime = 500;
	CanFrame_Rx[ID18FEE900].ComCycTime = 500;		//事件型报文
	CanFrame_Rx[ID18FEE500].ComCycTime = 500;		//事件型报文
	CanFrame_Rx[ID18FECA00].ComCycTime = 1000;
	CanFrame_Rx[ID18ECFF00].ComCycTime = 1000;		//没找到该报文
	CanFrame_Rx[ID18EBFF00].ComCycTime = 500;		//没找到该报文
	CanFrame_Rx[ID18FECA3D].ComCycTime = 500;		//没找到该报文
	CanFrame_Rx[ID18ECFF3D].ComCycTime = 500;		//没找到该报文
	CanFrame_Rx[ID18EBFF3D].ComCycTime = 500;		//没找到该报文
	CanFrame_Rx[ID18FECA0B].ComCycTime = 1000;
	CanFrame_Rx[ID18ECFF0B].ComCycTime = 1000;		//没找到该报文
	CanFrame_Rx[ID18EBFF0B].ComCycTime = 1000;		//没找到该报文
	CanFrame_Rx[ID0CF00300].ComCycTime = 1000;		//没找到该报文
	CanFrame_Rx[ID18FED921].ComCycTime = 50;
	CanFrame_Rx[ID18FF0C21].ComCycTime = 200;
	CanFrame_Rx[ID18FF0B21].ComCycTime = 100;
	CanFrame_Rx[ID18F0000F].ComCycTime = 100;		//没找到该报文
	CanFrame_Rx[ID18F0010B].ComCycTime = 100;
	CanFrame_Rx[ID18FEFF00].ComCycTime = 10000;
	CanFrame_Rx[ID18FEF100].ComCycTime = 100;
	CanFrame_Rx[ID18FEE400].ComCycTime = 1000;
	CanFrame_Rx[ID18FD7C00].ComCycTime = 1000;		//没找到该报文
	CanFrame_Rx[ID18FF1110].ComCycTime = 1000;		//没找到该报文
	CanFrame_Rx[ID18FEF300].ComCycTime = 1000;		//没找到该报文
	CanFrame_Rx[ID18FEF437].ComCycTime = 1000;		//没找到该报文
	CanFrame_Rx[ID18FE24EE].ComCycTime = 1000;		//没找到该报文
	CanFrame_Rx[ID18FF2121].ComCycTime = 500;
	CanFrame_Rx[ID18FF2221].ComCycTime = 500;
	CanFrame_Rx[ID18FD0700].ComCycTime = 100;
	CanFrame_Rx[ID18FEF433].ComCycTime = 200;
	CanFrame_Rx[ID18FED917].ComCycTime = 100;
	
}

//void CAN_Loss_Process(u8 CAN_ID)
void CAN_Loss_Process(void)
{
	u16 Second_Can_TimeCount;
	
	Second_Can_TimeCount=CanFrame_Rx[ID0CF00400].NoComTimeCnt;
	if( (second_1s-Second_Can_TimeCount)> 500 )		/* 50个报文周期算做报文丢失 */
	{
		Second_Can_TimeCount=CanFrame_Rx[ID0CF00400].NoComTimeCnt;
		if( (second_1s-Second_Can_TimeCount)>501 )
		{
			CanFrame_Rx[ID0CF00400].TOnLineFlg = 0;
			//if( (IG_IN==1) && (config_transsionfault) &&(pro_start>0) )
			//{
					//canloss_ID1A0=1;
					//dtc_canloss=1;
					//write_losscan_code(diag_losscan_code.pp);

			//}
			CanFrame_Rx[ID0CF00400].data[0].pp=0;
			CanFrame_Rx[ID0CF00400].data[1].pp=0;
			CanFrame_Rx[ID0CF00400].data[2].pp=0;
			CanFrame_Rx[ID0CF00400].data[3].pp=0;		/* 转速低位 */
			CanFrame_Rx[ID0CF00400].data[4].pp=0;		/* 转速高位 */
			CanFrame_Rx[ID0CF00400].data[5].pp=0;
			CanFrame_Rx[ID0CF00400].data[6].pp=0;
			CanFrame_Rx[ID0CF00400].data[7].pp=0;
		}
	}

	Second_Can_TimeCount=CanFrame_Rx[ID18FEEE00].NoComTimeCnt;
	if( (second_1s-Second_Can_TimeCount)>5000 )
	{
		Second_Can_TimeCount=CanFrame_Rx[ID18FEEE00].NoComTimeCnt;
		if( (second_1s-Second_Can_TimeCount)>5001 )
		{
			CanFrame_Rx[ID18FEEE00].TOnLineFlg = 0;
			//if( (IG_IN==1) && (config_transsionfault) &&(pro_start>0) )
			//{
					//canloss_ID1A0=1;
					//dtc_canloss=1;
					//write_losscan_code(diag_losscan_code.pp);

			//}
			CanFrame_Rx[ID18FEEE00].data[0].pp=0;		/* 水温值清零 */
			CanFrame_Rx[ID18FEEE00].data[1].pp=0;
			CanFrame_Rx[ID18FEEE00].data[2].pp=0;
			CanFrame_Rx[ID18FEEE00].data[3].pp=0;
			CanFrame_Rx[ID18FEEE00].data[4].pp=0;
			CanFrame_Rx[ID18FEEE00].data[5].pp=0;
			CanFrame_Rx[ID18FEEE00].data[6].pp=0;
			CanFrame_Rx[ID18FEEE00].data[7].pp=0;
		}
	}


	Second_Can_TimeCount=CanFrame_Rx[ID18FE5600].NoComTimeCnt;
	if( (second_1s-Second_Can_TimeCount)>5000 )
	{
		Second_Can_TimeCount=CanFrame_Rx[ID18FE5600].NoComTimeCnt;
		if( (second_1s-Second_Can_TimeCount)>5001 )
		{
			CanFrame_Rx[ID18FE5600].TOnLineFlg = 0;
			//if( (IG_IN==1) && (config_transsionfault) &&(pro_start>0) )
			//{
					//canloss_ID1A0=1;
					//dtc_canloss=1;
					//write_losscan_code(diag_losscan_code.pp);
			//}
			CanFrame_Rx[ID18FE5600].data[0].pp=0;		/* 尿素值 */
			CanFrame_Rx[ID18FE5600].data[1].pp=0;
			CanFrame_Rx[ID18FE5600].data[2].pp=0;
			CanFrame_Rx[ID18FE5600].data[3].pp=0;
			CanFrame_Rx[ID18FE5600].data[4].pp=0;
			CanFrame_Rx[ID18FE5600].data[5].pp=0;
			CanFrame_Rx[ID18FE5600].data[6].pp=0;
			CanFrame_Rx[ID18FE5600].data[7].pp=0;
		}
	}


	Second_Can_TimeCount=CanFrame_Rx[ID18FEEF00].NoComTimeCnt;
	if( (second_1s-Second_Can_TimeCount)>10000 )		/* 500ms/cyc  20个周期 */
	{
		Second_Can_TimeCount=CanFrame_Rx[ID18FEEF00].NoComTimeCnt;
		if( (second_1s-Second_Can_TimeCount)>10001 )
		{
			CanFrame_Rx[ID18FEEF00].TOnLineFlg = 0;
			//if( (IG_IN==1) && (config_transsionfault) &&(pro_start>0) )
			//{
					//canloss_ID1A0=1;
					//dtc_canloss=1;
					//write_losscan_code(diag_losscan_code.pp);

			//}
			CanFrame_Rx[ID18FEEF00].data[0].pp=0;
			CanFrame_Rx[ID18FEEF00].data[1].pp=0;
			CanFrame_Rx[ID18FEEF00].data[2].pp=0;
			CanFrame_Rx[ID18FEEF00].data[3].pp=0;		/* 机油压力 */
			CanFrame_Rx[ID18FEEF00].data[4].pp=0;
			CanFrame_Rx[ID18FEEF00].data[5].pp=0;
			CanFrame_Rx[ID18FEEF00].data[6].pp=0;
			CanFrame_Rx[ID18FEEF00].data[7].pp=0;
		}
	}

	Second_Can_TimeCount=CanFrame_Rx[ID18FECA00].NoComTimeCnt;
	if( (second_1s-Second_Can_TimeCount)>(CanFrame_Rx[ID18FECA00].ComCycTime*10) )
	{
		Second_Can_TimeCount=CanFrame_Rx[ID18FECA00].NoComTimeCnt;
		if( (second_1s-Second_Can_TimeCount)>((CanFrame_Rx[ID18FECA00].ComCycTime*10) + 1) )
		{
			CanFrame_Rx[ID18FECA00].TOnLineFlg = 0;
			//if( (IG_IN==1) && (config_transsionfault) &&(pro_start>0) )
			//{
					//canloss_ID1A0=1;
					//dtc_canloss=1;
					//write_losscan_code(diag_losscan_code.pp);

			//}
			CanFrame_Rx[ID18FECA00].data[0].pp=0;
			CanFrame_Rx[ID18FECA00].data[1].pp=0;
			CanFrame_Rx[ID18FECA00].data[2].pp=0;
			CanFrame_Rx[ID18FECA00].data[3].pp=0;
			CanFrame_Rx[ID18FECA00].data[4].pp=0;
			CanFrame_Rx[ID18FECA00].data[5].pp=0;
			CanFrame_Rx[ID18FECA00].data[6].pp=0;
			CanFrame_Rx[ID18FECA00].data[7].pp=0;
		}
	}


	Second_Can_TimeCount=CanFrame_Rx[ID18FECA0B].NoComTimeCnt;
	if( (second_1s-Second_Can_TimeCount)>(CanFrame_Rx[ID18FECA0B].ComCycTime*10) )
	{
		Second_Can_TimeCount=CanFrame_Rx[ID18FECA0B].NoComTimeCnt;
		if( (second_1s-Second_Can_TimeCount)>((CanFrame_Rx[ID18FECA0B].ComCycTime*10) + 1) )
		{
			CanFrame_Rx[ID18FECA0B].TOnLineFlg = 1;
			//if( (IG_IN==1) && (config_transsionfault) &&(pro_start>0) )
			//{
					//canloss_ID1A0=1;
					//dtc_canloss=1;
					//write_losscan_code(diag_losscan_code.pp);

			//}
			CanFrame_Rx[ID18FECA0B].data[0].pp=0;
			CanFrame_Rx[ID18FECA0B].data[1].pp=0;
			CanFrame_Rx[ID18FECA0B].data[2].pp=0;
			CanFrame_Rx[ID18FECA0B].data[3].pp=0;
			CanFrame_Rx[ID18FECA0B].data[4].pp=0;
			CanFrame_Rx[ID18FECA0B].data[5].pp=0;
			CanFrame_Rx[ID18FECA0B].data[6].pp=0;
			CanFrame_Rx[ID18FECA0B].data[7].pp=0;
		}
	}


	Second_Can_TimeCount=CanFrame_Rx[ID18FED921].NoComTimeCnt;
	if( (second_1s-Second_Can_TimeCount)>(CanFrame_Rx[ID18FED921].ComCycTime*10) )
	{
		Second_Can_TimeCount=CanFrame_Rx[ID18FED921].NoComTimeCnt;
		if( (second_1s-Second_Can_TimeCount)>((CanFrame_Rx[ID18FED921].ComCycTime*10) + 1) )
		{
			CanFrame_Rx[ID18FED921].TOnLineFlg = 1;
			//if( (IG_IN==1) && (config_transsionfault) &&(pro_start>0) )
			//{
					//canloss_ID1A0=1;
					//dtc_canloss=1;
					//write_losscan_code(diag_losscan_code.pp);

			//}
			CanFrame_Rx[ID18FED921].data[0].pp=0;
			CanFrame_Rx[ID18FED921].data[1].pp=0;
			CanFrame_Rx[ID18FED921].data[2].pp=0;
			CanFrame_Rx[ID18FED921].data[3].pp=0;
			CanFrame_Rx[ID18FED921].data[4].pp=0;
			CanFrame_Rx[ID18FED921].data[5].pp=0;
			CanFrame_Rx[ID18FED921].data[6].pp=0;
			CanFrame_Rx[ID18FED921].data[7].pp=0;
		}
	}


	Second_Can_TimeCount=CanFrame_Rx[ID18FF0C21].NoComTimeCnt;
	if( (second_1s-Second_Can_TimeCount)>(CanFrame_Rx[ID18FF0C21].ComCycTime*10) )
	{
		Second_Can_TimeCount=CanFrame_Rx[ID18FF0C21].NoComTimeCnt;
		if( (second_1s-Second_Can_TimeCount)>((CanFrame_Rx[ID18FF0C21].ComCycTime*10) + 1) )
		{
			CanFrame_Rx[ID18FF0C21].TOnLineFlg = 0;
			//if( (IG_IN==1) && (config_transsionfault) &&(pro_start>0) )
			//{
					//canloss_ID1A0=1;
					//dtc_canloss=1;
					//write_losscan_code(diag_losscan_code.pp);

			//}
			CanFrame_Rx[ID18FF0C21].data[0].pp=0;
			CanFrame_Rx[ID18FF0C21].data[1].pp=0;
			CanFrame_Rx[ID18FF0C21].data[2].pp=0;
			CanFrame_Rx[ID18FF0C21].data[3].pp=0;
			CanFrame_Rx[ID18FF0C21].data[4].pp=0;
			CanFrame_Rx[ID18FF0C21].data[5].pp=0;
			CanFrame_Rx[ID18FF0C21].data[6].pp=0;
			CanFrame_Rx[ID18FF0C21].data[7].pp=0;
		}
	}

	Second_Can_TimeCount=CanFrame_Rx[ID18FF0B21].NoComTimeCnt;
	if( (second_1s-Second_Can_TimeCount)>(CanFrame_Rx[ID18FF0B21].ComCycTime*10) )
	{
		Second_Can_TimeCount=CanFrame_Rx[ID18FF0B21].NoComTimeCnt;
		if( (second_1s-Second_Can_TimeCount)>((CanFrame_Rx[ID18FF0B21].ComCycTime*10) + 1) )
		{
			CanFrame_Rx[ID18FF0B21].TOnLineFlg = 1;
			//if( (IG_IN==1) && (config_transsionfault) &&(pro_start>0) )
			//{
					//canloss_ID1A0=1;
					//dtc_canloss=1;
					//write_losscan_code(diag_losscan_code.pp);

			//}
			CanFrame_Rx[ID18FF0B21].data[0].pp=0;
			CanFrame_Rx[ID18FF0B21].data[1].pp=0;
			CanFrame_Rx[ID18FF0B21].data[2].pp=0;
			CanFrame_Rx[ID18FF0B21].data[3].pp=0;
			CanFrame_Rx[ID18FF0B21].data[4].pp=0;
			CanFrame_Rx[ID18FF0B21].data[5].pp=0;
			CanFrame_Rx[ID18FF0B21].data[6].pp=0;
			CanFrame_Rx[ID18FF0B21].data[7].pp=0;
		}
	}


	Second_Can_TimeCount=CanFrame_Rx[ID18F0010B].NoComTimeCnt;
	if( (second_1s-Second_Can_TimeCount)>(CanFrame_Rx[ID18F0010B].ComCycTime*10) )
	{
		Second_Can_TimeCount=CanFrame_Rx[ID18F0010B].NoComTimeCnt;
		if( (second_1s-Second_Can_TimeCount)>((CanFrame_Rx[ID18F0010B].ComCycTime*10) + 1) )
		{
			CanFrame_Rx[ID18F0010B].TOnLineFlg = 1;
			//if( (IG_IN==1) && (config_transsionfault) &&(pro_start>0) )
			//{
					//canloss_ID1A0=1;
					//dtc_canloss=1;
					//write_losscan_code(diag_losscan_code.pp);

			//}
			CanFrame_Rx[ID18F0010B].data[0].pp=0;
			CanFrame_Rx[ID18F0010B].data[1].pp=0;
			CanFrame_Rx[ID18F0010B].data[2].pp=0;
			CanFrame_Rx[ID18F0010B].data[3].pp=0;
			CanFrame_Rx[ID18F0010B].data[4].pp=0;
			CanFrame_Rx[ID18F0010B].data[5].pp=0;
			CanFrame_Rx[ID18F0010B].data[6].pp=0;
			CanFrame_Rx[ID18F0010B].data[7].pp=0;
		}
	}


	Second_Can_TimeCount=CanFrame_Rx[ID18FEFF00].NoComTimeCnt;
	if( (second_1s-Second_Can_TimeCount)>(CanFrame_Rx[ID18FEFF00].ComCycTime*10) )
	{
		Second_Can_TimeCount=CanFrame_Rx[ID18FEFF00].NoComTimeCnt;
		if( (second_1s-Second_Can_TimeCount)>((CanFrame_Rx[ID18FEFF00].ComCycTime*10) + 1) )
		{
			CanFrame_Rx[ID18FEFF00].TOnLineFlg = 1;
			//if( (IG_IN==1) && (config_transsionfault) &&(pro_start>0) )
			//{
					//canloss_ID1A0=1;
					//dtc_canloss=1;
					//write_losscan_code(diag_losscan_code.pp);

			//}
			CanFrame_Rx[ID18FEFF00].data[0].pp=0;
			CanFrame_Rx[ID18FEFF00].data[1].pp=0;
			CanFrame_Rx[ID18FEFF00].data[2].pp=0;
			CanFrame_Rx[ID18FEFF00].data[3].pp=0;
			CanFrame_Rx[ID18FEFF00].data[4].pp=0;
			CanFrame_Rx[ID18FEFF00].data[5].pp=0;
			CanFrame_Rx[ID18FEFF00].data[6].pp=0;
			CanFrame_Rx[ID18FEFF00].data[7].pp=0;
		}
	}


	Second_Can_TimeCount=CanFrame_Rx[ID18FEF100].NoComTimeCnt;
	if( (second_1s-Second_Can_TimeCount)>(CanFrame_Rx[ID18FEF100].ComCycTime*10) )
	{
		Second_Can_TimeCount=CanFrame_Rx[ID18FEF100].NoComTimeCnt;
		if( (second_1s-Second_Can_TimeCount)>((CanFrame_Rx[ID18FEF100].ComCycTime*10) + 1) )
		{
			CanFrame_Rx[ID18FEF100].TOnLineFlg = 1;
			//if( (IG_IN==1) && (config_transsionfault) &&(pro_start>0) )
			//{
					//canloss_ID1A0=1;
					//dtc_canloss=1;
					//write_losscan_code(diag_losscan_code.pp);

			//}
			CanFrame_Rx[ID18FEF100].data[0].pp=0;
			CanFrame_Rx[ID18FEF100].data[1].pp=0;
			CanFrame_Rx[ID18FEF100].data[2].pp=0;
			CanFrame_Rx[ID18FEF100].data[3].pp=0;
			CanFrame_Rx[ID18FEF100].data[4].pp=0;
			CanFrame_Rx[ID18FEF100].data[5].pp=0;
			CanFrame_Rx[ID18FEF100].data[6].pp=0;
			CanFrame_Rx[ID18FEF100].data[7].pp=0;
		}
	}


	Second_Can_TimeCount=CanFrame_Rx[ID18FEE400].NoComTimeCnt;
	if( (second_1s-Second_Can_TimeCount)>(CanFrame_Rx[ID18FEE400].ComCycTime*10) )
	{
		Second_Can_TimeCount=CanFrame_Rx[ID18FEE400].NoComTimeCnt;
		if( (second_1s-Second_Can_TimeCount)>((CanFrame_Rx[ID18FEE400].ComCycTime*10) + 1) )
		{
			CanFrame_Rx[ID18FEE400].TOnLineFlg = 1;
			//if( (IG_IN==1) && (config_transsionfault) &&(pro_start>0) )
			//{
					//canloss_ID1A0=1;
					//dtc_canloss=1;
					//write_losscan_code(diag_losscan_code.pp);

			//}
			CanFrame_Rx[ID18FEE400].data[0].pp=0;
			CanFrame_Rx[ID18FEE400].data[1].pp=0;
			CanFrame_Rx[ID18FEE400].data[2].pp=0;
			CanFrame_Rx[ID18FEE400].data[3].pp=0;
			CanFrame_Rx[ID18FEE400].data[4].pp=0;
			CanFrame_Rx[ID18FEE400].data[5].pp=0;
			CanFrame_Rx[ID18FEE400].data[6].pp=0;
			CanFrame_Rx[ID18FEE400].data[7].pp=0;
		}
	}


	Second_Can_TimeCount=CanFrame_Rx[ID18FF2121].NoComTimeCnt;
	if( (second_1s-Second_Can_TimeCount)>(CanFrame_Rx[ID18FF2121].ComCycTime*10) )
	{
		Second_Can_TimeCount=CanFrame_Rx[ID18FF2121].NoComTimeCnt;
		if( (second_1s-Second_Can_TimeCount)>((CanFrame_Rx[ID18FF2121].ComCycTime*10) + 1) )
		{
			CanFrame_Rx[ID18FF2121].TOnLineFlg = 1;
			//if( (IG_IN==1) && (config_transsionfault) &&(pro_start>0) )
			//{
					//canloss_ID1A0=1;
					//dtc_canloss=1;
					//write_losscan_code(diag_losscan_code.pp);

			//}
			CanFrame_Rx[ID18FF2121].data[0].pp=0;
			CanFrame_Rx[ID18FF2121].data[1].pp=0;
			CanFrame_Rx[ID18FF2121].data[2].pp=0;
			CanFrame_Rx[ID18FF2121].data[3].pp=0;
			CanFrame_Rx[ID18FF2121].data[4].pp=0;
			CanFrame_Rx[ID18FF2121].data[5].pp=0;
			CanFrame_Rx[ID18FF2121].data[6].pp=0;
			CanFrame_Rx[ID18FF2121].data[7].pp=0;
		}
	}

	Second_Can_TimeCount=CanFrame_Rx[ID18FF2221].NoComTimeCnt;
	if( (second_1s-Second_Can_TimeCount)>(CanFrame_Rx[ID18FF2221].ComCycTime*10) )
	{
		Second_Can_TimeCount=CanFrame_Rx[ID18FF2221].NoComTimeCnt;
		if( (second_1s-Second_Can_TimeCount)>((CanFrame_Rx[ID18FF2221].ComCycTime*10) + 1) )
		{
			CanFrame_Rx[ID18FF2221].TOnLineFlg = 1;
			//if( (IG_IN==1) && (config_transsionfault) &&(pro_start>0) )
			//{
					//canloss_ID1A0=1;
					//dtc_canloss=1;
					//write_losscan_code(diag_losscan_code.pp);

			//}
			CanFrame_Rx[ID18FF2221].data[0].pp=0;
			CanFrame_Rx[ID18FF2221].data[1].pp=0;
			CanFrame_Rx[ID18FF2221].data[2].pp=0;
			CanFrame_Rx[ID18FF2221].data[3].pp=0;
			CanFrame_Rx[ID18FF2221].data[4].pp=0;
			CanFrame_Rx[ID18FF2221].data[5].pp=0;
			CanFrame_Rx[ID18FF2221].data[6].pp=0;
			CanFrame_Rx[ID18FF2221].data[7].pp=0;
		}
	}


	Second_Can_TimeCount=CanFrame_Rx[ID18FD0700].NoComTimeCnt;
	if( (second_1s-Second_Can_TimeCount)>(CanFrame_Rx[ID18FD0700].ComCycTime*10) )
	{
		Second_Can_TimeCount=CanFrame_Rx[ID18FD0700].NoComTimeCnt;
		if( (second_1s-Second_Can_TimeCount)>((CanFrame_Rx[ID18FD0700].ComCycTime*10) + 1) )
		{
			CanFrame_Rx[ID18FD0700].TOnLineFlg = 1;
			//if( (IG_IN==1) && (config_transsionfault) &&(pro_start>0) )
			//{
					//canloss_ID1A0=1;
					//dtc_canloss=1;
					//write_losscan_code(diag_losscan_code.pp);

			//}
			CanFrame_Rx[ID18FD0700].data[0].pp=0;
			CanFrame_Rx[ID18FD0700].data[1].pp=0;
			CanFrame_Rx[ID18FD0700].data[2].pp=0;
			CanFrame_Rx[ID18FD0700].data[3].pp=0;
			CanFrame_Rx[ID18FD0700].data[4].pp=0;
			CanFrame_Rx[ID18FD0700].data[5].pp=0;
			CanFrame_Rx[ID18FD0700].data[6].pp=0;
			CanFrame_Rx[ID18FD0700].data[7].pp=0;
		}
	}


	Second_Can_TimeCount=CanFrame_Rx[ID18FEF433].NoComTimeCnt;
	if( (second_1s-Second_Can_TimeCount)>(CanFrame_Rx[ID18FEF433].ComCycTime*10) )
	{
		Second_Can_TimeCount=CanFrame_Rx[ID18FEF433].NoComTimeCnt;
		if( (second_1s-Second_Can_TimeCount)>((CanFrame_Rx[ID18FEF433].ComCycTime*10) + 1) )
		{
			CanFrame_Rx[ID18FEF433].TOnLineFlg = 1;
			//if( (IG_IN==1) && (config_transsionfault) &&(pro_start>0) )
			//{
					//canloss_ID1A0=1;
					//dtc_canloss=1;
					//write_losscan_code(diag_losscan_code.pp);

			//}
			CanFrame_Rx[ID18FEF433].data[0].pp=0;
			CanFrame_Rx[ID18FEF433].data[1].pp=0;
			CanFrame_Rx[ID18FEF433].data[2].pp=0;
			CanFrame_Rx[ID18FEF433].data[3].pp=0;
			CanFrame_Rx[ID18FEF433].data[4].pp=0;
			CanFrame_Rx[ID18FEF433].data[5].pp=0;
			CanFrame_Rx[ID18FEF433].data[6].pp=0;
			CanFrame_Rx[ID18FEF433].data[7].pp=0;
		}
	}


	Second_Can_TimeCount=CanFrame_Rx[ID18FED917].NoComTimeCnt;
	if( (second_1s-Second_Can_TimeCount)>(CanFrame_Rx[ID18FED917].ComCycTime*10) )
	{
		Second_Can_TimeCount=CanFrame_Rx[ID18FED917].NoComTimeCnt;
		if( (second_1s-Second_Can_TimeCount)>((CanFrame_Rx[ID18FED917].ComCycTime*10) + 1) )
		{
			CanFrame_Rx[ID18FED917].TOnLineFlg = 1;
			//if( (IG_IN==1) && (config_transsionfault) &&(pro_start>0) )
			//{
					//canloss_ID1A0=1;
					//dtc_canloss=1;
					//write_losscan_code(diag_losscan_code.pp);

			//}
			CanFrame_Rx[ID18FED917].data[0].pp=0;
			CanFrame_Rx[ID18FED917].data[1].pp=0;
			CanFrame_Rx[ID18FED917].data[2].pp=0;
			CanFrame_Rx[ID18FED917].data[3].pp=0;
			CanFrame_Rx[ID18FED917].data[4].pp=0;
			CanFrame_Rx[ID18FED917].data[5].pp=0;
			CanFrame_Rx[ID18FED917].data[6].pp=0;
			CanFrame_Rx[ID18FED917].data[7].pp=0;
		}
	}
}

void CanLoss_Process(void)
{
#if 0
	u8 i;
	for(i = 0; i < IDMAX; i++)
	{
		CAN_Loss_Process(i);
	}
#endif
	CAN_Loss_Process();
}


void Buzzer_Manage(void)
{
	static u8 Buzzer_test;
	MCU_BEEP_POWER_PR1 = 1;
	BUZZER_PWMPER = 100;
	BUZZER_PWMDTY = 50;
	if((second_1s - second_Buzzer)>500)
	{
		second_Buzzer = second_1s;

		if(Buzzer_test == 1)
		{
			Buzzer_test = 0;
			BUZZER_Enable
		}
		else
		{
			Buzzer_test = 1;
			BUZZER_Disable
		}
	}
	else
	{
		
	}
	
}





void SSD_SGF18_NEAR INT_Init(void)
{
    UINT16 index;          /* Index for vector table */
    UINT16 *SSD_SGF18_NEAR vectorTable;   /* Vector table */

    /* Initialize the expection vector table */
    vectorTable = (UINT16 * SSD_SGF18_NEAR)0x3000;

    for(index=0;index < 128;index++)
    {
        vectorTable[index] = (UINT16)ExceptionAll;
    }

    /* Set the interrupt vector with flash interrupt service function */
    vectorTable[0x5C] = (UINT16)FSL_ISR_Handler;

    /* Set the vector table base address to IVBR */
    REG_WRITE((SSD_MCU_REGISTER_BASE + S12X_INT_REGISTER_OFFSET + \
               INT_IVBR_OFFSET),0x30);

    /* Clear I bit in CCR */
    asm{
        CLI
    }
}


void ee_prom_write(unsigned char id)
{
   UINT16 tempValue;
    __RESET_WATCHDOG();
    returnCode = FSL_WriteEeprom(id, ee_read_write);

    while (EED_OK != returnCode)
    {
        while(BUSY == EE_Status)
        {
            FSL_Main();
        }

        if( (returnCode==EED_ERROR_COPY) || (returnCode==EED_ERROR_SECTORSTATUS) )
        {
               returnCode = FSL_InitEeprom();
               if (EED_OK != returnCode)
               {
                 ;
               }

               while(BUSY == EE_Status)
               {
                    FSL_Main();
               }
        }
        else
        {
             //出现问题写记录为00
             tempValue=0x00;
             returnCode = FSL_Program( (freeSpaceAddress+EED_DATA_VALUE_SIZE), 2, &tempValue);
             while(BUSY == EE_Status)
             {
                FSL_Main();
              }
             freeSpaceAddress += EED_RECORD_LENGTH;
        }
        returnCode = FSL_WriteEeprom(id, ee_read_write);
    }

    while(BUSY == EE_Status)
    {
        FSL_Main();
    }
}


void ee_prom_read(unsigned char id)
{
    UINT8 i,j;
    returnCode=FSL_ReadEeprom(id, &readAddr);
    if (EED_OK != returnCode)
    {
	    returnCode=FSL_ReadEeprom(id, &readAddr);

        if (EED_OK != returnCode)
       	{
		loop_point:;
		returnCode = FlashInit();
		if ( EED_OK != returnCode )
		{
		goto loop_point;
		}

		returnCode = FSL_InitEeprom();
		if (EED_OK != returnCode)
		{
			goto loop_point;
		}

		while(BUSY == EE_Status)
		{
			FSL_Main();
		}

		returnCode=FSL_ReadEeprom(id, &readAddr);

        if (EED_OK != returnCode) //刷新程序后第一次显示
		{
				//初始化状态  大计  还有参数
                if(id==6)
                {
					ee_read_write[0]=0;//15054;//0x00;
					ee_read_write[1]=0x00;
					ee_read_write[2]=0;//15054;//0x00;
					ee_prom_write(1);

					ee_read_write[0]=0x00;
					ee_read_write[1]=0x00;
					ee_read_write[2]=0x00;
					ee_prom_write(2);

					ee_read_write[0]=0x00;
					ee_read_write[1]=0x00;
					ee_read_write[2]=0x00;
					ee_prom_write(3);


					ee_read_write[0]=0x00;
					ee_read_write[1]=0x00;
					ee_read_write[2]=0x00;
					ee_prom_write(4);


					ee_read_write[0]=0x00;
					ee_read_write[1]=0x00;
					ee_read_write[2]=0x00;
					ee_prom_write(5);

					
                    config_data[0].pp=0;//0x9F; //初始配置项
				    config_data[1].pp=0;
                    config_data[2].pp=0; //默认有AC
				    config_data[3].pp=0;

				    
                    
					ee_read_write[0]=0x01;    //ee_loop
					ee_read_write[1]= config_data[0].pp;
					                            // config 默认3探头，lin雷达
					ee_read_write[2]= config_data[1].pp; //手动档
					ee_prom_write(6);

                    ee_read_write[0]=0x00;  //diag_losscan_code.pp
					ee_read_write[1]=0x00;  //diag_trouble_code.pp
					ee_read_write[2]=0x00;  //保养
					ee_prom_write(7);

                    ee_read_write[0]=0;
					ee_read_write[1]=0;
					ee_read_write[2]=0; //超过保养
					ee_prom_write(8);

                    ee_read_write[0]=0x00;   //(((unsigned int)VIN_config_byte[1])<<8) + VIN_config_byte[0];
					ee_read_write[1]=0x00;   //(((unsigned int)VIN_config_byte[3])<<8) + VIN_config_byte[2];
					ee_read_write[2]=0x00;   //(((unsigned int)VIN_config_byte[5])<<8) + VIN_config_byte[4];
					ee_prom_write(9);

                    ee_read_write[0]=0x00;  //(((unsigned int)VIN_config_byte[7])<<8) + VIN_config_byte[6];
					ee_read_write[1]=0x00;  //(((unsigned int)VIN_config_byte[9])<<8) + VIN_config_byte[8];
					ee_read_write[2]=0x00;  //(((unsigned int)VIN_config_byte[11])<<8) + VIN_config_byte[10];
					ee_prom_write(10);
                    ee_read_write[0]=0x00;  //(((unsigned int)VIN_config_byte[13])<<8) + VIN_config_byte[12];
					ee_read_write[1]=0x00;  //(((unsigned int)VIN_config_byte[16])<<8) + VIN_config_byte[14];
					ee_read_write[2]=0x00;  //  VIN_config_byte[16];
					ee_prom_write(11);

            }
			if(id<6)
			{
					//错误就将当前ramdown中的值取回来
					ee_read_write[2]= (unsigned int)(lc_run_sum&0xffff);
                    ee_read_write[1]= (unsigned int)((lc_run_sum>>16)&0xff);
                    ee_read_write[1]=ee_read_write[1]<<8;

                    ee_read_write[0]= (unsigned int)(lc_run_sum&0xffff);
                    ee_read_write[1] |= (unsigned int)((lc_run_sum>>16)&0xff);
			}
			if(id==7)
			{
					ee_read_write[0]=0;
					ee_read_write[1]=0;
					ee_read_write[2]=0;
					ee_prom_write(7);

			}
            if(id==8)
			{
					ee_read_write[0]=0;
					ee_read_write[1]=0;
					ee_read_write[2]=0;
					ee_prom_write(8);

			}
		}
		else
		{
				for( i = 0;i < EED_DATA_VALUE_SIZE; i+=EED_MIN_PROG_SIZE)
				{
					j=i>>1;
					ee_read_write[j]=READ_DFLASH16(readAddr+i) ;
				}

		}
    }
	else
	{
		for( i = 0;i < EED_DATA_VALUE_SIZE; i+=EED_MIN_PROG_SIZE)
		{
                		j=i>>1;
                		ee_read_write[j]=READ_DFLASH16(readAddr+i) ;
		}

	}
    }
    else
    {
        for( i = 0;i < EED_DATA_VALUE_SIZE; i+=EED_MIN_PROG_SIZE)
        {
                j=i>>1;
                ee_read_write[j]=READ_DFLASH16(readAddr+i) ;
        }
    }
}


void lcdata_change(u8 up_down)
{
	u8 data;
	for(data=1;data<=up_down;data++)   //add 1 bit coml<rr1*********************************************
	{   
		(*l_p)++;
		if(*l_p>9)//循环判断进位，直到遇到无需进位的情况，退出循环
	    {    
	    	*l_p=0;		//该位数归零
	        l_p++;		//地址增加1
	    }
	    else
	    	break;
	}   
}



void scan(void) 
{  
	u16 temp_t2;	
					
	for(;;)
	{   	
		temp_t2=lc_num;
		if(temp_t2==lc_num) 
			break;
	} 
	
	 if((temp_t2-lc_pulsenum)>LC_LITTLE)
	{
		lc_pulsenum=lc_pulsenum+LC_LITTLE ; 
        l_p=ramup_a;
        lcdata_change(4);

		lc_trip_sum++;

        //l_p=ramup_b;
        //lcdata_change(4);

        //display_up();		/* 显示小计里程 */

        if(ramup_a[0]==lc_little_total) 
        {
		    l_p=ramdown;
			lcdata_change(6);
                        
			ee_loop++;
			if(ee_loop>5)
				ee_loop=1;
                        
			ee_read_write[2]= (u16)(lc_run_sum&0xffff);
			ee_read_write[1]= (u16)((lc_run_sum>>16)&0xff);
			ee_read_write[1]=ee_read_write[1]<<8;
                        
			lc_run_sum++;
              
			ee_read_write[0]= (u16)(lc_run_sum&0xffff);
			ee_read_write[1] |= (u16)((lc_run_sum>>16)&0xff);
                            
			ee_prom_write(ee_loop); 
                        
			ee_prom_read(6); 
			ee_read_write[0]=ee_loop;
			ee_prom_write(6); 
				
			
			//display_down();  		
		} 
	}
}


void Can_Tx_Process(void)
{
	byte txbuffer;
	if( (second_1s - second_CANTx_100ms)>100 )
	{
		second_CANTx_100ms=second_1s;
		if(CANTFLG>0)           // Wait for empty Tx Buffer 
		{  
			__RESET_WATCHDOG();	
			CANTBSEL = CANTFLG;	    
			txbuffer = CANTBSEL; 
			
			CANTXIDR0 = 0x67;  //0x0C FE 6C EE 
			CANTXIDR1 = 0xFC;
			CANTXIDR2 = 0xD9;
			CANTXIDR3 = 0xDC;
				
			CANTXDSR0 = 0;	
			CANTXDSR1 = 0;
			CANTXDSR2 = 0;
			CANTXDSR3 = 0;				
			CANTXDSR4 = 0;	
			CANTXDSR5 = 0;
			CANTXDSR6 = 0;	
			CANTXDSR7 = (u8)((Smeter[Mc_Speed].inp*7)/36);//(g_nSm_new[1]/32);
			CANTXDLR = 0x08;		// set data length 
			CANTXTBPR = 0x80;		// set data buffer priority 
			CANTFLG = txbuffer;     // start transmission   
		}
	}

	if( (second_1s - second_CANTx_150ms)>150 )		/* 该ID用来测试 */
	{
		second_CANTx_150ms = second_1s;
		if(CANTFLG>0)           // Wait for empty Tx Buffer 
		{  
			__RESET_WATCHDOG();	
			CANTBSEL = CANTFLG;	    
			txbuffer = CANTBSEL; 

			// 0x0CFE6CFF
			// 0x67FCD9FE
			CANTXIDR0 = 0x67;  
			CANTXIDR1 = 0xFC;
			CANTXIDR2 = 0xD9;
			CANTXIDR3 = 0xFE;

			//NXP74HC165A_DATA
			CANTXDSR0 = 0xAA;	// 代表A路74HC165
			CANTXDSR1 = (u8)(NXP74HC165A_DATA&0x000000FF);			// U24的8位数据
			CANTXDSR2 = (u8)((NXP74HC165A_DATA&0x0000FF00)>>8);		// U23的8位数据
			CANTXDSR3 = (u8)((NXP74HC165A_DATA&0x00FF0000)>>16);	// U22的8位数据			
			CANTXDSR4 = 0xBB;	// 代表B路74HC165
			CANTXDSR5 = (u8)(NXP74HC165B_DATA&0x000000FF);			// U29的8位数据
			CANTXDSR6 = (u8)((NXP74HC165B_DATA&0x0000FF00)>>8);		// U28的8位数据
			CANTXDSR7 = (u8)((NXP74HC165B_DATA&0x00FF0000)>>16);	// U27的8位数据
			CANTXDLR = 0x08;		// set data length 
			CANTXTBPR = 0x80;		// set data buffer priority 
			CANTFLG = txbuffer;     // start transmission   
		}
	}
}


u16	key1_time;
u8	key1_start;

void Key_Process(void)
{
	if(MCU_I_KEY1_PB7==0)
    {
		if(key1_start==0)
       	{
       	 	key1_start=1;
       	 	key1_time=second_1s;	
       	}
       	if( ((second_1s-key1_time)>2000) ) //清小计A
       	{
			key1_time=second_1s;
       	 	key1_start=2;
			
            if(lc_little_total>=ramup_a[0]) 
			{
				lc_little_total=lc_little_total-ramup_a[0]; 
            }
			else  
			{
				lc_little_total=10+lc_little_total;
				lc_little_total=lc_little_total-ramup_a[0] ;
			}
			
            ramup_a[0]=ramup_a[1]=ramup_a[2]=ramup_a[3]=ramup_a[4]=ramup_a[5]=0;
			lc_trip_sum = 0;
			//display_up();
       	}
    }
    else
    {
       	key1_start=0;
    }


	if( ign_jsq>0 )
	{
		if( ign_jsq>5 )
		{
			if(pro_start==0)
			{
				//dtc_check();
				pro_start=1;//自检结束
			}
		#if 0
			if(pro_start_dtc==0)
			{
				//if(dte_ram[0]==11)
				//cal_dte();
                if(dte_sum_inp<50)dte_sum_inp=51;//允许续航里程计算显示
				cal_dte();
				pro_start_dtc=1;
				smr_out(smr_new);
			}
		#endif
		}
	#if 0
		if(pro_start_dtc==0)
		{
			check_startzn();
			pro_start_ry=1;

            if(dte_sum_inp<50)dte_sum_inp=51;//允许续航里程计算显示
            cal_dte();
		    if(dte_sum_new<50)
			dte_sum_new=dte_sum_inp;
		}
	#endif
	}
}





void init_clock(void)
{
	    #if 1

	    __asm(nop);__asm(nop);
		__asm(nop);__asm(nop);
		CPMUCLKS_COPOSCSEL =1;// 	//1 COP clock source is OSCCLK       0 COP clock source is IRCCLK.
		CPMUCLKS_PLLSEL = 1; 	//select the PLL as the clock source
		CPMUCLKS_RTIOSCSEL =1;
		CPMUOSC = 0xc4;			//For example when using a 4MHz crystal and synthesizing a VCOCLK of 64 MHz, then OSCFILT must be set to8
								//(64MHz / 8MHz = 8, 8divided by 2 is 8).
		while(!CPMUFLG_UPOSC);	// wait for OSC to stabilise


		CPMUREFDIV = ((REFCLK_RANGE<<6) | (PLL_DIVIDER-1));       // Reference Clock / 1 = 8MHz
		CPMUSYNR = ((VCO_RANGE<<6) | (PLL_MULTIPLIER-1));        //  configure the PLL  x 16 = 64MHz VCO
		CPMUPOSTDIV = (PLL_POSTDIVIDER-1);      // Post divider / 1 = 32MHz Bus CLK
		while(!CPMUFLG_LOCK)	                    // wait for PLL to lock
		{
		}
		__asm(nop);__asm(nop);__asm(nop);__asm(nop); __asm(nop);__asm(nop);


		CPMURTI = 0xf9;
		CPMUCLKS_PSTP = 1;
		CPMUCLKS_PRE =1;
		CPMUCLKS_RTIOSCSEL =1;	// 	//1 RTI clock source is OSCCLK.
		CPMUINT = 0x80;



		//CPMUINT_OSCIE=1;		    //使能晶振检测
		//CPMUFLG_UPOSC=1;		    //清状态位
		CPMUCLKS_PSTP=1;		//伪stop状态下 晶振运行 Oscillator continues to run in Stop Mode (Pseudo Stop), option to run RTI and COP.
		CPMUCLKS_PCE=0;			//伪stop状态下 晶振运行COP continues running during Pseudo Stop Mode if COPOSCSEL=1
		CPMUCLKS_COPOSCSEL=0;   //看门狗时钟选rc


		//CPMUCOP=0x04; 			//使能看门狗 周期1s

		//CPMUHTCTL_HTE=1;		//temperature sense is enabled.
		//CPMUHTCTL_HTIF=1;		//High Temperature Interrupt Flag This flag can only be cleared by writing a 1.
		//CPMUHTCTL_HTIE=1;		//High Temperature Interrupt Enable Bit Interrupt will be requested whenever HTIF is set.
		//CPMULVCTL_LVIE=1;		//低压检测Interrupt will be requested whenever LVIF is set.
		CPMUPROT=0x01;		//时钟保护Protection of clock configuration registers is enabled.
		//__RESET_WATCHDOG();
		  #endif

}

void Init_Port(void)
{
#if 0
	DDRA = 0xff;
	DDRB = 0x01;

	DDRU = 0xff;
	DDRV = 0xff;//0k
    #if 1
      PIES &= (unsigned char)~(unsigned char)0x60U;                     
      /* Clear interrupt flags */
      /* WOMS: WOMS7=1,WOMS6=0,WOMS5=0,WOMS4=1,WOMS0=1 */
      WOMS = (WOMS & (unsigned char)~(unsigned char)0x60U) | (unsigned char)0x91U;
      /* PERS: PERS7=0,PERS4=0 */
      PERS &= (unsigned char)~(unsigned char)0x90U;                     
      /* DDRS: DDRS7=0,DDRS6=1,DDRS5=1,DDRS4=1,DDRS0=0 */
      //DDRS = (DDRS & (unsigned char)~(unsigned char)0x81U) | (unsigned char)0x70U;
    #endif
    
	DDRS = 0x7a;
    DDRR = 0xe1;

	DDRP = 0x70;

	DDRT = 0x00;
	DDRH = 0xff;

   	PERR = 0x00;
   	PPSR = 0x00;
   	PERP= 0x00;
   	PERH =0x00;
   	PPSH =0x00;
   	PERU = 0x00;   //0x10
   	PUCR_PUPAE=0;
   	PUCR_PUPBE=0;
   	PERT=0;

	DDR1AD = 0xff;
   	PER1AD = 0x00;   	// Enable pullups on Switches
#endif

	PORTU_DIRECTION;	//DDRU = 0x0F;
	PERU = 0x00;		//PERU—Port U Pull Device Enable Register

	PORTV_DIRECTION;	//DDRV = 0xF0;
	PERV = 0x00;		//默认值也是为零

	PORTS_DIRECTION;	//DDRS = 0xFA;
	PERS = 0x00;

	PORTR_DIRECTION;	//DDRR = 0xE1;
	PERR = 0x00;

	PORTT_DIRECTION;	//DDRT = 0xf9;
	PERT = 0x00;

	PORTP_DIRECTION;	//DDRP = 0xff;
	PERP = 0x00;

    PORTH_DIRECTION;	//DDRH = 0xff;
    PERH = 0x00;

	PORTB_DIRECTION;	//DDRB = 0xff;
	PUCR_PUPBE = 0;			//Ports A, B, BKGD pin Pull Control Register (PUCR)

	PORTA_DIRECTION;	//DDRA = 0xe2;
	PUCR_PUPAE = 0;			/* Pull-up Up Control Register */

	DDR1AD = 0x00;			/* 0 Associated pin is configured as input */
	PER1AD = 0x00;			/* 0 Pull device disabled */
}


void Init_Can(void)
{
	CAN_DRV_ON;
    DelayXms(5);  
	CANRIER_RXFIE = 0;  
	__RESET_WATCHDOG();
	if(CANCTL0_INITRQ==0)      	// 查询是否进入初始化状态   
		CANCTL0_INITRQ =1;        // 进入初始化状态

	while (CANCTL1_INITAK==0)
		;  //等待进入初始化状态
		
	//250k
	CANCTL1 = 0x80;	// enable CAN module, Loopback Mode, Ext OSC 
	//CANBTR0_SJW = 1;            //设置同步
	//CANBTR0_BRP = 0;            //设置波特率分频系数，此处BUS时钟为8M，设置为2分频 
	CANBTR0 = 0x41;
	CANBTR1 = 0x3A;       //设置时段1和时段2的Tq个数 ,总线频率为250kb/s ，时间段1位13tq，时间段2为2tq，根据公式8000000/2/(1+2+13)=250K

   // 100k
   //CANCTL1 = 0x80;	// enable CAN module, Loopback Mode, Ext OSC 
   //CANBTR0 = 0x44;	// sync jump - 4 Tq clocks, prescalar = 3 
   //CANBTR1 = 0x3A;	// Tseg = 3, Tseg1 = 10, 1 sample per bit 
   //CANIDAC = 0x10;	// four 16-bit filters 

    //500k
    //CANCTL1 = 0x80;	// enable CAN module, Loopback Mode, Ext OSC
   	//CANBTR0 = 0x40;	// sync jump - 4 Tq clocks, prescalar = 3
   	//CANBTR1 = 0x3A;	// Tseg = 3, Tseg1 = 10, 1 sample per bit
#if 0
  	CANIDAR0 = 0xc7;   
  	CANIDAR1 = 0xFC;
  	CANIDAR2 = 0x8C;
  	CANIDAR3 = 0x00;  
  	CANIDAR4 = 0x67;
  	CANIDAR5 = 0x98;
  	CANIDAR6 = 0x08;
  	CANIDAR7 = 0x00;
	//屏蔽码
  	CANIDMR0 = 0x00;
  	CANIDMR1 = 0x01;
  	CANIDMR2 = 0x70;
  	CANIDMR3 = 0x7A;
  	CANIDMR4 = 0x00;
  	CANIDMR5 = 0x00;
  	CANIDMR6 = 0x00;
  	CANIDMR7 = 0x00;
#else                                 
	CANIDMR0 = 0xFF;
	CANIDMR1 = 0xFF;
	CANIDMR2 = 0xFF;
	CANIDMR3 = 0xFF;
	CANIDMR4 = 0xFF;
	CANIDMR5 = 0xFF;
	CANIDMR6 = 0xFF;
	CANIDMR7 = 0xFF; 
#endif

	//CANCTL1 = 0xC0;             //使能MSCAN模块,设置为一般运行模式、使用总线时钟源 

	CANCTL0 = 0x00;             //返回一般模式运行

	while(CANCTL1_INITAK);      //等待回到一般运行模式

	while(CANCTL0_SYNCH==0);    //等待总线时钟同步
    CANRFLG = 0xc3;			     // reset Rx flags
    
	CANRIER_RXFIE = 1;          //使能接收中断
	
	//memset(CanCmdInputBuf,0,sizeof(CanCmdInputBuf));
}


void init_data_reset(void)
{
	unsigned int i,j;
	unsigned int pic;

    lc_fact =0;
	
    //SP_BUZZ(0,SpMode0);
        
    i=TIM0_TCNT;
    i=i+250;
	TIM0_TC6=i;
    TIM0_TIE_C6I = 1;
    
	TIM1_TIE_C5I=1;
    
    //i=TIM1_TCNT;
    //i=i;// 4ms
	//TIM1_TC4=TIM1_TCNT;
	TIM1_TIE_C4I=1;

	

	//#ifdef AUTO_GEAR
	//TIM1_TIE_C6I = 0;	//处理里程上电抖动现象
	//#else
   	//TIM1_TIE_C6I = 1;	//处理里程上电抖动现象
  	//#endif
    
	TIM1_TIE_C0I=1;
	//定时器中断

	//TIM0_TIE_C6I = 1;
	//TIM1_TIE_C7I = 1;
	//TIM1_TIE_C4I = 1;
	
	
	CANRIER_RXFIE = 1;     // Enable Full Receive Buffer interrupt

	CAN_ComCycTime_Init();

    main_sleep=0;

    //init_canParameter();
	//init_Varible();
    
    //init_diag_perameter();
	second_tft_1s=0;
	rolling_count=0;
	second_1s=0;
    second_501ms=0;
	second_500s=0;
	
	pro_start=0;		// 开机自检标志

	Dis_LampLever_En = 0;

   
	//second_can[ID1A0]=second_can[ID31D]=second_can[ID281]=second_can[ID278]=second_can[ID2EA]=
	//second_can[ID211]=second_can[ID392]=second_can[ID311]=0;
	second_tft_1s=0;
	diag_mode_out=0;
	pro_start_dtc=pro_start_ry=0;
	
	//fuel_failure_statueb=0;//燃油失效恢复bug
	tmps_enable=0;
	radarDataL=31;
	radarDataR=31;
	radarDataM=31;
    
	door_enable=0;
    #if 0
	if(maintenance==0)
	{
		 out_maint=1;
	}
	else
	{
		 out_maint=0;
         //maintenance_dic=maintenance;
	}
    #endif
	


	ms_flash=1;
	

	belt_enable=0;
    diag_IndicatorsControl_en=0;
    //if(IG_IN)
    //{
            //PWMDTY4 = 0xff;
            //PWMDTY5 = 0xff;
    //}
	//LAMP_DRV_ON;
    //TFT_DRV_ON;
        
	ign_jsq=0;
   
    
	tft_start=0;
	
    
	disp_en.pp|=0x7ef; //
	key_lianxu_en=0;
    PageClear=PageClr_No;
    set_over_speed=120;
    DispClockSet=0;

    KeyPressHandleEn=0;
    KeyPressHandleWattingCnt=0;

	V_Power_12V_Turn_On_Off(V_Power_On);		/* 12V输出打开 */
	V_Power_5V_Turn_On_Off(V_Power_On);			/* 5V输出打开 */

}



void Init_Ad(void)
{
	// 设置ADC端口复用使能
	ATDDIENH = 0x00;	//在只有8个ADC口时该寄存器默认为0
	ATDDIENL = 0x00;	//端口复用设置，0：AD采样口 1：普通IO口
    //ATDDIENL = 0xf7; 	// enable digital inputs on Switches

	// init ad pro
    ATDCTL1 = 0x20;  	// 10-Bit resolution
    ATDCTL3 = 0x88;		//0x88;   Right Justified Data, Single conversion sequence
    ATDCTL4 = 0x01;  	// 8MHz ATD Clock, 4 ATD Clock cycles sample time
    ATDCTL5 = 0x00;  	// Start Single Conversion on PAD00
}


void Init_Pwm(void)
{
	/* PWM端口全部映射到PP口上 */
    PTPRRL = 0x00; // 设定pwm 在哪路上
    PTPRRH=  0x01;	// PWM7 映射到PS1口
    
	PWMSCLA=128;		//A= 32M/128=250Khz     .SA =A/[(2*128)]= 1khz
	PWMSCLB=5;//5;		//B=32M/128=250khz      .SB = B/[(2*5)]=25khz

	PWMCAE = 0x7f; 		// 1: 中心对齐 0:左对齐
	PWMPOL = 0xFF; 		//Set polarity for channels 0 - 7 设置先是低电平还是高电平
	//B01
	PWMCLK =   0x80;   	//	=1SB  =0B 设置每个端口的时钟源
	PWMPRCLK = 0x77;	// PWM Prescale Clock Select Register ()  Bus clock / 128[B/128] [A/128] 设置时钟分频系数

    PWMPER0 = 0x50;		 //A/SA 表盘背光
    PWMPER1 = 0x50; 	 //A/SA LCD背光
    PWMPER2 = 250; 	     //B/SB
    PWMPER3 = 0x80; 	 //B/SB TFT背光:中心对齐：f=clock xx/(2*PWMPERx) =B/2*250=250Khz/500=500Hz
    PWMPER4 = 0xFF; 	 //A/SA 车速输出
    PWMPER5 = 0x80; 	 //A/SA 蜂鸣器:中心对齐：f=clock xx/(2*PWMPERx) f=A/2*128 =250K/256Khz=1khz
    PWMPER6 = 0xFF;     //B/SB 标牌背光:中心对齐：f=B/2*255=250khz/500=490hz
    PWMPER7 = 250;       //B/SB  水温外发:左心对齐：f=clock xx/(PWMPERx) =SB/250=25Khz/250=100Hz


	PWMDTY0 = 250;		// 表盘背光
	PWMDTY1 = 250;		// LCD背光
	PWMDTY2 = 0x00;
	PWMDTY3 = 0x00;		
	PWMDTY4 = 0x00;
	PWMDTY5 = 0x00; //A 蜂鸣
	PWMDTY6 = 0x00; //A 背光
	PWMDTY7 = 25;   //SB 水温

	PWME = 0x00;	//0xc8    //Enable PWM channels 0 - 3
}

void Init_Eeprom_Data(void)
{
	ee_prom_read(6);
    ee_loop=(unsigned char )(ee_read_write[0]&0xff);
    if( (ee_loop==0) || (ee_loop>5) )
    	ee_loop=1;

    ee:;
    ee_prom_read(ee_loop);


    temp_a = (ee_read_write[1]>>8);
    temp_a = temp_a <<16;
    temp_a = temp_a +ee_read_write[2];

    lc_run_sum = ee_read_write[1]&0xff;
    lc_run_sum = lc_run_sum <<16;
    lc_run_sum =lc_run_sum +ee_read_write[0];

    if( (lc_run_sum-temp_a)>1 )
    {
		if( ee_loop!=1)
		ee_loop--;
		else
		ee_loop=5;

		goto ee;
    }
    temp_a =lc_run_sum;
    //if(temp_a>999999) temp_a=999999;
    ramdown[0]=temp_a%10;  temp_a=temp_a/10;
    ramdown[1]=temp_a%10;  temp_a=temp_a/10;
    ramdown[2]=temp_a%10;  temp_a=temp_a/10;
    ramdown[3]=temp_a%10;  temp_a=temp_a/10;
    ramdown[4]=temp_a%10;  temp_a=temp_a/10;
    ramdown[5]=temp_a%10;  temp_a=temp_a/10;

	ee_prom_read(6);

	clear_256=(ee_read_write[0]>>8);
	config_data[0].pp=(ee_read_write[1]);
	config_data[1].pp=(ee_read_write[2]);
    
	ee_prom_read(7);
	diag_canloss_code.pp=ee_read_write[0];
	diag_trouble_code.pp=ee_read_write[1];
	maintenance=ee_read_write[2];

	ee_prom_read(8);
    tripa_sum=(ee_read_write[0]);
    
	//config_data[3].pp=(ee_read_write[1]);
	//maintenance_dic=ee_read_write[2];

	temp_a=tripa_sum;
	ramup_a[0]=temp_a%10;temp_a=temp_a/10;
	ramup_a[1]=temp_a%10;temp_a=temp_a/10;
	ramup_a[2]=temp_a%10;temp_a=temp_a/10;
	ramup_a[3]=temp_a%10;temp_a=temp_a/10;
	ramup_a[4]=temp_a%10;


	if(lc_little_total>9)
		lc_little_total=0;
}

void Init_Uart(void)
{
     
     SCIACR1_RXEDGIE=0;
     //Receive Input Active Edge Interrupt Enable 唤醒仪表用
     // 0 RXEDGIF interrupt requests disabled
     // 1 RXEDGIF interrupt requests enabled
     DDRS_DDRS0=0;
     DDRS_DDRS1=1;

     PERS=1;  // 0去除上下拉能力
     
     PTSRR  = 0x01;
     //LNSLP=1;//输出lin
	
	
	
    SCISR2 = 0x00; 
    // 0: The registers labelled SCIBDH (0x0000),SCIBDL (0x0001), SCICR1 (0x0002) are accessible
    
    //Set the Baud Rate 
    //BaudRatePrescaler =104;//(unsigned int)(32000000 / (16 * Baud_Rate));
	//Configure the SCI to Tx and Rx using the defined Baud Rate
    SCIBDH = 0x06;		//SCI Baud Rate Registers (SCIBDH, SCIBDL)这两个是时钟设置寄存器
    SCIBDL = 0x83;   // [208:9615hz] 104 [0x683:1200hz]

    
	
    SCICR1 = 0x00;  //SCI disabled in wait mode 8 Data Bits, 1 Start Bit, 1 Stop Bit, odd Parity Address mark wakeup
    //Data Bits = 8
	//Parity = None
	//Start Bits = 1
	//Stop Bits = 1

    
    SCISR2 = 0x82;    //自己加的   86  0x82
    // 1: The registers labelled SCIASR1 (0x0000),SCIACR1 (0x0001), SCIACR2 (0x00002) are accessible
    
    #if 0
    
    SCIACR2 = 0x01;   //Break detect circuit enabled

    SCIACR1 = 0x01;   //BKDIF interrupt requests enabled
    //SCI Alternative Control Register 1 (SCIACR1)
    #endif
    
    //SCICR2 = 0x2c;    // 0x2c Enable Tx and Rx     0x0c enable receive interrupt
    SCICR2_RIE=1;
    //Receiver Full Interrupt Enable Bit—RIE enables the receive data register full ?ag, RDRF, or the overrun ,
    //OR, to generate interrupt requests.
    // 0: RDRF and OR interrupt requests disabled
    // 1: RDRF and OR interrupt requests enabled
    SCICR2_TE=0;
    //Transmitter Enable Bit — TE enables the SCI transmitter and con?gures the TXD pin as being controlled by
    //the SCI. The TE bit can be used to queue an idle preamble.
    // 0: Transmitter disabled
    // 1: Transmitter enabled
    SCICR2_RE=1;
    //Receiver Enable Bit — RE enables the SCI receiver.
    // 0 Receiver disabled
    // 1 Receiver enabled
    //LIN_State=1;

    SCIASR1=0x81;
}


void Init_Dflash(void)
{
	#if(CALLBACK_ENABLE == TRUE)
    CallBack = CallBackFunc;
    #endif

    returnCode = FlashInit();
    if ( EED_OK != returnCode )
    {
        ErrorTrap();
    }

    returnCode = FSL_InitEeprom();
    if (EED_OK != returnCode)
    {
        ErrorTrap();
    }

    while(BUSY == EE_Status)
    {
        FSL_Main();
    }

    if(FAIL == EE_Status)
    {
        ErrorTrap();
    }
}


void Init_Timer(void)
{
	//Input Capture  setting
 	//PTTRR_PTTRR5=0; 		// Route IOC0_7 routed to PT7
 	PTTRR_PTTRR1 = 1; 		// Route IOC1_7 to Pr3
	PTTRR_PTTRR0 = 1;   		// Route IOC1_6
	PTTRR_PTTRR4 = 0;		// Route IOC0_6

	TIM1_TSCR1_PRNT = 1;		//必须先声明 复位后只有一次有效Enables precision time
	TIM1_TSCR1_TEN = 0; 		//Disable timer module before adjusting registers.
	//T1_0 
	TIM1_TIOS_IOS0 = 1; 		//Set Channel 0 as output compare
	TIM1_TC0 = 128;  		//
	TIM1_TIE_C0I = 0;   		//Enable channel 6 interrupt, handled by function TIM0CH6_ISR.
	TIM1_OCPD_OCPD0=1;
	
	//T1_1 
	TIM1_TIOS_IOS1 = 1; 		//Set Channel 1 as output compare
	TIM1_TC1 = 128;  		//
	TIM1_TIE_C1I = 0;   		//Enable channel 6 interrupt, handled by function TIM0CH6_ISR.
	TIM1_OCPD_OCPD1=1;	
	
	//T1_1 
	TIM1_TIOS_IOS2 = 1; 		//Set Channel 1 as output compare
	TIM1_TC2 = 128;  		//
	TIM1_TIE_C2I = 0;   		//Enable channel 6 interrupt, handled by function TIM0CH6_ISR.
	TIM1_OCPD_OCPD2=1;
		
	TIM1_TCTL3_EDG6A = 1;		//Set channel 6 to capture any edge transition.
	TIM1_TCTL3_EDG6B = 0;		//Set channel 6 to capture any edge transition.
	TIM1_TIE_C6I = 0;    		//Enable channel 6 interrupt, handled by function TIM1ISR. 1=============================================================
	TIM1_OCPD_OCPD6=1; //预留

	//定时功能
	//设置TIM1C1_4 功能
	// 0 0 Capture disabled
    // 0 1 Capture on rising edges only
    // 1 0 Capture on falling edges only
    // 1 1 Capture on any edge (rising or falling)
	TIM1_TCTL3_EDG4A = 1;		//Set channel 4 to capture rising edge transition.
	TIM1_TCTL3_EDG4B = 1;		//Set channel 4 to capture rising edge transition.
    TIM1_TIE_C4I = 0;   

	TIM1_TIOS_IOS5 = 1; 		//Set Channel 6 as output compare
	TIM1_TC5 = 128;  			//8us*128用于车速外发 Set a value for channel 6 timer compare.
	TIM1_TIE_C5I = 0;   		//Enable channel 6 interrupt, handled by function TIM0CH6_ISR.
	TIM1_OCPD_OCPD5=1;

	TIM1_TSCR2_TOI = 1;  		//Hardware interrupt requested when TOF flag set.

	TIM1_TSCR1_TSWAI = 1;		//Disables the timer module while in wait mode.
	TIM1_TSCR1_TSFRZ = 1;		//Disables the timer counter while in freeze mode.

	TIM1_PTPSR  = 0xff;  		//TIM1_TSCR2_PR = 0x07; //0x06Set prescaler to divide by 64.   0x07Set prescaler to divide by 128.
	TIM1_TSCR2_PR= 0x07;
	TIM1_TSCR1_TEN = 1;  		//Timer Enable.

	//定时功能

	TIM0_TIOS_IOS6 = 1; 		//Set Channel 6 as output compare.——————1ms
	TIM0_TC6 = 250;  			//Set a value for channel 6 timer compare.
	TIM0_TIE_C6I = 0;   		//Enable channel 6 interrupt, handled by function TIM0CH6_ISR.
	TIM0_OCPD_OCPD6=1;

	TIM0_TCTL4_EDG2A = 0;
	TIM0_TCTL4_EDG2B = 1;
	TIM0_TIE_C2I = 0; // 1yy		//倒车雷达 Capture on falling edges only

	TIM0_TSCR1_TSWAI = 1;	//Disables the timer module while in wait mode.
	TIM0_TSCR1_TSFRZ = 1;	//Disables the timer counter while in freeze mode.
	TIM0_TSCR2_PR = 0x7;		//Set prescaler to divide by 2.
	TIM0_TSCR1_TEN = 1; 		//Timer Enable.
}


void init_data(void)
{
	unsigned int i,temp_data;

    Init_Dflash();
	Init_Port();		/* 端口口初始化 */

	
	Init_Timer();		/* 中断初始化 */
    /*************************pwm****************************************/
	Init_Pwm();
	Init_Can();
    //Init_Uart();

    Init_Ad();
    Init_Eeprom_Data();
	


	gear=255;

	if(second_min>59)
	{
		second_min=0;
		second_hour=0;
	}
	
	if(second_hour>23)
	{
		second_min=0;
		second_hour=0;
	}

	//初始化屏时不允许背光亮
	//PWMDTY0= 0x00;

   	lc[0]=lc[1]=lc[2]=lc[3]=lc[4]=lc[5]=lc[6]=lc[7]=50000;

    tripb_sum=0;
	
    rolling_count=0;
	rolling_count433=0;
	CanTxBatOver6vEn=1;
    init_data_reset();

	//SMG_Driver();
	LED_INT();
	NXP74HC165_init();

	
	MCU_O_LED_POWER_PB1 = 1;
	MCU_O_12V_PR4 = 1;
	MCU_O_OILVOLT1_PA6 = 0;		/* change by zhang */

    init_smc_parameter();

    LCD_DisplayInit(); // 0.7s初始化时间
    
    //MCU_O_BLACK_LIGHT_PP1 = 1;	/* 表盘背光 */
	MCU_O_TFT_POWER_PV6 = 1;	/* 使能TFT电源开关，调光暂时还没有做 */
	//MCU_O_TFT_PWM_PP0 = 1;
	PWME = 0x03;	/* 使能PWM0 PWM1端口 */
    
	
}

void ig_off(void)//IG关闭
{
	if( (second_1s-second_ig)>200 ) 
	{
		second_ig=second_1s-201;
		if(main_sleep==0)
		{
			main_sleep=3;							
		}

		V_Power_12V_Control(V_Power_Off);
		V_Power_5V_Control(V_Power_Off);
		
		MCU_O_LED_POWER_PB1 = 0;
		MCU_O_12V_PR4 = 0;
		MCU_O_OILVOLT1_PA6 = 1; 	/* change by zhang */
		
		LED_Clear();
		SMG_Display_Clear();
			//LCD_DisplayInit();
		
		MCU_O_TFT_POWER_PV6 = 0;	/* 使能TFT电源开关，调光暂时还没有做 */
		//MCU_O_TFT_PWM_PP0 = 0;
		//MCU_O_BLACK_LIGHT_PP1 = 0;
		PWME = 0x00;	
	}	
}

void ig_on(void)
{
	main_sleep=0;
	//MCU_O_BLACK_LIGHT_PP1 = 1;
	MCU_O_TFT_POWER_PV6 = 1;	/* 使能TFT电源开关，调光暂时还没有做 */
	//MCU_O_TFT_PWM_PP0 = 1;
	PWME = 0x03;							/* 关闭所有PWM输出 */

	MCU_O_LED_POWER_PB1 = 1;
	MCU_O_12V_PR4 = 1;
	MCU_O_OILVOLT1_PA6 = 0; 	/* change by zhang */
		
	
	//LCD_DisplayInit();
		
	
	LED_INT();
}




// git test
void main(void)
{
	u16 temp_CJF1,temp_CJF2;

    
	unsigned int i,j;
	byte txbuffer;
	DisableInterrupts;
	init_clock();
    boot_flag=0x0000;//清除boot标记

	lamp_lever_sum=3;
	init_data();

    studyEn=1; //允许自学习
	EnableInterrupts;

	for(;;)
	{
		if( main_sleep>2 )
        {
            if(MCU_I_POWER_PP6==0) //无IG输入
            {
				__RESET_WATCHDOG();	
				if(main_sleep==3)
				{
					//asm ANDCC #0x7F; // Clear S-bit in the CCR to enable STOP instruction 
					//asm STOP
				} 
			}
			else
            {
                __RESET_WATCHDOG();	  
				//immo_pro();	
              	//init_data();//该函数内包含init_data函数  初始化main_sleep为0
              	ig_on();
                //EnableInterrupts;          
            }    
		}
		else	//main_sleep<=2
		{
			__RESET_WATCHDOG();	
            if(MCU_I_POWER_PP6==0) //无IG输入
            {
				__RESET_WATCHDOG();	
				ig_off();
			}
			else//有IG输入
			{
				__RESET_WATCHDOG();
				second_ig=second_1s;

				//SMG_Driver();



				__RESET_WATCHDOG();	
				scan();				/* 里程处理 */

				__RESET_WATCHDOG();	
				Can_Tx_Process();

				__RESET_WATCHDOG();	
				Key_Process();


				if((second_1s - second_501ms)>500)
				{
					second_501ms = second_1s;
					//if(no_key_c<=250)no_key_c++;
					//if(no_keyr_c<=250)no_keyr_c++;
					
					if(ign_jsq<=250)				// 点火启动计数器，每500ms计数一次
						ign_jsq++;
				}
				
				
				
        		if((second_1s - second_100ms)>100)
        		{
        			second_100ms = second_1s;
					Loop_500ms_Count++;
					if(Loop_500ms_Count == 5)
					{
						Loop_500ms_Count = 0;
						Loop_500ms = ~Loop_500ms;
					}
					
					if(pro_start>0)			/* 开机自检结束后正常处理LED信号灯 */
					{
						LED_Process();
					}
		        	Receive_74CH165_Byte();

					//Buzzer_Manage();
					//Receive_74CH165A_Byte();
		        	//Receive_74CH165_Read_Byte_Test();
            
        		}


				
        		if((second_1s - second_20ms)>20)
        		{   
            		ADC_Process();
                    lc_control();
                    zs_control();
					EngOilPress_Control();
            		second_500s=second_1s;
					CanLoss_Process();
			        
					
            		//Smeter[Mc_Speed].inp
                	//tachodata=sml_inp;
            		LCD_DisplayProcess();
        		}
			}
		}
		__RESET_WATCHDOG();	
  	}   					
}

