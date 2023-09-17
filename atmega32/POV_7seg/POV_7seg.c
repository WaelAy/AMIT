#include <util/delay.h>
#include "../dio/dio.h"


#include "POV_7seg.h"


void POV_setup(_7seg_config conf){
    _7seg_setup(conf);
    for (u8 i = 0; i <= _POV_NUMBER_OF_DEVICES-1; i++)
    {
        dio_init(POV_astrEnablePins[i].port,POV_astrEnablePins[i].pin,OUTPUT);
    }
    
}
void POV_Display(_7seg_config conf,u8 number){
    for (u8 i = 0; i <= _POV_NUMBER_OF_DEVICES-1; i++)
    {
        dio_write(POV_astrEnablePins[i].port,POV_astrEnablePins[i].pin,HIGH);
        _7seg_Display(conf,number%10);
        _delay_ms(10);
        number /=10;
        dio_write(POV_astrEnablePins[i].port,POV_astrEnablePins[i].pin,LOW);
        
    }
    
}