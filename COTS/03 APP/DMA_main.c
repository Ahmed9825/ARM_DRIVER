#include	"Std_Types.h"
#include	"Bit_Math.h"
#include	"RCC_interface.h"
#include    "DIO_interface.h"
#include	"NVIC_interface.h"
#include    "DMA_interface.h"
#include    "delay.h"
#include    "LED.h"
#include    "BUTTON.h"
#include 	"LCD4BIT.h"
#include 	"KEYPAD.h"




u32	Processor_Arr1[500];
u32	Processor_Arr2[500];

u32	DMA_Arr3[500];
u32	DMA_Arr4[500];


int main()
{
	for(u16 i = 0 ; i < 500 ; i++)
	{
		Processor_Arr1[i]	=	i;
		DMA_Arr3[i]			=	i;
	}

	/*	System init			*/
	RCC_voidSysClkInt() ;
	RCC_voidEnablePerClk(RCC_AHB,0);
	NVIC_voidEnablePerInt(11);
	DMA1_voidChannelInit(0 , M2M , HIGH_PRIORITY, BYTE, BYTE) ;
	/*	DMA1 Channel Transfere Round	*/
	DMA1_voidStartChannel(DMA_Arr3,DMA_Arr4,500);

	/*	Processor Transfere Round	*/
	for(u16 i = 0 ; i < 500 ; i++)
	{
		Processor_Arr2[i]	=	Processor_Arr1[i];
	}



while(1)
{

}

return 0;
}

void	DMA1_Channel1_IRQHandler()
{
	u8 x=8;
	x++;
}
