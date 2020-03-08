#ifndef _TEMPERATURE_FUEL_CAL_H_
#define _TEMPERATURE_FUEL_CAL_H_


extern unsigned char Fuel_ge;
extern unsigned char sw_ge;

extern void Calculate_Temperature(unsigned int EngCoolTemp);
extern void Calculate_Fuel(unsigned int temp_adc);


#endif

