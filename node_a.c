#include<lpc21xx.h>
#include "can1hdr.h"
#define REV_SW ((IOPIN0>>14)&1)
#define LED1 (1<<18)
#define LED (1<<17)
#define BUZZER (1<<19)

CAN1 r1,r2,v1,v2;
u8 flag;

main()
{
    u32 RG=0;

	IODIR0|=REV_SW|LED|BUZZER|LED1;
	IOSET0=LED|LED1;
	can1_init();
	uart0_init(9600);
	config_vic_for_can1();		      
	en_can1_interupt();
	v1.id=0x123;
	v1.dlc=2;
	v1.rtr=1;
	v2.id=0x02;
	v2.dlc=2;
	v2.rtr=0;
	uart0_tx_string("NODE A is configured\r\n");

while(1)
{
    if(REV_SW==0)
    {
        while(REV_SW==0);
        RG^=1;

        if(RG)
        {
            IOCLR0=LED;
            uart0_tx_string("Reverse gear is enabled\r\n");
            can1_tx(v1);
            
        }
        else
        {
            IOSET0=LED;
     	    uart0_tx_string("Reverse gear is disabled\r\n");
            can1_tx(v2);
            
        }
    }

 
    if(flag==1)
    {
        flag=0;

        r2.id=r1.id;
        r2.dlc=r1.dlc;

        if(r2.rtr==0)
        {
            r2.byteA=r1.byteA;
			uart0_tx_string("distance:\r\n");
            uart0_integer(r2.byteA);
            uart0_tx_string("cm\r\n");
        }

        if(r2.byteA>=300 && r2.byteA<=450)
        {
            IOSET0=BUZZER;
            IOCLR0=LED1;
         	delay_ms(50);
         	IOSET0=LED1;
         	IOCLR0=BUZZER;
            delay_ms(700);
        }										            
        else if(r2.byteA>=200 && r2.byteA<=299)
        {
		    IOSET0=BUZZER;
            IOCLR0=LED1;
			delay_ms(50);
			IOSET0=LED1;
		    IOCLR0=BUZZER;
            delay_ms(400);
        }
        else if(r2.byteA>=100 && r2.byteA<=199)
        {
            IOSET0=BUZZER;
            IOCLR0=LED1;
			delay_ms(50);
		    IOSET0=LED1;
		    IOCLR0=BUZZER;
            delay_ms(200);
        }
				
        else if(r2.byteA<=100 )
        {
  		    IOCLR0=LED1;
            IOSET0=BUZZER;
        }
    }
}
}
