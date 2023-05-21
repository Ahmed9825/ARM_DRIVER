#include	"Std_Types.h"
#include	"Bit_Math.h"
#include	"RCC_interface.h"
#include    "DIO_interface.h"
#include    "SPI_interface.h"
#include    "SPI_private.h"
#include    "SPI_config.h"

void  SPI_init (){
	
	//select direction  
	#if      DIRECTIONAL_DATA  == HALF_DUPLEX
	SET_BIT(SPI1 -> CR1 , CR1_BIDIMODE)  ;
	    #if  DIRECTION_MODE == RECEIVE_ONLY
	     CLR_BIT(SPI1 -> CR1 , CR1_BIDIOE)  ;
	    #elif    DIRECTION_MODE == TRANSMIT_ONLY
		SET_BIT(SPI1 -> CR1 , CR1_BIDIOE)   ; 
		#else   
			#error "worng choose direction mode "
		#endif 
	#elif   DIRECTIONAL_DATA  == FULL_DUPLEX
	CLR_BIT(SPI1 -> CR1 , CR1_BIDIMODE)  ;
	#if   DATA_DIR	== TRANS_RECEIVER
	  CLR_BIT(SPI1 -> CR1 , CR1_RXONLY)   ;
	  #elif   DATA_DIR	== RECEIVER
	  SET_BIT(SPI1 -> CR1 , CR1_RXONLY)   ;
	  #else 
		  #error "wrong choose direction"
	#endif
	#else 
		#error  "worng choose for  direction of data "
	#endif
	
	//CRC 
	#if  CRC_EN  == CRC_OFF 
     CLR_BIT(SPI1 -> CR1 , CR1_CRCEN) ;
	 #elif  CRC_EN  == CRC_ON 
     SET_BIT(SPI1 -> CR1 , CR1_CRCEN) ;
	
	#else   
		#error   "WRONG choose CRC MODE"
	
	#endif
	
	//data format  
	#if  FRAME_FORMAT == DATA_8BIT
	 CLR_BIT(SPI1 -> CR1 , CR1_DFF) ;
	#elif  FRAME_FORMAT == DATA_8BIT
	 SET_BIT(SPI1 -> CR1 , CR1_DFF) ;
	 
	#else 
		#error  "wrong data frame format choose"
	#endif 
	
	//soft ware   slave   management  
	#if  SLAVE_MANAG_EN  == DISABLE  
	 CLR_BIT(SPI1 -> CR1 , CR1_SSM) ;
	#elif  SLAVE_MANAG_EN  ==  ENABLE  
	 SET_BIT(SPI1 -> CR1 , CR1_SSM) ;
	 
	#else 
		#error  "wrong  choose slave management "
	#endif
	
	//choose shift      
    #if SHIFT_TYPE == MSB
	  CLR_BIT(SPI1 -> CR1 , CR1_LSBFIRST) ;
	#elif  SHIFT_TYPE == LSB  
	 SET_BIT(SPI1 -> CR1 , CR1_LSBFIRST) ;
	 #else    
		 #error  "wrong choose SHIFT TYPE"
	 #endif 
	 //Baud rate control
	 #if   BOUD_RATE_CON == F_OVER2
	 CLR_BIT(SPI1 -> CR1 , CR1_BR0) ;
	 CLR_BIT(SPI1 -> CR1 , CR1_BR1) ;
	 CLR_BIT(SPI1 -> CR1 , CR1_BR2) ;
	 #elif BOUD_RATE_CON == F_OVER4
	 SET_BIT(SPI1 -> CR1 , CR1_BR0) ;
	 CLR_BIT(SPI1 -> CR1 , CR1_BR1) ;
	 CLR_BIT(SPI1 -> CR1 , CR1_BR2) ;
	 #elif BOUD_RATE_CON == F_OVER8
	 CLR_BIT(SPI1 -> CR1 , CR1_BR0) ;
	 SET_BIT(SPI1 -> CR1 , CR1_BR1) ;
	 CLR_BIT(SPI1 -> CR1 , CR1_BR2) ;
	 #elif BOUD_RATE_CON == F_OVER16
	 SET_BIT(SPI1 -> CR1 , CR1_BR0) ;
	 SET_BIT(SPI1 -> CR1 , CR1_BR1) ;
	 CLR_BIT(SPI1 -> CR1 , CR1_BR2) ;
	 #elif BOUD_RATE_CON == F_OVER32
	 CLR_BIT(SPI1 -> CR1 , CR1_BR0) ;
	 CLR_BIT(SPI1 -> CR1 , CR1_BR1) ;
	 SET_BIT(SPI1 -> CR1 , CR1_BR2) ;
	 #elif BOUD_RATE_CON == F_OVER64
	 SET_BIT(SPI1 -> CR1 , CR1_BR0) ;
	 CLR_BIT(SPI1 -> CR1 , CR1_BR1) ;
	 SET_BIT(SPI1 -> CR1 , CR1_BR2) ;
	 #elif BOUD_RATE_CON == F_OVER128
	 CLR_BIT(SPI1 -> CR1 , CR1_BR0) ;
	 SET_BIT(SPI1 -> CR1 , CR1_BR1) ;
	 SET_BIT(SPI1 -> CR1 , CR1_BR2) ;
	 #elif BOUD_RATE_CON == F_OVER256
	 SET_BIT(SPI1 -> CR1 , CR1_BR0) ;
	 SET_BIT(SPI1 -> CR1 , CR1_BR1) ;
	 SET_BIT(SPI1 -> CR1 , CR1_BR2) ;
	 #else 
		 #error  "wrong choose boud rate"
	 #endif
	 //Master selection
     #if CONFIG_MODE ==  SLAVE
	  CLR_BIT(SPI1 -> CR1 , CR1_MSTR) ;
	#elif  CONFIG_MODE == MASTER  
	 SET_BIT(SPI1 -> CR1 , CR1_MSTR ) ;
	 #else    
		 #error  "wrong choose CONFIG MODE "
	 #endif
	 
	 //CPOL CPHA 
	 SET_BIT (SPI1 -> CR1 , CR1_CPOL) ;
	 SET_BIT (SPI1 -> CR1 , CR1_CPHA) ; 
	 //SPI_ENABLE 
	 SET_BIT(SPI1 -> CR1 , CR1_SPE);


	
}


u8  SPI_TX_RX(u8 data ){
	u8 rx  = 0 ; 
	
	SPI1 -> DR  = data ; 
	while (GET_BIT(SPI1 -> SR , 7)) ;
	rx = SPI1->DR ;
    return  rx ; 	
}

