#include <stdio.h>
#include <stdlib.h>

void factorize(int n){
    if (n<2){
        return;
    }
    for (int i=2;i<=n;i++){
        if (n%i == 0){
            if (n<10){
                printf("%d",i);
                n = n/i;
                break;
            }
            n = n/i;
            printf("%d*",i);
            break;
        }
    }
    factorize(n);
}

int main(){
    factorize(1000);
    return 0;
}