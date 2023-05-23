#include	"Std_Types.h"
#include	"Bit_Math.h"
#include    "delay.h"
#include	"RCC_interface.h"
#include	"DIO_interface.h"

#include	"NVIC_interface.h"
#include    "EXTI_interface.h"
#include    "LED.h"
#include    "BUTTON.h"


int main(void)
{

	/*	System Clock Init			*/
	RCC_voidSysClkInt();

	/*	Enable RCC for GPIOC 		*/
	RCC_voidEnablePerClk(RCC_APB2,4);
	RCC_voidEnablePerClk(RCC_APB2,2);
	RCC_voidEnablePerClk(RCC_APB2,3) ;

	LED_init(PORTA, PIN0) ;
	LED_init(PORTA, PIN1) ;
	LED_init(PORTA, PIN2) ;
	LED_init(PORTA, PIN3) ;
	LED_init(PORTA, PIN4) ;


	    DIO_voidSetPinDirection(PORTB, PIN8 ,GPIO_INPUT_PULL_UP_DOWN) ;
		DIO_voidSetPinDirection(PORTB, PIN7 ,GPIO_INPUT_PULL_UP_DOWN) ;
		DIO_voidSetPinDirection(PORTB, PIN6 ,GPIO_INPUT_PULL_UP_DOWN) ;
		DIO_voidSetPinDirection(PORTB, PIN5 ,GPIO_INPUT_PULL_UP_DOWN) ;
		DIO_voidSetPinDirection(PORTB, PIN4 ,GPIO_INPUT_PULL_UP_DOWN) ;





	while(1)
	{



      if(DIO_u8GetPinValue(PORTB, PIN8) == 1 ){
        LED_on(PORTA, PIN0) ;
      }else{
    	  LED_off(PORTA, PIN0) ;
      }
      if(DIO_u8GetPinValue(PORTB,PIN7) ==1 ){
    	  LED_on(PORTA, PIN1) ;
      }else{
    	  LED_off(PORTA, PIN1) ;
      }
      if(DIO_u8GetPinValue(PORTB,PIN6) ==1 ){
          	  LED_on(PORTA, PIN2) ;
            }else{
          	  LED_off(PORTA, PIN2) ;
            }
      if(DIO_u8GetPinValue(PORTB,PIN5) ==1 ){
          	  LED_on(PORTA, PIN3) ;
            }else{
          	  LED_off(PORTA, PIN3) ;
            }
      if(DIO_u8GetPinValue(PORTB,PIN4) ==1 ){
          	  LED_off(PORTA, PIN4) ;
            }
      else{
          	  LED_on(PORTA, PIN4) ;
            }
      _delay_ms(1000);
      _delay_ms(1000);


	}
	return 0;
}
//void 	__vector_1(void)

