#include "../MCAL/PWM/pwm.lib.h"
#include "../MCAL/dio/dio.h"
#include "../MCAL/adc/adc.lib.h"
#include "../MCAL/GIE/GIE.h"
#include <util/delay.h>

u16 LOC_u16DADCVal = 50;
bool flag = false;
void get_adc_val(){
    flag = true;
}


int main(){

    dio_init(STD_PORTD, 4, OUTPUT);
    dio_init(STD_PORTD, 5, OUTPUT);
    dio_init(STD_PORTA,0,INPUT);
    dio_write(STD_PORTA,0,INPUT);
    dio_init(STD_PORTC,0,OUTPUT);
    PWM_enuInit();
    GIE_vidEnable();
    ADC_enuADCinit(ADC_CHANNEL_0);
   // ADC_enuAutoTriggerEnable(ADC_FREE_RUNNING_MODE);
   // ADC_enuSetCallBackFun(get_adc_val, NULL);
    PWM_enuEnable(50, 50);
    while(1){

        //PWM_enuEnable((LOC_u16DADCVal/1024)*100,(LOC_u16DADCVal/1024)*100);
        ADC_Read(&LOC_u16DADCVal);
        LOC_u16DADCVal = (LOC_u16DADCVal /10) > 100 ? 100:LOC_u16DADCVal/10;
        PWM_enuEnable(LOC_u16DADCVal,LOC_u16DADCVal);
        flag = false;
        
        dio_toggle(STD_PORTC, 0);
        _delay_ms(3);
    }

    return 0;
}