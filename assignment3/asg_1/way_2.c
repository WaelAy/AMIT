#include "dio/dio.h"
#include <util/delay.h>


int main(){
    dio_init(STD_PORTA,STD_PIN0,OUTPUT);
    while(1){

        dio_toggle(STD_PORTA,STD_PIN0);
        _delay_ms(800);
    }

    return 0;
}