#ifndef _PLATFORM_TYPE_H_
#define _PLATFORM_TYPE_H_



typedef char         		FTC8;
typedef char				FT8;
typedef unsigned char      	FTU8;
typedef int      			FT16;
typedef unsigned int     	FTU16;
typedef long      			FT32;
typedef unsigned long     	FTU32;
#define STATIC static
#define FTVOID void

#define FTMAIN int main (FTVOID) 
#define APPS_SYS stm32_apps_sys_dummy
#define FTPRINT stm32_dumy_print
#define FTDELAY   stm32f4Delay
#define FTRANDOM stm32f4Random



#endif
