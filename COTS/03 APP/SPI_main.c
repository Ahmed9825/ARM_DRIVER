#include	"Std_Types.h"
#include	"Bit_Math.h"
#include	"RCC_interface.h"
#include    "DIO_interface.h"
#include    "SPI_interface.h"
#include    "delay.h"
#include    "LED.h"
#include    "BUTTON.h"
#include 	"LCD4BIT.h"
#include 	"KEYPAD.h"
#include 	"7seg.h"

int main(void)
{
	u8 x = 0 ;
	RCC_voidSysClkInt() ;
	RCC_voidEnablePerClk(RCC_APB2, 0);  // AF
	RCC_voidEnablePerClk(RCC_APB2, 2);  //PORTA
	RCC_voidEnablePerClk(RCC_APB2, 3);
	RCC_voidEnablePerClk(RCC_APB2, 12) ;

	DIO_voidSetPinDirection(PORTA, PIN7, GPIO_OUTPUT_2MHZ_AFPP) ;
	DIO_voidSetPinDirection(PORTA, PIN6, GPIO_INPUT_FLOAT) ;
	DIO_voidSetPinDirection(PORTA, PIN5, GPIO_OUTPUT_2MHZ_AFPP) ;
	LED_init(PORTB, PIN0) ;
	SPI_init() ;
    /* Loop forever */


	while(1) {

		x= SPI_TX_RX('a') ;
		if(x== 'a'){
			LED_on(PORTB ,PIN0) ;
			_delay_ms(1000) ;
		}else {
			LED_off(PORTB, PIN0) ;
			_delay_ms(1000) ;
		}


	}

	return 0 ;
}
