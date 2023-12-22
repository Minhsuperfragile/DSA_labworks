#include <stdio.h>
#include <math.h>

int condition(int a, int b, int c){
    return ((a*a - a*b + b*b) == c*c);
}

void loop(int *array, int ind_a, int ind_b, int ind_c, int length) {
    int a = array[ind_a];
    int b = array[ind_b];
    int c = array[ind_c];
    if ((condition(a, b, c) == 1) || (condition(b, c, a) == 1) || (condition(c, a, b) == 1)) {
        printf("%d %d %d\n",a,b,c);
    }
    if (ind_c < length - 1) {
        loop(array, ind_a, ind_b, ind_c + 1, length);
    } else if (ind_b < length - 2) {
        loop(array, ind_a, ind_b + 1, ind_b + 2, length);
    } else if (ind_a < length - 3) {
        loop(array, ind_a + 1, ind_a + 2, ind_a + 3, length);
    }
}
    
int main(){
    int array[20] = {90, 3, 66, 8, 57, 80, 24, 91, 74, 53, 21, 20, 84, 56, 34, 7, 63, 69, 25, 30};
    loop(array,0,1,2,20);
    return 0;
}