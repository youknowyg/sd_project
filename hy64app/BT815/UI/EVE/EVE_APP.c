/**********************************************
			EVE_APP.c
**********************************************//* 
Applicaton, Integrated function for EVE 
Author: Hawk
Email : hawk.gao@ftdichip.com	
Date  : 2013/Oct
 */
#include "platform.h"
#include "EVE_Gpu.h"
#include "EVE_HAL.h"
#include "EVE_APP.h"
#include "SPI.h"
#include <stdio.h>
#include <string.h>

#define FONT_CAL 27
#define FORCE_WAIT_COUNT 3
#define FORCE_WAIT_TIME 500
#define RETRY_COUNT  8
/* 
 * for FT9XX delay has to be larger than 10 
 * use a larger wait time (100) to expand the system's
 * adaptability
 */
#define READ_ID_WAIT 100//100

/* 
 * longer delay for CAP touch engin ready
 * for RES touch engin, 10 would be enough 
 * do longer delay anyway for safer status
 */
#define CLK_DELAY 150//200

FTU8 READ_ID = 0;

FTU8 dbg_str_buf[EVE_DBG_BUF_LEN] = "Error occur / Stop display";

typedef char         		FTC8;
typedef char				FT8;
typedef unsigned char      	FTU8;
typedef int      			FT16;
typedef unsigned int     	FTU16;
typedef long      			FT32;
typedef unsigned long     	FTU32;
#define STATIC static
#define FTVOID void
#ifndef NULL
#define NULL				(0L)
#endif
#define EVE_CAL_PARA_NUM    (6)

FTU8 * HAL_LoopMemMalloc (FTU32 handle, FTU32 src, FTU32 len);




#if defined(CAL_NEEDED)
STATIC appRet_en appCalCmd (FTU8 font, FTC8 *str1, FTC8 *str2)
{
    FTU32 ret_addr;

    HAL_CmdBufIn(CMD_DLSTART);

    HAL_CmdBufIn(CLEAR_COLOR_RGB(0,0,0));
    HAL_CmdBufIn(CLEAR(1,1,1));
    HAL_CmdBufIn(COLOR_RGB(255,255,255));

    CoCmd_TEXT(EVE_LCD_WIDTH/2,EVE_LCD_HIGH/2,font,OPT_CENTER,str1);
    CoCmd_TEXT(EVE_LCD_WIDTH/2,EVE_LCD_HIGH/3*2,font,OPT_CENTER,
               (str2 == NULL)?"NULL":str2);
    HAL_CmdBufIn(CMD_CALIBRATE);
    HAL_CmdBufIn(0);
    ret_addr = HAL_CalResultAddr();
    HAL_BufToReg(RAM_CMD,0);

    return (0 != HAL_Read32(ret_addr))?APP_OK:APP_ERR_CALC;
}

STATIC appRet_en appCalForce (FTC8 *dataPath)
{
    FTU32 CData[EVE_CAL_PARA_NUM] = {0},
          reg = REG_TOUCH_TRANSFORM_A, i = 0;

    /* make the tag part invalid */
    HAL_invaild_tag(dataPath);

    /* do calibration to get the CData */
    if (APP_OK == appCalCmd(FONT_CAL,(FTC8 *)"Tap the flashing point",dataPath)) {
        for (i = 0; i < EVE_CAL_PARA_NUM; reg+=4,i++) {
            CData[i] = HAL_Read32(reg);
        }
        /* save the CData */
        HAL_save_cdata(dataPath, (FTU8 *)CData);

        /* make the tag part valid */
        HAL_vaild_tag();
    }
    return APP_OK;
}

STATIC appRet_en appCal (FTU8 force, FTC8 *dPath)
{
    FTU32 CData[EVE_CAL_PARA_NUM] = {0};
    FTU32 reg = REG_TOUCH_TRANSFORM_A, i = 0;

    if (force || (dPath == NULL)) {
        return appCalForce(dPath);
    }

    if (!HAL_is_tag_vaild(dPath)) {
        return appCalForce(dPath);
    }

    HAL_restore_cdata(dPath, (FTU8 *)CData);
    
    while (reg <= REG_TOUCH_TRANSFORM_F) {
        HAL_Write32(reg, CData[i]);
        i++;
        reg += 4;
    }
    return APP_OK;
}
#endif

FTU32 appGetLinestride(bmpHDR_st *bmpHD)
{
    FTU32 linestride = 0;

    switch (bmpHD->format) {
        case L1:
            linestride = (bmpHD->wide)/8;
            break;
        case L2:
            linestride = (bmpHD->wide)/4;
            break;
        case L4:
            linestride = (bmpHD->wide)/2;
            break;
        case L8:
        case ARGB2:
        case RGB332:
#if defined(DEF_81X) || defined(DEF_BT81X)
        case PALETTED8:
        case PALETTED565:
        case PALETTED4444:
#else
        case PALETTED:
#endif 
            linestride = (bmpHD->wide);
            break;
#if defined(DEF_BT81X)
        case COMPRESSED_RGBA_ASTC_10x10_KHR:
            linestride = (bmpHD->wide)*128/800;
            break;
        case COMPRESSED_RGBA_ASTC_10x5_KHR:
            linestride = (bmpHD->wide)*213/800;
            break;
        case COMPRESSED_RGBA_ASTC_10x6_KHR:
            linestride = (bmpHD->wide)*200/800;
            break;
        case COMPRESSED_RGBA_ASTC_10x8_KHR:
            linestride = (bmpHD->wide)*160/800;
            break;
        case COMPRESSED_RGBA_ASTC_12x10_KHR:
            linestride = (bmpHD->wide)*107/800;
            break;
        case COMPRESSED_RGBA_ASTC_12x12_KHR:
            linestride = (bmpHD->wide)*89/800;
            break;
        case COMPRESSED_RGBA_ASTC_4x4_KHR:
            linestride = (bmpHD->wide);
            break;
        case COMPRESSED_RGBA_ASTC_5x4_KHR:
            linestride = (bmpHD->wide)*640/800;
            break;
        case COMPRESSED_RGBA_ASTC_5x5_KHR:
            linestride = (bmpHD->wide)*512/800;
            break;
        case COMPRESSED_RGBA_ASTC_6x5_KHR:
            linestride = (bmpHD->wide)*427/800;
            break;
        case COMPRESSED_RGBA_ASTC_6x6_KHR:
            linestride = (bmpHD->wide)*356/800;
            break;
        case COMPRESSED_RGBA_ASTC_8x5_KHR:
            linestride = (bmpHD->wide)*320/800;
            break;
        case COMPRESSED_RGBA_ASTC_8x6_KHR:
            linestride = (bmpHD->wide)*267/800;
            break;
        case COMPRESSED_RGBA_ASTC_8x8_KHR:
            linestride = (bmpHD->wide)*256/800;
            break;
#endif
        case ARGB4:
        case RGB565:
        case ARGB1555:
        default:
            linestride = (bmpHD->wide)*2;
            break;
    }

    return linestride;
}

FTVOID SegmentOperation (FTU32 handle, FTU32 src, FTU32 des, FTU32 len, FTU8 toCoPro)
{
    /* make sure the data length into EVE is 4bytes aligned */
    FTU32 i,block,l,file_len = BYTES4ALIGN(len);
    FTU8 * p = 0;

    if (toCoPro) {
        block = CMDBUF_SIZE/2;
    } else {
        block = MCU_BLOCK_SIZE;
    }

    p = HAL_LoopMemMalloc(handle, src, block);
    if(!p){
        //__FTPRINT("\nno segment memory");
        return; 
    }

    for (i = 0; i < file_len; i += l) {
        l = ((file_len - i) > block)?block:(file_len - i);
        
        HAL_LoopMemRead(handle, &p, l);
        
        if (toCoPro) {
            HAL_CmdWait(HAL_EVELoopMemWr(RAM_CMD, HAL_Read32(REG_CMD_WRITE), CMDBUF_SIZE, p, l));
        } else {
            HAL_Write8Src(des+i, p, l);
        }
    }

    HAL_LoopMemFree((FTU32)p);
}

FTU32 FileProcess(FTU32 handle, FTU32 src, FTU32 des, FTU32 len)
{
    if (HAL_ZlibCompressed(handle, src)) {
        /* make sure command buffer clean */
        HAL_CmdWait((FTU16)HAL_Read32(REG_CMD_WRITE));
        /* then start sending the command */
        HAL_CmdToReg(CMD_INFLATE);
        HAL_CmdToReg(des);
        SegmentOperation(handle, src, des, len, 1);
        /* 
           give a special length for the return routine
           to do some special handle for zlib file
         */
        return TYPE_ZLIB;
    } else {
        SegmentOperation(handle, src, des, len, 0);
        
        return len;
    }
}

FTU8 appFileExist (FTC8 *path) 
{
    FTU32 resHDL;

    resHDL = HAL_SegFileOpen((FTU8 *)path);
    if (resHDL == 0) {
        //__FTPRINT("\nappFileExist: file open error");
        return 0;
    }

    if (!HAL_SegFileSize(resHDL)) {
        HAL_SegFileClose(resHDL);
        //__FTPRINT("\nappFileExist: file size 0");
        return 0;
    }

    return 1;
}
FTU32 appGetNumFromStr(FTU8 *str)
{
/*
 max NUMBER string should be less than 10
 just expand it for any SPACE insert in NUMBER string
 */
#define SEARCH_MAX 100
    FTU32 tmp = 0, i = 0;

    while (str[i]) {
        if (str[i] >= '0' && str[i] <= '9') {
            tmp *= 10;
            tmp += (FTU32)(str[i] - '0');
        } else if (str[i] == MARK_LEN) {
            break;
		}
        if (++i >= SEARCH_MAX) {
            return 0;
        }
    }

    return tmp;
}
/* the chkExceed flag provid the flexibility while using puzzle overlap function */
FTU32 appFileToRamG (FTC8 *path, FTU32 inAddr, FTU8 chkExceed, FTU8 *outAddr, FTU32 outLen)
{
    FTU32 Len, resHDL;

    /* 
      the reason why not handle the eve-connected-flash reading operation here is
      during the eve-connected-flash reading operation, 
      there would be some image realted info is needed, 
      don't want to integrate too much function 
      in one simple purpose routine.
    */
    if (!appEVEFLHPath(path, &Len)) {
        
        resHDL = HAL_SegFileOpen((FTU8 *)path);
        if (resHDL == 0) {
            //__FTPRINT("\nappFileToRamG: file open error");
            return 0;
        }

        Len = HAL_SegFileSize(resHDL);
        if (chkExceed && (EVE_RAMG_SIZE < inAddr + Len)) {
            HAL_SegFileClose(resHDL);
            //__FTPRINT("\nappFileToRamG: EVE_RAMG_SIZE < inAddr + Len");
            return 0;
        }

        Len = FileProcess(resHDL,0,inAddr,Len);

        if (outAddr) {
            /* originally used for font application demo, 
               to read the font block info into font structure variable
               most of time are usless */
            HAL_WriteSrcToDes(resHDL,0,(FTU32)outAddr,outLen);
        }

        HAL_SegFileClose(resHDL);
    }

    return Len;
}

