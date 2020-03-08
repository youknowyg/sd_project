

#include "LCDDriver.h"
#include "LCDDisplay.h"
#include "SPI.h"
//#include "platform.h"
#include "EVE_Gpu.h"
#include "EVE_HAL.h"
#include "EVE_APP.h"
//#include "UI.h"
#include "UI_Bitmap.h"
#include "main.h"
extern SmControlStu	Smeter[Mc_MAX];


void LCD_DisplayInit(void)
{
    
//	LCD_Init();

	UI_INIT();// 772ms
   
    
	DispTest_Init();
    
	
}

unsigned int Cnt = 0;
unsigned char Dir = 0;
unsigned int pro_start1=0;

void LCD_DisplayProcess(void)
{
	
	DispTest(Smeter[Mc_Speed].inp,pro_start1/10);
}

#if 0
void LCD_DisplayProcess(void)
{
	
	DispTest(0);
}
#endif

