#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void fermat(int n){

    while (n%2==0){ // 3*log2(n)
        n = n/2;
        printf("2*");
    }

    int x , y , isSquared = 0;

    if (sqrt(n) * sqrt(n) == n){ // 3
        x = sqrt(n);
        y = sqrt(n);
        isSquared = 1;
    }

    if (!isSquared){ // if n is not a square of an integer

        for(y=1;y<n;y++){ // n
            x = ceil(sqrt(n+(y*y)));
            if ((x*x) == (n+y*y)){
                break;
            }
        }

        x = x+y;
        y = x-y-y;
    }

    for (int i=2;i*i<=x;i++){ // check if x is a prime, if it is not a prime, do fermat
        if (x%i == 0){
            fermat(x);
            printf("*");
            x = 1;
            break;
        }
    }
    
    for (int i=2;i*i<=y;i++){ // check if y is a prime, if it is not a prime, do fermat
        if (y%i == 0){
            fermat(y);
            printf("*");
            y = 1;
            break;
        }
    }

    printf("%d*%d",x,y);

}

int main(){

    for (int i=4;i<100;i++){
        printf("%d = ",i);
        fermat(i);
        printf("\n");
    }

    return 0;
}