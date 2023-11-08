#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct _item {
	int quantity;
	char name[20];
	float price;
}Item;

typedef struct _customers{
	int quantity;
	Item *item;
	struct _customerQueue *next;
}Customer;

typedef struct _customerQueue{
	int size;
	Customer *first;
}CustomerQueue;

Item initItem(int q, float p, char n[]){
	Item newItem;
	newItem.price = p;
	newItem.quantity = q;
	int s = sizeof(n)/sizeof(n[0]);
	if (s>20){
		exit(1);
	}
	strncpy(newItem.name,n,s);
	return newItem;
}

void initCQ(CustomerQueue *cq){
	cq->size = 0;
	cq->first = NULL;
}

void addCustomer(CustomerQueue *cq,Item *i,int q){
	Customer *newCustomer = (Customer*) malloc(sizeof(Customer));
	newCustomer->quantity = q;
	newCustomer->item = i;
	newCustomer->next = NULL;
	if (cq->first == NULL){
		cq->first = newCustomer;
	}
	else {
		Customer *curr = cq->first;
		while(curr->next!=NULL){
			curr = curr->next;
		}
		curr->next = newCustomer;
	}
	cq->size++;
} 

void displayCustomerQueue(CustomerQueue *cq){
	for(Customer *curr = cq->first;curr!=NULL;curr=curr->next){
		printf("this customer want to buy %d %s for $%.2f each\n",curr->quantity,curr->item->name,curr->item->price);
	}
}

void purchaseCustomer(CustomerQueue *cq){
	Customer *getPaid = cq->first;
	cq->first = cq->first->next;
	cq->size--;
	if (getPaid->item->quantity < getPaid->quantity){
		printf("ran out of %s, and can not sell for a customer\n",getPaid->item->name);
	}
	else {
		getPaid->item->quantity -= getPaid->quantity;
		printf("sold %d %s for a customer, there are %d left\n",getPaid->quantity,getPaid->item->name,getPaid->item->quantity);
		if (getPaid->item->quantity == 0){
			printf("warning: ran out of %s\n",getPaid->item->name);
		}
	}
	free(getPaid);
}

void freeQueue(CustomerQueue *cq){
	Customer *curr, *temp;
	curr = cq->first;
	do{
		temp = curr;
		curr = curr->next;
		free(temp);
	}while (curr!=NULL);
}

int main(){
	srand(time(NULL));
	Item itemList[3];
	itemList[0] = initItem(100,12.99,"Apples");
	itemList[1] = initItem(59,14.99,"Oranges");
	itemList[2] = initItem(20,99.99,"Cocktails");
	
	CustomerQueue *queue = (CustomerQueue*) malloc(sizeof(CustomerQueue));
	initCQ(queue);
	for (int i=0;i<8;i++){
		int randomItem = rand() % 3;
		int q = rand() % 15;
		addCustomer(queue,&itemList[randomItem],q+1);
	}
	purchaseCustomer(queue);
	purchaseCustomer(queue);
	purchaseCustomer(queue);
	
	displayCustomerQueue(queue);
	freeQueue(queue); free(queue);
}