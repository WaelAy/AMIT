#include<stdio.h>


void reverse(char *start,char *end){
    char temp;
    while(start<end){
        temp = *start;
        *start++ = *end;
        *end-- = temp;
    }
}

void reverse_sentence(char *s){
    char *temp = s;
    char *word = s;

    while(*temp){
        temp++;
        if(*temp == '\0'){
            reverse(word,temp-1);
        }
        else if(*temp == ' '){
            reverse(word,temp-1);
            word = temp +1;
        }
    }
    reverse(s,temp-1);


}


int main(){

    char str[20],rev[20];
    char *ptrOrg = str;
    char *ptrrev = rev;
    scanf("%[^\n]%*c", str);

    printf("String before reversing words: %s",str);

    reverse_sentence(str);
    


    printf("\nString after reversing words: %s",str);



    return 0;
}