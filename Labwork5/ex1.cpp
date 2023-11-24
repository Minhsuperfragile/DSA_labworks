#include <iostream>
#include <stdlib.h>
#include <time.h>

void insertIntAtRightPosition(int array[],int value,int amountOfValueInArray){
	if (amountOfValueInArray >= 100){ // check if there is no more space to insert
		std::cout << "no more space to insert\n";
		return;
	}
	int low = 0, high = amountOfValueInArray-1; // initial variables
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
	for (int i=amountOfValueInArray;i>high;i--){ // shift all value on the right hand of target
		array[i] = array[i-1];
	}
	array[high] = value; // insert target into high position
	std::cout << "\nhigh: " << high << "\n" << "low: " << low << "\n";
}

int main(){
	srand(time(NULL));
	int arr[20], seed = 2;
	for (int i=0;i<15;i++){ // create 15 values in array
		seed = seed + rand() % 15; // random ascending 
		if (seed == arr[i-1]){
			seed = seed + rand()%3; // reduce duplication
		}
		arr[i] = seed;
		std::cout << arr[i] << " ";
	}
	insertIntAtRightPosition(arr,73,15); //insert number 73
	std:: cout << "inserted 73\n----------------------\n";
	for (int i=0;i<16;i++){
		std::cout << arr[i] << " ";
	}
	return 0;
}