FTU8 LenTricksPal(FTU32 *p_addr, bmpHDR_st *pbmpHD)
{
    ImgInfoPal_st *p = (ImgInfoPal_st *)pbmpHD->info;

    p->addr_inx = *p_addr;
    /* lookup table alwasy smaller than 1K */
    p->len_lut = 1024;

    switch (p->len_inx) {
        case TYPE_ZLIB:
            /* 
               index file uncompress and forward to EVE action had been done
               in FileProcess, only got the correct length
               of uncompressed file, for the address offset
             */
            p->len_inx = appGetLinestride(pbmpHD)*pbmpHD->high;
            /* break out to read the lookup table file later*/
            break;
#if defined(DEF_BT81X)
        case TYPE_Z_EVEFLH:
            appEVEFLHUnzip(p->path_inx, p->addr_inx);
            p->len_inx = appGetLinestride(pbmpHD)*pbmpHD->high;
            p->addr_lut = p->addr_inx + p->len_inx;
            
            appEVEFLHUnzip(p->path_lut, p->addr_lut);
            
            *p_addr = p->addr_lut + p->len_lut;
            return 0;
        case TYPE_EVEFLH:
            p->len_inx = appEVEFLHLen(p->path_inx);
            if (appEVEFLHToEVE(appEVEFLHAddr(p->path_inx), p->addr_inx, p->len_inx)) {
                //__FTPRINT("\nLenTricksPal: inx flash to eve fail");
                return 1;
            }
            
            p->addr_lut = p->addr_inx + p->len_inx;
            p->len_lut = appEVEFLHLen(p->path_lut);
            if (appEVEFLHToEVE(appEVEFLHAddr(p->path_lut), p->addr_lut, p->len_lut)) {
                //__FTPRINT("\nLenTricksPal: lut flash to eve fail");
                return 1;
            }
            *p_addr = p->addr_lut + p->len_lut;
            return 0;
#endif
        case 0:
            //__FTPRINT("\nLenTricksPal: len 0");
            return 1;
        default:
            /* normal length, break out to read the lookup table file later*/
            break;
    }

    if (PALETTED == pbmpHD->format) {
        p->addr_lut = RAM_PAL;
        *p_addr = p->addr_inx + p->len_inx;
    } else {
        p->addr_lut = p->addr_inx + p->len_inx;
        *p_addr = p->addr_lut + p->len_lut;
    }
    /* 
       whatever none EVEFLH index file use compressed file or not, 
       FilePrecess inside the FileToRamG would handle it,
       no need to know the length
     */
    if (!appFileToRamG(p->path_lut,p->addr_lut,1,0,0)) {
        //__FTPRINT("\nLenTricksPal: lut file error");
        return 1;
    } else {
        return 0;
    }
}

FTU8 LenTricksDXT1(FTU32 *p_addr, bmpHDR_st *pbmpHD)
{
    ImgInfoDXT1_st *p = (ImgInfoDXT1_st *)pbmpHD->info;

    p->addr = *p_addr;

    /* 
       no TYPE_ZLIB,TYPE_Z_EVEFLH,TYPE_ASTC_EVEFLH for DXT1 
       if one file is in EVEFLH all consider all others in EVEFLH
       vice versa
     */
    switch (p->len_c0) {
#if defined(DEF_BT81X)
        case TYPE_EVEFLH:
            p->len_c0 = appEVEFLHLen(p->path_c0);
            if (appEVEFLHToEVE(appEVEFLHAddr(p->path_c0), p->addr, p->len_c0)) {
                //__FTPRINT("\nLenTricksDXT1: flash c0 to eve fail");
                return 1;
            }
            p->len_c1 = appEVEFLHLen(p->path_c1);
            if (appEVEFLHToEVE(appEVEFLHAddr(p->path_c1), p->addr+p->len_c0, p->len_c1)) {
                //__FTPRINT("\nLenTricksDXT1: flash c1 to eve fail");
                return 1;
            }
            p->len_b0 = appEVEFLHLen(p->path_b0);
            if (appEVEFLHToEVE(appEVEFLHAddr(p->path_b0), p->addr+p->len_c0+p->len_b0, \
                                           p->len_b0)) {
                //__FTPRINT("\nLenTricksDXT1: flash b0 to eve fail");
                return 1;
            }
            p->len_b1 = appEVEFLHLen(p->path_b1);
            if (appEVEFLHToEVE(appEVEFLHAddr(p->path_b1), p->addr+p->len_c0+p->len_b0+p->len_b1, \
                                           p->len_b1)) {
                //__FTPRINT("\nLenTricksDXT1: flash b1 to eve fail");
                return 1;
            }
            *p_addr += (p->len_c0+p->len_c1+p->len_b0+p->len_b1);
            break;
#endif
        case 0:
            //__FTPRINT("\nLenTricksDXT1: len 0");
            return 1;
        default:
            p->len_c1 = appFileToRamG(p->path_c1,*p_addr+p->len_c0,1,0,0);
            if (p->len_c1 == 0) {
                //__FTPRINT("\nLenTricksDXT1: c1 to eve fail");
                return 1;
            }
            p->len_b0 = appFileToRamG(p->path_b0,*p_addr+p->len_c0+p->len_c1,1,0,0);
            if (p->len_c1 == 0) {
                //__FTPRINT("\nLenTricksDXT1: c1 to eve fail");
                return 1;
            }
            p->len_b1 = appFileToRamG(p->path_b1,*p_addr+p->len_c0+p->len_c1+p->len_b0,1,0,0);
            if (p->len_c1 == 0) {
                //__FTPRINT("\nLenTricksDXT1: c1 to eve fail");
                return 1;
            }
            break;
    }
    *p_addr += (p->len_c0+p->len_c1+p->len_b0+p->len_b1);
	return 0;
}

FTU8 LenTricks(FTU32 *p_addr, bmpHDR_st *pbmpHD)
{
    ImgInfo_st *p = (ImgInfo_st *)pbmpHD->info;

    p->addr = *p_addr;

    switch (p->len) {
        case TYPE_ZLIB:
            /* 
               file uncompress and forward to EVE action had been done
               in FileProcess, only got the correct length
               of uncompressed file, for the address offset
               TODO: if using CELL function, there is a problem in len
                     would find some time to overcome it.
             */
            p->len = appGetLinestride(pbmpHD)*pbmpHD->high;
            break;
#if defined(DEF_BT81X)
        case TYPE_ASTC_EVEFLH:
            /* 
               ONLY for ASTC: when using flash to display raw file
               no RAM is needed, EVE render directly from EVEFLH
             */
            p->len = 0;
            p->addr = 0x800000 | appEVEFLHAddr(p->path) / 32;
            break;
        case TYPE_Z_EVEFLH:
            appEVEFLHUnzip(p->path, *p_addr);
            /*
             TODO: if using CELL function, there is a problem in len
                   would find some time to overcome it.
            */
            p->len = appGetLinestride(pbmpHD)*pbmpHD->high;
            break;
        case TYPE_EVEFLH:
            p->len = appEVEFLHLen(p->path);
            if (appEVEFLHToEVE(appEVEFLHAddr(p->path), p->addr, p->len)) {
                //__FTPRINT("\nLenTricks: flash to eve fail");
                return 1;
            }
            break;
#endif
        case 0:
            //__FTPRINT("\nLenTricks: len 0");
            return 1;
        default:
            /* 
               no trick for normal length, just do the address offset 
             */
            break;
    }

    *p_addr += p->len;
    
    return 0;
}

FTU8 LoadImgFile(FTU32 *p_addr, bmpHDR_st *pbmpHD)
{
    ImgInfo_st *p = (ImgInfo_st *)pbmpHD->info;

    p->len = appFileToRamG(p->path,*p_addr,1,0,0);

    return LenTricks(p_addr, pbmpHD);
}

FTU8 LoadImgFilePal(FTU32 *p_addr, bmpHDR_st *pbmpHD)
{
    ImgInfoPal_st *p = (ImgInfoPal_st *)pbmpHD->info;

    p->len_inx = appFileToRamG(p->path_inx,*p_addr,1,0,0);
    
    return LenTricksPal(p_addr, pbmpHD);
}

FTU8 LoadImgFileDXT1(FTU32 *p_addr, bmpHDR_st *pbmpHD)
{
    ImgInfoDXT1_st *p = (ImgInfoDXT1_st *)pbmpHD->info;

    p->len_c0 = appFileToRamG(p->path_c0,*p_addr,1,0,0);
    
    return LenTricksDXT1(p_addr, pbmpHD);
}

