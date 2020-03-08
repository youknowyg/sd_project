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
    VCU_ST_SOC,	 //����
    VCU_ST_VOL,
    VCU_ST_CURR,
    VCU_ST_SPEED,
    VCU_ST_GEAR,
    VCU_ST_HOUR,
    VCU_ST_MIN,
    VCU_ST_TACHO, //����ж�
    VCU_ST_DTE,
    VCU_ST_SEC,
    VCU_ST_CHARGTIME,
    VCU_ST_LEFT,
    VCU_ST_RIGHT,
    VCU_ST_LIGHT,
    VCU_ST_HIGHLAMP,
    VCU_ST_FRONTFOG,
    VCU_ST_REARFOG,
	AMOUNT_END //��Ҫ����VarID
	
}ValCtrlDef;

//�豸ID����
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

//�����ж϶���
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
    LED_READYVALID, //��Ч
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

//�������Ŷ���
typedef enum{
	OPT_EQUAL,		//����
	OPT_LARGER,		//����
	OPT_SMALLER,	//С��
	OPT_NOT_SMALLER,//���ڻ����
	OPT_NOT_LARGER,	//С�ڻ����
	OPT_NOT_EQUAL,	//������
	OPT_DIR_OUT	//���жϣ�ֱ�����
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
    POWER_MODE_OFF,   /* OFF���� */
    POWER_MODE_ES,    /* ���������� */
    POWER_MODE_START, /* �����Լ�(3s) */
    POWER_MODE_ON,    /* ON���� */
    POWER_MODE_LOCK,  /* ���� */
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
    buzz_brake, //ɲ��
    buzz_seat,  //��ȫ��
    buzz_overspeed, 	//����
    buzz_rader, 	    //�״�
    buzz_door, 	//ת���
    buzz_turn_on 	//ת���
}Tone_Type;  //��������������

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
	unsigned char  TOnLineFlg;		//����״̬�ж�ֵ
	unsigned short NoComTimeCnt;	//CANID�Ͽ����Ӽ�ʱ
}CanFrameDef; 

typedef struct{
	unsigned short ItemID;			//����ID	
    unsigned short VarID;		    //����������ֵ
	unsigned char  Oprator;	        //�ж�����
	unsigned long  Value;		    //�Ƚ�ֵ
	unsigned short Led;				//������Ӧ��LED
	unsigned char  OnOffFlash;	    //LED�������ǹر�,��˸
	unsigned char  BeepCtrl;		//�Ƿ���Ҫ��������
	unsigned short BeepSpeedSet;	//�������������������
	unsigned short DeviceID;		//����豸ID
}VarCtrlDef;

typedef struct{
	unsigned short Led;				//������Ӧ��LED
	unsigned char  IgOff;			//igoff���Ƿ�����
	unsigned char  IgOffDefine;		//igoff��״̬
	unsigned char  CheckEn;		    //�Լ��Ƿ����
	unsigned int OpenDelay;		//������ʱ
	unsigned int CloseDelay;	    //�ر���ʱ
}LedCtrlDef;

typedef struct{
	unsigned short VarID;		//����������
	unsigned long CanID;		//CAN_IDֵ
	unsigned char  StartByte;	//��CAN���������ֽ�λ��
	unsigned char  StartBit;	//��CAN��������bitλ��
	unsigned char  Length;		//����bit���ȣ�Ҳ����ռ��λ
  unsigned long perBitMolecule;            //bit���ȷ���
  unsigned long perBitDenominator;         //bit���ȷ�ĸ
  unsigned long offset;   
  unsigned long ValueMin;
  unsigned long ValueMax;
  unsigned long sDefine;    //��ʼĬ��ֵ
}CanVaribleDef;

struct can_msg     //���ͱ��ĵĽṹ��
{
    unsigned long id;
    unsigned char RTR;
    unsigned char data[8];
    unsigned char len;
    unsigned char prty;
};

typedef struct{
	unsigned long CanID;		//CANID
	unsigned char OnLineFlg;	//����״̬�ж�ֵ
	unsigned short NoComTime;	//CANID�Ͽ����Ӽ�ʱ

}CanIdUserDef;  //CAN���ݽṹ��

#endif


