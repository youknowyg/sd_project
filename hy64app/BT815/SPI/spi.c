/**********************************************************
		spi.c
*********************************************************/

//#include "stm32f10x.h"
#include "SPI.h"
#include "main.h"


#define EVE_CS_HIGH 	PTV_PTV3=1//(GPIO_SetBits(GPIOA,GPIO_Pin_4))
#define EVE_CS_LOW 		PTV_PTV3=0//(GPIO_ResetBits(GPIOA,GPIO_Pin_4))

//#define 	BT815_RESET       PORTA_PA7 
#define 	BT815_SDOUT       PTIV_PTIV0    //输入 MCU_815_MISO
#define 	BT815_SDOUT_DDR   DDRV_DDRV0

#define 	BT815_SDIN        PTV_PTV1 
#define 	BT815_SDIN_DDR    DDRV_DDRV1

#define 	BT815_SCS_N       PTV_PTV3
#define 	BT815_SCLK        PTV_PTV2  



#define XTAL            (168000000UL)    /* Oscillator frequency             */
#define SYSCLK 4*XTAL
/* the very first file storage starting flag 
 * storage format should be:
 * FILE_SADDR       0x557EE7AA (4bytes)
 * FILE_SADDR+04    file number(4bytes)
 * FILE_SADDR+08    file1 name (8bytes)
 * FILE_SADDR+16    file1 len  (4bytes)
 * FILE_SADDR+20    file1 data (YYbytes)
 * FILE_SADDR+20+YY file2 name (8bytes)
 * FILE_SADDR+20+YY file2 len  (4bytes)
 * FILE_SADDR+20+YY file2 data (KKbytes)
 * */
#define FILE_MAGIC 0x557EE7AA 
#define FILE_MGCL  4
#define FILE_NUML  4
#define FILE_NAMEL 8
#define FILE_LENL  4
#define FILE_SEARCH_BLOCK 512

//FTU16 VirtAddVarTab[NB_OF_VAR];
FTU32 TimingDelay;
FTU32 FILE_SADDR = 0;
FTU32 gfile_addr = 0;
unsigned int spitime_out = 0xfff;

void BT815_SPI_init(void)
{
    #if 1
    
    DDRV = 0xfe;   
    PTSRR = 0x21; //设置PV0为SPI模式
    //MODRR   = 0x00;     

/* 方案一 */
    SPICR1 = 0x50;//52 0x5e;   //SPI is in master mode   
    SPICR2 = 0x00;//0x00;//0x00;//0x10;   SPI_Mode_Master	该寄存器配置可能还需要考虑一下
    //SPI0BR  = 0x02; //BR=2M    
    //SPIBR  = 0x42; //800k//BR=busclk/((SPPR + 1)?? 2^(SPR + 1))=16000/(5*8)=800k  
    //SPIBR  = 0x43;  //400k
    SPIBR  = 0x02;  //0x42__变快速度0x02

    #else
    DDRV = 0xfe;   
    PTSRR = 0x21; //设置PV0为SPI模式
    //MODRR   = 0x00;     

/* 方案二 */
	SPICR1 = 0x50;                       // 0101 0000    Enable SPI, Configure as Master, CPOL and CPHA configured for mode 0
    SPICR2 = 0x00;                       // 0000 0000    None of the other features such as bi-directional mode used here.
    SPIBR = 0x00;                       // 0000 0000    Optional SPI clock divider.  可以将速度稍微调低一些
    #endif

    //SPIC1=0X50;  //???SPI??????????????????SPI0   
    //SPIC2=0X00;   
    //SPIBR=0X33; //????????????   
    //PTEDD_PTEDD2=1; //PTE2????????   
    
  
    
   
    BT815_SDOUT_DDR=0;  //输入
    
    
    //PTU_PTU5=1;
}

#if 1

FTU8 SPI_ReadWrite(FTU8 Data)
{
    FTU8 TempSPIstatus = 0;
    FTU8 MCU_Readbyte = 0;

    
    TempSPIstatus = 0x00;   
               
    while((TempSPIstatus & 0x20) != 0x20)
    {
        TempSPIstatus = SPISR;         
    }
    
    SPIDR = Data;               
    TempSPIstatus = 0x00;
    
     while((TempSPIstatus & 0x80) != 0x80)
    {
        TempSPIstatus = SPISR;          
    }
    
    MCU_Readbyte = SPIDR;              
        
    return MCU_Readbyte;
}