appRet_en appLoadBmp(FTU32 ramgAddr, bmpHDR_st *pbmpHD, FTU32 nums)
{
    FTU32 i = 0, addr = ramgAddr;
    bmpHDR_st *p = pbmpHD;

    while (i < nums) {
        switch (p->format) {
            case PALETTED8:
            case PALETTED565:
            case PALETTED4444:
            case PALETTED:
                if (LoadImgFilePal(&addr, p)){
                    //__FTPRINT("\nappLoadBmp: pal file len error");
                    return APP_ERR_LEN;
                }
                break;
            case FORMAT_DXT1:
                if (LoadImgFileDXT1(&addr, p)){
                    //__FTPRINT("\nappLoadBmp: dxt1 file len error");
                    return APP_ERR_LEN;
                }
                break;
            default:
                if (LoadImgFile(&addr, p)){
                    //__FTPRINT("\nappLoadBmp: file len error");
                    return APP_ERR_LEN;
                }
                break;
        }
        i++;
        p++;
    }

    return APP_OK;
}

FTVOID DXT1BmpInfo (FTU8 startHdl, FTU32 startAddr, FTU16 W, FTU16 H)
{
#define DXT1_BLOCK_NUMS (4)
	HAL_CmdBufIn(BITMAP_HANDLE(startHdl+1));
	HAL_CmdBufIn(BITMAP_SOURCE(startAddr));
	HAL_CmdBufIn(BITMAP_LAYOUT(RGB565, W/DXT1_BLOCK_NUMS*2, H/DXT1_BLOCK_NUMS));
    HAL_CmdBufIn(BITMAP_LAYOUT_H(W/DXT1_BLOCK_NUMS*2 >> 10, H/DXT1_BLOCK_NUMS >> 9));
	HAL_CmdBufIn(BITMAP_SIZE(NEAREST, BORDER, BORDER, W, H));
    HAL_CmdBufIn(BITMAP_SIZE_H(W>>9, H>>9));

	HAL_CmdBufIn(BITMAP_HANDLE(startHdl));
	HAL_CmdBufIn(BITMAP_SOURCE(startAddr + 2*(W/DXT1_BLOCK_NUMS*2*H/DXT1_BLOCK_NUMS)));
	HAL_CmdBufIn(BITMAP_LAYOUT(L1, W/DXT1_BLOCK_NUMS/2, H));
    HAL_CmdBufIn(BITMAP_LAYOUT_H(W/DXT1_BLOCK_NUMS/2 >> 10, H >> 9));
	HAL_CmdBufIn(BITMAP_SIZE(NEAREST, BORDER, BORDER, W, H));
    HAL_CmdBufIn(BITMAP_SIZE_H(W>>9, H>>9));
}

FTVOID BmpInfo (FTU8 Hdl, FTU32 Format, FTU32 LnSt, FTU32 Addr, FTU16 W, FTU16 H)
{
    HAL_CmdBufIn(BITMAP_HANDLE(Hdl));
#if defined(DEF_81X) || defined(DEF_BT81X)
    /* 
     * when using SETBITMAP 
     * NEAREST,BORDER,BORDER would be the only
     * option in size, you may use size seperatly
     * when you wish to set other option such as BILINEAR
     */
    CoCmd_SETBITMAP(Addr,Format,W,H);
#else
    HAL_CmdBufIn(BITMAP_SOURCE(Addr));
    HAL_CmdBufIn(BITMAP_LAYOUT(Format,LnSt,H));
    /* 
     * select NEAREST or BILINEAR base on your image and requirement
     * NEAREST: make the image shap clear
     * BILINEAR: make the image shap smooth
     */
    HAL_CmdBufIn(BITMAP_SIZE(NEAREST,BORDER,BORDER,W,W));
#endif
}

FTVOID appBilinearModify (FTU8 Hdl, FTU16 MaxSize)
{
    /* 
    this routine most likely to be used 
    1. after config the bitmap info to it's dedicated handle,
    2. before doing rotation and scaling

    for each current handle related bitmap display
    only need to do this once

    MaxSize == ZERO means maximum
    it consume eve resource, so 
    better use the minimum MaxSize
    */
    HAL_CmdBufIn(CMD_DLSTART);
    HAL_CmdBufIn(BITMAP_HANDLE(Hdl));
    HAL_CmdBufIn(BITMAP_SIZE(BILINEAR,BORDER,BORDER,MaxSize,MaxSize));
#if defined(DEF_81X) || defined(DEF_BT81X)
    HAL_CmdBufIn(BITMAP_SIZE_H(MaxSize>>9,MaxSize>>9));
#endif
    HAL_CmdBufIn(DISPLAY());
    HAL_CmdBufIn(CMD_SWAP);
    HAL_BufToReg(RAM_CMD,0);
}

FTVOID appDispDXT1 (FTU8 startHdl, FT16 X, FT16 Y)
{
    HAL_CmdBufIn(SAVE_CONTEXT());
	HAL_CmdBufIn(BLEND_FUNC(ONE,ZERO));
	HAL_CmdBufIn(COLOR_A(0x55));
	HAL_CmdBufIn(BITMAP_HANDLE(startHdl));
	HAL_CmdBufIn(CELL(0));
	HAL_CmdBufIn(VERTEX2F(X*EVE_PIXEL_UNIT,Y*EVE_PIXEL_UNIT));

	HAL_CmdBufIn(BLEND_FUNC(ONE,ONE));
	HAL_CmdBufIn(COLOR_A(0xAA));
	HAL_CmdBufIn(BITMAP_HANDLE(startHdl));
	HAL_CmdBufIn(CELL(1));
	HAL_CmdBufIn(VERTEX2F(X*EVE_PIXEL_UNIT,Y*EVE_PIXEL_UNIT));

	HAL_CmdBufIn(COLOR_MASK(1,1,1,0));

	CoCmd_LOADIDENTITY;
	CoCmd_SCALE(4*EVE_TRANSFORM_MAX, 4*EVE_TRANSFORM_MAX);
	CoCmd_SETMATRIX;

	HAL_CmdBufIn(BLEND_FUNC(DST_ALPHA,ZERO));
	HAL_CmdBufIn(BITMAP_HANDLE(startHdl+1));
	HAL_CmdBufIn(CELL(1));
	HAL_CmdBufIn(VERTEX2F(X*EVE_PIXEL_UNIT,Y*EVE_PIXEL_UNIT));

	HAL_CmdBufIn(BLEND_FUNC(ONE_MINUS_DST_ALPHA,ONE));
	HAL_CmdBufIn(BITMAP_HANDLE(startHdl+1));
	HAL_CmdBufIn(CELL(0));
	HAL_CmdBufIn(VERTEX2F(X*EVE_PIXEL_UNIT,Y*EVE_PIXEL_UNIT));
    HAL_CmdBufIn(RESTORE_CONTEXT());
}

#if defined(DEF_81X) || defined(DEF_BT81X)
FTVOID appDispPalette8 (FTU32 X, FTU32 Y, FTU32 PalSrc, FTU32 hdl, FTU32 cell)
{
    /* every thing after this commands would not display
       if not use save/restore context */
    HAL_CmdBufIn(SAVE_CONTEXT());
    HAL_CmdBufIn(BITMAP_HANDLE(hdl));
    HAL_CmdBufIn(CELL(cell));

    HAL_CmdBufIn(BLEND_FUNC(ONE, ZERO));
    HAL_CmdBufIn(COLOR_MASK(0,0,0,1));
    HAL_CmdBufIn(PALETTE_SOURCE(PalSrc + 3));
    HAL_CmdBufIn(VERTEX2F(X*EVE_PIXEL_UNIT,Y*EVE_PIXEL_UNIT));

    HAL_CmdBufIn(BLEND_FUNC(DST_ALPHA, ONE_MINUS_DST_ALPHA));
    HAL_CmdBufIn(COLOR_MASK(1,0,0,0));
    HAL_CmdBufIn(PALETTE_SOURCE(PalSrc + 2));
    HAL_CmdBufIn(VERTEX2F(X*EVE_PIXEL_UNIT,Y*EVE_PIXEL_UNIT));

    HAL_CmdBufIn(COLOR_MASK(0,1,0,0));
    HAL_CmdBufIn(PALETTE_SOURCE(PalSrc + 1));
    HAL_CmdBufIn(VERTEX2F(X*EVE_PIXEL_UNIT,Y*EVE_PIXEL_UNIT));

    HAL_CmdBufIn(COLOR_MASK(0,0,1,0));
    HAL_CmdBufIn(PALETTE_SOURCE(PalSrc + 0));
    HAL_CmdBufIn(VERTEX2F(X*EVE_PIXEL_UNIT,Y*EVE_PIXEL_UNIT));

    HAL_CmdBufIn(RESTORE_CONTEXT());
}
#endif

appRet_en appBmpToRamG(FTU32 bmpHdl, FTU32 ramgAddr, bmpHDR_st *pbmpHD, FTU32 nums)
{
    if ((nums + 1) > EVE_BMP_EXT_HANDLE || (bmpHdl + 1) >= EVE_BMP_EXT_HANDLE) {
        /* plus 1 is for in case there is DXT1, need 2 handle for 1 image */
        //__FTPRINT("\nappBmpToRamG: items exceed");
        return APP_ERR_HDL_EXC;
    }

    if (APP_OK != appLoadBmp(ramgAddr,pbmpHD,nums) ) {
        return APP_ERR_LEN;
    }

    appUI_FillBmpDL(bmpHdl, pbmpHD, nums);

    return APP_OK;
}

