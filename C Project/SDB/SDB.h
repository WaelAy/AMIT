#ifndef _SDB_
#define _SDB_
#include "STD.h"
#define DataBaseSize 10

typedef struct SimpleDb 
{ 
    uint32 Student_ID; 
    uint32 Student_year; 
    uint32 Course1_ID; 
    uint32 Course1_grade; 
    uint32 Course2_ID; 
    uint32 Course2_grade; 
    uint32 Course3_ID; 
    uint32 Course3_grade; 

} student; 



Bool SDB_IsFull();
uint8 SDB_GetUsedSize();
Bool SDB_AddEntry();
void SDB_DeletEntry(uint32 id);
Bool SDB_ReadEntry(uint32 id);
void SDB_GetList(uint8 * count, uint32 * list);
Bool SDB_IsIdExist(uint32 id);



#endif