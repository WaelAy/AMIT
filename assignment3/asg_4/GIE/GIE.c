#include "GIE.h"







void GIE_vidEnable(void)
{
	//SREG |= (1<<7);
	asm("sei");
//	__asm("sei");
//	__asm__("sei");
}

void GIE_vidDisable(void)
{
	asm("cli");
}