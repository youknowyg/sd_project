/* Based on CPU DB MC9S12HY64_100, version 3.00.011 (RegistersPrg V2.32) */
/*
** ###################################################################
**     Filename  : mc9s12hy48.h
**     Processor : MC9S12HY48CLL
**     FileFormat: V2.32
**     DataSheet : MC9S12HY64RMV1 Rev. 1.00 07/2009
**     Compiler  : CodeWarrior compiler
**     Date/Time : 8.6.2010, 8:45
**     Abstract  :
**         This header implements the mapping of I/O devices.
**
**     Copyright : 1997 - 2010 Freescale Semiconductor, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
**
**     CPU Registers Revisions:
**      - 1.7.2009, V3.00.0:
**              - Added PORTAB. REASON: Bug-fix (#7339 in Issue Manager).
**      - 14.4.2010, V3.00.1:
**              - Removed NVDFPROT[DPS4] bit to match definition with DFPROT register.
**
**     File-Format-Revisions:
**      - 17.3.2009, V2.27 :
**               - Merged bit-group is not generated, if the name matches with another bit name in the register
**      - 6.4.2009, V2.28 :
**               - Fixed generation of merged bits for bit-groups with a digit at the end, if group-name is defined in CPUDB
**      - 3.8.2009, V2.29 :
**               - If there is just one bits group matching register name, single bits are not generated
**      - 10.9.2009, V2.30 :
**               - Fixed generation of registers arrays.
**      - 15.10.2009, V2.31 :
**               - Changes have not affected this file (because they are related to another family)
**      - 18.05.2010, V2.32 :
**               - MISRA compliance: U/UL suffixes added to all numbers (_MASK,_BITNUM and addresses)
**
**     Not all general-purpose I/O pins are available on all packages or on all mask sets of a specific
**     derivative device. To avoid extra current drain from floating input pins, the user’s reset
**     initialization routine in the application program must either enable on-chip pull-up devices
**     or change the direction of unconnected pins to outputs so the pins do not float.
** ###################################################################
*/

#ifndef _MC9S12HY48_H
#define _MC9S12HY48_H

/*lint -save  -e950 -esym(960,18.4) -e46 -esym(961,19.7) Disable MISRA rule (1.1,18.4,6.4,19.7) checking. */
/* Types definition */
typedef unsigned char byte;
typedef unsigned int word;
typedef unsigned long dword;
typedef unsigned long dlong[2];

#define REG_BASE 0x0000                /* Base address for the I/O register block */


#pragma MESSAGE DISABLE C1106 /* WARNING C1106: Non-standard bitfield type */
#pragma OPTION ADD V30toV31Compatible "-BfaGapLimitBits4294967295" /*this guarantee correct bitfield positions*/

/**************** interrupt vector numbers ****************/
#define VectorNumber_Vsi                63U
#define VectorNumber_VReserved62        62U
#define VectorNumber_Vatdcompare        61U
#define VectorNumber_Vhti               60U
#define VectorNumber_Vapi               59U
#define VectorNumber_Vlvi               58U
#define VectorNumber_Vpwmesdn           57U
#define VectorNumber_Vportt             56U
#define VectorNumber_VReserved55        55U
#define VectorNumber_VReserved54        54U
#define VectorNumber_VReserved53        53U
#define VectorNumber_Vmctimovf          52U
#define VectorNumber_VReserved51        51U
#define VectorNumber_Vtim1paie          50U
#define VectorNumber_Vtim1paaovf        49U
#define VectorNumber_Vtim1ovf           48U
#define VectorNumber_Vtim1ch7           47U
#define VectorNumber_Vtim1ch6           46U
#define VectorNumber_Vtim1ch5           45U
#define VectorNumber_Vtim1ch4           44U
#define VectorNumber_Vtim1ch3           43U
#define VectorNumber_Vtim1ch2           42U
#define VectorNumber_Vtim1ch1           41U
#define VectorNumber_Vtim1ch0           40U
#define VectorNumber_Vcantx             39U
#define VectorNumber_Vcanrx             38U
#define VectorNumber_Vcanerr            37U
#define VectorNumber_Vcanwkup           36U
#define VectorNumber_Vflash             35U
#define VectorNumber_Vflashfd           34U
#define VectorNumber_VReserved33        33U
#define VectorNumber_VReserved32        32U
#define VectorNumber_Viic               31U
#define VectorNumber_VReserved30        30U
#define VectorNumber_VReserved29        29U
#define VectorNumber_Vcpmuplllck        28U
#define VectorNumber_Vcpmuocsns         27U
#define VectorNumber_Vports             26U
#define VectorNumber_Vportr             25U
#define VectorNumber_Vportad            24U
#define VectorNumber_VReserved23        23U
#define VectorNumber_Vatd               22U
#define VectorNumber_VReserved21        21U
#define VectorNumber_Vsci               20U
#define VectorNumber_Vspi               19U
#define VectorNumber_Vtim0paie          18U
#define VectorNumber_Vtim0paaovf        17U
#define VectorNumber_Vtim0ovf           16U
#define VectorNumber_Vtim0ch7           15U
#define VectorNumber_Vtim0ch6           14U
#define VectorNumber_Vtim0ch5           13U
#define VectorNumber_Vtim0ch4           12U
#define VectorNumber_Vtim0ch3           11U
#define VectorNumber_Vtim0ch2           10U
#define VectorNumber_Vtim0ch1           9U
#define VectorNumber_Vtim0ch0           8U
#define VectorNumber_Vrti               7U
#define VectorNumber_Virq               6U
#define VectorNumber_Vxirq              5U
#define VectorNumber_Vswi               4U
#define VectorNumber_Vtrap              3U
#define VectorNumber_Vcop               2U
#define VectorNumber_Vclkmon            1U
#define VectorNumber_Vreset             0U

/**************** interrupt vector table ****************/
#define Vsi                             0xFF80U
#define VReserved62                     0xFF82U
#define Vatdcompare                     0xFF84U
#define Vhti                            0xFF86U
#define Vapi                            0xFF88U
#define Vlvi                            0xFF8AU
#define Vpwmesdn                        0xFF8CU
#define Vportt                          0xFF8EU
#define VReserved55                     0xFF90U
#define VReserved54                     0xFF92U
#define VReserved53                     0xFF94U
#define Vmctimovf                       0xFF96U
#define VReserved51                     0xFF98U
#define Vtim1paie                       0xFF9AU
#define Vtim1paaovf                     0xFF9CU
#define Vtim1ovf                        0xFF9EU
#define Vtim1ch7                        0xFFA0U
#define Vtim1ch6                        0xFFA2U
#define Vtim1ch5                        0xFFA4U
#define Vtim1ch4                        0xFFA6U
#define Vtim1ch3                        0xFFA8U
#define Vtim1ch2                        0xFFAAU
#define Vtim1ch1                        0xFFACU
#define Vtim1ch0                        0xFFAEU
#define Vcantx                          0xFFB0U
#define Vcanrx                          0xFFB2U
#define Vcanerr                         0xFFB4U
#define Vcanwkup                        0xFFB6U
#define Vflash                          0xFFB8U
#define Vflashfd                        0xFFBAU
#define VReserved33                     0xFFBCU
#define VReserved32                     0xFFBEU
#define Viic                            0xFFC0U
#define VReserved30                     0xFFC2U
#define VReserved29                     0xFFC4U
#define Vcpmuplllck                     0xFFC6U
#define Vcpmuocsns                      0xFFC8U
#define Vports                          0xFFCAU
#define Vportr                          0xFFCCU
#define Vportad                         0xFFCEU
#define VReserved23                     0xFFD0U
#define Vatd                            0xFFD2U
#define VReserved21                     0xFFD4U
#define Vsci                            0xFFD6U
#define Vspi                            0xFFD8U
#define Vtim0paie                       0xFFDAU
#define Vtim0paaovf                     0xFFDCU
#define Vtim0ovf                        0xFFDEU
#define Vtim0ch7                        0xFFE0U
#define Vtim0ch6                        0xFFE2U
#define Vtim0ch5                        0xFFE4U
#define Vtim0ch4                        0xFFE6U
#define Vtim0ch3                        0xFFE8U
#define Vtim0ch2                        0xFFEAU
#define Vtim0ch1                        0xFFECU
#define Vtim0ch0                        0xFFEEU
#define Vrti                            0xFFF0U
#define Virq                            0xFFF2U
#define Vxirq                           0xFFF4U
#define Vswi                            0xFFF6U
#define Vtrap                           0xFFF8U
#define Vcop                            0xFFFAU
#define Vclkmon                         0xFFFCU
#define Vreset                          0xFFFEU

/**************** registers I/O map ****************/

/*** PORTAB - Port AB Data Register; 0x00000000 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** PORTA - Port A Data Register; 0x00000000 ***/
    union {
      byte Byte;
      struct {
        byte PA0         :1;                                       /* Port A Bit 0 */
        byte PA1         :1;                                       /* Port A Bit 1 */
        byte PA2         :1;                                       /* Port A Bit 2 */
        byte PA3         :1;                                       /* Port A Bit 3 */
        byte PA4         :1;                                       /* Port A Bit 4 */
        byte PA5         :1;                                       /* Port A Bit 5 */
        byte PA6         :1;                                       /* Port A Bit 6 */
        byte PA7         :1;                                       /* Port A Bit 7 */
      } Bits;
    } PORTASTR;
    #define PORTA                       _PORTAB.Overlap_STR.PORTASTR.Byte
    #define PORTA_PA0                   _PORTAB.Overlap_STR.PORTASTR.Bits.PA0
    #define PORTA_PA1                   _PORTAB.Overlap_STR.PORTASTR.Bits.PA1
    #define PORTA_PA2                   _PORTAB.Overlap_STR.PORTASTR.Bits.PA2
    #define PORTA_PA3                   _PORTAB.Overlap_STR.PORTASTR.Bits.PA3
    #define PORTA_PA4                   _PORTAB.Overlap_STR.PORTASTR.Bits.PA4
    #define PORTA_PA5                   _PORTAB.Overlap_STR.PORTASTR.Bits.PA5
    #define PORTA_PA6                   _PORTAB.Overlap_STR.PORTASTR.Bits.PA6
    #define PORTA_PA7                   _PORTAB.Overlap_STR.PORTASTR.Bits.PA7
    
    #define PORTA_PA0_MASK              1U
    #define PORTA_PA1_MASK              2U
    #define PORTA_PA2_MASK              4U
    #define PORTA_PA3_MASK              8U
    #define PORTA_PA4_MASK              16U
    #define PORTA_PA5_MASK              32U
    #define PORTA_PA6_MASK              64U
    #define PORTA_PA7_MASK              128U
    

    /*** PORTB - Port B Data Register; 0x00000001 ***/
    union {
      byte Byte;
      struct {
        byte PB0         :1;                                       /* Port B Bit 0 */
        byte PB1         :1;                                       /* Port B Bit 1 */
        byte PB2         :1;                                       /* Port B Bit 2 */
        byte PB3         :1;                                       /* Port B Bit 3 */
        byte PB4         :1;                                       /* Port B Bit 4 */
        byte PB5         :1;                                       /* Port B Bit 5 */
        byte PB6         :1;                                       /* Port B Bit 6 */
        byte PB7         :1;                                       /* Port B Bit 7 */
      } Bits;
    } PORTBSTR;
    #define PORTB                       _PORTAB.Overlap_STR.PORTBSTR.Byte
    #define PORTB_PB0                   _PORTAB.Overlap_STR.PORTBSTR.Bits.PB0
    #define PORTB_PB1                   _PORTAB.Overlap_STR.PORTBSTR.Bits.PB1
    #define PORTB_PB2                   _PORTAB.Overlap_STR.PORTBSTR.Bits.PB2
    #define PORTB_PB3                   _PORTAB.Overlap_STR.PORTBSTR.Bits.PB3
    #define PORTB_PB4                   _PORTAB.Overlap_STR.PORTBSTR.Bits.PB4
    #define PORTB_PB5                   _PORTAB.Overlap_STR.PORTBSTR.Bits.PB5
    #define PORTB_PB6                   _PORTAB.Overlap_STR.PORTBSTR.Bits.PB6
    #define PORTB_PB7                   _PORTAB.Overlap_STR.PORTBSTR.Bits.PB7
    
    #define PORTB_PB0_MASK              1U
    #define PORTB_PB1_MASK              2U
    #define PORTB_PB2_MASK              4U
    #define PORTB_PB3_MASK              8U
    #define PORTB_PB4_MASK              16U
    #define PORTB_PB5_MASK              32U
    #define PORTB_PB6_MASK              64U
    #define PORTB_PB7_MASK              128U
    
  } Overlap_STR;

  struct {
    word PB0         :1;                                       /* Port B Bit 0 */
    word PB1         :1;                                       /* Port B Bit 1 */
    word PB2         :1;                                       /* Port B Bit 2 */
    word PB3         :1;                                       /* Port B Bit 3 */
    word PB4         :1;                                       /* Port B Bit 4 */
    word PB5         :1;                                       /* Port B Bit 5 */
    word PB6         :1;                                       /* Port B Bit 6 */
    word PB7         :1;                                       /* Port B Bit 7 */
    word PA0         :1;                                       /* Port A Bit 0 */
    word PA1         :1;                                       /* Port A Bit 1 */
    word PA2         :1;                                       /* Port A Bit 2 */
    word PA3         :1;                                       /* Port A Bit 3 */
    word PA4         :1;                                       /* Port A Bit 4 */
    word PA5         :1;                                       /* Port A Bit 5 */
    word PA6         :1;                                       /* Port A Bit 6 */
    word PA7         :1;                                       /* Port A Bit 7 */
  } Bits;
  struct {
    word grpPB   :8;
    word grpPA   :8;
  } MergedBits;
} PORTABSTR;
extern volatile PORTABSTR _PORTAB @(REG_BASE + 0x00000000UL);
#define PORTAB                          _PORTAB.Word
#define PORTAB_PB0                      _PORTAB.Bits.PB0
#define PORTAB_PB1                      _PORTAB.Bits.PB1
#define PORTAB_PB2                      _PORTAB.Bits.PB2
#define PORTAB_PB3                      _PORTAB.Bits.PB3
#define PORTAB_PB4                      _PORTAB.Bits.PB4
#define PORTAB_PB5                      _PORTAB.Bits.PB5
#define PORTAB_PB6                      _PORTAB.Bits.PB6
#define PORTAB_PB7                      _PORTAB.Bits.PB7
#define PORTAB_PA0                      _PORTAB.Bits.PA0
#define PORTAB_PA1                      _PORTAB.Bits.PA1
#define PORTAB_PA2                      _PORTAB.Bits.PA2
#define PORTAB_PA3                      _PORTAB.Bits.PA3
#define PORTAB_PA4                      _PORTAB.Bits.PA4
#define PORTAB_PA5                      _PORTAB.Bits.PA5
#define PORTAB_PA6                      _PORTAB.Bits.PA6
#define PORTAB_PA7                      _PORTAB.Bits.PA7
#define PORTAB_PB                       _PORTAB.MergedBits.grpPB
#define PORTAB_PA                       _PORTAB.MergedBits.grpPA

#define PORTAB_PB0_MASK                 1U
#define PORTAB_PB1_MASK                 2U
#define PORTAB_PB2_MASK                 4U
#define PORTAB_PB3_MASK                 8U
#define PORTAB_PB4_MASK                 16U
#define PORTAB_PB5_MASK                 32U
#define PORTAB_PB6_MASK                 64U
#define PORTAB_PB7_MASK                 128U
#define PORTAB_PA0_MASK                 256U
#define PORTAB_PA1_MASK                 512U
#define PORTAB_PA2_MASK                 1024U
#define PORTAB_PA3_MASK                 2048U
#define PORTAB_PA4_MASK                 4096U
#define PORTAB_PA5_MASK                 8192U
#define PORTAB_PA6_MASK                 16384U
#define PORTAB_PA7_MASK                 32768U
#define PORTAB_PB_MASK                  255U
#define PORTAB_PB_BITNUM                0U
#define PORTAB_PA_MASK                  65280U
#define PORTAB_PA_BITNUM                8U


/*** DDRAB - Port AB Data Direction Register; 0x00000002 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** DDRA - Port A Data Direction Register; 0x00000002 ***/
    union {
      byte Byte;
      struct {
        byte DDRA0       :1;                                       /* Data Direction Port A Bit 0 */
        byte DDRA1       :1;                                       /* Data Direction Port A Bit 1 */
        byte DDRA2       :1;                                       /* Data Direction Port A Bit 2 */
        byte DDRA3       :1;                                       /* Data Direction Port A Bit 3 */
        byte DDRA4       :1;                                       /* Data Direction Port A Bit 4 */
        byte DDRA5       :1;                                       /* Data Direction Port A Bit 5 */
        byte DDRA6       :1;                                       /* Data Direction Port A Bit 6 */
        byte DDRA7       :1;                                       /* Data Direction Port A Bit 7 */
      } Bits;
    } DDRASTR;
    #define DDRA                        _DDRAB.Overlap_STR.DDRASTR.Byte
    #define DDRA_DDRA0                  _DDRAB.Overlap_STR.DDRASTR.Bits.DDRA0
    #define DDRA_DDRA1                  _DDRAB.Overlap_STR.DDRASTR.Bits.DDRA1
    #define DDRA_DDRA2                  _DDRAB.Overlap_STR.DDRASTR.Bits.DDRA2
    #define DDRA_DDRA3                  _DDRAB.Overlap_STR.DDRASTR.Bits.DDRA3
    #define DDRA_DDRA4                  _DDRAB.Overlap_STR.DDRASTR.Bits.DDRA4
    #define DDRA_DDRA5                  _DDRAB.Overlap_STR.DDRASTR.Bits.DDRA5
    #define DDRA_DDRA6                  _DDRAB.Overlap_STR.DDRASTR.Bits.DDRA6
    #define DDRA_DDRA7                  _DDRAB.Overlap_STR.DDRASTR.Bits.DDRA7
    
    #define DDRA_DDRA0_MASK             1U
    #define DDRA_DDRA1_MASK             2U
    #define DDRA_DDRA2_MASK             4U
    #define DDRA_DDRA3_MASK             8U
    #define DDRA_DDRA4_MASK             16U
    #define DDRA_DDRA5_MASK             32U
    #define DDRA_DDRA6_MASK             64U
    #define DDRA_DDRA7_MASK             128U
    

    /*** DDRB - Port B Data Direction Register; 0x00000003 ***/
    union {
      byte Byte;
      struct {
        byte DDRB0       :1;                                       /* Data Direction Port B Bit 0 */
        byte DDRB1       :1;                                       /* Data Direction Port B Bit 1 */
        byte DDRB2       :1;                                       /* Data Direction Port B Bit 2 */
        byte DDRB3       :1;                                       /* Data Direction Port B Bit 3 */
        byte DDRB4       :1;                                       /* Data Direction Port B Bit 4 */
        byte DDRB5       :1;                                       /* Data Direction Port B Bit 5 */
        byte DDRB6       :1;                                       /* Data Direction Port B Bit 6 */
        byte DDRB7       :1;                                       /* Data Direction Port B Bit 7 */
      } Bits;
    } DDRBSTR;
    #define DDRB                        _DDRAB.Overlap_STR.DDRBSTR.Byte
    #define DDRB_DDRB0                  _DDRAB.Overlap_STR.DDRBSTR.Bits.DDRB0
    #define DDRB_DDRB1                  _DDRAB.Overlap_STR.DDRBSTR.Bits.DDRB1
    #define DDRB_DDRB2                  _DDRAB.Overlap_STR.DDRBSTR.Bits.DDRB2
    #define DDRB_DDRB3                  _DDRAB.Overlap_STR.DDRBSTR.Bits.DDRB3
    #define DDRB_DDRB4                  _DDRAB.Overlap_STR.DDRBSTR.Bits.DDRB4
    #define DDRB_DDRB5                  _DDRAB.Overlap_STR.DDRBSTR.Bits.DDRB5
    #define DDRB_DDRB6                  _DDRAB.Overlap_STR.DDRBSTR.Bits.DDRB6
    #define DDRB_DDRB7                  _DDRAB.Overlap_STR.DDRBSTR.Bits.DDRB7
    
    #define DDRB_DDRB0_MASK             1U
    #define DDRB_DDRB1_MASK             2U
    #define DDRB_DDRB2_MASK             4U
    #define DDRB_DDRB3_MASK             8U
    #define DDRB_DDRB4_MASK             16U
    #define DDRB_DDRB5_MASK             32U
    #define DDRB_DDRB6_MASK             64U
    #define DDRB_DDRB7_MASK             128U
    
  } Overlap_STR;

  struct {
    word DDRB0       :1;                                       /* Data Direction Port B Bit 0 */
    word DDRB1       :1;                                       /* Data Direction Port B Bit 1 */
    word DDRB2       :1;                                       /* Data Direction Port B Bit 2 */
    word DDRB3       :1;                                       /* Data Direction Port B Bit 3 */
    word DDRB4       :1;                                       /* Data Direction Port B Bit 4 */
    word DDRB5       :1;                                       /* Data Direction Port B Bit 5 */
    word DDRB6       :1;                                       /* Data Direction Port B Bit 6 */
    word DDRB7       :1;                                       /* Data Direction Port B Bit 7 */
    word DDRA0       :1;                                       /* Data Direction Port A Bit 0 */
    word DDRA1       :1;                                       /* Data Direction Port A Bit 1 */
    word DDRA2       :1;                                       /* Data Direction Port A Bit 2 */
    word DDRA3       :1;                                       /* Data Direction Port A Bit 3 */
    word DDRA4       :1;                                       /* Data Direction Port A Bit 4 */
    word DDRA5       :1;                                       /* Data Direction Port A Bit 5 */
    word DDRA6       :1;                                       /* Data Direction Port A Bit 6 */
    word DDRA7       :1;                                       /* Data Direction Port A Bit 7 */
  } Bits;
  struct {
    word grpDDRB :8;
    word grpDDRA :8;
  } MergedBits;
} DDRABSTR;
extern volatile DDRABSTR _DDRAB @(REG_BASE + 0x00000002UL);
#define DDRAB                           _DDRAB.Word
#define DDRAB_DDRB0                     _DDRAB.Bits.DDRB0
#define DDRAB_DDRB1                     _DDRAB.Bits.DDRB1
#define DDRAB_DDRB2                     _DDRAB.Bits.DDRB2
#define DDRAB_DDRB3                     _DDRAB.Bits.DDRB3
#define DDRAB_DDRB4                     _DDRAB.Bits.DDRB4
#define DDRAB_DDRB5                     _DDRAB.Bits.DDRB5
#define DDRAB_DDRB6                     _DDRAB.Bits.DDRB6
#define DDRAB_DDRB7                     _DDRAB.Bits.DDRB7
#define DDRAB_DDRA0                     _DDRAB.Bits.DDRA0
#define DDRAB_DDRA1                     _DDRAB.Bits.DDRA1
#define DDRAB_DDRA2                     _DDRAB.Bits.DDRA2
#define DDRAB_DDRA3                     _DDRAB.Bits.DDRA3
#define DDRAB_DDRA4                     _DDRAB.Bits.DDRA4
#define DDRAB_DDRA5                     _DDRAB.Bits.DDRA5
#define DDRAB_DDRA6                     _DDRAB.Bits.DDRA6
#define DDRAB_DDRA7                     _DDRAB.Bits.DDRA7
#define DDRAB_DDRB                      _DDRAB.MergedBits.grpDDRB
#define DDRAB_DDRA                      _DDRAB.MergedBits.grpDDRA

#define DDRAB_DDRB0_MASK                1U
#define DDRAB_DDRB1_MASK                2U
#define DDRAB_DDRB2_MASK                4U
#define DDRAB_DDRB3_MASK                8U
#define DDRAB_DDRB4_MASK                16U
#define DDRAB_DDRB5_MASK                32U
#define DDRAB_DDRB6_MASK                64U
#define DDRAB_DDRB7_MASK                128U
#define DDRAB_DDRA0_MASK                256U
#define DDRAB_DDRA1_MASK                512U
#define DDRAB_DDRA2_MASK                1024U
#define DDRAB_DDRA3_MASK                2048U
#define DDRAB_DDRA4_MASK                4096U
#define DDRAB_DDRA5_MASK                8192U
#define DDRAB_DDRA6_MASK                16384U
#define DDRAB_DDRA7_MASK                32768U
#define DDRAB_DDRB_MASK                 255U
#define DDRAB_DDRB_BITNUM               0U
#define DDRAB_DDRA_MASK                 65280U
#define DDRAB_DDRA_BITNUM               8U


/*** MODE - Mode Register; 0x0000000B ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte MODC        :1;                                       /* Mode Select Bit */
  } Bits;
} MODESTR;
extern volatile MODESTR _MODE @(REG_BASE + 0x0000000BUL);
#define MODE                            _MODE.Byte
#define MODE_MODC                       _MODE.Bits.MODC

#define MODE_MODC_MASK                  128U


/*** PUCR - Pull-Up Control Register; 0x0000000C ***/
typedef union {
  byte Byte;
  struct {
    byte PUPAE       :1;                                       /* Pull-up Port A Enable */
    byte PUPBE       :1;                                       /* Pull-up Port B Enable */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte BKPUE       :1;                                       /* BKGD and VREGEN Pin Pull-up Enable */
    byte             :1; 
  } Bits;
} PUCRSTR;
extern volatile PUCRSTR _PUCR @(REG_BASE + 0x0000000CUL);
#define PUCR                            _PUCR.Byte
#define PUCR_PUPAE                      _PUCR.Bits.PUPAE
#define PUCR_PUPBE                      _PUCR.Bits.PUPBE
#define PUCR_BKPUE                      _PUCR.Bits.BKPUE

#define PUCR_PUPAE_MASK                 1U
#define PUCR_PUPBE_MASK                 2U
#define PUCR_BKPUE_MASK                 64U


/*** RDRIV - Reduced Drive Register; 0x0000000D ***/
typedef union {
  byte Byte;
  struct {
    byte RDPA        :1;                                       /* Reduced Drive of Port A */
    byte RDPB        :1;                                       /* Reduced Drive of Port B */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpRDPx :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} RDRIVSTR;
extern volatile RDRIVSTR _RDRIV @(REG_BASE + 0x0000000DUL);
#define RDRIV                           _RDRIV.Byte
#define RDRIV_RDPA                      _RDRIV.Bits.RDPA
#define RDRIV_RDPB                      _RDRIV.Bits.RDPB
#define RDRIV_RDPx                      _RDRIV.MergedBits.grpRDPx

#define RDRIV_RDPA_MASK                 1U
#define RDRIV_RDPB_MASK                 2U
#define RDRIV_RDPx_MASK                 3U
#define RDRIV_RDPx_BITNUM               0U


/*** DIRECT - Direct Page Register; 0x00000011 ***/
typedef union {
  byte Byte;
  struct {
    byte DP8         :1;                                       /* Direct Page Index Bit 8 */
    byte DP9         :1;                                       /* Direct Page Index Bit 9 */
    byte DP10        :1;                                       /* Direct Page Index Bit 10 */
    byte DP11        :1;                                       /* Direct Page Index Bit 11 */
    byte DP12        :1;                                       /* Direct Page Index Bit 12 */
    byte DP13        :1;                                       /* Direct Page Index Bit 13 */
    byte DP14        :1;                                       /* Direct Page Index Bit 14 */
    byte DP15        :1;                                       /* Direct Page Index Bit 15 */
  } Bits;
} DIRECTSTR;
extern volatile DIRECTSTR _DIRECT @(REG_BASE + 0x00000011UL);
#define DIRECT                          _DIRECT.Byte
#define DIRECT_DP8                      _DIRECT.Bits.DP8
#define DIRECT_DP9                      _DIRECT.Bits.DP9
#define DIRECT_DP10                     _DIRECT.Bits.DP10
#define DIRECT_DP11                     _DIRECT.Bits.DP11
#define DIRECT_DP12                     _DIRECT.Bits.DP12
#define DIRECT_DP13                     _DIRECT.Bits.DP13
#define DIRECT_DP14                     _DIRECT.Bits.DP14
#define DIRECT_DP15                     _DIRECT.Bits.DP15

#define DIRECT_DP8_MASK                 1U
#define DIRECT_DP9_MASK                 2U
#define DIRECT_DP10_MASK                4U
#define DIRECT_DP11_MASK                8U
#define DIRECT_DP12_MASK                16U
#define DIRECT_DP13_MASK                32U
#define DIRECT_DP14_MASK                64U
#define DIRECT_DP15_MASK                128U


/*** PPAGE - Program Page Index Register; 0x00000015 ***/
typedef union {
  byte Byte;
  struct {
    byte PIX0        :1;                                       /* Program Page Index Bit 0 */
    byte PIX1        :1;                                       /* Program Page Index Bit 1 */
    byte PIX2        :1;                                       /* Program Page Index Bit 2 */
    byte PIX3        :1;                                       /* Program Page Index Bit 3 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPIX  :4;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} PPAGESTR;
extern volatile PPAGESTR _PPAGE @(REG_BASE + 0x00000015UL);
#define PPAGE                           _PPAGE.Byte
#define PPAGE_PIX0                      _PPAGE.Bits.PIX0
#define PPAGE_PIX1                      _PPAGE.Bits.PIX1
#define PPAGE_PIX2                      _PPAGE.Bits.PIX2
#define PPAGE_PIX3                      _PPAGE.Bits.PIX3
#define PPAGE_PIX                       _PPAGE.MergedBits.grpPIX

#define PPAGE_PIX0_MASK                 1U
#define PPAGE_PIX1_MASK                 2U
#define PPAGE_PIX2_MASK                 4U
#define PPAGE_PIX3_MASK                 8U
#define PPAGE_PIX_MASK                  15U
#define PPAGE_PIX_BITNUM                0U


/*** PARTID - Part ID Register; 0x0000001A ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** PARTIDH - Part ID Register High; 0x0000001A ***/
    union {
      byte Byte;
      struct {
        byte ID8         :1;                                       /* Part ID Register Bit 8 */
        byte ID9         :1;                                       /* Part ID Register Bit 9 */
        byte ID10        :1;                                       /* Part ID Register Bit 10 */
        byte ID11        :1;                                       /* Part ID Register Bit 11 */
        byte ID12        :1;                                       /* Part ID Register Bit 12 */
        byte ID13        :1;                                       /* Part ID Register Bit 13 */
        byte ID14        :1;                                       /* Part ID Register Bit 14 */
        byte ID15        :1;                                       /* Part ID Register Bit 15 */
      } Bits;
    } PARTIDHSTR;
    #define PARTIDH                     _PARTID.Overlap_STR.PARTIDHSTR.Byte
    #define PARTIDH_ID8                 _PARTID.Overlap_STR.PARTIDHSTR.Bits.ID8
    #define PARTIDH_ID9                 _PARTID.Overlap_STR.PARTIDHSTR.Bits.ID9
    #define PARTIDH_ID10                _PARTID.Overlap_STR.PARTIDHSTR.Bits.ID10
    #define PARTIDH_ID11                _PARTID.Overlap_STR.PARTIDHSTR.Bits.ID11
    #define PARTIDH_ID12                _PARTID.Overlap_STR.PARTIDHSTR.Bits.ID12
    #define PARTIDH_ID13                _PARTID.Overlap_STR.PARTIDHSTR.Bits.ID13
    #define PARTIDH_ID14                _PARTID.Overlap_STR.PARTIDHSTR.Bits.ID14
    #define PARTIDH_ID15                _PARTID.Overlap_STR.PARTIDHSTR.Bits.ID15
    
    #define PARTIDH_ID8_MASK            1U
    #define PARTIDH_ID9_MASK            2U
    #define PARTIDH_ID10_MASK           4U
    #define PARTIDH_ID11_MASK           8U
    #define PARTIDH_ID12_MASK           16U
    #define PARTIDH_ID13_MASK           32U
    #define PARTIDH_ID14_MASK           64U
    #define PARTIDH_ID15_MASK           128U
    

    /*** PARTIDL - Part ID Register Low; 0x0000001B ***/
    union {
      byte Byte;
      struct {
        byte ID0         :1;                                       /* Part ID Register Bit 0 */
        byte ID1         :1;                                       /* Part ID Register Bit 1 */
        byte ID2         :1;                                       /* Part ID Register Bit 2 */
        byte ID3         :1;                                       /* Part ID Register Bit 3 */
        byte ID4         :1;                                       /* Part ID Register Bit 4 */
        byte ID5         :1;                                       /* Part ID Register Bit 5 */
        byte ID6         :1;                                       /* Part ID Register Bit 6 */
        byte ID7         :1;                                       /* Part ID Register Bit 7 */
      } Bits;
    } PARTIDLSTR;
    #define PARTIDL                     _PARTID.Overlap_STR.PARTIDLSTR.Byte
    #define PARTIDL_ID0                 _PARTID.Overlap_STR.PARTIDLSTR.Bits.ID0
    #define PARTIDL_ID1                 _PARTID.Overlap_STR.PARTIDLSTR.Bits.ID1
    #define PARTIDL_ID2                 _PARTID.Overlap_STR.PARTIDLSTR.Bits.ID2
    #define PARTIDL_ID3                 _PARTID.Overlap_STR.PARTIDLSTR.Bits.ID3
    #define PARTIDL_ID4                 _PARTID.Overlap_STR.PARTIDLSTR.Bits.ID4
    #define PARTIDL_ID5                 _PARTID.Overlap_STR.PARTIDLSTR.Bits.ID5
    #define PARTIDL_ID6                 _PARTID.Overlap_STR.PARTIDLSTR.Bits.ID6
    #define PARTIDL_ID7                 _PARTID.Overlap_STR.PARTIDLSTR.Bits.ID7
    
    #define PARTIDL_ID0_MASK            1U
    #define PARTIDL_ID1_MASK            2U
    #define PARTIDL_ID2_MASK            4U
    #define PARTIDL_ID3_MASK            8U
    #define PARTIDL_ID4_MASK            16U
    #define PARTIDL_ID5_MASK            32U
    #define PARTIDL_ID6_MASK            64U
    #define PARTIDL_ID7_MASK            128U
    
  } Overlap_STR;

  struct {
    word ID0         :1;                                       /* Part ID Register Bit 0 */
    word ID1         :1;                                       /* Part ID Register Bit 1 */
    word ID2         :1;                                       /* Part ID Register Bit 2 */
    word ID3         :1;                                       /* Part ID Register Bit 3 */
    word ID4         :1;                                       /* Part ID Register Bit 4 */
    word ID5         :1;                                       /* Part ID Register Bit 5 */
    word ID6         :1;                                       /* Part ID Register Bit 6 */
    word ID7         :1;                                       /* Part ID Register Bit 7 */
    word ID8         :1;                                       /* Part ID Register Bit 8 */
    word ID9         :1;                                       /* Part ID Register Bit 9 */
    word ID10        :1;                                       /* Part ID Register Bit 10 */
    word ID11        :1;                                       /* Part ID Register Bit 11 */
    word ID12        :1;                                       /* Part ID Register Bit 12 */
    word ID13        :1;                                       /* Part ID Register Bit 13 */
    word ID14        :1;                                       /* Part ID Register Bit 14 */
    word ID15        :1;                                       /* Part ID Register Bit 15 */
  } Bits;
} PARTIDSTR;
extern volatile PARTIDSTR _PARTID @(REG_BASE + 0x0000001AUL);
#define PARTID                          _PARTID.Word
#define PARTID_ID0                      _PARTID.Bits.ID0
#define PARTID_ID1                      _PARTID.Bits.ID1
#define PARTID_ID2                      _PARTID.Bits.ID2
#define PARTID_ID3                      _PARTID.Bits.ID3
#define PARTID_ID4                      _PARTID.Bits.ID4
#define PARTID_ID5                      _PARTID.Bits.ID5
#define PARTID_ID6                      _PARTID.Bits.ID6
#define PARTID_ID7                      _PARTID.Bits.ID7
#define PARTID_ID8                      _PARTID.Bits.ID8
#define PARTID_ID9                      _PARTID.Bits.ID9
#define PARTID_ID10                     _PARTID.Bits.ID10
#define PARTID_ID11                     _PARTID.Bits.ID11
#define PARTID_ID12                     _PARTID.Bits.ID12
#define PARTID_ID13                     _PARTID.Bits.ID13
#define PARTID_ID14                     _PARTID.Bits.ID14
#define PARTID_ID15                     _PARTID.Bits.ID15

#define PARTID_ID0_MASK                 1U
#define PARTID_ID1_MASK                 2U
#define PARTID_ID2_MASK                 4U
#define PARTID_ID3_MASK                 8U
#define PARTID_ID4_MASK                 16U
#define PARTID_ID5_MASK                 32U
#define PARTID_ID6_MASK                 64U
#define PARTID_ID7_MASK                 128U
#define PARTID_ID8_MASK                 256U
#define PARTID_ID9_MASK                 512U
#define PARTID_ID10_MASK                1024U
#define PARTID_ID11_MASK                2048U
#define PARTID_ID12_MASK                4096U
#define PARTID_ID13_MASK                8192U
#define PARTID_ID14_MASK                16384U
#define PARTID_ID15_MASK                32768U


/*** ECLKCTL - ECLK Control Register; 0x0000001C ***/
typedef union {
  byte Byte;
  struct {
    byte EDIV0       :1;                                       /* Free-running ECLK Divider, bit 0 */
    byte EDIV1       :1;                                       /* Free-running ECLK Divider, bit 1 */
    byte EDIV2       :1;                                       /* Free-running ECLK Divider, bit 2 */
    byte EDIV3       :1;                                       /* Free-running ECLK Divider, bit 3 */
    byte EDIV4       :1;                                       /* Free-running ECLK Divider, bit 4 */
    byte DIV16       :1;                                       /* Free-running ECLK predivider */
    byte             :1; 
    byte NECLK       :1;                                       /* No ECLK */
  } Bits;
  struct {
    byte grpEDIV :5;
    byte grpDIV_16 :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} ECLKCTLSTR;
extern volatile ECLKCTLSTR _ECLKCTL @(REG_BASE + 0x0000001CUL);
#define ECLKCTL                         _ECLKCTL.Byte
#define ECLKCTL_EDIV0                   _ECLKCTL.Bits.EDIV0
#define ECLKCTL_EDIV1                   _ECLKCTL.Bits.EDIV1
#define ECLKCTL_EDIV2                   _ECLKCTL.Bits.EDIV2
#define ECLKCTL_EDIV3                   _ECLKCTL.Bits.EDIV3
#define ECLKCTL_EDIV4                   _ECLKCTL.Bits.EDIV4
#define ECLKCTL_DIV16                   _ECLKCTL.Bits.DIV16
#define ECLKCTL_NECLK                   _ECLKCTL.Bits.NECLK
#define ECLKCTL_EDIV                    _ECLKCTL.MergedBits.grpEDIV

#define ECLKCTL_EDIV0_MASK              1U
#define ECLKCTL_EDIV1_MASK              2U
#define ECLKCTL_EDIV2_MASK              4U
#define ECLKCTL_EDIV3_MASK              8U
#define ECLKCTL_EDIV4_MASK              16U
#define ECLKCTL_DIV16_MASK              32U
#define ECLKCTL_NECLK_MASK              128U
#define ECLKCTL_EDIV_MASK               31U
#define ECLKCTL_EDIV_BITNUM             0U


/*** IRQCR - Interrupt Control Register; 0x0000001E ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte XIRQEN      :1;                                       /* XIRQ Enable */
    byte IRQEN       :1;                                       /* External IRQ Enable */
    byte IRQE        :1;                                       /* IRQ Select Edge Sensitive Only */
  } Bits;
} IRQCRSTR;
extern volatile IRQCRSTR _IRQCR @(REG_BASE + 0x0000001EUL);
#define IRQCR                           _IRQCR.Byte
#define IRQCR_XIRQEN                    _IRQCR.Bits.XIRQEN
#define IRQCR_IRQEN                     _IRQCR.Bits.IRQEN
#define IRQCR_IRQE                      _IRQCR.Bits.IRQE

#define IRQCR_XIRQEN_MASK               32U
#define IRQCR_IRQEN_MASK                64U
#define IRQCR_IRQE_MASK                 128U


/*** DBGC1 - Debug Control Register 1; 0x00000020 ***/
typedef union {
  byte Byte;
  struct {
    byte COMRV0      :1;                                       /* Comparator Register Visibility Bits, bit 0 */
    byte COMRV1      :1;                                       /* Comparator Register Visibility Bits, bit 1 */
    byte             :1; 
    byte DBGBRK      :1;                                       /* S12XDBG Breakpoint Enable Bit 1 */
    byte BDM         :1;                                       /* Background Debug Mode Enable */
    byte             :1; 
    byte TRIG        :1;                                       /* Immediate Trigger Request Bit */
    byte ARM         :1;                                       /* Arm Bit */
  } Bits;
  struct {
    byte grpCOMRV :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} DBGC1STR;
extern volatile DBGC1STR _DBGC1 @(REG_BASE + 0x00000020UL);
#define DBGC1                           _DBGC1.Byte
#define DBGC1_COMRV0                    _DBGC1.Bits.COMRV0
#define DBGC1_COMRV1                    _DBGC1.Bits.COMRV1
#define DBGC1_DBGBRK                    _DBGC1.Bits.DBGBRK
#define DBGC1_BDM                       _DBGC1.Bits.BDM
#define DBGC1_TRIG                      _DBGC1.Bits.TRIG
#define DBGC1_ARM                       _DBGC1.Bits.ARM
#define DBGC1_COMRV                     _DBGC1.MergedBits.grpCOMRV

#define DBGC1_COMRV0_MASK               1U
#define DBGC1_COMRV1_MASK               2U
#define DBGC1_DBGBRK_MASK               8U
#define DBGC1_BDM_MASK                  16U
#define DBGC1_TRIG_MASK                 64U
#define DBGC1_ARM_MASK                  128U
#define DBGC1_COMRV_MASK                3U
#define DBGC1_COMRV_BITNUM              0U


/*** DBGSR - Debug Status Register; 0x00000021 ***/
typedef union {
  byte Byte;
  struct {
    byte SSF0        :1;                                       /* State Sequencer Flag Bits */
    byte SSF1        :1;                                       /* State Sequencer Flag Bit 1 */
    byte SSF2        :1;                                       /* State Sequencer Flag Bit 2 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte TBF         :1;                                       /* Trace Buffer Full */
  } Bits;
  struct {
    byte grpSSF  :3;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} DBGSRSTR;
extern volatile DBGSRSTR _DBGSR @(REG_BASE + 0x00000021UL);
#define DBGSR                           _DBGSR.Byte
#define DBGSR_SSF0                      _DBGSR.Bits.SSF0
#define DBGSR_SSF1                      _DBGSR.Bits.SSF1
#define DBGSR_SSF2                      _DBGSR.Bits.SSF2
#define DBGSR_TBF                       _DBGSR.Bits.TBF
#define DBGSR_SSF                       _DBGSR.MergedBits.grpSSF

#define DBGSR_SSF0_MASK                 1U
#define DBGSR_SSF1_MASK                 2U
#define DBGSR_SSF2_MASK                 4U
#define DBGSR_TBF_MASK                  128U
#define DBGSR_SSF_MASK                  7U
#define DBGSR_SSF_BITNUM                0U


/*** DBGTCR - Debug Trace Control Register; 0x00000022 ***/
typedef union {
  byte Byte;
  struct {
    byte TALIGN      :1;                                       /* Trigger Align Bit */
    byte             :1; 
    byte TRCMOD0     :1;                                       /* Trace Mode Bits, bit 0 */
    byte TRCMOD1     :1;                                       /* Trace Mode Bits, bit 1 */
    byte             :1; 
    byte             :1; 
    byte TSOURCE     :1;                                       /* Trace Source Control Bits */
    byte             :1; 
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte grpTRCMOD :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} DBGTCRSTR;
extern volatile DBGTCRSTR _DBGTCR @(REG_BASE + 0x00000022UL);
#define DBGTCR                          _DBGTCR.Byte
#define DBGTCR_TALIGN                   _DBGTCR.Bits.TALIGN
#define DBGTCR_TRCMOD0                  _DBGTCR.Bits.TRCMOD0
#define DBGTCR_TRCMOD1                  _DBGTCR.Bits.TRCMOD1
#define DBGTCR_TSOURCE                  _DBGTCR.Bits.TSOURCE
#define DBGTCR_TRCMOD                   _DBGTCR.MergedBits.grpTRCMOD

#define DBGTCR_TALIGN_MASK              1U
#define DBGTCR_TRCMOD0_MASK             4U
#define DBGTCR_TRCMOD1_MASK             8U
#define DBGTCR_TSOURCE_MASK             64U
#define DBGTCR_TRCMOD_MASK              12U
#define DBGTCR_TRCMOD_BITNUM            2U


/*** DBGC2 - Debug Control Register 2; 0x00000023 ***/
typedef union {
  byte Byte;
  struct {
    byte ABCM0       :1;                                       /* A and B Comparator Match Control, bit 0 */
    byte ABCM1       :1;                                       /* A and B Comparator Match Control, bit 1 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpABCM :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} DBGC2STR;
extern volatile DBGC2STR _DBGC2 @(REG_BASE + 0x00000023UL);
#define DBGC2                           _DBGC2.Byte
#define DBGC2_ABCM0                     _DBGC2.Bits.ABCM0
#define DBGC2_ABCM1                     _DBGC2.Bits.ABCM1
#define DBGC2_ABCM                      _DBGC2.MergedBits.grpABCM

#define DBGC2_ABCM0_MASK                1U
#define DBGC2_ABCM1_MASK                2U
#define DBGC2_ABCM_MASK                 3U
#define DBGC2_ABCM_BITNUM               0U


/*** DBGTB - Debug Trace Buffer Register; 0x00000024 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** DBGTBH - Debug Trace Buffer Register High; 0x00000024 ***/
    union {
      byte Byte;
      struct {
        byte BIT8        :1;                                       /* Trace Buffer Data Bits */
        byte BIT9        :1;                                       /* Trace Buffer Data Bit 9 */
        byte BIT10       :1;                                       /* Trace Buffer Data Bit 10 */
        byte BIT11       :1;                                       /* Trace Buffer Data Bit 11 */
        byte BIT12       :1;                                       /* Trace Buffer Data Bit 12 */
        byte BIT13       :1;                                       /* Trace Buffer Data Bit 13 */
        byte BIT14       :1;                                       /* Trace Buffer Data Bit 14 */
        byte BIT15       :1;                                       /* Trace Buffer Data Bit 15 */
      } Bits;
    } DBGTBHSTR;
    #define DBGTBH                      _DBGTB.Overlap_STR.DBGTBHSTR.Byte
    #define DBGTBH_BIT8                 _DBGTB.Overlap_STR.DBGTBHSTR.Bits.BIT8
    #define DBGTBH_BIT9                 _DBGTB.Overlap_STR.DBGTBHSTR.Bits.BIT9
    #define DBGTBH_BIT10                _DBGTB.Overlap_STR.DBGTBHSTR.Bits.BIT10
    #define DBGTBH_BIT11                _DBGTB.Overlap_STR.DBGTBHSTR.Bits.BIT11
    #define DBGTBH_BIT12                _DBGTB.Overlap_STR.DBGTBHSTR.Bits.BIT12
    #define DBGTBH_BIT13                _DBGTB.Overlap_STR.DBGTBHSTR.Bits.BIT13
    #define DBGTBH_BIT14                _DBGTB.Overlap_STR.DBGTBHSTR.Bits.BIT14
    #define DBGTBH_BIT15                _DBGTB.Overlap_STR.DBGTBHSTR.Bits.BIT15
    
    #define DBGTBH_BIT8_MASK            1U
    #define DBGTBH_BIT9_MASK            2U
    #define DBGTBH_BIT10_MASK           4U
    #define DBGTBH_BIT11_MASK           8U
    #define DBGTBH_BIT12_MASK           16U
    #define DBGTBH_BIT13_MASK           32U
    #define DBGTBH_BIT14_MASK           64U
    #define DBGTBH_BIT15_MASK           128U
    

    /*** DBGTBL - Debug Trace Buffer Register Low; 0x00000025 ***/
    union {
      byte Byte;
      struct {
        byte BIT0        :1;                                       /* Trace Buffer Data Bits */
        byte BIT1        :1;                                       /* Trace Buffer Data Bit 1 */
        byte BIT2        :1;                                       /* Trace Buffer Data Bit 2 */
        byte BIT3        :1;                                       /* Trace Buffer Data Bit 3 */
        byte BIT4        :1;                                       /* Trace Buffer Data Bit 4 */
        byte BIT5        :1;                                       /* Trace Buffer Data Bit 5 */
        byte BIT6        :1;                                       /* Trace Buffer Data Bit 6 */
        byte BIT7        :1;                                       /* Trace Buffer Data Bit 7 */
      } Bits;
    } DBGTBLSTR;
    #define DBGTBL                      _DBGTB.Overlap_STR.DBGTBLSTR.Byte
    #define DBGTBL_BIT0                 _DBGTB.Overlap_STR.DBGTBLSTR.Bits.BIT0
    #define DBGTBL_BIT1                 _DBGTB.Overlap_STR.DBGTBLSTR.Bits.BIT1
    #define DBGTBL_BIT2                 _DBGTB.Overlap_STR.DBGTBLSTR.Bits.BIT2
    #define DBGTBL_BIT3                 _DBGTB.Overlap_STR.DBGTBLSTR.Bits.BIT3
    #define DBGTBL_BIT4                 _DBGTB.Overlap_STR.DBGTBLSTR.Bits.BIT4
    #define DBGTBL_BIT5                 _DBGTB.Overlap_STR.DBGTBLSTR.Bits.BIT5
    #define DBGTBL_BIT6                 _DBGTB.Overlap_STR.DBGTBLSTR.Bits.BIT6
    #define DBGTBL_BIT7                 _DBGTB.Overlap_STR.DBGTBLSTR.Bits.BIT7
    
    #define DBGTBL_BIT0_MASK            1U
    #define DBGTBL_BIT1_MASK            2U
    #define DBGTBL_BIT2_MASK            4U
    #define DBGTBL_BIT3_MASK            8U
    #define DBGTBL_BIT4_MASK            16U
    #define DBGTBL_BIT5_MASK            32U
    #define DBGTBL_BIT6_MASK            64U
    #define DBGTBL_BIT7_MASK            128U
    
  } Overlap_STR;

  struct {
    word BIT0        :1;                                       /* Trace Buffer Data Bits */
    word BIT1        :1;                                       /* Trace Buffer Data Bit 1 */
    word BIT2        :1;                                       /* Trace Buffer Data Bit 2 */
    word BIT3        :1;                                       /* Trace Buffer Data Bit 3 */
    word BIT4        :1;                                       /* Trace Buffer Data Bit 4 */
    word BIT5        :1;                                       /* Trace Buffer Data Bit 5 */
    word BIT6        :1;                                       /* Trace Buffer Data Bit 6 */
    word BIT7        :1;                                       /* Trace Buffer Data Bit 7 */
    word BIT8        :1;                                       /* Trace Buffer Data Bit 8 */
    word BIT9        :1;                                       /* Trace Buffer Data Bit 9 */
    word BIT10       :1;                                       /* Trace Buffer Data Bit 10 */
    word BIT11       :1;                                       /* Trace Buffer Data Bit 11 */
    word BIT12       :1;                                       /* Trace Buffer Data Bit 12 */
    word BIT13       :1;                                       /* Trace Buffer Data Bit 13 */
    word BIT14       :1;                                       /* Trace Buffer Data Bit 14 */
    word BIT15       :1;                                       /* Trace Buffer Data Bit 15 */
  } Bits;
} DBGTBSTR;
extern volatile DBGTBSTR _DBGTB @(REG_BASE + 0x00000024UL);
#define DBGTB                           _DBGTB.Word
#define DBGTB_BIT0                      _DBGTB.Bits.BIT0
#define DBGTB_BIT1                      _DBGTB.Bits.BIT1
#define DBGTB_BIT2                      _DBGTB.Bits.BIT2
#define DBGTB_BIT3                      _DBGTB.Bits.BIT3
#define DBGTB_BIT4                      _DBGTB.Bits.BIT4
#define DBGTB_BIT5                      _DBGTB.Bits.BIT5
#define DBGTB_BIT6                      _DBGTB.Bits.BIT6
#define DBGTB_BIT7                      _DBGTB.Bits.BIT7
#define DBGTB_BIT8                      _DBGTB.Bits.BIT8
#define DBGTB_BIT9                      _DBGTB.Bits.BIT9
#define DBGTB_BIT10                     _DBGTB.Bits.BIT10
#define DBGTB_BIT11                     _DBGTB.Bits.BIT11
#define DBGTB_BIT12                     _DBGTB.Bits.BIT12
#define DBGTB_BIT13                     _DBGTB.Bits.BIT13
#define DBGTB_BIT14                     _DBGTB.Bits.BIT14
#define DBGTB_BIT15                     _DBGTB.Bits.BIT15

#define DBGTB_BIT0_MASK                 1U
#define DBGTB_BIT1_MASK                 2U
#define DBGTB_BIT2_MASK                 4U
#define DBGTB_BIT3_MASK                 8U
#define DBGTB_BIT4_MASK                 16U
#define DBGTB_BIT5_MASK                 32U
#define DBGTB_BIT6_MASK                 64U
#define DBGTB_BIT7_MASK                 128U
#define DBGTB_BIT8_MASK                 256U
#define DBGTB_BIT9_MASK                 512U
#define DBGTB_BIT10_MASK                1024U
#define DBGTB_BIT11_MASK                2048U
#define DBGTB_BIT12_MASK                4096U
#define DBGTB_BIT13_MASK                8192U
#define DBGTB_BIT14_MASK                16384U
#define DBGTB_BIT15_MASK                32768U


/*** DBGCNT - Debug Count Register; 0x00000026 ***/
typedef union {
  byte Byte;
  struct {
    byte CNT0        :1;                                       /* Count Value, bit 0 */
    byte CNT1        :1;                                       /* Count Value, bit 1 */
    byte CNT2        :1;                                       /* Count Value, bit 2 */
    byte CNT3        :1;                                       /* Count Value, bit 3 */
    byte CNT4        :1;                                       /* Count Value, bit 4 */
    byte CNT5        :1;                                       /* Count Value, bit 5 */
    byte             :1; 
    byte TBF         :1;                                       /* Trace Buffer Full */
  } Bits;
  struct {
    byte grpCNT  :6;
    byte         :1;
    byte         :1;
  } MergedBits;
} DBGCNTSTR;
extern volatile DBGCNTSTR _DBGCNT @(REG_BASE + 0x00000026UL);
#define DBGCNT                          _DBGCNT.Byte
#define DBGCNT_CNT0                     _DBGCNT.Bits.CNT0
#define DBGCNT_CNT1                     _DBGCNT.Bits.CNT1
#define DBGCNT_CNT2                     _DBGCNT.Bits.CNT2
#define DBGCNT_CNT3                     _DBGCNT.Bits.CNT3
#define DBGCNT_CNT4                     _DBGCNT.Bits.CNT4
#define DBGCNT_CNT5                     _DBGCNT.Bits.CNT5
#define DBGCNT_TBF                      _DBGCNT.Bits.TBF
#define DBGCNT_CNT                      _DBGCNT.MergedBits.grpCNT

#define DBGCNT_CNT0_MASK                1U
#define DBGCNT_CNT1_MASK                2U
#define DBGCNT_CNT2_MASK                4U
#define DBGCNT_CNT3_MASK                8U
#define DBGCNT_CNT4_MASK                16U
#define DBGCNT_CNT5_MASK                32U
#define DBGCNT_TBF_MASK                 128U
#define DBGCNT_CNT_MASK                 63U
#define DBGCNT_CNT_BITNUM               0U


/*** DBGSCRX - Debug State Control Register; 0x00000027 ***/
typedef union {
  byte Byte;
  union { /* Several registers at the same address */
    /*** DBGSCRX - Debug State Control Register; Several registers at the same address ***/
    union {
      struct {
        byte SC0         :1;                                       /* State X Sequencer Next State Selection Bit 0 */
        byte SC1         :1;                                       /* State X Sequencer Next State Selection Bit 1 */
        byte SC2         :1;                                       /* State X Sequencer Next State Selection Bit 2 */
        byte SC3         :1;                                       /* State X Sequencer Next State Selection Bit 3 */
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
      } Bits;
      struct {
        byte grpSC :4;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
      } MergedBits;
    } DBGSCRXSTR;
    #define DBGSCRX                     _DBGSCRX.Byte
    #define DBGSCRX_SC0                 _DBGSCRX.SameAddr_STR.DBGSCRXSTR.Bits.SC0
    #define DBGSCRX_SC1                 _DBGSCRX.SameAddr_STR.DBGSCRXSTR.Bits.SC1
    #define DBGSCRX_SC2                 _DBGSCRX.SameAddr_STR.DBGSCRXSTR.Bits.SC2
    #define DBGSCRX_SC3                 _DBGSCRX.SameAddr_STR.DBGSCRXSTR.Bits.SC3
    #define DBGSCRX_SC                  _DBGSCRX.SameAddr_STR.DBGSCRXSTR.MergedBits.grpSC
    
    #define DBGSCRX_SC0_MASK            1U
    #define DBGSCRX_SC1_MASK            2U
    #define DBGSCRX_SC2_MASK            4U
    #define DBGSCRX_SC3_MASK            8U
    #define DBGSCRX_SC_MASK             15U
    #define DBGSCRX_SC_BITNUM           0U
    
    /*** DBGMFR - Debug Match Flag Register; Several registers at the same address ***/
    union {
      struct {
        byte MC0         :1;                                       /* Debug Match Flag Bit 0 */
        byte MC1         :1;                                       /* Debug Match Flag Bit 1 */
        byte MC2         :1;                                       /* Debug Match Flag Bit 2 */
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
      } Bits;
      struct {
        byte grpMC :3;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
      } MergedBits;
    } DBGMFRSTR;
    #define DBGMFR                      _DBGSCRX.Byte
    #define DBGMFR_MC0                  _DBGSCRX.SameAddr_STR.DBGMFRSTR.Bits.MC0
    #define DBGMFR_MC1                  _DBGSCRX.SameAddr_STR.DBGMFRSTR.Bits.MC1
    #define DBGMFR_MC2                  _DBGSCRX.SameAddr_STR.DBGMFRSTR.Bits.MC2
    #define DBGMFR_MC                   _DBGSCRX.SameAddr_STR.DBGMFRSTR.MergedBits.grpMC
    
    #define DBGMFR_MC0_MASK             1U
    #define DBGMFR_MC1_MASK             2U
    #define DBGMFR_MC2_MASK             4U
    #define DBGMFR_MC_MASK              7U
    #define DBGMFR_MC_BITNUM            0U
    
  } SameAddr_STR; /*Several registers at the same address */

} DBGSCRXSTR;
extern volatile DBGSCRXSTR _DBGSCRX @(REG_BASE + 0x00000027UL);


/*** DBGXCTL - Debug Comparator Control Register; 0x00000028 ***/
typedef union {
  byte Byte;
  struct {
    byte COMPE       :1;                                       /* Determines if comparator is enabled */
    byte NDB         :1;                                       /* Not Data Bus(Comparators A and C), Size Comparator Value Bit(Comparators B and D) */
    byte RWE         :1;                                       /* Read/Write Enable Bit */
    byte RW          :1;                                       /* Read/Write Comparator Value Bit */
    byte BRK         :1;                                       /* Break */
    byte TAG         :1;                                       /* Tag Select */
    byte SZ          :1;                                       /* Size Comparator Value Bit */
    byte SZE         :1;                                       /* Size Comparator Enable Bit */
  } Bits;
} DBGXCTLSTR;
extern volatile DBGXCTLSTR _DBGXCTL @(REG_BASE + 0x00000028UL);
#define DBGXCTL                         _DBGXCTL.Byte
#define DBGXCTL_COMPE                   _DBGXCTL.Bits.COMPE
#define DBGXCTL_NDB                     _DBGXCTL.Bits.NDB
#define DBGXCTL_RWE                     _DBGXCTL.Bits.RWE
#define DBGXCTL_RW                      _DBGXCTL.Bits.RW
#define DBGXCTL_BRK                     _DBGXCTL.Bits.BRK
#define DBGXCTL_TAG                     _DBGXCTL.Bits.TAG
#define DBGXCTL_SZ                      _DBGXCTL.Bits.SZ
#define DBGXCTL_SZE                     _DBGXCTL.Bits.SZE

#define DBGXCTL_COMPE_MASK              1U
#define DBGXCTL_NDB_MASK                2U
#define DBGXCTL_RWE_MASK                4U
#define DBGXCTL_RW_MASK                 8U
#define DBGXCTL_BRK_MASK                16U
#define DBGXCTL_TAG_MASK                32U
#define DBGXCTL_SZ_MASK                 64U
#define DBGXCTL_SZE_MASK                128U


/*** DBGXAH - Debug Comparator Address High Register; 0x00000029 ***/
typedef union {
  byte Byte;
  struct {
    byte BIT16       :1;                                       /* Comparator Address High Compare Bits */
    byte BIT17       :1;                                       /* Comparator Address High Compare Bit 17 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpBIT_16 :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} DBGXAHSTR;
extern volatile DBGXAHSTR _DBGXAH @(REG_BASE + 0x00000029UL);
#define DBGXAH                          _DBGXAH.Byte
#define DBGXAH_BIT16                    _DBGXAH.Bits.BIT16
#define DBGXAH_BIT17                    _DBGXAH.Bits.BIT17
#define DBGXAH_BIT_16                   _DBGXAH.MergedBits.grpBIT_16
#define DBGXAH_BIT                      DBGXAH_BIT_16

#define DBGXAH_BIT16_MASK               1U
#define DBGXAH_BIT17_MASK               2U
#define DBGXAH_BIT_16_MASK              3U
#define DBGXAH_BIT_16_BITNUM            0U


/*** DBGXAM - Debug Comparator Address Mid Register; 0x0000002A ***/
typedef union {
  byte Byte;
  struct {
    byte BIT8        :1;                                       /* Comparator Address Mid Compare Bits */
    byte BIT9        :1;                                       /* Comparator Address Mid Compare Bit 9 */
    byte BIT10       :1;                                       /* Comparator Address Mid Compare Bit 10 */
    byte BIT11       :1;                                       /* Comparator Address Mid Compare Bit 11 */
    byte BIT12       :1;                                       /* Comparator Address Mid Compare Bit 12 */
    byte BIT13       :1;                                       /* Comparator Address Mid Compare Bit 13 */
    byte BIT14       :1;                                       /* Comparator Address Mid Compare Bit 14 */
    byte BIT15       :1;                                       /* Comparator Address Mid Compare Bit 15 */
  } Bits;
} DBGXAMSTR;
extern volatile DBGXAMSTR _DBGXAM @(REG_BASE + 0x0000002AUL);
#define DBGXAM                          _DBGXAM.Byte
#define DBGXAM_BIT8                     _DBGXAM.Bits.BIT8
#define DBGXAM_BIT9                     _DBGXAM.Bits.BIT9
#define DBGXAM_BIT10                    _DBGXAM.Bits.BIT10
#define DBGXAM_BIT11                    _DBGXAM.Bits.BIT11
#define DBGXAM_BIT12                    _DBGXAM.Bits.BIT12
#define DBGXAM_BIT13                    _DBGXAM.Bits.BIT13
#define DBGXAM_BIT14                    _DBGXAM.Bits.BIT14
#define DBGXAM_BIT15                    _DBGXAM.Bits.BIT15

#define DBGXAM_BIT8_MASK                1U
#define DBGXAM_BIT9_MASK                2U
#define DBGXAM_BIT10_MASK               4U
#define DBGXAM_BIT11_MASK               8U
#define DBGXAM_BIT12_MASK               16U
#define DBGXAM_BIT13_MASK               32U
#define DBGXAM_BIT14_MASK               64U
#define DBGXAM_BIT15_MASK               128U


/*** DBGXAL - Debug Comparator Address Low Register; 0x0000002B ***/
typedef union {
  byte Byte;
  struct {
    byte BIT0        :1;                                       /* Comparator Address Low Compare Bits */
    byte BIT1        :1;                                       /* Comparator Address Low Compare Bit 1 */
    byte BIT2        :1;                                       /* Comparator Address Low Compare Bit 2 */
    byte BIT3        :1;                                       /* Comparator Address Low Compare Bit 3 */
    byte BIT4        :1;                                       /* Comparator Address Low Compare Bit 4 */
    byte BIT5        :1;                                       /* Comparator Address Low Compare Bit 5 */
    byte BIT6        :1;                                       /* Comparator Address Low Compare Bit 6 */
    byte BIT7        :1;                                       /* Comparator Address Low Compare Bit 7 */
  } Bits;
} DBGXALSTR;
extern volatile DBGXALSTR _DBGXAL @(REG_BASE + 0x0000002BUL);
#define DBGXAL                          _DBGXAL.Byte
#define DBGXAL_BIT0                     _DBGXAL.Bits.BIT0
#define DBGXAL_BIT1                     _DBGXAL.Bits.BIT1
#define DBGXAL_BIT2                     _DBGXAL.Bits.BIT2
#define DBGXAL_BIT3                     _DBGXAL.Bits.BIT3
#define DBGXAL_BIT4                     _DBGXAL.Bits.BIT4
#define DBGXAL_BIT5                     _DBGXAL.Bits.BIT5
#define DBGXAL_BIT6                     _DBGXAL.Bits.BIT6
#define DBGXAL_BIT7                     _DBGXAL.Bits.BIT7

#define DBGXAL_BIT0_MASK                1U
#define DBGXAL_BIT1_MASK                2U
#define DBGXAL_BIT2_MASK                4U
#define DBGXAL_BIT3_MASK                8U
#define DBGXAL_BIT4_MASK                16U
#define DBGXAL_BIT5_MASK                32U
#define DBGXAL_BIT6_MASK                64U
#define DBGXAL_BIT7_MASK                128U


/*** DBGADH - Debug Comparator Data High Register; 0x0000002C ***/
typedef union {
  byte Byte;
  struct {
    byte BIT8        :1;                                       /* Comparator Data High Compare Bit 8 */
    byte BIT9        :1;                                       /* Comparator Data High Compare Bit 9 */
    byte BIT10       :1;                                       /* Comparator Data High Compare Bit 10 */
    byte BIT11       :1;                                       /* Comparator Data High Compare Bit 11 */
    byte BIT12       :1;                                       /* Comparator Data High Compare Bit 12 */
    byte BIT13       :1;                                       /* Comparator Data High Compare Bit 13 */
    byte BIT14       :1;                                       /* Comparator Data High Compare Bit 14 */
    byte BIT15       :1;                                       /* Comparator Data High Compare Bit 15 */
  } Bits;
} DBGADHSTR;
extern volatile DBGADHSTR _DBGADH @(REG_BASE + 0x0000002CUL);
#define DBGADH                          _DBGADH.Byte
#define DBGADH_BIT8                     _DBGADH.Bits.BIT8
#define DBGADH_BIT9                     _DBGADH.Bits.BIT9
#define DBGADH_BIT10                    _DBGADH.Bits.BIT10
#define DBGADH_BIT11                    _DBGADH.Bits.BIT11
#define DBGADH_BIT12                    _DBGADH.Bits.BIT12
#define DBGADH_BIT13                    _DBGADH.Bits.BIT13
#define DBGADH_BIT14                    _DBGADH.Bits.BIT14
#define DBGADH_BIT15                    _DBGADH.Bits.BIT15

#define DBGADH_BIT8_MASK                1U
#define DBGADH_BIT9_MASK                2U
#define DBGADH_BIT10_MASK               4U
#define DBGADH_BIT11_MASK               8U
#define DBGADH_BIT12_MASK               16U
#define DBGADH_BIT13_MASK               32U
#define DBGADH_BIT14_MASK               64U
#define DBGADH_BIT15_MASK               128U


/*** DBGADL - Debug Comparator Data Low Register; 0x0000002D ***/
typedef union {
  byte Byte;
  struct {
    byte BIT0        :1;                                       /* Comparator Data Low Compare Bit 0 */
    byte BIT1        :1;                                       /* Comparator Data Low Compare Bit 1 */
    byte BIT2        :1;                                       /* Comparator Data Low Compare Bit 2 */
    byte BIT3        :1;                                       /* Comparator Data Low Compare Bit 3 */
    byte BIT4        :1;                                       /* Comparator Data Low Compare Bit 4 */
    byte BIT5        :1;                                       /* Comparator Data Low Compare Bit 5 */
    byte BIT6        :1;                                       /* Comparator Data Low Compare Bit 6 */
    byte BIT7        :1;                                       /* Comparator Data Low Compare Bit 7 */
  } Bits;
} DBGADLSTR;
extern volatile DBGADLSTR _DBGADL @(REG_BASE + 0x0000002DUL);
#define DBGADL                          _DBGADL.Byte
#define DBGADL_BIT0                     _DBGADL.Bits.BIT0
#define DBGADL_BIT1                     _DBGADL.Bits.BIT1
#define DBGADL_BIT2                     _DBGADL.Bits.BIT2
#define DBGADL_BIT3                     _DBGADL.Bits.BIT3
#define DBGADL_BIT4                     _DBGADL.Bits.BIT4
#define DBGADL_BIT5                     _DBGADL.Bits.BIT5
#define DBGADL_BIT6                     _DBGADL.Bits.BIT6
#define DBGADL_BIT7                     _DBGADL.Bits.BIT7

#define DBGADL_BIT0_MASK                1U
#define DBGADL_BIT1_MASK                2U
#define DBGADL_BIT2_MASK                4U
#define DBGADL_BIT3_MASK                8U
#define DBGADL_BIT4_MASK                16U
#define DBGADL_BIT5_MASK                32U
#define DBGADL_BIT6_MASK                64U
#define DBGADL_BIT7_MASK                128U


/*** DBGADHM - Debug Comparator Data High Mask Register; 0x0000002E ***/
typedef union {
  byte Byte;
  struct {
    byte BIT8        :1;                                       /* Comparator Data High Mask Bit 8 */
    byte BIT9        :1;                                       /* Comparator Data High Mask Bit 9 */
    byte BIT10       :1;                                       /* Comparator Data High Mask Bit 10 */
    byte BIT11       :1;                                       /* Comparator Data High Mask Bit 11 */
    byte BIT12       :1;                                       /* Comparator Data High Mask Bit 12 */
    byte BIT13       :1;                                       /* Comparator Data High Mask Bit 13 */
    byte BIT14       :1;                                       /* Comparator Data High Mask Bit 14 */
    byte BIT15       :1;                                       /* Comparator Data High Mask Bit 15 */
  } Bits;
} DBGADHMSTR;
extern volatile DBGADHMSTR _DBGADHM @(REG_BASE + 0x0000002EUL);
#define DBGADHM                         _DBGADHM.Byte
#define DBGADHM_BIT8                    _DBGADHM.Bits.BIT8
#define DBGADHM_BIT9                    _DBGADHM.Bits.BIT9
#define DBGADHM_BIT10                   _DBGADHM.Bits.BIT10
#define DBGADHM_BIT11                   _DBGADHM.Bits.BIT11
#define DBGADHM_BIT12                   _DBGADHM.Bits.BIT12
#define DBGADHM_BIT13                   _DBGADHM.Bits.BIT13
#define DBGADHM_BIT14                   _DBGADHM.Bits.BIT14
#define DBGADHM_BIT15                   _DBGADHM.Bits.BIT15

#define DBGADHM_BIT8_MASK               1U
#define DBGADHM_BIT9_MASK               2U
#define DBGADHM_BIT10_MASK              4U
#define DBGADHM_BIT11_MASK              8U
#define DBGADHM_BIT12_MASK              16U
#define DBGADHM_BIT13_MASK              32U
#define DBGADHM_BIT14_MASK              64U
#define DBGADHM_BIT15_MASK              128U


/*** DBGADLM - Debug Comparator Data Low Mask Register; 0x0000002F ***/
typedef union {
  byte Byte;
  struct {
    byte BIT0        :1;                                       /* Comparator Data Low Mask Bit 0 */
    byte BIT1        :1;                                       /* Comparator Data Low Mask Bit 1 */
    byte BIT2        :1;                                       /* Comparator Data Low Mask Bit 2 */
    byte BIT3        :1;                                       /* Comparator Data Low Mask Bit 3 */
    byte BIT4        :1;                                       /* Comparator Data Low Mask Bit 4 */
    byte BIT5        :1;                                       /* Comparator Data Low Mask Bit 5 */
    byte BIT6        :1;                                       /* Comparator Data Low Mask Bit 6 */
    byte BIT7        :1;                                       /* Comparator Data Low Mask Bit 7 */
  } Bits;
} DBGADLMSTR;
extern volatile DBGADLMSTR _DBGADLM @(REG_BASE + 0x0000002FUL);
#define DBGADLM                         _DBGADLM.Byte
#define DBGADLM_BIT0                    _DBGADLM.Bits.BIT0
#define DBGADLM_BIT1                    _DBGADLM.Bits.BIT1
#define DBGADLM_BIT2                    _DBGADLM.Bits.BIT2
#define DBGADLM_BIT3                    _DBGADLM.Bits.BIT3
#define DBGADLM_BIT4                    _DBGADLM.Bits.BIT4
#define DBGADLM_BIT5                    _DBGADLM.Bits.BIT5
#define DBGADLM_BIT6                    _DBGADLM.Bits.BIT6
#define DBGADLM_BIT7                    _DBGADLM.Bits.BIT7

#define DBGADLM_BIT0_MASK               1U
#define DBGADLM_BIT1_MASK               2U
#define DBGADLM_BIT2_MASK               4U
#define DBGADLM_BIT3_MASK               8U
#define DBGADLM_BIT4_MASK               16U
#define DBGADLM_BIT5_MASK               32U
#define DBGADLM_BIT6_MASK               64U
#define DBGADLM_BIT7_MASK               128U


/*** CPMUSYNR - S12CPMU Synthesizer Register; 0x00000034 ***/
typedef union {
  byte Byte;
  struct {
    byte SYNDIV0     :1;                                       /* Multiplication factor of the IPLL bit 0 */
    byte SYNDIV1     :1;                                       /* Multiplication factor of the IPLL bit 1 */
    byte SYNDIV2     :1;                                       /* Multiplication factor of the IPLL bit 2 */
    byte SYNDIV3     :1;                                       /* Multiplication factor of the IPLL bit 3 */
    byte SYNDIV4     :1;                                       /* Multiplication factor of the IPLL bit 4 */
    byte SYNDIV5     :1;                                       /* Multiplication factor of the IPLL bit 5 */
    byte VCOFRQ0     :1;                                       /* VCO frequency range bit 0 */
    byte VCOFRQ1     :1;                                       /* VCO frequency range bit 1 */
  } Bits;
  struct {
    byte grpSYNDIV :6;
    byte grpVCOFRQ :2;
  } MergedBits;
} CPMUSYNRSTR;
extern volatile CPMUSYNRSTR _CPMUSYNR @(REG_BASE + 0x00000034UL);
#define CPMUSYNR                        _CPMUSYNR.Byte
#define CPMUSYNR_SYNDIV0                _CPMUSYNR.Bits.SYNDIV0
#define CPMUSYNR_SYNDIV1                _CPMUSYNR.Bits.SYNDIV1
#define CPMUSYNR_SYNDIV2                _CPMUSYNR.Bits.SYNDIV2
#define CPMUSYNR_SYNDIV3                _CPMUSYNR.Bits.SYNDIV3
#define CPMUSYNR_SYNDIV4                _CPMUSYNR.Bits.SYNDIV4
#define CPMUSYNR_SYNDIV5                _CPMUSYNR.Bits.SYNDIV5
#define CPMUSYNR_VCOFRQ0                _CPMUSYNR.Bits.VCOFRQ0
#define CPMUSYNR_VCOFRQ1                _CPMUSYNR.Bits.VCOFRQ1
#define CPMUSYNR_SYNDIV                 _CPMUSYNR.MergedBits.grpSYNDIV
#define CPMUSYNR_VCOFRQ                 _CPMUSYNR.MergedBits.grpVCOFRQ

#define CPMUSYNR_SYNDIV0_MASK           1U
#define CPMUSYNR_SYNDIV1_MASK           2U
#define CPMUSYNR_SYNDIV2_MASK           4U
#define CPMUSYNR_SYNDIV3_MASK           8U
#define CPMUSYNR_SYNDIV4_MASK           16U
#define CPMUSYNR_SYNDIV5_MASK           32U
#define CPMUSYNR_VCOFRQ0_MASK           64U
#define CPMUSYNR_VCOFRQ1_MASK           128U
#define CPMUSYNR_SYNDIV_MASK            63U
#define CPMUSYNR_SYNDIV_BITNUM          0U
#define CPMUSYNR_VCOFRQ_MASK            192U
#define CPMUSYNR_VCOFRQ_BITNUM          6U


/*** CPMUREFDIV - S12CPMU Reference Divider Register; 0x00000035 ***/
typedef union {
  byte Byte;
  struct {
    byte REFDIV0     :1;                                       /* Finer granularity for the IPLL multiplier steps bit 0 */
    byte REFDIV1     :1;                                       /* Finer granularity for the IPLL multiplier steps bit 1 */
    byte REFDIV2     :1;                                       /* Finer granularity for the IPLL multiplier steps bit 2 */
    byte REFDIV3     :1;                                       /* Finer granularity for the IPLL multiplier steps bit 3 */
    byte             :1; 
    byte             :1; 
    byte REFFRQ0     :1;                                       /* IPLL optimal stability and lock time configuration bit 0 */
    byte REFFRQ1     :1;                                       /* IPLL optimal stability and lock time configuration bit 1 */
  } Bits;
  struct {
    byte grpREFDIV :4;
    byte         :1;
    byte         :1;
    byte grpREFFRQ :2;
  } MergedBits;
} CPMUREFDIVSTR;
extern volatile CPMUREFDIVSTR _CPMUREFDIV @(REG_BASE + 0x00000035UL);
#define CPMUREFDIV                      _CPMUREFDIV.Byte
#define CPMUREFDIV_REFDIV0              _CPMUREFDIV.Bits.REFDIV0
#define CPMUREFDIV_REFDIV1              _CPMUREFDIV.Bits.REFDIV1
#define CPMUREFDIV_REFDIV2              _CPMUREFDIV.Bits.REFDIV2
#define CPMUREFDIV_REFDIV3              _CPMUREFDIV.Bits.REFDIV3
#define CPMUREFDIV_REFFRQ0              _CPMUREFDIV.Bits.REFFRQ0
#define CPMUREFDIV_REFFRQ1              _CPMUREFDIV.Bits.REFFRQ1
#define CPMUREFDIV_REFDIV               _CPMUREFDIV.MergedBits.grpREFDIV
#define CPMUREFDIV_REFFRQ               _CPMUREFDIV.MergedBits.grpREFFRQ

#define CPMUREFDIV_REFDIV0_MASK         1U
#define CPMUREFDIV_REFDIV1_MASK         2U
#define CPMUREFDIV_REFDIV2_MASK         4U
#define CPMUREFDIV_REFDIV3_MASK         8U
#define CPMUREFDIV_REFFRQ0_MASK         64U
#define CPMUREFDIV_REFFRQ1_MASK         128U
#define CPMUREFDIV_REFDIV_MASK          15U
#define CPMUREFDIV_REFDIV_BITNUM        0U
#define CPMUREFDIV_REFFRQ_MASK          192U
#define CPMUREFDIV_REFFRQ_BITNUM        6U


/*** CPMUPOSTDIV - S12CPMU Post Divider Register; 0x00000036 ***/
typedef union {
  byte Byte;
  struct {
    byte POSTDIV0    :1;                                       /* Frequency ratio between the VCOCLK and PLLCLK control bit 0 */
    byte POSTDIV1    :1;                                       /* Frequency ratio between the VCOCLK and PLLCLK control bit 1 */
    byte POSTDIV2    :1;                                       /* Frequency ratio between the VCOCLK and PLLCLK control bit 2 */
    byte POSTDIV3    :1;                                       /* Frequency ratio between the VCOCLK and PLLCLK control bit 3 */
    byte POSTDIV4    :1;                                       /* Frequency ratio between the VCOCLK and PLLCLK control bit 4 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPOSTDIV :5;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} CPMUPOSTDIVSTR;
extern volatile CPMUPOSTDIVSTR _CPMUPOSTDIV @(REG_BASE + 0x00000036UL);
#define CPMUPOSTDIV                     _CPMUPOSTDIV.Byte
#define CPMUPOSTDIV_POSTDIV0            _CPMUPOSTDIV.Bits.POSTDIV0
#define CPMUPOSTDIV_POSTDIV1            _CPMUPOSTDIV.Bits.POSTDIV1
#define CPMUPOSTDIV_POSTDIV2            _CPMUPOSTDIV.Bits.POSTDIV2
#define CPMUPOSTDIV_POSTDIV3            _CPMUPOSTDIV.Bits.POSTDIV3
#define CPMUPOSTDIV_POSTDIV4            _CPMUPOSTDIV.Bits.POSTDIV4
#define CPMUPOSTDIV_POSTDIV             _CPMUPOSTDIV.MergedBits.grpPOSTDIV

#define CPMUPOSTDIV_POSTDIV0_MASK       1U
#define CPMUPOSTDIV_POSTDIV1_MASK       2U
#define CPMUPOSTDIV_POSTDIV2_MASK       4U
#define CPMUPOSTDIV_POSTDIV3_MASK       8U
#define CPMUPOSTDIV_POSTDIV4_MASK       16U
#define CPMUPOSTDIV_POSTDIV_MASK        31U
#define CPMUPOSTDIV_POSTDIV_BITNUM      0U


/*** CPMUFLG - S12CPMU Flags Register; 0x00000037 ***/
typedef union {
  byte Byte;
  struct {
    byte UPOSC       :1;                                       /* Oscillator Status Bit */
    byte OSCIF       :1;                                       /* Oscillator Interrupt Flag */
    byte ILAF        :1;                                       /* Illegal Address Reset Flag */
    byte LOCK        :1;                                       /* Lock Status Bit */
    byte LOCKIF      :1;                                       /* IPLL Lock Interrupt Flag */
    byte LVRF        :1;                                       /* Low Voltage Reset Flag */
    byte PORF        :1;                                       /* Power on Reset Flag */
    byte RTIF        :1;                                       /* Real Time Interrupt Flag */
  } Bits;
} CPMUFLGSTR;
extern volatile CPMUFLGSTR _CPMUFLG @(REG_BASE + 0x00000037UL);
#define CPMUFLG                         _CPMUFLG.Byte
#define CPMUFLG_UPOSC                   _CPMUFLG.Bits.UPOSC
#define CPMUFLG_OSCIF                   _CPMUFLG.Bits.OSCIF
#define CPMUFLG_ILAF                    _CPMUFLG.Bits.ILAF
#define CPMUFLG_LOCK                    _CPMUFLG.Bits.LOCK
#define CPMUFLG_LOCKIF                  _CPMUFLG.Bits.LOCKIF
#define CPMUFLG_LVRF                    _CPMUFLG.Bits.LVRF
#define CPMUFLG_PORF                    _CPMUFLG.Bits.PORF
#define CPMUFLG_RTIF                    _CPMUFLG.Bits.RTIF

#define CPMUFLG_UPOSC_MASK              1U
#define CPMUFLG_OSCIF_MASK              2U
#define CPMUFLG_ILAF_MASK               4U
#define CPMUFLG_LOCK_MASK               8U
#define CPMUFLG_LOCKIF_MASK             16U
#define CPMUFLG_LVRF_MASK               32U
#define CPMUFLG_PORF_MASK               64U
#define CPMUFLG_RTIF_MASK               128U


/*** CPMUINT - S12CPMU Interrupt Enable Register; 0x00000038 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte OSCIE       :1;                                       /* Oscillator Corrupt Interrupt Enable Bit */
    byte             :1; 
    byte             :1; 
    byte LOCKIE      :1;                                       /* Lock Interrupt Enable Bit */
    byte             :1; 
    byte             :1; 
    byte RTIE        :1;                                       /* Real Time Interrupt Enable Bit */
  } Bits;
} CPMUINTSTR;
extern volatile CPMUINTSTR _CPMUINT @(REG_BASE + 0x00000038UL);
#define CPMUINT                         _CPMUINT.Byte
#define CPMUINT_OSCIE                   _CPMUINT.Bits.OSCIE
#define CPMUINT_LOCKIE                  _CPMUINT.Bits.LOCKIE
#define CPMUINT_RTIE                    _CPMUINT.Bits.RTIE

#define CPMUINT_OSCIE_MASK              2U
#define CPMUINT_LOCKIE_MASK             16U
#define CPMUINT_RTIE_MASK               128U


/*** CPMUCLKS - S12CPMU Clock Select Register; 0x00000039 ***/
typedef union {
  byte Byte;
  struct {
    byte COPOSCSEL   :1;                                       /* COP Clock Select */
    byte RTIOSCSEL   :1;                                       /* RTI Clock Select */
    byte PCE         :1;                                       /* COP Enable During Pseudo Stop Bit */
    byte PRE         :1;                                       /* RTI Enable During Pseudo Stop Bit */
    byte             :1; 
    byte             :1; 
    byte PSTP        :1;                                       /* Pseudo Stop Bit */
    byte PLLSEL      :1;                                       /* PLL Select Bit */
  } Bits;
} CPMUCLKSSTR;
extern volatile CPMUCLKSSTR _CPMUCLKS @(REG_BASE + 0x00000039UL);
#define CPMUCLKS                        _CPMUCLKS.Byte
#define CPMUCLKS_COPOSCSEL              _CPMUCLKS.Bits.COPOSCSEL
#define CPMUCLKS_RTIOSCSEL              _CPMUCLKS.Bits.RTIOSCSEL
#define CPMUCLKS_PCE                    _CPMUCLKS.Bits.PCE
#define CPMUCLKS_PRE                    _CPMUCLKS.Bits.PRE
#define CPMUCLKS_PSTP                   _CPMUCLKS.Bits.PSTP
#define CPMUCLKS_PLLSEL                 _CPMUCLKS.Bits.PLLSEL

#define CPMUCLKS_COPOSCSEL_MASK         1U
#define CPMUCLKS_RTIOSCSEL_MASK         2U
#define CPMUCLKS_PCE_MASK               4U
#define CPMUCLKS_PRE_MASK               8U
#define CPMUCLKS_PSTP_MASK              64U
#define CPMUCLKS_PLLSEL_MASK            128U


/*** CPMUPLL - S12CPMU PLL Control Register; 0x0000003A ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte FM0         :1;                                       /* PLL Frequency Modulation Enable Bit 0 */
    byte FM1         :1;                                       /* PLL Frequency Modulation Enable Bit 1 */
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte grpFM   :2;
    byte         :1;
    byte         :1;
  } MergedBits;
} CPMUPLLSTR;
extern volatile CPMUPLLSTR _CPMUPLL @(REG_BASE + 0x0000003AUL);
#define CPMUPLL                         _CPMUPLL.Byte
#define CPMUPLL_FM0                     _CPMUPLL.Bits.FM0
#define CPMUPLL_FM1                     _CPMUPLL.Bits.FM1
#define CPMUPLL_FM                      _CPMUPLL.MergedBits.grpFM

#define CPMUPLL_FM0_MASK                16U
#define CPMUPLL_FM1_MASK                32U
#define CPMUPLL_FM_MASK                 48U
#define CPMUPLL_FM_BITNUM               4U


/*** CPMURTI - CPMU RTI Control Register; 0x0000003B ***/
typedef union {
  byte Byte;
  struct {
    byte RTR0        :1;                                       /* Real Time Interrupt Modulus Counter Select Bit 0 */
    byte RTR1        :1;                                       /* Real Time Interrupt Modulus Counter Select Bit 1 */
    byte RTR2        :1;                                       /* Real Time Interrupt Modulus Counter Select Bit 2 */
    byte RTR3        :1;                                       /* Real Time Interrupt Modulus Counter Select Bit 3 */
    byte RTR4        :1;                                       /* Real Time Interrupt Prescale Rate Select Bit 4 */
    byte RTR5        :1;                                       /* Real Time Interrupt Prescale Rate Select Bit 5 */
    byte RTR6        :1;                                       /* Real Time Interrupt Prescale Rate Select Bit 6 */
    byte RTDEC       :1;                                       /* Decimal or Binary Divider Select Bit */
  } Bits;
  struct {
    byte grpRTR  :7;
    byte         :1;
  } MergedBits;
} CPMURTISTR;
extern volatile CPMURTISTR _CPMURTI @(REG_BASE + 0x0000003BUL);
#define CPMURTI                         _CPMURTI.Byte
#define CPMURTI_RTR0                    _CPMURTI.Bits.RTR0
#define CPMURTI_RTR1                    _CPMURTI.Bits.RTR1
#define CPMURTI_RTR2                    _CPMURTI.Bits.RTR2
#define CPMURTI_RTR3                    _CPMURTI.Bits.RTR3
#define CPMURTI_RTR4                    _CPMURTI.Bits.RTR4
#define CPMURTI_RTR5                    _CPMURTI.Bits.RTR5
#define CPMURTI_RTR6                    _CPMURTI.Bits.RTR6
#define CPMURTI_RTDEC                   _CPMURTI.Bits.RTDEC
#define CPMURTI_RTR                     _CPMURTI.MergedBits.grpRTR

#define CPMURTI_RTR0_MASK               1U
#define CPMURTI_RTR1_MASK               2U
#define CPMURTI_RTR2_MASK               4U
#define CPMURTI_RTR3_MASK               8U
#define CPMURTI_RTR4_MASK               16U
#define CPMURTI_RTR5_MASK               32U
#define CPMURTI_RTR6_MASK               64U
#define CPMURTI_RTDEC_MASK              128U
#define CPMURTI_RTR_MASK                127U
#define CPMURTI_RTR_BITNUM              0U


/*** CPMUCOP - CPMU COP Control Register; 0x0000003C ***/
typedef union {
  byte Byte;
  struct {
    byte CR0         :1;                                       /* COP Watchdog Timer Rate select Bit 0 */
    byte CR1         :1;                                       /* COP Watchdog Timer Rate select Bit 1 */
    byte CR2         :1;                                       /* COP Watchdog Timer Rate select Bit 2 */
    byte             :1; 
    byte             :1; 
    byte WRTMASK     :1;                                       /* Write Mask for WCOP */
    byte RSBCK       :1;                                       /* COP and RTI stop in Active BDM mode Bit */
    byte WCOP        :1;                                       /* Window COP mode */
  } Bits;
  struct {
    byte grpCR   :3;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} CPMUCOPSTR;
extern volatile CPMUCOPSTR _CPMUCOP @(REG_BASE + 0x0000003CUL);
#define CPMUCOP                         _CPMUCOP.Byte
#define CPMUCOP_CR0                     _CPMUCOP.Bits.CR0
#define CPMUCOP_CR1                     _CPMUCOP.Bits.CR1
#define CPMUCOP_CR2                     _CPMUCOP.Bits.CR2
#define CPMUCOP_WRTMASK                 _CPMUCOP.Bits.WRTMASK
#define CPMUCOP_RSBCK                   _CPMUCOP.Bits.RSBCK
#define CPMUCOP_WCOP                    _CPMUCOP.Bits.WCOP
#define CPMUCOP_CR                      _CPMUCOP.MergedBits.grpCR

#define CPMUCOP_CR0_MASK                1U
#define CPMUCOP_CR1_MASK                2U
#define CPMUCOP_CR2_MASK                4U
#define CPMUCOP_WRTMASK_MASK            32U
#define CPMUCOP_RSBCK_MASK              64U
#define CPMUCOP_WCOP_MASK               128U
#define CPMUCOP_CR_MASK                 7U
#define CPMUCOP_CR_BITNUM               0U


/*** CPMUARMCOP - CPMU COP Timer Arm/Reset Register; 0x0000003F ***/
typedef union {
  byte Byte;
  struct {
    byte BIT0        :1;                                       /* CPMU COP Timer Arm/Reset Bit 0 */
    byte BIT1        :1;                                       /* CPMU COP Timer Arm/Reset Bit 1 */
    byte BIT2        :1;                                       /* CPMU COP Timer Arm/Reset Bit 2 */
    byte BIT3        :1;                                       /* CPMU COP Timer Arm/Reset Bit 3 */
    byte BIT4        :1;                                       /* CPMU COP Timer Arm/Reset Bit 4 */
    byte BIT5        :1;                                       /* CPMU COP Timer Arm/Reset Bit 5 */
    byte BIT6        :1;                                       /* CPMU COP Timer Arm/Reset Bit 6 */
    byte BIT7        :1;                                       /* CPMU COP Timer Arm/Reset Bit 7 */
  } Bits;
} CPMUARMCOPSTR;
extern volatile CPMUARMCOPSTR _CPMUARMCOP @(REG_BASE + 0x0000003FUL);
#define CPMUARMCOP                      _CPMUARMCOP.Byte
#define CPMUARMCOP_BIT0                 _CPMUARMCOP.Bits.BIT0
#define CPMUARMCOP_BIT1                 _CPMUARMCOP.Bits.BIT1
#define CPMUARMCOP_BIT2                 _CPMUARMCOP.Bits.BIT2
#define CPMUARMCOP_BIT3                 _CPMUARMCOP.Bits.BIT3
#define CPMUARMCOP_BIT4                 _CPMUARMCOP.Bits.BIT4
#define CPMUARMCOP_BIT5                 _CPMUARMCOP.Bits.BIT5
#define CPMUARMCOP_BIT6                 _CPMUARMCOP.Bits.BIT6
#define CPMUARMCOP_BIT7                 _CPMUARMCOP.Bits.BIT7

#define CPMUARMCOP_BIT0_MASK            1U
#define CPMUARMCOP_BIT1_MASK            2U
#define CPMUARMCOP_BIT2_MASK            4U
#define CPMUARMCOP_BIT3_MASK            8U
#define CPMUARMCOP_BIT4_MASK            16U
#define CPMUARMCOP_BIT5_MASK            32U
#define CPMUARMCOP_BIT6_MASK            64U
#define CPMUARMCOP_BIT7_MASK            128U


/*** TIM0_TIOS - Timer Input Capture/Output Compare Select; 0x00000040 ***/
typedef union {
  byte Byte;
  struct {
    byte IOS0        :1;                                       /* Input Capture or Output Compare Channel Configuration Bit 0 */
    byte IOS1        :1;                                       /* Input Capture or Output Compare Channel Configuration Bit 1 */
    byte IOS2        :1;                                       /* Input Capture or Output Compare Channel Configuration Bit 2 */
    byte IOS3        :1;                                       /* Input Capture or Output Compare Channel Configuration Bit 3 */
    byte IOS4        :1;                                       /* Input Capture or Output Compare Channel Configuration Bit 4 */
    byte IOS5        :1;                                       /* Input Capture or Output Compare Channel Configuration Bit 5 */
    byte IOS6        :1;                                       /* Input Capture or Output Compare Channel Configuration Bit 6 */
    byte IOS7        :1;                                       /* Input Capture or Output Compare Channel Configuration Bit 7 */
  } Bits;
} TIM0_TIOSSTR;
extern volatile TIM0_TIOSSTR _TIM0_TIOS @(REG_BASE + 0x00000040UL);
#define TIM0_TIOS                       _TIM0_TIOS.Byte
#define TIM0_TIOS_IOS0                  _TIM0_TIOS.Bits.IOS0
#define TIM0_TIOS_IOS1                  _TIM0_TIOS.Bits.IOS1
#define TIM0_TIOS_IOS2                  _TIM0_TIOS.Bits.IOS2
#define TIM0_TIOS_IOS3                  _TIM0_TIOS.Bits.IOS3
#define TIM0_TIOS_IOS4                  _TIM0_TIOS.Bits.IOS4
#define TIM0_TIOS_IOS5                  _TIM0_TIOS.Bits.IOS5
#define TIM0_TIOS_IOS6                  _TIM0_TIOS.Bits.IOS6
#define TIM0_TIOS_IOS7                  _TIM0_TIOS.Bits.IOS7

#define TIM0_TIOS_IOS0_MASK             1U
#define TIM0_TIOS_IOS1_MASK             2U
#define TIM0_TIOS_IOS2_MASK             4U
#define TIM0_TIOS_IOS3_MASK             8U
#define TIM0_TIOS_IOS4_MASK             16U
#define TIM0_TIOS_IOS5_MASK             32U
#define TIM0_TIOS_IOS6_MASK             64U
#define TIM0_TIOS_IOS7_MASK             128U


/*** TIM0_CFORC - Timer Compare Force Register; 0x00000041 ***/
typedef union {
  byte Byte;
  struct {
    byte FOC0        :1;                                       /* Force Output Compare Action for Channel 0 */
    byte FOC1        :1;                                       /* Force Output Compare Action for Channel 1 */
    byte FOC2        :1;                                       /* Force Output Compare Action for Channel 2 */
    byte FOC3        :1;                                       /* Force Output Compare Action for Channel 3 */
    byte FOC4        :1;                                       /* Force Output Compare Action for Channel 4 */
    byte FOC5        :1;                                       /* Force Output Compare Action for Channel 5 */
    byte FOC6        :1;                                       /* Force Output Compare Action for Channel 6 */
    byte FOC7        :1;                                       /* Force Output Compare Action for Channel 7 */
  } Bits;
} TIM0_CFORCSTR;
extern volatile TIM0_CFORCSTR _TIM0_CFORC @(REG_BASE + 0x00000041UL);
#define TIM0_CFORC                      _TIM0_CFORC.Byte
#define TIM0_CFORC_FOC0                 _TIM0_CFORC.Bits.FOC0
#define TIM0_CFORC_FOC1                 _TIM0_CFORC.Bits.FOC1
#define TIM0_CFORC_FOC2                 _TIM0_CFORC.Bits.FOC2
#define TIM0_CFORC_FOC3                 _TIM0_CFORC.Bits.FOC3
#define TIM0_CFORC_FOC4                 _TIM0_CFORC.Bits.FOC4
#define TIM0_CFORC_FOC5                 _TIM0_CFORC.Bits.FOC5
#define TIM0_CFORC_FOC6                 _TIM0_CFORC.Bits.FOC6
#define TIM0_CFORC_FOC7                 _TIM0_CFORC.Bits.FOC7

#define TIM0_CFORC_FOC0_MASK            1U
#define TIM0_CFORC_FOC1_MASK            2U
#define TIM0_CFORC_FOC2_MASK            4U
#define TIM0_CFORC_FOC3_MASK            8U
#define TIM0_CFORC_FOC4_MASK            16U
#define TIM0_CFORC_FOC5_MASK            32U
#define TIM0_CFORC_FOC6_MASK            64U
#define TIM0_CFORC_FOC7_MASK            128U


/*** TIM0_OC7M - Output Compare 7 Mask Register; 0x00000042 ***/
typedef union {
  byte Byte;
  struct {
    byte OC7M0       :1;                                       /* Output Compare 7 Mask Bit 0 */
    byte OC7M1       :1;                                       /* Output Compare 7 Mask Bit 1 */
    byte OC7M2       :1;                                       /* Output Compare 7 Mask Bit 2 */
    byte OC7M3       :1;                                       /* Output Compare 7 Mask Bit 3 */
    byte OC7M4       :1;                                       /* Output Compare 7 Mask Bit 4 */
    byte OC7M5       :1;                                       /* Output Compare 7 Mask Bit 5 */
    byte OC7M6       :1;                                       /* Output Compare 7 Mask Bit 6 */
    byte OC7M7       :1;                                       /* Output Compare 7 Mask Bit 7 */
  } Bits;
} TIM0_OC7MSTR;
extern volatile TIM0_OC7MSTR _TIM0_OC7M @(REG_BASE + 0x00000042UL);
#define TIM0_OC7M                       _TIM0_OC7M.Byte
#define TIM0_OC7M_OC7M0                 _TIM0_OC7M.Bits.OC7M0
#define TIM0_OC7M_OC7M1                 _TIM0_OC7M.Bits.OC7M1
#define TIM0_OC7M_OC7M2                 _TIM0_OC7M.Bits.OC7M2
#define TIM0_OC7M_OC7M3                 _TIM0_OC7M.Bits.OC7M3
#define TIM0_OC7M_OC7M4                 _TIM0_OC7M.Bits.OC7M4
#define TIM0_OC7M_OC7M5                 _TIM0_OC7M.Bits.OC7M5
#define TIM0_OC7M_OC7M6                 _TIM0_OC7M.Bits.OC7M6
#define TIM0_OC7M_OC7M7                 _TIM0_OC7M.Bits.OC7M7

#define TIM0_OC7M_OC7M0_MASK            1U
#define TIM0_OC7M_OC7M1_MASK            2U
#define TIM0_OC7M_OC7M2_MASK            4U
#define TIM0_OC7M_OC7M3_MASK            8U
#define TIM0_OC7M_OC7M4_MASK            16U
#define TIM0_OC7M_OC7M5_MASK            32U
#define TIM0_OC7M_OC7M6_MASK            64U
#define TIM0_OC7M_OC7M7_MASK            128U


/*** TIM0_OC7D - Output Compare 7 Data Register; 0x00000043 ***/
typedef union {
  byte Byte;
  struct {
    byte OC7D0       :1;                                       /* Output Compare 7 Bit 0 */
    byte OC7D1       :1;                                       /* Output Compare 7 Bit 1 */
    byte OC7D2       :1;                                       /* Output Compare 7 Bit 2 */
    byte OC7D3       :1;                                       /* Output Compare 7 Bit 3 */
    byte OC7D4       :1;                                       /* Output Compare 7 Bit 4 */
    byte OC7D5       :1;                                       /* Output Compare 7 Bit 5 */
    byte OC7D6       :1;                                       /* Output Compare 7 Bit 6 */
    byte OC7D7       :1;                                       /* Output Compare 7 Bit 7 */
  } Bits;
} TIM0_OC7DSTR;
extern volatile TIM0_OC7DSTR _TIM0_OC7D @(REG_BASE + 0x00000043UL);
#define TIM0_OC7D                       _TIM0_OC7D.Byte
#define TIM0_OC7D_OC7D0                 _TIM0_OC7D.Bits.OC7D0
#define TIM0_OC7D_OC7D1                 _TIM0_OC7D.Bits.OC7D1
#define TIM0_OC7D_OC7D2                 _TIM0_OC7D.Bits.OC7D2
#define TIM0_OC7D_OC7D3                 _TIM0_OC7D.Bits.OC7D3
#define TIM0_OC7D_OC7D4                 _TIM0_OC7D.Bits.OC7D4
#define TIM0_OC7D_OC7D5                 _TIM0_OC7D.Bits.OC7D5
#define TIM0_OC7D_OC7D6                 _TIM0_OC7D.Bits.OC7D6
#define TIM0_OC7D_OC7D7                 _TIM0_OC7D.Bits.OC7D7

#define TIM0_OC7D_OC7D0_MASK            1U
#define TIM0_OC7D_OC7D1_MASK            2U
#define TIM0_OC7D_OC7D2_MASK            4U
#define TIM0_OC7D_OC7D3_MASK            8U
#define TIM0_OC7D_OC7D4_MASK            16U
#define TIM0_OC7D_OC7D5_MASK            32U
#define TIM0_OC7D_OC7D6_MASK            64U
#define TIM0_OC7D_OC7D7_MASK            128U


/*** TIM0_TCNT - Timer Count Register; 0x00000044 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TIM0_TCNTHi - Timer Count Register High; 0x00000044 ***/
    union {
      byte Byte;
    } TIM0_TCNTHiSTR;
    #define TIM0_TCNTHi                 _TIM0_TCNT.Overlap_STR.TIM0_TCNTHiSTR.Byte
    

    /*** TIM0_TCNTLo - Timer Count Register Low; 0x00000045 ***/
    union {
      byte Byte;
    } TIM0_TCNTLoSTR;
    #define TIM0_TCNTLo                 _TIM0_TCNT.Overlap_STR.TIM0_TCNTLoSTR.Byte
    
  } Overlap_STR;

} TIM0_TCNTSTR;
extern volatile TIM0_TCNTSTR _TIM0_TCNT @(REG_BASE + 0x00000044UL);
#define TIM0_TCNT                       _TIM0_TCNT.Word


/*** TIM0_TSCR1 - Timer System Control Register1; 0x00000046 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte PRNT        :1;                                       /* Precision Timer */
    byte TFFCA       :1;                                       /* Timer Fast Flag Clear All */
    byte TSFRZ       :1;                                       /* Timer and Modulus Counter Stop While in Freeze Mode */
    byte TSWAI       :1;                                       /* Timer Module Stops While in Wait */
    byte TEN         :1;                                       /* Timer Enable */
  } Bits;
} TIM0_TSCR1STR;
extern volatile TIM0_TSCR1STR _TIM0_TSCR1 @(REG_BASE + 0x00000046UL);
#define TIM0_TSCR1                      _TIM0_TSCR1.Byte
#define TIM0_TSCR1_PRNT                 _TIM0_TSCR1.Bits.PRNT
#define TIM0_TSCR1_TFFCA                _TIM0_TSCR1.Bits.TFFCA
#define TIM0_TSCR1_TSFRZ                _TIM0_TSCR1.Bits.TSFRZ
#define TIM0_TSCR1_TSWAI                _TIM0_TSCR1.Bits.TSWAI
#define TIM0_TSCR1_TEN                  _TIM0_TSCR1.Bits.TEN

#define TIM0_TSCR1_PRNT_MASK            8U
#define TIM0_TSCR1_TFFCA_MASK           16U
#define TIM0_TSCR1_TSFRZ_MASK           32U
#define TIM0_TSCR1_TSWAI_MASK           64U
#define TIM0_TSCR1_TEN_MASK             128U


/*** TIM0_TTOV - Timer Toggle On Overflow Register; 0x00000047 ***/
typedef union {
  byte Byte;
  struct {
    byte TOV0        :1;                                       /* Toggle On Overflow Bit 0 */
    byte TOV1        :1;                                       /* Toggle On Overflow Bit 1 */
    byte TOV2        :1;                                       /* Toggle On Overflow Bit 2 */
    byte TOV3        :1;                                       /* Toggle On Overflow Bit 3 */
    byte TOV4        :1;                                       /* Toggle On Overflow Bit 4 */
    byte TOV5        :1;                                       /* Toggle On Overflow Bit 5 */
    byte TOV6        :1;                                       /* Toggle On Overflow Bit 6 */
    byte TOV7        :1;                                       /* Toggle On Overflow Bit 7 */
  } Bits;
} TIM0_TTOVSTR;
extern volatile TIM0_TTOVSTR _TIM0_TTOV @(REG_BASE + 0x00000047UL);
#define TIM0_TTOV                       _TIM0_TTOV.Byte
#define TIM0_TTOV_TOV0                  _TIM0_TTOV.Bits.TOV0
#define TIM0_TTOV_TOV1                  _TIM0_TTOV.Bits.TOV1
#define TIM0_TTOV_TOV2                  _TIM0_TTOV.Bits.TOV2
#define TIM0_TTOV_TOV3                  _TIM0_TTOV.Bits.TOV3
#define TIM0_TTOV_TOV4                  _TIM0_TTOV.Bits.TOV4
#define TIM0_TTOV_TOV5                  _TIM0_TTOV.Bits.TOV5
#define TIM0_TTOV_TOV6                  _TIM0_TTOV.Bits.TOV6
#define TIM0_TTOV_TOV7                  _TIM0_TTOV.Bits.TOV7

#define TIM0_TTOV_TOV0_MASK             1U
#define TIM0_TTOV_TOV1_MASK             2U
#define TIM0_TTOV_TOV2_MASK             4U
#define TIM0_TTOV_TOV3_MASK             8U
#define TIM0_TTOV_TOV4_MASK             16U
#define TIM0_TTOV_TOV5_MASK             32U
#define TIM0_TTOV_TOV6_MASK             64U
#define TIM0_TTOV_TOV7_MASK             128U


/*** TIM0_TCTL1 - Timer Control Register 1; 0x00000048 ***/
typedef union {
  byte Byte;
  struct {
    byte OL4         :1;                                       /* Output Level Bit 4 */
    byte OM4         :1;                                       /* Output Mode Bit 4 */
    byte OL5         :1;                                       /* Output Level Bit 5 */
    byte OM5         :1;                                       /* Output Mode Bit 5 */
    byte OL6         :1;                                       /* Output Level Bit 6 */
    byte OM6         :1;                                       /* Output Mode Bit 6 */
    byte OL7         :1;                                       /* Output Level Bit 7 */
    byte OM7         :1;                                       /* Output Mode Bit 7 */
  } Bits;
} TIM0_TCTL1STR;
extern volatile TIM0_TCTL1STR _TIM0_TCTL1 @(REG_BASE + 0x00000048UL);
#define TIM0_TCTL1                      _TIM0_TCTL1.Byte
#define TIM0_TCTL1_OL4                  _TIM0_TCTL1.Bits.OL4
#define TIM0_TCTL1_OM4                  _TIM0_TCTL1.Bits.OM4
#define TIM0_TCTL1_OL5                  _TIM0_TCTL1.Bits.OL5
#define TIM0_TCTL1_OM5                  _TIM0_TCTL1.Bits.OM5
#define TIM0_TCTL1_OL6                  _TIM0_TCTL1.Bits.OL6
#define TIM0_TCTL1_OM6                  _TIM0_TCTL1.Bits.OM6
#define TIM0_TCTL1_OL7                  _TIM0_TCTL1.Bits.OL7
#define TIM0_TCTL1_OM7                  _TIM0_TCTL1.Bits.OM7

#define TIM0_TCTL1_OL4_MASK             1U
#define TIM0_TCTL1_OM4_MASK             2U
#define TIM0_TCTL1_OL5_MASK             4U
#define TIM0_TCTL1_OM5_MASK             8U
#define TIM0_TCTL1_OL6_MASK             16U
#define TIM0_TCTL1_OM6_MASK             32U
#define TIM0_TCTL1_OL7_MASK             64U
#define TIM0_TCTL1_OM7_MASK             128U


/*** TIM0_TCTL2 - Timer Control Register 2; 0x00000049 ***/
typedef union {
  byte Byte;
  struct {
    byte OL0         :1;                                       /* Output Level Bit 0 */
    byte OM0         :1;                                       /* Output Mode Bit 0 */
    byte OL1         :1;                                       /* Output Lecel Bit 1 */
    byte OM1         :1;                                       /* Output Mode Bit 1 */
    byte OL2         :1;                                       /* Output Level Bit 2 */
    byte OM2         :1;                                       /* Output Mode Bit 2 */
    byte OL3         :1;                                       /* Output Level Bit 3 */
    byte OM3         :1;                                       /* Output Mode Bit 3 */
  } Bits;
} TIM0_TCTL2STR;
extern volatile TIM0_TCTL2STR _TIM0_TCTL2 @(REG_BASE + 0x00000049UL);
#define TIM0_TCTL2                      _TIM0_TCTL2.Byte
#define TIM0_TCTL2_OL0                  _TIM0_TCTL2.Bits.OL0
#define TIM0_TCTL2_OM0                  _TIM0_TCTL2.Bits.OM0
#define TIM0_TCTL2_OL1                  _TIM0_TCTL2.Bits.OL1
#define TIM0_TCTL2_OM1                  _TIM0_TCTL2.Bits.OM1
#define TIM0_TCTL2_OL2                  _TIM0_TCTL2.Bits.OL2
#define TIM0_TCTL2_OM2                  _TIM0_TCTL2.Bits.OM2
#define TIM0_TCTL2_OL3                  _TIM0_TCTL2.Bits.OL3
#define TIM0_TCTL2_OM3                  _TIM0_TCTL2.Bits.OM3

#define TIM0_TCTL2_OL0_MASK             1U
#define TIM0_TCTL2_OM0_MASK             2U
#define TIM0_TCTL2_OL1_MASK             4U
#define TIM0_TCTL2_OM1_MASK             8U
#define TIM0_TCTL2_OL2_MASK             16U
#define TIM0_TCTL2_OM2_MASK             32U
#define TIM0_TCTL2_OL3_MASK             64U
#define TIM0_TCTL2_OM3_MASK             128U


/*** TIM0_TCTL3 - Timer Control Register 3; 0x0000004A ***/
typedef union {
  byte Byte;
  struct {
    byte EDG4A       :1;                                       /* Input Capture Edge Control 4A */
    byte EDG4B       :1;                                       /* Input Capture Edge Control 4B */
    byte EDG5A       :1;                                       /* Input Capture Edge Control 5A */
    byte EDG5B       :1;                                       /* Input Capture Edge Control 5B */
    byte EDG6A       :1;                                       /* Input Capture Edge Control 6A */
    byte EDG6B       :1;                                       /* Input Capture Edge Control 6B */
    byte EDG7A       :1;                                       /* Input Capture Edge Control 7A */
    byte EDG7B       :1;                                       /* Input Capture Edge Control 7B */
  } Bits;
  struct {
    byte grpEDG4x :2;
    byte grpEDG5x :2;
    byte grpEDG6x :2;
    byte grpEDG7x :2;
  } MergedBits;
} TIM0_TCTL3STR;
extern volatile TIM0_TCTL3STR _TIM0_TCTL3 @(REG_BASE + 0x0000004AUL);
#define TIM0_TCTL3                      _TIM0_TCTL3.Byte
#define TIM0_TCTL3_EDG4A                _TIM0_TCTL3.Bits.EDG4A
#define TIM0_TCTL3_EDG4B                _TIM0_TCTL3.Bits.EDG4B
#define TIM0_TCTL3_EDG5A                _TIM0_TCTL3.Bits.EDG5A
#define TIM0_TCTL3_EDG5B                _TIM0_TCTL3.Bits.EDG5B
#define TIM0_TCTL3_EDG6A                _TIM0_TCTL3.Bits.EDG6A
#define TIM0_TCTL3_EDG6B                _TIM0_TCTL3.Bits.EDG6B
#define TIM0_TCTL3_EDG7A                _TIM0_TCTL3.Bits.EDG7A
#define TIM0_TCTL3_EDG7B                _TIM0_TCTL3.Bits.EDG7B
#define TIM0_TCTL3_EDG4x                _TIM0_TCTL3.MergedBits.grpEDG4x
#define TIM0_TCTL3_EDG5x                _TIM0_TCTL3.MergedBits.grpEDG5x
#define TIM0_TCTL3_EDG6x                _TIM0_TCTL3.MergedBits.grpEDG6x
#define TIM0_TCTL3_EDG7x                _TIM0_TCTL3.MergedBits.grpEDG7x

#define TIM0_TCTL3_EDG4A_MASK           1U
#define TIM0_TCTL3_EDG4B_MASK           2U
#define TIM0_TCTL3_EDG5A_MASK           4U
#define TIM0_TCTL3_EDG5B_MASK           8U
#define TIM0_TCTL3_EDG6A_MASK           16U
#define TIM0_TCTL3_EDG6B_MASK           32U
#define TIM0_TCTL3_EDG7A_MASK           64U
#define TIM0_TCTL3_EDG7B_MASK           128U
#define TIM0_TCTL3_EDG4x_MASK           3U
#define TIM0_TCTL3_EDG4x_BITNUM         0U
#define TIM0_TCTL3_EDG5x_MASK           12U
#define TIM0_TCTL3_EDG5x_BITNUM         2U
#define TIM0_TCTL3_EDG6x_MASK           48U
#define TIM0_TCTL3_EDG6x_BITNUM         4U
#define TIM0_TCTL3_EDG7x_MASK           192U
#define TIM0_TCTL3_EDG7x_BITNUM         6U


/*** TIM0_TCTL4 - Timer Control Register 4; 0x0000004B ***/
typedef union {
  byte Byte;
  struct {
    byte EDG0A       :1;                                       /* Input Capture Edge Control 0A */
    byte EDG0B       :1;                                       /* Input Capture Edge Control 0B */
    byte EDG1A       :1;                                       /* Input Capture Edge Control 1A */
    byte EDG1B       :1;                                       /* Input Capture Edge Control 1B */
    byte EDG2A       :1;                                       /* Input Capture Edge Control 2A */
    byte EDG2B       :1;                                       /* Input Capture Edge Control 2B */
    byte EDG3A       :1;                                       /* Input Capture Edge Control 3A */
    byte EDG3B       :1;                                       /* Input Capture Edge Control 3B */
  } Bits;
  struct {
    byte grpEDG0x :2;
    byte grpEDG1x :2;
    byte grpEDG2x :2;
    byte grpEDG3x :2;
  } MergedBits;
} TIM0_TCTL4STR;
extern volatile TIM0_TCTL4STR _TIM0_TCTL4 @(REG_BASE + 0x0000004BUL);
#define TIM0_TCTL4                      _TIM0_TCTL4.Byte
#define TIM0_TCTL4_EDG0A                _TIM0_TCTL4.Bits.EDG0A
#define TIM0_TCTL4_EDG0B                _TIM0_TCTL4.Bits.EDG0B
#define TIM0_TCTL4_EDG1A                _TIM0_TCTL4.Bits.EDG1A
#define TIM0_TCTL4_EDG1B                _TIM0_TCTL4.Bits.EDG1B
#define TIM0_TCTL4_EDG2A                _TIM0_TCTL4.Bits.EDG2A
#define TIM0_TCTL4_EDG2B                _TIM0_TCTL4.Bits.EDG2B
#define TIM0_TCTL4_EDG3A                _TIM0_TCTL4.Bits.EDG3A
#define TIM0_TCTL4_EDG3B                _TIM0_TCTL4.Bits.EDG3B
#define TIM0_TCTL4_EDG0x                _TIM0_TCTL4.MergedBits.grpEDG0x
#define TIM0_TCTL4_EDG1x                _TIM0_TCTL4.MergedBits.grpEDG1x
#define TIM0_TCTL4_EDG2x                _TIM0_TCTL4.MergedBits.grpEDG2x
#define TIM0_TCTL4_EDG3x                _TIM0_TCTL4.MergedBits.grpEDG3x

#define TIM0_TCTL4_EDG0A_MASK           1U
#define TIM0_TCTL4_EDG0B_MASK           2U
#define TIM0_TCTL4_EDG1A_MASK           4U
#define TIM0_TCTL4_EDG1B_MASK           8U
#define TIM0_TCTL4_EDG2A_MASK           16U
#define TIM0_TCTL4_EDG2B_MASK           32U
#define TIM0_TCTL4_EDG3A_MASK           64U
#define TIM0_TCTL4_EDG3B_MASK           128U
#define TIM0_TCTL4_EDG0x_MASK           3U
#define TIM0_TCTL4_EDG0x_BITNUM         0U
#define TIM0_TCTL4_EDG1x_MASK           12U
#define TIM0_TCTL4_EDG1x_BITNUM         2U
#define TIM0_TCTL4_EDG2x_MASK           48U
#define TIM0_TCTL4_EDG2x_BITNUM         4U
#define TIM0_TCTL4_EDG3x_MASK           192U
#define TIM0_TCTL4_EDG3x_BITNUM         6U


/*** TIM0_TIE - Timer Interrupt Enable Register; 0x0000004C ***/
typedef union {
  byte Byte;
  struct {
    byte C0I         :1;                                       /* Input Capture/Output Compare Interrupt Enable Bit 0 */
    byte C1I         :1;                                       /* Input Capture/Output Compare Interrupt Enable Bit 1 */
    byte C2I         :1;                                       /* Input Capture/Output Compare Interrupt Enable Bit 2 */
    byte C3I         :1;                                       /* Input Capture/Output Compare Interrupt Enable Bit 3 */
    byte C4I         :1;                                       /* Input Capture/Output Compare Interrupt Enable Bit 4 */
    byte C5I         :1;                                       /* Input Capture/Output Compare Interrupt Enable Bit 5 */
    byte C6I         :1;                                       /* Input Capture/Output Compare Interrupt Enable Bit 6 */
    byte C7I         :1;                                       /* Input Capture/Output Compare Interrupt Enable Bit 7 */
  } Bits;
} TIM0_TIESTR;
extern volatile TIM0_TIESTR _TIM0_TIE @(REG_BASE + 0x0000004CUL);
#define TIM0_TIE                        _TIM0_TIE.Byte
#define TIM0_TIE_C0I                    _TIM0_TIE.Bits.C0I
#define TIM0_TIE_C1I                    _TIM0_TIE.Bits.C1I
#define TIM0_TIE_C2I                    _TIM0_TIE.Bits.C2I
#define TIM0_TIE_C3I                    _TIM0_TIE.Bits.C3I
#define TIM0_TIE_C4I                    _TIM0_TIE.Bits.C4I
#define TIM0_TIE_C5I                    _TIM0_TIE.Bits.C5I
#define TIM0_TIE_C6I                    _TIM0_TIE.Bits.C6I
#define TIM0_TIE_C7I                    _TIM0_TIE.Bits.C7I

#define TIM0_TIE_C0I_MASK               1U
#define TIM0_TIE_C1I_MASK               2U
#define TIM0_TIE_C2I_MASK               4U
#define TIM0_TIE_C3I_MASK               8U
#define TIM0_TIE_C4I_MASK               16U
#define TIM0_TIE_C5I_MASK               32U
#define TIM0_TIE_C6I_MASK               64U
#define TIM0_TIE_C7I_MASK               128U


/*** TIM0_TSCR2 - Timer System Control Register 2; 0x0000004D ***/
typedef union {
  byte Byte;
  struct {
    byte PR0         :1;                                       /* Timer Prescaler Select Bit 0 */
    byte PR1         :1;                                       /* Timer Prescaler Select Bit 1 */
    byte PR2         :1;                                       /* Timer Prescaler Select Bit 2 */
    byte TCRE        :1;                                       /* Timer Counter Reset Enable */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte TOI         :1;                                       /* Timer Overflow Interrupt Enable */
  } Bits;
  struct {
    byte grpPR   :3;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} TIM0_TSCR2STR;
extern volatile TIM0_TSCR2STR _TIM0_TSCR2 @(REG_BASE + 0x0000004DUL);
#define TIM0_TSCR2                      _TIM0_TSCR2.Byte
#define TIM0_TSCR2_PR0                  _TIM0_TSCR2.Bits.PR0
#define TIM0_TSCR2_PR1                  _TIM0_TSCR2.Bits.PR1
#define TIM0_TSCR2_PR2                  _TIM0_TSCR2.Bits.PR2
#define TIM0_TSCR2_TCRE                 _TIM0_TSCR2.Bits.TCRE
#define TIM0_TSCR2_TOI                  _TIM0_TSCR2.Bits.TOI
#define TIM0_TSCR2_PR                   _TIM0_TSCR2.MergedBits.grpPR

#define TIM0_TSCR2_PR0_MASK             1U
#define TIM0_TSCR2_PR1_MASK             2U
#define TIM0_TSCR2_PR2_MASK             4U
#define TIM0_TSCR2_TCRE_MASK            8U
#define TIM0_TSCR2_TOI_MASK             128U
#define TIM0_TSCR2_PR_MASK              7U
#define TIM0_TSCR2_PR_BITNUM            0U


/*** TIM0_TFLG1 - Main Timer Interrupt Flag 1; 0x0000004E ***/
typedef union {
  byte Byte;
  struct {
    byte C0F         :1;                                       /* Input Capture/Output Compare Channel Flag 0 */
    byte C1F         :1;                                       /* Input Capture/Output Compare Channel Flag 1 */
    byte C2F         :1;                                       /* Input Capture/Output Compare Channel Flag 2 */
    byte C3F         :1;                                       /* Input Capture/Output Compare Channel Flag 3 */
    byte C4F         :1;                                       /* Input Capture/Output Compare Channel Flag 4 */
    byte C5F         :1;                                       /* Input Capture/Output Compare Channel Flag 5 */
    byte C6F         :1;                                       /* Input Capture/Output Compare Channel Flag 6 */
    byte C7F         :1;                                       /* Input Capture/Output Compare Channel Flag 7 */
  } Bits;
} TIM0_TFLG1STR;
extern volatile TIM0_TFLG1STR _TIM0_TFLG1 @(REG_BASE + 0x0000004EUL);
#define TIM0_TFLG1                      _TIM0_TFLG1.Byte
#define TIM0_TFLG1_C0F                  _TIM0_TFLG1.Bits.C0F
#define TIM0_TFLG1_C1F                  _TIM0_TFLG1.Bits.C1F
#define TIM0_TFLG1_C2F                  _TIM0_TFLG1.Bits.C2F
#define TIM0_TFLG1_C3F                  _TIM0_TFLG1.Bits.C3F
#define TIM0_TFLG1_C4F                  _TIM0_TFLG1.Bits.C4F
#define TIM0_TFLG1_C5F                  _TIM0_TFLG1.Bits.C5F
#define TIM0_TFLG1_C6F                  _TIM0_TFLG1.Bits.C6F
#define TIM0_TFLG1_C7F                  _TIM0_TFLG1.Bits.C7F

#define TIM0_TFLG1_C0F_MASK             1U
#define TIM0_TFLG1_C1F_MASK             2U
#define TIM0_TFLG1_C2F_MASK             4U
#define TIM0_TFLG1_C3F_MASK             8U
#define TIM0_TFLG1_C4F_MASK             16U
#define TIM0_TFLG1_C5F_MASK             32U
#define TIM0_TFLG1_C6F_MASK             64U
#define TIM0_TFLG1_C7F_MASK             128U


/*** TIM0_TFLG2 - Main Timer Interrupt Flag 2; 0x0000004F ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte TOF         :1;                                       /* Timer Overflow Flag */
  } Bits;
} TIM0_TFLG2STR;
extern volatile TIM0_TFLG2STR _TIM0_TFLG2 @(REG_BASE + 0x0000004FUL);
#define TIM0_TFLG2                      _TIM0_TFLG2.Byte
#define TIM0_TFLG2_TOF                  _TIM0_TFLG2.Bits.TOF

#define TIM0_TFLG2_TOF_MASK             128U


/*** TIM0_TC0 - Timer Input Capture/Output Compare Register 0; 0x00000050 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TIM0_TC0Hi - Timer Input Capture/Output Compare Register 0 High; 0x00000050 ***/
    union {
      byte Byte;
    } TIM0_TC0HiSTR;
    #define TIM0_TC0Hi                  _TIM0_TC0.Overlap_STR.TIM0_TC0HiSTR.Byte
    

    /*** TIM0_TC0Lo - Timer Input Capture/Output Compare Register 0 Low; 0x00000051 ***/
    union {
      byte Byte;
    } TIM0_TC0LoSTR;
    #define TIM0_TC0Lo                  _TIM0_TC0.Overlap_STR.TIM0_TC0LoSTR.Byte
    
  } Overlap_STR;

} TIM0_TC0STR;
extern volatile TIM0_TC0STR _TIM0_TC0 @(REG_BASE + 0x00000050UL);
#define TIM0_TC0                        _TIM0_TC0.Word
/* TIM0_TC_ARR: Access 8 TIM0_TCx registers in an array */
#define TIM0_TC_ARR                     ((volatile word *) &TIM0_TC0)


/*** TIM0_TC1 - Timer Input Capture/Output Compare Register 1; 0x00000052 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TIM0_TC1Hi - Timer Input Capture/Output Compare Register 1 High; 0x00000052 ***/
    union {
      byte Byte;
    } TIM0_TC1HiSTR;
    #define TIM0_TC1Hi                  _TIM0_TC1.Overlap_STR.TIM0_TC1HiSTR.Byte
    

    /*** TIM0_TC1Lo - Timer Input Capture/Output Compare Register 1 Low; 0x00000053 ***/
    union {
      byte Byte;
    } TIM0_TC1LoSTR;
    #define TIM0_TC1Lo                  _TIM0_TC1.Overlap_STR.TIM0_TC1LoSTR.Byte
    
  } Overlap_STR;

} TIM0_TC1STR;
extern volatile TIM0_TC1STR _TIM0_TC1 @(REG_BASE + 0x00000052UL);
#define TIM0_TC1                        _TIM0_TC1.Word


/*** TIM0_TC2 - Timer Input Capture/Output Compare Register 2; 0x00000054 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TIM0_TC2Hi - Timer Input Capture/Output Compare Register 2 High; 0x00000054 ***/
    union {
      byte Byte;
    } TIM0_TC2HiSTR;
    #define TIM0_TC2Hi                  _TIM0_TC2.Overlap_STR.TIM0_TC2HiSTR.Byte
    

    /*** TIM0_TC2Lo - Timer Input Capture/Output Compare Register 2 Low; 0x00000055 ***/
    union {
      byte Byte;
    } TIM0_TC2LoSTR;
    #define TIM0_TC2Lo                  _TIM0_TC2.Overlap_STR.TIM0_TC2LoSTR.Byte
    
  } Overlap_STR;

} TIM0_TC2STR;
extern volatile TIM0_TC2STR _TIM0_TC2 @(REG_BASE + 0x00000054UL);
#define TIM0_TC2                        _TIM0_TC2.Word


/*** TIM0_TC3 - Timer Input Capture/Output Compare Register 3; 0x00000056 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TIM0_TC3Hi - Timer Input Capture/Output Compare Register 3 High; 0x00000056 ***/
    union {
      byte Byte;
    } TIM0_TC3HiSTR;
    #define TIM0_TC3Hi                  _TIM0_TC3.Overlap_STR.TIM0_TC3HiSTR.Byte
    

    /*** TIM0_TC3Lo - Timer Input Capture/Output Compare Register 3 Low; 0x00000057 ***/
    union {
      byte Byte;
    } TIM0_TC3LoSTR;
    #define TIM0_TC3Lo                  _TIM0_TC3.Overlap_STR.TIM0_TC3LoSTR.Byte
    
  } Overlap_STR;

} TIM0_TC3STR;
extern volatile TIM0_TC3STR _TIM0_TC3 @(REG_BASE + 0x00000056UL);
#define TIM0_TC3                        _TIM0_TC3.Word


/*** TIM0_TC4 - Timer Input Capture/Output Compare Register 4; 0x00000058 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TIM0_TC4Hi - Timer Input Capture/Output Compare Register 4 High; 0x00000058 ***/
    union {
      byte Byte;
    } TIM0_TC4HiSTR;
    #define TIM0_TC4Hi                  _TIM0_TC4.Overlap_STR.TIM0_TC4HiSTR.Byte
    

    /*** TIM0_TC4Lo - Timer Input Capture/Output Compare Register 4 Low; 0x00000059 ***/
    union {
      byte Byte;
    } TIM0_TC4LoSTR;
    #define TIM0_TC4Lo                  _TIM0_TC4.Overlap_STR.TIM0_TC4LoSTR.Byte
    
  } Overlap_STR;

} TIM0_TC4STR;
extern volatile TIM0_TC4STR _TIM0_TC4 @(REG_BASE + 0x00000058UL);
#define TIM0_TC4                        _TIM0_TC4.Word


/*** TIM0_TC5 - Timer Input Capture/Output Compare Register 5; 0x0000005A ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TIM0_TC5Hi - Timer Input Capture/Output Compare Register 5 High; 0x0000005A ***/
    union {
      byte Byte;
    } TIM0_TC5HiSTR;
    #define TIM0_TC5Hi                  _TIM0_TC5.Overlap_STR.TIM0_TC5HiSTR.Byte
    

    /*** TIM0_TC5Lo - Timer Input Capture/Output Compare Register 5 Low; 0x0000005B ***/
    union {
      byte Byte;
    } TIM0_TC5LoSTR;
    #define TIM0_TC5Lo                  _TIM0_TC5.Overlap_STR.TIM0_TC5LoSTR.Byte
    
  } Overlap_STR;

} TIM0_TC5STR;
extern volatile TIM0_TC5STR _TIM0_TC5 @(REG_BASE + 0x0000005AUL);
#define TIM0_TC5                        _TIM0_TC5.Word


/*** TIM0_TC6 - Timer Input Capture/Output Compare Register 6; 0x0000005C ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TIM0_TC6Hi - Timer Input Capture/Output Compare Register 6 High; 0x0000005C ***/
    union {
      byte Byte;
    } TIM0_TC6HiSTR;
    #define TIM0_TC6Hi                  _TIM0_TC6.Overlap_STR.TIM0_TC6HiSTR.Byte
    

    /*** TIM0_TC6Lo - Timer Input Capture/Output Compare Register 6 Low; 0x0000005D ***/
    union {
      byte Byte;
    } TIM0_TC6LoSTR;
    #define TIM0_TC6Lo                  _TIM0_TC6.Overlap_STR.TIM0_TC6LoSTR.Byte
    
  } Overlap_STR;

} TIM0_TC6STR;
extern volatile TIM0_TC6STR _TIM0_TC6 @(REG_BASE + 0x0000005CUL);
#define TIM0_TC6                        _TIM0_TC6.Word


/*** TIM0_TC7 - Timer Input Capture/Output Compare Register 7; 0x0000005E ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TIM0_TC7Hi - Timer Input Capture/Output Compare Register 7 High; 0x0000005E ***/
    union {
      byte Byte;
    } TIM0_TC7HiSTR;
    #define TIM0_TC7Hi                  _TIM0_TC7.Overlap_STR.TIM0_TC7HiSTR.Byte
    

    /*** TIM0_TC7Lo - Timer Input Capture/Output Compare Register 7 Low; 0x0000005F ***/
    union {
      byte Byte;
    } TIM0_TC7LoSTR;
    #define TIM0_TC7Lo                  _TIM0_TC7.Overlap_STR.TIM0_TC7LoSTR.Byte
    
  } Overlap_STR;

} TIM0_TC7STR;
extern volatile TIM0_TC7STR _TIM0_TC7 @(REG_BASE + 0x0000005EUL);
#define TIM0_TC7                        _TIM0_TC7.Word


/*** TIM0_PACTL - 16-Bit Pulse Accumulator A Control Register; 0x00000060 ***/
typedef union {
  byte Byte;
  struct {
    byte PAI         :1;                                       /* Pulse Accumulator Input Interrupt enable */
    byte PAOVI       :1;                                       /* Pulse Accumulator A Overflow Interrupt enable */
    byte CLK0        :1;                                       /* Clock Select Bit 0 */
    byte CLK1        :1;                                       /* Clock Select Bit 1 */
    byte PEDGE       :1;                                       /* Pulse Accumulator Edge Control */
    byte PAMOD       :1;                                       /* Pulse Accumulator Mode */
    byte PAEN        :1;                                       /* Pulse Accumulator A System Enable */
    byte             :1; 
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte grpCLK  :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} TIM0_PACTLSTR;
extern volatile TIM0_PACTLSTR _TIM0_PACTL @(REG_BASE + 0x00000060UL);
#define TIM0_PACTL                      _TIM0_PACTL.Byte
#define TIM0_PACTL_PAI                  _TIM0_PACTL.Bits.PAI
#define TIM0_PACTL_PAOVI                _TIM0_PACTL.Bits.PAOVI
#define TIM0_PACTL_CLK0                 _TIM0_PACTL.Bits.CLK0
#define TIM0_PACTL_CLK1                 _TIM0_PACTL.Bits.CLK1
#define TIM0_PACTL_PEDGE                _TIM0_PACTL.Bits.PEDGE
#define TIM0_PACTL_PAMOD                _TIM0_PACTL.Bits.PAMOD
#define TIM0_PACTL_PAEN                 _TIM0_PACTL.Bits.PAEN
#define TIM0_PACTL_CLK                  _TIM0_PACTL.MergedBits.grpCLK

#define TIM0_PACTL_PAI_MASK             1U
#define TIM0_PACTL_PAOVI_MASK           2U
#define TIM0_PACTL_CLK0_MASK            4U
#define TIM0_PACTL_CLK1_MASK            8U
#define TIM0_PACTL_PEDGE_MASK           16U
#define TIM0_PACTL_PAMOD_MASK           32U
#define TIM0_PACTL_PAEN_MASK            64U
#define TIM0_PACTL_CLK_MASK             12U
#define TIM0_PACTL_CLK_BITNUM           2U


/*** TIM0_PAFLG - Pulse Accumulator A Flag Register; 0x00000061 ***/
typedef union {
  byte Byte;
  struct {
    byte PAIF        :1;                                       /* Pulse Accumulator Input edge Flag */
    byte PAOVF       :1;                                       /* Pulse Accumulator A Overflow Flag */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} TIM0_PAFLGSTR;
extern volatile TIM0_PAFLGSTR _TIM0_PAFLG @(REG_BASE + 0x00000061UL);
#define TIM0_PAFLG                      _TIM0_PAFLG.Byte
#define TIM0_PAFLG_PAIF                 _TIM0_PAFLG.Bits.PAIF
#define TIM0_PAFLG_PAOVF                _TIM0_PAFLG.Bits.PAOVF

#define TIM0_PAFLG_PAIF_MASK            1U
#define TIM0_PAFLG_PAOVF_MASK           2U


/*** TIM0_PACNT - Pulse Accumulators Count Register; 0x00000062 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TIM0_PACNTH - Pulse Accumulators Count Register High; 0x00000062 ***/
    union {
      byte Byte;
    } TIM0_PACNTHSTR;
    #define TIM0_PACNTH                 _TIM0_PACNT.Overlap_STR.TIM0_PACNTHSTR.Byte
    

    /*** TIM0_PACNTL - Pulse Accumulators Count Register Low; 0x00000063 ***/
    union {
      byte Byte;
    } TIM0_PACNTLSTR;
    #define TIM0_PACNTL                 _TIM0_PACNT.Overlap_STR.TIM0_PACNTLSTR.Byte
    
  } Overlap_STR;

} TIM0_PACNTSTR;
extern volatile TIM0_PACNTSTR _TIM0_PACNT @(REG_BASE + 0x00000062UL);
#define TIM0_PACNT                      _TIM0_PACNT.Word


/*** TIM0_OCPD - Output Compare Pin Disconnect Register; 0x0000006C ***/
typedef union {
  byte Byte;
  struct {
    byte OCPD0       :1;                                       /* Output Compare Pin Disconnect Bit 0 */
    byte OCPD1       :1;                                       /* Output Compare Pin Disconnect Bit 1 */
    byte OCPD2       :1;                                       /* Output Compare Pin Disconnect Bit 2 */
    byte OCPD3       :1;                                       /* Output Compare Pin Disconnect Bit 3 */
    byte OCPD4       :1;                                       /* Output Compare Pin Disconnect Bit 4 */
    byte OCPD5       :1;                                       /* Output Compare Pin Disconnect Bit 5 */
    byte OCPD6       :1;                                       /* Output Compare Pin Disconnect Bit 6 */
    byte OCPD7       :1;                                       /* Output Compare Pin Disconnect Bit 7 */
  } Bits;
} TIM0_OCPDSTR;
extern volatile TIM0_OCPDSTR _TIM0_OCPD @(REG_BASE + 0x0000006CUL);
#define TIM0_OCPD                       _TIM0_OCPD.Byte
#define TIM0_OCPD_OCPD0                 _TIM0_OCPD.Bits.OCPD0
#define TIM0_OCPD_OCPD1                 _TIM0_OCPD.Bits.OCPD1
#define TIM0_OCPD_OCPD2                 _TIM0_OCPD.Bits.OCPD2
#define TIM0_OCPD_OCPD3                 _TIM0_OCPD.Bits.OCPD3
#define TIM0_OCPD_OCPD4                 _TIM0_OCPD.Bits.OCPD4
#define TIM0_OCPD_OCPD5                 _TIM0_OCPD.Bits.OCPD5
#define TIM0_OCPD_OCPD6                 _TIM0_OCPD.Bits.OCPD6
#define TIM0_OCPD_OCPD7                 _TIM0_OCPD.Bits.OCPD7

#define TIM0_OCPD_OCPD0_MASK            1U
#define TIM0_OCPD_OCPD1_MASK            2U
#define TIM0_OCPD_OCPD2_MASK            4U
#define TIM0_OCPD_OCPD3_MASK            8U
#define TIM0_OCPD_OCPD4_MASK            16U
#define TIM0_OCPD_OCPD5_MASK            32U
#define TIM0_OCPD_OCPD6_MASK            64U
#define TIM0_OCPD_OCPD7_MASK            128U


/*** TIM0_PTPSR - Precision Timer Prescaler Select Register; 0x0000006E ***/
typedef union {
  byte Byte;
  struct {
    byte PTPS0       :1;                                       /* Precision Timer Prescaler Select Bit 0 */
    byte PTPS1       :1;                                       /* Precision Timer Prescaler Select Bit 1 */
    byte PTPS2       :1;                                       /* Precision Timer Prescaler Select Bit 2 */
    byte PTPS3       :1;                                       /* Precision Timer Prescaler Select Bit 3 */
    byte PTPS4       :1;                                       /* Precision Timer Prescaler Select Bit 4 */
    byte PTPS5       :1;                                       /* Precision Timer Prescaler Select Bit 5 */
    byte PTPS6       :1;                                       /* Precision Timer Prescaler Select Bit 6 */
    byte PTPS7       :1;                                       /* Precision Timer Prescaler Select Bit 7 */
  } Bits;
} TIM0_PTPSRSTR;
extern volatile TIM0_PTPSRSTR _TIM0_PTPSR @(REG_BASE + 0x0000006EUL);
#define TIM0_PTPSR                      _TIM0_PTPSR.Byte
#define TIM0_PTPSR_PTPS0                _TIM0_PTPSR.Bits.PTPS0
#define TIM0_PTPSR_PTPS1                _TIM0_PTPSR.Bits.PTPS1
#define TIM0_PTPSR_PTPS2                _TIM0_PTPSR.Bits.PTPS2
#define TIM0_PTPSR_PTPS3                _TIM0_PTPSR.Bits.PTPS3
#define TIM0_PTPSR_PTPS4                _TIM0_PTPSR.Bits.PTPS4
#define TIM0_PTPSR_PTPS5                _TIM0_PTPSR.Bits.PTPS5
#define TIM0_PTPSR_PTPS6                _TIM0_PTPSR.Bits.PTPS6
#define TIM0_PTPSR_PTPS7                _TIM0_PTPSR.Bits.PTPS7

#define TIM0_PTPSR_PTPS0_MASK           1U
#define TIM0_PTPSR_PTPS1_MASK           2U
#define TIM0_PTPSR_PTPS2_MASK           4U
#define TIM0_PTPSR_PTPS3_MASK           8U
#define TIM0_PTPSR_PTPS4_MASK           16U
#define TIM0_PTPSR_PTPS5_MASK           32U
#define TIM0_PTPSR_PTPS6_MASK           64U
#define TIM0_PTPSR_PTPS7_MASK           128U


/*** ATDCTL01 - ATD  Control Register 01; 0x00000070 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** ATDCTL0 - ATD  Control Register 0; 0x00000070 ***/
    union {
      byte Byte;
      struct {
        byte WRAP0       :1;                                       /* Wrap Around Channel Select Bit 0 */
        byte WRAP1       :1;                                       /* Wrap Around Channel Select Bit 1 */
        byte WRAP2       :1;                                       /* Wrap Around Channel Select Bit 2 */
        byte WRAP3       :1;                                       /* Wrap Around Channel Select Bit 3 */
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
      } Bits;
      struct {
        byte grpWRAP :4;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
      } MergedBits;
    } ATDCTL0STR;
    #define ATDCTL0                     _ATDCTL01.Overlap_STR.ATDCTL0STR.Byte
    #define ATDCTL0_WRAP0               _ATDCTL01.Overlap_STR.ATDCTL0STR.Bits.WRAP0
    #define ATDCTL0_WRAP1               _ATDCTL01.Overlap_STR.ATDCTL0STR.Bits.WRAP1
    #define ATDCTL0_WRAP2               _ATDCTL01.Overlap_STR.ATDCTL0STR.Bits.WRAP2
    #define ATDCTL0_WRAP3               _ATDCTL01.Overlap_STR.ATDCTL0STR.Bits.WRAP3
    /* ATDCTL_ARR: Access 6 ATDCTLx registers in an array */
    #define ATDCTL_ARR                  ((volatile byte *) &ATDCTL0)
    #define ATDCTL0_WRAP                _ATDCTL01.Overlap_STR.ATDCTL0STR.MergedBits.grpWRAP
    
    #define ATDCTL0_WRAP0_MASK          1U
    #define ATDCTL0_WRAP1_MASK          2U
    #define ATDCTL0_WRAP2_MASK          4U
    #define ATDCTL0_WRAP3_MASK          8U
    #define ATDCTL0_WRAP_MASK           15U
    #define ATDCTL0_WRAP_BITNUM         0U
    

    /*** ATDCTL1 - ATD  Control Register 1; 0x00000071 ***/
    union {
      byte Byte;
      struct {
        byte ETRIGCH0    :1;                                       /* External Trigger Channel Select Bit 0 */
        byte ETRIGCH1    :1;                                       /* External Trigger Channel Select Bit 1 */
        byte ETRIGCH2    :1;                                       /* External Trigger Channel Select Bit 2 */
        byte ETRIGCH3    :1;                                       /* External Trigger Channel Select Bit 3 */
        byte SMP_DIS     :1;                                       /* Discharge Before Sampling Bit */
        byte SRES0       :1;                                       /* A/D Resolution Select Bit 0 */
        byte SRES1       :1;                                       /* A/D Resolution Select Bit 1 */
        byte ETRIGSEL    :1;                                       /* External Trigger Source Select */
      } Bits;
      struct {
        byte grpETRIGCH :4;
        byte     :1;
        byte grpSRES :2;
        byte     :1;
      } MergedBits;
    } ATDCTL1STR;
    #define ATDCTL1                     _ATDCTL01.Overlap_STR.ATDCTL1STR.Byte
    #define ATDCTL1_ETRIGCH0            _ATDCTL01.Overlap_STR.ATDCTL1STR.Bits.ETRIGCH0
    #define ATDCTL1_ETRIGCH1            _ATDCTL01.Overlap_STR.ATDCTL1STR.Bits.ETRIGCH1
    #define ATDCTL1_ETRIGCH2            _ATDCTL01.Overlap_STR.ATDCTL1STR.Bits.ETRIGCH2
    #define ATDCTL1_ETRIGCH3            _ATDCTL01.Overlap_STR.ATDCTL1STR.Bits.ETRIGCH3
    #define ATDCTL1_SMP_DIS             _ATDCTL01.Overlap_STR.ATDCTL1STR.Bits.SMP_DIS
    #define ATDCTL1_SRES0               _ATDCTL01.Overlap_STR.ATDCTL1STR.Bits.SRES0
    #define ATDCTL1_SRES1               _ATDCTL01.Overlap_STR.ATDCTL1STR.Bits.SRES1
    #define ATDCTL1_ETRIGSEL            _ATDCTL01.Overlap_STR.ATDCTL1STR.Bits.ETRIGSEL
    #define ATDCTL1_ETRIGCH             _ATDCTL01.Overlap_STR.ATDCTL1STR.MergedBits.grpETRIGCH
    #define ATDCTL1_SRES                _ATDCTL01.Overlap_STR.ATDCTL1STR.MergedBits.grpSRES
    
    #define ATDCTL1_ETRIGCH0_MASK       1U
    #define ATDCTL1_ETRIGCH1_MASK       2U
    #define ATDCTL1_ETRIGCH2_MASK       4U
    #define ATDCTL1_ETRIGCH3_MASK       8U
    #define ATDCTL1_SMP_DIS_MASK        16U
    #define ATDCTL1_SRES0_MASK          32U
    #define ATDCTL1_SRES1_MASK          64U
    #define ATDCTL1_ETRIGSEL_MASK       128U
    #define ATDCTL1_ETRIGCH_MASK        15U
    #define ATDCTL1_ETRIGCH_BITNUM      0U
    #define ATDCTL1_SRES_MASK           96U
    #define ATDCTL1_SRES_BITNUM         5U
    
  } Overlap_STR;

  struct {
    word ETRIGCH0    :1;                                       /* External Trigger Channel Select Bit 0 */
    word ETRIGCH1    :1;                                       /* External Trigger Channel Select Bit 1 */
    word ETRIGCH2    :1;                                       /* External Trigger Channel Select Bit 2 */
    word ETRIGCH3    :1;                                       /* External Trigger Channel Select Bit 3 */
    word SMP_DIS     :1;                                       /* Discharge Before Sampling Bit */
    word SRES0       :1;                                       /* A/D Resolution Select Bit 0 */
    word SRES1       :1;                                       /* A/D Resolution Select Bit 1 */
    word ETRIGSEL    :1;                                       /* External Trigger Source Select */
    word WRAP0       :1;                                       /* Wrap Around Channel Select Bit 0 */
    word WRAP1       :1;                                       /* Wrap Around Channel Select Bit 1 */
    word WRAP2       :1;                                       /* Wrap Around Channel Select Bit 2 */
    word WRAP3       :1;                                       /* Wrap Around Channel Select Bit 3 */
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
  } Bits;
  struct {
    word grpETRIGCH :4;
    word         :1;
    word grpSRES :2;
    word         :1;
    word grpWRAP :4;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
  } MergedBits;
} ATDCTL01STR;
extern volatile ATDCTL01STR _ATDCTL01 @(REG_BASE + 0x00000070UL);
#define ATDCTL01                        _ATDCTL01.Word
#define ATDCTL01_ETRIGCH0               _ATDCTL01.Bits.ETRIGCH0
#define ATDCTL01_ETRIGCH1               _ATDCTL01.Bits.ETRIGCH1
#define ATDCTL01_ETRIGCH2               _ATDCTL01.Bits.ETRIGCH2
#define ATDCTL01_ETRIGCH3               _ATDCTL01.Bits.ETRIGCH3
#define ATDCTL01_SMP_DIS                _ATDCTL01.Bits.SMP_DIS
#define ATDCTL01_SRES0                  _ATDCTL01.Bits.SRES0
#define ATDCTL01_SRES1                  _ATDCTL01.Bits.SRES1
#define ATDCTL01_ETRIGSEL               _ATDCTL01.Bits.ETRIGSEL
#define ATDCTL01_WRAP0                  _ATDCTL01.Bits.WRAP0
#define ATDCTL01_WRAP1                  _ATDCTL01.Bits.WRAP1
#define ATDCTL01_WRAP2                  _ATDCTL01.Bits.WRAP2
#define ATDCTL01_WRAP3                  _ATDCTL01.Bits.WRAP3
#define ATDCTL01_ETRIGCH                _ATDCTL01.MergedBits.grpETRIGCH
#define ATDCTL01_SRES                   _ATDCTL01.MergedBits.grpSRES
#define ATDCTL01_WRAP                   _ATDCTL01.MergedBits.grpWRAP

#define ATDCTL01_ETRIGCH0_MASK          1U
#define ATDCTL01_ETRIGCH1_MASK          2U
#define ATDCTL01_ETRIGCH2_MASK          4U
#define ATDCTL01_ETRIGCH3_MASK          8U
#define ATDCTL01_SMP_DIS_MASK           16U
#define ATDCTL01_SRES0_MASK             32U
#define ATDCTL01_SRES1_MASK             64U
#define ATDCTL01_ETRIGSEL_MASK          128U
#define ATDCTL01_WRAP0_MASK             256U
#define ATDCTL01_WRAP1_MASK             512U
#define ATDCTL01_WRAP2_MASK             1024U
#define ATDCTL01_WRAP3_MASK             2048U
#define ATDCTL01_ETRIGCH_MASK           15U
#define ATDCTL01_ETRIGCH_BITNUM         0U
#define ATDCTL01_SRES_MASK              96U
#define ATDCTL01_SRES_BITNUM            5U
#define ATDCTL01_WRAP_MASK              3840U
#define ATDCTL01_WRAP_BITNUM            8U


/*** ATDCTL23 - ATD  Control Register 23; 0x00000072 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** ATDCTL2 - ATD  Control Register 2; 0x00000072 ***/
    union {
      byte Byte;
      struct {
        byte ACMPIE      :1;                                       /* ATD Compare Interrupt Enable */
        byte ASCIE       :1;                                       /* ATD Sequence Complete Interrupt Enable */
        byte ETRIGE      :1;                                       /* External Trigger Mode enable */
        byte ETRIGP      :1;                                       /* External Trigger Polarity */
        byte ETRIGLE     :1;                                       /* External Trigger Level/Edge control */
        byte ICLKSTP     :1;                                       /* Internal Clock in Stop Mode Bit */
        byte AFFC        :1;                                       /* ATD Fast Conversion Complete Flag Clear */
        byte             :1; 
      } Bits;
    } ATDCTL2STR;
    #define ATDCTL2                     _ATDCTL23.Overlap_STR.ATDCTL2STR.Byte
    #define ATDCTL2_ACMPIE              _ATDCTL23.Overlap_STR.ATDCTL2STR.Bits.ACMPIE
    #define ATDCTL2_ASCIE               _ATDCTL23.Overlap_STR.ATDCTL2STR.Bits.ASCIE
    #define ATDCTL2_ETRIGE              _ATDCTL23.Overlap_STR.ATDCTL2STR.Bits.ETRIGE
    #define ATDCTL2_ETRIGP              _ATDCTL23.Overlap_STR.ATDCTL2STR.Bits.ETRIGP
    #define ATDCTL2_ETRIGLE             _ATDCTL23.Overlap_STR.ATDCTL2STR.Bits.ETRIGLE
    #define ATDCTL2_ICLKSTP             _ATDCTL23.Overlap_STR.ATDCTL2STR.Bits.ICLKSTP
    #define ATDCTL2_AFFC                _ATDCTL23.Overlap_STR.ATDCTL2STR.Bits.AFFC
    
    #define ATDCTL2_ACMPIE_MASK         1U
    #define ATDCTL2_ASCIE_MASK          2U
    #define ATDCTL2_ETRIGE_MASK         4U
    #define ATDCTL2_ETRIGP_MASK         8U
    #define ATDCTL2_ETRIGLE_MASK        16U
    #define ATDCTL2_ICLKSTP_MASK        32U
    #define ATDCTL2_AFFC_MASK           64U
    

    /*** ATDCTL3 - ATD  Control Register 3; 0x00000073 ***/
    union {
      byte Byte;
      struct {
        byte FRZ0        :1;                                       /* Background Debug Freeze Enable Bit 0 */
        byte FRZ1        :1;                                       /* Background Debug Freeze Enable Bit 1 */
        byte FIFO        :1;                                       /* Result Register FIFO Mode */
        byte S1C         :1;                                       /* Conversion Sequence Length 1 */
        byte S2C         :1;                                       /* Conversion Sequence Length 2 */
        byte S4C         :1;                                       /* Conversion Sequence Length 4 */
        byte S8C         :1;                                       /* Conversion Sequence Length 8 */
        byte DJM         :1;                                       /* Result Register Data Justification */
      } Bits;
      struct {
        byte grpFRZ :2;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
      } MergedBits;
    } ATDCTL3STR;
    #define ATDCTL3                     _ATDCTL23.Overlap_STR.ATDCTL3STR.Byte
    #define ATDCTL3_FRZ0                _ATDCTL23.Overlap_STR.ATDCTL3STR.Bits.FRZ0
    #define ATDCTL3_FRZ1                _ATDCTL23.Overlap_STR.ATDCTL3STR.Bits.FRZ1
    #define ATDCTL3_FIFO                _ATDCTL23.Overlap_STR.ATDCTL3STR.Bits.FIFO
    #define ATDCTL3_S1C                 _ATDCTL23.Overlap_STR.ATDCTL3STR.Bits.S1C
    #define ATDCTL3_S2C                 _ATDCTL23.Overlap_STR.ATDCTL3STR.Bits.S2C
    #define ATDCTL3_S4C                 _ATDCTL23.Overlap_STR.ATDCTL3STR.Bits.S4C
    #define ATDCTL3_S8C                 _ATDCTL23.Overlap_STR.ATDCTL3STR.Bits.S8C
    #define ATDCTL3_DJM                 _ATDCTL23.Overlap_STR.ATDCTL3STR.Bits.DJM
    #define ATDCTL3_FRZ                 _ATDCTL23.Overlap_STR.ATDCTL3STR.MergedBits.grpFRZ
    
    #define ATDCTL3_FRZ0_MASK           1U
    #define ATDCTL3_FRZ1_MASK           2U
    #define ATDCTL3_FIFO_MASK           4U
    #define ATDCTL3_S1C_MASK            8U
    #define ATDCTL3_S2C_MASK            16U
    #define ATDCTL3_S4C_MASK            32U
    #define ATDCTL3_S8C_MASK            64U
    #define ATDCTL3_DJM_MASK            128U
    #define ATDCTL3_FRZ_MASK            3U
    #define ATDCTL3_FRZ_BITNUM          0U
    
  } Overlap_STR;

  struct {
    word FRZ0        :1;                                       /* Background Debug Freeze Enable Bit 0 */
    word FRZ1        :1;                                       /* Background Debug Freeze Enable Bit 1 */
    word FIFO        :1;                                       /* Result Register FIFO Mode */
    word S1C         :1;                                       /* Conversion Sequence Length 1 */
    word S2C         :1;                                       /* Conversion Sequence Length 2 */
    word S4C         :1;                                       /* Conversion Sequence Length 4 */
    word S8C         :1;                                       /* Conversion Sequence Length 8 */
    word DJM         :1;                                       /* Result Register Data Justification */
    word ACMPIE      :1;                                       /* ATD Compare Interrupt Enable */
    word ASCIE       :1;                                       /* ATD Sequence Complete Interrupt Enable */
    word ETRIGE      :1;                                       /* External Trigger Mode enable */
    word ETRIGP      :1;                                       /* External Trigger Polarity */
    word ETRIGLE     :1;                                       /* External Trigger Level/Edge control */
    word ICLKSTP     :1;                                       /* Internal Clock in Stop Mode Bit */
    word AFFC        :1;                                       /* ATD Fast Conversion Complete Flag Clear */
    word             :1; 
  } Bits;
  struct {
    word grpFRZ  :2;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
  } MergedBits;
} ATDCTL23STR;
extern volatile ATDCTL23STR _ATDCTL23 @(REG_BASE + 0x00000072UL);
#define ATDCTL23                        _ATDCTL23.Word
#define ATDCTL23_FRZ0                   _ATDCTL23.Bits.FRZ0
#define ATDCTL23_FRZ1                   _ATDCTL23.Bits.FRZ1
#define ATDCTL23_FIFO                   _ATDCTL23.Bits.FIFO
#define ATDCTL23_S1C                    _ATDCTL23.Bits.S1C
#define ATDCTL23_S2C                    _ATDCTL23.Bits.S2C
#define ATDCTL23_S4C                    _ATDCTL23.Bits.S4C
#define ATDCTL23_S8C                    _ATDCTL23.Bits.S8C
#define ATDCTL23_DJM                    _ATDCTL23.Bits.DJM
#define ATDCTL23_ACMPIE                 _ATDCTL23.Bits.ACMPIE
#define ATDCTL23_ASCIE                  _ATDCTL23.Bits.ASCIE
#define ATDCTL23_ETRIGE                 _ATDCTL23.Bits.ETRIGE
#define ATDCTL23_ETRIGP                 _ATDCTL23.Bits.ETRIGP
#define ATDCTL23_ETRIGLE                _ATDCTL23.Bits.ETRIGLE
#define ATDCTL23_ICLKSTP                _ATDCTL23.Bits.ICLKSTP
#define ATDCTL23_AFFC                   _ATDCTL23.Bits.AFFC
#define ATDCTL23_FRZ                    _ATDCTL23.MergedBits.grpFRZ

#define ATDCTL23_FRZ0_MASK              1U
#define ATDCTL23_FRZ1_MASK              2U
#define ATDCTL23_FIFO_MASK              4U
#define ATDCTL23_S1C_MASK               8U
#define ATDCTL23_S2C_MASK               16U
#define ATDCTL23_S4C_MASK               32U
#define ATDCTL23_S8C_MASK               64U
#define ATDCTL23_DJM_MASK               128U
#define ATDCTL23_ACMPIE_MASK            256U
#define ATDCTL23_ASCIE_MASK             512U
#define ATDCTL23_ETRIGE_MASK            1024U
#define ATDCTL23_ETRIGP_MASK            2048U
#define ATDCTL23_ETRIGLE_MASK           4096U
#define ATDCTL23_ICLKSTP_MASK           8192U
#define ATDCTL23_AFFC_MASK              16384U
#define ATDCTL23_FRZ_MASK               3U
#define ATDCTL23_FRZ_BITNUM             0U


/*** ATDCTL45 - ATD  Control Register 45; 0x00000074 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** ATDCTL4 - ATD  Control Register 4; 0x00000074 ***/
    union {
      byte Byte;
      struct {
        byte PRS0        :1;                                       /* ATD Clock Prescaler 0 */
        byte PRS1        :1;                                       /* ATD Clock Prescaler 1 */
        byte PRS2        :1;                                       /* ATD Clock Prescaler 2 */
        byte PRS3        :1;                                       /* ATD Clock Prescaler 3 */
        byte PRS4        :1;                                       /* ATD Clock Prescaler 4 */
        byte SMP0        :1;                                       /* Sample Time Select 0 */
        byte SMP1        :1;                                       /* Sample Time Select 1 */
        byte SMP2        :1;                                       /* Sample Time Select 2 */
      } Bits;
      struct {
        byte grpPRS :5;
        byte grpSMP :3;
      } MergedBits;
    } ATDCTL4STR;
    #define ATDCTL4                     _ATDCTL45.Overlap_STR.ATDCTL4STR.Byte
    #define ATDCTL4_PRS0                _ATDCTL45.Overlap_STR.ATDCTL4STR.Bits.PRS0
    #define ATDCTL4_PRS1                _ATDCTL45.Overlap_STR.ATDCTL4STR.Bits.PRS1
    #define ATDCTL4_PRS2                _ATDCTL45.Overlap_STR.ATDCTL4STR.Bits.PRS2
    #define ATDCTL4_PRS3                _ATDCTL45.Overlap_STR.ATDCTL4STR.Bits.PRS3
    #define ATDCTL4_PRS4                _ATDCTL45.Overlap_STR.ATDCTL4STR.Bits.PRS4
    #define ATDCTL4_SMP0                _ATDCTL45.Overlap_STR.ATDCTL4STR.Bits.SMP0
    #define ATDCTL4_SMP1                _ATDCTL45.Overlap_STR.ATDCTL4STR.Bits.SMP1
    #define ATDCTL4_SMP2                _ATDCTL45.Overlap_STR.ATDCTL4STR.Bits.SMP2
    #define ATDCTL4_PRS                 _ATDCTL45.Overlap_STR.ATDCTL4STR.MergedBits.grpPRS
    #define ATDCTL4_SMP                 _ATDCTL45.Overlap_STR.ATDCTL4STR.MergedBits.grpSMP
    
    #define ATDCTL4_PRS0_MASK           1U
    #define ATDCTL4_PRS1_MASK           2U
    #define ATDCTL4_PRS2_MASK           4U
    #define ATDCTL4_PRS3_MASK           8U
    #define ATDCTL4_PRS4_MASK           16U
    #define ATDCTL4_SMP0_MASK           32U
    #define ATDCTL4_SMP1_MASK           64U
    #define ATDCTL4_SMP2_MASK           128U
    #define ATDCTL4_PRS_MASK            31U
    #define ATDCTL4_PRS_BITNUM          0U
    #define ATDCTL4_SMP_MASK            224U
    #define ATDCTL4_SMP_BITNUM          5U
    

    /*** ATDCTL5 - ATD  Control Register 5; 0x00000075 ***/
    union {
      byte Byte;
      struct {
        byte CA          :1;                                       /* Analog Input Channel Select Code A */
        byte CB          :1;                                       /* Analog Input Channel Select Code B */
        byte CC          :1;                                       /* Analog Input Channel Select Code C */
        byte CD          :1;                                       /* Analog Input Channel Select Code D */
        byte MULT        :1;                                       /* Multi-Channel Sample Mode */
        byte SCAN        :1;                                       /* Continuous Conversion Sequence Mode */
        byte SC          :1;                                       /* Special Channel Conversion Bit */
        byte             :1; 
      } Bits;
      struct {
        byte grpCx :4;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
      } MergedBits;
    } ATDCTL5STR;
    #define ATDCTL5                     _ATDCTL45.Overlap_STR.ATDCTL5STR.Byte
    #define ATDCTL5_CA                  _ATDCTL45.Overlap_STR.ATDCTL5STR.Bits.CA
    #define ATDCTL5_CB                  _ATDCTL45.Overlap_STR.ATDCTL5STR.Bits.CB
    #define ATDCTL5_CC                  _ATDCTL45.Overlap_STR.ATDCTL5STR.Bits.CC
    #define ATDCTL5_CD                  _ATDCTL45.Overlap_STR.ATDCTL5STR.Bits.CD
    #define ATDCTL5_MULT                _ATDCTL45.Overlap_STR.ATDCTL5STR.Bits.MULT
    #define ATDCTL5_SCAN                _ATDCTL45.Overlap_STR.ATDCTL5STR.Bits.SCAN
    #define ATDCTL5_SC                  _ATDCTL45.Overlap_STR.ATDCTL5STR.Bits.SC
    #define ATDCTL5_Cx                  _ATDCTL45.Overlap_STR.ATDCTL5STR.MergedBits.grpCx
    
    #define ATDCTL5_CA_MASK             1U
    #define ATDCTL5_CB_MASK             2U
    #define ATDCTL5_CC_MASK             4U
    #define ATDCTL5_CD_MASK             8U
    #define ATDCTL5_MULT_MASK           16U
    #define ATDCTL5_SCAN_MASK           32U
    #define ATDCTL5_SC_MASK             64U
    #define ATDCTL5_Cx_MASK             15U
    #define ATDCTL5_Cx_BITNUM           0U
    
  } Overlap_STR;

  struct {
    word CA          :1;                                       /* Analog Input Channel Select Code A */
    word CB          :1;                                       /* Analog Input Channel Select Code B */
    word CC          :1;                                       /* Analog Input Channel Select Code C */
    word CD          :1;                                       /* Analog Input Channel Select Code D */
    word MULT        :1;                                       /* Multi-Channel Sample Mode */
    word SCAN        :1;                                       /* Continuous Conversion Sequence Mode */
    word SC          :1;                                       /* Special Channel Conversion Bit */
    word             :1; 
    word PRS0        :1;                                       /* ATD Clock Prescaler 0 */
    word PRS1        :1;                                       /* ATD Clock Prescaler 1 */
    word PRS2        :1;                                       /* ATD Clock Prescaler 2 */
    word PRS3        :1;                                       /* ATD Clock Prescaler 3 */
    word PRS4        :1;                                       /* ATD Clock Prescaler 4 */
    word SMP0        :1;                                       /* Sample Time Select 0 */
    word SMP1        :1;                                       /* Sample Time Select 1 */
    word SMP2        :1;                                       /* Sample Time Select 2 */
  } Bits;
  struct {
    word grpCx   :4;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word grpPRS  :5;
    word grpSMP  :3;
  } MergedBits;
} ATDCTL45STR;
extern volatile ATDCTL45STR _ATDCTL45 @(REG_BASE + 0x00000074UL);
#define ATDCTL45                        _ATDCTL45.Word
#define ATDCTL45_CA                     _ATDCTL45.Bits.CA
#define ATDCTL45_CB                     _ATDCTL45.Bits.CB
#define ATDCTL45_CC                     _ATDCTL45.Bits.CC
#define ATDCTL45_CD                     _ATDCTL45.Bits.CD
#define ATDCTL45_MULT                   _ATDCTL45.Bits.MULT
#define ATDCTL45_SCAN                   _ATDCTL45.Bits.SCAN
#define ATDCTL45_SC                     _ATDCTL45.Bits.SC
#define ATDCTL45_PRS0                   _ATDCTL45.Bits.PRS0
#define ATDCTL45_PRS1                   _ATDCTL45.Bits.PRS1
#define ATDCTL45_PRS2                   _ATDCTL45.Bits.PRS2
#define ATDCTL45_PRS3                   _ATDCTL45.Bits.PRS3
#define ATDCTL45_PRS4                   _ATDCTL45.Bits.PRS4
#define ATDCTL45_SMP0                   _ATDCTL45.Bits.SMP0
#define ATDCTL45_SMP1                   _ATDCTL45.Bits.SMP1
#define ATDCTL45_SMP2                   _ATDCTL45.Bits.SMP2
#define ATDCTL45_Cx                     _ATDCTL45.MergedBits.grpCx
#define ATDCTL45_PRS                    _ATDCTL45.MergedBits.grpPRS
#define ATDCTL45_SMP                    _ATDCTL45.MergedBits.grpSMP

#define ATDCTL45_CA_MASK                1U
#define ATDCTL45_CB_MASK                2U
#define ATDCTL45_CC_MASK                4U
#define ATDCTL45_CD_MASK                8U
#define ATDCTL45_MULT_MASK              16U
#define ATDCTL45_SCAN_MASK              32U
#define ATDCTL45_SC_MASK                64U
#define ATDCTL45_PRS0_MASK              256U
#define ATDCTL45_PRS1_MASK              512U
#define ATDCTL45_PRS2_MASK              1024U
#define ATDCTL45_PRS3_MASK              2048U
#define ATDCTL45_PRS4_MASK              4096U
#define ATDCTL45_SMP0_MASK              8192U
#define ATDCTL45_SMP1_MASK              16384U
#define ATDCTL45_SMP2_MASK              32768U
#define ATDCTL45_Cx_MASK                15U
#define ATDCTL45_Cx_BITNUM              0U
#define ATDCTL45_PRS_MASK               7936U
#define ATDCTL45_PRS_BITNUM             8U
#define ATDCTL45_SMP_MASK               57344U
#define ATDCTL45_SMP_BITNUM             13U


/*** ATDSTAT0 - ATD  Status Register 0; 0x00000076 ***/
typedef union {
  byte Byte;
  struct {
    byte CC0         :1;                                       /* Conversion Counter 0 */
    byte CC1         :1;                                       /* Conversion Counter 1 */
    byte CC2         :1;                                       /* Conversion Counter 2 */
    byte CC3         :1;                                       /* Conversion Counter 3 */
    byte FIFOR       :1;                                       /* FIFO Over Run Flag */
    byte ETORF       :1;                                       /* External Trigger Overrun Flag */
    byte             :1; 
    byte SCF         :1;                                       /* Sequence Complete Flag */
  } Bits;
  struct {
    byte grpCC   :4;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} ATDSTAT0STR;
extern volatile ATDSTAT0STR _ATDSTAT0 @(REG_BASE + 0x00000076UL);
#define ATDSTAT0                        _ATDSTAT0.Byte
#define ATDSTAT0_CC0                    _ATDSTAT0.Bits.CC0
#define ATDSTAT0_CC1                    _ATDSTAT0.Bits.CC1
#define ATDSTAT0_CC2                    _ATDSTAT0.Bits.CC2
#define ATDSTAT0_CC3                    _ATDSTAT0.Bits.CC3
#define ATDSTAT0_FIFOR                  _ATDSTAT0.Bits.FIFOR
#define ATDSTAT0_ETORF                  _ATDSTAT0.Bits.ETORF
#define ATDSTAT0_SCF                    _ATDSTAT0.Bits.SCF
#define ATDSTAT0_CC                     _ATDSTAT0.MergedBits.grpCC

#define ATDSTAT0_CC0_MASK               1U
#define ATDSTAT0_CC1_MASK               2U
#define ATDSTAT0_CC2_MASK               4U
#define ATDSTAT0_CC3_MASK               8U
#define ATDSTAT0_FIFOR_MASK             16U
#define ATDSTAT0_ETORF_MASK             32U
#define ATDSTAT0_SCF_MASK               128U
#define ATDSTAT0_CC_MASK                15U
#define ATDSTAT0_CC_BITNUM              0U


/*** ATDCMPE - ATD  Compare Enable Register; 0x00000078 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** ATDCMPEH - ATD  Compare Enable Register High; 0x00000078 ***/
    union {
      byte Byte;
      struct {
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
      } Bits;
    } ATDCMPEHSTR;
    #define ATDCMPEH                    _ATDCMPE.Overlap_STR.ATDCMPEHSTR.Byte
    

    /*** ATDCMPEL - ATD  Compare Enable Register Low; 0x00000079 ***/
    union {
      byte Byte;
      struct {
        byte CMPE0       :1;                                       /* Compare Enable for Conversion Number 0 of a Sequence */
        byte CMPE1       :1;                                       /* Compare Enable for Conversion Number 1 of a Sequence */
        byte CMPE2       :1;                                       /* Compare Enable for Conversion Number 2 of a Sequence */
        byte CMPE3       :1;                                       /* Compare Enable for Conversion Number 3 of a Sequence */
        byte CMPE4       :1;                                       /* Compare Enable for Conversion Number 4 of a Sequence */
        byte CMPE5       :1;                                       /* Compare Enable for Conversion Number 5 of a Sequence */
        byte CMPE6       :1;                                       /* Compare Enable for Conversion Number 6 of a Sequence */
        byte CMPE7       :1;                                       /* Compare Enable for Conversion Number 7 of a Sequence */
      } Bits;
    } ATDCMPELSTR;
    #define ATDCMPEL                    _ATDCMPE.Overlap_STR.ATDCMPELSTR.Byte
    #define ATDCMPEL_CMPE0              _ATDCMPE.Overlap_STR.ATDCMPELSTR.Bits.CMPE0
    #define ATDCMPEL_CMPE1              _ATDCMPE.Overlap_STR.ATDCMPELSTR.Bits.CMPE1
    #define ATDCMPEL_CMPE2              _ATDCMPE.Overlap_STR.ATDCMPELSTR.Bits.CMPE2
    #define ATDCMPEL_CMPE3              _ATDCMPE.Overlap_STR.ATDCMPELSTR.Bits.CMPE3
    #define ATDCMPEL_CMPE4              _ATDCMPE.Overlap_STR.ATDCMPELSTR.Bits.CMPE4
    #define ATDCMPEL_CMPE5              _ATDCMPE.Overlap_STR.ATDCMPELSTR.Bits.CMPE5
    #define ATDCMPEL_CMPE6              _ATDCMPE.Overlap_STR.ATDCMPELSTR.Bits.CMPE6
    #define ATDCMPEL_CMPE7              _ATDCMPE.Overlap_STR.ATDCMPELSTR.Bits.CMPE7
    
    #define ATDCMPEL_CMPE0_MASK         1U
    #define ATDCMPEL_CMPE1_MASK         2U
    #define ATDCMPEL_CMPE2_MASK         4U
    #define ATDCMPEL_CMPE3_MASK         8U
    #define ATDCMPEL_CMPE4_MASK         16U
    #define ATDCMPEL_CMPE5_MASK         32U
    #define ATDCMPEL_CMPE6_MASK         64U
    #define ATDCMPEL_CMPE7_MASK         128U
    
  } Overlap_STR;

  struct {
    word CMPE0       :1;                                       /* Compare Enable for Conversion Number 0 of a Sequence */
    word CMPE1       :1;                                       /* Compare Enable for Conversion Number 1 of a Sequence */
    word CMPE2       :1;                                       /* Compare Enable for Conversion Number 2 of a Sequence */
    word CMPE3       :1;                                       /* Compare Enable for Conversion Number 3 of a Sequence */
    word CMPE4       :1;                                       /* Compare Enable for Conversion Number 4 of a Sequence */
    word CMPE5       :1;                                       /* Compare Enable for Conversion Number 5 of a Sequence */
    word CMPE6       :1;                                       /* Compare Enable for Conversion Number 6 of a Sequence */
    word CMPE7       :1;                                       /* Compare Enable for Conversion Number 7 of a Sequence */
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
  } Bits;
  struct {
    word grpCMPE :8;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
  } MergedBits;
} ATDCMPESTR;
extern volatile ATDCMPESTR _ATDCMPE @(REG_BASE + 0x00000078UL);
#define ATDCMPE                         _ATDCMPE.Word
#define ATDCMPE_CMPE0                   _ATDCMPE.Bits.CMPE0
#define ATDCMPE_CMPE1                   _ATDCMPE.Bits.CMPE1
#define ATDCMPE_CMPE2                   _ATDCMPE.Bits.CMPE2
#define ATDCMPE_CMPE3                   _ATDCMPE.Bits.CMPE3
#define ATDCMPE_CMPE4                   _ATDCMPE.Bits.CMPE4
#define ATDCMPE_CMPE5                   _ATDCMPE.Bits.CMPE5
#define ATDCMPE_CMPE6                   _ATDCMPE.Bits.CMPE6
#define ATDCMPE_CMPE7                   _ATDCMPE.Bits.CMPE7
#define ATDCMPE_CMPE                    _ATDCMPE.MergedBits.grpCMPE

#define ATDCMPE_CMPE0_MASK              1U
#define ATDCMPE_CMPE1_MASK              2U
#define ATDCMPE_CMPE2_MASK              4U
#define ATDCMPE_CMPE3_MASK              8U
#define ATDCMPE_CMPE4_MASK              16U
#define ATDCMPE_CMPE5_MASK              32U
#define ATDCMPE_CMPE6_MASK              64U
#define ATDCMPE_CMPE7_MASK              128U
#define ATDCMPE_CMPE_MASK               255U
#define ATDCMPE_CMPE_BITNUM             0U


/*** ATDSTAT2 - ATD  Status Register 2; 0x0000007A ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** ATDSTAT2H - ATD  Status Register 2 High; 0x0000007A ***/
    union {
      byte Byte;
      struct {
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
      } Bits;
    } ATDSTAT2HSTR;
    #define ATDSTAT2H                   _ATDSTAT2.Overlap_STR.ATDSTAT2HSTR.Byte
    

    /*** ATDSTAT2L - ATD  Status Register 2 Low; 0x0000007B ***/
    union {
      byte Byte;
      struct {
        byte CCF0        :1;                                       /* Conversion Complete Flag 0 */
        byte CCF1        :1;                                       /* Conversion Complete Flag 1 */
        byte CCF2        :1;                                       /* Conversion Complete Flag 2 */
        byte CCF3        :1;                                       /* Conversion Complete Flag 3 */
        byte CCF4        :1;                                       /* Conversion Complete Flag 4 */
        byte CCF5        :1;                                       /* Conversion Complete Flag 5 */
        byte CCF6        :1;                                       /* Conversion Complete Flag 6 */
        byte CCF7        :1;                                       /* Conversion Complete Flag 7 */
      } Bits;
    } ATDSTAT2LSTR;
    #define ATDSTAT2L                   _ATDSTAT2.Overlap_STR.ATDSTAT2LSTR.Byte
    #define ATDSTAT2L_CCF0              _ATDSTAT2.Overlap_STR.ATDSTAT2LSTR.Bits.CCF0
    #define ATDSTAT2L_CCF1              _ATDSTAT2.Overlap_STR.ATDSTAT2LSTR.Bits.CCF1
    #define ATDSTAT2L_CCF2              _ATDSTAT2.Overlap_STR.ATDSTAT2LSTR.Bits.CCF2
    #define ATDSTAT2L_CCF3              _ATDSTAT2.Overlap_STR.ATDSTAT2LSTR.Bits.CCF3
    #define ATDSTAT2L_CCF4              _ATDSTAT2.Overlap_STR.ATDSTAT2LSTR.Bits.CCF4
    #define ATDSTAT2L_CCF5              _ATDSTAT2.Overlap_STR.ATDSTAT2LSTR.Bits.CCF5
    #define ATDSTAT2L_CCF6              _ATDSTAT2.Overlap_STR.ATDSTAT2LSTR.Bits.CCF6
    #define ATDSTAT2L_CCF7              _ATDSTAT2.Overlap_STR.ATDSTAT2LSTR.Bits.CCF7
    
    #define ATDSTAT2L_CCF0_MASK         1U
    #define ATDSTAT2L_CCF1_MASK         2U
    #define ATDSTAT2L_CCF2_MASK         4U
    #define ATDSTAT2L_CCF3_MASK         8U
    #define ATDSTAT2L_CCF4_MASK         16U
    #define ATDSTAT2L_CCF5_MASK         32U
    #define ATDSTAT2L_CCF6_MASK         64U
    #define ATDSTAT2L_CCF7_MASK         128U
    
  } Overlap_STR;

  struct {
    word CCF0        :1;                                       /* Conversion Complete Flag 0 */
    word CCF1        :1;                                       /* Conversion Complete Flag 1 */
    word CCF2        :1;                                       /* Conversion Complete Flag 2 */
    word CCF3        :1;                                       /* Conversion Complete Flag 3 */
    word CCF4        :1;                                       /* Conversion Complete Flag 4 */
    word CCF5        :1;                                       /* Conversion Complete Flag 5 */
    word CCF6        :1;                                       /* Conversion Complete Flag 6 */
    word CCF7        :1;                                       /* Conversion Complete Flag 7 */
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
  } Bits;
  struct {
    word grpCCF  :8;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
  } MergedBits;
} ATDSTAT2STR;
extern volatile ATDSTAT2STR _ATDSTAT2 @(REG_BASE + 0x0000007AUL);
#define ATDSTAT2                        _ATDSTAT2.Word
#define ATDSTAT2_CCF0                   _ATDSTAT2.Bits.CCF0
#define ATDSTAT2_CCF1                   _ATDSTAT2.Bits.CCF1
#define ATDSTAT2_CCF2                   _ATDSTAT2.Bits.CCF2
#define ATDSTAT2_CCF3                   _ATDSTAT2.Bits.CCF3
#define ATDSTAT2_CCF4                   _ATDSTAT2.Bits.CCF4
#define ATDSTAT2_CCF5                   _ATDSTAT2.Bits.CCF5
#define ATDSTAT2_CCF6                   _ATDSTAT2.Bits.CCF6
#define ATDSTAT2_CCF7                   _ATDSTAT2.Bits.CCF7
#define ATDSTAT2_CCF                    _ATDSTAT2.MergedBits.grpCCF

#define ATDSTAT2_CCF0_MASK              1U
#define ATDSTAT2_CCF1_MASK              2U
#define ATDSTAT2_CCF2_MASK              4U
#define ATDSTAT2_CCF3_MASK              8U
#define ATDSTAT2_CCF4_MASK              16U
#define ATDSTAT2_CCF5_MASK              32U
#define ATDSTAT2_CCF6_MASK              64U
#define ATDSTAT2_CCF7_MASK              128U
#define ATDSTAT2_CCF_MASK               255U
#define ATDSTAT2_CCF_BITNUM             0U


/*** ATDDIEN - ATD  Input Enable Register; 0x0000007C ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** ATDDIENH - ATD  Input Enable Register High; 0x0000007C ***/
    union {
      byte Byte;
      struct {
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
      } Bits;
    } ATDDIENHSTR;
    #define ATDDIENH                    _ATDDIEN.Overlap_STR.ATDDIENHSTR.Byte
    

    /*** ATDDIENL - ATD  Input Enable Register Low; 0x0000007D ***/
    union {
      byte Byte;
      struct {
        byte IEN0        :1;                                       /* ATD Digital Input Enable on channel 0 */
        byte IEN1        :1;                                       /* ATD Digital Input Enable on channel 1 */
        byte IEN2        :1;                                       /* ATD Digital Input Enable on channel 2 */
        byte IEN3        :1;                                       /* ATD Digital Input Enable on channel 3 */
        byte IEN4        :1;                                       /* ATD Digital Input Enable on channel 4 */
        byte IEN5        :1;                                       /* ATD Digital Input Enable on channel 5 */
        byte IEN6        :1;                                       /* ATD Digital Input Enable on channel 6 */
        byte IEN7        :1;                                       /* ATD Digital Input Enable on channel 7 */
      } Bits;
    } ATDDIENLSTR;
    #define ATDDIENL                    _ATDDIEN.Overlap_STR.ATDDIENLSTR.Byte
    #define ATDDIENL_IEN0               _ATDDIEN.Overlap_STR.ATDDIENLSTR.Bits.IEN0
    #define ATDDIENL_IEN1               _ATDDIEN.Overlap_STR.ATDDIENLSTR.Bits.IEN1
    #define ATDDIENL_IEN2               _ATDDIEN.Overlap_STR.ATDDIENLSTR.Bits.IEN2
    #define ATDDIENL_IEN3               _ATDDIEN.Overlap_STR.ATDDIENLSTR.Bits.IEN3
    #define ATDDIENL_IEN4               _ATDDIEN.Overlap_STR.ATDDIENLSTR.Bits.IEN4
    #define ATDDIENL_IEN5               _ATDDIEN.Overlap_STR.ATDDIENLSTR.Bits.IEN5
    #define ATDDIENL_IEN6               _ATDDIEN.Overlap_STR.ATDDIENLSTR.Bits.IEN6
    #define ATDDIENL_IEN7               _ATDDIEN.Overlap_STR.ATDDIENLSTR.Bits.IEN7
    
    #define ATDDIENL_IEN0_MASK          1U
    #define ATDDIENL_IEN1_MASK          2U
    #define ATDDIENL_IEN2_MASK          4U
    #define ATDDIENL_IEN3_MASK          8U
    #define ATDDIENL_IEN4_MASK          16U
    #define ATDDIENL_IEN5_MASK          32U
    #define ATDDIENL_IEN6_MASK          64U
    #define ATDDIENL_IEN7_MASK          128U
    
  } Overlap_STR;

  struct {
    word IEN0        :1;                                       /* ATD Digital Input Enable on channel 0 */
    word IEN1        :1;                                       /* ATD Digital Input Enable on channel 1 */
    word IEN2        :1;                                       /* ATD Digital Input Enable on channel 2 */
    word IEN3        :1;                                       /* ATD Digital Input Enable on channel 3 */
    word IEN4        :1;                                       /* ATD Digital Input Enable on channel 4 */
    word IEN5        :1;                                       /* ATD Digital Input Enable on channel 5 */
    word IEN6        :1;                                       /* ATD Digital Input Enable on channel 6 */
    word IEN7        :1;                                       /* ATD Digital Input Enable on channel 7 */
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
  } Bits;
  struct {
    word grpIEN  :8;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
  } MergedBits;
} ATDDIENSTR;
extern volatile ATDDIENSTR _ATDDIEN @(REG_BASE + 0x0000007CUL);
#define ATDDIEN                         _ATDDIEN.Word
#define ATDDIEN_IEN0                    _ATDDIEN.Bits.IEN0
#define ATDDIEN_IEN1                    _ATDDIEN.Bits.IEN1
#define ATDDIEN_IEN2                    _ATDDIEN.Bits.IEN2
#define ATDDIEN_IEN3                    _ATDDIEN.Bits.IEN3
#define ATDDIEN_IEN4                    _ATDDIEN.Bits.IEN4
#define ATDDIEN_IEN5                    _ATDDIEN.Bits.IEN5
#define ATDDIEN_IEN6                    _ATDDIEN.Bits.IEN6
#define ATDDIEN_IEN7                    _ATDDIEN.Bits.IEN7
#define ATDDIEN_IEN                     _ATDDIEN.MergedBits.grpIEN

#define ATDDIEN_IEN0_MASK               1U
#define ATDDIEN_IEN1_MASK               2U
#define ATDDIEN_IEN2_MASK               4U
#define ATDDIEN_IEN3_MASK               8U
#define ATDDIEN_IEN4_MASK               16U
#define ATDDIEN_IEN5_MASK               32U
#define ATDDIEN_IEN6_MASK               64U
#define ATDDIEN_IEN7_MASK               128U
#define ATDDIEN_IEN_MASK                255U
#define ATDDIEN_IEN_BITNUM              0U


/*** ATDCMPHT - ATD  Compare Higher Than Register; 0x0000007E ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** ATDCMPHTH - ATD  Compare Higher Than Register High; 0x0000007E ***/
    union {
      byte Byte;
      struct {
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
      } Bits;
    } ATDCMPHTHSTR;
    #define ATDCMPHTH                   _ATDCMPHT.Overlap_STR.ATDCMPHTHSTR.Byte
    

    /*** ATDCMPHTL - ATD  Compare Higher Than Register Low; 0x0000007F ***/
    union {
      byte Byte;
      struct {
        byte CMPHT0      :1;                                       /* Compare Operation Higher Than Enable for Conversion Number 0 of a Sequence */
        byte CMPHT1      :1;                                       /* Compare Operation Higher Than Enable for Conversion Number 1 of a Sequence */
        byte CMPHT2      :1;                                       /* Compare Operation Higher Than Enable for Conversion Number 2 of a Sequence */
        byte CMPHT3      :1;                                       /* Compare Operation Higher Than Enable for Conversion Number 3 of a Sequence */
        byte CMPHT4      :1;                                       /* Compare Operation Higher Than Enable for Conversion Number 4 of a Sequence */
        byte CMPHT5      :1;                                       /* Compare Operation Higher Than Enable for Conversion Number 5 of a Sequence */
        byte CMPHT6      :1;                                       /* Compare Operation Higher Than Enable for Conversion Number 6 of a Sequence */
        byte CMPHT7      :1;                                       /* Compare Operation Higher Than Enable for Conversion Number 7 of a Sequence */
      } Bits;
    } ATDCMPHTLSTR;
    #define ATDCMPHTL                   _ATDCMPHT.Overlap_STR.ATDCMPHTLSTR.Byte
    #define ATDCMPHTL_CMPHT0            _ATDCMPHT.Overlap_STR.ATDCMPHTLSTR.Bits.CMPHT0
    #define ATDCMPHTL_CMPHT1            _ATDCMPHT.Overlap_STR.ATDCMPHTLSTR.Bits.CMPHT1
    #define ATDCMPHTL_CMPHT2            _ATDCMPHT.Overlap_STR.ATDCMPHTLSTR.Bits.CMPHT2
    #define ATDCMPHTL_CMPHT3            _ATDCMPHT.Overlap_STR.ATDCMPHTLSTR.Bits.CMPHT3
    #define ATDCMPHTL_CMPHT4            _ATDCMPHT.Overlap_STR.ATDCMPHTLSTR.Bits.CMPHT4
    #define ATDCMPHTL_CMPHT5            _ATDCMPHT.Overlap_STR.ATDCMPHTLSTR.Bits.CMPHT5
    #define ATDCMPHTL_CMPHT6            _ATDCMPHT.Overlap_STR.ATDCMPHTLSTR.Bits.CMPHT6
    #define ATDCMPHTL_CMPHT7            _ATDCMPHT.Overlap_STR.ATDCMPHTLSTR.Bits.CMPHT7
    
    #define ATDCMPHTL_CMPHT0_MASK       1U
    #define ATDCMPHTL_CMPHT1_MASK       2U
    #define ATDCMPHTL_CMPHT2_MASK       4U
    #define ATDCMPHTL_CMPHT3_MASK       8U
    #define ATDCMPHTL_CMPHT4_MASK       16U
    #define ATDCMPHTL_CMPHT5_MASK       32U
    #define ATDCMPHTL_CMPHT6_MASK       64U
    #define ATDCMPHTL_CMPHT7_MASK       128U
    
  } Overlap_STR;

  struct {
    word CMPHT0      :1;                                       /* Compare Operation Higher Than Enable for Conversion Number 0 of a Sequence */
    word CMPHT1      :1;                                       /* Compare Operation Higher Than Enable for Conversion Number 1 of a Sequence */
    word CMPHT2      :1;                                       /* Compare Operation Higher Than Enable for Conversion Number 2 of a Sequence */
    word CMPHT3      :1;                                       /* Compare Operation Higher Than Enable for Conversion Number 3 of a Sequence */
    word CMPHT4      :1;                                       /* Compare Operation Higher Than Enable for Conversion Number 4 of a Sequence */
    word CMPHT5      :1;                                       /* Compare Operation Higher Than Enable for Conversion Number 5 of a Sequence */
    word CMPHT6      :1;                                       /* Compare Operation Higher Than Enable for Conversion Number 6 of a Sequence */
    word CMPHT7      :1;                                       /* Compare Operation Higher Than Enable for Conversion Number 7 of a Sequence */
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
  } Bits;
  struct {
    word grpCMPHT :8;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
  } MergedBits;
} ATDCMPHTSTR;
extern volatile ATDCMPHTSTR _ATDCMPHT @(REG_BASE + 0x0000007EUL);
#define ATDCMPHT                        _ATDCMPHT.Word
#define ATDCMPHT_CMPHT0                 _ATDCMPHT.Bits.CMPHT0
#define ATDCMPHT_CMPHT1                 _ATDCMPHT.Bits.CMPHT1
#define ATDCMPHT_CMPHT2                 _ATDCMPHT.Bits.CMPHT2
#define ATDCMPHT_CMPHT3                 _ATDCMPHT.Bits.CMPHT3
#define ATDCMPHT_CMPHT4                 _ATDCMPHT.Bits.CMPHT4
#define ATDCMPHT_CMPHT5                 _ATDCMPHT.Bits.CMPHT5
#define ATDCMPHT_CMPHT6                 _ATDCMPHT.Bits.CMPHT6
#define ATDCMPHT_CMPHT7                 _ATDCMPHT.Bits.CMPHT7
#define ATDCMPHT_CMPHT                  _ATDCMPHT.MergedBits.grpCMPHT

#define ATDCMPHT_CMPHT0_MASK            1U
#define ATDCMPHT_CMPHT1_MASK            2U
#define ATDCMPHT_CMPHT2_MASK            4U
#define ATDCMPHT_CMPHT3_MASK            8U
#define ATDCMPHT_CMPHT4_MASK            16U
#define ATDCMPHT_CMPHT5_MASK            32U
#define ATDCMPHT_CMPHT6_MASK            64U
#define ATDCMPHT_CMPHT7_MASK            128U
#define ATDCMPHT_CMPHT_MASK             255U
#define ATDCMPHT_CMPHT_BITNUM           0U


/*** ATDDR0 - ATD  Conversion Result Register 0; 0x00000080 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** ATDDR0H - ATD  Conversion Result Register 0 High; 0x00000080 ***/
    union {
      byte Byte;
      struct {
        byte BIT8        :1;                                       /* Bit 8 */
        byte BIT9        :1;                                       /* Bit 9 */
        byte BIT10       :1;                                       /* Bit 10 */
        byte BIT11       :1;                                       /* Bit 11 */
        byte BIT12       :1;                                       /* Bit 12 */
        byte BIT13       :1;                                       /* Bit 13 */
        byte BIT14       :1;                                       /* Bit 14 */
        byte BIT15       :1;                                       /* Bit 15 */
      } Bits;
    } ATDDR0HSTR;
    #define ATDDR0H                     _ATDDR0.Overlap_STR.ATDDR0HSTR.Byte
    #define ATDDR0H_BIT8                _ATDDR0.Overlap_STR.ATDDR0HSTR.Bits.BIT8
    #define ATDDR0H_BIT9                _ATDDR0.Overlap_STR.ATDDR0HSTR.Bits.BIT9
    #define ATDDR0H_BIT10               _ATDDR0.Overlap_STR.ATDDR0HSTR.Bits.BIT10
    #define ATDDR0H_BIT11               _ATDDR0.Overlap_STR.ATDDR0HSTR.Bits.BIT11
    #define ATDDR0H_BIT12               _ATDDR0.Overlap_STR.ATDDR0HSTR.Bits.BIT12
    #define ATDDR0H_BIT13               _ATDDR0.Overlap_STR.ATDDR0HSTR.Bits.BIT13
    #define ATDDR0H_BIT14               _ATDDR0.Overlap_STR.ATDDR0HSTR.Bits.BIT14
    #define ATDDR0H_BIT15               _ATDDR0.Overlap_STR.ATDDR0HSTR.Bits.BIT15
    
    #define ATDDR0H_BIT8_MASK           1U
    #define ATDDR0H_BIT9_MASK           2U
    #define ATDDR0H_BIT10_MASK          4U
    #define ATDDR0H_BIT11_MASK          8U
    #define ATDDR0H_BIT12_MASK          16U
    #define ATDDR0H_BIT13_MASK          32U
    #define ATDDR0H_BIT14_MASK          64U
    #define ATDDR0H_BIT15_MASK          128U
    

    /*** ATDDR0L - ATD  Conversion Result Register 0 Low; 0x00000081 ***/
    union {
      byte Byte;
      struct {
        byte BIT0        :1;                                       /* Bit 0 */
        byte BIT1        :1;                                       /* Bit 1 */
        byte BIT2        :1;                                       /* Bit 2 */
        byte BIT3        :1;                                       /* Bit 3 */
        byte BIT4        :1;                                       /* Bit 4 */
        byte BIT5        :1;                                       /* Bit 5 */
        byte BIT6        :1;                                       /* Bit 6 */
        byte BIT7        :1;                                       /* Bit 7 */
      } Bits;
    } ATDDR0LSTR;
    #define ATDDR0L                     _ATDDR0.Overlap_STR.ATDDR0LSTR.Byte
    #define ATDDR0L_BIT0                _ATDDR0.Overlap_STR.ATDDR0LSTR.Bits.BIT0
    #define ATDDR0L_BIT1                _ATDDR0.Overlap_STR.ATDDR0LSTR.Bits.BIT1
    #define ATDDR0L_BIT2                _ATDDR0.Overlap_STR.ATDDR0LSTR.Bits.BIT2
    #define ATDDR0L_BIT3                _ATDDR0.Overlap_STR.ATDDR0LSTR.Bits.BIT3
    #define ATDDR0L_BIT4                _ATDDR0.Overlap_STR.ATDDR0LSTR.Bits.BIT4
    #define ATDDR0L_BIT5                _ATDDR0.Overlap_STR.ATDDR0LSTR.Bits.BIT5
    #define ATDDR0L_BIT6                _ATDDR0.Overlap_STR.ATDDR0LSTR.Bits.BIT6
    #define ATDDR0L_BIT7                _ATDDR0.Overlap_STR.ATDDR0LSTR.Bits.BIT7
    
    #define ATDDR0L_BIT0_MASK           1U
    #define ATDDR0L_BIT1_MASK           2U
    #define ATDDR0L_BIT2_MASK           4U
    #define ATDDR0L_BIT3_MASK           8U
    #define ATDDR0L_BIT4_MASK           16U
    #define ATDDR0L_BIT5_MASK           32U
    #define ATDDR0L_BIT6_MASK           64U
    #define ATDDR0L_BIT7_MASK           128U
    
  } Overlap_STR;

  struct {
    word BIT0        :1;                                       /* Bit 0 */
    word BIT1        :1;                                       /* Bit 1 */
    word BIT2        :1;                                       /* Bit 2 */
    word BIT3        :1;                                       /* Bit 3 */
    word BIT4        :1;                                       /* Bit 4 */
    word BIT5        :1;                                       /* Bit 5 */
    word BIT6        :1;                                       /* Bit 6 */
    word BIT7        :1;                                       /* Bit 7 */
    word BIT8        :1;                                       /* Bit 8 */
    word BIT9        :1;                                       /* Bit 9 */
    word BIT10       :1;                                       /* Bit 10 */
    word BIT11       :1;                                       /* Bit 11 */
    word BIT12       :1;                                       /* Bit 12 */
    word BIT13       :1;                                       /* Bit 13 */
    word BIT14       :1;                                       /* Bit 14 */
    word BIT15       :1;                                       /* Bit 15 */
  } Bits;
} ATDDR0STR;
extern volatile ATDDR0STR _ATDDR0 @(REG_BASE + 0x00000080UL);
#define ATDDR0                          _ATDDR0.Word
#define ATDDR0_BIT0                     _ATDDR0.Bits.BIT0
#define ATDDR0_BIT1                     _ATDDR0.Bits.BIT1
#define ATDDR0_BIT2                     _ATDDR0.Bits.BIT2
#define ATDDR0_BIT3                     _ATDDR0.Bits.BIT3
#define ATDDR0_BIT4                     _ATDDR0.Bits.BIT4
#define ATDDR0_BIT5                     _ATDDR0.Bits.BIT5
#define ATDDR0_BIT6                     _ATDDR0.Bits.BIT6
#define ATDDR0_BIT7                     _ATDDR0.Bits.BIT7
#define ATDDR0_BIT8                     _ATDDR0.Bits.BIT8
#define ATDDR0_BIT9                     _ATDDR0.Bits.BIT9
#define ATDDR0_BIT10                    _ATDDR0.Bits.BIT10
#define ATDDR0_BIT11                    _ATDDR0.Bits.BIT11
#define ATDDR0_BIT12                    _ATDDR0.Bits.BIT12
#define ATDDR0_BIT13                    _ATDDR0.Bits.BIT13
#define ATDDR0_BIT14                    _ATDDR0.Bits.BIT14
#define ATDDR0_BIT15                    _ATDDR0.Bits.BIT15
/* ATDDR_ARR: Access 8 ATDDRx registers in an array */
#define ATDDR_ARR                       ((volatile word *) &ATDDR0)

#define ATDDR0_BIT0_MASK                1U
#define ATDDR0_BIT1_MASK                2U
#define ATDDR0_BIT2_MASK                4U
#define ATDDR0_BIT3_MASK                8U
#define ATDDR0_BIT4_MASK                16U
#define ATDDR0_BIT5_MASK                32U
#define ATDDR0_BIT6_MASK                64U
#define ATDDR0_BIT7_MASK                128U
#define ATDDR0_BIT8_MASK                256U
#define ATDDR0_BIT9_MASK                512U
#define ATDDR0_BIT10_MASK               1024U
#define ATDDR0_BIT11_MASK               2048U
#define ATDDR0_BIT12_MASK               4096U
#define ATDDR0_BIT13_MASK               8192U
#define ATDDR0_BIT14_MASK               16384U
#define ATDDR0_BIT15_MASK               32768U


/*** ATDDR1 - ATD  Conversion Result Register 1; 0x00000082 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** ATDDR1H - ATD  Conversion Result Register 1 High; 0x00000082 ***/
    union {
      byte Byte;
      struct {
        byte BIT8        :1;                                       /* Bit 8 */
        byte BIT9        :1;                                       /* Bit 9 */
        byte BIT10       :1;                                       /* Bit 10 */
        byte BIT11       :1;                                       /* Bit 11 */
        byte BIT12       :1;                                       /* Bit 12 */
        byte BIT13       :1;                                       /* Bit 13 */
        byte BIT14       :1;                                       /* Bit 14 */
        byte BIT15       :1;                                       /* Bit 15 */
      } Bits;
    } ATDDR1HSTR;
    #define ATDDR1H                     _ATDDR1.Overlap_STR.ATDDR1HSTR.Byte
    #define ATDDR1H_BIT8                _ATDDR1.Overlap_STR.ATDDR1HSTR.Bits.BIT8
    #define ATDDR1H_BIT9                _ATDDR1.Overlap_STR.ATDDR1HSTR.Bits.BIT9
    #define ATDDR1H_BIT10               _ATDDR1.Overlap_STR.ATDDR1HSTR.Bits.BIT10
    #define ATDDR1H_BIT11               _ATDDR1.Overlap_STR.ATDDR1HSTR.Bits.BIT11
    #define ATDDR1H_BIT12               _ATDDR1.Overlap_STR.ATDDR1HSTR.Bits.BIT12
    #define ATDDR1H_BIT13               _ATDDR1.Overlap_STR.ATDDR1HSTR.Bits.BIT13
    #define ATDDR1H_BIT14               _ATDDR1.Overlap_STR.ATDDR1HSTR.Bits.BIT14
    #define ATDDR1H_BIT15               _ATDDR1.Overlap_STR.ATDDR1HSTR.Bits.BIT15
    
    #define ATDDR1H_BIT8_MASK           1U
    #define ATDDR1H_BIT9_MASK           2U
    #define ATDDR1H_BIT10_MASK          4U
    #define ATDDR1H_BIT11_MASK          8U
    #define ATDDR1H_BIT12_MASK          16U
    #define ATDDR1H_BIT13_MASK          32U
    #define ATDDR1H_BIT14_MASK          64U
    #define ATDDR1H_BIT15_MASK          128U
    

    /*** ATDDR1L - ATD  Conversion Result Register 1 Low; 0x00000083 ***/
    union {
      byte Byte;
      struct {
        byte BIT0        :1;                                       /* Bit 0 */
        byte BIT1        :1;                                       /* Bit 1 */
        byte BIT2        :1;                                       /* Bit 2 */
        byte BIT3        :1;                                       /* Bit 3 */
        byte BIT4        :1;                                       /* Bit 4 */
        byte BIT5        :1;                                       /* Bit 5 */
        byte BIT6        :1;                                       /* Bit 6 */
        byte BIT7        :1;                                       /* Bit 7 */
      } Bits;
    } ATDDR1LSTR;
    #define ATDDR1L                     _ATDDR1.Overlap_STR.ATDDR1LSTR.Byte
    #define ATDDR1L_BIT0                _ATDDR1.Overlap_STR.ATDDR1LSTR.Bits.BIT0
    #define ATDDR1L_BIT1                _ATDDR1.Overlap_STR.ATDDR1LSTR.Bits.BIT1
    #define ATDDR1L_BIT2                _ATDDR1.Overlap_STR.ATDDR1LSTR.Bits.BIT2
    #define ATDDR1L_BIT3                _ATDDR1.Overlap_STR.ATDDR1LSTR.Bits.BIT3
    #define ATDDR1L_BIT4                _ATDDR1.Overlap_STR.ATDDR1LSTR.Bits.BIT4
    #define ATDDR1L_BIT5                _ATDDR1.Overlap_STR.ATDDR1LSTR.Bits.BIT5
    #define ATDDR1L_BIT6                _ATDDR1.Overlap_STR.ATDDR1LSTR.Bits.BIT6
    #define ATDDR1L_BIT7                _ATDDR1.Overlap_STR.ATDDR1LSTR.Bits.BIT7
    
    #define ATDDR1L_BIT0_MASK           1U
    #define ATDDR1L_BIT1_MASK           2U
    #define ATDDR1L_BIT2_MASK           4U
    #define ATDDR1L_BIT3_MASK           8U
    #define ATDDR1L_BIT4_MASK           16U
    #define ATDDR1L_BIT5_MASK           32U
    #define ATDDR1L_BIT6_MASK           64U
    #define ATDDR1L_BIT7_MASK           128U
    
  } Overlap_STR;

  struct {
    word BIT0        :1;                                       /* Bit 0 */
    word BIT1        :1;                                       /* Bit 1 */
    word BIT2        :1;                                       /* Bit 2 */
    word BIT3        :1;                                       /* Bit 3 */
    word BIT4        :1;                                       /* Bit 4 */
    word BIT5        :1;                                       /* Bit 5 */
    word BIT6        :1;                                       /* Bit 6 */
    word BIT7        :1;                                       /* Bit 7 */
    word BIT8        :1;                                       /* Bit 8 */
    word BIT9        :1;                                       /* Bit 9 */
    word BIT10       :1;                                       /* Bit 10 */
    word BIT11       :1;                                       /* Bit 11 */
    word BIT12       :1;                                       /* Bit 12 */
    word BIT13       :1;                                       /* Bit 13 */
    word BIT14       :1;                                       /* Bit 14 */
    word BIT15       :1;                                       /* Bit 15 */
  } Bits;
} ATDDR1STR;
extern volatile ATDDR1STR _ATDDR1 @(REG_BASE + 0x00000082UL);
#define ATDDR1                          _ATDDR1.Word
#define ATDDR1_BIT0                     _ATDDR1.Bits.BIT0
#define ATDDR1_BIT1                     _ATDDR1.Bits.BIT1
#define ATDDR1_BIT2                     _ATDDR1.Bits.BIT2
#define ATDDR1_BIT3                     _ATDDR1.Bits.BIT3
#define ATDDR1_BIT4                     _ATDDR1.Bits.BIT4
#define ATDDR1_BIT5                     _ATDDR1.Bits.BIT5
#define ATDDR1_BIT6                     _ATDDR1.Bits.BIT6
#define ATDDR1_BIT7                     _ATDDR1.Bits.BIT7
#define ATDDR1_BIT8                     _ATDDR1.Bits.BIT8
#define ATDDR1_BIT9                     _ATDDR1.Bits.BIT9
#define ATDDR1_BIT10                    _ATDDR1.Bits.BIT10
#define ATDDR1_BIT11                    _ATDDR1.Bits.BIT11
#define ATDDR1_BIT12                    _ATDDR1.Bits.BIT12
#define ATDDR1_BIT13                    _ATDDR1.Bits.BIT13
#define ATDDR1_BIT14                    _ATDDR1.Bits.BIT14
#define ATDDR1_BIT15                    _ATDDR1.Bits.BIT15

#define ATDDR1_BIT0_MASK                1U
#define ATDDR1_BIT1_MASK                2U
#define ATDDR1_BIT2_MASK                4U
#define ATDDR1_BIT3_MASK                8U
#define ATDDR1_BIT4_MASK                16U
#define ATDDR1_BIT5_MASK                32U
#define ATDDR1_BIT6_MASK                64U
#define ATDDR1_BIT7_MASK                128U
#define ATDDR1_BIT8_MASK                256U
#define ATDDR1_BIT9_MASK                512U
#define ATDDR1_BIT10_MASK               1024U
#define ATDDR1_BIT11_MASK               2048U
#define ATDDR1_BIT12_MASK               4096U
#define ATDDR1_BIT13_MASK               8192U
#define ATDDR1_BIT14_MASK               16384U
#define ATDDR1_BIT15_MASK               32768U


/*** ATDDR2 - ATD  Conversion Result Register 2; 0x00000084 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** ATDDR2H - ATD  Conversion Result Register 2 High; 0x00000084 ***/
    union {
      byte Byte;
      struct {
        byte BIT8        :1;                                       /* Bit 8 */
        byte BIT9        :1;                                       /* Bit 9 */
        byte BIT10       :1;                                       /* Bit 10 */
        byte BIT11       :1;                                       /* Bit 11 */
        byte BIT12       :1;                                       /* Bit 12 */
        byte BIT13       :1;                                       /* Bit 13 */
        byte BIT14       :1;                                       /* Bit 14 */
        byte BIT15       :1;                                       /* Bit 15 */
      } Bits;
    } ATDDR2HSTR;
    #define ATDDR2H                     _ATDDR2.Overlap_STR.ATDDR2HSTR.Byte
    #define ATDDR2H_BIT8                _ATDDR2.Overlap_STR.ATDDR2HSTR.Bits.BIT8
    #define ATDDR2H_BIT9                _ATDDR2.Overlap_STR.ATDDR2HSTR.Bits.BIT9
    #define ATDDR2H_BIT10               _ATDDR2.Overlap_STR.ATDDR2HSTR.Bits.BIT10
    #define ATDDR2H_BIT11               _ATDDR2.Overlap_STR.ATDDR2HSTR.Bits.BIT11
    #define ATDDR2H_BIT12               _ATDDR2.Overlap_STR.ATDDR2HSTR.Bits.BIT12
    #define ATDDR2H_BIT13               _ATDDR2.Overlap_STR.ATDDR2HSTR.Bits.BIT13
    #define ATDDR2H_BIT14               _ATDDR2.Overlap_STR.ATDDR2HSTR.Bits.BIT14
    #define ATDDR2H_BIT15               _ATDDR2.Overlap_STR.ATDDR2HSTR.Bits.BIT15
    
    #define ATDDR2H_BIT8_MASK           1U
    #define ATDDR2H_BIT9_MASK           2U
    #define ATDDR2H_BIT10_MASK          4U
    #define ATDDR2H_BIT11_MASK          8U
    #define ATDDR2H_BIT12_MASK          16U
    #define ATDDR2H_BIT13_MASK          32U
    #define ATDDR2H_BIT14_MASK          64U
    #define ATDDR2H_BIT15_MASK          128U
    

    /*** ATDDR2L - ATD  Conversion Result Register 2 Low; 0x00000085 ***/
    union {
      byte Byte;
      struct {
        byte BIT0        :1;                                       /* Bit 0 */
        byte BIT1        :1;                                       /* Bit 1 */
        byte BIT2        :1;                                       /* Bit 2 */
        byte BIT3        :1;                                       /* Bit 3 */
        byte BIT4        :1;                                       /* Bit 4 */
        byte BIT5        :1;                                       /* Bit 5 */
        byte BIT6        :1;                                       /* Bit 6 */
        byte BIT7        :1;                                       /* Bit 7 */
      } Bits;
    } ATDDR2LSTR;
    #define ATDDR2L                     _ATDDR2.Overlap_STR.ATDDR2LSTR.Byte
    #define ATDDR2L_BIT0                _ATDDR2.Overlap_STR.ATDDR2LSTR.Bits.BIT0
    #define ATDDR2L_BIT1                _ATDDR2.Overlap_STR.ATDDR2LSTR.Bits.BIT1
    #define ATDDR2L_BIT2                _ATDDR2.Overlap_STR.ATDDR2LSTR.Bits.BIT2
    #define ATDDR2L_BIT3                _ATDDR2.Overlap_STR.ATDDR2LSTR.Bits.BIT3
    #define ATDDR2L_BIT4                _ATDDR2.Overlap_STR.ATDDR2LSTR.Bits.BIT4
    #define ATDDR2L_BIT5                _ATDDR2.Overlap_STR.ATDDR2LSTR.Bits.BIT5
    #define ATDDR2L_BIT6                _ATDDR2.Overlap_STR.ATDDR2LSTR.Bits.BIT6
    #define ATDDR2L_BIT7                _ATDDR2.Overlap_STR.ATDDR2LSTR.Bits.BIT7
    
    #define ATDDR2L_BIT0_MASK           1U
    #define ATDDR2L_BIT1_MASK           2U
    #define ATDDR2L_BIT2_MASK           4U
    #define ATDDR2L_BIT3_MASK           8U
    #define ATDDR2L_BIT4_MASK           16U
    #define ATDDR2L_BIT5_MASK           32U
    #define ATDDR2L_BIT6_MASK           64U
    #define ATDDR2L_BIT7_MASK           128U
    
  } Overlap_STR;

  struct {
    word BIT0        :1;                                       /* Bit 0 */
    word BIT1        :1;                                       /* Bit 1 */
    word BIT2        :1;                                       /* Bit 2 */
    word BIT3        :1;                                       /* Bit 3 */
    word BIT4        :1;                                       /* Bit 4 */
    word BIT5        :1;                                       /* Bit 5 */
    word BIT6        :1;                                       /* Bit 6 */
    word BIT7        :1;                                       /* Bit 7 */
    word BIT8        :1;                                       /* Bit 8 */
    word BIT9        :1;                                       /* Bit 9 */
    word BIT10       :1;                                       /* Bit 10 */
    word BIT11       :1;                                       /* Bit 11 */
    word BIT12       :1;                                       /* Bit 12 */
    word BIT13       :1;                                       /* Bit 13 */
    word BIT14       :1;                                       /* Bit 14 */
    word BIT15       :1;                                       /* Bit 15 */
  } Bits;
} ATDDR2STR;
extern volatile ATDDR2STR _ATDDR2 @(REG_BASE + 0x00000084UL);
#define ATDDR2                          _ATDDR2.Word
#define ATDDR2_BIT0                     _ATDDR2.Bits.BIT0
#define ATDDR2_BIT1                     _ATDDR2.Bits.BIT1
#define ATDDR2_BIT2                     _ATDDR2.Bits.BIT2
#define ATDDR2_BIT3                     _ATDDR2.Bits.BIT3
#define ATDDR2_BIT4                     _ATDDR2.Bits.BIT4
#define ATDDR2_BIT5                     _ATDDR2.Bits.BIT5
#define ATDDR2_BIT6                     _ATDDR2.Bits.BIT6
#define ATDDR2_BIT7                     _ATDDR2.Bits.BIT7
#define ATDDR2_BIT8                     _ATDDR2.Bits.BIT8
#define ATDDR2_BIT9                     _ATDDR2.Bits.BIT9
#define ATDDR2_BIT10                    _ATDDR2.Bits.BIT10
#define ATDDR2_BIT11                    _ATDDR2.Bits.BIT11
#define ATDDR2_BIT12                    _ATDDR2.Bits.BIT12
#define ATDDR2_BIT13                    _ATDDR2.Bits.BIT13
#define ATDDR2_BIT14                    _ATDDR2.Bits.BIT14
#define ATDDR2_BIT15                    _ATDDR2.Bits.BIT15

#define ATDDR2_BIT0_MASK                1U
#define ATDDR2_BIT1_MASK                2U
#define ATDDR2_BIT2_MASK                4U
#define ATDDR2_BIT3_MASK                8U
#define ATDDR2_BIT4_MASK                16U
#define ATDDR2_BIT5_MASK                32U
#define ATDDR2_BIT6_MASK                64U
#define ATDDR2_BIT7_MASK                128U
#define ATDDR2_BIT8_MASK                256U
#define ATDDR2_BIT9_MASK                512U
#define ATDDR2_BIT10_MASK               1024U
#define ATDDR2_BIT11_MASK               2048U
#define ATDDR2_BIT12_MASK               4096U
#define ATDDR2_BIT13_MASK               8192U
#define ATDDR2_BIT14_MASK               16384U
#define ATDDR2_BIT15_MASK               32768U


/*** ATDDR3 - ATD  Conversion Result Register 3; 0x00000086 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** ATDDR3H - ATD  Conversion Result Register 3 High; 0x00000086 ***/
    union {
      byte Byte;
      struct {
        byte BIT8        :1;                                       /* Bit 8 */
        byte BIT9        :1;                                       /* Bit 9 */
        byte BIT10       :1;                                       /* Bit 10 */
        byte BIT11       :1;                                       /* Bit 11 */
        byte BIT12       :1;                                       /* Bit 12 */
        byte BIT13       :1;                                       /* Bit 13 */
        byte BIT14       :1;                                       /* Bit 14 */
        byte BIT15       :1;                                       /* Bit 15 */
      } Bits;
    } ATDDR3HSTR;
    #define ATDDR3H                     _ATDDR3.Overlap_STR.ATDDR3HSTR.Byte
    #define ATDDR3H_BIT8                _ATDDR3.Overlap_STR.ATDDR3HSTR.Bits.BIT8
    #define ATDDR3H_BIT9                _ATDDR3.Overlap_STR.ATDDR3HSTR.Bits.BIT9
    #define ATDDR3H_BIT10               _ATDDR3.Overlap_STR.ATDDR3HSTR.Bits.BIT10
    #define ATDDR3H_BIT11               _ATDDR3.Overlap_STR.ATDDR3HSTR.Bits.BIT11
    #define ATDDR3H_BIT12               _ATDDR3.Overlap_STR.ATDDR3HSTR.Bits.BIT12
    #define ATDDR3H_BIT13               _ATDDR3.Overlap_STR.ATDDR3HSTR.Bits.BIT13
    #define ATDDR3H_BIT14               _ATDDR3.Overlap_STR.ATDDR3HSTR.Bits.BIT14
    #define ATDDR3H_BIT15               _ATDDR3.Overlap_STR.ATDDR3HSTR.Bits.BIT15
    
    #define ATDDR3H_BIT8_MASK           1U
    #define ATDDR3H_BIT9_MASK           2U
    #define ATDDR3H_BIT10_MASK          4U
    #define ATDDR3H_BIT11_MASK          8U
    #define ATDDR3H_BIT12_MASK          16U
    #define ATDDR3H_BIT13_MASK          32U
    #define ATDDR3H_BIT14_MASK          64U
    #define ATDDR3H_BIT15_MASK          128U
    

    /*** ATDDR3L - ATD  Conversion Result Register 3 Low; 0x00000087 ***/
    union {
      byte Byte;
      struct {
        byte BIT0        :1;                                       /* Bit 0 */
        byte BIT1        :1;                                       /* Bit 1 */
        byte BIT2        :1;                                       /* Bit 2 */
        byte BIT3        :1;                                       /* Bit 3 */
        byte BIT4        :1;                                       /* Bit 4 */
        byte BIT5        :1;                                       /* Bit 5 */
        byte BIT6        :1;                                       /* Bit 6 */
        byte BIT7        :1;                                       /* Bit 7 */
      } Bits;
    } ATDDR3LSTR;
    #define ATDDR3L                     _ATDDR3.Overlap_STR.ATDDR3LSTR.Byte
    #define ATDDR3L_BIT0                _ATDDR3.Overlap_STR.ATDDR3LSTR.Bits.BIT0
    #define ATDDR3L_BIT1                _ATDDR3.Overlap_STR.ATDDR3LSTR.Bits.BIT1
    #define ATDDR3L_BIT2                _ATDDR3.Overlap_STR.ATDDR3LSTR.Bits.BIT2
    #define ATDDR3L_BIT3                _ATDDR3.Overlap_STR.ATDDR3LSTR.Bits.BIT3
    #define ATDDR3L_BIT4                _ATDDR3.Overlap_STR.ATDDR3LSTR.Bits.BIT4
    #define ATDDR3L_BIT5                _ATDDR3.Overlap_STR.ATDDR3LSTR.Bits.BIT5
    #define ATDDR3L_BIT6                _ATDDR3.Overlap_STR.ATDDR3LSTR.Bits.BIT6
    #define ATDDR3L_BIT7                _ATDDR3.Overlap_STR.ATDDR3LSTR.Bits.BIT7
    
    #define ATDDR3L_BIT0_MASK           1U
    #define ATDDR3L_BIT1_MASK           2U
    #define ATDDR3L_BIT2_MASK           4U
    #define ATDDR3L_BIT3_MASK           8U
    #define ATDDR3L_BIT4_MASK           16U
    #define ATDDR3L_BIT5_MASK           32U
    #define ATDDR3L_BIT6_MASK           64U
    #define ATDDR3L_BIT7_MASK           128U
    
  } Overlap_STR;

  struct {
    word BIT0        :1;                                       /* Bit 0 */
    word BIT1        :1;                                       /* Bit 1 */
    word BIT2        :1;                                       /* Bit 2 */
    word BIT3        :1;                                       /* Bit 3 */
    word BIT4        :1;                                       /* Bit 4 */
    word BIT5        :1;                                       /* Bit 5 */
    word BIT6        :1;                                       /* Bit 6 */
    word BIT7        :1;                                       /* Bit 7 */
    word BIT8        :1;                                       /* Bit 8 */
    word BIT9        :1;                                       /* Bit 9 */
    word BIT10       :1;                                       /* Bit 10 */
    word BIT11       :1;                                       /* Bit 11 */
    word BIT12       :1;                                       /* Bit 12 */
    word BIT13       :1;                                       /* Bit 13 */
    word BIT14       :1;                                       /* Bit 14 */
    word BIT15       :1;                                       /* Bit 15 */
  } Bits;
} ATDDR3STR;
extern volatile ATDDR3STR _ATDDR3 @(REG_BASE + 0x00000086UL);
#define ATDDR3                          _ATDDR3.Word
#define ATDDR3_BIT0                     _ATDDR3.Bits.BIT0
#define ATDDR3_BIT1                     _ATDDR3.Bits.BIT1
#define ATDDR3_BIT2                     _ATDDR3.Bits.BIT2
#define ATDDR3_BIT3                     _ATDDR3.Bits.BIT3
#define ATDDR3_BIT4                     _ATDDR3.Bits.BIT4
#define ATDDR3_BIT5                     _ATDDR3.Bits.BIT5
#define ATDDR3_BIT6                     _ATDDR3.Bits.BIT6
#define ATDDR3_BIT7                     _ATDDR3.Bits.BIT7
#define ATDDR3_BIT8                     _ATDDR3.Bits.BIT8
#define ATDDR3_BIT9                     _ATDDR3.Bits.BIT9
#define ATDDR3_BIT10                    _ATDDR3.Bits.BIT10
#define ATDDR3_BIT11                    _ATDDR3.Bits.BIT11
#define ATDDR3_BIT12                    _ATDDR3.Bits.BIT12
#define ATDDR3_BIT13                    _ATDDR3.Bits.BIT13
#define ATDDR3_BIT14                    _ATDDR3.Bits.BIT14
#define ATDDR3_BIT15                    _ATDDR3.Bits.BIT15

#define ATDDR3_BIT0_MASK                1U
#define ATDDR3_BIT1_MASK                2U
#define ATDDR3_BIT2_MASK                4U
#define ATDDR3_BIT3_MASK                8U
#define ATDDR3_BIT4_MASK                16U
#define ATDDR3_BIT5_MASK                32U
#define ATDDR3_BIT6_MASK                64U
#define ATDDR3_BIT7_MASK                128U
#define ATDDR3_BIT8_MASK                256U
#define ATDDR3_BIT9_MASK                512U
#define ATDDR3_BIT10_MASK               1024U
#define ATDDR3_BIT11_MASK               2048U
#define ATDDR3_BIT12_MASK               4096U
#define ATDDR3_BIT13_MASK               8192U
#define ATDDR3_BIT14_MASK               16384U
#define ATDDR3_BIT15_MASK               32768U


/*** ATDDR4 - ATD  Conversion Result Register 4; 0x00000088 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** ATDDR4H - ATD  Conversion Result Register 4 High; 0x00000088 ***/
    union {
      byte Byte;
      struct {
        byte BIT8        :1;                                       /* Bit 8 */
        byte BIT9        :1;                                       /* Bit 9 */
        byte BIT10       :1;                                       /* Bit 10 */
        byte BIT11       :1;                                       /* Bit 11 */
        byte BIT12       :1;                                       /* Bit 12 */
        byte BIT13       :1;                                       /* Bit 13 */
        byte BIT14       :1;                                       /* Bit 14 */
        byte BIT15       :1;                                       /* Bit 15 */
      } Bits;
    } ATDDR4HSTR;
    #define ATDDR4H                     _ATDDR4.Overlap_STR.ATDDR4HSTR.Byte
    #define ATDDR4H_BIT8                _ATDDR4.Overlap_STR.ATDDR4HSTR.Bits.BIT8
    #define ATDDR4H_BIT9                _ATDDR4.Overlap_STR.ATDDR4HSTR.Bits.BIT9
    #define ATDDR4H_BIT10               _ATDDR4.Overlap_STR.ATDDR4HSTR.Bits.BIT10
    #define ATDDR4H_BIT11               _ATDDR4.Overlap_STR.ATDDR4HSTR.Bits.BIT11
    #define ATDDR4H_BIT12               _ATDDR4.Overlap_STR.ATDDR4HSTR.Bits.BIT12
    #define ATDDR4H_BIT13               _ATDDR4.Overlap_STR.ATDDR4HSTR.Bits.BIT13
    #define ATDDR4H_BIT14               _ATDDR4.Overlap_STR.ATDDR4HSTR.Bits.BIT14
    #define ATDDR4H_BIT15               _ATDDR4.Overlap_STR.ATDDR4HSTR.Bits.BIT15
    
    #define ATDDR4H_BIT8_MASK           1U
    #define ATDDR4H_BIT9_MASK           2U
    #define ATDDR4H_BIT10_MASK          4U
    #define ATDDR4H_BIT11_MASK          8U
    #define ATDDR4H_BIT12_MASK          16U
    #define ATDDR4H_BIT13_MASK          32U
    #define ATDDR4H_BIT14_MASK          64U
    #define ATDDR4H_BIT15_MASK          128U
    

    /*** ATDDR4L - ATD  Conversion Result Register 4 Low; 0x00000089 ***/
    union {
      byte Byte;
      struct {
        byte BIT0        :1;                                       /* Bit 0 */
        byte BIT1        :1;                                       /* Bit 1 */
        byte BIT2        :1;                                       /* Bit 2 */
        byte BIT3        :1;                                       /* Bit 3 */
        byte BIT4        :1;                                       /* Bit 4 */
        byte BIT5        :1;                                       /* Bit 5 */
        byte BIT6        :1;                                       /* Bit 6 */
        byte BIT7        :1;                                       /* Bit 7 */
      } Bits;
    } ATDDR4LSTR;
    #define ATDDR4L                     _ATDDR4.Overlap_STR.ATDDR4LSTR.Byte
    #define ATDDR4L_BIT0                _ATDDR4.Overlap_STR.ATDDR4LSTR.Bits.BIT0
    #define ATDDR4L_BIT1                _ATDDR4.Overlap_STR.ATDDR4LSTR.Bits.BIT1
    #define ATDDR4L_BIT2                _ATDDR4.Overlap_STR.ATDDR4LSTR.Bits.BIT2
    #define ATDDR4L_BIT3                _ATDDR4.Overlap_STR.ATDDR4LSTR.Bits.BIT3
    #define ATDDR4L_BIT4                _ATDDR4.Overlap_STR.ATDDR4LSTR.Bits.BIT4
    #define ATDDR4L_BIT5                _ATDDR4.Overlap_STR.ATDDR4LSTR.Bits.BIT5
    #define ATDDR4L_BIT6                _ATDDR4.Overlap_STR.ATDDR4LSTR.Bits.BIT6
    #define ATDDR4L_BIT7                _ATDDR4.Overlap_STR.ATDDR4LSTR.Bits.BIT7
    
    #define ATDDR4L_BIT0_MASK           1U
    #define ATDDR4L_BIT1_MASK           2U
    #define ATDDR4L_BIT2_MASK           4U
    #define ATDDR4L_BIT3_MASK           8U
    #define ATDDR4L_BIT4_MASK           16U
    #define ATDDR4L_BIT5_MASK           32U
    #define ATDDR4L_BIT6_MASK           64U
    #define ATDDR4L_BIT7_MASK           128U
    
  } Overlap_STR;

  struct {
    word BIT0        :1;                                       /* Bit 0 */
    word BIT1        :1;                                       /* Bit 1 */
    word BIT2        :1;                                       /* Bit 2 */
    word BIT3        :1;                                       /* Bit 3 */
    word BIT4        :1;                                       /* Bit 4 */
    word BIT5        :1;                                       /* Bit 5 */
    word BIT6        :1;                                       /* Bit 6 */
    word BIT7        :1;                                       /* Bit 7 */
    word BIT8        :1;                                       /* Bit 8 */
    word BIT9        :1;                                       /* Bit 9 */
    word BIT10       :1;                                       /* Bit 10 */
    word BIT11       :1;                                       /* Bit 11 */
    word BIT12       :1;                                       /* Bit 12 */
    word BIT13       :1;                                       /* Bit 13 */
    word BIT14       :1;                                       /* Bit 14 */
    word BIT15       :1;                                       /* Bit 15 */
  } Bits;
} ATDDR4STR;
extern volatile ATDDR4STR _ATDDR4 @(REG_BASE + 0x00000088UL);
#define ATDDR4                          _ATDDR4.Word
#define ATDDR4_BIT0                     _ATDDR4.Bits.BIT0
#define ATDDR4_BIT1                     _ATDDR4.Bits.BIT1
#define ATDDR4_BIT2                     _ATDDR4.Bits.BIT2
#define ATDDR4_BIT3                     _ATDDR4.Bits.BIT3
#define ATDDR4_BIT4                     _ATDDR4.Bits.BIT4
#define ATDDR4_BIT5                     _ATDDR4.Bits.BIT5
#define ATDDR4_BIT6                     _ATDDR4.Bits.BIT6
#define ATDDR4_BIT7                     _ATDDR4.Bits.BIT7
#define ATDDR4_BIT8                     _ATDDR4.Bits.BIT8
#define ATDDR4_BIT9                     _ATDDR4.Bits.BIT9
#define ATDDR4_BIT10                    _ATDDR4.Bits.BIT10
#define ATDDR4_BIT11                    _ATDDR4.Bits.BIT11
#define ATDDR4_BIT12                    _ATDDR4.Bits.BIT12
#define ATDDR4_BIT13                    _ATDDR4.Bits.BIT13
#define ATDDR4_BIT14                    _ATDDR4.Bits.BIT14
#define ATDDR4_BIT15                    _ATDDR4.Bits.BIT15

#define ATDDR4_BIT0_MASK                1U
#define ATDDR4_BIT1_MASK                2U
#define ATDDR4_BIT2_MASK                4U
#define ATDDR4_BIT3_MASK                8U
#define ATDDR4_BIT4_MASK                16U
#define ATDDR4_BIT5_MASK                32U
#define ATDDR4_BIT6_MASK                64U
#define ATDDR4_BIT7_MASK                128U
#define ATDDR4_BIT8_MASK                256U
#define ATDDR4_BIT9_MASK                512U
#define ATDDR4_BIT10_MASK               1024U
#define ATDDR4_BIT11_MASK               2048U
#define ATDDR4_BIT12_MASK               4096U
#define ATDDR4_BIT13_MASK               8192U
#define ATDDR4_BIT14_MASK               16384U
#define ATDDR4_BIT15_MASK               32768U


/*** ATDDR5 - ATD  Conversion Result Register 5; 0x0000008A ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** ATDDR5H - ATD  Conversion Result Register 5 High; 0x0000008A ***/
    union {
      byte Byte;
      struct {
        byte BIT8        :1;                                       /* Bit 8 */
        byte BIT9        :1;                                       /* Bit 9 */
        byte BIT10       :1;                                       /* Bit 10 */
        byte BIT11       :1;                                       /* Bit 11 */
        byte BIT12       :1;                                       /* Bit 12 */
        byte BIT13       :1;                                       /* Bit 13 */
        byte BIT14       :1;                                       /* Bit 14 */
        byte BIT15       :1;                                       /* Bit 15 */
      } Bits;
    } ATDDR5HSTR;
    #define ATDDR5H                     _ATDDR5.Overlap_STR.ATDDR5HSTR.Byte
    #define ATDDR5H_BIT8                _ATDDR5.Overlap_STR.ATDDR5HSTR.Bits.BIT8
    #define ATDDR5H_BIT9                _ATDDR5.Overlap_STR.ATDDR5HSTR.Bits.BIT9
    #define ATDDR5H_BIT10               _ATDDR5.Overlap_STR.ATDDR5HSTR.Bits.BIT10
    #define ATDDR5H_BIT11               _ATDDR5.Overlap_STR.ATDDR5HSTR.Bits.BIT11
    #define ATDDR5H_BIT12               _ATDDR5.Overlap_STR.ATDDR5HSTR.Bits.BIT12
    #define ATDDR5H_BIT13               _ATDDR5.Overlap_STR.ATDDR5HSTR.Bits.BIT13
    #define ATDDR5H_BIT14               _ATDDR5.Overlap_STR.ATDDR5HSTR.Bits.BIT14
    #define ATDDR5H_BIT15               _ATDDR5.Overlap_STR.ATDDR5HSTR.Bits.BIT15
    
    #define ATDDR5H_BIT8_MASK           1U
    #define ATDDR5H_BIT9_MASK           2U
    #define ATDDR5H_BIT10_MASK          4U
    #define ATDDR5H_BIT11_MASK          8U
    #define ATDDR5H_BIT12_MASK          16U
    #define ATDDR5H_BIT13_MASK          32U
    #define ATDDR5H_BIT14_MASK          64U
    #define ATDDR5H_BIT15_MASK          128U
    

    /*** ATDDR5L - ATD  Conversion Result Register 5 Low; 0x0000008B ***/
    union {
      byte Byte;
      struct {
        byte BIT0        :1;                                       /* Bit 0 */
        byte BIT1        :1;                                       /* Bit 1 */
        byte BIT2        :1;                                       /* Bit 2 */
        byte BIT3        :1;                                       /* Bit 3 */
        byte BIT4        :1;                                       /* Bit 4 */
        byte BIT5        :1;                                       /* Bit 5 */
        byte BIT6        :1;                                       /* Bit 6 */
        byte BIT7        :1;                                       /* Bit 7 */
      } Bits;
    } ATDDR5LSTR;
    #define ATDDR5L                     _ATDDR5.Overlap_STR.ATDDR5LSTR.Byte
    #define ATDDR5L_BIT0                _ATDDR5.Overlap_STR.ATDDR5LSTR.Bits.BIT0
    #define ATDDR5L_BIT1                _ATDDR5.Overlap_STR.ATDDR5LSTR.Bits.BIT1
    #define ATDDR5L_BIT2                _ATDDR5.Overlap_STR.ATDDR5LSTR.Bits.BIT2
    #define ATDDR5L_BIT3                _ATDDR5.Overlap_STR.ATDDR5LSTR.Bits.BIT3
    #define ATDDR5L_BIT4                _ATDDR5.Overlap_STR.ATDDR5LSTR.Bits.BIT4
    #define ATDDR5L_BIT5                _ATDDR5.Overlap_STR.ATDDR5LSTR.Bits.BIT5
    #define ATDDR5L_BIT6                _ATDDR5.Overlap_STR.ATDDR5LSTR.Bits.BIT6
    #define ATDDR5L_BIT7                _ATDDR5.Overlap_STR.ATDDR5LSTR.Bits.BIT7
    
    #define ATDDR5L_BIT0_MASK           1U
    #define ATDDR5L_BIT1_MASK           2U
    #define ATDDR5L_BIT2_MASK           4U
    #define ATDDR5L_BIT3_MASK           8U
    #define ATDDR5L_BIT4_MASK           16U
    #define ATDDR5L_BIT5_MASK           32U
    #define ATDDR5L_BIT6_MASK           64U
    #define ATDDR5L_BIT7_MASK           128U
    
  } Overlap_STR;

  struct {
    word BIT0        :1;                                       /* Bit 0 */
    word BIT1        :1;                                       /* Bit 1 */
    word BIT2        :1;                                       /* Bit 2 */
    word BIT3        :1;                                       /* Bit 3 */
    word BIT4        :1;                                       /* Bit 4 */
    word BIT5        :1;                                       /* Bit 5 */
    word BIT6        :1;                                       /* Bit 6 */
    word BIT7        :1;                                       /* Bit 7 */
    word BIT8        :1;                                       /* Bit 8 */
    word BIT9        :1;                                       /* Bit 9 */
    word BIT10       :1;                                       /* Bit 10 */
    word BIT11       :1;                                       /* Bit 11 */
    word BIT12       :1;                                       /* Bit 12 */
    word BIT13       :1;                                       /* Bit 13 */
    word BIT14       :1;                                       /* Bit 14 */
    word BIT15       :1;                                       /* Bit 15 */
  } Bits;
} ATDDR5STR;
extern volatile ATDDR5STR _ATDDR5 @(REG_BASE + 0x0000008AUL);
#define ATDDR5                          _ATDDR5.Word
#define ATDDR5_BIT0                     _ATDDR5.Bits.BIT0
#define ATDDR5_BIT1                     _ATDDR5.Bits.BIT1
#define ATDDR5_BIT2                     _ATDDR5.Bits.BIT2
#define ATDDR5_BIT3                     _ATDDR5.Bits.BIT3
#define ATDDR5_BIT4                     _ATDDR5.Bits.BIT4
#define ATDDR5_BIT5                     _ATDDR5.Bits.BIT5
#define ATDDR5_BIT6                     _ATDDR5.Bits.BIT6
#define ATDDR5_BIT7                     _ATDDR5.Bits.BIT7
#define ATDDR5_BIT8                     _ATDDR5.Bits.BIT8
#define ATDDR5_BIT9                     _ATDDR5.Bits.BIT9
#define ATDDR5_BIT10                    _ATDDR5.Bits.BIT10
#define ATDDR5_BIT11                    _ATDDR5.Bits.BIT11
#define ATDDR5_BIT12                    _ATDDR5.Bits.BIT12
#define ATDDR5_BIT13                    _ATDDR5.Bits.BIT13
#define ATDDR5_BIT14                    _ATDDR5.Bits.BIT14
#define ATDDR5_BIT15                    _ATDDR5.Bits.BIT15

#define ATDDR5_BIT0_MASK                1U
#define ATDDR5_BIT1_MASK                2U
#define ATDDR5_BIT2_MASK                4U
#define ATDDR5_BIT3_MASK                8U
#define ATDDR5_BIT4_MASK                16U
#define ATDDR5_BIT5_MASK                32U
#define ATDDR5_BIT6_MASK                64U
#define ATDDR5_BIT7_MASK                128U
#define ATDDR5_BIT8_MASK                256U
#define ATDDR5_BIT9_MASK                512U
#define ATDDR5_BIT10_MASK               1024U
#define ATDDR5_BIT11_MASK               2048U
#define ATDDR5_BIT12_MASK               4096U
#define ATDDR5_BIT13_MASK               8192U
#define ATDDR5_BIT14_MASK               16384U
#define ATDDR5_BIT15_MASK               32768U


/*** ATDDR6 - ATD  Conversion Result Register 6; 0x0000008C ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** ATDDR6H - ATD  Conversion Result Register 6 High; 0x0000008C ***/
    union {
      byte Byte;
      struct {
        byte BIT8        :1;                                       /* Bit 8 */
        byte BIT9        :1;                                       /* Bit 9 */
        byte BIT10       :1;                                       /* Bit 10 */
        byte BIT11       :1;                                       /* Bit 11 */
        byte BIT12       :1;                                       /* Bit 12 */
        byte BIT13       :1;                                       /* Bit 13 */
        byte BIT14       :1;                                       /* Bit 14 */
        byte BIT15       :1;                                       /* Bit 15 */
      } Bits;
    } ATDDR6HSTR;
    #define ATDDR6H                     _ATDDR6.Overlap_STR.ATDDR6HSTR.Byte
    #define ATDDR6H_BIT8                _ATDDR6.Overlap_STR.ATDDR6HSTR.Bits.BIT8
    #define ATDDR6H_BIT9                _ATDDR6.Overlap_STR.ATDDR6HSTR.Bits.BIT9
    #define ATDDR6H_BIT10               _ATDDR6.Overlap_STR.ATDDR6HSTR.Bits.BIT10
    #define ATDDR6H_BIT11               _ATDDR6.Overlap_STR.ATDDR6HSTR.Bits.BIT11
    #define ATDDR6H_BIT12               _ATDDR6.Overlap_STR.ATDDR6HSTR.Bits.BIT12
    #define ATDDR6H_BIT13               _ATDDR6.Overlap_STR.ATDDR6HSTR.Bits.BIT13
    #define ATDDR6H_BIT14               _ATDDR6.Overlap_STR.ATDDR6HSTR.Bits.BIT14
    #define ATDDR6H_BIT15               _ATDDR6.Overlap_STR.ATDDR6HSTR.Bits.BIT15
    
    #define ATDDR6H_BIT8_MASK           1U
    #define ATDDR6H_BIT9_MASK           2U
    #define ATDDR6H_BIT10_MASK          4U
    #define ATDDR6H_BIT11_MASK          8U
    #define ATDDR6H_BIT12_MASK          16U
    #define ATDDR6H_BIT13_MASK          32U
    #define ATDDR6H_BIT14_MASK          64U
    #define ATDDR6H_BIT15_MASK          128U
    

    /*** ATDDR6L - ATD  Conversion Result Register 6 Low; 0x0000008D ***/
    union {
      byte Byte;
      struct {
        byte BIT0        :1;                                       /* Bit 0 */
        byte BIT1        :1;                                       /* Bit 1 */
        byte BIT2        :1;                                       /* Bit 2 */
        byte BIT3        :1;                                       /* Bit 3 */
        byte BIT4        :1;                                       /* Bit 4 */
        byte BIT5        :1;                                       /* Bit 5 */
        byte BIT6        :1;                                       /* Bit 6 */
        byte BIT7        :1;                                       /* Bit 7 */
      } Bits;
    } ATDDR6LSTR;
    #define ATDDR6L                     _ATDDR6.Overlap_STR.ATDDR6LSTR.Byte
    #define ATDDR6L_BIT0                _ATDDR6.Overlap_STR.ATDDR6LSTR.Bits.BIT0
    #define ATDDR6L_BIT1                _ATDDR6.Overlap_STR.ATDDR6LSTR.Bits.BIT1
    #define ATDDR6L_BIT2                _ATDDR6.Overlap_STR.ATDDR6LSTR.Bits.BIT2
    #define ATDDR6L_BIT3                _ATDDR6.Overlap_STR.ATDDR6LSTR.Bits.BIT3
    #define ATDDR6L_BIT4                _ATDDR6.Overlap_STR.ATDDR6LSTR.Bits.BIT4
    #define ATDDR6L_BIT5                _ATDDR6.Overlap_STR.ATDDR6LSTR.Bits.BIT5
    #define ATDDR6L_BIT6                _ATDDR6.Overlap_STR.ATDDR6LSTR.Bits.BIT6
    #define ATDDR6L_BIT7                _ATDDR6.Overlap_STR.ATDDR6LSTR.Bits.BIT7
    
    #define ATDDR6L_BIT0_MASK           1U
    #define ATDDR6L_BIT1_MASK           2U
    #define ATDDR6L_BIT2_MASK           4U
    #define ATDDR6L_BIT3_MASK           8U
    #define ATDDR6L_BIT4_MASK           16U
    #define ATDDR6L_BIT5_MASK           32U
    #define ATDDR6L_BIT6_MASK           64U
    #define ATDDR6L_BIT7_MASK           128U
    
  } Overlap_STR;

  struct {
    word BIT0        :1;                                       /* Bit 0 */
    word BIT1        :1;                                       /* Bit 1 */
    word BIT2        :1;                                       /* Bit 2 */
    word BIT3        :1;                                       /* Bit 3 */
    word BIT4        :1;                                       /* Bit 4 */
    word BIT5        :1;                                       /* Bit 5 */
    word BIT6        :1;                                       /* Bit 6 */
    word BIT7        :1;                                       /* Bit 7 */
    word BIT8        :1;                                       /* Bit 8 */
    word BIT9        :1;                                       /* Bit 9 */
    word BIT10       :1;                                       /* Bit 10 */
    word BIT11       :1;                                       /* Bit 11 */
    word BIT12       :1;                                       /* Bit 12 */
    word BIT13       :1;                                       /* Bit 13 */
    word BIT14       :1;                                       /* Bit 14 */
    word BIT15       :1;                                       /* Bit 15 */
  } Bits;
} ATDDR6STR;
extern volatile ATDDR6STR _ATDDR6 @(REG_BASE + 0x0000008CUL);
#define ATDDR6                          _ATDDR6.Word
#define ATDDR6_BIT0                     _ATDDR6.Bits.BIT0
#define ATDDR6_BIT1                     _ATDDR6.Bits.BIT1
#define ATDDR6_BIT2                     _ATDDR6.Bits.BIT2
#define ATDDR6_BIT3                     _ATDDR6.Bits.BIT3
#define ATDDR6_BIT4                     _ATDDR6.Bits.BIT4
#define ATDDR6_BIT5                     _ATDDR6.Bits.BIT5
#define ATDDR6_BIT6                     _ATDDR6.Bits.BIT6
#define ATDDR6_BIT7                     _ATDDR6.Bits.BIT7
#define ATDDR6_BIT8                     _ATDDR6.Bits.BIT8
#define ATDDR6_BIT9                     _ATDDR6.Bits.BIT9
#define ATDDR6_BIT10                    _ATDDR6.Bits.BIT10
#define ATDDR6_BIT11                    _ATDDR6.Bits.BIT11
#define ATDDR6_BIT12                    _ATDDR6.Bits.BIT12
#define ATDDR6_BIT13                    _ATDDR6.Bits.BIT13
#define ATDDR6_BIT14                    _ATDDR6.Bits.BIT14
#define ATDDR6_BIT15                    _ATDDR6.Bits.BIT15

#define ATDDR6_BIT0_MASK                1U
#define ATDDR6_BIT1_MASK                2U
#define ATDDR6_BIT2_MASK                4U
#define ATDDR6_BIT3_MASK                8U
#define ATDDR6_BIT4_MASK                16U
#define ATDDR6_BIT5_MASK                32U
#define ATDDR6_BIT6_MASK                64U
#define ATDDR6_BIT7_MASK                128U
#define ATDDR6_BIT8_MASK                256U
#define ATDDR6_BIT9_MASK                512U
#define ATDDR6_BIT10_MASK               1024U
#define ATDDR6_BIT11_MASK               2048U
#define ATDDR6_BIT12_MASK               4096U
#define ATDDR6_BIT13_MASK               8192U
#define ATDDR6_BIT14_MASK               16384U
#define ATDDR6_BIT15_MASK               32768U


/*** ATDDR7 - ATD  Conversion Result Register 7; 0x0000008E ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** ATDDR7H - ATD  Conversion Result Register 7 High; 0x0000008E ***/
    union {
      byte Byte;
      struct {
        byte BIT8        :1;                                       /* Bit 8 */
        byte BIT9        :1;                                       /* Bit 9 */
        byte BIT10       :1;                                       /* Bit 10 */
        byte BIT11       :1;                                       /* Bit 11 */
        byte BIT12       :1;                                       /* Bit 12 */
        byte BIT13       :1;                                       /* Bit 13 */
        byte BIT14       :1;                                       /* Bit 14 */
        byte BIT15       :1;                                       /* Bit 15 */
      } Bits;
    } ATDDR7HSTR;
    #define ATDDR7H                     _ATDDR7.Overlap_STR.ATDDR7HSTR.Byte
    #define ATDDR7H_BIT8                _ATDDR7.Overlap_STR.ATDDR7HSTR.Bits.BIT8
    #define ATDDR7H_BIT9                _ATDDR7.Overlap_STR.ATDDR7HSTR.Bits.BIT9
    #define ATDDR7H_BIT10               _ATDDR7.Overlap_STR.ATDDR7HSTR.Bits.BIT10
    #define ATDDR7H_BIT11               _ATDDR7.Overlap_STR.ATDDR7HSTR.Bits.BIT11
    #define ATDDR7H_BIT12               _ATDDR7.Overlap_STR.ATDDR7HSTR.Bits.BIT12
    #define ATDDR7H_BIT13               _ATDDR7.Overlap_STR.ATDDR7HSTR.Bits.BIT13
    #define ATDDR7H_BIT14               _ATDDR7.Overlap_STR.ATDDR7HSTR.Bits.BIT14
    #define ATDDR7H_BIT15               _ATDDR7.Overlap_STR.ATDDR7HSTR.Bits.BIT15
    
    #define ATDDR7H_BIT8_MASK           1U
    #define ATDDR7H_BIT9_MASK           2U
    #define ATDDR7H_BIT10_MASK          4U
    #define ATDDR7H_BIT11_MASK          8U
    #define ATDDR7H_BIT12_MASK          16U
    #define ATDDR7H_BIT13_MASK          32U
    #define ATDDR7H_BIT14_MASK          64U
    #define ATDDR7H_BIT15_MASK          128U
    

    /*** ATDDR7L - ATD  Conversion Result Register 7 Low; 0x0000008F ***/
    union {
      byte Byte;
      struct {
        byte BIT0        :1;                                       /* Bit 0 */
        byte BIT1        :1;                                       /* Bit 1 */
        byte BIT2        :1;                                       /* Bit 2 */
        byte BIT3        :1;                                       /* Bit 3 */
        byte BIT4        :1;                                       /* Bit 4 */
        byte BIT5        :1;                                       /* Bit 5 */
        byte BIT6        :1;                                       /* Bit 6 */
        byte BIT7        :1;                                       /* Bit 7 */
      } Bits;
    } ATDDR7LSTR;
    #define ATDDR7L                     _ATDDR7.Overlap_STR.ATDDR7LSTR.Byte
    #define ATDDR7L_BIT0                _ATDDR7.Overlap_STR.ATDDR7LSTR.Bits.BIT0
    #define ATDDR7L_BIT1                _ATDDR7.Overlap_STR.ATDDR7LSTR.Bits.BIT1
    #define ATDDR7L_BIT2                _ATDDR7.Overlap_STR.ATDDR7LSTR.Bits.BIT2
    #define ATDDR7L_BIT3                _ATDDR7.Overlap_STR.ATDDR7LSTR.Bits.BIT3
    #define ATDDR7L_BIT4                _ATDDR7.Overlap_STR.ATDDR7LSTR.Bits.BIT4
    #define ATDDR7L_BIT5                _ATDDR7.Overlap_STR.ATDDR7LSTR.Bits.BIT5
    #define ATDDR7L_BIT6                _ATDDR7.Overlap_STR.ATDDR7LSTR.Bits.BIT6
    #define ATDDR7L_BIT7                _ATDDR7.Overlap_STR.ATDDR7LSTR.Bits.BIT7
    
    #define ATDDR7L_BIT0_MASK           1U
    #define ATDDR7L_BIT1_MASK           2U
    #define ATDDR7L_BIT2_MASK           4U
    #define ATDDR7L_BIT3_MASK           8U
    #define ATDDR7L_BIT4_MASK           16U
    #define ATDDR7L_BIT5_MASK           32U
    #define ATDDR7L_BIT6_MASK           64U
    #define ATDDR7L_BIT7_MASK           128U
    
  } Overlap_STR;

  struct {
    word BIT0        :1;                                       /* Bit 0 */
    word BIT1        :1;                                       /* Bit 1 */
    word BIT2        :1;                                       /* Bit 2 */
    word BIT3        :1;                                       /* Bit 3 */
    word BIT4        :1;                                       /* Bit 4 */
    word BIT5        :1;                                       /* Bit 5 */
    word BIT6        :1;                                       /* Bit 6 */
    word BIT7        :1;                                       /* Bit 7 */
    word BIT8        :1;                                       /* Bit 8 */
    word BIT9        :1;                                       /* Bit 9 */
    word BIT10       :1;                                       /* Bit 10 */
    word BIT11       :1;                                       /* Bit 11 */
    word BIT12       :1;                                       /* Bit 12 */
    word BIT13       :1;                                       /* Bit 13 */
    word BIT14       :1;                                       /* Bit 14 */
    word BIT15       :1;                                       /* Bit 15 */
  } Bits;
} ATDDR7STR;
extern volatile ATDDR7STR _ATDDR7 @(REG_BASE + 0x0000008EUL);
#define ATDDR7                          _ATDDR7.Word
#define ATDDR7_BIT0                     _ATDDR7.Bits.BIT0
#define ATDDR7_BIT1                     _ATDDR7.Bits.BIT1
#define ATDDR7_BIT2                     _ATDDR7.Bits.BIT2
#define ATDDR7_BIT3                     _ATDDR7.Bits.BIT3
#define ATDDR7_BIT4                     _ATDDR7.Bits.BIT4
#define ATDDR7_BIT5                     _ATDDR7.Bits.BIT5
#define ATDDR7_BIT6                     _ATDDR7.Bits.BIT6
#define ATDDR7_BIT7                     _ATDDR7.Bits.BIT7
#define ATDDR7_BIT8                     _ATDDR7.Bits.BIT8
#define ATDDR7_BIT9                     _ATDDR7.Bits.BIT9
#define ATDDR7_BIT10                    _ATDDR7.Bits.BIT10
#define ATDDR7_BIT11                    _ATDDR7.Bits.BIT11
#define ATDDR7_BIT12                    _ATDDR7.Bits.BIT12
#define ATDDR7_BIT13                    _ATDDR7.Bits.BIT13
#define ATDDR7_BIT14                    _ATDDR7.Bits.BIT14
#define ATDDR7_BIT15                    _ATDDR7.Bits.BIT15

#define ATDDR7_BIT0_MASK                1U
#define ATDDR7_BIT1_MASK                2U
#define ATDDR7_BIT2_MASK                4U
#define ATDDR7_BIT3_MASK                8U
#define ATDDR7_BIT4_MASK                16U
#define ATDDR7_BIT5_MASK                32U
#define ATDDR7_BIT6_MASK                64U
#define ATDDR7_BIT7_MASK                128U
#define ATDDR7_BIT8_MASK                256U
#define ATDDR7_BIT9_MASK                512U
#define ATDDR7_BIT10_MASK               1024U
#define ATDDR7_BIT11_MASK               2048U
#define ATDDR7_BIT12_MASK               4096U
#define ATDDR7_BIT13_MASK               8192U
#define ATDDR7_BIT14_MASK               16384U
#define ATDDR7_BIT15_MASK               32768U


/*** PWME - PWM Enable Register; 0x000000A0 ***/
typedef union {
  byte Byte;
  struct {
    byte PWME0       :1;                                       /* Pulse Width Channel 0 Enable */
    byte PWME1       :1;                                       /* Pulse Width Channel 1 Enable */
    byte PWME2       :1;                                       /* Pulse Width Channel 2 Enable */
    byte PWME3       :1;                                       /* Pulse Width Channel 3 Enable */
    byte PWME4       :1;                                       /* Pulse Width Channel 4 Enable */
    byte PWME5       :1;                                       /* Pulse Width Channel 5 Enable */
    byte PWME6       :1;                                       /* Pulse Width Channel 6 Enable */
    byte PWME7       :1;                                       /* Pulse Width Channel 7 Enable */
  } Bits;
} PWMESTR;
extern volatile PWMESTR _PWME @(REG_BASE + 0x000000A0UL);
#define PWME                            _PWME.Byte
#define PWME_PWME0                      _PWME.Bits.PWME0
#define PWME_PWME1                      _PWME.Bits.PWME1
#define PWME_PWME2                      _PWME.Bits.PWME2
#define PWME_PWME3                      _PWME.Bits.PWME3
#define PWME_PWME4                      _PWME.Bits.PWME4
#define PWME_PWME5                      _PWME.Bits.PWME5
#define PWME_PWME6                      _PWME.Bits.PWME6
#define PWME_PWME7                      _PWME.Bits.PWME7

#define PWME_PWME0_MASK                 1U
#define PWME_PWME1_MASK                 2U
#define PWME_PWME2_MASK                 4U
#define PWME_PWME3_MASK                 8U
#define PWME_PWME4_MASK                 16U
#define PWME_PWME5_MASK                 32U
#define PWME_PWME6_MASK                 64U
#define PWME_PWME7_MASK                 128U


/*** PWMPOL - PWM Polarity Register; 0x000000A1 ***/
typedef union {
  byte Byte;
  struct {
    byte PPOL0       :1;                                       /* Pulse Width Channel 0 Polarity */
    byte PPOL1       :1;                                       /* Pulse Width Channel 1 Polarity */
    byte PPOL2       :1;                                       /* Pulse Width Channel 2 Polarity */
    byte PPOL3       :1;                                       /* Pulse Width Channel 3 Polarity */
    byte PPOL4       :1;                                       /* Pulse Width Channel 4 Polarity */
    byte PPOL5       :1;                                       /* Pulse Width Channel 5 Polarity */
    byte PPOL6       :1;                                       /* Pulse Width Channel 6 Polarity */
    byte PPOL7       :1;                                       /* Pulse Width Channel 7 Polarity */
  } Bits;
} PWMPOLSTR;
extern volatile PWMPOLSTR _PWMPOL @(REG_BASE + 0x000000A1UL);
#define PWMPOL                          _PWMPOL.Byte
#define PWMPOL_PPOL0                    _PWMPOL.Bits.PPOL0
#define PWMPOL_PPOL1                    _PWMPOL.Bits.PPOL1
#define PWMPOL_PPOL2                    _PWMPOL.Bits.PPOL2
#define PWMPOL_PPOL3                    _PWMPOL.Bits.PPOL3
#define PWMPOL_PPOL4                    _PWMPOL.Bits.PPOL4
#define PWMPOL_PPOL5                    _PWMPOL.Bits.PPOL5
#define PWMPOL_PPOL6                    _PWMPOL.Bits.PPOL6
#define PWMPOL_PPOL7                    _PWMPOL.Bits.PPOL7

#define PWMPOL_PPOL0_MASK               1U
#define PWMPOL_PPOL1_MASK               2U
#define PWMPOL_PPOL2_MASK               4U
#define PWMPOL_PPOL3_MASK               8U
#define PWMPOL_PPOL4_MASK               16U
#define PWMPOL_PPOL5_MASK               32U
#define PWMPOL_PPOL6_MASK               64U
#define PWMPOL_PPOL7_MASK               128U


/*** PWMCLK - PWM Clock Select Register; 0x000000A2 ***/
typedef union {
  byte Byte;
  struct {
    byte PCLK0       :1;                                       /* Pulse Width Channel 0 Clock Select */
    byte PCLK1       :1;                                       /* Pulse Width Channel 1 Clock Select */
    byte PCLK2       :1;                                       /* Pulse Width Channel 2 Clock Select */
    byte PCLK3       :1;                                       /* Pulse Width Channel 3 Clock Select */
    byte PCLK4       :1;                                       /* Pulse Width Channel 4 Clock Select */
    byte PCLK5       :1;                                       /* Pulse Width Channel 5 Clock Select */
    byte PCLK6       :1;                                       /* Pulse Width Channel 6 Clock Select */
    byte PCLK7       :1;                                       /* Pulse Width Channel 7 Clock Select */
  } Bits;
} PWMCLKSTR;
extern volatile PWMCLKSTR _PWMCLK @(REG_BASE + 0x000000A2UL);
#define PWMCLK                          _PWMCLK.Byte
#define PWMCLK_PCLK0                    _PWMCLK.Bits.PCLK0
#define PWMCLK_PCLK1                    _PWMCLK.Bits.PCLK1
#define PWMCLK_PCLK2                    _PWMCLK.Bits.PCLK2
#define PWMCLK_PCLK3                    _PWMCLK.Bits.PCLK3
#define PWMCLK_PCLK4                    _PWMCLK.Bits.PCLK4
#define PWMCLK_PCLK5                    _PWMCLK.Bits.PCLK5
#define PWMCLK_PCLK6                    _PWMCLK.Bits.PCLK6
#define PWMCLK_PCLK7                    _PWMCLK.Bits.PCLK7

#define PWMCLK_PCLK0_MASK               1U
#define PWMCLK_PCLK1_MASK               2U
#define PWMCLK_PCLK2_MASK               4U
#define PWMCLK_PCLK3_MASK               8U
#define PWMCLK_PCLK4_MASK               16U
#define PWMCLK_PCLK5_MASK               32U
#define PWMCLK_PCLK6_MASK               64U
#define PWMCLK_PCLK7_MASK               128U


/*** PWMPRCLK - PWM Prescale Clock Select Register; 0x000000A3 ***/
typedef union {
  byte Byte;
  struct {
    byte PCKA0       :1;                                       /* Prescaler Select for Clock A 0 */
    byte PCKA1       :1;                                       /* Prescaler Select for Clock A 1 */
    byte PCKA2       :1;                                       /* Prescaler Select for Clock A 2 */
    byte             :1; 
    byte PCKB0       :1;                                       /* Prescaler Select for Clock B 0 */
    byte PCKB1       :1;                                       /* Prescaler Select for Clock B 1 */
    byte PCKB2       :1;                                       /* Prescaler Select for Clock B 2 */
    byte             :1; 
  } Bits;
  struct {
    byte grpPCKA :3;
    byte         :1;
    byte grpPCKB :3;
    byte         :1;
  } MergedBits;
} PWMPRCLKSTR;
extern volatile PWMPRCLKSTR _PWMPRCLK @(REG_BASE + 0x000000A3UL);
#define PWMPRCLK                        _PWMPRCLK.Byte
#define PWMPRCLK_PCKA0                  _PWMPRCLK.Bits.PCKA0
#define PWMPRCLK_PCKA1                  _PWMPRCLK.Bits.PCKA1
#define PWMPRCLK_PCKA2                  _PWMPRCLK.Bits.PCKA2
#define PWMPRCLK_PCKB0                  _PWMPRCLK.Bits.PCKB0
#define PWMPRCLK_PCKB1                  _PWMPRCLK.Bits.PCKB1
#define PWMPRCLK_PCKB2                  _PWMPRCLK.Bits.PCKB2
#define PWMPRCLK_PCKA                   _PWMPRCLK.MergedBits.grpPCKA
#define PWMPRCLK_PCKB                   _PWMPRCLK.MergedBits.grpPCKB

#define PWMPRCLK_PCKA0_MASK             1U
#define PWMPRCLK_PCKA1_MASK             2U
#define PWMPRCLK_PCKA2_MASK             4U
#define PWMPRCLK_PCKB0_MASK             16U
#define PWMPRCLK_PCKB1_MASK             32U
#define PWMPRCLK_PCKB2_MASK             64U
#define PWMPRCLK_PCKA_MASK              7U
#define PWMPRCLK_PCKA_BITNUM            0U
#define PWMPRCLK_PCKB_MASK              112U
#define PWMPRCLK_PCKB_BITNUM            4U


/*** PWMCAE - PWM Center Align Enable Register; 0x000000A4 ***/
typedef union {
  byte Byte;
  struct {
    byte CAE0        :1;                                       /* Center Aligned Output Mode on channel 0 */
    byte CAE1        :1;                                       /* Center Aligned Output Mode on channel 1 */
    byte CAE2        :1;                                       /* Center Aligned Output Mode on channel 2 */
    byte CAE3        :1;                                       /* Center Aligned Output Mode on channel 3 */
    byte CAE4        :1;                                       /* Center Aligned Output Mode on channel 4 */
    byte CAE5        :1;                                       /* Center Aligned Output Mode on channel 5 */
    byte CAE6        :1;                                       /* Center Aligned Output Mode on channel 6 */
    byte CAE7        :1;                                       /* Center Aligned Output Mode on channel 7 */
  } Bits;
} PWMCAESTR;
extern volatile PWMCAESTR _PWMCAE @(REG_BASE + 0x000000A4UL);
#define PWMCAE                          _PWMCAE.Byte
#define PWMCAE_CAE0                     _PWMCAE.Bits.CAE0
#define PWMCAE_CAE1                     _PWMCAE.Bits.CAE1
#define PWMCAE_CAE2                     _PWMCAE.Bits.CAE2
#define PWMCAE_CAE3                     _PWMCAE.Bits.CAE3
#define PWMCAE_CAE4                     _PWMCAE.Bits.CAE4
#define PWMCAE_CAE5                     _PWMCAE.Bits.CAE5
#define PWMCAE_CAE6                     _PWMCAE.Bits.CAE6
#define PWMCAE_CAE7                     _PWMCAE.Bits.CAE7

#define PWMCAE_CAE0_MASK                1U
#define PWMCAE_CAE1_MASK                2U
#define PWMCAE_CAE2_MASK                4U
#define PWMCAE_CAE3_MASK                8U
#define PWMCAE_CAE4_MASK                16U
#define PWMCAE_CAE5_MASK                32U
#define PWMCAE_CAE6_MASK                64U
#define PWMCAE_CAE7_MASK                128U


/*** PWMCTL - PWM Control Register; 0x000000A5 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte PFRZ        :1;                                       /* PWM Counters Stop in Freeze Mode */
    byte PSWAI       :1;                                       /* PWM Stops in Wait Mode */
    byte CON01       :1;                                       /* Concatenate channels 0 and 1 */
    byte CON23       :1;                                       /* Concatenate channels 2 and 3 */
    byte CON45       :1;                                       /* Concatenate channels 4 and 5 */
    byte CON67       :1;                                       /* Concatenate channels 6 and 7 */
  } Bits;
} PWMCTLSTR;
extern volatile PWMCTLSTR _PWMCTL @(REG_BASE + 0x000000A5UL);
#define PWMCTL                          _PWMCTL.Byte
#define PWMCTL_PFRZ                     _PWMCTL.Bits.PFRZ
#define PWMCTL_PSWAI                    _PWMCTL.Bits.PSWAI
#define PWMCTL_CON01                    _PWMCTL.Bits.CON01
#define PWMCTL_CON23                    _PWMCTL.Bits.CON23
#define PWMCTL_CON45                    _PWMCTL.Bits.CON45
#define PWMCTL_CON67                    _PWMCTL.Bits.CON67

#define PWMCTL_PFRZ_MASK                4U
#define PWMCTL_PSWAI_MASK               8U
#define PWMCTL_CON01_MASK               16U
#define PWMCTL_CON23_MASK               32U
#define PWMCTL_CON45_MASK               64U
#define PWMCTL_CON67_MASK               128U


/*** PWMSCLA - PWM Scale A Register; 0x000000A8 ***/
typedef union {
  byte Byte;
  struct {
    byte BIT0        :1;                                       /* PWM Scale A Bit 0 */
    byte BIT1        :1;                                       /* PWM Scale A Bit 1 */
    byte BIT2        :1;                                       /* PWM Scale A Bit 2 */
    byte BIT3        :1;                                       /* PWM Scale A Bit 3 */
    byte BIT4        :1;                                       /* PWM Scale A Bit 4 */
    byte BIT5        :1;                                       /* PWM Scale A Bit 5 */
    byte BIT6        :1;                                       /* PWM Scale A Bit 6 */
    byte BIT7        :1;                                       /* PWM Scale A Bit 7 */
  } Bits;
} PWMSCLASTR;
extern volatile PWMSCLASTR _PWMSCLA @(REG_BASE + 0x000000A8UL);
#define PWMSCLA                         _PWMSCLA.Byte
#define PWMSCLA_BIT0                    _PWMSCLA.Bits.BIT0
#define PWMSCLA_BIT1                    _PWMSCLA.Bits.BIT1
#define PWMSCLA_BIT2                    _PWMSCLA.Bits.BIT2
#define PWMSCLA_BIT3                    _PWMSCLA.Bits.BIT3
#define PWMSCLA_BIT4                    _PWMSCLA.Bits.BIT4
#define PWMSCLA_BIT5                    _PWMSCLA.Bits.BIT5
#define PWMSCLA_BIT6                    _PWMSCLA.Bits.BIT6
#define PWMSCLA_BIT7                    _PWMSCLA.Bits.BIT7

#define PWMSCLA_BIT0_MASK               1U
#define PWMSCLA_BIT1_MASK               2U
#define PWMSCLA_BIT2_MASK               4U
#define PWMSCLA_BIT3_MASK               8U
#define PWMSCLA_BIT4_MASK               16U
#define PWMSCLA_BIT5_MASK               32U
#define PWMSCLA_BIT6_MASK               64U
#define PWMSCLA_BIT7_MASK               128U


/*** PWMSCLB - PWM Scale B Register; 0x000000A9 ***/
typedef union {
  byte Byte;
  struct {
    byte BIT0        :1;                                       /* PWM Scale B Bit 0 */
    byte BIT1        :1;                                       /* PWM Scale B Bit 1 */
    byte BIT2        :1;                                       /* PWM Scale B Bit 2 */
    byte BIT3        :1;                                       /* PWM Scale B Bit 3 */
    byte BIT4        :1;                                       /* PWM Scale B Bit 4 */
    byte BIT5        :1;                                       /* PWM Scale B Bit 5 */
    byte BIT6        :1;                                       /* PWM Scale B Bit 6 */
    byte BIT7        :1;                                       /* PWM Scale B Bit 7 */
  } Bits;
} PWMSCLBSTR;
extern volatile PWMSCLBSTR _PWMSCLB @(REG_BASE + 0x000000A9UL);
#define PWMSCLB                         _PWMSCLB.Byte
#define PWMSCLB_BIT0                    _PWMSCLB.Bits.BIT0
#define PWMSCLB_BIT1                    _PWMSCLB.Bits.BIT1
#define PWMSCLB_BIT2                    _PWMSCLB.Bits.BIT2
#define PWMSCLB_BIT3                    _PWMSCLB.Bits.BIT3
#define PWMSCLB_BIT4                    _PWMSCLB.Bits.BIT4
#define PWMSCLB_BIT5                    _PWMSCLB.Bits.BIT5
#define PWMSCLB_BIT6                    _PWMSCLB.Bits.BIT6
#define PWMSCLB_BIT7                    _PWMSCLB.Bits.BIT7

#define PWMSCLB_BIT0_MASK               1U
#define PWMSCLB_BIT1_MASK               2U
#define PWMSCLB_BIT2_MASK               4U
#define PWMSCLB_BIT3_MASK               8U
#define PWMSCLB_BIT4_MASK               16U
#define PWMSCLB_BIT5_MASK               32U
#define PWMSCLB_BIT6_MASK               64U
#define PWMSCLB_BIT7_MASK               128U


/*** PWMCNT01 - PWM Channel Counter 01 Register; 0x000000AC ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** PWMCNT0 - PWM Channel Counter 0 Register; 0x000000AC ***/
    union {
      byte Byte;
    } PWMCNT0STR;
    #define PWMCNT0                     _PWMCNT01.Overlap_STR.PWMCNT0STR.Byte
    /* PWMCNT_ARR: Access 8 PWMCNTx registers in an array */
    #define PWMCNT_ARR                  ((volatile byte *) &PWMCNT0)
    

    /*** PWMCNT1 - PWM Channel Counter 1 Register; 0x000000AD ***/
    union {
      byte Byte;
    } PWMCNT1STR;
    #define PWMCNT1                     _PWMCNT01.Overlap_STR.PWMCNT1STR.Byte
    
  } Overlap_STR;

} PWMCNT01STR;
extern volatile PWMCNT01STR _PWMCNT01 @(REG_BASE + 0x000000ACUL);
#define PWMCNT01                        _PWMCNT01.Word


/*** PWMCNT23 - PWM Channel Counter 23 Register; 0x000000AE ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** PWMCNT2 - PWM Channel Counter 2 Register; 0x000000AE ***/
    union {
      byte Byte;
    } PWMCNT2STR;
    #define PWMCNT2                     _PWMCNT23.Overlap_STR.PWMCNT2STR.Byte
    

    /*** PWMCNT3 - PWM Channel Counter 3 Register; 0x000000AF ***/
    union {
      byte Byte;
    } PWMCNT3STR;
    #define PWMCNT3                     _PWMCNT23.Overlap_STR.PWMCNT3STR.Byte
    
  } Overlap_STR;

} PWMCNT23STR;
extern volatile PWMCNT23STR _PWMCNT23 @(REG_BASE + 0x000000AEUL);
#define PWMCNT23                        _PWMCNT23.Word


/*** PWMCNT45 - PWM Channel Counter 45 Register; 0x000000B0 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** PWMCNT4 - PWM Channel Counter 4 Register; 0x000000B0 ***/
    union {
      byte Byte;
    } PWMCNT4STR;
    #define PWMCNT4                     _PWMCNT45.Overlap_STR.PWMCNT4STR.Byte
    

    /*** PWMCNT5 - PWM Channel Counter 5 Register; 0x000000B1 ***/
    union {
      byte Byte;
    } PWMCNT5STR;
    #define PWMCNT5                     _PWMCNT45.Overlap_STR.PWMCNT5STR.Byte
    
  } Overlap_STR;

} PWMCNT45STR;
extern volatile PWMCNT45STR _PWMCNT45 @(REG_BASE + 0x000000B0UL);
#define PWMCNT45                        _PWMCNT45.Word


/*** PWMCNT67 - PWM Channel Counter 67 Register; 0x000000B2 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** PWMCNT6 - PWM Channel Counter 6 Register; 0x000000B2 ***/
    union {
      byte Byte;
    } PWMCNT6STR;
    #define PWMCNT6                     _PWMCNT67.Overlap_STR.PWMCNT6STR.Byte
    

    /*** PWMCNT7 - PWM Channel Counter 7 Register; 0x000000B3 ***/
    union {
      byte Byte;
    } PWMCNT7STR;
    #define PWMCNT7                     _PWMCNT67.Overlap_STR.PWMCNT7STR.Byte
    
  } Overlap_STR;

} PWMCNT67STR;
extern volatile PWMCNT67STR _PWMCNT67 @(REG_BASE + 0x000000B2UL);
#define PWMCNT67                        _PWMCNT67.Word


/*** PWMPER01 - PWM Channel Period 01 Register; 0x000000B4 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** PWMPER0 - PWM Channel Period 0 Register; 0x000000B4 ***/
    union {
      byte Byte;
    } PWMPER0STR;
    #define PWMPER0                     _PWMPER01.Overlap_STR.PWMPER0STR.Byte
    /* PWMPER_ARR: Access 8 PWMPERx registers in an array */
    #define PWMPER_ARR                  ((volatile byte *) &PWMPER0)
    

    /*** PWMPER1 - PWM Channel Period 1 Register; 0x000000B5 ***/
    union {
      byte Byte;
    } PWMPER1STR;
    #define PWMPER1                     _PWMPER01.Overlap_STR.PWMPER1STR.Byte
    
  } Overlap_STR;

} PWMPER01STR;
extern volatile PWMPER01STR _PWMPER01 @(REG_BASE + 0x000000B4UL);
#define PWMPER01                        _PWMPER01.Word


/*** PWMPER23 - PWM Channel Period 23 Register; 0x000000B6 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** PWMPER2 - PWM Channel Period 2 Register; 0x000000B6 ***/
    union {
      byte Byte;
    } PWMPER2STR;
    #define PWMPER2                     _PWMPER23.Overlap_STR.PWMPER2STR.Byte
    

    /*** PWMPER3 - PWM Channel Period 3 Register; 0x000000B7 ***/
    union {
      byte Byte;
    } PWMPER3STR;
    #define PWMPER3                     _PWMPER23.Overlap_STR.PWMPER3STR.Byte
    
  } Overlap_STR;

} PWMPER23STR;
extern volatile PWMPER23STR _PWMPER23 @(REG_BASE + 0x000000B6UL);
#define PWMPER23                        _PWMPER23.Word


/*** PWMPER45 - PWM Channel Period 45 Register; 0x000000B8 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** PWMPER4 - PWM Channel Period 4 Register; 0x000000B8 ***/
    union {
      byte Byte;
    } PWMPER4STR;
    #define PWMPER4                     _PWMPER45.Overlap_STR.PWMPER4STR.Byte
    

    /*** PWMPER5 - PWM Channel Period 5 Register; 0x000000B9 ***/
    union {
      byte Byte;
    } PWMPER5STR;
    #define PWMPER5                     _PWMPER45.Overlap_STR.PWMPER5STR.Byte
    
  } Overlap_STR;

} PWMPER45STR;
extern volatile PWMPER45STR _PWMPER45 @(REG_BASE + 0x000000B8UL);
#define PWMPER45                        _PWMPER45.Word


/*** PWMPER67 - PWM Channel Period 67 Register; 0x000000BA ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** PWMPER6 - PWM Channel Period 6 Register; 0x000000BA ***/
    union {
      byte Byte;
    } PWMPER6STR;
    #define PWMPER6                     _PWMPER67.Overlap_STR.PWMPER6STR.Byte
    

    /*** PWMPER7 - PWM Channel Period 7 Register; 0x000000BB ***/
    union {
      byte Byte;
    } PWMPER7STR;
    #define PWMPER7                     _PWMPER67.Overlap_STR.PWMPER7STR.Byte
    
  } Overlap_STR;

} PWMPER67STR;
extern volatile PWMPER67STR _PWMPER67 @(REG_BASE + 0x000000BAUL);
#define PWMPER67                        _PWMPER67.Word


/*** PWMDTY01 - PWM Channel Duty 01 Register; 0x000000BC ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** PWMDTY0 - PWM Channel Duty 0 Register; 0x000000BC ***/
    union {
      byte Byte;
    } PWMDTY0STR;
    #define PWMDTY0                     _PWMDTY01.Overlap_STR.PWMDTY0STR.Byte
    /* PWMDTY_ARR: Access 8 PWMDTYx registers in an array */
    #define PWMDTY_ARR                  ((volatile byte *) &PWMDTY0)
    

    /*** PWMDTY1 - PWM Channel Duty 1 Register; 0x000000BD ***/
    union {
      byte Byte;
    } PWMDTY1STR;
    #define PWMDTY1                     _PWMDTY01.Overlap_STR.PWMDTY1STR.Byte
    
  } Overlap_STR;

} PWMDTY01STR;
extern volatile PWMDTY01STR _PWMDTY01 @(REG_BASE + 0x000000BCUL);
#define PWMDTY01                        _PWMDTY01.Word


/*** PWMDTY23 - PWM Channel Duty 23 Register; 0x000000BE ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** PWMDTY2 - PWM Channel Duty 2 Register; 0x000000BE ***/
    union {
      byte Byte;
    } PWMDTY2STR;
    #define PWMDTY2                     _PWMDTY23.Overlap_STR.PWMDTY2STR.Byte
    

    /*** PWMDTY3 - PWM Channel Duty 3 Register; 0x000000BF ***/
    union {
      byte Byte;
    } PWMDTY3STR;
    #define PWMDTY3                     _PWMDTY23.Overlap_STR.PWMDTY3STR.Byte
    
  } Overlap_STR;

} PWMDTY23STR;
extern volatile PWMDTY23STR _PWMDTY23 @(REG_BASE + 0x000000BEUL);
#define PWMDTY23                        _PWMDTY23.Word


/*** PWMDTY45 - PWM Channel Duty 45 Register; 0x000000C0 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** PWMDTY4 - PWM Channel Duty 4 Register; 0x000000C0 ***/
    union {
      byte Byte;
    } PWMDTY4STR;
    #define PWMDTY4                     _PWMDTY45.Overlap_STR.PWMDTY4STR.Byte
    

    /*** PWMDTY5 - PWM Channel Duty 5 Register; 0x000000C1 ***/
    union {
      byte Byte;
    } PWMDTY5STR;
    #define PWMDTY5                     _PWMDTY45.Overlap_STR.PWMDTY5STR.Byte
    
  } Overlap_STR;

} PWMDTY45STR;
extern volatile PWMDTY45STR _PWMDTY45 @(REG_BASE + 0x000000C0UL);
#define PWMDTY45                        _PWMDTY45.Word


/*** PWMDTY67 - PWM Channel Duty 67 Register; 0x000000C2 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** PWMDTY6 - PWM Channel Duty 6 Register; 0x000000C2 ***/
    union {
      byte Byte;
    } PWMDTY6STR;
    #define PWMDTY6                     _PWMDTY67.Overlap_STR.PWMDTY6STR.Byte
    

    /*** PWMDTY7 - PWM Channel Duty 7 Register; 0x000000C3 ***/
    union {
      byte Byte;
    } PWMDTY7STR;
    #define PWMDTY7                     _PWMDTY67.Overlap_STR.PWMDTY7STR.Byte
    
  } Overlap_STR;

} PWMDTY67STR;
extern volatile PWMDTY67STR _PWMDTY67 @(REG_BASE + 0x000000C2UL);
#define PWMDTY67                        _PWMDTY67.Word


/*** PWMSDN - PWM Shutdown Register; 0x000000C4 ***/
typedef union {
  byte Byte;
  struct {
    byte PWM7ENA     :1;                                       /* PWM emergency shutdown Enable */
    byte PWM7INL     :1;                                       /* PWM shutdown active input level for ch. 7 */
    byte PWM7IN      :1;                                       /* PWM channel 7 input status */
    byte             :1; 
    byte PWMLVL      :1;                                       /* PWM shutdown output Level */
    byte PWMRSTRT    :1;                                       /* PWM Restart */
    byte PWMIE       :1;                                       /* PWM Interrupt Enable */
    byte PWMIF       :1;                                       /* PWM Interrupt Flag */
  } Bits;
} PWMSDNSTR;
extern volatile PWMSDNSTR _PWMSDN @(REG_BASE + 0x000000C4UL);
#define PWMSDN                          _PWMSDN.Byte
#define PWMSDN_PWM7ENA                  _PWMSDN.Bits.PWM7ENA
#define PWMSDN_PWM7INL                  _PWMSDN.Bits.PWM7INL
#define PWMSDN_PWM7IN                   _PWMSDN.Bits.PWM7IN
#define PWMSDN_PWMLVL                   _PWMSDN.Bits.PWMLVL
#define PWMSDN_PWMRSTRT                 _PWMSDN.Bits.PWMRSTRT
#define PWMSDN_PWMIE                    _PWMSDN.Bits.PWMIE
#define PWMSDN_PWMIF                    _PWMSDN.Bits.PWMIF

#define PWMSDN_PWM7ENA_MASK             1U
#define PWMSDN_PWM7INL_MASK             2U
#define PWMSDN_PWM7IN_MASK              4U
#define PWMSDN_PWMLVL_MASK              16U
#define PWMSDN_PWMRSTRT_MASK            32U
#define PWMSDN_PWMIE_MASK               64U
#define PWMSDN_PWMIF_MASK               128U


/*** SCIBD - SCI  Baud Rate Register; 0x000000C8 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** SCIASR1 - SCI  Alternative Status Register 1; 0x000000C8 ***/
    union {
      byte Byte;
      union { /* Several registers at the same address */
        /*** SCIASR1 - SCI  Alternative Status Register 1; Several registers at the same address ***/
        union {
          struct {
            byte BKDIF       :1;                                       /* Break Detect Interrupt Flag */
            byte BERRIF      :1;                                       /* Bit Error Interrupt Flag */
            byte BERRV       :1;                                       /* Bit Error Value */
            byte             :1; 
            byte             :1; 
            byte             :1; 
            byte             :1; 
            byte RXEDGIF     :1;                                       /* Receive Input Active Edge Interrupt Flag */
          } Bits;
        } SCIASR1STR;
        #define SCIASR1                 _SCIBD.Overlap_STR.SCIASR1STR.Byte
        #define SCIASR1_BKDIF           _SCIBD.Overlap_STR.SCIASR1STR.SameAddr_STR.SCIASR1STR.Bits.BKDIF
        #define SCIASR1_BERRIF          _SCIBD.Overlap_STR.SCIASR1STR.SameAddr_STR.SCIASR1STR.Bits.BERRIF
        #define SCIASR1_BERRV           _SCIBD.Overlap_STR.SCIASR1STR.SameAddr_STR.SCIASR1STR.Bits.BERRV
        #define SCIASR1_RXEDGIF         _SCIBD.Overlap_STR.SCIASR1STR.SameAddr_STR.SCIASR1STR.Bits.RXEDGIF
        
        #define SCIASR1_BKDIF_MASK      1U
        #define SCIASR1_BERRIF_MASK     2U
        #define SCIASR1_BERRV_MASK      4U
        #define SCIASR1_RXEDGIF_MASK    128U
        
        /*** SCIBDH - SCI  Baud Rate Register High; Several registers at the same address ***/
        union {
          struct {
            byte SBR8        :1;                                       /* SCI Baud Rate Bit 8 */
            byte SBR9        :1;                                       /* SCI Baud Rate Bit 9 */
            byte SBR10       :1;                                       /* SCI Baud Rate Bit 10 */
            byte SBR11       :1;                                       /* SCI Baud Rate Bit 11 */
            byte SBR12       :1;                                       /* SCI Baud Rate Bit 12 */
            byte TNP0        :1;                                       /* Transmitter Narrow Pulse Bit 0 */
            byte TNP1        :1;                                       /* Transmitter Narrow Pulse Bit 1 */
            byte IREN        :1;                                       /* Infrared Enable Bit */
          } Bits;
          struct {
            byte grpSBR_8 :5;
            byte grpTNP :2;
            byte :1;
          } MergedBits;
        } SCIBDHSTR;
        #define SCIBDH                  _SCIBD.Overlap_STR.SCIASR1STR.Byte
        #define SCIBDH_SBR8             _SCIBD.Overlap_STR.SCIASR1STR.SameAddr_STR.SCIBDHSTR.Bits.SBR8
        #define SCIBDH_SBR9             _SCIBD.Overlap_STR.SCIASR1STR.SameAddr_STR.SCIBDHSTR.Bits.SBR9
        #define SCIBDH_SBR10            _SCIBD.Overlap_STR.SCIASR1STR.SameAddr_STR.SCIBDHSTR.Bits.SBR10
        #define SCIBDH_SBR11            _SCIBD.Overlap_STR.SCIASR1STR.SameAddr_STR.SCIBDHSTR.Bits.SBR11
        #define SCIBDH_SBR12            _SCIBD.Overlap_STR.SCIASR1STR.SameAddr_STR.SCIBDHSTR.Bits.SBR12
        #define SCIBDH_TNP0             _SCIBD.Overlap_STR.SCIASR1STR.SameAddr_STR.SCIBDHSTR.Bits.TNP0
        #define SCIBDH_TNP1             _SCIBD.Overlap_STR.SCIASR1STR.SameAddr_STR.SCIBDHSTR.Bits.TNP1
        #define SCIBDH_IREN             _SCIBD.Overlap_STR.SCIASR1STR.SameAddr_STR.SCIBDHSTR.Bits.IREN
        #define SCIBDH_SBR_8            _SCIBD.Overlap_STR.SCIASR1STR.SameAddr_STR.SCIBDHSTR.MergedBits.grpSBR_8
        #define SCIBDH_TNP              _SCIBD.Overlap_STR.SCIASR1STR.SameAddr_STR.SCIBDHSTR.MergedBits.grpTNP
        #define SCIBDH_SBR              SCIBDH_SBR_8
        
        #define SCIBDH_SBR8_MASK        1U
        #define SCIBDH_SBR9_MASK        2U
        #define SCIBDH_SBR10_MASK       4U
        #define SCIBDH_SBR11_MASK       8U
        #define SCIBDH_SBR12_MASK       16U
        #define SCIBDH_TNP0_MASK        32U
        #define SCIBDH_TNP1_MASK        64U
        #define SCIBDH_IREN_MASK        128U
        #define SCIBDH_SBR_8_MASK       31U
        #define SCIBDH_SBR_8_BITNUM     0U
        #define SCIBDH_TNP_MASK         96U
        #define SCIBDH_TNP_BITNUM       5U
        
      } SameAddr_STR; /*Several registers at the same address */
    
    } SCIASR1STR;
    

    /*** SCIACR1 - SCI  Alternative Control Register 1; 0x000000C9 ***/
    union {
      byte Byte;
      union { /* Several registers at the same address */
        /*** SCIACR1 - SCI  Alternative Control Register 1; Several registers at the same address ***/
        union {
          struct {
            byte BKDIE       :1;                                       /* Break Detect Interrupt Enable */
            byte BERRIE      :1;                                       /* Bit Error Interrupt Enable */
            byte             :1; 
            byte             :1; 
            byte             :1; 
            byte             :1; 
            byte             :1; 
            byte RXEDGIE     :1;                                       /* Receive Input Active Edge Interrupt Enable */
          } Bits;
        } SCIACR1STR;
        #define SCIACR1                 _SCIBD.Overlap_STR.SCIACR1STR.Byte
        #define SCIACR1_BKDIE           _SCIBD.Overlap_STR.SCIACR1STR.SameAddr_STR.SCIACR1STR.Bits.BKDIE
        #define SCIACR1_BERRIE          _SCIBD.Overlap_STR.SCIACR1STR.SameAddr_STR.SCIACR1STR.Bits.BERRIE
        #define SCIACR1_RXEDGIE         _SCIBD.Overlap_STR.SCIACR1STR.SameAddr_STR.SCIACR1STR.Bits.RXEDGIE
        
        #define SCIACR1_BKDIE_MASK      1U
        #define SCIACR1_BERRIE_MASK     2U
        #define SCIACR1_RXEDGIE_MASK    128U
        
        /*** SCIBDL - SCI  Baud Rate Register Low; Several registers at the same address ***/
        union {
          struct {
            byte SBR0        :1;                                       /* SCI Baud Rate Bit 0 */
            byte SBR1        :1;                                       /* SCI Baud Rate Bit 1 */
            byte SBR2        :1;                                       /* SCI Baud Rate Bit 2 */
            byte SBR3        :1;                                       /* SCI Baud Rate Bit 3 */
            byte SBR4        :1;                                       /* SCI Baud Rate Bit 4 */
            byte SBR5        :1;                                       /* SCI Baud Rate Bit 5 */
            byte SBR6        :1;                                       /* SCI Baud Rate Bit 6 */
            byte SBR7        :1;                                       /* SCI Baud Rate Bit 7 */
          } Bits;
        } SCIBDLSTR;
        #define SCIBDL                  _SCIBD.Overlap_STR.SCIACR1STR.Byte
        #define SCIBDL_SBR0             _SCIBD.Overlap_STR.SCIACR1STR.SameAddr_STR.SCIBDLSTR.Bits.SBR0
        #define SCIBDL_SBR1             _SCIBD.Overlap_STR.SCIACR1STR.SameAddr_STR.SCIBDLSTR.Bits.SBR1
        #define SCIBDL_SBR2             _SCIBD.Overlap_STR.SCIACR1STR.SameAddr_STR.SCIBDLSTR.Bits.SBR2
        #define SCIBDL_SBR3             _SCIBD.Overlap_STR.SCIACR1STR.SameAddr_STR.SCIBDLSTR.Bits.SBR3
        #define SCIBDL_SBR4             _SCIBD.Overlap_STR.SCIACR1STR.SameAddr_STR.SCIBDLSTR.Bits.SBR4
        #define SCIBDL_SBR5             _SCIBD.Overlap_STR.SCIACR1STR.SameAddr_STR.SCIBDLSTR.Bits.SBR5
        #define SCIBDL_SBR6             _SCIBD.Overlap_STR.SCIACR1STR.SameAddr_STR.SCIBDLSTR.Bits.SBR6
        #define SCIBDL_SBR7             _SCIBD.Overlap_STR.SCIACR1STR.SameAddr_STR.SCIBDLSTR.Bits.SBR7
        
        #define SCIBDL_SBR0_MASK        1U
        #define SCIBDL_SBR1_MASK        2U
        #define SCIBDL_SBR2_MASK        4U
        #define SCIBDL_SBR3_MASK        8U
        #define SCIBDL_SBR4_MASK        16U
        #define SCIBDL_SBR5_MASK        32U
        #define SCIBDL_SBR6_MASK        64U
        #define SCIBDL_SBR7_MASK        128U
        
      } SameAddr_STR; /*Several registers at the same address */
    
    } SCIACR1STR;
    
  } Overlap_STR;

  struct {
    word SBR0        :1;                                       /* SCI Baud Rate Bit 0 */
    word SBR1        :1;                                       /* SCI Baud Rate Bit 1 */
    word SBR2        :1;                                       /* SCI Baud Rate Bit 2 */
    word SBR3        :1;                                       /* SCI Baud Rate Bit 3 */
    word SBR4        :1;                                       /* SCI Baud Rate Bit 4 */
    word SBR5        :1;                                       /* SCI Baud Rate Bit 5 */
    word SBR6        :1;                                       /* SCI Baud Rate Bit 6 */
    word SBR7        :1;                                       /* SCI Baud Rate Bit 7 */
    word SBR8        :1;                                       /* SCI Baud Rate Bit 8 */
    word SBR9        :1;                                       /* SCI Baud Rate Bit 9 */
    word SBR10       :1;                                       /* SCI Baud Rate Bit 10 */
    word SBR11       :1;                                       /* SCI Baud Rate Bit 11 */
    word SBR12       :1;                                       /* SCI Baud Rate Bit 12 */
    word TNP0        :1;                                       /* Transmitter Narrow Pulse Bit 0 */
    word TNP1        :1;                                       /* Transmitter Narrow Pulse Bit 1 */
    word IREN        :1;                                       /* Infrared Enable Bit */
  } Bits;
  struct {
    word grpSBR  :13;
    word grpTNP  :2;
    word         :1;
  } MergedBits;
} SCIBDSTR;
extern volatile SCIBDSTR _SCIBD @(REG_BASE + 0x000000C8UL);
#define SCIBD                           _SCIBD.Word
#define SCIBD_SBR0                      _SCIBD.Bits.SBR0
#define SCIBD_SBR1                      _SCIBD.Bits.SBR1
#define SCIBD_SBR2                      _SCIBD.Bits.SBR2
#define SCIBD_SBR3                      _SCIBD.Bits.SBR3
#define SCIBD_SBR4                      _SCIBD.Bits.SBR4
#define SCIBD_SBR5                      _SCIBD.Bits.SBR5
#define SCIBD_SBR6                      _SCIBD.Bits.SBR6
#define SCIBD_SBR7                      _SCIBD.Bits.SBR7
#define SCIBD_SBR8                      _SCIBD.Bits.SBR8
#define SCIBD_SBR9                      _SCIBD.Bits.SBR9
#define SCIBD_SBR10                     _SCIBD.Bits.SBR10
#define SCIBD_SBR11                     _SCIBD.Bits.SBR11
#define SCIBD_SBR12                     _SCIBD.Bits.SBR12
#define SCIBD_TNP0                      _SCIBD.Bits.TNP0
#define SCIBD_TNP1                      _SCIBD.Bits.TNP1
#define SCIBD_IREN                      _SCIBD.Bits.IREN
#define SCIBD_SBR                       _SCIBD.MergedBits.grpSBR
#define SCIBD_TNP                       _SCIBD.MergedBits.grpTNP

#define SCIBD_SBR0_MASK                 1U
#define SCIBD_SBR1_MASK                 2U
#define SCIBD_SBR2_MASK                 4U
#define SCIBD_SBR3_MASK                 8U
#define SCIBD_SBR4_MASK                 16U
#define SCIBD_SBR5_MASK                 32U
#define SCIBD_SBR6_MASK                 64U
#define SCIBD_SBR7_MASK                 128U
#define SCIBD_SBR8_MASK                 256U
#define SCIBD_SBR9_MASK                 512U
#define SCIBD_SBR10_MASK                1024U
#define SCIBD_SBR11_MASK                2048U
#define SCIBD_SBR12_MASK                4096U
#define SCIBD_TNP0_MASK                 8192U
#define SCIBD_TNP1_MASK                 16384U
#define SCIBD_IREN_MASK                 32768U
#define SCIBD_SBR_MASK                  8191U
#define SCIBD_SBR_BITNUM                0U
#define SCIBD_TNP_MASK                  24576U
#define SCIBD_TNP_BITNUM                13U


/*** SCIACR2 - SCI  Alternative Control Register 2; 0x000000CA ***/
typedef union {
  byte Byte;
  union { /* Several registers at the same address */
    /*** SCIACR2 - SCI  Alternative Control Register 2; Several registers at the same address ***/
    union {
      struct {
        byte BKDFE       :1;                                       /* Break Detect Feature Enable */
        byte BERRM0      :1;                                       /* Bit Error Mode 0 */
        byte BERRM1      :1;                                       /* Bit Error Mode 1 */
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
      } Bits;
      struct {
        byte     :1;
        byte grpBERRM :2;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
      } MergedBits;
    } SCIACR2STR;
    #define SCIACR2                     _SCIACR2.Byte
    #define SCIACR2_BKDFE               _SCIACR2.SameAddr_STR.SCIACR2STR.Bits.BKDFE
    #define SCIACR2_BERRM0              _SCIACR2.SameAddr_STR.SCIACR2STR.Bits.BERRM0
    #define SCIACR2_BERRM1              _SCIACR2.SameAddr_STR.SCIACR2STR.Bits.BERRM1
    #define SCIACR2_BERRM               _SCIACR2.SameAddr_STR.SCIACR2STR.MergedBits.grpBERRM
    
    #define SCIACR2_BKDFE_MASK          1U
    #define SCIACR2_BERRM0_MASK         2U
    #define SCIACR2_BERRM1_MASK         4U
    #define SCIACR2_BERRM_MASK          6U
    #define SCIACR2_BERRM_BITNUM        1U
    
    /*** SCICR1 - SCI  Control Register 1; Several registers at the same address ***/
    union {
      struct {
        byte PT          :1;                                       /* Parity Type Bit */
        byte PE          :1;                                       /* Parity Enable Bit */
        byte ILT         :1;                                       /* Idle Line Type Bit */
        byte WAKE        :1;                                       /* Wakeup Condition Bit */
        byte M           :1;                                       /* Data Format Mode Bit */
        byte RSRC        :1;                                       /* Receiver Source Bit */
        byte SCISWAI     :1;                                       /* SCI Stop in Wait Mode Bit */
        byte LOOPS       :1;                                       /* Loop Select Bit */
      } Bits;
    } SCICR1STR;
    #define SCICR1                      _SCIACR2.Byte
    #define SCICR1_PT                   _SCIACR2.SameAddr_STR.SCICR1STR.Bits.PT
    #define SCICR1_PE                   _SCIACR2.SameAddr_STR.SCICR1STR.Bits.PE
    #define SCICR1_ILT                  _SCIACR2.SameAddr_STR.SCICR1STR.Bits.ILT
    #define SCICR1_WAKE                 _SCIACR2.SameAddr_STR.SCICR1STR.Bits.WAKE
    #define SCICR1_M                    _SCIACR2.SameAddr_STR.SCICR1STR.Bits.M
    #define SCICR1_RSRC                 _SCIACR2.SameAddr_STR.SCICR1STR.Bits.RSRC
    #define SCICR1_SCISWAI              _SCIACR2.SameAddr_STR.SCICR1STR.Bits.SCISWAI
    #define SCICR1_LOOPS                _SCIACR2.SameAddr_STR.SCICR1STR.Bits.LOOPS
    
    #define SCICR1_PT_MASK              1U
    #define SCICR1_PE_MASK              2U
    #define SCICR1_ILT_MASK             4U
    #define SCICR1_WAKE_MASK            8U
    #define SCICR1_M_MASK               16U
    #define SCICR1_RSRC_MASK            32U
    #define SCICR1_SCISWAI_MASK         64U
    #define SCICR1_LOOPS_MASK           128U
    
  } SameAddr_STR; /*Several registers at the same address */

} SCIACR2STR;
extern volatile SCIACR2STR _SCIACR2 @(REG_BASE + 0x000000CAUL);


/*** SCICR2 - SCI  Control Register 2; 0x000000CB ***/
typedef union {
  byte Byte;
  struct {
    byte SBK         :1;                                       /* Send Break Bit */
    byte RWU         :1;                                       /* Receiver Wakeup Bit */
    byte RE          :1;                                       /* Receiver Enable Bit */
    byte TE          :1;                                       /* Transmitter Enable Bit */
    byte ILIE        :1;                                       /* Idle Line Interrupt Enable Bit */
    byte RIE         :1;                                       /* Receiver Full Interrupt Enable Bit */
    byte TCIE        :1;                                       /* Transmission Complete Interrupt Enable Bit */
    byte TIE         :1;                                       /* Transmitter Interrupt Enable Bit */
  } Bits;
} SCICR2STR;
extern volatile SCICR2STR _SCICR2 @(REG_BASE + 0x000000CBUL);
#define SCICR2                          _SCICR2.Byte
#define SCICR2_SBK                      _SCICR2.Bits.SBK
#define SCICR2_RWU                      _SCICR2.Bits.RWU
#define SCICR2_RE                       _SCICR2.Bits.RE
#define SCICR2_TE                       _SCICR2.Bits.TE
#define SCICR2_ILIE                     _SCICR2.Bits.ILIE
#define SCICR2_RIE                      _SCICR2.Bits.RIE
#define SCICR2_TCIE                     _SCICR2.Bits.TCIE
#define SCICR2_TIE                      _SCICR2.Bits.TIE

#define SCICR2_SBK_MASK                 1U
#define SCICR2_RWU_MASK                 2U
#define SCICR2_RE_MASK                  4U
#define SCICR2_TE_MASK                  8U
#define SCICR2_ILIE_MASK                16U
#define SCICR2_RIE_MASK                 32U
#define SCICR2_TCIE_MASK                64U
#define SCICR2_TIE_MASK                 128U


/*** SCISR1 - SCI  Status Register 1; 0x000000CC ***/
typedef union {
  byte Byte;
  struct {
    byte PF          :1;                                       /* Parity Error Flag */
    byte FE          :1;                                       /* Framing Error Flag */
    byte NF          :1;                                       /* Noise Flag */
    byte OR          :1;                                       /* Overrun Flag */
    byte IDLE        :1;                                       /* Idle Line Flag */
    byte RDRF        :1;                                       /* Receive Data Register Full Flag */
    byte TC          :1;                                       /* Transmit Complete Flag */
    byte TDRE        :1;                                       /* Transmit Data Register Empty Flag */
  } Bits;
} SCISR1STR;
extern volatile SCISR1STR _SCISR1 @(REG_BASE + 0x000000CCUL);
#define SCISR1                          _SCISR1.Byte
#define SCISR1_PF                       _SCISR1.Bits.PF
#define SCISR1_FE                       _SCISR1.Bits.FE
#define SCISR1_NF                       _SCISR1.Bits.NF
#define SCISR1_OR                       _SCISR1.Bits.OR
#define SCISR1_IDLE                     _SCISR1.Bits.IDLE
#define SCISR1_RDRF                     _SCISR1.Bits.RDRF
#define SCISR1_TC                       _SCISR1.Bits.TC
#define SCISR1_TDRE                     _SCISR1.Bits.TDRE

#define SCISR1_PF_MASK                  1U
#define SCISR1_FE_MASK                  2U
#define SCISR1_NF_MASK                  4U
#define SCISR1_OR_MASK                  8U
#define SCISR1_IDLE_MASK                16U
#define SCISR1_RDRF_MASK                32U
#define SCISR1_TC_MASK                  64U
#define SCISR1_TDRE_MASK                128U


/*** SCISR2 - SCI  Status Register 2; 0x000000CD ***/
typedef union {
  byte Byte;
  struct {
    byte RAF         :1;                                       /* Receiver Active Flag */
    byte TXDIR       :1;                                       /* Transmitter pin data direction in Single-Wire mode */
    byte BRK13       :1;                                       /* Break Transmit character length */
    byte RXPOL       :1;                                       /* Receive Polarity */
    byte TXPOL       :1;                                       /* Transmit Polarity */
    byte             :1; 
    byte             :1; 
    byte AMAP        :1;                                       /* Alternative Map */
  } Bits;
} SCISR2STR;
extern volatile SCISR2STR _SCISR2 @(REG_BASE + 0x000000CDUL);
#define SCISR2                          _SCISR2.Byte
#define SCISR2_RAF                      _SCISR2.Bits.RAF
#define SCISR2_TXDIR                    _SCISR2.Bits.TXDIR
#define SCISR2_BRK13                    _SCISR2.Bits.BRK13
#define SCISR2_RXPOL                    _SCISR2.Bits.RXPOL
#define SCISR2_TXPOL                    _SCISR2.Bits.TXPOL
#define SCISR2_AMAP                     _SCISR2.Bits.AMAP

#define SCISR2_RAF_MASK                 1U
#define SCISR2_TXDIR_MASK               2U
#define SCISR2_BRK13_MASK               4U
#define SCISR2_RXPOL_MASK               8U
#define SCISR2_TXPOL_MASK               16U
#define SCISR2_AMAP_MASK                128U


/*** SCIDRH - SCI  Data Register High; 0x000000CE ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte T8          :1;                                       /* Transmit Bit 8 */
    byte R8          :1;                                       /* Received Bit 8 */
  } Bits;
} SCIDRHSTR;
extern volatile SCIDRHSTR _SCIDRH @(REG_BASE + 0x000000CEUL);
#define SCIDRH                          _SCIDRH.Byte
#define SCIDRH_T8                       _SCIDRH.Bits.T8
#define SCIDRH_R8                       _SCIDRH.Bits.R8

#define SCIDRH_T8_MASK                  64U
#define SCIDRH_R8_MASK                  128U


/*** SCIDRL - SCI  Data Register Low; 0x000000CF ***/
typedef union {
  byte Byte;
  struct {
    byte R0_T0       :1;                                       /* Received bit 0 or Transmit bit 0 */
    byte R1_T1       :1;                                       /* Received bit 1 or Transmit bit 1 */
    byte R2_T2       :1;                                       /* Received bit 2 or Transmit bit 2 */
    byte R3_T3       :1;                                       /* Received bit 3 or Transmit bit 3 */
    byte R4_T4       :1;                                       /* Received bit 4 or Transmit bit 4 */
    byte R5_T5       :1;                                       /* Received bit 5 or Transmit bit 5 */
    byte R6_T6       :1;                                       /* Received bit 6 or Transmit bit 6 */
    byte R7_T7       :1;                                       /* Received bit 7 or Transmit bit 7 */
  } Bits;
} SCIDRLSTR;
extern volatile SCIDRLSTR _SCIDRL @(REG_BASE + 0x000000CFUL);
#define SCIDRL                          _SCIDRL.Byte
#define SCIDRL_R0_T0                    _SCIDRL.Bits.R0_T0
#define SCIDRL_R1_T1                    _SCIDRL.Bits.R1_T1
#define SCIDRL_R2_T2                    _SCIDRL.Bits.R2_T2
#define SCIDRL_R3_T3                    _SCIDRL.Bits.R3_T3
#define SCIDRL_R4_T4                    _SCIDRL.Bits.R4_T4
#define SCIDRL_R5_T5                    _SCIDRL.Bits.R5_T5
#define SCIDRL_R6_T6                    _SCIDRL.Bits.R6_T6
#define SCIDRL_R7_T7                    _SCIDRL.Bits.R7_T7

#define SCIDRL_R0_T0_MASK               1U
#define SCIDRL_R1_T1_MASK               2U
#define SCIDRL_R2_T2_MASK               4U
#define SCIDRL_R3_T3_MASK               8U
#define SCIDRL_R4_T4_MASK               16U
#define SCIDRL_R5_T5_MASK               32U
#define SCIDRL_R6_T6_MASK               64U
#define SCIDRL_R7_T7_MASK               128U


/*** SPICR1 - SPI  Control Register 1; 0x000000D8 ***/
typedef union {
  byte Byte;
  struct {
    byte LSBFE       :1;                                       /* SPI LSB-First Enable */
    byte SSOE        :1;                                       /* Slave Select Output Enable */
    byte CPHA        :1;                                       /* SPI Clock Phase Bit */
    byte CPOL        :1;                                       /* SPI Clock Polarity Bit */
    byte MSTR        :1;                                       /* SPI Master/Slave Mode Select Bit */
    byte SPTIE       :1;                                       /* SPI Transmit Interrupt Enable */
    byte SPE         :1;                                       /* SPI System Enable Bit */
    byte SPIE        :1;                                       /* SPI Interrupt Enable Bit */
  } Bits;
} SPICR1STR;
extern volatile SPICR1STR _SPICR1 @(REG_BASE + 0x000000D8UL);
#define SPICR1                          _SPICR1.Byte
#define SPICR1_LSBFE                    _SPICR1.Bits.LSBFE
#define SPICR1_SSOE                     _SPICR1.Bits.SSOE
#define SPICR1_CPHA                     _SPICR1.Bits.CPHA
#define SPICR1_CPOL                     _SPICR1.Bits.CPOL
#define SPICR1_MSTR                     _SPICR1.Bits.MSTR
#define SPICR1_SPTIE                    _SPICR1.Bits.SPTIE
#define SPICR1_SPE                      _SPICR1.Bits.SPE
#define SPICR1_SPIE                     _SPICR1.Bits.SPIE

#define SPICR1_LSBFE_MASK               1U
#define SPICR1_SSOE_MASK                2U
#define SPICR1_CPHA_MASK                4U
#define SPICR1_CPOL_MASK                8U
#define SPICR1_MSTR_MASK                16U
#define SPICR1_SPTIE_MASK               32U
#define SPICR1_SPE_MASK                 64U
#define SPICR1_SPIE_MASK                128U


/*** SPICR2 - SPI  Control Register 2; 0x000000D9 ***/
typedef union {
  byte Byte;
  struct {
    byte SPC0        :1;                                       /* Serial Pin Control Bit 0 */
    byte SPISWAI     :1;                                       /* SPI Stop in Wait Mode Bit */
    byte             :1; 
    byte BIDIROE     :1;                                       /* Output enable in the Bidirectional mode of operation */
    byte MODFEN      :1;                                       /* Mode Fault Enable Bit */
    byte             :1; 
    byte XFRW        :1;                                       /* Transfer Width */
    byte             :1; 
  } Bits;
} SPICR2STR;
extern volatile SPICR2STR _SPICR2 @(REG_BASE + 0x000000D9UL);
#define SPICR2                          _SPICR2.Byte
#define SPICR2_SPC0                     _SPICR2.Bits.SPC0
#define SPICR2_SPISWAI                  _SPICR2.Bits.SPISWAI
#define SPICR2_BIDIROE                  _SPICR2.Bits.BIDIROE
#define SPICR2_MODFEN                   _SPICR2.Bits.MODFEN
#define SPICR2_XFRW                     _SPICR2.Bits.XFRW

#define SPICR2_SPC0_MASK                1U
#define SPICR2_SPISWAI_MASK             2U
#define SPICR2_BIDIROE_MASK             8U
#define SPICR2_MODFEN_MASK              16U
#define SPICR2_XFRW_MASK                64U


/*** SPIBR - SPI  Baud Rate Register; 0x000000DA ***/
typedef union {
  byte Byte;
  struct {
    byte SPR0        :1;                                       /* SPI Baud Rate Selection Bit 0 */
    byte SPR1        :1;                                       /* SPI Baud Rate Selection Bit 1 */
    byte SPR2        :1;                                       /* SPI Baud Rate Selection Bit 2 */
    byte             :1; 
    byte SPPR0       :1;                                       /* SPI Baud Rate Preselection Bits 0 */
    byte SPPR1       :1;                                       /* SPI Baud Rate Preselection Bits 1 */
    byte SPPR2       :1;                                       /* SPI Baud Rate Preselection Bits 2 */
    byte             :1; 
  } Bits;
  struct {
    byte grpSPR  :3;
    byte         :1;
    byte grpSPPR :3;
    byte         :1;
  } MergedBits;
} SPIBRSTR;
extern volatile SPIBRSTR _SPIBR @(REG_BASE + 0x000000DAUL);
#define SPIBR                           _SPIBR.Byte
#define SPIBR_SPR0                      _SPIBR.Bits.SPR0
#define SPIBR_SPR1                      _SPIBR.Bits.SPR1
#define SPIBR_SPR2                      _SPIBR.Bits.SPR2
#define SPIBR_SPPR0                     _SPIBR.Bits.SPPR0
#define SPIBR_SPPR1                     _SPIBR.Bits.SPPR1
#define SPIBR_SPPR2                     _SPIBR.Bits.SPPR2
#define SPIBR_SPR                       _SPIBR.MergedBits.grpSPR
#define SPIBR_SPPR                      _SPIBR.MergedBits.grpSPPR

#define SPIBR_SPR0_MASK                 1U
#define SPIBR_SPR1_MASK                 2U
#define SPIBR_SPR2_MASK                 4U
#define SPIBR_SPPR0_MASK                16U
#define SPIBR_SPPR1_MASK                32U
#define SPIBR_SPPR2_MASK                64U
#define SPIBR_SPR_MASK                  7U
#define SPIBR_SPR_BITNUM                0U
#define SPIBR_SPPR_MASK                 112U
#define SPIBR_SPPR_BITNUM               4U


/*** SPISR - SPI  Status Register; 0x000000DB ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte MODF        :1;                                       /* Mode Fault Flag */
    byte SPTEF       :1;                                       /* SPI Transmit Empty Interrupt Flag */
    byte             :1; 
    byte SPIF        :1;                                       /* SPIF Receive Interrupt Flag */
  } Bits;
} SPISRSTR;
extern volatile SPISRSTR _SPISR @(REG_BASE + 0x000000DBUL);
#define SPISR                           _SPISR.Byte
#define SPISR_MODF                      _SPISR.Bits.MODF
#define SPISR_SPTEF                     _SPISR.Bits.SPTEF
#define SPISR_SPIF                      _SPISR.Bits.SPIF

#define SPISR_MODF_MASK                 16U
#define SPISR_SPTEF_MASK                32U
#define SPISR_SPIF_MASK                 128U


/*** SPIDR - SPI  Data Register; 0x000000DC ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** SPIDRH - SPI  Data Register High; 0x000000DC ***/
    union {
      byte Byte;
      struct {
        byte R8_T8       :1;                                       /* SPI  Data Bit 8 */
        byte R9_T9       :1;                                       /* SPI  Data Bit 9 */
        byte R10_T10     :1;                                       /* SPI  Data Bit 10 */
        byte R11_T11     :1;                                       /* SPI  Data Bit 11 */
        byte R12_T12     :1;                                       /* SPI  Data Bit 12 */
        byte R13_T13     :1;                                       /* SPI  Data Bit 13 */
        byte R14_T14     :1;                                       /* SPI  Data Bit 14 */
        byte R15_T15     :1;                                       /* SPI  Data Bit 15 */
      } Bits;
    } SPIDRHSTR;
    #define SPIDRH                      _SPIDR.Overlap_STR.SPIDRHSTR.Byte
    #define SPIDRH_R8_T8                _SPIDR.Overlap_STR.SPIDRHSTR.Bits.R8_T8
    #define SPIDRH_R9_T9                _SPIDR.Overlap_STR.SPIDRHSTR.Bits.R9_T9
    #define SPIDRH_R10_T10              _SPIDR.Overlap_STR.SPIDRHSTR.Bits.R10_T10
    #define SPIDRH_R11_T11              _SPIDR.Overlap_STR.SPIDRHSTR.Bits.R11_T11
    #define SPIDRH_R12_T12              _SPIDR.Overlap_STR.SPIDRHSTR.Bits.R12_T12
    #define SPIDRH_R13_T13              _SPIDR.Overlap_STR.SPIDRHSTR.Bits.R13_T13
    #define SPIDRH_R14_T14              _SPIDR.Overlap_STR.SPIDRHSTR.Bits.R14_T14
    #define SPIDRH_R15_T15              _SPIDR.Overlap_STR.SPIDRHSTR.Bits.R15_T15
    
    #define SPIDRH_R8_T8_MASK           1U
    #define SPIDRH_R9_T9_MASK           2U
    #define SPIDRH_R10_T10_MASK         4U
    #define SPIDRH_R11_T11_MASK         8U
    #define SPIDRH_R12_T12_MASK         16U
    #define SPIDRH_R13_T13_MASK         32U
    #define SPIDRH_R14_T14_MASK         64U
    #define SPIDRH_R15_T15_MASK         128U
    

    /*** SPIDRL - SPI  Data Register Low; 0x000000DD ***/
    union {
      byte Byte;
      struct {
        byte R0_T0       :1;                                       /* SPI  Data Bit 0 */
        byte R1_T1       :1;                                       /* SPI  Data Bit 1 */
        byte R2_T2       :1;                                       /* SPI  Data Bit 2 */
        byte R3_T3       :1;                                       /* SPI  Data Bit 3 */
        byte R4_T4       :1;                                       /* SPI  Data Bit 4 */
        byte R5_T5       :1;                                       /* SPI  Data Bit 5 */
        byte R6_T6       :1;                                       /* SPI  Data Bit 6 */
        byte R7_T7       :1;                                       /* SPI  Data Bit 7 */
      } Bits;
    } SPIDRLSTR;
    #define SPIDRL                      _SPIDR.Overlap_STR.SPIDRLSTR.Byte
    #define SPIDRL_R0_T0                _SPIDR.Overlap_STR.SPIDRLSTR.Bits.R0_T0
    #define SPIDRL_R1_T1                _SPIDR.Overlap_STR.SPIDRLSTR.Bits.R1_T1
    #define SPIDRL_R2_T2                _SPIDR.Overlap_STR.SPIDRLSTR.Bits.R2_T2
    #define SPIDRL_R3_T3                _SPIDR.Overlap_STR.SPIDRLSTR.Bits.R3_T3
    #define SPIDRL_R4_T4                _SPIDR.Overlap_STR.SPIDRLSTR.Bits.R4_T4
    #define SPIDRL_R5_T5                _SPIDR.Overlap_STR.SPIDRLSTR.Bits.R5_T5
    #define SPIDRL_R6_T6                _SPIDR.Overlap_STR.SPIDRLSTR.Bits.R6_T6
    #define SPIDRL_R7_T7                _SPIDR.Overlap_STR.SPIDRLSTR.Bits.R7_T7
    
    #define SPIDRL_R0_T0_MASK           1U
    #define SPIDRL_R1_T1_MASK           2U
    #define SPIDRL_R2_T2_MASK           4U
    #define SPIDRL_R3_T3_MASK           8U
    #define SPIDRL_R4_T4_MASK           16U
    #define SPIDRL_R5_T5_MASK           32U
    #define SPIDRL_R6_T6_MASK           64U
    #define SPIDRL_R7_T7_MASK           128U
    
  } Overlap_STR;

  struct {
    word R0_T0       :1;                                       /* SPI  Data Bit 0 */
    word R1_T1       :1;                                       /* SPI  Data Bit 1 */
    word R2_T2       :1;                                       /* SPI  Data Bit 2 */
    word R3_T3       :1;                                       /* SPI  Data Bit 3 */
    word R4_T4       :1;                                       /* SPI  Data Bit 4 */
    word R5_T5       :1;                                       /* SPI  Data Bit 5 */
    word R6_T6       :1;                                       /* SPI  Data Bit 6 */
    word R7_T7       :1;                                       /* SPI  Data Bit 7 */
    word R8_T8       :1;                                       /* SPI  Data Bit 8 */
    word R9_T9       :1;                                       /* SPI  Data Bit 9 */
    word R10_T10     :1;                                       /* SPI  Data Bit 10 */
    word R11_T11     :1;                                       /* SPI  Data Bit 11 */
    word R12_T12     :1;                                       /* SPI  Data Bit 12 */
    word R13_T13     :1;                                       /* SPI  Data Bit 13 */
    word R14_T14     :1;                                       /* SPI  Data Bit 14 */
    word R15_T15     :1;                                       /* SPI  Data Bit 15 */
  } Bits;
} SPIDRSTR;
extern volatile SPIDRSTR _SPIDR @(REG_BASE + 0x000000DCUL);
#define SPIDR                           _SPIDR.Word
#define SPIDR_R0_T0                     _SPIDR.Bits.R0_T0
#define SPIDR_R1_T1                     _SPIDR.Bits.R1_T1
#define SPIDR_R2_T2                     _SPIDR.Bits.R2_T2
#define SPIDR_R3_T3                     _SPIDR.Bits.R3_T3
#define SPIDR_R4_T4                     _SPIDR.Bits.R4_T4
#define SPIDR_R5_T5                     _SPIDR.Bits.R5_T5
#define SPIDR_R6_T6                     _SPIDR.Bits.R6_T6
#define SPIDR_R7_T7                     _SPIDR.Bits.R7_T7
#define SPIDR_R8_T8                     _SPIDR.Bits.R8_T8
#define SPIDR_R9_T9                     _SPIDR.Bits.R9_T9
#define SPIDR_R10_T10                   _SPIDR.Bits.R10_T10
#define SPIDR_R11_T11                   _SPIDR.Bits.R11_T11
#define SPIDR_R12_T12                   _SPIDR.Bits.R12_T12
#define SPIDR_R13_T13                   _SPIDR.Bits.R13_T13
#define SPIDR_R14_T14                   _SPIDR.Bits.R14_T14
#define SPIDR_R15_T15                   _SPIDR.Bits.R15_T15

#define SPIDR_R0_T0_MASK                1U
#define SPIDR_R1_T1_MASK                2U
#define SPIDR_R2_T2_MASK                4U
#define SPIDR_R3_T3_MASK                8U
#define SPIDR_R4_T4_MASK                16U
#define SPIDR_R5_T5_MASK                32U
#define SPIDR_R6_T6_MASK                64U
#define SPIDR_R7_T7_MASK                128U
#define SPIDR_R8_T8_MASK                256U
#define SPIDR_R9_T9_MASK                512U
#define SPIDR_R10_T10_MASK              1024U
#define SPIDR_R11_T11_MASK              2048U
#define SPIDR_R12_T12_MASK              4096U
#define SPIDR_R13_T13_MASK              8192U
#define SPIDR_R14_T14_MASK              16384U
#define SPIDR_R15_T15_MASK              32768U


/*** IIC_IBAD - IIC Address Register; 0x000000E0 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte ADR1        :1;                                       /* Slave Address Bit 1 */
    byte ADR2        :1;                                       /* Slave Address Bit 2 */
    byte ADR3        :1;                                       /* Slave Address Bit 3 */
    byte ADR4        :1;                                       /* Slave Address Bit 4 */
    byte ADR5        :1;                                       /* Slave Address Bit 5 */
    byte ADR6        :1;                                       /* Slave Address Bit 6 */
    byte ADR7        :1;                                       /* Slave Address Bit 7 */
  } Bits;
  struct {
    byte         :1;
    byte grpADR_1 :7;
  } MergedBits;
} IIC_IBADSTR;
extern volatile IIC_IBADSTR _IIC_IBAD @(REG_BASE + 0x000000E0UL);
#define IIC_IBAD                        _IIC_IBAD.Byte
#define IIC_IBAD_ADR1                   _IIC_IBAD.Bits.ADR1
#define IIC_IBAD_ADR2                   _IIC_IBAD.Bits.ADR2
#define IIC_IBAD_ADR3                   _IIC_IBAD.Bits.ADR3
#define IIC_IBAD_ADR4                   _IIC_IBAD.Bits.ADR4
#define IIC_IBAD_ADR5                   _IIC_IBAD.Bits.ADR5
#define IIC_IBAD_ADR6                   _IIC_IBAD.Bits.ADR6
#define IIC_IBAD_ADR7                   _IIC_IBAD.Bits.ADR7
#define IIC_IBAD_ADR_1                  _IIC_IBAD.MergedBits.grpADR_1
#define IIC_IBAD_ADR                    IIC_IBAD_ADR_1

#define IIC_IBAD_ADR1_MASK              2U
#define IIC_IBAD_ADR2_MASK              4U
#define IIC_IBAD_ADR3_MASK              8U
#define IIC_IBAD_ADR4_MASK              16U
#define IIC_IBAD_ADR5_MASK              32U
#define IIC_IBAD_ADR6_MASK              64U
#define IIC_IBAD_ADR7_MASK              128U
#define IIC_IBAD_ADR_1_MASK             254U
#define IIC_IBAD_ADR_1_BITNUM           1U


/*** IIC_IBFD - IIC Frequency Divider Register; 0x000000E1 ***/
typedef union {
  byte Byte;
  struct {
    byte IBC0        :1;                                       /* I-Bus Clock Rate 0 */
    byte IBC1        :1;                                       /* I-Bus Clock Rate 1 */
    byte IBC2        :1;                                       /* I-Bus Clock Rate 2 */
    byte IBC3        :1;                                       /* I-Bus Clock Rate 3 */
    byte IBC4        :1;                                       /* I-Bus Clock Rate 4 */
    byte IBC5        :1;                                       /* I-Bus Clock Rate 5 */
    byte IBC6        :1;                                       /* I-Bus Clock Rate 6 */
    byte IBC7        :1;                                       /* I-Bus Clock Rate 7 */
  } Bits;
} IIC_IBFDSTR;
extern volatile IIC_IBFDSTR _IIC_IBFD @(REG_BASE + 0x000000E1UL);
#define IIC_IBFD                        _IIC_IBFD.Byte
#define IIC_IBFD_IBC0                   _IIC_IBFD.Bits.IBC0
#define IIC_IBFD_IBC1                   _IIC_IBFD.Bits.IBC1
#define IIC_IBFD_IBC2                   _IIC_IBFD.Bits.IBC2
#define IIC_IBFD_IBC3                   _IIC_IBFD.Bits.IBC3
#define IIC_IBFD_IBC4                   _IIC_IBFD.Bits.IBC4
#define IIC_IBFD_IBC5                   _IIC_IBFD.Bits.IBC5
#define IIC_IBFD_IBC6                   _IIC_IBFD.Bits.IBC6
#define IIC_IBFD_IBC7                   _IIC_IBFD.Bits.IBC7

#define IIC_IBFD_IBC0_MASK              1U
#define IIC_IBFD_IBC1_MASK              2U
#define IIC_IBFD_IBC2_MASK              4U
#define IIC_IBFD_IBC3_MASK              8U
#define IIC_IBFD_IBC4_MASK              16U
#define IIC_IBFD_IBC5_MASK              32U
#define IIC_IBFD_IBC6_MASK              64U
#define IIC_IBFD_IBC7_MASK              128U


/*** IIC_IBCR - IIC Control Register; 0x000000E2 ***/
typedef union {
  byte Byte;
  struct {
    byte IBSWAI      :1;                                       /* I-Bus Interface Stop in WAIT mode */
    byte             :1; 
    byte RSTA        :1;                                       /* Repeat Start */
    byte TXAK        :1;                                       /* Transmit Acknowledge enable */
    byte TX_RX       :1;                                       /* Transmit/Receive mode select bit */
    byte MS_SL       :1;                                       /* Master/Slave mode select bit */
    byte IBIE        :1;                                       /* I-Bus Interrupt Enable */
    byte IBEN        :1;                                       /* I-Bus Enable */
  } Bits;
} IIC_IBCRSTR;
extern volatile IIC_IBCRSTR _IIC_IBCR @(REG_BASE + 0x000000E2UL);
#define IIC_IBCR                        _IIC_IBCR.Byte
#define IIC_IBCR_IBSWAI                 _IIC_IBCR.Bits.IBSWAI
#define IIC_IBCR_RSTA                   _IIC_IBCR.Bits.RSTA
#define IIC_IBCR_TXAK                   _IIC_IBCR.Bits.TXAK
#define IIC_IBCR_TX_RX                  _IIC_IBCR.Bits.TX_RX
#define IIC_IBCR_MS_SL                  _IIC_IBCR.Bits.MS_SL
#define IIC_IBCR_IBIE                   _IIC_IBCR.Bits.IBIE
#define IIC_IBCR_IBEN                   _IIC_IBCR.Bits.IBEN

#define IIC_IBCR_IBSWAI_MASK            1U
#define IIC_IBCR_RSTA_MASK              4U
#define IIC_IBCR_TXAK_MASK              8U
#define IIC_IBCR_TX_RX_MASK             16U
#define IIC_IBCR_MS_SL_MASK             32U
#define IIC_IBCR_IBIE_MASK              64U
#define IIC_IBCR_IBEN_MASK              128U


/*** IIC_IBSR - IIC Status Register; 0x000000E3 ***/
typedef union {
  byte Byte;
  struct {
    byte RXAK        :1;                                       /* Received Acknowledge */
    byte IBIF        :1;                                       /* I-Bus Interrupt */
    byte SRW         :1;                                       /* Slave Read/Write */
    byte             :1; 
    byte IBAL        :1;                                       /* Arbitration Lost */
    byte IBB         :1;                                       /* Bus busy bit */
    byte IAAS        :1;                                       /* Addressed as a slave bit */
    byte TCF         :1;                                       /* Data transferring bit */
  } Bits;
} IIC_IBSRSTR;
extern volatile IIC_IBSRSTR _IIC_IBSR @(REG_BASE + 0x000000E3UL);
#define IIC_IBSR                        _IIC_IBSR.Byte
#define IIC_IBSR_RXAK                   _IIC_IBSR.Bits.RXAK
#define IIC_IBSR_IBIF                   _IIC_IBSR.Bits.IBIF
#define IIC_IBSR_SRW                    _IIC_IBSR.Bits.SRW
#define IIC_IBSR_IBAL                   _IIC_IBSR.Bits.IBAL
#define IIC_IBSR_IBB                    _IIC_IBSR.Bits.IBB
#define IIC_IBSR_IAAS                   _IIC_IBSR.Bits.IAAS
#define IIC_IBSR_TCF                    _IIC_IBSR.Bits.TCF

#define IIC_IBSR_RXAK_MASK              1U
#define IIC_IBSR_IBIF_MASK              2U
#define IIC_IBSR_SRW_MASK               4U
#define IIC_IBSR_IBAL_MASK              16U
#define IIC_IBSR_IBB_MASK               32U
#define IIC_IBSR_IAAS_MASK              64U
#define IIC_IBSR_TCF_MASK               128U


/*** IIC_IBDR - IIC Data I/O Register; 0x000000E4 ***/
typedef union {
  byte Byte;
  struct {
    byte D0          :1;                                       /* IIC Data Bit 0 */
    byte D1          :1;                                       /* IIC Data Bit 1 */
    byte D2          :1;                                       /* IIC Data Bit 2 */
    byte D3          :1;                                       /* IIC Data Bit 3 */
    byte D4          :1;                                       /* IIC Data Bit 4 */
    byte D5          :1;                                       /* IIC Data Bit 5 */
    byte D6          :1;                                       /* IIC Data Bit 6 */
    byte D7          :1;                                       /* IIC Data Bit 7 */
  } Bits;
} IIC_IBDRSTR;
extern volatile IIC_IBDRSTR _IIC_IBDR @(REG_BASE + 0x000000E4UL);
#define IIC_IBDR                        _IIC_IBDR.Byte
#define IIC_IBDR_D0                     _IIC_IBDR.Bits.D0
#define IIC_IBDR_D1                     _IIC_IBDR.Bits.D1
#define IIC_IBDR_D2                     _IIC_IBDR.Bits.D2
#define IIC_IBDR_D3                     _IIC_IBDR.Bits.D3
#define IIC_IBDR_D4                     _IIC_IBDR.Bits.D4
#define IIC_IBDR_D5                     _IIC_IBDR.Bits.D5
#define IIC_IBDR_D6                     _IIC_IBDR.Bits.D6
#define IIC_IBDR_D7                     _IIC_IBDR.Bits.D7

#define IIC_IBDR_D0_MASK                1U
#define IIC_IBDR_D1_MASK                2U
#define IIC_IBDR_D2_MASK                4U
#define IIC_IBDR_D3_MASK                8U
#define IIC_IBDR_D4_MASK                16U
#define IIC_IBDR_D5_MASK                32U
#define IIC_IBDR_D6_MASK                64U
#define IIC_IBDR_D7_MASK                128U


/*** IIC_IBCR2 - IIC Control Register 2; 0x000000E5 ***/
typedef union {
  byte Byte;
  struct {
    byte ADR8        :1;                                       /* Slave Address Bit 8 */
    byte ADR9        :1;                                       /* Slave Address Bit 9 */
    byte ADR10       :1;                                       /* Slave Address Bit 10 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte ADTYPE      :1;                                       /* Address Type */
    byte GCEN        :1;                                       /* General Call Enable */
  } Bits;
  struct {
    byte grpADR_8 :3;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} IIC_IBCR2STR;
extern volatile IIC_IBCR2STR _IIC_IBCR2 @(REG_BASE + 0x000000E5UL);
#define IIC_IBCR2                       _IIC_IBCR2.Byte
#define IIC_IBCR2_ADR8                  _IIC_IBCR2.Bits.ADR8
#define IIC_IBCR2_ADR9                  _IIC_IBCR2.Bits.ADR9
#define IIC_IBCR2_ADR10                 _IIC_IBCR2.Bits.ADR10
#define IIC_IBCR2_ADTYPE                _IIC_IBCR2.Bits.ADTYPE
#define IIC_IBCR2_GCEN                  _IIC_IBCR2.Bits.GCEN
#define IIC_IBCR2_ADR_8                 _IIC_IBCR2.MergedBits.grpADR_8
#define IIC_IBCR2_ADR                   IIC_IBCR2_ADR_8

#define IIC_IBCR2_ADR8_MASK             1U
#define IIC_IBCR2_ADR9_MASK             2U
#define IIC_IBCR2_ADR10_MASK            4U
#define IIC_IBCR2_ADTYPE_MASK           64U
#define IIC_IBCR2_GCEN_MASK             128U
#define IIC_IBCR2_ADR_8_MASK            7U
#define IIC_IBCR2_ADR_8_BITNUM          0U


/*** FCLKDIV - Flash Clock Divider Register; 0x00000100 ***/
typedef union {
  byte Byte;
  struct {
    byte FDIV0       :1;                                       /* Clock Divider Bit 0 */
    byte FDIV1       :1;                                       /* Clock Divider Bit 1 */
    byte FDIV2       :1;                                       /* Clock Divider Bit 2 */
    byte FDIV3       :1;                                       /* Clock Divider Bit 3 */
    byte FDIV4       :1;                                       /* Clock Divider Bit 4 */
    byte FDIV5       :1;                                       /* Clock Divider Bit 5 */
    byte FDIVLCK     :1;                                       /* Clock divider locked */
    byte FDIVLD      :1;                                       /* Clock Divider Loaded */
  } Bits;
  struct {
    byte grpFDIV :6;
    byte         :1;
    byte         :1;
  } MergedBits;
} FCLKDIVSTR;
extern volatile FCLKDIVSTR _FCLKDIV @(REG_BASE + 0x00000100UL);
#define FCLKDIV                         _FCLKDIV.Byte
#define FCLKDIV_FDIV0                   _FCLKDIV.Bits.FDIV0
#define FCLKDIV_FDIV1                   _FCLKDIV.Bits.FDIV1
#define FCLKDIV_FDIV2                   _FCLKDIV.Bits.FDIV2
#define FCLKDIV_FDIV3                   _FCLKDIV.Bits.FDIV3
#define FCLKDIV_FDIV4                   _FCLKDIV.Bits.FDIV4
#define FCLKDIV_FDIV5                   _FCLKDIV.Bits.FDIV5
#define FCLKDIV_FDIVLCK                 _FCLKDIV.Bits.FDIVLCK
#define FCLKDIV_FDIVLD                  _FCLKDIV.Bits.FDIVLD
#define FCLKDIV_FDIV                    _FCLKDIV.MergedBits.grpFDIV

#define FCLKDIV_FDIV0_MASK              1U
#define FCLKDIV_FDIV1_MASK              2U
#define FCLKDIV_FDIV2_MASK              4U
#define FCLKDIV_FDIV3_MASK              8U
#define FCLKDIV_FDIV4_MASK              16U
#define FCLKDIV_FDIV5_MASK              32U
#define FCLKDIV_FDIVLCK_MASK            64U
#define FCLKDIV_FDIVLD_MASK             128U
#define FCLKDIV_FDIV_MASK               63U
#define FCLKDIV_FDIV_BITNUM             0U


/*** FSEC - Flash Security Register; 0x00000101 ***/
typedef union {
  byte Byte;
  struct {
    byte SEC0        :1;                                       /* Flash Security Bit 0 */
    byte SEC1        :1;                                       /* Flash Security Bit 1 */
    byte RNV2        :1;                                       /* Reserved Nonvolatile Bit 2 */
    byte RNV3        :1;                                       /* Reserved Nonvolatile Bit 3 */
    byte RNV4        :1;                                       /* Reserved Nonvolatile Bit 4 */
    byte RNV5        :1;                                       /* Reserved Nonvolatile Bit 5 */
    byte KEYEN0      :1;                                       /* Backdoor Key Security Enable Bit 0 */
    byte KEYEN1      :1;                                       /* Backdoor Key Security Enable Bit 1 */
  } Bits;
  struct {
    byte grpSEC  :2;
    byte grpRNV_2 :4;
    byte grpKEYEN :2;
  } MergedBits;
} FSECSTR;
extern volatile FSECSTR _FSEC @(REG_BASE + 0x00000101UL);
#define FSEC                            _FSEC.Byte
#define FSEC_SEC0                       _FSEC.Bits.SEC0
#define FSEC_SEC1                       _FSEC.Bits.SEC1
#define FSEC_RNV2                       _FSEC.Bits.RNV2
#define FSEC_RNV3                       _FSEC.Bits.RNV3
#define FSEC_RNV4                       _FSEC.Bits.RNV4
#define FSEC_RNV5                       _FSEC.Bits.RNV5
#define FSEC_KEYEN0                     _FSEC.Bits.KEYEN0
#define FSEC_KEYEN1                     _FSEC.Bits.KEYEN1
#define FSEC_SEC                        _FSEC.MergedBits.grpSEC
#define FSEC_RNV_2                      _FSEC.MergedBits.grpRNV_2
#define FSEC_KEYEN                      _FSEC.MergedBits.grpKEYEN
#define FSEC_RNV                        FSEC_RNV_2

#define FSEC_SEC0_MASK                  1U
#define FSEC_SEC1_MASK                  2U
#define FSEC_RNV2_MASK                  4U
#define FSEC_RNV3_MASK                  8U
#define FSEC_RNV4_MASK                  16U
#define FSEC_RNV5_MASK                  32U
#define FSEC_KEYEN0_MASK                64U
#define FSEC_KEYEN1_MASK                128U
#define FSEC_SEC_MASK                   3U
#define FSEC_SEC_BITNUM                 0U
#define FSEC_RNV_2_MASK                 60U
#define FSEC_RNV_2_BITNUM               2U
#define FSEC_KEYEN_MASK                 192U
#define FSEC_KEYEN_BITNUM               6U


/*** FCCOBIX - Flash CCOB Index Register; 0x00000102 ***/
typedef union {
  byte Byte;
  struct {
    byte CCOBIX0     :1;                                       /* Common Command Register Index Bit 0 */
    byte CCOBIX1     :1;                                       /* Common Command Register Index Bit 1 */
    byte CCOBIX2     :1;                                       /* Common Command Register Index Bit 2 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpCCOBIX :3;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} FCCOBIXSTR;
extern volatile FCCOBIXSTR _FCCOBIX @(REG_BASE + 0x00000102UL);
#define FCCOBIX                         _FCCOBIX.Byte
#define FCCOBIX_CCOBIX0                 _FCCOBIX.Bits.CCOBIX0
#define FCCOBIX_CCOBIX1                 _FCCOBIX.Bits.CCOBIX1
#define FCCOBIX_CCOBIX2                 _FCCOBIX.Bits.CCOBIX2
#define FCCOBIX_CCOBIX                  _FCCOBIX.MergedBits.grpCCOBIX

#define FCCOBIX_CCOBIX0_MASK            1U
#define FCCOBIX_CCOBIX1_MASK            2U
#define FCCOBIX_CCOBIX2_MASK            4U
#define FCCOBIX_CCOBIX_MASK             7U
#define FCCOBIX_CCOBIX_BITNUM           0U


/*** FCNFG - Flash Configuration Register; 0x00000104 ***/
typedef union {
  byte Byte;
  struct {
    byte FSFD        :1;                                       /* Force Single Bit Fault Detect */
    byte FDFD        :1;                                       /* Force Double Bit Fault Detect */
    byte             :1; 
    byte             :1; 
    byte IGNSF       :1;                                       /* Ignore Single Bit Fault */
    byte             :1; 
    byte             :1; 
    byte CCIE        :1;                                       /* Command Complete Interrupt Enable */
  } Bits;
} FCNFGSTR;
extern volatile FCNFGSTR _FCNFG @(REG_BASE + 0x00000104UL);
#define FCNFG                           _FCNFG.Byte
#define FCNFG_FSFD                      _FCNFG.Bits.FSFD
#define FCNFG_FDFD                      _FCNFG.Bits.FDFD
#define FCNFG_IGNSF                     _FCNFG.Bits.IGNSF
#define FCNFG_CCIE                      _FCNFG.Bits.CCIE

#define FCNFG_FSFD_MASK                 1U
#define FCNFG_FDFD_MASK                 2U
#define FCNFG_IGNSF_MASK                16U
#define FCNFG_CCIE_MASK                 128U


/*** FERCNFG - Flash Error Configuration Register; 0x00000105 ***/
typedef union {
  byte Byte;
  struct {
    byte SFDIE       :1;                                       /* Single Bit Fault Detect Interrupt Enable */
    byte DFDIE       :1;                                       /* Double Bit Fault Detect Interrupt Enable */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} FERCNFGSTR;
extern volatile FERCNFGSTR _FERCNFG @(REG_BASE + 0x00000105UL);
#define FERCNFG                         _FERCNFG.Byte
#define FERCNFG_SFDIE                   _FERCNFG.Bits.SFDIE
#define FERCNFG_DFDIE                   _FERCNFG.Bits.DFDIE

#define FERCNFG_SFDIE_MASK              1U
#define FERCNFG_DFDIE_MASK              2U


/*** FSTAT - Flash Status Register; 0x00000106 ***/
typedef union {
  byte Byte;
  struct {
    byte MGSTAT0     :1;                                       /* Memory Controller Command Completion Status Flag 0 */
    byte MGSTAT1     :1;                                       /* Memory Controller Command Completion Status Flag 1 */
    byte             :1; 
    byte MGBUSY      :1;                                       /* Memory Controller Busy Flag */
    byte FPVIOL      :1;                                       /* Flash Protection Violation Flag */
    byte ACCERR      :1;                                       /* Flash Access Error Flag */
    byte             :1; 
    byte CCIF        :1;                                       /* Command Complete Interrupt Flag */
  } Bits;
  struct {
    byte grpMGSTAT :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} FSTATSTR;
extern volatile FSTATSTR _FSTAT @(REG_BASE + 0x00000106UL);
#define FSTAT                           _FSTAT.Byte
#define FSTAT_MGSTAT0                   _FSTAT.Bits.MGSTAT0
#define FSTAT_MGSTAT1                   _FSTAT.Bits.MGSTAT1
#define FSTAT_MGBUSY                    _FSTAT.Bits.MGBUSY
#define FSTAT_FPVIOL                    _FSTAT.Bits.FPVIOL
#define FSTAT_ACCERR                    _FSTAT.Bits.ACCERR
#define FSTAT_CCIF                      _FSTAT.Bits.CCIF
#define FSTAT_MGSTAT                    _FSTAT.MergedBits.grpMGSTAT

#define FSTAT_MGSTAT0_MASK              1U
#define FSTAT_MGSTAT1_MASK              2U
#define FSTAT_MGBUSY_MASK               8U
#define FSTAT_FPVIOL_MASK               16U
#define FSTAT_ACCERR_MASK               32U
#define FSTAT_CCIF_MASK                 128U
#define FSTAT_MGSTAT_MASK               3U
#define FSTAT_MGSTAT_BITNUM             0U


/*** FERSTAT - Flash Error Status Register; 0x00000107 ***/
typedef union {
  byte Byte;
  struct {
    byte SFDIF       :1;                                       /* Single Bit Fault Detect Interrupt Flag */
    byte DFDIF       :1;                                       /* Double Bit Fault Detect Interrupt Flag */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} FERSTATSTR;
extern volatile FERSTATSTR _FERSTAT @(REG_BASE + 0x00000107UL);
#define FERSTAT                         _FERSTAT.Byte
#define FERSTAT_SFDIF                   _FERSTAT.Bits.SFDIF
#define FERSTAT_DFDIF                   _FERSTAT.Bits.DFDIF

#define FERSTAT_SFDIF_MASK              1U
#define FERSTAT_DFDIF_MASK              2U


/*** FPROT - P-Flash Protection Register; 0x00000108 ***/
typedef union {
  byte Byte;
  struct {
    byte FPLS0       :1;                                       /* Flash Protection Lower Address Size Bit 0 */
    byte FPLS1       :1;                                       /* Flash Protection Lower Address Size Bit 1 */
    byte FPLDIS      :1;                                       /* Flash Protection Lower Address Range Disable */
    byte FPHS0       :1;                                       /* Flash Protection Higher Address Size Bit 0 */
    byte FPHS1       :1;                                       /* Flash Protection Higher Address Size Bit 1 */
    byte FPHDIS      :1;                                       /* Flash Protection Higher Address Range Disable */
    byte RNV6        :1;                                       /* Reserved Nonvolatile Bit */
    byte FPOPEN      :1;                                       /* Flash Protection Operation Enable */
  } Bits;
  struct {
    byte grpFPLS :2;
    byte         :1;
    byte grpFPHS :2;
    byte         :1;
    byte grpRNV_6 :1;
    byte         :1;
  } MergedBits;
} FPROTSTR;
extern volatile FPROTSTR _FPROT @(REG_BASE + 0x00000108UL);
#define FPROT                           _FPROT.Byte
#define FPROT_FPLS0                     _FPROT.Bits.FPLS0
#define FPROT_FPLS1                     _FPROT.Bits.FPLS1
#define FPROT_FPLDIS                    _FPROT.Bits.FPLDIS
#define FPROT_FPHS0                     _FPROT.Bits.FPHS0
#define FPROT_FPHS1                     _FPROT.Bits.FPHS1
#define FPROT_FPHDIS                    _FPROT.Bits.FPHDIS
#define FPROT_RNV6                      _FPROT.Bits.RNV6
#define FPROT_FPOPEN                    _FPROT.Bits.FPOPEN
#define FPROT_FPLS                      _FPROT.MergedBits.grpFPLS
#define FPROT_FPHS                      _FPROT.MergedBits.grpFPHS

#define FPROT_FPLS0_MASK                1U
#define FPROT_FPLS1_MASK                2U
#define FPROT_FPLDIS_MASK               4U
#define FPROT_FPHS0_MASK                8U
#define FPROT_FPHS1_MASK                16U
#define FPROT_FPHDIS_MASK               32U
#define FPROT_RNV6_MASK                 64U
#define FPROT_FPOPEN_MASK               128U
#define FPROT_FPLS_MASK                 3U
#define FPROT_FPLS_BITNUM               0U
#define FPROT_FPHS_MASK                 24U
#define FPROT_FPHS_BITNUM               3U


/*** DFPROT - D-Flash Protection Register; 0x00000109 ***/
typedef union {
  byte Byte;
  struct {
    byte DPS0        :1;                                       /* D-Flash Protection Size Bit 0 */
    byte DPS1        :1;                                       /* D-Flash Protection Size Bit 1 */
    byte DPS2        :1;                                       /* D-Flash Protection Size Bit 2 */
    byte DPS3        :1;                                       /* D-Flash Protection Size Bit 3 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte DPOPEN      :1;                                       /* D-Flash Protection Control */
  } Bits;
  struct {
    byte grpDPS  :4;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} DFPROTSTR;
extern volatile DFPROTSTR _DFPROT @(REG_BASE + 0x00000109UL);
#define DFPROT                          _DFPROT.Byte
#define DFPROT_DPS0                     _DFPROT.Bits.DPS0
#define DFPROT_DPS1                     _DFPROT.Bits.DPS1
#define DFPROT_DPS2                     _DFPROT.Bits.DPS2
#define DFPROT_DPS3                     _DFPROT.Bits.DPS3
#define DFPROT_DPOPEN                   _DFPROT.Bits.DPOPEN
#define DFPROT_DPS                      _DFPROT.MergedBits.grpDPS

#define DFPROT_DPS0_MASK                1U
#define DFPROT_DPS1_MASK                2U
#define DFPROT_DPS2_MASK                4U
#define DFPROT_DPS3_MASK                8U
#define DFPROT_DPOPEN_MASK              128U
#define DFPROT_DPS_MASK                 15U
#define DFPROT_DPS_BITNUM               0U


/*** FCCOB - Flash Common Command Object Register; 0x0000010A ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** FCCOBHI - Flash Common Command Object Register High; 0x0000010A ***/
    union {
      byte Byte;
      struct {
        byte CCOB8       :1;                                       /* Flash Common Command Object Bit 8 */
        byte CCOB9       :1;                                       /* Flash Common Command Object Bit 9 */
        byte CCOB10      :1;                                       /* Flash Common Command Object Bit 10 */
        byte CCOB11      :1;                                       /* Flash Common Command Object Bit 11 */
        byte CCOB12      :1;                                       /* Flash Common Command Object Bit 12 */
        byte CCOB13      :1;                                       /* Flash Common Command Object Bit 13 */
        byte CCOB14      :1;                                       /* Flash Common Command Object Bit 14 */
        byte CCOB15      :1;                                       /* Flash Common Command Object Bit 15 */
      } Bits;
    } FCCOBHISTR;
    #define FCCOBHI                     _FCCOB.Overlap_STR.FCCOBHISTR.Byte
    #define FCCOBHI_CCOB8               _FCCOB.Overlap_STR.FCCOBHISTR.Bits.CCOB8
    #define FCCOBHI_CCOB9               _FCCOB.Overlap_STR.FCCOBHISTR.Bits.CCOB9
    #define FCCOBHI_CCOB10              _FCCOB.Overlap_STR.FCCOBHISTR.Bits.CCOB10
    #define FCCOBHI_CCOB11              _FCCOB.Overlap_STR.FCCOBHISTR.Bits.CCOB11
    #define FCCOBHI_CCOB12              _FCCOB.Overlap_STR.FCCOBHISTR.Bits.CCOB12
    #define FCCOBHI_CCOB13              _FCCOB.Overlap_STR.FCCOBHISTR.Bits.CCOB13
    #define FCCOBHI_CCOB14              _FCCOB.Overlap_STR.FCCOBHISTR.Bits.CCOB14
    #define FCCOBHI_CCOB15              _FCCOB.Overlap_STR.FCCOBHISTR.Bits.CCOB15
    
    #define FCCOBHI_CCOB8_MASK          1U
    #define FCCOBHI_CCOB9_MASK          2U
    #define FCCOBHI_CCOB10_MASK         4U
    #define FCCOBHI_CCOB11_MASK         8U
    #define FCCOBHI_CCOB12_MASK         16U
    #define FCCOBHI_CCOB13_MASK         32U
    #define FCCOBHI_CCOB14_MASK         64U
    #define FCCOBHI_CCOB15_MASK         128U
    

    /*** FCCOBLO - Flash Common Command Object Register Low; 0x0000010B ***/
    union {
      byte Byte;
      struct {
        byte CCOB0       :1;                                       /* Flash Common Command Object Bit 0 */
        byte CCOB1       :1;                                       /* Flash Common Command Object Bit 1 */
        byte CCOB2       :1;                                       /* Flash Common Command Object Bit 2 */
        byte CCOB3       :1;                                       /* Flash Common Command Object Bit 3 */
        byte CCOB4       :1;                                       /* Flash Common Command Object Bit 4 */
        byte CCOB5       :1;                                       /* Flash Common Command Object Bit 5 */
        byte CCOB6       :1;                                       /* Flash Common Command Object Bit 6 */
        byte CCOB7       :1;                                       /* Flash Common Command Object Bit 7 */
      } Bits;
    } FCCOBLOSTR;
    #define FCCOBLO                     _FCCOB.Overlap_STR.FCCOBLOSTR.Byte
    #define FCCOBLO_CCOB0               _FCCOB.Overlap_STR.FCCOBLOSTR.Bits.CCOB0
    #define FCCOBLO_CCOB1               _FCCOB.Overlap_STR.FCCOBLOSTR.Bits.CCOB1
    #define FCCOBLO_CCOB2               _FCCOB.Overlap_STR.FCCOBLOSTR.Bits.CCOB2
    #define FCCOBLO_CCOB3               _FCCOB.Overlap_STR.FCCOBLOSTR.Bits.CCOB3
    #define FCCOBLO_CCOB4               _FCCOB.Overlap_STR.FCCOBLOSTR.Bits.CCOB4
    #define FCCOBLO_CCOB5               _FCCOB.Overlap_STR.FCCOBLOSTR.Bits.CCOB5
    #define FCCOBLO_CCOB6               _FCCOB.Overlap_STR.FCCOBLOSTR.Bits.CCOB6
    #define FCCOBLO_CCOB7               _FCCOB.Overlap_STR.FCCOBLOSTR.Bits.CCOB7
    
    #define FCCOBLO_CCOB0_MASK          1U
    #define FCCOBLO_CCOB1_MASK          2U
    #define FCCOBLO_CCOB2_MASK          4U
    #define FCCOBLO_CCOB3_MASK          8U
    #define FCCOBLO_CCOB4_MASK          16U
    #define FCCOBLO_CCOB5_MASK          32U
    #define FCCOBLO_CCOB6_MASK          64U
    #define FCCOBLO_CCOB7_MASK          128U
    
  } Overlap_STR;

  struct {
    word CCOB0       :1;                                       /* Flash Common Command Object Bit 0 */
    word CCOB1       :1;                                       /* Flash Common Command Object Bit 1 */
    word CCOB2       :1;                                       /* Flash Common Command Object Bit 2 */
    word CCOB3       :1;                                       /* Flash Common Command Object Bit 3 */
    word CCOB4       :1;                                       /* Flash Common Command Object Bit 4 */
    word CCOB5       :1;                                       /* Flash Common Command Object Bit 5 */
    word CCOB6       :1;                                       /* Flash Common Command Object Bit 6 */
    word CCOB7       :1;                                       /* Flash Common Command Object Bit 7 */
    word CCOB8       :1;                                       /* Flash Common Command Object Bit 8 */
    word CCOB9       :1;                                       /* Flash Common Command Object Bit 9 */
    word CCOB10      :1;                                       /* Flash Common Command Object Bit 10 */
    word CCOB11      :1;                                       /* Flash Common Command Object Bit 11 */
    word CCOB12      :1;                                       /* Flash Common Command Object Bit 12 */
    word CCOB13      :1;                                       /* Flash Common Command Object Bit 13 */
    word CCOB14      :1;                                       /* Flash Common Command Object Bit 14 */
    word CCOB15      :1;                                       /* Flash Common Command Object Bit 15 */
  } Bits;
} FCCOBSTR;
extern volatile FCCOBSTR _FCCOB @(REG_BASE + 0x0000010AUL);
#define FCCOB                           _FCCOB.Word
#define FCCOB_CCOB0                     _FCCOB.Bits.CCOB0
#define FCCOB_CCOB1                     _FCCOB.Bits.CCOB1
#define FCCOB_CCOB2                     _FCCOB.Bits.CCOB2
#define FCCOB_CCOB3                     _FCCOB.Bits.CCOB3
#define FCCOB_CCOB4                     _FCCOB.Bits.CCOB4
#define FCCOB_CCOB5                     _FCCOB.Bits.CCOB5
#define FCCOB_CCOB6                     _FCCOB.Bits.CCOB6
#define FCCOB_CCOB7                     _FCCOB.Bits.CCOB7
#define FCCOB_CCOB8                     _FCCOB.Bits.CCOB8
#define FCCOB_CCOB9                     _FCCOB.Bits.CCOB9
#define FCCOB_CCOB10                    _FCCOB.Bits.CCOB10
#define FCCOB_CCOB11                    _FCCOB.Bits.CCOB11
#define FCCOB_CCOB12                    _FCCOB.Bits.CCOB12
#define FCCOB_CCOB13                    _FCCOB.Bits.CCOB13
#define FCCOB_CCOB14                    _FCCOB.Bits.CCOB14
#define FCCOB_CCOB15                    _FCCOB.Bits.CCOB15

#define FCCOB_CCOB0_MASK                1U
#define FCCOB_CCOB1_MASK                2U
#define FCCOB_CCOB2_MASK                4U
#define FCCOB_CCOB3_MASK                8U
#define FCCOB_CCOB4_MASK                16U
#define FCCOB_CCOB5_MASK                32U
#define FCCOB_CCOB6_MASK                64U
#define FCCOB_CCOB7_MASK                128U
#define FCCOB_CCOB8_MASK                256U
#define FCCOB_CCOB9_MASK                512U
#define FCCOB_CCOB10_MASK               1024U
#define FCCOB_CCOB11_MASK               2048U
#define FCCOB_CCOB12_MASK               4096U
#define FCCOB_CCOB13_MASK               8192U
#define FCCOB_CCOB14_MASK               16384U
#define FCCOB_CCOB15_MASK               32768U


/*** FOPT - Flash Option Register; 0x00000110 ***/
typedef union {
  byte Byte;
  struct {
    byte NV0         :1;                                       /* Nonvolatile Bit 0 */
    byte NV1         :1;                                       /* Nonvolatile Bit 1 */
    byte NV2         :1;                                       /* Nonvolatile Bit 2 */
    byte NV3         :1;                                       /* Nonvolatile Bit 3 */
    byte NV4         :1;                                       /* Nonvolatile Bit 4 */
    byte NV5         :1;                                       /* Nonvolatile Bit 5 */
    byte NV6         :1;                                       /* Nonvolatile Bit 6 */
    byte NV7         :1;                                       /* Nonvolatile Bit 7 */
  } Bits;
} FOPTSTR;
extern volatile FOPTSTR _FOPT @(REG_BASE + 0x00000110UL);
#define FOPT                            _FOPT.Byte
#define FOPT_NV0                        _FOPT.Bits.NV0
#define FOPT_NV1                        _FOPT.Bits.NV1
#define FOPT_NV2                        _FOPT.Bits.NV2
#define FOPT_NV3                        _FOPT.Bits.NV3
#define FOPT_NV4                        _FOPT.Bits.NV4
#define FOPT_NV5                        _FOPT.Bits.NV5
#define FOPT_NV6                        _FOPT.Bits.NV6
#define FOPT_NV7                        _FOPT.Bits.NV7

#define FOPT_NV0_MASK                   1U
#define FOPT_NV1_MASK                   2U
#define FOPT_NV2_MASK                   4U
#define FOPT_NV3_MASK                   8U
#define FOPT_NV4_MASK                   16U
#define FOPT_NV5_MASK                   32U
#define FOPT_NV6_MASK                   64U
#define FOPT_NV7_MASK                   128U


/*** IVBR - Interrupt Vector Base Register; 0x00000120 ***/
typedef union {
  byte Byte;
  struct {
    byte IVB_ADDR0   :1;                                       /* Interrupt Vector Base Address Bits, bit 0 */
    byte IVB_ADDR1   :1;                                       /* Interrupt Vector Base Address Bits, bit 1 */
    byte IVB_ADDR2   :1;                                       /* Interrupt Vector Base Address Bits, bit 2 */
    byte IVB_ADDR3   :1;                                       /* Interrupt Vector Base Address Bits, bit 3 */
    byte IVB_ADDR4   :1;                                       /* Interrupt Vector Base Address Bits, bit 4 */
    byte IVB_ADDR5   :1;                                       /* Interrupt Vector Base Address Bits, bit 5 */
    byte IVB_ADDR6   :1;                                       /* Interrupt Vector Base Address Bits, bit 6 */
    byte IVB_ADDR7   :1;                                       /* Interrupt Vector Base Address Bits, bit 7 */
  } Bits;
} IVBRSTR;
extern volatile IVBRSTR _IVBR @(REG_BASE + 0x00000120UL);
#define IVBR                            _IVBR.Byte
#define IVBR_IVB_ADDR0                  _IVBR.Bits.IVB_ADDR0
#define IVBR_IVB_ADDR1                  _IVBR.Bits.IVB_ADDR1
#define IVBR_IVB_ADDR2                  _IVBR.Bits.IVB_ADDR2
#define IVBR_IVB_ADDR3                  _IVBR.Bits.IVB_ADDR3
#define IVBR_IVB_ADDR4                  _IVBR.Bits.IVB_ADDR4
#define IVBR_IVB_ADDR5                  _IVBR.Bits.IVB_ADDR5
#define IVBR_IVB_ADDR6                  _IVBR.Bits.IVB_ADDR6
#define IVBR_IVB_ADDR7                  _IVBR.Bits.IVB_ADDR7

#define IVBR_IVB_ADDR0_MASK             1U
#define IVBR_IVB_ADDR1_MASK             2U
#define IVBR_IVB_ADDR2_MASK             4U
#define IVBR_IVB_ADDR3_MASK             8U
#define IVBR_IVB_ADDR4_MASK             16U
#define IVBR_IVB_ADDR5_MASK             32U
#define IVBR_IVB_ADDR6_MASK             64U
#define IVBR_IVB_ADDR7_MASK             128U


/*** CANCTL0 - MSCAN Control 0 Register; 0x00000140 ***/
typedef union {
  byte Byte;
  struct {
    byte INITRQ      :1;                                       /* Initialization Mode Request */
    byte SLPRQ       :1;                                       /* Sleep Mode Request */
    byte WUPE        :1;                                       /* Wake-Up Enable */
    byte TIME        :1;                                       /* Timer Enable */
    byte SYNCH       :1;                                       /* Synchronized Status */
    byte CSWAI       :1;                                       /* CAN Stops in Wait Mode */
    byte RXACT       :1;                                       /* Receiver Active Status */
    byte RXFRM       :1;                                       /* Received Frame Flag */
  } Bits;
} CANCTL0STR;
extern volatile CANCTL0STR _CANCTL0 @(REG_BASE + 0x00000140UL);
#define CANCTL0                         _CANCTL0.Byte
#define CANCTL0_INITRQ                  _CANCTL0.Bits.INITRQ
#define CANCTL0_SLPRQ                   _CANCTL0.Bits.SLPRQ
#define CANCTL0_WUPE                    _CANCTL0.Bits.WUPE
#define CANCTL0_TIME                    _CANCTL0.Bits.TIME
#define CANCTL0_SYNCH                   _CANCTL0.Bits.SYNCH
#define CANCTL0_CSWAI                   _CANCTL0.Bits.CSWAI
#define CANCTL0_RXACT                   _CANCTL0.Bits.RXACT
#define CANCTL0_RXFRM                   _CANCTL0.Bits.RXFRM
/* CANCTL_ARR: Access 2 CANCTLx registers in an array */
#define CANCTL_ARR                      ((volatile byte *) &CANCTL0)

#define CANCTL0_INITRQ_MASK             1U
#define CANCTL0_SLPRQ_MASK              2U
#define CANCTL0_WUPE_MASK               4U
#define CANCTL0_TIME_MASK               8U
#define CANCTL0_SYNCH_MASK              16U
#define CANCTL0_CSWAI_MASK              32U
#define CANCTL0_RXACT_MASK              64U
#define CANCTL0_RXFRM_MASK              128U


/*** CANCTL1 - MSCAN Control 1 Register; 0x00000141 ***/
typedef union {
  byte Byte;
  struct {
    byte INITAK      :1;                                       /* Initialization Mode Acknowledge */
    byte SLPAK       :1;                                       /* Sleep Mode Acknowledge */
    byte WUPM        :1;                                       /* Wake-Up Mode */
    byte BORM        :1;                                       /* Bus-Off Recovery Mode */
    byte LISTEN      :1;                                       /* Listen Only Mode */
    byte LOOPB       :1;                                       /* Loop Back Self Test Mode */
    byte CLKSRC      :1;                                       /* MSCAN Clock Source */
    byte CANE        :1;                                       /* MSCAN Enable */
  } Bits;
} CANCTL1STR;
extern volatile CANCTL1STR _CANCTL1 @(REG_BASE + 0x00000141UL);
#define CANCTL1                         _CANCTL1.Byte
#define CANCTL1_INITAK                  _CANCTL1.Bits.INITAK
#define CANCTL1_SLPAK                   _CANCTL1.Bits.SLPAK
#define CANCTL1_WUPM                    _CANCTL1.Bits.WUPM
#define CANCTL1_BORM                    _CANCTL1.Bits.BORM
#define CANCTL1_LISTEN                  _CANCTL1.Bits.LISTEN
#define CANCTL1_LOOPB                   _CANCTL1.Bits.LOOPB
#define CANCTL1_CLKSRC                  _CANCTL1.Bits.CLKSRC
#define CANCTL1_CANE                    _CANCTL1.Bits.CANE

#define CANCTL1_INITAK_MASK             1U
#define CANCTL1_SLPAK_MASK              2U
#define CANCTL1_WUPM_MASK               4U
#define CANCTL1_BORM_MASK               8U
#define CANCTL1_LISTEN_MASK             16U
#define CANCTL1_LOOPB_MASK              32U
#define CANCTL1_CLKSRC_MASK             64U
#define CANCTL1_CANE_MASK               128U


/*** CANBTR0 - MSCAN Bus Timing Register 0; 0x00000142 ***/
typedef union {
  byte Byte;
  struct {
    byte BRP0        :1;                                       /* Baud Rate Prescaler 0 */
    byte BRP1        :1;                                       /* Baud Rate Prescaler 1 */
    byte BRP2        :1;                                       /* Baud Rate Prescaler 2 */
    byte BRP3        :1;                                       /* Baud Rate Prescaler 3 */
    byte BRP4        :1;                                       /* Baud Rate Prescaler 4 */
    byte BRP5        :1;                                       /* Baud Rate Prescaler 5 */
    byte SJW0        :1;                                       /* Synchronization Jump Width 0 */
    byte SJW1        :1;                                       /* Synchronization Jump Width 1 */
  } Bits;
  struct {
    byte grpBRP  :6;
    byte grpSJW  :2;
  } MergedBits;
} CANBTR0STR;
extern volatile CANBTR0STR _CANBTR0 @(REG_BASE + 0x00000142UL);
#define CANBTR0                         _CANBTR0.Byte
#define CANBTR0_BRP0                    _CANBTR0.Bits.BRP0
#define CANBTR0_BRP1                    _CANBTR0.Bits.BRP1
#define CANBTR0_BRP2                    _CANBTR0.Bits.BRP2
#define CANBTR0_BRP3                    _CANBTR0.Bits.BRP3
#define CANBTR0_BRP4                    _CANBTR0.Bits.BRP4
#define CANBTR0_BRP5                    _CANBTR0.Bits.BRP5
#define CANBTR0_SJW0                    _CANBTR0.Bits.SJW0
#define CANBTR0_SJW1                    _CANBTR0.Bits.SJW1
/* CANBTR_ARR: Access 2 CANBTRx registers in an array */
#define CANBTR_ARR                      ((volatile byte *) &CANBTR0)
#define CANBTR0_BRP                     _CANBTR0.MergedBits.grpBRP
#define CANBTR0_SJW                     _CANBTR0.MergedBits.grpSJW

#define CANBTR0_BRP0_MASK               1U
#define CANBTR0_BRP1_MASK               2U
#define CANBTR0_BRP2_MASK               4U
#define CANBTR0_BRP3_MASK               8U
#define CANBTR0_BRP4_MASK               16U
#define CANBTR0_BRP5_MASK               32U
#define CANBTR0_SJW0_MASK               64U
#define CANBTR0_SJW1_MASK               128U
#define CANBTR0_BRP_MASK                63U
#define CANBTR0_BRP_BITNUM              0U
#define CANBTR0_SJW_MASK                192U
#define CANBTR0_SJW_BITNUM              6U


/*** CANBTR1 - MSCAN Bus Timing Register 1; 0x00000143 ***/
typedef union {
  byte Byte;
  struct {
    byte TSEG10      :1;                                       /* Time Segment 10 */
    byte TSEG11      :1;                                       /* Time Segment 11 */
    byte TSEG12      :1;                                       /* Time Segment 12 */
    byte TSEG13      :1;                                       /* Time Segment 13 */
    byte TSEG20      :1;                                       /* Time Segment 20 */
    byte TSEG21      :1;                                       /* Time Segment 21 */
    byte TSEG22      :1;                                       /* Time Segment 22 */
    byte SAMP        :1;                                       /* Sampling */
  } Bits;
  struct {
    byte grpTSEG_10 :4;
    byte grpTSEG_20 :3;
    byte         :1;
  } MergedBits;
} CANBTR1STR;
extern volatile CANBTR1STR _CANBTR1 @(REG_BASE + 0x00000143UL);
#define CANBTR1                         _CANBTR1.Byte
#define CANBTR1_TSEG10                  _CANBTR1.Bits.TSEG10
#define CANBTR1_TSEG11                  _CANBTR1.Bits.TSEG11
#define CANBTR1_TSEG12                  _CANBTR1.Bits.TSEG12
#define CANBTR1_TSEG13                  _CANBTR1.Bits.TSEG13
#define CANBTR1_TSEG20                  _CANBTR1.Bits.TSEG20
#define CANBTR1_TSEG21                  _CANBTR1.Bits.TSEG21
#define CANBTR1_TSEG22                  _CANBTR1.Bits.TSEG22
#define CANBTR1_SAMP                    _CANBTR1.Bits.SAMP
#define CANBTR1_TSEG_10                 _CANBTR1.MergedBits.grpTSEG_10
#define CANBTR1_TSEG_20                 _CANBTR1.MergedBits.grpTSEG_20
#define CANBTR1_TSEG                    CANBTR1_TSEG_10

#define CANBTR1_TSEG10_MASK             1U
#define CANBTR1_TSEG11_MASK             2U
#define CANBTR1_TSEG12_MASK             4U
#define CANBTR1_TSEG13_MASK             8U
#define CANBTR1_TSEG20_MASK             16U
#define CANBTR1_TSEG21_MASK             32U
#define CANBTR1_TSEG22_MASK             64U
#define CANBTR1_SAMP_MASK               128U
#define CANBTR1_TSEG_10_MASK            15U
#define CANBTR1_TSEG_10_BITNUM          0U
#define CANBTR1_TSEG_20_MASK            112U
#define CANBTR1_TSEG_20_BITNUM          4U


/*** CANRFLG - MSCAN Receiver Flag Register; 0x00000144 ***/
typedef union {
  byte Byte;
  struct {
    byte RXF         :1;                                       /* Receive Buffer Full */
    byte OVRIF       :1;                                       /* Overrun Interrupt Flag */
    byte TSTAT0      :1;                                       /* Transmitter Status Bit 0 */
    byte TSTAT1      :1;                                       /* Transmitter Status Bit 1 */
    byte RSTAT0      :1;                                       /* Receiver Status Bit 0 */
    byte RSTAT1      :1;                                       /* Receiver Status Bit 1 */
    byte CSCIF       :1;                                       /* CAN Status Change Interrupt Flag */
    byte WUPIF       :1;                                       /* Wake-up Interrupt Flag */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte grpTSTAT :2;
    byte grpRSTAT :2;
    byte         :1;
    byte         :1;
  } MergedBits;
} CANRFLGSTR;
extern volatile CANRFLGSTR _CANRFLG @(REG_BASE + 0x00000144UL);
#define CANRFLG                         _CANRFLG.Byte
#define CANRFLG_RXF                     _CANRFLG.Bits.RXF
#define CANRFLG_OVRIF                   _CANRFLG.Bits.OVRIF
#define CANRFLG_TSTAT0                  _CANRFLG.Bits.TSTAT0
#define CANRFLG_TSTAT1                  _CANRFLG.Bits.TSTAT1
#define CANRFLG_RSTAT0                  _CANRFLG.Bits.RSTAT0
#define CANRFLG_RSTAT1                  _CANRFLG.Bits.RSTAT1
#define CANRFLG_CSCIF                   _CANRFLG.Bits.CSCIF
#define CANRFLG_WUPIF                   _CANRFLG.Bits.WUPIF
#define CANRFLG_TSTAT                   _CANRFLG.MergedBits.grpTSTAT
#define CANRFLG_RSTAT                   _CANRFLG.MergedBits.grpRSTAT

#define CANRFLG_RXF_MASK                1U
#define CANRFLG_OVRIF_MASK              2U
#define CANRFLG_TSTAT0_MASK             4U
#define CANRFLG_TSTAT1_MASK             8U
#define CANRFLG_RSTAT0_MASK             16U
#define CANRFLG_RSTAT1_MASK             32U
#define CANRFLG_CSCIF_MASK              64U
#define CANRFLG_WUPIF_MASK              128U
#define CANRFLG_TSTAT_MASK              12U
#define CANRFLG_TSTAT_BITNUM            2U
#define CANRFLG_RSTAT_MASK              48U
#define CANRFLG_RSTAT_BITNUM            4U


/*** CANRIER - MSCAN Receiver Interrupt Enable Register; 0x00000145 ***/
typedef union {
  byte Byte;
  struct {
    byte RXFIE       :1;                                       /* Receiver Full Interrupt Enable */
    byte OVRIE       :1;                                       /* Overrun Interrupt Enable */
    byte TSTATE0     :1;                                       /* Transmitter Status Change Enable 0 */
    byte TSTATE1     :1;                                       /* Transmitter Status Change Enable 1 */
    byte RSTATE0     :1;                                       /* Receiver Status Change Enable 0 */
    byte RSTATE1     :1;                                       /* Receiver Status Change Enable 1 */
    byte CSCIE       :1;                                       /* CAN Status Change Interrupt Enable */
    byte WUPIE       :1;                                       /* Wake-up Interrupt Enable */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte grpTSTATE :2;
    byte grpRSTATE :2;
    byte         :1;
    byte         :1;
  } MergedBits;
} CANRIERSTR;
extern volatile CANRIERSTR _CANRIER @(REG_BASE + 0x00000145UL);
#define CANRIER                         _CANRIER.Byte
#define CANRIER_RXFIE                   _CANRIER.Bits.RXFIE
#define CANRIER_OVRIE                   _CANRIER.Bits.OVRIE
#define CANRIER_TSTATE0                 _CANRIER.Bits.TSTATE0
#define CANRIER_TSTATE1                 _CANRIER.Bits.TSTATE1
#define CANRIER_RSTATE0                 _CANRIER.Bits.RSTATE0
#define CANRIER_RSTATE1                 _CANRIER.Bits.RSTATE1
#define CANRIER_CSCIE                   _CANRIER.Bits.CSCIE
#define CANRIER_WUPIE                   _CANRIER.Bits.WUPIE
#define CANRIER_TSTATE                  _CANRIER.MergedBits.grpTSTATE
#define CANRIER_RSTATE                  _CANRIER.MergedBits.grpRSTATE

#define CANRIER_RXFIE_MASK              1U
#define CANRIER_OVRIE_MASK              2U
#define CANRIER_TSTATE0_MASK            4U
#define CANRIER_TSTATE1_MASK            8U
#define CANRIER_RSTATE0_MASK            16U
#define CANRIER_RSTATE1_MASK            32U
#define CANRIER_CSCIE_MASK              64U
#define CANRIER_WUPIE_MASK              128U
#define CANRIER_TSTATE_MASK             12U
#define CANRIER_TSTATE_BITNUM           2U
#define CANRIER_RSTATE_MASK             48U
#define CANRIER_RSTATE_BITNUM           4U


/*** CANTFLG - MSCAN Transmitter Flag Register; 0x00000146 ***/
typedef union {
  byte Byte;
  struct {
    byte TXE0        :1;                                       /* Transmitter Buffer Empty 0 */
    byte TXE1        :1;                                       /* Transmitter Buffer Empty 1 */
    byte TXE2        :1;                                       /* Transmitter Buffer Empty 2 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpTXE  :3;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} CANTFLGSTR;
extern volatile CANTFLGSTR _CANTFLG @(REG_BASE + 0x00000146UL);
#define CANTFLG                         _CANTFLG.Byte
#define CANTFLG_TXE0                    _CANTFLG.Bits.TXE0
#define CANTFLG_TXE1                    _CANTFLG.Bits.TXE1
#define CANTFLG_TXE2                    _CANTFLG.Bits.TXE2
#define CANTFLG_TXE                     _CANTFLG.MergedBits.grpTXE

#define CANTFLG_TXE0_MASK               1U
#define CANTFLG_TXE1_MASK               2U
#define CANTFLG_TXE2_MASK               4U
#define CANTFLG_TXE_MASK                7U
#define CANTFLG_TXE_BITNUM              0U


/*** CANTIER - MSCAN Transmitter Interrupt Enable Register; 0x00000147 ***/
typedef union {
  byte Byte;
  struct {
    byte TXEIE0      :1;                                       /* Transmitter Empty Interrupt Enable 0 */
    byte TXEIE1      :1;                                       /* Transmitter Empty Interrupt Enable 1 */
    byte TXEIE2      :1;                                       /* Transmitter Empty Interrupt Enable 2 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpTXEIE :3;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} CANTIERSTR;
extern volatile CANTIERSTR _CANTIER @(REG_BASE + 0x00000147UL);
#define CANTIER                         _CANTIER.Byte
#define CANTIER_TXEIE0                  _CANTIER.Bits.TXEIE0
#define CANTIER_TXEIE1                  _CANTIER.Bits.TXEIE1
#define CANTIER_TXEIE2                  _CANTIER.Bits.TXEIE2
#define CANTIER_TXEIE                   _CANTIER.MergedBits.grpTXEIE

#define CANTIER_TXEIE0_MASK             1U
#define CANTIER_TXEIE1_MASK             2U
#define CANTIER_TXEIE2_MASK             4U
#define CANTIER_TXEIE_MASK              7U
#define CANTIER_TXEIE_BITNUM            0U


/*** CANTARQ - MSCAN Transmitter Message Abort Request; 0x00000148 ***/
typedef union {
  byte Byte;
  struct {
    byte ABTRQ0      :1;                                       /* Abort Request 0 */
    byte ABTRQ1      :1;                                       /* Abort Request 1 */
    byte ABTRQ2      :1;                                       /* Abort Request 2 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpABTRQ :3;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} CANTARQSTR;
extern volatile CANTARQSTR _CANTARQ @(REG_BASE + 0x00000148UL);
#define CANTARQ                         _CANTARQ.Byte
#define CANTARQ_ABTRQ0                  _CANTARQ.Bits.ABTRQ0
#define CANTARQ_ABTRQ1                  _CANTARQ.Bits.ABTRQ1
#define CANTARQ_ABTRQ2                  _CANTARQ.Bits.ABTRQ2
#define CANTARQ_ABTRQ                   _CANTARQ.MergedBits.grpABTRQ

#define CANTARQ_ABTRQ0_MASK             1U
#define CANTARQ_ABTRQ1_MASK             2U
#define CANTARQ_ABTRQ2_MASK             4U
#define CANTARQ_ABTRQ_MASK              7U
#define CANTARQ_ABTRQ_BITNUM            0U


/*** CANTAAK - MSCAN Transmitter Message Abort Acknowledge; 0x00000149 ***/
typedef union {
  byte Byte;
  struct {
    byte ABTAK0      :1;                                       /* Abort Acknowledge 0 */
    byte ABTAK1      :1;                                       /* Abort Acknowledge 1 */
    byte ABTAK2      :1;                                       /* Abort Acknowledge 2 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpABTAK :3;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} CANTAAKSTR;
extern volatile CANTAAKSTR _CANTAAK @(REG_BASE + 0x00000149UL);
#define CANTAAK                         _CANTAAK.Byte
#define CANTAAK_ABTAK0                  _CANTAAK.Bits.ABTAK0
#define CANTAAK_ABTAK1                  _CANTAAK.Bits.ABTAK1
#define CANTAAK_ABTAK2                  _CANTAAK.Bits.ABTAK2
#define CANTAAK_ABTAK                   _CANTAAK.MergedBits.grpABTAK

#define CANTAAK_ABTAK0_MASK             1U
#define CANTAAK_ABTAK1_MASK             2U
#define CANTAAK_ABTAK2_MASK             4U
#define CANTAAK_ABTAK_MASK              7U
#define CANTAAK_ABTAK_BITNUM            0U


/*** CANTBSEL - MSCAN Transmit Buffer Selection; 0x0000014A ***/
typedef union {
  byte Byte;
  struct {
    byte TX0         :1;                                       /* Transmit Buffer Select 0 */
    byte TX1         :1;                                       /* Transmit Buffer Select 1 */
    byte TX2         :1;                                       /* Transmit Buffer Select 2 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpTX   :3;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} CANTBSELSTR;
extern volatile CANTBSELSTR _CANTBSEL @(REG_BASE + 0x0000014AUL);
#define CANTBSEL                        _CANTBSEL.Byte
#define CANTBSEL_TX0                    _CANTBSEL.Bits.TX0
#define CANTBSEL_TX1                    _CANTBSEL.Bits.TX1
#define CANTBSEL_TX2                    _CANTBSEL.Bits.TX2
#define CANTBSEL_TX                     _CANTBSEL.MergedBits.grpTX

#define CANTBSEL_TX0_MASK               1U
#define CANTBSEL_TX1_MASK               2U
#define CANTBSEL_TX2_MASK               4U
#define CANTBSEL_TX_MASK                7U
#define CANTBSEL_TX_BITNUM              0U


/*** CANIDAC - MSCAN Identifier Acceptance Control Register; 0x0000014B ***/
typedef union {
  byte Byte;
  struct {
    byte IDHIT0      :1;                                       /* Identifier Acceptance Hit Indicator 0 */
    byte IDHIT1      :1;                                       /* Identifier Acceptance Hit Indicator 1 */
    byte IDHIT2      :1;                                       /* Identifier Acceptance Hit Indicator 2 */
    byte             :1; 
    byte IDAM0       :1;                                       /* Identifier Acceptance Mode 0 */
    byte IDAM1       :1;                                       /* Identifier Acceptance Mode 1 */
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpIDHIT :3;
    byte         :1;
    byte grpIDAM :2;
    byte         :1;
    byte         :1;
  } MergedBits;
} CANIDACSTR;
extern volatile CANIDACSTR _CANIDAC @(REG_BASE + 0x0000014BUL);
#define CANIDAC                         _CANIDAC.Byte
#define CANIDAC_IDHIT0                  _CANIDAC.Bits.IDHIT0
#define CANIDAC_IDHIT1                  _CANIDAC.Bits.IDHIT1
#define CANIDAC_IDHIT2                  _CANIDAC.Bits.IDHIT2
#define CANIDAC_IDAM0                   _CANIDAC.Bits.IDAM0
#define CANIDAC_IDAM1                   _CANIDAC.Bits.IDAM1
#define CANIDAC_IDHIT                   _CANIDAC.MergedBits.grpIDHIT
#define CANIDAC_IDAM                    _CANIDAC.MergedBits.grpIDAM

#define CANIDAC_IDHIT0_MASK             1U
#define CANIDAC_IDHIT1_MASK             2U
#define CANIDAC_IDHIT2_MASK             4U
#define CANIDAC_IDAM0_MASK              16U
#define CANIDAC_IDAM1_MASK              32U
#define CANIDAC_IDHIT_MASK              7U
#define CANIDAC_IDHIT_BITNUM            0U
#define CANIDAC_IDAM_MASK               48U
#define CANIDAC_IDAM_BITNUM             4U


/*** CANMISC - MSCAN Miscellaneous Register; 0x0000014D ***/
typedef union {
  byte Byte;
  struct {
    byte BOHOLD      :1;                                       /* Bus-off State Hold Until User Request */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} CANMISCSTR;
extern volatile CANMISCSTR _CANMISC @(REG_BASE + 0x0000014DUL);
#define CANMISC                         _CANMISC.Byte
#define CANMISC_BOHOLD                  _CANMISC.Bits.BOHOLD

#define CANMISC_BOHOLD_MASK             1U


/*** CANRXERR - MSCAN Receive Error Counter Register; 0x0000014E ***/
typedef union {
  byte Byte;
  struct {
    byte RXERR0      :1;                                       /* Bit 0 */
    byte RXERR1      :1;                                       /* Bit 1 */
    byte RXERR2      :1;                                       /* Bit 2 */
    byte RXERR3      :1;                                       /* Bit 3 */
    byte RXERR4      :1;                                       /* Bit 4 */
    byte RXERR5      :1;                                       /* Bit 5 */
    byte RXERR6      :1;                                       /* Bit 6 */
    byte RXERR7      :1;                                       /* Bit 7 */
  } Bits;
} CANRXERRSTR;
extern volatile CANRXERRSTR _CANRXERR @(REG_BASE + 0x0000014EUL);
#define CANRXERR                        _CANRXERR.Byte
#define CANRXERR_RXERR0                 _CANRXERR.Bits.RXERR0
#define CANRXERR_RXERR1                 _CANRXERR.Bits.RXERR1
#define CANRXERR_RXERR2                 _CANRXERR.Bits.RXERR2
#define CANRXERR_RXERR3                 _CANRXERR.Bits.RXERR3
#define CANRXERR_RXERR4                 _CANRXERR.Bits.RXERR4
#define CANRXERR_RXERR5                 _CANRXERR.Bits.RXERR5
#define CANRXERR_RXERR6                 _CANRXERR.Bits.RXERR6
#define CANRXERR_RXERR7                 _CANRXERR.Bits.RXERR7

#define CANRXERR_RXERR0_MASK            1U
#define CANRXERR_RXERR1_MASK            2U
#define CANRXERR_RXERR2_MASK            4U
#define CANRXERR_RXERR3_MASK            8U
#define CANRXERR_RXERR4_MASK            16U
#define CANRXERR_RXERR5_MASK            32U
#define CANRXERR_RXERR6_MASK            64U
#define CANRXERR_RXERR7_MASK            128U


/*** CANTXERR - MSCAN Transmit Error Counter Register; 0x0000014F ***/
typedef union {
  byte Byte;
  struct {
    byte TXERR0      :1;                                       /* Bit 0 */
    byte TXERR1      :1;                                       /* Bit 1 */
    byte TXERR2      :1;                                       /* Bit 2 */
    byte TXERR3      :1;                                       /* Bit 3 */
    byte TXERR4      :1;                                       /* Bit 4 */
    byte TXERR5      :1;                                       /* Bit 5 */
    byte TXERR6      :1;                                       /* Bit 6 */
    byte TXERR7      :1;                                       /* Bit 7 */
  } Bits;
} CANTXERRSTR;
extern volatile CANTXERRSTR _CANTXERR @(REG_BASE + 0x0000014FUL);
#define CANTXERR                        _CANTXERR.Byte
#define CANTXERR_TXERR0                 _CANTXERR.Bits.TXERR0
#define CANTXERR_TXERR1                 _CANTXERR.Bits.TXERR1
#define CANTXERR_TXERR2                 _CANTXERR.Bits.TXERR2
#define CANTXERR_TXERR3                 _CANTXERR.Bits.TXERR3
#define CANTXERR_TXERR4                 _CANTXERR.Bits.TXERR4
#define CANTXERR_TXERR5                 _CANTXERR.Bits.TXERR5
#define CANTXERR_TXERR6                 _CANTXERR.Bits.TXERR6
#define CANTXERR_TXERR7                 _CANTXERR.Bits.TXERR7

#define CANTXERR_TXERR0_MASK            1U
#define CANTXERR_TXERR1_MASK            2U
#define CANTXERR_TXERR2_MASK            4U
#define CANTXERR_TXERR3_MASK            8U
#define CANTXERR_TXERR4_MASK            16U
#define CANTXERR_TXERR5_MASK            32U
#define CANTXERR_TXERR6_MASK            64U
#define CANTXERR_TXERR7_MASK            128U


/*** CANIDAR0 - MSCAN Identifier Acceptance Register 0; 0x00000150 ***/
typedef union {
  byte Byte;
  struct {
    byte AC0         :1;                                       /* Acceptance Code Bit 0 */
    byte AC1         :1;                                       /* Acceptance Code Bit 1 */
    byte AC2         :1;                                       /* Acceptance Code Bit 2 */
    byte AC3         :1;                                       /* Acceptance Code Bit 3 */
    byte AC4         :1;                                       /* Acceptance Code Bit 4 */
    byte AC5         :1;                                       /* Acceptance Code Bit 5 */
    byte AC6         :1;                                       /* Acceptance Code Bit 6 */
    byte AC7         :1;                                       /* Acceptance Code Bit 7 */
  } Bits;
} CANIDAR0STR;
extern volatile CANIDAR0STR _CANIDAR0 @(REG_BASE + 0x00000150UL);
#define CANIDAR0                        _CANIDAR0.Byte
#define CANIDAR0_AC0                    _CANIDAR0.Bits.AC0
#define CANIDAR0_AC1                    _CANIDAR0.Bits.AC1
#define CANIDAR0_AC2                    _CANIDAR0.Bits.AC2
#define CANIDAR0_AC3                    _CANIDAR0.Bits.AC3
#define CANIDAR0_AC4                    _CANIDAR0.Bits.AC4
#define CANIDAR0_AC5                    _CANIDAR0.Bits.AC5
#define CANIDAR0_AC6                    _CANIDAR0.Bits.AC6
#define CANIDAR0_AC7                    _CANIDAR0.Bits.AC7
/* CANIDAR_ARR: Access 4 CANIDARx registers in an array */
#define CANIDAR_ARR                     ((volatile byte *) &CANIDAR0)

#define CANIDAR0_AC0_MASK               1U
#define CANIDAR0_AC1_MASK               2U
#define CANIDAR0_AC2_MASK               4U
#define CANIDAR0_AC3_MASK               8U
#define CANIDAR0_AC4_MASK               16U
#define CANIDAR0_AC5_MASK               32U
#define CANIDAR0_AC6_MASK               64U
#define CANIDAR0_AC7_MASK               128U


/*** CANIDAR1 - MSCAN Identifier Acceptance Register 1; 0x00000151 ***/
typedef union {
  byte Byte;
  struct {
    byte AC0         :1;                                       /* Acceptance Code Bit 0 */
    byte AC1         :1;                                       /* Acceptance Code Bit 1 */
    byte AC2         :1;                                       /* Acceptance Code Bit 2 */
    byte AC3         :1;                                       /* Acceptance Code Bit 3 */
    byte AC4         :1;                                       /* Acceptance Code Bit 4 */
    byte AC5         :1;                                       /* Acceptance Code Bit 5 */
    byte AC6         :1;                                       /* Acceptance Code Bit 6 */
    byte AC7         :1;                                       /* Acceptance Code Bit 7 */
  } Bits;
} CANIDAR1STR;
extern volatile CANIDAR1STR _CANIDAR1 @(REG_BASE + 0x00000151UL);
#define CANIDAR1                        _CANIDAR1.Byte
#define CANIDAR1_AC0                    _CANIDAR1.Bits.AC0
#define CANIDAR1_AC1                    _CANIDAR1.Bits.AC1
#define CANIDAR1_AC2                    _CANIDAR1.Bits.AC2
#define CANIDAR1_AC3                    _CANIDAR1.Bits.AC3
#define CANIDAR1_AC4                    _CANIDAR1.Bits.AC4
#define CANIDAR1_AC5                    _CANIDAR1.Bits.AC5
#define CANIDAR1_AC6                    _CANIDAR1.Bits.AC6
#define CANIDAR1_AC7                    _CANIDAR1.Bits.AC7

#define CANIDAR1_AC0_MASK               1U
#define CANIDAR1_AC1_MASK               2U
#define CANIDAR1_AC2_MASK               4U
#define CANIDAR1_AC3_MASK               8U
#define CANIDAR1_AC4_MASK               16U
#define CANIDAR1_AC5_MASK               32U
#define CANIDAR1_AC6_MASK               64U
#define CANIDAR1_AC7_MASK               128U


/*** CANIDAR2 - MSCAN Identifier Acceptance Register 2; 0x00000152 ***/
typedef union {
  byte Byte;
  struct {
    byte AC0         :1;                                       /* Acceptance Code Bit 0 */
    byte AC1         :1;                                       /* Acceptance Code Bit 1 */
    byte AC2         :1;                                       /* Acceptance Code Bit 2 */
    byte AC3         :1;                                       /* Acceptance Code Bit 3 */
    byte AC4         :1;                                       /* Acceptance Code Bit 4 */
    byte AC5         :1;                                       /* Acceptance Code Bit 5 */
    byte AC6         :1;                                       /* Acceptance Code Bit 6 */
    byte AC7         :1;                                       /* Acceptance Code Bit 7 */
  } Bits;
} CANIDAR2STR;
extern volatile CANIDAR2STR _CANIDAR2 @(REG_BASE + 0x00000152UL);
#define CANIDAR2                        _CANIDAR2.Byte
#define CANIDAR2_AC0                    _CANIDAR2.Bits.AC0
#define CANIDAR2_AC1                    _CANIDAR2.Bits.AC1
#define CANIDAR2_AC2                    _CANIDAR2.Bits.AC2
#define CANIDAR2_AC3                    _CANIDAR2.Bits.AC3
#define CANIDAR2_AC4                    _CANIDAR2.Bits.AC4
#define CANIDAR2_AC5                    _CANIDAR2.Bits.AC5
#define CANIDAR2_AC6                    _CANIDAR2.Bits.AC6
#define CANIDAR2_AC7                    _CANIDAR2.Bits.AC7

#define CANIDAR2_AC0_MASK               1U
#define CANIDAR2_AC1_MASK               2U
#define CANIDAR2_AC2_MASK               4U
#define CANIDAR2_AC3_MASK               8U
#define CANIDAR2_AC4_MASK               16U
#define CANIDAR2_AC5_MASK               32U
#define CANIDAR2_AC6_MASK               64U
#define CANIDAR2_AC7_MASK               128U


/*** CANIDAR3 - MSCAN Identifier Acceptance Register 3; 0x00000153 ***/
typedef union {
  byte Byte;
  struct {
    byte AC0         :1;                                       /* Acceptance Code Bit 0 */
    byte AC1         :1;                                       /* Acceptance Code Bit 1 */
    byte AC2         :1;                                       /* Acceptance Code Bit 2 */
    byte AC3         :1;                                       /* Acceptance Code Bit 3 */
    byte AC4         :1;                                       /* Acceptance Code Bit 4 */
    byte AC5         :1;                                       /* Acceptance Code Bit 5 */
    byte AC6         :1;                                       /* Acceptance Code Bit 6 */
    byte AC7         :1;                                       /* Acceptance Code Bit 7 */
  } Bits;
} CANIDAR3STR;
extern volatile CANIDAR3STR _CANIDAR3 @(REG_BASE + 0x00000153UL);
#define CANIDAR3                        _CANIDAR3.Byte
#define CANIDAR3_AC0                    _CANIDAR3.Bits.AC0
#define CANIDAR3_AC1                    _CANIDAR3.Bits.AC1
#define CANIDAR3_AC2                    _CANIDAR3.Bits.AC2
#define CANIDAR3_AC3                    _CANIDAR3.Bits.AC3
#define CANIDAR3_AC4                    _CANIDAR3.Bits.AC4
#define CANIDAR3_AC5                    _CANIDAR3.Bits.AC5
#define CANIDAR3_AC6                    _CANIDAR3.Bits.AC6
#define CANIDAR3_AC7                    _CANIDAR3.Bits.AC7

#define CANIDAR3_AC0_MASK               1U
#define CANIDAR3_AC1_MASK               2U
#define CANIDAR3_AC2_MASK               4U
#define CANIDAR3_AC3_MASK               8U
#define CANIDAR3_AC4_MASK               16U
#define CANIDAR3_AC5_MASK               32U
#define CANIDAR3_AC6_MASK               64U
#define CANIDAR3_AC7_MASK               128U


/*** CANIDMR0 - MSCAN Identifier Mask Register 0; 0x00000154 ***/
typedef union {
  byte Byte;
  struct {
    byte AM0         :1;                                       /* Acceptance Mask Bit 0 */
    byte AM1         :1;                                       /* Acceptance Mask Bit 1 */
    byte AM2         :1;                                       /* Acceptance Mask Bit 2 */
    byte AM3         :1;                                       /* Acceptance Mask Bit 3 */
    byte AM4         :1;                                       /* Acceptance Mask Bit 4 */
    byte AM5         :1;                                       /* Acceptance Mask Bit 5 */
    byte AM6         :1;                                       /* Acceptance Mask Bit 6 */
    byte AM7         :1;                                       /* Acceptance Mask Bit 7 */
  } Bits;
} CANIDMR0STR;
extern volatile CANIDMR0STR _CANIDMR0 @(REG_BASE + 0x00000154UL);
#define CANIDMR0                        _CANIDMR0.Byte
#define CANIDMR0_AM0                    _CANIDMR0.Bits.AM0
#define CANIDMR0_AM1                    _CANIDMR0.Bits.AM1
#define CANIDMR0_AM2                    _CANIDMR0.Bits.AM2
#define CANIDMR0_AM3                    _CANIDMR0.Bits.AM3
#define CANIDMR0_AM4                    _CANIDMR0.Bits.AM4
#define CANIDMR0_AM5                    _CANIDMR0.Bits.AM5
#define CANIDMR0_AM6                    _CANIDMR0.Bits.AM6
#define CANIDMR0_AM7                    _CANIDMR0.Bits.AM7
/* CANIDMR_ARR: Access 4 CANIDMRx registers in an array */
#define CANIDMR_ARR                     ((volatile byte *) &CANIDMR0)

#define CANIDMR0_AM0_MASK               1U
#define CANIDMR0_AM1_MASK               2U
#define CANIDMR0_AM2_MASK               4U
#define CANIDMR0_AM3_MASK               8U
#define CANIDMR0_AM4_MASK               16U
#define CANIDMR0_AM5_MASK               32U
#define CANIDMR0_AM6_MASK               64U
#define CANIDMR0_AM7_MASK               128U


/*** CANIDMR1 - MSCAN Identifier Mask Register 1; 0x00000155 ***/
typedef union {
  byte Byte;
  struct {
    byte AM0         :1;                                       /* Acceptance Mask Bit 0 */
    byte AM1         :1;                                       /* Acceptance Mask Bit 1 */
    byte AM2         :1;                                       /* Acceptance Mask Bit 2 */
    byte AM3         :1;                                       /* Acceptance Mask Bit 3 */
    byte AM4         :1;                                       /* Acceptance Mask Bit 4 */
    byte AM5         :1;                                       /* Acceptance Mask Bit 5 */
    byte AM6         :1;                                       /* Acceptance Mask Bit 6 */
    byte AM7         :1;                                       /* Acceptance Mask Bit 7 */
  } Bits;
} CANIDMR1STR;
extern volatile CANIDMR1STR _CANIDMR1 @(REG_BASE + 0x00000155UL);
#define CANIDMR1                        _CANIDMR1.Byte
#define CANIDMR1_AM0                    _CANIDMR1.Bits.AM0
#define CANIDMR1_AM1                    _CANIDMR1.Bits.AM1
#define CANIDMR1_AM2                    _CANIDMR1.Bits.AM2
#define CANIDMR1_AM3                    _CANIDMR1.Bits.AM3
#define CANIDMR1_AM4                    _CANIDMR1.Bits.AM4
#define CANIDMR1_AM5                    _CANIDMR1.Bits.AM5
#define CANIDMR1_AM6                    _CANIDMR1.Bits.AM6
#define CANIDMR1_AM7                    _CANIDMR1.Bits.AM7

#define CANIDMR1_AM0_MASK               1U
#define CANIDMR1_AM1_MASK               2U
#define CANIDMR1_AM2_MASK               4U
#define CANIDMR1_AM3_MASK               8U
#define CANIDMR1_AM4_MASK               16U
#define CANIDMR1_AM5_MASK               32U
#define CANIDMR1_AM6_MASK               64U
#define CANIDMR1_AM7_MASK               128U


/*** CANIDMR2 - MSCAN Identifier Mask Register 2; 0x00000156 ***/
typedef union {
  byte Byte;
  struct {
    byte AM0         :1;                                       /* Acceptance Mask Bit 0 */
    byte AM1         :1;                                       /* Acceptance Mask Bit 1 */
    byte AM2         :1;                                       /* Acceptance Mask Bit 2 */
    byte AM3         :1;                                       /* Acceptance Mask Bit 3 */
    byte AM4         :1;                                       /* Acceptance Mask Bit 4 */
    byte AM5         :1;                                       /* Acceptance Mask Bit 5 */
    byte AM6         :1;                                       /* Acceptance Mask Bit 6 */
    byte AM7         :1;                                       /* Acceptance Mask Bit 7 */
  } Bits;
} CANIDMR2STR;
extern volatile CANIDMR2STR _CANIDMR2 @(REG_BASE + 0x00000156UL);
#define CANIDMR2                        _CANIDMR2.Byte
#define CANIDMR2_AM0                    _CANIDMR2.Bits.AM0
#define CANIDMR2_AM1                    _CANIDMR2.Bits.AM1
#define CANIDMR2_AM2                    _CANIDMR2.Bits.AM2
#define CANIDMR2_AM3                    _CANIDMR2.Bits.AM3
#define CANIDMR2_AM4                    _CANIDMR2.Bits.AM4
#define CANIDMR2_AM5                    _CANIDMR2.Bits.AM5
#define CANIDMR2_AM6                    _CANIDMR2.Bits.AM6
#define CANIDMR2_AM7                    _CANIDMR2.Bits.AM7

#define CANIDMR2_AM0_MASK               1U
#define CANIDMR2_AM1_MASK               2U
#define CANIDMR2_AM2_MASK               4U
#define CANIDMR2_AM3_MASK               8U
#define CANIDMR2_AM4_MASK               16U
#define CANIDMR2_AM5_MASK               32U
#define CANIDMR2_AM6_MASK               64U
#define CANIDMR2_AM7_MASK               128U


/*** CANIDMR3 - MSCAN Identifier Mask Register 3; 0x00000157 ***/
typedef union {
  byte Byte;
  struct {
    byte AM0         :1;                                       /* Acceptance Mask Bit 0 */
    byte AM1         :1;                                       /* Acceptance Mask Bit 1 */
    byte AM2         :1;                                       /* Acceptance Mask Bit 2 */
    byte AM3         :1;                                       /* Acceptance Mask Bit 3 */
    byte AM4         :1;                                       /* Acceptance Mask Bit 4 */
    byte AM5         :1;                                       /* Acceptance Mask Bit 5 */
    byte AM6         :1;                                       /* Acceptance Mask Bit 6 */
    byte AM7         :1;                                       /* Acceptance Mask Bit 7 */
  } Bits;
} CANIDMR3STR;
extern volatile CANIDMR3STR _CANIDMR3 @(REG_BASE + 0x00000157UL);
#define CANIDMR3                        _CANIDMR3.Byte
#define CANIDMR3_AM0                    _CANIDMR3.Bits.AM0
#define CANIDMR3_AM1                    _CANIDMR3.Bits.AM1
#define CANIDMR3_AM2                    _CANIDMR3.Bits.AM2
#define CANIDMR3_AM3                    _CANIDMR3.Bits.AM3
#define CANIDMR3_AM4                    _CANIDMR3.Bits.AM4
#define CANIDMR3_AM5                    _CANIDMR3.Bits.AM5
#define CANIDMR3_AM6                    _CANIDMR3.Bits.AM6
#define CANIDMR3_AM7                    _CANIDMR3.Bits.AM7

#define CANIDMR3_AM0_MASK               1U
#define CANIDMR3_AM1_MASK               2U
#define CANIDMR3_AM2_MASK               4U
#define CANIDMR3_AM3_MASK               8U
#define CANIDMR3_AM4_MASK               16U
#define CANIDMR3_AM5_MASK               32U
#define CANIDMR3_AM6_MASK               64U
#define CANIDMR3_AM7_MASK               128U


/*** CANIDAR4 - MSCAN Identifier Acceptance Register 4; 0x00000158 ***/
typedef union {
  byte Byte;
  struct {
    byte AC0         :1;                                       /* Acceptance Code Bit 0 */
    byte AC1         :1;                                       /* Acceptance Code Bit 1 */
    byte AC2         :1;                                       /* Acceptance Code Bit 2 */
    byte AC3         :1;                                       /* Acceptance Code Bit 3 */
    byte AC4         :1;                                       /* Acceptance Code Bit 4 */
    byte AC5         :1;                                       /* Acceptance Code Bit 5 */
    byte AC6         :1;                                       /* Acceptance Code Bit 6 */
    byte AC7         :1;                                       /* Acceptance Code Bit 7 */
  } Bits;
} CANIDAR4STR;
extern volatile CANIDAR4STR _CANIDAR4 @(REG_BASE + 0x00000158UL);
#define CANIDAR4                        _CANIDAR4.Byte
#define CANIDAR4_AC0                    _CANIDAR4.Bits.AC0
#define CANIDAR4_AC1                    _CANIDAR4.Bits.AC1
#define CANIDAR4_AC2                    _CANIDAR4.Bits.AC2
#define CANIDAR4_AC3                    _CANIDAR4.Bits.AC3
#define CANIDAR4_AC4                    _CANIDAR4.Bits.AC4
#define CANIDAR4_AC5                    _CANIDAR4.Bits.AC5
#define CANIDAR4_AC6                    _CANIDAR4.Bits.AC6
#define CANIDAR4_AC7                    _CANIDAR4.Bits.AC7

#define CANIDAR4_AC0_MASK               1U
#define CANIDAR4_AC1_MASK               2U
#define CANIDAR4_AC2_MASK               4U
#define CANIDAR4_AC3_MASK               8U
#define CANIDAR4_AC4_MASK               16U
#define CANIDAR4_AC5_MASK               32U
#define CANIDAR4_AC6_MASK               64U
#define CANIDAR4_AC7_MASK               128U


/*** CANIDAR5 - MSCAN Identifier Acceptance Register 5; 0x00000159 ***/
typedef union {
  byte Byte;
  struct {
    byte AC0         :1;                                       /* Acceptance Code Bit 0 */
    byte AC1         :1;                                       /* Acceptance Code Bit 1 */
    byte AC2         :1;                                       /* Acceptance Code Bit 2 */
    byte AC3         :1;                                       /* Acceptance Code Bit 3 */
    byte AC4         :1;                                       /* Acceptance Code Bit 4 */
    byte AC5         :1;                                       /* Acceptance Code Bit 5 */
    byte AC6         :1;                                       /* Acceptance Code Bit 6 */
    byte AC7         :1;                                       /* Acceptance Code Bit 7 */
  } Bits;
} CANIDAR5STR;
extern volatile CANIDAR5STR _CANIDAR5 @(REG_BASE + 0x00000159UL);
#define CANIDAR5                        _CANIDAR5.Byte
#define CANIDAR5_AC0                    _CANIDAR5.Bits.AC0
#define CANIDAR5_AC1                    _CANIDAR5.Bits.AC1
#define CANIDAR5_AC2                    _CANIDAR5.Bits.AC2
#define CANIDAR5_AC3                    _CANIDAR5.Bits.AC3
#define CANIDAR5_AC4                    _CANIDAR5.Bits.AC4
#define CANIDAR5_AC5                    _CANIDAR5.Bits.AC5
#define CANIDAR5_AC6                    _CANIDAR5.Bits.AC6
#define CANIDAR5_AC7                    _CANIDAR5.Bits.AC7

#define CANIDAR5_AC0_MASK               1U
#define CANIDAR5_AC1_MASK               2U
#define CANIDAR5_AC2_MASK               4U
#define CANIDAR5_AC3_MASK               8U
#define CANIDAR5_AC4_MASK               16U
#define CANIDAR5_AC5_MASK               32U
#define CANIDAR5_AC6_MASK               64U
#define CANIDAR5_AC7_MASK               128U


/*** CANIDAR6 - MSCAN Identifier Acceptance Register 6; 0x0000015A ***/
typedef union {
  byte Byte;
  struct {
    byte AC0         :1;                                       /* Acceptance Code Bit 0 */
    byte AC1         :1;                                       /* Acceptance Code Bit 1 */
    byte AC2         :1;                                       /* Acceptance Code Bit 2 */
    byte AC3         :1;                                       /* Acceptance Code Bit 3 */
    byte AC4         :1;                                       /* Acceptance Code Bit 4 */
    byte AC5         :1;                                       /* Acceptance Code Bit 5 */
    byte AC6         :1;                                       /* Acceptance Code Bit 6 */
    byte AC7         :1;                                       /* Acceptance Code Bit 7 */
  } Bits;
} CANIDAR6STR;
extern volatile CANIDAR6STR _CANIDAR6 @(REG_BASE + 0x0000015AUL);
#define CANIDAR6                        _CANIDAR6.Byte
#define CANIDAR6_AC0                    _CANIDAR6.Bits.AC0
#define CANIDAR6_AC1                    _CANIDAR6.Bits.AC1
#define CANIDAR6_AC2                    _CANIDAR6.Bits.AC2
#define CANIDAR6_AC3                    _CANIDAR6.Bits.AC3
#define CANIDAR6_AC4                    _CANIDAR6.Bits.AC4
#define CANIDAR6_AC5                    _CANIDAR6.Bits.AC5
#define CANIDAR6_AC6                    _CANIDAR6.Bits.AC6
#define CANIDAR6_AC7                    _CANIDAR6.Bits.AC7

#define CANIDAR6_AC0_MASK               1U
#define CANIDAR6_AC1_MASK               2U
#define CANIDAR6_AC2_MASK               4U
#define CANIDAR6_AC3_MASK               8U
#define CANIDAR6_AC4_MASK               16U
#define CANIDAR6_AC5_MASK               32U
#define CANIDAR6_AC6_MASK               64U
#define CANIDAR6_AC7_MASK               128U


/*** CANIDAR7 - MSCAN Identifier Acceptance Register 7; 0x0000015B ***/
typedef union {
  byte Byte;
  struct {
    byte AC0         :1;                                       /* Acceptance Code Bit 0 */
    byte AC1         :1;                                       /* Acceptance Code Bit 1 */
    byte AC2         :1;                                       /* Acceptance Code Bit 2 */
    byte AC3         :1;                                       /* Acceptance Code Bit 3 */
    byte AC4         :1;                                       /* Acceptance Code Bit 4 */
    byte AC5         :1;                                       /* Acceptance Code Bit 5 */
    byte AC6         :1;                                       /* Acceptance Code Bit 6 */
    byte AC7         :1;                                       /* Acceptance Code Bit 7 */
  } Bits;
} CANIDAR7STR;
extern volatile CANIDAR7STR _CANIDAR7 @(REG_BASE + 0x0000015BUL);
#define CANIDAR7                        _CANIDAR7.Byte
#define CANIDAR7_AC0                    _CANIDAR7.Bits.AC0
#define CANIDAR7_AC1                    _CANIDAR7.Bits.AC1
#define CANIDAR7_AC2                    _CANIDAR7.Bits.AC2
#define CANIDAR7_AC3                    _CANIDAR7.Bits.AC3
#define CANIDAR7_AC4                    _CANIDAR7.Bits.AC4
#define CANIDAR7_AC5                    _CANIDAR7.Bits.AC5
#define CANIDAR7_AC6                    _CANIDAR7.Bits.AC6
#define CANIDAR7_AC7                    _CANIDAR7.Bits.AC7

#define CANIDAR7_AC0_MASK               1U
#define CANIDAR7_AC1_MASK               2U
#define CANIDAR7_AC2_MASK               4U
#define CANIDAR7_AC3_MASK               8U
#define CANIDAR7_AC4_MASK               16U
#define CANIDAR7_AC5_MASK               32U
#define CANIDAR7_AC6_MASK               64U
#define CANIDAR7_AC7_MASK               128U


/*** CANIDMR4 - MSCAN Identifier Mask Register 4; 0x0000015C ***/
typedef union {
  byte Byte;
  struct {
    byte AM0         :1;                                       /* Acceptance Mask Bit 0 */
    byte AM1         :1;                                       /* Acceptance Mask Bit 1 */
    byte AM2         :1;                                       /* Acceptance Mask Bit 2 */
    byte AM3         :1;                                       /* Acceptance Mask Bit 3 */
    byte AM4         :1;                                       /* Acceptance Mask Bit 4 */
    byte AM5         :1;                                       /* Acceptance Mask Bit 5 */
    byte AM6         :1;                                       /* Acceptance Mask Bit 6 */
    byte AM7         :1;                                       /* Acceptance Mask Bit 7 */
  } Bits;
} CANIDMR4STR;
extern volatile CANIDMR4STR _CANIDMR4 @(REG_BASE + 0x0000015CUL);
#define CANIDMR4                        _CANIDMR4.Byte
#define CANIDMR4_AM0                    _CANIDMR4.Bits.AM0
#define CANIDMR4_AM1                    _CANIDMR4.Bits.AM1
#define CANIDMR4_AM2                    _CANIDMR4.Bits.AM2
#define CANIDMR4_AM3                    _CANIDMR4.Bits.AM3
#define CANIDMR4_AM4                    _CANIDMR4.Bits.AM4
#define CANIDMR4_AM5                    _CANIDMR4.Bits.AM5
#define CANIDMR4_AM6                    _CANIDMR4.Bits.AM6
#define CANIDMR4_AM7                    _CANIDMR4.Bits.AM7

#define CANIDMR4_AM0_MASK               1U
#define CANIDMR4_AM1_MASK               2U
#define CANIDMR4_AM2_MASK               4U
#define CANIDMR4_AM3_MASK               8U
#define CANIDMR4_AM4_MASK               16U
#define CANIDMR4_AM5_MASK               32U
#define CANIDMR4_AM6_MASK               64U
#define CANIDMR4_AM7_MASK               128U


/*** CANIDMR5 - MSCAN Identifier Mask Register 5; 0x0000015D ***/
typedef union {
  byte Byte;
  struct {
    byte AM0         :1;                                       /* Acceptance Mask Bit 0 */
    byte AM1         :1;                                       /* Acceptance Mask Bit 1 */
    byte AM2         :1;                                       /* Acceptance Mask Bit 2 */
    byte AM3         :1;                                       /* Acceptance Mask Bit 3 */
    byte AM4         :1;                                       /* Acceptance Mask Bit 4 */
    byte AM5         :1;                                       /* Acceptance Mask Bit 5 */
    byte AM6         :1;                                       /* Acceptance Mask Bit 6 */
    byte AM7         :1;                                       /* Acceptance Mask Bit 7 */
  } Bits;
} CANIDMR5STR;
extern volatile CANIDMR5STR _CANIDMR5 @(REG_BASE + 0x0000015DUL);
#define CANIDMR5                        _CANIDMR5.Byte
#define CANIDMR5_AM0                    _CANIDMR5.Bits.AM0
#define CANIDMR5_AM1                    _CANIDMR5.Bits.AM1
#define CANIDMR5_AM2                    _CANIDMR5.Bits.AM2
#define CANIDMR5_AM3                    _CANIDMR5.Bits.AM3
#define CANIDMR5_AM4                    _CANIDMR5.Bits.AM4
#define CANIDMR5_AM5                    _CANIDMR5.Bits.AM5
#define CANIDMR5_AM6                    _CANIDMR5.Bits.AM6
#define CANIDMR5_AM7                    _CANIDMR5.Bits.AM7

#define CANIDMR5_AM0_MASK               1U
#define CANIDMR5_AM1_MASK               2U
#define CANIDMR5_AM2_MASK               4U
#define CANIDMR5_AM3_MASK               8U
#define CANIDMR5_AM4_MASK               16U
#define CANIDMR5_AM5_MASK               32U
#define CANIDMR5_AM6_MASK               64U
#define CANIDMR5_AM7_MASK               128U


/*** CANIDMR6 - MSCAN Identifier Mask Register 6; 0x0000015E ***/
typedef union {
  byte Byte;
  struct {
    byte AM0         :1;                                       /* Acceptance Mask Bit 0 */
    byte AM1         :1;                                       /* Acceptance Mask Bit 1 */
    byte AM2         :1;                                       /* Acceptance Mask Bit 2 */
    byte AM3         :1;                                       /* Acceptance Mask Bit 3 */
    byte AM4         :1;                                       /* Acceptance Mask Bit 4 */
    byte AM5         :1;                                       /* Acceptance Mask Bit 5 */
    byte AM6         :1;                                       /* Acceptance Mask Bit 6 */
    byte AM7         :1;                                       /* Acceptance Mask Bit 7 */
  } Bits;
} CANIDMR6STR;
extern volatile CANIDMR6STR _CANIDMR6 @(REG_BASE + 0x0000015EUL);
#define CANIDMR6                        _CANIDMR6.Byte
#define CANIDMR6_AM0                    _CANIDMR6.Bits.AM0
#define CANIDMR6_AM1                    _CANIDMR6.Bits.AM1
#define CANIDMR6_AM2                    _CANIDMR6.Bits.AM2
#define CANIDMR6_AM3                    _CANIDMR6.Bits.AM3
#define CANIDMR6_AM4                    _CANIDMR6.Bits.AM4
#define CANIDMR6_AM5                    _CANIDMR6.Bits.AM5
#define CANIDMR6_AM6                    _CANIDMR6.Bits.AM6
#define CANIDMR6_AM7                    _CANIDMR6.Bits.AM7

#define CANIDMR6_AM0_MASK               1U
#define CANIDMR6_AM1_MASK               2U
#define CANIDMR6_AM2_MASK               4U
#define CANIDMR6_AM3_MASK               8U
#define CANIDMR6_AM4_MASK               16U
#define CANIDMR6_AM5_MASK               32U
#define CANIDMR6_AM6_MASK               64U
#define CANIDMR6_AM7_MASK               128U


/*** CANIDMR7 - MSCAN Identifier Mask Register 7; 0x0000015F ***/
typedef union {
  byte Byte;
  struct {
    byte AM0         :1;                                       /* Acceptance Mask Bit 0 */
    byte AM1         :1;                                       /* Acceptance Mask Bit 1 */
    byte AM2         :1;                                       /* Acceptance Mask Bit 2 */
    byte AM3         :1;                                       /* Acceptance Mask Bit 3 */
    byte AM4         :1;                                       /* Acceptance Mask Bit 4 */
    byte AM5         :1;                                       /* Acceptance Mask Bit 5 */
    byte AM6         :1;                                       /* Acceptance Mask Bit 6 */
    byte AM7         :1;                                       /* Acceptance Mask Bit 7 */
  } Bits;
} CANIDMR7STR;
extern volatile CANIDMR7STR _CANIDMR7 @(REG_BASE + 0x0000015FUL);
#define CANIDMR7                        _CANIDMR7.Byte
#define CANIDMR7_AM0                    _CANIDMR7.Bits.AM0
#define CANIDMR7_AM1                    _CANIDMR7.Bits.AM1
#define CANIDMR7_AM2                    _CANIDMR7.Bits.AM2
#define CANIDMR7_AM3                    _CANIDMR7.Bits.AM3
#define CANIDMR7_AM4                    _CANIDMR7.Bits.AM4
#define CANIDMR7_AM5                    _CANIDMR7.Bits.AM5
#define CANIDMR7_AM6                    _CANIDMR7.Bits.AM6
#define CANIDMR7_AM7                    _CANIDMR7.Bits.AM7

#define CANIDMR7_AM0_MASK               1U
#define CANIDMR7_AM1_MASK               2U
#define CANIDMR7_AM2_MASK               4U
#define CANIDMR7_AM3_MASK               8U
#define CANIDMR7_AM4_MASK               16U
#define CANIDMR7_AM5_MASK               32U
#define CANIDMR7_AM6_MASK               64U
#define CANIDMR7_AM7_MASK               128U


/*** CANRXIDR0 - MSCAN Receive Identifier Register 0; 0x00000160 ***/
typedef union {
  byte Byte;
  struct {
    byte ID21        :1;                                       /* Extended format identifier Bit 21 */
    byte ID22        :1;                                       /* Extended format identifier Bit 22 */
    byte ID23        :1;                                       /* Extended format identifier Bit 23 */
    byte ID24        :1;                                       /* Extended format identifier Bit 24 */
    byte ID25        :1;                                       /* Extended format identifier Bit 25 */
    byte ID26        :1;                                       /* Extended format identifier Bit 26 */
    byte ID27        :1;                                       /* Extended format identifier Bit 27 */
    byte ID28        :1;                                       /* Extended format identifier Bit 28 */
  } Bits;
} CANRXIDR0STR;
extern volatile CANRXIDR0STR _CANRXIDR0 @(REG_BASE + 0x00000160UL);
#define CANRXIDR0                       _CANRXIDR0.Byte
#define CANRXIDR0_ID21                  _CANRXIDR0.Bits.ID21
#define CANRXIDR0_ID22                  _CANRXIDR0.Bits.ID22
#define CANRXIDR0_ID23                  _CANRXIDR0.Bits.ID23
#define CANRXIDR0_ID24                  _CANRXIDR0.Bits.ID24
#define CANRXIDR0_ID25                  _CANRXIDR0.Bits.ID25
#define CANRXIDR0_ID26                  _CANRXIDR0.Bits.ID26
#define CANRXIDR0_ID27                  _CANRXIDR0.Bits.ID27
#define CANRXIDR0_ID28                  _CANRXIDR0.Bits.ID28
/* CANRXIDR_ARR: Access 4 CANRXIDRx registers in an array */
#define CANRXIDR_ARR                    ((volatile byte *) &CANRXIDR0)

#define CANRXIDR0_ID21_MASK             1U
#define CANRXIDR0_ID22_MASK             2U
#define CANRXIDR0_ID23_MASK             4U
#define CANRXIDR0_ID24_MASK             8U
#define CANRXIDR0_ID25_MASK             16U
#define CANRXIDR0_ID26_MASK             32U
#define CANRXIDR0_ID27_MASK             64U
#define CANRXIDR0_ID28_MASK             128U


/*** CANRXIDR1 - MSCAN Receive Identifier Register 1; 0x00000161 ***/
typedef union {
  byte Byte;
  struct {
    byte ID15        :1;                                       /* Extended format identifier Bit 15 */
    byte ID16        :1;                                       /* Extended format identifier Bit 16 */
    byte ID17        :1;                                       /* Extended format identifier Bit 17 */
    byte IDE         :1;                                       /* ID Extended */
    byte SRR         :1;                                       /* Substitute Remote Request */
    byte ID18        :1;                                       /* Extended format identifier Bit 18 */
    byte ID19        :1;                                       /* Extended format identifier Bit 19 */
    byte ID20        :1;                                       /* Extended format identifier Bit 20 */
  } Bits;
  struct {
    byte grpID_15 :3;
    byte         :1;
    byte         :1;
    byte grpID_18 :3;
  } MergedBits;
} CANRXIDR1STR;
extern volatile CANRXIDR1STR _CANRXIDR1 @(REG_BASE + 0x00000161UL);
#define CANRXIDR1                       _CANRXIDR1.Byte
#define CANRXIDR1_ID15                  _CANRXIDR1.Bits.ID15
#define CANRXIDR1_ID16                  _CANRXIDR1.Bits.ID16
#define CANRXIDR1_ID17                  _CANRXIDR1.Bits.ID17
#define CANRXIDR1_IDE                   _CANRXIDR1.Bits.IDE
#define CANRXIDR1_SRR                   _CANRXIDR1.Bits.SRR
#define CANRXIDR1_ID18                  _CANRXIDR1.Bits.ID18
#define CANRXIDR1_ID19                  _CANRXIDR1.Bits.ID19
#define CANRXIDR1_ID20                  _CANRXIDR1.Bits.ID20
#define CANRXIDR1_ID_15                 _CANRXIDR1.MergedBits.grpID_15
#define CANRXIDR1_ID_18                 _CANRXIDR1.MergedBits.grpID_18
#define CANRXIDR1_ID                    CANRXIDR1_ID_15

#define CANRXIDR1_ID15_MASK             1U
#define CANRXIDR1_ID16_MASK             2U
#define CANRXIDR1_ID17_MASK             4U
#define CANRXIDR1_IDE_MASK              8U
#define CANRXIDR1_SRR_MASK              16U
#define CANRXIDR1_ID18_MASK             32U
#define CANRXIDR1_ID19_MASK             64U
#define CANRXIDR1_ID20_MASK             128U
#define CANRXIDR1_ID_15_MASK            7U
#define CANRXIDR1_ID_15_BITNUM          0U
#define CANRXIDR1_ID_18_MASK            224U
#define CANRXIDR1_ID_18_BITNUM          5U


/*** CANRXIDR2 - MSCAN Receive Identifier Register 2; 0x00000162 ***/
typedef union {
  byte Byte;
  struct {
    byte ID7         :1;                                       /* Extended format identifier Bit 7 */
    byte ID8         :1;                                       /* Extended format identifier Bit 8 */
    byte ID9         :1;                                       /* Extended format identifier Bit 9 */
    byte ID10        :1;                                       /* Extended format identifier Bit 10 */
    byte ID11        :1;                                       /* Extended format identifier Bit 11 */
    byte ID12        :1;                                       /* Extended format identifier Bit 12 */
    byte ID13        :1;                                       /* Extended format identifier Bit 13 */
    byte ID14        :1;                                       /* Extended format identifier Bit 14 */
  } Bits;
} CANRXIDR2STR;
extern volatile CANRXIDR2STR _CANRXIDR2 @(REG_BASE + 0x00000162UL);
#define CANRXIDR2                       _CANRXIDR2.Byte
#define CANRXIDR2_ID7                   _CANRXIDR2.Bits.ID7
#define CANRXIDR2_ID8                   _CANRXIDR2.Bits.ID8
#define CANRXIDR2_ID9                   _CANRXIDR2.Bits.ID9
#define CANRXIDR2_ID10                  _CANRXIDR2.Bits.ID10
#define CANRXIDR2_ID11                  _CANRXIDR2.Bits.ID11
#define CANRXIDR2_ID12                  _CANRXIDR2.Bits.ID12
#define CANRXIDR2_ID13                  _CANRXIDR2.Bits.ID13
#define CANRXIDR2_ID14                  _CANRXIDR2.Bits.ID14

#define CANRXIDR2_ID7_MASK              1U
#define CANRXIDR2_ID8_MASK              2U
#define CANRXIDR2_ID9_MASK              4U
#define CANRXIDR2_ID10_MASK             8U
#define CANRXIDR2_ID11_MASK             16U
#define CANRXIDR2_ID12_MASK             32U
#define CANRXIDR2_ID13_MASK             64U
#define CANRXIDR2_ID14_MASK             128U


/*** CANRXIDR3 - MSCAN Receive Identifier Register 3; 0x00000163 ***/
typedef union {
  byte Byte;
  struct {
    byte RTR         :1;                                       /* Remote Transmission Request */
    byte ID0         :1;                                       /* Extended format identifier Bit 0 */
    byte ID1         :1;                                       /* Extended format identifier Bit 1 */
    byte ID2         :1;                                       /* Extended format identifier Bit 2 */
    byte ID3         :1;                                       /* Extended format identifier Bit 3 */
    byte ID4         :1;                                       /* Extended format identifier Bit 4 */
    byte ID5         :1;                                       /* Extended format identifier Bit 5 */
    byte ID6         :1;                                       /* Extended format identifier Bit 6 */
  } Bits;
  struct {
    byte         :1;
    byte grpID   :7;
  } MergedBits;
} CANRXIDR3STR;
extern volatile CANRXIDR3STR _CANRXIDR3 @(REG_BASE + 0x00000163UL);
#define CANRXIDR3                       _CANRXIDR3.Byte
#define CANRXIDR3_RTR                   _CANRXIDR3.Bits.RTR
#define CANRXIDR3_ID0                   _CANRXIDR3.Bits.ID0
#define CANRXIDR3_ID1                   _CANRXIDR3.Bits.ID1
#define CANRXIDR3_ID2                   _CANRXIDR3.Bits.ID2
#define CANRXIDR3_ID3                   _CANRXIDR3.Bits.ID3
#define CANRXIDR3_ID4                   _CANRXIDR3.Bits.ID4
#define CANRXIDR3_ID5                   _CANRXIDR3.Bits.ID5
#define CANRXIDR3_ID6                   _CANRXIDR3.Bits.ID6
#define CANRXIDR3_ID                    _CANRXIDR3.MergedBits.grpID

#define CANRXIDR3_RTR_MASK              1U
#define CANRXIDR3_ID0_MASK              2U
#define CANRXIDR3_ID1_MASK              4U
#define CANRXIDR3_ID2_MASK              8U
#define CANRXIDR3_ID3_MASK              16U
#define CANRXIDR3_ID4_MASK              32U
#define CANRXIDR3_ID5_MASK              64U
#define CANRXIDR3_ID6_MASK              128U
#define CANRXIDR3_ID_MASK               254U
#define CANRXIDR3_ID_BITNUM             1U


/*** CANRXDSR0 - MSCAN Receive Data Segment Register 0; 0x00000164 ***/
typedef union {
  byte Byte;
  struct {
    byte DB0         :1;                                       /* Data Bit 0 */
    byte DB1         :1;                                       /* Data Bit 1 */
    byte DB2         :1;                                       /* Data Bit 2 */
    byte DB3         :1;                                       /* Data Bit 3 */
    byte DB4         :1;                                       /* Data Bit 4 */
    byte DB5         :1;                                       /* Data Bit 5 */
    byte DB6         :1;                                       /* Data Bit 6 */
    byte DB7         :1;                                       /* Data Bit 7 */
  } Bits;
} CANRXDSR0STR;
extern volatile CANRXDSR0STR _CANRXDSR0 @(REG_BASE + 0x00000164UL);
#define CANRXDSR0                       _CANRXDSR0.Byte
#define CANRXDSR0_DB0                   _CANRXDSR0.Bits.DB0
#define CANRXDSR0_DB1                   _CANRXDSR0.Bits.DB1
#define CANRXDSR0_DB2                   _CANRXDSR0.Bits.DB2
#define CANRXDSR0_DB3                   _CANRXDSR0.Bits.DB3
#define CANRXDSR0_DB4                   _CANRXDSR0.Bits.DB4
#define CANRXDSR0_DB5                   _CANRXDSR0.Bits.DB5
#define CANRXDSR0_DB6                   _CANRXDSR0.Bits.DB6
#define CANRXDSR0_DB7                   _CANRXDSR0.Bits.DB7
/* CANRXDSR_ARR: Access 8 CANRXDSRx registers in an array */
#define CANRXDSR_ARR                    ((volatile byte *) &CANRXDSR0)

#define CANRXDSR0_DB0_MASK              1U
#define CANRXDSR0_DB1_MASK              2U
#define CANRXDSR0_DB2_MASK              4U
#define CANRXDSR0_DB3_MASK              8U
#define CANRXDSR0_DB4_MASK              16U
#define CANRXDSR0_DB5_MASK              32U
#define CANRXDSR0_DB6_MASK              64U
#define CANRXDSR0_DB7_MASK              128U


/*** CANRXDSR1 - MSCAN Receive Data Segment Register 1; 0x00000165 ***/
typedef union {
  byte Byte;
  struct {
    byte DB0         :1;                                       /* Data Bit 0 */
    byte DB1         :1;                                       /* Data Bit 1 */
    byte DB2         :1;                                       /* Data Bit 2 */
    byte DB3         :1;                                       /* Data Bit 3 */
    byte DB4         :1;                                       /* Data Bit 4 */
    byte DB5         :1;                                       /* Data Bit 5 */
    byte DB6         :1;                                       /* Data Bit 6 */
    byte DB7         :1;                                       /* Data Bit 7 */
  } Bits;
} CANRXDSR1STR;
extern volatile CANRXDSR1STR _CANRXDSR1 @(REG_BASE + 0x00000165UL);
#define CANRXDSR1                       _CANRXDSR1.Byte
#define CANRXDSR1_DB0                   _CANRXDSR1.Bits.DB0
#define CANRXDSR1_DB1                   _CANRXDSR1.Bits.DB1
#define CANRXDSR1_DB2                   _CANRXDSR1.Bits.DB2
#define CANRXDSR1_DB3                   _CANRXDSR1.Bits.DB3
#define CANRXDSR1_DB4                   _CANRXDSR1.Bits.DB4
#define CANRXDSR1_DB5                   _CANRXDSR1.Bits.DB5
#define CANRXDSR1_DB6                   _CANRXDSR1.Bits.DB6
#define CANRXDSR1_DB7                   _CANRXDSR1.Bits.DB7

#define CANRXDSR1_DB0_MASK              1U
#define CANRXDSR1_DB1_MASK              2U
#define CANRXDSR1_DB2_MASK              4U
#define CANRXDSR1_DB3_MASK              8U
#define CANRXDSR1_DB4_MASK              16U
#define CANRXDSR1_DB5_MASK              32U
#define CANRXDSR1_DB6_MASK              64U
#define CANRXDSR1_DB7_MASK              128U


/*** CANRXDSR2 - MSCAN Receive Data Segment Register 2; 0x00000166 ***/
typedef union {
  byte Byte;
  struct {
    byte DB0         :1;                                       /* Data Bit 0 */
    byte DB1         :1;                                       /* Data Bit 1 */
    byte DB2         :1;                                       /* Data Bit 2 */
    byte DB3         :1;                                       /* Data Bit 3 */
    byte DB4         :1;                                       /* Data Bit 4 */
    byte DB5         :1;                                       /* Data Bit 5 */
    byte DB6         :1;                                       /* Data Bit 6 */
    byte DB7         :1;                                       /* Data Bit 7 */
  } Bits;
} CANRXDSR2STR;
extern volatile CANRXDSR2STR _CANRXDSR2 @(REG_BASE + 0x00000166UL);
#define CANRXDSR2                       _CANRXDSR2.Byte
#define CANRXDSR2_DB0                   _CANRXDSR2.Bits.DB0
#define CANRXDSR2_DB1                   _CANRXDSR2.Bits.DB1
#define CANRXDSR2_DB2                   _CANRXDSR2.Bits.DB2
#define CANRXDSR2_DB3                   _CANRXDSR2.Bits.DB3
#define CANRXDSR2_DB4                   _CANRXDSR2.Bits.DB4
#define CANRXDSR2_DB5                   _CANRXDSR2.Bits.DB5
#define CANRXDSR2_DB6                   _CANRXDSR2.Bits.DB6
#define CANRXDSR2_DB7                   _CANRXDSR2.Bits.DB7

#define CANRXDSR2_DB0_MASK              1U
#define CANRXDSR2_DB1_MASK              2U
#define CANRXDSR2_DB2_MASK              4U
#define CANRXDSR2_DB3_MASK              8U
#define CANRXDSR2_DB4_MASK              16U
#define CANRXDSR2_DB5_MASK              32U
#define CANRXDSR2_DB6_MASK              64U
#define CANRXDSR2_DB7_MASK              128U


/*** CANRXDSR3 - MSCAN Receive Data Segment Register 3; 0x00000167 ***/
typedef union {
  byte Byte;
  struct {
    byte DB0         :1;                                       /* Data Bit 0 */
    byte DB1         :1;                                       /* Data Bit 1 */
    byte DB2         :1;                                       /* Data Bit 2 */
    byte DB3         :1;                                       /* Data Bit 3 */
    byte DB4         :1;                                       /* Data Bit 4 */
    byte DB5         :1;                                       /* Data Bit 5 */
    byte DB6         :1;                                       /* Data Bit 6 */
    byte DB7         :1;                                       /* Data Bit 7 */
  } Bits;
} CANRXDSR3STR;
extern volatile CANRXDSR3STR _CANRXDSR3 @(REG_BASE + 0x00000167UL);
#define CANRXDSR3                       _CANRXDSR3.Byte
#define CANRXDSR3_DB0                   _CANRXDSR3.Bits.DB0
#define CANRXDSR3_DB1                   _CANRXDSR3.Bits.DB1
#define CANRXDSR3_DB2                   _CANRXDSR3.Bits.DB2
#define CANRXDSR3_DB3                   _CANRXDSR3.Bits.DB3
#define CANRXDSR3_DB4                   _CANRXDSR3.Bits.DB4
#define CANRXDSR3_DB5                   _CANRXDSR3.Bits.DB5
#define CANRXDSR3_DB6                   _CANRXDSR3.Bits.DB6
#define CANRXDSR3_DB7                   _CANRXDSR3.Bits.DB7

#define CANRXDSR3_DB0_MASK              1U
#define CANRXDSR3_DB1_MASK              2U
#define CANRXDSR3_DB2_MASK              4U
#define CANRXDSR3_DB3_MASK              8U
#define CANRXDSR3_DB4_MASK              16U
#define CANRXDSR3_DB5_MASK              32U
#define CANRXDSR3_DB6_MASK              64U
#define CANRXDSR3_DB7_MASK              128U


/*** CANRXDSR4 - MSCAN Receive Data Segment Register 4; 0x00000168 ***/
typedef union {
  byte Byte;
  struct {
    byte DB0         :1;                                       /* Data Bit 0 */
    byte DB1         :1;                                       /* Data Bit 1 */
    byte DB2         :1;                                       /* Data Bit 2 */
    byte DB3         :1;                                       /* Data Bit 3 */
    byte DB4         :1;                                       /* Data Bit 4 */
    byte DB5         :1;                                       /* Data Bit 5 */
    byte DB6         :1;                                       /* Data Bit 6 */
    byte DB7         :1;                                       /* Data Bit 7 */
  } Bits;
} CANRXDSR4STR;
extern volatile CANRXDSR4STR _CANRXDSR4 @(REG_BASE + 0x00000168UL);
#define CANRXDSR4                       _CANRXDSR4.Byte
#define CANRXDSR4_DB0                   _CANRXDSR4.Bits.DB0
#define CANRXDSR4_DB1                   _CANRXDSR4.Bits.DB1
#define CANRXDSR4_DB2                   _CANRXDSR4.Bits.DB2
#define CANRXDSR4_DB3                   _CANRXDSR4.Bits.DB3
#define CANRXDSR4_DB4                   _CANRXDSR4.Bits.DB4
#define CANRXDSR4_DB5                   _CANRXDSR4.Bits.DB5
#define CANRXDSR4_DB6                   _CANRXDSR4.Bits.DB6
#define CANRXDSR4_DB7                   _CANRXDSR4.Bits.DB7

#define CANRXDSR4_DB0_MASK              1U
#define CANRXDSR4_DB1_MASK              2U
#define CANRXDSR4_DB2_MASK              4U
#define CANRXDSR4_DB3_MASK              8U
#define CANRXDSR4_DB4_MASK              16U
#define CANRXDSR4_DB5_MASK              32U
#define CANRXDSR4_DB6_MASK              64U
#define CANRXDSR4_DB7_MASK              128U


/*** CANRXDSR5 - MSCAN Receive Data Segment Register 5; 0x00000169 ***/
typedef union {
  byte Byte;
  struct {
    byte DB0         :1;                                       /* Data Bit 0 */
    byte DB1         :1;                                       /* Data Bit 1 */
    byte DB2         :1;                                       /* Data Bit 2 */
    byte DB3         :1;                                       /* Data Bit 3 */
    byte DB4         :1;                                       /* Data Bit 4 */
    byte DB5         :1;                                       /* Data Bit 5 */
    byte DB6         :1;                                       /* Data Bit 6 */
    byte DB7         :1;                                       /* Data Bit 7 */
  } Bits;
} CANRXDSR5STR;
extern volatile CANRXDSR5STR _CANRXDSR5 @(REG_BASE + 0x00000169UL);
#define CANRXDSR5                       _CANRXDSR5.Byte
#define CANRXDSR5_DB0                   _CANRXDSR5.Bits.DB0
#define CANRXDSR5_DB1                   _CANRXDSR5.Bits.DB1
#define CANRXDSR5_DB2                   _CANRXDSR5.Bits.DB2
#define CANRXDSR5_DB3                   _CANRXDSR5.Bits.DB3
#define CANRXDSR5_DB4                   _CANRXDSR5.Bits.DB4
#define CANRXDSR5_DB5                   _CANRXDSR5.Bits.DB5
#define CANRXDSR5_DB6                   _CANRXDSR5.Bits.DB6
#define CANRXDSR5_DB7                   _CANRXDSR5.Bits.DB7

#define CANRXDSR5_DB0_MASK              1U
#define CANRXDSR5_DB1_MASK              2U
#define CANRXDSR5_DB2_MASK              4U
#define CANRXDSR5_DB3_MASK              8U
#define CANRXDSR5_DB4_MASK              16U
#define CANRXDSR5_DB5_MASK              32U
#define CANRXDSR5_DB6_MASK              64U
#define CANRXDSR5_DB7_MASK              128U


/*** CANRXDSR6 - MSCAN Receive Data Segment Register 6; 0x0000016A ***/
typedef union {
  byte Byte;
  struct {
    byte DB0         :1;                                       /* Data Bit 0 */
    byte DB1         :1;                                       /* Data Bit 1 */
    byte DB2         :1;                                       /* Data Bit 2 */
    byte DB3         :1;                                       /* Data Bit 3 */
    byte DB4         :1;                                       /* Data Bit 4 */
    byte DB5         :1;                                       /* Data Bit 5 */
    byte DB6         :1;                                       /* Data Bit 6 */
    byte DB7         :1;                                       /* Data Bit 7 */
  } Bits;
} CANRXDSR6STR;
extern volatile CANRXDSR6STR _CANRXDSR6 @(REG_BASE + 0x0000016AUL);
#define CANRXDSR6                       _CANRXDSR6.Byte
#define CANRXDSR6_DB0                   _CANRXDSR6.Bits.DB0
#define CANRXDSR6_DB1                   _CANRXDSR6.Bits.DB1
#define CANRXDSR6_DB2                   _CANRXDSR6.Bits.DB2
#define CANRXDSR6_DB3                   _CANRXDSR6.Bits.DB3
#define CANRXDSR6_DB4                   _CANRXDSR6.Bits.DB4
#define CANRXDSR6_DB5                   _CANRXDSR6.Bits.DB5
#define CANRXDSR6_DB6                   _CANRXDSR6.Bits.DB6
#define CANRXDSR6_DB7                   _CANRXDSR6.Bits.DB7

#define CANRXDSR6_DB0_MASK              1U
#define CANRXDSR6_DB1_MASK              2U
#define CANRXDSR6_DB2_MASK              4U
#define CANRXDSR6_DB3_MASK              8U
#define CANRXDSR6_DB4_MASK              16U
#define CANRXDSR6_DB5_MASK              32U
#define CANRXDSR6_DB6_MASK              64U
#define CANRXDSR6_DB7_MASK              128U


/*** CANRXDSR7 - MSCAN Receive Data Segment Register 7; 0x0000016B ***/
typedef union {
  byte Byte;
  struct {
    byte DB0         :1;                                       /* Data Bit 0 */
    byte DB1         :1;                                       /* Data Bit 1 */
    byte DB2         :1;                                       /* Data Bit 2 */
    byte DB3         :1;                                       /* Data Bit 3 */
    byte DB4         :1;                                       /* Data Bit 4 */
    byte DB5         :1;                                       /* Data Bit 5 */
    byte DB6         :1;                                       /* Data Bit 6 */
    byte DB7         :1;                                       /* Data Bit 7 */
  } Bits;
} CANRXDSR7STR;
extern volatile CANRXDSR7STR _CANRXDSR7 @(REG_BASE + 0x0000016BUL);
#define CANRXDSR7                       _CANRXDSR7.Byte
#define CANRXDSR7_DB0                   _CANRXDSR7.Bits.DB0
#define CANRXDSR7_DB1                   _CANRXDSR7.Bits.DB1
#define CANRXDSR7_DB2                   _CANRXDSR7.Bits.DB2
#define CANRXDSR7_DB3                   _CANRXDSR7.Bits.DB3
#define CANRXDSR7_DB4                   _CANRXDSR7.Bits.DB4
#define CANRXDSR7_DB5                   _CANRXDSR7.Bits.DB5
#define CANRXDSR7_DB6                   _CANRXDSR7.Bits.DB6
#define CANRXDSR7_DB7                   _CANRXDSR7.Bits.DB7

#define CANRXDSR7_DB0_MASK              1U
#define CANRXDSR7_DB1_MASK              2U
#define CANRXDSR7_DB2_MASK              4U
#define CANRXDSR7_DB3_MASK              8U
#define CANRXDSR7_DB4_MASK              16U
#define CANRXDSR7_DB5_MASK              32U
#define CANRXDSR7_DB6_MASK              64U
#define CANRXDSR7_DB7_MASK              128U


/*** CANRXDLR - MSCAN Receive Data Length Register; 0x0000016C ***/
typedef union {
  byte Byte;
  struct {
    byte DLC0        :1;                                       /* Data Length Code Bit 0 */
    byte DLC1        :1;                                       /* Data Length Code Bit 1 */
    byte DLC2        :1;                                       /* Data Length Code Bit 2 */
    byte DLC3        :1;                                       /* Data Length Code Bit 3 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpDLC  :4;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} CANRXDLRSTR;
extern volatile CANRXDLRSTR _CANRXDLR @(REG_BASE + 0x0000016CUL);
#define CANRXDLR                        _CANRXDLR.Byte
#define CANRXDLR_DLC0                   _CANRXDLR.Bits.DLC0
#define CANRXDLR_DLC1                   _CANRXDLR.Bits.DLC1
#define CANRXDLR_DLC2                   _CANRXDLR.Bits.DLC2
#define CANRXDLR_DLC3                   _CANRXDLR.Bits.DLC3
#define CANRXDLR_DLC                    _CANRXDLR.MergedBits.grpDLC

#define CANRXDLR_DLC0_MASK              1U
#define CANRXDLR_DLC1_MASK              2U
#define CANRXDLR_DLC2_MASK              4U
#define CANRXDLR_DLC3_MASK              8U
#define CANRXDLR_DLC_MASK               15U
#define CANRXDLR_DLC_BITNUM             0U


/*** CANRXTSR - MSCAN Receive Time Stamp Register; 0x0000016E ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** CANRXTSRH - MSCAN Receive Time Stamp Register High; 0x0000016E ***/
    union {
      byte Byte;
      struct {
        byte TSR8        :1;                                       /* Time Stamp Bit 8 */
        byte TSR9        :1;                                       /* Time Stamp Bit 9 */
        byte TSR10       :1;                                       /* Time Stamp Bit 10 */
        byte TSR11       :1;                                       /* Time Stamp Bit 11 */
        byte TSR12       :1;                                       /* Time Stamp Bit 12 */
        byte TSR13       :1;                                       /* Time Stamp Bit 13 */
        byte TSR14       :1;                                       /* Time Stamp Bit 14 */
        byte TSR15       :1;                                       /* Time Stamp Bit 15 */
      } Bits;
    } CANRXTSRHSTR;
    #define CANRXTSRH                   _CANRXTSR.Overlap_STR.CANRXTSRHSTR.Byte
    #define CANRXTSRH_TSR8              _CANRXTSR.Overlap_STR.CANRXTSRHSTR.Bits.TSR8
    #define CANRXTSRH_TSR9              _CANRXTSR.Overlap_STR.CANRXTSRHSTR.Bits.TSR9
    #define CANRXTSRH_TSR10             _CANRXTSR.Overlap_STR.CANRXTSRHSTR.Bits.TSR10
    #define CANRXTSRH_TSR11             _CANRXTSR.Overlap_STR.CANRXTSRHSTR.Bits.TSR11
    #define CANRXTSRH_TSR12             _CANRXTSR.Overlap_STR.CANRXTSRHSTR.Bits.TSR12
    #define CANRXTSRH_TSR13             _CANRXTSR.Overlap_STR.CANRXTSRHSTR.Bits.TSR13
    #define CANRXTSRH_TSR14             _CANRXTSR.Overlap_STR.CANRXTSRHSTR.Bits.TSR14
    #define CANRXTSRH_TSR15             _CANRXTSR.Overlap_STR.CANRXTSRHSTR.Bits.TSR15
    
    #define CANRXTSRH_TSR8_MASK         1U
    #define CANRXTSRH_TSR9_MASK         2U
    #define CANRXTSRH_TSR10_MASK        4U
    #define CANRXTSRH_TSR11_MASK        8U
    #define CANRXTSRH_TSR12_MASK        16U
    #define CANRXTSRH_TSR13_MASK        32U
    #define CANRXTSRH_TSR14_MASK        64U
    #define CANRXTSRH_TSR15_MASK        128U
    

    /*** CANRXTSRL - MSCAN Receive Time Stamp Register Low; 0x0000016F ***/
    union {
      byte Byte;
      struct {
        byte TSR0        :1;                                       /* Time Stamp Bit 0 */
        byte TSR1        :1;                                       /* Time Stamp Bit 1 */
        byte TSR2        :1;                                       /* Time Stamp Bit 2 */
        byte TSR3        :1;                                       /* Time Stamp Bit 3 */
        byte TSR4        :1;                                       /* Time Stamp Bit 4 */
        byte TSR5        :1;                                       /* Time Stamp Bit 5 */
        byte TSR6        :1;                                       /* Time Stamp Bit 6 */
        byte TSR7        :1;                                       /* Time Stamp Bit 7 */
      } Bits;
    } CANRXTSRLSTR;
    #define CANRXTSRL                   _CANRXTSR.Overlap_STR.CANRXTSRLSTR.Byte
    #define CANRXTSRL_TSR0              _CANRXTSR.Overlap_STR.CANRXTSRLSTR.Bits.TSR0
    #define CANRXTSRL_TSR1              _CANRXTSR.Overlap_STR.CANRXTSRLSTR.Bits.TSR1
    #define CANRXTSRL_TSR2              _CANRXTSR.Overlap_STR.CANRXTSRLSTR.Bits.TSR2
    #define CANRXTSRL_TSR3              _CANRXTSR.Overlap_STR.CANRXTSRLSTR.Bits.TSR3
    #define CANRXTSRL_TSR4              _CANRXTSR.Overlap_STR.CANRXTSRLSTR.Bits.TSR4
    #define CANRXTSRL_TSR5              _CANRXTSR.Overlap_STR.CANRXTSRLSTR.Bits.TSR5
    #define CANRXTSRL_TSR6              _CANRXTSR.Overlap_STR.CANRXTSRLSTR.Bits.TSR6
    #define CANRXTSRL_TSR7              _CANRXTSR.Overlap_STR.CANRXTSRLSTR.Bits.TSR7
    
    #define CANRXTSRL_TSR0_MASK         1U
    #define CANRXTSRL_TSR1_MASK         2U
    #define CANRXTSRL_TSR2_MASK         4U
    #define CANRXTSRL_TSR3_MASK         8U
    #define CANRXTSRL_TSR4_MASK         16U
    #define CANRXTSRL_TSR5_MASK         32U
    #define CANRXTSRL_TSR6_MASK         64U
    #define CANRXTSRL_TSR7_MASK         128U
    
  } Overlap_STR;

  struct {
    word TSR0        :1;                                       /* Time Stamp Bit 0 */
    word TSR1        :1;                                       /* Time Stamp Bit 1 */
    word TSR2        :1;                                       /* Time Stamp Bit 2 */
    word TSR3        :1;                                       /* Time Stamp Bit 3 */
    word TSR4        :1;                                       /* Time Stamp Bit 4 */
    word TSR5        :1;                                       /* Time Stamp Bit 5 */
    word TSR6        :1;                                       /* Time Stamp Bit 6 */
    word TSR7        :1;                                       /* Time Stamp Bit 7 */
    word TSR8        :1;                                       /* Time Stamp Bit 8 */
    word TSR9        :1;                                       /* Time Stamp Bit 9 */
    word TSR10       :1;                                       /* Time Stamp Bit 10 */
    word TSR11       :1;                                       /* Time Stamp Bit 11 */
    word TSR12       :1;                                       /* Time Stamp Bit 12 */
    word TSR13       :1;                                       /* Time Stamp Bit 13 */
    word TSR14       :1;                                       /* Time Stamp Bit 14 */
    word TSR15       :1;                                       /* Time Stamp Bit 15 */
  } Bits;
} CANRXTSRSTR;
extern volatile CANRXTSRSTR _CANRXTSR @(REG_BASE + 0x0000016EUL);
#define CANRXTSR                        _CANRXTSR.Word
#define CANRXTSR_TSR0                   _CANRXTSR.Bits.TSR0
#define CANRXTSR_TSR1                   _CANRXTSR.Bits.TSR1
#define CANRXTSR_TSR2                   _CANRXTSR.Bits.TSR2
#define CANRXTSR_TSR3                   _CANRXTSR.Bits.TSR3
#define CANRXTSR_TSR4                   _CANRXTSR.Bits.TSR4
#define CANRXTSR_TSR5                   _CANRXTSR.Bits.TSR5
#define CANRXTSR_TSR6                   _CANRXTSR.Bits.TSR6
#define CANRXTSR_TSR7                   _CANRXTSR.Bits.TSR7
#define CANRXTSR_TSR8                   _CANRXTSR.Bits.TSR8
#define CANRXTSR_TSR9                   _CANRXTSR.Bits.TSR9
#define CANRXTSR_TSR10                  _CANRXTSR.Bits.TSR10
#define CANRXTSR_TSR11                  _CANRXTSR.Bits.TSR11
#define CANRXTSR_TSR12                  _CANRXTSR.Bits.TSR12
#define CANRXTSR_TSR13                  _CANRXTSR.Bits.TSR13
#define CANRXTSR_TSR14                  _CANRXTSR.Bits.TSR14
#define CANRXTSR_TSR15                  _CANRXTSR.Bits.TSR15

#define CANRXTSR_TSR0_MASK              1U
#define CANRXTSR_TSR1_MASK              2U
#define CANRXTSR_TSR2_MASK              4U
#define CANRXTSR_TSR3_MASK              8U
#define CANRXTSR_TSR4_MASK              16U
#define CANRXTSR_TSR5_MASK              32U
#define CANRXTSR_TSR6_MASK              64U
#define CANRXTSR_TSR7_MASK              128U
#define CANRXTSR_TSR8_MASK              256U
#define CANRXTSR_TSR9_MASK              512U
#define CANRXTSR_TSR10_MASK             1024U
#define CANRXTSR_TSR11_MASK             2048U
#define CANRXTSR_TSR12_MASK             4096U
#define CANRXTSR_TSR13_MASK             8192U
#define CANRXTSR_TSR14_MASK             16384U
#define CANRXTSR_TSR15_MASK             32768U


/*** CANTXIDR0 - MSCAN Transmit Identifier Register 0; 0x00000170 ***/
typedef union {
  byte Byte;
  struct {
    byte ID21        :1;                                       /* Extended format identifier Bit 21 */
    byte ID22        :1;                                       /* Extended format identifier Bit 22 */
    byte ID23        :1;                                       /* Extended format identifier Bit 23 */
    byte ID24        :1;                                       /* Extended format identifier Bit 24 */
    byte ID25        :1;                                       /* Extended format identifier Bit 25 */
    byte ID26        :1;                                       /* Extended format identifier Bit 26 */
    byte ID27        :1;                                       /* Extended format identifier Bit 27 */
    byte ID28        :1;                                       /* Extended format identifier Bit 28 */
  } Bits;
} CANTXIDR0STR;
extern volatile CANTXIDR0STR _CANTXIDR0 @(REG_BASE + 0x00000170UL);
#define CANTXIDR0                       _CANTXIDR0.Byte
#define CANTXIDR0_ID21                  _CANTXIDR0.Bits.ID21
#define CANTXIDR0_ID22                  _CANTXIDR0.Bits.ID22
#define CANTXIDR0_ID23                  _CANTXIDR0.Bits.ID23
#define CANTXIDR0_ID24                  _CANTXIDR0.Bits.ID24
#define CANTXIDR0_ID25                  _CANTXIDR0.Bits.ID25
#define CANTXIDR0_ID26                  _CANTXIDR0.Bits.ID26
#define CANTXIDR0_ID27                  _CANTXIDR0.Bits.ID27
#define CANTXIDR0_ID28                  _CANTXIDR0.Bits.ID28
/* CANTXIDR_ARR: Access 4 CANTXIDRx registers in an array */
#define CANTXIDR_ARR                    ((volatile byte *) &CANTXIDR0)

#define CANTXIDR0_ID21_MASK             1U
#define CANTXIDR0_ID22_MASK             2U
#define CANTXIDR0_ID23_MASK             4U
#define CANTXIDR0_ID24_MASK             8U
#define CANTXIDR0_ID25_MASK             16U
#define CANTXIDR0_ID26_MASK             32U
#define CANTXIDR0_ID27_MASK             64U
#define CANTXIDR0_ID28_MASK             128U


/*** CANTXIDR1 - MSCAN Transmit Identifier Register 1; 0x00000171 ***/
typedef union {
  byte Byte;
  struct {
    byte ID15        :1;                                       /* Extended format identifier Bit 15 */
    byte ID16        :1;                                       /* Extended format identifier Bit 16 */
    byte ID17        :1;                                       /* Extended format identifier Bit 17 */
    byte IDE         :1;                                       /* ID Extended */
    byte SRR         :1;                                       /* Substitute Remote Request */
    byte ID18        :1;                                       /* Extended format identifier Bit 18 */
    byte ID19        :1;                                       /* Extended format identifier Bit 19 */
    byte ID20        :1;                                       /* Extended format identifier Bit 20 */
  } Bits;
  struct {
    byte grpID_15 :3;
    byte         :1;
    byte         :1;
    byte grpID_18 :3;
  } MergedBits;
} CANTXIDR1STR;
extern volatile CANTXIDR1STR _CANTXIDR1 @(REG_BASE + 0x00000171UL);
#define CANTXIDR1                       _CANTXIDR1.Byte
#define CANTXIDR1_ID15                  _CANTXIDR1.Bits.ID15
#define CANTXIDR1_ID16                  _CANTXIDR1.Bits.ID16
#define CANTXIDR1_ID17                  _CANTXIDR1.Bits.ID17
#define CANTXIDR1_IDE                   _CANTXIDR1.Bits.IDE
#define CANTXIDR1_SRR                   _CANTXIDR1.Bits.SRR
#define CANTXIDR1_ID18                  _CANTXIDR1.Bits.ID18
#define CANTXIDR1_ID19                  _CANTXIDR1.Bits.ID19
#define CANTXIDR1_ID20                  _CANTXIDR1.Bits.ID20
#define CANTXIDR1_ID_15                 _CANTXIDR1.MergedBits.grpID_15
#define CANTXIDR1_ID_18                 _CANTXIDR1.MergedBits.grpID_18
#define CANTXIDR1_ID                    CANTXIDR1_ID_15

#define CANTXIDR1_ID15_MASK             1U
#define CANTXIDR1_ID16_MASK             2U
#define CANTXIDR1_ID17_MASK             4U
#define CANTXIDR1_IDE_MASK              8U
#define CANTXIDR1_SRR_MASK              16U
#define CANTXIDR1_ID18_MASK             32U
#define CANTXIDR1_ID19_MASK             64U
#define CANTXIDR1_ID20_MASK             128U
#define CANTXIDR1_ID_15_MASK            7U
#define CANTXIDR1_ID_15_BITNUM          0U
#define CANTXIDR1_ID_18_MASK            224U
#define CANTXIDR1_ID_18_BITNUM          5U


/*** CANTXIDR2 - MSCAN Transmit Identifier Register 2; 0x00000172 ***/
typedef union {
  byte Byte;
  struct {
    byte ID7         :1;                                       /* Extended format identifier Bit 7 */
    byte ID8         :1;                                       /* Extended format identifier Bit 8 */
    byte ID9         :1;                                       /* Extended format identifier Bit 9 */
    byte ID10        :1;                                       /* Extended format identifier Bit 10 */
    byte ID11        :1;                                       /* Extended format identifier Bit 11 */
    byte ID12        :1;                                       /* Extended format identifier Bit 12 */
    byte ID13        :1;                                       /* Extended format identifier Bit 13 */
    byte ID14        :1;                                       /* Extended format identifier Bit 14 */
  } Bits;
} CANTXIDR2STR;
extern volatile CANTXIDR2STR _CANTXIDR2 @(REG_BASE + 0x00000172UL);
#define CANTXIDR2                       _CANTXIDR2.Byte
#define CANTXIDR2_ID7                   _CANTXIDR2.Bits.ID7
#define CANTXIDR2_ID8                   _CANTXIDR2.Bits.ID8
#define CANTXIDR2_ID9                   _CANTXIDR2.Bits.ID9
#define CANTXIDR2_ID10                  _CANTXIDR2.Bits.ID10
#define CANTXIDR2_ID11                  _CANTXIDR2.Bits.ID11
#define CANTXIDR2_ID12                  _CANTXIDR2.Bits.ID12
#define CANTXIDR2_ID13                  _CANTXIDR2.Bits.ID13
#define CANTXIDR2_ID14                  _CANTXIDR2.Bits.ID14

#define CANTXIDR2_ID7_MASK              1U
#define CANTXIDR2_ID8_MASK              2U
#define CANTXIDR2_ID9_MASK              4U
#define CANTXIDR2_ID10_MASK             8U
#define CANTXIDR2_ID11_MASK             16U
#define CANTXIDR2_ID12_MASK             32U
#define CANTXIDR2_ID13_MASK             64U
#define CANTXIDR2_ID14_MASK             128U


/*** CANTXIDR3 - MSCAN Transmit Identifier Register 3; 0x00000173 ***/
typedef union {
  byte Byte;
  struct {
    byte RTR         :1;                                       /* Remote Transmission Request */
    byte ID0         :1;                                       /* Extended format identifier Bit 0 */
    byte ID1         :1;                                       /* Extended format identifier Bit 1 */
    byte ID2         :1;                                       /* Extended format identifier Bit 2 */
    byte ID3         :1;                                       /* Extended format identifier Bit 3 */
    byte ID4         :1;                                       /* Extended format identifier Bit 4 */
    byte ID5         :1;                                       /* Extended format identifier Bit 5 */
    byte ID6         :1;                                       /* Extended format identifier Bit 6 */
  } Bits;
  struct {
    byte         :1;
    byte grpID   :7;
  } MergedBits;
} CANTXIDR3STR;
extern volatile CANTXIDR3STR _CANTXIDR3 @(REG_BASE + 0x00000173UL);
#define CANTXIDR3                       _CANTXIDR3.Byte
#define CANTXIDR3_RTR                   _CANTXIDR3.Bits.RTR
#define CANTXIDR3_ID0                   _CANTXIDR3.Bits.ID0
#define CANTXIDR3_ID1                   _CANTXIDR3.Bits.ID1
#define CANTXIDR3_ID2                   _CANTXIDR3.Bits.ID2
#define CANTXIDR3_ID3                   _CANTXIDR3.Bits.ID3
#define CANTXIDR3_ID4                   _CANTXIDR3.Bits.ID4
#define CANTXIDR3_ID5                   _CANTXIDR3.Bits.ID5
#define CANTXIDR3_ID6                   _CANTXIDR3.Bits.ID6
#define CANTXIDR3_ID                    _CANTXIDR3.MergedBits.grpID

#define CANTXIDR3_RTR_MASK              1U
#define CANTXIDR3_ID0_MASK              2U
#define CANTXIDR3_ID1_MASK              4U
#define CANTXIDR3_ID2_MASK              8U
#define CANTXIDR3_ID3_MASK              16U
#define CANTXIDR3_ID4_MASK              32U
#define CANTXIDR3_ID5_MASK              64U
#define CANTXIDR3_ID6_MASK              128U
#define CANTXIDR3_ID_MASK               254U
#define CANTXIDR3_ID_BITNUM             1U


/*** CANTXDSR0 - MSCAN Transmit Data Segment Register 0; 0x00000174 ***/
typedef union {
  byte Byte;
  struct {
    byte DB0         :1;                                       /* Data Bit 0 */
    byte DB1         :1;                                       /* Data Bit 1 */
    byte DB2         :1;                                       /* Data Bit 2 */
    byte DB3         :1;                                       /* Data Bit 3 */
    byte DB4         :1;                                       /* Data Bit 4 */
    byte DB5         :1;                                       /* Data Bit 5 */
    byte DB6         :1;                                       /* Data Bit 6 */
    byte DB7         :1;                                       /* Data Bit 7 */
  } Bits;
} CANTXDSR0STR;
extern volatile CANTXDSR0STR _CANTXDSR0 @(REG_BASE + 0x00000174UL);
#define CANTXDSR0                       _CANTXDSR0.Byte
#define CANTXDSR0_DB0                   _CANTXDSR0.Bits.DB0
#define CANTXDSR0_DB1                   _CANTXDSR0.Bits.DB1
#define CANTXDSR0_DB2                   _CANTXDSR0.Bits.DB2
#define CANTXDSR0_DB3                   _CANTXDSR0.Bits.DB3
#define CANTXDSR0_DB4                   _CANTXDSR0.Bits.DB4
#define CANTXDSR0_DB5                   _CANTXDSR0.Bits.DB5
#define CANTXDSR0_DB6                   _CANTXDSR0.Bits.DB6
#define CANTXDSR0_DB7                   _CANTXDSR0.Bits.DB7
/* CANTXDSR_ARR: Access 8 CANTXDSRx registers in an array */
#define CANTXDSR_ARR                    ((volatile byte *) &CANTXDSR0)

#define CANTXDSR0_DB0_MASK              1U
#define CANTXDSR0_DB1_MASK              2U
#define CANTXDSR0_DB2_MASK              4U
#define CANTXDSR0_DB3_MASK              8U
#define CANTXDSR0_DB4_MASK              16U
#define CANTXDSR0_DB5_MASK              32U
#define CANTXDSR0_DB6_MASK              64U
#define CANTXDSR0_DB7_MASK              128U


/*** CANTXDSR1 - MSCAN Transmit Data Segment Register 1; 0x00000175 ***/
typedef union {
  byte Byte;
  struct {
    byte DB0         :1;                                       /* Data Bit 0 */
    byte DB1         :1;                                       /* Data Bit 1 */
    byte DB2         :1;                                       /* Data Bit 2 */
    byte DB3         :1;                                       /* Data Bit 3 */
    byte DB4         :1;                                       /* Data Bit 4 */
    byte DB5         :1;                                       /* Data Bit 5 */
    byte DB6         :1;                                       /* Data Bit 6 */
    byte DB7         :1;                                       /* Data Bit 7 */
  } Bits;
} CANTXDSR1STR;
extern volatile CANTXDSR1STR _CANTXDSR1 @(REG_BASE + 0x00000175UL);
#define CANTXDSR1                       _CANTXDSR1.Byte
#define CANTXDSR1_DB0                   _CANTXDSR1.Bits.DB0
#define CANTXDSR1_DB1                   _CANTXDSR1.Bits.DB1
#define CANTXDSR1_DB2                   _CANTXDSR1.Bits.DB2
#define CANTXDSR1_DB3                   _CANTXDSR1.Bits.DB3
#define CANTXDSR1_DB4                   _CANTXDSR1.Bits.DB4
#define CANTXDSR1_DB5                   _CANTXDSR1.Bits.DB5
#define CANTXDSR1_DB6                   _CANTXDSR1.Bits.DB6
#define CANTXDSR1_DB7                   _CANTXDSR1.Bits.DB7

#define CANTXDSR1_DB0_MASK              1U
#define CANTXDSR1_DB1_MASK              2U
#define CANTXDSR1_DB2_MASK              4U
#define CANTXDSR1_DB3_MASK              8U
#define CANTXDSR1_DB4_MASK              16U
#define CANTXDSR1_DB5_MASK              32U
#define CANTXDSR1_DB6_MASK              64U
#define CANTXDSR1_DB7_MASK              128U


/*** CANTXDSR2 - MSCAN Transmit Data Segment Register 2; 0x00000176 ***/
typedef union {
  byte Byte;
  struct {
    byte DB0         :1;                                       /* Data Bit 0 */
    byte DB1         :1;                                       /* Data Bit 1 */
    byte DB2         :1;                                       /* Data Bit 2 */
    byte DB3         :1;                                       /* Data Bit 3 */
    byte DB4         :1;                                       /* Data Bit 4 */
    byte DB5         :1;                                       /* Data Bit 5 */
    byte DB6         :1;                                       /* Data Bit 6 */
    byte DB7         :1;                                       /* Data Bit 7 */
  } Bits;
} CANTXDSR2STR;
extern volatile CANTXDSR2STR _CANTXDSR2 @(REG_BASE + 0x00000176UL);
#define CANTXDSR2                       _CANTXDSR2.Byte
#define CANTXDSR2_DB0                   _CANTXDSR2.Bits.DB0
#define CANTXDSR2_DB1                   _CANTXDSR2.Bits.DB1
#define CANTXDSR2_DB2                   _CANTXDSR2.Bits.DB2
#define CANTXDSR2_DB3                   _CANTXDSR2.Bits.DB3
#define CANTXDSR2_DB4                   _CANTXDSR2.Bits.DB4
#define CANTXDSR2_DB5                   _CANTXDSR2.Bits.DB5
#define CANTXDSR2_DB6                   _CANTXDSR2.Bits.DB6
#define CANTXDSR2_DB7                   _CANTXDSR2.Bits.DB7

#define CANTXDSR2_DB0_MASK              1U
#define CANTXDSR2_DB1_MASK              2U
#define CANTXDSR2_DB2_MASK              4U
#define CANTXDSR2_DB3_MASK              8U
#define CANTXDSR2_DB4_MASK              16U
#define CANTXDSR2_DB5_MASK              32U
#define CANTXDSR2_DB6_MASK              64U
#define CANTXDSR2_DB7_MASK              128U


/*** CANTXDSR3 - MSCAN Transmit Data Segment Register 3; 0x00000177 ***/
typedef union {
  byte Byte;
  struct {
    byte DB0         :1;                                       /* Data Bit 0 */
    byte DB1         :1;                                       /* Data Bit 1 */
    byte DB2         :1;                                       /* Data Bit 2 */
    byte DB3         :1;                                       /* Data Bit 3 */
    byte DB4         :1;                                       /* Data Bit 4 */
    byte DB5         :1;                                       /* Data Bit 5 */
    byte DB6         :1;                                       /* Data Bit 6 */
    byte DB7         :1;                                       /* Data Bit 7 */
  } Bits;
} CANTXDSR3STR;
extern volatile CANTXDSR3STR _CANTXDSR3 @(REG_BASE + 0x00000177UL);
#define CANTXDSR3                       _CANTXDSR3.Byte
#define CANTXDSR3_DB0                   _CANTXDSR3.Bits.DB0
#define CANTXDSR3_DB1                   _CANTXDSR3.Bits.DB1
#define CANTXDSR3_DB2                   _CANTXDSR3.Bits.DB2
#define CANTXDSR3_DB3                   _CANTXDSR3.Bits.DB3
#define CANTXDSR3_DB4                   _CANTXDSR3.Bits.DB4
#define CANTXDSR3_DB5                   _CANTXDSR3.Bits.DB5
#define CANTXDSR3_DB6                   _CANTXDSR3.Bits.DB6
#define CANTXDSR3_DB7                   _CANTXDSR3.Bits.DB7

#define CANTXDSR3_DB0_MASK              1U
#define CANTXDSR3_DB1_MASK              2U
#define CANTXDSR3_DB2_MASK              4U
#define CANTXDSR3_DB3_MASK              8U
#define CANTXDSR3_DB4_MASK              16U
#define CANTXDSR3_DB5_MASK              32U
#define CANTXDSR3_DB6_MASK              64U
#define CANTXDSR3_DB7_MASK              128U


/*** CANTXDSR4 - MSCAN Transmit Data Segment Register 4; 0x00000178 ***/
typedef union {
  byte Byte;
  struct {
    byte DB0         :1;                                       /* Data Bit 0 */
    byte DB1         :1;                                       /* Data Bit 1 */
    byte DB2         :1;                                       /* Data Bit 2 */
    byte DB3         :1;                                       /* Data Bit 3 */
    byte DB4         :1;                                       /* Data Bit 4 */
    byte DB5         :1;                                       /* Data Bit 5 */
    byte DB6         :1;                                       /* Data Bit 6 */
    byte DB7         :1;                                       /* Data Bit 7 */
  } Bits;
} CANTXDSR4STR;
extern volatile CANTXDSR4STR _CANTXDSR4 @(REG_BASE + 0x00000178UL);
#define CANTXDSR4                       _CANTXDSR4.Byte
#define CANTXDSR4_DB0                   _CANTXDSR4.Bits.DB0
#define CANTXDSR4_DB1                   _CANTXDSR4.Bits.DB1
#define CANTXDSR4_DB2                   _CANTXDSR4.Bits.DB2
#define CANTXDSR4_DB3                   _CANTXDSR4.Bits.DB3
#define CANTXDSR4_DB4                   _CANTXDSR4.Bits.DB4
#define CANTXDSR4_DB5                   _CANTXDSR4.Bits.DB5
#define CANTXDSR4_DB6                   _CANTXDSR4.Bits.DB6
#define CANTXDSR4_DB7                   _CANTXDSR4.Bits.DB7

#define CANTXDSR4_DB0_MASK              1U
#define CANTXDSR4_DB1_MASK              2U
#define CANTXDSR4_DB2_MASK              4U
#define CANTXDSR4_DB3_MASK              8U
#define CANTXDSR4_DB4_MASK              16U
#define CANTXDSR4_DB5_MASK              32U
#define CANTXDSR4_DB6_MASK              64U
#define CANTXDSR4_DB7_MASK              128U


/*** CANTXDSR5 - MSCAN Transmit Data Segment Register 5; 0x00000179 ***/
typedef union {
  byte Byte;
  struct {
    byte DB0         :1;                                       /* Data Bit 0 */
    byte DB1         :1;                                       /* Data Bit 1 */
    byte DB2         :1;                                       /* Data Bit 2 */
    byte DB3         :1;                                       /* Data Bit 3 */
    byte DB4         :1;                                       /* Data Bit 4 */
    byte DB5         :1;                                       /* Data Bit 5 */
    byte DB6         :1;                                       /* Data Bit 6 */
    byte DB7         :1;                                       /* Data Bit 7 */
  } Bits;
} CANTXDSR5STR;
extern volatile CANTXDSR5STR _CANTXDSR5 @(REG_BASE + 0x00000179UL);
#define CANTXDSR5                       _CANTXDSR5.Byte
#define CANTXDSR5_DB0                   _CANTXDSR5.Bits.DB0
#define CANTXDSR5_DB1                   _CANTXDSR5.Bits.DB1
#define CANTXDSR5_DB2                   _CANTXDSR5.Bits.DB2
#define CANTXDSR5_DB3                   _CANTXDSR5.Bits.DB3
#define CANTXDSR5_DB4                   _CANTXDSR5.Bits.DB4
#define CANTXDSR5_DB5                   _CANTXDSR5.Bits.DB5
#define CANTXDSR5_DB6                   _CANTXDSR5.Bits.DB6
#define CANTXDSR5_DB7                   _CANTXDSR5.Bits.DB7

#define CANTXDSR5_DB0_MASK              1U
#define CANTXDSR5_DB1_MASK              2U
#define CANTXDSR5_DB2_MASK              4U
#define CANTXDSR5_DB3_MASK              8U
#define CANTXDSR5_DB4_MASK              16U
#define CANTXDSR5_DB5_MASK              32U
#define CANTXDSR5_DB6_MASK              64U
#define CANTXDSR5_DB7_MASK              128U


/*** CANTXDSR6 - MSCAN Transmit Data Segment Register 6; 0x0000017A ***/
typedef union {
  byte Byte;
  struct {
    byte DB0         :1;                                       /* Data Bit 0 */
    byte DB1         :1;                                       /* Data Bit 1 */
    byte DB2         :1;                                       /* Data Bit 2 */
    byte DB3         :1;                                       /* Data Bit 3 */
    byte DB4         :1;                                       /* Data Bit 4 */
    byte DB5         :1;                                       /* Data Bit 5 */
    byte DB6         :1;                                       /* Data Bit 6 */
    byte DB7         :1;                                       /* Data Bit 7 */
  } Bits;
} CANTXDSR6STR;
extern volatile CANTXDSR6STR _CANTXDSR6 @(REG_BASE + 0x0000017AUL);
#define CANTXDSR6                       _CANTXDSR6.Byte
#define CANTXDSR6_DB0                   _CANTXDSR6.Bits.DB0
#define CANTXDSR6_DB1                   _CANTXDSR6.Bits.DB1
#define CANTXDSR6_DB2                   _CANTXDSR6.Bits.DB2
#define CANTXDSR6_DB3                   _CANTXDSR6.Bits.DB3
#define CANTXDSR6_DB4                   _CANTXDSR6.Bits.DB4
#define CANTXDSR6_DB5                   _CANTXDSR6.Bits.DB5
#define CANTXDSR6_DB6                   _CANTXDSR6.Bits.DB6
#define CANTXDSR6_DB7                   _CANTXDSR6.Bits.DB7

#define CANTXDSR6_DB0_MASK              1U
#define CANTXDSR6_DB1_MASK              2U
#define CANTXDSR6_DB2_MASK              4U
#define CANTXDSR6_DB3_MASK              8U
#define CANTXDSR6_DB4_MASK              16U
#define CANTXDSR6_DB5_MASK              32U
#define CANTXDSR6_DB6_MASK              64U
#define CANTXDSR6_DB7_MASK              128U


/*** CANTXDSR7 - MSCAN Transmit Data Segment Register 7; 0x0000017B ***/
typedef union {
  byte Byte;
  struct {
    byte DB0         :1;                                       /* Data Bit 0 */
    byte DB1         :1;                                       /* Data Bit 1 */
    byte DB2         :1;                                       /* Data Bit 2 */
    byte DB3         :1;                                       /* Data Bit 3 */
    byte DB4         :1;                                       /* Data Bit 4 */
    byte DB5         :1;                                       /* Data Bit 5 */
    byte DB6         :1;                                       /* Data Bit 6 */
    byte DB7         :1;                                       /* Data Bit 7 */
  } Bits;
} CANTXDSR7STR;
extern volatile CANTXDSR7STR _CANTXDSR7 @(REG_BASE + 0x0000017BUL);
#define CANTXDSR7                       _CANTXDSR7.Byte
#define CANTXDSR7_DB0                   _CANTXDSR7.Bits.DB0
#define CANTXDSR7_DB1                   _CANTXDSR7.Bits.DB1
#define CANTXDSR7_DB2                   _CANTXDSR7.Bits.DB2
#define CANTXDSR7_DB3                   _CANTXDSR7.Bits.DB3
#define CANTXDSR7_DB4                   _CANTXDSR7.Bits.DB4
#define CANTXDSR7_DB5                   _CANTXDSR7.Bits.DB5
#define CANTXDSR7_DB6                   _CANTXDSR7.Bits.DB6
#define CANTXDSR7_DB7                   _CANTXDSR7.Bits.DB7

#define CANTXDSR7_DB0_MASK              1U
#define CANTXDSR7_DB1_MASK              2U
#define CANTXDSR7_DB2_MASK              4U
#define CANTXDSR7_DB3_MASK              8U
#define CANTXDSR7_DB4_MASK              16U
#define CANTXDSR7_DB5_MASK              32U
#define CANTXDSR7_DB6_MASK              64U
#define CANTXDSR7_DB7_MASK              128U


/*** CANTXDLR - MSCAN Transmit Data Length Register; 0x0000017C ***/
typedef union {
  byte Byte;
  struct {
    byte DLC0        :1;                                       /* Data Length Code Bit 0 */
    byte DLC1        :1;                                       /* Data Length Code Bit 1 */
    byte DLC2        :1;                                       /* Data Length Code Bit 2 */
    byte DLC3        :1;                                       /* Data Length Code Bit 3 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpDLC  :4;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} CANTXDLRSTR;
extern volatile CANTXDLRSTR _CANTXDLR @(REG_BASE + 0x0000017CUL);
#define CANTXDLR                        _CANTXDLR.Byte
#define CANTXDLR_DLC0                   _CANTXDLR.Bits.DLC0
#define CANTXDLR_DLC1                   _CANTXDLR.Bits.DLC1
#define CANTXDLR_DLC2                   _CANTXDLR.Bits.DLC2
#define CANTXDLR_DLC3                   _CANTXDLR.Bits.DLC3
#define CANTXDLR_DLC                    _CANTXDLR.MergedBits.grpDLC

#define CANTXDLR_DLC0_MASK              1U
#define CANTXDLR_DLC1_MASK              2U
#define CANTXDLR_DLC2_MASK              4U
#define CANTXDLR_DLC3_MASK              8U
#define CANTXDLR_DLC_MASK               15U
#define CANTXDLR_DLC_BITNUM             0U


/*** CANTXTBPR - MSCAN Transmit Buffer Priority; 0x0000017D ***/
typedef union {
  byte Byte;
  struct {
    byte PRIO0       :1;                                       /* Transmit Buffer Priority Bit 0 */
    byte PRIO1       :1;                                       /* Transmit Buffer Priority Bit 1 */
    byte PRIO2       :1;                                       /* Transmit Buffer Priority Bit 2 */
    byte PRIO3       :1;                                       /* Transmit Buffer Priority Bit 3 */
    byte PRIO4       :1;                                       /* Transmit Buffer Priority Bit 4 */
    byte PRIO5       :1;                                       /* Transmit Buffer Priority Bit 5 */
    byte PRIO6       :1;                                       /* Transmit Buffer Priority Bit 6 */
    byte PRIO7       :1;                                       /* Transmit Buffer Priority Bit 7 */
  } Bits;
} CANTXTBPRSTR;
extern volatile CANTXTBPRSTR _CANTXTBPR @(REG_BASE + 0x0000017DUL);
#define CANTXTBPR                       _CANTXTBPR.Byte
#define CANTXTBPR_PRIO0                 _CANTXTBPR.Bits.PRIO0
#define CANTXTBPR_PRIO1                 _CANTXTBPR.Bits.PRIO1
#define CANTXTBPR_PRIO2                 _CANTXTBPR.Bits.PRIO2
#define CANTXTBPR_PRIO3                 _CANTXTBPR.Bits.PRIO3
#define CANTXTBPR_PRIO4                 _CANTXTBPR.Bits.PRIO4
#define CANTXTBPR_PRIO5                 _CANTXTBPR.Bits.PRIO5
#define CANTXTBPR_PRIO6                 _CANTXTBPR.Bits.PRIO6
#define CANTXTBPR_PRIO7                 _CANTXTBPR.Bits.PRIO7

#define CANTXTBPR_PRIO0_MASK            1U
#define CANTXTBPR_PRIO1_MASK            2U
#define CANTXTBPR_PRIO2_MASK            4U
#define CANTXTBPR_PRIO3_MASK            8U
#define CANTXTBPR_PRIO4_MASK            16U
#define CANTXTBPR_PRIO5_MASK            32U
#define CANTXTBPR_PRIO6_MASK            64U
#define CANTXTBPR_PRIO7_MASK            128U


/*** CANTXTSR - MSCAN Transmit Time Stamp Register; 0x0000017E ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** CANTXTSRH - MSCAN Transmit Time Stamp Register High; 0x0000017E ***/
    union {
      byte Byte;
      struct {
        byte TSR8        :1;                                       /* Time Stamp Bit 8 */
        byte TSR9        :1;                                       /* Time Stamp Bit 9 */
        byte TSR10       :1;                                       /* Time Stamp Bit 10 */
        byte TSR11       :1;                                       /* Time Stamp Bit 11 */
        byte TSR12       :1;                                       /* Time Stamp Bit 12 */
        byte TSR13       :1;                                       /* Time Stamp Bit 13 */
        byte TSR14       :1;                                       /* Time Stamp Bit 14 */
        byte TSR15       :1;                                       /* Time Stamp Bit 15 */
      } Bits;
    } CANTXTSRHSTR;
    #define CANTXTSRH                   _CANTXTSR.Overlap_STR.CANTXTSRHSTR.Byte
    #define CANTXTSRH_TSR8              _CANTXTSR.Overlap_STR.CANTXTSRHSTR.Bits.TSR8
    #define CANTXTSRH_TSR9              _CANTXTSR.Overlap_STR.CANTXTSRHSTR.Bits.TSR9
    #define CANTXTSRH_TSR10             _CANTXTSR.Overlap_STR.CANTXTSRHSTR.Bits.TSR10
    #define CANTXTSRH_TSR11             _CANTXTSR.Overlap_STR.CANTXTSRHSTR.Bits.TSR11
    #define CANTXTSRH_TSR12             _CANTXTSR.Overlap_STR.CANTXTSRHSTR.Bits.TSR12
    #define CANTXTSRH_TSR13             _CANTXTSR.Overlap_STR.CANTXTSRHSTR.Bits.TSR13
    #define CANTXTSRH_TSR14             _CANTXTSR.Overlap_STR.CANTXTSRHSTR.Bits.TSR14
    #define CANTXTSRH_TSR15             _CANTXTSR.Overlap_STR.CANTXTSRHSTR.Bits.TSR15
    
    #define CANTXTSRH_TSR8_MASK         1U
    #define CANTXTSRH_TSR9_MASK         2U
    #define CANTXTSRH_TSR10_MASK        4U
    #define CANTXTSRH_TSR11_MASK        8U
    #define CANTXTSRH_TSR12_MASK        16U
    #define CANTXTSRH_TSR13_MASK        32U
    #define CANTXTSRH_TSR14_MASK        64U
    #define CANTXTSRH_TSR15_MASK        128U
    

    /*** CANTXTSRL - MSCAN Transmit Time Stamp Register Low; 0x0000017F ***/
    union {
      byte Byte;
      struct {
        byte TSR0        :1;                                       /* Time Stamp Bit 0 */
        byte TSR1        :1;                                       /* Time Stamp Bit 1 */
        byte TSR2        :1;                                       /* Time Stamp Bit 2 */
        byte TSR3        :1;                                       /* Time Stamp Bit 3 */
        byte TSR4        :1;                                       /* Time Stamp Bit 4 */
        byte TSR5        :1;                                       /* Time Stamp Bit 5 */
        byte TSR6        :1;                                       /* Time Stamp Bit 6 */
        byte TSR7        :1;                                       /* Time Stamp Bit 7 */
      } Bits;
    } CANTXTSRLSTR;
    #define CANTXTSRL                   _CANTXTSR.Overlap_STR.CANTXTSRLSTR.Byte
    #define CANTXTSRL_TSR0              _CANTXTSR.Overlap_STR.CANTXTSRLSTR.Bits.TSR0
    #define CANTXTSRL_TSR1              _CANTXTSR.Overlap_STR.CANTXTSRLSTR.Bits.TSR1
    #define CANTXTSRL_TSR2              _CANTXTSR.Overlap_STR.CANTXTSRLSTR.Bits.TSR2
    #define CANTXTSRL_TSR3              _CANTXTSR.Overlap_STR.CANTXTSRLSTR.Bits.TSR3
    #define CANTXTSRL_TSR4              _CANTXTSR.Overlap_STR.CANTXTSRLSTR.Bits.TSR4
    #define CANTXTSRL_TSR5              _CANTXTSR.Overlap_STR.CANTXTSRLSTR.Bits.TSR5
    #define CANTXTSRL_TSR6              _CANTXTSR.Overlap_STR.CANTXTSRLSTR.Bits.TSR6
    #define CANTXTSRL_TSR7              _CANTXTSR.Overlap_STR.CANTXTSRLSTR.Bits.TSR7
    
    #define CANTXTSRL_TSR0_MASK         1U
    #define CANTXTSRL_TSR1_MASK         2U
    #define CANTXTSRL_TSR2_MASK         4U
    #define CANTXTSRL_TSR3_MASK         8U
    #define CANTXTSRL_TSR4_MASK         16U
    #define CANTXTSRL_TSR5_MASK         32U
    #define CANTXTSRL_TSR6_MASK         64U
    #define CANTXTSRL_TSR7_MASK         128U
    
  } Overlap_STR;

  struct {
    word TSR0        :1;                                       /* Time Stamp Bit 0 */
    word TSR1        :1;                                       /* Time Stamp Bit 1 */
    word TSR2        :1;                                       /* Time Stamp Bit 2 */
    word TSR3        :1;                                       /* Time Stamp Bit 3 */
    word TSR4        :1;                                       /* Time Stamp Bit 4 */
    word TSR5        :1;                                       /* Time Stamp Bit 5 */
    word TSR6        :1;                                       /* Time Stamp Bit 6 */
    word TSR7        :1;                                       /* Time Stamp Bit 7 */
    word TSR8        :1;                                       /* Time Stamp Bit 8 */
    word TSR9        :1;                                       /* Time Stamp Bit 9 */
    word TSR10       :1;                                       /* Time Stamp Bit 10 */
    word TSR11       :1;                                       /* Time Stamp Bit 11 */
    word TSR12       :1;                                       /* Time Stamp Bit 12 */
    word TSR13       :1;                                       /* Time Stamp Bit 13 */
    word TSR14       :1;                                       /* Time Stamp Bit 14 */
    word TSR15       :1;                                       /* Time Stamp Bit 15 */
  } Bits;
} CANTXTSRSTR;
extern volatile CANTXTSRSTR _CANTXTSR @(REG_BASE + 0x0000017EUL);
#define CANTXTSR                        _CANTXTSR.Word
#define CANTXTSR_TSR0                   _CANTXTSR.Bits.TSR0
#define CANTXTSR_TSR1                   _CANTXTSR.Bits.TSR1
#define CANTXTSR_TSR2                   _CANTXTSR.Bits.TSR2
#define CANTXTSR_TSR3                   _CANTXTSR.Bits.TSR3
#define CANTXTSR_TSR4                   _CANTXTSR.Bits.TSR4
#define CANTXTSR_TSR5                   _CANTXTSR.Bits.TSR5
#define CANTXTSR_TSR6                   _CANTXTSR.Bits.TSR6
#define CANTXTSR_TSR7                   _CANTXTSR.Bits.TSR7
#define CANTXTSR_TSR8                   _CANTXTSR.Bits.TSR8
#define CANTXTSR_TSR9                   _CANTXTSR.Bits.TSR9
#define CANTXTSR_TSR10                  _CANTXTSR.Bits.TSR10
#define CANTXTSR_TSR11                  _CANTXTSR.Bits.TSR11
#define CANTXTSR_TSR12                  _CANTXTSR.Bits.TSR12
#define CANTXTSR_TSR13                  _CANTXTSR.Bits.TSR13
#define CANTXTSR_TSR14                  _CANTXTSR.Bits.TSR14
#define CANTXTSR_TSR15                  _CANTXTSR.Bits.TSR15

#define CANTXTSR_TSR0_MASK              1U
#define CANTXTSR_TSR1_MASK              2U
#define CANTXTSR_TSR2_MASK              4U
#define CANTXTSR_TSR3_MASK              8U
#define CANTXTSR_TSR4_MASK              16U
#define CANTXTSR_TSR5_MASK              32U
#define CANTXTSR_TSR6_MASK              64U
#define CANTXTSR_TSR7_MASK              128U
#define CANTXTSR_TSR8_MASK              256U
#define CANTXTSR_TSR9_MASK              512U
#define CANTXTSR_TSR10_MASK             1024U
#define CANTXTSR_TSR11_MASK             2048U
#define CANTXTSR_TSR12_MASK             4096U
#define CANTXTSR_TSR13_MASK             8192U
#define CANTXTSR_TSR14_MASK             16384U
#define CANTXTSR_TSR15_MASK             32768U


/*** MCCTL0 - Motor Controller Control Register 0; 0x000001C0 ***/
typedef union {
  byte Byte;
  struct {
    byte MCTOIF      :1;                                       /* Motor Controller Timer Counter Overflow Interrupt Flag */
    byte             :1; 
    byte DITH        :1;                                       /* Motor Control/Driver Dither Feature Enable */
    byte FAST        :1;                                       /* Motor Controller PWM Resolution Mode */
    byte MCSWAI      :1;                                       /* Motor Controller Module Stop in Wait Mode */
    byte MCPRE0      :1;                                       /* Motor Controller Prescaler Select, bit 0 */
    byte MCPRE1      :1;                                       /* Motor Controller Prescaler Select, bit 1 */
    byte             :1; 
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte grpMCPRE :2;
    byte         :1;
  } MergedBits;
} MCCTL0STR;
extern volatile MCCTL0STR _MCCTL0 @(REG_BASE + 0x000001C0UL);
#define MCCTL0                          _MCCTL0.Byte
#define MCCTL0_MCTOIF                   _MCCTL0.Bits.MCTOIF
#define MCCTL0_DITH                     _MCCTL0.Bits.DITH
#define MCCTL0_FAST                     _MCCTL0.Bits.FAST
#define MCCTL0_MCSWAI                   _MCCTL0.Bits.MCSWAI
#define MCCTL0_MCPRE0                   _MCCTL0.Bits.MCPRE0
#define MCCTL0_MCPRE1                   _MCCTL0.Bits.MCPRE1
/* MCCTL_ARR: Access 2 MCCTLx registers in an array */
#define MCCTL_ARR                       ((volatile byte *) &MCCTL0)
#define MCCTL0_MCPRE                    _MCCTL0.MergedBits.grpMCPRE

#define MCCTL0_MCTOIF_MASK              1U
#define MCCTL0_DITH_MASK                4U
#define MCCTL0_FAST_MASK                8U
#define MCCTL0_MCSWAI_MASK              16U
#define MCCTL0_MCPRE0_MASK              32U
#define MCCTL0_MCPRE1_MASK              64U
#define MCCTL0_MCPRE_MASK               96U
#define MCCTL0_MCPRE_BITNUM             5U


/*** MCCTL1 - Motor Controller Control Register 1; 0x000001C1 ***/
typedef union {
  byte Byte;
  struct {
    byte MCTOIE      :1;                                       /* Motor Controller Timer Counter Overflow Interrupt Enable */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte RECIRC      :1;                                       /* Recirculation in (Dual) Full H-Bridge Mode */
  } Bits;
} MCCTL1STR;
extern volatile MCCTL1STR _MCCTL1 @(REG_BASE + 0x000001C1UL);
#define MCCTL1                          _MCCTL1.Byte
#define MCCTL1_MCTOIE                   _MCCTL1.Bits.MCTOIE
#define MCCTL1_RECIRC                   _MCCTL1.Bits.RECIRC

#define MCCTL1_MCTOIE_MASK              1U
#define MCCTL1_RECIRC_MASK              128U


/*** MCPER - Motor Controller Period Register; 0x000001C2 ***/
typedef union {
  word Word;
  struct {
    word P0          :1;                                       /* Motor Controller Period Bit 1 */
    word P1          :1;                                       /* Motor Controller Period, bit 1 */
    word P2          :1;                                       /* Motor Controller Period, bit 2 */
    word P3          :1;                                       /* Motor Controller Period, bit 3 */
    word P4          :1;                                       /* Motor Controller Period, bit 4 */
    word P5          :1;                                       /* Motor Controller Period, bit 5 */
    word P6          :1;                                       /* Motor Controller Period, bit 6 */
    word P7          :1;                                       /* Motor Controller Period, bit 7 */
    word P8          :1;                                       /* Motor Controller Period, bit 8 */
    word P9          :1;                                       /* Motor Controller Period, bit 9 */
    word P10         :1;                                       /* Motor Controller Period, bit 10 */
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
  } Bits;
  struct {
    word grpP    :11;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
  } MergedBits;
} MCPERSTR;
extern volatile MCPERSTR _MCPER @(REG_BASE + 0x000001C2UL);
#define MCPER                           _MCPER.Word
#define MCPER_P0                        _MCPER.Bits.P0
#define MCPER_P1                        _MCPER.Bits.P1
#define MCPER_P2                        _MCPER.Bits.P2
#define MCPER_P3                        _MCPER.Bits.P3
#define MCPER_P4                        _MCPER.Bits.P4
#define MCPER_P5                        _MCPER.Bits.P5
#define MCPER_P6                        _MCPER.Bits.P6
#define MCPER_P7                        _MCPER.Bits.P7
#define MCPER_P8                        _MCPER.Bits.P8
#define MCPER_P9                        _MCPER.Bits.P9
#define MCPER_P10                       _MCPER.Bits.P10
#define MCPER_P                         _MCPER.MergedBits.grpP

#define MCPER_P0_MASK                   1U
#define MCPER_P1_MASK                   2U
#define MCPER_P2_MASK                   4U
#define MCPER_P3_MASK                   8U
#define MCPER_P4_MASK                   16U
#define MCPER_P5_MASK                   32U
#define MCPER_P6_MASK                   64U
#define MCPER_P7_MASK                   128U
#define MCPER_P8_MASK                   256U
#define MCPER_P9_MASK                   512U
#define MCPER_P10_MASK                  1024U
#define MCPER_P_MASK                    2047U
#define MCPER_P_BITNUM                  0U


/*** MCCC0 - Motor Controller Control Register 0; 0x000001D0 ***/
typedef union {
  byte Byte;
  struct {
    byte CD0         :1;                                       /* PWM Channel Delay */
    byte CD1         :1;                                       /* PWM Channel Delay */
    byte             :1; 
    byte             :1; 
    byte MCAM0       :1;                                       /* PWM Channel Alignment Mode */
    byte MCAM1       :1;                                       /* PWM Channel Alignment Mode */
    byte MCOM0       :1;                                       /* Output Mode */
    byte MCOM1       :1;                                       /* Output Mode */
  } Bits;
  struct {
    byte grpCD   :2;
    byte         :1;
    byte         :1;
    byte grpMCAM :2;
    byte grpMCOM :2;
  } MergedBits;
} MCCC0STR;
extern volatile MCCC0STR _MCCC0 @(REG_BASE + 0x000001D0UL);
#define MCCC0                           _MCCC0.Byte
#define MCCC0_CD0                       _MCCC0.Bits.CD0
#define MCCC0_CD1                       _MCCC0.Bits.CD1
#define MCCC0_MCAM0                     _MCCC0.Bits.MCAM0
#define MCCC0_MCAM1                     _MCCC0.Bits.MCAM1
#define MCCC0_MCOM0                     _MCCC0.Bits.MCOM0
#define MCCC0_MCOM1                     _MCCC0.Bits.MCOM1
/* MCCC_ARR: Access 8 MCCCx registers in an array */
#define MCCC_ARR                        ((volatile byte *) &MCCC0)
#define MCCC0_CD                        _MCCC0.MergedBits.grpCD
#define MCCC0_MCAM                      _MCCC0.MergedBits.grpMCAM
#define MCCC0_MCOM                      _MCCC0.MergedBits.grpMCOM

#define MCCC0_CD0_MASK                  1U
#define MCCC0_CD1_MASK                  2U
#define MCCC0_MCAM0_MASK                16U
#define MCCC0_MCAM1_MASK                32U
#define MCCC0_MCOM0_MASK                64U
#define MCCC0_MCOM1_MASK                128U
#define MCCC0_CD_MASK                   3U
#define MCCC0_CD_BITNUM                 0U
#define MCCC0_MCAM_MASK                 48U
#define MCCC0_MCAM_BITNUM               4U
#define MCCC0_MCOM_MASK                 192U
#define MCCC0_MCOM_BITNUM               6U


/*** MCCC1 - Motor Controller Control Register 1; 0x000001D1 ***/
typedef union {
  byte Byte;
  struct {
    byte CD0         :1;                                       /* PWM Channel Delay */
    byte CD1         :1;                                       /* PWM Channel Delay */
    byte             :1; 
    byte             :1; 
    byte MCAM0       :1;                                       /* PWM Channel Alignment Mode */
    byte MCAM1       :1;                                       /* PWM Channel Alignment Mode */
    byte MCOM0       :1;                                       /* Output Mode */
    byte MCOM1       :1;                                       /* Output Mode */
  } Bits;
  struct {
    byte grpCD   :2;
    byte         :1;
    byte         :1;
    byte grpMCAM :2;
    byte grpMCOM :2;
  } MergedBits;
} MCCC1STR;
extern volatile MCCC1STR _MCCC1 @(REG_BASE + 0x000001D1UL);
#define MCCC1                           _MCCC1.Byte
#define MCCC1_CD0                       _MCCC1.Bits.CD0
#define MCCC1_CD1                       _MCCC1.Bits.CD1
#define MCCC1_MCAM0                     _MCCC1.Bits.MCAM0
#define MCCC1_MCAM1                     _MCCC1.Bits.MCAM1
#define MCCC1_MCOM0                     _MCCC1.Bits.MCOM0
#define MCCC1_MCOM1                     _MCCC1.Bits.MCOM1
#define MCCC1_CD                        _MCCC1.MergedBits.grpCD
#define MCCC1_MCAM                      _MCCC1.MergedBits.grpMCAM
#define MCCC1_MCOM                      _MCCC1.MergedBits.grpMCOM

#define MCCC1_CD0_MASK                  1U
#define MCCC1_CD1_MASK                  2U
#define MCCC1_MCAM0_MASK                16U
#define MCCC1_MCAM1_MASK                32U
#define MCCC1_MCOM0_MASK                64U
#define MCCC1_MCOM1_MASK                128U
#define MCCC1_CD_MASK                   3U
#define MCCC1_CD_BITNUM                 0U
#define MCCC1_MCAM_MASK                 48U
#define MCCC1_MCAM_BITNUM               4U
#define MCCC1_MCOM_MASK                 192U
#define MCCC1_MCOM_BITNUM               6U


/*** MCCC2 - Motor Controller Control Register 2; 0x000001D2 ***/
typedef union {
  byte Byte;
  struct {
    byte CD0         :1;                                       /* PWM Channel Delay */
    byte CD1         :1;                                       /* PWM Channel Delay */
    byte             :1; 
    byte             :1; 
    byte MCAM0       :1;                                       /* PWM Channel Alignment Mode */
    byte MCAM1       :1;                                       /* PWM Channel Alignment Mode */
    byte MCOM0       :1;                                       /* Output Mode */
    byte MCOM1       :1;                                       /* Output Mode */
  } Bits;
  struct {
    byte grpCD   :2;
    byte         :1;
    byte         :1;
    byte grpMCAM :2;
    byte grpMCOM :2;
  } MergedBits;
} MCCC2STR;
extern volatile MCCC2STR _MCCC2 @(REG_BASE + 0x000001D2UL);
#define MCCC2                           _MCCC2.Byte
#define MCCC2_CD0                       _MCCC2.Bits.CD0
#define MCCC2_CD1                       _MCCC2.Bits.CD1
#define MCCC2_MCAM0                     _MCCC2.Bits.MCAM0
#define MCCC2_MCAM1                     _MCCC2.Bits.MCAM1
#define MCCC2_MCOM0                     _MCCC2.Bits.MCOM0
#define MCCC2_MCOM1                     _MCCC2.Bits.MCOM1
#define MCCC2_CD                        _MCCC2.MergedBits.grpCD
#define MCCC2_MCAM                      _MCCC2.MergedBits.grpMCAM
#define MCCC2_MCOM                      _MCCC2.MergedBits.grpMCOM

#define MCCC2_CD0_MASK                  1U
#define MCCC2_CD1_MASK                  2U
#define MCCC2_MCAM0_MASK                16U
#define MCCC2_MCAM1_MASK                32U
#define MCCC2_MCOM0_MASK                64U
#define MCCC2_MCOM1_MASK                128U
#define MCCC2_CD_MASK                   3U
#define MCCC2_CD_BITNUM                 0U
#define MCCC2_MCAM_MASK                 48U
#define MCCC2_MCAM_BITNUM               4U
#define MCCC2_MCOM_MASK                 192U
#define MCCC2_MCOM_BITNUM               6U


/*** MCCC3 - Motor Controller Control Register 3; 0x000001D3 ***/
typedef union {
  byte Byte;
  struct {
    byte CD0         :1;                                       /* PWM Channel Delay */
    byte CD1         :1;                                       /* PWM Channel Delay */
    byte             :1; 
    byte             :1; 
    byte MCAM0       :1;                                       /* PWM Channel Alignment Mode */
    byte MCAM1       :1;                                       /* PWM Channel Alignment Mode */
    byte MCOM0       :1;                                       /* Output Mode */
    byte MCOM1       :1;                                       /* Output Mode */
  } Bits;
  struct {
    byte grpCD   :2;
    byte         :1;
    byte         :1;
    byte grpMCAM :2;
    byte grpMCOM :2;
  } MergedBits;
} MCCC3STR;
extern volatile MCCC3STR _MCCC3 @(REG_BASE + 0x000001D3UL);
#define MCCC3                           _MCCC3.Byte
#define MCCC3_CD0                       _MCCC3.Bits.CD0
#define MCCC3_CD1                       _MCCC3.Bits.CD1
#define MCCC3_MCAM0                     _MCCC3.Bits.MCAM0
#define MCCC3_MCAM1                     _MCCC3.Bits.MCAM1
#define MCCC3_MCOM0                     _MCCC3.Bits.MCOM0
#define MCCC3_MCOM1                     _MCCC3.Bits.MCOM1
#define MCCC3_CD                        _MCCC3.MergedBits.grpCD
#define MCCC3_MCAM                      _MCCC3.MergedBits.grpMCAM
#define MCCC3_MCOM                      _MCCC3.MergedBits.grpMCOM

#define MCCC3_CD0_MASK                  1U
#define MCCC3_CD1_MASK                  2U
#define MCCC3_MCAM0_MASK                16U
#define MCCC3_MCAM1_MASK                32U
#define MCCC3_MCOM0_MASK                64U
#define MCCC3_MCOM1_MASK                128U
#define MCCC3_CD_MASK                   3U
#define MCCC3_CD_BITNUM                 0U
#define MCCC3_MCAM_MASK                 48U
#define MCCC3_MCAM_BITNUM               4U
#define MCCC3_MCOM_MASK                 192U
#define MCCC3_MCOM_BITNUM               6U


/*** MCCC4 - Motor Controller Control Register 4; 0x000001D4 ***/
typedef union {
  byte Byte;
  struct {
    byte CD0         :1;                                       /* PWM Channel Delay */
    byte CD1         :1;                                       /* PWM Channel Delay */
    byte             :1; 
    byte             :1; 
    byte MCAM0       :1;                                       /* PWM Channel Alignment Mode */
    byte MCAM1       :1;                                       /* PWM Channel Alignment Mode */
    byte MCOM0       :1;                                       /* Output Mode */
    byte MCOM1       :1;                                       /* Output Mode */
  } Bits;
  struct {
    byte grpCD   :2;
    byte         :1;
    byte         :1;
    byte grpMCAM :2;
    byte grpMCOM :2;
  } MergedBits;
} MCCC4STR;
extern volatile MCCC4STR _MCCC4 @(REG_BASE + 0x000001D4UL);
#define MCCC4                           _MCCC4.Byte
#define MCCC4_CD0                       _MCCC4.Bits.CD0
#define MCCC4_CD1                       _MCCC4.Bits.CD1
#define MCCC4_MCAM0                     _MCCC4.Bits.MCAM0
#define MCCC4_MCAM1                     _MCCC4.Bits.MCAM1
#define MCCC4_MCOM0                     _MCCC4.Bits.MCOM0
#define MCCC4_MCOM1                     _MCCC4.Bits.MCOM1
#define MCCC4_CD                        _MCCC4.MergedBits.grpCD
#define MCCC4_MCAM                      _MCCC4.MergedBits.grpMCAM
#define MCCC4_MCOM                      _MCCC4.MergedBits.grpMCOM

#define MCCC4_CD0_MASK                  1U
#define MCCC4_CD1_MASK                  2U
#define MCCC4_MCAM0_MASK                16U
#define MCCC4_MCAM1_MASK                32U
#define MCCC4_MCOM0_MASK                64U
#define MCCC4_MCOM1_MASK                128U
#define MCCC4_CD_MASK                   3U
#define MCCC4_CD_BITNUM                 0U
#define MCCC4_MCAM_MASK                 48U
#define MCCC4_MCAM_BITNUM               4U
#define MCCC4_MCOM_MASK                 192U
#define MCCC4_MCOM_BITNUM               6U


/*** MCCC5 - Motor Controller Control Register 5; 0x000001D5 ***/
typedef union {
  byte Byte;
  struct {
    byte CD0         :1;                                       /* PWM Channel Delay */
    byte CD1         :1;                                       /* PWM Channel Delay */
    byte             :1; 
    byte             :1; 
    byte MCAM0       :1;                                       /* PWM Channel Alignment Mode */
    byte MCAM1       :1;                                       /* PWM Channel Alignment Mode */
    byte MCOM0       :1;                                       /* Output Mode */
    byte MCOM1       :1;                                       /* Output Mode */
  } Bits;
  struct {
    byte grpCD   :2;
    byte         :1;
    byte         :1;
    byte grpMCAM :2;
    byte grpMCOM :2;
  } MergedBits;
} MCCC5STR;
extern volatile MCCC5STR _MCCC5 @(REG_BASE + 0x000001D5UL);
#define MCCC5                           _MCCC5.Byte
#define MCCC5_CD0                       _MCCC5.Bits.CD0
#define MCCC5_CD1                       _MCCC5.Bits.CD1
#define MCCC5_MCAM0                     _MCCC5.Bits.MCAM0
#define MCCC5_MCAM1                     _MCCC5.Bits.MCAM1
#define MCCC5_MCOM0                     _MCCC5.Bits.MCOM0
#define MCCC5_MCOM1                     _MCCC5.Bits.MCOM1
#define MCCC5_CD                        _MCCC5.MergedBits.grpCD
#define MCCC5_MCAM                      _MCCC5.MergedBits.grpMCAM
#define MCCC5_MCOM                      _MCCC5.MergedBits.grpMCOM

#define MCCC5_CD0_MASK                  1U
#define MCCC5_CD1_MASK                  2U
#define MCCC5_MCAM0_MASK                16U
#define MCCC5_MCAM1_MASK                32U
#define MCCC5_MCOM0_MASK                64U
#define MCCC5_MCOM1_MASK                128U
#define MCCC5_CD_MASK                   3U
#define MCCC5_CD_BITNUM                 0U
#define MCCC5_MCAM_MASK                 48U
#define MCCC5_MCAM_BITNUM               4U
#define MCCC5_MCOM_MASK                 192U
#define MCCC5_MCOM_BITNUM               6U


/*** MCCC6 - Motor Controller Control Register 6; 0x000001D6 ***/
typedef union {
  byte Byte;
  struct {
    byte CD0         :1;                                       /* PWM Channel Delay */
    byte CD1         :1;                                       /* PWM Channel Delay */
    byte             :1; 
    byte             :1; 
    byte MCAM0       :1;                                       /* PWM Channel Alignment Mode */
    byte MCAM1       :1;                                       /* PWM Channel Alignment Mode */
    byte MCOM0       :1;                                       /* Output Mode */
    byte MCOM1       :1;                                       /* Output Mode */
  } Bits;
  struct {
    byte grpCD   :2;
    byte         :1;
    byte         :1;
    byte grpMCAM :2;
    byte grpMCOM :2;
  } MergedBits;
} MCCC6STR;
extern volatile MCCC6STR _MCCC6 @(REG_BASE + 0x000001D6UL);
#define MCCC6                           _MCCC6.Byte
#define MCCC6_CD0                       _MCCC6.Bits.CD0
#define MCCC6_CD1                       _MCCC6.Bits.CD1
#define MCCC6_MCAM0                     _MCCC6.Bits.MCAM0
#define MCCC6_MCAM1                     _MCCC6.Bits.MCAM1
#define MCCC6_MCOM0                     _MCCC6.Bits.MCOM0
#define MCCC6_MCOM1                     _MCCC6.Bits.MCOM1
#define MCCC6_CD                        _MCCC6.MergedBits.grpCD
#define MCCC6_MCAM                      _MCCC6.MergedBits.grpMCAM
#define MCCC6_MCOM                      _MCCC6.MergedBits.grpMCOM

#define MCCC6_CD0_MASK                  1U
#define MCCC6_CD1_MASK                  2U
#define MCCC6_MCAM0_MASK                16U
#define MCCC6_MCAM1_MASK                32U
#define MCCC6_MCOM0_MASK                64U
#define MCCC6_MCOM1_MASK                128U
#define MCCC6_CD_MASK                   3U
#define MCCC6_CD_BITNUM                 0U
#define MCCC6_MCAM_MASK                 48U
#define MCCC6_MCAM_BITNUM               4U
#define MCCC6_MCOM_MASK                 192U
#define MCCC6_MCOM_BITNUM               6U


/*** MCCC7 - Motor Controller Control Register 7; 0x000001D7 ***/
typedef union {
  byte Byte;
  struct {
    byte CD0         :1;                                       /* PWM Channel Delay */
    byte CD1         :1;                                       /* PWM Channel Delay */
    byte             :1; 
    byte             :1; 
    byte MCAM0       :1;                                       /* PWM Channel Alignment Mode */
    byte MCAM1       :1;                                       /* PWM Channel Alignment Mode */
    byte MCOM0       :1;                                       /* Output Mode */
    byte MCOM1       :1;                                       /* Output Mode */
  } Bits;
  struct {
    byte grpCD   :2;
    byte         :1;
    byte         :1;
    byte grpMCAM :2;
    byte grpMCOM :2;
  } MergedBits;
} MCCC7STR;
extern volatile MCCC7STR _MCCC7 @(REG_BASE + 0x000001D7UL);
#define MCCC7                           _MCCC7.Byte
#define MCCC7_CD0                       _MCCC7.Bits.CD0
#define MCCC7_CD1                       _MCCC7.Bits.CD1
#define MCCC7_MCAM0                     _MCCC7.Bits.MCAM0
#define MCCC7_MCAM1                     _MCCC7.Bits.MCAM1
#define MCCC7_MCOM0                     _MCCC7.Bits.MCOM0
#define MCCC7_MCOM1                     _MCCC7.Bits.MCOM1
#define MCCC7_CD                        _MCCC7.MergedBits.grpCD
#define MCCC7_MCAM                      _MCCC7.MergedBits.grpMCAM
#define MCCC7_MCOM                      _MCCC7.MergedBits.grpMCOM

#define MCCC7_CD0_MASK                  1U
#define MCCC7_CD1_MASK                  2U
#define MCCC7_MCAM0_MASK                16U
#define MCCC7_MCAM1_MASK                32U
#define MCCC7_MCOM0_MASK                64U
#define MCCC7_MCOM1_MASK                128U
#define MCCC7_CD_MASK                   3U
#define MCCC7_CD_BITNUM                 0U
#define MCCC7_MCAM_MASK                 48U
#define MCCC7_MCAM_BITNUM               4U
#define MCCC7_MCOM_MASK                 192U
#define MCCC7_MCOM_BITNUM               6U


/*** MCDC0 - Motor Controller Period Register 0; 0x000001E0 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** MCDC0_FAST - Motor Controller Period Register 0 access with FAST bit = 1; 0x000001E0 ***/
    union {
      byte Byte;
      struct {
        byte D2          :1;                                       /* Motor Controller Duty Cycle, bit 2 */
        byte D3          :1;                                       /* Motor Controller Duty Cycle, bit 3 */
        byte D4          :1;                                       /* Motor Controller Duty Cycle, bit 4 */
        byte D5          :1;                                       /* Motor Controller Duty Cycle, bit 5 */
        byte D6          :1;                                       /* Motor Controller Duty Cycle, bit 6 */
        byte D7          :1;                                       /* Motor Controller Duty Cycle, bit 7 */
        byte D8          :1;                                       /* Motor Controller Duty Cycle, bit 8 */
        byte S           :1;                                       /* Sign */
      } Bits;
      struct {
        byte grpD_2 :7;
        byte     :1;
      } MergedBits;
    } MCDC0_FASTSTR;
    #define MCDC0_FAST                  _MCDC0.Overlap_STR.MCDC0_FASTSTR.Byte
    #define MCDC0_FAST_D2               _MCDC0.Overlap_STR.MCDC0_FASTSTR.Bits.D2
    #define MCDC0_FAST_D3               _MCDC0.Overlap_STR.MCDC0_FASTSTR.Bits.D3
    #define MCDC0_FAST_D4               _MCDC0.Overlap_STR.MCDC0_FASTSTR.Bits.D4
    #define MCDC0_FAST_D5               _MCDC0.Overlap_STR.MCDC0_FASTSTR.Bits.D5
    #define MCDC0_FAST_D6               _MCDC0.Overlap_STR.MCDC0_FASTSTR.Bits.D6
    #define MCDC0_FAST_D7               _MCDC0.Overlap_STR.MCDC0_FASTSTR.Bits.D7
    #define MCDC0_FAST_D8               _MCDC0.Overlap_STR.MCDC0_FASTSTR.Bits.D8
    #define MCDC0_FAST_S                _MCDC0.Overlap_STR.MCDC0_FASTSTR.Bits.S
    #define MCDC0_FAST_D_2              _MCDC0.Overlap_STR.MCDC0_FASTSTR.MergedBits.grpD_2
    #define MCDC0_FAST_D                MCDC0_FAST_D_2
    
    #define MCDC0_FAST_D2_MASK          1U
    #define MCDC0_FAST_D3_MASK          2U
    #define MCDC0_FAST_D4_MASK          4U
    #define MCDC0_FAST_D5_MASK          8U
    #define MCDC0_FAST_D6_MASK          16U
    #define MCDC0_FAST_D7_MASK          32U
    #define MCDC0_FAST_D8_MASK          64U
    #define MCDC0_FAST_S_MASK           128U
    #define MCDC0_FAST_D_2_MASK         127U
    #define MCDC0_FAST_D_2_BITNUM       0U
    
  } Overlap_STR;

  struct {
    word D0          :1;                                       /* Motor Controller Duty Cycle, bit 0 */
    word D1          :1;                                       /* Motor Controller Duty Cycle, bit 1 */
    word D2          :1;                                       /* Motor Controller Duty Cycle, bit 2 */
    word D3          :1;                                       /* Motor Controller Duty Cycle, bit 3 */
    word D4          :1;                                       /* Motor Controller Duty Cycle, bit 4 */
    word D5          :1;                                       /* Motor Controller Duty Cycle, bit 5 */
    word D6          :1;                                       /* Motor Controller Duty Cycle, bit 6 */
    word D7          :1;                                       /* Motor Controller Duty Cycle, bit 7 */
    word D8          :1;                                       /* Motor Controller Duty Cycle, bit 8 */
    word D9          :1;                                       /* Motor Controller Duty Cycle, bit 9 */
    word D10         :1;                                       /* Motor Controller Duty Cycle, bit 10 */
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word S           :1;                                       /* Sign */
  } Bits;
  struct {
    word grpD    :11;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
  } MergedBits;
} MCDC0STR;
extern volatile MCDC0STR _MCDC0 @(REG_BASE + 0x000001E0UL);
#define MCDC0                           _MCDC0.Word
#define MCDC0_D0                        _MCDC0.Bits.D0
#define MCDC0_D1                        _MCDC0.Bits.D1
#define MCDC0_D2                        _MCDC0.Bits.D2
#define MCDC0_D3                        _MCDC0.Bits.D3
#define MCDC0_D4                        _MCDC0.Bits.D4
#define MCDC0_D5                        _MCDC0.Bits.D5
#define MCDC0_D6                        _MCDC0.Bits.D6
#define MCDC0_D7                        _MCDC0.Bits.D7
#define MCDC0_D8                        _MCDC0.Bits.D8
#define MCDC0_D9                        _MCDC0.Bits.D9
#define MCDC0_D10                       _MCDC0.Bits.D10
#define MCDC0_S                         _MCDC0.Bits.S
/* MCDC_ARR: Access 8 MCDCx registers in an array */
#define MCDC_ARR                        ((volatile word *) &MCDC0)
#define MCDC0_D                         _MCDC0.MergedBits.grpD

#define MCDC0_D0_MASK                   1U
#define MCDC0_D1_MASK                   2U
#define MCDC0_D2_MASK                   4U
#define MCDC0_D3_MASK                   8U
#define MCDC0_D4_MASK                   16U
#define MCDC0_D5_MASK                   32U
#define MCDC0_D6_MASK                   64U
#define MCDC0_D7_MASK                   128U
#define MCDC0_D8_MASK                   256U
#define MCDC0_D9_MASK                   512U
#define MCDC0_D10_MASK                  1024U
#define MCDC0_S_MASK                    32768U
#define MCDC0_D_MASK                    2047U
#define MCDC0_D_BITNUM                  0U


/*** MCDC1 - Motor Controller Period Register 1; 0x000001E2 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** MCDC1_FAST - Motor Controller Period Register 1 access with FAST bit = 1; 0x000001E2 ***/
    union {
      byte Byte;
      struct {
        byte D2          :1;                                       /* Motor Controller Duty Cycle, bit 2 */
        byte D3          :1;                                       /* Motor Controller Duty Cycle, bit 3 */
        byte D4          :1;                                       /* Motor Controller Duty Cycle, bit 4 */
        byte D5          :1;                                       /* Motor Controller Duty Cycle, bit 5 */
        byte D6          :1;                                       /* Motor Controller Duty Cycle, bit 6 */
        byte D7          :1;                                       /* Motor Controller Duty Cycle, bit 7 */
        byte D8          :1;                                       /* Motor Controller Duty Cycle, bit 8 */
        byte S           :1;                                       /* Sign */
      } Bits;
      struct {
        byte grpD_2 :7;
        byte     :1;
      } MergedBits;
    } MCDC1_FASTSTR;
    #define MCDC1_FAST                  _MCDC1.Overlap_STR.MCDC1_FASTSTR.Byte
    #define MCDC1_FAST_D2               _MCDC1.Overlap_STR.MCDC1_FASTSTR.Bits.D2
    #define MCDC1_FAST_D3               _MCDC1.Overlap_STR.MCDC1_FASTSTR.Bits.D3
    #define MCDC1_FAST_D4               _MCDC1.Overlap_STR.MCDC1_FASTSTR.Bits.D4
    #define MCDC1_FAST_D5               _MCDC1.Overlap_STR.MCDC1_FASTSTR.Bits.D5
    #define MCDC1_FAST_D6               _MCDC1.Overlap_STR.MCDC1_FASTSTR.Bits.D6
    #define MCDC1_FAST_D7               _MCDC1.Overlap_STR.MCDC1_FASTSTR.Bits.D7
    #define MCDC1_FAST_D8               _MCDC1.Overlap_STR.MCDC1_FASTSTR.Bits.D8
    #define MCDC1_FAST_S                _MCDC1.Overlap_STR.MCDC1_FASTSTR.Bits.S
    #define MCDC1_FAST_D_2              _MCDC1.Overlap_STR.MCDC1_FASTSTR.MergedBits.grpD_2
    #define MCDC1_FAST_D                MCDC1_FAST_D_2
    
    #define MCDC1_FAST_D2_MASK          1U
    #define MCDC1_FAST_D3_MASK          2U
    #define MCDC1_FAST_D4_MASK          4U
    #define MCDC1_FAST_D5_MASK          8U
    #define MCDC1_FAST_D6_MASK          16U
    #define MCDC1_FAST_D7_MASK          32U
    #define MCDC1_FAST_D8_MASK          64U
    #define MCDC1_FAST_S_MASK           128U
    #define MCDC1_FAST_D_2_MASK         127U
    #define MCDC1_FAST_D_2_BITNUM       0U
    
  } Overlap_STR;

  struct {
    word D0          :1;                                       /* Motor Controller Duty Cycle, bit 0 */
    word D1          :1;                                       /* Motor Controller Duty Cycle, bit 1 */
    word D2          :1;                                       /* Motor Controller Duty Cycle, bit 2 */
    word D3          :1;                                       /* Motor Controller Duty Cycle, bit 3 */
    word D4          :1;                                       /* Motor Controller Duty Cycle, bit 4 */
    word D5          :1;                                       /* Motor Controller Duty Cycle, bit 5 */
    word D6          :1;                                       /* Motor Controller Duty Cycle, bit 6 */
    word D7          :1;                                       /* Motor Controller Duty Cycle, bit 7 */
    word D8          :1;                                       /* Motor Controller Duty Cycle, bit 8 */
    word D9          :1;                                       /* Motor Controller Duty Cycle, bit 9 */
    word D10         :1;                                       /* Motor Controller Duty Cycle, bit 10 */
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word S           :1;                                       /* Sign */
  } Bits;
  struct {
    word grpD    :11;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
  } MergedBits;
} MCDC1STR;
extern volatile MCDC1STR _MCDC1 @(REG_BASE + 0x000001E2UL);
#define MCDC1                           _MCDC1.Word
#define MCDC1_D0                        _MCDC1.Bits.D0
#define MCDC1_D1                        _MCDC1.Bits.D1
#define MCDC1_D2                        _MCDC1.Bits.D2
#define MCDC1_D3                        _MCDC1.Bits.D3
#define MCDC1_D4                        _MCDC1.Bits.D4
#define MCDC1_D5                        _MCDC1.Bits.D5
#define MCDC1_D6                        _MCDC1.Bits.D6
#define MCDC1_D7                        _MCDC1.Bits.D7
#define MCDC1_D8                        _MCDC1.Bits.D8
#define MCDC1_D9                        _MCDC1.Bits.D9
#define MCDC1_D10                       _MCDC1.Bits.D10
#define MCDC1_S                         _MCDC1.Bits.S
#define MCDC1_D                         _MCDC1.MergedBits.grpD

#define MCDC1_D0_MASK                   1U
#define MCDC1_D1_MASK                   2U
#define MCDC1_D2_MASK                   4U
#define MCDC1_D3_MASK                   8U
#define MCDC1_D4_MASK                   16U
#define MCDC1_D5_MASK                   32U
#define MCDC1_D6_MASK                   64U
#define MCDC1_D7_MASK                   128U
#define MCDC1_D8_MASK                   256U
#define MCDC1_D9_MASK                   512U
#define MCDC1_D10_MASK                  1024U
#define MCDC1_S_MASK                    32768U
#define MCDC1_D_MASK                    2047U
#define MCDC1_D_BITNUM                  0U


/*** MCDC2 - Motor Controller Period Register 2; 0x000001E4 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** MCDC2_FAST - Motor Controller Period Register 2 access with FAST bit = 1; 0x000001E4 ***/
    union {
      byte Byte;
      struct {
        byte D2          :1;                                       /* Motor Controller Duty Cycle, bit 2 */
        byte D3          :1;                                       /* Motor Controller Duty Cycle, bit 3 */
        byte D4          :1;                                       /* Motor Controller Duty Cycle, bit 4 */
        byte D5          :1;                                       /* Motor Controller Duty Cycle, bit 5 */
        byte D6          :1;                                       /* Motor Controller Duty Cycle, bit 6 */
        byte D7          :1;                                       /* Motor Controller Duty Cycle, bit 7 */
        byte D8          :1;                                       /* Motor Controller Duty Cycle, bit 8 */
        byte S           :1;                                       /* Sign */
      } Bits;
      struct {
        byte grpD_2 :7;
        byte     :1;
      } MergedBits;
    } MCDC2_FASTSTR;
    #define MCDC2_FAST                  _MCDC2.Overlap_STR.MCDC2_FASTSTR.Byte
    #define MCDC2_FAST_D2               _MCDC2.Overlap_STR.MCDC2_FASTSTR.Bits.D2
    #define MCDC2_FAST_D3               _MCDC2.Overlap_STR.MCDC2_FASTSTR.Bits.D3
    #define MCDC2_FAST_D4               _MCDC2.Overlap_STR.MCDC2_FASTSTR.Bits.D4
    #define MCDC2_FAST_D5               _MCDC2.Overlap_STR.MCDC2_FASTSTR.Bits.D5
    #define MCDC2_FAST_D6               _MCDC2.Overlap_STR.MCDC2_FASTSTR.Bits.D6
    #define MCDC2_FAST_D7               _MCDC2.Overlap_STR.MCDC2_FASTSTR.Bits.D7
    #define MCDC2_FAST_D8               _MCDC2.Overlap_STR.MCDC2_FASTSTR.Bits.D8
    #define MCDC2_FAST_S                _MCDC2.Overlap_STR.MCDC2_FASTSTR.Bits.S
    #define MCDC2_FAST_D_2              _MCDC2.Overlap_STR.MCDC2_FASTSTR.MergedBits.grpD_2
    #define MCDC2_FAST_D                MCDC2_FAST_D_2
    
    #define MCDC2_FAST_D2_MASK          1U
    #define MCDC2_FAST_D3_MASK          2U
    #define MCDC2_FAST_D4_MASK          4U
    #define MCDC2_FAST_D5_MASK          8U
    #define MCDC2_FAST_D6_MASK          16U
    #define MCDC2_FAST_D7_MASK          32U
    #define MCDC2_FAST_D8_MASK          64U
    #define MCDC2_FAST_S_MASK           128U
    #define MCDC2_FAST_D_2_MASK         127U
    #define MCDC2_FAST_D_2_BITNUM       0U
    
  } Overlap_STR;

  struct {
    word D0          :1;                                       /* Motor Controller Duty Cycle, bit 0 */
    word D1          :1;                                       /* Motor Controller Duty Cycle, bit 1 */
    word D2          :1;                                       /* Motor Controller Duty Cycle, bit 2 */
    word D3          :1;                                       /* Motor Controller Duty Cycle, bit 3 */
    word D4          :1;                                       /* Motor Controller Duty Cycle, bit 4 */
    word D5          :1;                                       /* Motor Controller Duty Cycle, bit 5 */
    word D6          :1;                                       /* Motor Controller Duty Cycle, bit 6 */
    word D7          :1;                                       /* Motor Controller Duty Cycle, bit 7 */
    word D8          :1;                                       /* Motor Controller Duty Cycle, bit 8 */
    word D9          :1;                                       /* Motor Controller Duty Cycle, bit 9 */
    word D10         :1;                                       /* Motor Controller Duty Cycle, bit 10 */
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word S           :1;                                       /* Sign */
  } Bits;
  struct {
    word grpD    :11;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
  } MergedBits;
} MCDC2STR;
extern volatile MCDC2STR _MCDC2 @(REG_BASE + 0x000001E4UL);
#define MCDC2                           _MCDC2.Word
#define MCDC2_D0                        _MCDC2.Bits.D0
#define MCDC2_D1                        _MCDC2.Bits.D1
#define MCDC2_D2                        _MCDC2.Bits.D2
#define MCDC2_D3                        _MCDC2.Bits.D3
#define MCDC2_D4                        _MCDC2.Bits.D4
#define MCDC2_D5                        _MCDC2.Bits.D5
#define MCDC2_D6                        _MCDC2.Bits.D6
#define MCDC2_D7                        _MCDC2.Bits.D7
#define MCDC2_D8                        _MCDC2.Bits.D8
#define MCDC2_D9                        _MCDC2.Bits.D9
#define MCDC2_D10                       _MCDC2.Bits.D10
#define MCDC2_S                         _MCDC2.Bits.S
#define MCDC2_D                         _MCDC2.MergedBits.grpD

#define MCDC2_D0_MASK                   1U
#define MCDC2_D1_MASK                   2U
#define MCDC2_D2_MASK                   4U
#define MCDC2_D3_MASK                   8U
#define MCDC2_D4_MASK                   16U
#define MCDC2_D5_MASK                   32U
#define MCDC2_D6_MASK                   64U
#define MCDC2_D7_MASK                   128U
#define MCDC2_D8_MASK                   256U
#define MCDC2_D9_MASK                   512U
#define MCDC2_D10_MASK                  1024U
#define MCDC2_S_MASK                    32768U
#define MCDC2_D_MASK                    2047U
#define MCDC2_D_BITNUM                  0U


/*** MCDC3 - Motor Controller Period Register 3; 0x000001E6 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** MCDC3_FAST - Motor Controller Period Register 3 access with FAST bit = 1; 0x000001E6 ***/
    union {
      byte Byte;
      struct {
        byte D2          :1;                                       /* Motor Controller Duty Cycle, bit 2 */
        byte D3          :1;                                       /* Motor Controller Duty Cycle, bit 3 */
        byte D4          :1;                                       /* Motor Controller Duty Cycle, bit 4 */
        byte D5          :1;                                       /* Motor Controller Duty Cycle, bit 5 */
        byte D6          :1;                                       /* Motor Controller Duty Cycle, bit 6 */
        byte D7          :1;                                       /* Motor Controller Duty Cycle, bit 7 */
        byte D8          :1;                                       /* Motor Controller Duty Cycle, bit 8 */
        byte S           :1;                                       /* Sign */
      } Bits;
      struct {
        byte grpD_2 :7;
        byte     :1;
      } MergedBits;
    } MCDC3_FASTSTR;
    #define MCDC3_FAST                  _MCDC3.Overlap_STR.MCDC3_FASTSTR.Byte
    #define MCDC3_FAST_D2               _MCDC3.Overlap_STR.MCDC3_FASTSTR.Bits.D2
    #define MCDC3_FAST_D3               _MCDC3.Overlap_STR.MCDC3_FASTSTR.Bits.D3
    #define MCDC3_FAST_D4               _MCDC3.Overlap_STR.MCDC3_FASTSTR.Bits.D4
    #define MCDC3_FAST_D5               _MCDC3.Overlap_STR.MCDC3_FASTSTR.Bits.D5
    #define MCDC3_FAST_D6               _MCDC3.Overlap_STR.MCDC3_FASTSTR.Bits.D6
    #define MCDC3_FAST_D7               _MCDC3.Overlap_STR.MCDC3_FASTSTR.Bits.D7
    #define MCDC3_FAST_D8               _MCDC3.Overlap_STR.MCDC3_FASTSTR.Bits.D8
    #define MCDC3_FAST_S                _MCDC3.Overlap_STR.MCDC3_FASTSTR.Bits.S
    #define MCDC3_FAST_D_2              _MCDC3.Overlap_STR.MCDC3_FASTSTR.MergedBits.grpD_2
    #define MCDC3_FAST_D                MCDC3_FAST_D_2
    
    #define MCDC3_FAST_D2_MASK          1U
    #define MCDC3_FAST_D3_MASK          2U
    #define MCDC3_FAST_D4_MASK          4U
    #define MCDC3_FAST_D5_MASK          8U
    #define MCDC3_FAST_D6_MASK          16U
    #define MCDC3_FAST_D7_MASK          32U
    #define MCDC3_FAST_D8_MASK          64U
    #define MCDC3_FAST_S_MASK           128U
    #define MCDC3_FAST_D_2_MASK         127U
    #define MCDC3_FAST_D_2_BITNUM       0U
    
  } Overlap_STR;

  struct {
    word D0          :1;                                       /* Motor Controller Duty Cycle, bit 0 */
    word D1          :1;                                       /* Motor Controller Duty Cycle, bit 1 */
    word D2          :1;                                       /* Motor Controller Duty Cycle, bit 2 */
    word D3          :1;                                       /* Motor Controller Duty Cycle, bit 3 */
    word D4          :1;                                       /* Motor Controller Duty Cycle, bit 4 */
    word D5          :1;                                       /* Motor Controller Duty Cycle, bit 5 */
    word D6          :1;                                       /* Motor Controller Duty Cycle, bit 6 */
    word D7          :1;                                       /* Motor Controller Duty Cycle, bit 7 */
    word D8          :1;                                       /* Motor Controller Duty Cycle, bit 8 */
    word D9          :1;                                       /* Motor Controller Duty Cycle, bit 9 */
    word D10         :1;                                       /* Motor Controller Duty Cycle, bit 10 */
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word S           :1;                                       /* Sign */
  } Bits;
  struct {
    word grpD    :11;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
  } MergedBits;
} MCDC3STR;
extern volatile MCDC3STR _MCDC3 @(REG_BASE + 0x000001E6UL);
#define MCDC3                           _MCDC3.Word
#define MCDC3_D0                        _MCDC3.Bits.D0
#define MCDC3_D1                        _MCDC3.Bits.D1
#define MCDC3_D2                        _MCDC3.Bits.D2
#define MCDC3_D3                        _MCDC3.Bits.D3
#define MCDC3_D4                        _MCDC3.Bits.D4
#define MCDC3_D5                        _MCDC3.Bits.D5
#define MCDC3_D6                        _MCDC3.Bits.D6
#define MCDC3_D7                        _MCDC3.Bits.D7
#define MCDC3_D8                        _MCDC3.Bits.D8
#define MCDC3_D9                        _MCDC3.Bits.D9
#define MCDC3_D10                       _MCDC3.Bits.D10
#define MCDC3_S                         _MCDC3.Bits.S
#define MCDC3_D                         _MCDC3.MergedBits.grpD

#define MCDC3_D0_MASK                   1U
#define MCDC3_D1_MASK                   2U
#define MCDC3_D2_MASK                   4U
#define MCDC3_D3_MASK                   8U
#define MCDC3_D4_MASK                   16U
#define MCDC3_D5_MASK                   32U
#define MCDC3_D6_MASK                   64U
#define MCDC3_D7_MASK                   128U
#define MCDC3_D8_MASK                   256U
#define MCDC3_D9_MASK                   512U
#define MCDC3_D10_MASK                  1024U
#define MCDC3_S_MASK                    32768U
#define MCDC3_D_MASK                    2047U
#define MCDC3_D_BITNUM                  0U


/*** MCDC4 - Motor Controller Period Register 4; 0x000001E8 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** MCDC4_FAST - Motor Controller Period Register 4 access with FAST bit = 1; 0x000001E8 ***/
    union {
      byte Byte;
      struct {
        byte D2          :1;                                       /* Motor Controller Duty Cycle, bit 2 */
        byte D3          :1;                                       /* Motor Controller Duty Cycle, bit 3 */
        byte D4          :1;                                       /* Motor Controller Duty Cycle, bit 4 */
        byte D5          :1;                                       /* Motor Controller Duty Cycle, bit 5 */
        byte D6          :1;                                       /* Motor Controller Duty Cycle, bit 6 */
        byte D7          :1;                                       /* Motor Controller Duty Cycle, bit 7 */
        byte D8          :1;                                       /* Motor Controller Duty Cycle, bit 8 */
        byte S           :1;                                       /* Sign */
      } Bits;
      struct {
        byte grpD_2 :7;
        byte     :1;
      } MergedBits;
    } MCDC4_FASTSTR;
    #define MCDC4_FAST                  _MCDC4.Overlap_STR.MCDC4_FASTSTR.Byte
    #define MCDC4_FAST_D2               _MCDC4.Overlap_STR.MCDC4_FASTSTR.Bits.D2
    #define MCDC4_FAST_D3               _MCDC4.Overlap_STR.MCDC4_FASTSTR.Bits.D3
    #define MCDC4_FAST_D4               _MCDC4.Overlap_STR.MCDC4_FASTSTR.Bits.D4
    #define MCDC4_FAST_D5               _MCDC4.Overlap_STR.MCDC4_FASTSTR.Bits.D5
    #define MCDC4_FAST_D6               _MCDC4.Overlap_STR.MCDC4_FASTSTR.Bits.D6
    #define MCDC4_FAST_D7               _MCDC4.Overlap_STR.MCDC4_FASTSTR.Bits.D7
    #define MCDC4_FAST_D8               _MCDC4.Overlap_STR.MCDC4_FASTSTR.Bits.D8
    #define MCDC4_FAST_S                _MCDC4.Overlap_STR.MCDC4_FASTSTR.Bits.S
    #define MCDC4_FAST_D_2              _MCDC4.Overlap_STR.MCDC4_FASTSTR.MergedBits.grpD_2
    #define MCDC4_FAST_D                MCDC4_FAST_D_2
    
    #define MCDC4_FAST_D2_MASK          1U
    #define MCDC4_FAST_D3_MASK          2U
    #define MCDC4_FAST_D4_MASK          4U
    #define MCDC4_FAST_D5_MASK          8U
    #define MCDC4_FAST_D6_MASK          16U
    #define MCDC4_FAST_D7_MASK          32U
    #define MCDC4_FAST_D8_MASK          64U
    #define MCDC4_FAST_S_MASK           128U
    #define MCDC4_FAST_D_2_MASK         127U
    #define MCDC4_FAST_D_2_BITNUM       0U
    
  } Overlap_STR;

  struct {
    word D0          :1;                                       /* Motor Controller Duty Cycle, bit 0 */
    word D1          :1;                                       /* Motor Controller Duty Cycle, bit 1 */
    word D2          :1;                                       /* Motor Controller Duty Cycle, bit 2 */
    word D3          :1;                                       /* Motor Controller Duty Cycle, bit 3 */
    word D4          :1;                                       /* Motor Controller Duty Cycle, bit 4 */
    word D5          :1;                                       /* Motor Controller Duty Cycle, bit 5 */
    word D6          :1;                                       /* Motor Controller Duty Cycle, bit 6 */
    word D7          :1;                                       /* Motor Controller Duty Cycle, bit 7 */
    word D8          :1;                                       /* Motor Controller Duty Cycle, bit 8 */
    word D9          :1;                                       /* Motor Controller Duty Cycle, bit 9 */
    word D10         :1;                                       /* Motor Controller Duty Cycle, bit 10 */
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word S           :1;                                       /* Sign */
  } Bits;
  struct {
    word grpD    :11;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
  } MergedBits;
} MCDC4STR;
extern volatile MCDC4STR _MCDC4 @(REG_BASE + 0x000001E8UL);
#define MCDC4                           _MCDC4.Word
#define MCDC4_D0                        _MCDC4.Bits.D0
#define MCDC4_D1                        _MCDC4.Bits.D1
#define MCDC4_D2                        _MCDC4.Bits.D2
#define MCDC4_D3                        _MCDC4.Bits.D3
#define MCDC4_D4                        _MCDC4.Bits.D4
#define MCDC4_D5                        _MCDC4.Bits.D5
#define MCDC4_D6                        _MCDC4.Bits.D6
#define MCDC4_D7                        _MCDC4.Bits.D7
#define MCDC4_D8                        _MCDC4.Bits.D8
#define MCDC4_D9                        _MCDC4.Bits.D9
#define MCDC4_D10                       _MCDC4.Bits.D10
#define MCDC4_S                         _MCDC4.Bits.S
#define MCDC4_D                         _MCDC4.MergedBits.grpD

#define MCDC4_D0_MASK                   1U
#define MCDC4_D1_MASK                   2U
#define MCDC4_D2_MASK                   4U
#define MCDC4_D3_MASK                   8U
#define MCDC4_D4_MASK                   16U
#define MCDC4_D5_MASK                   32U
#define MCDC4_D6_MASK                   64U
#define MCDC4_D7_MASK                   128U
#define MCDC4_D8_MASK                   256U
#define MCDC4_D9_MASK                   512U
#define MCDC4_D10_MASK                  1024U
#define MCDC4_S_MASK                    32768U
#define MCDC4_D_MASK                    2047U
#define MCDC4_D_BITNUM                  0U


/*** MCDC5 - Motor Controller Period Register 5; 0x000001EA ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** MCDC5_FAST - Motor Controller Period Register 5 access with FAST bit = 1; 0x000001EA ***/
    union {
      byte Byte;
      struct {
        byte D2          :1;                                       /* Motor Controller Duty Cycle, bit 2 */
        byte D3          :1;                                       /* Motor Controller Duty Cycle, bit 3 */
        byte D4          :1;                                       /* Motor Controller Duty Cycle, bit 4 */
        byte D5          :1;                                       /* Motor Controller Duty Cycle, bit 5 */
        byte D6          :1;                                       /* Motor Controller Duty Cycle, bit 6 */
        byte D7          :1;                                       /* Motor Controller Duty Cycle, bit 7 */
        byte D8          :1;                                       /* Motor Controller Duty Cycle, bit 8 */
        byte S           :1;                                       /* Sign */
      } Bits;
      struct {
        byte grpD_2 :7;
        byte     :1;
      } MergedBits;
    } MCDC5_FASTSTR;
    #define MCDC5_FAST                  _MCDC5.Overlap_STR.MCDC5_FASTSTR.Byte
    #define MCDC5_FAST_D2               _MCDC5.Overlap_STR.MCDC5_FASTSTR.Bits.D2
    #define MCDC5_FAST_D3               _MCDC5.Overlap_STR.MCDC5_FASTSTR.Bits.D3
    #define MCDC5_FAST_D4               _MCDC5.Overlap_STR.MCDC5_FASTSTR.Bits.D4
    #define MCDC5_FAST_D5               _MCDC5.Overlap_STR.MCDC5_FASTSTR.Bits.D5
    #define MCDC5_FAST_D6               _MCDC5.Overlap_STR.MCDC5_FASTSTR.Bits.D6
    #define MCDC5_FAST_D7               _MCDC5.Overlap_STR.MCDC5_FASTSTR.Bits.D7
    #define MCDC5_FAST_D8               _MCDC5.Overlap_STR.MCDC5_FASTSTR.Bits.D8
    #define MCDC5_FAST_S                _MCDC5.Overlap_STR.MCDC5_FASTSTR.Bits.S
    #define MCDC5_FAST_D_2              _MCDC5.Overlap_STR.MCDC5_FASTSTR.MergedBits.grpD_2
    #define MCDC5_FAST_D                MCDC5_FAST_D_2
    
    #define MCDC5_FAST_D2_MASK          1U
    #define MCDC5_FAST_D3_MASK          2U
    #define MCDC5_FAST_D4_MASK          4U
    #define MCDC5_FAST_D5_MASK          8U
    #define MCDC5_FAST_D6_MASK          16U
    #define MCDC5_FAST_D7_MASK          32U
    #define MCDC5_FAST_D8_MASK          64U
    #define MCDC5_FAST_S_MASK           128U
    #define MCDC5_FAST_D_2_MASK         127U
    #define MCDC5_FAST_D_2_BITNUM       0U
    
  } Overlap_STR;

  struct {
    word D0          :1;                                       /* Motor Controller Duty Cycle, bit 0 */
    word D1          :1;                                       /* Motor Controller Duty Cycle, bit 1 */
    word D2          :1;                                       /* Motor Controller Duty Cycle, bit 2 */
    word D3          :1;                                       /* Motor Controller Duty Cycle, bit 3 */
    word D4          :1;                                       /* Motor Controller Duty Cycle, bit 4 */
    word D5          :1;                                       /* Motor Controller Duty Cycle, bit 5 */
    word D6          :1;                                       /* Motor Controller Duty Cycle, bit 6 */
    word D7          :1;                                       /* Motor Controller Duty Cycle, bit 7 */
    word D8          :1;                                       /* Motor Controller Duty Cycle, bit 8 */
    word D9          :1;                                       /* Motor Controller Duty Cycle, bit 9 */
    word D10         :1;                                       /* Motor Controller Duty Cycle, bit 10 */
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word S           :1;                                       /* Sign */
  } Bits;
  struct {
    word grpD    :11;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
  } MergedBits;
} MCDC5STR;
extern volatile MCDC5STR _MCDC5 @(REG_BASE + 0x000001EAUL);
#define MCDC5                           _MCDC5.Word
#define MCDC5_D0                        _MCDC5.Bits.D0
#define MCDC5_D1                        _MCDC5.Bits.D1
#define MCDC5_D2                        _MCDC5.Bits.D2
#define MCDC5_D3                        _MCDC5.Bits.D3
#define MCDC5_D4                        _MCDC5.Bits.D4
#define MCDC5_D5                        _MCDC5.Bits.D5
#define MCDC5_D6                        _MCDC5.Bits.D6
#define MCDC5_D7                        _MCDC5.Bits.D7
#define MCDC5_D8                        _MCDC5.Bits.D8
#define MCDC5_D9                        _MCDC5.Bits.D9
#define MCDC5_D10                       _MCDC5.Bits.D10
#define MCDC5_S                         _MCDC5.Bits.S
#define MCDC5_D                         _MCDC5.MergedBits.grpD

#define MCDC5_D0_MASK                   1U
#define MCDC5_D1_MASK                   2U
#define MCDC5_D2_MASK                   4U
#define MCDC5_D3_MASK                   8U
#define MCDC5_D4_MASK                   16U
#define MCDC5_D5_MASK                   32U
#define MCDC5_D6_MASK                   64U
#define MCDC5_D7_MASK                   128U
#define MCDC5_D8_MASK                   256U
#define MCDC5_D9_MASK                   512U
#define MCDC5_D10_MASK                  1024U
#define MCDC5_S_MASK                    32768U
#define MCDC5_D_MASK                    2047U
#define MCDC5_D_BITNUM                  0U


/*** MCDC6 - Motor Controller Period Register 6; 0x000001EC ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** MCDC6_FAST - Motor Controller Period Register 6 access with FAST bit = 1; 0x000001EC ***/
    union {
      byte Byte;
      struct {
        byte D2          :1;                                       /* Motor Controller Duty Cycle, bit 2 */
        byte D3          :1;                                       /* Motor Controller Duty Cycle, bit 3 */
        byte D4          :1;                                       /* Motor Controller Duty Cycle, bit 4 */
        byte D5          :1;                                       /* Motor Controller Duty Cycle, bit 5 */
        byte D6          :1;                                       /* Motor Controller Duty Cycle, bit 6 */
        byte D7          :1;                                       /* Motor Controller Duty Cycle, bit 7 */
        byte D8          :1;                                       /* Motor Controller Duty Cycle, bit 8 */
        byte S           :1;                                       /* Sign */
      } Bits;
      struct {
        byte grpD_2 :7;
        byte     :1;
      } MergedBits;
    } MCDC6_FASTSTR;
    #define MCDC6_FAST                  _MCDC6.Overlap_STR.MCDC6_FASTSTR.Byte
    #define MCDC6_FAST_D2               _MCDC6.Overlap_STR.MCDC6_FASTSTR.Bits.D2
    #define MCDC6_FAST_D3               _MCDC6.Overlap_STR.MCDC6_FASTSTR.Bits.D3
    #define MCDC6_FAST_D4               _MCDC6.Overlap_STR.MCDC6_FASTSTR.Bits.D4
    #define MCDC6_FAST_D5               _MCDC6.Overlap_STR.MCDC6_FASTSTR.Bits.D5
    #define MCDC6_FAST_D6               _MCDC6.Overlap_STR.MCDC6_FASTSTR.Bits.D6
    #define MCDC6_FAST_D7               _MCDC6.Overlap_STR.MCDC6_FASTSTR.Bits.D7
    #define MCDC6_FAST_D8               _MCDC6.Overlap_STR.MCDC6_FASTSTR.Bits.D8
    #define MCDC6_FAST_S                _MCDC6.Overlap_STR.MCDC6_FASTSTR.Bits.S
    #define MCDC6_FAST_D_2              _MCDC6.Overlap_STR.MCDC6_FASTSTR.MergedBits.grpD_2
    #define MCDC6_FAST_D                MCDC6_FAST_D_2
    
    #define MCDC6_FAST_D2_MASK          1U
    #define MCDC6_FAST_D3_MASK          2U
    #define MCDC6_FAST_D4_MASK          4U
    #define MCDC6_FAST_D5_MASK          8U
    #define MCDC6_FAST_D6_MASK          16U
    #define MCDC6_FAST_D7_MASK          32U
    #define MCDC6_FAST_D8_MASK          64U
    #define MCDC6_FAST_S_MASK           128U
    #define MCDC6_FAST_D_2_MASK         127U
    #define MCDC6_FAST_D_2_BITNUM       0U
    
  } Overlap_STR;

  struct {
    word D0          :1;                                       /* Motor Controller Duty Cycle, bit 0 */
    word D1          :1;                                       /* Motor Controller Duty Cycle, bit 1 */
    word D2          :1;                                       /* Motor Controller Duty Cycle, bit 2 */
    word D3          :1;                                       /* Motor Controller Duty Cycle, bit 3 */
    word D4          :1;                                       /* Motor Controller Duty Cycle, bit 4 */
    word D5          :1;                                       /* Motor Controller Duty Cycle, bit 5 */
    word D6          :1;                                       /* Motor Controller Duty Cycle, bit 6 */
    word D7          :1;                                       /* Motor Controller Duty Cycle, bit 7 */
    word D8          :1;                                       /* Motor Controller Duty Cycle, bit 8 */
    word D9          :1;                                       /* Motor Controller Duty Cycle, bit 9 */
    word D10         :1;                                       /* Motor Controller Duty Cycle, bit 10 */
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word S           :1;                                       /* Sign */
  } Bits;
  struct {
    word grpD    :11;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
  } MergedBits;
} MCDC6STR;
extern volatile MCDC6STR _MCDC6 @(REG_BASE + 0x000001ECUL);
#define MCDC6                           _MCDC6.Word
#define MCDC6_D0                        _MCDC6.Bits.D0
#define MCDC6_D1                        _MCDC6.Bits.D1
#define MCDC6_D2                        _MCDC6.Bits.D2
#define MCDC6_D3                        _MCDC6.Bits.D3
#define MCDC6_D4                        _MCDC6.Bits.D4
#define MCDC6_D5                        _MCDC6.Bits.D5
#define MCDC6_D6                        _MCDC6.Bits.D6
#define MCDC6_D7                        _MCDC6.Bits.D7
#define MCDC6_D8                        _MCDC6.Bits.D8
#define MCDC6_D9                        _MCDC6.Bits.D9
#define MCDC6_D10                       _MCDC6.Bits.D10
#define MCDC6_S                         _MCDC6.Bits.S
#define MCDC6_D                         _MCDC6.MergedBits.grpD

#define MCDC6_D0_MASK                   1U
#define MCDC6_D1_MASK                   2U
#define MCDC6_D2_MASK                   4U
#define MCDC6_D3_MASK                   8U
#define MCDC6_D4_MASK                   16U
#define MCDC6_D5_MASK                   32U
#define MCDC6_D6_MASK                   64U
#define MCDC6_D7_MASK                   128U
#define MCDC6_D8_MASK                   256U
#define MCDC6_D9_MASK                   512U
#define MCDC6_D10_MASK                  1024U
#define MCDC6_S_MASK                    32768U
#define MCDC6_D_MASK                    2047U
#define MCDC6_D_BITNUM                  0U


/*** MCDC7 - Motor Controller Period Register 7; 0x000001EE ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** MCDC7_FAST - Motor Controller Period Register 7 access with FAST bit = 1; 0x000001EE ***/
    union {
      byte Byte;
      struct {
        byte D2          :1;                                       /* Motor Controller Duty Cycle, bit 2 */
        byte D3          :1;                                       /* Motor Controller Duty Cycle, bit 3 */
        byte D4          :1;                                       /* Motor Controller Duty Cycle, bit 4 */
        byte D5          :1;                                       /* Motor Controller Duty Cycle, bit 5 */
        byte D6          :1;                                       /* Motor Controller Duty Cycle, bit 6 */
        byte D7          :1;                                       /* Motor Controller Duty Cycle, bit 7 */
        byte D8          :1;                                       /* Motor Controller Duty Cycle, bit 8 */
        byte S           :1;                                       /* Sign */
      } Bits;
      struct {
        byte grpD_2 :7;
        byte     :1;
      } MergedBits;
    } MCDC7_FASTSTR;
    #define MCDC7_FAST                  _MCDC7.Overlap_STR.MCDC7_FASTSTR.Byte
    #define MCDC7_FAST_D2               _MCDC7.Overlap_STR.MCDC7_FASTSTR.Bits.D2
    #define MCDC7_FAST_D3               _MCDC7.Overlap_STR.MCDC7_FASTSTR.Bits.D3
    #define MCDC7_FAST_D4               _MCDC7.Overlap_STR.MCDC7_FASTSTR.Bits.D4
    #define MCDC7_FAST_D5               _MCDC7.Overlap_STR.MCDC7_FASTSTR.Bits.D5
    #define MCDC7_FAST_D6               _MCDC7.Overlap_STR.MCDC7_FASTSTR.Bits.D6
    #define MCDC7_FAST_D7               _MCDC7.Overlap_STR.MCDC7_FASTSTR.Bits.D7
    #define MCDC7_FAST_D8               _MCDC7.Overlap_STR.MCDC7_FASTSTR.Bits.D8
    #define MCDC7_FAST_S                _MCDC7.Overlap_STR.MCDC7_FASTSTR.Bits.S
    #define MCDC7_FAST_D_2              _MCDC7.Overlap_STR.MCDC7_FASTSTR.MergedBits.grpD_2
    #define MCDC7_FAST_D                MCDC7_FAST_D_2
    
    #define MCDC7_FAST_D2_MASK          1U
    #define MCDC7_FAST_D3_MASK          2U
    #define MCDC7_FAST_D4_MASK          4U
    #define MCDC7_FAST_D5_MASK          8U
    #define MCDC7_FAST_D6_MASK          16U
    #define MCDC7_FAST_D7_MASK          32U
    #define MCDC7_FAST_D8_MASK          64U
    #define MCDC7_FAST_S_MASK           128U
    #define MCDC7_FAST_D_2_MASK         127U
    #define MCDC7_FAST_D_2_BITNUM       0U
    
  } Overlap_STR;

  struct {
    word D0          :1;                                       /* Motor Controller Duty Cycle, bit 0 */
    word D1          :1;                                       /* Motor Controller Duty Cycle, bit 1 */
    word D2          :1;                                       /* Motor Controller Duty Cycle, bit 2 */
    word D3          :1;                                       /* Motor Controller Duty Cycle, bit 3 */
    word D4          :1;                                       /* Motor Controller Duty Cycle, bit 4 */
    word D5          :1;                                       /* Motor Controller Duty Cycle, bit 5 */
    word D6          :1;                                       /* Motor Controller Duty Cycle, bit 6 */
    word D7          :1;                                       /* Motor Controller Duty Cycle, bit 7 */
    word D8          :1;                                       /* Motor Controller Duty Cycle, bit 8 */
    word D9          :1;                                       /* Motor Controller Duty Cycle, bit 9 */
    word D10         :1;                                       /* Motor Controller Duty Cycle, bit 10 */
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word S           :1;                                       /* Sign */
  } Bits;
  struct {
    word grpD    :11;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
  } MergedBits;
} MCDC7STR;
extern volatile MCDC7STR _MCDC7 @(REG_BASE + 0x000001EEUL);
#define MCDC7                           _MCDC7.Word
#define MCDC7_D0                        _MCDC7.Bits.D0
#define MCDC7_D1                        _MCDC7.Bits.D1
#define MCDC7_D2                        _MCDC7.Bits.D2
#define MCDC7_D3                        _MCDC7.Bits.D3
#define MCDC7_D4                        _MCDC7.Bits.D4
#define MCDC7_D5                        _MCDC7.Bits.D5
#define MCDC7_D6                        _MCDC7.Bits.D6
#define MCDC7_D7                        _MCDC7.Bits.D7
#define MCDC7_D8                        _MCDC7.Bits.D8
#define MCDC7_D9                        _MCDC7.Bits.D9
#define MCDC7_D10                       _MCDC7.Bits.D10
#define MCDC7_S                         _MCDC7.Bits.S
#define MCDC7_D                         _MCDC7.MergedBits.grpD

#define MCDC7_D0_MASK                   1U
#define MCDC7_D1_MASK                   2U
#define MCDC7_D2_MASK                   4U
#define MCDC7_D3_MASK                   8U
#define MCDC7_D4_MASK                   16U
#define MCDC7_D5_MASK                   32U
#define MCDC7_D6_MASK                   64U
#define MCDC7_D7_MASK                   128U
#define MCDC7_D8_MASK                   256U
#define MCDC7_D9_MASK                   512U
#define MCDC7_D10_MASK                  1024U
#define MCDC7_S_MASK                    32768U
#define MCDC7_D_MASK                    2047U
#define MCDC7_D_BITNUM                  0U


/*** LCDCR0 - LCD Control Register 0; 0x00000200 ***/
typedef union {
  byte Byte;
  struct {
    byte DUTY0       :1;                                       /* LCD Duty Select Bit 0 */
    byte DUTY1       :1;                                       /* LCD Duty Select Bit 1 */
    byte BIAS        :1;                                       /* BIAS Voltage Level Select */
    byte LCLK0       :1;                                       /* LCD Clock Prescaler Bit 0 */
    byte LCLK1       :1;                                       /* LCD Clock Prescaler Bit 1 */
    byte LCLK2       :1;                                       /* LCD Clock Prescaler Bit 2 */
    byte             :1; 
    byte LCDEN       :1;                                       /* LCD32F4BV1 Driver System Enable */
  } Bits;
  struct {
    byte grpDUTY :2;
    byte         :1;
    byte grpLCLK :3;
    byte         :1;
    byte         :1;
  } MergedBits;
} LCDCR0STR;
extern volatile LCDCR0STR _LCDCR0 @(REG_BASE + 0x00000200UL);
#define LCDCR0                          _LCDCR0.Byte
#define LCDCR0_DUTY0                    _LCDCR0.Bits.DUTY0
#define LCDCR0_DUTY1                    _LCDCR0.Bits.DUTY1
#define LCDCR0_BIAS                     _LCDCR0.Bits.BIAS
#define LCDCR0_LCLK0                    _LCDCR0.Bits.LCLK0
#define LCDCR0_LCLK1                    _LCDCR0.Bits.LCLK1
#define LCDCR0_LCLK2                    _LCDCR0.Bits.LCLK2
#define LCDCR0_LCDEN                    _LCDCR0.Bits.LCDEN
/* LCDCR_ARR: Access 2 LCDCRx registers in an array */
#define LCDCR_ARR                       ((volatile byte *) &LCDCR0)
#define LCDCR0_DUTY                     _LCDCR0.MergedBits.grpDUTY
#define LCDCR0_LCLK                     _LCDCR0.MergedBits.grpLCLK

#define LCDCR0_DUTY0_MASK               1U
#define LCDCR0_DUTY1_MASK               2U
#define LCDCR0_BIAS_MASK                4U
#define LCDCR0_LCLK0_MASK               8U
#define LCDCR0_LCLK1_MASK               16U
#define LCDCR0_LCLK2_MASK               32U
#define LCDCR0_LCDEN_MASK               128U
#define LCDCR0_DUTY_MASK                3U
#define LCDCR0_DUTY_BITNUM              0U
#define LCDCR0_LCLK_MASK                56U
#define LCDCR0_LCLK_BITNUM              3U


/*** LCDCR1 - LCD Control Register 1; 0x00000201 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte LCDSWAI     :1;                                       /* LCD Stop in Wait Mode */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} LCDCR1STR;
extern volatile LCDCR1STR _LCDCR1 @(REG_BASE + 0x00000201UL);
#define LCDCR1                          _LCDCR1.Byte
#define LCDCR1_LCDSWAI                  _LCDCR1.Bits.LCDSWAI

#define LCDCR1_LCDSWAI_MASK             2U


/*** FPENR0 - LCD Frontplane Enable Register 0; 0x00000202 ***/
typedef union {
  byte Byte;
  struct {
    byte FP0EN       :1;                                       /* Frontplane Output Enable Bit 0 */
    byte FP1EN       :1;                                       /* Frontplane Output Enable Bit 1 */
    byte FP2EN       :1;                                       /* Frontplane Output Enable Bit 2 */
    byte FP3EN       :1;                                       /* Frontplane Output Enable Bit 3 */
    byte FP4EN       :1;                                       /* Frontplane Output Enable Bit 4 */
    byte FP5EN       :1;                                       /* Frontplane Output Enable Bit 5 */
    byte FP6EN       :1;                                       /* Frontplane Output Enable Bit 6 */
    byte FP7EN       :1;                                       /* Frontplane Output Enable Bit 7 */
  } Bits;
} FPENR0STR;
extern volatile FPENR0STR _FPENR0 @(REG_BASE + 0x00000202UL);
#define FPENR0                          _FPENR0.Byte
#define FPENR0_FP0EN                    _FPENR0.Bits.FP0EN
#define FPENR0_FP1EN                    _FPENR0.Bits.FP1EN
#define FPENR0_FP2EN                    _FPENR0.Bits.FP2EN
#define FPENR0_FP3EN                    _FPENR0.Bits.FP3EN
#define FPENR0_FP4EN                    _FPENR0.Bits.FP4EN
#define FPENR0_FP5EN                    _FPENR0.Bits.FP5EN
#define FPENR0_FP6EN                    _FPENR0.Bits.FP6EN
#define FPENR0_FP7EN                    _FPENR0.Bits.FP7EN
/* FPENR_ARR: Access 5 FPENRx registers in an array */
#define FPENR_ARR                       ((volatile byte *) &FPENR0)

#define FPENR0_FP0EN_MASK               1U
#define FPENR0_FP1EN_MASK               2U
#define FPENR0_FP2EN_MASK               4U
#define FPENR0_FP3EN_MASK               8U
#define FPENR0_FP4EN_MASK               16U
#define FPENR0_FP5EN_MASK               32U
#define FPENR0_FP6EN_MASK               64U
#define FPENR0_FP7EN_MASK               128U


/*** FPENR1 - LCD Frontplane Enable Register 1; 0x00000203 ***/
typedef union {
  byte Byte;
  struct {
    byte FP8EN       :1;                                       /* Frontplane Output Enable Bit 8 */
    byte FP9EN       :1;                                       /* Frontplane Output Enable Bit 9 */
    byte FP10EN      :1;                                       /* Frontplane Output Enable Bit 10 */
    byte FP11EN      :1;                                       /* Frontplane Output Enable Bit 11 */
    byte FP12EN      :1;                                       /* Frontplane Output Enable Bit 12 */
    byte FP13EN      :1;                                       /* Frontplane Output Enable Bit 13 */
    byte FP14EN      :1;                                       /* Frontplane Output Enable Bit 14 */
    byte FP15EN      :1;                                       /* Frontplane Output Enable Bit 15 */
  } Bits;
} FPENR1STR;
extern volatile FPENR1STR _FPENR1 @(REG_BASE + 0x00000203UL);
#define FPENR1                          _FPENR1.Byte
#define FPENR1_FP8EN                    _FPENR1.Bits.FP8EN
#define FPENR1_FP9EN                    _FPENR1.Bits.FP9EN
#define FPENR1_FP10EN                   _FPENR1.Bits.FP10EN
#define FPENR1_FP11EN                   _FPENR1.Bits.FP11EN
#define FPENR1_FP12EN                   _FPENR1.Bits.FP12EN
#define FPENR1_FP13EN                   _FPENR1.Bits.FP13EN
#define FPENR1_FP14EN                   _FPENR1.Bits.FP14EN
#define FPENR1_FP15EN                   _FPENR1.Bits.FP15EN

#define FPENR1_FP8EN_MASK               1U
#define FPENR1_FP9EN_MASK               2U
#define FPENR1_FP10EN_MASK              4U
#define FPENR1_FP11EN_MASK              8U
#define FPENR1_FP12EN_MASK              16U
#define FPENR1_FP13EN_MASK              32U
#define FPENR1_FP14EN_MASK              64U
#define FPENR1_FP15EN_MASK              128U


/*** FPENR2 - LCD Frontplane Enable Register 2; 0x00000204 ***/
typedef union {
  byte Byte;
  struct {
    byte FP16EN      :1;                                       /* Frontplane Output Enable Bit 16 */
    byte FP17EN      :1;                                       /* Frontplane Output Enable Bit 17 */
    byte FP18EN      :1;                                       /* Frontplane Output Enable Bit 18 */
    byte FP19EN      :1;                                       /* Frontplane Output Enable Bit 19 */
    byte FP20EN      :1;                                       /* Frontplane Output Enable Bit 20 */
    byte FP21EN      :1;                                       /* Frontplane Output Enable Bit 21 */
    byte FP22EN      :1;                                       /* Frontplane Output Enable Bit 22 */
    byte FP23EN      :1;                                       /* Frontplane Output Enable Bit 23 */
  } Bits;
} FPENR2STR;
extern volatile FPENR2STR _FPENR2 @(REG_BASE + 0x00000204UL);
#define FPENR2                          _FPENR2.Byte
#define FPENR2_FP16EN                   _FPENR2.Bits.FP16EN
#define FPENR2_FP17EN                   _FPENR2.Bits.FP17EN
#define FPENR2_FP18EN                   _FPENR2.Bits.FP18EN
#define FPENR2_FP19EN                   _FPENR2.Bits.FP19EN
#define FPENR2_FP20EN                   _FPENR2.Bits.FP20EN
#define FPENR2_FP21EN                   _FPENR2.Bits.FP21EN
#define FPENR2_FP22EN                   _FPENR2.Bits.FP22EN
#define FPENR2_FP23EN                   _FPENR2.Bits.FP23EN

#define FPENR2_FP16EN_MASK              1U
#define FPENR2_FP17EN_MASK              2U
#define FPENR2_FP18EN_MASK              4U
#define FPENR2_FP19EN_MASK              8U
#define FPENR2_FP20EN_MASK              16U
#define FPENR2_FP21EN_MASK              32U
#define FPENR2_FP22EN_MASK              64U
#define FPENR2_FP23EN_MASK              128U


/*** FPENR3 - LCD Frontplane Enable Register 3; 0x00000205 ***/
typedef union {
  byte Byte;
  struct {
    byte FP24EN      :1;                                       /* Frontplane Output Enable Bit 24 */
    byte FP25EN      :1;                                       /* Frontplane Output Enable Bit 25 */
    byte FP26EN      :1;                                       /* Frontplane Output Enable Bit 26 */
    byte FP27EN      :1;                                       /* Frontplane Output Enable Bit 27 */
    byte FP28EN      :1;                                       /* Frontplane Output Enable Bit 28 */
    byte FP29EN      :1;                                       /* Frontplane Output Enable Bit 29 */
    byte FP30EN      :1;                                       /* Frontplane Output Enable Bit 30 */
    byte FP31EN      :1;                                       /* Frontplane Output Enable Bit 31 */
  } Bits;
} FPENR3STR;
extern volatile FPENR3STR _FPENR3 @(REG_BASE + 0x00000205UL);
#define FPENR3                          _FPENR3.Byte
#define FPENR3_FP24EN                   _FPENR3.Bits.FP24EN
#define FPENR3_FP25EN                   _FPENR3.Bits.FP25EN
#define FPENR3_FP26EN                   _FPENR3.Bits.FP26EN
#define FPENR3_FP27EN                   _FPENR3.Bits.FP27EN
#define FPENR3_FP28EN                   _FPENR3.Bits.FP28EN
#define FPENR3_FP29EN                   _FPENR3.Bits.FP29EN
#define FPENR3_FP30EN                   _FPENR3.Bits.FP30EN
#define FPENR3_FP31EN                   _FPENR3.Bits.FP31EN

#define FPENR3_FP24EN_MASK              1U
#define FPENR3_FP25EN_MASK              2U
#define FPENR3_FP26EN_MASK              4U
#define FPENR3_FP27EN_MASK              8U
#define FPENR3_FP28EN_MASK              16U
#define FPENR3_FP29EN_MASK              32U
#define FPENR3_FP30EN_MASK              64U
#define FPENR3_FP31EN_MASK              128U


/*** FPENR4 - LCD Frontplane Enable Register 4; 0x00000206 ***/
typedef union {
  byte Byte;
  struct {
    byte FP32EN      :1;                                       /* Frontplane Output Enable Bit 32 */
    byte FP33EN      :1;                                       /* Frontplane Output Enable Bit 33 */
    byte FP34EN      :1;                                       /* Frontplane Output Enable Bit 34 */
    byte FP35EN      :1;                                       /* Frontplane Output Enable Bit 35 */
    byte FP36EN      :1;                                       /* Frontplane Output Enable Bit 36 */
    byte FP37EN      :1;                                       /* Frontplane Output Enable Bit 37 */
    byte FP38EN      :1;                                       /* Frontplane Output Enable Bit 38 */
    byte FP39EN      :1;                                       /* Frontplane Output Enable Bit 39 */
  } Bits;
} FPENR4STR;
extern volatile FPENR4STR _FPENR4 @(REG_BASE + 0x00000206UL);
#define FPENR4                          _FPENR4.Byte
#define FPENR4_FP32EN                   _FPENR4.Bits.FP32EN
#define FPENR4_FP33EN                   _FPENR4.Bits.FP33EN
#define FPENR4_FP34EN                   _FPENR4.Bits.FP34EN
#define FPENR4_FP35EN                   _FPENR4.Bits.FP35EN
#define FPENR4_FP36EN                   _FPENR4.Bits.FP36EN
#define FPENR4_FP37EN                   _FPENR4.Bits.FP37EN
#define FPENR4_FP38EN                   _FPENR4.Bits.FP38EN
#define FPENR4_FP39EN                   _FPENR4.Bits.FP39EN

#define FPENR4_FP32EN_MASK              1U
#define FPENR4_FP33EN_MASK              2U
#define FPENR4_FP34EN_MASK              4U
#define FPENR4_FP35EN_MASK              8U
#define FPENR4_FP36EN_MASK              16U
#define FPENR4_FP37EN_MASK              32U
#define FPENR4_FP38EN_MASK              64U
#define FPENR4_FP39EN_MASK              128U


/*** LCDRAM0 - LCD RAM 0; 0x00000208 ***/
typedef union {
  byte Byte;
  struct {
    byte FP0BP0      :1;                                       /* LCD Segment FP0, BP0 ON */
    byte FP0BP1      :1;                                       /* LCD Segment FP0, BP1 ON */
    byte FP0BP2      :1;                                       /* LCD Segment FP0, BP2 ON */
    byte FP0BP3      :1;                                       /* LCD Segment FP0, BP3 ON */
    byte FP1BP0      :1;                                       /* LCD Segment FP1, BP0 ON */
    byte FP1BP1      :1;                                       /* LCD Segment FP1, BP1 ON */
    byte FP1BP2      :1;                                       /* LCD Segment FP1, BP2 ON */
    byte FP1BP3      :1;                                       /* LCD Segment FP1, BP3 ON */
  } Bits;
  struct {
    byte grpFP0BP :4;
    byte grpFP1BP :4;
  } MergedBits;
} LCDRAM0STR;
extern volatile LCDRAM0STR _LCDRAM0 @(REG_BASE + 0x00000208UL);
#define LCDRAM0                         _LCDRAM0.Byte
#define LCDRAM0_FP0BP0                  _LCDRAM0.Bits.FP0BP0
#define LCDRAM0_FP0BP1                  _LCDRAM0.Bits.FP0BP1
#define LCDRAM0_FP0BP2                  _LCDRAM0.Bits.FP0BP2
#define LCDRAM0_FP0BP3                  _LCDRAM0.Bits.FP0BP3
#define LCDRAM0_FP1BP0                  _LCDRAM0.Bits.FP1BP0
#define LCDRAM0_FP1BP1                  _LCDRAM0.Bits.FP1BP1
#define LCDRAM0_FP1BP2                  _LCDRAM0.Bits.FP1BP2
#define LCDRAM0_FP1BP3                  _LCDRAM0.Bits.FP1BP3
/* LCDRAM_ARR: Access 20 LCDRAMx registers in an array */
#define LCDRAM_ARR                      ((volatile byte *) &LCDRAM0)
#define LCDRAM0_FP0BP                   _LCDRAM0.MergedBits.grpFP0BP
#define LCDRAM0_FP1BP                   _LCDRAM0.MergedBits.grpFP1BP

#define LCDRAM0_FP0BP0_MASK             1U
#define LCDRAM0_FP0BP1_MASK             2U
#define LCDRAM0_FP0BP2_MASK             4U
#define LCDRAM0_FP0BP3_MASK             8U
#define LCDRAM0_FP1BP0_MASK             16U
#define LCDRAM0_FP1BP1_MASK             32U
#define LCDRAM0_FP1BP2_MASK             64U
#define LCDRAM0_FP1BP3_MASK             128U
#define LCDRAM0_FP0BP_MASK              15U
#define LCDRAM0_FP0BP_BITNUM            0U
#define LCDRAM0_FP1BP_MASK              240U
#define LCDRAM0_FP1BP_BITNUM            4U


/*** LCDRAM1 - LCD RAM 1; 0x00000209 ***/
typedef union {
  byte Byte;
  struct {
    byte FP2BP0      :1;                                       /* LCD Segment FP2, BP0 ON */
    byte FP2BP1      :1;                                       /* LCD Segment FP2, BP1 ON */
    byte FP2BP2      :1;                                       /* LCD Segment FP2, BP2 ON */
    byte FP2BP3      :1;                                       /* LCD Segment FP2, BP3 ON */
    byte FP3BP0      :1;                                       /* LCD Segment FP3, BP0 ON */
    byte FP3BP1      :1;                                       /* LCD Segment FP3, BP1 ON */
    byte FP3BP2      :1;                                       /* LCD Segment FP3, BP2 ON */
    byte FP3BP3      :1;                                       /* LCD Segment FP3, BP3 ON */
  } Bits;
  struct {
    byte grpFP2BP :4;
    byte grpFP3BP :4;
  } MergedBits;
} LCDRAM1STR;
extern volatile LCDRAM1STR _LCDRAM1 @(REG_BASE + 0x00000209UL);
#define LCDRAM1                         _LCDRAM1.Byte
#define LCDRAM1_FP2BP0                  _LCDRAM1.Bits.FP2BP0
#define LCDRAM1_FP2BP1                  _LCDRAM1.Bits.FP2BP1
#define LCDRAM1_FP2BP2                  _LCDRAM1.Bits.FP2BP2
#define LCDRAM1_FP2BP3                  _LCDRAM1.Bits.FP2BP3
#define LCDRAM1_FP3BP0                  _LCDRAM1.Bits.FP3BP0
#define LCDRAM1_FP3BP1                  _LCDRAM1.Bits.FP3BP1
#define LCDRAM1_FP3BP2                  _LCDRAM1.Bits.FP3BP2
#define LCDRAM1_FP3BP3                  _LCDRAM1.Bits.FP3BP3
#define LCDRAM1_FP2BP                   _LCDRAM1.MergedBits.grpFP2BP
#define LCDRAM1_FP3BP                   _LCDRAM1.MergedBits.grpFP3BP

#define LCDRAM1_FP2BP0_MASK             1U
#define LCDRAM1_FP2BP1_MASK             2U
#define LCDRAM1_FP2BP2_MASK             4U
#define LCDRAM1_FP2BP3_MASK             8U
#define LCDRAM1_FP3BP0_MASK             16U
#define LCDRAM1_FP3BP1_MASK             32U
#define LCDRAM1_FP3BP2_MASK             64U
#define LCDRAM1_FP3BP3_MASK             128U
#define LCDRAM1_FP2BP_MASK              15U
#define LCDRAM1_FP2BP_BITNUM            0U
#define LCDRAM1_FP3BP_MASK              240U
#define LCDRAM1_FP3BP_BITNUM            4U


/*** LCDRAM2 - LCD RAM 2; 0x0000020A ***/
typedef union {
  byte Byte;
  struct {
    byte FP4BP0      :1;                                       /* LCD Segment FP4, BP0 ON */
    byte FP4BP1      :1;                                       /* LCD Segment FP4, BP1 ON */
    byte FP4BP2      :1;                                       /* LCD Segment FP4, BP2 ON */
    byte FP4BP3      :1;                                       /* LCD Segment FP4, BP3 ON */
    byte FP5BP0      :1;                                       /* LCD Segment FP5, BP0 ON */
    byte FP5BP1      :1;                                       /* LCD Segment FP5, BP1 ON */
    byte FP5BP2      :1;                                       /* LCD Segment FP5, BP2 ON */
    byte FP5BP3      :1;                                       /* LCD Segment FP5, BP3 ON */
  } Bits;
  struct {
    byte grpFP4BP :4;
    byte grpFP5BP :4;
  } MergedBits;
} LCDRAM2STR;
extern volatile LCDRAM2STR _LCDRAM2 @(REG_BASE + 0x0000020AUL);
#define LCDRAM2                         _LCDRAM2.Byte
#define LCDRAM2_FP4BP0                  _LCDRAM2.Bits.FP4BP0
#define LCDRAM2_FP4BP1                  _LCDRAM2.Bits.FP4BP1
#define LCDRAM2_FP4BP2                  _LCDRAM2.Bits.FP4BP2
#define LCDRAM2_FP4BP3                  _LCDRAM2.Bits.FP4BP3
#define LCDRAM2_FP5BP0                  _LCDRAM2.Bits.FP5BP0
#define LCDRAM2_FP5BP1                  _LCDRAM2.Bits.FP5BP1
#define LCDRAM2_FP5BP2                  _LCDRAM2.Bits.FP5BP2
#define LCDRAM2_FP5BP3                  _LCDRAM2.Bits.FP5BP3
#define LCDRAM2_FP4BP                   _LCDRAM2.MergedBits.grpFP4BP
#define LCDRAM2_FP5BP                   _LCDRAM2.MergedBits.grpFP5BP

#define LCDRAM2_FP4BP0_MASK             1U
#define LCDRAM2_FP4BP1_MASK             2U
#define LCDRAM2_FP4BP2_MASK             4U
#define LCDRAM2_FP4BP3_MASK             8U
#define LCDRAM2_FP5BP0_MASK             16U
#define LCDRAM2_FP5BP1_MASK             32U
#define LCDRAM2_FP5BP2_MASK             64U
#define LCDRAM2_FP5BP3_MASK             128U
#define LCDRAM2_FP4BP_MASK              15U
#define LCDRAM2_FP4BP_BITNUM            0U
#define LCDRAM2_FP5BP_MASK              240U
#define LCDRAM2_FP5BP_BITNUM            4U


/*** LCDRAM3 - LCD RAM 3; 0x0000020B ***/
typedef union {
  byte Byte;
  struct {
    byte FP6BP0      :1;                                       /* LCD Segment FP6, BP0 ON */
    byte FP6BP1      :1;                                       /* LCD Segment FP6, BP1 ON */
    byte FP6BP2      :1;                                       /* LCD Segment FP6, BP2 ON */
    byte FP6BP3      :1;                                       /* LCD Segment FP6, BP3 ON */
    byte FP7BP0      :1;                                       /* LCD Segment FP7, BP0 ON */
    byte FP7BP1      :1;                                       /* LCD Segment FP7, BP1 ON */
    byte FP7BP2      :1;                                       /* LCD Segment FP7, BP2 ON */
    byte FP7BP3      :1;                                       /* LCD Segment FP7, BP3 ON */
  } Bits;
  struct {
    byte grpFP6BP :4;
    byte grpFP7BP :4;
  } MergedBits;
} LCDRAM3STR;
extern volatile LCDRAM3STR _LCDRAM3 @(REG_BASE + 0x0000020BUL);
#define LCDRAM3                         _LCDRAM3.Byte
#define LCDRAM3_FP6BP0                  _LCDRAM3.Bits.FP6BP0
#define LCDRAM3_FP6BP1                  _LCDRAM3.Bits.FP6BP1
#define LCDRAM3_FP6BP2                  _LCDRAM3.Bits.FP6BP2
#define LCDRAM3_FP6BP3                  _LCDRAM3.Bits.FP6BP3
#define LCDRAM3_FP7BP0                  _LCDRAM3.Bits.FP7BP0
#define LCDRAM3_FP7BP1                  _LCDRAM3.Bits.FP7BP1
#define LCDRAM3_FP7BP2                  _LCDRAM3.Bits.FP7BP2
#define LCDRAM3_FP7BP3                  _LCDRAM3.Bits.FP7BP3
#define LCDRAM3_FP6BP                   _LCDRAM3.MergedBits.grpFP6BP
#define LCDRAM3_FP7BP                   _LCDRAM3.MergedBits.grpFP7BP

#define LCDRAM3_FP6BP0_MASK             1U
#define LCDRAM3_FP6BP1_MASK             2U
#define LCDRAM3_FP6BP2_MASK             4U
#define LCDRAM3_FP6BP3_MASK             8U
#define LCDRAM3_FP7BP0_MASK             16U
#define LCDRAM3_FP7BP1_MASK             32U
#define LCDRAM3_FP7BP2_MASK             64U
#define LCDRAM3_FP7BP3_MASK             128U
#define LCDRAM3_FP6BP_MASK              15U
#define LCDRAM3_FP6BP_BITNUM            0U
#define LCDRAM3_FP7BP_MASK              240U
#define LCDRAM3_FP7BP_BITNUM            4U


/*** LCDRAM4 - LCD RAM 4; 0x0000020C ***/
typedef union {
  byte Byte;
  struct {
    byte FP8BP0      :1;                                       /* LCD Segment FP8, BP0 ON */
    byte FP8BP1      :1;                                       /* LCD Segment FP8, BP1 ON */
    byte FP8BP2      :1;                                       /* LCD Segment FP8, BP2 ON */
    byte FP8BP3      :1;                                       /* LCD Segment FP8, BP3 ON */
    byte FP9BP0      :1;                                       /* LCD Segment FP9, BP0 ON */
    byte FP9BP1      :1;                                       /* LCD Segment FP9, BP1 ON */
    byte FP9BP2      :1;                                       /* LCD Segment FP9, BP2 ON */
    byte FP9BP3      :1;                                       /* LCD Segment FP9, BP3 ON */
  } Bits;
  struct {
    byte grpFP8BP :4;
    byte grpFP9BP :4;
  } MergedBits;
} LCDRAM4STR;
extern volatile LCDRAM4STR _LCDRAM4 @(REG_BASE + 0x0000020CUL);
#define LCDRAM4                         _LCDRAM4.Byte
#define LCDRAM4_FP8BP0                  _LCDRAM4.Bits.FP8BP0
#define LCDRAM4_FP8BP1                  _LCDRAM4.Bits.FP8BP1
#define LCDRAM4_FP8BP2                  _LCDRAM4.Bits.FP8BP2
#define LCDRAM4_FP8BP3                  _LCDRAM4.Bits.FP8BP3
#define LCDRAM4_FP9BP0                  _LCDRAM4.Bits.FP9BP0
#define LCDRAM4_FP9BP1                  _LCDRAM4.Bits.FP9BP1
#define LCDRAM4_FP9BP2                  _LCDRAM4.Bits.FP9BP2
#define LCDRAM4_FP9BP3                  _LCDRAM4.Bits.FP9BP3
#define LCDRAM4_FP8BP                   _LCDRAM4.MergedBits.grpFP8BP
#define LCDRAM4_FP9BP                   _LCDRAM4.MergedBits.grpFP9BP

#define LCDRAM4_FP8BP0_MASK             1U
#define LCDRAM4_FP8BP1_MASK             2U
#define LCDRAM4_FP8BP2_MASK             4U
#define LCDRAM4_FP8BP3_MASK             8U
#define LCDRAM4_FP9BP0_MASK             16U
#define LCDRAM4_FP9BP1_MASK             32U
#define LCDRAM4_FP9BP2_MASK             64U
#define LCDRAM4_FP9BP3_MASK             128U
#define LCDRAM4_FP8BP_MASK              15U
#define LCDRAM4_FP8BP_BITNUM            0U
#define LCDRAM4_FP9BP_MASK              240U
#define LCDRAM4_FP9BP_BITNUM            4U


/*** LCDRAM5 - LCD RAM 5; 0x0000020D ***/
typedef union {
  byte Byte;
  struct {
    byte FP10BP0     :1;                                       /* LCD Segment FP10, BP0 ON */
    byte FP10BP1     :1;                                       /* LCD Segment FP10, BP1 ON */
    byte FP10BP2     :1;                                       /* LCD Segment FP10, BP2 ON */
    byte FP10BP3     :1;                                       /* LCD Segment FP10, BP3 ON */
    byte FP11BP0     :1;                                       /* LCD Segment FP11, BP0 ON */
    byte FP11BP1     :1;                                       /* LCD Segment FP11, BP1 ON */
    byte FP11BP2     :1;                                       /* LCD Segment FP11, BP2 ON */
    byte FP11BP3     :1;                                       /* LCD Segment FP11, BP3 ON */
  } Bits;
  struct {
    byte grpFP10BP :4;
    byte grpFP11BP :4;
  } MergedBits;
} LCDRAM5STR;
extern volatile LCDRAM5STR _LCDRAM5 @(REG_BASE + 0x0000020DUL);
#define LCDRAM5                         _LCDRAM5.Byte
#define LCDRAM5_FP10BP0                 _LCDRAM5.Bits.FP10BP0
#define LCDRAM5_FP10BP1                 _LCDRAM5.Bits.FP10BP1
#define LCDRAM5_FP10BP2                 _LCDRAM5.Bits.FP10BP2
#define LCDRAM5_FP10BP3                 _LCDRAM5.Bits.FP10BP3
#define LCDRAM5_FP11BP0                 _LCDRAM5.Bits.FP11BP0
#define LCDRAM5_FP11BP1                 _LCDRAM5.Bits.FP11BP1
#define LCDRAM5_FP11BP2                 _LCDRAM5.Bits.FP11BP2
#define LCDRAM5_FP11BP3                 _LCDRAM5.Bits.FP11BP3
#define LCDRAM5_FP10BP                  _LCDRAM5.MergedBits.grpFP10BP
#define LCDRAM5_FP11BP                  _LCDRAM5.MergedBits.grpFP11BP

#define LCDRAM5_FP10BP0_MASK            1U
#define LCDRAM5_FP10BP1_MASK            2U
#define LCDRAM5_FP10BP2_MASK            4U
#define LCDRAM5_FP10BP3_MASK            8U
#define LCDRAM5_FP11BP0_MASK            16U
#define LCDRAM5_FP11BP1_MASK            32U
#define LCDRAM5_FP11BP2_MASK            64U
#define LCDRAM5_FP11BP3_MASK            128U
#define LCDRAM5_FP10BP_MASK             15U
#define LCDRAM5_FP10BP_BITNUM           0U
#define LCDRAM5_FP11BP_MASK             240U
#define LCDRAM5_FP11BP_BITNUM           4U


/*** LCDRAM6 - LCD RAM 6; 0x0000020E ***/
typedef union {
  byte Byte;
  struct {
    byte FP12BP0     :1;                                       /* LCD Segment FP12, BP0 ON */
    byte FP12BP1     :1;                                       /* LCD Segment FP12, BP1 ON */
    byte FP12BP2     :1;                                       /* LCD Segment FP12, BP2 ON */
    byte FP12BP3     :1;                                       /* LCD Segment FP12, BP3 ON */
    byte FP13BP0     :1;                                       /* LCD Segment FP13, BP0 ON */
    byte FP13BP1     :1;                                       /* LCD Segment FP13, BP1 ON */
    byte FP13BP2     :1;                                       /* LCD Segment FP13, BP2 ON */
    byte FP13BP3     :1;                                       /* LCD Segment FP13, BP3 ON */
  } Bits;
  struct {
    byte grpFP12BP :4;
    byte grpFP13BP :4;
  } MergedBits;
} LCDRAM6STR;
extern volatile LCDRAM6STR _LCDRAM6 @(REG_BASE + 0x0000020EUL);
#define LCDRAM6                         _LCDRAM6.Byte
#define LCDRAM6_FP12BP0                 _LCDRAM6.Bits.FP12BP0
#define LCDRAM6_FP12BP1                 _LCDRAM6.Bits.FP12BP1
#define LCDRAM6_FP12BP2                 _LCDRAM6.Bits.FP12BP2
#define LCDRAM6_FP12BP3                 _LCDRAM6.Bits.FP12BP3
#define LCDRAM6_FP13BP0                 _LCDRAM6.Bits.FP13BP0
#define LCDRAM6_FP13BP1                 _LCDRAM6.Bits.FP13BP1
#define LCDRAM6_FP13BP2                 _LCDRAM6.Bits.FP13BP2
#define LCDRAM6_FP13BP3                 _LCDRAM6.Bits.FP13BP3
#define LCDRAM6_FP12BP                  _LCDRAM6.MergedBits.grpFP12BP
#define LCDRAM6_FP13BP                  _LCDRAM6.MergedBits.grpFP13BP

#define LCDRAM6_FP12BP0_MASK            1U
#define LCDRAM6_FP12BP1_MASK            2U
#define LCDRAM6_FP12BP2_MASK            4U
#define LCDRAM6_FP12BP3_MASK            8U
#define LCDRAM6_FP13BP0_MASK            16U
#define LCDRAM6_FP13BP1_MASK            32U
#define LCDRAM6_FP13BP2_MASK            64U
#define LCDRAM6_FP13BP3_MASK            128U
#define LCDRAM6_FP12BP_MASK             15U
#define LCDRAM6_FP12BP_BITNUM           0U
#define LCDRAM6_FP13BP_MASK             240U
#define LCDRAM6_FP13BP_BITNUM           4U


/*** LCDRAM7 - LCD RAM 7; 0x0000020F ***/
typedef union {
  byte Byte;
  struct {
    byte FP14BP0     :1;                                       /* LCD Segment FP14, BP0 ON */
    byte FP14BP1     :1;                                       /* LCD Segment FP14, BP1 ON */
    byte FP14BP2     :1;                                       /* LCD Segment FP14, BP2 ON */
    byte FP14BP3     :1;                                       /* LCD Segment FP14, BP3 ON */
    byte FP15BP0     :1;                                       /* LCD Segment FP15, BP0 ON */
    byte FP15BP1     :1;                                       /* LCD Segment FP15, BP1 ON */
    byte FP15BP2     :1;                                       /* LCD Segment FP15, BP2 ON */
    byte FP15BP3     :1;                                       /* LCD Segment FP15, BP3 ON */
  } Bits;
  struct {
    byte grpFP14BP :4;
    byte grpFP15BP :4;
  } MergedBits;
} LCDRAM7STR;
extern volatile LCDRAM7STR _LCDRAM7 @(REG_BASE + 0x0000020FUL);
#define LCDRAM7                         _LCDRAM7.Byte
#define LCDRAM7_FP14BP0                 _LCDRAM7.Bits.FP14BP0
#define LCDRAM7_FP14BP1                 _LCDRAM7.Bits.FP14BP1
#define LCDRAM7_FP14BP2                 _LCDRAM7.Bits.FP14BP2
#define LCDRAM7_FP14BP3                 _LCDRAM7.Bits.FP14BP3
#define LCDRAM7_FP15BP0                 _LCDRAM7.Bits.FP15BP0
#define LCDRAM7_FP15BP1                 _LCDRAM7.Bits.FP15BP1
#define LCDRAM7_FP15BP2                 _LCDRAM7.Bits.FP15BP2
#define LCDRAM7_FP15BP3                 _LCDRAM7.Bits.FP15BP3
#define LCDRAM7_FP14BP                  _LCDRAM7.MergedBits.grpFP14BP
#define LCDRAM7_FP15BP                  _LCDRAM7.MergedBits.grpFP15BP

#define LCDRAM7_FP14BP0_MASK            1U
#define LCDRAM7_FP14BP1_MASK            2U
#define LCDRAM7_FP14BP2_MASK            4U
#define LCDRAM7_FP14BP3_MASK            8U
#define LCDRAM7_FP15BP0_MASK            16U
#define LCDRAM7_FP15BP1_MASK            32U
#define LCDRAM7_FP15BP2_MASK            64U
#define LCDRAM7_FP15BP3_MASK            128U
#define LCDRAM7_FP14BP_MASK             15U
#define LCDRAM7_FP14BP_BITNUM           0U
#define LCDRAM7_FP15BP_MASK             240U
#define LCDRAM7_FP15BP_BITNUM           4U


/*** LCDRAM8 - LCD RAM 8; 0x00000210 ***/
typedef union {
  byte Byte;
  struct {
    byte FP16BP0     :1;                                       /* LCD Segment FP16, BP0 ON */
    byte FP16BP1     :1;                                       /* LCD Segment FP16, BP1 ON */
    byte FP16BP2     :1;                                       /* LCD Segment FP16, BP2 ON */
    byte FP16BP3     :1;                                       /* LCD Segment FP16, BP3 ON */
    byte FP17BP0     :1;                                       /* LCD Segment FP17, BP0 ON */
    byte FP17BP1     :1;                                       /* LCD Segment FP17, BP1 ON */
    byte FP17BP2     :1;                                       /* LCD Segment FP17, BP2 ON */
    byte FP17BP3     :1;                                       /* LCD Segment FP17, BP3 ON */
  } Bits;
  struct {
    byte grpFP16BP :4;
    byte grpFP17BP :4;
  } MergedBits;
} LCDRAM8STR;
extern volatile LCDRAM8STR _LCDRAM8 @(REG_BASE + 0x00000210UL);
#define LCDRAM8                         _LCDRAM8.Byte
#define LCDRAM8_FP16BP0                 _LCDRAM8.Bits.FP16BP0
#define LCDRAM8_FP16BP1                 _LCDRAM8.Bits.FP16BP1
#define LCDRAM8_FP16BP2                 _LCDRAM8.Bits.FP16BP2
#define LCDRAM8_FP16BP3                 _LCDRAM8.Bits.FP16BP3
#define LCDRAM8_FP17BP0                 _LCDRAM8.Bits.FP17BP0
#define LCDRAM8_FP17BP1                 _LCDRAM8.Bits.FP17BP1
#define LCDRAM8_FP17BP2                 _LCDRAM8.Bits.FP17BP2
#define LCDRAM8_FP17BP3                 _LCDRAM8.Bits.FP17BP3
#define LCDRAM8_FP16BP                  _LCDRAM8.MergedBits.grpFP16BP
#define LCDRAM8_FP17BP                  _LCDRAM8.MergedBits.grpFP17BP

#define LCDRAM8_FP16BP0_MASK            1U
#define LCDRAM8_FP16BP1_MASK            2U
#define LCDRAM8_FP16BP2_MASK            4U
#define LCDRAM8_FP16BP3_MASK            8U
#define LCDRAM8_FP17BP0_MASK            16U
#define LCDRAM8_FP17BP1_MASK            32U
#define LCDRAM8_FP17BP2_MASK            64U
#define LCDRAM8_FP17BP3_MASK            128U
#define LCDRAM8_FP16BP_MASK             15U
#define LCDRAM8_FP16BP_BITNUM           0U
#define LCDRAM8_FP17BP_MASK             240U
#define LCDRAM8_FP17BP_BITNUM           4U


/*** LCDRAM9 - LCD RAM 9; 0x00000211 ***/
typedef union {
  byte Byte;
  struct {
    byte FP18BP0     :1;                                       /* LCD Segment FP18, BP0 ON */
    byte FP18BP1     :1;                                       /* LCD Segment FP18, BP1 ON */
    byte FP18BP2     :1;                                       /* LCD Segment FP18, BP2 ON */
    byte FP18BP3     :1;                                       /* LCD Segment FP18, BP3 ON */
    byte FP19BP0     :1;                                       /* LCD Segment FP19, BP0 ON */
    byte FP19BP1     :1;                                       /* LCD Segment FP19, BP1 ON */
    byte FP19BP2     :1;                                       /* LCD Segment FP19, BP2 ON */
    byte FP19BP3     :1;                                       /* LCD Segment FP19, BP3 ON */
  } Bits;
  struct {
    byte grpFP18BP :4;
    byte grpFP19BP :4;
  } MergedBits;
} LCDRAM9STR;
extern volatile LCDRAM9STR _LCDRAM9 @(REG_BASE + 0x00000211UL);
#define LCDRAM9                         _LCDRAM9.Byte
#define LCDRAM9_FP18BP0                 _LCDRAM9.Bits.FP18BP0
#define LCDRAM9_FP18BP1                 _LCDRAM9.Bits.FP18BP1
#define LCDRAM9_FP18BP2                 _LCDRAM9.Bits.FP18BP2
#define LCDRAM9_FP18BP3                 _LCDRAM9.Bits.FP18BP3
#define LCDRAM9_FP19BP0                 _LCDRAM9.Bits.FP19BP0
#define LCDRAM9_FP19BP1                 _LCDRAM9.Bits.FP19BP1
#define LCDRAM9_FP19BP2                 _LCDRAM9.Bits.FP19BP2
#define LCDRAM9_FP19BP3                 _LCDRAM9.Bits.FP19BP3
#define LCDRAM9_FP18BP                  _LCDRAM9.MergedBits.grpFP18BP
#define LCDRAM9_FP19BP                  _LCDRAM9.MergedBits.grpFP19BP

#define LCDRAM9_FP18BP0_MASK            1U
#define LCDRAM9_FP18BP1_MASK            2U
#define LCDRAM9_FP18BP2_MASK            4U
#define LCDRAM9_FP18BP3_MASK            8U
#define LCDRAM9_FP19BP0_MASK            16U
#define LCDRAM9_FP19BP1_MASK            32U
#define LCDRAM9_FP19BP2_MASK            64U
#define LCDRAM9_FP19BP3_MASK            128U
#define LCDRAM9_FP18BP_MASK             15U
#define LCDRAM9_FP18BP_BITNUM           0U
#define LCDRAM9_FP19BP_MASK             240U
#define LCDRAM9_FP19BP_BITNUM           4U


/*** LCDRAM10 - LCD RAM 10; 0x00000212 ***/
typedef union {
  byte Byte;
  struct {
    byte FP20BP0     :1;                                       /* LCD Segment FP20, BP0 ON */
    byte FP20BP1     :1;                                       /* LCD Segment FP20, BP1 ON */
    byte FP20BP2     :1;                                       /* LCD Segment FP20, BP2 ON */
    byte FP20BP3     :1;                                       /* LCD Segment FP20, BP3 ON */
    byte FP21BP0     :1;                                       /* LCD Segment FP21, BP0 ON */
    byte FP21BP1     :1;                                       /* LCD Segment FP21, BP1 ON */
    byte FP21BP2     :1;                                       /* LCD Segment FP21, BP2 ON */
    byte FP21BP3     :1;                                       /* LCD Segment FP21, BP3 ON */
  } Bits;
  struct {
    byte grpFP20BP :4;
    byte grpFP21BP :4;
  } MergedBits;
} LCDRAM10STR;
extern volatile LCDRAM10STR _LCDRAM10 @(REG_BASE + 0x00000212UL);
#define LCDRAM10                        _LCDRAM10.Byte
#define LCDRAM10_FP20BP0                _LCDRAM10.Bits.FP20BP0
#define LCDRAM10_FP20BP1                _LCDRAM10.Bits.FP20BP1
#define LCDRAM10_FP20BP2                _LCDRAM10.Bits.FP20BP2
#define LCDRAM10_FP20BP3                _LCDRAM10.Bits.FP20BP3
#define LCDRAM10_FP21BP0                _LCDRAM10.Bits.FP21BP0
#define LCDRAM10_FP21BP1                _LCDRAM10.Bits.FP21BP1
#define LCDRAM10_FP21BP2                _LCDRAM10.Bits.FP21BP2
#define LCDRAM10_FP21BP3                _LCDRAM10.Bits.FP21BP3
#define LCDRAM10_FP20BP                 _LCDRAM10.MergedBits.grpFP20BP
#define LCDRAM10_FP21BP                 _LCDRAM10.MergedBits.grpFP21BP

#define LCDRAM10_FP20BP0_MASK           1U
#define LCDRAM10_FP20BP1_MASK           2U
#define LCDRAM10_FP20BP2_MASK           4U
#define LCDRAM10_FP20BP3_MASK           8U
#define LCDRAM10_FP21BP0_MASK           16U
#define LCDRAM10_FP21BP1_MASK           32U
#define LCDRAM10_FP21BP2_MASK           64U
#define LCDRAM10_FP21BP3_MASK           128U
#define LCDRAM10_FP20BP_MASK            15U
#define LCDRAM10_FP20BP_BITNUM          0U
#define LCDRAM10_FP21BP_MASK            240U
#define LCDRAM10_FP21BP_BITNUM          4U


/*** LCDRAM11 - LCD RAM 11; 0x00000213 ***/
typedef union {
  byte Byte;
  struct {
    byte FP22BP0     :1;                                       /* LCD Segment FP22, BP0 ON */
    byte FP22BP1     :1;                                       /* LCD Segment FP22, BP1 ON */
    byte FP22BP2     :1;                                       /* LCD Segment FP22, BP2 ON */
    byte FP22BP3     :1;                                       /* LCD Segment FP22, BP3 ON */
    byte FP23BP0     :1;                                       /* LCD Segment FP23, BP0 ON */
    byte FP23BP1     :1;                                       /* LCD Segment FP23, BP1 ON */
    byte FP23BP2     :1;                                       /* LCD Segment FP23, BP2 ON */
    byte FP23BP3     :1;                                       /* LCD Segment FP23, BP3 ON */
  } Bits;
  struct {
    byte grpFP22BP :4;
    byte grpFP23BP :4;
  } MergedBits;
} LCDRAM11STR;
extern volatile LCDRAM11STR _LCDRAM11 @(REG_BASE + 0x00000213UL);
#define LCDRAM11                        _LCDRAM11.Byte
#define LCDRAM11_FP22BP0                _LCDRAM11.Bits.FP22BP0
#define LCDRAM11_FP22BP1                _LCDRAM11.Bits.FP22BP1
#define LCDRAM11_FP22BP2                _LCDRAM11.Bits.FP22BP2
#define LCDRAM11_FP22BP3                _LCDRAM11.Bits.FP22BP3
#define LCDRAM11_FP23BP0                _LCDRAM11.Bits.FP23BP0
#define LCDRAM11_FP23BP1                _LCDRAM11.Bits.FP23BP1
#define LCDRAM11_FP23BP2                _LCDRAM11.Bits.FP23BP2
#define LCDRAM11_FP23BP3                _LCDRAM11.Bits.FP23BP3
#define LCDRAM11_FP22BP                 _LCDRAM11.MergedBits.grpFP22BP
#define LCDRAM11_FP23BP                 _LCDRAM11.MergedBits.grpFP23BP

#define LCDRAM11_FP22BP0_MASK           1U
#define LCDRAM11_FP22BP1_MASK           2U
#define LCDRAM11_FP22BP2_MASK           4U
#define LCDRAM11_FP22BP3_MASK           8U
#define LCDRAM11_FP23BP0_MASK           16U
#define LCDRAM11_FP23BP1_MASK           32U
#define LCDRAM11_FP23BP2_MASK           64U
#define LCDRAM11_FP23BP3_MASK           128U
#define LCDRAM11_FP22BP_MASK            15U
#define LCDRAM11_FP22BP_BITNUM          0U
#define LCDRAM11_FP23BP_MASK            240U
#define LCDRAM11_FP23BP_BITNUM          4U


/*** LCDRAM12 - LCD RAM 12; 0x00000214 ***/
typedef union {
  byte Byte;
  struct {
    byte FP24BP0     :1;                                       /* LCD Segment FP24, BP0 ON */
    byte FP24BP1     :1;                                       /* LCD Segment FP24, BP1 ON */
    byte FP24BP2     :1;                                       /* LCD Segment FP24, BP2 ON */
    byte FP24BP3     :1;                                       /* LCD Segment FP24, BP3 ON */
    byte FP25BP0     :1;                                       /* LCD Segment FP25, BP0 ON */
    byte FP25BP1     :1;                                       /* LCD Segment FP25, BP1 ON */
    byte FP25BP2     :1;                                       /* LCD Segment FP25, BP2 ON */
    byte FP25BP3     :1;                                       /* LCD Segment FP25, BP3 ON */
  } Bits;
  struct {
    byte grpFP24BP :4;
    byte grpFP25BP :4;
  } MergedBits;
} LCDRAM12STR;
extern volatile LCDRAM12STR _LCDRAM12 @(REG_BASE + 0x00000214UL);
#define LCDRAM12                        _LCDRAM12.Byte
#define LCDRAM12_FP24BP0                _LCDRAM12.Bits.FP24BP0
#define LCDRAM12_FP24BP1                _LCDRAM12.Bits.FP24BP1
#define LCDRAM12_FP24BP2                _LCDRAM12.Bits.FP24BP2
#define LCDRAM12_FP24BP3                _LCDRAM12.Bits.FP24BP3
#define LCDRAM12_FP25BP0                _LCDRAM12.Bits.FP25BP0
#define LCDRAM12_FP25BP1                _LCDRAM12.Bits.FP25BP1
#define LCDRAM12_FP25BP2                _LCDRAM12.Bits.FP25BP2
#define LCDRAM12_FP25BP3                _LCDRAM12.Bits.FP25BP3
#define LCDRAM12_FP24BP                 _LCDRAM12.MergedBits.grpFP24BP
#define LCDRAM12_FP25BP                 _LCDRAM12.MergedBits.grpFP25BP

#define LCDRAM12_FP24BP0_MASK           1U
#define LCDRAM12_FP24BP1_MASK           2U
#define LCDRAM12_FP24BP2_MASK           4U
#define LCDRAM12_FP24BP3_MASK           8U
#define LCDRAM12_FP25BP0_MASK           16U
#define LCDRAM12_FP25BP1_MASK           32U
#define LCDRAM12_FP25BP2_MASK           64U
#define LCDRAM12_FP25BP3_MASK           128U
#define LCDRAM12_FP24BP_MASK            15U
#define LCDRAM12_FP24BP_BITNUM          0U
#define LCDRAM12_FP25BP_MASK            240U
#define LCDRAM12_FP25BP_BITNUM          4U


/*** LCDRAM13 - LCD RAM 13; 0x00000215 ***/
typedef union {
  byte Byte;
  struct {
    byte FP26BP0     :1;                                       /* LCD Segment FP26, BP0 ON */
    byte FP26BP1     :1;                                       /* LCD Segment FP26, BP1 ON */
    byte FP26BP2     :1;                                       /* LCD Segment FP26, BP2 ON */
    byte FP26BP3     :1;                                       /* LCD Segment FP26, BP3 ON */
    byte FP27BP0     :1;                                       /* LCD Segment FP27, BP0 ON */
    byte FP27BP1     :1;                                       /* LCD Segment FP27, BP1 ON */
    byte FP27BP2     :1;                                       /* LCD Segment FP27, BP2 ON */
    byte FP27BP3     :1;                                       /* LCD Segment FP27, BP3 ON */
  } Bits;
  struct {
    byte grpFP26BP :4;
    byte grpFP27BP :4;
  } MergedBits;
} LCDRAM13STR;
extern volatile LCDRAM13STR _LCDRAM13 @(REG_BASE + 0x00000215UL);
#define LCDRAM13                        _LCDRAM13.Byte
#define LCDRAM13_FP26BP0                _LCDRAM13.Bits.FP26BP0
#define LCDRAM13_FP26BP1                _LCDRAM13.Bits.FP26BP1
#define LCDRAM13_FP26BP2                _LCDRAM13.Bits.FP26BP2
#define LCDRAM13_FP26BP3                _LCDRAM13.Bits.FP26BP3
#define LCDRAM13_FP27BP0                _LCDRAM13.Bits.FP27BP0
#define LCDRAM13_FP27BP1                _LCDRAM13.Bits.FP27BP1
#define LCDRAM13_FP27BP2                _LCDRAM13.Bits.FP27BP2
#define LCDRAM13_FP27BP3                _LCDRAM13.Bits.FP27BP3
#define LCDRAM13_FP26BP                 _LCDRAM13.MergedBits.grpFP26BP
#define LCDRAM13_FP27BP                 _LCDRAM13.MergedBits.grpFP27BP

#define LCDRAM13_FP26BP0_MASK           1U
#define LCDRAM13_FP26BP1_MASK           2U
#define LCDRAM13_FP26BP2_MASK           4U
#define LCDRAM13_FP26BP3_MASK           8U
#define LCDRAM13_FP27BP0_MASK           16U
#define LCDRAM13_FP27BP1_MASK           32U
#define LCDRAM13_FP27BP2_MASK           64U
#define LCDRAM13_FP27BP3_MASK           128U
#define LCDRAM13_FP26BP_MASK            15U
#define LCDRAM13_FP26BP_BITNUM          0U
#define LCDRAM13_FP27BP_MASK            240U
#define LCDRAM13_FP27BP_BITNUM          4U


/*** LCDRAM14 - LCD RAM 14; 0x00000216 ***/
typedef union {
  byte Byte;
  struct {
    byte FP28BP0     :1;                                       /* LCD Segment FP28, BP0 ON */
    byte FP28BP1     :1;                                       /* LCD Segment FP28, BP1 ON */
    byte FP28BP2     :1;                                       /* LCD Segment FP28, BP2 ON */
    byte FP28BP3     :1;                                       /* LCD Segment FP28, BP3 ON */
    byte FP29BP0     :1;                                       /* LCD Segment FP29, BP0 ON */
    byte FP29BP1     :1;                                       /* LCD Segment FP29, BP1 ON */
    byte FP29BP2     :1;                                       /* LCD Segment FP29, BP2 ON */
    byte FP29BP3     :1;                                       /* LCD Segment FP29, BP3 ON */
  } Bits;
  struct {
    byte grpFP28BP :4;
    byte grpFP29BP :4;
  } MergedBits;
} LCDRAM14STR;
extern volatile LCDRAM14STR _LCDRAM14 @(REG_BASE + 0x00000216UL);
#define LCDRAM14                        _LCDRAM14.Byte
#define LCDRAM14_FP28BP0                _LCDRAM14.Bits.FP28BP0
#define LCDRAM14_FP28BP1                _LCDRAM14.Bits.FP28BP1
#define LCDRAM14_FP28BP2                _LCDRAM14.Bits.FP28BP2
#define LCDRAM14_FP28BP3                _LCDRAM14.Bits.FP28BP3
#define LCDRAM14_FP29BP0                _LCDRAM14.Bits.FP29BP0
#define LCDRAM14_FP29BP1                _LCDRAM14.Bits.FP29BP1
#define LCDRAM14_FP29BP2                _LCDRAM14.Bits.FP29BP2
#define LCDRAM14_FP29BP3                _LCDRAM14.Bits.FP29BP3
#define LCDRAM14_FP28BP                 _LCDRAM14.MergedBits.grpFP28BP
#define LCDRAM14_FP29BP                 _LCDRAM14.MergedBits.grpFP29BP

#define LCDRAM14_FP28BP0_MASK           1U
#define LCDRAM14_FP28BP1_MASK           2U
#define LCDRAM14_FP28BP2_MASK           4U
#define LCDRAM14_FP28BP3_MASK           8U
#define LCDRAM14_FP29BP0_MASK           16U
#define LCDRAM14_FP29BP1_MASK           32U
#define LCDRAM14_FP29BP2_MASK           64U
#define LCDRAM14_FP29BP3_MASK           128U
#define LCDRAM14_FP28BP_MASK            15U
#define LCDRAM14_FP28BP_BITNUM          0U
#define LCDRAM14_FP29BP_MASK            240U
#define LCDRAM14_FP29BP_BITNUM          4U


/*** LCDRAM15 - LCD RAM 15; 0x00000217 ***/
typedef union {
  byte Byte;
  struct {
    byte FP30BP0     :1;                                       /* LCD Segment FP30, BP0 ON */
    byte FP30BP1     :1;                                       /* LCD Segment FP30, BP1 ON */
    byte FP30BP2     :1;                                       /* LCD Segment FP30, BP2 ON */
    byte FP30BP3     :1;                                       /* LCD Segment FP30, BP3 ON */
    byte FP31BP0     :1;                                       /* LCD Segment FP31, BP0 ON */
    byte FP31BP1     :1;                                       /* LCD Segment FP31, BP1 ON */
    byte FP31BP2     :1;                                       /* LCD Segment FP31, BP2 ON */
    byte FP31BP3     :1;                                       /* LCD Segment FP31, BP3 ON */
  } Bits;
  struct {
    byte grpFP30BP :4;
    byte grpFP31BP :4;
  } MergedBits;
} LCDRAM15STR;
extern volatile LCDRAM15STR _LCDRAM15 @(REG_BASE + 0x00000217UL);
#define LCDRAM15                        _LCDRAM15.Byte
#define LCDRAM15_FP30BP0                _LCDRAM15.Bits.FP30BP0
#define LCDRAM15_FP30BP1                _LCDRAM15.Bits.FP30BP1
#define LCDRAM15_FP30BP2                _LCDRAM15.Bits.FP30BP2
#define LCDRAM15_FP30BP3                _LCDRAM15.Bits.FP30BP3
#define LCDRAM15_FP31BP0                _LCDRAM15.Bits.FP31BP0
#define LCDRAM15_FP31BP1                _LCDRAM15.Bits.FP31BP1
#define LCDRAM15_FP31BP2                _LCDRAM15.Bits.FP31BP2
#define LCDRAM15_FP31BP3                _LCDRAM15.Bits.FP31BP3
#define LCDRAM15_FP30BP                 _LCDRAM15.MergedBits.grpFP30BP
#define LCDRAM15_FP31BP                 _LCDRAM15.MergedBits.grpFP31BP

#define LCDRAM15_FP30BP0_MASK           1U
#define LCDRAM15_FP30BP1_MASK           2U
#define LCDRAM15_FP30BP2_MASK           4U
#define LCDRAM15_FP30BP3_MASK           8U
#define LCDRAM15_FP31BP0_MASK           16U
#define LCDRAM15_FP31BP1_MASK           32U
#define LCDRAM15_FP31BP2_MASK           64U
#define LCDRAM15_FP31BP3_MASK           128U
#define LCDRAM15_FP30BP_MASK            15U
#define LCDRAM15_FP30BP_BITNUM          0U
#define LCDRAM15_FP31BP_MASK            240U
#define LCDRAM15_FP31BP_BITNUM          4U


/*** LCDRAM16 - LCD RAM 16; 0x00000218 ***/
typedef union {
  byte Byte;
  struct {
    byte FP32BP0     :1;                                       /* LCD Segment FP32, BP0 ON */
    byte FP32BP1     :1;                                       /* LCD Segment FP32, BP1 ON */
    byte FP32BP2     :1;                                       /* LCD Segment FP32, BP2 ON */
    byte FP32BP3     :1;                                       /* LCD Segment FP32, BP3 ON */
    byte FP33BP0     :1;                                       /* LCD Segment FP33, BP0 ON */
    byte FP33BP1     :1;                                       /* LCD Segment FP33, BP1 ON */
    byte FP33BP2     :1;                                       /* LCD Segment FP33, BP2 ON */
    byte FP33BP3     :1;                                       /* LCD Segment FP33, BP3 ON */
  } Bits;
  struct {
    byte grpFP32BP :4;
    byte grpFP33BP :4;
  } MergedBits;
} LCDRAM16STR;
extern volatile LCDRAM16STR _LCDRAM16 @(REG_BASE + 0x00000218UL);
#define LCDRAM16                        _LCDRAM16.Byte
#define LCDRAM16_FP32BP0                _LCDRAM16.Bits.FP32BP0
#define LCDRAM16_FP32BP1                _LCDRAM16.Bits.FP32BP1
#define LCDRAM16_FP32BP2                _LCDRAM16.Bits.FP32BP2
#define LCDRAM16_FP32BP3                _LCDRAM16.Bits.FP32BP3
#define LCDRAM16_FP33BP0                _LCDRAM16.Bits.FP33BP0
#define LCDRAM16_FP33BP1                _LCDRAM16.Bits.FP33BP1
#define LCDRAM16_FP33BP2                _LCDRAM16.Bits.FP33BP2
#define LCDRAM16_FP33BP3                _LCDRAM16.Bits.FP33BP3
#define LCDRAM16_FP32BP                 _LCDRAM16.MergedBits.grpFP32BP
#define LCDRAM16_FP33BP                 _LCDRAM16.MergedBits.grpFP33BP

#define LCDRAM16_FP32BP0_MASK           1U
#define LCDRAM16_FP32BP1_MASK           2U
#define LCDRAM16_FP32BP2_MASK           4U
#define LCDRAM16_FP32BP3_MASK           8U
#define LCDRAM16_FP33BP0_MASK           16U
#define LCDRAM16_FP33BP1_MASK           32U
#define LCDRAM16_FP33BP2_MASK           64U
#define LCDRAM16_FP33BP3_MASK           128U
#define LCDRAM16_FP32BP_MASK            15U
#define LCDRAM16_FP32BP_BITNUM          0U
#define LCDRAM16_FP33BP_MASK            240U
#define LCDRAM16_FP33BP_BITNUM          4U


/*** LCDRAM17 - LCD RAM 17; 0x00000219 ***/
typedef union {
  byte Byte;
  struct {
    byte FP34BP0     :1;                                       /* LCD Segment FP34, BP0 ON */
    byte FP34BP1     :1;                                       /* LCD Segment FP34, BP1 ON */
    byte FP34BP2     :1;                                       /* LCD Segment FP34, BP2 ON */
    byte FP34BP3     :1;                                       /* LCD Segment FP34, BP3 ON */
    byte FP35BP0     :1;                                       /* LCD Segment FP35, BP0 ON */
    byte FP35BP1     :1;                                       /* LCD Segment FP35, BP1 ON */
    byte FP35BP2     :1;                                       /* LCD Segment FP35, BP2 ON */
    byte FP35BP3     :1;                                       /* LCD Segment FP35, BP3 ON */
  } Bits;
  struct {
    byte grpFP34BP :4;
    byte grpFP35BP :4;
  } MergedBits;
} LCDRAM17STR;
extern volatile LCDRAM17STR _LCDRAM17 @(REG_BASE + 0x00000219UL);
#define LCDRAM17                        _LCDRAM17.Byte
#define LCDRAM17_FP34BP0                _LCDRAM17.Bits.FP34BP0
#define LCDRAM17_FP34BP1                _LCDRAM17.Bits.FP34BP1
#define LCDRAM17_FP34BP2                _LCDRAM17.Bits.FP34BP2
#define LCDRAM17_FP34BP3                _LCDRAM17.Bits.FP34BP3
#define LCDRAM17_FP35BP0                _LCDRAM17.Bits.FP35BP0
#define LCDRAM17_FP35BP1                _LCDRAM17.Bits.FP35BP1
#define LCDRAM17_FP35BP2                _LCDRAM17.Bits.FP35BP2
#define LCDRAM17_FP35BP3                _LCDRAM17.Bits.FP35BP3
#define LCDRAM17_FP34BP                 _LCDRAM17.MergedBits.grpFP34BP
#define LCDRAM17_FP35BP                 _LCDRAM17.MergedBits.grpFP35BP

#define LCDRAM17_FP34BP0_MASK           1U
#define LCDRAM17_FP34BP1_MASK           2U
#define LCDRAM17_FP34BP2_MASK           4U
#define LCDRAM17_FP34BP3_MASK           8U
#define LCDRAM17_FP35BP0_MASK           16U
#define LCDRAM17_FP35BP1_MASK           32U
#define LCDRAM17_FP35BP2_MASK           64U
#define LCDRAM17_FP35BP3_MASK           128U
#define LCDRAM17_FP34BP_MASK            15U
#define LCDRAM17_FP34BP_BITNUM          0U
#define LCDRAM17_FP35BP_MASK            240U
#define LCDRAM17_FP35BP_BITNUM          4U


/*** LCDRAM18 - LCD RAM 18; 0x0000021A ***/
typedef union {
  byte Byte;
  struct {
    byte FP36BP0     :1;                                       /* LCD Segment FP36, BP0 ON */
    byte FP36BP1     :1;                                       /* LCD Segment FP36, BP1 ON */
    byte FP36BP2     :1;                                       /* LCD Segment FP36, BP2 ON */
    byte FP36BP3     :1;                                       /* LCD Segment FP36, BP3 ON */
    byte FP37BP0     :1;                                       /* LCD Segment FP37, BP0 ON */
    byte FP37BP1     :1;                                       /* LCD Segment FP37, BP1 ON */
    byte FP37BP2     :1;                                       /* LCD Segment FP37, BP2 ON */
    byte FP37BP3     :1;                                       /* LCD Segment FP37, BP3 ON */
  } Bits;
  struct {
    byte grpFP36BP :4;
    byte grpFP37BP :4;
  } MergedBits;
} LCDRAM18STR;
extern volatile LCDRAM18STR _LCDRAM18 @(REG_BASE + 0x0000021AUL);
#define LCDRAM18                        _LCDRAM18.Byte
#define LCDRAM18_FP36BP0                _LCDRAM18.Bits.FP36BP0
#define LCDRAM18_FP36BP1                _LCDRAM18.Bits.FP36BP1
#define LCDRAM18_FP36BP2                _LCDRAM18.Bits.FP36BP2
#define LCDRAM18_FP36BP3                _LCDRAM18.Bits.FP36BP3
#define LCDRAM18_FP37BP0                _LCDRAM18.Bits.FP37BP0
#define LCDRAM18_FP37BP1                _LCDRAM18.Bits.FP37BP1
#define LCDRAM18_FP37BP2                _LCDRAM18.Bits.FP37BP2
#define LCDRAM18_FP37BP3                _LCDRAM18.Bits.FP37BP3
#define LCDRAM18_FP36BP                 _LCDRAM18.MergedBits.grpFP36BP
#define LCDRAM18_FP37BP                 _LCDRAM18.MergedBits.grpFP37BP

#define LCDRAM18_FP36BP0_MASK           1U
#define LCDRAM18_FP36BP1_MASK           2U
#define LCDRAM18_FP36BP2_MASK           4U
#define LCDRAM18_FP36BP3_MASK           8U
#define LCDRAM18_FP37BP0_MASK           16U
#define LCDRAM18_FP37BP1_MASK           32U
#define LCDRAM18_FP37BP2_MASK           64U
#define LCDRAM18_FP37BP3_MASK           128U
#define LCDRAM18_FP36BP_MASK            15U
#define LCDRAM18_FP36BP_BITNUM          0U
#define LCDRAM18_FP37BP_MASK            240U
#define LCDRAM18_FP37BP_BITNUM          4U


/*** LCDRAM19 - LCD RAM 19; 0x0000021B ***/
typedef union {
  byte Byte;
  struct {
    byte FP38BP0     :1;                                       /* LCD Segment FP38, BP0 ON */
    byte FP38BP1     :1;                                       /* LCD Segment FP38, BP1 ON */
    byte FP38BP2     :1;                                       /* LCD Segment FP38, BP2 ON */
    byte FP38BP3     :1;                                       /* LCD Segment FP38, BP3 ON */
    byte FP39BP0     :1;                                       /* LCD Segment FP39, BP0 ON */
    byte FP39BP1     :1;                                       /* LCD Segment FP39, BP1 ON */
    byte FP39BP2     :1;                                       /* LCD Segment FP39, BP2 ON */
    byte FP39BP3     :1;                                       /* LCD Segment FP39, BP3 ON */
  } Bits;
  struct {
    byte grpFP38BP :4;
    byte grpFP39BP :4;
  } MergedBits;
} LCDRAM19STR;
extern volatile LCDRAM19STR _LCDRAM19 @(REG_BASE + 0x0000021BUL);
#define LCDRAM19                        _LCDRAM19.Byte
#define LCDRAM19_FP38BP0                _LCDRAM19.Bits.FP38BP0
#define LCDRAM19_FP38BP1                _LCDRAM19.Bits.FP38BP1
#define LCDRAM19_FP38BP2                _LCDRAM19.Bits.FP38BP2
#define LCDRAM19_FP38BP3                _LCDRAM19.Bits.FP38BP3
#define LCDRAM19_FP39BP0                _LCDRAM19.Bits.FP39BP0
#define LCDRAM19_FP39BP1                _LCDRAM19.Bits.FP39BP1
#define LCDRAM19_FP39BP2                _LCDRAM19.Bits.FP39BP2
#define LCDRAM19_FP39BP3                _LCDRAM19.Bits.FP39BP3
#define LCDRAM19_FP38BP                 _LCDRAM19.MergedBits.grpFP38BP
#define LCDRAM19_FP39BP                 _LCDRAM19.MergedBits.grpFP39BP

#define LCDRAM19_FP38BP0_MASK           1U
#define LCDRAM19_FP38BP1_MASK           2U
#define LCDRAM19_FP38BP2_MASK           4U
#define LCDRAM19_FP38BP3_MASK           8U
#define LCDRAM19_FP39BP0_MASK           16U
#define LCDRAM19_FP39BP1_MASK           32U
#define LCDRAM19_FP39BP2_MASK           64U
#define LCDRAM19_FP39BP3_MASK           128U
#define LCDRAM19_FP38BP_MASK            15U
#define LCDRAM19_FP38BP_BITNUM          0U
#define LCDRAM19_FP39BP_MASK            240U
#define LCDRAM19_FP39BP_BITNUM          4U


/*** PTT - Port T Data Register; 0x00000240 ***/
typedef union {
  byte Byte;
  struct {
    byte PTT0        :1;                                       /* Port T general purpose input/output data bit 0 */
    byte PTT1        :1;                                       /* Port T general purpose input/output data bit 1 */
    byte PTT2        :1;                                       /* Port T general purpose input/output data bit 2 */
    byte PTT3        :1;                                       /* Port T general purpose input/output data bit 3 */
    byte PTT4        :1;                                       /* Port T general purpose input/output data bit 4 */
    byte PTT5        :1;                                       /* Port T general purpose input/output data bit 5 */
    byte PTT6        :1;                                       /* Port T general purpose input/output data bit 6 */
    byte PTT7        :1;                                       /* Port T general purpose input/output data bit 7 */
  } Bits;
} PTTSTR;
extern volatile PTTSTR _PTT @(REG_BASE + 0x00000240UL);
#define PTT                             _PTT.Byte
#define PTT_PTT0                        _PTT.Bits.PTT0
#define PTT_PTT1                        _PTT.Bits.PTT1
#define PTT_PTT2                        _PTT.Bits.PTT2
#define PTT_PTT3                        _PTT.Bits.PTT3
#define PTT_PTT4                        _PTT.Bits.PTT4
#define PTT_PTT5                        _PTT.Bits.PTT5
#define PTT_PTT6                        _PTT.Bits.PTT6
#define PTT_PTT7                        _PTT.Bits.PTT7

#define PTT_PTT0_MASK                   1U
#define PTT_PTT1_MASK                   2U
#define PTT_PTT2_MASK                   4U
#define PTT_PTT3_MASK                   8U
#define PTT_PTT4_MASK                   16U
#define PTT_PTT5_MASK                   32U
#define PTT_PTT6_MASK                   64U
#define PTT_PTT7_MASK                   128U


/*** PTIT - Port T Input Register; 0x00000241 ***/
typedef union {
  byte Byte;
  struct {
    byte PTIT0       :1;                                       /* Port T input data bit 0 */
    byte PTIT1       :1;                                       /* Port T input data bit 1 */
    byte PTIT2       :1;                                       /* Port T input data bit 2 */
    byte PTIT3       :1;                                       /* Port T input data bit 3 */
    byte PTIT4       :1;                                       /* Port T input data bit 4 */
    byte PTIT5       :1;                                       /* Port T input data bit 5 */
    byte PTIT6       :1;                                       /* Port T input data bit 6 */
    byte PTIT7       :1;                                       /* Port T input data bit 7 */
  } Bits;
} PTITSTR;
extern volatile PTITSTR _PTIT @(REG_BASE + 0x00000241UL);
#define PTIT                            _PTIT.Byte
#define PTIT_PTIT0                      _PTIT.Bits.PTIT0
#define PTIT_PTIT1                      _PTIT.Bits.PTIT1
#define PTIT_PTIT2                      _PTIT.Bits.PTIT2
#define PTIT_PTIT3                      _PTIT.Bits.PTIT3
#define PTIT_PTIT4                      _PTIT.Bits.PTIT4
#define PTIT_PTIT5                      _PTIT.Bits.PTIT5
#define PTIT_PTIT6                      _PTIT.Bits.PTIT6
#define PTIT_PTIT7                      _PTIT.Bits.PTIT7

#define PTIT_PTIT0_MASK                 1U
#define PTIT_PTIT1_MASK                 2U
#define PTIT_PTIT2_MASK                 4U
#define PTIT_PTIT3_MASK                 8U
#define PTIT_PTIT4_MASK                 16U
#define PTIT_PTIT5_MASK                 32U
#define PTIT_PTIT6_MASK                 64U
#define PTIT_PTIT7_MASK                 128U


/*** DDRT - Port T Data Direction Register; 0x00000242 ***/
typedef union {
  byte Byte;
  struct {
    byte DDRT0       :1;                                       /* Port T data direction bit 0 */
    byte DDRT1       :1;                                       /* Port T data direction bit 1 */
    byte DDRT2       :1;                                       /* Port T data direction bit 2 */
    byte DDRT3       :1;                                       /* Port T data direction bit 3 */
    byte DDRT4       :1;                                       /* Port T data direction bit 4 */
    byte DDRT5       :1;                                       /* Port T data direction bit 5 */
    byte DDRT6       :1;                                       /* Port T data direction bit 6 */
    byte DDRT7       :1;                                       /* Port T data direction bit 7 */
  } Bits;
} DDRTSTR;
extern volatile DDRTSTR _DDRT @(REG_BASE + 0x00000242UL);
#define DDRT                            _DDRT.Byte
#define DDRT_DDRT0                      _DDRT.Bits.DDRT0
#define DDRT_DDRT1                      _DDRT.Bits.DDRT1
#define DDRT_DDRT2                      _DDRT.Bits.DDRT2
#define DDRT_DDRT3                      _DDRT.Bits.DDRT3
#define DDRT_DDRT4                      _DDRT.Bits.DDRT4
#define DDRT_DDRT5                      _DDRT.Bits.DDRT5
#define DDRT_DDRT6                      _DDRT.Bits.DDRT6
#define DDRT_DDRT7                      _DDRT.Bits.DDRT7

#define DDRT_DDRT0_MASK                 1U
#define DDRT_DDRT1_MASK                 2U
#define DDRT_DDRT2_MASK                 4U
#define DDRT_DDRT3_MASK                 8U
#define DDRT_DDRT4_MASK                 16U
#define DDRT_DDRT5_MASK                 32U
#define DDRT_DDRT6_MASK                 64U
#define DDRT_DDRT7_MASK                 128U


/*** RDRT - Port T Reduced Drive Register; 0x00000243 ***/
typedef union {
  byte Byte;
  struct {
    byte RDRT0       :1;                                       /* Port T reduced drive bit 0 */
    byte RDRT1       :1;                                       /* Port T reduced drive bit 1 */
    byte RDRT2       :1;                                       /* Port T reduced drive bit 2 */
    byte RDRT3       :1;                                       /* Port T reduced drive bit 3 */
    byte RDRT4       :1;                                       /* Port T reduced drive bit 4 */
    byte RDRT5       :1;                                       /* Port T reduced drive bit 5 */
    byte RDRT6       :1;                                       /* Port T reduced drive bit 6 */
    byte RDRT7       :1;                                       /* Port T reduced drive bit 7 */
  } Bits;
} RDRTSTR;
extern volatile RDRTSTR _RDRT @(REG_BASE + 0x00000243UL);
#define RDRT                            _RDRT.Byte
#define RDRT_RDRT0                      _RDRT.Bits.RDRT0
#define RDRT_RDRT1                      _RDRT.Bits.RDRT1
#define RDRT_RDRT2                      _RDRT.Bits.RDRT2
#define RDRT_RDRT3                      _RDRT.Bits.RDRT3
#define RDRT_RDRT4                      _RDRT.Bits.RDRT4
#define RDRT_RDRT5                      _RDRT.Bits.RDRT5
#define RDRT_RDRT6                      _RDRT.Bits.RDRT6
#define RDRT_RDRT7                      _RDRT.Bits.RDRT7

#define RDRT_RDRT0_MASK                 1U
#define RDRT_RDRT1_MASK                 2U
#define RDRT_RDRT2_MASK                 4U
#define RDRT_RDRT3_MASK                 8U
#define RDRT_RDRT4_MASK                 16U
#define RDRT_RDRT5_MASK                 32U
#define RDRT_RDRT6_MASK                 64U
#define RDRT_RDRT7_MASK                 128U


/*** PERT - Port T Pull Device Enable Register; 0x00000244 ***/
typedef union {
  byte Byte;
  struct {
    byte PERT0       :1;                                       /* Port T pull device enable bit 0 */
    byte PERT1       :1;                                       /* Port T pull device enable bit 1 */
    byte PERT2       :1;                                       /* Port T pull device enable bit 2 */
    byte PERT3       :1;                                       /* Port T pull device enable bit 3 */
    byte PERT4       :1;                                       /* Port T pull device enable bit 4 */
    byte PERT5       :1;                                       /* Port T pull device enable bit 5 */
    byte PERT6       :1;                                       /* Port T pull device enable bit 6 */
    byte PERT7       :1;                                       /* Port T pull device enable bit 7 */
  } Bits;
} PERTSTR;
extern volatile PERTSTR _PERT @(REG_BASE + 0x00000244UL);
#define PERT                            _PERT.Byte
#define PERT_PERT0                      _PERT.Bits.PERT0
#define PERT_PERT1                      _PERT.Bits.PERT1
#define PERT_PERT2                      _PERT.Bits.PERT2
#define PERT_PERT3                      _PERT.Bits.PERT3
#define PERT_PERT4                      _PERT.Bits.PERT4
#define PERT_PERT5                      _PERT.Bits.PERT5
#define PERT_PERT6                      _PERT.Bits.PERT6
#define PERT_PERT7                      _PERT.Bits.PERT7

#define PERT_PERT0_MASK                 1U
#define PERT_PERT1_MASK                 2U
#define PERT_PERT2_MASK                 4U
#define PERT_PERT3_MASK                 8U
#define PERT_PERT4_MASK                 16U
#define PERT_PERT5_MASK                 32U
#define PERT_PERT6_MASK                 64U
#define PERT_PERT7_MASK                 128U


/*** PPST - Port T Polarity Select Register; 0x00000245 ***/
typedef union {
  byte Byte;
  struct {
    byte PPST0       :1;                                       /* Port T pull device select bit 0 */
    byte PPST1       :1;                                       /* Port T pull device select bit 1 */
    byte PPST2       :1;                                       /* Port T pull device select bit 2 */
    byte PPST3       :1;                                       /* Port T pull device select bit 3 */
    byte PPST4       :1;                                       /* Port T pull device select bit 4 */
    byte PPST5       :1;                                       /* Port T pull device select bit 5 */
    byte PPST6       :1;                                       /* Port T pull device select bit 6 */
    byte PPST7       :1;                                       /* Port T pull device select bit 7 */
  } Bits;
} PPSTSTR;
extern volatile PPSTSTR _PPST @(REG_BASE + 0x00000245UL);
#define PPST                            _PPST.Byte
#define PPST_PPST0                      _PPST.Bits.PPST0
#define PPST_PPST1                      _PPST.Bits.PPST1
#define PPST_PPST2                      _PPST.Bits.PPST2
#define PPST_PPST3                      _PPST.Bits.PPST3
#define PPST_PPST4                      _PPST.Bits.PPST4
#define PPST_PPST5                      _PPST.Bits.PPST5
#define PPST_PPST6                      _PPST.Bits.PPST6
#define PPST_PPST7                      _PPST.Bits.PPST7

#define PPST_PPST0_MASK                 1U
#define PPST_PPST1_MASK                 2U
#define PPST_PPST2_MASK                 4U
#define PPST_PPST3_MASK                 8U
#define PPST_PPST4_MASK                 16U
#define PPST_PPST5_MASK                 32U
#define PPST_PPST6_MASK                 64U
#define PPST_PPST7_MASK                 128U


/*** PTTRR - Port T Routing Register; 0x00000247 ***/
typedef union {
  byte Byte;
  struct {
    byte PTTRR0      :1;                                       /* Port T  routing */
    byte PTTRR1      :1;                                       /* Port T  routing */
    byte             :1; 
    byte             :1; 
    byte PTTRR4      :1;                                       /* Port T  routing */
    byte PTTRR5      :1;                                       /* Port T  routing */
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPTTRR :2;
    byte         :1;
    byte         :1;
    byte grpPTTRR_4 :2;
    byte         :1;
    byte         :1;
  } MergedBits;
} PTTRRSTR;
extern volatile PTTRRSTR _PTTRR @(REG_BASE + 0x00000247UL);
#define PTTRR                           _PTTRR.Byte
#define PTTRR_PTTRR0                    _PTTRR.Bits.PTTRR0
#define PTTRR_PTTRR1                    _PTTRR.Bits.PTTRR1
#define PTTRR_PTTRR4                    _PTTRR.Bits.PTTRR4
#define PTTRR_PTTRR5                    _PTTRR.Bits.PTTRR5
#define PTTRR_PTTRR                     _PTTRR.MergedBits.grpPTTRR
#define PTTRR_PTTRR_4                   _PTTRR.MergedBits.grpPTTRR_4

#define PTTRR_PTTRR0_MASK               1U
#define PTTRR_PTTRR1_MASK               2U
#define PTTRR_PTTRR4_MASK               16U
#define PTTRR_PTTRR5_MASK               32U
#define PTTRR_PTTRR_MASK                3U
#define PTTRR_PTTRR_BITNUM              0U
#define PTTRR_PTTRR_4_MASK              48U
#define PTTRR_PTTRR_4_BITNUM            4U


/*** PTS - Port S Data Register; 0x00000248 ***/
typedef union {
  byte Byte;
  struct {
    byte PTS0        :1;                                       /* Port S general purpose input/output data bit 0 */
    byte PTS1        :1;                                       /* Port S general purpose input/output data bit 1 */
    byte PTS2        :1;                                       /* Port S general purpose input/output data bit 2 */
    byte PTS3        :1;                                       /* Port S general purpose input/output data bit 3 */
    byte PTS4        :1;                                       /* Port S general purpose input/output data bit 4 */
    byte PTS5        :1;                                       /* Port S general purpose input/output data bit 5 */
    byte PTS6        :1;                                       /* Port S general purpose input/output data bit 6 */
    byte PTS7        :1;                                       /* Port S general purpose input/output data bit 7 */
  } Bits;
} PTSSTR;
extern volatile PTSSTR _PTS @(REG_BASE + 0x00000248UL);
#define PTS                             _PTS.Byte
#define PTS_PTS0                        _PTS.Bits.PTS0
#define PTS_PTS1                        _PTS.Bits.PTS1
#define PTS_PTS2                        _PTS.Bits.PTS2
#define PTS_PTS3                        _PTS.Bits.PTS3
#define PTS_PTS4                        _PTS.Bits.PTS4
#define PTS_PTS5                        _PTS.Bits.PTS5
#define PTS_PTS6                        _PTS.Bits.PTS6
#define PTS_PTS7                        _PTS.Bits.PTS7

#define PTS_PTS0_MASK                   1U
#define PTS_PTS1_MASK                   2U
#define PTS_PTS2_MASK                   4U
#define PTS_PTS3_MASK                   8U
#define PTS_PTS4_MASK                   16U
#define PTS_PTS5_MASK                   32U
#define PTS_PTS6_MASK                   64U
#define PTS_PTS7_MASK                   128U


/*** PTIS - Port S Input Register; 0x00000249 ***/
typedef union {
  byte Byte;
  struct {
    byte PTIS0       :1;                                       /* Port S input data bit 0 */
    byte PTIS1       :1;                                       /* Port S input data bit 1 */
    byte PTIS2       :1;                                       /* Port S input data bit 2 */
    byte PTIS3       :1;                                       /* Port S input data bit 3 */
    byte PTIS4       :1;                                       /* Port S input data bit 4 */
    byte PTIS5       :1;                                       /* Port S input data bit 5 */
    byte PTIS6       :1;                                       /* Port S input data bit 6 */
    byte PTIS7       :1;                                       /* Port S input data bit 7 */
  } Bits;
} PTISSTR;
extern volatile PTISSTR _PTIS @(REG_BASE + 0x00000249UL);
#define PTIS                            _PTIS.Byte
#define PTIS_PTIS0                      _PTIS.Bits.PTIS0
#define PTIS_PTIS1                      _PTIS.Bits.PTIS1
#define PTIS_PTIS2                      _PTIS.Bits.PTIS2
#define PTIS_PTIS3                      _PTIS.Bits.PTIS3
#define PTIS_PTIS4                      _PTIS.Bits.PTIS4
#define PTIS_PTIS5                      _PTIS.Bits.PTIS5
#define PTIS_PTIS6                      _PTIS.Bits.PTIS6
#define PTIS_PTIS7                      _PTIS.Bits.PTIS7

#define PTIS_PTIS0_MASK                 1U
#define PTIS_PTIS1_MASK                 2U
#define PTIS_PTIS2_MASK                 4U
#define PTIS_PTIS3_MASK                 8U
#define PTIS_PTIS4_MASK                 16U
#define PTIS_PTIS5_MASK                 32U
#define PTIS_PTIS6_MASK                 64U
#define PTIS_PTIS7_MASK                 128U


/*** DDRS - Port S Data Direction Register; 0x0000024A ***/
typedef union {
  byte Byte;
  struct {
    byte DDRS0       :1;                                       /* Port S data direction bit 0 */
    byte DDRS1       :1;                                       /* Port S data direction bit 1 */
    byte DDRS2       :1;                                       /* Port S data direction bit 2 */
    byte DDRS3       :1;                                       /* Port S data direction bit 3 */
    byte DDRS4       :1;                                       /* Port S data direction bit 4 */
    byte DDRS5       :1;                                       /* Port S data direction bit 5 */
    byte DDRS6       :1;                                       /* Port S data direction bit 6 */
    byte DDRS7       :1;                                       /* Port S data direction bit 7 */
  } Bits;
} DDRSSTR;
extern volatile DDRSSTR _DDRS @(REG_BASE + 0x0000024AUL);
#define DDRS                            _DDRS.Byte
#define DDRS_DDRS0                      _DDRS.Bits.DDRS0
#define DDRS_DDRS1                      _DDRS.Bits.DDRS1
#define DDRS_DDRS2                      _DDRS.Bits.DDRS2
#define DDRS_DDRS3                      _DDRS.Bits.DDRS3
#define DDRS_DDRS4                      _DDRS.Bits.DDRS4
#define DDRS_DDRS5                      _DDRS.Bits.DDRS5
#define DDRS_DDRS6                      _DDRS.Bits.DDRS6
#define DDRS_DDRS7                      _DDRS.Bits.DDRS7

#define DDRS_DDRS0_MASK                 1U
#define DDRS_DDRS1_MASK                 2U
#define DDRS_DDRS2_MASK                 4U
#define DDRS_DDRS3_MASK                 8U
#define DDRS_DDRS4_MASK                 16U
#define DDRS_DDRS5_MASK                 32U
#define DDRS_DDRS6_MASK                 64U
#define DDRS_DDRS7_MASK                 128U


/*** RDRS - Port S Reduced Drive Register; 0x0000024B ***/
typedef union {
  byte Byte;
  struct {
    byte RDRS0       :1;                                       /* Port S reduced drive bit 0 */
    byte RDRS1       :1;                                       /* Port S reduced drive bit 1 */
    byte RDRS2       :1;                                       /* Port S reduced drive bit 2 */
    byte RDRS3       :1;                                       /* Port S reduced drive bit 3 */
    byte RDRS4       :1;                                       /* Port S reduced drive bit 4 */
    byte RDRS5       :1;                                       /* Port S reduced drive bit 5 */
    byte RDRS6       :1;                                       /* Port S reduced drive bit 6 */
    byte RDRS7       :1;                                       /* Port S reduced drive bit 7 */
  } Bits;
} RDRSSTR;
extern volatile RDRSSTR _RDRS @(REG_BASE + 0x0000024BUL);
#define RDRS                            _RDRS.Byte
#define RDRS_RDRS0                      _RDRS.Bits.RDRS0
#define RDRS_RDRS1                      _RDRS.Bits.RDRS1
#define RDRS_RDRS2                      _RDRS.Bits.RDRS2
#define RDRS_RDRS3                      _RDRS.Bits.RDRS3
#define RDRS_RDRS4                      _RDRS.Bits.RDRS4
#define RDRS_RDRS5                      _RDRS.Bits.RDRS5
#define RDRS_RDRS6                      _RDRS.Bits.RDRS6
#define RDRS_RDRS7                      _RDRS.Bits.RDRS7

#define RDRS_RDRS0_MASK                 1U
#define RDRS_RDRS1_MASK                 2U
#define RDRS_RDRS2_MASK                 4U
#define RDRS_RDRS3_MASK                 8U
#define RDRS_RDRS4_MASK                 16U
#define RDRS_RDRS5_MASK                 32U
#define RDRS_RDRS6_MASK                 64U
#define RDRS_RDRS7_MASK                 128U


/*** PERS - Port S Pull Device Enable Register; 0x0000024C ***/
typedef union {
  byte Byte;
  struct {
    byte PERS0       :1;                                       /* Port S pull device enable bit 0 */
    byte PERS1       :1;                                       /* Port S pull device enable bit 1 */
    byte PERS2       :1;                                       /* Port S pull device enable bit 2 */
    byte PERS3       :1;                                       /* Port S pull device enable bit 3 */
    byte PERS4       :1;                                       /* Port S pull device enable bit 4 */
    byte PERS5       :1;                                       /* Port S pull device enable bit 5 */
    byte PERS6       :1;                                       /* Port S pull device enable bit 6 */
    byte PERS7       :1;                                       /* Port S pull device enable bit 7 */
  } Bits;
} PERSSTR;
extern volatile PERSSTR _PERS @(REG_BASE + 0x0000024CUL);
#define PERS                            _PERS.Byte
#define PERS_PERS0                      _PERS.Bits.PERS0
#define PERS_PERS1                      _PERS.Bits.PERS1
#define PERS_PERS2                      _PERS.Bits.PERS2
#define PERS_PERS3                      _PERS.Bits.PERS3
#define PERS_PERS4                      _PERS.Bits.PERS4
#define PERS_PERS5                      _PERS.Bits.PERS5
#define PERS_PERS6                      _PERS.Bits.PERS6
#define PERS_PERS7                      _PERS.Bits.PERS7

#define PERS_PERS0_MASK                 1U
#define PERS_PERS1_MASK                 2U
#define PERS_PERS2_MASK                 4U
#define PERS_PERS3_MASK                 8U
#define PERS_PERS4_MASK                 16U
#define PERS_PERS5_MASK                 32U
#define PERS_PERS6_MASK                 64U
#define PERS_PERS7_MASK                 128U


/*** PPSS - Port S Polarity Select Register; 0x0000024D ***/
typedef union {
  byte Byte;
  struct {
    byte PPSS0       :1;                                       /* Port S pull device select bit 0 */
    byte PPSS1       :1;                                       /* Port S pull device select bit 1 */
    byte PPSS2       :1;                                       /* Port S pull device select bit 2 */
    byte PPSS3       :1;                                       /* Port S pull device select bit 3 */
    byte PPSS4       :1;                                       /* Port S pull device select bit 4 */
    byte PPSS5       :1;                                       /* Port S pull device select bit 5 */
    byte PPSS6       :1;                                       /* Port S pull device select bit 6 */
    byte PPSS7       :1;                                       /* Port S pull device select bit 7 */
  } Bits;
} PPSSSTR;
extern volatile PPSSSTR _PPSS @(REG_BASE + 0x0000024DUL);
#define PPSS                            _PPSS.Byte
#define PPSS_PPSS0                      _PPSS.Bits.PPSS0
#define PPSS_PPSS1                      _PPSS.Bits.PPSS1
#define PPSS_PPSS2                      _PPSS.Bits.PPSS2
#define PPSS_PPSS3                      _PPSS.Bits.PPSS3
#define PPSS_PPSS4                      _PPSS.Bits.PPSS4
#define PPSS_PPSS5                      _PPSS.Bits.PPSS5
#define PPSS_PPSS6                      _PPSS.Bits.PPSS6
#define PPSS_PPSS7                      _PPSS.Bits.PPSS7

#define PPSS_PPSS0_MASK                 1U
#define PPSS_PPSS1_MASK                 2U
#define PPSS_PPSS2_MASK                 4U
#define PPSS_PPSS3_MASK                 8U
#define PPSS_PPSS4_MASK                 16U
#define PPSS_PPSS5_MASK                 32U
#define PPSS_PPSS6_MASK                 64U
#define PPSS_PPSS7_MASK                 128U


/*** WOMS - Port S Wired-Or Mode Register; 0x0000024E ***/
typedef union {
  byte Byte;
  struct {
    byte WOMS0       :1;                                       /* Port S wired-or mode bit 0 */
    byte WOMS1       :1;                                       /* Port S wired-or mode bit 1 */
    byte WOMS2       :1;                                       /* Port S wired-or mode bit 2 */
    byte WOMS3       :1;                                       /* Port S wired-or mode bit 3 */
    byte WOMS4       :1;                                       /* Port S wired-or mode bit 4 */
    byte WOMS5       :1;                                       /* Port S wired-or mode bit 5 */
    byte WOMS6       :1;                                       /* Port S wired-or mode bit 6 */
    byte WOMS7       :1;                                       /* Port S wired-or mode bit 7 */
  } Bits;
} WOMSSTR;
extern volatile WOMSSTR _WOMS @(REG_BASE + 0x0000024EUL);
#define WOMS                            _WOMS.Byte
#define WOMS_WOMS0                      _WOMS.Bits.WOMS0
#define WOMS_WOMS1                      _WOMS.Bits.WOMS1
#define WOMS_WOMS2                      _WOMS.Bits.WOMS2
#define WOMS_WOMS3                      _WOMS.Bits.WOMS3
#define WOMS_WOMS4                      _WOMS.Bits.WOMS4
#define WOMS_WOMS5                      _WOMS.Bits.WOMS5
#define WOMS_WOMS6                      _WOMS.Bits.WOMS6
#define WOMS_WOMS7                      _WOMS.Bits.WOMS7

#define WOMS_WOMS0_MASK                 1U
#define WOMS_WOMS1_MASK                 2U
#define WOMS_WOMS2_MASK                 4U
#define WOMS_WOMS3_MASK                 8U
#define WOMS_WOMS4_MASK                 16U
#define WOMS_WOMS5_MASK                 32U
#define WOMS_WOMS6_MASK                 64U
#define WOMS_WOMS7_MASK                 128U


/*** PTSRR - Port S Routing Register; 0x0000024F ***/
typedef union {
  byte Byte;
  struct {
    byte PTSRR0      :1;                                       /* Port S  routing */
    byte PTSRR1      :1;                                       /* Port S  routing */
    byte             :1; 
    byte             :1; 
    byte PTSRR4      :1;                                       /* Port S  routing */
    byte PTSRR5      :1;                                       /* Port S  routing */
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPTSRR :2;
    byte         :1;
    byte         :1;
    byte grpPTSRR_4 :2;
    byte         :1;
    byte         :1;
  } MergedBits;
} PTSRRSTR;
extern volatile PTSRRSTR _PTSRR @(REG_BASE + 0x0000024FUL);
#define PTSRR                           _PTSRR.Byte
#define PTSRR_PTSRR0                    _PTSRR.Bits.PTSRR0
#define PTSRR_PTSRR1                    _PTSRR.Bits.PTSRR1
#define PTSRR_PTSRR4                    _PTSRR.Bits.PTSRR4
#define PTSRR_PTSRR5                    _PTSRR.Bits.PTSRR5
#define PTSRR_PTSRR                     _PTSRR.MergedBits.grpPTSRR
#define PTSRR_PTSRR_4                   _PTSRR.MergedBits.grpPTSRR_4

#define PTSRR_PTSRR0_MASK               1U
#define PTSRR_PTSRR1_MASK               2U
#define PTSRR_PTSRR4_MASK               16U
#define PTSRR_PTSRR5_MASK               32U
#define PTSRR_PTSRR_MASK                3U
#define PTSRR_PTSRR_BITNUM              0U
#define PTSRR_PTSRR_4_MASK              48U
#define PTSRR_PTSRR_4_BITNUM            4U


/*** PTP - Port P Data Register; 0x00000258 ***/
typedef union {
  byte Byte;
  struct {
    byte PTP0        :1;                                       /* Port P general purpose input/output data bit 0 */
    byte PTP1        :1;                                       /* Port P general purpose input/output data bit 1 */
    byte PTP2        :1;                                       /* Port P general purpose input/output data bit 2 */
    byte PTP3        :1;                                       /* Port P general purpose input/output data bit 3 */
    byte PTP4        :1;                                       /* Port P general purpose input/output data bit 4 */
    byte PTP5        :1;                                       /* Port P general purpose input/output data bit 5 */
    byte PTP6        :1;                                       /* Port P general purpose input/output data bit 6 */
    byte PTP7        :1;                                       /* Port P general purpose input/output data bit 7 */
  } Bits;
} PTPSTR;
extern volatile PTPSTR _PTP @(REG_BASE + 0x00000258UL);
#define PTP                             _PTP.Byte
#define PTP_PTP0                        _PTP.Bits.PTP0
#define PTP_PTP1                        _PTP.Bits.PTP1
#define PTP_PTP2                        _PTP.Bits.PTP2
#define PTP_PTP3                        _PTP.Bits.PTP3
#define PTP_PTP4                        _PTP.Bits.PTP4
#define PTP_PTP5                        _PTP.Bits.PTP5
#define PTP_PTP6                        _PTP.Bits.PTP6
#define PTP_PTP7                        _PTP.Bits.PTP7

#define PTP_PTP0_MASK                   1U
#define PTP_PTP1_MASK                   2U
#define PTP_PTP2_MASK                   4U
#define PTP_PTP3_MASK                   8U
#define PTP_PTP4_MASK                   16U
#define PTP_PTP5_MASK                   32U
#define PTP_PTP6_MASK                   64U
#define PTP_PTP7_MASK                   128U


/*** PTIP - Port P Input Register; 0x00000259 ***/
typedef union {
  byte Byte;
  struct {
    byte PTIP0       :1;                                       /* Port P input data bit 0 */
    byte PTIP1       :1;                                       /* Port P input data bit 1 */
    byte PTIP2       :1;                                       /* Port P input data bit 2 */
    byte PTIP3       :1;                                       /* Port P input data bit 3 */
    byte PTIP4       :1;                                       /* Port P input data bit 4 */
    byte PTIP5       :1;                                       /* Port P input data bit 5 */
    byte PTIP6       :1;                                       /* Port P input data bit 6 */
    byte PTIP7       :1;                                       /* Port P input data bit 7 */
  } Bits;
} PTIPSTR;
extern volatile PTIPSTR _PTIP @(REG_BASE + 0x00000259UL);
#define PTIP                            _PTIP.Byte
#define PTIP_PTIP0                      _PTIP.Bits.PTIP0
#define PTIP_PTIP1                      _PTIP.Bits.PTIP1
#define PTIP_PTIP2                      _PTIP.Bits.PTIP2
#define PTIP_PTIP3                      _PTIP.Bits.PTIP3
#define PTIP_PTIP4                      _PTIP.Bits.PTIP4
#define PTIP_PTIP5                      _PTIP.Bits.PTIP5
#define PTIP_PTIP6                      _PTIP.Bits.PTIP6
#define PTIP_PTIP7                      _PTIP.Bits.PTIP7

#define PTIP_PTIP0_MASK                 1U
#define PTIP_PTIP1_MASK                 2U
#define PTIP_PTIP2_MASK                 4U
#define PTIP_PTIP3_MASK                 8U
#define PTIP_PTIP4_MASK                 16U
#define PTIP_PTIP5_MASK                 32U
#define PTIP_PTIP6_MASK                 64U
#define PTIP_PTIP7_MASK                 128U


/*** DDRP - Port P Data Direction Register; 0x0000025A ***/
typedef union {
  byte Byte;
  struct {
    byte DDRP0       :1;                                       /* Port P data direction bit 0 */
    byte DDRP1       :1;                                       /* Port P data direction bit 1 */
    byte DDRP2       :1;                                       /* Port P data direction bit 2 */
    byte DDRP3       :1;                                       /* Port P data direction bit 3 */
    byte DDRP4       :1;                                       /* Port P data direction bit 4 */
    byte DDRP5       :1;                                       /* Port P data direction bit 5 */
    byte DDRP6       :1;                                       /* Port P data direction bit 6 */
    byte DDRP7       :1;                                       /* Port P data direction bit 7 */
  } Bits;
} DDRPSTR;
extern volatile DDRPSTR _DDRP @(REG_BASE + 0x0000025AUL);
#define DDRP                            _DDRP.Byte
#define DDRP_DDRP0                      _DDRP.Bits.DDRP0
#define DDRP_DDRP1                      _DDRP.Bits.DDRP1
#define DDRP_DDRP2                      _DDRP.Bits.DDRP2
#define DDRP_DDRP3                      _DDRP.Bits.DDRP3
#define DDRP_DDRP4                      _DDRP.Bits.DDRP4
#define DDRP_DDRP5                      _DDRP.Bits.DDRP5
#define DDRP_DDRP6                      _DDRP.Bits.DDRP6
#define DDRP_DDRP7                      _DDRP.Bits.DDRP7

#define DDRP_DDRP0_MASK                 1U
#define DDRP_DDRP1_MASK                 2U
#define DDRP_DDRP2_MASK                 4U
#define DDRP_DDRP3_MASK                 8U
#define DDRP_DDRP4_MASK                 16U
#define DDRP_DDRP5_MASK                 32U
#define DDRP_DDRP6_MASK                 64U
#define DDRP_DDRP7_MASK                 128U


/*** RDRP - Port P Reduced Drive Register; 0x0000025B ***/
typedef union {
  byte Byte;
  struct {
    byte RDRP0       :1;                                       /* Port P reduced drive bit 0 */
    byte RDRP1       :1;                                       /* Port P reduced drive bit 1 */
    byte RDRP2       :1;                                       /* Port P reduced drive bit 2 */
    byte RDRP3       :1;                                       /* Port P reduced drive bit 3 */
    byte RDRP4       :1;                                       /* Port P reduced drive bit 4 */
    byte RDRP5       :1;                                       /* Port P reduced drive bit 5 */
    byte RDRP6       :1;                                       /* Port P reduced drive bit 6 */
    byte RDRP7       :1;                                       /* Port P reduced drive bit 7 */
  } Bits;
} RDRPSTR;
extern volatile RDRPSTR _RDRP @(REG_BASE + 0x0000025BUL);
#define RDRP                            _RDRP.Byte
#define RDRP_RDRP0                      _RDRP.Bits.RDRP0
#define RDRP_RDRP1                      _RDRP.Bits.RDRP1
#define RDRP_RDRP2                      _RDRP.Bits.RDRP2
#define RDRP_RDRP3                      _RDRP.Bits.RDRP3
#define RDRP_RDRP4                      _RDRP.Bits.RDRP4
#define RDRP_RDRP5                      _RDRP.Bits.RDRP5
#define RDRP_RDRP6                      _RDRP.Bits.RDRP6
#define RDRP_RDRP7                      _RDRP.Bits.RDRP7

#define RDRP_RDRP0_MASK                 1U
#define RDRP_RDRP1_MASK                 2U
#define RDRP_RDRP2_MASK                 4U
#define RDRP_RDRP3_MASK                 8U
#define RDRP_RDRP4_MASK                 16U
#define RDRP_RDRP5_MASK                 32U
#define RDRP_RDRP6_MASK                 64U
#define RDRP_RDRP7_MASK                 128U


/*** PERP - Port P Pull Device Enable Register; 0x0000025C ***/
typedef union {
  byte Byte;
  struct {
    byte PERP0       :1;                                       /* Port P pull device enable bit 0 */
    byte PERP1       :1;                                       /* Port P pull device enable bit 1 */
    byte PERP2       :1;                                       /* Port P pull device enable bit 2 */
    byte PERP3       :1;                                       /* Port P pull device enable bit 3 */
    byte PERP4       :1;                                       /* Port P pull device enable bit 4 */
    byte PERP5       :1;                                       /* Port P pull device enable bit 5 */
    byte PERP6       :1;                                       /* Port P pull device enable bit 6 */
    byte PERP7       :1;                                       /* Port P pull device enable bit 7 */
  } Bits;
} PERPSTR;
extern volatile PERPSTR _PERP @(REG_BASE + 0x0000025CUL);
#define PERP                            _PERP.Byte
#define PERP_PERP0                      _PERP.Bits.PERP0
#define PERP_PERP1                      _PERP.Bits.PERP1
#define PERP_PERP2                      _PERP.Bits.PERP2
#define PERP_PERP3                      _PERP.Bits.PERP3
#define PERP_PERP4                      _PERP.Bits.PERP4
#define PERP_PERP5                      _PERP.Bits.PERP5
#define PERP_PERP6                      _PERP.Bits.PERP6
#define PERP_PERP7                      _PERP.Bits.PERP7

#define PERP_PERP0_MASK                 1U
#define PERP_PERP1_MASK                 2U
#define PERP_PERP2_MASK                 4U
#define PERP_PERP3_MASK                 8U
#define PERP_PERP4_MASK                 16U
#define PERP_PERP5_MASK                 32U
#define PERP_PERP6_MASK                 64U
#define PERP_PERP7_MASK                 128U


/*** PPSP - Port P Polarity Select Register; 0x0000025D ***/
typedef union {
  byte Byte;
  struct {
    byte PPSP0       :1;                                       /* Port P pull device select bit 0 */
    byte PPSP1       :1;                                       /* Port P pull device select bit 1 */
    byte PPSP2       :1;                                       /* Port P pull device select bit 2 */
    byte PPSP3       :1;                                       /* Port P pull device select bit 3 */
    byte PPSP4       :1;                                       /* Port P pull device select bit 4 */
    byte PPSP5       :1;                                       /* Port P pull device select bit 5 */
    byte PPSP6       :1;                                       /* Port P pull device select bit 6 */
    byte PPSP7       :1;                                       /* Port P pull device select bit 7 */
  } Bits;
} PPSPSTR;
extern volatile PPSPSTR _PPSP @(REG_BASE + 0x0000025DUL);
#define PPSP                            _PPSP.Byte
#define PPSP_PPSP0                      _PPSP.Bits.PPSP0
#define PPSP_PPSP1                      _PPSP.Bits.PPSP1
#define PPSP_PPSP2                      _PPSP.Bits.PPSP2
#define PPSP_PPSP3                      _PPSP.Bits.PPSP3
#define PPSP_PPSP4                      _PPSP.Bits.PPSP4
#define PPSP_PPSP5                      _PPSP.Bits.PPSP5
#define PPSP_PPSP6                      _PPSP.Bits.PPSP6
#define PPSP_PPSP7                      _PPSP.Bits.PPSP7

#define PPSP_PPSP0_MASK                 1U
#define PPSP_PPSP1_MASK                 2U
#define PPSP_PPSP2_MASK                 4U
#define PPSP_PPSP3_MASK                 8U
#define PPSP_PPSP4_MASK                 16U
#define PPSP_PPSP5_MASK                 32U
#define PPSP_PPSP6_MASK                 64U
#define PPSP_PPSP7_MASK                 128U


/*** PTPRR - Port P Routing Register; 0x0000025E ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** PTPRRH - Port P Routing Register High; 0x0000025E ***/
    union {
      byte Byte;
      struct {
        byte PTPRRH0     :1;                                       /* Port P  routing */
        byte PTPRRH1     :1;                                       /* Port P  routing */
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
      } Bits;
      struct {
        byte grpPTPRRH :2;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
      } MergedBits;
    } PTPRRHSTR;
    #define PTPRRH                      _PTPRR.Overlap_STR.PTPRRHSTR.Byte
    #define PTPRRH_PTPRRH0              _PTPRR.Overlap_STR.PTPRRHSTR.Bits.PTPRRH0
    #define PTPRRH_PTPRRH1              _PTPRR.Overlap_STR.PTPRRHSTR.Bits.PTPRRH1
    #define PTPRRH_PTPRRH               _PTPRR.Overlap_STR.PTPRRHSTR.MergedBits.grpPTPRRH
    
    #define PTPRRH_PTPRRH0_MASK         1U
    #define PTPRRH_PTPRRH1_MASK         2U
    #define PTPRRH_PTPRRH_MASK          3U
    #define PTPRRH_PTPRRH_BITNUM        0U
    

    /*** PTPRRL - Port P Routing Register Low; 0x0000025F ***/
    union {
      byte Byte;
      struct {
        byte PTPRRL0     :1;                                       /* Port P  routing */
        byte PTPRRL1     :1;                                       /* Port P  routing */
        byte PTPRRL2     :1;                                       /* Port P  routing */
        byte PTPRRL3     :1;                                       /* Port P  routing */
        byte PTPRRL4     :1;                                       /* Port P  routing */
        byte PTPRRL5     :1;                                       /* Port P  routing */
        byte PTPRRL6     :1;                                       /* Port P  routing */
        byte PTPRRL7     :1;                                       /* Port P  routing */
      } Bits;
    } PTPRRLSTR;
    #define PTPRRL                      _PTPRR.Overlap_STR.PTPRRLSTR.Byte
    #define PTPRRL_PTPRRL0              _PTPRR.Overlap_STR.PTPRRLSTR.Bits.PTPRRL0
    #define PTPRRL_PTPRRL1              _PTPRR.Overlap_STR.PTPRRLSTR.Bits.PTPRRL1
    #define PTPRRL_PTPRRL2              _PTPRR.Overlap_STR.PTPRRLSTR.Bits.PTPRRL2
    #define PTPRRL_PTPRRL3              _PTPRR.Overlap_STR.PTPRRLSTR.Bits.PTPRRL3
    #define PTPRRL_PTPRRL4              _PTPRR.Overlap_STR.PTPRRLSTR.Bits.PTPRRL4
    #define PTPRRL_PTPRRL5              _PTPRR.Overlap_STR.PTPRRLSTR.Bits.PTPRRL5
    #define PTPRRL_PTPRRL6              _PTPRR.Overlap_STR.PTPRRLSTR.Bits.PTPRRL6
    #define PTPRRL_PTPRRL7              _PTPRR.Overlap_STR.PTPRRLSTR.Bits.PTPRRL7
    
    #define PTPRRL_PTPRRL0_MASK         1U
    #define PTPRRL_PTPRRL1_MASK         2U
    #define PTPRRL_PTPRRL2_MASK         4U
    #define PTPRRL_PTPRRL3_MASK         8U
    #define PTPRRL_PTPRRL4_MASK         16U
    #define PTPRRL_PTPRRL5_MASK         32U
    #define PTPRRL_PTPRRL6_MASK         64U
    #define PTPRRL_PTPRRL7_MASK         128U
    
  } Overlap_STR;

  struct {
    word PTPRRL0     :1;                                       /* Port P  routing */
    word PTPRRL1     :1;                                       /* Port P  routing */
    word PTPRRL2     :1;                                       /* Port P  routing */
    word PTPRRL3     :1;                                       /* Port P  routing */
    word PTPRRL4     :1;                                       /* Port P  routing */
    word PTPRRL5     :1;                                       /* Port P  routing */
    word PTPRRL6     :1;                                       /* Port P  routing */
    word PTPRRL7     :1;                                       /* Port P  routing */
    word PTPRRH0     :1;                                       /* Port P  routing */
    word PTPRRH1     :1;                                       /* Port P  routing */
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
  } Bits;
  struct {
    word grpPTPRRL :8;
    word grpPTPRRH :2;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
  } MergedBits;
} PTPRRSTR;
extern volatile PTPRRSTR _PTPRR @(REG_BASE + 0x0000025EUL);
#define PTPRR                           _PTPRR.Word
#define PTPRR_PTPRRL0                   _PTPRR.Bits.PTPRRL0
#define PTPRR_PTPRRL1                   _PTPRR.Bits.PTPRRL1
#define PTPRR_PTPRRL2                   _PTPRR.Bits.PTPRRL2
#define PTPRR_PTPRRL3                   _PTPRR.Bits.PTPRRL3
#define PTPRR_PTPRRL4                   _PTPRR.Bits.PTPRRL4
#define PTPRR_PTPRRL5                   _PTPRR.Bits.PTPRRL5
#define PTPRR_PTPRRL6                   _PTPRR.Bits.PTPRRL6
#define PTPRR_PTPRRL7                   _PTPRR.Bits.PTPRRL7
#define PTPRR_PTPRRH0                   _PTPRR.Bits.PTPRRH0
#define PTPRR_PTPRRH1                   _PTPRR.Bits.PTPRRH1
#define PTPRR_PTPRRL                    _PTPRR.MergedBits.grpPTPRRL
#define PTPRR_PTPRRH                    _PTPRR.MergedBits.grpPTPRRH

#define PTPRR_PTPRRL0_MASK              1U
#define PTPRR_PTPRRL1_MASK              2U
#define PTPRR_PTPRRL2_MASK              4U
#define PTPRR_PTPRRL3_MASK              8U
#define PTPRR_PTPRRL4_MASK              16U
#define PTPRR_PTPRRL5_MASK              32U
#define PTPRR_PTPRRL6_MASK              64U
#define PTPRR_PTPRRL7_MASK              128U
#define PTPRR_PTPRRH0_MASK              256U
#define PTPRR_PTPRRH1_MASK              512U
#define PTPRR_PTPRRL_MASK               255U
#define PTPRR_PTPRRL_BITNUM             0U
#define PTPRR_PTPRRH_MASK               768U
#define PTPRR_PTPRRH_BITNUM             8U


/*** PTH - Port H Data Register; 0x00000260 ***/
typedef union {
  byte Byte;
  struct {
    byte PTH0        :1;                                       /* Port H general purpose input/output data bit 0 */
    byte PTH1        :1;                                       /* Port H general purpose input/output data bit 1 */
    byte PTH2        :1;                                       /* Port H general purpose input/output data bit 2 */
    byte PTH3        :1;                                       /* Port H general purpose input/output data bit 3 */
    byte PTH4        :1;                                       /* Port H general purpose input/output data bit 4 */
    byte PTH5        :1;                                       /* Port H general purpose input/output data bit 5 */
    byte PTH6        :1;                                       /* Port H general purpose input/output data bit 6 */
    byte PTH7        :1;                                       /* Port H general purpose input/output data bit 7 */
  } Bits;
} PTHSTR;
extern volatile PTHSTR _PTH @(REG_BASE + 0x00000260UL);
#define PTH                             _PTH.Byte
#define PTH_PTH0                        _PTH.Bits.PTH0
#define PTH_PTH1                        _PTH.Bits.PTH1
#define PTH_PTH2                        _PTH.Bits.PTH2
#define PTH_PTH3                        _PTH.Bits.PTH3
#define PTH_PTH4                        _PTH.Bits.PTH4
#define PTH_PTH5                        _PTH.Bits.PTH5
#define PTH_PTH6                        _PTH.Bits.PTH6
#define PTH_PTH7                        _PTH.Bits.PTH7

#define PTH_PTH0_MASK                   1U
#define PTH_PTH1_MASK                   2U
#define PTH_PTH2_MASK                   4U
#define PTH_PTH3_MASK                   8U
#define PTH_PTH4_MASK                   16U
#define PTH_PTH5_MASK                   32U
#define PTH_PTH6_MASK                   64U
#define PTH_PTH7_MASK                   128U


/*** PTIH - Port H Input Register; 0x00000261 ***/
typedef union {
  byte Byte;
  struct {
    byte PTIH0       :1;                                       /* Port H input data bit 0 */
    byte PTIH1       :1;                                       /* Port H input data bit 1 */
    byte PTIH2       :1;                                       /* Port H input data bit 2 */
    byte PTIH3       :1;                                       /* Port H input data bit 3 */
    byte PTIH4       :1;                                       /* Port H input data bit 4 */
    byte PTIH5       :1;                                       /* Port H input data bit 5 */
    byte PTIH6       :1;                                       /* Port H input data bit 6 */
    byte PTIH7       :1;                                       /* Port H input data bit 7 */
  } Bits;
} PTIHSTR;
extern volatile PTIHSTR _PTIH @(REG_BASE + 0x00000261UL);
#define PTIH                            _PTIH.Byte
#define PTIH_PTIH0                      _PTIH.Bits.PTIH0
#define PTIH_PTIH1                      _PTIH.Bits.PTIH1
#define PTIH_PTIH2                      _PTIH.Bits.PTIH2
#define PTIH_PTIH3                      _PTIH.Bits.PTIH3
#define PTIH_PTIH4                      _PTIH.Bits.PTIH4
#define PTIH_PTIH5                      _PTIH.Bits.PTIH5
#define PTIH_PTIH6                      _PTIH.Bits.PTIH6
#define PTIH_PTIH7                      _PTIH.Bits.PTIH7

#define PTIH_PTIH0_MASK                 1U
#define PTIH_PTIH1_MASK                 2U
#define PTIH_PTIH2_MASK                 4U
#define PTIH_PTIH3_MASK                 8U
#define PTIH_PTIH4_MASK                 16U
#define PTIH_PTIH5_MASK                 32U
#define PTIH_PTIH6_MASK                 64U
#define PTIH_PTIH7_MASK                 128U


/*** DDRH - Port H Data Direction Register; 0x00000262 ***/
typedef union {
  byte Byte;
  struct {
    byte DDRH0       :1;                                       /* Port H data direction bit 0 */
    byte DDRH1       :1;                                       /* Port H data direction bit 1 */
    byte DDRH2       :1;                                       /* Port H data direction bit 2 */
    byte DDRH3       :1;                                       /* Port H data direction bit 3 */
    byte DDRH4       :1;                                       /* Port H data direction bit 4 */
    byte DDRH5       :1;                                       /* Port H data direction bit 5 */
    byte DDRH6       :1;                                       /* Port H data direction bit 6 */
    byte DDRH7       :1;                                       /* Port H data direction bit 7 */
  } Bits;
} DDRHSTR;
extern volatile DDRHSTR _DDRH @(REG_BASE + 0x00000262UL);
#define DDRH                            _DDRH.Byte
#define DDRH_DDRH0                      _DDRH.Bits.DDRH0
#define DDRH_DDRH1                      _DDRH.Bits.DDRH1
#define DDRH_DDRH2                      _DDRH.Bits.DDRH2
#define DDRH_DDRH3                      _DDRH.Bits.DDRH3
#define DDRH_DDRH4                      _DDRH.Bits.DDRH4
#define DDRH_DDRH5                      _DDRH.Bits.DDRH5
#define DDRH_DDRH6                      _DDRH.Bits.DDRH6
#define DDRH_DDRH7                      _DDRH.Bits.DDRH7

#define DDRH_DDRH0_MASK                 1U
#define DDRH_DDRH1_MASK                 2U
#define DDRH_DDRH2_MASK                 4U
#define DDRH_DDRH3_MASK                 8U
#define DDRH_DDRH4_MASK                 16U
#define DDRH_DDRH5_MASK                 32U
#define DDRH_DDRH6_MASK                 64U
#define DDRH_DDRH7_MASK                 128U


/*** RDRH - Port H Reduced Drive Register; 0x00000263 ***/
typedef union {
  byte Byte;
  struct {
    byte RDRH0       :1;                                       /* Port H reduced drive bit 0 */
    byte RDRH1       :1;                                       /* Port H reduced drive bit 1 */
    byte RDRH2       :1;                                       /* Port H reduced drive bit 2 */
    byte RDRH3       :1;                                       /* Port H reduced drive bit 3 */
    byte RDRH4       :1;                                       /* Port H reduced drive bit 4 */
    byte RDRH5       :1;                                       /* Port H reduced drive bit 5 */
    byte RDRH6       :1;                                       /* Port H reduced drive bit 6 */
    byte RDRH7       :1;                                       /* Port H reduced drive bit 7 */
  } Bits;
} RDRHSTR;
extern volatile RDRHSTR _RDRH @(REG_BASE + 0x00000263UL);
#define RDRH                            _RDRH.Byte
#define RDRH_RDRH0                      _RDRH.Bits.RDRH0
#define RDRH_RDRH1                      _RDRH.Bits.RDRH1
#define RDRH_RDRH2                      _RDRH.Bits.RDRH2
#define RDRH_RDRH3                      _RDRH.Bits.RDRH3
#define RDRH_RDRH4                      _RDRH.Bits.RDRH4
#define RDRH_RDRH5                      _RDRH.Bits.RDRH5
#define RDRH_RDRH6                      _RDRH.Bits.RDRH6
#define RDRH_RDRH7                      _RDRH.Bits.RDRH7

#define RDRH_RDRH0_MASK                 1U
#define RDRH_RDRH1_MASK                 2U
#define RDRH_RDRH2_MASK                 4U
#define RDRH_RDRH3_MASK                 8U
#define RDRH_RDRH4_MASK                 16U
#define RDRH_RDRH5_MASK                 32U
#define RDRH_RDRH6_MASK                 64U
#define RDRH_RDRH7_MASK                 128U


/*** PERH - Port H Pull Device Enable Register; 0x00000264 ***/
typedef union {
  byte Byte;
  struct {
    byte PERH0       :1;                                       /* Port H pull device enable bit 0 */
    byte PERH1       :1;                                       /* Port H pull device enable bit 1 */
    byte PERH2       :1;                                       /* Port H pull device enable bit 2 */
    byte PERH3       :1;                                       /* Port H pull device enable bit 3 */
    byte PERH4       :1;                                       /* Port H pull device enable bit 4 */
    byte PERH5       :1;                                       /* Port H pull device enable bit 5 */
    byte PERH6       :1;                                       /* Port H pull device enable bit 6 */
    byte PERH7       :1;                                       /* Port H pull device enable bit 7 */
  } Bits;
} PERHSTR;
extern volatile PERHSTR _PERH @(REG_BASE + 0x00000264UL);
#define PERH                            _PERH.Byte
#define PERH_PERH0                      _PERH.Bits.PERH0
#define PERH_PERH1                      _PERH.Bits.PERH1
#define PERH_PERH2                      _PERH.Bits.PERH2
#define PERH_PERH3                      _PERH.Bits.PERH3
#define PERH_PERH4                      _PERH.Bits.PERH4
#define PERH_PERH5                      _PERH.Bits.PERH5
#define PERH_PERH6                      _PERH.Bits.PERH6
#define PERH_PERH7                      _PERH.Bits.PERH7

#define PERH_PERH0_MASK                 1U
#define PERH_PERH1_MASK                 2U
#define PERH_PERH2_MASK                 4U
#define PERH_PERH3_MASK                 8U
#define PERH_PERH4_MASK                 16U
#define PERH_PERH5_MASK                 32U
#define PERH_PERH6_MASK                 64U
#define PERH_PERH7_MASK                 128U


/*** PPSH - Port H Polarity Select Register; 0x00000265 ***/
typedef union {
  byte Byte;
  struct {
    byte PPSH0       :1;                                       /* Port H pull device select bit 0 */
    byte PPSH1       :1;                                       /* Port H pull device select bit 1 */
    byte PPSH2       :1;                                       /* Port H pull device select bit 2 */
    byte PPSH3       :1;                                       /* Port H pull device select bit 3 */
    byte PPSH4       :1;                                       /* Port H pull device select bit 4 */
    byte PPSH5       :1;                                       /* Port H pull device select bit 5 */
    byte PPSH6       :1;                                       /* Port H pull device select bit 6 */
    byte PPSH7       :1;                                       /* Port H pull device select bit 7 */
  } Bits;
} PPSHSTR;
extern volatile PPSHSTR _PPSH @(REG_BASE + 0x00000265UL);
#define PPSH                            _PPSH.Byte
#define PPSH_PPSH0                      _PPSH.Bits.PPSH0
#define PPSH_PPSH1                      _PPSH.Bits.PPSH1
#define PPSH_PPSH2                      _PPSH.Bits.PPSH2
#define PPSH_PPSH3                      _PPSH.Bits.PPSH3
#define PPSH_PPSH4                      _PPSH.Bits.PPSH4
#define PPSH_PPSH5                      _PPSH.Bits.PPSH5
#define PPSH_PPSH6                      _PPSH.Bits.PPSH6
#define PPSH_PPSH7                      _PPSH.Bits.PPSH7

#define PPSH_PPSH0_MASK                 1U
#define PPSH_PPSH1_MASK                 2U
#define PPSH_PPSH2_MASK                 4U
#define PPSH_PPSH3_MASK                 8U
#define PPSH_PPSH4_MASK                 16U
#define PPSH_PPSH5_MASK                 32U
#define PPSH_PPSH6_MASK                 64U
#define PPSH_PPSH7_MASK                 128U


/*** WOMH - Port H Wired-Or Mode Register; 0x00000266 ***/
typedef union {
  byte Byte;
  struct {
    byte WOMH0       :1;                                       /* Port H wired-or mode bit 0 */
    byte WOMH1       :1;                                       /* Port H wired-or mode bit 1 */
    byte WOMH2       :1;                                       /* Port H wired-or mode bit 2 */
    byte WOMH3       :1;                                       /* Port H wired-or mode bit 3 */
    byte WOMH4       :1;                                       /* Port H wired-or mode bit 4 */
    byte WOMH5       :1;                                       /* Port H wired-or mode bit 5 */
    byte WOMH6       :1;                                       /* Port H wired-or mode bit 6 */
    byte WOMH7       :1;                                       /* Port H wired-or mode bit 7 */
  } Bits;
} WOMHSTR;
extern volatile WOMHSTR _WOMH @(REG_BASE + 0x00000266UL);
#define WOMH                            _WOMH.Byte
#define WOMH_WOMH0                      _WOMH.Bits.WOMH0
#define WOMH_WOMH1                      _WOMH.Bits.WOMH1
#define WOMH_WOMH2                      _WOMH.Bits.WOMH2
#define WOMH_WOMH3                      _WOMH.Bits.WOMH3
#define WOMH_WOMH4                      _WOMH.Bits.WOMH4
#define WOMH_WOMH5                      _WOMH.Bits.WOMH5
#define WOMH_WOMH6                      _WOMH.Bits.WOMH6
#define WOMH_WOMH7                      _WOMH.Bits.WOMH7

#define WOMH_WOMH0_MASK                 1U
#define WOMH_WOMH1_MASK                 2U
#define WOMH_WOMH2_MASK                 4U
#define WOMH_WOMH3_MASK                 8U
#define WOMH_WOMH4_MASK                 16U
#define WOMH_WOMH5_MASK                 32U
#define WOMH_WOMH6_MASK                 64U
#define WOMH_WOMH7_MASK                 128U


/*** PT1AD - Port AD Data Register; 0x00000271 ***/
typedef union {
  byte Byte;
  struct {
    byte PT1AD0      :1;                                       /* Port AD data bit 0 */
    byte PT1AD1      :1;                                       /* Port AD data bit 1 */
    byte PT1AD2      :1;                                       /* Port AD data bit 2 */
    byte PT1AD3      :1;                                       /* Port AD data bit 3 */
    byte PT1AD4      :1;                                       /* Port AD data bit 4 */
    byte PT1AD5      :1;                                       /* Port AD data bit 5 */
    byte PT1AD6      :1;                                       /* Port AD data bit 6 */
    byte PT1AD7      :1;                                       /* Port AD data bit 7 */
  } Bits;
} PT1ADSTR;
extern volatile PT1ADSTR _PT1AD @(REG_BASE + 0x00000271UL);
#define PT1AD                           _PT1AD.Byte
#define PT1AD_PT1AD0                    _PT1AD.Bits.PT1AD0
#define PT1AD_PT1AD1                    _PT1AD.Bits.PT1AD1
#define PT1AD_PT1AD2                    _PT1AD.Bits.PT1AD2
#define PT1AD_PT1AD3                    _PT1AD.Bits.PT1AD3
#define PT1AD_PT1AD4                    _PT1AD.Bits.PT1AD4
#define PT1AD_PT1AD5                    _PT1AD.Bits.PT1AD5
#define PT1AD_PT1AD6                    _PT1AD.Bits.PT1AD6
#define PT1AD_PT1AD7                    _PT1AD.Bits.PT1AD7

#define PT1AD_PT1AD0_MASK               1U
#define PT1AD_PT1AD1_MASK               2U
#define PT1AD_PT1AD2_MASK               4U
#define PT1AD_PT1AD3_MASK               8U
#define PT1AD_PT1AD4_MASK               16U
#define PT1AD_PT1AD5_MASK               32U
#define PT1AD_PT1AD6_MASK               64U
#define PT1AD_PT1AD7_MASK               128U


/*** DDR1AD - Port AD Data Direction Register; 0x00000273 ***/
typedef union {
  byte Byte;
  struct {
    byte DDR1AD0     :1;                                       /* Port AD data direction bit 0 */
    byte DDR1AD1     :1;                                       /* Port AD data direction bit 1 */
    byte DDR1AD2     :1;                                       /* Port AD data direction bit 2 */
    byte DDR1AD3     :1;                                       /* Port AD data direction bit 3 */
    byte DDR1AD4     :1;                                       /* Port AD data direction bit 4 */
    byte DDR1AD5     :1;                                       /* Port AD data direction bit 5 */
    byte DDR1AD6     :1;                                       /* Port AD data direction bit 6 */
    byte DDR1AD7     :1;                                       /* Port AD data direction bit 7 */
  } Bits;
} DDR1ADSTR;
extern volatile DDR1ADSTR _DDR1AD @(REG_BASE + 0x00000273UL);
#define DDR1AD                          _DDR1AD.Byte
#define DDR1AD_DDR1AD0                  _DDR1AD.Bits.DDR1AD0
#define DDR1AD_DDR1AD1                  _DDR1AD.Bits.DDR1AD1
#define DDR1AD_DDR1AD2                  _DDR1AD.Bits.DDR1AD2
#define DDR1AD_DDR1AD3                  _DDR1AD.Bits.DDR1AD3
#define DDR1AD_DDR1AD4                  _DDR1AD.Bits.DDR1AD4
#define DDR1AD_DDR1AD5                  _DDR1AD.Bits.DDR1AD5
#define DDR1AD_DDR1AD6                  _DDR1AD.Bits.DDR1AD6
#define DDR1AD_DDR1AD7                  _DDR1AD.Bits.DDR1AD7

#define DDR1AD_DDR1AD0_MASK             1U
#define DDR1AD_DDR1AD1_MASK             2U
#define DDR1AD_DDR1AD2_MASK             4U
#define DDR1AD_DDR1AD3_MASK             8U
#define DDR1AD_DDR1AD4_MASK             16U
#define DDR1AD_DDR1AD5_MASK             32U
#define DDR1AD_DDR1AD6_MASK             64U
#define DDR1AD_DDR1AD7_MASK             128U


/*** RDR1AD - Port AD Reduced Drive Register; 0x00000275 ***/
typedef union {
  byte Byte;
  struct {
    byte RDR1AD0     :1;                                       /* Port AD reduced drive bit 0 */
    byte RDR1AD1     :1;                                       /* Port AD reduced drive bit 1 */
    byte RDR1AD2     :1;                                       /* Port AD reduced drive bit 2 */
    byte RDR1AD3     :1;                                       /* Port AD reduced drive bit 3 */
    byte RDR1AD4     :1;                                       /* Port AD reduced drive bit 4 */
    byte RDR1AD5     :1;                                       /* Port AD reduced drive bit 5 */
    byte RDR1AD6     :1;                                       /* Port AD reduced drive bit 6 */
    byte RDR1AD7     :1;                                       /* Port AD reduced drive bit 7 */
  } Bits;
} RDR1ADSTR;
extern volatile RDR1ADSTR _RDR1AD @(REG_BASE + 0x00000275UL);
#define RDR1AD                          _RDR1AD.Byte
#define RDR1AD_RDR1AD0                  _RDR1AD.Bits.RDR1AD0
#define RDR1AD_RDR1AD1                  _RDR1AD.Bits.RDR1AD1
#define RDR1AD_RDR1AD2                  _RDR1AD.Bits.RDR1AD2
#define RDR1AD_RDR1AD3                  _RDR1AD.Bits.RDR1AD3
#define RDR1AD_RDR1AD4                  _RDR1AD.Bits.RDR1AD4
#define RDR1AD_RDR1AD5                  _RDR1AD.Bits.RDR1AD5
#define RDR1AD_RDR1AD6                  _RDR1AD.Bits.RDR1AD6
#define RDR1AD_RDR1AD7                  _RDR1AD.Bits.RDR1AD7

#define RDR1AD_RDR1AD0_MASK             1U
#define RDR1AD_RDR1AD1_MASK             2U
#define RDR1AD_RDR1AD2_MASK             4U
#define RDR1AD_RDR1AD3_MASK             8U
#define RDR1AD_RDR1AD4_MASK             16U
#define RDR1AD_RDR1AD5_MASK             32U
#define RDR1AD_RDR1AD6_MASK             64U
#define RDR1AD_RDR1AD7_MASK             128U


/*** PER1AD - Port AD Pull Up Enable Register; 0x00000277 ***/
typedef union {
  byte Byte;
  struct {
    byte PER1AD0     :1;                                       /* Port AD pull up enable bit 0 */
    byte PER1AD1     :1;                                       /* Port AD pull up enable bit 1 */
    byte PER1AD2     :1;                                       /* Port AD pull up enable bit 2 */
    byte PER1AD3     :1;                                       /* Port AD pull up enable bit 3 */
    byte PER1AD4     :1;                                       /* Port AD pull up enable bit 4 */
    byte PER1AD5     :1;                                       /* Port AD pull up enable bit 5 */
    byte PER1AD6     :1;                                       /* Port AD pull up enable bit 6 */
    byte PER1AD7     :1;                                       /* Port AD pull up enable bit 7 */
  } Bits;
} PER1ADSTR;
extern volatile PER1ADSTR _PER1AD @(REG_BASE + 0x00000277UL);
#define PER1AD                          _PER1AD.Byte
#define PER1AD_PER1AD0                  _PER1AD.Bits.PER1AD0
#define PER1AD_PER1AD1                  _PER1AD.Bits.PER1AD1
#define PER1AD_PER1AD2                  _PER1AD.Bits.PER1AD2
#define PER1AD_PER1AD3                  _PER1AD.Bits.PER1AD3
#define PER1AD_PER1AD4                  _PER1AD.Bits.PER1AD4
#define PER1AD_PER1AD5                  _PER1AD.Bits.PER1AD5
#define PER1AD_PER1AD6                  _PER1AD.Bits.PER1AD6
#define PER1AD_PER1AD7                  _PER1AD.Bits.PER1AD7

#define PER1AD_PER1AD0_MASK             1U
#define PER1AD_PER1AD1_MASK             2U
#define PER1AD_PER1AD2_MASK             4U
#define PER1AD_PER1AD3_MASK             8U
#define PER1AD_PER1AD4_MASK             16U
#define PER1AD_PER1AD5_MASK             32U
#define PER1AD_PER1AD6_MASK             64U
#define PER1AD_PER1AD7_MASK             128U


/*** PTR - Port R Data Register; 0x00000280 ***/
typedef union {
  byte Byte;
  struct {
    byte PTR0        :1;                                       /* Port R general purpose input/output data bit 0 */
    byte PTR1        :1;                                       /* Port R general purpose input/output data bit 1 */
    byte PTR2        :1;                                       /* Port R general purpose input/output data bit 2 */
    byte PTR3        :1;                                       /* Port R general purpose input/output data bit 3 */
    byte PTR4        :1;                                       /* Port R general purpose input/output data bit 4 */
    byte PTR5        :1;                                       /* Port R general purpose input/output data bit 5 */
    byte PTR6        :1;                                       /* Port R general purpose input/output data bit 6 */
    byte PTR7        :1;                                       /* Port R general purpose input/output data bit 7 */
  } Bits;
} PTRSTR;
extern volatile PTRSTR _PTR @(REG_BASE + 0x00000280UL);
#define PTR                             _PTR.Byte
#define PTR_PTR0                        _PTR.Bits.PTR0
#define PTR_PTR1                        _PTR.Bits.PTR1
#define PTR_PTR2                        _PTR.Bits.PTR2
#define PTR_PTR3                        _PTR.Bits.PTR3
#define PTR_PTR4                        _PTR.Bits.PTR4
#define PTR_PTR5                        _PTR.Bits.PTR5
#define PTR_PTR6                        _PTR.Bits.PTR6
#define PTR_PTR7                        _PTR.Bits.PTR7

#define PTR_PTR0_MASK                   1U
#define PTR_PTR1_MASK                   2U
#define PTR_PTR2_MASK                   4U
#define PTR_PTR3_MASK                   8U
#define PTR_PTR4_MASK                   16U
#define PTR_PTR5_MASK                   32U
#define PTR_PTR6_MASK                   64U
#define PTR_PTR7_MASK                   128U


/*** PTIR - Port R Input Register; 0x00000281 ***/
typedef union {
  byte Byte;
  struct {
    byte PTIR0       :1;                                       /* Port R input data bit 0 */
    byte PTIR1       :1;                                       /* Port R input data bit 1 */
    byte PTIR2       :1;                                       /* Port R input data bit 2 */
    byte PTIR3       :1;                                       /* Port R input data bit 3 */
    byte PTIR4       :1;                                       /* Port R input data bit 4 */
    byte PTIR5       :1;                                       /* Port R input data bit 5 */
    byte PTIR6       :1;                                       /* Port R input data bit 6 */
    byte PTIR7       :1;                                       /* Port R input data bit 7 */
  } Bits;
} PTIRSTR;
extern volatile PTIRSTR _PTIR @(REG_BASE + 0x00000281UL);
#define PTIR                            _PTIR.Byte
#define PTIR_PTIR0                      _PTIR.Bits.PTIR0
#define PTIR_PTIR1                      _PTIR.Bits.PTIR1
#define PTIR_PTIR2                      _PTIR.Bits.PTIR2
#define PTIR_PTIR3                      _PTIR.Bits.PTIR3
#define PTIR_PTIR4                      _PTIR.Bits.PTIR4
#define PTIR_PTIR5                      _PTIR.Bits.PTIR5
#define PTIR_PTIR6                      _PTIR.Bits.PTIR6
#define PTIR_PTIR7                      _PTIR.Bits.PTIR7

#define PTIR_PTIR0_MASK                 1U
#define PTIR_PTIR1_MASK                 2U
#define PTIR_PTIR2_MASK                 4U
#define PTIR_PTIR3_MASK                 8U
#define PTIR_PTIR4_MASK                 16U
#define PTIR_PTIR5_MASK                 32U
#define PTIR_PTIR6_MASK                 64U
#define PTIR_PTIR7_MASK                 128U


/*** DDRR - Port R Data Direction Register; 0x00000282 ***/
typedef union {
  byte Byte;
  struct {
    byte DDRR0       :1;                                       /* Port R data direction bit 0 */
    byte DDRR1       :1;                                       /* Port R data direction bit 1 */
    byte DDRR2       :1;                                       /* Port R data direction bit 2 */
    byte DDRR3       :1;                                       /* Port R data direction bit 3 */
    byte DDRR4       :1;                                       /* Port R data direction bit 4 */
    byte DDRR5       :1;                                       /* Port R data direction bit 5 */
    byte DDRR6       :1;                                       /* Port R data direction bit 6 */
    byte DDRR7       :1;                                       /* Port R data direction bit 7 */
  } Bits;
} DDRRSTR;
extern volatile DDRRSTR _DDRR @(REG_BASE + 0x00000282UL);
#define DDRR                            _DDRR.Byte
#define DDRR_DDRR0                      _DDRR.Bits.DDRR0
#define DDRR_DDRR1                      _DDRR.Bits.DDRR1
#define DDRR_DDRR2                      _DDRR.Bits.DDRR2
#define DDRR_DDRR3                      _DDRR.Bits.DDRR3
#define DDRR_DDRR4                      _DDRR.Bits.DDRR4
#define DDRR_DDRR5                      _DDRR.Bits.DDRR5
#define DDRR_DDRR6                      _DDRR.Bits.DDRR6
#define DDRR_DDRR7                      _DDRR.Bits.DDRR7

#define DDRR_DDRR0_MASK                 1U
#define DDRR_DDRR1_MASK                 2U
#define DDRR_DDRR2_MASK                 4U
#define DDRR_DDRR3_MASK                 8U
#define DDRR_DDRR4_MASK                 16U
#define DDRR_DDRR5_MASK                 32U
#define DDRR_DDRR6_MASK                 64U
#define DDRR_DDRR7_MASK                 128U


/*** RDRR - Port R Reduced Drive Register; 0x00000283 ***/
typedef union {
  byte Byte;
  struct {
    byte RDRR0       :1;                                       /* Port R reduced drive bit 0 */
    byte RDRR1       :1;                                       /* Port R reduced drive bit 1 */
    byte RDRR2       :1;                                       /* Port R reduced drive bit 2 */
    byte RDRR3       :1;                                       /* Port R reduced drive bit 3 */
    byte RDRR4       :1;                                       /* Port R reduced drive bit 4 */
    byte RDRR5       :1;                                       /* Port R reduced drive bit 5 */
    byte RDRR6       :1;                                       /* Port R reduced drive bit 6 */
    byte RDRR7       :1;                                       /* Port R reduced drive bit 7 */
  } Bits;
} RDRRSTR;
extern volatile RDRRSTR _RDRR @(REG_BASE + 0x00000283UL);
#define RDRR                            _RDRR.Byte
#define RDRR_RDRR0                      _RDRR.Bits.RDRR0
#define RDRR_RDRR1                      _RDRR.Bits.RDRR1
#define RDRR_RDRR2                      _RDRR.Bits.RDRR2
#define RDRR_RDRR3                      _RDRR.Bits.RDRR3
#define RDRR_RDRR4                      _RDRR.Bits.RDRR4
#define RDRR_RDRR5                      _RDRR.Bits.RDRR5
#define RDRR_RDRR6                      _RDRR.Bits.RDRR6
#define RDRR_RDRR7                      _RDRR.Bits.RDRR7

#define RDRR_RDRR0_MASK                 1U
#define RDRR_RDRR1_MASK                 2U
#define RDRR_RDRR2_MASK                 4U
#define RDRR_RDRR3_MASK                 8U
#define RDRR_RDRR4_MASK                 16U
#define RDRR_RDRR5_MASK                 32U
#define RDRR_RDRR6_MASK                 64U
#define RDRR_RDRR7_MASK                 128U


/*** PERR - Port R Pull Device Enable Register; 0x00000284 ***/
typedef union {
  byte Byte;
  struct {
    byte PERR0       :1;                                       /* Port R pull device enable bit 0 */
    byte PERR1       :1;                                       /* Port R pull device enable bit 1 */
    byte PERR2       :1;                                       /* Port R pull device enable bit 2 */
    byte PERR3       :1;                                       /* Port R pull device enable bit 3 */
    byte PERR4       :1;                                       /* Port R pull device enable bit 4 */
    byte PERR5       :1;                                       /* Port R pull device enable bit 5 */
    byte PERR6       :1;                                       /* Port R pull device enable bit 6 */
    byte PERR7       :1;                                       /* Port R pull device enable bit 7 */
  } Bits;
} PERRSTR;
extern volatile PERRSTR _PERR @(REG_BASE + 0x00000284UL);
#define PERR                            _PERR.Byte
#define PERR_PERR0                      _PERR.Bits.PERR0
#define PERR_PERR1                      _PERR.Bits.PERR1
#define PERR_PERR2                      _PERR.Bits.PERR2
#define PERR_PERR3                      _PERR.Bits.PERR3
#define PERR_PERR4                      _PERR.Bits.PERR4
#define PERR_PERR5                      _PERR.Bits.PERR5
#define PERR_PERR6                      _PERR.Bits.PERR6
#define PERR_PERR7                      _PERR.Bits.PERR7

#define PERR_PERR0_MASK                 1U
#define PERR_PERR1_MASK                 2U
#define PERR_PERR2_MASK                 4U
#define PERR_PERR3_MASK                 8U
#define PERR_PERR4_MASK                 16U
#define PERR_PERR5_MASK                 32U
#define PERR_PERR6_MASK                 64U
#define PERR_PERR7_MASK                 128U


/*** PPSR - Port R Polarity Select Register; 0x00000285 ***/
typedef union {
  byte Byte;
  struct {
    byte PPSR0       :1;                                       /* Port R pull device select bit 0 */
    byte PPSR1       :1;                                       /* Port R pull device select bit 1 */
    byte PPSR2       :1;                                       /* Port R pull device select bit 2 */
    byte PPSR3       :1;                                       /* Port R pull device select bit 3 */
    byte PPSR4       :1;                                       /* Port R pull device select bit 4 */
    byte PPSR5       :1;                                       /* Port R pull device select bit 5 */
    byte PPSR6       :1;                                       /* Port R pull device select bit 6 */
    byte PPSR7       :1;                                       /* Port R pull device select bit 7 */
  } Bits;
} PPSRSTR;
extern volatile PPSRSTR _PPSR @(REG_BASE + 0x00000285UL);
#define PPSR                            _PPSR.Byte
#define PPSR_PPSR0                      _PPSR.Bits.PPSR0
#define PPSR_PPSR1                      _PPSR.Bits.PPSR1
#define PPSR_PPSR2                      _PPSR.Bits.PPSR2
#define PPSR_PPSR3                      _PPSR.Bits.PPSR3
#define PPSR_PPSR4                      _PPSR.Bits.PPSR4
#define PPSR_PPSR5                      _PPSR.Bits.PPSR5
#define PPSR_PPSR6                      _PPSR.Bits.PPSR6
#define PPSR_PPSR7                      _PPSR.Bits.PPSR7

#define PPSR_PPSR0_MASK                 1U
#define PPSR_PPSR1_MASK                 2U
#define PPSR_PPSR2_MASK                 4U
#define PPSR_PPSR3_MASK                 8U
#define PPSR_PPSR4_MASK                 16U
#define PPSR_PPSR5_MASK                 32U
#define PPSR_PPSR6_MASK                 64U
#define PPSR_PPSR7_MASK                 128U


/*** WOMR - Port R Wired-Or Mode Register; 0x00000286 ***/
typedef union {
  byte Byte;
  struct {
    byte WOMR0       :1;                                       /* Port R wired-or mode bit 0 */
    byte WOMR1       :1;                                       /* Port R wired-or mode bit 1 */
    byte WOMR2       :1;                                       /* Port R wired-or mode bit 2 */
    byte WOMR3       :1;                                       /* Port R wired-or mode bit 3 */
    byte WOMR4       :1;                                       /* Port R wired-or mode bit 4 */
    byte WOMR5       :1;                                       /* Port R wired-or mode bit 5 */
    byte WOMR6       :1;                                       /* Port R wired-or mode bit 6 */
    byte WOMR7       :1;                                       /* Port R wired-or mode bit 7 */
  } Bits;
} WOMRSTR;
extern volatile WOMRSTR _WOMR @(REG_BASE + 0x00000286UL);
#define WOMR                            _WOMR.Byte
#define WOMR_WOMR0                      _WOMR.Bits.WOMR0
#define WOMR_WOMR1                      _WOMR.Bits.WOMR1
#define WOMR_WOMR2                      _WOMR.Bits.WOMR2
#define WOMR_WOMR3                      _WOMR.Bits.WOMR3
#define WOMR_WOMR4                      _WOMR.Bits.WOMR4
#define WOMR_WOMR5                      _WOMR.Bits.WOMR5
#define WOMR_WOMR6                      _WOMR.Bits.WOMR6
#define WOMR_WOMR7                      _WOMR.Bits.WOMR7

#define WOMR_WOMR0_MASK                 1U
#define WOMR_WOMR1_MASK                 2U
#define WOMR_WOMR2_MASK                 4U
#define WOMR_WOMR3_MASK                 8U
#define WOMR_WOMR4_MASK                 16U
#define WOMR_WOMR5_MASK                 32U
#define WOMR_WOMR6_MASK                 64U
#define WOMR_WOMR7_MASK                 128U


/*** PIET - Port T Interrupt Enable Register; 0x00000288 ***/
typedef union {
  byte Byte;
  struct {
    byte PIET0       :1;                                       /* Port T interrupt enable bit 0 */
    byte PIET1       :1;                                       /* Port T interrupt enable bit 1 */
    byte PIET2       :1;                                       /* Port T interrupt enable bit 2 */
    byte PIET3       :1;                                       /* Port T interrupt enable bit 3 */
    byte PIET4       :1;                                       /* Port T interrupt enable bit 4 */
    byte PIET5       :1;                                       /* Port T interrupt enable bit 5 */
    byte PIET6       :1;                                       /* Port T interrupt enable bit 6 */
    byte PIET7       :1;                                       /* Port T interrupt enable bit 7 */
  } Bits;
} PIETSTR;
extern volatile PIETSTR _PIET @(REG_BASE + 0x00000288UL);
#define PIET                            _PIET.Byte
#define PIET_PIET0                      _PIET.Bits.PIET0
#define PIET_PIET1                      _PIET.Bits.PIET1
#define PIET_PIET2                      _PIET.Bits.PIET2
#define PIET_PIET3                      _PIET.Bits.PIET3
#define PIET_PIET4                      _PIET.Bits.PIET4
#define PIET_PIET5                      _PIET.Bits.PIET5
#define PIET_PIET6                      _PIET.Bits.PIET6
#define PIET_PIET7                      _PIET.Bits.PIET7

#define PIET_PIET0_MASK                 1U
#define PIET_PIET1_MASK                 2U
#define PIET_PIET2_MASK                 4U
#define PIET_PIET3_MASK                 8U
#define PIET_PIET4_MASK                 16U
#define PIET_PIET5_MASK                 32U
#define PIET_PIET6_MASK                 64U
#define PIET_PIET7_MASK                 128U


/*** PIFT - Port T Interrupt Flag Register; 0x00000289 ***/
typedef union {
  byte Byte;
  struct {
    byte PIFT0       :1;                                       /* Port T interrupt flag bit 0 */
    byte PIFT1       :1;                                       /* Port T interrupt flag bit 1 */
    byte PIFT2       :1;                                       /* Port T interrupt flag bit 2 */
    byte PIFT3       :1;                                       /* Port T interrupt flag bit 3 */
    byte PIFT4       :1;                                       /* Port T interrupt flag bit 4 */
    byte PIFT5       :1;                                       /* Port T interrupt flag bit 5 */
    byte PIFT6       :1;                                       /* Port T interrupt flag bit 6 */
    byte PIFT7       :1;                                       /* Port T interrupt flag bit 7 */
  } Bits;
} PIFTSTR;
extern volatile PIFTSTR _PIFT @(REG_BASE + 0x00000289UL);
#define PIFT                            _PIFT.Byte
#define PIFT_PIFT0                      _PIFT.Bits.PIFT0
#define PIFT_PIFT1                      _PIFT.Bits.PIFT1
#define PIFT_PIFT2                      _PIFT.Bits.PIFT2
#define PIFT_PIFT3                      _PIFT.Bits.PIFT3
#define PIFT_PIFT4                      _PIFT.Bits.PIFT4
#define PIFT_PIFT5                      _PIFT.Bits.PIFT5
#define PIFT_PIFT6                      _PIFT.Bits.PIFT6
#define PIFT_PIFT7                      _PIFT.Bits.PIFT7

#define PIFT_PIFT0_MASK                 1U
#define PIFT_PIFT1_MASK                 2U
#define PIFT_PIFT2_MASK                 4U
#define PIFT_PIFT3_MASK                 8U
#define PIFT_PIFT4_MASK                 16U
#define PIFT_PIFT5_MASK                 32U
#define PIFT_PIFT6_MASK                 64U
#define PIFT_PIFT7_MASK                 128U


/*** PIES - Port S Interrupt Enable Register; 0x0000028A ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte PIES5       :1;                                       /* Port S interrupt enable bit 5 */
    byte PIES6       :1;                                       /* Port S interrupt enable bit 6 */
    byte             :1; 
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte grpPIES_5 :2;
    byte         :1;
  } MergedBits;
} PIESSTR;
extern volatile PIESSTR _PIES @(REG_BASE + 0x0000028AUL);
#define PIES                            _PIES.Byte
#define PIES_PIES5                      _PIES.Bits.PIES5
#define PIES_PIES6                      _PIES.Bits.PIES6
#define PIES_PIES_5                     _PIES.MergedBits.grpPIES_5

#define PIES_PIES5_MASK                 32U
#define PIES_PIES6_MASK                 64U
#define PIES_PIES_5_MASK                96U
#define PIES_PIES_5_BITNUM              5U


/*** PIFS - Port S Interrupt Flag Register; 0x0000028B ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte PIFS5       :1;                                       /* Port S interrupt flag bit 5 */
    byte PIFS6       :1;                                       /* Port S interrupt flag bit 6 */
    byte             :1; 
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte grpPIFS_5 :2;
    byte         :1;
  } MergedBits;
} PIFSSTR;
extern volatile PIFSSTR _PIFS @(REG_BASE + 0x0000028BUL);
#define PIFS                            _PIFS.Byte
#define PIFS_PIFS5                      _PIFS.Bits.PIFS5
#define PIFS_PIFS6                      _PIFS.Bits.PIFS6
#define PIFS_PIFS_5                     _PIFS.MergedBits.grpPIFS_5

#define PIFS_PIFS5_MASK                 32U
#define PIFS_PIFS6_MASK                 64U
#define PIFS_PIFS_5_MASK                96U
#define PIFS_PIFS_5_BITNUM              5U


/*** PIE1AD - Port AD Interrupt Enable Register; 0x0000028C ***/
typedef union {
  byte Byte;
  struct {
    byte PIE1AD0     :1;                                       /* Port AD Interrupt Enable Bit 0 */
    byte PIE1AD1     :1;                                       /* Port AD Interrupt Enable Bit 1 */
    byte PIE1AD2     :1;                                       /* Port AD Interrupt Enable Bit 2 */
    byte PIE1AD3     :1;                                       /* Port AD Interrupt Enable Bit 3 */
    byte PIE1AD4     :1;                                       /* Port AD Interrupt Enable Bit 4 */
    byte PIE1AD5     :1;                                       /* Port AD Interrupt Enable Bit 5 */
    byte PIE1AD6     :1;                                       /* Port AD Interrupt Enable Bit 6 */
    byte PIE1AD7     :1;                                       /* Port AD Interrupt Enable Bit 7 */
  } Bits;
} PIE1ADSTR;
extern volatile PIE1ADSTR _PIE1AD @(REG_BASE + 0x0000028CUL);
#define PIE1AD                          _PIE1AD.Byte
#define PIE1AD_PIE1AD0                  _PIE1AD.Bits.PIE1AD0
#define PIE1AD_PIE1AD1                  _PIE1AD.Bits.PIE1AD1
#define PIE1AD_PIE1AD2                  _PIE1AD.Bits.PIE1AD2
#define PIE1AD_PIE1AD3                  _PIE1AD.Bits.PIE1AD3
#define PIE1AD_PIE1AD4                  _PIE1AD.Bits.PIE1AD4
#define PIE1AD_PIE1AD5                  _PIE1AD.Bits.PIE1AD5
#define PIE1AD_PIE1AD6                  _PIE1AD.Bits.PIE1AD6
#define PIE1AD_PIE1AD7                  _PIE1AD.Bits.PIE1AD7

#define PIE1AD_PIE1AD0_MASK             1U
#define PIE1AD_PIE1AD1_MASK             2U
#define PIE1AD_PIE1AD2_MASK             4U
#define PIE1AD_PIE1AD3_MASK             8U
#define PIE1AD_PIE1AD4_MASK             16U
#define PIE1AD_PIE1AD5_MASK             32U
#define PIE1AD_PIE1AD6_MASK             64U
#define PIE1AD_PIE1AD7_MASK             128U


/*** PIF1AD - Port AD Interrupt Flag Register; 0x0000028D ***/
typedef union {
  byte Byte;
  struct {
    byte PIF1AD0     :1;                                       /* Port AD Bit 0 */
    byte PIF1AD1     :1;                                       /* Port AD Bit 1 */
    byte PIF1AD2     :1;                                       /* Port AD Bit 2 */
    byte PIF1AD3     :1;                                       /* Port AD Bit 3 */
    byte PIF1AD4     :1;                                       /* Port AD Bit 4 */
    byte PIF1AD5     :1;                                       /* Port AD Bit 5 */
    byte PIF1AD6     :1;                                       /* Port AD Bit 6 */
    byte PIF1AD7     :1;                                       /* Port AD Bit 7 */
  } Bits;
} PIF1ADSTR;
extern volatile PIF1ADSTR _PIF1AD @(REG_BASE + 0x0000028DUL);
#define PIF1AD                          _PIF1AD.Byte
#define PIF1AD_PIF1AD0                  _PIF1AD.Bits.PIF1AD0
#define PIF1AD_PIF1AD1                  _PIF1AD.Bits.PIF1AD1
#define PIF1AD_PIF1AD2                  _PIF1AD.Bits.PIF1AD2
#define PIF1AD_PIF1AD3                  _PIF1AD.Bits.PIF1AD3
#define PIF1AD_PIF1AD4                  _PIF1AD.Bits.PIF1AD4
#define PIF1AD_PIF1AD5                  _PIF1AD.Bits.PIF1AD5
#define PIF1AD_PIF1AD6                  _PIF1AD.Bits.PIF1AD6
#define PIF1AD_PIF1AD7                  _PIF1AD.Bits.PIF1AD7

#define PIF1AD_PIF1AD0_MASK             1U
#define PIF1AD_PIF1AD1_MASK             2U
#define PIF1AD_PIF1AD2_MASK             4U
#define PIF1AD_PIF1AD3_MASK             8U
#define PIF1AD_PIF1AD4_MASK             16U
#define PIF1AD_PIF1AD5_MASK             32U
#define PIF1AD_PIF1AD6_MASK             64U
#define PIF1AD_PIF1AD7_MASK             128U


/*** PIER - Port R Interrupt Enable Register; 0x0000028E ***/
typedef union {
  byte Byte;
  struct {
    byte PIER0       :1;                                       /* Port R interrupt enable bit 0 */
    byte PIER1       :1;                                       /* Port R interrupt enable bit 1 */
    byte PIER2       :1;                                       /* Port R interrupt enable bit 2 */
    byte PIER3       :1;                                       /* Port R interrupt enable bit 3 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPIER :4;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} PIERSTR;
extern volatile PIERSTR _PIER @(REG_BASE + 0x0000028EUL);
#define PIER                            _PIER.Byte
#define PIER_PIER0                      _PIER.Bits.PIER0
#define PIER_PIER1                      _PIER.Bits.PIER1
#define PIER_PIER2                      _PIER.Bits.PIER2
#define PIER_PIER3                      _PIER.Bits.PIER3
#define PIER_PIER                       _PIER.MergedBits.grpPIER

#define PIER_PIER0_MASK                 1U
#define PIER_PIER1_MASK                 2U
#define PIER_PIER2_MASK                 4U
#define PIER_PIER3_MASK                 8U
#define PIER_PIER_MASK                  15U
#define PIER_PIER_BITNUM                0U


/*** PIFR - Port R Interrupt Flag Register; 0x0000028F ***/
typedef union {
  byte Byte;
  struct {
    byte PIFR0       :1;                                       /* Port R interrupt flag bit 0 */
    byte PIFR1       :1;                                       /* Port R interrupt flag bit 1 */
    byte PIFR2       :1;                                       /* Port R interrupt flag bit 2 */
    byte PIFR3       :1;                                       /* Port R interrupt flag bit 3 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPIFR :4;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} PIFRSTR;
extern volatile PIFRSTR _PIFR @(REG_BASE + 0x0000028FUL);
#define PIFR                            _PIFR.Byte
#define PIFR_PIFR0                      _PIFR.Bits.PIFR0
#define PIFR_PIFR1                      _PIFR.Bits.PIFR1
#define PIFR_PIFR2                      _PIFR.Bits.PIFR2
#define PIFR_PIFR3                      _PIFR.Bits.PIFR3
#define PIFR_PIFR                       _PIFR.MergedBits.grpPIFR

#define PIFR_PIFR0_MASK                 1U
#define PIFR_PIFR1_MASK                 2U
#define PIFR_PIFR2_MASK                 4U
#define PIFR_PIFR3_MASK                 8U
#define PIFR_PIFR_MASK                  15U
#define PIFR_PIFR_BITNUM                0U


/*** PTU - Port U Data Register; 0x00000290 ***/
typedef union {
  byte Byte;
  struct {
    byte PTU0        :1;                                       /* Port U general purpose input/output data bit 0 */
    byte PTU1        :1;                                       /* Port U general purpose input/output data bit 1 */
    byte PTU2        :1;                                       /* Port U general purpose input/output data bit 2 */
    byte PTU3        :1;                                       /* Port U general purpose input/output data bit 3 */
    byte PTU4        :1;                                       /* Port U general purpose input/output data bit 4 */
    byte PTU5        :1;                                       /* Port U general purpose input/output data bit 5 */
    byte PTU6        :1;                                       /* Port U general purpose input/output data bit 6 */
    byte PTU7        :1;                                       /* Port U general purpose input/output data bit 7 */
  } Bits;
} PTUSTR;
extern volatile PTUSTR _PTU @(REG_BASE + 0x00000290UL);
#define PTU                             _PTU.Byte
#define PTU_PTU0                        _PTU.Bits.PTU0
#define PTU_PTU1                        _PTU.Bits.PTU1
#define PTU_PTU2                        _PTU.Bits.PTU2
#define PTU_PTU3                        _PTU.Bits.PTU3
#define PTU_PTU4                        _PTU.Bits.PTU4
#define PTU_PTU5                        _PTU.Bits.PTU5
#define PTU_PTU6                        _PTU.Bits.PTU6
#define PTU_PTU7                        _PTU.Bits.PTU7

#define PTU_PTU0_MASK                   1U
#define PTU_PTU1_MASK                   2U
#define PTU_PTU2_MASK                   4U
#define PTU_PTU3_MASK                   8U
#define PTU_PTU4_MASK                   16U
#define PTU_PTU5_MASK                   32U
#define PTU_PTU6_MASK                   64U
#define PTU_PTU7_MASK                   128U


/*** PTIU - Port U Input Register; 0x00000291 ***/
typedef union {
  byte Byte;
  struct {
    byte PTIU0       :1;                                       /* Port U input data bit 0 */
    byte PTIU1       :1;                                       /* Port U input data bit 1 */
    byte PTIU2       :1;                                       /* Port U input data bit 2 */
    byte PTIU3       :1;                                       /* Port U input data bit 3 */
    byte PTIU4       :1;                                       /* Port U input data bit 4 */
    byte PTIU5       :1;                                       /* Port U input data bit 5 */
    byte PTIU6       :1;                                       /* Port U input data bit 6 */
    byte PTIU7       :1;                                       /* Port U input data bit 7 */
  } Bits;
} PTIUSTR;
extern volatile PTIUSTR _PTIU @(REG_BASE + 0x00000291UL);
#define PTIU                            _PTIU.Byte
#define PTIU_PTIU0                      _PTIU.Bits.PTIU0
#define PTIU_PTIU1                      _PTIU.Bits.PTIU1
#define PTIU_PTIU2                      _PTIU.Bits.PTIU2
#define PTIU_PTIU3                      _PTIU.Bits.PTIU3
#define PTIU_PTIU4                      _PTIU.Bits.PTIU4
#define PTIU_PTIU5                      _PTIU.Bits.PTIU5
#define PTIU_PTIU6                      _PTIU.Bits.PTIU6
#define PTIU_PTIU7                      _PTIU.Bits.PTIU7

#define PTIU_PTIU0_MASK                 1U
#define PTIU_PTIU1_MASK                 2U
#define PTIU_PTIU2_MASK                 4U
#define PTIU_PTIU3_MASK                 8U
#define PTIU_PTIU4_MASK                 16U
#define PTIU_PTIU5_MASK                 32U
#define PTIU_PTIU6_MASK                 64U
#define PTIU_PTIU7_MASK                 128U


/*** DDRU - Port U Data Direction Register; 0x00000292 ***/
typedef union {
  byte Byte;
  struct {
    byte DDRU0       :1;                                       /* Port U data direction bit 0 */
    byte DDRU1       :1;                                       /* Port U data direction bit 1 */
    byte DDRU2       :1;                                       /* Port U data direction bit 2 */
    byte DDRU3       :1;                                       /* Port U data direction bit 3 */
    byte DDRU4       :1;                                       /* Port U data direction bit 4 */
    byte DDRU5       :1;                                       /* Port U data direction bit 5 */
    byte DDRU6       :1;                                       /* Port U data direction bit 6 */
    byte DDRU7       :1;                                       /* Port U data direction bit 7 */
  } Bits;
} DDRUSTR;
extern volatile DDRUSTR _DDRU @(REG_BASE + 0x00000292UL);
#define DDRU                            _DDRU.Byte
#define DDRU_DDRU0                      _DDRU.Bits.DDRU0
#define DDRU_DDRU1                      _DDRU.Bits.DDRU1
#define DDRU_DDRU2                      _DDRU.Bits.DDRU2
#define DDRU_DDRU3                      _DDRU.Bits.DDRU3
#define DDRU_DDRU4                      _DDRU.Bits.DDRU4
#define DDRU_DDRU5                      _DDRU.Bits.DDRU5
#define DDRU_DDRU6                      _DDRU.Bits.DDRU6
#define DDRU_DDRU7                      _DDRU.Bits.DDRU7

#define DDRU_DDRU0_MASK                 1U
#define DDRU_DDRU1_MASK                 2U
#define DDRU_DDRU2_MASK                 4U
#define DDRU_DDRU3_MASK                 8U
#define DDRU_DDRU4_MASK                 16U
#define DDRU_DDRU5_MASK                 32U
#define DDRU_DDRU6_MASK                 64U
#define DDRU_DDRU7_MASK                 128U


/*** PERU - Port U Pull Device Enable Register; 0x00000294 ***/
typedef union {
  byte Byte;
  struct {
    byte PERU0       :1;                                       /* Port U pull device enable bit 0 */
    byte PERU1       :1;                                       /* Port U pull device enable bit 1 */
    byte PERU2       :1;                                       /* Port U pull device enable bit 2 */
    byte PERU3       :1;                                       /* Port U pull device enable bit 3 */
    byte PERU4       :1;                                       /* Port U pull device enable bit 4 */
    byte PERU5       :1;                                       /* Port U pull device enable bit 5 */
    byte PERU6       :1;                                       /* Port U pull device enable bit 6 */
    byte PERU7       :1;                                       /* Port U pull device enable bit 7 */
  } Bits;
} PERUSTR;
extern volatile PERUSTR _PERU @(REG_BASE + 0x00000294UL);
#define PERU                            _PERU.Byte
#define PERU_PERU0                      _PERU.Bits.PERU0
#define PERU_PERU1                      _PERU.Bits.PERU1
#define PERU_PERU2                      _PERU.Bits.PERU2
#define PERU_PERU3                      _PERU.Bits.PERU3
#define PERU_PERU4                      _PERU.Bits.PERU4
#define PERU_PERU5                      _PERU.Bits.PERU5
#define PERU_PERU6                      _PERU.Bits.PERU6
#define PERU_PERU7                      _PERU.Bits.PERU7

#define PERU_PERU0_MASK                 1U
#define PERU_PERU1_MASK                 2U
#define PERU_PERU2_MASK                 4U
#define PERU_PERU3_MASK                 8U
#define PERU_PERU4_MASK                 16U
#define PERU_PERU5_MASK                 32U
#define PERU_PERU6_MASK                 64U
#define PERU_PERU7_MASK                 128U


/*** PPSU - Port U Polarity Select Register; 0x00000295 ***/
typedef union {
  byte Byte;
  struct {
    byte PPSU0       :1;                                       /* Port U pull device select bit 0 */
    byte PPSU1       :1;                                       /* Port U pull device select bit 1 */
    byte PPSU2       :1;                                       /* Port U pull device select bit 2 */
    byte PPSU3       :1;                                       /* Port U pull device select bit 3 */
    byte PPSU4       :1;                                       /* Port U pull device select bit 4 */
    byte PPSU5       :1;                                       /* Port U pull device select bit 5 */
    byte PPSU6       :1;                                       /* Port U pull device select bit 6 */
    byte PPSU7       :1;                                       /* Port U pull device select bit 7 */
  } Bits;
} PPSUSTR;
extern volatile PPSUSTR _PPSU @(REG_BASE + 0x00000295UL);
#define PPSU                            _PPSU.Byte
#define PPSU_PPSU0                      _PPSU.Bits.PPSU0
#define PPSU_PPSU1                      _PPSU.Bits.PPSU1
#define PPSU_PPSU2                      _PPSU.Bits.PPSU2
#define PPSU_PPSU3                      _PPSU.Bits.PPSU3
#define PPSU_PPSU4                      _PPSU.Bits.PPSU4
#define PPSU_PPSU5                      _PPSU.Bits.PPSU5
#define PPSU_PPSU6                      _PPSU.Bits.PPSU6
#define PPSU_PPSU7                      _PPSU.Bits.PPSU7

#define PPSU_PPSU0_MASK                 1U
#define PPSU_PPSU1_MASK                 2U
#define PPSU_PPSU2_MASK                 4U
#define PPSU_PPSU3_MASK                 8U
#define PPSU_PPSU4_MASK                 16U
#define PPSU_PPSU5_MASK                 32U
#define PPSU_PPSU6_MASK                 64U
#define PPSU_PPSU7_MASK                 128U


/*** SRRU - Port U Slew Rate Register; 0x00000296 ***/
typedef union {
  byte Byte;
  struct {
    byte SRRU0       :1;                                       /* Slew rate port U bit 0 */
    byte SRRU1       :1;                                       /* Slew rate port U bit 1 */
    byte SRRU2       :1;                                       /* Slew rate port U bit 2 */
    byte SRRU3       :1;                                       /* Slew rate port U bit 3 */
    byte SRRU4       :1;                                       /* Slew rate port U bit 4 */
    byte SRRU5       :1;                                       /* Slew rate port U bit 5 */
    byte SRRU6       :1;                                       /* Slew rate port U bit 6 */
    byte SRRU7       :1;                                       /* Slew rate port U bit 7 */
  } Bits;
} SRRUSTR;
extern volatile SRRUSTR _SRRU @(REG_BASE + 0x00000296UL);
#define SRRU                            _SRRU.Byte
#define SRRU_SRRU0                      _SRRU.Bits.SRRU0
#define SRRU_SRRU1                      _SRRU.Bits.SRRU1
#define SRRU_SRRU2                      _SRRU.Bits.SRRU2
#define SRRU_SRRU3                      _SRRU.Bits.SRRU3
#define SRRU_SRRU4                      _SRRU.Bits.SRRU4
#define SRRU_SRRU5                      _SRRU.Bits.SRRU5
#define SRRU_SRRU6                      _SRRU.Bits.SRRU6
#define SRRU_SRRU7                      _SRRU.Bits.SRRU7

#define SRRU_SRRU0_MASK                 1U
#define SRRU_SRRU1_MASK                 2U
#define SRRU_SRRU2_MASK                 4U
#define SRRU_SRRU3_MASK                 8U
#define SRRU_SRRU4_MASK                 16U
#define SRRU_SRRU5_MASK                 32U
#define SRRU_SRRU6_MASK                 64U
#define SRRU_SRRU7_MASK                 128U


/*** PTV - Port V Data Register; 0x00000298 ***/
typedef union {
  byte Byte;
  struct {
    byte PTV0        :1;                                       /* Port V general purpose input/output data bit 0 */
    byte PTV1        :1;                                       /* Port V general purpose input/output data bit 1 */
    byte PTV2        :1;                                       /* Port V general purpose input/output data bit 2 */
    byte PTV3        :1;                                       /* Port V general purpose input/output data bit 3 */
    byte PTV4        :1;                                       /* Port V general purpose input/output data bit 4 */
    byte PTV5        :1;                                       /* Port V general purpose input/output data bit 5 */
    byte PTV6        :1;                                       /* Port V general purpose input/output data bit 6 */
    byte PTV7        :1;                                       /* Port V general purpose input/output data bit 7 */
  } Bits;
} PTVSTR;
extern volatile PTVSTR _PTV @(REG_BASE + 0x00000298UL);
#define PTV                             _PTV.Byte
#define PTV_PTV0                        _PTV.Bits.PTV0
#define PTV_PTV1                        _PTV.Bits.PTV1
#define PTV_PTV2                        _PTV.Bits.PTV2
#define PTV_PTV3                        _PTV.Bits.PTV3
#define PTV_PTV4                        _PTV.Bits.PTV4
#define PTV_PTV5                        _PTV.Bits.PTV5
#define PTV_PTV6                        _PTV.Bits.PTV6
#define PTV_PTV7                        _PTV.Bits.PTV7

#define PTV_PTV0_MASK                   1U
#define PTV_PTV1_MASK                   2U
#define PTV_PTV2_MASK                   4U
#define PTV_PTV3_MASK                   8U
#define PTV_PTV4_MASK                   16U
#define PTV_PTV5_MASK                   32U
#define PTV_PTV6_MASK                   64U
#define PTV_PTV7_MASK                   128U


/*** PTIV - Port V Input Register; 0x00000299 ***/
typedef union {
  byte Byte;
  struct {
    byte PTIV0       :1;                                       /* Port V input data bit 0 */
    byte PTIV1       :1;                                       /* Port V input data bit 1 */
    byte PTIV2       :1;                                       /* Port V input data bit 2 */
    byte PTIV3       :1;                                       /* Port V input data bit 3 */
    byte PTIV4       :1;                                       /* Port V input data bit 4 */
    byte PTIV5       :1;                                       /* Port V input data bit 5 */
    byte PTIV6       :1;                                       /* Port V input data bit 6 */
    byte PTIV7       :1;                                       /* Port V input data bit 7 */
  } Bits;
} PTIVSTR;
extern volatile PTIVSTR _PTIV @(REG_BASE + 0x00000299UL);
#define PTIV                            _PTIV.Byte
#define PTIV_PTIV0                      _PTIV.Bits.PTIV0
#define PTIV_PTIV1                      _PTIV.Bits.PTIV1
#define PTIV_PTIV2                      _PTIV.Bits.PTIV2
#define PTIV_PTIV3                      _PTIV.Bits.PTIV3
#define PTIV_PTIV4                      _PTIV.Bits.PTIV4
#define PTIV_PTIV5                      _PTIV.Bits.PTIV5
#define PTIV_PTIV6                      _PTIV.Bits.PTIV6
#define PTIV_PTIV7                      _PTIV.Bits.PTIV7

#define PTIV_PTIV0_MASK                 1U
#define PTIV_PTIV1_MASK                 2U
#define PTIV_PTIV2_MASK                 4U
#define PTIV_PTIV3_MASK                 8U
#define PTIV_PTIV4_MASK                 16U
#define PTIV_PTIV5_MASK                 32U
#define PTIV_PTIV6_MASK                 64U
#define PTIV_PTIV7_MASK                 128U


/*** DDRV - Port V Data Direction Register; 0x0000029A ***/
typedef union {
  byte Byte;
  struct {
    byte DDRV0       :1;                                       /* Port V data direction bit 0 */
    byte DDRV1       :1;                                       /* Port V data direction bit 1 */
    byte DDRV2       :1;                                       /* Port V data direction bit 2 */
    byte DDRV3       :1;                                       /* Port V data direction bit 3 */
    byte DDRV4       :1;                                       /* Port V data direction bit 4 */
    byte DDRV5       :1;                                       /* Port V data direction bit 5 */
    byte DDRV6       :1;                                       /* Port V data direction bit 6 */
    byte DDRV7       :1;                                       /* Port V data direction bit 7 */
  } Bits;
} DDRVSTR;
extern volatile DDRVSTR _DDRV @(REG_BASE + 0x0000029AUL);
#define DDRV                            _DDRV.Byte
#define DDRV_DDRV0                      _DDRV.Bits.DDRV0
#define DDRV_DDRV1                      _DDRV.Bits.DDRV1
#define DDRV_DDRV2                      _DDRV.Bits.DDRV2
#define DDRV_DDRV3                      _DDRV.Bits.DDRV3
#define DDRV_DDRV4                      _DDRV.Bits.DDRV4
#define DDRV_DDRV5                      _DDRV.Bits.DDRV5
#define DDRV_DDRV6                      _DDRV.Bits.DDRV6
#define DDRV_DDRV7                      _DDRV.Bits.DDRV7

#define DDRV_DDRV0_MASK                 1U
#define DDRV_DDRV1_MASK                 2U
#define DDRV_DDRV2_MASK                 4U
#define DDRV_DDRV3_MASK                 8U
#define DDRV_DDRV4_MASK                 16U
#define DDRV_DDRV5_MASK                 32U
#define DDRV_DDRV6_MASK                 64U
#define DDRV_DDRV7_MASK                 128U


/*** PERV - Port V Pull Device Enable Register; 0x0000029C ***/
typedef union {
  byte Byte;
  struct {
    byte PERV0       :1;                                       /* Port V pull device enable bit 0 */
    byte PERV1       :1;                                       /* Port V pull device enable bit 1 */
    byte PERV2       :1;                                       /* Port V pull device enable bit 2 */
    byte PERV3       :1;                                       /* Port V pull device enable bit 3 */
    byte PERV4       :1;                                       /* Port V pull device enable bit 4 */
    byte PERV5       :1;                                       /* Port V pull device enable bit 5 */
    byte PERV6       :1;                                       /* Port V pull device enable bit 6 */
    byte PERV7       :1;                                       /* Port V pull device enable bit 7 */
  } Bits;
} PERVSTR;
extern volatile PERVSTR _PERV @(REG_BASE + 0x0000029CUL);
#define PERV                            _PERV.Byte
#define PERV_PERV0                      _PERV.Bits.PERV0
#define PERV_PERV1                      _PERV.Bits.PERV1
#define PERV_PERV2                      _PERV.Bits.PERV2
#define PERV_PERV3                      _PERV.Bits.PERV3
#define PERV_PERV4                      _PERV.Bits.PERV4
#define PERV_PERV5                      _PERV.Bits.PERV5
#define PERV_PERV6                      _PERV.Bits.PERV6
#define PERV_PERV7                      _PERV.Bits.PERV7

#define PERV_PERV0_MASK                 1U
#define PERV_PERV1_MASK                 2U
#define PERV_PERV2_MASK                 4U
#define PERV_PERV3_MASK                 8U
#define PERV_PERV4_MASK                 16U
#define PERV_PERV5_MASK                 32U
#define PERV_PERV6_MASK                 64U
#define PERV_PERV7_MASK                 128U


/*** PPSV - Port V Polarity Select Register; 0x0000029D ***/
typedef union {
  byte Byte;
  struct {
    byte PPSV0       :1;                                       /* Port V pull device select bit 0 */
    byte PPSV1       :1;                                       /* Port V pull device select bit 1 */
    byte PPSV2       :1;                                       /* Port V pull device select bit 2 */
    byte PPSV3       :1;                                       /* Port V pull device select bit 3 */
    byte PPSV4       :1;                                       /* Port V pull device select bit 4 */
    byte PPSV5       :1;                                       /* Port V pull device select bit 5 */
    byte PPSV6       :1;                                       /* Port V pull device select bit 6 */
    byte PPSV7       :1;                                       /* Port V pull device select bit 7 */
  } Bits;
} PPSVSTR;
extern volatile PPSVSTR _PPSV @(REG_BASE + 0x0000029DUL);
#define PPSV                            _PPSV.Byte
#define PPSV_PPSV0                      _PPSV.Bits.PPSV0
#define PPSV_PPSV1                      _PPSV.Bits.PPSV1
#define PPSV_PPSV2                      _PPSV.Bits.PPSV2
#define PPSV_PPSV3                      _PPSV.Bits.PPSV3
#define PPSV_PPSV4                      _PPSV.Bits.PPSV4
#define PPSV_PPSV5                      _PPSV.Bits.PPSV5
#define PPSV_PPSV6                      _PPSV.Bits.PPSV6
#define PPSV_PPSV7                      _PPSV.Bits.PPSV7

#define PPSV_PPSV0_MASK                 1U
#define PPSV_PPSV1_MASK                 2U
#define PPSV_PPSV2_MASK                 4U
#define PPSV_PPSV3_MASK                 8U
#define PPSV_PPSV4_MASK                 16U
#define PPSV_PPSV5_MASK                 32U
#define PPSV_PPSV6_MASK                 64U
#define PPSV_PPSV7_MASK                 128U


/*** SRRV - Port V Slew Rate Register; 0x0000029E ***/
typedef union {
  byte Byte;
  struct {
    byte SRRV0       :1;                                       /* Slew rate port V bit 0 */
    byte SRRV1       :1;                                       /* Slew rate port V bit 1 */
    byte SRRV2       :1;                                       /* Slew rate port V bit 2 */
    byte SRRV3       :1;                                       /* Slew rate port V bit 3 */
    byte SRRV4       :1;                                       /* Slew rate port V bit 4 */
    byte SRRV5       :1;                                       /* Slew rate port V bit 5 */
    byte SRRV6       :1;                                       /* Slew rate port V bit 6 */
    byte SRRV7       :1;                                       /* Slew rate port V bit 7 */
  } Bits;
} SRRVSTR;
extern volatile SRRVSTR _SRRV @(REG_BASE + 0x0000029EUL);
#define SRRV                            _SRRV.Byte
#define SRRV_SRRV0                      _SRRV.Bits.SRRV0
#define SRRV_SRRV1                      _SRRV.Bits.SRRV1
#define SRRV_SRRV2                      _SRRV.Bits.SRRV2
#define SRRV_SRRV3                      _SRRV.Bits.SRRV3
#define SRRV_SRRV4                      _SRRV.Bits.SRRV4
#define SRRV_SRRV5                      _SRRV.Bits.SRRV5
#define SRRV_SRRV6                      _SRRV.Bits.SRRV6
#define SRRV_SRRV7                      _SRRV.Bits.SRRV7

#define SRRV_SRRV0_MASK                 1U
#define SRRV_SRRV1_MASK                 2U
#define SRRV_SRRV2_MASK                 4U
#define SRRV_SRRV3_MASK                 8U
#define SRRV_SRRV4_MASK                 16U
#define SRRV_SRRV5_MASK                 32U
#define SRRV_SRRV6_MASK                 64U
#define SRRV_SRRV7_MASK                 128U


/*** TIM1_TIOS - Timer Input Capture/Output Compare Select; 0x000002A0 ***/
typedef union {
  byte Byte;
  struct {
    byte IOS0        :1;                                       /* Input Capture or Output Compare Channel Configuration Bit 0 */
    byte IOS1        :1;                                       /* Input Capture or Output Compare Channel Configuration Bit 1 */
    byte IOS2        :1;                                       /* Input Capture or Output Compare Channel Configuration Bit 2 */
    byte IOS3        :1;                                       /* Input Capture or Output Compare Channel Configuration Bit 3 */
    byte IOS4        :1;                                       /* Input Capture or Output Compare Channel Configuration Bit 4 */
    byte IOS5        :1;                                       /* Input Capture or Output Compare Channel Configuration Bit 5 */
    byte IOS6        :1;                                       /* Input Capture or Output Compare Channel Configuration Bit 6 */
    byte IOS7        :1;                                       /* Input Capture or Output Compare Channel Configuration Bit 7 */
  } Bits;
} TIM1_TIOSSTR;
extern volatile TIM1_TIOSSTR _TIM1_TIOS @(REG_BASE + 0x000002A0UL);
#define TIM1_TIOS                       _TIM1_TIOS.Byte
#define TIM1_TIOS_IOS0                  _TIM1_TIOS.Bits.IOS0
#define TIM1_TIOS_IOS1                  _TIM1_TIOS.Bits.IOS1
#define TIM1_TIOS_IOS2                  _TIM1_TIOS.Bits.IOS2
#define TIM1_TIOS_IOS3                  _TIM1_TIOS.Bits.IOS3
#define TIM1_TIOS_IOS4                  _TIM1_TIOS.Bits.IOS4
#define TIM1_TIOS_IOS5                  _TIM1_TIOS.Bits.IOS5
#define TIM1_TIOS_IOS6                  _TIM1_TIOS.Bits.IOS6
#define TIM1_TIOS_IOS7                  _TIM1_TIOS.Bits.IOS7

#define TIM1_TIOS_IOS0_MASK             1U
#define TIM1_TIOS_IOS1_MASK             2U
#define TIM1_TIOS_IOS2_MASK             4U
#define TIM1_TIOS_IOS3_MASK             8U
#define TIM1_TIOS_IOS4_MASK             16U
#define TIM1_TIOS_IOS5_MASK             32U
#define TIM1_TIOS_IOS6_MASK             64U
#define TIM1_TIOS_IOS7_MASK             128U


/*** TIM1_CFORC - Timer Compare Force Register; 0x000002A1 ***/
typedef union {
  byte Byte;
  struct {
    byte FOC0        :1;                                       /* Force Output Compare Action for Channel 0 */
    byte FOC1        :1;                                       /* Force Output Compare Action for Channel 1 */
    byte FOC2        :1;                                       /* Force Output Compare Action for Channel 2 */
    byte FOC3        :1;                                       /* Force Output Compare Action for Channel 3 */
    byte FOC4        :1;                                       /* Force Output Compare Action for Channel 4 */
    byte FOC5        :1;                                       /* Force Output Compare Action for Channel 5 */
    byte FOC6        :1;                                       /* Force Output Compare Action for Channel 6 */
    byte FOC7        :1;                                       /* Force Output Compare Action for Channel 7 */
  } Bits;
} TIM1_CFORCSTR;
extern volatile TIM1_CFORCSTR _TIM1_CFORC @(REG_BASE + 0x000002A1UL);
#define TIM1_CFORC                      _TIM1_CFORC.Byte
#define TIM1_CFORC_FOC0                 _TIM1_CFORC.Bits.FOC0
#define TIM1_CFORC_FOC1                 _TIM1_CFORC.Bits.FOC1
#define TIM1_CFORC_FOC2                 _TIM1_CFORC.Bits.FOC2
#define TIM1_CFORC_FOC3                 _TIM1_CFORC.Bits.FOC3
#define TIM1_CFORC_FOC4                 _TIM1_CFORC.Bits.FOC4
#define TIM1_CFORC_FOC5                 _TIM1_CFORC.Bits.FOC5
#define TIM1_CFORC_FOC6                 _TIM1_CFORC.Bits.FOC6
#define TIM1_CFORC_FOC7                 _TIM1_CFORC.Bits.FOC7

#define TIM1_CFORC_FOC0_MASK            1U
#define TIM1_CFORC_FOC1_MASK            2U
#define TIM1_CFORC_FOC2_MASK            4U
#define TIM1_CFORC_FOC3_MASK            8U
#define TIM1_CFORC_FOC4_MASK            16U
#define TIM1_CFORC_FOC5_MASK            32U
#define TIM1_CFORC_FOC6_MASK            64U
#define TIM1_CFORC_FOC7_MASK            128U


/*** TIM1_OC7M - Output Compare 7 Mask Register; 0x000002A2 ***/
typedef union {
  byte Byte;
  struct {
    byte OC7M0       :1;                                       /* Output Compare 7 Mask Bit 0 */
    byte OC7M1       :1;                                       /* Output Compare 7 Mask Bit 1 */
    byte OC7M2       :1;                                       /* Output Compare 7 Mask Bit 2 */
    byte OC7M3       :1;                                       /* Output Compare 7 Mask Bit 3 */
    byte OC7M4       :1;                                       /* Output Compare 7 Mask Bit 4 */
    byte OC7M5       :1;                                       /* Output Compare 7 Mask Bit 5 */
    byte OC7M6       :1;                                       /* Output Compare 7 Mask Bit 6 */
    byte OC7M7       :1;                                       /* Output Compare 7 Mask Bit 7 */
  } Bits;
} TIM1_OC7MSTR;
extern volatile TIM1_OC7MSTR _TIM1_OC7M @(REG_BASE + 0x000002A2UL);
#define TIM1_OC7M                       _TIM1_OC7M.Byte
#define TIM1_OC7M_OC7M0                 _TIM1_OC7M.Bits.OC7M0
#define TIM1_OC7M_OC7M1                 _TIM1_OC7M.Bits.OC7M1
#define TIM1_OC7M_OC7M2                 _TIM1_OC7M.Bits.OC7M2
#define TIM1_OC7M_OC7M3                 _TIM1_OC7M.Bits.OC7M3
#define TIM1_OC7M_OC7M4                 _TIM1_OC7M.Bits.OC7M4
#define TIM1_OC7M_OC7M5                 _TIM1_OC7M.Bits.OC7M5
#define TIM1_OC7M_OC7M6                 _TIM1_OC7M.Bits.OC7M6
#define TIM1_OC7M_OC7M7                 _TIM1_OC7M.Bits.OC7M7

#define TIM1_OC7M_OC7M0_MASK            1U
#define TIM1_OC7M_OC7M1_MASK            2U
#define TIM1_OC7M_OC7M2_MASK            4U
#define TIM1_OC7M_OC7M3_MASK            8U
#define TIM1_OC7M_OC7M4_MASK            16U
#define TIM1_OC7M_OC7M5_MASK            32U
#define TIM1_OC7M_OC7M6_MASK            64U
#define TIM1_OC7M_OC7M7_MASK            128U


/*** TIM1_OC7D - Output Compare 7 Data Register; 0x000002A3 ***/
typedef union {
  byte Byte;
  struct {
    byte OC7D0       :1;                                       /* Output Compare 7 Bit 0 */
    byte OC7D1       :1;                                       /* Output Compare 7 Bit 1 */
    byte OC7D2       :1;                                       /* Output Compare 7 Bit 2 */
    byte OC7D3       :1;                                       /* Output Compare 7 Bit 3 */
    byte OC7D4       :1;                                       /* Output Compare 7 Bit 4 */
    byte OC7D5       :1;                                       /* Output Compare 7 Bit 5 */
    byte OC7D6       :1;                                       /* Output Compare 7 Bit 6 */
    byte OC7D7       :1;                                       /* Output Compare 7 Bit 7 */
  } Bits;
} TIM1_OC7DSTR;
extern volatile TIM1_OC7DSTR _TIM1_OC7D @(REG_BASE + 0x000002A3UL);
#define TIM1_OC7D                       _TIM1_OC7D.Byte
#define TIM1_OC7D_OC7D0                 _TIM1_OC7D.Bits.OC7D0
#define TIM1_OC7D_OC7D1                 _TIM1_OC7D.Bits.OC7D1
#define TIM1_OC7D_OC7D2                 _TIM1_OC7D.Bits.OC7D2
#define TIM1_OC7D_OC7D3                 _TIM1_OC7D.Bits.OC7D3
#define TIM1_OC7D_OC7D4                 _TIM1_OC7D.Bits.OC7D4
#define TIM1_OC7D_OC7D5                 _TIM1_OC7D.Bits.OC7D5
#define TIM1_OC7D_OC7D6                 _TIM1_OC7D.Bits.OC7D6
#define TIM1_OC7D_OC7D7                 _TIM1_OC7D.Bits.OC7D7

#define TIM1_OC7D_OC7D0_MASK            1U
#define TIM1_OC7D_OC7D1_MASK            2U
#define TIM1_OC7D_OC7D2_MASK            4U
#define TIM1_OC7D_OC7D3_MASK            8U
#define TIM1_OC7D_OC7D4_MASK            16U
#define TIM1_OC7D_OC7D5_MASK            32U
#define TIM1_OC7D_OC7D6_MASK            64U
#define TIM1_OC7D_OC7D7_MASK            128U


/*** TIM1_TCNT - Timer Count Register; 0x000002A4 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TIM1_TCNTHi - Timer Count Register High; 0x000002A4 ***/
    union {
      byte Byte;
    } TIM1_TCNTHiSTR;
    #define TIM1_TCNTHi                 _TIM1_TCNT.Overlap_STR.TIM1_TCNTHiSTR.Byte
    

    /*** TIM1_TCNTLo - Timer Count Register Low; 0x000002A5 ***/
    union {
      byte Byte;
    } TIM1_TCNTLoSTR;
    #define TIM1_TCNTLo                 _TIM1_TCNT.Overlap_STR.TIM1_TCNTLoSTR.Byte
    
  } Overlap_STR;

} TIM1_TCNTSTR;
extern volatile TIM1_TCNTSTR _TIM1_TCNT @(REG_BASE + 0x000002A4UL);
#define TIM1_TCNT                       _TIM1_TCNT.Word


/*** TIM1_TSCR1 - Timer System Control Register1; 0x000002A6 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte PRNT        :1;                                       /* Precision Timer */
    byte TFFCA       :1;                                       /* Timer Fast Flag Clear All */
    byte TSFRZ       :1;                                       /* Timer and Modulus Counter Stop While in Freeze Mode */
    byte TSWAI       :1;                                       /* Timer Module Stops While in Wait */
    byte TEN         :1;                                       /* Timer Enable */
  } Bits;
} TIM1_TSCR1STR;
extern volatile TIM1_TSCR1STR _TIM1_TSCR1 @(REG_BASE + 0x000002A6UL);
#define TIM1_TSCR1                      _TIM1_TSCR1.Byte
#define TIM1_TSCR1_PRNT                 _TIM1_TSCR1.Bits.PRNT
#define TIM1_TSCR1_TFFCA                _TIM1_TSCR1.Bits.TFFCA
#define TIM1_TSCR1_TSFRZ                _TIM1_TSCR1.Bits.TSFRZ
#define TIM1_TSCR1_TSWAI                _TIM1_TSCR1.Bits.TSWAI
#define TIM1_TSCR1_TEN                  _TIM1_TSCR1.Bits.TEN

#define TIM1_TSCR1_PRNT_MASK            8U
#define TIM1_TSCR1_TFFCA_MASK           16U
#define TIM1_TSCR1_TSFRZ_MASK           32U
#define TIM1_TSCR1_TSWAI_MASK           64U
#define TIM1_TSCR1_TEN_MASK             128U


/*** TIM1_TTOV - Timer Toggle On Overflow Register; 0x000002A7 ***/
typedef union {
  byte Byte;
  struct {
    byte TOV0        :1;                                       /* Toggle On Overflow Bit 0 */
    byte TOV1        :1;                                       /* Toggle On Overflow Bit 1 */
    byte TOV2        :1;                                       /* Toggle On Overflow Bit 2 */
    byte TOV3        :1;                                       /* Toggle On Overflow Bit 3 */
    byte TOV4        :1;                                       /* Toggle On Overflow Bit 4 */
    byte TOV5        :1;                                       /* Toggle On Overflow Bit 5 */
    byte TOV6        :1;                                       /* Toggle On Overflow Bit 6 */
    byte TOV7        :1;                                       /* Toggle On Overflow Bit 7 */
  } Bits;
} TIM1_TTOVSTR;
extern volatile TIM1_TTOVSTR _TIM1_TTOV @(REG_BASE + 0x000002A7UL);
#define TIM1_TTOV                       _TIM1_TTOV.Byte
#define TIM1_TTOV_TOV0                  _TIM1_TTOV.Bits.TOV0
#define TIM1_TTOV_TOV1                  _TIM1_TTOV.Bits.TOV1
#define TIM1_TTOV_TOV2                  _TIM1_TTOV.Bits.TOV2
#define TIM1_TTOV_TOV3                  _TIM1_TTOV.Bits.TOV3
#define TIM1_TTOV_TOV4                  _TIM1_TTOV.Bits.TOV4
#define TIM1_TTOV_TOV5                  _TIM1_TTOV.Bits.TOV5
#define TIM1_TTOV_TOV6                  _TIM1_TTOV.Bits.TOV6
#define TIM1_TTOV_TOV7                  _TIM1_TTOV.Bits.TOV7

#define TIM1_TTOV_TOV0_MASK             1U
#define TIM1_TTOV_TOV1_MASK             2U
#define TIM1_TTOV_TOV2_MASK             4U
#define TIM1_TTOV_TOV3_MASK             8U
#define TIM1_TTOV_TOV4_MASK             16U
#define TIM1_TTOV_TOV5_MASK             32U
#define TIM1_TTOV_TOV6_MASK             64U
#define TIM1_TTOV_TOV7_MASK             128U


/*** TIM1_TCTL1 - Timer Control Register 1; 0x000002A8 ***/
typedef union {
  byte Byte;
  struct {
    byte OL4         :1;                                       /* Output Level Bit 4 */
    byte OM4         :1;                                       /* Output Mode Bit 4 */
    byte OL5         :1;                                       /* Output Level Bit 5 */
    byte OM5         :1;                                       /* Output Mode Bit 5 */
    byte OL6         :1;                                       /* Output Level Bit 6 */
    byte OM6         :1;                                       /* Output Mode Bit 6 */
    byte OL7         :1;                                       /* Output Level Bit 7 */
    byte OM7         :1;                                       /* Output Mode Bit 7 */
  } Bits;
} TIM1_TCTL1STR;
extern volatile TIM1_TCTL1STR _TIM1_TCTL1 @(REG_BASE + 0x000002A8UL);
#define TIM1_TCTL1                      _TIM1_TCTL1.Byte
#define TIM1_TCTL1_OL4                  _TIM1_TCTL1.Bits.OL4
#define TIM1_TCTL1_OM4                  _TIM1_TCTL1.Bits.OM4
#define TIM1_TCTL1_OL5                  _TIM1_TCTL1.Bits.OL5
#define TIM1_TCTL1_OM5                  _TIM1_TCTL1.Bits.OM5
#define TIM1_TCTL1_OL6                  _TIM1_TCTL1.Bits.OL6
#define TIM1_TCTL1_OM6                  _TIM1_TCTL1.Bits.OM6
#define TIM1_TCTL1_OL7                  _TIM1_TCTL1.Bits.OL7
#define TIM1_TCTL1_OM7                  _TIM1_TCTL1.Bits.OM7

#define TIM1_TCTL1_OL4_MASK             1U
#define TIM1_TCTL1_OM4_MASK             2U
#define TIM1_TCTL1_OL5_MASK             4U
#define TIM1_TCTL1_OM5_MASK             8U
#define TIM1_TCTL1_OL6_MASK             16U
#define TIM1_TCTL1_OM6_MASK             32U
#define TIM1_TCTL1_OL7_MASK             64U
#define TIM1_TCTL1_OM7_MASK             128U


/*** TIM1_TCTL2 - Timer Control Register 2; 0x000002A9 ***/
typedef union {
  byte Byte;
  struct {
    byte OL0         :1;                                       /* Output Level Bit 0 */
    byte OM0         :1;                                       /* Output Mode Bit 0 */
    byte OL1         :1;                                       /* Output Lecel Bit 1 */
    byte OM1         :1;                                       /* Output Mode Bit 1 */
    byte OL2         :1;                                       /* Output Level Bit 2 */
    byte OM2         :1;                                       /* Output Mode Bit 2 */
    byte OL3         :1;                                       /* Output Level Bit 3 */
    byte OM3         :1;                                       /* Output Mode Bit 3 */
  } Bits;
} TIM1_TCTL2STR;
extern volatile TIM1_TCTL2STR _TIM1_TCTL2 @(REG_BASE + 0x000002A9UL);
#define TIM1_TCTL2                      _TIM1_TCTL2.Byte
#define TIM1_TCTL2_OL0                  _TIM1_TCTL2.Bits.OL0
#define TIM1_TCTL2_OM0                  _TIM1_TCTL2.Bits.OM0
#define TIM1_TCTL2_OL1                  _TIM1_TCTL2.Bits.OL1
#define TIM1_TCTL2_OM1                  _TIM1_TCTL2.Bits.OM1
#define TIM1_TCTL2_OL2                  _TIM1_TCTL2.Bits.OL2
#define TIM1_TCTL2_OM2                  _TIM1_TCTL2.Bits.OM2
#define TIM1_TCTL2_OL3                  _TIM1_TCTL2.Bits.OL3
#define TIM1_TCTL2_OM3                  _TIM1_TCTL2.Bits.OM3

#define TIM1_TCTL2_OL0_MASK             1U
#define TIM1_TCTL2_OM0_MASK             2U
#define TIM1_TCTL2_OL1_MASK             4U
#define TIM1_TCTL2_OM1_MASK             8U
#define TIM1_TCTL2_OL2_MASK             16U
#define TIM1_TCTL2_OM2_MASK             32U
#define TIM1_TCTL2_OL3_MASK             64U
#define TIM1_TCTL2_OM3_MASK             128U


/*** TIM1_TCTL3 - Timer Control Register 3; 0x000002AA ***/
typedef union {
  byte Byte;
  struct {
    byte EDG4A       :1;                                       /* Input Capture Edge Control 4A */
    byte EDG4B       :1;                                       /* Input Capture Edge Control 4B */
    byte EDG5A       :1;                                       /* Input Capture Edge Control 5A */
    byte EDG5B       :1;                                       /* Input Capture Edge Control 5B */
    byte EDG6A       :1;                                       /* Input Capture Edge Control 6A */
    byte EDG6B       :1;                                       /* Input Capture Edge Control 6B */
    byte EDG7A       :1;                                       /* Input Capture Edge Control 7A */
    byte EDG7B       :1;                                       /* Input Capture Edge Control 7B */
  } Bits;
  struct {
    byte grpEDG4x :2;
    byte grpEDG5x :2;
    byte grpEDG6x :2;
    byte grpEDG7x :2;
  } MergedBits;
} TIM1_TCTL3STR;
extern volatile TIM1_TCTL3STR _TIM1_TCTL3 @(REG_BASE + 0x000002AAUL);
#define TIM1_TCTL3                      _TIM1_TCTL3.Byte
#define TIM1_TCTL3_EDG4A                _TIM1_TCTL3.Bits.EDG4A
#define TIM1_TCTL3_EDG4B                _TIM1_TCTL3.Bits.EDG4B
#define TIM1_TCTL3_EDG5A                _TIM1_TCTL3.Bits.EDG5A
#define TIM1_TCTL3_EDG5B                _TIM1_TCTL3.Bits.EDG5B
#define TIM1_TCTL3_EDG6A                _TIM1_TCTL3.Bits.EDG6A
#define TIM1_TCTL3_EDG6B                _TIM1_TCTL3.Bits.EDG6B
#define TIM1_TCTL3_EDG7A                _TIM1_TCTL3.Bits.EDG7A
#define TIM1_TCTL3_EDG7B                _TIM1_TCTL3.Bits.EDG7B
#define TIM1_TCTL3_EDG4x                _TIM1_TCTL3.MergedBits.grpEDG4x
#define TIM1_TCTL3_EDG5x                _TIM1_TCTL3.MergedBits.grpEDG5x
#define TIM1_TCTL3_EDG6x                _TIM1_TCTL3.MergedBits.grpEDG6x
#define TIM1_TCTL3_EDG7x                _TIM1_TCTL3.MergedBits.grpEDG7x

#define TIM1_TCTL3_EDG4A_MASK           1U
#define TIM1_TCTL3_EDG4B_MASK           2U
#define TIM1_TCTL3_EDG5A_MASK           4U
#define TIM1_TCTL3_EDG5B_MASK           8U
#define TIM1_TCTL3_EDG6A_MASK           16U
#define TIM1_TCTL3_EDG6B_MASK           32U
#define TIM1_TCTL3_EDG7A_MASK           64U
#define TIM1_TCTL3_EDG7B_MASK           128U
#define TIM1_TCTL3_EDG4x_MASK           3U
#define TIM1_TCTL3_EDG4x_BITNUM         0U
#define TIM1_TCTL3_EDG5x_MASK           12U
#define TIM1_TCTL3_EDG5x_BITNUM         2U
#define TIM1_TCTL3_EDG6x_MASK           48U
#define TIM1_TCTL3_EDG6x_BITNUM         4U
#define TIM1_TCTL3_EDG7x_MASK           192U
#define TIM1_TCTL3_EDG7x_BITNUM         6U


/*** TIM1_TCTL4 - Timer Control Register 4; 0x000002AB ***/
typedef union {
  byte Byte;
  struct {
    byte EDG0A       :1;                                       /* Input Capture Edge Control 0A */
    byte EDG0B       :1;                                       /* Input Capture Edge Control 0B */
    byte EDG1A       :1;                                       /* Input Capture Edge Control 1A */
    byte EDG1B       :1;                                       /* Input Capture Edge Control 1B */
    byte EDG2A       :1;                                       /* Input Capture Edge Control 2A */
    byte EDG2B       :1;                                       /* Input Capture Edge Control 2B */
    byte EDG3A       :1;                                       /* Input Capture Edge Control 3A */
    byte EDG3B       :1;                                       /* Input Capture Edge Control 3B */
  } Bits;
  struct {
    byte grpEDG0x :2;
    byte grpEDG1x :2;
    byte grpEDG2x :2;
    byte grpEDG3x :2;
  } MergedBits;
} TIM1_TCTL4STR;
extern volatile TIM1_TCTL4STR _TIM1_TCTL4 @(REG_BASE + 0x000002ABUL);
#define TIM1_TCTL4                      _TIM1_TCTL4.Byte
#define TIM1_TCTL4_EDG0A                _TIM1_TCTL4.Bits.EDG0A
#define TIM1_TCTL4_EDG0B                _TIM1_TCTL4.Bits.EDG0B
#define TIM1_TCTL4_EDG1A                _TIM1_TCTL4.Bits.EDG1A
#define TIM1_TCTL4_EDG1B                _TIM1_TCTL4.Bits.EDG1B
#define TIM1_TCTL4_EDG2A                _TIM1_TCTL4.Bits.EDG2A
#define TIM1_TCTL4_EDG2B                _TIM1_TCTL4.Bits.EDG2B
#define TIM1_TCTL4_EDG3A                _TIM1_TCTL4.Bits.EDG3A
#define TIM1_TCTL4_EDG3B                _TIM1_TCTL4.Bits.EDG3B
#define TIM1_TCTL4_EDG0x                _TIM1_TCTL4.MergedBits.grpEDG0x
#define TIM1_TCTL4_EDG1x                _TIM1_TCTL4.MergedBits.grpEDG1x
#define TIM1_TCTL4_EDG2x                _TIM1_TCTL4.MergedBits.grpEDG2x
#define TIM1_TCTL4_EDG3x                _TIM1_TCTL4.MergedBits.grpEDG3x

#define TIM1_TCTL4_EDG0A_MASK           1U
#define TIM1_TCTL4_EDG0B_MASK           2U
#define TIM1_TCTL4_EDG1A_MASK           4U
#define TIM1_TCTL4_EDG1B_MASK           8U
#define TIM1_TCTL4_EDG2A_MASK           16U
#define TIM1_TCTL4_EDG2B_MASK           32U
#define TIM1_TCTL4_EDG3A_MASK           64U
#define TIM1_TCTL4_EDG3B_MASK           128U
#define TIM1_TCTL4_EDG0x_MASK           3U
#define TIM1_TCTL4_EDG0x_BITNUM         0U
#define TIM1_TCTL4_EDG1x_MASK           12U
#define TIM1_TCTL4_EDG1x_BITNUM         2U
#define TIM1_TCTL4_EDG2x_MASK           48U
#define TIM1_TCTL4_EDG2x_BITNUM         4U
#define TIM1_TCTL4_EDG3x_MASK           192U
#define TIM1_TCTL4_EDG3x_BITNUM         6U


/*** TIM1_TIE - Timer Interrupt Enable Register; 0x000002AC ***/
typedef union {
  byte Byte;
  struct {
    byte C0I         :1;                                       /* Input Capture/Output Compare Interrupt Enable Bit 0 */
    byte C1I         :1;                                       /* Input Capture/Output Compare Interrupt Enable Bit 1 */
    byte C2I         :1;                                       /* Input Capture/Output Compare Interrupt Enable Bit 2 */
    byte C3I         :1;                                       /* Input Capture/Output Compare Interrupt Enable Bit 3 */
    byte C4I         :1;                                       /* Input Capture/Output Compare Interrupt Enable Bit 4 */
    byte C5I         :1;                                       /* Input Capture/Output Compare Interrupt Enable Bit 5 */
    byte C6I         :1;                                       /* Input Capture/Output Compare Interrupt Enable Bit 6 */
    byte C7I         :1;                                       /* Input Capture/Output Compare Interrupt Enable Bit 7 */
  } Bits;
} TIM1_TIESTR;
extern volatile TIM1_TIESTR _TIM1_TIE @(REG_BASE + 0x000002ACUL);
#define TIM1_TIE                        _TIM1_TIE.Byte
#define TIM1_TIE_C0I                    _TIM1_TIE.Bits.C0I
#define TIM1_TIE_C1I                    _TIM1_TIE.Bits.C1I
#define TIM1_TIE_C2I                    _TIM1_TIE.Bits.C2I
#define TIM1_TIE_C3I                    _TIM1_TIE.Bits.C3I
#define TIM1_TIE_C4I                    _TIM1_TIE.Bits.C4I
#define TIM1_TIE_C5I                    _TIM1_TIE.Bits.C5I
#define TIM1_TIE_C6I                    _TIM1_TIE.Bits.C6I
#define TIM1_TIE_C7I                    _TIM1_TIE.Bits.C7I

#define TIM1_TIE_C0I_MASK               1U
#define TIM1_TIE_C1I_MASK               2U
#define TIM1_TIE_C2I_MASK               4U
#define TIM1_TIE_C3I_MASK               8U
#define TIM1_TIE_C4I_MASK               16U
#define TIM1_TIE_C5I_MASK               32U
#define TIM1_TIE_C6I_MASK               64U
#define TIM1_TIE_C7I_MASK               128U


/*** TIM1_TSCR2 - Timer System Control Register 2; 0x000002AD ***/
typedef union {
  byte Byte;
  struct {
    byte PR0         :1;                                       /* Timer Prescaler Select Bit 0 */
    byte PR1         :1;                                       /* Timer Prescaler Select Bit 1 */
    byte PR2         :1;                                       /* Timer Prescaler Select Bit 2 */
    byte TCRE        :1;                                       /* Timer Counter Reset Enable */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte TOI         :1;                                       /* Timer Overflow Interrupt Enable */
  } Bits;
  struct {
    byte grpPR   :3;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} TIM1_TSCR2STR;
extern volatile TIM1_TSCR2STR _TIM1_TSCR2 @(REG_BASE + 0x000002ADUL);
#define TIM1_TSCR2                      _TIM1_TSCR2.Byte
#define TIM1_TSCR2_PR0                  _TIM1_TSCR2.Bits.PR0
#define TIM1_TSCR2_PR1                  _TIM1_TSCR2.Bits.PR1
#define TIM1_TSCR2_PR2                  _TIM1_TSCR2.Bits.PR2
#define TIM1_TSCR2_TCRE                 _TIM1_TSCR2.Bits.TCRE
#define TIM1_TSCR2_TOI                  _TIM1_TSCR2.Bits.TOI
#define TIM1_TSCR2_PR                   _TIM1_TSCR2.MergedBits.grpPR

#define TIM1_TSCR2_PR0_MASK             1U
#define TIM1_TSCR2_PR1_MASK             2U
#define TIM1_TSCR2_PR2_MASK             4U
#define TIM1_TSCR2_TCRE_MASK            8U
#define TIM1_TSCR2_TOI_MASK             128U
#define TIM1_TSCR2_PR_MASK              7U
#define TIM1_TSCR2_PR_BITNUM            0U


/*** TIM1_TFLG1 - Main Timer Interrupt Flag 1; 0x000002AE ***/
typedef union {
  byte Byte;
  struct {
    byte C0F         :1;                                       /* Input Capture/Output Compare Channel Flag 0 */
    byte C1F         :1;                                       /* Input Capture/Output Compare Channel Flag 1 */
    byte C2F         :1;                                       /* Input Capture/Output Compare Channel Flag 2 */
    byte C3F         :1;                                       /* Input Capture/Output Compare Channel Flag 3 */
    byte C4F         :1;                                       /* Input Capture/Output Compare Channel Flag 4 */
    byte C5F         :1;                                       /* Input Capture/Output Compare Channel Flag 5 */
    byte C6F         :1;                                       /* Input Capture/Output Compare Channel Flag 6 */
    byte C7F         :1;                                       /* Input Capture/Output Compare Channel Flag 7 */
  } Bits;
} TIM1_TFLG1STR;
extern volatile TIM1_TFLG1STR _TIM1_TFLG1 @(REG_BASE + 0x000002AEUL);
#define TIM1_TFLG1                      _TIM1_TFLG1.Byte
#define TIM1_TFLG1_C0F                  _TIM1_TFLG1.Bits.C0F
#define TIM1_TFLG1_C1F                  _TIM1_TFLG1.Bits.C1F
#define TIM1_TFLG1_C2F                  _TIM1_TFLG1.Bits.C2F
#define TIM1_TFLG1_C3F                  _TIM1_TFLG1.Bits.C3F
#define TIM1_TFLG1_C4F                  _TIM1_TFLG1.Bits.C4F
#define TIM1_TFLG1_C5F                  _TIM1_TFLG1.Bits.C5F
#define TIM1_TFLG1_C6F                  _TIM1_TFLG1.Bits.C6F
#define TIM1_TFLG1_C7F                  _TIM1_TFLG1.Bits.C7F

#define TIM1_TFLG1_C0F_MASK             1U
#define TIM1_TFLG1_C1F_MASK             2U
#define TIM1_TFLG1_C2F_MASK             4U
#define TIM1_TFLG1_C3F_MASK             8U
#define TIM1_TFLG1_C4F_MASK             16U
#define TIM1_TFLG1_C5F_MASK             32U
#define TIM1_TFLG1_C6F_MASK             64U
#define TIM1_TFLG1_C7F_MASK             128U


/*** TIM1_TFLG2 - Main Timer Interrupt Flag 2; 0x000002AF ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte TOF         :1;                                       /* Timer Overflow Flag */
  } Bits;
} TIM1_TFLG2STR;
extern volatile TIM1_TFLG2STR _TIM1_TFLG2 @(REG_BASE + 0x000002AFUL);
#define TIM1_TFLG2                      _TIM1_TFLG2.Byte
#define TIM1_TFLG2_TOF                  _TIM1_TFLG2.Bits.TOF

#define TIM1_TFLG2_TOF_MASK             128U


/*** TIM1_TC0 - Timer Input Capture/Output Compare Register 0; 0x000002B0 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TIM1_TC0Hi - Timer Input Capture/Output Compare Register 0 High; 0x000002B0 ***/
    union {
      byte Byte;
    } TIM1_TC0HiSTR;
    #define TIM1_TC0Hi                  _TIM1_TC0.Overlap_STR.TIM1_TC0HiSTR.Byte
    

    /*** TIM1_TC0Lo - Timer Input Capture/Output Compare Register 0 Low; 0x000002B1 ***/
    union {
      byte Byte;
    } TIM1_TC0LoSTR;
    #define TIM1_TC0Lo                  _TIM1_TC0.Overlap_STR.TIM1_TC0LoSTR.Byte
    
  } Overlap_STR;

} TIM1_TC0STR;
extern volatile TIM1_TC0STR _TIM1_TC0 @(REG_BASE + 0x000002B0UL);
#define TIM1_TC0                        _TIM1_TC0.Word
/* TIM1_TC_ARR: Access 8 TIM1_TCx registers in an array */
#define TIM1_TC_ARR                     ((volatile word *) &TIM1_TC0)


/*** TIM1_TC1 - Timer Input Capture/Output Compare Register 1; 0x000002B2 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TIM1_TC1Hi - Timer Input Capture/Output Compare Register 1 High; 0x000002B2 ***/
    union {
      byte Byte;
    } TIM1_TC1HiSTR;
    #define TIM1_TC1Hi                  _TIM1_TC1.Overlap_STR.TIM1_TC1HiSTR.Byte
    

    /*** TIM1_TC1Lo - Timer Input Capture/Output Compare Register 1 Low; 0x000002B3 ***/
    union {
      byte Byte;
    } TIM1_TC1LoSTR;
    #define TIM1_TC1Lo                  _TIM1_TC1.Overlap_STR.TIM1_TC1LoSTR.Byte
    
  } Overlap_STR;

} TIM1_TC1STR;
extern volatile TIM1_TC1STR _TIM1_TC1 @(REG_BASE + 0x000002B2UL);
#define TIM1_TC1                        _TIM1_TC1.Word


/*** TIM1_TC2 - Timer Input Capture/Output Compare Register 2; 0x000002B4 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TIM1_TC2Hi - Timer Input Capture/Output Compare Register 2 High; 0x000002B4 ***/
    union {
      byte Byte;
    } TIM1_TC2HiSTR;
    #define TIM1_TC2Hi                  _TIM1_TC2.Overlap_STR.TIM1_TC2HiSTR.Byte
    

    /*** TIM1_TC2Lo - Timer Input Capture/Output Compare Register 2 Low; 0x000002B5 ***/
    union {
      byte Byte;
    } TIM1_TC2LoSTR;
    #define TIM1_TC2Lo                  _TIM1_TC2.Overlap_STR.TIM1_TC2LoSTR.Byte
    
  } Overlap_STR;

} TIM1_TC2STR;
extern volatile TIM1_TC2STR _TIM1_TC2 @(REG_BASE + 0x000002B4UL);
#define TIM1_TC2                        _TIM1_TC2.Word


/*** TIM1_TC3 - Timer Input Capture/Output Compare Register 3; 0x000002B6 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TIM1_TC3Hi - Timer Input Capture/Output Compare Register 3 High; 0x000002B6 ***/
    union {
      byte Byte;
    } TIM1_TC3HiSTR;
    #define TIM1_TC3Hi                  _TIM1_TC3.Overlap_STR.TIM1_TC3HiSTR.Byte
    

    /*** TIM1_TC3Lo - Timer Input Capture/Output Compare Register 3 Low; 0x000002B7 ***/
    union {
      byte Byte;
    } TIM1_TC3LoSTR;
    #define TIM1_TC3Lo                  _TIM1_TC3.Overlap_STR.TIM1_TC3LoSTR.Byte
    
  } Overlap_STR;

} TIM1_TC3STR;
extern volatile TIM1_TC3STR _TIM1_TC3 @(REG_BASE + 0x000002B6UL);
#define TIM1_TC3                        _TIM1_TC3.Word


/*** TIM1_TC4 - Timer Input Capture/Output Compare Register 4; 0x000002B8 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TIM1_TC4Hi - Timer Input Capture/Output Compare Register 4 High; 0x000002B8 ***/
    union {
      byte Byte;
    } TIM1_TC4HiSTR;
    #define TIM1_TC4Hi                  _TIM1_TC4.Overlap_STR.TIM1_TC4HiSTR.Byte
    

    /*** TIM1_TC4Lo - Timer Input Capture/Output Compare Register 4 Low; 0x000002B9 ***/
    union {
      byte Byte;
    } TIM1_TC4LoSTR;
    #define TIM1_TC4Lo                  _TIM1_TC4.Overlap_STR.TIM1_TC4LoSTR.Byte
    
  } Overlap_STR;

} TIM1_TC4STR;
extern volatile TIM1_TC4STR _TIM1_TC4 @(REG_BASE + 0x000002B8UL);
#define TIM1_TC4                        _TIM1_TC4.Word


/*** TIM1_TC5 - Timer Input Capture/Output Compare Register 5; 0x000002BA ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TIM1_TC5Hi - Timer Input Capture/Output Compare Register 5 High; 0x000002BA ***/
    union {
      byte Byte;
    } TIM1_TC5HiSTR;
    #define TIM1_TC5Hi                  _TIM1_TC5.Overlap_STR.TIM1_TC5HiSTR.Byte
    

    /*** TIM1_TC5Lo - Timer Input Capture/Output Compare Register 5 Low; 0x000002BB ***/
    union {
      byte Byte;
    } TIM1_TC5LoSTR;
    #define TIM1_TC5Lo                  _TIM1_TC5.Overlap_STR.TIM1_TC5LoSTR.Byte
    
  } Overlap_STR;

} TIM1_TC5STR;
extern volatile TIM1_TC5STR _TIM1_TC5 @(REG_BASE + 0x000002BAUL);
#define TIM1_TC5                        _TIM1_TC5.Word


/*** TIM1_TC6 - Timer Input Capture/Output Compare Register 6; 0x000002BC ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TIM1_TC6Hi - Timer Input Capture/Output Compare Register 6 High; 0x000002BC ***/
    union {
      byte Byte;
    } TIM1_TC6HiSTR;
    #define TIM1_TC6Hi                  _TIM1_TC6.Overlap_STR.TIM1_TC6HiSTR.Byte
    

    /*** TIM1_TC6Lo - Timer Input Capture/Output Compare Register 6 Low; 0x000002BD ***/
    union {
      byte Byte;
    } TIM1_TC6LoSTR;
    #define TIM1_TC6Lo                  _TIM1_TC6.Overlap_STR.TIM1_TC6LoSTR.Byte
    
  } Overlap_STR;

} TIM1_TC6STR;
extern volatile TIM1_TC6STR _TIM1_TC6 @(REG_BASE + 0x000002BCUL);
#define TIM1_TC6                        _TIM1_TC6.Word


/*** TIM1_TC7 - Timer Input Capture/Output Compare Register 7; 0x000002BE ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TIM1_TC7Hi - Timer Input Capture/Output Compare Register 7 High; 0x000002BE ***/
    union {
      byte Byte;
    } TIM1_TC7HiSTR;
    #define TIM1_TC7Hi                  _TIM1_TC7.Overlap_STR.TIM1_TC7HiSTR.Byte
    

    /*** TIM1_TC7Lo - Timer Input Capture/Output Compare Register 7 Low; 0x000002BF ***/
    union {
      byte Byte;
    } TIM1_TC7LoSTR;
    #define TIM1_TC7Lo                  _TIM1_TC7.Overlap_STR.TIM1_TC7LoSTR.Byte
    
  } Overlap_STR;

} TIM1_TC7STR;
extern volatile TIM1_TC7STR _TIM1_TC7 @(REG_BASE + 0x000002BEUL);
#define TIM1_TC7                        _TIM1_TC7.Word


/*** TIM1_PACTL - 16-Bit Pulse Accumulator A Control Register; 0x000002C0 ***/
typedef union {
  byte Byte;
  struct {
    byte PAI         :1;                                       /* Pulse Accumulator Input Interrupt enable */
    byte PAOVI       :1;                                       /* Pulse Accumulator A Overflow Interrupt enable */
    byte CLK0        :1;                                       /* Clock Select Bit 0 */
    byte CLK1        :1;                                       /* Clock Select Bit 1 */
    byte PEDGE       :1;                                       /* Pulse Accumulator Edge Control */
    byte PAMOD       :1;                                       /* Pulse Accumulator Mode */
    byte PAEN        :1;                                       /* Pulse Accumulator A System Enable */
    byte             :1; 
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte grpCLK  :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} TIM1_PACTLSTR;
extern volatile TIM1_PACTLSTR _TIM1_PACTL @(REG_BASE + 0x000002C0UL);
#define TIM1_PACTL                      _TIM1_PACTL.Byte
#define TIM1_PACTL_PAI                  _TIM1_PACTL.Bits.PAI
#define TIM1_PACTL_PAOVI                _TIM1_PACTL.Bits.PAOVI
#define TIM1_PACTL_CLK0                 _TIM1_PACTL.Bits.CLK0
#define TIM1_PACTL_CLK1                 _TIM1_PACTL.Bits.CLK1
#define TIM1_PACTL_PEDGE                _TIM1_PACTL.Bits.PEDGE
#define TIM1_PACTL_PAMOD                _TIM1_PACTL.Bits.PAMOD
#define TIM1_PACTL_PAEN                 _TIM1_PACTL.Bits.PAEN
#define TIM1_PACTL_CLK                  _TIM1_PACTL.MergedBits.grpCLK

#define TIM1_PACTL_PAI_MASK             1U
#define TIM1_PACTL_PAOVI_MASK           2U
#define TIM1_PACTL_CLK0_MASK            4U
#define TIM1_PACTL_CLK1_MASK            8U
#define TIM1_PACTL_PEDGE_MASK           16U
#define TIM1_PACTL_PAMOD_MASK           32U
#define TIM1_PACTL_PAEN_MASK            64U
#define TIM1_PACTL_CLK_MASK             12U
#define TIM1_PACTL_CLK_BITNUM           2U


/*** TIM1_PAFLG - Pulse Accumulator A Flag Register; 0x000002C1 ***/
typedef union {
  byte Byte;
  struct {
    byte PAIF        :1;                                       /* Pulse Accumulator Input edge Flag */
    byte PAOVF       :1;                                       /* Pulse Accumulator A Overflow Flag */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} TIM1_PAFLGSTR;
extern volatile TIM1_PAFLGSTR _TIM1_PAFLG @(REG_BASE + 0x000002C1UL);
#define TIM1_PAFLG                      _TIM1_PAFLG.Byte
#define TIM1_PAFLG_PAIF                 _TIM1_PAFLG.Bits.PAIF
#define TIM1_PAFLG_PAOVF                _TIM1_PAFLG.Bits.PAOVF

#define TIM1_PAFLG_PAIF_MASK            1U
#define TIM1_PAFLG_PAOVF_MASK           2U


/*** TIM1_PACNT - Pulse Accumulators Count Register; 0x000002C2 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TIM1_PACNTH - Pulse Accumulators Count Register High; 0x000002C2 ***/
    union {
      byte Byte;
    } TIM1_PACNTHSTR;
    #define TIM1_PACNTH                 _TIM1_PACNT.Overlap_STR.TIM1_PACNTHSTR.Byte
    

    /*** TIM1_PACNTL - Pulse Accumulators Count Register Low; 0x000002C3 ***/
    union {
      byte Byte;
    } TIM1_PACNTLSTR;
    #define TIM1_PACNTL                 _TIM1_PACNT.Overlap_STR.TIM1_PACNTLSTR.Byte
    
  } Overlap_STR;

} TIM1_PACNTSTR;
extern volatile TIM1_PACNTSTR _TIM1_PACNT @(REG_BASE + 0x000002C2UL);
#define TIM1_PACNT                      _TIM1_PACNT.Word


/*** TIM1_OCPD - Output Compare Pin Disconnect Register; 0x000002CC ***/
typedef union {
  byte Byte;
  struct {
    byte OCPD0       :1;                                       /* Output Compare Pin Disconnect Bit 0 */
    byte OCPD1       :1;                                       /* Output Compare Pin Disconnect Bit 1 */
    byte OCPD2       :1;                                       /* Output Compare Pin Disconnect Bit 2 */
    byte OCPD3       :1;                                       /* Output Compare Pin Disconnect Bit 3 */
    byte OCPD4       :1;                                       /* Output Compare Pin Disconnect Bit 4 */
    byte OCPD5       :1;                                       /* Output Compare Pin Disconnect Bit 5 */
    byte OCPD6       :1;                                       /* Output Compare Pin Disconnect Bit 6 */
    byte OCPD7       :1;                                       /* Output Compare Pin Disconnect Bit 7 */
  } Bits;
} TIM1_OCPDSTR;
extern volatile TIM1_OCPDSTR _TIM1_OCPD @(REG_BASE + 0x000002CCUL);
#define TIM1_OCPD                       _TIM1_OCPD.Byte
#define TIM1_OCPD_OCPD0                 _TIM1_OCPD.Bits.OCPD0
#define TIM1_OCPD_OCPD1                 _TIM1_OCPD.Bits.OCPD1
#define TIM1_OCPD_OCPD2                 _TIM1_OCPD.Bits.OCPD2
#define TIM1_OCPD_OCPD3                 _TIM1_OCPD.Bits.OCPD3
#define TIM1_OCPD_OCPD4                 _TIM1_OCPD.Bits.OCPD4
#define TIM1_OCPD_OCPD5                 _TIM1_OCPD.Bits.OCPD5
#define TIM1_OCPD_OCPD6                 _TIM1_OCPD.Bits.OCPD6
#define TIM1_OCPD_OCPD7                 _TIM1_OCPD.Bits.OCPD7

#define TIM1_OCPD_OCPD0_MASK            1U
#define TIM1_OCPD_OCPD1_MASK            2U
#define TIM1_OCPD_OCPD2_MASK            4U
#define TIM1_OCPD_OCPD3_MASK            8U
#define TIM1_OCPD_OCPD4_MASK            16U
#define TIM1_OCPD_OCPD5_MASK            32U
#define TIM1_OCPD_OCPD6_MASK            64U
#define TIM1_OCPD_OCPD7_MASK            128U


/*** TIM1_PTPSR - Precision Timer Prescaler Select Register; 0x000002CE ***/
typedef union {
  byte Byte;
  struct {
    byte PTPS0       :1;                                       /* Precision Timer Prescaler Select Bit 0 */
    byte PTPS1       :1;                                       /* Precision Timer Prescaler Select Bit 1 */
    byte PTPS2       :1;                                       /* Precision Timer Prescaler Select Bit 2 */
    byte PTPS3       :1;                                       /* Precision Timer Prescaler Select Bit 3 */
    byte PTPS4       :1;                                       /* Precision Timer Prescaler Select Bit 4 */
    byte PTPS5       :1;                                       /* Precision Timer Prescaler Select Bit 5 */
    byte PTPS6       :1;                                       /* Precision Timer Prescaler Select Bit 6 */
    byte PTPS7       :1;                                       /* Precision Timer Prescaler Select Bit 7 */
  } Bits;
} TIM1_PTPSRSTR;
extern volatile TIM1_PTPSRSTR _TIM1_PTPSR @(REG_BASE + 0x000002CEUL);
#define TIM1_PTPSR                      _TIM1_PTPSR.Byte
#define TIM1_PTPSR_PTPS0                _TIM1_PTPSR.Bits.PTPS0
#define TIM1_PTPSR_PTPS1                _TIM1_PTPSR.Bits.PTPS1
#define TIM1_PTPSR_PTPS2                _TIM1_PTPSR.Bits.PTPS2
#define TIM1_PTPSR_PTPS3                _TIM1_PTPSR.Bits.PTPS3
#define TIM1_PTPSR_PTPS4                _TIM1_PTPSR.Bits.PTPS4
#define TIM1_PTPSR_PTPS5                _TIM1_PTPSR.Bits.PTPS5
#define TIM1_PTPSR_PTPS6                _TIM1_PTPSR.Bits.PTPS6
#define TIM1_PTPSR_PTPS7                _TIM1_PTPSR.Bits.PTPS7

#define TIM1_PTPSR_PTPS0_MASK           1U
#define TIM1_PTPSR_PTPS1_MASK           2U
#define TIM1_PTPSR_PTPS2_MASK           4U
#define TIM1_PTPSR_PTPS3_MASK           8U
#define TIM1_PTPSR_PTPS4_MASK           16U
#define TIM1_PTPSR_PTPS5_MASK           32U
#define TIM1_PTPSR_PTPS6_MASK           64U
#define TIM1_PTPSR_PTPS7_MASK           128U


/*** CPMUHTCTL - High Temperature Control Register; 0x000002F0 ***/
typedef union {
  byte Byte;
  struct {
    byte HTIF        :1;                                       /* High Temperature Interrupt Flag */
    byte HTIE        :1;                                       /* High Temperature Interrupt Enable Bit */
    byte HTDS        :1;                                       /* High Temperature Detect Status Bi */
    byte HTE         :1;                                       /* High Temperature Enable Bit */
    byte             :1; 
    byte VSEL        :1;                                       /* Voltage Access Select Bit */
    byte             :1; 
    byte             :1; 
  } Bits;
} CPMUHTCTLSTR;
extern volatile CPMUHTCTLSTR _CPMUHTCTL @(REG_BASE + 0x000002F0UL);
#define CPMUHTCTL                       _CPMUHTCTL.Byte
#define CPMUHTCTL_HTIF                  _CPMUHTCTL.Bits.HTIF
#define CPMUHTCTL_HTIE                  _CPMUHTCTL.Bits.HTIE
#define CPMUHTCTL_HTDS                  _CPMUHTCTL.Bits.HTDS
#define CPMUHTCTL_HTE                   _CPMUHTCTL.Bits.HTE
#define CPMUHTCTL_VSEL                  _CPMUHTCTL.Bits.VSEL

#define CPMUHTCTL_HTIF_MASK             1U
#define CPMUHTCTL_HTIE_MASK             2U
#define CPMUHTCTL_HTDS_MASK             4U
#define CPMUHTCTL_HTE_MASK              8U
#define CPMUHTCTL_VSEL_MASK             32U


/*** CPMULVCTL - Low Voltage Control Register; 0x000002F1 ***/
typedef union {
  byte Byte;
  struct {
    byte LVIF        :1;                                       /* Low-Voltage Interrupt Flag */
    byte LVIE        :1;                                       /* Low-Voltage Interrupt Enable Bit */
    byte LVDS        :1;                                       /* Low-Voltage Detect Status Bit */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} CPMULVCTLSTR;
extern volatile CPMULVCTLSTR _CPMULVCTL @(REG_BASE + 0x000002F1UL);
#define CPMULVCTL                       _CPMULVCTL.Byte
#define CPMULVCTL_LVIF                  _CPMULVCTL.Bits.LVIF
#define CPMULVCTL_LVIE                  _CPMULVCTL.Bits.LVIE
#define CPMULVCTL_LVDS                  _CPMULVCTL.Bits.LVDS

#define CPMULVCTL_LVIF_MASK             1U
#define CPMULVCTL_LVIE_MASK             2U
#define CPMULVCTL_LVDS_MASK             4U


/*** CPMUAPICTL - Autonomous Periodical Interrupt Control Register; 0x000002F2 ***/
typedef union {
  byte Byte;
  struct {
    byte APIF        :1;                                       /* Autonomous Periodical Interrupt Flag */
    byte APIE        :1;                                       /* Autonomous Periodical Interrupt Enable Bit */
    byte APIFE       :1;                                       /* Autonomous Periodical Interrupt Feature Enable Bit */
    byte APIEA       :1;                                       /* Autonomous Periodical Interrupt External Access Enable Bit */
    byte APIES       :1;                                       /* Autonomous Periodical Interrupt External Select Bit */
    byte             :1; 
    byte             :1; 
    byte APICLK      :1;                                       /* Autonomous Periodical Interrupt Clock Select Bit */
  } Bits;
} CPMUAPICTLSTR;
extern volatile CPMUAPICTLSTR _CPMUAPICTL @(REG_BASE + 0x000002F2UL);
#define CPMUAPICTL                      _CPMUAPICTL.Byte
#define CPMUAPICTL_APIF                 _CPMUAPICTL.Bits.APIF
#define CPMUAPICTL_APIE                 _CPMUAPICTL.Bits.APIE
#define CPMUAPICTL_APIFE                _CPMUAPICTL.Bits.APIFE
#define CPMUAPICTL_APIEA                _CPMUAPICTL.Bits.APIEA
#define CPMUAPICTL_APIES                _CPMUAPICTL.Bits.APIES
#define CPMUAPICTL_APICLK               _CPMUAPICTL.Bits.APICLK

#define CPMUAPICTL_APIF_MASK            1U
#define CPMUAPICTL_APIE_MASK            2U
#define CPMUAPICTL_APIFE_MASK           4U
#define CPMUAPICTL_APIEA_MASK           8U
#define CPMUAPICTL_APIES_MASK           16U
#define CPMUAPICTL_APICLK_MASK          128U


/*** CPMUAPITR - Autonomous Periodical Interrupt Trimming Register; 0x000002F3 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte APITR0      :1;                                       /* Autonomous Periodical Interrupt Period Trimming Bit 0 */
    byte APITR1      :1;                                       /* Autonomous Periodical Interrupt Period Trimming Bit 1 */
    byte APITR2      :1;                                       /* Autonomous Periodical Interrupt Period Trimming Bit 2 */
    byte APITR3      :1;                                       /* Autonomous Periodical Interrupt Period Trimming Bit 3 */
    byte APITR4      :1;                                       /* Autonomous Periodical Interrupt Period Trimming Bit 4 */
    byte APITR5      :1;                                       /* Autonomous Periodical Interrupt Period Trimming Bit 5 */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte grpAPITR :6;
  } MergedBits;
} CPMUAPITRSTR;
extern volatile CPMUAPITRSTR _CPMUAPITR @(REG_BASE + 0x000002F3UL);
#define CPMUAPITR                       _CPMUAPITR.Byte
#define CPMUAPITR_APITR0                _CPMUAPITR.Bits.APITR0
#define CPMUAPITR_APITR1                _CPMUAPITR.Bits.APITR1
#define CPMUAPITR_APITR2                _CPMUAPITR.Bits.APITR2
#define CPMUAPITR_APITR3                _CPMUAPITR.Bits.APITR3
#define CPMUAPITR_APITR4                _CPMUAPITR.Bits.APITR4
#define CPMUAPITR_APITR5                _CPMUAPITR.Bits.APITR5
#define CPMUAPITR_APITR                 _CPMUAPITR.MergedBits.grpAPITR

#define CPMUAPITR_APITR0_MASK           4U
#define CPMUAPITR_APITR1_MASK           8U
#define CPMUAPITR_APITR2_MASK           16U
#define CPMUAPITR_APITR3_MASK           32U
#define CPMUAPITR_APITR4_MASK           64U
#define CPMUAPITR_APITR5_MASK           128U
#define CPMUAPITR_APITR_MASK            252U
#define CPMUAPITR_APITR_BITNUM          2U


/*** CPMUAPIR - Autonomous Periodical Interrupt Rate Register; 0x000002F4 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** CPMUAPIRH - Autonomous Periodical Interrupt Rate Register High; 0x000002F4 ***/
    union {
      byte Byte;
      struct {
        byte APIR8       :1;                                       /* Autonomous Periodical Interrupt Rate Bit 8 */
        byte APIR9       :1;                                       /* Autonomous Periodical Interrupt Rate Bit 9 */
        byte APIR10      :1;                                       /* Autonomous Periodical Interrupt Rate Bit 10 */
        byte APIR11      :1;                                       /* Autonomous Periodical Interrupt Rate Bit 11 */
        byte APIR12      :1;                                       /* Autonomous Periodical Interrupt Rate Bit 12 */
        byte APIR13      :1;                                       /* Autonomous Periodical Interrupt Rate Bit 13 */
        byte APIR14      :1;                                       /* Autonomous Periodical Interrupt Rate Bit 14 */
        byte APIR15      :1;                                       /* Autonomous Periodical Interrupt Rate Bit 15 */
      } Bits;
    } CPMUAPIRHSTR;
    #define CPMUAPIRH                   _CPMUAPIR.Overlap_STR.CPMUAPIRHSTR.Byte
    #define CPMUAPIRH_APIR8             _CPMUAPIR.Overlap_STR.CPMUAPIRHSTR.Bits.APIR8
    #define CPMUAPIRH_APIR9             _CPMUAPIR.Overlap_STR.CPMUAPIRHSTR.Bits.APIR9
    #define CPMUAPIRH_APIR10            _CPMUAPIR.Overlap_STR.CPMUAPIRHSTR.Bits.APIR10
    #define CPMUAPIRH_APIR11            _CPMUAPIR.Overlap_STR.CPMUAPIRHSTR.Bits.APIR11
    #define CPMUAPIRH_APIR12            _CPMUAPIR.Overlap_STR.CPMUAPIRHSTR.Bits.APIR12
    #define CPMUAPIRH_APIR13            _CPMUAPIR.Overlap_STR.CPMUAPIRHSTR.Bits.APIR13
    #define CPMUAPIRH_APIR14            _CPMUAPIR.Overlap_STR.CPMUAPIRHSTR.Bits.APIR14
    #define CPMUAPIRH_APIR15            _CPMUAPIR.Overlap_STR.CPMUAPIRHSTR.Bits.APIR15
    
    #define CPMUAPIRH_APIR8_MASK        1U
    #define CPMUAPIRH_APIR9_MASK        2U
    #define CPMUAPIRH_APIR10_MASK       4U
    #define CPMUAPIRH_APIR11_MASK       8U
    #define CPMUAPIRH_APIR12_MASK       16U
    #define CPMUAPIRH_APIR13_MASK       32U
    #define CPMUAPIRH_APIR14_MASK       64U
    #define CPMUAPIRH_APIR15_MASK       128U
    

    /*** CPMUAPIRL - Autonomous Periodical Interrupt Rate Register Low; 0x000002F5 ***/
    union {
      byte Byte;
      struct {
        byte APIR0       :1;                                       /* Autonomous Periodical Interrupt Rate Bit 0 */
        byte APIR1       :1;                                       /* Autonomous Periodical Interrupt Rate Bit 1 */
        byte APIR2       :1;                                       /* Autonomous Periodical Interrupt Rate Bit 2 */
        byte APIR3       :1;                                       /* Autonomous Periodical Interrupt Rate Bit 3 */
        byte APIR4       :1;                                       /* Autonomous Periodical Interrupt Rate Bit 4 */
        byte APIR5       :1;                                       /* Autonomous Periodical Interrupt Rate Bit 5 */
        byte APIR6       :1;                                       /* Autonomous Periodical Interrupt Rate Bit 6 */
        byte APIR7       :1;                                       /* Autonomous Periodical Interrupt Rate Bit 7 */
      } Bits;
    } CPMUAPIRLSTR;
    #define CPMUAPIRL                   _CPMUAPIR.Overlap_STR.CPMUAPIRLSTR.Byte
    #define CPMUAPIRL_APIR0             _CPMUAPIR.Overlap_STR.CPMUAPIRLSTR.Bits.APIR0
    #define CPMUAPIRL_APIR1             _CPMUAPIR.Overlap_STR.CPMUAPIRLSTR.Bits.APIR1
    #define CPMUAPIRL_APIR2             _CPMUAPIR.Overlap_STR.CPMUAPIRLSTR.Bits.APIR2
    #define CPMUAPIRL_APIR3             _CPMUAPIR.Overlap_STR.CPMUAPIRLSTR.Bits.APIR3
    #define CPMUAPIRL_APIR4             _CPMUAPIR.Overlap_STR.CPMUAPIRLSTR.Bits.APIR4
    #define CPMUAPIRL_APIR5             _CPMUAPIR.Overlap_STR.CPMUAPIRLSTR.Bits.APIR5
    #define CPMUAPIRL_APIR6             _CPMUAPIR.Overlap_STR.CPMUAPIRLSTR.Bits.APIR6
    #define CPMUAPIRL_APIR7             _CPMUAPIR.Overlap_STR.CPMUAPIRLSTR.Bits.APIR7
    
    #define CPMUAPIRL_APIR0_MASK        1U
    #define CPMUAPIRL_APIR1_MASK        2U
    #define CPMUAPIRL_APIR2_MASK        4U
    #define CPMUAPIRL_APIR3_MASK        8U
    #define CPMUAPIRL_APIR4_MASK        16U
    #define CPMUAPIRL_APIR5_MASK        32U
    #define CPMUAPIRL_APIR6_MASK        64U
    #define CPMUAPIRL_APIR7_MASK        128U
    
  } Overlap_STR;

  struct {
    word APIR0       :1;                                       /* Autonomous Periodical Interrupt Rate Bit 0 */
    word APIR1       :1;                                       /* Autonomous Periodical Interrupt Rate Bit 1 */
    word APIR2       :1;                                       /* Autonomous Periodical Interrupt Rate Bit 2 */
    word APIR3       :1;                                       /* Autonomous Periodical Interrupt Rate Bit 3 */
    word APIR4       :1;                                       /* Autonomous Periodical Interrupt Rate Bit 4 */
    word APIR5       :1;                                       /* Autonomous Periodical Interrupt Rate Bit 5 */
    word APIR6       :1;                                       /* Autonomous Periodical Interrupt Rate Bit 6 */
    word APIR7       :1;                                       /* Autonomous Periodical Interrupt Rate Bit 7 */
    word APIR8       :1;                                       /* Autonomous Periodical Interrupt Rate Bit 8 */
    word APIR9       :1;                                       /* Autonomous Periodical Interrupt Rate Bit 9 */
    word APIR10      :1;                                       /* Autonomous Periodical Interrupt Rate Bit 10 */
    word APIR11      :1;                                       /* Autonomous Periodical Interrupt Rate Bit 11 */
    word APIR12      :1;                                       /* Autonomous Periodical Interrupt Rate Bit 12 */
    word APIR13      :1;                                       /* Autonomous Periodical Interrupt Rate Bit 13 */
    word APIR14      :1;                                       /* Autonomous Periodical Interrupt Rate Bit 14 */
    word APIR15      :1;                                       /* Autonomous Periodical Interrupt Rate Bit 15 */
  } Bits;
} CPMUAPIRSTR;
extern volatile CPMUAPIRSTR _CPMUAPIR @(REG_BASE + 0x000002F4UL);
#define CPMUAPIR                        _CPMUAPIR.Word
#define CPMUAPIR_APIR0                  _CPMUAPIR.Bits.APIR0
#define CPMUAPIR_APIR1                  _CPMUAPIR.Bits.APIR1
#define CPMUAPIR_APIR2                  _CPMUAPIR.Bits.APIR2
#define CPMUAPIR_APIR3                  _CPMUAPIR.Bits.APIR3
#define CPMUAPIR_APIR4                  _CPMUAPIR.Bits.APIR4
#define CPMUAPIR_APIR5                  _CPMUAPIR.Bits.APIR5
#define CPMUAPIR_APIR6                  _CPMUAPIR.Bits.APIR6
#define CPMUAPIR_APIR7                  _CPMUAPIR.Bits.APIR7
#define CPMUAPIR_APIR8                  _CPMUAPIR.Bits.APIR8
#define CPMUAPIR_APIR9                  _CPMUAPIR.Bits.APIR9
#define CPMUAPIR_APIR10                 _CPMUAPIR.Bits.APIR10
#define CPMUAPIR_APIR11                 _CPMUAPIR.Bits.APIR11
#define CPMUAPIR_APIR12                 _CPMUAPIR.Bits.APIR12
#define CPMUAPIR_APIR13                 _CPMUAPIR.Bits.APIR13
#define CPMUAPIR_APIR14                 _CPMUAPIR.Bits.APIR14
#define CPMUAPIR_APIR15                 _CPMUAPIR.Bits.APIR15

#define CPMUAPIR_APIR0_MASK             1U
#define CPMUAPIR_APIR1_MASK             2U
#define CPMUAPIR_APIR2_MASK             4U
#define CPMUAPIR_APIR3_MASK             8U
#define CPMUAPIR_APIR4_MASK             16U
#define CPMUAPIR_APIR5_MASK             32U
#define CPMUAPIR_APIR6_MASK             64U
#define CPMUAPIR_APIR7_MASK             128U
#define CPMUAPIR_APIR8_MASK             256U
#define CPMUAPIR_APIR9_MASK             512U
#define CPMUAPIR_APIR10_MASK            1024U
#define CPMUAPIR_APIR11_MASK            2048U
#define CPMUAPIR_APIR12_MASK            4096U
#define CPMUAPIR_APIR13_MASK            8192U
#define CPMUAPIR_APIR14_MASK            16384U
#define CPMUAPIR_APIR15_MASK            32768U


/*** CPMUHTTR - High Temperature Trimming Register; 0x000002F7 ***/
typedef union {
  byte Byte;
  struct {
    byte HTTR0       :1;                                       /* High Temperature Trimming Bits, bit 0 */
    byte HTTR1       :1;                                       /* High Temperature Trimming Bits, bit 1 */
    byte HTTR2       :1;                                       /* High Temperature Trimming Bits, bit 2 */
    byte HTTR3       :1;                                       /* High Temperature Trimming Bits, bit 3 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte HTOE        :1;                                       /* High Temperature Offeset Enable Bit */
  } Bits;
  struct {
    byte grpHTTR :4;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} CPMUHTTRSTR;
extern volatile CPMUHTTRSTR _CPMUHTTR @(REG_BASE + 0x000002F7UL);
#define CPMUHTTR                        _CPMUHTTR.Byte
#define CPMUHTTR_HTTR0                  _CPMUHTTR.Bits.HTTR0
#define CPMUHTTR_HTTR1                  _CPMUHTTR.Bits.HTTR1
#define CPMUHTTR_HTTR2                  _CPMUHTTR.Bits.HTTR2
#define CPMUHTTR_HTTR3                  _CPMUHTTR.Bits.HTTR3
#define CPMUHTTR_HTOE                   _CPMUHTTR.Bits.HTOE
#define CPMUHTTR_HTTR                   _CPMUHTTR.MergedBits.grpHTTR

#define CPMUHTTR_HTTR0_MASK             1U
#define CPMUHTTR_HTTR1_MASK             2U
#define CPMUHTTR_HTTR2_MASK             4U
#define CPMUHTTR_HTTR3_MASK             8U
#define CPMUHTTR_HTOE_MASK              128U
#define CPMUHTTR_HTTR_MASK              15U
#define CPMUHTTR_HTTR_BITNUM            0U


/*** CPMUIRCTRIM - S12CPMU IRC1M Trim Registers; 0x000002F8 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** CPMUIRCTRIMH - S12CPMU IRC1M Trim Registers High; 0x000002F8 ***/
    union {
      byte Byte;
      struct {
        byte IRCTRIM8    :1;                                       /* IRC1M Frequency Trim Bit 8 */
        byte IRCTRIM9    :1;                                       /* IRC1M Frequency Trim Bit 9 */
        byte             :1; 
        byte             :1; 
        byte TCTRIM0     :1;                                       /* IRC1M temperature coeficient Trim Bit 0 */
        byte TCTRIM1     :1;                                       /* IRC1M temperature coeficient Trim Bit 1 */
        byte TCTRIM2     :1;                                       /* IRC1M temperature coeficient Trim Bit 2 */
        byte TCTRIM3     :1;                                       /* IRC1M temperature coeficient Trim Bit 3 */
      } Bits;
      struct {
        byte grpIRCTRIM_8 :2;
        byte     :1;
        byte     :1;
        byte grpTCTRIM :4;
      } MergedBits;
    } CPMUIRCTRIMHSTR;
    #define CPMUIRCTRIMH                _CPMUIRCTRIM.Overlap_STR.CPMUIRCTRIMHSTR.Byte
    #define CPMUIRCTRIMH_IRCTRIM8       _CPMUIRCTRIM.Overlap_STR.CPMUIRCTRIMHSTR.Bits.IRCTRIM8
    #define CPMUIRCTRIMH_IRCTRIM9       _CPMUIRCTRIM.Overlap_STR.CPMUIRCTRIMHSTR.Bits.IRCTRIM9
    #define CPMUIRCTRIMH_TCTRIM0        _CPMUIRCTRIM.Overlap_STR.CPMUIRCTRIMHSTR.Bits.TCTRIM0
    #define CPMUIRCTRIMH_TCTRIM1        _CPMUIRCTRIM.Overlap_STR.CPMUIRCTRIMHSTR.Bits.TCTRIM1
    #define CPMUIRCTRIMH_TCTRIM2        _CPMUIRCTRIM.Overlap_STR.CPMUIRCTRIMHSTR.Bits.TCTRIM2
    #define CPMUIRCTRIMH_TCTRIM3        _CPMUIRCTRIM.Overlap_STR.CPMUIRCTRIMHSTR.Bits.TCTRIM3
    #define CPMUIRCTRIMH_IRCTRIM_8      _CPMUIRCTRIM.Overlap_STR.CPMUIRCTRIMHSTR.MergedBits.grpIRCTRIM_8
    #define CPMUIRCTRIMH_TCTRIM         _CPMUIRCTRIM.Overlap_STR.CPMUIRCTRIMHSTR.MergedBits.grpTCTRIM
    #define CPMUIRCTRIMH_IRCTRIM        CPMUIRCTRIMH_IRCTRIM_8
    
    #define CPMUIRCTRIMH_IRCTRIM8_MASK  1U
    #define CPMUIRCTRIMH_IRCTRIM9_MASK  2U
    #define CPMUIRCTRIMH_TCTRIM0_MASK   16U
    #define CPMUIRCTRIMH_TCTRIM1_MASK   32U
    #define CPMUIRCTRIMH_TCTRIM2_MASK   64U
    #define CPMUIRCTRIMH_TCTRIM3_MASK   128U
    #define CPMUIRCTRIMH_IRCTRIM_8_MASK 3U
    #define CPMUIRCTRIMH_IRCTRIM_8_BITNUM 0U
    #define CPMUIRCTRIMH_TCTRIM_MASK    240U
    #define CPMUIRCTRIMH_TCTRIM_BITNUM  4U
    

    /*** CPMUIRCTRIML - S12CPMU IRC1M Trim Registers Low; 0x000002F9 ***/
    union {
      byte Byte;
      struct {
        byte IRCTRIM0    :1;                                       /* IRC1M Frequency Trim Bit 0 */
        byte IRCTRIM1    :1;                                       /* IRC1M Frequency Trim Bit 1 */
        byte IRCTRIM2    :1;                                       /* IRC1M Frequency Trim Bit 2 */
        byte IRCTRIM3    :1;                                       /* IRC1M Frequency Trim Bit 3 */
        byte IRCTRIM4    :1;                                       /* IRC1M Frequency Trim Bit 4 */
        byte IRCTRIM5    :1;                                       /* IRC1M Frequency Trim Bit 5 */
        byte IRCTRIM6    :1;                                       /* IRC1M Frequency Trim Bit 6 */
        byte IRCTRIM7    :1;                                       /* IRC1M Frequency Trim Bit 7 */
      } Bits;
    } CPMUIRCTRIMLSTR;
    #define CPMUIRCTRIML                _CPMUIRCTRIM.Overlap_STR.CPMUIRCTRIMLSTR.Byte
    #define CPMUIRCTRIML_IRCTRIM0       _CPMUIRCTRIM.Overlap_STR.CPMUIRCTRIMLSTR.Bits.IRCTRIM0
    #define CPMUIRCTRIML_IRCTRIM1       _CPMUIRCTRIM.Overlap_STR.CPMUIRCTRIMLSTR.Bits.IRCTRIM1
    #define CPMUIRCTRIML_IRCTRIM2       _CPMUIRCTRIM.Overlap_STR.CPMUIRCTRIMLSTR.Bits.IRCTRIM2
    #define CPMUIRCTRIML_IRCTRIM3       _CPMUIRCTRIM.Overlap_STR.CPMUIRCTRIMLSTR.Bits.IRCTRIM3
    #define CPMUIRCTRIML_IRCTRIM4       _CPMUIRCTRIM.Overlap_STR.CPMUIRCTRIMLSTR.Bits.IRCTRIM4
    #define CPMUIRCTRIML_IRCTRIM5       _CPMUIRCTRIM.Overlap_STR.CPMUIRCTRIMLSTR.Bits.IRCTRIM5
    #define CPMUIRCTRIML_IRCTRIM6       _CPMUIRCTRIM.Overlap_STR.CPMUIRCTRIMLSTR.Bits.IRCTRIM6
    #define CPMUIRCTRIML_IRCTRIM7       _CPMUIRCTRIM.Overlap_STR.CPMUIRCTRIMLSTR.Bits.IRCTRIM7
    
    #define CPMUIRCTRIML_IRCTRIM0_MASK  1U
    #define CPMUIRCTRIML_IRCTRIM1_MASK  2U
    #define CPMUIRCTRIML_IRCTRIM2_MASK  4U
    #define CPMUIRCTRIML_IRCTRIM3_MASK  8U
    #define CPMUIRCTRIML_IRCTRIM4_MASK  16U
    #define CPMUIRCTRIML_IRCTRIM5_MASK  32U
    #define CPMUIRCTRIML_IRCTRIM6_MASK  64U
    #define CPMUIRCTRIML_IRCTRIM7_MASK  128U
    
  } Overlap_STR;

  struct {
    word IRCTRIM0    :1;                                       /* IRC1M Frequency Trim Bit 0 */
    word IRCTRIM1    :1;                                       /* IRC1M Frequency Trim Bit 1 */
    word IRCTRIM2    :1;                                       /* IRC1M Frequency Trim Bit 2 */
    word IRCTRIM3    :1;                                       /* IRC1M Frequency Trim Bit 3 */
    word IRCTRIM4    :1;                                       /* IRC1M Frequency Trim Bit 4 */
    word IRCTRIM5    :1;                                       /* IRC1M Frequency Trim Bit 5 */
    word IRCTRIM6    :1;                                       /* IRC1M Frequency Trim Bit 6 */
    word IRCTRIM7    :1;                                       /* IRC1M Frequency Trim Bit 7 */
    word IRCTRIM8    :1;                                       /* IRC1M Frequency Trim Bit 8 */
    word IRCTRIM9    :1;                                       /* IRC1M Frequency Trim Bit 9 */
    word             :1; 
    word             :1; 
    word TCTRIM0     :1;                                       /* IRC1M temperature coeficient Trim Bit 0 */
    word TCTRIM1     :1;                                       /* IRC1M temperature coeficient Trim Bit 1 */
    word TCTRIM2     :1;                                       /* IRC1M temperature coeficient Trim Bit 2 */
    word TCTRIM3     :1;                                       /* IRC1M temperature coeficient Trim Bit 3 */
  } Bits;
  struct {
    word grpIRCTRIM :10;
    word         :1;
    word         :1;
    word grpTCTRIM :4;
  } MergedBits;
} CPMUIRCTRIMSTR;
extern volatile CPMUIRCTRIMSTR _CPMUIRCTRIM @(REG_BASE + 0x000002F8UL);
#define CPMUIRCTRIM                     _CPMUIRCTRIM.Word
#define CPMUIRCTRIM_IRCTRIM0            _CPMUIRCTRIM.Bits.IRCTRIM0
#define CPMUIRCTRIM_IRCTRIM1            _CPMUIRCTRIM.Bits.IRCTRIM1
#define CPMUIRCTRIM_IRCTRIM2            _CPMUIRCTRIM.Bits.IRCTRIM2
#define CPMUIRCTRIM_IRCTRIM3            _CPMUIRCTRIM.Bits.IRCTRIM3
#define CPMUIRCTRIM_IRCTRIM4            _CPMUIRCTRIM.Bits.IRCTRIM4
#define CPMUIRCTRIM_IRCTRIM5            _CPMUIRCTRIM.Bits.IRCTRIM5
#define CPMUIRCTRIM_IRCTRIM6            _CPMUIRCTRIM.Bits.IRCTRIM6
#define CPMUIRCTRIM_IRCTRIM7            _CPMUIRCTRIM.Bits.IRCTRIM7
#define CPMUIRCTRIM_IRCTRIM8            _CPMUIRCTRIM.Bits.IRCTRIM8
#define CPMUIRCTRIM_IRCTRIM9            _CPMUIRCTRIM.Bits.IRCTRIM9
#define CPMUIRCTRIM_TCTRIM0             _CPMUIRCTRIM.Bits.TCTRIM0
#define CPMUIRCTRIM_TCTRIM1             _CPMUIRCTRIM.Bits.TCTRIM1
#define CPMUIRCTRIM_TCTRIM2             _CPMUIRCTRIM.Bits.TCTRIM2
#define CPMUIRCTRIM_TCTRIM3             _CPMUIRCTRIM.Bits.TCTRIM3
#define CPMUIRCTRIM_IRCTRIM             _CPMUIRCTRIM.MergedBits.grpIRCTRIM
#define CPMUIRCTRIM_TCTRIM              _CPMUIRCTRIM.MergedBits.grpTCTRIM

#define CPMUIRCTRIM_IRCTRIM0_MASK       1U
#define CPMUIRCTRIM_IRCTRIM1_MASK       2U
#define CPMUIRCTRIM_IRCTRIM2_MASK       4U
#define CPMUIRCTRIM_IRCTRIM3_MASK       8U
#define CPMUIRCTRIM_IRCTRIM4_MASK       16U
#define CPMUIRCTRIM_IRCTRIM5_MASK       32U
#define CPMUIRCTRIM_IRCTRIM6_MASK       64U
#define CPMUIRCTRIM_IRCTRIM7_MASK       128U
#define CPMUIRCTRIM_IRCTRIM8_MASK       256U
#define CPMUIRCTRIM_IRCTRIM9_MASK       512U
#define CPMUIRCTRIM_TCTRIM0_MASK        4096U
#define CPMUIRCTRIM_TCTRIM1_MASK        8192U
#define CPMUIRCTRIM_TCTRIM2_MASK        16384U
#define CPMUIRCTRIM_TCTRIM3_MASK        32768U
#define CPMUIRCTRIM_IRCTRIM_MASK        1023U
#define CPMUIRCTRIM_IRCTRIM_BITNUM      0U
#define CPMUIRCTRIM_TCTRIM_MASK         61440U
#define CPMUIRCTRIM_TCTRIM_BITNUM       12U


/*** CPMUOSC - S12CPMU Oscillator Register; 0x000002FA ***/
typedef union {
  byte Byte;
  struct {
    byte OSCFILT0    :1;                                       /* Oscillator Filter Bits, bit 0 */
    byte OSCFILT1    :1;                                       /* Oscillator Filter Bits, bit 1 */
    byte OSCFILT2    :1;                                       /* Oscillator Filter Bits, bit 2 */
    byte OSCFILT3    :1;                                       /* Oscillator Filter Bits, bit 3 */
    byte OSCFILT4    :1;                                       /* Oscillator Filter Bits, bit 4 */
    byte             :1; 
    byte OSCBW       :1;                                       /* Oscillator Filter Bandwidth Bit */
    byte OSCE        :1;                                       /* Oscillator Enable Bit */
  } Bits;
  struct {
    byte grpOSCFILT :5;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} CPMUOSCSTR;
extern volatile CPMUOSCSTR _CPMUOSC @(REG_BASE + 0x000002FAUL);
#define CPMUOSC                         _CPMUOSC.Byte
#define CPMUOSC_OSCFILT0                _CPMUOSC.Bits.OSCFILT0
#define CPMUOSC_OSCFILT1                _CPMUOSC.Bits.OSCFILT1
#define CPMUOSC_OSCFILT2                _CPMUOSC.Bits.OSCFILT2
#define CPMUOSC_OSCFILT3                _CPMUOSC.Bits.OSCFILT3
#define CPMUOSC_OSCFILT4                _CPMUOSC.Bits.OSCFILT4
#define CPMUOSC_OSCBW                   _CPMUOSC.Bits.OSCBW
#define CPMUOSC_OSCE                    _CPMUOSC.Bits.OSCE
#define CPMUOSC_OSCFILT                 _CPMUOSC.MergedBits.grpOSCFILT

#define CPMUOSC_OSCFILT0_MASK           1U
#define CPMUOSC_OSCFILT1_MASK           2U
#define CPMUOSC_OSCFILT2_MASK           4U
#define CPMUOSC_OSCFILT3_MASK           8U
#define CPMUOSC_OSCFILT4_MASK           16U
#define CPMUOSC_OSCBW_MASK              64U
#define CPMUOSC_OSCE_MASK               128U
#define CPMUOSC_OSCFILT_MASK            31U
#define CPMUOSC_OSCFILT_BITNUM          0U


/*** CPMUPROT - S12CPMUV1 Protection Register; 0x000002FB ***/
typedef union {
  byte Byte;
  struct {
    byte PROT        :1;                                       /* Clock Configuration Registers Protection Bit */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} CPMUPROTSTR;
extern volatile CPMUPROTSTR _CPMUPROT @(REG_BASE + 0x000002FBUL);
#define CPMUPROT                        _CPMUPROT.Byte
#define CPMUPROT_PROT                   _CPMUPROT.Bits.PROT

#define CPMUPROT_PROT_MASK              1U


/*** BAKEY0 - Backdoor Comparison Key 0; 0x0000FF00 ***/
typedef union {
  word Word;
  struct {
    word KEY0        :1;                                       /* Backdoor Comparison Key Bits, bit 0 */
    word KEY1        :1;                                       /* Backdoor Comparison Key Bits, bit 1 */
    word KEY2        :1;                                       /* Backdoor Comparison Key Bits, bit 2 */
    word KEY3        :1;                                       /* Backdoor Comparison Key Bits, bit 3 */
    word KEY4        :1;                                       /* Backdoor Comparison Key Bits, bit 4 */
    word KEY5        :1;                                       /* Backdoor Comparison Key Bits, bit 5 */
    word KEY6        :1;                                       /* Backdoor Comparison Key Bits, bit 6 */
    word KEY7        :1;                                       /* Backdoor Comparison Key Bits, bit 7 */
    word KEY8        :1;                                       /* Backdoor Comparison Key Bits, bit 8 */
    word KEY9        :1;                                       /* Backdoor Comparison Key Bits, bit 9 */
    word KEY10       :1;                                       /* Backdoor Comparison Key Bits, bit 10 */
    word KEY11       :1;                                       /* Backdoor Comparison Key Bits, bit 11 */
    word KEY12       :1;                                       /* Backdoor Comparison Key Bits, bit 12 */
    word KEY13       :1;                                       /* Backdoor Comparison Key Bits, bit 13 */
    word KEY14       :1;                                       /* Backdoor Comparison Key Bits, bit 14 */
    word KEY15       :1;                                       /* Backdoor Comparison Key Bits, bit 15 */
  } Bits;
} BAKEY0STR;
/* Tip for register initialization in the user code:  const word BAKEY0_INIT @0x0000FF00 = <BAKEY0_INITVAL>; */
#define _BAKEY0 (*(const BAKEY0STR *)0x0000FF00)
#define BAKEY0                          _BAKEY0.Word
#define BAKEY0_KEY0                     _BAKEY0.Bits.KEY0
#define BAKEY0_KEY1                     _BAKEY0.Bits.KEY1
#define BAKEY0_KEY2                     _BAKEY0.Bits.KEY2
#define BAKEY0_KEY3                     _BAKEY0.Bits.KEY3
#define BAKEY0_KEY4                     _BAKEY0.Bits.KEY4
#define BAKEY0_KEY5                     _BAKEY0.Bits.KEY5
#define BAKEY0_KEY6                     _BAKEY0.Bits.KEY6
#define BAKEY0_KEY7                     _BAKEY0.Bits.KEY7
#define BAKEY0_KEY8                     _BAKEY0.Bits.KEY8
#define BAKEY0_KEY9                     _BAKEY0.Bits.KEY9
#define BAKEY0_KEY10                    _BAKEY0.Bits.KEY10
#define BAKEY0_KEY11                    _BAKEY0.Bits.KEY11
#define BAKEY0_KEY12                    _BAKEY0.Bits.KEY12
#define BAKEY0_KEY13                    _BAKEY0.Bits.KEY13
#define BAKEY0_KEY14                    _BAKEY0.Bits.KEY14
#define BAKEY0_KEY15                    _BAKEY0.Bits.KEY15
/* BAKEY_ARR: Access 4 BAKEYx registers in an array */
#define BAKEY_ARR                       ((volatile word *) &BAKEY0)

#define BAKEY0_KEY0_MASK                1U
#define BAKEY0_KEY1_MASK                2U
#define BAKEY0_KEY2_MASK                4U
#define BAKEY0_KEY3_MASK                8U
#define BAKEY0_KEY4_MASK                16U
#define BAKEY0_KEY5_MASK                32U
#define BAKEY0_KEY6_MASK                64U
#define BAKEY0_KEY7_MASK                128U
#define BAKEY0_KEY8_MASK                256U
#define BAKEY0_KEY9_MASK                512U
#define BAKEY0_KEY10_MASK               1024U
#define BAKEY0_KEY11_MASK               2048U
#define BAKEY0_KEY12_MASK               4096U
#define BAKEY0_KEY13_MASK               8192U
#define BAKEY0_KEY14_MASK               16384U
#define BAKEY0_KEY15_MASK               32768U


/*** BAKEY1 - Backdoor Comparison Key 1; 0x0000FF02 ***/
typedef union {
  word Word;
  struct {
    word KEY0        :1;                                       /* Backdoor Comparison Key Bits, bit 0 */
    word KEY1        :1;                                       /* Backdoor Comparison Key Bits, bit 1 */
    word KEY2        :1;                                       /* Backdoor Comparison Key Bits, bit 2 */
    word KEY3        :1;                                       /* Backdoor Comparison Key Bits, bit 3 */
    word KEY4        :1;                                       /* Backdoor Comparison Key Bits, bit 4 */
    word KEY5        :1;                                       /* Backdoor Comparison Key Bits, bit 5 */
    word KEY6        :1;                                       /* Backdoor Comparison Key Bits, bit 6 */
    word KEY7        :1;                                       /* Backdoor Comparison Key Bits, bit 7 */
    word KEY8        :1;                                       /* Backdoor Comparison Key Bits, bit 8 */
    word KEY9        :1;                                       /* Backdoor Comparison Key Bits, bit 9 */
    word KEY10       :1;                                       /* Backdoor Comparison Key Bits, bit 10 */
    word KEY11       :1;                                       /* Backdoor Comparison Key Bits, bit 11 */
    word KEY12       :1;                                       /* Backdoor Comparison Key Bits, bit 12 */
    word KEY13       :1;                                       /* Backdoor Comparison Key Bits, bit 13 */
    word KEY14       :1;                                       /* Backdoor Comparison Key Bits, bit 14 */
    word KEY15       :1;                                       /* Backdoor Comparison Key Bits, bit 15 */
  } Bits;
} BAKEY1STR;
/* Tip for register initialization in the user code:  const word BAKEY1_INIT @0x0000FF02 = <BAKEY1_INITVAL>; */
#define _BAKEY1 (*(const BAKEY1STR *)0x0000FF02)
#define BAKEY1                          _BAKEY1.Word
#define BAKEY1_KEY0                     _BAKEY1.Bits.KEY0
#define BAKEY1_KEY1                     _BAKEY1.Bits.KEY1
#define BAKEY1_KEY2                     _BAKEY1.Bits.KEY2
#define BAKEY1_KEY3                     _BAKEY1.Bits.KEY3
#define BAKEY1_KEY4                     _BAKEY1.Bits.KEY4
#define BAKEY1_KEY5                     _BAKEY1.Bits.KEY5
#define BAKEY1_KEY6                     _BAKEY1.Bits.KEY6
#define BAKEY1_KEY7                     _BAKEY1.Bits.KEY7
#define BAKEY1_KEY8                     _BAKEY1.Bits.KEY8
#define BAKEY1_KEY9                     _BAKEY1.Bits.KEY9
#define BAKEY1_KEY10                    _BAKEY1.Bits.KEY10
#define BAKEY1_KEY11                    _BAKEY1.Bits.KEY11
#define BAKEY1_KEY12                    _BAKEY1.Bits.KEY12
#define BAKEY1_KEY13                    _BAKEY1.Bits.KEY13
#define BAKEY1_KEY14                    _BAKEY1.Bits.KEY14
#define BAKEY1_KEY15                    _BAKEY1.Bits.KEY15

#define BAKEY1_KEY0_MASK                1U
#define BAKEY1_KEY1_MASK                2U
#define BAKEY1_KEY2_MASK                4U
#define BAKEY1_KEY3_MASK                8U
#define BAKEY1_KEY4_MASK                16U
#define BAKEY1_KEY5_MASK                32U
#define BAKEY1_KEY6_MASK                64U
#define BAKEY1_KEY7_MASK                128U
#define BAKEY1_KEY8_MASK                256U
#define BAKEY1_KEY9_MASK                512U
#define BAKEY1_KEY10_MASK               1024U
#define BAKEY1_KEY11_MASK               2048U
#define BAKEY1_KEY12_MASK               4096U
#define BAKEY1_KEY13_MASK               8192U
#define BAKEY1_KEY14_MASK               16384U
#define BAKEY1_KEY15_MASK               32768U


/*** BAKEY2 - Backdoor Comparison Key 2; 0x0000FF04 ***/
typedef union {
  word Word;
  struct {
    word KEY0        :1;                                       /* Backdoor Comparison Key Bits, bit 0 */
    word KEY1        :1;                                       /* Backdoor Comparison Key Bits, bit 1 */
    word KEY2        :1;                                       /* Backdoor Comparison Key Bits, bit 2 */
    word KEY3        :1;                                       /* Backdoor Comparison Key Bits, bit 3 */
    word KEY4        :1;                                       /* Backdoor Comparison Key Bits, bit 4 */
    word KEY5        :1;                                       /* Backdoor Comparison Key Bits, bit 5 */
    word KEY6        :1;                                       /* Backdoor Comparison Key Bits, bit 6 */
    word KEY7        :1;                                       /* Backdoor Comparison Key Bits, bit 7 */
    word KEY8        :1;                                       /* Backdoor Comparison Key Bits, bit 8 */
    word KEY9        :1;                                       /* Backdoor Comparison Key Bits, bit 9 */
    word KEY10       :1;                                       /* Backdoor Comparison Key Bits, bit 10 */
    word KEY11       :1;                                       /* Backdoor Comparison Key Bits, bit 11 */
    word KEY12       :1;                                       /* Backdoor Comparison Key Bits, bit 12 */
    word KEY13       :1;                                       /* Backdoor Comparison Key Bits, bit 13 */
    word KEY14       :1;                                       /* Backdoor Comparison Key Bits, bit 14 */
    word KEY15       :1;                                       /* Backdoor Comparison Key Bits, bit 15 */
  } Bits;
} BAKEY2STR;
/* Tip for register initialization in the user code:  const word BAKEY2_INIT @0x0000FF04 = <BAKEY2_INITVAL>; */
#define _BAKEY2 (*(const BAKEY2STR *)0x0000FF04)
#define BAKEY2                          _BAKEY2.Word
#define BAKEY2_KEY0                     _BAKEY2.Bits.KEY0
#define BAKEY2_KEY1                     _BAKEY2.Bits.KEY1
#define BAKEY2_KEY2                     _BAKEY2.Bits.KEY2
#define BAKEY2_KEY3                     _BAKEY2.Bits.KEY3
#define BAKEY2_KEY4                     _BAKEY2.Bits.KEY4
#define BAKEY2_KEY5                     _BAKEY2.Bits.KEY5
#define BAKEY2_KEY6                     _BAKEY2.Bits.KEY6
#define BAKEY2_KEY7                     _BAKEY2.Bits.KEY7
#define BAKEY2_KEY8                     _BAKEY2.Bits.KEY8
#define BAKEY2_KEY9                     _BAKEY2.Bits.KEY9
#define BAKEY2_KEY10                    _BAKEY2.Bits.KEY10
#define BAKEY2_KEY11                    _BAKEY2.Bits.KEY11
#define BAKEY2_KEY12                    _BAKEY2.Bits.KEY12
#define BAKEY2_KEY13                    _BAKEY2.Bits.KEY13
#define BAKEY2_KEY14                    _BAKEY2.Bits.KEY14
#define BAKEY2_KEY15                    _BAKEY2.Bits.KEY15

#define BAKEY2_KEY0_MASK                1U
#define BAKEY2_KEY1_MASK                2U
#define BAKEY2_KEY2_MASK                4U
#define BAKEY2_KEY3_MASK                8U
#define BAKEY2_KEY4_MASK                16U
#define BAKEY2_KEY5_MASK                32U
#define BAKEY2_KEY6_MASK                64U
#define BAKEY2_KEY7_MASK                128U
#define BAKEY2_KEY8_MASK                256U
#define BAKEY2_KEY9_MASK                512U
#define BAKEY2_KEY10_MASK               1024U
#define BAKEY2_KEY11_MASK               2048U
#define BAKEY2_KEY12_MASK               4096U
#define BAKEY2_KEY13_MASK               8192U
#define BAKEY2_KEY14_MASK               16384U
#define BAKEY2_KEY15_MASK               32768U


/*** BAKEY3 - Backdoor Comparison Key 3; 0x0000FF06 ***/
typedef union {
  word Word;
  struct {
    word KEY0        :1;                                       /* Backdoor Comparison Key Bits, bit 0 */
    word KEY1        :1;                                       /* Backdoor Comparison Key Bits, bit 1 */
    word KEY2        :1;                                       /* Backdoor Comparison Key Bits, bit 2 */
    word KEY3        :1;                                       /* Backdoor Comparison Key Bits, bit 3 */
    word KEY4        :1;                                       /* Backdoor Comparison Key Bits, bit 4 */
    word KEY5        :1;                                       /* Backdoor Comparison Key Bits, bit 5 */
    word KEY6        :1;                                       /* Backdoor Comparison Key Bits, bit 6 */
    word KEY7        :1;                                       /* Backdoor Comparison Key Bits, bit 7 */
    word KEY8        :1;                                       /* Backdoor Comparison Key Bits, bit 8 */
    word KEY9        :1;                                       /* Backdoor Comparison Key Bits, bit 9 */
    word KEY10       :1;                                       /* Backdoor Comparison Key Bits, bit 10 */
    word KEY11       :1;                                       /* Backdoor Comparison Key Bits, bit 11 */
    word KEY12       :1;                                       /* Backdoor Comparison Key Bits, bit 12 */
    word KEY13       :1;                                       /* Backdoor Comparison Key Bits, bit 13 */
    word KEY14       :1;                                       /* Backdoor Comparison Key Bits, bit 14 */
    word KEY15       :1;                                       /* Backdoor Comparison Key Bits, bit 15 */
  } Bits;
} BAKEY3STR;
/* Tip for register initialization in the user code:  const word BAKEY3_INIT @0x0000FF06 = <BAKEY3_INITVAL>; */
#define _BAKEY3 (*(const BAKEY3STR *)0x0000FF06)
#define BAKEY3                          _BAKEY3.Word
#define BAKEY3_KEY0                     _BAKEY3.Bits.KEY0
#define BAKEY3_KEY1                     _BAKEY3.Bits.KEY1
#define BAKEY3_KEY2                     _BAKEY3.Bits.KEY2
#define BAKEY3_KEY3                     _BAKEY3.Bits.KEY3
#define BAKEY3_KEY4                     _BAKEY3.Bits.KEY4
#define BAKEY3_KEY5                     _BAKEY3.Bits.KEY5
#define BAKEY3_KEY6                     _BAKEY3.Bits.KEY6
#define BAKEY3_KEY7                     _BAKEY3.Bits.KEY7
#define BAKEY3_KEY8                     _BAKEY3.Bits.KEY8
#define BAKEY3_KEY9                     _BAKEY3.Bits.KEY9
#define BAKEY3_KEY10                    _BAKEY3.Bits.KEY10
#define BAKEY3_KEY11                    _BAKEY3.Bits.KEY11
#define BAKEY3_KEY12                    _BAKEY3.Bits.KEY12
#define BAKEY3_KEY13                    _BAKEY3.Bits.KEY13
#define BAKEY3_KEY14                    _BAKEY3.Bits.KEY14
#define BAKEY3_KEY15                    _BAKEY3.Bits.KEY15

#define BAKEY3_KEY0_MASK                1U
#define BAKEY3_KEY1_MASK                2U
#define BAKEY3_KEY2_MASK                4U
#define BAKEY3_KEY3_MASK                8U
#define BAKEY3_KEY4_MASK                16U
#define BAKEY3_KEY5_MASK                32U
#define BAKEY3_KEY6_MASK                64U
#define BAKEY3_KEY7_MASK                128U
#define BAKEY3_KEY8_MASK                256U
#define BAKEY3_KEY9_MASK                512U
#define BAKEY3_KEY10_MASK               1024U
#define BAKEY3_KEY11_MASK               2048U
#define BAKEY3_KEY12_MASK               4096U
#define BAKEY3_KEY13_MASK               8192U
#define BAKEY3_KEY14_MASK               16384U
#define BAKEY3_KEY15_MASK               32768U


/*** NVFPROT - Non Volatile P-Flash Protection Register; 0x0000FF0C ***/
typedef union {
  byte Byte;
  struct {
    byte FPLS0       :1;                                       /* Flash Protection Lower Address Size Bit 0 */
    byte FPLS1       :1;                                       /* Flash Protection Lower Address Size Bit 1 */
    byte FPLDIS      :1;                                       /* Flash Protection Lower Address Range Disable */
    byte FPHS0       :1;                                       /* Flash Protection Higher Address Size Bit 0 */
    byte FPHS1       :1;                                       /* Flash Protection Higher Address Size Bit 1 */
    byte FPHDIS      :1;                                       /* Flash Protection Higher Address Range Disable */
    byte RNV6        :1;                                       /* Reserved Nonvolatile Bit */
    byte FPOPEN      :1;                                       /* Flash Protection Operation Enable */
  } Bits;
  struct {
    byte grpFPLS :2;
    byte         :1;
    byte grpFPHS :2;
    byte         :1;
    byte grpRNV_6 :1;
    byte         :1;
  } MergedBits;
} NVFPROTSTR;
/* Tip for register initialization in the user code:  const byte NVFPROT_INIT @0x0000FF0C = <NVFPROT_INITVAL>; */
#define _NVFPROT (*(const NVFPROTSTR *)0x0000FF0C)
#define NVFPROT                         _NVFPROT.Byte
#define NVFPROT_FPLS0                   _NVFPROT.Bits.FPLS0
#define NVFPROT_FPLS1                   _NVFPROT.Bits.FPLS1
#define NVFPROT_FPLDIS                  _NVFPROT.Bits.FPLDIS
#define NVFPROT_FPHS0                   _NVFPROT.Bits.FPHS0
#define NVFPROT_FPHS1                   _NVFPROT.Bits.FPHS1
#define NVFPROT_FPHDIS                  _NVFPROT.Bits.FPHDIS
#define NVFPROT_RNV6                    _NVFPROT.Bits.RNV6
#define NVFPROT_FPOPEN                  _NVFPROT.Bits.FPOPEN
#define NVFPROT_FPLS                    _NVFPROT.MergedBits.grpFPLS
#define NVFPROT_FPHS                    _NVFPROT.MergedBits.grpFPHS

#define NVFPROT_FPLS0_MASK              1U
#define NVFPROT_FPLS1_MASK              2U
#define NVFPROT_FPLDIS_MASK             4U
#define NVFPROT_FPHS0_MASK              8U
#define NVFPROT_FPHS1_MASK              16U
#define NVFPROT_FPHDIS_MASK             32U
#define NVFPROT_RNV6_MASK               64U
#define NVFPROT_FPOPEN_MASK             128U
#define NVFPROT_FPLS_MASK               3U
#define NVFPROT_FPLS_BITNUM             0U
#define NVFPROT_FPHS_MASK               24U
#define NVFPROT_FPHS_BITNUM             3U


/*** NVDFPROT - Non Volatile D-Flash Protection Register; 0x0000FF0D ***/
typedef union {
  byte Byte;
  struct {
    byte DPS0        :1;                                       /* D-Flash Protection Size Bit 0 */
    byte DPS1        :1;                                       /* D-Flash Protection Size Bit 1 */
    byte DPS2        :1;                                       /* D-Flash Protection Size Bit 2 */
    byte DPS3        :1;                                       /* D-Flash Protection Size Bit 3 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte DPOPEN      :1;                                       /* D-Flash Protection Control */
  } Bits;
  struct {
    byte grpDPS  :4;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} NVDFPROTSTR;
/* Tip for register initialization in the user code:  const byte NVDFPROT_INIT @0x0000FF0D = <NVDFPROT_INITVAL>; */
#define _NVDFPROT (*(const NVDFPROTSTR *)0x0000FF0D)
#define NVDFPROT                        _NVDFPROT.Byte
#define NVDFPROT_DPS0                   _NVDFPROT.Bits.DPS0
#define NVDFPROT_DPS1                   _NVDFPROT.Bits.DPS1
#define NVDFPROT_DPS2                   _NVDFPROT.Bits.DPS2
#define NVDFPROT_DPS3                   _NVDFPROT.Bits.DPS3
#define NVDFPROT_DPOPEN                 _NVDFPROT.Bits.DPOPEN
#define NVDFPROT_DPS                    _NVDFPROT.MergedBits.grpDPS

#define NVDFPROT_DPS0_MASK              1U
#define NVDFPROT_DPS1_MASK              2U
#define NVDFPROT_DPS2_MASK              4U
#define NVDFPROT_DPS3_MASK              8U
#define NVDFPROT_DPOPEN_MASK            128U
#define NVDFPROT_DPS_MASK               15U
#define NVDFPROT_DPS_BITNUM             0U


/*** NVFOPT - Non Volatile Flash Option Register; 0x0000FF0E ***/
typedef union {
  byte Byte;
  struct {
    byte NV0         :1;                                       /* Nonvolatile Bit 0 */
    byte NV1         :1;                                       /* Nonvolatile Bit 1 */
    byte NV2         :1;                                       /* Nonvolatile Bit 2 */
    byte NV3         :1;                                       /* Nonvolatile Bit 3 */
    byte NV4         :1;                                       /* Nonvolatile Bit 4 */
    byte NV5         :1;                                       /* Nonvolatile Bit 5 */
    byte NV6         :1;                                       /* Nonvolatile Bit 6 */
    byte NV7         :1;                                       /* Nonvolatile Bit 7 */
  } Bits;
} NVFOPTSTR;
/* Tip for register initialization in the user code:  const byte NVFOPT_INIT @0x0000FF0E = <NVFOPT_INITVAL>; */
#define _NVFOPT (*(const NVFOPTSTR *)0x0000FF0E)
#define NVFOPT                          _NVFOPT.Byte
#define NVFOPT_NV0                      _NVFOPT.Bits.NV0
#define NVFOPT_NV1                      _NVFOPT.Bits.NV1
#define NVFOPT_NV2                      _NVFOPT.Bits.NV2
#define NVFOPT_NV3                      _NVFOPT.Bits.NV3
#define NVFOPT_NV4                      _NVFOPT.Bits.NV4
#define NVFOPT_NV5                      _NVFOPT.Bits.NV5
#define NVFOPT_NV6                      _NVFOPT.Bits.NV6
#define NVFOPT_NV7                      _NVFOPT.Bits.NV7

#define NVFOPT_NV0_MASK                 1U
#define NVFOPT_NV1_MASK                 2U
#define NVFOPT_NV2_MASK                 4U
#define NVFOPT_NV3_MASK                 8U
#define NVFOPT_NV4_MASK                 16U
#define NVFOPT_NV5_MASK                 32U
#define NVFOPT_NV6_MASK                 64U
#define NVFOPT_NV7_MASK                 128U


/*** NVFSEC - Non Volatile Flash Security Register; 0x0000FF0F ***/
typedef union {
  byte Byte;
  struct {
    byte SEC0        :1;                                       /* Flash Security Bit 0 */
    byte SEC1        :1;                                       /* Flash Security Bit 1 */
    byte RNV2        :1;                                       /* Reserved Nonvolatile Bit 2 */
    byte RNV3        :1;                                       /* Reserved Nonvolatile Bit 3 */
    byte RNV4        :1;                                       /* Reserved Nonvolatile Bit 4 */
    byte RNV5        :1;                                       /* Reserved Nonvolatile Bit 5 */
    byte KEYEN0      :1;                                       /* Backdoor Key Security Enable Bit 0 */
    byte KEYEN1      :1;                                       /* Backdoor Key Security Enable Bit 1 */
  } Bits;
  struct {
    byte grpSEC  :2;
    byte grpRNV_2 :4;
    byte grpKEYEN :2;
  } MergedBits;
} NVFSECSTR;
/* Tip for register initialization in the user code:  const byte NVFSEC_INIT @0x0000FF0F = <NVFSEC_INITVAL>; */
#define _NVFSEC (*(const NVFSECSTR *)0x0000FF0F)
#define NVFSEC                          _NVFSEC.Byte
#define NVFSEC_SEC0                     _NVFSEC.Bits.SEC0
#define NVFSEC_SEC1                     _NVFSEC.Bits.SEC1
#define NVFSEC_RNV2                     _NVFSEC.Bits.RNV2
#define NVFSEC_RNV3                     _NVFSEC.Bits.RNV3
#define NVFSEC_RNV4                     _NVFSEC.Bits.RNV4
#define NVFSEC_RNV5                     _NVFSEC.Bits.RNV5
#define NVFSEC_KEYEN0                   _NVFSEC.Bits.KEYEN0
#define NVFSEC_KEYEN1                   _NVFSEC.Bits.KEYEN1
#define NVFSEC_SEC                      _NVFSEC.MergedBits.grpSEC
#define NVFSEC_RNV_2                    _NVFSEC.MergedBits.grpRNV_2
#define NVFSEC_KEYEN                    _NVFSEC.MergedBits.grpKEYEN
#define NVFSEC_RNV                      NVFSEC_RNV_2

#define NVFSEC_SEC0_MASK                1U
#define NVFSEC_SEC1_MASK                2U
#define NVFSEC_RNV2_MASK                4U
#define NVFSEC_RNV3_MASK                8U
#define NVFSEC_RNV4_MASK                16U
#define NVFSEC_RNV5_MASK                32U
#define NVFSEC_KEYEN0_MASK              64U
#define NVFSEC_KEYEN1_MASK              128U
#define NVFSEC_SEC_MASK                 3U
#define NVFSEC_SEC_BITNUM               0U
#define NVFSEC_RNV_2_MASK               60U
#define NVFSEC_RNV_2_BITNUM             2U
#define NVFSEC_KEYEN_MASK               192U
#define NVFSEC_KEYEN_BITNUM             6U


  /* Watchdog reset macro */
#ifndef __RESET_WATCHDOG
#ifdef _lint
  #define __RESET_WATCHDOG()  /* empty */
#else
  #define __RESET_WATCHDOG() (void)(CPMUARMCOP = 0x55U, CPMUARMCOP = 0xAAU)
#endif
#endif /* __RESET_WATCHDOG */


/***********************************************/
/**   D E P R E C I A T E D   S Y M B O L S   **/
/***********************************************/
/* --------------------------------------------------------------------------- */
/* The following symbols were removed, because they were invalid or irrelevant */
/* --------------------------------------------------------------------------- */



/* **** 14.4.2010 13:19:27 */

#define NVDFPROT_DPS4                    This_symb_has_been_depreciated
#define NVDFPROT_DPS4_MASK               This_symb_has_been_depreciated

#ifndef __V30COMPATIBLE__
#pragma OPTION DEL V30toV31Compatible
#endif
/*lint -restore  +esym(961,18.4) +esym(961,19.7) Enable MISRA rule (1.1,18.4,6.4,19.7) checking. */

#endif
