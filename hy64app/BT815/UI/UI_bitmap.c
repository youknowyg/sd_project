/*************************
	UI_bitmap.h
************************/
/* 
    Sample code to show how to display bitmap
    Author: Hawk
	Email : hawk.gao@ftdichip.com
	Date  : 2016/Jan
            2018/Jun - Add ASTC support
*/
#include "main.h"
#include "UI_bitmap.h"
#include "platform.h"
#include "EVE_Gpu.h"
#include "EVE_HAL.h"
#include "EVE_APP.h"
#include "SPI.h"
// #include <stdio.h>
// #include <string.h>


#if defined(FILESYS_USED)
#define DISPBP_L1              ROOT_PATH"bitmap\\L1.raw"
#define DISPBP_L8              ROOT_PATH"bitmap\\L8.raw"
#define DISPBP_RGB332          ROOT_PATH"bitmap\\RGB332.raw"
#define DISPBP_RGB565          ROOT_PATH"bitmap\\RGB565.raw"
/* use zlib compressed file to test the INFLATE function */
#define DISPBP_ARGB1555        ROOT_PATH"bitmap\\ARGB1555.bin"

#if defined(DEF_81X) || defined(DEF_BT81X)
#define DISPBP_PALETTE8        ROOT_PATH"bitmap\\Pal8_inx.raw"
#define DISPBP_PALETTE8_LUT    ROOT_PATH"bitmap\\Pal8_lut.raw"
/* use zlib compressed file to test the INFLATE function */
#define DISPBP_PALETTE565      ROOT_PATH"bitmap\\Pal565_inx.bin"
#define DISPBP_PALETTE565_LUT  ROOT_PATH"bitmap\\Pal565_lut.bin"
#define DISPBP_PALETTE4444     ROOT_PATH"bitmap\\Pal4444_inx.raw"
#define DISPBP_PALETTE4444_LUT ROOT_PATH"bitmap\\Pal4444_lut.raw"
/* use zlib compressed file to test the INFLATE function*/
#define DISPBP_ASTC4X4_RAM     ROOT_PATH"bitmap\\ASTC4x4.bin"

#else
#define DISPBP_PALETTE         ROOT_PATH"bitmap\\Pal_inx.raw"
#define DISPBP_PALETTE_LUT     ROOT_PATH"bitmap\\Pal_lut.raw"
#endif

#else

#define DISPBP_L1              ROOT_PATH"L1.raw"
#define DISPBP_L8              ROOT_PATH"L8.raw"
#define DISPBP_RGB332          ROOT_PATH"RGB332.raw"
#define DISPBP_RGB565          ROOT_PATH"RGB565.raw"
#define DISPBP_ARGB1555        ROOT_PATH"ARGB1555.raw"

#if defined(DEF_81X) || defined(DEF_BT81X)
#define DISPBP_PALETTE8        ROOT_PATH"Pal8_inx.raw"
#define DISPBP_PALETTE8_LUT    ROOT_PATH"Pal8_lut.raw"
#define DISPBP_PALETTE565      ROOT_PATH"Pal565_inx.raw"
#define DISPBP_PALETTE565_LUT  ROOT_PATH"Pal565_lut.raw"
#define DISPBP_PALETTE4444     ROOT_PATH"Pal4444_inx.raw"
#define DISPBP_PALETTE4444_LUT ROOT_PATH"Pal4444_lut.raw"
/* use zlib compressed file to test the INFLATE function*/
#define DISPBP_ASTC4X4_RAM     ROOT_PATH"ASTC4x4.bin"

#else
#define DISPBP_PALETTE         ROOT_PATH"Pal_inx.raw"
#define DISPBP_PALETTE_LUT     ROOT_PATH"Pal_lut.raw"
#endif

#endif

/* zlib compressed file in flash, DEINFLATE in RAM_G and display*/
#define DISPBP_ASTC4X4_ZFLH    "Z_FLASH@2249984"
/* raw file in Flash, display from RAM_G */
#define DISPBP_ARGB4_FLH       "EVEFLH@2217216:32768"
/* raw file in Flash, direct display from Flash*/
#define DISPBP_ASTC12X12_AFLH  "ASTC_FLASH@2257856"

#define HDL_START 0
#define FNT_WIDE  30
#define FNT_NUM   24
#define FNT_OPT   OPT_CENTERX
extern SmControlStu Smeter[Mc_MAX];
extern unsigned char yg_test;
extern unsigned char ramdown[6];
extern unsigned char ramup_a[6];

extern void DispTest(unsigned int data,unsigned char stu);

FTVOID ecar_getXYfrmCenter(FT16 Angle, FT16 Radius, FT16 *pX, FT16 *pY);


#define CoCmd_ROTATE(a)             HAL_CmdBufIn(CMD_ROTATE); \
                                    HAL_CmdBufIn((FT32)(a))

#define CoCmd_ROTATEAROUND(x,y,a,s) HAL_CmdBufIn(CMD_ROTATEAROUND); \
                                    HAL_CmdBufIn((FT32)(x)); \
                                    HAL_CmdBufIn((FT32)(y)); \
                                    HAL_CmdBufIn((FT32)(a)); \
                                    HAL_CmdBufIn((FT32)(s))



#define unified.blob                            "EVEFLH@ 0      : 4096"
#define a1_240x320_raw                          "EVEFLH@ 4096   : 76800" //背景1
#define b_num_16x20_raw                         "EVEFLH@ 80896  : 3200"  //12x20数字
#define c1_ready_80x32_raw                      "EVEFLH@ 84096  : 2560"  //ready灯
#define c2_warn_28x28_raw                       "EVEFLH@ 86656  : 832"  //绝缘故障灯
#define c3_seat_24x24_raw                       "EVEFLH@ 87488  : 2880" //安全带灯
//#define c3_seat_20x24_raw                       "EVEFLH@ 86848  : 4992"  //安全带图标
//#define c6_seat_24x24_raw                       "EVEFLH@ 89152  : 832"  //安全带图标

#define SOC_d1_6_160x160_raw                    "EVEFLH@ 90368  : 179200" //SOC圈
#define Power_e_200x200_raw                     "EVEFLH@ 277248 : 280000" //Power圈
// #define power_d7_96x40_raw                      "EVEFLH@ 242368 : 3840"  //灰色半圈
// #define power_d8_96x40_raw                      "EVEFLH@ 246208 : 3840"  //灰色半圈




#define FONT_ADD					(RAM_G)
#define FONT_HANDLE					(6)

app_para_t appGP = {0};


/*************************start logp********************************************/
ImgInfo_st info_StartLog[]=
{
		
    {a1_240x320_raw, 0, 0, 0},  
};
bmpHDR_st bmp_StartLog[] = 
{
	{COMPRESSED_RGBA_ASTC_4x4_KHR,240,320,(FTU32)&info_StartLog},
};

/********************************************************************
//相同尺寸的图合并调用需要去做类似处理
#define w64_64_0_64x64_raw          "EVEFLH@16267008 : 40960"
//#define w64_64_1_64x64_raw          "EVEFLH@16271104 : 4096"
********************************************************************/
typedef enum LedAlarmDisp_INX_ {

Led_cut=0,         
Led_drl,         
Led_ebd,          
Led_ebpw,   
Led_eco,         
Led_epb,         
Led_eps,         
Led_front_fog,   
Led_g,           
};

ImgInfo_st info_header1[] = {
	{a1_240x320_raw,    0, 0, 0},
    {b_num_16x20_raw,   0, 0, 0},
	{c1_ready_80x32_raw,  0, 0, 0},
    {c2_warn_28x28_raw,   0, 0, 0},
    {c3_seat_24x24_raw,   0, 0, 0},
    //{c6_seat_24x24_raw,   0, 0, 0},
    {SOC_d1_6_160x160_raw,  0, 0, 0},
    {Power_e_200x200_raw,   0, 0, 0},
    // {power_c7_160x160_raw,   0, 0, 0},
    // {ready_80x32_raw,   0, 0, 0},
    // {warn_28x24_raw,    0,0,0 },
	// {seat_20x24_raw,    0,0,0 },
};

typedef enum EDISP_INX_ {
		EDISP_INX_A1=0,	
		EDISP_INX_BNum16x20, 
        EDISP_INX_READY80X32,
		EDISP_INX_Warn28x28,
        EDISP_INX_Seat24x24,
        EDISP_INX_SOC160X160,
        EDISP_INX_Power200X200,
		EDISP_HDL_MAX		
}EDISPINX_E;
		
bmpHDR_st bmp_header1[] = 
{
	{COMPRESSED_RGBA_ASTC_4x4_KHR,240,320,(FTU32)&info_header1[EDISP_INX_A1]},
    {COMPRESSED_RGBA_ASTC_4x4_KHR,16,20,(FTU32)&info_header1[EDISP_INX_BNum16x20]},
	{COMPRESSED_RGBA_ASTC_4x4_KHR,80,32,(FTU32)&info_header1[EDISP_INX_READY80X32]},
    {COMPRESSED_RGBA_ASTC_4x4_KHR,28,28,(FTU32)&info_header1[EDISP_INX_Warn28x28]},
    {COMPRESSED_RGBA_ASTC_4x4_KHR,24,24,(FTU32)&info_header1[EDISP_INX_Seat24x24]},
    //{COMPRESSED_RGBA_ASTC_4x4_KHR,28,28,(FTU32)&info_header1[EDISP_INX_Seat24x24]},
    {COMPRESSED_RGBA_ASTC_4x4_KHR,160,160,(FTU32)&info_header1[EDISP_INX_SOC160X160]},
    {COMPRESSED_RGBA_ASTC_4x4_KHR,200,200,(FTU32)&info_header1[EDISP_INX_Power200X200]},
};


extern appRet_en appBmpToRamG(FTU32 bmpHdl, FTU32 ramgAddr, bmpHDR_st *pbmpHD, FTU32 nums);
extern FTU32 appFileToRamG (FTC8 *path, FTU32 inAddr, FTU8 chkExceed, FTU8 *outAddr, FTU32 outLen);

unsigned char RamgRet = 0;

