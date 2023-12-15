#include <stdio.h>

int isPentagonal(int n, int target){ // same strategy for other shit 
    int fn = (3*n*n-n)/2;
    if(target > fn){
        isPentagonal(n+1,target);
    }
    else if(target == fn){
        printf("%d is pentagonal\n",target);
        return 1;
    } else {
        printf("%d is not pentagonal\n",target);
        return 0;
    }
}

int main(){
    isPentagonal(0,52);
    return 0;
}