/*
Create 2 dynamic array of prime number and divisors of n for later use
Using sieve algorithm to find all prime number from 2 to n.
Know that sphenic numbers always have exactly 8 divisors,
find all divisors of n, if there are not 8 divisors, return false.
After that, check if n is a prime number, return false.
Finally check if there are exactly 3 distint prime number in divisors array.
Return true if all that conditions are satisfied
*/

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int *primeList, *divisors; //create 2 dynamic array for later use

void findDivisors(int n){
    divisors = (int *) realloc(divisors,8*sizeof(int)); //give it 8 integeres
    for(int i=0;i<8;i++){ // fill with 0
        divisors[i] = 0;
    }
    int count = 0;
    for (int i=1;i*i <= n;i++){
        if (count >= 8){ // if there are more than 8 divisors, it's wrong
            for(int i=0;i<8;i++){
                divisors[i] = 0; // reset to 0
            }
            return;
        }
        if(n%i == 0){
            if (i*i == n){ // if there are 2 divisors with the same value, return 0
                for(int i=0;i<8;i++){
                    divisors[i] = 0;
                }
                return;
            }
            divisors[count] = i;
            divisors[7-count] = floor(n/i); // a little optimization to algorithm
            count++;    
        }
    }
} // this part has time complexity of O(sqrt(n))

void findPrime(int n){ // sieve algorithm to find prime number less than n
    primeList = (int *) realloc(primeList,n*sizeof(int));
    primeList[0] = 0;
    primeList[1] = 0;
    for(int i=2;i<n;i++){ // fill with 1
        primeList[i] = 1;
    }
    for (int i=2; i<= sqrt(n);i++){
        if(primeList[i] == 1){ 
            for (int j=i*i;j<=n;j=j+i){ // mark all numbers which are divisable by i with 0
                primeList[j] = 0;
            }
        }
    }
} // this part has time complexity of  O(n*log(log(n)))

int checkSphenic(int n){
    findDivisors(n);
    if (divisors[0] == 0){
        return 0;
    }
    int count = 0;
    findPrime(n+1);
    if (primeList[n] == 1){
        return 0;
    }
    for (int i=1;i<7;i++){ 
        if (primeList[divisors[i]] == 1){
            count++;
        }
    }
    if (count != 3){
        return 0;
    }
    else {return 1;}
} // the total algorithm has time complexity of O(n*log(log(n)))

int main() {
    for (int i=30; i<=100;i++){
        int output = checkSphenic(i);
        if (output == 1){
            printf("%d ",i);
        }
    }
    free(divisors);
    free(primeList);
    return 0;
}