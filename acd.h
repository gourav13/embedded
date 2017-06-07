/*
 * acdheaderfile.c
 *
 * Created: 17-06-2016 15:24:50
 * Author : hp
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include <string.h>
void adcinit()
{
	ADMUX|=(1<<REFS0);
	ADCSRA|=(1<<ADEN);
	ADCSRA|=(1<<ADSC);
	
}



int adcread()
{
	ADCSRA|=(1<<ADSC);
	while(ADCSRA&(1<<ADIF)==0);
	return ADC;
	
}
