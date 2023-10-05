#include"dio.h"
#include"dio.registers.h"
//functions bodies.

// function to initialize DIO pin.
dio_state dio_init(u8 portNum,u8 pinNum, u8 direction) 
{

	if (pinNum > 7 || pinNum < 0)
		return DIO_ERROR;

	if (direction < 0 || direction>2)
		return DIO_ERROR;

// if pin direction was input we clear pin.
// if it was output we set bit to one.
	switch (portNum){
		case PA:
			if (direction == INPUT)
				DDRA &= ~(1<<pinNum);

			else if (direction == OUTPUT)
				DDRA |= (1<<pinNum);	
			break;

		case PB:
			if(direction == INPUT)
				DDRB &= ~(1<<pinNum);

			else if (direction == OUTPUT)
				DDRB |= (1<<pinNum);
				
			break;
		case PC:
			if(direction == INPUT)
				DDRC &= ~(1<<pinNum);

			else if (direction == OUTPUT)
				DDRC |= (1<<pinNum);
				
			break;

		case PD:
			if(direction == INPUT)
				DDRD &= ~(1<<pinNum);

			else if (direction == OUTPUT)
				DDRD |= (1<<pinNum);
				
			break;

		default:
			return DIO_ERROR;
			break;
			
	}
	return DIO_OK;
}

// function to set the pin's value.
dio_state dio_write(u8 portNum,u8 pinNum,u8 value) 
{
	if (pinNum > 7 || pinNum < 0)
		return DIO_ERROR;

	if (value < 0 || value>1)
		return DIO_ERROR;

		switch (portNum){
			case PA:
				if (value == LOW)
					PORTA &= ~(1<<pinNum);
					
				else if(value==HIGH)
					PORTA |= (1<<pinNum); 
					
				break;	
				
			case PB:
				if (value == LOW)
					PORTB &= ~(1<<pinNum);
					
				else if(value==HIGH)
					PORTB |= (1<<pinNum);
					
				break;
			case PC:
				if (value == LOW)
					PORTC &= ~(1<<pinNum);
				
				else if(value==HIGH)
					PORTC |= (1<<pinNum);
				break;
			case PD:
				if (value == LOW)
					PORTD &= ~(1<<pinNum);
					
				else if(value==HIGH)
					PORTD |= (1<<pinNum);
				
				break;
				
			default:
			return DIO_ERROR;
				break;	
		}
		return DIO_OK;
}

// function to read the pin's value.
dio_state dio_read(u8 portNum,u8 pinNum,u8 *value) 
{
	if (pinNum > 7 || pinNum < 0)
		return DIO_ERROR;


	switch(portNum){
		case PA:
			*value = (PINA &(1<<pinNum))>>pinNum;
			*value = ((PINA >> pinNum) & 1);
			return DIO_OK;
		case PB:
			*value = (PINB &(1<<pinNum))>>pinNum;
			return DIO_OK;
        case PC:
            *value = (PINC &(1<<pinNum))>>pinNum;
			return DIO_OK;
		case PD:
			*value = (PIND &(1<<pinNum))>>pinNum;
			*value = ((PIND >> pinNum) & 1);
			return DIO_OK;
		default:
			return DIO_ERROR;
			break;			
		
	}
	return DIO_ERROR;
	
}

