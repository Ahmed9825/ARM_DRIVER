#ifndef     SPI_CONFIG_H
#define     SPI_CONFIG_H

/*  choose  bidrictional data mode :
              1- FULL_DUPLEX
			  2- HALF_DUPLEX
			  */

#define         DIRECTIONAL_DATA             FULL_DUPLEX

/* choose the  direction of mode  :       // choose if you work on half duplex mode 
                    1-RECEIVE_ONLY 
					2-TRANSMIT_ONLY  
					
					*/ 
#define       DIRECTION_MODE           RECEIVE_ONLY

/*choose  direction  :  1- TRANS_RECEIVER
                        2- RECEIVER
						*/
						
#if			DIRECTIONAL_DATA	==		FULL_DUPLEX				
#define			DATA_DIR			TRANS_RECEIVER
#endif




/*choose CRC  mode  :
               1-  CRC_ON
			   2-  CRC_OFF 
			   
			   */
#define      CRC_EN           CRC_OFF

/*choose data frame format  :    1- DATA_8BIT
								 2- DATA_16BIT
								 */
#define      FRAME_FORMAT         DATA_8BIT

/*choose Software slave management : 

                                     1- DISABLE 
                                     2- ENABLE	
            */
#define      SLAVE_MANAG_EN            DISABLE

/*choose    SHIFT TYPE  :  1- MSB
						   2- LSB
							   */	
#define     SHIFT_TYPE       MSB  

/*choose BOUD RATE CONTROL :   1- F_OVER2
							   2- F_OVER4
							   3- F_OVER8
							   4- F_OVER16
							   5- F_OVER32
							   6- F_OVER64
							   7- F_OVER128
							   8- F_OVER256
							   */
#define    BOUD_RATE_CON        F_OVER4
/*choose  CONFIG_MODE :
                       1- SLAVE 
					   2- MASTER
					   */
#define     CONFIG_MODE      MASTER

#endif
