#include "pwm.config.h"
#include "pwm.priv.h"
#include "pwm.lib.h"






Error_State PWM_enuInit(){

    TCCR2 |= (BIT_MASK<<WGM20);
    


    return ES_OK;
}
Error_State PWM_enuEnable(u8 copy_u8DutyCycle){





    return ES_OK;
}
Error_State PWM_enuDisable(u8 copy_u8DutyCycle);