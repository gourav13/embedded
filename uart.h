/*
 * uart.h.c
 *
 * Created: 20-06-2016 23:20:14
 * Author : hp
 */ 

#include <avr/io.h>
#include <util/delay.h>

void tx(unsigned char a)
{
	UDR=a;
	while((UCSRA&(1<<UDRE))==0x00);
}

unsigned char rec()
{
	while((UCSRA&(1<<RXC))==0x00);
	return UDR;
}


void init_uart()
{
	
	UBRRH=0;
	UBRRL=51;
	UCSRB|=(1<<RXEN)|(1<<TXEN);
	UCSRC|=(1<<URSEL)|(1<<UCSZ1)|(1<<UCSZ0);
}

