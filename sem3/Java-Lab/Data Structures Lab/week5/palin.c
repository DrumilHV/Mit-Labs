# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# define MAX 100

struct stack{
	int top;
	int arr[MAX];
};

int isEmpty(struct stack *s){
	return s -> top == -1;
}

int isFull(struct stack *s){
	return s -> top == MAX - 1;
}

void push(struct stack *s,char ch){
	if(isFull(s)){
		printf("Stackoverflow\n");
	}
	else{
		s -> arr[++s -> top] = ch;
	}
}

char pop(struct stack *s){
	if(isEmpty(s)){
		printf("Stackunderflow\n");
	}
	else{
		return s -> arr[s -> top--];
	}
}

int main(){
	char input[100];
	int length;

	struct stack s;
	s.top = -1;

	printf("Enter a string : ");
	gets(input);
	length = strlen(input);

	for(int i = 0;i < length;i++){
		push(&s,input[i]);
	}

	for(int i = 0;i < length;i++){
		if(pop(&s) != input[i]){
			printf("Not a palindrome\n");
			break;
		}
		else{
			printf("%s is a palindrome \n",input);
		}
	}
	
	
	return 0;
}