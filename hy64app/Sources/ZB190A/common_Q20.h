#ifndef _COMMON_H
#define _COMMON_H



#define u8 unsigned char
#define u16 unsigned short
#define u32 unsigned long

#define TRUE    1
#define FALSE    0

#define     ID706       0
#define     IDTxMAX     1
#define CAN_AlignMode	0	//大小端对其模式: 0为小端模式 inter, 1为大端模式motrol

#define Fuel_Temp_dn    7//5
#define Fuel_Temp_Max   1// 1

#define RY_V_START          0
#define RY_V_FAST           1
#define RY_V_SLOW           2


#define TXBUFF02 0



#define Bat6000mV    290 // 6.0V
#define Bat6500mV    310 // 6.5V
#define Bat9500mV    450 // 9.5V
#define Bat18000mV   920 // 18V

#define PageClr_SPEED  0 
#define PageClr_INFO   1
#define PageClr_ERRCODE  2
#define PageClr_CLOCKSET  3
#define PageClr_CdConnect  4
#define PageClr_radar   5
#define PageClr_No      255

#define FUNCTION_SPEED  0 
#define FUNCTION_INFO   1
#define FUNCTION_ERRCODE  2

#define FUNCTION_RADAR  3
#define FUNCTION_CD     4

    
#define SpMode0         0
#define SpMode_Tpms     1
#define SpMode_Door     2
#define SpMode_Turn     3
#define SpMode_radar    4
#define SpMode_No       5




#define     canloss_ID1A0       diag_canloss_code.bit.p0
#define     canloss_ID31D	    diag_canloss_code.bit.p1
#define     canloss_ID281		diag_canloss_code.bit.p2            
#define     canloss_ID540	    diag_canloss_code.bit.p3
#define     canloss_ID225	    diag_canloss_code.bit.p4
#define     canloss_ID230	    diag_canloss_code.bit.p5
#define 	canloss_ID525		diag_canloss_code.bit.p6 //
#define     canloss_ID58B	    diag_canloss_code.bit.p7

#define    canloss_ID320	    diag_canloss_code.bit.p8
#define    canloss_ID311	    diag_canloss_code.bit.p9
#define    canloss_ID392	    diag_canloss_code.bit.p10
#define    canloss_ID5A0_5A1	diag_canloss_code.bit.p11
#define    canloss_ID393	    diag_canloss_code.bit.p12  
#define    canloss_ID590	    diag_canloss_code.bit.p13  
#define    canloss_ID435	    diag_canloss_code.bit.p14 
#define    canloss_4wd	        diag_canloss_code.bit.p15



#define  out_tpms                   L1.bit.p0   //  
#define  out_driverbelt             L1.bit.p1   //     
#define  out_epb                     L1.bit.p2   //    
#define  out_eps                    L1.bit.p3   //    
#define  out_CdConnect              L1.bit.p4   //    
#define  out_CdLock                 L1.bit.p5   //   
#define  out_car                    L1.bit.p6   //     
#define  out_wugui               L1.bit.p7   //out_qtoff   

#define  out_escoff      L2.bit.p0 //out_qt         
#define  out_esc         L2.bit.p1//   
#define  out_BatCut      L2.bit.p2//      
#define  out_SocR       L2.bit.p3//        
#define  out_MotorHot       L2.bit.p4// 
#define  out_ZKB         L2.bit.p5               
#define  out_Bat      L2.bit.p6//辅助电池故障     
#define  out_SocG        L2.bit.p7//   




#define    outLed_Door          PT1AD_PT1AD1
#define    outLed_Insulate      PT1AD_PT1AD2 //绝缘
#define    outLed_BatHot        PT1AD_PT1AD3
#define    outLed_BatFault      PT1AD_PT1AD4



/* CAN Trancever 低使能，高关闭 */
#define CAN_DRV_ON				PTR_PTR0 = 0  	//PR0
#define CAN_DRV_OFF				PTR_PTR0 = 1

#define LAMP_DRV_ON                 //PWME_PWME4=1
#define LAMP_DRV_OFF                //PWME_PWME4=0

#define TFT_DRV_ON                  //PWME_PWME5=1
#define TFT_DRV_OFF                 //PWME_PWME5=0


#define		LAMP_IN	        PTT_PTT4
#define		EPB_IN		    PTT_PTT1
#define		BREAKLEVER_IN	PTP_PTP0 //真空泵
#define		DOOR_IN	        PTP_PTP7
#define     BeltMaster_IN   PTR_PTR2
#define		KEY_PAGE_IN	    PTR_PTR1
#define		KEY_ADJU_IN	    PTIS_PTIS7
#define		KEY_IN	        PORTA_PA5


#define		OUT_MoBackGround	PTV_PTV0
#define		OUT_ShutDown	    PTV_PTV1
#define		IG_IN		        PTS_PTS7
 
#if 0
typedef enum{ 
ID18FFDC01,//	(0)
ID0CFF7902,//   (3)
ID0CFF7B02,
ID0CFF7C02,
ID0CFF7D03 ,
ID0CFF7E03,
ID0CFF7F03,
ID0CFF8103,
ID18FEDCD5,//	
ID18FEDED5,//   (2)
ID766,
ID7DF,
IDMAX//	(19)
}CanId;
#endif

typedef enum{ 
	ID0CF00400,		//0
	ID18FEEE00,		//1
	ID18FE5600,//2
	ID18FEEF00,//3
	ID18FEE900,//4
	ID18FEE500,//5
	ID18FECA00,//6
	ID18ECFF00,//7
	ID18EBFF00,//8
	ID18FECA3D,//9
	ID18ECFF3D,//10
	ID18EBFF3D,//11
	ID18FECA0B,//12
	ID18ECFF0B,//13
	ID18EBFF0B,//14
	ID0CF00300,//15
	ID18FED921,//16
	ID18FF0C21,//17
	ID18FF0B21,//18
	ID18F0000F,//19
	ID18F0010B,//20
	ID18FEFF00,//21
	ID18FEF100,//22
	ID18FEE400,//23
	ID18FD7C00,
	ID18FF1110,
	ID18FEF300,
	ID18FEF437,
	ID18FE24EE,
	ID18FF2121,
	ID18FF2221,
	ID18FD0700,
	ID18FEF433,
	ID18FED917,
	IDMAX//	(19)
}CanId;


typedef struct
{
    unsigned char  index[2];
    unsigned char  data[72];
}BWord;


#define CAN_BUF_SIZE	8

typedef struct{	
	unsigned long  TCanId;
    union  
	{
		unsigned char	pp;
		struct {
				unsigned char	p0:1;
				unsigned char	p1:1;
				unsigned char	p2:1;
				unsigned char	p3:1;
				unsigned char	p4:1;
				unsigned char	p5:1;
				unsigned char	p6:1;
				unsigned char	p7:1;
			}bit;
	}data[CAN_BUF_SIZE];
	//unsigned char  Gdata[CAN_BUF_SIZE];
	unsigned char  TOnLineFlg;		//在线状态判断值
	unsigned short NoComTimeCnt;	//CANID断开连接计时
	unsigned short ComCycTime;
}CanFrameDef; 




typedef enum
{
    POWER_MODE_OFF,   /* OFF档电 */
    POWER_MODE_ES,    /* 发动机设置 */
    POWER_MODE_START, /* 开机自检(3s) */
    POWER_MODE_ON,    /* ON档电 */
    POWER_MODE_LOCK,  /* 锁车 */
} PowerModeType;




#endif


