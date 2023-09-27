#include <util/delay.h>
#include <string.h>

#include "../dio/dio.h"
#include "../adc/adc.lib.h"
#include "../GIE/GIE.h"

#include "../lcd/lcd.lib.h"
#include "../keypad/keypad.lib.h"
#include "../LM45/lm45.h"


#include "app.h"

#define APP_MAIN_MENU_       0
#define APP_LED_             1
#define APP_TEMPERATURE_     2
#define APP_MOTOR_           3



static char *safe_password = "123/Cx";
static u8 state = 0;

static Error_State APP_TEMP();
static Error_State APP_MOTOR();
static Error_State APP_LED();
static Error_State APP_main_menu();
static Error_State APP_Welcome();
static Error_State APP_Auth();

Error_State APP_INIT(){
    LCD_Init();
    Keypad_init();
    GIE_vidEnable();
    ADC_enuADCinit(ADC_CHANNEL_0);
    ADC_enuAutoTriggerEnable(ADC_FREE_RUNNING_MODE);
    ADC_enuEnableInterrupt();
    dio_init(PA,STD_PIN3,OUTPUT);
    dio_init(PC,STD_PIN3,OUTPUT);
    dio_init(PA,STD_PIN2,OUTPUT);
    return ES_OK;
}




Error_State APP_LOGIC(){
    APP_Welcome();
    APP_Auth();
    
    while (1)
    {
        if (state){
            if(state == APP_LED_){
                APP_LED();
            }
            else if(state == APP_TEMPERATURE_){
                APP_TEMP();
            }
            else if(state == APP_MOTOR_){
                APP_MOTOR();
            }
        }else
            APP_main_menu();
    }
    
    

    return ES_OK;
}

static Error_State APP_TEMP(){
    

    u16 local_u16temp;
    LCD_Clear();
    LCD_Display("Temp= ");
    LCD_Set_Position(1,9);
    LCD_Display("C");
    LCD_Set_Position(2,1);
    LCD_Display("1-Back");
    u8 key = KEYPAD_NOT_PRESSED;
    while (key == KEYPAD_NOT_PRESSED){
        Keypad_readKey(&key);
        LCD_Set_Position(1,7);
        LM45_read(&local_u16temp);
        LCD_Displayint(local_u16temp);
        _delay_ms(300);
    }
    
    if (key == '1')
    {
        return ES_OK;
    }
    

    if(key > '1'){
        LCD_Clear();
        LCD_Display("Error invalid");
        LCD_Set_Position(2,3);
        LCD_Display("key input!");
        _delay_ms(800);
        state = APP_TEMPERATURE_;
    } 

    return ES_OK;   
}


static Error_State APP_MOTOR(){
    LCD_Clear();
    LCD_Display("1-ON");
    LCD_Set_Position(1,10);
    LCD_Display("2-OFF");
    LCD_Set_Position(2,1);
    LCD_Display("3-Back");

    u8 key = KEYPAD_NOT_PRESSED;
    while (key == KEYPAD_NOT_PRESSED)
        Keypad_readKey(&key);

    if(key == '1'){
        dio_write(PA,STD_PIN2,HIGH);
        state = APP_MOTOR_;
        return ES_OK;
    }

    if(key == '2'){
        dio_write(PA,STD_PIN2,LOW);
        state = APP_MOTOR_;
        return ES_OK;
    }

    if(key == '3'){
        state = APP_MAIN_MENU_;
        return ES_OK;
    }

    if(key>'3'){
        LCD_Clear();
        LCD_Display("Error invalid");
        LCD_Set_Position(2,3);
        LCD_Display("key input!");
        _delay_ms(800);
        state = APP_MOTOR_;
        return ES_OK;
    }
    return ES_OK;
}


static Error_State APP_LED(){
    LCD_Clear();
    LCD_Display("1-ON");
    LCD_Set_Position(1,9);
    LCD_Display("2-OFF");
    LCD_Set_Position(2,1);
    LCD_Display("3-Back");

    u8 key = KEYPAD_NOT_PRESSED;
    while (key == KEYPAD_NOT_PRESSED)
        Keypad_readKey(&key);

    if(key == '1'){
        dio_write(PC,STD_PIN3,HIGH);
        state = APP_LED_;
        return ES_OK;
    }

    if(key == '2'){
        dio_write(PC,STD_PIN3,LOW);
        state = APP_LED_;
        return ES_OK;
    }

    if(key == '3'){
        state = APP_MAIN_MENU_;
        return ES_OK;
    }

    if(key>'3'){
        LCD_Clear();
        LCD_Display("Error invalid ");
        LCD_Set_Position(2,3);
        LCD_Display("key input!");
        _delay_ms(800);
        state = 1;
        return ES_OK;
    }

    return ES_OK;
}

static Error_State APP_main_menu(){
    LCD_Clear();
    LCD_Display("1-LED");
    LCD_Set_Position(1,10);
    LCD_Display("2-Temp");
    LCD_Set_Position(2,1);
    LCD_Display("3-Motor");
    LCD_hide_cursor();
    u8 key = KEYPAD_NOT_PRESSED;
    while (key == KEYPAD_NOT_PRESSED)
        Keypad_readKey(&key);
    
    if(key == '1'){
        APP_LED();
        return ES_OK;
    }

    if(key == '2'){
        APP_TEMP();
        return ES_OK;
    }

    if(key == '3'){
        APP_MOTOR();
        return ES_OK;
    }

    if(key>'3'){
        LCD_Clear();
        LCD_Display("Error invalid ");
        LCD_Set_Position(2,3);
        LCD_Display("key input!");
        state = APP_MAIN_MENU_;
        return ES_OK;
    }

    return ES_OK;

}

static Error_State APP_Auth(){
    LCD_Clear();
    LCD_Set_Position(1,2);
    LCD_Display("Password:");
    LCD_Set_Position(2,1);
    LCD_show_cursor();
    u8 key = KEYPAD_NOT_PRESSED;
    
    char given_password[16];
    u8 iter;

    for (iter = 0; iter < 16; iter++)
    {
        while(key == KEYPAD_NOT_PRESSED)
            Keypad_readKey(&key);

        if (key == '=')
        {
            break;
        }
        
        LCD_Display("*");
        given_password[iter] = key;
        key = KEYPAD_NOT_PRESSED;
        

    }

    given_password[iter] = '\0';

   if(strcmp(given_password,safe_password)){
        static u8 number_of_entries = 0;
        if(number_of_entries > 2){
            LCD_Clear();
            LCD_Display("7aramy"); 
            LCD_hide_cursor();
            while (1)
            {
                dio_write(STD_PORTA,STD_PIN3,HIGH);
                _delay_ms(500);
                dio_write(STD_PORTA,STD_PIN3,LOW);
                _delay_ms(500);
            }
            return ES_NOK;
        }
        else{
            LCD_Clear();
            LCD_Display("WRONG PASSWORD");
            LCD_hide_cursor();
            _delay_ms(2000);
            number_of_entries++;
            APP_Auth();
        }
    };
    LCD_Clear();
    LCD_Display("Correct password!");
    _delay_ms(2000);
    return ES_OK;
}


static Error_State APP_Welcome(){
    LCD_Set_Position(1,5);
    LCD_Display("Welcome");
    LCD_Set_Position(2,4);
    LCD_Display("Loading");
    LCD_hide_cursor();
    _delay_ms(1000);
    return ES_OK;
}