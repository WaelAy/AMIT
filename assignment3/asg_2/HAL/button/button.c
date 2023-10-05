#include "button.h"
#include "../../MCAL/dio/dio.h"

void button_init(u8 port,u8 pin,u8 config){
    dio_init(port, pin , config);
}

u8 button_read(u8 port,u8 pin){
    u8 value;
    dio_read(port,pin,&value);
    return value;
}