FTU32 appEveCRC(FTU32 eve_addr, FTU32 len)
{
    FTU32 addr = HAL_Read32(REG_CMD_WRITE), cmd[4];
    /* the result would be saved in co-processor's command buffer
       so need to mark the current offset down
       then do the read out at result offset
       to tell the result*/
    cmd[0] = CMD_MEMCRC;
    cmd[1] = eve_addr;
    cmd[2] = len;
    cmd[3] = 0;
    HAL_CmdExeNow(cmd, 4);
    
    return HAL_Read32(RAM_CMD+addr+4*3);
}
FTVOID appEveZERO(FTU32 eve_addr, FTU32 len)
{
    FTU32 cmd[3];
    cmd[0] = CMD_MEMZERO;
    cmd[1] = eve_addr;
	cmd[2] = len;
    HAL_CmdExeNow(cmd, 3);
}
FTU8 appFlashPath (FTC8 *path, FTU32 *len)
{
#if defined(DEF_BT81X)
    if (!memcmp(path, "ASTC_EVEFLH", L_ASTC_EVEFLH)) {
        appEVEFLHSetFull();
        *len = TYPE_ASTC_FLASH;
        return 1;
    }
    
    if (!memcmp(path, "Z_EVEFLH", L_Z_EVEFLH)) {
        appEVEFLHSetFull();
        *len = TYPE_Z_FLASH;
        return 1;
    }

    if (!memcmp(path, "EVEFLH", L_EVEFLH)) {
        appEVEFLHSetFull();
        *len = TYPE_FLASH;
        return 1;
    }
#endif
    return 0;
}

FTU8 appEVEFLHPath (FTC8 *path, FTU32 *len)
{
#if defined(DEF_BT81X)
	if (!path) {
		//__FTPRINT("\nappEVEFLHAddr: path NULL");
		return 0;
	}

    if (!memcmp(path, "ASTC_EVEFLH", L_ASTC_EVEFLH)) {
        appEVEFLHSetFull();
        *len = TYPE_ASTC_EVEFLH;
        return 1;
    }
    
    if (!memcmp(path, "Z_EVEFLH", L_Z_EVEFLH)) {
        appEVEFLHSetFull();
        *len = TYPE_Z_EVEFLH;
        return 1;
    }

    if (!memcmp(path, "EVEFLH", L_EVEFLH)) {
        appEVEFLHSetFull();
        *len = TYPE_EVEFLH;
        return 1;
    }
	
#endif
	return 0;

}
#if defined(DEF_BT81X)

#if 0
FTU32 appFlashSrcToDes (FTU32 handle, FTU32 src, FTU32 des, FTU32 len, FTU8 update)
{
    FTU32 file_index = src, flash_addr = des, block, l = len;

    if (update) {
        while (l) {
            block = (l > EVE_FLHUPDATE_LEN)?EVE_FLHUPDATE_LEN:l;

            /* read the file into EVE GRAM */
            SegmentOperation(handle, file_index, EVE_FLHUPDATE_ADDR, block, 0);
            
            /* then start update the flash */
            appFlashUpdate(flash_addr, EVE_FLHUPDATE_ADDR, EVE_FLHUPDATE_LEN);

            l -= block;
            file_index += block;
            flash_addr += block;
        }
    } else {
        /* make sure command buffer clean */
        HAL_CmdWait((FTU16)HAL_Read32(REG_CMD_WRITE));

        /* then start sending the command */
        HAL_CmdToReg(CMD_FLASHWRITE);
        HAL_CmdToReg(des);
        HAL_CmdToReg(len);
        SegmentOperation(handle, src, des, len, 1);
    }
    return len;
}
FTU32 appFlashAddr(FTC8 *path)
{
    FTU8 *p = (FTU8 *)path;

    if (p[L_Z_FLASH] == MARK_ADDR) {
        return appGetNumFromStr(&p[L_Z_FLASH+1]);
    } else if (p[L_ASTC_FLASH] == MARK_ADDR) {
        return appGetNumFromStr(&p[L_ASTC_FLASH+1]);
    } else if (p[L_FLASH] == MARK_ADDR) {
        return appGetNumFromStr(&p[L_FLASH+1]);
    } else {
        //__FTPRINT("\nappFlashAddr: addr mark not found");
        return 0;
    }
}
FTU32 appFlashLen(FTC8 *path)
{
    FTU8 *p = (FTU8 *)path;

    if (p[L_Z_FLASH] == MARK_ADDR) {
        p += L_Z_FLASH+1;
    } else if (p[L_ASTC_FLASH] == MARK_ADDR) {
        p += L_ASTC_FLASH+1;
    } else if (p[L_FLASH] == MARK_ADDR) {
        p += L_FLASH+1;
    } else {
        //__FTPRINT("\nappFlashLen: addr mark not found");
        return 0;
    }

    /* it's a internal function
       skip the endless loop check */
    while (*p != MARK_LEN) {
        p++;
    }
    p++;

    return appGetNumFromStr(p);
}
FTVOID appFlashUnzip(FTC8 *path, FTU32 src)
{
    FTU32 cmd[5] = {0};

    cmd[0] = CMD_FLASHSOURCE;
    cmd[1] = appFlashAddr(path);
    cmd[2] = CMD_INFLATE2;
    cmd[3] = src;
    cmd[4] = OPT_FLASH;
    HAL_CmdExeNow(cmd,5);
}
FTU8 appFlashSetFull(FTVOID)
{
    FTU32 addr, a[2];

    if(FLASH_STATUS_FULL == HAL_Read32(REG_FLASH_STATUS)) {
        return 0;
    }
    
    a[0] = CMD_FLASHDETACH;
    HAL_CmdExeNow(a, 1);
    
    a[0] = CMD_FLASHATTACH;
    HAL_CmdExeNow(a, 1);
    
    a[0] = CMD_FLASHFAST;
    a[1] = 0;
    /* the result would be saved in co-processor's command buffer
       so need to mark the current offset down
       then do the read out at result offset
       to tell the result*/
    addr = HAL_Read32(REG_CMD_WRITE);
    HAL_CmdExeNow(a, 2);
    
    switch (HAL_Read32(RAM_CMD+addr+4)) {
        case 0:
            //__FTPRINT("\nFlash: successful set full");
            return 0;
        case 0xE001:
            //__FTPRINT("\nFlash: flash is not supported");
            return 1; 
        case 0xE002:
            //__FTPRINT("\nFlash: no header detected in sector 0");
            return 1; 
        case 0xE003:
            //__FTPRINT("\nFlash: sector 0 data failed integrity check");
            return 1; 
        case 0xE004:
            //__FTPRINT("\nFlash: device/blob mismatch");
            return 1; 
        case 0xE005:
            //__FTPRINT("\nFlash: failed full-speed test");
            return 1; 
        default:
            //__FTPRINT("\nFlash: unknown failure");
            return 1; 
    }
}
FTU8 appFlashToEVE(FTU32 f_addr, FTU32 e_addr, FTU32 len)
{
    FTU32 cmd[4];
    
    if (f_addr % 64 || e_addr % 4 || len % 4) {
        //__FTPRINT("\nappFlashToEVE: input error");
        return 1;
    }

    cmd[0] = CMD_FLASHREAD;
    cmd[1] = e_addr;
    cmd[2] = f_addr;
    cmd[3] = len;
    HAL_CmdExeNow(cmd, 4);

    return 0;
}
FTVOID appFlashErase(FTVOID)
{
    FTU32 cmd = CMD_FLASHERASE;

    HAL_CmdExeNow(&cmd, 1);
}
FTU8 appFlashUpdate(FTU32 f_addr, FTU32 e_addr, FTU32 len)
{
	FTU32 cmd[4];

    if (f_addr % EVE_FLHUPDATE_LEN || e_addr % 4 || len % EVE_FLHUPDATE_LEN) {
        //__FTPRINT("\nappFlashUpdate: input error");
        return 1;
    }

    cmd[0] = CMD_FLASHUPDATE;
    cmd[1] = f_addr;
    cmd[2] = e_addr;
    cmd[3] = len;
    
    HAL_CmdExeNow(cmd, 4);

	return 0;
}
FTU32 appFlashVerify(FTU8 *golden_file, FTU32 f_addr)
{
#define CHECK_NUM   3 //head, middle, tail
#define CHECK_LEN   256
#define CHECK_EVE_TMP  (EVE_RAMG_SIZE - CHECK_LEN)
    FTU8 * pbuf;
    FTU32 crc;
    static FTU8 count;
    static FTU32 resHDL, point, block, Len;

    if (!resHDL) {
        resHDL = HAL_SegFileOpen(golden_file);
        if (resHDL == 0) {
            //__FTPRINT("\nappFlashVerify: file open error");
            return CHECK_NUM|0x80;
        }

        if (f_addr%64) {
            //__FTPRINT("\nappFlashVerify: flash addr error");
            HAL_SegFileClose(resHDL);
            return CHECK_NUM|0x80;
        }

        Len = HAL_SegFileSize(resHDL);
        /* if too small, don't have to pick check point
           just check the first CHECK_LEN*/
        if (Len <= CHECK_NUM*CHECK_LEN) {
            count = 1;
            block = (Len < CHECK_LEN)?(Len - Len%4):Len;
        } else {
            count = CHECK_NUM;
            block = CHECK_LEN;
        }

        point = 0;
    }

    /* read a piece of file to a block */
    pbuf = HAL_LoopMemMalloc(0,0,CHECK_LEN);
    if (HAL_WriteSrcToDes(resHDL,point,(FTU32)pbuf,block) != block) {
        //__FTPRINT("\nappFlashVerify: file read error");
        HAL_SegFileClose(resHDL);
        return count|0x80;
    }
    /* if there is a way to calulate the crc32
       in MCU the same way as EVE (zlib) does
       it would be even better than sending data to eve
       then do the crc32, but I don't found any
       convenience way to do so...

       send that piece of file to EVE for CRC
     */
    HAL_Write8Src(CHECK_EVE_TMP, pbuf, block);
    HAL_LoopMemFree((FTU32)pbuf);
    crc = appEveCRC(CHECK_EVE_TMP, block);
    /* clear the temp space in EVE */
    appEveZERO(CHECK_EVE_TMP, block);

    /* read a piece of flash to EVE */
    if (appFlashToEVE(f_addr+point, CHECK_EVE_TMP, block)) {
        //__FTPRINT("\nappFlashVerify: fail to write to eve");
        return count|0x80;
    }

    /* do CRC in EVE and compare the CRC with file piece*/
    if (crc != appEveCRC(CHECK_EVE_TMP, block)) {
        //__FTPRINT("\nappFlashVerify: crc not match");
        HAL_SegFileClose(resHDL);
        return count|0x80;
    }

    count--;

    if (count == 2) {
        /* check the middle of the body, skip the none 64 align part */
        point = (Len - CHECK_LEN)/2 - ((Len - CHECK_LEN)/2)%64;
    } else if (count == 1) {
        /* check the tail of the body, skip the none 64 align part */
        point = (Len - CHECK_LEN) - (Len - CHECK_LEN)%64;
    } else {
        HAL_SegFileClose(resHDL);
        resHDL = 0;
    }

    return count;
}

