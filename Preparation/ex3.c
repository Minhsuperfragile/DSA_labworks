#include <stdio.h>
#include <string.h>
#include <math.h>

int isPalindrome(int num){
    int size = (int)((ceil(log10(num))+1)*sizeof(char));
    char str[size];
    sprintf(str, "%d", num);

    for (int i=0; i<(size/2);i++){
        if(str[i] != str[size-2-i]){
            return 0;
        }
    }
    return 1;
}

int main(){
    printf("%d",isPalindrome(1221));
}