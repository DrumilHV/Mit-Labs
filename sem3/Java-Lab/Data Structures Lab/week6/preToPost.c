#include<stdio.h>
#include<string.h>
char stack[20][20];
int top = -1;
void push(char* ch){
	if(top<19)
		stack[++top]=*ch;
}

char* pop(){
	if(top>-1)
		return stack[top--];
}
int isoperand(char ch){
	if(ch == '+' || ch == '-' || ch == '*'||ch == '/')
		return 1;
	else
		return 0;
}
void main(){
	int i,l;
	char c,c1[2],
	char* o1,o2;
	char exp[20];
	printf("enter expression : ");
	scanf("%s",exp);
	l = strlen(exp);
	for(i=l;i>=0;i--){
		c = exp[i];
		if(isoperand(c)){
			o1 = pop();
			o2 = pop();
			strcat(d,*o1);
			strcat(d,&c);
			strcat(d,*o2);
			push(d);
		}
		else{
			push(&c);
		}
	}
	printf("final evaluation = %s",pop());

}