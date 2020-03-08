/* Based on CPU DB MC9S12HY64_100, version 3.00.001 (RegistersPrg V2.28) */
/* DataSheet : MC9S12HY64RMV1 Rev. 1.00 07/2009 */

#include <mc9s12hy48.h>

/*lint -save -esym(765, *) */


/* * * * *  8-BIT REGISTERS  * * * * * * * * * * * * * * * */
volatile MODESTR _MODE;                                    /* Mode Register; 0x0000000B */
volatile PUCRSTR _PUCR;                                    /* Pull-Up Control Register; 0x0000000C */
volatile RDRIVSTR _RDRIV;                                  /* Reduced Drive Register; 0x0000000D */
volatile DIRECTSTR _DIRECT;                                /* Direct Page Register; 0x00000011 */
volatile PPAGESTR _PPAGE;                                  /* Program Page Index Register; 0x00000015 */
volatile ECLKCTLSTR _ECLKCTL;                              /* ECLK Control Register; 0x0000001C */
volatile IRQCRSTR _IRQCR;                                  /* Interrupt Control Register; 0x0000001E */
volatile DBGC1STR _DBGC1;                                  /* Debug Control Register 1; 0x00000020 */
volatile DBGSRSTR _DBGSR;                                  /* Debug Status Register; 0x00000021 */
volatile DBGTCRSTR _DBGTCR;                                /* Debug Trace Control Register; 0x00000022 */
volatile DBGC2STR _DBGC2;                                  /* Debug Control Register 2; 0x00000023 */
volatile DBGCNTSTR _DBGCNT;                                /* Debug Count Register; 0x00000026 */
volatile DBGSCRXSTR _DBGSCRX;                              /* Debug State Control Register; 0x00000027 */
volatile DBGXCTLSTR _DBGXCTL;                              /* Debug Comparator Control Register; 0x00000028 */
volatile DBGXAHSTR _DBGXAH;                                /* Debug Comparator Address High Register; 0x00000029 */
volatile DBGXAMSTR _DBGXAM;                                /* Debug Comparator Address Mid Register; 0x0000002A */
volatile DBGXALSTR _DBGXAL;                                /* Debug Comparator Address Low Register; 0x0000002B */
volatile DBGADHSTR _DBGADH;                                /* Debug Comparator Data High Register; 0x0000002C */
volatile DBGADLSTR _DBGADL;                                /* Debug Comparator Data Low Register; 0x0000002D */
volatile DBGADHMSTR _DBGADHM;                              /* Debug Comparator Data High Mask Register; 0x0000002E */
volatile DBGADLMSTR _DBGADLM;                              /* Debug Comparator Data Low Mask Register; 0x0000002F */
volatile CPMUSYNRSTR _CPMUSYNR;                            /* S12CPMU Synthesizer Register; 0x00000034 */
volatile CPMUREFDIVSTR _CPMUREFDIV;                        /* S12CPMU Reference Divider Register; 0x00000035 */
volatile CPMUPOSTDIVSTR _CPMUPOSTDIV;                      /* S12CPMU Post Divider Register; 0x00000036 */
volatile CPMUFLGSTR _CPMUFLG;                              /* S12CPMU Flags Register; 0x00000037 */
volatile CPMUINTSTR _CPMUINT;                              /* S12CPMU Interrupt Enable Register; 0x00000038 */
volatile CPMUCLKSSTR _CPMUCLKS;                            /* S12CPMU Clock Select Register; 0x00000039 */
volatile CPMUPLLSTR _CPMUPLL;                              /* S12CPMU PLL Control Register; 0x0000003A */
volatile CPMURTISTR _CPMURTI;                              /* CPMU RTI Control Register; 0x0000003B */
volatile CPMUCOPSTR _CPMUCOP;                              /* CPMU COP Control Register; 0x0000003C */
volatile CPMUARMCOPSTR _CPMUARMCOP;                        /* CPMU COP Timer Arm/Reset Register; 0x0000003F */
volatile TIM0_TIOSSTR _TIM0_TIOS;                          /* Timer Input Capture/Output Compare Select; 0x00000040 */
volatile TIM0_CFORCSTR _TIM0_CFORC;                        /* Timer Compare Force Register; 0x00000041 */
volatile TIM0_OC7MSTR _TIM0_OC7M;                          /* Output Compare 7 Mask Register; 0x00000042 */
volatile TIM0_OC7DSTR _TIM0_OC7D;                          /* Output Compare 7 Data Register; 0x00000043 */
volatile TIM0_TSCR1STR _TIM0_TSCR1;                        /* Timer System Control Register1; 0x00000046 */
volatile TIM0_TTOVSTR _TIM0_TTOV;                          /* Timer Toggle On Overflow Register; 0x00000047 */
volatile TIM0_TCTL1STR _TIM0_TCTL1;                        /* Timer Control Register 1; 0x00000048 */
volatile TIM0_TCTL2STR _TIM0_TCTL2;                        /* Timer Control Register 2; 0x00000049 */
volatile TIM0_TCTL3STR _TIM0_TCTL3;                        /* Timer Control Register 3; 0x0000004A */
volatile TIM0_TCTL4STR _TIM0_TCTL4;                        /* Timer Control Register 4; 0x0000004B */
volatile TIM0_TIESTR _TIM0_TIE;                            /* Timer Interrupt Enable Register; 0x0000004C */
volatile TIM0_TSCR2STR _TIM0_TSCR2;                        /* Timer System Control Register 2; 0x0000004D */
volatile TIM0_TFLG1STR _TIM0_TFLG1;                        /* Main Timer Interrupt Flag 1; 0x0000004E */
volatile TIM0_TFLG2STR _TIM0_TFLG2;                        /* Main Timer Interrupt Flag 2; 0x0000004F */
volatile TIM0_PACTLSTR _TIM0_PACTL;                        /* 16-Bit Pulse Accumulator A Control Register; 0x00000060 */
volatile TIM0_PAFLGSTR _TIM0_PAFLG;                        /* Pulse Accumulator A Flag Register; 0x00000061 */
volatile TIM0_OCPDSTR _TIM0_OCPD;                          /* Output Compare Pin Disconnect Register; 0x0000006C */
volatile TIM0_PTPSRSTR _TIM0_PTPSR;                        /* Precision Timer Prescaler Select Register; 0x0000006E */
volatile ATDSTAT0STR _ATDSTAT0;                            /* ATD  Status Register 0; 0x00000076 */
volatile PWMESTR _PWME;                                    /* PWM Enable Register; 0x000000A0 */
volatile PWMPOLSTR _PWMPOL;                                /* PWM Polarity Register; 0x000000A1 */
volatile PWMCLKSTR _PWMCLK;                                /* PWM Clock Select Register; 0x000000A2 */
volatile PWMPRCLKSTR _PWMPRCLK;                            /* PWM Prescale Clock Select Register; 0x000000A3 */
volatile PWMCAESTR _PWMCAE;                                /* PWM Center Align Enable Register; 0x000000A4 */
volatile PWMCTLSTR _PWMCTL;                                /* PWM Control Register; 0x000000A5 */
volatile PWMSCLASTR _PWMSCLA;                              /* PWM Scale A Register; 0x000000A8 */
volatile PWMSCLBSTR _PWMSCLB;                              /* PWM Scale B Register; 0x000000A9 */
volatile PWMSDNSTR _PWMSDN;                                /* PWM Shutdown Register; 0x000000C4 */
volatile SCIACR2STR _SCIACR2;                              /* SCI  Alternative Control Register 2; 0x000000CA */
volatile SCICR2STR _SCICR2;                                /* SCI  Control Register 2; 0x000000CB */
volatile SCISR1STR _SCISR1;                                /* SCI  Status Register 1; 0x000000CC */
volatile SCISR2STR _SCISR2;                                /* SCI  Status Register 2; 0x000000CD */
volatile SCIDRHSTR _SCIDRH;                                /* SCI  Data Register High; 0x000000CE */
volatile SCIDRLSTR _SCIDRL;                                /* SCI  Data Register Low; 0x000000CF */
volatile SPICR1STR _SPICR1;                                /* SPI  Control Register 1; 0x000000D8 */
volatile SPICR2STR _SPICR2;                                /* SPI  Control Register 2; 0x000000D9 */
volatile SPIBRSTR _SPIBR;                                  /* SPI  Baud Rate Register; 0x000000DA */
volatile SPISRSTR _SPISR;                                  /* SPI  Status Register; 0x000000DB */
volatile IIC_IBADSTR _IIC_IBAD;                            /* IIC Address Register; 0x000000E0 */
volatile IIC_IBFDSTR _IIC_IBFD;                            /* IIC Frequency Divider Register; 0x000000E1 */
volatile IIC_IBCRSTR _IIC_IBCR;                            /* IIC Control Register; 0x000000E2 */
volatile IIC_IBSRSTR _IIC_IBSR;                            /* IIC Status Register; 0x000000E3 */
volatile IIC_IBDRSTR _IIC_IBDR;                            /* IIC Data I/O Register; 0x000000E4 */
volatile IIC_IBCR2STR _IIC_IBCR2;                          /* IIC Control Register 2; 0x000000E5 */
volatile FCLKDIVSTR _FCLKDIV;                              /* Flash Clock Divider Register; 0x00000100 */
volatile FSECSTR _FSEC;                                    /* Flash Security Register; 0x00000101 */
volatile FCCOBIXSTR _FCCOBIX;                              /* Flash CCOB Index Register; 0x00000102 */
volatile FCNFGSTR _FCNFG;                                  /* Flash Configuration Register; 0x00000104 */
volatile FERCNFGSTR _FERCNFG;                              /* Flash Error Configuration Register; 0x00000105 */
volatile FSTATSTR _FSTAT;                                  /* Flash Status Register; 0x00000106 */
volatile FERSTATSTR _FERSTAT;                              /* Flash Error Status Register; 0x00000107 */
volatile FPROTSTR _FPROT;                                  /* P-Flash Protection Register; 0x00000108 */
volatile DFPROTSTR _DFPROT;                                /* D-Flash Protection Register; 0x00000109 */
volatile FOPTSTR _FOPT;                                    /* Flash Option Register; 0x00000110 */
volatile IVBRSTR _IVBR;                                    /* Interrupt Vector Base Register; 0x00000120 */
volatile CANCTL0STR _CANCTL0;                              /* MSCAN Control 0 Register; 0x00000140 */
volatile CANCTL1STR _CANCTL1;                              /* MSCAN Control 1 Register; 0x00000141 */
volatile CANBTR0STR _CANBTR0;                              /* MSCAN Bus Timing Register 0; 0x00000142 */
volatile CANBTR1STR _CANBTR1;                              /* MSCAN Bus Timing Register 1; 0x00000143 */
volatile CANRFLGSTR _CANRFLG;                              /* MSCAN Receiver Flag Register; 0x00000144 */
volatile CANRIERSTR _CANRIER;                              /* MSCAN Receiver Interrupt Enable Register; 0x00000145 */
volatile CANTFLGSTR _CANTFLG;                              /* MSCAN Transmitter Flag Register; 0x00000146 */
volatile CANTIERSTR _CANTIER;                              /* MSCAN Transmitter Interrupt Enable Register; 0x00000147 */
volatile CANTARQSTR _CANTARQ;                              /* MSCAN Transmitter Message Abort Request; 0x00000148 */
volatile CANTAAKSTR _CANTAAK;                              /* MSCAN Transmitter Message Abort Acknowledge; 0x00000149 */
volatile CANTBSELSTR _CANTBSEL;                            /* MSCAN Transmit Buffer Selection; 0x0000014A */
volatile CANIDACSTR _CANIDAC;                              /* MSCAN Identifier Acceptance Control Register; 0x0000014B */
volatile CANMISCSTR _CANMISC;                              /* MSCAN Miscellaneous Register; 0x0000014D */
volatile CANRXERRSTR _CANRXERR;                            /* MSCAN Receive Error Counter Register; 0x0000014E */
volatile CANTXERRSTR _CANTXERR;                            /* MSCAN Transmit Error Counter Register; 0x0000014F */
volatile CANIDAR0STR _CANIDAR0;                            /* MSCAN Identifier Acceptance Register 0; 0x00000150 */
volatile CANIDAR1STR _CANIDAR1;                            /* MSCAN Identifier Acceptance Register 1; 0x00000151 */
volatile CANIDAR2STR _CANIDAR2;                            /* MSCAN Identifier Acceptance Register 2; 0x00000152 */
volatile CANIDAR3STR _CANIDAR3;                            /* MSCAN Identifier Acceptance Register 3; 0x00000153 */
volatile CANIDMR0STR _CANIDMR0;                            /* MSCAN Identifier Mask Register 0; 0x00000154 */
volatile CANIDMR1STR _CANIDMR1;                            /* MSCAN Identifier Mask Register 1; 0x00000155 */
volatile CANIDMR2STR _CANIDMR2;                            /* MSCAN Identifier Mask Register 2; 0x00000156 */
volatile CANIDMR3STR _CANIDMR3;                            /* MSCAN Identifier Mask Register 3; 0x00000157 */
volatile CANIDAR4STR _CANIDAR4;                            /* MSCAN Identifier Acceptance Register 4; 0x00000158 */
volatile CANIDAR5STR _CANIDAR5;                            /* MSCAN Identifier Acceptance Register 5; 0x00000159 */
volatile CANIDAR6STR _CANIDAR6;                            /* MSCAN Identifier Acceptance Register 6; 0x0000015A */
volatile CANIDAR7STR _CANIDAR7;                            /* MSCAN Identifier Acceptance Register 7; 0x0000015B */
volatile CANIDMR4STR _CANIDMR4;                            /* MSCAN Identifier Mask Register 4; 0x0000015C */
volatile CANIDMR5STR _CANIDMR5;                            /* MSCAN Identifier Mask Register 5; 0x0000015D */
volatile CANIDMR6STR _CANIDMR6;                            /* MSCAN Identifier Mask Register 6; 0x0000015E */
volatile CANIDMR7STR _CANIDMR7;                            /* MSCAN Identifier Mask Register 7; 0x0000015F */
volatile CANRXIDR0STR _CANRXIDR0;                          /* MSCAN Receive Identifier Register 0; 0x00000160 */
volatile CANRXIDR1STR _CANRXIDR1;                          /* MSCAN Receive Identifier Register 1; 0x00000161 */
volatile CANRXIDR2STR _CANRXIDR2;                          /* MSCAN Receive Identifier Register 2; 0x00000162 */
volatile CANRXIDR3STR _CANRXIDR3;                          /* MSCAN Receive Identifier Register 3; 0x00000163 */
volatile CANRXDSR0STR _CANRXDSR0;                          /* MSCAN Receive Data Segment Register 0; 0x00000164 */
volatile CANRXDSR1STR _CANRXDSR1;                          /* MSCAN Receive Data Segment Register 1; 0x00000165 */
volatile CANRXDSR2STR _CANRXDSR2;                          /* MSCAN Receive Data Segment Register 2; 0x00000166 */
volatile CANRXDSR3STR _CANRXDSR3;                          /* MSCAN Receive Data Segment Register 3; 0x00000167 */
volatile CANRXDSR4STR _CANRXDSR4;                          /* MSCAN Receive Data Segment Register 4; 0x00000168 */
volatile CANRXDSR5STR _CANRXDSR5;                          /* MSCAN Receive Data Segment Register 5; 0x00000169 */
volatile CANRXDSR6STR _CANRXDSR6;                          /* MSCAN Receive Data Segment Register 6; 0x0000016A */
volatile CANRXDSR7STR _CANRXDSR7;                          /* MSCAN Receive Data Segment Register 7; 0x0000016B */
volatile CANRXDLRSTR _CANRXDLR;                            /* MSCAN Receive Data Length Register; 0x0000016C */
volatile CANTXIDR0STR _CANTXIDR0;                          /* MSCAN Transmit Identifier Register 0; 0x00000170 */
volatile CANTXIDR1STR _CANTXIDR1;                          /* MSCAN Transmit Identifier Register 1; 0x00000171 */
volatile CANTXIDR2STR _CANTXIDR2;                          /* MSCAN Transmit Identifier Register 2; 0x00000172 */
volatile CANTXIDR3STR _CANTXIDR3;                          /* MSCAN Transmit Identifier Register 3; 0x00000173 */
volatile CANTXDSR0STR _CANTXDSR0;                          /* MSCAN Transmit Data Segment Register 0; 0x00000174 */
volatile CANTXDSR1STR _CANTXDSR1;                          /* MSCAN Transmit Data Segment Register 1; 0x00000175 */
volatile CANTXDSR2STR _CANTXDSR2;                          /* MSCAN Transmit Data Segment Register 2; 0x00000176 */
volatile CANTXDSR3STR _CANTXDSR3;                          /* MSCAN Transmit Data Segment Register 3; 0x00000177 */
volatile CANTXDSR4STR _CANTXDSR4;                          /* MSCAN Transmit Data Segment Register 4; 0x00000178 */
volatile CANTXDSR5STR _CANTXDSR5;                          /* MSCAN Transmit Data Segment Register 5; 0x00000179 */
volatile CANTXDSR6STR _CANTXDSR6;                          /* MSCAN Transmit Data Segment Register 6; 0x0000017A */
volatile CANTXDSR7STR _CANTXDSR7;                          /* MSCAN Transmit Data Segment Register 7; 0x0000017B */
volatile CANTXDLRSTR _CANTXDLR;                            /* MSCAN Transmit Data Length Register; 0x0000017C */
volatile CANTXTBPRSTR _CANTXTBPR;                          /* MSCAN Transmit Buffer Priority; 0x0000017D */
volatile MCCTL0STR _MCCTL0;                                /* Motor Controller Control Register 0; 0x000001C0 */
volatile MCCTL1STR _MCCTL1;                                /* Motor Controller Control Register 1; 0x000001C1 */
volatile MCCC0STR _MCCC0;                                  /* Motor Controller Control Register 0; 0x000001D0 */
volatile MCCC1STR _MCCC1;                                  /* Motor Controller Control Register 1; 0x000001D1 */
volatile MCCC2STR _MCCC2;                                  /* Motor Controller Control Register 2; 0x000001D2 */
volatile MCCC3STR _MCCC3;                                  /* Motor Controller Control Register 3; 0x000001D3 */
volatile MCCC4STR _MCCC4;                                  /* Motor Controller Control Register 4; 0x000001D4 */
volatile MCCC5STR _MCCC5;                                  /* Motor Controller Control Register 5; 0x000001D5 */
volatile MCCC6STR _MCCC6;                                  /* Motor Controller Control Register 6; 0x000001D6 */
volatile MCCC7STR _MCCC7;                                  /* Motor Controller Control Register 7; 0x000001D7 */
volatile LCDCR0STR _LCDCR0;                                /* LCD Control Register 0; 0x00000200 */
volatile LCDCR1STR _LCDCR1;                                /* LCD Control Register 1; 0x00000201 */
volatile FPENR0STR _FPENR0;                                /* LCD Frontplane Enable Register 0; 0x00000202 */
volatile FPENR1STR _FPENR1;                                /* LCD Frontplane Enable Register 1; 0x00000203 */
volatile FPENR2STR _FPENR2;                                /* LCD Frontplane Enable Register 2; 0x00000204 */
volatile FPENR3STR _FPENR3;                                /* LCD Frontplane Enable Register 3; 0x00000205 */
volatile FPENR4STR _FPENR4;                                /* LCD Frontplane Enable Register 4; 0x00000206 */
volatile LCDRAM0STR _LCDRAM0;                              /* LCD RAM 0; 0x00000208 */
volatile LCDRAM1STR _LCDRAM1;                              /* LCD RAM 1; 0x00000209 */
volatile LCDRAM2STR _LCDRAM2;                              /* LCD RAM 2; 0x0000020A */
volatile LCDRAM3STR _LCDRAM3;                              /* LCD RAM 3; 0x0000020B */
volatile LCDRAM4STR _LCDRAM4;                              /* LCD RAM 4; 0x0000020C */
volatile LCDRAM5STR _LCDRAM5;                              /* LCD RAM 5; 0x0000020D */
volatile LCDRAM6STR _LCDRAM6;                              /* LCD RAM 6; 0x0000020E */
volatile LCDRAM7STR _LCDRAM7;                              /* LCD RAM 7; 0x0000020F */
volatile LCDRAM8STR _LCDRAM8;                              /* LCD RAM 8; 0x00000210 */
volatile LCDRAM9STR _LCDRAM9;                              /* LCD RAM 9; 0x00000211 */
volatile LCDRAM10STR _LCDRAM10;                            /* LCD RAM 10; 0x00000212 */
volatile LCDRAM11STR _LCDRAM11;                            /* LCD RAM 11; 0x00000213 */
volatile LCDRAM12STR _LCDRAM12;                            /* LCD RAM 12; 0x00000214 */
volatile LCDRAM13STR _LCDRAM13;                            /* LCD RAM 13; 0x00000215 */
volatile LCDRAM14STR _LCDRAM14;                            /* LCD RAM 14; 0x00000216 */
volatile LCDRAM15STR _LCDRAM15;                            /* LCD RAM 15; 0x00000217 */
volatile LCDRAM16STR _LCDRAM16;                            /* LCD RAM 16; 0x00000218 */
volatile LCDRAM17STR _LCDRAM17;                            /* LCD RAM 17; 0x00000219 */
volatile LCDRAM18STR _LCDRAM18;                            /* LCD RAM 18; 0x0000021A */
volatile LCDRAM19STR _LCDRAM19;                            /* LCD RAM 19; 0x0000021B */
volatile PTTSTR _PTT;                                      /* Port T Data Register; 0x00000240 */
volatile PTITSTR _PTIT;                                    /* Port T Input Register; 0x00000241 */
volatile DDRTSTR _DDRT;                                    /* Port T Data Direction Register; 0x00000242 */
volatile RDRTSTR _RDRT;                                    /* Port T Reduced Drive Register; 0x00000243 */
volatile PERTSTR _PERT;                                    /* Port T Pull Device Enable Register; 0x00000244 */
volatile PPSTSTR _PPST;                                    /* Port T Polarity Select Register; 0x00000245 */
volatile PTTRRSTR _PTTRR;                                  /* Port T Routing Register; 0x00000247 */
volatile PTSSTR _PTS;                                      /* Port S Data Register; 0x00000248 */
volatile PTISSTR _PTIS;                                    /* Port S Input Register; 0x00000249 */
volatile DDRSSTR _DDRS;                                    /* Port S Data Direction Register; 0x0000024A */
volatile RDRSSTR _RDRS;                                    /* Port S Reduced Drive Register; 0x0000024B */
volatile PERSSTR _PERS;                                    /* Port S Pull Device Enable Register; 0x0000024C */
volatile PPSSSTR _PPSS;                                    /* Port S Polarity Select Register; 0x0000024D */
volatile WOMSSTR _WOMS;                                    /* Port S Wired-Or Mode Register; 0x0000024E */
volatile PTSRRSTR _PTSRR;                                  /* Port S Routing Register; 0x0000024F */
volatile PTPSTR _PTP;                                      /* Port P Data Register; 0x00000258 */
volatile PTIPSTR _PTIP;                                    /* Port P Input Register; 0x00000259 */
volatile DDRPSTR _DDRP;                                    /* Port P Data Direction Register; 0x0000025A */
volatile RDRPSTR _RDRP;                                    /* Port P Reduced Drive Register; 0x0000025B */
volatile PERPSTR _PERP;                                    /* Port P Pull Device Enable Register; 0x0000025C */
volatile PPSPSTR _PPSP;                                    /* Port P Polarity Select Register; 0x0000025D */
volatile PTHSTR _PTH;                                      /* Port H Data Register; 0x00000260 */
volatile PTIHSTR _PTIH;                                    /* Port H Input Register; 0x00000261 */
volatile DDRHSTR _DDRH;                                    /* Port H Data Direction Register; 0x00000262 */
volatile RDRHSTR _RDRH;                                    /* Port H Reduced Drive Register; 0x00000263 */
volatile PERHSTR _PERH;                                    /* Port H Pull Device Enable Register; 0x00000264 */
volatile PPSHSTR _PPSH;                                    /* Port H Polarity Select Register; 0x00000265 */
volatile WOMHSTR _WOMH;                                    /* Port H Wired-Or Mode Register; 0x00000266 */
volatile PT1ADSTR _PT1AD;                                  /* Port AD Data Register; 0x00000271 */
volatile DDR1ADSTR _DDR1AD;                                /* Port AD Data Direction Register; 0x00000273 */
volatile RDR1ADSTR _RDR1AD;                                /* Port AD Reduced Drive Register; 0x00000275 */
volatile PER1ADSTR _PER1AD;                                /* Port AD Pull Up Enable Register; 0x00000277 */
volatile PTRSTR _PTR;                                      /* Port R Data Register; 0x00000280 */
volatile PTIRSTR _PTIR;                                    /* Port R Input Register; 0x00000281 */
volatile DDRRSTR _DDRR;                                    /* Port R Data Direction Register; 0x00000282 */
volatile RDRRSTR _RDRR;                                    /* Port R Reduced Drive Register; 0x00000283 */
volatile PERRSTR _PERR;                                    /* Port R Pull Device Enable Register; 0x00000284 */
volatile PPSRSTR _PPSR;                                    /* Port R Polarity Select Register; 0x00000285 */
volatile WOMRSTR _WOMR;                                    /* Port R Wired-Or Mode Register; 0x00000286 */
volatile PIETSTR _PIET;                                    /* Port T Interrupt Enable Register; 0x00000288 */
volatile PIFTSTR _PIFT;                                    /* Port T Interrupt Flag Register; 0x00000289 */
volatile PIESSTR _PIES;                                    /* Port S Interrupt Enable Register; 0x0000028A */
volatile PIFSSTR _PIFS;                                    /* Port S Interrupt Flag Register; 0x0000028B */
volatile PIE1ADSTR _PIE1AD;                                /* Port AD Interrupt Enable Register; 0x0000028C */
volatile PIF1ADSTR _PIF1AD;                                /* Port AD Interrupt Flag Register; 0x0000028D */
volatile PIERSTR _PIER;                                    /* Port R Interrupt Enable Register; 0x0000028E */
volatile PIFRSTR _PIFR;                                    /* Port R Interrupt Flag Register; 0x0000028F */
volatile PTUSTR _PTU;                                      /* Port U Data Register; 0x00000290 */
volatile PTIUSTR _PTIU;                                    /* Port U Input Register; 0x00000291 */
volatile DDRUSTR _DDRU;                                    /* Port U Data Direction Register; 0x00000292 */
volatile PERUSTR _PERU;                                    /* Port U Pull Device Enable Register; 0x00000294 */
volatile PPSUSTR _PPSU;                                    /* Port U Polarity Select Register; 0x00000295 */
volatile SRRUSTR _SRRU;                                    /* Port U Slew Rate Register; 0x00000296 */
volatile PTVSTR _PTV;                                      /* Port V Data Register; 0x00000298 */
volatile PTIVSTR _PTIV;                                    /* Port V Input Register; 0x00000299 */
volatile DDRVSTR _DDRV;                                    /* Port V Data Direction Register; 0x0000029A */
volatile PERVSTR _PERV;                                    /* Port V Pull Device Enable Register; 0x0000029C */
volatile PPSVSTR _PPSV;                                    /* Port V Polarity Select Register; 0x0000029D */
volatile SRRVSTR _SRRV;                                    /* Port V Slew Rate Register; 0x0000029E */
volatile TIM1_TIOSSTR _TIM1_TIOS;                          /* Timer Input Capture/Output Compare Select; 0x000002A0 */
volatile TIM1_CFORCSTR _TIM1_CFORC;                        /* Timer Compare Force Register; 0x000002A1 */
volatile TIM1_OC7MSTR _TIM1_OC7M;                          /* Output Compare 7 Mask Register; 0x000002A2 */
volatile TIM1_OC7DSTR _TIM1_OC7D;                          /* Output Compare 7 Data Register; 0x000002A3 */
volatile TIM1_TSCR1STR _TIM1_TSCR1;                        /* Timer System Control Register1; 0x000002A6 */
volatile TIM1_TTOVSTR _TIM1_TTOV;                          /* Timer Toggle On Overflow Register; 0x000002A7 */
volatile TIM1_TCTL1STR _TIM1_TCTL1;                        /* Timer Control Register 1; 0x000002A8 */
volatile TIM1_TCTL2STR _TIM1_TCTL2;                        /* Timer Control Register 2; 0x000002A9 */
volatile TIM1_TCTL3STR _TIM1_TCTL3;                        /* Timer Control Register 3; 0x000002AA */
volatile TIM1_TCTL4STR _TIM1_TCTL4;                        /* Timer Control Register 4; 0x000002AB */
volatile TIM1_TIESTR _TIM1_TIE;                            /* Timer Interrupt Enable Register; 0x000002AC */
volatile TIM1_TSCR2STR _TIM1_TSCR2;                        /* Timer System Control Register 2; 0x000002AD */
volatile TIM1_TFLG1STR _TIM1_TFLG1;                        /* Main Timer Interrupt Flag 1; 0x000002AE */
volatile TIM1_TFLG2STR _TIM1_TFLG2;                        /* Main Timer Interrupt Flag 2; 0x000002AF */
volatile TIM1_PACTLSTR _TIM1_PACTL;                        /* 16-Bit Pulse Accumulator A Control Register; 0x000002C0 */
volatile TIM1_PAFLGSTR _TIM1_PAFLG;                        /* Pulse Accumulator A Flag Register; 0x000002C1 */
volatile TIM1_OCPDSTR _TIM1_OCPD;                          /* Output Compare Pin Disconnect Register; 0x000002CC */
volatile TIM1_PTPSRSTR _TIM1_PTPSR;                        /* Precision Timer Prescaler Select Register; 0x000002CE */
volatile CPMUHTCTLSTR _CPMUHTCTL;                          /* High Temperature Control Register; 0x000002F0 */
volatile CPMULVCTLSTR _CPMULVCTL;                          /* Low Voltage Control Register; 0x000002F1 */
volatile CPMUAPICTLSTR _CPMUAPICTL;                        /* Autonomous Periodical Interrupt Control Register; 0x000002F2 */
volatile CPMUAPITRSTR _CPMUAPITR;                          /* Autonomous Periodical Interrupt Trimming Register; 0x000002F3 */
volatile CPMUHTTRSTR _CPMUHTTR;                            /* High Temperature Trimming Register; 0x000002F7 */
volatile CPMUOSCSTR _CPMUOSC;                              /* S12CPMU Oscillator Register; 0x000002FA */
volatile CPMUPROTSTR _CPMUPROT;                            /* S12CPMUV1 Protection Register; 0x000002FB */
/* NVFPROT - macro for reading non volatile register       Non Volatile P-Flash Protection Register; 0x0000FF0C */
/* NVDFPROT - macro for reading non volatile register      Non Volatile D-Flash Protection Register; 0x0000FF0D */
/* NVFOPT - macro for reading non volatile register        Non Volatile Flash Option Register; 0x0000FF0E */
/* NVFSEC - macro for reading non volatile register        Non Volatile Flash Security Register; 0x0000FF0F */


