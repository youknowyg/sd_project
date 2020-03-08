#ifndef _MAIN_H
#define _MAIN_H

#include <MC9S12HY64.h>     /* derivative information */

#define 	Mc_Tacho			0
#define 	Mc_Press1	        1
#define 	Mc_Speed			2
#define 	Mc_Press2			3
#define 	Mc_Fuel		        4
#define 	Mc_MAX			    5

typedef union  
{
		unsigned char	pp;
	  	struct {
				unsigned char	p0	:1;
				unsigned char	p1	:1;
				unsigned char	p2	:1;
				unsigned char	p3	:1;
				unsigned char	p4	:1;
				unsigned char	p5	:1;
				unsigned char	p6	:1;
				unsigned char	p7	:1;
		}bit;
	
} packet_8bit;      

typedef  union  {

		unsigned int	 pp;
	  	struct {
				
						unsigned int	p8	:1;//H8
						unsigned int	p9	:1;
						unsigned int	p10	:1;
						unsigned int	p11	:1;
						unsigned int	p12	:1;
						unsigned int	p13	:1; //
						unsigned int	p14	:1;
						unsigned int	p15	:1;//
					
						unsigned int	p0	:1; //L0
						unsigned int	p1	:1;
						unsigned int	p2	:1;
						unsigned int	p3	:1;
						unsigned int	p4	:1;
						unsigned int	p5	:1;
						unsigned int	p6    :1;
						unsigned int	p7    :1; //L7
					
				
		}bit;
	
}packet_16bit;


extern long	sms_pt1,  sms_pt2, sms_clc1, sms_clc2;
extern int	    sms_inp,  sms_new, sms_old;

extern long	smr_pt1,  smr_pt2, smr_clc1, smr_clc2;
extern int	    smr_inp,  smr_new, smr_old,smr_new_bak,B_POINT;

typedef struct
{
	long pt1;
	long pt2;
	long clc1;  
	long clc2;
	int inp;	
	int m_new;  
	int new_bak; 
	int old;    
	int acc;
	int velo;

	unsigned char  dn;
	char         vmax;
	unsigned char DispEn;
	
}SmControlStu;




  		      
#endif


