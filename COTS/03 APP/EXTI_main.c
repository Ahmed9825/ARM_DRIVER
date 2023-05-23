#include	"Std_Types.h"
#include	"Bit_Math.h"
#include    "delay.h"
#include	"RCC_interface.h"
#include	"DIO_interface.h"

#include	"NVIC_interface.h"
#include    "EXTI_interface.h"
#include    "LED.h"
#include    "BUTTON.h"

void LED (void){

	LED_on(PORTA , PIN0 ) ;
	_delay_ms(1000) ;
	LED_off(PORTA , PIN0 ) ;
		_delay_ms(1000) ;

}


int main(void)
{

	/*	System Clock Init			*/
	RCC_voidSysClkInt();

	/*	Enable RCC for GPIOC 		*/
	RCC_voidEnablePerClk(RCC_APB2,4);
	RCC_voidEnablePerClk(RCC_APB2,2);
	RCC_voidEnablePerClk(RCC_APB2,3);
	//enable AFIO
	RCC_voidEnablePerClk(RCC_APB2,0);
	EXTI_voidSetCallBack(LED, 1);

	LED_init(PORTA, PIN0) ;
		BUTTON_init(PORTB, PIN1) ;


		/*	C13 Direction 	"Output @ 2MHz Push Pull"	*/
	//DIO_voidSetPinDirection(PORTC,PIN13,GPIO_OUTPUT_2MHZ_PP);

	/*	Interrupt Initialization	*/
	NVIC_voidInit();

	EXTI_voidInit() ;



	/*	EXTI0 Gropu id 3 and Sub 0	lower priority	*/
	//NVIC_voidSetSwIntPriority(7,0b1100);

	/*	EXTI1 Gropu id 0 and Sub 2 Higher priority	*/
	//NVIC_voidSetSwIntPriority(6,0b0010);

	/*	Set pending Flag EXTI0		*/
	//NVIC_voidSetPendingFlag(6);


	/*	Set pending Flag EXTI1		*/
	//NVIC_voidSetPendingFlag(7);

	/*	NVIC EXTI0 Enable 			*/
	NVIC_voidEnablePerInt(7);

	EXTI_voidEnableInt(1);
	/*	NVIC EXTI1 Enable 			*/
	//NVIC_voidEnablePerInt(7);


	while(1)
	{

	}
	return 0;
}
//void 	__vector_1(void)

