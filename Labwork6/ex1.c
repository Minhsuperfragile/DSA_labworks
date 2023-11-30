#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct _node{
    int value;
    struct _node *low;
    struct _node *high;
    struct _node *parent;
    struct _node *next;
}Node;

typedef struct _layer{
    Node *head;
    struct _layer *down;
    struct _layer *up;
}Layer;

typedef struct _tree{
    Node *root;
    Layer *leaf;
    int height;
    int max;
}Tree;

Node *createNode(Node *p, int v){
    Node *newNode = (Node*) malloc(sizeof(Node));
    if (newNode==NULL){exit(1);}
    
    newNode->value = v;
    newNode->high = newNode->low = newNode->next = NULL;
    newNode->parent = p;
}

Layer *createLayer(Node *head){
    Layer *leaf = (Layer*) malloc(sizeof(Layer));
    if (leaf == NULL){exit(1);}    

    leaf->down = leaf->up = NULL;
    leaf->head = head;
}

Layer *initLeaf(int array[], int arraySize, int arrayMax){
    Layer *leaf = createLayer(createNode(NULL, array[0]));
    int h = pow(2,floor(log2(arraySize))+1);
    Node *current = leaf->head;
    for(int i=1;i<h;i++){
        if (i<arraySize){
            current->next = createNode(NULL,array[i]);
        } else {
            current->next = createNode(NULL,arrayMax + 1);
        }
        current = current->next;
    }

    return leaf;
}

Layer *initLayer(Layer *layer){
    Layer *upper; 
    Node *upperNode;

    Node *currentNode = layer->head;

    if (currentNode->value < currentNode->next->value){
        upperNode = createNode(NULL,currentNode->value);

        currentNode->parent = upperNode;
        upperNode->low = currentNode;

        currentNode->next->parent = upperNode;
        upperNode->high = currentNode->next;
    }
    else {
        upperNode = createNode(NULL,currentNode->next->value);

        currentNode->parent = upperNode;
        upperNode->high = currentNode;

        currentNode->next->parent = upperNode;
        upperNode->low = currentNode->next;
    }

    upper = createLayer(upperNode);

    currentNode = currentNode->next->next;

    while(currentNode!=NULL && currentNode->next!=NULL){
        
        if (currentNode->value < currentNode->next->value){
            upperNode->next = createNode(NULL,currentNode->value);
            upperNode = upperNode->next;

            currentNode->parent = upperNode;
            upperNode->low = currentNode;

            currentNode->next->parent = upperNode;
            upperNode->high = currentNode->next;
        }
        else {
            upperNode->next = createNode(NULL,currentNode->next->value);
            upperNode = upperNode->next;

            currentNode->parent = upperNode;
            upperNode->high = currentNode;

            currentNode->next->parent = upperNode;
            upperNode->low = currentNode->next;
        }
        currentNode = currentNode->next->next;
    }

    layer->up = upper;
    upper->down = layer;

    return upper;
}

void displayLayer(Layer *l){
    for(Node *current = l->head;current!=NULL;current=current->next){
        printf("%d ",current->value);
    }
    printf("\n");
}

Tree *initTree(Layer *leaf, int height, int max){
    Layer *temp, *current;
    Tree *tree = (Tree*) malloc(sizeof(Tree));
    if(tree==NULL){exit(1);}

    current = leaf;
    tree->leaf = current;

    for(int i=0;i<height;i++){
        current->up = initLayer(current);
        temp = current;
        current = current->up;
        current->down = temp;
        displayLayer(temp); 
    }

    current = current->down;
    if (current->head->value > current->head->next->value){
        tree->root = createNode(NULL,current->head->next->value);
        tree->root->low = current->head->next;
        tree->root->high = current->head;
    }
    else {
        tree->root = createNode(NULL,current->head->value);
        tree->root->low = current->head;
        tree->root->high = current->head->next;
    }

    printf("%d\n",tree->root->value);
    current->head->parent = tree->root;
    current->head->next->parent = tree->root;
    tree->height = height;
    tree->max = max;

    return tree;
}

void insert(Tree *tree,int value){
    Node *current = tree->leaf->head;

    while (current->value < (tree->max+1)){
        current = current->next;
        if (current == NULL){
            printf("no more space to insert!!!\n");
            return;
        }
    }
    current->value = value;

    if (value > tree->max){
        tree->max = value;
        while (current->next!=NULL){
            current = current->next;
            current->value = tree->max + 1;
        }
    }
}

void delete(Tree *tree,int val){
    Layer *currentLayer = tree->leaf;

    for(Node *currentNode = currentLayer->head;currentNode!=NULL;currentNode=currentNode->next){
        if(currentNode->value == val){
            currentNode->value = tree->max + 1;
            return;
        }
    }

    printf("target doesn't exist\n");
}

void display_preorder(Node *root) {
    if (root==NULL){
        return;
    }
    printf("%d ",root->value);
    display_preorder(root->low);
    display_preorder(root->high);
}

void freeLayer(Layer *l){
    Node *current = l->head, *temp;
    while(current!=NULL){
        temp = current;
        current = current->next;
        free(temp);
    }
    free(l);
}

void freeTree(Tree *tree){
    Layer *temp, *current;
    current = tree->leaf;
    while(current!= NULL){
        temp = current;
        current = current->up;
        freeLayer(temp);
    }
}

void updateTree(Tree *tree){
    Layer *currentLayer = tree->leaf->up, *temp;
    
    while(currentLayer!=NULL){
        temp = currentLayer;
        currentLayer = currentLayer->up;
        freeLayer(temp);
    }
    
    tree = initTree(tree->leaf,tree->height,tree->max);
}

int maxArray(int array[], int arraySize){
    int m = array[0];

    for(int i=1;i<arraySize;i++){
        if (m<array[i]){
            m = array[i];
        }
    }

    return m;
}

int main(){
    int randomNumbers[20] = {95, 87, 57, 97, 43, 14, 94, 23, 60, 76, 98, 34, 48, 13, 91, 52, 63, 99, 15, 20};
    int h = floor(log2(20)) + 1;
    int maxRandomNumber = maxArray(randomNumbers,20);

    Layer *leaf = initLeaf(randomNumbers,20,maxRandomNumber);
    
    Tree *myTree = initTree(leaf,h,maxRandomNumber);

    printf("----------------------------\n");
    printf("All values in tree:\n");
    display_preorder(myTree->root);

    printf("\n----------------------------\n");
    insert(myTree,110);
    printf("inserted 110\n");
    delete(myTree,60);
    printf("deleted 60\n");
    printf("----------------------------\n");

    updateTree(myTree);

    freeTree(myTree);

    return 0;
}