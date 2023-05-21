#ifndef   DMA_private_H
#define   DMA_private_H


typedef		struct
{
	u32		CCR;
	u32		CNDTR;
	u32		CPAR;
	u32		CMAR;
	u32		Reserved;		
}DMA_Channel;

typedef		struct
{
	u32				ISR;
	u32				IFCR;
	DMA_Channel		Channel[7]	;
}DMA1_Type;

#define		DMA1		((volatile DMA1_Type*)(0x40020000))

//define bit register ccr 
 #define    CCR_EN					0
 #define    CCR_TCIE				1
 #define    CCR_HTIE				2
 #define    CCR_TEIE				3
 #define    CCR_DIR					4
 #define    CCR_CIRC				5
 #define    CCR_PINC				6
 #define    CCR_MINC				7
 #define    CCR_PSIZE0				8
 #define    CCR_PSIZE1				9
 #define    CCR_MSIZE0				10
 #define    CCR_MSIZE1				11
 #define    CCR_PL0					12
 #define    CCR_PL1					13
 #define    CCR_MEM2MEM				14
 
#endif 