unsigned char title1[] = 
{
	//{20320,22909,19990,30028,0}//
	0xE4,0xBD,0xA0,0xE5,0xA5,0xBD,'s','b',0//
	//0xE5,0xA5,0xBD,0x00
	//0xE4,0xBD,0xA0,0x00
	//"sdfghaweg"
};
static FT_Gpu_Fonts_t stFB1;
unsigned char FontRet = 0;

unsigned long UTF8Code = 0;
unsigned int Unicode = 20320;

unsigned long Unicode2UTF8(unsigned int Unicode)
{
	unsigned long UTF8Code = 0;
	unsigned char Temp = 0;

	Temp = Unicode & 0x3F;
	Temp |= 0x80;
	UTF8Code |= ((unsigned long)Temp<<16);
	Temp = (Unicode>>6) & 0x3F;
	Temp |= 0x80;
	UTF8Code |= ((unsigned int)Temp<<8);
	Temp = Unicode>>12;
	Temp |= 0xE0;
	UTF8Code |= Temp;

	return (UTF8Code);
}


void DispFont(void)
{
	#ifdef OLD
//	CoCmd_SETFONT2(FONT_HANDLE, FONT_ADD, 0);

	/* set the external font to each font index */
//	CoCmd_SETFONT(FONT_HANDLE, FONT_ADD, &stFB1);

//	HAL_CmdBufIn(COLOR_RGB(0,0,0xFF));
//	CoCmd_TEXT(100,100,FONT_HANDLE,0,"111");
	#endif

	CoCmd_SETFONT2(FONT_HANDLE, FONT_ADD, 0);

	/* show how to impliment customer font directly on screen */
	HAL_CmdBufIn(COLOR_RGB(0,0,0xFF));
	CoCmd_TEXT(100,100,FONT_HANDLE,0,(unsigned char*)title1);

	/* after finish UTF-8 text display, in some cases, 
	   add below command to avoid some corner cases */
	HAL_CmdBufIn(BITMAP_SWIZZLE(RED, GREEN, BLUE, ALPHA));


	
}
unsigned char PointerNum = 1;
unsigned int DispSum;
extern unsigned int RA_Press,FA_Press,tachodata,sml_inp;
void Disp_Ground(unsigned int data)
{
   
	HAL_CmdBufIn(BITMAP_HANDLE(EDISP_INX_A1));
	HAL_CmdBufIn(CELL(0));
	HAL_CmdBufIn(VERTEX2F(0,0));
}
void Disp_alarm(unsigned int data)
{
  /*
	#if 0
	HAL_CmdBufIn(BITMAP_HANDLE(2));
	HAL_CmdBufIn(CELL(0));
	HAL_CmdBufIn(VERTEX2F(100,100));
	//HAL_CmdBufIn(COLOR_A(0));		// 猫庐戮莽陆庐盲赂鈥姑┞澛⒚ぢ糕偓盲赂陋忙藴戮莽陇潞氓鈥郝久р�扳�∶?拧鈥灻┾偓聫忙藴沤氓潞娄
	#else
	unsigned char yydata;
	if(data>128)
	{
		DispSum=(256-data)<<1;
	}
	else if(data==128)
	{
		DispSum=255;
	}
	else
	{
		DispSum=data<<1;
	}
	HAL_CmdBufIn(COLOR_A(DispSum)); //猫庐戮莽陆庐茅垄艙猫鈥奥裁┾偓聫忙藴沤氓潞娄0氓鈥β?茅鈧?聫茂录艗255盲赂聧茅鈧???
	
	
	//HAL_CmdBufIn(BLEND_FUNC(SRC_ALPHA, ONE_MINUS_SRC_ALPHA));  //Specify pixel arithmetic
	//HAL_CmdBufIn(COLOR_MASK(0, 0, 0, 1));
	
	HAL_CmdBufIn(VERTEX2II(280,350,EDISP_INX_p_AlarmLed_32x32,0));	// 氓掳鈥爃andle氓聫路盲赂潞2莽拧鈥灻モ�郝久р�扳�∶λ溌久?陇潞氓艙??100,100)莽拧鈥灻ぢ铰嵜?陆??芒鈧?艙盲赂艙氓聧鈥斆⑩偓聺
	HAL_CmdBufIn(VERTEX2II(360,350,EDISP_INX_p_AlarmLed_32x32,1));
	//HAL_CmdBufIn(VERTEX2II(400,350,EDISP_INX_p_AlarmLed_32x32,Led_ebpw));
	//HAL_CmdBufIn(VERTEX2II(440,350,EDISP_INX_p_AlarmLed_32x32,Led_eco));
	//HAL_CmdBufIn(VERTEX2II(480,350,EDISP_INX_p_AlarmLed_32x32,Led_epb));

	HAL_CmdBufIn(COLOR_A(DispSum)); //猫庐戮莽陆庐茅垄艙猫鈥奥裁┾偓聫忙藴沤氓潞娄0氓鈥β?茅鈧?聫茂录艗255盲赂聧茅鈧???
	HAL_CmdBufIn(VERTEX2II(360,300,EDISP_INX_p_AlarmLed_32x32,2));
	//HAL_CmdBufIn(VERTEX2II(400,300,EDISP_INX_p_AlarmLed_32x32,Led_front_fog));
	//HAL_CmdBufIn(VERTEX2II(440,300,EDISP_INX_p_AlarmLed_32x32,Led_g));
	
	
	
	HAL_CmdBufIn(COLOR_A(255)); //猫庐戮莽陆庐茅垄艙猫鈥奥裁ぢ嘎嵜┾偓聫
	
	#endif
	*/

}



#define ECAR_PRECISE_CIRCLE 4UL
#define NEEDLE_SPD_R        (160)
#define NEEDLE_SPD_CENTER_X (12)
#define NEEDLE_SPD_CENTER_Y (220)
#define NEEDLE_SPD_OFFSET   (bmp_header1[EDISP_INX_point_24x80_raw].high)


void Disp_Odo(void)
{
  
	unsigned char tempchar,i;
    
    // HAL_CmdBufIn(BITMAP_HANDLE(EDISP_INX_BNum12x20));
    // HAL_CmdBufIn(CELL(6));
    // HAL_CmdBufIn(VERTEX2F((110*EVE_PIXEL_UNIT,292*EVE_PIXEL_UNIT));
    //HAL_CmdBufIn(VERTEX2II(110,292,EDISP_INX_BNum12x20,0));
    for(i=0;i<6;i++)
    {
	    //tempchar=ramdown[i];
        tempchar = 6;
        HAL_CmdBufIn(BITMAP_HANDLE(EDISP_INX_BNum16x20));
        HAL_CmdBufIn(PALETTE_SOURCE(((ImgInfoPal_st *)(bmp_header1[EDISP_INX_BNum16x20].info))->addr_lut));
        HAL_CmdBufIn(CELL(tempchar));
        HAL_CmdBufIn(VERTEX2F((106+i*12)*EVE_PIXEL_UNIT,292*EVE_PIXEL_UNIT));
    }  
	
}

void Disp_Trip(void)
{
  
	unsigned char tempchar;
	tempchar=ramup_a[0];
	//HAL_CmdBufIn(VERTEX2II(60,452,EDISP_INX_Sum16x16,tempchar));
	tempchar=ramup_a[1];
	//HAL_CmdBufIn(VERTEX2II(36,452,EDISP_INX_Sum16x16,tempchar));
	tempchar=ramup_a[2];
//	HAL_CmdBufIn(VERTEX2II(20,452,EDISP_INX_Sum16x16,tempchar));
    tempchar=ramup_a[3];
//	HAL_CmdBufIn(VERTEX2II(4,452,EDISP_INX_Sum16x16,tempchar));
   
}
void Disp_SpeedValue(unsigned int data)
{
	unsigned char tempchar;
	#if 1
	data*=7; //角度换数值
	data/=36;
	
	if(data>=100)	//data=99;
	{
		tempchar=data%10;data/=10;
		//HAL_CmdBufIn(VERTEX2II(424,244,EDISP_INX_Sum64x64,tempchar));
		tempchar=data%10;data/=10;
		//HAL_CmdBufIn(VERTEX2II(376,244,EDISP_INX_Sum64x64,tempchar));
		tempchar=data%10;
		//HAL_CmdBufIn(VERTEX2II(328,244,EDISP_INX_Sum64x64,tempchar));
	}
	else if(data>=10)
	{
		tempchar=data%10;
		//HAL_CmdBufIn(VERTEX2II(400,244,EDISP_INX_Sum64x64,tempchar));
		tempchar=data/10;
		//HAL_CmdBufIn(VERTEX2II(352,244,EDISP_INX_Sum64x64,tempchar));

	}
	else
	{
		
		//HAL_CmdBufIn(VERTEX2II(376,244,EDISP_INX_Sum64x64,data));

	}
		
     
   
	#endif


}
extern unsigned int yytest,second_1s;
unsigned int tachodatayy,RA_Pressyy,FA_Pressyy,speedyy;

void DispTest_Init(void)
{
	
	
//	FontRet = appFileToRamG(DISP_FONT_GLYPH,FONT_ADD,FONT_HANDLE,(FTU8 *)&stFB1,sizeof(FT_Gpu_Fonts_t));
//	appEVEFLHSetFull();
//	appEVEFLHToEVE(appEVEFLHAddr(DISP_XFONT), FONT_ADD, appEVEFLHLen(DISP_XFONT)); 
}

extern unsigned char dbg_str_buf[50];

#define start00_800x480_raw_ADD 	6561920
#define Start_BOOT_SLEN				384000		
/*开机动画*/
FTU8 Start_boot_frame(FTU32 *pframe, FTU32 max)
{
    if (*pframe >= max-1) 
	{
        return 1;
    } 
	else 
	{
        //*pframe = *pframe + 1;
    }
	
    info_StartLog->addr = start00_800x480_raw_ADD + *pframe * Start_BOOT_SLEN;
    /* keep pumpping the data into the GRAM */
    
		
	appEVEFLHToEVE(info_StartLog->addr, RAM_G, Start_BOOT_SLEN);
    
    return 0;
}	
 FTU8 StartLogFirst = 1;

