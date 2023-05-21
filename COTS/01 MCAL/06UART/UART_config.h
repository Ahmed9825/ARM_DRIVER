

#ifndef          UART_CONFIG_H
#define          UART_CONFIG_H
/* Choose the boud rate  with 

             FCPU  = 8 MHz:   

				1-BOUD8MHz_9600
				2-BOUD8MHz_115200         
			 FCPU  = 72 MHz:
			    1-BOUD72MHz_9600
			    2-BOUD72MHz_115200 

				*/

#define  BOUD_RATE     			BOUD8MHz_9600 
   
/* Choose WORD LENGTH 

             1- DATA_8BIT
			 2- DATA_9BIT

				*/
				
#define     DATA_LENGTH      DATA_8BIT

/* Choose PARITY 

             1- PARITY_EN
			 2- PARITY_DIS

				*/
				
#define     PARITY      PARITY_DIS
				
/* Choose PARITY_TYPE        if enable the PARITY 

             1- EVEN
			 2- ODD

				*/	
				
#define   PARITY_TYPE          EVEN

/* Choose STOP_BITNUM       

             1- STOP_1BIT
			 2- STOP_2BIT

				*/	
				
#define     STOP_BITNUM        STOP_1BIT
#endif
