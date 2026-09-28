#include<lpc21xx.h>
#define THRE ((U0LSR>>5)&1)
#define RDR (U0LSR&1)

void uart0_init(unsigned int baud)
{
	int pclk,result=0;
	int a[]={15,60,30,0,0};
	pclk=a[VPBDIV]*1000000;
	result=pclk/(16*baud);
	PINSEL0=0x5;
	U0LCR=0x83;
	U0DLL=result&0xff;
	U0DLM=(result>>8)&0xff;
	U0LCR=0x03;
}

void uart0_tx(unsigned char data)
{
	U0THR=data;
	while(THRE==0);
}

unsigned char uart0_rx()
{
	while(RDR==0);
	return U0RBR;
}

void uart0_tx_string(char *p)
{
	while(*p){
	uart0_tx(*p);
	p++;
	}
}

void uart0_integer(int num)
{
	int a[10],i=0;
	if(num==0)
	uart0_tx('0');
	if(num<0){
	num=-num;
	uart0_tx('-');
	}
	while(num>0)
	{
		a[i]=num%10+48;
		num=num/10;
		i++;
	}
	for(i=i-1;i>=0;i--)
		uart0_tx(a[i]);
}

void uart0_rx_string(char *p,int len)
{
	int i=0;
	for(i=0;i<len;i++)
	{
		while(RDR==0);
		p[i]=U0RBR;
		uart0_tx(p[i]);
		if(p[i]=='\r')
			break;
	}
	p[i]='\0';
}
