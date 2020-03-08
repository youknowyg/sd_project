/***************************************************************************
   Startup.c - standard startup code
   The startup code may be optimized to special user requests

Note: ROM libraries are not implemented in this startup code
***************************************************************************/

#include "hidef.h"
#include "startup.h"


void app(void);

#pragma DATA_SEG __NEAR_SEG STARTUP_DATA //_startupData can be accessed using 16 bit accesses.

struct _tagStartup _startupData; // read-only: _startupData is allocated in ROM
                                 // and initialized by the linker 

#pragma DATA_SEG DEFAULT

// #include "default.sgm"

#define __FEED_COP_IN_HLI() 


#ifndef __ONLY_INIT_SP

/* purpose:     1) zero out RAM-areas where data is allocated   */
/*              2) copy initialization data from ROM to RAM     */
/*              3) call global constructors in C++              */
/*   called from: _Startup, LibInits                            */
static void Init(void)
{
   __asm {
ZeroOut:
#if defined(__HIWARE_OBJECT_FILE_FORMAT__) && defined(__LARGE__)
             LDX   _startupData.pZeroOut:1  ; in the large memory model in the HIWARE format, pZeroOut is a 24 bit pointer
#else
             LDX   _startupData.pZeroOut    ; *pZeroOut
#endif
             LDY   _startupData.nofZeroOuts ; nofZeroOuts
             BEQ   CopyDown                 ; if nothing to zero out

NextZeroOut: PSHY                           ; save nofZeroOuts
#if defined(FAR_DATA)
             LDAB  1,X+                     ; load page of destination address
             LDY   2,X+                     ; load offset of destination address
#if defined(__HCS12X__)
             STAB  __GPAGE_ADR__
#else /* defined(__HCS12X__) */
             __PIC_JSR(_SET_PAGE)           ; sets the page in the correct page register
#endif /* defined(__HCS12X__) */
#else   /* FAR_DATA */
             LDY   2,X+                     ; start address and advance *pZeroOut (X = X+4)
#endif  /* FAR_DATA */

#if defined(__HCS12X__) && defined(FAR_DATA)
             PSHX
             LDX   0,X                      ; byte count
#if defined(__OPTIMIZE_FOR_SIZE__)
             CLRA
NextWord:    GSTAA 1,Y+                     ; clear memory byte
             __FEED_COP_IN_HLI()            ; feed the COP if necessary /*lint !e505 !e522 asm code */
             DBNE  X, NextWord              ; dec byte count
#else
             LDD #0
             LSRX
             BEQ   LoopClrW1                ; do we copy more than 1 byte?
NextWord:    GSTD 2,Y+                      ; clear memory word
             __FEED_COP_IN_HLI()            ; feed the COP if necessary /*lint !e505 !e522 asm code */
             DBNE  X, NextWord              ; dec word count
LoopClrW1:
             BCC   LastClr                  ; handle last byte
             GSTAA 1,Y+											; handle last byte
LastClr:
#endif
             PULX
             LEAX  2,X
#elif defined(__OPTIMIZE_FOR_SIZE__)               /* -os, default */
             LDD   2,X+                     ; byte count
NextWord:    CLR   1,Y+                     ; clear memory byte
             __FEED_COP_IN_HLI()            ; feed the COP if necessary /*lint !e505 !e522 asm code */
             DBNE  D, NextWord              ; dec byte count
#else /* __OPTIMIZE_FOR_TIME__ */
             LDD   2,X+                     ; byte count
             LSRD                           ; /2 and save bit 0 in the carry
             BEQ   LoopClrW1                ; do we copy more than 1 byte?
             PSHX
             LDX   #0
LoopClrW:    STX   2,Y+                     ; Word-Clear
             __FEED_COP_IN_HLI()            ; feed the COP if necessary /*lint !e505 !e522 asm code */
             DBNE  D, LoopClrW
             PULX
LoopClrW1:
             BCC   LastClr                  ; handle last byte
             CLR   1,Y+
LastClr:
#endif /* __OPTIMIZE_FOR_SIZE__/__OPTIMIZE_FOR_TIME__ */
             PULY                           ; restore nofZeroOuts
             DEY                            ; dec nofZeroOuts
             BNE  NextZeroOut
CopyDown:
#if defined(__BANKED_COPY_DOWN)
             LDAA  _startupData.toCopyDownBeg:0 ; get PAGE address of .copy section
             STAA	 __PPAGE_ADR__          ; set PPAGE address
             LDX   _startupData.toCopyDownBeg:1 ; load address of copy down desc.
#elif defined(__ELF_OBJECT_FILE_FORMAT__)
             LDX   _startupData.toCopyDownBeg ; load address of copy down desc.
#else
             LDX   _startupData.toCopyDownBeg:2 ; load address of copy down desc.
#endif
NextBlock:
             LDD   2,X+                     ; size of init-data -> D
             BEQ   funcInits                ; end of copy down desc.
#ifdef FAR_DATA
             PSHD                           ; save counter
             LDAB  1,X+                     ; load destination page
             LDY   2,X+                     ; destination address
#if defined(__HCS12X__)
             STAB  __GPAGE_ADR__
#else  /* __HCS12X__ */
             __PIC_JSR(_SET_PAGE)           ; sets the destinations page register
#endif /* __HCS12X__ */
             PULD                           ; restore counter
#else  /* FAR_DATA */
             LDY   2,X+                     ; load destination address
#endif /* FAR_DATA */

#if defined(__HCS12X__) && defined(FAR_DATA)
#if defined(__OPTIMIZE_FOR_SIZE__)               /* -os, default */
Copy:        PSHA
             LDAA  1,X+
             GSTAA  1,Y+                    ; move a byte from ROM to the data area
             PULA
             __FEED_COP_IN_HLI()            ; feed the COP if necessary /*lint !e505 !e522 asm code */
             DBNE  D,Copy                   ; copy-byte loop
#else
             LSRD                           ; /2 and save bit 0 in the carry
             BEQ    Copy1                   ; do we copy more than 1 byte?

Copy:        PSHD
             LDD   2,X+
             GSTD  2,Y+                     ; move a word from ROM to the data area
             PULD
             __FEED_COP_IN_HLI()            ; feed the COP if necessary /*lint !e505 !e522 asm code */
             DBNE  D,Copy                   ; copy-word loop
Copy1:
             BCC   NextBlock                ; handle last byte?
             LDAA  1,X+
             GSTAA  1,Y+                    ; move a byte from ROM to the data area
#endif
#elif defined(__OPTIMIZE_FOR_SIZE__)               /* -os, default */
Copy:        MOVB  1,X+,1,Y+                ; move a byte from ROM to the data area
             __FEED_COP_IN_HLI()            ; feed the COP if necessary /*lint !e505 !e522 asm code */
             DBNE  D,Copy                   ; copy-byte loop
#else /* __OPTIMIZE_FOR_TIME__ */
             LSRD                           ; /2 and save bit 0 in the carry
             BEQ   Copy1                    ; do we copy more than 1 byte?
Copy:        MOVW  2,X+,2,Y+                ; move a word from ROM to the data area
             __FEED_COP_IN_HLI()            ; feed the COP if necessary /*lint !e505 !e522 asm code */
             DBNE  D,Copy                   ; copy-word loop
Copy1:
             BCC   NextBlock                ; handle last byte?
             MOVB  1,X+,1,Y+                ; copy the last byte
#endif /* __OPTIMIZE_FOR_SIZE__/__OPTIMIZE_FOR_TIME__ */
             BRA   NextBlock
funcInits:                                  ; call of global construtors is only in c++ necessary
#if defined(__cplusplus)
#if defined(__ELF_OBJECT_FILE_FORMAT__)
#if defined( __BANKED__) || defined(__LARGE__)
             LDY   _startupData.nofInitBodies; load number of cpp.
             BEQ   done                     ; if cppcount == 0, goto done
             LDX   _startupData.initBodies  ; load address of first module to initialize
nextInit:
             LEAX   3,X                     ; increment to next init
             PSHX                           ; save address of next function to initialize
             PSHY                           ; save cpp counter
             CALL  [-3,X]                   ; use double indirect call to load the page register also
             PULY                           ; restore cpp counter
             PULX                           ; restore actual address
             DEY                            ; decrement cpp counter
             BNE    nextInit
#else  /* defined( __BANKED__) || defined(__LARGE__) */

             LDD   _startupData.nofInitBodies; load number of cpp.
             BEQ   done                     ; if cppcount == 0, goto done
             LDX   _startupData.initBodies  ; load address of first module to initialize
nextInit:
             LDY   2,X+                     ; load address of first module to initialize
             PSHD
             PSHX                           ; save actual address
             JSR   0,Y                      ; call initialization function
             PULX                           ; restore actual address
             PULD                           ; restore cpp counter
             DBNE D, nextInit
#endif /* defined( __BANKED__) || defined(__LARGE__) */
#else /* __ELF_OBJECT_FILE_FORMAT__  */
             LDX   _startupData.mInits      ; load address of first module to initialize
#if defined( __BANKED__) || defined(__LARGE__)
nextInit:    LDY   3,X+                     ; load address of initialization function
             BEQ   done                     ; stop when address  == 0
                                            ; in common environments the offset of a function is never 0, so this test could be avoided
#ifdef __InitFunctionsMayHaveOffset0__
             BRCLR -1,X, done, 0xff         ; stop when address  == 0
#endif  /* __InitFunctionsMayHaveOffset0__ */
             PSHX                           ; save address of next function to initialize
             CALL  [-3,X]                   ; use double indirect call to load the page register also
#else  /* defined( __BANKED__) || defined(__LARGE__) */
nextInit:
             LDY   2,X+                     ; load address of first module to initialize
             BEQ   done                     ; stop when address of function == 0
             PSHX                           ; save actual address
             JSR   0,Y                      ; call initialization function
#endif /* defined( __BANKED__) || defined(__LARGE__) */
             PULX                           ; restore actual address
             BRA   nextInit
#endif  /* __ELF_OBJECT_FILE_FORMAT__  */
done:
#endif /* __cplusplus */
   }
}
#endif /* __ONLY_INIT_SP */

