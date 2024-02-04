// #include <stdio.h>
// #include <stdlib.h>
// #include<ctype.h>
// #include <string.h>
// #include "Stack_operation_char.h"
// int getPriority(char c){
// 	if(c=='+'||c=='-'){
// 		return 1;
// 	}
// 	if(c=='*'||c=='/'){
// 		return 2;
// 	}
// 	if(c=='$'||c=='^'){
// 		return 3;
// 	}
// }
// int isOperand(char c){
// 	if((c>='a'&&c<='z')||(c>='A'&&c<='Z')){
// 		return 1;
// 	}
// 	else return 0;
// }
// int  isOperator(char c){
// 	if(c=='+'||c=='-'||c=='*'||c=='\\'||c=='^'){
// 		return 1;
// 	}else return 0;
// }
//  int isDigit(char c){
// 	if(c>='1'||c<='9'){
// 		return 1;
// 	}else return 0;
// }
// 	int j = 0;
// 	stack s;
// 	char ex[20];
// char * infixToPrefix(char string[20]){
// 	s.top = -1;
// 	int l = strlen(string);
// 	for(int i=l-1;i<=0;i++){
// 		if(isOperand(string[i])||isDigit(string[i])){
// 			ex[j++]= string[i];
// 		}
// 		else if(isOperator(string[i])){
// 			while(getPriority(s.item[s.top])>getPriority(string[i])){
// 				ex[j++]=pop(&s);
// 			}
// 			push(&s,string[i]);
// 		}
// 		else if(string[i]=='('){
// 			push(&s,string[i]);
			
// 		}
// 		else if(string[i]=='('){
// 			while(s.item[s.top]!='('){
// 				ex[j++]=pop(&s);
// 			}
// 			pop(&s);
// 		}

		

// 	}
// 	while(s.top>-1){
// 		ex[j++]=pop(&s);
// 	}
// 	printf("%s",ex);
// 	char temp;
// 	for(int i=0;i<strlen(ex)/2;i++){
// 		temp = ex[i];
// 		ex[i]=ex[strlen(ex)-1-i];
// 		ex[strlen(ex)-1-i]=ex[i];
// 	}
// 	printf("%s",ex);
// 	return ex;
// }
// void main(){
// 	char s[20]= "a+b-c/d^e*f";
// 	infixToPrefix(s);
// 	printf("the prefix is: %s ",infixToPrefix(s));
// }


#include<stdio.h>
#include<string.h>
char stack[20];
int top = -1;
void push(char ch){
	if(top<19)
		stack[++top]=ch;
}

char pop(){
	if(top>-1)
		return stack[top--];
}
int isoperand(char ch) {
    return ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')); 
} 
int isoperator(char ch){
	if(ch == '+' || ch == '-' || ch == '*'||ch == '/')
		return 1;
	else
		return 0;
}
int precedence(char x){
	if(x=='+'|| x=='-')
	return 1;
	if(x=='*'||x=='/')
	return 2;
	if(x=='^')
	return 3;
}
void main(){
	int l,i,al=0;
	char c,c1;
	char exp[20],ans[20];
	printf("enter expression : ");
	scanf("\n%s",exp);
	l = strlen(exp);
	for(i=l-1;i>=0;i--){
		c = exp[i];
		if(isoperator(c)==1){
			while(precedence(stack[top])>precedence(c)){
				c1 = pop();
				ans[al++]= c1;
			}
			push(c);
		}
		else if(c==')'){
			push(c);
		}
		else if(c=='('){
			while(stack[top] != ')'){
				ans[al++] = pop();
			}
			pop();
		}
		else if(isoperand(c)==1){
			ans[al++] = c;
		}
	}
while(top>-1){
	c1 = pop();
	ans[al++]= c1;
}
for(i=0;i<strlen(ans)/2;i++){
	c = ans[i];
	ans[i]=ans[strlen(ans)-i-1];
	ans[strlen(ans)-i-1]=c;
}
for(i=0;i<strlen(ans);i++)
	printf("%c",ans[i]);
}