/* 
BEGIN
    int n -> 123
    string str -> n
    swap(str[sizeOfN-1],str[0])
    return int newNum -> str (newNum = 321)
END
*/
#include <stdio.h>
#include <math.h>
#include <string.h>

int main (){
    int n;
    scanf("%d",&n); 

    char str[(int)ceil(log10(n))]; //number of digits of n
    sprintf(str, "%d", n); // convert n to string
    
    printf("new number is %d", swapDigits(str,(int)ceil(log10(n))));
    return 0;
}

int swapDigits(char *str,int n){
    char temp = str[n-1]; //swap
    str[n-1] = str[0];
    str[0] = temp;
    int newNum = atoi(str); //convert string back to int
    return newNum;
}