FTVOID Start_Log_Disp(FTU32 para)
{
		#if 1
		//static FTU32 c = 1;
		
		if (StartLogFirst) 
		{
			if(APP_OK != appBmpToRamG(0, RAM_G,bmp_StartLog, 1)){
				//DBGPRINT;
				return;
			}
	
			HAL_CmdBufIn(CMD_DLSTART);
			HAL_CmdBufIn(CLEAR_COLOR_RGB(255, 255, 255));
			HAL_CmdBufIn(CLEAR(1, 1, 1));
	
			HAL_CmdBufIn(BEGIN(BITMAPS));
			HAL_CmdBufIn(BITMAP_HANDLE(0));
			HAL_CmdBufIn(CELL(0));
	
			/* display one frame */
			HAL_CmdBufIn(VERTEX2F(0,0));
	
	
			HAL_CmdBufIn(END());
			HAL_CmdBufIn(DISPLAY());
			HAL_CmdBufIn(CMD_SWAP);
	
			HAL_BufToReg(RAM_CMD, 0);
	
			StartLogFirst = 0; 
			//c = 1;//盲禄沤莽卢卢盲赂鈧?氓鹿鈥γモ�郝久ヂ尖偓氓搂鈥姑︹�櫬?忙鈥澛?
		}
		else 
		{
			/* change the frame index to make it 'animation' */
			//if (Start_boot_frame(&c, 20)) 
			if (Start_boot_frame(&para, 20)) 
			{
				//appClnScrn(0,0,0);
				/* boot process finished, go next */
				appGP.appIndex = 1;
			}
			else 
			{
				/* stay in boot process */
				appGP.appIndex = 0;
			}
			/* 
			 the delay has two function
			 1. for the delay of each frame (you may use other way to do it)
			 2. for the delay of appClnScrn (occasionally blurred screen be shown without delay)
			 */
			//FTDELAY(100);
		}
		#endif
}

//显示LED灯
FTVOID Dis_LED()
{
    HAL_CmdBufIn(BITMAP_HANDLE(EDISP_INX_Warn28x28)); //绝缘故障灯
    HAL_CmdBufIn(CELL(0));   
	HAL_CmdBufIn(VERTEX2F(176*EVE_PIXEL_UNIT,48*EVE_PIXEL_UNIT));  //起始位置    


    HAL_CmdBufIn(BITMAP_HANDLE(EDISP_INX_Seat24x24));
    HAL_CmdBufIn(CELL(0));    
	//HAL_CmdBufIn(BITMAP_SIZE(BILINEAR,BORDER,BORDER,28,28)); //width height
	HAL_CmdBufIn(VERTEX2F(15*EVE_PIXEL_UNIT,42*EVE_PIXEL_UNIT));  //起始位置 

    HAL_CmdBufIn(CELL(1));    
	//HAL_CmdBufIn(BITMAP_SIZE(BILINEAR,BORDER,BORDER,28,28)); //width height
	HAL_CmdBufIn(VERTEX2F(50*EVE_PIXEL_UNIT,42*EVE_PIXEL_UNIT));  //起始位置 


    HAL_CmdBufIn(CELL(2));    
	HAL_CmdBufIn(VERTEX2F(15*EVE_PIXEL_UNIT,64*EVE_PIXEL_UNIT));  //起始位置 

    HAL_CmdBufIn(CELL(3));    
	HAL_CmdBufIn(VERTEX2F(33*EVE_PIXEL_UNIT,64*EVE_PIXEL_UNIT));  //起始位置 

    HAL_CmdBufIn(CELL(4));    
	HAL_CmdBufIn(VERTEX2F(50*EVE_PIXEL_UNIT,64*EVE_PIXEL_UNIT));  //起始位置 

    HAL_CmdBufIn(BITMAP_HANDLE(EDISP_INX_READY80X32));
    HAL_CmdBufIn(CELL(0));    
	HAL_CmdBufIn(BITMAP_SIZE(BILINEAR,BORDER,BORDER,80,32)); //width height
	HAL_CmdBufIn(VERTEX2F(84*EVE_PIXEL_UNIT,40*EVE_PIXEL_UNIT));  //起始位置 

}

//SOC圈显示

FTVOID Dis_SOC(FTU16 data)
{
    #if 1


    HAL_CmdBufIn(BITMAP_HANDLE(EDISP_INX_SOC160X160)); //底图半绿半灰
    HAL_CmdBufIn(CELL(5));
    HAL_CmdBufIn(SAVE_CONTEXT());
	HAL_CmdBufIn(BITMAP_SIZE(BILINEAR,BORDER,BORDER,160,160)); //width height
	HAL_CmdBufIn(VERTEX2F(46*EVE_PIXEL_UNIT,90*EVE_PIXEL_UNIT));  //起始位置    
    HAL_CmdBufIn(RESTORE_CONTEXT());

    if(data<=50) //黑色层
    {
        HAL_CmdBufIn(BITMAP_HANDLE(EDISP_INX_SOC160X160));
        HAL_CmdBufIn(CELL(6));
        CoCmd_LOADIDENTITY;	//设置身份
        CoCmd_ROTATEAROUND(80 ,80, (data*36)*EVE_TRANSFORM_MAX/3600,EVE_TRANSFORM_MAX);  //旋转中心坐标 旋转角度
        CoCmd_SETMATRIX; //把当前图像转为位图显示
    }
    else
    {
        HAL_CmdBufIn(BITMAP_HANDLE(EDISP_INX_SOC160X160));
        HAL_CmdBufIn(CELL(6));
        CoCmd_LOADIDENTITY;	//设置身份
        CoCmd_ROTATEAROUND(80 ,80, (data*36-1800)*EVE_TRANSFORM_MAX/3600,EVE_TRANSFORM_MAX);  //旋转中心坐标 旋转角度
        CoCmd_SETMATRIX; //把当前图像转为位图显示
    }
    HAL_CmdBufIn(SAVE_CONTEXT());
	HAL_CmdBufIn(BITMAP_SIZE(BILINEAR,BORDER,BORDER,160,160)); //width height
	HAL_CmdBufIn(VERTEX2F(46*EVE_PIXEL_UNIT,90*EVE_PIXEL_UNIT));  //起始位置    
    HAL_CmdBufIn(RESTORE_CONTEXT());

    if(data<=50) //灰色/绿色层
    {
        HAL_CmdBufIn(BITMAP_HANDLE(EDISP_INX_SOC160X160));
        HAL_CmdBufIn(CELL(3));
        CoCmd_LOADIDENTITY;	//设置身份
        CoCmd_ROTATEAROUND(80 ,80, data*36*EVE_TRANSFORM_MAX/3600,EVE_TRANSFORM_MAX);  //旋转中心坐标 旋转角度
        CoCmd_SETMATRIX; //把当前图像转为位图显示
    }
    else
    {
        HAL_CmdBufIn(BITMAP_HANDLE(EDISP_INX_SOC160X160));
        HAL_CmdBufIn(CELL(4));
        CoCmd_LOADIDENTITY;	//设置身份
        CoCmd_ROTATEAROUND(80 ,80, (data*36-1800)*EVE_TRANSFORM_MAX/3600,EVE_TRANSFORM_MAX);  //旋转中心坐标 旋转角度
        CoCmd_SETMATRIX; //把当前图像转为位图显示
    }

    //Push the current graphics context on the context stack
    HAL_CmdBufIn(SAVE_CONTEXT());
	HAL_CmdBufIn(BITMAP_SIZE(BILINEAR,BORDER,BORDER,160,160)); //width height
	HAL_CmdBufIn(VERTEX2F(46*EVE_PIXEL_UNIT,90*EVE_PIXEL_UNIT));  //起始位置    
    HAL_CmdBufIn(RESTORE_CONTEXT());
    #endif 
}

