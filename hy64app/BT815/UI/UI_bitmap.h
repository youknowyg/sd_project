#ifndef _UI_BITMAP_H_
#define _EE_BITMAP_H_



 typedef char				 FTC8;
 typedef char				 FT8;
 typedef unsigned char		 FTU8;
 typedef int				 FT16;
 typedef unsigned int		 FTU16;
 typedef long				 FT32;
 typedef unsigned long		 FTU32;

#define STATIC static
#define FTVOID void




/*
 * global parameter, data exchange between
 * 1. UI.n and UI.n+1
 * 2. UI and SYS
 */


void DispTest(unsigned int data,unsigned char stu);
#endif