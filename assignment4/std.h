#ifndef _std_
#define _std_


#define NULL 0
#define BIT_MASK 1
/***********************************************/
/***************ATmega32 ports******************/
/**********************************************/
#define STD_PORTA 'A'
#define STD_PORTB 'B'
#define STD_PORTC 'C'
#define STD_PORTD 'D'

/***********************************************/
/***************ATmega32 pins******************/
/**********************************************/

#define STD_PIN0 0
#define STD_PIN1 1
#define STD_PIN2 2
#define STD_PIN3 3
#define STD_PIN4 4
#define STD_PIN5 5
#define STD_PIN6 6
#define STD_PIN7 7



/***********************************************/
/***************Standard types******************/
/**********************************************/
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

typedef signed char s8;
typedef signed short s16;
typedef signed long s32;


/***********************************************/
/*******************Enums**********************/
/**********************************************/

typedef enum {
    ES_OK,
    ES_NOK
} Error_State;


typedef enum {
    false,
    true
} bool;


#endif