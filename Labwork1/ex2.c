#include <stdio.h>

int main(){
    int *m;
    int q = 0;
    m = &q;
    findMax(m, 9);
    printf("%d",*m);
    return 0;
}

void findMax(int *max, int a){
    int *temp = &a;
    if (a > *max){
        *max = *temp;
    }
}