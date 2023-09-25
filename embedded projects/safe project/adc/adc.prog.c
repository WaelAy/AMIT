#include <stdio.h>
#include "../dio/dio.h"

#include "adc.priv.h"
#include "adc.lib.h"
#include "adc.conf.h"



Error_State ADC_enuADCinit(u8 Copy_u8channel,u8 Copy_u8Mode){
    if (Copy_u8channel > ADC_NUMBER_OF_CHANNELS || Copy_u8channel < 0){
        return ES_NOK;
    } 

    dio_init(ADC_PORT_NUMBER,Copy_u8channel,INPUT);

    if(Copy_u8Mode == ADC_SINGLE_CONVERSION_MODE){
        ADMUX = Copy_u8Mode;
    }
   
    /*ADC Left shift*/
    if(ADC_ADJUST_LEFT == ADC_ENABLE){
        ADMUX = (ADC_ADJUST_LEFT<<ADLAR) | ADMUX;
    }
    
    
    /*Setting the refrence voltage*/
    ADMUX = (ADC_VOLTAGE_REF<<REFS0) | ADMUX;
    ADMUX = (ADC_VOLTAGE_REF<<REFS1) | ADMUX;


    /*ADC Enable*/
    ADCSRA |= (1<<ADEN);

    #if (ADC_MODE == ADC_AUTO_TRIGGER_MODE)
        ADCSRA |= (1<<ADATE);
        SFIOR = (ADC_AUTO_TRIGGER_MODE<<ADTS0) | SFIOR;

    #endif

    
    ADCSRA = (ADC_PRESCALER<<ADPS0) | ADCSRA;

    return ES_OK;

}

Error_State ADC_Read(u16 *Copy_u16Value){
    if (Copy_u16Value == NULL)
    {
        return ES_NOK;
    }
    
    /*ADC Start Conversion */
    ADCSRA |= (1<<ADSC);

    /*Waiting  to End Conversion */
    while ((ADCSRA & (1<<ADIF))==0);
    
    #if ADC_ADJUST_LEFT == ADC_ENABLE
        u8 local_u8lowernipple = ADCL>>6;
        *Copy_u16Value = ADCH<<2;
        *Copy_u16Value = *Copy_u16Value + local_u8lowernipple;
        

    #elif ADC_ADJUST_LEFT == 0

        *Copy_u16Value = ADCL;
        *Copy_u16Value = Copy_u16Value<<6;
        *Copy_u16Value = Copy_u16Value + (ADCL>>2);

    #endif


    return ES_OK;
}




