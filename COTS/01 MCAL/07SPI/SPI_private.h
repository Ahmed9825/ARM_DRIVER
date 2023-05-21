
#ifndef     SPI_PRIVATE_H
#define     SPI_PRIVATE_H

typedef  struct {
	u32  CR1 	;
	u32  CR2 	;
	u32  SR  	;
	u32  DR  	;
	u32  CRCPR 	;
	u32  RXCRCR ;
	u32  TXCRCR ;

}SPI1_TYPE ;








#define 		SPI1          ((SPI1_TYPE *)0x40013000)


#define   FULL_DUPLEX       1
#define   HALF_DUPLEX		2


#define       RECEIVE_ONLY        1
#define       TRANSMIT_ONLY       2  


#define      CRC_ON               1
#define      CRC_OFF              2

#define       DATA_8BIT           1
#define       DATA_16BIT          2 


#define       TRANS_RECEIVER 		1
#define       RECEIVER              2


#define         DISABLE 			1
#define         ENABLE              2 

#define      MSB             1
#define      LSB		     2

#define      F_OVER2                  1
#define      F_OVER4     			  2
#define      F_OVER8			      3
#define      F_OVER16				  4
#define      F_OVER32				  5
#define      F_OVER64				  6
#define      F_OVER128			      7
#define      F_OVER256			      8

#define      SLAVE				1 
#define      MASTER				2  
//CR1

#define  CR1_BIDIMODE            15
#define  CR1_BIDIOE              14
#define  CR1_CRCEN               13
#define  CR1_DFF                 11
#define  CR1_RXONLY              10
#define  CR1_SSM                 9
#define  CR1_SSI                 8
#define  CR1_LSBFIRST            7
#define  CR1_SPE                 6
#define  CR1_BR0                 5
#define  CR1_BR1                 4
#define  CR1_BR2                 3
#define  CR1_MSTR                2
#define  CR1_CPOL 			     1
#define  CR1_CPHA                0
#endif
