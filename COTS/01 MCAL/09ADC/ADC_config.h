#ifndef		ADC_config
#define		ADC_config




/*chose  ADC_SCANMODE   :  1-ADC_ENABLE    
						   2-ADC_DISABLE
						   */




#define ADC1_ScanConvMode	ADC_DISABLE 

/*choose ADC_MODE     1- SINGLE_MODE 
                      2-CON_MODE 
					  */



#define ADC1_MODE 	CON_MODE

/*choose  ADC_EXTRNALCONV_MODE          1-TIMER1_CC1            				
										2-TIMER1_CC2
										3-TIMER1_CC3	
										4-TIMER2_CC2
										5-TIMER3_TRGo
										6-TIMER4_CC4
										7-Ext1_LINE11	
										8-SWSTART
										
										*/


#define ADC1_ExternalTrigConv  SWSTART

/*choose DATA_MODE : 1- DATA_ALIGN_Right          
					 2- DATA_ALIGN_Left  
*/					 


#define DATA_MODE  DATA_ALIGN_Right 
/*choose number of conv : from 1 to 16 */


#define    ADC1_NbrOfConversion       1

/*choose  temp. sensor : 1- ADC_ENABLE
						 2- ADC_DISABLE 
						 */


#define ADC1_tempSen  ADC_ENABLE

/*choose  DMA          : 1- ADC_ENABLE
						 2- ADC_DISABLE 
						 */

#define ADC1_DMA  ADC_DISABLE






#endif
