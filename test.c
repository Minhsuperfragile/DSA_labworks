#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    int id ;
    scanf("%d",&id);
    int q1 = (3+(id%4))%7+1;
	int q2 = (4+(q1%3))%7 +1;
	int q3 = id%7 + 1;
	printf("%d %d %d",q1,q2,q3);
    return 0;
}