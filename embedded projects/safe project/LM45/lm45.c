#include "lm45.h"
#include "../adc/adc.lib.h"


Error_State LM45_read(u16 *Copy_u16Temp){

    u16 local_u16temp;
    ADC_Read(&local_u16temp);
    float local_fCelusius = (float)local_u16temp * (float)((float)5/(float)1021);
    local_fCelusius /= 0.01;

    
    *Copy_u16Temp = (u16)(local_fCelusius); 
    //
    



    return ES_OK;
}