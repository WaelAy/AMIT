
#include "pwm.priv.h"
#include "pwm.lib.h"
#include "pwm.config.h"


#if (PWM_CHANNEL == PWM_CHANNEL_1)
    static void Local_vTM1SetMode(bool copy_WGM10,bool copy_WGM11,bool copy_WGM12,bool copy_WGM13){
        if (copy_WGM10 == true)
            TCCR1A |= (BIT_MASK<<copy_WGM10);
        else
            TCCR1A &=~(BIT_MASK<<copy_WGM10);


        if (copy_WGM11 == true)
            TCCR1A |= (BIT_MASK<<copy_WGM11);
        else
            TCCR1A &=~(BIT_MASK<<copy_WGM11);

        if (copy_WGM12 == true)
            TCCR1A |= (BIT_MASK<<copy_WGM12);
        else
            TCCR1A &=~(BIT_MASK<<copy_WGM12);

        if (copy_WGM13 == true)
            TCCR1A |= (BIT_MASK<<copy_WGM13);
        else
            TCCR1A &=~(BIT_MASK<<copy_WGM13);        
    }

#endif

static void Local_vSetPrescaler(u16 Copy_u16Prescaler){
    #if (PWM_CHANNEL == PWM_CHANNEL_0)
    
        switch(Copy_u16Prescaler){
            case PWM_PRESC_1:
                TCCR0 |= (BIT_MASK<<CS00);
                break;
            case PWM_PRESC_8:
                TCCR0 |= (BIT_MASK<<CS01);
                break;

            case PWM_PRESC_64:

                TCCR0 |= (BIT_MASK<<CS00);
                TCCR0 |= (BIT_MASK<<CS01);
                break;

            case PWM_PRESC_256:

                TCCR0 |= (BIT_MASK<<CS02);
                
                break;
            case PWM_PRESC_1024:
                TCCR0 |= (BIT_MASK<<CS02);
                TCCR0 |= (BIT_MASK<<CS00);
                break;
            case PWM_PRESC_EXT_FE:
                TCCR0 |= (BIT_MASK<<CS01);
                TCCR0 |= (BIT_MASK<<CS02);
                break;
            case PWM_PRESC_EXT_RE:
                TCCR0 |= (BIT_MASK<<CS00);
                TCCR0 |= (BIT_MASK<<CS01);
                TCCR0 |= (BIT_MASK<<CS02);
                
                break;
        }
    #elif (PWM_CHANNEL == PWM_CHANNEL_1)
        switch(Copy_u16Prescaler){
            case PWM_PRESC_1:
                TCCR1B |= (BIT_MASK<<CS10);
                break;
            case PWM_PRESC_8:
                TCCR1B |= (BIT_MASK<<CS11);
                break;
            case PWM_PRESC_64:

                TCCR1B |= (BIT_MASK<<CS10);
                TCCR1B |= (BIT_MASK<<CS11);

                break;
            case PWM_PRESC_256:

                TCCR1B |= (BIT_MASK<<CS12);
                
                break;
                
            case PWM_PRESC_1024:
                TCCR1B |= (BIT_MASK<<CS12);
                TCCR1B |= (BIT_MASK<<CS10);
                break;
            case PWM_PRESC_EXT_FE:

                TCCR1B  |= (BIT_MASK<<CS11);
                TCCR1B  |= (BIT_MASK<<CS12);
                break;
            case PWM_PRESC_EXT_RE:

                TCCR1B |= (BIT_MASK<<CS10);
                TCCR1B |= (BIT_MASK<<CS11);
                TCCR1B |= (BIT_MASK<<CS12);
                
                break;
        }

    #elif (PWM_CHANNEL == PWM_CHANNEL_2)
        switch(Copy_u16Prescaler){
            case PWM_PRESC_1:
                TCCR2 |= (BIT_MASK<<CS20);
                break;
            case PWM_PRESC_8:
                TCCR2 |= (BIT_MASK<<CS21);
                break;
            case PWM_PRESC_64:

                TCCR2 |= (BIT_MASK<<CS20);
                TCCR2 |= (BIT_MASK<<CS21);

                break;
            case PWM_PRESC_256:

                TCCR2 |= (BIT_MASK<<CS22);
                
                break;
                
            case PWM_PRESC_1024:
                TCCR2 |= (BIT_MASK<<CS22);
                TCCR2 |= (BIT_MASK<<CS20);
                break;
            case PWM_PRESC_EXT_FE:

                TCCR2  |= (BIT_MASK<<CS21);
                TCCR2  |= (BIT_MASK<<CS22);
                break;
            case PWM_PRESC_EXT_RE:

                TCCR2 |= (BIT_MASK<<CS20);
                TCCR2 |= (BIT_MASK<<CS21);
                TCCR2 |= (BIT_MASK<<CS22);
                
                break;
        }


    #endif


    return;
}


