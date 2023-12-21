#include <stdio.h>
#include <string.h>

typedef struct  _bracket{
    int isOpen;
    int firstCharHolder;
    int lastCharHolder;
}Bracket;

void swap(char *a, char *b){
    char t = *a;
    *a = *b;
    *b = t;
}

void inverseString(char *str,int start, int end){
    while(start < end){
        swap(&str[start],&str[end]);
        start++;
        end--;
    }
}

void printStr(char *str,int size){
    for (int i=0;i<size;i++){
        printf("%c",str[i]);
    }
    printf("\n");
}

void bracketDetect(char *str){
    int size = strlen(str);
    Bracket stack[20];

    int stackCount = 0;

    for(int i=0;i<size;i++){
        if (str[i] == 91){
            stack[stackCount].isOpen = 1;
            stack[stackCount].firstCharHolder = i+1;    
            stackCount++;    
        }
        if (str[i] == 93){
        	--stackCount;
            stack[stackCount].isOpen = 0;
            stack[stackCount].lastCharHolder = i-1;
			inverseString(str,stack[stackCount].firstCharHolder,stack[stackCount].lastCharHolder);
        }
    }
}

int main(){
    char run[] = "13j[831[2o[l;k]jd[6ld]at]lwix]ofa as[os 2p]dd"; // size = 46

    bracketDetect(run);
    printStr(run,46);

    return 0;
}