unsigned char SPIRead(unsigned char add)
{
 
    static unsigned char tmp;
    tmp=SPI_ReadWrite(add);
    return tmp;
}

void SPIWrite(unsigned char Data)
{

    SPI_ReadWrite(Data);
    
	
}
#else
unsigned char SPIRead_sub(unsigned char add)
{
	unsigned char temp=0;
	BT815_SDOUT_DDR=0;  //输入
	
	//delay_spi(); 	
	BT815_SCLK = 0;        				delay_spi();   

	if(BT815_SDOUT==1) 
	{
	  temp=temp|0x80;
	}        
	
	
	BT815_SCLK = 1;  	temp=temp>>1;    delay_spi();  
	
	
	
	BT815_SCLK = 0;                     delay_spi();      
	if(BT815_SDOUT==1) 
	{
	  temp=temp|0x80;
	}                     
	BT815_SCLK = 1;   	temp=temp>>1;    delay_spi(); 
	
	BT815_SCLK = 0;                     delay_spi();      
	if(BT815_SDOUT==1) 
	{
	  temp=temp|0x80;
	}                       
	BT815_SCLK = 1;      temp=temp>>1 ; delay_spi();  
	
	BT815_SCLK = 0;                     delay_spi();      
	if(BT815_SDOUT==1) 
	{
	  temp=temp|0x80;
	}                        
	BT815_SCLK = 1;      temp=temp>>1;  delay_spi();  
	
	BT815_SCLK = 0;                     delay_spi();    
	if(BT815_SDOUT==1) 
	{
	  temp=temp|0x80;
	}                          
	BT815_SCLK = 1;      temp=temp>>1; delay_spi();  
	
	BT815_SCLK = 0;                    delay_spi();     
	if(BT815_SDOUT==1) 
	{
	  temp=temp|0x80;
	}                           
	BT815_SCLK = 1;      temp=temp>>1;  delay_spi();   
	
	BT815_SCLK = 0;                     delay_spi();       
	if(BT815_SDOUT==1) 
	{
	  temp=temp|0x80;
	}                          
	BT815_SCLK = 1;      temp=temp>>1;  delay_spi(); 
	
	BT815_SCLK = 0;                     delay_spi();  
	if(BT815_SDOUT==1)                       
	{
	  temp=temp|0x80;
	}
	BT815_SCLK = 1;        			      delay_spi(); 
	
	
 	BT815_SCLK = 0;                   delay_spi();                            
	//BT815_SCS_N = 1;		                   
  	BT815_SCLK = 1; 
	
	return temp;
}


void SPIWrite(unsigned char Data)
{
    unsigned char temp;
	temp = Data;
	BT815_SCLK = 0; 			                      
	BT815_SDIN = temp&0x01;             delay_spi();
	BT815_SCLK = 1;        temp=temp>>1;delay_spi(); 
	
	BT815_SCLK = 0;                    
	BT815_SDIN = temp&0x01;             delay_spi();
	BT815_SCLK = 1;        temp=temp>>1;delay_spi();  
	
	BT815_SCLK = 0;                 
	BT815_SDIN = temp&0x01;             delay_spi();
	BT815_SCLK = 1;        temp=temp>>1;delay_spi();  
	
	BT815_SCLK = 0;
	BT815_SDIN = temp&0x01;             delay_spi();
	BT815_SCLK = 1;        temp=temp>>1;delay_spi();  
	
	BT815_SCLK = 0;                   
	BT815_SDIN = temp&0x01;             delay_spi();
	BT815_SCLK = 1;        temp=temp>>1;delay_spi();  
	
	BT815_SCLK = 0;                   
	BT815_SDIN = temp&0x01;             delay_spi();
	BT815_SCLK = 1;        temp=temp>>1;delay_spi(); 
	
	BT815_SCLK = 0;                
	BT815_SDIN = temp&0x01;             delay_spi();
	BT815_SCLK = 1;        temp=temp>>1;delay_spi(); 
	
	BT815_SCLK = 0;                   
	BT815_SDIN = temp&0x01;             delay_spi();       
	BT815_SCLK = 1;                     delay_spi();  
}

