/*
 * GccApplication13.c
 *
 * Created: 14-06-2016 11:23:15
 * Author : hp
 */ 

#include <avr/io.h>

#define lcd_data PORTB
#define control PORTC
#define rs PC0
#define rw PC1
#define e PC2


void lcdcmd(char a)
{
	lcd_data=a;
	control=(0<<rs)|(0<<rw)|(1<<e);
	_delay_ms(1);
	control=(0<<rs)|(0<<rw)|(0<<e);
	_delay_ms(10);
}

void lcddata(char d)
{
	lcd_data=d;
	control=(1<<rs)|(0<<rw)|(1<<e);
	_delay_ms(1);
	control=(1<<rs)|(0<<rw)|(0<<e);
	_delay_ms(10);
}

void init()
{
	
	lcdcmd(0x38);
	_delay_ms(1);
	lcdcmd(0x01);
	_delay_ms(1);
	lcdcmd(0x0e);
	_delay_ms(1);
	lcdcmd(0x82);
	_delay_ms(1);
	
}


void str1(char *p)
{
	while(*p!='\0')
	{
	lcddata(*p);
	_delay_ms(10);
	p++;
  }
}

void cus()
{
	
	lcdcmd(64);
	lcddata(0x1f);
	lcdcmd(0x80);
	lcddata(0);
}