//功率圈显示
FTVOID Dis_Power(FT16 data)
{
    /**************************0-100(data+1 转2°)*********************************/
    HAL_CmdBufIn(BITMAP_HANDLE(EDISP_INX_Power200X200));  //白色进度条
    HAL_CmdBufIn(CELL(0));
	HAL_CmdBufIn(BITMAP_SIZE(BILINEAR,BORDER,BORDER,200,200)); //width height
	HAL_CmdBufIn(VERTEX2F(24*EVE_PIXEL_UNIT,68*EVE_PIXEL_UNIT));  //起始位置    

    if(data>0)
    {
        if(data<=20)
        {
            HAL_CmdBufIn(CELL(1)); //黑色遮盖条0-20
            CoCmd_LOADIDENTITY;	
            CoCmd_ROTATEAROUND(100 ,100, (360-(data*2))*EVE_TRANSFORM_MAX/360,EVE_TRANSFORM_MAX);  //旋转中心坐标 旋转角度
            CoCmd_SETMATRIX; 
            HAL_CmdBufIn(BITMAP_SIZE(BILINEAR,BORDER,BORDER,200,200)); //width height
            HAL_CmdBufIn(VERTEX2F(24*EVE_PIXEL_UNIT,68*EVE_PIXEL_UNIT));  //起始位置
        }  

        if(data<=60)
        {
            HAL_CmdBufIn(CELL(2)); //黑色遮盖条21-60
            CoCmd_LOADIDENTITY;	
            if(data>20&&data<=60)
            {
                CoCmd_ROTATEAROUND(100 ,100, (360-(data*2-40))*EVE_TRANSFORM_MAX/360,EVE_TRANSFORM_MAX);  //旋转中心坐标 旋转角度
            }
            else
            {
                CoCmd_ROTATEAROUND(100 ,100, 0*EVE_TRANSFORM_MAX/360,EVE_TRANSFORM_MAX);  //旋转中心坐标 旋转角度
            }
            CoCmd_SETMATRIX; 
            HAL_CmdBufIn(BITMAP_SIZE(BILINEAR,BORDER,BORDER,200,200)); //width height
            HAL_CmdBufIn(VERTEX2F(24*EVE_PIXEL_UNIT,68*EVE_PIXEL_UNIT));  //起始位置 
        } 
    
        if(data<=100)
        {
            HAL_CmdBufIn(CELL(3)); //黑色遮盖条61-100
            CoCmd_LOADIDENTITY;	
            if(data>60&&data<=100)
            {
                CoCmd_ROTATEAROUND(100 ,100, (360-(data*2-120))*EVE_TRANSFORM_MAX/360,EVE_TRANSFORM_MAX);  //旋转中心坐标 旋转角度
            }
            else
            {
                CoCmd_ROTATEAROUND(100 ,100, 0*EVE_TRANSFORM_MAX/360,EVE_TRANSFORM_MAX);  //旋转中心坐标 旋转角度
            }
            CoCmd_SETMATRIX;
            HAL_CmdBufIn(BITMAP_SIZE(BILINEAR,BORDER,BORDER,200,200)); //width height
            HAL_CmdBufIn(VERTEX2F(24*EVE_PIXEL_UNIT,68*EVE_PIXEL_UNIT));  //起始位置  
        }
    }
    else
    {
        /**************************-100-0*********************************/
        HAL_CmdBufIn(CELL(1)); //黑色遮盖条0-20
        CoCmd_LOADIDENTITY;	
        CoCmd_ROTATEAROUND(100 ,100, 0,EVE_TRANSFORM_MAX);  //旋转中心坐标 旋转角度
        CoCmd_SETMATRIX;
        HAL_CmdBufIn(BITMAP_SIZE(BILINEAR,BORDER,BORDER,200,200)); //width height
        HAL_CmdBufIn(VERTEX2F(24*EVE_PIXEL_UNIT,68*EVE_PIXEL_UNIT));  //起始位置

        HAL_CmdBufIn(CELL(2)); //黑色遮盖条21-60
        HAL_CmdBufIn(BITMAP_SIZE(BILINEAR,BORDER,BORDER,200,200)); //width height
        HAL_CmdBufIn(VERTEX2F(24*EVE_PIXEL_UNIT,68*EVE_PIXEL_UNIT));  //起始位置

        HAL_CmdBufIn(CELL(3)); //黑色遮盖条61-100
        HAL_CmdBufIn(BITMAP_SIZE(BILINEAR,BORDER,BORDER,200,200)); //width height
        HAL_CmdBufIn(VERTEX2F(24*EVE_PIXEL_UNIT,68*EVE_PIXEL_UNIT));  //起始位置

        HAL_CmdBufIn(CELL(4)); //绿色进度条
        HAL_CmdBufIn(BITMAP_SIZE(BILINEAR,BORDER,BORDER,200,200)); //width height
        HAL_CmdBufIn(VERTEX2F(24*EVE_PIXEL_UNIT,68*EVE_PIXEL_UNIT));  //起始位置

        HAL_CmdBufIn(CELL(5)); //黑色遮盖条
        CoCmd_LOADIDENTITY;	
        CoCmd_ROTATEAROUND(100 ,100,((-data)/4)*EVE_TRANSFORM_MAX/360,EVE_TRANSFORM_MAX);  //每增加4向前转1度
        CoCmd_SETMATRIX; 
        HAL_CmdBufIn(SAVE_CONTEXT());
        HAL_CmdBufIn(BITMAP_SIZE(BILINEAR,BORDER,BORDER,200,200)); //width height
        HAL_CmdBufIn(VERTEX2F(24*EVE_PIXEL_UNIT,68*EVE_PIXEL_UNIT));  //起始位置 
        HAL_CmdBufIn(RESTORE_CONTEXT());

    }
    


    // HAL_CmdBufIn(CELL(4)); //绿色进度条
	// HAL_CmdBufIn(BITMAP_SIZE(BILINEAR,BORDER,BORDER,200,200)); //width height
	// HAL_CmdBufIn(VERTEX2F(24*EVE_PIXEL_UNIT,68*EVE_PIXEL_UNIT));  //起始位置   

    // HAL_CmdBufIn(CELL(5)); //黑色遮盖条
    // CoCmd_LOADIDENTITY;	
    // CoCmd_ROTATEAROUND(100 ,100,10*EVE_TRANSFORM_MAX/360,EVE_TRANSFORM_MAX);  //旋转中心坐标 旋转角度
    // CoCmd_SETMATRIX; //把当前图像转为位图显示
    // HAL_CmdBufIn(SAVE_CONTEXT());
	// HAL_CmdBufIn(BITMAP_SIZE(BILINEAR,BORDER,BORDER,200,200)); //width height
	// HAL_CmdBufIn(VERTEX2F(25*EVE_PIXEL_UNIT,69*EVE_PIXEL_UNIT));  //起始位置 
    // HAL_CmdBufIn(RESTORE_CONTEXT());

    /**************************外数值框*********************************/
    HAL_CmdBufIn(BITMAP_HANDLE(EDISP_INX_Power200X200));  //数值外框
    HAL_CmdBufIn(CELL(6));
    CoCmd_LOADIDENTITY;	
    CoCmd_ROTATEAROUND(100 ,100, 0*EVE_TRANSFORM_MAX/360,EVE_TRANSFORM_MAX);  //这里设置为0度 不然会受上面的影响
    CoCmd_SETMATRIX; //把当前图像转为位图显示
    HAL_CmdBufIn(SAVE_CONTEXT());
	HAL_CmdBufIn(BITMAP_SIZE(BILINEAR,BORDER,BORDER,200,200)); //width height
	HAL_CmdBufIn(VERTEX2F(18*EVE_PIXEL_UNIT,77*EVE_PIXEL_UNIT));  //起始位置    
    HAL_CmdBufIn(RESTORE_CONTEXT());
}
//温度显示
FTVOID Dis_Temp(FT16 data)
{
    unsigned short tempchar=0;
    unsigned char i;
    for(i=0;i<2;i++)
    {
	    tempchar=data%10;
        HAL_CmdBufIn(BITMAP_HANDLE(EDISP_INX_BNum16x20));
        HAL_CmdBufIn(PALETTE_SOURCE(((ImgInfoPal_st *)(bmp_header1[EDISP_INX_BNum16x20].info))->addr_lut));
        HAL_CmdBufIn(CELL(tempchar));
        HAL_CmdBufIn(VERTEX2F((160-i*12)*EVE_PIXEL_UNIT,8*EVE_PIXEL_UNIT));
        data /=10;
    }    
}

//时间显示
FTVOID Dis_Time(FTU16 hour,FTU16 min)
{
    unsigned short tempchar=0;
    unsigned char i;
    for(i=0;i<2;i++)
    {
	    tempchar=hour%10;
        HAL_CmdBufIn(BITMAP_HANDLE(EDISP_INX_BNum16x20));
        HAL_CmdBufIn(PALETTE_SOURCE(((ImgInfoPal_st *)(bmp_header1[EDISP_INX_BNum16x20].info))->addr_lut));
        HAL_CmdBufIn(CELL(tempchar));
        HAL_CmdBufIn(VERTEX2F((44-i*12)*EVE_PIXEL_UNIT,8*EVE_PIXEL_UNIT));
        hour /=10;
    }    
    for(i=0;i<2;i++)
    {
	    tempchar=min%10;
        HAL_CmdBufIn(BITMAP_HANDLE(EDISP_INX_BNum16x20));
        HAL_CmdBufIn(PALETTE_SOURCE(((ImgInfoPal_st *)(bmp_header1[EDISP_INX_BNum16x20].info))->addr_lut));
        HAL_CmdBufIn(CELL(tempchar));
        HAL_CmdBufIn(VERTEX2F((78-i*12)*EVE_PIXEL_UNIT,8*EVE_PIXEL_UNIT));
        min /=10;
    }    
}
short ss=0,cnt_s=0,s_falg=0;
void DispTest(unsigned int data,unsigned char stu)
{
	static unsigned char flag=1,stu_bak=255;
    static unsigned int second_500sTset=0;
    unsigned int tmp = 0;
    static unsigned int tachodata_bak=0,RA_Press_bak=0,FA_Press_bak=0,speed_bak=0;
    unsigned long int templong;
	#if 1
	
//if(stu!=stu_bak)
//{
//	stu_bak=stu;
//	if(stu==0)
//	{
//		appGP.appIndex=0;
//		StartLogFirst=1;
//		flag=1;
//	}
//}
    cnt_s++;
    if(cnt_s>=10)
    {
        cnt_s=0;
        ss+=1;
        if(ss>=100)
        {
            ss=0;
            if(s_falg)
            {
                s_falg=0;
            }
            else
            {
                s_falg = 1;
            }
        }
    }
	
	if(appGP.appIndex==0)
	{
		//Start_Log_Disp(stu); //LOG展示
		appGP.appIndex=1;
		flag=1;
	}
	else
	{
        if(flag==1)
        {	//clear_screen();
            RamgRet = appBmpToRamG(0, RAM_G, &bmp_header1[0], EDISP_HDL_MAX);  // 忙鈥孤访?麓??-6
            flag=0;
            
        }
        
        // 1-2ms
        HAL_CmdBufIn(CMD_DLSTART);				// start a new display list
        HAL_CmdBufIn(CLEAR_COLOR_RGB(0,0,0));	// set clear color
        HAL_CmdBufIn(CLEAR(1,1,1));				// clear screen 
        HAL_CmdBufIn(BEGIN(BITMAPS));
        
        /*****************disp***************************************/
        //DispBitMap(data); //all disp set 
        Disp_Ground(data); // 1ms//卤鲁戮掳碌脳脥录
        
        Dis_LED();
        Dis_Temp(ss);
        Dis_Time(11,11);
        Disp_Odo();
        if(s_falg)
            Dis_Power(ss);
        else
            Dis_Power(-ss);
        
       // Dis_SOC(yg_test);
       Dis_SOC(ss);
 
        
        yytest++;
        if(yytest>960)
            yytest=0;
        
    
        //Disp_needle_speed(Smeter[Mc_Speed].m_new);
        //else
        // Disp_needle_bar1(Smeter[Mc_Press1].m_new);

        // Disp_needle_bar2(Smeter[Mc_Press2].m_new);
        
        //Disp_SpeedRotate(yytest);
        //Disp_SpeedRotate1(yytest/2);
        /****************************************************************/
            
            HAL_CmdBufIn(END());				// 莽禄鈥溍β澟该?禄藴氓鈥郝?
            HAL_CmdBufIn(DISPLAY());			// 忙藴戮莽陇潞
            HAL_CmdBufIn(CMD_SWAP);
            HAL_BufToReg(RAM_CMD,0);// 6-7ms
            
            //second_500sTset=second_1s;
            //yytest = second_1s-second_500sTset;


	}
	
	#else
	if(stu<20)
	{
				//clear_screen();
				
				
				if(stu!=stu_bak)
				{
						stu_bak=stu;
						if((stu&0x01)==0x00)
						{
							RamgRet = appBmpToRamG(0, RAM_G, &bmp_StartLog[stu], 2);
						}
						flag=1;
				}
	}
	else
	
	{			stu_bak=255;
				if(flag==1)
				{	//clear_screen();
					RamgRet = appBmpToRamG(0, RAM_G, bmp_header1, 6);  // 忙鈥孤访?麓??-6
					flag=0;
				}
	}
	HAL_CmdBufIn(CMD_DLSTART);				// start a new display list
	HAL_CmdBufIn(CLEAR_COLOR_RGB(0,0,0));	// set clear color
	HAL_CmdBufIn(CLEAR(1,1,1));				// clear screen 
	HAL_CmdBufIn(BEGIN(BITMAPS));
	if(stu<20)
	{
		HAL_CmdBufIn(BITMAP_HANDLE(stu&0x01));
		HAL_CmdBufIn(CELL(0));
		HAL_CmdBufIn(VERTEX2F(0,0));
	}
	else
	{
		DispBitMap(data); //
	}
//	DispFont();
//	UTF8Code = Unicode2UTF8(Unicode);


//	CoCmd_SETFONT2(FONT_HANDLE, FONT_ADD, 0);

//	/* show how to impliment customer font directly on screen */
//	HAL_CmdBufIn(COLOR_RGB(0,0,0xFF));
//	CoCmd_TEXT(100,100,FONT_HANDLE,0,(unsigned char*)title1);//0xE4,0xBD,0xA0,0x00

//	/* after finish UTF-8 text display, in some cases, 
//	   add below command to avoid some corner cases */
//	HAL_CmdBufIn(BITMAP_SWIZZLE(RED, GREEN, BLUE, ALPHA));

    HAL_CmdBufIn(END());				// 莽禄鈥溍β澟该?禄藴氓鈥郝?
    HAL_CmdBufIn(DISPLAY());			// 忙藴戮莽陇潞
	HAL_CmdBufIn(CMD_SWAP);

    HAL_BufToReg(RAM_CMD,0);
	#endif
}