FTU32 appFlashProgProgress(FTU8 *f_file, FTU32 f_addr, FTU32 block, FTU8 update)
{
    static FTU32 resHDL = 0, Len = 0, f_addr_index = 0;
    FTU32 piece = 0;

    if (!Len || !resHDL) {
        resHDL = HAL_SegFileOpen(f_file);
        if (resHDL == 0) {
            //__FTPRINT("\nappFlashProgProgress: file open error");
            resHDL = 0;
            Len = 0;
            return 0;
        }

        /* if the original file length not 256 byte align
           it would pad some extra bytes at the tail*/
        Len = HAL_SegFileSize(resHDL);
        
        if (update) {
            if (f_addr%EVE_FLHUPDATE_LEN) {
                //__FTPRINT("\nappFlashProgProgress: file addr error");
                HAL_SegFileClose(resHDL);
                return 0;
            }
        } else {
            if (f_addr%256) {
                //__FTPRINT("\nappFlashProgProgress: file addr error");
                HAL_SegFileClose(resHDL);
                resHDL = 0;
                Len = 0;
                return 0;
            }

            Len += Len%256?(256 - Len%256):0;
        }

        f_addr_index = f_addr;
    }

    if (!block) {
        block = Len;
    }
    piece = f_addr_index - f_addr;
    piece = Len - piece;
    if (piece > block) {
        piece = block;
    }

    if (appFlashSrcToDes(resHDL,0, f_addr_index, piece, update) != piece) {
        //__FTPRINT("\nappFlashProgProgress: file program error");
        HAL_SegFileClose(resHDL);
        resHDL = 0;
        Len = 0;
        return 0;
    }
        
    f_addr_index += piece;
    piece = f_addr_index - f_addr;
	piece = (piece * 100) / Len;
    
	if (piece == 100) {
		HAL_SegFileClose(resHDL);
		resHDL = 0;
		Len = 0;
	}
    return piece?piece:1;
}

#endif

FTU32 appEVEFLHSrcToDes (FTU32 handle, FTU32 src, FTU32 des, FTU32 len, FTU8 update)
{
    FTU32 file_index = src, flash_addr = des, block, l = len;

    if (update) {
        while (l) {
            block = (l > EVE_FLHUPDATE_LEN)?EVE_FLHUPDATE_LEN:l;

            /* read the file into EVE GRAM */
            SegmentOperation(handle, file_index, EVE_FLHUPDATE_ADDR, block, 0);
            
            /* then start update the flash */
            appEVEFLHUpdate(flash_addr, EVE_FLHUPDATE_ADDR, EVE_FLHUPDATE_LEN);

            l -= block;
            file_index += block;
            flash_addr += block;
        }
    } else {
        /* make sure command buffer clean */
        HAL_CmdWait((FTU16)HAL_Read32(REG_CMD_WRITE));

        /* then start sending the command */
        HAL_CmdToReg(CMD_FLASHWRITE);
        HAL_CmdToReg(des);
        HAL_CmdToReg(len);
        SegmentOperation(handle, src, des, len, 1);
    }
    return len;
}
FTU32 appEVEFLHAddr(FTC8 *path)
{
    FTU8 *p = (FTU8 *)path;

    if (p[L_Z_EVEFLH] == MARK_ADDR) {
        p += L_Z_EVEFLH+1;
    } else if (p[L_ASTC_EVEFLH] == MARK_ADDR) {
        p += L_ASTC_EVEFLH+1;
    } else if (p[L_EVEFLH] == MARK_ADDR) {
        p += L_EVEFLH+1;
    } else {
        //__FTPRINT("\nappEVEFLHAddr: addr mark not found");
        return 0;
    }

    /* in case any space between ':' and number */
    while (*p < '0' || *p > '9') {
        p++;
    }

    return appGetNumFromStr(p);
}
FTU32 appEVEFLHLen(FTC8 *path)
{
    FTU8 *p = (FTU8 *)path;

    if (p[L_Z_EVEFLH] == MARK_ADDR) {
        p += L_Z_EVEFLH +1;
    } else if (p[L_ASTC_EVEFLH] == MARK_ADDR) {
        p += L_ASTC_EVEFLH +1;
    } else if (p[L_EVEFLH] == MARK_ADDR) {
        p += L_EVEFLH +1;
    } else {
        //__FTPRINT("\nappEVEFLHLen: addr mark not found");
        return 0;
    }

    /* it's a internal function
       skip the endless loop check */
    while (*p != MARK_LEN) {
        p++;
    }
    p++;
    /* in case any space between ':' and number */
    while (*p < '0' || *p > '9') {
        p++;
    }

    return appGetNumFromStr(p);
}
FTVOID appEVEFLHUnzip(FTC8 *path, FTU32 src)
{
    FTU32 cmd[5] = {0};

    cmd[0] = CMD_FLASHSOURCE;
    cmd[1] = appEVEFLHAddr(path);
    cmd[2] = CMD_INFLATE2;
    cmd[3] = src;
    cmd[4] = OPT_FLASH;
    HAL_CmdExeNow(cmd,5);
}
FTU8 appEVEFLHSetFull(FTVOID)
{
    FTU32 addr, a[2];

    if(FLASH_STATUS_FULL == HAL_Read32(REG_FLASH_STATUS)) {
        return 0;
    }
    
    a[0] = CMD_FLASHDETACH;
    HAL_CmdExeNow(a, 1);
    
    a[0] = CMD_FLASHATTACH;
    HAL_CmdExeNow(a, 1);
    
    a[0] = CMD_FLASHFAST;
    a[1] = 0;
    /* the result would be saved in co-processor's command buffer
       so need to mark the current offset down
       then do the read out at result offset
       to tell the result*/
    addr = HAL_Read32(REG_CMD_WRITE);
    HAL_CmdExeNow(a, 2);
    
    switch (HAL_Read32(RAM_CMD+addr+4)) {
        case 0:
            //__FTPRINT("\nEVEFLH: successful set full");
            return 0;
        case 0xE001:
            //__FTPRINT("\nEVEFLH: flash is not supported");
            return 1; 
        case 0xE002:
            //__FTPRINT("\nEVEFLH: no header detected in sector 0");
            return 1; 
        case 0xE003:
            //__FTPRINT("\nEVEFLH: sector 0 data failed integrity check");
            return 1; 
        case 0xE004:
            //__FTPRINT("\nEVEFLH: device/blob mismatch");
            return 1; 
        case 0xE005:
            //__FTPRINT("\nEVEFLH: failed full-speed test");
            return 1; 
        default:
            //__FTPRINT("\nEVEFLH: unknown failure");
            return 1; 
    }
}
FTU8 appEVEFLHToEVE(FTU32 f_addr, FTU32 e_addr, FTU32 len)
{
    FTU32 cmd[4];
    
    if (f_addr % 64 || e_addr % 4 || len % 4 || len == 0) {
        //__FTPRINT("\nappEVEFLHToEVE: input error");
        return 1;
    }

    cmd[0] = CMD_FLASHREAD;
    cmd[1] = e_addr;
    cmd[2] = f_addr;
    cmd[3] = len;
    HAL_CmdExeNow(cmd, 4);

    return 0;
}
FTVOID appEVEFLHErase(FTVOID)
{
    FTU32 cmd = CMD_FLASHERASE;

    HAL_CmdExeNow(&cmd, 1);
}
FTU8 appEVEFLHUpdate(FTU32 f_addr, FTU32 e_addr, FTU32 len)
{
	FTU32 cmd[4];

    if (f_addr % EVE_FLHUPDATE_LEN || e_addr % 4 || len % EVE_FLHUPDATE_LEN || len == 0) {
        //__FTPRINT("\nappEVEFLHUpdate: input error");
        return 1;
    }

    cmd[0] = CMD_FLASHUPDATE;
    cmd[1] = f_addr;
    cmd[2] = e_addr;
    cmd[3] = len;
    
    HAL_CmdExeNow(cmd, 4);

	return 0;
}
FTU32 appEVEFLHVerify(FTU8 *golden_file, FTU32 f_addr)
{
#define CHECK_NUM   3 //head, middle, tail
#define CHECK_LEN   256
#define CHECK_EVE_TMP  (EVE_RAMG_SIZE - CHECK_LEN)
    FTU8 * pbuf;
    FTU32 crc;
    static FTU8 count;
    static FTU32 resHDL, point, block, Len;

    if (!resHDL) {
        resHDL = HAL_SegFileOpen(golden_file);
        if (resHDL == 0) {
            //__FTPRINT("\nappEVEFLHVerify: file open error");
            return CHECK_NUM|0x80;
        }

        if (f_addr%64) {
            //__FTPRINT("\nappEVEFLHVerify: flash addr error");
            HAL_SegFileClose(resHDL);
            return CHECK_NUM|0x80;
        }

        Len = HAL_SegFileSize(resHDL);
        /* if too small, don't have to pick check point
           just check the first CHECK_LEN*/
        if (Len <= CHECK_NUM*CHECK_LEN) {
            count = 1;
            block = (Len < CHECK_LEN)?(Len - Len%4):Len;
        } else {
            count = CHECK_NUM;
            block = CHECK_LEN;
        }

        point = 0;
    }

    /* read a piece of file to a block */
    pbuf = HAL_LoopMemMalloc(0,0,CHECK_LEN);
    if (HAL_WriteSrcToDes(resHDL,point,(FTU32)pbuf,block) != block) {
        //__FTPRINT("\nappEVEFLHVerify: file read error");
        HAL_SegFileClose(resHDL);
        return count|0x80;
    }
    /* if there is a way to calulate the crc32
       in MCU the same way as EVE (zlib) does
       it would be even better than sending data to eve
       then do the crc32, but I don't found any
       convenience way to do so...

       send that piece of file to EVE for CRC
     */
    HAL_Write8Src(CHECK_EVE_TMP, pbuf, block);
    HAL_LoopMemFree((FTU32)pbuf);
    crc = appEveCRC(CHECK_EVE_TMP, block);
    /* clear the temp space in EVE */
    appEveZERO(CHECK_EVE_TMP, block);

    /* read a piece of flash to EVE */
    if (appEVEFLHToEVE(f_addr+point, CHECK_EVE_TMP, block)) {
        //__FTPRINT("\nappEVEFLHVerify: fail to write to eve");
        return count|0x80;
    }

    /* do CRC in EVE and compare the CRC with file piece*/
    if (crc != appEveCRC(CHECK_EVE_TMP, block)) {
        //__FTPRINT("\nappEVEFLHVerify: crc not match");
        HAL_SegFileClose(resHDL);
        return count|0x80;
    }

    count--;

    if (count == 2) {
        /* check the middle of the body, skip the none 64 align part */
        point = (Len - CHECK_LEN)/2 - ((Len - CHECK_LEN)/2)%64;
    } else if (count == 1) {
        /* check the tail of the body, skip the none 64 align part */
        point = (Len - CHECK_LEN) - (Len - CHECK_LEN)%64;
    } else {
        HAL_SegFileClose(resHDL);
        resHDL = 0;
    }

    return count;
}

