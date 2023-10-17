#ifndef _TIMER_PRIV_H_
#define _TIMER_PRIV_H_


#define F_CPU 16000000UL
#define TIMSK *((volatile u8*)0x59)
#define TIFR  *((volatile u8*)0x58)

#define OCR0    *((volatile u8*) 0x5C)
#define TCCR0   *((volatile u8*) 0x53)
#define TCNT0   *((volatile u8*) 0x52)
#define SFIOR   *((volatile u8*) 0x50)



#define TOV0 0
#define OCF0 1

#define WGM00 6
#define WGM01 3 
#define COM00 4
#define COM01 5

#define CS00 0
#define CS01 1
#define CS02 2
#endif