
#include "main.h"
#include "LCDDriver.h"


extern void delay_ms(unsigned int nms);

//-----------------------------------------------------------
//176*220
#define  HDP COL-1  //Hsync Display period   
#define  VDP ROW-1 //Vertical Display period

#define  HT  252	  //Horizontal total period = (HT + 1) pixels
#define  HPS 4	  //Horizontal Sync Pulse Start Position = (HPS + 1) pixels	 		 
#define  LPS 2	  //Horizontal Display Period Start Position = LPS pixels		
#define  HPW 2   //Horizontal Sync Pulse Width = (HPW + 1) pixels	

#define  VT 326	 //Vertical Total = (VT + 1) lines
#define  VPS 4  //Vertical Sync Pulse Start Position = VPS lines					  
#define  FPS 0   //Vertical Display Period Start Position = FPS lines				  
#define  VPW 2  //Vertical Sync Pulse Width = (VPW + 1) lines


 /*

#define  HT  181	 //Horizontal total period = (HT + 1) pixels    326,3,2,3
#define  HPS 5	  //Horizontal Sync Pulse Start Position = (HPS + 1) pixels	 		 
#define  LPS 2	  //Horizontal Display Period Start Position = LPS pixels		
#define  HPW 3  //Horizontal Sync Pulse Width = (HPW + 1) pixels	

#define  VT  224	 //Vertical Total = (VT + 1) lines  //496,2,7,3
#define  VPS 4  //Vertical Sync Pulse Start Position = VPS lines					  
#define  FPS 0  //Vertical Display Period Start Position = FPS lines				  
#define  VPW 3  //Vertical Sync Pulse Width = (VPW + 1) lines

*/
//-----------------------------------------------------------





void LCD_IOInit(void)
{
	DDRH = 0xfe;   
    PTSRR = 0x13; //选择设置哪组IO用于SPI 这里选择PH
    //MODRR   = 0x00;     

/* 方案一 */
    SPICR1 = 0x50;//52 0x5e;   //SPI is in master mode   
    SPICR2 = 0x00;//0x00;//0x00;//0x10;   SPI_Mode_Master	该寄存器配置可能还需要考虑一下
    //SPI0BR  = 0x02; //BR=2M    
    //SPIBR  = 0x42; //800k//BR=busclk/((SPPR + 1)?? 2^(SPR + 1))=16000/(5*8)=800k  
    //SPIBR  = 0x43;  //400k
    SPIBR  = 0x02;  //0x42__变快速度0x02
}

void SPI_SendData(unsigned char i)
{
   unsigned char n;
   
   for(n=0; n<8; n++)			
   {  
		if(i&0x80) 
			PTH_PTH1=1;
		else
			PTH_PTH1=0;
		i<<= 1;

		PTH_PTH2=0;
		//__asm(nop); __asm(nop);__asm(nop);__asm(nop);
		DelayXms(1);
		PTH_PTH2=1;//__asm(nop);__asm(nop);__asm(nop);__asm(nop);			
		DelayXms(1);
   }
}


// void SPI_SendData(unsigned char Data)
// {
// 	unsigned char TempSPIstatus = 0;
//     unsigned char MCU_Readbyte = 0;

// 	TempSPIstatus = 0x00;   
               
//     while((TempSPIstatus & 0x20) != 0x20)
//     {
//         TempSPIstatus = SPISR;         
//     }
    
//     SPIDR = Data;               
//     TempSPIstatus = 0x00;
    
//     //  while((TempSPIstatus & 0x80) != 0x80)
//     // {
//     //     TempSPIstatus = SPISR;          
//     // }
    
//     // MCU_Readbyte = SPIDR;              

// }

void SPI_WriteComm(unsigned short i)
{
	PTR_PTR6 = 0;
	SPI_SendData(0x74);	 //cmd
	SPI_SendData(i>>8);
	SPI_SendData(i);
	PTR_PTR6 = 1;
}

void SPI_WriteData(unsigned short i)
{
	PTR_PTR6 = 0;
	SPI_SendData(0x76); //para
	SPI_SendData(i>>8);
	SPI_SendData(i);
	PTR_PTR6 = 1;
}