#if defined( __ELF_OBJECT_FILE_FORMAT__) && defined(__cplusplus ) && 0 /* the call to main does not support to return anymore */

#if !defined(FAR_DATA) && (defined( __BANKED__) || defined(__LARGE__))
static void __far Fini(void)
#else
static void Fini(void)
#endif
{
/* purpose:     1) call global destructors in C++ */
   __asm {
#if defined( __BANKED__) || defined(__LARGE__)

             LDY   _startupData.nofFiniBodies; load number of cpp.
             BEQ   done                     ; if cppcount == 0, goto done
             LDX   _startupData.finiBodies  ; load address of first module to finalize
nextInit2:
             LEAX   3,X                     ; increment to next init
             PSHX                           ; save address of next function to finalize
             PSHY                           ; save cpp counter
             CALL  [-3,X]                   ; use double indirect call to load the page register also
             PULY                           ; restore cpp counter
             PULX                           ; restore actual address
             DEY                            ; decrement cpp counter
             BNE    nextInit2
#else  /* defined( __BANKED__) || defined(__LARGE__) */

             LDD   _startupData.nofFiniBodies; load number of cpp.
             BEQ   done                     ; if cppcount == 0, goto done
             LDX   _startupData.finiBodies  ; load address of first module to finalize
nextInit2:
             LDY   2,X+                     ; load address of first module to finalize
             PSHD
             PSHX                           ; save actual address
             JSR   0,Y                      ; call finalize function
             PULX                           ; restore actual address
             PULD                           ; restore cpp counter
             DBNE D, nextInit2
#endif /* defined(__BANKED__) || defined(__LARGE__) */
done:;
   }
}
#endif


#include "non_bank.sgm"

/* The function _Startup must be called in order to initialize global variables and to call main */
/* You can adapt this function or call it from your startup code to implement a different startup */
/* functionality. */

/* You should also setup the needed IO registers as WINDEF (HC12A4 only) or the COP registers to run */
/* on hardware */

/* to set the reset vector several ways are possible : */
/* 1. define the function with "interrupt 0" as done below in the first case */
/* 2. add the following line to your prm file : VECTOR ADDRESS 0xfffe _Startup */
/* of course, even more posibilities exists */
/* the reset vector must be set so that the application has a defined entry point */
extern void app(void);
void _Startup(void) {
/*  purpose:    1)  initialize the stack
                2)  initialize the RAM, copy down init data etc (Init)
                3)  call main;
    parameters: NONE
    called from: _PRESTART-code generated by the Linker
                 or directly referenced by the reset vector */

// initialize the stack pointer 
//   INIT_SP_FROM_STARTUP_DESC(); 

//   Init();  // zero out, copy down, call constructors 
   
   app();
}
