
#include "main.h"
#include "LCDDriver.h"


extern void delay_ms(unsigned int nms);

//-----------------------------------------------------------
#define ROW  800		    //显示的行、列数
#define COL  480
//800*480
#define  HDP COL-1  //Hsync Display period   
#define  VDP ROW-1 //Vertical Display period

#define  HT  525	  //Horizontal total period = (HT + 1) pixels
#define  HPS 43	  //Horizontal Sync Pulse Start Position = (HPS + 1) pixels	 		 
#define  LPS 1	  //Horizontal Display Period Start Position = LPS pixels		
#define  HPW 0   //Horizontal Sync Pulse Width = (HPW + 1) pixels	

#define  VT 859	 //Vertical Total = (VT + 1) lines
#define  VPS 4  //Vertical Sync Pulse Start Position = VPS lines					  
#define  FPS 0   //Vertical Display Period Start Position = FPS lines				  
#define  VPW 0  //Vertical Sync Pulse Width = (VPW + 1) lines




//-----------------------------------------------------------
void SPI_SendData(unsigned char i)
{  
    #if 0
   unsigned char n;
   
   for(n=0; n<8; n++)			
   {  
	  if(i&0x80) SET_SPI_DI();
      	else CLR_SPI_DI();
      i<<= 1;

	  CLR_SPI_CLK();
	  __NOP(); __NOP();__NOP();__NOP();
      SET_SPI_CLK();
	  __NOP(); __NOP();__NOP();__NOP();
   }
   #endif
}


void SPI_WriteComm(unsigned int i)	  //spec page 46
{
    #if 0
    CLR_SPI_CS();

	SPI_SendData(0x20);	 //high 8bit
	SPI_SendData(i>>8);

	SPI_SendData(0x00);	//low 8bit
	SPI_SendData(i);

    SET_SPI_CS();
    #endif
}

void SPI_WriteData(unsigned int i)
{
    #if 0
    CLR_SPI_CS();

	SPI_SendData(0x40);
	SPI_SendData(i);

    SET_SPI_CS();
    #endif
}


void LCD_IOInit(void)
{
    #if 0
	GPIO_InitTypeDef GPIO_InitStructure;										//定义GPIO结构体
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOC, ENABLE);		//使能PA口的时钟
	
	GPIO_InitStructure.GPIO_Pin = (GPIO_Pin_11);  //GPIO_Pin_8 片选   GPIO_Pin_11  RES  GPIO_Pin_11 DC(数据命令选择线)
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 				//推挽输出
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 			//输出速度
	GPIO_Init(GPIOC, &GPIO_InitStructure);
	
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);		//使能PB口的时钟
	GPIO_InitStructure.GPIO_Pin = (GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14|GPIO_Pin_1 );
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 				//推挽输出
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 			//输出速度
	GPIO_Init(GPIOB, &GPIO_InitStructure);

	GPIO_ResetBits(GPIOB,GPIO_Pin_12);      //片选口有效
	GPIO_ResetBits(GPIOB,GPIO_Pin_13);	   //片选口有效
	GPIO_ResetBits(GPIOB,GPIO_Pin_14);	   //片选口有效
	#endif
}