extern unsigned  int yytest1;
unsigned char SPIRead(unsigned char add)
{
	unsigned char ret,ret1;

	//EVE_CS_LOW;delay_spi();              


	
	//SPIWrite(add);

	
	ret = SPIRead_sub(add);
    yytest1=ret;
    ret1=yytest1;
	//Y825_SCS_N = 1;		   //delay_spi();  
	//Y825_SCLK = 1; 
	return ret1;
}
#endif

STATIC FTVOID rdStart ( FTU32 addr )
{
    EVE_CS_LOW;
    SPIWrite((FTU8)(addr >> 16));
    SPIWrite((FTU8)(addr >> 8));
    SPIWrite((FTU8)addr);
    SPIWrite(0); //Dummy byte to generate read clock
}

STATIC FTVOID wrStart ( FTU32 addr )
{
    EVE_CS_LOW;
    SPIWrite((FTU8)(0x80 | (addr >> 16)));
    SPIWrite((FTU8)(addr >> 8));
    SPIWrite((FTU8)addr);
}

FTVOID HAL_Write8 ( FTU32 addr, FTU8 data )
{
    wrStart(addr);

    SPIWrite(data);

    EVE_CS_HIGH;
}

FTVOID HAL_Write8Src ( FTU32 addr, FTU8 *src, FTU32 len )
{
    FTU32 i;

    wrStart(addr);

    for (i = 0; i < len; i++) {
        SPIWrite(src[i]);
    }

    EVE_CS_HIGH;
}

FTVOID HAL_Write16 ( FTU32 addr, FTU16 data )
{
    wrStart(addr);

    SPIWrite((FTU8)data&0xFF);
    SPIWrite((FTU8)(data>>8)&0xFF);

    EVE_CS_HIGH;
}

FTVOID HAL_Write32 ( FTU32 addr, FTU32 data )
{
    wrStart(addr);

    SPIWrite((FTU8)data&0xFF);
    SPIWrite((FTU8)(data>>8)&0xFF);
    SPIWrite((FTU8)(data>>16)&0xFF);
    SPIWrite((FTU8)(data>>24)&0xFF);

    EVE_CS_HIGH;
}

FTVOID HAL_Cfg ( FTU8 cfg )
{
    EVE_CS_LOW;

    SPIWrite(cfg);

    SPIWrite(0);

    SPIWrite(0);

    EVE_CS_HIGH;
}

FTVOID HAL_Cfg3 ( FTU32 cfg3 )
{
    EVE_CS_LOW;

    SPIWrite(cfg3);

    SPIWrite(cfg3>>8);

    SPIWrite(cfg3>>16);

    EVE_CS_HIGH;
}

FTU8 HAL_Read8 ( FTU32 addr )
{
    FTU8 tmp;

    rdStart(addr);
    tmp = SPIRead(0);

    EVE_CS_HIGH;

    return tmp;
}

FTU32 HAL_Read8Buff ( FTU32 addr, FTU8 *buff, FTU32 len )
{
    FTU32 tmp = len;
    FTU8 *p = buff;

    rdStart(addr);

    while (tmp--) {
        *p = SPIRead(0);
        p++;
    }

    EVE_CS_HIGH;

    return len;
}

FTU16 HAL_Read16 ( FTU32 addr )
{
    FTU16 tmp = 0;

    rdStart(addr);

    /* force type definition is critical while running on different platform */
    tmp = (FTU16)SPIRead(0);
    tmp |= (FTU16)SPIRead(0) << 8;

    EVE_CS_HIGH;

    return tmp;
}

FTU32 HAL_Read32 ( FTU32 addr )
{
    FTU32 tmp = 0;

    rdStart(addr);

    /* force type definition is critical while running on different platform */
    tmp = (FTU32)SPIRead(0);
    tmp |= (FTU32)SPIRead(0) << 8;
    tmp |= (FTU32)SPIRead(0) << 16;
    tmp |= (FTU32)SPIRead(0) << 24;

    EVE_CS_HIGH;

    return tmp;
}

FTVOID HAL_PwdCyc ( FTU8 OnOff )
{
    DDRU_DDRU5=1;
	PTU_PTU5=1;
    FTDELAY(15);
	PTU_PTU5=0;
    FTDELAY(200);
    PTU_PTU5=1;
}

