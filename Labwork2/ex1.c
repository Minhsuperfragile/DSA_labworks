#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct digit{
    int value;
    struct digit *next;
}Digit;

typedef struct unboundedInt{
    int size;
    Digit *head;
}UnboundedInt;

Digit *initDigit(int digit){
    Digit *node = (Digit*) malloc(sizeof(Digit)); 
    if(node == NULL){
        exit(1);
    }
    node->value = digit;
    node->next = NULL;
    return node;
}

void initUnboundedInt(int SIZE,UnboundedInt *number){
    
    Digit *curr;
    int d; 
    number->size = SIZE;
    number->head = initDigit(1);
    number->head->next = curr;
    for(int i=0;i<SIZE;i++){
        d = rand() % 10;// random from 0 to 9
        curr->next = initDigit(d);
        curr = curr->next;
    }
}

void displayUnboundedInt(UnboundedInt *number){
    for(Digit *root = number->head;root!=NULL;root = root->next){
        printf("%d ",root->value);
    }
}

int main(){
    srand(time(NULL));
    UnboundedInt *number = (UnboundedInt*) malloc(sizeof(UnboundedInt));
    if (number==NULL){
        exit(2);
    }
    initUnboundedInt(10,number);
    displayUnboundedInt(number);
    return 0;
}