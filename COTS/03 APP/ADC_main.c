#include	"Std_Types.h"
#include	"Bit_Math.h"

#include	"RCC_interface.h"
#include   "Dio_interface.h"
#include 	"EXTI_interface.h"
#include	"NVIC_interface.h"
#include	"STK_interface.h"
#include 	"DMA_interface.h"
#include   "Dio_interface.h"
#include "ADC_interface.h"
#include  "delay.h"

 //ADC_temperature main.c

 float Temperature;
 u16 ADC_Value;
 int main()
 {
	 RCC_voidSysClkInt();
	 RCC_voidEnablePerClk(RCC_APB2, 9); // enable ADC1 clock
	 RCC_voidEnablePerClk(RCC_APB2, 2);  // enable GPIOA clock

	 //temp sensor channel config
	 ADC_channelSetup(ADC_channe16,SEQ1,cyc_239_5);
	 ADC_voidInit();
	 ADC_voidEnable();
	 ADC_Start();
	 while(1)
	 {
		 ADC_Value	= ADC1->DR &0x0000FFFF;
		 Temperature = ((1.43 - ((float)(3.3*ADC_Value/(float)4095))) / 0.0043) + 15;
		 _delay_ms(1000);
	 }
	 return 0;
 }
