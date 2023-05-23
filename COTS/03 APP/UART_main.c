#include	"Std_Types.h"
#include	"Bit_Math.h"
#include	"RCC_interface.h"
#include    "DIO_interface.h"
#include    "delay.h"
#include    "UART_interface.h"
#include    "LED.h"
#include    "BUTTON.h"
#include 	"LCD4BIT.h"
#include 	"KEYPAD.h"

u8 d = 0 ;

int main()
{

	RCC_voidSysClkInt();

	RCC_voidEnablePerClk(RCC_APB2,2); //porta
	RCC_voidEnablePerClk(RCC_APB2,14);//uart1
	RCC_voidEnablePerClk(RCC_APB2,0);//AF

	DIO_voidSetPinDirection(PORTA ,PIN9, GPIO_OUTPUT_2MHZ_AFPP);
	DIO_voidSetPinDirection(PORTA ,PIN10,GPIO_INPUT_FLOAT );
    LED_init(PORTA, PIN0) ;
	UART_init() ;
	UART_enableTX();
	UART_enableRX() ;
	while (1) {
        UART_TXdata('a') ;
        UART_RXdata(&d) ;
       if (d == 'a'){
    	   LED_on(PORTA, PIN0) ;
    	   _delay_ms(1000) ;
       }

        LED_off(PORTA , PIN0) ;
        _delay_ms(1000) ;
 }
	return 0 ;
}
