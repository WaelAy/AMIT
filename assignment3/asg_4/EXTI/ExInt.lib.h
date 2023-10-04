#ifndef _EXTI_LIB_
#define _EXTI_LIB_
#include "../std.h"


#define EXTI_NUMBER                 3

#define EXTI_INT0                   0
#define EXTI_INT1                   1
#define EXTI_INT2                   2   

#define EXTI_LOW_LEVEL              0
#define EXTI_ANY_CHANGE             1
#define EXTI_FALLING                2
#define EXTI_RISING                 3

#define EXTI_INTERRUPT_MODE         1
#define EXTI_POLLING_MODE           2

Error_State EXTI_Init(void);

Error_State EXTI_Config(u8 EXTI_Pin,u8 config);


Error_State EXTI_EnableInterrupt(u8 EXTI_Pin);

Error_State EXTI_enuSetCallBackFun(u8 EXTI_Pin  ,void (*Copy_funptrCallbackfun)(void*) ,void *Copy_funptrCallbackParameter);

#endif