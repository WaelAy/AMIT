#ifndef _LCD_LIB_H
#define _LCD_LIB_H

#include "../../std.h"




#define CHAR 1
#define COMMAND 0



/*function to initsialize LCD*/
Error_State LCD_Init(void);
/*function to display characters or numbers In char * format*/
Error_State LCD_Display(const char *Text);
/*function to clear LCD*/
Error_State LCD_Clear(void);
/*function to set LCD place*/
Error_State LCD_Set_Position(u8 row, u8 column);
/*function to send LCD command or char */
Error_State LCD_char(u8 content);
/*Function to hide cursor from LCD*/
Error_State LCD_hide_cursor();
/*Function to show cursor from LCD*/
Error_State LCD_show_cursor();
/*Function to print integers*/
Error_State LCD_Displayint(s32 Copy_s32Number);

#endif