/************************************
	UI_ecar.h
************************************/
/* 
    Sample code to show how to demostrate a E-Car dashboard
    Author: Hawk
	Email : hawk.gao@ftdichip.com
	Date  : 2019/Jan
*/
#if 0

#if defined(VC_EMULATOR)
#error "copy res/ecar/eveflh.bin to res/eveflh, then comment this line"
#elif defined(VC_MPSSE) || defined(VC_FT4222)
#error "program res/ecar/eveflh.bin to eve-connected-flash, then comment this line"
#endif


#include "EVE_Gpu.h"
#include "EVE_APP.h"
#include "EVE_HAL.h"



#define ECAR_BOOT        "EVEFLH@4096:122880"
#define ECAR_BG          "EVEFLH@9220096 : 384000"
#define ECAR_NEEDLE_0    "EVEFLH@9604096 : 832"
#define ECAR_NEEDLE_1    "EVEFLH@9604928 : 960"
#define ECAR_NUM_C       "EVEFLH@9605888 : 3584"
#define ECAR_NUM_C_      "EVEFLH@9609472 : 320"
#define ECAR_NUM_D       "EVEFLH@9609792 : 7104"
#define ECAR_NUM_D_      "EVEFLH@9616896 : 512"
#define ECAR_OVERSPEED_B "EVEFLH@9617408 : 44736"
#define ECAR_SPEED_B     "EVEFLH@9662144 : 12096"
#define ECAR_SPEED_B_    "EVEFLH@9674240 : 512"
#define ECAR_SPEED_N     "EVEFLH@9674752 : 7232"
#define ECAR_SPEED_N_    "EVEFLH@9681984 : 64"
#define ECAR_WARNING     "EVEFLH@9682048 : 4800"
#define ECAR_XPATCH      "EVEFLH@9686848 : 960"


/* 
 it just for easy debug/implimentable of your evaluation
 once found the proper value in your system 
 recommanded to use calculated fixed number
 less multiple/division, better performance
 */
#define ECAR_PRECISE_SPEED  2ul
#define ECAR_PRECISE_PWR    2ul
#define ECAR_PRECISE_TRPM   10ul
/* 
 the division of 1 degree
 you MUST have the correct corresponding "sintbl"
*/
#define ECAR_PRECISE_CIRCLE 4UL

#define ECAR_WIDTH          800
#define ECAR_HIGH           480

#define ECAR_BOOT_ADDR      4096
#define ECAR_BOOT_SLEN      122880
#define ECAR_BOOT_FMAX      75

#define ECAR_RAM_BOOT       RAM_G
#define ECAR_RAM_DASHBOARD  RAM_G

#define ECAR_NEEDLE_0_W     16
#define ECAR_NEEDLE_0_H     52
#define ECAR_NEEDLE_1_W     12
#define ECAR_NEEDLE_1_H     76

#define ECAR_OVERSPEED_W    228
#define ECAR_OVERSPEED_H    196
#define ECAR_OVERSPEED_SPD  (120*ECAR_PRECISE_SPEED)

#define ECAR_NUM_C_W        14
#define ECAR_NUM_C_H        23//23*11
#define ECAR_NUM_D_W        21
#define ECAR_NUM_D_H        26//26*13

#define ECAR_SPEED_B_W      48
#define ECAR_SPEED_B_H      28//28*9
#define ECAR_SPEED_N_W      40
#define ECAR_SPEED_N_H      20//20*9

#define ECAR_WARNING_N_W    40
#define ECAR_WARNING_N_H    40//40*3

#define ECAR_XPATCH_W       40
#define ECAR_XPATCH_H       24

#define ECAR_MIN_SPEED      (0*ECAR_PRECISE_SPEED)
#define ECAR_MIN_PWR        (-25*ECAR_PRECISE_PWR)
#define ECAR_MIN_TRPM       (-10*ECAR_PRECISE_TRPM)
#define ECAR_MIN_TKM        0
#define ECAR_MIN_AKM        0
#define ECAR_MIN_BKM        0
#define ECAR_MIN_VOT        0
#define ECAR_MIN_AMP        (-200)

#define ECAR_MAX_SPEED      (160*ECAR_PRECISE_SPEED)
#define ECAR_MAX_PWR        (125*ECAR_PRECISE_PWR)
#define ECAR_MAX_TRPM       (20*ECAR_PRECISE_TRPM)
#define ECAR_MAX_TKM        999999ul
#define ECAR_MAX_AKM        999999ul
#define ECAR_MAX_BKM        999999ul
#define ECAR_MAX_VOT        200ul
#define ECAR_MAX_AMP        200ul

#define ECAR_MARK_NUM       9

#define ECAR_WARNING_SPD    (80*ECAR_PRECISE_SPEED)

#define ECAR_AB_SPD         (80*ECAR_PRECISE_SPEED)

typedef enum ECAR_HDL_ { //bitmap handle
    ECAR_HDL_BOOT = 0,
    ECAR_HDL_BG   = 0,   //background
                         //in new screen, reuse handle 0
    ECAR_HDL_NEEDLE_0,   //speed needle
    ECAR_HDL_NEEDLE_1,   //power/trpm needle
    ECAR_HDL_NUM_C,      //number in the center (V/A) of dashboard
    ECAR_HDL_NUM_D,      //number in the down (A/B/Total trip) dashboard
    ECAR_HDL_OVERSPEED_B,//overspeed waning display in center
    ECAR_HDL_SPEED_B,    //speed number in big size
    ECAR_HDL_SPEED_N,    //speed number in normal size
    ECAR_HDL_WARNING,    //3 warning icon
    ECAR_HDL_XPATCH,     //cover the km/h mark when speed over 160km/h
    ECAR_HDL_MAX,
}ECAR_HDL_E;

ImgInfo_st info_header[] = {
    {ECAR_BOOT,0,0,0},
    {ECAR_BG,0,0,0},
    {ECAR_NEEDLE_0,0,0,0},
    {ECAR_NEEDLE_1,0,0,0},
    {ECAR_OVERSPEED_B,0,0,0},
    {ECAR_WARNING,0,0,0},
    {ECAR_XPATCH,0,0,0},
};
ImgInfoPal_st info_pal_header[] = {
    {ECAR_NUM_C,ECAR_NUM_C_,0,0,0,0,0},
    {ECAR_NUM_D,ECAR_NUM_D_,0,0,0,0,0},
    {ECAR_SPEED_B,ECAR_SPEED_B_,0,0,0,0,0},
    {ECAR_SPEED_N,ECAR_SPEED_N_,0,0,0,0,0},
};
bmpHDR_st bmp_header[] = {
    {COMPRESSED_RGBA_ASTC_10x5_KHR,ECAR_WIDTH,ECAR_HIGH,(FTU32)&info_header[0]},
    {COMPRESSED_RGBA_ASTC_4x4_KHR, ECAR_WIDTH,ECAR_HIGH,(FTU32)&info_header[1]},
    {COMPRESSED_RGBA_ASTC_4x4_KHR, ECAR_NEEDLE_0_W,ECAR_NEEDLE_0_H,(FTU32)&info_header[2]},
    {COMPRESSED_RGBA_ASTC_4x4_KHR, ECAR_NEEDLE_1_W,ECAR_NEEDLE_1_H,(FTU32)&info_header[3]},
    {PALETTED4444, ECAR_NUM_C_W,ECAR_NUM_C_H,(FTU32)&info_pal_header[0]},
    {PALETTED4444, ECAR_NUM_D_W,ECAR_NUM_D_H,(FTU32)&info_pal_header[1]},
    {COMPRESSED_RGBA_ASTC_4x4_KHR, ECAR_OVERSPEED_W,ECAR_OVERSPEED_H,(FTU32)&info_header[4]},
    {PALETTED4444, ECAR_SPEED_B_W,ECAR_SPEED_B_H,(FTU32)&info_pal_header[2]},
    {PALETTED4444, ECAR_SPEED_N_W,ECAR_SPEED_N_H,(FTU32)&info_pal_header[3]},
    {COMPRESSED_RGBA_ASTC_4x4_KHR, ECAR_WARNING_N_W,ECAR_WARNING_N_H,(FTU32)&info_header[5]},
    {COMPRESSED_RGBA_ASTC_4x4_KHR, ECAR_XPATCH_W,ECAR_XPATCH_H,(FTU32)&info_header[6]},
};
typedef enum ECAR_INX_ {
    ECAR_INX_BOOT = 0,
    ECAR_INX_BG,
    ECAR_INX_NEEDLE_0,
    ECAR_INX_NEEDLE_1,
    ECAR_INX_NUM_C,
    ECAR_INX_NUM_D,
    ECAR_INX_OVERSPEED_B,
    ECAR_INX_SPEED_B,
    ECAR_INX_SPEED_N,
    ECAR_INX_WARNING,
    ECAR_INX_XPATCH,
    ECAR_INX_MAX,
}ECAR_INX_E;
typedef struct spd_mark_ {
    FTU8 spd_n1_low;  //normal size range before big size range
    FTU8 spd_n1_high;
    FTU8 spd_b_low;   //big size range
    FTU8 spd_b_high;
    FTU8 spd_n2_low;  //normal size range after big size range
    FTU8 spd_n2_high;
    FTU16 spd_x;
    FTU16 spd_y;
} spd_mark_st;
/* instaed of using 0xFF, you may also use 
   ECAR_MAX_SPEED+1 for better understanding */
