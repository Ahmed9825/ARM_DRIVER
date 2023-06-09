#include "ADC_interface.h"

void	ADC_voidInit(void){

	ADC_ScanConvMode() ;  // SCAN mode enabled
	ADC_singOrcontainusConvMode();    // enable continuous conversion mode
	ADC_ExternalTrigConv();  // External Event selection pointed to SWSTART bit
	ADC_DataAligment();   // Data Alignment RIGHT
	//Set the Regular channel sequence length in ADC_SQR1
	ADC_NbrOfConversion();
	// Set the TSVREFE Bit to wake the sensor
	ADC_tempSenEnable();
	// Enable or disable  DMA for ADC
	ADC_DMAenable();

}


//adc enable
void	ADC_voidEnable(void){
SET_BIT(ADC1->CR2,0);  // ADON =1 enable ADC1
	u32 delay = 10000;
	while (delay--);
}
//ADC_start adc
void ADC_Start(void){
	 // Clear Status register
	CLR_BIT(  ADC1->SR,0);
	CLR_BIT(  ADC1->SR,1);
	CLR_BIT(  ADC1->SR,2);
	CLR_BIT(  ADC1->SR,3);
	CLR_BIT(  ADC1->SR,4);

	SET_BIT(ADC1->CR2 ,20);// Conversion on external event enabled
	SET_BIT(ADC1->CR2,22);// Start conversion
}

void ADC_channelSetup(u8 channel , u8 SEQuance,u8 SamplingTime){
switch(SEQuance){
case SEQ1:	ADC1->SQR3 |= (channel<<0); 		  break;
case SEQ2:	ADC1->SQR3 |= (channel<<5); 		  break;
case SEQ3:	ADC1->SQR3 |= (channel<<10); 		  break;
case SEQ4:	ADC1->SQR3 |= (channel<<15); 		  break;
case SEQ5:	ADC1->SQR3 |= (channel<<20); 		  break;
case SEQ6:	ADC1->SQR3 |= (channel<<25); 		  break;
case SEQ7:	ADC1->SQR2 |= (channel<<0); 		  break;
case SEQ8:	ADC1->SQR2 |= (channel<<5);			  break;
case SEQ9:	ADC1->SQR2 |= (channel<<10);		  break;
case SEQ10:	ADC1->SQR2 |= (channel<<15);		  break;
case SEQ11:	ADC1->SQR2 |= (channel<<20);		  break;
case SEQ12:	ADC1->SQR2 |= (channel<<25);		  break;
case SEQ13:	ADC1->SQR1 |= (channel<<0);			  break;
case SEQ14:	ADC1->SQR1 |= (channel<<5);			  break;
case SEQ15:	ADC1->SQR1 |= (channel<<10);		  break;
case SEQ16:	ADC1->SQR1 |= (channel<<15);		  break;
}
switch (channel){
case ADC_channe0: ADC1->SMPR2 |= (SamplingTime<<0);		break;
case ADC_channe1: ADC1->SMPR2 |= (SamplingTime<<3);		break;
case ADC_channe2: ADC1->SMPR2 |= (SamplingTime<<6);		break;
case ADC_channe3: ADC1->SMPR2 |= (SamplingTime<<9);		break;
case ADC_channe4: ADC1->SMPR2 |= (SamplingTime<<12);		break;
case ADC_channe5: ADC1->SMPR2 |= (SamplingTime<<15);		break;
case ADC_channe6: ADC1->SMPR2 |= (SamplingTime<<18);		break;
case ADC_channe7: ADC1->SMPR2 |= (SamplingTime<<21);		break;
case ADC_channe8: ADC1->SMPR2 |= (SamplingTime<<24);		break;
case ADC_channe9: ADC1->SMPR2 |= (SamplingTime<<27);		break;

case ADC_channe10: ADC1->SMPR1 |= (SamplingTime<<0);		break;
case ADC_channe11: ADC1->SMPR1 |= (SamplingTime<<3);		break;
case ADC_channe12: ADC1->SMPR1 |= (SamplingTime<<6);		break;
case ADC_channe13: ADC1->SMPR1 |= (SamplingTime<<9);		break;
case ADC_channe14: ADC1->SMPR1 |= (SamplingTime<<12);		break;
case ADC_channe15: ADC1->SMPR1 |= (SamplingTime<<15);		break;
case ADC_channe16: ADC1->SMPR1 |= (SamplingTime<<18);		break;
case ADC_channe17: ADC1->SMPR1 |= (SamplingTime<<21);		break;

}

}

