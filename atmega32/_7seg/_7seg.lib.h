#ifndef _7seg_
#define _7seg_
#include "../std.h"

/*Set this to one if you have a BCD*/
#define _4bitDecoder 0

/*Set this to one if you are using a common cathode*/
/*if this bit is set to zero you it will be common anode*/
#define commonCathode 1

/*if all pins lie on the same port*/
#define UNI_PORT 1



/*The following struct is set to configure 7segs if 4bit is set*/
/*The first 4bits only are recognized rest 4bits will be ignored*/
/*if the uni_port mode is set, port1 will be the only port read */
typedef struct {
    bool _4bit_mode;
    bool uni_port;
    u8 pins[7];
    char ports[7];

} _7seg_config;

    




void _7seg_setup(_7seg_config config);



void _7seg_Display(_7seg_config config,u8 number);



#endif