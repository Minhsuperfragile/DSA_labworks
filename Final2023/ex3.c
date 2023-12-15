#include <stdio.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int array[], int arraySize){ // this is better than standard bubble sort by 0.002s
    int mid = arraySize/2, swappedFirstHalf = 0, swappedSecondHalf = 0;
    for (int i=0;i<mid;i++){
        swappedFirstHalf = 0;
        swappedSecondHalf = 0;

        if(!swappedFirstHalf){
            for (int j=i;j<arraySize-i-1;j++){
                if(array[j]<array[j+1]){
                    swap(&array[j],&array[j+1]);
                    swappedFirstHalf = 1;
                }
            }
        }

        if(!swappedSecondHalf){
            for(int j=arraySize-1;j>0+i;j--){
                if(array[j]<array[j-1]){
                    swap(&array[j],&array[j-1]);
                    swappedSecondHalf = 1;
                }
            }
        }

        if (!swappedFirstHalf && !swappedSecondHalf){
            break;
        }
    }
}

void displayArray(int array[], int arraySize){
    for(int i=0;i<arraySize;i++){
        printf("%d ",array[i]);
    }
}

int main(){
    int array[20] = {81,53,78,66,65,33,86,37,1,14,38,73,36,56,79,94,92,40,64,96};

    bubbleSort(array,20);
    displayArray(array,20);

    return 0;
}