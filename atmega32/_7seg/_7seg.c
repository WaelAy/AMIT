#include <math.h>
#include <util/delay.h>
#include "../dio/dio.h"
#include "_7seg.lib.h"



static const int _7segmentNumbers8bit[11] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};



void _7seg_setup(_7seg_config config){
        if(config._4bit_mode){
        
            if(config.uni_port)
                for(int i = 0; i < 4; i++)
                    dio_init(config.ports[0],config.pins[i],OUTPUT);
            else
                for(int i = 0; i < 4; i++)
                    dio_init(config.ports[i],config.pins[i],OUTPUT);   
        }
        else
            if(config.uni_port)
                for(int i = 0; i < 7; i++)
                    dio_init(config.ports[0],i,OUTPUT);
            else
                for(int i = 0; i < 7; i++)
                    dio_init(config.ports[i],config.pins[i],OUTPUT);  
    }
    
                


void _7seg_clear(_7seg_config config){
    u8 count;
    if(config._4bit_mode)
        count = 4;
    else
        count = 7;


    if(config.uni_port)
        for(int i = 0; i<count; i++){
            dio_write(config.ports[0],config.pins[i],LOW);
        }
    else
        for(int i = 0; i<count; i++){
            dio_write(config.ports[i],config.pins[i],LOW);
        }

}

void _7seg_Display(_7seg_config config,u8 number){
        u8 count = 0;
        if(config._4bit_mode)
            count = 4;
        
        else
        {
            count = 7;
            number = _7segmentNumbers8bit[number];
        }
        _7seg_clear(config);
        if (config.uni_port){
            for (u8 i = 0; i < count; i++)
                {
                    bool bit = (number & (1<<i))>>i;
                    dio_write(config.ports[0],config.pins[i],bit);
                }
        }
        else{
        
            for (u8 i = 0; i < count; i++)
                {
                    bool bit = (number & (1<<i))>>i;
                    dio_write(config.ports[i],config.pins[i],bit);
                }
        }
}