spd_mark_st spd_mark[ECAR_MARK_NUM] = {
    {0xFF,0xFF,0,18,0xFF,0xFF, 266, 339}, //0
    {0,8,9,38,39,40,           247, 254}, //20
    {15,29,30,59,60,65,        264, 167}, //40
    {30,49,50,80,81,85,        316, 116}, //60
    {55,70,71,110,111,113,     390,  91}, //80
    {78,99,100,124,125,130,    459, 112}, //100
    {99,119,120,141,142,144,   507, 172}, //120
    {119,132,133,159,0xFF,0xFF,528, 255}, //140
    {140,154,155,160,0xFF,0xFF,498, 335}, //160
};
/* 
 1. angle unit: 1/ECAR_PRECISE_CIRCLE degree
 2. the original sin data multiple 10000 (e.g. sin(1) = 0.0174)
    so the calulated result need to div 10000, in order to 
    make the calulation faster for MCU (bit shift faster than div)
    div the original sin data by 1.22 to come out a new sin table
    then the result only need to right shift 13 bits
    (2^13=8192, 10000/8192=1.22) 
 3. there is an easy way to generate the table by using EXCEL
    you may search it online, the way I'm using is
    by using this formular "ROUND(SIN(RADIANS(A1))/1.22*10000,0)"
    "A1" the cell which content the "angle" value
 4. in MCU, you may put this table in Flash instead of memory
    as long as your system has a fast accessing Flash mechanism
 */
FTU16 sintbl[] = 
{
0	,	36	,	72	,	107	,
143	,	179	,	215	,	250	,
286	,	322	,	358	,	393	,
429	,	465	,	500	,	536	,
572	,	607	,	643	,	679	,
714	,	750	,	786	,	821	,
857	,	892	,	928	,	963	,
999	,	1034	,	1070	,	1105	,
1141	,	1176	,	1212	,	1247	,
1282	,	1318	,	1353	,	1388	,
1423	,	1459	,	1494	,	1529	,
1564	,	1599	,	1634	,	1669	,
1704	,	1739	,	1774	,	1809	,
1844	,	1879	,	1913	,	1948	,
1983	,	2018	,	2052	,	2087	,
2121	,	2156	,	2190	,	2225	,
2259	,	2294	,	2328	,	2362	,
2396	,	2431	,	2465	,	2499	,
2533	,	2567	,	2601	,	2635	,
2669	,	2702	,	2736	,	2770	,
2803	,	2837	,	2871	,	2904	,
2937	,	2971	,	3004	,	3037	,
3071	,	3104	,	3137	,	3170	,
3203	,	3236	,	3268	,	3301	,
3334	,	3367	,	3399	,	3432	,
3464	,	3496	,	3529	,	3561	,
3593	,	3625	,	3657	,	3689	,
3721	,	3753	,	3785	,	3817	,
3848	,	3880	,	3911	,	3943	,
3974	,	4005	,	4036	,	4067	,
4098	,	4129	,	4160	,	4191	,
4222	,	4252	,	4283	,	4313	,
4344	,	4374	,	4404	,	4434	,
4464	,	4494	,	4524	,	4554	,
4584	,	4613	,	4643	,	4672	,
4701	,	4731	,	4760	,	4789	,
4818	,	4847	,	4876	,	4904	,
4933	,	4961	,	4990	,	5018	,
5046	,	5075	,	5103	,	5131	,
5158	,	5186	,	5214	,	5241	,
5269	,	5296	,	5323	,	5350	,
5378	,	5404	,	5431	,	5458	,
5485	,	5511	,	5538	,	5564	,
5590	,	5616	,	5642	,	5668	,
5694	,	5720	,	5745	,	5771	,
5796	,	5821	,	5846	,	5871	,
5896	,	5921	,	5946	,	5970	,
5995	,	6019	,	6043	,	6067	,
6091	,	6115	,	6139	,	6163	,
6186	,	6210	,	6233	,	6256	,
6279	,	6302	,	6325	,	6347	,
6370	,	6392	,	6415	,	6437	,
6459	,	6481	,	6503	,	6525	,
6546	,	6568	,	6589	,	6610	,
6631	,	6652	,	6673	,	6694	,
6714	,	6735	,	6755	,	6775	,
6795	,	6815	,	6835	,	6855	,
6874	,	6894	,	6913	,	6932	,
6951	,	6970	,	6989	,	7007	,
7026	,	7044	,	7063	,	7081	,
7099	,	7116	,	7134	,	7152	,
7169	,	7186	,	7203	,	7220	,
7237	,	7254	,	7271	,	7287	,
7303	,	7319	,	7336	,	7351	,
7367	,	7383	,	7398	,	7414	,
7429	,	7444	,	7459	,	7473	,
7488	,	7503	,	7517	,	7531	,
7545	,	7559	,	7573	,	7586	,
7600	,	7613	,	7626	,	7639	,
7652	,	7665	,	7678	,	7690	,
7702	,	7715	,	7727	,	7738	,
7750	,	7762	,	7773	,	7784	,
7796	,	7807	,	7817	,	7828	,
7839	,	7849	,	7859	,	7869	,
7879	,	7889	,	7899	,	7908	,
7917	,	7927	,	7936	,	7945	,
7953	,	7962	,	7970	,	7979	,
7987	,	7995	,	8002	,	8010	,
8018	,	8025	,	8032	,	8039	,
8046	,	8053	,	8059	,	8066	,
8072	,	8078	,	8084	,	8090	,
8096	,	8101	,	8107	,	8112	,
8117	,	8122	,	8127	,	8131	,
8136	,	8140	,	8144	,	8148	,
8152	,	8155	,	8159	,	8162	,
8166	,	8169	,	8171	,	8174	,
8177	,	8179	,	8181	,	8184	,
8185	,	8187	,	8189	,	8190	,
8192	,	8193	,	8194	,	8195	,
8195	,	8196	,	8196	,	8197	,
8197							
};
FT16 ecar_Qsin(FTU16 Angle)
{
    if (Angle >= 0 && Angle <= 90*ECAR_PRECISE_CIRCLE) {
        return sintbl[Angle];
    } else if (Angle > 90*ECAR_PRECISE_CIRCLE && Angle <= 180*ECAR_PRECISE_CIRCLE) {
        return sintbl[90*ECAR_PRECISE_CIRCLE - (Angle-90*ECAR_PRECISE_CIRCLE)];
    } else if (Angle > 180*ECAR_PRECISE_CIRCLE && Angle <= 270*ECAR_PRECISE_CIRCLE) {
        return 0 - sintbl[Angle-180*ECAR_PRECISE_CIRCLE];
    } else if (Angle > 270*ECAR_PRECISE_CIRCLE && Angle < 360*ECAR_PRECISE_CIRCLE) {
        return 0 - sintbl[90*ECAR_PRECISE_CIRCLE - (Angle-270*ECAR_PRECISE_CIRCLE)];
    } else {
        return 0;
    }
}
FT16 ecar_Qcos(FTU16 Angle)
{
    if (Angle >= 0 && Angle+90*ECAR_PRECISE_CIRCLE < 360*ECAR_PRECISE_CIRCLE) {
        return ecar_Qsin(Angle+90*ECAR_PRECISE_CIRCLE);
    } else if (Angle+90*ECAR_PRECISE_CIRCLE > 360*ECAR_PRECISE_CIRCLE && Angle < 360*ECAR_PRECISE_CIRCLE) {
        return ecar_Qsin(90*ECAR_PRECISE_CIRCLE + (Angle - 360*ECAR_PRECISE_CIRCLE));
    } else {
        return 1; 
    }
}
FTVOID ecar_getXYfrmCenter(FT16 Angle, FT16 Radius, FT16 *pX, FT16 *pY)
{
    *pX = *pX - (FT16)(((FT32)Radius*ecar_Qsin(Angle)) >> 13);
    *pY = *pY + (FT16)(((FT32)Radius*ecar_Qcos(Angle)) >> 13);
}

FTU8 ecar_boot_frame(FTU32 *pframe, FTU32 max)
{
    if (*pframe >= max-1) {
        return 1;
    } else {
        *pframe = *pframe + 1;
    }

    info_header->addr = ECAR_BOOT_ADDR + *pframe * ECAR_BOOT_SLEN;
    /* keep pumpping the data into the GRAM */
    appEVEFLHToEVE(info_header->addr, ECAR_RAM_BOOT, ECAR_BOOT_SLEN);
    
    return 0;
}

