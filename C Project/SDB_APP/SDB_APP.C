#include "SDB_APP.h"



void SDB_APP(){
    while (1)
    {
        printf("Please select one of the following options:-\n");
        printf("1.To add entry.\n");
        printf("2.To get used size in database.\n");
        printf("3.To read student data.\n");
        printf("4.To get the list of all student IDs.\n");
        printf("5.To check is ID is existed.\n");
        printf("6.To delete student data.\n");
        printf("7. To check is database is full.\n");
        printf("0.Exit\n");
        uint8 number;
        scanf("%d",&number);
        if(!number) return;
        SDB_action(number);
    }
    
}


void SDB_action (uint8 choice){
    uint32 read,id;
    uint8 nOfstudent;
    switch (choice)
        {
        case AddEntry:
            SDB_AddEntry();
            break;
        case GetUsedSize:
            printf("The used size is %d from %d\n",SDB_GetUsedSize(),DataBaseSize);
            break;
        case ReadStudentData:
            
            printf("Enter The ID to be read\n");
            scanf("%u",&read);
            SDB_ReadEntry(read);
            break;
        case GetList:
            printf("Enter the number of Students");
            
            scanf("%u",&nOfstudent);
            SDB_GetList(&nOfstudent,NULL);
            break;
        case IDExits:
            printf("Enter ID to be read:");
            scanf("%u",&id);
            if(SDB_IsIdExist(id))
                printf("\nIt Exists!");
            break;
        case DeleteStudata:
            
            printf("Enter The ID to be read\n");
            scanf("%u",&id);
            SDB_DeletEntry(id);
            break;
        case isFull:
            SDB_IsFull();
            break;
        default:
        printf("Error Invalid input!\n");
            break;
        }
}