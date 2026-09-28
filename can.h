/*header.h*/

typedef unsigned char u8;

typedef signed char s8;

typedef unsigned int u32;

typedef signed int s32;

typedef unsigned short int u16;


extern void config_eint0(void);

extern void config_vic_for_eint0(void);

extern void config_eint1(void);

extern void config_vic_for_eint1(void);




extern void delay_sec(unsigned int sec);

extern void delay_ms(unsigned int ms);


extern unsigned char uart0_rx(void);

extern void uart0_tx(unsigned char data);

extern void uart0_init(unsigned int baud);

extern void uart0_rx_string(char *ptr,int max_bytes);

extern void uart0_tx_string(char *ptr);

extern unsigned char uart0_rx(void);

extern void uart0_tx(unsigned char data);

extern void uart0_init(unsigned int baud);

void uart0_tx_integer(int num);

void uart0_tx_float(float num);

extern void lcd_init(void);

extern void lcd_data(unsigned char data);

extern void lcd_cmd(unsigned char cmd);

extern void lcd_integer(int num);

extern void lcd_string(char *ptr);


u32 adc_read(u8 ch_num);

void adc_init(void);




extern void config_vic_for_uart0(void);

extern void en_uart0_intr(void);

extern void config_uart0_intr(void);





extern void spi0_init(void);

extern u8 spi0(u8 data);

extern u32 mcp3204_adc_read(u8 ch_num);




extern void i2c_init(void);

extern void i2c_send(u8 sa, u8 mr, u8 data);

extern u8 i2c_receive(u8 sa, u8 mr);


extern void timer1_init(void);

extern void config_vic_for_timer1(void);


typedef struct CAN1_MSG{

	u32 id;

	u32 byteA;

	u32 byteB;

	u8 dlc;

	u8 rtr;

	u8 ff;

}CAN1;


extern void can1_tx(CAN1 v);

extern void can1_init(void);

extern void can1_rx(CAN1 *ptr);

extern void config_vic_for_can1(void);
