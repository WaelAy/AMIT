#ifndef _EXTI_CONF_
#define __EXTI_CONF_


/*The Number of used EXTI pins in microcontroller*/
#define EXTI_NUMBER 3

typedef unsigned char u8;

typedef struct 
{
    u8 intPin;
    u8 senseLevel;
    u8 intMode;
}EXTI_t;




#endif 