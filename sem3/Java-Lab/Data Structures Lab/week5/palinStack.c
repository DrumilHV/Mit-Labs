#include <stdio.h>
#include <stdlib.h>
#include "Stack_operations_intiger.h"
#include <string.h>
// isPalin(stack s,int length){

// }

void main(){

	stack s;
	s.top = -1;
	int i,j;
	int flag = 1;
	char str[20];
	printf("\nenter String: ");
	fgets(str,20,stdin);
	// for(i=0;str[i]!='\0';i++);
	for(j=0;j<i/2;j++)
	{
		push(&s,str[j]);
	}
	if(strlen(str)%2 ==0){
		j++;
	}
	while(!empty(&s)){
		if(str[j]!=pop(&s)){
			flag=0;
		}
		j++;
	}
	if(flag){
		printf("%s is Palindrome.",str);
	}else
		printf("%s is NOT Palindrome.",str);
}

