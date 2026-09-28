#include<lpc21xx.h>
#include "can1hdr.h"
#define TRIG (1<<8) //P0.8
#define ECHO (1<<9)
void ultrasonic_init()
{
 IODIR0|=TRIG;
IODIR0 &= ~(ECHO);
T0TCR = 0x02; 
 T0PR = 59; 
}
void send_pulse()
{
 T0TC=0;
 T0PR = 59; 
 IOSET0=TRIG; //trig=1
 delay_us(10); //10us delay
 IOCLR0=TRIG;   //trig=0
IODIR0 &= ~(ECHO) ;
}
u32 get_range()
{
 u32 time;
 float d;
 send_pulse();
 while(!((IO0PIN & ECHO)));//waiting for echo to high
 T0TCR=1;
 while((IO0PIN & ECHO));//waiting for ech to go low 
 T0TCR=0;
 time=T0TC; 
 d=(0.0343 * time)/2;
 return d;
 }
