#ifndef _ADC_LIB_
#define _ADC_LIB_

#include "../std.h"


#define ADC_CHANNEL_0 0
#define ADC_CHANNEL_1 1
#define ADC_CHANNEL_2 2
#define ADC_CHANNEL_3 3
#define ADC_CHANNEL_4 4
#define ADC_CHANNEL_5 5
#define ADC_CHANNEL_6 6
#define ADC_CHANNEL_7 7


#define ADC_AUTO_TRIGGER_MODE           1
#define ADC_SINGLE_CONVERSION_MODE      0




Error_State ADC_enuADCinit(u8 Copy_u8channel,u8 Copy_u8Mode);

Error_State ADC_Read(u16 *Copy_u16Value);



#endif