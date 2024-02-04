// #include<stdio.h>
// #include<stdlib.h>
// #include"Stack_operations_intiger.h"

// int i;
// for (i=0;i<MAX;i++){
// 	s.item[i]=NULL;
// }
// bool isFull(){
// 	if(t1 == t2-1){
// 		printf("The stack is full!");
// 		return true;
// 	}else
// 		return false;

// }
// bool EmptyS(stack *s){
// 	if(t1==s && t2==(s+MAX-1)){
// 		return true;
// 	}else
// 		return false;
// }
// void pushS(stack *s,stack *top,int element){
// 	if(!isFull()){
// 		if(*top==t1)
// 			push(&s,element)
// 		else 
// 			s->item[top--]=element;
// 	}
// }
// int popS(stack *s,stack *top){
// 	if(!EmptyS(&s))
// 	if(top==t1){
// 		// return s->item[top--];
// 		return pop(&s)
// 	}else{
// 		return s->item[top++];
// 	}
// }
// void displayS(stack *s, stack *top){
// 	if(top==t1){
// 		for(stack *s1 = s;s1<top;s1++){
// 			printf("%d",s->item[])
// 		}
// 	}
// }
// void main(){
// 	stack s;
// 	stack *t1,*t2;
// 	t1 = s;
// 	t2 = s+MAX-1;
// 	int i;
// 	do{
// 		printf("1.push\n2.pop\n3.display")
// 	}


// }

#include<stdio.h>
#define len 6
int arr[len];
int top1 = -1;
int top2 = len;
void isfull(int a){
	printf("stack %d is full\n",a);
}
void push(int a,int ele){
	if(top1==top2-1){
			isfull(a);
		}
	else{
		if(a==1){
			arr[++top1]=ele;
		}
		else{
			arr[--top2]=ele;
		}
	}
}
int pop(int a){
	if(a==1){
		if(top1==-1){
			printf("stack1 empty");
			return -1;
		}
		else
			return arr[top1--];
	}
	else{
		if(top2==len){
			printf("stack2 empty");
			return -1;
		}
		else
			return arr[top2++];
	}
}
void display(int a){
	int t;
	if(a==1){
		printf("Stack 1 : ");
		t = top1;
		while(t>-1){
			printf("%d,",arr[t--]);
		}
		printf("\n");
	}
	else{
		printf("Stack 2 : ");
		t = top2;
		while(t<len){
			printf("%d,",arr[t++]);
		}
		printf("\n");
	}
}
void main(){
	int i,n;
	push(1,1);
	push(1,2);
	push(1,3);
	push(1,4);
	push(2,1);
	push(2,3);
	push(2,4);
	display(1);
	display(2);
	printf("popping from stack 1 : %d\n",pop(1));
	push(2,4);
	display(1);
	display(2);
}