#include <stdio.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void displayArray(int array[], int arraySize){
    for(int i=0;i<arraySize;i++){
        printf("%d ",array[i]);
    }
}

void selectionSort(int array[], int arraySize){ // this is better than standard selection sort by 0.002s
    int max, min;
    for (int i=0; i<(arraySize/2); i++){
        max = i;
        min = arraySize - 1 -i;

        for(int j=i; j<arraySize-i-1; j++){
            if(array[min] > array[j]){
            min = j;
            }
        }
        swap(&array[i],&array[min]);

        for (int j=arraySize-i-1; j>i; j--){
            if(array[max] < array[j]){
            max = j;
            }
        }
        swap(&array[arraySize - 1 -i],&array[max]);
    }
}

int main(){
    int array[20] = {81,53,78,66,65,33,86,37,1,14,38,73,36,56,79,94,92,40,64,96};
    selectionSort(array,20);
    displayArray(array,20);
    return 0;
}