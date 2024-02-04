#include <stdio.h>
#include<stdlib.h>
#define MAX 10
typedef struct 
{
	char ch[max];
	char front;
	char rear;
}queue;
void insertq(queue *, char);
void displayq(queue);
char deleteq(queue *);
void insertq(queue *q, char c){
	if(q->rear == MAX){
		printf("overflow !!");
		return;
	}else{
		q->ch[++q->rear]=c;
		if(q->front==-1){
			q->front = 0;
		}
	}
}
char deleteq(queue *q){
	if(q->rear == -1){
		printf("Underflow!!");
		return;
	}
	else if(q->rear==q->front){
		char c = q->ch[q->front];
		q->rear=q->front=-1;
		return c;
	}
	else{
		return q->ch[q->front++];
	}

}
void displayq(queue *q){
	int i;
	if(q->front==-1&&q->rear==-1){
		printf("\nQueue is Empty!!!");
	}else{
		printf("\nQueue is:\n");
		for(i=*q->front;i<=*q->rear;i++){
		printf("%d\n",q->ch[i]);
		}
	}
}


