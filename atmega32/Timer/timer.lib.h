#ifndef _TIMER_LIB_H_
#define _TIMER_LIB_H_

#include "../std.h"

Error_State Timer_init();
Error_State Timer_delay_ms(u16 copy_u16NumberOfms);
Error_State Timer_delay_us(u16 copy_u16NumberOfus);
Error_State Timer_setcallbackfun(void (*copy_vfunptrISR)(void*),void *vptr_parameter);






#endif