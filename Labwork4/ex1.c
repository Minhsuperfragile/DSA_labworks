#include <stdio.h>
#include <string.h>
#include <math.h>

int sumAllDigit(long long n){
	/*
	let sum be 0 at start
	get the number of digits of input number
	create a char array or string with the size of input number
	go through each char in char array and add it to sum
	return sum
	*/
	int sum = 0;
	int sizeOfN = (int)ceil(log10(n));//number of digits of n
	char str[sizeOfN]; 
    sprintf(str, "%d", n); // convert n to string
	for(int i=0;i<sizeOfN;i++){
		sum = sum + (str[i]-48); //we need to -48 because character zero = 48 in ascii table
		printf("string: %s,digit: %d, sum: %d\n",str,(str[i]-48),sum);
	}
	return sum;	
	// complexity is O(n) with n = the number of digits of input number	
}

int sumAllDigitRecursive(long long n,int sum){
	/*
	let sum = 0 at the begining
	get the last digit value of n, using modulus
	remove the last digit value of n by divide n by 10 and round down
	pass the new number and new sum into function again
	return total sum when n < 1 or n = 0
	*/
	if (n < 1){
		return sum;
	}
	int digit = n%10;
	sum = sum + digit;
	n = floor(n/10.0);
	printf("number: %lld,digit: %d,sum: %d\n",n,digit,sum);
	return sumAllDigitRecursive(n,sum);
	// complexity is O(n) with n = the number of digits of input number	
}

int main(){
	printf("Iteration sum is %d",sumAllDigit(123456789));
	printf("\n---------------------\n");
	printf("Recursion sum is %d",sumAllDigitRecursive(123456789,0));
	return 0;
}