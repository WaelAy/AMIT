#include <util/delay.h>
#include "../../std.h"
#include "../../MCAL/dio/dio.h"

#include "keypad.lib.h"
#include "keypad.priv.h"
#include "keypad.config.h"
#include "../lcd/lcd.lib.h"



Error_State Keypad_init(void){
    u8 keys_rows_groups[KEYPAD_ROW_NUM] = {R1_PORT,R2_PORT,R3_PORT,R4_PORT};
    u8 keys_rows_pins[KEYPAD_ROW_NUM] = {R1_PIN,R2_PIN,R3_PIN,R4_PIN};

    u8 keys_columns_groups[KEYPAD_COL_NUM] = {C1_PORT,C2_PORT,C3_PORT,C4_PORT};
    u8 keys_columns_pins[KEYPAD_COL_NUM] = {C1_PIN,C2_PIN,C3_PIN,C4_PIN};

    for (u8 i = 0; i < KEYPAD_COL_NUM; i++)
    {
        dio_init(keys_columns_groups[i],keys_columns_pins[i],OUTPUT);
        dio_write(keys_columns_groups[i],keys_columns_pins[i],HIGH);
    }
    
    for (u8 i = 0; i < KEYPAD_ROW_NUM; i++)
    {
        dio_init(keys_rows_groups[i],keys_rows_pins[i],INPUT);
        dio_write(keys_rows_groups[i],keys_rows_pins[i],HIGH);
    }
    
    
    return ES_OK;
}

Error_State Keypad_readKey(u8 *key_val){


    u8 keys_rows_groups[KEYPAD_ROW_NUM] = {R1_PORT,R2_PORT,R3_PORT,R4_PORT};
    u8 keys_rows_pins[KEYPAD_ROW_NUM] = {R1_PIN,R2_PIN,R3_PIN,R4_PIN};

    u8 keys_columns_groups[KEYPAD_COL_NUM] = {C1_PORT,C2_PORT,C3_PORT,C4_PORT};
    u8 keys_columns_pins[KEYPAD_COL_NUM] = {C1_PIN,C2_PIN,C3_PIN,C4_PIN};

    u8 value = 0XFF;
    *key_val = 0xff;
    bool break_flag = false;

    for (u8 i = 0; i < KEYPAD_COL_NUM; i++)
    {

        dio_write(keys_columns_groups[i],keys_columns_pins[i],LOW);

        for (u8 j = 0; j < KEYPAD_ROW_NUM; j++){
            dio_read(keys_rows_groups[j],keys_rows_pins[j],&value);

            if(value==LOW){
                
                dio_read(keys_rows_groups[j],keys_rows_pins[j],&value);
                if (value==LOW)
                {
                    u8 keys[KEYPAD_ROW_NUM][KEYPAD_COL_NUM] = KEYPAD_KEY_VALUES;
                    *key_val = keys[j][i];

                    while(value==LOW){
                        dio_read(keys_rows_groups[j],keys_rows_pins[j],&value);   
                    }

                    break_flag = true;
                    break;
                }
                
            }


        }
            dio_write(keys_columns_groups[i],keys_columns_pins[i],HIGH);
            if(break_flag)
                break;
    }
    


    return ES_OK;
}

