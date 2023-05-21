#include	"Std_Types.h"
#include	"Bit_Math.h"
#include	"RCC_interface.h"
#include    "DIO_interface.h"
#include    "delay.h"
#include    "DMA_interface.h"
#include    "DMA_config.h"
#include    "DMA_private.h"




void	DMA1_voidChannelInit(u8 channelID , u16 trans  , u8 prioritylevel , u8 suorcesize ,u8 distincsize )
{
	/*Memory to Memory*/
	switch(trans){
		case M2M : SET_BIT(DMA1 ->Channel[channelID].CCR,CCR_MEM2MEM);
				   SET_BIT(DMA1 ->Channel[channelID].CCR,CCR_MINC)   ;
				   SET_BIT(DMA1 ->Channel[channelID].CCR,CCR_PINC)   ;
				   CLR_BIT(DMA1 ->Channel[channelID].CCR,CCR_DIR)   ;break ;


		case M2P : CLR_BIT(DMA1 ->Channel[channelID].CCR,CCR_MEM2MEM);
				   SET_BIT(DMA1 ->Channel[channelID].CCR,CCR_MINC)   ;
	               CLR_BIT(DMA1 ->Channel[channelID].CCR,CCR_PINC)   ;
				   SET_BIT(DMA1 ->Channel[channelID].CCR,CCR_DIR)   ;break ;

		case P2M : CLR_BIT(DMA1 ->Channel[channelID].CCR,CCR_MEM2MEM);
		           SET_BIT(DMA1 ->Channel[channelID].CCR,CCR_MINC)   ;
				   CLR_BIT(DMA1 ->Channel[channelID].CCR,CCR_PINC)   ;
				   CLR_BIT(DMA1 ->Channel[channelID].CCR,CCR_DIR)   ;break ;

		case P2P : CLR_BIT(DMA1 ->Channel[channelID].CCR,CCR_MEM2MEM);
		           CLR_BIT(DMA1 ->Channel[channelID].CCR,CCR_MINC)   ;
				   CLR_BIT(DMA1 ->Channel[channelID].CCR,CCR_PINC)   ;
				   CLR_BIT(DMA1 ->Channel[channelID].CCR,CCR_DIR)   ;break ;
	}
	/*priority very high*/
	    switch(prioritylevel){

			case  LOW_PRIORITY      : CLR_BIT(DMA1 ->Channel[channelID].CCR,CCR_PL0);
									  CLR_BIT(DMA1 ->Channel[channelID].CCR,CCR_PL1)   ;break ;


			case  MEDIUM_PRIORITY   : SET_BIT(DMA1 ->Channel[channelID].CCR,CCR_PL0);
									  CLR_BIT(DMA1 ->Channel[channelID].CCR,CCR_PL1) ;break ;

			case  HIGH_PRIORITY     : CLR_BIT(DMA1 ->Channel[channelID].CCR,CCR_PL0);
									  SET_BIT(DMA1 ->Channel[channelID].CCR,CCR_PL1)   ;break ;

			case  VERYHIGH_PRIORITY :SET_BIT(DMA1 ->Channel[channelID].CCR,CCR_PL0);
									 SET_BIT(DMA1 ->Channel[channelID].CCR,CCR_PL1)   ;break ;
		}
	//Size (Source & Destination) u32
	switch(suorcesize){

			case  BYTE      :CLR_BIT(DMA1 ->Channel[channelID].CCR,CCR_MSIZE0);
							 CLR_BIT(DMA1 ->Channel[channelID].CCR,CCR_MSIZE1);break ;

			case  TWO_BYTE   : SET_BIT(DMA1 ->Channel[channelID].CCR,CCR_MSIZE0);
							   CLR_BIT(DMA1 ->Channel[channelID].CCR,CCR_MSIZE1);break ;

			case  FOUR_BYTE  : CLR_BIT(DMA1 ->Channel[channelID].CCR,CCR_MSIZE0);
							   SET_BIT(DMA1 ->Channel[channelID].CCR,CCR_MSIZE1);break ;
		}
		switch(distincsize){

			case  BYTE      :CLR_BIT(DMA1 ->Channel[channelID].CCR,CCR_PSIZE0);
							 CLR_BIT(DMA1 ->Channel[channelID].CCR,CCR_PSIZE1);break ;

			case  TWO_BYTE   : SET_BIT(DMA1 ->Channel[channelID].CCR,CCR_PSIZE0);
							   CLR_BIT(DMA1 ->Channel[channelID].CCR,CCR_PSIZE1);break ;

			case  FOUR_BYTE  : CLR_BIT(DMA1 ->Channel[channelID].CCR,CCR_PSIZE0);
							   SET_BIT(DMA1 ->Channel[channelID].CCR,CCR_PSIZE1);break ;
		}
	//MINC, PINC enabled
	//Direction read from Peripheral
	//Transfere Complete Interrupt
	//Transfere Complete Interrupt
    SET_BIT(DMA1 ->Channel[channelID].CCR,CCR_TEIE);
    //Channel Disable
    CLR_BIT(DMA1 ->Channel[channelID].CCR,CCR_EN);
	//Channel Disable
	
	DMA1 ->	Channel[0].CCR = 0x00007AC2;
}

void	DMA1_voidStartChannel(u32 * SrcAdd,u32 * DestAdd,u16 BlockLength)
{
	/*		Make Sure that the channel is  disabled */
	CLR_BIT(DMA1 -> Channel[0].CCR,0);
	
	DMA1 -> Channel[0].CPAR	=	SrcAdd;
	DMA1 -> Channel[0].CMAR	=	DestAdd;
	
	/*	Load the Block Length				*/
	DMA1 -> Channel[0].CNDTR	=	BlockLength;

	/*		Make Sure that the channel is  Enabled to strat transfere*/
	SET_BIT(DMA1 -> Channel[0].CCR,0);	
}








