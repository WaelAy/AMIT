#define F_CPU 16000000UL
#include "std.h"
#include <util/delay.h>
#include "button/button.h"
#include "dio/dio.h"
#include "POV_7seg/POV_7seg.h"
#include "lcd/lcd.lib.h"
#include <avr/io.h>
#include "keypad/keypad.lib.h"


int main(){
    LCD_Init();
    Keypad_init();
    u8 key_val;
    /*main logic*/
    while (1)
    {
        
        Keypad_readKey(&key_val);
        if(key_val != KEYPAD_NOT_PRESSED){
            LCD_char(key_val);
            key_val = KEYPAD_NOT_PRESSED;
        }

	    
        
    }


    return 0;
}
