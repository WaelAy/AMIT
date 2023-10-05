#ifndef _LCD_CONFIG_H
#define _LCD_CONFIG_H

/************************************/
/************************************/
/************************************/
/*NUMBER OF ROWS AND COLUMNS ON LCD*/
/************************************/
/************************************/
/************************************/

#define LCD_N_COLUMNS 16
#define LCD_N_ROWS 2

/************************************/
/************************************/
/************************************/
/*Type LCD_4_PIN_MODE for 4bit mode*/
/*Type LCD_8_PIN_MODE for 8bit mode*/
/************************************/
/************************************/
/************************************/

#define LCD_MODE LCD_4PIN_MODE

/************************************/
/************************************/
/**********LCD Control Pins**********/
/************************************/
/************************************/

#define LCD_RS_PIN    1
#define LCD_RS_PORT  'B'

#define LCD_RW_PIN   2
#define LCD_RW_PORT 'B'

#define LCD_EN_PIN    3
#define LCD_EN_PORT  'B'


/************************************/
/************************************/
/***********LCD Data Pins************/
/************************************/
/************************************/
#define LCD_DB7_PIN   7
#define LCD_DB7_PORT 'A'

#define LCD_DB6_PIN   6
#define LCD_DB6_PORT 'A'

#define LCD_DB5_PIN   5
#define LCD_DB5_PORT 'A'

#define LCD_DB4_PIN   4
#define LCD_DB4_PORT 'A'


/************************************/
/************************************/
/******If its 8 pin mode ************/
/************************************/
/************************************/
#define LCD_DB3_PIN
#define LCD_DB3_PORT

#define LCD_DB2_PIN
#define LCD_DB2_PORT

#define LCD_DB1_PIN
#define LCD_DB1_PORT

#define LCD_DB0_PIN
#define LCD_DB0_PORT


#endif