FTVOID ecar_boot(FTU32 para)
{
	static FTU8 first = 1;
	static FTU32 c = 1;

	if (first) 
	{
		if(APP_OK != appBmpToRamG(ECAR_HDL_BG, ECAR_RAM_BOOT, bmp_header, 1)){
			//DBGPRINT;
			return;
		}

        HAL_CmdBufIn(CMD_DLSTART);
        HAL_CmdBufIn(CLEAR_COLOR_RGB(255, 255, 255));
        HAL_CmdBufIn(CLEAR(1, 1, 1));

        HAL_CmdBufIn(BEGIN(BITMAPS));
        HAL_CmdBufIn(BITMAP_HANDLE(ECAR_HDL_BOOT));
        HAL_CmdBufIn(CELL(0));

        /* display one frame */
        HAL_CmdBufIn(VERTEX2F(0,0));


        HAL_CmdBufIn(END());
        HAL_CmdBufIn(DISPLAY());
        HAL_CmdBufIn(CMD_SWAP);

        HAL_BufToReg(RAM_CMD, 0);

		first = 0;
	}
	else 
	{
        /* change the frame index to make it 'animation' */
        if (ecar_boot_frame(&c, ECAR_BOOT_FMAX)) 
		{
            //appClnScrn(0,0,0);
            /* boot process finished, go next */
	        appGP.appIndex = 1;
        }
		else 
		{
            /* stay in boot process */
            appGP.appIndex = 0;
        }
        /* 
         the delay has two function
         1. for the delay of each frame (you may use other way to do it)
         2. for the delay of appClnScrn (occasionally blurred screen be shown without delay)
         */
        FTDELAY(100);
    }
}

FTVOID ecar_background(FTVOID)
{
    HAL_CmdBufIn(BITMAP_HANDLE(ECAR_HDL_BG));
    HAL_CmdBufIn(CELL(0));
    HAL_CmdBufIn(VERTEX2F(0,0));
}

FTVOID ecar_number_tkm(FT32 num)
{
#define NUM_TKM_X 430
#define NUM_TKM_Y 382
    FT32 tmp = num, x = NUM_TKM_X;

    HAL_CmdBufIn(BITMAP_HANDLE(ECAR_HDL_NUM_D));
    HAL_CmdBufIn(PALETTE_SOURCE(((ImgInfoPal_st *)(bmp_header[ECAR_INX_NUM_D].info))->addr_lut));
    
    if (tmp == 0) {
        HAL_CmdBufIn(CELL(0));
        HAL_CmdBufIn(VERTEX2F(x*EVE_PIXEL_UNIT, NUM_TKM_Y*EVE_PIXEL_UNIT));
        return;
    }

    while (tmp) {
        HAL_CmdBufIn(CELL(tmp%10));
        HAL_CmdBufIn(VERTEX2F(x*EVE_PIXEL_UNIT, NUM_TKM_Y*EVE_PIXEL_UNIT));
        tmp = tmp/10;
        x -= (bmp_header[ECAR_INX_NUM_D].wide - 3);
    }
}

FTVOID ecar_number_abkm(FT32 num, FTU8 AorB)
{
#define NUM_ABMK_X 324
#define NUM_ABKM_X 430
#define NUM_ABKM_Y 409
    FT32 tmp = num, x = NUM_ABKM_X;

    HAL_CmdBufIn(BITMAP_HANDLE(ECAR_HDL_NUM_D));
    HAL_CmdBufIn(PALETTE_SOURCE(((ImgInfoPal_st *)(bmp_header[ECAR_INX_NUM_D].info))->addr_lut));
   
    HAL_CmdBufIn(CELL(tmp%10));
    HAL_CmdBufIn(VERTEX2F(x*EVE_PIXEL_UNIT, NUM_ABKM_Y*EVE_PIXEL_UNIT));
    x -= (bmp_header[ECAR_INX_NUM_D].wide - 15);
    tmp = tmp/10;
    HAL_CmdBufIn(CELL(12));
    HAL_CmdBufIn(VERTEX2F(x*EVE_PIXEL_UNIT, NUM_ABKM_Y*EVE_PIXEL_UNIT));

    do {
        x -= (bmp_header[ECAR_INX_NUM_D].wide - 3);
        HAL_CmdBufIn(CELL(tmp%10));
        HAL_CmdBufIn(VERTEX2F(x*EVE_PIXEL_UNIT, NUM_ABKM_Y*EVE_PIXEL_UNIT));
        tmp = tmp/10;
    } while (tmp);

    if (AorB) {
        HAL_CmdBufIn(CELL(11));
    } else {
        HAL_CmdBufIn(CELL(10));
    }
    HAL_CmdBufIn(VERTEX2F(NUM_ABMK_X*EVE_PIXEL_UNIT, NUM_ABKM_Y*EVE_PIXEL_UNIT));
}
FTVOID ecar_number_vot(FT32 vot)
{
#define NUM_VOT_X 405
#define NUM_VOT_Y 194
    FT32 tmp = vot, x = NUM_VOT_X;

    HAL_CmdBufIn(BITMAP_HANDLE(ECAR_HDL_NUM_C));
    HAL_CmdBufIn(PALETTE_SOURCE(((ImgInfoPal_st *)(bmp_header[ECAR_INX_NUM_C].info))->addr_lut));
    
    if (tmp == 0) {
        HAL_CmdBufIn(CELL(0));
        HAL_CmdBufIn(VERTEX2F(x*EVE_PIXEL_UNIT, NUM_VOT_Y*EVE_PIXEL_UNIT));
        return;
    }

    while (tmp) {
        HAL_CmdBufIn(CELL(tmp%10));
        HAL_CmdBufIn(VERTEX2F(x*EVE_PIXEL_UNIT, NUM_VOT_Y*EVE_PIXEL_UNIT));
        tmp = tmp/10;
        x -= bmp_header[ECAR_INX_NUM_C].wide;
    }
}
FTVOID ecar_number_amp(FT32 amp)
{
#define NUM_AMP_X 405
#define NUM_AMP_Y 294
    FT32 tmp = amp, x = NUM_AMP_X, n = 0;

    HAL_CmdBufIn(BITMAP_HANDLE(ECAR_HDL_NUM_C));
    HAL_CmdBufIn(PALETTE_SOURCE(((ImgInfoPal_st *)(bmp_header[ECAR_INX_NUM_C].info))->addr_lut));
    
    if (tmp == 0) {
        HAL_CmdBufIn(CELL(0));
        HAL_CmdBufIn(VERTEX2F(x*EVE_PIXEL_UNIT, NUM_AMP_Y*EVE_PIXEL_UNIT));
        return;
    }

    if (tmp < 0) {
        n = 1;
        tmp = tmp * (-1);
    }

    while (tmp) {
        HAL_CmdBufIn(CELL(tmp%10));
        HAL_CmdBufIn(VERTEX2F(x*EVE_PIXEL_UNIT, NUM_AMP_Y*EVE_PIXEL_UNIT));
        tmp = tmp/10;
        x -= bmp_header[ECAR_INX_NUM_C].wide;
    }

    if (n) {
        HAL_CmdBufIn(CELL(10));
        HAL_CmdBufIn(VERTEX2F(x*EVE_PIXEL_UNIT, NUM_AMP_Y*EVE_PIXEL_UNIT));
    }
}
FTVOID ecar_speed(FT16 spd)
{
    FTU8 i;
  
    for (i = 0; i < ECAR_MARK_NUM; i++) {
        if ((spd >= ECAR_PRECISE_SPEED*spd_mark[i].spd_n1_low && spd <= ECAR_PRECISE_SPEED*spd_mark[i].spd_n1_high) || 
            (spd >= ECAR_PRECISE_SPEED*spd_mark[i].spd_n2_low && spd <= ECAR_PRECISE_SPEED*spd_mark[i].spd_n2_high)) {
            HAL_CmdBufIn(BITMAP_HANDLE(ECAR_HDL_SPEED_N));
            HAL_CmdBufIn(PALETTE_SOURCE(((ImgInfoPal_st *)(bmp_header[ECAR_INX_SPEED_N].info))->addr_lut));
            HAL_CmdBufIn(CELL(i));
            HAL_CmdBufIn(VERTEX2F(spd_mark[i].spd_x*EVE_PIXEL_UNIT,spd_mark[i].spd_y*EVE_PIXEL_UNIT));
        }
        
        if (spd >= ECAR_PRECISE_SPEED*spd_mark[i].spd_b_low && spd <= ECAR_PRECISE_SPEED*spd_mark[i].spd_b_high) {
            HAL_CmdBufIn(BITMAP_HANDLE(ECAR_HDL_SPEED_B));
            HAL_CmdBufIn(PALETTE_SOURCE(((ImgInfoPal_st *)(bmp_header[ECAR_INX_SPEED_B].info))->addr_lut));
            HAL_CmdBufIn(CELL(i));
            HAL_CmdBufIn(VERTEX2F(spd_mark[i].spd_x*EVE_PIXEL_UNIT,spd_mark[i].spd_y*EVE_PIXEL_UNIT));
        }
    }
}
static FTU32  ecar_x2a(FT16 x, FT16 x_min, FT16 x_max, FT16 a_start, FT16 a_end)
{
    FT16 a = (x - x_min);

    if (a < 0) {
        a = (-1)*a;
    }

    a = a_start + (FT32)a*(a_end-a_start)/(x_max - x_min);

    return (a >= 360*ECAR_PRECISE_CIRCLE)?0:a;
}
FTVOID ecar_needle_speed(FT16 speed)
{
#define NEEDLE_SPD_R        (160)
#define NEEDLE_SPD_CENTER_X (10)
#define NEEDLE_SPD_CENTER_Y (5)
//#define NEEDLE_SPD_OFFSET   (bmp_header[ECAR_INX_NEEDLE_0].high)
//#define SPEED2ANGLE_START   (56*ECAR_PRECISE_CIRCLE)
//#define SPEED2ANGLE_END     (302*ECAR_PRECISE_CIRCLE)

    FT16 x = (EVE_LCD_WIDTH/2-10)-NEEDLE_SPD_OFFSET,
         y = (EVE_LCD_HIGH/2+10)-NEEDLE_SPD_OFFSET,
         agl = ecar_x2a(speed,ECAR_MIN_SPEED,ECAR_MAX_SPEED,SPEED2ANGLE_START,SPEED2ANGLE_END);

    HAL_CmdBufIn(BITMAP_HANDLE(ECAR_HDL_NEEDLE_0));
    HAL_CmdBufIn(CELL(0));
    
    HAL_CmdBufIn(SAVE_CONTEXT());
    CoCmd_LOADIDENTITY;
    /* have to do the offset to make it fully display */
    CoCmd_TRANSLATE(NEEDLE_SPD_OFFSET*EVE_TRANSFORM_MAX, 
                    NEEDLE_SPD_OFFSET*EVE_TRANSFORM_MAX);
    CoCmd_ROTATEAROUND(NEEDLE_SPD_CENTER_X,
                       NEEDLE_SPD_CENTER_Y,
                       (FT32)agl*EVE_TRANSFORM_MAX/(360*ECAR_PRECISE_CIRCLE),EVE_TRANSFORM_MAX);
    CoCmd_SETMATRIX;
    
    ecar_getXYfrmCenter(agl,NEEDLE_SPD_R,&x,&y);

    HAL_CmdBufIn(VERTEX2F(x*EVE_PIXEL_UNIT,y*EVE_PIXEL_UNIT));
    HAL_CmdBufIn(RESTORE_CONTEXT());
}
FTVOID ecar_needle_power(FT16 power)
{
#define NEEDLE_PWR_R        (260)
#define NEEDLE_PWR_CENTER_X (6)
#define NEEDLE_PWR_CENTER_Y (5)
#define NEEDLE_PWR_OFFSET   (bmp_header[ECAR_INX_NEEDLE_1].high)
#define POWER2ANGLE_START   (56*ECAR_PRECISE_CIRCLE)
#define POWER2ANGLE_END     (132*ECAR_PRECISE_CIRCLE)

    FT16 x = (EVE_LCD_WIDTH/2-10)-NEEDLE_PWR_OFFSET,
         y = (EVE_LCD_HIGH/2+10)-NEEDLE_PWR_OFFSET,
         agl = ecar_x2a(power,ECAR_MIN_PWR,ECAR_MAX_PWR,POWER2ANGLE_START,POWER2ANGLE_END);

    HAL_CmdBufIn(BITMAP_HANDLE(ECAR_HDL_NEEDLE_1));
    HAL_CmdBufIn(CELL(0));
    
    HAL_CmdBufIn(SAVE_CONTEXT());
    CoCmd_LOADIDENTITY;
    /* have to do the offset to make it fully display */
    CoCmd_TRANSLATE(NEEDLE_PWR_OFFSET*EVE_TRANSFORM_MAX, 
                    NEEDLE_PWR_OFFSET*EVE_TRANSFORM_MAX);
    CoCmd_ROTATEAROUND(NEEDLE_PWR_CENTER_X,
                       NEEDLE_PWR_CENTER_Y,
                       agl*EVE_TRANSFORM_MAX/(360*ECAR_PRECISE_CIRCLE),EVE_TRANSFORM_MAX);
    CoCmd_SETMATRIX;
    
    ecar_getXYfrmCenter(agl,NEEDLE_PWR_R,&x,&y);

    HAL_CmdBufIn(VERTEX2F(x*EVE_PIXEL_UNIT,y*EVE_PIXEL_UNIT));
    HAL_CmdBufIn(RESTORE_CONTEXT());
}
FTVOID ecar_needle_trpm(FT16 trpm)
{
#define NEEDLE_TRPM_R        (260)
#define NEEDLE_TRPM_CENTER_X (6)
#define NEEDLE_TRPM_CENTER_Y (5)
#define NEEDLE_TRPM_OFFSET   (bmp_header[ECAR_INX_NEEDLE_1].high)
#define TRPM2ANGLE_START     (299*ECAR_PRECISE_CIRCLE)
#define TRPM2ANGLE_END       (228*ECAR_PRECISE_CIRCLE)

    FT16 x = (EVE_LCD_WIDTH/2-10)-NEEDLE_TRPM_OFFSET,
         y = (EVE_LCD_HIGH/2+10)-NEEDLE_TRPM_OFFSET,
         agl = ecar_x2a(trpm,ECAR_MIN_TRPM,ECAR_MAX_TRPM,TRPM2ANGLE_START,TRPM2ANGLE_END);

    HAL_CmdBufIn(BITMAP_HANDLE(ECAR_HDL_NEEDLE_1));
    HAL_CmdBufIn(CELL(0));
    
    HAL_CmdBufIn(SAVE_CONTEXT());
    CoCmd_LOADIDENTITY;
    /* have to do the offset to make it fully display */
    CoCmd_TRANSLATE(NEEDLE_PWR_OFFSET*EVE_TRANSFORM_MAX, 
                    NEEDLE_PWR_OFFSET*EVE_TRANSFORM_MAX);
    CoCmd_ROTATEAROUND(NEEDLE_PWR_CENTER_X,
                       NEEDLE_PWR_CENTER_Y,
                       agl*EVE_TRANSFORM_MAX/(360*ECAR_PRECISE_CIRCLE),EVE_TRANSFORM_MAX);
    CoCmd_SETMATRIX;
    
    ecar_getXYfrmCenter(agl,NEEDLE_TRPM_R,&x,&y);

    HAL_CmdBufIn(VERTEX2F(x*EVE_PIXEL_UNIT,y*EVE_PIXEL_UNIT));
    HAL_CmdBufIn(RESTORE_CONTEXT());
}
FTVOID ecar_overspeed(FTVOID)
{
#define OVERSPEED_X 287
#define OVERSPEED_Y 141
    HAL_CmdBufIn(BITMAP_HANDLE(ECAR_HDL_OVERSPEED_B));
    HAL_CmdBufIn(CELL(0));
    HAL_CmdBufIn(VERTEX2F(OVERSPEED_X*EVE_PIXEL_UNIT,OVERSPEED_Y*EVE_PIXEL_UNIT));
}
FTVOID ecar_xpatch(FTVOID)
{
#define XPATCH_X 495
#define XPATCH_Y 332
    HAL_CmdBufIn(BITMAP_HANDLE(ECAR_HDL_XPATCH));
    HAL_CmdBufIn(CELL(0));
    HAL_CmdBufIn(VERTEX2F(XPATCH_X*EVE_PIXEL_UNIT,XPATCH_Y*EVE_PIXEL_UNIT));
}
FTVOID ecar_warning(FTVOID)
{
#define WARNING_1_X 49
#define WARNING_1_Y 16
#define WARNING_2_X 753
#define WARNING_2_Y 185
#define WARNING_3_X 32
#define WARNING_3_Y 422

    HAL_CmdBufIn(BITMAP_HANDLE(ECAR_HDL_WARNING));
    HAL_CmdBufIn(CELL(0));
    HAL_CmdBufIn(VERTEX2F(WARNING_1_X*EVE_PIXEL_UNIT,WARNING_1_Y*EVE_PIXEL_UNIT));
    HAL_CmdBufIn(CELL(1));
    HAL_CmdBufIn(VERTEX2F(WARNING_2_X*EVE_PIXEL_UNIT,WARNING_2_Y*EVE_PIXEL_UNIT));
    HAL_CmdBufIn(CELL(2));
    HAL_CmdBufIn(VERTEX2F(WARNING_3_X*EVE_PIXEL_UNIT,WARNING_3_Y*EVE_PIXEL_UNIT));
}

