#include <stdio.h>
#include <stdlib.h>

int binarySearch(int array[],int value,int high,int low){
    int pivot = (low+high)/2;
    while ((high-low)!=1){
		if (array[pivot] <= value){ // check if target is in the right side 
			low = pivot;
			pivot = (low+high)/2; 
		}
		else { // check if target is in the left side 
			high = pivot;
			pivot = (low+high)/2; 
		}
	}
    return high;
}

void insertionSort(int array[], int size){
    
}

void swap(int *a, int *b){
    int temp =  *a;
    *a = *b;
    *b = temp;
}

int main(){
    int oop[100] = {2,67,29,68,15,22,16,30,54,70,86,76,92,21,17,73,99,35,1,94,43,91,98,89,80,20,33,47,74,61,79,7,51,41,65,28,69,6,63,84,24,42,78,3,14,55,100,96,9,40,93,49,87,88,56,82,4,39,36,50,59,18,31,95,23,77,66,26,60,44,75,45,10,53,8,71,12,38,97,25,81,34,11,72,48,90,64,83,57,32,62,27,13,52,37,46,5,85,19,58};    
    return 0;
}