void LCD_Init(void)
{
    #if 0
	LCD_IOInit();

	SET_SPI_RES();
	delay_ms(10);

	CLR_SPI_RES();
    delay_ms(20);

    SET_SPI_RES();
	delay_ms(100);
  
	//for RGB interface should be send PCLK/VS/HS first then SPI
	//-------------Start Initial Sequence------------//
	SPI_WriteComm(0xF000);SPI_WriteData(0x55); //page 1
	SPI_WriteComm(0xF001);SPI_WriteData(0xAA);
	SPI_WriteComm(0xF002);SPI_WriteData(0x52);
	SPI_WriteComm(0xF003);SPI_WriteData(0x08);
	SPI_WriteComm(0xF004);SPI_WriteData(0x01);
	SPI_WriteComm(0xD100);SPI_WriteData(0x00);//Gamma setting Red
	SPI_WriteComm(0xD101);SPI_WriteData(0x00);
	SPI_WriteComm(0xD102);SPI_WriteData(0x22);
	SPI_WriteComm(0xD103);SPI_WriteData(0x55);
	SPI_WriteComm(0xD104);SPI_WriteData(0x78);
	SPI_WriteComm(0xD105);SPI_WriteData(0x40);
	SPI_WriteComm(0xD106);SPI_WriteData(0x93);
	SPI_WriteComm(0xD107);SPI_WriteData(0xBF);
	SPI_WriteComm(0xD108);SPI_WriteData(0xE0);
	SPI_WriteComm(0xD109);SPI_WriteData(0x10);
	SPI_WriteComm(0xD10A);SPI_WriteData(0x55);
	SPI_WriteComm(0xD10B);SPI_WriteData(0x33);
	SPI_WriteComm(0xD10C);SPI_WriteData(0x4F);
	SPI_WriteComm(0xD10D);SPI_WriteData(0x66);
	SPI_WriteComm(0xD10E);SPI_WriteData(0x7A);
	SPI_WriteComm(0xD10F);SPI_WriteData(0x55);
	SPI_WriteComm(0xD110);SPI_WriteData(0x8C);
	SPI_WriteComm(0xD111);SPI_WriteData(0x9C);
	SPI_WriteComm(0xD112);SPI_WriteData(0xA9);
	SPI_WriteComm(0xD113);SPI_WriteData(0xB6);
	SPI_WriteComm(0xD114);SPI_WriteData(0x55);
	SPI_WriteComm(0xD115);SPI_WriteData(0xC2);
	SPI_WriteComm(0xD116);SPI_WriteData(0xCE);
	SPI_WriteComm(0xD117);SPI_WriteData(0xD8);
	SPI_WriteComm(0xD118);SPI_WriteData(0xE2);
	SPI_WriteComm(0xD119);SPI_WriteData(0x55);
	SPI_WriteComm(0xD11A);SPI_WriteData(0xEC);
	SPI_WriteComm(0xD11B);SPI_WriteData(0xED);
	SPI_WriteComm(0xD11C);SPI_WriteData(0xF6);
	SPI_WriteComm(0xD11D);SPI_WriteData(0xFF);
	SPI_WriteComm(0xD11E);SPI_WriteData(0xAA);
	SPI_WriteComm(0xD11F);SPI_WriteData(0x07);
	SPI_WriteComm(0xD120);SPI_WriteData(0x0F);
	SPI_WriteComm(0xD121);SPI_WriteData(0x17);
	SPI_WriteComm(0xD122);SPI_WriteData(0x20);
	SPI_WriteComm(0xD123);SPI_WriteData(0xAA);
	SPI_WriteComm(0xD124);SPI_WriteData(0x28);
	SPI_WriteComm(0xD125);SPI_WriteData(0x30);
	SPI_WriteComm(0xD126);SPI_WriteData(0x3A);
	SPI_WriteComm(0xD127);SPI_WriteData(0x44);
	SPI_WriteComm(0xD128);SPI_WriteData(0xAA);
	SPI_WriteComm(0xD129);SPI_WriteData(0x52);
	SPI_WriteComm(0xD12A);SPI_WriteData(0x66);
	SPI_WriteComm(0xD12B);SPI_WriteData(0x86);
	SPI_WriteComm(0xD12C);SPI_WriteData(0xC5);
	SPI_WriteComm(0xD12D);SPI_WriteData(0xFF);
	SPI_WriteComm(0xD12E);SPI_WriteData(0x00);
	SPI_WriteComm(0xD12F);SPI_WriteData(0x51);
	SPI_WriteComm(0xD130);SPI_WriteData(0x8D);
	SPI_WriteComm(0xD131);SPI_WriteData(0xC4);
	SPI_WriteComm(0xD132);SPI_WriteData(0x0F);
	SPI_WriteComm(0xD133);SPI_WriteData(0xE0);
	SPI_WriteComm(0xD134);SPI_WriteData(0xFF);
	SPI_WriteComm(0xD200);SPI_WriteData(0x00);//Gamma setting Green
	SPI_WriteComm(0xD201);SPI_WriteData(0x00);
	SPI_WriteComm(0xD202);SPI_WriteData(0x22);
	SPI_WriteComm(0xD203);SPI_WriteData(0x55);
	SPI_WriteComm(0xD204);SPI_WriteData(0x78);
	SPI_WriteComm(0xD205);SPI_WriteData(0x40);
	SPI_WriteComm(0xD206);SPI_WriteData(0x93);
	SPI_WriteComm(0xD207);SPI_WriteData(0xBF);
	SPI_WriteComm(0xD208);SPI_WriteData(0xE0);
	SPI_WriteComm(0xD209);SPI_WriteData(0x10);
	SPI_WriteComm(0xD20A);SPI_WriteData(0x55);
	SPI_WriteComm(0xD20B);SPI_WriteData(0x33);
	SPI_WriteComm(0xD20C);SPI_WriteData(0x4F);
	SPI_WriteComm(0xD20D);SPI_WriteData(0x66);
	SPI_WriteComm(0xD20E);SPI_WriteData(0x7A);
	SPI_WriteComm(0xD20F);SPI_WriteData(0x55);
	SPI_WriteComm(0xD210);SPI_WriteData(0x8C);
	SPI_WriteComm(0xD211);SPI_WriteData(0x9C);
	SPI_WriteComm(0xD212);SPI_WriteData(0xA9);
	SPI_WriteComm(0xD213);SPI_WriteData(0xB6);
	SPI_WriteComm(0xD214);SPI_WriteData(0x55);
	SPI_WriteComm(0xD215);SPI_WriteData(0xC2);
	SPI_WriteComm(0xD216);SPI_WriteData(0xCE);
	SPI_WriteComm(0xD217);SPI_WriteData(0xD8);
	SPI_WriteComm(0xD218);SPI_WriteData(0xE2);
	SPI_WriteComm(0xD219);SPI_WriteData(0x55);
	SPI_WriteComm(0xD21A);SPI_WriteData(0xEC);
	SPI_WriteComm(0xD21B);SPI_WriteData(0xED);
	SPI_WriteComm(0xD21C);SPI_WriteData(0xF6);
	SPI_WriteComm(0xD21D);SPI_WriteData(0xFF);
	SPI_WriteComm(0xD21E);SPI_WriteData(0xAA);
	SPI_WriteComm(0xD21F);SPI_WriteData(0x07);
	SPI_WriteComm(0xD220);SPI_WriteData(0x0F);
	SPI_WriteComm(0xD221);SPI_WriteData(0x17);
	SPI_WriteComm(0xD222);SPI_WriteData(0x20);
	SPI_WriteComm(0xD223);SPI_WriteData(0xAA);
	SPI_WriteComm(0xD224);SPI_WriteData(0x28);
	SPI_WriteComm(0xD225);SPI_WriteData(0x30);
	SPI_WriteComm(0xD226);SPI_WriteData(0x3A);
	SPI_WriteComm(0xD227);SPI_WriteData(0x44);
	SPI_WriteComm(0xD228);SPI_WriteData(0xAA);
	SPI_WriteComm(0xD229);SPI_WriteData(0x52);
	SPI_WriteComm(0xD22A);SPI_WriteData(0x66);
	SPI_WriteComm(0xD22B);SPI_WriteData(0x86);
	SPI_WriteComm(0xD22C);SPI_WriteData(0xC5);
	SPI_WriteComm(0xD22D);SPI_WriteData(0xFF);
	SPI_WriteComm(0xD22E);SPI_WriteData(0x00);
	SPI_WriteComm(0xD22F);SPI_WriteData(0x51);
	SPI_WriteComm(0xD230);SPI_WriteData(0x8D);
	SPI_WriteComm(0xD231);SPI_WriteData(0xC4);
	SPI_WriteComm(0xD232);SPI_WriteData(0x0F);
	SPI_WriteComm(0xD233);SPI_WriteData(0xE0);
	SPI_WriteComm(0xD234);SPI_WriteData(0xFF);
	SPI_WriteComm(0xD300);SPI_WriteData(0x00);//Gamma setting Blue
	SPI_WriteComm(0xD301);SPI_WriteData(0x00);
	SPI_WriteComm(0xD302);SPI_WriteData(0x22);
	SPI_WriteComm(0xD303);SPI_WriteData(0x55);
	SPI_WriteComm(0xD304);SPI_WriteData(0x78);
	SPI_WriteComm(0xD305);SPI_WriteData(0x40);
	SPI_WriteComm(0xD306);SPI_WriteData(0x93);
	SPI_WriteComm(0xD307);SPI_WriteData(0xBF);
	SPI_WriteComm(0xD308);SPI_WriteData(0xE0);
	SPI_WriteComm(0xD309);SPI_WriteData(0x10);
	SPI_WriteComm(0xD30A);SPI_WriteData(0x55);
	SPI_WriteComm(0xD30B);SPI_WriteData(0x33);
	SPI_WriteComm(0xD30C);SPI_WriteData(0x4F);
	SPI_WriteComm(0xD30D);SPI_WriteData(0x66);
	SPI_WriteComm(0xD30E);SPI_WriteData(0x7A);
	SPI_WriteComm(0xD30F);SPI_WriteData(0x55);
	SPI_WriteComm(0xD310);SPI_WriteData(0x8C);
	SPI_WriteComm(0xD311);SPI_WriteData(0x9C);
	SPI_WriteComm(0xD312);SPI_WriteData(0xA9);
	SPI_WriteComm(0xD313);SPI_WriteData(0xB6);
	SPI_WriteComm(0xD314);SPI_WriteData(0x55);
	SPI_WriteComm(0xD315);SPI_WriteData(0xC2);
	SPI_WriteComm(0xD316);SPI_WriteData(0xCE);
	SPI_WriteComm(0xD317);SPI_WriteData(0xD8);
	SPI_WriteComm(0xD318);SPI_WriteData(0xE2);
	SPI_WriteComm(0xD319);SPI_WriteData(0x55);
	SPI_WriteComm(0xD31A);SPI_WriteData(0xEC);
	SPI_WriteComm(0xD31B);SPI_WriteData(0xED);
	SPI_WriteComm(0xD31C);SPI_WriteData(0xF6);
	SPI_WriteComm(0xD31D);SPI_WriteData(0xFF);
	SPI_WriteComm(0xD31E);SPI_WriteData(0xAA);
	SPI_WriteComm(0xD31F);SPI_WriteData(0x07);
	SPI_WriteComm(0xD320);SPI_WriteData(0x0F);
	SPI_WriteComm(0xD321);SPI_WriteData(0x17);
	SPI_WriteComm(0xD322);SPI_WriteData(0x20);
	SPI_WriteComm(0xD323);SPI_WriteData(0xAA);
	SPI_WriteComm(0xD324);SPI_WriteData(0x28);
	SPI_WriteComm(0xD325);SPI_WriteData(0x30);
	SPI_WriteComm(0xD326);SPI_WriteData(0x3A);
	SPI_WriteComm(0xD327);SPI_WriteData(0x44);
	SPI_WriteComm(0xD328);SPI_WriteData(0xAA);
	SPI_WriteComm(0xD329);SPI_WriteData(0x52);
	SPI_WriteComm(0xD32A);SPI_WriteData(0x66);
	SPI_WriteComm(0xD32B);SPI_WriteData(0x86);
	SPI_WriteComm(0xD32C);SPI_WriteData(0xC5);
	SPI_WriteComm(0xD32D);SPI_WriteData(0xFF);
	SPI_WriteComm(0xD32E);SPI_WriteData(0x00);
	SPI_WriteComm(0xD32F);SPI_WriteData(0x51);
	SPI_WriteComm(0xD330);SPI_WriteData(0x8D);
	SPI_WriteComm(0xD331);SPI_WriteData(0xC4);
	SPI_WriteComm(0xD332);SPI_WriteData(0x0F);
	SPI_WriteComm(0xD333);SPI_WriteData(0xE0);
	SPI_WriteComm(0xD334);SPI_WriteData(0xFF);
	SPI_WriteComm(0xD400);SPI_WriteData(0x00);//Gamma setting Red
	SPI_WriteComm(0xD401);SPI_WriteData(0x00);
	SPI_WriteComm(0xD402);SPI_WriteData(0x22);
	SPI_WriteComm(0xD403);SPI_WriteData(0x55);
	SPI_WriteComm(0xD404);SPI_WriteData(0x78);
	SPI_WriteComm(0xD405);SPI_WriteData(0x40);
	SPI_WriteComm(0xD406);SPI_WriteData(0x93);
	SPI_WriteComm(0xD407);SPI_WriteData(0xBF);
	SPI_WriteComm(0xD408);SPI_WriteData(0xE0);
	SPI_WriteComm(0xD409);SPI_WriteData(0x10);
	SPI_WriteComm(0xD40A);SPI_WriteData(0x55);
	SPI_WriteComm(0xD40B);SPI_WriteData(0x33);
	SPI_WriteComm(0xD40C);SPI_WriteData(0x4F);
	SPI_WriteComm(0xD40D);SPI_WriteData(0x66);
	SPI_WriteComm(0xD40E);SPI_WriteData(0x7A);
	SPI_WriteComm(0xD40F);SPI_WriteData(0x55);
	SPI_WriteComm(0xD410);SPI_WriteData(0x8C);
	SPI_WriteComm(0xD411);SPI_WriteData(0x9C);
	SPI_WriteComm(0xD412);SPI_WriteData(0xA9);
	SPI_WriteComm(0xD413);SPI_WriteData(0xB6);
	SPI_WriteComm(0xD414);SPI_WriteData(0x55);
	SPI_WriteComm(0xD415);SPI_WriteData(0xC2);
	SPI_WriteComm(0xD416);SPI_WriteData(0xCE);
	SPI_WriteComm(0xD417);SPI_WriteData(0xD8);
	SPI_WriteComm(0xD418);SPI_WriteData(0xE2);
	SPI_WriteComm(0xD419);SPI_WriteData(0x55);
	SPI_WriteComm(0xD41A);SPI_WriteData(0xEC);
	SPI_WriteComm(0xD41B);SPI_WriteData(0xED);
	SPI_WriteComm(0xD41C);SPI_WriteData(0xF6);
	SPI_WriteComm(0xD41D);SPI_WriteData(0xFF);
	SPI_WriteComm(0xD41E);SPI_WriteData(0xAA);
	SPI_WriteComm(0xD41F);SPI_WriteData(0x07);
	SPI_WriteComm(0xD420);SPI_WriteData(0x0F);
	SPI_WriteComm(0xD421);SPI_WriteData(0x17);
	SPI_WriteComm(0xD422);SPI_WriteData(0x20);
	SPI_WriteComm(0xD423);SPI_WriteData(0xAA);
	SPI_WriteComm(0xD424);SPI_WriteData(0x28);
	SPI_WriteComm(0xD425);SPI_WriteData(0x30);
	SPI_WriteComm(0xD426);SPI_WriteData(0x3A);
	SPI_WriteComm(0xD427);SPI_WriteData(0x44);
	SPI_WriteComm(0xD428);SPI_WriteData(0xAA);
	SPI_WriteComm(0xD429);SPI_WriteData(0x52);
	SPI_WriteComm(0xD42A);SPI_WriteData(0x66);
	SPI_WriteComm(0xD42B);SPI_WriteData(0x86);
	SPI_WriteComm(0xD42C);SPI_WriteData(0xC5);
	SPI_WriteComm(0xD42D);SPI_WriteData(0xFF);
	SPI_WriteComm(0xD42E);SPI_WriteData(0x00);
	SPI_WriteComm(0xD42F);SPI_WriteData(0x51);
	SPI_WriteComm(0xD430);SPI_WriteData(0x8D);
	SPI_WriteComm(0xD431);SPI_WriteData(0xC4);
	SPI_WriteComm(0xD432);SPI_WriteData(0x0F);
	SPI_WriteComm(0xD433);SPI_WriteData(0xE0);
	SPI_WriteComm(0xD434);SPI_WriteData(0xFF);
	SPI_WriteComm(0xD500);SPI_WriteData(0x00);//Gamma setting Green
	SPI_WriteComm(0xD501);SPI_WriteData(0x00);
	SPI_WriteComm(0xD502);SPI_WriteData(0x22);
	SPI_WriteComm(0xD503);SPI_WriteData(0x55);
	SPI_WriteComm(0xD504);SPI_WriteData(0x78);
	SPI_WriteComm(0xD505);SPI_WriteData(0x40);
	SPI_WriteComm(0xD506);SPI_WriteData(0x93);
	SPI_WriteComm(0xD507);SPI_WriteData(0xBF);
	SPI_WriteComm(0xD508);SPI_WriteData(0xE0);
	SPI_WriteComm(0xD509);SPI_WriteData(0x10);
	SPI_WriteComm(0xD50A);SPI_WriteData(0x55);
	SPI_WriteComm(0xD50B);SPI_WriteData(0x33);
	SPI_WriteComm(0xD50C);SPI_WriteData(0x4F);
	SPI_WriteComm(0xD50D);SPI_WriteData(0x66);
	SPI_WriteComm(0xD50E);SPI_WriteData(0x7A);
	SPI_WriteComm(0xD50F);SPI_WriteData(0x55);
	SPI_WriteComm(0xD510);SPI_WriteData(0x8C);
	SPI_WriteComm(0xD511);SPI_WriteData(0x9C);
	SPI_WriteComm(0xD512);SPI_WriteData(0xA9);
	SPI_WriteComm(0xD513);SPI_WriteData(0xB6);
	SPI_WriteComm(0xD514);SPI_WriteData(0x55);
	SPI_WriteComm(0xD515);SPI_WriteData(0xC2);
	SPI_WriteComm(0xD516);SPI_WriteData(0xCE);
	SPI_WriteComm(0xD517);SPI_WriteData(0xD8);
	SPI_WriteComm(0xD518);SPI_WriteData(0xE2);
	SPI_WriteComm(0xD519);SPI_WriteData(0x55);
	SPI_WriteComm(0xD51A);SPI_WriteData(0xEC);
	SPI_WriteComm(0xD51B);SPI_WriteData(0xED);
	SPI_WriteComm(0xD51C);SPI_WriteData(0xF6);
	SPI_WriteComm(0xD51D);SPI_WriteData(0xFF);
	SPI_WriteComm(0xD51E);SPI_WriteData(0xAA);
	SPI_WriteComm(0xD51F);SPI_WriteData(0x07);
	SPI_WriteComm(0xD520);SPI_WriteData(0x0F);
	SPI_WriteComm(0xD521);SPI_WriteData(0x17);
	SPI_WriteComm(0xD522);SPI_WriteData(0x20);
	SPI_WriteComm(0xD523);SPI_WriteData(0xAA);
	SPI_WriteComm(0xD524);SPI_WriteData(0x28);
	SPI_WriteComm(0xD525);SPI_WriteData(0x30);
	SPI_WriteComm(0xD526);SPI_WriteData(0x3A);
	SPI_WriteComm(0xD527);SPI_WriteData(0x44);
	SPI_WriteComm(0xD528);SPI_WriteData(0xAA);
	SPI_WriteComm(0xD529);SPI_WriteData(0x52);
	SPI_WriteComm(0xD52A);SPI_WriteData(0x66);
	SPI_WriteComm(0xD52B);SPI_WriteData(0x86);
	SPI_WriteComm(0xD52C);SPI_WriteData(0xC5);
	SPI_WriteComm(0xD52D);SPI_WriteData(0xFF);
	SPI_WriteComm(0xD52E);SPI_WriteData(0x00);
	SPI_WriteComm(0xD52F);SPI_WriteData(0x51);
	SPI_WriteComm(0xD530);SPI_WriteData(0x8D);
	SPI_WriteComm(0xD531);SPI_WriteData(0xC4);
	SPI_WriteComm(0xD532);SPI_WriteData(0x0F);
	SPI_WriteComm(0xD533);SPI_WriteData(0xE0);
	SPI_WriteComm(0xD534);SPI_WriteData(0xFF);
	SPI_WriteComm(0xD600);SPI_WriteData(0x00);//Gamma setting Blue
	SPI_WriteComm(0xD601);SPI_WriteData(0x00);
	SPI_WriteComm(0xD602);SPI_WriteData(0x22);
	SPI_WriteComm(0xD603);SPI_WriteData(0x55);
	SPI_WriteComm(0xD604);SPI_WriteData(0x78);
	SPI_WriteComm(0xD605);SPI_WriteData(0x40);
	SPI_WriteComm(0xD606);SPI_WriteData(0x93);
	SPI_WriteComm(0xD607);SPI_WriteData(0xBF);
	SPI_WriteComm(0xD608);SPI_WriteData(0xE0);
	SPI_WriteComm(0xD609);SPI_WriteData(0x10);
	SPI_WriteComm(0xD60A);SPI_WriteData(0x55);
	SPI_WriteComm(0xD60B);SPI_WriteData(0x33);
	SPI_WriteComm(0xD60C);SPI_WriteData(0x4F);
	SPI_WriteComm(0xD60D);SPI_WriteData(0x66);
	SPI_WriteComm(0xD60E);SPI_WriteData(0x7A);
	SPI_WriteComm(0xD60F);SPI_WriteData(0x55);
	SPI_WriteComm(0xD610);SPI_WriteData(0x8C);
	SPI_WriteComm(0xD611);SPI_WriteData(0x9C);
	SPI_WriteComm(0xD612);SPI_WriteData(0xA9);
	SPI_WriteComm(0xD613);SPI_WriteData(0xB6);
	SPI_WriteComm(0xD614);SPI_WriteData(0x55);
	SPI_WriteComm(0xD615);SPI_WriteData(0xC2);
	SPI_WriteComm(0xD616);SPI_WriteData(0xCE);
	SPI_WriteComm(0xD617);SPI_WriteData(0xD8);
	SPI_WriteComm(0xD618);SPI_WriteData(0xE2);
	SPI_WriteComm(0xD619);SPI_WriteData(0x55);
	SPI_WriteComm(0xD61A);SPI_WriteData(0xEC);
	SPI_WriteComm(0xD61B);SPI_WriteData(0xED);
	SPI_WriteComm(0xD61C);SPI_WriteData(0xF6);
	SPI_WriteComm(0xD61D);SPI_WriteData(0xFF);
	SPI_WriteComm(0xD61E);SPI_WriteData(0xAA);
	SPI_WriteComm(0xD61F);SPI_WriteData(0x07);
	SPI_WriteComm(0xD620);SPI_WriteData(0x0F);
	SPI_WriteComm(0xD621);SPI_WriteData(0x17);
	SPI_WriteComm(0xD622);SPI_WriteData(0x20);
	SPI_WriteComm(0xD623);SPI_WriteData(0xAA);
	SPI_WriteComm(0xD624);SPI_WriteData(0x28);
	SPI_WriteComm(0xD625);SPI_WriteData(0x30);
	SPI_WriteComm(0xD626);SPI_WriteData(0x3A);
	SPI_WriteComm(0xD627);SPI_WriteData(0x44);
	SPI_WriteComm(0xD628);SPI_WriteData(0xAA);
	SPI_WriteComm(0xD629);SPI_WriteData(0x52);
	SPI_WriteComm(0xD62A);SPI_WriteData(0x66);
	SPI_WriteComm(0xD62B);SPI_WriteData(0x86);
	SPI_WriteComm(0xD62C);SPI_WriteData(0xC5);
	SPI_WriteComm(0xD62D);SPI_WriteData(0xFF);
	SPI_WriteComm(0xD62E);SPI_WriteData(0x00);
	SPI_WriteComm(0xD62F);SPI_WriteData(0x51);
	SPI_WriteComm(0xD630);SPI_WriteData(0x8D);
	SPI_WriteComm(0xD631);SPI_WriteData(0xC4);
	SPI_WriteComm(0xD632);SPI_WriteData(0x0F);
	SPI_WriteComm(0xD633);SPI_WriteData(0xE0);
	SPI_WriteComm(0xD634);SPI_WriteData(0xFF);
	SPI_WriteComm(0xB000);SPI_WriteData(0x00);//AVDD
	SPI_WriteComm(0xB001);SPI_WriteData(0x00);
	SPI_WriteComm(0xB002);SPI_WriteData(0x00);
	SPI_WriteComm(0xB100);SPI_WriteData(0x05);//AVEE
	SPI_WriteComm(0xB101);SPI_WriteData(0x05);
	SPI_WriteComm(0xB102);SPI_WriteData(0x05);
	SPI_WriteComm(0xB600);SPI_WriteData(0x44);//AVDD Boosting
	SPI_WriteComm(0xB601);SPI_WriteData(0x44);
	SPI_WriteComm(0xB602);SPI_WriteData(0x44);
	SPI_WriteComm(0xB700);SPI_WriteData(0x34);//AVEE Boosting
	SPI_WriteComm(0xB701);SPI_WriteData(0x34);
	SPI_WriteComm(0xB702);SPI_WriteData(0x34);
	SPI_WriteComm(0xB900);SPI_WriteData(0x34);//VGH
	SPI_WriteComm(0xB901);SPI_WriteData(0x34);
	SPI_WriteComm(0xB902);SPI_WriteData(0x34);
	SPI_WriteComm(0xBA00);SPI_WriteData(0x14);//VGL
	SPI_WriteComm(0xBA01);SPI_WriteData(0x14);
	SPI_WriteComm(0xBA02);SPI_WriteData(0x14);
	SPI_WriteComm(0xBC00);SPI_WriteData(0x00);
	SPI_WriteComm(0xBC01);SPI_WriteData(0xB8);//VGMP
	SPI_WriteComm(0xBD00);SPI_WriteData(0x00);
	SPI_WriteComm(0xBD01);SPI_WriteData(0xB8);//VGMN
	SPI_WriteComm(0xBE00);SPI_WriteData(0x00);//VCOM
	SPI_WriteComm(0xBE01);SPI_WriteData(0x58);//VCOM
	SPI_WriteComm(0xF000);SPI_WriteData(0x55);//Enable Page 0
	SPI_WriteComm(0xF001);SPI_WriteData(0xAA);
	SPI_WriteComm(0xF002);SPI_WriteData(0x52);
	SPI_WriteComm(0xF003);SPI_WriteData(0x08);
	SPI_WriteComm(0xF004);SPI_WriteData(0x00);
	SPI_WriteComm(0xB400);SPI_WriteData(0x10);//Color Enhancement Enable
	SPI_WriteComm(0xB600);SPI_WriteData(0x02);//Source Output Control
	SPI_WriteComm(0xB000);SPI_WriteData(0x00);//Control Signal Polarity
	SPI_WriteComm(0xB100);SPI_WriteData(0xCC);//RAM Keep
	SPI_WriteComm(0xB101);SPI_WriteData(0x00);//Normal Scan
	delay_ms(10);//Delay 10ms
	
	SPI_WriteComm(0xB700);SPI_WriteData(0x22);//Gate EQ Control
	SPI_WriteComm(0xB701);SPI_WriteData(0x22);
	SPI_WriteComm(0xC800);SPI_WriteData(0x01);//Display Timing Control
	SPI_WriteComm(0xC801);SPI_WriteData(0x00);
	SPI_WriteComm(0xC802);SPI_WriteData(0x54);
	SPI_WriteComm(0xC803);SPI_WriteData(0x38);
	SPI_WriteComm(0xC804);SPI_WriteData(0x54);
	SPI_WriteComm(0xC805);SPI_WriteData(0x38);
	SPI_WriteComm(0xC806);SPI_WriteData(0x54);
	SPI_WriteComm(0xC807);SPI_WriteData(0x38);
	SPI_WriteComm(0xC808);SPI_WriteData(0x54);
	SPI_WriteComm(0xC809);SPI_WriteData(0x38);
	SPI_WriteComm(0xC80A);SPI_WriteData(0x8C);
	SPI_WriteComm(0xC80B);SPI_WriteData(0x2A);
	SPI_WriteComm(0xC80C);SPI_WriteData(0x2A);
	SPI_WriteComm(0xC80D);SPI_WriteData(0x8C);
	SPI_WriteComm(0xC80E);SPI_WriteData(0x8C);
	SPI_WriteComm(0xC80F);SPI_WriteData(0x2A);
	SPI_WriteComm(0xC810);SPI_WriteData(0x2A);
	SPI_WriteComm(0xB800);SPI_WriteData(0x01);//Source EQ Control
	SPI_WriteComm(0xB801);SPI_WriteData(0x03);
	SPI_WriteComm(0xB802);SPI_WriteData(0x03);
	SPI_WriteComm(0xB803);SPI_WriteData(0x03);
	SPI_WriteComm(0xBC00);SPI_WriteData(0x05);//Z-inversion
	SPI_WriteComm(0xBC01);SPI_WriteData(0x05);
	SPI_WriteComm(0xBC02);SPI_WriteData(0x05);
	SPI_WriteComm(0xD000);SPI_WriteData(0x01);//PWM_ENH_OE=1
	SPI_WriteComm(0xBA00);SPI_WriteData(0x01);//PRG=0
	SPI_WriteComm(0xBD00);SPI_WriteData(0x01);//Porch Lines
	SPI_WriteComm(0xBD01);SPI_WriteData(0x10);//Porch Lines
	SPI_WriteComm(0xBD02);SPI_WriteData(0x07);//Porch Lines
	SPI_WriteComm(0xBD03);SPI_WriteData(0x07);//Porch Lines
	SPI_WriteComm(0xBE00);SPI_WriteData(0x01);//Porch Lines
	SPI_WriteComm(0xBE01);SPI_WriteData(0x10);//Porch Lines
	SPI_WriteComm(0xBE02);SPI_WriteData(0x07);//Porch Lines
	SPI_WriteComm(0xBE03);SPI_WriteData(0x07);//Porch Lines
	SPI_WriteComm(0xBF00);SPI_WriteData(0x01);//Porch Lines
	SPI_WriteComm(0xBF01);SPI_WriteData(0x10);//Porch Lines
	SPI_WriteComm(0xBF02);SPI_WriteData(0x07);//Porch Lines
	SPI_WriteComm(0xBF03);SPI_WriteData(0x07);//Porch Lines
	SPI_WriteComm(0xF000);SPI_WriteData(0x55);//Enable Page 2
	SPI_WriteComm(0xF001);SPI_WriteData(0xAA);
	SPI_WriteComm(0xF002);SPI_WriteData(0x52);
	SPI_WriteComm(0xF003);SPI_WriteData(0x08);
	SPI_WriteComm(0xF004);SPI_WriteData(0x02);
	SPI_WriteComm(0xC300);SPI_WriteData(0x00);
	SPI_WriteComm(0xC301);SPI_WriteData(0xA9);
	SPI_WriteComm(0xFE00);SPI_WriteData(0x00);
	SPI_WriteComm(0xFE01);SPI_WriteData(0x94);
	SPI_WriteComm(0x3500);SPI_WriteData(0x00);//TE Enable
	SPI_WriteComm(0x3A00);SPI_WriteData(0x77);//Color Depth
	SPI_WriteComm(0x1100);SPI_WriteData(0x00);//Sleep out
	delay_ms(120);//delay 120ms
	
	SPI_WriteComm(0x2C00);SPI_WriteData(0x00);//Write frame memory
	delay_ms(100);
	//Write Pattern();
	
	SPI_WriteComm(0x2900);SPI_WriteData(0x00);//Display on
	delay_ms(100);//delay 100ms  
    #endif
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

