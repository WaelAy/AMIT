#ifndef _adc_conf_
#define _adc_conf_



#define ADC_VOLTAGE_REF ADC_VOLTAGE_AREF

#define ADC_PRESCALER ADC_PRESCALER_64

#define ADC_ADJUST_LEFT ADC_ENABLE

#define ADC_MODE ADC_SINGLE_CONVERSION_MODE  

/* If single converstion mode is active this bit won't have any effect */
#define ADC_AUTO_TRIGGER_SOURCE 0



#endif