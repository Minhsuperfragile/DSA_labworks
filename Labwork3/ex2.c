#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _web{
	char address[20];
	char title[15];
	struct _web *next;
}Web;

typedef struct _webList{
	int size;
	Web *top;
}WebList;


Web *initWeb(char a[],char t[]){
	Web *nW = (Web*) malloc(sizeof(Web));
	if (nW == NULL){
		exit(1);
	}
	strcpy(nW->address,a);
	strcpy(nW->title,t);
	nW->next = NULL;
	return nW;
}

void initWebList(WebList *l){
	l->size = 0;
	l->top = NULL;
}

void pushWebList(WebList *l, Web *w){
	if (l->size == 0){
		l->top = w;
	}
	else {
		w->next = l->top;
		l->top = w;
	}
	l->size++;
}

Web  *popWebList(WebList *l){
	Web *temp = l->top;
	l->top = temp->next;
	return temp;
}

void displayList(WebList *l){
	Web *curr = l->top;
	while(curr!=NULL){
		printf("%s (%s)\n",curr->address,curr->title);
		curr = curr->next;
	}
}
int main(){
	WebList *bwL = (WebList*) malloc(sizeof(WebList));
	if (bwL == NULL) {
		exit(1);
	}
	Web *currentWeb;
	currentWeb = initWeb("x.com","x");
	pushWebList(bwL,currentWeb);
	currentWeb = initWeb("reddit.com","reddit");
	pushWebList(bwL,currentWeb);
	currentWeb = initWeb("open.spotify.com","spotify");
	pushWebList(bwL,currentWeb);
	currentWeb = initWeb("facebook.com","facebook");
	pushWebList(bwL,currentWeb);
	displayList(bwL);
	currentWeb = popWebList(bwL);
	printf("%s (%s)\n",currentWeb->address,currentWeb->title);
	displayList(bwL);
	return 0;
}