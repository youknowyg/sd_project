/*****************************************************
      start12.h - datastructures for startup
 ----------------------------------------------------
   Copyright (c) Metrowerks, Basel, Switzerland
               All rights reserved
                  Do not modify!
 *****************************************************/

#ifndef START12_H
#define START12_H

typedef struct _Range {
    unsigned char * beg; 
    int size;      // [beg..beg+size] 
} _Range;

typedef struct _Copy {
    int size; 
    unsigned char * dest;
} _Copy;


typedef void (*_PFunc)(void);

typedef struct _LibInit {
    _PFunc  *startup;      /* address of startup desc */
} _LibInit;

typedef struct _Cpp {
    _PFunc  initFunc;      /* address of init function */
} _Cpp;

#pragma DATA_SEG __NEAR_SEG STARTUP_DATA /* _startupData can be accessed using 16 bit accesses. This is needed because it contains the stack top, and without stack, far data cannot be accessed */

#ifdef __ELF_OBJECT_FILE_FORMAT__


/* ELF/DWARF object file format */
/* attention: the linker scans the debug information for these structures */
/* to obtain the available fields and their sizes. */
/* So do not change the names in this file. */
extern struct _tagStartup {
    unsigned char  flags;
    _PFunc         main;            // top level procedure of user program 
    Word           stackOffset;     // 16bit, initial value of the stack pointer 
    unsigned int   nofZeroOuts;     // number of zero out ranges 
    _Range *       pZeroOut;        // vector of ranges with nofZeroOuts elements 
    _Copy *        toCopyDownBeg;   // rom-address where copydown-data begins 
} _startupData;


#endif


#pragma DATA_SEG DEFAULT

#include "push.sgm"
#include "non_bank.sgm"            // the _Startup function must be in non banked memory 
#ifdef __cplusplus
extern "C"
#endif

// execution begins in _Startup 
#if defined(__SET_RESET_VECTOR__)
void __near __interrupt 0 _Startup(void);
#else
void _Startup(void);
#endif


/*--------------------------------------------------------------------*/
#ifdef __cplusplus
 }
#endif

#include "default.sgm"
#include "pop.sgm"

#endif

