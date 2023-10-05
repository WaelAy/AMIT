#include <util/delay.h>

#include "../.././MCAL/dio/dio.h"

#include "lcd.lib.h"
#include "lcd.priv.h"
#include "lcd.config.h"

void LCD_send4B(uint8_t pin1,uint8_t pin2, uint8_t pin3, uint8_t pin4 ,uint8_t type){
	dio_write(LCD_RS_PORT,LCD_RS_PIN,type);
	dio_write(LCD_EN_PORT,LCD_EN_PIN,HIGH);
	dio_write(LCD_DB7_PORT,LCD_DB7_PIN,pin1);
	dio_write(LCD_DB6_PORT,LCD_DB6_PIN,pin2);
	dio_write(LCD_DB5_PORT,LCD_DB5_PIN,pin3);
	dio_write(LCD_DB4_PORT,LCD_DB4_PIN,pin4);
	dio_write(LCD_EN_PORT,LCD_EN_PIN,LOW);
	_delay_ms(LCD_PHASE_DELAY);

}



Error_State LCD_send(u8 content,u8 type){
        dio_write(LCD_RS_PORT,LCD_RS_PIN,type);
        dio_write(LCD_EN_PORT,LCD_EN_PIN,LOW);
        dio_write(LCD_DB7_PORT,LCD_DB7_PIN,((content>>STD_PIN7) & HIGH));
        dio_write(LCD_DB6_PORT,LCD_DB6_PIN,((content>>STD_PIN6) & HIGH));
        dio_write(LCD_DB5_PORT,LCD_DB5_PIN,((content>>STD_PIN5) & HIGH));
        dio_write(LCD_DB4_PORT,LCD_DB4_PIN,((content>>STD_PIN4) & HIGH));


    #if (LCD_MODE == LCD_8PIN_MODE)

        dio_write(LCD_DB3_PORT,LCD_DB3_PIN,((content>>STD_PIN3) & HIGH));
        dio_write(LCD_DB2_PORT,LCD_DB2_PIN,((content>>STD_PIN2) & HIGH));
        dio_write(LCD_DB1_PORT,LCD_DB1_PIN,((content>>STD_PIN1) & HIGH));
        dio_write(LCD_DB0_PORT,LCD_DB0_PIN,((content>>STD_PIN0) & HIGH));

    #elif (LCD_MODE == LCD_4PIN_MODE)
        dio_write(LCD_EN_PORT,LCD_EN_PIN,LCD_HIGH);
        _delay_ms(LCD_PHASE_DELAY);

        dio_write(LCD_EN_PORT,LCD_EN_PIN,LCD_LOW);

        dio_write(LCD_DB7_PORT,LCD_DB7_PIN,((content>>STD_PIN3) & HIGH));
        dio_write(LCD_DB6_PORT,LCD_DB6_PIN,((content>>STD_PIN2) & HIGH));
        dio_write(LCD_DB5_PORT,LCD_DB5_PIN,((content>>STD_PIN1) & HIGH));
        dio_write(LCD_DB4_PORT,LCD_DB4_PIN,((content>>STD_PIN0) & HIGH));
        

    #endif
    dio_write(LCD_EN_PORT,LCD_EN_PIN,LCD_HIGH);
    _delay_ms(LCD_PHASE_DELAY);

    dio_write(LCD_EN_PORT,LCD_EN_PIN,LCD_LOW);
    // waiting delay to finish exectution

    _delay_ms(LCD_PHASE_DELAY);
    return ES_OK;
}


