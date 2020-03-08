/*****************************************************
	SPI.h
*****************************************************/

#ifndef _SPI_H_
#define _SPI_H_

#include "Platform_Type.h"

//typedef char         		FTC8;
//typedef char				FT8;
//typedef unsigned char      	FTU8;
//typedef int      			FT16;
//typedef unsigned int     	FTU16;
//typedef long      			FT32;
//typedef unsigned long     	FTU32;
//#define STATIC static
//#define FTVOID void

//#define FTMAIN int main (FTVOID) 
//#define APPS_SYS stm32_apps_sys_dummy
//#define FTPRINT stm32_dumy_print
//#define FTDELAY   stm32f4Delay
//#define FTRANDOM stm32f4Random



#define ROOT_PATH 
#define CDATA_PATH NULL

#define CALD_TAG_ADDR 0
#define CALD_TAG_DATA "CALD"
#define CALD_TAG_LEN  4

FTVOID HAL_invaild_tag (FTC8 *dataPath);
FTU8 HAL_is_tag_vaild (FTC8 *dataPath);
FTVOID HAL_save_cdata (FTC8 *dataPath, FTU8 *p);
FTVOID HAL_restore_cdata (FTC8 *dataPath, FTU8 *p);
FTVOID HAL_vaild_tag (FTVOID);
FTVOID stm32f4Delay(FTU32 nTime);
extern FTU32 HAL_SegFileSize (FTU32 handle);
extern FTVOID HAL_SegFileClose (FTU32 handle);
extern FTU8 HAL_ZlibCompressed (FTU32 handle, FTU32 src);
extern FTVOID HAL_Write8 ( FTU32 addr, FTU8 data );
extern FTVOID HAL_Write16 ( FTU32 addr, FTU16 data );
extern FTVOID HAL_Write32 ( FTU32 addr, FTU32 data );
extern FTU8 HAL_Read8 ( FTU32 addr );
extern FTU16 HAL_Read16 ( FTU32 addr );
extern FTU32 HAL_Read32 ( FTU32 addr );
extern FTVOID HAL_Write8Src ( FTU32 addr, FTU8 *src, FTU32 len );
extern FTU32 HAL_Read8Buff ( FTU32 addr, FTU8 *buff, FTU32 len );
extern FTVOID HAL_LoopMemFree (FTU32 buf);
extern FTVOID HAL_PwdCyc ( FTU8 OnOff );
extern FTVOID HAL_SpiInit ( FTVOID );
extern FTVOID HAL_Cfg ( FTU8 cfg );
extern FTU32 HAL_SegFileOpen (FTU8 *path);
extern FTU32 HAL_WriteSrcToDes (FTU32 handle, FTU32 src, FTU32 des, FTU32 len);
extern FTVOID HAL_preparation (FTVOID);
extern FTVOID stm32_dumy_print(char * p);
extern FTVOID HAL_LoopMemRead (FTU32 handle, FTU8 **ppbuf, FTU32 len);


#endif

