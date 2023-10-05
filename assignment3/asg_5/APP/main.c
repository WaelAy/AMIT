#include "util/delay.h"
#include "../HAL/lcd/lcd.lib.h"
#include "../MCAL/adc/adc.lib.h"




int main(){
    LCD_Init();
    ADC_enuADCinit(ADC_CHANNEL_0);
    u16 val;
    LCD_Display("mv = ");
    while (1)
    {
        ADC_Read(&val);
        LCD_Set_Position(1,5);
        LCD_Displayint(val);
        _delay_ms(250);
        
    }
    



    return 0;
}

