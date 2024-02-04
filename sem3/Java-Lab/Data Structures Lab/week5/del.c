# include <stdio.h>
# include <stdlib.h>


struct stack{
	int *data;
	int top;
	int size;
};

struct stack *newstk(int n){
	struct stack *ptr = (struct stack*)malloc(sizeof(struct stack));
	ptr -> size = n;
	ptr -> top = -1;
	ptr -> data = (int *)malloc(n * sizeof(int));
	return ptr;
}

int isFull(struct stack *s){
	return s -> top == s -> size - 1; 
}

int isEmpty(struct stack *s){
	return s -> top == -1;
}

void push(struct stack *s,int n){
	
	if(isFull(s)){
		printf("StackOverflow\n");
		exit(0);
	}
	else{
		s -> top++;
		s -> data[s -> top] = n; 
	}

}

int pop(struct stack *s){
	if(isEmpty(s)){
		printf("StackUnderflow\n");
	}
	else{
		return s -> data[s -> top--];
	}
}

int main(){
	int n, *arr,k;
	printf("Enter the size of stack : ");
	scanf("%d",&n);
	printf("Enter number of elements to be deleted : ");
	scanf("%d",&k);
	struct stack *ptr = newstk(n);
	arr = (int *)malloc(n * sizeof(int));
	printf("Enter the array elements : ");
	for(int i = 0;i < n;i++){
		scanf("%d",&arr[i]);
	}

	push(ptr,arr[0]);
	int count = 0;
	for(int i = 1; i < n;i++){
		while(!isEmpty(ptr) && ptr -> top < arr[i] && count < k){
			pop(ptr);
			count++;
		}
		push(ptr,arr[i]);
	}

	int m = ptr -> size;
	int a[m];

	while(!isEmpty(ptr)){
		a[--m] = ptr -> data[ptr -> top];
		pop(ptr);
	}

	for(int i = 0;i < m;i++){
		printf("%d\t",a[i]);
	}
	printf("\n");
}