Error_State PWM_enuInit(){
    #if (PWM_CHANNEL == PWM_CHANNEL_2)   
        #if (PWM_MODE == PWM_PHASE_CORRECT_MODE)

            TCCR2 |= (BIT_MASK<<WGM20);
            TCCR2 |= (BIT_MASK<<COM21);

        #elif (PWM_MODE == PWM_FAST_PWM_MODE)

            TCCR2 |= (BIT_MASK<<WGM20);
            TCCR2 |= (BIT_MASK<<COM21);
        #else
            #error Wrong PWM MODE
        #endif
    #elif (PWM_CHANNEL == PWM_CHANNEL_0)
         #if (PWM_MODE == PWM_PHASE_CORRECT_MODE)

            TCCR0 |= (BIT_MASK<<WGM00);
            TCCR0 &=~(BIT_MASK<<WGM01);

        #elif (PWM_MODE == PWM_FAST_PWM_MODE)

            TCCR0 |= (BIT_MASK<<WGM00);
            TCCR0 |= (BIT_MASK<<WGM01);

        #else       
            #error Wrong PWM MODE
        #endif
    #elif (PWM_CHANNEL == PWM_CHANNEL_1)
         #if (PWM_MODE == PWM_PHASE_CORRECT_8_BIT)

            Local_vTM1SetMode(1,0,0,0);

        #elif (PWM_MODE == PWM_PHASE_CORRECT_9_BIT)

            Local_vTM1SetMode(0,1,0,0);

        #elif (PWM_MODE == PWM_PHASE_CORRECT_10_BIT)

            Local_vTM1SetMode(1,1,0,0);

        #elif (PWM_MODE == PWM_FAST_PWM_8_BIT)

            Local_vTM1SetMode(1,0,1,0); 
        #elif (PWM_MODE == PWM_FAST_PWM_9_BIT)

            Local_vTM1SetMode(0,1,1,0);   
        #elif (PWM_MODE == PWM_FAST_PWM_10_BIT)

            Local_vTM1SetMode(1,1,1,0);               
        #else       
            #error Wrong PWM MODE
        #endif    
    #endif
    return ES_OK;
}
Error_State PWM_enuEnable(u8 copy_u8DutyCycle){
    if (copy_u8DutyCycle < 0){
        return ES_NOK;
    }
   

    #if (PWM_CHANNEL == PWM_CHANNEL_2)
        u8 local_u8OCRVal =  (255 * copy_u8DutyCycle) / 100;
        #if(PWM_PHASE_MODE == PWM_NON_INVERTING_MODE)

            TCCR2 |= (BIT_MASK << COM21);

        #elif(PWM_PHASE_MODE == PWM_INVERTING_MODE)
            TCCR2 |= (BIT_MASK << COM20);
            TCCR2 |= (BIT_MASK << COM21);
        #else 
            #error signal phase Invalid mode 
        #endif
        OCR2 = local_u8OCRVal;
    
    #elif (PWM_CHANNEL == PWM_CHANNEL_0)
        u8 local_u8OCRVal =  (255 * copy_u8DutyCycle) / 100;
        #if(PWM_PHASE_MODE == PWM_NON_INVERTING_MODE)
            
            TCCR0 |= (BIT_MASK << COM01);


        #elif(PWM_PHASE_MODE == PWM_INVERTING_MODE)

            TCCR0 |= (BIT_MASK << COM00);
            TCCR0 |= (BIT_MASK << COM01);
        #else 
            #error signal phase Invalid mode 

        #endif


        OCR0 = local_u8OCRVal;

    #elif (PWM_CHANNEL == PWM_CHANNEL_1_A)
        u16 local_u16OCRVal =  (65535 * copy_u8DutyCycle) / 100;
        #if (PWM_PHASE_MODE == PWM_NON_INVERTING_MODE)
         
            TCCR1A |= (BIT_MASK << COM1A0);

        #elif (PWM_PHASE_MODE == PWM_INVERTING_MODE)

            TCCR1A |= (BIT_MASK << COM1A0);
            TCCR1A |= (BIT_MASK << COM1A1);

        #else 
            #error signal phase Invalid mode 
        #endif
        OCR1A = local_u16OCRVal;

    #elif (PWM_CHANNEL == PWM_CHANNEL_1_B)
        u16 local_u16OCRVal =  (65535 * copy_u8DutyCycle) / 100;
        #if (PWM_PHASE_MODE == PWM_NON_INVERTING_MODE)
            TCCR1B |= (BIT_MASK << COM1B0);

        #elif (PWM_PHASE_MODE == PWm_INVERTING_MODE)
            TCCR1B |= (BIT_MASK << COM1B0);
            TCCR1B |= (BIT_MASK << COM1B1);
        #else 
            #error signal phase Invalid mode 
        
        OCR1B = local_u16OCRVal;
         #endif

    #endif
    Local_vSetPrescaler(PWM_PRESCALER);


    return ES_OK;
}
Error_State PWM_enuDisable(u8 copy_u8DutyCycle){

    #if (PWM_CHANNEL == PWM_CHANNEL_2)
        TCCR2 &= ~(1<<CS22);
        TCCR2 &= ~(1<<CS21);
    #endif

    return ES_OK;
}