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
    number->head = initDigit(d%2); //random sign -> 0 is negative, 1 is positive
    for(int i=0;i<SIZE;i++){
        d = rand() % 10;// random from 0 to 9
        curr->next = initDigit(d);
        curr = curr->next;
        if(i==0){
            number->head->next = curr;
        }
    }
}

void displayUnboundedInt(UnboundedInt *number){
    if(number->head->value != 1){
        printf("-");
    }
    for(Digit *root = number->head->next;root!=NULL;root = root->next){
        printf("%d",root->value);
    }
}

void deleteEntireNumber(UnboundedInt *number){
    Digit *curr = number->head;
    while(curr!=NULL){
        Digit *support = curr;
        curr = curr->next;
        free(support);
    }
    number = NULL;
}

int calculateAllDigits(UnboundedInt *number){
    int sum = 0;
    for(Digit *root = number->head->next;root!=NULL;root = root->next){
        sum += root->value;  
    }
    return sum;
}

void insertDigit(UnboundedInt *number,int position, int digit){
    Digit *curr = number->head;
    for(int i=0;i<position-1;i++){
        curr = curr->next;
    }
    Digit *support = curr->next;
    Digit *newDigit = initDigit(digit);
    curr->next = newDigit;
    newDigit->next = support;
}

void deleteDigit(UnboundedInt *number,int position){
    Digit *curr = number->head;
    for(int i=0;i<position-1;i++){
        curr = curr->next;
    }
    Digit *support = curr->next;
    curr->next = support->next;
    free(support);
}

int main(){
    srand(time(NULL));//set seed for random function
    UnboundedInt *number = (UnboundedInt*) malloc(sizeof(UnboundedInt));
    if (number==NULL){exit(2);}
    initUnboundedInt(100,number); // create a random number with 100 digits
    insertDigit(number,1,9); // insert 9 to the first place, replace any 0 that might happen
    deleteDigit(number,2); // delete the 2 second digits, which was at the first place before inserting 9
    // this 2 lines mean that I replace the first digit with 9
    displayUnboundedInt(number);
    printf("\n%d",calculateAllDigits(number));
    deleteEntireNumber(number);// clear memory
    return 0;
}