#include <stdio.h>
void reverse_array(int *arr,int sz){
    int temp  , l=0;
    sz--;
    while (sz>l)
    {
        temp = *(arr+l);
        *(arr+l) = *(arr+sz);
        *(arr+sz) = temp;
        sz--;
        l++;
    }
    
}

int main(void){

    int arr[5] = {1,2,3,4,5};
    reverse_array(arr,5);
    for (int i = 0; i < 5; i++)
    {
        printf("%d",arr[i]);
    }
    
        
    return 0;
}