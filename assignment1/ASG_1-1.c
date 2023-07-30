#include<stdio.h>


int main(){
    
    float x;
    int input;

    printf("Enter input:");
    scanf("%d",&input);

    x = ((float)input / 2);
    input = input / 2;


    if(printf("The number is Even: %d\n",x==input)){
        printf("The number is odd: %d",x!=input);
    }

    return 0;
}