void LCD_Init(void)
{
	DDRH = 0xFE;
	//while (1)
	{
	//LCD_IOInit();
	PTU_PTU6=1;
	DelayXms(10);
	PTU_PTU6=0;
    DelayXms(800);
	PTU_PTU6=1;
    DelayXms(800);
	// Gamma for CMO 3.2”
	SPI_WriteComm(0x0046);  SPI_WriteData(0x0070); 
	SPI_WriteComm(0x0047);  SPI_WriteData(0x0077); 
	SPI_WriteComm(0x0048);  SPI_WriteData(0x0076); 
	SPI_WriteComm(0x0049);  SPI_WriteData(0x0010); 
	SPI_WriteComm(0x004a);  SPI_WriteData(0x0047); 
	SPI_WriteComm(0x004b);  SPI_WriteData(0x0003); 
	SPI_WriteComm(0x004c);  SPI_WriteData(0x0072); 
	SPI_WriteComm(0x004d);  SPI_WriteData(0x0074); 
	SPI_WriteComm(0x004e);  SPI_WriteData(0x0010); 
	SPI_WriteComm(0x004f);  SPI_WriteData(0x005f); 
	SPI_WriteComm(0x0050);  SPI_WriteData(0x00ff); 
	SPI_WriteComm(0x0051);  SPI_WriteData(0x00C0);
	//240x320 window setting
	SPI_WriteComm(0x0002);  SPI_WriteData(0x0000); // Column address start2
	SPI_WriteComm(0x0003);  SPI_WriteData(0x0000); // Column address start1
	SPI_WriteComm(0x0004);  SPI_WriteData(0x0000); // Column address end2
	SPI_WriteComm(0x0005);  SPI_WriteData(0x00EF); // Column address end1
	SPI_WriteComm(0x0006);  SPI_WriteData(0x0000); // Row address start2
	SPI_WriteComm(0x0007);  SPI_WriteData(0x0000); // Row address start1
	SPI_WriteComm(0x0008);  SPI_WriteData(0x0001); // Row address end2
	SPI_WriteComm(0x0009);  SPI_WriteData(0x003F); // Row address end1
	// Display Setting
	SPI_WriteComm(0x0001);  SPI_WriteData(0x0002); // IDMON=0, INVON=1, NORON=1, PTLON=0
	SPI_WriteComm(0x0016);  SPI_WriteData(0x0048); // MY=0, MX=0, MV=0, ML=1, BGR=0, TEON=0
	SPI_WriteComm(0x0038);  SPI_WriteData(0x0010); // RGB_EN=0, use MPU Interface
	SPI_WriteComm(0x0023);  SPI_WriteData(0x0095); // N_DC=1001 0101
	SPI_WriteComm(0x0024);  SPI_WriteData(0x0095); // PI_DC=1001 0101
	SPI_WriteComm(0x0025);  SPI_WriteData(0x00FF); // I_DC=1111 1111
	SPI_WriteComm(0x0027);  SPI_WriteData(0x0002); // N_BP=0000 0010
	SPI_WriteComm(0x0028);  SPI_WriteData(0x0002); // N_FP=0000 0010
	SPI_WriteComm(0x0029);  SPI_WriteData(0x0002); // PI_BP=0000 0010
	SPI_WriteComm(0x002A);  SPI_WriteData(0x0002); // PI_FP=0000 0010
	SPI_WriteComm(0x002C);  SPI_WriteData(0x0002); // I_BP=0000 0010
	SPI_WriteComm(0x002D);  SPI_WriteData(0x0002); // I_FP=0000 0010
	SPI_WriteComm(0x003A);  SPI_WriteData(0x0001); // N_RTN=0000, N_NW=001
	SPI_WriteComm(0x003B);  SPI_WriteData(0x0000); // PI_RTN=0000, PI_NW=000
	SPI_WriteComm(0x003C);  SPI_WriteData(0x00F0); // I_RTN=1111, I_NW=000
	SPI_WriteComm(0x003D);  SPI_WriteData(0x0000); // DIV=00
	SPI_WriteComm(0x0070);  SPI_WriteData(0x0066); // 18-Bit RGB Interface
	DelayXms(20);
	SPI_WriteComm(0x0035);  SPI_WriteData(0x0038); // EQS=38h
	SPI_WriteComm(0x0036);  SPI_WriteData(0x0078); // EQP=78h
	SPI_WriteComm(0x003E);  SPI_WriteData(0x0038); // SON=38h
	SPI_WriteComm(0x0040);  SPI_WriteData(0x000F); // GDON=0Fh
	SPI_WriteComm(0x0041);  SPI_WriteData(0x00F0); // GDOFF
	// Power Supply Setting
	SPI_WriteComm(0x0019);  SPI_WriteData(0x0049); // CADJ=0100, CUADJ=100(FR:60Hz),, OSD_EN=1
	SPI_WriteComm(0x0093);  SPI_WriteData(0x000F); // RADJ=1111, 100%
	DelayXms(10);
	SPI_WriteComm(0x0020);  SPI_WriteData(0x0040); // BT=0100
	SPI_WriteComm(0x001D);  SPI_WriteData(0x0007); // VC1=111
	SPI_WriteComm(0x001E);  SPI_WriteData(0x0006); // VC3=000
	SPI_WriteComm(0x001F);  SPI_WriteData(0x000E); // VRH=0100
	// VCOM Setting for CMO 3.2” Panel
	SPI_WriteComm(0x0044);  SPI_WriteData(0x00f1); // VCM=100 1101
	SPI_WriteComm(0x0045);  SPI_WriteData(0x0011); // VDV=1 0001
	DelayXms(10);
	SPI_WriteComm(0x001C);  SPI_WriteData(0x0004); // AP=100
	DelayXms(20);
	SPI_WriteComm(0x001B);  SPI_WriteData(0x0018); // GASENB=0, PON=1, DK=1, XDK=0, VLCD_TRI=0, STB=0
	DelayXms(40);
	SPI_WriteComm(0x001B);  SPI_WriteData(0x0010); // GASENB=0, PON=1, DK=0, XDK=0, VLCD_TRI=0, STB=0
	DelayXms(40);
	SPI_WriteComm(0x0043);  SPI_WriteData(0x0080); //Set VCOMG=1
	DelayXms(100);
	// Display ON Setting
	SPI_WriteComm(0x0090);  SPI_WriteData(0x007F); // SAP=0111 1111
	SPI_WriteComm(0x0026);  SPI_WriteData(0x0004); //GON=0, DTE=0, D=01
	DelayXms(40);
	SPI_WriteComm(0x0026);  SPI_WriteData(0x0024); //GON=1, DTE=0, D=01
	SPI_WriteComm(0x0026);  SPI_WriteData(0x002C); //GON=1, DTE=0, D=11
	DelayXms(40);
	SPI_WriteComm(0x0026);  SPI_WriteData(0x003C); //GON=1, DTE=1, D=11
	// Internal register setting
	SPI_WriteComm(0x0057);  SPI_WriteData(0x0002); //Test_Mode Enable
	SPI_WriteComm(0x0095);  SPI_WriteData(0x0001); // Set Display clock and Pumping clock to synchronize
	SPI_WriteComm(0x0057);  SPI_WriteData(0x0000); // Test_Mode Disable
	}
}


