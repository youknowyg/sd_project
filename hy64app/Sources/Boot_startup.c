/**************************************** HY64 startup ****************************************/
/*  This is the templet for HY64 application startup routine work with Bootloader,            */
/*  DO NOT modify this file                                                                   */             
/*                                                                                            */
/*  r66193, Freescale China AutoLab                                                           */
/*  Dec, 16, 2009                                                                             */
/**********************************************************************************************/
#include <hidef.h>      
#include "mc9s12hy64.h"
#include "startup.h"

#pragma  CODE_SEG  BOOT_SEG 


static void ZeroOut(struct _tagStartup *_startupData);
static void CopyDown(struct _tagStartup *_startupData);
void main(void);

typedef void(* APPFn)(void);
APPFn Jump2Main;

void app(void) 
{   
      
    
    INIT_SP_FROM_STARTUP_DESC(); 

    ZeroOut( (struct _tagStartup *)&_startupData.flags );
    CopyDown( (struct _tagStartup *)&_startupData.flags );    



    
    IVBR = 0x14;   // relocate interrupt table to 0x1400;

// To simulate the bootloader invoking enviroment, 2 methods can be used here:

/******************** Method1: call absolute address directly **********************/
/* note: address = PPAGE + Local Address                                           */
/***********************************************************************************/ 
//  (*(APPFn)MAIN_LOGICAL_ADDRESS)();

/******************** Method2: call a function pointer *****************************/  
/* note: address = Local Address + PPAGE                                           */
/***********************************************************************************/ 

//    Jump2Main = (APPFn)MAIN_FUNCTION_ADDRESS;    
//    (*Jump2Main)();

/* another method, however difficult to silumation in bootloader environment */
//    Jump2Main = main;
//    (*Jump2Main)();

      main();
}


// purpose: zero out RAM-areas where data is allocated.
static void ZeroOut(struct _tagStartup *_startupData) 
{
    int i, j;
    unsigned char *dst;
    _Range *r;
    
    r = _startupData->pZeroOut;
    for (i=0; i<_startupData->nofZeroOuts; i++) {
        dst = r->beg;
        j = r->size;
        do {
            *dst = '\0'; // zero out 
            dst++;
            j--;
        } while(j>0);
        r++;
    }
}


// purpose: initializes global variables with their values,
static void CopyDown(struct _tagStartup *_startupData) 
{
    int i;
    unsigned char *dst;
    int *p;

    p = (int*)_startupData->toCopyDownBeg;                   //1. p=&size
    while (*p != 0) {
        i = *p;                          // nof              //2. i=size
        p++;                                                 //3. p = (int*)(&(unsigned char *)dest)
        dst = (unsigned char*)*p;        // dstAddr          //4. dst = dest
        p++;
        do {                             // p points now into 'bytes' 
            *dst = *((unsigned char*)p); // copy byte-wise 
            dst++;
            ((char*)p)++;
            i--;
        } while (i>0);
    }
}



