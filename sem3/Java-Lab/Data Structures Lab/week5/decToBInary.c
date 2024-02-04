#include <stdio.h>
#include <stdlib.h>
#include "Stack_operations_intiger.h"
void main(){
	stack s;
	s.top= -1;
	int num ;
	int rem;
	printf("enter the number: ");
	scanf("%d",&num);
	while(num!=0){
		rem = num%2;
		push(&s,rem);
		printf("%d",rem);
		num=num/2;
	}
	printf("\n\nthe binary no is: ");
	while(!empty(&s)){
		printf("%d",pop(&s));
	}
	printf("\n");
}
