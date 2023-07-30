#include <stdio.h>

void swap(int *x, int *y){
    *x = *x ^ *y;
    *y = *x ^ *y;
    *x = *x ^ *y;

}


int main(){
    int x = 10, y=20;
    printf("Before swapping\nx: %d\ny:%d",x,y);
    swap(&x,&y);
    printf("\nAfter swapping\nx: %d\ny:%d",x,y);
    return 0;
}