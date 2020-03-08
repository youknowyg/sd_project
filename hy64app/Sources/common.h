#ifndef _COMMON_H
#define _COMMON_H

#define TXBUFF02 0

#define TRUE    1
#define FALSE    0


#define    out_esc      PORTB_PB0
#define    out_escoff   PTH_PTH6
#define    out_mil      PTH_PTH4

#define     ID706       0
#define     IDTxMAX     1

typedef enum{ 
ID430,//	(0)
ID258,//	(1)
ID631,//   (2)
ID652,//   (3)
ID670,
ID300,
ID390,
ID320,
ID630,
ID63E,
ID433,
ID341,
ID230,
ID301,
ID432,
ID304,
ID562,
ID3FA,
ID766,//	(10)
ID7DF,//	(18)
ID5A1,//	(12)
IDMAX//	(19)
}CanId;

typedef enum{   
    VCU_ST_SOC,	 //电量
    VCU_ST_VOL,
    VCU_ST_CURR,
    VCU_ST_SPEED,
    VCU_ST_GEAR,
    VCU_ST_HOUR,
    VCU_ST_MIN,
    VCU_ST_TACHO, //电池切断
    VCU_ST_DTE,
    VCU_ST_SEC,
    VCU_ST_CHARGTIME,
    VCU_ST_LEFT,
    VCU_ST_RIGHT,
    VCU_ST_LIGHT,
    VCU_ST_HIGHLAMP,
    VCU_ST_FRONTFOG,
    VCU_ST_REARFOG,
	AMOUNT_END //主要是用VarID
	
}ValCtrlDef;

//设备ID定义
typedef enum{  	
	DEV_LCD_SOC,
    DEV_LCD_VOL,
    DEV_LCD_CURR,
    DEV_LCD_SPEED,
    DEV_LCD_GEAR,
    DEV_LCD_HOUR,
    DEV_LCD_MIN,
    DEV_LCD_TACHO,
    DEV_LCD_DTE,
    DEV_LCD_SEC,
    DEV_LCD_CHARGTIME,
    DEV_LED_LEFT,
    DEV_LED_RIGHT,
    DEV_LED_LIGHT,
    DEV_LED_HIGHLAMP,
    DEV_LED_FRONTFOG,
    DEV_LED_REARFOG,
}DeviceDef;

//条件判断定义
typedef enum{ 
	VCU_ST_SOC_D,
    VCU_ST_VOL_D,
    VCU_ST_CURR_D,
    VCU_ST_SPEED_D,
    VCU_ST_GEAR_D,
    VCU_ST_HOUR_D,
    VCU_ST_MIN_D,
    VCU_ST_TACHO_D,
    VCU_ST_DTE_D,
    VCU_ST_SEC_D,
    VCU_ST_CHARGTIME_D,
    VCU_ST_LEFT_D,
    VCU_ST_RIGHT_D,
    VCU_ST_LIGHT_D,
    VCU_ST_HIGHLAMP_D,
    VCU_ST_FRONTFOG_D,
    VCU_ST_REARFOG_D,
}ValCmpDef;
//
typedef enum{
	LED_READY,	    
    LED_READYVALID, //有效
    LED_BATCUT,
    LED_CONNECT,
    LED_LEFT,
    LED_RIGHT,
    LED_LIGHT,
    LED_HIGHLAMP,
    LED_FRONTFOG,
    LED_REARFOG,
	LED_END   
}LedNameDef;

//操作符号定义
typedef enum{
	OPT_EQUAL,		//等于
	OPT_LARGER,		//大于
	OPT_SMALLER,	//小于
	OPT_NOT_SMALLER,//大于或等于
	OPT_NOT_LARGER,	//小于或等于
	OPT_NOT_EQUAL,	//不等于
	OPT_DIR_OUT	//不判断，直接输出
}OpratorDef;

typedef enum{
    LED_Define,
    LED_ON,		
	LED_OFF,
	LED_1HZ_FLASH,
	LED_2HZ_FLASH
}LedStuDef;

#define CAN_BUF_SIZE	8
#define u8 unsigned char
#define u16 unsigned short
#define u32 unsigned long

typedef enum
{
    POWER_MODE_OFF,   /* OFF档电 */
    POWER_MODE_ES,    /* 发动机设置 */
    POWER_MODE_START, /* 开机自检(3s) */
    POWER_MODE_ON,    /* ON档电 */
    POWER_MODE_LOCK,  /* 锁车 */
} PowerModeType;

typedef enum
{
    KEY_UP,   
    KEY_DOWN,    
    KEY_TRUE, 
    KEY_BACK,    
    KEY_NOP,  
} KeyType;

typedef struct{
   unsigned char cnt;
   unsigned char stu;
   unsigned char en;
   unsigned char inputValue;
   unsigned char outputValue;
}LedDef;

typedef enum
{    
    buzz_brake, //刹车
    buzz_seat,  //安全带
    buzz_overspeed, 	//故障
    buzz_rader, 	    //雷达
    buzz_door, 	//转向灯
    buzz_turn_on 	//转向灯
}Tone_Type;  //蜂鸣器声音类型

typedef struct{
   unsigned long Value;
   unsigned long ValueMax;
   unsigned long ValueMin;
   unsigned char  UpdataFlg;
   unsigned char  ConnectFlg;
   unsigned char  LedStu;
}VarDef;

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
}CanFrameDef; 

typedef struct{
	unsigned short ItemID;			//条件ID	
    unsigned short VarID;		    //变量表索引值
	unsigned char  Oprator;	        //判断条件
	unsigned long  Value;		    //比较值
	unsigned short Led;				//条件对应的LED
	unsigned char  OnOffFlash;	    //LED点亮还是关闭,闪烁
	unsigned char  BeepCtrl;		//是否需要蜂鸣报警
	unsigned short BeepSpeedSet;	//蜂鸣器报警音间隔设置
	unsigned short DeviceID;		//输出设备ID
}VarCtrlDef;

typedef struct{
	unsigned short Led;				//条件对应的LED
	unsigned char  IgOff;			//igoff后是否启动
	unsigned char  IgOffDefine;		//igoff后状态
	unsigned char  CheckEn;		    //自检是否控制
	unsigned int OpenDelay;		//开启延时
	unsigned int CloseDelay;	    //关闭延时
}LedCtrlDef;

typedef struct{
	unsigned short VarID;		//变量表索引
	unsigned long CanID;		//CAN_ID值
	unsigned char  StartByte;	//在CAN缓冲区的字节位置
	unsigned char  StartBit;	//在CAN缓冲区的bit位置
	unsigned char  Length;		//变量bit长度，也就是占几位
  unsigned long perBitMolecule;            //bit精度分子
  unsigned long perBitDenominator;         //bit精度分母
  unsigned long offset;   
  unsigned long ValueMin;
  unsigned long ValueMax;
  unsigned long sDefine;    //初始默认值
}CanVaribleDef;

struct can_msg     //发送报文的结构体
{
    unsigned long id;
    unsigned char RTR;
    unsigned char data[8];
    unsigned char len;
    unsigned char prty;
};

typedef struct{
	unsigned long CanID;		//CANID
	unsigned char OnLineFlg;	//在线状态判断值
	unsigned short NoComTime;	//CANID断开连接计时

}CanIdUserDef;  //CAN数据结构体

#endif


