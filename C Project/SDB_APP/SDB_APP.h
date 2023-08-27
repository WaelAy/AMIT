#ifndef _SDB_APP_
#define _SDB_APP_
#include<stdio.h>
#include "../STD.h"
#include".././SDB/SDB.h"


typedef enum {
    
    AddEntry = 1,
    GetUsedSize,
    ReadStudentData,
    GetList,
    IDExits,
    DeleteStudata,
    isFull,
    Exit = 0
} options;



void SDB_APP();
void SDB_action (uint8 choice);




#endif