#if 0
void WriteComm(unsigned int i)
{
	 //CS0=0;
	 //RD0=1;
	 RS=0;

 	 DBH=i>>8;
	 DBL=i;

	 WR0=0;
	 WR0=1; 

	 //CS0=1
}
    
void WriteData(unsigned int i)
{
	 //CS0=0;
	 //RD0=1;
	 RS=1;

	 DBH=i>>8;
	 DBL=i;	

	 WR0=0;
	 WR0=1;  

     //CS0=1;
}

void WriteDispData(unsigned char DataH,unsigned char DataL)
{

	 //CS0=0;
	 //RD0=1;
	 //RS=1;

	 DBH=DataH;
	 DBL=DataL;

	 WR0=0;
	 WR0=1; 

	 //CS0=1;
}

void SSD1963_Init(void)
{
	CS0=0;

	RST=1;  
	Delay(100);
	
	RST=0;
	Delay(800);

	RST=1;
	Delay(800);


	//SSD1963,800*480

	WriteComm(0x01);  // software reset
	Delay(50);
	
	WriteComm(0x00E2);	//set_pll_mn
	WriteData(0x0030);	//M=0x23=35, VCO = Reference input clock x (M + 1),PLL multiplier, set PLL clock to 120M
	WriteData(0x0001);	//N=0x02=2,	 PLL frequency  = VCO / (N + 1) 
	WriteData(0x0004);	//0x36 for 6.5M, 0x23 for 10M crystal
	
	WriteComm(0xE0);  // PLL enable
	WriteData(0x01);
	Delay(5);
	
	WriteComm(0xE0);
	WriteData(0x03);
	
	Delay(5);
	

	WriteComm(0x00E6);	//set_lshift_freq ,PLL setting for PCLK, depends on resolution
	WriteData(0x0001);	//4.94M
	WriteData(0x0050);
	WriteData(0x0094);	//94					   

	WriteComm(0xB0); //LCD SPECIFICATION
	WriteData(0x24); //A5=0=18bit  A5=1=24bit  A2_PCLK=0 A1_HS=0 A0_VS=0 DE=1
	WriteData(0x00);
	WriteData((HDP>>8)&0xFF);  //Set HDP
	WriteData(HDP&0xFF);
    WriteData((VDP>>8)&0xFF);  //Set VDP
	WriteData(VDP&0xFF);
    WriteData(0x00);   
	Delay(5);
	
	WriteComm(0xB4);	         //HSYNC
	WriteData((HT>>8)&0xFF);  //Set HT
	WriteData(HT&0xFF);
	WriteData((HPS>>8)&0xFF);  //Set HPS
	WriteData(HPS&0xFF);
	WriteData(HPW);			   //Set HPW
	WriteData((LPS>>8)&0xFF);   //SetLPS
	WriteData(LPS&0xFF);
	WriteData(0x00);

	WriteComm(0xB6);	          //VSYNC
	WriteData((VT>>8)&0xFF);   //Set VT
	WriteData(VT&0xFF);
	WriteData((VPS>>8)&0xFF);   //Set VPS
	WriteData(VPS&0xFF);
	WriteData(VPW);			   //Set VPW
	WriteData((FPS>>8)&0xFF);   //Set FPS
	WriteData(FPS&0xFF);

	WriteComm(0x36); //rotation
	WriteData(0x00);  //00

	WriteComm(0xF0); //pixel data interface  
    WriteData(0x03); // 03	16-bit (565 format)	  05 :24BIT 

	Delay(5);
	ClearAll();

	WriteComm(0x29); //display on
	Delay(5);

	WriteComm(0x00BE); //set_pwm_conf,for B/L
	WriteData(0x0006);
	WriteData(0x00f0);
	WriteData(0x0001);
	WriteData(0x00f0);
	WriteData(0x0000);
	WriteData(0x0000);

	WriteComm(0x00D0); 	//set_dbc_conf,for B/L
	WriteData(0x000d);	

}
#endif

