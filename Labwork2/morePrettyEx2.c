#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define CAP 3
#define ID_LENGTH 6

typedef struct _car{
    int capacity;
    char id[ID_LENGTH];
    int numberOfPassengers;
    struct _car *next;
}Car;

typedef struct _train{
    int size;
    Car *head;
}Train;

Car *initCar(int passengers){
    Car *newCar = (Car*) malloc(sizeof(Car));
    if (newCar == NULL){
        exit(1);
    }
    newCar->capacity = CAP-1;
    newCar->numberOfPassengers = passengers;
    for(int i=0;i<ID_LENGTH;i++){
        char c = (char)((rand() % 26) + 97); // random a charactor from A->Z
        newCar->id[i] = c;
    }
    newCar->next = NULL;
}

void initTrain(Train *tauhoa, int SIZE){
    tauhoa->size = SIZE;
    Car *current;
    for(int i=0;i<SIZE;i++){
        int p = rand() % CAP;
        if (i == 0){
            current = initCar(p);
            tauhoa->head = current;
        }
        else {
        	current->next = initCar(p);
        	current = current->next;
    	}
    } 
	printf("generated a train successfully\n----------\n");
}

void addNewCar(Train *tauhoa){
	Car *current = tauhoa->head;
	while(current->next!=NULL){
		current = current->next;
	}
	int p = rand() % CAP;
	current->next = initCar(p);
}

void rmCarWithNoPassenger(Train *tauhoa){
	Car *current, *temp;
	char delID[ID_LENGTH];	
	while (tauhoa->head->numberOfPassengers == 0){ // if first car has 0 passenger
		temp = tauhoa->	head;
		strncpy(delID,temp->id,ID_LENGTH);
		tauhoa->head = temp->next;
		free(temp);
		tauhoa->size--;
		printf("deleted the first car with ID: ");
		for (int i=0;i<ID_LENGTH;i++){
            printf("%c",delID[i]);
        } printf("\n");
		if (tauhoa->head == NULL){
			printf("there is nothing to delete!\n");
			return;
		}
	}
	current = tauhoa->head;
	while (current->next != NULL){ //other cars
		if (current->next->numberOfPassengers == 0){
			temp = current->next;
			strncpy(delID,temp->id,ID_LENGTH);
			current->next = temp->next;
			free(temp);
			tauhoa->size--;
			printf("deleted a car with ID: ");
			for (int i=0;i<ID_LENGTH;i++){
            	printf("%c",delID[i]);
        	} printf("\n");
		}
		else{
			current = current->next;
		}
	}
}

void displayAllTrain(Train *tauhoa){
    for (Car *root = tauhoa->head;root != NULL;root = root->next){
        printf("\ncar's number of passenger: %d\n",root->numberOfPassengers);
        printf("car's id: ");
        for (int i=0;i<ID_LENGTH;i++){
            printf("%c",root->id[i]);
        }
    }
}

int main (){
    srand(time(NULL));
    Train *kesshokuBand = (Train*) malloc(sizeof(Train));
    if (kesshokuBand == NULL){
        exit(2);
    }
    initTrain(kesshokuBand,8);

    addNewCar(kesshokuBand);
    rmCarWithNoPassenger(kesshokuBand);
	printf("----------");
    displayAllTrain(kesshokuBand);
    return 0;
}