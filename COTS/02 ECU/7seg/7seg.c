#include	"Std_Types.h"
#include	"Bit_Math.h"
#include	"RCC_interface.h"
#include    "DIO_interface.h"
#include    "delay.h"
#include 	"7seg.h"


void seg_init(void){
	DIO_voidSetPinDirection(DATA_PORT_7seg, A, GPIO_OUTPUT_2MHZ_PP);
	DIO_voidSetPinDirection(DATA_PORT_7seg, B, GPIO_OUTPUT_2MHZ_PP);
	DIO_voidSetPinDirection(DATA_PORT_7seg, C, GPIO_OUTPUT_2MHZ_PP);
	DIO_voidSetPinDirection(DATA_PORT_7seg, D, GPIO_OUTPUT_2MHZ_PP);
	DIO_voidSetPinDirection(DATA_PORT_7seg, E, GPIO_OUTPUT_2MHZ_PP);
	DIO_voidSetPinDirection(DATA_PORT_7seg, F, GPIO_OUTPUT_2MHZ_PP);
	DIO_voidSetPinDirection(DATA_PORT_7seg, G, GPIO_OUTPUT_2MHZ_PP);
    DIO_voidSetPinDirection(DATA_PORT_7seg, H, GPIO_OUTPUT_2MHZ_PP);
}

void seg_number(u8 number) {
	switch(number){
		case 0 :  DIO_voidSethlafPortval(DATA_PORT_7seg , 0x3f) ; break ;
		case 1 :  DIO_voidSethlafPortval(DATA_PORT_7seg , 0x06) ; break ;
		case 2 :  DIO_voidSethlafPortval(DATA_PORT_7seg , 0x5b) ; break ;
		case 3 :  DIO_voidSethlafPortval(DATA_PORT_7seg , 0x4f) ; break ;
		case 4 :  DIO_voidSethlafPortval(DATA_PORT_7seg , 0x66) ; break ;
		case 5 :  DIO_voidSethlafPortval(DATA_PORT_7seg , 0x6d) ; break ;
		case 6 :  DIO_voidSethlafPortval(DATA_PORT_7seg , 0x7c) ; break ;
		case 7 :  DIO_voidSethlafPortval(DATA_PORT_7seg , 0x07) ; break ;
		case 8 :  DIO_voidSethlafPortval(DATA_PORT_7seg , 0x7f) ; break ;
		case 9 :  DIO_voidSethlafPortval(DATA_PORT_7seg , 0x6f) ; break ;
	}
}
