#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define maxCapacitance 12

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

Car *initCar(int passengers,char c[]){
    Car *newCar = (Car*) malloc(sizeof(Car));
    if (newCar==NULL){
        exit(1);
    }
    newCar->capacity = maxCapacitance;
    newCar->amountOfPassengers = passengers;
    newCar->next = NULL;
    strncpy(newCar->id,c,4);
    return newCar;
}

void initTrain(Train *t,int SIZE){
    t->size = SIZE;
    Car *curr;
    int p;
    char c[4];
    for(int i=0;i<SIZE;i++){
        p = rand() % maxCapacitance;
        c[3] = (i%10 + 48);
        c[2] = ((i/10)%10 + 48);
        c[1] = ((i/100)%26 + 65);
        c[0] = ((i/(26*100))%26 + 65);
        if(i==0){
            curr = initCar(p,c);
            t->head = curr;
        }
        else{
            curr->next = initCar(p,c);
            curr = curr->next;
        }
        
    }
}

void displayTrain(Train *t){
    Car *curr = t->head;
    printf("train has %d cars\n",t->size);
    for (int i=0;i<t->size;i++){
        printf("Car ID: ");
        for (int j=0;j<4;j++){
            printf("%c",curr->id[j]);
        }
        printf(" has %d passengers\n",curr->amountOfPassengers);
        curr = curr->next;
    }
}

void removeCar(Train *t,int position){
    Car *curr = t->head, *support;
    for(int i=1;i<position;i++){
        curr = curr->next;
    }
    support = curr->next;
    curr->next = support->next;
    t->size--;
    free(support);
}

void deleteZeroPassengerCar(Train *t){
    Car *curr = t->head,*support;
    for(int i=0;i<t->size;i++){
        while(t->head->amountOfPassengers == 0){ //case first car has 0 passenger
            support = t->head;
            t->head = t->head->next;
            free(support);
            t->size--;
            printf("the first car has 0 passengers\n");
            curr = t->head;
            if (t->head == NULL){
                printf("all are 0");
                return;
            }
        }
        if (i+1 == t->size && curr->next->amountOfPassengers ==0){ //case last car has 0 passenger
            support = curr->next;
            curr->next =NULL;
            printf("the last car has 0 passenger\n");
            t->size--;
            free(support);
            return;
        }
        if (curr->next->amountOfPassengers == 0){ // any other cases
            support = curr->next;
            curr->next = support->next;
            free(support);
            t->size--;
            printf("deleted a car has 0 passengers\n");
        }
        else {
            curr = curr->next;
        }
    }
}

void addNewCar(Train *t,int passengers){
    char c[4] = "AA00";
    int count = 0;
    Car *support, *new = NULL;
    
    for (Car *curr = t->head;curr!=NULL;curr = curr->next){// search for a free ID
        c[3] = (count%10 + 48);
        c[2] = ((count/10)%10 + 48);
        c[1] = ((count/100)%26 + 65);
        c[0] = ((count/(26*100))%26 + 65);
        count++;
        if(strncmp(c,curr->id,4)!=0){
            new = initCar(passengers,c);
            break;
        }
    }
    if (strncmp(c,t->head->id,4)<0 || t->head == NULL){//case insert at the beginning
        support = t->head->next;
        t->head = new;
        new->next = support;
        return;
    }
    Car *curr = t->head;
    while (curr->next!=NULL){
        if (new!=NULL){ // if we can find a free ID, run this
            if (strncmp(new->id,curr->id,4)>0 && strncmp(new->id,curr->next->id,4)<0){
                support = curr->next;
                curr->next = new;
                new->next = support;
                t->size++;
                return;
            } 
        } // if there is no free ID, run to the end of list
        curr = curr->next;
    }
    count = (t->size)++; // create a new node at the end
    c[3] = (count%10 + 48);
    c[2] = ((count/10)%10 + 48);
    c[1] = ((count/100)%26 + 65);
    c[0] = ((count/(26*100))%26 + 65);
    new = initCar(passengers,c);
    curr->next = new;
}

void deleteEntireTrain(Train *t){
    Car *curr = t->head;
    while(curr!=NULL){
        Car *support = curr;
        curr = curr->next;
        free(support);
    }
    t = NULL;
}

int main (){
    srand(time(NULL));
    Train *bocchi = (Train*) malloc(sizeof(Train));
    if (bocchi == NULL){
        exit(2);
    }
    initTrain(bocchi,10);
    displayTrain(bocchi);
    // removeCar(bocchi,3);
    printf("-------\n");
    // displayTrain(bocchi);
    // printf("-------\n");
    addNewCar(bocchi,9);
    displayTrain(bocchi);
    printf("-------\n");
    // deleteZeroPassengerCar(bocchi);
    // printf("-------\n");
    // displayTrain(bocchi);
    // addNewCar(bocchi,4);
    // printf("-------\n");
    // displayTrain(bocchi);
    deleteEntireTrain(bocchi);
    return 0;
}