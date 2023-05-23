#include 			"STD_TYPES.h"
#include 			"Bit-Math.h"
#include            "RCC_interface.h"
#include            "GPIO_interface.h"
#include            "SPI_interface.h"
#include            "TFT_interface.h"
#include            "STK_interface.h"
//#include            "727e5ea10a3f1852dcbdb06b3733cb7f.h"
#include      "Un.h"
void  main(){

	// HSE 8MHZ
	RCC_voidInit();
	// GPIO A
	RCC_voidEnableClock(RCC_APB2,2);
/* spi enable clock*/
	RCC_voidEnableClock(RCC_APB2,12);

		MGPIO_voidSetPinDirection(GPIO_U8_A,GPIO_U8_PIN1,GPIO_OUTPUT_2MHZ_PP);
		MGPIO_voidSetPinDirection(GPIO_U8_A,GPIO_U8_PIN2,GPIO_OUTPUT_2MHZ_PP);
		MGPIO_voidSetPinDirection(GPIO_U8_A,GPIO_U8_PIN5,GPIO_OUTPUT_2MHZ_AFPP);
		MGPIO_voidSetPinDirection(GPIO_U8_A,GPIO_U8_PIN7,GPIO_OUTPUT_2MHZ_AFPP);


	MSTK_voidInit();

	MSPI1_voidInit();

	HTFT_voidInit();
	 HTFT_voidDisplayImage(image);

	 while(1){



	 }




 }
