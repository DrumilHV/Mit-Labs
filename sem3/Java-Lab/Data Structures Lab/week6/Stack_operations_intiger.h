#include <stdio.h>
#include<string.h>
# define MAX 10
# define true 1
# define false 0
/* Structure definition */
	typedef struct{
		int item[MAX];
		int top;
	}stack;
	void push(stack *ps,int x);
	int pop(stack *ps);
	int empty(stack *ps);
	int full(stack *ps);
/* Push operation */
	void push(stack *ps,int x){
		if (ps->top!=MAX-1){
				ps->top++;
				ps->item[ps->top]=x;
			}
	}
/* Pop operation */
	int pop(stack *ps){
		if(!empty(ps))
			return(ps->item[ps->top--]);
	}
/* Stack empty operation */
		int empty(stack *ps){
		if (ps->top==-1)
			return(true);
		else
			return(false);
	}
/*Stack full operation*/
	int full(stack *ps){
		if(ps->top == MAX-1){
			return true;
		}else
			return false;
	}
/*stack Display operation */
	void display(stack *s){
		if(!empty(s))
		for(int i =0;i<(s->top+1);i++){
			printf("%d\n",s->item[i]);
		}
	}