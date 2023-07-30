#include <stdio.h>


int main(){

    int num1 , num2;
    char op;
    printf("Enter the first number: ");
    scanf("%d",&num1);
    printf("\nEnter the operand: ");
    scanf("%s", &op);
    printf("\nEnter the 2nd number: ");
    scanf("%d",&num2);

    switch (op)
    {
    case '+':
        printf("\nA+B = %d",num1 + num2);
        break;
    case '-':
        printf("\nA-B = %d",num1 - num2);
        break;
    case '*':
        printf("\nA*B = %d",num1 * num2);
        break;
    case '/':
        printf("\nA/B = %d",num1 / num2);
        break;                    
    default:
        break;
    }




    return 0;
    }