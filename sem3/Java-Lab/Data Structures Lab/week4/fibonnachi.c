#include<stdio.h>
#include<stdlib.h>

int fib(int x){
	if(x==1){
		return 0;
	}
	if(x==2){
		return 1;
	}
	else
		return (fib(x-1)+fib(x-2));
}
void main(){
	int n,i;
	printf("enter the number of fibonacchi sequence you want: ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	printf("%d\t",fib(i));

	// printf("the sum is: %d",fibonacchi(n));
}