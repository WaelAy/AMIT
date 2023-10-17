#ifndef _Timer_PRIV_
#define _Timer_PRIV_

#include "../std.h"





#define TIMER_PRESC_OFF       0
#define TIMER_PRESC_0         1
#define TIMER_PRESC_8         8
#define TIMER_PRESC_64        64
#define TIMER_PRESC_256       256
#define TIMER_PRESC_1024      1024
#define TIMER_PRESC_EXT_T0_FE 6
#define TIMER_PRESC_EXT_T0_RE 7

#define TIMSK *((volatile u8*)0x59)
#define TIFR  *((volatile u8*)0x58)

#define OCR0    *((volatile u8*) 0x5C)
#define TCCR0   *((volatile u8*) 0x53)
#define TCNT0   *((volatile u8*) 0x52)
#define SFIOR   *((volatile u8*) 0x50)

#define TCCR1A  *((volatile u8*) 0x4F)
#define TCCR1B  *((volatile u8*) 0x4E)
#define TCNT1H  *((volatile u8*) 0x4D)
#define TCNT1L  *((volatile u8*) 0x4C)
#define OCR1AH  *((volatile u8*) 0x4B)
#define OCR1AL  *((volatile u8*) 0x4A)
#define OCR1BH  *((volatile u8*) 0x49)
#define OCR1BL  *((volatile u8*) 0x48)
#define ICR1H   *((volatile u8*) 0x47)
#define ICR1L   *((volatile u8*) 0x46)



#define TCCR2   *((volatile u8*) 0x45)
#define TCNT2   *((volatile u8*) 0x45)



#define WGM00 6
#define WGM01 3 
#define COM00 4
#define COM01 5
#define CS00 0
#define CS01 1

#define WGM20 6
#define COM21 5
#define COM20 4


/*TCCRB*/
#define WGM13 4
#define WGM12 3
/*TCCRA*/
#define WGM11 1
#define WGM10 0
#define COM1A1 7
#define COM1A0 6

#define TOV0 0


#define TIMER_DISABLED   0
#define TIMER_DELAY_MODE 1
#define TIMER_PWM_MODE   2



#define TIMER_CPU_CLK      0
#define TIMER_EXTERNAL_CLK 1









#define TIMER_OC_DISABLED   0 
#define TIMER_OC_SET        1
#define TIMER_OC_TOGGLE     2
#define TIMTER_OC_CLEAR     3
 


#endif