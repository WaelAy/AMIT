#ifndef _btn_
#define _btn_

#include "../../std.h"

#define PULL_UP 0
#define PULL_DOWN 1


#define BUTTON_1_PIN    STD_PIN0
#define BUTTON_2_PIN    STD_PIN2
#define BUTTON_3_PIN    STD_PIN6

#define BUTTON_1_PORT STD_PORTB
#define BUTTON_2_PORT STD_PORTD
#define BUTTON_3_PORT STD_PORTD

/*function to instialize the button's pin and port*/
void button_init(u8 port,u8 pin,u8 config);
/*Function to check if the button is pressed or not*/
u8 button_read(u8 port,u8 pin);









#endif