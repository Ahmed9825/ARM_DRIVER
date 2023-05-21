


#ifndef		EXTI_PRIVATE_H
#define		EXTI_PRIVATE_H



#define		EXTI_BASE_ADD			0x40010400


typedef struct
{
	volatile	u32		IMR;
	volatile	u32		EMR;
	volatile	u32		RTSR;
	volatile	u32		FTSR;
	volatile	u32		SWIER;
	volatile	u32		PR;
	
}EXTI_Type;

#define			EXTI				((EXTI_Type *)(EXTI_BASE_ADD))

#define     PA           1
#define     PB	         2
#define     PC			 3

#define   	LIN0		0
#define		LIN1        1
#define		LIN2		2
#define		LIN3	    3
#define		LIN4		4
#define		LIN5		5
#define		LIN6		6
#define		LIN7		7
#define		LIN8        8
#define		LIN9        9
#define		LIN10	    10
#define		LIN11       11
#define		LIN12       12
#define		LIN13		13
#define     LIN14       14
#define		LIN15       15
























#endif
