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

Web *moveForward(WebList *bw,WebList *fw,Web *w){
	pushWebList(bw,w);
	return popWebList(fw);
}

Web *moveBackward(WebList *bw,WebList *fw,Web *w){
	pushWebList(fw,w);
	return popWebList(bw);
}

void deleteAllStack(WebList *wl){
	Web *curr = wl->top,*temp;
	while(curr!=NULL){
		temp = curr;
		curr = curr->next;
		free(temp);
	}
}

int main(){
	WebList *bwL = (WebList*) malloc(sizeof(WebList));
	if (bwL == NULL) {
		exit(1);
	}
	WebList *fwL = (WebList*) malloc(sizeof(WebList));
	if (fwL == NULL) {
		exit(1);
	}
	initWebList(fwL);
	initWebList(bwL);
	// initialize 2 stacks

	Web *currentWeb;
	currentWeb = initWeb("x.com","x");
	pushWebList(bwL,currentWeb);
	currentWeb = initWeb("reddit.com","reddit");
	pushWebList(bwL,currentWeb);
	currentWeb = initWeb("open.spotify.com","spotify");
	pushWebList(bwL,currentWeb);
	currentWeb = initWeb("facebook.com","facebook");
	pushWebList(bwL,currentWeb);
	// add backward web to backward web list

	currentWeb = initWeb("instagram.com","instagram");
	pushWebList(fwL,currentWeb);
	currentWeb = initWeb("stackoverflow.com","stackoverflow");
	pushWebList(fwL,currentWeb);
	currentWeb = initWeb("minecraft.net","minecraft");
	pushWebList(fwL,currentWeb);
	currentWeb = initWeb("monkeytype.com","monkeytype");
	pushWebList(fwL,currentWeb);
	// add forward web to forward web list

	currentWeb = popWebList(bwL);
	printf("current is %s (%s)\n",currentWeb->address,currentWeb->title);
	printf("---------------\n");
	printf("all in backward list:\n");
	displayList(bwL);
	printf("---------------\n");
	printf("all in forward list:\n");
	displayList(fwL);
	printf("---------------\n");
	// pop out a web in backward list

	currentWeb = moveForward(bwL,fwL,currentWeb);
	printf("current is %s (%s) - moved forward\n",currentWeb->address,currentWeb->title);
	printf("---------------\n");
	printf("all in backward list:\n");
	displayList(bwL);
	printf("---------------\n");
	printf("all in forward list:\n");
	displayList(fwL);
	printf("---------------\n");
	// move forward and display all

	currentWeb = moveBackward(bwL,fwL,currentWeb);
	printf("current is %s (%s) - moved backward\n",currentWeb->address,currentWeb->title);
	printf("---------------\n");
	printf("all in backward list:\n");
	displayList(bwL);
	printf("---------------\n");
	printf("all in forward list:\n");
	displayList(fwL);
	printf("---------------\n");
	// move backward and display all

	deleteAllStack(bwL);
	deleteAllStack(fwL);
	return 0;
}