FTU32 appEVEFLHProgProgress(FTU8 *f_file, FTU32 f_addr, FTU32 block, FTU8 update)
{
    static FTU32 resHDL = 0, Len = 0, f_addr_index = 0;
    FTU32 piece = 0;

    if (!Len || !resHDL) {
        resHDL = HAL_SegFileOpen(f_file);
        if (resHDL == 0) {
            //__FTPRINT("\nappEVEFLHProgProgress: file open error");
            resHDL = 0;
            Len = 0;
            return 0;
        }

        /* if the original file length not 256 byte align
           it would pad some extra bytes at the tail*/
        Len = HAL_SegFileSize(resHDL);
        
        if (update) {
            if (f_addr%EVE_FLHUPDATE_LEN) {
                //__FTPRINT("\nappEVEFLHProgProgress: file addr error");
                HAL_SegFileClose(resHDL);
                return 0;
            }
        } else {
            if (f_addr%256) {
                //__FTPRINT("\nappEVEFLHProgProgress: file addr error");
                HAL_SegFileClose(resHDL);
                resHDL = 0;
                Len = 0;
                return 0;
            }

            Len += Len%256?(256 - Len%256):0;
        }

        f_addr_index = f_addr;
    }

    if (!block) {
        block = Len;
    }
    piece = f_addr_index - f_addr;
    piece = Len - piece;
    if (piece > block) {
        piece = block;
    }

    if (appEVEFLHSrcToDes(resHDL,0, f_addr_index, piece, update) != piece) {
        //__FTPRINT("\nappEVEFLHProgProgress: file program error");
        HAL_SegFileClose(resHDL);
        resHDL = 0;
        Len = 0;
        return 0;
    }
        
    f_addr_index += piece;
    piece = f_addr_index - f_addr;
	piece = (piece * 100) / Len;
    
	if (piece == 100) {
		HAL_SegFileClose(resHDL);
		resHDL = 0;
		Len = 0;
	}
    return piece?piece:1;
}

#endif
/*
 * You may do this bitmap related display list setup here
 * or do it in your own routine
 * all base on your actual application needed
 * it just one of the way to tell the EVE about bitmap information
 */
FTVOID appUI_FillBmpDL(FTU32 bmpHdl, bmpHDR_st *pbmpHD, FTU32 nums)
{
	FTU32 i, src, hdl;

	HAL_CmdBufIn(CMD_DLSTART); //会�?�致屏显示清除，屏蔽会�?�致拷贝不成�?
	
	for (i = 0, hdl = bmpHdl; i < nums; i++) {
		switch (pbmpHD[i].format) {
			case PALETTED8:
			case PALETTED565:
			case PALETTED4444:
			case PALETTED:
				((ImgInfoPal_st *)pbmpHD[i].info)->handle = hdl + i;
				src = ((ImgInfoPal_st *)pbmpHD[i].info)->addr_inx;
				BmpInfo(hdl + i,pbmpHD[i].format,appGetLinestride(&pbmpHD[i]),src,pbmpHD[i].wide,pbmpHD[i].high);
				break;
			case FORMAT_DXT1:
				((ImgInfoDXT1_st *)pbmpHD[i].info)->handle = hdl + i;
				src = ((ImgInfoDXT1_st *)pbmpHD[i].info)->addr;
				DXT1BmpInfo(hdl + i,src,pbmpHD[i].wide,pbmpHD[i].high);
				/* one DXT1 image need two handle */
				hdl += 1;
				break;
			default:
				((ImgInfo_st *)pbmpHD[i].info)->handle = hdl + i;
				src = ((ImgInfo_st *)pbmpHD[i].info)->addr;
				BmpInfo(hdl + i,pbmpHD[i].format,appGetLinestride(&pbmpHD[i]),src,pbmpHD[i].wide,pbmpHD[i].high);
				break;
		}
	}

	HAL_CmdBufIn(DISPLAY());
	HAL_CmdBufIn(CMD_SWAP);
	HAL_BufToReg(RAM_CMD,0);
}

STATIC FTU8 appUI_GetEVEID (FTVOID)
{
    /* for FT81X and later, recommended to 
       read 1 bytes data from address EVE_ID_REG 
       before application overwrites this address,
       since it is located in RAM_G. */
    READ_ID = HAL_Read8(EVE_ID_REG);
    //__FTPRINT("\nChip: ");
    switch (READ_ID) {
        case 0x10:
            //__FTPRINT("FT810");
#if defined(EVE_DEF_CHECK) && !defined(DEF_81X)
            //__FTPRINT("\nDemo not for this chip");
            return 0;
#else
            return 1;
#endif
        case 0x11:
            //__FTPRINT("FT811");
#if defined(EVE_DEF_CHECK) && !defined(DEF_81X)
            //__FTPRINT("\nDemo not for this chip");
            return 0;
#else
            return 1;
#endif
        case 0x12:
            //__FTPRINT("FT812");
#if defined(EVE_DEF_CHECK) && !defined(DEF_81X)
            //__FTPRINT("\nDemo not for this chip");
            return 0;
#else
            return 1;
#endif
        case 0x13:
            //__FTPRINT("FT813");
#if defined(EVE_DEF_CHECK) && !defined(DEF_81X)
            //__FTPRINT("\nDemo not for this chip");
            return 0;
#else
            return 1;
#endif
        case 0x15:
            //__FTPRINT("BT815");
#if defined(EVE_DEF_CHECK) && !defined(DEF_BT81X)
            //__FTPRINT("\nDemo not for this chip");
            return 0;
#else
            return 1;
#endif
        case 0x16:
            //__FTPRINT("BT816");
#if defined(EVE_DEF_CHECK) && !defined(DEF_BT81X)
            //__FTPRINT("\nDemo not for this chip");
            return 0;
#else
            return 1;
#endif
        default:
            /* only new FT81X able to read the EVE ID */
            //__FTPRINT("EVE");
#if defined(EVE_DEF_CHECK) && !defined(DEF_80X)
            //__FTPRINT("\nDemo not for this chip");
            return 0;
#else
            return 1;
#endif
    }
}

STATIC FTVOID appUI_EVEPathCfg ( FTVOID )
{
    /*
     it's nothing to do with EVE
     I just put some related preparation action
     you may handle this things some other place
     */
    HAL_preparation();

    /* 
     do the data buffering base on your system
     you may even not do the buffering before sending out the data
     it just an example, you may do it in your own way
     */
    HAL_McuCmdBufInit();
    
    /* 
     1.the SPI clock shall not exceed 11MHz before system clock is enabled. 
       After system clock is properly enabled, 
       the SPI clock is allowed to go up to 30MHz.
       
     2.if you going to send 4 bytes, after pull low the CS,
       pull high the CS after all 4 bytes finish
       if you going to send 100 bytes,
       pull high the CS after all 100 bytes finish
     */
    HAL_SpiInit();
}

STATIC FTVOID appUI_EVEActive ( FTVOID )
{
    HAL_Cfg(FT_GPU_ACTIVE_M);
    FTDELAY(2);
#if defined(DEF_81X) || defined(DEF_BT81X)
    /* 81X need more action for the active */
    HAL_Cfg(FT_GPU_ACTIVE_M);
#endif

    /* 
     it's important to wait enough long 
     for the EVE to active
     */
    FTDELAY(150);//___(300);
}

STATIC FTVOID appUI_EVEClk ( FTVOID )
{
    //__FTPRINT("\nOSC: ");
#if defined(TRIM_NEEDED)
    //__FTPRINT("internal");
#else
    ////__FTPRINT("external");
    /* Set the clk to external clock */
    HAL_Cfg(FT_GPU_INTERNAL_OSC);  
#endif
#if !defined(DEF_81X) && !defined(DEF_BT81X)
    /* default 48MHz, no need to config
    HAL_Cfg(FT_GPU_PLL_48M);  
    */

    /* for BT81X, you may select EVE system clock
    HAL_Cfg(FT_GPU_SLEEP_M); 
    FTDELAY(50);
    HAL_Cfg3(GPU_SYSCLK_72M);
    FTDELAY(50);
    HAL_Cfg(FT_GPU_ACTIVE_M);
    FTDELAY(50);
    */
#endif
    FTDELAY(CLK_DELAY);
}

