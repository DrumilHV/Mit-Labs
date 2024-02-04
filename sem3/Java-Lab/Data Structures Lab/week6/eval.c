#include<stdio.h>
#include<string.h>
int stack[20];
int top = -1;
void push(int ch){
	if(top<19)
		stack[++top]=ch;
}

int pop(){
	if(top>-1)
		return stack[top--];
}
int isoperand(char ch){
	if(ch == '+' || ch == '-' || ch == '*'||ch == '/')
		return 1;
	else
		return 0;
}
int eval(int op1,int op2,char x){
	if(x=='+')
	return(op1+op2);
	if(x=='-')
	return(op1-op2);
	if(x=='*')
	return(op1*op2);
	if(x=='/')
	return(op1/op2);
	if(x=='%')
	return(op1%op2);
}
void main(){
	int i,l,d,o1,o2;
	char c;
	char exp[20];
	printf("enter expression : ");
	scanf("%s",exp);
	l = strlen(exp);
	for(i=l;i>=0;i--){
		c = exp[i];
		d = (int)c;
		d-=48;
		if(isoperand(c)){
			o1 = pop();
			o2 = pop();
			d = eval(o1,o2,c);
			push(d);
		}
		else{
			push(d);
		}
	}
	printf("final evaluation = %d",pop());

}