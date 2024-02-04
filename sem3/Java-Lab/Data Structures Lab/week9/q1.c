#include <stdio.h>
#include<stdlib.h>

#define SIZE 10
typedef struct linkQ
{
	int key;
	struct linkQ *next;
}linkQ;
void push(linkQ *first, int key){
	linkQ *temp = NULL;

	if(first){
		temp = first;
		while(temp->next){
			temp = temp->next;
		}
		linkQ *new;
		new = (linkQ *)malloc(sizeof(linkQ));
		new->key = key;
		temp->next = new;
		new->next = NULL;
	}
	else{
		first = (linkQ *)malloc(sizeof(linkQ));
		first->key = key;
		first->next = NULL;
	}
}
int pop(linkQ *q,linkQ *first){
	linkQ *temp = NULL;
	if(first){
		temp = first;
		while(temp->next->next){
			temp = temp->next;
		}
		int val = temp->next->key;
		temp->next = NULL;
		return val;
	}
	else{
		printf("stack is empty\n");
		return -111111;
	}
}
void display(linkQ *first){
	linkQ *temp = first;
	while(temp->next){
		printf("%d -> ",temp->key);
		temp = temp->next;
	}
}
void  main()
{
	
linkQ *first;
first = (linkQ*)malloc(sizeof(linkQ));
first->key = 1;
for (int i = 1; i < 10; i++)
{
push(first,i+1);
}
display(first);
}