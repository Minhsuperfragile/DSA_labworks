#include <stdio.h>
#include <math.h>

void factorize(int n){
    int mid = floor(sqrt(n));
    int d1, d2;

    for (int i=mid;i>0;i--){
        if (i==1){
            printf("%d*",n);
            return;
        }
        if (n%i == 0){
            d1 = i;
            d2 = n/i;
            break;
        }
    }
    factorize(d1);
    factorize(d2);
}

int main(){
    for(int i=4;i<100;i++){
        printf("%d = ",i);
        factorize(i);
        printf("1\n");
    }
    return 0;
}