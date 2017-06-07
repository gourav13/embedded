#include<avr/io.h>
#include<util/delay.h>
void lcd_cmd(unsigned char cd)
{
char a,b;
DDRB=0xff;
a=cd & 0xf0;
PORTB=a | 0x04;
_delay_ms(100);
PORTB=a | 0x00;
b=cd<<4;
PORTB=b | 0x04;
_delay_ms(100);
PORTB=b | 0x00;
}
void lcd_display(unsigned char disp)
{
char a,b;
DDRB=0xff;
a=disp & 0xf0;

PORTB=a | 0x05;
_delay_ms(50);
PORTB=a | 0x01;
b=disp<<4;
PORTB=b | 0x05;
_delay_ms(50);
PORTB=b | 0x01;
}
void main()
{
char c1[]="12345";
char c2[]="23451";
char g[]="access granted";
char h[]="not granted";
char f[]="ENTER ur card";
char card[5];
int i,j,p,q,r,v,count1=0,count2=0;
DDRD=0x00;
DDRB=0xff;
UBRRL=0X33;
UCSRA=0X20;
UCSRB=0X10;
UCSRC=0X86;
lcd_cmd(0x02);
lcd_cmd(0x28);
lcd_cmd(0x80);
lcd_cmd(0x0e);
for(v=0;f[v]!='\0';v++)
{
lcd_display(f[v]);
}
lcd_cmd(0xc0);
while(1)
{
for(j=0;j<5;j++)
{
while (( UCSRA & 0x80)==0x00);
card[j]=UDR;
UCSRA=0;
}
for(i=0;i<5;i++)
{
if(card[i]==c1[i])
{
count1++;
}

if(card[i]==c2[i])
{
count2++;
}
}
if(count1==5)
{
lcd_cmd(0x01);
lcd_cmd(0x80);
for(p=0;g[p]!='\0';p++)
{
lcd_display(g[p]);
}}
else 
{
lcd_cmd(0x01);
for(q=0;h[q]!='\0';q++)
{
lcd_display(h[q]);
}
}
}}
