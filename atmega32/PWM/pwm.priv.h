#ifndef _PWM_PRIV_
#define _PWM_PRIV_

#include "../std.h"


#define TCCR2 *((volatile u8*) 0x45)
#define TCNT2 *((volatile u8*) 0x44)
#define OCR2  *((volatile u8*) 0x43)

#define WGM20 6
#define WGM21 3
#define COM21 5
#define COM20 4


#endif