/*
 * lcdcfile.c
 *
 * Created: 14-06-2016 11:17:46
 * Author : hp
 */ 
#include <avr/io.h>
#include <util/delay.h>
#include"lcd.h"

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
