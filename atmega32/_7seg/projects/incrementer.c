#define F_CPU 16000000UL
#include "std.h"
#include <util/delay.h>
#include "button/button.h"
#include "dio/dio.h"
#include "POV_7seg/POV_7seg.h"
#include <avr/io.h>

int main(){
   _7seg_config CONF;
    CONF.uni_port = true;
    CONF._4bit_mode = true;
    CONF.ports[0] = STD_PORTA; 
    CONF.pins[0] = 4;
    CONF.pins[1] = 5;
    CONF.pins[2] = 6;
    CONF.pins[3] = 7;
    POV_setup(CONF);
    button_init(BUTTON_1_PORT,BUTTON_1_PORT,PULL_DOWN);
    u8 num = 0;
    bool clicked = false;
    while (1)
    {
        POV_Display(CONF,num);
        if(button_read(BUTTON_1_PORT,BUTTON_1_PIN) && !clicked){
            num++;
            clicked = 1;
        }
        else if(button_read(BUTTON_1_PORT,BUTTON_1_PIN) && clicked){

        }
        else if(!button_read(BUTTON_1_PORT,BUTTON_1_PIN) && clicked){
            clicked = 0;   
        }

           
         
        
	    
    }


    return 0;
}