FTVOID HAL_SpiInit ( FTVOID )
{
    /* 
       the SPI clock shall not exceed 11MHz before system clock is enabled. 
       After system clock is properly enabled, 
       the SPI clock is allowed to go up to 30MHz.	
     */
     BT815_SPI_init();
}

FTVOID HAL_preparation (FTVOID)
{
    //do nothing
}

FTU32 HAL_WriteSrcToDes (FTU32 handle, FTU32 src, FTU32 des, FTU32 len)
{
    FTU32 i;

    for (i = 0; i < len ; i++) {
        *(FTU8 *)(des+i) = *(FTU8 *)(handle+src+i);
    }
    
    return i;
}

FTU8 * HAL_LoopMemMalloc (FTU32 handle, FTU32 src, FTU32 len)
{
    //if (MCU_BLOCK_SIZE < len) {
    //    FTPRINT("\nHAL_LoopMemMalloc: malloc exceeded");
    //}
    return (FTU8 *)handle+src;
}

FTVOID HAL_LoopMemRead (FTU32 handle, FTU8 **ppbuf, FTU32 len)
{
    *ppbuf += len;
}

FTVOID HAL_LoopMemFree (FTU32 buf)
{
    // do nothing
}

FTU32 stm32f4_len (FTU8 *str)
{
	FTU32 i = 0;

	while (str[i] != '\0') {
		i++;
	}

	return i;
}

FTU32 stm32f4_is_match (FTU8 *path, FTU8 *name)
{
	if (stm32f4_len(path) != stm32f4_len(name) ) {
		return 0;
	}

	//return memcmp(path,name,stm32f4_len(path))?0:1;
	return 1;
}

FTU32 HAL_SegFileOpen (FTU8 *path)
{
	FTU32 i, num, addr;

	if (FILE_MAGIC != *(FTU32 *)FILE_SADDR) {
		return 0;
	}

	num = *(FTU32 *)(FILE_SADDR+FILE_MGCL);
	addr = (FILE_SADDR+FILE_MGCL+FILE_NUML);
	
	for (i = 0; i < num; i++) {
		if (stm32f4_is_match(path,(FTU8 *)addr)) {
			gfile_addr = addr + FILE_NAMEL+FILE_LENL;
			return gfile_addr;
		} else {
			addr += (*(FTU32 *)(addr+FILE_NAMEL) + FILE_NAMEL + FILE_LENL);
		}
	}
	
	return 0;
}

FTU32 HAL_SegFileSize (FTU32 handle)
{
	return *(FTU32 *)(handle-FILE_LENL);
}

FTVOID HAL_SegFileClose (FTU32 handle)
{
    // do nothing
}

FTU8 HAL_ZlibCompressed (FTU32 handle, FTU32 src)
{
    FTU8 header[2] = {0};

    header[0] = *(FTU8 *)(handle+src);
    header[1] = *(FTU8 *)(handle+src+1);
    /*
       zLib compression header
       +---+---+
       |CMF|FLG|
       +---+---+

       78 01 - No Compression/low
       78 9C - Default Compression
       78 DA - Best Compression 
     */
    if (header[0] == 0x78 && header[1] == 0x9C) {
        return 1;
    } else {
        return 0;
    }
}

FTVOID stm32_apps_sys_dummy (FTU32 para)
{
/* do nothing */
}


FTVOID stm32_dumy_print(char * p)
{
/* do nothing */
}

FTVOID HAL_invaild_tag (FTC8 *dataPath)
{

}

FTU8 HAL_is_tag_vaild (FTC8 *dataPath)
{
//	FTU8 i, tag[] = CALD_TAG_DATA, tmp[CALD_TAG_LEN] = {0};

	return 1;
}

FTVOID HAL_save_cdata (FTC8 *dataPath, FTU8 *p)
{


}

FTVOID HAL_restore_cdata (FTC8 *dataPath, FTU8 *p)
{

}

FTVOID HAL_vaild_tag (FTVOID)
{
//	FTU8 tag[] = CALD_TAG_DATA;
//	FTU32 i;

}

extern void DelayXms(unsigned int n);
FTVOID stm32f4Delay(FTU32 nTime)
{ 
	DelayXms(nTime);
	//_FEED_COP();								// 喂狗
}

FTU32 stm32f4Random(FTU32 r)
{
	return 0;
}

