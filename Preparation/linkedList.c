#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct _node{
    int value;
    struct _node *next;
}Node;

typedef struct _linkedList{
    Node *head;
    int size;
}LinkedList;

Node *initNode(int v){
    Node *newNode = (Node*) malloc(sizeof(Node));
    if (newNode == NULL){exit(1);}
    newNode->value = v;
    newNode->next = NULL;
}

int isEmpty(LinkedList *linkedList){
    return linkedList->size == 0;
}

void initLinkedList(LinkedList *linkedList){
    linkedList->head = NULL;
    linkedList->size = 0;
}

void addNodeToHead(LinkedList *linkedList, Node *node){
    node->next = linkedList->head;
    linkedList->head = node;
    linkedList->size++;
}

void addNodeToTail(LinkedList *linkedList, Node *node){
    if (isEmpty(linkedList)) {
        addNodeToHead(linkedList,node);
        return;
    }
    Node *current = linkedList->head;
    while(current->next!=NULL){
        current=current->next; 
    }
    current->next = node;
    linkedList->size++;
}

void insertNode(LinkedList *linkedList, Node *node, int index){
    if (index > linkedList->size){
        printf("There isn't index %d\n",index);
        return;
    }
    if (isEmpty(linkedList)) {
        addNodeToHead(linkedList,node);
        return;
    }

    Node *current = linkedList->head;
    for (int i=1;i<index;i++){
        current = current->next;
    }

    node->next = current->next;
    current->next = node;
    linkedList->size++;
}

void removeNodeAtHead(LinkedList *linkedList){
    if (isEmpty(linkedList)){
        printf("Nothing to delete\n");
        return;
    }
    Node *temp = linkedList->head;
    linkedList->head = linkedList->head->next;
    free(temp);
    linkedList->size--;
}

void removeNodeAtTail(LinkedList *linkedList){
    if (isEmpty(linkedList)){
        printf("Nothing to delete\n");
        return;
    }
    Node *current = linkedList->head;
    for (int i=0;i<linkedList->size-1;i++){
        current = current->next;
    }
    Node *temp = current->next;
    free(temp);
    linkedList->size--;
}

void removeNode(LinkedList *linkedList, int index){
    if (isEmpty(linkedList)){
        printf("Nothing to delete\n");
        return;
    }
    if (index > linkedList->size){
        printf("There isn't index %d\n",index);
        return;
    }

    Node *current = linkedList->head;
    for(int i=1;i<index-1;i++){
        current = current->next;
    }

    Node *temp = current->next;
    current->next = temp->next;
    free(temp);
    linkedList->size--;
}

void displayLinkedList(LinkedList *linkedList){
    if (isEmpty(linkedList)){
        printf("Nothing to display\n");
        return;
    }
    for (Node *current = linkedList->head;current!=NULL;current=current->next){
        printf("%d ",current->value);
    }
    printf("\n");
}

void deleteLinkedList(LinkedList *linkedList){
    Node *current = linkedList->head, *temp;
    while (current->next!=NULL){
        temp = current;
        current = current->next;
        free(temp);
    }
    free(linkedList);
}

Node *search(LinkedList *linkedList, int target){
    if (isEmpty(linkedList)){
        printf("Nothing to search for\n");
        return NULL;
    }
    for(Node *current = linkedList->head;current!=NULL;current=current->next){
        if (current->value==target){
            return current;
        }
    }
}

int main(){
    srand(time(NULL));

    LinkedList *myLinkedList = (LinkedList*) malloc(sizeof(LinkedList));
    if (myLinkedList == NULL){exit(1);}
    initLinkedList(myLinkedList);

    for(int i=0;i<10;i++){
        addNodeToTail(myLinkedList,initNode(rand()%53));
    }

    displayLinkedList(myLinkedList);

    insertNode(myLinkedList,initNode(69),7);
    removeNode(myLinkedList,3);

    displayLinkedList(myLinkedList);

    deleteLinkedList(myLinkedList);

    return 0;
}