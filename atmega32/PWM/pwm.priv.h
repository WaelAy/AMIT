#ifndef _PWM_PRIV_
#define _PWM_PRIV_

#include "pwm.config.h"


#define PWM_CHANNEL_0 0x35
#define PWM_CHANNEL_1_A 36 
#define PWM_CHANNEL_1_B 53
#define PWM_CHANNEL_1_AB 35
#define PWM_CHANNEL_2 2

#define PWM_NON_INVERTING_MODE 65
#define PWM_INVERTING_MODE 39



#if (PWM_CHANNEL == PWM_CHANNEL_2)

    #define TCCR2 *((volatile u8*) 0x45)
    #define TCNT2 *((volatile u8*) 0x44)
    #define OCR2  *((volatile u8*) 0x43)

    #define WGM20 6
    #define WGM21 3
    #define COM21 5
    #define COM20 4

    #define CS22 2
    #define CS21 1
    #define CS20 0

#elif (PWM_CHANNEL == PWM_CHANNEL_0)

    #define OCR0    *((volatile u8*) 0x5C)
    #define TCCR0   *((volatile u8*) 0x53)
    #define TCNT0   *((volatile u8*) 0x52)
    #define SFIOR   *((volatile u8*) 0x50)
    #define WGM00 6
    #define WGM01 3 
    #define COM00 4
    #define COM01 5
    #define CS00 0
    #define CS01 1
    #define CS02  2
#elif (PWM_CHANNEL == PWM_CHANNEL_1)

    #define TCCR1A  *((volatile u8*) 0x4F)
    #define TCCR1B  *((volatile u8*) 0x4E)
    #define TCNT1H  *((volatile u8*) 0x4D)
    #define TCNT1L  *((volatile u8*) 0x4C)
    #define OCR1A   *((volatile u16*) 0x4A)
    #define OCR1AH  *((volatile u8*) 0x4B)
    #define OCR1AL  *((volatile u8*) 0x4A)
    #define OCR1B   *((volatile u16*) 0x48)
    #define OCR1BH  *((volatile u8*) 0x49)
    #define OCR1BL  *((volatile u8*) 0x48)
    #define ICR1H   *((volatile u8*) 0x47)
    #define ICR1L   *((volatile u8*) 0x46)

    /*TCCRB*/
    #define WGM13 4
    #define WGM12 3
    /*TCCRA*/
    #define WGM11 1
    #define WGM10 0
    #define COM1A1 7
    #define COM1A0 6
    
    /*PWM MODES*/

    #define PWM_PHASE_CORRECT_8_BIT 1
    #define PWM_PHASE_CORRECT_9_BIT 2
    #define PWM_PHASE_CORRECT_10_BIT 3

    #define PWM_FAST_PWM_8_BIT 5
    #define PWM_FAST_PWM_9_BIT 6
    #define PWM_FAST_PWM_10_BIT 7

    
    #define  COM1A1 0
    #define  COM1A0 1
    #define  COM1B1 2
    #define  COM1B0 3
    #define  FOC1A  4
    #define  FOC1B 5
    #define  WGM11 6
    #define  WGM10 7
    #define CS12 2
    #define CS11 1
    #define CS10 0

#else 
    #error Invalid PWM CHANNEL 
#endif

#define PWM_PHASE_CORRECT_MODE 0X36 
#define PWM_FAST_PWM_MODE 0X56 

#define PWM_PRESC_OFF       0
#define PWM_PRESC_1         1
#define PWM_PRESC_8         8
#define PWM_PRESC_64        64
#define PWM_PRESC_256       256
#define PWM_PRESC_1024      1024
#define PWM_PRESC_EXT_FE 6
#define PWM_PRESC_EXT_RE 7


#define PWM_CPU_CLK      0
#define PWM_EXTERNAL_CLK 1


#endif