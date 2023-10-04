#include "keypad/keypad.lib.h"
#include "lcd/lcd.lib.h"
#include <string.h>

int main(){

    Keypad_init();
    LCD_Init();

    u8 key1 = KEYPAD_NOT_PRESSED,key2 =KEYPAD_NOT_PRESSED,op=KEYPAD_NOT_PRESSED;
    while (1)
    {
         key1 = KEYPAD_NOT_PRESSED,key2 =KEYPAD_NOT_PRESSED,op=KEYPAD_NOT_PRESSED;
        while(key1 == KEYPAD_NOT_PRESSED){
            Keypad_readKey(&key1);
        };
        LCD_char(key1);
        while(op == KEYPAD_NOT_PRESSED){
            Keypad_readKey(&op);
        };
        LCD_char(op);
        while(key2 == KEYPAD_NOT_PRESSED){
            Keypad_readKey(&key2);
        };
        LCD_char(key2);
        LCD_hide_cursor();
        LCD_Set_Position(2,1);
        key1 -= 48;
      
        key2 -= 48;
        switch (op)
        {
        case '+':
            LCD_Displayint(key1+key2);
            break;
        case '-':
            LCD_Displayint(key1-key2);
            break;
        case 'x':
            LCD_Displayint(key1*key2);
            break;
        case '/':
            LCD_Displayint(key1/key2);
        default:
            break;
        }
        


        key1 = KEYPAD_NOT_PRESSED;


        while (key1==KEYPAD_NOT_PRESSED)
        {
            Keypad_readKey(&key1);
        }
        
        LCD_Clear();

    }
    


    return 0;
}