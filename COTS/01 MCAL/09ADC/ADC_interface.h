#ifndef        ADC_interface
#define        ADC_interface

#include    "Std_Types.h"
#include    "Bit_Math.h"
#include    "ADC_private.h"
#include  "ADC_config.h"






//Adc_flags

#define    AWD        0                    // Analog watchdog flag
#define    EOC        1                    // End of conversion
#define    JEOC       2                    // Injected channel end of conversion
#define    JSTRT    3                        //Injected channel Start flag
#define    STRT      4                    //Regular channel Start flag


u8 ADC_getStatusflag(u8 flag);
void ADC_clearStatusflag(u8 flag);

void    ADC_voidInit(void);
void    ADC_voidEnable(void);
void     ADC_Start(void);

void ADC_channelSetup(u8 channel , u8 SEQuance,u8 SamplingTime);
void ADC_ScanConvMode(void);
void ADC_singOrcontainusConvMode(void);
void ADC_ExternalTrigConv(void);
void ADC_DataAligment(void);
void ADC_NbrOfConversion(void);
void ADC_tempSenEnable(void);
void ADC_DMAenable (void);




#endif
