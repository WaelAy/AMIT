#ifndef DIO_H_
#define DIO_H_

// defining the used registers.
// Defining port A registers.
#define PORTA *((volatile u8*) 0x3B)  // 8 bit register.
#define DDRA *((volatile u8*) 0x3A)   // 8 bit register.
#define PINA *((volatile u8*) 0x39)	  // 8 bit register.
/*##############################################################*/
// Defining port B registers.
#define PORTB *((volatile u8*) 0x38)   // 8 bit register.
#define DDRB *((volatile u8*) 0x37)   // 8 bit register.
#define PINB *((volatile u8*) 0x36)   // 8 bit register.
/*##############################################################*/
#define PORTC *((volatile u8*) 0x35)  // 8 bit register.
#define DDRC *((volatile u8*) 0x34)   // 8 bit register.
#define PINC *((volatile u8*) 0x33)   // 8 bit register.
/*##############################################################*/
// Defining port D registers.
#define PORTD *((volatile u8*) 0x32)  // 8 bit register.
#define DDRD *((volatile u8*) 0x31)   // 8 bit register.
#define PIND *((volatile u8*) 0x30)   // 8 bit register.

#endif