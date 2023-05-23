#ifndef		ADC_PRIVATE_H
#define		ADC_PRIVATE_H


typedef		struct
{
	u32				SR;
	u32				CR1;
	u32				CR2;
	u32				SMPR1;
	u32				SMPR2;
	u32				JOFR1;
	u32				JOFR2;
	u32				JOFR3;
	u32				JOFR4;
	u32				HTR;
	u32				LTR;
	u32				SQR1;
	u32				SQR2;
	u32				SQR3;
	u32				JSQR;
	u32				JDR1;
	u32				JDR2;
	u32				JDR3;
	u32				JDR4;
	u32				DR;
}ADC1_Type;

#define		ADC1		((volatile ADC1_Type*)(0x40012400))


#define 	ADC_ENABLE                    0
#define 	ADC_DISABLE 				  1

 
 //data alligment config

#define  	DATA_ALIGN_Right              0
#define  	DATA_ALIGN_Left               1 



//Choose  ADC_channel 

#define 	ADC_channe0 	    0
#define 	ADC_channe1			1
#define 	ADC_channe2			2
#define 	ADC_channe3			3
#define 	ADC_channe4			4
#define 	ADC_channe5			5
#define 	ADC_channe6			6
#define 	ADC_channe7			7
#define 	ADC_channe8			8
#define 	ADC_channe9			9
#define 	ADC_channe10		10
#define 	ADC_channe11		11
#define 	ADC_channe12		12
#define 	ADC_channe13		13
#define 	ADC_channe14		14
#define 	ADC_channe15		15
#define 	ADC_channe16		16
#define 	ADC_channe17		17


//choose sample time

#define 	cyc_1_5			0
#define 	cyc_7_5			1
#define 	cyc_13_5		2
#define 	cyc_28_5		3
#define 	cyc_41_5		4
#define 	cyc_55_5		5
#define 	cyc_71_5		6
#define 	cyc_239_5		7





#define 	SINGLE_MODE          0
#define 	CON_MODE     		 1

//external trigers starting

#define 	TIMER1_CC1            0	
#define 	TIMER1_CC2			  1
#define 	TIMER1_CC3			  2
#define 	TIMER2_CC2			  3
#define 	TIMER3_TRGo           4
#define 	TIMER4_CC4			  5
#define 	Ext1_LINE11			  6
#define 	SWSTART				  7

//sequance values

#define 	SEQ1        	1
#define 	SEQ2			2
#define 	SEQ3			3
#define 	SEQ4			4
#define 	SEQ5			5
#define 	SEQ6			6
#define 	SEQ7			7
#define 	SEQ8			8
#define 	SEQ9			9
#define 	SEQ10			10
#define 	SEQ11			11
#define 	SEQ12			12
#define 	SEQ13			13
#define 	SEQ14			14
#define 	SEQ15			15
#define 	SEQ16			16


#endif
