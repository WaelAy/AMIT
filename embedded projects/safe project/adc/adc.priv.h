#ifndef _adc_priv_
#define _adc_priv_

#define ADMUX   *((volatile u8*) 0x27)
#define ADCSRA  *((volatile u8*) 0x26)
#define ADCH    *((volatile u8*) 0x25)
#define ADCL    *((volatile u8*) 0x24)
#define SFIOR   *((volatile u8*) 0x50)


/*ADMUX register bit names*/
#define ADLAR 5
#define REFS0 6
#define REFS1 7

/*ADCSRA register bit names*/
#define ADPS0   0
#define ADPS1   1
#define ADPS2   2
#define ADIE    3
#define ADIF    4
#define ADATE   5
#define ADSC    6
#define ADEN    7


/*SFIOR register bit names*/
#define ADTS0 5
#define ADTS1 6
#define ADTS2 7


#define ADC_NUMBER_OF_CHANNELS  7
#define ADC_PORT_NUMBER 'A'


#define ADC_VOLTAGE_AREF        0
#define ADC_VOLTAGE_AVCC        1
#define ADC_VOLTAGE_INTERNAL    3



#define ADC_PRESCALER_2     0
#define ADC_PRESCALER_4     2
#define ADC_PRESCALER_8     3
#define ADC_PRESCALER_16    4
#define ADC_PRESCALER_32    5
#define ADC_PRESCALER_64    6
#define ADC_PRESCALER_128   7





#define ADC_ENABLE 1

#endif