/* * * * *  16-BIT REGISTERS  * * * * * * * * * * * * * * * */
volatile PORTABSTR _PORTAB;                                /* Port AB Data Register; 0x00000000 */
volatile DDRABSTR _DDRAB;                                  /* Port AB Data Direction Register; 0x00000002 */
volatile PARTIDSTR _PARTID;                                /* Part ID Register; 0x0000001A */
volatile DBGTBSTR _DBGTB;                                  /* Debug Trace Buffer Register; 0x00000024 */
volatile TIM0_TCNTSTR _TIM0_TCNT;                          /* Timer Count Register; 0x00000044 */
volatile TIM0_TC0STR _TIM0_TC0;                            /* Timer Input Capture/Output Compare Register 0; 0x00000050 */
volatile TIM0_TC1STR _TIM0_TC1;                            /* Timer Input Capture/Output Compare Register 1; 0x00000052 */
volatile TIM0_TC2STR _TIM0_TC2;                            /* Timer Input Capture/Output Compare Register 2; 0x00000054 */
volatile TIM0_TC3STR _TIM0_TC3;                            /* Timer Input Capture/Output Compare Register 3; 0x00000056 */
volatile TIM0_TC4STR _TIM0_TC4;                            /* Timer Input Capture/Output Compare Register 4; 0x00000058 */
volatile TIM0_TC5STR _TIM0_TC5;                            /* Timer Input Capture/Output Compare Register 5; 0x0000005A */
volatile TIM0_TC6STR _TIM0_TC6;                            /* Timer Input Capture/Output Compare Register 6; 0x0000005C */
volatile TIM0_TC7STR _TIM0_TC7;                            /* Timer Input Capture/Output Compare Register 7; 0x0000005E */
volatile TIM0_PACNTSTR _TIM0_PACNT;                        /* Pulse Accumulators Count Register; 0x00000062 */
volatile ATDCTL01STR _ATDCTL01;                            /* ATD  Control Register 01; 0x00000070 */
volatile ATDCTL23STR _ATDCTL23;                            /* ATD  Control Register 23; 0x00000072 */
volatile ATDCTL45STR _ATDCTL45;                            /* ATD  Control Register 45; 0x00000074 */
volatile ATDCMPESTR _ATDCMPE;                              /* ATD  Compare Enable Register; 0x00000078 */
volatile ATDSTAT2STR _ATDSTAT2;                            /* ATD  Status Register 2; 0x0000007A */
volatile ATDDIENSTR _ATDDIEN;                              /* ATD  Input Enable Register; 0x0000007C */
volatile ATDCMPHTSTR _ATDCMPHT;                            /* ATD  Compare Higher Than Register; 0x0000007E */
volatile ATDDR0STR _ATDDR0;                                /* ATD  Conversion Result Register 0; 0x00000080 */
volatile ATDDR1STR _ATDDR1;                                /* ATD  Conversion Result Register 1; 0x00000082 */
volatile ATDDR2STR _ATDDR2;                                /* ATD  Conversion Result Register 2; 0x00000084 */
volatile ATDDR3STR _ATDDR3;                                /* ATD  Conversion Result Register 3; 0x00000086 */
volatile ATDDR4STR _ATDDR4;                                /* ATD  Conversion Result Register 4; 0x00000088 */
volatile ATDDR5STR _ATDDR5;                                /* ATD  Conversion Result Register 5; 0x0000008A */
volatile ATDDR6STR _ATDDR6;                                /* ATD  Conversion Result Register 6; 0x0000008C */
volatile ATDDR7STR _ATDDR7;                                /* ATD  Conversion Result Register 7; 0x0000008E */
volatile PWMCNT01STR _PWMCNT01;                            /* PWM Channel Counter 01 Register; 0x000000AC */
volatile PWMCNT23STR _PWMCNT23;                            /* PWM Channel Counter 23 Register; 0x000000AE */
volatile PWMCNT45STR _PWMCNT45;                            /* PWM Channel Counter 45 Register; 0x000000B0 */
volatile PWMCNT67STR _PWMCNT67;                            /* PWM Channel Counter 67 Register; 0x000000B2 */
volatile PWMPER01STR _PWMPER01;                            /* PWM Channel Period 01 Register; 0x000000B4 */
volatile PWMPER23STR _PWMPER23;                            /* PWM Channel Period 23 Register; 0x000000B6 */
volatile PWMPER45STR _PWMPER45;                            /* PWM Channel Period 45 Register; 0x000000B8 */
volatile PWMPER67STR _PWMPER67;                            /* PWM Channel Period 67 Register; 0x000000BA */
volatile PWMDTY01STR _PWMDTY01;                            /* PWM Channel Duty 01 Register; 0x000000BC */
volatile PWMDTY23STR _PWMDTY23;                            /* PWM Channel Duty 23 Register; 0x000000BE */
volatile PWMDTY45STR _PWMDTY45;                            /* PWM Channel Duty 45 Register; 0x000000C0 */
volatile PWMDTY67STR _PWMDTY67;                            /* PWM Channel Duty 67 Register; 0x000000C2 */
volatile SCIBDSTR _SCIBD;                                  /* SCI  Baud Rate Register; 0x000000C8 */
volatile SPIDRSTR _SPIDR;                                  /* SPI  Data Register; 0x000000DC */
volatile FCCOBSTR _FCCOB;                                  /* Flash Common Command Object Register; 0x0000010A */
volatile CANRXTSRSTR _CANRXTSR;                            /* MSCAN Receive Time Stamp Register; 0x0000016E */
volatile CANTXTSRSTR _CANTXTSR;                            /* MSCAN Transmit Time Stamp Register; 0x0000017E */
volatile MCPERSTR _MCPER;                                  /* Motor Controller Period Register; 0x000001C2 */
volatile MCDC0STR _MCDC0;                                  /* Motor Controller Period Register 0; 0x000001E0 */
volatile MCDC1STR _MCDC1;                                  /* Motor Controller Period Register 1; 0x000001E2 */
volatile MCDC2STR _MCDC2;                                  /* Motor Controller Period Register 2; 0x000001E4 */
volatile MCDC3STR _MCDC3;                                  /* Motor Controller Period Register 3; 0x000001E6 */
volatile MCDC4STR _MCDC4;                                  /* Motor Controller Period Register 4; 0x000001E8 */
volatile MCDC5STR _MCDC5;                                  /* Motor Controller Period Register 5; 0x000001EA */
volatile MCDC6STR _MCDC6;                                  /* Motor Controller Period Register 6; 0x000001EC */
volatile MCDC7STR _MCDC7;                                  /* Motor Controller Period Register 7; 0x000001EE */
volatile PTPRRSTR _PTPRR;                                  /* Port P Routing Register; 0x0000025E */
volatile TIM1_TCNTSTR _TIM1_TCNT;                          /* Timer Count Register; 0x000002A4 */
volatile TIM1_TC0STR _TIM1_TC0;                            /* Timer Input Capture/Output Compare Register 0; 0x000002B0 */
volatile TIM1_TC1STR _TIM1_TC1;                            /* Timer Input Capture/Output Compare Register 1; 0x000002B2 */
volatile TIM1_TC2STR _TIM1_TC2;                            /* Timer Input Capture/Output Compare Register 2; 0x000002B4 */
volatile TIM1_TC3STR _TIM1_TC3;                            /* Timer Input Capture/Output Compare Register 3; 0x000002B6 */
volatile TIM1_TC4STR _TIM1_TC4;                            /* Timer Input Capture/Output Compare Register 4; 0x000002B8 */
volatile TIM1_TC5STR _TIM1_TC5;                            /* Timer Input Capture/Output Compare Register 5; 0x000002BA */
volatile TIM1_TC6STR _TIM1_TC6;                            /* Timer Input Capture/Output Compare Register 6; 0x000002BC */
volatile TIM1_TC7STR _TIM1_TC7;                            /* Timer Input Capture/Output Compare Register 7; 0x000002BE */
volatile TIM1_PACNTSTR _TIM1_PACNT;                        /* Pulse Accumulators Count Register; 0x000002C2 */
volatile CPMUAPIRSTR _CPMUAPIR;                            /* Autonomous Periodical Interrupt Rate Register; 0x000002F4 */
volatile CPMUIRCTRIMSTR _CPMUIRCTRIM;                      /* S12CPMU IRC1M Trim Registers; 0x000002F8 */
/* BAKEY0 - macro for reading non volatile register        Backdoor Comparison Key 0; 0x0000FF00 */
/* BAKEY1 - macro for reading non volatile register        Backdoor Comparison Key 1; 0x0000FF02 */
/* BAKEY2 - macro for reading non volatile register        Backdoor Comparison Key 2; 0x0000FF04 */
/* BAKEY3 - macro for reading non volatile register        Backdoor Comparison Key 3; 0x0000FF06 */

/*lint -restore */

/* EOF */
