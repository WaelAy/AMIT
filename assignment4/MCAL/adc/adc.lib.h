#ifndef _ADC_LIB_
#define _ADC_LIB_

#include "../../std.h"


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



#define ADC_FREE_RUNNING_MODE   0
#define ADC_ANALOG_COMPARTOR    1
#define ADC_EXTI_1              2
#define ADC_T0_COMPARE_MATCH    3
#define ADC_T0_OVERFLOW         4
#define ADC_T1_COMPARE_MATCH_B  5
#define ADC_T1_OVERFLOW         6
#define ADC_T1_CAPTURE_EVENT    7



Error_State ADC_enuADCinit(u8 Copy_u8channel);

Error_State ADC_Read(u16 *Copy_u16Value);

Error_State ADC_enuAutoTriggerEnable(u8 Copy_u8AutoTriggerSource);

Error_State ADC_enuSetCallBackFun(void (*Copy_funptr)(void*),void *Copy_vptrParameter);

Error_State ADC_enuEnableInterrupt(void);

Error_State ADC_enuDisableInterrupt(void);

Error_State ADC_enuEnable(void);

Error_State ADC_enuDisable(void);

Error_State ADC_enuChangeChannel(u8 Copy_u8NewChannel);

#endif