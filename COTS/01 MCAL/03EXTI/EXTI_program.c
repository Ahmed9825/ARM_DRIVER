#include	"Std_Types.h"
#include	"Bit_Math.h"
#include    "delay.h"
#include	"RCC_interface.h"
#include	"DIO_interface.h"

#include    "EXTI_interface.h"
#include    "EXTI_private.h"
#include    "EXTI_config.h"
#ifndef		NULL
#define		NULL			((void *)0)
#endif


static	void	(*EXTI_CallBack[16])	(void)	= {NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};

void		EXTI_voidInit(void)
{
	#ifndef      AFIO
	#define     AFIO_base_add       (0x40010000)
	#define     AFIO_EXTICR1       *((u32*)(AFIO_base_add +0x08))
	#define     AFIO_EXTICR2       *((u32*)(AFIO_base_add +0x0C))
	#define     AFIO_EXTICR3	   *((u32*)(AFIO_base_add +0x10))
	#define     AFIO_EXTICR4	   *((u32*)(AFIO_base_add +0x14))
	#endif
/*choose port       */
	switch(EXTI_PORT){
	case PA :

	AFIO_EXTICR1=0x0000 ;
	AFIO_EXTICR2=0x0000 ;
	AFIO_EXTICR3=0x0000 ;
	AFIO_EXTICR4=0x0000 ; break ;
	case PB:
	    AFIO_EXTICR1=0x1111 ;
		AFIO_EXTICR2=0x1111 ;
		AFIO_EXTICR3=0x1111 ;
		AFIO_EXTICR4=0x1111 ;break ;
	case  PC :
		AFIO_EXTICR4=0x2220 ; break ;

	}
/*choose sense mode     */
#if   SENSE_MODE  ==  RISING_EDGE
		SET_BIT(EXTI -> RTSR,LINE_NUM);
 #elif  SENSE_MODE  ==   FALLING_EDGE
		SET_BIT(EXTI -> FTSR,LINE_NUM);
 #elif  SENSE_MODE  ==   IOC
		SET_BIT(EXTI -> RTSR,LINE_NUM);
		SET_BIT(EXTI -> FTSR,LINE_NUM);
#else
#error  "Error chose wrong sense mode "
#endif
}
void		EXTI_voidEnableInt(u8 ID_INT)
{
	SET_BIT(EXTI -> IMR,ID_INT);
}
void		EXTI_voidDisableInt(u8 ID_INT)
{
	CLR_BIT(EXTI -> IMR,ID_INT);
}

void		EXTI_voidEnableSWI(u8 line_num)
{
	SET_BIT(EXTI -> SWIER,line_num);
}
void		EXTI_voidChangeSenseMode(u8 line_num, u8 Sense_Mode)
{
	switch(Sense_Mode)
	{
		case	RISING_EDGE		:	SET_BIT(EXTI -> RTSR,line_num);
									CLR_BIT(EXTI -> FTSR,line_num);		break;
		case	FALLING_EDGE	:	SET_BIT(EXTI -> FTSR,line_num);
									CLR_BIT(EXTI -> RTSR,line_num);		break;
		case	IOC				:	SET_BIT(EXTI -> RTSR,line_num);
									SET_BIT(EXTI -> FTSR,line_num);		break;
	}
	SET_BIT(EXTI -> IMR,line_num);
}

void		EXTI_voidSetCallBack(void (*Fptr)(void), u8 ID_EXTI)
{
	if(Fptr != NULL)
	{
		EXTI_CallBack[ID_EXTI] = Fptr;
	}
}

void	EXTI0_IRQHandler(void)
{
	if(EXTI_CallBack[0] !=NULL){
	EXTI_CallBack[0]();
	SET_BIT(EXTI-> PR ,LIN0 );
	}
	/*	Clear the Flag			*/
}

void	EXTI1_IRQHandler(void)
{
	if(EXTI_CallBack[1]!=NULL){
	EXTI_CallBack[1]();
	SET_BIT(EXTI-> PR ,LIN1 );
	}
	/*	Clear the Flag			*/
}

