#include <stdio.h>

char isArmstrong(int num){
    int answer = 0,buff=num;
    while (buff)
    {
        int temp = buff%10;
        temp = temp * temp * temp;
        answer += temp;
        buff /=10;
    }
    if (answer == num)
        return 1;
    return 0;
}





int main(){
    int scan;
    scanf("%d",&scan);
    char result = isArmstrong(scan);

    result ? printf("Its Armstrong"): printf("Its not Armstrong");



    return 0;
}