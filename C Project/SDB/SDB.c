#include "SDB.h"

#include<stdio.h>

static uint8 NumberOfStudents = 0;

student DataBase[DataBaseSize] = {0};


/*check if the database is full or 
not.*/
Bool SDB_IsFull(){
    return (NumberOfStudents == 10) ? True : False;
}


/*
get how many students in 
your database have added*/
uint8 SDB_GetUsedSize(){
    return NumberOfStudents;
}



/*When the user chooses to 
add entry this function asks him for the 
required data in the database to add one 
student */
Bool SDB_AddEntry(){

    uint32 temp = 0;
    uint32 id;

    if(NumberOfStudents == DataBaseSize) return False;


    
    for(int i =0; i<50; i++)
        printf("*");
    
ID:
    printf("\nPlease Enter User ID: ");
    scanf("%u",&id);
    if(id == 0){
        printf("Error Student ID can't be Zero!");
        goto ID;
    }
    while(temp < DataBaseSize){
        if(id == DataBase[temp].Student_ID)
        {
            printf("Error Student Already Exists!");
            SDB_ReadEntry(id);
            goto ID;
        }
        temp++;
    };
    DataBase[NumberOfStudents].Student_ID = id;

YEAR:
    printf("Please Enter Year: ");
    scanf("%d",&DataBase[NumberOfStudents].Student_year);
    if(DataBase[NumberOfStudents].Student_year < 1900 ||
        DataBase[NumberOfStudents].Student_year >2023){
        printf("Please Enter a valid Year\n ");
            goto YEAR;
        }



    printf("Please Enter Course 1 ID: ");
    scanf("%d",&DataBase[NumberOfStudents].Course1_ID);
C1:    
    printf("Please Enter Course 1 Grade: ");
    scanf("%d",&DataBase[NumberOfStudents].Course1_grade);

    if(DataBase[NumberOfStudents].Course1_grade > 100){
        printf("Invalid grade please add a grade between 0 to 100\n");
        goto C1;
    }




    printf("Please Enter Course 2 ID: ");
    scanf("%d",&DataBase[NumberOfStudents].Course2_ID);
C2:
    printf("Please Enter Course 2 Grade: ");
    scanf("%d",&DataBase[NumberOfStudents].Course2_grade);

    if(DataBase[NumberOfStudents].Course2_grade > 100){
        printf("Invalid grade please add a grade between 0 to 100\n");
        goto C2;
    }



    printf("Please Enter Course 3 ID: ");
    scanf("%d",&DataBase[NumberOfStudents].Course3_ID);
C3:
    printf("Please Enter Course 3 Grade: ");
    scanf("%d",&DataBase[NumberOfStudents].Course3_grade);

    if(DataBase[NumberOfStudents].Course3_grade> 100){
        printf("Invalid grade please add a grade between 0 to 100\n");
        goto C3;
    }
    NumberOfStudents++;
    for(int i =0; i<50; i++)
        printf("*");
    printf("\n");
    return True;
}




/*delete the student data with 
the given id. */
void SDB_DeletEntry(uint32 id){
    for (int i = 0; i < DataBaseSize; i++)
    {
        if (id == DataBase[i].Student_ID){
            DataBase[i].Student_ID = 0;
            NumberOfStudents--;
            return;
        }

    }

    printf("Error Student not found!");

    
}



/*print the data of the user by 
searching on his data by the given id*/
Bool SDB_ReadEntry(uint32 id)
{
    for (int i = 0; i < DataBaseSize; i++)
    {
        if (id == DataBase[i].Student_ID){

            printf("User ID: ");
            printf("%d\n",DataBase[i].Student_ID);
            printf("Year: ");
            printf("%d\n",DataBase[i].Student_year);
            printf("Course 1 ID: ");
            printf("%d\n",DataBase[i].Course1_ID);
            printf("Course 1 Grade: ");
            printf("%d\n",DataBase[i].Course1_grade);
            printf("Course 2 ID: ");
            printf("%d\n",DataBase[i].Course2_ID);
            printf("Course 2 Grade: ");
            printf("%d\n",DataBase[i].Course2_grade);
            printf("Course 3 ID: ");
            printf("%d\n",DataBase[i].Course3_ID);
            printf("Course 3 Grade: ");
            printf("%d\n",DataBase[i].Course3_grade);            
            return True;
        }

    }
    return False;
}


void SDB_GetList(uint8 * count, uint32 * list){
        int i = 0;
        if(*count > DataBaseSize){
            printf("Error number exceeds database size!\n");
            return;
        }
        while(*(count) && i < NumberOfStudents){
            if(DataBase[i].Student_ID ==0 ){
                    i++;
                    continue;
            }
            for(int i =0; i<50; i++)
                    printf("*");
            printf("User ID: ");
            printf("%d\n",DataBase[i].Student_ID);
            printf("Year: ");
            printf("%d\n",DataBase[i].Student_year);
            printf("PCourse 1 ID: ");
            printf("%d\n",DataBase[i].Course1_ID);
            printf("PCourse 1 Grade: ");
            printf("%d\n",DataBase[i].Course1_grade);
            printf("Course 2 ID: ");
            printf("%d\n",DataBase[i].Course2_ID);
            printf("Course 2 Grade: ");
            printf("%d\n",DataBase[i].Course2_grade);
            printf("Course 3 ID: ");
            printf("%d\n",DataBase[i].Course3_ID);
            printf("Course 3 Grade: ");
            printf("%d\n",DataBase[i].Course3_grade);  
            for(int i =0; i<50; i++)
                printf("*");
            printf("\n");
            *(count)--;
            i++;
    }
    *count = 0;
}

/*print the data of the user by 
searching on his data by the given id exists*/
Bool SDB_IsIdExist(uint32 id){

    for (int i = 0; i < DataBaseSize; i++)
    {
        if (id == DataBase[i].Student_ID) return True;

    }
    return False;
}
