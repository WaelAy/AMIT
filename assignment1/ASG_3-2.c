#include <stdio.h>


int main(){
    int input;
    scanf("%d",&input);
    int a = 0 , b = 1, temp = 0;
    while (input)
    {
        printf("%d ",a);
        temp = a + b;
        a = b;
        b = temp;

        input--;
    }
    




    return 0;
}