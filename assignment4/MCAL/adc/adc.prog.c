
#include "../dio/dio.h"

#include "adc.priv.h"
#include "adc.lib.h"
#include "adc.conf.h"

static void (*local_funptrIntTriggered)(void*) = NULL;
static void *local_vfunParameterptr = NULL;

Error_State ADC_enuADCinit(u8 Copy_u8channel){
    if (Copy_u8channel > ADC_NUMBER_OF_CHANNELS || Copy_u8channel < 0){
        return ES_NOK;
    } 

    dio_init(ADC_PORT_NUMBER,Copy_u8channel,INPUT);

    /*Setting ADC Channel*/
    ADMUX = Copy_u8channel;


    /*ADC Left shift*/
    if(ADC_ADJUST_LEFT == ADC_ENABLE){
        ADMUX = (ADC_ADJUST_LEFT<<ADLAR) | ADMUX;
    }
    
    
    /*Setting the refrence voltage*/
    ADMUX = (ADC_VOLTAGE_REF<<REFS0) | ADMUX;
    ADMUX = (ADC_VOLTAGE_REF<<REFS1) | ADMUX;


    /*ADC Enable*/
    ADCSRA |= (1<<ADEN);


    
    ADCSRA = (ADC_PRESCALER<<ADPS0) | ADCSRA;

    return ES_OK;

}

Error_State ADC_Read(u16 *Copy_u16Value){
    if (Copy_u16Value == NULL)
    {
        return ES_NOK;
    }
    

    /*If the ADATE bit is not set then its single convertion mode*/
    if((ADCSRA & (1<<ADATE))==0){

        /*ADC Start Conversion */
        ADCSRA |= (1<<ADSC);

        /*Waiting  to End Conversion */
        while ((ADCSRA & (1<<ADIF))==0);


    }

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

Error_State ADC_enuAutoTriggerEnable(u8 Copy_u8AutoTriggerSource){

        static bool Local_u8firstTimeFlag = false;


        /*Setting the auto trigger bit*/  
        ADCSRA |= (ADC_ENABLE<<ADATE);

        /*Setting the auto trigger source*/
        SFIOR |= Copy_u8AutoTriggerSource<<ADTS0;


        /*Starting the first Convertion*/
        ADCSRA |= (1<<ADSC);

        /*Setting the flag to wait for 25 cycles*/
        if (Local_u8firstTimeFlag == false){
            Local_u8firstTimeFlag = true;
            while ((ADCSRA & (1<<ADIF))==0);

        }

    return ES_OK;
}


Error_State ADC_enuSetCallBackFun(void (*Copy_funptr)(void*),void *Copy_vptrParameter){

    if(Copy_funptr == NULL){

        local_funptrIntTriggered = Copy_funptr;
        Copy_vptrParameter = local_vfunParameterptr;
    }
    return ES_OK;

}


Error_State ADC_enuEnableInterrupt(){
    
    ADCSRA |= (ADC_ENABLE<<ADIE);

    return ES_OK;
}

Error_State ADC_enuDisableInterrupt(){
    ADCSRA &= ~(ADC_ENABLE<<ADIE);

    return ES_OK;
}


void __vector_16 (void) __attribute__((signal));
void __vector_16(void){

    if(local_funptrIntTriggered != NULL){
        local_funptrIntTriggered(local_vfunParameterptr);
    }
    
}



Error_State ADC_enuEnable(void)

{
    ADCSRA |= (ADC_ENABLE<<ADEN);
    return ES_OK;
}


Error_State ADC_enuDisable(void)

{
    ADCSRA &=~(ADC_ENABLE<<ADEN);
    return ES_OK;
}


Error_State ADC_enuChangeChannel(u8 Copy_u8NewChannel)
{
    if (Copy_u8NewChannel > ADC_CHANNEL_7)
    {
        return ES_NOK;
    }
    
    /*Changing ADC input Channel*/
    ADMUX |= Copy_u8NewChannel;  

    return ES_OK;
}