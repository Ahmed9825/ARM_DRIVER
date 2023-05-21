


#ifndef		EXTI_INTERFACE_H
#define		EXTI_INTERFACE_H

void		EXTI_voidInit(void);
void		EXTI_voidEnableInt(u8 line_num);
void		EXTI_voidDisableInt(u8 line_num);

void		EXTI_voidEnableSWI(u8 line_num);
void		EXTI_voidChangeSenseMode(u8 line_num, u8 Sense_Mode);


void		EXTI_voidSetCallBack(void (*Fptr)(void), u8 ID_EXTI);

#define    RISING_EDGE            1
#define    FALLING_EDGE           2
#define    IOC                    3

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
