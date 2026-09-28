#include <lpc21xx.h>		              
#include "can1hdr.h"

CAN1 r1,v1;
u8 flag;

main()
{
u32 dist,value;

can1_init();
config_vic_for_can1();
en_can1_interupt();
ultrasonic_init();
uart0_init(9600);

while(1)
{
    if(flag==1)
    {   
        flag=0;
        uart0_tx_string("remote frame is recived\r\n");

        if(r1.rtr==1)
        {
            v1.id=r1.id; 
            v1.dlc=r1.dlc;
            value = 1;
        }
        else
           value=0;
    }   

    if(value==1)
    {   
        dist=get_range();
        delay_sec(1);
		v1.rtr = 0;
		 
        v1.byteA=dist;
       
        can1_tx(v1);
    }   
}
}
