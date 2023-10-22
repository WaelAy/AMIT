#ifndef _PWM_LIB_
#define _PWM_LIB_

#include "../../std.h"

#define PWM_OFF 0x55
#define PWM_DISABLE 0x23



Error_State PWM_enuInit();
#if (PWM_CHANNEL != PWM_CHANNEL_1_AB)
    Error_State PWM_enuEnable(u8 copy_u8DutyCycle);
    Error_State PWM_enuDisable();
    #if (PWM_CHANNEL == PWM_CHANNEL_0)
        #define PWM_DISABLE_CHANNEL_0 0x65
    #elif (PWM_CHANNEL == PWM_CHANNEL_2)
        #define PWM_DISABLE_CHANNEL_2 0x62
    #endif
#else
    Error_State PWM_enuEnable(u8 copy_u8DutyCycleA,u8 copy_u8DutyCycleB);

    Error_State PWM_enuDisable(u8 copy_u8A_B);
    #define PWM_DISABLE_A 0x23
    #define PWM_DISABLE_AB 0x54
    #define PWM_DISABLE_B 0x66 
#endif





#endif