STATIC FTVOID appUI_EVEGPIOCfg ( FTVOID )
{
    /* set DISP to output, then enable the DISP */
#if defined(DEF_81X) || defined(DEF_BT81X)
    /*
       Bit 31-16: Reserved
       Bit 15 : Controlling the direction of pin DISP. For DISP functionality, this bit
       shall be kept intact.
       Bit 14-4: Reserved
       Bit 3-0: Controlling the direction of pin GPIO 3-0. (1 = output, 0 = input)
       For FT810/811, only GPIO 1-0 are available. For FT812/813, GPIO 3-0 are
       available.
     */
    HAL_Write16(REG_GPIOX_DIR,0x800F);
    /*
       Bit 31-16: Reserved
       Bit 15 : Setting or reading the level of pin DISP. 1 for high and 0 for low
       Bit 14-13:GPIO[3:0], TOUCHWAKE Drive Strength Setting
       (00:5mA - default, 01:10mA, 10:15mA, 11:20mA)
       Bit 12:PCLK, DISP, V/HSYNC, DE, R,G,B, BACKLIGHT Drive Strength Setting
       (0:5mA - default, 1:10mA)
       Bit 11 - 10:MISO, MOSI, IO2, IO3, INT_N Drive Strength Setting
       (00:5mA - default, 01:10mA, 10:15mA, 11:20mA)
       Bit 9: INT_N Type
       (0 : OD - default, 1 : Push-pull)
       Bit 8-4: Reserved
       Bit 3-0: Writing or reading the pin of GPIO 3-0. 1 for high and 0 for low.
       For FT810/811, only GPIO 1-0 are available. For FT812/813, GPIO 3-0 are available.
     */
    HAL_Write16(REG_GPIOX,0x800F);
#else
    /*
       Bit 0 - 7 : These bits configure the direction of GPIO pins of the EVE. Bit 0 controls
       the direction of GPIO0 and Bit 7 controls the direction of GPIO7. The bit value 1
       means the GPIO pin is set as an output, otherwise it means an input. After reset, only
       the GPIO7 is set to output by default.
     */
    HAL_Write8(REG_GPIO_DIR,0xFF);
    /*
       Bit 0 - 7 : These bits are versatile. Bit 0 , 1, 7 are used to control GPIO pin values.
       Bit 2 - 6 : These are used to configure the drive strength of the pins.
     */
    HAL_Write8(REG_GPIO,0xFF);
#endif

    /* mute sound to avoid pop sound */
    HAL_Write16(REG_SOUND,0x0060);
    HAL_Write8(REG_PLAY,0x01);
    while(HAL_Read8(REG_PLAY));
}

/*
 * Add the FT81X support, with the CTP controller
 * you may change the delay time base on your own HW and CTP
 */
STATIC FTVOID appUI_EVETchCfg ( FTVOID )
{
#if defined(DEF_CAP_NONMULTI) || defined(DEF_CAP_MULTI)
    FTDELAY(150);//___(300);
    HAL_Write8(REG_CPURESET, 2);
    FTDELAY(150);//___(300);
#ifdef DEF_GOODIX
    /* for Goodix touch panel, I don't know why */
    HAL_Write16(REG_CYA_TOUCH,0x05D0);
#else
    HAL_Write16(REG_CYA_TOUCH,(HAL_Read16(REG_CYA_TOUCH) & 0x7fff));
#endif
    FTDELAY(150);//___(300);
    HAL_Write8(REG_CPURESET, 0);
    FTDELAY(150);//___(300);

#ifdef DEF_CAP_MULTI
    HAL_Write8(REG_CTOUCH_EXTENDED,CTOUCH_MODE_EXTENDED);
#endif

#else
    /*
     * for this code, I consider "resistance touch" + "WVGA" 
     * means using FTDI WH70R, it use default touch threshold: 
     * the lightest touch will be accepted
     * you may change it depends on your real system
     */
#if !defined(LCD_WVGA)
    HAL_Write16(REG_TOUCH_RZTHRESH,EVE_TOUCH_THRESHOLD);
#endif
    HAL_Write16(REG_CYA_TOUCH,(HAL_Read16(REG_CYA_TOUCH) | 0x8000));
#endif
}
STATIC FTVOID appUI_EVESetSPI (FTU32 type)
{
    //__FTPRINT("\nSPI: ");
#if defined(DEF_81X) || defined(DEF_BT81X)
    if (type == 4) {
        HAL_Write8(REG_SPI_WIDTH, EVE_QSPI | EVE_SPI_DUMMY);
        //__FTPRINT("Quad");
    } else if (type == 2) {
        HAL_Write8(REG_SPI_WIDTH, EVE_DSPI | EVE_SPI_DUMMY);
        //__FTPRINT("Dual");
    } else {
        HAL_Write8(REG_SPI_WIDTH, EVE_SSPI);
        //__FTPRINT("Single");
    }

    //HAL_speed_up(type);
#else
    //__FTPRINT("Single");
#endif
}
#if defined(CAL_NEEDED)
#define VER_FONT 25
#define CAL_FONT 20
#define CAL_WIDE 15
#define SYS_HANG (0)
STATIC FTVOID appUI_EVEBootupDisp ( FTU32 count )
{
    do {
        HAL_CmdBufIn(CMD_DLSTART);
        HAL_CmdBufIn(CLEAR_COLOR_RGB(0,0,0));
        HAL_CmdBufIn(CLEAR(1,1,1));

        switch (READ_ID) {
            case 0x10:
                CoCmd_TEXT(EVE_LCD_WIDTH/3,EVE_LCD_HIGH/4,
                        VER_FONT,OPT_CENTERX,"FT810");
                break;
            case 0x11:
                CoCmd_TEXT(EVE_LCD_WIDTH/3,EVE_LCD_HIGH/4,
                        VER_FONT,OPT_CENTERX,"FT811");
                break;
            case 0x12:
                CoCmd_TEXT(EVE_LCD_WIDTH/3,EVE_LCD_HIGH/4,
                        VER_FONT,OPT_CENTERX,"FT812");
                break;
            case 0x13:
                CoCmd_TEXT(EVE_LCD_WIDTH/3,EVE_LCD_HIGH/4,
                        VER_FONT,OPT_CENTERX,"FT813");
                break;
            case 0x15:
                CoCmd_TEXT(EVE_LCD_WIDTH/3,EVE_LCD_HIGH/4,
                        VER_FONT,OPT_CENTERX,"BT815");
                break;
            case 0x16:
                CoCmd_TEXT(EVE_LCD_WIDTH/3,EVE_LCD_HIGH/4,
                        VER_FONT,OPT_CENTERX,"BT816");
                break;
            default:
                /* only new FT81X able to read the EVE ID */
                CoCmd_TEXT(EVE_LCD_WIDTH/3,EVE_LCD_HIGH/4,
                        VER_FONT,OPT_CENTERX,"EVE Chip");
                break;
        }
#if defined(DEF_CAP_MULTI)
        CoCmd_TEXT(EVE_LCD_WIDTH/3*2,EVE_LCD_HIGH/4,
                VER_FONT,OPT_CENTERX,"CAP-M");
#elif defined(DEF_CAP_NONMULTI)
        CoCmd_TEXT(EVE_LCD_WIDTH/3*2,EVE_LCD_HIGH/4,
                VER_FONT,OPT_CENTERX,"CAP-NM");
#else
        CoCmd_TEXT(EVE_LCD_WIDTH/3*2,EVE_LCD_HIGH/4,
                VER_FONT,OPT_CENTERX,"RES");
#endif
        CoCmd_TEXT(EVE_LCD_WIDTH/2,EVE_LCD_HIGH/2,
                VER_FONT,OPT_CENTERX,"Ver: "APPS_VER);
        CoCmd_TEXT(EVE_LCD_WIDTH/2-10,EVE_LCD_HIGH/4*3,
                CAL_FONT,OPT_CENTERX,"MCU CMD Buf: ");
        CoCmd_NUMBER(EVE_LCD_WIDTH/2+40,EVE_LCD_HIGH/4*3,
                CAL_FONT,OPT_CENTERX,HAL_CmdBufSize());
        
        if (SYS_HANG) {
            CoCmd_TEXT(EVE_LCD_WIDTH/2,EVE_LCD_HIGH - CAL_WIDE*2,
                    CAL_FONT,OPT_CENTERX,"system hange due to memory limit!");
        } else {
            CoCmd_TEXT(EVE_LCD_WIDTH/2,EVE_LCD_HIGH - CAL_WIDE*2,
                    CAL_FONT,OPT_CENTERX,"press and hold to force in calibration");
            CoCmd_NUMBER(EVE_LCD_WIDTH/2,EVE_LCD_HIGH - CAL_WIDE,
                    CAL_FONT,OPT_CENTERX,count);
        }

        HAL_CmdBufIn(DISPLAY());
        HAL_CmdBufIn(CMD_SWAP);
        HAL_BufToReg(RAM_CMD,0);
    } while (SYS_HANG);
}
#endif
#if defined(TRIM_NEEDED)
STATIC FTU32 appUI_EVEGetFrq (FTVOID)
{
    FTU32 t0, t1;
    FT32 r = 15625;

    t0 = HAL_Read32(REG_CLOCK); /* t0 read */

    FTUDELAY(r);

    t1 = HAL_Read32(REG_CLOCK); /* t1 read */
    /* bitshift 6 places is the same as multiplying 64 */
    return ((t1 - t0) * 64); 
}
#endif
STATIC FTVOID appUI_EVEClkTrim ( FTVOID )
{
#if defined(TRIM_NEEDED)
#define LOW_FREQ_BOUND  58800000L//98% of 60Mhz
    FTU32 f;
    FTU8 i;
    /* Trim the internal clock by increase the REG_TRIM register
       till the measured frequency is within the acceptable range.*/
    for (i=0; (i < 31) && ((f= appUI_EVEGetFrq()) < LOW_FREQ_BOUND); i++)
    {
        /* increase the REG_TRIM register value 
           automatically increases the internal clock */
        HAL_Write8(REG_TRIM, i);  
    }
    /* Set the final frequency to be used for internal operations */
    HAL_Write32(REG_FREQUENCY,f);  
#endif
}
STATIC FTVOID appUI_EVELCDCfg ( FTVOID )
{
    /* 
       PCLK is critical,
       sometime it may need to set to larger number (2,3)
       some smaller number (set to 1), may case under run issue 
       while too much commands needs to be executed
     */
    EVE_LCD lcd = {EVE_LCD_WIDTH,EVE_LCD_HIGH, 
        /*
           HCycle HOffset HSync0 HSync1 
           VCycle VOffset VSync0 VSync1 
           PCLK Swizzle PCLKPol Cspread Dither
         */
#if defined(LCD_WXGA)
        1440,38,0,16,
        838,8,0,2,
        1,0,0,0,0};
#elif defined(LCD_WVGA)
        /* 
        this setting seems better than SampleApp (below)
        setting in some project
        1058,40,0,20,
        525,25,0,10,
         */
//        928,88,0,48, 
//        525,32,0,3, 
//        2,0,1,0,1};
        928,88,0,48, 
		525,32,0,3, 
        2,0,1,0,1};
                                                                    
