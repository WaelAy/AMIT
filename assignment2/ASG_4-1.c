#include<stdio.h>


void edit(int *x){
    (*x)++;
}




int main(){
    int x = 40;
    printf("Before edit: %d" , x);
    edit(&x);
    printf("\nAfter edit: %d" , x);

    return 0;
}