#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Stack_operations_intiger.h"
// ch = 'y';
void main(){
stack s;
// s = (stack*)malloc(sizeof(stack));
s.top = -1;
int ch;
char cont='y';
int element;
int i;


	while(cont == 'y')
	{
		printf("\n1.push\n2.pop\n3.display\nenter choise: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("\nEnter the element to push: ");
				scanf("%d",&element);
				if(!full(&s)){
					push(&s,element);
				}else{
					break;
				}
				break;
			case 2:
				printf("element popped: %d",pop(&s));
				break;
			case 3:
				display(&s);
				break;
			default: 
				printf("invalid choise.\n plese try again.");
				break;
		}
		printf("\ndo You want to continue? (y/n) :");
		scanf("\n%c",&cont);
	}
}