//#define  HT  525	  //Horizontal total period = (HT + 1) pixels
//#define  HPS 43	  //Horizontal Sync Pulse Start Position = (HPS + 1) pixels	 		 
//#define  LPS 1	  //Horizontal Display Period Start Position = LPS pixels		
//#define  HPW 0   //Horizontal Sync Pulse Width = (HPW + 1) pixels	

//#define  VT 859	 //Vertical Total = (VT + 1) lines
//#define  VPS 4  //Vertical Sync Pulse Start Position = VPS lines					  
//#define  FPS 0   //Vertical Display Period Start Position = FPS lines				  
//#define  VPW 0  //Vertical Sync Pulse Width = (VPW + 1) lines

#elif defined(LCD_QVGA)
        408,70,0,10, 
        263,13,0, 2, 
        8,2,0,1,1};
#elif defined(LCD_HVGA)
        400,40,0,10, 
        500,10,0, 5, 
        5,2,1,1,1}; //for ME810A_HV35R pclk is 5
#elif defined(LCD_WQVGA)
        548,43,0,41, 
        292,12,0,10, 
        5,0,1,1,1};
#else
#error "undefined LCD"
#endif

    /* config the LCD related parameters */
    HAL_Write16(REG_HSIZE, lcd.Width);  //800
    HAL_Write16(REG_VSIZE, lcd.Height); //480
    HAL_Write16(REG_HCYCLE, lcd.HCycle); //928
    HAL_Write16(REG_HOFFSET, lcd.HOffset); //88
    HAL_Write16(REG_HSYNC0, lcd.HSync0);   //0
    HAL_Write16(REG_HSYNC1, lcd.HSync1);   //48
    HAL_Write16(REG_VCYCLE, lcd.VCycle);   //525
    HAL_Write16(REG_VOFFSET, lcd.VOffset); //32
    HAL_Write16(REG_VSYNC0, lcd.VSync0);   //0
    HAL_Write16(REG_VSYNC1, lcd.VSync1);   //3
    HAL_Write8(REG_SWIZZLE, lcd.Swizzle);  //0
    HAL_Write8(REG_PCLK_POL, lcd.PCLKPol); //1
    HAL_Write16(REG_CSPREAD, lcd.Cspread); //0
    HAL_Write16(REG_DITHER, lcd.Dither);   

    /* the backlight default is highest 
    HAL_Write8(REG_PWM_DUTY,128);
    */

    /* the RGB output default is 6x6x6 
        R:8,7,6
        G:5,4,3
        B:2,1,0
        0x000 stands for 8x8x8x
        default:
        FT810/1: 0x1B6(6x6x6)
        FT812/3: 0    (8x8x8)
        BT815/6: 0    (8x8x8)
     */
#if defined(LCD_18BITS)
    HAL_Write32(REG_OUTBITS,0x1B6);
#else 
    HAL_Write32(REG_OUTBITS,0);
#endif

#if defined(LCD_HVGA)
    HAL_ili9488();
#endif

    /* start to display */
    HAL_Write8(REG_PCLK,lcd.PCLK); //1

#if defined(DEF_BT81X)
    /* if you want to enable adaptive frame rate 
    set it to 1*/
    HAL_Write8(REG_ADAPTIVE_FRAMERATE, 0);
#endif
}
unsigned int yaa;

STATIC FTU8 appUI_EVEVerify (FTVOID)
{
    FTU8 count = RETRY_COUNT;

    ////__FTPRINT("\nVerify: ");
    yaa=HAL_Read8(REG_ID);
    while ((yaa!= EVE_ID ||HAL_Read8(REG_CPURESET)) &&count) 
    {
        ////__FTPRINT(".");
        count--;
        FTDELAY(READ_ID_WAIT);
    }
    #if 0
    while ((HAL_Read8(REG_ID) != EVE_ID ||
           HAL_Read8(REG_CPURESET)) &&
           count) {
        ////__FTPRINT(".");
        count--;
        FTDELAY(READ_ID_WAIT);
    }
    #endif

    if (count) {
        return appUI_GetEVEID();
    } else {
        return count;
    }
}

STATIC FTVOID appUI_EVEClnScrn (FTVOID)
{
    HAL_CmdBufIn(CMD_DLSTART);
    HAL_CmdBufIn(CLEAR_COLOR_RGB(0,255,0));
    HAL_CmdBufIn(CLEAR(1,1,1));
    HAL_CmdBufIn(DISPLAY());
    HAL_CmdBufIn(CMD_SWAP);
    HAL_BufToReg(RAM_CMD,0);
}

STATIC appRet_en appUI_WaitCal (FTVOID)
{
//#if defined(CAL_NEEDED)
//    FTU8 i = 0;
//    appRet_en ret;

//    /* Cal would judge whether it should do the calibration or not  */
//    do {
//        /* keep doing the calibration until it success */
//        ret = appCal(i,CDATA_PATH);
//    } while (ret != APP_OK);

//    /* wait for a while, 
//     * let user decide if need to force calibration
//     * or see some debug information */
//    i = FORCE_WAIT_COUNT;
//    while (!TOUCHED) {
//        appUI_EVEBootupDisp(i);

//        FTDELAY(FORCE_WAIT_TIME);
//        if (0 == --i) {
//            break;
//        }
//    }

//    /* deciede to do the calibration or not depend on user's input */
//    if (i) {
//        /* into the calibration, after press released */
//        while (TOUCHED) {
//            FTDELAY(FORCE_WAIT_TIME);
//        }
//        do {
//            /* keep doing the calibration until it success */
//            ret = appCal(i,CDATA_PATH);
//        } while (ret != APP_OK);
//    }
//#endif
    appUI_EVEClnScrn();
    return APP_OK; 
}


FTVOID appUI_EVEBeforeLaunch(FTVOID)
{
#if defined(DEF_BT81X)
    // clean up the error report area
	HAL_Write8(RAM_ERR_REPORT, 0);
#endif    
}
FTVOID UI_INIT (FTVOID)
{


    
    
    
    /* 
     there are some basic hardware related init in it
     such as SPI interface init
     */
    
    appUI_EVEPathCfg();
    
    /* 
     PD pin has to be pull high.
     */
    
    HAL_PwdCyc(1); // 105ms
    
    appUI_EVEClk(); //200ms
    
    appUI_EVEActive(); //300ms
    
    
    
    /* 
     you should be able to see the clock in X1/X2 pin here
     if not, you will never read the ChipID
     there is some problem above (power, SPI, PD, CLK, etc.)
     */
    #if 1
	
    if (!appUI_EVEVerify()) {
        ////__FTPRINT("\nEVE init fail");
        while(1);
    }
	#endif
	
    
    //FTPRINT("\nEVE inited");
    /* 
     better do the trimming when using internal clock 
     */
    appUI_EVEClkTrim();

    /* 
     set DISP to output, then enable the DISP
     and some other GPIO related pin
     */
    appUI_EVEGPIOCfg();
    
    /* 
     config the touch related part
     the 'host mode' for FT81X and BT81X not implimented here
     you may refer to offical code example
     */
    appUI_EVETchCfg();
    
    /* 
     do the LCD HW related part here
     */
    appUI_EVELCDCfg();

	/*
	clear the screen before enable the LCD
	to avoid messy info on LCD during bootup
	*/
	appUI_EVEClnScrn();

    /* 
     I just put some none EVE related initial steps
     before launch the major code here 
     */
    appUI_EVEBeforeLaunch();
    
    /* 
     execute the screen calibration step for the touch
     */
    appUI_WaitCal();

    /* 
     after use single SPI to config the EVE
     you may set the SPI base on real HW: SPI/DSPI/QSPI 
     */
    appUI_EVESetSPI(EVE_SPI_TYPE); 
    
    
}
/*
 * Only when error happen
 * or user intend to end the display
 * process would reach here
 */
FTVOID UI_END (FTVOID)
{
#if defined(DEF_BT81X)
	FTU8 reg_rd = HAL_Read8(RAM_ERR_REPORT);
    /* 
       in company's sampleapp code if fault reported, 
       read REG_CMD_READ == 0xFFF, for the fault report indicater
       but in my real pratice, read the RAM_ERR_REPORT 
       if any none '\0', means some error message in it
       should be better
     */
	if (reg_rd)	{
		HAL_Read8Buff(RAM_ERR_REPORT, dbg_str_buf, EVE_DBG_BUF_LEN);
	}
#endif
    HAL_CoReset();

    HAL_CmdBufIn(CMD_DLSTART);
    // give a RED background to highlight the error
    HAL_CmdBufIn(CLEAR_COLOR_RGB(0xFF,0,0));
    HAL_CmdBufIn(CLEAR(1,1,1));
    CoCmd_TEXT(EVE_LCD_WIDTH/2,EVE_LCD_HIGH/2,24,
               OPT_CENTER,(FTC8 *)dbg_str_buf);
    HAL_CmdBufIn(DISPLAY());
    HAL_CmdBufIn(CMD_SWAP);
    HAL_BufToReg(RAM_CMD,0);
    
    //__FTPRINT("\nEVE ended");
	FTDELAY(2500);//_________(5000);
}

