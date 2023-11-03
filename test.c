#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
int main(){
    int count = 69820;
    char id[4] = {'A','A','0','0'};
    for(int i=0;i<100;i++){
        id[3] = (count%10 + 48);
        id[2] = ((count/10)%10 + 48);
        id[1] = ((count/2600)%26 + 65);
        id[0] = ((count/(26*26*100))%26 + 65);
        for (int j=0;j<4;j++){
            printf("%c ",id[j]);
        }
        printf("\n");
        count++;
    }
    return 0;
}