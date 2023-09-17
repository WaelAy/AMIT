#ifndef _LCD_PRIV_H
#define _LCD_PRIV_H

/*The time taken to initailize the LCD in ms during the first power up*/
#define LCD_INIT_DELAY 32

/*The delay time taken between LCD initialization phases in ms*/
#define LCD_PHASE_DELAY 2

#define LCD_4PIN_MODE 4
#define LCD_8PIN_MODE 8

#define CHAR 1
#define COMMAND 0

#define LCD_RW_OUTPUT 0

#define LCD_LOW 0
#define LCD_HIGH 1


#define LCD_CLEAR_CMD 0X01
#define LCD_8PIN_INIT_CMD 0X3C
#define LCD_8PIN_DISPLAY_ON_OFF 0X0F
#define LCD_8PIN_ENTRY_MODE_SET 0X07



#endif