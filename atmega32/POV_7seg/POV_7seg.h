#ifndef _POV_
#define _POV_



#include "../std.h"

#include "../_7seg/_7seg.lib.h"


/*  number seven segements connected to the same pins */
#define _POV_NUMBER_OF_DEVICES 2
/******************************************************/


typedef struct {
    char port;
    u8 pin;
} POV_EN_Config;



/********Enable pins in the following format***********/
        /***in the following format***/
            /***{STD_port,STD_pin}***/
 static const POV_EN_Config POV_astrEnablePins[_POV_NUMBER_OF_DEVICES] = {
    {STD_PORTB,STD_PIN1},
    {STD_PORTB,STD_PIN2}
};

void POV_setup(_7seg_config conf);
/*pass here the number that you want to print and the configuration of the pins*/
void POV_Display(_7seg_config conf,u8 number);



#endif