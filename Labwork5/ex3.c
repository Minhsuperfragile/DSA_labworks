#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct _node{
    int value;
    struct _node *next;
    struct _node *previous;
}Node;

typedef struct _linkedList{
    int size;
    Node *head;
}LinkedList;

Node *createNode(int v){
    Node *newNode = (Node*) malloc(sizeof(Node));
    if (newNode == NULL){
        exit(1);
    }
    newNode->value = v;
    newNode->next = NULL;
    newNode->previous = NULL;
}

void initLinkedList(LinkedList *list){
    list->head = NULL;
    list->size = 0;
}

void insertNodeAtTheEnd(LinkedList *list, Node *newNode){
    Node *current;
    if (list->head == NULL){
        list->head = newNode;
        ++list->size;
        return;
    }
    current = list->head;
    while(current->next!=NULL){
        current = current->next;
    }
    newNode->previous = current;
    current->next = newNode;
    ++list->size;
}

void displayLinkedList(LinkedList *list){
    for (Node *current=list->head;current!=NULL;current=current->next){
        printf("%d ",current->value);
    }
}

void freeLinkedList(LinkedList *list){
    if (list->head == NULL){
        return;
    }
	Node *curr = list->head,*temp;
	while(curr!=NULL){
		temp = curr;
		curr = curr->next;
		free(temp);
	}
}

Node *binarySearch(LinkedList *list,int item){
    Node *current = list->head;
    int count = 1;
    int mid = floor(list->size/pow(2,count));

    if (list->size <= 1){
        return list->head;
    }

    for(int i=0;i<mid;i++){
        current = current->next;
    }

    while(current->previous->value > item || current->value < item){
        ++count;
        mid = ceil(list->size/pow(2,count));
        if (mid == 0){
            break;
        }
        
        if (current->value < item){
            for(int i=0;i<mid;i++){
                current = current->next;
            }
        }

        else{
            for(int i=0;i<mid-1;i++){
                current = current->previous;
            }
        }

        if(current->previous == NULL || current==NULL){
            break;
        }
    }
    return current;
}

void *insertionSort(LinkedList *list,LinkedList *sortedList){
    Node *current, *temp, *auxilary;
    int maxValue;
    insertNodeAtTheEnd(sortedList,createNode(list->head->value));
    current = list->head->next;

    while (current!=NULL){
        if (sortedList->size < 2){ // case there is only 1 element in sorted array
            temp = current;
            current = current->next;
            temp->next = NULL;
            sortedList->head->next = temp;
            temp->previous = sortedList->head;
            maxValue = temp->value;
            if (current==NULL) {break;}
        }

        if(current->value < sortedList->head->value){ // case current value is the smallest in sorted array 
            temp = current;
            current = current->next;
            maxValue = sortedList->head->value;
            sortedList->head->previous = temp;
            temp->next = sortedList->head;
            sortedList->head = temp;
            if (current==NULL) {break;}
        }

        if (current->value >= maxValue){ // case current value is the largest in sorted array
            temp = sortedList->head;
            maxValue = current->value;
            while (temp->next!=NULL){
                temp = temp->next;
            }
            auxilary = current;
            current = current->next;
            auxilary->next = NULL;
            temp->next = auxilary;
            if (current==NULL) {break;}
        }
        // every things else
        if (sortedList->size >= 2 && current->value < maxValue && current->value >= sortedList->head->value){
            temp = binarySearch(sortedList,current->value);
            auxilary = current;
            current = current->next;
            auxilary->next = temp;
            temp->previous->next = auxilary;
            auxilary->previous = temp->previous;
            temp->previous = auxilary;  
            if (current==NULL) {break;}
        }
        sortedList->size++;
    }
}

void reverseList(LinkedList *list){
    Node *current = list->head;
    while(current->next!=NULL){
        current=current->next;
    }
    while(current!=NULL){
        printf("%d ", current->value);
        current=current->previous;
    }
}

int main(){
    /*
    I chose linked list to do this exercise.
    The best data structure for sorting algorithm is list
    because it has index
    */
    LinkedList *myList = (LinkedList*) malloc(sizeof(LinkedList));
    LinkedList *anotherList = (LinkedList*) malloc(sizeof(LinkedList));
    if (myList == NULL || anotherList == NULL){
        exit(1);
    }
    initLinkedList(myList);
    initLinkedList(anotherList);

    int oop[10] = {2,67,29,68,15,22,16,30,54,70};

    for (int i=0;i<10;i++){
        Node *new = createNode(oop[i]);
        insertNodeAtTheEnd(myList,new);
    }
    
    printf("Unsorted List: \n");
    displayLinkedList(myList);

    printf("\n-----------\nSorted List: \n");
    insertionSort(myList,anotherList);
    displayLinkedList(anotherList);

    freeLinkedList(anotherList);
    free(myList);
    free(anotherList);
}