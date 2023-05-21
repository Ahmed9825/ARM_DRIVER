#include	"Std_Types.h"
#include	"Bit_Math.h"
#include	"RCC_interface.h"
#include    "DIO_interface.h"
#include    "delay.h"
#include    "UART_interface.h"
#include    "UART_config.h"
#include    "UART_private.h"





//initialize function
void UART_init() {
	

	//CHOOSE SPEED 
    #if 	BOUD_RATE ==  BOUD8MHz_9600
	 
	   UART1 -> BRR = 0x341 ;
    
    #elif 	BOUD_RATE ==  BOUD8MHz_115200
	  
	      UART1 -> BRR = 0x45
	#elif 	BOUD_RATE ==  BOUD72MHz_9600
		  UART1 -> BRR = 0x1D4C
          
    #elif 	BOUD_RATE ==  BOUD72MHz_115200
	      UART1 -> BRR = 0x271
	#else  
		#error "wrong BOUD rate choose "
	
	#endif
   
   //SET DATA SIZE 
   #if  	DATA_LENGTH == DATA_8BIT
     CLR_BIT(UART1 -> CR1 , CR1_M) ; 
   #elif  	DATA_LENGTH == DATA_9BIT
     SET_BIT(UART1 -> CR1 , CR1_M) ;
   #else  
	   #error  "wrong choose for DATA LENGTH "
   #endif
  
  //CHOOSE PARITY 
   #if  	PARITY == PARITY_EN
    SET_BIT(UART1 -> CR1 , CR1_PCE) ;
     #if  PARITY_TYPE ==  EVEN 
	    CLR_BIT (UART1 -> CR1 , CR1_PS) ;
	 #elif  PARITY_TYPE ==  ODD 
        SET_BIT(UART1 -> CR1 , CR1_PS) ;
     #endif	 
   #elif 	PARITY == PARITY_DIS
   CLR_BIT (UART1 -> CR1 , CR1_PCE) ;
   #else 
	   #error "Wrong choose PARITY Control "
   #endif
   
   //CHOOSE NOMBER OF STOP BITS  
   #if   STOP_BITNUM  ==    STOP_1BIT
       CLR_BIT (UART1 -> CR2 , CR2_STOP0) ;
	   CLR_BIT (UART1 -> CR2 , CR2_STOP1) ;
	   
   #elif    STOP_BITNUM  ==    STOP_2BIT
       CLR_BIT (UART1 -> CR2 , CR2_STOP0) ;
	   SET_BIT (UART1 -> CR2 , CR2_STOP1) ;
   #endif

	   SET_BIT(UART1 -> CR1 , CR1_UE) ;
}
//enable transmitter
void UART_enableTX(void) {
	SET_BIT(UART1 -> CR1 , CR1_TE) ;
}

void UART_disableTX(void) {
	CLR_BIT(UART1 -> CR1 , CR1_TE) ;
}
//enable receiver
void UART_enableRX(void) {
	SET_BIT(UART1 -> CR1 , CR1_RE) ;
}

void UART_disableRX(void) {
	CLR_BIT(UART1 -> CR1 , CR1_RE) ;
}
//transmit data
void UART_TXdata(u8 data){
	 while(!GET_BIT(UART1 -> SR ,SR_TXE)) ;
	UART1 -> DR = data ;
	while(!GET_BIT(UART1 -> SR ,6)) ;
}
//receive data
void UART_RXdata (u8 *data) {
	while(!GET_BIT(UART1 -> SR, SR_RXNE));
	*data = UART1 -> DR;
	
}


void UART1_voidSendString(u8 *  str)
{     
	while (*str != '\0'){
		UART_TXdata(*str) ;
		str ++ ; 
	}
}

u8 * const UART1_StrReceiveString()
{     
    static u8  * LOCAL_STR   ;
    while (*LOCAL_STR != '\0'){
		UART_RXdata(*LOCAL_STR) ;
		LOCAL_STR ++ ; 
	}
	return LOCAL_STR ;
}
