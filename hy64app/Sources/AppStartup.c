#include "hidef.h"
#include "startup.h"


void app(void);


/*  purpose:    1)  initialize the stack
                2)  initialize the RAM, copy down init data etc (Init)
                3)  call main;
    parameters: NONE
    called from: _PRESTART-code generated by the Linker
                 or directly referenced by the reset vector */

void _Startup(void) {

//   INIT_SP_FROM_STARTUP_DESC(); 

//   Init();  // zero out, copy down, call constructors 
   
   app();
}

