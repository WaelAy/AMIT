#include "timer.config.h"
#include "timer.priv.h"
#include "timer.lib.h"


void (*Local_vfunPtrOFC0)(void *Local_vfParam) = NULL;


void *Local_vptrParamOFC0 = NULL;


Error_State Timer_init(){




    return ES_OK;
}
Error_State Timer_delay_ms(u16 copy_u16NumberOfms){

    TCCR0 = 0x00;
    
    TCCR0 |= (BIT_MASK<<CS00);
    TCCR0 |= (BIT_MASK<<CS01);
    TCNT0 = 6;
    
    
        
      while (copy_u16NumberOfms > 0)
      {
        
            while(((BIT_MASK << TOV0) & TIFR) == 0);
            TIFR |= (BIT_MASK<<TOV0); //clearing the ocr0 flag.
            
           TCNT0 = 6;
        

        copy_u16NumberOfms--;
      }
        


    

    TCCR0 = 0x00;

    return ES_OK;

}
Error_State Timer_delay_us(u16 copy_u16NumberOfus){

    TCCR0 = 0x00;
    
    TCCR0 |= (BIT_MASK<<CS00);
    //TCCR0 |= (BIT_MASK<<CS01);
    TCNT0 = 240;
    
   if(copy_u16NumberOfus > 64){
        u16 local_u16NumberOfPasseduSecs = copy_u16NumberOfus ,local_u16DivFac = 16;
        if(copy_u16NumberOfus > 32 && copy_u16NumberOfus < 64)
            local_u16DivFac/=2;
        else if(copy_u16NumberOfus > 64)
            local_u16DivFac/=4;
        local_u16NumberOfPasseduSecs /= local_u16DivFac;
        copy_u16NumberOfus -= local_u16NumberOfPasseduSecs;
    }
        
   while (copy_u16NumberOfus > 0)
      {
        
        while(((BIT_MASK << TOV0) & TIFR) == 0);
        TIFR |= (BIT_MASK<<TOV0); //clearing the ocr0 flag.
            
        TCNT0 = 240;
        

        copy_u16NumberOfus--;
      }
    


    

    TCCR0 = 0x00;

    return ES_OK;


}


Error_State Timer_setcallbackfun(void (*copy_vfunptrISR)(void*),void *vptr_parameter){

    if(copy_vfunptrISR == NULL)
        return ES_NOK;

    Local_vfunPtrOFC0 = copy_vfunptrISR;
    Local_vptrParamOFC0 = vptr_parameter;

    return ES_OK;
}
void __vector_6 (void)__attribute__((signal));
void __vector_6(){
    if(Local_vfunPtrOFC0 != NULL){
        Local_vfunPtrOFC0(Local_vptrParamOFC0);
    }
}