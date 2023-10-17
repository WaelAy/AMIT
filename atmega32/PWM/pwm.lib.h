#ifndef _PWM_LIB_
#define _PWM_LIB_

#include "../std.h"


Error_State PWM_enuInit();
Error_State PWM_enuEnable(u8 copy_u8DutyCycle);
Error_State PWM_enuDisable(u8 copy_u8DutyCycle);


#endif