FTVOID ecar_simulat(FT32 *p, FT32 min, FT32 max)
{
    if (TOUCHED) {
        if (max > *p) {
            *p = *p + 4;
        }
    } else {
        if (min < *p) {
            *p = *p - 4;
        } 
    }
}

FTVOID ecar_dashboard(FTU32 para)
{
	static FT32 load = 1, 
                speed = ECAR_MIN_SPEED, 
                power = ECAR_MIN_PWR, 
                trpm = ECAR_MIN_TRPM,
                tkm = ECAR_MIN_TKM,
                akm = ECAR_MIN_AKM,
                bkm = ECAR_MIN_BKM,
                vot = ECAR_MIN_VOT,
                amp = ECAR_MIN_AMP;

	if (load) {
		if(APP_OK != appBmpToRamG(ECAR_HDL_BOOT, ECAR_RAM_DASHBOARD, &bmp_header[1], ECAR_HDL_MAX)){
			//DBGPRINT;
			return;
		}

        appBilinearModify(ECAR_HDL_NEEDLE_0, bmp_header[ECAR_INX_NEEDLE_0].high*2);
        appBilinearModify(ECAR_HDL_NEEDLE_1, bmp_header[ECAR_INX_NEEDLE_1].high*2);
        load = 0;
	}
    HAL_CmdBufIn(CMD_DLSTART);
    HAL_CmdBufIn(CLEAR_COLOR_RGB(0, 0, 0));
    HAL_CmdBufIn(CLEAR(1, 1, 1));

    HAL_CmdBufIn(BEGIN(BITMAPS));

    ecar_background();
 
    ecar_number_tkm(tkm);

    if (speed > ECAR_AB_SPD) {
        ecar_number_abkm(bkm,1);
        ecar_simulat(&bkm, ECAR_MIN_BKM, ECAR_MAX_BKM);
    } else {
        ecar_number_abkm(akm,0);
        ecar_simulat(&akm, ECAR_MIN_AKM, ECAR_MAX_AKM);
    }

    if (speed > ECAR_WARNING_SPD) {
        ecar_warning();
    }

    if (speed > ECAR_OVERSPEED_SPD) {
        ecar_overspeed();
        ecar_xpatch();
    } else {
        ecar_number_vot(vot); 
        ecar_number_amp(amp);
    }
   
    ecar_speed(speed);
    ecar_needle_speed(speed);
    ecar_needle_power(power);
	ecar_needle_trpm(trpm);

    HAL_CmdBufIn(END());
    HAL_CmdBufIn(DISPLAY());
    HAL_CmdBufIn(CMD_SWAP);
    HAL_BufToReg(RAM_CMD, 0);

    ecar_simulat(&speed, ECAR_MIN_SPEED, ECAR_MAX_SPEED);
    ecar_simulat(&power, ECAR_MIN_PWR, ECAR_MAX_PWR);
    ecar_simulat(&trpm, ECAR_MIN_TRPM, ECAR_MAX_TRPM);
    ecar_simulat(&tkm, ECAR_MIN_TKM, ECAR_MAX_TKM);
    ecar_simulat(&vot, ECAR_MIN_VOT, ECAR_MAX_VOT);
    ecar_simulat(&amp, ECAR_MIN_AMP, ECAR_MAX_AMP);
    /* stay in dashboard process */
	appGP.appIndex = 1;
}
typedef FTVOID (* AppFunc) (FTU32);

#endif


