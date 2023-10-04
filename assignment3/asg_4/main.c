#include "dio/dio.h"
#include "GIE/GIE.h"
#include "EXTI/ExInt.lib.h"


static u8 led = 0;

void Led_on(){

       dio_write(STD_PORTA,led,HIGH);
       led++;
       if(led>2)
            led = 2;
    
    
    
    
}
void Led_OFF(){
       dio_write(STD_PORTA,led,LOW);
       led--;
       if(led<0)
            led = 0;
    
    
}

int main(){
    dio_init(STD_PORTA,STD_PIN0,OUTPUT);
    dio_init(STD_PORTA,STD_PIN1,OUTPUT);
    dio_init(STD_PORTA,STD_PIN2,OUTPUT);
    dio_init(STD_PORTD,STD_PIN2,INPUT);
    dio_init(STD_PORTD,STD_PIN3,INPUT);
    dio_write(STD_PORTD,STD_PIN2,INPUT);
    dio_write(STD_PORTD,STD_PIN3,INPUT);
    GIE_vidEnable();
    EXTI_EnableInterrupt(EXTI_INT0);
    EXTI_EnableInterrupt(EXTI_INT1);
    EXTI_enuSetCallBackFun(EXTI_INT0,Led_on,NULL);
    EXTI_enuSetCallBackFun(EXTI_INT1,Led_OFF,NULL);
    while (1)
    {

    }
    








    return 0;
}