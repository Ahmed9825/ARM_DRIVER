#ifndef UART_PRIVATE_H
#define UART_PRIVATE_H


typedef  struct   {
	u32 SR  	;
	u32 DR  	;
	u32 BRR 	;
	u32 CR1 	;
	u32 CR2 	;
	u32 CR3 	;
	u32 GTPR 	;

    }UART1_TYPE  ;

#define      UART1            ((volatile UART1_TYPE *)0x40013800)

#define         BOUD8MHz_9600            1
#define         BOUD8MHz_115200			 2        


#define         BOUD72MHz_9600         1
#define         BOUD72MHz_115200	   2 

#define         DATA_8BIT              1
#define         DATA_9BIT			   2 

#define         PARITY_EN              1
#define         PARITY_DIS             2

#define        EVEN                 1
#define        ODD                  2 

#define        STOP_1BIT        1
#define        STOP_2BIT        2 

//CR1 
#define       CR1_UE              13
#define       CR1_M               12
#define       CR1_PCE             10
#define       CR1_PS              9
#define       CR1_TE              3
#define       CR1_RE              2


//CR2 

#define          CR2_STOP0               12
#define          CR2_STOP1               13

//SR 
#define          SR_RXNE                5
#define          SR_TXE                 7

#endif /* UART_H_ */