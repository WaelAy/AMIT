#define F_CPU 16000000UL

//#include <avr/io.h>
#include "Timer/timer.lib.h"
#include "dio/dio.h"
#include "GIE/GIE.h"

int main(){

    Timer_init();
    dio_init(STD_PORTB,STD_PIN2,OUTPUT);

    while (1)
    {
        dio_toggle(STD_PORTB,STD_PIN2);
        Timer_delay_us(100UL);
    }
    

    // TCCR0 |= (1<<WGM00);
    // TCCR0 |= (1<<WGM01);
    // TCCR0 |= (1<<COM01);

    // //uint32_t F_PWM = 16000000 / (256UL);

    // uint8_t Duty_Cycle = 35;
    // OCR0 =  255 * Duty_Cycle / 100;
    // TCCR0 |= (1<<CS02);

    // DDRB |= (1<<3);
    // DDRB |= (1<<2);
    // while (1){
    //     PORTB ^= (1<<2);
    //     for(int32_t x = 0; x < 999999; x++);
    // };
    


    return 0;
}
