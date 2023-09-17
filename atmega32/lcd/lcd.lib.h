#ifndef _LCD_LIB_H
#define _LCD_LIB_H

#include "../std.h"




#define CHAR 1
#define COMMAND 0



/*function to initsialize LCD*/
Error_State LCD_Init(void);
/*function to display characters or numbers*/
Error_State LCD_Display(const char *Text);
/*function to clear LCD*/
Error_State LCD_Clear(void);
/*function to set LCD place*/
Error_State LCD_Set_Position(u8 row, u8 column);
/*function to send LCD command or char */
Error_State LCD_char(u8 content);



#endif