Error_State LCD_Init(void){
        _delay_ms(LCD_INIT_DELAY);
        dio_init(LCD_RS_PORT,LCD_RS_PIN,OUTPUT);
        dio_init(LCD_RW_PORT,LCD_RW_PIN,OUTPUT);
        dio_init(LCD_EN_PORT,LCD_EN_PIN,OUTPUT);
        dio_init(LCD_DB7_PORT,LCD_DB7_PIN,OUTPUT);
        dio_init(LCD_DB6_PORT,LCD_DB6_PIN,OUTPUT);
        dio_init(LCD_DB5_PORT,LCD_DB5_PIN,OUTPUT);
        dio_init(LCD_DB4_PORT,LCD_DB4_PIN,OUTPUT);
#if (LCD_MODE == LCD_4PIN_MODE)
        /*LCD 4bit mode intialisation according TO data sheet*/
        LCD_send4B(0,0,1,0,COMMAND);
        LCD_send4B(0,0,1,0,COMMAND);
        LCD_send4B(1,1,1,1,COMMAND);
        _delay_ms(LCD_PHASE_DELAY);
        LCD_send4B(0,0,0,0,COMMAND);
        LCD_send4B(1,1,1,1,COMMAND);
        _delay_ms(LCD_PHASE_DELAY);
        LCD_send4B(0,0,0,0,COMMAND);
        LCD_send4B(0,0,0,1,COMMAND);
        _delay_ms(LCD_PHASE_DELAY);
        LCD_send4B(0,0,0,0,COMMAND);
        LCD_send4B(0,0,1,1,COMMAND);
        _delay_ms(LCD_PHASE_DELAY);


#elif (LCD_MODE == LCD_8PIN_MODE)

        dio_init(LCD_DB3_PORT,LCD_DB3_PIN,OUTPUT);
        dio_init(LCD_DB2_PORT,LCD_DB2_PIN,OUTPUT);
        dio_init(LCD_DB1_PORT,LCD_DB1_PIN,OUTPUT);
        dio_init(LCD_DB0_PORT,LCD_DB0_PIN,OUTPUT);
        dio_write(LCD_RS_PORT , LCD_RS_PIN , LOW);
        LCD_send(LCD_8PIN_INIT_CMD,COMMAND);
        _delay_ms(LCD_PHASE_DELAY);
        LCD_send(LCD_8PIN_DISPLAY_ON_OFF,COMMAND);
        _delay_ms(LCD_PHASE_DELAY);
        LCD_send(LCD_CLEAR,COMMAND);
        _delay_ms(LCD_PHASE_DELAY);
        LCD_send(LCD_8PIN_ENTRY_MODE_SET,COMMAND);
        _delay_ms(LCD_PHASE_DELAY);

#endif




    return ES_OK;

}

Error_State LCD_Display(const char *Text){
    while(*Text){
        dio_write(LCD_RS_PORT,LCD_RS_PIN,HIGH);
        LCD_send(*Text,CHAR);
        Text++;
    }

    return ES_OK;
}

Error_State LCD_Set_Position(u8 row, u8 column){
    

	if (row > LCD_N_ROWS || column > LCD_N_COLUMNS)
		return ES_NOK;

    LCD_send((0x80 + (0x40*(row -1))) + (column -1),COMMAND);

    return ES_OK;

}



Error_State LCD_Clear(void){

    LCD_send(LCD_CLEAR_CMD,COMMAND);

    return ES_OK;
}

Error_State LCD_char(u8 content){
    
    LCD_send(content , CHAR);

    return ES_OK;
}


Error_State LCD_hide_cursor(){


    LCD_send4B(0,0,0,0,COMMAND);
    LCD_send4B(1,1,0,0,COMMAND);

    return ES_OK;
}

Error_State LCD_Displayint(s32 Copy_s32Number){
    if(Copy_s32Number < 0){
        LCD_Display("-");
        Copy_s32Number = Copy_s32Number * -1;
    }

    u32 local_s32temp = Copy_s32Number;
    u32 local_u32iter = 10;
    while (local_s32temp > 100)
    {
        local_s32temp /= 10; 
        local_u32iter *=10; 
    }


    while (local_u32iter > 0)
    {
        u8 Local_u8ASCIINum = ((Copy_s32Number/local_u32iter)%10) + 48;
        LCD_send(Local_u8ASCIINum,CHAR);
        local_u32iter /= 10;   
          
    }
    


    return ES_OK;
}



Error_State LCD_show_cursor(){
    LCD_send4B(0,0,0,0,COMMAND);
    LCD_send4B(1,1,1,1,COMMAND);

    return ES_OK;
}