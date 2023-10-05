#include "../MCAL/dio/dio.h"
#include <util/delay.h>


int main(){
    dio_init(STD_PORTA,STD_PIN0,OUTPUT);
    while(1){

        dio_write(STD_PORTA,STD_PIN0,HIGH);
        _delay_ms(800);
        dio_write(STD_PORTA,STD_PIN0,LOW);
        _delay_ms(800);
    }

    return 0;
}