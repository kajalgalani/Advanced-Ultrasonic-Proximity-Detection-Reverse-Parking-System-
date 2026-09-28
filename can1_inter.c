#include<lpc21xx.h>
#include "can1hdr.h"
extern u8 flag;
extern CAN1 r1;

void can1_rx_handler(void) __irq{
	r1.id=C1RID;
	r1.dlc=(C1RFS>>16)&0XF;
	r1.rtr=(C1RFS>>30)&1;
	r1.ff=(C1RFS>>31)&1;
	if(r1.rtr==0)
	{
		r1.byteA=C1RDA;
		r1.byteB=C1RDB;
	}
	C1CMR=(1<<2);
	flag=1;
	VICVectAddr=0;
}
void en_can1_interupt(void){
	C1IER=1;
}

void config_vic_for_can1(void)
{
	VICIntSelect=0;
	VICVectCntl3=26|(1<<5);
	VICVectAddr3=(u32) can1_rx_handler;
	VICIntEnable=(1<<26);
}
