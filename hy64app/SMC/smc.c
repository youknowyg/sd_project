
#include "smc.h"
#include "main.h"
extern SmControlStu	Smeter[Mc_MAX];
void init_smc_parameter(void)
{
		unsigned char cn;
		cn=Mc_Tacho;
        Smeter[cn].inp =0;
    	Smeter[cn].pt1 =0; Smeter[cn].pt2 = 0;
    	Smeter[cn].m_new =0; Smeter[cn].old = 0;
    	Smeter[cn].dn   = 8;
    	Smeter[cn].vmax = 2;//10
    	Smeter[cn].acc=1; Smeter[cn].velo=0;

		cn=Mc_Speed;
        Smeter[cn].inp =0;
    	Smeter[cn].pt1 =0; Smeter[cn].pt2 = 0;
    	Smeter[cn].m_new =0; Smeter[cn].old = 0;
    	Smeter[cn].dn   = 8;
    	Smeter[cn].vmax = 6;//10
    	Smeter[cn].acc=1; Smeter[cn].velo=0;
		
	   
		cn=Mc_Press1;
        Smeter[cn].inp =0;
    	Smeter[cn].pt1 =0; Smeter[cn].pt2 = 0;
    	Smeter[cn].m_new =0; Smeter[cn].old = 0;
    	Smeter[cn].dn   = 8;
    	Smeter[cn].vmax = 7;//10
    	Smeter[cn].acc=1; Smeter[cn].velo=0;

		cn=Mc_Press2;
        Smeter[cn].inp =0;
    	Smeter[cn].pt1 =0; Smeter[cn].pt2 = 0;
    	Smeter[cn].m_new =0; Smeter[cn].old = 0;
    	Smeter[cn].dn   = 7;
    	Smeter[cn].vmax = 1;//10
    	Smeter[cn].acc=1; Smeter[cn].velo=0;

		cn=Mc_Fuel;
        Smeter[cn].inp =0;
    	Smeter[cn].pt1 =0; Smeter[cn].pt2 = 0;
    	Smeter[cn].m_new =0; Smeter[cn].old = 0;
    	Smeter[cn].dn   = 7;
    	Smeter[cn].vmax = 1;//10
    	Smeter[cn].acc=1; Smeter[cn].velo=0;
		

       
}  

void smc_ido(unsigned char cn)
{
  	Smeter[cn].old=Smeter[cn].m_new;
  	Smeter[cn].clc1=Smeter[cn].inp;
  	Smeter[cn].clc1=(Smeter[cn].clc1<<(16-Smeter[cn].dn));   

  	Smeter[cn].clc2=(Smeter[cn].pt1-(Smeter[cn].pt1>>Smeter[cn].dn)); 
  	Smeter[cn].pt1=Smeter[cn].clc2+Smeter[cn].clc1;

  	Smeter[cn].clc2=(Smeter[cn].pt2-(Smeter[cn].pt2>>Smeter[cn].dn));
  	Smeter[cn].pt2=Smeter[cn].clc2+(Smeter[cn].pt1>>Smeter[cn].dn);
  	Smeter[cn].m_new=(int)(Smeter[cn].pt2>>16);
}


void smc_avclip(unsigned char cn)
{
	Smeter[cn].clc1=(Smeter[cn].m_new-Smeter[cn].old);  
	if (Smeter[cn].clc1 < -Smeter[cn].vmax  ) //当差值大于设置上限的时候直接减最大值
	{
			Smeter[cn].m_new=Smeter[cn].old-Smeter[cn].vmax;
			Smeter[cn].clc1=-Smeter[cn].vmax; //计算剩余差值
			*((int *)&Smeter[cn].pt2+1)=Smeter[cn].m_new;
	}
	if ( Smeter[cn].clc1 >  Smeter[cn].vmax ) //与上面反向 这里加上最大值
	{
			Smeter[cn].m_new=Smeter[cn].old+Smeter[cn].vmax;
			Smeter[cn].clc1=Smeter[cn].vmax; //计算剩余差值
			*((int *)&Smeter[cn].pt2+1)=Smeter[cn].m_new;
	}

	Smeter[cn].acc=(Smeter[cn].clc1-Smeter[cn].velo);
	if ( Smeter[cn].acc < -Smeter[cn].vmax )
	{

		Smeter[cn].clc1=Smeter[cn].velo-Smeter[cn].vmax;
		Smeter[cn].m_new=Smeter[cn].old+Smeter[cn].clc1;
		*((int *)&Smeter[cn].pt2+1)=Smeter[cn].m_new;
	}
	if ( Smeter[cn].acc > Smeter[cn].vmax )
	{
		Smeter[cn].clc1=Smeter[cn].velo+Smeter[cn].vmax;
		Smeter[cn].m_new=Smeter[cn].old+Smeter[cn].clc1;
		*((int *)&Smeter[cn].pt2+1)=Smeter[cn].m_new;
	}
	Smeter[cn].acc =Smeter[cn].clc1-Smeter[cn].velo;
	Smeter[cn].velo=Smeter[cn].clc1;

}




static void Smc_Calculate(unsigned char cn)
{
	if(Smeter[cn].m_new!=Smeter[cn].inp)
	{
		smc_ido(cn);
		smc_avclip(cn);
		Smeter[cn].DispEn=1;
	}
}


void SM_Calculate(void)
{
	Smc_Calculate(Mc_Tacho);
	Smc_Calculate(Mc_Speed);
	
	
	Smc_Calculate(Mc_Press1);
	
	Smc_Calculate(Mc_Press2);
	
	//Smc_Calculate(Mc_Fuel);

}






