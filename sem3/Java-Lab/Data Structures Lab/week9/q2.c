#include <stdio.h>
#include<stdlib.h>

#define SIZE 10
typedef struct Node
{
	int key;
	struct Node *next;
}Node;
void insert(Node *first, int key){
	Node *temp = NULL;

	if(first){
		temp = first;
		while(temp->next){
			temp = temp->next;
		}
		Node *new;
		new = (Node *)malloc(sizeof(Node));
		new->key = key;
		temp->next = new;
		new->next = NULL;
	}
	else{
		first = (Node *)malloc(sizeof(Node));
		first->key = key;
		first->next = NULL;
	}
}
void delete(Node *q,Node *p){
	Node *temp = NULL;
	if(q->next){
		q->next = p->next;
	}
	else{
		
		p->next = NULL;
	}
}
void display(Node *first){
	Node *temp = first;
	while(temp){
		printf("%d -> ",temp->key);
		temp = temp->next;
	}
	printf("\n");
}
Node* intersection(Node *f1,Node *f2){
	// display(f1);
	// display(f2);

	Node *this,*temp,*f3,*pre;
	temp = f2;
	this = f1;
	f3 = f1;
	pre = f2;

	while(this){
		while(pre->next){
			temp = pre->next;
			if(temp->key == this->key){
				delete(temp,pre);
			}
			pre = pre->next;
		}
		this = this->next;
	}
	temp = f2;
	while(temp){
		insert(this,temp->key);
		temp  = temp->next;
	}
	display(f1);
	return f1;
}
void create(Node *first){
int n;
		scanf("%d",&n);
		int num;
		for (int i = 0; i < n; i++)
		{
			printf("enter num: ");
			scanf("\n%d",&num);
			if(i+1 == 1){
				first->key = num;
				first->next = NULL;
				continue;
			}
			insert(first,num);
		}
}
void  main()
{	
	Node *first,*f1,*f2,*f3;
	first = (Node*)malloc(sizeof(Node));
	f1 = (Node*)malloc(sizeof(Node));
	f2 = (Node*)malloc(sizeof(Node));
	f3 = (Node*)malloc(sizeof(Node));
	// first->key = 1;
	int j=0;
	
		printf("enter the num of elements in Q1: ");
		create(f1);
		printf("enter the num of elements in Q2: ");
		create(f2);
		display(f1);
		display(f2);
		intersection(f1,f2);
		// display(f3);
}