#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
typedef struct car{
    int capacity;
    int amountOfPassengers;
    char id[4];
    struct car *next;
}Car;

typedef struct train {
    int size;
    Car *head;
}Train;

Car *initCar(int capa,int passengers,char ID[]){
    Car *newCar = (Car*) malloc(sizeof(Car));
    newCar->capacity = capa;
    newCar->amountOfPassengers = passengers;
    newCar->next = NULL;
    strncpy(newCar->id,ID,4);
}

void initTrain(Train *t,int SIZE){
    t->size = SIZE;
    char c;
    for(int i=0;i<SIZE;i++){
        
    }


}

int main (){
    srand(time(NULL));
    return 0;
}