//get flag status
u8 ADC_getStatusflag(u8 flag){
	u8 local_val = 0 ;
	if (flag == AWD){
		local_val=GET_BIT(ADC1->SR,0);
	}else if (flag ==EOC ){
		local_val=GET_BIT(ADC1->SR,1);
	}else if (flag ==JEOC ){
		local_val=GET_BIT(ADC1->SR,2);
	}else if (flag == JSTRT){
		local_val=	GET_BIT(ADC1->SR,3);
	}else if (flag==STRT ){
		local_val=GET_BIT(ADC1->SR,4);
	}else {
		//wrong status flag select
	}

	return local_val ;
}


//clear flag status
void AD_clearStatusflag(u8 flag){
	if (flag == AWD){
			CLR_BIT(ADC1->SR,0);
		}else if (flag ==EOC ){
			CLR_BIT(ADC1->SR,1);
		}else if (flag ==JEOC ){
			CLR_BIT(ADC1->SR,2);
		}else if (flag == JSTRT){
			CLR_BIT(ADC1->SR,3);
		}else if (flag==STRT ){
			CLR_BIT(ADC1->SR,4);
		}else {
			/*wrong status flag select*/
		}
}

void ADC_ScanConvMode(void){

	if(ADC1_ScanConvMode == ADC_ENABLE){
		SET_BIT(ADC1->CR1,8);
	}else if(ADC1_ScanConvMode == ADC_DISABLE){
		CLR_BIT(ADC1->CR1,8);
	}else{
		//error in config
	}
}

void ADC_singOrcontainusConvMode(void){

	if( ADC1_MODE 	==   CON_MODE ){
		SET_BIT(ADC1->CR2,1);
	}else if(ADC1_MODE == SINGLE_MODE){
		CLR_BIT(ADC1->CR2,1);
	}else{
		//error in config
	}
}


void ADC_ExternalTrigConv(void){
	if(ADC1_ExternalTrigConv==TIMER1_CC1){
		ADC1->CR2 |= (0<<17);
	}else if(ADC1_ExternalTrigConv==TIMER1_CC2){
		ADC1->CR2 |= (1<<17);
	}else if(ADC1_ExternalTrigConv==TIMER1_CC3){
		ADC1->CR2 |= (2<<17);
	}else if(ADC1_ExternalTrigConv==TIMER2_CC2){
		ADC1->CR2 |= (3<<17);
	}else if(ADC1_ExternalTrigConv==TIMER3_TRGo){
		ADC1->CR2 |= (4<<17);
	}else if(ADC1_ExternalTrigConv==TIMER4_CC4){
		ADC1->CR2 |= (5<<17);
	}else if(ADC1_ExternalTrigConv==Ext1_LINE11){
		ADC1->CR2 |= (6<<17);
	}else if(ADC1_ExternalTrigConv==SWSTART){
		ADC1->CR2 |= (7<<17);
	}else{
		//error selecting external trigger
	}

}
void ADC_DataAligment(void){
	if(DATA_MODE == DATA_ALIGN_Right){
		CLR_BIT(ADC1->CR2,11);
	}else if (DATA_MODE  == DATA_ALIGN_Left ){
		SET_BIT(ADC1->CR2,11);
	}else{
		//error inalligment config
	}

}
void ADC_NbrOfConversion(void){
	ADC1->SQR1 |= ((ADC1_NbrOfConversion-1)<<20);
}

void ADC_tempSenEnable(void){

	if(ADC1_tempSen == ADC_ENABLE){
		SET_BIT(ADC1->CR2,23);
	}else if(ADC1_tempSen == ADC_DISABLE){
		CLR_BIT(ADC1->CR2,23);
	}else{
		//error in temp config
	}
}


void ADC_DMAenable (void){
	if(ADC1_DMA == ADC_ENABLE){
			SET_BIT(ADC1->CR2,8);
		}else if(ADC1_DMA == ADC_DISABLE){
			CLR_BIT(ADC1->CR2,8);
		}else{
			//error in DMA config
		}
}
