#ifndef _KEYPAD_LIB_
#define _KEYPAD_LIB_

#include "keypad.priv.h"

#define KEYPAD_NOT_PRESSED 0xFF

Error_State Keypad_init(void);

Error_State Keypad_readKey(u8 *key_val);






#endif /*kEYPAD LIB*/