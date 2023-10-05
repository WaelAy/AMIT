



#include "ExInt.config.h"
#include "ExInt.lib.h"
#include "ExInt.priv.h"

static Error_State SetIntMode(u8 IntPin, u8 IntMode);
static Error_State EXTI_Setup(u8 IntPin, u8 TriggerType);


static void (*Local_vfunptrExt0)(void*) = NULL;
static void (*Local_vfunptrExt1)(void*) = NULL;
static void (*Local_vfunptrExt2)(void*) = NULL;

static void *Local_vfunParameterEXT0    = NULL;
static void *Local_vfunParameterEXT1    = NULL;
static void *Local_vfunParameterEXT2    = NULL;

extern EXTI_t EXTI_ConfigArr[];
extern u8 EXTIPinNum;


Error_State EXTI_Init(void){
    for (u8 i = 0 ; i < EXTIPinNum ; i++){
        SetIntMode(EXTI_ConfigArr[i].intPin,EXTI_ConfigArr[i].intMode);
        EXTI_Setup(EXTI_ConfigArr[i].intPin,EXTI_ConfigArr[i].senseLevel);
    }



    return ES_OK;
}

Error_State EXTI_Config(u8 EXTI_Pin,u8 config){

    EXTI_Setup(EXTI_Pin,config);
    return ES_OK;


}

Error_State EXTI_EnableInterrupt(u8 EXTI_Pin){
    SetIntMode(EXTI_Pin,EXTI_INTERRUPT_MODE);
    return ES_OK;
}


void __vector_1 (void)__attribute__((signal));
void __vector_2 (void)__attribute__((signal));
void __vector_3 (void)__attribute__((signal));

void __vector_1 (void)
{
    if(Local_vfunptrExt0 !=NULL){

        Local_vfunptrExt0(Local_vfunParameterEXT0);
    }
}
//INT1
void __vector_2 (void)
{
    if(Local_vfunptrExt1 !=NULL){

        Local_vfunptrExt1(Local_vfunParameterEXT1);
    }
}
//INT2
void __vector_3 (void)
{
    if(Local_vfunptrExt2 !=NULL){

        Local_vfunptrExt2(Local_vfunParameterEXT2);
    }
}

static Error_State SetIntMode(u8 IntPin, u8 IntMode)
{
    switch (IntPin)
    {
        case EXTI_INT0:
            if (IntMode == EXTI_INTERRUPT_MODE)
            {
                GICR |= (1<<6);
            }
            else 
            {
                GICR &=~ (1<<6);
            }
            break;
            
        case EXTI_INT1:
            if (IntMode == EXTI_INTERRUPT_MODE)
            {
                GICR |= (1<<7);
            }
            else 
            {
                GICR &=~ (1<<7);
            }
            break;

        case EXTI_INT2:
            if (IntMode == EXTI_INTERRUPT_MODE)
            {
                GICR |= (1<<5);
            }
            else 
            {
                GICR &=~ (1<<6);
            }
            break;
        default:

            return ES_NOK;
            
            break;
    }
    return ES_OK;
}



static Error_State EXTI_Setup(u8 IntPin, u8 TriggerType)
{
    switch (IntPin)
    {
        case EXTI_INT0:
            if (TriggerType == EXTI_LOW_LEVEL)
            {
                MCUCR &= ~(3<<0);
            }
            else if (TriggerType == EXTI_ANY_CHANGE)
            {
                MCUCR &= ~(3<<0);
                MCUCR |=  (1<<0);
            }
            else if (TriggerType == EXTI_FALLING)
            {
                MCUCR &= ~(3<<0);
                MCUCR |=  (1<<1);
            }
            else if (TriggerType == EXTI_RISING)
            {
                MCUCR |=  (3<<0);
            }
            else 
            {
            }
            break;
            
        case EXTI_INT1:
            if (TriggerType == EXTI_LOW_LEVEL)
            {
                MCUCR &= ~(3<<2);
            }
            else if (TriggerType == EXTI_ANY_CHANGE)
            {
                MCUCR &= ~(3<<2);
                MCUCR |=  (1<<2);
            }
            else if (TriggerType == EXTI_FALLING)
            {
                MCUCR &= ~(3<<2);
                MCUCR |=  (1<<3);
            }
            else if (TriggerType == EXTI_RISING)
            {
                MCUCR |=  (3<<2);
            }
            else 
            {
            }
            break;

        case EXTI_INT2:
            if (TriggerType == EXTI_FALLING)
            {
                MCUCSR &= ~(1<<6);
            }
            else if (TriggerType == EXTI_RISING)
            {
                MCUCSR |=  (1<<6);
            }
            else 
            {
            }
            break;
    }
    return ES_OK;
}


Error_State EXTI_enuSetCallBackFun(u8 EXTI_Pin  , void (*Copy_funptrCallbackfun)(void*),void *Copy_funptrCallbackParameter){

    if (EXTI_Pin > EXTI_INT2 && Copy_funptrCallbackfun == NULL)
    {
        return ES_NOK;
    }
    
    if (EXTI_Pin == EXTI_INT0)
    {
        Local_vfunptrExt0 = Copy_funptrCallbackfun;
        Local_vfunParameterEXT0 = Copy_funptrCallbackParameter;
        return ES_OK;
    }
                                  
    if (EXTI_Pin == EXTI_INT1)
    {
        Local_vfunptrExt1 = Copy_funptrCallbackfun;
        Local_vfunParameterEXT1 = Copy_funptrCallbackParameter;
        return ES_OK;
        
    }
    if (EXTI_Pin == EXTI_INT2)
    {
        Local_vfunptrExt2 = Copy_funptrCallbackfun;
        Local_vfunParameterEXT2 = Copy_funptrCallbackParameter;
        return ES_OK;
    }

    return ES_OK;
}