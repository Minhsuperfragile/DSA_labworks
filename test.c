#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
int main(){
    int count = 702;
    char id[4] = {'A','A','0','0'};
    // for(int i=0;i<100;i++){
    //     id[3] = (count%10 + 48);
    //     id[2] = ((count/10)%10 + 48);
    //     id[1] = ((count/100)%26 + 65);
    //     id[0] = ((count/(26*100))%26 + 65);
    //     for (int j=0;j<4;j++){
    //         printf("%c ",id[j]);
    //     }
    //     printf("\n");
    //     count++;
    // }
    printf("%d",strncmp("AA00","AA01",4));
    return 0;
}