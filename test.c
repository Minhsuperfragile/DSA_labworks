#include <stdio.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(){
    int low = 4, high = 3;
    swap(&low,&high);
    printf("High: %d, Low: %d",high,low);
}