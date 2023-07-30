#include <stdio.h>

int main(void){
    int input,bitN;
    printf("Please type the number followed by the bit: ");
    scanf("%d %d",&input,&bitN);
    printf("The number after toggling the %dth bit: %d", bitN,input ^= (1<<bitN));
    return 0;
}