#include "../MCAL/dio/dio.h"
#include "../HAL/lcd/lcd.lib.h"
#include "../HAL/button/button.h"

int main(){

    LCD_Init();
    button_init(STD_PORTC,2,PULL_UP);
    button_init(STD_PORTC,3,PULL_UP);
    u8 Number = 0,key_pressed = false;
    LCD_Display("Number = ");
    LCD_Set_Position(1,8);
    LCD_Displayint(Number);
    LCD_hide_cursor();
    while(1){
        
        if(button_read(STD_PORTC,2) && Number < 9 && key_pressed == false){
            Number++;
            LCD_Set_Position(1,8);
            LCD_Displayint(Number);
            key_pressed = true;

        }
        if(button_read(STD_PORTC,2) && Number < 9 && key_pressed == true){




        }
        if(button_read(STD_PORTC,3) && Number > 0 && key_pressed == false){

            Number--;
            LCD_Set_Position(1,8);
            LCD_Displayint(Number);
            key_pressed = true;


        }
        if(button_read(STD_PORTC,3) && Number > 0 && key_pressed == false){

            


        }
        if(!button_read(STD_PORTC,3) && !button_read(STD_PORTC,2)  && key_pressed == true){

            key_pressed = false;


        }

    }



    return 0;
}