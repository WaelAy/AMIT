#include "../../std.h"
#include "ExInt.config.h"
#include "ExInt.lib.h"

u8 EXTIPinNum = EXTI_NUMBER;

EXTI_t EXTI_ConfigArr [ EXTI_NUMBER ]=
    {
        {EXTI_INT0 , EXTI_RISING , EXTI_INTERRUPT_MODE},
        {EXTI_INT2 , EXTI_RISING ,  EXTI_INTERRUPT_MODE},
        {EXTI_INT1 , EXTI_RISING ,  EXTI_POLLING_MODE},
    };