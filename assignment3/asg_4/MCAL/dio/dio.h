#ifndef _dio_
#define _dio_
#include "../../std.h"

//defining pin direction.
#define INPUT 0
#define OUTPUT 1
/********************************************/
#define HIGH 1
#define LOW 0
/********************************************/
#define PA 'A'
#define PB 'B'
#define PC 'C'
#define PD 'D'

typedef enum DIO {DIO_OK,DIO_ERROR} dio_state;
/* defining our functions prototypes. */

dio_state dio_init(u8 portNum,u8 pinNum, u8 direction); // function to initialize DIO pin.
dio_state dio_write(u8 portNum,u8 pinNum,u8 value); // function to set the pin's value.
dio_state dio_read(u8 portNum,u8 pinNum, u8 *value); // function to read the pin's value.
#endif